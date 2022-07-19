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
typedef __builtin_va_list __gnuc_va_list;
typedef __gnuc_va_list va_list;
struct _heap_block_header {
   cgc_size_t remaining_size ;
   struct _heap_block_header *next ;
   char data[1] ;
};
typedef struct _heap_block_header heap_block_header;
struct _heap_header {
   cgc_size_t size ;
   char flags ;
};
typedef struct _heap_header heap_header;
struct _heap_metadata {
   cgc_size_t mem_commit ;
   cgc_size_t mem_free ;
   cgc_size_t mem_inuse ;
   heap_block_header *blocks ;
};
typedef struct _heap_metadata heap_metadata;
typedef signed char int8_t;
typedef short int16_t;
typedef int int32_t;
typedef long long int64_t;
typedef unsigned char uint8_t;
typedef unsigned short uint16_t;
typedef unsigned int uint32_t;
typedef unsigned long long uint64_t;
struct dListNode_s {
   struct dListNode_s *prev ;
   struct dListNode_s *next ;
   void *this ;
   char data[128] ;
};
typedef struct dListNode_s dListNode;
typedef struct dListNode_s *pdListNode;
struct sListNode_s {
   char data[4080] ;
   struct sListNode_s *next ;
   unsigned int count ;
};
typedef struct sListNode_s sListNode;
typedef struct sListNode_s *psListNode;
struct dList_s {
   pdListNode listRoot ;
   int count ;
};
typedef struct dList_s dList;
typedef struct dList_s *pdList;
struct sList_s {
   psListNode listRoot ;
   int count ;
   int countRemaining ;
};
typedef struct sList_s sList;
typedef struct sList_s *psList;
struct road_s;
struct intersection_s {
   char FLAG[32] ;
   pdListNode self ;
   struct road_s *other_road ;
   struct intersection_s *prevIntersection ;
   double distance_to_prev ;
   struct intersection_s *nextIntersection ;
   double distance_to_next ;
};
typedef struct intersection_s intersection;
typedef struct intersection_s *pintersection;
struct road_s {
   char FLAG[16] ;
   pdListNode self ;
   char name[32] ;
   pdList addressList ;
   pdList intersectionList ;
   double length ;
};
typedef struct road_s road;
typedef struct road_s *proad;
struct map_s {
   char name[32] ;
   pdList roadList ;
};
typedef struct map_s map;
typedef struct map_s *pmap;
struct address_s {
   char FLAG[8] ;
   pdListNode self ;
   int number ;
   char resident[32] ;
   proad thisRoad ;
   pintersection prevIntersection ;
   double distance_to_prev ;
   pintersection nextIntersection ;
   double distance_to_next ;
};
typedef struct address_s address;
typedef struct address_s *paddress;
struct routeList_s {
   proad thisRoad ;
   struct routeList_s *parent ;
   char filler[120] ;
};
typedef struct routeList_s routeList;
typedef struct routeList_s *prouteList;
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
extern int cgc_isspace(int c ) ;
extern int cgc_isdigit(int c ) ;
extern int cgc_isnan(double val ) ;
extern int cgc_isinf(double val ) ;
extern double cgc_atof(char const   *str ) ;
extern int cgc_atoi(char const   *str ) ;
extern void *cgc_calloc(cgc_size_t count , cgc_size_t size ) ;
extern void cgc_free(void *ptr ) ;
extern void *cgc_malloc(cgc_size_t size ) ;
extern char *cgc_strcpy(char *dest , char *src ) ;
extern int cgc_printf(char const   *fmt  , ...) ;
extern void cgc_bzero(void * , cgc_size_t  ) ;
extern int cgc_strcmp(char const   * , char const   * ) ;
extern char *cgc_strncat(char *dest , char const   *src , cgc_size_t n ) ;
extern cgc_size_t cgc_receive_until(char * , char  , cgc_size_t  ) ;
extern cgc_size_t cgc_strcat(char * , char * ) ;
extern cgc_size_t cgc_strlen(char *str ) ;
extern cgc_size_t cgc_itoa(char * , cgc_size_t  , cgc_size_t  ) ;
extern void cgc_puts(char *t ) ;
extern void *cgc_memcpy(void *dest , void *src , unsigned int len ) ;
extern void *cgc_memset(void *dest , char c , unsigned int len ) ;
extern double cgc_floor(double  ) ;
extern double cgc_round(double  , double n ) ;
extern psListNode cgc_get_last_element_s(psList thisList ) ;
extern pdListNode cgc_get_last_element_d(pdList thisList ) ;
extern psList cgc_create_single_list() ;
extern pdList cgc_create_double_list() ;
extern pdListNode cgc_insert_double_list_node(pdList thisList ,
                                              pdListNode prevNode ) ;
extern pdListNode cgc_delete_double_list_node(pdList thisList ,
                                              pdListNode deletedNode ) ;
extern psListNode cgc_insert_single_list_node(psList thisList ,
                                              psListNode prevNode ) ;
extern pmap cgc_init_map(char *mapName ) ;
extern proad cgc_add_road(pmap thisMap , char *roadName , double roadLength ) ;
extern void cgc_print_roads(pmap thisMap ) ;
extern paddress cgc_add_address(int number , char *resident , proad thisRoad ,
                                pintersection prevIntersection ,
                                double distance_to_prev ,
                                pintersection nextIntersection ,
                                double distance_to_next ) ;
extern void cgc_print_addresses(proad thisRoad ) ;
extern pintersection cgc_add_intersection(proad thisRoad , proad other_road ,
                                          pintersection prevIntersection ,
                                          double distance_to_prev ,
                                          double distance_to_next ) ;
extern void cgc_print_intersections(proad thisRoad ) ;
extern pintersection cgc_delete_intersection(proad thisRoad ,
                                             pintersection deletedIntersection ) ;
extern psList cgc_init_turnList() ;
extern psList cgc_get_route(pmap thisMap , psList turnList , proad targetRoad ,
                            proad startRoad ) ;
extern void name_map(pmap map ) ;
extern void cgc_prompt_loop(pmap map , psList turnList ) ;
int main(int cgc_argc , char **cgc_argv ) 
{ 
  psList turnList ;
  psList tmp ;
  pmap thisMap ;
  pmap tmp___0 ;

  {
  tmp = cgc_init_turnList();
  turnList = tmp;
  tmp___0 = cgc_init_map((char *)"Newville");
  thisMap = tmp___0;
  cgc_puts((char *)"This is Mapper.");
  cgc_prompt_loop(thisMap, turnList);
  return (1);
}
}
