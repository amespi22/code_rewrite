# 1 "/home/pdreiter/Data/APR_eval/GenProg/v24.cb_eval/Griswold.transform.ga/Griswold/src/Griswold/src/assemble.c"
# 1 "/home/pdreiter/Data/APR_eval/GenProg/v24.cb_eval/Griswold.transform.ga/Griswold/build/Griswold//"
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
# 1 "/home/pdreiter/Data/APR_eval/GenProg/v24.cb_eval/Griswold.transform.ga/Griswold/src/Griswold/src/assemble.c"


# 1 "/home/pdreiter/Data/APR_eval/GenProg/v24.cb_eval/Griswold.transform.ga/Griswold/src/include/libcgc.h" 1

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
# 122 "/home/pdreiter/Data/APR_eval/GenProg/v24.cb_eval/Griswold.transform.ga/Griswold/src/include/libcgc.h"
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
# 4 "/home/pdreiter/Data/APR_eval/GenProg/v24.cb_eval/Griswold.transform.ga/Griswold/src/Griswold/src/assemble.c" 2
# 1 "/home/pdreiter/Data/APR_eval/GenProg/v24.cb_eval/Griswold.transform.ga/Griswold/src/Griswold/lib/cgc_libc.h" 1
# 30 "/home/pdreiter/Data/APR_eval/GenProg/v24.cb_eval/Griswold.transform.ga/Griswold/src/Griswold/lib/cgc_libc.h"
#define NARF_LIBC_H 



typedef signed char int8_t;
typedef signed int int32_t;
typedef unsigned int uint32_t;
typedef unsigned char uint8_t;

typedef enum {
  FALSE = 0,
  TRUE = 1,
} bool_t;

#define SUCCESS 0
#define ERRNO_ALLOC 5

typedef struct node {
 void * data;
 struct node *next;
 struct node *prev;
} node_t;



typedef struct list {
 node_t *head;
 node_t *tail;
 uint32_t count;
} list_t;


list_t * cgc_list_create_dup();
int cgc_list_append(list_t *lst, node_t *nd);


node_t * cgc_node_create(void * data);
node_t * cgc_get_list_head(list_t * lst);
node_t * cgc_get_list_tail(list_t * lst);
node_t * cgc_get_first_node(list_t * lst);
node_t * cgc_get_last_node(list_t * lst);

int cgc_rand(char *buf, cgc_size_t sz);




int cgc_send(const char *buf, const cgc_size_t size);
int cgc_transmit_all(int fd, const char *buf, const cgc_size_t size);
unsigned int cgc_recv_all(char *res_buf, cgc_size_t res_buf_size);
unsigned int cgc_read_all(int fd, char *buf, unsigned int size);


void *cgc_memset(void *dst, int c, unsigned int n);
# 5 "/home/pdreiter/Data/APR_eval/GenProg/v24.cb_eval/Griswold.transform.ga/Griswold/src/Griswold/src/assemble.c" 2
# 1 "/home/pdreiter/Data/APR_eval/GenProg/v24.cb_eval/Griswold.transform.ga/Griswold/src/Griswold/src/cgc_components.h" 1
# 24 "/home/pdreiter/Data/APR_eval/GenProg/v24.cb_eval/Griswold.transform.ga/Griswold/src/Griswold/src/cgc_components.h"
#define COMPONENTS_H 1

typedef enum {
 INCANDESCENT_M5_100BULB = 5,
 LED_C6_150BULB = 6,
 INCANDESCENT_C7_25BULB = 7,
 INCANDESCENT_C9_25BULB = 9,
} LIGHT_STRING_MODELS_T;

typedef enum {
 THREE_WAY = 3,
 SIX_WAY = 6,
 EIGHT_WAY = 8,
} SPLITTER_MODELS_T;

typedef enum {
 FIFTEEN_AMP = 15,
 TWENTY_AMP = 20,
} CIRCUIT_MODELS_T;

typedef enum {
 ONE_HUNDRED_AMP_EIGHT_SPACE = 10008,
 ONE_HUNDRED_AMP_SIXTEEN_SPACE = 10016,
 ONE_HUNDRED_AMP_TWENTY_SPACE = 10020,
 ONE_HUNDRED_FIFTY_AMP_TWENTY_SPACE = 15020,
 ONE_HUNDRED_FIFTY_AMP_TWENTY_FOUR_SPACE = 15024,
 ONE_HUNDRED_FIFTY_AMP_THIRTY_SPACE = 15030,
 TWO_HUNDRED_AMP_TWENTY_SPACE = 20020,
 TWO_HUNDRED_AMP_THIRTY_SPACE = 20030,
 TWO_HUNDRED_AMP_FOURTY_SPACE = 20040,
 TWO_HUNDRED_AMP_FOURTY_TWO_SPACE = 20042,
 FOUR_HUNDRED_AMP_TWENTY_SPACE = 40020,
 FOUR_HUNDRED_AMP_THIRTY_SPACE = 40030,
 FOUR_HUNDRED_AMP_FOURTY_SPACE = 40040,
 FOUR_HUNDRED_AMP_FOURTY_TWO_SPACE = 40042,
} LOAD_CENTER_MODELS_T;




typedef enum {
 SPLITTER = 0,
 LIGHT_STRING = 1,
 NO_LOAD = 2,
} LOAD_TYPE_T;

typedef struct receptacle_t {
 uint32_t id;
 LOAD_TYPE_T load_type;
 void *load;
 uint8_t amp_rating;
} receptacle_t;

typedef struct outlet_t {
 uint32_t id;
 receptacle_t r1;
 receptacle_t r2;
 uint8_t amp_rating;
} outlet_t;

typedef struct n_way_splitter_t {
 uint32_t id;
 uint8_t total_amp_rating;
 uint8_t receptacle_amp_rating;
 uint8_t receptacle_count;
 receptacle_t receptacles[8];
} n_way_splitter_t;

typedef struct light_string_t {
 uint32_t id;
 LIGHT_STRING_MODELS_T model_id;
 float total_wattage;
 receptacle_t receptacle;
} light_string_t;

typedef struct breaker_t {
 uint32_t id;
 uint8_t amp_rating;
 list_t *outlets;
} breaker_t;

typedef struct load_center_t {
 uint8_t breaker_spaces;
 uint8_t breakers_installed_cnt;
 uint32_t amp_rating;
 breaker_t breakers[0];
} load_center_t;

float cgc_get_max_amps_of_light_string();
load_center_t *cgc_get_new_load_center_by_model_id(LOAD_CENTER_MODELS_T model_id);
int8_t cgc_get_new_breaker_by_model_id(CIRCUIT_MODELS_T model_id, breaker_t *breaker_space, uint8_t breaker_space_idx);
outlet_t *cgc_get_new_outlet_by_model_id(CIRCUIT_MODELS_T model_id);
n_way_splitter_t *cgc_get_new_n_way_splitter_by_model_id(SPLITTER_MODELS_T model_id);
light_string_t *cgc_get_new_light_string_by_model_id(LIGHT_STRING_MODELS_T model_id);
# 6 "/home/pdreiter/Data/APR_eval/GenProg/v24.cb_eval/Griswold.transform.ga/Griswold/src/Griswold/src/assemble.c" 2
# 1 "/home/pdreiter/Data/APR_eval/GenProg/v24.cb_eval/Griswold.transform.ga/Griswold/src/Griswold/src/cgc_assemble.h" 1
# 24 "/home/pdreiter/Data/APR_eval/GenProg/v24.cb_eval/Griswold.transform.ga/Griswold/src/Griswold/src/cgc_assemble.h"
#define ASSEMBLE_H 1







typedef struct assemble_result_t {
 uint32_t object_id;
 uint32_t receptacle_id[8];
 uint8_t receptacle_ids_assigned_cnt;
} assemble_result_t;

enum {
 ERR_E_MODEL_EXISTS = -41,
 ERR_E_MODEL_NOT_EXISTS = -42,
 ERR_BREAKER_SPACES_FULL = -43,
 ERR_INVALID_MODEL_ID = -44,
 ERR_INVALID_BREAKER_ID = -45,
 ERR_INVALID_RECEPTACLE_ID = -46,
 ERR_INVALID_OUTLET_ID = -47,
 ERR_INVALID_SPLITTER_ID = -48,
 ERR_INVALID_LIGHT_STRING_ID = -49,
 ERR_RECEPTACLE_FULL = -50,
 ERR_OUTLET_AMPS_EXCEED_BREAKER_AMPS = -51,
};


int32_t cgc_get_count_outlets_on_breaker(uint32_t breaker_id);
int8_t cgc_get_amp_rating_of_breaker(uint32_t breaker_id);
float cgc_get_total_amp_load_on_breaker_by_breaker_id(uint32_t breaker_id);

int8_t cgc_get_amp_rating_of_outlet(uint32_t outlet_id);
float cgc_get_total_amp_load_on_outlet_by_outlet_id(uint32_t outlet_id);
float cgc_get_max_receptacle_amp_load_on_outlet_by_outlet_id(uint32_t outlet_id);

int8_t cgc_get_amp_rating_of_splitter(uint32_t splitter_id);
float cgc_get_total_amp_load_on_splitter_by_splitter_id(uint32_t splitter_id);
float cgc_get_max_receptacle_amp_load_on_splitter_by_splitter_id(uint32_t splitter_id);

float cgc_get_amp_rating_of_light_string(uint32_t light_string_id);
float cgc_get_total_amp_load_on_light_string_by_light_string_id(uint32_t light_string_id);

int8_t cgc_get_amp_rating_of_receptacle(uint32_t receptacle_id);
float cgc_get_total_amp_load_on_receptacle_by_receptacle_id(uint32_t receptacle_id);

