

#include "libcgc.h"
#include "cgc_stdarg.h"
#include "cgc_stdlib.h"
#include "cgc_string.h"
#include "cgc_ctype.h"
#define ERROR 9
#define NEW_CHALLENGE 0
#define RESET 1
#define QUIT 2
static int total = 0;
static int win = 0;
static char *words[] = {
    "leonite", "drawdown", "conuzor", "franklin", "married",
    "excircle", "solidness", "aneuria", "constablery", "infractible",
    "speedingly", "scantlinged", "presphenoid", "diphyozooid", "twistiways",
    "didrachma", "fa", "gyte", "emblazonry", "insulize"
};

typedef struct hackman_state {
    void (*quit_handler) (void);
    void (*new_challenge_handler) (struct hackman_state *);
    char word[20];
    char progress[20];
    unsigned int num_tries;
} hackman_state_t;
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
	    break;
	}
	if (*(c++) == delim) {
	    break;
	}
    }
    *(c - 1) = '\0';
    return c - buf;
}

void fix_ingred_main_1_1_0();
void fix_ingred_main_1_1_1();
void fix_ingred_main_1_1_2();
void fix_ingred_main_1_1_3();
void fix_ingred_main_1_1();
void fix_ingred_main_1_2_0();
void fix_ingred_main_1_2_1();
void fix_ingred_main_1_2();
void fix_ingred_main_1_8_0();
void fix_ingred_main_1_8();
void fix_ingred_main_1();
char cgc_parse_input(char *buf)
{
if (fix_ingred_enable){ fix_ingred_main_1(); };
    int tlv1;
    {
        int tlv6;
        tlv6 = STDIN;
        char* tlv5;
         tlv5 = buf;
        cgc_size_t tlv4;
        tlv4 = 128;
        char tlv3;
        tlv3 = '\n';
        tlv1 = cgc_read_until(tlv6,tlv5,tlv4,tlv3);
    }
    if (tlv1 > 0) {
	switch (buf[0]) {
	case '+':
	    {
		return NEW_CHALLENGE;
	    }
	    break;
	case '/':
	    {
		return QUIT;
	    }
	    break;
	case '?':
	    {
		return RESET;
	    }
	    break;
	default:
	    {
  int tlv2;
  {
      int tlv7;
      tlv7 = buf [ 0 ];
      tlv2 = cgc_isalpha(tlv7);
  }
		if (tlv2) {
		    return cgc_tolower(buf[0]);
		}
	    }
	    break;
	}
    } else {
	cgc_exit(0);
    }
    return ERROR;
}

void fix_ingred_main_2_0_0();
void fix_ingred_main_2_0_1();
void fix_ingred_main_2_0();
void fix_ingred_main_2_1_0();
void fix_ingred_main_2_1_2();
void fix_ingred_main_2_1();
void fix_ingred_main_2_2_3();
void fix_ingred_main_2_2_4();
void fix_ingred_main_2_2();
void fix_ingred_main_2_3_5();
void fix_ingred_main_2_3_6();
void fix_ingred_main_2_3();
void fix_ingred_main_2_6_0();
void fix_ingred_main_2_6();
void fix_ingred_main_2();
void cgc_banner()
{
if (fix_ingred_enable){ fix_ingred_main_2(); };
    char msg[2048];
    int i;
    int j;
    int cnt;
    cnt = 0;
    {
        void* tlv3;
        tlv3 = msg;
        int tlv2;
        tlv2 = 0;
        cgc_size_t tlv1;
        tlv1 = sizeof ( msg );
        cgc_memset(tlv3,tlv2,tlv1);
    }
    for (j = 0; j < 2; ++j) {
	for (i = 0; i < 33; ++i) {
	    if (i % 2) {
		msg[cnt++] = '-';
	    } else {
		msg[cnt++] = '_';
	    }
	}
	msg[cnt++] = '\n';
    }
    {
        char* tlv5;
         tlv5 = & msg [ cnt ];
        const char tlv4 [ ] = "     Sh41l w3 p14y a g4m3?\n";
        cgc_strcpy(tlv5,tlv4);
    }
    cnt += 27;
    for (j = 0; j < 2; ++j) {
	for (i = 0; i < 33; ++i) {
	    if (i % 2) {
		msg[cnt++] = '-';
	    } else {
		msg[cnt++] = '_';
	    }
	}
	msg[cnt++] = '\n';
    }
    cgc_fdprintf(STDOUT, "%s\n", msg);
}

void fix_ingred_main_3_1_0();
void fix_ingred_main_3_1();
void fix_ingred_main_3_5_0();
void fix_ingred_main_3_5_1();
void fix_ingred_main_3_5_2();
void fix_ingred_main_3_5_3();
void fix_ingred_main_3_5();
void fix_ingred_main_3_6_1();
void fix_ingred_main_3_6_2();
void fix_ingred_main_3_6();
void fix_ingred_main_3();
void cgc_record_winner()
{
if (fix_ingred_enable){ fix_ingred_main_3(); };
    char comment[2048];
    {
        int tlv3;
        tlv3 = STDOUT;
        const char tlv2 [ ] = "###### Good Work! ######\n";
        cgc_fdprintf(tlv3,tlv2);
    }
    {
        int tlv5;
        tlv5 = STDOUT;
        const char tlv4 [ ] = "# Leave your comment!! #\n";
        cgc_fdprintf(tlv5,tlv4);
    }
    {
        int tlv7;
        tlv7 = STDOUT;
        const char tlv6 [ ] = "########################\n";
        cgc_fdprintf(tlv7,tlv6);
    }
    {
        int tlv9;
        tlv9 = STDOUT;
        const char tlv8 [ ] = "Comment: ";
        cgc_fdprintf(tlv9,tlv8);
    }
    int tlv1;
    {
        int tlv13;
        tlv13 = STDIN;
        char* tlv12;
         tlv12 = comment;
        cgc_size_t tlv11;
        tlv11 = sizeof ( comment );
        char tlv10;
        tlv10 = '\n';
        tlv1 = cgc_read_until(tlv13,tlv12,tlv11,tlv10);
    }
    if (tlv1 > 0) {
	comment[2047] = '\0';
	cgc_fdprintf(STDOUT, "You wrote: %s\n", comment);
    } else {
	cgc_exit(0);
    }
    total++;
}

void fix_ingred_main_4_0_0();
void fix_ingred_main_4_0_1();
void fix_ingred_main_4_0_2();
void fix_ingred_main_4_0();
void fix_ingred_main_4_1_0();
void fix_ingred_main_4_1();
void fix_ingred_main_4_3_0();
void fix_ingred_main_4_3_1();
void fix_ingred_main_4_3_2();
void fix_ingred_main_4_3_3();
void fix_ingred_main_4_3();
void fix_ingred_main_4_4_0();
void fix_ingred_main_4_4_1();
void fix_ingred_main_4_4();
void fix_ingred_main_4_5_1();
void fix_ingred_main_4_5();
void fix_ingred_main_4_6_0();
void fix_ingred_main_4_6_2();
void fix_ingred_main_4_6_3();
void fix_ingred_main_4_6();
void fix_ingred_main_4_7_0();
void fix_ingred_main_4_7_2();
void fix_ingred_main_4_7();
void fix_ingred_main_4_8_0();
void fix_ingred_main_4_8_2();
void fix_ingred_main_4_8();
void fix_ingred_main_4_9_0();
void fix_ingred_main_4_9();
void fix_ingred_main_4_10_1();
void fix_ingred_main_4_10();
void fix_ingred_main_4_11_0();
void fix_ingred_main_4_11();
void fix_ingred_main_4();
void cgc_new_challenge(hackman_state_t * h_state)
{
if (fix_ingred_enable){ fix_ingred_main_4(); };
    unsigned short lfsr;
    unsigned int num;
    char buf[32];
    {
        int tlv3;
        tlv3 = STDOUT;
        const char tlv2 [ ] = "\n@ @ @ @ @  New Challenge  @ @ @ @ @\n";
        cgc_fdprintf(tlv3,tlv2);
    }
    {
        int tlv5;
        tlv5 = STDOUT;
        const char tlv4 [ ] = "Seed? ";
        cgc_fdprintf(tlv5,tlv4);
    }
    int tlv1;
    {
        int tlv20;
        tlv20 = STDIN;
        char* tlv19;
         tlv19 = buf;
        cgc_size_t tlv18;
        tlv18 = sizeof ( buf );
        char tlv17;
        tlv17 = '\n';
        tlv1 = cgc_read_until(tlv20,tlv19,tlv18,tlv17);
    }
    if (tlv1 <= 0) {
	cgc_exit(0);
    }
    {
        const char* tlv23 = buf;
        char** tlv22;
         tlv22 = NULL;
        int tlv21;
        tlv21 = 10;
        num = cgc_strtoul(tlv23,tlv22,tlv21);
    }

    lfsr = ((num & 0x00FF0000) >> 16) | ((num & 0x000000FF) << 8);
    if (lfsr == 0) {
	lfsr = 0xACE1u;
    }
    num = ((lfsr >> 0) ^ (lfsr >> 2) ^ (lfsr >> 3) ^ (lfsr >> 5)) & 1;
    num = (lfsr >> 1) | (num << 15);
    {
        void* tlv8;
        tlv8 = h_state -> word;
        int tlv7;
        tlv7 = 0;
        cgc_size_t tlv6;
        tlv6 = sizeof ( h_state -> word );
        cgc_memset(tlv8,tlv7,tlv6);
    }
    {
        void* tlv11;
        tlv11 = h_state -> progress;
        int tlv10;
        tlv10 = 0;
        cgc_size_t tlv9;
        tlv9 = sizeof ( h_state -> progress );
        cgc_memset(tlv11,tlv10,tlv9);
    }
    {
        char* tlv13;
         tlv13 = h_state -> word;
        const char* tlv12 = words [ num % 20 ];
        cgc_strcpy(tlv13,tlv12);
    }
    {
        void* tlv16;
        tlv16 = h_state -> progress;
        int tlv15;
        tlv15 = '_';
        cgc_size_t tlv14;
        {
            const char* tlv24 = words [ num % 20 ];
            tlv14 = cgc_strlen(tlv24);
        }
        cgc_memset(tlv16,tlv15,tlv14);
    }
    h_state->num_tries = 0;
}

void fix_ingred_main_5();
void cgc_quit_game()
{
if (fix_ingred_enable){ fix_ingred_main_5(); };
    cgc_fdprintf(STDOUT, "\n * * * * Thank you for playing! You've won %d times! * * * *\n", total);
    cgc_exit(0);
}

