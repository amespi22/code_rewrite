# 1 "/home/pdreiter/Data/APR_eval/GenProg/v25.cb_eval/On_Sale.base.ga/On_Sale/src/On_Sale/src/inventory.c"
# 1 "/home/pdreiter/Data/APR_eval/GenProg/v25.cb_eval/On_Sale.base.ga/On_Sale/build/On_Sale//"
# 1 "<built-in>"
#define __STDC__ 1
#define __STDC_VERSION__ 199901L
#define __STDC_UTF_16__ 1
#define __STDC_UTF_32__ 1
#define __STDC_HOSTED__ 1
#define __GNUC__ 8
#define __GNUC_MINOR__ 4
#define __GNUC_PATCHLEVEL__ 0
#define __VERSION__ "8.4.0"
#define __ATOMIC_RELAXED 0
#define __ATOMIC_SEQ_CST 5
#define __ATOMIC_ACQUIRE 2
#define __ATOMIC_RELEASE 3
#define __ATOMIC_ACQ_REL 4
#define __ATOMIC_CONSUME 1
#define __pic__ 2
#define __PIC__ 2
#define __pie__ 2
#define __PIE__ 2
#define __FINITE_MATH_ONLY__ 0
#define __SIZEOF_INT__ 4
#define __SIZEOF_LONG__ 4
#define __SIZEOF_LONG_LONG__ 8
#define __SIZEOF_SHORT__ 2
#define __SIZEOF_FLOAT__ 4
#define __SIZEOF_DOUBLE__ 8
#define __SIZEOF_LONG_DOUBLE__ 12
#define __SIZEOF_SIZE_T__ 4
#define __CHAR_BIT__ 8
#define __BIGGEST_ALIGNMENT__ 16
#define __ORDER_LITTLE_ENDIAN__ 1234
#define __ORDER_BIG_ENDIAN__ 4321
#define __ORDER_PDP_ENDIAN__ 3412
#define __BYTE_ORDER__ __ORDER_LITTLE_ENDIAN__
#define __FLOAT_WORD_ORDER__ __ORDER_LITTLE_ENDIAN__
#define __SIZEOF_POINTER__ 4
#define __SIZE_TYPE__ unsigned int
#define __PTRDIFF_TYPE__ int
#define __WCHAR_TYPE__ long int
#define __WINT_TYPE__ unsigned int
#define __INTMAX_TYPE__ long long int
#define __UINTMAX_TYPE__ long long unsigned int
#define __CHAR16_TYPE__ short unsigned int
#define __CHAR32_TYPE__ unsigned int
#define __SIG_ATOMIC_TYPE__ int
#define __INT8_TYPE__ signed char
#define __INT16_TYPE__ short int
#define __INT32_TYPE__ int
#define __INT64_TYPE__ long long int
#define __UINT8_TYPE__ unsigned char
#define __UINT16_TYPE__ short unsigned int
#define __UINT32_TYPE__ unsigned int
#define __UINT64_TYPE__ long long unsigned int
#define __INT_LEAST8_TYPE__ signed char
#define __INT_LEAST16_TYPE__ short int
#define __INT_LEAST32_TYPE__ int
#define __INT_LEAST64_TYPE__ long long int
#define __UINT_LEAST8_TYPE__ unsigned char
#define __UINT_LEAST16_TYPE__ short unsigned int
#define __UINT_LEAST32_TYPE__ unsigned int
#define __UINT_LEAST64_TYPE__ long long unsigned int
#define __INT_FAST8_TYPE__ signed char
#define __INT_FAST16_TYPE__ int
#define __INT_FAST32_TYPE__ int
#define __INT_FAST64_TYPE__ long long int
#define __UINT_FAST8_TYPE__ unsigned char
#define __UINT_FAST16_TYPE__ unsigned int
#define __UINT_FAST32_TYPE__ unsigned int
#define __UINT_FAST64_TYPE__ long long unsigned int
#define __INTPTR_TYPE__ int
#define __UINTPTR_TYPE__ unsigned int
#define __has_include(STR) __has_include__(STR)
#define __has_include_next(STR) __has_include_next__(STR)
#define __GXX_ABI_VERSION 1013
#define __SCHAR_MAX__ 0x7f
#define __SHRT_MAX__ 0x7fff
#define __INT_MAX__ 0x7fffffff
#define __LONG_MAX__ 0x7fffffffL
#define __LONG_LONG_MAX__ 0x7fffffffffffffffLL
#define __WCHAR_MAX__ 0x7fffffffL
#define __WCHAR_MIN__ (-__WCHAR_MAX__ - 1)
#define __WINT_MAX__ 0xffffffffU
#define __WINT_MIN__ 0U
#define __PTRDIFF_MAX__ 0x7fffffff
#define __SIZE_MAX__ 0xffffffffU
#define __SCHAR_WIDTH__ 8
#define __SHRT_WIDTH__ 16
#define __INT_WIDTH__ 32
#define __LONG_WIDTH__ 32
#define __LONG_LONG_WIDTH__ 64
#define __WCHAR_WIDTH__ 32
#define __WINT_WIDTH__ 32
#define __PTRDIFF_WIDTH__ 32
#define __SIZE_WIDTH__ 32
#define __INTMAX_MAX__ 0x7fffffffffffffffLL
#define __INTMAX_C(c) c ## LL
#define __UINTMAX_MAX__ 0xffffffffffffffffULL
#define __UINTMAX_C(c) c ## ULL
#define __INTMAX_WIDTH__ 64
#define __SIG_ATOMIC_MAX__ 0x7fffffff
#define __SIG_ATOMIC_MIN__ (-__SIG_ATOMIC_MAX__ - 1)
#define __SIG_ATOMIC_WIDTH__ 32
#define __INT8_MAX__ 0x7f
#define __INT16_MAX__ 0x7fff
#define __INT32_MAX__ 0x7fffffff
#define __INT64_MAX__ 0x7fffffffffffffffLL
#define __UINT8_MAX__ 0xff
#define __UINT16_MAX__ 0xffff
#define __UINT32_MAX__ 0xffffffffU
#define __UINT64_MAX__ 0xffffffffffffffffULL
#define __INT_LEAST8_MAX__ 0x7f
#define __INT8_C(c) c
#define __INT_LEAST8_WIDTH__ 8
#define __INT_LEAST16_MAX__ 0x7fff
#define __INT16_C(c) c
#define __INT_LEAST16_WIDTH__ 16
#define __INT_LEAST32_MAX__ 0x7fffffff
#define __INT32_C(c) c
#define __INT_LEAST32_WIDTH__ 32
#define __INT_LEAST64_MAX__ 0x7fffffffffffffffLL
#define __INT64_C(c) c ## LL
#define __INT_LEAST64_WIDTH__ 64
#define __UINT_LEAST8_MAX__ 0xff
#define __UINT8_C(c) c
#define __UINT_LEAST16_MAX__ 0xffff
#define __UINT16_C(c) c
#define __UINT_LEAST32_MAX__ 0xffffffffU
#define __UINT32_C(c) c ## U
#define __UINT_LEAST64_MAX__ 0xffffffffffffffffULL
#define __UINT64_C(c) c ## ULL
#define __INT_FAST8_MAX__ 0x7f
#define __INT_FAST8_WIDTH__ 8
#define __INT_FAST16_MAX__ 0x7fffffff
#define __INT_FAST16_WIDTH__ 32
#define __INT_FAST32_MAX__ 0x7fffffff
#define __INT_FAST32_WIDTH__ 32
#define __INT_FAST64_MAX__ 0x7fffffffffffffffLL
#define __INT_FAST64_WIDTH__ 64
#define __UINT_FAST8_MAX__ 0xff
#define __UINT_FAST16_MAX__ 0xffffffffU
#define __UINT_FAST32_MAX__ 0xffffffffU
#define __UINT_FAST64_MAX__ 0xffffffffffffffffULL
#define __INTPTR_MAX__ 0x7fffffff
#define __INTPTR_WIDTH__ 32
#define __UINTPTR_MAX__ 0xffffffffU
#define __GCC_IEC_559 2
#define __GCC_IEC_559_COMPLEX 2
#define __FLT_EVAL_METHOD__ 2
#define __FLT_EVAL_METHOD_TS_18661_3__ 2
#define __DEC_EVAL_METHOD__ 2
#define __FLT_RADIX__ 2
#define __FLT_MANT_DIG__ 24
#define __FLT_DIG__ 6
#define __FLT_MIN_EXP__ (-125)
#define __FLT_MIN_10_EXP__ (-37)
#define __FLT_MAX_EXP__ 128
#define __FLT_MAX_10_EXP__ 38
#define __FLT_DECIMAL_DIG__ 9
#define __FLT_MAX__ 3.40282346638528859811704183484516925e+38F
#define __FLT_MIN__ 1.17549435082228750796873653722224568e-38F
#define __FLT_EPSILON__ 1.19209289550781250000000000000000000e-7F
#define __FLT_DENORM_MIN__ 1.40129846432481707092372958328991613e-45F
#define __FLT_HAS_DENORM__ 1
#define __FLT_HAS_INFINITY__ 1
#define __FLT_HAS_QUIET_NAN__ 1
#define __DBL_MANT_DIG__ 53
#define __DBL_DIG__ 15
#define __DBL_MIN_EXP__ (-1021)
#define __DBL_MIN_10_EXP__ (-307)
#define __DBL_MAX_EXP__ 1024
#define __DBL_MAX_10_EXP__ 308
#define __DBL_DECIMAL_DIG__ 17
#define __DBL_MAX__ ((double)1.79769313486231570814527423731704357e+308L)
#define __DBL_MIN__ ((double)2.22507385850720138309023271733240406e-308L)
#define __DBL_EPSILON__ ((double)2.22044604925031308084726333618164062e-16L)
#define __DBL_DENORM_MIN__ ((double)4.94065645841246544176568792868221372e-324L)
#define __DBL_HAS_DENORM__ 1
#define __DBL_HAS_INFINITY__ 1
#define __DBL_HAS_QUIET_NAN__ 1
#define __LDBL_MANT_DIG__ 64
#define __LDBL_DIG__ 18
#define __LDBL_MIN_EXP__ (-16381)
#define __LDBL_MIN_10_EXP__ (-4931)
#define __LDBL_MAX_EXP__ 16384
#define __LDBL_MAX_10_EXP__ 4932
#define __DECIMAL_DIG__ 21
#define __LDBL_DECIMAL_DIG__ 21
#define __LDBL_MAX__ 1.18973149535723176502126385303097021e+4932L
#define __LDBL_MIN__ 3.36210314311209350626267781732175260e-4932L
#define __LDBL_EPSILON__ 1.08420217248550443400745280086994171e-19L
#define __LDBL_DENORM_MIN__ 3.64519953188247460252840593361941982e-4951L
#define __LDBL_HAS_DENORM__ 1
#define __LDBL_HAS_INFINITY__ 1
#define __LDBL_HAS_QUIET_NAN__ 1
#define __FLT32_MANT_DIG__ 24
#define __FLT32_DIG__ 6
#define __FLT32_MIN_EXP__ (-125)
#define __FLT32_MIN_10_EXP__ (-37)
#define __FLT32_MAX_EXP__ 128
#define __FLT32_MAX_10_EXP__ 38
#define __FLT32_DECIMAL_DIG__ 9
#define __FLT32_MAX__ 3.40282346638528859811704183484516925e+38F32
#define __FLT32_MIN__ 1.17549435082228750796873653722224568e-38F32
#define __FLT32_EPSILON__ 1.19209289550781250000000000000000000e-7F32
#define __FLT32_DENORM_MIN__ 1.40129846432481707092372958328991613e-45F32
#define __FLT32_HAS_DENORM__ 1
#define __FLT32_HAS_INFINITY__ 1
#define __FLT32_HAS_QUIET_NAN__ 1
#define __FLT64_MANT_DIG__ 53
#define __FLT64_DIG__ 15
#define __FLT64_MIN_EXP__ (-1021)
#define __FLT64_MIN_10_EXP__ (-307)
#define __FLT64_MAX_EXP__ 1024
#define __FLT64_MAX_10_EXP__ 308
#define __FLT64_DECIMAL_DIG__ 17
#define __FLT64_MAX__ 1.79769313486231570814527423731704357e+308F64
#define __FLT64_MIN__ 2.22507385850720138309023271733240406e-308F64
#define __FLT64_EPSILON__ 2.22044604925031308084726333618164062e-16F64
#define __FLT64_DENORM_MIN__ 4.94065645841246544176568792868221372e-324F64
#define __FLT64_HAS_DENORM__ 1
#define __FLT64_HAS_INFINITY__ 1
#define __FLT64_HAS_QUIET_NAN__ 1
#define __FLT128_MANT_DIG__ 113
#define __FLT128_DIG__ 33
#define __FLT128_MIN_EXP__ (-16381)
#define __FLT128_MIN_10_EXP__ (-4931)
#define __FLT128_MAX_EXP__ 16384
#define __FLT128_MAX_10_EXP__ 4932
#define __FLT128_DECIMAL_DIG__ 36
#define __FLT128_MAX__ 1.18973149535723176508575932662800702e+4932F128
#define __FLT128_MIN__ 3.36210314311209350626267781732175260e-4932F128
#define __FLT128_EPSILON__ 1.92592994438723585305597794258492732e-34F128
#define __FLT128_DENORM_MIN__ 6.47517511943802511092443895822764655e-4966F128
#define __FLT128_HAS_DENORM__ 1
#define __FLT128_HAS_INFINITY__ 1
#define __FLT128_HAS_QUIET_NAN__ 1
#define __FLT32X_MANT_DIG__ 53
#define __FLT32X_DIG__ 15
#define __FLT32X_MIN_EXP__ (-1021)
#define __FLT32X_MIN_10_EXP__ (-307)
#define __FLT32X_MAX_EXP__ 1024
#define __FLT32X_MAX_10_EXP__ 308
#define __FLT32X_DECIMAL_DIG__ 17
#define __FLT32X_MAX__ 1.79769313486231570814527423731704357e+308F32x
#define __FLT32X_MIN__ 2.22507385850720138309023271733240406e-308F32x
#define __FLT32X_EPSILON__ 2.22044604925031308084726333618164062e-16F32x
#define __FLT32X_DENORM_MIN__ 4.94065645841246544176568792868221372e-324F32x
#define __FLT32X_HAS_DENORM__ 1
#define __FLT32X_HAS_INFINITY__ 1
#define __FLT32X_HAS_QUIET_NAN__ 1
#define __FLT64X_MANT_DIG__ 64
#define __FLT64X_DIG__ 18
#define __FLT64X_MIN_EXP__ (-16381)
#define __FLT64X_MIN_10_EXP__ (-4931)
#define __FLT64X_MAX_EXP__ 16384
#define __FLT64X_MAX_10_EXP__ 4932
#define __FLT64X_DECIMAL_DIG__ 21
#define __FLT64X_MAX__ 1.18973149535723176502126385303097021e+4932F64x
#define __FLT64X_MIN__ 3.36210314311209350626267781732175260e-4932F64x
#define __FLT64X_EPSILON__ 1.08420217248550443400745280086994171e-19F64x
#define __FLT64X_DENORM_MIN__ 3.64519953188247460252840593361941982e-4951F64x
#define __FLT64X_HAS_DENORM__ 1
#define __FLT64X_HAS_INFINITY__ 1
#define __FLT64X_HAS_QUIET_NAN__ 1
#define __DEC32_MANT_DIG__ 7
#define __DEC32_MIN_EXP__ (-94)
#define __DEC32_MAX_EXP__ 97
#define __DEC32_MIN__ 1E-95DF
#define __DEC32_MAX__ 9.999999E96DF
#define __DEC32_EPSILON__ 1E-6DF
#define __DEC32_SUBNORMAL_MIN__ 0.000001E-95DF
#define __DEC64_MANT_DIG__ 16
#define __DEC64_MIN_EXP__ (-382)
#define __DEC64_MAX_EXP__ 385
#define __DEC64_MIN__ 1E-383DD
#define __DEC64_MAX__ 9.999999999999999E384DD
#define __DEC64_EPSILON__ 1E-15DD
#define __DEC64_SUBNORMAL_MIN__ 0.000000000000001E-383DD
#define __DEC128_MANT_DIG__ 34
#define __DEC128_MIN_EXP__ (-6142)
#define __DEC128_MAX_EXP__ 6145
#define __DEC128_MIN__ 1E-6143DL
#define __DEC128_MAX__ 9.999999999999999999999999999999999E6144DL
#define __DEC128_EPSILON__ 1E-33DL
#define __DEC128_SUBNORMAL_MIN__ 0.000000000000000000000000000000001E-6143DL
#define __REGISTER_PREFIX__ 
#define __USER_LABEL_PREFIX__ 
#define __GNUC_STDC_INLINE__ 1
#define __NO_INLINE__ 1
#define __GCC_HAVE_SYNC_COMPARE_AND_SWAP_1 1
#define __GCC_HAVE_SYNC_COMPARE_AND_SWAP_2 1
#define __GCC_HAVE_SYNC_COMPARE_AND_SWAP_4 1
#define __GCC_HAVE_SYNC_COMPARE_AND_SWAP_8 1
#define __GCC_ATOMIC_BOOL_LOCK_FREE 2
#define __GCC_ATOMIC_CHAR_LOCK_FREE 2
#define __GCC_ATOMIC_CHAR16_T_LOCK_FREE 2
#define __GCC_ATOMIC_CHAR32_T_LOCK_FREE 2
#define __GCC_ATOMIC_WCHAR_T_LOCK_FREE 2
#define __GCC_ATOMIC_SHORT_LOCK_FREE 2
#define __GCC_ATOMIC_INT_LOCK_FREE 2
#define __GCC_ATOMIC_LONG_LOCK_FREE 2
#define __GCC_ATOMIC_LLONG_LOCK_FREE 2
#define __GCC_ATOMIC_TEST_AND_SET_TRUEVAL 1
#define __GCC_ATOMIC_POINTER_LOCK_FREE 2
#define __GCC_HAVE_DWARF2_CFI_ASM 1
#define __PRAGMA_REDEFINE_EXTNAME 1
#define __SIZEOF_WCHAR_T__ 4
#define __SIZEOF_WINT_T__ 4
#define __SIZEOF_PTRDIFF_T__ 4
#define __i386 1
#define __i386__ 1
#define i386 1
#define __SIZEOF_FLOAT80__ 12
#define __SIZEOF_FLOAT128__ 16
#define __ATOMIC_HLE_ACQUIRE 65536
#define __ATOMIC_HLE_RELEASE 131072
#define __GCC_ASM_FLAG_OUTPUTS__ 1
#define __i686 1
#define __i686__ 1
#define __pentiumpro 1
#define __pentiumpro__ 1
#define __code_model_32__ 1
#define __SEG_FS 1
#define __SEG_GS 1
#define __gnu_linux__ 1
#define __linux 1
#define __linux__ 1
#define linux 1
#define __unix 1
#define __unix__ 1
#define unix 1
#define __ELF__ 1
#define __DECIMAL_BID_FORMAT__ 1
# 1 "<command-line>"
#define FORTIFY_SOURCE 0
#define LINUX 1
#define NPATCHED 1
#define errno __cgc_errno
# 1 "/usr/include/stdc-predef.h" 1 3 4
# 19 "/usr/include/stdc-predef.h" 3 4
#define _STDC_PREDEF_H 1
# 38 "/usr/include/stdc-predef.h" 3 4
#define __STDC_IEC_559__ 1







