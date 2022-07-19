# 1 "/home/pdreiter/Data/APR_eval/GenProg/v24.cb_eval/stack_vm.transform.ga/stack_vm/src/stack_vm/src/stack.c"
# 1 "/home/pdreiter/Data/APR_eval/GenProg/v24.cb_eval/stack_vm.transform.ga/stack_vm/build/stack_vm//"
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
# 1 "/home/pdreiter/Data/APR_eval/GenProg/v24.cb_eval/stack_vm.transform.ga/stack_vm/src/stack_vm/src/stack.c"


# 1 "/home/pdreiter/Data/APR_eval/GenProg/v24.cb_eval/stack_vm.transform.ga/stack_vm/src/include/libcgc.h" 1

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
# 122 "/home/pdreiter/Data/APR_eval/GenProg/v24.cb_eval/stack_vm.transform.ga/stack_vm/src/include/libcgc.h"
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
# 4 "/home/pdreiter/Data/APR_eval/GenProg/v24.cb_eval/stack_vm.transform.ga/stack_vm/src/stack_vm/src/stack.c" 2
# 1 "/home/pdreiter/Data/APR_eval/GenProg/v24.cb_eval/stack_vm.transform.ga/stack_vm/src/stack_vm/lib/cgc_libc.h" 1
# 24 "/home/pdreiter/Data/APR_eval/GenProg/v24.cb_eval/stack_vm.transform.ga/stack_vm/src/stack_vm/lib/cgc_libc.h"
#define LIBC_H 

typedef unsigned char uint8_t;
#define MAX_WIDTH 16

extern int cgc_transmit_all(int fd, const char *buf, const cgc_size_t size);
int cgc_recvline(int fd, char *buf, cgc_size_t size);
int cgc_strncmp(const char *s1, const char *s2, cgc_size_t n);
int cgc_strn2int(const char* str_buf, cgc_size_t max_chars);
void * cgc_memcpy(void* dst, const void* src, cgc_size_t cnt);
cgc_size_t cgc_strnlen(const char *string, cgc_size_t max_len);
cgc_size_t cgc_strlen(const char *string);
char * cgc_itoaB10(int value);
void * cgc_memset(void* str, int ch, cgc_size_t n);
# 5 "/home/pdreiter/Data/APR_eval/GenProg/v24.cb_eval/stack_vm.transform.ga/stack_vm/src/stack_vm/src/stack.c" 2
# 1 "/home/pdreiter/Data/APR_eval/GenProg/v24.cb_eval/stack_vm.transform.ga/stack_vm/src/stack_vm/src/cgc_stack.h" 1
# 23 "/home/pdreiter/Data/APR_eval/GenProg/v24.cb_eval/stack_vm.transform.ga/stack_vm/src/stack_vm/src/cgc_stack.h"
#define STACK_H 

#define TOO_MANY_ELEM_STR "Too many elements!\n"
#define NOT_ENOUGH_ELEM_STR "Not enough elements!\n"
#define MAX_STACK_SIZE 2000000

typedef struct {
 int top;
 int elementSize;
 int numElements;
 void *elements;
} Stack;

void cgc_initStack(Stack *stack, int numElements, int elementSize);
void cgc_destroyStack(Stack *stack);

int cgc_isStackFull(Stack *stack);
int cgc_isStackEmpty(Stack *stack);

void cgc_pushElement(Stack *stack, void* element);
void* cgc_popElement(Stack *stack);
# 6 "/home/pdreiter/Data/APR_eval/GenProg/v24.cb_eval/stack_vm.transform.ga/stack_vm/src/stack_vm/src/stack.c" 2

#define FIX_INGREDIENT_CONTENT 
#define FIX_INGREDIENT_CONTENT_VAR 
static int fix_ingred_enable=0;
static void __attribute((constructor)) fix_ingred_enable_init(){
    char* tmp=getenv("ENABLE_FIXES");
    if (tmp) { fix_ingred_enable=1; }
}