void fix_ingred_main_6_1_0();
void fix_ingred_main_6_1();
void fix_ingred_main_6_2_0();
void fix_ingred_main_6_2();
void fix_ingred_main_6_3_1();
void fix_ingred_main_6_3_2();
void fix_ingred_main_6_3();
void fix_ingred_main_6_4_0();
void fix_ingred_main_6_4();
void fix_ingred_main_6_5_0();
void fix_ingred_main_6_5();
void fix_ingred_main_6_11_0();
void fix_ingred_main_6_11_1();
void fix_ingred_main_6_11();
void fix_ingred_main_6_12_0();
void fix_ingred_main_6_12();
void fix_ingred_main_6_16_0();
void fix_ingred_main_6_16();
void fix_ingred_main_6_20_3();
void fix_ingred_main_6_20_4();
void fix_ingred_main_6_20();
void fix_ingred_main_6_21_7();
void fix_ingred_main_6_21();
void fix_ingred_main_6_23_5();
void fix_ingred_main_6_23();
void fix_ingred_main_6();
void cgc_play_game()
{
if (fix_ingred_enable){ fix_ingred_main_6(); };
    hackman_state_t h_state;
    char buf[128];
    int i;
    int found;
    int error;
    while (1) {
	error = 0;
 cgc_size_t tlv1;
 {
     const char* tlv5 = h_state . word;
     tlv1 = cgc_strlen(tlv5);
 }
	if (win || tlv1 == 0) {
	    goto new_chal;
	}
	cgc_fdprintf(STDOUT, "[[[ Your challenge: %s ]]]\n", h_state.progress);
 {
     int tlv4;
     tlv4 = STDOUT;
     const char tlv3 [ ] = "Guess a letter: ";
    	cgc_fdprintf(tlv4,tlv3);
 }
 char tlv2;
 {
     char* tlv6;
      tlv6 = buf;
     tlv2 = cgc_parse_input(tlv6);
 }
	switch (tlv2) {
	case NEW_CHALLENGE:
	    {
	      new_chal:
		if (h_state.new_challenge_handler == NULL) {
		    h_state.new_challenge_handler = cgc_new_challenge;
		}
	    }
	    if (h_state.quit_handler == NULL) {
		h_state.quit_handler = cgc_quit_game;
	    }
	    h_state.new_challenge_handler(&h_state);
	    win = 0;
	    continue;
	    break;
	case RESET:
	    {
		h_state.num_tries = 0;
	    }
     {
         void* tlv9;
         tlv9 = h_state . progress;
         int tlv8;
         tlv8 = '_';
         cgc_size_t tlv7;
         {
             const char* tlv12 = h_state . word;
             tlv7 = cgc_strlen(tlv12);
         }
    	    cgc_memset(tlv9,tlv8,tlv7);
     }
     {
         int tlv11;
         tlv11 = STDOUT;
         const char tlv10 [ ] = "\n^^^^^ RESET ^^^^^\n\n";
    	    cgc_fdprintf(tlv11,tlv10);
     }
	    continue;
	    break;
	case QUIT:
	    {
		if (h_state.quit_handler == NULL) {
		    h_state.quit_handler = cgc_quit_game;
		}
	    }
	    h_state.quit_handler();
	    break;
	case ERROR:
	    {
		error = 1;
	    }
	    break;
	default:
	    { {
		    h_state.num_tries++;
	    }
	    }
	    break;
	}
	if (!error) {
	    found = 0;
	    for (i = 0; i < cgc_strlen(h_state.word); ++i) {
		if (buf[0] == h_state.word[i]) {
		    h_state.progress[i] = buf[0];
		    found = 1;
		}
	    }
	    if (found) {
		found = 0;
		for (i = 0; i < cgc_strlen(h_state.progress); ++i)
  {
		    if (h_state.progress[i] == '_') {
			found = 1;
		    }
  }
		if (!found) {
		    cgc_fdprintf(STDOUT, ">>> You got it!! \"%s\" (%d tries) <<<\n", h_state.word, h_state.num_tries);
		    win = 1;
		    break;
		}
	    }
	}
    }
}

