/*
 * socket_efun.c -- socket efuns for MudOS.
 *    5-92 : Dwayne Fontenot (Jacques@TMI) : original coding.
 *   10-92 : Dave Richards (Cynosure) : less original coding.
 */

#include "std.h"
#include "network_incl.h"
#include "lpc_incl.h"
#include "socket_efuns.h"
#include "socket_err.h"
#include "include/socket_err.h"
#include "debug.h"
#include "socket_ctrl.h"
#include "comm.h"

#ifdef SOCKET_EFUNS

struct lpc_socket lpc_socks[MAX_EFUN_SOCKS];
static int socket_name_to_sin PROT((char *, struct sockaddr_in *));
static char *inet_address PROT((struct sockaddr_in *));

/*
 * check permission
 */
int check_valid_socket P5(char *, what, int, fd, struct object *, owner,
			  char *, addr, int, port) {
    struct vector *info;
    struct svalue *mret;
    
    info = allocate_empty_array(4);
    info->item[0].type = T_NUMBER;
    info->item[0].u.number = fd;
    assign_socket_owner(&info->item[1], owner);
    info->item[2].type = T_STRING;
    info->item[2].subtype = STRING_CONSTANT;
    info->item[2].u.string = addr;
    info->item[3].type = T_NUMBER;
    info->item[3].u.number = port;

    push_object(current_object);
    push_string(what, STRING_CONSTANT);
    push_refed_vector(info);

    mret = apply_master_ob(APPLY_VALID_SOCKET, 3);
    return MASTER_APPROVED(mret);
}

/*
 * Initialize the LPC efun socket array
 */
void init_sockets()
{
    int i;

    debug(8192, ("init_sockets: initializing %d socket descriptor(s)\n",
		 MAX_EFUN_SOCKS));

    for (i = 0; i < MAX_EFUN_SOCKS; i++) {
	lpc_socks[i].fd = -1;
	lpc_socks[i].flags = 0;
	lpc_socks[i].mode = MUD;
	lpc_socks[i].state = CLOSED;
	memset((char *) &lpc_socks[i].l_addr, 0, sizeof(lpc_socks[i].l_addr));
	memset((char *) &lpc_socks[i].r_addr, 0, sizeof(lpc_socks[i].r_addr));
	lpc_socks[i].name[0] = '\0';
	lpc_socks[i].owner_ob = NULL;
	lpc_socks[i].release_ob = NULL;
	lpc_socks[i].read_callback[0] = '\0';
	lpc_socks[i].write_callback[0] = '\0';
	lpc_socks[i].close_callback[0] = '\0';
	lpc_socks[i].r_buf = NULL;
	lpc_socks[i].r_off = 0;
	lpc_socks[i].r_len = 0;
	lpc_socks[i].w_buf = NULL;
	lpc_socks[i].w_off = 0;
	lpc_socks[i].w_len = 0;
    }
}

/*
 * Create an LPC efun socket
 */
int
socket_create P3(enum socket_mode, mode, char *, read_callback, char *, close_callback)
{
    int type, i, fd, optval;
    int binary = 0;

    if (mode == STREAM_BINARY) {
	binary = 1;
	mode = STREAM;
    } else if (mode == DATAGRAM_BINARY) {
	binary = 1;
	mode = DATAGRAM;
    }
    switch (mode) {

    case MUD:
    case STREAM:
	type = SOCK_STREAM;
	break;
    case DATAGRAM:
	type = SOCK_DGRAM;
	break;

    default:
	return EEMODENOTSUPP;
    }

    for (i = 0; i < MAX_EFUN_SOCKS; i++) {
	if (lpc_socks[i].state != CLOSED)
	    continue;

	fd = socket(AF_INET, type, 0);
	if (fd == -1) {
	    perror("socket_create: socket");
	    return EESOCKET;
	}
	optval = 1;
	if (setsockopt(fd, SOL_SOCKET, SO_REUSEADDR, (char *) &optval,
		       sizeof(optval)) == -1) {
	    perror("socket_create: setsockopt");
	    close(fd);
	    return EESETSOCKOPT;
	}
	if (set_socket_nonblocking(fd, 1) == -1) {
	    perror("socket_create: set_socket_nonblocking");
	    close(fd);
	    return EENONBLOCK;
	}
	lpc_socks[i].fd = fd;
	lpc_socks[i].flags = S_HEADER;
	if (binary) {
	    lpc_socks[i].flags |= S_BINARY;
	}
	lpc_socks[i].mode = mode;
	lpc_socks[i].state = UNBOUND;
	memset((char *) &lpc_socks[i].l_addr, 0, sizeof(lpc_socks[i].l_addr));
	memset((char *) &lpc_socks[i].r_addr, 0, sizeof(lpc_socks[i].r_addr));
	lpc_socks[i].name[0] = '\0';
	lpc_socks[i].owner_ob = current_object;
	lpc_socks[i].release_ob = NULL;
	if (read_callback == NULL)
	    lpc_socks[i].read_callback[0] = '\0';
	else {
	    strncpy(lpc_socks[i].read_callback, read_callback, CALLBK_BUF_SIZE);
	    lpc_socks[i].read_callback[CALLBK_BUF_SIZE - 1] = '\0';
	}
	lpc_socks[i].write_callback[0] = '\0';
	if (type != SOCK_DGRAM && close_callback != NULL) {
	    strncpy(lpc_socks[i].close_callback, close_callback, CALLBK_BUF_SIZE);
	    lpc_socks[i].close_callback[CALLBK_BUF_SIZE - 1] = '\0';
	} else
	    lpc_socks[i].close_callback[0] = '\0';
	lpc_socks[i].r_buf = NULL;
	lpc_socks[i].r_off = 0;
	lpc_socks[i].r_len = 0;
	lpc_socks[i].w_buf = NULL;
	lpc_socks[i].w_off = 0;
	lpc_socks[i].w_len = 0;

	current_object->flags |= O_EFUN_SOCKET;

	debug(8192, ("socket_create: created socket %d mode %d fd %d\n",
		     i, mode, fd));

	return i;
    }

    return EENOSOCKS;
}

