#include "std.h"
#include "network_incl.h"

#ifndef OS2
/*
  ioctl.c: part of the MudOS release -- Truilkan@TMI

  isolates the code which sets the various socket modes since various
  machines seem to need this done in different ways.
*/

#if defined(SVR4)
#include <sys/filio.h>
#include <sys/sockio.h>
#endif

/*
 * set process receiving SIGIO/SIGURG signals to us.
 */

INLINE int set_socket_owner P2(int, fd, int, which)
{
#ifdef OLD_ULTRIX
    return fcntl(fd, F_SETOWN, which);
#else
    return ioctl(fd, SIOCSPGRP, &which);
#endif
}

/*
 * allow receipt of asynchronous I/O signals.
 */

INLINE int set_socket_async P2(int, fd, int, which)
{
#ifdef OLD_ULTRIX
    return fcntl(fd, F_SETFL, FASYNC);
#else
    return ioctl(fd, FIOASYNC, &which);
#endif
}

/*
 * set socket non-blocking
 */

INLINE int set_socket_nonblocking P2(int, fd, int, which)
{
#if !defined(OLD_ULTRIX) && !defined(_SEQUENT_)
    int result;

#endif

#ifdef OLD_ULTRIX
    if (which)
	return fcntl(fd, F_SETFL, FNDELAY);
    else
	return fcntl(fd, F_SETFL, FNBLOCK);
#else

#ifdef _SEQUENT_
    int flags = fcntl(fd, F_GETFL, 0);

    if (flags == -1)
	return (-1);
    if (which)
	flags |= O_NONBLOCK;
    else
	flags &= ~O_NONBLOCK;
    return fcntl(fd, F_SETFL, flags);
#else
    result = ioctl(fd, FIONBIO, &which);
    if (result == -1) {
	fprintf(stderr, "Try using cc instead of gcc to correct this error.\n");
    }
    return result;
#endif

#endif
}

#endif				/* OS2 */
