

#include "libcgc.h"
#include "cgc_libc.h"
#include "cgc_stack.h"
#ifndef FIX_INGREDIENT_CONTENT
#define FIX_INGREDIENT_CONTENT
#define FIX_INGREDIENT_CONTENT_VAR
static int fix_ingred_enable=0;
static void __attribute((constructor)) fix_ingred_enable_init(){
    char* tmp=getenv("ENABLE_FIXES");
    if (tmp) { fix_ingred_enable=1; }
}
#else
#ifndef FIX_INGREDIENT_CONTENT_VAR
#define FIX_INGREDIENT_CONTENT_VAR
static int fix_ingred_enable=0;
#endif
#endif

void fix_ingred_stack_0_1_1();
void fix_ingred_stack_0_1_2();
void fix_ingred_stack_0_1();
void fix_ingred_stack_0_2_0();
void fix_ingred_stack_0_2_1();
void fix_ingred_stack_0_2();
void fix_ingred_stack_0_3_0();
void fix_ingred_stack_0_3();
void fix_ingred_stack_0_4_0();
void fix_ingred_stack_0_4();
void fix_ingred_stack_0();
void cgc_initStack(Stack * stack, int numElements, int elementSize)
{
if (fix_ingred_enable){ fix_ingred_stack_0(); };
    int ret;
    if (numElements > MAX_STACK_SIZE / elementSize) {
	stack->elements = NULL;
	return;
    }
    {
        cgc_size_t tlv3;
        tlv3 = elementSize * numElements;
        int tlv2;
        tlv2 = 0;
        void** tlv1;
        tlv1 = ( void * * ) & stack -> elements;
        ret = cgc_allocate(tlv3,tlv2,tlv1);
    }
    if (ret != 0) {
 {
     unsigned int tlv4;
     tlv4 = 16;
    	cgc__terminate(tlv4);
 }
    }
    stack->numElements = numElements;
    stack->elementSize = elementSize;
    stack->top = -1;
}

void fix_ingred_stack_1_1_0();
void fix_ingred_stack_1_1_1();
void fix_ingred_stack_1_1();
void fix_ingred_stack_1_2_0();
void fix_ingred_stack_1_2_1();
void fix_ingred_stack_1_2();
void fix_ingred_stack_1_3_0();
void fix_ingred_stack_1_3();
void fix_ingred_stack_1();
void cgc_destroyStack(Stack * stack)
{
if (fix_ingred_enable){ fix_ingred_stack_1(); };

    int ret;
    {
        void* tlv2;
        tlv2 = stack -> elements;
        cgc_size_t tlv1;
        tlv1 = stack -> numElements * stack -> elementSize;
        ret = cgc_deallocate(tlv2,tlv1);
    }
    if (ret != 0) {
 {
     unsigned int tlv3;
     tlv3 = 17;
    	cgc__terminate(tlv3);
 }
    }
    stack->elements = NULL;
    stack->numElements = 0;
    stack->elementSize = 0;
    stack->top = -1;
}

void fix_ingred_stack_2();
int cgc_isStackFull(Stack * stack)
{
if (fix_ingred_enable){ fix_ingred_stack_2(); };
    return stack->top >= stack->numElements;
}

void fix_ingred_stack_3();
int cgc_isStackEmpty(Stack * stack)
{
if (fix_ingred_enable){ fix_ingred_stack_3(); };
    return stack->top < 0;
}

