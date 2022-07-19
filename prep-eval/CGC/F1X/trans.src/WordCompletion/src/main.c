

#include "libcgc.h"
#include "cgc_words.h"
typedef unsigned int uint32_t;
#define PAGE_SIZE 4096
char gValidChars[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
#define VALID_CHARS_LEN (sizeof(gValidChars) - 1)
#define IS_VALID_CHAR(_c) ( ((_c >= 'a') && (_c <= 'z')) || ((_c >= 'A') && (_c <= 'Z')) || ((_c >= '0') && (_c <= '9')) )
#define NUM_WORDS (sizeof(gSeedWords) / sizeof(char*))
#define NUM_ROUNDS 10
#define ENTER_NUM_MSG "Please Enter a 2 Digit Number\n"
#define WORD_MSG "Word: "
#define LOSE_MSG "You Lose\n"
#define WIN_MSG "You Win!\n"
#define NEXT_WORD_MSG "Next Word: "
#define FINAL_RND_MSG "Final Round. Chose another 2 digit number\n"
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
void fix_ingred_main_0_1();
void fix_ingred_main_0_2_3();
void fix_ingred_main_0_2();
void fix_ingred_main_0();
cgc_size_t cgc_strlen(char *str)
{
if (fix_ingred_enable){ fix_ingred_main_0(); };
    cgc_size_t ret;
    ret = 0;
    if (str == NULL) {
	return (0);
    }
    for (ret = 0; str[ret] != '\0'; ret++) {
    }
    return (ret);
}

void fix_ingred_main_1_0_0();
void fix_ingred_main_1_0_2();
void fix_ingred_main_1_0();
void fix_ingred_main_1_1_3();
void fix_ingred_main_1_1_4();
void fix_ingred_main_1_1();
void fix_ingred_main_1_2_3();
void fix_ingred_main_1_2_4();
void fix_ingred_main_1_2();
void fix_ingred_main_1_3_0();
void fix_ingred_main_1_3();
void fix_ingred_main_1_4_0();
void fix_ingred_main_1_4_1();
void fix_ingred_main_1_4_2();
void fix_ingred_main_1_4();
void fix_ingred_main_1_5_3();
void fix_ingred_main_1_5();
void fix_ingred_main_1_6_0();
void fix_ingred_main_1_6();
void fix_ingred_main_1();
cgc_size_t cgc_transmit_all(char *buf, cgc_size_t size)
{
if (fix_ingred_enable){ fix_ingred_main_1(); };
    cgc_size_t rx_bytes;
    rx_bytes = 0;
    cgc_size_t total;
    total = 0;
    int ret;
    ret = 0;
    if (buf == NULL) {
	return (0);
    }

    do {
 {
     int tlv4;
     tlv4 = STDOUT;
     void* tlv3;
     tlv3 = buf;
     cgc_size_t tlv2;
     tlv2 = size - total;
     cgc_size_t* tlv1;
     tlv1 = & rx_bytes;
    	ret = cgc_transmit(tlv4,tlv3,tlv2,tlv1);
 }
	if ((ret != 0) || (rx_bytes == 0)) {
     {
         unsigned int tlv5;
         tlv5 = 1;
    	    cgc__terminate(tlv5);
     }
	}
	total += rx_bytes;
    }
    while (total < size);
    return (size);
}

void fix_ingred_main_2_1_0();
void fix_ingred_main_2_1_1();
void fix_ingred_main_2_1();
void fix_ingred_main_2();
cgc_size_t cgc_transmit_str(char *buf)
{
if (fix_ingred_enable){ fix_ingred_main_2(); };
    cgc_size_t len;
    {
        char* tlv1;
         tlv1 = buf;
        len = cgc_strlen(tlv1);
    }
    return (cgc_transmit_all(buf, len));
}

void fix_ingred_main_3_4_0();
void fix_ingred_main_3_4();
void fix_ingred_main_3();
cgc_size_t cgc_receive_all(char *buf, cgc_size_t size)
{
if (fix_ingred_enable){ fix_ingred_main_3(); };
    cgc_size_t rx_bytes;
    rx_bytes = 0;
    cgc_size_t total;
    total = 0;
    int ret;
    ret = 0;
    if (buf == NULL) {
	return (0);
    }

    do {
 {
     int tlv4;
     tlv4 = STDIN;
     void* tlv3;
     tlv3 = buf;
     cgc_size_t tlv2;
     tlv2 = size - total;
     cgc_size_t* tlv1;
     tlv1 = & rx_bytes;
    	ret = cgc_receive(tlv4,tlv3,tlv2,tlv1);
 }
	if ((ret != 0) || (rx_bytes == 0)) {
     {
         unsigned int tlv5;
         tlv5 = 1;
    	    cgc__terminate(tlv5);
     }
	}
	total += rx_bytes;
    }
    while (total < size);

    return (size);
}

void fix_ingred_main_4_0_0();
void fix_ingred_main_4_0_1();
void fix_ingred_main_4_0_2();
void fix_ingred_main_4_0();
void fix_ingred_main_4_1_0();
void fix_ingred_main_4_1_1();
void fix_ingred_main_4_1();
void fix_ingred_main_4_2_4();
void fix_ingred_main_4_2_5();
void fix_ingred_main_4_2_6();
void fix_ingred_main_4_2_7();
void fix_ingred_main_4_2();
void fix_ingred_main_4_4_0();
void fix_ingred_main_4_4_1();
void fix_ingred_main_4_4_2();
void fix_ingred_main_4_4();
void fix_ingred_main_4_5_4();
void fix_ingred_main_4_5_6();
void fix_ingred_main_4_5();
void fix_ingred_main_4_6_0();
void fix_ingred_main_4_6();
void fix_ingred_main_4();
cgc_size_t cgc_readline(char *buf, cgc_size_t len)
{
if (fix_ingred_enable){ fix_ingred_main_4(); };
    if (buf == NULL) {
	return (0);
    }
    cgc_size_t count;
    count = 0;
    int ret;
    ret = 0;
    char c;
    c = 0;
    cgc_size_t rx_bytes;
    rx_bytes = 0;
    do {
 {
     int tlv4;
     tlv4 = STDIN;
     void* tlv3;
     tlv3 = & c;
     cgc_size_t tlv2;
     tlv2 = 1;
     cgc_size_t* tlv1;
     tlv1 = & rx_bytes;
    	ret = cgc_receive(tlv4,tlv3,tlv2,tlv1);
 }
	if ((ret != 0) || (rx_bytes == 0)) {
     {
         unsigned int tlv5;
         tlv5 = 1;
    	    cgc__terminate(tlv5);
     }
	}
	buf[count] = c;
	count++;
    } while ((c != '\n') && (count < len));
    return (count);
}

void fix_ingred_main_5_0_0();
void fix_ingred_main_5_0_2();
void fix_ingred_main_5_0();
void fix_ingred_main_5_1_0();
void fix_ingred_main_5_1_3();
void fix_ingred_main_5_1_4();
void fix_ingred_main_5_1_6();
void fix_ingred_main_5_1();
void fix_ingred_main_5_3_0();
void fix_ingred_main_5_3_4();
void fix_ingred_main_5_3_6();
void fix_ingred_main_5_3();
void fix_ingred_main_5_5_0();
void fix_ingred_main_5_5_4();
void fix_ingred_main_5_5_6();
void fix_ingred_main_5_5();
void fix_ingred_main_5();
char cgc_rotN(char c, int n)
{
if (fix_ingred_enable){ fix_ingred_main_5(); };
    int temp;
    temp = 0;
    n = n % VALID_CHARS_LEN;
    if ((c >= 'a') && (c <= 'z')) {
	temp = c - 'a';
;		//temp is the offset
    } else {
	if ((c >= 'A') && (c <= 'Z')) {
	    temp = c - 'A' + 26;
	} else {
	    if ((c >= '0') && (c <= '9')) {
		temp = c - '0' + 52;
	    } else {
		return (c);
;	//no rotation
	    }
	}
    }
    temp += n;
    temp = temp % VALID_CHARS_LEN;
    return (gValidChars[temp]);
}

void fix_ingred_main_6_0_0();
void fix_ingred_main_6_0();
void fix_ingred_main_6_1_0();
void fix_ingred_main_6_1_1();
void fix_ingred_main_6_1_2();
void fix_ingred_main_6_1();
void fix_ingred_main_6_2_2();
void fix_ingred_main_6_2_3();
void fix_ingred_main_6_2();
void fix_ingred_main_6_3_0();
void fix_ingred_main_6_3_1();
void fix_ingred_main_6_3();
void fix_ingred_main_6();
cgc_size_t cgc_strrotcpy(char *dst, char *src, int rot)
{
if (fix_ingred_enable){ fix_ingred_main_6(); };
    if ((src == NULL) || (dst == NULL)) {
	return (0);
    }
    cgc_size_t ret;
    ret = 0;
    for (ret = 0; src[ret] != '\0'; ret++) {
 {
     char tlv2;
     tlv2 = src [ ret ];
     int tlv1;
     tlv1 = rot;
    	dst[ret] = cgc_rotN(tlv2,tlv1);
 }
    }
    dst[ret] = '\0';
    return (ret);
}

char **cgc_gWords = NULL;
char *cgc_gWordData = NULL;
void fix_ingred_main_7_0_0();
void fix_ingred_main_7_0_1();
void fix_ingred_main_7_0_2();
void fix_ingred_main_7_0_5();
void fix_ingred_main_7_0();
void fix_ingred_main_7_1_0();
void fix_ingred_main_7_1();
void fix_ingred_main_7_2_2();
void fix_ingred_main_7_2();
void fix_ingred_main_7_3_0();
void fix_ingred_main_7_3_6();
void fix_ingred_main_7_3_7();
void fix_ingred_main_7_3();
void fix_ingred_main_7_4_0();
void fix_ingred_main_7_4_1();
void fix_ingred_main_7_4();
void fix_ingred_main_7_5_0();
void fix_ingred_main_7_5();
void fix_ingred_main_7_7_1();
void fix_ingred_main_7_7();
void fix_ingred_main_7_8_0();
void fix_ingred_main_7_8_2();
void fix_ingred_main_7_8();
void fix_ingred_main_7();
int cgc_init(int rot)
{
if (fix_ingred_enable){ fix_ingred_main_7(); };
    int ret;
    ret = 0;
    cgc_size_t numWords;
    numWords = NUM_WORDS;
    //first allocate enough space for the wordlist
    {
        cgc_size_t tlv3;
        tlv3 = sizeof ( gSeedWords );
        int tlv2;
        tlv2 = 0;
        void** tlv1;
        tlv1 = ( void * * ) ( & cgc_gWords );
        ret = cgc_allocate(tlv3,tlv2,tlv1);
    }
    if (ret != 0) {
	return (ret);
    }
    //now calculate how many bytes we need to store the words themselves
    cgc_size_t total;
    total = 0;
    int i;
    i = 0;
    for (i = 0; i < numWords; i++) {
 {
     char* tlv7;
      tlv7 = gSeedWords [ i ];
    	total += cgc_strlen(tlv7);
 }
	total += 1;
;		//for the NULL character
    }

    {
        cgc_size_t tlv6;
        tlv6 = total;
        int tlv5;
        tlv5 = 0;
        void** tlv4;
        tlv4 = ( void * * ) ( & cgc_gWordData );
        ret = cgc_allocate(tlv6,tlv5,tlv4);
    }
    if (ret != 0) {
	return (ret);
    }
    //now that we have both we can fill in the data  
    cgc_size_t temp;
    temp = 0;
    char* pTemp;
     pTemp = cgc_gWordData;
    for (i = 0; i < numWords; i++) {
	cgc_gWords[i] = pTemp;
 {
     char* tlv10;
      tlv10 = pTemp;
     char* tlv9;
      tlv9 = gSeedWords [ i ];
     int tlv8;
     tlv8 = rot;
    	pTemp += cgc_strrotcpy(tlv10,tlv9,tlv8);
 }
	pTemp += 1;
;		//for the NULL character
    }

    for (; i < (PAGE_SIZE / sizeof(char *)); i++) {
	cgc_gWords[i] = 0;
    }
    return (0);
}

void fix_ingred_main_8_1_0();
void fix_ingred_main_8_1_2();
void fix_ingred_main_8_1_3();
void fix_ingred_main_8_1_5();
void fix_ingred_main_8_1();
void fix_ingred_main_8_2_0();
void fix_ingred_main_8_2_1();
void fix_ingred_main_8_2_8();
void fix_ingred_main_8_2();
void fix_ingred_main_8_4_7();
void fix_ingred_main_8_4();
void fix_ingred_main_8();
int cgc_toInt(char c1, char c2)
{
if (fix_ingred_enable){ fix_ingred_main_8(); };
    int ret;
    ret = 0;
    if ((c1 >= '0') && (c1 <= '9')) {
	ret = c1 - '0';
	if ((c2 >= '0') && (c2 <= '9')) {
	    ret *= 10;
	    ret += c2 - '0';
	    return (ret);
	} else {
	    if (c2 != '\0') {
		return (ret);
	    } else {
		return (0);
	    }
	}
    }
    return (0);
}

static uint32_t gRandRegister = 0xDA2bAC9C;
void fix_ingred_main_9();
uint32_t cgc_RANDOM()
{
if (fix_ingred_enable){ fix_ingred_main_9(); };
    gRandRegister = ((((gRandRegister >> 31)
		       ^ (gRandRegister >> 6)
		       ^ (gRandRegister >> 4)
		       ^ (gRandRegister >> 2)
		       ^ (gRandRegister >> 1)
		       ^ gRandRegister)
		      & 0x00000001)
		     << 31)
	| (gRandRegister >> 1);
    return (gRandRegister);
}

void fix_ingred_main_10_1_0();
void fix_ingred_main_10_1_1();
void fix_ingred_main_10_1();
void fix_ingred_main_10_2_2();
void fix_ingred_main_10_2();
void fix_ingred_main_10_5_2();
void fix_ingred_main_10_5();
void fix_ingred_main_10();
int cgc_strcmp(char *s1, char *s2)
{
if (fix_ingred_enable){ fix_ingred_main_10(); };
    if (s1 == NULL) {
	if (s2 == NULL) {
	    return (0);
	} else {
	    return (-1);
	}
    }
    if (s2 == NULL) {
	return (1);
    }
    int i;
    i = 0;
    while (s1[i] != '\0') {
	if (s2[i] == '\0') {
	    return (1);
	}
	if (s1[i] < s2[i]) {
	    return (-1);
	} else {
	    if (s1[i] > s2[i]) {
		return (1);
	    }
	}
	i++;
    }
    if (s2[i] == '\0') {
	return (0);
    }

    return (-1);
}

void fix_ingred_main_11();
void cgc_my_srand(uint32_t seed)
{
if (fix_ingred_enable){ fix_ingred_main_11(); };
    gRandRegister = seed;
}

void fix_ingred_main_12_0_0();
void fix_ingred_main_12_0();
void fix_ingred_main_12_1_1();
void fix_ingred_main_12_1_2();
void fix_ingred_main_12_1_3();
void fix_ingred_main_12_1_4();
void fix_ingred_main_12_1();
void fix_ingred_main_12();
void cgc_scramble(char *dst, char *src, cgc_size_t len)
{
if (fix_ingred_enable){ fix_ingred_main_12(); };
    int i;
    i = 0;
    uint32_t r;
    r = ( cgc_RANDOM ( ) % 3 ) + 2;
    while ((src[i] != '\0') && (i < len)) {
	if (IS_VALID_CHAR(src[i])) {
	    if (i % r) {
		dst[i] = src[i];
	    } else {
		dst[i] = '_';
	    }
	} else {
	    dst[i] = src[i];
	}
	i++;
    }
    dst[i] = '\0';
}

void fix_ingred_main_13_0_0();
void fix_ingred_main_13_0_3();
void fix_ingred_main_13_0_4();
void fix_ingred_main_13_0();
void fix_ingred_main_13_1_0();
void fix_ingred_main_13_1_1();
void fix_ingred_main_13_1();
void fix_ingred_main_13_2_0();
void fix_ingred_main_13_2();
void fix_ingred_main_13_3_5();
void fix_ingred_main_13_3();
void fix_ingred_main_13_4_0();
void fix_ingred_main_13_4();
void fix_ingred_main_13_5_7();
void fix_ingred_main_13_5_8();
void fix_ingred_main_13_5();
void fix_ingred_main_13_8_0();
void fix_ingred_main_13_8_1();
void fix_ingred_main_13_8_2();
void fix_ingred_main_13_8();
void fix_ingred_main_13_9_0();
void fix_ingred_main_13_9_1();
void fix_ingred_main_13_9();
void fix_ingred_main_13_11_9();
void fix_ingred_main_13_11();
void fix_ingred_main_13_13_1();
void fix_ingred_main_13_13();
void fix_ingred_main_13_16_6();
void fix_ingred_main_13_16();
void fix_ingred_main_13();
int main(int cgc_argc, char *cgc_argv[])
{
if (fix_ingred_enable){ fix_ingred_main_13(); };
#define BUF_SIZE 64
#define READLINE(_buf, _len) do { sret = cgc_readline(_buf, _len); if (sret == 0) { cgc__terminate(1); } } while (0)
    char buf[BUF_SIZE] = { };
    int i;
    i = 0;
    int ret;
    ret = 0;
    int temp;
    temp = 0;
    cgc_size_t sret;
    sret = 0;
    char c;
    c = '\n';
    cgc_transmit_str(ENTER_NUM_MSG);
    READLINE(buf, BUF_SIZE);

    {
        char tlv11;
        tlv11 = buf [ 0 ];
        char tlv10;
        tlv10 = buf [ 1 ];
        i = cgc_toInt(tlv11,tlv10);
    }
    int tlv1;
    {
        int tlv12;
        tlv12 = i + 1;
        tlv1 = cgc_init(tlv12);
    }
    if (tlv1 != 0) {
	return (-1);
    }
    //initialize the LFSR
    {
        uint32_t tlv4;
        tlv4 = * ( ( int * ) buf );
        cgc_my_srand(tlv4);
    }

    for (i = 0; i < NUM_ROUNDS; i++) {
	if (i == 0) {
	    cgc_transmit_str(WORD_MSG);
	} else {
	    cgc_transmit_str(NEXT_WORD_MSG);
	}
	temp = cgc_RANDOM() % NUM_WORDS;
 {
     char* tlv19;
      tlv19 = buf;
     char* tlv18;
      tlv18 = cgc_gWords [ temp ];
     cgc_size_t tlv17;
     tlv17 = BUF_SIZE;
    	cgc_scramble(tlv19,tlv18,tlv17);
 }
	cgc_transmit_str(buf);
 {
     char* tlv21;
      tlv21 = & c;
     cgc_size_t tlv20;
     tlv20 = 1;
    	cgc_transmit_all(tlv21,tlv20);
 }
	READLINE(buf, BUF_SIZE);

	buf[sret - 1] = '\0';
 int tlv3;
 {
     char* tlv23;
      tlv23 = buf;
     char* tlv22;
      tlv22 = cgc_gWords [ temp ];
     tlv3 = cgc_strcmp(tlv23,tlv22);
 }
	if (tlv3 != 0) {
	    cgc_transmit_str(LOSE_MSG);
	    return (0);
	}
    }
    cgc_transmit_str(FINAL_RND_MSG);
    READLINE(buf, BUF_SIZE);

    {
        char tlv14;
        tlv14 = buf [ 0 ];
        char tlv13;
        tlv13 = buf [ 1 ];
        i = cgc_toInt(tlv14,tlv13);
    }
    {
        char* tlv7;
         tlv7 = buf;
        char* tlv6;
         tlv6 = cgc_gWords [ i ];
        cgc_size_t tlv5;
        tlv5 = BUF_SIZE;
        cgc_scramble(tlv7,tlv6,tlv5);
    }
    cgc_transmit_str(buf);
    {
        char* tlv9;
         tlv9 = & c;
        cgc_size_t tlv8;
        tlv8 = 1;
        cgc_transmit_all(tlv9,tlv8);
    }
    READLINE(buf, BUF_SIZE);

    buf[sret - 1] = '\0';
    int tlv2;
    {
        char* tlv16;
         tlv16 = buf;
        char* tlv15;
         tlv15 = cgc_gWords [ i ];
        tlv2 = cgc_strcmp(tlv16,tlv15);
    }
    if (tlv2 != 0) {
	cgc_transmit_str(LOSE_MSG);
    } else {
	cgc_transmit_str(WIN_MSG);
    }
    return (0);
}

void fix_ingred_main_0_0_0(){
    {cgc_size_t ret; ret = (cgc_size_t)(0); }
}
void fix_ingred_main_0_0(){
fix_ingred_main_0_0_0();
}
void fix_ingred_main_0_1_1(){
char str_ref;
    bzero(&str_ref,1*sizeof(char));
char * str = &str_ref;
    {cgc_size_t ret; ret = (cgc_size_t)(str); }
}
void fix_ingred_main_0_1_2(){
char str_ref;
    bzero(&str_ref,1*sizeof(char));
char * str = &str_ref;
    {cgc_size_t ret; ret = (cgc_size_t)(NULL); }
}
void fix_ingred_main_0_1(){
fix_ingred_main_0_1_1();
fix_ingred_main_0_1_2();
}
void fix_ingred_main_0_2_3(){
char str_ref;
    bzero(&str_ref,1*sizeof(char));
char * str = &str_ref;
cgc_size_t ret;
    bzero(&ret,sizeof(cgc_size_t));
    {cgc_size_t ret; ret = (cgc_size_t)('\0'); }
}
void fix_ingred_main_0_2(){
fix_ingred_main_0_2_3();
}
void fix_ingred_main_0(){
fix_ingred_main_0_0();
fix_ingred_main_0_1();
fix_ingred_main_0_2();
}
void fix_ingred_main_1_0_0(){
    {cgc_size_t rx_bytes; rx_bytes = (cgc_size_t)(0); }
    {cgc_size_t total; total = (cgc_size_t)(0); }
    {int ret; ret = (int)(0); }
    {int tlv4; tlv4 = (int)(0); }
    {void * tlv3; tlv3 = (void *)(0); }
    {cgc_size_t tlv2; tlv2 = (cgc_size_t)(0); }
    {unsigned int tlv5; tlv5 = (unsigned int)(0); }
}
void fix_ingred_main_1_0_2(){
    {cgc_size_t rx_bytes; rx_bytes = (cgc_size_t)(0); }
    {cgc_size_t total; total = (cgc_size_t)(0); }
    {int ret; ret = (int)(0); }
    {int tlv4; tlv4 = (int)(0); }
    {void * tlv3; tlv3 = (void *)(0); }
    {cgc_size_t tlv2; tlv2 = (cgc_size_t)(0); }
    {unsigned int tlv5; tlv5 = (unsigned int)(0); }
}
void fix_ingred_main_1_0(){
fix_ingred_main_1_0_0();
fix_ingred_main_1_0_2();
}
void fix_ingred_main_1_1_3(){
char buf_ref;
    bzero(&buf_ref,1*sizeof(char));
char * buf = &buf_ref;
    {cgc_size_t rx_bytes; rx_bytes = (cgc_size_t)(buf); }
    {cgc_size_t total; total = (cgc_size_t)(buf); }
    {int ret; ret = (int)(buf); }
    {int tlv4; tlv4 = (int)(buf); }
    {void * tlv3; tlv3 = (void *)(buf); }
    {cgc_size_t tlv2; tlv2 = (cgc_size_t)(buf); }
    {unsigned int tlv5; tlv5 = (unsigned int)(buf); }
}
void fix_ingred_main_1_1_4(){
char buf_ref;
    bzero(&buf_ref,1*sizeof(char));
char * buf = &buf_ref;
    {cgc_size_t rx_bytes; rx_bytes = (cgc_size_t)(NULL); }
    {cgc_size_t total; total = (cgc_size_t)(NULL); }
    {int ret; ret = (int)(NULL); }
    {int tlv4; tlv4 = (int)(NULL); }
    {void * tlv3; tlv3 = (void *)(NULL); }
    {cgc_size_t tlv2; tlv2 = (cgc_size_t)(NULL); }
    {unsigned int tlv5; tlv5 = (unsigned int)(NULL); }
}
void fix_ingred_main_1_1(){
fix_ingred_main_1_1_3();
fix_ingred_main_1_1_4();
}
void fix_ingred_main_1_2_3(){
cgc_size_t total;
    bzero(&total,sizeof(cgc_size_t));
cgc_size_t size;
    bzero(&size,sizeof(cgc_size_t));
    {cgc_size_t rx_bytes; rx_bytes = (cgc_size_t)(total); }
    {int ret; ret = (int)(total); }
    {int tlv4; tlv4 = (int)(total); }
    {void * tlv3; tlv3 = (void *)(total); }
    {cgc_size_t tlv2; tlv2 = (cgc_size_t)(total); }
    {unsigned int tlv5; tlv5 = (unsigned int)(total); }
}
void fix_ingred_main_1_2_4(){
cgc_size_t total;
    bzero(&total,sizeof(cgc_size_t));
cgc_size_t size;
    bzero(&size,sizeof(cgc_size_t));
    {cgc_size_t rx_bytes; rx_bytes = (cgc_size_t)(size); }
    {cgc_size_t total; total = (cgc_size_t)(size); }
    {int ret; ret = (int)(size); }
    {int tlv4; tlv4 = (int)(size); }
    {void * tlv3; tlv3 = (void *)(size); }
    {cgc_size_t tlv2; tlv2 = (cgc_size_t)(size); }
    {unsigned int tlv5; tlv5 = (unsigned int)(size); }
}
void fix_ingred_main_1_2(){
fix_ingred_main_1_2_3();
fix_ingred_main_1_2_4();
}
void fix_ingred_main_1_3_0(){
cgc_size_t rx_bytes;
    bzero(&rx_bytes,sizeof(cgc_size_t));
    {cgc_size_t total; total = (cgc_size_t)(rx_bytes); }
    {int ret; ret = (int)(rx_bytes); }
    {int tlv4; tlv4 = (int)(rx_bytes); }
    {void * tlv3; tlv3 = (void *)(rx_bytes); }
    {cgc_size_t tlv2; tlv2 = (cgc_size_t)(rx_bytes); }
    {unsigned int tlv5; tlv5 = (unsigned int)(rx_bytes); }
}
void fix_ingred_main_1_3(){
fix_ingred_main_1_3_0();
}
void fix_ingred_main_1_4_0(){
char buf_ref;
    bzero(&buf_ref,1*sizeof(char));
char * buf = &buf_ref;
cgc_size_t size;
    bzero(&size,sizeof(cgc_size_t));
cgc_size_t total;
    bzero(&total,sizeof(cgc_size_t));
    {cgc_size_t rx_bytes; rx_bytes = (cgc_size_t)(STDOUT); }
    {cgc_size_t total; total = (cgc_size_t)(STDOUT); }
    {int ret; ret = (int)(STDOUT); }
    {int tlv4; tlv4 = (int)(STDOUT); }
    {void * tlv3; tlv3 = (void *)(STDOUT); }
    {cgc_size_t tlv2; tlv2 = (cgc_size_t)(STDOUT); }
    {unsigned int tlv5; tlv5 = (unsigned int)(STDOUT); }
}
void fix_ingred_main_1_4_1(){
char buf_ref;
    bzero(&buf_ref,1*sizeof(char));
char * buf = &buf_ref;
cgc_size_t size;
    bzero(&size,sizeof(cgc_size_t));
cgc_size_t total;
    bzero(&total,sizeof(cgc_size_t));
    {cgc_size_t rx_bytes; rx_bytes = (cgc_size_t)(buf); }
    {cgc_size_t total; total = (cgc_size_t)(buf); }
    {int ret; ret = (int)(buf); }
    {int tlv4; tlv4 = (int)(buf); }
    {void * tlv3; tlv3 = (void *)(buf); }
    {cgc_size_t tlv2; tlv2 = (cgc_size_t)(buf); }
    {unsigned int tlv5; tlv5 = (unsigned int)(buf); }
}
void fix_ingred_main_1_4_2(){
char buf_ref;
    bzero(&buf_ref,1*sizeof(char));
char * buf = &buf_ref;
cgc_size_t size;
    bzero(&size,sizeof(cgc_size_t));
cgc_size_t total;
    bzero(&total,sizeof(cgc_size_t));
    {cgc_size_t rx_bytes; rx_bytes = (cgc_size_t)(size - total); }
    {int ret; ret = (int)(size - total); }
    {int tlv4; tlv4 = (int)(size - total); }
    {void * tlv3; tlv3 = (void *)(size - total); }
    {cgc_size_t tlv2; tlv2 = (cgc_size_t)(size - total); }
    {unsigned int tlv5; tlv5 = (unsigned int)(size - total); }
}
void fix_ingred_main_1_4(){
fix_ingred_main_1_4_0();
fix_ingred_main_1_4_1();
fix_ingred_main_1_4_2();
}
void fix_ingred_main_1_5_3(){
int ret;
    bzero(&ret,sizeof(int));
    {cgc_size_t rx_bytes; rx_bytes = (cgc_size_t)(ret); }
    {cgc_size_t total; total = (cgc_size_t)(ret); }
    {int tlv4; tlv4 = (int)(ret); }
    {void * tlv3; tlv3 = (void *)(ret); }
    {cgc_size_t tlv2; tlv2 = (cgc_size_t)(ret); }
    {unsigned int tlv5; tlv5 = (unsigned int)(ret); }
}
void fix_ingred_main_1_5(){
fix_ingred_main_1_5_3();
}
void fix_ingred_main_1_6_0(){
    {cgc_size_t rx_bytes; rx_bytes = (cgc_size_t)(1); }
    {cgc_size_t total; total = (cgc_size_t)(1); }
    {int ret; ret = (int)(1); }
    {int tlv4; tlv4 = (int)(1); }
    {void * tlv3; tlv3 = (void *)(1); }
    {cgc_size_t tlv2; tlv2 = (cgc_size_t)(1); }
    {unsigned int tlv5; tlv5 = (unsigned int)(1); }
}
void fix_ingred_main_1_6(){
fix_ingred_main_1_6_0();
}
void fix_ingred_main_1(){
fix_ingred_main_1_0();
fix_ingred_main_1_1();
fix_ingred_main_1_2();
fix_ingred_main_1_3();
fix_ingred_main_1_4();
fix_ingred_main_1_5();
fix_ingred_main_1_6();
}
void fix_ingred_main_2_1_0(){
char buf_ref;
    bzero(&buf_ref,1*sizeof(char));
char * buf = &buf_ref;
char tlv1_ref;
    bzero(&tlv1_ref,1*sizeof(char));
char * tlv1 = &tlv1_ref;
    {cgc_size_t len; len = (cgc_size_t)(buf); }
    {char * tlv1; tlv1 = (char *)(buf); }
}
void fix_ingred_main_2_1_1(){
char buf_ref;
    bzero(&buf_ref,1*sizeof(char));
char * buf = &buf_ref;
char tlv1_ref;
    bzero(&tlv1_ref,1*sizeof(char));
char * tlv1 = &tlv1_ref;
    {cgc_size_t len; len = (cgc_size_t)(cgc_strlen ( tlv1 )); }
}
void fix_ingred_main_2_1(){
fix_ingred_main_2_1_0();
fix_ingred_main_2_1_1();
}
void fix_ingred_main_2(){
fix_ingred_main_2_1();
}
void fix_ingred_main_3_4_0(){
    {cgc_size_t rx_bytes; rx_bytes = (cgc_size_t)(STDIN); }
    {cgc_size_t total; total = (cgc_size_t)(STDIN); }
    {int ret; ret = (int)(STDIN); }
    {int tlv4; tlv4 = (int)(STDIN); }
    {void * tlv3; tlv3 = (void *)(STDIN); }
    {cgc_size_t tlv2; tlv2 = (cgc_size_t)(STDIN); }
    {unsigned int tlv5; tlv5 = (unsigned int)(STDIN); }
}
void fix_ingred_main_3_4(){
fix_ingred_main_3_4_0();
}
void fix_ingred_main_3(){
fix_ingred_main_3_4();
}
void fix_ingred_main_4_0_0(){
    {cgc_size_t count; count = (cgc_size_t)(0); }
    {char c; c = (char)(0); }
}
void fix_ingred_main_4_0_1(){
    {cgc_size_t count; count = (cgc_size_t)(0); }
    {char c; c = (char)(0); }
}
void fix_ingred_main_4_0_2(){
    {cgc_size_t count; count = (cgc_size_t)(0); }
    {int ret; ret = (int)(0); }
    {char c; c = (char)(0); }
    {cgc_size_t rx_bytes; rx_bytes = (cgc_size_t)(0); }
    {int tlv4; tlv4 = (int)(0); }
    {void * tlv3; tlv3 = (void *)(0); }
    {cgc_size_t tlv2; tlv2 = (cgc_size_t)(0); }
    {unsigned int tlv5; tlv5 = (unsigned int)(0); }
}
void fix_ingred_main_4_0(){
fix_ingred_main_4_0_0();
fix_ingred_main_4_0_1();
fix_ingred_main_4_0_2();
}
void fix_ingred_main_4_1_0(){
char buf_ref;
    bzero(&buf_ref,1*sizeof(char));
char * buf = &buf_ref;
    {cgc_size_t count; count = (cgc_size_t)(buf); }
    {char c; c = (char)(buf); }
}
void fix_ingred_main_4_1_1(){
char buf_ref;
    bzero(&buf_ref,1*sizeof(char));
char * buf = &buf_ref;
    {cgc_size_t count; count = (cgc_size_t)(NULL); }
    {char c; c = (char)(NULL); }
}
void fix_ingred_main_4_1(){
fix_ingred_main_4_1_0();
fix_ingred_main_4_1_1();
}
void fix_ingred_main_4_2_4(){
char c;
    bzero(&c,sizeof(char));
cgc_size_t count;
    bzero(&count,sizeof(cgc_size_t));
cgc_size_t len;
    bzero(&len,sizeof(cgc_size_t));
    {cgc_size_t count; count = (cgc_size_t)(c); }
    {int ret; ret = (int)(c); }
    {cgc_size_t rx_bytes; rx_bytes = (cgc_size_t)(c); }
    {int tlv4; tlv4 = (int)(c); }
    {void * tlv3; tlv3 = (void *)(c); }
    {cgc_size_t tlv2; tlv2 = (cgc_size_t)(c); }
    {unsigned int tlv5; tlv5 = (unsigned int)(c); }
}
void fix_ingred_main_4_2_5(){
char c;
    bzero(&c,sizeof(char));
cgc_size_t count;
    bzero(&count,sizeof(cgc_size_t));
cgc_size_t len;
    bzero(&len,sizeof(cgc_size_t));
    {cgc_size_t count; count = (cgc_size_t)('\n'); }
    {int ret; ret = (int)('\n'); }
    {char c; c = (char)('\n'); }
    {cgc_size_t rx_bytes; rx_bytes = (cgc_size_t)('\n'); }
    {int tlv4; tlv4 = (int)('\n'); }
    {void * tlv3; tlv3 = (void *)('\n'); }
    {cgc_size_t tlv2; tlv2 = (cgc_size_t)('\n'); }
    {unsigned int tlv5; tlv5 = (unsigned int)('\n'); }
}
void fix_ingred_main_4_2_6(){
char c;
    bzero(&c,sizeof(char));
cgc_size_t count;
    bzero(&count,sizeof(cgc_size_t));
cgc_size_t len;
    bzero(&len,sizeof(cgc_size_t));
    {int ret; ret = (int)(count); }
    {char c; c = (char)(count); }
    {cgc_size_t rx_bytes; rx_bytes = (cgc_size_t)(count); }
    {int tlv4; tlv4 = (int)(count); }
    {void * tlv3; tlv3 = (void *)(count); }
    {cgc_size_t tlv2; tlv2 = (cgc_size_t)(count); }
    {unsigned int tlv5; tlv5 = (unsigned int)(count); }
}
void fix_ingred_main_4_2_7(){
char c;
    bzero(&c,sizeof(char));
cgc_size_t count;
    bzero(&count,sizeof(cgc_size_t));
cgc_size_t len;
    bzero(&len,sizeof(cgc_size_t));
    {cgc_size_t count; count = (cgc_size_t)(len); }
    {int ret; ret = (int)(len); }
    {char c; c = (char)(len); }
    {cgc_size_t rx_bytes; rx_bytes = (cgc_size_t)(len); }
    {int tlv4; tlv4 = (int)(len); }
    {void * tlv3; tlv3 = (void *)(len); }
    {cgc_size_t tlv2; tlv2 = (cgc_size_t)(len); }
    {unsigned int tlv5; tlv5 = (unsigned int)(len); }
}
void fix_ingred_main_4_2(){
fix_ingred_main_4_2_4();
fix_ingred_main_4_2_5();
fix_ingred_main_4_2_6();
fix_ingred_main_4_2_7();
}
void fix_ingred_main_4_4_0(){
char c;
    bzero(&c,sizeof(char));
    {cgc_size_t count; count = (cgc_size_t)(STDIN); }
    {char c; c = (char)(STDIN); }
}
void fix_ingred_main_4_4_1(){
char c;
    bzero(&c,sizeof(char));
    {cgc_size_t count; count = (cgc_size_t)(& c); }
    {int ret; ret = (int)(& c); }
    {cgc_size_t rx_bytes; rx_bytes = (cgc_size_t)(& c); }
    {int tlv4; tlv4 = (int)(& c); }
    {void * tlv3; tlv3 = (void *)(& c); }
    {cgc_size_t tlv2; tlv2 = (cgc_size_t)(& c); }
    {unsigned int tlv5; tlv5 = (unsigned int)(& c); }
}
void fix_ingred_main_4_4_2(){
char c;
    bzero(&c,sizeof(char));
    {cgc_size_t count; count = (cgc_size_t)(1); }
    {int ret; ret = (int)(1); }
    {char c; c = (char)(1); }
    {cgc_size_t rx_bytes; rx_bytes = (cgc_size_t)(1); }
    {int tlv4; tlv4 = (int)(1); }
    {void * tlv3; tlv3 = (void *)(1); }
    {cgc_size_t tlv2; tlv2 = (cgc_size_t)(1); }
    {unsigned int tlv5; tlv5 = (unsigned int)(1); }
}
void fix_ingred_main_4_4(){
fix_ingred_main_4_4_0();
fix_ingred_main_4_4_1();
fix_ingred_main_4_4_2();
}
void fix_ingred_main_4_5_4(){
int ret;
    bzero(&ret,sizeof(int));
cgc_size_t rx_bytes;
    bzero(&rx_bytes,sizeof(cgc_size_t));
    {cgc_size_t count; count = (cgc_size_t)(ret); }
    {char c; c = (char)(ret); }
}
void fix_ingred_main_4_5_6(){
int ret;
    bzero(&ret,sizeof(int));
cgc_size_t rx_bytes;
    bzero(&rx_bytes,sizeof(cgc_size_t));
    {cgc_size_t count; count = (cgc_size_t)(rx_bytes); }
    {char c; c = (char)(rx_bytes); }
}
void fix_ingred_main_4_5(){
fix_ingred_main_4_5_4();
fix_ingred_main_4_5_6();
}
void fix_ingred_main_4_6_0(){
    {cgc_size_t count; count = (cgc_size_t)(1); }
    {char c; c = (char)(1); }
}
void fix_ingred_main_4_6(){
fix_ingred_main_4_6_0();
}
void fix_ingred_main_4(){
fix_ingred_main_4_0();
fix_ingred_main_4_1();
fix_ingred_main_4_2();
fix_ingred_main_4_4();
fix_ingred_main_4_5();
fix_ingred_main_4_6();
}
void fix_ingred_main_5_0_0(){
int n;
    bzero(&n,sizeof(int));
int temp;
    bzero(&temp,sizeof(int));
    {int temp; temp = (int)(0); }
}
void fix_ingred_main_5_0_2(){
int n;
    bzero(&n,sizeof(int));
int temp;
    bzero(&temp,sizeof(int));
    {int temp; temp = (int)(n); }
}
void fix_ingred_main_5_0(){
fix_ingred_main_5_0_0();
fix_ingred_main_5_0_2();
}
void fix_ingred_main_5_1_0(){
char c;
    bzero(&c,sizeof(char));
    {int temp; temp = (int)(c - 'a'); }
}
void fix_ingred_main_5_1_3(){
char c;
    bzero(&c,sizeof(char));
    {int temp; temp = (int)(c); }
}
void fix_ingred_main_5_1_4(){
char c;
    bzero(&c,sizeof(char));
    {int temp; temp = (int)('a'); }
}
void fix_ingred_main_5_1_6(){
char c;
    bzero(&c,sizeof(char));
    {int temp; temp = (int)('z'); }
}
void fix_ingred_main_5_1(){
fix_ingred_main_5_1_0();
fix_ingred_main_5_1_3();
fix_ingred_main_5_1_4();
fix_ingred_main_5_1_6();
}
void fix_ingred_main_5_3_0(){
char c;
    bzero(&c,sizeof(char));
    {int temp; temp = (int)(c - 'A' + 26); }
}
void fix_ingred_main_5_3_4(){
char c;
    bzero(&c,sizeof(char));
    {int temp; temp = (int)('A'); }
}
void fix_ingred_main_5_3_6(){
char c;
    bzero(&c,sizeof(char));
    {int temp; temp = (int)('Z'); }
}
void fix_ingred_main_5_3(){
fix_ingred_main_5_3_0();
fix_ingred_main_5_3_4();
fix_ingred_main_5_3_6();
}
void fix_ingred_main_5_5_0(){
char c;
    bzero(&c,sizeof(char));
    {int temp; temp = (int)(c - '0' + 52); }
}
void fix_ingred_main_5_5_4(){
char c;
    bzero(&c,sizeof(char));
    {int temp; temp = (int)('0'); }
}
void fix_ingred_main_5_5_6(){
char c;
    bzero(&c,sizeof(char));
    {int temp; temp = (int)('9'); }
}
void fix_ingred_main_5_5(){
fix_ingred_main_5_5_0();
fix_ingred_main_5_5_4();
fix_ingred_main_5_5_6();
}
void fix_ingred_main_5(){
fix_ingred_main_5_0();
fix_ingred_main_5_1();
fix_ingred_main_5_3();
fix_ingred_main_5_5();
}
void fix_ingred_main_6_0_0(){
    {char tlv2; tlv2 = (char)(0); }
    {int tlv1; tlv1 = (int)(0); }
}
void fix_ingred_main_6_0(){
fix_ingred_main_6_0_0();
}
void fix_ingred_main_6_1_0(){
char src_ref;
    bzero(&src_ref,1*sizeof(char));
char * src = &src_ref;
char dst_ref;
    bzero(&dst_ref,1*sizeof(char));
char * dst = &dst_ref;
    {cgc_size_t ret; ret = (cgc_size_t)(src); }
    {char tlv2; tlv2 = (char)(src); }
    {int tlv1; tlv1 = (int)(src); }
}
void fix_ingred_main_6_1_1(){
char src_ref;
    bzero(&src_ref,1*sizeof(char));
char * src = &src_ref;
char dst_ref;
    bzero(&dst_ref,1*sizeof(char));
char * dst = &dst_ref;
    {char tlv2; tlv2 = (char)(NULL); }
    {int tlv1; tlv1 = (int)(NULL); }
}
void fix_ingred_main_6_1_2(){
char src_ref;
    bzero(&src_ref,1*sizeof(char));
char * src = &src_ref;
char dst_ref;
    bzero(&dst_ref,1*sizeof(char));
char * dst = &dst_ref;
    {cgc_size_t ret; ret = (cgc_size_t)(dst); }
    {char tlv2; tlv2 = (char)(dst); }
    {int tlv1; tlv1 = (int)(dst); }
}
void fix_ingred_main_6_1(){
fix_ingred_main_6_1_0();
fix_ingred_main_6_1_1();
fix_ingred_main_6_1_2();
}
void fix_ingred_main_6_2_2(){
char src_ref;
    bzero(&src_ref,1*sizeof(char));
char * src = &src_ref;
cgc_size_t ret;
    bzero(&ret,sizeof(cgc_size_t));
    {    ret = 0;
         char tlv2; tlv2 = (char)(src [ ret ]); }
    {    ret = 0;
         int tlv1; tlv1 = (int)(src [ ret ]); }
}
void fix_ingred_main_6_2_3(){
char src_ref;
    bzero(&src_ref,1*sizeof(char));
char * src = &src_ref;
cgc_size_t ret;
    bzero(&ret,sizeof(cgc_size_t));
    {char tlv2; tlv2 = (char)('\0'); }
    {int tlv1; tlv1 = (int)('\0'); }
}
void fix_ingred_main_6_2(){
fix_ingred_main_6_2_2();
fix_ingred_main_6_2_3();
}
void fix_ingred_main_6_3_0(){
char src_ref;
    bzero(&src_ref,1*sizeof(char));
char * src = &src_ref;
cgc_size_t ret;
    bzero(&ret,sizeof(cgc_size_t));
int rot;
    bzero(&rot,sizeof(int));
    {    ret = 0;
         char tlv2; tlv2 = (char)(src [ ret ]); }
    {    ret = 0;
         int tlv1; tlv1 = (int)(src [ ret ]); }
}
void fix_ingred_main_6_3_1(){
char src_ref;
    bzero(&src_ref,1*sizeof(char));
char * src = &src_ref;
cgc_size_t ret;
    bzero(&ret,sizeof(cgc_size_t));
int rot;
    bzero(&rot,sizeof(int));
    {cgc_size_t ret; ret = (cgc_size_t)(rot); }
    {char tlv2; tlv2 = (char)(rot); }
    {int tlv1; tlv1 = (int)(rot); }
}
void fix_ingred_main_6_3(){
fix_ingred_main_6_3_0();
fix_ingred_main_6_3_1();
}
void fix_ingred_main_6(){
fix_ingred_main_6_0();
fix_ingred_main_6_1();
fix_ingred_main_6_2();
fix_ingred_main_6_3();
}
void fix_ingred_main_7_0_0(){
    {cgc_size_t numWords; numWords = (cgc_size_t)(0); }
    {int i; i = (int)(0); }
    {cgc_size_t temp; temp = (cgc_size_t)(0); }
    {char * pTemp; pTemp = (char *)(0); }
    {cgc_size_t tlv3; tlv3 = (cgc_size_t)(0); }
    {int tlv2; tlv2 = (int)(0); }
    {cgc_size_t tlv6; tlv6 = (cgc_size_t)(0); }
    {int tlv5; tlv5 = (int)(0); }
    {char * tlv7; tlv7 = (char *)(0); }
    {char * tlv10; tlv10 = (char *)(0); }
    {char * tlv9; tlv9 = (char *)(0); }
    {int tlv8; tlv8 = (int)(0); }
}
void fix_ingred_main_7_0_1(){
    {int ret; ret = (int)(NUM_WORDS); }
    {cgc_size_t numWords; numWords = (cgc_size_t)(NUM_WORDS); }
    {cgc_size_t total; total = (cgc_size_t)(NUM_WORDS); }
    {int i; i = (int)(NUM_WORDS); }
    {cgc_size_t temp; temp = (cgc_size_t)(NUM_WORDS); }
    {char * pTemp; pTemp = (char *)(NUM_WORDS); }
    {cgc_size_t tlv3; tlv3 = (cgc_size_t)(NUM_WORDS); }
    {int tlv2; tlv2 = (int)(NUM_WORDS); }
    {cgc_size_t tlv6; tlv6 = (cgc_size_t)(NUM_WORDS); }
    {int tlv5; tlv5 = (int)(NUM_WORDS); }
    {char * tlv7; tlv7 = (char *)(NUM_WORDS); }
    {char * tlv10; tlv10 = (char *)(NUM_WORDS); }
    {char * tlv9; tlv9 = (char *)(NUM_WORDS); }
    {int tlv8; tlv8 = (int)(NUM_WORDS); }
}
void fix_ingred_main_7_0_2(){
    {cgc_size_t numWords; numWords = (cgc_size_t)(0); }
    {int i; i = (int)(0); }
    {cgc_size_t temp; temp = (cgc_size_t)(0); }
    {char * pTemp; pTemp = (char *)(0); }
    {cgc_size_t tlv3; tlv3 = (cgc_size_t)(0); }
    {int tlv2; tlv2 = (int)(0); }
    {cgc_size_t tlv6; tlv6 = (cgc_size_t)(0); }
    {int tlv5; tlv5 = (int)(0); }
    {char * tlv7; tlv7 = (char *)(0); }
    {char * tlv10; tlv10 = (char *)(0); }
    {char * tlv9; tlv9 = (char *)(0); }
    {int tlv8; tlv8 = (int)(0); }
}
void fix_ingred_main_7_0_5(){
    {int ret; ret = (int)(cgc_gWordData); }
    {cgc_size_t numWords; numWords = (cgc_size_t)(cgc_gWordData); }
    {cgc_size_t total; total = (cgc_size_t)(cgc_gWordData); }
    {int i; i = (int)(cgc_gWordData); }
    {cgc_size_t temp; temp = (cgc_size_t)(cgc_gWordData); }
    {char * pTemp; pTemp = (char *)(cgc_gWordData); }
    {cgc_size_t tlv3; tlv3 = (cgc_size_t)(cgc_gWordData); }
    {int tlv2; tlv2 = (int)(cgc_gWordData); }
    {cgc_size_t tlv6; tlv6 = (cgc_size_t)(cgc_gWordData); }
    {int tlv5; tlv5 = (int)(cgc_gWordData); }
    {char * tlv7; tlv7 = (char *)(cgc_gWordData); }
    {char * tlv10; tlv10 = (char *)(cgc_gWordData); }
    {char * tlv9; tlv9 = (char *)(cgc_gWordData); }
    {int tlv8; tlv8 = (int)(cgc_gWordData); }
}
void fix_ingred_main_7_0(){
fix_ingred_main_7_0_0();
fix_ingred_main_7_0_1();
fix_ingred_main_7_0_2();
fix_ingred_main_7_0_5();
}
void fix_ingred_main_7_1_0(){
    {int ret; ret = (int)(sizeof ( gSeedWords )); }
    {cgc_size_t numWords; numWords = (cgc_size_t)(sizeof ( gSeedWords )); }
    {cgc_size_t total; total = (cgc_size_t)(sizeof ( gSeedWords )); }
    {int i; i = (int)(sizeof ( gSeedWords )); }
    {cgc_size_t temp; temp = (cgc_size_t)(sizeof ( gSeedWords )); }
    {char * pTemp; pTemp = (char *)(sizeof ( gSeedWords )); }
    {cgc_size_t tlv3; tlv3 = (cgc_size_t)(sizeof ( gSeedWords )); }
    {int tlv2; tlv2 = (int)(sizeof ( gSeedWords )); }
    {cgc_size_t tlv6; tlv6 = (cgc_size_t)(sizeof ( gSeedWords )); }
    {int tlv5; tlv5 = (int)(sizeof ( gSeedWords )); }
    {char * tlv7; tlv7 = (char *)(sizeof ( gSeedWords )); }
    {char * tlv10; tlv10 = (char *)(sizeof ( gSeedWords )); }
    {char * tlv9; tlv9 = (char *)(sizeof ( gSeedWords )); }
    {int tlv8; tlv8 = (int)(sizeof ( gSeedWords )); }
}
void fix_ingred_main_7_1(){
fix_ingred_main_7_1_0();
}
void fix_ingred_main_7_2_2(){
int ret;
    bzero(&ret,sizeof(int));
    {cgc_size_t numWords; numWords = (cgc_size_t)(ret); }
    {int i; i = (int)(ret); }
    {cgc_size_t temp; temp = (cgc_size_t)(ret); }
    {char * pTemp; pTemp = (char *)(ret); }
    {cgc_size_t tlv3; tlv3 = (cgc_size_t)(ret); }
    {int tlv2; tlv2 = (int)(ret); }
    {cgc_size_t tlv6; tlv6 = (cgc_size_t)(ret); }
    {int tlv5; tlv5 = (int)(ret); }
    {char * tlv7; tlv7 = (char *)(ret); }
    {char * tlv10; tlv10 = (char *)(ret); }
    {char * tlv9; tlv9 = (char *)(ret); }
    {int tlv8; tlv8 = (int)(ret); }
}
void fix_ingred_main_7_2(){
fix_ingred_main_7_2_2();
}
void fix_ingred_main_7_3_0(){
int i;
    bzero(&i,sizeof(int));
cgc_size_t numWords;
    bzero(&numWords,sizeof(cgc_size_t));
    {cgc_size_t numWords; numWords = (cgc_size_t)(1); }
    {cgc_size_t total; total = (cgc_size_t)(1); }
    {int i; i = (int)(1); }
    {cgc_size_t temp; temp = (cgc_size_t)(1); }
    {char * pTemp; pTemp = (char *)(1); }
    {cgc_size_t tlv3; tlv3 = (cgc_size_t)(1); }
    {int tlv2; tlv2 = (int)(1); }
    {cgc_size_t tlv6; tlv6 = (cgc_size_t)(1); }
    {int tlv5; tlv5 = (int)(1); }
    {char * tlv7; tlv7 = (char *)(1); }
    {char * tlv10; tlv10 = (char *)(1); }
    {char * tlv9; tlv9 = (char *)(1); }
    {int tlv8; tlv8 = (int)(1); }
}
void fix_ingred_main_7_3_6(){
int i;
    bzero(&i,sizeof(int));
cgc_size_t numWords;
    bzero(&numWords,sizeof(cgc_size_t));
    {int ret; ret = (int)(i); }
    {cgc_size_t numWords; numWords = (cgc_size_t)(i); }
    {cgc_size_t total; total = (cgc_size_t)(i); }
    {cgc_size_t temp; temp = (cgc_size_t)(i); }
    {char * pTemp; pTemp = (char *)(i); }
    {cgc_size_t tlv3; tlv3 = (cgc_size_t)(i); }
    {int tlv2; tlv2 = (int)(i); }
    {cgc_size_t tlv6; tlv6 = (cgc_size_t)(i); }
    {int tlv5; tlv5 = (int)(i); }
    {char * tlv7; tlv7 = (char *)(i); }
    {char * tlv10; tlv10 = (char *)(i); }
    {char * tlv9; tlv9 = (char *)(i); }
    {int tlv8; tlv8 = (int)(i); }
}
void fix_ingred_main_7_3_7(){
int i;
    bzero(&i,sizeof(int));
cgc_size_t numWords;
    bzero(&numWords,sizeof(cgc_size_t));
    {int ret; ret = (int)(numWords); }
    {cgc_size_t total; total = (cgc_size_t)(numWords); }
    {int i; i = (int)(numWords); }
    {cgc_size_t temp; temp = (cgc_size_t)(numWords); }
    {char * pTemp; pTemp = (char *)(numWords); }
    {cgc_size_t tlv3; tlv3 = (cgc_size_t)(numWords); }
    {int tlv2; tlv2 = (int)(numWords); }
    {cgc_size_t tlv6; tlv6 = (cgc_size_t)(numWords); }
    {int tlv5; tlv5 = (int)(numWords); }
    {char * tlv7; tlv7 = (char *)(numWords); }
    {char * tlv10; tlv10 = (char *)(numWords); }
    {char * tlv9; tlv9 = (char *)(numWords); }
    {int tlv8; tlv8 = (int)(numWords); }
}
void fix_ingred_main_7_3(){
fix_ingred_main_7_3_0();
fix_ingred_main_7_3_6();
fix_ingred_main_7_3_7();
}
void fix_ingred_main_7_4_0(){
int i;
    bzero(&i,sizeof(int));
char tlv7_ref;
    bzero(&tlv7_ref,1*sizeof(char));
char * tlv7 = &tlv7_ref;
    {if (gSeedWords){    i = 0;
         int ret; ret = (int)(gSeedWords [ i ]); }}
    {if (gSeedWords){    i = 0;
         cgc_size_t numWords; numWords = (cgc_size_t)(gSeedWords [ i ]); }}
    {if (gSeedWords){    i = 0;
         cgc_size_t total; total = (cgc_size_t)(gSeedWords [ i ]); }}
    {if (gSeedWords){    i = 0;
         cgc_size_t temp; temp = (cgc_size_t)(gSeedWords [ i ]); }}
    {if (gSeedWords){    i = 0;
         char * pTemp; pTemp = (char *)(gSeedWords [ i ]); }}
    {if (gSeedWords){    i = 0;
         cgc_size_t tlv3; tlv3 = (cgc_size_t)(gSeedWords [ i ]); }}
    {if (gSeedWords){    i = 0;
         int tlv2; tlv2 = (int)(gSeedWords [ i ]); }}
    {if (gSeedWords){    i = 0;
         cgc_size_t tlv6; tlv6 = (cgc_size_t)(gSeedWords [ i ]); }}
    {if (gSeedWords){    i = 0;
         int tlv5; tlv5 = (int)(gSeedWords [ i ]); }}
    {if (gSeedWords){    i = 0;
         char * tlv7; tlv7 = (char *)(gSeedWords [ i ]); }}
    {if (gSeedWords){    i = 0;
         char * tlv10; tlv10 = (char *)(gSeedWords [ i ]); }}
    {if (gSeedWords){    i = 0;
         char * tlv9; tlv9 = (char *)(gSeedWords [ i ]); }}
    {if (gSeedWords){    i = 0;
         int tlv8; tlv8 = (int)(gSeedWords [ i ]); }}
}
void fix_ingred_main_7_4_1(){
int i;
    bzero(&i,sizeof(int));
char tlv7_ref;
    bzero(&tlv7_ref,1*sizeof(char));
char * tlv7 = &tlv7_ref;
    {int ret; ret = (int)(cgc_strlen ( tlv7 )); }
    {cgc_size_t numWords; numWords = (cgc_size_t)(cgc_strlen ( tlv7 )); }
    {cgc_size_t total; total = (cgc_size_t)(cgc_strlen ( tlv7 )); }
    {int i; i = (int)(cgc_strlen ( tlv7 )); }
    {cgc_size_t temp; temp = (cgc_size_t)(cgc_strlen ( tlv7 )); }
    {char * pTemp; pTemp = (char *)(cgc_strlen ( tlv7 )); }
    {cgc_size_t tlv3; tlv3 = (cgc_size_t)(cgc_strlen ( tlv7 )); }
    {int tlv2; tlv2 = (int)(cgc_strlen ( tlv7 )); }
    {cgc_size_t tlv6; tlv6 = (cgc_size_t)(cgc_strlen ( tlv7 )); }
    {int tlv5; tlv5 = (int)(cgc_strlen ( tlv7 )); }
    {char * tlv10; tlv10 = (char *)(cgc_strlen ( tlv7 )); }
    {char * tlv9; tlv9 = (char *)(cgc_strlen ( tlv7 )); }
    {int tlv8; tlv8 = (int)(cgc_strlen ( tlv7 )); }
}
void fix_ingred_main_7_4(){
fix_ingred_main_7_4_0();
fix_ingred_main_7_4_1();
}
void fix_ingred_main_7_5_0(){
cgc_size_t total;
    bzero(&total,sizeof(cgc_size_t));
    {cgc_size_t numWords; numWords = (cgc_size_t)(total); }
    {int i; i = (int)(total); }
    {cgc_size_t temp; temp = (cgc_size_t)(total); }
    {char * pTemp; pTemp = (char *)(total); }
    {cgc_size_t tlv3; tlv3 = (cgc_size_t)(total); }
    {int tlv2; tlv2 = (int)(total); }
    {cgc_size_t tlv6; tlv6 = (cgc_size_t)(total); }
    {int tlv5; tlv5 = (int)(total); }
    {char * tlv7; tlv7 = (char *)(total); }
    {char * tlv10; tlv10 = (char *)(total); }
    {char * tlv9; tlv9 = (char *)(total); }
    {int tlv8; tlv8 = (int)(total); }
}
void fix_ingred_main_7_5(){
fix_ingred_main_7_5_0();
}
void fix_ingred_main_7_7_1(){
    {int ret; ret = (int)(1); }
    {cgc_size_t numWords; numWords = (cgc_size_t)(1); }
    {cgc_size_t total; total = (cgc_size_t)(1); }
    {int i; i = (int)(1); }
    {cgc_size_t temp; temp = (cgc_size_t)(1); }
    {char * pTemp; pTemp = (char *)(1); }
    {cgc_size_t tlv3; tlv3 = (cgc_size_t)(1); }
    {int tlv2; tlv2 = (int)(1); }
    {cgc_size_t tlv6; tlv6 = (cgc_size_t)(1); }
    {int tlv5; tlv5 = (int)(1); }
    {char * tlv7; tlv7 = (char *)(1); }
    {char * tlv10; tlv10 = (char *)(1); }
    {char * tlv9; tlv9 = (char *)(1); }
    {int tlv8; tlv8 = (int)(1); }
}
void fix_ingred_main_7_7(){
fix_ingred_main_7_7_1();
}
void fix_ingred_main_7_8_0(){
char pTemp_ref;
    bzero(&pTemp_ref,1*sizeof(char));
char * pTemp = &pTemp_ref;
int rot;
    bzero(&rot,sizeof(int));
    {int ret; ret = (int)(pTemp); }
    {cgc_size_t numWords; numWords = (cgc_size_t)(pTemp); }
    {cgc_size_t total; total = (cgc_size_t)(pTemp); }
    {int i; i = (int)(pTemp); }
    {cgc_size_t temp; temp = (cgc_size_t)(pTemp); }
    {cgc_size_t tlv3; tlv3 = (cgc_size_t)(pTemp); }
    {int tlv2; tlv2 = (int)(pTemp); }
    {cgc_size_t tlv6; tlv6 = (cgc_size_t)(pTemp); }
    {int tlv5; tlv5 = (int)(pTemp); }
    {char * tlv7; tlv7 = (char *)(pTemp); }
    {char * tlv10; tlv10 = (char *)(pTemp); }
    {char * tlv9; tlv9 = (char *)(pTemp); }
    {int tlv8; tlv8 = (int)(pTemp); }
}
void fix_ingred_main_7_8_2(){
char pTemp_ref;
    bzero(&pTemp_ref,1*sizeof(char));
char * pTemp = &pTemp_ref;
int rot;
    bzero(&rot,sizeof(int));
    {int ret; ret = (int)(rot); }
    {cgc_size_t numWords; numWords = (cgc_size_t)(rot); }
    {cgc_size_t total; total = (cgc_size_t)(rot); }
    {int i; i = (int)(rot); }
    {cgc_size_t temp; temp = (cgc_size_t)(rot); }
    {char * pTemp; pTemp = (char *)(rot); }
    {cgc_size_t tlv3; tlv3 = (cgc_size_t)(rot); }
    {int tlv2; tlv2 = (int)(rot); }
    {cgc_size_t tlv6; tlv6 = (cgc_size_t)(rot); }
    {int tlv5; tlv5 = (int)(rot); }
    {char * tlv7; tlv7 = (char *)(rot); }
    {char * tlv10; tlv10 = (char *)(rot); }
    {char * tlv9; tlv9 = (char *)(rot); }
    {int tlv8; tlv8 = (int)(rot); }
}
void fix_ingred_main_7_8(){
fix_ingred_main_7_8_0();
fix_ingred_main_7_8_2();
}
void fix_ingred_main_7(){
fix_ingred_main_7_0();
fix_ingred_main_7_1();
fix_ingred_main_7_2();
fix_ingred_main_7_3();
fix_ingred_main_7_4();
fix_ingred_main_7_5();
fix_ingred_main_7_7();
fix_ingred_main_7_8();
}
void fix_ingred_main_8_1_0(){
char c1;
    bzero(&c1,sizeof(char));
    {int ret; ret = (int)(c1 - '0'); }
}
void fix_ingred_main_8_1_2(){
char c1;
    bzero(&c1,sizeof(char));
    {int ret; ret = (int)(c1); }
}
void fix_ingred_main_8_1_3(){
char c1;
    bzero(&c1,sizeof(char));
    {int ret; ret = (int)('0'); }
}
void fix_ingred_main_8_1_5(){
char c1;
    bzero(&c1,sizeof(char));
    {int ret; ret = (int)('9'); }
}
void fix_ingred_main_8_1(){
fix_ingred_main_8_1_0();
fix_ingred_main_8_1_2();
fix_ingred_main_8_1_3();
fix_ingred_main_8_1_5();
}
void fix_ingred_main_8_2_0(){
char c2;
    bzero(&c2,sizeof(char));
    {int ret; ret = (int)(10); }
}
void fix_ingred_main_8_2_1(){
char c2;
    bzero(&c2,sizeof(char));
    {int ret; ret = (int)(c2 - '0'); }
}
void fix_ingred_main_8_2_8(){
char c2;
    bzero(&c2,sizeof(char));
    {int ret; ret = (int)(c2); }
}
void fix_ingred_main_8_2(){
fix_ingred_main_8_2_0();
fix_ingred_main_8_2_1();
fix_ingred_main_8_2_8();
}
void fix_ingred_main_8_4_7(){
    {int ret; ret = (int)('\0'); }
}
void fix_ingred_main_8_4(){
fix_ingred_main_8_4_7();
}
void fix_ingred_main_8(){
fix_ingred_main_8_1();
fix_ingred_main_8_2();
fix_ingred_main_8_4();
}
void fix_ingred_main_9(){
}
void fix_ingred_main_10_1_0(){
char s1_ref;
    bzero(&s1_ref,1*sizeof(char));
char * s1 = &s1_ref;
    {int i; i = (int)(s1); }
}
void fix_ingred_main_10_1_1(){
char s1_ref;
    bzero(&s1_ref,1*sizeof(char));
char * s1 = &s1_ref;
    {int i; i = (int)(NULL); }
}
void fix_ingred_main_10_1(){
fix_ingred_main_10_1_0();
fix_ingred_main_10_1_1();
}
void fix_ingred_main_10_2_2(){
char s2_ref;
    bzero(&s2_ref,1*sizeof(char));
char * s2 = &s2_ref;
    {int i; i = (int)(s2); }
}
void fix_ingred_main_10_2(){
fix_ingred_main_10_2_2();
}
void fix_ingred_main_10_5_2(){
char s1_ref;
    bzero(&s1_ref,1*sizeof(char));
char * s1 = &s1_ref;
int i;
    bzero(&i,sizeof(int));
    {int i; i = (int)('\0'); }
}
void fix_ingred_main_10_5(){
fix_ingred_main_10_5_2();
}
void fix_ingred_main_10(){
fix_ingred_main_10_1();
fix_ingred_main_10_2();
fix_ingred_main_10_5();
}
void fix_ingred_main_11(){
}
void fix_ingred_main_12_0_0(){
    {uint32_t r; r = (uint32_t)(0); }
}
void fix_ingred_main_12_0(){
fix_ingred_main_12_0_0();
}
void fix_ingred_main_12_1_1(){
char src_ref;
    bzero(&src_ref,1*sizeof(char));
char * src = &src_ref;
int i;
    bzero(&i,sizeof(int));
cgc_size_t len;
    bzero(&len,sizeof(cgc_size_t));
    {    i = 0;
         uint32_t r; r = (uint32_t)(src [ i ]); }
}
void fix_ingred_main_12_1_2(){
char src_ref;
    bzero(&src_ref,1*sizeof(char));
char * src = &src_ref;
int i;
    bzero(&i,sizeof(int));
cgc_size_t len;
    bzero(&len,sizeof(cgc_size_t));
    {uint32_t r; r = (uint32_t)('\0'); }
}
void fix_ingred_main_12_1_3(){
char src_ref;
    bzero(&src_ref,1*sizeof(char));
char * src = &src_ref;
int i;
    bzero(&i,sizeof(int));
cgc_size_t len;
    bzero(&len,sizeof(cgc_size_t));
    {uint32_t r; r = (uint32_t)(i); }
}
void fix_ingred_main_12_1_4(){
char src_ref;
    bzero(&src_ref,1*sizeof(char));
char * src = &src_ref;
int i;
    bzero(&i,sizeof(int));
cgc_size_t len;
    bzero(&len,sizeof(cgc_size_t));
    {int i; i = (int)(len); }
    {uint32_t r; r = (uint32_t)(len); }
}
void fix_ingred_main_12_1(){
fix_ingred_main_12_1_1();
fix_ingred_main_12_1_2();
fix_ingred_main_12_1_3();
fix_ingred_main_12_1_4();
}
void fix_ingred_main_12(){
fix_ingred_main_12_0();
fix_ingred_main_12_1();
}
void fix_ingred_main_13_0_0(){
    {char buf [ BUF_SIZE ]; buf [ ( BUF_SIZE )-1 ] = (char)(0); }
    {cgc_size_t sret; sret = (cgc_size_t)(0); }
    {int tlv1; tlv1 = (int)(0); }
    {char tlv11; tlv11 = (char)(0); }
    {char tlv10; tlv10 = (char)(0); }
    {int tlv12; tlv12 = (int)(0); }
    {uint32_t tlv4; tlv4 = (uint32_t)(0); }
    {char tlv14; tlv14 = (char)(0); }
    {char tlv13; tlv13 = (char)(0); }
    {char * tlv6; tlv6 = (char *)(0); }
    {cgc_size_t tlv5; tlv5 = (cgc_size_t)(0); }
    {cgc_size_t tlv8; tlv8 = (cgc_size_t)(0); }
    {char * tlv16; tlv16 = (char *)(0); }
    {char * tlv15; tlv15 = (char *)(0); }
    {int tlv3; tlv3 = (int)(0); }
    {char * tlv19; tlv19 = (char *)(0); }
    {char * tlv18; tlv18 = (char *)(0); }
    {cgc_size_t tlv17; tlv17 = (cgc_size_t)(0); }
    {char * tlv21; tlv21 = (char *)(0); }
    {cgc_size_t tlv20; tlv20 = (cgc_size_t)(0); }
    {char * tlv23; tlv23 = (char *)(0); }
    {char * tlv22; tlv22 = (char *)(0); }
}
void fix_ingred_main_13_0_3(){
    {char buf [ BUF_SIZE ]; buf [ ( BUF_SIZE )-1 ] = (char)(0); }
    {int temp; temp = (int)(0); }
    {cgc_size_t sret; sret = (cgc_size_t)(0); }
    {char tlv11; tlv11 = (char)(0); }
    {char tlv10; tlv10 = (char)(0); }
    {int tlv12; tlv12 = (int)(0); }
    {uint32_t tlv4; tlv4 = (uint32_t)(0); }
    {char tlv14; tlv14 = (char)(0); }
    {char tlv13; tlv13 = (char)(0); }
    {char * tlv6; tlv6 = (char *)(0); }
    {cgc_size_t tlv5; tlv5 = (cgc_size_t)(0); }
    {cgc_size_t tlv8; tlv8 = (cgc_size_t)(0); }
    {char * tlv16; tlv16 = (char *)(0); }
    {char * tlv15; tlv15 = (char *)(0); }
    {int tlv3; tlv3 = (int)(0); }
    {char * tlv19; tlv19 = (char *)(0); }
    {char * tlv18; tlv18 = (char *)(0); }
    {cgc_size_t tlv17; tlv17 = (cgc_size_t)(0); }
    {char * tlv21; tlv21 = (char *)(0); }
    {cgc_size_t tlv20; tlv20 = (cgc_size_t)(0); }
    {char * tlv23; tlv23 = (char *)(0); }
    {char * tlv22; tlv22 = (char *)(0); }
}
void fix_ingred_main_13_0_4(){
    {char buf [ BUF_SIZE ]; buf [ ( BUF_SIZE )-1 ] = (char)('\n'); }
    {int i; i = (int)('\n'); }
    {int temp; temp = (int)('\n'); }
    {cgc_size_t sret; sret = (cgc_size_t)('\n'); }
    {int tlv1; tlv1 = (int)('\n'); }
    {int tlv2; tlv2 = (int)('\n'); }
    {char tlv11; tlv11 = (char)('\n'); }
    {char tlv10; tlv10 = (char)('\n'); }
    {int tlv12; tlv12 = (int)('\n'); }
    {uint32_t tlv4; tlv4 = (uint32_t)('\n'); }
    {char tlv14; tlv14 = (char)('\n'); }
    {char tlv13; tlv13 = (char)('\n'); }
    {char * tlv7; tlv7 = (char *)('\n'); }
    {char * tlv6; tlv6 = (char *)('\n'); }
    {cgc_size_t tlv5; tlv5 = (cgc_size_t)('\n'); }
    {char * tlv9; tlv9 = (char *)('\n'); }
    {cgc_size_t tlv8; tlv8 = (cgc_size_t)('\n'); }
    {char * tlv16; tlv16 = (char *)('\n'); }
    {char * tlv15; tlv15 = (char *)('\n'); }
    {int tlv3; tlv3 = (int)('\n'); }
    {char * tlv19; tlv19 = (char *)('\n'); }
    {char * tlv18; tlv18 = (char *)('\n'); }
    {cgc_size_t tlv17; tlv17 = (cgc_size_t)('\n'); }
    {char * tlv21; tlv21 = (char *)('\n'); }
    {cgc_size_t tlv20; tlv20 = (cgc_size_t)('\n'); }
    {char * tlv23; tlv23 = (char *)('\n'); }
    {char * tlv22; tlv22 = (char *)('\n'); }
}
void fix_ingred_main_13_0(){
fix_ingred_main_13_0_0();
fix_ingred_main_13_0_3();
fix_ingred_main_13_0_4();
}
void fix_ingred_main_13_1_0(){
char buf [ BUF_SIZE ];
    bzero(&buf,( BUF_SIZE *sizeof(char) ) );
    {if (buf){char buf [ BUF_SIZE ]; buf [ ( BUF_SIZE )-1 ] = (char)(buf [ 0 ]); }}
    {if (buf){int i; i = (int)(buf [ 0 ]); }}
    {if (buf){int ret; ret = (int)(buf [ 0 ]); }}
    {if (buf){int temp; temp = (int)(buf [ 0 ]); }}
    {if (buf){cgc_size_t sret; sret = (cgc_size_t)(buf [ 0 ]); }}
    {if (buf){char c; c = (char)(buf [ 0 ]); }}
    {if (buf){int tlv1; tlv1 = (int)(buf [ 0 ]); }}
    {if (buf){int tlv2; tlv2 = (int)(buf [ 0 ]); }}
    {if (buf){char tlv11; tlv11 = (char)(buf [ 0 ]); }}
    {if (buf){char tlv10; tlv10 = (char)(buf [ 0 ]); }}
    {if (buf){int tlv12; tlv12 = (int)(buf [ 0 ]); }}
    {if (buf){uint32_t tlv4; tlv4 = (uint32_t)(buf [ 0 ]); }}
    {if (buf){char tlv14; tlv14 = (char)(buf [ 0 ]); }}
    {if (buf){char tlv13; tlv13 = (char)(buf [ 0 ]); }}
    {if (buf){char * tlv7; tlv7 = (char *)(buf [ 0 ]); }}
    {if (buf){char * tlv6; tlv6 = (char *)(buf [ 0 ]); }}
    {if (buf){cgc_size_t tlv5; tlv5 = (cgc_size_t)(buf [ 0 ]); }}
    {if (buf){char * tlv9; tlv9 = (char *)(buf [ 0 ]); }}
    {if (buf){cgc_size_t tlv8; tlv8 = (cgc_size_t)(buf [ 0 ]); }}
    {if (buf){char * tlv16; tlv16 = (char *)(buf [ 0 ]); }}
    {if (buf){char * tlv15; tlv15 = (char *)(buf [ 0 ]); }}
    {if (buf){int tlv3; tlv3 = (int)(buf [ 0 ]); }}
    {if (buf){char * tlv19; tlv19 = (char *)(buf [ 0 ]); }}
    {if (buf){char * tlv18; tlv18 = (char *)(buf [ 0 ]); }}
    {if (buf){cgc_size_t tlv17; tlv17 = (cgc_size_t)(buf [ 0 ]); }}
    {if (buf){char * tlv21; tlv21 = (char *)(buf [ 0 ]); }}
    {if (buf){cgc_size_t tlv20; tlv20 = (cgc_size_t)(buf [ 0 ]); }}
    {if (buf){char * tlv23; tlv23 = (char *)(buf [ 0 ]); }}
    {if (buf){char * tlv22; tlv22 = (char *)(buf [ 0 ]); }}
}
void fix_ingred_main_13_1_1(){
char buf [ BUF_SIZE ];
    bzero(&buf,( BUF_SIZE *sizeof(char) ) );
    {if (buf){char buf [ BUF_SIZE ]; buf [ ( BUF_SIZE )-1 ] = (char)(buf [ 1 ]); }}
    {if (buf){int i; i = (int)(buf [ 1 ]); }}
    {if (buf){int ret; ret = (int)(buf [ 1 ]); }}
    {if (buf){int temp; temp = (int)(buf [ 1 ]); }}
    {if (buf){cgc_size_t sret; sret = (cgc_size_t)(buf [ 1 ]); }}
    {if (buf){char c; c = (char)(buf [ 1 ]); }}
    {if (buf){int tlv1; tlv1 = (int)(buf [ 1 ]); }}
    {if (buf){int tlv2; tlv2 = (int)(buf [ 1 ]); }}
    {if (buf){char tlv11; tlv11 = (char)(buf [ 1 ]); }}
    {if (buf){char tlv10; tlv10 = (char)(buf [ 1 ]); }}
    {if (buf){int tlv12; tlv12 = (int)(buf [ 1 ]); }}
    {if (buf){uint32_t tlv4; tlv4 = (uint32_t)(buf [ 1 ]); }}
    {if (buf){char tlv14; tlv14 = (char)(buf [ 1 ]); }}
    {if (buf){char tlv13; tlv13 = (char)(buf [ 1 ]); }}
    {if (buf){char * tlv7; tlv7 = (char *)(buf [ 1 ]); }}
    {if (buf){char * tlv6; tlv6 = (char *)(buf [ 1 ]); }}
    {if (buf){cgc_size_t tlv5; tlv5 = (cgc_size_t)(buf [ 1 ]); }}
    {if (buf){char * tlv9; tlv9 = (char *)(buf [ 1 ]); }}
    {if (buf){cgc_size_t tlv8; tlv8 = (cgc_size_t)(buf [ 1 ]); }}
    {if (buf){char * tlv16; tlv16 = (char *)(buf [ 1 ]); }}
    {if (buf){char * tlv15; tlv15 = (char *)(buf [ 1 ]); }}
    {if (buf){int tlv3; tlv3 = (int)(buf [ 1 ]); }}
    {if (buf){char * tlv19; tlv19 = (char *)(buf [ 1 ]); }}
    {if (buf){char * tlv18; tlv18 = (char *)(buf [ 1 ]); }}
    {if (buf){cgc_size_t tlv17; tlv17 = (cgc_size_t)(buf [ 1 ]); }}
    {if (buf){char * tlv21; tlv21 = (char *)(buf [ 1 ]); }}
    {if (buf){cgc_size_t tlv20; tlv20 = (cgc_size_t)(buf [ 1 ]); }}
    {if (buf){char * tlv23; tlv23 = (char *)(buf [ 1 ]); }}
    {if (buf){char * tlv22; tlv22 = (char *)(buf [ 1 ]); }}
}
void fix_ingred_main_13_1(){
fix_ingred_main_13_1_0();
fix_ingred_main_13_1_1();
}
void fix_ingred_main_13_2_0(){
int i;
    bzero(&i,sizeof(int));
    {char buf [ BUF_SIZE ]; buf [ ( BUF_SIZE )-1 ] = (char)(i + 1); }
    {int ret; ret = (int)(i + 1); }
    {int temp; temp = (int)(i + 1); }
    {cgc_size_t sret; sret = (cgc_size_t)(i + 1); }
    {char c; c = (char)(i + 1); }
    {int tlv1; tlv1 = (int)(i + 1); }
    {int tlv2; tlv2 = (int)(i + 1); }
    {char tlv11; tlv11 = (char)(i + 1); }
    {char tlv10; tlv10 = (char)(i + 1); }
    {int tlv12; tlv12 = (int)(i + 1); }
    {uint32_t tlv4; tlv4 = (uint32_t)(i + 1); }
    {char tlv14; tlv14 = (char)(i + 1); }
    {char tlv13; tlv13 = (char)(i + 1); }
    {char * tlv7; tlv7 = (char *)(i + 1); }
    {char * tlv6; tlv6 = (char *)(i + 1); }
    {cgc_size_t tlv5; tlv5 = (cgc_size_t)(i + 1); }
    {char * tlv9; tlv9 = (char *)(i + 1); }
    {cgc_size_t tlv8; tlv8 = (cgc_size_t)(i + 1); }
    {char * tlv16; tlv16 = (char *)(i + 1); }
    {char * tlv15; tlv15 = (char *)(i + 1); }
    {int tlv3; tlv3 = (int)(i + 1); }
    {char * tlv19; tlv19 = (char *)(i + 1); }
    {char * tlv18; tlv18 = (char *)(i + 1); }
    {cgc_size_t tlv17; tlv17 = (cgc_size_t)(i + 1); }
    {char * tlv21; tlv21 = (char *)(i + 1); }
    {cgc_size_t tlv20; tlv20 = (cgc_size_t)(i + 1); }
    {char * tlv23; tlv23 = (char *)(i + 1); }
    {char * tlv22; tlv22 = (char *)(i + 1); }
}
void fix_ingred_main_13_2(){
fix_ingred_main_13_2_0();
}
void fix_ingred_main_13_3_5(){
int tlv1;
    bzero(&tlv1,sizeof(int));
    {char buf [ BUF_SIZE ]; buf [ ( BUF_SIZE )-1 ] = (char)(tlv1); }
    {int i; i = (int)(tlv1); }
    {int ret; ret = (int)(tlv1); }
    {int temp; temp = (int)(tlv1); }
    {cgc_size_t sret; sret = (cgc_size_t)(tlv1); }
    {char c; c = (char)(tlv1); }
    {int tlv2; tlv2 = (int)(tlv1); }
    {char tlv11; tlv11 = (char)(tlv1); }
    {char tlv10; tlv10 = (char)(tlv1); }
    {int tlv12; tlv12 = (int)(tlv1); }
    {uint32_t tlv4; tlv4 = (uint32_t)(tlv1); }
    {char tlv14; tlv14 = (char)(tlv1); }
    {char tlv13; tlv13 = (char)(tlv1); }
    {char * tlv7; tlv7 = (char *)(tlv1); }
    {char * tlv6; tlv6 = (char *)(tlv1); }
    {cgc_size_t tlv5; tlv5 = (cgc_size_t)(tlv1); }
    {char * tlv9; tlv9 = (char *)(tlv1); }
    {cgc_size_t tlv8; tlv8 = (cgc_size_t)(tlv1); }
    {char * tlv16; tlv16 = (char *)(tlv1); }
    {char * tlv15; tlv15 = (char *)(tlv1); }
    {int tlv3; tlv3 = (int)(tlv1); }
    {char * tlv19; tlv19 = (char *)(tlv1); }
    {char * tlv18; tlv18 = (char *)(tlv1); }
    {cgc_size_t tlv17; tlv17 = (cgc_size_t)(tlv1); }
    {char * tlv21; tlv21 = (char *)(tlv1); }
    {cgc_size_t tlv20; tlv20 = (cgc_size_t)(tlv1); }
    {char * tlv23; tlv23 = (char *)(tlv1); }
    {char * tlv22; tlv22 = (char *)(tlv1); }
}
void fix_ingred_main_13_3(){
fix_ingred_main_13_3_5();
}
void fix_ingred_main_13_4_0(){
char buf [ BUF_SIZE ];
    bzero(&buf,( BUF_SIZE *sizeof(char) ) );
    {char buf [ BUF_SIZE ]; buf [ ( BUF_SIZE )-1 ] = (char)(* ( ( int * ) buf )); }
    {int i; i = (int)(* ( ( int * ) buf )); }
    {int ret; ret = (int)(* ( ( int * ) buf )); }
    {int temp; temp = (int)(* ( ( int * ) buf )); }
    {cgc_size_t sret; sret = (cgc_size_t)(* ( ( int * ) buf )); }
    {char c; c = (char)(* ( ( int * ) buf )); }
    {int tlv1; tlv1 = (int)(* ( ( int * ) buf )); }
    {int tlv2; tlv2 = (int)(* ( ( int * ) buf )); }
    {char tlv11; tlv11 = (char)(* ( ( int * ) buf )); }
    {char tlv10; tlv10 = (char)(* ( ( int * ) buf )); }
    {int tlv12; tlv12 = (int)(* ( ( int * ) buf )); }
    {uint32_t tlv4; tlv4 = (uint32_t)(* ( ( int * ) buf )); }
    {char tlv14; tlv14 = (char)(* ( ( int * ) buf )); }
    {char tlv13; tlv13 = (char)(* ( ( int * ) buf )); }
    {char * tlv7; tlv7 = (char *)(* ( ( int * ) buf )); }
    {char * tlv6; tlv6 = (char *)(* ( ( int * ) buf )); }
    {cgc_size_t tlv5; tlv5 = (cgc_size_t)(* ( ( int * ) buf )); }
    {char * tlv9; tlv9 = (char *)(* ( ( int * ) buf )); }
    {cgc_size_t tlv8; tlv8 = (cgc_size_t)(* ( ( int * ) buf )); }
    {char * tlv16; tlv16 = (char *)(* ( ( int * ) buf )); }
    {char * tlv15; tlv15 = (char *)(* ( ( int * ) buf )); }
    {int tlv3; tlv3 = (int)(* ( ( int * ) buf )); }
    {char * tlv19; tlv19 = (char *)(* ( ( int * ) buf )); }
    {char * tlv18; tlv18 = (char *)(* ( ( int * ) buf )); }
    {cgc_size_t tlv17; tlv17 = (cgc_size_t)(* ( ( int * ) buf )); }
    {char * tlv21; tlv21 = (char *)(* ( ( int * ) buf )); }
    {cgc_size_t tlv20; tlv20 = (cgc_size_t)(* ( ( int * ) buf )); }
    {char * tlv23; tlv23 = (char *)(* ( ( int * ) buf )); }
    {char * tlv22; tlv22 = (char *)(* ( ( int * ) buf )); }
}
void fix_ingred_main_13_4(){
fix_ingred_main_13_4_0();
}
void fix_ingred_main_13_5_7(){
int i;
    bzero(&i,sizeof(int));
    {char buf [ BUF_SIZE ]; buf [ ( BUF_SIZE )-1 ] = (char)(i); }
    {int temp; temp = (int)(i); }
    {cgc_size_t sret; sret = (cgc_size_t)(i); }
    {char c; c = (char)(i); }
    {int tlv1; tlv1 = (int)(i); }
    {char tlv11; tlv11 = (char)(i); }
    {char tlv10; tlv10 = (char)(i); }
    {int tlv12; tlv12 = (int)(i); }
    {uint32_t tlv4; tlv4 = (uint32_t)(i); }
    {char tlv14; tlv14 = (char)(i); }
    {char tlv13; tlv13 = (char)(i); }
    {char * tlv6; tlv6 = (char *)(i); }
    {cgc_size_t tlv5; tlv5 = (cgc_size_t)(i); }
    {cgc_size_t tlv8; tlv8 = (cgc_size_t)(i); }
    {char * tlv16; tlv16 = (char *)(i); }
    {char * tlv15; tlv15 = (char *)(i); }
    {int tlv3; tlv3 = (int)(i); }
    {char * tlv19; tlv19 = (char *)(i); }
    {char * tlv18; tlv18 = (char *)(i); }
    {cgc_size_t tlv17; tlv17 = (cgc_size_t)(i); }
    {char * tlv21; tlv21 = (char *)(i); }
    {cgc_size_t tlv20; tlv20 = (cgc_size_t)(i); }
    {char * tlv23; tlv23 = (char *)(i); }
    {char * tlv22; tlv22 = (char *)(i); }
}
void fix_ingred_main_13_5_8(){
int i;
    bzero(&i,sizeof(int));
    {char buf [ BUF_SIZE ]; buf [ ( BUF_SIZE )-1 ] = (char)(NUM_ROUNDS); }
    {int i; i = (int)(NUM_ROUNDS); }
    {int ret; ret = (int)(NUM_ROUNDS); }
    {int temp; temp = (int)(NUM_ROUNDS); }
    {cgc_size_t sret; sret = (cgc_size_t)(NUM_ROUNDS); }
    {char c; c = (char)(NUM_ROUNDS); }
    {int tlv1; tlv1 = (int)(NUM_ROUNDS); }
    {int tlv2; tlv2 = (int)(NUM_ROUNDS); }
    {char tlv11; tlv11 = (char)(NUM_ROUNDS); }
    {char tlv10; tlv10 = (char)(NUM_ROUNDS); }
    {int tlv12; tlv12 = (int)(NUM_ROUNDS); }
    {uint32_t tlv4; tlv4 = (uint32_t)(NUM_ROUNDS); }
    {char tlv14; tlv14 = (char)(NUM_ROUNDS); }
    {char tlv13; tlv13 = (char)(NUM_ROUNDS); }
    {char * tlv7; tlv7 = (char *)(NUM_ROUNDS); }
    {char * tlv6; tlv6 = (char *)(NUM_ROUNDS); }
    {cgc_size_t tlv5; tlv5 = (cgc_size_t)(NUM_ROUNDS); }
    {char * tlv9; tlv9 = (char *)(NUM_ROUNDS); }
    {cgc_size_t tlv8; tlv8 = (cgc_size_t)(NUM_ROUNDS); }
    {char * tlv16; tlv16 = (char *)(NUM_ROUNDS); }
    {char * tlv15; tlv15 = (char *)(NUM_ROUNDS); }
    {int tlv3; tlv3 = (int)(NUM_ROUNDS); }
    {char * tlv19; tlv19 = (char *)(NUM_ROUNDS); }
    {char * tlv18; tlv18 = (char *)(NUM_ROUNDS); }
    {cgc_size_t tlv17; tlv17 = (cgc_size_t)(NUM_ROUNDS); }
    {char * tlv21; tlv21 = (char *)(NUM_ROUNDS); }
    {cgc_size_t tlv20; tlv20 = (cgc_size_t)(NUM_ROUNDS); }
    {char * tlv23; tlv23 = (char *)(NUM_ROUNDS); }
    {char * tlv22; tlv22 = (char *)(NUM_ROUNDS); }
}
void fix_ingred_main_13_5(){
fix_ingred_main_13_5_7();
fix_ingred_main_13_5_8();
}
void fix_ingred_main_13_8_0(){
char buf [ BUF_SIZE ];
    bzero(&buf,( BUF_SIZE *sizeof(char) ) );
int temp;
    bzero(&temp,sizeof(int));
    {char buf [ BUF_SIZE ]; buf [ ( BUF_SIZE )-1 ] = (char)(buf); }
    {int i; i = (int)(buf); }
    {int temp; temp = (int)(buf); }
    {cgc_size_t sret; sret = (cgc_size_t)(buf); }
    {int tlv1; tlv1 = (int)(buf); }
    {int tlv2; tlv2 = (int)(buf); }
    {char tlv11; tlv11 = (char)(buf); }
    {char tlv10; tlv10 = (char)(buf); }
    {int tlv12; tlv12 = (int)(buf); }
    {uint32_t tlv4; tlv4 = (uint32_t)(buf); }
    {char tlv14; tlv14 = (char)(buf); }
    {char tlv13; tlv13 = (char)(buf); }
    {char * tlv7; tlv7 = (char *)(buf); }
    {char * tlv6; tlv6 = (char *)(buf); }
    {cgc_size_t tlv5; tlv5 = (cgc_size_t)(buf); }
    {char * tlv9; tlv9 = (char *)(buf); }
    {cgc_size_t tlv8; tlv8 = (cgc_size_t)(buf); }
    {char * tlv16; tlv16 = (char *)(buf); }
    {char * tlv15; tlv15 = (char *)(buf); }
    {int tlv3; tlv3 = (int)(buf); }
    {char * tlv19; tlv19 = (char *)(buf); }
    {char * tlv18; tlv18 = (char *)(buf); }
    {cgc_size_t tlv17; tlv17 = (cgc_size_t)(buf); }
    {char * tlv21; tlv21 = (char *)(buf); }
    {cgc_size_t tlv20; tlv20 = (cgc_size_t)(buf); }
    {char * tlv23; tlv23 = (char *)(buf); }
    {char * tlv22; tlv22 = (char *)(buf); }
}
void fix_ingred_main_13_8_1(){
char buf [ BUF_SIZE ];
    bzero(&buf,( BUF_SIZE *sizeof(char) ) );
int temp;
    bzero(&temp,sizeof(int));
    {if (cgc_gWords){    temp = 0;
         char buf [ BUF_SIZE ]; buf [ ( BUF_SIZE )-1 ] = (char)(cgc_gWords [ temp ]); }}
    {if (cgc_gWords){    temp = 0;
         int i; i = (int)(cgc_gWords [ temp ]); }}
    {if (cgc_gWords){    temp = 0;
         int ret; ret = (int)(cgc_gWords [ temp ]); }}
    {if (cgc_gWords){    temp = 0;
         cgc_size_t sret; sret = (cgc_size_t)(cgc_gWords [ temp ]); }}
    {if (cgc_gWords){    temp = 0;
         char c; c = (char)(cgc_gWords [ temp ]); }}
    {if (cgc_gWords){    temp = 0;
         int tlv1; tlv1 = (int)(cgc_gWords [ temp ]); }}
    {if (cgc_gWords){    temp = 0;
         int tlv2; tlv2 = (int)(cgc_gWords [ temp ]); }}
    {if (cgc_gWords){    temp = 0;
         char tlv11; tlv11 = (char)(cgc_gWords [ temp ]); }}
    {if (cgc_gWords){    temp = 0;
         char tlv10; tlv10 = (char)(cgc_gWords [ temp ]); }}
    {if (cgc_gWords){    temp = 0;
         int tlv12; tlv12 = (int)(cgc_gWords [ temp ]); }}
    {if (cgc_gWords){    temp = 0;
         uint32_t tlv4; tlv4 = (uint32_t)(cgc_gWords [ temp ]); }}
    {if (cgc_gWords){    temp = 0;
         char tlv14; tlv14 = (char)(cgc_gWords [ temp ]); }}
    {if (cgc_gWords){    temp = 0;
         char tlv13; tlv13 = (char)(cgc_gWords [ temp ]); }}
    {if (cgc_gWords){    temp = 0;
         char * tlv7; tlv7 = (char *)(cgc_gWords [ temp ]); }}
    {if (cgc_gWords){    temp = 0;
         char * tlv6; tlv6 = (char *)(cgc_gWords [ temp ]); }}
    {if (cgc_gWords){    temp = 0;
         cgc_size_t tlv5; tlv5 = (cgc_size_t)(cgc_gWords [ temp ]); }}
    {if (cgc_gWords){    temp = 0;
         char * tlv9; tlv9 = (char *)(cgc_gWords [ temp ]); }}
    {if (cgc_gWords){    temp = 0;
         cgc_size_t tlv8; tlv8 = (cgc_size_t)(cgc_gWords [ temp ]); }}
    {if (cgc_gWords){    temp = 0;
         char * tlv16; tlv16 = (char *)(cgc_gWords [ temp ]); }}
    {if (cgc_gWords){    temp = 0;
         char * tlv15; tlv15 = (char *)(cgc_gWords [ temp ]); }}
    {if (cgc_gWords){    temp = 0;
         int tlv3; tlv3 = (int)(cgc_gWords [ temp ]); }}
    {if (cgc_gWords){    temp = 0;
         char * tlv19; tlv19 = (char *)(cgc_gWords [ temp ]); }}
    {if (cgc_gWords){    temp = 0;
         char * tlv18; tlv18 = (char *)(cgc_gWords [ temp ]); }}
    {if (cgc_gWords){    temp = 0;
         cgc_size_t tlv17; tlv17 = (cgc_size_t)(cgc_gWords [ temp ]); }}
    {if (cgc_gWords){    temp = 0;
         char * tlv21; tlv21 = (char *)(cgc_gWords [ temp ]); }}
    {if (cgc_gWords){    temp = 0;
         cgc_size_t tlv20; tlv20 = (cgc_size_t)(cgc_gWords [ temp ]); }}
    {if (cgc_gWords){    temp = 0;
         char * tlv23; tlv23 = (char *)(cgc_gWords [ temp ]); }}
    {if (cgc_gWords){    temp = 0;
         char * tlv22; tlv22 = (char *)(cgc_gWords [ temp ]); }}
}
void fix_ingred_main_13_8_2(){
char buf [ BUF_SIZE ];
    bzero(&buf,( BUF_SIZE *sizeof(char) ) );
int temp;
    bzero(&temp,sizeof(int));
    {char buf [ BUF_SIZE ]; buf [ ( BUF_SIZE )-1 ] = (char)(BUF_SIZE); }
    {int i; i = (int)(BUF_SIZE); }
    {int ret; ret = (int)(BUF_SIZE); }
    {int temp; temp = (int)(BUF_SIZE); }
    {cgc_size_t sret; sret = (cgc_size_t)(BUF_SIZE); }
    {char c; c = (char)(BUF_SIZE); }
    {int tlv1; tlv1 = (int)(BUF_SIZE); }
    {int tlv2; tlv2 = (int)(BUF_SIZE); }
    {char tlv11; tlv11 = (char)(BUF_SIZE); }
    {char tlv10; tlv10 = (char)(BUF_SIZE); }
    {int tlv12; tlv12 = (int)(BUF_SIZE); }
    {uint32_t tlv4; tlv4 = (uint32_t)(BUF_SIZE); }
    {char tlv14; tlv14 = (char)(BUF_SIZE); }
    {char tlv13; tlv13 = (char)(BUF_SIZE); }
    {char * tlv7; tlv7 = (char *)(BUF_SIZE); }
    {char * tlv6; tlv6 = (char *)(BUF_SIZE); }
    {cgc_size_t tlv5; tlv5 = (cgc_size_t)(BUF_SIZE); }
    {char * tlv9; tlv9 = (char *)(BUF_SIZE); }
    {cgc_size_t tlv8; tlv8 = (cgc_size_t)(BUF_SIZE); }
    {char * tlv16; tlv16 = (char *)(BUF_SIZE); }
    {char * tlv15; tlv15 = (char *)(BUF_SIZE); }
    {int tlv3; tlv3 = (int)(BUF_SIZE); }
    {char * tlv19; tlv19 = (char *)(BUF_SIZE); }
    {char * tlv18; tlv18 = (char *)(BUF_SIZE); }
    {cgc_size_t tlv17; tlv17 = (cgc_size_t)(BUF_SIZE); }
    {char * tlv21; tlv21 = (char *)(BUF_SIZE); }
    {cgc_size_t tlv20; tlv20 = (cgc_size_t)(BUF_SIZE); }
    {char * tlv23; tlv23 = (char *)(BUF_SIZE); }
    {char * tlv22; tlv22 = (char *)(BUF_SIZE); }
}
void fix_ingred_main_13_8(){
fix_ingred_main_13_8_0();
fix_ingred_main_13_8_1();
fix_ingred_main_13_8_2();
}
void fix_ingred_main_13_9_0(){
char c;
    bzero(&c,sizeof(char));
    {char buf [ BUF_SIZE ]; buf [ ( BUF_SIZE )-1 ] = (char)(& c); }
    {int i; i = (int)(& c); }
    {int ret; ret = (int)(& c); }
    {int temp; temp = (int)(& c); }
    {cgc_size_t sret; sret = (cgc_size_t)(& c); }
    {int tlv1; tlv1 = (int)(& c); }
    {int tlv2; tlv2 = (int)(& c); }
    {char tlv11; tlv11 = (char)(& c); }
    {char tlv10; tlv10 = (char)(& c); }
    {int tlv12; tlv12 = (int)(& c); }
    {uint32_t tlv4; tlv4 = (uint32_t)(& c); }
    {char tlv14; tlv14 = (char)(& c); }
    {char tlv13; tlv13 = (char)(& c); }
    {char * tlv7; tlv7 = (char *)(& c); }
    {char * tlv6; tlv6 = (char *)(& c); }
    {cgc_size_t tlv5; tlv5 = (cgc_size_t)(& c); }
    {char * tlv9; tlv9 = (char *)(& c); }
    {cgc_size_t tlv8; tlv8 = (cgc_size_t)(& c); }
    {char * tlv16; tlv16 = (char *)(& c); }
    {char * tlv15; tlv15 = (char *)(& c); }
    {int tlv3; tlv3 = (int)(& c); }
    {char * tlv19; tlv19 = (char *)(& c); }
    {char * tlv18; tlv18 = (char *)(& c); }
    {cgc_size_t tlv17; tlv17 = (cgc_size_t)(& c); }
    {char * tlv21; tlv21 = (char *)(& c); }
    {cgc_size_t tlv20; tlv20 = (cgc_size_t)(& c); }
    {char * tlv23; tlv23 = (char *)(& c); }
    {char * tlv22; tlv22 = (char *)(& c); }
}
void fix_ingred_main_13_9_1(){
char c;
    bzero(&c,sizeof(char));
    {char buf [ BUF_SIZE ]; buf [ ( BUF_SIZE )-1 ] = (char)(1); }
    {int temp; temp = (int)(1); }
    {cgc_size_t sret; sret = (cgc_size_t)(1); }
    {int tlv1; tlv1 = (int)(1); }
    {char tlv11; tlv11 = (char)(1); }
    {char tlv10; tlv10 = (char)(1); }
    {int tlv12; tlv12 = (int)(1); }
    {uint32_t tlv4; tlv4 = (uint32_t)(1); }
    {char tlv14; tlv14 = (char)(1); }
    {char tlv13; tlv13 = (char)(1); }
    {char * tlv6; tlv6 = (char *)(1); }
    {cgc_size_t tlv5; tlv5 = (cgc_size_t)(1); }
    {cgc_size_t tlv8; tlv8 = (cgc_size_t)(1); }
    {char * tlv16; tlv16 = (char *)(1); }
    {char * tlv15; tlv15 = (char *)(1); }
    {int tlv3; tlv3 = (int)(1); }
    {char * tlv19; tlv19 = (char *)(1); }
    {char * tlv18; tlv18 = (char *)(1); }
    {cgc_size_t tlv17; tlv17 = (cgc_size_t)(1); }
    {char * tlv21; tlv21 = (char *)(1); }
    {cgc_size_t tlv20; tlv20 = (cgc_size_t)(1); }
    {char * tlv23; tlv23 = (char *)(1); }
    {char * tlv22; tlv22 = (char *)(1); }
}
void fix_ingred_main_13_9(){
fix_ingred_main_13_9_0();
fix_ingred_main_13_9_1();
}
void fix_ingred_main_13_11_9(){
int tlv3;
    bzero(&tlv3,sizeof(int));
    {char buf [ BUF_SIZE ]; buf [ ( BUF_SIZE )-1 ] = (char)(tlv3); }
    {int i; i = (int)(tlv3); }
    {int ret; ret = (int)(tlv3); }
    {int temp; temp = (int)(tlv3); }
    {cgc_size_t sret; sret = (cgc_size_t)(tlv3); }
    {char c; c = (char)(tlv3); }
    {int tlv1; tlv1 = (int)(tlv3); }
    {int tlv2; tlv2 = (int)(tlv3); }
    {char tlv11; tlv11 = (char)(tlv3); }
    {char tlv10; tlv10 = (char)(tlv3); }
    {int tlv12; tlv12 = (int)(tlv3); }
    {uint32_t tlv4; tlv4 = (uint32_t)(tlv3); }
    {char tlv14; tlv14 = (char)(tlv3); }
    {char tlv13; tlv13 = (char)(tlv3); }
    {char * tlv7; tlv7 = (char *)(tlv3); }
    {char * tlv6; tlv6 = (char *)(tlv3); }
    {cgc_size_t tlv5; tlv5 = (cgc_size_t)(tlv3); }
    {char * tlv9; tlv9 = (char *)(tlv3); }
    {cgc_size_t tlv8; tlv8 = (cgc_size_t)(tlv3); }
    {char * tlv16; tlv16 = (char *)(tlv3); }
    {char * tlv15; tlv15 = (char *)(tlv3); }
    {char * tlv19; tlv19 = (char *)(tlv3); }
    {char * tlv18; tlv18 = (char *)(tlv3); }
    {cgc_size_t tlv17; tlv17 = (cgc_size_t)(tlv3); }
    {char * tlv21; tlv21 = (char *)(tlv3); }
    {cgc_size_t tlv20; tlv20 = (cgc_size_t)(tlv3); }
    {char * tlv23; tlv23 = (char *)(tlv3); }
    {char * tlv22; tlv22 = (char *)(tlv3); }
}
void fix_ingred_main_13_11(){
fix_ingred_main_13_11_9();
}
void fix_ingred_main_13_13_1(){
int i;
    bzero(&i,sizeof(int));
    {if (cgc_gWords){    i = 0;
         char buf [ BUF_SIZE ]; buf [ ( BUF_SIZE )-1 ] = (char)(cgc_gWords [ i ]); }}
    {if (cgc_gWords){    i = 0;
         int ret; ret = (int)(cgc_gWords [ i ]); }}
    {if (cgc_gWords){    i = 0;
         int temp; temp = (int)(cgc_gWords [ i ]); }}
    {if (cgc_gWords){    i = 0;
         cgc_size_t sret; sret = (cgc_size_t)(cgc_gWords [ i ]); }}
    {if (cgc_gWords){    i = 0;
         char c; c = (char)(cgc_gWords [ i ]); }}
    {if (cgc_gWords){    i = 0;
         int tlv1; tlv1 = (int)(cgc_gWords [ i ]); }}
    {if (cgc_gWords){    i = 0;
         int tlv2; tlv2 = (int)(cgc_gWords [ i ]); }}
    {if (cgc_gWords){    i = 0;
         char tlv11; tlv11 = (char)(cgc_gWords [ i ]); }}
    {if (cgc_gWords){    i = 0;
         char tlv10; tlv10 = (char)(cgc_gWords [ i ]); }}
    {if (cgc_gWords){    i = 0;
         int tlv12; tlv12 = (int)(cgc_gWords [ i ]); }}
    {if (cgc_gWords){    i = 0;
         uint32_t tlv4; tlv4 = (uint32_t)(cgc_gWords [ i ]); }}
    {if (cgc_gWords){    i = 0;
         char tlv14; tlv14 = (char)(cgc_gWords [ i ]); }}
    {if (cgc_gWords){    i = 0;
         char tlv13; tlv13 = (char)(cgc_gWords [ i ]); }}
    {if (cgc_gWords){    i = 0;
         char * tlv7; tlv7 = (char *)(cgc_gWords [ i ]); }}
    {if (cgc_gWords){    i = 0;
         char * tlv6; tlv6 = (char *)(cgc_gWords [ i ]); }}
    {if (cgc_gWords){    i = 0;
         cgc_size_t tlv5; tlv5 = (cgc_size_t)(cgc_gWords [ i ]); }}
    {if (cgc_gWords){    i = 0;
         char * tlv9; tlv9 = (char *)(cgc_gWords [ i ]); }}
    {if (cgc_gWords){    i = 0;
         cgc_size_t tlv8; tlv8 = (cgc_size_t)(cgc_gWords [ i ]); }}
    {if (cgc_gWords){    i = 0;
         char * tlv16; tlv16 = (char *)(cgc_gWords [ i ]); }}
    {if (cgc_gWords){    i = 0;
         char * tlv15; tlv15 = (char *)(cgc_gWords [ i ]); }}
    {if (cgc_gWords){    i = 0;
         int tlv3; tlv3 = (int)(cgc_gWords [ i ]); }}
    {if (cgc_gWords){    i = 0;
         char * tlv19; tlv19 = (char *)(cgc_gWords [ i ]); }}
    {if (cgc_gWords){    i = 0;
         char * tlv18; tlv18 = (char *)(cgc_gWords [ i ]); }}
    {if (cgc_gWords){    i = 0;
         cgc_size_t tlv17; tlv17 = (cgc_size_t)(cgc_gWords [ i ]); }}
    {if (cgc_gWords){    i = 0;
         char * tlv21; tlv21 = (char *)(cgc_gWords [ i ]); }}
    {if (cgc_gWords){    i = 0;
         cgc_size_t tlv20; tlv20 = (cgc_size_t)(cgc_gWords [ i ]); }}
    {if (cgc_gWords){    i = 0;
         char * tlv23; tlv23 = (char *)(cgc_gWords [ i ]); }}
    {if (cgc_gWords){    i = 0;
         char * tlv22; tlv22 = (char *)(cgc_gWords [ i ]); }}
}
void fix_ingred_main_13_13(){
fix_ingred_main_13_13_1();
}
void fix_ingred_main_13_16_6(){
int tlv2;
    bzero(&tlv2,sizeof(int));
    {char buf [ BUF_SIZE ]; buf [ ( BUF_SIZE )-1 ] = (char)(tlv2); }
    {int i; i = (int)(tlv2); }
    {int ret; ret = (int)(tlv2); }
    {int temp; temp = (int)(tlv2); }
    {cgc_size_t sret; sret = (cgc_size_t)(tlv2); }
    {char c; c = (char)(tlv2); }
    {int tlv1; tlv1 = (int)(tlv2); }
    {char tlv11; tlv11 = (char)(tlv2); }
    {char tlv10; tlv10 = (char)(tlv2); }
    {int tlv12; tlv12 = (int)(tlv2); }
    {uint32_t tlv4; tlv4 = (uint32_t)(tlv2); }
    {char tlv14; tlv14 = (char)(tlv2); }
    {char tlv13; tlv13 = (char)(tlv2); }
    {char * tlv7; tlv7 = (char *)(tlv2); }
    {char * tlv6; tlv6 = (char *)(tlv2); }
    {cgc_size_t tlv5; tlv5 = (cgc_size_t)(tlv2); }
    {char * tlv9; tlv9 = (char *)(tlv2); }
    {cgc_size_t tlv8; tlv8 = (cgc_size_t)(tlv2); }
    {char * tlv16; tlv16 = (char *)(tlv2); }
    {char * tlv15; tlv15 = (char *)(tlv2); }
    {int tlv3; tlv3 = (int)(tlv2); }
    {char * tlv19; tlv19 = (char *)(tlv2); }
    {char * tlv18; tlv18 = (char *)(tlv2); }
    {cgc_size_t tlv17; tlv17 = (cgc_size_t)(tlv2); }
    {char * tlv21; tlv21 = (char *)(tlv2); }
    {cgc_size_t tlv20; tlv20 = (cgc_size_t)(tlv2); }
    {char * tlv23; tlv23 = (char *)(tlv2); }
    {char * tlv22; tlv22 = (char *)(tlv2); }
}
void fix_ingred_main_13_16(){
fix_ingred_main_13_16_6();
}
void fix_ingred_main_13(){
fix_ingred_main_13_0();
fix_ingred_main_13_1();
fix_ingred_main_13_2();
fix_ingred_main_13_3();
fix_ingred_main_13_4();
fix_ingred_main_13_5();
fix_ingred_main_13_8();
fix_ingred_main_13_9();
fix_ingred_main_13_11();
fix_ingred_main_13_13();
fix_ingred_main_13_16();
}