/*
 * Bind an address to an LPC efun socket
 */
int
socket_bind P2(int, fd, int, port)
{
    int len;
    struct sockaddr_in sin;

    if (fd < 0 || fd >= MAX_EFUN_SOCKS)
	return EEFDRANGE;
    if (lpc_socks[fd].state == CLOSED)
	return EEBADF;
    if (lpc_socks[fd].owner_ob != current_object)
	return EESECURITY;
    if (lpc_socks[fd].state != UNBOUND)
	return EEISBOUND;

    sin.sin_family = AF_INET;
    sin.sin_addr.s_addr = INADDR_ANY;
    sin.sin_port = htons((u_short) port);

    if (bind(lpc_socks[fd].fd, (struct sockaddr *) & sin, sizeof(sin)) == -1) {
	switch (errno) {
	case EADDRINUSE:
	    return EEADDRINUSE;
	default:
	    perror("socket_bind: bind");
	    return EEBIND;
	}
    }
    len = sizeof(sin);
    if (getsockname(lpc_socks[fd].fd, (struct sockaddr *) & lpc_socks[fd].l_addr, &len) == -1) {
	perror("socket_bind: getsockname");
	return EEGETSOCKNAME;
    }
    lpc_socks[fd].state = BOUND;

    debug(8192, ("socket_bind: bound socket %d to %s.%d\n",
		 fd, inet_ntoa(lpc_socks[fd].l_addr.sin_addr),
		 ntohs(lpc_socks[fd].l_addr.sin_port)));

    return EESUCCESS;
}

/*
 * Listen for connections on an LPC efun socket
 */
int
socket_listen P2(int, fd, char *, callback)
{
    if (fd < 0 || fd >= MAX_EFUN_SOCKS)
	return EEFDRANGE;
    if (lpc_socks[fd].state == CLOSED)
	return EEBADF;
    if (lpc_socks[fd].owner_ob != current_object)
	return EESECURITY;
    if (lpc_socks[fd].mode == DATAGRAM)
	return EEMODENOTSUPP;
    if (lpc_socks[fd].state == UNBOUND)
	return EENOADDR;
    if (lpc_socks[fd].state != BOUND)
	return EEISCONN;

    if (listen(lpc_socks[fd].fd, 5) == -1) {
	perror("socket_listen: listen");
	return EELISTEN;
    }
    lpc_socks[fd].state = LISTEN;
    strncpy(lpc_socks[fd].read_callback, callback, CALLBK_BUF_SIZE);
    lpc_socks[fd].read_callback[CALLBK_BUF_SIZE - 1] = '\0';

    current_object->flags |= O_EFUN_SOCKET;

    debug(8192, ("socket_listen: listen on socket %d\n", fd));

    return EESUCCESS;
}

/*
 * Accept a connection on an LPC efun socket
 */
