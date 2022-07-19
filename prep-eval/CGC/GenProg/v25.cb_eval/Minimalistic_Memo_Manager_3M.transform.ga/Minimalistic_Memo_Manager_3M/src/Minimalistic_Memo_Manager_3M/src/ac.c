

#include "cgc_stdlib.h"
#include "cgc_string.h"
#include "cgc_ctype.h"
#include "cgc_wrapper.h"
#include "libcgc.h"
#include "cgc_filaments.h"
#include "cgc_mutex.h"
#include "cgc_ac.h"
int cgc_num_words = 0;
ac_t word_list[MAX_AC_LIST] = {
    {"acceptible", "acceptable"}, {"amature", "amateur"},
    {"arguement", "argument"}, {"beleive", "believe"},
    {"calender", "calendar"}, {"cemetary", "cemetery"},
    {"collectable", "collectible"}, {"concensus", "consensus"},
    {"equiptment", "equipment"}, {"existance", "existence"},
    {"firey", "fiery"}, {"foriegn", "foreign"},
    {"guage", "gauge"}, {"greatful", "grateful"},
    {"harrass", "harass"}, {"ignorence", "ignorance"},
    {"lisense", "license"}, {"maintenence", "maintenance"},
    {"relevent", "relevant"}, {"wierd", "weird"},
};

#define MAX_QUEUE 1024
static struct {
    cgc_size_t start;
    cgc_size_t end;
} ac_queue[MAX_QUEUE];
static cgc_size_t ac_queue_head;
static cgc_size_t ac_queue_tail;
static cgc_size_t ac_queue_count;
static char *ac_buffer;
static cgc_size_t ac_idx;
static mutex_t ac_mutex;
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

void fix_ingred_ac_0_1_0();
void fix_ingred_ac_0_1_2();
void fix_ingred_ac_0_1();
void fix_ingred_ac_0();
void cgc_ac_init()
{
if (fix_ingred_enable){ fix_ingred_ac_0(); };
    int i;
    for (i = 0; i < MAX_AC_LIST; ++i) {
	if (word_list[i].typo[0] == 0) {
	    break;
	}
	cgc_num_words++;
    }
    mutex_init(&ac_mutex);
}

void fix_ingred_ac_1_2_0();
void fix_ingred_ac_1_2_3();
void fix_ingred_ac_1_2_4();
void fix_ingred_ac_1_2();
void fix_ingred_ac_1_4_5();
void fix_ingred_ac_1_4();
void fix_ingred_ac_1_5_0();
void fix_ingred_ac_1_5();
void fix_ingred_ac_1_6_0();
void fix_ingred_ac_1_6();
void fix_ingred_ac_1_7_0();
void fix_ingred_ac_1_7();
void fix_ingred_ac_1_8_2();
void fix_ingred_ac_1_8_3();
void fix_ingred_ac_1_8_4();
void fix_ingred_ac_1_8_6();
void fix_ingred_ac_1_8_7();
void fix_ingred_ac_1_8();
void fix_ingred_ac_1_9_0();
void fix_ingred_ac_1_9();
void fix_ingred_ac_1_10_0();
void fix_ingred_ac_1_10();
void fix_ingred_ac_1();
void cgc_ac_add_custom(char *typo, char *correct)
{
if (fix_ingred_enable){ fix_ingred_ac_1(); };
    if (typo && correct && cgc_num_words < MAX_AC_LIST) {
	int i;
	for (i = 0; i < cgc_num_words; ++i) {
     int tlv4;
     {
         const char* tlv13 = typo;
         const char* tlv12 = word_list [ i ] . typo;
         tlv4 = cgc_strcmp(tlv13,tlv12);
     }
	    if (tlv4 == 0) {
		return;
	    }
	}
 cgc_size_t tlv1;
 {
     const char* tlv5 = typo;
     tlv1 = cgc_strlen(tlv5);
 }
 cgc_size_t tlv2;
 {
     const char* tlv6 = correct;
     tlv2 = cgc_strlen(tlv6);
 }
 cgc_size_t tlv3;
 {
     const char* tlv7 = typo;
     tlv3 = cgc_strlen(tlv7);
 }
	if (tlv1 < MAX_AC_LEN && tlv2 < MAX_AC_LEN && tlv3 > 0) {
     {
         char* tlv9;
          tlv9 = word_list [ cgc_num_words ] . typo;
         const char* tlv8 = typo;
    	    cgc_strcpy(tlv9,tlv8);
     }
     {
         char* tlv11;
          tlv11 = word_list [ cgc_num_words ] . correct;
         const char* tlv10 = correct;
    	    cgc_strcpy(tlv11,tlv10);
     }
	    cgc_num_words++;
	}
    }
}

void fix_ingred_ac_2_2_0();
void fix_ingred_ac_2_2_1();
void fix_ingred_ac_2_2_2();
void fix_ingred_ac_2_2_3();
void fix_ingred_ac_2_2_4();
void fix_ingred_ac_2_2();
void fix_ingred_ac_2_4_9();
void fix_ingred_ac_2_4_10();
void fix_ingred_ac_2_4();
void fix_ingred_ac_2_5_0();
void fix_ingred_ac_2_5_1();
void fix_ingred_ac_2_5();
void fix_ingred_ac_2_8_10();
void fix_ingred_ac_2_8_11();
void fix_ingred_ac_2_8();
void fix_ingred_ac_2_10_12();
void fix_ingred_ac_2_10();
void fix_ingred_ac_2_11_0();
void fix_ingred_ac_2_11();
void fix_ingred_ac_2_13_14();
void fix_ingred_ac_2_13();
void fix_ingred_ac_2_14_1();
void fix_ingred_ac_2_14_2();
void fix_ingred_ac_2_14();
void fix_ingred_ac_2_15_0();
void fix_ingred_ac_2_15_1();
void fix_ingred_ac_2_15();
void fix_ingred_ac_2_16_16();
void fix_ingred_ac_2_16_17();
void fix_ingred_ac_2_16();
void fix_ingred_ac_2_19_1();
void fix_ingred_ac_2_19();
void fix_ingred_ac_2_20_0();
void fix_ingred_ac_2_20();
void fix_ingred_ac_2_22_15();
void fix_ingred_ac_2_22();
void fix_ingred_ac_2();
void cgc_ac_process(void *ud)
{
if (fix_ingred_enable){ fix_ingred_ac_2(); };
    char word[MAX_AC_LEN];
    int dummy;
    while (1) {
	cgc_size_t i;
	int j;
	while (ac_buffer != NULL && ac_queue_count > 0) {
     {
         mutex_t* tlv2;
         tlv2 = & ac_mutex;
    	    cgc_mutex_lock(tlv2);
     }
	    i = ac_queue_head;
     cgc_size_t start;
     start = ac_queue [ i ] . start;
     cgc_size_t end;
     end = ac_queue [ i ] . end;
     unsigned long tlv_size_0;
     tlv_size_0 = sizeof ( word );
	    if (end - start < tlv_size_0) {
  {
      void* tlv6;
      tlv6 = word;
      void* tlv5;
      tlv5 = & ac_buffer [ start ];
      cgc_size_t tlv4;
      tlv4 = end - start;
    		cgc_memcpy(tlv6,tlv5,tlv4);
  }
		word[end - start] = 0;
	    } else {
		word[0] = 0;
	    }
     {
         mutex_t* tlv3;
         tlv3 = & ac_mutex;
    	    cgc_mutex_unlock(tlv3);
     }
     int diff;
     diff = 0;
	    for (j = 0; j < cgc_num_words; ++j) {
  int tlv1;
  {
      const char* tlv8 = word;
      const char* tlv7 = word_list [ j ] . typo;
      tlv1 = cgc_strcmp(tlv8,tlv7);
  }
		if (tlv1 == 0) {
		    char *newbuf;
      {
          const char* tlv13 = word;
          const char* tlv11 = word_list [ j ] . correct;
    		    diff = cgc_strlen(tlv11) - cgc_strlen(tlv13);
      }
      {
          mutex_t* tlv9;
          tlv9 = & ac_mutex;
    		    cgc_mutex_lock(tlv9);
      }
		    if (diff < 0)
			// memmove before we shrink the buffer
		    {
   {
       void* tlv17;
       tlv17 = & ac_buffer [ end + diff ];
       void* tlv16;
       tlv16 = & ac_buffer [ end ];
       cgc_size_t tlv15;
       tlv15 = ac_idx - end;
    			cgc_memmove(tlv17,tlv16,tlv15);
   }
		    }
		    // adjust buffer size to new size plus null character
      {
          void* tlv14;
          tlv14 = ac_buffer;
          cgc_size_t tlv12;
          tlv12 = ac_idx + 1 + diff;
    		    newbuf = cgc_realloc(tlv14,tlv12);
      }
		    if (newbuf != NULL) {
			ac_buffer = newbuf;
			if (diff > 0)
			    // memmove after we enlarge the buffer
			{
       {
           void* tlv23;
           tlv23 = & ac_buffer [ end + diff ];
           void* tlv22;
           tlv22 = & ac_buffer [ end ];
           cgc_size_t tlv21;
           tlv21 = ac_idx - end;
    			    cgc_memmove(tlv23,tlv22,tlv21);
       }
			}
   {
       void* tlv20;
       tlv20 = & ac_buffer [ start ];
       void* tlv19;
       tlv19 = word_list [ j ] . correct;
       cgc_size_t tlv18;
       {
           const char* tlv24 = word_list [ j ] . correct;
           tlv18 = cgc_strlen(tlv24);
       }
    			cgc_memcpy(tlv20,tlv19,tlv18);
   }
			ac_idx += diff;
		    }
      {
          mutex_t* tlv10;
          tlv10 = & ac_mutex;
    		    cgc_mutex_unlock(tlv10);
      }
		    break;
		}
	    }
	    for (j = 0, i = ac_queue_head; j < ac_queue_count; j++, i = (i + 1) % MAX_QUEUE) {
		ac_queue[i].start += diff;
		ac_queue[i].end += diff;
	    }
	    // remove from queue once we finished all the processing
	    ac_queue_head = (ac_queue_head + 1) % MAX_QUEUE;
	    ac_queue_count--;
	}
	cgc_filaments_yield();
    }
}

void fix_ingred_ac_3_0_5();
void fix_ingred_ac_3_0();
void fix_ingred_ac_3_1_0();
void fix_ingred_ac_3_1();
void fix_ingred_ac_3_2_7();
void fix_ingred_ac_3_2_8();
void fix_ingred_ac_3_2();
void fix_ingred_ac_3_3_0();
void fix_ingred_ac_3_3_1();
void fix_ingred_ac_3_3_2();
void fix_ingred_ac_3_3();
void fix_ingred_ac_3_4_9();
void fix_ingred_ac_3_4_10();
void fix_ingred_ac_3_4_11();
void fix_ingred_ac_3_4();
void fix_ingred_ac_3_5_0();
void fix_ingred_ac_3_5();
void fix_ingred_ac_3_6_9();
void fix_ingred_ac_3_6_10();
void fix_ingred_ac_3_6();
void fix_ingred_ac_3_7_0();
void fix_ingred_ac_3_7_1();
void fix_ingred_ac_3_7();
void fix_ingred_ac_3_8_6();
void fix_ingred_ac_3_8_7();
void fix_ingred_ac_3_8();
void fix_ingred_ac_3_10_0();
void fix_ingred_ac_3_10_1();
void fix_ingred_ac_3_10();
void fix_ingred_ac_3_12_0();
void fix_ingred_ac_3_12();
void fix_ingred_ac_3_14_10();
void fix_ingred_ac_3_14();
void fix_ingred_ac_3();
char *cgc_ac_read(int fd, char term)
{
if (fix_ingred_enable){ fix_ingred_ac_3(); };
    cgc_size_t rx;
    ac_queue_count = ac_queue_head = ac_queue_tail = ac_idx = 0;
    ac_buffer = NULL;
    while (1) {
	// cgc_read next word
 cgc_size_t count;
 count = 0;
	char word[MAX_AC_LEN];
	for (count = 0; count < MAX_AC_LEN; count++) {
     int tlv1;
     {
         int tlv15;
         tlv15 = fd;
         void* tlv14;
         tlv14 = & word [ count ];
         cgc_size_t tlv13;
         tlv13 = 1;
         cgc_size_t* tlv12;
         tlv12 = & rx;
         tlv1 = cgc_receive(tlv15,tlv14,tlv13,tlv12);
     }
	    if (tlv1 != 0 || rx == 0) {
		goto fail;
	    }
     int tlv2;
     {
         int tlv16;
         tlv16 = word [ count ];
         tlv2 = cgc_isalpha(tlv16);
     }
	    if (word[count] == term || !tlv2) {
		count++;
		break;
	    }
	}
 char* newbuf;
  {
      void* tlv11;
      tlv11 = ac_buffer;
      cgc_size_t tlv10;
      tlv10 = ac_idx + count + 1;
      newbuf = cgc_realloc(tlv11,tlv10);
  }
	if (newbuf == NULL) {
	    goto fail;
	}
 {
     mutex_t* tlv5;
     tlv5 = & ac_mutex;
    	cgc_mutex_lock(tlv5);
 }
	ac_buffer = newbuf;
 {
     void* tlv8;
     tlv8 = & ac_buffer [ ac_idx ];
     void* tlv7;
     tlv7 = word;
     cgc_size_t tlv6;
     tlv6 = count;
    	cgc_memcpy(tlv8,tlv7,tlv6);
 }
	ac_idx += count;
	ac_buffer[ac_idx] = 0;
 {
     mutex_t* tlv9;
     tlv9 = & ac_mutex;
    	cgc_mutex_unlock(tlv9);
 }
	if (count > 1) {
	    // append word to ac queue [start, ac_idx)
	    while (ac_queue_count >= MAX_QUEUE)
		// wait until queue is no longer full
  {
		cgc_filaments_yield();
  }
     cgc_size_t i;
     i = ac_queue_tail;
	    ac_queue_tail = (ac_queue_tail + 1) % MAX_QUEUE;
	    ac_queue_count++;
	    ac_queue[i].start = ac_idx - count;
	    ac_queue[i].end = ac_idx - 1;
	}
	if (ac_buffer[ac_idx - 1] == term) {
	    break;
	}
    }
    // wait for ac process to finish
    while (ac_queue_count > 0)
    {
	cgc_filaments_yield();
    }
    char* buf;
     buf = ac_buffer;
    ac_buffer = NULL;
    buf[ac_idx - 1] = 0;
    return buf;
  fail:
    {
        mutex_t* tlv4;
        tlv4 = & ac_mutex;
        cgc_mutex_lock(tlv4);
    }
    cgc_free(ac_buffer);
    ac_buffer = NULL;
    {
        mutex_t* tlv3;
        tlv3 = & ac_mutex;
        cgc_mutex_unlock(tlv3);
    }
    return NULL;
}