void fix_ingred_stack_4_3_0();
void fix_ingred_stack_4_3_1();
void fix_ingred_stack_4_3();
void fix_ingred_stack_4_4_0();
void fix_ingred_stack_4_4_1();
void fix_ingred_stack_4_4();
void fix_ingred_stack_4_5_0();
void fix_ingred_stack_4_5();
void fix_ingred_stack_4_6_0();
void fix_ingred_stack_4_6();
void fix_ingred_stack_4_7_1();
void fix_ingred_stack_4_7_2();
void fix_ingred_stack_4_7();
void fix_ingred_stack_4();
void cgc_pushElement(Stack * stack, void *element)
{
if (fix_ingred_enable){ fix_ingred_stack_4(); };
    int ret;
    int tlv1;
    {
        Stack* tlv5;
        tlv5 = stack;
        tlv1 = cgc_isStackFull(tlv5);
    }
    if (tlv1) {
 {
     int tlv9;
     tlv9 = STDOUT;
     const char* tlv8 = TOO_MANY_ELEM_STR;
     cgc_size_t tlv7;
     tlv7 = sizeof ( TOO_MANY_ELEM_STR );
    	ret = cgc_transmit_all(tlv9,tlv8,tlv7);
 }
	if (ret != 0) {
     {
         unsigned int tlv10;
         tlv10 = 18;
    	    cgc__terminate(tlv10);
     }
	}
 {
     unsigned int tlv6;
     tlv6 = 19;
    	cgc__terminate(tlv6);
 }
    }
    stack->top++;
    {
        void* tlv4;
        tlv4 = & stack -> elements [ stack -> elementSize * stack -> top ];
        void* tlv3;
        tlv3 = element;
        cgc_size_t tlv2;
        tlv2 = stack -> elementSize;
        cgc_memcpy(tlv4,tlv3,tlv2);
    }
}

void fix_ingred_stack_5_3_0();
void fix_ingred_stack_5_3_1();
void fix_ingred_stack_5_3();
void fix_ingred_stack_5_4_0();
void fix_ingred_stack_5_4_1();
void fix_ingred_stack_5_4();
void fix_ingred_stack_5_5_0();
void fix_ingred_stack_5_5();
void fix_ingred_stack_5_6_0();
void fix_ingred_stack_5_6();
void fix_ingred_stack_5();
void *cgc_popElement(Stack * stack)
{
if (fix_ingred_enable){ fix_ingred_stack_5(); };
    int ret;
    int tlv1;
    {
        Stack* tlv2;
        tlv2 = stack;
        tlv1 = cgc_isStackEmpty(tlv2);
    }
    if (tlv1) {
 {
     int tlv6;
     tlv6 = STDOUT;
     const char* tlv5 = NOT_ENOUGH_ELEM_STR;
     cgc_size_t tlv4;
     tlv4 = sizeof ( NOT_ENOUGH_ELEM_STR );
    	ret = cgc_transmit_all(tlv6,tlv5,tlv4);
 }
	if (ret != 0) {
     {
         unsigned int tlv7;
         tlv7 = 20;
    	    cgc__terminate(tlv7);
     }
	}
 {
     unsigned int tlv3;
     tlv3 = 21;
    	cgc__terminate(tlv3);
 }
    }
    return &stack->elements[stack->elementSize * stack->top--];
}