int
socket_accept P3(int, fd, char *, read_callback, char *, write_callback)
{
    int len, accept_fd, i;
    struct sockaddr_in sin;
    struct hostent *hp;

    if (fd < 0 || fd >= MAX_EFUN_SOCKS)
	return EEFDRANGE;
    if (lpc_socks[fd].state == CLOSED)
	return EEBADF;
    if (lpc_socks[fd].owner_ob != current_object)
	return EESECURITY;
    if (lpc_socks[fd].mode == DATAGRAM)
	return EEMODENOTSUPP;
    if (lpc_socks[fd].state != LISTEN)
	return EENOTLISTN;

    lpc_socks[fd].flags &= ~S_WACCEPT;

    len = sizeof(sin);
    accept_fd = accept(lpc_socks[fd].fd, (struct sockaddr *) & sin, (int *) &len);
    if (accept_fd == -1) {
	switch (errno) {
	case EWOULDBLOCK:
	    return EEWOULDBLOCK;
	case EINTR:
	    return EEINTR;
	default:
	    perror("socket_accept: accept");
	    return EEACCEPT;
	}
    }
    for (i = 0; i < MAX_EFUN_SOCKS; i++) {
	fd_set wmask;
	struct timeval t;
	int nb;

	if (lpc_socks[i].state != CLOSED)
	    continue;

	lpc_socks[i].fd = accept_fd;
	lpc_socks[i].flags = S_HEADER |
	    (lpc_socks[fd].flags & S_BINARY);

	FD_ZERO(&wmask);
	FD_SET(accept_fd, &wmask);
	t.tv_sec = 0;
	t.tv_usec = 0;
#ifndef hpux
	nb = select(FD_SETSIZE, (fd_set *) 0, &wmask, (fd_set *) 0, &t);
#else
	nb = select(FD_SETSIZE, (int *) 0, (int *) &wmask, (int *) 0, &t);
#endif
	if (!(FD_ISSET(accept_fd, &wmask)))
	    lpc_socks[i].flags |= S_BLOCKED;

	lpc_socks[i].mode = lpc_socks[fd].mode;
	lpc_socks[i].state = DATA_XFER;
	lpc_socks[i].l_addr = lpc_socks[fd].l_addr;
	lpc_socks[i].r_addr = sin;
	lpc_socks[i].owner_ob = NULL;
	lpc_socks[i].release_ob = NULL;
	lpc_socks[i].read_callback[0] = '\0';
	lpc_socks[i].write_callback[0] = '\0';
	lpc_socks[i].close_callback[0] = '\0';
	lpc_socks[i].r_buf = NULL;
	lpc_socks[i].r_off = 0;
	lpc_socks[i].r_len = 0;
	lpc_socks[i].w_buf = NULL;
	lpc_socks[i].w_off = 0;
	lpc_socks[i].w_len = 0;

#ifdef cray
/* cray can't take addresses of bitfields */
	hp = gethostbyaddr((char *) &sin.sin_addr,
			   (int) sizeof(sin.sin_addr), AF_INET);
#else
	hp = gethostbyaddr((char *) &sin.sin_addr.s_addr,
			   (int) sizeof(sin.sin_addr.s_addr), AF_INET);
#endif
	if (hp != NULL) {
	    strncpy(lpc_socks[i].name, hp->h_name, ADDR_BUF_SIZE);
	    lpc_socks[i].name[ADDR_BUF_SIZE - 1] = '\0';
	} else
	    lpc_socks[i].name[0] = '\0';

	lpc_socks[i].owner_ob = current_object;
	strncpy(lpc_socks[i].read_callback, read_callback, CALLBK_BUF_SIZE);
	strncpy(lpc_socks[i].write_callback, write_callback, CALLBK_BUF_SIZE);
	strncpy(lpc_socks[i].close_callback, lpc_socks[fd].close_callback,
		CALLBK_BUF_SIZE);
	lpc_socks[i].read_callback[CALLBK_BUF_SIZE - 1] = '\0';
	lpc_socks[i].write_callback[CALLBK_BUF_SIZE - 1] = '\0';
	lpc_socks[i].close_callback[CALLBK_BUF_SIZE - 1] = '\0';

	current_object->flags |= O_EFUN_SOCKET;

	debug(8192, ("socket_accept: accept on socket %d\n", fd));
	debug(8192, ("socket_accept: new socket %d on fd %d\n", i, accept_fd));

	return i;
    }

    close(accept_fd);

    return EENOSOCKS;
}

/*
 * Connect an LPC efun socket
 */
