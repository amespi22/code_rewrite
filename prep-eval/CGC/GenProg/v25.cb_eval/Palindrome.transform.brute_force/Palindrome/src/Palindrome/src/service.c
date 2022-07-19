

//CADET's first C program
#include "libcgc.h"
#include "cgc_libc.h"
#define HI "\nWelcome to Palindrome Finder\n\n"
#define ASK "\tPlease enter a possible palindrome: "
#define YES "\t\tYes, that's a palindrome!\n\n"
#define NO "\t\tNope, that's not a palindrome\n\n"
#define EASTEREGG "\n\nEASTER EGG!\n\n"
int cgc_check();
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
void fix_ingred_service_0_1_1();
void fix_ingred_service_0_1();
void fix_ingred_service_0_2_0();
void fix_ingred_service_0_2_1();
void fix_ingred_service_0_2();
void fix_ingred_service_0_3_0();
void fix_ingred_service_0_3();
void fix_ingred_service_0_5_1();
void fix_ingred_service_0_5();
void fix_ingred_service_0_6_0();
void fix_ingred_service_0_6();
void fix_ingred_service_0_8_0();
void fix_ingred_service_0_8_1();
void fix_ingred_service_0_8();
void fix_ingred_service_0_11_1();
void fix_ingred_service_0_11();
void fix_ingred_service_0_12_2();
void fix_ingred_service_0_12();
void fix_ingred_service_0_15_1();
void fix_ingred_service_0_15();
void fix_ingred_service_0_16_0();
void fix_ingred_service_0_16();
void fix_ingred_service_0();
int main(int cgc_argc, char *cgc_argv[])
{
if (fix_ingred_enable){ fix_ingred_service_0(); };
    int r;
    int tlv1;
    {
        int tlv7;
        tlv7 = 1;
        const char* tlv6 = HI;
        cgc_size_t tlv5;
        tlv5 = sizeof ( HI ) - 1;
        tlv1 = cgc_transmit_all(tlv7,tlv6,tlv5);
    }
    if (tlv1 != 0) {
 {
     unsigned int tlv8;
     tlv8 = 0;
    	cgc__terminate(tlv8);
 }
    }

    while (1) {
 int tlv2;
 {
     int tlv11;
     tlv11 = 1;
     const char* tlv10 = ASK;
     cgc_size_t tlv9;
     tlv9 = sizeof ( ASK ) - 1;
     tlv2 = cgc_transmit_all(tlv11,tlv10,tlv9);
 }
	if (tlv2 != 0) {
     {
         unsigned int tlv12;
         tlv12 = 0;
    	    cgc__terminate(tlv12);
     }
	}
	r = cgc_check();
	if (r == -1) {
	    break;
	} else {
	    if (r == 0) {
  int tlv3;
  {
      int tlv15;
      tlv15 = 1;
      const char* tlv14 = NO;
      cgc_size_t tlv13;
      tlv13 = sizeof ( NO ) - 1;
      tlv3 = cgc_transmit_all(tlv15,tlv14,tlv13);
  }
		if (tlv3 != 0) {
      {
          unsigned int tlv19;
          tlv19 = 0;
    		    cgc__terminate(tlv19);
      }
		}
	    } else {
  int tlv4;
  {
      int tlv18;
      tlv18 = 1;
      const char* tlv17 = YES;
      cgc_size_t tlv16;
      tlv16 = sizeof ( YES ) - 1;
      tlv4 = cgc_transmit_all(tlv18,tlv17,tlv16);
  }
		if (tlv4 != 0) {
      {
          unsigned int tlv20;
          tlv20 = 0;
    		    cgc__terminate(tlv20);
      }
		}
	    }
	}
    }
    return 0;
}

void fix_ingred_service_1_0_0();
void fix_ingred_service_1_0_1();
void fix_ingred_service_1_0_2();
void fix_ingred_service_1_0_3();
void fix_ingred_service_1_0();
void fix_ingred_service_1_1_4();
void fix_ingred_service_1_1_5();
void fix_ingred_service_1_1_6();
void fix_ingred_service_1_1();
void fix_ingred_service_1_2_1();
void fix_ingred_service_1_2_2();
void fix_ingred_service_1_2_3();
void fix_ingred_service_1_2();
void fix_ingred_service_1_3_3();
void fix_ingred_service_1_3();
void fix_ingred_service_1_4_4();
void fix_ingred_service_1_4_5();
void fix_ingred_service_1_4();
void fix_ingred_service_1_8_4();
void fix_ingred_service_1_8_5();
void fix_ingred_service_1_8();
void fix_ingred_service_1_9_1();
void fix_ingred_service_1_9();
void fix_ingred_service_1_10_6();
void fix_ingred_service_1_10();
void fix_ingred_service_1_11_0();
void fix_ingred_service_1_11();
void fix_ingred_service_1();
int cgc_check()
{
if (fix_ingred_enable){ fix_ingred_service_1(); };
    int len;
    len = - 1;
    int i;
    int pal;
    pal = 1;
    char string[64];
    unsigned long tlv_size_0;
    tlv_size_0 = sizeof ( string );
    for (i = 0; i < tlv_size_0; i++)
    {
	string[i] = '\0';
    }
    int tlv1;
    {
        int tlv6;
        tlv6 = 0;
        char* tlv5;
         tlv5 = string;
        cgc_size_t tlv4;
        tlv4 = 128;
        char tlv3;
        tlv3 = '\n';
        tlv1 = cgc_receive_delim(tlv6,tlv5,tlv4,tlv3);
    }
    if (tlv1 != 0) {
	return -1;
    }
    for (i = 0; string[i] != '\0'; i++) {
	len++;
    }
    int steps;
    steps = len;
    if (len % 2 == 1) {
	steps--;
    }
    for (i = 0; i <= steps / 2; i++) {
	if (string[i] != string[len - 1 - i]) {
	    pal = 0;
	}
    }
    if (string[0] == '^') {
 int tlv2;
 {
     int tlv9;
     tlv9 = 1;
     const char* tlv8 = EASTEREGG;
     cgc_size_t tlv7;
     tlv7 = sizeof ( EASTEREGG ) - 1;
     tlv2 = cgc_transmit_all(tlv9,tlv8,tlv7);
 }
	if (tlv2 != 0) {
     {
         unsigned int tlv10;
         tlv10 = 0;
    	    cgc__terminate(tlv10);
     }
	}
    }
    return pal;
}