#define __STDC_IEC_559_COMPLEX__ 1
# 58 "/usr/include/stdc-predef.h" 3 4
#define __STDC_ISO_10646__ 201706L


#define __STDC_NO_THREADS__ 1
# 1 "<command-line>" 2
# 1 "/home/pdreiter/Data/APR_eval/GenProg/v25.cb_eval/On_Sale.base.ga/On_Sale/src/On_Sale/src/inventory.c"
# 22 "/home/pdreiter/Data/APR_eval/GenProg/v25.cb_eval/On_Sale.base.ga/On_Sale/src/On_Sale/src/inventory.c"
# 1 "/home/pdreiter/Data/APR_eval/GenProg/v25.cb_eval/On_Sale.base.ga/On_Sale/src/include/libcgc.h" 1

#define _LIBCGC_H 

#define STDIN 0
#define STDOUT 1
#define STDERR 2




#define NULL (0)







typedef unsigned long cgc_size_t;
typedef long cgc_ssize_t;





#define STD_SIZE_T unsigned int



#define PAGE_SIZE 4096



#define CGC_FLAG_PAGE_ADDRESS 0x4347C000



#define offsetof(TYPE,MEMBER) __builtin_offsetof (TYPE, MEMBER)



#define SSIZE_MAX ((cgc_ssize_t)((~((cgc_size_t)0ULL))>>1))



