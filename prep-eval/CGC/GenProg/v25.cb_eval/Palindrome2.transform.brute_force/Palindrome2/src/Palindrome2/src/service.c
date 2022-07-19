typedef unsigned long cgc_size_t;
typedef long cgc_ssize_t;
typedef long _fd_mask;
struct __anonstruct_cgc_fd_set_1 {
   _fd_mask _fd_bits[1024UL / (8UL * sizeof(_fd_mask ))] ;
};
typedef struct __anonstruct_cgc_fd_set_1 cgc_fd_set;
struct cgc_timeval {
   int tv_sec ;
   int tv_usec ;
};
struct __anonstruct_jmp_buf_2 {
   long _b[8] ;
};
typedef struct __anonstruct_jmp_buf_2 jmp_buf[1];
extern  __attribute__((__noreturn__)) void cgc__terminate(unsigned int status ) ;
extern int cgc_transmit(int fd , void const   *buf , cgc_size_t count ,
                        cgc_size_t *tx_bytes ) ;
extern int cgc_receive(int fd , void *buf , cgc_size_t count ,
                       cgc_size_t *rx_bytes ) ;
extern int cgc_fdwait(int nfds , cgc_fd_set *readfds , cgc_fd_set *writefds ,
                      struct cgc_timeval  const  *timeout , int *readyfds ) ;
extern int cgc_allocate(cgc_size_t length , int is_X , void **addr ) ;
extern int cgc_deallocate(void *addr , cgc_size_t length ) ;
extern int cgc_random(void *buf , cgc_size_t count , cgc_size_t *rnd_bytes ) ;
extern int cgc_setjmp(struct __anonstruct_jmp_buf_2 * )  __attribute__((__returns_twice__)) ;
extern  __attribute__((__noreturn__)) void cgc_longjmp(struct __anonstruct_jmp_buf_2 * ,
                                                       int  ) ;
extern float cgc_sinf(float  ) ;
extern double cgc_sin(double  ) ;
extern long double cgc_sinl(long double  ) ;
extern float cgc_cosf(float  ) ;
extern double cgc_cos(double  ) ;
extern long double cgc_cosl(long double  ) ;
extern float cgc_tanf(float  ) ;
extern double cgc_tan(double  ) ;
extern long double cgc_tanl(long double  ) ;
extern float cgc_logf(float  ) ;
extern double cgc_log(double  ) ;
extern long double cgc_logl(long double  ) ;
extern float cgc_rintf(float  ) ;
extern double cgc_rint(double  ) ;
extern long double cgc_rintl(long double  ) ;
extern float cgc_sqrtf(float  ) ;
extern double cgc_sqrt(double  ) ;
extern long double cgc_sqrtl(long double  ) ;
extern float cgc_fabsf(float  ) ;
extern double cgc_fabs(double  ) ;
extern long double cgc_fabsl(long double  ) ;
extern float cgc_log2f(float  ) ;
extern double cgc_log2(double  ) ;
extern long double cgc_log2l(long double  ) ;
extern float cgc_exp2f(float  ) ;
extern double cgc_exp2(double  ) ;
extern long double cgc_exp2l(long double  ) ;
extern float cgc_expf(float  ) ;
extern double cgc_exp(double  ) ;
extern long double cgc_expl(long double  ) ;
extern float cgc_log10f(float  ) ;
extern double cgc_log10(double  ) ;
extern long double cgc_log10l(long double  ) ;
extern float cgc_powf(float  , float  ) ;
extern double cgc_pow(double  , double  ) ;
extern long double cgc_powl(long double  , long double  ) ;
extern float cgc_atan2f(float  , float  ) ;
extern double cgc_atan2(double  , double  ) ;
extern long double cgc_atan2l(long double  , long double  ) ;
extern float cgc_remainderf(float  , float  ) ;
extern double cgc_remainder(double  , double  ) ;
extern long double cgc_remainderl(long double  , long double  ) ;
extern float cgc_scalbnf(float  , int  ) ;
extern double cgc_scalbn(double  , int  ) ;
extern long double cgc_scalbnl(long double  , int  ) ;
extern float cgc_scalblnf(float  , long  ) ;
extern double cgc_scalbln(double  , long  ) ;
extern long double cgc_scalblnl(long double  , long  ) ;
extern float cgc_significandf(float  ) ;
extern double cgc_significand(double  ) ;
extern long double cgc_significandl(long double  ) ;
extern int cgc_transmit_all(int fd , char const   *buf ,
                            cgc_size_t const   size ) ;
extern int cgc_receive_delim(int fd , char *buf , cgc_size_t const   size ,
                             char delim ) ;