void fix_ingred_stack_0_1_1();
void fix_ingred_stack_0_1_2();
void fix_ingred_stack_0_1();
void fix_ingred_stack_0_2_0();
void fix_ingred_stack_0_2_1();
void fix_ingred_stack_0_2();
void fix_ingred_stack_0_3_0();
void fix_ingred_stack_0_3();
void fix_ingred_stack_0_4_0();
void fix_ingred_stack_0_4();
void fix_ingred_stack_0();
void cgc_initStack(Stack * stack, int numElements, int elementSize)
{
if (fix_ingred_enable){ fix_ingred_stack_0(); };
    int ret;
    if (numElements > 2000000 / elementSize) {
 stack->elements = (0);
 return;
    }
    {
        cgc_size_t tlv3;
        tlv3 = elementSize * numElements;
        int tlv2;
        tlv2 = 0;
        void** tlv1;
        tlv1 = ( void * * ) & stack -> elements;
        ret = cgc_allocate(tlv3,tlv2,tlv1);
    }
    if (ret != 0) {
 {
     unsigned int tlv4;
     tlv4 = 16;
     cgc__terminate(tlv4);
 }
    }
    stack->numElements = numElements;
    stack->elementSize = elementSize;
    stack->top = -1;
}

void fix_ingred_stack_1_1_0();
void fix_ingred_stack_1_1_1();
void fix_ingred_stack_1_1();
void fix_ingred_stack_1_2_0();
void fix_ingred_stack_1_2_1();
void fix_ingred_stack_1_2();
void fix_ingred_stack_1_3_0();
void fix_ingred_stack_1_3();
void fix_ingred_stack_1();
void cgc_destroyStack(Stack * stack)
{
if (fix_ingred_enable){ fix_ingred_stack_1(); };

    int ret;
    {
        void* tlv2;
        tlv2 = stack -> elements;
        cgc_size_t tlv1;
        tlv1 = stack -> numElements * stack -> elementSize;
        ret = cgc_deallocate(tlv2,tlv1);
    }
    if (ret != 0) {
 {
     unsigned int tlv3;
     tlv3 = 17;
     cgc__terminate(tlv3);
 }
    }
    stack->elements = (0);
    stack->numElements = 0;
    stack->elementSize = 0;
    stack->top = -1;
}

void fix_ingred_stack_2();
int cgc_isStackFull(Stack * stack)
{
if (fix_ingred_enable){ fix_ingred_stack_2(); };
    return stack->top >= stack->numElements;
}

void fix_ingred_stack_3();
int cgc_isStackEmpty(Stack * stack)
{
if (fix_ingred_enable){ fix_ingred_stack_3(); };
    return stack->top < 0;
}

void fix_ingred_stack_4_3_0();
void fix_ingred_stack_4_3_1();
void fix_ingred_stack_4_3();
void fix_ingred_stack_4_4_0();
void fix_ingred_stack_4_4_1();
void fix_ingred_stack_4_4();
void fix_ingred_stack_4_5_0();
void fix_ingred_stack_4_5();
void fix_ingred_stack_4_6_0();
void fix_ingred_stack_4_6();
void fix_ingred_stack_4_7_1();
void fix_ingred_stack_4_7_2();
void fix_ingred_stack_4_7();
void fix_ingred_stack_4();
void cgc_pushElement(Stack * stack, void *element)
{
if (fix_ingred_enable){ fix_ingred_stack_4(); };
    int ret;
    int tlv1;
    {
        Stack* tlv5;
        tlv5 = stack;
        tlv1 = cgc_isStackFull(tlv5);
    }
    if (tlv1) {
 {
     int tlv9;
     tlv9 = 1;
     const char* tlv8 = "Too many elements!\n";
     cgc_size_t tlv7;
     tlv7 = sizeof ( "Too many elements!\n" );
     ret = cgc_transmit_all(tlv9,tlv8,tlv7);
 }
 if (ret != 0) {
     {
         unsigned int tlv10;
         tlv10 = 18;
         cgc__terminate(tlv10);
     }
 }
 {
     unsigned int tlv6;
     tlv6 = 19;
     cgc__terminate(tlv6);
 }
    }
    stack->top++;
    {
        void* tlv4;
        tlv4 = & stack -> elements [ stack -> elementSize * stack -> top ];
        void* tlv3;
        tlv3 = element;
        cgc_size_t tlv2;
        tlv2 = stack -> elementSize;
        cgc_memcpy(tlv4,tlv3,tlv2);
    }
}

