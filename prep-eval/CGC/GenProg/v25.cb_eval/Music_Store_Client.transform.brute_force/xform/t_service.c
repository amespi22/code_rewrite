

#include "libcgc.h"
#include "cgc_libc.h"
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

void fix_ingred_service_0_0_0();
void fix_ingred_service_0_0_1();
void fix_ingred_service_0_0_3();
void fix_ingred_service_0_0_4();
void fix_ingred_service_0_0();
void fix_ingred_service_0_1_5();
void fix_ingred_service_0_1_6();
void fix_ingred_service_0_1_7();
void fix_ingred_service_0_1_8();
void fix_ingred_service_0_1();
void fix_ingred_service_0_2_0();
void fix_ingred_service_0_2_1();
void fix_ingred_service_0_2_2();
void fix_ingred_service_0_2();
void fix_ingred_service_0();
char *cgc_setValue(char *buffer, char *value)
{
if (fix_ingred_enable){ fix_ingred_service_0(); };
    char* ptr;
     ptr = NULL;
    int count;
    count = 0;
    int i;
    i = 0;
    char* delim;
     delim = PARAM_DELIM;
    ptr = buffer;
    while (*ptr && (*ptr != *delim) && count < RESULT_VALUE_SIZE)
    {
	ptr++, count++;
    }
    {
        void* tlv3;
        tlv3 = value;
        void* tlv2;
        tlv2 = buffer;
        cgc_size_t tlv1;
        tlv1 = count;
        cgc_memcpy(tlv3,tlv2,tlv1);
    }
    return ++ptr;
}

void fix_ingred_service_1_0_0();
void fix_ingred_service_1_0_2();
void fix_ingred_service_1_0_4();
void fix_ingred_service_1_0_7();
void fix_ingred_service_1_0_8();
void fix_ingred_service_1_0();
void fix_ingred_service_1_1_10();
void fix_ingred_service_1_1_11();
void fix_ingred_service_1_1_12();
void fix_ingred_service_1_1_13();
void fix_ingred_service_1_1();
void fix_ingred_service_1_2_0();
void fix_ingred_service_1_2_1();
void fix_ingred_service_1_2_2();
void fix_ingred_service_1_2();
void fix_ingred_service_1_4_10();
void fix_ingred_service_1_4();
void fix_ingred_service_1_5_0();
void fix_ingred_service_1_5_1();
void fix_ingred_service_1_5();
void fix_ingred_service_1();
int cgc_parseResultSize(char *buffer)
{
if (fix_ingred_enable){ fix_ingred_service_1(); };
    char* start;
     start = NULL;
    char* end;
     end = NULL;
    char key[KEY_SIZE] = { 0 };
    char value[RESULT_VALUE_SIZE] = { 0 };
    int count;
    count = 0;
    int i;
    i = 0;
    char* delim;
     delim = KEYVAL_DELIM;
    int ret;
    ret = 0;
    int num_results;
    num_results = 0;
    start = buffer;
    end = start;
    count = 0;
    while (*end && (*end != *delim) && count < KEY_SIZE)
    {
	end++, count++;
    }
    {
        void* tlv4;
        tlv4 = key;
        void* tlv3;
        tlv3 = start;
        cgc_size_t tlv2;
        tlv2 = count;
        cgc_memcpy(tlv4,tlv3,tlv2);
    }
    int tlv1;
    {
        const char* tlv6 = key;
        const char* tlv5 = NUM_STR;
        tlv1 = cgc_strcmp(tlv6,tlv5);
    }
    if (tlv1 == 0) {
 {
     char* tlv8;
      tlv8 = ++ end;
     char* tlv7;
      tlv7 = value;
    	cgc_setValue(tlv8,tlv7);
 }
 {
     const char* tlv9 = value;
    	num_results = cgc_str2int(tlv9);
 }
	return num_results;
    }
    return 0;
}

void fix_ingred_service_2_0_0();
void fix_ingred_service_2_0_2();
void fix_ingred_service_2_0_4();
void fix_ingred_service_2_0_7();
void fix_ingred_service_2_0_8();
void fix_ingred_service_2_0();
void fix_ingred_service_2_1_10();
void fix_ingred_service_2_1_11();
void fix_ingred_service_2_1_12();
void fix_ingred_service_2_1_13();
void fix_ingred_service_2_1();
void fix_ingred_service_2_2_0();
void fix_ingred_service_2_2_1();
void fix_ingred_service_2_2_2();
void fix_ingred_service_2_2();
void fix_ingred_service_2_4_10();
void fix_ingred_service_2_4();
void fix_ingred_service_2_5_0();
void fix_ingred_service_2_5_1();
void fix_ingred_service_2_5();
void fix_ingred_service_2_7_12();
void fix_ingred_service_2_7_15();
void fix_ingred_service_2_7();
void fix_ingred_service_2();
int cgc_parseBalanceResult(char *buffer)
{
if (fix_ingred_enable){ fix_ingred_service_2(); };
    char* start;
     start = NULL;
    char* end;
     end = NULL;
    char key[KEY_SIZE] = { 0 };
    char value[RESULT_VALUE_SIZE] = { 0 };
    int count;
    count = 0;
    int i;
    i = 0;
    char* delim;
     delim = KEYVAL_DELIM;
    int ret;
    ret = 0;
    int balance;
    balance = 0;
    start = buffer;
    end = start;
    count = 0;
    while (*end && (*end != *delim) && count < KEY_SIZE)
    {
	end++, count++;
    }
    {
        void* tlv4;
        tlv4 = key;
        void* tlv3;
        tlv3 = start;
        cgc_size_t tlv2;
        tlv2 = count;
        cgc_memcpy(tlv4,tlv3,tlv2);
    }
    int tlv1;
    {
        const char* tlv6 = key;
        const char* tlv5 = BAL_STR;
        tlv1 = cgc_strcmp(tlv6,tlv5);
    }
    if (tlv1 == 0) {
 {
     char* tlv8;
      tlv8 = ++ end;
     char* tlv7;
      tlv7 = value;
    	cgc_setValue(tlv8,tlv7);
 }
 {
     const char* tlv9 = value;
    	balance = cgc_str2int(tlv9);
 }
	if (balance < 0 || balance > 255) {
	    return 0;
	}
	return balance;
    }
    return 0;
}

void fix_ingred_service_3_0_0();
void fix_ingred_service_3_0_2();
void fix_ingred_service_3_0_4();
void fix_ingred_service_3_0_6();
void fix_ingred_service_3_0();
void fix_ingred_service_3_1_0();
void fix_ingred_service_3_1_2();
void fix_ingred_service_3_1();
void fix_ingred_service_3_2_0();
void fix_ingred_service_3_2();
void fix_ingred_service_3_3_9();
void fix_ingred_service_3_3_10();
void fix_ingred_service_3_3_11();
void fix_ingred_service_3_3_12();
void fix_ingred_service_3_3();
void fix_ingred_service_3_4_0();
void fix_ingred_service_3_4_1();
void fix_ingred_service_3_4_2();
void fix_ingred_service_3_4();
void fix_ingred_service_3_6_9();
void fix_ingred_service_3_6();
void fix_ingred_service_3_7_0();
void fix_ingred_service_3_7_1();
void fix_ingred_service_3_7();
void fix_ingred_service_3_10_9();
void fix_ingred_service_3_10();
void fix_ingred_service_3_11_1();
void fix_ingred_service_3_11();
void fix_ingred_service_3_14_9();
void fix_ingred_service_3_14();
void fix_ingred_service_3_15_1();
void fix_ingred_service_3_15();
void fix_ingred_service_3_18_9();
void fix_ingred_service_3_18();
void fix_ingred_service_3_19_1();
void fix_ingred_service_3_19();
void fix_ingred_service_3_22_9();
void fix_ingred_service_3_22();
void fix_ingred_service_3_23_1();
void fix_ingred_service_3_23();
void fix_ingred_service_3_25_2();
void fix_ingred_service_3_25();
void fix_ingred_service_3();
int cgc_parseSearchResult(char *buffer, Song * song)
{
if (fix_ingred_enable){ fix_ingred_service_3(); };
    char* start;
     start = NULL;
    char* end;
     end = NULL;
    char key[KEY_SIZE] = { 0 };
    int count;
    count = 0;
    int i;
    i = 0;
    char* delim;
     delim = KEYVAL_DELIM;
    int ret;
    ret = 0;
    {
        void* tlv8;
        tlv8 = song;
        int tlv7;
        tlv7 = 0;
        cgc_size_t tlv6;
        tlv6 = SONG_SIZE;
        cgc_memset(tlv8,tlv7,tlv6);
    }
    start = buffer;
    while (1) {
	end = start;
	count = 0;
	while (*end && (*end != *delim) && count < KEY_SIZE)
 {
	    end++, count++;
 }

 {
     void* tlv11;
     tlv11 = key;
     void* tlv10;
     tlv10 = start;
     cgc_size_t tlv9;
     tlv9 = count;
    	cgc_memcpy(tlv11,tlv10,tlv9);
 }
 int tlv1;
 {
     const char* tlv16 = key;
     const char* tlv15 = SONG_ID_STR;
     tlv1 = cgc_strcmp(tlv16,tlv15);
 }
	if (tlv1 == 0) {
     {
         char* tlv18;
          tlv18 = ++ end;
         char* tlv17;
          tlv17 = song -> id;
    	    start = cgc_setValue(tlv18,tlv17);
     }
	} else {
     int tlv2;
     {
         const char* tlv20 = key;
         const char* tlv19 = PRICE_STR;
         tlv2 = cgc_strcmp(tlv20,tlv19);
     }
	    if (tlv2 == 0) {
  {
      char* tlv22;
       tlv22 = ++ end;
      char* tlv21;
       tlv21 = song -> price;
    		start = cgc_setValue(tlv22,tlv21);
  }
	    } else {
  int tlv3;
  {
      const char* tlv24 = key;
      const char* tlv23 = ARTIST_STR;
      tlv3 = cgc_strcmp(tlv24,tlv23);
  }
		if (tlv3 == 0) {
      {
          char* tlv26;
           tlv26 = ++ end;
          char* tlv25;
           tlv25 = song -> artist;
    		    start = cgc_setValue(tlv26,tlv25);
      }
		} else {
      int tlv4;
      {
          const char* tlv28 = key;
          const char* tlv27 = ALBUM_STR;
          tlv4 = cgc_strcmp(tlv28,tlv27);
      }
		    if (tlv4 == 0) {
   {
       char* tlv30;
        tlv30 = ++ end;
       char* tlv29;
        tlv29 = song -> album;
    			start = cgc_setValue(tlv30,tlv29);
   }
		    } else {
   int tlv5;
   {
       const char* tlv32 = key;
       const char* tlv31 = SONG_STR;
       tlv5 = cgc_strcmp(tlv32,tlv31);
   }
			if (tlv5 == 0) {
       {
           char* tlv34;
            tlv34 = ++ end;
           char* tlv33;
            tlv33 = song -> song;
    			    cgc_setValue(tlv34,tlv33);
       }
			    return 0;
			} else {
			    return 0;
			}
		    }
		}
	    }
	}
 {
     void* tlv14;
     tlv14 = key;
     int tlv13;
     tlv13 = 0;
     cgc_size_t tlv12;
     tlv12 = KEY_SIZE;
    	cgc_memset(tlv14,tlv13,tlv12);
 }
    }
    return 0;
}

void fix_ingred_service_4_0_0();
void fix_ingred_service_4_0();
void fix_ingred_service_4_1_0();
void fix_ingred_service_4_1_1();
void fix_ingred_service_4_1_2();
void fix_ingred_service_4_1();
void fix_ingred_service_4_2_2();
void fix_ingred_service_4_2();
void fix_ingred_service_4_3_0();
void fix_ingred_service_4_3();
void fix_ingred_service_4();
int cgc_receiveBalance(int socket)
{
if (fix_ingred_enable){ fix_ingred_service_4(); };
    char buf[1024] = { 0 };
    int bytes_read;
    bytes_read = 0;
    int balance;
    balance = 0;
    {
        int tlv3;
        tlv3 = socket;
        char* tlv2;
         tlv2 = buf;
        cgc_size_t tlv1;
        tlv1 = sizeof ( buf ) - 1;
        bytes_read = cgc_recvline(tlv3,tlv2,tlv1);
    }
    if (bytes_read < 0) {
 {
     unsigned int tlv5;
     tlv5 = 2;
    	cgc__terminate(tlv5);
 }
    }
    if (bytes_read == 0) {
	return 0;
    }
    {
        char* tlv4;
         tlv4 = buf;
        balance = cgc_parseBalanceResult(tlv4);
    }
    return balance;
}

void fix_ingred_service_5_1_0();
void fix_ingred_service_5_1_1();
void fix_ingred_service_5_1_2();
void fix_ingred_service_5_1();
void fix_ingred_service_5_2_2();
void fix_ingred_service_5_2();
void fix_ingred_service_5_3_0();
void fix_ingred_service_5_3();
void fix_ingred_service_5_6_2();
void fix_ingred_service_5_6();
void fix_ingred_service_5();
int cgc_receiveNumResults(int socket)
{
if (fix_ingred_enable){ fix_ingred_service_5(); };
    char buf[1024] = { 0 };
    int bytes_read;
    bytes_read = 0;
    int num_results;
    num_results = 0;
    {
        int tlv3;
        tlv3 = socket;
        char* tlv2;
         tlv2 = buf;
        cgc_size_t tlv1;
        tlv1 = sizeof ( buf ) - 1;
        bytes_read = cgc_recvline(tlv3,tlv2,tlv1);
    }
    if (bytes_read < 0) {
 {
     unsigned int tlv5;
     tlv5 = 2;
    	cgc__terminate(tlv5);
 }
    }
    if (bytes_read == 0) {
	return 0;
    }
    {
        char* tlv4;
         tlv4 = buf;
        num_results = cgc_parseResultSize(tlv4);
    }
    if (num_results > 0) {
	return num_results;
    }

    return 0;
}

void fix_ingred_service_6_0_0();
void fix_ingred_service_6_0();
void fix_ingred_service_6_1_0();
void fix_ingred_service_6_1();
void fix_ingred_service_6_3_1();
void fix_ingred_service_6_3_2();
void fix_ingred_service_6_3();
void fix_ingred_service_6_4_3();
void fix_ingred_service_6_4();
void fix_ingred_service_6_5_0();
void fix_ingred_service_6_5();
void fix_ingred_service_6_9_5();
void fix_ingred_service_6_9();
void fix_ingred_service_6_10_0();
void fix_ingred_service_6_10();
void fix_ingred_service_6();
int cgc_receiveSearchResults(int socket, SongList * songList, int limit)
{
if (fix_ingred_enable){ fix_ingred_service_6(); };
    char buf[1024] = { 0 };
    int ret;
    ret = 0;
    int bytes_read;
    bytes_read = 0;
    int num_results;
    num_results = 0;
    {
        int tlv1;
        tlv1 = socket;
        num_results = cgc_receiveNumResults(tlv1);
    }
    while (num_results) {
 {
     int tlv4;
     tlv4 = socket;
     char* tlv3;
      tlv3 = buf;
     cgc_size_t tlv2;
     tlv2 = sizeof ( buf ) - 1;
    	bytes_read = cgc_recvline(tlv4,tlv3,tlv2);
 }
	if (bytes_read < 0) {
     {
         unsigned int tlv5;
         tlv5 = 2;
    	    cgc__terminate(tlv5);
     }
	}
	if (bytes_read == 0) {
	    return 0;
	}
	if (songList->size < limit) {
     {
         char* tlv7;
          tlv7 = buf;
         Song* tlv6;
         tlv6 = & songList -> songs [ songList -> size ];
    	    ret = cgc_parseSearchResult(tlv7,tlv6);
     }
	    if (ret != 0) {
  {
      unsigned int tlv8;
      tlv8 = 10;
    		cgc__terminate(tlv8);
  }
	    }
	    songList->size++;
	}
	num_results--;
    }
    return 0;
}

void fix_ingred_service_7_0_0();
void fix_ingred_service_7_0_1();
void fix_ingred_service_7_0();
void fix_ingred_service_7_1_0();
void fix_ingred_service_7_1();
void fix_ingred_service_7_2_2();
void fix_ingred_service_7_2();
void fix_ingred_service_7_3_0();
void fix_ingred_service_7_3();
void fix_ingred_service_7_4_0();
void fix_ingred_service_7_4();
void fix_ingred_service_7_5_0();
void fix_ingred_service_7_5();
void fix_ingred_service_7();
char *cgc_createSearchString(Request request)
{
if (fix_ingred_enable){ fix_ingred_service_7(); };
    char* buffer;
     buffer = NULL;
    int ret;
    ret = 0;
    {
        cgc_size_t tlv30;
        tlv30 = sizeof ( request ) + cgc_MIN_REQ_LEN;
        int tlv29;
        tlv29 = 0;
        void** tlv28;
        tlv28 = ( void * * ) & buffer;
        ret = cgc_allocate(tlv30,tlv29,tlv28);
    }
    if (ret != 0) {
 {
     unsigned int tlv31;
     tlv31 = 3;
    	cgc__terminate(tlv31);
 }
    }
    {
        void* tlv3;
        tlv3 = buffer;
        int tlv2;
        tlv2 = 0;
        cgc_size_t tlv1;
        tlv1 = sizeof ( request ) + cgc_MIN_REQ_LEN;
        cgc_memset(tlv3,tlv2,tlv1);
    }
    {
        char* tlv5;
         tlv5 = buffer;
        const char* tlv4 = TERM_STR;
        cgc_strcat(tlv5,tlv4);
    }
    {
        char* tlv7;
         tlv7 = buffer;
        const char* tlv6 = KEYVAL_DELIM;
        cgc_strcat(tlv7,tlv6);
    }
    {
        char* tlv9;
         tlv9 = buffer;
        const char* tlv8 = request . term;
        cgc_strcat(tlv9,tlv8);
    }
    {
        char* tlv11;
         tlv11 = buffer;
        const char* tlv10 = PARAM_DELIM;
        cgc_strcat(tlv11,tlv10);
    }
    {
        char* tlv13;
         tlv13 = buffer;
        const char* tlv12 = ATTRIBUTE_STR;
        cgc_strcat(tlv13,tlv12);
    }
    {
        char* tlv15;
         tlv15 = buffer;
        const char* tlv14 = KEYVAL_DELIM;
        cgc_strcat(tlv15,tlv14);
    }
    {
        char* tlv17;
         tlv17 = buffer;
        const char* tlv16 = request . attribute;
        cgc_strcat(tlv17,tlv16);
    }
    {
        char* tlv19;
         tlv19 = buffer;
        const char* tlv18 = PARAM_DELIM;
        cgc_strcat(tlv19,tlv18);
    }
    {
        char* tlv21;
         tlv21 = buffer;
        const char* tlv20 = LIMIT_STR;
        cgc_strcat(tlv21,tlv20);
    }
    {
        char* tlv23;
         tlv23 = buffer;
        const char* tlv22 = KEYVAL_DELIM;
        cgc_strcat(tlv23,tlv22);
    }
    {
        char* tlv25;
         tlv25 = buffer;
        const char* tlv24 = request . limit;
        cgc_strcat(tlv25,tlv24);
    }
    {
        char* tlv27;
         tlv27 = buffer;
        const char* tlv26 = EOL_STR;
        cgc_strcat(tlv27,tlv26);
    }
    return buffer;
}

void fix_ingred_service_8_0_0();
void fix_ingred_service_8_0_1();
void fix_ingred_service_8_0_2();
void fix_ingred_service_8_0_3();
void fix_ingred_service_8_0_4();
void fix_ingred_service_8_0();
void fix_ingred_service_8_1_0();
void fix_ingred_service_8_1_1();
void fix_ingred_service_8_1();
void fix_ingred_service_8_2_3();
void fix_ingred_service_8_2();
void fix_ingred_service_8_3_0();
void fix_ingred_service_8_3();
void fix_ingred_service_8_4_4();
void fix_ingred_service_8_4_5();
void fix_ingred_service_8_4();
void fix_ingred_service_8_5_0();
void fix_ingred_service_8_5();
void fix_ingred_service_8();
unsigned int cgc_getRandomNumber(unsigned int max)
{
if (fix_ingred_enable){ fix_ingred_service_8(); };
    cgc_size_t bytes_written;
    bytes_written = 0;
    unsigned int index;
    index = 0;
    int ret;
    ret = 0;
    {
        void* tlv3;
        tlv3 = & index;
        cgc_size_t tlv2;
        tlv2 = sizeof ( index );
        cgc_size_t* tlv1;
        tlv1 = & bytes_written;
        ret = cgc_random(tlv3,tlv2,tlv1);
    }
    if (ret != 0) {
 {
     unsigned int tlv4;
     tlv4 = 1;
    	cgc__terminate(tlv4);
 }
    }
    unsigned long tlv_size_0;
    tlv_size_0 = sizeof ( index );
    if (bytes_written != tlv_size_0) {
 {
     unsigned int tlv5;
     tlv5 = 2;
    	cgc__terminate(tlv5);
 }
    }
    index = index % max;
    return index;
}

void fix_ingred_service_9_0_0();
void fix_ingred_service_9_0();
void fix_ingred_service_9_1_0();
void fix_ingred_service_9_1();
void fix_ingred_service_9_2_0();
void fix_ingred_service_9_2_1();
void fix_ingred_service_9_2();
void fix_ingred_service_9_3_0();
void fix_ingred_service_9_3();
void fix_ingred_service_9();
void cgc_getRandomAttribute(Request * request)
{
if (fix_ingred_enable){ fix_ingred_service_9(); };
    int index;
    index = 0;
    {
        unsigned int tlv4;
        tlv4 = ATTR_NUM;
        index = cgc_getRandomNumber(tlv4);
    }
    {
        void* tlv3;
        tlv3 = request -> attribute;
        void* tlv2;
        tlv2 = attributes [ index ];
        cgc_size_t tlv1;
        {
            const char* tlv5 = attributes [ index ];
            tlv1 = cgc_strlen(tlv5);
        }
        cgc_memcpy(tlv3,tlv2,tlv1);
    }
}

void fix_ingred_service_10_0_0();
void fix_ingred_service_10_0_2();
void fix_ingred_service_10_0();
void fix_ingred_service_10_1_3();
void fix_ingred_service_10_1();
void fix_ingred_service_10_2_0();
void fix_ingred_service_10_2();
void fix_ingred_service_10_3_0();
void fix_ingred_service_10_3();
void fix_ingred_service_10_4_5();
void fix_ingred_service_10_4_6();
void fix_ingred_service_10_4();
void fix_ingred_service_10_5_0();
void fix_ingred_service_10_5();
void fix_ingred_service_10();
void cgc_getRandomTerm(Request * request)
{
if (fix_ingred_enable){ fix_ingred_service_10(); };
    unsigned int size;
    size = 0;
    unsigned int charset_size;
    charset_size = 0;
    int index;
    index = 0;
    while (size == 0) {
 {
     unsigned int tlv2;
     tlv2 = RESULT_VALUE_SIZE;
    	size = cgc_getRandomNumber(tlv2);
 }
    }
    {
        const char* tlv1 = cgc_charset;
        charset_size = cgc_strlen(tlv1);
    }
    for (index = 0; index < size; index++) {
 int letter;
 {
     unsigned int tlv3;
     tlv3 = charset_size;
     letter = cgc_getRandomNumber(tlv3);
 }
	request->term[index] = cgc_charset[letter];
    }
    request->term[size] = '\0';
}

void fix_ingred_service_11_1_0();
void fix_ingred_service_11_1_1();
void fix_ingred_service_11_1_2();
void fix_ingred_service_11_1();
void fix_ingred_service_11_2_0();
void fix_ingred_service_11_2_1();
void fix_ingred_service_11_2_2();
void fix_ingred_service_11_2();
void fix_ingred_service_11();
void cgc_createRandomRequest(Request * request)
{
if (fix_ingred_enable){ fix_ingred_service_11(); };
    {
        void* tlv3;
        tlv3 = request;
        int tlv2;
        tlv2 = 0;
        cgc_size_t tlv1;
        tlv1 = REQUEST_SIZE;
        cgc_memset(tlv3,tlv2,tlv1);
    }
    cgc_getRandomTerm(request);
    cgc_getRandomAttribute(request);
    {
        void* tlv6;
        tlv6 = request -> limit;
        void* tlv5;
        tlv5 = RESULT_LIMIT_STR;
        cgc_size_t tlv4;
        tlv4 = sizeof ( RESULT_LIMIT_STR );
        cgc_memcpy(tlv6,tlv5,tlv4);
    }
}

void fix_ingred_service_12_0_0();
void fix_ingred_service_12_0_1();
void fix_ingred_service_12_0();
void fix_ingred_service_12_1_0();
void fix_ingred_service_12_1();
void fix_ingred_service_12_2_4();
void fix_ingred_service_12_2();
void fix_ingred_service_12_3_0();
void fix_ingred_service_12_3();
void fix_ingred_service_12_4_0();
void fix_ingred_service_12_4_2();
void fix_ingred_service_12_4();
void fix_ingred_service_12_5_0();
void fix_ingred_service_12_5();
void fix_ingred_service_12_6_6();
void fix_ingred_service_12_6_7();
void fix_ingred_service_12_6();
void fix_ingred_service_12_7_0();
void fix_ingred_service_12_7();
void fix_ingred_service_12();
cgc_size_t cgc_getRandomGiftCard(char **gift_card)
{
if (fix_ingred_enable){ fix_ingred_service_12(); };
    unsigned int charset_size;
    charset_size = 0;
    int index;
    index = 0;
    int section;
    section = 0;
    int ret;
    ret = 0;
    {
        cgc_size_t tlv6;
        tlv6 = GIFT_CARD_LEN + 1;
        int tlv5;
        tlv5 = 0;
        void** tlv4;
        tlv4 = ( void * * ) gift_card;
        ret = cgc_allocate(tlv6,tlv5,tlv4);
    }
    if (ret != 0) {
 {
     unsigned int tlv8;
     tlv8 = 3;
    	cgc__terminate(tlv8);
 }
    }
    {
        void* tlv3;
        tlv3 = * gift_card;
        int tlv2;
        tlv2 = 0;
        cgc_size_t tlv1;
        tlv1 = GIFT_CARD_LEN;
        cgc_memset(tlv3,tlv2,tlv1);
    }
    {
        const char* tlv7 = cgc_charset;
        charset_size = cgc_strlen(tlv7);
    }
    for (index = 0; index < GIFT_CARD_LEN; index++) {
 int letter;
 {
     unsigned int tlv9;
     tlv9 = charset_size;
     letter = cgc_getRandomNumber(tlv9);
 }
	(*gift_card)[index] = cgc_charset[letter];
    }
    (*gift_card)[GIFT_CARD_LEN] = '\0';
    return GIFT_CARD_LEN + 1;
}

void fix_ingred_service_13_0_0();
void fix_ingred_service_13_0_1();
void fix_ingred_service_13_0();
void fix_ingred_service_13_3_1();
void fix_ingred_service_13_3_2();
void fix_ingred_service_13_3();
void fix_ingred_service_13_4_0();
void fix_ingred_service_13_4();
void fix_ingred_service_13_5_0();
void fix_ingred_service_13_5();
void fix_ingred_service_13_6_5();
void fix_ingred_service_13_6();
void fix_ingred_service_13_7_0();
void fix_ingred_service_13_7();
void fix_ingred_service_13_9_0();
void fix_ingred_service_13_9();
void fix_ingred_service_13();
int cgc_purchaseSong(int socket, Song * selectedSong, SongList * mySongList)
{
if (fix_ingred_enable){ fix_ingred_service_13(); };
    int ret;
    ret = 0;
    char price;
    price = 0;
    {
        const char* tlv1 = selectedSong -> price;
        price = cgc_str2int(tlv1);
    }
    if (mySongList->balance >= price) {
	mySongList->balance -= price;
	mySongList->size++;
 {
     void* tlv4;
     tlv4 = & mySongList -> songs [ mySongList -> size - 1 ];
     void* tlv3;
     tlv3 = selectedSong;
     cgc_size_t tlv2;
     tlv2 = RESULT_VALUE_SIZE * 3;
    	cgc_memcpy(tlv4,tlv3,tlv2);
 }
 {
     int tlv7;
     tlv7 = socket;
     const char* tlv6 = mySongList -> songs [ mySongList -> size - 1 ] . id;
     cgc_size_t tlv5;
     {
         const char* tlv13 = mySongList -> songs [ mySongList -> size - 1 ] . id;
         tlv5 = cgc_strlen(tlv13);
     }
    	ret = cgc_transmit_all(tlv7,tlv6,tlv5);
 }
	if (ret != 0) {
     {
         unsigned int tlv11;
         tlv11 = 10;
    	    cgc__terminate(tlv11);
     }
	}
 {
     int tlv10;
     tlv10 = socket;
     const char tlv9 [ ] = "\n";
     cgc_size_t tlv8;
     {
         const char tlv14 [ ] = "\n";
         tlv8 = cgc_strlen(tlv14);
     }
    	ret = cgc_transmit_all(tlv10,tlv9,tlv8);
 }
	if (ret != 0) {
     {
         unsigned int tlv12;
         tlv12 = 10;
    	    cgc__terminate(tlv12);
     }
	}
	return SUCCESS;
    }
    return LOW_BALANCE;
}