int
socket_connect P4(int, fd, char *, name, char *, read_callback, char *, write_callback)
{
    if (fd < 0 || fd >= MAX_EFUN_SOCKS)
	return EEFDRANGE;
    if (lpc_socks[fd].state == CLOSED)
	return EEBADF;
    if (lpc_socks[fd].owner_ob != current_object)
	return EESECURITY;
    if (lpc_socks[fd].mode == DATAGRAM)
	return EEMODENOTSUPP;
    switch (lpc_socks[fd].state) {
    case CLOSED:
    case UNBOUND:
    case BOUND:
	break;
    case LISTEN:
	return EEISLISTEN;
    case DATA_XFER:
	return EEISCONN;
    }

    if (!socket_name_to_sin(name, &lpc_socks[fd].r_addr))
	return EEBADADDR;

    strncpy(lpc_socks[fd].read_callback, read_callback, CALLBK_BUF_SIZE);
    strncpy(lpc_socks[fd].write_callback, write_callback, CALLBK_BUF_SIZE);
    lpc_socks[fd].read_callback[CALLBK_BUF_SIZE - 1] = '\0';
    lpc_socks[fd].write_callback[CALLBK_BUF_SIZE - 1] = '\0';

    current_object->flags |= O_EFUN_SOCKET;

    if (connect(lpc_socks[fd].fd, (struct sockaddr *) & lpc_socks[fd].r_addr,
		sizeof(struct sockaddr_in)) == -1) {
	switch (errno) {
	case EINTR:
	    return EEINTR;
	case EADDRINUSE:
	    return EEADDRINUSE;
	case EALREADY:
	    return EEALREADY;
	case ECONNREFUSED:
	    return EECONNREFUSED;
	case EINPROGRESS:
	    break;
	default:
	    perror("socket_connect: connect");
	    return EECONNECT;
	}
    }
    lpc_socks[fd].state = DATA_XFER;
    lpc_socks[fd].flags |= S_BLOCKED;

    return EESUCCESS;
}

/*
 * Write a message on an LPC efun socket
 */
int
socket_write P3(int, fd, struct svalue *, message, char *, name)
{
    int len, off;
    char *buf, *p;
    struct sockaddr_in sin;

    if (fd < 0 || fd >= MAX_EFUN_SOCKS)
	return EEFDRANGE;
    if (lpc_socks[fd].state == CLOSED)
	return EEBADF;
    if (lpc_socks[fd].owner_ob != current_object)
	return EESECURITY;
    if (lpc_socks[fd].mode == DATAGRAM) {
	if (name == NULL)
	    return EENOADDR;
	if (!socket_name_to_sin(name, &sin))
	    return EEBADADDR;
    } else {
	if (lpc_socks[fd].state != DATA_XFER)
	    return EENOTCONN;
	if (name != NULL)
	    return EEBADADDR;
	if (lpc_socks[fd].flags & S_BLOCKED)
	    return EEALREADY;
    }

    switch (lpc_socks[fd].mode) {

    case MUD:
	switch (message->type) {

	case T_OBJECT:
	    return EETYPENOTSUPP;

	default:
	    save_svalue_depth = 0;
	    len = svalue_save_size(message);
	    if (save_svalue_depth > MAX_SAVE_SVALUE_DEPTH) {
		return EEBADDATA;
	    }
	    buf = (char *)
		DMALLOC(sizeof(long) + len + 1, TAG_TEMPORARY, "socket_write: default");
	    if (buf == NULL)
		crash_MudOS("Out of memory");
	    *(long *) buf = htonl((long) len);
	    len += sizeof(long);
	    buf[sizeof(long)] = '\0';
	    p = buf + sizeof(long);
	    save_svalue(message, &p);
	    break;
	}
	break;

    case STREAM:
	switch (message->type) {
	case T_BUFFER:
	    len = message->u.buf->size;
	    buf = (char *) DMALLOC(len, TAG_TEMPORARY, "socket_write: T_BUFFER");
	    if (buf == NULL)
		crash_MudOS("Out of memory");
	    memcpy(buf, message->u.buf->item, len);
	    break;
	case T_STRING:
	    len = strlen(message->u.string);
	    buf = (char *) DMALLOC(len + 1, TAG_TEMPORARY, "socket_write: T_STRING");
	    if (buf == NULL)
		crash_MudOS("Out of memory");
	    strcpy(buf, message->u.string);
	    break;
	case T_POINTER:
	    {
		int i, limit;
		struct svalue *el;

		len = message->u.vec->size * sizeof(int);
		buf = (char *) DMALLOC(len + 1, TAG_TEMPORARY, "socket_write: T_POINTER");
		if (buf == NULL)
		    crash_MudOS("Out of memory");
		el = message->u.vec->item;
		limit = len / sizeof(int);
		for (i = 0; i < limit; i++) {
		    switch (el[i].type) {
		    case T_NUMBER:
			memcpy((char *) &buf[i * sizeof(int)],
			       (char *) &el[i].u.number, sizeof(int));
			break;
		    case T_REAL:
			memcpy((char *) &buf[i * sizeof(int)], (char *) &el[i].u.real,
			       sizeof(int));
			break;
		    default:
			break;
		    }
		}
		break;
	    }
	default:
	    return EETYPENOTSUPP;
	}
	break;

    case DATAGRAM:
	switch (message->type) {

	case T_STRING:
	    if (sendto(lpc_socks[fd].fd, (char *)message->u.string,
		       strlen(message->u.string) + 1, 0,
		       (struct sockaddr *) & sin, sizeof(sin)) == -1) {
		perror("socket_write: sendto");
		return EESENDTO;
	    }
	    return EESUCCESS;


	case T_BUFFER:
	    if (sendto(lpc_socks[fd].fd, (char *)message->u.buf->item,
		       message->u.buf->size, 0,
		       (struct sockaddr *) & sin, sizeof(sin)) == -1) {
		perror("socket_write: sendto");
		return EESENDTO;
	    }
	    return EESUCCESS;

	default:
	    return EETYPENOTSUPP;
	}

    default:
	return EEMODENOTSUPP;
    }

    off = write(lpc_socks[fd].fd, buf, len);
    if (off == -1) {
	FREE(buf);
	switch (errno) {

	case EWOULDBLOCK:
	    return EEWOULDBLOCK;

	default:
	    perror("socket_write: send");
	    return EESEND;
	}
    }
    if (off < len) {
	lpc_socks[fd].flags |= S_BLOCKED;
	lpc_socks[fd].w_buf = buf;
	lpc_socks[fd].w_off = off;
	lpc_socks[fd].w_len = len - off;
	return EECALLBACK;
    }
    FREE(buf);

    return EESUCCESS;
}