int8_t cgc_get_number_of_breakers_installed_in_load_center();
int8_t cgc_get_total_breaker_space_count();
int32_t cgc_get_amp_rating_of_load_center();
float cgc_get_total_amp_load_on_load_center();



int8_t cgc_init_electric_model(LOAD_CENTER_MODELS_T model_id);
int8_t cgc_add_breaker_to_load_center(CIRCUIT_MODELS_T model_id, assemble_result_t *result);
int8_t cgc_add_outlet_to_breaker(CIRCUIT_MODELS_T outlet_model_id, uint32_t breaker_id, assemble_result_t *result);
int8_t cgc_add_n_way_splitter_to_receptacle(SPLITTER_MODELS_T splitter_model_id, uint32_t receptacle_id, assemble_result_t *result);
int8_t cgc_add_light_string_to_receptacle(LIGHT_STRING_MODELS_T light_string_model_id, uint32_t receptacle_id, assemble_result_t *result);
# 7 "/home/pdreiter/Data/APR_eval/GenProg/v24.cb_eval/Griswold.transform.ga/Griswold/src/Griswold/src/assemble.c" 2
static receptacle_t *cgc_search_receptacle_for_receptacle_id(receptacle_t * receptacle, uint32_t receptacle_id);
static receptacle_t *cgc_search_light_string_for_receptacle_id(light_string_t * light_string, uint32_t receptacle_id);
static receptacle_t *cgc_search_outlet_for_receptacle_id(outlet_t * outlet, uint32_t receptacle_id);
static receptacle_t *cgc_search_splitter_for_receptacle_id(n_way_splitter_t * splitter, uint32_t receptacle_id);
static n_way_splitter_t *cgc_search_receptacle_for_splitter_id(receptacle_t * r, uint32_t splitter_id);
static n_way_splitter_t *cgc_search_light_string_for_splitter_id(light_string_t * ls, uint32_t splitter_id);
static n_way_splitter_t *cgc_search_outlet_for_splitter_id(outlet_t * o, uint32_t splitter_id);
static n_way_splitter_t *cgc_search_splitter_for_splitter_id(n_way_splitter_t * splitter, uint32_t splitter_id);
static light_string_t *cgc_search_receptacle_for_light_string_id(receptacle_t * r, uint32_t light_string_id);
static light_string_t *cgc_search_light_string_for_light_string_id(light_string_t * light_string, uint32_t light_string_id);
static light_string_t *cgc_search_outlet_for_light_string_id(outlet_t * o, uint32_t light_string_id);
static light_string_t *cgc_search_splitter_for_light_string_id(n_way_splitter_t * s, uint32_t light_string_id);
static list_t *cgc_get_outlet_list_on_breaker(uint32_t breaker_id);
static float cgc_get_total_amp_load_on_light_string_by_light_string_va(light_string_t * light_string);
static float cgc_get_total_amp_load_on_splitter_by_splitter_va(n_way_splitter_t * splitter);
static float cgc_get_total_amp_load_on_receptacle_by_receptacle_va(receptacle_t * receptacle);
static float cgc_get_total_amp_load_on_outlet_by_outlet_va(outlet_t * outlet);

static load_center_t *e_model = (0);

#define FIX_INGREDIENT_CONTENT 
#define FIX_INGREDIENT_CONTENT_VAR 
static int fix_ingred_enable=0;
static void __attribute((constructor)) fix_ingred_enable_init(){
    char* tmp=getenv("ENABLE_FIXES");
    if (tmp) { fix_ingred_enable=1; }
}







void fix_ingred_assemble_0();
static float cgc_convert_watts_to_amps(float watts)
{
if (fix_ingred_enable){ fix_ingred_assemble_0(); };
    return (watts / 120.0);
}

void fix_ingred_assemble_1();
static uint8_t cgc_load_center_is_created()
{
if (fix_ingred_enable){ fix_ingred_assemble_1(); };
    if ((0) == e_model) {
 return FALSE;
    } else {
 return TRUE;
    }
}

void fix_ingred_assemble_2();
static int8_t cgc_load_center_breaker_spaces_are_full()
{
if (fix_ingred_enable){ fix_ingred_assemble_2(); };
    if ((TRUE == cgc_load_center_is_created()) && (e_model->breaker_spaces == e_model->breakers_installed_cnt)) {
 return TRUE;
    } else {
 return FALSE;
    }
}

void fix_ingred_assemble_3();
static LOAD_TYPE_T cgc_get_receptacle_load_type(receptacle_t * receptacle)
{
if (fix_ingred_enable){ fix_ingred_assemble_3(); };
    return receptacle->load_type;
}

void fix_ingred_assemble_4();
static int8_t cgc_receptacle_is_loaded(receptacle_t * receptacle)
{
if (fix_ingred_enable){ fix_ingred_assemble_4(); };
    static LOAD_TYPE_T tlv1;
    {
        receptacle_t* tlv2;
        tlv2 = receptacle;
        tlv1 = cgc_get_receptacle_load_type(tlv2);
    }
    if (NO_LOAD > tlv1) {
 return TRUE;
    } else {
 return FALSE;
    }
}

void fix_ingred_assemble_5_1_2();
void fix_ingred_assemble_5_1_3();
void fix_ingred_assemble_5_1();
void fix_ingred_assemble_5();
static receptacle_t *cgc_search_receptacle_for_receptacle_id(receptacle_t * receptacle, uint32_t receptacle_id)
{
if (fix_ingred_enable){ fix_ingred_assemble_5(); };
    receptacle_t* r;
    r = (0);
    if (receptacle_id == receptacle->id) {
 r = receptacle;
    } else {
 static LOAD_TYPE_T tlv1;
 {
     receptacle_t* tlv3;
     tlv3 = receptacle;
     tlv1 = cgc_get_receptacle_load_type(tlv3);
 }
 if (SPLITTER == tlv1) {
     {
         n_way_splitter_t* tlv5;
         tlv5 = ( n_way_splitter_t * ) receptacle -> load;
         uint32_t tlv4;
         tlv4 = receptacle_id;
         r = cgc_search_splitter_for_receptacle_id(tlv5,tlv4);
     }
 } else {
     static LOAD_TYPE_T tlv2;
     {
         receptacle_t* tlv6;
         tlv6 = receptacle;
         tlv2 = cgc_get_receptacle_load_type(tlv6);
     }
     if (LIGHT_STRING == tlv2) {
  {
      light_string_t* tlv8;
      tlv8 = ( light_string_t * ) receptacle -> load;
      uint32_t tlv7;
      tlv7 = receptacle_id;
      r = cgc_search_light_string_for_receptacle_id(tlv8,tlv7);
  }
     }
 }
    }
    return r;
}

void fix_ingred_assemble_6_1_1();
void fix_ingred_assemble_6_1();
void fix_ingred_assemble_6();
static receptacle_t *cgc_search_outlet_for_receptacle_id(outlet_t * outlet, uint32_t receptacle_id)
{
if (fix_ingred_enable){ fix_ingred_assemble_6(); };
    receptacle_t* r;
    r = (0);
    {
        receptacle_t* tlv2;
        tlv2 = & ( outlet -> r1 );
        uint32_t tlv1;
        tlv1 = receptacle_id;
        r = cgc_search_receptacle_for_receptacle_id(tlv2,tlv1);
    }
    if ((0) == r) {
 {
     receptacle_t* tlv4;
     tlv4 = & ( outlet -> r2 );
     uint32_t tlv3;
     tlv3 = receptacle_id;
     r = cgc_search_receptacle_for_receptacle_id(tlv4,tlv3);
 }
    }
    return r;
}

void fix_ingred_assemble_7_1_1();
void fix_ingred_assemble_7_1_2();
void fix_ingred_assemble_7_1();
void fix_ingred_assemble_7();
static receptacle_t *cgc_search_splitter_for_receptacle_id(n_way_splitter_t * splitter, uint32_t receptacle_id)
{
if (fix_ingred_enable){ fix_ingred_assemble_7(); };
    receptacle_t* r;
    r = (0);
    for (uint32_t idx = 0; idx <= splitter->receptacle_count; idx++) {
 {
     receptacle_t* tlv2;
     tlv2 = & ( splitter -> receptacles [ idx ] );
     uint32_t tlv1;
     tlv1 = receptacle_id;
     r = cgc_search_receptacle_for_receptacle_id(tlv2,tlv1);
 }
 if ((0) != r) {
     break;
 }
    }
    return r;
}

void fix_ingred_assemble_8();
static receptacle_t *cgc_search_light_string_for_receptacle_id(light_string_t * light_string, uint32_t receptacle_id)
{
if (fix_ingred_enable){ fix_ingred_assemble_8(); };
    return cgc_search_receptacle_for_receptacle_id(&(light_string->receptacle), receptacle_id);
}

void fix_ingred_assemble_9_3_1();
void fix_ingred_assemble_9_3();
void fix_ingred_assemble_9();
static n_way_splitter_t *cgc_search_receptacle_for_splitter_id(receptacle_t * r, uint32_t splitter_id)
{
if (fix_ingred_enable){ fix_ingred_assemble_9(); };
    n_way_splitter_t* s;
    s = (0);
    static LOAD_TYPE_T tlv1;
    {
        receptacle_t* tlv3;
        tlv3 = r;
        tlv1 = cgc_get_receptacle_load_type(tlv3);
    }
    if (SPLITTER == tlv1) {
 {
     n_way_splitter_t* tlv5;
     tlv5 = ( n_way_splitter_t * ) r -> load;
     uint32_t tlv4;
     tlv4 = splitter_id;
     s = cgc_search_splitter_for_splitter_id(tlv5,tlv4);
 }
    } else {
 static LOAD_TYPE_T tlv2;
 {
     receptacle_t* tlv6;
     tlv6 = r;
     tlv2 = cgc_get_receptacle_load_type(tlv6);
 }
 if (LIGHT_STRING == tlv2) {
     {
         light_string_t* tlv8;
         tlv8 = ( light_string_t * ) r -> load;
         uint32_t tlv7;
         tlv7 = splitter_id;
         s = cgc_search_light_string_for_splitter_id(tlv8,tlv7);
     }
 }
    }
    return s;
}