void fix_ingred_service_0_1_0(){
    {int r; r = (int)(1); }
    {int tlv1; tlv1 = (int)(1); }
    {int tlv7; tlv7 = (int)(1); }
    {cgc_size_t tlv5; tlv5 = (cgc_size_t)(1); }
    {int tlv2; tlv2 = (int)(1); }
    {unsigned int tlv8; tlv8 = (unsigned int)(1); }
    {int tlv11; tlv11 = (int)(1); }
    {cgc_size_t tlv9; tlv9 = (cgc_size_t)(1); }
    {unsigned int tlv12; tlv12 = (unsigned int)(1); }
    {int tlv3; tlv3 = (int)(1); }
    {int tlv4; tlv4 = (int)(1); }
    {int tlv15; tlv15 = (int)(1); }
    {cgc_size_t tlv13; tlv13 = (cgc_size_t)(1); }
    {int tlv18; tlv18 = (int)(1); }
    {cgc_size_t tlv16; tlv16 = (cgc_size_t)(1); }
    {unsigned int tlv19; tlv19 = (unsigned int)(1); }
    {unsigned int tlv20; tlv20 = (unsigned int)(1); }
}
void fix_ingred_service_0_1_1(){
    {int r; r = (int)(sizeof ( HI ) - 1); }
    {int tlv1; tlv1 = (int)(sizeof ( HI ) - 1); }
    {int tlv7; tlv7 = (int)(sizeof ( HI ) - 1); }
    {cgc_size_t tlv5; tlv5 = (cgc_size_t)(sizeof ( HI ) - 1); }
    {int tlv2; tlv2 = (int)(sizeof ( HI ) - 1); }
    {unsigned int tlv8; tlv8 = (unsigned int)(sizeof ( HI ) - 1); }
    {int tlv11; tlv11 = (int)(sizeof ( HI ) - 1); }
    {cgc_size_t tlv9; tlv9 = (cgc_size_t)(sizeof ( HI ) - 1); }
    {unsigned int tlv12; tlv12 = (unsigned int)(sizeof ( HI ) - 1); }
    {int tlv3; tlv3 = (int)(sizeof ( HI ) - 1); }
    {int tlv4; tlv4 = (int)(sizeof ( HI ) - 1); }
    {int tlv15; tlv15 = (int)(sizeof ( HI ) - 1); }
    {cgc_size_t tlv13; tlv13 = (cgc_size_t)(sizeof ( HI ) - 1); }
    {int tlv18; tlv18 = (int)(sizeof ( HI ) - 1); }
    {cgc_size_t tlv16; tlv16 = (cgc_size_t)(sizeof ( HI ) - 1); }
    {unsigned int tlv19; tlv19 = (unsigned int)(sizeof ( HI ) - 1); }
    {unsigned int tlv20; tlv20 = (unsigned int)(sizeof ( HI ) - 1); }
}
void fix_ingred_service_0_1(){
fix_ingred_service_0_1_0();
fix_ingred_service_0_1_1();
}
void fix_ingred_service_0_2_0(){
int tlv1;
    bzero(&tlv1,sizeof(int));
    {int r; r = (int)(tlv1); }
    {int tlv7; tlv7 = (int)(tlv1); }
    {cgc_size_t tlv5; tlv5 = (cgc_size_t)(tlv1); }
    {int tlv2; tlv2 = (int)(tlv1); }
    {unsigned int tlv8; tlv8 = (unsigned int)(tlv1); }
    {int tlv11; tlv11 = (int)(tlv1); }
    {cgc_size_t tlv9; tlv9 = (cgc_size_t)(tlv1); }
    {unsigned int tlv12; tlv12 = (unsigned int)(tlv1); }
    {int tlv3; tlv3 = (int)(tlv1); }
    {int tlv4; tlv4 = (int)(tlv1); }
    {int tlv15; tlv15 = (int)(tlv1); }
    {cgc_size_t tlv13; tlv13 = (cgc_size_t)(tlv1); }
    {int tlv18; tlv18 = (int)(tlv1); }
    {cgc_size_t tlv16; tlv16 = (cgc_size_t)(tlv1); }
    {unsigned int tlv19; tlv19 = (unsigned int)(tlv1); }
    {unsigned int tlv20; tlv20 = (unsigned int)(tlv1); }
}
void fix_ingred_service_0_2_1(){
int tlv1;
    bzero(&tlv1,sizeof(int));
    {int r; r = (int)(0); }
    {int tlv1; tlv1 = (int)(0); }
    {int tlv7; tlv7 = (int)(0); }
    {cgc_size_t tlv5; tlv5 = (cgc_size_t)(0); }
    {int tlv2; tlv2 = (int)(0); }
    {unsigned int tlv8; tlv8 = (unsigned int)(0); }
    {int tlv11; tlv11 = (int)(0); }
    {cgc_size_t tlv9; tlv9 = (cgc_size_t)(0); }
    {unsigned int tlv12; tlv12 = (unsigned int)(0); }
    {int tlv3; tlv3 = (int)(0); }
    {int tlv4; tlv4 = (int)(0); }
    {int tlv15; tlv15 = (int)(0); }
    {cgc_size_t tlv13; tlv13 = (cgc_size_t)(0); }
    {int tlv18; tlv18 = (int)(0); }
    {cgc_size_t tlv16; tlv16 = (cgc_size_t)(0); }
    {unsigned int tlv19; tlv19 = (unsigned int)(0); }
    {unsigned int tlv20; tlv20 = (unsigned int)(0); }
}
void fix_ingred_service_0_2(){
fix_ingred_service_0_2_0();
fix_ingred_service_0_2_1();
}
void fix_ingred_service_0_3_0(){
    {int r; r = (int)(0); }
    {int tlv1; tlv1 = (int)(0); }
    {int tlv7; tlv7 = (int)(0); }
    {cgc_size_t tlv5; tlv5 = (cgc_size_t)(0); }
    {int tlv2; tlv2 = (int)(0); }
    {unsigned int tlv8; tlv8 = (unsigned int)(0); }
    {int tlv11; tlv11 = (int)(0); }
    {cgc_size_t tlv9; tlv9 = (cgc_size_t)(0); }
    {unsigned int tlv12; tlv12 = (unsigned int)(0); }
    {int tlv3; tlv3 = (int)(0); }
    {int tlv4; tlv4 = (int)(0); }
    {int tlv15; tlv15 = (int)(0); }
    {cgc_size_t tlv13; tlv13 = (cgc_size_t)(0); }
    {int tlv18; tlv18 = (int)(0); }
    {cgc_size_t tlv16; tlv16 = (cgc_size_t)(0); }
    {unsigned int tlv19; tlv19 = (unsigned int)(0); }
    {unsigned int tlv20; tlv20 = (unsigned int)(0); }
}
void fix_ingred_service_0_3(){
fix_ingred_service_0_3_0();
}
void fix_ingred_service_0_5_1(){
    {int r; r = (int)(sizeof ( ASK ) - 1); }
    {int tlv1; tlv1 = (int)(sizeof ( ASK ) - 1); }
    {int tlv7; tlv7 = (int)(sizeof ( ASK ) - 1); }
    {cgc_size_t tlv5; tlv5 = (cgc_size_t)(sizeof ( ASK ) - 1); }
    {int tlv2; tlv2 = (int)(sizeof ( ASK ) - 1); }
    {unsigned int tlv8; tlv8 = (unsigned int)(sizeof ( ASK ) - 1); }
    {int tlv11; tlv11 = (int)(sizeof ( ASK ) - 1); }
    {cgc_size_t tlv9; tlv9 = (cgc_size_t)(sizeof ( ASK ) - 1); }
    {unsigned int tlv12; tlv12 = (unsigned int)(sizeof ( ASK ) - 1); }
    {int tlv3; tlv3 = (int)(sizeof ( ASK ) - 1); }
    {int tlv4; tlv4 = (int)(sizeof ( ASK ) - 1); }
    {int tlv15; tlv15 = (int)(sizeof ( ASK ) - 1); }
    {cgc_size_t tlv13; tlv13 = (cgc_size_t)(sizeof ( ASK ) - 1); }
    {int tlv18; tlv18 = (int)(sizeof ( ASK ) - 1); }
    {cgc_size_t tlv16; tlv16 = (cgc_size_t)(sizeof ( ASK ) - 1); }
    {unsigned int tlv19; tlv19 = (unsigned int)(sizeof ( ASK ) - 1); }
    {unsigned int tlv20; tlv20 = (unsigned int)(sizeof ( ASK ) - 1); }
}
void fix_ingred_service_0_5(){
fix_ingred_service_0_5_1();
}
void fix_ingred_service_0_6_0(){
int tlv2;
    bzero(&tlv2,sizeof(int));
    {int r; r = (int)(tlv2); }
    {int tlv1; tlv1 = (int)(tlv2); }
    {int tlv7; tlv7 = (int)(tlv2); }
    {cgc_size_t tlv5; tlv5 = (cgc_size_t)(tlv2); }
    {unsigned int tlv8; tlv8 = (unsigned int)(tlv2); }
    {int tlv11; tlv11 = (int)(tlv2); }
    {cgc_size_t tlv9; tlv9 = (cgc_size_t)(tlv2); }
    {unsigned int tlv12; tlv12 = (unsigned int)(tlv2); }
    {int tlv3; tlv3 = (int)(tlv2); }
    {int tlv4; tlv4 = (int)(tlv2); }
    {int tlv15; tlv15 = (int)(tlv2); }
    {cgc_size_t tlv13; tlv13 = (cgc_size_t)(tlv2); }
    {int tlv18; tlv18 = (int)(tlv2); }
    {cgc_size_t tlv16; tlv16 = (cgc_size_t)(tlv2); }
    {unsigned int tlv19; tlv19 = (unsigned int)(tlv2); }
    {unsigned int tlv20; tlv20 = (unsigned int)(tlv2); }
}
void fix_ingred_service_0_6(){
fix_ingred_service_0_6_0();
}
void fix_ingred_service_0_8_0(){
int r;
    bzero(&r,sizeof(int));
    {int tlv1; tlv1 = (int)(r); }
    {int tlv7; tlv7 = (int)(r); }
    {cgc_size_t tlv5; tlv5 = (cgc_size_t)(r); }
    {int tlv2; tlv2 = (int)(r); }
    {unsigned int tlv8; tlv8 = (unsigned int)(r); }
    {int tlv11; tlv11 = (int)(r); }
    {cgc_size_t tlv9; tlv9 = (cgc_size_t)(r); }
    {unsigned int tlv12; tlv12 = (unsigned int)(r); }
    {int tlv3; tlv3 = (int)(r); }
    {int tlv4; tlv4 = (int)(r); }
    {int tlv15; tlv15 = (int)(r); }
    {cgc_size_t tlv13; tlv13 = (cgc_size_t)(r); }
    {int tlv18; tlv18 = (int)(r); }
    {cgc_size_t tlv16; tlv16 = (cgc_size_t)(r); }
    {unsigned int tlv19; tlv19 = (unsigned int)(r); }
    {unsigned int tlv20; tlv20 = (unsigned int)(r); }
}
void fix_ingred_service_0_8_1(){
int r;
    bzero(&r,sizeof(int));
    {int r; r = (int)(- 1); }
    {int tlv1; tlv1 = (int)(- 1); }
    {int tlv7; tlv7 = (int)(- 1); }
    {cgc_size_t tlv5; tlv5 = (cgc_size_t)(- 1); }
    {int tlv2; tlv2 = (int)(- 1); }
    {unsigned int tlv8; tlv8 = (unsigned int)(- 1); }
    {int tlv11; tlv11 = (int)(- 1); }
    {cgc_size_t tlv9; tlv9 = (cgc_size_t)(- 1); }
    {unsigned int tlv12; tlv12 = (unsigned int)(- 1); }
    {int tlv3; tlv3 = (int)(- 1); }
    {int tlv4; tlv4 = (int)(- 1); }
    {int tlv15; tlv15 = (int)(- 1); }
    {cgc_size_t tlv13; tlv13 = (cgc_size_t)(- 1); }
    {int tlv18; tlv18 = (int)(- 1); }
    {cgc_size_t tlv16; tlv16 = (cgc_size_t)(- 1); }
    {unsigned int tlv19; tlv19 = (unsigned int)(- 1); }
    {unsigned int tlv20; tlv20 = (unsigned int)(- 1); }
}
void fix_ingred_service_0_8(){
fix_ingred_service_0_8_0();
fix_ingred_service_0_8_1();
}
void fix_ingred_service_0_11_1(){
    {int r; r = (int)(sizeof ( NO ) - 1); }
    {int tlv1; tlv1 = (int)(sizeof ( NO ) - 1); }
    {int tlv7; tlv7 = (int)(sizeof ( NO ) - 1); }
    {cgc_size_t tlv5; tlv5 = (cgc_size_t)(sizeof ( NO ) - 1); }
    {int tlv2; tlv2 = (int)(sizeof ( NO ) - 1); }
    {unsigned int tlv8; tlv8 = (unsigned int)(sizeof ( NO ) - 1); }
    {int tlv11; tlv11 = (int)(sizeof ( NO ) - 1); }
    {cgc_size_t tlv9; tlv9 = (cgc_size_t)(sizeof ( NO ) - 1); }
    {unsigned int tlv12; tlv12 = (unsigned int)(sizeof ( NO ) - 1); }
    {int tlv3; tlv3 = (int)(sizeof ( NO ) - 1); }
    {int tlv4; tlv4 = (int)(sizeof ( NO ) - 1); }
    {int tlv15; tlv15 = (int)(sizeof ( NO ) - 1); }
    {cgc_size_t tlv13; tlv13 = (cgc_size_t)(sizeof ( NO ) - 1); }
    {int tlv18; tlv18 = (int)(sizeof ( NO ) - 1); }
    {cgc_size_t tlv16; tlv16 = (cgc_size_t)(sizeof ( NO ) - 1); }
    {unsigned int tlv19; tlv19 = (unsigned int)(sizeof ( NO ) - 1); }
    {unsigned int tlv20; tlv20 = (unsigned int)(sizeof ( NO ) - 1); }
}
void fix_ingred_service_0_11(){
fix_ingred_service_0_11_1();
}
void fix_ingred_service_0_12_2(){
int tlv3;
    bzero(&tlv3,sizeof(int));
    {int r; r = (int)(tlv3); }
    {int tlv1; tlv1 = (int)(tlv3); }
    {int tlv7; tlv7 = (int)(tlv3); }
    {cgc_size_t tlv5; tlv5 = (cgc_size_t)(tlv3); }
    {int tlv2; tlv2 = (int)(tlv3); }
    {unsigned int tlv8; tlv8 = (unsigned int)(tlv3); }
    {int tlv11; tlv11 = (int)(tlv3); }
    {cgc_size_t tlv9; tlv9 = (cgc_size_t)(tlv3); }
    {unsigned int tlv12; tlv12 = (unsigned int)(tlv3); }
    {int tlv4; tlv4 = (int)(tlv3); }
    {int tlv15; tlv15 = (int)(tlv3); }
    {cgc_size_t tlv13; tlv13 = (cgc_size_t)(tlv3); }
    {int tlv18; tlv18 = (int)(tlv3); }
    {cgc_size_t tlv16; tlv16 = (cgc_size_t)(tlv3); }
    {unsigned int tlv19; tlv19 = (unsigned int)(tlv3); }
    {unsigned int tlv20; tlv20 = (unsigned int)(tlv3); }
}
void fix_ingred_service_0_12(){
fix_ingred_service_0_12_2();
}
void fix_ingred_service_0_15_1(){
    {int r; r = (int)(sizeof ( YES ) - 1); }
    {int tlv1; tlv1 = (int)(sizeof ( YES ) - 1); }
    {int tlv7; tlv7 = (int)(sizeof ( YES ) - 1); }
    {cgc_size_t tlv5; tlv5 = (cgc_size_t)(sizeof ( YES ) - 1); }
    {int tlv2; tlv2 = (int)(sizeof ( YES ) - 1); }
    {unsigned int tlv8; tlv8 = (unsigned int)(sizeof ( YES ) - 1); }
    {int tlv11; tlv11 = (int)(sizeof ( YES ) - 1); }
    {cgc_size_t tlv9; tlv9 = (cgc_size_t)(sizeof ( YES ) - 1); }
    {unsigned int tlv12; tlv12 = (unsigned int)(sizeof ( YES ) - 1); }
    {int tlv3; tlv3 = (int)(sizeof ( YES ) - 1); }
    {int tlv4; tlv4 = (int)(sizeof ( YES ) - 1); }
    {int tlv15; tlv15 = (int)(sizeof ( YES ) - 1); }
    {cgc_size_t tlv13; tlv13 = (cgc_size_t)(sizeof ( YES ) - 1); }
    {int tlv18; tlv18 = (int)(sizeof ( YES ) - 1); }
    {cgc_size_t tlv16; tlv16 = (cgc_size_t)(sizeof ( YES ) - 1); }
    {unsigned int tlv19; tlv19 = (unsigned int)(sizeof ( YES ) - 1); }
    {unsigned int tlv20; tlv20 = (unsigned int)(sizeof ( YES ) - 1); }
}
void fix_ingred_service_0_15(){
fix_ingred_service_0_15_1();
}
void fix_ingred_service_0_16_0(){
int tlv4;
    bzero(&tlv4,sizeof(int));
    {int r; r = (int)(tlv4); }
    {int tlv1; tlv1 = (int)(tlv4); }
    {int tlv7; tlv7 = (int)(tlv4); }
    {cgc_size_t tlv5; tlv5 = (cgc_size_t)(tlv4); }
    {int tlv2; tlv2 = (int)(tlv4); }
    {unsigned int tlv8; tlv8 = (unsigned int)(tlv4); }
    {int tlv11; tlv11 = (int)(tlv4); }
    {cgc_size_t tlv9; tlv9 = (cgc_size_t)(tlv4); }
    {unsigned int tlv12; tlv12 = (unsigned int)(tlv4); }
    {int tlv3; tlv3 = (int)(tlv4); }
    {int tlv15; tlv15 = (int)(tlv4); }
    {cgc_size_t tlv13; tlv13 = (cgc_size_t)(tlv4); }
    {int tlv18; tlv18 = (int)(tlv4); }
    {cgc_size_t tlv16; tlv16 = (cgc_size_t)(tlv4); }
    {unsigned int tlv19; tlv19 = (unsigned int)(tlv4); }
    {unsigned int tlv20; tlv20 = (unsigned int)(tlv4); }
}
void fix_ingred_service_0_16(){
fix_ingred_service_0_16_0();
}
void fix_ingred_service_0(){
fix_ingred_service_0_1();
fix_ingred_service_0_2();
fix_ingred_service_0_3();
fix_ingred_service_0_5();
fix_ingred_service_0_6();
fix_ingred_service_0_8();
fix_ingred_service_0_11();
fix_ingred_service_0_12();
fix_ingred_service_0_15();
fix_ingred_service_0_16();
}
void fix_ingred_service_1_0_0(){
char string [ 64 ];
    bzero(&string,( 64 *sizeof(char) ) );
int len;
    bzero(&len,sizeof(int));
    {int len; len = (int)(- 1); }
    {int i; i = (int)(- 1); }
    {int pal; pal = (int)(- 1); }
    {char string [ 64 ]; string [ ( 64 )-1 ] = (char)(- 1); }
    {unsigned long tlv_size_0; tlv_size_0 = (unsigned long)(- 1); }
    {int steps; steps = (int)(- 1); }
    {int tlv6; tlv6 = (int)(- 1); }
    {char * tlv5; tlv5 = (char *)(- 1); }
    {cgc_size_t tlv4; tlv4 = (cgc_size_t)(- 1); }
    {char tlv3; tlv3 = (char)(- 1); }
    {int tlv9; tlv9 = (int)(- 1); }
    {cgc_size_t tlv7; tlv7 = (cgc_size_t)(- 1); }
    {unsigned int tlv10; tlv10 = (unsigned int)(- 1); }
}
void fix_ingred_service_1_0_1(){
char string [ 64 ];
    bzero(&string,( 64 *sizeof(char) ) );
int len;
    bzero(&len,sizeof(int));
    {int len; len = (int)(1); }
    {int i; i = (int)(1); }
    {int pal; pal = (int)(1); }
    {char string [ 64 ]; string [ ( 64 )-1 ] = (char)(1); }
    {unsigned long tlv_size_0; tlv_size_0 = (unsigned long)(1); }
    {int steps; steps = (int)(1); }
    {int tlv6; tlv6 = (int)(1); }
    {char * tlv5; tlv5 = (char *)(1); }
    {cgc_size_t tlv4; tlv4 = (cgc_size_t)(1); }
    {char tlv3; tlv3 = (char)(1); }
    {int tlv9; tlv9 = (int)(1); }
    {cgc_size_t tlv7; tlv7 = (cgc_size_t)(1); }
    {unsigned int tlv10; tlv10 = (unsigned int)(1); }
}
void fix_ingred_service_1_0_2(){
char string [ 64 ];
    bzero(&string,( 64 *sizeof(char) ) );
int len;
    bzero(&len,sizeof(int));
    {int len; len = (int)(sizeof ( string )); }
    {int i; i = (int)(sizeof ( string )); }
    {int pal; pal = (int)(sizeof ( string )); }
    {char string [ 64 ]; string [ ( 64 )-1 ] = (char)(sizeof ( string )); }
    {unsigned long tlv_size_0; tlv_size_0 = (unsigned long)(sizeof ( string )); }
    {int tlv1; tlv1 = (int)(sizeof ( string )); }
    {int steps; steps = (int)(sizeof ( string )); }
    {int tlv6; tlv6 = (int)(sizeof ( string )); }
    {char * tlv5; tlv5 = (char *)(sizeof ( string )); }
    {cgc_size_t tlv4; tlv4 = (cgc_size_t)(sizeof ( string )); }
    {char tlv3; tlv3 = (char)(sizeof ( string )); }
    {int tlv2; tlv2 = (int)(sizeof ( string )); }
    {int tlv9; tlv9 = (int)(sizeof ( string )); }
    {cgc_size_t tlv7; tlv7 = (cgc_size_t)(sizeof ( string )); }
    {unsigned int tlv10; tlv10 = (unsigned int)(sizeof ( string )); }
}
void fix_ingred_service_1_0_3(){
char string [ 64 ];
    bzero(&string,( 64 *sizeof(char) ) );
int len;
    bzero(&len,sizeof(int));
    {int i; i = (int)(len); }
    {int pal; pal = (int)(len); }
    {char string [ 64 ]; string [ ( 64 )-1 ] = (char)(len); }
    {unsigned long tlv_size_0; tlv_size_0 = (unsigned long)(len); }
    {int tlv1; tlv1 = (int)(len); }
    {int steps; steps = (int)(len); }
    {int tlv6; tlv6 = (int)(len); }
    {char * tlv5; tlv5 = (char *)(len); }
    {cgc_size_t tlv4; tlv4 = (cgc_size_t)(len); }
    {char tlv3; tlv3 = (char)(len); }
    {int tlv2; tlv2 = (int)(len); }
    {int tlv9; tlv9 = (int)(len); }
    {cgc_size_t tlv7; tlv7 = (cgc_size_t)(len); }
    {unsigned int tlv10; tlv10 = (unsigned int)(len); }
}
void fix_ingred_service_1_0(){
fix_ingred_service_1_0_0();
fix_ingred_service_1_0_1();
fix_ingred_service_1_0_2();
fix_ingred_service_1_0_3();
}
void fix_ingred_service_1_1_4(){
int i;
    bzero(&i,sizeof(int));
unsigned long tlv_size_0;
    bzero(&tlv_size_0,sizeof(unsigned long));
    {int len; len = (int)(0); }
    {int i; i = (int)(0); }
    {int pal; pal = (int)(0); }
    {char string [ 64 ]; string [ ( 64 )-1 ] = (char)(0); }
    {unsigned long tlv_size_0; tlv_size_0 = (unsigned long)(0); }
    {int steps; steps = (int)(0); }
    {int tlv6; tlv6 = (int)(0); }
    {char * tlv5; tlv5 = (char *)(0); }
    {cgc_size_t tlv4; tlv4 = (cgc_size_t)(0); }
    {char tlv3; tlv3 = (char)(0); }
    {int tlv9; tlv9 = (int)(0); }
    {cgc_size_t tlv7; tlv7 = (cgc_size_t)(0); }
    {unsigned int tlv10; tlv10 = (unsigned int)(0); }
}
void fix_ingred_service_1_1_5(){
int i;
    bzero(&i,sizeof(int));
unsigned long tlv_size_0;
    bzero(&tlv_size_0,sizeof(unsigned long));
    {int len; len = (int)(i); }
    {int pal; pal = (int)(i); }
    {char string [ 64 ]; string [ ( 64 )-1 ] = (char)(i); }
    {unsigned long tlv_size_0; tlv_size_0 = (unsigned long)(i); }
    {int tlv1; tlv1 = (int)(i); }
    {int steps; steps = (int)(i); }
    {int tlv6; tlv6 = (int)(i); }
    {char * tlv5; tlv5 = (char *)(i); }
    {cgc_size_t tlv4; tlv4 = (cgc_size_t)(i); }
    {char tlv3; tlv3 = (char)(i); }
    {int tlv2; tlv2 = (int)(i); }
    {int tlv9; tlv9 = (int)(i); }
    {cgc_size_t tlv7; tlv7 = (cgc_size_t)(i); }
    {unsigned int tlv10; tlv10 = (unsigned int)(i); }
}
void fix_ingred_service_1_1_6(){
int i;
    bzero(&i,sizeof(int));
unsigned long tlv_size_0;
    bzero(&tlv_size_0,sizeof(unsigned long));
    {int len; len = (int)(tlv_size_0); }
    {int i; i = (int)(tlv_size_0); }
    {int pal; pal = (int)(tlv_size_0); }
    {char string [ 64 ]; string [ ( 64 )-1 ] = (char)(tlv_size_0); }
    {int tlv1; tlv1 = (int)(tlv_size_0); }
    {int steps; steps = (int)(tlv_size_0); }
    {int tlv6; tlv6 = (int)(tlv_size_0); }
    {char * tlv5; tlv5 = (char *)(tlv_size_0); }
    {cgc_size_t tlv4; tlv4 = (cgc_size_t)(tlv_size_0); }
    {char tlv3; tlv3 = (char)(tlv_size_0); }
    {int tlv2; tlv2 = (int)(tlv_size_0); }
    {int tlv9; tlv9 = (int)(tlv_size_0); }
    {cgc_size_t tlv7; tlv7 = (cgc_size_t)(tlv_size_0); }
    {unsigned int tlv10; tlv10 = (unsigned int)(tlv_size_0); }
}
void fix_ingred_service_1_1(){
fix_ingred_service_1_1_4();
fix_ingred_service_1_1_5();
fix_ingred_service_1_1_6();
}
void fix_ingred_service_1_2_1(){
char string [ 64 ];
    bzero(&string,( 64 *sizeof(char) ) );
    {int len; len = (int)(string); }
    {int i; i = (int)(string); }
    {int pal; pal = (int)(string); }
    {char string [ 64 ]; string [ ( 64 )-1 ] = (char)(string); }
    {unsigned long tlv_size_0; tlv_size_0 = (unsigned long)(string); }
    {int tlv1; tlv1 = (int)(string); }
    {int steps; steps = (int)(string); }
    {int tlv6; tlv6 = (int)(string); }
    {char * tlv5; tlv5 = (char *)(string); }
    {cgc_size_t tlv4; tlv4 = (cgc_size_t)(string); }
    {char tlv3; tlv3 = (char)(string); }
    {int tlv2; tlv2 = (int)(string); }
    {int tlv9; tlv9 = (int)(string); }
    {cgc_size_t tlv7; tlv7 = (cgc_size_t)(string); }
    {unsigned int tlv10; tlv10 = (unsigned int)(string); }
}
void fix_ingred_service_1_2_2(){
char string [ 64 ];
    bzero(&string,( 64 *sizeof(char) ) );
    {int len; len = (int)(128); }
    {int i; i = (int)(128); }
    {int pal; pal = (int)(128); }
    {char string [ 64 ]; string [ ( 64 )-1 ] = (char)(128); }
    {unsigned long tlv_size_0; tlv_size_0 = (unsigned long)(128); }
    {int tlv1; tlv1 = (int)(128); }
    {int steps; steps = (int)(128); }
    {int tlv6; tlv6 = (int)(128); }
    {char * tlv5; tlv5 = (char *)(128); }
    {cgc_size_t tlv4; tlv4 = (cgc_size_t)(128); }
    {char tlv3; tlv3 = (char)(128); }
    {int tlv2; tlv2 = (int)(128); }
    {int tlv9; tlv9 = (int)(128); }
    {cgc_size_t tlv7; tlv7 = (cgc_size_t)(128); }
    {unsigned int tlv10; tlv10 = (unsigned int)(128); }
}
void fix_ingred_service_1_2_3(){
char string [ 64 ];
    bzero(&string,( 64 *sizeof(char) ) );
    {int len; len = (int)('\n'); }
    {int i; i = (int)('\n'); }
    {int pal; pal = (int)('\n'); }
    {char string [ 64 ]; string [ ( 64 )-1 ] = (char)('\n'); }
    {unsigned long tlv_size_0; tlv_size_0 = (unsigned long)('\n'); }
    {int tlv1; tlv1 = (int)('\n'); }
    {int steps; steps = (int)('\n'); }
    {int tlv6; tlv6 = (int)('\n'); }
    {char * tlv5; tlv5 = (char *)('\n'); }
    {cgc_size_t tlv4; tlv4 = (cgc_size_t)('\n'); }
    {char tlv3; tlv3 = (char)('\n'); }
    {int tlv2; tlv2 = (int)('\n'); }
    {int tlv9; tlv9 = (int)('\n'); }
    {cgc_size_t tlv7; tlv7 = (cgc_size_t)('\n'); }
    {unsigned int tlv10; tlv10 = (unsigned int)('\n'); }
}
void fix_ingred_service_1_2(){
fix_ingred_service_1_2_1();
fix_ingred_service_1_2_2();
fix_ingred_service_1_2_3();
}
void fix_ingred_service_1_3_3(){
int tlv1;
    bzero(&tlv1,sizeof(int));
    {int len; len = (int)(tlv1); }
    {int i; i = (int)(tlv1); }
    {int pal; pal = (int)(tlv1); }
    {char string [ 64 ]; string [ ( 64 )-1 ] = (char)(tlv1); }
    {unsigned long tlv_size_0; tlv_size_0 = (unsigned long)(tlv1); }
    {int steps; steps = (int)(tlv1); }
    {int tlv6; tlv6 = (int)(tlv1); }
    {char * tlv5; tlv5 = (char *)(tlv1); }
    {cgc_size_t tlv4; tlv4 = (cgc_size_t)(tlv1); }
    {char tlv3; tlv3 = (char)(tlv1); }
    {int tlv9; tlv9 = (int)(tlv1); }
    {cgc_size_t tlv7; tlv7 = (cgc_size_t)(tlv1); }
    {unsigned int tlv10; tlv10 = (unsigned int)(tlv1); }
}
void fix_ingred_service_1_3(){
fix_ingred_service_1_3_3();
}
void fix_ingred_service_1_4_4(){
char string [ 64 ];
    bzero(&string,( 64 *sizeof(char) ) );
int i;
    bzero(&i,sizeof(int));
    {if (string){    i = 0;
         int len; len = (int)(string [ i ]); }}
    {if (string){    i = 0;
         int pal; pal = (int)(string [ i ]); }}
    {if (string){    i = 0;
         char string [ 64 ]; string [ ( 64 )-1 ] = (char)(string [ i ]); }}
    {if (string){    i = 0;
         unsigned long tlv_size_0; tlv_size_0 = (unsigned long)(string [ i ]); }}
    {if (string){    i = 0;
         int tlv1; tlv1 = (int)(string [ i ]); }}
    {if (string){    i = 0;
         int steps; steps = (int)(string [ i ]); }}
    {if (string){    i = 0;
         int tlv6; tlv6 = (int)(string [ i ]); }}
    {if (string){    i = 0;
         char * tlv5; tlv5 = (char *)(string [ i ]); }}
    {if (string){    i = 0;
         cgc_size_t tlv4; tlv4 = (cgc_size_t)(string [ i ]); }}
    {if (string){    i = 0;
         char tlv3; tlv3 = (char)(string [ i ]); }}
    {if (string){    i = 0;
         int tlv2; tlv2 = (int)(string [ i ]); }}
    {if (string){    i = 0;
         int tlv9; tlv9 = (int)(string [ i ]); }}
    {if (string){    i = 0;
         cgc_size_t tlv7; tlv7 = (cgc_size_t)(string [ i ]); }}
    {if (string){    i = 0;
         unsigned int tlv10; tlv10 = (unsigned int)(string [ i ]); }}
}
void fix_ingred_service_1_4_5(){
char string [ 64 ];
    bzero(&string,( 64 *sizeof(char) ) );
int i;
    bzero(&i,sizeof(int));
    {int len; len = (int)('\0'); }
    {int i; i = (int)('\0'); }
    {int pal; pal = (int)('\0'); }
    {char string [ 64 ]; string [ ( 64 )-1 ] = (char)('\0'); }
    {unsigned long tlv_size_0; tlv_size_0 = (unsigned long)('\0'); }
    {int tlv1; tlv1 = (int)('\0'); }
    {int steps; steps = (int)('\0'); }
    {int tlv6; tlv6 = (int)('\0'); }
    {char * tlv5; tlv5 = (char *)('\0'); }
    {cgc_size_t tlv4; tlv4 = (cgc_size_t)('\0'); }
    {char tlv3; tlv3 = (char)('\0'); }
    {int tlv2; tlv2 = (int)('\0'); }
    {int tlv9; tlv9 = (int)('\0'); }
    {cgc_size_t tlv7; tlv7 = (cgc_size_t)('\0'); }
    {unsigned int tlv10; tlv10 = (unsigned int)('\0'); }
}
void fix_ingred_service_1_4(){
fix_ingred_service_1_4_4();
fix_ingred_service_1_4_5();
}
void fix_ingred_service_1_8_4(){
char string [ 64 ];
    bzero(&string,( 64 *sizeof(char) ) );
    {if (string){int len; len = (int)(string [ 0 ]); }}
    {if (string){int i; i = (int)(string [ 0 ]); }}
    {if (string){int pal; pal = (int)(string [ 0 ]); }}
    {if (string){char string [ 64 ]; string [ ( 64 )-1 ] = (char)(string [ 0 ]); }}
    {if (string){unsigned long tlv_size_0; tlv_size_0 = (unsigned long)(string [ 0 ]); }}
    {if (string){int tlv1; tlv1 = (int)(string [ 0 ]); }}
    {if (string){int steps; steps = (int)(string [ 0 ]); }}
    {if (string){int tlv6; tlv6 = (int)(string [ 0 ]); }}
    {if (string){char * tlv5; tlv5 = (char *)(string [ 0 ]); }}
    {if (string){cgc_size_t tlv4; tlv4 = (cgc_size_t)(string [ 0 ]); }}
    {if (string){char tlv3; tlv3 = (char)(string [ 0 ]); }}
    {if (string){int tlv2; tlv2 = (int)(string [ 0 ]); }}
    {if (string){int tlv9; tlv9 = (int)(string [ 0 ]); }}
    {if (string){cgc_size_t tlv7; tlv7 = (cgc_size_t)(string [ 0 ]); }}
    {if (string){unsigned int tlv10; tlv10 = (unsigned int)(string [ 0 ]); }}
}
void fix_ingred_service_1_8_5(){
char string [ 64 ];
    bzero(&string,( 64 *sizeof(char) ) );
    {int len; len = (int)('^'); }
    {int i; i = (int)('^'); }
    {int pal; pal = (int)('^'); }
    {char string [ 64 ]; string [ ( 64 )-1 ] = (char)('^'); }
    {unsigned long tlv_size_0; tlv_size_0 = (unsigned long)('^'); }
    {int tlv1; tlv1 = (int)('^'); }
    {int steps; steps = (int)('^'); }
    {int tlv6; tlv6 = (int)('^'); }
    {char * tlv5; tlv5 = (char *)('^'); }
    {cgc_size_t tlv4; tlv4 = (cgc_size_t)('^'); }
    {char tlv3; tlv3 = (char)('^'); }
    {int tlv2; tlv2 = (int)('^'); }
    {int tlv9; tlv9 = (int)('^'); }
    {cgc_size_t tlv7; tlv7 = (cgc_size_t)('^'); }
    {unsigned int tlv10; tlv10 = (unsigned int)('^'); }
}
void fix_ingred_service_1_8(){
fix_ingred_service_1_8_4();
fix_ingred_service_1_8_5();
}
void fix_ingred_service_1_9_1(){
    {int len; len = (int)(sizeof ( EASTEREGG ) - 1); }
    {int i; i = (int)(sizeof ( EASTEREGG ) - 1); }
    {int pal; pal = (int)(sizeof ( EASTEREGG ) - 1); }
    {char string [ 64 ]; string [ ( 64 )-1 ] = (char)(sizeof ( EASTEREGG ) - 1); }
    {unsigned long tlv_size_0; tlv_size_0 = (unsigned long)(sizeof ( EASTEREGG ) - 1); }
    {int tlv1; tlv1 = (int)(sizeof ( EASTEREGG ) - 1); }
    {int steps; steps = (int)(sizeof ( EASTEREGG ) - 1); }
    {int tlv6; tlv6 = (int)(sizeof ( EASTEREGG ) - 1); }
    {char * tlv5; tlv5 = (char *)(sizeof ( EASTEREGG ) - 1); }
    {cgc_size_t tlv4; tlv4 = (cgc_size_t)(sizeof ( EASTEREGG ) - 1); }
    {char tlv3; tlv3 = (char)(sizeof ( EASTEREGG ) - 1); }
    {int tlv2; tlv2 = (int)(sizeof ( EASTEREGG ) - 1); }
    {int tlv9; tlv9 = (int)(sizeof ( EASTEREGG ) - 1); }
    {cgc_size_t tlv7; tlv7 = (cgc_size_t)(sizeof ( EASTEREGG ) - 1); }
    {unsigned int tlv10; tlv10 = (unsigned int)(sizeof ( EASTEREGG ) - 1); }
}
void fix_ingred_service_1_9(){
fix_ingred_service_1_9_1();
}
void fix_ingred_service_1_10_6(){
int tlv2;
    bzero(&tlv2,sizeof(int));
    {int len; len = (int)(tlv2); }
    {int i; i = (int)(tlv2); }
    {int pal; pal = (int)(tlv2); }
    {char string [ 64 ]; string [ ( 64 )-1 ] = (char)(tlv2); }
    {unsigned long tlv_size_0; tlv_size_0 = (unsigned long)(tlv2); }
    {int steps; steps = (int)(tlv2); }
    {int tlv6; tlv6 = (int)(tlv2); }
    {char * tlv5; tlv5 = (char *)(tlv2); }
    {cgc_size_t tlv4; tlv4 = (cgc_size_t)(tlv2); }
    {char tlv3; tlv3 = (char)(tlv2); }
    {int tlv9; tlv9 = (int)(tlv2); }
    {cgc_size_t tlv7; tlv7 = (cgc_size_t)(tlv2); }
    {unsigned int tlv10; tlv10 = (unsigned int)(tlv2); }
}
void fix_ingred_service_1_10(){
fix_ingred_service_1_10_6();
}
void fix_ingred_service_1_11_0(){
    {int len; len = (int)(0); }
    {int i; i = (int)(0); }
    {int pal; pal = (int)(0); }
    {char string [ 64 ]; string [ ( 64 )-1 ] = (char)(0); }
    {unsigned long tlv_size_0; tlv_size_0 = (unsigned long)(0); }
    {int steps; steps = (int)(0); }
    {int tlv6; tlv6 = (int)(0); }
    {char * tlv5; tlv5 = (char *)(0); }
    {cgc_size_t tlv4; tlv4 = (cgc_size_t)(0); }
    {char tlv3; tlv3 = (char)(0); }
    {int tlv9; tlv9 = (int)(0); }
    {cgc_size_t tlv7; tlv7 = (cgc_size_t)(0); }
    {unsigned int tlv10; tlv10 = (unsigned int)(0); }
}
void fix_ingred_service_1_11(){
fix_ingred_service_1_11_0();
}
void fix_ingred_service_1(){
fix_ingred_service_1_0();
fix_ingred_service_1_1();
fix_ingred_service_1_2();
fix_ingred_service_1_3();
fix_ingred_service_1_4();
fix_ingred_service_1_8();
fix_ingred_service_1_9();
fix_ingred_service_1_10();
fix_ingred_service_1_11();
}
