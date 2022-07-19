

#1 "src/main.c"
#1 "<built-in>" 1
#1 "<built-in>" 3
#157 "<built-in>" 3
#1 "<command line>" 1
#1 "<built-in>" 2
#1 "src/main.c" 2
#24 "src/main.c"
#1 "lib/libcgc.h" 1
#10 "lib/libcgc.h"
typedef long unsigned int cgc_size_t;
typedef long signed int cgc_ssize_t;
typedef long int _fd_mask;
typedef struct {
    _fd_mask _fd_bits[1024 / (8 * sizeof(_fd_mask))];
}
cgc_fd_set;
#38 "lib/libcgc.h"
struct cgc_timeval {
    int tv_sec;
    int tv_usec;
};
#50 "lib/libcgc.h"
void cgc__terminate(unsigned int status) __attribute__ ((__noreturn__));
int cgc_transmit(int fd, const void *buf, cgc_size_t count, cgc_size_t * tx_bytes);
int cgc_receive(int fd, void *buf, cgc_size_t count, cgc_size_t * rx_bytes);
int cgc_fdwait(int nfds, cgc_fd_set * readfds, cgc_fd_set * writefds, const struct cgc_timeval *timeout, int *readyfds);
int cgc_allocate(cgc_size_t length, int is_X, void **addr);
int deallocate(void *addr, cgc_size_t length);
int cgc_random(void *buf, cgc_size_t count, cgc_size_t * rnd_bytes);
typedef struct {
    long _b[8];
} jmp_buf[1];
int setjmp(jmp_buf) __attribute__ ((__returns_twice__));
void longjmp(jmp_buf, int) __attribute__ ((__noreturn__));
float sinf(float);
double cgc_sin(double);
long double sinl(long double);
float cosf(float);
double cgc_cos(double);
long double cosl(long double);
float tanf(float);
double cgc_tan(double);
long double tanl(long double);
float cgc_logf(float);
double cgc_log(double);
long double logl(long double);
float rintf(float);
double cgc_rint(double);
long double rintl(long double);
float cgc_sqrtf(float);
double cgc_sqrt(double);
long double sqrtl(long double);
float fabsf(float);
double cgc_fabs(double);
long double fabsl(long double);
float cgc_log2f(float);
double cgc_log2(double);
long double log2l(long double);
float cgc_exp2f(float);
double exp2(double);
long double exp2l(long double);
float expf(float);
double exp(double);
long double expl(long double);
float log10f(float);
double cgc_log10(double);
long double log10l(long double);
float powf(float, float);
double cgc_pow(double, double);
long double powl(long double, long double);
float atan2f(float, float);
double cgc_atan2(double, double);
long double atan2l(long double, long double);
float remainderf(float, float);
double cgc_remainder(double, double);
long double remainderl(long double, long double);
float scalbnf(float, int);
double scalbn(double, int);
long double scalbnl(long double, int);
float scalblnf(float, long int);
double scalbln(double, long int);
long double scalblnl(long double, long int);
float significandf(float);
double significand(double);
long double significandl(long double);
#25 "src/main.c" 2
#1 "lib/ctype.h" 1
int isdigit(int c);
int isascii(int c);
int isprint(int c);
int isalnum(int c);
int isalpha(int c);
int islower(int c);
int isupper(int c);
int cgc_isspace(int c);
int ispunct(int c);
int tolower(int c);
int toupper(int c);
#26 "src/main.c" 2
#1 "lib/stdlib.h" 1
#1 "lib/stdarg.h" 1
typedef __builtin_va_list __gnuc_va_list;
typedef __gnuc_va_list va_list;
#6 "lib/stdlib.h" 2
#1 "lib/stddef.h" 1
typedef long int ptrdiff_t;
#7 "lib/stdlib.h" 2
extern int cgc_fdprintf(int fd, const char *fmt, ...);
extern int sprintf(char *s, const char *fmt, ...);
long strtol(const char *str, char **endptr, int base);
unsigned long strtoul(const char *str, char **endptr, int base);
extern void *malloc(cgc_size_t size);
extern void *cgc_calloc(cgc_size_t nmemb, cgc_size_t size);
extern void *cgc_realloc(void *ptr, cgc_size_t size);
extern void cgc_free(void *ptr);
extern cgc_size_t malloc_size(void *ptr);
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

void fix_ingred_main_0();
static void cgc_exit(int ret)
{
if (fix_ingred_enable){ fix_ingred_main_0(); };
    cgc__terminate(ret);
}

#27 "src/main.c" 2
#1 "lib/string.h" 1
extern void *cgc_memcpy(void *dest, const void *src, cgc_size_t n);
extern void *cgc_memmove(void *dest, const void *src, cgc_size_t n);
extern void *cgc_memset(void *dest, int c, cgc_size_t n);
extern int memcmp(void *s1, const void *s2, cgc_size_t n);
extern void *memchr(const void *s, int c, cgc_size_t n);
extern cgc_size_t cgc_strlen(const char *s);
extern char *cgc_strcpy(char *dest, const char *src);
extern char *cgc_strncpy(char *dest, const char *src, cgc_size_t n);
extern char *cgc_strchr(const char *s, int c);
extern char *strsep(char **stringp, const char *delim);
extern int cgc_strcmp(const char *s1, const char *s2);
extern int cgc_strncmp(const char *s1, const char *s2, cgc_size_t n);
extern int strcasecmp(const char *s1, const char *s2);
extern int strncasecmp(const char *s1, const char *s2, cgc_size_t n);
extern char *cgc_strcat(char *dest, const char *src);
extern char *strdup(const char *src);
#28 "src/main.c" 2
#1 "src/io.h" 1
#35 "src/io.h"
int send_n_bytes(int fd, cgc_size_t n, char *buf);
int read_n_bytes(int fd, cgc_size_t n, char *buf);
int cgc_read_until(int fd, cgc_size_t n, char terminator, char *buf);
int cgc_transmit_string(int fd, char *buf);
#30 "src/main.c" 2
typedef struct thunk_t thunk_t;
typedef struct list_t list_t;
struct list_t {
    list_t *prev, *next;
    thunk_t *thunk;
};
void cgc_remove_head_list(list_t ** list);
typedef struct note_t note_t;
struct note_t {
    cgc_size_t size;
    cgc_size_t cap;
    char *buf;
    char *title;
};
note_t *cgc_note_store[(512)] = { 0 };

void fix_ingred_main_1();
note_t *cgc_get_note(char *title)
{
if (fix_ingred_enable){ fix_ingred_main_1(); };
    for (cgc_size_t i = 0; i < (512); i++)
    {
	if (cgc_note_store[i] && cgc_strcmp(title, cgc_note_store[i]->title) == 0) {
	    return cgc_note_store[i];
	}
    }
    return ((void *) 0);
}

void fix_ingred_main_2_2_0();
void fix_ingred_main_2_2();
void fix_ingred_main_2_4_0();
void fix_ingred_main_2_4_1();
void fix_ingred_main_2_4();
void fix_ingred_main_2_8_0();
void fix_ingred_main_2_8();
void fix_ingred_main_2_9_0();
void fix_ingred_main_2_9();
void fix_ingred_main_2_10_2();
void fix_ingred_main_2_10_3();
void fix_ingred_main_2_10();
void fix_ingred_main_2_11_0();
void fix_ingred_main_2_11();
void fix_ingred_main_2_16_0();
void fix_ingred_main_2_16();
void fix_ingred_main_2_25_0();
void fix_ingred_main_2_25();
void fix_ingred_main_2_30_0();
void fix_ingred_main_2_30();
void fix_ingred_main_2_31_0();
void fix_ingred_main_2_31_1();
void fix_ingred_main_2_31_2();
void fix_ingred_main_2_31();
void fix_ingred_main_2();
note_t *cgc_new_note(char *title, char *data)
{
if (fix_ingred_enable){ fix_ingred_main_2(); };
    if (!data || !title) {
	return ((void *) 0);
    }
    note_t* tlv1;
    {
        char* tlv4;
         tlv4 = title;
        tlv1 = cgc_get_note(tlv4);
    }
    if (tlv1) {
	return ((void *) 0);
    }
    note_t* note;
    {
        cgc_size_t tlv6;
        tlv6 = sizeof ( note_t );
        cgc_size_t tlv5;
        tlv5 = 1;
        note = cgc_calloc(tlv6,tlv5);
    }
    ( {
     if (note == ((void *) 0)) {
     ( {
      cgc_fdprintf(2, "ERROR %s:%d:\t" "bad alloc" "\n", "src/main.c", 75); 
 {
     int tlv18;
     tlv18 = 1;
     cgc_exit(tlv18);
 }
;});
;}});
    cgc_size_t data_size;
    {
        const char* tlv7 = data;
        data_size = cgc_strlen(tlv7);
    }
    if (data_size + 1 > (1024)) {
 {
     cgc_size_t tlv15;
     tlv15 = sizeof ( char );
     cgc_size_t tlv14;
     tlv14 = data_size + 1;
    	note->buf = cgc_calloc(tlv15,tlv14);
 }
	( {
	 if (note->buf == ((void *) 0)) {
	 ( {
	  cgc_fdprintf(2, "ERROR %s:%d:\t" "bad alloc" "\n", "src/main.c", 82); 
 {
     int tlv20;
     tlv20 = 1;
     cgc_exit(tlv20);
 }
;});
;}});
	note->size = note->cap = data_size;
 {
     char* tlv11;
      tlv11 = note -> buf;
     const char* tlv10 = data;
    	cgc_strcpy(tlv11,tlv10);
 }
    } else {
 {
     cgc_size_t tlv17;
     tlv17 = sizeof ( char );
     cgc_size_t tlv16;
     tlv16 = ( 1024 );
    	note->buf = cgc_calloc(tlv17,tlv16);
 }
	( {
	 if (note->buf == ((void *) 0)) {
	 ( {
	  cgc_fdprintf(2, "ERROR %s:%d:\t" "bad alloc" "\n", "src/main.c", 89); 
 {
     int tlv21;
     tlv21 = 1;
     cgc_exit(tlv21);
 }
;});
;}});
	note->size = data_size;
	note->cap = (1024);
 {
     char* tlv13;
      tlv13 = note -> buf;
     const char* tlv12 = data;
    	cgc_strcpy(tlv13,tlv12);
 }
    }
    {
        cgc_size_t tlv9;
        tlv9 = sizeof ( char );
        cgc_size_t tlv8;
        {
            const char* tlv22 = title;
            tlv8 = cgc_strlen(tlv22) + 1;
        }
        note->title = cgc_calloc(tlv9,tlv8);
    }
    ( {
     if (note->title == ((void *) 0)) {
     ( {
      cgc_fdprintf(2, "ERROR %s:%d:\t" "bad alloc" "\n", "src/main.c", 96); 
 {
     int tlv19;
     tlv19 = 1;
     cgc_exit(tlv19);
 }
;});
;}});
    {
        char* tlv3;
         tlv3 = note -> title;
        const char* tlv2 = title;
        cgc_strcpy(tlv3,tlv2);
    }
    cgc_size_t i;
    for (i = 0; i < (512); i++) {
	if (cgc_note_store[i] == ((void *) 0)) {
	    cgc_note_store[i] = note;
	    break;
	}
    }
    if (i == (512)) {
	return ((void *) 0);
    }
    return note;
}

void fix_ingred_main_3_2_0();
void fix_ingred_main_3_2();
void fix_ingred_main_3_3_1();
void fix_ingred_main_3_3_2();
void fix_ingred_main_3_3();
void fix_ingred_main_3_4_0();
void fix_ingred_main_3_4();
void fix_ingred_main_3_8_0();
void fix_ingred_main_3_8();
void fix_ingred_main_3_9_0();
void fix_ingred_main_3_9();
void fix_ingred_main_3();
note_t *cgc_append_note(note_t * note, char *data)
{
if (fix_ingred_enable){ fix_ingred_main_3(); };
    if (!note || !data) {
	return ((void *) 0);
    }
    cgc_size_t tlv1;
    {
        const char* tlv4 = data;
        tlv1 = cgc_strlen(tlv4);
    }
    if (tlv1 + note->size + 1 > note->cap) {
	note->cap *= 2;
 {
     void* tlv7;
     tlv7 = note -> buf;
     cgc_size_t tlv6;
     tlv6 = note -> cap;
    	note->buf = cgc_realloc(tlv7,tlv6);
 }
	( {
	 if (note->buf == ((void *) 0)) {
	 ( {
	  cgc_fdprintf(2, "ERROR %s:%d:\t" "bad alloc" "\n", "src/main.c", 124); 
 {
     int tlv8;
     tlv8 = 1;
     cgc_exit(tlv8);
 }
;});
;}});
    }
    {
        char* tlv3;
         tlv3 = note -> buf;
        const char* tlv2 = data;
        cgc_strcat(tlv3,tlv2);
    }
    {
        const char* tlv5 = data;
        note->size += cgc_strlen(tlv5);
    }
    return note;
}

void fix_ingred_main_4_2_0();
void fix_ingred_main_4_2_1();
void fix_ingred_main_4_2();
void fix_ingred_main_4_5_0();
void fix_ingred_main_4_5();
void fix_ingred_main_4_7_0();
void fix_ingred_main_4_7();
void fix_ingred_main_4();
int cgc_delete_note(note_t * note)
{
if (fix_ingred_enable){ fix_ingred_main_4(); };
    if (!note) {
	return -1;
    }
    for (cgc_size_t i = 0; i < (512); i++)
    {
	if (cgc_note_store[i] == note) {
	    cgc_note_store[i] = ((void *) 0);
	}
    }
    if (note->buf) {
 {
     void* tlv1;
     tlv1 = note -> buf;
    	cgc_free(tlv1);
 }
    }
    if (note->title) {
 {
     void* tlv2;
     tlv2 = note -> title;
    	cgc_free(tlv2);
 }
    }
    cgc_free(note);
    return 0;
}

typedef int (*thunk_fp_t) (char **, list_t **);
struct thunk_t {
    unsigned arity;
    char **argv;
    thunk_fp_t fp;
};
char *cgc_thunk_res = ((void *) 0);
void fix_ingred_main_5_1_0();
void fix_ingred_main_5_1_1();
void fix_ingred_main_5_1();
void fix_ingred_main_5_4_0();
void fix_ingred_main_5_4();
void fix_ingred_main_5();
void cgc_free_thunk(thunk_t * thunk)
{
if (fix_ingred_enable){ fix_ingred_main_5(); };
    for (unsigned i = 0; i < thunk->arity; i++)
    {
	if (thunk->argv[i]) {
     {
         void* tlv2;
         tlv2 = thunk -> argv [ i ];
    	    cgc_free(tlv2);
     }
	}
    }
    {
        void* tlv1;
        tlv1 = thunk -> argv;
        cgc_free(tlv1);
    }
    cgc_free(thunk);
}

void fix_ingred_main_6_1_0();
void fix_ingred_main_6_1_1();
void fix_ingred_main_6_1();
void fix_ingred_main_6_2_0();
void fix_ingred_main_6_2_1();
void fix_ingred_main_6_2();
void fix_ingred_main_6_6_0();
void fix_ingred_main_6_6();
void fix_ingred_main_6_7_0();
void fix_ingred_main_6_7_1();
void fix_ingred_main_6_7();
void fix_ingred_main_6_12_2();
void fix_ingred_main_6_12_3();
void fix_ingred_main_6_12();
void fix_ingred_main_6_14_0();
void fix_ingred_main_6_14();
void fix_ingred_main_6_15_0();
void fix_ingred_main_6_15();
void fix_ingred_main_6();
thunk_t *cgc_new_thunk(thunk_fp_t fp, unsigned arity, char **argv)
{
if (fix_ingred_enable){ fix_ingred_main_6(); };
    if (arity > 4 || !argv) {
	return ((void *) 0);
    }
    thunk_t* thunk;
    {
        cgc_size_t tlv2;
        tlv2 = sizeof ( thunk_t );
        cgc_size_t tlv1;
        tlv1 = 1;
        thunk = cgc_calloc(tlv2,tlv1);
    }
    ( {
     if (thunk == ((void *) 0)) {
     ( {
      cgc_fdprintf(2, "ERROR %s:%d:\t" "bad alloc" "\n", "src/main.c", 180); 
 {
     int tlv10;
     tlv10 = 1;
     cgc_exit(tlv10);
 }
;});
;}});
    thunk->fp = fp;
    thunk->arity = arity;
    {
        cgc_size_t tlv4;
        tlv4 = sizeof ( char * );
        cgc_size_t tlv3;
        tlv3 = thunk -> arity;
        thunk->argv = cgc_calloc(tlv4,tlv3);
    }
    ( {
     if (thunk->argv == ((void *) 0)) {
     ( {
      cgc_fdprintf(2, "ERROR %s:%d:\t" "bad alloc" "\n", "src/main.c", 185); 
 {
     int tlv11;
     tlv11 = 1;
     cgc_exit(tlv11);
 }
;});
;}});
    for (unsigned i = 0; i < thunk->arity; i++) {
	if (!argv[i]) {
	    goto error;
	}
 {
     cgc_size_t tlv9;
     tlv9 = sizeof ( char );
     cgc_size_t tlv8;
     {
         const char* tlv13 = argv [ i ];
         tlv8 = cgc_strlen(tlv13) + 1;
     }
    	thunk->argv[i] = cgc_calloc(tlv9,tlv8);
 }
	( {
	 if (thunk->argv[i] == ((void *) 0)) {
	 ( {
	  cgc_fdprintf(2, "ERROR %s:%d:\t" "bad alloc" "\n", "src/main.c", 193); 
 {
     int tlv12;
     tlv12 = 1;
     cgc_exit(tlv12);
 }
;});
;}});
 {
     char* tlv7;
      tlv7 = thunk -> argv [ i ];
     const char* tlv6 = argv [ i ];
    	cgc_strcpy(tlv7,tlv6);
 }
    }
    return thunk;
  error:
    {
        thunk_t* tlv5;
        tlv5 = thunk;
        cgc_free_thunk(tlv5);
    }
    return ((void *) 0);
}

void fix_ingred_main_7();
void cgc_run_thunk(list_t ** list)
{
if (fix_ingred_enable){ fix_ingred_main_7(); };
    if (!list || !*list) {
	return;
    }
    thunk_t* thunk;
    thunk = ( * list ) -> thunk;
    thunk->fp(thunk->argv, list);
}

void fix_ingred_main_8_0_0();
void fix_ingred_main_8_0_1();
void fix_ingred_main_8_0_3();
void fix_ingred_main_8_0();
void fix_ingred_main_8_3_0();
void fix_ingred_main_8_3_1();
void fix_ingred_main_8_3();
void fix_ingred_main_8_4_0();
void fix_ingred_main_8_4();
void fix_ingred_main_8_5_4();
void fix_ingred_main_8_5_5();
void fix_ingred_main_8_5();
void fix_ingred_main_8_6_0();
void fix_ingred_main_8_6();
void fix_ingred_main_8_7_7();
void fix_ingred_main_8_7_8();
void fix_ingred_main_8_7();
void fix_ingred_main_8_8_0();
void fix_ingred_main_8_8_1();
void fix_ingred_main_8_8();
void fix_ingred_main_8_11_0();
void fix_ingred_main_8_11();
void fix_ingred_main_8_12_0();
void fix_ingred_main_8_12();
void fix_ingred_main_8_14_4();
void fix_ingred_main_8_14_5();
void fix_ingred_main_8_14();
void fix_ingred_main_8_16_0();
void fix_ingred_main_8_16();
void fix_ingred_main_8_18_0();
void fix_ingred_main_8_18();
void fix_ingred_main_8();
int cgc_append_thunk(char **argv, list_t ** list)
{
if (fix_ingred_enable){ fix_ingred_main_8(); };
    char tmp[(8192) + 1];
    if (!argv) {
	return -1;
    }
    char* note_title;
     note_title = argv [ 0 ];
    char* content;
     content = argv [ 1 ];
    if (!note_title || !content) {
	return -1;
    }
    {
        char* tlv5;
         tlv5 = tmp;
        const char* tlv4 = content;
        cgc_size_t tlv3;
        tlv3 = ( 8192 );
        cgc_strncpy(tlv5,tlv4,tlv3);
    }
    tmp[(8192)] = '\0';
    cgc_size_t rep_len;
    {
        const char tlv6 [ ] = "cloud";
        rep_len = cgc_strlen(tlv6);
    }
    cgc_size_t idx;
    idx = 0;
    while (idx < (8192) - rep_len) {
 int tlv2;
 {
     const char* tlv16 = tmp + idx;
     const char tlv15 [ ] = "cloud";
     cgc_size_t tlv14;
     tlv14 = rep_len;
     tlv2 = cgc_strncmp(tlv16,tlv15,tlv14);
 }
	if (tlv2 == 0) {
     {
         void* tlv21;
         tlv21 = tmp + idx;
         void* tlv20;
         tlv20 = "butt ";
         cgc_size_t tlv19;
         tlv19 = rep_len;
    	    cgc_memcpy(tlv21,tlv20,tlv19);
     }
	    idx += rep_len;
	}
	idx++;
    }
    int tlv1;
    {
        const char* tlv8 = content;
        const char* tlv7 = tmp;
        tlv1 = cgc_strcmp(tlv8,tlv7);
    }
    if (tlv1) {
 {
     void* tlv18;
     tlv18 = content;
     cgc_size_t tlv17;
     {
         const char* tlv23 = tmp;
         tlv17 = cgc_strlen(tlv23) + 1;
     }
    	content = cgc_realloc(tlv18,tlv17);
 }
	( {
	 if (content == ((void *) 0)) {
	 ( {
	  cgc_fdprintf(2, "ERROR %s:%d:\t" "bad alloc" "\n", "src/main.c", 246); 
 {
     int tlv22;
     tlv22 = 1;
     cgc_exit(tlv22);
 }
;});
;}});
 {
     char* tlv11;
      tlv11 = content;
     const char* tlv10 = tmp;
    	cgc_strcpy(tlv11,tlv10);
 }
    }
    note_t* note;
    {
        char* tlv9;
         tlv9 = note_title;
        note = cgc_get_note(tlv9);
    }
    if (note) {
 {
     note_t* tlv13;
     tlv13 = note;
     char* tlv12;
      tlv12 = content;
    	cgc_append_note(tlv13,tlv12);
 }
    }
    cgc_remove_head_list(list);
    if (list) {
	cgc_run_thunk(list);
    }
    return 0;
}

void fix_ingred_main_9_0_0();
void fix_ingred_main_9_0();
void fix_ingred_main_9_2_0();
void fix_ingred_main_9_2();
void fix_ingred_main_9();
int cgc_delete_thunk(char **argv, list_t ** list)
{
if (fix_ingred_enable){ fix_ingred_main_9(); };
    char* note_title;
     note_title = argv [ 0 ];
    if (!note_title) {
	return -1;
    }
    note_t* note;
    {
        char* tlv1;
         tlv1 = note_title;
        note = cgc_get_note(tlv1);
    }
    if (note) {
	cgc_delete_note(note);
    }
    cgc_remove_head_list(list);
    if (list) {
	cgc_run_thunk(list);
    }
    return 0;
}

list_t *cgc_thunks = ((void *) 0);
void fix_ingred_main_10_1_0();
void fix_ingred_main_10_1_1();
void fix_ingred_main_10_1();
void fix_ingred_main_10_5_0();
void fix_ingred_main_10_5();
void fix_ingred_main_10();
list_t *cgc_new_list(list_t * prev, list_t * next, thunk_t * thunk)
{
if (fix_ingred_enable){ fix_ingred_main_10(); };
    list_t* new;
    {
        cgc_size_t tlv2;
        tlv2 = sizeof ( list_t );
        cgc_size_t tlv1;
        tlv1 = 1;
        new = cgc_calloc(tlv2,tlv1);
    }
    ( {
     if (new == ((void *) 0)) {
     ( {
      cgc_fdprintf(2, "ERROR %s:%d:\t" "bad alloc" "\n", "src/main.c", 288); 
 {
     int tlv3;
     tlv3 = 1;
     cgc_exit(tlv3);
 }
;});
;}});
    new->prev = prev;
    new->next = next;
    new->thunk = thunk;
    return new;
}

void fix_ingred_main_11();
int cgc_append_list(list_t ** list, thunk_t * thunk)
{
if (fix_ingred_enable){ fix_ingred_main_11(); };
    if (!*list) {
 {
     list_t* tlv6;
     tlv6 = ( ( void * ) 0 );
     list_t* tlv5;
     tlv5 = ( ( void * ) 0 );
     thunk_t* tlv4;
     tlv4 = thunk;
    	*list = cgc_new_list(tlv6,tlv5,tlv4);
 }
	return 0;
    }
    list_t* elem;
    elem = * list;
    while (elem->next)
    {
	elem = elem->next;
    }
    list_t* new;
    {
        list_t* tlv3;
        tlv3 = elem;
        list_t* tlv2;
        tlv2 = ( ( void * ) 0 );
        thunk_t* tlv1;
        tlv1 = thunk;
        new = cgc_new_list(tlv3,tlv2,tlv1);
    }
    elem->next = new;
    return 0;
}

void fix_ingred_main_12();
void cgc_remove_head_list(list_t ** list)
{
if (fix_ingred_enable){ fix_ingred_main_12(); };
    if (!list || !*list) {
	return;
    }
    if ((*list)->next) {
	(*list)->next->prev = ((void *) 0);
    }
    *list = (*list)->next;
}

void fix_ingred_main_13_0_0();
void fix_ingred_main_13_0();
void fix_ingred_main_13();
cgc_size_t cgc_len_list(list_t * list)
{
if (fix_ingred_enable){ fix_ingred_main_13(); };
    cgc_size_t len;
    len = 0;
    while (list && ++len)
    {
	list = list->next;
    }
    return len;
}

static const char *WELCOME_MSG = "      Welcome to the Note Keeper 9001!\n" "~~~~~ A PREMIERE NOTE TAKING SOLUTION ~~~~";
static const char *PROMPT_MSG = "nk9001> ";
static const char *ERROR_MSG = "I don't know what you want, but you can't find it here.\n";
static const char *NOTE_FULL = "Your note book is full.\n";
static const char *NOTE_UNK = "Unknown note.\n";
static const char *NOTE_CREATED = "Note successfully created.\n";
static const char *NOTE_DELETED = "Note successfully deleted.\n";
static const char *NOTE_APPENDED = "Note successfully appended.\n";
void fix_ingred_main_14_1_0();
void fix_ingred_main_14_1_1();
void fix_ingred_main_14_1();
void fix_ingred_main_14();
void cgc_prompt(int fd)
{
if (fix_ingred_enable){ fix_ingred_main_14(); };
    {
        int tlv2;
        tlv2 = fd;
        char* tlv1;
         tlv1 = ( char * ) PROMPT_MSG;
        cgc_transmit_string(tlv2,tlv1);
    }
}

void fix_ingred_main_15_1_1();
void fix_ingred_main_15_1();
void fix_ingred_main_15();
void cgc_yell(int fd)
{
if (fix_ingred_enable){ fix_ingred_main_15(); };
    {
        int tlv2;
        tlv2 = fd;
        char* tlv1;
         tlv1 = ( char * ) ERROR_MSG;
        cgc_transmit_string(tlv2,tlv1);
    }
}

void fix_ingred_main_16_0_0();
void fix_ingred_main_16_0_1();
void fix_ingred_main_16_0();
void fix_ingred_main_16_1_0();
void fix_ingred_main_16_1();
void fix_ingred_main_16_2_0();
void fix_ingred_main_16_2_1();
void fix_ingred_main_16_2();
void fix_ingred_main_16_3_2();
void fix_ingred_main_16_3_3();
void fix_ingred_main_16_3();
void fix_ingred_main_16_4_0();
void fix_ingred_main_16_4();
void fix_ingred_main_16_6_3();
void fix_ingred_main_16_6_4();
void fix_ingred_main_16_6();
void fix_ingred_main_16_7_0();
void fix_ingred_main_16_7();
void fix_ingred_main_16_16_0();
void fix_ingred_main_16_16();
void fix_ingred_main_16_17_0();
void fix_ingred_main_16_17_1();
void fix_ingred_main_16_17();
void fix_ingred_main_16_19_2();
void fix_ingred_main_16_19();
void fix_ingred_main_16();
char *cgc_nth_word(unsigned n, char *input, int to_end)
{
if (fix_ingred_enable){ fix_ingred_main_16(); };
    cgc_size_t len;
    {
        const char* tlv5 = input;
        len = cgc_strlen(tlv5);
    }
    char *word_start[128];
    char* p;
     p = input;
    {
        void* tlv4;
        tlv4 = word_start;
        int tlv3;
        tlv3 = '\0';
        cgc_size_t tlv2;
        tlv2 = 128 * sizeof ( char * );
        cgc_memset(tlv4,tlv3,tlv2);
    }
    for (cgc_size_t i = 0; i < 128; i++) {
 int tlv1;
 {
     int tlv8;
     tlv8 = * p;
     tlv1 = cgc_isspace(tlv8);
 }
	if (*p && tlv1) {
	    p++;
	}
	if (p >= input + len) {
	    break;
	}
	word_start[i] = p;
 {
     const char* tlv10 = p;
     int tlv9;
     tlv9 = ' ';
    	p = cgc_strchr(tlv10,tlv9);
 }
	if (!p) {
	    break;
	}
    }
    p = word_start[n];
    if (!p) {
	return ((void *) 0);
    }
    char* end;
     end = ( ( void * ) 0 );
    if (!to_end) {
 {
     const char* tlv12 = p;
     int tlv11;
     tlv11 = ' ';
    	end = cgc_strchr(tlv12,tlv11);
 }
    }
    if (!end) {
 {
     const char* tlv14 = p;
     int tlv13;
     tlv13 = '\0';
    	end = cgc_strchr(tlv14,tlv13);
 }
    }
    if (!end) {
	( {
	 cgc_fdprintf(2, "ERROR %s:%d:\t" "malformed string" "\n", "src/main.c", 389);
  {
      int tlv15;
      tlv15 = 1;
    	 cgc_exit(tlv15);
  }
	 }
	);
    }
    char* res;
     {
         cgc_size_t tlv7;
         tlv7 = sizeof ( char );
         cgc_size_t tlv6;
         tlv6 = end - p + 1;
         res = cgc_calloc(tlv7,tlv6);
     }
    ( {
     if (res == ((void *) 0)) {
     ( {
      cgc_fdprintf(2, "ERROR %s:%d:\t" "bad alloc" "\n", "src/main.c", 392); 
 {
     int tlv16;
     tlv16 = 1;
     cgc_exit(tlv16);
 }
;});
;}});
    return cgc_strncpy(res, p, end - p);
}

