

#include "libcgc.h"
#include "cgc_stdarg.h"
#include "cgc_stdlib.h"
#include "cgc_string.h"
#include "cgc_ctype.h"
#include "cgc_kty.h"
#define MAX_KTY_LENGTH 8192
kty_parser_t *parser;
kty_item_t *my_kty;
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

void fix_ingred_main_0_0_0();
void fix_ingred_main_0_0();
void fix_ingred_main_0_1_1();
void fix_ingred_main_0_1_2();
void fix_ingred_main_0_1_3();
void fix_ingred_main_0_1();
void fix_ingred_main_0_2_0();
void fix_ingred_main_0_2_1();
void fix_ingred_main_0_2_2();
void fix_ingred_main_0_2();
void fix_ingred_main_0_3_4();
void fix_ingred_main_0_3_5();
void fix_ingred_main_0_3_6();
void fix_ingred_main_0_3();
void fix_ingred_main_0_4_4();
void fix_ingred_main_0_4_5();
void fix_ingred_main_0_4();
void fix_ingred_main_0();
int cgc_read_until(int fd, char *buf, cgc_size_t len, char delim)
{
if (fix_ingred_enable){ fix_ingred_main_0(); };
    cgc_size_t i;
    char* c;
     c = buf;
    for (i = 0; i < len; ++i) {
	cgc_size_t rx;
 int tlv1;
 {
     int tlv5;
     tlv5 = fd;
     void* tlv4;
     tlv4 = c;
     cgc_size_t tlv3;
     tlv3 = 1;
     cgc_size_t* tlv2;
     tlv2 = & rx;
     tlv1 = cgc_receive(tlv5,tlv4,tlv3,tlv2);
 }
	if (tlv1 != 0 || rx == 0) {
	    return -1;
	}
	if (*(c++) == delim) {
	    break;
	}
    }
    *(c - 1) = '\0';
    return c - buf;
}

void fix_ingred_main_1_3_0();
void fix_ingred_main_1_3();
void fix_ingred_main_1();
void cgc_import_kty(char *buf)
{
if (fix_ingred_enable){ fix_ingred_main_1(); };
    if (my_kty != NULL) {
	cgc_free_kty_item(my_kty);
	my_kty = NULL;
    }
    parser->cats = 0;
    my_kty = parser->loads(buf);
    if (my_kty == NULL) {
 {
     int tlv2;
     tlv2 = STDOUT;
     const char tlv1 [ ] = "Error!\n";
    	cgc_fdprintf(tlv2,tlv1);
 }
    }
}

void fix_ingred_main_2();
void cgc_print_kty()
{
if (fix_ingred_enable){ fix_ingred_main_2(); };
    if (my_kty == NULL) {
 {
     int tlv2;
     tlv2 = STDOUT;
     const char tlv1 [ ] = "Error!\n";
    	cgc_fdprintf(tlv2,tlv1);
 }
	return;
    }
    parser->cats = 0;
    parser->dumps(my_kty);
}

void fix_ingred_main_3_0_0();
void fix_ingred_main_3_0();
void fix_ingred_main_3_2_0();
void fix_ingred_main_3_2();
void fix_ingred_main_3_4_2();
void fix_ingred_main_3_4_3();
void fix_ingred_main_3_4();
void fix_ingred_main_3_6_0();
void fix_ingred_main_3_6();
void fix_ingred_main_3();
void cgc_nyan()
{
if (fix_ingred_enable){ fix_ingred_main_3(); };
    int i;
    char *c;
    char buf[1024] = { 0 };
    char nyan_cat[] = "\n\n\
+      o     +              o\n\
    +             o     +       +\n\
o          +\n\
    o  +           +        +\n\
+        o     o       +        o\n\
-_-_-_-_-_-_-_,------,      o\n\
_-_-_-_-_-_-_-|   /\\_/\\\n\
-_-_-_-_-_-_-~|__( ^ .^)  +     +\n\
_-_-_-_-_-_-_-\"\"  \"\"\n\
+      o         o   +       o\n\
    +         +\n\
o        o         o      o     +\n\
    o           +\n\
+      +     o        o      +\n\n";
    if (my_kty == NULL) {
 {
     int tlv2;
     tlv2 = STDOUT;
     const char tlv1 [ ] = "Error!\n";
    	cgc_fdprintf(tlv2,tlv1);
 }
	return;
    }
    parser->dumps(my_kty);
    if (parser->cats < 3) {
	return;
    }
    cgc_fdprintf(STDOUT, "%s", nyan_cat);
    c = buf;
    for (i = 0; i < cgc_array_length(parser->nyan_says); ++i) {
 kty_item_t* item;
 {
     array_t* tlv6;
     tlv6 = parser -> nyan_says;
     int tlv5;
     tlv5 = i;
     item = cgc_array_get(tlv6,tlv5);
 }
 {
     char* tlv4;
      tlv4 = c;
     const char* tlv3 = item -> item . i_string . s;
    	cgc_strcpy(tlv4,tlv3);
 }
	c += item->item.i_string.len;
    }
    cgc_fdprintf(STDOUT, "NYAN SAYS...\n\"\n%s\n\"", buf);
}

