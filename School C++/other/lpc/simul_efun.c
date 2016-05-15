#include "std.h"
#include "program.h"
#include "lex.h"
#include "simul_efun.h"
#include "stralloc.h"
#include "simulate.h"

/*
 * This file rewritten by Beek because it was inefficient and slow.  We
 * now keep track of two mappings:
 *     name -> index       and     index -> function
 * 
 * index->function is used at runtime since it's very fast.  name->index
 * is used at compile time.  It's sorted so we can search it in O(log n)
 * as opposed to a linear search on the function table.  Note that we
 * can't sort the function table b/c then indices wouldn't be preserved
 * across updates.
 *
 * note, the name list holds names for past and present simul_efuns and
 * is now sorted for finding entries faster etc.  The identifier hash
 * table is used at compile time.
 */

typedef struct {
  char *name;
  short index;
} simul_entry;

simul_entry *simul_names = 0;
struct function **simuls = 0;
static int num_simul_efun = 0;
struct object *simul_efun_ob;

/* Don't release this pointer ever. It is used elsewhere. */
char *simul_efun_file_name = 0;

static void find_or_add_simul_efun PROT((struct function *));
static void remove_simuls PROT((void));

#ifdef DEBUGMALLOC_EXTENSIONS
void mark_simuls() {
    int i;

    EXTRA_REF(BLOCK(simul_efun_file_name))++;
    for (i = 0; i < num_simul_efun; i++) 
	EXTRA_REF(BLOCK(simul_names[i].name))++;
}
#endif

/*
 * If there is a simul_efun file, then take care of it and extract all
 * information we need.
 */
void set_simul_efun P1(char *, file)
{
    char buf[512];

    if (!file) {
	fprintf(stderr, "No simul_efun\n");
	return;
    }
    while (file[0] == '/')
	file++;
    strcpy(buf, file);
    if (file[strlen(file) - 2] != '.')
	strcat(buf, ".c");
    simul_efun_file_name = make_shared_string(buf);

    simul_efun_ob = 0;
    (void) load_object(simul_efun_file_name, 0);
    if (simul_efun_ob == 0) {
	fprintf(stderr, "The simul_efun file %s was not loaded.\n",
		simul_efun_file_name);
	exit(-1);
    }
}

static void remove_simuls() {
    int i;
    struct ident_hash_elem *ihe;
    /* inactivate all old simul_efuns */
    for (i=0; i<num_simul_efun; i++) {
	simuls[i]=0;
    }
    for (i=0; i<num_simul_efun; i++) {
	if (ihe = lookup_ident(simul_names[i].name)) {
	    if (ihe->dn.simul_num != -1)
		ihe->sem_value--;
	    ihe->dn.simul_num = -1;
	    ihe->token &= ~IHE_SIMUL;
	}
    }    
}

void get_simul_efuns P1(struct program *, prog)
{
    struct function *funp;
    int i;
    int num_new = prog->p.i.num_functions;

    funp = prog->p.i.functions;
    if (num_simul_efun) {
	remove_simuls();
	/* will be resized later */
	simul_names = RESIZE(simul_names, num_simul_efun + num_new,
			     simul_entry, TAG_SIMULS, "get_simul_efuns");
	simuls = RESIZE(simuls, num_simul_efun + num_new,
			struct function *, TAG_SIMULS, "get_simul_efuns: 2");
    } else {
	simul_names = CALLOCATE(num_new, simul_entry, TAG_SIMULS, "get_simul_efuns");
	simuls = CALLOCATE(num_new, struct function *, TAG_SIMULS, "get_simul_efuns: 2");
    }
    for (i=0; i < (int)prog->p.i.num_functions; i++)
	if ((funp[i].type & (TYPE_MOD_STATIC | TYPE_MOD_PRIVATE)) == 0
	    && (!(funp[i].flags & NAME_NO_CODE)))
	    find_or_add_simul_efun(&funp[i]);
    
    /* shrink to fit */
    simul_names = RESIZE(simul_names, num_simul_efun, simul_entry,
			 TAG_SIMULS, "get_simul_efuns");
    simuls = RESIZE(simuls, num_simul_efun, struct function *,
		    TAG_SIMULS, "get_simul_efuns");
}

#define compare_addrs(x,y) (x < y ? -1 : (x > y ? 1 : 0))

/*
 * Test if 'name' is a simul_efun. The string pointer MUST be a pointer to
 * a shared string.
 */
int find_simul_efun P1(char *, name)
{
    int first = 0;
    int last = num_simul_efun - 1;
    int i,j;
    
    while (first <= last) {
	j = (first + last)/2;
	i = compare_addrs(name, simul_names[j].name);
	if (i == -1) 
	    {
		last = j-1;
	    }
	else if (i == 1)
	    {
		first = j+1;
	    }
	else
	    return simul_names[j].index;
    }
    return -1;
}

/*
 * Define a new simul_efun
 */
static void
find_or_add_simul_efun P1(struct function *, funp) {
    struct ident_hash_elem *ihe;
    int first = 0;
    int last = num_simul_efun - 1;
    int i,j;
    
    while (first <= last) {
	j = (first + last)/2;
	i = compare_addrs(funp->name, simul_names[j].name);
	if (i == -1) 
	    {
		last = j-1;
	    }
	else if (i == 1)
	    {
		first = j+1;
	    }
	else
	    {
		ihe = find_or_add_perm_ident(simul_names[j].name);
		ihe->token |= IHE_SIMUL;
		ihe->sem_value++;
		ihe->dn.simul_num = simul_names[j].index;
		simuls[simul_names[j].index]=funp;
		return;
	    }
    }
    for (i=num_simul_efun - 1; i > last; i--)
	simul_names[i+1] = simul_names[i];
    simuls[num_simul_efun] = funp;
    simul_names[first].name = funp->name;
    simul_names[first].index = num_simul_efun;
    ihe = find_or_add_perm_ident(funp->name);
    ihe->token |= IHE_SIMUL;
    ihe->sem_value++;
    ihe->dn.simul_num = num_simul_efun++;
    ref_string(funp->name);
}