void fix_ingred_assemble_10();
static n_way_splitter_t *cgc_search_light_string_for_splitter_id(light_string_t * ls, uint32_t splitter_id)
{
if (fix_ingred_enable){ fix_ingred_assemble_10(); };
    return cgc_search_receptacle_for_splitter_id(&(ls->receptacle), splitter_id);
}

void fix_ingred_assemble_11_1_1();
void fix_ingred_assemble_11_1();
void fix_ingred_assemble_11();
static n_way_splitter_t *cgc_search_outlet_for_splitter_id(outlet_t * o, uint32_t splitter_id)
{
if (fix_ingred_enable){ fix_ingred_assemble_11(); };
    n_way_splitter_t* s;
    s = (0);
    {
        receptacle_t* tlv2;
        tlv2 = & ( o -> r1 );
        uint32_t tlv1;
        tlv1 = splitter_id;
        s = cgc_search_receptacle_for_splitter_id(tlv2,tlv1);
    }
    if ((0) == s) {
 {
     receptacle_t* tlv4;
     tlv4 = & ( o -> r2 );
     uint32_t tlv3;
     tlv3 = splitter_id;
     s = cgc_search_receptacle_for_splitter_id(tlv4,tlv3);
 }
    }
    return s;
}

void fix_ingred_assemble_12_1_3();
void fix_ingred_assemble_12_1();
void fix_ingred_assemble_12_3_1();
void fix_ingred_assemble_12_3_2();
void fix_ingred_assemble_12_3();
void fix_ingred_assemble_12();
static n_way_splitter_t *cgc_search_splitter_for_splitter_id(n_way_splitter_t * splitter, uint32_t splitter_id)
{
if (fix_ingred_enable){ fix_ingred_assemble_12(); };
    n_way_splitter_t* s;
    s = (0);
    if (splitter_id == splitter->id) {
 s = splitter;
    } else {
 for (uint8_t idx = 0; idx < splitter->receptacle_count; idx++) {
     {
         receptacle_t* tlv2;
         tlv2 = & ( splitter -> receptacles [ idx ] );
         uint32_t tlv1;
         tlv1 = splitter_id;
         s = cgc_search_receptacle_for_splitter_id(tlv2,tlv1);
     }
     if ((0) != s) {
  break;
     }
 }
    }
    return s;
}

void fix_ingred_assemble_13_3_1();
void fix_ingred_assemble_13_3();
void fix_ingred_assemble_13();
static light_string_t *cgc_search_receptacle_for_light_string_id(receptacle_t * r, uint32_t light_string_id)
{
if (fix_ingred_enable){ fix_ingred_assemble_13(); };
    light_string_t* ls;
    ls = (0);
    static LOAD_TYPE_T tlv1;
    {
        receptacle_t* tlv3;
        tlv3 = r;
        tlv1 = cgc_get_receptacle_load_type(tlv3);
    }
    if (SPLITTER == tlv1) {
 {
     n_way_splitter_t* tlv5;
     tlv5 = ( n_way_splitter_t * ) r -> load;
     uint32_t tlv4;
     tlv4 = light_string_id;
     ls = cgc_search_splitter_for_light_string_id(tlv5,tlv4);
 }
    } else {
 static LOAD_TYPE_T tlv2;
 {
     receptacle_t* tlv6;
     tlv6 = r;
     tlv2 = cgc_get_receptacle_load_type(tlv6);
 }
 if (LIGHT_STRING == tlv2) {
     {
         light_string_t* tlv8;
         tlv8 = ( light_string_t * ) r -> load;
         uint32_t tlv7;
         tlv7 = light_string_id;
         ls = cgc_search_light_string_for_light_string_id(tlv8,tlv7);
     }
 }
    }
    return ls;
}

void fix_ingred_assemble_14_1_2();
void fix_ingred_assemble_14_1_3();
void fix_ingred_assemble_14_1();
void fix_ingred_assemble_14();
static light_string_t *cgc_search_light_string_for_light_string_id(light_string_t * light_string, uint32_t light_string_id)
{
if (fix_ingred_enable){ fix_ingred_assemble_14(); };
    light_string_t* ls;
    ls = (0);
    if (light_string_id == light_string->id) {
 ls = light_string;
    } else {
 {
     receptacle_t* tlv2;
     tlv2 = & ( light_string -> receptacle );
     uint32_t tlv1;
     tlv1 = light_string_id;
     ls = cgc_search_receptacle_for_light_string_id(tlv2,tlv1);
 }
    }
    return ls;
}

void fix_ingred_assemble_15_1_1();
void fix_ingred_assemble_15_1();
void fix_ingred_assemble_15();
static light_string_t *cgc_search_outlet_for_light_string_id(outlet_t * o, uint32_t light_string_id)
{
if (fix_ingred_enable){ fix_ingred_assemble_15(); };
    light_string_t* ls;
    ls = (0);
    {
        receptacle_t* tlv2;
        tlv2 = & ( o -> r1 );
        uint32_t tlv1;
        tlv1 = light_string_id;
        ls = cgc_search_receptacle_for_light_string_id(tlv2,tlv1);
    }
    if ((0) == ls) {
 {
     receptacle_t* tlv4;
     tlv4 = & ( o -> r2 );
     uint32_t tlv3;
     tlv3 = light_string_id;
     ls = cgc_search_receptacle_for_light_string_id(tlv4,tlv3);
 }
    }
    return ls;
}

void fix_ingred_assemble_16_1_2();
void fix_ingred_assemble_16_1();
void fix_ingred_assemble_16();
static light_string_t *cgc_search_splitter_for_light_string_id(n_way_splitter_t * s, uint32_t light_string_id)
{
if (fix_ingred_enable){ fix_ingred_assemble_16(); };
    light_string_t* ls;
    ls = (0);
    for (uint8_t idx = 0; idx < s->receptacle_count; idx++) {
 {
     receptacle_t* tlv2;
     tlv2 = & ( s -> receptacles [ idx ] );
     uint32_t tlv1;
     tlv1 = light_string_id;
     ls = cgc_search_receptacle_for_light_string_id(tlv2,tlv1);
 }
 if ((0) != ls) {
     break;
 }
    }
    return ls;
}

void fix_ingred_assemble_17_1_0();
void fix_ingred_assemble_17_1();
void fix_ingred_assemble_17();
static receptacle_t *cgc_get_receptacle_by_id_from_breaker_id(uint32_t breaker_id, uint32_t receptacle_id)
{
if (fix_ingred_enable){ fix_ingred_assemble_17(); };
    receptacle_t* r;
    r = (0);
    list_t* outlet_list;
    {
        uint32_t tlv1;
        tlv1 = breaker_id;
        outlet_list = cgc_get_outlet_list_on_breaker(tlv1);
    }
    node_t* outlet_node_ptr;
    {
        list_t* tlv2;
        tlv2 = outlet_list;
        outlet_node_ptr = cgc_get_first_node(tlv2);
    }
    while (cgc_get_list_tail(outlet_list) != outlet_node_ptr) {
 {
     outlet_t* tlv4;
     tlv4 = ( outlet_t * ) outlet_node_ptr -> data;
     uint32_t tlv3;
     tlv3 = receptacle_id;
     r = cgc_search_outlet_for_receptacle_id(tlv4,tlv3);
 }
 if ((0) != r) {
     break;
 }
 outlet_node_ptr = outlet_node_ptr->next;
    }
    return r;
}

void fix_ingred_assemble_18_2_3();
void fix_ingred_assemble_18_2_4();
void fix_ingred_assemble_18_2();
void fix_ingred_assemble_18_3_1();
void fix_ingred_assemble_18_3();
void fix_ingred_assemble_18();
static receptacle_t *cgc_get_receptacle_by_id(uint32_t receptacle_id)
{
if (fix_ingred_enable){ fix_ingred_assemble_18(); };
    receptacle_t* r;
    r = (0);

    static uint8_t tlv1;
    tlv1 = cgc_load_center_is_created ( );
    if (TRUE == tlv1) {
 for (uint32_t breaker_idx = 0; breaker_idx < e_model->breakers_installed_cnt; breaker_idx++) {

     {
         uint32_t tlv3;
         tlv3 = breaker_idx;
         uint32_t tlv2;
         tlv2 = receptacle_id;
         r = cgc_get_receptacle_by_id_from_breaker_id(tlv3,tlv2);
     }
     if ((0) != r) {
  break;
     }
 }
    }
    return r;
}

void fix_ingred_assemble_19();
static breaker_t *cgc_get_breaker_by_id(uint32_t breaker_id)
{
if (fix_ingred_enable){ fix_ingred_assemble_19(); };
    static uint8_t tlv1;
    tlv1 = cgc_load_center_is_created ( );
    if ((FALSE == tlv1) || (0 == e_model->breakers_installed_cnt)) {
 return (0);
    }
    return &(e_model->breakers[breaker_id]);
}