void fix_ingred_main_4();
void cgc_quit()
{
if (fix_ingred_enable){ fix_ingred_main_4(); };
    {
        int tlv2;
        tlv2 = STDOUT;
        const char tlv1 [ ] = "\n\n=^.^=// Bye!\n\n";
        cgc_fdprintf(tlv2,tlv1);
    }
    cgc_exit(0);
}

void fix_ingred_main_5_1_0();
void fix_ingred_main_5_1();
void fix_ingred_main_5();
void cgc_menu()
{
if (fix_ingred_enable){ fix_ingred_main_5(); };
    {
        int tlv2;
        tlv2 = STDOUT;
        const char tlv1 [ ] = "=======================\n";
        cgc_fdprintf(tlv2,tlv1);
    }
    {
        int tlv4;
        tlv4 = STDOUT;
        const char tlv3 [ ] = " 1. Import KTY\n";
        cgc_fdprintf(tlv4,tlv3);
    }
    {
        int tlv6;
        tlv6 = STDOUT;
        const char tlv5 [ ] = " 2. Print KTY\n";
        cgc_fdprintf(tlv6,tlv5);
    }
    {
        int tlv8;
        tlv8 = STDOUT;
        const char tlv7 [ ] = " 3. Quit\n";
        cgc_fdprintf(tlv8,tlv7);
    }
    {
        int tlv10;
        tlv10 = STDOUT;
        const char tlv9 [ ] = "=======================\n";
        cgc_fdprintf(tlv10,tlv9);
    }
}

void fix_ingred_main_6_0_0();
void fix_ingred_main_6_0();
void fix_ingred_main_6_1_0();
void fix_ingred_main_6_1();
void fix_ingred_main_6_2_0();
void fix_ingred_main_6_2();
void fix_ingred_main_6_4_0();
void fix_ingred_main_6_4_1();
void fix_ingred_main_6_4();
void fix_ingred_main_6_7_1();
void fix_ingred_main_6_7();
void fix_ingred_main_6_10_0();
void fix_ingred_main_6_10_1();
void fix_ingred_main_6_10_2();
void fix_ingred_main_6_10_3();
void fix_ingred_main_6_10();
void fix_ingred_main_6_11_2();
void fix_ingred_main_6_11();
void fix_ingred_main_6();
int main(int cgc_argc, char *cgc_argv[])
{
if (fix_ingred_enable){ fix_ingred_main_6(); };
    char buf[MAX_KTY_LENGTH];
    char cgc_select[16];
    {
        int tlv4;
        tlv4 = STDOUT;
        const char tlv3 [ ] = "KTY Pretty Printer v0.1\n";
        cgc_fdprintf(tlv4,tlv3);
    }
    {
        cgc_size_t tlv6;
        tlv6 = sizeof ( kty_parser_t );
        parser = (kty_parser_t *) cgc_malloc(tlv6);
    }
    int tlv1;
    {
        kty_parser_t* tlv5;
        tlv5 = parser;
        tlv1 = cgc_kty_init(tlv5);
    }
    if (tlv1 != 0) {
 {
     int tlv8;
     tlv8 = STDOUT;
     const char tlv7 [ ] = "Error!\n";
    	cgc_fdprintf(tlv8,tlv7);
 }
	cgc_quit();
    }
    cgc_menu();
    unsigned long tlv_size_0;
    tlv_size_0 = sizeof ( cgc_select );
    while (cgc_read_until(STDIN, cgc_select, tlv_size_0, '\n') > 0) {
 int menu;
 {
     const char* tlv11 = cgc_select;
     char** tlv10;
      tlv10 = NULL;
     int tlv9;
     tlv9 = 10;
     menu = cgc_strtol(tlv11,tlv10,tlv9);
 }
	switch (menu) {
	case 1:
	    {
  int tlv2;
  {
      int tlv17;
      tlv17 = STDIN;
      char* tlv16;
       tlv16 = buf;
      cgc_size_t tlv15;
      tlv15 = MAX_KTY_LENGTH;
      char tlv14;
      tlv14 = '\x00';
      tlv2 = cgc_read_until(tlv17,tlv16,tlv15,tlv14);
  }
		if (tlv2 > 0) {
		    cgc_import_kty(buf);
		} else {
      {
          int tlv19;
          tlv19 = STDOUT;
          const char tlv18 [ ] = "Error!\n";
    		    cgc_fdprintf(tlv19,tlv18);
      }
		}
	    }
	    break;
	case 2:
	    {
		cgc_print_kty();
	    }
	    break;
	case 3:
	    {
		cgc_quit();
	    }
	    break;
	case 777:
	    {
		cgc_nyan();
	    }
	    break;
	default:
	    {
  {
      int tlv13;
      tlv13 = STDOUT;
      const char tlv12 [ ] = "Invalid menu. Try again.\n";
    		cgc_fdprintf(tlv13,tlv12);
  }
	    }
	    break;
	}
    }
    return 0;
}