void fix_ingred_stack_0_1_1(){
int numElements;
    bzero(&numElements,sizeof(int));
int elementSize;
    bzero(&elementSize,sizeof(int));
    {int ret; ret = (int)(numElements); }
    {cgc_size_t tlv3; tlv3 = (cgc_size_t)(numElements); }
    {int tlv2; tlv2 = (int)(numElements); }
    {unsigned int tlv4; tlv4 = (unsigned int)(numElements); }
}
void fix_ingred_stack_0_1_2(){
int numElements;
    bzero(&numElements,sizeof(int));
int elementSize;
    bzero(&elementSize,sizeof(int));
    {    elementSize = 1;
         int ret; ret = (int)(MAX_STACK_SIZE / elementSize); }
    {    elementSize = 1;
         cgc_size_t tlv3; tlv3 = (cgc_size_t)(MAX_STACK_SIZE / elementSize); }
    {    elementSize = 1;
         int tlv2; tlv2 = (int)(MAX_STACK_SIZE / elementSize); }
    {    elementSize = 1;
         unsigned int tlv4; tlv4 = (unsigned int)(MAX_STACK_SIZE / elementSize); }
}
void fix_ingred_stack_0_1(){
fix_ingred_stack_0_1_1();
fix_ingred_stack_0_1_2();
}
void fix_ingred_stack_0_2_0(){
int elementSize;
    bzero(&elementSize,sizeof(int));
int numElements;
    bzero(&numElements,sizeof(int));
    {int ret; ret = (int)(elementSize * numElements); }
    {cgc_size_t tlv3; tlv3 = (cgc_size_t)(elementSize * numElements); }
    {int tlv2; tlv2 = (int)(elementSize * numElements); }
    {unsigned int tlv4; tlv4 = (unsigned int)(elementSize * numElements); }
}
void fix_ingred_stack_0_2_1(){
int elementSize;
    bzero(&elementSize,sizeof(int));
int numElements;
    bzero(&numElements,sizeof(int));
    {int ret; ret = (int)(0); }
    {cgc_size_t tlv3; tlv3 = (cgc_size_t)(0); }
    {int tlv2; tlv2 = (int)(0); }
    {unsigned int tlv4; tlv4 = (unsigned int)(0); }
}
void fix_ingred_stack_0_2(){
fix_ingred_stack_0_2_0();
fix_ingred_stack_0_2_1();
}
void fix_ingred_stack_0_3_0(){
int ret;
    bzero(&ret,sizeof(int));
    {cgc_size_t tlv3; tlv3 = (cgc_size_t)(ret); }
    {int tlv2; tlv2 = (int)(ret); }
    {unsigned int tlv4; tlv4 = (unsigned int)(ret); }
}
void fix_ingred_stack_0_3(){
fix_ingred_stack_0_3_0();
}
void fix_ingred_stack_0_4_0(){
    {int ret; ret = (int)(16); }
    {cgc_size_t tlv3; tlv3 = (cgc_size_t)(16); }
    {int tlv2; tlv2 = (int)(16); }
    {unsigned int tlv4; tlv4 = (unsigned int)(16); }
}
void fix_ingred_stack_0_4(){
fix_ingred_stack_0_4_0();
}
void fix_ingred_stack_0(){
fix_ingred_stack_0_1();
fix_ingred_stack_0_2();
fix_ingred_stack_0_3();
fix_ingred_stack_0_4();
}
void fix_ingred_stack_1_1_0(){
Stack stack_ref;
    bzero(&stack_ref,1*sizeof(Stack));
Stack * stack = &stack_ref;
    {int ret; ret = (int)(stack -> elements); }
    {void * tlv2; tlv2 = (void *)(stack -> elements); }
    {cgc_size_t tlv1; tlv1 = (cgc_size_t)(stack -> elements); }
    {unsigned int tlv3; tlv3 = (unsigned int)(stack -> elements); }
}
void fix_ingred_stack_1_1_1(){
Stack stack_ref;
    bzero(&stack_ref,1*sizeof(Stack));
Stack * stack = &stack_ref;
    {int ret; ret = (int)(stack -> numElements * stack -> elementSize); }
    {void * tlv2; tlv2 = (void *)(stack -> numElements * stack -> elementSize); }
    {cgc_size_t tlv1; tlv1 = (cgc_size_t)(stack -> numElements * stack -> elementSize); }
    {unsigned int tlv3; tlv3 = (unsigned int)(stack -> numElements * stack -> elementSize); }
}
void fix_ingred_stack_1_1(){
fix_ingred_stack_1_1_0();
fix_ingred_stack_1_1_1();
}
void fix_ingred_stack_1_2_0(){
int ret;
    bzero(&ret,sizeof(int));
    {void * tlv2; tlv2 = (void *)(ret); }
    {cgc_size_t tlv1; tlv1 = (cgc_size_t)(ret); }
    {unsigned int tlv3; tlv3 = (unsigned int)(ret); }
}
void fix_ingred_stack_1_2_1(){
int ret;
    bzero(&ret,sizeof(int));
    {void * tlv2; tlv2 = (void *)(0); }
    {cgc_size_t tlv1; tlv1 = (cgc_size_t)(0); }
    {unsigned int tlv3; tlv3 = (unsigned int)(0); }
}
void fix_ingred_stack_1_2(){
fix_ingred_stack_1_2_0();
fix_ingred_stack_1_2_1();
}
void fix_ingred_stack_1_3_0(){
    {int ret; ret = (int)(17); }
    {void * tlv2; tlv2 = (void *)(17); }
    {cgc_size_t tlv1; tlv1 = (cgc_size_t)(17); }
    {unsigned int tlv3; tlv3 = (unsigned int)(17); }
}
void fix_ingred_stack_1_3(){
fix_ingred_stack_1_3_0();
}
void fix_ingred_stack_1(){
fix_ingred_stack_1_1();
fix_ingred_stack_1_2();
fix_ingred_stack_1_3();
}
void fix_ingred_stack_2(){
}
void fix_ingred_stack_3(){
}
void fix_ingred_stack_4_3_0(){
    {int ret; ret = (int)(STDOUT); }
    {int tlv1; tlv1 = (int)(STDOUT); }
    {void * tlv4; tlv4 = (void *)(STDOUT); }
    {void * tlv3; tlv3 = (void *)(STDOUT); }
    {cgc_size_t tlv2; tlv2 = (cgc_size_t)(STDOUT); }
    {int tlv9; tlv9 = (int)(STDOUT); }
    {cgc_size_t tlv7; tlv7 = (cgc_size_t)(STDOUT); }
    {unsigned int tlv6; tlv6 = (unsigned int)(STDOUT); }
    {unsigned int tlv10; tlv10 = (unsigned int)(STDOUT); }
}
void fix_ingred_stack_4_3_1(){
    {int ret; ret = (int)(sizeof ( TOO_MANY_ELEM_STR )); }
    {int tlv1; tlv1 = (int)(sizeof ( TOO_MANY_ELEM_STR )); }
    {void * tlv4; tlv4 = (void *)(sizeof ( TOO_MANY_ELEM_STR )); }
    {void * tlv3; tlv3 = (void *)(sizeof ( TOO_MANY_ELEM_STR )); }
    {cgc_size_t tlv2; tlv2 = (cgc_size_t)(sizeof ( TOO_MANY_ELEM_STR )); }
    {int tlv9; tlv9 = (int)(sizeof ( TOO_MANY_ELEM_STR )); }
    {cgc_size_t tlv7; tlv7 = (cgc_size_t)(sizeof ( TOO_MANY_ELEM_STR )); }
    {unsigned int tlv6; tlv6 = (unsigned int)(sizeof ( TOO_MANY_ELEM_STR )); }
    {unsigned int tlv10; tlv10 = (unsigned int)(sizeof ( TOO_MANY_ELEM_STR )); }
}
void fix_ingred_stack_4_3(){
fix_ingred_stack_4_3_0();
fix_ingred_stack_4_3_1();
}
void fix_ingred_stack_4_4_0(){
int ret;
    bzero(&ret,sizeof(int));
    {int tlv1; tlv1 = (int)(ret); }
    {void * tlv4; tlv4 = (void *)(ret); }
    {void * tlv3; tlv3 = (void *)(ret); }
    {cgc_size_t tlv2; tlv2 = (cgc_size_t)(ret); }
    {int tlv9; tlv9 = (int)(ret); }
    {cgc_size_t tlv7; tlv7 = (cgc_size_t)(ret); }
    {unsigned int tlv6; tlv6 = (unsigned int)(ret); }
    {unsigned int tlv10; tlv10 = (unsigned int)(ret); }
}
void fix_ingred_stack_4_4_1(){
int ret;
    bzero(&ret,sizeof(int));
    {int tlv1; tlv1 = (int)(0); }
    {void * tlv4; tlv4 = (void *)(0); }
    {void * tlv3; tlv3 = (void *)(0); }
    {cgc_size_t tlv2; tlv2 = (cgc_size_t)(0); }
    {int tlv9; tlv9 = (int)(0); }
    {cgc_size_t tlv7; tlv7 = (cgc_size_t)(0); }
    {unsigned int tlv6; tlv6 = (unsigned int)(0); }
    {unsigned int tlv10; tlv10 = (unsigned int)(0); }
}
void fix_ingred_stack_4_4(){
fix_ingred_stack_4_4_0();
fix_ingred_stack_4_4_1();
}
void fix_ingred_stack_4_5_0(){
    {int ret; ret = (int)(18); }
    {int tlv1; tlv1 = (int)(18); }
    {void * tlv4; tlv4 = (void *)(18); }
    {void * tlv3; tlv3 = (void *)(18); }
    {cgc_size_t tlv2; tlv2 = (cgc_size_t)(18); }
    {int tlv9; tlv9 = (int)(18); }
    {cgc_size_t tlv7; tlv7 = (cgc_size_t)(18); }
    {unsigned int tlv6; tlv6 = (unsigned int)(18); }
    {unsigned int tlv10; tlv10 = (unsigned int)(18); }
}
void fix_ingred_stack_4_5(){
fix_ingred_stack_4_5_0();
}
void fix_ingred_stack_4_6_0(){
    {int ret; ret = (int)(19); }
    {int tlv1; tlv1 = (int)(19); }
    {void * tlv4; tlv4 = (void *)(19); }
    {void * tlv3; tlv3 = (void *)(19); }
    {cgc_size_t tlv2; tlv2 = (cgc_size_t)(19); }
    {int tlv9; tlv9 = (int)(19); }
    {cgc_size_t tlv7; tlv7 = (cgc_size_t)(19); }
    {unsigned int tlv6; tlv6 = (unsigned int)(19); }
    {unsigned int tlv10; tlv10 = (unsigned int)(19); }
}
void fix_ingred_stack_4_6(){
fix_ingred_stack_4_6_0();
}
void fix_ingred_stack_4_7_1(){
int element_ref;
    bzero(&element_ref,1*sizeof(int));
void * element = (void*)&element_ref;
Stack stack_ref;
    bzero(&stack_ref,1*sizeof(Stack));
Stack * stack = &stack_ref;
    {int ret; ret = (int)(element); }
    {int tlv1; tlv1 = (int)(element); }
    {void * tlv4; tlv4 = (void *)(element); }
    {void * tlv3; tlv3 = (void *)(element); }
    {cgc_size_t tlv2; tlv2 = (cgc_size_t)(element); }
    {int tlv9; tlv9 = (int)(element); }
    {cgc_size_t tlv7; tlv7 = (cgc_size_t)(element); }
    {unsigned int tlv6; tlv6 = (unsigned int)(element); }
    {unsigned int tlv10; tlv10 = (unsigned int)(element); }
}
void fix_ingred_stack_4_7_2(){
int element_ref;
    bzero(&element_ref,1*sizeof(int));
void * element = (void*)&element_ref;
Stack stack_ref;
    bzero(&stack_ref,1*sizeof(Stack));
Stack * stack = &stack_ref;
    {int ret; ret = (int)(stack -> elementSize); }
    {int tlv1; tlv1 = (int)(stack -> elementSize); }
    {void * tlv4; tlv4 = (void *)(stack -> elementSize); }
    {void * tlv3; tlv3 = (void *)(stack -> elementSize); }
    {cgc_size_t tlv2; tlv2 = (cgc_size_t)(stack -> elementSize); }
    {int tlv9; tlv9 = (int)(stack -> elementSize); }
    {cgc_size_t tlv7; tlv7 = (cgc_size_t)(stack -> elementSize); }
    {unsigned int tlv6; tlv6 = (unsigned int)(stack -> elementSize); }
    {unsigned int tlv10; tlv10 = (unsigned int)(stack -> elementSize); }
}
void fix_ingred_stack_4_7(){
fix_ingred_stack_4_7_1();
fix_ingred_stack_4_7_2();
}
void fix_ingred_stack_4(){
fix_ingred_stack_4_3();
fix_ingred_stack_4_4();
fix_ingred_stack_4_5();
fix_ingred_stack_4_6();
fix_ingred_stack_4_7();
}
void fix_ingred_stack_5_3_0(){
    {int tlv6; tlv6 = (int)(STDOUT); }
    {cgc_size_t tlv4; tlv4 = (cgc_size_t)(STDOUT); }
    {unsigned int tlv3; tlv3 = (unsigned int)(STDOUT); }
    {unsigned int tlv7; tlv7 = (unsigned int)(STDOUT); }
}
void fix_ingred_stack_5_3_1(){
    {int ret; ret = (int)(sizeof ( NOT_ENOUGH_ELEM_STR )); }
    {int tlv1; tlv1 = (int)(sizeof ( NOT_ENOUGH_ELEM_STR )); }
    {int tlv6; tlv6 = (int)(sizeof ( NOT_ENOUGH_ELEM_STR )); }
    {cgc_size_t tlv4; tlv4 = (cgc_size_t)(sizeof ( NOT_ENOUGH_ELEM_STR )); }
    {unsigned int tlv3; tlv3 = (unsigned int)(sizeof ( NOT_ENOUGH_ELEM_STR )); }
    {unsigned int tlv7; tlv7 = (unsigned int)(sizeof ( NOT_ENOUGH_ELEM_STR )); }
}
void fix_ingred_stack_5_3(){
fix_ingred_stack_5_3_0();
fix_ingred_stack_5_3_1();
}
void fix_ingred_stack_5_4_0(){
int ret;
    bzero(&ret,sizeof(int));
    {int tlv6; tlv6 = (int)(ret); }
    {cgc_size_t tlv4; tlv4 = (cgc_size_t)(ret); }
    {unsigned int tlv7; tlv7 = (unsigned int)(ret); }
}
void fix_ingred_stack_5_4_1(){
int ret;
    bzero(&ret,sizeof(int));
    {int tlv6; tlv6 = (int)(0); }
    {cgc_size_t tlv4; tlv4 = (cgc_size_t)(0); }
    {unsigned int tlv7; tlv7 = (unsigned int)(0); }
}
void fix_ingred_stack_5_4(){
fix_ingred_stack_5_4_0();
fix_ingred_stack_5_4_1();
}
void fix_ingred_stack_5_5_0(){
    {int ret; ret = (int)(20); }
    {int tlv1; tlv1 = (int)(20); }
    {int tlv6; tlv6 = (int)(20); }
    {cgc_size_t tlv4; tlv4 = (cgc_size_t)(20); }
    {unsigned int tlv3; tlv3 = (unsigned int)(20); }
    {unsigned int tlv7; tlv7 = (unsigned int)(20); }
}
void fix_ingred_stack_5_5(){
fix_ingred_stack_5_5_0();
}
void fix_ingred_stack_5_6_0(){
    {int ret; ret = (int)(21); }
    {int tlv1; tlv1 = (int)(21); }
    {int tlv6; tlv6 = (int)(21); }
    {cgc_size_t tlv4; tlv4 = (cgc_size_t)(21); }
    {unsigned int tlv3; tlv3 = (unsigned int)(21); }
    {unsigned int tlv7; tlv7 = (unsigned int)(21); }
}
void fix_ingred_stack_5_6(){
fix_ingred_stack_5_6_0();
}
void fix_ingred_stack_5(){
fix_ingred_stack_5_3();
fix_ingred_stack_5_4();
fix_ingred_stack_5_5();
fix_ingred_stack_5_6();
}