void fix_ingred_assemble_20_2_2();
void fix_ingred_assemble_20_2();
void fix_ingred_assemble_20_6_5();
void fix_ingred_assemble_20_6_6();
void fix_ingred_assemble_20_6();
void fix_ingred_assemble_20();
static outlet_t *cgc_get_outlet_by_id(uint32_t outlet_id)
{
if (fix_ingred_enable){ fix_ingred_assemble_20(); };
    outlet_t* o;
    o = (0);
    int8_t breakers_installed_cnt;
    breakers_installed_cnt = cgc_get_number_of_breakers_installed_in_load_center ( );
    if (0 > breakers_installed_cnt) {
 return (0);
    }
    for (uint32_t breaker_id = 0; breaker_id < breakers_installed_cnt; breaker_id++) {
 list_t* outlet_list;
 {
     uint32_t tlv1;
     tlv1 = breaker_id;
     outlet_list = cgc_get_outlet_list_on_breaker(tlv1);
 }
 node_t* outlet_node_ptr;
 {
     list_t* tlv2;
     tlv2 = outlet_list;
     outlet_node_ptr = cgc_get_first_node(tlv2);
 }
 while (cgc_get_list_tail(outlet_list) != outlet_node_ptr) {
     o = (outlet_t *) outlet_node_ptr->data;
     if (outlet_id == o->id) {
  break;
     } else {
  o = (0);
     }
     outlet_node_ptr = outlet_node_ptr->next;
 }
    }
    return o;
}

void fix_ingred_assemble_21_2_2();
void fix_ingred_assemble_21_2();
void fix_ingred_assemble_21();
static n_way_splitter_t *cgc_get_splitter_by_id(uint32_t splitter_id)
{
if (fix_ingred_enable){ fix_ingred_assemble_21(); };
    n_way_splitter_t* s;
    s = (0);
    int8_t breakers_installed_cnt;
    breakers_installed_cnt = cgc_get_number_of_breakers_installed_in_load_center ( );
    if (0 > breakers_installed_cnt) {
 return (0);
    }
    for (uint32_t breaker_id = 0; breaker_id < breakers_installed_cnt; breaker_id++) {
 list_t* outlet_list;
 {
     uint32_t tlv1;
     tlv1 = breaker_id;
     outlet_list = cgc_get_outlet_list_on_breaker(tlv1);
 }
 node_t* outlet_node_ptr;
 {
     list_t* tlv2;
     tlv2 = outlet_list;
     outlet_node_ptr = cgc_get_first_node(tlv2);
 }
 while (cgc_get_list_tail(outlet_list) != outlet_node_ptr) {
     outlet_t* o;
     o = ( outlet_t * ) outlet_node_ptr -> data;
     {
         outlet_t* tlv4;
         tlv4 = o;
         uint32_t tlv3;
         tlv3 = splitter_id;
         s = cgc_search_outlet_for_splitter_id(tlv4,tlv3);
     }
     if ((0) != s) {
  break;
     }
     outlet_node_ptr = outlet_node_ptr->next;
 }
    }
    return s;
}

void fix_ingred_assemble_22();
static light_string_t *cgc_get_light_string_by_id(uint32_t light_string_id)
{
if (fix_ingred_enable){ fix_ingred_assemble_22(); };
    light_string_t* ls;
    ls = (0);
    int8_t breakers_installed_cnt;
    breakers_installed_cnt = cgc_get_number_of_breakers_installed_in_load_center ( );
    if (0 > breakers_installed_cnt) {
 return (0);
    }
    for (uint32_t breaker_id = 0; breaker_id < breakers_installed_cnt; breaker_id++) {
 list_t* outlet_list;
 {
     uint32_t tlv1;
     tlv1 = breaker_id;
     outlet_list = cgc_get_outlet_list_on_breaker(tlv1);
 }
 node_t* outlet_node_ptr;
 {
     list_t* tlv2;
     tlv2 = outlet_list;
     outlet_node_ptr = cgc_get_first_node(tlv2);
 }
 while (cgc_get_list_tail(outlet_list) != outlet_node_ptr) {
     outlet_t* o;
     o = ( outlet_t * ) outlet_node_ptr -> data;
     {
         outlet_t* tlv4;
         tlv4 = o;
         uint32_t tlv3;
         tlv3 = light_string_id;
         ls = cgc_search_outlet_for_light_string_id(tlv4,tlv3);
     }
     if ((0) != ls) {
  break;
     }
     outlet_node_ptr = outlet_node_ptr->next;
 }
    }
    return ls;
}

void fix_ingred_assemble_23_1_0();
void fix_ingred_assemble_23_1();
void fix_ingred_assemble_23();
static uint8_t cgc_breaker_id_is_installed(uint32_t breaker_id)
{
if (fix_ingred_enable){ fix_ingred_assemble_23(); };
    static breaker_t* tlv1;
    {
        uint32_t tlv2;
        tlv2 = breaker_id;
        tlv1 = cgc_get_breaker_by_id(tlv2);
    }
    if ((0) == tlv1) {
 return FALSE;
    } else {
 return TRUE;
    }
}

void fix_ingred_assemble_24();
static list_t *cgc_get_outlet_list_on_breaker(uint32_t breaker_id)
{
if (fix_ingred_enable){ fix_ingred_assemble_24(); };
    static uint8_t tlv1;
    {
        uint32_t tlv2;
        tlv2 = breaker_id;
        tlv1 = cgc_breaker_id_is_installed(tlv2);
    }
    if (FALSE == tlv1) {
 return (0);
    }
    breaker_t* b;
    {
        uint32_t tlv3;
        tlv3 = breaker_id;
        b = cgc_get_breaker_by_id(tlv3);
    }
    return b->outlets;
}

void fix_ingred_assemble_25();
int32_t cgc_get_count_outlets_on_breaker(uint32_t breaker_id)
{
if (fix_ingred_enable){ fix_ingred_assemble_25(); };
    static uint8_t tlv1;
    {
        uint32_t tlv2;
        tlv2 = breaker_id;
        tlv1 = cgc_breaker_id_is_installed(tlv2);
    }
    if (FALSE == tlv1) {
 return ERR_INVALID_BREAKER_ID;
    }
    breaker_t* b;
    {
        uint32_t tlv3;
        tlv3 = breaker_id;
        b = cgc_get_breaker_by_id(tlv3);
    }
    return b->outlets->count;
}

void fix_ingred_assemble_26();
int8_t cgc_get_amp_rating_of_breaker(uint32_t breaker_id)
{
if (fix_ingred_enable){ fix_ingred_assemble_26(); };
    static uint8_t tlv1;
    {
        uint32_t tlv2;
        tlv2 = breaker_id;
        tlv1 = cgc_breaker_id_is_installed(tlv2);
    }
    if (FALSE == tlv1) {
 return ERR_INVALID_BREAKER_ID;
    }
    breaker_t* b;
    {
        uint32_t tlv3;
        tlv3 = breaker_id;
        b = cgc_get_breaker_by_id(tlv3);
    }
    return b->amp_rating;
}

void fix_ingred_assemble_27();
int8_t cgc_get_amp_rating_of_outlet(uint32_t outlet_id)
{
if (fix_ingred_enable){ fix_ingred_assemble_27(); };
    outlet_t* o;
    {
        uint32_t tlv1;
        tlv1 = outlet_id;
        o = cgc_get_outlet_by_id(tlv1);
    }
    if ((0) == o) {
 return ERR_INVALID_OUTLET_ID;
    } else {
 return o->amp_rating;
    }
}

void fix_ingred_assemble_28();
int8_t cgc_get_amp_rating_of_splitter(uint32_t splitter_id)
{
if (fix_ingred_enable){ fix_ingred_assemble_28(); };
    n_way_splitter_t* s;
    {
        uint32_t tlv1;
        tlv1 = splitter_id;
        s = cgc_get_splitter_by_id(tlv1);
    }
    if ((0) == s) {
 return ERR_INVALID_SPLITTER_ID;
    } else {
 return s->total_amp_rating;
    }
}

void fix_ingred_assemble_29();
float cgc_get_amp_rating_of_light_string(uint32_t light_string_id)
{
if (fix_ingred_enable){ fix_ingred_assemble_29(); };
    light_string_t* s;
    {
        uint32_t tlv1;
        tlv1 = light_string_id;
        s = cgc_get_light_string_by_id(tlv1);
    }
    if ((0) == s) {
 return (float) ERR_INVALID_LIGHT_STRING_ID;
    } else {
 return cgc_get_max_amps_of_light_string();
    }
}

void fix_ingred_assemble_30();
int8_t cgc_get_amp_rating_of_receptacle(uint32_t receptacle_id)
{
if (fix_ingred_enable){ fix_ingred_assemble_30(); };
    receptacle_t* r;
    {
        uint32_t tlv1;
        tlv1 = receptacle_id;
        r = cgc_get_receptacle_by_id(tlv1);
    }
    if ((0) == r) {
 return ERR_INVALID_RECEPTACLE_ID;
    } else {
 return r->amp_rating;
    }
}

void fix_ingred_assemble_31();
int8_t cgc_get_number_of_breakers_installed_in_load_center()
{
if (fix_ingred_enable){ fix_ingred_assemble_31(); };
    static uint8_t tlv1;
    tlv1 = cgc_load_center_is_created ( );
    if (FALSE == tlv1) {
 return ERR_E_MODEL_NOT_EXISTS;
    }
    return e_model->breakers_installed_cnt;
}

void fix_ingred_assemble_32();
int8_t cgc_get_total_breaker_space_count()
{
if (fix_ingred_enable){ fix_ingred_assemble_32(); };
    static uint8_t tlv1;
    tlv1 = cgc_load_center_is_created ( );
    if (FALSE == tlv1) {
 return ERR_E_MODEL_NOT_EXISTS;
    }
    return e_model->breaker_spaces;
}

