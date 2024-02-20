//############################################
// THIS FILE HAS BEEN AUTOMATICALLY GENERATED BY
//          genprog_setup.bash
//##########################################

#include "decompiled_source.h"



//  Please populate with vulnerable code segments

// Otherwise, the following can be used as a template:
#ifdef PARAMS_NEEDED
typedef void* (*pcgc_calloc)(cgc_size_t,cgc_size_t);
pcgc_calloc cgc_calloc = NULL;
typedef void* (*pcgc_malloc)(cgc_size_t);
pcgc_malloc cgc_malloc = NULL;
typedef void (*pcgc_free)(void*);
pcgc_free cgc_free = NULL;
typedef void* (*pcgc_realloc)(void*,cgc_size_t);
pcgc_realloc cgc_realloc = NULL;
#endif


void det_CHANGEME(
#ifdef PARAMS_NEEDED
void* mycgc_calloc,
void* mycgc_malloc, 
void* mycgc_free, 
void* mycgc_realloc
#endif
//, remaining params
) 
{
#ifdef PARAMS_NEEDED
    cgc_calloc = (pcgc_calloc) mycgc_calloc;
    cgc_malloc = (pcgc_malloc) mycgc_malloc;
    cgc_free = (pcgc_free) mycgc_free;
    cgc_realloc = (pcgc_realloc) mycgc_realloc;
    //void x = 
    CHANGEME(
    // remaining params
    );
    //------------------------------------------------------------
    // IMPORTANT NOTES TO PATCH DEVELOPER
    // To ensure C Calling Convention Consistency between the detour insertion
    //  (this is the JMP/E9 inserted in original function)
    //  and the original function caller
    //   == THIS MUST BE UPDATED CORRECTLY ==
    // 1) If the number of void* being passed in changes,
    //    Update the following line for the correct value, s.t. 
    //     => add $0x10,%esp
    //     $0x10 = 4 void pointers * 4 BYTES
    // 2) Check how much the stack changed in this function call:
    //    What effects the stack growth: local variables 
    //      a)  local variables 
    //      b)  parameters for myCHANGEME function call 
    //     => add $0x8,%esp
    //    Q:How can you check what this value should be?
    //    A: Just compile this file and look at the objdump
    //       The %esp will be reduced as items are pushed or copied onto the stack
    //       Before returning, %esp will be increased
    //       This is the value you need to replace $0x8 with.
    //------------------------------------------------------------
    asm (
    "nop\n\t"
    "nop\n\t"
    "nop\n\t"
    "nop\n\t"
    "add $0x4,%esp\n\t"
    "pop %ebx\n\t"
    "pop %ebp\n\t"
    "pop %ecx\n\t"
    "add $0x10,%esp\n\t"
    "push %ecx\n\t"
    "ret\n\t"
    );
    myreturn:
    //return x;
    return;
#else
    return CHANGEME(
    // remaining params
    );
#endif
}
 

void CHANGEME(
)
{ 



}


void main()
{
	det_CHANGEME(
#ifdef PARAMS_NEEDED
		NULL,
		NULL,
		NULL,
		NULL
#endif
		// remaining params
	);
}
