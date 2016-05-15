/*
  binaries.c: code to save loaded LPC objects to binary files (in order
  to speed loading during subsequent runs of the driver).

  This is mostly original code by Darin Johnson.  Ideas came from CD,
  including crdir_fopen().  Feel free to use this code but please keep
  credits intact.
*/

#include "std.h"
#include "config.h"
#include "lpc_incl.h"
#include "file_incl.h"
#include "compiler.h"
#include "binaries.h"
#include "lex.h"
#include "backend.h"
#include "swap.h"
#include "qsort.h"

#ifdef OPTIMIZE_FUNCTION_TABLE_SEARCH
#include "functab_tree.h"
#endif

#ifdef BINARIES

static char *magic_id = "MUDB";
static time_t driver_id;
static time_t config_id;

char driver_name[512];

#ifndef MAXSHORT
#define MAXSHORT ((1 << (sizeof(short)*8)) - 1)
#endif

static void patch_out PROT((struct program *, short *, int));
static void patch_in PROT((struct program *, short *, int));
static int str_case_cmp PROT((char *, char *));
static int check_times PROT((time_t, char *));
static int do_stat PROT((char *, struct stat *, char *));

/*
 * stats fname or CONFIG_FILE_DIR/fname (for finding config files) and/or
 * BIN_DIR/fname (for finding config files and/or driver), whichever exists.
 */
