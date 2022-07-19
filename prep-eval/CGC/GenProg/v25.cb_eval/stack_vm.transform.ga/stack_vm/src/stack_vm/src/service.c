

#include "libcgc.h"
#include "cgc_libc.h"
#include "cgc_vm.h"
#include "cgc_stack.h"
#include "cgc_service.h"
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

void fix_ingred_service_0_1_0();
void fix_ingred_service_0_1();
void fix_ingred_service_0_2_0();
void fix_ingred_service_0_2_1();
void fix_ingred_service_0_2_2();
void fix_ingred_service_0_2();
void fix_ingred_service_0_3_2();
void fix_ingred_service_0_3();
void fix_ingred_service_0_4_0();
void fix_ingred_service_0_4();
void fix_ingred_service_0_6_1();
void fix_ingred_service_0_6_2();
void fix_ingred_service_0_6();
void fix_ingred_service_0_7_0();
void fix_ingred_service_0_7();
void fix_ingred_service_0_8_3();
void fix_ingred_service_0_8();
void fix_ingred_service_0_11_1();
void fix_ingred_service_0_11();
void fix_ingred_service_0_13_0();
void fix_ingred_service_0_13();
void fix_ingred_service_0_14_2();
void fix_ingred_service_0_14();
void fix_ingred_service_0_15_0();
void fix_ingred_service_0_15();
void fix_ingred_service_0_16_5();
void fix_ingred_service_0_16_6();
void fix_ingred_service_0_16();
void fix_ingred_service_0_17_0();
void fix_ingred_service_0_17_1();
void fix_ingred_service_0_17();
void fix_ingred_service_0_18_7();
void fix_ingred_service_0_18();
void fix_ingred_service_0_19_0();
void fix_ingred_service_0_19();
void fix_ingred_service_0();
int main(int cgc_argc, char *cgc_argv[])
{
if (fix_ingred_enable){ fix_ingred_service_0(); };
    Stack programStack = { -1, 0, 0, NULL };
    while (1) {
	char buf[1024] = { 0 };
 int bytes_read;
 bytes_read = 0;
 int arg_pos;
 arg_pos = 0;
 {
     int tlv5;
     tlv5 = STDIN;
     char* tlv4;
      tlv4 = buf;
     cgc_size_t tlv3;
     tlv3 = sizeof ( buf ) - 1;
    	bytes_read = cgc_recvline(tlv5,tlv4,tlv3);
 }
	if (bytes_read <= 0) {
     {
         unsigned int tlv8;
         tlv8 = 1;
    	    cgc__terminate(tlv8);
     }
	}
	if (programStack.numElements <= 0) {
     {
         Stack* tlv11;
         tlv11 = & programStack;
         int tlv10;
         tlv10 = MAX_PROGRAM_STACK_SIZE;
         int tlv9;
         tlv9 = sizeof ( Program * );
    	    cgc_initStack(tlv11,tlv10,tlv9);
     }
	}
 int tlv1;
 {
     char* tlv7;
      tlv7 = NEW_PROGRAM_CMD_STR;
     char* tlv6;
      tlv6 = buf;
     tlv1 = cgc_parseCmd(tlv7,tlv6);
 }
	if ((arg_pos = tlv1) > 0) {
     Program* program;
     program = NULL;
     {
         Program** tlv13;
         tlv13 = & program;
         int tlv12;
         tlv12 = STDIN;
    	    cgc_initProgram(tlv13,tlv12);
     }
	    if (program != NULL) {
  {
      Stack* tlv17;
      tlv17 = & programStack;
      void* tlv16;
      tlv16 = & program;
    		cgc_pushElement(tlv17,tlv16);
  }
	    }
	} else {
     int tlv2;
     {
         char* tlv15;
          tlv15 = EXECUTE_PROGRAM_CMD_STR;
         char* tlv14;
          tlv14 = buf;
         tlv2 = cgc_parseCmd(tlv15,tlv14);
     }
	    if ((arg_pos = tlv2) > 0) {
		int program_num;
		int ret;
  {
      const char* tlv19 = buf + arg_pos;
      cgc_size_t tlv18;
      tlv18 = 10;
    		program_num = cgc_strn2int(tlv19,tlv18);
  }
		if (program_num > programStack.top) {
      {
          int tlv22;
          tlv22 = STDOUT;
          const char* tlv21 = INVALID_PROGRAM_STR;
          cgc_size_t tlv20;
          tlv20 = sizeof ( TOO_MANY_LINES_STR );
    		    ret = cgc_transmit_all(tlv22,tlv21,tlv20);
      }
		    if (ret != 0) {
   {
       unsigned int tlv23;
       tlv23 = 13;
    			cgc__terminate(tlv23);
   }
		    }
		} else {
		    Program **program_ptr;
		    program_ptr = programStack.elements + (program_num * sizeof(Program *));
		    cgc_executeProgram(*program_ptr);
		}
	    }
	}
    }
}