#define SIZE_MAX (~((cgc_size_t)0ULL))


#define CGC_FD_SETSIZE 1024

typedef long int _fd_mask;

#define CGC__NFDBITS (8 * sizeof(_fd_mask))

typedef struct {
    _fd_mask _fd_bits[1024 / (8 * sizeof(_fd_mask))];
} cgc_fd_set;

#define CGC_FD_ZERO(set) do { int __i; for (__i = 0; __i < (CGC_FD_SETSIZE / CGC__NFDBITS); __i++) (set)->_fd_bits[__i] = 0; } while (0)






#define CGC_FD_SET(b,set) ((set)->_fd_bits[b / CGC__NFDBITS] |= (1 << (b & (CGC__NFDBITS - 1))))


#define CGC_FD_CLR(b,set) ((set)->_fd_bits[b / CGC__NFDBITS] &= ~(1 << (b & (CGC__NFDBITS - 1))))


#define CGC_FD_ISSET(b,set) ((set)->_fd_bits[b / CGC__NFDBITS] & (1 << (b & (CGC__NFDBITS - 1))))


struct cgc_timeval {
    int tv_sec;
    int tv_usec;
};

#define CGC_EBADF 1
#define CGC_EFAULT 2
#define CGC_EINVAL 3
#define CGC_ENOMEM 4
#define CGC_ENOSYS 5
#define CGC_EPIPE 6


#define FD_SETSIZE CGC_FD_SETSIZE
#define _NFDBITS CGC__NFDBITS
#define FD_ZERO CGC_FD_ZERO
#define FD_SET CGC_FD_SET
#define FD_CLR CGC_FD_CLR
#define FD_ISSET CGC_FD_ISSET

#define EBADF CGC_EBADF
#define EFAULT CGC_EFAULT
#define EINVAL CGC_EINVAL
#define ENOMEM CGC_ENOMEM
#define ENOSYS CGC_ENOSYS
#define EPIPE CGC_EPIPE
# 122 "/home/pdreiter/Data/APR_eval/GenProg/v25.cb_eval/On_Sale.base.ga/On_Sale/src/include/libcgc.h"
void cgc__terminate(unsigned int status) __attribute__((__noreturn__));
int cgc_transmit(int fd, const void *buf, cgc_size_t count, cgc_size_t *tx_bytes);
int cgc_receive(int fd, void *buf, cgc_size_t count, cgc_size_t *rx_bytes);
int cgc_fdwait(int nfds, cgc_fd_set *readfds, cgc_fd_set *writefds,
               const struct cgc_timeval *timeout, int *readyfds);
int cgc_allocate(cgc_size_t length, int is_X, void **addr);
int cgc_deallocate(void *addr, cgc_size_t length);
int cgc_random(void *buf, cgc_size_t count, cgc_size_t *rnd_bytes);



typedef struct { long _b[8]; } jmp_buf[1];
extern int cgc_setjmp(jmp_buf) __attribute__((__returns_twice__));
extern void cgc_longjmp(jmp_buf, int) __attribute__((__noreturn__));

extern float cgc_sinf(float); extern double cgc_sin(double); extern long double cgc_sinl(long double);
extern float cgc_cosf(float); extern double cgc_cos(double); extern long double cgc_cosl(long double);
extern float cgc_tanf(float); extern double cgc_tan(double); extern long double cgc_tanl(long double);
extern float cgc_logf(float); extern double cgc_log(double); extern long double cgc_logl(long double);
extern float cgc_rintf(float); extern double cgc_rint(double); extern long double cgc_rintl(long double);
extern float cgc_sqrtf(float); extern double cgc_sqrt(double); extern long double cgc_sqrtl(long double);
extern float cgc_fabsf(float); extern double cgc_fabs(double); extern long double cgc_fabsl(long double);
extern float cgc_log2f(float); extern double cgc_log2(double); extern long double cgc_log2l(long double);
extern float cgc_exp2f(float); extern double cgc_exp2(double); extern long double cgc_exp2l(long double);
extern float cgc_expf(float); extern double cgc_exp(double); extern long double cgc_expl(long double);
extern float cgc_log10f(float); extern double cgc_log10(double); extern long double cgc_log10l(long double);

extern float cgc_powf(float, float);
extern double cgc_pow(double, double);
extern long double cgc_powl(long double, long double);
extern float cgc_atan2f(float, float);
extern double cgc_atan2(double, double);
extern long double cgc_atan2l(long double, long double);
extern float cgc_remainderf(float, float);
extern double cgc_remainder(double, double);
extern long double cgc_remainderl(long double, long double);
extern float cgc_scalbnf(float, int);
extern double cgc_scalbn(double, int);
extern long double cgc_scalbnl(long double, int);
extern float cgc_scalblnf(float, long int);
extern double cgc_scalbln(double, long int);
extern long double cgc_scalblnl(long double, long int);
extern float cgc_significandf(float);
extern double cgc_significand(double);
extern long double cgc_significandl(long double);
# 23 "/home/pdreiter/Data/APR_eval/GenProg/v25.cb_eval/On_Sale.base.ga/On_Sale/src/On_Sale/src/inventory.c" 2
# 1 "/home/pdreiter/Data/APR_eval/GenProg/v25.cb_eval/On_Sale.base.ga/On_Sale/src/On_Sale/include/cgc_stdint.h" 1
# 24 "/home/pdreiter/Data/APR_eval/GenProg/v25.cb_eval/On_Sale.base.ga/On_Sale/src/On_Sale/include/cgc_stdint.h"
#define STDINT_H 1



#define INT_MAX (2147483647)

#define INT_MIN (-2147483647 - 1)

#define UINT_MAX (4294967295)

#define UINT_MIN (0)

#define FALSE 0
#define TRUE 1

#define SUCCESS 0
# 24 "/home/pdreiter/Data/APR_eval/GenProg/v25.cb_eval/On_Sale.base.ga/On_Sale/src/On_Sale/src/inventory.c" 2
# 1 "/home/pdreiter/Data/APR_eval/GenProg/v25.cb_eval/On_Sale.base.ga/On_Sale/src/On_Sale/lib/cgc_libc.h" 1
# 22 "/home/pdreiter/Data/APR_eval/GenProg/v25.cb_eval/On_Sale.base.ga/On_Sale/src/On_Sale/lib/cgc_libc.h"
       

# 1 "/home/pdreiter/Data/APR_eval/GenProg/v25.cb_eval/On_Sale.base.ga/On_Sale/src/On_Sale/include/cgc_errno.h" 1
# 24 "/home/pdreiter/Data/APR_eval/GenProg/v25.cb_eval/On_Sale.base.ga/On_Sale/src/On_Sale/include/cgc_errno.h"
#define ERRNO_H 1

#define ERRNO_ALLOC -7
#define ERRNO_SEND -9
#define ERRNO_RECV -11
#define ERRNO_RAND -13
#define ERRNO_HASH -14
#define ERRNO_CONV -15
#define ERRNO_COPY -17
# 25 "/home/pdreiter/Data/APR_eval/GenProg/v25.cb_eval/On_Sale.base.ga/On_Sale/src/On_Sale/lib/cgc_libc.h" 2

# 1 "/home/pdreiter/Data/APR_eval/GenProg/v25.cb_eval/On_Sale.base.ga/On_Sale/src/On_Sale/lib/cgc_recv_bytes.h" 1
# 23 "/home/pdreiter/Data/APR_eval/GenProg/v25.cb_eval/On_Sale.base.ga/On_Sale/src/On_Sale/lib/cgc_recv_bytes.h"
       