/*
 * Handle LPC efun socket read select events
 */
void
socket_read_select_handler P1(int, fd)
{
    int cc = 0, addrlen;
    char buf[BUF_SIZE], addr[ADDR_BUF_SIZE];
    struct svalue value;
    struct sockaddr_in sin;
    struct object *save_current_object;

    debug(8192, ("read_socket_handler: fd %d state %d\n",
		 fd, lpc_socks[fd].state));

    switch (lpc_socks[fd].state) {

    case CLOSED:
    case UNBOUND:
	return;

    case BOUND:
	switch (lpc_socks[fd].mode) {

	case MUD:
	case STREAM:
	    break;

	case DATAGRAM:
	    debug(8192, ("read_socket_handler: DATA_XFER DATAGRAM\n"));
	    addrlen = sizeof(sin);
	    cc = recvfrom(lpc_socks[fd].fd, buf, sizeof(buf) - 1, 0,
			  (struct sockaddr *) & sin, &addrlen);
	    if (cc <= 0)
		break;
	    debug(8192, ("read_socket_handler: read %d bytes\n", cc));
	    buf[cc] = '\0';
	    sprintf(addr, "%s %d", inet_ntoa(sin.sin_addr),
		    (int)ntohs(sin.sin_port));
	    push_number(fd);
	    if (lpc_socks[fd].flags & S_BINARY) {
		struct buffer *b;

		b = allocate_buffer(cc);
		if (b) {
		    memcpy(b->item, buf, cc);
		    push_refed_buffer(b);
		} else {
		    push_number(0);
		}
	    } else {
		push_string(buf, STRING_MALLOC);
	    }
	    push_string(addr, STRING_MALLOC);
	    debug(8192, ("read_socket_handler: apply\n"));
	    save_current_object = current_object;
	    current_object = lpc_socks[fd].owner_ob;
	    safe_apply(lpc_socks[fd].read_callback, lpc_socks[fd].owner_ob, 3,
		       ORIGIN_DRIVER);
	    current_object = save_current_object;
	    return;
	}
	break;

    case LISTEN:
	debug(8192, ("read_socket_handler: apply read callback\n"));
	lpc_socks[fd].flags |= S_WACCEPT;
	push_number(fd);
	save_current_object = current_object;
	current_object = lpc_socks[fd].owner_ob;
	safe_apply(lpc_socks[fd].read_callback, lpc_socks[fd].owner_ob, 1, ORIGIN_DRIVER);
	current_object = save_current_object;
	return;

    case DATA_XFER:
	switch (lpc_socks[fd].mode) {

	case DATAGRAM:
	    break;

	case MUD:
	    debug(8192, ("read_socket_handler: DATA_XFER MUD\n"));
	    if (lpc_socks[fd].flags & S_HEADER) {
		cc = recv(lpc_socks[fd].fd, (char *) &lpc_socks[fd].r_len +
			  lpc_socks[fd].r_off, sizeof(long) -
			  lpc_socks[fd].r_off, 0);
		if (cc <= 0)
		    break;
		debug(8192, ("read_socket_handler: read %d bytes\n", cc));
		lpc_socks[fd].r_off += cc;
		if (lpc_socks[fd].r_off != sizeof(long))
		    return;
		debug(8192, ("read_socket_handler: read header\n"));
		lpc_socks[fd].flags &= ~S_HEADER;
		lpc_socks[fd].r_off = 0;
		lpc_socks[fd].r_len = ntohl(lpc_socks[fd].r_len);
		lpc_socks[fd].r_buf = (char *)
		    DMALLOC(lpc_socks[fd].r_len + 1, TAG_TEMPORARY, "socket_read_select_handler");
		if (lpc_socks[fd].r_buf == NULL)
		    crash_MudOS("Out of memory");
		debug(8192, ("read_socket_handler: svalue len is %d\n",
			     lpc_socks[fd].r_len));
	    }
	    if (lpc_socks[fd].r_off < lpc_socks[fd].r_len) {
		cc = recv(lpc_socks[fd].fd, lpc_socks[fd].r_buf +
			  lpc_socks[fd].r_off, lpc_socks[fd].r_len -
			  lpc_socks[fd].r_off, 0);
		if (cc <= 0)
		    break;
		debug(8192, ("read_socket_handler: read %d bytes\n", cc));
		lpc_socks[fd].r_off += cc;
		if (lpc_socks[fd].r_off != lpc_socks[fd].r_len)
		    return;
		debug(8192, ("read_socket_handler: read svalue\n"));
	    }
	    lpc_socks[fd].r_buf[lpc_socks[fd].r_len] = '\0';
	    value = const0;
	    push_number(fd);
	    if (restore_svalue(lpc_socks[fd].r_buf, &value) == 0)
		push_svalue(&value);
	    else
		push_null();
	    FREE(lpc_socks[fd].r_buf);
	    lpc_socks[fd].flags |= S_HEADER;
	    lpc_socks[fd].r_buf = NULL;
	    lpc_socks[fd].r_off = 0;
	    lpc_socks[fd].r_len = 0;
	    debug(8192, ("read_socket_handler: apply read callback\n"));
	    save_current_object = current_object;
	    current_object = lpc_socks[fd].owner_ob;
	    safe_apply(lpc_socks[fd].read_callback, lpc_socks[fd].owner_ob, 2, ORIGIN_DRIVER);
	    current_object = save_current_object;
	    return;

	case STREAM:
	    debug(8192, ("read_socket_handler: DATA_XFER STREAM\n"));
	    cc = read(lpc_socks[fd].fd, buf, sizeof(buf) - 1);
	    if (cc <= 0)
		break;
	    debug(8192, ("read_socket_handler: read %d bytes\n", cc));
	    buf[cc] = '\0';
	    push_number(fd);
	    if (lpc_socks[fd].flags & S_BINARY) {
		struct buffer *b;

		b = allocate_buffer(cc);
		if (b) {
		    b->ref--;
		    memcpy(b->item, buf, cc);
		    push_buffer(b);
		} else {
		    push_number(0);
		}
	    } else {
		push_string(buf, STRING_MALLOC);
	    }
	    debug(8192, ("read_socket_handler: apply read callback\n"));
	    save_current_object = current_object;
	    current_object = lpc_socks[fd].owner_ob;
	    safe_apply(lpc_socks[fd].read_callback, lpc_socks[fd].owner_ob, 2, ORIGIN_DRIVER);
	    current_object = save_current_object;
	    return;
	}
	break;
    }
    if (cc == -1) {
	switch (errno) {
	case EINTR:
	case EWOULDBLOCK:
	    return;
	default:
	    break;
	}
    }
    save_current_object = current_object;
    current_object = lpc_socks[fd].owner_ob;
    socket_close(fd);
    current_object = save_current_object;

    debug(8192, ("read_socket_handler: apply close callback\n"));
    push_number(fd);
    save_current_object = current_object;
    current_object = lpc_socks[fd].owner_ob;
    safe_apply(lpc_socks[fd].close_callback, lpc_socks[fd].owner_ob, 1, ORIGIN_DRIVER);
    current_object = save_current_object;
}