void fix_ingred_main_17_1_0();
void fix_ingred_main_17_1_1();
void fix_ingred_main_17_1();
void fix_ingred_main_17_2_0();
void fix_ingred_main_17_2_1();
void fix_ingred_main_17_2_2();
void fix_ingred_main_17_2();
void fix_ingred_main_17_3_0();
void fix_ingred_main_17_3_1();
void fix_ingred_main_17_3_2();
void fix_ingred_main_17_3();
void fix_ingred_main_17_5_2();
void fix_ingred_main_17_5();
void fix_ingred_main_17();
char **cgc_make_argv(char *input, cgc_size_t n)
{
if (fix_ingred_enable){ fix_ingred_main_17(); };
    char** argv;
     {
         cgc_size_t tlv2;
         tlv2 = sizeof ( char * );
         cgc_size_t tlv1;
         tlv1 = n;
         argv = cgc_calloc(tlv2,tlv1);
     }
    cgc_size_t i;
    for (i = 0; i < n - 1; i++) {
 {
     unsigned  tlv8;
     tlv8 = i + 1;
     char* tlv7;
      tlv7 = input;
     int tlv6;
     tlv6 = 0;
    	argv[i] = cgc_nth_word(tlv8,tlv7,tlv6);
 }
	if (!argv[i]) {
	    goto error;
	}
    }
    {
        unsigned  tlv5;
        tlv5 = i + 1;
        char* tlv4;
         tlv4 = input;
        int tlv3;
        tlv3 = 1;
        argv[i] = cgc_nth_word(tlv5,tlv4,tlv3);
    }
    if (!argv[i]) {
	goto error;
    }
    return argv;
  error:
    for (cgc_size_t i = 1; i < n - 1; i++)
    {
	if (argv[i]) {
	    cgc_free(argv[i]);
	}
    }
    cgc_free(argv);
    return ((void *) 0);
}

void fix_ingred_main_18();
void cgc_print_argv(char **argv, cgc_size_t n)
{
if (fix_ingred_enable){ fix_ingred_main_18(); };
    for (cgc_size_t i = 0; i < n; i++)
    {
	if (argv[i]) {;
	}
    }
}

void fix_ingred_main_19();
void cgc_free_argv(char **argv, cgc_size_t n)
{
if (fix_ingred_enable){ fix_ingred_main_19(); };
    if (!argv || !n) {
	return;
    }
    for (cgc_size_t i = 0; i < n; i++)
    {
	if (argv[i]) {
	    cgc_free(argv[i]);
	}
    }
    cgc_free(argv);
}

#454 "src/main.c"
void fix_ingred_main_20_2_0();
void fix_ingred_main_20_2();
void fix_ingred_main_20_3_0();
void fix_ingred_main_20_3_1();
void fix_ingred_main_20_3_2();
void fix_ingred_main_20_3();
void fix_ingred_main_20_4_0();
void fix_ingred_main_20_4_2();
void fix_ingred_main_20_4_3();
void fix_ingred_main_20_4();
void fix_ingred_main_20_5_0();
void fix_ingred_main_20_5();
void fix_ingred_main_20_6_0();
void fix_ingred_main_20_6();
void fix_ingred_main_20_7_0();
void fix_ingred_main_20_7();
void fix_ingred_main_20_9_0();
void fix_ingred_main_20_9();
void fix_ingred_main_20_12_0();
void fix_ingred_main_20_12();
void fix_ingred_main_20_13_1();
void fix_ingred_main_20_13();
void fix_ingred_main_20_15_1();
void fix_ingred_main_20_15();
void fix_ingred_main_20_17_0();
void fix_ingred_main_20_17_1();
void fix_ingred_main_20_17();
void fix_ingred_main_20_23_0();
void fix_ingred_main_20_23();
void fix_ingred_main_20_24_1();
void fix_ingred_main_20_24();
void fix_ingred_main_20_27_0();
void fix_ingred_main_20_27();
void fix_ingred_main_20_32_0();
void fix_ingred_main_20_32();
void fix_ingred_main_20_33_1();
void fix_ingred_main_20_33();
void fix_ingred_main_20_34_1();
void fix_ingred_main_20_34();
void fix_ingred_main_20_36_0();
void fix_ingred_main_20_36();
void fix_ingred_main_20_41_0();
void fix_ingred_main_20_41();
void fix_ingred_main_20_42_1();
void fix_ingred_main_20_42();
void fix_ingred_main_20_52_1();
void fix_ingred_main_20_52();
void fix_ingred_main_20();
int main(int cgc_argc, char *cgc_argv[])
{
if (fix_ingred_enable){ fix_ingred_main_20(); };
    char input_buf[(16 * 1024)];
    const char *resp;
    for (;;) {
 {
     int tlv8;
     tlv8 = 1;
    	cgc_prompt(tlv8);
 }
 {
     void* tlv11;
     tlv11 = input_buf;
     int tlv10;
     tlv10 = '\0';
     cgc_size_t tlv9;
     tlv9 = ( 16 * 1024 );
    	cgc_memset(tlv11,tlv10,tlv9);
 }
 int tlv1;
 {
     int tlv15;
     tlv15 = 0;
     cgc_size_t tlv14;
     tlv14 = ( 16 * 1024 );
     char tlv13;
     tlv13 = '\n';
     char* tlv12;
      tlv12 = input_buf;
     tlv1 = cgc_read_until(tlv15,tlv14,tlv13,tlv12);
 }
	if (tlv1 < 0) {
	    break;
	}
 int tlv2;
 {
     const char* tlv18 = input_buf;
     const char tlv17 [ ] = "quit";
     cgc_size_t tlv16;
     tlv16 = 4;
     tlv2 = cgc_strncmp(tlv18,tlv17,tlv16);
 }
	if (tlv2 == 0) {
     {
         int tlv25;
         tlv25 = 0;
    	    cgc_exit(tlv25);
     }
	}
 char* command;
  {
      unsigned  tlv21;
      tlv21 = 0;
      char* tlv20;
       tlv20 = input_buf;
      int tlv19;
      tlv19 = 0;
      command = cgc_nth_word(tlv21,tlv20,tlv19);
  }
 char** argv;
  argv = ( ( void * ) 0 );
	if (!command) {
	    continue;
	}
 int tlv3;
 {
     const char* tlv24 = command;
     const char tlv23 [ ] = "new-note";
     cgc_size_t tlv22;
     {
         const char tlv67 [ ] = "new-note";
         tlv22 = cgc_strlen(tlv67);
     }
     tlv3 = cgc_strncmp(tlv24,tlv23,tlv22);
 }
	if (tlv3 == 0) {
     {
         list_t** tlv26;
         tlv26 = & cgc_thunks;
    	    cgc_run_thunk(tlv26);
     }
     {
         char* tlv30;
          tlv30 = input_buf;
         cgc_size_t tlv29;
         tlv29 = 2;
    	    argv = cgc_make_argv(tlv30,tlv29);
     }
	    if (argv) {
  note_t* tlv5;
  {
      char* tlv37;
       tlv37 = argv [ 0 ];
      char* tlv36;
       tlv36 = argv [ 1 ];
      tlv5 = cgc_new_note(tlv37,tlv36);
  }
		if (tlv5 == ((void *) 0)) {
		    resp = NOTE_FULL;
		} else {
		    resp = NOTE_CREATED;
		}
  {
      char** tlv35;
       tlv35 = argv;
      cgc_size_t tlv34;
      tlv34 = 2;
    		cgc_free_argv(tlv35,tlv34);
  }
	    }
	} else {
     int tlv4;
     {
         const char* tlv33 = command;
         const char tlv32 [ ] = "append-note";
         cgc_size_t tlv31;
         {
             const char tlv68 [ ] = "append-note";
             tlv31 = cgc_strlen(tlv68);
         }
         tlv4 = cgc_strncmp(tlv33,tlv32,tlv31);
     }
	    if (tlv4 == 0) {
  {
      char* tlv39;
       tlv39 = input_buf;
      cgc_size_t tlv38;
      tlv38 = 2;
    		argv = cgc_make_argv(tlv39,tlv38);
  }
		if (argv) {
      thunk_t* thunk;
      {
          thunk_fp_t tlv49 = cgc_append_thunk;
          unsigned  tlv48;
          tlv48 = 2;
          char** tlv47;
           tlv47 = argv;
          thunk = cgc_new_thunk(tlv49,tlv48,tlv47);
      }
      {
          list_t** tlv44;
          tlv44 = & cgc_thunks;
          thunk_t* tlv43;
          tlv43 = thunk;
    		    cgc_append_list(tlv44,tlv43);
      }
		    resp = NOTE_APPENDED;
      {
          char** tlv46;
           tlv46 = argv;
          cgc_size_t tlv45;
          tlv45 = 2;
    		    cgc_free_argv(tlv46,tlv45);
      }
		}
	    } else {
  int tlv6;
  {
      const char* tlv42 = command;
      const char tlv41 [ ] = "delete-note";
      cgc_size_t tlv40;
      {
          const char tlv69 [ ] = "delete-note";
          tlv40 = cgc_strlen(tlv69);
      }
      tlv6 = cgc_strncmp(tlv42,tlv41,tlv40);
  }
		if (tlv6 == 0) {
      {
          char* tlv51;
           tlv51 = input_buf;
          cgc_size_t tlv50;
          tlv50 = 1;
    		    argv = cgc_make_argv(tlv51,tlv50);
      }
		    if (argv) {
   thunk_t* thunk;
   {
       thunk_fp_t tlv63 = cgc_delete_thunk;
       unsigned  tlv62;
       tlv62 = 1;
       char** tlv61;
        tlv61 = argv;
       thunk = cgc_new_thunk(tlv63,tlv62,tlv61);
   }
   {
       list_t** tlv56;
       tlv56 = & cgc_thunks;
       thunk_t* tlv55;
       tlv55 = thunk;
    			cgc_append_list(tlv56,tlv55);
   }
			resp = NOTE_DELETED;
   {
       char** tlv58;
        tlv58 = argv;
       cgc_size_t tlv57;
       tlv57 = 1;
    			cgc_free_argv(tlv58,tlv57);
   }
		    }
		} else {
      int tlv7;
      {
          const char* tlv54 = command;
          const char tlv53 [ ] = "get-note";
          cgc_size_t tlv52;
          {
              const char tlv70 [ ] = "get-note";
              tlv52 = cgc_strlen(tlv70);
          }
          tlv7 = cgc_strncmp(tlv54,tlv53,tlv52);
      }
		    if (tlv7 == 0) {
   {
       list_t** tlv59;
       tlv59 = & cgc_thunks;
    			cgc_run_thunk(tlv59);
   }
   {
       char* tlv65;
        tlv65 = input_buf;
       cgc_size_t tlv64;
       tlv64 = 1;
    			argv = cgc_make_argv(tlv65,tlv64);
   }
			if (argv) {
       note_t* note;
       {
           char* tlv66;
            tlv66 = argv [ 0 ];
           note = cgc_get_note(tlv66);
       }
			    if (note) {
				cgc_fdprintf(1, "%s\n", note->buf);
			    } else {
				resp = NOTE_UNK;
			    }
			}
		    } else {
   {
       int tlv60;
       tlv60 = 1;
    			cgc_yell(tlv60);
   }
		    }
		}
	    }
	}
	if (resp) {
     {
         int tlv28;
         tlv28 = 1;
         char* tlv27;
          tlv27 = ( char * ) resp;
    	    cgc_transmit_string(tlv28,tlv27);
     }
	}
	resp = ((void *) 0);
	cgc_free(command);
    }
}

