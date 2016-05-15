#ifndef SIMUL_EFUN_H
#define SIMUL_EFUN_H

/*
 * simul_efun.c
 */
extern struct object *simul_efun_ob;
extern char *simul_efun_file_name;
extern struct function **simuls;

void set_simul_efun PROT((char *));
void get_simul_efuns PROT((struct program *));
int find_simul_efun PROT((char *));

#ifdef DEBUGMALLOC_EXTENSIONS
void mark_simuls PROT((void));
#endif

#endif