/*
 * Handle LPC efun socket write select events
 */
void
socket_write_select_handler P1(int, fd)
{
    int cc;
    struct object *save_current_object;

    debug(8192, ("write_socket_handler: fd %d state %d\n",
		 fd, lpc_socks[fd].state));

    if ((lpc_socks[fd].flags & S_BLOCKED) == 0)
	return;

    if (lpc_socks[fd].w_buf != NULL) {
	cc = write(lpc_socks[fd].fd, lpc_socks[fd].w_buf + lpc_socks[fd].w_off,
		   lpc_socks[fd].w_len);
	if (cc == -1)
	    return;
	lpc_socks[fd].w_off += cc;
	lpc_socks[fd].w_len -= cc;
	if (lpc_socks[fd].w_len != 0)
	    return;
	FREE(lpc_socks[fd].w_buf);
	lpc_socks[fd].w_buf = NULL;
	lpc_socks[fd].w_off = 0;
    }
    lpc_socks[fd].flags &= ~S_BLOCKED;

    debug(8192, ("write_socket_handler: apply write_callback\n"));

    push_number(fd);
    save_current_object = current_object;
    current_object = lpc_socks[fd].owner_ob;
    safe_apply(lpc_socks[fd].write_callback, lpc_socks[fd].owner_ob, 1, ORIGIN_DRIVER);
    current_object = save_current_object;
}