void fix_ingred_main_0_0_0(){
char buf_ref;
    bzero(&buf_ref,1*sizeof(char));
char * buf = &buf_ref;
    {cgc_size_t i; i = (cgc_size_t)(buf); }
    {char * c; c = (char *)(buf); }
    {cgc_size_t rx; rx = (cgc_size_t)(buf); }
    {int tlv1; tlv1 = (int)(buf); }
    {int tlv5; tlv5 = (int)(buf); }
    {void * tlv4; tlv4 = (void *)(buf); }
    {cgc_size_t tlv3; tlv3 = (cgc_size_t)(buf); }
}
void fix_ingred_main_0_0(){
fix_ingred_main_0_0_0();
}
void fix_ingred_main_0_1_1(){
cgc_size_t i;
    bzero(&i,sizeof(cgc_size_t));
cgc_size_t len;
    bzero(&len,sizeof(cgc_size_t));
    {cgc_size_t i; i = (cgc_size_t)(0); }
    {char * c; c = (char *)(0); }
    {cgc_size_t rx; rx = (cgc_size_t)(0); }
    {int tlv1; tlv1 = (int)(0); }
    {int tlv5; tlv5 = (int)(0); }
    {void * tlv4; tlv4 = (void *)(0); }
    {cgc_size_t tlv3; tlv3 = (cgc_size_t)(0); }
}
void fix_ingred_main_0_1_2(){
cgc_size_t i;
    bzero(&i,sizeof(cgc_size_t));
cgc_size_t len;
    bzero(&len,sizeof(cgc_size_t));
    {char * c; c = (char *)(i); }
    {cgc_size_t rx; rx = (cgc_size_t)(i); }
    {int tlv1; tlv1 = (int)(i); }
    {int tlv5; tlv5 = (int)(i); }
    {void * tlv4; tlv4 = (void *)(i); }
    {cgc_size_t tlv3; tlv3 = (cgc_size_t)(i); }
}
void fix_ingred_main_0_1_3(){
cgc_size_t i;
    bzero(&i,sizeof(cgc_size_t));
cgc_size_t len;
    bzero(&len,sizeof(cgc_size_t));
    {cgc_size_t i; i = (cgc_size_t)(len); }
    {char * c; c = (char *)(len); }
    {cgc_size_t rx; rx = (cgc_size_t)(len); }
    {int tlv1; tlv1 = (int)(len); }
    {int tlv5; tlv5 = (int)(len); }
    {void * tlv4; tlv4 = (void *)(len); }
    {cgc_size_t tlv3; tlv3 = (cgc_size_t)(len); }
}
void fix_ingred_main_0_1(){
fix_ingred_main_0_1_1();
fix_ingred_main_0_1_2();
fix_ingred_main_0_1_3();
}
void fix_ingred_main_0_2_0(){
int fd;
    bzero(&fd,sizeof(int));
char c_ref;
    bzero(&c_ref,1*sizeof(char));
char * c = &c_ref;
    {cgc_size_t i; i = (cgc_size_t)(fd); }
    {char * c; c = (char *)(fd); }
    {cgc_size_t rx; rx = (cgc_size_t)(fd); }
    {int tlv1; tlv1 = (int)(fd); }
    {int tlv5; tlv5 = (int)(fd); }
    {void * tlv4; tlv4 = (void *)(fd); }
    {cgc_size_t tlv3; tlv3 = (cgc_size_t)(fd); }
}
void fix_ingred_main_0_2_1(){
int fd;
    bzero(&fd,sizeof(int));
char c_ref;
    bzero(&c_ref,1*sizeof(char));
char * c = &c_ref;
    {cgc_size_t i; i = (cgc_size_t)(c); }
    {cgc_size_t rx; rx = (cgc_size_t)(c); }
    {int tlv1; tlv1 = (int)(c); }
    {int tlv5; tlv5 = (int)(c); }
    {void * tlv4; tlv4 = (void *)(c); }
    {cgc_size_t tlv3; tlv3 = (cgc_size_t)(c); }
}
void fix_ingred_main_0_2_2(){
int fd;
    bzero(&fd,sizeof(int));
char c_ref;
    bzero(&c_ref,1*sizeof(char));
char * c = &c_ref;
    {cgc_size_t i; i = (cgc_size_t)(1); }
    {char * c; c = (char *)(1); }
    {cgc_size_t rx; rx = (cgc_size_t)(1); }
    {int tlv1; tlv1 = (int)(1); }
    {int tlv5; tlv5 = (int)(1); }
    {void * tlv4; tlv4 = (void *)(1); }
    {cgc_size_t tlv3; tlv3 = (cgc_size_t)(1); }
}
void fix_ingred_main_0_2(){
fix_ingred_main_0_2_0();
fix_ingred_main_0_2_1();
fix_ingred_main_0_2_2();
}
void fix_ingred_main_0_3_4(){
int tlv1;
    bzero(&tlv1,sizeof(int));
cgc_size_t rx;
    bzero(&rx,sizeof(cgc_size_t));
    {cgc_size_t i; i = (cgc_size_t)(tlv1); }
    {char * c; c = (char *)(tlv1); }
    {cgc_size_t rx; rx = (cgc_size_t)(tlv1); }
    {int tlv5; tlv5 = (int)(tlv1); }
    {void * tlv4; tlv4 = (void *)(tlv1); }
    {cgc_size_t tlv3; tlv3 = (cgc_size_t)(tlv1); }
}
void fix_ingred_main_0_3_5(){
int tlv1;
    bzero(&tlv1,sizeof(int));
cgc_size_t rx;
    bzero(&rx,sizeof(cgc_size_t));
    {cgc_size_t i; i = (cgc_size_t)(0); }
    {char * c; c = (char *)(0); }
    {cgc_size_t rx; rx = (cgc_size_t)(0); }
    {int tlv1; tlv1 = (int)(0); }
    {int tlv5; tlv5 = (int)(0); }
    {void * tlv4; tlv4 = (void *)(0); }
    {cgc_size_t tlv3; tlv3 = (cgc_size_t)(0); }
}
void fix_ingred_main_0_3_6(){
int tlv1;
    bzero(&tlv1,sizeof(int));
cgc_size_t rx;
    bzero(&rx,sizeof(cgc_size_t));
    {cgc_size_t i; i = (cgc_size_t)(rx); }
    {char * c; c = (char *)(rx); }
    {int tlv1; tlv1 = (int)(rx); }
    {int tlv5; tlv5 = (int)(rx); }
    {void * tlv4; tlv4 = (void *)(rx); }
    {cgc_size_t tlv3; tlv3 = (cgc_size_t)(rx); }
}
void fix_ingred_main_0_3(){
fix_ingred_main_0_3_4();
fix_ingred_main_0_3_5();
fix_ingred_main_0_3_6();
}
void fix_ingred_main_0_4_4(){
char c_ref;
    bzero(&c_ref,1*sizeof(char));
char * c = &c_ref;
char delim;
    bzero(&delim,sizeof(char));
    {cgc_size_t i; i = (cgc_size_t)(* ( c ++ )); }
    {cgc_size_t rx; rx = (cgc_size_t)(* ( c ++ )); }
    {int tlv1; tlv1 = (int)(* ( c ++ )); }
    {int tlv5; tlv5 = (int)(* ( c ++ )); }
    {void * tlv4; tlv4 = (void *)(* ( c ++ )); }
    {cgc_size_t tlv3; tlv3 = (cgc_size_t)(* ( c ++ )); }
}
void fix_ingred_main_0_4_5(){
char c_ref;
    bzero(&c_ref,1*sizeof(char));
char * c = &c_ref;
char delim;
    bzero(&delim,sizeof(char));
    {cgc_size_t i; i = (cgc_size_t)(delim); }
    {char * c; c = (char *)(delim); }
    {cgc_size_t rx; rx = (cgc_size_t)(delim); }
    {int tlv1; tlv1 = (int)(delim); }
    {int tlv5; tlv5 = (int)(delim); }
    {void * tlv4; tlv4 = (void *)(delim); }
    {cgc_size_t tlv3; tlv3 = (cgc_size_t)(delim); }
}
void fix_ingred_main_0_4(){
fix_ingred_main_0_4_4();
fix_ingred_main_0_4_5();
}
void fix_ingred_main_0(){
fix_ingred_main_0_0();
fix_ingred_main_0_1();
fix_ingred_main_0_2();
fix_ingred_main_0_3();
fix_ingred_main_0_4();
}
void fix_ingred_main_1_3_0(){
    {int tlv2; tlv2 = (int)(STDOUT); }
}
void fix_ingred_main_1_3(){
fix_ingred_main_1_3_0();
}
void fix_ingred_main_1(){
fix_ingred_main_1_3();
}
void fix_ingred_main_2(){
}
void fix_ingred_main_3_0_0(){
char buf [ 1024 ];
    bzero(&buf,( 1024 *sizeof(char) ) );
    {int i; i = (int)(buf); }
    {char buf [ 1024 ]; buf [ ( 1024 )-1 ] = (char)(buf); }
    {char* nyan_cat ; nyan_cat  = (char*)(buf); }
    {int tlv2; tlv2 = (int)(buf); }
    {char * tlv4; tlv4 = (char *)(buf); }
}
void fix_ingred_main_3_0(){
fix_ingred_main_3_0_0();
}
void fix_ingred_main_3_2_0(){
    {int i; i = (int)(STDOUT); }
    {char * c; c = (char *)(STDOUT); }
    {char buf [ 1024 ]; buf [ ( 1024 )-1 ] = (char)(STDOUT); }
    {char* nyan_cat ; nyan_cat  = (char*)(STDOUT); }
    {int tlv5; tlv5 = (int)(STDOUT); }
    {char * tlv4; tlv4 = (char *)(STDOUT); }
}
void fix_ingred_main_3_2(){
fix_ingred_main_3_2_0();
}
void fix_ingred_main_3_4_2(){
int i;
    bzero(&i,sizeof(int));
    {int i; i = (int)(0); }
    {char buf [ 1024 ]; buf [ ( 1024 )-1 ] = (char)(0); }
    {char* nyan_cat ; nyan_cat  = (char*)(0); }
    {int tlv2; tlv2 = (int)(0); }
    {char * tlv4; tlv4 = (char *)(0); }
}
void fix_ingred_main_3_4_3(){
int i;
    bzero(&i,sizeof(int));
    {char * c; c = (char *)(i); }
    {char buf [ 1024 ]; buf [ ( 1024 )-1 ] = (char)(i); }
    {char* nyan_cat ; nyan_cat  = (char*)(i); }
    {int tlv2; tlv2 = (int)(i); }
    {int tlv5; tlv5 = (int)(i); }
    {char * tlv4; tlv4 = (char *)(i); }
}
void fix_ingred_main_3_4(){
fix_ingred_main_3_4_2();
fix_ingred_main_3_4_3();
}
void fix_ingred_main_3_6_0(){
char c_ref;
    bzero(&c_ref,1*sizeof(char));
char * c = &c_ref;
    {int i; i = (int)(c); }
    {char buf [ 1024 ]; buf [ ( 1024 )-1 ] = (char)(c); }
    {char* nyan_cat ; nyan_cat  = (char*)(c); }
    {int tlv2; tlv2 = (int)(c); }
    {int tlv5; tlv5 = (int)(c); }
    {char * tlv4; tlv4 = (char *)(c); }
}
void fix_ingred_main_3_6(){
fix_ingred_main_3_6_0();
}
void fix_ingred_main_3(){
fix_ingred_main_3_0();
fix_ingred_main_3_2();
fix_ingred_main_3_4();
fix_ingred_main_3_6();
}
void fix_ingred_main_4(){
}
void fix_ingred_main_5_1_0(){
    {int tlv4; tlv4 = (int)(STDOUT); }
    {int tlv6; tlv6 = (int)(STDOUT); }
    {int tlv8; tlv8 = (int)(STDOUT); }
    {int tlv10; tlv10 = (int)(STDOUT); }
}
void fix_ingred_main_5_1(){
fix_ingred_main_5_1_0();
}
void fix_ingred_main_5(){
fix_ingred_main_5_1();
}
void fix_ingred_main_6_0_0(){
char cgc_select [ 16 ];
    bzero(&cgc_select,( 16 *sizeof(char) ) );
    {char buf [ MAX_KTY_LENGTH ]; buf [ ( MAX_KTY_LENGTH )-1 ] = (char)(sizeof ( cgc_select )); }
    {char cgc_select [ 16 ]; cgc_select [ ( 16 )-1 ] = (char)(sizeof ( cgc_select )); }
    {int tlv1; tlv1 = (int)(sizeof ( cgc_select )); }
    {unsigned long tlv_size_0; tlv_size_0 = (unsigned long)(sizeof ( cgc_select )); }
    {int tlv4; tlv4 = (int)(sizeof ( cgc_select )); }
    {cgc_size_t tlv6; tlv6 = (cgc_size_t)(sizeof ( cgc_select )); }
    {int menu; menu = (int)(sizeof ( cgc_select )); }
    {int tlv8; tlv8 = (int)(sizeof ( cgc_select )); }
    {int tlv9; tlv9 = (int)(sizeof ( cgc_select )); }
    {int tlv2; tlv2 = (int)(sizeof ( cgc_select )); }
    {int tlv17; tlv17 = (int)(sizeof ( cgc_select )); }
    {char * tlv16; tlv16 = (char *)(sizeof ( cgc_select )); }
    {cgc_size_t tlv15; tlv15 = (cgc_size_t)(sizeof ( cgc_select )); }
    {char tlv14; tlv14 = (char)(sizeof ( cgc_select )); }
    {int tlv13; tlv13 = (int)(sizeof ( cgc_select )); }
    {int tlv19; tlv19 = (int)(sizeof ( cgc_select )); }
}
void fix_ingred_main_6_0(){
fix_ingred_main_6_0_0();
}
void fix_ingred_main_6_1_0(){
    {char buf [ MAX_KTY_LENGTH ]; buf [ ( MAX_KTY_LENGTH )-1 ] = (char)(STDOUT); }
    {char cgc_select [ 16 ]; cgc_select [ ( 16 )-1 ] = (char)(STDOUT); }
    {int tlv1; tlv1 = (int)(STDOUT); }
    {unsigned long tlv_size_0; tlv_size_0 = (unsigned long)(STDOUT); }
    {cgc_size_t tlv6; tlv6 = (cgc_size_t)(STDOUT); }
    {int menu; menu = (int)(STDOUT); }
    {int tlv9; tlv9 = (int)(STDOUT); }
    {int tlv17; tlv17 = (int)(STDOUT); }
    {char * tlv16; tlv16 = (char *)(STDOUT); }
    {cgc_size_t tlv15; tlv15 = (cgc_size_t)(STDOUT); }
    {char tlv14; tlv14 = (char)(STDOUT); }
    {int tlv13; tlv13 = (int)(STDOUT); }
    {int tlv19; tlv19 = (int)(STDOUT); }
}
void fix_ingred_main_6_1(){
fix_ingred_main_6_1_0();
}
void fix_ingred_main_6_2_0(){
    {char buf [ MAX_KTY_LENGTH ]; buf [ ( MAX_KTY_LENGTH )-1 ] = (char)(sizeof ( kty_parser_t )); }
    {char cgc_select [ 16 ]; cgc_select [ ( 16 )-1 ] = (char)(sizeof ( kty_parser_t )); }
    {int tlv1; tlv1 = (int)(sizeof ( kty_parser_t )); }
    {unsigned long tlv_size_0; tlv_size_0 = (unsigned long)(sizeof ( kty_parser_t )); }
    {int tlv4; tlv4 = (int)(sizeof ( kty_parser_t )); }
    {cgc_size_t tlv6; tlv6 = (cgc_size_t)(sizeof ( kty_parser_t )); }
    {int menu; menu = (int)(sizeof ( kty_parser_t )); }
    {int tlv8; tlv8 = (int)(sizeof ( kty_parser_t )); }
    {int tlv9; tlv9 = (int)(sizeof ( kty_parser_t )); }
    {int tlv2; tlv2 = (int)(sizeof ( kty_parser_t )); }
    {int tlv17; tlv17 = (int)(sizeof ( kty_parser_t )); }
    {char * tlv16; tlv16 = (char *)(sizeof ( kty_parser_t )); }
    {cgc_size_t tlv15; tlv15 = (cgc_size_t)(sizeof ( kty_parser_t )); }
    {char tlv14; tlv14 = (char)(sizeof ( kty_parser_t )); }
    {int tlv13; tlv13 = (int)(sizeof ( kty_parser_t )); }
    {int tlv19; tlv19 = (int)(sizeof ( kty_parser_t )); }
}
void fix_ingred_main_6_2(){
fix_ingred_main_6_2_0();
}
void fix_ingred_main_6_4_0(){
int tlv1;
    bzero(&tlv1,sizeof(int));
    {char buf [ MAX_KTY_LENGTH ]; buf [ ( MAX_KTY_LENGTH )-1 ] = (char)(tlv1); }
    {char cgc_select [ 16 ]; cgc_select [ ( 16 )-1 ] = (char)(tlv1); }
    {unsigned long tlv_size_0; tlv_size_0 = (unsigned long)(tlv1); }
    {int tlv4; tlv4 = (int)(tlv1); }
    {cgc_size_t tlv6; tlv6 = (cgc_size_t)(tlv1); }
    {int menu; menu = (int)(tlv1); }
    {int tlv8; tlv8 = (int)(tlv1); }
    {int tlv9; tlv9 = (int)(tlv1); }
    {int tlv2; tlv2 = (int)(tlv1); }
    {int tlv17; tlv17 = (int)(tlv1); }
    {char * tlv16; tlv16 = (char *)(tlv1); }
    {cgc_size_t tlv15; tlv15 = (cgc_size_t)(tlv1); }
    {char tlv14; tlv14 = (char)(tlv1); }
    {int tlv13; tlv13 = (int)(tlv1); }
    {int tlv19; tlv19 = (int)(tlv1); }
}
void fix_ingred_main_6_4_1(){
int tlv1;
    bzero(&tlv1,sizeof(int));
    {char buf [ MAX_KTY_LENGTH ]; buf [ ( MAX_KTY_LENGTH )-1 ] = (char)(0); }
    {char cgc_select [ 16 ]; cgc_select [ ( 16 )-1 ] = (char)(0); }
    {unsigned long tlv_size_0; tlv_size_0 = (unsigned long)(0); }
    {int tlv4; tlv4 = (int)(0); }
    {cgc_size_t tlv6; tlv6 = (cgc_size_t)(0); }
    {int menu; menu = (int)(0); }
    {int tlv8; tlv8 = (int)(0); }
    {int tlv9; tlv9 = (int)(0); }
    {int tlv17; tlv17 = (int)(0); }
    {char * tlv16; tlv16 = (char *)(0); }
    {cgc_size_t tlv15; tlv15 = (cgc_size_t)(0); }
    {char tlv14; tlv14 = (char)(0); }
    {int tlv13; tlv13 = (int)(0); }
    {int tlv19; tlv19 = (int)(0); }
}
void fix_ingred_main_6_4(){
fix_ingred_main_6_4_0();
fix_ingred_main_6_4_1();
}
void fix_ingred_main_6_7_1(){
    {char buf [ MAX_KTY_LENGTH ]; buf [ ( MAX_KTY_LENGTH )-1 ] = (char)(10); }
    {char cgc_select [ 16 ]; cgc_select [ ( 16 )-1 ] = (char)(10); }
    {int tlv1; tlv1 = (int)(10); }
    {unsigned long tlv_size_0; tlv_size_0 = (unsigned long)(10); }
    {int tlv4; tlv4 = (int)(10); }
    {cgc_size_t tlv6; tlv6 = (cgc_size_t)(10); }
    {int menu; menu = (int)(10); }
    {int tlv8; tlv8 = (int)(10); }
    {int tlv9; tlv9 = (int)(10); }
    {int tlv2; tlv2 = (int)(10); }
    {int tlv17; tlv17 = (int)(10); }
    {char * tlv16; tlv16 = (char *)(10); }
    {cgc_size_t tlv15; tlv15 = (cgc_size_t)(10); }
    {char tlv14; tlv14 = (char)(10); }
    {int tlv13; tlv13 = (int)(10); }
    {int tlv19; tlv19 = (int)(10); }
}
void fix_ingred_main_6_7(){
fix_ingred_main_6_7_1();
}
void fix_ingred_main_6_10_0(){
char buf [ MAX_KTY_LENGTH ];
    bzero(&buf,( MAX_KTY_LENGTH *sizeof(char) ) );
    {char buf [ MAX_KTY_LENGTH ]; buf [ ( MAX_KTY_LENGTH )-1 ] = (char)(STDIN); }
    {char cgc_select [ 16 ]; cgc_select [ ( 16 )-1 ] = (char)(STDIN); }
    {int tlv1; tlv1 = (int)(STDIN); }
    {unsigned long tlv_size_0; tlv_size_0 = (unsigned long)(STDIN); }
    {int tlv4; tlv4 = (int)(STDIN); }
    {cgc_size_t tlv6; tlv6 = (cgc_size_t)(STDIN); }
    {int menu; menu = (int)(STDIN); }
    {int tlv8; tlv8 = (int)(STDIN); }
    {int tlv9; tlv9 = (int)(STDIN); }
    {int tlv2; tlv2 = (int)(STDIN); }
    {int tlv17; tlv17 = (int)(STDIN); }
    {char * tlv16; tlv16 = (char *)(STDIN); }
    {cgc_size_t tlv15; tlv15 = (cgc_size_t)(STDIN); }
    {char tlv14; tlv14 = (char)(STDIN); }
    {int tlv13; tlv13 = (int)(STDIN); }
    {int tlv19; tlv19 = (int)(STDIN); }
}
void fix_ingred_main_6_10_1(){
char buf [ MAX_KTY_LENGTH ];
    bzero(&buf,( MAX_KTY_LENGTH *sizeof(char) ) );
    {char buf [ MAX_KTY_LENGTH ]; buf [ ( MAX_KTY_LENGTH )-1 ] = (char)(buf); }
    {char cgc_select [ 16 ]; cgc_select [ ( 16 )-1 ] = (char)(buf); }
    {unsigned long tlv_size_0; tlv_size_0 = (unsigned long)(buf); }
    {int tlv4; tlv4 = (int)(buf); }
    {cgc_size_t tlv6; tlv6 = (cgc_size_t)(buf); }
    {int menu; menu = (int)(buf); }
    {int tlv8; tlv8 = (int)(buf); }
    {int tlv9; tlv9 = (int)(buf); }
    {int tlv17; tlv17 = (int)(buf); }
    {char * tlv16; tlv16 = (char *)(buf); }
    {cgc_size_t tlv15; tlv15 = (cgc_size_t)(buf); }
    {char tlv14; tlv14 = (char)(buf); }
    {int tlv13; tlv13 = (int)(buf); }
    {int tlv19; tlv19 = (int)(buf); }
}
void fix_ingred_main_6_10_2(){
char buf [ MAX_KTY_LENGTH ];
    bzero(&buf,( MAX_KTY_LENGTH *sizeof(char) ) );
    {char buf [ MAX_KTY_LENGTH ]; buf [ ( MAX_KTY_LENGTH )-1 ] = (char)(MAX_KTY_LENGTH); }
    {char cgc_select [ 16 ]; cgc_select [ ( 16 )-1 ] = (char)(MAX_KTY_LENGTH); }
    {int tlv1; tlv1 = (int)(MAX_KTY_LENGTH); }
    {unsigned long tlv_size_0; tlv_size_0 = (unsigned long)(MAX_KTY_LENGTH); }
    {int tlv4; tlv4 = (int)(MAX_KTY_LENGTH); }
    {cgc_size_t tlv6; tlv6 = (cgc_size_t)(MAX_KTY_LENGTH); }
    {int menu; menu = (int)(MAX_KTY_LENGTH); }
    {int tlv8; tlv8 = (int)(MAX_KTY_LENGTH); }
    {int tlv9; tlv9 = (int)(MAX_KTY_LENGTH); }
    {int tlv2; tlv2 = (int)(MAX_KTY_LENGTH); }
    {int tlv17; tlv17 = (int)(MAX_KTY_LENGTH); }
    {char * tlv16; tlv16 = (char *)(MAX_KTY_LENGTH); }
    {cgc_size_t tlv15; tlv15 = (cgc_size_t)(MAX_KTY_LENGTH); }
    {char tlv14; tlv14 = (char)(MAX_KTY_LENGTH); }
    {int tlv13; tlv13 = (int)(MAX_KTY_LENGTH); }
    {int tlv19; tlv19 = (int)(MAX_KTY_LENGTH); }
}
void fix_ingred_main_6_10_3(){
char buf [ MAX_KTY_LENGTH ];
    bzero(&buf,( MAX_KTY_LENGTH *sizeof(char) ) );
    {char buf [ MAX_KTY_LENGTH ]; buf [ ( MAX_KTY_LENGTH )-1 ] = (char)('\x00'); }
    {char cgc_select [ 16 ]; cgc_select [ ( 16 )-1 ] = (char)('\x00'); }
    {int tlv1; tlv1 = (int)('\x00'); }
    {unsigned long tlv_size_0; tlv_size_0 = (unsigned long)('\x00'); }
    {int tlv4; tlv4 = (int)('\x00'); }
    {cgc_size_t tlv6; tlv6 = (cgc_size_t)('\x00'); }
    {int menu; menu = (int)('\x00'); }
    {int tlv8; tlv8 = (int)('\x00'); }
    {int tlv9; tlv9 = (int)('\x00'); }
    {int tlv2; tlv2 = (int)('\x00'); }
    {int tlv17; tlv17 = (int)('\x00'); }
    {char * tlv16; tlv16 = (char *)('\x00'); }
    {cgc_size_t tlv15; tlv15 = (cgc_size_t)('\x00'); }
    {char tlv14; tlv14 = (char)('\x00'); }
    {int tlv13; tlv13 = (int)('\x00'); }
    {int tlv19; tlv19 = (int)('\x00'); }
}
void fix_ingred_main_6_10(){
fix_ingred_main_6_10_0();
fix_ingred_main_6_10_1();
fix_ingred_main_6_10_2();
fix_ingred_main_6_10_3();
}
void fix_ingred_main_6_11_2(){
int tlv2;
    bzero(&tlv2,sizeof(int));
    {char buf [ MAX_KTY_LENGTH ]; buf [ ( MAX_KTY_LENGTH )-1 ] = (char)(tlv2); }
    {char cgc_select [ 16 ]; cgc_select [ ( 16 )-1 ] = (char)(tlv2); }
    {int tlv1; tlv1 = (int)(tlv2); }
    {unsigned long tlv_size_0; tlv_size_0 = (unsigned long)(tlv2); }
    {int tlv4; tlv4 = (int)(tlv2); }
    {cgc_size_t tlv6; tlv6 = (cgc_size_t)(tlv2); }
    {int menu; menu = (int)(tlv2); }
    {int tlv8; tlv8 = (int)(tlv2); }
    {int tlv9; tlv9 = (int)(tlv2); }
    {int tlv17; tlv17 = (int)(tlv2); }
    {char * tlv16; tlv16 = (char *)(tlv2); }
    {cgc_size_t tlv15; tlv15 = (cgc_size_t)(tlv2); }
    {char tlv14; tlv14 = (char)(tlv2); }
    {int tlv13; tlv13 = (int)(tlv2); }
    {int tlv19; tlv19 = (int)(tlv2); }
}
void fix_ingred_main_6_11(){
fix_ingred_main_6_11_2();
}
void fix_ingred_main_6(){
fix_ingred_main_6_0();
fix_ingred_main_6_1();
fix_ingred_main_6_2();
fix_ingred_main_6_4();
fix_ingred_main_6_7();
fix_ingred_main_6_10();
fix_ingred_main_6_11();
}