int cgc_check(void) ;
static int fix_ingred_enable  =    0;
extern int ( /* missing proto */  getenv)() ;
static void fix_ingred_enable_init(void)  __attribute__((__constructor__)) ;
static void fix_ingred_enable_init(void) 
{ 
  char *tmp ;
  int tmp___0 ;

  {
  tmp___0 = getenv("ENABLE_FIXES");
  tmp = (char *)tmp___0;
  if (tmp) {
    fix_ingred_enable = 1;
  } else {

  }
  return;
}
}
void fix_ingred_service_0_1_0(void) ;
void fix_ingred_service_0_1_1(void) ;
void fix_ingred_service_0_1(void) ;
void fix_ingred_service_0_2_0(void) ;
void fix_ingred_service_0_2_1(void) ;
void fix_ingred_service_0_2(void) ;
void fix_ingred_service_0_3_0(void) ;
void fix_ingred_service_0_3(void) ;
void fix_ingred_service_0_5_1(void) ;
void fix_ingred_service_0_5(void) ;
void fix_ingred_service_0_6_0(void) ;
void fix_ingred_service_0_6(void) ;
void fix_ingred_service_0_8_0(void) ;
void fix_ingred_service_0_8_1(void) ;
void fix_ingred_service_0_8(void) ;
void fix_ingred_service_0_11_1(void) ;
void fix_ingred_service_0_11(void) ;
void fix_ingred_service_0_12_2(void) ;
void fix_ingred_service_0_12(void) ;
void fix_ingred_service_0_15_1(void) ;
void fix_ingred_service_0_15(void) ;
void fix_ingred_service_0_16_0(void) ;
void fix_ingred_service_0_16(void) ;
void fix_ingred_service_0(void) ;
int main(int cgc_argc , char **cgc_argv ) 
{ 
  int r ;
  int tlv1 ;
  int tlv7 ;
  char const   *tlv6 ;
  cgc_size_t tlv5 ;
  unsigned int tlv8 ;
  int tlv2 ;
  int tlv11 ;
  char const   *tlv10 ;
  cgc_size_t tlv9 ;
  unsigned int tlv12 ;
  int tlv3 ;
  int tlv15 ;
  char const   *tlv14 ;
  cgc_size_t tlv13 ;
  unsigned int tlv19 ;
  int tlv4 ;
  int tlv18 ;
  char const   *tlv17 ;
  cgc_size_t tlv16 ;
  unsigned int tlv20 ;

  {
  if (fix_ingred_enable) {
    fix_ingred_service_0();
  } else {

  }
  tlv7 = 1;
  tlv6 = "\nWelcome to Palindrome Finder\n\n";
  tlv5 = sizeof("\nWelcome to Palindrome Finder\n\n") - 1UL;
  tlv1 = cgc_transmit_all(tlv7, tlv6, (cgc_size_t const   )tlv5);
  if (tlv1 != 0) {
    tlv8 = 0U;
    cgc__terminate(tlv8);
  } else {

  }
  while (1) {
    tlv11 = 1;
    tlv10 = "\tPlease enter a possible palindrome: ";
    tlv9 = sizeof("\tPlease enter a possible palindrome: ") - 1UL;
    tlv2 = cgc_transmit_all(tlv11, tlv10, (cgc_size_t const   )tlv9);
    if (tlv2 != 0) {
      tlv12 = 0U;
      cgc__terminate(tlv12);
    } else {

    }
    r = cgc_check();
    if (r == -1) {
      break;
    } else
    if (r == 0) {
      tlv15 = 1;
      tlv14 = "\t\tNope, that\'s not a palindrome\n\n";
      tlv13 = sizeof("\t\tNope, that\'s not a palindrome\n\n") - 1UL;
      tlv3 = cgc_transmit_all(tlv15, tlv14, (cgc_size_t const   )tlv13);
      if (tlv3 != 0) {
        tlv19 = 0U;
        cgc__terminate(tlv19);
      } else {

      }
    } else {
      tlv18 = 1;
      tlv17 = "\t\tYes, that\'s a palindrome!\n\n";
      tlv16 = sizeof("\t\tYes, that\'s a palindrome!\n\n") - 1UL;
      tlv4 = cgc_transmit_all(tlv18, tlv17, (cgc_size_t const   )tlv16);
      if (tlv4 != 0) {
        tlv20 = 0U;
        cgc__terminate(tlv20);
      } else {

      }
    }
  }
  return (0);
}
}
void fix_ingred_service_1_0_0(void) ;
void fix_ingred_service_1_0_1(void) ;
void fix_ingred_service_1_0_2(void) ;
void fix_ingred_service_1_0_3(void) ;
void fix_ingred_service_1_0(void) ;
void fix_ingred_service_1_1_4(void) ;
void fix_ingred_service_1_1_5(void) ;
void fix_ingred_service_1_1_6(void) ;
void fix_ingred_service_1_1(void) ;
void fix_ingred_service_1_2_1(void) ;
void fix_ingred_service_1_2_2(void) ;
void fix_ingred_service_1_2_3(void) ;
void fix_ingred_service_1_2(void) ;
void fix_ingred_service_1_3_3(void) ;
void fix_ingred_service_1_3(void) ;
void fix_ingred_service_1_4_4(void) ;
void fix_ingred_service_1_4_5(void) ;
void fix_ingred_service_1_4(void) ;
void fix_ingred_service_1_8_4(void) ;
void fix_ingred_service_1_8_5(void) ;
void fix_ingred_service_1_8(void) ;
void fix_ingred_service_1_9_1(void) ;
void fix_ingred_service_1_9(void) ;
void fix_ingred_service_1_10_6(void) ;
void fix_ingred_service_1_10(void) ;
void fix_ingred_service_1_11_0(void) ;
void fix_ingred_service_1_11(void) ;
void fix_ingred_service_1(void) ;
int cgc_check(void) 
{ 
  int len ;
  int i ;
  int pal ;
  char string[64] ;
  unsigned long tlv_size_0 ;
  int tlv1 ;
  int tlv6 ;
  char *tlv5 ;
  cgc_size_t tlv4 ;
  char tlv3 ;
  int steps ;
  int tlv2 ;
  int tlv9 ;
  char const   *tlv8 ;
  cgc_size_t tlv7 ;
  unsigned int tlv10 ;

  {
  if (fix_ingred_enable) {
    fix_ingred_service_1();
  } else {

  }
  len = -1;
  pal = 1;
  tlv_size_0 = sizeof(string);
  i = 0;
  while ((unsigned long )i < tlv_size_0) {
    string[i] = (char )'\000';
    i ++;
  }
  tlv6 = 0;
  tlv5 = string;
  tlv4 = (cgc_size_t )128;
  tlv3 = (char )'\n';
  tlv1 = cgc_receive_delim(tlv6, tlv5, (cgc_size_t const   )tlv4, tlv3);
  if (tlv1 != 0) {
    return (-1);
  } else {

  }
  i = 0;
  while ((int )string[i] != 0) {
    len ++;
    i ++;
  }
  steps = len;
  if (len % 2 == 1) {
    steps --;
  } else {

  }
  i = 0;
  while (i <= steps / 2) {
    if ((int )string[i] != (int )string[(len - 1) - i]) {
      pal = 0;
    } else {

    }
    i ++;
  }
  if ((int )string[0] == 94) {
    tlv9 = 1;
    tlv8 = "\n\nEASTER EGG!\n\n";
    tlv7 = sizeof("\n\nEASTER EGG!\n\n") - 1UL;
    tlv2 = cgc_transmit_all(tlv9, tlv8, (cgc_size_t const   )tlv7);
    if (tlv2 != 0) {
      tlv10 = 0U;
      cgc__terminate(tlv10);
    } else {

    }
  } else {

  }
  return (pal);
}
}
void fix_ingred_service_0_1_0(void) 
{ 
  int r ;
  int tlv1 ;
  int tlv7 ;
  cgc_size_t tlv5 ;
  int tlv2 ;
  unsigned int tlv8 ;
  int tlv11 ;
  cgc_size_t tlv9 ;
  unsigned int tlv12 ;
  int tlv3 ;
  int tlv4 ;
  int tlv15 ;
  cgc_size_t tlv13 ;
  int tlv18 ;
  cgc_size_t tlv16 ;
  unsigned int tlv19 ;
  unsigned int tlv20 ;

  {
  r = 1;
  tlv1 = 1;
  tlv7 = 1;
  tlv5 = (cgc_size_t )1;
  tlv2 = 1;
  tlv8 = 1U;
  tlv11 = 1;
  tlv9 = (cgc_size_t )1;
  tlv12 = 1U;
  tlv3 = 1;
  tlv4 = 1;
  tlv15 = 1;
  tlv13 = (cgc_size_t )1;
  tlv18 = 1;
  tlv16 = (cgc_size_t )1;
  tlv19 = 1U;
  tlv20 = 1U;
  return;
}
}
void fix_ingred_service_0_1_1(void) 
{ 
  int r ;
  int tlv1 ;
  int tlv7 ;
  cgc_size_t tlv5 ;
  int tlv2 ;
  unsigned int tlv8 ;
  int tlv11 ;
  cgc_size_t tlv9 ;
  unsigned int tlv12 ;
  int tlv3 ;
  int tlv4 ;
  int tlv15 ;
  cgc_size_t tlv13 ;
  int tlv18 ;
  cgc_size_t tlv16 ;
  unsigned int tlv19 ;
  unsigned int tlv20 ;

  {
  r = (int )(sizeof("\nWelcome to Palindrome Finder\n\n") - 1UL);
  tlv1 = (int )(sizeof("\nWelcome to Palindrome Finder\n\n") - 1UL);
  tlv7 = (int )(sizeof("\nWelcome to Palindrome Finder\n\n") - 1UL);
  tlv5 = sizeof("\nWelcome to Palindrome Finder\n\n") - 1UL;
  tlv2 = (int )(sizeof("\nWelcome to Palindrome Finder\n\n") - 1UL);
  tlv8 = (unsigned int )(sizeof("\nWelcome to Palindrome Finder\n\n") - 1UL);
  tlv11 = (int )(sizeof("\nWelcome to Palindrome Finder\n\n") - 1UL);
  tlv9 = sizeof("\nWelcome to Palindrome Finder\n\n") - 1UL;
  tlv12 = (unsigned int )(sizeof("\nWelcome to Palindrome Finder\n\n") - 1UL);
  tlv3 = (int )(sizeof("\nWelcome to Palindrome Finder\n\n") - 1UL);
  tlv4 = (int )(sizeof("\nWelcome to Palindrome Finder\n\n") - 1UL);
  tlv15 = (int )(sizeof("\nWelcome to Palindrome Finder\n\n") - 1UL);
  tlv13 = sizeof("\nWelcome to Palindrome Finder\n\n") - 1UL;
  tlv18 = (int )(sizeof("\nWelcome to Palindrome Finder\n\n") - 1UL);
  tlv16 = sizeof("\nWelcome to Palindrome Finder\n\n") - 1UL;
  tlv19 = (unsigned int )(sizeof("\nWelcome to Palindrome Finder\n\n") - 1UL);
  tlv20 = (unsigned int )(sizeof("\nWelcome to Palindrome Finder\n\n") - 1UL);
  return;
}
}
void fix_ingred_service_0_1(void) 
{ 


  {
  fix_ingred_service_0_1_0();
  fix_ingred_service_0_1_1();
  return;
}
}
extern int ( /* missing proto */  bzero)() ;
void fix_ingred_service_0_2_0(void) 
{ 
  int tlv1 ;
  int r ;
  int tlv7 ;
  cgc_size_t tlv5 ;
  int tlv2 ;
  unsigned int tlv8 ;
  int tlv11 ;
  cgc_size_t tlv9 ;
  unsigned int tlv12 ;
  int tlv3 ;
  int tlv4 ;
  int tlv15 ;
  cgc_size_t tlv13 ;
  int tlv18 ;
  cgc_size_t tlv16 ;
  unsigned int tlv19 ;
  unsigned int tlv20 ;

  {
  bzero(& tlv1, sizeof(int ));
  r = tlv1;
  tlv7 = tlv1;
  tlv5 = (cgc_size_t )tlv1;
  tlv2 = tlv1;
  tlv8 = (unsigned int )tlv1;
  tlv11 = tlv1;
  tlv9 = (cgc_size_t )tlv1;
  tlv12 = (unsigned int )tlv1;
  tlv3 = tlv1;
  tlv4 = tlv1;
  tlv15 = tlv1;
  tlv13 = (cgc_size_t )tlv1;
  tlv18 = tlv1;
  tlv16 = (cgc_size_t )tlv1;
  tlv19 = (unsigned int )tlv1;
  tlv20 = (unsigned int )tlv1;
  return;
}
}
void fix_ingred_service_0_2_1(void) 
{ 
  int tlv1 ;
  int r ;
  int tlv1___0 ;
  int tlv7 ;
  cgc_size_t tlv5 ;
  int tlv2 ;
  unsigned int tlv8 ;
  int tlv11 ;
  cgc_size_t tlv9 ;
  unsigned int tlv12 ;
  int tlv3 ;
  int tlv4 ;
  int tlv15 ;
  cgc_size_t tlv13 ;
  int tlv18 ;
  cgc_size_t tlv16 ;
  unsigned int tlv19 ;
  unsigned int tlv20 ;

  {
  bzero(& tlv1, sizeof(int ));
  r = 0;
  tlv1___0 = 0;
  tlv7 = 0;
  tlv5 = (cgc_size_t )0;
  tlv2 = 0;
  tlv8 = 0U;
  tlv11 = 0;
  tlv9 = (cgc_size_t )0;
  tlv12 = 0U;
  tlv3 = 0;
  tlv4 = 0;
  tlv15 = 0;
  tlv13 = (cgc_size_t )0;
  tlv18 = 0;
  tlv16 = (cgc_size_t )0;
  tlv19 = 0U;
  tlv20 = 0U;
  return;
}
}
void fix_ingred_service_0_2(void) 
{ 


  {
  fix_ingred_service_0_2_0();
  fix_ingred_service_0_2_1();
  return;
}
}
void fix_ingred_service_0_3_0(void) 
{ 
  int r ;
  int tlv1 ;
  int tlv7 ;
  cgc_size_t tlv5 ;
  int tlv2 ;
  unsigned int tlv8 ;
  int tlv11 ;
  cgc_size_t tlv9 ;
  unsigned int tlv12 ;
  int tlv3 ;
  int tlv4 ;
  int tlv15 ;
  cgc_size_t tlv13 ;
  int tlv18 ;
  cgc_size_t tlv16 ;
  unsigned int tlv19 ;
  unsigned int tlv20 ;

  {
  r = 0;
  tlv1 = 0;
  tlv7 = 0;
  tlv5 = (cgc_size_t )0;
  tlv2 = 0;
  tlv8 = 0U;
  tlv11 = 0;
  tlv9 = (cgc_size_t )0;
  tlv12 = 0U;
  tlv3 = 0;
  tlv4 = 0;
  tlv15 = 0;
  tlv13 = (cgc_size_t )0;
  tlv18 = 0;
  tlv16 = (cgc_size_t )0;
  tlv19 = 0U;
  tlv20 = 0U;
  return;
}
}
void fix_ingred_service_0_3(void) 
{ 


  {
  fix_ingred_service_0_3_0();
  return;
}
}
void fix_ingred_service_0_5_1(void) 
{ 
  int r ;
  int tlv1 ;
  int tlv7 ;
  cgc_size_t tlv5 ;
  int tlv2 ;
  unsigned int tlv8 ;
  int tlv11 ;
  cgc_size_t tlv9 ;
  unsigned int tlv12 ;
  int tlv3 ;
  int tlv4 ;
  int tlv15 ;
  cgc_size_t tlv13 ;
  int tlv18 ;
  cgc_size_t tlv16 ;
  unsigned int tlv19 ;
  unsigned int tlv20 ;

  {
  r = (int )(sizeof("\tPlease enter a possible palindrome: ") - 1UL);
  tlv1 = (int )(sizeof("\tPlease enter a possible palindrome: ") - 1UL);
  tlv7 = (int )(sizeof("\tPlease enter a possible palindrome: ") - 1UL);
  tlv5 = sizeof("\tPlease enter a possible palindrome: ") - 1UL;
  tlv2 = (int )(sizeof("\tPlease enter a possible palindrome: ") - 1UL);
  tlv8 = (unsigned int )(sizeof("\tPlease enter a possible palindrome: ") - 1UL);
  tlv11 = (int )(sizeof("\tPlease enter a possible palindrome: ") - 1UL);
  tlv9 = sizeof("\tPlease enter a possible palindrome: ") - 1UL;
  tlv12 = (unsigned int )(sizeof("\tPlease enter a possible palindrome: ") - 1UL);
  tlv3 = (int )(sizeof("\tPlease enter a possible palindrome: ") - 1UL);
  tlv4 = (int )(sizeof("\tPlease enter a possible palindrome: ") - 1UL);
  tlv15 = (int )(sizeof("\tPlease enter a possible palindrome: ") - 1UL);
  tlv13 = sizeof("\tPlease enter a possible palindrome: ") - 1UL;
  tlv18 = (int )(sizeof("\tPlease enter a possible palindrome: ") - 1UL);
  tlv16 = sizeof("\tPlease enter a possible palindrome: ") - 1UL;
  tlv19 = (unsigned int )(sizeof("\tPlease enter a possible palindrome: ") - 1UL);
  tlv20 = (unsigned int )(sizeof("\tPlease enter a possible palindrome: ") - 1UL);
  return;
}
}
void fix_ingred_service_0_5(void) 
{ 


  {
  fix_ingred_service_0_5_1();
  return;
}
}
void fix_ingred_service_0_6_0(void) 
{ 
  int tlv2 ;
  int r ;
  int tlv1 ;
  int tlv7 ;
  cgc_size_t tlv5 ;
  unsigned int tlv8 ;
  int tlv11 ;
  cgc_size_t tlv9 ;
  unsigned int tlv12 ;
  int tlv3 ;
  int tlv4 ;
  int tlv15 ;
  cgc_size_t tlv13 ;
  int tlv18 ;
  cgc_size_t tlv16 ;
  unsigned int tlv19 ;
  unsigned int tlv20 ;

  {
  bzero(& tlv2, sizeof(int ));
  r = tlv2;
  tlv1 = tlv2;
  tlv7 = tlv2;
  tlv5 = (cgc_size_t )tlv2;
  tlv8 = (unsigned int )tlv2;
  tlv11 = tlv2;
  tlv9 = (cgc_size_t )tlv2;
  tlv12 = (unsigned int )tlv2;
  tlv3 = tlv2;
  tlv4 = tlv2;
  tlv15 = tlv2;
  tlv13 = (cgc_size_t )tlv2;
  tlv18 = tlv2;
  tlv16 = (cgc_size_t )tlv2;
  tlv19 = (unsigned int )tlv2;
  tlv20 = (unsigned int )tlv2;
  return;
}
}
void fix_ingred_service_0_6(void) 
{ 


  {
  fix_ingred_service_0_6_0();
  return;
}
}
void fix_ingred_service_0_8_0(void) 
{ 
  int r ;
  int tlv1 ;
  int tlv7 ;
  cgc_size_t tlv5 ;
  int tlv2 ;
  unsigned int tlv8 ;
  int tlv11 ;
  cgc_size_t tlv9 ;
  unsigned int tlv12 ;
  int tlv3 ;
  int tlv4 ;
  int tlv15 ;
  cgc_size_t tlv13 ;
  int tlv18 ;
  cgc_size_t tlv16 ;
  unsigned int tlv19 ;
  unsigned int tlv20 ;

  {
  bzero(& r, sizeof(int ));
  tlv1 = r;
  tlv7 = r;
  tlv5 = (cgc_size_t )r;
  tlv2 = r;
  tlv8 = (unsigned int )r;
  tlv11 = r;
  tlv9 = (cgc_size_t )r;
  tlv12 = (unsigned int )r;
  tlv3 = r;
  tlv4 = r;
  tlv15 = r;
  tlv13 = (cgc_size_t )r;
  tlv18 = r;
  tlv16 = (cgc_size_t )r;
  tlv19 = (unsigned int )r;
  tlv20 = (unsigned int )r;
  return;
}
}
void fix_ingred_service_0_8_1(void) 
{ 
  int r ;
  int r___0 ;
  int tlv1 ;
  int tlv7 ;
  cgc_size_t tlv5 ;
  int tlv2 ;
  unsigned int tlv8 ;
  int tlv11 ;
  cgc_size_t tlv9 ;
  unsigned int tlv12 ;
  int tlv3 ;
  int tlv4 ;
  int tlv15 ;
  cgc_size_t tlv13 ;
  int tlv18 ;
  cgc_size_t tlv16 ;
  unsigned int tlv19 ;
  unsigned int tlv20 ;

  {
  bzero(& r, sizeof(int ));
  r___0 = -1;
  tlv1 = -1;
  tlv7 = -1;
  tlv5 = (cgc_size_t )-1;
  tlv2 = -1;
  tlv8 = 4294967295U;
  tlv11 = -1;
  tlv9 = (cgc_size_t )-1;
  tlv12 = 4294967295U;
  tlv3 = -1;
  tlv4 = -1;
  tlv15 = -1;
  tlv13 = (cgc_size_t )-1;
  tlv18 = -1;
  tlv16 = (cgc_size_t )-1;
  tlv19 = 4294967295U;
  tlv20 = 4294967295U;
  return;
}
}
void fix_ingred_service_0_8(void) 
{ 


  {
  fix_ingred_service_0_8_0();
  fix_ingred_service_0_8_1();
  return;
}
}
void fix_ingred_service_0_11_1(void) 
{ 
  int r ;
  int tlv1 ;
  int tlv7 ;
  cgc_size_t tlv5 ;
  int tlv2 ;
  unsigned int tlv8 ;
  int tlv11 ;
  cgc_size_t tlv9 ;
  unsigned int tlv12 ;
  int tlv3 ;
  int tlv4 ;
  int tlv15 ;
  cgc_size_t tlv13 ;
  int tlv18 ;
  cgc_size_t tlv16 ;
  unsigned int tlv19 ;
  unsigned int tlv20 ;

  {
  r = (int )(sizeof("\t\tNope, that\'s not a palindrome\n\n") - 1UL);
  tlv1 = (int )(sizeof("\t\tNope, that\'s not a palindrome\n\n") - 1UL);
  tlv7 = (int )(sizeof("\t\tNope, that\'s not a palindrome\n\n") - 1UL);
  tlv5 = sizeof("\t\tNope, that\'s not a palindrome\n\n") - 1UL;
  tlv2 = (int )(sizeof("\t\tNope, that\'s not a palindrome\n\n") - 1UL);
  tlv8 = (unsigned int )(sizeof("\t\tNope, that\'s not a palindrome\n\n") - 1UL);
  tlv11 = (int )(sizeof("\t\tNope, that\'s not a palindrome\n\n") - 1UL);
  tlv9 = sizeof("\t\tNope, that\'s not a palindrome\n\n") - 1UL;
  tlv12 = (unsigned int )(sizeof("\t\tNope, that\'s not a palindrome\n\n") - 1UL);
  tlv3 = (int )(sizeof("\t\tNope, that\'s not a palindrome\n\n") - 1UL);
  tlv4 = (int )(sizeof("\t\tNope, that\'s not a palindrome\n\n") - 1UL);
  tlv15 = (int )(sizeof("\t\tNope, that\'s not a palindrome\n\n") - 1UL);
  tlv13 = sizeof("\t\tNope, that\'s not a palindrome\n\n") - 1UL;
  tlv18 = (int )(sizeof("\t\tNope, that\'s not a palindrome\n\n") - 1UL);
  tlv16 = sizeof("\t\tNope, that\'s not a palindrome\n\n") - 1UL;
  tlv19 = (unsigned int )(sizeof("\t\tNope, that\'s not a palindrome\n\n") - 1UL);
  tlv20 = (unsigned int )(sizeof("\t\tNope, that\'s not a palindrome\n\n") - 1UL);
  return;
}
}
void fix_ingred_service_0_11(void) 
{ 


  {
  fix_ingred_service_0_11_1();
  return;
}
}
void fix_ingred_service_0_12_2(void) 
{ 
  int tlv3 ;
  int r ;
  int tlv1 ;
  int tlv7 ;
  cgc_size_t tlv5 ;
  int tlv2 ;
  unsigned int tlv8 ;
  int tlv11 ;
  cgc_size_t tlv9 ;
  unsigned int tlv12 ;
  int tlv4 ;
  int tlv15 ;
  cgc_size_t tlv13 ;
  int tlv18 ;
  cgc_size_t tlv16 ;
  unsigned int tlv19 ;
  unsigned int tlv20 ;

  {
  bzero(& tlv3, sizeof(int ));
  r = tlv3;
  tlv1 = tlv3;
  tlv7 = tlv3;
  tlv5 = (cgc_size_t )tlv3;
  tlv2 = tlv3;
  tlv8 = (unsigned int )tlv3;
  tlv11 = tlv3;
  tlv9 = (cgc_size_t )tlv3;
  tlv12 = (unsigned int )tlv3;
  tlv4 = tlv3;
  tlv15 = tlv3;
  tlv13 = (cgc_size_t )tlv3;
  tlv18 = tlv3;
  tlv16 = (cgc_size_t )tlv3;
  tlv19 = (unsigned int )tlv3;
  tlv20 = (unsigned int )tlv3;
  return;
}
}
void fix_ingred_service_0_12(void) 
{ 


  {
  fix_ingred_service_0_12_2();
  return;
}
}
void fix_ingred_service_0_15_1(void) 
{ 
  int r ;
  int tlv1 ;
  int tlv7 ;
  cgc_size_t tlv5 ;
  int tlv2 ;
  unsigned int tlv8 ;
  int tlv11 ;
  cgc_size_t tlv9 ;
  unsigned int tlv12 ;
  int tlv3 ;
  int tlv4 ;
  int tlv15 ;
  cgc_size_t tlv13 ;
  int tlv18 ;
  cgc_size_t tlv16 ;
  unsigned int tlv19 ;
  unsigned int tlv20 ;

  {
  r = (int )(sizeof("\t\tYes, that\'s a palindrome!\n\n") - 1UL);
  tlv1 = (int )(sizeof("\t\tYes, that\'s a palindrome!\n\n") - 1UL);
  tlv7 = (int )(sizeof("\t\tYes, that\'s a palindrome!\n\n") - 1UL);
  tlv5 = sizeof("\t\tYes, that\'s a palindrome!\n\n") - 1UL;
  tlv2 = (int )(sizeof("\t\tYes, that\'s a palindrome!\n\n") - 1UL);
  tlv8 = (unsigned int )(sizeof("\t\tYes, that\'s a palindrome!\n\n") - 1UL);
  tlv11 = (int )(sizeof("\t\tYes, that\'s a palindrome!\n\n") - 1UL);
  tlv9 = sizeof("\t\tYes, that\'s a palindrome!\n\n") - 1UL;
  tlv12 = (unsigned int )(sizeof("\t\tYes, that\'s a palindrome!\n\n") - 1UL);
  tlv3 = (int )(sizeof("\t\tYes, that\'s a palindrome!\n\n") - 1UL);
  tlv4 = (int )(sizeof("\t\tYes, that\'s a palindrome!\n\n") - 1UL);
  tlv15 = (int )(sizeof("\t\tYes, that\'s a palindrome!\n\n") - 1UL);
  tlv13 = sizeof("\t\tYes, that\'s a palindrome!\n\n") - 1UL;
  tlv18 = (int )(sizeof("\t\tYes, that\'s a palindrome!\n\n") - 1UL);
  tlv16 = sizeof("\t\tYes, that\'s a palindrome!\n\n") - 1UL;
  tlv19 = (unsigned int )(sizeof("\t\tYes, that\'s a palindrome!\n\n") - 1UL);
  tlv20 = (unsigned int )(sizeof("\t\tYes, that\'s a palindrome!\n\n") - 1UL);
  return;
}
}
void fix_ingred_service_0_15(void) 
{ 


  {
  fix_ingred_service_0_15_1();
  return;
}
}
void fix_ingred_service_0_16_0(void) 
{ 
  int tlv4 ;
  int r ;
  int tlv1 ;
  int tlv7 ;
  cgc_size_t tlv5 ;
  int tlv2 ;
  unsigned int tlv8 ;
  int tlv11 ;
  cgc_size_t tlv9 ;
  unsigned int tlv12 ;
  int tlv3 ;
  int tlv15 ;
  cgc_size_t tlv13 ;
  int tlv18 ;
  cgc_size_t tlv16 ;
  unsigned int tlv19 ;
  unsigned int tlv20 ;

  {
  bzero(& tlv4, sizeof(int ));
  r = tlv4;
  tlv1 = tlv4;
  tlv7 = tlv4;
  tlv5 = (cgc_size_t )tlv4;
  tlv2 = tlv4;
  tlv8 = (unsigned int )tlv4;
  tlv11 = tlv4;
  tlv9 = (cgc_size_t )tlv4;
  tlv12 = (unsigned int )tlv4;
  tlv3 = tlv4;
  tlv15 = tlv4;
  tlv13 = (cgc_size_t )tlv4;
  tlv18 = tlv4;
  tlv16 = (cgc_size_t )tlv4;
  tlv19 = (unsigned int )tlv4;
  tlv20 = (unsigned int )tlv4;
  return;
}
}
void fix_ingred_service_0_16(void) 
{ 


  {
  fix_ingred_service_0_16_0();
  return;
}
}
void fix_ingred_service_0(void) 
{ 


  {
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
  return;
}
}
void fix_ingred_service_1_0_0(void) 
{ 
  char string[64] ;
  int len ;
  int len___0 ;
  int i ;
  int pal ;
  char string___0[64] ;
  unsigned long tlv_size_0 ;
  int steps ;
  int tlv6 ;
  char *tlv5 ;
  cgc_size_t tlv4 ;
  char tlv3 ;
  int tlv9 ;
  cgc_size_t tlv7 ;
  unsigned int tlv10 ;

  {
  bzero(& string, 64UL * sizeof(char ));
  bzero(& len, sizeof(int ));
  len___0 = -1;
  i = -1;
  pal = -1;
  string___0[63] = (char)-1;
  tlv_size_0 = 0xffffffffffffffffUL;
  steps = -1;
  tlv6 = -1;
  tlv5 = (char *)-1;
  tlv4 = (cgc_size_t )-1;
  tlv3 = (char)-1;
  tlv9 = -1;
  tlv7 = (cgc_size_t )-1;
  tlv10 = 4294967295U;
  return;
}
}
void fix_ingred_service_1_0_1(void) 
{ 
  char string[64] ;
  int len ;
  int len___0 ;
  int i ;
  int pal ;
  char string___0[64] ;
  unsigned long tlv_size_0 ;
  int steps ;
  int tlv6 ;
  char *tlv5 ;
  cgc_size_t tlv4 ;
  char tlv3 ;
  int tlv9 ;
  cgc_size_t tlv7 ;
  unsigned int tlv10 ;

  {
  bzero(& string, 64UL * sizeof(char ));
  bzero(& len, sizeof(int ));
  len___0 = 1;
  i = 1;
  pal = 1;
  string___0[63] = (char)1;
  tlv_size_0 = 1UL;
  steps = 1;
  tlv6 = 1;
  tlv5 = (char *)1;
  tlv4 = (cgc_size_t )1;
  tlv3 = (char)1;
  tlv9 = 1;
  tlv7 = (cgc_size_t )1;
  tlv10 = 1U;
  return;
}
}
void fix_ingred_service_1_0_2(void) 
{ 
  char string[64] ;
  int len ;
  int len___0 ;
  int i ;
  int pal ;
  char string___0[64] ;
  unsigned long tlv_size_0 ;
  int tlv1 ;
  int steps ;
  int tlv6 ;
  char *tlv5 ;
  cgc_size_t tlv4 ;
  char tlv3 ;
  int tlv2 ;
  int tlv9 ;
  cgc_size_t tlv7 ;
  unsigned int tlv10 ;

  {
  bzero(& string, 64UL * sizeof(char ));
  bzero(& len, sizeof(int ));
  len___0 = (int )sizeof(string);
  i = (int )sizeof(string);
  pal = (int )sizeof(string);
  string___0[63] = (char )sizeof(string___0);
  tlv_size_0 = sizeof(string);
  tlv1 = (int )sizeof(string);
  steps = (int )sizeof(string);
  tlv6 = (int )sizeof(string);
  tlv5 = (char *)sizeof(string);
  tlv4 = sizeof(string);
  tlv3 = (char )sizeof(string);
  tlv2 = (int )sizeof(string);
  tlv9 = (int )sizeof(string);
  tlv7 = sizeof(string);
  tlv10 = (unsigned int )sizeof(string);
  return;
}
}
void fix_ingred_service_1_0_3(void) 
{ 
  char string[64] ;
  int len ;
  int i ;
  int pal ;
  char string___0[64] ;
  unsigned long tlv_size_0 ;
  int tlv1 ;
  int steps ;
  int tlv6 ;
  char *tlv5 ;
  cgc_size_t tlv4 ;
  char tlv3 ;
  int tlv2 ;
  int tlv9 ;
  cgc_size_t tlv7 ;
  unsigned int tlv10 ;

  {
  bzero(& string, 64UL * sizeof(char ));
  bzero(& len, sizeof(int ));
  i = len;
  pal = len;
  string___0[63] = (char )len;
  tlv_size_0 = (unsigned long )len;
  tlv1 = len;
  steps = len;
  tlv6 = len;
  tlv5 = (char *)len;
  tlv4 = (cgc_size_t )len;
  tlv3 = (char )len;
  tlv2 = len;
  tlv9 = len;
  tlv7 = (cgc_size_t )len;
  tlv10 = (unsigned int )len;
  return;
}
}
void fix_ingred_service_1_0(void) 
{ 


  {
  fix_ingred_service_1_0_0();
  fix_ingred_service_1_0_1();
  fix_ingred_service_1_0_2();
  fix_ingred_service_1_0_3();
  return;
}
}
void fix_ingred_service_1_1_4(void) 
{ 
  int i ;
  unsigned long tlv_size_0 ;
  int len ;
  int i___0 ;
  int pal ;
  char string[64] ;
  unsigned long tlv_size_0___0 ;
  int steps ;
  int tlv6 ;
  char *tlv5 ;
  cgc_size_t tlv4 ;
  char tlv3 ;
  int tlv9 ;
  cgc_size_t tlv7 ;
  unsigned int tlv10 ;

  {
  bzero(& i, sizeof(int ));
  bzero(& tlv_size_0, sizeof(unsigned long ));
  len = 0;
  i___0 = 0;
  pal = 0;
  string[63] = (char)0;
  tlv_size_0___0 = 0UL;
  steps = 0;
  tlv6 = 0;
  tlv5 = (char *)0;
  tlv4 = (cgc_size_t )0;
  tlv3 = (char)0;
  tlv9 = 0;
  tlv7 = (cgc_size_t )0;
  tlv10 = 0U;
  return;
}
}
void fix_ingred_service_1_1_5(void) 
{ 
  int i ;
  unsigned long tlv_size_0 ;
  int len ;
  int pal ;
  char string[64] ;
  unsigned long tlv_size_0___0 ;
  int tlv1 ;
  int steps ;
  int tlv6 ;
  char *tlv5 ;
  cgc_size_t tlv4 ;
  char tlv3 ;
  int tlv2 ;
  int tlv9 ;
  cgc_size_t tlv7 ;
  unsigned int tlv10 ;

  {
  bzero(& i, sizeof(int ));
  bzero(& tlv_size_0, sizeof(unsigned long ));
  len = i;
  pal = i;
  string[63] = (char )i;
  tlv_size_0___0 = (unsigned long )i;
  tlv1 = i;
  steps = i;
  tlv6 = i;
  tlv5 = (char *)i;
  tlv4 = (cgc_size_t )i;
  tlv3 = (char )i;
  tlv2 = i;
  tlv9 = i;
  tlv7 = (cgc_size_t )i;
  tlv10 = (unsigned int )i;
  return;
}
}
void fix_ingred_service_1_1_6(void) 
{ 
  int i ;
  unsigned long tlv_size_0 ;
  int len ;
  int i___0 ;
  int pal ;
  char string[64] ;
  int tlv1 ;
  int steps ;
  int tlv6 ;
  char *tlv5 ;
  cgc_size_t tlv4 ;
  char tlv3 ;
  int tlv2 ;
  int tlv9 ;
  cgc_size_t tlv7 ;
  unsigned int tlv10 ;

  {
  bzero(& i, sizeof(int ));
  bzero(& tlv_size_0, sizeof(unsigned long ));
  len = (int )tlv_size_0;
  i___0 = (int )tlv_size_0;
  pal = (int )tlv_size_0;
  string[63] = (char )tlv_size_0;
  tlv1 = (int )tlv_size_0;
  steps = (int )tlv_size_0;
  tlv6 = (int )tlv_size_0;
  tlv5 = (char *)tlv_size_0;
  tlv4 = tlv_size_0;
  tlv3 = (char )tlv_size_0;
  tlv2 = (int )tlv_size_0;
  tlv9 = (int )tlv_size_0;
  tlv7 = tlv_size_0;
  tlv10 = (unsigned int )tlv_size_0;
  return;
}
}
void fix_ingred_service_1_1(void) 
{ 


  {
  fix_ingred_service_1_1_4();
  fix_ingred_service_1_1_5();
  fix_ingred_service_1_1_6();
  return;
}
}
void fix_ingred_service_1_2_1(void) 
{ 
  char string[64] ;
  int len ;
  int i ;
  int pal ;
  char string___0[64] ;
  unsigned long tlv_size_0 ;
  int tlv1 ;
  int steps ;
  int tlv6 ;
  char *tlv5 ;
  cgc_size_t tlv4 ;
  char tlv3 ;
  int tlv2 ;
  int tlv9 ;
  cgc_size_t tlv7 ;
  unsigned int tlv10 ;

  {
  bzero(& string, 64UL * sizeof(char ));
  len = (int )(string);
  i = (int )(string);
  pal = (int )(string);
  string___0[63] = (char )(string___0);
  tlv_size_0 = (unsigned long )(string);
  tlv1 = (int )(string);
  steps = (int )(string);
  tlv6 = (int )(string);
  tlv5 = string;
  tlv4 = (cgc_size_t )(string);
  tlv3 = (char )(string);
  tlv2 = (int )(string);
  tlv9 = (int )(string);
  tlv7 = (cgc_size_t )(string);
  tlv10 = (unsigned int )(string);
  return;
}
}
void fix_ingred_service_1_2_2(void) 
{ 
  char string[64] ;
  int len ;
  int i ;
  int pal ;
  char string___0[64] ;
  unsigned long tlv_size_0 ;
  int tlv1 ;
  int steps ;
  int tlv6 ;
  char *tlv5 ;
  cgc_size_t tlv4 ;
  char tlv3 ;
  int tlv2 ;
  int tlv9 ;
  cgc_size_t tlv7 ;
  unsigned int tlv10 ;

  {
  bzero(& string, 64UL * sizeof(char ));
  len = 128;
  i = 128;
  pal = 128;
  string___0[63] = (char)-128;
  tlv_size_0 = 128UL;
  tlv1 = 128;
  steps = 128;
  tlv6 = 128;
  tlv5 = (char *)128;
  tlv4 = (cgc_size_t )128;
  tlv3 = (char)-128;
  tlv2 = 128;
  tlv9 = 128;
  tlv7 = (cgc_size_t )128;
  tlv10 = 128U;
  return;
}
}
void fix_ingred_service_1_2_3(void) 
{ 
  char string[64] ;
  int len ;
  int i ;
  int pal ;
  char string___0[64] ;
  unsigned long tlv_size_0 ;
  int tlv1 ;
  int steps ;
  int tlv6 ;
  char *tlv5 ;
  cgc_size_t tlv4 ;
  char tlv3 ;
  int tlv2 ;
  int tlv9 ;
  cgc_size_t tlv7 ;
  unsigned int tlv10 ;

  {
  bzero(& string, 64UL * sizeof(char ));
  len = '\n';
  i = '\n';
  pal = '\n';
  string___0[63] = (char )'\n';
  tlv_size_0 = (unsigned long )'\n';
  tlv1 = '\n';
  steps = '\n';
  tlv6 = '\n';
  tlv5 = (char *)'\n';
  tlv4 = (cgc_size_t )'\n';
  tlv3 = (char )'\n';
  tlv2 = '\n';
  tlv9 = '\n';
  tlv7 = (cgc_size_t )'\n';
  tlv10 = (unsigned int )'\n';
  return;
}
}
void fix_ingred_service_1_2(void) 
{ 


  {
  fix_ingred_service_1_2_1();
  fix_ingred_service_1_2_2();
  fix_ingred_service_1_2_3();
  return;
}
}
void fix_ingred_service_1_3_3(void) 
{ 
  int tlv1 ;
  int len ;
  int i ;
  int pal ;
  char string[64] ;
  unsigned long tlv_size_0 ;
  int steps ;
  int tlv6 ;
  char *tlv5 ;
  cgc_size_t tlv4 ;
  char tlv3 ;
  int tlv9 ;
  cgc_size_t tlv7 ;
  unsigned int tlv10 ;

  {
  bzero(& tlv1, sizeof(int ));
  len = tlv1;
  i = tlv1;
  pal = tlv1;
  string[63] = (char )tlv1;
  tlv_size_0 = (unsigned long )tlv1;
  steps = tlv1;
  tlv6 = tlv1;
  tlv5 = (char *)tlv1;
  tlv4 = (cgc_size_t )tlv1;
  tlv3 = (char )tlv1;
  tlv9 = tlv1;
  tlv7 = (cgc_size_t )tlv1;
  tlv10 = (unsigned int )tlv1;
  return;
}
}
void fix_ingred_service_1_3(void) 
{ 


  {
  fix_ingred_service_1_3_3();
  return;
}
}
void fix_ingred_service_1_4_4(void) 
{ 
  char string[64] ;
  int i ;
  int len ;
  int pal ;
  char string___0[64] ;
  unsigned long tlv_size_0 ;
  int tlv1 ;
  int steps ;
  int tlv6 ;
  char *tlv5 ;
  cgc_size_t tlv4 ;
  char tlv3 ;
  int tlv2 ;
  int tlv9 ;
  cgc_size_t tlv7 ;
  unsigned int tlv10 ;

  {
  bzero(& string, 64UL * sizeof(char ));
  bzero(& i, sizeof(int ));
  if (string) {
    i = 0;
    len = (int )string[i];
  } else {

  }
  if (string) {
    i = 0;
    pal = (int )string[i];
  } else {

  }
  if (string) {
    i = 0;
    string___0[63] = string___0[i];
  } else {

  }
  if (string) {
    i = 0;
    tlv_size_0 = (unsigned long )string[i];
  } else {

  }
  if (string) {
    i = 0;
    tlv1 = (int )string[i];
  } else {

  }
  if (string) {
    i = 0;
    steps = (int )string[i];
  } else {

  }
  if (string) {
    i = 0;
    tlv6 = (int )string[i];
  } else {

  }
  if (string) {
    i = 0;
    tlv5 = (char *)string[i];
  } else {

  }
  if (string) {
    i = 0;
    tlv4 = (cgc_size_t )string[i];
  } else {

  }
  if (string) {
    i = 0;
    tlv3 = string[i];
  } else {

  }
  if (string) {
    i = 0;
    tlv2 = (int )string[i];
  } else {

  }
  if (string) {
    i = 0;
    tlv9 = (int )string[i];
  } else {

  }
  if (string) {
    i = 0;
    tlv7 = (cgc_size_t )string[i];
  } else {

  }
  if (string) {
    i = 0;
    tlv10 = (unsigned int )string[i];
  } else {

  }
  return;
}
}
void fix_ingred_service_1_4_5(void) 
{ 
  char string[64] ;
  int i ;
  int len ;
  int i___0 ;
  int pal ;
  char string___0[64] ;
  unsigned long tlv_size_0 ;
  int tlv1 ;
  int steps ;
  int tlv6 ;
  char *tlv5 ;
  cgc_size_t tlv4 ;
  char tlv3 ;
  int tlv2 ;
  int tlv9 ;
  cgc_size_t tlv7 ;
  unsigned int tlv10 ;

  {
  bzero(& string, 64UL * sizeof(char ));
  bzero(& i, sizeof(int ));
  len = '\000';
  i___0 = '\000';
  pal = '\000';
  string___0[63] = (char )'\000';
  tlv_size_0 = (unsigned long )'\000';
  tlv1 = '\000';
  steps = '\000';
  tlv6 = '\000';
  tlv5 = (char *)'\000';
  tlv4 = (cgc_size_t )'\000';
  tlv3 = (char )'\000';
  tlv2 = '\000';
  tlv9 = '\000';
  tlv7 = (cgc_size_t )'\000';
  tlv10 = (unsigned int )'\000';
  return;
}
}
void fix_ingred_service_1_4(void) 
{ 


  {
  fix_ingred_service_1_4_4();
  fix_ingred_service_1_4_5();
  return;
}
}
void fix_ingred_service_1_8_4(void) 
{ 
  char string[64] ;
  int len ;
  int i ;
  int pal ;
  char string___0[64] ;
  unsigned long tlv_size_0 ;
  int tlv1 ;
  int steps ;
  int tlv6 ;
  char *tlv5 ;
  cgc_size_t tlv4 ;
  char tlv3 ;
  int tlv2 ;
  int tlv9 ;
  cgc_size_t tlv7 ;
  unsigned int tlv10 ;

  {
  bzero(& string, 64UL * sizeof(char ));
  if (string) {
    len = (int )string[0];
  } else {

  }
  if (string) {
    i = (int )string[0];
  } else {

  }
  if (string) {
    pal = (int )string[0];
  } else {

  }
  if (string) {
    string___0[63] = string___0[0];
  } else {

  }
  if (string) {
    tlv_size_0 = (unsigned long )string[0];
  } else {

  }
  if (string) {
    tlv1 = (int )string[0];
  } else {

  }
  if (string) {
    steps = (int )string[0];
  } else {

  }
  if (string) {
    tlv6 = (int )string[0];
  } else {

  }
  if (string) {
    tlv5 = (char *)string[0];
  } else {

  }
  if (string) {
    tlv4 = (cgc_size_t )string[0];
  } else {

  }
  if (string) {
    tlv3 = string[0];
  } else {

  }
  if (string) {
    tlv2 = (int )string[0];
  } else {

  }
  if (string) {
    tlv9 = (int )string[0];
  } else {

  }
  if (string) {
    tlv7 = (cgc_size_t )string[0];
  } else {

  }
  if (string) {
    tlv10 = (unsigned int )string[0];
  } else {

  }
  return;
}
}
void fix_ingred_service_1_8_5(void) 
{ 
  char string[64] ;
  int len ;
  int i ;
  int pal ;
  char string___0[64] ;
  unsigned long tlv_size_0 ;
  int tlv1 ;
  int steps ;
  int tlv6 ;
  char *tlv5 ;
  cgc_size_t tlv4 ;
  char tlv3 ;
  int tlv2 ;
  int tlv9 ;
  cgc_size_t tlv7 ;
  unsigned int tlv10 ;

  {
  bzero(& string, 64UL * sizeof(char ));
  len = '^';
  i = '^';
  pal = '^';
  string___0[63] = (char )'^';
  tlv_size_0 = (unsigned long )'^';
  tlv1 = '^';
  steps = '^';
  tlv6 = '^';
  tlv5 = (char *)'^';
  tlv4 = (cgc_size_t )'^';
  tlv3 = (char )'^';
  tlv2 = '^';
  tlv9 = '^';
  tlv7 = (cgc_size_t )'^';
  tlv10 = (unsigned int )'^';
  return;
}
}
void fix_ingred_service_1_8(void) 
{ 


  {
  fix_ingred_service_1_8_4();
  fix_ingred_service_1_8_5();
  return;
}
}
void fix_ingred_service_1_9_1(void) 
{ 
  int len ;
  int i ;
  int pal ;
  char string[64] ;
  unsigned long tlv_size_0 ;
  int tlv1 ;
  int steps ;
  int tlv6 ;
  char *tlv5 ;
  cgc_size_t tlv4 ;
  char tlv3 ;
  int tlv2 ;
  int tlv9 ;
  cgc_size_t tlv7 ;
  unsigned int tlv10 ;

  {
  len = (int )(sizeof("\n\nEASTER EGG!\n\n") - 1UL);
  i = (int )(sizeof("\n\nEASTER EGG!\n\n") - 1UL);
  pal = (int )(sizeof("\n\nEASTER EGG!\n\n") - 1UL);
  string[63] = (char )(sizeof("\n\nEASTER EGG!\n\n") - 1UL);
  tlv_size_0 = sizeof("\n\nEASTER EGG!\n\n") - 1UL;
  tlv1 = (int )(sizeof("\n\nEASTER EGG!\n\n") - 1UL);
  steps = (int )(sizeof("\n\nEASTER EGG!\n\n") - 1UL);
  tlv6 = (int )(sizeof("\n\nEASTER EGG!\n\n") - 1UL);
  tlv5 = (char *)(sizeof("\n\nEASTER EGG!\n\n") - 1UL);
  tlv4 = sizeof("\n\nEASTER EGG!\n\n") - 1UL;
  tlv3 = (char )(sizeof("\n\nEASTER EGG!\n\n") - 1UL);
  tlv2 = (int )(sizeof("\n\nEASTER EGG!\n\n") - 1UL);
  tlv9 = (int )(sizeof("\n\nEASTER EGG!\n\n") - 1UL);
  tlv7 = sizeof("\n\nEASTER EGG!\n\n") - 1UL;
  tlv10 = (unsigned int )(sizeof("\n\nEASTER EGG!\n\n") - 1UL);
  return;
}
}
void fix_ingred_service_1_9(void) 
{ 


  {
  fix_ingred_service_1_9_1();
  return;
}
}
void fix_ingred_service_1_10_6(void) 
{ 
  int tlv2 ;
  int len ;
  int i ;
  int pal ;
  char string[64] ;
  unsigned long tlv_size_0 ;
  int steps ;
  int tlv6 ;
  char *tlv5 ;
  cgc_size_t tlv4 ;
  char tlv3 ;
  int tlv9 ;
  cgc_size_t tlv7 ;
  unsigned int tlv10 ;

  {
  bzero(& tlv2, sizeof(int ));
  len = tlv2;
  i = tlv2;
  pal = tlv2;
  string[63] = (char )tlv2;
  tlv_size_0 = (unsigned long )tlv2;
  steps = tlv2;
  tlv6 = tlv2;
  tlv5 = (char *)tlv2;
  tlv4 = (cgc_size_t )tlv2;
  tlv3 = (char )tlv2;
  tlv9 = tlv2;
  tlv7 = (cgc_size_t )tlv2;
  tlv10 = (unsigned int )tlv2;
  return;
}
}
void fix_ingred_service_1_10(void) 
{ 


  {
  fix_ingred_service_1_10_6();
  return;
}
}
void fix_ingred_service_1_11_0(void) 
{ 
  int len ;
  int i ;
  int pal ;
  char string[64] ;
  unsigned long tlv_size_0 ;
  int steps ;
  int tlv6 ;
  char *tlv5 ;
  cgc_size_t tlv4 ;
  char tlv3 ;
  int tlv9 ;
  cgc_size_t tlv7 ;
  unsigned int tlv10 ;

  {
  len = 0;
  i = 0;
  pal = 0;
  string[63] = (char)0;
  tlv_size_0 = 0UL;
  steps = 0;
  tlv6 = 0;
  tlv5 = (char *)0;
  tlv4 = (cgc_size_t )0;
  tlv3 = (char)0;
  tlv9 = 0;
  tlv7 = (cgc_size_t )0;
  tlv10 = 0U;
  return;
}
}
void fix_ingred_service_1_11(void) 
{ 


  {
  fix_ingred_service_1_11_0();
  return;
}
}
void fix_ingred_service_1(void) 
{ 


  {
  fix_ingred_service_1_0();
  fix_ingred_service_1_1();
  fix_ingred_service_1_2();
  fix_ingred_service_1_3();
  fix_ingred_service_1_4();
  fix_ingred_service_1_8();
  fix_ingred_service_1_9();
  fix_ingred_service_1_10();
  fix_ingred_service_1_11();
  return;
}
}