/*
 * Close an LPC efun socket
 */
int
socket_close P1(int, fd)
{
    if (fd < 0 || fd >= MAX_EFUN_SOCKS)
	return EEFDRANGE;
    if (lpc_socks[fd].state == CLOSED)
	return EEBADF;
    if (lpc_socks[fd].owner_ob != current_object)
	return EESECURITY;
    while (close(lpc_socks[fd].fd) == -1 && errno == EINTR)
	;	/* empty while */
    lpc_socks[fd].state = CLOSED;
    if (lpc_socks[fd].r_buf != NULL)
	FREE(lpc_socks[fd].r_buf);
    if (lpc_socks[fd].w_buf != NULL)
	FREE(lpc_socks[fd].w_buf);
    debug(8192, ("socket_close: closed fd %d\n", fd));
    return EESUCCESS;
}

/*
 * Release an LPC efun socket to another object
 */
int
socket_release P3(int, fd, struct object *, ob, char *, callback)
{
    struct object *save_current_object;

    if (fd < 0 || fd >= MAX_EFUN_SOCKS)
	return EEFDRANGE;
    if (lpc_socks[fd].state == CLOSED)
	return EEBADF;
    if (lpc_socks[fd].owner_ob != current_object)
	return EESECURITY;
    if (lpc_socks[fd].flags & S_RELEASE)
	return EESOCKRLSD;

    lpc_socks[fd].flags |= S_RELEASE;
    lpc_socks[fd].release_ob = ob;

    push_number(fd);
    push_object(ob);
    save_current_object = current_object;
    current_object = ob;
    safe_apply(callback, ob, 2, ORIGIN_DRIVER);
    current_object = save_current_object;

    if ((lpc_socks[fd].flags & S_RELEASE) == 0)
	return EESUCCESS;

    lpc_socks[fd].flags &= ~S_RELEASE;
    lpc_socks[fd].release_ob = NULL;

    return EESOCKNOTRLSD;
}

/*
 * Aquire an LPC efun socket from another object
 */
int
socket_acquire P4(int, fd, char *, read_callback, char *, write_callback, char *, close_callback)
{
    if (fd < 0 || fd >= MAX_EFUN_SOCKS)
	return EEFDRANGE;
    if (lpc_socks[fd].state == CLOSED)
	return EEBADF;
    if ((lpc_socks[fd].flags & S_RELEASE) == 0)
	return EESOCKNOTRLSD;
    if (lpc_socks[fd].release_ob != current_object)
	return EESECURITY;

    lpc_socks[fd].flags &= ~S_RELEASE;
    lpc_socks[fd].owner_ob = current_object;
    lpc_socks[fd].release_ob = NULL;

    strncpy(lpc_socks[fd].read_callback, read_callback, CALLBK_BUF_SIZE);
    strncpy(lpc_socks[fd].write_callback, write_callback, CALLBK_BUF_SIZE);
    strncpy(lpc_socks[fd].close_callback, close_callback, CALLBK_BUF_SIZE);
    lpc_socks[fd].read_callback[CALLBK_BUF_SIZE - 1] = '\0';
    lpc_socks[fd].write_callback[CALLBK_BUF_SIZE - 1] = '\0';
    lpc_socks[fd].close_callback[CALLBK_BUF_SIZE - 1] = '\0';

    return EESUCCESS;
}

/*
 * Return the string representation of a socket error
 */