void fix_ingred_service_0_1_0(){
    {char buf [ 1024 ]; buf [ ( 1024 )-1 ] = (char)(0); }
    {int bytes_read; bytes_read = (int)(0); }
    {int arg_pos; arg_pos = (int)(0); }
    {int tlv1; tlv1 = (int)(0); }
    {int tlv5; tlv5 = (int)(0); }
    {char * tlv4; tlv4 = (char *)(0); }
    {cgc_size_t tlv3; tlv3 = (cgc_size_t)(0); }
    {char * tlv7; tlv7 = (char *)(0); }
    {char * tlv6; tlv6 = (char *)(0); }
    {int tlv2; tlv2 = (int)(0); }
    {unsigned int tlv8; tlv8 = (unsigned int)(0); }
    {int tlv10; tlv10 = (int)(0); }
    {int tlv9; tlv9 = (int)(0); }
    {int tlv12; tlv12 = (int)(0); }
    {char * tlv15; tlv15 = (char *)(0); }
    {char * tlv14; tlv14 = (char *)(0); }
    {int program_num; program_num = (int)(0); }
    {int ret; ret = (int)(0); }
    {void * tlv16; tlv16 = (void *)(0); }
    {cgc_size_t tlv18; tlv18 = (cgc_size_t)(0); }
    {int tlv22; tlv22 = (int)(0); }
    {cgc_size_t tlv20; tlv20 = (cgc_size_t)(0); }
    {unsigned int tlv23; tlv23 = (unsigned int)(0); }
}
void fix_ingred_service_0_1(){
fix_ingred_service_0_1_0();
}
void fix_ingred_service_0_2_0(){
char buf [ 1024 ];
    bzero(&buf,( 1024 *sizeof(char) ) );
    {char buf [ 1024 ]; buf [ ( 1024 )-1 ] = (char)(STDIN); }
    {int bytes_read; bytes_read = (int)(STDIN); }
    {int arg_pos; arg_pos = (int)(STDIN); }
    {int tlv1; tlv1 = (int)(STDIN); }
    {int tlv5; tlv5 = (int)(STDIN); }
    {char * tlv4; tlv4 = (char *)(STDIN); }
    {cgc_size_t tlv3; tlv3 = (cgc_size_t)(STDIN); }
    {char * tlv7; tlv7 = (char *)(STDIN); }
    {char * tlv6; tlv6 = (char *)(STDIN); }
    {int tlv2; tlv2 = (int)(STDIN); }
    {unsigned int tlv8; tlv8 = (unsigned int)(STDIN); }
    {int tlv10; tlv10 = (int)(STDIN); }
    {int tlv9; tlv9 = (int)(STDIN); }
    {int tlv12; tlv12 = (int)(STDIN); }
    {char * tlv15; tlv15 = (char *)(STDIN); }
    {char * tlv14; tlv14 = (char *)(STDIN); }
    {int program_num; program_num = (int)(STDIN); }
    {int ret; ret = (int)(STDIN); }
    {void * tlv16; tlv16 = (void *)(STDIN); }
    {cgc_size_t tlv18; tlv18 = (cgc_size_t)(STDIN); }
    {int tlv22; tlv22 = (int)(STDIN); }
    {cgc_size_t tlv20; tlv20 = (cgc_size_t)(STDIN); }
    {unsigned int tlv23; tlv23 = (unsigned int)(STDIN); }
}
void fix_ingred_service_0_2_1(){
char buf [ 1024 ];
    bzero(&buf,( 1024 *sizeof(char) ) );
    {char buf [ 1024 ]; buf [ ( 1024 )-1 ] = (char)(buf); }
    {int bytes_read; bytes_read = (int)(buf); }
    {int arg_pos; arg_pos = (int)(buf); }
    {int tlv1; tlv1 = (int)(buf); }
    {int tlv5; tlv5 = (int)(buf); }
    {char * tlv4; tlv4 = (char *)(buf); }
    {cgc_size_t tlv3; tlv3 = (cgc_size_t)(buf); }
    {char * tlv7; tlv7 = (char *)(buf); }
    {char * tlv6; tlv6 = (char *)(buf); }
    {int tlv2; tlv2 = (int)(buf); }
    {unsigned int tlv8; tlv8 = (unsigned int)(buf); }
    {int tlv10; tlv10 = (int)(buf); }
    {int tlv9; tlv9 = (int)(buf); }
    {int tlv12; tlv12 = (int)(buf); }
    {char * tlv15; tlv15 = (char *)(buf); }
    {char * tlv14; tlv14 = (char *)(buf); }
    {int program_num; program_num = (int)(buf); }
    {int ret; ret = (int)(buf); }
    {void * tlv16; tlv16 = (void *)(buf); }
    {cgc_size_t tlv18; tlv18 = (cgc_size_t)(buf); }
    {int tlv22; tlv22 = (int)(buf); }
    {cgc_size_t tlv20; tlv20 = (cgc_size_t)(buf); }
    {unsigned int tlv23; tlv23 = (unsigned int)(buf); }
}
void fix_ingred_service_0_2_2(){
char buf [ 1024 ];
    bzero(&buf,( 1024 *sizeof(char) ) );
    {char buf [ 1024 ]; buf [ ( 1024 )-1 ] = (char)(sizeof ( buf ) - 1); }
    {int bytes_read; bytes_read = (int)(sizeof ( buf ) - 1); }
    {int arg_pos; arg_pos = (int)(sizeof ( buf ) - 1); }
    {int tlv1; tlv1 = (int)(sizeof ( buf ) - 1); }
    {int tlv5; tlv5 = (int)(sizeof ( buf ) - 1); }
    {char * tlv4; tlv4 = (char *)(sizeof ( buf ) - 1); }
    {cgc_size_t tlv3; tlv3 = (cgc_size_t)(sizeof ( buf ) - 1); }
    {char * tlv7; tlv7 = (char *)(sizeof ( buf ) - 1); }
    {char * tlv6; tlv6 = (char *)(sizeof ( buf ) - 1); }
    {int tlv2; tlv2 = (int)(sizeof ( buf ) - 1); }
    {unsigned int tlv8; tlv8 = (unsigned int)(sizeof ( buf ) - 1); }
    {int tlv10; tlv10 = (int)(sizeof ( buf ) - 1); }
    {int tlv9; tlv9 = (int)(sizeof ( buf ) - 1); }
    {int tlv12; tlv12 = (int)(sizeof ( buf ) - 1); }
    {char * tlv15; tlv15 = (char *)(sizeof ( buf ) - 1); }
    {char * tlv14; tlv14 = (char *)(sizeof ( buf ) - 1); }
    {int program_num; program_num = (int)(sizeof ( buf ) - 1); }
    {int ret; ret = (int)(sizeof ( buf ) - 1); }
    {void * tlv16; tlv16 = (void *)(sizeof ( buf ) - 1); }
    {cgc_size_t tlv18; tlv18 = (cgc_size_t)(sizeof ( buf ) - 1); }
    {int tlv22; tlv22 = (int)(sizeof ( buf ) - 1); }
    {cgc_size_t tlv20; tlv20 = (cgc_size_t)(sizeof ( buf ) - 1); }
    {unsigned int tlv23; tlv23 = (unsigned int)(sizeof ( buf ) - 1); }
}
void fix_ingred_service_0_2(){
fix_ingred_service_0_2_0();
fix_ingred_service_0_2_1();
fix_ingred_service_0_2_2();
}
void fix_ingred_service_0_3_2(){
int bytes_read;
    bzero(&bytes_read,sizeof(int));
    {char buf [ 1024 ]; buf [ ( 1024 )-1 ] = (char)(bytes_read); }
    {int arg_pos; arg_pos = (int)(bytes_read); }
    {int tlv1; tlv1 = (int)(bytes_read); }
    {int tlv5; tlv5 = (int)(bytes_read); }
    {char * tlv4; tlv4 = (char *)(bytes_read); }
    {cgc_size_t tlv3; tlv3 = (cgc_size_t)(bytes_read); }
    {char * tlv7; tlv7 = (char *)(bytes_read); }
    {char * tlv6; tlv6 = (char *)(bytes_read); }
    {int tlv2; tlv2 = (int)(bytes_read); }
    {unsigned int tlv8; tlv8 = (unsigned int)(bytes_read); }
    {int tlv10; tlv10 = (int)(bytes_read); }
    {int tlv9; tlv9 = (int)(bytes_read); }
    {int tlv12; tlv12 = (int)(bytes_read); }
    {char * tlv15; tlv15 = (char *)(bytes_read); }
    {char * tlv14; tlv14 = (char *)(bytes_read); }
    {int program_num; program_num = (int)(bytes_read); }
    {int ret; ret = (int)(bytes_read); }
    {void * tlv16; tlv16 = (void *)(bytes_read); }
    {cgc_size_t tlv18; tlv18 = (cgc_size_t)(bytes_read); }
    {int tlv22; tlv22 = (int)(bytes_read); }
    {cgc_size_t tlv20; tlv20 = (cgc_size_t)(bytes_read); }
    {unsigned int tlv23; tlv23 = (unsigned int)(bytes_read); }
}
void fix_ingred_service_0_3(){
fix_ingred_service_0_3_2();
}
void fix_ingred_service_0_4_0(){
    {char buf [ 1024 ]; buf [ ( 1024 )-1 ] = (char)(1); }
    {int bytes_read; bytes_read = (int)(1); }
    {int arg_pos; arg_pos = (int)(1); }
    {int tlv1; tlv1 = (int)(1); }
    {int tlv5; tlv5 = (int)(1); }
    {char * tlv4; tlv4 = (char *)(1); }
    {cgc_size_t tlv3; tlv3 = (cgc_size_t)(1); }
    {char * tlv7; tlv7 = (char *)(1); }
    {char * tlv6; tlv6 = (char *)(1); }
    {int tlv2; tlv2 = (int)(1); }
    {unsigned int tlv8; tlv8 = (unsigned int)(1); }
    {int tlv10; tlv10 = (int)(1); }
    {int tlv9; tlv9 = (int)(1); }
    {int tlv12; tlv12 = (int)(1); }
    {char * tlv15; tlv15 = (char *)(1); }
    {char * tlv14; tlv14 = (char *)(1); }
    {int program_num; program_num = (int)(1); }
    {int ret; ret = (int)(1); }
    {void * tlv16; tlv16 = (void *)(1); }
    {cgc_size_t tlv18; tlv18 = (cgc_size_t)(1); }
    {int tlv22; tlv22 = (int)(1); }
    {cgc_size_t tlv20; tlv20 = (cgc_size_t)(1); }
    {unsigned int tlv23; tlv23 = (unsigned int)(1); }
}
void fix_ingred_service_0_4(){
fix_ingred_service_0_4_0();
}
void fix_ingred_service_0_6_1(){
    {char buf [ 1024 ]; buf [ ( 1024 )-1 ] = (char)(MAX_PROGRAM_STACK_SIZE); }
    {int bytes_read; bytes_read = (int)(MAX_PROGRAM_STACK_SIZE); }
    {int arg_pos; arg_pos = (int)(MAX_PROGRAM_STACK_SIZE); }
    {int tlv1; tlv1 = (int)(MAX_PROGRAM_STACK_SIZE); }
    {int tlv5; tlv5 = (int)(MAX_PROGRAM_STACK_SIZE); }
    {char * tlv4; tlv4 = (char *)(MAX_PROGRAM_STACK_SIZE); }
    {cgc_size_t tlv3; tlv3 = (cgc_size_t)(MAX_PROGRAM_STACK_SIZE); }
    {char * tlv7; tlv7 = (char *)(MAX_PROGRAM_STACK_SIZE); }
    {char * tlv6; tlv6 = (char *)(MAX_PROGRAM_STACK_SIZE); }
    {int tlv2; tlv2 = (int)(MAX_PROGRAM_STACK_SIZE); }
    {unsigned int tlv8; tlv8 = (unsigned int)(MAX_PROGRAM_STACK_SIZE); }
    {int tlv10; tlv10 = (int)(MAX_PROGRAM_STACK_SIZE); }
    {int tlv9; tlv9 = (int)(MAX_PROGRAM_STACK_SIZE); }
    {int tlv12; tlv12 = (int)(MAX_PROGRAM_STACK_SIZE); }
    {char * tlv15; tlv15 = (char *)(MAX_PROGRAM_STACK_SIZE); }
    {char * tlv14; tlv14 = (char *)(MAX_PROGRAM_STACK_SIZE); }
    {int program_num; program_num = (int)(MAX_PROGRAM_STACK_SIZE); }
    {int ret; ret = (int)(MAX_PROGRAM_STACK_SIZE); }
    {void * tlv16; tlv16 = (void *)(MAX_PROGRAM_STACK_SIZE); }
    {cgc_size_t tlv18; tlv18 = (cgc_size_t)(MAX_PROGRAM_STACK_SIZE); }
    {int tlv22; tlv22 = (int)(MAX_PROGRAM_STACK_SIZE); }
    {cgc_size_t tlv20; tlv20 = (cgc_size_t)(MAX_PROGRAM_STACK_SIZE); }
    {unsigned int tlv23; tlv23 = (unsigned int)(MAX_PROGRAM_STACK_SIZE); }
}
void fix_ingred_service_0_6_2(){
    {char buf [ 1024 ]; buf [ ( 1024 )-1 ] = (char)(sizeof ( Program * )); }
    {int bytes_read; bytes_read = (int)(sizeof ( Program * )); }
    {int arg_pos; arg_pos = (int)(sizeof ( Program * )); }
    {int tlv1; tlv1 = (int)(sizeof ( Program * )); }
    {int tlv5; tlv5 = (int)(sizeof ( Program * )); }
    {char * tlv4; tlv4 = (char *)(sizeof ( Program * )); }
    {cgc_size_t tlv3; tlv3 = (cgc_size_t)(sizeof ( Program * )); }
    {char * tlv7; tlv7 = (char *)(sizeof ( Program * )); }
    {char * tlv6; tlv6 = (char *)(sizeof ( Program * )); }
    {int tlv2; tlv2 = (int)(sizeof ( Program * )); }
    {unsigned int tlv8; tlv8 = (unsigned int)(sizeof ( Program * )); }
    {int tlv10; tlv10 = (int)(sizeof ( Program * )); }
    {int tlv9; tlv9 = (int)(sizeof ( Program * )); }
    {int tlv12; tlv12 = (int)(sizeof ( Program * )); }
    {char * tlv15; tlv15 = (char *)(sizeof ( Program * )); }
    {char * tlv14; tlv14 = (char *)(sizeof ( Program * )); }
    {int program_num; program_num = (int)(sizeof ( Program * )); }
    {int ret; ret = (int)(sizeof ( Program * )); }
    {void * tlv16; tlv16 = (void *)(sizeof ( Program * )); }
    {cgc_size_t tlv18; tlv18 = (cgc_size_t)(sizeof ( Program * )); }
    {int tlv22; tlv22 = (int)(sizeof ( Program * )); }
    {cgc_size_t tlv20; tlv20 = (cgc_size_t)(sizeof ( Program * )); }
    {unsigned int tlv23; tlv23 = (unsigned int)(sizeof ( Program * )); }
}
void fix_ingred_service_0_6(){
fix_ingred_service_0_6_1();
fix_ingred_service_0_6_2();
}
void fix_ingred_service_0_7_0(){
    {char buf [ 1024 ]; buf [ ( 1024 )-1 ] = (char)(NEW_PROGRAM_CMD_STR); }
    {int bytes_read; bytes_read = (int)(NEW_PROGRAM_CMD_STR); }
    {int arg_pos; arg_pos = (int)(NEW_PROGRAM_CMD_STR); }
    {int tlv1; tlv1 = (int)(NEW_PROGRAM_CMD_STR); }
    {int tlv5; tlv5 = (int)(NEW_PROGRAM_CMD_STR); }
    {char * tlv4; tlv4 = (char *)(NEW_PROGRAM_CMD_STR); }
    {cgc_size_t tlv3; tlv3 = (cgc_size_t)(NEW_PROGRAM_CMD_STR); }
    {char * tlv7; tlv7 = (char *)(NEW_PROGRAM_CMD_STR); }
    {char * tlv6; tlv6 = (char *)(NEW_PROGRAM_CMD_STR); }
    {int tlv2; tlv2 = (int)(NEW_PROGRAM_CMD_STR); }
    {unsigned int tlv8; tlv8 = (unsigned int)(NEW_PROGRAM_CMD_STR); }
    {int tlv10; tlv10 = (int)(NEW_PROGRAM_CMD_STR); }
    {int tlv9; tlv9 = (int)(NEW_PROGRAM_CMD_STR); }
    {int tlv12; tlv12 = (int)(NEW_PROGRAM_CMD_STR); }
    {char * tlv15; tlv15 = (char *)(NEW_PROGRAM_CMD_STR); }
    {char * tlv14; tlv14 = (char *)(NEW_PROGRAM_CMD_STR); }
    {int program_num; program_num = (int)(NEW_PROGRAM_CMD_STR); }
    {int ret; ret = (int)(NEW_PROGRAM_CMD_STR); }
    {void * tlv16; tlv16 = (void *)(NEW_PROGRAM_CMD_STR); }
    {cgc_size_t tlv18; tlv18 = (cgc_size_t)(NEW_PROGRAM_CMD_STR); }
    {int tlv22; tlv22 = (int)(NEW_PROGRAM_CMD_STR); }
    {cgc_size_t tlv20; tlv20 = (cgc_size_t)(NEW_PROGRAM_CMD_STR); }
    {unsigned int tlv23; tlv23 = (unsigned int)(NEW_PROGRAM_CMD_STR); }
}
void fix_ingred_service_0_7(){
fix_ingred_service_0_7_0();
}
void fix_ingred_service_0_8_3(){
int tlv1;
    bzero(&tlv1,sizeof(int));
    {char buf [ 1024 ]; buf [ ( 1024 )-1 ] = (char)(tlv1); }
    {int bytes_read; bytes_read = (int)(tlv1); }
    {int arg_pos; arg_pos = (int)(tlv1); }
    {int tlv5; tlv5 = (int)(tlv1); }
    {char * tlv4; tlv4 = (char *)(tlv1); }
    {cgc_size_t tlv3; tlv3 = (cgc_size_t)(tlv1); }
    {char * tlv7; tlv7 = (char *)(tlv1); }
    {char * tlv6; tlv6 = (char *)(tlv1); }
    {int tlv2; tlv2 = (int)(tlv1); }
    {unsigned int tlv8; tlv8 = (unsigned int)(tlv1); }
    {int tlv10; tlv10 = (int)(tlv1); }
    {int tlv9; tlv9 = (int)(tlv1); }
    {int tlv12; tlv12 = (int)(tlv1); }
    {char * tlv15; tlv15 = (char *)(tlv1); }
    {char * tlv14; tlv14 = (char *)(tlv1); }
    {int program_num; program_num = (int)(tlv1); }
    {int ret; ret = (int)(tlv1); }
    {void * tlv16; tlv16 = (void *)(tlv1); }
    {cgc_size_t tlv18; tlv18 = (cgc_size_t)(tlv1); }
    {int tlv22; tlv22 = (int)(tlv1); }
    {cgc_size_t tlv20; tlv20 = (cgc_size_t)(tlv1); }
    {unsigned int tlv23; tlv23 = (unsigned int)(tlv1); }
}
void fix_ingred_service_0_8(){
fix_ingred_service_0_8_3();
}
void fix_ingred_service_0_11_1(){
Program program_ref;
    bzero(&program_ref,1*sizeof(Program));
Program * program = &program_ref;
    {char buf [ 1024 ]; buf [ ( 1024 )-1 ] = (char)(& program); }
    {int bytes_read; bytes_read = (int)(& program); }
    {int arg_pos; arg_pos = (int)(& program); }
    {int tlv1; tlv1 = (int)(& program); }
    {int tlv5; tlv5 = (int)(& program); }
    {char * tlv4; tlv4 = (char *)(& program); }
    {cgc_size_t tlv3; tlv3 = (cgc_size_t)(& program); }
    {char * tlv7; tlv7 = (char *)(& program); }
    {char * tlv6; tlv6 = (char *)(& program); }
    {int tlv2; tlv2 = (int)(& program); }
    {unsigned int tlv8; tlv8 = (unsigned int)(& program); }
    {int tlv10; tlv10 = (int)(& program); }
    {int tlv9; tlv9 = (int)(& program); }
    {int tlv12; tlv12 = (int)(& program); }
    {char * tlv15; tlv15 = (char *)(& program); }
    {char * tlv14; tlv14 = (char *)(& program); }
    {int program_num; program_num = (int)(& program); }
    {int ret; ret = (int)(& program); }
    {void * tlv16; tlv16 = (void *)(& program); }
    {cgc_size_t tlv18; tlv18 = (cgc_size_t)(& program); }
    {int tlv22; tlv22 = (int)(& program); }
    {cgc_size_t tlv20; tlv20 = (cgc_size_t)(& program); }
    {unsigned int tlv23; tlv23 = (unsigned int)(& program); }
}
void fix_ingred_service_0_11(){
fix_ingred_service_0_11_1();
}
void fix_ingred_service_0_13_0(){
    {char buf [ 1024 ]; buf [ ( 1024 )-1 ] = (char)(EXECUTE_PROGRAM_CMD_STR); }
    {int bytes_read; bytes_read = (int)(EXECUTE_PROGRAM_CMD_STR); }
    {int arg_pos; arg_pos = (int)(EXECUTE_PROGRAM_CMD_STR); }
    {int tlv1; tlv1 = (int)(EXECUTE_PROGRAM_CMD_STR); }
    {int tlv5; tlv5 = (int)(EXECUTE_PROGRAM_CMD_STR); }
    {char * tlv4; tlv4 = (char *)(EXECUTE_PROGRAM_CMD_STR); }
    {cgc_size_t tlv3; tlv3 = (cgc_size_t)(EXECUTE_PROGRAM_CMD_STR); }
    {char * tlv7; tlv7 = (char *)(EXECUTE_PROGRAM_CMD_STR); }
    {char * tlv6; tlv6 = (char *)(EXECUTE_PROGRAM_CMD_STR); }
    {int tlv2; tlv2 = (int)(EXECUTE_PROGRAM_CMD_STR); }
    {unsigned int tlv8; tlv8 = (unsigned int)(EXECUTE_PROGRAM_CMD_STR); }
    {int tlv10; tlv10 = (int)(EXECUTE_PROGRAM_CMD_STR); }
    {int tlv9; tlv9 = (int)(EXECUTE_PROGRAM_CMD_STR); }
    {int tlv12; tlv12 = (int)(EXECUTE_PROGRAM_CMD_STR); }
    {char * tlv15; tlv15 = (char *)(EXECUTE_PROGRAM_CMD_STR); }
    {char * tlv14; tlv14 = (char *)(EXECUTE_PROGRAM_CMD_STR); }
    {int program_num; program_num = (int)(EXECUTE_PROGRAM_CMD_STR); }
    {int ret; ret = (int)(EXECUTE_PROGRAM_CMD_STR); }
    {void * tlv16; tlv16 = (void *)(EXECUTE_PROGRAM_CMD_STR); }
    {cgc_size_t tlv18; tlv18 = (cgc_size_t)(EXECUTE_PROGRAM_CMD_STR); }
    {int tlv22; tlv22 = (int)(EXECUTE_PROGRAM_CMD_STR); }
    {cgc_size_t tlv20; tlv20 = (cgc_size_t)(EXECUTE_PROGRAM_CMD_STR); }
    {unsigned int tlv23; tlv23 = (unsigned int)(EXECUTE_PROGRAM_CMD_STR); }
}
void fix_ingred_service_0_13(){
fix_ingred_service_0_13_0();
}
void fix_ingred_service_0_14_2(){
int tlv2;
    bzero(&tlv2,sizeof(int));
    {char buf [ 1024 ]; buf [ ( 1024 )-1 ] = (char)(tlv2); }
    {int bytes_read; bytes_read = (int)(tlv2); }
    {int arg_pos; arg_pos = (int)(tlv2); }
    {int tlv1; tlv1 = (int)(tlv2); }
    {int tlv5; tlv5 = (int)(tlv2); }
    {char * tlv4; tlv4 = (char *)(tlv2); }
    {cgc_size_t tlv3; tlv3 = (cgc_size_t)(tlv2); }
    {char * tlv7; tlv7 = (char *)(tlv2); }
    {char * tlv6; tlv6 = (char *)(tlv2); }
    {unsigned int tlv8; tlv8 = (unsigned int)(tlv2); }
    {int tlv10; tlv10 = (int)(tlv2); }
    {int tlv9; tlv9 = (int)(tlv2); }
    {int tlv12; tlv12 = (int)(tlv2); }
    {char * tlv15; tlv15 = (char *)(tlv2); }
    {char * tlv14; tlv14 = (char *)(tlv2); }
    {int program_num; program_num = (int)(tlv2); }
    {int ret; ret = (int)(tlv2); }
    {void * tlv16; tlv16 = (void *)(tlv2); }
    {cgc_size_t tlv18; tlv18 = (cgc_size_t)(tlv2); }
    {int tlv22; tlv22 = (int)(tlv2); }
    {cgc_size_t tlv20; tlv20 = (cgc_size_t)(tlv2); }
    {unsigned int tlv23; tlv23 = (unsigned int)(tlv2); }
}
void fix_ingred_service_0_14(){
fix_ingred_service_0_14_2();
}
void fix_ingred_service_0_15_0(){
    {char buf [ 1024 ]; buf [ ( 1024 )-1 ] = (char)(10); }
    {int bytes_read; bytes_read = (int)(10); }
    {int arg_pos; arg_pos = (int)(10); }
    {int tlv1; tlv1 = (int)(10); }
    {int tlv5; tlv5 = (int)(10); }
    {char * tlv4; tlv4 = (char *)(10); }
    {cgc_size_t tlv3; tlv3 = (cgc_size_t)(10); }
    {char * tlv7; tlv7 = (char *)(10); }
    {char * tlv6; tlv6 = (char *)(10); }
    {int tlv2; tlv2 = (int)(10); }
    {unsigned int tlv8; tlv8 = (unsigned int)(10); }
    {int tlv10; tlv10 = (int)(10); }
    {int tlv9; tlv9 = (int)(10); }
    {int tlv12; tlv12 = (int)(10); }
    {char * tlv15; tlv15 = (char *)(10); }
    {char * tlv14; tlv14 = (char *)(10); }
    {int program_num; program_num = (int)(10); }
    {int ret; ret = (int)(10); }
    {void * tlv16; tlv16 = (void *)(10); }
    {cgc_size_t tlv18; tlv18 = (cgc_size_t)(10); }
    {int tlv22; tlv22 = (int)(10); }
    {cgc_size_t tlv20; tlv20 = (cgc_size_t)(10); }
    {unsigned int tlv23; tlv23 = (unsigned int)(10); }
}
void fix_ingred_service_0_15(){
fix_ingred_service_0_15_0();
}
void fix_ingred_service_0_16_5(){
int program_num;
    bzero(&program_num,sizeof(int));
Stack programStack;
    bzero(&programStack,sizeof(Stack));
    {char buf [ 1024 ]; buf [ ( 1024 )-1 ] = (char)(program_num); }
    {int bytes_read; bytes_read = (int)(program_num); }
    {int arg_pos; arg_pos = (int)(program_num); }
    {int tlv1; tlv1 = (int)(program_num); }
    {int tlv5; tlv5 = (int)(program_num); }
    {char * tlv4; tlv4 = (char *)(program_num); }
    {cgc_size_t tlv3; tlv3 = (cgc_size_t)(program_num); }
    {char * tlv7; tlv7 = (char *)(program_num); }
    {char * tlv6; tlv6 = (char *)(program_num); }
    {int tlv2; tlv2 = (int)(program_num); }
    {unsigned int tlv8; tlv8 = (unsigned int)(program_num); }
    {int tlv10; tlv10 = (int)(program_num); }
    {int tlv9; tlv9 = (int)(program_num); }
    {int tlv12; tlv12 = (int)(program_num); }
    {char * tlv15; tlv15 = (char *)(program_num); }
    {char * tlv14; tlv14 = (char *)(program_num); }
    {int ret; ret = (int)(program_num); }
    {void * tlv16; tlv16 = (void *)(program_num); }
    {cgc_size_t tlv18; tlv18 = (cgc_size_t)(program_num); }
    {int tlv22; tlv22 = (int)(program_num); }
    {cgc_size_t tlv20; tlv20 = (cgc_size_t)(program_num); }
    {unsigned int tlv23; tlv23 = (unsigned int)(program_num); }
}
void fix_ingred_service_0_16_6(){
int program_num;
    bzero(&program_num,sizeof(int));
Stack programStack;
    bzero(&programStack,sizeof(Stack));
    {char buf [ 1024 ]; buf [ ( 1024 )-1 ] = (char)(programStack . top); }
    {int bytes_read; bytes_read = (int)(programStack . top); }
    {int arg_pos; arg_pos = (int)(programStack . top); }
    {int tlv1; tlv1 = (int)(programStack . top); }
    {int tlv5; tlv5 = (int)(programStack . top); }
    {char * tlv4; tlv4 = (char *)(programStack . top); }
    {cgc_size_t tlv3; tlv3 = (cgc_size_t)(programStack . top); }
    {char * tlv7; tlv7 = (char *)(programStack . top); }
    {char * tlv6; tlv6 = (char *)(programStack . top); }
    {int tlv2; tlv2 = (int)(programStack . top); }
    {unsigned int tlv8; tlv8 = (unsigned int)(programStack . top); }
    {int tlv10; tlv10 = (int)(programStack . top); }
    {int tlv9; tlv9 = (int)(programStack . top); }
    {int tlv12; tlv12 = (int)(programStack . top); }
    {char * tlv15; tlv15 = (char *)(programStack . top); }
    {char * tlv14; tlv14 = (char *)(programStack . top); }
    {int program_num; program_num = (int)(programStack . top); }
    {int ret; ret = (int)(programStack . top); }
    {void * tlv16; tlv16 = (void *)(programStack . top); }
    {cgc_size_t tlv18; tlv18 = (cgc_size_t)(programStack . top); }
    {int tlv22; tlv22 = (int)(programStack . top); }
    {cgc_size_t tlv20; tlv20 = (cgc_size_t)(programStack . top); }
    {unsigned int tlv23; tlv23 = (unsigned int)(programStack . top); }
}
void fix_ingred_service_0_16(){
fix_ingred_service_0_16_5();
fix_ingred_service_0_16_6();
}
void fix_ingred_service_0_17_0(){
    {char buf [ 1024 ]; buf [ ( 1024 )-1 ] = (char)(STDOUT); }
    {int bytes_read; bytes_read = (int)(STDOUT); }
    {int arg_pos; arg_pos = (int)(STDOUT); }
    {int tlv1; tlv1 = (int)(STDOUT); }
    {int tlv5; tlv5 = (int)(STDOUT); }
    {char * tlv4; tlv4 = (char *)(STDOUT); }
    {cgc_size_t tlv3; tlv3 = (cgc_size_t)(STDOUT); }
    {char * tlv7; tlv7 = (char *)(STDOUT); }
    {char * tlv6; tlv6 = (char *)(STDOUT); }
    {int tlv2; tlv2 = (int)(STDOUT); }
    {unsigned int tlv8; tlv8 = (unsigned int)(STDOUT); }
    {int tlv10; tlv10 = (int)(STDOUT); }
    {int tlv9; tlv9 = (int)(STDOUT); }
    {int tlv12; tlv12 = (int)(STDOUT); }
    {char * tlv15; tlv15 = (char *)(STDOUT); }
    {char * tlv14; tlv14 = (char *)(STDOUT); }
    {int program_num; program_num = (int)(STDOUT); }
    {int ret; ret = (int)(STDOUT); }
    {void * tlv16; tlv16 = (void *)(STDOUT); }
    {cgc_size_t tlv18; tlv18 = (cgc_size_t)(STDOUT); }
    {int tlv22; tlv22 = (int)(STDOUT); }
    {cgc_size_t tlv20; tlv20 = (cgc_size_t)(STDOUT); }
    {unsigned int tlv23; tlv23 = (unsigned int)(STDOUT); }
}
void fix_ingred_service_0_17_1(){
    {char buf [ 1024 ]; buf [ ( 1024 )-1 ] = (char)(sizeof ( TOO_MANY_LINES_STR )); }
    {int bytes_read; bytes_read = (int)(sizeof ( TOO_MANY_LINES_STR )); }
    {int arg_pos; arg_pos = (int)(sizeof ( TOO_MANY_LINES_STR )); }
    {int tlv1; tlv1 = (int)(sizeof ( TOO_MANY_LINES_STR )); }
    {int tlv5; tlv5 = (int)(sizeof ( TOO_MANY_LINES_STR )); }
    {char * tlv4; tlv4 = (char *)(sizeof ( TOO_MANY_LINES_STR )); }
    {cgc_size_t tlv3; tlv3 = (cgc_size_t)(sizeof ( TOO_MANY_LINES_STR )); }
    {char * tlv7; tlv7 = (char *)(sizeof ( TOO_MANY_LINES_STR )); }
    {char * tlv6; tlv6 = (char *)(sizeof ( TOO_MANY_LINES_STR )); }
    {int tlv2; tlv2 = (int)(sizeof ( TOO_MANY_LINES_STR )); }
    {unsigned int tlv8; tlv8 = (unsigned int)(sizeof ( TOO_MANY_LINES_STR )); }
    {int tlv10; tlv10 = (int)(sizeof ( TOO_MANY_LINES_STR )); }
    {int tlv9; tlv9 = (int)(sizeof ( TOO_MANY_LINES_STR )); }
    {int tlv12; tlv12 = (int)(sizeof ( TOO_MANY_LINES_STR )); }
    {char * tlv15; tlv15 = (char *)(sizeof ( TOO_MANY_LINES_STR )); }
    {char * tlv14; tlv14 = (char *)(sizeof ( TOO_MANY_LINES_STR )); }
    {int program_num; program_num = (int)(sizeof ( TOO_MANY_LINES_STR )); }
    {int ret; ret = (int)(sizeof ( TOO_MANY_LINES_STR )); }
    {void * tlv16; tlv16 = (void *)(sizeof ( TOO_MANY_LINES_STR )); }
    {cgc_size_t tlv18; tlv18 = (cgc_size_t)(sizeof ( TOO_MANY_LINES_STR )); }
    {int tlv22; tlv22 = (int)(sizeof ( TOO_MANY_LINES_STR )); }
    {cgc_size_t tlv20; tlv20 = (cgc_size_t)(sizeof ( TOO_MANY_LINES_STR )); }
    {unsigned int tlv23; tlv23 = (unsigned int)(sizeof ( TOO_MANY_LINES_STR )); }
}
void fix_ingred_service_0_17(){
fix_ingred_service_0_17_0();
fix_ingred_service_0_17_1();
}
void fix_ingred_service_0_18_7(){
int ret;
    bzero(&ret,sizeof(int));
    {char buf [ 1024 ]; buf [ ( 1024 )-1 ] = (char)(ret); }
    {int bytes_read; bytes_read = (int)(ret); }
    {int arg_pos; arg_pos = (int)(ret); }
    {int tlv1; tlv1 = (int)(ret); }
    {int tlv5; tlv5 = (int)(ret); }
    {char * tlv4; tlv4 = (char *)(ret); }
    {cgc_size_t tlv3; tlv3 = (cgc_size_t)(ret); }
    {char * tlv7; tlv7 = (char *)(ret); }
    {char * tlv6; tlv6 = (char *)(ret); }
    {int tlv2; tlv2 = (int)(ret); }
    {unsigned int tlv8; tlv8 = (unsigned int)(ret); }
    {int tlv10; tlv10 = (int)(ret); }
    {int tlv9; tlv9 = (int)(ret); }
    {int tlv12; tlv12 = (int)(ret); }
    {char * tlv15; tlv15 = (char *)(ret); }
    {char * tlv14; tlv14 = (char *)(ret); }
    {int program_num; program_num = (int)(ret); }
    {void * tlv16; tlv16 = (void *)(ret); }
    {cgc_size_t tlv18; tlv18 = (cgc_size_t)(ret); }
    {int tlv22; tlv22 = (int)(ret); }
    {cgc_size_t tlv20; tlv20 = (cgc_size_t)(ret); }
    {unsigned int tlv23; tlv23 = (unsigned int)(ret); }
}
void fix_ingred_service_0_18(){
fix_ingred_service_0_18_7();
}
void fix_ingred_service_0_19_0(){
    {char buf [ 1024 ]; buf [ ( 1024 )-1 ] = (char)(13); }
    {int bytes_read; bytes_read = (int)(13); }
    {int arg_pos; arg_pos = (int)(13); }
    {int tlv1; tlv1 = (int)(13); }
    {int tlv5; tlv5 = (int)(13); }
    {char * tlv4; tlv4 = (char *)(13); }
    {cgc_size_t tlv3; tlv3 = (cgc_size_t)(13); }
    {char * tlv7; tlv7 = (char *)(13); }
    {char * tlv6; tlv6 = (char *)(13); }
    {int tlv2; tlv2 = (int)(13); }
    {unsigned int tlv8; tlv8 = (unsigned int)(13); }
    {int tlv10; tlv10 = (int)(13); }
    {int tlv9; tlv9 = (int)(13); }
    {int tlv12; tlv12 = (int)(13); }
    {char * tlv15; tlv15 = (char *)(13); }
    {char * tlv14; tlv14 = (char *)(13); }
    {int program_num; program_num = (int)(13); }
    {int ret; ret = (int)(13); }
    {void * tlv16; tlv16 = (void *)(13); }
    {cgc_size_t tlv18; tlv18 = (cgc_size_t)(13); }
    {int tlv22; tlv22 = (int)(13); }
    {cgc_size_t tlv20; tlv20 = (cgc_size_t)(13); }
    {unsigned int tlv23; tlv23 = (unsigned int)(13); }
}
void fix_ingred_service_0_19(){
fix_ingred_service_0_19_0();
}
void fix_ingred_service_0(){
fix_ingred_service_0_1();
fix_ingred_service_0_2();
fix_ingred_service_0_3();
fix_ingred_service_0_4();
fix_ingred_service_0_6();
fix_ingred_service_0_7();
fix_ingred_service_0_8();
fix_ingred_service_0_11();
fix_ingred_service_0_13();
fix_ingred_service_0_14();
fix_ingred_service_0_15();
fix_ingred_service_0_16();
fix_ingred_service_0_17();
fix_ingred_service_0_18();
fix_ingred_service_0_19();
}