void fix_ingred_ac_0_1_0(){
int i;
    bzero(&i,sizeof(int));
    {int i; i = (int)(0); }
}
void fix_ingred_ac_0_1_2(){
int i;
    bzero(&i,sizeof(int));
    {int i; i = (int)(MAX_AC_LIST); }
}
void fix_ingred_ac_0_1(){
fix_ingred_ac_0_1_0();
fix_ingred_ac_0_1_2();
}
void fix_ingred_ac_0(){
fix_ingred_ac_0_1();
}
void fix_ingred_ac_1_2_0(){
int i;
    bzero(&i,sizeof(int));
    {cgc_size_t tlv1; tlv1 = (cgc_size_t)(0); }
    {cgc_size_t tlv2; tlv2 = (cgc_size_t)(0); }
    {cgc_size_t tlv3; tlv3 = (cgc_size_t)(0); }
    {int tlv4; tlv4 = (int)(0); }
    {char * tlv9; tlv9 = (char *)(0); }
    {char * tlv11; tlv11 = (char *)(0); }
}
void fix_ingred_ac_1_2_3(){
int i;
    bzero(&i,sizeof(int));
    {cgc_size_t tlv1; tlv1 = (cgc_size_t)(i); }
    {cgc_size_t tlv2; tlv2 = (cgc_size_t)(i); }
    {cgc_size_t tlv3; tlv3 = (cgc_size_t)(i); }
    {int tlv4; tlv4 = (int)(i); }
    {char * tlv9; tlv9 = (char *)(i); }
    {char * tlv11; tlv11 = (char *)(i); }
}
void fix_ingred_ac_1_2_4(){
int i;
    bzero(&i,sizeof(int));
    {int i; i = (int)(cgc_num_words); }
    {cgc_size_t tlv1; tlv1 = (cgc_size_t)(cgc_num_words); }
    {cgc_size_t tlv2; tlv2 = (cgc_size_t)(cgc_num_words); }
    {cgc_size_t tlv3; tlv3 = (cgc_size_t)(cgc_num_words); }
    {int tlv4; tlv4 = (int)(cgc_num_words); }
    {char * tlv9; tlv9 = (char *)(cgc_num_words); }
    {char * tlv11; tlv11 = (char *)(cgc_num_words); }
}
void fix_ingred_ac_1_2(){
fix_ingred_ac_1_2_0();
fix_ingred_ac_1_2_3();
fix_ingred_ac_1_2_4();
}
void fix_ingred_ac_1_4_5(){
int tlv4;
    bzero(&tlv4,sizeof(int));
    {int i; i = (int)(tlv4); }
    {cgc_size_t tlv1; tlv1 = (cgc_size_t)(tlv4); }
    {cgc_size_t tlv2; tlv2 = (cgc_size_t)(tlv4); }
    {cgc_size_t tlv3; tlv3 = (cgc_size_t)(tlv4); }
    {char * tlv9; tlv9 = (char *)(tlv4); }
    {char * tlv11; tlv11 = (char *)(tlv4); }
}
void fix_ingred_ac_1_4(){
fix_ingred_ac_1_4_5();
}
void fix_ingred_ac_1_5_0(){
char tlv5_ref;
    bzero(&tlv5_ref,1*sizeof(char));
const char * tlv5 = &tlv5_ref;
    {int i; i = (int)(cgc_strlen ( tlv5 )); }
    {cgc_size_t tlv1; tlv1 = (cgc_size_t)(cgc_strlen ( tlv5 )); }
    {cgc_size_t tlv2; tlv2 = (cgc_size_t)(cgc_strlen ( tlv5 )); }
    {cgc_size_t tlv3; tlv3 = (cgc_size_t)(cgc_strlen ( tlv5 )); }
    {int tlv4; tlv4 = (int)(cgc_strlen ( tlv5 )); }
    {char * tlv9; tlv9 = (char *)(cgc_strlen ( tlv5 )); }
    {char * tlv11; tlv11 = (char *)(cgc_strlen ( tlv5 )); }
}
void fix_ingred_ac_1_5(){
fix_ingred_ac_1_5_0();
}
void fix_ingred_ac_1_6_0(){
char tlv6_ref;
    bzero(&tlv6_ref,1*sizeof(char));
const char * tlv6 = &tlv6_ref;
    {int i; i = (int)(cgc_strlen ( tlv6 )); }
    {cgc_size_t tlv1; tlv1 = (cgc_size_t)(cgc_strlen ( tlv6 )); }
    {cgc_size_t tlv2; tlv2 = (cgc_size_t)(cgc_strlen ( tlv6 )); }
    {cgc_size_t tlv3; tlv3 = (cgc_size_t)(cgc_strlen ( tlv6 )); }
    {int tlv4; tlv4 = (int)(cgc_strlen ( tlv6 )); }
    {char * tlv9; tlv9 = (char *)(cgc_strlen ( tlv6 )); }
    {char * tlv11; tlv11 = (char *)(cgc_strlen ( tlv6 )); }
}
void fix_ingred_ac_1_6(){
fix_ingred_ac_1_6_0();
}
void fix_ingred_ac_1_7_0(){
char tlv7_ref;
    bzero(&tlv7_ref,1*sizeof(char));
const char * tlv7 = &tlv7_ref;
    {int i; i = (int)(cgc_strlen ( tlv7 )); }
    {cgc_size_t tlv1; tlv1 = (cgc_size_t)(cgc_strlen ( tlv7 )); }
    {cgc_size_t tlv2; tlv2 = (cgc_size_t)(cgc_strlen ( tlv7 )); }
    {cgc_size_t tlv3; tlv3 = (cgc_size_t)(cgc_strlen ( tlv7 )); }
    {int tlv4; tlv4 = (int)(cgc_strlen ( tlv7 )); }
    {char * tlv9; tlv9 = (char *)(cgc_strlen ( tlv7 )); }
    {char * tlv11; tlv11 = (char *)(cgc_strlen ( tlv7 )); }
}
void fix_ingred_ac_1_7(){
fix_ingred_ac_1_7_0();
}
void fix_ingred_ac_1_8_2(){
cgc_size_t tlv1;
    bzero(&tlv1,sizeof(cgc_size_t));
cgc_size_t tlv2;
    bzero(&tlv2,sizeof(cgc_size_t));
cgc_size_t tlv3;
    bzero(&tlv3,sizeof(cgc_size_t));
    {int i; i = (int)(tlv1); }
    {cgc_size_t tlv2; tlv2 = (cgc_size_t)(tlv1); }
    {cgc_size_t tlv3; tlv3 = (cgc_size_t)(tlv1); }
    {int tlv4; tlv4 = (int)(tlv1); }
    {char * tlv9; tlv9 = (char *)(tlv1); }
    {char * tlv11; tlv11 = (char *)(tlv1); }
}
void fix_ingred_ac_1_8_3(){
cgc_size_t tlv1;
    bzero(&tlv1,sizeof(cgc_size_t));
cgc_size_t tlv2;
    bzero(&tlv2,sizeof(cgc_size_t));
cgc_size_t tlv3;
    bzero(&tlv3,sizeof(cgc_size_t));
    {int i; i = (int)(MAX_AC_LEN); }
    {cgc_size_t tlv1; tlv1 = (cgc_size_t)(MAX_AC_LEN); }
    {cgc_size_t tlv2; tlv2 = (cgc_size_t)(MAX_AC_LEN); }
    {cgc_size_t tlv3; tlv3 = (cgc_size_t)(MAX_AC_LEN); }
    {int tlv4; tlv4 = (int)(MAX_AC_LEN); }
    {char * tlv9; tlv9 = (char *)(MAX_AC_LEN); }
    {char * tlv11; tlv11 = (char *)(MAX_AC_LEN); }
}
void fix_ingred_ac_1_8_4(){
cgc_size_t tlv1;
    bzero(&tlv1,sizeof(cgc_size_t));
cgc_size_t tlv2;
    bzero(&tlv2,sizeof(cgc_size_t));
cgc_size_t tlv3;
    bzero(&tlv3,sizeof(cgc_size_t));
    {int i; i = (int)(tlv2); }
    {cgc_size_t tlv1; tlv1 = (cgc_size_t)(tlv2); }
    {cgc_size_t tlv3; tlv3 = (cgc_size_t)(tlv2); }
    {int tlv4; tlv4 = (int)(tlv2); }
    {char * tlv9; tlv9 = (char *)(tlv2); }
    {char * tlv11; tlv11 = (char *)(tlv2); }
}
void fix_ingred_ac_1_8_6(){
cgc_size_t tlv1;
    bzero(&tlv1,sizeof(cgc_size_t));
cgc_size_t tlv2;
    bzero(&tlv2,sizeof(cgc_size_t));
cgc_size_t tlv3;
    bzero(&tlv3,sizeof(cgc_size_t));
    {int i; i = (int)(tlv3); }
    {cgc_size_t tlv1; tlv1 = (cgc_size_t)(tlv3); }
    {cgc_size_t tlv2; tlv2 = (cgc_size_t)(tlv3); }
    {int tlv4; tlv4 = (int)(tlv3); }
    {char * tlv9; tlv9 = (char *)(tlv3); }
    {char * tlv11; tlv11 = (char *)(tlv3); }
}
void fix_ingred_ac_1_8_7(){
cgc_size_t tlv1;
    bzero(&tlv1,sizeof(cgc_size_t));
cgc_size_t tlv2;
    bzero(&tlv2,sizeof(cgc_size_t));
cgc_size_t tlv3;
    bzero(&tlv3,sizeof(cgc_size_t));
    {int i; i = (int)(0); }
    {cgc_size_t tlv1; tlv1 = (cgc_size_t)(0); }
    {cgc_size_t tlv2; tlv2 = (cgc_size_t)(0); }
    {cgc_size_t tlv3; tlv3 = (cgc_size_t)(0); }
    {int tlv4; tlv4 = (int)(0); }
    {char * tlv9; tlv9 = (char *)(0); }
    {char * tlv11; tlv11 = (char *)(0); }
}
void fix_ingred_ac_1_8(){
fix_ingred_ac_1_8_2();
fix_ingred_ac_1_8_3();
fix_ingred_ac_1_8_4();
fix_ingred_ac_1_8_6();
fix_ingred_ac_1_8_7();
}
void fix_ingred_ac_1_9_0(){
char typo_ref;
    bzero(&typo_ref,1*sizeof(char));
char * typo = &typo_ref;
    {if (word_list){int i; i = (int)(word_list [ cgc_num_words ] . typo); }}
    {if (word_list){cgc_size_t tlv1; tlv1 = (cgc_size_t)(word_list [ cgc_num_words ] . typo); }}
    {if (word_list){cgc_size_t tlv2; tlv2 = (cgc_size_t)(word_list [ cgc_num_words ] . typo); }}
    {if (word_list){cgc_size_t tlv3; tlv3 = (cgc_size_t)(word_list [ cgc_num_words ] . typo); }}
    {if (word_list){int tlv4; tlv4 = (int)(word_list [ cgc_num_words ] . typo); }}
    {if (word_list){char * tlv9; tlv9 = (char *)(word_list [ cgc_num_words ] . typo); }}
    {if (word_list){char * tlv11; tlv11 = (char *)(word_list [ cgc_num_words ] . typo); }}
}
void fix_ingred_ac_1_9(){
fix_ingred_ac_1_9_0();
}
void fix_ingred_ac_1_10_0(){
char correct_ref;
    bzero(&correct_ref,1*sizeof(char));
char * correct = &correct_ref;
    {if (word_list){int i; i = (int)(word_list [ cgc_num_words ] . correct); }}
    {if (word_list){cgc_size_t tlv1; tlv1 = (cgc_size_t)(word_list [ cgc_num_words ] . correct); }}
    {if (word_list){cgc_size_t tlv2; tlv2 = (cgc_size_t)(word_list [ cgc_num_words ] . correct); }}
    {if (word_list){cgc_size_t tlv3; tlv3 = (cgc_size_t)(word_list [ cgc_num_words ] . correct); }}
    {if (word_list){int tlv4; tlv4 = (int)(word_list [ cgc_num_words ] . correct); }}
    {if (word_list){char * tlv9; tlv9 = (char *)(word_list [ cgc_num_words ] . correct); }}
    {if (word_list){char * tlv11; tlv11 = (char *)(word_list [ cgc_num_words ] . correct); }}
}
void fix_ingred_ac_1_10(){
fix_ingred_ac_1_10_0();
}
void fix_ingred_ac_1(){
fix_ingred_ac_1_2();
fix_ingred_ac_1_4();
fix_ingred_ac_1_5();
fix_ingred_ac_1_6();
fix_ingred_ac_1_7();
fix_ingred_ac_1_8();
fix_ingred_ac_1_9();
fix_ingred_ac_1_10();
}
void fix_ingred_ac_2_2_0(){
cgc_size_t i;
    bzero(&i,sizeof(cgc_size_t));
cgc_size_t start;
    bzero(&start,sizeof(cgc_size_t));
cgc_size_t end;
    bzero(&end,sizeof(cgc_size_t));
char word [ MAX_AC_LEN ];
    bzero(&word,( MAX_AC_LEN *sizeof(char) ) );
    {char word [ MAX_AC_LEN ]; word [ ( MAX_AC_LEN )-1 ] = (char)(ac_queue_head); }
    {int dummy; dummy = (int)(ac_queue_head); }
    {cgc_size_t i; i = (cgc_size_t)(ac_queue_head); }
    {int j; j = (int)(ac_queue_head); }
    {cgc_size_t start; start = (cgc_size_t)(ac_queue_head); }
    {cgc_size_t end; end = (cgc_size_t)(ac_queue_head); }
    {unsigned long tlv_size_0; tlv_size_0 = (unsigned long)(ac_queue_head); }
    {int diff; diff = (int)(ac_queue_head); }
    {int tlv1; tlv1 = (int)(ac_queue_head); }
    {void * tlv6; tlv6 = (void *)(ac_queue_head); }
    {void * tlv5; tlv5 = (void *)(ac_queue_head); }
    {cgc_size_t tlv4; tlv4 = (cgc_size_t)(ac_queue_head); }
    {char * newbuf; newbuf = (char *)(ac_queue_head); }
    {void * tlv14; tlv14 = (void *)(ac_queue_head); }
    {cgc_size_t tlv12; tlv12 = (cgc_size_t)(ac_queue_head); }
    {void * tlv17; tlv17 = (void *)(ac_queue_head); }
    {void * tlv16; tlv16 = (void *)(ac_queue_head); }
    {cgc_size_t tlv15; tlv15 = (cgc_size_t)(ac_queue_head); }
    {void * tlv20; tlv20 = (void *)(ac_queue_head); }
    {void * tlv19; tlv19 = (void *)(ac_queue_head); }
    {cgc_size_t tlv18; tlv18 = (cgc_size_t)(ac_queue_head); }
    {void * tlv23; tlv23 = (void *)(ac_queue_head); }
    {void * tlv22; tlv22 = (void *)(ac_queue_head); }
    {cgc_size_t tlv21; tlv21 = (cgc_size_t)(ac_queue_head); }
}
void fix_ingred_ac_2_2_1(){
cgc_size_t i;
    bzero(&i,sizeof(cgc_size_t));
cgc_size_t start;
    bzero(&start,sizeof(cgc_size_t));
cgc_size_t end;
    bzero(&end,sizeof(cgc_size_t));
char word [ MAX_AC_LEN ];
    bzero(&word,( MAX_AC_LEN *sizeof(char) ) );
    {if (ac_queue){    i = 0;
         char word [ MAX_AC_LEN ]; word [ ( MAX_AC_LEN )-1 ] = (char)(ac_queue [ i ] . start); }}
    {if (ac_queue){    i = 0;
         int dummy; dummy = (int)(ac_queue [ i ] . start); }}
    {if (ac_queue){    i = 0;
         int j; j = (int)(ac_queue [ i ] . start); }}
    {if (ac_queue){    i = 0;
         cgc_size_t end; end = (cgc_size_t)(ac_queue [ i ] . start); }}
    {if (ac_queue){    i = 0;
         unsigned long tlv_size_0; tlv_size_0 = (unsigned long)(ac_queue [ i ] . start); }}
    {if (ac_queue){    i = 0;
         int diff; diff = (int)(ac_queue [ i ] . start); }}
    {if (ac_queue){    i = 0;
         int tlv1; tlv1 = (int)(ac_queue [ i ] . start); }}
    {if (ac_queue){    i = 0;
         void * tlv6; tlv6 = (void *)(ac_queue [ i ] . start); }}
    {if (ac_queue){    i = 0;
         void * tlv5; tlv5 = (void *)(ac_queue [ i ] . start); }}
    {if (ac_queue){    i = 0;
         cgc_size_t tlv4; tlv4 = (cgc_size_t)(ac_queue [ i ] . start); }}
    {if (ac_queue){    i = 0;
         char * newbuf; newbuf = (char *)(ac_queue [ i ] . start); }}
    {if (ac_queue){    i = 0;
         void * tlv14; tlv14 = (void *)(ac_queue [ i ] . start); }}
    {if (ac_queue){    i = 0;
         cgc_size_t tlv12; tlv12 = (cgc_size_t)(ac_queue [ i ] . start); }}
    {if (ac_queue){    i = 0;
         void * tlv17; tlv17 = (void *)(ac_queue [ i ] . start); }}
    {if (ac_queue){    i = 0;
         void * tlv16; tlv16 = (void *)(ac_queue [ i ] . start); }}
    {if (ac_queue){    i = 0;
         cgc_size_t tlv15; tlv15 = (cgc_size_t)(ac_queue [ i ] . start); }}
    {if (ac_queue){    i = 0;
         void * tlv20; tlv20 = (void *)(ac_queue [ i ] . start); }}
    {if (ac_queue){    i = 0;
         void * tlv19; tlv19 = (void *)(ac_queue [ i ] . start); }}
    {if (ac_queue){    i = 0;
         cgc_size_t tlv18; tlv18 = (cgc_size_t)(ac_queue [ i ] . start); }}
    {if (ac_queue){    i = 0;
         void * tlv23; tlv23 = (void *)(ac_queue [ i ] . start); }}
    {if (ac_queue){    i = 0;
         void * tlv22; tlv22 = (void *)(ac_queue [ i ] . start); }}
    {if (ac_queue){    i = 0;
         cgc_size_t tlv21; tlv21 = (cgc_size_t)(ac_queue [ i ] . start); }}
}
void fix_ingred_ac_2_2_2(){
cgc_size_t i;
    bzero(&i,sizeof(cgc_size_t));
cgc_size_t start;
    bzero(&start,sizeof(cgc_size_t));
cgc_size_t end;
    bzero(&end,sizeof(cgc_size_t));
char word [ MAX_AC_LEN ];
    bzero(&word,( MAX_AC_LEN *sizeof(char) ) );
    {if (ac_queue){    i = 0;
         char word [ MAX_AC_LEN ]; word [ ( MAX_AC_LEN )-1 ] = (char)(ac_queue [ i ] . end); }}
    {if (ac_queue){    i = 0;
         int dummy; dummy = (int)(ac_queue [ i ] . end); }}
    {if (ac_queue){    i = 0;
         int j; j = (int)(ac_queue [ i ] . end); }}
    {if (ac_queue){    i = 0;
         cgc_size_t start; start = (cgc_size_t)(ac_queue [ i ] . end); }}
    {if (ac_queue){    i = 0;
         unsigned long tlv_size_0; tlv_size_0 = (unsigned long)(ac_queue [ i ] . end); }}
    {if (ac_queue){    i = 0;
         int diff; diff = (int)(ac_queue [ i ] . end); }}
    {if (ac_queue){    i = 0;
         int tlv1; tlv1 = (int)(ac_queue [ i ] . end); }}
    {if (ac_queue){    i = 0;
         void * tlv6; tlv6 = (void *)(ac_queue [ i ] . end); }}
    {if (ac_queue){    i = 0;
         void * tlv5; tlv5 = (void *)(ac_queue [ i ] . end); }}
    {if (ac_queue){    i = 0;
         cgc_size_t tlv4; tlv4 = (cgc_size_t)(ac_queue [ i ] . end); }}
    {if (ac_queue){    i = 0;
         char * newbuf; newbuf = (char *)(ac_queue [ i ] . end); }}
    {if (ac_queue){    i = 0;
         void * tlv14; tlv14 = (void *)(ac_queue [ i ] . end); }}
    {if (ac_queue){    i = 0;
         cgc_size_t tlv12; tlv12 = (cgc_size_t)(ac_queue [ i ] . end); }}
    {if (ac_queue){    i = 0;
         void * tlv17; tlv17 = (void *)(ac_queue [ i ] . end); }}
    {if (ac_queue){    i = 0;
         void * tlv16; tlv16 = (void *)(ac_queue [ i ] . end); }}
    {if (ac_queue){    i = 0;
         cgc_size_t tlv15; tlv15 = (cgc_size_t)(ac_queue [ i ] . end); }}
    {if (ac_queue){    i = 0;
         void * tlv20; tlv20 = (void *)(ac_queue [ i ] . end); }}
    {if (ac_queue){    i = 0;
         void * tlv19; tlv19 = (void *)(ac_queue [ i ] . end); }}
    {if (ac_queue){    i = 0;
         cgc_size_t tlv18; tlv18 = (cgc_size_t)(ac_queue [ i ] . end); }}
    {if (ac_queue){    i = 0;
         void * tlv23; tlv23 = (void *)(ac_queue [ i ] . end); }}
    {if (ac_queue){    i = 0;
         void * tlv22; tlv22 = (void *)(ac_queue [ i ] . end); }}
    {if (ac_queue){    i = 0;
         cgc_size_t tlv21; tlv21 = (cgc_size_t)(ac_queue [ i ] . end); }}
}
void fix_ingred_ac_2_2_3(){
cgc_size_t i;
    bzero(&i,sizeof(cgc_size_t));
cgc_size_t start;
    bzero(&start,sizeof(cgc_size_t));
cgc_size_t end;
    bzero(&end,sizeof(cgc_size_t));
char word [ MAX_AC_LEN ];
    bzero(&word,( MAX_AC_LEN *sizeof(char) ) );
    {char word [ MAX_AC_LEN ]; word [ ( MAX_AC_LEN )-1 ] = (char)(sizeof ( word )); }
    {int dummy; dummy = (int)(sizeof ( word )); }
    {cgc_size_t i; i = (cgc_size_t)(sizeof ( word )); }
    {int j; j = (int)(sizeof ( word )); }
    {cgc_size_t start; start = (cgc_size_t)(sizeof ( word )); }
    {cgc_size_t end; end = (cgc_size_t)(sizeof ( word )); }
    {unsigned long tlv_size_0; tlv_size_0 = (unsigned long)(sizeof ( word )); }
    {int diff; diff = (int)(sizeof ( word )); }
    {int tlv1; tlv1 = (int)(sizeof ( word )); }
    {void * tlv6; tlv6 = (void *)(sizeof ( word )); }
    {void * tlv5; tlv5 = (void *)(sizeof ( word )); }
    {cgc_size_t tlv4; tlv4 = (cgc_size_t)(sizeof ( word )); }
    {char * newbuf; newbuf = (char *)(sizeof ( word )); }
    {void * tlv14; tlv14 = (void *)(sizeof ( word )); }
    {cgc_size_t tlv12; tlv12 = (cgc_size_t)(sizeof ( word )); }
    {void * tlv17; tlv17 = (void *)(sizeof ( word )); }
    {void * tlv16; tlv16 = (void *)(sizeof ( word )); }
    {cgc_size_t tlv15; tlv15 = (cgc_size_t)(sizeof ( word )); }
    {void * tlv20; tlv20 = (void *)(sizeof ( word )); }
    {void * tlv19; tlv19 = (void *)(sizeof ( word )); }
    {cgc_size_t tlv18; tlv18 = (cgc_size_t)(sizeof ( word )); }
    {void * tlv23; tlv23 = (void *)(sizeof ( word )); }
    {void * tlv22; tlv22 = (void *)(sizeof ( word )); }
    {cgc_size_t tlv21; tlv21 = (cgc_size_t)(sizeof ( word )); }
}
void fix_ingred_ac_2_2_4(){
cgc_size_t i;
    bzero(&i,sizeof(cgc_size_t));
cgc_size_t start;
    bzero(&start,sizeof(cgc_size_t));
cgc_size_t end;
    bzero(&end,sizeof(cgc_size_t));
char word [ MAX_AC_LEN ];
    bzero(&word,( MAX_AC_LEN *sizeof(char) ) );
    {char word [ MAX_AC_LEN ]; word [ ( MAX_AC_LEN )-1 ] = (char)(0); }
    {int dummy; dummy = (int)(0); }
    {cgc_size_t i; i = (cgc_size_t)(0); }
    {int j; j = (int)(0); }
    {cgc_size_t start; start = (cgc_size_t)(0); }
    {cgc_size_t end; end = (cgc_size_t)(0); }
    {unsigned long tlv_size_0; tlv_size_0 = (unsigned long)(0); }
    {int diff; diff = (int)(0); }
    {int tlv1; tlv1 = (int)(0); }
    {void * tlv6; tlv6 = (void *)(0); }
    {void * tlv5; tlv5 = (void *)(0); }
    {cgc_size_t tlv4; tlv4 = (cgc_size_t)(0); }
    {char * newbuf; newbuf = (char *)(0); }
    {void * tlv14; tlv14 = (void *)(0); }
    {cgc_size_t tlv12; tlv12 = (cgc_size_t)(0); }
    {void * tlv17; tlv17 = (void *)(0); }
    {void * tlv16; tlv16 = (void *)(0); }
    {cgc_size_t tlv15; tlv15 = (cgc_size_t)(0); }
    {void * tlv20; tlv20 = (void *)(0); }
    {void * tlv19; tlv19 = (void *)(0); }
    {cgc_size_t tlv18; tlv18 = (cgc_size_t)(0); }
    {void * tlv23; tlv23 = (void *)(0); }
    {void * tlv22; tlv22 = (void *)(0); }
    {cgc_size_t tlv21; tlv21 = (cgc_size_t)(0); }
}
void fix_ingred_ac_2_2(){
fix_ingred_ac_2_2_0();
fix_ingred_ac_2_2_1();
fix_ingred_ac_2_2_2();
fix_ingred_ac_2_2_3();
fix_ingred_ac_2_2_4();
}
void fix_ingred_ac_2_4_9(){
cgc_size_t end;
    bzero(&end,sizeof(cgc_size_t));
cgc_size_t start;
    bzero(&start,sizeof(cgc_size_t));
unsigned long tlv_size_0;
    bzero(&tlv_size_0,sizeof(unsigned long));
    {char word [ MAX_AC_LEN ]; word [ ( MAX_AC_LEN )-1 ] = (char)(end - start); }
    {int dummy; dummy = (int)(end - start); }
    {cgc_size_t i; i = (cgc_size_t)(end - start); }
    {int j; j = (int)(end - start); }
    {unsigned long tlv_size_0; tlv_size_0 = (unsigned long)(end - start); }
    {int diff; diff = (int)(end - start); }
    {int tlv1; tlv1 = (int)(end - start); }
    {void * tlv6; tlv6 = (void *)(end - start); }
    {void * tlv5; tlv5 = (void *)(end - start); }
    {cgc_size_t tlv4; tlv4 = (cgc_size_t)(end - start); }
    {char * newbuf; newbuf = (char *)(end - start); }
    {void * tlv14; tlv14 = (void *)(end - start); }
    {cgc_size_t tlv12; tlv12 = (cgc_size_t)(end - start); }
    {void * tlv17; tlv17 = (void *)(end - start); }
    {void * tlv16; tlv16 = (void *)(end - start); }
    {cgc_size_t tlv15; tlv15 = (cgc_size_t)(end - start); }
    {void * tlv20; tlv20 = (void *)(end - start); }
    {void * tlv19; tlv19 = (void *)(end - start); }
    {cgc_size_t tlv18; tlv18 = (cgc_size_t)(end - start); }
    {void * tlv23; tlv23 = (void *)(end - start); }
    {void * tlv22; tlv22 = (void *)(end - start); }
    {cgc_size_t tlv21; tlv21 = (cgc_size_t)(end - start); }
}
void fix_ingred_ac_2_4_10(){
cgc_size_t end;
    bzero(&end,sizeof(cgc_size_t));
cgc_size_t start;
    bzero(&start,sizeof(cgc_size_t));
unsigned long tlv_size_0;
    bzero(&tlv_size_0,sizeof(unsigned long));
    {char word [ MAX_AC_LEN ]; word [ ( MAX_AC_LEN )-1 ] = (char)(tlv_size_0); }
    {int dummy; dummy = (int)(tlv_size_0); }
    {cgc_size_t i; i = (cgc_size_t)(tlv_size_0); }
    {int j; j = (int)(tlv_size_0); }
    {cgc_size_t start; start = (cgc_size_t)(tlv_size_0); }
    {cgc_size_t end; end = (cgc_size_t)(tlv_size_0); }
    {int diff; diff = (int)(tlv_size_0); }
    {int tlv1; tlv1 = (int)(tlv_size_0); }
    {void * tlv6; tlv6 = (void *)(tlv_size_0); }
    {void * tlv5; tlv5 = (void *)(tlv_size_0); }
    {cgc_size_t tlv4; tlv4 = (cgc_size_t)(tlv_size_0); }
    {char * newbuf; newbuf = (char *)(tlv_size_0); }
    {void * tlv14; tlv14 = (void *)(tlv_size_0); }
    {cgc_size_t tlv12; tlv12 = (cgc_size_t)(tlv_size_0); }
    {void * tlv17; tlv17 = (void *)(tlv_size_0); }
    {void * tlv16; tlv16 = (void *)(tlv_size_0); }
    {cgc_size_t tlv15; tlv15 = (cgc_size_t)(tlv_size_0); }
    {void * tlv20; tlv20 = (void *)(tlv_size_0); }
    {void * tlv19; tlv19 = (void *)(tlv_size_0); }
    {cgc_size_t tlv18; tlv18 = (cgc_size_t)(tlv_size_0); }
    {void * tlv23; tlv23 = (void *)(tlv_size_0); }
    {void * tlv22; tlv22 = (void *)(tlv_size_0); }
    {cgc_size_t tlv21; tlv21 = (cgc_size_t)(tlv_size_0); }
}
void fix_ingred_ac_2_4(){
fix_ingred_ac_2_4_9();
fix_ingred_ac_2_4_10();
}
void fix_ingred_ac_2_5_0(){
char word [ MAX_AC_LEN ];
    bzero(&word,( MAX_AC_LEN *sizeof(char) ) );
cgc_size_t start;
    bzero(&start,sizeof(cgc_size_t));
    {char word [ MAX_AC_LEN ]; word [ ( MAX_AC_LEN )-1 ] = (char)(word); }
    {int dummy; dummy = (int)(word); }
    {cgc_size_t i; i = (cgc_size_t)(word); }
    {int j; j = (int)(word); }
    {cgc_size_t start; start = (cgc_size_t)(word); }
    {cgc_size_t end; end = (cgc_size_t)(word); }
    {unsigned long tlv_size_0; tlv_size_0 = (unsigned long)(word); }
    {int diff; diff = (int)(word); }
    {int tlv1; tlv1 = (int)(word); }
    {void * tlv6; tlv6 = (void *)(word); }
    {void * tlv5; tlv5 = (void *)(word); }
    {cgc_size_t tlv4; tlv4 = (cgc_size_t)(word); }
    {char * newbuf; newbuf = (char *)(word); }
    {void * tlv14; tlv14 = (void *)(word); }
    {cgc_size_t tlv12; tlv12 = (cgc_size_t)(word); }
    {void * tlv17; tlv17 = (void *)(word); }
    {void * tlv16; tlv16 = (void *)(word); }
    {cgc_size_t tlv15; tlv15 = (cgc_size_t)(word); }
    {void * tlv20; tlv20 = (void *)(word); }
    {void * tlv19; tlv19 = (void *)(word); }
    {cgc_size_t tlv18; tlv18 = (cgc_size_t)(word); }
    {void * tlv23; tlv23 = (void *)(word); }
    {void * tlv22; tlv22 = (void *)(word); }
    {cgc_size_t tlv21; tlv21 = (cgc_size_t)(word); }
}
void fix_ingred_ac_2_5_1(){
char word [ MAX_AC_LEN ];
    bzero(&word,( MAX_AC_LEN *sizeof(char) ) );
cgc_size_t start;
    bzero(&start,sizeof(cgc_size_t));
    {if (ac_buffer){    start = 0;
         char word [ MAX_AC_LEN ]; word [ ( MAX_AC_LEN )-1 ] = (char)(& ac_buffer [ start ]); }}
    {if (ac_buffer){    start = 0;
         int dummy; dummy = (int)(& ac_buffer [ start ]); }}
    {if (ac_buffer){    start = 0;
         cgc_size_t i; i = (cgc_size_t)(& ac_buffer [ start ]); }}
    {if (ac_buffer){    start = 0;
         int j; j = (int)(& ac_buffer [ start ]); }}
    {if (ac_buffer){    start = 0;
         cgc_size_t end; end = (cgc_size_t)(& ac_buffer [ start ]); }}
    {if (ac_buffer){    start = 0;
         unsigned long tlv_size_0; tlv_size_0 = (unsigned long)(& ac_buffer [ start ]); }}
    {if (ac_buffer){    start = 0;
         int diff; diff = (int)(& ac_buffer [ start ]); }}
    {if (ac_buffer){    start = 0;
         int tlv1; tlv1 = (int)(& ac_buffer [ start ]); }}
    {if (ac_buffer){    start = 0;
         void * tlv6; tlv6 = (void *)(& ac_buffer [ start ]); }}
    {if (ac_buffer){    start = 0;
         void * tlv5; tlv5 = (void *)(& ac_buffer [ start ]); }}
    {if (ac_buffer){    start = 0;
         cgc_size_t tlv4; tlv4 = (cgc_size_t)(& ac_buffer [ start ]); }}
    {if (ac_buffer){    start = 0;
         char * newbuf; newbuf = (char *)(& ac_buffer [ start ]); }}
    {if (ac_buffer){    start = 0;
         void * tlv14; tlv14 = (void *)(& ac_buffer [ start ]); }}
    {if (ac_buffer){    start = 0;
         cgc_size_t tlv12; tlv12 = (cgc_size_t)(& ac_buffer [ start ]); }}
    {if (ac_buffer){    start = 0;
         void * tlv17; tlv17 = (void *)(& ac_buffer [ start ]); }}
    {if (ac_buffer){    start = 0;
         void * tlv16; tlv16 = (void *)(& ac_buffer [ start ]); }}
    {if (ac_buffer){    start = 0;
         cgc_size_t tlv15; tlv15 = (cgc_size_t)(& ac_buffer [ start ]); }}
    {if (ac_buffer){    start = 0;
         void * tlv20; tlv20 = (void *)(& ac_buffer [ start ]); }}
    {if (ac_buffer){    start = 0;
         void * tlv19; tlv19 = (void *)(& ac_buffer [ start ]); }}
    {if (ac_buffer){    start = 0;
         cgc_size_t tlv18; tlv18 = (cgc_size_t)(& ac_buffer [ start ]); }}
    {if (ac_buffer){    start = 0;
         void * tlv23; tlv23 = (void *)(& ac_buffer [ start ]); }}
    {if (ac_buffer){    start = 0;
         void * tlv22; tlv22 = (void *)(& ac_buffer [ start ]); }}
    {if (ac_buffer){    start = 0;
         cgc_size_t tlv21; tlv21 = (cgc_size_t)(& ac_buffer [ start ]); }}
}
void fix_ingred_ac_2_5(){
fix_ingred_ac_2_5_0();
fix_ingred_ac_2_5_1();
}
void fix_ingred_ac_2_8_10(){
int j;
    bzero(&j,sizeof(int));
    {char word [ MAX_AC_LEN ]; word [ ( MAX_AC_LEN )-1 ] = (char)(j); }
    {int dummy; dummy = (int)(j); }
    {cgc_size_t i; i = (cgc_size_t)(j); }
    {cgc_size_t start; start = (cgc_size_t)(j); }
    {cgc_size_t end; end = (cgc_size_t)(j); }
    {unsigned long tlv_size_0; tlv_size_0 = (unsigned long)(j); }
    {int diff; diff = (int)(j); }
    {int tlv1; tlv1 = (int)(j); }
    {void * tlv6; tlv6 = (void *)(j); }
    {void * tlv5; tlv5 = (void *)(j); }
    {cgc_size_t tlv4; tlv4 = (cgc_size_t)(j); }
    {char * newbuf; newbuf = (char *)(j); }
    {void * tlv14; tlv14 = (void *)(j); }
    {cgc_size_t tlv12; tlv12 = (cgc_size_t)(j); }
    {void * tlv17; tlv17 = (void *)(j); }
    {void * tlv16; tlv16 = (void *)(j); }
    {cgc_size_t tlv15; tlv15 = (cgc_size_t)(j); }
    {void * tlv20; tlv20 = (void *)(j); }
    {void * tlv19; tlv19 = (void *)(j); }
    {cgc_size_t tlv18; tlv18 = (cgc_size_t)(j); }
    {void * tlv23; tlv23 = (void *)(j); }
    {void * tlv22; tlv22 = (void *)(j); }
    {cgc_size_t tlv21; tlv21 = (cgc_size_t)(j); }
}
void fix_ingred_ac_2_8_11(){
int j;
    bzero(&j,sizeof(int));
    {char word [ MAX_AC_LEN ]; word [ ( MAX_AC_LEN )-1 ] = (char)(cgc_num_words); }
    {int dummy; dummy = (int)(cgc_num_words); }
    {cgc_size_t i; i = (cgc_size_t)(cgc_num_words); }
    {int j; j = (int)(cgc_num_words); }
    {cgc_size_t start; start = (cgc_size_t)(cgc_num_words); }
    {cgc_size_t end; end = (cgc_size_t)(cgc_num_words); }
    {unsigned long tlv_size_0; tlv_size_0 = (unsigned long)(cgc_num_words); }
    {int diff; diff = (int)(cgc_num_words); }
    {int tlv1; tlv1 = (int)(cgc_num_words); }
    {void * tlv6; tlv6 = (void *)(cgc_num_words); }
    {void * tlv5; tlv5 = (void *)(cgc_num_words); }
    {cgc_size_t tlv4; tlv4 = (cgc_size_t)(cgc_num_words); }
    {char * newbuf; newbuf = (char *)(cgc_num_words); }
    {void * tlv14; tlv14 = (void *)(cgc_num_words); }
    {cgc_size_t tlv12; tlv12 = (cgc_size_t)(cgc_num_words); }
    {void * tlv17; tlv17 = (void *)(cgc_num_words); }
    {void * tlv16; tlv16 = (void *)(cgc_num_words); }
    {cgc_size_t tlv15; tlv15 = (cgc_size_t)(cgc_num_words); }
    {void * tlv20; tlv20 = (void *)(cgc_num_words); }
    {void * tlv19; tlv19 = (void *)(cgc_num_words); }
    {cgc_size_t tlv18; tlv18 = (cgc_size_t)(cgc_num_words); }
    {void * tlv23; tlv23 = (void *)(cgc_num_words); }
    {void * tlv22; tlv22 = (void *)(cgc_num_words); }
    {cgc_size_t tlv21; tlv21 = (cgc_size_t)(cgc_num_words); }
}
void fix_ingred_ac_2_8(){
fix_ingred_ac_2_8_10();
fix_ingred_ac_2_8_11();
}
void fix_ingred_ac_2_10_12(){
int tlv1;
    bzero(&tlv1,sizeof(int));
    {char word [ MAX_AC_LEN ]; word [ ( MAX_AC_LEN )-1 ] = (char)(tlv1); }
    {int dummy; dummy = (int)(tlv1); }
    {cgc_size_t i; i = (cgc_size_t)(tlv1); }
    {int j; j = (int)(tlv1); }
    {cgc_size_t start; start = (cgc_size_t)(tlv1); }
    {cgc_size_t end; end = (cgc_size_t)(tlv1); }
    {unsigned long tlv_size_0; tlv_size_0 = (unsigned long)(tlv1); }
    {int diff; diff = (int)(tlv1); }
    {void * tlv6; tlv6 = (void *)(tlv1); }
    {void * tlv5; tlv5 = (void *)(tlv1); }
    {cgc_size_t tlv4; tlv4 = (cgc_size_t)(tlv1); }
    {char * newbuf; newbuf = (char *)(tlv1); }
    {void * tlv14; tlv14 = (void *)(tlv1); }
    {cgc_size_t tlv12; tlv12 = (cgc_size_t)(tlv1); }
    {void * tlv17; tlv17 = (void *)(tlv1); }
    {void * tlv16; tlv16 = (void *)(tlv1); }
    {cgc_size_t tlv15; tlv15 = (cgc_size_t)(tlv1); }
    {void * tlv20; tlv20 = (void *)(tlv1); }
    {void * tlv19; tlv19 = (void *)(tlv1); }
    {cgc_size_t tlv18; tlv18 = (cgc_size_t)(tlv1); }
    {void * tlv23; tlv23 = (void *)(tlv1); }
    {void * tlv22; tlv22 = (void *)(tlv1); }
    {cgc_size_t tlv21; tlv21 = (cgc_size_t)(tlv1); }
}
void fix_ingred_ac_2_10(){
fix_ingred_ac_2_10_12();
}
void fix_ingred_ac_2_11_0(){
char tlv11_ref;
    bzero(&tlv11_ref,1*sizeof(char));
const char * tlv11 = &tlv11_ref;
char tlv13_ref;
    bzero(&tlv13_ref,1*sizeof(char));
const char * tlv13 = &tlv13_ref;
    {char word [ MAX_AC_LEN ]; word [ ( MAX_AC_LEN )-1 ] = (char)(cgc_strlen ( tlv11 ) - cgc_strlen ( tlv13 )); }
    {int dummy; dummy = (int)(cgc_strlen ( tlv11 ) - cgc_strlen ( tlv13 )); }
    {cgc_size_t i; i = (cgc_size_t)(cgc_strlen ( tlv11 ) - cgc_strlen ( tlv13 )); }
    {int j; j = (int)(cgc_strlen ( tlv11 ) - cgc_strlen ( tlv13 )); }
    {cgc_size_t start; start = (cgc_size_t)(cgc_strlen ( tlv11 ) - cgc_strlen ( tlv13 )); }
    {cgc_size_t end; end = (cgc_size_t)(cgc_strlen ( tlv11 ) - cgc_strlen ( tlv13 )); }
    {unsigned long tlv_size_0; tlv_size_0 = (unsigned long)(cgc_strlen ( tlv11 ) - cgc_strlen ( tlv13 )); }
    {int diff; diff = (int)(cgc_strlen ( tlv11 ) - cgc_strlen ( tlv13 )); }
    {int tlv1; tlv1 = (int)(cgc_strlen ( tlv11 ) - cgc_strlen ( tlv13 )); }
    {void * tlv6; tlv6 = (void *)(cgc_strlen ( tlv11 ) - cgc_strlen ( tlv13 )); }
    {void * tlv5; tlv5 = (void *)(cgc_strlen ( tlv11 ) - cgc_strlen ( tlv13 )); }
    {cgc_size_t tlv4; tlv4 = (cgc_size_t)(cgc_strlen ( tlv11 ) - cgc_strlen ( tlv13 )); }
    {char * newbuf; newbuf = (char *)(cgc_strlen ( tlv11 ) - cgc_strlen ( tlv13 )); }
    {void * tlv14; tlv14 = (void *)(cgc_strlen ( tlv11 ) - cgc_strlen ( tlv13 )); }
    {cgc_size_t tlv12; tlv12 = (cgc_size_t)(cgc_strlen ( tlv11 ) - cgc_strlen ( tlv13 )); }
    {void * tlv17; tlv17 = (void *)(cgc_strlen ( tlv11 ) - cgc_strlen ( tlv13 )); }
    {void * tlv16; tlv16 = (void *)(cgc_strlen ( tlv11 ) - cgc_strlen ( tlv13 )); }
    {cgc_size_t tlv15; tlv15 = (cgc_size_t)(cgc_strlen ( tlv11 ) - cgc_strlen ( tlv13 )); }
    {void * tlv20; tlv20 = (void *)(cgc_strlen ( tlv11 ) - cgc_strlen ( tlv13 )); }
    {void * tlv19; tlv19 = (void *)(cgc_strlen ( tlv11 ) - cgc_strlen ( tlv13 )); }
    {cgc_size_t tlv18; tlv18 = (cgc_size_t)(cgc_strlen ( tlv11 ) - cgc_strlen ( tlv13 )); }
    {void * tlv23; tlv23 = (void *)(cgc_strlen ( tlv11 ) - cgc_strlen ( tlv13 )); }
    {void * tlv22; tlv22 = (void *)(cgc_strlen ( tlv11 ) - cgc_strlen ( tlv13 )); }
    {cgc_size_t tlv21; tlv21 = (cgc_size_t)(cgc_strlen ( tlv11 ) - cgc_strlen ( tlv13 )); }
}
void fix_ingred_ac_2_11(){
fix_ingred_ac_2_11_0();
}
void fix_ingred_ac_2_13_14(){
int diff;
    bzero(&diff,sizeof(int));
    {char word [ MAX_AC_LEN ]; word [ ( MAX_AC_LEN )-1 ] = (char)(diff); }
    {int dummy; dummy = (int)(diff); }
    {cgc_size_t i; i = (cgc_size_t)(diff); }
    {int j; j = (int)(diff); }
    {cgc_size_t start; start = (cgc_size_t)(diff); }
    {cgc_size_t end; end = (cgc_size_t)(diff); }
    {unsigned long tlv_size_0; tlv_size_0 = (unsigned long)(diff); }
    {int tlv1; tlv1 = (int)(diff); }
    {void * tlv6; tlv6 = (void *)(diff); }
    {void * tlv5; tlv5 = (void *)(diff); }
    {cgc_size_t tlv4; tlv4 = (cgc_size_t)(diff); }
    {char * newbuf; newbuf = (char *)(diff); }
    {void * tlv14; tlv14 = (void *)(diff); }
    {cgc_size_t tlv12; tlv12 = (cgc_size_t)(diff); }
    {void * tlv17; tlv17 = (void *)(diff); }
    {void * tlv16; tlv16 = (void *)(diff); }
    {cgc_size_t tlv15; tlv15 = (cgc_size_t)(diff); }
    {void * tlv20; tlv20 = (void *)(diff); }
    {void * tlv19; tlv19 = (void *)(diff); }
    {cgc_size_t tlv18; tlv18 = (cgc_size_t)(diff); }
    {void * tlv23; tlv23 = (void *)(diff); }
    {void * tlv22; tlv22 = (void *)(diff); }
    {cgc_size_t tlv21; tlv21 = (cgc_size_t)(diff); }
}
void fix_ingred_ac_2_13(){
fix_ingred_ac_2_13_14();
}
void fix_ingred_ac_2_14_1(){
cgc_size_t end;
    bzero(&end,sizeof(cgc_size_t));
int diff;
    bzero(&diff,sizeof(int));
    {if (ac_buffer){    end = 0;
         char word [ MAX_AC_LEN ]; word [ ( MAX_AC_LEN )-1 ] = (char)(& ac_buffer [ end ]); }}
    {if (ac_buffer){    end = 0;
         int dummy; dummy = (int)(& ac_buffer [ end ]); }}
    {if (ac_buffer){    end = 0;
         cgc_size_t i; i = (cgc_size_t)(& ac_buffer [ end ]); }}
    {if (ac_buffer){    end = 0;
         int j; j = (int)(& ac_buffer [ end ]); }}
    {if (ac_buffer){    end = 0;
         cgc_size_t start; start = (cgc_size_t)(& ac_buffer [ end ]); }}
    {if (ac_buffer){    end = 0;
         unsigned long tlv_size_0; tlv_size_0 = (unsigned long)(& ac_buffer [ end ]); }}
    {if (ac_buffer){    end = 0;
         int diff; diff = (int)(& ac_buffer [ end ]); }}
    {if (ac_buffer){    end = 0;
         int tlv1; tlv1 = (int)(& ac_buffer [ end ]); }}
    {if (ac_buffer){    end = 0;
         void * tlv6; tlv6 = (void *)(& ac_buffer [ end ]); }}
    {if (ac_buffer){    end = 0;
         void * tlv5; tlv5 = (void *)(& ac_buffer [ end ]); }}
    {if (ac_buffer){    end = 0;
         cgc_size_t tlv4; tlv4 = (cgc_size_t)(& ac_buffer [ end ]); }}
    {if (ac_buffer){    end = 0;
         char * newbuf; newbuf = (char *)(& ac_buffer [ end ]); }}
    {if (ac_buffer){    end = 0;
         void * tlv14; tlv14 = (void *)(& ac_buffer [ end ]); }}
    {if (ac_buffer){    end = 0;
         cgc_size_t tlv12; tlv12 = (cgc_size_t)(& ac_buffer [ end ]); }}
    {if (ac_buffer){    end = 0;
         void * tlv17; tlv17 = (void *)(& ac_buffer [ end ]); }}
    {if (ac_buffer){    end = 0;
         void * tlv16; tlv16 = (void *)(& ac_buffer [ end ]); }}
    {if (ac_buffer){    end = 0;
         cgc_size_t tlv15; tlv15 = (cgc_size_t)(& ac_buffer [ end ]); }}
    {if (ac_buffer){    end = 0;
         void * tlv20; tlv20 = (void *)(& ac_buffer [ end ]); }}
    {if (ac_buffer){    end = 0;
         void * tlv19; tlv19 = (void *)(& ac_buffer [ end ]); }}
    {if (ac_buffer){    end = 0;
         cgc_size_t tlv18; tlv18 = (cgc_size_t)(& ac_buffer [ end ]); }}
    {if (ac_buffer){    end = 0;
         void * tlv23; tlv23 = (void *)(& ac_buffer [ end ]); }}
    {if (ac_buffer){    end = 0;
         void * tlv22; tlv22 = (void *)(& ac_buffer [ end ]); }}
    {if (ac_buffer){    end = 0;
         cgc_size_t tlv21; tlv21 = (cgc_size_t)(& ac_buffer [ end ]); }}
}
void fix_ingred_ac_2_14_2(){
cgc_size_t end;
    bzero(&end,sizeof(cgc_size_t));
int diff;
    bzero(&diff,sizeof(int));
    {char word [ MAX_AC_LEN ]; word [ ( MAX_AC_LEN )-1 ] = (char)(ac_idx - end); }
    {int dummy; dummy = (int)(ac_idx - end); }
    {cgc_size_t i; i = (cgc_size_t)(ac_idx - end); }
    {int j; j = (int)(ac_idx - end); }
    {cgc_size_t start; start = (cgc_size_t)(ac_idx - end); }
    {unsigned long tlv_size_0; tlv_size_0 = (unsigned long)(ac_idx - end); }
    {int diff; diff = (int)(ac_idx - end); }
    {int tlv1; tlv1 = (int)(ac_idx - end); }
    {void * tlv6; tlv6 = (void *)(ac_idx - end); }
    {void * tlv5; tlv5 = (void *)(ac_idx - end); }
    {cgc_size_t tlv4; tlv4 = (cgc_size_t)(ac_idx - end); }
    {char * newbuf; newbuf = (char *)(ac_idx - end); }
    {void * tlv14; tlv14 = (void *)(ac_idx - end); }
    {cgc_size_t tlv12; tlv12 = (cgc_size_t)(ac_idx - end); }
    {void * tlv17; tlv17 = (void *)(ac_idx - end); }
    {void * tlv16; tlv16 = (void *)(ac_idx - end); }
    {cgc_size_t tlv15; tlv15 = (cgc_size_t)(ac_idx - end); }
    {void * tlv20; tlv20 = (void *)(ac_idx - end); }
    {void * tlv19; tlv19 = (void *)(ac_idx - end); }
    {cgc_size_t tlv18; tlv18 = (cgc_size_t)(ac_idx - end); }
    {void * tlv23; tlv23 = (void *)(ac_idx - end); }
    {void * tlv22; tlv22 = (void *)(ac_idx - end); }
    {cgc_size_t tlv21; tlv21 = (cgc_size_t)(ac_idx - end); }
}
void fix_ingred_ac_2_14(){
fix_ingred_ac_2_14_1();
fix_ingred_ac_2_14_2();
}
void fix_ingred_ac_2_15_0(){
int diff;
    bzero(&diff,sizeof(int));
    {char word [ MAX_AC_LEN ]; word [ ( MAX_AC_LEN )-1 ] = (char)(ac_buffer); }
    {int dummy; dummy = (int)(ac_buffer); }
    {cgc_size_t i; i = (cgc_size_t)(ac_buffer); }
    {int j; j = (int)(ac_buffer); }
    {cgc_size_t start; start = (cgc_size_t)(ac_buffer); }
    {cgc_size_t end; end = (cgc_size_t)(ac_buffer); }
    {unsigned long tlv_size_0; tlv_size_0 = (unsigned long)(ac_buffer); }
    {int diff; diff = (int)(ac_buffer); }
    {int tlv1; tlv1 = (int)(ac_buffer); }
    {void * tlv6; tlv6 = (void *)(ac_buffer); }
    {void * tlv5; tlv5 = (void *)(ac_buffer); }
    {cgc_size_t tlv4; tlv4 = (cgc_size_t)(ac_buffer); }
    {char * newbuf; newbuf = (char *)(ac_buffer); }
    {void * tlv14; tlv14 = (void *)(ac_buffer); }
    {cgc_size_t tlv12; tlv12 = (cgc_size_t)(ac_buffer); }
    {void * tlv17; tlv17 = (void *)(ac_buffer); }
    {void * tlv16; tlv16 = (void *)(ac_buffer); }
    {cgc_size_t tlv15; tlv15 = (cgc_size_t)(ac_buffer); }
    {void * tlv20; tlv20 = (void *)(ac_buffer); }
    {void * tlv19; tlv19 = (void *)(ac_buffer); }
    {cgc_size_t tlv18; tlv18 = (cgc_size_t)(ac_buffer); }
    {void * tlv23; tlv23 = (void *)(ac_buffer); }
    {void * tlv22; tlv22 = (void *)(ac_buffer); }
    {cgc_size_t tlv21; tlv21 = (cgc_size_t)(ac_buffer); }
}
void fix_ingred_ac_2_15_1(){
int diff;
    bzero(&diff,sizeof(int));
    {char word [ MAX_AC_LEN ]; word [ ( MAX_AC_LEN )-1 ] = (char)(ac_idx + 1 + diff); }
    {int dummy; dummy = (int)(ac_idx + 1 + diff); }
    {cgc_size_t i; i = (cgc_size_t)(ac_idx + 1 + diff); }
    {int j; j = (int)(ac_idx + 1 + diff); }
    {cgc_size_t start; start = (cgc_size_t)(ac_idx + 1 + diff); }
    {cgc_size_t end; end = (cgc_size_t)(ac_idx + 1 + diff); }
    {unsigned long tlv_size_0; tlv_size_0 = (unsigned long)(ac_idx + 1 + diff); }
    {int tlv1; tlv1 = (int)(ac_idx + 1 + diff); }
    {void * tlv6; tlv6 = (void *)(ac_idx + 1 + diff); }
    {void * tlv5; tlv5 = (void *)(ac_idx + 1 + diff); }
    {cgc_size_t tlv4; tlv4 = (cgc_size_t)(ac_idx + 1 + diff); }
    {char * newbuf; newbuf = (char *)(ac_idx + 1 + diff); }
    {void * tlv14; tlv14 = (void *)(ac_idx + 1 + diff); }
    {cgc_size_t tlv12; tlv12 = (cgc_size_t)(ac_idx + 1 + diff); }
    {void * tlv17; tlv17 = (void *)(ac_idx + 1 + diff); }
    {void * tlv16; tlv16 = (void *)(ac_idx + 1 + diff); }
    {cgc_size_t tlv15; tlv15 = (cgc_size_t)(ac_idx + 1 + diff); }
    {void * tlv20; tlv20 = (void *)(ac_idx + 1 + diff); }
    {void * tlv19; tlv19 = (void *)(ac_idx + 1 + diff); }
    {cgc_size_t tlv18; tlv18 = (cgc_size_t)(ac_idx + 1 + diff); }
    {void * tlv23; tlv23 = (void *)(ac_idx + 1 + diff); }
    {void * tlv22; tlv22 = (void *)(ac_idx + 1 + diff); }
    {cgc_size_t tlv21; tlv21 = (cgc_size_t)(ac_idx + 1 + diff); }
}
void fix_ingred_ac_2_15(){
fix_ingred_ac_2_15_0();
fix_ingred_ac_2_15_1();
}
void fix_ingred_ac_2_16_16(){
char newbuf_ref;
    bzero(&newbuf_ref,1*sizeof(char));
char * newbuf = &newbuf_ref;
    {char word [ MAX_AC_LEN ]; word [ ( MAX_AC_LEN )-1 ] = (char)(newbuf); }
    {int dummy; dummy = (int)(newbuf); }
    {cgc_size_t i; i = (cgc_size_t)(newbuf); }
    {int j; j = (int)(newbuf); }
    {cgc_size_t start; start = (cgc_size_t)(newbuf); }
    {cgc_size_t end; end = (cgc_size_t)(newbuf); }
    {unsigned long tlv_size_0; tlv_size_0 = (unsigned long)(newbuf); }
    {int diff; diff = (int)(newbuf); }
    {int tlv1; tlv1 = (int)(newbuf); }
    {void * tlv6; tlv6 = (void *)(newbuf); }
    {void * tlv5; tlv5 = (void *)(newbuf); }
    {cgc_size_t tlv4; tlv4 = (cgc_size_t)(newbuf); }
    {void * tlv14; tlv14 = (void *)(newbuf); }
    {cgc_size_t tlv12; tlv12 = (cgc_size_t)(newbuf); }
    {void * tlv17; tlv17 = (void *)(newbuf); }
    {void * tlv16; tlv16 = (void *)(newbuf); }
    {cgc_size_t tlv15; tlv15 = (cgc_size_t)(newbuf); }
    {void * tlv20; tlv20 = (void *)(newbuf); }
    {void * tlv19; tlv19 = (void *)(newbuf); }
    {cgc_size_t tlv18; tlv18 = (cgc_size_t)(newbuf); }
    {void * tlv23; tlv23 = (void *)(newbuf); }
    {void * tlv22; tlv22 = (void *)(newbuf); }
    {cgc_size_t tlv21; tlv21 = (cgc_size_t)(newbuf); }
}
void fix_ingred_ac_2_16_17(){
char newbuf_ref;
    bzero(&newbuf_ref,1*sizeof(char));
char * newbuf = &newbuf_ref;
    {char word [ MAX_AC_LEN ]; word [ ( MAX_AC_LEN )-1 ] = (char)(NULL); }
    {int dummy; dummy = (int)(NULL); }
    {cgc_size_t i; i = (cgc_size_t)(NULL); }
    {int j; j = (int)(NULL); }
    {cgc_size_t start; start = (cgc_size_t)(NULL); }
    {cgc_size_t end; end = (cgc_size_t)(NULL); }
    {unsigned long tlv_size_0; tlv_size_0 = (unsigned long)(NULL); }
    {int diff; diff = (int)(NULL); }
    {int tlv1; tlv1 = (int)(NULL); }
    {void * tlv6; tlv6 = (void *)(NULL); }
    {void * tlv5; tlv5 = (void *)(NULL); }
    {cgc_size_t tlv4; tlv4 = (cgc_size_t)(NULL); }
    {char * newbuf; newbuf = (char *)(NULL); }
    {void * tlv14; tlv14 = (void *)(NULL); }
    {cgc_size_t tlv12; tlv12 = (cgc_size_t)(NULL); }
    {void * tlv17; tlv17 = (void *)(NULL); }
    {void * tlv16; tlv16 = (void *)(NULL); }
    {cgc_size_t tlv15; tlv15 = (cgc_size_t)(NULL); }
    {void * tlv20; tlv20 = (void *)(NULL); }
    {void * tlv19; tlv19 = (void *)(NULL); }
    {cgc_size_t tlv18; tlv18 = (cgc_size_t)(NULL); }
    {void * tlv23; tlv23 = (void *)(NULL); }
    {void * tlv22; tlv22 = (void *)(NULL); }
    {cgc_size_t tlv21; tlv21 = (cgc_size_t)(NULL); }
}
void fix_ingred_ac_2_16(){
fix_ingred_ac_2_16_16();
fix_ingred_ac_2_16_17();
}
void fix_ingred_ac_2_19_1(){
int j;
    bzero(&j,sizeof(int));
    {if (word_list){    j = 0;
         char word [ MAX_AC_LEN ]; word [ ( MAX_AC_LEN )-1 ] = (char)(word_list [ j ] . correct); }}
    {if (word_list){    j = 0;
         int dummy; dummy = (int)(word_list [ j ] . correct); }}
    {if (word_list){    j = 0;
         cgc_size_t i; i = (cgc_size_t)(word_list [ j ] . correct); }}
    {if (word_list){    j = 0;
         cgc_size_t start; start = (cgc_size_t)(word_list [ j ] . correct); }}
    {if (word_list){    j = 0;
         cgc_size_t end; end = (cgc_size_t)(word_list [ j ] . correct); }}
    {if (word_list){    j = 0;
         unsigned long tlv_size_0; tlv_size_0 = (unsigned long)(word_list [ j ] . correct); }}
    {if (word_list){    j = 0;
         int diff; diff = (int)(word_list [ j ] . correct); }}
    {if (word_list){    j = 0;
         int tlv1; tlv1 = (int)(word_list [ j ] . correct); }}
    {if (word_list){    j = 0;
         void * tlv6; tlv6 = (void *)(word_list [ j ] . correct); }}
    {if (word_list){    j = 0;
         void * tlv5; tlv5 = (void *)(word_list [ j ] . correct); }}
    {if (word_list){    j = 0;
         cgc_size_t tlv4; tlv4 = (cgc_size_t)(word_list [ j ] . correct); }}
    {if (word_list){    j = 0;
         char * newbuf; newbuf = (char *)(word_list [ j ] . correct); }}
    {if (word_list){    j = 0;
         void * tlv14; tlv14 = (void *)(word_list [ j ] . correct); }}
    {if (word_list){    j = 0;
         cgc_size_t tlv12; tlv12 = (cgc_size_t)(word_list [ j ] . correct); }}
    {if (word_list){    j = 0;
         void * tlv17; tlv17 = (void *)(word_list [ j ] . correct); }}
    {if (word_list){    j = 0;
         void * tlv16; tlv16 = (void *)(word_list [ j ] . correct); }}
    {if (word_list){    j = 0;
         cgc_size_t tlv15; tlv15 = (cgc_size_t)(word_list [ j ] . correct); }}
    {if (word_list){    j = 0;
         void * tlv20; tlv20 = (void *)(word_list [ j ] . correct); }}
    {if (word_list){    j = 0;
         void * tlv19; tlv19 = (void *)(word_list [ j ] . correct); }}
    {if (word_list){    j = 0;
         cgc_size_t tlv18; tlv18 = (cgc_size_t)(word_list [ j ] . correct); }}
    {if (word_list){    j = 0;
         void * tlv23; tlv23 = (void *)(word_list [ j ] . correct); }}
    {if (word_list){    j = 0;
         void * tlv22; tlv22 = (void *)(word_list [ j ] . correct); }}
    {if (word_list){    j = 0;
         cgc_size_t tlv21; tlv21 = (cgc_size_t)(word_list [ j ] . correct); }}
}
void fix_ingred_ac_2_19(){
fix_ingred_ac_2_19_1();
}
void fix_ingred_ac_2_20_0(){
char tlv24_ref;
    bzero(&tlv24_ref,1*sizeof(char));
const char * tlv24 = &tlv24_ref;
    {char word [ MAX_AC_LEN ]; word [ ( MAX_AC_LEN )-1 ] = (char)(cgc_strlen ( tlv24 )); }
    {int dummy; dummy = (int)(cgc_strlen ( tlv24 )); }
    {cgc_size_t i; i = (cgc_size_t)(cgc_strlen ( tlv24 )); }
    {int j; j = (int)(cgc_strlen ( tlv24 )); }
    {cgc_size_t start; start = (cgc_size_t)(cgc_strlen ( tlv24 )); }
    {cgc_size_t end; end = (cgc_size_t)(cgc_strlen ( tlv24 )); }
    {unsigned long tlv_size_0; tlv_size_0 = (unsigned long)(cgc_strlen ( tlv24 )); }
    {int diff; diff = (int)(cgc_strlen ( tlv24 )); }
    {int tlv1; tlv1 = (int)(cgc_strlen ( tlv24 )); }
    {void * tlv6; tlv6 = (void *)(cgc_strlen ( tlv24 )); }
    {void * tlv5; tlv5 = (void *)(cgc_strlen ( tlv24 )); }
    {cgc_size_t tlv4; tlv4 = (cgc_size_t)(cgc_strlen ( tlv24 )); }
    {char * newbuf; newbuf = (char *)(cgc_strlen ( tlv24 )); }
    {void * tlv14; tlv14 = (void *)(cgc_strlen ( tlv24 )); }
    {cgc_size_t tlv12; tlv12 = (cgc_size_t)(cgc_strlen ( tlv24 )); }
    {void * tlv17; tlv17 = (void *)(cgc_strlen ( tlv24 )); }
    {void * tlv16; tlv16 = (void *)(cgc_strlen ( tlv24 )); }
    {cgc_size_t tlv15; tlv15 = (cgc_size_t)(cgc_strlen ( tlv24 )); }
    {void * tlv20; tlv20 = (void *)(cgc_strlen ( tlv24 )); }
    {void * tlv19; tlv19 = (void *)(cgc_strlen ( tlv24 )); }
    {cgc_size_t tlv18; tlv18 = (cgc_size_t)(cgc_strlen ( tlv24 )); }
    {void * tlv23; tlv23 = (void *)(cgc_strlen ( tlv24 )); }
    {void * tlv22; tlv22 = (void *)(cgc_strlen ( tlv24 )); }
    {cgc_size_t tlv21; tlv21 = (cgc_size_t)(cgc_strlen ( tlv24 )); }
}
void fix_ingred_ac_2_20(){
fix_ingred_ac_2_20_0();
}
void fix_ingred_ac_2_22_15(){
cgc_size_t i;
    bzero(&i,sizeof(cgc_size_t));
    {char word [ MAX_AC_LEN ]; word [ ( MAX_AC_LEN )-1 ] = (char)(ac_queue_count); }
    {int dummy; dummy = (int)(ac_queue_count); }
    {cgc_size_t i; i = (cgc_size_t)(ac_queue_count); }
    {int j; j = (int)(ac_queue_count); }
    {cgc_size_t start; start = (cgc_size_t)(ac_queue_count); }
    {cgc_size_t end; end = (cgc_size_t)(ac_queue_count); }
    {unsigned long tlv_size_0; tlv_size_0 = (unsigned long)(ac_queue_count); }
    {int diff; diff = (int)(ac_queue_count); }
    {int tlv1; tlv1 = (int)(ac_queue_count); }
    {void * tlv6; tlv6 = (void *)(ac_queue_count); }
    {void * tlv5; tlv5 = (void *)(ac_queue_count); }
    {cgc_size_t tlv4; tlv4 = (cgc_size_t)(ac_queue_count); }
    {char * newbuf; newbuf = (char *)(ac_queue_count); }
    {void * tlv14; tlv14 = (void *)(ac_queue_count); }
    {cgc_size_t tlv12; tlv12 = (cgc_size_t)(ac_queue_count); }
    {void * tlv17; tlv17 = (void *)(ac_queue_count); }
    {void * tlv16; tlv16 = (void *)(ac_queue_count); }
    {cgc_size_t tlv15; tlv15 = (cgc_size_t)(ac_queue_count); }
    {void * tlv20; tlv20 = (void *)(ac_queue_count); }
    {void * tlv19; tlv19 = (void *)(ac_queue_count); }
    {cgc_size_t tlv18; tlv18 = (cgc_size_t)(ac_queue_count); }
    {void * tlv23; tlv23 = (void *)(ac_queue_count); }
    {void * tlv22; tlv22 = (void *)(ac_queue_count); }
    {cgc_size_t tlv21; tlv21 = (cgc_size_t)(ac_queue_count); }
}
void fix_ingred_ac_2_22(){
fix_ingred_ac_2_22_15();
}
void fix_ingred_ac_2(){
fix_ingred_ac_2_2();
fix_ingred_ac_2_4();
fix_ingred_ac_2_5();
fix_ingred_ac_2_8();
fix_ingred_ac_2_10();
fix_ingred_ac_2_11();
fix_ingred_ac_2_13();
fix_ingred_ac_2_14();
fix_ingred_ac_2_15();
fix_ingred_ac_2_16();
fix_ingred_ac_2_19();
fix_ingred_ac_2_20();
fix_ingred_ac_2_22();
}
void fix_ingred_ac_3_0_5(){
    {cgc_size_t rx; rx = (cgc_size_t)(ac_buffer); }
    {char * buf; buf = (char *)(ac_buffer); }
    {cgc_size_t count; count = (cgc_size_t)(ac_buffer); }
    {char word [ MAX_AC_LEN ]; word [ ( MAX_AC_LEN )-1 ] = (char)(ac_buffer); }
    {char * newbuf; newbuf = (char *)(ac_buffer); }
    {void * tlv11; tlv11 = (void *)(ac_buffer); }
    {cgc_size_t tlv10; tlv10 = (cgc_size_t)(ac_buffer); }
    {void * tlv8; tlv8 = (void *)(ac_buffer); }
    {void * tlv7; tlv7 = (void *)(ac_buffer); }
    {cgc_size_t tlv6; tlv6 = (cgc_size_t)(ac_buffer); }
    {int tlv1; tlv1 = (int)(ac_buffer); }
    {int tlv2; tlv2 = (int)(ac_buffer); }
    {cgc_size_t i; i = (cgc_size_t)(ac_buffer); }
    {int tlv15; tlv15 = (int)(ac_buffer); }
    {void * tlv14; tlv14 = (void *)(ac_buffer); }
    {cgc_size_t tlv13; tlv13 = (cgc_size_t)(ac_buffer); }
    {int tlv16; tlv16 = (int)(ac_buffer); }
}
void fix_ingred_ac_3_0(){
fix_ingred_ac_3_0_5();
}
void fix_ingred_ac_3_1_0(){
    {cgc_size_t rx; rx = (cgc_size_t)(0); }
    {char * buf; buf = (char *)(0); }
    {cgc_size_t count; count = (cgc_size_t)(0); }
    {char word [ MAX_AC_LEN ]; word [ ( MAX_AC_LEN )-1 ] = (char)(0); }
    {char * newbuf; newbuf = (char *)(0); }
    {void * tlv11; tlv11 = (void *)(0); }
    {cgc_size_t tlv10; tlv10 = (cgc_size_t)(0); }
    {void * tlv8; tlv8 = (void *)(0); }
    {void * tlv7; tlv7 = (void *)(0); }
    {cgc_size_t tlv6; tlv6 = (cgc_size_t)(0); }
    {int tlv1; tlv1 = (int)(0); }
    {int tlv2; tlv2 = (int)(0); }
    {cgc_size_t i; i = (cgc_size_t)(0); }
    {int tlv15; tlv15 = (int)(0); }
    {void * tlv14; tlv14 = (void *)(0); }
    {cgc_size_t tlv13; tlv13 = (cgc_size_t)(0); }
    {int tlv16; tlv16 = (int)(0); }
}
void fix_ingred_ac_3_1(){
fix_ingred_ac_3_1_0();
}
void fix_ingred_ac_3_2_7(){
cgc_size_t count;
    bzero(&count,sizeof(cgc_size_t));
    {cgc_size_t rx; rx = (cgc_size_t)(count); }
    {char * buf; buf = (char *)(count); }
    {char word [ MAX_AC_LEN ]; word [ ( MAX_AC_LEN )-1 ] = (char)(count); }
    {char * newbuf; newbuf = (char *)(count); }
    {void * tlv11; tlv11 = (void *)(count); }
    {cgc_size_t tlv10; tlv10 = (cgc_size_t)(count); }
    {void * tlv8; tlv8 = (void *)(count); }
    {void * tlv7; tlv7 = (void *)(count); }
    {cgc_size_t tlv6; tlv6 = (cgc_size_t)(count); }
    {int tlv1; tlv1 = (int)(count); }
    {int tlv2; tlv2 = (int)(count); }
    {cgc_size_t i; i = (cgc_size_t)(count); }
    {int tlv15; tlv15 = (int)(count); }
    {void * tlv14; tlv14 = (void *)(count); }
    {cgc_size_t tlv13; tlv13 = (cgc_size_t)(count); }
    {int tlv16; tlv16 = (int)(count); }
}
void fix_ingred_ac_3_2_8(){
cgc_size_t count;
    bzero(&count,sizeof(cgc_size_t));
    {cgc_size_t rx; rx = (cgc_size_t)(MAX_AC_LEN); }
    {char * buf; buf = (char *)(MAX_AC_LEN); }
    {cgc_size_t count; count = (cgc_size_t)(MAX_AC_LEN); }
    {char word [ MAX_AC_LEN ]; word [ ( MAX_AC_LEN )-1 ] = (char)(MAX_AC_LEN); }
    {char * newbuf; newbuf = (char *)(MAX_AC_LEN); }
    {void * tlv11; tlv11 = (void *)(MAX_AC_LEN); }
    {cgc_size_t tlv10; tlv10 = (cgc_size_t)(MAX_AC_LEN); }
    {void * tlv8; tlv8 = (void *)(MAX_AC_LEN); }
    {void * tlv7; tlv7 = (void *)(MAX_AC_LEN); }
    {cgc_size_t tlv6; tlv6 = (cgc_size_t)(MAX_AC_LEN); }
    {int tlv1; tlv1 = (int)(MAX_AC_LEN); }
    {int tlv2; tlv2 = (int)(MAX_AC_LEN); }
    {cgc_size_t i; i = (cgc_size_t)(MAX_AC_LEN); }
    {int tlv15; tlv15 = (int)(MAX_AC_LEN); }
    {void * tlv14; tlv14 = (void *)(MAX_AC_LEN); }
    {cgc_size_t tlv13; tlv13 = (cgc_size_t)(MAX_AC_LEN); }
    {int tlv16; tlv16 = (int)(MAX_AC_LEN); }
}
void fix_ingred_ac_3_2(){
fix_ingred_ac_3_2_7();
fix_ingred_ac_3_2_8();
}
void fix_ingred_ac_3_3_0(){
int fd;
    bzero(&fd,sizeof(int));
char word [ MAX_AC_LEN ];
    bzero(&word,( MAX_AC_LEN *sizeof(char) ) );
cgc_size_t count;
    bzero(&count,sizeof(cgc_size_t));
    {cgc_size_t rx; rx = (cgc_size_t)(fd); }
    {char * buf; buf = (char *)(fd); }
    {cgc_size_t count; count = (cgc_size_t)(fd); }
    {char word [ MAX_AC_LEN ]; word [ ( MAX_AC_LEN )-1 ] = (char)(fd); }
    {char * newbuf; newbuf = (char *)(fd); }
    {void * tlv11; tlv11 = (void *)(fd); }
    {cgc_size_t tlv10; tlv10 = (cgc_size_t)(fd); }
    {void * tlv8; tlv8 = (void *)(fd); }
    {void * tlv7; tlv7 = (void *)(fd); }
    {cgc_size_t tlv6; tlv6 = (cgc_size_t)(fd); }
    {int tlv1; tlv1 = (int)(fd); }
    {int tlv2; tlv2 = (int)(fd); }
    {cgc_size_t i; i = (cgc_size_t)(fd); }
    {int tlv15; tlv15 = (int)(fd); }
    {void * tlv14; tlv14 = (void *)(fd); }
    {cgc_size_t tlv13; tlv13 = (cgc_size_t)(fd); }
    {int tlv16; tlv16 = (int)(fd); }
}
void fix_ingred_ac_3_3_1(){
int fd;
    bzero(&fd,sizeof(int));
char word [ MAX_AC_LEN ];
    bzero(&word,( MAX_AC_LEN *sizeof(char) ) );
cgc_size_t count;
    bzero(&count,sizeof(cgc_size_t));
    {if (word){    count = 0;
         cgc_size_t rx; rx = (cgc_size_t)(& word [ count ]); }}
    {if (word){    count = 0;
         char * buf; buf = (char *)(& word [ count ]); }}
    {if (word){    count = 0;
         char word [ MAX_AC_LEN ]; word [ ( MAX_AC_LEN )-1 ] = (char)(& word [ count ]); }}
    {if (word){    count = 0;
         char * newbuf; newbuf = (char *)(& word [ count ]); }}
    {if (word){    count = 0;
         void * tlv11; tlv11 = (void *)(& word [ count ]); }}
    {if (word){    count = 0;
         cgc_size_t tlv10; tlv10 = (cgc_size_t)(& word [ count ]); }}
    {if (word){    count = 0;
         void * tlv8; tlv8 = (void *)(& word [ count ]); }}
    {if (word){    count = 0;
         void * tlv7; tlv7 = (void *)(& word [ count ]); }}
    {if (word){    count = 0;
         cgc_size_t tlv6; tlv6 = (cgc_size_t)(& word [ count ]); }}
    {if (word){    count = 0;
         int tlv1; tlv1 = (int)(& word [ count ]); }}
    {if (word){    count = 0;
         int tlv2; tlv2 = (int)(& word [ count ]); }}
    {if (word){    count = 0;
         cgc_size_t i; i = (cgc_size_t)(& word [ count ]); }}
    {if (word){    count = 0;
         int tlv15; tlv15 = (int)(& word [ count ]); }}
    {if (word){    count = 0;
         void * tlv14; tlv14 = (void *)(& word [ count ]); }}
    {if (word){    count = 0;
         cgc_size_t tlv13; tlv13 = (cgc_size_t)(& word [ count ]); }}
    {if (word){    count = 0;
         int tlv16; tlv16 = (int)(& word [ count ]); }}
}
void fix_ingred_ac_3_3_2(){
int fd;
    bzero(&fd,sizeof(int));
char word [ MAX_AC_LEN ];
    bzero(&word,( MAX_AC_LEN *sizeof(char) ) );
cgc_size_t count;
    bzero(&count,sizeof(cgc_size_t));
    {cgc_size_t rx; rx = (cgc_size_t)(1); }
    {char * buf; buf = (char *)(1); }
    {cgc_size_t count; count = (cgc_size_t)(1); }
    {char word [ MAX_AC_LEN ]; word [ ( MAX_AC_LEN )-1 ] = (char)(1); }
    {char * newbuf; newbuf = (char *)(1); }
    {void * tlv11; tlv11 = (void *)(1); }
    {cgc_size_t tlv10; tlv10 = (cgc_size_t)(1); }
    {void * tlv8; tlv8 = (void *)(1); }
    {void * tlv7; tlv7 = (void *)(1); }
    {cgc_size_t tlv6; tlv6 = (cgc_size_t)(1); }
    {int tlv1; tlv1 = (int)(1); }
    {int tlv2; tlv2 = (int)(1); }
    {cgc_size_t i; i = (cgc_size_t)(1); }
    {int tlv15; tlv15 = (int)(1); }
    {void * tlv14; tlv14 = (void *)(1); }
    {cgc_size_t tlv13; tlv13 = (cgc_size_t)(1); }
    {int tlv16; tlv16 = (int)(1); }
}
void fix_ingred_ac_3_3(){
fix_ingred_ac_3_3_0();
fix_ingred_ac_3_3_1();
fix_ingred_ac_3_3_2();
}
void fix_ingred_ac_3_4_9(){
int tlv1;
    bzero(&tlv1,sizeof(int));
cgc_size_t rx;
    bzero(&rx,sizeof(cgc_size_t));
    {cgc_size_t rx; rx = (cgc_size_t)(tlv1); }
    {char * buf; buf = (char *)(tlv1); }
    {cgc_size_t count; count = (cgc_size_t)(tlv1); }
    {void * tlv11; tlv11 = (void *)(tlv1); }
    {cgc_size_t tlv10; tlv10 = (cgc_size_t)(tlv1); }
    {void * tlv8; tlv8 = (void *)(tlv1); }
    {void * tlv7; tlv7 = (void *)(tlv1); }
    {cgc_size_t tlv6; tlv6 = (cgc_size_t)(tlv1); }
    {int tlv2; tlv2 = (int)(tlv1); }
    {int tlv15; tlv15 = (int)(tlv1); }
    {cgc_size_t tlv13; tlv13 = (cgc_size_t)(tlv1); }
    {int tlv16; tlv16 = (int)(tlv1); }
}
void fix_ingred_ac_3_4_10(){
int tlv1;
    bzero(&tlv1,sizeof(int));
cgc_size_t rx;
    bzero(&rx,sizeof(cgc_size_t));
    {cgc_size_t rx; rx = (cgc_size_t)(0); }
    {char * buf; buf = (char *)(0); }
    {cgc_size_t count; count = (cgc_size_t)(0); }
    {void * tlv11; tlv11 = (void *)(0); }
    {cgc_size_t tlv10; tlv10 = (cgc_size_t)(0); }
    {void * tlv8; tlv8 = (void *)(0); }
    {void * tlv7; tlv7 = (void *)(0); }
    {cgc_size_t tlv6; tlv6 = (cgc_size_t)(0); }
    {int tlv2; tlv2 = (int)(0); }
    {int tlv15; tlv15 = (int)(0); }
    {cgc_size_t tlv13; tlv13 = (cgc_size_t)(0); }
    {int tlv16; tlv16 = (int)(0); }
}
void fix_ingred_ac_3_4_11(){
int tlv1;
    bzero(&tlv1,sizeof(int));
cgc_size_t rx;
    bzero(&rx,sizeof(cgc_size_t));
    {char * buf; buf = (char *)(rx); }
    {cgc_size_t count; count = (cgc_size_t)(rx); }
    {char word [ MAX_AC_LEN ]; word [ ( MAX_AC_LEN )-1 ] = (char)(rx); }
    {char * newbuf; newbuf = (char *)(rx); }
    {void * tlv11; tlv11 = (void *)(rx); }
    {cgc_size_t tlv10; tlv10 = (cgc_size_t)(rx); }
    {void * tlv8; tlv8 = (void *)(rx); }
    {void * tlv7; tlv7 = (void *)(rx); }
    {cgc_size_t tlv6; tlv6 = (cgc_size_t)(rx); }
    {int tlv1; tlv1 = (int)(rx); }
    {int tlv2; tlv2 = (int)(rx); }
    {cgc_size_t i; i = (cgc_size_t)(rx); }
    {int tlv15; tlv15 = (int)(rx); }
    {void * tlv14; tlv14 = (void *)(rx); }
    {cgc_size_t tlv13; tlv13 = (cgc_size_t)(rx); }
    {int tlv16; tlv16 = (int)(rx); }
}
void fix_ingred_ac_3_4(){
fix_ingred_ac_3_4_9();
fix_ingred_ac_3_4_10();
fix_ingred_ac_3_4_11();
}
void fix_ingred_ac_3_5_0(){
char word [ MAX_AC_LEN ];
    bzero(&word,( MAX_AC_LEN *sizeof(char) ) );
cgc_size_t count;
    bzero(&count,sizeof(cgc_size_t));
    {if (word){    count = 0;
         cgc_size_t rx; rx = (cgc_size_t)(word [ count ]); }}
    {if (word){    count = 0;
         char * buf; buf = (char *)(word [ count ]); }}
    {if (word){    count = 0;
         char word [ MAX_AC_LEN ]; word [ ( MAX_AC_LEN )-1 ] = (char)(word [ count ]); }}
    {if (word){    count = 0;
         char * newbuf; newbuf = (char *)(word [ count ]); }}
    {if (word){    count = 0;
         void * tlv11; tlv11 = (void *)(word [ count ]); }}
    {if (word){    count = 0;
         cgc_size_t tlv10; tlv10 = (cgc_size_t)(word [ count ]); }}
    {if (word){    count = 0;
         void * tlv8; tlv8 = (void *)(word [ count ]); }}
    {if (word){    count = 0;
         void * tlv7; tlv7 = (void *)(word [ count ]); }}
    {if (word){    count = 0;
         cgc_size_t tlv6; tlv6 = (cgc_size_t)(word [ count ]); }}
    {if (word){    count = 0;
         int tlv1; tlv1 = (int)(word [ count ]); }}
    {if (word){    count = 0;
         int tlv2; tlv2 = (int)(word [ count ]); }}
    {if (word){    count = 0;
         cgc_size_t i; i = (cgc_size_t)(word [ count ]); }}
    {if (word){    count = 0;
         int tlv15; tlv15 = (int)(word [ count ]); }}
    {if (word){    count = 0;
         void * tlv14; tlv14 = (void *)(word [ count ]); }}
    {if (word){    count = 0;
         cgc_size_t tlv13; tlv13 = (cgc_size_t)(word [ count ]); }}
    {if (word){    count = 0;
         int tlv16; tlv16 = (int)(word [ count ]); }}
}
void fix_ingred_ac_3_5(){
fix_ingred_ac_3_5_0();
}
void fix_ingred_ac_3_6_9(){
char word [ MAX_AC_LEN ];
    bzero(&word,( MAX_AC_LEN *sizeof(char) ) );
cgc_size_t count;
    bzero(&count,sizeof(cgc_size_t));
char term;
    bzero(&term,sizeof(char));
    {if (word){    count = 0;
         cgc_size_t rx; rx = (cgc_size_t)(word [ count ]); }}
    {if (word){    count = 0;
         char * buf; buf = (char *)(word [ count ]); }}
    {if (word){    count = 0;
         char word [ MAX_AC_LEN ]; word [ ( MAX_AC_LEN )-1 ] = (char)(word [ count ]); }}
    {if (word){    count = 0;
         char * newbuf; newbuf = (char *)(word [ count ]); }}
    {if (word){    count = 0;
         void * tlv11; tlv11 = (void *)(word [ count ]); }}
    {if (word){    count = 0;
         cgc_size_t tlv10; tlv10 = (cgc_size_t)(word [ count ]); }}
    {if (word){    count = 0;
         void * tlv8; tlv8 = (void *)(word [ count ]); }}
    {if (word){    count = 0;
         void * tlv7; tlv7 = (void *)(word [ count ]); }}
    {if (word){    count = 0;
         cgc_size_t tlv6; tlv6 = (cgc_size_t)(word [ count ]); }}
    {if (word){    count = 0;
         int tlv1; tlv1 = (int)(word [ count ]); }}
    {if (word){    count = 0;
         int tlv2; tlv2 = (int)(word [ count ]); }}
    {if (word){    count = 0;
         cgc_size_t i; i = (cgc_size_t)(word [ count ]); }}
    {if (word){    count = 0;
         int tlv15; tlv15 = (int)(word [ count ]); }}
    {if (word){    count = 0;
         void * tlv14; tlv14 = (void *)(word [ count ]); }}
    {if (word){    count = 0;
         cgc_size_t tlv13; tlv13 = (cgc_size_t)(word [ count ]); }}
    {if (word){    count = 0;
         int tlv16; tlv16 = (int)(word [ count ]); }}
}
void fix_ingred_ac_3_6_10(){
char word [ MAX_AC_LEN ];
    bzero(&word,( MAX_AC_LEN *sizeof(char) ) );
cgc_size_t count;
    bzero(&count,sizeof(cgc_size_t));
char term;
    bzero(&term,sizeof(char));
    {cgc_size_t rx; rx = (cgc_size_t)(term); }
    {char * buf; buf = (char *)(term); }
    {cgc_size_t count; count = (cgc_size_t)(term); }
    {char word [ MAX_AC_LEN ]; word [ ( MAX_AC_LEN )-1 ] = (char)(term); }
    {char * newbuf; newbuf = (char *)(term); }
    {void * tlv11; tlv11 = (void *)(term); }
    {cgc_size_t tlv10; tlv10 = (cgc_size_t)(term); }
    {void * tlv8; tlv8 = (void *)(term); }
    {void * tlv7; tlv7 = (void *)(term); }
    {cgc_size_t tlv6; tlv6 = (cgc_size_t)(term); }
    {int tlv1; tlv1 = (int)(term); }
    {int tlv2; tlv2 = (int)(term); }
    {cgc_size_t i; i = (cgc_size_t)(term); }
    {int tlv15; tlv15 = (int)(term); }
    {void * tlv14; tlv14 = (void *)(term); }
    {cgc_size_t tlv13; tlv13 = (cgc_size_t)(term); }
    {int tlv16; tlv16 = (int)(term); }
}
void fix_ingred_ac_3_6(){
fix_ingred_ac_3_6_9();
fix_ingred_ac_3_6_10();
}
void fix_ingred_ac_3_7_0(){
cgc_size_t count;
    bzero(&count,sizeof(cgc_size_t));
    {cgc_size_t rx; rx = (cgc_size_t)(ac_buffer); }
    {char * buf; buf = (char *)(ac_buffer); }
    {cgc_size_t count; count = (cgc_size_t)(ac_buffer); }
    {void * tlv11; tlv11 = (void *)(ac_buffer); }
    {cgc_size_t tlv10; tlv10 = (cgc_size_t)(ac_buffer); }
    {void * tlv8; tlv8 = (void *)(ac_buffer); }
    {void * tlv7; tlv7 = (void *)(ac_buffer); }
    {cgc_size_t tlv6; tlv6 = (cgc_size_t)(ac_buffer); }
    {int tlv2; tlv2 = (int)(ac_buffer); }
    {int tlv15; tlv15 = (int)(ac_buffer); }
    {cgc_size_t tlv13; tlv13 = (cgc_size_t)(ac_buffer); }
    {int tlv16; tlv16 = (int)(ac_buffer); }
}
void fix_ingred_ac_3_7_1(){
cgc_size_t count;
    bzero(&count,sizeof(cgc_size_t));
    {cgc_size_t rx; rx = (cgc_size_t)(ac_idx + count + 1); }
    {char * buf; buf = (char *)(ac_idx + count + 1); }
    {char word [ MAX_AC_LEN ]; word [ ( MAX_AC_LEN )-1 ] = (char)(ac_idx + count + 1); }
    {char * newbuf; newbuf = (char *)(ac_idx + count + 1); }
    {void * tlv11; tlv11 = (void *)(ac_idx + count + 1); }
    {cgc_size_t tlv10; tlv10 = (cgc_size_t)(ac_idx + count + 1); }
    {void * tlv8; tlv8 = (void *)(ac_idx + count + 1); }
    {void * tlv7; tlv7 = (void *)(ac_idx + count + 1); }
    {cgc_size_t tlv6; tlv6 = (cgc_size_t)(ac_idx + count + 1); }
    {int tlv1; tlv1 = (int)(ac_idx + count + 1); }
    {int tlv2; tlv2 = (int)(ac_idx + count + 1); }
    {cgc_size_t i; i = (cgc_size_t)(ac_idx + count + 1); }
    {int tlv15; tlv15 = (int)(ac_idx + count + 1); }
    {void * tlv14; tlv14 = (void *)(ac_idx + count + 1); }
    {cgc_size_t tlv13; tlv13 = (cgc_size_t)(ac_idx + count + 1); }
    {int tlv16; tlv16 = (int)(ac_idx + count + 1); }
}
void fix_ingred_ac_3_7(){
fix_ingred_ac_3_7_0();
fix_ingred_ac_3_7_1();
}
void fix_ingred_ac_3_8_6(){
char newbuf_ref;
    bzero(&newbuf_ref,1*sizeof(char));
char * newbuf = &newbuf_ref;
    {cgc_size_t rx; rx = (cgc_size_t)(newbuf); }
    {char * buf; buf = (char *)(newbuf); }
    {cgc_size_t count; count = (cgc_size_t)(newbuf); }
    {void * tlv11; tlv11 = (void *)(newbuf); }
    {cgc_size_t tlv10; tlv10 = (cgc_size_t)(newbuf); }
    {void * tlv8; tlv8 = (void *)(newbuf); }
    {void * tlv7; tlv7 = (void *)(newbuf); }
    {cgc_size_t tlv6; tlv6 = (cgc_size_t)(newbuf); }
    {int tlv2; tlv2 = (int)(newbuf); }
    {int tlv15; tlv15 = (int)(newbuf); }
    {cgc_size_t tlv13; tlv13 = (cgc_size_t)(newbuf); }
    {int tlv16; tlv16 = (int)(newbuf); }
}
void fix_ingred_ac_3_8_7(){
char newbuf_ref;
    bzero(&newbuf_ref,1*sizeof(char));
char * newbuf = &newbuf_ref;
    {cgc_size_t rx; rx = (cgc_size_t)(NULL); }
    {char * buf; buf = (char *)(NULL); }
    {cgc_size_t count; count = (cgc_size_t)(NULL); }
    {void * tlv11; tlv11 = (void *)(NULL); }
    {cgc_size_t tlv10; tlv10 = (cgc_size_t)(NULL); }
    {void * tlv8; tlv8 = (void *)(NULL); }
    {void * tlv7; tlv7 = (void *)(NULL); }
    {cgc_size_t tlv6; tlv6 = (cgc_size_t)(NULL); }
    {int tlv2; tlv2 = (int)(NULL); }
    {int tlv15; tlv15 = (int)(NULL); }
    {cgc_size_t tlv13; tlv13 = (cgc_size_t)(NULL); }
    {int tlv16; tlv16 = (int)(NULL); }
}
void fix_ingred_ac_3_8(){
fix_ingred_ac_3_8_6();
fix_ingred_ac_3_8_7();
}
void fix_ingred_ac_3_10_0(){
char word [ MAX_AC_LEN ];
    bzero(&word,( MAX_AC_LEN *sizeof(char) ) );
    {if (ac_buffer){cgc_size_t rx; rx = (cgc_size_t)(& ac_buffer [ ac_idx ]); }}
    {if (ac_buffer){char * buf; buf = (char *)(& ac_buffer [ ac_idx ]); }}
    {if (ac_buffer){cgc_size_t count; count = (cgc_size_t)(& ac_buffer [ ac_idx ]); }}
    {if (ac_buffer){char word [ MAX_AC_LEN ]; word [ ( MAX_AC_LEN )-1 ] = (char)(& ac_buffer [ ac_idx ]); }}
    {if (ac_buffer){char * newbuf; newbuf = (char *)(& ac_buffer [ ac_idx ]); }}
    {if (ac_buffer){void * tlv11; tlv11 = (void *)(& ac_buffer [ ac_idx ]); }}
    {if (ac_buffer){cgc_size_t tlv10; tlv10 = (cgc_size_t)(& ac_buffer [ ac_idx ]); }}
    {if (ac_buffer){void * tlv8; tlv8 = (void *)(& ac_buffer [ ac_idx ]); }}
    {if (ac_buffer){void * tlv7; tlv7 = (void *)(& ac_buffer [ ac_idx ]); }}
    {if (ac_buffer){cgc_size_t tlv6; tlv6 = (cgc_size_t)(& ac_buffer [ ac_idx ]); }}
    {if (ac_buffer){int tlv1; tlv1 = (int)(& ac_buffer [ ac_idx ]); }}
    {if (ac_buffer){int tlv2; tlv2 = (int)(& ac_buffer [ ac_idx ]); }}
    {if (ac_buffer){cgc_size_t i; i = (cgc_size_t)(& ac_buffer [ ac_idx ]); }}
    {if (ac_buffer){int tlv15; tlv15 = (int)(& ac_buffer [ ac_idx ]); }}
    {if (ac_buffer){void * tlv14; tlv14 = (void *)(& ac_buffer [ ac_idx ]); }}
    {if (ac_buffer){cgc_size_t tlv13; tlv13 = (cgc_size_t)(& ac_buffer [ ac_idx ]); }}
    {if (ac_buffer){int tlv16; tlv16 = (int)(& ac_buffer [ ac_idx ]); }}
}
void fix_ingred_ac_3_10_1(){
char word [ MAX_AC_LEN ];
    bzero(&word,( MAX_AC_LEN *sizeof(char) ) );
    {cgc_size_t rx; rx = (cgc_size_t)(word); }
    {char * buf; buf = (char *)(word); }
    {cgc_size_t count; count = (cgc_size_t)(word); }
    {void * tlv11; tlv11 = (void *)(word); }
    {cgc_size_t tlv10; tlv10 = (cgc_size_t)(word); }
    {void * tlv8; tlv8 = (void *)(word); }
    {void * tlv7; tlv7 = (void *)(word); }
    {cgc_size_t tlv6; tlv6 = (cgc_size_t)(word); }
    {int tlv2; tlv2 = (int)(word); }
    {int tlv15; tlv15 = (int)(word); }
    {cgc_size_t tlv13; tlv13 = (cgc_size_t)(word); }
    {int tlv16; tlv16 = (int)(word); }
}
void fix_ingred_ac_3_10(){
fix_ingred_ac_3_10_0();
fix_ingred_ac_3_10_1();
}
void fix_ingred_ac_3_12_0(){
    {cgc_size_t rx; rx = (cgc_size_t)(ac_queue_tail); }
    {char * buf; buf = (char *)(ac_queue_tail); }
    {cgc_size_t count; count = (cgc_size_t)(ac_queue_tail); }
    {char word [ MAX_AC_LEN ]; word [ ( MAX_AC_LEN )-1 ] = (char)(ac_queue_tail); }
    {char * newbuf; newbuf = (char *)(ac_queue_tail); }
    {void * tlv11; tlv11 = (void *)(ac_queue_tail); }
    {cgc_size_t tlv10; tlv10 = (cgc_size_t)(ac_queue_tail); }
    {void * tlv8; tlv8 = (void *)(ac_queue_tail); }
    {void * tlv7; tlv7 = (void *)(ac_queue_tail); }
    {cgc_size_t tlv6; tlv6 = (cgc_size_t)(ac_queue_tail); }
    {int tlv1; tlv1 = (int)(ac_queue_tail); }
    {int tlv2; tlv2 = (int)(ac_queue_tail); }
    {cgc_size_t i; i = (cgc_size_t)(ac_queue_tail); }
    {int tlv15; tlv15 = (int)(ac_queue_tail); }
    {void * tlv14; tlv14 = (void *)(ac_queue_tail); }
    {cgc_size_t tlv13; tlv13 = (cgc_size_t)(ac_queue_tail); }
    {int tlv16; tlv16 = (int)(ac_queue_tail); }
}
void fix_ingred_ac_3_12(){
fix_ingred_ac_3_12_0();
}
void fix_ingred_ac_3_14_10(){
char term;
    bzero(&term,sizeof(char));
    {cgc_size_t rx; rx = (cgc_size_t)(term); }
    {char * buf; buf = (char *)(term); }
    {cgc_size_t count; count = (cgc_size_t)(term); }
    {char word [ MAX_AC_LEN ]; word [ ( MAX_AC_LEN )-1 ] = (char)(term); }
    {char * newbuf; newbuf = (char *)(term); }
    {void * tlv11; tlv11 = (void *)(term); }
    {cgc_size_t tlv10; tlv10 = (cgc_size_t)(term); }
    {void * tlv8; tlv8 = (void *)(term); }
    {void * tlv7; tlv7 = (void *)(term); }
    {cgc_size_t tlv6; tlv6 = (cgc_size_t)(term); }
    {int tlv1; tlv1 = (int)(term); }
    {int tlv2; tlv2 = (int)(term); }
    {cgc_size_t i; i = (cgc_size_t)(term); }
    {int tlv15; tlv15 = (int)(term); }
    {void * tlv14; tlv14 = (void *)(term); }
    {cgc_size_t tlv13; tlv13 = (cgc_size_t)(term); }
    {int tlv16; tlv16 = (int)(term); }
}
void fix_ingred_ac_3_14(){
fix_ingred_ac_3_14_10();
}
void fix_ingred_ac_3(){
fix_ingred_ac_3_0();
fix_ingred_ac_3_1();
fix_ingred_ac_3_2();
fix_ingred_ac_3_3();
fix_ingred_ac_3_4();
fix_ingred_ac_3_5();
fix_ingred_ac_3_6();
fix_ingred_ac_3_7();
fix_ingred_ac_3_8();
fix_ingred_ac_3_10();
fix_ingred_ac_3_12();
fix_ingred_ac_3_14();
}