char *
     socket_error P1(int, error)
{
    error = -(error + 1);
    if (error < 0 || error >= ERROR_STRINGS)
	return "socket_error: invalid error number";
    return error_strings[error];
}

/*
 * Return the remote address for an LPC efun socket
 */
int get_socket_address P3(int, fd, char *, addr, int *, port)
{
    if (fd < 0 || fd >= MAX_EFUN_SOCKS) {
	addr[0] = '\0';
	*port = 0;
	return EEFDRANGE;
    }
    *port = (int) ntohs(lpc_socks[fd].r_addr.sin_port);
    sprintf(addr, "%s", inet_ntoa(lpc_socks[fd].r_addr.sin_addr));
    return EESUCCESS;
}

/*
 * Return the current socket owner
 */
struct object *
       get_socket_owner P1(int, fd)
{
    if (fd < 0 || fd >= MAX_EFUN_SOCKS)
	return (struct object *) NULL;
    if (lpc_socks[fd].state == CLOSED)
	return (struct object *) NULL;
    return lpc_socks[fd].owner_ob;
}

/*
 * Initialize a T_OBJECT svalue
 */
void
assign_socket_owner P2(struct svalue *, sv, struct object *, ob)
{
    if (ob != NULL) {
	sv->type = T_OBJECT;
	sv->u.ob = ob;
	add_ref(ob, "assign_socket_owner");
    } else
	assign_svalue_no_free(sv, &const0n);
}

/*
 * Convert a string representation of an address to a sockaddr_in
 */
static int
socket_name_to_sin P2(char *, name, struct sockaddr_in *, sin)
{
    int port;
    char *cp, addr[ADDR_BUF_SIZE];

    strncpy(addr, name, ADDR_BUF_SIZE);
    addr[ADDR_BUF_SIZE - 1] = '\0';

    cp = strchr(addr, ' ');
    if (cp == NULL)
	return 0;

    *cp = '\0';
    port = atoi(cp + 1);

    sin->sin_family = AF_INET;
    sin->sin_port = htons((u_short) port);
    sin->sin_addr.s_addr = inet_addr(addr);

    return 1;
}

/*
 * Close any sockets owned by ob
 */
void
close_referencing_sockets P1(struct object *, ob)
{
    int i;
    struct object *save_current_object;

    save_current_object = current_object;

    current_object = ob;
    for (i = 0; i < MAX_EFUN_SOCKS; i++)
	if (lpc_socks[i].owner_ob == ob && lpc_socks[i].state != CLOSED)
	    socket_close(i);

    current_object = save_current_object;
}

/*
 * Return the string representation of a sockaddr_in
 */
static char *
     inet_address P1(struct sockaddr_in *, sin)
{
    static char addr[23], port[7];

    if (ntohl(sin->sin_addr.s_addr) == INADDR_ANY)
	strcpy(addr, "*");
    else
	strcpy(addr, inet_ntoa(sin->sin_addr));
    strcat(addr, ".");
    if (ntohs(sin->sin_port) == 0)
	strcpy(port, "*");
    else
	sprintf(port, "%d", (int)ntohs(sin->sin_port));
    strcat(addr, port);

    return (addr);
}

/*
 * Dump the LPC efun socket array
 */
void dump_socket_status()
{
    int i;

    add_message("Fd    State      Mode       Local Address          Remote Address\n");
    add_message("--  ---------  --------  ---------------------  ---------------------\n");

    for (i = 0; i < MAX_EFUN_SOCKS; i++) {
	add_vmessage("%2d  ", lpc_socks[i].fd);

	switch (lpc_socks[i].state) {
	case CLOSED:
	    add_message("  CLOSED ");
	    break;
	case UNBOUND:
	    add_message(" UNBOUND ");
	    break;
	case BOUND:
	    add_message("  BOUND  ");
	    break;
	case LISTEN:
	    add_message(" LISTEN  ");
	    break;
	case DATA_XFER:
	    add_message("DATA_XFER");
	    break;
	default:
	    add_message("    ??    ");
	    break;
	}
	add_message("  ");

	switch (lpc_socks[i].mode) {
	case MUD:
	    add_message("   MUD  ");
	    break;
	case STREAM:
	    add_message(" STREAM ");
	    break;
	case DATAGRAM:
	    add_message("DATAGRAM");
	    break;
	default:
	    add_message("   ??   ");
	    break;
	}
	add_message("  ");

	add_vmessage("%-21s  ", inet_address(&lpc_socks[i].l_addr));
	add_vmessage("%-21s\n", inet_address(&lpc_socks[i].r_addr));
    }
}
#endif				/* SOCKET_EFUNS */