void fix_ingred_assemble_33();
int32_t cgc_get_amp_rating_of_load_center()
{
if (fix_ingred_enable){ fix_ingred_assemble_33(); };
    static uint8_t tlv1;
    tlv1 = cgc_load_center_is_created ( );
    if (FALSE == tlv1) {
 return ERR_E_MODEL_NOT_EXISTS;
    }
    return e_model->amp_rating;
}

void fix_ingred_assemble_34_0_0();
void fix_ingred_assemble_34_0();
void fix_ingred_assemble_34_3_1();
void fix_ingred_assemble_34_3_2();
void fix_ingred_assemble_34_3();
void fix_ingred_assemble_34_4_0();
void fix_ingred_assemble_34_4();
void fix_ingred_assemble_34();
float cgc_get_total_amp_load_on_load_center()
{
if (fix_ingred_enable){ fix_ingred_assemble_34(); };
    static uint8_t tlv1;
    tlv1 = cgc_load_center_is_created ( );
    if (FALSE == tlv1) {
 return ERR_E_MODEL_NOT_EXISTS;
    }

    float total_amp_load;
    total_amp_load = 0.0;
    int32_t breakers_installed_cnt;
    breakers_installed_cnt = cgc_get_number_of_breakers_installed_in_load_center ( );
    if (0 > breakers_installed_cnt) {
 return breakers_installed_cnt;
    }
    for (uint8_t idx = 0; idx < breakers_installed_cnt; idx++) {
 {
     uint32_t tlv2;
     tlv2 = idx;
     total_amp_load += cgc_get_total_amp_load_on_breaker_by_breaker_id(tlv2);
 }
    }
    return total_amp_load;
}

void fix_ingred_assemble_35();
float cgc_get_total_amp_load_on_breaker_by_breaker_id(uint32_t breaker_id)
{
if (fix_ingred_enable){ fix_ingred_assemble_35(); };
    static uint8_t tlv1;
    {
        uint32_t tlv2;
        tlv2 = breaker_id;
        tlv1 = cgc_breaker_id_is_installed(tlv2);
    }
    if (FALSE == tlv1) {
 return ERR_INVALID_BREAKER_ID;
    }

    float total_amp_load;
    total_amp_load = 0.0;
    list_t* outlet_list;
    {
        uint32_t tlv3;
        tlv3 = breaker_id;
        outlet_list = cgc_get_outlet_list_on_breaker(tlv3);
    }
    node_t* outlet_node_ptr;
    {
        list_t* tlv4;
        tlv4 = outlet_list;
        outlet_node_ptr = cgc_get_first_node(tlv4);
    }
    while (cgc_get_list_tail(outlet_list) != outlet_node_ptr) {
 {
     outlet_t* tlv5;
     tlv5 = ( outlet_t * ) outlet_node_ptr -> data;
     total_amp_load += cgc_get_total_amp_load_on_outlet_by_outlet_va(tlv5);
 }
 outlet_node_ptr = outlet_node_ptr->next;
    }
    return total_amp_load;
}

void fix_ingred_assemble_36();
static float cgc_get_total_amp_load_on_outlet_by_outlet_va(outlet_t * outlet)
{
if (fix_ingred_enable){ fix_ingred_assemble_36(); };
    float total_amp_load;
    total_amp_load = 0.0;
    {
        receptacle_t* tlv1;
        tlv1 = & ( outlet -> r1 );
        total_amp_load += cgc_get_total_amp_load_on_receptacle_by_receptacle_va(tlv1);
    }
    {
        receptacle_t* tlv2;
        tlv2 = & ( outlet -> r2 );
        total_amp_load += cgc_get_total_amp_load_on_receptacle_by_receptacle_va(tlv2);
    }
    return total_amp_load;
}

void fix_ingred_assemble_37();
float cgc_get_total_amp_load_on_outlet_by_outlet_id(uint32_t outlet_id)
{
if (fix_ingred_enable){ fix_ingred_assemble_37(); };
    outlet_t* o;
    {
        uint32_t tlv1;
        tlv1 = outlet_id;
        o = cgc_get_outlet_by_id(tlv1);
    }
    if ((0) == o) {
 return ERR_INVALID_OUTLET_ID;
    } else {
 return cgc_get_total_amp_load_on_outlet_by_outlet_va(o);
    }
}

void fix_ingred_assemble_38();
static float cgc_get_total_amp_load_on_receptacle_by_receptacle_va(receptacle_t * receptacle)
{
if (fix_ingred_enable){ fix_ingred_assemble_38(); };
    float total_amp_load;
    total_amp_load = 0.0;
    static LOAD_TYPE_T tlv1;
    {
        receptacle_t* tlv3;
        tlv3 = receptacle;
        tlv1 = cgc_get_receptacle_load_type(tlv3);
    }
    if (SPLITTER == tlv1) {
 {
     n_way_splitter_t* tlv4;
     tlv4 = ( n_way_splitter_t * ) receptacle -> load;
     total_amp_load = cgc_get_total_amp_load_on_splitter_by_splitter_va(tlv4);
 }
    } else {
 static LOAD_TYPE_T tlv2;
 {
     receptacle_t* tlv5;
     tlv5 = receptacle;
     tlv2 = cgc_get_receptacle_load_type(tlv5);
 }
 if (LIGHT_STRING == tlv2) {
     {
         light_string_t* tlv6;
         tlv6 = ( light_string_t * ) receptacle -> load;
         total_amp_load = cgc_get_total_amp_load_on_light_string_by_light_string_va(tlv6);
     }
 }
    }

    return total_amp_load;
}

void fix_ingred_assemble_39();
float cgc_get_total_amp_load_on_receptacle_by_receptacle_id(uint32_t receptacle_id)
{
if (fix_ingred_enable){ fix_ingred_assemble_39(); };
    receptacle_t* r;
    {
        uint32_t tlv1;
        tlv1 = receptacle_id;
        r = cgc_get_receptacle_by_id(tlv1);
    }
    if ((0) == r) {
 return ERR_INVALID_RECEPTACLE_ID;
    } else {
 return cgc_get_total_amp_load_on_receptacle_by_receptacle_va(r);
    }
}

void fix_ingred_assemble_40();
static float cgc_get_total_amp_load_on_splitter_by_splitter_va(n_way_splitter_t * splitter)
{
if (fix_ingred_enable){ fix_ingred_assemble_40(); };
    float total_amp_load;
    total_amp_load = 0.0;
    for (int idx = 0; idx < splitter->receptacle_count; idx++) {
 {
     receptacle_t* tlv1;
     tlv1 = & ( splitter -> receptacles [ idx ] );
     total_amp_load += cgc_get_total_amp_load_on_receptacle_by_receptacle_va(tlv1);
 }
    }
    return total_amp_load;
}

void fix_ingred_assemble_41();
float cgc_get_total_amp_load_on_splitter_by_splitter_id(uint32_t splitter_id)
{
if (fix_ingred_enable){ fix_ingred_assemble_41(); };
    n_way_splitter_t* s;
    {
        uint32_t tlv1;
        tlv1 = splitter_id;
        s = cgc_get_splitter_by_id(tlv1);
    }
    if ((0) == s) {
 return ERR_INVALID_SPLITTER_ID;
    } else {
 return cgc_get_total_amp_load_on_splitter_by_splitter_va(s);
    }
}

void fix_ingred_assemble_42_0_0();
void fix_ingred_assemble_42_0();
void fix_ingred_assemble_42_1_0();
void fix_ingred_assemble_42_1();
void fix_ingred_assemble_42();
static float cgc_get_total_amp_load_on_light_string_by_light_string_va(light_string_t * light_string)
{
if (fix_ingred_enable){ fix_ingred_assemble_42(); };
    float total_amp_load;
    total_amp_load = 0.0;
    {
        float tlv1;
        tlv1 = light_string -> total_wattage;
        total_amp_load += cgc_convert_watts_to_amps(tlv1);
    }
    {
        receptacle_t* tlv2;
        tlv2 = & ( light_string -> receptacle );
        total_amp_load += cgc_get_total_amp_load_on_receptacle_by_receptacle_va(tlv2);
    }
    return total_amp_load;
}

void fix_ingred_assemble_43();
float cgc_get_total_amp_load_on_light_string_by_light_string_id(uint32_t light_string_id)
{
if (fix_ingred_enable){ fix_ingred_assemble_43(); };
    light_string_t* ls;
    {
        uint32_t tlv1;
        tlv1 = light_string_id;
        ls = cgc_get_light_string_by_id(tlv1);
    }
    if ((0) == ls) {
 return ERR_INVALID_LIGHT_STRING_ID;
    } else {
 return cgc_get_total_amp_load_on_light_string_by_light_string_va(ls);
    }
}

void fix_ingred_assemble_44_3_0();
void fix_ingred_assemble_44_3_1();
void fix_ingred_assemble_44_3();
void fix_ingred_assemble_44();
static float cgc_get_max_receptacle_amp_load_on_outlet_by_outlet_va(outlet_t * outlet)
{
if (fix_ingred_enable){ fix_ingred_assemble_44(); };
    float r1_load;
    {
        receptacle_t* tlv1;
        tlv1 = & ( outlet -> r1 );
        r1_load = cgc_get_total_amp_load_on_receptacle_by_receptacle_va(tlv1);
    }
    float r2_load;
    {
        receptacle_t* tlv2;
        tlv2 = & ( outlet -> r2 );
        r2_load = cgc_get_total_amp_load_on_receptacle_by_receptacle_va(tlv2);
    }
    if (r1_load > r2_load) {
 return r1_load;
    } else {
 return r2_load;
    }
}