void fix_ingred_service_14_0_0();
void fix_ingred_service_14_0_1();
void fix_ingred_service_14_0();
void fix_ingred_service_14_2_0();
void fix_ingred_service_14_2();
void fix_ingred_service_14_3_0();
void fix_ingred_service_14_3();
void fix_ingred_service_14_4_2();
void fix_ingred_service_14_4();
void fix_ingred_service_14_5_0();
void fix_ingred_service_14_5();
void fix_ingred_service_14();
int cgc_sendSearchString(int socket, Request request)
{
if (fix_ingred_enable){ fix_ingred_service_14(); };
    int ret;
    ret = 0;
    char* search_string;
     search_string = NULL;
    {
        Request tlv1;
        tlv1 = request;
        search_string = cgc_createSearchString(tlv1);
    }
    {
        int tlv4;
        tlv4 = socket;
        const char* tlv3 = search_string;
        cgc_size_t tlv2;
        {
            const char* tlv6 = search_string;
            tlv2 = cgc_strlen(tlv6);
        }
        ret = cgc_transmit_all(tlv4,tlv3,tlv2);
    }
    if (ret != 0) {
 {
     unsigned int tlv5;
     tlv5 = 4;
    	cgc__terminate(tlv5);
 }
    }
    return 0;
}

void fix_ingred_service_15_0_0();
void fix_ingred_service_15_0_1();
void fix_ingred_service_15_0_3();
void fix_ingred_service_15_0();
void fix_ingred_service_15_2_0();
void fix_ingred_service_15_2();
void fix_ingred_service_15_3_4();
void fix_ingred_service_15_3();
void fix_ingred_service_15_4_0();
void fix_ingred_service_15_4();
void fix_ingred_service_15_5_0();
void fix_ingred_service_15_5();
void fix_ingred_service_15_6_0();
void fix_ingred_service_15_6();
void fix_ingred_service_15_9_0();
void fix_ingred_service_15_9_1();
void fix_ingred_service_15_9();
void fix_ingred_service_15_12_0();
void fix_ingred_service_15_12();
void fix_ingred_service_15_13_0();
void fix_ingred_service_15_13();
void fix_ingred_service_15_15_0();
void fix_ingred_service_15_15();
void fix_ingred_service_15_19_0();
void fix_ingred_service_15_19();
void fix_ingred_service_15_20_0();
void fix_ingred_service_15_20();
void fix_ingred_service_15();
int cgc_getBalance(SongList * mySongList)
{
if (fix_ingred_enable){ fix_ingred_service_15(); };
    cgc_size_t size;
    size = 0;
    char* gift_card;
     gift_card = NULL;
    char* buffer;
     buffer = NULL;
    int ret;
    ret = 0;
    {
        char** tlv10;
         tlv10 = & gift_card;
        size = cgc_getRandomGiftCard(tlv10);
    }
    {
        cgc_size_t tlv13;
        tlv13 = size + sizeof ( "ID=" ) + sizeof ( "\n" ) + 1;
        int tlv12;
        tlv12 = 0;
        void** tlv11;
        tlv11 = ( void * * ) & buffer;
        ret = cgc_allocate(tlv13,tlv12,tlv11);
    }
    if (ret != 0) {
 {
     unsigned int tlv25;
     tlv25 = 3;
    	cgc__terminate(tlv25);
 }
    }
    {
        void* tlv3;
        tlv3 = buffer;
        int tlv2;
        tlv2 = 0;
        cgc_size_t tlv1;
        tlv1 = size + sizeof ( "ID=" ) + sizeof ( "\n" ) + 1;
        cgc_memset(tlv3,tlv2,tlv1);
    }
    {
        char* tlv5;
         tlv5 = buffer;
        const char tlv4 [ ] = "ID=";
        cgc_strcat(tlv5,tlv4);
    }
    {
        char* tlv7;
         tlv7 = buffer;
        const char* tlv6 = gift_card;
        cgc_strcat(tlv7,tlv6);
    }
    {
        char* tlv9;
         tlv9 = buffer;
        const char tlv8 [ ] = "\n";
        cgc_strcat(tlv9,tlv8);
    }
    {
        void* tlv15;
        tlv15 = gift_card;
        cgc_size_t tlv14;
        tlv14 = size;
        ret = cgc_deallocate(tlv15,tlv14);
    }
    if (ret != 0) {
 {
     unsigned int tlv26;
     tlv26 = 3;
    	cgc__terminate(tlv26);
 }
    }
    {
        int tlv18;
        tlv18 = STDOUT;
        const char* tlv17 = buffer;
        cgc_size_t tlv16;
        {
            const char* tlv30 = buffer;
            tlv16 = cgc_strlen(tlv30);
        }
        ret = cgc_transmit_all(tlv18,tlv17,tlv16);
    }
    if (ret != 0) {
 {
     unsigned int tlv27;
     tlv27 = 10;
    	cgc__terminate(tlv27);
 }
    }
    {
        void* tlv20;
        tlv20 = buffer;
        cgc_size_t tlv19;
        tlv19 = size + sizeof ( "ID=" ) + sizeof ( "\n" ) + 1;
        ret = cgc_deallocate(tlv20,tlv19);
    }
    if (ret != 0) {
 {
     unsigned int tlv28;
     tlv28 = 3;
    	cgc__terminate(tlv28);
 }
    }
    {
        int tlv21;
        tlv21 = STDIN;
        mySongList->balance = cgc_receiveBalance(tlv21);
    }
    {
        cgc_size_t tlv24;
        tlv24 = sizeof ( Song ) * mySongList -> balance;
        int tlv23;
        tlv23 = 0;
        void** tlv22;
        tlv22 = ( void * * ) & mySongList -> songs;
        ret = cgc_allocate(tlv24,tlv23,tlv22);
    }
    if (ret != 0) {
 {
     unsigned int tlv29;
     tlv29 = 3;
    	cgc__terminate(tlv29);
 }
    }
    return 0;
}

void fix_ingred_service_16();
Song *cgc_selectSong(SongList results, Request request)
{
if (fix_ingred_enable){ fix_ingred_service_16(); };
    return &results.songs[0];
}

void fix_ingred_service_17_0_0();
void fix_ingred_service_17_0_4();
void fix_ingred_service_17_0();
void fix_ingred_service_17_4_0();
void fix_ingred_service_17_4();
void fix_ingred_service_17_5_0();
void fix_ingred_service_17_5_2();
void fix_ingred_service_17_5();
void fix_ingred_service_17_8_8();
void fix_ingred_service_17_8_9();
void fix_ingred_service_17_8();
void fix_ingred_service_17_9_0();
void fix_ingred_service_17_9_1();
void fix_ingred_service_17_9();
void fix_ingred_service_17_11_0();
void fix_ingred_service_17_11();
void fix_ingred_service_17();
int main(int cgc_argc, char *cgc_argv[])
{
if (fix_ingred_enable){ fix_ingred_service_17(); };
    int ret;
    ret = 0;
    int starting_balance;
    starting_balance = 0;
    SongList mySongList = { 0, NULL, 0 };
    SongList results = { 0, NULL, 0 };
    Request request = { 0, 0, 0 };
    Song songs[RESULT_LIMIT] = { 0 };
    Song* selectedSong;
    selectedSong = NULL;
    results.songs = songs;
    {
        SongList* tlv1;
        tlv1 = & mySongList;
        cgc_getBalance(tlv1);
    }
    starting_balance = mySongList.balance;
    while (mySongList.balance > 0) {
	results.size = 0;
 {
     Request* tlv4;
     tlv4 = & request;
    	cgc_createRandomRequest(tlv4);
 }
 {
     int tlv6;
     tlv6 = STDOUT;
     Request tlv5;
     tlv5 = request;
    	cgc_sendSearchString(tlv6,tlv5);
 }
 {
     int tlv9;
     tlv9 = STDIN;
     SongList* tlv8;
     tlv8 = & results;
     int tlv7;
     tlv7 = RESULT_LIMIT;
    	cgc_receiveSearchResults(tlv9,tlv8,tlv7);
 }
 {
     SongList tlv12;
     tlv12 = results;
     Request tlv11;
     tlv11 = request;
    	selectedSong = cgc_selectSong(tlv12,tlv11);
 }
 {
     int tlv15;
     tlv15 = STDOUT;
     Song* tlv14;
     tlv14 = selectedSong;
     SongList* tlv13;
     tlv13 = & mySongList;
    	ret = cgc_purchaseSong(tlv15,tlv14,tlv13);
 }
	if (ret == LOW_BALANCE) {
	    break;
	}
	cgc_receiveBalance(STDIN);
    }
    {
        void* tlv3;
        tlv3 = mySongList . songs;
        cgc_size_t tlv2;
        tlv2 = sizeof ( Song ) * starting_balance;
        ret = cgc_deallocate(tlv3,tlv2);
    }
    if (ret != 0) {
 {
     unsigned int tlv10;
     tlv10 = 3;
    	cgc__terminate(tlv10);
 }
    }
    return ret;
}