# 33 "/home/pdreiter/Data/APR_eval/GenProg/v25.cb_eval/On_Sale.base.ga/On_Sale/src/On_Sale/lib/cgc_recv_bytes.h"
int cgc_recv_bytes(int fd, char *buf, unsigned int size);
# 27 "/home/pdreiter/Data/APR_eval/GenProg/v25.cb_eval/On_Sale.base.ga/On_Sale/src/On_Sale/lib/cgc_libc.h" 2
# 1 "/home/pdreiter/Data/APR_eval/GenProg/v25.cb_eval/On_Sale.base.ga/On_Sale/src/On_Sale/lib/cgc_send_bytes.h" 1
# 24 "/home/pdreiter/Data/APR_eval/GenProg/v25.cb_eval/On_Sale.base.ga/On_Sale/src/On_Sale/lib/cgc_send_bytes.h"
#define SEND_BYTES_H 1
# 35 "/home/pdreiter/Data/APR_eval/GenProg/v25.cb_eval/On_Sale.base.ga/On_Sale/src/On_Sale/lib/cgc_send_bytes.h"
int cgc_send_bytes(int fd, const char *buf, unsigned int size);
# 28 "/home/pdreiter/Data/APR_eval/GenProg/v25.cb_eval/On_Sale.base.ga/On_Sale/src/On_Sale/lib/cgc_libc.h" 2



#define MY_ID 0


#define READ_FD MY_ID






#define FLAG_PAGE 0x4347C000

#define SEND(f,b,s) if(s != cgc_send_bytes(f,b,s)) cgc__terminate(ERRNO_SEND)

#define RECV(f,b,s) if(0 > cgc_recv_bytes(f,b,s)) cgc__terminate(ERRNO_RECV)

#define FAIL_BAIL_RET(e) if (SUCCESS != (ret = e)) return ret;
#define NEG_BAIL_RET(e) if (0 > (ret = e)) return ret
#define MALLOC_OK(p) if (NULL == p) cgc__terminate(ERRNO_ALLOC)
# 25 "/home/pdreiter/Data/APR_eval/GenProg/v25.cb_eval/On_Sale.base.ga/On_Sale/src/On_Sale/src/inventory.c" 2
# 1 "/home/pdreiter/Data/APR_eval/GenProg/v25.cb_eval/On_Sale.base.ga/On_Sale/src/On_Sale/lib/cgc_memcpy.h" 1
# 24 "/home/pdreiter/Data/APR_eval/GenProg/v25.cb_eval/On_Sale.base.ga/On_Sale/src/On_Sale/lib/cgc_memcpy.h"
#define MEMCPY_H 1
# 34 "/home/pdreiter/Data/APR_eval/GenProg/v25.cb_eval/On_Sale.base.ga/On_Sale/src/On_Sale/lib/cgc_memcpy.h"
unsigned int cgc_memcpy(void *dst, const void *src, unsigned int cnt);
# 26 "/home/pdreiter/Data/APR_eval/GenProg/v25.cb_eval/On_Sale.base.ga/On_Sale/src/On_Sale/src/inventory.c" 2
# 1 "/home/pdreiter/Data/APR_eval/GenProg/v25.cb_eval/On_Sale.base.ga/On_Sale/src/On_Sale/lib/cgc_memset.h" 1
# 25 "/home/pdreiter/Data/APR_eval/GenProg/v25.cb_eval/On_Sale.base.ga/On_Sale/src/On_Sale/lib/cgc_memset.h"
#define MEMSET_H 1
# 35 "/home/pdreiter/Data/APR_eval/GenProg/v25.cb_eval/On_Sale.base.ga/On_Sale/src/On_Sale/lib/cgc_memset.h"
unsigned int cgc_memset(void *buf, unsigned char ch, unsigned int n);
# 27 "/home/pdreiter/Data/APR_eval/GenProg/v25.cb_eval/On_Sale.base.ga/On_Sale/src/On_Sale/src/inventory.c" 2
# 1 "/home/pdreiter/Data/APR_eval/GenProg/v25.cb_eval/On_Sale.base.ga/On_Sale/src/On_Sale/lib/cgc_list.h" 1
# 24 "/home/pdreiter/Data/APR_eval/GenProg/v25.cb_eval/On_Sale.base.ga/On_Sale/src/On_Sale/lib/cgc_list.h"
#define LIST_H 1
# 39 "/home/pdreiter/Data/APR_eval/GenProg/v25.cb_eval/On_Sale.base.ga/On_Sale/src/On_Sale/lib/cgc_list.h"
typedef void (*nodeDataFreeFn)(void *);

struct node {
 void *data;
 struct node *next;
 struct node *prev;
};

struct list {
 unsigned int length;
 struct node dummy;
 nodeDataFreeFn ndf;
};







struct node *cgc_list_create_node(void *data);
# 68 "/home/pdreiter/Data/APR_eval/GenProg/v25.cb_eval/On_Sale.base.ga/On_Sale/src/On_Sale/lib/cgc_list.h"
void cgc_list_destroy_node(struct list *l, struct node **n);







void cgc_list_init(struct list *l, nodeDataFreeFn ndf);






void cgc_list_destroy(struct list *l);







void cgc_list_insert_before_node(struct node *existing, struct node *new);







void cgc_list_insert_after_node(struct node *existing, struct node *new);







void cgc_list_insert_node_at_end(struct list *l, struct node *new);







void cgc_list_insert_at_end(struct list *l, void *d);







void cgc_list_insert_node_at_start(struct list *l, struct node *new);







void cgc_list_insert_at_start(struct list *l, void *d);
# 141 "/home/pdreiter/Data/APR_eval/GenProg/v25.cb_eval/On_Sale.base.ga/On_Sale/src/On_Sale/lib/cgc_list.h"
void cgc_list_insert_node_sorted(struct list *l, struct node *new, unsigned char (*predFn)(const void *, void *), unsigned char desc);
# 151 "/home/pdreiter/Data/APR_eval/GenProg/v25.cb_eval/On_Sale.base.ga/On_Sale/src/On_Sale/lib/cgc_list.h"
void cgc_list_insert_sorted(struct list *l, void *d, unsigned char (*predFn)(const void *, void *), unsigned char desc);







struct node *cgc_list_pop(struct list *l);







void cgc_list_remove_node(struct list *l, struct node *n);







struct node *cgc_list_head_node(struct list *l);







struct node *cgc_list_tail_node(struct list *l);







struct node *cgc_list_next_node(struct node *cur_node);







struct node *cgc_list_start_marker(struct list *l);







struct node *cgc_list_end_marker(struct list *l);







unsigned int cgc_list_length(struct list *l);
# 225 "/home/pdreiter/Data/APR_eval/GenProg/v25.cb_eval/On_Sale.base.ga/On_Sale/src/On_Sale/lib/cgc_list.h"
struct node *cgc_list_find_node_with_data(struct list *l, unsigned char (*predFn)(const void *, void *), void *data);
# 28 "/home/pdreiter/Data/APR_eval/GenProg/v25.cb_eval/On_Sale.base.ga/On_Sale/src/On_Sale/src/inventory.c" 2
# 1 "/home/pdreiter/Data/APR_eval/GenProg/v25.cb_eval/On_Sale.base.ga/On_Sale/src/On_Sale/lib/cgc_malloc.h" 1
# 23 "/home/pdreiter/Data/APR_eval/GenProg/v25.cb_eval/On_Sale.base.ga/On_Sale/src/On_Sale/lib/cgc_malloc.h"
#define MALLOC_H 1



#define PAGE_SZ 4096
# 36 "/home/pdreiter/Data/APR_eval/GenProg/v25.cb_eval/On_Sale.base.ga/On_Sale/src/On_Sale/lib/cgc_malloc.h"
void *cgc_malloc(cgc_size_t size);
# 46 "/home/pdreiter/Data/APR_eval/GenProg/v25.cb_eval/On_Sale.base.ga/On_Sale/src/On_Sale/lib/cgc_malloc.h"
void cgc_free(void *ptr);
# 29 "/home/pdreiter/Data/APR_eval/GenProg/v25.cb_eval/On_Sale.base.ga/On_Sale/src/On_Sale/src/inventory.c" 2
# 1 "/home/pdreiter/Data/APR_eval/GenProg/v25.cb_eval/On_Sale.base.ga/On_Sale/src/On_Sale/lib/cgc_string.h" 1
# 24 "/home/pdreiter/Data/APR_eval/GenProg/v25.cb_eval/On_Sale.base.ga/On_Sale/src/On_Sale/lib/cgc_string.h"
#define STRING_H 1
# 35 "/home/pdreiter/Data/APR_eval/GenProg/v25.cb_eval/On_Sale.base.ga/On_Sale/src/On_Sale/lib/cgc_string.h"
int cgc_streq(const char* str1, const char* str2, const char term);
# 45 "/home/pdreiter/Data/APR_eval/GenProg/v25.cb_eval/On_Sale.base.ga/On_Sale/src/On_Sale/lib/cgc_string.h"
int cgc_strcmp(const char* str1, const char* str2, const char term);
# 54 "/home/pdreiter/Data/APR_eval/GenProg/v25.cb_eval/On_Sale.base.ga/On_Sale/src/On_Sale/lib/cgc_string.h"
unsigned int cgc_strlen(const char *str, const char term);
# 30 "/home/pdreiter/Data/APR_eval/GenProg/v25.cb_eval/On_Sale.base.ga/On_Sale/src/On_Sale/src/inventory.c" 2

# 1 "/home/pdreiter/Data/APR_eval/GenProg/v25.cb_eval/On_Sale.base.ga/On_Sale/src/On_Sale/src/cgc_products.h" 1
# 24 "/home/pdreiter/Data/APR_eval/GenProg/v25.cb_eval/On_Sale.base.ga/On_Sale/src/On_Sale/src/cgc_products.h"
#define PRODUCTS_H 1

#define MAX_DESC_LEN 128
#define BARCODE_SZ 8

typedef float __attribute__((regparm(2))) (*sale_fn)(unsigned int, float);

typedef struct {
 unsigned char barcode[8];
 char desc[128];
 unsigned int model_num;
 float cost;
 sale_fn sfn;
 unsigned int update_serial;
} Product;





void cgc_setup(void);