void fix_ingred_main_0(){
}
void fix_ingred_main_1(){
}
void fix_ingred_main_2_2_0(){
char title_ref;
    bzero(&title_ref,1*sizeof(char));
char * title = &title_ref;
    {cgc_size_t data_size; data_size = (cgc_size_t)(title); }
    {cgc_size_t i; i = (cgc_size_t)(title); }
    {char * tlv4; tlv4 = (char *)(title); }
    {cgc_size_t tlv6; tlv6 = (cgc_size_t)(title); }
    {cgc_size_t tlv5; tlv5 = (cgc_size_t)(title); }
    {cgc_size_t tlv9; tlv9 = (cgc_size_t)(title); }
    {cgc_size_t tlv8; tlv8 = (cgc_size_t)(title); }
    {char * tlv3; tlv3 = (char *)(title); }
    {cgc_size_t tlv15; tlv15 = (cgc_size_t)(title); }
    {cgc_size_t tlv14; tlv14 = (cgc_size_t)(title); }
    {char * tlv11; tlv11 = (char *)(title); }
    {cgc_size_t tlv17; tlv17 = (cgc_size_t)(title); }
    {cgc_size_t tlv16; tlv16 = (cgc_size_t)(title); }
    {char * tlv13; tlv13 = (char *)(title); }
    {int tlv18; tlv18 = (int)(title); }
    {int tlv19; tlv19 = (int)(title); }
    {int tlv20; tlv20 = (int)(title); }
    {int tlv21; tlv21 = (int)(title); }
}
void fix_ingred_main_2_2(){
fix_ingred_main_2_2_0();
}
void fix_ingred_main_2_4_0(){
    {cgc_size_t data_size; data_size = (cgc_size_t)(sizeof ( note_t )); }
    {cgc_size_t i; i = (cgc_size_t)(sizeof ( note_t )); }
    {char * tlv4; tlv4 = (char *)(sizeof ( note_t )); }
    {cgc_size_t tlv6; tlv6 = (cgc_size_t)(sizeof ( note_t )); }
    {cgc_size_t tlv5; tlv5 = (cgc_size_t)(sizeof ( note_t )); }
    {cgc_size_t tlv9; tlv9 = (cgc_size_t)(sizeof ( note_t )); }
    {cgc_size_t tlv8; tlv8 = (cgc_size_t)(sizeof ( note_t )); }
    {char * tlv3; tlv3 = (char *)(sizeof ( note_t )); }
    {cgc_size_t tlv15; tlv15 = (cgc_size_t)(sizeof ( note_t )); }
    {cgc_size_t tlv14; tlv14 = (cgc_size_t)(sizeof ( note_t )); }
    {char * tlv11; tlv11 = (char *)(sizeof ( note_t )); }
    {cgc_size_t tlv17; tlv17 = (cgc_size_t)(sizeof ( note_t )); }
    {cgc_size_t tlv16; tlv16 = (cgc_size_t)(sizeof ( note_t )); }
    {char * tlv13; tlv13 = (char *)(sizeof ( note_t )); }
    {int tlv18; tlv18 = (int)(sizeof ( note_t )); }
    {int tlv19; tlv19 = (int)(sizeof ( note_t )); }
    {int tlv20; tlv20 = (int)(sizeof ( note_t )); }
    {int tlv21; tlv21 = (int)(sizeof ( note_t )); }
}
void fix_ingred_main_2_4_1(){
    {cgc_size_t data_size; data_size = (cgc_size_t)(1); }
    {cgc_size_t i; i = (cgc_size_t)(1); }
    {char * tlv4; tlv4 = (char *)(1); }
    {cgc_size_t tlv6; tlv6 = (cgc_size_t)(1); }
    {cgc_size_t tlv5; tlv5 = (cgc_size_t)(1); }
    {cgc_size_t tlv9; tlv9 = (cgc_size_t)(1); }
    {cgc_size_t tlv8; tlv8 = (cgc_size_t)(1); }
    {char * tlv3; tlv3 = (char *)(1); }
    {cgc_size_t tlv15; tlv15 = (cgc_size_t)(1); }
    {cgc_size_t tlv14; tlv14 = (cgc_size_t)(1); }
    {char * tlv11; tlv11 = (char *)(1); }
    {cgc_size_t tlv17; tlv17 = (cgc_size_t)(1); }
    {cgc_size_t tlv16; tlv16 = (cgc_size_t)(1); }
    {char * tlv13; tlv13 = (char *)(1); }
    {int tlv18; tlv18 = (int)(1); }
    {int tlv19; tlv19 = (int)(1); }
    {int tlv20; tlv20 = (int)(1); }
    {int tlv21; tlv21 = (int)(1); }
}
void fix_ingred_main_2_4(){
fix_ingred_main_2_4_0();
fix_ingred_main_2_4_1();
}
void fix_ingred_main_2_8_0(){
    {cgc_size_t data_size; data_size = (cgc_size_t)(1); }
    {cgc_size_t i; i = (cgc_size_t)(1); }
    {char * tlv4; tlv4 = (char *)(1); }
    {cgc_size_t tlv6; tlv6 = (cgc_size_t)(1); }
    {cgc_size_t tlv5; tlv5 = (cgc_size_t)(1); }
    {cgc_size_t tlv9; tlv9 = (cgc_size_t)(1); }
    {cgc_size_t tlv8; tlv8 = (cgc_size_t)(1); }
    {char * tlv3; tlv3 = (char *)(1); }
    {cgc_size_t tlv15; tlv15 = (cgc_size_t)(1); }
    {cgc_size_t tlv14; tlv14 = (cgc_size_t)(1); }
    {char * tlv11; tlv11 = (char *)(1); }
    {cgc_size_t tlv17; tlv17 = (cgc_size_t)(1); }
    {cgc_size_t tlv16; tlv16 = (cgc_size_t)(1); }
    {char * tlv13; tlv13 = (char *)(1); }
    {int tlv18; tlv18 = (int)(1); }
    {int tlv19; tlv19 = (int)(1); }
    {int tlv20; tlv20 = (int)(1); }
    {int tlv21; tlv21 = (int)(1); }
}
void fix_ingred_main_2_8(){
fix_ingred_main_2_8_0();
}
void fix_ingred_main_2_9_0(){
char tlv7_ref;
    bzero(&tlv7_ref,1*sizeof(char));
const char * tlv7 = &tlv7_ref;
    {cgc_size_t data_size; data_size = (cgc_size_t)(cgc_strlen ( tlv7 )); }
    {cgc_size_t i; i = (cgc_size_t)(cgc_strlen ( tlv7 )); }
    {char * tlv4; tlv4 = (char *)(cgc_strlen ( tlv7 )); }
    {cgc_size_t tlv6; tlv6 = (cgc_size_t)(cgc_strlen ( tlv7 )); }
    {cgc_size_t tlv5; tlv5 = (cgc_size_t)(cgc_strlen ( tlv7 )); }
    {cgc_size_t tlv9; tlv9 = (cgc_size_t)(cgc_strlen ( tlv7 )); }
    {cgc_size_t tlv8; tlv8 = (cgc_size_t)(cgc_strlen ( tlv7 )); }
    {char * tlv3; tlv3 = (char *)(cgc_strlen ( tlv7 )); }
    {cgc_size_t tlv15; tlv15 = (cgc_size_t)(cgc_strlen ( tlv7 )); }
    {cgc_size_t tlv14; tlv14 = (cgc_size_t)(cgc_strlen ( tlv7 )); }
    {char * tlv11; tlv11 = (char *)(cgc_strlen ( tlv7 )); }
    {cgc_size_t tlv17; tlv17 = (cgc_size_t)(cgc_strlen ( tlv7 )); }
    {cgc_size_t tlv16; tlv16 = (cgc_size_t)(cgc_strlen ( tlv7 )); }
    {char * tlv13; tlv13 = (char *)(cgc_strlen ( tlv7 )); }
    {int tlv18; tlv18 = (int)(cgc_strlen ( tlv7 )); }
    {int tlv19; tlv19 = (int)(cgc_strlen ( tlv7 )); }
    {int tlv20; tlv20 = (int)(cgc_strlen ( tlv7 )); }
    {int tlv21; tlv21 = (int)(cgc_strlen ( tlv7 )); }
}
void fix_ingred_main_2_9(){
fix_ingred_main_2_9_0();
}
void fix_ingred_main_2_10_2(){
cgc_size_t data_size;
    bzero(&data_size,sizeof(cgc_size_t));
    {cgc_size_t i; i = (cgc_size_t)(data_size + 1); }
    {char * tlv4; tlv4 = (char *)(data_size + 1); }
    {cgc_size_t tlv6; tlv6 = (cgc_size_t)(data_size + 1); }
    {cgc_size_t tlv5; tlv5 = (cgc_size_t)(data_size + 1); }
    {cgc_size_t tlv9; tlv9 = (cgc_size_t)(data_size + 1); }
    {cgc_size_t tlv8; tlv8 = (cgc_size_t)(data_size + 1); }
    {char * tlv3; tlv3 = (char *)(data_size + 1); }
    {cgc_size_t tlv15; tlv15 = (cgc_size_t)(data_size + 1); }
    {cgc_size_t tlv14; tlv14 = (cgc_size_t)(data_size + 1); }
    {char * tlv11; tlv11 = (char *)(data_size + 1); }
    {cgc_size_t tlv17; tlv17 = (cgc_size_t)(data_size + 1); }
    {cgc_size_t tlv16; tlv16 = (cgc_size_t)(data_size + 1); }
    {char * tlv13; tlv13 = (char *)(data_size + 1); }
    {int tlv18; tlv18 = (int)(data_size + 1); }
    {int tlv19; tlv19 = (int)(data_size + 1); }
    {int tlv20; tlv20 = (int)(data_size + 1); }
    {int tlv21; tlv21 = (int)(data_size + 1); }
}
void fix_ingred_main_2_10_3(){
cgc_size_t data_size;
    bzero(&data_size,sizeof(cgc_size_t));
    {cgc_size_t data_size; data_size = (cgc_size_t)(( 1024 )); }
    {cgc_size_t i; i = (cgc_size_t)(( 1024 )); }
    {char * tlv4; tlv4 = (char *)(( 1024 )); }
    {cgc_size_t tlv6; tlv6 = (cgc_size_t)(( 1024 )); }
    {cgc_size_t tlv5; tlv5 = (cgc_size_t)(( 1024 )); }
    {cgc_size_t tlv9; tlv9 = (cgc_size_t)(( 1024 )); }
    {cgc_size_t tlv8; tlv8 = (cgc_size_t)(( 1024 )); }
    {char * tlv3; tlv3 = (char *)(( 1024 )); }
    {cgc_size_t tlv15; tlv15 = (cgc_size_t)(( 1024 )); }
    {cgc_size_t tlv14; tlv14 = (cgc_size_t)(( 1024 )); }
    {char * tlv11; tlv11 = (char *)(( 1024 )); }
    {cgc_size_t tlv17; tlv17 = (cgc_size_t)(( 1024 )); }
    {cgc_size_t tlv16; tlv16 = (cgc_size_t)(( 1024 )); }
    {char * tlv13; tlv13 = (char *)(( 1024 )); }
    {int tlv18; tlv18 = (int)(( 1024 )); }
    {int tlv19; tlv19 = (int)(( 1024 )); }
    {int tlv20; tlv20 = (int)(( 1024 )); }
    {int tlv21; tlv21 = (int)(( 1024 )); }
}
void fix_ingred_main_2_10(){
fix_ingred_main_2_10_2();
fix_ingred_main_2_10_3();
}
void fix_ingred_main_2_11_0(){
    {cgc_size_t data_size; data_size = (cgc_size_t)(sizeof ( char )); }
    {cgc_size_t i; i = (cgc_size_t)(sizeof ( char )); }
    {char * tlv4; tlv4 = (char *)(sizeof ( char )); }
    {cgc_size_t tlv6; tlv6 = (cgc_size_t)(sizeof ( char )); }
    {cgc_size_t tlv5; tlv5 = (cgc_size_t)(sizeof ( char )); }
    {cgc_size_t tlv9; tlv9 = (cgc_size_t)(sizeof ( char )); }
    {cgc_size_t tlv8; tlv8 = (cgc_size_t)(sizeof ( char )); }
    {char * tlv3; tlv3 = (char *)(sizeof ( char )); }
    {cgc_size_t tlv15; tlv15 = (cgc_size_t)(sizeof ( char )); }
    {cgc_size_t tlv14; tlv14 = (cgc_size_t)(sizeof ( char )); }
    {char * tlv11; tlv11 = (char *)(sizeof ( char )); }
    {cgc_size_t tlv17; tlv17 = (cgc_size_t)(sizeof ( char )); }
    {cgc_size_t tlv16; tlv16 = (cgc_size_t)(sizeof ( char )); }
    {char * tlv13; tlv13 = (char *)(sizeof ( char )); }
    {int tlv18; tlv18 = (int)(sizeof ( char )); }
    {int tlv19; tlv19 = (int)(sizeof ( char )); }
    {int tlv20; tlv20 = (int)(sizeof ( char )); }
    {int tlv21; tlv21 = (int)(sizeof ( char )); }
}
void fix_ingred_main_2_11(){
fix_ingred_main_2_11_0();
}
void fix_ingred_main_2_16_0(){
note_t note_ref;
    bzero(&note_ref,1*sizeof(note_t));
note_t * note = &note_ref;
    {cgc_size_t data_size; data_size = (cgc_size_t)(note -> buf); }
    {cgc_size_t i; i = (cgc_size_t)(note -> buf); }
    {char * tlv4; tlv4 = (char *)(note -> buf); }
    {cgc_size_t tlv6; tlv6 = (cgc_size_t)(note -> buf); }
    {cgc_size_t tlv5; tlv5 = (cgc_size_t)(note -> buf); }
    {cgc_size_t tlv9; tlv9 = (cgc_size_t)(note -> buf); }
    {cgc_size_t tlv8; tlv8 = (cgc_size_t)(note -> buf); }
    {char * tlv3; tlv3 = (char *)(note -> buf); }
    {cgc_size_t tlv15; tlv15 = (cgc_size_t)(note -> buf); }
    {cgc_size_t tlv14; tlv14 = (cgc_size_t)(note -> buf); }
    {char * tlv11; tlv11 = (char *)(note -> buf); }
    {cgc_size_t tlv17; tlv17 = (cgc_size_t)(note -> buf); }
    {cgc_size_t tlv16; tlv16 = (cgc_size_t)(note -> buf); }
    {char * tlv13; tlv13 = (char *)(note -> buf); }
    {int tlv18; tlv18 = (int)(note -> buf); }
    {int tlv19; tlv19 = (int)(note -> buf); }
    {int tlv20; tlv20 = (int)(note -> buf); }
    {int tlv21; tlv21 = (int)(note -> buf); }
}
void fix_ingred_main_2_16(){
fix_ingred_main_2_16_0();
}
void fix_ingred_main_2_25_0(){
char tlv22_ref;
    bzero(&tlv22_ref,1*sizeof(char));
const char * tlv22 = &tlv22_ref;
    {cgc_size_t data_size; data_size = (cgc_size_t)(cgc_strlen ( tlv22 ) + 1); }
    {cgc_size_t i; i = (cgc_size_t)(cgc_strlen ( tlv22 ) + 1); }
    {char * tlv4; tlv4 = (char *)(cgc_strlen ( tlv22 ) + 1); }
    {cgc_size_t tlv6; tlv6 = (cgc_size_t)(cgc_strlen ( tlv22 ) + 1); }
    {cgc_size_t tlv5; tlv5 = (cgc_size_t)(cgc_strlen ( tlv22 ) + 1); }
    {cgc_size_t tlv9; tlv9 = (cgc_size_t)(cgc_strlen ( tlv22 ) + 1); }
    {cgc_size_t tlv8; tlv8 = (cgc_size_t)(cgc_strlen ( tlv22 ) + 1); }
    {char * tlv3; tlv3 = (char *)(cgc_strlen ( tlv22 ) + 1); }
    {cgc_size_t tlv15; tlv15 = (cgc_size_t)(cgc_strlen ( tlv22 ) + 1); }
    {cgc_size_t tlv14; tlv14 = (cgc_size_t)(cgc_strlen ( tlv22 ) + 1); }
    {char * tlv11; tlv11 = (char *)(cgc_strlen ( tlv22 ) + 1); }
    {cgc_size_t tlv17; tlv17 = (cgc_size_t)(cgc_strlen ( tlv22 ) + 1); }
    {cgc_size_t tlv16; tlv16 = (cgc_size_t)(cgc_strlen ( tlv22 ) + 1); }
    {char * tlv13; tlv13 = (char *)(cgc_strlen ( tlv22 ) + 1); }
    {int tlv18; tlv18 = (int)(cgc_strlen ( tlv22 ) + 1); }
    {int tlv19; tlv19 = (int)(cgc_strlen ( tlv22 ) + 1); }
    {int tlv20; tlv20 = (int)(cgc_strlen ( tlv22 ) + 1); }
    {int tlv21; tlv21 = (int)(cgc_strlen ( tlv22 ) + 1); }
}
void fix_ingred_main_2_25(){
fix_ingred_main_2_25_0();
}
void fix_ingred_main_2_30_0(){
note_t note_ref;
    bzero(&note_ref,1*sizeof(note_t));
note_t * note = &note_ref;
char title_ref;
    bzero(&title_ref,1*sizeof(char));
char * title = &title_ref;
    {cgc_size_t data_size; data_size = (cgc_size_t)(note -> title); }
    {cgc_size_t i; i = (cgc_size_t)(note -> title); }
    {char * tlv4; tlv4 = (char *)(note -> title); }
    {cgc_size_t tlv6; tlv6 = (cgc_size_t)(note -> title); }
    {cgc_size_t tlv5; tlv5 = (cgc_size_t)(note -> title); }
    {cgc_size_t tlv9; tlv9 = (cgc_size_t)(note -> title); }
    {cgc_size_t tlv8; tlv8 = (cgc_size_t)(note -> title); }
    {char * tlv3; tlv3 = (char *)(note -> title); }
    {cgc_size_t tlv15; tlv15 = (cgc_size_t)(note -> title); }
    {cgc_size_t tlv14; tlv14 = (cgc_size_t)(note -> title); }
    {char * tlv11; tlv11 = (char *)(note -> title); }
    {cgc_size_t tlv17; tlv17 = (cgc_size_t)(note -> title); }
    {cgc_size_t tlv16; tlv16 = (cgc_size_t)(note -> title); }
    {char * tlv13; tlv13 = (char *)(note -> title); }
    {int tlv18; tlv18 = (int)(note -> title); }
    {int tlv19; tlv19 = (int)(note -> title); }
    {int tlv20; tlv20 = (int)(note -> title); }
    {int tlv21; tlv21 = (int)(note -> title); }
}
void fix_ingred_main_2_30(){
fix_ingred_main_2_30_0();
}
void fix_ingred_main_2_31_0(){
cgc_size_t i;
    bzero(&i,sizeof(cgc_size_t));
    {cgc_size_t data_size; data_size = (cgc_size_t)(0); }
    {cgc_size_t i; i = (cgc_size_t)(0); }
    {char * tlv4; tlv4 = (char *)(0); }
    {cgc_size_t tlv6; tlv6 = (cgc_size_t)(0); }
    {cgc_size_t tlv5; tlv5 = (cgc_size_t)(0); }
    {cgc_size_t tlv9; tlv9 = (cgc_size_t)(0); }
    {cgc_size_t tlv8; tlv8 = (cgc_size_t)(0); }
    {char * tlv3; tlv3 = (char *)(0); }
    {cgc_size_t tlv15; tlv15 = (cgc_size_t)(0); }
    {cgc_size_t tlv14; tlv14 = (cgc_size_t)(0); }
    {char * tlv11; tlv11 = (char *)(0); }
    {cgc_size_t tlv17; tlv17 = (cgc_size_t)(0); }
    {cgc_size_t tlv16; tlv16 = (cgc_size_t)(0); }
    {char * tlv13; tlv13 = (char *)(0); }
    {int tlv18; tlv18 = (int)(0); }
    {int tlv19; tlv19 = (int)(0); }
    {int tlv20; tlv20 = (int)(0); }
    {int tlv21; tlv21 = (int)(0); }
}
void fix_ingred_main_2_31_1(){
cgc_size_t i;
    bzero(&i,sizeof(cgc_size_t));
    {cgc_size_t data_size; data_size = (cgc_size_t)(i); }
    {char * tlv4; tlv4 = (char *)(i); }
    {cgc_size_t tlv6; tlv6 = (cgc_size_t)(i); }
    {cgc_size_t tlv5; tlv5 = (cgc_size_t)(i); }
    {cgc_size_t tlv9; tlv9 = (cgc_size_t)(i); }
    {cgc_size_t tlv8; tlv8 = (cgc_size_t)(i); }
    {char * tlv3; tlv3 = (char *)(i); }
    {cgc_size_t tlv15; tlv15 = (cgc_size_t)(i); }
    {cgc_size_t tlv14; tlv14 = (cgc_size_t)(i); }
    {char * tlv11; tlv11 = (char *)(i); }
    {cgc_size_t tlv17; tlv17 = (cgc_size_t)(i); }
    {cgc_size_t tlv16; tlv16 = (cgc_size_t)(i); }
    {char * tlv13; tlv13 = (char *)(i); }
    {int tlv18; tlv18 = (int)(i); }
    {int tlv19; tlv19 = (int)(i); }
    {int tlv20; tlv20 = (int)(i); }
    {int tlv21; tlv21 = (int)(i); }
}
void fix_ingred_main_2_31_2(){
cgc_size_t i;
    bzero(&i,sizeof(cgc_size_t));
    {cgc_size_t data_size; data_size = (cgc_size_t)(( 512 )); }
    {cgc_size_t i; i = (cgc_size_t)(( 512 )); }
    {char * tlv4; tlv4 = (char *)(( 512 )); }
    {cgc_size_t tlv6; tlv6 = (cgc_size_t)(( 512 )); }
    {cgc_size_t tlv5; tlv5 = (cgc_size_t)(( 512 )); }
    {cgc_size_t tlv9; tlv9 = (cgc_size_t)(( 512 )); }
    {cgc_size_t tlv8; tlv8 = (cgc_size_t)(( 512 )); }
    {char * tlv3; tlv3 = (char *)(( 512 )); }
    {cgc_size_t tlv15; tlv15 = (cgc_size_t)(( 512 )); }
    {cgc_size_t tlv14; tlv14 = (cgc_size_t)(( 512 )); }
    {char * tlv11; tlv11 = (char *)(( 512 )); }
    {cgc_size_t tlv17; tlv17 = (cgc_size_t)(( 512 )); }
    {cgc_size_t tlv16; tlv16 = (cgc_size_t)(( 512 )); }
    {char * tlv13; tlv13 = (char *)(( 512 )); }
    {int tlv18; tlv18 = (int)(( 512 )); }
    {int tlv19; tlv19 = (int)(( 512 )); }
    {int tlv20; tlv20 = (int)(( 512 )); }
    {int tlv21; tlv21 = (int)(( 512 )); }
}
void fix_ingred_main_2_31(){
fix_ingred_main_2_31_0();
fix_ingred_main_2_31_1();
fix_ingred_main_2_31_2();
}
void fix_ingred_main_2(){
fix_ingred_main_2_2();
fix_ingred_main_2_4();
fix_ingred_main_2_8();
fix_ingred_main_2_9();
fix_ingred_main_2_10();
fix_ingred_main_2_11();
fix_ingred_main_2_16();
fix_ingred_main_2_25();
fix_ingred_main_2_30();
fix_ingred_main_2_31();
}
void fix_ingred_main_3_2_0(){
char tlv4_ref;
    bzero(&tlv4_ref,1*sizeof(char));
const char * tlv4 = &tlv4_ref;
    {cgc_size_t tlv1; tlv1 = (cgc_size_t)(cgc_strlen ( tlv4 )); }
    {char * tlv3; tlv3 = (char *)(cgc_strlen ( tlv4 )); }
    {void * tlv7; tlv7 = (void *)(cgc_strlen ( tlv4 )); }
    {cgc_size_t tlv6; tlv6 = (cgc_size_t)(cgc_strlen ( tlv4 )); }
    {int tlv8; tlv8 = (int)(cgc_strlen ( tlv4 )); }
}
void fix_ingred_main_3_2(){
fix_ingred_main_3_2_0();
}
void fix_ingred_main_3_3_1(){
cgc_size_t tlv1;
    bzero(&tlv1,sizeof(cgc_size_t));
note_t note_ref;
    bzero(&note_ref,1*sizeof(note_t));
note_t * note = &note_ref;
    {char * tlv3; tlv3 = (char *)(tlv1 + note -> size + 1); }
    {void * tlv7; tlv7 = (void *)(tlv1 + note -> size + 1); }
    {cgc_size_t tlv6; tlv6 = (cgc_size_t)(tlv1 + note -> size + 1); }
    {int tlv8; tlv8 = (int)(tlv1 + note -> size + 1); }
}
void fix_ingred_main_3_3_2(){
cgc_size_t tlv1;
    bzero(&tlv1,sizeof(cgc_size_t));
note_t note_ref;
    bzero(&note_ref,1*sizeof(note_t));
note_t * note = &note_ref;
    {cgc_size_t tlv1; tlv1 = (cgc_size_t)(note -> cap); }
    {char * tlv3; tlv3 = (char *)(note -> cap); }
    {void * tlv7; tlv7 = (void *)(note -> cap); }
    {cgc_size_t tlv6; tlv6 = (cgc_size_t)(note -> cap); }
    {int tlv8; tlv8 = (int)(note -> cap); }
}
void fix_ingred_main_3_3(){
fix_ingred_main_3_3_1();
fix_ingred_main_3_3_2();
}
void fix_ingred_main_3_4_0(){
note_t note_ref;
    bzero(&note_ref,1*sizeof(note_t));
note_t * note = &note_ref;
    {cgc_size_t tlv1; tlv1 = (cgc_size_t)(note -> buf); }
    {char * tlv3; tlv3 = (char *)(note -> buf); }
    {void * tlv7; tlv7 = (void *)(note -> buf); }
    {cgc_size_t tlv6; tlv6 = (cgc_size_t)(note -> buf); }
    {int tlv8; tlv8 = (int)(note -> buf); }
}
void fix_ingred_main_3_4(){
fix_ingred_main_3_4_0();
}
void fix_ingred_main_3_8_0(){
    {cgc_size_t tlv1; tlv1 = (cgc_size_t)(1); }
    {void * tlv7; tlv7 = (void *)(1); }
    {int tlv8; tlv8 = (int)(1); }
}
void fix_ingred_main_3_8(){
fix_ingred_main_3_8_0();
}
void fix_ingred_main_3_9_0(){
note_t note_ref;
    bzero(&note_ref,1*sizeof(note_t));
note_t * note = &note_ref;
    {cgc_size_t tlv1; tlv1 = (cgc_size_t)(note -> buf); }
    {void * tlv7; tlv7 = (void *)(note -> buf); }
    {int tlv8; tlv8 = (int)(note -> buf); }
}
void fix_ingred_main_3_9(){
fix_ingred_main_3_9_0();
}
void fix_ingred_main_3(){
fix_ingred_main_3_2();
fix_ingred_main_3_3();
fix_ingred_main_3_4();
fix_ingred_main_3_8();
fix_ingred_main_3_9();
}
void fix_ingred_main_4_2_0(){
cgc_size_t i;
    bzero(&i,sizeof(cgc_size_t));
    {void * tlv1; tlv1 = (void *)(i); }
    {void * tlv2; tlv2 = (void *)(i); }
}
void fix_ingred_main_4_2_1(){
cgc_size_t i;
    bzero(&i,sizeof(cgc_size_t));
    {void * tlv1; tlv1 = (void *)(( 512 )); }
    {void * tlv2; tlv2 = (void *)(( 512 )); }
}
void fix_ingred_main_4_2(){
fix_ingred_main_4_2_0();
fix_ingred_main_4_2_1();
}
void fix_ingred_main_4_5_0(){
note_t note_ref;
    bzero(&note_ref,1*sizeof(note_t));
note_t * note = &note_ref;
    {void * tlv1; tlv1 = (void *)(note -> buf); }
    {void * tlv2; tlv2 = (void *)(note -> buf); }
}
void fix_ingred_main_4_5(){
fix_ingred_main_4_5_0();
}
void fix_ingred_main_4_7_0(){
note_t note_ref;
    bzero(&note_ref,1*sizeof(note_t));
note_t * note = &note_ref;
    {void * tlv1; tlv1 = (void *)(note -> title); }
    {void * tlv2; tlv2 = (void *)(note -> title); }
}
void fix_ingred_main_4_7(){
fix_ingred_main_4_7_0();
}
void fix_ingred_main_4(){
fix_ingred_main_4_2();
fix_ingred_main_4_5();
fix_ingred_main_4_7();
}
void fix_ingred_main_5_1_0(){
unsigned i;
    bzero(&i,sizeof(unsigned));
thunk_t thunk_ref;
    bzero(&thunk_ref,1*sizeof(thunk_t));
thunk_t * thunk = &thunk_ref;
    {void * tlv1; tlv1 = (void *)(i); }
    {void * tlv2; tlv2 = (void *)(i); }
}
void fix_ingred_main_5_1_1(){
unsigned i;
    bzero(&i,sizeof(unsigned));
thunk_t thunk_ref;
    bzero(&thunk_ref,1*sizeof(thunk_t));
thunk_t * thunk = &thunk_ref;
    {void * tlv1; tlv1 = (void *)(thunk -> arity); }
    {void * tlv2; tlv2 = (void *)(thunk -> arity); }
}
void fix_ingred_main_5_1(){
fix_ingred_main_5_1_0();
fix_ingred_main_5_1_1();
}
void fix_ingred_main_5_4_0(){
thunk_t thunk_ref;
    bzero(&thunk_ref,1*sizeof(thunk_t));
thunk_t * thunk = &thunk_ref;
    {void * tlv1; tlv1 = (void *)(thunk -> argv); }
    {void * tlv2; tlv2 = (void *)(thunk -> argv); }
}
void fix_ingred_main_5_4(){
fix_ingred_main_5_4_0();
}
void fix_ingred_main_5(){
fix_ingred_main_5_1();
fix_ingred_main_5_4();
}
void fix_ingred_main_6_1_0(){
unsigned arity;
    bzero(&arity,sizeof(unsigned));
    {cgc_size_t tlv2; tlv2 = (cgc_size_t)(arity); }
    {cgc_size_t tlv1; tlv1 = (cgc_size_t)(arity); }
    {cgc_size_t tlv4; tlv4 = (cgc_size_t)(arity); }
    {cgc_size_t tlv3; tlv3 = (cgc_size_t)(arity); }
    {cgc_size_t tlv9; tlv9 = (cgc_size_t)(arity); }
    {cgc_size_t tlv8; tlv8 = (cgc_size_t)(arity); }
    {char * tlv7; tlv7 = (char *)(arity); }
    {int tlv10; tlv10 = (int)(arity); }
    {int tlv11; tlv11 = (int)(arity); }
    {int tlv12; tlv12 = (int)(arity); }
}
void fix_ingred_main_6_1_1(){
unsigned arity;
    bzero(&arity,sizeof(unsigned));
    {cgc_size_t tlv2; tlv2 = (cgc_size_t)(4); }
    {cgc_size_t tlv1; tlv1 = (cgc_size_t)(4); }
    {cgc_size_t tlv4; tlv4 = (cgc_size_t)(4); }
    {cgc_size_t tlv3; tlv3 = (cgc_size_t)(4); }
    {cgc_size_t tlv9; tlv9 = (cgc_size_t)(4); }
    {cgc_size_t tlv8; tlv8 = (cgc_size_t)(4); }
    {char * tlv7; tlv7 = (char *)(4); }
    {int tlv10; tlv10 = (int)(4); }
    {int tlv11; tlv11 = (int)(4); }
    {int tlv12; tlv12 = (int)(4); }
}
void fix_ingred_main_6_1(){
fix_ingred_main_6_1_0();
fix_ingred_main_6_1_1();
}
void fix_ingred_main_6_2_0(){
    {cgc_size_t tlv2; tlv2 = (cgc_size_t)(sizeof ( thunk_t )); }
    {cgc_size_t tlv1; tlv1 = (cgc_size_t)(sizeof ( thunk_t )); }
    {cgc_size_t tlv4; tlv4 = (cgc_size_t)(sizeof ( thunk_t )); }
    {cgc_size_t tlv3; tlv3 = (cgc_size_t)(sizeof ( thunk_t )); }
    {cgc_size_t tlv9; tlv9 = (cgc_size_t)(sizeof ( thunk_t )); }
    {cgc_size_t tlv8; tlv8 = (cgc_size_t)(sizeof ( thunk_t )); }
    {char * tlv7; tlv7 = (char *)(sizeof ( thunk_t )); }
    {int tlv10; tlv10 = (int)(sizeof ( thunk_t )); }
    {int tlv11; tlv11 = (int)(sizeof ( thunk_t )); }
    {int tlv12; tlv12 = (int)(sizeof ( thunk_t )); }
}
void fix_ingred_main_6_2_1(){
    {cgc_size_t tlv2; tlv2 = (cgc_size_t)(1); }
    {cgc_size_t tlv1; tlv1 = (cgc_size_t)(1); }
    {cgc_size_t tlv4; tlv4 = (cgc_size_t)(1); }
    {cgc_size_t tlv3; tlv3 = (cgc_size_t)(1); }
    {char * tlv7; tlv7 = (char *)(1); }
    {int tlv10; tlv10 = (int)(1); }
    {int tlv11; tlv11 = (int)(1); }
    {int tlv12; tlv12 = (int)(1); }
}
void fix_ingred_main_6_2(){
fix_ingred_main_6_2_0();
fix_ingred_main_6_2_1();
}
void fix_ingred_main_6_6_0(){
    {cgc_size_t tlv2; tlv2 = (cgc_size_t)(1); }
    {cgc_size_t tlv4; tlv4 = (cgc_size_t)(1); }
    {cgc_size_t tlv3; tlv3 = (cgc_size_t)(1); }
    {char * tlv7; tlv7 = (char *)(1); }
    {int tlv10; tlv10 = (int)(1); }
    {int tlv11; tlv11 = (int)(1); }
    {int tlv12; tlv12 = (int)(1); }
}
void fix_ingred_main_6_6(){
fix_ingred_main_6_6_0();
}
void fix_ingred_main_6_7_0(){
thunk_t thunk_ref;
    bzero(&thunk_ref,1*sizeof(thunk_t));
thunk_t * thunk = &thunk_ref;
unsigned arity;
    bzero(&arity,sizeof(unsigned));
    {cgc_size_t tlv2; tlv2 = (cgc_size_t)(sizeof ( char * )); }
    {cgc_size_t tlv1; tlv1 = (cgc_size_t)(sizeof ( char * )); }
    {cgc_size_t tlv4; tlv4 = (cgc_size_t)(sizeof ( char * )); }
    {cgc_size_t tlv3; tlv3 = (cgc_size_t)(sizeof ( char * )); }
    {cgc_size_t tlv9; tlv9 = (cgc_size_t)(sizeof ( char * )); }
    {cgc_size_t tlv8; tlv8 = (cgc_size_t)(sizeof ( char * )); }
    {char * tlv7; tlv7 = (char *)(sizeof ( char * )); }
    {int tlv10; tlv10 = (int)(sizeof ( char * )); }
    {int tlv11; tlv11 = (int)(sizeof ( char * )); }
    {int tlv12; tlv12 = (int)(sizeof ( char * )); }
}
void fix_ingred_main_6_7_1(){
thunk_t thunk_ref;
    bzero(&thunk_ref,1*sizeof(thunk_t));
thunk_t * thunk = &thunk_ref;
unsigned arity;
    bzero(&arity,sizeof(unsigned));
    {cgc_size_t tlv2; tlv2 = (cgc_size_t)(thunk -> arity); }
    {cgc_size_t tlv1; tlv1 = (cgc_size_t)(thunk -> arity); }
    {cgc_size_t tlv4; tlv4 = (cgc_size_t)(thunk -> arity); }
    {cgc_size_t tlv3; tlv3 = (cgc_size_t)(thunk -> arity); }
    {cgc_size_t tlv9; tlv9 = (cgc_size_t)(thunk -> arity); }
    {cgc_size_t tlv8; tlv8 = (cgc_size_t)(thunk -> arity); }
    {char * tlv7; tlv7 = (char *)(thunk -> arity); }
    {int tlv10; tlv10 = (int)(thunk -> arity); }
    {int tlv11; tlv11 = (int)(thunk -> arity); }
    {int tlv12; tlv12 = (int)(thunk -> arity); }
}
void fix_ingred_main_6_7(){
fix_ingred_main_6_7_0();
fix_ingred_main_6_7_1();
}
void fix_ingred_main_6_12_2(){
unsigned i;
    bzero(&i,sizeof(unsigned));
thunk_t thunk_ref;
    bzero(&thunk_ref,1*sizeof(thunk_t));
thunk_t * thunk = &thunk_ref;
unsigned arity;
    bzero(&arity,sizeof(unsigned));
    {cgc_size_t tlv2; tlv2 = (cgc_size_t)(i); }
    {cgc_size_t tlv1; tlv1 = (cgc_size_t)(i); }
    {cgc_size_t tlv4; tlv4 = (cgc_size_t)(i); }
    {cgc_size_t tlv3; tlv3 = (cgc_size_t)(i); }
    {cgc_size_t tlv9; tlv9 = (cgc_size_t)(i); }
    {cgc_size_t tlv8; tlv8 = (cgc_size_t)(i); }
    {char * tlv7; tlv7 = (char *)(i); }
    {int tlv10; tlv10 = (int)(i); }
    {int tlv11; tlv11 = (int)(i); }
    {int tlv12; tlv12 = (int)(i); }
}
void fix_ingred_main_6_12_3(){
unsigned i;
    bzero(&i,sizeof(unsigned));
thunk_t thunk_ref;
    bzero(&thunk_ref,1*sizeof(thunk_t));
thunk_t * thunk = &thunk_ref;
unsigned arity;
    bzero(&arity,sizeof(unsigned));
    {cgc_size_t tlv2; tlv2 = (cgc_size_t)(thunk -> arity); }
    {cgc_size_t tlv1; tlv1 = (cgc_size_t)(thunk -> arity); }
    {cgc_size_t tlv4; tlv4 = (cgc_size_t)(thunk -> arity); }
    {cgc_size_t tlv3; tlv3 = (cgc_size_t)(thunk -> arity); }
    {cgc_size_t tlv9; tlv9 = (cgc_size_t)(thunk -> arity); }
    {cgc_size_t tlv8; tlv8 = (cgc_size_t)(thunk -> arity); }
    {char * tlv7; tlv7 = (char *)(thunk -> arity); }
    {int tlv10; tlv10 = (int)(thunk -> arity); }
    {int tlv11; tlv11 = (int)(thunk -> arity); }
    {int tlv12; tlv12 = (int)(thunk -> arity); }
}
void fix_ingred_main_6_12(){
fix_ingred_main_6_12_2();
fix_ingred_main_6_12_3();
}
void fix_ingred_main_6_14_0(){
    {cgc_size_t tlv2; tlv2 = (cgc_size_t)(sizeof ( char )); }
    {cgc_size_t tlv1; tlv1 = (cgc_size_t)(sizeof ( char )); }
    {cgc_size_t tlv4; tlv4 = (cgc_size_t)(sizeof ( char )); }
    {cgc_size_t tlv3; tlv3 = (cgc_size_t)(sizeof ( char )); }
    {char * tlv7; tlv7 = (char *)(sizeof ( char )); }
    {int tlv10; tlv10 = (int)(sizeof ( char )); }
    {int tlv11; tlv11 = (int)(sizeof ( char )); }
    {int tlv12; tlv12 = (int)(sizeof ( char )); }
}
void fix_ingred_main_6_14(){
fix_ingred_main_6_14_0();
}
void fix_ingred_main_6_15_0(){
char tlv13_ref;
    bzero(&tlv13_ref,1*sizeof(char));
const char * tlv13 = &tlv13_ref;
    {cgc_size_t tlv2; tlv2 = (cgc_size_t)(cgc_strlen ( tlv13 ) + 1); }
    {cgc_size_t tlv1; tlv1 = (cgc_size_t)(cgc_strlen ( tlv13 ) + 1); }
    {cgc_size_t tlv4; tlv4 = (cgc_size_t)(cgc_strlen ( tlv13 ) + 1); }
    {cgc_size_t tlv3; tlv3 = (cgc_size_t)(cgc_strlen ( tlv13 ) + 1); }
    {cgc_size_t tlv9; tlv9 = (cgc_size_t)(cgc_strlen ( tlv13 ) + 1); }
    {cgc_size_t tlv8; tlv8 = (cgc_size_t)(cgc_strlen ( tlv13 ) + 1); }
    {char * tlv7; tlv7 = (char *)(cgc_strlen ( tlv13 ) + 1); }
    {int tlv10; tlv10 = (int)(cgc_strlen ( tlv13 ) + 1); }
    {int tlv11; tlv11 = (int)(cgc_strlen ( tlv13 ) + 1); }
    {int tlv12; tlv12 = (int)(cgc_strlen ( tlv13 ) + 1); }
}
void fix_ingred_main_6_15(){
fix_ingred_main_6_15_0();
}
void fix_ingred_main_6(){
fix_ingred_main_6_1();
fix_ingred_main_6_2();
fix_ingred_main_6_6();
fix_ingred_main_6_7();
fix_ingred_main_6_12();
fix_ingred_main_6_14();
fix_ingred_main_6_15();
}
void fix_ingred_main_7(){
}
void fix_ingred_main_8_0_0(){
char argv_ref;
    bzero(&argv_ref,1*sizeof(char));
char * * argv = &argv_ref;
    {char tmp [ ( 8192 ) + 1 ]; tmp [ ( ( 8192 ) + 1 )-1 ] = (char)(argv [ 0 ]); }
    {char * note_title; note_title = (char *)(argv [ 0 ]); }
    {char * content; content = (char *)(argv [ 0 ]); }
    {cgc_size_t rep_len; rep_len = (cgc_size_t)(argv [ 0 ]); }
    {cgc_size_t idx; idx = (cgc_size_t)(argv [ 0 ]); }
    {int tlv1; tlv1 = (int)(argv [ 0 ]); }
    {char * tlv5; tlv5 = (char *)(argv [ 0 ]); }
    {cgc_size_t tlv3; tlv3 = (cgc_size_t)(argv [ 0 ]); }
    {char * tlv9; tlv9 = (char *)(argv [ 0 ]); }
    {int tlv2; tlv2 = (int)(argv [ 0 ]); }
    {cgc_size_t tlv14; tlv14 = (cgc_size_t)(argv [ 0 ]); }
    {void * tlv18; tlv18 = (void *)(argv [ 0 ]); }
    {cgc_size_t tlv17; tlv17 = (cgc_size_t)(argv [ 0 ]); }
    {char * tlv11; tlv11 = (char *)(argv [ 0 ]); }
    {char * tlv12; tlv12 = (char *)(argv [ 0 ]); }
    {void * tlv21; tlv21 = (void *)(argv [ 0 ]); }
    {void * tlv20; tlv20 = (void *)(argv [ 0 ]); }
    {cgc_size_t tlv19; tlv19 = (cgc_size_t)(argv [ 0 ]); }
    {int tlv22; tlv22 = (int)(argv [ 0 ]); }
}
void fix_ingred_main_8_0_1(){
char argv_ref;
    bzero(&argv_ref,1*sizeof(char));
char * * argv = &argv_ref;
    {char tmp [ ( 8192 ) + 1 ]; tmp [ ( ( 8192 ) + 1 )-1 ] = (char)(argv [ 1 ]); }
    {char * note_title; note_title = (char *)(argv [ 1 ]); }
    {char * content; content = (char *)(argv [ 1 ]); }
    {cgc_size_t rep_len; rep_len = (cgc_size_t)(argv [ 1 ]); }
    {cgc_size_t idx; idx = (cgc_size_t)(argv [ 1 ]); }
    {int tlv1; tlv1 = (int)(argv [ 1 ]); }
    {char * tlv5; tlv5 = (char *)(argv [ 1 ]); }
    {cgc_size_t tlv3; tlv3 = (cgc_size_t)(argv [ 1 ]); }
    {char * tlv9; tlv9 = (char *)(argv [ 1 ]); }
    {int tlv2; tlv2 = (int)(argv [ 1 ]); }
    {cgc_size_t tlv14; tlv14 = (cgc_size_t)(argv [ 1 ]); }
    {void * tlv18; tlv18 = (void *)(argv [ 1 ]); }
    {cgc_size_t tlv17; tlv17 = (cgc_size_t)(argv [ 1 ]); }
    {char * tlv11; tlv11 = (char *)(argv [ 1 ]); }
    {char * tlv12; tlv12 = (char *)(argv [ 1 ]); }
    {void * tlv21; tlv21 = (void *)(argv [ 1 ]); }
    {void * tlv20; tlv20 = (void *)(argv [ 1 ]); }
    {cgc_size_t tlv19; tlv19 = (cgc_size_t)(argv [ 1 ]); }
    {int tlv22; tlv22 = (int)(argv [ 1 ]); }
}
void fix_ingred_main_8_0_3(){
char argv_ref;
    bzero(&argv_ref,1*sizeof(char));
char * * argv = &argv_ref;
    {char tmp [ ( 8192 ) + 1 ]; tmp [ ( ( 8192 ) + 1 )-1 ] = (char)(0); }
    {char * note_title; note_title = (char *)(0); }
    {char * content; content = (char *)(0); }
    {cgc_size_t rep_len; rep_len = (cgc_size_t)(0); }
    {cgc_size_t idx; idx = (cgc_size_t)(0); }
    {int tlv1; tlv1 = (int)(0); }
    {char * tlv5; tlv5 = (char *)(0); }
    {cgc_size_t tlv3; tlv3 = (cgc_size_t)(0); }
    {char * tlv9; tlv9 = (char *)(0); }
    {int tlv2; tlv2 = (int)(0); }
    {void * tlv18; tlv18 = (void *)(0); }
    {char * tlv12; tlv12 = (char *)(0); }
    {void * tlv21; tlv21 = (void *)(0); }
    {void * tlv20; tlv20 = (void *)(0); }
    {cgc_size_t tlv19; tlv19 = (cgc_size_t)(0); }
    {int tlv22; tlv22 = (int)(0); }
}
void fix_ingred_main_8_0(){
fix_ingred_main_8_0_0();
fix_ingred_main_8_0_1();
fix_ingred_main_8_0_3();
}
void fix_ingred_main_8_3_0(){
char tmp [ ( 8192 ) + 1 ];
    bzero(&tmp,( ( 8192 ) + 1 *sizeof(char) ) );
    {char tmp [ ( 8192 ) + 1 ]; tmp [ ( ( 8192 ) + 1 )-1 ] = (char)(tmp); }
    {char * note_title; note_title = (char *)(tmp); }
    {char * content; content = (char *)(tmp); }
    {cgc_size_t rep_len; rep_len = (cgc_size_t)(tmp); }
    {cgc_size_t idx; idx = (cgc_size_t)(tmp); }
    {int tlv1; tlv1 = (int)(tmp); }
    {char * tlv5; tlv5 = (char *)(tmp); }
    {cgc_size_t tlv3; tlv3 = (cgc_size_t)(tmp); }
    {char * tlv9; tlv9 = (char *)(tmp); }
    {int tlv2; tlv2 = (int)(tmp); }
    {cgc_size_t tlv14; tlv14 = (cgc_size_t)(tmp); }
    {void * tlv18; tlv18 = (void *)(tmp); }
    {cgc_size_t tlv17; tlv17 = (cgc_size_t)(tmp); }
    {char * tlv11; tlv11 = (char *)(tmp); }
    {char * tlv12; tlv12 = (char *)(tmp); }
    {void * tlv21; tlv21 = (void *)(tmp); }
    {void * tlv20; tlv20 = (void *)(tmp); }
    {cgc_size_t tlv19; tlv19 = (cgc_size_t)(tmp); }
    {int tlv22; tlv22 = (int)(tmp); }
}
void fix_ingred_main_8_3_1(){
char tmp [ ( 8192 ) + 1 ];
    bzero(&tmp,( ( 8192 ) + 1 *sizeof(char) ) );
    {char tmp [ ( 8192 ) + 1 ]; tmp [ ( ( 8192 ) + 1 )-1 ] = (char)(( 8192 )); }
    {char * note_title; note_title = (char *)(( 8192 )); }
    {char * content; content = (char *)(( 8192 )); }
    {cgc_size_t rep_len; rep_len = (cgc_size_t)(( 8192 )); }
    {cgc_size_t idx; idx = (cgc_size_t)(( 8192 )); }
    {int tlv1; tlv1 = (int)(( 8192 )); }
    {char * tlv5; tlv5 = (char *)(( 8192 )); }
    {cgc_size_t tlv3; tlv3 = (cgc_size_t)(( 8192 )); }
    {char * tlv9; tlv9 = (char *)(( 8192 )); }
    {int tlv2; tlv2 = (int)(( 8192 )); }
    {cgc_size_t tlv14; tlv14 = (cgc_size_t)(( 8192 )); }
    {void * tlv18; tlv18 = (void *)(( 8192 )); }
    {cgc_size_t tlv17; tlv17 = (cgc_size_t)(( 8192 )); }
    {char * tlv11; tlv11 = (char *)(( 8192 )); }
    {char * tlv12; tlv12 = (char *)(( 8192 )); }
    {void * tlv21; tlv21 = (void *)(( 8192 )); }
    {void * tlv20; tlv20 = (void *)(( 8192 )); }
    {cgc_size_t tlv19; tlv19 = (cgc_size_t)(( 8192 )); }
    {int tlv22; tlv22 = (int)(( 8192 )); }
}
void fix_ingred_main_8_3(){
fix_ingred_main_8_3_0();
fix_ingred_main_8_3_1();
}
void fix_ingred_main_8_4_0(){
const char tlv6 [0];
    bzero(&tlv6 [0],sizeof(char));
    {char tmp [ ( 8192 ) + 1 ]; tmp [ ( ( 8192 ) + 1 )-1 ] = (char)(cgc_strlen ( tlv6 )); }
    {char * note_title; note_title = (char *)(cgc_strlen ( tlv6 )); }
    {char * content; content = (char *)(cgc_strlen ( tlv6 )); }
    {cgc_size_t rep_len; rep_len = (cgc_size_t)(cgc_strlen ( tlv6 )); }
    {cgc_size_t idx; idx = (cgc_size_t)(cgc_strlen ( tlv6 )); }
    {int tlv1; tlv1 = (int)(cgc_strlen ( tlv6 )); }
    {char * tlv5; tlv5 = (char *)(cgc_strlen ( tlv6 )); }
    {cgc_size_t tlv3; tlv3 = (cgc_size_t)(cgc_strlen ( tlv6 )); }
    {char * tlv9; tlv9 = (char *)(cgc_strlen ( tlv6 )); }
    {int tlv2; tlv2 = (int)(cgc_strlen ( tlv6 )); }
    {cgc_size_t tlv14; tlv14 = (cgc_size_t)(cgc_strlen ( tlv6 )); }
    {void * tlv18; tlv18 = (void *)(cgc_strlen ( tlv6 )); }
    {cgc_size_t tlv17; tlv17 = (cgc_size_t)(cgc_strlen ( tlv6 )); }
    {char * tlv11; tlv11 = (char *)(cgc_strlen ( tlv6 )); }
    {char * tlv12; tlv12 = (char *)(cgc_strlen ( tlv6 )); }
    {void * tlv21; tlv21 = (void *)(cgc_strlen ( tlv6 )); }
    {void * tlv20; tlv20 = (void *)(cgc_strlen ( tlv6 )); }
    {cgc_size_t tlv19; tlv19 = (cgc_size_t)(cgc_strlen ( tlv6 )); }
    {int tlv22; tlv22 = (int)(cgc_strlen ( tlv6 )); }
}
void fix_ingred_main_8_4(){
fix_ingred_main_8_4_0();
}
void fix_ingred_main_8_5_4(){
cgc_size_t idx;
    bzero(&idx,sizeof(cgc_size_t));
cgc_size_t rep_len;
    bzero(&rep_len,sizeof(cgc_size_t));
    {char tmp [ ( 8192 ) + 1 ]; tmp [ ( ( 8192 ) + 1 )-1 ] = (char)(idx); }
    {char * note_title; note_title = (char *)(idx); }
    {char * content; content = (char *)(idx); }
    {cgc_size_t rep_len; rep_len = (cgc_size_t)(idx); }
    {int tlv1; tlv1 = (int)(idx); }
    {char * tlv5; tlv5 = (char *)(idx); }
    {cgc_size_t tlv3; tlv3 = (cgc_size_t)(idx); }
    {char * tlv9; tlv9 = (char *)(idx); }
    {int tlv2; tlv2 = (int)(idx); }
    {cgc_size_t tlv14; tlv14 = (cgc_size_t)(idx); }
    {void * tlv18; tlv18 = (void *)(idx); }
    {cgc_size_t tlv17; tlv17 = (cgc_size_t)(idx); }
    {char * tlv11; tlv11 = (char *)(idx); }
    {char * tlv12; tlv12 = (char *)(idx); }
    {void * tlv21; tlv21 = (void *)(idx); }
    {void * tlv20; tlv20 = (void *)(idx); }
    {cgc_size_t tlv19; tlv19 = (cgc_size_t)(idx); }
    {int tlv22; tlv22 = (int)(idx); }
}
void fix_ingred_main_8_5_5(){
cgc_size_t idx;
    bzero(&idx,sizeof(cgc_size_t));
cgc_size_t rep_len;
    bzero(&rep_len,sizeof(cgc_size_t));
    {char tmp [ ( 8192 ) + 1 ]; tmp [ ( ( 8192 ) + 1 )-1 ] = (char)(( 8192 ) - rep_len); }
    {char * note_title; note_title = (char *)(( 8192 ) - rep_len); }
    {char * content; content = (char *)(( 8192 ) - rep_len); }
    {cgc_size_t idx; idx = (cgc_size_t)(( 8192 ) - rep_len); }
    {int tlv1; tlv1 = (int)(( 8192 ) - rep_len); }
    {char * tlv5; tlv5 = (char *)(( 8192 ) - rep_len); }
    {cgc_size_t tlv3; tlv3 = (cgc_size_t)(( 8192 ) - rep_len); }
    {char * tlv9; tlv9 = (char *)(( 8192 ) - rep_len); }
    {int tlv2; tlv2 = (int)(( 8192 ) - rep_len); }
    {cgc_size_t tlv14; tlv14 = (cgc_size_t)(( 8192 ) - rep_len); }
    {void * tlv18; tlv18 = (void *)(( 8192 ) - rep_len); }
    {cgc_size_t tlv17; tlv17 = (cgc_size_t)(( 8192 ) - rep_len); }
    {char * tlv11; tlv11 = (char *)(( 8192 ) - rep_len); }
    {char * tlv12; tlv12 = (char *)(( 8192 ) - rep_len); }
    {void * tlv21; tlv21 = (void *)(( 8192 ) - rep_len); }
    {void * tlv20; tlv20 = (void *)(( 8192 ) - rep_len); }
    {cgc_size_t tlv19; tlv19 = (cgc_size_t)(( 8192 ) - rep_len); }
    {int tlv22; tlv22 = (int)(( 8192 ) - rep_len); }
}
void fix_ingred_main_8_5(){
fix_ingred_main_8_5_4();
fix_ingred_main_8_5_5();
}
void fix_ingred_main_8_6_0(){
cgc_size_t rep_len;
    bzero(&rep_len,sizeof(cgc_size_t));
    {char tmp [ ( 8192 ) + 1 ]; tmp [ ( ( 8192 ) + 1 )-1 ] = (char)(rep_len); }
    {char * note_title; note_title = (char *)(rep_len); }
    {char * content; content = (char *)(rep_len); }
    {cgc_size_t idx; idx = (cgc_size_t)(rep_len); }
    {int tlv1; tlv1 = (int)(rep_len); }
    {char * tlv5; tlv5 = (char *)(rep_len); }
    {cgc_size_t tlv3; tlv3 = (cgc_size_t)(rep_len); }
    {char * tlv9; tlv9 = (char *)(rep_len); }
    {int tlv2; tlv2 = (int)(rep_len); }
    {cgc_size_t tlv14; tlv14 = (cgc_size_t)(rep_len); }
    {void * tlv18; tlv18 = (void *)(rep_len); }
    {cgc_size_t tlv17; tlv17 = (cgc_size_t)(rep_len); }
    {char * tlv11; tlv11 = (char *)(rep_len); }
    {char * tlv12; tlv12 = (char *)(rep_len); }
    {void * tlv21; tlv21 = (void *)(rep_len); }
    {void * tlv20; tlv20 = (void *)(rep_len); }
    {cgc_size_t tlv19; tlv19 = (cgc_size_t)(rep_len); }
    {int tlv22; tlv22 = (int)(rep_len); }
}
void fix_ingred_main_8_6(){
fix_ingred_main_8_6_0();
}
void fix_ingred_main_8_7_7(){
int tlv2;
    bzero(&tlv2,sizeof(int));
    {char tmp [ ( 8192 ) + 1 ]; tmp [ ( ( 8192 ) + 1 )-1 ] = (char)(tlv2); }
    {char * note_title; note_title = (char *)(tlv2); }
    {char * content; content = (char *)(tlv2); }
    {cgc_size_t rep_len; rep_len = (cgc_size_t)(tlv2); }
    {cgc_size_t idx; idx = (cgc_size_t)(tlv2); }
    {int tlv1; tlv1 = (int)(tlv2); }
    {char * tlv5; tlv5 = (char *)(tlv2); }
    {cgc_size_t tlv3; tlv3 = (cgc_size_t)(tlv2); }
    {char * tlv9; tlv9 = (char *)(tlv2); }
    {cgc_size_t tlv14; tlv14 = (cgc_size_t)(tlv2); }
    {void * tlv18; tlv18 = (void *)(tlv2); }
    {cgc_size_t tlv17; tlv17 = (cgc_size_t)(tlv2); }
    {char * tlv11; tlv11 = (char *)(tlv2); }
    {char * tlv12; tlv12 = (char *)(tlv2); }
    {void * tlv21; tlv21 = (void *)(tlv2); }
    {void * tlv20; tlv20 = (void *)(tlv2); }
    {cgc_size_t tlv19; tlv19 = (cgc_size_t)(tlv2); }
    {int tlv22; tlv22 = (int)(tlv2); }
}
void fix_ingred_main_8_7_8(){
int tlv2;
    bzero(&tlv2,sizeof(int));
    {char tmp [ ( 8192 ) + 1 ]; tmp [ ( ( 8192 ) + 1 )-1 ] = (char)(0); }
    {char * note_title; note_title = (char *)(0); }
    {char * content; content = (char *)(0); }
    {cgc_size_t rep_len; rep_len = (cgc_size_t)(0); }
    {cgc_size_t idx; idx = (cgc_size_t)(0); }
    {int tlv1; tlv1 = (int)(0); }
    {char * tlv5; tlv5 = (char *)(0); }
    {cgc_size_t tlv3; tlv3 = (cgc_size_t)(0); }
    {char * tlv9; tlv9 = (char *)(0); }
    {int tlv2; tlv2 = (int)(0); }
    {cgc_size_t tlv14; tlv14 = (cgc_size_t)(0); }
    {void * tlv18; tlv18 = (void *)(0); }
    {cgc_size_t tlv17; tlv17 = (cgc_size_t)(0); }
    {char * tlv11; tlv11 = (char *)(0); }
    {char * tlv12; tlv12 = (char *)(0); }
    {void * tlv21; tlv21 = (void *)(0); }
    {void * tlv20; tlv20 = (void *)(0); }
    {cgc_size_t tlv19; tlv19 = (cgc_size_t)(0); }
    {int tlv22; tlv22 = (int)(0); }
}
void fix_ingred_main_8_7(){
fix_ingred_main_8_7_7();
fix_ingred_main_8_7_8();
}
void fix_ingred_main_8_8_0(){
char tmp [ ( 8192 ) + 1 ];
    bzero(&tmp,( ( 8192 ) + 1 *sizeof(char) ) );
cgc_size_t idx;
    bzero(&idx,sizeof(cgc_size_t));
    {char tmp [ ( 8192 ) + 1 ]; tmp [ ( ( 8192 ) + 1 )-1 ] = (char)(tmp + idx); }
    {char * note_title; note_title = (char *)(tmp + idx); }
    {char * content; content = (char *)(tmp + idx); }
    {cgc_size_t rep_len; rep_len = (cgc_size_t)(tmp + idx); }
    {int tlv1; tlv1 = (int)(tmp + idx); }
    {char * tlv5; tlv5 = (char *)(tmp + idx); }
    {cgc_size_t tlv3; tlv3 = (cgc_size_t)(tmp + idx); }
    {char * tlv9; tlv9 = (char *)(tmp + idx); }
    {int tlv2; tlv2 = (int)(tmp + idx); }
    {cgc_size_t tlv14; tlv14 = (cgc_size_t)(tmp + idx); }
    {void * tlv18; tlv18 = (void *)(tmp + idx); }
    {cgc_size_t tlv17; tlv17 = (cgc_size_t)(tmp + idx); }
    {char * tlv11; tlv11 = (char *)(tmp + idx); }
    {char * tlv12; tlv12 = (char *)(tmp + idx); }
    {void * tlv21; tlv21 = (void *)(tmp + idx); }
    {void * tlv20; tlv20 = (void *)(tmp + idx); }
    {cgc_size_t tlv19; tlv19 = (cgc_size_t)(tmp + idx); }
    {int tlv22; tlv22 = (int)(tmp + idx); }
}
void fix_ingred_main_8_8_1(){
char tmp [ ( 8192 ) + 1 ];
    bzero(&tmp,( ( 8192 ) + 1 *sizeof(char) ) );
cgc_size_t idx;
    bzero(&idx,sizeof(cgc_size_t));
    {char tmp [ ( 8192 ) + 1 ]; tmp [ ( ( 8192 ) + 1 )-1 ] = (char)("butt "); }
    {char * note_title; note_title = (char *)("butt "); }
    {char * content; content = (char *)("butt "); }
    {cgc_size_t rep_len; rep_len = (cgc_size_t)("butt "); }
    {cgc_size_t idx; idx = (cgc_size_t)("butt "); }
    {int tlv1; tlv1 = (int)("butt "); }
    {char * tlv5; tlv5 = (char *)("butt "); }
    {cgc_size_t tlv3; tlv3 = (cgc_size_t)("butt "); }
    {char * tlv9; tlv9 = (char *)("butt "); }
    {int tlv2; tlv2 = (int)("butt "); }
    {cgc_size_t tlv14; tlv14 = (cgc_size_t)("butt "); }
    {void * tlv18; tlv18 = (void *)("butt "); }
    {cgc_size_t tlv17; tlv17 = (cgc_size_t)("butt "); }
    {char * tlv11; tlv11 = (char *)("butt "); }
    {char * tlv12; tlv12 = (char *)("butt "); }
    {void * tlv21; tlv21 = (void *)("butt "); }
    {void * tlv20; tlv20 = (void *)("butt "); }
    {cgc_size_t tlv19; tlv19 = (cgc_size_t)("butt "); }
    {int tlv22; tlv22 = (int)("butt "); }
}
void fix_ingred_main_8_8(){
fix_ingred_main_8_8_0();
fix_ingred_main_8_8_1();
}
void fix_ingred_main_8_11_0(){
char content_ref;
    bzero(&content_ref,1*sizeof(char));
char * content = &content_ref;
    {char tmp [ ( 8192 ) + 1 ]; tmp [ ( ( 8192 ) + 1 )-1 ] = (char)(content); }
    {char * note_title; note_title = (char *)(content); }
    {cgc_size_t rep_len; rep_len = (cgc_size_t)(content); }
    {cgc_size_t idx; idx = (cgc_size_t)(content); }
    {int tlv1; tlv1 = (int)(content); }
    {char * tlv5; tlv5 = (char *)(content); }
    {cgc_size_t tlv3; tlv3 = (cgc_size_t)(content); }
    {char * tlv9; tlv9 = (char *)(content); }
    {int tlv2; tlv2 = (int)(content); }
    {cgc_size_t tlv14; tlv14 = (cgc_size_t)(content); }
    {void * tlv18; tlv18 = (void *)(content); }
    {cgc_size_t tlv17; tlv17 = (cgc_size_t)(content); }
    {char * tlv11; tlv11 = (char *)(content); }
    {char * tlv12; tlv12 = (char *)(content); }
    {void * tlv21; tlv21 = (void *)(content); }
    {void * tlv20; tlv20 = (void *)(content); }
    {cgc_size_t tlv19; tlv19 = (cgc_size_t)(content); }
    {int tlv22; tlv22 = (int)(content); }
}
void fix_ingred_main_8_11(){
fix_ingred_main_8_11_0();
}
void fix_ingred_main_8_12_0(){
char tlv23_ref;
    bzero(&tlv23_ref,1*sizeof(char));
const char * tlv23 = &tlv23_ref;
    {char tmp [ ( 8192 ) + 1 ]; tmp [ ( ( 8192 ) + 1 )-1 ] = (char)(cgc_strlen ( tlv23 ) + 1); }
    {char * note_title; note_title = (char *)(cgc_strlen ( tlv23 ) + 1); }
    {char * content; content = (char *)(cgc_strlen ( tlv23 ) + 1); }
    {cgc_size_t rep_len; rep_len = (cgc_size_t)(cgc_strlen ( tlv23 ) + 1); }
    {cgc_size_t idx; idx = (cgc_size_t)(cgc_strlen ( tlv23 ) + 1); }
    {int tlv1; tlv1 = (int)(cgc_strlen ( tlv23 ) + 1); }
    {char * tlv5; tlv5 = (char *)(cgc_strlen ( tlv23 ) + 1); }
    {cgc_size_t tlv3; tlv3 = (cgc_size_t)(cgc_strlen ( tlv23 ) + 1); }
    {char * tlv9; tlv9 = (char *)(cgc_strlen ( tlv23 ) + 1); }
    {int tlv2; tlv2 = (int)(cgc_strlen ( tlv23 ) + 1); }
    {cgc_size_t tlv14; tlv14 = (cgc_size_t)(cgc_strlen ( tlv23 ) + 1); }
    {void * tlv18; tlv18 = (void *)(cgc_strlen ( tlv23 ) + 1); }
    {cgc_size_t tlv17; tlv17 = (cgc_size_t)(cgc_strlen ( tlv23 ) + 1); }
    {char * tlv11; tlv11 = (char *)(cgc_strlen ( tlv23 ) + 1); }
    {char * tlv12; tlv12 = (char *)(cgc_strlen ( tlv23 ) + 1); }
    {void * tlv21; tlv21 = (void *)(cgc_strlen ( tlv23 ) + 1); }
    {void * tlv20; tlv20 = (void *)(cgc_strlen ( tlv23 ) + 1); }
    {cgc_size_t tlv19; tlv19 = (cgc_size_t)(cgc_strlen ( tlv23 ) + 1); }
    {int tlv22; tlv22 = (int)(cgc_strlen ( tlv23 ) + 1); }
}
void fix_ingred_main_8_12(){
fix_ingred_main_8_12_0();
}
void fix_ingred_main_8_14_4(){
char content_ref;
    bzero(&content_ref,1*sizeof(char));
char * content = &content_ref;
    {char tmp [ ( 8192 ) + 1 ]; tmp [ ( ( 8192 ) + 1 )-1 ] = (char)(content); }
    {char * note_title; note_title = (char *)(content); }
    {cgc_size_t rep_len; rep_len = (cgc_size_t)(content); }
    {cgc_size_t idx; idx = (cgc_size_t)(content); }
    {int tlv1; tlv1 = (int)(content); }
    {char * tlv5; tlv5 = (char *)(content); }
    {cgc_size_t tlv3; tlv3 = (cgc_size_t)(content); }
    {char * tlv9; tlv9 = (char *)(content); }
    {int tlv2; tlv2 = (int)(content); }
    {cgc_size_t tlv14; tlv14 = (cgc_size_t)(content); }
    {void * tlv18; tlv18 = (void *)(content); }
    {cgc_size_t tlv17; tlv17 = (cgc_size_t)(content); }
    {char * tlv11; tlv11 = (char *)(content); }
    {char * tlv12; tlv12 = (char *)(content); }
    {void * tlv21; tlv21 = (void *)(content); }
    {void * tlv20; tlv20 = (void *)(content); }
    {cgc_size_t tlv19; tlv19 = (cgc_size_t)(content); }
    {int tlv22; tlv22 = (int)(content); }
}
void fix_ingred_main_8_14_5(){
char content_ref;
    bzero(&content_ref,1*sizeof(char));
char * content = &content_ref;
    {char tmp [ ( 8192 ) + 1 ]; tmp [ ( ( 8192 ) + 1 )-1 ] = (char)(( ( void * ) 0 )); }
    {char * note_title; note_title = (char *)(( ( void * ) 0 )); }
    {char * content; content = (char *)(( ( void * ) 0 )); }
    {cgc_size_t rep_len; rep_len = (cgc_size_t)(( ( void * ) 0 )); }
    {cgc_size_t idx; idx = (cgc_size_t)(( ( void * ) 0 )); }
    {int tlv1; tlv1 = (int)(( ( void * ) 0 )); }
    {char * tlv5; tlv5 = (char *)(( ( void * ) 0 )); }
    {cgc_size_t tlv3; tlv3 = (cgc_size_t)(( ( void * ) 0 )); }
    {char * tlv9; tlv9 = (char *)(( ( void * ) 0 )); }
    {int tlv2; tlv2 = (int)(( ( void * ) 0 )); }
    {cgc_size_t tlv14; tlv14 = (cgc_size_t)(( ( void * ) 0 )); }
    {void * tlv18; tlv18 = (void *)(( ( void * ) 0 )); }
    {cgc_size_t tlv17; tlv17 = (cgc_size_t)(( ( void * ) 0 )); }
    {char * tlv11; tlv11 = (char *)(( ( void * ) 0 )); }
    {char * tlv12; tlv12 = (char *)(( ( void * ) 0 )); }
    {void * tlv21; tlv21 = (void *)(( ( void * ) 0 )); }
    {void * tlv20; tlv20 = (void *)(( ( void * ) 0 )); }
    {cgc_size_t tlv19; tlv19 = (cgc_size_t)(( ( void * ) 0 )); }
    {int tlv22; tlv22 = (int)(( ( void * ) 0 )); }
}
void fix_ingred_main_8_14(){
fix_ingred_main_8_14_4();
fix_ingred_main_8_14_5();
}
void fix_ingred_main_8_16_0(){
    {char tmp [ ( 8192 ) + 1 ]; tmp [ ( ( 8192 ) + 1 )-1 ] = (char)(1); }
    {char * note_title; note_title = (char *)(1); }
    {char * content; content = (char *)(1); }
    {cgc_size_t rep_len; rep_len = (cgc_size_t)(1); }
    {cgc_size_t idx; idx = (cgc_size_t)(1); }
    {int tlv1; tlv1 = (int)(1); }
    {char * tlv5; tlv5 = (char *)(1); }
    {char * tlv9; tlv9 = (char *)(1); }
    {int tlv2; tlv2 = (int)(1); }
    {void * tlv18; tlv18 = (void *)(1); }
    {char * tlv12; tlv12 = (char *)(1); }
    {void * tlv21; tlv21 = (void *)(1); }
    {void * tlv20; tlv20 = (void *)(1); }
    {cgc_size_t tlv19; tlv19 = (cgc_size_t)(1); }
    {int tlv22; tlv22 = (int)(1); }
}
void fix_ingred_main_8_16(){
fix_ingred_main_8_16_0();
}
void fix_ingred_main_8_18_0(){
char note_title_ref;
    bzero(&note_title_ref,1*sizeof(char));
char * note_title = &note_title_ref;
    {char tmp [ ( 8192 ) + 1 ]; tmp [ ( ( 8192 ) + 1 )-1 ] = (char)(note_title); }
    {char * content; content = (char *)(note_title); }
    {cgc_size_t rep_len; rep_len = (cgc_size_t)(note_title); }
    {cgc_size_t idx; idx = (cgc_size_t)(note_title); }
    {int tlv1; tlv1 = (int)(note_title); }
    {char * tlv5; tlv5 = (char *)(note_title); }
    {cgc_size_t tlv3; tlv3 = (cgc_size_t)(note_title); }
    {char * tlv9; tlv9 = (char *)(note_title); }
    {int tlv2; tlv2 = (int)(note_title); }
    {cgc_size_t tlv14; tlv14 = (cgc_size_t)(note_title); }
    {void * tlv18; tlv18 = (void *)(note_title); }
    {cgc_size_t tlv17; tlv17 = (cgc_size_t)(note_title); }
    {char * tlv11; tlv11 = (char *)(note_title); }
    {char * tlv12; tlv12 = (char *)(note_title); }
    {void * tlv21; tlv21 = (void *)(note_title); }
    {void * tlv20; tlv20 = (void *)(note_title); }
    {cgc_size_t tlv19; tlv19 = (cgc_size_t)(note_title); }
    {int tlv22; tlv22 = (int)(note_title); }
}
void fix_ingred_main_8_18(){
fix_ingred_main_8_18_0();
}
void fix_ingred_main_8(){
fix_ingred_main_8_0();
fix_ingred_main_8_3();
fix_ingred_main_8_4();
fix_ingred_main_8_5();
fix_ingred_main_8_6();
fix_ingred_main_8_7();
fix_ingred_main_8_8();
fix_ingred_main_8_11();
fix_ingred_main_8_12();
fix_ingred_main_8_14();
fix_ingred_main_8_16();
fix_ingred_main_8_18();
}
void fix_ingred_main_9_0_0(){
char argv_ref;
    bzero(&argv_ref,1*sizeof(char));
char * * argv = &argv_ref;
    {char * tlv1; tlv1 = (char *)(argv [ 0 ]); }
}
void fix_ingred_main_9_0(){
fix_ingred_main_9_0_0();
}
void fix_ingred_main_9_2_0(){
char note_title_ref;
    bzero(&note_title_ref,1*sizeof(char));
char * note_title = &note_title_ref;
    {char * tlv1; tlv1 = (char *)(note_title); }
}
void fix_ingred_main_9_2(){
fix_ingred_main_9_2_0();
}
void fix_ingred_main_9(){
fix_ingred_main_9_0();
fix_ingred_main_9_2();
}
void fix_ingred_main_10_1_0(){
    {cgc_size_t tlv2; tlv2 = (cgc_size_t)(sizeof ( list_t )); }
    {cgc_size_t tlv1; tlv1 = (cgc_size_t)(sizeof ( list_t )); }
    {int tlv3; tlv3 = (int)(sizeof ( list_t )); }
}
void fix_ingred_main_10_1_1(){
    {int tlv3; tlv3 = (int)(1); }
}
void fix_ingred_main_10_1(){
fix_ingred_main_10_1_0();
fix_ingred_main_10_1_1();
}
void fix_ingred_main_10_5_0(){
    {int tlv3; tlv3 = (int)(1); }
}
void fix_ingred_main_10_5(){
fix_ingred_main_10_5_0();
}
void fix_ingred_main_10(){
fix_ingred_main_10_1();
fix_ingred_main_10_5();
}
void fix_ingred_main_11(){
}
void fix_ingred_main_12(){
}
void fix_ingred_main_13_0_0(){
    {cgc_size_t len; len = (cgc_size_t)(0); }
}
void fix_ingred_main_13_0(){
fix_ingred_main_13_0_0();
}
void fix_ingred_main_13(){
fix_ingred_main_13_0();
}
void fix_ingred_main_14_1_0(){
int fd;
    bzero(&fd,sizeof(int));
    {int tlv2; tlv2 = (int)(fd); }
    {char * tlv1; tlv1 = (char *)(fd); }
}
void fix_ingred_main_14_1_1(){
int fd;
    bzero(&fd,sizeof(int));
    {int tlv2; tlv2 = (int)(( char * ) PROMPT_MSG); }
    {char * tlv1; tlv1 = (char *)(( char * ) PROMPT_MSG); }
}
void fix_ingred_main_14_1(){
fix_ingred_main_14_1_0();
fix_ingred_main_14_1_1();
}
void fix_ingred_main_14(){
fix_ingred_main_14_1();
}
void fix_ingred_main_15_1_1(){
    {int tlv2; tlv2 = (int)(( char * ) ERROR_MSG); }
    {char * tlv1; tlv1 = (char *)(( char * ) ERROR_MSG); }
}
void fix_ingred_main_15_1(){
fix_ingred_main_15_1_1();
}
void fix_ingred_main_15(){
fix_ingred_main_15_1();
}
void fix_ingred_main_16_0_0(){
char input_ref;
    bzero(&input_ref,1*sizeof(char));
char * input = &input_ref;
    {cgc_size_t len; len = (cgc_size_t)(input); }
    {char * word_start [ 128 ]; word_start [ ( 128 )-1 ] = (char *)(input); }
    {char * p; p = (char *)(input); }
    {char * end; end = (char *)(input); }
    {char * res; res = (char *)(input); }
    {void * tlv4; tlv4 = (void *)(input); }
    {int tlv3; tlv3 = (int)(input); }
    {cgc_size_t tlv2; tlv2 = (cgc_size_t)(input); }
    {cgc_size_t tlv7; tlv7 = (cgc_size_t)(input); }
    {cgc_size_t tlv6; tlv6 = (cgc_size_t)(input); }
    {int tlv1; tlv1 = (int)(input); }
    {int tlv8; tlv8 = (int)(input); }
    {int tlv9; tlv9 = (int)(input); }
    {int tlv11; tlv11 = (int)(input); }
    {int tlv13; tlv13 = (int)(input); }
    {int tlv15; tlv15 = (int)(input); }
    {int tlv16; tlv16 = (int)(input); }
}
void fix_ingred_main_16_0_1(){
char input_ref;
    bzero(&input_ref,1*sizeof(char));
char * input = &input_ref;
    {cgc_size_t len; len = (cgc_size_t)(( ( void * ) 0 )); }
    {char * word_start [ 128 ]; word_start [ ( 128 )-1 ] = (char *)(( ( void * ) 0 )); }
    {char * p; p = (char *)(( ( void * ) 0 )); }
    {char * end; end = (char *)(( ( void * ) 0 )); }
    {char * res; res = (char *)(( ( void * ) 0 )); }
    {void * tlv4; tlv4 = (void *)(( ( void * ) 0 )); }
    {int tlv3; tlv3 = (int)(( ( void * ) 0 )); }
    {cgc_size_t tlv2; tlv2 = (cgc_size_t)(( ( void * ) 0 )); }
    {cgc_size_t tlv7; tlv7 = (cgc_size_t)(( ( void * ) 0 )); }
    {cgc_size_t tlv6; tlv6 = (cgc_size_t)(( ( void * ) 0 )); }
    {int tlv8; tlv8 = (int)(( ( void * ) 0 )); }
    {int tlv9; tlv9 = (int)(( ( void * ) 0 )); }
    {int tlv11; tlv11 = (int)(( ( void * ) 0 )); }
    {int tlv13; tlv13 = (int)(( ( void * ) 0 )); }
    {int tlv15; tlv15 = (int)(( ( void * ) 0 )); }
    {int tlv16; tlv16 = (int)(( ( void * ) 0 )); }
}
void fix_ingred_main_16_0(){
fix_ingred_main_16_0_0();
fix_ingred_main_16_0_1();
}
void fix_ingred_main_16_1_0(){
char tlv5_ref;
    bzero(&tlv5_ref,1*sizeof(char));
const char * tlv5 = &tlv5_ref;
    {cgc_size_t len; len = (cgc_size_t)(cgc_strlen ( tlv5 )); }
    {char * word_start [ 128 ]; word_start [ ( 128 )-1 ] = (char *)(cgc_strlen ( tlv5 )); }
    {char * p; p = (char *)(cgc_strlen ( tlv5 )); }
    {char * end; end = (char *)(cgc_strlen ( tlv5 )); }
    {char * res; res = (char *)(cgc_strlen ( tlv5 )); }
    {void * tlv4; tlv4 = (void *)(cgc_strlen ( tlv5 )); }
    {int tlv3; tlv3 = (int)(cgc_strlen ( tlv5 )); }
    {cgc_size_t tlv2; tlv2 = (cgc_size_t)(cgc_strlen ( tlv5 )); }
    {cgc_size_t tlv7; tlv7 = (cgc_size_t)(cgc_strlen ( tlv5 )); }
    {cgc_size_t tlv6; tlv6 = (cgc_size_t)(cgc_strlen ( tlv5 )); }
    {int tlv1; tlv1 = (int)(cgc_strlen ( tlv5 )); }
    {int tlv8; tlv8 = (int)(cgc_strlen ( tlv5 )); }
    {int tlv9; tlv9 = (int)(cgc_strlen ( tlv5 )); }
    {int tlv11; tlv11 = (int)(cgc_strlen ( tlv5 )); }
    {int tlv13; tlv13 = (int)(cgc_strlen ( tlv5 )); }
    {int tlv15; tlv15 = (int)(cgc_strlen ( tlv5 )); }
    {int tlv16; tlv16 = (int)(cgc_strlen ( tlv5 )); }
}
void fix_ingred_main_16_1(){
fix_ingred_main_16_1_0();
}
void fix_ingred_main_16_2_0(){
    {cgc_size_t len; len = (cgc_size_t)('\0'); }
    {char * word_start [ 128 ]; word_start [ ( 128 )-1 ] = (char *)('\0'); }
    {char * p; p = (char *)('\0'); }
    {char * end; end = (char *)('\0'); }
    {char * res; res = (char *)('\0'); }
    {void * tlv4; tlv4 = (void *)('\0'); }
    {int tlv3; tlv3 = (int)('\0'); }
    {cgc_size_t tlv2; tlv2 = (cgc_size_t)('\0'); }
    {cgc_size_t tlv7; tlv7 = (cgc_size_t)('\0'); }
    {cgc_size_t tlv6; tlv6 = (cgc_size_t)('\0'); }
    {int tlv1; tlv1 = (int)('\0'); }
    {int tlv8; tlv8 = (int)('\0'); }
    {int tlv9; tlv9 = (int)('\0'); }
    {int tlv11; tlv11 = (int)('\0'); }
    {int tlv13; tlv13 = (int)('\0'); }
    {int tlv15; tlv15 = (int)('\0'); }
    {int tlv16; tlv16 = (int)('\0'); }
}
void fix_ingred_main_16_2_1(){
    {cgc_size_t len; len = (cgc_size_t)(128 * sizeof ( char * )); }
    {char * word_start [ 128 ]; word_start [ ( 128 )-1 ] = (char *)(128 * sizeof ( char * )); }
    {char * p; p = (char *)(128 * sizeof ( char * )); }
    {char * end; end = (char *)(128 * sizeof ( char * )); }
    {char * res; res = (char *)(128 * sizeof ( char * )); }
    {void * tlv4; tlv4 = (void *)(128 * sizeof ( char * )); }
    {int tlv3; tlv3 = (int)(128 * sizeof ( char * )); }
    {cgc_size_t tlv2; tlv2 = (cgc_size_t)(128 * sizeof ( char * )); }
    {cgc_size_t tlv7; tlv7 = (cgc_size_t)(128 * sizeof ( char * )); }
    {cgc_size_t tlv6; tlv6 = (cgc_size_t)(128 * sizeof ( char * )); }
    {int tlv1; tlv1 = (int)(128 * sizeof ( char * )); }
    {int tlv8; tlv8 = (int)(128 * sizeof ( char * )); }
    {int tlv9; tlv9 = (int)(128 * sizeof ( char * )); }
    {int tlv11; tlv11 = (int)(128 * sizeof ( char * )); }
    {int tlv13; tlv13 = (int)(128 * sizeof ( char * )); }
    {int tlv15; tlv15 = (int)(128 * sizeof ( char * )); }
    {int tlv16; tlv16 = (int)(128 * sizeof ( char * )); }
}
void fix_ingred_main_16_2(){
fix_ingred_main_16_2_0();
fix_ingred_main_16_2_1();
}
void fix_ingred_main_16_3_2(){
cgc_size_t i;
    bzero(&i,sizeof(cgc_size_t));
    {cgc_size_t len; len = (cgc_size_t)(i); }
    {char * word_start [ 128 ]; word_start [ ( 128 )-1 ] = (char *)(i); }
    {char * p; p = (char *)(i); }
    {char * end; end = (char *)(i); }
    {char * res; res = (char *)(i); }
    {void * tlv4; tlv4 = (void *)(i); }
    {int tlv3; tlv3 = (int)(i); }
    {cgc_size_t tlv2; tlv2 = (cgc_size_t)(i); }
    {cgc_size_t tlv7; tlv7 = (cgc_size_t)(i); }
    {int tlv1; tlv1 = (int)(i); }
    {int tlv8; tlv8 = (int)(i); }
    {int tlv9; tlv9 = (int)(i); }
    {int tlv11; tlv11 = (int)(i); }
    {int tlv13; tlv13 = (int)(i); }
    {int tlv15; tlv15 = (int)(i); }
    {int tlv16; tlv16 = (int)(i); }
}
void fix_ingred_main_16_3_3(){
cgc_size_t i;
    bzero(&i,sizeof(cgc_size_t));
    {cgc_size_t len; len = (cgc_size_t)(128); }
    {char * word_start [ 128 ]; word_start [ ( 128 )-1 ] = (char *)(128); }
    {char * p; p = (char *)(128); }
    {char * end; end = (char *)(128); }
    {char * res; res = (char *)(128); }
    {void * tlv4; tlv4 = (void *)(128); }
    {int tlv3; tlv3 = (int)(128); }
    {cgc_size_t tlv2; tlv2 = (cgc_size_t)(128); }
    {cgc_size_t tlv7; tlv7 = (cgc_size_t)(128); }
    {cgc_size_t tlv6; tlv6 = (cgc_size_t)(128); }
    {int tlv1; tlv1 = (int)(128); }
    {int tlv8; tlv8 = (int)(128); }
    {int tlv9; tlv9 = (int)(128); }
    {int tlv11; tlv11 = (int)(128); }
    {int tlv13; tlv13 = (int)(128); }
    {int tlv15; tlv15 = (int)(128); }
    {int tlv16; tlv16 = (int)(128); }
}
void fix_ingred_main_16_3(){
fix_ingred_main_16_3_2();
fix_ingred_main_16_3_3();
}
void fix_ingred_main_16_4_0(){
char p_ref;
    bzero(&p_ref,1*sizeof(char));
char * p = &p_ref;
    {cgc_size_t len; len = (cgc_size_t)(* p); }
    {char * word_start [ 128 ]; word_start [ ( 128 )-1 ] = (char *)(* p); }
    {char * end; end = (char *)(* p); }
    {char * res; res = (char *)(* p); }
    {void * tlv4; tlv4 = (void *)(* p); }
    {int tlv3; tlv3 = (int)(* p); }
    {cgc_size_t tlv2; tlv2 = (cgc_size_t)(* p); }
    {cgc_size_t tlv7; tlv7 = (cgc_size_t)(* p); }
    {cgc_size_t tlv6; tlv6 = (cgc_size_t)(* p); }
    {int tlv1; tlv1 = (int)(* p); }
    {int tlv8; tlv8 = (int)(* p); }
    {int tlv9; tlv9 = (int)(* p); }
    {int tlv11; tlv11 = (int)(* p); }
    {int tlv13; tlv13 = (int)(* p); }
    {int tlv15; tlv15 = (int)(* p); }
    {int tlv16; tlv16 = (int)(* p); }
}
void fix_ingred_main_16_4(){
fix_ingred_main_16_4_0();
}
void fix_ingred_main_16_6_3(){
char p_ref;
    bzero(&p_ref,1*sizeof(char));
char * p = &p_ref;
char input_ref;
    bzero(&input_ref,1*sizeof(char));
char * input = &input_ref;
cgc_size_t len;
    bzero(&len,sizeof(cgc_size_t));
    {cgc_size_t len; len = (cgc_size_t)(p); }
    {char * word_start [ 128 ]; word_start [ ( 128 )-1 ] = (char *)(p); }
    {char * end; end = (char *)(p); }
    {char * res; res = (char *)(p); }
    {void * tlv4; tlv4 = (void *)(p); }
    {int tlv3; tlv3 = (int)(p); }
    {cgc_size_t tlv2; tlv2 = (cgc_size_t)(p); }
    {cgc_size_t tlv7; tlv7 = (cgc_size_t)(p); }
    {cgc_size_t tlv6; tlv6 = (cgc_size_t)(p); }
    {int tlv1; tlv1 = (int)(p); }
    {int tlv8; tlv8 = (int)(p); }
    {int tlv9; tlv9 = (int)(p); }
    {int tlv11; tlv11 = (int)(p); }
    {int tlv13; tlv13 = (int)(p); }
    {int tlv15; tlv15 = (int)(p); }
    {int tlv16; tlv16 = (int)(p); }
}
void fix_ingred_main_16_6_4(){
char p_ref;
    bzero(&p_ref,1*sizeof(char));
char * p = &p_ref;
char input_ref;
    bzero(&input_ref,1*sizeof(char));
char * input = &input_ref;
cgc_size_t len;
    bzero(&len,sizeof(cgc_size_t));
    {char * word_start [ 128 ]; word_start [ ( 128 )-1 ] = (char *)(input + len); }
    {char * p; p = (char *)(input + len); }
    {char * end; end = (char *)(input + len); }
    {char * res; res = (char *)(input + len); }
    {void * tlv4; tlv4 = (void *)(input + len); }
    {int tlv3; tlv3 = (int)(input + len); }
    {cgc_size_t tlv2; tlv2 = (cgc_size_t)(input + len); }
    {cgc_size_t tlv7; tlv7 = (cgc_size_t)(input + len); }
    {cgc_size_t tlv6; tlv6 = (cgc_size_t)(input + len); }
    {int tlv1; tlv1 = (int)(input + len); }
    {int tlv8; tlv8 = (int)(input + len); }
    {int tlv9; tlv9 = (int)(input + len); }
    {int tlv11; tlv11 = (int)(input + len); }
    {int tlv13; tlv13 = (int)(input + len); }
    {int tlv15; tlv15 = (int)(input + len); }
    {int tlv16; tlv16 = (int)(input + len); }
}
void fix_ingred_main_16_6(){
fix_ingred_main_16_6_3();
fix_ingred_main_16_6_4();
}
void fix_ingred_main_16_7_0(){
    {cgc_size_t len; len = (cgc_size_t)(' '); }
    {char * word_start [ 128 ]; word_start [ ( 128 )-1 ] = (char *)(' '); }
    {char * p; p = (char *)(' '); }
    {char * end; end = (char *)(' '); }
    {char * res; res = (char *)(' '); }
    {void * tlv4; tlv4 = (void *)(' '); }
    {int tlv3; tlv3 = (int)(' '); }
    {cgc_size_t tlv2; tlv2 = (cgc_size_t)(' '); }
    {cgc_size_t tlv7; tlv7 = (cgc_size_t)(' '); }
    {cgc_size_t tlv6; tlv6 = (cgc_size_t)(' '); }
    {int tlv1; tlv1 = (int)(' '); }
    {int tlv8; tlv8 = (int)(' '); }
    {int tlv9; tlv9 = (int)(' '); }
    {int tlv11; tlv11 = (int)(' '); }
    {int tlv13; tlv13 = (int)(' '); }
    {int tlv15; tlv15 = (int)(' '); }
    {int tlv16; tlv16 = (int)(' '); }
}
void fix_ingred_main_16_7(){
fix_ingred_main_16_7_0();
}
void fix_ingred_main_16_16_0(){
    {cgc_size_t len; len = (cgc_size_t)(1); }
    {char * word_start [ 128 ]; word_start [ ( 128 )-1 ] = (char *)(1); }
    {char * p; p = (char *)(1); }
    {char * end; end = (char *)(1); }
    {char * res; res = (char *)(1); }
    {void * tlv4; tlv4 = (void *)(1); }
    {cgc_size_t tlv7; tlv7 = (cgc_size_t)(1); }
    {int tlv9; tlv9 = (int)(1); }
    {int tlv13; tlv13 = (int)(1); }
    {int tlv15; tlv15 = (int)(1); }
    {int tlv16; tlv16 = (int)(1); }
}
void fix_ingred_main_16_16(){
fix_ingred_main_16_16_0();
}
void fix_ingred_main_16_17_0(){
char end_ref;
    bzero(&end_ref,1*sizeof(char));
char * end = &end_ref;
char p_ref;
    bzero(&p_ref,1*sizeof(char));
char * p = &p_ref;
    {cgc_size_t len; len = (cgc_size_t)(sizeof ( char )); }
    {char * word_start [ 128 ]; word_start [ ( 128 )-1 ] = (char *)(sizeof ( char )); }
    {char * p; p = (char *)(sizeof ( char )); }
    {char * end; end = (char *)(sizeof ( char )); }
    {char * res; res = (char *)(sizeof ( char )); }
    {void * tlv4; tlv4 = (void *)(sizeof ( char )); }
    {int tlv3; tlv3 = (int)(sizeof ( char )); }
    {cgc_size_t tlv7; tlv7 = (cgc_size_t)(sizeof ( char )); }
    {int tlv1; tlv1 = (int)(sizeof ( char )); }
    {int tlv8; tlv8 = (int)(sizeof ( char )); }
    {int tlv9; tlv9 = (int)(sizeof ( char )); }
    {int tlv13; tlv13 = (int)(sizeof ( char )); }
    {int tlv15; tlv15 = (int)(sizeof ( char )); }
    {int tlv16; tlv16 = (int)(sizeof ( char )); }
}
void fix_ingred_main_16_17_1(){
char end_ref;
    bzero(&end_ref,1*sizeof(char));
char * end = &end_ref;
char p_ref;
    bzero(&p_ref,1*sizeof(char));
char * p = &p_ref;
    {cgc_size_t len; len = (cgc_size_t)(end - p + 1); }
    {char * word_start [ 128 ]; word_start [ ( 128 )-1 ] = (char *)(end - p + 1); }
    {char * res; res = (char *)(end - p + 1); }
    {void * tlv4; tlv4 = (void *)(end - p + 1); }
    {int tlv3; tlv3 = (int)(end - p + 1); }
    {cgc_size_t tlv2; tlv2 = (cgc_size_t)(end - p + 1); }
    {cgc_size_t tlv7; tlv7 = (cgc_size_t)(end - p + 1); }
    {cgc_size_t tlv6; tlv6 = (cgc_size_t)(end - p + 1); }
    {int tlv1; tlv1 = (int)(end - p + 1); }
    {int tlv8; tlv8 = (int)(end - p + 1); }
    {int tlv9; tlv9 = (int)(end - p + 1); }
    {int tlv11; tlv11 = (int)(end - p + 1); }
    {int tlv13; tlv13 = (int)(end - p + 1); }
    {int tlv15; tlv15 = (int)(end - p + 1); }
    {int tlv16; tlv16 = (int)(end - p + 1); }
}
void fix_ingred_main_16_17(){
fix_ingred_main_16_17_0();
fix_ingred_main_16_17_1();
}
void fix_ingred_main_16_19_2(){
char res_ref;
    bzero(&res_ref,1*sizeof(char));
char * res = &res_ref;
    {cgc_size_t len; len = (cgc_size_t)(res); }
    {char * word_start [ 128 ]; word_start [ ( 128 )-1 ] = (char *)(res); }
    {char * p; p = (char *)(res); }
    {char * end; end = (char *)(res); }
    {void * tlv4; tlv4 = (void *)(res); }
    {int tlv3; tlv3 = (int)(res); }
    {cgc_size_t tlv2; tlv2 = (cgc_size_t)(res); }
    {cgc_size_t tlv7; tlv7 = (cgc_size_t)(res); }
    {cgc_size_t tlv6; tlv6 = (cgc_size_t)(res); }
    {int tlv1; tlv1 = (int)(res); }
    {int tlv8; tlv8 = (int)(res); }
    {int tlv9; tlv9 = (int)(res); }
    {int tlv11; tlv11 = (int)(res); }
    {int tlv13; tlv13 = (int)(res); }
    {int tlv15; tlv15 = (int)(res); }
    {int tlv16; tlv16 = (int)(res); }
}
void fix_ingred_main_16_19(){
fix_ingred_main_16_19_2();
}
void fix_ingred_main_16(){
fix_ingred_main_16_0();
fix_ingred_main_16_1();
fix_ingred_main_16_2();
fix_ingred_main_16_3();
fix_ingred_main_16_4();
fix_ingred_main_16_6();
fix_ingred_main_16_7();
fix_ingred_main_16_16();
fix_ingred_main_16_17();
fix_ingred_main_16_19();
}
void fix_ingred_main_17_1_0(){
cgc_size_t i;
    i=1;
cgc_size_t n;
    bzero(&n,sizeof(cgc_size_t));
    {cgc_size_t i; i = (cgc_size_t)(sizeof ( char * )); }
    {unsigned tlv5; tlv5 = (unsigned)(sizeof ( char * )); }
    {char * tlv4; tlv4 = (char *)(sizeof ( char * )); }
    {int tlv3; tlv3 = (int)(sizeof ( char * )); }
    {unsigned tlv8; tlv8 = (unsigned)(sizeof ( char * )); }
    {int tlv6; tlv6 = (int)(sizeof ( char * )); }
}
void fix_ingred_main_17_1_1(){
cgc_size_t i;
    i=1;
cgc_size_t n;
    bzero(&n,sizeof(cgc_size_t));
    {cgc_size_t i; i = (cgc_size_t)(n); }
    {cgc_size_t tlv2; tlv2 = (cgc_size_t)(n); }
    {cgc_size_t tlv1; tlv1 = (cgc_size_t)(n); }
    {unsigned tlv5; tlv5 = (unsigned)(n); }
    {char * tlv4; tlv4 = (char *)(n); }
    {int tlv3; tlv3 = (int)(n); }
    {unsigned tlv8; tlv8 = (unsigned)(n); }
    {char * tlv7; tlv7 = (char *)(n); }
    {int tlv6; tlv6 = (int)(n); }
}
void fix_ingred_main_17_1(){
fix_ingred_main_17_1_0();
fix_ingred_main_17_1_1();
}
void fix_ingred_main_17_2_0(){
cgc_size_t i;
    i=1;
cgc_size_t n;
    bzero(&n,sizeof(cgc_size_t));
    {cgc_size_t tlv2; tlv2 = (cgc_size_t)(0); }
    {cgc_size_t tlv1; tlv1 = (cgc_size_t)(0); }
    {unsigned tlv5; tlv5 = (unsigned)(0); }
    {int tlv3; tlv3 = (int)(0); }
    {unsigned tlv8; tlv8 = (unsigned)(0); }
    {char * tlv7; tlv7 = (char *)(0); }
    {int tlv6; tlv6 = (int)(0); }
}
void fix_ingred_main_17_2_1(){
cgc_size_t i;
    i=1;
cgc_size_t n;
    bzero(&n,sizeof(cgc_size_t));
    {cgc_size_t tlv1; tlv1 = (cgc_size_t)(i); }
    {unsigned tlv5; tlv5 = (unsigned)(i); }
    {unsigned tlv8; tlv8 = (unsigned)(i); }
    {char * tlv7; tlv7 = (char *)(i); }
    {int tlv6; tlv6 = (int)(i); }
}
void fix_ingred_main_17_2_2(){
cgc_size_t i;
    i=1;
cgc_size_t n;
    bzero(&n,sizeof(cgc_size_t));
    {cgc_size_t i; i = (cgc_size_t)(n - 1); }
    {cgc_size_t tlv2; tlv2 = (cgc_size_t)(n - 1); }
    {cgc_size_t tlv1; tlv1 = (cgc_size_t)(n - 1); }
    {unsigned tlv5; tlv5 = (unsigned)(n - 1); }
    {char * tlv4; tlv4 = (char *)(n - 1); }
    {int tlv3; tlv3 = (int)(n - 1); }
    {unsigned tlv8; tlv8 = (unsigned)(n - 1); }
    {char * tlv7; tlv7 = (char *)(n - 1); }
    {int tlv6; tlv6 = (int)(n - 1); }
}
void fix_ingred_main_17_2(){
fix_ingred_main_17_2_0();
fix_ingred_main_17_2_1();
fix_ingred_main_17_2_2();
}
void fix_ingred_main_17_3_0(){
cgc_size_t i;
    i=1;
char input_ref;
    bzero(&input_ref,1*sizeof(char));
char * input = &input_ref;
    {cgc_size_t tlv2; tlv2 = (cgc_size_t)(i + 1); }
    {cgc_size_t tlv1; tlv1 = (cgc_size_t)(i + 1); }
    {unsigned tlv5; tlv5 = (unsigned)(i + 1); }
    {char * tlv4; tlv4 = (char *)(i + 1); }
    {int tlv3; tlv3 = (int)(i + 1); }
    {unsigned tlv8; tlv8 = (unsigned)(i + 1); }
    {char * tlv7; tlv7 = (char *)(i + 1); }
    {int tlv6; tlv6 = (int)(i + 1); }
}
void fix_ingred_main_17_3_1(){
cgc_size_t i;
    i=1;
char input_ref;
    bzero(&input_ref,1*sizeof(char));
char * input = &input_ref;
    {cgc_size_t i; i = (cgc_size_t)(input); }
    {cgc_size_t tlv1; tlv1 = (cgc_size_t)(input); }
    {unsigned tlv5; tlv5 = (unsigned)(input); }
    {char * tlv4; tlv4 = (char *)(input); }
    {unsigned tlv8; tlv8 = (unsigned)(input); }
    {char * tlv7; tlv7 = (char *)(input); }
    {int tlv6; tlv6 = (int)(input); }
}
void fix_ingred_main_17_3_2(){
cgc_size_t i;
    i=1;
char input_ref;
    bzero(&input_ref,1*sizeof(char));
char * input = &input_ref;
    {cgc_size_t i; i = (cgc_size_t)(0); }
    {cgc_size_t tlv2; tlv2 = (cgc_size_t)(0); }
    {cgc_size_t tlv1; tlv1 = (cgc_size_t)(0); }
    {unsigned tlv5; tlv5 = (unsigned)(0); }
    {char * tlv4; tlv4 = (char *)(0); }
    {int tlv3; tlv3 = (int)(0); }
    {unsigned tlv8; tlv8 = (unsigned)(0); }
    {char * tlv7; tlv7 = (char *)(0); }
    {int tlv6; tlv6 = (int)(0); }
}
void fix_ingred_main_17_3(){
fix_ingred_main_17_3_0();
fix_ingred_main_17_3_1();
fix_ingred_main_17_3_2();
}
void fix_ingred_main_17_5_2(){
cgc_size_t i;
    i=1;
    {unsigned tlv5; tlv5 = (unsigned)(1); }
    {unsigned tlv8; tlv8 = (unsigned)(1); }
    {int tlv6; tlv6 = (int)(1); }
}
void fix_ingred_main_17_5(){
fix_ingred_main_17_5_2();
}
void fix_ingred_main_17(){
fix_ingred_main_17_1();
fix_ingred_main_17_2();
fix_ingred_main_17_3();
fix_ingred_main_17_5();
}
void fix_ingred_main_18(){
}
void fix_ingred_main_19(){
}
void fix_ingred_main_20_2_0(){
    {char input_buf [ ( 16 * 1024 ) ]; input_buf [ ( ( 16 * 1024 ) )-1 ] = (char)(1); }
    {char * command; command = (char *)(1); }
    {void * tlv11; tlv11 = (void *)(1); }
    {char tlv13; tlv13 = (char)(1); }
    {unsigned tlv21; tlv21 = (unsigned)(1); }
    {char * tlv20; tlv20 = (char *)(1); }
    {cgc_size_t tlv22; tlv22 = (cgc_size_t)(1); }
    {int tlv4; tlv4 = (int)(1); }
    {int tlv25; tlv25 = (int)(1); }
    {char * tlv30; tlv30 = (char *)(1); }
    {cgc_size_t tlv29; tlv29 = (cgc_size_t)(1); }
    {cgc_size_t tlv31; tlv31 = (cgc_size_t)(1); }
    {int tlv28; tlv28 = (int)(1); }
    {char * tlv27; tlv27 = (char *)(1); }
    {char * tlv37; tlv37 = (char *)(1); }
    {char * tlv36; tlv36 = (char *)(1); }
    {cgc_size_t tlv34; tlv34 = (cgc_size_t)(1); }
    {char * tlv39; tlv39 = (char *)(1); }
    {cgc_size_t tlv38; tlv38 = (cgc_size_t)(1); }
    {cgc_size_t tlv40; tlv40 = (cgc_size_t)(1); }
    {int tlv7; tlv7 = (int)(1); }
    {unsigned tlv48; tlv48 = (unsigned)(1); }
    {cgc_size_t tlv45; tlv45 = (cgc_size_t)(1); }
    {char * tlv51; tlv51 = (char *)(1); }
    {cgc_size_t tlv50; tlv50 = (cgc_size_t)(1); }
    {cgc_size_t tlv52; tlv52 = (cgc_size_t)(1); }
    {unsigned tlv62; tlv62 = (unsigned)(1); }
    {cgc_size_t tlv57; tlv57 = (cgc_size_t)(1); }
    {char * tlv65; tlv65 = (char *)(1); }
    {cgc_size_t tlv64; tlv64 = (cgc_size_t)(1); }
    {int tlv60; tlv60 = (int)(1); }
    {char * tlv66; tlv66 = (char *)(1); }
}
void fix_ingred_main_20_2(){
fix_ingred_main_20_2_0();
}
void fix_ingred_main_20_3_0(){
char input_buf [ ( 16 * 1024 ) ];
    bzero(&input_buf,( ( 16 * 1024 ) *sizeof(char) ) );
    {char input_buf [ ( 16 * 1024 ) ]; input_buf [ ( ( 16 * 1024 ) )-1 ] = (char)(input_buf); }
    {int tlv1; tlv1 = (int)(input_buf); }
    {int tlv2; tlv2 = (int)(input_buf); }
    {char * command; command = (char *)(input_buf); }
    {int tlv3; tlv3 = (int)(input_buf); }
    {int tlv8; tlv8 = (int)(input_buf); }
    {void * tlv11; tlv11 = (void *)(input_buf); }
    {int tlv10; tlv10 = (int)(input_buf); }
    {cgc_size_t tlv9; tlv9 = (cgc_size_t)(input_buf); }
    {int tlv15; tlv15 = (int)(input_buf); }
    {cgc_size_t tlv14; tlv14 = (cgc_size_t)(input_buf); }
    {char tlv13; tlv13 = (char)(input_buf); }
    {char * tlv12; tlv12 = (char *)(input_buf); }
    {cgc_size_t tlv16; tlv16 = (cgc_size_t)(input_buf); }
    {unsigned tlv21; tlv21 = (unsigned)(input_buf); }
    {char * tlv20; tlv20 = (char *)(input_buf); }
    {int tlv19; tlv19 = (int)(input_buf); }
    {cgc_size_t tlv22; tlv22 = (cgc_size_t)(input_buf); }
    {int tlv4; tlv4 = (int)(input_buf); }
    {int tlv25; tlv25 = (int)(input_buf); }
    {char * tlv30; tlv30 = (char *)(input_buf); }
    {cgc_size_t tlv29; tlv29 = (cgc_size_t)(input_buf); }
    {cgc_size_t tlv31; tlv31 = (cgc_size_t)(input_buf); }
    {int tlv28; tlv28 = (int)(input_buf); }
    {char * tlv27; tlv27 = (char *)(input_buf); }
    {int tlv6; tlv6 = (int)(input_buf); }
    {char * tlv37; tlv37 = (char *)(input_buf); }
    {char * tlv36; tlv36 = (char *)(input_buf); }
    {cgc_size_t tlv34; tlv34 = (cgc_size_t)(input_buf); }
    {char * tlv39; tlv39 = (char *)(input_buf); }
    {cgc_size_t tlv38; tlv38 = (cgc_size_t)(input_buf); }
    {cgc_size_t tlv40; tlv40 = (cgc_size_t)(input_buf); }
    {int tlv7; tlv7 = (int)(input_buf); }
    {unsigned tlv48; tlv48 = (unsigned)(input_buf); }
    {cgc_size_t tlv45; tlv45 = (cgc_size_t)(input_buf); }
    {char * tlv51; tlv51 = (char *)(input_buf); }
    {cgc_size_t tlv50; tlv50 = (cgc_size_t)(input_buf); }
    {cgc_size_t tlv52; tlv52 = (cgc_size_t)(input_buf); }
    {unsigned tlv62; tlv62 = (unsigned)(input_buf); }
    {cgc_size_t tlv57; tlv57 = (cgc_size_t)(input_buf); }
    {char * tlv65; tlv65 = (char *)(input_buf); }
    {cgc_size_t tlv64; tlv64 = (cgc_size_t)(input_buf); }
    {int tlv60; tlv60 = (int)(input_buf); }
    {char * tlv66; tlv66 = (char *)(input_buf); }
}
void fix_ingred_main_20_3_1(){
char input_buf [ ( 16 * 1024 ) ];
    bzero(&input_buf,( ( 16 * 1024 ) *sizeof(char) ) );
    {char input_buf [ ( 16 * 1024 ) ]; input_buf [ ( ( 16 * 1024 ) )-1 ] = (char)('\0'); }
    {int tlv2; tlv2 = (int)('\0'); }
    {char * command; command = (char *)('\0'); }
    {void * tlv11; tlv11 = (void *)('\0'); }
    {int tlv10; tlv10 = (int)('\0'); }
    {cgc_size_t tlv9; tlv9 = (cgc_size_t)('\0'); }
    {cgc_size_t tlv14; tlv14 = (cgc_size_t)('\0'); }
    {char tlv13; tlv13 = (char)('\0'); }
    {char * tlv12; tlv12 = (char *)('\0'); }
    {cgc_size_t tlv16; tlv16 = (cgc_size_t)('\0'); }
    {unsigned tlv21; tlv21 = (unsigned)('\0'); }
    {char * tlv20; tlv20 = (char *)('\0'); }
    {int tlv19; tlv19 = (int)('\0'); }
    {cgc_size_t tlv22; tlv22 = (cgc_size_t)('\0'); }
    {int tlv4; tlv4 = (int)('\0'); }
    {int tlv25; tlv25 = (int)('\0'); }
    {char * tlv30; tlv30 = (char *)('\0'); }
    {cgc_size_t tlv29; tlv29 = (cgc_size_t)('\0'); }
    {cgc_size_t tlv31; tlv31 = (cgc_size_t)('\0'); }
    {int tlv28; tlv28 = (int)('\0'); }
    {char * tlv27; tlv27 = (char *)('\0'); }
    {int tlv6; tlv6 = (int)('\0'); }
    {char * tlv37; tlv37 = (char *)('\0'); }
    {char * tlv36; tlv36 = (char *)('\0'); }
    {cgc_size_t tlv34; tlv34 = (cgc_size_t)('\0'); }
    {char * tlv39; tlv39 = (char *)('\0'); }
    {cgc_size_t tlv38; tlv38 = (cgc_size_t)('\0'); }
    {cgc_size_t tlv40; tlv40 = (cgc_size_t)('\0'); }
    {int tlv7; tlv7 = (int)('\0'); }
    {unsigned tlv48; tlv48 = (unsigned)('\0'); }
    {cgc_size_t tlv45; tlv45 = (cgc_size_t)('\0'); }
    {char * tlv51; tlv51 = (char *)('\0'); }
    {cgc_size_t tlv50; tlv50 = (cgc_size_t)('\0'); }
    {cgc_size_t tlv52; tlv52 = (cgc_size_t)('\0'); }
    {unsigned tlv62; tlv62 = (unsigned)('\0'); }
    {cgc_size_t tlv57; tlv57 = (cgc_size_t)('\0'); }
    {char * tlv65; tlv65 = (char *)('\0'); }
    {cgc_size_t tlv64; tlv64 = (cgc_size_t)('\0'); }
    {int tlv60; tlv60 = (int)('\0'); }
    {char * tlv66; tlv66 = (char *)('\0'); }
}
void fix_ingred_main_20_3_2(){
char input_buf [ ( 16 * 1024 ) ];
    bzero(&input_buf,( ( 16 * 1024 ) *sizeof(char) ) );
    {char input_buf [ ( 16 * 1024 ) ]; input_buf [ ( ( 16 * 1024 ) )-1 ] = (char)(( 16 * 1024 )); }
    {int tlv1; tlv1 = (int)(( 16 * 1024 )); }
    {int tlv2; tlv2 = (int)(( 16 * 1024 )); }
    {char * command; command = (char *)(( 16 * 1024 )); }
    {int tlv3; tlv3 = (int)(( 16 * 1024 )); }
    {int tlv8; tlv8 = (int)(( 16 * 1024 )); }
    {void * tlv11; tlv11 = (void *)(( 16 * 1024 )); }
    {int tlv10; tlv10 = (int)(( 16 * 1024 )); }
    {cgc_size_t tlv9; tlv9 = (cgc_size_t)(( 16 * 1024 )); }
    {int tlv15; tlv15 = (int)(( 16 * 1024 )); }
    {cgc_size_t tlv14; tlv14 = (cgc_size_t)(( 16 * 1024 )); }
    {char tlv13; tlv13 = (char)(( 16 * 1024 )); }
    {char * tlv12; tlv12 = (char *)(( 16 * 1024 )); }
    {cgc_size_t tlv16; tlv16 = (cgc_size_t)(( 16 * 1024 )); }
    {unsigned tlv21; tlv21 = (unsigned)(( 16 * 1024 )); }
    {char * tlv20; tlv20 = (char *)(( 16 * 1024 )); }
    {int tlv19; tlv19 = (int)(( 16 * 1024 )); }
    {cgc_size_t tlv22; tlv22 = (cgc_size_t)(( 16 * 1024 )); }
    {int tlv4; tlv4 = (int)(( 16 * 1024 )); }
    {int tlv25; tlv25 = (int)(( 16 * 1024 )); }
    {char * tlv30; tlv30 = (char *)(( 16 * 1024 )); }
    {cgc_size_t tlv29; tlv29 = (cgc_size_t)(( 16 * 1024 )); }
    {cgc_size_t tlv31; tlv31 = (cgc_size_t)(( 16 * 1024 )); }
    {int tlv28; tlv28 = (int)(( 16 * 1024 )); }
    {char * tlv27; tlv27 = (char *)(( 16 * 1024 )); }
    {int tlv6; tlv6 = (int)(( 16 * 1024 )); }
    {char * tlv37; tlv37 = (char *)(( 16 * 1024 )); }
    {char * tlv36; tlv36 = (char *)(( 16 * 1024 )); }
    {cgc_size_t tlv34; tlv34 = (cgc_size_t)(( 16 * 1024 )); }
    {char * tlv39; tlv39 = (char *)(( 16 * 1024 )); }
    {cgc_size_t tlv38; tlv38 = (cgc_size_t)(( 16 * 1024 )); }
    {cgc_size_t tlv40; tlv40 = (cgc_size_t)(( 16 * 1024 )); }
    {int tlv7; tlv7 = (int)(( 16 * 1024 )); }
    {unsigned tlv48; tlv48 = (unsigned)(( 16 * 1024 )); }
    {cgc_size_t tlv45; tlv45 = (cgc_size_t)(( 16 * 1024 )); }
    {char * tlv51; tlv51 = (char *)(( 16 * 1024 )); }
    {cgc_size_t tlv50; tlv50 = (cgc_size_t)(( 16 * 1024 )); }
    {cgc_size_t tlv52; tlv52 = (cgc_size_t)(( 16 * 1024 )); }
    {unsigned tlv62; tlv62 = (unsigned)(( 16 * 1024 )); }
    {cgc_size_t tlv57; tlv57 = (cgc_size_t)(( 16 * 1024 )); }
    {char * tlv65; tlv65 = (char *)(( 16 * 1024 )); }
    {cgc_size_t tlv64; tlv64 = (cgc_size_t)(( 16 * 1024 )); }
    {int tlv60; tlv60 = (int)(( 16 * 1024 )); }
    {char * tlv66; tlv66 = (char *)(( 16 * 1024 )); }
}
void fix_ingred_main_20_3(){
fix_ingred_main_20_3_0();
fix_ingred_main_20_3_1();
fix_ingred_main_20_3_2();
}
void fix_ingred_main_20_4_0(){
char input_buf [ ( 16 * 1024 ) ];
    bzero(&input_buf,( ( 16 * 1024 ) *sizeof(char) ) );
    {char input_buf [ ( 16 * 1024 ) ]; input_buf [ ( ( 16 * 1024 ) )-1 ] = (char)(0); }
    {char * command; command = (char *)(0); }
    {int tlv8; tlv8 = (int)(0); }
    {void * tlv11; tlv11 = (void *)(0); }
    {int tlv10; tlv10 = (int)(0); }
    {cgc_size_t tlv9; tlv9 = (cgc_size_t)(0); }
    {int tlv15; tlv15 = (int)(0); }
    {char tlv13; tlv13 = (char)(0); }
    {cgc_size_t tlv16; tlv16 = (cgc_size_t)(0); }
    {unsigned tlv21; tlv21 = (unsigned)(0); }
    {char * tlv20; tlv20 = (char *)(0); }
    {int tlv19; tlv19 = (int)(0); }
    {cgc_size_t tlv22; tlv22 = (cgc_size_t)(0); }
    {int tlv4; tlv4 = (int)(0); }
    {int tlv25; tlv25 = (int)(0); }
    {char * tlv30; tlv30 = (char *)(0); }
    {cgc_size_t tlv29; tlv29 = (cgc_size_t)(0); }
    {cgc_size_t tlv31; tlv31 = (cgc_size_t)(0); }
    {int tlv28; tlv28 = (int)(0); }
    {char * tlv27; tlv27 = (char *)(0); }
    {char * tlv37; tlv37 = (char *)(0); }
    {char * tlv36; tlv36 = (char *)(0); }
    {cgc_size_t tlv34; tlv34 = (cgc_size_t)(0); }
    {char * tlv39; tlv39 = (char *)(0); }
    {cgc_size_t tlv38; tlv38 = (cgc_size_t)(0); }
    {cgc_size_t tlv40; tlv40 = (cgc_size_t)(0); }
    {int tlv7; tlv7 = (int)(0); }
    {unsigned tlv48; tlv48 = (unsigned)(0); }
    {cgc_size_t tlv45; tlv45 = (cgc_size_t)(0); }
    {char * tlv51; tlv51 = (char *)(0); }
    {cgc_size_t tlv50; tlv50 = (cgc_size_t)(0); }
    {cgc_size_t tlv52; tlv52 = (cgc_size_t)(0); }
    {unsigned tlv62; tlv62 = (unsigned)(0); }
    {cgc_size_t tlv57; tlv57 = (cgc_size_t)(0); }
    {char * tlv65; tlv65 = (char *)(0); }
    {cgc_size_t tlv64; tlv64 = (cgc_size_t)(0); }
    {int tlv60; tlv60 = (int)(0); }
    {char * tlv66; tlv66 = (char *)(0); }
}
void fix_ingred_main_20_4_2(){
char input_buf [ ( 16 * 1024 ) ];
    bzero(&input_buf,( ( 16 * 1024 ) *sizeof(char) ) );
    {char input_buf [ ( 16 * 1024 ) ]; input_buf [ ( ( 16 * 1024 ) )-1 ] = (char)('\n'); }
    {int tlv1; tlv1 = (int)('\n'); }
    {int tlv2; tlv2 = (int)('\n'); }
    {char * command; command = (char *)('\n'); }
    {int tlv3; tlv3 = (int)('\n'); }
    {int tlv8; tlv8 = (int)('\n'); }
    {void * tlv11; tlv11 = (void *)('\n'); }
    {int tlv10; tlv10 = (int)('\n'); }
    {cgc_size_t tlv9; tlv9 = (cgc_size_t)('\n'); }
    {int tlv15; tlv15 = (int)('\n'); }
    {cgc_size_t tlv14; tlv14 = (cgc_size_t)('\n'); }
    {char tlv13; tlv13 = (char)('\n'); }
    {char * tlv12; tlv12 = (char *)('\n'); }
    {cgc_size_t tlv16; tlv16 = (cgc_size_t)('\n'); }
    {unsigned tlv21; tlv21 = (unsigned)('\n'); }
    {char * tlv20; tlv20 = (char *)('\n'); }
    {int tlv19; tlv19 = (int)('\n'); }
    {cgc_size_t tlv22; tlv22 = (cgc_size_t)('\n'); }
    {int tlv4; tlv4 = (int)('\n'); }
    {int tlv25; tlv25 = (int)('\n'); }
    {char * tlv30; tlv30 = (char *)('\n'); }
    {cgc_size_t tlv29; tlv29 = (cgc_size_t)('\n'); }
    {cgc_size_t tlv31; tlv31 = (cgc_size_t)('\n'); }
    {int tlv28; tlv28 = (int)('\n'); }
    {char * tlv27; tlv27 = (char *)('\n'); }
    {int tlv6; tlv6 = (int)('\n'); }
    {char * tlv37; tlv37 = (char *)('\n'); }
    {char * tlv36; tlv36 = (char *)('\n'); }
    {cgc_size_t tlv34; tlv34 = (cgc_size_t)('\n'); }
    {char * tlv39; tlv39 = (char *)('\n'); }
    {cgc_size_t tlv38; tlv38 = (cgc_size_t)('\n'); }
    {cgc_size_t tlv40; tlv40 = (cgc_size_t)('\n'); }
    {int tlv7; tlv7 = (int)('\n'); }
    {unsigned tlv48; tlv48 = (unsigned)('\n'); }
    {cgc_size_t tlv45; tlv45 = (cgc_size_t)('\n'); }
    {char * tlv51; tlv51 = (char *)('\n'); }
    {cgc_size_t tlv50; tlv50 = (cgc_size_t)('\n'); }
    {cgc_size_t tlv52; tlv52 = (cgc_size_t)('\n'); }
    {unsigned tlv62; tlv62 = (unsigned)('\n'); }
    {cgc_size_t tlv57; tlv57 = (cgc_size_t)('\n'); }
    {char * tlv65; tlv65 = (char *)('\n'); }
    {cgc_size_t tlv64; tlv64 = (cgc_size_t)('\n'); }
    {int tlv60; tlv60 = (int)('\n'); }
    {char * tlv66; tlv66 = (char *)('\n'); }
}
void fix_ingred_main_20_4_3(){
char input_buf [ ( 16 * 1024 ) ];
    bzero(&input_buf,( ( 16 * 1024 ) *sizeof(char) ) );
    {char input_buf [ ( 16 * 1024 ) ]; input_buf [ ( ( 16 * 1024 ) )-1 ] = (char)(input_buf); }
    {int tlv1; tlv1 = (int)(input_buf); }
    {int tlv2; tlv2 = (int)(input_buf); }
    {char * command; command = (char *)(input_buf); }
    {int tlv3; tlv3 = (int)(input_buf); }
    {int tlv8; tlv8 = (int)(input_buf); }
    {void * tlv11; tlv11 = (void *)(input_buf); }
    {int tlv10; tlv10 = (int)(input_buf); }
    {cgc_size_t tlv9; tlv9 = (cgc_size_t)(input_buf); }
    {int tlv15; tlv15 = (int)(input_buf); }
    {cgc_size_t tlv14; tlv14 = (cgc_size_t)(input_buf); }
    {char tlv13; tlv13 = (char)(input_buf); }
    {char * tlv12; tlv12 = (char *)(input_buf); }
    {cgc_size_t tlv16; tlv16 = (cgc_size_t)(input_buf); }
    {unsigned tlv21; tlv21 = (unsigned)(input_buf); }
    {char * tlv20; tlv20 = (char *)(input_buf); }
    {int tlv19; tlv19 = (int)(input_buf); }
    {cgc_size_t tlv22; tlv22 = (cgc_size_t)(input_buf); }
    {int tlv4; tlv4 = (int)(input_buf); }
    {int tlv25; tlv25 = (int)(input_buf); }
    {char * tlv30; tlv30 = (char *)(input_buf); }
    {cgc_size_t tlv29; tlv29 = (cgc_size_t)(input_buf); }
    {cgc_size_t tlv31; tlv31 = (cgc_size_t)(input_buf); }
    {int tlv28; tlv28 = (int)(input_buf); }
    {char * tlv27; tlv27 = (char *)(input_buf); }
    {int tlv6; tlv6 = (int)(input_buf); }
    {char * tlv37; tlv37 = (char *)(input_buf); }
    {char * tlv36; tlv36 = (char *)(input_buf); }
    {cgc_size_t tlv34; tlv34 = (cgc_size_t)(input_buf); }
    {char * tlv39; tlv39 = (char *)(input_buf); }
    {cgc_size_t tlv38; tlv38 = (cgc_size_t)(input_buf); }
    {cgc_size_t tlv40; tlv40 = (cgc_size_t)(input_buf); }
    {int tlv7; tlv7 = (int)(input_buf); }
    {unsigned tlv48; tlv48 = (unsigned)(input_buf); }
    {cgc_size_t tlv45; tlv45 = (cgc_size_t)(input_buf); }
    {char * tlv51; tlv51 = (char *)(input_buf); }
    {cgc_size_t tlv50; tlv50 = (cgc_size_t)(input_buf); }
    {cgc_size_t tlv52; tlv52 = (cgc_size_t)(input_buf); }
    {unsigned tlv62; tlv62 = (unsigned)(input_buf); }
    {cgc_size_t tlv57; tlv57 = (cgc_size_t)(input_buf); }
    {char * tlv65; tlv65 = (char *)(input_buf); }
    {cgc_size_t tlv64; tlv64 = (cgc_size_t)(input_buf); }
    {int tlv60; tlv60 = (int)(input_buf); }
    {char * tlv66; tlv66 = (char *)(input_buf); }
}
void fix_ingred_main_20_4(){
fix_ingred_main_20_4_0();
fix_ingred_main_20_4_2();
fix_ingred_main_20_4_3();
}
void fix_ingred_main_20_5_0(){
int tlv1;
    bzero(&tlv1,sizeof(int));
    {char input_buf [ ( 16 * 1024 ) ]; input_buf [ ( ( 16 * 1024 ) )-1 ] = (char)(tlv1); }
    {int tlv2; tlv2 = (int)(tlv1); }
    {char * command; command = (char *)(tlv1); }
    {int tlv3; tlv3 = (int)(tlv1); }
    {int tlv8; tlv8 = (int)(tlv1); }
    {void * tlv11; tlv11 = (void *)(tlv1); }
    {int tlv10; tlv10 = (int)(tlv1); }
    {cgc_size_t tlv9; tlv9 = (cgc_size_t)(tlv1); }
    {int tlv15; tlv15 = (int)(tlv1); }
    {cgc_size_t tlv14; tlv14 = (cgc_size_t)(tlv1); }
    {char tlv13; tlv13 = (char)(tlv1); }
    {char * tlv12; tlv12 = (char *)(tlv1); }
    {cgc_size_t tlv16; tlv16 = (cgc_size_t)(tlv1); }
    {unsigned tlv21; tlv21 = (unsigned)(tlv1); }
    {char * tlv20; tlv20 = (char *)(tlv1); }
    {int tlv19; tlv19 = (int)(tlv1); }
    {cgc_size_t tlv22; tlv22 = (cgc_size_t)(tlv1); }
    {int tlv4; tlv4 = (int)(tlv1); }
    {int tlv25; tlv25 = (int)(tlv1); }
    {char * tlv30; tlv30 = (char *)(tlv1); }
    {cgc_size_t tlv29; tlv29 = (cgc_size_t)(tlv1); }
    {cgc_size_t tlv31; tlv31 = (cgc_size_t)(tlv1); }
    {int tlv28; tlv28 = (int)(tlv1); }
    {char * tlv27; tlv27 = (char *)(tlv1); }
    {int tlv6; tlv6 = (int)(tlv1); }
    {char * tlv37; tlv37 = (char *)(tlv1); }
    {char * tlv36; tlv36 = (char *)(tlv1); }
    {cgc_size_t tlv34; tlv34 = (cgc_size_t)(tlv1); }
    {char * tlv39; tlv39 = (char *)(tlv1); }
    {cgc_size_t tlv38; tlv38 = (cgc_size_t)(tlv1); }
    {cgc_size_t tlv40; tlv40 = (cgc_size_t)(tlv1); }
    {int tlv7; tlv7 = (int)(tlv1); }
    {unsigned tlv48; tlv48 = (unsigned)(tlv1); }
    {cgc_size_t tlv45; tlv45 = (cgc_size_t)(tlv1); }
    {char * tlv51; tlv51 = (char *)(tlv1); }
    {cgc_size_t tlv50; tlv50 = (cgc_size_t)(tlv1); }
    {cgc_size_t tlv52; tlv52 = (cgc_size_t)(tlv1); }
    {unsigned tlv62; tlv62 = (unsigned)(tlv1); }
    {cgc_size_t tlv57; tlv57 = (cgc_size_t)(tlv1); }
    {char * tlv65; tlv65 = (char *)(tlv1); }
    {cgc_size_t tlv64; tlv64 = (cgc_size_t)(tlv1); }
    {int tlv60; tlv60 = (int)(tlv1); }
    {char * tlv66; tlv66 = (char *)(tlv1); }
}
void fix_ingred_main_20_5(){
fix_ingred_main_20_5_0();
}
void fix_ingred_main_20_6_0(){
    {char input_buf [ ( 16 * 1024 ) ]; input_buf [ ( ( 16 * 1024 ) )-1 ] = (char)(4); }
    {int tlv1; tlv1 = (int)(4); }
    {int tlv2; tlv2 = (int)(4); }
    {char * command; command = (char *)(4); }
    {int tlv3; tlv3 = (int)(4); }
    {int tlv8; tlv8 = (int)(4); }
    {void * tlv11; tlv11 = (void *)(4); }
    {int tlv10; tlv10 = (int)(4); }
    {cgc_size_t tlv9; tlv9 = (cgc_size_t)(4); }
    {int tlv15; tlv15 = (int)(4); }
    {cgc_size_t tlv14; tlv14 = (cgc_size_t)(4); }
    {char tlv13; tlv13 = (char)(4); }
    {char * tlv12; tlv12 = (char *)(4); }
    {cgc_size_t tlv16; tlv16 = (cgc_size_t)(4); }
    {unsigned tlv21; tlv21 = (unsigned)(4); }
    {char * tlv20; tlv20 = (char *)(4); }
    {int tlv19; tlv19 = (int)(4); }
    {cgc_size_t tlv22; tlv22 = (cgc_size_t)(4); }
    {int tlv4; tlv4 = (int)(4); }
    {int tlv25; tlv25 = (int)(4); }
    {char * tlv30; tlv30 = (char *)(4); }
    {cgc_size_t tlv29; tlv29 = (cgc_size_t)(4); }
    {cgc_size_t tlv31; tlv31 = (cgc_size_t)(4); }
    {int tlv28; tlv28 = (int)(4); }
    {char * tlv27; tlv27 = (char *)(4); }
    {int tlv6; tlv6 = (int)(4); }
    {char * tlv37; tlv37 = (char *)(4); }
    {char * tlv36; tlv36 = (char *)(4); }
    {cgc_size_t tlv34; tlv34 = (cgc_size_t)(4); }
    {char * tlv39; tlv39 = (char *)(4); }
    {cgc_size_t tlv38; tlv38 = (cgc_size_t)(4); }
    {cgc_size_t tlv40; tlv40 = (cgc_size_t)(4); }
    {int tlv7; tlv7 = (int)(4); }
    {unsigned tlv48; tlv48 = (unsigned)(4); }
    {cgc_size_t tlv45; tlv45 = (cgc_size_t)(4); }
    {char * tlv51; tlv51 = (char *)(4); }
    {cgc_size_t tlv50; tlv50 = (cgc_size_t)(4); }
    {cgc_size_t tlv52; tlv52 = (cgc_size_t)(4); }
    {unsigned tlv62; tlv62 = (unsigned)(4); }
    {cgc_size_t tlv57; tlv57 = (cgc_size_t)(4); }
    {char * tlv65; tlv65 = (char *)(4); }
    {cgc_size_t tlv64; tlv64 = (cgc_size_t)(4); }
    {int tlv60; tlv60 = (int)(4); }
    {char * tlv66; tlv66 = (char *)(4); }
}
void fix_ingred_main_20_6(){
fix_ingred_main_20_6_0();
}
void fix_ingred_main_20_7_0(){
int tlv2;
    bzero(&tlv2,sizeof(int));
    {char input_buf [ ( 16 * 1024 ) ]; input_buf [ ( ( 16 * 1024 ) )-1 ] = (char)(tlv2); }
    {char * command; command = (char *)(tlv2); }
    {int tlv3; tlv3 = (int)(tlv2); }
    {int tlv8; tlv8 = (int)(tlv2); }
    {void * tlv11; tlv11 = (void *)(tlv2); }
    {int tlv10; tlv10 = (int)(tlv2); }
    {cgc_size_t tlv9; tlv9 = (cgc_size_t)(tlv2); }
    {int tlv15; tlv15 = (int)(tlv2); }
    {char tlv13; tlv13 = (char)(tlv2); }
    {cgc_size_t tlv16; tlv16 = (cgc_size_t)(tlv2); }
    {unsigned tlv21; tlv21 = (unsigned)(tlv2); }
    {char * tlv20; tlv20 = (char *)(tlv2); }
    {int tlv19; tlv19 = (int)(tlv2); }
    {cgc_size_t tlv22; tlv22 = (cgc_size_t)(tlv2); }
    {int tlv4; tlv4 = (int)(tlv2); }
    {int tlv25; tlv25 = (int)(tlv2); }
    {char * tlv30; tlv30 = (char *)(tlv2); }
    {cgc_size_t tlv29; tlv29 = (cgc_size_t)(tlv2); }
    {cgc_size_t tlv31; tlv31 = (cgc_size_t)(tlv2); }
    {int tlv28; tlv28 = (int)(tlv2); }
    {char * tlv27; tlv27 = (char *)(tlv2); }
    {int tlv6; tlv6 = (int)(tlv2); }
    {char * tlv37; tlv37 = (char *)(tlv2); }
    {char * tlv36; tlv36 = (char *)(tlv2); }
    {cgc_size_t tlv34; tlv34 = (cgc_size_t)(tlv2); }
    {char * tlv39; tlv39 = (char *)(tlv2); }
    {cgc_size_t tlv38; tlv38 = (cgc_size_t)(tlv2); }
    {cgc_size_t tlv40; tlv40 = (cgc_size_t)(tlv2); }
    {int tlv7; tlv7 = (int)(tlv2); }
    {unsigned tlv48; tlv48 = (unsigned)(tlv2); }
    {cgc_size_t tlv45; tlv45 = (cgc_size_t)(tlv2); }
    {char * tlv51; tlv51 = (char *)(tlv2); }
    {cgc_size_t tlv50; tlv50 = (cgc_size_t)(tlv2); }
    {cgc_size_t tlv52; tlv52 = (cgc_size_t)(tlv2); }
    {unsigned tlv62; tlv62 = (unsigned)(tlv2); }
    {cgc_size_t tlv57; tlv57 = (cgc_size_t)(tlv2); }
    {char * tlv65; tlv65 = (char *)(tlv2); }
    {cgc_size_t tlv64; tlv64 = (cgc_size_t)(tlv2); }
    {int tlv60; tlv60 = (int)(tlv2); }
    {char * tlv66; tlv66 = (char *)(tlv2); }
}
void fix_ingred_main_20_7(){
fix_ingred_main_20_7_0();
}
void fix_ingred_main_20_9_0(){
    {char input_buf [ ( 16 * 1024 ) ]; input_buf [ ( ( 16 * 1024 ) )-1 ] = (char)(0); }
    {int tlv1; tlv1 = (int)(0); }
    {int tlv2; tlv2 = (int)(0); }
    {char * command; command = (char *)(0); }
    {int tlv3; tlv3 = (int)(0); }
    {int tlv8; tlv8 = (int)(0); }
    {void * tlv11; tlv11 = (void *)(0); }
    {int tlv10; tlv10 = (int)(0); }
    {cgc_size_t tlv9; tlv9 = (cgc_size_t)(0); }
    {int tlv15; tlv15 = (int)(0); }
    {cgc_size_t tlv14; tlv14 = (cgc_size_t)(0); }
    {char tlv13; tlv13 = (char)(0); }
    {char * tlv12; tlv12 = (char *)(0); }
    {cgc_size_t tlv16; tlv16 = (cgc_size_t)(0); }
    {unsigned tlv21; tlv21 = (unsigned)(0); }
    {char * tlv20; tlv20 = (char *)(0); }
    {int tlv19; tlv19 = (int)(0); }
    {cgc_size_t tlv22; tlv22 = (cgc_size_t)(0); }
    {int tlv4; tlv4 = (int)(0); }
    {int tlv25; tlv25 = (int)(0); }
    {char * tlv30; tlv30 = (char *)(0); }
    {cgc_size_t tlv29; tlv29 = (cgc_size_t)(0); }
    {cgc_size_t tlv31; tlv31 = (cgc_size_t)(0); }
    {int tlv28; tlv28 = (int)(0); }
    {char * tlv27; tlv27 = (char *)(0); }
    {int tlv6; tlv6 = (int)(0); }
    {char * tlv37; tlv37 = (char *)(0); }
    {char * tlv36; tlv36 = (char *)(0); }
    {cgc_size_t tlv34; tlv34 = (cgc_size_t)(0); }
    {char * tlv39; tlv39 = (char *)(0); }
    {cgc_size_t tlv38; tlv38 = (cgc_size_t)(0); }
    {cgc_size_t tlv40; tlv40 = (cgc_size_t)(0); }
    {int tlv7; tlv7 = (int)(0); }
    {unsigned tlv48; tlv48 = (unsigned)(0); }
    {cgc_size_t tlv45; tlv45 = (cgc_size_t)(0); }
    {char * tlv51; tlv51 = (char *)(0); }
    {cgc_size_t tlv50; tlv50 = (cgc_size_t)(0); }
    {cgc_size_t tlv52; tlv52 = (cgc_size_t)(0); }
    {unsigned tlv62; tlv62 = (unsigned)(0); }
    {cgc_size_t tlv57; tlv57 = (cgc_size_t)(0); }
    {char * tlv65; tlv65 = (char *)(0); }
    {cgc_size_t tlv64; tlv64 = (cgc_size_t)(0); }
    {int tlv60; tlv60 = (int)(0); }
    {char * tlv66; tlv66 = (char *)(0); }
}
void fix_ingred_main_20_9(){
fix_ingred_main_20_9_0();
}
void fix_ingred_main_20_12_0(){
const char tlv67 [0];
    bzero(&tlv67 [0],sizeof(char));
    {char input_buf [ ( 16 * 1024 ) ]; input_buf [ ( ( 16 * 1024 ) )-1 ] = (char)(cgc_strlen ( tlv67 )); }
    {int tlv1; tlv1 = (int)(cgc_strlen ( tlv67 )); }
    {int tlv2; tlv2 = (int)(cgc_strlen ( tlv67 )); }
    {char * command; command = (char *)(cgc_strlen ( tlv67 )); }
    {int tlv3; tlv3 = (int)(cgc_strlen ( tlv67 )); }
    {int tlv8; tlv8 = (int)(cgc_strlen ( tlv67 )); }
    {void * tlv11; tlv11 = (void *)(cgc_strlen ( tlv67 )); }
    {int tlv10; tlv10 = (int)(cgc_strlen ( tlv67 )); }
    {cgc_size_t tlv9; tlv9 = (cgc_size_t)(cgc_strlen ( tlv67 )); }
    {int tlv15; tlv15 = (int)(cgc_strlen ( tlv67 )); }
    {cgc_size_t tlv14; tlv14 = (cgc_size_t)(cgc_strlen ( tlv67 )); }
    {char tlv13; tlv13 = (char)(cgc_strlen ( tlv67 )); }
    {char * tlv12; tlv12 = (char *)(cgc_strlen ( tlv67 )); }
    {cgc_size_t tlv16; tlv16 = (cgc_size_t)(cgc_strlen ( tlv67 )); }
    {unsigned tlv21; tlv21 = (unsigned)(cgc_strlen ( tlv67 )); }
    {char * tlv20; tlv20 = (char *)(cgc_strlen ( tlv67 )); }
    {int tlv19; tlv19 = (int)(cgc_strlen ( tlv67 )); }
    {cgc_size_t tlv22; tlv22 = (cgc_size_t)(cgc_strlen ( tlv67 )); }
    {int tlv4; tlv4 = (int)(cgc_strlen ( tlv67 )); }
    {int tlv25; tlv25 = (int)(cgc_strlen ( tlv67 )); }
    {char * tlv30; tlv30 = (char *)(cgc_strlen ( tlv67 )); }
    {cgc_size_t tlv29; tlv29 = (cgc_size_t)(cgc_strlen ( tlv67 )); }
    {cgc_size_t tlv31; tlv31 = (cgc_size_t)(cgc_strlen ( tlv67 )); }
    {int tlv28; tlv28 = (int)(cgc_strlen ( tlv67 )); }
    {char * tlv27; tlv27 = (char *)(cgc_strlen ( tlv67 )); }
    {int tlv6; tlv6 = (int)(cgc_strlen ( tlv67 )); }
    {char * tlv37; tlv37 = (char *)(cgc_strlen ( tlv67 )); }
    {char * tlv36; tlv36 = (char *)(cgc_strlen ( tlv67 )); }
    {cgc_size_t tlv34; tlv34 = (cgc_size_t)(cgc_strlen ( tlv67 )); }
    {char * tlv39; tlv39 = (char *)(cgc_strlen ( tlv67 )); }
    {cgc_size_t tlv38; tlv38 = (cgc_size_t)(cgc_strlen ( tlv67 )); }
    {cgc_size_t tlv40; tlv40 = (cgc_size_t)(cgc_strlen ( tlv67 )); }
    {int tlv7; tlv7 = (int)(cgc_strlen ( tlv67 )); }
    {unsigned tlv48; tlv48 = (unsigned)(cgc_strlen ( tlv67 )); }
    {cgc_size_t tlv45; tlv45 = (cgc_size_t)(cgc_strlen ( tlv67 )); }
    {char * tlv51; tlv51 = (char *)(cgc_strlen ( tlv67 )); }
    {cgc_size_t tlv50; tlv50 = (cgc_size_t)(cgc_strlen ( tlv67 )); }
    {cgc_size_t tlv52; tlv52 = (cgc_size_t)(cgc_strlen ( tlv67 )); }
    {unsigned tlv62; tlv62 = (unsigned)(cgc_strlen ( tlv67 )); }
    {cgc_size_t tlv57; tlv57 = (cgc_size_t)(cgc_strlen ( tlv67 )); }
    {char * tlv65; tlv65 = (char *)(cgc_strlen ( tlv67 )); }
    {cgc_size_t tlv64; tlv64 = (cgc_size_t)(cgc_strlen ( tlv67 )); }
    {int tlv60; tlv60 = (int)(cgc_strlen ( tlv67 )); }
    {char * tlv66; tlv66 = (char *)(cgc_strlen ( tlv67 )); }
}
void fix_ingred_main_20_12(){
fix_ingred_main_20_12_0();
}
void fix_ingred_main_20_13_1(){
int tlv3;
    bzero(&tlv3,sizeof(int));
    {char input_buf [ ( 16 * 1024 ) ]; input_buf [ ( ( 16 * 1024 ) )-1 ] = (char)(tlv3); }
    {int tlv1; tlv1 = (int)(tlv3); }
    {int tlv2; tlv2 = (int)(tlv3); }
    {char * command; command = (char *)(tlv3); }
    {int tlv8; tlv8 = (int)(tlv3); }
    {void * tlv11; tlv11 = (void *)(tlv3); }
    {int tlv10; tlv10 = (int)(tlv3); }
    {cgc_size_t tlv9; tlv9 = (cgc_size_t)(tlv3); }
    {int tlv15; tlv15 = (int)(tlv3); }
    {cgc_size_t tlv14; tlv14 = (cgc_size_t)(tlv3); }
    {char tlv13; tlv13 = (char)(tlv3); }
    {char * tlv12; tlv12 = (char *)(tlv3); }
    {cgc_size_t tlv16; tlv16 = (cgc_size_t)(tlv3); }
    {unsigned tlv21; tlv21 = (unsigned)(tlv3); }
    {char * tlv20; tlv20 = (char *)(tlv3); }
    {int tlv19; tlv19 = (int)(tlv3); }
    {cgc_size_t tlv22; tlv22 = (cgc_size_t)(tlv3); }
    {int tlv4; tlv4 = (int)(tlv3); }
    {int tlv25; tlv25 = (int)(tlv3); }
    {char * tlv30; tlv30 = (char *)(tlv3); }
    {cgc_size_t tlv29; tlv29 = (cgc_size_t)(tlv3); }
    {cgc_size_t tlv31; tlv31 = (cgc_size_t)(tlv3); }
    {int tlv28; tlv28 = (int)(tlv3); }
    {char * tlv27; tlv27 = (char *)(tlv3); }
    {int tlv6; tlv6 = (int)(tlv3); }
    {char * tlv37; tlv37 = (char *)(tlv3); }
    {char * tlv36; tlv36 = (char *)(tlv3); }
    {cgc_size_t tlv34; tlv34 = (cgc_size_t)(tlv3); }
    {char * tlv39; tlv39 = (char *)(tlv3); }
    {cgc_size_t tlv38; tlv38 = (cgc_size_t)(tlv3); }
    {cgc_size_t tlv40; tlv40 = (cgc_size_t)(tlv3); }
    {int tlv7; tlv7 = (int)(tlv3); }
    {unsigned tlv48; tlv48 = (unsigned)(tlv3); }
    {cgc_size_t tlv45; tlv45 = (cgc_size_t)(tlv3); }
    {char * tlv51; tlv51 = (char *)(tlv3); }
    {cgc_size_t tlv50; tlv50 = (cgc_size_t)(tlv3); }
    {cgc_size_t tlv52; tlv52 = (cgc_size_t)(tlv3); }
    {unsigned tlv62; tlv62 = (unsigned)(tlv3); }
    {cgc_size_t tlv57; tlv57 = (cgc_size_t)(tlv3); }
    {char * tlv65; tlv65 = (char *)(tlv3); }
    {cgc_size_t tlv64; tlv64 = (cgc_size_t)(tlv3); }
    {int tlv60; tlv60 = (int)(tlv3); }
    {char * tlv66; tlv66 = (char *)(tlv3); }
}
void fix_ingred_main_20_13(){
fix_ingred_main_20_13_1();
}
void fix_ingred_main_20_15_1(){
    {char input_buf [ ( 16 * 1024 ) ]; input_buf [ ( ( 16 * 1024 ) )-1 ] = (char)(2); }
    {int tlv1; tlv1 = (int)(2); }
    {int tlv2; tlv2 = (int)(2); }
    {char * command; command = (char *)(2); }
    {int tlv3; tlv3 = (int)(2); }
    {int tlv8; tlv8 = (int)(2); }
    {void * tlv11; tlv11 = (void *)(2); }
    {int tlv10; tlv10 = (int)(2); }
    {cgc_size_t tlv9; tlv9 = (cgc_size_t)(2); }
    {int tlv15; tlv15 = (int)(2); }
    {cgc_size_t tlv14; tlv14 = (cgc_size_t)(2); }
    {char tlv13; tlv13 = (char)(2); }
    {char * tlv12; tlv12 = (char *)(2); }
    {cgc_size_t tlv16; tlv16 = (cgc_size_t)(2); }
    {unsigned tlv21; tlv21 = (unsigned)(2); }
    {char * tlv20; tlv20 = (char *)(2); }
    {int tlv19; tlv19 = (int)(2); }
    {cgc_size_t tlv22; tlv22 = (cgc_size_t)(2); }
    {int tlv4; tlv4 = (int)(2); }
    {int tlv25; tlv25 = (int)(2); }
    {char * tlv30; tlv30 = (char *)(2); }
    {cgc_size_t tlv29; tlv29 = (cgc_size_t)(2); }
    {cgc_size_t tlv31; tlv31 = (cgc_size_t)(2); }
    {int tlv28; tlv28 = (int)(2); }
    {char * tlv27; tlv27 = (char *)(2); }
    {int tlv6; tlv6 = (int)(2); }
    {char * tlv37; tlv37 = (char *)(2); }
    {char * tlv36; tlv36 = (char *)(2); }
    {cgc_size_t tlv34; tlv34 = (cgc_size_t)(2); }
    {char * tlv39; tlv39 = (char *)(2); }
    {cgc_size_t tlv38; tlv38 = (cgc_size_t)(2); }
    {cgc_size_t tlv40; tlv40 = (cgc_size_t)(2); }
    {int tlv7; tlv7 = (int)(2); }
    {unsigned tlv48; tlv48 = (unsigned)(2); }
    {cgc_size_t tlv45; tlv45 = (cgc_size_t)(2); }
    {char * tlv51; tlv51 = (char *)(2); }
    {cgc_size_t tlv50; tlv50 = (cgc_size_t)(2); }
    {cgc_size_t tlv52; tlv52 = (cgc_size_t)(2); }
    {unsigned tlv62; tlv62 = (unsigned)(2); }
    {cgc_size_t tlv57; tlv57 = (cgc_size_t)(2); }
    {char * tlv65; tlv65 = (char *)(2); }
    {cgc_size_t tlv64; tlv64 = (cgc_size_t)(2); }
    {int tlv60; tlv60 = (int)(2); }
    {char * tlv66; tlv66 = (char *)(2); }
}
void fix_ingred_main_20_15(){
fix_ingred_main_20_15_1();
}
void fix_ingred_main_20_17_0(){
char argv_ref;
    bzero(&argv_ref,1*sizeof(char));
char * * argv = &argv_ref;
    {char input_buf [ ( 16 * 1024 ) ]; input_buf [ ( ( 16 * 1024 ) )-1 ] = (char)(argv [ 0 ]); }
    {char * command; command = (char *)(argv [ 0 ]); }
    {int tlv3; tlv3 = (int)(argv [ 0 ]); }
    {int tlv8; tlv8 = (int)(argv [ 0 ]); }
    {void * tlv11; tlv11 = (void *)(argv [ 0 ]); }
    {int tlv10; tlv10 = (int)(argv [ 0 ]); }
    {cgc_size_t tlv9; tlv9 = (cgc_size_t)(argv [ 0 ]); }
    {int tlv15; tlv15 = (int)(argv [ 0 ]); }
    {char tlv13; tlv13 = (char)(argv [ 0 ]); }
    {cgc_size_t tlv16; tlv16 = (cgc_size_t)(argv [ 0 ]); }
    {unsigned tlv21; tlv21 = (unsigned)(argv [ 0 ]); }
    {char * tlv20; tlv20 = (char *)(argv [ 0 ]); }
    {int tlv19; tlv19 = (int)(argv [ 0 ]); }
    {cgc_size_t tlv22; tlv22 = (cgc_size_t)(argv [ 0 ]); }
    {int tlv4; tlv4 = (int)(argv [ 0 ]); }
    {int tlv25; tlv25 = (int)(argv [ 0 ]); }
    {char * tlv30; tlv30 = (char *)(argv [ 0 ]); }
    {cgc_size_t tlv29; tlv29 = (cgc_size_t)(argv [ 0 ]); }
    {cgc_size_t tlv31; tlv31 = (cgc_size_t)(argv [ 0 ]); }
    {int tlv28; tlv28 = (int)(argv [ 0 ]); }
    {char * tlv27; tlv27 = (char *)(argv [ 0 ]); }
    {int tlv6; tlv6 = (int)(argv [ 0 ]); }
    {char * tlv37; tlv37 = (char *)(argv [ 0 ]); }
    {char * tlv36; tlv36 = (char *)(argv [ 0 ]); }
    {cgc_size_t tlv34; tlv34 = (cgc_size_t)(argv [ 0 ]); }
    {char * tlv39; tlv39 = (char *)(argv [ 0 ]); }
    {cgc_size_t tlv38; tlv38 = (cgc_size_t)(argv [ 0 ]); }
    {cgc_size_t tlv40; tlv40 = (cgc_size_t)(argv [ 0 ]); }
    {int tlv7; tlv7 = (int)(argv [ 0 ]); }
    {unsigned tlv48; tlv48 = (unsigned)(argv [ 0 ]); }
    {cgc_size_t tlv45; tlv45 = (cgc_size_t)(argv [ 0 ]); }
    {char * tlv51; tlv51 = (char *)(argv [ 0 ]); }
    {cgc_size_t tlv50; tlv50 = (cgc_size_t)(argv [ 0 ]); }
    {cgc_size_t tlv52; tlv52 = (cgc_size_t)(argv [ 0 ]); }
    {unsigned tlv62; tlv62 = (unsigned)(argv [ 0 ]); }
    {cgc_size_t tlv57; tlv57 = (cgc_size_t)(argv [ 0 ]); }
    {char * tlv65; tlv65 = (char *)(argv [ 0 ]); }
    {cgc_size_t tlv64; tlv64 = (cgc_size_t)(argv [ 0 ]); }
    {int tlv60; tlv60 = (int)(argv [ 0 ]); }
    {char * tlv66; tlv66 = (char *)(argv [ 0 ]); }
}
void fix_ingred_main_20_17_1(){
char argv_ref;
    bzero(&argv_ref,1*sizeof(char));
char * * argv = &argv_ref;
    {char input_buf [ ( 16 * 1024 ) ]; input_buf [ ( ( 16 * 1024 ) )-1 ] = (char)(argv [ 1 ]); }
    {char * command; command = (char *)(argv [ 1 ]); }
    {int tlv3; tlv3 = (int)(argv [ 1 ]); }
    {int tlv8; tlv8 = (int)(argv [ 1 ]); }
    {void * tlv11; tlv11 = (void *)(argv [ 1 ]); }
    {int tlv10; tlv10 = (int)(argv [ 1 ]); }
    {cgc_size_t tlv9; tlv9 = (cgc_size_t)(argv [ 1 ]); }
    {int tlv15; tlv15 = (int)(argv [ 1 ]); }
    {char tlv13; tlv13 = (char)(argv [ 1 ]); }
    {cgc_size_t tlv16; tlv16 = (cgc_size_t)(argv [ 1 ]); }
    {unsigned tlv21; tlv21 = (unsigned)(argv [ 1 ]); }
    {char * tlv20; tlv20 = (char *)(argv [ 1 ]); }
    {int tlv19; tlv19 = (int)(argv [ 1 ]); }
    {cgc_size_t tlv22; tlv22 = (cgc_size_t)(argv [ 1 ]); }
    {int tlv4; tlv4 = (int)(argv [ 1 ]); }
    {int tlv25; tlv25 = (int)(argv [ 1 ]); }
    {char * tlv30; tlv30 = (char *)(argv [ 1 ]); }
    {cgc_size_t tlv29; tlv29 = (cgc_size_t)(argv [ 1 ]); }
    {cgc_size_t tlv31; tlv31 = (cgc_size_t)(argv [ 1 ]); }
    {int tlv28; tlv28 = (int)(argv [ 1 ]); }
    {char * tlv27; tlv27 = (char *)(argv [ 1 ]); }
    {int tlv6; tlv6 = (int)(argv [ 1 ]); }
    {char * tlv37; tlv37 = (char *)(argv [ 1 ]); }
    {char * tlv36; tlv36 = (char *)(argv [ 1 ]); }
    {cgc_size_t tlv34; tlv34 = (cgc_size_t)(argv [ 1 ]); }
    {char * tlv39; tlv39 = (char *)(argv [ 1 ]); }
    {cgc_size_t tlv38; tlv38 = (cgc_size_t)(argv [ 1 ]); }
    {cgc_size_t tlv40; tlv40 = (cgc_size_t)(argv [ 1 ]); }
    {int tlv7; tlv7 = (int)(argv [ 1 ]); }
    {unsigned tlv48; tlv48 = (unsigned)(argv [ 1 ]); }
    {cgc_size_t tlv45; tlv45 = (cgc_size_t)(argv [ 1 ]); }
    {char * tlv51; tlv51 = (char *)(argv [ 1 ]); }
    {cgc_size_t tlv50; tlv50 = (cgc_size_t)(argv [ 1 ]); }
    {cgc_size_t tlv52; tlv52 = (cgc_size_t)(argv [ 1 ]); }
    {unsigned tlv62; tlv62 = (unsigned)(argv [ 1 ]); }
    {cgc_size_t tlv57; tlv57 = (cgc_size_t)(argv [ 1 ]); }
    {char * tlv65; tlv65 = (char *)(argv [ 1 ]); }
    {cgc_size_t tlv64; tlv64 = (cgc_size_t)(argv [ 1 ]); }
    {int tlv60; tlv60 = (int)(argv [ 1 ]); }
    {char * tlv66; tlv66 = (char *)(argv [ 1 ]); }
}
void fix_ingred_main_20_17(){
fix_ingred_main_20_17_0();
fix_ingred_main_20_17_1();
}
void fix_ingred_main_20_23_0(){
const char tlv68 [0];
    bzero(&tlv68 [0],sizeof(char));
    {char input_buf [ ( 16 * 1024 ) ]; input_buf [ ( ( 16 * 1024 ) )-1 ] = (char)(cgc_strlen ( tlv68 )); }
    {int tlv1; tlv1 = (int)(cgc_strlen ( tlv68 )); }
    {int tlv2; tlv2 = (int)(cgc_strlen ( tlv68 )); }
    {char * command; command = (char *)(cgc_strlen ( tlv68 )); }
    {int tlv3; tlv3 = (int)(cgc_strlen ( tlv68 )); }
    {int tlv8; tlv8 = (int)(cgc_strlen ( tlv68 )); }
    {void * tlv11; tlv11 = (void *)(cgc_strlen ( tlv68 )); }
    {int tlv10; tlv10 = (int)(cgc_strlen ( tlv68 )); }
    {cgc_size_t tlv9; tlv9 = (cgc_size_t)(cgc_strlen ( tlv68 )); }
    {int tlv15; tlv15 = (int)(cgc_strlen ( tlv68 )); }
    {cgc_size_t tlv14; tlv14 = (cgc_size_t)(cgc_strlen ( tlv68 )); }
    {char tlv13; tlv13 = (char)(cgc_strlen ( tlv68 )); }
    {char * tlv12; tlv12 = (char *)(cgc_strlen ( tlv68 )); }
    {cgc_size_t tlv16; tlv16 = (cgc_size_t)(cgc_strlen ( tlv68 )); }
    {unsigned tlv21; tlv21 = (unsigned)(cgc_strlen ( tlv68 )); }
    {char * tlv20; tlv20 = (char *)(cgc_strlen ( tlv68 )); }
    {int tlv19; tlv19 = (int)(cgc_strlen ( tlv68 )); }
    {cgc_size_t tlv22; tlv22 = (cgc_size_t)(cgc_strlen ( tlv68 )); }
    {int tlv4; tlv4 = (int)(cgc_strlen ( tlv68 )); }
    {int tlv25; tlv25 = (int)(cgc_strlen ( tlv68 )); }
    {char * tlv30; tlv30 = (char *)(cgc_strlen ( tlv68 )); }
    {cgc_size_t tlv29; tlv29 = (cgc_size_t)(cgc_strlen ( tlv68 )); }
    {cgc_size_t tlv31; tlv31 = (cgc_size_t)(cgc_strlen ( tlv68 )); }
    {int tlv28; tlv28 = (int)(cgc_strlen ( tlv68 )); }
    {char * tlv27; tlv27 = (char *)(cgc_strlen ( tlv68 )); }
    {int tlv6; tlv6 = (int)(cgc_strlen ( tlv68 )); }
    {char * tlv37; tlv37 = (char *)(cgc_strlen ( tlv68 )); }
    {char * tlv36; tlv36 = (char *)(cgc_strlen ( tlv68 )); }
    {cgc_size_t tlv34; tlv34 = (cgc_size_t)(cgc_strlen ( tlv68 )); }
    {char * tlv39; tlv39 = (char *)(cgc_strlen ( tlv68 )); }
    {cgc_size_t tlv38; tlv38 = (cgc_size_t)(cgc_strlen ( tlv68 )); }
    {cgc_size_t tlv40; tlv40 = (cgc_size_t)(cgc_strlen ( tlv68 )); }
    {int tlv7; tlv7 = (int)(cgc_strlen ( tlv68 )); }
    {unsigned tlv48; tlv48 = (unsigned)(cgc_strlen ( tlv68 )); }
    {cgc_size_t tlv45; tlv45 = (cgc_size_t)(cgc_strlen ( tlv68 )); }
    {char * tlv51; tlv51 = (char *)(cgc_strlen ( tlv68 )); }
    {cgc_size_t tlv50; tlv50 = (cgc_size_t)(cgc_strlen ( tlv68 )); }
    {cgc_size_t tlv52; tlv52 = (cgc_size_t)(cgc_strlen ( tlv68 )); }
    {unsigned tlv62; tlv62 = (unsigned)(cgc_strlen ( tlv68 )); }
    {cgc_size_t tlv57; tlv57 = (cgc_size_t)(cgc_strlen ( tlv68 )); }
    {char * tlv65; tlv65 = (char *)(cgc_strlen ( tlv68 )); }
    {cgc_size_t tlv64; tlv64 = (cgc_size_t)(cgc_strlen ( tlv68 )); }
    {int tlv60; tlv60 = (int)(cgc_strlen ( tlv68 )); }
    {char * tlv66; tlv66 = (char *)(cgc_strlen ( tlv68 )); }
}
void fix_ingred_main_20_23(){
fix_ingred_main_20_23_0();
}
void fix_ingred_main_20_24_1(){
int tlv4;
    bzero(&tlv4,sizeof(int));
    {char input_buf [ ( 16 * 1024 ) ]; input_buf [ ( ( 16 * 1024 ) )-1 ] = (char)(tlv4); }
    {int tlv1; tlv1 = (int)(tlv4); }
    {int tlv2; tlv2 = (int)(tlv4); }
    {char * command; command = (char *)(tlv4); }
    {int tlv3; tlv3 = (int)(tlv4); }
    {int tlv8; tlv8 = (int)(tlv4); }
    {void * tlv11; tlv11 = (void *)(tlv4); }
    {int tlv10; tlv10 = (int)(tlv4); }
    {cgc_size_t tlv9; tlv9 = (cgc_size_t)(tlv4); }
    {int tlv15; tlv15 = (int)(tlv4); }
    {cgc_size_t tlv14; tlv14 = (cgc_size_t)(tlv4); }
    {char tlv13; tlv13 = (char)(tlv4); }
    {char * tlv12; tlv12 = (char *)(tlv4); }
    {cgc_size_t tlv16; tlv16 = (cgc_size_t)(tlv4); }
    {unsigned tlv21; tlv21 = (unsigned)(tlv4); }
    {char * tlv20; tlv20 = (char *)(tlv4); }
    {int tlv19; tlv19 = (int)(tlv4); }
    {cgc_size_t tlv22; tlv22 = (cgc_size_t)(tlv4); }
    {int tlv25; tlv25 = (int)(tlv4); }
    {char * tlv30; tlv30 = (char *)(tlv4); }
    {cgc_size_t tlv29; tlv29 = (cgc_size_t)(tlv4); }
    {cgc_size_t tlv31; tlv31 = (cgc_size_t)(tlv4); }
    {int tlv28; tlv28 = (int)(tlv4); }
    {char * tlv27; tlv27 = (char *)(tlv4); }
    {int tlv6; tlv6 = (int)(tlv4); }
    {char * tlv37; tlv37 = (char *)(tlv4); }
    {char * tlv36; tlv36 = (char *)(tlv4); }
    {cgc_size_t tlv34; tlv34 = (cgc_size_t)(tlv4); }
    {char * tlv39; tlv39 = (char *)(tlv4); }
    {cgc_size_t tlv38; tlv38 = (cgc_size_t)(tlv4); }
    {cgc_size_t tlv40; tlv40 = (cgc_size_t)(tlv4); }
    {int tlv7; tlv7 = (int)(tlv4); }
    {unsigned tlv48; tlv48 = (unsigned)(tlv4); }
    {cgc_size_t tlv45; tlv45 = (cgc_size_t)(tlv4); }
    {char * tlv51; tlv51 = (char *)(tlv4); }
    {cgc_size_t tlv50; tlv50 = (cgc_size_t)(tlv4); }
    {cgc_size_t tlv52; tlv52 = (cgc_size_t)(tlv4); }
    {unsigned tlv62; tlv62 = (unsigned)(tlv4); }
    {cgc_size_t tlv57; tlv57 = (cgc_size_t)(tlv4); }
    {char * tlv65; tlv65 = (char *)(tlv4); }
    {cgc_size_t tlv64; tlv64 = (cgc_size_t)(tlv4); }
    {int tlv60; tlv60 = (int)(tlv4); }
    {char * tlv66; tlv66 = (char *)(tlv4); }
}
void fix_ingred_main_20_24(){
fix_ingred_main_20_24_1();
}
void fix_ingred_main_20_27_0(){
    {char input_buf [ ( 16 * 1024 ) ]; input_buf [ ( ( 16 * 1024 ) )-1 ] = (char)(2); }
    {int tlv1; tlv1 = (int)(2); }
    {int tlv2; tlv2 = (int)(2); }
    {char * command; command = (char *)(2); }
    {int tlv3; tlv3 = (int)(2); }
    {int tlv8; tlv8 = (int)(2); }
    {void * tlv11; tlv11 = (void *)(2); }
    {int tlv10; tlv10 = (int)(2); }
    {cgc_size_t tlv9; tlv9 = (cgc_size_t)(2); }
    {int tlv15; tlv15 = (int)(2); }
    {cgc_size_t tlv14; tlv14 = (cgc_size_t)(2); }
    {char tlv13; tlv13 = (char)(2); }
    {char * tlv12; tlv12 = (char *)(2); }
    {cgc_size_t tlv16; tlv16 = (cgc_size_t)(2); }
    {unsigned tlv21; tlv21 = (unsigned)(2); }
    {char * tlv20; tlv20 = (char *)(2); }
    {int tlv19; tlv19 = (int)(2); }
    {cgc_size_t tlv22; tlv22 = (cgc_size_t)(2); }
    {int tlv4; tlv4 = (int)(2); }
    {int tlv25; tlv25 = (int)(2); }
    {char * tlv30; tlv30 = (char *)(2); }
    {cgc_size_t tlv29; tlv29 = (cgc_size_t)(2); }
    {cgc_size_t tlv31; tlv31 = (cgc_size_t)(2); }
    {int tlv28; tlv28 = (int)(2); }
    {char * tlv27; tlv27 = (char *)(2); }
    {int tlv6; tlv6 = (int)(2); }
    {char * tlv37; tlv37 = (char *)(2); }
    {char * tlv36; tlv36 = (char *)(2); }
    {cgc_size_t tlv34; tlv34 = (cgc_size_t)(2); }
    {char * tlv39; tlv39 = (char *)(2); }
    {cgc_size_t tlv38; tlv38 = (cgc_size_t)(2); }
    {cgc_size_t tlv40; tlv40 = (cgc_size_t)(2); }
    {int tlv7; tlv7 = (int)(2); }
    {unsigned tlv48; tlv48 = (unsigned)(2); }
    {cgc_size_t tlv45; tlv45 = (cgc_size_t)(2); }
    {char * tlv51; tlv51 = (char *)(2); }
    {cgc_size_t tlv50; tlv50 = (cgc_size_t)(2); }
    {cgc_size_t tlv52; tlv52 = (cgc_size_t)(2); }
    {unsigned tlv62; tlv62 = (unsigned)(2); }
    {cgc_size_t tlv57; tlv57 = (cgc_size_t)(2); }
    {char * tlv65; tlv65 = (char *)(2); }
    {cgc_size_t tlv64; tlv64 = (cgc_size_t)(2); }
    {int tlv60; tlv60 = (int)(2); }
    {char * tlv66; tlv66 = (char *)(2); }
}
void fix_ingred_main_20_27(){
fix_ingred_main_20_27_0();
}
void fix_ingred_main_20_32_0(){
const char tlv69 [0];
    bzero(&tlv69 [0],sizeof(char));
    {char input_buf [ ( 16 * 1024 ) ]; input_buf [ ( ( 16 * 1024 ) )-1 ] = (char)(cgc_strlen ( tlv69 )); }
    {int tlv1; tlv1 = (int)(cgc_strlen ( tlv69 )); }
    {int tlv2; tlv2 = (int)(cgc_strlen ( tlv69 )); }
    {char * command; command = (char *)(cgc_strlen ( tlv69 )); }
    {int tlv3; tlv3 = (int)(cgc_strlen ( tlv69 )); }
    {int tlv8; tlv8 = (int)(cgc_strlen ( tlv69 )); }
    {void * tlv11; tlv11 = (void *)(cgc_strlen ( tlv69 )); }
    {int tlv10; tlv10 = (int)(cgc_strlen ( tlv69 )); }
    {cgc_size_t tlv9; tlv9 = (cgc_size_t)(cgc_strlen ( tlv69 )); }
    {int tlv15; tlv15 = (int)(cgc_strlen ( tlv69 )); }
    {cgc_size_t tlv14; tlv14 = (cgc_size_t)(cgc_strlen ( tlv69 )); }
    {char tlv13; tlv13 = (char)(cgc_strlen ( tlv69 )); }
    {char * tlv12; tlv12 = (char *)(cgc_strlen ( tlv69 )); }
    {cgc_size_t tlv16; tlv16 = (cgc_size_t)(cgc_strlen ( tlv69 )); }
    {unsigned tlv21; tlv21 = (unsigned)(cgc_strlen ( tlv69 )); }
    {char * tlv20; tlv20 = (char *)(cgc_strlen ( tlv69 )); }
    {int tlv19; tlv19 = (int)(cgc_strlen ( tlv69 )); }
    {cgc_size_t tlv22; tlv22 = (cgc_size_t)(cgc_strlen ( tlv69 )); }
    {int tlv4; tlv4 = (int)(cgc_strlen ( tlv69 )); }
    {int tlv25; tlv25 = (int)(cgc_strlen ( tlv69 )); }
    {char * tlv30; tlv30 = (char *)(cgc_strlen ( tlv69 )); }
    {cgc_size_t tlv29; tlv29 = (cgc_size_t)(cgc_strlen ( tlv69 )); }
    {cgc_size_t tlv31; tlv31 = (cgc_size_t)(cgc_strlen ( tlv69 )); }
    {int tlv28; tlv28 = (int)(cgc_strlen ( tlv69 )); }
    {char * tlv27; tlv27 = (char *)(cgc_strlen ( tlv69 )); }
    {int tlv6; tlv6 = (int)(cgc_strlen ( tlv69 )); }
    {char * tlv37; tlv37 = (char *)(cgc_strlen ( tlv69 )); }
    {char * tlv36; tlv36 = (char *)(cgc_strlen ( tlv69 )); }
    {cgc_size_t tlv34; tlv34 = (cgc_size_t)(cgc_strlen ( tlv69 )); }
    {char * tlv39; tlv39 = (char *)(cgc_strlen ( tlv69 )); }
    {cgc_size_t tlv38; tlv38 = (cgc_size_t)(cgc_strlen ( tlv69 )); }
    {cgc_size_t tlv40; tlv40 = (cgc_size_t)(cgc_strlen ( tlv69 )); }
    {int tlv7; tlv7 = (int)(cgc_strlen ( tlv69 )); }
    {unsigned tlv48; tlv48 = (unsigned)(cgc_strlen ( tlv69 )); }
    {cgc_size_t tlv45; tlv45 = (cgc_size_t)(cgc_strlen ( tlv69 )); }
    {char * tlv51; tlv51 = (char *)(cgc_strlen ( tlv69 )); }
    {cgc_size_t tlv50; tlv50 = (cgc_size_t)(cgc_strlen ( tlv69 )); }
    {cgc_size_t tlv52; tlv52 = (cgc_size_t)(cgc_strlen ( tlv69 )); }
    {unsigned tlv62; tlv62 = (unsigned)(cgc_strlen ( tlv69 )); }
    {cgc_size_t tlv57; tlv57 = (cgc_size_t)(cgc_strlen ( tlv69 )); }
    {char * tlv65; tlv65 = (char *)(cgc_strlen ( tlv69 )); }
    {cgc_size_t tlv64; tlv64 = (cgc_size_t)(cgc_strlen ( tlv69 )); }
    {int tlv60; tlv60 = (int)(cgc_strlen ( tlv69 )); }
    {char * tlv66; tlv66 = (char *)(cgc_strlen ( tlv69 )); }
}
void fix_ingred_main_20_32(){
fix_ingred_main_20_32_0();
}
void fix_ingred_main_20_33_1(){
int tlv6;
    bzero(&tlv6,sizeof(int));
    {char input_buf [ ( 16 * 1024 ) ]; input_buf [ ( ( 16 * 1024 ) )-1 ] = (char)(tlv6); }
    {int tlv1; tlv1 = (int)(tlv6); }
    {int tlv2; tlv2 = (int)(tlv6); }
    {char * command; command = (char *)(tlv6); }
    {int tlv3; tlv3 = (int)(tlv6); }
    {int tlv8; tlv8 = (int)(tlv6); }
    {void * tlv11; tlv11 = (void *)(tlv6); }
    {int tlv10; tlv10 = (int)(tlv6); }
    {cgc_size_t tlv9; tlv9 = (cgc_size_t)(tlv6); }
    {int tlv15; tlv15 = (int)(tlv6); }
    {cgc_size_t tlv14; tlv14 = (cgc_size_t)(tlv6); }
    {char tlv13; tlv13 = (char)(tlv6); }
    {char * tlv12; tlv12 = (char *)(tlv6); }
    {cgc_size_t tlv16; tlv16 = (cgc_size_t)(tlv6); }
    {unsigned tlv21; tlv21 = (unsigned)(tlv6); }
    {char * tlv20; tlv20 = (char *)(tlv6); }
    {int tlv19; tlv19 = (int)(tlv6); }
    {cgc_size_t tlv22; tlv22 = (cgc_size_t)(tlv6); }
    {int tlv4; tlv4 = (int)(tlv6); }
    {int tlv25; tlv25 = (int)(tlv6); }
    {char * tlv30; tlv30 = (char *)(tlv6); }
    {cgc_size_t tlv29; tlv29 = (cgc_size_t)(tlv6); }
    {cgc_size_t tlv31; tlv31 = (cgc_size_t)(tlv6); }
    {int tlv28; tlv28 = (int)(tlv6); }
    {char * tlv27; tlv27 = (char *)(tlv6); }
    {char * tlv37; tlv37 = (char *)(tlv6); }
    {char * tlv36; tlv36 = (char *)(tlv6); }
    {cgc_size_t tlv34; tlv34 = (cgc_size_t)(tlv6); }
    {char * tlv39; tlv39 = (char *)(tlv6); }
    {cgc_size_t tlv38; tlv38 = (cgc_size_t)(tlv6); }
    {cgc_size_t tlv40; tlv40 = (cgc_size_t)(tlv6); }
    {int tlv7; tlv7 = (int)(tlv6); }
    {unsigned tlv48; tlv48 = (unsigned)(tlv6); }
    {cgc_size_t tlv45; tlv45 = (cgc_size_t)(tlv6); }
    {char * tlv51; tlv51 = (char *)(tlv6); }
    {cgc_size_t tlv50; tlv50 = (cgc_size_t)(tlv6); }
    {cgc_size_t tlv52; tlv52 = (cgc_size_t)(tlv6); }
    {unsigned tlv62; tlv62 = (unsigned)(tlv6); }
    {cgc_size_t tlv57; tlv57 = (cgc_size_t)(tlv6); }
    {char * tlv65; tlv65 = (char *)(tlv6); }
    {cgc_size_t tlv64; tlv64 = (cgc_size_t)(tlv6); }
    {int tlv60; tlv60 = (int)(tlv6); }
    {char * tlv66; tlv66 = (char *)(tlv6); }
}
void fix_ingred_main_20_33(){
fix_ingred_main_20_33_1();
}
void fix_ingred_main_20_34_1(){
    {char input_buf [ ( 16 * 1024 ) ]; input_buf [ ( ( 16 * 1024 ) )-1 ] = (char)(1); }
    {int tlv1; tlv1 = (int)(1); }
    {int tlv2; tlv2 = (int)(1); }
    {char * command; command = (char *)(1); }
    {int tlv8; tlv8 = (int)(1); }
    {void * tlv11; tlv11 = (void *)(1); }
    {int tlv15; tlv15 = (int)(1); }
    {char tlv13; tlv13 = (char)(1); }
    {char * tlv12; tlv12 = (char *)(1); }
    {unsigned tlv21; tlv21 = (unsigned)(1); }
    {char * tlv20; tlv20 = (char *)(1); }
    {cgc_size_t tlv22; tlv22 = (cgc_size_t)(1); }
    {int tlv4; tlv4 = (int)(1); }
    {int tlv25; tlv25 = (int)(1); }
    {char * tlv30; tlv30 = (char *)(1); }
    {cgc_size_t tlv29; tlv29 = (cgc_size_t)(1); }
    {cgc_size_t tlv31; tlv31 = (cgc_size_t)(1); }
    {int tlv28; tlv28 = (int)(1); }
    {char * tlv27; tlv27 = (char *)(1); }
    {int tlv6; tlv6 = (int)(1); }
    {char * tlv37; tlv37 = (char *)(1); }
    {char * tlv36; tlv36 = (char *)(1); }
    {cgc_size_t tlv34; tlv34 = (cgc_size_t)(1); }
    {char * tlv39; tlv39 = (char *)(1); }
    {cgc_size_t tlv38; tlv38 = (cgc_size_t)(1); }
    {cgc_size_t tlv40; tlv40 = (cgc_size_t)(1); }
    {int tlv7; tlv7 = (int)(1); }
    {unsigned tlv48; tlv48 = (unsigned)(1); }
    {cgc_size_t tlv45; tlv45 = (cgc_size_t)(1); }
    {char * tlv51; tlv51 = (char *)(1); }
    {cgc_size_t tlv50; tlv50 = (cgc_size_t)(1); }
    {cgc_size_t tlv52; tlv52 = (cgc_size_t)(1); }
    {unsigned tlv62; tlv62 = (unsigned)(1); }
    {cgc_size_t tlv57; tlv57 = (cgc_size_t)(1); }
    {char * tlv65; tlv65 = (char *)(1); }
    {cgc_size_t tlv64; tlv64 = (cgc_size_t)(1); }
    {int tlv60; tlv60 = (int)(1); }
    {char * tlv66; tlv66 = (char *)(1); }
}
void fix_ingred_main_20_34(){
fix_ingred_main_20_34_1();
}
void fix_ingred_main_20_36_0(){
    {char input_buf [ ( 16 * 1024 ) ]; input_buf [ ( ( 16 * 1024 ) )-1 ] = (char)(1); }
    {int tlv1; tlv1 = (int)(1); }
    {int tlv2; tlv2 = (int)(1); }
    {char * command; command = (char *)(1); }
    {int tlv3; tlv3 = (int)(1); }
    {int tlv8; tlv8 = (int)(1); }
    {void * tlv11; tlv11 = (void *)(1); }
    {int tlv10; tlv10 = (int)(1); }
    {cgc_size_t tlv9; tlv9 = (cgc_size_t)(1); }
    {int tlv15; tlv15 = (int)(1); }
    {cgc_size_t tlv14; tlv14 = (cgc_size_t)(1); }
    {char tlv13; tlv13 = (char)(1); }
    {char * tlv12; tlv12 = (char *)(1); }
    {cgc_size_t tlv16; tlv16 = (cgc_size_t)(1); }
    {unsigned tlv21; tlv21 = (unsigned)(1); }
    {char * tlv20; tlv20 = (char *)(1); }
    {int tlv19; tlv19 = (int)(1); }
    {cgc_size_t tlv22; tlv22 = (cgc_size_t)(1); }
    {int tlv4; tlv4 = (int)(1); }
    {int tlv25; tlv25 = (int)(1); }
    {char * tlv30; tlv30 = (char *)(1); }
    {cgc_size_t tlv29; tlv29 = (cgc_size_t)(1); }
    {cgc_size_t tlv31; tlv31 = (cgc_size_t)(1); }
    {int tlv28; tlv28 = (int)(1); }
    {char * tlv27; tlv27 = (char *)(1); }
    {int tlv6; tlv6 = (int)(1); }
    {char * tlv37; tlv37 = (char *)(1); }
    {char * tlv36; tlv36 = (char *)(1); }
    {cgc_size_t tlv34; tlv34 = (cgc_size_t)(1); }
    {char * tlv39; tlv39 = (char *)(1); }
    {cgc_size_t tlv38; tlv38 = (cgc_size_t)(1); }
    {cgc_size_t tlv40; tlv40 = (cgc_size_t)(1); }
    {int tlv7; tlv7 = (int)(1); }
    {unsigned tlv48; tlv48 = (unsigned)(1); }
    {cgc_size_t tlv45; tlv45 = (cgc_size_t)(1); }
    {char * tlv51; tlv51 = (char *)(1); }
    {cgc_size_t tlv50; tlv50 = (cgc_size_t)(1); }
    {cgc_size_t tlv52; tlv52 = (cgc_size_t)(1); }
    {unsigned tlv62; tlv62 = (unsigned)(1); }
    {cgc_size_t tlv57; tlv57 = (cgc_size_t)(1); }
    {char * tlv65; tlv65 = (char *)(1); }
    {cgc_size_t tlv64; tlv64 = (cgc_size_t)(1); }
    {int tlv60; tlv60 = (int)(1); }
    {char * tlv66; tlv66 = (char *)(1); }
}
void fix_ingred_main_20_36(){
fix_ingred_main_20_36_0();
}
void fix_ingred_main_20_41_0(){
const char tlv70 [0];
    bzero(&tlv70 [0],sizeof(char));
    {char input_buf [ ( 16 * 1024 ) ]; input_buf [ ( ( 16 * 1024 ) )-1 ] = (char)(cgc_strlen ( tlv70 )); }
    {int tlv1; tlv1 = (int)(cgc_strlen ( tlv70 )); }
    {int tlv2; tlv2 = (int)(cgc_strlen ( tlv70 )); }
    {char * command; command = (char *)(cgc_strlen ( tlv70 )); }
    {int tlv3; tlv3 = (int)(cgc_strlen ( tlv70 )); }
    {int tlv8; tlv8 = (int)(cgc_strlen ( tlv70 )); }
    {void * tlv11; tlv11 = (void *)(cgc_strlen ( tlv70 )); }
    {int tlv10; tlv10 = (int)(cgc_strlen ( tlv70 )); }
    {cgc_size_t tlv9; tlv9 = (cgc_size_t)(cgc_strlen ( tlv70 )); }
    {int tlv15; tlv15 = (int)(cgc_strlen ( tlv70 )); }
    {cgc_size_t tlv14; tlv14 = (cgc_size_t)(cgc_strlen ( tlv70 )); }
    {char tlv13; tlv13 = (char)(cgc_strlen ( tlv70 )); }
    {char * tlv12; tlv12 = (char *)(cgc_strlen ( tlv70 )); }
    {cgc_size_t tlv16; tlv16 = (cgc_size_t)(cgc_strlen ( tlv70 )); }
    {unsigned tlv21; tlv21 = (unsigned)(cgc_strlen ( tlv70 )); }
    {char * tlv20; tlv20 = (char *)(cgc_strlen ( tlv70 )); }
    {int tlv19; tlv19 = (int)(cgc_strlen ( tlv70 )); }
    {cgc_size_t tlv22; tlv22 = (cgc_size_t)(cgc_strlen ( tlv70 )); }
    {int tlv4; tlv4 = (int)(cgc_strlen ( tlv70 )); }
    {int tlv25; tlv25 = (int)(cgc_strlen ( tlv70 )); }
    {char * tlv30; tlv30 = (char *)(cgc_strlen ( tlv70 )); }
    {cgc_size_t tlv29; tlv29 = (cgc_size_t)(cgc_strlen ( tlv70 )); }
    {cgc_size_t tlv31; tlv31 = (cgc_size_t)(cgc_strlen ( tlv70 )); }
    {int tlv28; tlv28 = (int)(cgc_strlen ( tlv70 )); }
    {char * tlv27; tlv27 = (char *)(cgc_strlen ( tlv70 )); }
    {int tlv6; tlv6 = (int)(cgc_strlen ( tlv70 )); }
    {char * tlv37; tlv37 = (char *)(cgc_strlen ( tlv70 )); }
    {char * tlv36; tlv36 = (char *)(cgc_strlen ( tlv70 )); }
    {cgc_size_t tlv34; tlv34 = (cgc_size_t)(cgc_strlen ( tlv70 )); }
    {char * tlv39; tlv39 = (char *)(cgc_strlen ( tlv70 )); }
    {cgc_size_t tlv38; tlv38 = (cgc_size_t)(cgc_strlen ( tlv70 )); }
    {cgc_size_t tlv40; tlv40 = (cgc_size_t)(cgc_strlen ( tlv70 )); }
    {int tlv7; tlv7 = (int)(cgc_strlen ( tlv70 )); }
    {unsigned tlv48; tlv48 = (unsigned)(cgc_strlen ( tlv70 )); }
    {cgc_size_t tlv45; tlv45 = (cgc_size_t)(cgc_strlen ( tlv70 )); }
    {char * tlv51; tlv51 = (char *)(cgc_strlen ( tlv70 )); }
    {cgc_size_t tlv50; tlv50 = (cgc_size_t)(cgc_strlen ( tlv70 )); }
    {cgc_size_t tlv52; tlv52 = (cgc_size_t)(cgc_strlen ( tlv70 )); }
    {unsigned tlv62; tlv62 = (unsigned)(cgc_strlen ( tlv70 )); }
    {cgc_size_t tlv57; tlv57 = (cgc_size_t)(cgc_strlen ( tlv70 )); }
    {char * tlv65; tlv65 = (char *)(cgc_strlen ( tlv70 )); }
    {cgc_size_t tlv64; tlv64 = (cgc_size_t)(cgc_strlen ( tlv70 )); }
    {int tlv60; tlv60 = (int)(cgc_strlen ( tlv70 )); }
    {char * tlv66; tlv66 = (char *)(cgc_strlen ( tlv70 )); }
}
void fix_ingred_main_20_41(){
fix_ingred_main_20_41_0();
}
void fix_ingred_main_20_42_1(){
int tlv7;
    bzero(&tlv7,sizeof(int));
    {char input_buf [ ( 16 * 1024 ) ]; input_buf [ ( ( 16 * 1024 ) )-1 ] = (char)(tlv7); }
    {int tlv1; tlv1 = (int)(tlv7); }
    {int tlv2; tlv2 = (int)(tlv7); }
    {char * command; command = (char *)(tlv7); }
    {int tlv3; tlv3 = (int)(tlv7); }
    {int tlv8; tlv8 = (int)(tlv7); }
    {void * tlv11; tlv11 = (void *)(tlv7); }
    {int tlv10; tlv10 = (int)(tlv7); }
    {cgc_size_t tlv9; tlv9 = (cgc_size_t)(tlv7); }
    {int tlv15; tlv15 = (int)(tlv7); }
    {cgc_size_t tlv14; tlv14 = (cgc_size_t)(tlv7); }
    {char tlv13; tlv13 = (char)(tlv7); }
    {char * tlv12; tlv12 = (char *)(tlv7); }
    {cgc_size_t tlv16; tlv16 = (cgc_size_t)(tlv7); }
    {unsigned tlv21; tlv21 = (unsigned)(tlv7); }
    {char * tlv20; tlv20 = (char *)(tlv7); }
    {int tlv19; tlv19 = (int)(tlv7); }
    {cgc_size_t tlv22; tlv22 = (cgc_size_t)(tlv7); }
    {int tlv4; tlv4 = (int)(tlv7); }
    {int tlv25; tlv25 = (int)(tlv7); }
    {char * tlv30; tlv30 = (char *)(tlv7); }
    {cgc_size_t tlv29; tlv29 = (cgc_size_t)(tlv7); }
    {cgc_size_t tlv31; tlv31 = (cgc_size_t)(tlv7); }
    {int tlv28; tlv28 = (int)(tlv7); }
    {char * tlv27; tlv27 = (char *)(tlv7); }
    {int tlv6; tlv6 = (int)(tlv7); }
    {char * tlv37; tlv37 = (char *)(tlv7); }
    {char * tlv36; tlv36 = (char *)(tlv7); }
    {cgc_size_t tlv34; tlv34 = (cgc_size_t)(tlv7); }
    {char * tlv39; tlv39 = (char *)(tlv7); }
    {cgc_size_t tlv38; tlv38 = (cgc_size_t)(tlv7); }
    {cgc_size_t tlv40; tlv40 = (cgc_size_t)(tlv7); }
    {unsigned tlv48; tlv48 = (unsigned)(tlv7); }
    {cgc_size_t tlv45; tlv45 = (cgc_size_t)(tlv7); }
    {char * tlv51; tlv51 = (char *)(tlv7); }
    {cgc_size_t tlv50; tlv50 = (cgc_size_t)(tlv7); }
    {cgc_size_t tlv52; tlv52 = (cgc_size_t)(tlv7); }
    {unsigned tlv62; tlv62 = (unsigned)(tlv7); }
    {cgc_size_t tlv57; tlv57 = (cgc_size_t)(tlv7); }
    {char * tlv65; tlv65 = (char *)(tlv7); }
    {cgc_size_t tlv64; tlv64 = (cgc_size_t)(tlv7); }
    {int tlv60; tlv60 = (int)(tlv7); }
    {char * tlv66; tlv66 = (char *)(tlv7); }
}
void fix_ingred_main_20_42(){
fix_ingred_main_20_42_1();
}
void fix_ingred_main_20_52_1(){
char resp_ref;
    bzero(&resp_ref,1*sizeof(char));
const char * resp = &resp_ref;
    {char input_buf [ ( 16 * 1024 ) ]; input_buf [ ( ( 16 * 1024 ) )-1 ] = (char)(( char * ) resp); }
    {int tlv1; tlv1 = (int)(( char * ) resp); }
    {int tlv2; tlv2 = (int)(( char * ) resp); }
    {char * command; command = (char *)(( char * ) resp); }
    {int tlv3; tlv3 = (int)(( char * ) resp); }
    {int tlv8; tlv8 = (int)(( char * ) resp); }
    {void * tlv11; tlv11 = (void *)(( char * ) resp); }
    {int tlv10; tlv10 = (int)(( char * ) resp); }
    {cgc_size_t tlv9; tlv9 = (cgc_size_t)(( char * ) resp); }
    {int tlv15; tlv15 = (int)(( char * ) resp); }
    {cgc_size_t tlv14; tlv14 = (cgc_size_t)(( char * ) resp); }
    {char tlv13; tlv13 = (char)(( char * ) resp); }
    {char * tlv12; tlv12 = (char *)(( char * ) resp); }
    {cgc_size_t tlv16; tlv16 = (cgc_size_t)(( char * ) resp); }
    {unsigned tlv21; tlv21 = (unsigned)(( char * ) resp); }
    {char * tlv20; tlv20 = (char *)(( char * ) resp); }
    {int tlv19; tlv19 = (int)(( char * ) resp); }
    {cgc_size_t tlv22; tlv22 = (cgc_size_t)(( char * ) resp); }
    {int tlv4; tlv4 = (int)(( char * ) resp); }
    {int tlv25; tlv25 = (int)(( char * ) resp); }
    {char * tlv30; tlv30 = (char *)(( char * ) resp); }
    {cgc_size_t tlv29; tlv29 = (cgc_size_t)(( char * ) resp); }
    {cgc_size_t tlv31; tlv31 = (cgc_size_t)(( char * ) resp); }
    {int tlv28; tlv28 = (int)(( char * ) resp); }
    {char * tlv27; tlv27 = (char *)(( char * ) resp); }
    {int tlv6; tlv6 = (int)(( char * ) resp); }
    {char * tlv37; tlv37 = (char *)(( char * ) resp); }
    {char * tlv36; tlv36 = (char *)(( char * ) resp); }
    {cgc_size_t tlv34; tlv34 = (cgc_size_t)(( char * ) resp); }
    {char * tlv39; tlv39 = (char *)(( char * ) resp); }
    {cgc_size_t tlv38; tlv38 = (cgc_size_t)(( char * ) resp); }
    {cgc_size_t tlv40; tlv40 = (cgc_size_t)(( char * ) resp); }
    {int tlv7; tlv7 = (int)(( char * ) resp); }
    {unsigned tlv48; tlv48 = (unsigned)(( char * ) resp); }
    {cgc_size_t tlv45; tlv45 = (cgc_size_t)(( char * ) resp); }
    {char * tlv51; tlv51 = (char *)(( char * ) resp); }
    {cgc_size_t tlv50; tlv50 = (cgc_size_t)(( char * ) resp); }
    {cgc_size_t tlv52; tlv52 = (cgc_size_t)(( char * ) resp); }
    {unsigned tlv62; tlv62 = (unsigned)(( char * ) resp); }
    {cgc_size_t tlv57; tlv57 = (cgc_size_t)(( char * ) resp); }
    {char * tlv65; tlv65 = (char *)(( char * ) resp); }
    {cgc_size_t tlv64; tlv64 = (cgc_size_t)(( char * ) resp); }
    {int tlv60; tlv60 = (int)(( char * ) resp); }
    {char * tlv66; tlv66 = (char *)(( char * ) resp); }
}
void fix_ingred_main_20_52(){
fix_ingred_main_20_52_1();
}
void fix_ingred_main_20(){
fix_ingred_main_20_2();
fix_ingred_main_20_3();
fix_ingred_main_20_4();
fix_ingred_main_20_5();
fix_ingred_main_20_6();
fix_ingred_main_20_7();
fix_ingred_main_20_9();
fix_ingred_main_20_12();
fix_ingred_main_20_13();
fix_ingred_main_20_15();
fix_ingred_main_20_17();
fix_ingred_main_20_23();
fix_ingred_main_20_24();
fix_ingred_main_20_27();
fix_ingred_main_20_32();
fix_ingred_main_20_33();
fix_ingred_main_20_34();
fix_ingred_main_20_36();
fix_ingred_main_20_41();
fix_ingred_main_20_42();
fix_ingred_main_20_52();
}