void fix_ingred_service_0_0_0(){
char buffer_ref;
    bzero(&buffer_ref,1*sizeof(char));
char * buffer = &buffer_ref;
    {char * ptr; ptr = (char *)(NULL); }
    {int count; count = (int)(NULL); }
    {int i; i = (int)(NULL); }
    {char * delim; delim = (char *)(NULL); }
    {void * tlv3; tlv3 = (void *)(NULL); }
    {void * tlv2; tlv2 = (void *)(NULL); }
    {cgc_size_t tlv1; tlv1 = (cgc_size_t)(NULL); }
}
void fix_ingred_service_0_0_1(){
char buffer_ref;
    bzero(&buffer_ref,1*sizeof(char));
char * buffer = &buffer_ref;
    {char * ptr; ptr = (char *)(0); }
    {int count; count = (int)(0); }
    {int i; i = (int)(0); }
    {char * delim; delim = (char *)(0); }
    {void * tlv3; tlv3 = (void *)(0); }
    {void * tlv2; tlv2 = (void *)(0); }
    {cgc_size_t tlv1; tlv1 = (cgc_size_t)(0); }
}
void fix_ingred_service_0_0_3(){
char buffer_ref;
    bzero(&buffer_ref,1*sizeof(char));
char * buffer = &buffer_ref;
    {char * ptr; ptr = (char *)(PARAM_DELIM); }
    {int count; count = (int)(PARAM_DELIM); }
    {int i; i = (int)(PARAM_DELIM); }
    {char * delim; delim = (char *)(PARAM_DELIM); }
    {void * tlv3; tlv3 = (void *)(PARAM_DELIM); }
    {void * tlv2; tlv2 = (void *)(PARAM_DELIM); }
    {cgc_size_t tlv1; tlv1 = (cgc_size_t)(PARAM_DELIM); }
}
void fix_ingred_service_0_0_4(){
char buffer_ref;
    bzero(&buffer_ref,1*sizeof(char));
char * buffer = &buffer_ref;
    {char * ptr; ptr = (char *)(buffer); }
    {int count; count = (int)(buffer); }
    {int i; i = (int)(buffer); }
    {char * delim; delim = (char *)(buffer); }
    {void * tlv3; tlv3 = (void *)(buffer); }
    {void * tlv2; tlv2 = (void *)(buffer); }
    {cgc_size_t tlv1; tlv1 = (cgc_size_t)(buffer); }
}
void fix_ingred_service_0_0(){
fix_ingred_service_0_0_0();
fix_ingred_service_0_0_1();
fix_ingred_service_0_0_3();
fix_ingred_service_0_0_4();
}
void fix_ingred_service_0_1_5(){
char ptr_ref;
    bzero(&ptr_ref,1*sizeof(char));
char * ptr = &ptr_ref;
char delim_ref;
    bzero(&delim_ref,1*sizeof(char));
char * delim = &delim_ref;
int count;
    bzero(&count,sizeof(int));
    {int count; count = (int)(* ptr); }
    {int i; i = (int)(* ptr); }
    {char * delim; delim = (char *)(* ptr); }
    {void * tlv3; tlv3 = (void *)(* ptr); }
    {void * tlv2; tlv2 = (void *)(* ptr); }
    {cgc_size_t tlv1; tlv1 = (cgc_size_t)(* ptr); }
}
void fix_ingred_service_0_1_6(){
char ptr_ref;
    bzero(&ptr_ref,1*sizeof(char));
char * ptr = &ptr_ref;
char delim_ref;
    bzero(&delim_ref,1*sizeof(char));
char * delim = &delim_ref;
int count;
    bzero(&count,sizeof(int));
    {char * ptr; ptr = (char *)(* delim); }
    {int count; count = (int)(* delim); }
    {int i; i = (int)(* delim); }
    {void * tlv3; tlv3 = (void *)(* delim); }
    {void * tlv2; tlv2 = (void *)(* delim); }
    {cgc_size_t tlv1; tlv1 = (cgc_size_t)(* delim); }
}
void fix_ingred_service_0_1_7(){
char ptr_ref;
    bzero(&ptr_ref,1*sizeof(char));
char * ptr = &ptr_ref;
char delim_ref;
    bzero(&delim_ref,1*sizeof(char));
char * delim = &delim_ref;
int count;
    bzero(&count,sizeof(int));
    {char * ptr; ptr = (char *)(count); }
    {int i; i = (int)(count); }
    {char * delim; delim = (char *)(count); }
    {void * tlv3; tlv3 = (void *)(count); }
    {void * tlv2; tlv2 = (void *)(count); }
    {cgc_size_t tlv1; tlv1 = (cgc_size_t)(count); }
}
void fix_ingred_service_0_1_8(){
char ptr_ref;
    bzero(&ptr_ref,1*sizeof(char));
char * ptr = &ptr_ref;
char delim_ref;
    bzero(&delim_ref,1*sizeof(char));
char * delim = &delim_ref;
int count;
    bzero(&count,sizeof(int));
    {char * ptr; ptr = (char *)(RESULT_VALUE_SIZE); }
    {int count; count = (int)(RESULT_VALUE_SIZE); }
    {int i; i = (int)(RESULT_VALUE_SIZE); }
    {char * delim; delim = (char *)(RESULT_VALUE_SIZE); }
    {void * tlv3; tlv3 = (void *)(RESULT_VALUE_SIZE); }
    {void * tlv2; tlv2 = (void *)(RESULT_VALUE_SIZE); }
    {cgc_size_t tlv1; tlv1 = (cgc_size_t)(RESULT_VALUE_SIZE); }
}
void fix_ingred_service_0_1(){
fix_ingred_service_0_1_5();
fix_ingred_service_0_1_6();
fix_ingred_service_0_1_7();
fix_ingred_service_0_1_8();
}
void fix_ingred_service_0_2_0(){
char value_ref;
    bzero(&value_ref,1*sizeof(char));
char * value = &value_ref;
char buffer_ref;
    bzero(&buffer_ref,1*sizeof(char));
char * buffer = &buffer_ref;
int count;
    bzero(&count,sizeof(int));
    {char * ptr; ptr = (char *)(value); }
    {int count; count = (int)(value); }
    {int i; i = (int)(value); }
    {char * delim; delim = (char *)(value); }
    {void * tlv3; tlv3 = (void *)(value); }
    {void * tlv2; tlv2 = (void *)(value); }
    {cgc_size_t tlv1; tlv1 = (cgc_size_t)(value); }
}
void fix_ingred_service_0_2_1(){
char value_ref;
    bzero(&value_ref,1*sizeof(char));
char * value = &value_ref;
char buffer_ref;
    bzero(&buffer_ref,1*sizeof(char));
char * buffer = &buffer_ref;
int count;
    bzero(&count,sizeof(int));
    {char * ptr; ptr = (char *)(buffer); }
    {int count; count = (int)(buffer); }
    {int i; i = (int)(buffer); }
    {char * delim; delim = (char *)(buffer); }
    {void * tlv3; tlv3 = (void *)(buffer); }
    {void * tlv2; tlv2 = (void *)(buffer); }
    {cgc_size_t tlv1; tlv1 = (cgc_size_t)(buffer); }
}
void fix_ingred_service_0_2_2(){
char value_ref;
    bzero(&value_ref,1*sizeof(char));
char * value = &value_ref;
char buffer_ref;
    bzero(&buffer_ref,1*sizeof(char));
char * buffer = &buffer_ref;
int count;
    bzero(&count,sizeof(int));
    {char * ptr; ptr = (char *)(count); }
    {int i; i = (int)(count); }
    {char * delim; delim = (char *)(count); }
    {void * tlv3; tlv3 = (void *)(count); }
    {void * tlv2; tlv2 = (void *)(count); }
    {cgc_size_t tlv1; tlv1 = (cgc_size_t)(count); }
}
void fix_ingred_service_0_2(){
fix_ingred_service_0_2_0();
fix_ingred_service_0_2_1();
fix_ingred_service_0_2_2();
}
void fix_ingred_service_0(){
fix_ingred_service_0_0();
fix_ingred_service_0_1();
fix_ingred_service_0_2();
}
void fix_ingred_service_1_0_0(){
char buffer_ref;
    bzero(&buffer_ref,1*sizeof(char));
char * buffer = &buffer_ref;
char start_ref;
    bzero(&start_ref,1*sizeof(char));
char * start = &start_ref;
    {char * start; start = (char *)(NULL); }
    {char * end; end = (char *)(NULL); }
    {char key [ KEY_SIZE ]; key [ ( KEY_SIZE )-1 ] = (char)(NULL); }
    {char value [ RESULT_VALUE_SIZE ]; value [ ( RESULT_VALUE_SIZE )-1 ] = (char)(NULL); }
    {int ret; ret = (int)(NULL); }
    {int num_results; num_results = (int)(NULL); }
    {int tlv1; tlv1 = (int)(NULL); }
    {void * tlv4; tlv4 = (void *)(NULL); }
    {cgc_size_t tlv2; tlv2 = (cgc_size_t)(NULL); }
    {char * tlv8; tlv8 = (char *)(NULL); }
    {char * tlv7; tlv7 = (char *)(NULL); }
}
void fix_ingred_service_1_0_2(){
char buffer_ref;
    bzero(&buffer_ref,1*sizeof(char));
char * buffer = &buffer_ref;
char start_ref;
    bzero(&start_ref,1*sizeof(char));
char * start = &start_ref;
    {char * start; start = (char *)(0); }
    {char * end; end = (char *)(0); }
    {char key [ KEY_SIZE ]; key [ ( KEY_SIZE )-1 ] = (char)(0); }
    {char value [ RESULT_VALUE_SIZE ]; value [ ( RESULT_VALUE_SIZE )-1 ] = (char)(0); }
    {int ret; ret = (int)(0); }
    {int num_results; num_results = (int)(0); }
    {int tlv1; tlv1 = (int)(0); }
    {void * tlv4; tlv4 = (void *)(0); }
    {cgc_size_t tlv2; tlv2 = (cgc_size_t)(0); }
    {char * tlv8; tlv8 = (char *)(0); }
    {char * tlv7; tlv7 = (char *)(0); }
}
void fix_ingred_service_1_0_4(){
char buffer_ref;
    bzero(&buffer_ref,1*sizeof(char));
char * buffer = &buffer_ref;
char start_ref;
    bzero(&start_ref,1*sizeof(char));
char * start = &start_ref;
    {char * start; start = (char *)(KEYVAL_DELIM); }
    {char * end; end = (char *)(KEYVAL_DELIM); }
    {char key [ KEY_SIZE ]; key [ ( KEY_SIZE )-1 ] = (char)(KEYVAL_DELIM); }
    {char value [ RESULT_VALUE_SIZE ]; value [ ( RESULT_VALUE_SIZE )-1 ] = (char)(KEYVAL_DELIM); }
    {int count; count = (int)(KEYVAL_DELIM); }
    {int i; i = (int)(KEYVAL_DELIM); }
    {char * delim; delim = (char *)(KEYVAL_DELIM); }
    {int ret; ret = (int)(KEYVAL_DELIM); }
    {int num_results; num_results = (int)(KEYVAL_DELIM); }
    {int tlv1; tlv1 = (int)(KEYVAL_DELIM); }
    {void * tlv4; tlv4 = (void *)(KEYVAL_DELIM); }
    {void * tlv3; tlv3 = (void *)(KEYVAL_DELIM); }
    {cgc_size_t tlv2; tlv2 = (cgc_size_t)(KEYVAL_DELIM); }
    {char * tlv8; tlv8 = (char *)(KEYVAL_DELIM); }
    {char * tlv7; tlv7 = (char *)(KEYVAL_DELIM); }
}
void fix_ingred_service_1_0_7(){
char buffer_ref;
    bzero(&buffer_ref,1*sizeof(char));
char * buffer = &buffer_ref;
char start_ref;
    bzero(&start_ref,1*sizeof(char));
char * start = &start_ref;
    {char * start; start = (char *)(buffer); }
    {char * end; end = (char *)(buffer); }
    {char key [ KEY_SIZE ]; key [ ( KEY_SIZE )-1 ] = (char)(buffer); }
    {char value [ RESULT_VALUE_SIZE ]; value [ ( RESULT_VALUE_SIZE )-1 ] = (char)(buffer); }
    {int ret; ret = (int)(buffer); }
    {int num_results; num_results = (int)(buffer); }
    {int tlv1; tlv1 = (int)(buffer); }
    {void * tlv4; tlv4 = (void *)(buffer); }
    {cgc_size_t tlv2; tlv2 = (cgc_size_t)(buffer); }
    {char * tlv8; tlv8 = (char *)(buffer); }
    {char * tlv7; tlv7 = (char *)(buffer); }
}
void fix_ingred_service_1_0_8(){
char buffer_ref;
    bzero(&buffer_ref,1*sizeof(char));
char * buffer = &buffer_ref;
char start_ref;
    bzero(&start_ref,1*sizeof(char));
char * start = &start_ref;
    {char * end; end = (char *)(start); }
    {char key [ KEY_SIZE ]; key [ ( KEY_SIZE )-1 ] = (char)(start); }
    {char value [ RESULT_VALUE_SIZE ]; value [ ( RESULT_VALUE_SIZE )-1 ] = (char)(start); }
    {int count; count = (int)(start); }
    {int i; i = (int)(start); }
    {char * delim; delim = (char *)(start); }
    {int ret; ret = (int)(start); }
    {int num_results; num_results = (int)(start); }
    {int tlv1; tlv1 = (int)(start); }
    {void * tlv4; tlv4 = (void *)(start); }
    {void * tlv3; tlv3 = (void *)(start); }
    {cgc_size_t tlv2; tlv2 = (cgc_size_t)(start); }
    {char * tlv8; tlv8 = (char *)(start); }
    {char * tlv7; tlv7 = (char *)(start); }
}
void fix_ingred_service_1_0(){
fix_ingred_service_1_0_0();
fix_ingred_service_1_0_2();
fix_ingred_service_1_0_4();
fix_ingred_service_1_0_7();
fix_ingred_service_1_0_8();
}
void fix_ingred_service_1_1_10(){
char end_ref;
    bzero(&end_ref,1*sizeof(char));
char * end = &end_ref;
char delim_ref;
    bzero(&delim_ref,1*sizeof(char));
char * delim = &delim_ref;
int count;
    bzero(&count,sizeof(int));
    {char * start; start = (char *)(* end); }
    {char key [ KEY_SIZE ]; key [ ( KEY_SIZE )-1 ] = (char)(* end); }
    {char value [ RESULT_VALUE_SIZE ]; value [ ( RESULT_VALUE_SIZE )-1 ] = (char)(* end); }
    {int count; count = (int)(* end); }
    {int i; i = (int)(* end); }
    {char * delim; delim = (char *)(* end); }
    {int ret; ret = (int)(* end); }
    {int num_results; num_results = (int)(* end); }
    {int tlv1; tlv1 = (int)(* end); }
    {void * tlv4; tlv4 = (void *)(* end); }
    {void * tlv3; tlv3 = (void *)(* end); }
    {cgc_size_t tlv2; tlv2 = (cgc_size_t)(* end); }
    {char * tlv8; tlv8 = (char *)(* end); }
    {char * tlv7; tlv7 = (char *)(* end); }
}
void fix_ingred_service_1_1_11(){
char end_ref;
    bzero(&end_ref,1*sizeof(char));
char * end = &end_ref;
char delim_ref;
    bzero(&delim_ref,1*sizeof(char));
char * delim = &delim_ref;
int count;
    bzero(&count,sizeof(int));
    {char * start; start = (char *)(* delim); }
    {char * end; end = (char *)(* delim); }
    {char key [ KEY_SIZE ]; key [ ( KEY_SIZE )-1 ] = (char)(* delim); }
    {char value [ RESULT_VALUE_SIZE ]; value [ ( RESULT_VALUE_SIZE )-1 ] = (char)(* delim); }
    {int ret; ret = (int)(* delim); }
    {int num_results; num_results = (int)(* delim); }
    {int tlv1; tlv1 = (int)(* delim); }
    {void * tlv4; tlv4 = (void *)(* delim); }
    {cgc_size_t tlv2; tlv2 = (cgc_size_t)(* delim); }
    {char * tlv8; tlv8 = (char *)(* delim); }
    {char * tlv7; tlv7 = (char *)(* delim); }
}
void fix_ingred_service_1_1_12(){
char end_ref;
    bzero(&end_ref,1*sizeof(char));
char * end = &end_ref;
char delim_ref;
    bzero(&delim_ref,1*sizeof(char));
char * delim = &delim_ref;
int count;
    bzero(&count,sizeof(int));
    {char * start; start = (char *)(count); }
    {char * end; end = (char *)(count); }
    {char key [ KEY_SIZE ]; key [ ( KEY_SIZE )-1 ] = (char)(count); }
    {char value [ RESULT_VALUE_SIZE ]; value [ ( RESULT_VALUE_SIZE )-1 ] = (char)(count); }
    {int ret; ret = (int)(count); }
    {int num_results; num_results = (int)(count); }
    {int tlv1; tlv1 = (int)(count); }
    {void * tlv4; tlv4 = (void *)(count); }
    {cgc_size_t tlv2; tlv2 = (cgc_size_t)(count); }
    {char * tlv8; tlv8 = (char *)(count); }
    {char * tlv7; tlv7 = (char *)(count); }
}
void fix_ingred_service_1_1_13(){
char end_ref;
    bzero(&end_ref,1*sizeof(char));
char * end = &end_ref;
char delim_ref;
    bzero(&delim_ref,1*sizeof(char));
char * delim = &delim_ref;
int count;
    bzero(&count,sizeof(int));
    {char * start; start = (char *)(KEY_SIZE); }
    {char * end; end = (char *)(KEY_SIZE); }
    {char key [ KEY_SIZE ]; key [ ( KEY_SIZE )-1 ] = (char)(KEY_SIZE); }
    {char value [ RESULT_VALUE_SIZE ]; value [ ( RESULT_VALUE_SIZE )-1 ] = (char)(KEY_SIZE); }
    {int count; count = (int)(KEY_SIZE); }
    {int i; i = (int)(KEY_SIZE); }
    {char * delim; delim = (char *)(KEY_SIZE); }
    {int ret; ret = (int)(KEY_SIZE); }
    {int num_results; num_results = (int)(KEY_SIZE); }
    {int tlv1; tlv1 = (int)(KEY_SIZE); }
    {void * tlv4; tlv4 = (void *)(KEY_SIZE); }
    {void * tlv3; tlv3 = (void *)(KEY_SIZE); }
    {cgc_size_t tlv2; tlv2 = (cgc_size_t)(KEY_SIZE); }
    {char * tlv8; tlv8 = (char *)(KEY_SIZE); }
    {char * tlv7; tlv7 = (char *)(KEY_SIZE); }
}
void fix_ingred_service_1_1(){
fix_ingred_service_1_1_10();
fix_ingred_service_1_1_11();
fix_ingred_service_1_1_12();
fix_ingred_service_1_1_13();
}
void fix_ingred_service_1_2_0(){
char key [ KEY_SIZE ];
    bzero(&key,( KEY_SIZE *sizeof(char) ) );
char start_ref;
    bzero(&start_ref,1*sizeof(char));
char * start = &start_ref;
int count;
    bzero(&count,sizeof(int));
    {char * start; start = (char *)(key); }
    {char * end; end = (char *)(key); }
    {char key [ KEY_SIZE ]; key [ ( KEY_SIZE )-1 ] = (char)(key); }
    {char value [ RESULT_VALUE_SIZE ]; value [ ( RESULT_VALUE_SIZE )-1 ] = (char)(key); }
    {int count; count = (int)(key); }
    {int i; i = (int)(key); }
    {char * delim; delim = (char *)(key); }
    {int ret; ret = (int)(key); }
    {int num_results; num_results = (int)(key); }
    {int tlv1; tlv1 = (int)(key); }
    {void * tlv4; tlv4 = (void *)(key); }
    {void * tlv3; tlv3 = (void *)(key); }
    {cgc_size_t tlv2; tlv2 = (cgc_size_t)(key); }
    {char * tlv8; tlv8 = (char *)(key); }
    {char * tlv7; tlv7 = (char *)(key); }
}
void fix_ingred_service_1_2_1(){
char key [ KEY_SIZE ];
    bzero(&key,( KEY_SIZE *sizeof(char) ) );
char start_ref;
    bzero(&start_ref,1*sizeof(char));
char * start = &start_ref;
int count;
    bzero(&count,sizeof(int));
    {char * end; end = (char *)(start); }
    {char key [ KEY_SIZE ]; key [ ( KEY_SIZE )-1 ] = (char)(start); }
    {char value [ RESULT_VALUE_SIZE ]; value [ ( RESULT_VALUE_SIZE )-1 ] = (char)(start); }
    {int count; count = (int)(start); }
    {int i; i = (int)(start); }
    {char * delim; delim = (char *)(start); }
    {int ret; ret = (int)(start); }
    {int num_results; num_results = (int)(start); }
    {int tlv1; tlv1 = (int)(start); }
    {void * tlv4; tlv4 = (void *)(start); }
    {void * tlv3; tlv3 = (void *)(start); }
    {cgc_size_t tlv2; tlv2 = (cgc_size_t)(start); }
    {char * tlv8; tlv8 = (char *)(start); }
    {char * tlv7; tlv7 = (char *)(start); }
}
void fix_ingred_service_1_2_2(){
char key [ KEY_SIZE ];
    bzero(&key,( KEY_SIZE *sizeof(char) ) );
char start_ref;
    bzero(&start_ref,1*sizeof(char));
char * start = &start_ref;
int count;
    bzero(&count,sizeof(int));
    {char * start; start = (char *)(count); }
    {char * end; end = (char *)(count); }
    {char key [ KEY_SIZE ]; key [ ( KEY_SIZE )-1 ] = (char)(count); }
    {char value [ RESULT_VALUE_SIZE ]; value [ ( RESULT_VALUE_SIZE )-1 ] = (char)(count); }
    {int ret; ret = (int)(count); }
    {int num_results; num_results = (int)(count); }
    {int tlv1; tlv1 = (int)(count); }
    {void * tlv4; tlv4 = (void *)(count); }
    {cgc_size_t tlv2; tlv2 = (cgc_size_t)(count); }
    {char * tlv8; tlv8 = (char *)(count); }
    {char * tlv7; tlv7 = (char *)(count); }
}
void fix_ingred_service_1_2(){
fix_ingred_service_1_2_0();
fix_ingred_service_1_2_1();
fix_ingred_service_1_2_2();
}
void fix_ingred_service_1_4_10(){
int tlv1;
    bzero(&tlv1,sizeof(int));
    {char * start; start = (char *)(tlv1); }
    {char * end; end = (char *)(tlv1); }
    {char key [ KEY_SIZE ]; key [ ( KEY_SIZE )-1 ] = (char)(tlv1); }
    {char value [ RESULT_VALUE_SIZE ]; value [ ( RESULT_VALUE_SIZE )-1 ] = (char)(tlv1); }
    {int count; count = (int)(tlv1); }
    {int i; i = (int)(tlv1); }
    {char * delim; delim = (char *)(tlv1); }
    {int ret; ret = (int)(tlv1); }
    {int num_results; num_results = (int)(tlv1); }
    {void * tlv4; tlv4 = (void *)(tlv1); }
    {void * tlv3; tlv3 = (void *)(tlv1); }
    {cgc_size_t tlv2; tlv2 = (cgc_size_t)(tlv1); }
    {char * tlv8; tlv8 = (char *)(tlv1); }
    {char * tlv7; tlv7 = (char *)(tlv1); }
}
void fix_ingred_service_1_4(){
fix_ingred_service_1_4_10();
}
void fix_ingred_service_1_5_0(){
char end_ref;
    bzero(&end_ref,1*sizeof(char));
char * end = &end_ref;
char value [ RESULT_VALUE_SIZE ];
    bzero(&value,( RESULT_VALUE_SIZE *sizeof(char) ) );
    {char * start; start = (char *)(++ end); }
    {char key [ KEY_SIZE ]; key [ ( KEY_SIZE )-1 ] = (char)(++ end); }
    {char value [ RESULT_VALUE_SIZE ]; value [ ( RESULT_VALUE_SIZE )-1 ] = (char)(++ end); }
    {int count; count = (int)(++ end); }
    {int i; i = (int)(++ end); }
    {char * delim; delim = (char *)(++ end); }
    {int ret; ret = (int)(++ end); }
    {int num_results; num_results = (int)(++ end); }
    {int tlv1; tlv1 = (int)(++ end); }
    {void * tlv4; tlv4 = (void *)(++ end); }
    {void * tlv3; tlv3 = (void *)(++ end); }
    {cgc_size_t tlv2; tlv2 = (cgc_size_t)(++ end); }
    {char * tlv8; tlv8 = (char *)(++ end); }
    {char * tlv7; tlv7 = (char *)(++ end); }
}
void fix_ingred_service_1_5_1(){
char end_ref;
    bzero(&end_ref,1*sizeof(char));
char * end = &end_ref;
char value [ RESULT_VALUE_SIZE ];
    bzero(&value,( RESULT_VALUE_SIZE *sizeof(char) ) );
    {char * start; start = (char *)(value); }
    {char * end; end = (char *)(value); }
    {char key [ KEY_SIZE ]; key [ ( KEY_SIZE )-1 ] = (char)(value); }
    {char value [ RESULT_VALUE_SIZE ]; value [ ( RESULT_VALUE_SIZE )-1 ] = (char)(value); }
    {int count; count = (int)(value); }
    {int i; i = (int)(value); }
    {char * delim; delim = (char *)(value); }
    {int ret; ret = (int)(value); }
    {int num_results; num_results = (int)(value); }
    {int tlv1; tlv1 = (int)(value); }
    {void * tlv4; tlv4 = (void *)(value); }
    {void * tlv3; tlv3 = (void *)(value); }
    {cgc_size_t tlv2; tlv2 = (cgc_size_t)(value); }
    {char * tlv8; tlv8 = (char *)(value); }
    {char * tlv7; tlv7 = (char *)(value); }
}
void fix_ingred_service_1_5(){
fix_ingred_service_1_5_0();
fix_ingred_service_1_5_1();
}
void fix_ingred_service_1(){
fix_ingred_service_1_0();
fix_ingred_service_1_1();
fix_ingred_service_1_2();
fix_ingred_service_1_4();
fix_ingred_service_1_5();
}
void fix_ingred_service_2_0_0(){
char buffer_ref;
    bzero(&buffer_ref,1*sizeof(char));
char * buffer = &buffer_ref;
char start_ref;
    bzero(&start_ref,1*sizeof(char));
char * start = &start_ref;
    {int balance; balance = (int)(NULL); }
}
void fix_ingred_service_2_0_2(){
char buffer_ref;
    bzero(&buffer_ref,1*sizeof(char));
char * buffer = &buffer_ref;
char start_ref;
    bzero(&start_ref,1*sizeof(char));
char * start = &start_ref;
    {int balance; balance = (int)(0); }
}
void fix_ingred_service_2_0_4(){
char buffer_ref;
    bzero(&buffer_ref,1*sizeof(char));
char * buffer = &buffer_ref;
char start_ref;
    bzero(&start_ref,1*sizeof(char));
char * start = &start_ref;
    {int balance; balance = (int)(KEYVAL_DELIM); }
}
void fix_ingred_service_2_0_7(){
char buffer_ref;
    bzero(&buffer_ref,1*sizeof(char));
char * buffer = &buffer_ref;
char start_ref;
    bzero(&start_ref,1*sizeof(char));
char * start = &start_ref;
    {int balance; balance = (int)(buffer); }
}
void fix_ingred_service_2_0_8(){
char buffer_ref;
    bzero(&buffer_ref,1*sizeof(char));
char * buffer = &buffer_ref;
char start_ref;
    bzero(&start_ref,1*sizeof(char));
char * start = &start_ref;
    {int balance; balance = (int)(start); }
}
void fix_ingred_service_2_0(){
fix_ingred_service_2_0_0();
fix_ingred_service_2_0_2();
fix_ingred_service_2_0_4();
fix_ingred_service_2_0_7();
fix_ingred_service_2_0_8();
}
void fix_ingred_service_2_1_10(){
char end_ref;
    bzero(&end_ref,1*sizeof(char));
char * end = &end_ref;
char delim_ref;
    bzero(&delim_ref,1*sizeof(char));
char * delim = &delim_ref;
int count;
    bzero(&count,sizeof(int));
    {int balance; balance = (int)(* end); }
}
void fix_ingred_service_2_1_11(){
char end_ref;
    bzero(&end_ref,1*sizeof(char));
char * end = &end_ref;
char delim_ref;
    bzero(&delim_ref,1*sizeof(char));
char * delim = &delim_ref;
int count;
    bzero(&count,sizeof(int));
    {int balance; balance = (int)(* delim); }
}
void fix_ingred_service_2_1_12(){
char end_ref;
    bzero(&end_ref,1*sizeof(char));
char * end = &end_ref;
char delim_ref;
    bzero(&delim_ref,1*sizeof(char));
char * delim = &delim_ref;
int count;
    bzero(&count,sizeof(int));
    {int balance; balance = (int)(count); }
}
void fix_ingred_service_2_1_13(){
char end_ref;
    bzero(&end_ref,1*sizeof(char));
char * end = &end_ref;
char delim_ref;
    bzero(&delim_ref,1*sizeof(char));
char * delim = &delim_ref;
int count;
    bzero(&count,sizeof(int));
    {int balance; balance = (int)(KEY_SIZE); }
}
void fix_ingred_service_2_1(){
fix_ingred_service_2_1_10();
fix_ingred_service_2_1_11();
fix_ingred_service_2_1_12();
fix_ingred_service_2_1_13();
}
void fix_ingred_service_2_2_0(){
char key [ KEY_SIZE ];
    bzero(&key,( KEY_SIZE *sizeof(char) ) );
char start_ref;
    bzero(&start_ref,1*sizeof(char));
char * start = &start_ref;
int count;
    bzero(&count,sizeof(int));
    {int balance; balance = (int)(key); }
}
void fix_ingred_service_2_2_1(){
char key [ KEY_SIZE ];
    bzero(&key,( KEY_SIZE *sizeof(char) ) );
char start_ref;
    bzero(&start_ref,1*sizeof(char));
char * start = &start_ref;
int count;
    bzero(&count,sizeof(int));
    {int balance; balance = (int)(start); }
}
void fix_ingred_service_2_2_2(){
char key [ KEY_SIZE ];
    bzero(&key,( KEY_SIZE *sizeof(char) ) );
char start_ref;
    bzero(&start_ref,1*sizeof(char));
char * start = &start_ref;
int count;
    bzero(&count,sizeof(int));
    {int balance; balance = (int)(count); }
}
void fix_ingred_service_2_2(){
fix_ingred_service_2_2_0();
fix_ingred_service_2_2_1();
fix_ingred_service_2_2_2();
}
void fix_ingred_service_2_4_10(){
int tlv1;
    bzero(&tlv1,sizeof(int));
    {int balance; balance = (int)(tlv1); }
}
void fix_ingred_service_2_4(){
fix_ingred_service_2_4_10();
}
void fix_ingred_service_2_5_0(){
char end_ref;
    bzero(&end_ref,1*sizeof(char));
char * end = &end_ref;
char value [ RESULT_VALUE_SIZE ];
    bzero(&value,( RESULT_VALUE_SIZE *sizeof(char) ) );
    {int balance; balance = (int)(++ end); }
}
void fix_ingred_service_2_5_1(){
char end_ref;
    bzero(&end_ref,1*sizeof(char));
char * end = &end_ref;
char value [ RESULT_VALUE_SIZE ];
    bzero(&value,( RESULT_VALUE_SIZE *sizeof(char) ) );
    {int balance; balance = (int)(value); }
}
void fix_ingred_service_2_5(){
fix_ingred_service_2_5_0();
fix_ingred_service_2_5_1();
}
void fix_ingred_service_2_7_12(){
int balance;
    bzero(&balance,sizeof(int));
    {char * start; start = (char *)(balance); }
    {char * end; end = (char *)(balance); }
    {char key [ KEY_SIZE ]; key [ ( KEY_SIZE )-1 ] = (char)(balance); }
    {char value [ RESULT_VALUE_SIZE ]; value [ ( RESULT_VALUE_SIZE )-1 ] = (char)(balance); }
    {int count; count = (int)(balance); }
    {int i; i = (int)(balance); }
    {char * delim; delim = (char *)(balance); }
    {int ret; ret = (int)(balance); }
    {int tlv1; tlv1 = (int)(balance); }
    {void * tlv4; tlv4 = (void *)(balance); }
    {void * tlv3; tlv3 = (void *)(balance); }
    {cgc_size_t tlv2; tlv2 = (cgc_size_t)(balance); }
    {char * tlv8; tlv8 = (char *)(balance); }
    {char * tlv7; tlv7 = (char *)(balance); }
}
void fix_ingred_service_2_7_15(){
int balance;
    bzero(&balance,sizeof(int));
    {char * start; start = (char *)(255); }
    {char * end; end = (char *)(255); }
    {char key [ KEY_SIZE ]; key [ ( KEY_SIZE )-1 ] = (char)(255); }
    {char value [ RESULT_VALUE_SIZE ]; value [ ( RESULT_VALUE_SIZE )-1 ] = (char)(255); }
    {int count; count = (int)(255); }
    {int i; i = (int)(255); }
    {char * delim; delim = (char *)(255); }
    {int ret; ret = (int)(255); }
    {int balance; balance = (int)(255); }
    {int tlv1; tlv1 = (int)(255); }
    {void * tlv4; tlv4 = (void *)(255); }
    {void * tlv3; tlv3 = (void *)(255); }
    {cgc_size_t tlv2; tlv2 = (cgc_size_t)(255); }
    {char * tlv8; tlv8 = (char *)(255); }
    {char * tlv7; tlv7 = (char *)(255); }
}
void fix_ingred_service_2_7(){
fix_ingred_service_2_7_12();
fix_ingred_service_2_7_15();
}
void fix_ingred_service_2(){
fix_ingred_service_2_0();
fix_ingred_service_2_1();
fix_ingred_service_2_2();
fix_ingred_service_2_4();
fix_ingred_service_2_5();
fix_ingred_service_2_7();
}
void fix_ingred_service_3_0_0(){
char buffer_ref;
    bzero(&buffer_ref,1*sizeof(char));
char * buffer = &buffer_ref;
    {void * tlv8; tlv8 = (void *)(NULL); }
    {int tlv7; tlv7 = (int)(NULL); }
    {cgc_size_t tlv6; tlv6 = (cgc_size_t)(NULL); }
    {void * tlv11; tlv11 = (void *)(NULL); }
    {void * tlv10; tlv10 = (void *)(NULL); }
    {cgc_size_t tlv9; tlv9 = (cgc_size_t)(NULL); }
    {void * tlv14; tlv14 = (void *)(NULL); }
    {int tlv13; tlv13 = (int)(NULL); }
    {cgc_size_t tlv12; tlv12 = (cgc_size_t)(NULL); }
    {int tlv2; tlv2 = (int)(NULL); }
    {char * tlv18; tlv18 = (char *)(NULL); }
    {char * tlv17; tlv17 = (char *)(NULL); }
    {int tlv3; tlv3 = (int)(NULL); }
    {char * tlv22; tlv22 = (char *)(NULL); }
    {char * tlv21; tlv21 = (char *)(NULL); }
    {int tlv4; tlv4 = (int)(NULL); }
    {char * tlv26; tlv26 = (char *)(NULL); }
    {char * tlv25; tlv25 = (char *)(NULL); }
    {int tlv5; tlv5 = (int)(NULL); }
    {char * tlv30; tlv30 = (char *)(NULL); }
    {char * tlv29; tlv29 = (char *)(NULL); }
    {char * tlv34; tlv34 = (char *)(NULL); }
    {char * tlv33; tlv33 = (char *)(NULL); }
}
void fix_ingred_service_3_0_2(){
char buffer_ref;
    bzero(&buffer_ref,1*sizeof(char));
char * buffer = &buffer_ref;
    {void * tlv8; tlv8 = (void *)(0); }
    {int tlv7; tlv7 = (int)(0); }
    {cgc_size_t tlv6; tlv6 = (cgc_size_t)(0); }
    {void * tlv11; tlv11 = (void *)(0); }
    {void * tlv10; tlv10 = (void *)(0); }
    {cgc_size_t tlv9; tlv9 = (cgc_size_t)(0); }
    {void * tlv14; tlv14 = (void *)(0); }
    {int tlv13; tlv13 = (int)(0); }
    {cgc_size_t tlv12; tlv12 = (cgc_size_t)(0); }
    {int tlv2; tlv2 = (int)(0); }
    {char * tlv18; tlv18 = (char *)(0); }
    {char * tlv17; tlv17 = (char *)(0); }
    {int tlv3; tlv3 = (int)(0); }
    {char * tlv22; tlv22 = (char *)(0); }
    {char * tlv21; tlv21 = (char *)(0); }
    {int tlv4; tlv4 = (int)(0); }
    {char * tlv26; tlv26 = (char *)(0); }
    {char * tlv25; tlv25 = (char *)(0); }
    {int tlv5; tlv5 = (int)(0); }
    {char * tlv30; tlv30 = (char *)(0); }
    {char * tlv29; tlv29 = (char *)(0); }
    {char * tlv34; tlv34 = (char *)(0); }
    {char * tlv33; tlv33 = (char *)(0); }
}
void fix_ingred_service_3_0_4(){
char buffer_ref;
    bzero(&buffer_ref,1*sizeof(char));
char * buffer = &buffer_ref;
    {void * tlv8; tlv8 = (void *)(KEYVAL_DELIM); }
    {int tlv7; tlv7 = (int)(KEYVAL_DELIM); }
    {cgc_size_t tlv6; tlv6 = (cgc_size_t)(KEYVAL_DELIM); }
    {void * tlv11; tlv11 = (void *)(KEYVAL_DELIM); }
    {void * tlv10; tlv10 = (void *)(KEYVAL_DELIM); }
    {cgc_size_t tlv9; tlv9 = (cgc_size_t)(KEYVAL_DELIM); }
    {void * tlv14; tlv14 = (void *)(KEYVAL_DELIM); }
    {int tlv13; tlv13 = (int)(KEYVAL_DELIM); }
    {cgc_size_t tlv12; tlv12 = (cgc_size_t)(KEYVAL_DELIM); }
    {int tlv2; tlv2 = (int)(KEYVAL_DELIM); }
    {char * tlv18; tlv18 = (char *)(KEYVAL_DELIM); }
    {char * tlv17; tlv17 = (char *)(KEYVAL_DELIM); }
    {int tlv3; tlv3 = (int)(KEYVAL_DELIM); }
    {char * tlv22; tlv22 = (char *)(KEYVAL_DELIM); }
    {char * tlv21; tlv21 = (char *)(KEYVAL_DELIM); }
    {int tlv4; tlv4 = (int)(KEYVAL_DELIM); }
    {char * tlv26; tlv26 = (char *)(KEYVAL_DELIM); }
    {char * tlv25; tlv25 = (char *)(KEYVAL_DELIM); }
    {int tlv5; tlv5 = (int)(KEYVAL_DELIM); }
    {char * tlv30; tlv30 = (char *)(KEYVAL_DELIM); }
    {char * tlv29; tlv29 = (char *)(KEYVAL_DELIM); }
    {char * tlv34; tlv34 = (char *)(KEYVAL_DELIM); }
    {char * tlv33; tlv33 = (char *)(KEYVAL_DELIM); }
}
void fix_ingred_service_3_0_6(){
char buffer_ref;
    bzero(&buffer_ref,1*sizeof(char));
char * buffer = &buffer_ref;
    {void * tlv8; tlv8 = (void *)(buffer); }
    {int tlv7; tlv7 = (int)(buffer); }
    {cgc_size_t tlv6; tlv6 = (cgc_size_t)(buffer); }
    {void * tlv11; tlv11 = (void *)(buffer); }
    {void * tlv10; tlv10 = (void *)(buffer); }
    {cgc_size_t tlv9; tlv9 = (cgc_size_t)(buffer); }
    {void * tlv14; tlv14 = (void *)(buffer); }
    {int tlv13; tlv13 = (int)(buffer); }
    {cgc_size_t tlv12; tlv12 = (cgc_size_t)(buffer); }
    {int tlv2; tlv2 = (int)(buffer); }
    {char * tlv18; tlv18 = (char *)(buffer); }
    {char * tlv17; tlv17 = (char *)(buffer); }
    {int tlv3; tlv3 = (int)(buffer); }
    {char * tlv22; tlv22 = (char *)(buffer); }
    {char * tlv21; tlv21 = (char *)(buffer); }
    {int tlv4; tlv4 = (int)(buffer); }
    {char * tlv26; tlv26 = (char *)(buffer); }
    {char * tlv25; tlv25 = (char *)(buffer); }
    {int tlv5; tlv5 = (int)(buffer); }
    {char * tlv30; tlv30 = (char *)(buffer); }
    {char * tlv29; tlv29 = (char *)(buffer); }
    {char * tlv34; tlv34 = (char *)(buffer); }
    {char * tlv33; tlv33 = (char *)(buffer); }
}
void fix_ingred_service_3_0(){
fix_ingred_service_3_0_0();
fix_ingred_service_3_0_2();
fix_ingred_service_3_0_4();
fix_ingred_service_3_0_6();
}
void fix_ingred_service_3_1_0(){
Song song_ref;
    bzero(&song_ref,1*sizeof(Song));
Song * song = &song_ref;
    {char * start; start = (char *)(song); }
    {char * end; end = (char *)(song); }
    {char key [ KEY_SIZE ]; key [ ( KEY_SIZE )-1 ] = (char)(song); }
    {int count; count = (int)(song); }
    {int i; i = (int)(song); }
    {char * delim; delim = (char *)(song); }
    {int ret; ret = (int)(song); }
    {void * tlv8; tlv8 = (void *)(song); }
    {int tlv7; tlv7 = (int)(song); }
    {cgc_size_t tlv6; tlv6 = (cgc_size_t)(song); }
    {int tlv1; tlv1 = (int)(song); }
    {void * tlv11; tlv11 = (void *)(song); }
    {void * tlv10; tlv10 = (void *)(song); }
    {cgc_size_t tlv9; tlv9 = (cgc_size_t)(song); }
    {void * tlv14; tlv14 = (void *)(song); }
    {int tlv13; tlv13 = (int)(song); }
    {cgc_size_t tlv12; tlv12 = (cgc_size_t)(song); }
    {int tlv2; tlv2 = (int)(song); }
    {char * tlv18; tlv18 = (char *)(song); }
    {char * tlv17; tlv17 = (char *)(song); }
    {int tlv3; tlv3 = (int)(song); }
    {char * tlv22; tlv22 = (char *)(song); }
    {char * tlv21; tlv21 = (char *)(song); }
    {int tlv4; tlv4 = (int)(song); }
    {char * tlv26; tlv26 = (char *)(song); }
    {char * tlv25; tlv25 = (char *)(song); }
    {int tlv5; tlv5 = (int)(song); }
    {char * tlv30; tlv30 = (char *)(song); }
    {char * tlv29; tlv29 = (char *)(song); }
    {char * tlv34; tlv34 = (char *)(song); }
    {char * tlv33; tlv33 = (char *)(song); }
}
void fix_ingred_service_3_1_2(){
Song song_ref;
    bzero(&song_ref,1*sizeof(Song));
Song * song = &song_ref;
    {char * start; start = (char *)(SONG_SIZE); }
    {char * end; end = (char *)(SONG_SIZE); }
    {char key [ KEY_SIZE ]; key [ ( KEY_SIZE )-1 ] = (char)(SONG_SIZE); }
    {int count; count = (int)(SONG_SIZE); }
    {int i; i = (int)(SONG_SIZE); }
    {char * delim; delim = (char *)(SONG_SIZE); }
    {int ret; ret = (int)(SONG_SIZE); }
    {void * tlv8; tlv8 = (void *)(SONG_SIZE); }
    {int tlv7; tlv7 = (int)(SONG_SIZE); }
    {cgc_size_t tlv6; tlv6 = (cgc_size_t)(SONG_SIZE); }
    {int tlv1; tlv1 = (int)(SONG_SIZE); }
    {void * tlv11; tlv11 = (void *)(SONG_SIZE); }
    {void * tlv10; tlv10 = (void *)(SONG_SIZE); }
    {cgc_size_t tlv9; tlv9 = (cgc_size_t)(SONG_SIZE); }
    {void * tlv14; tlv14 = (void *)(SONG_SIZE); }
    {int tlv13; tlv13 = (int)(SONG_SIZE); }
    {cgc_size_t tlv12; tlv12 = (cgc_size_t)(SONG_SIZE); }
    {int tlv2; tlv2 = (int)(SONG_SIZE); }
    {char * tlv18; tlv18 = (char *)(SONG_SIZE); }
    {char * tlv17; tlv17 = (char *)(SONG_SIZE); }
    {int tlv3; tlv3 = (int)(SONG_SIZE); }
    {char * tlv22; tlv22 = (char *)(SONG_SIZE); }
    {char * tlv21; tlv21 = (char *)(SONG_SIZE); }
    {int tlv4; tlv4 = (int)(SONG_SIZE); }
    {char * tlv26; tlv26 = (char *)(SONG_SIZE); }
    {char * tlv25; tlv25 = (char *)(SONG_SIZE); }
    {int tlv5; tlv5 = (int)(SONG_SIZE); }
    {char * tlv30; tlv30 = (char *)(SONG_SIZE); }
    {char * tlv29; tlv29 = (char *)(SONG_SIZE); }
    {char * tlv34; tlv34 = (char *)(SONG_SIZE); }
    {char * tlv33; tlv33 = (char *)(SONG_SIZE); }
}
void fix_ingred_service_3_1(){
fix_ingred_service_3_1_0();
fix_ingred_service_3_1_2();
}
void fix_ingred_service_3_2_0(){
char start_ref;
    bzero(&start_ref,1*sizeof(char));
char * start = &start_ref;
    {void * tlv8; tlv8 = (void *)(start); }
    {int tlv7; tlv7 = (int)(start); }
    {cgc_size_t tlv6; tlv6 = (cgc_size_t)(start); }
    {void * tlv11; tlv11 = (void *)(start); }
    {void * tlv10; tlv10 = (void *)(start); }
    {cgc_size_t tlv9; tlv9 = (cgc_size_t)(start); }
    {void * tlv14; tlv14 = (void *)(start); }
    {int tlv13; tlv13 = (int)(start); }
    {cgc_size_t tlv12; tlv12 = (cgc_size_t)(start); }
    {int tlv2; tlv2 = (int)(start); }
    {char * tlv18; tlv18 = (char *)(start); }
    {char * tlv17; tlv17 = (char *)(start); }
    {int tlv3; tlv3 = (int)(start); }
    {char * tlv22; tlv22 = (char *)(start); }
    {char * tlv21; tlv21 = (char *)(start); }
    {int tlv4; tlv4 = (int)(start); }
    {char * tlv26; tlv26 = (char *)(start); }
    {char * tlv25; tlv25 = (char *)(start); }
    {int tlv5; tlv5 = (int)(start); }
    {char * tlv30; tlv30 = (char *)(start); }
    {char * tlv29; tlv29 = (char *)(start); }
    {char * tlv34; tlv34 = (char *)(start); }
    {char * tlv33; tlv33 = (char *)(start); }
}
void fix_ingred_service_3_2(){
fix_ingred_service_3_2_0();
}
void fix_ingred_service_3_3_9(){
char end_ref;
    bzero(&end_ref,1*sizeof(char));
char * end = &end_ref;
char delim_ref;
    bzero(&delim_ref,1*sizeof(char));
char * delim = &delim_ref;
int count;
    bzero(&count,sizeof(int));
    {void * tlv8; tlv8 = (void *)(* end); }
    {int tlv7; tlv7 = (int)(* end); }
    {cgc_size_t tlv6; tlv6 = (cgc_size_t)(* end); }
    {void * tlv11; tlv11 = (void *)(* end); }
    {void * tlv10; tlv10 = (void *)(* end); }
    {cgc_size_t tlv9; tlv9 = (cgc_size_t)(* end); }
    {void * tlv14; tlv14 = (void *)(* end); }
    {int tlv13; tlv13 = (int)(* end); }
    {cgc_size_t tlv12; tlv12 = (cgc_size_t)(* end); }
    {int tlv2; tlv2 = (int)(* end); }
    {char * tlv18; tlv18 = (char *)(* end); }
    {char * tlv17; tlv17 = (char *)(* end); }
    {int tlv3; tlv3 = (int)(* end); }
    {char * tlv22; tlv22 = (char *)(* end); }
    {char * tlv21; tlv21 = (char *)(* end); }
    {int tlv4; tlv4 = (int)(* end); }
    {char * tlv26; tlv26 = (char *)(* end); }
    {char * tlv25; tlv25 = (char *)(* end); }
    {int tlv5; tlv5 = (int)(* end); }
    {char * tlv30; tlv30 = (char *)(* end); }
    {char * tlv29; tlv29 = (char *)(* end); }
    {char * tlv34; tlv34 = (char *)(* end); }
    {char * tlv33; tlv33 = (char *)(* end); }
}
void fix_ingred_service_3_3_10(){
char end_ref;
    bzero(&end_ref,1*sizeof(char));
char * end = &end_ref;
char delim_ref;
    bzero(&delim_ref,1*sizeof(char));
char * delim = &delim_ref;
int count;
    bzero(&count,sizeof(int));
    {void * tlv8; tlv8 = (void *)(* delim); }
    {int tlv7; tlv7 = (int)(* delim); }
    {cgc_size_t tlv6; tlv6 = (cgc_size_t)(* delim); }
    {void * tlv11; tlv11 = (void *)(* delim); }
    {void * tlv10; tlv10 = (void *)(* delim); }
    {cgc_size_t tlv9; tlv9 = (cgc_size_t)(* delim); }
    {void * tlv14; tlv14 = (void *)(* delim); }
    {int tlv13; tlv13 = (int)(* delim); }
    {cgc_size_t tlv12; tlv12 = (cgc_size_t)(* delim); }
    {int tlv2; tlv2 = (int)(* delim); }
    {char * tlv18; tlv18 = (char *)(* delim); }
    {char * tlv17; tlv17 = (char *)(* delim); }
    {int tlv3; tlv3 = (int)(* delim); }
    {char * tlv22; tlv22 = (char *)(* delim); }
    {char * tlv21; tlv21 = (char *)(* delim); }
    {int tlv4; tlv4 = (int)(* delim); }
    {char * tlv26; tlv26 = (char *)(* delim); }
    {char * tlv25; tlv25 = (char *)(* delim); }
    {int tlv5; tlv5 = (int)(* delim); }
    {char * tlv30; tlv30 = (char *)(* delim); }
    {char * tlv29; tlv29 = (char *)(* delim); }
    {char * tlv34; tlv34 = (char *)(* delim); }
    {char * tlv33; tlv33 = (char *)(* delim); }
}
void fix_ingred_service_3_3_11(){
char end_ref;
    bzero(&end_ref,1*sizeof(char));
char * end = &end_ref;
char delim_ref;
    bzero(&delim_ref,1*sizeof(char));
char * delim = &delim_ref;
int count;
    bzero(&count,sizeof(int));
    {void * tlv8; tlv8 = (void *)(count); }
    {int tlv7; tlv7 = (int)(count); }
    {cgc_size_t tlv6; tlv6 = (cgc_size_t)(count); }
    {void * tlv11; tlv11 = (void *)(count); }
    {void * tlv10; tlv10 = (void *)(count); }
    {cgc_size_t tlv9; tlv9 = (cgc_size_t)(count); }
    {void * tlv14; tlv14 = (void *)(count); }
    {int tlv13; tlv13 = (int)(count); }
    {cgc_size_t tlv12; tlv12 = (cgc_size_t)(count); }
    {int tlv2; tlv2 = (int)(count); }
    {char * tlv18; tlv18 = (char *)(count); }
    {char * tlv17; tlv17 = (char *)(count); }
    {int tlv3; tlv3 = (int)(count); }
    {char * tlv22; tlv22 = (char *)(count); }
    {char * tlv21; tlv21 = (char *)(count); }
    {int tlv4; tlv4 = (int)(count); }
    {char * tlv26; tlv26 = (char *)(count); }
    {char * tlv25; tlv25 = (char *)(count); }
    {int tlv5; tlv5 = (int)(count); }
    {char * tlv30; tlv30 = (char *)(count); }
    {char * tlv29; tlv29 = (char *)(count); }
    {char * tlv34; tlv34 = (char *)(count); }
    {char * tlv33; tlv33 = (char *)(count); }
}
void fix_ingred_service_3_3_12(){
char end_ref;
    bzero(&end_ref,1*sizeof(char));
char * end = &end_ref;
char delim_ref;
    bzero(&delim_ref,1*sizeof(char));
char * delim = &delim_ref;
int count;
    bzero(&count,sizeof(int));
    {void * tlv8; tlv8 = (void *)(KEY_SIZE); }
    {int tlv7; tlv7 = (int)(KEY_SIZE); }
    {cgc_size_t tlv6; tlv6 = (cgc_size_t)(KEY_SIZE); }
    {void * tlv11; tlv11 = (void *)(KEY_SIZE); }
    {void * tlv10; tlv10 = (void *)(KEY_SIZE); }
    {cgc_size_t tlv9; tlv9 = (cgc_size_t)(KEY_SIZE); }
    {void * tlv14; tlv14 = (void *)(KEY_SIZE); }
    {int tlv13; tlv13 = (int)(KEY_SIZE); }
    {cgc_size_t tlv12; tlv12 = (cgc_size_t)(KEY_SIZE); }
    {int tlv2; tlv2 = (int)(KEY_SIZE); }
    {char * tlv18; tlv18 = (char *)(KEY_SIZE); }
    {char * tlv17; tlv17 = (char *)(KEY_SIZE); }
    {int tlv3; tlv3 = (int)(KEY_SIZE); }
    {char * tlv22; tlv22 = (char *)(KEY_SIZE); }
    {char * tlv21; tlv21 = (char *)(KEY_SIZE); }
    {int tlv4; tlv4 = (int)(KEY_SIZE); }
    {char * tlv26; tlv26 = (char *)(KEY_SIZE); }
    {char * tlv25; tlv25 = (char *)(KEY_SIZE); }
    {int tlv5; tlv5 = (int)(KEY_SIZE); }
    {char * tlv30; tlv30 = (char *)(KEY_SIZE); }
    {char * tlv29; tlv29 = (char *)(KEY_SIZE); }
    {char * tlv34; tlv34 = (char *)(KEY_SIZE); }
    {char * tlv33; tlv33 = (char *)(KEY_SIZE); }
}
void fix_ingred_service_3_3(){
fix_ingred_service_3_3_9();
fix_ingred_service_3_3_10();
fix_ingred_service_3_3_11();
fix_ingred_service_3_3_12();
}
void fix_ingred_service_3_4_0(){
char key [ KEY_SIZE ];
    bzero(&key,( KEY_SIZE *sizeof(char) ) );
char start_ref;
    bzero(&start_ref,1*sizeof(char));
char * start = &start_ref;
int count;
    bzero(&count,sizeof(int));
    {void * tlv8; tlv8 = (void *)(key); }
    {int tlv7; tlv7 = (int)(key); }
    {cgc_size_t tlv6; tlv6 = (cgc_size_t)(key); }
    {void * tlv11; tlv11 = (void *)(key); }
    {void * tlv10; tlv10 = (void *)(key); }
    {cgc_size_t tlv9; tlv9 = (cgc_size_t)(key); }
    {void * tlv14; tlv14 = (void *)(key); }
    {int tlv13; tlv13 = (int)(key); }
    {cgc_size_t tlv12; tlv12 = (cgc_size_t)(key); }
    {int tlv2; tlv2 = (int)(key); }
    {char * tlv18; tlv18 = (char *)(key); }
    {char * tlv17; tlv17 = (char *)(key); }
    {int tlv3; tlv3 = (int)(key); }
    {char * tlv22; tlv22 = (char *)(key); }
    {char * tlv21; tlv21 = (char *)(key); }
    {int tlv4; tlv4 = (int)(key); }
    {char * tlv26; tlv26 = (char *)(key); }
    {char * tlv25; tlv25 = (char *)(key); }
    {int tlv5; tlv5 = (int)(key); }
    {char * tlv30; tlv30 = (char *)(key); }
    {char * tlv29; tlv29 = (char *)(key); }
    {char * tlv34; tlv34 = (char *)(key); }
    {char * tlv33; tlv33 = (char *)(key); }
}
void fix_ingred_service_3_4_1(){
char key [ KEY_SIZE ];
    bzero(&key,( KEY_SIZE *sizeof(char) ) );
char start_ref;
    bzero(&start_ref,1*sizeof(char));
char * start = &start_ref;
int count;
    bzero(&count,sizeof(int));
    {void * tlv8; tlv8 = (void *)(start); }
    {int tlv7; tlv7 = (int)(start); }
    {cgc_size_t tlv6; tlv6 = (cgc_size_t)(start); }
    {void * tlv11; tlv11 = (void *)(start); }
    {void * tlv10; tlv10 = (void *)(start); }
    {cgc_size_t tlv9; tlv9 = (cgc_size_t)(start); }
    {void * tlv14; tlv14 = (void *)(start); }
    {int tlv13; tlv13 = (int)(start); }
    {cgc_size_t tlv12; tlv12 = (cgc_size_t)(start); }
    {int tlv2; tlv2 = (int)(start); }
    {char * tlv18; tlv18 = (char *)(start); }
    {char * tlv17; tlv17 = (char *)(start); }
    {int tlv3; tlv3 = (int)(start); }
    {char * tlv22; tlv22 = (char *)(start); }
    {char * tlv21; tlv21 = (char *)(start); }
    {int tlv4; tlv4 = (int)(start); }
    {char * tlv26; tlv26 = (char *)(start); }
    {char * tlv25; tlv25 = (char *)(start); }
    {int tlv5; tlv5 = (int)(start); }
    {char * tlv30; tlv30 = (char *)(start); }
    {char * tlv29; tlv29 = (char *)(start); }
    {char * tlv34; tlv34 = (char *)(start); }
    {char * tlv33; tlv33 = (char *)(start); }
}
void fix_ingred_service_3_4_2(){
char key [ KEY_SIZE ];
    bzero(&key,( KEY_SIZE *sizeof(char) ) );
char start_ref;
    bzero(&start_ref,1*sizeof(char));
char * start = &start_ref;
int count;
    bzero(&count,sizeof(int));
    {void * tlv8; tlv8 = (void *)(count); }
    {int tlv7; tlv7 = (int)(count); }
    {cgc_size_t tlv6; tlv6 = (cgc_size_t)(count); }
    {void * tlv11; tlv11 = (void *)(count); }
    {void * tlv10; tlv10 = (void *)(count); }
    {cgc_size_t tlv9; tlv9 = (cgc_size_t)(count); }
    {void * tlv14; tlv14 = (void *)(count); }
    {int tlv13; tlv13 = (int)(count); }
    {cgc_size_t tlv12; tlv12 = (cgc_size_t)(count); }
    {int tlv2; tlv2 = (int)(count); }
    {char * tlv18; tlv18 = (char *)(count); }
    {char * tlv17; tlv17 = (char *)(count); }
    {int tlv3; tlv3 = (int)(count); }
    {char * tlv22; tlv22 = (char *)(count); }
    {char * tlv21; tlv21 = (char *)(count); }
    {int tlv4; tlv4 = (int)(count); }
    {char * tlv26; tlv26 = (char *)(count); }
    {char * tlv25; tlv25 = (char *)(count); }
    {int tlv5; tlv5 = (int)(count); }
    {char * tlv30; tlv30 = (char *)(count); }
    {char * tlv29; tlv29 = (char *)(count); }
    {char * tlv34; tlv34 = (char *)(count); }
    {char * tlv33; tlv33 = (char *)(count); }
}
void fix_ingred_service_3_4(){
fix_ingred_service_3_4_0();
fix_ingred_service_3_4_1();
fix_ingred_service_3_4_2();
}
void fix_ingred_service_3_6_9(){
int tlv1;
    bzero(&tlv1,sizeof(int));
    {void * tlv8; tlv8 = (void *)(tlv1); }
    {int tlv7; tlv7 = (int)(tlv1); }
    {cgc_size_t tlv6; tlv6 = (cgc_size_t)(tlv1); }
    {void * tlv11; tlv11 = (void *)(tlv1); }
    {void * tlv10; tlv10 = (void *)(tlv1); }
    {cgc_size_t tlv9; tlv9 = (cgc_size_t)(tlv1); }
    {void * tlv14; tlv14 = (void *)(tlv1); }
    {int tlv13; tlv13 = (int)(tlv1); }
    {cgc_size_t tlv12; tlv12 = (cgc_size_t)(tlv1); }
    {int tlv2; tlv2 = (int)(tlv1); }
    {char * tlv18; tlv18 = (char *)(tlv1); }
    {char * tlv17; tlv17 = (char *)(tlv1); }
    {int tlv3; tlv3 = (int)(tlv1); }
    {char * tlv22; tlv22 = (char *)(tlv1); }
    {char * tlv21; tlv21 = (char *)(tlv1); }
    {int tlv4; tlv4 = (int)(tlv1); }
    {char * tlv26; tlv26 = (char *)(tlv1); }
    {char * tlv25; tlv25 = (char *)(tlv1); }
    {int tlv5; tlv5 = (int)(tlv1); }
    {char * tlv30; tlv30 = (char *)(tlv1); }
    {char * tlv29; tlv29 = (char *)(tlv1); }
    {char * tlv34; tlv34 = (char *)(tlv1); }
    {char * tlv33; tlv33 = (char *)(tlv1); }
}
void fix_ingred_service_3_6(){
fix_ingred_service_3_6_9();
}
void fix_ingred_service_3_7_0(){
Song song_ref;
    bzero(&song_ref,1*sizeof(Song));
Song * song = &song_ref;
char end_ref;
    bzero(&end_ref,1*sizeof(char));
char * end = &end_ref;
    {void * tlv8; tlv8 = (void *)(++ end); }
    {int tlv7; tlv7 = (int)(++ end); }
    {cgc_size_t tlv6; tlv6 = (cgc_size_t)(++ end); }
    {void * tlv11; tlv11 = (void *)(++ end); }
    {void * tlv10; tlv10 = (void *)(++ end); }
    {cgc_size_t tlv9; tlv9 = (cgc_size_t)(++ end); }
    {void * tlv14; tlv14 = (void *)(++ end); }
    {int tlv13; tlv13 = (int)(++ end); }
    {cgc_size_t tlv12; tlv12 = (cgc_size_t)(++ end); }
    {int tlv2; tlv2 = (int)(++ end); }
    {char * tlv18; tlv18 = (char *)(++ end); }
    {char * tlv17; tlv17 = (char *)(++ end); }
    {int tlv3; tlv3 = (int)(++ end); }
    {char * tlv22; tlv22 = (char *)(++ end); }
    {char * tlv21; tlv21 = (char *)(++ end); }
    {int tlv4; tlv4 = (int)(++ end); }
    {char * tlv26; tlv26 = (char *)(++ end); }
    {char * tlv25; tlv25 = (char *)(++ end); }
    {int tlv5; tlv5 = (int)(++ end); }
    {char * tlv30; tlv30 = (char *)(++ end); }
    {char * tlv29; tlv29 = (char *)(++ end); }
    {char * tlv34; tlv34 = (char *)(++ end); }
    {char * tlv33; tlv33 = (char *)(++ end); }
}
void fix_ingred_service_3_7_1(){
Song song_ref;
    bzero(&song_ref,1*sizeof(Song));
Song * song = &song_ref;
char end_ref;
    bzero(&end_ref,1*sizeof(char));
char * end = &end_ref;
    {char * start; start = (char *)(song -> id); }
    {char * end; end = (char *)(song -> id); }
    {char key [ KEY_SIZE ]; key [ ( KEY_SIZE )-1 ] = (char)(song -> id); }
    {int count; count = (int)(song -> id); }
    {int i; i = (int)(song -> id); }
    {char * delim; delim = (char *)(song -> id); }
    {int ret; ret = (int)(song -> id); }
    {void * tlv8; tlv8 = (void *)(song -> id); }
    {int tlv7; tlv7 = (int)(song -> id); }
    {cgc_size_t tlv6; tlv6 = (cgc_size_t)(song -> id); }
    {int tlv1; tlv1 = (int)(song -> id); }
    {void * tlv11; tlv11 = (void *)(song -> id); }
    {void * tlv10; tlv10 = (void *)(song -> id); }
    {cgc_size_t tlv9; tlv9 = (cgc_size_t)(song -> id); }
    {void * tlv14; tlv14 = (void *)(song -> id); }
    {int tlv13; tlv13 = (int)(song -> id); }
    {cgc_size_t tlv12; tlv12 = (cgc_size_t)(song -> id); }
    {int tlv2; tlv2 = (int)(song -> id); }
    {char * tlv18; tlv18 = (char *)(song -> id); }
    {char * tlv17; tlv17 = (char *)(song -> id); }
    {int tlv3; tlv3 = (int)(song -> id); }
    {char * tlv22; tlv22 = (char *)(song -> id); }
    {char * tlv21; tlv21 = (char *)(song -> id); }
    {int tlv4; tlv4 = (int)(song -> id); }
    {char * tlv26; tlv26 = (char *)(song -> id); }
    {char * tlv25; tlv25 = (char *)(song -> id); }
    {int tlv5; tlv5 = (int)(song -> id); }
    {char * tlv30; tlv30 = (char *)(song -> id); }
    {char * tlv29; tlv29 = (char *)(song -> id); }
    {char * tlv34; tlv34 = (char *)(song -> id); }
    {char * tlv33; tlv33 = (char *)(song -> id); }
}
void fix_ingred_service_3_7(){
fix_ingred_service_3_7_0();
fix_ingred_service_3_7_1();
}
void fix_ingred_service_3_10_9(){
int tlv2;
    bzero(&tlv2,sizeof(int));
    {char * start; start = (char *)(tlv2); }
    {char * end; end = (char *)(tlv2); }
    {char key [ KEY_SIZE ]; key [ ( KEY_SIZE )-1 ] = (char)(tlv2); }
    {int count; count = (int)(tlv2); }
    {int i; i = (int)(tlv2); }
    {char * delim; delim = (char *)(tlv2); }
    {int ret; ret = (int)(tlv2); }
    {void * tlv8; tlv8 = (void *)(tlv2); }
    {int tlv7; tlv7 = (int)(tlv2); }
    {cgc_size_t tlv6; tlv6 = (cgc_size_t)(tlv2); }
    {int tlv1; tlv1 = (int)(tlv2); }
    {void * tlv11; tlv11 = (void *)(tlv2); }
    {void * tlv10; tlv10 = (void *)(tlv2); }
    {cgc_size_t tlv9; tlv9 = (cgc_size_t)(tlv2); }
    {void * tlv14; tlv14 = (void *)(tlv2); }
    {int tlv13; tlv13 = (int)(tlv2); }
    {cgc_size_t tlv12; tlv12 = (cgc_size_t)(tlv2); }
    {char * tlv18; tlv18 = (char *)(tlv2); }
    {char * tlv17; tlv17 = (char *)(tlv2); }
    {int tlv3; tlv3 = (int)(tlv2); }
    {char * tlv22; tlv22 = (char *)(tlv2); }
    {char * tlv21; tlv21 = (char *)(tlv2); }
    {int tlv4; tlv4 = (int)(tlv2); }
    {char * tlv26; tlv26 = (char *)(tlv2); }
    {char * tlv25; tlv25 = (char *)(tlv2); }
    {int tlv5; tlv5 = (int)(tlv2); }
    {char * tlv30; tlv30 = (char *)(tlv2); }
    {char * tlv29; tlv29 = (char *)(tlv2); }
    {char * tlv34; tlv34 = (char *)(tlv2); }
    {char * tlv33; tlv33 = (char *)(tlv2); }
}
void fix_ingred_service_3_10(){
fix_ingred_service_3_10_9();
}
void fix_ingred_service_3_11_1(){
Song song_ref;
    bzero(&song_ref,1*sizeof(Song));
Song * song = &song_ref;
    {char * start; start = (char *)(song -> price); }
    {char * end; end = (char *)(song -> price); }
    {char key [ KEY_SIZE ]; key [ ( KEY_SIZE )-1 ] = (char)(song -> price); }
    {int count; count = (int)(song -> price); }
    {int i; i = (int)(song -> price); }
    {char * delim; delim = (char *)(song -> price); }
    {int ret; ret = (int)(song -> price); }
    {void * tlv8; tlv8 = (void *)(song -> price); }
    {int tlv7; tlv7 = (int)(song -> price); }
    {cgc_size_t tlv6; tlv6 = (cgc_size_t)(song -> price); }
    {int tlv1; tlv1 = (int)(song -> price); }
    {void * tlv11; tlv11 = (void *)(song -> price); }
    {void * tlv10; tlv10 = (void *)(song -> price); }
    {cgc_size_t tlv9; tlv9 = (cgc_size_t)(song -> price); }
    {void * tlv14; tlv14 = (void *)(song -> price); }
    {int tlv13; tlv13 = (int)(song -> price); }
    {cgc_size_t tlv12; tlv12 = (cgc_size_t)(song -> price); }
    {int tlv2; tlv2 = (int)(song -> price); }
    {char * tlv18; tlv18 = (char *)(song -> price); }
    {char * tlv17; tlv17 = (char *)(song -> price); }
    {int tlv3; tlv3 = (int)(song -> price); }
    {char * tlv22; tlv22 = (char *)(song -> price); }
    {char * tlv21; tlv21 = (char *)(song -> price); }
    {int tlv4; tlv4 = (int)(song -> price); }
    {char * tlv26; tlv26 = (char *)(song -> price); }
    {char * tlv25; tlv25 = (char *)(song -> price); }
    {int tlv5; tlv5 = (int)(song -> price); }
    {char * tlv30; tlv30 = (char *)(song -> price); }
    {char * tlv29; tlv29 = (char *)(song -> price); }
    {char * tlv34; tlv34 = (char *)(song -> price); }
    {char * tlv33; tlv33 = (char *)(song -> price); }
}
void fix_ingred_service_3_11(){
fix_ingred_service_3_11_1();
}
void fix_ingred_service_3_14_9(){
int tlv3;
    bzero(&tlv3,sizeof(int));
    {char * start; start = (char *)(tlv3); }
    {char * end; end = (char *)(tlv3); }
    {char key [ KEY_SIZE ]; key [ ( KEY_SIZE )-1 ] = (char)(tlv3); }
    {int count; count = (int)(tlv3); }
    {int i; i = (int)(tlv3); }
    {char * delim; delim = (char *)(tlv3); }
    {int ret; ret = (int)(tlv3); }
    {void * tlv8; tlv8 = (void *)(tlv3); }
    {int tlv7; tlv7 = (int)(tlv3); }
    {cgc_size_t tlv6; tlv6 = (cgc_size_t)(tlv3); }
    {int tlv1; tlv1 = (int)(tlv3); }
    {void * tlv11; tlv11 = (void *)(tlv3); }
    {void * tlv10; tlv10 = (void *)(tlv3); }
    {cgc_size_t tlv9; tlv9 = (cgc_size_t)(tlv3); }
    {void * tlv14; tlv14 = (void *)(tlv3); }
    {int tlv13; tlv13 = (int)(tlv3); }
    {cgc_size_t tlv12; tlv12 = (cgc_size_t)(tlv3); }
    {int tlv2; tlv2 = (int)(tlv3); }
    {char * tlv18; tlv18 = (char *)(tlv3); }
    {char * tlv17; tlv17 = (char *)(tlv3); }
    {char * tlv22; tlv22 = (char *)(tlv3); }
    {char * tlv21; tlv21 = (char *)(tlv3); }
    {int tlv4; tlv4 = (int)(tlv3); }
    {char * tlv26; tlv26 = (char *)(tlv3); }
    {char * tlv25; tlv25 = (char *)(tlv3); }
    {int tlv5; tlv5 = (int)(tlv3); }
    {char * tlv30; tlv30 = (char *)(tlv3); }
    {char * tlv29; tlv29 = (char *)(tlv3); }
    {char * tlv34; tlv34 = (char *)(tlv3); }
    {char * tlv33; tlv33 = (char *)(tlv3); }
}
void fix_ingred_service_3_14(){
fix_ingred_service_3_14_9();
}
void fix_ingred_service_3_15_1(){
Song song_ref;
    bzero(&song_ref,1*sizeof(Song));
Song * song = &song_ref;
    {char * start; start = (char *)(song -> artist); }
    {char * end; end = (char *)(song -> artist); }
    {char key [ KEY_SIZE ]; key [ ( KEY_SIZE )-1 ] = (char)(song -> artist); }
    {int count; count = (int)(song -> artist); }
    {int i; i = (int)(song -> artist); }
    {char * delim; delim = (char *)(song -> artist); }
    {int ret; ret = (int)(song -> artist); }
    {void * tlv8; tlv8 = (void *)(song -> artist); }
    {int tlv7; tlv7 = (int)(song -> artist); }
    {cgc_size_t tlv6; tlv6 = (cgc_size_t)(song -> artist); }
    {int tlv1; tlv1 = (int)(song -> artist); }
    {void * tlv11; tlv11 = (void *)(song -> artist); }
    {void * tlv10; tlv10 = (void *)(song -> artist); }
    {cgc_size_t tlv9; tlv9 = (cgc_size_t)(song -> artist); }
    {void * tlv14; tlv14 = (void *)(song -> artist); }
    {int tlv13; tlv13 = (int)(song -> artist); }
    {cgc_size_t tlv12; tlv12 = (cgc_size_t)(song -> artist); }
    {int tlv2; tlv2 = (int)(song -> artist); }
    {char * tlv18; tlv18 = (char *)(song -> artist); }
    {char * tlv17; tlv17 = (char *)(song -> artist); }
    {int tlv3; tlv3 = (int)(song -> artist); }
    {char * tlv22; tlv22 = (char *)(song -> artist); }
    {char * tlv21; tlv21 = (char *)(song -> artist); }
    {int tlv4; tlv4 = (int)(song -> artist); }
    {char * tlv26; tlv26 = (char *)(song -> artist); }
    {char * tlv25; tlv25 = (char *)(song -> artist); }
    {int tlv5; tlv5 = (int)(song -> artist); }
    {char * tlv30; tlv30 = (char *)(song -> artist); }
    {char * tlv29; tlv29 = (char *)(song -> artist); }
    {char * tlv34; tlv34 = (char *)(song -> artist); }
    {char * tlv33; tlv33 = (char *)(song -> artist); }
}
void fix_ingred_service_3_15(){
fix_ingred_service_3_15_1();
}
void fix_ingred_service_3_18_9(){
int tlv4;
    bzero(&tlv4,sizeof(int));
    {char * start; start = (char *)(tlv4); }
    {char * end; end = (char *)(tlv4); }
    {char key [ KEY_SIZE ]; key [ ( KEY_SIZE )-1 ] = (char)(tlv4); }
    {int count; count = (int)(tlv4); }
    {int i; i = (int)(tlv4); }
    {char * delim; delim = (char *)(tlv4); }
    {int ret; ret = (int)(tlv4); }
    {void * tlv8; tlv8 = (void *)(tlv4); }
    {int tlv7; tlv7 = (int)(tlv4); }
    {cgc_size_t tlv6; tlv6 = (cgc_size_t)(tlv4); }
    {int tlv1; tlv1 = (int)(tlv4); }
    {void * tlv11; tlv11 = (void *)(tlv4); }
    {void * tlv10; tlv10 = (void *)(tlv4); }
    {cgc_size_t tlv9; tlv9 = (cgc_size_t)(tlv4); }
    {void * tlv14; tlv14 = (void *)(tlv4); }
    {int tlv13; tlv13 = (int)(tlv4); }
    {cgc_size_t tlv12; tlv12 = (cgc_size_t)(tlv4); }
    {int tlv2; tlv2 = (int)(tlv4); }
    {char * tlv18; tlv18 = (char *)(tlv4); }
    {char * tlv17; tlv17 = (char *)(tlv4); }
    {int tlv3; tlv3 = (int)(tlv4); }
    {char * tlv22; tlv22 = (char *)(tlv4); }
    {char * tlv21; tlv21 = (char *)(tlv4); }
    {char * tlv26; tlv26 = (char *)(tlv4); }
    {char * tlv25; tlv25 = (char *)(tlv4); }
    {int tlv5; tlv5 = (int)(tlv4); }
    {char * tlv30; tlv30 = (char *)(tlv4); }
    {char * tlv29; tlv29 = (char *)(tlv4); }
    {char * tlv34; tlv34 = (char *)(tlv4); }
    {char * tlv33; tlv33 = (char *)(tlv4); }
}
void fix_ingred_service_3_18(){
fix_ingred_service_3_18_9();
}
void fix_ingred_service_3_19_1(){
Song song_ref;
    bzero(&song_ref,1*sizeof(Song));
Song * song = &song_ref;
    {char * start; start = (char *)(song -> album); }
    {char * end; end = (char *)(song -> album); }
    {char key [ KEY_SIZE ]; key [ ( KEY_SIZE )-1 ] = (char)(song -> album); }
    {int count; count = (int)(song -> album); }
    {int i; i = (int)(song -> album); }
    {char * delim; delim = (char *)(song -> album); }
    {int ret; ret = (int)(song -> album); }
    {void * tlv8; tlv8 = (void *)(song -> album); }
    {int tlv7; tlv7 = (int)(song -> album); }
    {cgc_size_t tlv6; tlv6 = (cgc_size_t)(song -> album); }
    {int tlv1; tlv1 = (int)(song -> album); }
    {void * tlv11; tlv11 = (void *)(song -> album); }
    {void * tlv10; tlv10 = (void *)(song -> album); }
    {cgc_size_t tlv9; tlv9 = (cgc_size_t)(song -> album); }
    {void * tlv14; tlv14 = (void *)(song -> album); }
    {int tlv13; tlv13 = (int)(song -> album); }
    {cgc_size_t tlv12; tlv12 = (cgc_size_t)(song -> album); }
    {int tlv2; tlv2 = (int)(song -> album); }
    {char * tlv18; tlv18 = (char *)(song -> album); }
    {char * tlv17; tlv17 = (char *)(song -> album); }
    {int tlv3; tlv3 = (int)(song -> album); }
    {char * tlv22; tlv22 = (char *)(song -> album); }
    {char * tlv21; tlv21 = (char *)(song -> album); }
    {int tlv4; tlv4 = (int)(song -> album); }
    {char * tlv26; tlv26 = (char *)(song -> album); }
    {char * tlv25; tlv25 = (char *)(song -> album); }
    {int tlv5; tlv5 = (int)(song -> album); }
    {char * tlv30; tlv30 = (char *)(song -> album); }
    {char * tlv29; tlv29 = (char *)(song -> album); }
    {char * tlv34; tlv34 = (char *)(song -> album); }
    {char * tlv33; tlv33 = (char *)(song -> album); }
}
void fix_ingred_service_3_19(){
fix_ingred_service_3_19_1();
}
void fix_ingred_service_3_22_9(){
int tlv5;
    bzero(&tlv5,sizeof(int));
    {char * start; start = (char *)(tlv5); }
    {char * end; end = (char *)(tlv5); }
    {char key [ KEY_SIZE ]; key [ ( KEY_SIZE )-1 ] = (char)(tlv5); }
    {int count; count = (int)(tlv5); }
    {int i; i = (int)(tlv5); }
    {char * delim; delim = (char *)(tlv5); }
    {int ret; ret = (int)(tlv5); }
    {void * tlv8; tlv8 = (void *)(tlv5); }
    {int tlv7; tlv7 = (int)(tlv5); }
    {cgc_size_t tlv6; tlv6 = (cgc_size_t)(tlv5); }
    {int tlv1; tlv1 = (int)(tlv5); }
    {void * tlv11; tlv11 = (void *)(tlv5); }
    {void * tlv10; tlv10 = (void *)(tlv5); }
    {cgc_size_t tlv9; tlv9 = (cgc_size_t)(tlv5); }
    {void * tlv14; tlv14 = (void *)(tlv5); }
    {int tlv13; tlv13 = (int)(tlv5); }
    {cgc_size_t tlv12; tlv12 = (cgc_size_t)(tlv5); }
    {int tlv2; tlv2 = (int)(tlv5); }
    {char * tlv18; tlv18 = (char *)(tlv5); }
    {char * tlv17; tlv17 = (char *)(tlv5); }
    {int tlv3; tlv3 = (int)(tlv5); }
    {char * tlv22; tlv22 = (char *)(tlv5); }
    {char * tlv21; tlv21 = (char *)(tlv5); }
    {int tlv4; tlv4 = (int)(tlv5); }
    {char * tlv26; tlv26 = (char *)(tlv5); }
    {char * tlv25; tlv25 = (char *)(tlv5); }
    {char * tlv30; tlv30 = (char *)(tlv5); }
    {char * tlv29; tlv29 = (char *)(tlv5); }
    {char * tlv34; tlv34 = (char *)(tlv5); }
    {char * tlv33; tlv33 = (char *)(tlv5); }
}
void fix_ingred_service_3_22(){
fix_ingred_service_3_22_9();
}
void fix_ingred_service_3_23_1(){
Song song_ref;
    bzero(&song_ref,1*sizeof(Song));
Song * song = &song_ref;
    {char * start; start = (char *)(song -> song); }
    {char * end; end = (char *)(song -> song); }
    {char key [ KEY_SIZE ]; key [ ( KEY_SIZE )-1 ] = (char)(song -> song); }
    {int count; count = (int)(song -> song); }
    {int i; i = (int)(song -> song); }
    {char * delim; delim = (char *)(song -> song); }
    {int ret; ret = (int)(song -> song); }
    {void * tlv8; tlv8 = (void *)(song -> song); }
    {int tlv7; tlv7 = (int)(song -> song); }
    {cgc_size_t tlv6; tlv6 = (cgc_size_t)(song -> song); }
    {int tlv1; tlv1 = (int)(song -> song); }
    {void * tlv11; tlv11 = (void *)(song -> song); }
    {void * tlv10; tlv10 = (void *)(song -> song); }
    {cgc_size_t tlv9; tlv9 = (cgc_size_t)(song -> song); }
    {void * tlv14; tlv14 = (void *)(song -> song); }
    {int tlv13; tlv13 = (int)(song -> song); }
    {cgc_size_t tlv12; tlv12 = (cgc_size_t)(song -> song); }
    {int tlv2; tlv2 = (int)(song -> song); }
    {char * tlv18; tlv18 = (char *)(song -> song); }
    {char * tlv17; tlv17 = (char *)(song -> song); }
    {int tlv3; tlv3 = (int)(song -> song); }
    {char * tlv22; tlv22 = (char *)(song -> song); }
    {char * tlv21; tlv21 = (char *)(song -> song); }
    {int tlv4; tlv4 = (int)(song -> song); }
    {char * tlv26; tlv26 = (char *)(song -> song); }
    {char * tlv25; tlv25 = (char *)(song -> song); }
    {int tlv5; tlv5 = (int)(song -> song); }
    {char * tlv30; tlv30 = (char *)(song -> song); }
    {char * tlv29; tlv29 = (char *)(song -> song); }
    {char * tlv34; tlv34 = (char *)(song -> song); }
    {char * tlv33; tlv33 = (char *)(song -> song); }
}
void fix_ingred_service_3_23(){
fix_ingred_service_3_23_1();
}
void fix_ingred_service_3_25_2(){
    {char * start; start = (char *)(KEY_SIZE); }
    {char * end; end = (char *)(KEY_SIZE); }
    {char key [ KEY_SIZE ]; key [ ( KEY_SIZE )-1 ] = (char)(KEY_SIZE); }
    {int count; count = (int)(KEY_SIZE); }
    {int i; i = (int)(KEY_SIZE); }
    {char * delim; delim = (char *)(KEY_SIZE); }
    {int ret; ret = (int)(KEY_SIZE); }
    {void * tlv8; tlv8 = (void *)(KEY_SIZE); }
    {int tlv7; tlv7 = (int)(KEY_SIZE); }
    {cgc_size_t tlv6; tlv6 = (cgc_size_t)(KEY_SIZE); }
    {int tlv1; tlv1 = (int)(KEY_SIZE); }
    {void * tlv11; tlv11 = (void *)(KEY_SIZE); }
    {void * tlv10; tlv10 = (void *)(KEY_SIZE); }
    {cgc_size_t tlv9; tlv9 = (cgc_size_t)(KEY_SIZE); }
    {void * tlv14; tlv14 = (void *)(KEY_SIZE); }
    {int tlv13; tlv13 = (int)(KEY_SIZE); }
    {cgc_size_t tlv12; tlv12 = (cgc_size_t)(KEY_SIZE); }
    {int tlv2; tlv2 = (int)(KEY_SIZE); }
    {char * tlv18; tlv18 = (char *)(KEY_SIZE); }
    {char * tlv17; tlv17 = (char *)(KEY_SIZE); }
    {int tlv3; tlv3 = (int)(KEY_SIZE); }
    {char * tlv22; tlv22 = (char *)(KEY_SIZE); }
    {char * tlv21; tlv21 = (char *)(KEY_SIZE); }
    {int tlv4; tlv4 = (int)(KEY_SIZE); }
    {char * tlv26; tlv26 = (char *)(KEY_SIZE); }
    {char * tlv25; tlv25 = (char *)(KEY_SIZE); }
    {int tlv5; tlv5 = (int)(KEY_SIZE); }
    {char * tlv30; tlv30 = (char *)(KEY_SIZE); }
    {char * tlv29; tlv29 = (char *)(KEY_SIZE); }
    {char * tlv34; tlv34 = (char *)(KEY_SIZE); }
    {char * tlv33; tlv33 = (char *)(KEY_SIZE); }
}
void fix_ingred_service_3_25(){
fix_ingred_service_3_25_2();
}
void fix_ingred_service_3(){
fix_ingred_service_3_0();
fix_ingred_service_3_1();
fix_ingred_service_3_2();
fix_ingred_service_3_3();
fix_ingred_service_3_4();
fix_ingred_service_3_6();
fix_ingred_service_3_7();
fix_ingred_service_3_10();
fix_ingred_service_3_11();
fix_ingred_service_3_14();
fix_ingred_service_3_15();
fix_ingred_service_3_18();
fix_ingred_service_3_19();
fix_ingred_service_3_22();
fix_ingred_service_3_23();
fix_ingred_service_3_25();
}
void fix_ingred_service_4_0_0(){
    {char buf [ 1024 ]; buf [ ( 1024 )-1 ] = (char)(0); }
    {int bytes_read; bytes_read = (int)(0); }
    {char * tlv2; tlv2 = (char *)(0); }
    {char * tlv4; tlv4 = (char *)(0); }
    {unsigned int tlv5; tlv5 = (unsigned int)(0); }
}
void fix_ingred_service_4_0(){
fix_ingred_service_4_0_0();
}
void fix_ingred_service_4_1_0(){
int socket;
    bzero(&socket,sizeof(int));
char buf [ 1024 ];
    bzero(&buf,( 1024 *sizeof(char) ) );
    {char buf [ 1024 ]; buf [ ( 1024 )-1 ] = (char)(socket); }
    {int bytes_read; bytes_read = (int)(socket); }
    {int balance; balance = (int)(socket); }
    {int tlv3; tlv3 = (int)(socket); }
    {char * tlv2; tlv2 = (char *)(socket); }
    {cgc_size_t tlv1; tlv1 = (cgc_size_t)(socket); }
    {char * tlv4; tlv4 = (char *)(socket); }
    {unsigned int tlv5; tlv5 = (unsigned int)(socket); }
}
void fix_ingred_service_4_1_1(){
int socket;
    bzero(&socket,sizeof(int));
char buf [ 1024 ];
    bzero(&buf,( 1024 *sizeof(char) ) );
    {char buf [ 1024 ]; buf [ ( 1024 )-1 ] = (char)(buf); }
    {int bytes_read; bytes_read = (int)(buf); }
    {int balance; balance = (int)(buf); }
    {int tlv3; tlv3 = (int)(buf); }
    {char * tlv2; tlv2 = (char *)(buf); }
    {cgc_size_t tlv1; tlv1 = (cgc_size_t)(buf); }
    {char * tlv4; tlv4 = (char *)(buf); }
    {unsigned int tlv5; tlv5 = (unsigned int)(buf); }
}
void fix_ingred_service_4_1_2(){
int socket;
    bzero(&socket,sizeof(int));
char buf [ 1024 ];
    bzero(&buf,( 1024 *sizeof(char) ) );
    {char buf [ 1024 ]; buf [ ( 1024 )-1 ] = (char)(sizeof ( buf ) - 1); }
    {int bytes_read; bytes_read = (int)(sizeof ( buf ) - 1); }
    {int balance; balance = (int)(sizeof ( buf ) - 1); }
    {int tlv3; tlv3 = (int)(sizeof ( buf ) - 1); }
    {char * tlv2; tlv2 = (char *)(sizeof ( buf ) - 1); }
    {cgc_size_t tlv1; tlv1 = (cgc_size_t)(sizeof ( buf ) - 1); }
    {char * tlv4; tlv4 = (char *)(sizeof ( buf ) - 1); }
    {unsigned int tlv5; tlv5 = (unsigned int)(sizeof ( buf ) - 1); }
}
void fix_ingred_service_4_1(){
fix_ingred_service_4_1_0();
fix_ingred_service_4_1_1();
fix_ingred_service_4_1_2();
}
void fix_ingred_service_4_2_2(){
int bytes_read;
    bzero(&bytes_read,sizeof(int));
    {char buf [ 1024 ]; buf [ ( 1024 )-1 ] = (char)(bytes_read); }
    {int balance; balance = (int)(bytes_read); }
    {int tlv3; tlv3 = (int)(bytes_read); }
    {char * tlv2; tlv2 = (char *)(bytes_read); }
    {cgc_size_t tlv1; tlv1 = (cgc_size_t)(bytes_read); }
    {char * tlv4; tlv4 = (char *)(bytes_read); }
    {unsigned int tlv5; tlv5 = (unsigned int)(bytes_read); }
}
void fix_ingred_service_4_2(){
fix_ingred_service_4_2_2();
}
void fix_ingred_service_4_3_0(){
    {char buf [ 1024 ]; buf [ ( 1024 )-1 ] = (char)(2); }
    {int bytes_read; bytes_read = (int)(2); }
    {int balance; balance = (int)(2); }
    {int tlv3; tlv3 = (int)(2); }
    {char * tlv2; tlv2 = (char *)(2); }
    {cgc_size_t tlv1; tlv1 = (cgc_size_t)(2); }
    {char * tlv4; tlv4 = (char *)(2); }
    {unsigned int tlv5; tlv5 = (unsigned int)(2); }
}
void fix_ingred_service_4_3(){
fix_ingred_service_4_3_0();
}
void fix_ingred_service_4(){
fix_ingred_service_4_0();
fix_ingred_service_4_1();
fix_ingred_service_4_2();
fix_ingred_service_4_3();
}
void fix_ingred_service_5_1_0(){
int socket;
    bzero(&socket,sizeof(int));
char buf [ 1024 ];
    bzero(&buf,( 1024 *sizeof(char) ) );
    {int num_results; num_results = (int)(socket); }
}
void fix_ingred_service_5_1_1(){
int socket;
    bzero(&socket,sizeof(int));
char buf [ 1024 ];
    bzero(&buf,( 1024 *sizeof(char) ) );
    {int num_results; num_results = (int)(buf); }
}
void fix_ingred_service_5_1_2(){
int socket;
    bzero(&socket,sizeof(int));
char buf [ 1024 ];
    bzero(&buf,( 1024 *sizeof(char) ) );
    {int num_results; num_results = (int)(sizeof ( buf ) - 1); }
}
void fix_ingred_service_5_1(){
fix_ingred_service_5_1_0();
fix_ingred_service_5_1_1();
fix_ingred_service_5_1_2();
}
void fix_ingred_service_5_2_2(){
int bytes_read;
    bzero(&bytes_read,sizeof(int));
    {int num_results; num_results = (int)(bytes_read); }
}
void fix_ingred_service_5_2(){
fix_ingred_service_5_2_2();
}
void fix_ingred_service_5_3_0(){
    {int num_results; num_results = (int)(2); }
}
void fix_ingred_service_5_3(){
fix_ingred_service_5_3_0();
}
void fix_ingred_service_5_6_2(){
int num_results;
    bzero(&num_results,sizeof(int));
    {char buf [ 1024 ]; buf [ ( 1024 )-1 ] = (char)(num_results); }
    {int bytes_read; bytes_read = (int)(num_results); }
    {int tlv3; tlv3 = (int)(num_results); }
    {char * tlv2; tlv2 = (char *)(num_results); }
    {cgc_size_t tlv1; tlv1 = (cgc_size_t)(num_results); }
    {char * tlv4; tlv4 = (char *)(num_results); }
    {unsigned int tlv5; tlv5 = (unsigned int)(num_results); }
}
void fix_ingred_service_5_6(){
fix_ingred_service_5_6_2();
}
void fix_ingred_service_5(){
fix_ingred_service_5_1();
fix_ingred_service_5_2();
fix_ingred_service_5_3();
fix_ingred_service_5_6();
}
void fix_ingred_service_6_0_0(){
    {char * tlv3; tlv3 = (char *)(0); }
    {unsigned int tlv8; tlv8 = (unsigned int)(0); }
}
void fix_ingred_service_6_0(){
fix_ingred_service_6_0_0();
}
void fix_ingred_service_6_1_0(){
int socket;
    bzero(&socket,sizeof(int));
    {int ret; ret = (int)(socket); }
    {int tlv1; tlv1 = (int)(socket); }
    {int tlv4; tlv4 = (int)(socket); }
    {char * tlv3; tlv3 = (char *)(socket); }
    {cgc_size_t tlv2; tlv2 = (cgc_size_t)(socket); }
    {char * tlv7; tlv7 = (char *)(socket); }
    {unsigned int tlv8; tlv8 = (unsigned int)(socket); }
}
void fix_ingred_service_6_1(){
fix_ingred_service_6_1_0();
}
void fix_ingred_service_6_3_1(){
char buf [ 1024 ];
    bzero(&buf,( 1024 *sizeof(char) ) );
    {int ret; ret = (int)(buf); }
    {int tlv1; tlv1 = (int)(buf); }
    {int tlv4; tlv4 = (int)(buf); }
    {char * tlv3; tlv3 = (char *)(buf); }
    {cgc_size_t tlv2; tlv2 = (cgc_size_t)(buf); }
    {char * tlv7; tlv7 = (char *)(buf); }
    {unsigned int tlv8; tlv8 = (unsigned int)(buf); }
}
void fix_ingred_service_6_3_2(){
char buf [ 1024 ];
    bzero(&buf,( 1024 *sizeof(char) ) );
    {int ret; ret = (int)(sizeof ( buf ) - 1); }
    {int tlv1; tlv1 = (int)(sizeof ( buf ) - 1); }
    {int tlv4; tlv4 = (int)(sizeof ( buf ) - 1); }
    {char * tlv3; tlv3 = (char *)(sizeof ( buf ) - 1); }
    {cgc_size_t tlv2; tlv2 = (cgc_size_t)(sizeof ( buf ) - 1); }
    {char * tlv7; tlv7 = (char *)(sizeof ( buf ) - 1); }
    {unsigned int tlv8; tlv8 = (unsigned int)(sizeof ( buf ) - 1); }
}
void fix_ingred_service_6_3(){
fix_ingred_service_6_3_1();
fix_ingred_service_6_3_2();
}
void fix_ingred_service_6_4_3(){
int bytes_read;
    bzero(&bytes_read,sizeof(int));
    {int ret; ret = (int)(bytes_read); }
    {int tlv1; tlv1 = (int)(bytes_read); }
    {int tlv4; tlv4 = (int)(bytes_read); }
    {char * tlv3; tlv3 = (char *)(bytes_read); }
    {cgc_size_t tlv2; tlv2 = (cgc_size_t)(bytes_read); }
    {char * tlv7; tlv7 = (char *)(bytes_read); }
    {unsigned int tlv8; tlv8 = (unsigned int)(bytes_read); }
}
void fix_ingred_service_6_4(){
fix_ingred_service_6_4_3();
}
void fix_ingred_service_6_5_0(){
    {int ret; ret = (int)(2); }
    {int tlv1; tlv1 = (int)(2); }
    {int tlv4; tlv4 = (int)(2); }
    {char * tlv3; tlv3 = (char *)(2); }
    {cgc_size_t tlv2; tlv2 = (cgc_size_t)(2); }
    {char * tlv7; tlv7 = (char *)(2); }
    {unsigned int tlv8; tlv8 = (unsigned int)(2); }
}
void fix_ingred_service_6_5(){
fix_ingred_service_6_5_0();
}
void fix_ingred_service_6_9_5(){
int ret;
    bzero(&ret,sizeof(int));
    {char buf [ 1024 ]; buf [ ( 1024 )-1 ] = (char)(ret); }
    {int bytes_read; bytes_read = (int)(ret); }
    {int num_results; num_results = (int)(ret); }
    {int tlv1; tlv1 = (int)(ret); }
    {int tlv4; tlv4 = (int)(ret); }
    {char * tlv3; tlv3 = (char *)(ret); }
    {cgc_size_t tlv2; tlv2 = (cgc_size_t)(ret); }
    {unsigned int tlv5; tlv5 = (unsigned int)(ret); }
    {char * tlv7; tlv7 = (char *)(ret); }
    {unsigned int tlv8; tlv8 = (unsigned int)(ret); }
}
void fix_ingred_service_6_9(){
fix_ingred_service_6_9_5();
}
void fix_ingred_service_6_10_0(){
    {char buf [ 1024 ]; buf [ ( 1024 )-1 ] = (char)(10); }
    {int ret; ret = (int)(10); }
    {int bytes_read; bytes_read = (int)(10); }
    {int num_results; num_results = (int)(10); }
    {int tlv1; tlv1 = (int)(10); }
    {int tlv4; tlv4 = (int)(10); }
    {char * tlv3; tlv3 = (char *)(10); }
    {cgc_size_t tlv2; tlv2 = (cgc_size_t)(10); }
    {unsigned int tlv5; tlv5 = (unsigned int)(10); }
    {char * tlv7; tlv7 = (char *)(10); }
    {unsigned int tlv8; tlv8 = (unsigned int)(10); }
}
void fix_ingred_service_6_10(){
fix_ingred_service_6_10_0();
}
void fix_ingred_service_6(){
fix_ingred_service_6_0();
fix_ingred_service_6_1();
fix_ingred_service_6_3();
fix_ingred_service_6_4();
fix_ingred_service_6_5();
fix_ingred_service_6_9();
fix_ingred_service_6_10();
}
void fix_ingred_service_7_0_0(){
    {char * buffer; buffer = (char *)(NULL); }
    {cgc_size_t tlv30; tlv30 = (cgc_size_t)(NULL); }
    {int tlv29; tlv29 = (int)(NULL); }
    {char * tlv5; tlv5 = (char *)(NULL); }
    {char * tlv9; tlv9 = (char *)(NULL); }
    {char * tlv11; tlv11 = (char *)(NULL); }
    {char * tlv13; tlv13 = (char *)(NULL); }
    {char * tlv15; tlv15 = (char *)(NULL); }
    {char * tlv19; tlv19 = (char *)(NULL); }
    {char * tlv23; tlv23 = (char *)(NULL); }
    {char * tlv27; tlv27 = (char *)(NULL); }
    {unsigned int tlv31; tlv31 = (unsigned int)(NULL); }
}
void fix_ingred_service_7_0_1(){
    {char * buffer; buffer = (char *)(0); }
    {cgc_size_t tlv30; tlv30 = (cgc_size_t)(0); }
    {int tlv29; tlv29 = (int)(0); }
    {char * tlv5; tlv5 = (char *)(0); }
    {char * tlv9; tlv9 = (char *)(0); }
    {char * tlv11; tlv11 = (char *)(0); }
    {char * tlv13; tlv13 = (char *)(0); }
    {char * tlv15; tlv15 = (char *)(0); }
    {char * tlv19; tlv19 = (char *)(0); }
    {char * tlv23; tlv23 = (char *)(0); }
    {char * tlv27; tlv27 = (char *)(0); }
    {unsigned int tlv31; tlv31 = (unsigned int)(0); }
}
void fix_ingred_service_7_0(){
fix_ingred_service_7_0_0();
fix_ingred_service_7_0_1();
}
void fix_ingred_service_7_1_0(){
Request request;
    bzero(&request,sizeof(Request));
    {char * buffer; buffer = (char *)(sizeof ( request ) + cgc_MIN_REQ_LEN); }
    {int ret; ret = (int)(sizeof ( request ) + cgc_MIN_REQ_LEN); }
    {cgc_size_t tlv30; tlv30 = (cgc_size_t)(sizeof ( request ) + cgc_MIN_REQ_LEN); }
    {int tlv29; tlv29 = (int)(sizeof ( request ) + cgc_MIN_REQ_LEN); }
    {void * tlv3; tlv3 = (void *)(sizeof ( request ) + cgc_MIN_REQ_LEN); }
    {int tlv2; tlv2 = (int)(sizeof ( request ) + cgc_MIN_REQ_LEN); }
    {cgc_size_t tlv1; tlv1 = (cgc_size_t)(sizeof ( request ) + cgc_MIN_REQ_LEN); }
    {char * tlv5; tlv5 = (char *)(sizeof ( request ) + cgc_MIN_REQ_LEN); }
    {char * tlv7; tlv7 = (char *)(sizeof ( request ) + cgc_MIN_REQ_LEN); }
    {char * tlv9; tlv9 = (char *)(sizeof ( request ) + cgc_MIN_REQ_LEN); }
    {char * tlv11; tlv11 = (char *)(sizeof ( request ) + cgc_MIN_REQ_LEN); }
    {char * tlv13; tlv13 = (char *)(sizeof ( request ) + cgc_MIN_REQ_LEN); }
    {char * tlv15; tlv15 = (char *)(sizeof ( request ) + cgc_MIN_REQ_LEN); }
    {char * tlv17; tlv17 = (char *)(sizeof ( request ) + cgc_MIN_REQ_LEN); }
    {char * tlv19; tlv19 = (char *)(sizeof ( request ) + cgc_MIN_REQ_LEN); }
    {char * tlv21; tlv21 = (char *)(sizeof ( request ) + cgc_MIN_REQ_LEN); }
    {char * tlv23; tlv23 = (char *)(sizeof ( request ) + cgc_MIN_REQ_LEN); }
    {char * tlv25; tlv25 = (char *)(sizeof ( request ) + cgc_MIN_REQ_LEN); }
    {char * tlv27; tlv27 = (char *)(sizeof ( request ) + cgc_MIN_REQ_LEN); }
    {unsigned int tlv31; tlv31 = (unsigned int)(sizeof ( request ) + cgc_MIN_REQ_LEN); }
}
void fix_ingred_service_7_1(){
fix_ingred_service_7_1_0();
}
void fix_ingred_service_7_2_2(){
int ret;
    bzero(&ret,sizeof(int));
    {char * buffer; buffer = (char *)(ret); }
    {cgc_size_t tlv30; tlv30 = (cgc_size_t)(ret); }
    {int tlv29; tlv29 = (int)(ret); }
    {void * tlv3; tlv3 = (void *)(ret); }
    {int tlv2; tlv2 = (int)(ret); }
    {cgc_size_t tlv1; tlv1 = (cgc_size_t)(ret); }
    {char * tlv5; tlv5 = (char *)(ret); }
    {char * tlv9; tlv9 = (char *)(ret); }
    {char * tlv11; tlv11 = (char *)(ret); }
    {char * tlv13; tlv13 = (char *)(ret); }
    {char * tlv15; tlv15 = (char *)(ret); }
    {char * tlv17; tlv17 = (char *)(ret); }
    {char * tlv19; tlv19 = (char *)(ret); }
    {char * tlv21; tlv21 = (char *)(ret); }
    {char * tlv23; tlv23 = (char *)(ret); }
    {char * tlv25; tlv25 = (char *)(ret); }
    {char * tlv27; tlv27 = (char *)(ret); }
    {unsigned int tlv31; tlv31 = (unsigned int)(ret); }
}
void fix_ingred_service_7_2(){
fix_ingred_service_7_2_2();
}
void fix_ingred_service_7_3_0(){
    {char * buffer; buffer = (char *)(3); }
    {int ret; ret = (int)(3); }
    {cgc_size_t tlv30; tlv30 = (cgc_size_t)(3); }
    {int tlv29; tlv29 = (int)(3); }
    {void * tlv3; tlv3 = (void *)(3); }
    {int tlv2; tlv2 = (int)(3); }
    {cgc_size_t tlv1; tlv1 = (cgc_size_t)(3); }
    {char * tlv5; tlv5 = (char *)(3); }
    {char * tlv7; tlv7 = (char *)(3); }
    {char * tlv9; tlv9 = (char *)(3); }
    {char * tlv11; tlv11 = (char *)(3); }
    {char * tlv13; tlv13 = (char *)(3); }
    {char * tlv15; tlv15 = (char *)(3); }
    {char * tlv17; tlv17 = (char *)(3); }
    {char * tlv19; tlv19 = (char *)(3); }
    {char * tlv21; tlv21 = (char *)(3); }
    {char * tlv23; tlv23 = (char *)(3); }
    {char * tlv25; tlv25 = (char *)(3); }
    {char * tlv27; tlv27 = (char *)(3); }
    {unsigned int tlv31; tlv31 = (unsigned int)(3); }
}
void fix_ingred_service_7_3(){
fix_ingred_service_7_3_0();
}
void fix_ingred_service_7_4_0(){
char buffer_ref;
    bzero(&buffer_ref,1*sizeof(char));
char * buffer = &buffer_ref;
    {int ret; ret = (int)(buffer); }
    {cgc_size_t tlv30; tlv30 = (cgc_size_t)(buffer); }
    {int tlv29; tlv29 = (int)(buffer); }
    {int tlv2; tlv2 = (int)(buffer); }
    {char * tlv5; tlv5 = (char *)(buffer); }
    {char * tlv7; tlv7 = (char *)(buffer); }
    {char * tlv9; tlv9 = (char *)(buffer); }
    {char * tlv11; tlv11 = (char *)(buffer); }
    {char * tlv13; tlv13 = (char *)(buffer); }
    {char * tlv15; tlv15 = (char *)(buffer); }
    {char * tlv17; tlv17 = (char *)(buffer); }
    {char * tlv19; tlv19 = (char *)(buffer); }
    {char * tlv21; tlv21 = (char *)(buffer); }
    {char * tlv23; tlv23 = (char *)(buffer); }
    {char * tlv25; tlv25 = (char *)(buffer); }
    {char * tlv27; tlv27 = (char *)(buffer); }
    {unsigned int tlv31; tlv31 = (unsigned int)(buffer); }
}
void fix_ingred_service_7_4(){
fix_ingred_service_7_4_0();
}
void fix_ingred_service_7_5_0(){
char buffer_ref;
    bzero(&buffer_ref,1*sizeof(char));
char * buffer = &buffer_ref;
    {cgc_size_t tlv30; tlv30 = (cgc_size_t)(buffer); }
    {int tlv29; tlv29 = (int)(buffer); }
    {char * tlv5; tlv5 = (char *)(buffer); }
    {char * tlv9; tlv9 = (char *)(buffer); }
    {char * tlv11; tlv11 = (char *)(buffer); }
    {char * tlv13; tlv13 = (char *)(buffer); }
    {char * tlv15; tlv15 = (char *)(buffer); }
    {char * tlv19; tlv19 = (char *)(buffer); }
    {char * tlv23; tlv23 = (char *)(buffer); }
    {char * tlv27; tlv27 = (char *)(buffer); }
    {unsigned int tlv31; tlv31 = (unsigned int)(buffer); }
}
void fix_ingred_service_7_5(){
fix_ingred_service_7_5_0();
}
void fix_ingred_service_7(){
fix_ingred_service_7_0();
fix_ingred_service_7_1();
fix_ingred_service_7_2();
fix_ingred_service_7_3();
fix_ingred_service_7_4();
fix_ingred_service_7_5();
}
void fix_ingred_service_8_0_0(){
unsigned int index;
    bzero(&index,sizeof(unsigned int));
unsigned int max;
    bzero(&max,sizeof(unsigned int));
    {cgc_size_t bytes_written; bytes_written = (cgc_size_t)(0); }
    {unsigned int index; index = (unsigned int)(0); }
    {int ret; ret = (int)(0); }
    {unsigned long tlv_size_0; tlv_size_0 = (unsigned long)(0); }
    {void * tlv3; tlv3 = (void *)(0); }
    {cgc_size_t tlv2; tlv2 = (cgc_size_t)(0); }
    {unsigned int tlv4; tlv4 = (unsigned int)(0); }
    {unsigned int tlv5; tlv5 = (unsigned int)(0); }
}
void fix_ingred_service_8_0_1(){
unsigned int index;
    bzero(&index,sizeof(unsigned int));
unsigned int max;
    bzero(&max,sizeof(unsigned int));
    {cgc_size_t bytes_written; bytes_written = (cgc_size_t)(0); }
    {unsigned int index; index = (unsigned int)(0); }
    {int ret; ret = (int)(0); }
    {unsigned long tlv_size_0; tlv_size_0 = (unsigned long)(0); }
    {void * tlv3; tlv3 = (void *)(0); }
    {cgc_size_t tlv2; tlv2 = (cgc_size_t)(0); }
    {unsigned int tlv4; tlv4 = (unsigned int)(0); }
    {unsigned int tlv5; tlv5 = (unsigned int)(0); }
}
void fix_ingred_service_8_0_2(){
unsigned int index;
    bzero(&index,sizeof(unsigned int));
unsigned int max;
    bzero(&max,sizeof(unsigned int));
    {cgc_size_t bytes_written; bytes_written = (cgc_size_t)(0); }
    {unsigned int index; index = (unsigned int)(0); }
    {unsigned long tlv_size_0; tlv_size_0 = (unsigned long)(0); }
    {unsigned int tlv4; tlv4 = (unsigned int)(0); }
}
void fix_ingred_service_8_0_3(){
unsigned int index;
    bzero(&index,sizeof(unsigned int));
unsigned int max;
    bzero(&max,sizeof(unsigned int));
    {cgc_size_t bytes_written; bytes_written = (cgc_size_t)(sizeof ( index )); }
    {int ret; ret = (int)(sizeof ( index )); }
    {unsigned long tlv_size_0; tlv_size_0 = (unsigned long)(sizeof ( index )); }
    {void * tlv3; tlv3 = (void *)(sizeof ( index )); }
    {cgc_size_t tlv2; tlv2 = (cgc_size_t)(sizeof ( index )); }
    {unsigned int tlv4; tlv4 = (unsigned int)(sizeof ( index )); }
    {unsigned int tlv5; tlv5 = (unsigned int)(sizeof ( index )); }
}
void fix_ingred_service_8_0_4(){
unsigned int index;
    bzero(&index,sizeof(unsigned int));
unsigned int max;
    bzero(&max,sizeof(unsigned int));
    {    max = 1;
         cgc_size_t bytes_written; bytes_written = (cgc_size_t)(index % max); }
    {    max = 1;
         int ret; ret = (int)(index % max); }
    {    max = 1;
         unsigned long tlv_size_0; tlv_size_0 = (unsigned long)(index % max); }
    {    max = 1;
         void * tlv3; tlv3 = (void *)(index % max); }
    {    max = 1;
         cgc_size_t tlv2; tlv2 = (cgc_size_t)(index % max); }
    {    max = 1;
         unsigned int tlv4; tlv4 = (unsigned int)(index % max); }
    {    max = 1;
         unsigned int tlv5; tlv5 = (unsigned int)(index % max); }
}
void fix_ingred_service_8_0(){
fix_ingred_service_8_0_0();
fix_ingred_service_8_0_1();
fix_ingred_service_8_0_2();
fix_ingred_service_8_0_3();
fix_ingred_service_8_0_4();
}
void fix_ingred_service_8_1_0(){
unsigned int index;
    bzero(&index,sizeof(unsigned int));
    {cgc_size_t bytes_written; bytes_written = (cgc_size_t)(& index); }
    {int ret; ret = (int)(& index); }
    {unsigned long tlv_size_0; tlv_size_0 = (unsigned long)(& index); }
    {void * tlv3; tlv3 = (void *)(& index); }
    {cgc_size_t tlv2; tlv2 = (cgc_size_t)(& index); }
    {unsigned int tlv4; tlv4 = (unsigned int)(& index); }
    {unsigned int tlv5; tlv5 = (unsigned int)(& index); }
}
void fix_ingred_service_8_1_1(){
unsigned int index;
    bzero(&index,sizeof(unsigned int));
    {cgc_size_t bytes_written; bytes_written = (cgc_size_t)(sizeof ( index )); }
    {int ret; ret = (int)(sizeof ( index )); }
    {unsigned long tlv_size_0; tlv_size_0 = (unsigned long)(sizeof ( index )); }
    {void * tlv3; tlv3 = (void *)(sizeof ( index )); }
    {cgc_size_t tlv2; tlv2 = (cgc_size_t)(sizeof ( index )); }
    {unsigned int tlv4; tlv4 = (unsigned int)(sizeof ( index )); }
    {unsigned int tlv5; tlv5 = (unsigned int)(sizeof ( index )); }
}
void fix_ingred_service_8_1(){
fix_ingred_service_8_1_0();
fix_ingred_service_8_1_1();
}
void fix_ingred_service_8_2_3(){
int ret;
    bzero(&ret,sizeof(int));
    {cgc_size_t bytes_written; bytes_written = (cgc_size_t)(ret); }
    {unsigned int index; index = (unsigned int)(ret); }
    {unsigned long tlv_size_0; tlv_size_0 = (unsigned long)(ret); }
    {unsigned int tlv4; tlv4 = (unsigned int)(ret); }
}
void fix_ingred_service_8_2(){
fix_ingred_service_8_2_3();
}
void fix_ingred_service_8_3_0(){
    {cgc_size_t bytes_written; bytes_written = (cgc_size_t)(1); }
    {unsigned int index; index = (unsigned int)(1); }
    {int ret; ret = (int)(1); }
    {unsigned long tlv_size_0; tlv_size_0 = (unsigned long)(1); }
    {void * tlv3; tlv3 = (void *)(1); }
    {cgc_size_t tlv2; tlv2 = (cgc_size_t)(1); }
    {unsigned int tlv4; tlv4 = (unsigned int)(1); }
    {unsigned int tlv5; tlv5 = (unsigned int)(1); }
}
void fix_ingred_service_8_3(){
fix_ingred_service_8_3_0();
}
void fix_ingred_service_8_4_4(){
cgc_size_t bytes_written;
    bzero(&bytes_written,sizeof(cgc_size_t));
unsigned long tlv_size_0;
    bzero(&tlv_size_0,sizeof(unsigned long));
    {unsigned int index; index = (unsigned int)(bytes_written); }
    {int ret; ret = (int)(bytes_written); }
    {unsigned long tlv_size_0; tlv_size_0 = (unsigned long)(bytes_written); }
    {void * tlv3; tlv3 = (void *)(bytes_written); }
    {cgc_size_t tlv2; tlv2 = (cgc_size_t)(bytes_written); }
    {unsigned int tlv4; tlv4 = (unsigned int)(bytes_written); }
    {unsigned int tlv5; tlv5 = (unsigned int)(bytes_written); }
}
void fix_ingred_service_8_4_5(){
cgc_size_t bytes_written;
    bzero(&bytes_written,sizeof(cgc_size_t));
unsigned long tlv_size_0;
    bzero(&tlv_size_0,sizeof(unsigned long));
    {cgc_size_t bytes_written; bytes_written = (cgc_size_t)(tlv_size_0); }
    {unsigned int index; index = (unsigned int)(tlv_size_0); }
    {int ret; ret = (int)(tlv_size_0); }
    {void * tlv3; tlv3 = (void *)(tlv_size_0); }
    {cgc_size_t tlv2; tlv2 = (cgc_size_t)(tlv_size_0); }
    {unsigned int tlv4; tlv4 = (unsigned int)(tlv_size_0); }
    {unsigned int tlv5; tlv5 = (unsigned int)(tlv_size_0); }
}
void fix_ingred_service_8_4(){
fix_ingred_service_8_4_4();
fix_ingred_service_8_4_5();
}
void fix_ingred_service_8_5_0(){
    {cgc_size_t bytes_written; bytes_written = (cgc_size_t)(2); }
    {unsigned int index; index = (unsigned int)(2); }
    {unsigned long tlv_size_0; tlv_size_0 = (unsigned long)(2); }
    {void * tlv3; tlv3 = (void *)(2); }
    {unsigned int tlv4; tlv4 = (unsigned int)(2); }
}
void fix_ingred_service_8_5(){
fix_ingred_service_8_5_0();
}
void fix_ingred_service_8(){
fix_ingred_service_8_0();
fix_ingred_service_8_1();
fix_ingred_service_8_2();
fix_ingred_service_8_3();
fix_ingred_service_8_4();
fix_ingred_service_8_5();
}
void fix_ingred_service_9_0_0(){
    {int index; index = (int)(0); }
}
void fix_ingred_service_9_0(){
fix_ingred_service_9_0_0();
}
void fix_ingred_service_9_1_0(){
    {int index; index = (int)(ATTR_NUM); }
    {unsigned int tlv4; tlv4 = (unsigned int)(ATTR_NUM); }
    {void * tlv3; tlv3 = (void *)(ATTR_NUM); }
    {void * tlv2; tlv2 = (void *)(ATTR_NUM); }
    {cgc_size_t tlv1; tlv1 = (cgc_size_t)(ATTR_NUM); }
}
void fix_ingred_service_9_1(){
fix_ingred_service_9_1_0();
}
void fix_ingred_service_9_2_0(){
Request request_ref;
    bzero(&request_ref,1*sizeof(Request));
Request * request = &request_ref;
int index;
    bzero(&index,sizeof(int));
    {int index; index = (int)(request -> attribute); }
    {unsigned int tlv4; tlv4 = (unsigned int)(request -> attribute); }
    {void * tlv3; tlv3 = (void *)(request -> attribute); }
    {void * tlv2; tlv2 = (void *)(request -> attribute); }
    {cgc_size_t tlv1; tlv1 = (cgc_size_t)(request -> attribute); }
}
void fix_ingred_service_9_2_1(){
Request request_ref;
    bzero(&request_ref,1*sizeof(Request));
Request * request = &request_ref;
int index;
    bzero(&index,sizeof(int));
    {if (attributes){    index = 0;
         unsigned int tlv4; tlv4 = (unsigned int)(attributes [ index ]); }}
    {if (attributes){    index = 0;
         void * tlv3; tlv3 = (void *)(attributes [ index ]); }}
    {if (attributes){    index = 0;
         void * tlv2; tlv2 = (void *)(attributes [ index ]); }}
    {if (attributes){    index = 0;
         cgc_size_t tlv1; tlv1 = (cgc_size_t)(attributes [ index ]); }}
}
void fix_ingred_service_9_2(){
fix_ingred_service_9_2_0();
fix_ingred_service_9_2_1();
}
void fix_ingred_service_9_3_0(){
char tlv5_ref;
    bzero(&tlv5_ref,1*sizeof(char));
const char * tlv5 = &tlv5_ref;
    {int index; index = (int)(cgc_strlen ( tlv5 )); }
    {unsigned int tlv4; tlv4 = (unsigned int)(cgc_strlen ( tlv5 )); }
    {void * tlv3; tlv3 = (void *)(cgc_strlen ( tlv5 )); }
    {void * tlv2; tlv2 = (void *)(cgc_strlen ( tlv5 )); }
    {cgc_size_t tlv1; tlv1 = (cgc_size_t)(cgc_strlen ( tlv5 )); }
}
void fix_ingred_service_9_3(){
fix_ingred_service_9_3_0();
}
void fix_ingred_service_9(){
fix_ingred_service_9_0();
fix_ingred_service_9_1();
fix_ingred_service_9_2();
fix_ingred_service_9_3();
}
void fix_ingred_service_10_0_0(){
    {unsigned int size; size = (unsigned int)(0); }
    {unsigned int charset_size; charset_size = (unsigned int)(0); }
    {int index; index = (int)(0); }
    {int letter; letter = (int)(0); }
    {unsigned int tlv2; tlv2 = (unsigned int)(0); }
    {unsigned int tlv3; tlv3 = (unsigned int)(0); }
}
void fix_ingred_service_10_0_2(){
    {unsigned int size; size = (unsigned int)(0); }
    {unsigned int charset_size; charset_size = (unsigned int)(0); }
    {int letter; letter = (int)(0); }
    {unsigned int tlv2; tlv2 = (unsigned int)(0); }
    {unsigned int tlv3; tlv3 = (unsigned int)(0); }
}
void fix_ingred_service_10_0(){
fix_ingred_service_10_0_0();
fix_ingred_service_10_0_2();
}
void fix_ingred_service_10_1_3(){
unsigned int size;
    bzero(&size,sizeof(unsigned int));
    {unsigned int charset_size; charset_size = (unsigned int)(size); }
    {int index; index = (int)(size); }
    {int letter; letter = (int)(size); }
    {unsigned int tlv2; tlv2 = (unsigned int)(size); }
    {unsigned int tlv3; tlv3 = (unsigned int)(size); }
}
void fix_ingred_service_10_1(){
fix_ingred_service_10_1_3();
}
void fix_ingred_service_10_2_0(){
    {unsigned int size; size = (unsigned int)(RESULT_VALUE_SIZE); }
    {unsigned int charset_size; charset_size = (unsigned int)(RESULT_VALUE_SIZE); }
    {int index; index = (int)(RESULT_VALUE_SIZE); }
    {int letter; letter = (int)(RESULT_VALUE_SIZE); }
    {unsigned int tlv2; tlv2 = (unsigned int)(RESULT_VALUE_SIZE); }
    {unsigned int tlv3; tlv3 = (unsigned int)(RESULT_VALUE_SIZE); }
}
void fix_ingred_service_10_2(){
fix_ingred_service_10_2_0();
}
void fix_ingred_service_10_3_0(){
char tlv1_ref;
    bzero(&tlv1_ref,1*sizeof(char));
const char * tlv1 = &tlv1_ref;
    {unsigned int size; size = (unsigned int)(cgc_strlen ( tlv1 )); }
    {unsigned int charset_size; charset_size = (unsigned int)(cgc_strlen ( tlv1 )); }
    {int index; index = (int)(cgc_strlen ( tlv1 )); }
    {int letter; letter = (int)(cgc_strlen ( tlv1 )); }
    {unsigned int tlv2; tlv2 = (unsigned int)(cgc_strlen ( tlv1 )); }
    {unsigned int tlv3; tlv3 = (unsigned int)(cgc_strlen ( tlv1 )); }
}
void fix_ingred_service_10_3(){
fix_ingred_service_10_3_0();
}
void fix_ingred_service_10_4_5(){
int index;
    bzero(&index,sizeof(int));
unsigned int size;
    bzero(&size,sizeof(unsigned int));
    {unsigned int size; size = (unsigned int)(index); }
    {unsigned int charset_size; charset_size = (unsigned int)(index); }
    {int letter; letter = (int)(index); }
    {unsigned int tlv2; tlv2 = (unsigned int)(index); }
    {unsigned int tlv3; tlv3 = (unsigned int)(index); }
}
void fix_ingred_service_10_4_6(){
int index;
    bzero(&index,sizeof(int));
unsigned int size;
    bzero(&size,sizeof(unsigned int));
    {unsigned int charset_size; charset_size = (unsigned int)(size); }
    {int index; index = (int)(size); }
    {int letter; letter = (int)(size); }
    {unsigned int tlv2; tlv2 = (unsigned int)(size); }
    {unsigned int tlv3; tlv3 = (unsigned int)(size); }
}
void fix_ingred_service_10_4(){
fix_ingred_service_10_4_5();
fix_ingred_service_10_4_6();
}
void fix_ingred_service_10_5_0(){
unsigned int charset_size;
    bzero(&charset_size,sizeof(unsigned int));
    {unsigned int size; size = (unsigned int)(charset_size); }
    {int index; index = (int)(charset_size); }
    {int letter; letter = (int)(charset_size); }
    {unsigned int tlv2; tlv2 = (unsigned int)(charset_size); }
    {unsigned int tlv3; tlv3 = (unsigned int)(charset_size); }
}
void fix_ingred_service_10_5(){
fix_ingred_service_10_5_0();
}
void fix_ingred_service_10(){
fix_ingred_service_10_0();
fix_ingred_service_10_1();
fix_ingred_service_10_2();
fix_ingred_service_10_3();
fix_ingred_service_10_4();
fix_ingred_service_10_5();
}
void fix_ingred_service_11_1_0(){
Request request_ref;
    bzero(&request_ref,1*sizeof(Request));
Request * request = &request_ref;
    {void * tlv3; tlv3 = (void *)(request); }
    {int tlv2; tlv2 = (int)(request); }
    {cgc_size_t tlv1; tlv1 = (cgc_size_t)(request); }
    {void * tlv6; tlv6 = (void *)(request); }
    {void * tlv5; tlv5 = (void *)(request); }
    {cgc_size_t tlv4; tlv4 = (cgc_size_t)(request); }
}
void fix_ingred_service_11_1_1(){
Request request_ref;
    bzero(&request_ref,1*sizeof(Request));
Request * request = &request_ref;
    {void * tlv6; tlv6 = (void *)(0); }
    {void * tlv5; tlv5 = (void *)(0); }
    {cgc_size_t tlv4; tlv4 = (cgc_size_t)(0); }
}
void fix_ingred_service_11_1_2(){
Request request_ref;
    bzero(&request_ref,1*sizeof(Request));
Request * request = &request_ref;
    {void * tlv3; tlv3 = (void *)(REQUEST_SIZE); }
    {int tlv2; tlv2 = (int)(REQUEST_SIZE); }
    {cgc_size_t tlv1; tlv1 = (cgc_size_t)(REQUEST_SIZE); }
    {void * tlv6; tlv6 = (void *)(REQUEST_SIZE); }
    {void * tlv5; tlv5 = (void *)(REQUEST_SIZE); }
    {cgc_size_t tlv4; tlv4 = (cgc_size_t)(REQUEST_SIZE); }
}
void fix_ingred_service_11_1(){
fix_ingred_service_11_1_0();
fix_ingred_service_11_1_1();
fix_ingred_service_11_1_2();
}
void fix_ingred_service_11_2_0(){
Request request_ref;
    bzero(&request_ref,1*sizeof(Request));
Request * request = &request_ref;
    {void * tlv3; tlv3 = (void *)(request -> limit); }
    {int tlv2; tlv2 = (int)(request -> limit); }
    {cgc_size_t tlv1; tlv1 = (cgc_size_t)(request -> limit); }
    {void * tlv6; tlv6 = (void *)(request -> limit); }
    {void * tlv5; tlv5 = (void *)(request -> limit); }
    {cgc_size_t tlv4; tlv4 = (cgc_size_t)(request -> limit); }
}
void fix_ingred_service_11_2_1(){
Request request_ref;
    bzero(&request_ref,1*sizeof(Request));
Request * request = &request_ref;
    {void * tlv3; tlv3 = (void *)(RESULT_LIMIT_STR); }
    {int tlv2; tlv2 = (int)(RESULT_LIMIT_STR); }
    {cgc_size_t tlv1; tlv1 = (cgc_size_t)(RESULT_LIMIT_STR); }
    {void * tlv6; tlv6 = (void *)(RESULT_LIMIT_STR); }
    {void * tlv5; tlv5 = (void *)(RESULT_LIMIT_STR); }
    {cgc_size_t tlv4; tlv4 = (cgc_size_t)(RESULT_LIMIT_STR); }
}
void fix_ingred_service_11_2_2(){
Request request_ref;
    bzero(&request_ref,1*sizeof(Request));
Request * request = &request_ref;
    {void * tlv3; tlv3 = (void *)(sizeof ( RESULT_LIMIT_STR )); }
    {int tlv2; tlv2 = (int)(sizeof ( RESULT_LIMIT_STR )); }
    {cgc_size_t tlv1; tlv1 = (cgc_size_t)(sizeof ( RESULT_LIMIT_STR )); }
    {void * tlv6; tlv6 = (void *)(sizeof ( RESULT_LIMIT_STR )); }
    {void * tlv5; tlv5 = (void *)(sizeof ( RESULT_LIMIT_STR )); }
    {cgc_size_t tlv4; tlv4 = (cgc_size_t)(sizeof ( RESULT_LIMIT_STR )); }
}
void fix_ingred_service_11_2(){
fix_ingred_service_11_2_0();
fix_ingred_service_11_2_1();
fix_ingred_service_11_2_2();
}
void fix_ingred_service_11(){
fix_ingred_service_11_1();
fix_ingred_service_11_2();
}
void fix_ingred_service_12_0_0(){
    {int section; section = (int)(0); }
    {cgc_size_t tlv6; tlv6 = (cgc_size_t)(0); }
    {int tlv5; tlv5 = (int)(0); }
    {int tlv2; tlv2 = (int)(0); }
    {cgc_size_t tlv1; tlv1 = (cgc_size_t)(0); }
    {unsigned int tlv8; tlv8 = (unsigned int)(0); }
    {unsigned int tlv9; tlv9 = (unsigned int)(0); }
}
void fix_ingred_service_12_0_1(){
    {int section; section = (int)(0); }
    {unsigned int tlv9; tlv9 = (unsigned int)(0); }
}
void fix_ingred_service_12_0(){
fix_ingred_service_12_0_0();
fix_ingred_service_12_0_1();
}
void fix_ingred_service_12_1_0(){
    {unsigned int charset_size; charset_size = (unsigned int)(GIFT_CARD_LEN + 1); }
    {int index; index = (int)(GIFT_CARD_LEN + 1); }
    {int section; section = (int)(GIFT_CARD_LEN + 1); }
    {int ret; ret = (int)(GIFT_CARD_LEN + 1); }
    {cgc_size_t tlv6; tlv6 = (cgc_size_t)(GIFT_CARD_LEN + 1); }
    {int tlv5; tlv5 = (int)(GIFT_CARD_LEN + 1); }
    {void * tlv3; tlv3 = (void *)(GIFT_CARD_LEN + 1); }
    {int tlv2; tlv2 = (int)(GIFT_CARD_LEN + 1); }
    {cgc_size_t tlv1; tlv1 = (cgc_size_t)(GIFT_CARD_LEN + 1); }
    {int letter; letter = (int)(GIFT_CARD_LEN + 1); }
    {unsigned int tlv8; tlv8 = (unsigned int)(GIFT_CARD_LEN + 1); }
    {unsigned int tlv9; tlv9 = (unsigned int)(GIFT_CARD_LEN + 1); }
}
void fix_ingred_service_12_1(){
fix_ingred_service_12_1_0();
}
void fix_ingred_service_12_2_4(){
int ret;
    bzero(&ret,sizeof(int));
    {unsigned int charset_size; charset_size = (unsigned int)(ret); }
    {int index; index = (int)(ret); }
    {int section; section = (int)(ret); }
    {cgc_size_t tlv6; tlv6 = (cgc_size_t)(ret); }
    {int tlv5; tlv5 = (int)(ret); }
    {int letter; letter = (int)(ret); }
    {unsigned int tlv9; tlv9 = (unsigned int)(ret); }
}
void fix_ingred_service_12_2(){
fix_ingred_service_12_2_4();
}
void fix_ingred_service_12_3_0(){
    {unsigned int charset_size; charset_size = (unsigned int)(3); }
    {int index; index = (int)(3); }
    {int section; section = (int)(3); }
    {cgc_size_t tlv6; tlv6 = (cgc_size_t)(3); }
    {int tlv5; tlv5 = (int)(3); }
    {int letter; letter = (int)(3); }
    {unsigned int tlv8; tlv8 = (unsigned int)(3); }
    {unsigned int tlv9; tlv9 = (unsigned int)(3); }
}
void fix_ingred_service_12_3(){
fix_ingred_service_12_3_0();
}
void fix_ingred_service_12_4_0(){
char gift_card_ref;
    bzero(&gift_card_ref,1*sizeof(char));
char * * gift_card = &gift_card_ref;
    {unsigned int charset_size; charset_size = (unsigned int)(* gift_card); }
    {int index; index = (int)(* gift_card); }
    {int section; section = (int)(* gift_card); }
    {int ret; ret = (int)(* gift_card); }
    {cgc_size_t tlv6; tlv6 = (cgc_size_t)(* gift_card); }
    {int tlv5; tlv5 = (int)(* gift_card); }
    {void * tlv3; tlv3 = (void *)(* gift_card); }
    {int tlv2; tlv2 = (int)(* gift_card); }
    {cgc_size_t tlv1; tlv1 = (cgc_size_t)(* gift_card); }
    {int letter; letter = (int)(* gift_card); }
    {unsigned int tlv8; tlv8 = (unsigned int)(* gift_card); }
    {unsigned int tlv9; tlv9 = (unsigned int)(* gift_card); }
}
void fix_ingred_service_12_4_2(){
char gift_card_ref;
    bzero(&gift_card_ref,1*sizeof(char));
char * * gift_card = &gift_card_ref;
    {unsigned int charset_size; charset_size = (unsigned int)(GIFT_CARD_LEN); }
    {int index; index = (int)(GIFT_CARD_LEN); }
    {int section; section = (int)(GIFT_CARD_LEN); }
    {int ret; ret = (int)(GIFT_CARD_LEN); }
    {cgc_size_t tlv6; tlv6 = (cgc_size_t)(GIFT_CARD_LEN); }
    {int tlv5; tlv5 = (int)(GIFT_CARD_LEN); }
    {void * tlv3; tlv3 = (void *)(GIFT_CARD_LEN); }
    {int tlv2; tlv2 = (int)(GIFT_CARD_LEN); }
    {cgc_size_t tlv1; tlv1 = (cgc_size_t)(GIFT_CARD_LEN); }
    {int letter; letter = (int)(GIFT_CARD_LEN); }
    {unsigned int tlv8; tlv8 = (unsigned int)(GIFT_CARD_LEN); }
    {unsigned int tlv9; tlv9 = (unsigned int)(GIFT_CARD_LEN); }
}
void fix_ingred_service_12_4(){
fix_ingred_service_12_4_0();
fix_ingred_service_12_4_2();
}
void fix_ingred_service_12_5_0(){
char tlv7_ref;
    bzero(&tlv7_ref,1*sizeof(char));
const char * tlv7 = &tlv7_ref;
    {unsigned int charset_size; charset_size = (unsigned int)(cgc_strlen ( tlv7 )); }
    {int index; index = (int)(cgc_strlen ( tlv7 )); }
    {int section; section = (int)(cgc_strlen ( tlv7 )); }
    {int ret; ret = (int)(cgc_strlen ( tlv7 )); }
    {cgc_size_t tlv6; tlv6 = (cgc_size_t)(cgc_strlen ( tlv7 )); }
    {int tlv5; tlv5 = (int)(cgc_strlen ( tlv7 )); }
    {void * tlv3; tlv3 = (void *)(cgc_strlen ( tlv7 )); }
    {int tlv2; tlv2 = (int)(cgc_strlen ( tlv7 )); }
    {cgc_size_t tlv1; tlv1 = (cgc_size_t)(cgc_strlen ( tlv7 )); }
    {int letter; letter = (int)(cgc_strlen ( tlv7 )); }
    {unsigned int tlv8; tlv8 = (unsigned int)(cgc_strlen ( tlv7 )); }
    {unsigned int tlv9; tlv9 = (unsigned int)(cgc_strlen ( tlv7 )); }
}
void fix_ingred_service_12_5(){
fix_ingred_service_12_5_0();
}
void fix_ingred_service_12_6_6(){
int index;
    bzero(&index,sizeof(int));
    {int section; section = (int)(index); }
    {int ret; ret = (int)(index); }
    {cgc_size_t tlv6; tlv6 = (cgc_size_t)(index); }
    {int tlv5; tlv5 = (int)(index); }
    {void * tlv3; tlv3 = (void *)(index); }
    {int tlv2; tlv2 = (int)(index); }
    {cgc_size_t tlv1; tlv1 = (cgc_size_t)(index); }
    {unsigned int tlv8; tlv8 = (unsigned int)(index); }
    {unsigned int tlv9; tlv9 = (unsigned int)(index); }
}
void fix_ingred_service_12_6_7(){
int index;
    bzero(&index,sizeof(int));
    {unsigned int charset_size; charset_size = (unsigned int)(GIFT_CARD_LEN); }
    {int index; index = (int)(GIFT_CARD_LEN); }
    {int section; section = (int)(GIFT_CARD_LEN); }
    {int ret; ret = (int)(GIFT_CARD_LEN); }
    {cgc_size_t tlv6; tlv6 = (cgc_size_t)(GIFT_CARD_LEN); }
    {int tlv5; tlv5 = (int)(GIFT_CARD_LEN); }
    {void * tlv3; tlv3 = (void *)(GIFT_CARD_LEN); }
    {int tlv2; tlv2 = (int)(GIFT_CARD_LEN); }
    {cgc_size_t tlv1; tlv1 = (cgc_size_t)(GIFT_CARD_LEN); }
    {int letter; letter = (int)(GIFT_CARD_LEN); }
    {unsigned int tlv8; tlv8 = (unsigned int)(GIFT_CARD_LEN); }
    {unsigned int tlv9; tlv9 = (unsigned int)(GIFT_CARD_LEN); }
}
void fix_ingred_service_12_6(){
fix_ingred_service_12_6_6();
fix_ingred_service_12_6_7();
}
void fix_ingred_service_12_7_0(){
unsigned int charset_size;
    bzero(&charset_size,sizeof(unsigned int));
    {int section; section = (int)(charset_size); }
    {int ret; ret = (int)(charset_size); }
    {cgc_size_t tlv6; tlv6 = (cgc_size_t)(charset_size); }
    {int tlv5; tlv5 = (int)(charset_size); }
    {void * tlv3; tlv3 = (void *)(charset_size); }
    {int tlv2; tlv2 = (int)(charset_size); }
    {cgc_size_t tlv1; tlv1 = (cgc_size_t)(charset_size); }
    {unsigned int tlv8; tlv8 = (unsigned int)(charset_size); }
    {unsigned int tlv9; tlv9 = (unsigned int)(charset_size); }
}
void fix_ingred_service_12_7(){
fix_ingred_service_12_7_0();
}
void fix_ingred_service_12(){
fix_ingred_service_12_0();
fix_ingred_service_12_1();
fix_ingred_service_12_2();
fix_ingred_service_12_3();
fix_ingred_service_12_4();
fix_ingred_service_12_5();
fix_ingred_service_12_6();
fix_ingred_service_12_7();
}
void fix_ingred_service_13_0_0(){
    {char price; price = (char)(0); }
    {cgc_size_t tlv5; tlv5 = (cgc_size_t)(0); }
    {int tlv10; tlv10 = (int)(0); }
    {cgc_size_t tlv8; tlv8 = (cgc_size_t)(0); }
    {unsigned int tlv11; tlv11 = (unsigned int)(0); }
    {unsigned int tlv12; tlv12 = (unsigned int)(0); }
}
void fix_ingred_service_13_0_1(){
    {int ret; ret = (int)(0); }
    {char price; price = (char)(0); }
    {void * tlv4; tlv4 = (void *)(0); }
    {void * tlv3; tlv3 = (void *)(0); }
    {cgc_size_t tlv2; tlv2 = (cgc_size_t)(0); }
    {int tlv7; tlv7 = (int)(0); }
    {cgc_size_t tlv5; tlv5 = (cgc_size_t)(0); }
    {int tlv10; tlv10 = (int)(0); }
    {cgc_size_t tlv8; tlv8 = (cgc_size_t)(0); }
    {unsigned int tlv11; tlv11 = (unsigned int)(0); }
    {unsigned int tlv12; tlv12 = (unsigned int)(0); }
}
void fix_ingred_service_13_0(){
fix_ingred_service_13_0_0();
fix_ingred_service_13_0_1();
}
void fix_ingred_service_13_3_1(){
Song selectedSong_ref;
    bzero(&selectedSong_ref,1*sizeof(Song));
Song * selectedSong = &selectedSong_ref;
    {int ret; ret = (int)(selectedSong); }
    {char price; price = (char)(selectedSong); }
    {void * tlv4; tlv4 = (void *)(selectedSong); }
    {void * tlv3; tlv3 = (void *)(selectedSong); }
    {cgc_size_t tlv2; tlv2 = (cgc_size_t)(selectedSong); }
    {int tlv7; tlv7 = (int)(selectedSong); }
    {cgc_size_t tlv5; tlv5 = (cgc_size_t)(selectedSong); }
    {int tlv10; tlv10 = (int)(selectedSong); }
    {cgc_size_t tlv8; tlv8 = (cgc_size_t)(selectedSong); }
    {unsigned int tlv11; tlv11 = (unsigned int)(selectedSong); }
    {unsigned int tlv12; tlv12 = (unsigned int)(selectedSong); }
}
void fix_ingred_service_13_3_2(){
Song selectedSong_ref;
    bzero(&selectedSong_ref,1*sizeof(Song));
Song * selectedSong = &selectedSong_ref;
    {int ret; ret = (int)(RESULT_VALUE_SIZE * 3); }
    {char price; price = (char)(RESULT_VALUE_SIZE * 3); }
    {void * tlv4; tlv4 = (void *)(RESULT_VALUE_SIZE * 3); }
    {void * tlv3; tlv3 = (void *)(RESULT_VALUE_SIZE * 3); }
    {cgc_size_t tlv2; tlv2 = (cgc_size_t)(RESULT_VALUE_SIZE * 3); }
    {int tlv7; tlv7 = (int)(RESULT_VALUE_SIZE * 3); }
    {cgc_size_t tlv5; tlv5 = (cgc_size_t)(RESULT_VALUE_SIZE * 3); }
    {int tlv10; tlv10 = (int)(RESULT_VALUE_SIZE * 3); }
    {cgc_size_t tlv8; tlv8 = (cgc_size_t)(RESULT_VALUE_SIZE * 3); }
    {unsigned int tlv11; tlv11 = (unsigned int)(RESULT_VALUE_SIZE * 3); }
    {unsigned int tlv12; tlv12 = (unsigned int)(RESULT_VALUE_SIZE * 3); }
}
void fix_ingred_service_13_3(){
fix_ingred_service_13_3_1();
fix_ingred_service_13_3_2();
}
void fix_ingred_service_13_4_0(){
int socket;
    bzero(&socket,sizeof(int));
    {char price; price = (char)(socket); }
    {void * tlv4; tlv4 = (void *)(socket); }
    {void * tlv3; tlv3 = (void *)(socket); }
    {int tlv7; tlv7 = (int)(socket); }
    {cgc_size_t tlv5; tlv5 = (cgc_size_t)(socket); }
    {int tlv10; tlv10 = (int)(socket); }
    {cgc_size_t tlv8; tlv8 = (cgc_size_t)(socket); }
    {unsigned int tlv11; tlv11 = (unsigned int)(socket); }
    {unsigned int tlv12; tlv12 = (unsigned int)(socket); }
}
void fix_ingred_service_13_4(){
fix_ingred_service_13_4_0();
}
void fix_ingred_service_13_5_0(){
char tlv13_ref;
    bzero(&tlv13_ref,1*sizeof(char));
const char * tlv13 = &tlv13_ref;
    {int ret; ret = (int)(cgc_strlen ( tlv13 )); }
    {char price; price = (char)(cgc_strlen ( tlv13 )); }
    {void * tlv4; tlv4 = (void *)(cgc_strlen ( tlv13 )); }
    {void * tlv3; tlv3 = (void *)(cgc_strlen ( tlv13 )); }
    {cgc_size_t tlv2; tlv2 = (cgc_size_t)(cgc_strlen ( tlv13 )); }
    {int tlv7; tlv7 = (int)(cgc_strlen ( tlv13 )); }
    {cgc_size_t tlv5; tlv5 = (cgc_size_t)(cgc_strlen ( tlv13 )); }
    {int tlv10; tlv10 = (int)(cgc_strlen ( tlv13 )); }
    {cgc_size_t tlv8; tlv8 = (cgc_size_t)(cgc_strlen ( tlv13 )); }
    {unsigned int tlv11; tlv11 = (unsigned int)(cgc_strlen ( tlv13 )); }
    {unsigned int tlv12; tlv12 = (unsigned int)(cgc_strlen ( tlv13 )); }
}
void fix_ingred_service_13_5(){
fix_ingred_service_13_5_0();
}
void fix_ingred_service_13_6_5(){
int ret;
    bzero(&ret,sizeof(int));
    {char price; price = (char)(ret); }
    {void * tlv4; tlv4 = (void *)(ret); }
    {int tlv7; tlv7 = (int)(ret); }
    {cgc_size_t tlv5; tlv5 = (cgc_size_t)(ret); }
    {int tlv10; tlv10 = (int)(ret); }
    {cgc_size_t tlv8; tlv8 = (cgc_size_t)(ret); }
    {unsigned int tlv11; tlv11 = (unsigned int)(ret); }
    {unsigned int tlv12; tlv12 = (unsigned int)(ret); }
}
void fix_ingred_service_13_6(){
fix_ingred_service_13_6_5();
}
void fix_ingred_service_13_7_0(){
    {char price; price = (char)(10); }
    {void * tlv4; tlv4 = (void *)(10); }
    {void * tlv3; tlv3 = (void *)(10); }
    {int tlv7; tlv7 = (int)(10); }
    {cgc_size_t tlv5; tlv5 = (cgc_size_t)(10); }
    {int tlv10; tlv10 = (int)(10); }
    {cgc_size_t tlv8; tlv8 = (cgc_size_t)(10); }
    {unsigned int tlv11; tlv11 = (unsigned int)(10); }
    {unsigned int tlv12; tlv12 = (unsigned int)(10); }
}
void fix_ingred_service_13_7(){
fix_ingred_service_13_7_0();
}
void fix_ingred_service_13_9_0(){
const char tlv14 [0];
    bzero(&tlv14 [0],sizeof(char));
    {int ret; ret = (int)(cgc_strlen ( tlv14 )); }
    {char price; price = (char)(cgc_strlen ( tlv14 )); }
    {void * tlv4; tlv4 = (void *)(cgc_strlen ( tlv14 )); }
    {void * tlv3; tlv3 = (void *)(cgc_strlen ( tlv14 )); }
    {cgc_size_t tlv2; tlv2 = (cgc_size_t)(cgc_strlen ( tlv14 )); }
    {int tlv7; tlv7 = (int)(cgc_strlen ( tlv14 )); }
    {cgc_size_t tlv5; tlv5 = (cgc_size_t)(cgc_strlen ( tlv14 )); }
    {int tlv10; tlv10 = (int)(cgc_strlen ( tlv14 )); }
    {cgc_size_t tlv8; tlv8 = (cgc_size_t)(cgc_strlen ( tlv14 )); }
    {unsigned int tlv11; tlv11 = (unsigned int)(cgc_strlen ( tlv14 )); }
    {unsigned int tlv12; tlv12 = (unsigned int)(cgc_strlen ( tlv14 )); }
}
void fix_ingred_service_13_9(){
fix_ingred_service_13_9_0();
}
void fix_ingred_service_13(){
fix_ingred_service_13_0();
fix_ingred_service_13_3();
fix_ingred_service_13_4();
fix_ingred_service_13_5();
fix_ingred_service_13_6();
fix_ingred_service_13_7();
fix_ingred_service_13_9();
}
void fix_ingred_service_14_0_0(){
    {char * search_string; search_string = (char *)(0); }
}
void fix_ingred_service_14_0_1(){
    {char * search_string; search_string = (char *)(NULL); }
    {unsigned int tlv5; tlv5 = (unsigned int)(NULL); }
}
void fix_ingred_service_14_0(){
fix_ingred_service_14_0_0();
fix_ingred_service_14_0_1();
}
void fix_ingred_service_14_2_0(){
int socket;
    bzero(&socket,sizeof(int));
    {char * search_string; search_string = (char *)(socket); }
}
void fix_ingred_service_14_2(){
fix_ingred_service_14_2_0();
}
void fix_ingred_service_14_3_0(){
char tlv6_ref;
    bzero(&tlv6_ref,1*sizeof(char));
const char * tlv6 = &tlv6_ref;
    {int ret; ret = (int)(cgc_strlen ( tlv6 )); }
    {char * search_string; search_string = (char *)(cgc_strlen ( tlv6 )); }
    {int tlv4; tlv4 = (int)(cgc_strlen ( tlv6 )); }
    {cgc_size_t tlv2; tlv2 = (cgc_size_t)(cgc_strlen ( tlv6 )); }
    {unsigned int tlv5; tlv5 = (unsigned int)(cgc_strlen ( tlv6 )); }
}
void fix_ingred_service_14_3(){
fix_ingred_service_14_3_0();
}
void fix_ingred_service_14_4_2(){
int ret;
    bzero(&ret,sizeof(int));
    {char * search_string; search_string = (char *)(ret); }
}
void fix_ingred_service_14_4(){
fix_ingred_service_14_4_2();
}
void fix_ingred_service_14_5_0(){
    {int ret; ret = (int)(4); }
    {char * search_string; search_string = (char *)(4); }
    {int tlv4; tlv4 = (int)(4); }
    {cgc_size_t tlv2; tlv2 = (cgc_size_t)(4); }
    {unsigned int tlv5; tlv5 = (unsigned int)(4); }
}
void fix_ingred_service_14_5(){
fix_ingred_service_14_5_0();
}
void fix_ingred_service_14(){
fix_ingred_service_14_0();
fix_ingred_service_14_2();
fix_ingred_service_14_3();
fix_ingred_service_14_4();
fix_ingred_service_14_5();
}
void fix_ingred_service_15_0_0(){
    {cgc_size_t size; size = (cgc_size_t)(0); }
    {char * gift_card; gift_card = (char *)(0); }
    {char * buffer; buffer = (char *)(0); }
    {cgc_size_t tlv13; tlv13 = (cgc_size_t)(0); }
    {int tlv12; tlv12 = (int)(0); }
    {int tlv2; tlv2 = (int)(0); }
    {cgc_size_t tlv1; tlv1 = (cgc_size_t)(0); }
    {char * tlv5; tlv5 = (char *)(0); }
    {char * tlv7; tlv7 = (char *)(0); }
    {char * tlv9; tlv9 = (char *)(0); }
    {void * tlv15; tlv15 = (void *)(0); }
    {cgc_size_t tlv14; tlv14 = (cgc_size_t)(0); }
    {int tlv18; tlv18 = (int)(0); }
    {cgc_size_t tlv16; tlv16 = (cgc_size_t)(0); }
    {void * tlv20; tlv20 = (void *)(0); }
    {cgc_size_t tlv19; tlv19 = (cgc_size_t)(0); }
    {int tlv21; tlv21 = (int)(0); }
    {cgc_size_t tlv24; tlv24 = (cgc_size_t)(0); }
    {int tlv23; tlv23 = (int)(0); }
    {unsigned int tlv25; tlv25 = (unsigned int)(0); }
    {unsigned int tlv26; tlv26 = (unsigned int)(0); }
    {unsigned int tlv27; tlv27 = (unsigned int)(0); }
    {unsigned int tlv28; tlv28 = (unsigned int)(0); }
    {unsigned int tlv29; tlv29 = (unsigned int)(0); }
}
void fix_ingred_service_15_0_1(){
    {cgc_size_t size; size = (cgc_size_t)(NULL); }
    {char * gift_card; gift_card = (char *)(NULL); }
    {cgc_size_t tlv13; tlv13 = (cgc_size_t)(NULL); }
    {int tlv12; tlv12 = (int)(NULL); }
    {void * tlv15; tlv15 = (void *)(NULL); }
    {cgc_size_t tlv14; tlv14 = (cgc_size_t)(NULL); }
    {int tlv18; tlv18 = (int)(NULL); }
    {cgc_size_t tlv16; tlv16 = (cgc_size_t)(NULL); }
    {void * tlv20; tlv20 = (void *)(NULL); }
    {cgc_size_t tlv19; tlv19 = (cgc_size_t)(NULL); }
    {int tlv21; tlv21 = (int)(NULL); }
    {cgc_size_t tlv24; tlv24 = (cgc_size_t)(NULL); }
    {int tlv23; tlv23 = (int)(NULL); }
    {unsigned int tlv25; tlv25 = (unsigned int)(NULL); }
    {unsigned int tlv26; tlv26 = (unsigned int)(NULL); }
    {unsigned int tlv27; tlv27 = (unsigned int)(NULL); }
    {unsigned int tlv28; tlv28 = (unsigned int)(NULL); }
    {unsigned int tlv29; tlv29 = (unsigned int)(NULL); }
}
void fix_ingred_service_15_0_3(){
    {cgc_size_t size; size = (cgc_size_t)(0); }
    {char * gift_card; gift_card = (char *)(0); }
    {cgc_size_t tlv13; tlv13 = (cgc_size_t)(0); }
    {int tlv12; tlv12 = (int)(0); }
    {void * tlv15; tlv15 = (void *)(0); }
    {cgc_size_t tlv14; tlv14 = (cgc_size_t)(0); }
    {int tlv18; tlv18 = (int)(0); }
    {cgc_size_t tlv16; tlv16 = (cgc_size_t)(0); }
    {void * tlv20; tlv20 = (void *)(0); }
    {cgc_size_t tlv19; tlv19 = (cgc_size_t)(0); }
    {int tlv21; tlv21 = (int)(0); }
    {cgc_size_t tlv24; tlv24 = (cgc_size_t)(0); }
    {int tlv23; tlv23 = (int)(0); }
    {unsigned int tlv25; tlv25 = (unsigned int)(0); }
    {unsigned int tlv26; tlv26 = (unsigned int)(0); }
    {unsigned int tlv27; tlv27 = (unsigned int)(0); }
    {unsigned int tlv28; tlv28 = (unsigned int)(0); }
    {unsigned int tlv29; tlv29 = (unsigned int)(0); }
}
void fix_ingred_service_15_0(){
fix_ingred_service_15_0_0();
fix_ingred_service_15_0_1();
fix_ingred_service_15_0_3();
}
void fix_ingred_service_15_2_0(){
cgc_size_t size;
    bzero(&size,sizeof(cgc_size_t));
    {char * gift_card; gift_card = (char *)(size + sizeof ( "ID=" ) + sizeof ( "\n" ) + 1); }
    {char * buffer; buffer = (char *)(size + sizeof ( "ID=" ) + sizeof ( "\n" ) + 1); }
    {int ret; ret = (int)(size + sizeof ( "ID=" ) + sizeof ( "\n" ) + 1); }
    {cgc_size_t tlv13; tlv13 = (cgc_size_t)(size + sizeof ( "ID=" ) + sizeof ( "\n" ) + 1); }
    {int tlv12; tlv12 = (int)(size + sizeof ( "ID=" ) + sizeof ( "\n" ) + 1); }
    {void * tlv3; tlv3 = (void *)(size + sizeof ( "ID=" ) + sizeof ( "\n" ) + 1); }
    {int tlv2; tlv2 = (int)(size + sizeof ( "ID=" ) + sizeof ( "\n" ) + 1); }
    {cgc_size_t tlv1; tlv1 = (cgc_size_t)(size + sizeof ( "ID=" ) + sizeof ( "\n" ) + 1); }
    {char * tlv5; tlv5 = (char *)(size + sizeof ( "ID=" ) + sizeof ( "\n" ) + 1); }
    {char * tlv7; tlv7 = (char *)(size + sizeof ( "ID=" ) + sizeof ( "\n" ) + 1); }
    {char * tlv9; tlv9 = (char *)(size + sizeof ( "ID=" ) + sizeof ( "\n" ) + 1); }
    {void * tlv15; tlv15 = (void *)(size + sizeof ( "ID=" ) + sizeof ( "\n" ) + 1); }
    {cgc_size_t tlv14; tlv14 = (cgc_size_t)(size + sizeof ( "ID=" ) + sizeof ( "\n" ) + 1); }
    {int tlv18; tlv18 = (int)(size + sizeof ( "ID=" ) + sizeof ( "\n" ) + 1); }
    {cgc_size_t tlv16; tlv16 = (cgc_size_t)(size + sizeof ( "ID=" ) + sizeof ( "\n" ) + 1); }
    {void * tlv20; tlv20 = (void *)(size + sizeof ( "ID=" ) + sizeof ( "\n" ) + 1); }
    {cgc_size_t tlv19; tlv19 = (cgc_size_t)(size + sizeof ( "ID=" ) + sizeof ( "\n" ) + 1); }
    {int tlv21; tlv21 = (int)(size + sizeof ( "ID=" ) + sizeof ( "\n" ) + 1); }
    {cgc_size_t tlv24; tlv24 = (cgc_size_t)(size + sizeof ( "ID=" ) + sizeof ( "\n" ) + 1); }
    {int tlv23; tlv23 = (int)(size + sizeof ( "ID=" ) + sizeof ( "\n" ) + 1); }
    {unsigned int tlv25; tlv25 = (unsigned int)(size + sizeof ( "ID=" ) + sizeof ( "\n" ) + 1); }
    {unsigned int tlv26; tlv26 = (unsigned int)(size + sizeof ( "ID=" ) + sizeof ( "\n" ) + 1); }
    {unsigned int tlv27; tlv27 = (unsigned int)(size + sizeof ( "ID=" ) + sizeof ( "\n" ) + 1); }
    {unsigned int tlv28; tlv28 = (unsigned int)(size + sizeof ( "ID=" ) + sizeof ( "\n" ) + 1); }
    {unsigned int tlv29; tlv29 = (unsigned int)(size + sizeof ( "ID=" ) + sizeof ( "\n" ) + 1); }
}
void fix_ingred_service_15_2(){
fix_ingred_service_15_2_0();
}
void fix_ingred_service_15_3_4(){
int ret;
    bzero(&ret,sizeof(int));
    {cgc_size_t size; size = (cgc_size_t)(ret); }
    {char * gift_card; gift_card = (char *)(ret); }
    {cgc_size_t tlv13; tlv13 = (cgc_size_t)(ret); }
    {int tlv12; tlv12 = (int)(ret); }
    {void * tlv15; tlv15 = (void *)(ret); }
    {cgc_size_t tlv14; tlv14 = (cgc_size_t)(ret); }
    {int tlv18; tlv18 = (int)(ret); }
    {cgc_size_t tlv16; tlv16 = (cgc_size_t)(ret); }
    {void * tlv20; tlv20 = (void *)(ret); }
    {cgc_size_t tlv19; tlv19 = (cgc_size_t)(ret); }
    {int tlv21; tlv21 = (int)(ret); }
    {cgc_size_t tlv24; tlv24 = (cgc_size_t)(ret); }
    {int tlv23; tlv23 = (int)(ret); }
    {unsigned int tlv25; tlv25 = (unsigned int)(ret); }
    {unsigned int tlv26; tlv26 = (unsigned int)(ret); }
    {unsigned int tlv27; tlv27 = (unsigned int)(ret); }
    {unsigned int tlv28; tlv28 = (unsigned int)(ret); }
    {unsigned int tlv29; tlv29 = (unsigned int)(ret); }
}
void fix_ingred_service_15_3(){
fix_ingred_service_15_3_4();
}
void fix_ingred_service_15_4_0(){
    {cgc_size_t size; size = (cgc_size_t)(3); }
    {char * gift_card; gift_card = (char *)(3); }
    {cgc_size_t tlv13; tlv13 = (cgc_size_t)(3); }
    {int tlv12; tlv12 = (int)(3); }
    {void * tlv15; tlv15 = (void *)(3); }
    {cgc_size_t tlv14; tlv14 = (cgc_size_t)(3); }
    {int tlv18; tlv18 = (int)(3); }
    {cgc_size_t tlv16; tlv16 = (cgc_size_t)(3); }
    {void * tlv20; tlv20 = (void *)(3); }
    {cgc_size_t tlv19; tlv19 = (cgc_size_t)(3); }
    {int tlv21; tlv21 = (int)(3); }
    {cgc_size_t tlv24; tlv24 = (cgc_size_t)(3); }
    {int tlv23; tlv23 = (int)(3); }
    {unsigned int tlv25; tlv25 = (unsigned int)(3); }
    {unsigned int tlv26; tlv26 = (unsigned int)(3); }
    {unsigned int tlv27; tlv27 = (unsigned int)(3); }
    {unsigned int tlv28; tlv28 = (unsigned int)(3); }
    {unsigned int tlv29; tlv29 = (unsigned int)(3); }
}
void fix_ingred_service_15_4(){
fix_ingred_service_15_4_0();
}
void fix_ingred_service_15_5_0(){
char buffer_ref;
    bzero(&buffer_ref,1*sizeof(char));
char * buffer = &buffer_ref;
    {cgc_size_t size; size = (cgc_size_t)(buffer); }
    {char * gift_card; gift_card = (char *)(buffer); }
    {cgc_size_t tlv13; tlv13 = (cgc_size_t)(buffer); }
    {int tlv12; tlv12 = (int)(buffer); }
    {void * tlv15; tlv15 = (void *)(buffer); }
    {cgc_size_t tlv14; tlv14 = (cgc_size_t)(buffer); }
    {int tlv18; tlv18 = (int)(buffer); }
    {cgc_size_t tlv16; tlv16 = (cgc_size_t)(buffer); }
    {void * tlv20; tlv20 = (void *)(buffer); }
    {cgc_size_t tlv19; tlv19 = (cgc_size_t)(buffer); }
    {int tlv21; tlv21 = (int)(buffer); }
    {cgc_size_t tlv24; tlv24 = (cgc_size_t)(buffer); }
    {int tlv23; tlv23 = (int)(buffer); }
    {unsigned int tlv25; tlv25 = (unsigned int)(buffer); }
    {unsigned int tlv26; tlv26 = (unsigned int)(buffer); }
    {unsigned int tlv27; tlv27 = (unsigned int)(buffer); }
    {unsigned int tlv28; tlv28 = (unsigned int)(buffer); }
    {unsigned int tlv29; tlv29 = (unsigned int)(buffer); }
}
void fix_ingred_service_15_5(){
fix_ingred_service_15_5_0();
}
void fix_ingred_service_15_6_0(){
char buffer_ref;
    bzero(&buffer_ref,1*sizeof(char));
char * buffer = &buffer_ref;
    {cgc_size_t size; size = (cgc_size_t)(buffer); }
    {char * gift_card; gift_card = (char *)(buffer); }
    {cgc_size_t tlv13; tlv13 = (cgc_size_t)(buffer); }
    {int tlv12; tlv12 = (int)(buffer); }
    {void * tlv15; tlv15 = (void *)(buffer); }
    {cgc_size_t tlv14; tlv14 = (cgc_size_t)(buffer); }
    {int tlv18; tlv18 = (int)(buffer); }
    {cgc_size_t tlv16; tlv16 = (cgc_size_t)(buffer); }
    {void * tlv20; tlv20 = (void *)(buffer); }
    {cgc_size_t tlv19; tlv19 = (cgc_size_t)(buffer); }
    {int tlv21; tlv21 = (int)(buffer); }
    {cgc_size_t tlv24; tlv24 = (cgc_size_t)(buffer); }
    {int tlv23; tlv23 = (int)(buffer); }
    {unsigned int tlv25; tlv25 = (unsigned int)(buffer); }
    {unsigned int tlv26; tlv26 = (unsigned int)(buffer); }
    {unsigned int tlv27; tlv27 = (unsigned int)(buffer); }
    {unsigned int tlv28; tlv28 = (unsigned int)(buffer); }
    {unsigned int tlv29; tlv29 = (unsigned int)(buffer); }
}
void fix_ingred_service_15_6(){
fix_ingred_service_15_6_0();
}
void fix_ingred_service_15_9_0(){
char gift_card_ref;
    bzero(&gift_card_ref,1*sizeof(char));
char * gift_card = &gift_card_ref;
cgc_size_t size;
    bzero(&size,sizeof(cgc_size_t));
    {cgc_size_t size; size = (cgc_size_t)(gift_card); }
    {char * buffer; buffer = (char *)(gift_card); }
    {int ret; ret = (int)(gift_card); }
    {cgc_size_t tlv13; tlv13 = (cgc_size_t)(gift_card); }
    {int tlv12; tlv12 = (int)(gift_card); }
    {void * tlv3; tlv3 = (void *)(gift_card); }
    {int tlv2; tlv2 = (int)(gift_card); }
    {cgc_size_t tlv1; tlv1 = (cgc_size_t)(gift_card); }
    {char * tlv5; tlv5 = (char *)(gift_card); }
    {char * tlv7; tlv7 = (char *)(gift_card); }
    {char * tlv9; tlv9 = (char *)(gift_card); }
    {void * tlv15; tlv15 = (void *)(gift_card); }
    {cgc_size_t tlv14; tlv14 = (cgc_size_t)(gift_card); }
    {int tlv18; tlv18 = (int)(gift_card); }
    {cgc_size_t tlv16; tlv16 = (cgc_size_t)(gift_card); }
    {void * tlv20; tlv20 = (void *)(gift_card); }
    {cgc_size_t tlv19; tlv19 = (cgc_size_t)(gift_card); }
    {int tlv21; tlv21 = (int)(gift_card); }
    {cgc_size_t tlv24; tlv24 = (cgc_size_t)(gift_card); }
    {int tlv23; tlv23 = (int)(gift_card); }
    {unsigned int tlv25; tlv25 = (unsigned int)(gift_card); }
    {unsigned int tlv26; tlv26 = (unsigned int)(gift_card); }
    {unsigned int tlv27; tlv27 = (unsigned int)(gift_card); }
    {unsigned int tlv28; tlv28 = (unsigned int)(gift_card); }
    {unsigned int tlv29; tlv29 = (unsigned int)(gift_card); }
}
void fix_ingred_service_15_9_1(){
char gift_card_ref;
    bzero(&gift_card_ref,1*sizeof(char));
char * gift_card = &gift_card_ref;
cgc_size_t size;
    bzero(&size,sizeof(cgc_size_t));
    {char * gift_card; gift_card = (char *)(size); }
    {char * buffer; buffer = (char *)(size); }
    {int ret; ret = (int)(size); }
    {cgc_size_t tlv13; tlv13 = (cgc_size_t)(size); }
    {int tlv12; tlv12 = (int)(size); }
    {void * tlv3; tlv3 = (void *)(size); }
    {int tlv2; tlv2 = (int)(size); }
    {cgc_size_t tlv1; tlv1 = (cgc_size_t)(size); }
    {char * tlv5; tlv5 = (char *)(size); }
    {char * tlv7; tlv7 = (char *)(size); }
    {char * tlv9; tlv9 = (char *)(size); }
    {void * tlv15; tlv15 = (void *)(size); }
    {cgc_size_t tlv14; tlv14 = (cgc_size_t)(size); }
    {int tlv18; tlv18 = (int)(size); }
    {cgc_size_t tlv16; tlv16 = (cgc_size_t)(size); }
    {void * tlv20; tlv20 = (void *)(size); }
    {cgc_size_t tlv19; tlv19 = (cgc_size_t)(size); }
    {int tlv21; tlv21 = (int)(size); }
    {cgc_size_t tlv24; tlv24 = (cgc_size_t)(size); }
    {int tlv23; tlv23 = (int)(size); }
    {unsigned int tlv25; tlv25 = (unsigned int)(size); }
    {unsigned int tlv26; tlv26 = (unsigned int)(size); }
    {unsigned int tlv27; tlv27 = (unsigned int)(size); }
    {unsigned int tlv28; tlv28 = (unsigned int)(size); }
    {unsigned int tlv29; tlv29 = (unsigned int)(size); }
}
void fix_ingred_service_15_9(){
fix_ingred_service_15_9_0();
fix_ingred_service_15_9_1();
}
void fix_ingred_service_15_12_0(){
    {cgc_size_t size; size = (cgc_size_t)(STDOUT); }
    {char * gift_card; gift_card = (char *)(STDOUT); }
    {char * buffer; buffer = (char *)(STDOUT); }
    {int ret; ret = (int)(STDOUT); }
    {cgc_size_t tlv13; tlv13 = (cgc_size_t)(STDOUT); }
    {int tlv12; tlv12 = (int)(STDOUT); }
    {void * tlv3; tlv3 = (void *)(STDOUT); }
    {int tlv2; tlv2 = (int)(STDOUT); }
    {cgc_size_t tlv1; tlv1 = (cgc_size_t)(STDOUT); }
    {char * tlv5; tlv5 = (char *)(STDOUT); }
    {char * tlv7; tlv7 = (char *)(STDOUT); }
    {char * tlv9; tlv9 = (char *)(STDOUT); }
    {void * tlv15; tlv15 = (void *)(STDOUT); }
    {cgc_size_t tlv14; tlv14 = (cgc_size_t)(STDOUT); }
    {int tlv18; tlv18 = (int)(STDOUT); }
    {cgc_size_t tlv16; tlv16 = (cgc_size_t)(STDOUT); }
    {void * tlv20; tlv20 = (void *)(STDOUT); }
    {cgc_size_t tlv19; tlv19 = (cgc_size_t)(STDOUT); }
    {int tlv21; tlv21 = (int)(STDOUT); }
    {cgc_size_t tlv24; tlv24 = (cgc_size_t)(STDOUT); }
    {int tlv23; tlv23 = (int)(STDOUT); }
    {unsigned int tlv25; tlv25 = (unsigned int)(STDOUT); }
    {unsigned int tlv26; tlv26 = (unsigned int)(STDOUT); }
    {unsigned int tlv27; tlv27 = (unsigned int)(STDOUT); }
    {unsigned int tlv28; tlv28 = (unsigned int)(STDOUT); }
    {unsigned int tlv29; tlv29 = (unsigned int)(STDOUT); }
}
void fix_ingred_service_15_12(){
fix_ingred_service_15_12_0();
}
void fix_ingred_service_15_13_0(){
char tlv30_ref;
    bzero(&tlv30_ref,1*sizeof(char));
const char * tlv30 = &tlv30_ref;
    {cgc_size_t size; size = (cgc_size_t)(cgc_strlen ( tlv30 )); }
    {char * gift_card; gift_card = (char *)(cgc_strlen ( tlv30 )); }
    {char * buffer; buffer = (char *)(cgc_strlen ( tlv30 )); }
    {int ret; ret = (int)(cgc_strlen ( tlv30 )); }
    {cgc_size_t tlv13; tlv13 = (cgc_size_t)(cgc_strlen ( tlv30 )); }
    {int tlv12; tlv12 = (int)(cgc_strlen ( tlv30 )); }
    {void * tlv3; tlv3 = (void *)(cgc_strlen ( tlv30 )); }
    {int tlv2; tlv2 = (int)(cgc_strlen ( tlv30 )); }
    {cgc_size_t tlv1; tlv1 = (cgc_size_t)(cgc_strlen ( tlv30 )); }
    {char * tlv5; tlv5 = (char *)(cgc_strlen ( tlv30 )); }
    {char * tlv7; tlv7 = (char *)(cgc_strlen ( tlv30 )); }
    {char * tlv9; tlv9 = (char *)(cgc_strlen ( tlv30 )); }
    {void * tlv15; tlv15 = (void *)(cgc_strlen ( tlv30 )); }
    {cgc_size_t tlv14; tlv14 = (cgc_size_t)(cgc_strlen ( tlv30 )); }
    {int tlv18; tlv18 = (int)(cgc_strlen ( tlv30 )); }
    {cgc_size_t tlv16; tlv16 = (cgc_size_t)(cgc_strlen ( tlv30 )); }
    {void * tlv20; tlv20 = (void *)(cgc_strlen ( tlv30 )); }
    {cgc_size_t tlv19; tlv19 = (cgc_size_t)(cgc_strlen ( tlv30 )); }
    {int tlv21; tlv21 = (int)(cgc_strlen ( tlv30 )); }
    {cgc_size_t tlv24; tlv24 = (cgc_size_t)(cgc_strlen ( tlv30 )); }
    {int tlv23; tlv23 = (int)(cgc_strlen ( tlv30 )); }
    {unsigned int tlv25; tlv25 = (unsigned int)(cgc_strlen ( tlv30 )); }
    {unsigned int tlv26; tlv26 = (unsigned int)(cgc_strlen ( tlv30 )); }
    {unsigned int tlv27; tlv27 = (unsigned int)(cgc_strlen ( tlv30 )); }
    {unsigned int tlv28; tlv28 = (unsigned int)(cgc_strlen ( tlv30 )); }
    {unsigned int tlv29; tlv29 = (unsigned int)(cgc_strlen ( tlv30 )); }
}
void fix_ingred_service_15_13(){
fix_ingred_service_15_13_0();
}
void fix_ingred_service_15_15_0(){
    {cgc_size_t size; size = (cgc_size_t)(10); }
    {char * gift_card; gift_card = (char *)(10); }
    {char * buffer; buffer = (char *)(10); }
    {cgc_size_t tlv13; tlv13 = (cgc_size_t)(10); }
    {int tlv12; tlv12 = (int)(10); }
    {int tlv2; tlv2 = (int)(10); }
    {cgc_size_t tlv1; tlv1 = (cgc_size_t)(10); }
    {char * tlv5; tlv5 = (char *)(10); }
    {char * tlv9; tlv9 = (char *)(10); }
    {void * tlv15; tlv15 = (void *)(10); }
    {cgc_size_t tlv14; tlv14 = (cgc_size_t)(10); }
    {int tlv18; tlv18 = (int)(10); }
    {cgc_size_t tlv16; tlv16 = (cgc_size_t)(10); }
    {void * tlv20; tlv20 = (void *)(10); }
    {cgc_size_t tlv19; tlv19 = (cgc_size_t)(10); }
    {int tlv21; tlv21 = (int)(10); }
    {cgc_size_t tlv24; tlv24 = (cgc_size_t)(10); }
    {int tlv23; tlv23 = (int)(10); }
    {unsigned int tlv25; tlv25 = (unsigned int)(10); }
    {unsigned int tlv26; tlv26 = (unsigned int)(10); }
    {unsigned int tlv27; tlv27 = (unsigned int)(10); }
    {unsigned int tlv28; tlv28 = (unsigned int)(10); }
    {unsigned int tlv29; tlv29 = (unsigned int)(10); }
}
void fix_ingred_service_15_15(){
fix_ingred_service_15_15_0();
}
void fix_ingred_service_15_19_0(){
    {cgc_size_t size; size = (cgc_size_t)(STDIN); }
    {char * gift_card; gift_card = (char *)(STDIN); }
    {char * buffer; buffer = (char *)(STDIN); }
    {int ret; ret = (int)(STDIN); }
    {cgc_size_t tlv13; tlv13 = (cgc_size_t)(STDIN); }
    {int tlv12; tlv12 = (int)(STDIN); }
    {void * tlv3; tlv3 = (void *)(STDIN); }
    {int tlv2; tlv2 = (int)(STDIN); }
    {cgc_size_t tlv1; tlv1 = (cgc_size_t)(STDIN); }
    {char * tlv5; tlv5 = (char *)(STDIN); }
    {char * tlv7; tlv7 = (char *)(STDIN); }
    {char * tlv9; tlv9 = (char *)(STDIN); }
    {void * tlv15; tlv15 = (void *)(STDIN); }
    {cgc_size_t tlv14; tlv14 = (cgc_size_t)(STDIN); }
    {int tlv18; tlv18 = (int)(STDIN); }
    {cgc_size_t tlv16; tlv16 = (cgc_size_t)(STDIN); }
    {void * tlv20; tlv20 = (void *)(STDIN); }
    {cgc_size_t tlv19; tlv19 = (cgc_size_t)(STDIN); }
    {int tlv21; tlv21 = (int)(STDIN); }
    {cgc_size_t tlv24; tlv24 = (cgc_size_t)(STDIN); }
    {int tlv23; tlv23 = (int)(STDIN); }
    {unsigned int tlv25; tlv25 = (unsigned int)(STDIN); }
    {unsigned int tlv26; tlv26 = (unsigned int)(STDIN); }
    {unsigned int tlv27; tlv27 = (unsigned int)(STDIN); }
    {unsigned int tlv28; tlv28 = (unsigned int)(STDIN); }
    {unsigned int tlv29; tlv29 = (unsigned int)(STDIN); }
}
void fix_ingred_service_15_19(){
fix_ingred_service_15_19_0();
}
void fix_ingred_service_15_20_0(){
SongList mySongList_ref;
    bzero(&mySongList_ref,1*sizeof(SongList));
SongList * mySongList = &mySongList_ref;
    {cgc_size_t size; size = (cgc_size_t)(sizeof ( Song ) * mySongList -> balance); }
    {char * gift_card; gift_card = (char *)(sizeof ( Song ) * mySongList -> balance); }
    {char * buffer; buffer = (char *)(sizeof ( Song ) * mySongList -> balance); }
    {int ret; ret = (int)(sizeof ( Song ) * mySongList -> balance); }
    {cgc_size_t tlv13; tlv13 = (cgc_size_t)(sizeof ( Song ) * mySongList -> balance); }
    {int tlv12; tlv12 = (int)(sizeof ( Song ) * mySongList -> balance); }
    {void * tlv3; tlv3 = (void *)(sizeof ( Song ) * mySongList -> balance); }
    {int tlv2; tlv2 = (int)(sizeof ( Song ) * mySongList -> balance); }
    {cgc_size_t tlv1; tlv1 = (cgc_size_t)(sizeof ( Song ) * mySongList -> balance); }
    {char * tlv5; tlv5 = (char *)(sizeof ( Song ) * mySongList -> balance); }
    {char * tlv7; tlv7 = (char *)(sizeof ( Song ) * mySongList -> balance); }
    {char * tlv9; tlv9 = (char *)(sizeof ( Song ) * mySongList -> balance); }
    {void * tlv15; tlv15 = (void *)(sizeof ( Song ) * mySongList -> balance); }
    {cgc_size_t tlv14; tlv14 = (cgc_size_t)(sizeof ( Song ) * mySongList -> balance); }
    {int tlv18; tlv18 = (int)(sizeof ( Song ) * mySongList -> balance); }
    {cgc_size_t tlv16; tlv16 = (cgc_size_t)(sizeof ( Song ) * mySongList -> balance); }
    {void * tlv20; tlv20 = (void *)(sizeof ( Song ) * mySongList -> balance); }
    {cgc_size_t tlv19; tlv19 = (cgc_size_t)(sizeof ( Song ) * mySongList -> balance); }
    {int tlv21; tlv21 = (int)(sizeof ( Song ) * mySongList -> balance); }
    {cgc_size_t tlv24; tlv24 = (cgc_size_t)(sizeof ( Song ) * mySongList -> balance); }
    {int tlv23; tlv23 = (int)(sizeof ( Song ) * mySongList -> balance); }
    {unsigned int tlv25; tlv25 = (unsigned int)(sizeof ( Song ) * mySongList -> balance); }
    {unsigned int tlv26; tlv26 = (unsigned int)(sizeof ( Song ) * mySongList -> balance); }
    {unsigned int tlv27; tlv27 = (unsigned int)(sizeof ( Song ) * mySongList -> balance); }
    {unsigned int tlv28; tlv28 = (unsigned int)(sizeof ( Song ) * mySongList -> balance); }
    {unsigned int tlv29; tlv29 = (unsigned int)(sizeof ( Song ) * mySongList -> balance); }
}
void fix_ingred_service_15_20(){
fix_ingred_service_15_20_0();
}
void fix_ingred_service_15(){
fix_ingred_service_15_0();
fix_ingred_service_15_2();
fix_ingred_service_15_3();
fix_ingred_service_15_4();
fix_ingred_service_15_5();
fix_ingred_service_15_6();
fix_ingred_service_15_9();
fix_ingred_service_15_12();
fix_ingred_service_15_13();
fix_ingred_service_15_15();
fix_ingred_service_15_19();
fix_ingred_service_15_20();
}
void fix_ingred_service_16(){
}
void fix_ingred_service_17_0_0(){
SongList mySongList;
    bzero(&mySongList,sizeof(SongList));
    {int starting_balance; starting_balance = (int)(0); }
    {int tlv6; tlv6 = (int)(0); }
    {int tlv9; tlv9 = (int)(0); }
    {int tlv15; tlv15 = (int)(0); }
    {unsigned int tlv10; tlv10 = (unsigned int)(0); }
}
void fix_ingred_service_17_0_4(){
SongList mySongList;
    bzero(&mySongList,sizeof(SongList));
    {int ret; ret = (int)(mySongList . balance); }
    {int starting_balance; starting_balance = (int)(mySongList . balance); }
    {void * tlv3; tlv3 = (void *)(mySongList . balance); }
    {cgc_size_t tlv2; tlv2 = (cgc_size_t)(mySongList . balance); }
    {int tlv6; tlv6 = (int)(mySongList . balance); }
    {int tlv9; tlv9 = (int)(mySongList . balance); }
    {int tlv7; tlv7 = (int)(mySongList . balance); }
    {int tlv15; tlv15 = (int)(mySongList . balance); }
    {unsigned int tlv10; tlv10 = (unsigned int)(mySongList . balance); }
}
void fix_ingred_service_17_0(){
fix_ingred_service_17_0_0();
fix_ingred_service_17_0_4();
}
void fix_ingred_service_17_4_0(){
    {int starting_balance; starting_balance = (int)(STDOUT); }
    {cgc_size_t tlv2; tlv2 = (cgc_size_t)(STDOUT); }
    {int tlv6; tlv6 = (int)(STDOUT); }
    {int tlv9; tlv9 = (int)(STDOUT); }
    {int tlv7; tlv7 = (int)(STDOUT); }
    {int tlv15; tlv15 = (int)(STDOUT); }
    {unsigned int tlv10; tlv10 = (unsigned int)(STDOUT); }
}
void fix_ingred_service_17_4(){
fix_ingred_service_17_4_0();
}
void fix_ingred_service_17_5_0(){
    {int starting_balance; starting_balance = (int)(STDIN); }
    {cgc_size_t tlv2; tlv2 = (cgc_size_t)(STDIN); }
    {int tlv6; tlv6 = (int)(STDIN); }
    {int tlv9; tlv9 = (int)(STDIN); }
    {int tlv7; tlv7 = (int)(STDIN); }
    {int tlv15; tlv15 = (int)(STDIN); }
    {unsigned int tlv10; tlv10 = (unsigned int)(STDIN); }
}
void fix_ingred_service_17_5_2(){
    {int ret; ret = (int)(RESULT_LIMIT); }
    {int starting_balance; starting_balance = (int)(RESULT_LIMIT); }
    {void * tlv3; tlv3 = (void *)(RESULT_LIMIT); }
    {cgc_size_t tlv2; tlv2 = (cgc_size_t)(RESULT_LIMIT); }
    {int tlv6; tlv6 = (int)(RESULT_LIMIT); }
    {int tlv9; tlv9 = (int)(RESULT_LIMIT); }
    {int tlv7; tlv7 = (int)(RESULT_LIMIT); }
    {int tlv15; tlv15 = (int)(RESULT_LIMIT); }
    {unsigned int tlv10; tlv10 = (unsigned int)(RESULT_LIMIT); }
}
void fix_ingred_service_17_5(){
fix_ingred_service_17_5_0();
fix_ingred_service_17_5_2();
}
void fix_ingred_service_17_8_8(){
int ret;
    bzero(&ret,sizeof(int));
    {int starting_balance; starting_balance = (int)(ret); }
    {int tlv6; tlv6 = (int)(ret); }
    {int tlv9; tlv9 = (int)(ret); }
    {int tlv15; tlv15 = (int)(ret); }
    {unsigned int tlv10; tlv10 = (unsigned int)(ret); }
}
void fix_ingred_service_17_8_9(){
int ret;
    bzero(&ret,sizeof(int));
    {int ret; ret = (int)(LOW_BALANCE); }
    {int starting_balance; starting_balance = (int)(LOW_BALANCE); }
    {void * tlv3; tlv3 = (void *)(LOW_BALANCE); }
    {cgc_size_t tlv2; tlv2 = (cgc_size_t)(LOW_BALANCE); }
    {int tlv6; tlv6 = (int)(LOW_BALANCE); }
    {int tlv9; tlv9 = (int)(LOW_BALANCE); }
    {int tlv7; tlv7 = (int)(LOW_BALANCE); }
    {int tlv15; tlv15 = (int)(LOW_BALANCE); }
    {unsigned int tlv10; tlv10 = (unsigned int)(LOW_BALANCE); }
}
void fix_ingred_service_17_8(){
fix_ingred_service_17_8_8();
fix_ingred_service_17_8_9();
}
void fix_ingred_service_17_9_0(){
SongList mySongList;
    bzero(&mySongList,sizeof(SongList));
Song songs [ RESULT_LIMIT ];
    bzero(&songs,( RESULT_LIMIT *sizeof(Song) ) );
int starting_balance;
    bzero(&starting_balance,sizeof(int));
    {int ret; ret = (int)(mySongList . songs); }
    {int starting_balance; starting_balance = (int)(mySongList . songs); }
    {void * tlv3; tlv3 = (void *)(mySongList . songs); }
    {cgc_size_t tlv2; tlv2 = (cgc_size_t)(mySongList . songs); }
    {int tlv6; tlv6 = (int)(mySongList . songs); }
    {int tlv9; tlv9 = (int)(mySongList . songs); }
    {int tlv7; tlv7 = (int)(mySongList . songs); }
    {int tlv15; tlv15 = (int)(mySongList . songs); }
    {unsigned int tlv10; tlv10 = (unsigned int)(mySongList . songs); }
}
void fix_ingred_service_17_9_1(){
SongList mySongList;
    bzero(&mySongList,sizeof(SongList));
Song songs [ RESULT_LIMIT ];
    bzero(&songs,( RESULT_LIMIT *sizeof(Song) ) );
int starting_balance;
    bzero(&starting_balance,sizeof(int));
    {int ret; ret = (int)(sizeof ( Song ) * starting_balance); }
    {void * tlv3; tlv3 = (void *)(sizeof ( Song ) * starting_balance); }
    {cgc_size_t tlv2; tlv2 = (cgc_size_t)(sizeof ( Song ) * starting_balance); }
    {int tlv6; tlv6 = (int)(sizeof ( Song ) * starting_balance); }
    {int tlv9; tlv9 = (int)(sizeof ( Song ) * starting_balance); }
    {int tlv7; tlv7 = (int)(sizeof ( Song ) * starting_balance); }
    {int tlv15; tlv15 = (int)(sizeof ( Song ) * starting_balance); }
    {unsigned int tlv10; tlv10 = (unsigned int)(sizeof ( Song ) * starting_balance); }
}
void fix_ingred_service_17_9(){
fix_ingred_service_17_9_0();
fix_ingred_service_17_9_1();
}
void fix_ingred_service_17_11_0(){
    {int starting_balance; starting_balance = (int)(3); }
    {cgc_size_t tlv2; tlv2 = (cgc_size_t)(3); }
    {int tlv6; tlv6 = (int)(3); }
    {int tlv9; tlv9 = (int)(3); }
    {int tlv7; tlv7 = (int)(3); }
    {int tlv15; tlv15 = (int)(3); }
    {unsigned int tlv10; tlv10 = (unsigned int)(3); }
}
void fix_ingred_service_17_11(){
fix_ingred_service_17_11_0();
}
void fix_ingred_service_17(){
fix_ingred_service_17_0();
fix_ingred_service_17_4();
fix_ingred_service_17_5();
fix_ingred_service_17_8();
fix_ingred_service_17_9();
fix_ingred_service_17_11();
}