void fix_ingred_stack_5_3_0();
void fix_ingred_stack_5_3_1();
void fix_ingred_stack_5_3();
void fix_ingred_stack_5_4_0();
void fix_ingred_stack_5_4_1();
void fix_ingred_stack_5_4();
void fix_ingred_stack_5_5_0();
void fix_ingred_stack_5_5();
void fix_ingred_stack_5_6_0();
void fix_ingred_stack_5_6();
void fix_ingred_stack_5();
void *cgc_popElement(Stack * stack)
{
if (fix_ingred_enable){ fix_ingred_stack_5(); };
    int ret;
    int tlv1;
    {
        Stack* tlv2;
        tlv2 = stack;
        tlv1 = cgc_isStackEmpty(tlv2);
    }
    if (tlv1) {
 {
     int tlv6;
     tlv6 = 1;
     const char* tlv5 = "Not enough elements!\n";
     cgc_size_t tlv4;
     tlv4 = sizeof ( "Not enough elements!\n" );
     ret = cgc_transmit_all(tlv6,tlv5,tlv4);
 }
 if (ret != 0) {
     {
         unsigned int tlv7;
         tlv7 = 20;
         cgc__terminate(tlv7);
     }
 }
 {
     unsigned int tlv3;
     tlv3 = 21;
     cgc__terminate(tlv3);
 }
    }
    return &stack->elements[stack->elementSize * stack->top--];
}