short cgc_process_cmd(void);
# 32 "/home/pdreiter/Data/APR_eval/GenProg/v25.cb_eval/On_Sale.base.ga/On_Sale/src/On_Sale/src/inventory.c" 2
# 1 "/home/pdreiter/Data/APR_eval/GenProg/v25.cb_eval/On_Sale.base.ga/On_Sale/src/On_Sale/src/cgc_inventory.h" 1
# 24 "/home/pdreiter/Data/APR_eval/GenProg/v25.cb_eval/On_Sale.base.ga/On_Sale/src/On_Sale/src/cgc_inventory.h"
#define INVENTORY_H 1

typedef struct list Inventory;

void cgc_load_inventory(Inventory *inv);
# 33 "/home/pdreiter/Data/APR_eval/GenProg/v25.cb_eval/On_Sale.base.ga/On_Sale/src/On_Sale/src/inventory.c" 2
# 1 "/home/pdreiter/Data/APR_eval/GenProg/v25.cb_eval/On_Sale.base.ga/On_Sale/src/On_Sale/src/cgc_sale.h" 1
# 24 "/home/pdreiter/Data/APR_eval/GenProg/v25.cb_eval/On_Sale.base.ga/On_Sale/src/On_Sale/src/cgc_sale.h"
#define SALE_H 1

float __attribute__((regparm(2))) (*onsale_fn[101])(unsigned int model_num, float cost);
# 34 "/home/pdreiter/Data/APR_eval/GenProg/v25.cb_eval/On_Sale.base.ga/On_Sale/src/On_Sale/src/inventory.c" 2