void fix_ingred_main_7_1_0();
void fix_ingred_main_7_1();
void fix_ingred_main_7();
int main(int cgc_argc, char *cgc_argv[])
{
if (fix_ingred_enable){ fix_ingred_main_7(); };
    char buf[128];
    {
        int tlv2;
        tlv2 = STDOUT;
        const char tlv1 [ ] = "\nWelcome to HackMan v13.37\n\n";
        cgc_fdprintf(tlv2,tlv1);
    }
    while (1) {
	if (win) {
	    cgc_record_winner();
	} else {
	    cgc_banner();
	}
	cgc_play_game();
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
void fix_ingred_main_1_1_0(){
char buf_ref;
    bzero(&buf_ref,1*sizeof(char));
char * buf = &buf_ref;
    {int tlv1; tlv1 = (int)(STDIN); }
    {int tlv6; tlv6 = (int)(STDIN); }
    {char * tlv5; tlv5 = (char *)(STDIN); }
    {cgc_size_t tlv4; tlv4 = (cgc_size_t)(STDIN); }
    {char tlv3; tlv3 = (char)(STDIN); }
    {int tlv2; tlv2 = (int)(STDIN); }
    {int tlv7; tlv7 = (int)(STDIN); }
}
void fix_ingred_main_1_1_1(){
char buf_ref;
    bzero(&buf_ref,1*sizeof(char));
char * buf = &buf_ref;
    {int tlv6; tlv6 = (int)(buf); }
    {char * tlv5; tlv5 = (char *)(buf); }
    {cgc_size_t tlv4; tlv4 = (cgc_size_t)(buf); }
    {char tlv3; tlv3 = (char)(buf); }
    {int tlv2; tlv2 = (int)(buf); }
    {int tlv7; tlv7 = (int)(buf); }
}
void fix_ingred_main_1_1_2(){
char buf_ref;
    bzero(&buf_ref,1*sizeof(char));
char * buf = &buf_ref;
    {int tlv1; tlv1 = (int)(128); }
    {int tlv6; tlv6 = (int)(128); }
    {char * tlv5; tlv5 = (char *)(128); }
    {cgc_size_t tlv4; tlv4 = (cgc_size_t)(128); }
    {char tlv3; tlv3 = (char)(128); }
    {int tlv2; tlv2 = (int)(128); }
    {int tlv7; tlv7 = (int)(128); }
}
void fix_ingred_main_1_1_3(){
char buf_ref;
    bzero(&buf_ref,1*sizeof(char));
char * buf = &buf_ref;
    {int tlv1; tlv1 = (int)('\n'); }
    {int tlv6; tlv6 = (int)('\n'); }
    {char * tlv5; tlv5 = (char *)('\n'); }
    {cgc_size_t tlv4; tlv4 = (cgc_size_t)('\n'); }
    {char tlv3; tlv3 = (char)('\n'); }
    {int tlv2; tlv2 = (int)('\n'); }
    {int tlv7; tlv7 = (int)('\n'); }
}
void fix_ingred_main_1_1(){
fix_ingred_main_1_1_0();
fix_ingred_main_1_1_1();
fix_ingred_main_1_1_2();
fix_ingred_main_1_1_3();
}
void fix_ingred_main_1_2_0(){
int tlv1;
    bzero(&tlv1,sizeof(int));
    {int tlv6; tlv6 = (int)(tlv1); }
    {char * tlv5; tlv5 = (char *)(tlv1); }
    {cgc_size_t tlv4; tlv4 = (cgc_size_t)(tlv1); }
    {char tlv3; tlv3 = (char)(tlv1); }
    {int tlv2; tlv2 = (int)(tlv1); }
    {int tlv7; tlv7 = (int)(tlv1); }
}
void fix_ingred_main_1_2_1(){
int tlv1;
    bzero(&tlv1,sizeof(int));
    {int tlv6; tlv6 = (int)(0); }
    {char * tlv5; tlv5 = (char *)(0); }
    {cgc_size_t tlv4; tlv4 = (cgc_size_t)(0); }
    {char tlv3; tlv3 = (char)(0); }
    {int tlv2; tlv2 = (int)(0); }
    {int tlv7; tlv7 = (int)(0); }
}
void fix_ingred_main_1_2(){
fix_ingred_main_1_2_0();
fix_ingred_main_1_2_1();
}
void fix_ingred_main_1_8_0(){
char buf_ref;
    bzero(&buf_ref,1*sizeof(char));
char * buf = &buf_ref;
    {int tlv1; tlv1 = (int)(buf [ 0 ]); }
    {int tlv6; tlv6 = (int)(buf [ 0 ]); }
    {char * tlv5; tlv5 = (char *)(buf [ 0 ]); }
    {cgc_size_t tlv4; tlv4 = (cgc_size_t)(buf [ 0 ]); }
    {char tlv3; tlv3 = (char)(buf [ 0 ]); }
    {int tlv2; tlv2 = (int)(buf [ 0 ]); }
    {int tlv7; tlv7 = (int)(buf [ 0 ]); }
}
void fix_ingred_main_1_8(){
fix_ingred_main_1_8_0();
}
void fix_ingred_main_1(){
fix_ingred_main_1_1();
fix_ingred_main_1_2();
fix_ingred_main_1_8();
}
void fix_ingred_main_2_0_0(){
    {char msg [ 2048 ]; msg [ ( 2048 )-1 ] = (char)(0); }
    {int i; i = (int)(0); }
    {int j; j = (int)(0); }
    {int cnt; cnt = (int)(0); }
    {void * tlv3; tlv3 = (void *)(0); }
    {cgc_size_t tlv1; tlv1 = (cgc_size_t)(0); }
}
void fix_ingred_main_2_0_1(){
    {char msg [ 2048 ]; msg [ ( 2048 )-1 ] = (char)(27); }
    {int i; i = (int)(27); }
    {int j; j = (int)(27); }
    {int cnt; cnt = (int)(27); }
    {void * tlv3; tlv3 = (void *)(27); }
    {int tlv2; tlv2 = (int)(27); }
    {cgc_size_t tlv1; tlv1 = (cgc_size_t)(27); }
    {char * tlv5; tlv5 = (char *)(27); }
}
void fix_ingred_main_2_0(){
fix_ingred_main_2_0_0();
fix_ingred_main_2_0_1();
}
void fix_ingred_main_2_1_0(){
char msg [ 2048 ];
    bzero(&msg,( 2048 *sizeof(char) ) );
    {char msg [ 2048 ]; msg [ ( 2048 )-1 ] = (char)(msg); }
    {int i; i = (int)(msg); }
    {int j; j = (int)(msg); }
    {int cnt; cnt = (int)(msg); }
    {void * tlv3; tlv3 = (void *)(msg); }
    {int tlv2; tlv2 = (int)(msg); }
    {cgc_size_t tlv1; tlv1 = (cgc_size_t)(msg); }
    {char * tlv5; tlv5 = (char *)(msg); }
}
void fix_ingred_main_2_1_2(){
char msg [ 2048 ];
    bzero(&msg,( 2048 *sizeof(char) ) );
    {char msg [ 2048 ]; msg [ ( 2048 )-1 ] = (char)(sizeof ( msg )); }
    {int i; i = (int)(sizeof ( msg )); }
    {int j; j = (int)(sizeof ( msg )); }
    {int cnt; cnt = (int)(sizeof ( msg )); }
    {void * tlv3; tlv3 = (void *)(sizeof ( msg )); }
    {int tlv2; tlv2 = (int)(sizeof ( msg )); }
    {cgc_size_t tlv1; tlv1 = (cgc_size_t)(sizeof ( msg )); }
    {char * tlv5; tlv5 = (char *)(sizeof ( msg )); }
}
void fix_ingred_main_2_1(){
fix_ingred_main_2_1_0();
fix_ingred_main_2_1_2();
}
void fix_ingred_main_2_2_3(){
int j;
    bzero(&j,sizeof(int));
    {char msg [ 2048 ]; msg [ ( 2048 )-1 ] = (char)(j); }
    {int i; i = (int)(j); }
    {int cnt; cnt = (int)(j); }
    {void * tlv3; tlv3 = (void *)(j); }
    {int tlv2; tlv2 = (int)(j); }
    {cgc_size_t tlv1; tlv1 = (cgc_size_t)(j); }
    {char * tlv5; tlv5 = (char *)(j); }
}
void fix_ingred_main_2_2_4(){
int j;
    bzero(&j,sizeof(int));
    {char msg [ 2048 ]; msg [ ( 2048 )-1 ] = (char)(2); }
    {int i; i = (int)(2); }
    {int j; j = (int)(2); }
    {int cnt; cnt = (int)(2); }
    {void * tlv3; tlv3 = (void *)(2); }
    {int tlv2; tlv2 = (int)(2); }
    {cgc_size_t tlv1; tlv1 = (cgc_size_t)(2); }
    {char * tlv5; tlv5 = (char *)(2); }
}
void fix_ingred_main_2_2(){
fix_ingred_main_2_2_3();
fix_ingred_main_2_2_4();
}
void fix_ingred_main_2_3_5(){
int i;
    bzero(&i,sizeof(int));
    {char msg [ 2048 ]; msg [ ( 2048 )-1 ] = (char)(i); }
    {int j; j = (int)(i); }
    {int cnt; cnt = (int)(i); }
    {void * tlv3; tlv3 = (void *)(i); }
    {int tlv2; tlv2 = (int)(i); }
    {cgc_size_t tlv1; tlv1 = (cgc_size_t)(i); }
    {char * tlv5; tlv5 = (char *)(i); }
}
void fix_ingred_main_2_3_6(){
int i;
    bzero(&i,sizeof(int));
    {char msg [ 2048 ]; msg [ ( 2048 )-1 ] = (char)(33); }
    {int i; i = (int)(33); }
    {int j; j = (int)(33); }
    {int cnt; cnt = (int)(33); }
    {void * tlv3; tlv3 = (void *)(33); }
    {int tlv2; tlv2 = (int)(33); }
    {cgc_size_t tlv1; tlv1 = (cgc_size_t)(33); }
    {char * tlv5; tlv5 = (char *)(33); }
}
void fix_ingred_main_2_3(){
fix_ingred_main_2_3_5();
fix_ingred_main_2_3_6();
}
void fix_ingred_main_2_6_0(){
char msg [ 2048 ];
    bzero(&msg,( 2048 *sizeof(char) ) );
int cnt;
    bzero(&cnt,sizeof(int));
    {if (msg){    cnt = 0;
         char msg [ 2048 ]; msg [ ( 2048 )-1 ] = (char)(& msg [ cnt ]); }}
    {if (msg){    cnt = 0;
         int i; i = (int)(& msg [ cnt ]); }}
    {if (msg){    cnt = 0;
         int j; j = (int)(& msg [ cnt ]); }}
    {if (msg){    cnt = 0;
         void * tlv3; tlv3 = (void *)(& msg [ cnt ]); }}
    {if (msg){    cnt = 0;
         int tlv2; tlv2 = (int)(& msg [ cnt ]); }}
    {if (msg){    cnt = 0;
         cgc_size_t tlv1; tlv1 = (cgc_size_t)(& msg [ cnt ]); }}
    {if (msg){    cnt = 0;
         char * tlv5; tlv5 = (char *)(& msg [ cnt ]); }}
}
void fix_ingred_main_2_6(){
fix_ingred_main_2_6_0();
}
void fix_ingred_main_2(){
fix_ingred_main_2_0();
fix_ingred_main_2_1();
fix_ingred_main_2_2();
fix_ingred_main_2_3();
fix_ingred_main_2_6();
}
void fix_ingred_main_3_1_0(){
    {char comment [ 2048 ]; comment [ ( 2048 )-1 ] = (char)(STDOUT); }
    {int tlv1; tlv1 = (int)(STDOUT); }
    {int tlv3; tlv3 = (int)(STDOUT); }
    {int tlv5; tlv5 = (int)(STDOUT); }
    {int tlv7; tlv7 = (int)(STDOUT); }
    {int tlv9; tlv9 = (int)(STDOUT); }
    {int tlv13; tlv13 = (int)(STDOUT); }
    {char * tlv12; tlv12 = (char *)(STDOUT); }
    {cgc_size_t tlv11; tlv11 = (cgc_size_t)(STDOUT); }
    {char tlv10; tlv10 = (char)(STDOUT); }
}
void fix_ingred_main_3_1(){
fix_ingred_main_3_1_0();
}
void fix_ingred_main_3_5_0(){
char comment [ 2048 ];
    bzero(&comment,( 2048 *sizeof(char) ) );
    {char comment [ 2048 ]; comment [ ( 2048 )-1 ] = (char)(STDIN); }
    {int tlv3; tlv3 = (int)(STDIN); }
    {int tlv5; tlv5 = (int)(STDIN); }
    {int tlv9; tlv9 = (int)(STDIN); }
    {int tlv13; tlv13 = (int)(STDIN); }
    {char * tlv12; tlv12 = (char *)(STDIN); }
    {cgc_size_t tlv11; tlv11 = (cgc_size_t)(STDIN); }
    {char tlv10; tlv10 = (char)(STDIN); }
}
void fix_ingred_main_3_5_1(){
char comment [ 2048 ];
    bzero(&comment,( 2048 *sizeof(char) ) );
    {char comment [ 2048 ]; comment [ ( 2048 )-1 ] = (char)(comment); }
    {int tlv1; tlv1 = (int)(comment); }
    {int tlv3; tlv3 = (int)(comment); }
    {int tlv5; tlv5 = (int)(comment); }
    {int tlv7; tlv7 = (int)(comment); }
    {int tlv9; tlv9 = (int)(comment); }
    {int tlv13; tlv13 = (int)(comment); }
    {char * tlv12; tlv12 = (char *)(comment); }
    {cgc_size_t tlv11; tlv11 = (cgc_size_t)(comment); }
    {char tlv10; tlv10 = (char)(comment); }
}
void fix_ingred_main_3_5_2(){
char comment [ 2048 ];
    bzero(&comment,( 2048 *sizeof(char) ) );
    {char comment [ 2048 ]; comment [ ( 2048 )-1 ] = (char)(sizeof ( comment )); }
    {int tlv1; tlv1 = (int)(sizeof ( comment )); }
    {int tlv3; tlv3 = (int)(sizeof ( comment )); }
    {int tlv5; tlv5 = (int)(sizeof ( comment )); }
    {int tlv7; tlv7 = (int)(sizeof ( comment )); }
    {int tlv9; tlv9 = (int)(sizeof ( comment )); }
    {int tlv13; tlv13 = (int)(sizeof ( comment )); }
    {char * tlv12; tlv12 = (char *)(sizeof ( comment )); }
    {cgc_size_t tlv11; tlv11 = (cgc_size_t)(sizeof ( comment )); }
    {char tlv10; tlv10 = (char)(sizeof ( comment )); }
}
void fix_ingred_main_3_5_3(){
char comment [ 2048 ];
    bzero(&comment,( 2048 *sizeof(char) ) );
    {char comment [ 2048 ]; comment [ ( 2048 )-1 ] = (char)('\n'); }
    {int tlv3; tlv3 = (int)('\n'); }
    {int tlv5; tlv5 = (int)('\n'); }
    {int tlv9; tlv9 = (int)('\n'); }
    {int tlv13; tlv13 = (int)('\n'); }
    {char * tlv12; tlv12 = (char *)('\n'); }
    {cgc_size_t tlv11; tlv11 = (cgc_size_t)('\n'); }
    {char tlv10; tlv10 = (char)('\n'); }
}
void fix_ingred_main_3_5(){
fix_ingred_main_3_5_0();
fix_ingred_main_3_5_1();
fix_ingred_main_3_5_2();
fix_ingred_main_3_5_3();
}
void fix_ingred_main_3_6_1(){
int tlv1;
    bzero(&tlv1,sizeof(int));
    {char comment [ 2048 ]; comment [ ( 2048 )-1 ] = (char)(tlv1); }
    {int tlv3; tlv3 = (int)(tlv1); }
    {int tlv9; tlv9 = (int)(tlv1); }
    {int tlv13; tlv13 = (int)(tlv1); }
    {char * tlv12; tlv12 = (char *)(tlv1); }
    {cgc_size_t tlv11; tlv11 = (cgc_size_t)(tlv1); }
    {char tlv10; tlv10 = (char)(tlv1); }
}
void fix_ingred_main_3_6_2(){
int tlv1;
    bzero(&tlv1,sizeof(int));
    {char comment [ 2048 ]; comment [ ( 2048 )-1 ] = (char)(0); }
    {int tlv3; tlv3 = (int)(0); }
    {int tlv9; tlv9 = (int)(0); }
    {int tlv13; tlv13 = (int)(0); }
    {char * tlv12; tlv12 = (char *)(0); }
    {cgc_size_t tlv11; tlv11 = (cgc_size_t)(0); }
    {char tlv10; tlv10 = (char)(0); }
}
void fix_ingred_main_3_6(){
fix_ingred_main_3_6_1();
fix_ingred_main_3_6_2();
}
void fix_ingred_main_3(){
fix_ingred_main_3_1();
fix_ingred_main_3_5();
fix_ingred_main_3_6();
}
void fix_ingred_main_4_0_0(){
unsigned int num;
    bzero(&num,sizeof(unsigned int));
unsigned short lfsr;
    bzero(&lfsr,sizeof(unsigned short));
    {unsigned short lfsr; lfsr = (unsigned short)(( ( num & 0x00FF0000 ) >> 16 ) | ( ( num & 0x000000FF ) << 8 )); }
    {char buf [ 32 ]; buf [ ( 32 )-1 ] = (char)(( ( num & 0x00FF0000 ) >> 16 ) | ( ( num & 0x000000FF ) << 8 )); }
    {int tlv1; tlv1 = (int)(( ( num & 0x00FF0000 ) >> 16 ) | ( ( num & 0x000000FF ) << 8 )); }
    {int tlv3; tlv3 = (int)(( ( num & 0x00FF0000 ) >> 16 ) | ( ( num & 0x000000FF ) << 8 )); }
    {int tlv5; tlv5 = (int)(( ( num & 0x00FF0000 ) >> 16 ) | ( ( num & 0x000000FF ) << 8 )); }
    {int tlv20; tlv20 = (int)(( ( num & 0x00FF0000 ) >> 16 ) | ( ( num & 0x000000FF ) << 8 )); }
    {char * tlv19; tlv19 = (char *)(( ( num & 0x00FF0000 ) >> 16 ) | ( ( num & 0x000000FF ) << 8 )); }
    {cgc_size_t tlv18; tlv18 = (cgc_size_t)(( ( num & 0x00FF0000 ) >> 16 ) | ( ( num & 0x000000FF ) << 8 )); }
    {char tlv17; tlv17 = (char)(( ( num & 0x00FF0000 ) >> 16 ) | ( ( num & 0x000000FF ) << 8 )); }
    {int tlv21; tlv21 = (int)(( ( num & 0x00FF0000 ) >> 16 ) | ( ( num & 0x000000FF ) << 8 )); }
    {void * tlv8; tlv8 = (void *)(( ( num & 0x00FF0000 ) >> 16 ) | ( ( num & 0x000000FF ) << 8 )); }
    {int tlv7; tlv7 = (int)(( ( num & 0x00FF0000 ) >> 16 ) | ( ( num & 0x000000FF ) << 8 )); }
    {cgc_size_t tlv6; tlv6 = (cgc_size_t)(( ( num & 0x00FF0000 ) >> 16 ) | ( ( num & 0x000000FF ) << 8 )); }
    {void * tlv11; tlv11 = (void *)(( ( num & 0x00FF0000 ) >> 16 ) | ( ( num & 0x000000FF ) << 8 )); }
    {int tlv10; tlv10 = (int)(( ( num & 0x00FF0000 ) >> 16 ) | ( ( num & 0x000000FF ) << 8 )); }
    {cgc_size_t tlv9; tlv9 = (cgc_size_t)(( ( num & 0x00FF0000 ) >> 16 ) | ( ( num & 0x000000FF ) << 8 )); }
    {char * tlv13; tlv13 = (char *)(( ( num & 0x00FF0000 ) >> 16 ) | ( ( num & 0x000000FF ) << 8 )); }
    {void * tlv16; tlv16 = (void *)(( ( num & 0x00FF0000 ) >> 16 ) | ( ( num & 0x000000FF ) << 8 )); }
    {int tlv15; tlv15 = (int)(( ( num & 0x00FF0000 ) >> 16 ) | ( ( num & 0x000000FF ) << 8 )); }
    {cgc_size_t tlv14; tlv14 = (cgc_size_t)(( ( num & 0x00FF0000 ) >> 16 ) | ( ( num & 0x000000FF ) << 8 )); }
}
void fix_ingred_main_4_0_1(){
unsigned int num;
    bzero(&num,sizeof(unsigned int));
unsigned short lfsr;
    bzero(&lfsr,sizeof(unsigned short));
    {unsigned int num; num = (unsigned int)(( ( lfsr >> 0 ) ^ ( lfsr >> 2 ) ^ ( lfsr >> 3 ) ^ ( lfsr >> 5 ) ) & 1); }
    {char buf [ 32 ]; buf [ ( 32 )-1 ] = (char)(( ( lfsr >> 0 ) ^ ( lfsr >> 2 ) ^ ( lfsr >> 3 ) ^ ( lfsr >> 5 ) ) & 1); }
    {int tlv1; tlv1 = (int)(( ( lfsr >> 0 ) ^ ( lfsr >> 2 ) ^ ( lfsr >> 3 ) ^ ( lfsr >> 5 ) ) & 1); }
    {int tlv3; tlv3 = (int)(( ( lfsr >> 0 ) ^ ( lfsr >> 2 ) ^ ( lfsr >> 3 ) ^ ( lfsr >> 5 ) ) & 1); }
    {int tlv5; tlv5 = (int)(( ( lfsr >> 0 ) ^ ( lfsr >> 2 ) ^ ( lfsr >> 3 ) ^ ( lfsr >> 5 ) ) & 1); }
    {int tlv20; tlv20 = (int)(( ( lfsr >> 0 ) ^ ( lfsr >> 2 ) ^ ( lfsr >> 3 ) ^ ( lfsr >> 5 ) ) & 1); }
    {char * tlv19; tlv19 = (char *)(( ( lfsr >> 0 ) ^ ( lfsr >> 2 ) ^ ( lfsr >> 3 ) ^ ( lfsr >> 5 ) ) & 1); }
    {cgc_size_t tlv18; tlv18 = (cgc_size_t)(( ( lfsr >> 0 ) ^ ( lfsr >> 2 ) ^ ( lfsr >> 3 ) ^ ( lfsr >> 5 ) ) & 1); }
    {char tlv17; tlv17 = (char)(( ( lfsr >> 0 ) ^ ( lfsr >> 2 ) ^ ( lfsr >> 3 ) ^ ( lfsr >> 5 ) ) & 1); }
    {int tlv21; tlv21 = (int)(( ( lfsr >> 0 ) ^ ( lfsr >> 2 ) ^ ( lfsr >> 3 ) ^ ( lfsr >> 5 ) ) & 1); }
    {void * tlv8; tlv8 = (void *)(( ( lfsr >> 0 ) ^ ( lfsr >> 2 ) ^ ( lfsr >> 3 ) ^ ( lfsr >> 5 ) ) & 1); }
    {int tlv7; tlv7 = (int)(( ( lfsr >> 0 ) ^ ( lfsr >> 2 ) ^ ( lfsr >> 3 ) ^ ( lfsr >> 5 ) ) & 1); }
    {cgc_size_t tlv6; tlv6 = (cgc_size_t)(( ( lfsr >> 0 ) ^ ( lfsr >> 2 ) ^ ( lfsr >> 3 ) ^ ( lfsr >> 5 ) ) & 1); }
    {void * tlv11; tlv11 = (void *)(( ( lfsr >> 0 ) ^ ( lfsr >> 2 ) ^ ( lfsr >> 3 ) ^ ( lfsr >> 5 ) ) & 1); }
    {int tlv10; tlv10 = (int)(( ( lfsr >> 0 ) ^ ( lfsr >> 2 ) ^ ( lfsr >> 3 ) ^ ( lfsr >> 5 ) ) & 1); }
    {cgc_size_t tlv9; tlv9 = (cgc_size_t)(( ( lfsr >> 0 ) ^ ( lfsr >> 2 ) ^ ( lfsr >> 3 ) ^ ( lfsr >> 5 ) ) & 1); }
    {char * tlv13; tlv13 = (char *)(( ( lfsr >> 0 ) ^ ( lfsr >> 2 ) ^ ( lfsr >> 3 ) ^ ( lfsr >> 5 ) ) & 1); }
    {void * tlv16; tlv16 = (void *)(( ( lfsr >> 0 ) ^ ( lfsr >> 2 ) ^ ( lfsr >> 3 ) ^ ( lfsr >> 5 ) ) & 1); }
    {int tlv15; tlv15 = (int)(( ( lfsr >> 0 ) ^ ( lfsr >> 2 ) ^ ( lfsr >> 3 ) ^ ( lfsr >> 5 ) ) & 1); }
    {cgc_size_t tlv14; tlv14 = (cgc_size_t)(( ( lfsr >> 0 ) ^ ( lfsr >> 2 ) ^ ( lfsr >> 3 ) ^ ( lfsr >> 5 ) ) & 1); }
}
void fix_ingred_main_4_0_2(){
unsigned int num;
    bzero(&num,sizeof(unsigned int));
unsigned short lfsr;
    bzero(&lfsr,sizeof(unsigned short));
    {char buf [ 32 ]; buf [ ( 32 )-1 ] = (char)(( lfsr >> 1 ) | ( num << 15 )); }
    {int tlv1; tlv1 = (int)(( lfsr >> 1 ) | ( num << 15 )); }
    {int tlv3; tlv3 = (int)(( lfsr >> 1 ) | ( num << 15 )); }
    {int tlv5; tlv5 = (int)(( lfsr >> 1 ) | ( num << 15 )); }
    {int tlv20; tlv20 = (int)(( lfsr >> 1 ) | ( num << 15 )); }
    {char * tlv19; tlv19 = (char *)(( lfsr >> 1 ) | ( num << 15 )); }
    {cgc_size_t tlv18; tlv18 = (cgc_size_t)(( lfsr >> 1 ) | ( num << 15 )); }
    {char tlv17; tlv17 = (char)(( lfsr >> 1 ) | ( num << 15 )); }
    {int tlv21; tlv21 = (int)(( lfsr >> 1 ) | ( num << 15 )); }
    {void * tlv8; tlv8 = (void *)(( lfsr >> 1 ) | ( num << 15 )); }
    {int tlv7; tlv7 = (int)(( lfsr >> 1 ) | ( num << 15 )); }
    {cgc_size_t tlv6; tlv6 = (cgc_size_t)(( lfsr >> 1 ) | ( num << 15 )); }
    {void * tlv11; tlv11 = (void *)(( lfsr >> 1 ) | ( num << 15 )); }
    {int tlv10; tlv10 = (int)(( lfsr >> 1 ) | ( num << 15 )); }
    {cgc_size_t tlv9; tlv9 = (cgc_size_t)(( lfsr >> 1 ) | ( num << 15 )); }
    {char * tlv13; tlv13 = (char *)(( lfsr >> 1 ) | ( num << 15 )); }
    {void * tlv16; tlv16 = (void *)(( lfsr >> 1 ) | ( num << 15 )); }
    {int tlv15; tlv15 = (int)(( lfsr >> 1 ) | ( num << 15 )); }
    {cgc_size_t tlv14; tlv14 = (cgc_size_t)(( lfsr >> 1 ) | ( num << 15 )); }
}
void fix_ingred_main_4_0(){
fix_ingred_main_4_0_0();
fix_ingred_main_4_0_1();
fix_ingred_main_4_0_2();
}
void fix_ingred_main_4_1_0(){
    {unsigned short lfsr; lfsr = (unsigned short)(STDOUT); }
    {unsigned int num; num = (unsigned int)(STDOUT); }
    {char buf [ 32 ]; buf [ ( 32 )-1 ] = (char)(STDOUT); }
    {int tlv20; tlv20 = (int)(STDOUT); }
    {char * tlv19; tlv19 = (char *)(STDOUT); }
    {cgc_size_t tlv18; tlv18 = (cgc_size_t)(STDOUT); }
    {char tlv17; tlv17 = (char)(STDOUT); }
    {int tlv21; tlv21 = (int)(STDOUT); }
    {void * tlv8; tlv8 = (void *)(STDOUT); }
    {cgc_size_t tlv6; tlv6 = (cgc_size_t)(STDOUT); }
    {void * tlv11; tlv11 = (void *)(STDOUT); }
    {int tlv10; tlv10 = (int)(STDOUT); }
    {cgc_size_t tlv9; tlv9 = (cgc_size_t)(STDOUT); }
    {char * tlv13; tlv13 = (char *)(STDOUT); }
    {void * tlv16; tlv16 = (void *)(STDOUT); }
    {int tlv15; tlv15 = (int)(STDOUT); }
    {cgc_size_t tlv14; tlv14 = (cgc_size_t)(STDOUT); }
}
void fix_ingred_main_4_1(){
fix_ingred_main_4_1_0();
}
void fix_ingred_main_4_3_0(){
char buf [ 32 ];
    bzero(&buf,( 32 *sizeof(char) ) );
    {unsigned short lfsr; lfsr = (unsigned short)(STDIN); }
    {unsigned int num; num = (unsigned int)(STDIN); }
    {char buf [ 32 ]; buf [ ( 32 )-1 ] = (char)(STDIN); }
    {int tlv20; tlv20 = (int)(STDIN); }
    {char * tlv19; tlv19 = (char *)(STDIN); }
    {cgc_size_t tlv18; tlv18 = (cgc_size_t)(STDIN); }
    {char tlv17; tlv17 = (char)(STDIN); }
    {int tlv21; tlv21 = (int)(STDIN); }
    {void * tlv8; tlv8 = (void *)(STDIN); }
    {cgc_size_t tlv6; tlv6 = (cgc_size_t)(STDIN); }
    {void * tlv11; tlv11 = (void *)(STDIN); }
    {int tlv10; tlv10 = (int)(STDIN); }
    {cgc_size_t tlv9; tlv9 = (cgc_size_t)(STDIN); }
    {char * tlv13; tlv13 = (char *)(STDIN); }
    {void * tlv16; tlv16 = (void *)(STDIN); }
    {int tlv15; tlv15 = (int)(STDIN); }
    {cgc_size_t tlv14; tlv14 = (cgc_size_t)(STDIN); }
}
void fix_ingred_main_4_3_1(){
char buf [ 32 ];
    bzero(&buf,( 32 *sizeof(char) ) );
    {unsigned short lfsr; lfsr = (unsigned short)(buf); }
    {unsigned int num; num = (unsigned int)(buf); }
    {char buf [ 32 ]; buf [ ( 32 )-1 ] = (char)(buf); }
    {int tlv3; tlv3 = (int)(buf); }
    {int tlv20; tlv20 = (int)(buf); }
    {char * tlv19; tlv19 = (char *)(buf); }
    {cgc_size_t tlv18; tlv18 = (cgc_size_t)(buf); }
    {char tlv17; tlv17 = (char)(buf); }
    {int tlv21; tlv21 = (int)(buf); }
    {void * tlv8; tlv8 = (void *)(buf); }
    {cgc_size_t tlv6; tlv6 = (cgc_size_t)(buf); }
    {void * tlv11; tlv11 = (void *)(buf); }
    {int tlv10; tlv10 = (int)(buf); }
    {cgc_size_t tlv9; tlv9 = (cgc_size_t)(buf); }
    {char * tlv13; tlv13 = (char *)(buf); }
    {void * tlv16; tlv16 = (void *)(buf); }
    {int tlv15; tlv15 = (int)(buf); }
    {cgc_size_t tlv14; tlv14 = (cgc_size_t)(buf); }
}
void fix_ingred_main_4_3_2(){
char buf [ 32 ];
    bzero(&buf,( 32 *sizeof(char) ) );
    {unsigned short lfsr; lfsr = (unsigned short)(sizeof ( buf )); }
    {unsigned int num; num = (unsigned int)(sizeof ( buf )); }
    {char buf [ 32 ]; buf [ ( 32 )-1 ] = (char)(sizeof ( buf )); }
    {int tlv1; tlv1 = (int)(sizeof ( buf )); }
    {int tlv3; tlv3 = (int)(sizeof ( buf )); }
    {int tlv5; tlv5 = (int)(sizeof ( buf )); }
    {int tlv20; tlv20 = (int)(sizeof ( buf )); }
    {char * tlv19; tlv19 = (char *)(sizeof ( buf )); }
    {cgc_size_t tlv18; tlv18 = (cgc_size_t)(sizeof ( buf )); }
    {char tlv17; tlv17 = (char)(sizeof ( buf )); }
    {int tlv21; tlv21 = (int)(sizeof ( buf )); }
    {void * tlv8; tlv8 = (void *)(sizeof ( buf )); }
    {int tlv7; tlv7 = (int)(sizeof ( buf )); }
    {cgc_size_t tlv6; tlv6 = (cgc_size_t)(sizeof ( buf )); }
    {void * tlv11; tlv11 = (void *)(sizeof ( buf )); }
    {int tlv10; tlv10 = (int)(sizeof ( buf )); }
    {cgc_size_t tlv9; tlv9 = (cgc_size_t)(sizeof ( buf )); }
    {char * tlv13; tlv13 = (char *)(sizeof ( buf )); }
    {void * tlv16; tlv16 = (void *)(sizeof ( buf )); }
    {int tlv15; tlv15 = (int)(sizeof ( buf )); }
    {cgc_size_t tlv14; tlv14 = (cgc_size_t)(sizeof ( buf )); }
}
void fix_ingred_main_4_3_3(){
char buf [ 32 ];
    bzero(&buf,( 32 *sizeof(char) ) );
    {unsigned short lfsr; lfsr = (unsigned short)('\n'); }
    {unsigned int num; num = (unsigned int)('\n'); }
    {char buf [ 32 ]; buf [ ( 32 )-1 ] = (char)('\n'); }
    {int tlv20; tlv20 = (int)('\n'); }
    {char * tlv19; tlv19 = (char *)('\n'); }
    {cgc_size_t tlv18; tlv18 = (cgc_size_t)('\n'); }
    {char tlv17; tlv17 = (char)('\n'); }
    {int tlv21; tlv21 = (int)('\n'); }
    {void * tlv8; tlv8 = (void *)('\n'); }
    {cgc_size_t tlv6; tlv6 = (cgc_size_t)('\n'); }
    {void * tlv11; tlv11 = (void *)('\n'); }
    {int tlv10; tlv10 = (int)('\n'); }
    {cgc_size_t tlv9; tlv9 = (cgc_size_t)('\n'); }
    {char * tlv13; tlv13 = (char *)('\n'); }
    {void * tlv16; tlv16 = (void *)('\n'); }
    {int tlv15; tlv15 = (int)('\n'); }
    {cgc_size_t tlv14; tlv14 = (cgc_size_t)('\n'); }
}
void fix_ingred_main_4_3(){
fix_ingred_main_4_3_0();
fix_ingred_main_4_3_1();
fix_ingred_main_4_3_2();
fix_ingred_main_4_3_3();
}
void fix_ingred_main_4_4_0(){
int tlv1;
    bzero(&tlv1,sizeof(int));
    {unsigned short lfsr; lfsr = (unsigned short)(tlv1); }
    {unsigned int num; num = (unsigned int)(tlv1); }
    {char buf [ 32 ]; buf [ ( 32 )-1 ] = (char)(tlv1); }
    {int tlv20; tlv20 = (int)(tlv1); }
    {char * tlv19; tlv19 = (char *)(tlv1); }
    {cgc_size_t tlv18; tlv18 = (cgc_size_t)(tlv1); }
    {char tlv17; tlv17 = (char)(tlv1); }
    {int tlv21; tlv21 = (int)(tlv1); }
    {void * tlv8; tlv8 = (void *)(tlv1); }
    {cgc_size_t tlv6; tlv6 = (cgc_size_t)(tlv1); }
    {void * tlv11; tlv11 = (void *)(tlv1); }
    {int tlv10; tlv10 = (int)(tlv1); }
    {cgc_size_t tlv9; tlv9 = (cgc_size_t)(tlv1); }
    {char * tlv13; tlv13 = (char *)(tlv1); }
    {void * tlv16; tlv16 = (void *)(tlv1); }
    {int tlv15; tlv15 = (int)(tlv1); }
    {cgc_size_t tlv14; tlv14 = (cgc_size_t)(tlv1); }
}
void fix_ingred_main_4_4_1(){
int tlv1;
    bzero(&tlv1,sizeof(int));
    {unsigned short lfsr; lfsr = (unsigned short)(0); }
    {unsigned int num; num = (unsigned int)(0); }
    {char buf [ 32 ]; buf [ ( 32 )-1 ] = (char)(0); }
    {int tlv20; tlv20 = (int)(0); }
    {char * tlv19; tlv19 = (char *)(0); }
    {cgc_size_t tlv18; tlv18 = (cgc_size_t)(0); }
    {char tlv17; tlv17 = (char)(0); }
    {int tlv21; tlv21 = (int)(0); }
    {void * tlv8; tlv8 = (void *)(0); }
    {cgc_size_t tlv6; tlv6 = (cgc_size_t)(0); }
    {void * tlv11; tlv11 = (void *)(0); }
    {int tlv10; tlv10 = (int)(0); }
    {cgc_size_t tlv9; tlv9 = (cgc_size_t)(0); }
    {char * tlv13; tlv13 = (char *)(0); }
    {void * tlv16; tlv16 = (void *)(0); }
    {int tlv15; tlv15 = (int)(0); }
    {cgc_size_t tlv14; tlv14 = (cgc_size_t)(0); }
}
void fix_ingred_main_4_4(){
fix_ingred_main_4_4_0();
fix_ingred_main_4_4_1();
}
void fix_ingred_main_4_5_1(){
    {unsigned short lfsr; lfsr = (unsigned short)(10); }
    {unsigned int num; num = (unsigned int)(10); }
    {char buf [ 32 ]; buf [ ( 32 )-1 ] = (char)(10); }
    {int tlv1; tlv1 = (int)(10); }
    {int tlv3; tlv3 = (int)(10); }
    {int tlv5; tlv5 = (int)(10); }
    {int tlv20; tlv20 = (int)(10); }
    {char * tlv19; tlv19 = (char *)(10); }
    {cgc_size_t tlv18; tlv18 = (cgc_size_t)(10); }
    {char tlv17; tlv17 = (char)(10); }
    {int tlv21; tlv21 = (int)(10); }
    {void * tlv8; tlv8 = (void *)(10); }
    {int tlv7; tlv7 = (int)(10); }
    {cgc_size_t tlv6; tlv6 = (cgc_size_t)(10); }
    {void * tlv11; tlv11 = (void *)(10); }
    {int tlv10; tlv10 = (int)(10); }
    {cgc_size_t tlv9; tlv9 = (cgc_size_t)(10); }
    {char * tlv13; tlv13 = (char *)(10); }
    {void * tlv16; tlv16 = (void *)(10); }
    {int tlv15; tlv15 = (int)(10); }
    {cgc_size_t tlv14; tlv14 = (cgc_size_t)(10); }
}
void fix_ingred_main_4_5(){
fix_ingred_main_4_5_1();
}
void fix_ingred_main_4_6_0(){
unsigned short lfsr;
    bzero(&lfsr,sizeof(unsigned short));
    {unsigned short lfsr; lfsr = (unsigned short)(0xACE1u); }
    {unsigned int num; num = (unsigned int)(0xACE1u); }
    {char buf [ 32 ]; buf [ ( 32 )-1 ] = (char)(0xACE1u); }
    {int tlv1; tlv1 = (int)(0xACE1u); }
    {int tlv3; tlv3 = (int)(0xACE1u); }
    {int tlv5; tlv5 = (int)(0xACE1u); }
    {int tlv20; tlv20 = (int)(0xACE1u); }
    {char * tlv19; tlv19 = (char *)(0xACE1u); }
    {cgc_size_t tlv18; tlv18 = (cgc_size_t)(0xACE1u); }
    {char tlv17; tlv17 = (char)(0xACE1u); }
    {int tlv21; tlv21 = (int)(0xACE1u); }
    {void * tlv8; tlv8 = (void *)(0xACE1u); }
    {int tlv7; tlv7 = (int)(0xACE1u); }
    {cgc_size_t tlv6; tlv6 = (cgc_size_t)(0xACE1u); }
    {void * tlv11; tlv11 = (void *)(0xACE1u); }
    {int tlv10; tlv10 = (int)(0xACE1u); }
    {cgc_size_t tlv9; tlv9 = (cgc_size_t)(0xACE1u); }
    {char * tlv13; tlv13 = (char *)(0xACE1u); }
    {void * tlv16; tlv16 = (void *)(0xACE1u); }
    {int tlv15; tlv15 = (int)(0xACE1u); }
    {cgc_size_t tlv14; tlv14 = (cgc_size_t)(0xACE1u); }
}
void fix_ingred_main_4_6_2(){
unsigned short lfsr;
    bzero(&lfsr,sizeof(unsigned short));
    {unsigned int num; num = (unsigned int)(lfsr); }
    {char buf [ 32 ]; buf [ ( 32 )-1 ] = (char)(lfsr); }
    {int tlv1; tlv1 = (int)(lfsr); }
    {int tlv3; tlv3 = (int)(lfsr); }
    {int tlv5; tlv5 = (int)(lfsr); }
    {int tlv20; tlv20 = (int)(lfsr); }
    {char * tlv19; tlv19 = (char *)(lfsr); }
    {cgc_size_t tlv18; tlv18 = (cgc_size_t)(lfsr); }
    {char tlv17; tlv17 = (char)(lfsr); }
    {int tlv21; tlv21 = (int)(lfsr); }
    {void * tlv8; tlv8 = (void *)(lfsr); }
    {int tlv7; tlv7 = (int)(lfsr); }
    {cgc_size_t tlv6; tlv6 = (cgc_size_t)(lfsr); }
    {void * tlv11; tlv11 = (void *)(lfsr); }
    {int tlv10; tlv10 = (int)(lfsr); }
    {cgc_size_t tlv9; tlv9 = (cgc_size_t)(lfsr); }
    {char * tlv13; tlv13 = (char *)(lfsr); }
    {void * tlv16; tlv16 = (void *)(lfsr); }
    {int tlv15; tlv15 = (int)(lfsr); }
    {cgc_size_t tlv14; tlv14 = (cgc_size_t)(lfsr); }
}
void fix_ingred_main_4_6_3(){
unsigned short lfsr;
    bzero(&lfsr,sizeof(unsigned short));
    {unsigned short lfsr; lfsr = (unsigned short)(0); }
    {unsigned int num; num = (unsigned int)(0); }
    {char buf [ 32 ]; buf [ ( 32 )-1 ] = (char)(0); }
    {int tlv1; tlv1 = (int)(0); }
    {int tlv3; tlv3 = (int)(0); }
    {int tlv5; tlv5 = (int)(0); }
    {int tlv20; tlv20 = (int)(0); }
    {char * tlv19; tlv19 = (char *)(0); }
    {cgc_size_t tlv18; tlv18 = (cgc_size_t)(0); }
    {char tlv17; tlv17 = (char)(0); }
    {int tlv21; tlv21 = (int)(0); }
    {void * tlv8; tlv8 = (void *)(0); }
    {int tlv7; tlv7 = (int)(0); }
    {cgc_size_t tlv6; tlv6 = (cgc_size_t)(0); }
    {void * tlv11; tlv11 = (void *)(0); }
    {int tlv10; tlv10 = (int)(0); }
    {cgc_size_t tlv9; tlv9 = (cgc_size_t)(0); }
    {char * tlv13; tlv13 = (char *)(0); }
    {void * tlv16; tlv16 = (void *)(0); }
    {int tlv15; tlv15 = (int)(0); }
    {cgc_size_t tlv14; tlv14 = (cgc_size_t)(0); }
}
void fix_ingred_main_4_6(){
fix_ingred_main_4_6_0();
fix_ingred_main_4_6_2();
fix_ingred_main_4_6_3();
}
void fix_ingred_main_4_7_0(){
hackman_state_t h_state_ref;
    bzero(&h_state_ref,1*sizeof(hackman_state_t));
hackman_state_t * h_state = &h_state_ref;
    {unsigned short lfsr; lfsr = (unsigned short)(h_state -> word); }
    {unsigned int num; num = (unsigned int)(h_state -> word); }
    {char buf [ 32 ]; buf [ ( 32 )-1 ] = (char)(h_state -> word); }
    {int tlv1; tlv1 = (int)(h_state -> word); }
    {int tlv3; tlv3 = (int)(h_state -> word); }
    {int tlv5; tlv5 = (int)(h_state -> word); }
    {int tlv20; tlv20 = (int)(h_state -> word); }
    {char * tlv19; tlv19 = (char *)(h_state -> word); }
    {cgc_size_t tlv18; tlv18 = (cgc_size_t)(h_state -> word); }
    {char tlv17; tlv17 = (char)(h_state -> word); }
    {int tlv21; tlv21 = (int)(h_state -> word); }
    {void * tlv8; tlv8 = (void *)(h_state -> word); }
    {int tlv7; tlv7 = (int)(h_state -> word); }
    {cgc_size_t tlv6; tlv6 = (cgc_size_t)(h_state -> word); }
    {void * tlv11; tlv11 = (void *)(h_state -> word); }
    {int tlv10; tlv10 = (int)(h_state -> word); }
    {cgc_size_t tlv9; tlv9 = (cgc_size_t)(h_state -> word); }
    {char * tlv13; tlv13 = (char *)(h_state -> word); }
    {void * tlv16; tlv16 = (void *)(h_state -> word); }
    {int tlv15; tlv15 = (int)(h_state -> word); }
    {cgc_size_t tlv14; tlv14 = (cgc_size_t)(h_state -> word); }
}
void fix_ingred_main_4_7_2(){
hackman_state_t h_state_ref;
    bzero(&h_state_ref,1*sizeof(hackman_state_t));
hackman_state_t * h_state = &h_state_ref;
    {unsigned short lfsr; lfsr = (unsigned short)(sizeof ( h_state -> word )); }
    {unsigned int num; num = (unsigned int)(sizeof ( h_state -> word )); }
    {char buf [ 32 ]; buf [ ( 32 )-1 ] = (char)(sizeof ( h_state -> word )); }
    {int tlv1; tlv1 = (int)(sizeof ( h_state -> word )); }
    {int tlv3; tlv3 = (int)(sizeof ( h_state -> word )); }
    {int tlv5; tlv5 = (int)(sizeof ( h_state -> word )); }
    {int tlv20; tlv20 = (int)(sizeof ( h_state -> word )); }
    {char * tlv19; tlv19 = (char *)(sizeof ( h_state -> word )); }
    {cgc_size_t tlv18; tlv18 = (cgc_size_t)(sizeof ( h_state -> word )); }
    {char tlv17; tlv17 = (char)(sizeof ( h_state -> word )); }
    {int tlv21; tlv21 = (int)(sizeof ( h_state -> word )); }
    {void * tlv8; tlv8 = (void *)(sizeof ( h_state -> word )); }
    {int tlv7; tlv7 = (int)(sizeof ( h_state -> word )); }
    {cgc_size_t tlv6; tlv6 = (cgc_size_t)(sizeof ( h_state -> word )); }
    {void * tlv11; tlv11 = (void *)(sizeof ( h_state -> word )); }
    {int tlv10; tlv10 = (int)(sizeof ( h_state -> word )); }
    {cgc_size_t tlv9; tlv9 = (cgc_size_t)(sizeof ( h_state -> word )); }
    {char * tlv13; tlv13 = (char *)(sizeof ( h_state -> word )); }
    {void * tlv16; tlv16 = (void *)(sizeof ( h_state -> word )); }
    {int tlv15; tlv15 = (int)(sizeof ( h_state -> word )); }
    {cgc_size_t tlv14; tlv14 = (cgc_size_t)(sizeof ( h_state -> word )); }
}
void fix_ingred_main_4_7(){
fix_ingred_main_4_7_0();
fix_ingred_main_4_7_2();
}
void fix_ingred_main_4_8_0(){
hackman_state_t h_state_ref;
    bzero(&h_state_ref,1*sizeof(hackman_state_t));
hackman_state_t * h_state = &h_state_ref;
    {unsigned short lfsr; lfsr = (unsigned short)(h_state -> progress); }
    {unsigned int num; num = (unsigned int)(h_state -> progress); }
    {char buf [ 32 ]; buf [ ( 32 )-1 ] = (char)(h_state -> progress); }
    {int tlv1; tlv1 = (int)(h_state -> progress); }
    {int tlv3; tlv3 = (int)(h_state -> progress); }
    {int tlv5; tlv5 = (int)(h_state -> progress); }
    {int tlv20; tlv20 = (int)(h_state -> progress); }
    {char * tlv19; tlv19 = (char *)(h_state -> progress); }
    {cgc_size_t tlv18; tlv18 = (cgc_size_t)(h_state -> progress); }
    {char tlv17; tlv17 = (char)(h_state -> progress); }
    {int tlv21; tlv21 = (int)(h_state -> progress); }
    {void * tlv8; tlv8 = (void *)(h_state -> progress); }
    {int tlv7; tlv7 = (int)(h_state -> progress); }
    {cgc_size_t tlv6; tlv6 = (cgc_size_t)(h_state -> progress); }
    {void * tlv11; tlv11 = (void *)(h_state -> progress); }
    {int tlv10; tlv10 = (int)(h_state -> progress); }
    {cgc_size_t tlv9; tlv9 = (cgc_size_t)(h_state -> progress); }
    {char * tlv13; tlv13 = (char *)(h_state -> progress); }
    {void * tlv16; tlv16 = (void *)(h_state -> progress); }
    {int tlv15; tlv15 = (int)(h_state -> progress); }
    {cgc_size_t tlv14; tlv14 = (cgc_size_t)(h_state -> progress); }
}
void fix_ingred_main_4_8_2(){
hackman_state_t h_state_ref;
    bzero(&h_state_ref,1*sizeof(hackman_state_t));
hackman_state_t * h_state = &h_state_ref;
    {unsigned short lfsr; lfsr = (unsigned short)(sizeof ( h_state -> progress )); }
    {unsigned int num; num = (unsigned int)(sizeof ( h_state -> progress )); }
    {char buf [ 32 ]; buf [ ( 32 )-1 ] = (char)(sizeof ( h_state -> progress )); }
    {int tlv1; tlv1 = (int)(sizeof ( h_state -> progress )); }
    {int tlv3; tlv3 = (int)(sizeof ( h_state -> progress )); }
    {int tlv5; tlv5 = (int)(sizeof ( h_state -> progress )); }
    {int tlv20; tlv20 = (int)(sizeof ( h_state -> progress )); }
    {char * tlv19; tlv19 = (char *)(sizeof ( h_state -> progress )); }
    {cgc_size_t tlv18; tlv18 = (cgc_size_t)(sizeof ( h_state -> progress )); }
    {char tlv17; tlv17 = (char)(sizeof ( h_state -> progress )); }
    {int tlv21; tlv21 = (int)(sizeof ( h_state -> progress )); }
    {void * tlv8; tlv8 = (void *)(sizeof ( h_state -> progress )); }
    {int tlv7; tlv7 = (int)(sizeof ( h_state -> progress )); }
    {cgc_size_t tlv6; tlv6 = (cgc_size_t)(sizeof ( h_state -> progress )); }
    {void * tlv11; tlv11 = (void *)(sizeof ( h_state -> progress )); }
    {int tlv10; tlv10 = (int)(sizeof ( h_state -> progress )); }
    {cgc_size_t tlv9; tlv9 = (cgc_size_t)(sizeof ( h_state -> progress )); }
    {char * tlv13; tlv13 = (char *)(sizeof ( h_state -> progress )); }
    {void * tlv16; tlv16 = (void *)(sizeof ( h_state -> progress )); }
    {int tlv15; tlv15 = (int)(sizeof ( h_state -> progress )); }
    {cgc_size_t tlv14; tlv14 = (cgc_size_t)(sizeof ( h_state -> progress )); }
}
void fix_ingred_main_4_8(){
fix_ingred_main_4_8_0();
fix_ingred_main_4_8_2();
}
void fix_ingred_main_4_9_0(){
hackman_state_t h_state_ref;
    bzero(&h_state_ref,1*sizeof(hackman_state_t));
hackman_state_t * h_state = &h_state_ref;
    {unsigned short lfsr; lfsr = (unsigned short)(h_state -> word); }
    {unsigned int num; num = (unsigned int)(h_state -> word); }
    {char buf [ 32 ]; buf [ ( 32 )-1 ] = (char)(h_state -> word); }
    {int tlv1; tlv1 = (int)(h_state -> word); }
    {int tlv3; tlv3 = (int)(h_state -> word); }
    {int tlv5; tlv5 = (int)(h_state -> word); }
    {int tlv20; tlv20 = (int)(h_state -> word); }
    {char * tlv19; tlv19 = (char *)(h_state -> word); }
    {cgc_size_t tlv18; tlv18 = (cgc_size_t)(h_state -> word); }
    {char tlv17; tlv17 = (char)(h_state -> word); }
    {int tlv21; tlv21 = (int)(h_state -> word); }
    {void * tlv8; tlv8 = (void *)(h_state -> word); }
    {int tlv7; tlv7 = (int)(h_state -> word); }
    {cgc_size_t tlv6; tlv6 = (cgc_size_t)(h_state -> word); }
    {void * tlv11; tlv11 = (void *)(h_state -> word); }
    {int tlv10; tlv10 = (int)(h_state -> word); }
    {cgc_size_t tlv9; tlv9 = (cgc_size_t)(h_state -> word); }
    {char * tlv13; tlv13 = (char *)(h_state -> word); }
    {void * tlv16; tlv16 = (void *)(h_state -> word); }
    {int tlv15; tlv15 = (int)(h_state -> word); }
    {cgc_size_t tlv14; tlv14 = (cgc_size_t)(h_state -> word); }
}
void fix_ingred_main_4_9(){
fix_ingred_main_4_9_0();
}
void fix_ingred_main_4_10_1(){
    {unsigned short lfsr; lfsr = (unsigned short)('_'); }
    {unsigned int num; num = (unsigned int)('_'); }
    {char buf [ 32 ]; buf [ ( 32 )-1 ] = (char)('_'); }
    {int tlv1; tlv1 = (int)('_'); }
    {int tlv3; tlv3 = (int)('_'); }
    {int tlv5; tlv5 = (int)('_'); }
    {int tlv20; tlv20 = (int)('_'); }
    {char * tlv19; tlv19 = (char *)('_'); }
    {cgc_size_t tlv18; tlv18 = (cgc_size_t)('_'); }
    {char tlv17; tlv17 = (char)('_'); }
    {int tlv21; tlv21 = (int)('_'); }
    {void * tlv8; tlv8 = (void *)('_'); }
    {int tlv7; tlv7 = (int)('_'); }
    {cgc_size_t tlv6; tlv6 = (cgc_size_t)('_'); }
    {void * tlv11; tlv11 = (void *)('_'); }
    {int tlv10; tlv10 = (int)('_'); }
    {cgc_size_t tlv9; tlv9 = (cgc_size_t)('_'); }
    {char * tlv13; tlv13 = (char *)('_'); }
    {void * tlv16; tlv16 = (void *)('_'); }
    {int tlv15; tlv15 = (int)('_'); }
    {cgc_size_t tlv14; tlv14 = (cgc_size_t)('_'); }
}
void fix_ingred_main_4_10(){
fix_ingred_main_4_10_1();
}
void fix_ingred_main_4_11_0(){
char tlv24_ref;
    bzero(&tlv24_ref,1*sizeof(char));
const char * tlv24 = &tlv24_ref;
    {unsigned short lfsr; lfsr = (unsigned short)(cgc_strlen ( tlv24 )); }
    {unsigned int num; num = (unsigned int)(cgc_strlen ( tlv24 )); }
    {char buf [ 32 ]; buf [ ( 32 )-1 ] = (char)(cgc_strlen ( tlv24 )); }
    {int tlv1; tlv1 = (int)(cgc_strlen ( tlv24 )); }
    {int tlv3; tlv3 = (int)(cgc_strlen ( tlv24 )); }
    {int tlv5; tlv5 = (int)(cgc_strlen ( tlv24 )); }
    {int tlv20; tlv20 = (int)(cgc_strlen ( tlv24 )); }
    {char * tlv19; tlv19 = (char *)(cgc_strlen ( tlv24 )); }
    {cgc_size_t tlv18; tlv18 = (cgc_size_t)(cgc_strlen ( tlv24 )); }
    {char tlv17; tlv17 = (char)(cgc_strlen ( tlv24 )); }
    {int tlv21; tlv21 = (int)(cgc_strlen ( tlv24 )); }
    {void * tlv8; tlv8 = (void *)(cgc_strlen ( tlv24 )); }
    {int tlv7; tlv7 = (int)(cgc_strlen ( tlv24 )); }
    {cgc_size_t tlv6; tlv6 = (cgc_size_t)(cgc_strlen ( tlv24 )); }
    {void * tlv11; tlv11 = (void *)(cgc_strlen ( tlv24 )); }
    {int tlv10; tlv10 = (int)(cgc_strlen ( tlv24 )); }
    {cgc_size_t tlv9; tlv9 = (cgc_size_t)(cgc_strlen ( tlv24 )); }
    {char * tlv13; tlv13 = (char *)(cgc_strlen ( tlv24 )); }
    {void * tlv16; tlv16 = (void *)(cgc_strlen ( tlv24 )); }
    {int tlv15; tlv15 = (int)(cgc_strlen ( tlv24 )); }
    {cgc_size_t tlv14; tlv14 = (cgc_size_t)(cgc_strlen ( tlv24 )); }
}
void fix_ingred_main_4_11(){
fix_ingred_main_4_11_0();
}
void fix_ingred_main_4(){
fix_ingred_main_4_0();
fix_ingred_main_4_1();
fix_ingred_main_4_3();
fix_ingred_main_4_4();
fix_ingred_main_4_5();
fix_ingred_main_4_6();
fix_ingred_main_4_7();
fix_ingred_main_4_8();
fix_ingred_main_4_9();
fix_ingred_main_4_10();
fix_ingred_main_4_11();
}
void fix_ingred_main_5(){
}
void fix_ingred_main_6_1_0(){
    {char buf [ 128 ]; buf [ ( 128 )-1 ] = (char)(0); }
    {int found; found = (int)(0); }
    {int error; error = (int)(0); }
    {char tlv2; tlv2 = (char)(0); }
    {int tlv4; tlv4 = (int)(0); }
    {char * tlv6; tlv6 = (char *)(0); }
    {void * tlv9; tlv9 = (void *)(0); }
    {int tlv8; tlv8 = (int)(0); }
    {cgc_size_t tlv7; tlv7 = (cgc_size_t)(0); }
    {int tlv11; tlv11 = (int)(0); }
}
void fix_ingred_main_6_1(){
fix_ingred_main_6_1_0();
}
void fix_ingred_main_6_2_0(){
char tlv5_ref;
    bzero(&tlv5_ref,1*sizeof(char));
const char * tlv5 = &tlv5_ref;
    {char buf [ 128 ]; buf [ ( 128 )-1 ] = (char)(cgc_strlen ( tlv5 )); }
    {int i; i = (int)(cgc_strlen ( tlv5 )); }
    {int found; found = (int)(cgc_strlen ( tlv5 )); }
    {int error; error = (int)(cgc_strlen ( tlv5 )); }
    {cgc_size_t tlv1; tlv1 = (cgc_size_t)(cgc_strlen ( tlv5 )); }
    {char tlv2; tlv2 = (char)(cgc_strlen ( tlv5 )); }
    {int tlv4; tlv4 = (int)(cgc_strlen ( tlv5 )); }
    {char * tlv6; tlv6 = (char *)(cgc_strlen ( tlv5 )); }
    {void * tlv9; tlv9 = (void *)(cgc_strlen ( tlv5 )); }
    {int tlv8; tlv8 = (int)(cgc_strlen ( tlv5 )); }
    {cgc_size_t tlv7; tlv7 = (cgc_size_t)(cgc_strlen ( tlv5 )); }
    {int tlv11; tlv11 = (int)(cgc_strlen ( tlv5 )); }
}
void fix_ingred_main_6_2(){
fix_ingred_main_6_2_0();
}
void fix_ingred_main_6_3_1(){
cgc_size_t tlv1;
    bzero(&tlv1,sizeof(cgc_size_t));
    {char buf [ 128 ]; buf [ ( 128 )-1 ] = (char)(tlv1); }
    {int i; i = (int)(tlv1); }
    {int found; found = (int)(tlv1); }
    {int error; error = (int)(tlv1); }
    {char tlv2; tlv2 = (char)(tlv1); }
    {int tlv4; tlv4 = (int)(tlv1); }
    {char * tlv6; tlv6 = (char *)(tlv1); }
    {void * tlv9; tlv9 = (void *)(tlv1); }
    {int tlv8; tlv8 = (int)(tlv1); }
    {cgc_size_t tlv7; tlv7 = (cgc_size_t)(tlv1); }
    {int tlv11; tlv11 = (int)(tlv1); }
}
void fix_ingred_main_6_3_2(){
cgc_size_t tlv1;
    bzero(&tlv1,sizeof(cgc_size_t));
    {char buf [ 128 ]; buf [ ( 128 )-1 ] = (char)(0); }
    {int i; i = (int)(0); }
    {int found; found = (int)(0); }
    {int error; error = (int)(0); }
    {cgc_size_t tlv1; tlv1 = (cgc_size_t)(0); }
    {char tlv2; tlv2 = (char)(0); }
    {int tlv4; tlv4 = (int)(0); }
    {char * tlv6; tlv6 = (char *)(0); }
    {void * tlv9; tlv9 = (void *)(0); }
    {int tlv8; tlv8 = (int)(0); }
    {cgc_size_t tlv7; tlv7 = (cgc_size_t)(0); }
    {int tlv11; tlv11 = (int)(0); }
}
void fix_ingred_main_6_3(){
fix_ingred_main_6_3_1();
fix_ingred_main_6_3_2();
}
void fix_ingred_main_6_4_0(){
    {char buf [ 128 ]; buf [ ( 128 )-1 ] = (char)(STDOUT); }
    {int i; i = (int)(STDOUT); }
    {int found; found = (int)(STDOUT); }
    {int error; error = (int)(STDOUT); }
    {cgc_size_t tlv1; tlv1 = (cgc_size_t)(STDOUT); }
    {char tlv2; tlv2 = (char)(STDOUT); }
    {int tlv4; tlv4 = (int)(STDOUT); }
    {char * tlv6; tlv6 = (char *)(STDOUT); }
    {void * tlv9; tlv9 = (void *)(STDOUT); }
    {int tlv8; tlv8 = (int)(STDOUT); }
    {cgc_size_t tlv7; tlv7 = (cgc_size_t)(STDOUT); }
    {int tlv11; tlv11 = (int)(STDOUT); }
}
void fix_ingred_main_6_4(){
fix_ingred_main_6_4_0();
}
void fix_ingred_main_6_5_0(){
char buf [ 128 ];
    bzero(&buf,( 128 *sizeof(char) ) );
    {char buf [ 128 ]; buf [ ( 128 )-1 ] = (char)(buf); }
    {int i; i = (int)(buf); }
    {int found; found = (int)(buf); }
    {int error; error = (int)(buf); }
    {cgc_size_t tlv1; tlv1 = (cgc_size_t)(buf); }
    {char tlv2; tlv2 = (char)(buf); }
    {int tlv4; tlv4 = (int)(buf); }
    {char * tlv6; tlv6 = (char *)(buf); }
    {void * tlv9; tlv9 = (void *)(buf); }
    {int tlv8; tlv8 = (int)(buf); }
    {cgc_size_t tlv7; tlv7 = (cgc_size_t)(buf); }
    {int tlv11; tlv11 = (int)(buf); }
}
void fix_ingred_main_6_5(){
fix_ingred_main_6_5_0();
}
void fix_ingred_main_6_11_0(){
hackman_state_t h_state;
    bzero(&h_state,sizeof(hackman_state_t));
    {char buf [ 128 ]; buf [ ( 128 )-1 ] = (char)(h_state . progress); }
    {int i; i = (int)(h_state . progress); }
    {int found; found = (int)(h_state . progress); }
    {int error; error = (int)(h_state . progress); }
    {cgc_size_t tlv1; tlv1 = (cgc_size_t)(h_state . progress); }
    {char tlv2; tlv2 = (char)(h_state . progress); }
    {int tlv4; tlv4 = (int)(h_state . progress); }
    {char * tlv6; tlv6 = (char *)(h_state . progress); }
    {void * tlv9; tlv9 = (void *)(h_state . progress); }
    {int tlv8; tlv8 = (int)(h_state . progress); }
    {cgc_size_t tlv7; tlv7 = (cgc_size_t)(h_state . progress); }
    {int tlv11; tlv11 = (int)(h_state . progress); }
}
void fix_ingred_main_6_11_1(){
hackman_state_t h_state;
    bzero(&h_state,sizeof(hackman_state_t));
    {char buf [ 128 ]; buf [ ( 128 )-1 ] = (char)('_'); }
    {int i; i = (int)('_'); }
    {int found; found = (int)('_'); }
    {int error; error = (int)('_'); }
    {cgc_size_t tlv1; tlv1 = (cgc_size_t)('_'); }
    {char tlv2; tlv2 = (char)('_'); }
    {int tlv4; tlv4 = (int)('_'); }
    {char * tlv6; tlv6 = (char *)('_'); }
    {void * tlv9; tlv9 = (void *)('_'); }
    {int tlv8; tlv8 = (int)('_'); }
    {cgc_size_t tlv7; tlv7 = (cgc_size_t)('_'); }
    {int tlv11; tlv11 = (int)('_'); }
}
void fix_ingred_main_6_11(){
fix_ingred_main_6_11_0();
fix_ingred_main_6_11_1();
}
void fix_ingred_main_6_12_0(){
char tlv12_ref;
    bzero(&tlv12_ref,1*sizeof(char));
const char * tlv12 = &tlv12_ref;
    {char buf [ 128 ]; buf [ ( 128 )-1 ] = (char)(cgc_strlen ( tlv12 )); }
    {int i; i = (int)(cgc_strlen ( tlv12 )); }
    {int found; found = (int)(cgc_strlen ( tlv12 )); }
    {int error; error = (int)(cgc_strlen ( tlv12 )); }
    {cgc_size_t tlv1; tlv1 = (cgc_size_t)(cgc_strlen ( tlv12 )); }
    {char tlv2; tlv2 = (char)(cgc_strlen ( tlv12 )); }
    {int tlv4; tlv4 = (int)(cgc_strlen ( tlv12 )); }
    {char * tlv6; tlv6 = (char *)(cgc_strlen ( tlv12 )); }
    {void * tlv9; tlv9 = (void *)(cgc_strlen ( tlv12 )); }
    {int tlv8; tlv8 = (int)(cgc_strlen ( tlv12 )); }
    {cgc_size_t tlv7; tlv7 = (cgc_size_t)(cgc_strlen ( tlv12 )); }
    {int tlv11; tlv11 = (int)(cgc_strlen ( tlv12 )); }
}
void fix_ingred_main_6_12(){
fix_ingred_main_6_12_0();
}
void fix_ingred_main_6_16_0(){
    {char buf [ 128 ]; buf [ ( 128 )-1 ] = (char)(1); }
    {int i; i = (int)(1); }
    {int found; found = (int)(1); }
    {int error; error = (int)(1); }
    {cgc_size_t tlv1; tlv1 = (cgc_size_t)(1); }
    {char tlv2; tlv2 = (char)(1); }
    {int tlv4; tlv4 = (int)(1); }
    {char * tlv6; tlv6 = (char *)(1); }
    {void * tlv9; tlv9 = (void *)(1); }
    {int tlv8; tlv8 = (int)(1); }
    {cgc_size_t tlv7; tlv7 = (cgc_size_t)(1); }
    {int tlv11; tlv11 = (int)(1); }
}
void fix_ingred_main_6_16(){
fix_ingred_main_6_16_0();
}
void fix_ingred_main_6_20_3(){
int i;
    bzero(&i,sizeof(int));
hackman_state_t h_state;
    bzero(&h_state,sizeof(hackman_state_t));
    {char buf [ 128 ]; buf [ ( 128 )-1 ] = (char)(i); }
    {int found; found = (int)(i); }
    {int error; error = (int)(i); }
    {char tlv2; tlv2 = (char)(i); }
    {int tlv4; tlv4 = (int)(i); }
    {char * tlv6; tlv6 = (char *)(i); }
    {void * tlv9; tlv9 = (void *)(i); }
    {int tlv8; tlv8 = (int)(i); }
    {cgc_size_t tlv7; tlv7 = (cgc_size_t)(i); }
    {int tlv11; tlv11 = (int)(i); }
}
void fix_ingred_main_6_20_4(){
int i;
    bzero(&i,sizeof(int));
hackman_state_t h_state;
    bzero(&h_state,sizeof(hackman_state_t));
    {char buf [ 128 ]; buf [ ( 128 )-1 ] = (char)(cgc_strlen ( h_state . word )); }
    {int i; i = (int)(cgc_strlen ( h_state . word )); }
    {int found; found = (int)(cgc_strlen ( h_state . word )); }
    {int error; error = (int)(cgc_strlen ( h_state . word )); }
    {cgc_size_t tlv1; tlv1 = (cgc_size_t)(cgc_strlen ( h_state . word )); }
    {char tlv2; tlv2 = (char)(cgc_strlen ( h_state . word )); }
    {int tlv4; tlv4 = (int)(cgc_strlen ( h_state . word )); }
    {char * tlv6; tlv6 = (char *)(cgc_strlen ( h_state . word )); }
    {void * tlv9; tlv9 = (void *)(cgc_strlen ( h_state . word )); }
    {int tlv8; tlv8 = (int)(cgc_strlen ( h_state . word )); }
    {cgc_size_t tlv7; tlv7 = (cgc_size_t)(cgc_strlen ( h_state . word )); }
    {int tlv11; tlv11 = (int)(cgc_strlen ( h_state . word )); }
}
void fix_ingred_main_6_20(){
fix_ingred_main_6_20_3();
fix_ingred_main_6_20_4();
}
void fix_ingred_main_6_21_7(){
char buf [ 128 ];
    bzero(&buf,( 128 *sizeof(char) ) );
    {if (buf){char buf [ 128 ]; buf [ ( 128 )-1 ] = (char)(buf [ 0 ]); }}
    {if (buf){int i; i = (int)(buf [ 0 ]); }}
    {if (buf){int found; found = (int)(buf [ 0 ]); }}
    {if (buf){int error; error = (int)(buf [ 0 ]); }}
    {if (buf){cgc_size_t tlv1; tlv1 = (cgc_size_t)(buf [ 0 ]); }}
    {if (buf){char tlv2; tlv2 = (char)(buf [ 0 ]); }}
    {if (buf){int tlv4; tlv4 = (int)(buf [ 0 ]); }}
    {if (buf){char * tlv6; tlv6 = (char *)(buf [ 0 ]); }}
    {if (buf){void * tlv9; tlv9 = (void *)(buf [ 0 ]); }}
    {if (buf){int tlv8; tlv8 = (int)(buf [ 0 ]); }}
    {if (buf){cgc_size_t tlv7; tlv7 = (cgc_size_t)(buf [ 0 ]); }}
    {if (buf){int tlv11; tlv11 = (int)(buf [ 0 ]); }}
}
void fix_ingred_main_6_21(){
fix_ingred_main_6_21_7();
}
void fix_ingred_main_6_23_5(){
hackman_state_t h_state;
    bzero(&h_state,sizeof(hackman_state_t));
    {char buf [ 128 ]; buf [ ( 128 )-1 ] = (char)(cgc_strlen ( h_state . progress )); }
    {int i; i = (int)(cgc_strlen ( h_state . progress )); }
    {int found; found = (int)(cgc_strlen ( h_state . progress )); }
    {int error; error = (int)(cgc_strlen ( h_state . progress )); }
    {cgc_size_t tlv1; tlv1 = (cgc_size_t)(cgc_strlen ( h_state . progress )); }
    {char tlv2; tlv2 = (char)(cgc_strlen ( h_state . progress )); }
    {int tlv4; tlv4 = (int)(cgc_strlen ( h_state . progress )); }
    {char * tlv6; tlv6 = (char *)(cgc_strlen ( h_state . progress )); }
    {void * tlv9; tlv9 = (void *)(cgc_strlen ( h_state . progress )); }
    {int tlv8; tlv8 = (int)(cgc_strlen ( h_state . progress )); }
    {cgc_size_t tlv7; tlv7 = (cgc_size_t)(cgc_strlen ( h_state . progress )); }
    {int tlv11; tlv11 = (int)(cgc_strlen ( h_state . progress )); }
}
void fix_ingred_main_6_23(){
fix_ingred_main_6_23_5();
}
void fix_ingred_main_6(){
fix_ingred_main_6_1();
fix_ingred_main_6_2();
fix_ingred_main_6_3();
fix_ingred_main_6_4();
fix_ingred_main_6_5();
fix_ingred_main_6_11();
fix_ingred_main_6_12();
fix_ingred_main_6_16();
fix_ingred_main_6_20();
fix_ingred_main_6_21();
fix_ingred_main_6_23();
}
void fix_ingred_main_7_1_0(){
    {int tlv2; tlv2 = (int)(STDOUT); }
}
void fix_ingred_main_7_1(){
fix_ingred_main_7_1_0();
}
void fix_ingred_main_7(){
fix_ingred_main_7_1();
}