void fix_ingred_assemble_45();
float cgc_get_max_receptacle_amp_load_on_outlet_by_outlet_id(uint32_t outlet_id)
{
if (fix_ingred_enable){ fix_ingred_assemble_45(); };
    outlet_t* o;
    {
        uint32_t tlv1;
        tlv1 = outlet_id;
        o = cgc_get_outlet_by_id(tlv1);
    }
    if ((0) == o) {
 return ERR_INVALID_OUTLET_ID;
    } else {
 return cgc_get_max_receptacle_amp_load_on_outlet_by_outlet_va(o);
    }
}

void fix_ingred_assemble_46_0_0();
void fix_ingred_assemble_46_0();
void fix_ingred_assemble_46_3_0();
void fix_ingred_assemble_46_3_6();
void fix_ingred_assemble_46_3();
void fix_ingred_assemble_46();
static float cgc_get_max_receptacle_amp_load_on_splitter_by_splitter_va(n_way_splitter_t * splitter)
{
if (fix_ingred_enable){ fix_ingred_assemble_46(); };
    float max_amp_load;
    max_amp_load = 0.0;
    float tmp_amp_load;
    tmp_amp_load = 0.0;
    for (int idx = 0; idx < splitter->receptacle_count; idx++) {
 {
     receptacle_t* tlv1;
     tlv1 = & ( splitter -> receptacles [ idx ] );
     tmp_amp_load = cgc_get_total_amp_load_on_receptacle_by_receptacle_va(tlv1);
 }
 if (tmp_amp_load > max_amp_load) {
     max_amp_load = tmp_amp_load;
 }
    }
    return max_amp_load;
}

void fix_ingred_assemble_47();
float cgc_get_max_receptacle_amp_load_on_splitter_by_splitter_id(uint32_t splitter_id)
{
if (fix_ingred_enable){ fix_ingred_assemble_47(); };
    n_way_splitter_t* s;
    {
        uint32_t tlv1;
        tlv1 = splitter_id;
        s = cgc_get_splitter_by_id(tlv1);
    }
    if ((0) == s) {
 return ERR_INVALID_SPLITTER_ID;
    } else {
 return cgc_get_max_receptacle_amp_load_on_splitter_by_splitter_va(s);
    }
}

void fix_ingred_assemble_48();
int8_t cgc_init_electric_model(LOAD_CENTER_MODELS_T model_id)
{
if (fix_ingred_enable){ fix_ingred_assemble_48(); };
    static uint8_t tlv1;
    tlv1 = cgc_load_center_is_created ( );
    if (TRUE == tlv1) {
 return ERR_E_MODEL_EXISTS;
    }
    {
        LOAD_CENTER_MODELS_T tlv2;
        tlv2 = model_id;
        e_model = cgc_get_new_load_center_by_model_id(tlv2);
    }
    if ((0) == e_model) {
 return ERR_INVALID_MODEL_ID;
    } else {
 return 0;
    }
}

void fix_ingred_assemble_49_3_2();
void fix_ingred_assemble_49_3();
void fix_ingred_assemble_49();
int8_t cgc_add_breaker_to_load_center(CIRCUIT_MODELS_T model_id, assemble_result_t * result)
{
if (fix_ingred_enable){ fix_ingred_assemble_49(); };
    static uint8_t tlv1;
    tlv1 = cgc_load_center_is_created ( );
    if (FALSE == tlv1) {
 return ERR_E_MODEL_NOT_EXISTS;
    }
    static int8_t tlv2;
    tlv2 = cgc_load_center_breaker_spaces_are_full ( );
    if (TRUE == tlv2) {
 return ERR_BREAKER_SPACES_FULL;
    }
    breaker_t* breaker_space;
    breaker_space = & ( e_model -> breakers [ e_model -> breakers_installed_cnt ] );
    int8_t tlv3;
    {
        CIRCUIT_MODELS_T tlv6;
        tlv6 = model_id;
        breaker_t* tlv5;
        tlv5 = breaker_space;
        uint8_t tlv4;
        tlv4 = e_model -> breakers_installed_cnt;
        tlv3 = cgc_get_new_breaker_by_model_id(tlv6,tlv5,tlv4);
    }
    if (-1 == tlv3) {
 return ERR_INVALID_MODEL_ID;
    }
    result->object_id = e_model->breakers_installed_cnt++;
    return 0;
}

void fix_ingred_assemble_50_2_0();
void fix_ingred_assemble_50_2();
void fix_ingred_assemble_50_7_0();
void fix_ingred_assemble_50_7_1();
void fix_ingred_assemble_50_7();
void fix_ingred_assemble_50();
int8_t cgc_add_outlet_to_breaker(CIRCUIT_MODELS_T outlet_model_id, uint32_t breaker_id, assemble_result_t * result)
{
if (fix_ingred_enable){ fix_ingred_assemble_50(); };
    static uint8_t tlv1;
    tlv1 = cgc_load_center_is_created ( );
    if (FALSE == tlv1) {
 return ERR_E_MODEL_NOT_EXISTS;
    }
    breaker_t* breaker;
    {
        uint32_t tlv2;
        tlv2 = breaker_id;
        breaker = cgc_get_breaker_by_id(tlv2);
    }
    if ((0) == breaker) {
 return ERR_INVALID_BREAKER_ID;
    }
    outlet_t* o;
    {
        CIRCUIT_MODELS_T tlv3;
        tlv3 = outlet_model_id;
        o = cgc_get_new_outlet_by_model_id(tlv3);
    }
    if ((0) == o) {
 return ERR_INVALID_MODEL_ID;
    }

    if (o->amp_rating > breaker->amp_rating) {
 {
     void* tlv5;
     tlv5 = ( void * ) o;
     cgc_size_t tlv4;
     tlv4 = sizeof ( outlet_t );
     cgc_deallocate(tlv5,tlv4);
 }
 return ERR_OUTLET_AMPS_EXCEED_BREAKER_AMPS;
    }
    result->object_id = o->id;
    result->receptacle_id[0] = o->r1.id;
    result->receptacle_id[1] = o->r2.id;
    result->receptacle_ids_assigned_cnt = 2;
    return cgc_list_append(breaker->outlets, cgc_node_create((void *) o));
}

void fix_ingred_assemble_51_8_6();
void fix_ingred_assemble_51_8_7();
void fix_ingred_assemble_51_8();
void fix_ingred_assemble_51();
int8_t cgc_add_n_way_splitter_to_receptacle(SPLITTER_MODELS_T splitter_model_id, uint32_t receptacle_id, assemble_result_t * result)
{
if (fix_ingred_enable){ fix_ingred_assemble_51(); };
    static uint8_t tlv1;
    tlv1 = cgc_load_center_is_created ( );
    if (FALSE == tlv1) {
 return ERR_E_MODEL_NOT_EXISTS;
    }
    receptacle_t* r;
    {
        uint32_t tlv3;
        tlv3 = receptacle_id;
        r = cgc_get_receptacle_by_id(tlv3);
    }
    if ((0) == r) {
 return ERR_INVALID_RECEPTACLE_ID;
    }
    static int8_t tlv2;
    {
        receptacle_t* tlv4;
        tlv4 = r;
        tlv2 = cgc_receptacle_is_loaded(tlv4);
    }
    if (TRUE == tlv2) {
 return ERR_RECEPTACLE_FULL;
    }
    n_way_splitter_t* s;
    {
        SPLITTER_MODELS_T tlv5;
        tlv5 = splitter_model_id;
        s = cgc_get_new_n_way_splitter_by_model_id(tlv5);
    }
    if ((0) == s) {
 return ERR_INVALID_MODEL_ID;
    }

    r->load_type = SPLITTER;
    r->load = (void *) s;
    r->amp_rating = s->total_amp_rating;

    result->object_id = s->id;
    result->receptacle_ids_assigned_cnt = s->receptacle_count;
    for (int i = 0; i < s->receptacle_count; i++) {
 result->receptacle_id[i] = s->receptacles[i].id;
    }
    return 0;
}

void fix_ingred_assemble_52();
int8_t cgc_add_light_string_to_receptacle(LIGHT_STRING_MODELS_T light_string_model_id, uint32_t receptacle_id, assemble_result_t * result)
{
if (fix_ingred_enable){ fix_ingred_assemble_52(); };
    static uint8_t tlv1;
    tlv1 = cgc_load_center_is_created ( );
    if (FALSE == tlv1) {
 return ERR_E_MODEL_NOT_EXISTS;
    }
    receptacle_t* r;
    {
        uint32_t tlv3;
        tlv3 = receptacle_id;
        r = cgc_get_receptacle_by_id(tlv3);
    }
    if ((0) == r) {
 return ERR_INVALID_RECEPTACLE_ID;
    }
    static int8_t tlv2;
    {
        receptacle_t* tlv4;
        tlv4 = r;
        tlv2 = cgc_receptacle_is_loaded(tlv4);
    }
    if (TRUE == tlv2) {
 return ERR_RECEPTACLE_FULL;
    }
    light_string_t* ls;
    {
        LIGHT_STRING_MODELS_T tlv5;
        tlv5 = light_string_model_id;
        ls = cgc_get_new_light_string_by_model_id(tlv5);
    }
    if ((0) == ls) {
 return ERR_INVALID_MODEL_ID;
    }

    r->load_type = LIGHT_STRING;
    r->load = (void *) ls;

    result->object_id = ls->id;
    result->receptacle_ids_assigned_cnt = 1;
    result->receptacle_id[0] = ls->receptacle.id;
    return 0;
}