static int
do_stat P3(char *, fname, struct stat *, st, char *, pathname)
{
    int i;
    char buf[256];

#ifdef OS2
    int bing = 1;

    if ((i = stat(fname, st)) == -1) {
	getcwd(buf, 256);
	strcat(buf, argv[0]);
	if ((i = stat(buf, st)) == -1) {
	    if (pathname) {
		strcat(buf, ".exe");
		if ((i = stat(buf, st)) == -1)
		    bing = 0;
	    } else
		bing = 0
		}
		}
	    if (bing) {
#else
    if ((i = stat(fname, st)) != -1) {
#endif
	if (pathname)
	    strcpy(pathname, fname);
	return i;
    }
    /* look in CONFIG_FILE_DIR */
    if (!pathname) {
#ifdef OS2
	sprintf(buf, "%s\\%s", CONFIG_FILE_DIR, fname);
#else
#ifdef LATTICE
	if (strchr(CONFIG_FILE_DIR, ':'))
	    sprintf(buf, "%s%s", CONFIG_FILE_DIR, fname);
	else
#endif
	    sprintf(buf, "%s/%s", CONFIG_FILE_DIR, fname);
#endif
	if ((i = stat(buf, st)) != -1)
	    return i;
    }
    /* look in BIN_DIR */
#ifdef OS2
    sprintf(buf, "%s\\%s", BIN_DIR, fname);
#else
#ifdef LATTICE
    if (strchr(BIN_DIR, ':'))
	sprintf(buf, "%s%s", BIN_DIR, fname);
    else
#endif
	sprintf(buf, "%s/%s", BIN_DIR, fname);
#endif

#ifdef OS2
    bing = 1;
    if ((i = stat(buf, st)) == -1) {
	if (pathname) {
	    strcat(buf, ".exe");
	    if ((i = stat(buf, st)) == -1)
		bing = 0;
	} else
	    bing = 0;
    }
    if (bing) {
#else
    if ((i = stat(buf, st)) != -1) {
#endif
	if (pathname)
	    strcpy(pathname, buf);
	return i;
    }
    return -1;
}				/* do_stat() */

void save_binary P3(struct program *, prog, struct mem_block *, includes, struct mem_block *, patches)
{
    char file_name_buf[200];
    char *file_name = file_name_buf;
    FILE *f;
    int i, tmp;
    short len;
    struct program *p;
    struct stat st;

    struct svalue *ret;
    char *nm;

    nm = add_slash(prog->name);
    push_malloced_string(nm);
    ret = safe_apply_master_ob(APPLY_VALID_SAVE_BINARY, 1);
    if (!MASTER_APPROVED(ret))
	return;
    if (prog->p.i.total_size > (int) MAXSHORT ||
	includes->current_size > (int) MAXSHORT)
	/* assume all other sizes ok */
	return;

    strcpy(file_name, SAVE_BINARIES);
    if (file_name[0] == '/')
	file_name++;
    if (stat(file_name, &st) == -1)
	return;
    strcat(file_name, "/");
    strcat(file_name, prog->name);
    len = strlen(file_name);
    file_name[len - 1] = 'b';	/* change .c ending to .b */

    if (!(f = crdir_fopen(file_name)))
	return;

    if (comp_flag) {
	fprintf(stderr, " saving binary ... ");
#ifdef LATTICE
	fflush(stderr);
#endif
    }
    /*
     * Write out preamble.  Includes magic number, etc, all of which must
     * match while loading.
     */
    if (fwrite(magic_id, strlen(magic_id), 1, f) != 1 ||
	fwrite((char *) &driver_id, sizeof driver_id, 1, f) != 1 ||
	fwrite((char *) &config_id, sizeof config_id, 1, f) != 1) {
	debug_message("I/O error in save_binary.\n");
	fclose(f);
	unlink(file_name);
	return;
    }
    /*
     * Write out list of include files.
     */
    len = includes->current_size;
    fwrite((char *) &len, sizeof len, 1, f);
    fwrite(includes->block, includes->current_size, 1, f);

    /*
     * copy and patch program
     */
    p = (struct program *) DXALLOC(prog->p.i.total_size, TAG_TEMPORARY, "save_binary");
    /* convert to relative pointers, copy, then convert back */
    locate_out(prog);
    memcpy(p, prog, prog->p.i.total_size);
    locate_in(prog);
    if (patches->current_size) {
	locate_in(p);
	patch_out(p, (short *) patches->block,
		  patches->current_size / sizeof(short));
	locate_out(p);
    }
    /*
     * write out prog.  The prog structure is mostly setup, but strings will
     * have to be stored specially.
     */
    len = strlen(p->name);
    fwrite((char *) &len, sizeof len, 1, f);
    fwrite(p->name, sizeof(char), len, f);

    fwrite((char *) &p->p.i.total_size, sizeof p->p.i.total_size, 1, f);
    fwrite((char *) p, p->p.i.total_size, 1, f);
    FREE(p);
    p = prog;

    /* inherit names */
    for (i = 0; i < (int) p->p.i.num_inherited; i++) {
	len = strlen(p->p.i.inherit[i].prog->name);
	fwrite((char *) &len, sizeof len, 1, f);
	fwrite(p->p.i.inherit[i].prog->name, sizeof(char), len, f);
    }

    /* string table */
    for (i = 0; i < (int) p->p.i.num_strings; i++) {
	tmp = strlen(p->p.i.strings[i]);
	if (tmp > (int) MAXSHORT) {	/* possible? */
	    fclose(f);
	    unlink(file_name);
	    error("String to long for save_binary.\n");
	    return;
	}
	len = tmp;
	fwrite((char *) &len, sizeof len, 1, f);
	fwrite(p->p.i.strings[i], sizeof(char), len, f);
    }

    /* var names */
    for (i = 0; i < (int) p->p.i.num_variables; i++) {
	len = strlen(p->p.i.variable_names[i].name);
	fwrite((char *) &len, sizeof len, 1, f);
	fwrite(p->p.i.variable_names[i].name, sizeof(char), len, f);
    }

    /* function names */
    for (i = 0; i < (int) p->p.i.num_functions; i++) {
	len = strlen(p->p.i.functions[i].name);
	fwrite((char *) &len, sizeof len, 1, f);
	fwrite(p->p.i.functions[i].name, sizeof(char), len, f);
    }

    /* line_numbers */
    if (p->p.i.line_info)
	len = p->p.i.file_info[0];
    else
	len = 0;
    fwrite((char *) &len, sizeof len, 1, f);
    fwrite((char *) p->p.i.file_info, len, 1, f);

    /*
     * patches
     */
    len = patches->current_size;
    fwrite((char *) &len, sizeof len, 1, f);
    fwrite(patches->block, patches->current_size, 1, f);

    fclose(f);
}				/* save_binary() */

#define ALLOC_BUF(size) \
    if ((size) > buf_size) { FREE(buf); buf = DXALLOC(buf_size = size, TAG_TEMPORARY, "ALLOC_BUF"); }

int load_binary P1(char *, name)
{
    char file_name_buf[400];
    char *buf, *iname, *file_name = file_name_buf, *file_name_two = &file_name_buf[200];
    FILE *f;
    int i, buf_size, ilen;
    time_t mtime;
    short len;
    struct program *p;
    struct object *ob;
    struct stat st;

#ifdef LPC_TO_C
    void (**jump_table) (struct svalue *);
    int err;
    char *code;
#endif

    /* stuff from prolog() */
    prog = 0;
    num_parse_error = 0;

    sprintf(file_name, "%s/%s", SAVE_BINARIES, name);
    if (file_name[0] == '/')
	file_name++;
    len = strlen(file_name);
    file_name[len - 1] = 'b';	/* change .c ending to .b */

#ifdef OS2
    /* Put /'s in all the right places.... */
    {
	char *bing = file_name;

	while (bing) {
	    bing = strchr(bing, '/');
	    if (bing)
		*bing = '\\';
	}
    }
#endif

    if (stat(file_name, &st) != -1)
	mtime = st.st_mtime;
    else
	return 0;

#ifdef OS2
    if (!(f = fopen(file_name, "rb")))
	return 0;
#else
    if (!(f = fopen(file_name, "r")))
	return 0;
#endif

    if (comp_flag) {
	fprintf(stderr, " loading binary %s ... ", name);
#ifdef LATTICE
	fflush(stderr);
#endif
    }
    /* see if we're out of date with source */
    if (check_times(mtime, name) <= 0) {
	if (comp_flag)
	    fprintf(stderr, "out of date (source file newer).\n");
	fclose(f);
	return 0;
    }
    buf = DXALLOC(buf_size = SMALL_STRING_SIZE, TAG_TEMPORARY, "ALLOC_BUF");

    /*
     * Read preamble.  This must match, or we assume a different driver or
     * configuration.
     */
    if (fread(buf, strlen(magic_id), 1, f) != 1 ||
	strncmp(buf, magic_id, strlen(magic_id)) != 0) {
	if (comp_flag)
	    fprintf(stderr, "out of date. (bad magic number)\n");
	fclose(f);
	FREE(buf);
	return 0;
    }
    if (fread((char *) &i, sizeof i, 1, f) != 1 || driver_id != i) {
	if (comp_flag)
	    fprintf(stderr, "out of date. (driver changed)\n");
	fclose(f);
	FREE(buf);
	return 0;
    }
    if (fread((char *) &i, sizeof i, 1, f) != 1 || config_id != i) {
	if (comp_flag)
	    fprintf(stderr, "out of date. (config file changed)\n");
	fclose(f);
	FREE(buf);
	return 0;
    }
    /*
     * read list of includes and check times
     */
    fread((char *) &len, sizeof len, 1, f);
    ALLOC_BUF(len);
    fread(buf, sizeof(char), len, f);
    for (iname = buf; iname < buf + len; iname += strlen(iname) + 1) {
	if (check_times(mtime, iname) <= 0) {
	    if (comp_flag)
		fprintf(stderr, "out of date (include file newer).\n");
	    fclose(f);
	    FREE(buf);
	    return 0;
	}
    }

    /* check program name */
    fread((char *) &len, sizeof len, 1, f);
    ALLOC_BUF(len + 1);
    fread(buf, sizeof(char), len, f);
    buf[len] = '\0';
    if (strcmp(name, buf) != 0) {
	if (comp_flag)
	    fprintf(stderr, "binary name inconsistent with file.\n");
	fclose(f);
	FREE(buf);
	return 0;
    }
    /*
     * Read program structure.
     */
    fread((char *) &ilen, sizeof ilen, 1, f);
    p = (struct program *) DXALLOC(ilen, TAG_PROGRAM, "load_binary");
    fread((char *) p, ilen, 1, f);
    locate_in(p);		/* from swap.c */
    p->name = make_shared_string(name);

    /* Read inherit names and find prog.  Check mod times also. */
    for (i = 0; i < (int) p->p.i.num_inherited; i++) {
	fread((char *) &len, sizeof len, 1, f);
	ALLOC_BUF(len + 1);
	fread(buf, sizeof(char), len, f);
	buf[len] = '\0';

	/*
	 * Check times against inherited source.  If saved binary of
	 * inherited prog exists, check against it also.
	 */
	sprintf(file_name_two, "%s/%s", SAVE_BINARIES, buf);
	if (file_name_two[0] == '/')
	    file_name_two++;
	len = strlen(file_name_two);
	file_name_two[len - 1] = 'b';
	if (check_times(mtime, buf) <= 0 ||
	    check_times(mtime, file_name_two) == 0) {	/* ok if -1 */

	    if (comp_flag)
		fprintf(stderr, "out of date (inherited source newer).\n");
	    fclose(f);
	    free_string(p->name);
	    FREE(p);
	    FREE(buf);
	    return 0;
	}
	/* find inherited program (maybe load it here?) */
	ob = find_object2(buf);
	if (!ob) {
	    if (comp_flag)
		fprintf(stderr, "missing inherited prog.\n");
	    fclose(f);
	    free_string(p->name);
	    FREE(p);
	    inherit_file = buf;	/* freed elsewhere */
	    return 1;		/* not 0 */
	}
	p->p.i.inherit[i].prog = ob->prog;
    }

    /* Read string table */
    for (i = 0; i < (int) p->p.i.num_strings; i++) {
	fread((char *) &len, sizeof len, 1, f);
	ALLOC_BUF(len + 1);
	fread(buf, sizeof(char), len, f);
	buf[len] = '\0';
	p->p.i.strings[i] = make_shared_string(buf);
    }

    /* var names */
    for (i = 0; i < (int) p->p.i.num_variables; i++) {
	fread((char *) &len, sizeof len, 1, f);
	ALLOC_BUF(len + 1);
	fread(buf, sizeof(char), len, f);
	buf[len] = '\0';
	p->p.i.variable_names[i].name = make_shared_string(buf);
    }

#ifdef OPTIMIZE_FUNCTION_TABLE_SEARCH
    /* function table tree's root */
    p->p.i.tree_r = (unsigned short) 0xffff;
#endif

    /* function names */
    for (i = 0; i < (int) p->p.i.num_functions; i++) {
	fread((char *) &len, sizeof len, 1, f);
	ALLOC_BUF(len + 1);
	fread(buf, sizeof(char), len, f);
	buf[len] = '\0';
	p->p.i.functions[i].name = make_shared_string(buf);

#ifdef OPTIMIZE_FUNCTION_TABLE_SEARCH
	/* rebuild function table tree */
	if (!(p->p.i.functions[i].flags & NAME_ALIAS))
	    add_function(p->p.i.functions, &p->p.i.tree_r, i);
#endif
    }

    /* line numbers */
    fread((char *) &len, sizeof len, 1, f);
    p->p.i.file_info = (unsigned short *) DXALLOC(len, TAG_LINENUMBERS, "load binary");
    fread((char *) p->p.i.file_info, len, 1, f);
    p->p.i.line_info = (unsigned char *)&p->p.i.file_info[p->p.i.file_info[1]];

    /* patches */
    fread((char *) &len, sizeof len, 1, f);
    ALLOC_BUF(len);
    fread(buf, len, 1, f);
    /* fix up some stuff */
    patch_in(p, (short *) buf, len / sizeof(short));

    fclose(f);
    FREE(buf);

    /*
     * Now finish everything up.  (stuff from epilog())
     */
    prog = p;
    prog->p.i.id_number = get_id_number();

    total_prog_block_size += prog->p.i.total_size;
    total_num_prog_blocks += 1;

    swap_line_numbers(prog);
    reference_prog(prog, "load_binary");
    for (i = 0; (unsigned) i < prog->p.i.num_inherited; i++) {
	reference_prog(prog->p.i.inherit[i].prog, "inheritance");
    }

#ifdef LPC_TO_C
    if (prog->p.i.program_size == 0) {
#ifdef RUNTIME_LOADING
	/*
	 * The binary we just loaded was a compiled file.  Look for the
	 * corresponding .B file, and link it.  Or possibly use a modified .c
	 * file if it exists.
	 */

	file_name[strlen(file_name) - 1] = 'B';	/* change .b ending to .B */

	/*
	 * check if a .c exists and is newer than the .B file.
	 */
	if (stat(file_name, &st) == -1) {
	    fprintf(stderr, "Missing .B file\n");
	    return 0;
	}
	mtime = st.st_mtime;

	file_name[strlen(file_name) - 1] = 'c';	/* Can you say too many
						 * extensions? */

	if (check_times(mtime, file_name) == 0) {
	    /* the .c file needs to be recompiled */
	    err = compile_and_link(file_name, &jump_table, &code, "errors", "OUT");
	} else {
	    file_name[strlen(file_name) - 2] = 0;
	    err = runtime_link(file_name, &jump_table, &code, "errors", "OUT");
	}
	if (err) {
	    compile_file_error(err, "runtime_link");
	    if (prog)
		free_prog(prog, 1);
	    return 0;
	} else
	    link_jump_table(prog, jump_table, code);
#else
	if (prog)
	    free_prog(prog, 1);
	return 0;
#endif
    }
#endif

    if (comp_flag)
	fprintf(stderr, "done.\n");
    return 1;
}				/* load_binary() */

void init_binaries P2(int, argc, char **, argv)
{
    struct stat st;
    int arg_id, i;

    if (do_stat(argv[0], &st, driver_name) != -1) {
	driver_id = st.st_mtime;
    } else {
	driver_id = current_time;
	fprintf(stderr, "Can't stat <%s>, ignoring old binaries.\n", argv[0]);
	fprintf(stderr, "Try invoking the driver using the full pathname.\n");
    }

    arg_id = 0;
    for (i = 1; i < argc; i++) {
	if (argv[i][0] != '-') {
	    if (config_id)
		continue;
	    if (do_stat(argv[i], &st, 0) != -1)
		config_id = st.st_mtime;
	    else
		config_id = current_time;
	} else if (argv[i][1] == 'D' || argv[i][1] == 'm') {
	    arg_id = (arg_id << 1) ^ whashstr(argv[i] + 2, 32);
	}
    }

    config_id ^= (arg_id << (sizeof(short) * 8));
}				/* init_binaries() */

/*
 * Test against modification times.  -1 if file doesn't exist,
 * 0 if out of date, and 1 if it's ok.
 */
static int check_times P2(time_t, mtime, char *, nm)
{
    struct stat st;

#ifdef OS2
    char *tmp, *c;

    tmp = string_copy(nm, "check_times");
    while ((c = strchr(tmp, '/')))
	*c = '\\';
    if (stat(tmp, &st) == -1)
	return -1;
    if (st.st_mtime > mtime)
	return 0;
    return 1;
#else
#ifdef LATTICE
    if (*nm == '/')
	nm++;
#endif
    if (stat(nm, &st) == -1)
	return -1;
    if (st.st_mtime > mtime) {
	return 0;
    }
    return 1;
#endif
}				/* check_times() */

/*
 * open file for writing, creating intermediate directories if needed.
 */
FILE *crdir_fopen P1(char *, file_name)
{
    char *p;
    struct stat st;
    FILE *ret;

#ifdef OS2
    char *newy;

    /* Take a copy as it could be a shared string */
    newy = string_copy(file_name, "crdir_fopen");
#endif

    /*
     * Beek - These directories probably exist most of the time, so let's
     * optimize by trying the fopen first
     */
#ifdef OS2
    if ((ret = fopen(newy, "wb")) != NULL) {
	FREE(newy);
	return ret;
    }
    p = newy;
#else
    if ((ret = fopen(file_name, "w")) != NULL) {
	return ret;
    }
    p = file_name;
#endif

    while (*p && (p = (char *) strchr(p, '/'))) {
	*p = '\0';
#ifdef OS2
	if (stat(newy, &st) == -1) {
	    /* make this dir */
	    if (mkdir(newy, 0770) == -1) {
		*p = '\\';
		FREE(newy);
		return (FILE *) 0;
	    }
	}
	*p = '\\';
#else
	if (stat(file_name, &st) == -1) {
	    /* make this dir */
	    if (mkdir(file_name, 0770) == -1) {
		*p = '/';
		return (FILE *) 0;
	    }
	}
	*p = '/';
#endif
	p++;
    }

#ifdef OS2
    f = fopen(newy, "wb");
    FREE(newy);
    return f;
#else
    return fopen(file_name, "wb");
#endif
}				/* crdir_fopen() */

/*
 * Routines to do some hacking on the program being saved/loaded.
 * Basically to fix up string switch tables, since the alternative
 * would probably need a linear search in f_switch().
 * I set things up so these routines can be used with other things
 * that might need patching.
 */
static void patch_out P3(struct program *, prog, short *, patches, int, len)
{
    int i;
    char *p;

    p = prog->p.i.program;
    while (len > 0) {
	i = patches[--len];
	if (p[i] == F_SWITCH && p[i + 1] >> 4 != 0xf) {	/* string switch */
	    short offset, break_addr;
	    char *s;

	    /* replace strings in table with string table indices */
	    COPY_SHORT(&offset, p + i + 2);
	    COPY_SHORT(&break_addr, p + i + 4);

	    while (offset < break_addr) {
		COPY_PTR(&s, p + offset);
		/*
		 * take advantage of fact that s is in strings table to find
		 * it's index.
		 */
		if (s == 0)
		    s = (char *)(POINTER_INT)-1;
		else
		    s = (char *)(POINTER_INT)store_prog_string(s);
		COPY_PTR(p + offset, &s);
		offset += SWITCH_CASE_SIZE;
	    }
	}
    }
}				/* patch_out() */

static int str_case_cmp P2(char *, a, char *, b)
{
    char *s1, *s2;

    COPY_PTR(&s1, a);
    COPY_PTR(&s2, b);

    return s1 - s2;
}				/* str_case_cmp() */

static void patch_in P3(struct program *, prog, short *, patches, int, len)
{
    int i;
    char *p;

    p = prog->p.i.program;
    while (len > 0) {
	i = patches[--len];
	if (p[i] == F_SWITCH && p[i + 1] >> 4 != 0xf) {	/* string switch */
	    short offset, start, break_addr;
	    char *s;

	    /* replace string indices with string pointers */
	    COPY_SHORT(&offset, p + i + 2);
	    COPY_SHORT(&break_addr, p + i + 4);

	    start = offset;
	    while (offset < break_addr) {
		COPY_PTR(&s, p + offset);
		/*
		 * get real pointer from strings table
		 */
		if (s == (char *)-1)
		    s = 0;
		else
		    s = prog->p.i.strings[(int)s];
		COPY_PTR(p + offset, &s);
		offset += SWITCH_CASE_SIZE;
	    }
	    /* sort so binary search still works */
	    quickSort(&p[start], (break_addr - start) / SWITCH_CASE_SIZE, 
		      SWITCH_CASE_SIZE, str_case_cmp);
	}
    }
}				/* patch_in() */

#endif