void fix_ingred_stack_0_1_1(){
int numElements;
    bzero(&numElements,sizeof(int));
int elementSize;
    bzero(&elementSize,sizeof(int));
    {int ret; ret = (int)(numElements); }
    {cgc_size_t tlv3; tlv3 = (cgc_size_t)(numElements); }
    {int tlv2; tlv2 = (int)(numElements); }
    {unsigned int tlv4; tlv4 = (unsigned int)(numElements); }
}
void fix_ingred_stack_0_1_2(){
int numElements;
    bzero(&numElements,sizeof(int));
int elementSize;
    bzero(&elementSize,sizeof(int));
    { elementSize = 1;
         int ret; ret = (int)(2000000 / elementSize); }
    { elementSize = 1;
         cgc_size_t tlv3; tlv3 = (cgc_size_t)(2000000 / elementSize); }
    { elementSize = 1;
         int tlv2; tlv2 = (int)(2000000 / elementSize); }
    { elementSize = 1;
         unsigned int tlv4; tlv4 = (unsigned int)(2000000 / elementSize); }
}
void fix_ingred_stack_0_1(){
fix_ingred_stack_0_1_1();
fix_ingred_stack_0_1_2();
}
void fix_ingred_stack_0_2_0(){
int elementSize;
    bzero(&elementSize,sizeof(int));
int numElements;
    bzero(&numElements,sizeof(int));
    {int ret; ret = (int)(elementSize * numElements); }
    {cgc_size_t tlv3; tlv3 = (cgc_size_t)(elementSize * numElements); }
    {int tlv2; tlv2 = (int)(elementSize * numElements); }
    {unsigned int tlv4; tlv4 = (unsigned int)(elementSize * numElements); }
}
void fix_ingred_stack_0_2_1(){
int elementSize;
    bzero(&elementSize,sizeof(int));
int numElements;
    bzero(&numElements,sizeof(int));
    {int ret; ret = (int)(0); }
    {cgc_size_t tlv3; tlv3 = (cgc_size_t)(0); }
    {int tlv2; tlv2 = (int)(0); }
    {unsigned int tlv4; tlv4 = (unsigned int)(0); }
}
void fix_ingred_stack_0_2(){
fix_ingred_stack_0_2_0();
fix_ingred_stack_0_2_1();
}
void fix_ingred_stack_0_3_0(){
int ret;
    bzero(&ret,sizeof(int));
    {cgc_size_t tlv3; tlv3 = (cgc_size_t)(ret); }
    {int tlv2; tlv2 = (int)(ret); }
    {unsigned int tlv4; tlv4 = (unsigned int)(ret); }
}
void fix_ingred_stack_0_3(){
fix_ingred_stack_0_3_0();
}
void fix_ingred_stack_0_4_0(){
    {int ret; ret = (int)(16); }
    {cgc_size_t tlv3; tlv3 = (cgc_size_t)(16); }
    {int tlv2; tlv2 = (int)(16); }
    {unsigned int tlv4; tlv4 = (unsigned int)(16); }
}
void fix_ingred_stack_0_4(){
fix_ingred_stack_0_4_0();
}
void fix_ingred_stack_0(){
fix_ingred_stack_0_1();
fix_ingred_stack_0_2();
fix_ingred_stack_0_3();
fix_ingred_stack_0_4();
}
void fix_ingred_stack_1_1_0(){
Stack stack_ref;
    bzero(&stack_ref,1*sizeof(Stack));
Stack * stack = &stack_ref;
    {int ret; ret = (int)(stack -> elements); }
    {void * tlv2; tlv2 = (void *)(stack -> elements); }
    {cgc_size_t tlv1; tlv1 = (cgc_size_t)(stack -> elements); }
    {unsigned int tlv3; tlv3 = (unsigned int)(stack -> elements); }
}
void fix_ingred_stack_1_1_1(){
Stack stack_ref;
    bzero(&stack_ref,1*sizeof(Stack));
Stack * stack = &stack_ref;
    {int ret; ret = (int)(stack -> numElements * stack -> elementSize); }
    {void * tlv2; tlv2 = (void *)(stack -> numElements * stack -> elementSize); }
    {cgc_size_t tlv1; tlv1 = (cgc_size_t)(stack -> numElements * stack -> elementSize); }
    {unsigned int tlv3; tlv3 = (unsigned int)(stack -> numElements * stack -> elementSize); }
}
void fix_ingred_stack_1_1(){
fix_ingred_stack_1_1_0();
fix_ingred_stack_1_1_1();
}
void fix_ingred_stack_1_2_0(){
int ret;
    bzero(&ret,sizeof(int));
    {void * tlv2; tlv2 = (void *)(ret); }
    {cgc_size_t tlv1; tlv1 = (cgc_size_t)(ret); }
    {unsigned int tlv3; tlv3 = (unsigned int)(ret); }
}
void fix_ingred_stack_1_2_1(){
int ret;
    bzero(&ret,sizeof(int));
    {void * tlv2; tlv2 = (void *)(0); }
    {cgc_size_t tlv1; tlv1 = (cgc_size_t)(0); }
    {unsigned int tlv3; tlv3 = (unsigned int)(0); }
}
void fix_ingred_stack_1_2(){
fix_ingred_stack_1_2_0();
fix_ingred_stack_1_2_1();
}
void fix_ingred_stack_1_3_0(){
    {int ret; ret = (int)(17); }
    {void * tlv2; tlv2 = (void *)(17); }
    {cgc_size_t tlv1; tlv1 = (cgc_size_t)(17); }
    {unsigned int tlv3; tlv3 = (unsigned int)(17); }
}
void fix_ingred_stack_1_3(){
fix_ingred_stack_1_3_0();
}
void fix_ingred_stack_1(){
fix_ingred_stack_1_1();
fix_ingred_stack_1_2();
fix_ingred_stack_1_3();
}
void fix_ingred_stack_2(){
}
void fix_ingred_stack_3(){
}
void fix_ingred_stack_4_3_0(){
    {int ret; ret = (int)(1); }
    {int tlv1; tlv1 = (int)(1); }
    {void * tlv4; tlv4 = (void *)(1); }
    {void * tlv3; tlv3 = (void *)(1); }
    {cgc_size_t tlv2; tlv2 = (cgc_size_t)(1); }
    {int tlv9; tlv9 = (int)(1); }
    {cgc_size_t tlv7; tlv7 = (cgc_size_t)(1); }
    {unsigned int tlv6; tlv6 = (unsigned int)(1); }
    {unsigned int tlv10; tlv10 = (unsigned int)(1); }
}
void fix_ingred_stack_4_3_1(){
    {int ret; ret = (int)(sizeof ( "Too many elements!\n" )); }
    {int tlv1; tlv1 = (int)(sizeof ( "Too many elements!\n" )); }
    {void * tlv4; tlv4 = (void *)(sizeof ( "Too many elements!\n" )); }
    {void * tlv3; tlv3 = (void *)(sizeof ( "Too many elements!\n" )); }
    {cgc_size_t tlv2; tlv2 = (cgc_size_t)(sizeof ( "Too many elements!\n" )); }
    {int tlv9; tlv9 = (int)(sizeof ( "Too many elements!\n" )); }
    {cgc_size_t tlv7; tlv7 = (cgc_size_t)(sizeof ( "Too many elements!\n" )); }
    {unsigned int tlv6; tlv6 = (unsigned int)(sizeof ( "Too many elements!\n" )); }
    {unsigned int tlv10; tlv10 = (unsigned int)(sizeof ( "Too many elements!\n" )); }
}
void fix_ingred_stack_4_3(){
fix_ingred_stack_4_3_0();
fix_ingred_stack_4_3_1();
}
void fix_ingred_stack_4_4_0(){
int ret;
    bzero(&ret,sizeof(int));
    {int tlv1; tlv1 = (int)(ret); }
    {void * tlv4; tlv4 = (void *)(ret); }
    {void * tlv3; tlv3 = (void *)(ret); }
    {cgc_size_t tlv2; tlv2 = (cgc_size_t)(ret); }
    {int tlv9; tlv9 = (int)(ret); }
    {cgc_size_t tlv7; tlv7 = (cgc_size_t)(ret); }
    {unsigned int tlv6; tlv6 = (unsigned int)(ret); }
    {unsigned int tlv10; tlv10 = (unsigned int)(ret); }
}
void fix_ingred_stack_4_4_1(){
int ret;
    bzero(&ret,sizeof(int));
    {int tlv1; tlv1 = (int)(0); }
    {void * tlv4; tlv4 = (void *)(0); }
    {void * tlv3; tlv3 = (void *)(0); }
    {cgc_size_t tlv2; tlv2 = (cgc_size_t)(0); }
    {int tlv9; tlv9 = (int)(0); }
    {cgc_size_t tlv7; tlv7 = (cgc_size_t)(0); }
    {unsigned int tlv6; tlv6 = (unsigned int)(0); }
    {unsigned int tlv10; tlv10 = (unsigned int)(0); }
}
void fix_ingred_stack_4_4(){
fix_ingred_stack_4_4_0();
fix_ingred_stack_4_4_1();
}
void fix_ingred_stack_4_5_0(){
    {int ret; ret = (int)(18); }
    {int tlv1; tlv1 = (int)(18); }
    {void * tlv4; tlv4 = (void *)(18); }
    {void * tlv3; tlv3 = (void *)(18); }
    {cgc_size_t tlv2; tlv2 = (cgc_size_t)(18); }
    {int tlv9; tlv9 = (int)(18); }
    {cgc_size_t tlv7; tlv7 = (cgc_size_t)(18); }
    {unsigned int tlv6; tlv6 = (unsigned int)(18); }
    {unsigned int tlv10; tlv10 = (unsigned int)(18); }
}
void fix_ingred_stack_4_5(){
fix_ingred_stack_4_5_0();
}
void fix_ingred_stack_4_6_0(){
    {int ret; ret = (int)(19); }
    {int tlv1; tlv1 = (int)(19); }
    {void * tlv4; tlv4 = (void *)(19); }
    {void * tlv3; tlv3 = (void *)(19); }
    {cgc_size_t tlv2; tlv2 = (cgc_size_t)(19); }
    {int tlv9; tlv9 = (int)(19); }
    {cgc_size_t tlv7; tlv7 = (cgc_size_t)(19); }
    {unsigned int tlv6; tlv6 = (unsigned int)(19); }
    {unsigned int tlv10; tlv10 = (unsigned int)(19); }
}
void fix_ingred_stack_4_6(){
fix_ingred_stack_4_6_0();
}
void fix_ingred_stack_4_7_1(){
int element_ref;
    bzero(&element_ref,1*sizeof(int));
void * element = (void*)&element_ref;
Stack stack_ref;
    bzero(&stack_ref,1*sizeof(Stack));
Stack * stack = &stack_ref;
    {int ret; ret = (int)(element); }
    {int tlv1; tlv1 = (int)(element); }
    {void * tlv4; tlv4 = (void *)(element); }
    {void * tlv3; tlv3 = (void *)(element); }
    {cgc_size_t tlv2; tlv2 = (cgc_size_t)(element); }
    {int tlv9; tlv9 = (int)(element); }
    {cgc_size_t tlv7; tlv7 = (cgc_size_t)(element); }
    {unsigned int tlv6; tlv6 = (unsigned int)(element); }
    {unsigned int tlv10; tlv10 = (unsigned int)(element); }
}
void fix_ingred_stack_4_7_2(){
int element_ref;
    bzero(&element_ref,1*sizeof(int));
void * element = (void*)&element_ref;
Stack stack_ref;
    bzero(&stack_ref,1*sizeof(Stack));
Stack * stack = &stack_ref;
    {int ret; ret = (int)(stack -> elementSize); }
    {int tlv1; tlv1 = (int)(stack -> elementSize); }
    {void * tlv4; tlv4 = (void *)(stack -> elementSize); }
    {void * tlv3; tlv3 = (void *)(stack -> elementSize); }
    {cgc_size_t tlv2; tlv2 = (cgc_size_t)(stack -> elementSize); }
    {int tlv9; tlv9 = (int)(stack -> elementSize); }
    {cgc_size_t tlv7; tlv7 = (cgc_size_t)(stack -> elementSize); }
    {unsigned int tlv6; tlv6 = (unsigned int)(stack -> elementSize); }
    {unsigned int tlv10; tlv10 = (unsigned int)(stack -> elementSize); }
}
void fix_ingred_stack_4_7(){
fix_ingred_stack_4_7_1();
fix_ingred_stack_4_7_2();
}
void fix_ingred_stack_4(){
fix_ingred_stack_4_3();
fix_ingred_stack_4_4();
fix_ingred_stack_4_5();
fix_ingred_stack_4_6();
fix_ingred_stack_4_7();
}
void fix_ingred_stack_5_3_0(){
    {int tlv6; tlv6 = (int)(1); }
    {cgc_size_t tlv4; tlv4 = (cgc_size_t)(1); }
    {unsigned int tlv3; tlv3 = (unsigned int)(1); }
    {unsigned int tlv7; tlv7 = (unsigned int)(1); }
}
void fix_ingred_stack_5_3_1(){
    {int ret; ret = (int)(sizeof ( "Not enough elements!\n" )); }
    {int tlv1; tlv1 = (int)(sizeof ( "Not enough elements!\n" )); }
    {int tlv6; tlv6 = (int)(sizeof ( "Not enough elements!\n" )); }
    {cgc_size_t tlv4; tlv4 = (cgc_size_t)(sizeof ( "Not enough elements!\n" )); }
    {unsigned int tlv3; tlv3 = (unsigned int)(sizeof ( "Not enough elements!\n" )); }
    {unsigned int tlv7; tlv7 = (unsigned int)(sizeof ( "Not enough elements!\n" )); }
}
void fix_ingred_stack_5_3(){
fix_ingred_stack_5_3_0();
fix_ingred_stack_5_3_1();
}
void fix_ingred_stack_5_4_0(){
int ret;
    bzero(&ret,sizeof(int));
    {int tlv6; tlv6 = (int)(ret); }
    {cgc_size_t tlv4; tlv4 = (cgc_size_t)(ret); }
    {unsigned int tlv7; tlv7 = (unsigned int)(ret); }
}
void fix_ingred_stack_5_4_1(){
int ret;
    bzero(&ret,sizeof(int));
    {int tlv6; tlv6 = (int)(0); }
    {cgc_size_t tlv4; tlv4 = (cgc_size_t)(0); }
    {unsigned int tlv7; tlv7 = (unsigned int)(0); }
}
void fix_ingred_stack_5_4(){
fix_ingred_stack_5_4_0();
fix_ingred_stack_5_4_1();
}
void fix_ingred_stack_5_5_0(){
    {int ret; ret = (int)(20); }
    {int tlv1; tlv1 = (int)(20); }
    {int tlv6; tlv6 = (int)(20); }
    {cgc_size_t tlv4; tlv4 = (cgc_size_t)(20); }
    {unsigned int tlv3; tlv3 = (unsigned int)(20); }
    {unsigned int tlv7; tlv7 = (unsigned int)(20); }
}
void fix_ingred_stack_5_5(){
fix_ingred_stack_5_5_0();
}
void fix_ingred_stack_5_6_0(){
    {int ret; ret = (int)(21); }
    {int tlv1; tlv1 = (int)(21); }
    {int tlv6; tlv6 = (int)(21); }
    {cgc_size_t tlv4; tlv4 = (cgc_size_t)(21); }
    {unsigned int tlv3; tlv3 = (unsigned int)(21); }
    {unsigned int tlv7; tlv7 = (unsigned int)(21); }
}
void fix_ingred_stack_5_6(){
fix_ingred_stack_5_6_0();
}
void fix_ingred_stack_5(){
fix_ingred_stack_5_3();
fix_ingred_stack_5_4();
fix_ingred_stack_5_5();
fix_ingred_stack_5_6();
}