void fix_ingred_assemble_0(){
}
void fix_ingred_assemble_1(){
}
void fix_ingred_assemble_2(){
}
void fix_ingred_assemble_3(){
}
void fix_ingred_assemble_4(){
}
void fix_ingred_assemble_5_1_2(){
uint32_t receptacle_id;
    bzero(&receptacle_id,sizeof(uint32_t));
receptacle_t receptacle_ref;
    bzero(&receptacle_ref,1*sizeof(receptacle_t));
receptacle_t * receptacle = &receptacle_ref;
    {uint32_t tlv4; tlv4 = (uint32_t)(receptacle_id); }
    {uint32_t tlv7; tlv7 = (uint32_t)(receptacle_id); }
}
void fix_ingred_assemble_5_1_3(){
uint32_t receptacle_id;
    bzero(&receptacle_id,sizeof(uint32_t));
receptacle_t receptacle_ref;
    bzero(&receptacle_ref,1*sizeof(receptacle_t));
receptacle_t * receptacle = &receptacle_ref;
    {uint32_t tlv4; tlv4 = (uint32_t)(receptacle -> id); }
    {uint32_t tlv7; tlv7 = (uint32_t)(receptacle -> id); }
}
void fix_ingred_assemble_5_1(){
fix_ingred_assemble_5_1_2();
fix_ingred_assemble_5_1_3();
}
void fix_ingred_assemble_5(){
fix_ingred_assemble_5_1();
}
void fix_ingred_assemble_6_1_1(){
uint32_t receptacle_id;
    bzero(&receptacle_id,sizeof(uint32_t));
    {uint32_t tlv1; tlv1 = (uint32_t)(receptacle_id); }
    {uint32_t tlv3; tlv3 = (uint32_t)(receptacle_id); }
}
void fix_ingred_assemble_6_1(){
fix_ingred_assemble_6_1_1();
}
void fix_ingred_assemble_6(){
fix_ingred_assemble_6_1();
}
void fix_ingred_assemble_7_1_1(){
uint32_t idx;
    bzero(&idx,sizeof(uint32_t));
n_way_splitter_t splitter_ref;
    bzero(&splitter_ref,1*sizeof(n_way_splitter_t));
n_way_splitter_t * splitter = &splitter_ref;
    {uint32_t tlv1; tlv1 = (uint32_t)(idx); }
}
void fix_ingred_assemble_7_1_2(){
uint32_t idx;
    bzero(&idx,sizeof(uint32_t));
n_way_splitter_t splitter_ref;
    bzero(&splitter_ref,1*sizeof(n_way_splitter_t));
n_way_splitter_t * splitter = &splitter_ref;
    {uint32_t tlv1; tlv1 = (uint32_t)(splitter -> receptacle_count); }
}
void fix_ingred_assemble_7_1(){
fix_ingred_assemble_7_1_1();
fix_ingred_assemble_7_1_2();
}
void fix_ingred_assemble_7(){
fix_ingred_assemble_7_1();
}
void fix_ingred_assemble_8(){
}
void fix_ingred_assemble_9_3_1(){
uint32_t splitter_id;
    bzero(&splitter_id,sizeof(uint32_t));
    {uint32_t tlv4; tlv4 = (uint32_t)(splitter_id); }
    {uint32_t tlv7; tlv7 = (uint32_t)(splitter_id); }
}
void fix_ingred_assemble_9_3(){
fix_ingred_assemble_9_3_1();
}
void fix_ingred_assemble_9(){
fix_ingred_assemble_9_3();
}
void fix_ingred_assemble_10(){
}
void fix_ingred_assemble_11_1_1(){
uint32_t splitter_id;
    bzero(&splitter_id,sizeof(uint32_t));
    {uint32_t tlv1; tlv1 = (uint32_t)(splitter_id); }
    {uint32_t tlv3; tlv3 = (uint32_t)(splitter_id); }
}
void fix_ingred_assemble_11_1(){
fix_ingred_assemble_11_1_1();
}
void fix_ingred_assemble_11(){
fix_ingred_assemble_11_1();
}
void fix_ingred_assemble_12_1_3(){
n_way_splitter_t splitter_ref;
    bzero(&splitter_ref,1*sizeof(n_way_splitter_t));
n_way_splitter_t * splitter = &splitter_ref;
    {uint32_t tlv1; tlv1 = (uint32_t)(splitter -> id); }
}
void fix_ingred_assemble_12_1(){
fix_ingred_assemble_12_1_3();
}
void fix_ingred_assemble_12_3_1(){
uint8_t idx;
    bzero(&idx,sizeof(uint8_t));
n_way_splitter_t splitter_ref;
    bzero(&splitter_ref,1*sizeof(n_way_splitter_t));
n_way_splitter_t * splitter = &splitter_ref;
    {uint32_t tlv1; tlv1 = (uint32_t)(idx); }
}
void fix_ingred_assemble_12_3_2(){
uint8_t idx;
    bzero(&idx,sizeof(uint8_t));
n_way_splitter_t splitter_ref;
    bzero(&splitter_ref,1*sizeof(n_way_splitter_t));
n_way_splitter_t * splitter = &splitter_ref;
    {uint32_t tlv1; tlv1 = (uint32_t)(splitter -> receptacle_count); }
}
void fix_ingred_assemble_12_3(){
fix_ingred_assemble_12_3_1();
fix_ingred_assemble_12_3_2();
}
void fix_ingred_assemble_12(){
fix_ingred_assemble_12_1();
fix_ingred_assemble_12_3();
}
void fix_ingred_assemble_13_3_1(){
uint32_t light_string_id;
    bzero(&light_string_id,sizeof(uint32_t));
    {uint32_t tlv4; tlv4 = (uint32_t)(light_string_id); }
    {uint32_t tlv7; tlv7 = (uint32_t)(light_string_id); }
}
void fix_ingred_assemble_13_3(){
fix_ingred_assemble_13_3_1();
}
void fix_ingred_assemble_13(){
fix_ingred_assemble_13_3();
}
void fix_ingred_assemble_14_1_2(){
uint32_t light_string_id;
    bzero(&light_string_id,sizeof(uint32_t));
light_string_t light_string_ref;
    bzero(&light_string_ref,1*sizeof(light_string_t));
light_string_t * light_string = &light_string_ref;
    {uint32_t tlv1; tlv1 = (uint32_t)(light_string_id); }
}
void fix_ingred_assemble_14_1_3(){
uint32_t light_string_id;
    bzero(&light_string_id,sizeof(uint32_t));
light_string_t light_string_ref;
    bzero(&light_string_ref,1*sizeof(light_string_t));
light_string_t * light_string = &light_string_ref;
    {uint32_t tlv1; tlv1 = (uint32_t)(light_string -> id); }
}
void fix_ingred_assemble_14_1(){
fix_ingred_assemble_14_1_2();
fix_ingred_assemble_14_1_3();
}
void fix_ingred_assemble_14(){
fix_ingred_assemble_14_1();
}
void fix_ingred_assemble_15_1_1(){
uint32_t light_string_id;
    bzero(&light_string_id,sizeof(uint32_t));
    {uint32_t tlv3; tlv3 = (uint32_t)(light_string_id); }
}
void fix_ingred_assemble_15_1(){
fix_ingred_assemble_15_1_1();
}
void fix_ingred_assemble_15(){
fix_ingred_assemble_15_1();
}
void fix_ingred_assemble_16_1_2(){
n_way_splitter_t s_ref;
    bzero(&s_ref,1*sizeof(n_way_splitter_t));
n_way_splitter_t * s = &s_ref;
    {uint32_t tlv1; tlv1 = (uint32_t)(s -> receptacle_count); }
}
void fix_ingred_assemble_16_1(){
fix_ingred_assemble_16_1_2();
}
void fix_ingred_assemble_16(){
fix_ingred_assemble_16_1();
}
void fix_ingred_assemble_17_1_0(){
uint32_t breaker_id;
    bzero(&breaker_id,sizeof(uint32_t));
    {uint32_t tlv1; tlv1 = (uint32_t)(breaker_id); }
    {uint32_t tlv3; tlv3 = (uint32_t)(breaker_id); }
}
void fix_ingred_assemble_17_1(){
fix_ingred_assemble_17_1_0();
}
void fix_ingred_assemble_17(){
fix_ingred_assemble_17_1();
}
void fix_ingred_assemble_18_2_3(){
uint32_t breaker_idx;
    bzero(&breaker_idx,sizeof(uint32_t));
    {uint32_t tlv3; tlv3 = (uint32_t)(breaker_idx); }
    {uint32_t tlv2; tlv2 = (uint32_t)(breaker_idx); }
}
void fix_ingred_assemble_18_2_4(){
uint32_t breaker_idx;
    bzero(&breaker_idx,sizeof(uint32_t));
    {uint32_t tlv3; tlv3 = (uint32_t)(e_model -> breakers_installed_cnt); }
    {uint32_t tlv2; tlv2 = (uint32_t)(e_model -> breakers_installed_cnt); }
}
void fix_ingred_assemble_18_2(){
fix_ingred_assemble_18_2_3();
fix_ingred_assemble_18_2_4();
}
void fix_ingred_assemble_18_3_1(){
uint32_t receptacle_id;
    bzero(&receptacle_id,sizeof(uint32_t));
    {uint32_t tlv2; tlv2 = (uint32_t)(receptacle_id); }
}
void fix_ingred_assemble_18_3(){
fix_ingred_assemble_18_3_1();
}
void fix_ingred_assemble_18(){
fix_ingred_assemble_18_2();
fix_ingred_assemble_18_3();
}
void fix_ingred_assemble_19(){
}
void fix_ingred_assemble_20_2_2(){
int8_t breakers_installed_cnt;
    bzero(&breakers_installed_cnt,sizeof(int8_t));
    {uint32_t tlv1; tlv1 = (uint32_t)(breakers_installed_cnt); }
}
void fix_ingred_assemble_20_2(){
fix_ingred_assemble_20_2_2();
}
void fix_ingred_assemble_20_6_5(){
uint32_t outlet_id;
    bzero(&outlet_id,sizeof(uint32_t));
outlet_t o_ref;
    bzero(&o_ref,1*sizeof(outlet_t));
outlet_t * o = &o_ref;
    {uint32_t tlv1; tlv1 = (uint32_t)(outlet_id); }
}
void fix_ingred_assemble_20_6_6(){
uint32_t outlet_id;
    bzero(&outlet_id,sizeof(uint32_t));
outlet_t o_ref;
    bzero(&o_ref,1*sizeof(outlet_t));
outlet_t * o = &o_ref;
    {uint32_t tlv1; tlv1 = (uint32_t)(o -> id); }
}
void fix_ingred_assemble_20_6(){
fix_ingred_assemble_20_6_5();
fix_ingred_assemble_20_6_6();
}
void fix_ingred_assemble_20(){
fix_ingred_assemble_20_2();
fix_ingred_assemble_20_6();
}
void fix_ingred_assemble_21_2_2(){
int8_t breakers_installed_cnt;
    bzero(&breakers_installed_cnt,sizeof(int8_t));
    {uint32_t tlv3; tlv3 = (uint32_t)(breakers_installed_cnt); }
}
void fix_ingred_assemble_21_2(){
fix_ingred_assemble_21_2_2();
}
void fix_ingred_assemble_21(){
fix_ingred_assemble_21_2();
}
void fix_ingred_assemble_22(){
}
void fix_ingred_assemble_23_1_0(){
uint32_t breaker_id;
    bzero(&breaker_id,sizeof(uint32_t));
    {uint32_t tlv2; tlv2 = (uint32_t)(breaker_id); }
}
void fix_ingred_assemble_23_1(){
fix_ingred_assemble_23_1_0();
}
void fix_ingred_assemble_23(){
fix_ingred_assemble_23_1();
}
void fix_ingred_assemble_24(){
}
void fix_ingred_assemble_25(){
}
void fix_ingred_assemble_26(){
}
void fix_ingred_assemble_27(){
}
void fix_ingred_assemble_28(){
}
void fix_ingred_assemble_29(){
}
void fix_ingred_assemble_30(){
}
void fix_ingred_assemble_31(){
}
void fix_ingred_assemble_32(){
}
void fix_ingred_assemble_33(){
}
void fix_ingred_assemble_34_0_0(){
    {float total_amp_load; total_amp_load = (float)(0.0); }
}
void fix_ingred_assemble_34_0(){
fix_ingred_assemble_34_0_0();
}
void fix_ingred_assemble_34_3_1(){
uint8_t idx;
    bzero(&idx,sizeof(uint8_t));
int32_t breakers_installed_cnt;
    bzero(&breakers_installed_cnt,sizeof(int32_t));
    {uint32_t tlv2; tlv2 = (uint32_t)(idx); }
}
void fix_ingred_assemble_34_3_2(){
uint8_t idx;
    bzero(&idx,sizeof(uint8_t));
int32_t breakers_installed_cnt;
    bzero(&breakers_installed_cnt,sizeof(int32_t));
    {uint32_t tlv2; tlv2 = (uint32_t)(breakers_installed_cnt); }
}
void fix_ingred_assemble_34_3(){
fix_ingred_assemble_34_3_1();
fix_ingred_assemble_34_3_2();
}
void fix_ingred_assemble_34_4_0(){
uint8_t idx;
    bzero(&idx,sizeof(uint8_t));
    {uint32_t tlv2; tlv2 = (uint32_t)(idx); }
}
void fix_ingred_assemble_34_4(){
fix_ingred_assemble_34_4_0();
}
void fix_ingred_assemble_34(){
fix_ingred_assemble_34_0();
fix_ingred_assemble_34_3();
fix_ingred_assemble_34_4();
}
void fix_ingred_assemble_35(){
}
void fix_ingred_assemble_36(){
}
void fix_ingred_assemble_37(){
}
void fix_ingred_assemble_38(){
}
void fix_ingred_assemble_39(){
}
void fix_ingred_assemble_40(){
}
void fix_ingred_assemble_41(){
}
void fix_ingred_assemble_42_0_0(){
    {float tlv1; tlv1 = (float)(0.0); }
}
void fix_ingred_assemble_42_0(){
fix_ingred_assemble_42_0_0();
}
void fix_ingred_assemble_42_1_0(){
light_string_t light_string_ref;
    bzero(&light_string_ref,1*sizeof(light_string_t));
light_string_t * light_string = &light_string_ref;
    {float total_amp_load; total_amp_load = (float)(light_string -> total_wattage); }
    {float tlv1; tlv1 = (float)(light_string -> total_wattage); }
}
void fix_ingred_assemble_42_1(){
fix_ingred_assemble_42_1_0();
}
void fix_ingred_assemble_42(){
fix_ingred_assemble_42_0();
fix_ingred_assemble_42_1();
}
void fix_ingred_assemble_43(){
}
void fix_ingred_assemble_44_3_0(){
float r1_load;
    bzero(&r1_load,sizeof(float));
float r2_load;
    bzero(&r2_load,sizeof(float));
    {float r2_load; r2_load = (float)(r1_load); }
}
void fix_ingred_assemble_44_3_1(){
float r1_load;
    bzero(&r1_load,sizeof(float));
float r2_load;
    bzero(&r2_load,sizeof(float));
    {float r1_load; r1_load = (float)(r2_load); }
}
void fix_ingred_assemble_44_3(){
fix_ingred_assemble_44_3_0();
fix_ingred_assemble_44_3_1();
}
void fix_ingred_assemble_44(){
fix_ingred_assemble_44_3();
}
void fix_ingred_assemble_45(){
}
void fix_ingred_assemble_46_0_0(){
    {float max_amp_load; max_amp_load = (float)(0.0); }
    {float tmp_amp_load; tmp_amp_load = (float)(0.0); }
}
void fix_ingred_assemble_46_0(){
fix_ingred_assemble_46_0_0();
}
void fix_ingred_assemble_46_3_0(){
float tmp_amp_load;
    bzero(&tmp_amp_load,sizeof(float));
float max_amp_load;
    bzero(&max_amp_load,sizeof(float));
    {float max_amp_load; max_amp_load = (float)(tmp_amp_load); }
}
void fix_ingred_assemble_46_3_6(){
float tmp_amp_load;
    bzero(&tmp_amp_load,sizeof(float));
float max_amp_load;
    bzero(&max_amp_load,sizeof(float));
    {float tmp_amp_load; tmp_amp_load = (float)(max_amp_load); }
}
void fix_ingred_assemble_46_3(){
fix_ingred_assemble_46_3_0();
fix_ingred_assemble_46_3_6();
}
void fix_ingred_assemble_46(){
fix_ingred_assemble_46_0();
fix_ingred_assemble_46_3();
}
void fix_ingred_assemble_47(){
}
void fix_ingred_assemble_48(){
}
void fix_ingred_assemble_49_3_2(){
    {uint8_t tlv4; tlv4 = (uint8_t)(e_model -> breakers_installed_cnt); }
}
void fix_ingred_assemble_49_3(){
fix_ingred_assemble_49_3_2();
}
void fix_ingred_assemble_49(){
fix_ingred_assemble_49_3();
}
void fix_ingred_assemble_50_2_0(){
uint32_t breaker_id;
    bzero(&breaker_id,sizeof(uint32_t));
    {void * tlv5; tlv5 = (void *)(breaker_id); }
    {cgc_size_t tlv4; tlv4 = (cgc_size_t)(breaker_id); }
}
void fix_ingred_assemble_50_2(){
fix_ingred_assemble_50_2_0();
}
void fix_ingred_assemble_50_7_0(){
outlet_t o_ref;
    bzero(&o_ref,1*sizeof(outlet_t));
outlet_t * o = &o_ref;
    {uint32_t tlv2; tlv2 = (uint32_t)(( void * ) o); }
    {void * tlv5; tlv5 = (void *)(( void * ) o); }
    {cgc_size_t tlv4; tlv4 = (cgc_size_t)(( void * ) o); }
}
void fix_ingred_assemble_50_7_1(){
outlet_t o_ref;
    bzero(&o_ref,1*sizeof(outlet_t));
outlet_t * o = &o_ref;
    {uint32_t tlv2; tlv2 = (uint32_t)(sizeof ( outlet_t )); }
    {void * tlv5; tlv5 = (void *)(sizeof ( outlet_t )); }
    {cgc_size_t tlv4; tlv4 = (cgc_size_t)(sizeof ( outlet_t )); }
}
void fix_ingred_assemble_50_7(){
fix_ingred_assemble_50_7_0();
fix_ingred_assemble_50_7_1();
}
void fix_ingred_assemble_50(){
fix_ingred_assemble_50_2();
fix_ingred_assemble_50_7();
}
void fix_ingred_assemble_51_8_6(){
int i;
    bzero(&i,sizeof(int));
n_way_splitter_t s_ref;
    bzero(&s_ref,1*sizeof(n_way_splitter_t));
n_way_splitter_t * s = &s_ref;
    {uint32_t tlv3; tlv3 = (uint32_t)(i); }
}
void fix_ingred_assemble_51_8_7(){
int i;
    bzero(&i,sizeof(int));
n_way_splitter_t s_ref;
    bzero(&s_ref,1*sizeof(n_way_splitter_t));
n_way_splitter_t * s = &s_ref;
    {uint32_t tlv3; tlv3 = (uint32_t)(s -> receptacle_count); }
}
void fix_ingred_assemble_51_8(){
fix_ingred_assemble_51_8_6();
fix_ingred_assemble_51_8_7();
}
void fix_ingred_assemble_51(){
fix_ingred_assemble_51_8();
}
void fix_ingred_assemble_52(){
}