void cgc_load_inventory(Inventory *inv) {
    Product *p = (0);
    const char *b = (0);
    const char *d = (0);


    p = cgc_malloc(sizeof(Product));
    if ((0) == p) cgc__terminate(-7);
    cgc_memset(p, '\0', sizeof(Product));

    b = "41916155";
    d = "CBoXdTVlxY";
    cgc_memcpy(p->barcode, b, cgc_strlen(b, '\0'));
    cgc_memcpy(p->desc, d, cgc_strlen(d, '\0'));
    p->model_num = 59889;
    p->cost = 0.17;
    p->sfn = onsale_fn[0];
    p->update_serial = 0;

    cgc_list_insert_at_end(inv, p);


    p = cgc_malloc(sizeof(Product));
    if ((0) == p) cgc__terminate(-7);
    cgc_memset(p, '\0', sizeof(Product));

    b = "12099137";
    d = "BURcRQvrJKLoWsuIu";
    cgc_memcpy(p->barcode, b, cgc_strlen(b, '\0'));
    cgc_memcpy(p->desc, d, cgc_strlen(d, '\0'));
    p->model_num = 1128;
    p->cost = 5.87;
    p->sfn = onsale_fn[0];
    p->update_serial = 0;

    cgc_list_insert_at_end(inv, p);


    p = cgc_malloc(sizeof(Product));
    if ((0) == p) cgc__terminate(-7);
    cgc_memset(p, '\0', sizeof(Product));

    b = "86848322";
    d = "OuYFqLLPzpStQmLGNfrdmNBtqESEZPD";
    cgc_memcpy(p->barcode, b, cgc_strlen(b, '\0'));
    cgc_memcpy(p->desc, d, cgc_strlen(d, '\0'));
    p->model_num = 64101;
    p->cost = 2.54;
    p->sfn = onsale_fn[0];
    p->update_serial = 0;

    cgc_list_insert_at_end(inv, p);


    p = cgc_malloc(sizeof(Product));
    if ((0) == p) cgc__terminate(-7);
    cgc_memset(p, '\0', sizeof(Product));

    b = "87849215";
    d = "osjXtGjM";
    cgc_memcpy(p->barcode, b, cgc_strlen(b, '\0'));
    cgc_memcpy(p->desc, d, cgc_strlen(d, '\0'));
    p->model_num = 46035;
    p->cost = 4.37;
    p->sfn = onsale_fn[0];
    p->update_serial = 0;

    cgc_list_insert_at_end(inv, p);


    p = cgc_malloc(sizeof(Product));
    if ((0) == p) cgc__terminate(-7);
    cgc_memset(p, '\0', sizeof(Product));

    b = "50361802";
    d = "WaALSqUGTUcRRQbrpD";
    cgc_memcpy(p->barcode, b, cgc_strlen(b, '\0'));
    cgc_memcpy(p->desc, d, cgc_strlen(d, '\0'));
    p->model_num = 12881;
    p->cost = 5.64;
    p->sfn = onsale_fn[0];
    p->update_serial = 0;

    cgc_list_insert_at_end(inv, p);


    p = cgc_malloc(sizeof(Product));
    if ((0) == p) cgc__terminate(-7);
    cgc_memset(p, '\0', sizeof(Product));

    b = "28433101";
    d = "UeC";
    cgc_memcpy(p->barcode, b, cgc_strlen(b, '\0'));
    cgc_memcpy(p->desc, d, cgc_strlen(d, '\0'));
    p->model_num = 31708;
    p->cost = 7.28;
    p->sfn = onsale_fn[0];
    p->update_serial = 0;

    cgc_list_insert_at_end(inv, p);


    p = cgc_malloc(sizeof(Product));
    if ((0) == p) cgc__terminate(-7);
    cgc_memset(p, '\0', sizeof(Product));

    b = "12220539";
    d = "lbYe";
    cgc_memcpy(p->barcode, b, cgc_strlen(b, '\0'));
    cgc_memcpy(p->desc, d, cgc_strlen(d, '\0'));
    p->model_num = 23198;
    p->cost = 5.34;
    p->sfn = onsale_fn[0];
    p->update_serial = 0;

    cgc_list_insert_at_end(inv, p);


    p = cgc_malloc(sizeof(Product));
    if ((0) == p) cgc__terminate(-7);
    cgc_memset(p, '\0', sizeof(Product));

    b = "47111925";
    d = "MxLyPsRDfZNyZCZyPiFcO";
    cgc_memcpy(p->barcode, b, cgc_strlen(b, '\0'));
    cgc_memcpy(p->desc, d, cgc_strlen(d, '\0'));
    p->model_num = 31486;
    p->cost = 1.1;
    p->sfn = onsale_fn[0];
    p->update_serial = 0;

    cgc_list_insert_at_end(inv, p);


    p = cgc_malloc(sizeof(Product));
    if ((0) == p) cgc__terminate(-7);
    cgc_memset(p, '\0', sizeof(Product));

    b = "00664810";
    d = "WBsFTZeoBiL";
    cgc_memcpy(p->barcode, b, cgc_strlen(b, '\0'));
    cgc_memcpy(p->desc, d, cgc_strlen(d, '\0'));
    p->model_num = 27300;
    p->cost = 4.89;
    p->sfn = onsale_fn[0];
    p->update_serial = 0;

    cgc_list_insert_at_end(inv, p);


    p = cgc_malloc(sizeof(Product));
    if ((0) == p) cgc__terminate(-7);
    cgc_memset(p, '\0', sizeof(Product));

    b = "94282841";
    d = "CiyXLti";
    cgc_memcpy(p->barcode, b, cgc_strlen(b, '\0'));
    cgc_memcpy(p->desc, d, cgc_strlen(d, '\0'));
    p->model_num = 10630;
    p->cost = 1.09;
    p->sfn = onsale_fn[0];
    p->update_serial = 0;

    cgc_list_insert_at_end(inv, p);


    p = cgc_malloc(sizeof(Product));
    if ((0) == p) cgc__terminate(-7);
    cgc_memset(p, '\0', sizeof(Product));

    b = "72291601";
    d = "RJOT";
    cgc_memcpy(p->barcode, b, cgc_strlen(b, '\0'));
    cgc_memcpy(p->desc, d, cgc_strlen(d, '\0'));
    p->model_num = 50229;
    p->cost = 5.77;
    p->sfn = onsale_fn[0];
    p->update_serial = 0;

    cgc_list_insert_at_end(inv, p);


    p = cgc_malloc(sizeof(Product));
    if ((0) == p) cgc__terminate(-7);
    cgc_memset(p, '\0', sizeof(Product));

    b = "49840365";
    d = "LrmPNlODBcMuDdejSrklcnEJbCdJOA";
    cgc_memcpy(p->barcode, b, cgc_strlen(b, '\0'));
    cgc_memcpy(p->desc, d, cgc_strlen(d, '\0'));
    p->model_num = 45345;
    p->cost = 5.19;
    p->sfn = onsale_fn[0];
    p->update_serial = 0;

    cgc_list_insert_at_end(inv, p);


    p = cgc_malloc(sizeof(Product));
    if ((0) == p) cgc__terminate(-7);
    cgc_memset(p, '\0', sizeof(Product));

    b = "50717007";
    d = "OcYEZmPsrGyvcbxflxxamqLlLJ";
    cgc_memcpy(p->barcode, b, cgc_strlen(b, '\0'));
    cgc_memcpy(p->desc, d, cgc_strlen(d, '\0'));
    p->model_num = 60011;
    p->cost = 2.57;
    p->sfn = onsale_fn[0];
    p->update_serial = 0;

    cgc_list_insert_at_end(inv, p);


    p = cgc_malloc(sizeof(Product));
    if ((0) == p) cgc__terminate(-7);
    cgc_memset(p, '\0', sizeof(Product));

    b = "99964712";
    d = "NcVIOJwRguXBwKdEwzx";
    cgc_memcpy(p->barcode, b, cgc_strlen(b, '\0'));
    cgc_memcpy(p->desc, d, cgc_strlen(d, '\0'));
    p->model_num = 116;
    p->cost = 6.68;
    p->sfn = onsale_fn[0];
    p->update_serial = 0;

    cgc_list_insert_at_end(inv, p);


    p = cgc_malloc(sizeof(Product));
    if ((0) == p) cgc__terminate(-7);
    cgc_memset(p, '\0', sizeof(Product));

    b = "13706532";
    d = "SmMpCSxZTsPtsDwZprYJIBYtCczZ";
    cgc_memcpy(p->barcode, b, cgc_strlen(b, '\0'));
    cgc_memcpy(p->desc, d, cgc_strlen(d, '\0'));
    p->model_num = 39806;
    p->cost = 7.33;
    p->sfn = onsale_fn[0];
    p->update_serial = 0;

    cgc_list_insert_at_end(inv, p);


    p = cgc_malloc(sizeof(Product));
    if ((0) == p) cgc__terminate(-7);
    cgc_memset(p, '\0', sizeof(Product));

    b = "44381534";
    d = "mfuSPgiZIaaPTtfMKuYWPqW";
    cgc_memcpy(p->barcode, b, cgc_strlen(b, '\0'));
    cgc_memcpy(p->desc, d, cgc_strlen(d, '\0'));
    p->model_num = 30120;
    p->cost = 4.71;
    p->sfn = onsale_fn[0];
    p->update_serial = 0;

    cgc_list_insert_at_end(inv, p);


    p = cgc_malloc(sizeof(Product));
    if ((0) == p) cgc__terminate(-7);
    cgc_memset(p, '\0', sizeof(Product));

    b = "66900952";
    d = "dLuOlZFcVURjFo";
    cgc_memcpy(p->barcode, b, cgc_strlen(b, '\0'));
    cgc_memcpy(p->desc, d, cgc_strlen(d, '\0'));
    p->model_num = 14927;
    p->cost = 3.05;
    p->sfn = onsale_fn[0];
    p->update_serial = 0;

    cgc_list_insert_at_end(inv, p);


    p = cgc_malloc(sizeof(Product));
    if ((0) == p) cgc__terminate(-7);
    cgc_memset(p, '\0', sizeof(Product));

    b = "74926350";
    d = "cXK";
    cgc_memcpy(p->barcode, b, cgc_strlen(b, '\0'));
    cgc_memcpy(p->desc, d, cgc_strlen(d, '\0'));
    p->model_num = 2472;
    p->cost = 3.89;
    p->sfn = onsale_fn[0];
    p->update_serial = 0;

    cgc_list_insert_at_end(inv, p);


    p = cgc_malloc(sizeof(Product));
    if ((0) == p) cgc__terminate(-7);
    cgc_memset(p, '\0', sizeof(Product));

    b = "31951871";
    d = "gZOISWZizsGWxfIV";
    cgc_memcpy(p->barcode, b, cgc_strlen(b, '\0'));
    cgc_memcpy(p->desc, d, cgc_strlen(d, '\0'));
    p->model_num = 25650;
    p->cost = 2.72;
    p->sfn = onsale_fn[0];
    p->update_serial = 0;

    cgc_list_insert_at_end(inv, p);


    p = cgc_malloc(sizeof(Product));
    if ((0) == p) cgc__terminate(-7);
    cgc_memset(p, '\0', sizeof(Product));

    b = "20585072";
    d = "OVNnctOCWjcIXOvxXwZdeYk";
    cgc_memcpy(p->barcode, b, cgc_strlen(b, '\0'));
    cgc_memcpy(p->desc, d, cgc_strlen(d, '\0'));
    p->model_num = 33445;
    p->cost = 3.71;
    p->sfn = onsale_fn[0];
    p->update_serial = 0;

    cgc_list_insert_at_end(inv, p);


    p = cgc_malloc(sizeof(Product));
    if ((0) == p) cgc__terminate(-7);
    cgc_memset(p, '\0', sizeof(Product));

    b = "29987528";
    d = "bQemYYbkbgRlHzYhddLTXBV";
    cgc_memcpy(p->barcode, b, cgc_strlen(b, '\0'));
    cgc_memcpy(p->desc, d, cgc_strlen(d, '\0'));
    p->model_num = 63850;
    p->cost = 8.27;
    p->sfn = onsale_fn[0];
    p->update_serial = 0;

    cgc_list_insert_at_end(inv, p);


    p = cgc_malloc(sizeof(Product));
    if ((0) == p) cgc__terminate(-7);
    cgc_memset(p, '\0', sizeof(Product));

    b = "44567831";
    d = "bVxVzqJoMAbbABpuK";
    cgc_memcpy(p->barcode, b, cgc_strlen(b, '\0'));
    cgc_memcpy(p->desc, d, cgc_strlen(d, '\0'));
    p->model_num = 10273;
    p->cost = 1.29;
    p->sfn = onsale_fn[0];
    p->update_serial = 0;

    cgc_list_insert_at_end(inv, p);


    p = cgc_malloc(sizeof(Product));
    if ((0) == p) cgc__terminate(-7);
    cgc_memset(p, '\0', sizeof(Product));

    b = "50044195";
    d = "TIwQNAxBYeidFJgiuiceKyyZOo";
    cgc_memcpy(p->barcode, b, cgc_strlen(b, '\0'));
    cgc_memcpy(p->desc, d, cgc_strlen(d, '\0'));
    p->model_num = 64340;
    p->cost = 6.58;
    p->sfn = onsale_fn[0];
    p->update_serial = 0;

    cgc_list_insert_at_end(inv, p);


    p = cgc_malloc(sizeof(Product));
    if ((0) == p) cgc__terminate(-7);
    cgc_memset(p, '\0', sizeof(Product));

    b = "80320569";
    d = "ZbOKiKsPtSLZUXGSgVuVvEg";
    cgc_memcpy(p->barcode, b, cgc_strlen(b, '\0'));
    cgc_memcpy(p->desc, d, cgc_strlen(d, '\0'));
    p->model_num = 3226;
    p->cost = 8.54;
    p->sfn = onsale_fn[0];
    p->update_serial = 0;

    cgc_list_insert_at_end(inv, p);


    p = cgc_malloc(sizeof(Product));
    if ((0) == p) cgc__terminate(-7);
    cgc_memset(p, '\0', sizeof(Product));

    b = "12555125";
    d = "OOBHIukxWBXTujZouCmy";
    cgc_memcpy(p->barcode, b, cgc_strlen(b, '\0'));
    cgc_memcpy(p->desc, d, cgc_strlen(d, '\0'));
    p->model_num = 48316;
    p->cost = 1.52;
    p->sfn = onsale_fn[0];
    p->update_serial = 0;

    cgc_list_insert_at_end(inv, p);


    p = cgc_malloc(sizeof(Product));
    if ((0) == p) cgc__terminate(-7);
    cgc_memset(p, '\0', sizeof(Product));

    b = "77475676";
    d = "TkFFmsuzuD";
    cgc_memcpy(p->barcode, b, cgc_strlen(b, '\0'));
    cgc_memcpy(p->desc, d, cgc_strlen(d, '\0'));
    p->model_num = 12910;
    p->cost = 8.68;
    p->sfn = onsale_fn[0];
    p->update_serial = 0;

    cgc_list_insert_at_end(inv, p);


    p = cgc_malloc(sizeof(Product));
    if ((0) == p) cgc__terminate(-7);
    cgc_memset(p, '\0', sizeof(Product));

    b = "68500061";
    d = "xXKivnPyFeKjDSsLIcHJkcfDZr";
    cgc_memcpy(p->barcode, b, cgc_strlen(b, '\0'));
    cgc_memcpy(p->desc, d, cgc_strlen(d, '\0'));
    p->model_num = 25325;
    p->cost = 5.73;
    p->sfn = onsale_fn[0];
    p->update_serial = 0;

    cgc_list_insert_at_end(inv, p);


    p = cgc_malloc(sizeof(Product));
    if ((0) == p) cgc__terminate(-7);
    cgc_memset(p, '\0', sizeof(Product));

    b = "28801547";
    d = "zPzfWrYgkzusXM";
    cgc_memcpy(p->barcode, b, cgc_strlen(b, '\0'));
    cgc_memcpy(p->desc, d, cgc_strlen(d, '\0'));
    p->model_num = 55098;
    p->cost = 3.69;
    p->sfn = onsale_fn[0];
    p->update_serial = 0;

    cgc_list_insert_at_end(inv, p);


    p = cgc_malloc(sizeof(Product));
    if ((0) == p) cgc__terminate(-7);
    cgc_memset(p, '\0', sizeof(Product));

    b = "27286316";
    d = "iaOSmHodjClBbsmNMxMUjFEEBw";
    cgc_memcpy(p->barcode, b, cgc_strlen(b, '\0'));
    cgc_memcpy(p->desc, d, cgc_strlen(d, '\0'));
    p->model_num = 45201;
    p->cost = 6.05;
    p->sfn = onsale_fn[0];
    p->update_serial = 0;

    cgc_list_insert_at_end(inv, p);


    p = cgc_malloc(sizeof(Product));
    if ((0) == p) cgc__terminate(-7);
    cgc_memset(p, '\0', sizeof(Product));

    b = "06744775";
    d = "RZaRMCR";
    cgc_memcpy(p->barcode, b, cgc_strlen(b, '\0'));
    cgc_memcpy(p->desc, d, cgc_strlen(d, '\0'));
    p->model_num = 39161;
    p->cost = 10.0;
    p->sfn = onsale_fn[0];
    p->update_serial = 0;

    cgc_list_insert_at_end(inv, p);


    p = cgc_malloc(sizeof(Product));
    if ((0) == p) cgc__terminate(-7);
    cgc_memset(p, '\0', sizeof(Product));

    b = "14976063";
    d = "lXkSGfmjnIcJrqjzuwaLpNVsxCoeZla";
    cgc_memcpy(p->barcode, b, cgc_strlen(b, '\0'));
    cgc_memcpy(p->desc, d, cgc_strlen(d, '\0'));
    p->model_num = 58432;
    p->cost = 5.36;
    p->sfn = onsale_fn[0];
    p->update_serial = 0;

    cgc_list_insert_at_end(inv, p);


    p = cgc_malloc(sizeof(Product));
    if ((0) == p) cgc__terminate(-7);
    cgc_memset(p, '\0', sizeof(Product));

    b = "93921599";
    d = "qJGFxRH";
    cgc_memcpy(p->barcode, b, cgc_strlen(b, '\0'));
    cgc_memcpy(p->desc, d, cgc_strlen(d, '\0'));
    p->model_num = 51914;
    p->cost = 1.06;
    p->sfn = onsale_fn[0];
    p->update_serial = 0;

    cgc_list_insert_at_end(inv, p);


    p = cgc_malloc(sizeof(Product));
    if ((0) == p) cgc__terminate(-7);
    cgc_memset(p, '\0', sizeof(Product));

    b = "78486525";
    d = "lrWSt";
    cgc_memcpy(p->barcode, b, cgc_strlen(b, '\0'));
    cgc_memcpy(p->desc, d, cgc_strlen(d, '\0'));
    p->model_num = 5215;
    p->cost = 1.92;
    p->sfn = onsale_fn[0];
    p->update_serial = 0;

    cgc_list_insert_at_end(inv, p);


    p = cgc_malloc(sizeof(Product));
    if ((0) == p) cgc__terminate(-7);
    cgc_memset(p, '\0', sizeof(Product));

    b = "75836131";
    d = "Cm";
    cgc_memcpy(p->barcode, b, cgc_strlen(b, '\0'));
    cgc_memcpy(p->desc, d, cgc_strlen(d, '\0'));
    p->model_num = 35136;
    p->cost = 8.44;
    p->sfn = onsale_fn[0];
    p->update_serial = 0;

    cgc_list_insert_at_end(inv, p);


    p = cgc_malloc(sizeof(Product));
    if ((0) == p) cgc__terminate(-7);
    cgc_memset(p, '\0', sizeof(Product));

    b = "95486291";
    d = "jJIhbikVwbdVIhCAZGHqjLY";
    cgc_memcpy(p->barcode, b, cgc_strlen(b, '\0'));
    cgc_memcpy(p->desc, d, cgc_strlen(d, '\0'));
    p->model_num = 30557;
    p->cost = 5.14;
    p->sfn = onsale_fn[0];
    p->update_serial = 0;

    cgc_list_insert_at_end(inv, p);


    p = cgc_malloc(sizeof(Product));
    if ((0) == p) cgc__terminate(-7);
    cgc_memset(p, '\0', sizeof(Product));

    b = "19044824";
    d = "mfoLvDmaKMrQNvWLWUiYCiXNnZOMU";
    cgc_memcpy(p->barcode, b, cgc_strlen(b, '\0'));
    cgc_memcpy(p->desc, d, cgc_strlen(d, '\0'));
    p->model_num = 18280;
    p->cost = 3.65;
    p->sfn = onsale_fn[0];
    p->update_serial = 0;

    cgc_list_insert_at_end(inv, p);


    p = cgc_malloc(sizeof(Product));
    if ((0) == p) cgc__terminate(-7);
    cgc_memset(p, '\0', sizeof(Product));

    b = "30172465";
    d = "CKFuyRMTABZMIBdsK";
    cgc_memcpy(p->barcode, b, cgc_strlen(b, '\0'));
    cgc_memcpy(p->desc, d, cgc_strlen(d, '\0'));
    p->model_num = 44608;
    p->cost = 5.41;
    p->sfn = onsale_fn[0];
    p->update_serial = 0;

    cgc_list_insert_at_end(inv, p);


    p = cgc_malloc(sizeof(Product));
    if ((0) == p) cgc__terminate(-7);
    cgc_memset(p, '\0', sizeof(Product));

    b = "83497266";
    d = "XyEYbfHmiWVtxO";
    cgc_memcpy(p->barcode, b, cgc_strlen(b, '\0'));
    cgc_memcpy(p->desc, d, cgc_strlen(d, '\0'));
    p->model_num = 1520;
    p->cost = 6.46;
    p->sfn = onsale_fn[0];
    p->update_serial = 0;

    cgc_list_insert_at_end(inv, p);


    p = cgc_malloc(sizeof(Product));
    if ((0) == p) cgc__terminate(-7);
    cgc_memset(p, '\0', sizeof(Product));

    b = "46693171";
    d = "YmUHUvQoJ";
    cgc_memcpy(p->barcode, b, cgc_strlen(b, '\0'));
    cgc_memcpy(p->desc, d, cgc_strlen(d, '\0'));
    p->model_num = 45063;
    p->cost = 0.68;
    p->sfn = onsale_fn[0];
    p->update_serial = 0;

    cgc_list_insert_at_end(inv, p);


    p = cgc_malloc(sizeof(Product));
    if ((0) == p) cgc__terminate(-7);
    cgc_memset(p, '\0', sizeof(Product));

    b = "60531381";
    d = "QiMrgINCfFjkdvozTnpjtYrELDjgmK";
    cgc_memcpy(p->barcode, b, cgc_strlen(b, '\0'));
    cgc_memcpy(p->desc, d, cgc_strlen(d, '\0'));
    p->model_num = 50365;
    p->cost = 1.93;
    p->sfn = onsale_fn[0];
    p->update_serial = 0;

    cgc_list_insert_at_end(inv, p);


    p = cgc_malloc(sizeof(Product));
    if ((0) == p) cgc__terminate(-7);
    cgc_memset(p, '\0', sizeof(Product));

    b = "80111827";
    d = "EGCyAcNvAoGTznBIInHD";
    cgc_memcpy(p->barcode, b, cgc_strlen(b, '\0'));
    cgc_memcpy(p->desc, d, cgc_strlen(d, '\0'));
    p->model_num = 50163;
    p->cost = 7.36;
    p->sfn = onsale_fn[0];
    p->update_serial = 0;

    cgc_list_insert_at_end(inv, p);


    p = cgc_malloc(sizeof(Product));
    if ((0) == p) cgc__terminate(-7);
    cgc_memset(p, '\0', sizeof(Product));

    b = "46108933";
    d = "yA";
    cgc_memcpy(p->barcode, b, cgc_strlen(b, '\0'));
    cgc_memcpy(p->desc, d, cgc_strlen(d, '\0'));
    p->model_num = 18997;
    p->cost = 0.89;
    p->sfn = onsale_fn[0];
    p->update_serial = 0;

    cgc_list_insert_at_end(inv, p);


    p = cgc_malloc(sizeof(Product));
    if ((0) == p) cgc__terminate(-7);
    cgc_memset(p, '\0', sizeof(Product));

    b = "71344234";
    d = "GZxglAxzKwgOEwRVCgPdf";
    cgc_memcpy(p->barcode, b, cgc_strlen(b, '\0'));
    cgc_memcpy(p->desc, d, cgc_strlen(d, '\0'));
    p->model_num = 40662;
    p->cost = 4.91;
    p->sfn = onsale_fn[0];
    p->update_serial = 0;

    cgc_list_insert_at_end(inv, p);


    p = cgc_malloc(sizeof(Product));
    if ((0) == p) cgc__terminate(-7);
    cgc_memset(p, '\0', sizeof(Product));

    b = "20102117";
    d = "RijMwfgJPEmoMjLCeepSY";
    cgc_memcpy(p->barcode, b, cgc_strlen(b, '\0'));
    cgc_memcpy(p->desc, d, cgc_strlen(d, '\0'));
    p->model_num = 31998;
    p->cost = 1.43;
    p->sfn = onsale_fn[0];
    p->update_serial = 0;

    cgc_list_insert_at_end(inv, p);


    p = cgc_malloc(sizeof(Product));
    if ((0) == p) cgc__terminate(-7);
    cgc_memset(p, '\0', sizeof(Product));

    b = "79267208";
    d = "XvnPoMSNWZVhfUMmpFKpphmfbwSTVo";
    cgc_memcpy(p->barcode, b, cgc_strlen(b, '\0'));
    cgc_memcpy(p->desc, d, cgc_strlen(d, '\0'));
    p->model_num = 34301;
    p->cost = 9.62;
    p->sfn = onsale_fn[0];
    p->update_serial = 0;

    cgc_list_insert_at_end(inv, p);


    p = cgc_malloc(sizeof(Product));
    if ((0) == p) cgc__terminate(-7);
    cgc_memset(p, '\0', sizeof(Product));

    b = "13001388";
    d = "ngllfhKdGIPHvstPd";
    cgc_memcpy(p->barcode, b, cgc_strlen(b, '\0'));
    cgc_memcpy(p->desc, d, cgc_strlen(d, '\0'));
    p->model_num = 54407;
    p->cost = 4.96;
    p->sfn = onsale_fn[0];
    p->update_serial = 0;

    cgc_list_insert_at_end(inv, p);


    p = cgc_malloc(sizeof(Product));
    if ((0) == p) cgc__terminate(-7);
    cgc_memset(p, '\0', sizeof(Product));

    b = "17573103";
    d = "P";
    cgc_memcpy(p->barcode, b, cgc_strlen(b, '\0'));
    cgc_memcpy(p->desc, d, cgc_strlen(d, '\0'));
    p->model_num = 2515;
    p->cost = 4.57;
    p->sfn = onsale_fn[0];
    p->update_serial = 0;

    cgc_list_insert_at_end(inv, p);


    p = cgc_malloc(sizeof(Product));
    if ((0) == p) cgc__terminate(-7);
    cgc_memset(p, '\0', sizeof(Product));

    b = "22995054";
    d = "GoiSSYhLBSSyDMzpZEfEN";
    cgc_memcpy(p->barcode, b, cgc_strlen(b, '\0'));
    cgc_memcpy(p->desc, d, cgc_strlen(d, '\0'));
    p->model_num = 23072;
    p->cost = 8.89;
    p->sfn = onsale_fn[0];
    p->update_serial = 0;

    cgc_list_insert_at_end(inv, p);


    p = cgc_malloc(sizeof(Product));
    if ((0) == p) cgc__terminate(-7);
    cgc_memset(p, '\0', sizeof(Product));

    b = "58885039";
    d = "LvJBSMasVdFOjklc";
    cgc_memcpy(p->barcode, b, cgc_strlen(b, '\0'));
    cgc_memcpy(p->desc, d, cgc_strlen(d, '\0'));
    p->model_num = 45088;
    p->cost = 2.69;
    p->sfn = onsale_fn[0];
    p->update_serial = 0;

    cgc_list_insert_at_end(inv, p);


    p = cgc_malloc(sizeof(Product));
    if ((0) == p) cgc__terminate(-7);
    cgc_memset(p, '\0', sizeof(Product));

    b = "36970139";
    d = "emCCzWhvvveEoEViRKwIsyWcMA";
    cgc_memcpy(p->barcode, b, cgc_strlen(b, '\0'));
    cgc_memcpy(p->desc, d, cgc_strlen(d, '\0'));
    p->model_num = 47167;
    p->cost = 1.94;
    p->sfn = onsale_fn[0];
    p->update_serial = 0;

    cgc_list_insert_at_end(inv, p);


    p = cgc_malloc(sizeof(Product));
    if ((0) == p) cgc__terminate(-7);
    cgc_memset(p, '\0', sizeof(Product));

    b = "15048891";
    d = "QPuFuYcsUqextKPzFHBFhWWxiwL";
    cgc_memcpy(p->barcode, b, cgc_strlen(b, '\0'));
    cgc_memcpy(p->desc, d, cgc_strlen(d, '\0'));
    p->model_num = 39914;
    p->cost = 9.83;
    p->sfn = onsale_fn[0];
    p->update_serial = 0;

    cgc_list_insert_at_end(inv, p);


    p = cgc_malloc(sizeof(Product));
    if ((0) == p) cgc__terminate(-7);
    cgc_memset(p, '\0', sizeof(Product));

    b = "52820574";
    d = "VweQMYhAYdTCE";
    cgc_memcpy(p->barcode, b, cgc_strlen(b, '\0'));
    cgc_memcpy(p->desc, d, cgc_strlen(d, '\0'));
    p->model_num = 34549;
    p->cost = 7.15;
    p->sfn = onsale_fn[0];
    p->update_serial = 0;

    cgc_list_insert_at_end(inv, p);


    p = cgc_malloc(sizeof(Product));
    if ((0) == p) cgc__terminate(-7);
    cgc_memset(p, '\0', sizeof(Product));

    b = "05558432";
    d = "YrsbMdytqSNuDPUN";
    cgc_memcpy(p->barcode, b, cgc_strlen(b, '\0'));
    cgc_memcpy(p->desc, d, cgc_strlen(d, '\0'));
    p->model_num = 43021;
    p->cost = 7.77;
    p->sfn = onsale_fn[0];
    p->update_serial = 0;

    cgc_list_insert_at_end(inv, p);


    p = cgc_malloc(sizeof(Product));
    if ((0) == p) cgc__terminate(-7);
    cgc_memset(p, '\0', sizeof(Product));

    b = "45266556";
    d = "SxagJhzOzEhqAhpAdpuREDJnM";
    cgc_memcpy(p->barcode, b, cgc_strlen(b, '\0'));
    cgc_memcpy(p->desc, d, cgc_strlen(d, '\0'));
    p->model_num = 53735;
    p->cost = 2.5;
    p->sfn = onsale_fn[0];
    p->update_serial = 0;

    cgc_list_insert_at_end(inv, p);


    p = cgc_malloc(sizeof(Product));
    if ((0) == p) cgc__terminate(-7);
    cgc_memset(p, '\0', sizeof(Product));

    b = "55671691";
    d = "JvqXCPHjJyQ";
    cgc_memcpy(p->barcode, b, cgc_strlen(b, '\0'));
    cgc_memcpy(p->desc, d, cgc_strlen(d, '\0'));
    p->model_num = 60683;
    p->cost = 5.15;
    p->sfn = onsale_fn[0];
    p->update_serial = 0;

    cgc_list_insert_at_end(inv, p);


    p = cgc_malloc(sizeof(Product));
    if ((0) == p) cgc__terminate(-7);
    cgc_memset(p, '\0', sizeof(Product));

    b = "30246117";
    d = "DaEzVgFxbPzzIF";
    cgc_memcpy(p->barcode, b, cgc_strlen(b, '\0'));
    cgc_memcpy(p->desc, d, cgc_strlen(d, '\0'));
    p->model_num = 11978;
    p->cost = 2.24;
    p->sfn = onsale_fn[0];
    p->update_serial = 0;

    cgc_list_insert_at_end(inv, p);


    p = cgc_malloc(sizeof(Product));
    if ((0) == p) cgc__terminate(-7);
    cgc_memset(p, '\0', sizeof(Product));

    b = "32349600";
    d = "vDzqEgRHizanDmHWYmtKjy";
    cgc_memcpy(p->barcode, b, cgc_strlen(b, '\0'));
    cgc_memcpy(p->desc, d, cgc_strlen(d, '\0'));
    p->model_num = 32694;
    p->cost = 0.9;
    p->sfn = onsale_fn[0];
    p->update_serial = 0;

    cgc_list_insert_at_end(inv, p);


    p = cgc_malloc(sizeof(Product));
    if ((0) == p) cgc__terminate(-7);
    cgc_memset(p, '\0', sizeof(Product));

    b = "27002400";
    d = "TAAwfhYZBDTbayzgoqEhIiYYZLPBss";
    cgc_memcpy(p->barcode, b, cgc_strlen(b, '\0'));
    cgc_memcpy(p->desc, d, cgc_strlen(d, '\0'));
    p->model_num = 28221;
    p->cost = 9.18;
    p->sfn = onsale_fn[0];
    p->update_serial = 0;

    cgc_list_insert_at_end(inv, p);


    p = cgc_malloc(sizeof(Product));
    if ((0) == p) cgc__terminate(-7);
    cgc_memset(p, '\0', sizeof(Product));

    b = "23728750";
    d = "KMLqLPUgFrTS";
    cgc_memcpy(p->barcode, b, cgc_strlen(b, '\0'));
    cgc_memcpy(p->desc, d, cgc_strlen(d, '\0'));
    p->model_num = 28808;
    p->cost = 0.98;
    p->sfn = onsale_fn[0];
    p->update_serial = 0;

    cgc_list_insert_at_end(inv, p);


    p = cgc_malloc(sizeof(Product));
    if ((0) == p) cgc__terminate(-7);
    cgc_memset(p, '\0', sizeof(Product));

    b = "27227405";
    d = "xbIkRMPWFwVechYvOEnobB";
    cgc_memcpy(p->barcode, b, cgc_strlen(b, '\0'));
    cgc_memcpy(p->desc, d, cgc_strlen(d, '\0'));
    p->model_num = 7006;
    p->cost = 9.0;
    p->sfn = onsale_fn[0];
    p->update_serial = 0;

    cgc_list_insert_at_end(inv, p);


    p = cgc_malloc(sizeof(Product));
    if ((0) == p) cgc__terminate(-7);
    cgc_memset(p, '\0', sizeof(Product));

    b = "88925705";
    d = "aMZLCrgwzBKDLiauIPwEHaX";
    cgc_memcpy(p->barcode, b, cgc_strlen(b, '\0'));
    cgc_memcpy(p->desc, d, cgc_strlen(d, '\0'));
    p->model_num = 6082;
    p->cost = 6.82;
    p->sfn = onsale_fn[0];
    p->update_serial = 0;

    cgc_list_insert_at_end(inv, p);


    p = cgc_malloc(sizeof(Product));
    if ((0) == p) cgc__terminate(-7);
    cgc_memset(p, '\0', sizeof(Product));

    b = "60234543";
    d = "UcWX";
    cgc_memcpy(p->barcode, b, cgc_strlen(b, '\0'));
    cgc_memcpy(p->desc, d, cgc_strlen(d, '\0'));
    p->model_num = 23069;
    p->cost = 1.92;
    p->sfn = onsale_fn[0];
    p->update_serial = 0;

    cgc_list_insert_at_end(inv, p);


    p = cgc_malloc(sizeof(Product));
    if ((0) == p) cgc__terminate(-7);
    cgc_memset(p, '\0', sizeof(Product));

    b = "26550548";
    d = "btg";
    cgc_memcpy(p->barcode, b, cgc_strlen(b, '\0'));
    cgc_memcpy(p->desc, d, cgc_strlen(d, '\0'));
    p->model_num = 57058;
    p->cost = 7.31;
    p->sfn = onsale_fn[0];
    p->update_serial = 0;

    cgc_list_insert_at_end(inv, p);


    p = cgc_malloc(sizeof(Product));
    if ((0) == p) cgc__terminate(-7);
    cgc_memset(p, '\0', sizeof(Product));

    b = "80824106";
    d = "B";
    cgc_memcpy(p->barcode, b, cgc_strlen(b, '\0'));
    cgc_memcpy(p->desc, d, cgc_strlen(d, '\0'));
    p->model_num = 37533;
    p->cost = 4.06;
    p->sfn = onsale_fn[0];
    p->update_serial = 0;

    cgc_list_insert_at_end(inv, p);


}
