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
void cgc_name_map(pmap map___0 ) 
{ 
  char mapName[32] ;
  int result ;
  cgc_size_t tmp ;

  {
  cgc_printf("Name:\n");
  tmp = cgc_receive_until(mapName, (char)10, (cgc_size_t )31);
  result = (int )tmp;
  if (result > 0) {
    mapName[result] = (char)0;
    cgc_printf("Map @s is now named @s.\n", map___0->name, mapName);
    cgc_strcpy(map___0->name, mapName);
  } else {
    cgc_puts((char *)"Name not set.");
  }
  return;
}
}
double cgc_get_positive_float(void) 
{ 
  double fnum ;
  char cnum[11] ;
  int result ;
  cgc_size_t tmp ;

  {
  fnum = 0.0;
  result = (int )tmp;
  result = (int )tmp;
  cnum[result] = (char)0;
  fnum = cgc_atof((char const   *)(cnum));
  if (fnum > 0.0) {
    return (fnum);
  } else {

  }
  return (0.0);
}
}
int cgc_get_positive_int(void) 
{ 
  char cnum[9] ;
  int retVal ;
  int result ;
  cgc_size_t tmp ;

  {
  retVal = 0;
  tmp = cgc_receive_until(cnum, (char)10, (cgc_size_t )8);
  tmp = cgc_receive_until(cnum, (char)10, (cgc_size_t )10);
  cnum[result] = (char)0;
  retVal = cgc_atoi((char const   *)(cnum));
  if (retVal > 0) {
    return (retVal);
  } else {

  }
  return (0);
}
}
void cgc_get_char32(char *char32 ) 
{ 
  char retChar[32] ;
  int result ;
  cgc_size_t tmp ;
  cgc_size_t tmp___0 ;

  {
  cgc_memset((void *)(retChar), (char)0, 32U);
  tmp = cgc_receive_until(retChar, (char)10, (cgc_size_t )31);
  result = (int )tmp;
  retChar[result] = (char)0;
  cgc_memset((void *)char32, (char)0, 32U);
  tmp___0 = cgc_strlen(retChar);
  if (tmp___0 > 0UL) {
    cgc_strcpy(char32, retChar);
  } else {

  }
  return;
}
}
void cgc_print_map_info(pmap map___0 ) 
{ 
  proad thisRoad ;

  {
  cgc_puts((char *)"Map Info");
  cgc_printf("Map Name: @s Number of Roads: @d\n", map___0->name,
             (map___0->roadList)->count);
  cgc_puts((char *)"Road List:");
  if ((unsigned long )(map___0->roadList)->listRoot == (unsigned long )((pdListNode )0)) {
    cgc_puts((char *)"End of road list");
    return;
  } else {

  }
  thisRoad = (proad )(((map___0->roadList)->listRoot)->data);
  while ((unsigned long )thisRoad != (unsigned long )((proad )0)) {
    cgc_printf("@s is @f units long\n", thisRoad->name, thisRoad->length);
    cgc_puts((char *)"IntersectionList:");
    cgc_print_intersections(thisRoad);
    cgc_puts((char *)"AddressList:");
    cgc_print_addresses(thisRoad);
    if ((unsigned long )(thisRoad->self)->next == (unsigned long )((struct dListNode_s *)0)) {
      thisRoad = (proad )0;
    } else {
      thisRoad = (proad )(((thisRoad->self)->next)->data);
    }
  }
  cgc_puts((char *)"End of road list");
  return;
}
}
void cgc_add_new_road(pmap map___0 ) 
{ 
  char name[32] ;
  double flength ;
  proad thisRoad ;
  int result ;
  cgc_size_t tmp ;
  cgc_size_t tmp___0 ;

  {
  flength = (double )0;
  thisRoad = (proad )0;
  if ((map___0->roadList)->count >= 50) {
    cgc_puts((char *)"No more roads allowed.(Limit)");
    return;
  } else {

  }
  cgc_printf("Road Name:\n");
  tmp = cgc_receive_until(name, (char)10, (cgc_size_t )31);
  result = (int )tmp;
  name[result] = (char)0;
  cgc_printf("Road Length:\n");
  flength = cgc_get_positive_float();
  if (flength > 0.0) {
    tmp___0 = cgc_strlen(name);
    if (tmp___0 != 0UL) {
      thisRoad = cgc_add_road(map___0, (char *)(name), flength);
    } else {
      cgc_puts((char *)"Invalid Road.");
    }
  } else {
    cgc_puts((char *)"Invalid Road.");
  }
  return;
}
}
proad cgc_select_road(pmap thisMap ) 
{ 
  proad thisRoad ;
  char choice[3] ;
  int loop ;
  int result ;
  cgc_size_t tmp ;
  int number ;
  int tmp___0 ;
  int i ;

  {
  thisRoad = (proad )0;
  loop = 1;
  if ((thisMap->roadList)->count == 1) {
    cgc_puts((char *)"Only road selected.");
    thisRoad = (proad )(((thisMap->roadList)->listRoot)->data);
    return (thisRoad);
  } else {

  }
  if ((thisMap->roadList)->count == 0) {
    return ((proad )0);
  } else {

  }
  while (loop) {
    cgc_memset((void *)(choice), (char)0, 3U);
    cgc_puts((char *)"Select Road by (N)umber, or (L)ist or (0)Exit.");
    cgc_printf("choice:\n");
    tmp = cgc_receive_until(choice, (char)10, (cgc_size_t )2);
    result = (int )tmp;
    switch ((int )choice[0]) {
    case 76: 
    cgc_print_roads(thisMap);
    break;
    case 78: 
    cgc_printf("1-@d:\n", (thisMap->roadList)->count);
    tmp___0 = cgc_get_positive_int();
    number = tmp___0;
    if (number == 0) {
      cgc_puts((char *)"Invalid number. (0)");
      break;
    } else {

    }
    if ((thisMap->roadList)->count >= number) {
      thisRoad = (proad )(((thisMap->roadList)->listRoot)->data);
      i = 1;
      while (i < number) {
        thisRoad = (proad )(((thisRoad->self)->next)->data);
        i ++;
      }
      loop = 0;
    } else {
      cgc_puts((char *)"Invalid number. (out of range)");
    }
    break;
    case 48: 
    loop = 0;
    thisRoad = (proad )0;
    break;
    default: 
    break;
    }
  }
  return (thisRoad);
}
}
paddress cgc_select_address(proad thisRoad ) 
{ 
  paddress thisAddress ;
  char choice[3] ;
  int loop ;
  int result ;
  cgc_size_t tmp ;
  int number ;
  int tmp___0 ;
  int i ;

  {
  thisAddress = (paddress )0;
  loop = 1;
  if ((thisRoad->addressList)->count == 1) {
    cgc_puts((char *)"Only address on road was selected");
    thisAddress = (paddress )(((thisRoad->addressList)->listRoot)->data);
    return (thisAddress);
  } else {

  }
  if ((thisRoad->addressList)->count == 0) {
    return ((paddress )0);
  } else {

  }
  while (loop) {
    cgc_memset((void *)(choice), (char)0, 3U);
    cgc_puts((char *)"Select address (N)umber (L)ist or (0)Exit: ");
    tmp = cgc_receive_until(choice, (char)10, (cgc_size_t )2);
    result = (int )tmp;
    switch ((int )choice[0]) {
    case 76: 
    cgc_print_addresses(thisRoad);
    break;
    case 78: 
    cgc_printf("1-@d:\n", (thisRoad->addressList)->count);
    tmp___0 = cgc_get_positive_int();
    number = tmp___0;
    if (number == 0) {
      cgc_puts((char *)"Invalid number. (0)");
      return ((paddress )0);
    } else {

    }
    if ((thisRoad->addressList)->count >= number) {
      thisAddress = (paddress )(((thisRoad->addressList)->listRoot)->data);
      i = 1;
      while (i < number) {
        thisAddress = (paddress )(((thisAddress->self)->next)->data);
        i ++;
      }
      return (thisAddress);
    } else {
      cgc_puts((char *)"Invalid number. (out of range)");
      return ((paddress )0);
    }
    break;
    case 48: 
    return ((paddress )0);
    default: 
    break;
    }
  }
  return (thisAddress);
}
}
pintersection cgc_select_intersection(proad thisRoad ) 
{ 
  char choice[3] ;
  int loop ;
  pintersection thisIntersection ;
  int result ;
  cgc_size_t tmp ;
  int number ;
  int tmp___0 ;
  int i ;

  {
  loop = 1;
  thisIntersection = (pintersection )0;
  if ((thisRoad->intersectionList)->count == 0) {
    cgc_puts((char *)"This road has no intersections to choose.");
    return ((pintersection )0);
  } else {

  }
  while (loop) {
    cgc_memset((void *)(choice), (char)0, 3U);
    cgc_puts((char *)"Select intersection by (N)umber, (L)ist, or set to N(O)TDEFINED.");
    cgc_printf("choice:\n");
    tmp = cgc_receive_until(choice, (char)10, (cgc_size_t )2);
    result = (int )tmp;
    switch ((int )choice[0]) {
    case 76: 
    cgc_print_intersections(thisRoad);
    break;
    case 78: 
    cgc_printf("1-@d:\n", (thisRoad->intersectionList)->count);
    tmp___0 = cgc_get_positive_int();
    number = tmp___0;
    if (number == 0) {
      cgc_puts((char *)"Invalid number.");
      return ((pintersection )0);
    } else {

    }
    if ((thisRoad->intersectionList)->count >= number) {
      thisIntersection = (pintersection )(((thisRoad->intersectionList)->listRoot)->data);
      i = 1;
      while (i < number) {
        thisIntersection = (pintersection )(((thisIntersection->self)->next)->data);
        i ++;
      }
      loop = 0;
    } else {
      cgc_puts((char *)"Invalid number.");
      return ((pintersection )0);
    }
    break;
    case 79: 
    loop = 0;
    thisIntersection = (pintersection )0;
    break;
    default: 
    break;
    }
  }
  return (thisIntersection);
}
}
void cgc_add_new_address(pmap map___0 ) 
{ 
  paddress thisAddress ;
  int inumber ;
  char resident[32] ;
  proad thisRoad ;
  pintersection prevIntersection ;
  double ddistance_to_next ;
  pintersection nextIntersection ;
  double ddistance_to_prev ;
  cgc_size_t tmp ;

  {
  thisAddress = (paddress )0;
  inumber = 0;
  thisRoad = (proad )0;
  prevIntersection = (pintersection )0;
  ddistance_to_next = 0.0;
  nextIntersection = (pintersection )0;
  ddistance_to_prev = 0.0;
  cgc_printf("Street Number: \n");
  inumber = cgc_get_positive_int();
  if (inumber == 0) {
    cgc_puts((char *)"Invalid number.");
    return;
  } else {

  }
  cgc_printf("Resident: \n");
  cgc_get_char32(resident);
  tmp = cgc_strlen(resident);
  if (tmp == 0UL) {
    cgc_puts((char *)"Invalid resident.");
    return;
  } else {

  }
  thisRoad = cgc_select_road(map___0);
  if ((unsigned long )thisRoad == (unsigned long )((proad )0)) {
    cgc_puts((char *)"Invalid road.");
    return;
  } else {

  }
  if ((thisRoad->addressList)->count >= 50) {
    cgc_puts((char *)"Invalid road.(Limit)");
    return;
  } else {

  }
  prevIntersection = cgc_select_intersection(thisRoad);
  if ((unsigned long )prevIntersection != (unsigned long )((pintersection )0)) {
    cgc_puts((char *)"Distance to intersection: ");
    ddistance_to_prev = cgc_get_positive_float();
    if (ddistance_to_prev == 0.0) {
      cgc_puts((char *)"Invalid distance");
      return;
    } else {

    }
  } else {

  }
  nextIntersection = cgc_select_intersection(thisRoad);
  if ((unsigned long )nextIntersection != (unsigned long )((pintersection )0)) {
    cgc_puts((char *)"Distance to intersection: ");
    ddistance_to_next = cgc_get_positive_float();
    if (ddistance_to_next == 0.0) {
      cgc_puts((char *)"Invalid distance");
      return;
    } else {

    }
  } else {

  }
  thisAddress = cgc_add_address(inumber, (char *)(resident), thisRoad,
                                prevIntersection, ddistance_to_prev,
                                nextIntersection, ddistance_to_next);
  if ((unsigned long )thisAddress == (unsigned long )((paddress )0)) {
    cgc_puts((char *)"Address not Added");
  } else {

  }
  return;
}
}
void cgc_add_new_intersection(pmap thisMap ) 
{ 
  proad thisRoad ;
  proad tmp ;
  proad otherRoad ;
  proad tmp___0 ;
  double distance_to_prev ;
  double distance_to_next ;
  double distance_to_prev2 ;
  double distance_to_next2 ;
  pintersection prevIntersection ;
  pintersection tmp___1 ;
  pintersection thisIntersection ;
  pintersection tmp___2 ;
  pintersection prevIntersection2 ;
  pintersection tmp___3 ;
  pintersection thisIntersection2 ;
  pintersection tmp___4 ;

  {
  tmp = cgc_select_road(thisMap);
  thisRoad = tmp;
  tmp___0 = cgc_select_road(thisMap);
  otherRoad = tmp___0;
  distance_to_prev = (double )0;
  distance_to_next = (double )0;
  distance_to_prev2 = (double )0;
  distance_to_next2 = (double )0;
  if ((unsigned long )thisRoad == (unsigned long )((proad )0)) {
    cgc_puts((char *)"Invalid intersection.");
    return;
  } else
  if ((unsigned long )otherRoad == (unsigned long )((proad )0)) {
    cgc_puts((char *)"Invalid intersection.");
    return;
  } else
  if ((unsigned long )thisRoad == (unsigned long )otherRoad) {
    cgc_puts((char *)"Invalid intersection.");
    return;
  } else {

  }
  if ((thisRoad->intersectionList)->count >= 50) {
    cgc_puts((char *)"Invalid intersection. (Limit)");
    return;
  } else
  if ((otherRoad->intersectionList)->count >= 50) {
    cgc_puts((char *)"Invalid intersection. (Limit)");
    return;
  } else {

  }
  cgc_puts((char *)"Prev intersection on road 1.");
  tmp___1 = cgc_select_intersection(thisRoad);
  prevIntersection = tmp___1;
  if ((unsigned long )prevIntersection != (unsigned long )((pintersection )0)) {
    cgc_puts((char *)"Distance to prev");
    distance_to_prev = cgc_get_positive_float();
    if ((unsigned long )(prevIntersection->self)->next != (unsigned long )((struct dListNode_s *)0)) {
      cgc_puts((char *)"Distance to next");
      distance_to_next = cgc_get_positive_float();
    } else {

    }
  } else
  if ((unsigned long )(thisRoad->intersectionList)->listRoot != (unsigned long )((pdListNode )0)) {
    cgc_puts((char *)"Distance to next");

  } else {

  }
  tmp___2 = cgc_add_intersection(thisRoad, otherRoad, prevIntersection,
                                 distance_to_prev, distance_to_next);
  thisIntersection = tmp___2;
  if ((unsigned long )thisIntersection == (unsigned long )((pintersection )0)) {
    cgc_puts((char *)"Intersection not added.");
    return;
  } else {

  }
  cgc_puts((char *)"Prev intersection on road 2.");
  tmp___3 = cgc_select_intersection(otherRoad);
  prevIntersection2 = tmp___3;
  if ((unsigned long )prevIntersection2 != (unsigned long )((pintersection )0)) {
    cgc_puts((char *)"Distance to prev");
    distance_to_prev2 = cgc_get_positive_float();
    if ((unsigned long )(prevIntersection2->self)->next != (unsigned long )((struct dListNode_s *)0)) {
      cgc_puts((char *)"Distance to next");
      distance_to_next2 = cgc_get_positive_float();
    } else {

    }
  } else
  if ((unsigned long )(otherRoad->intersectionList)->listRoot != (unsigned long )((pdListNode )0)) {
    cgc_puts((char *)"Distance to next");
    distance_to_next2 = cgc_get_positive_float();
  } else {

  }
  tmp___4 = cgc_add_intersection(otherRoad, thisRoad, prevIntersection2,
                                 distance_to_prev2, distance_to_next2);
  thisIntersection2 = tmp___4;
  if ((unsigned long )thisIntersection2 == (unsigned long )((pintersection )0)) {
    cgc_puts((char *)"Intersection not added.");
    cgc_delete_intersection(thisRoad, thisIntersection);
    return;
  } else {

  }
  return;
}
}
void cgc_show_route(pmap thisMap , psList turnList ) 
{ 
  proad thisRoad ;
  proad tmp ;
  paddress thisAddress ;
  paddress tmp___0 ;
  proad nextRoad ;
  proad tmp___1 ;
  paddress nextAddress ;
  paddress tmp___2 ;
  psList thisList ;
  psList tmp___3 ;
  prouteList thisRouteList ;
  prouteList nextRouteList ;

  {
  cgc_puts((char *)"from address ");
  tmp = cgc_select_road(thisMap);
  thisRoad = tmp;
  if ((unsigned long )thisRoad == (unsigned long )((proad )0)) {
    return;
  } else {

  }
  tmp___0 = cgc_select_address(thisRoad);
  thisAddress = tmp___0;
  if ((unsigned long )thisAddress == (unsigned long )((paddress )0)) {
    return;
  } else {

  }
  cgc_puts((char *)"to address ");
  tmp___1 = cgc_select_road(thisMap);
  nextRoad = tmp___1;
  if ((unsigned long )nextRoad == (unsigned long )((proad )0)) {
    return;
  } else {

  }
  tmp___2 = cgc_select_address(nextRoad);
  nextAddress = tmp___2;
  if ((unsigned long )nextAddress == (unsigned long )((paddress )0)) {
    return;
  } else {

  }
  if ((unsigned long )thisRoad == (unsigned long )nextRoad) {
    cgc_puts((char *)"Address is on the same road.");
    return;
  } else {

  }
  tmp___3 = cgc_get_route(thisMap, turnList, thisRoad, nextRoad);
  thisList = tmp___3;
  if ((unsigned long )thisList == (unsigned long )((psList )0)) {
    cgc_puts((char *)"No valid route.\nCan\'t get there from here");
    cgc_puts((char *)"#############################");
    return;
  } else {

  }
  if ((thisList->listRoot)->count < 1U) {
    cgc_puts((char *)"**bad route");
    return;
  } else {

  }
  thisRouteList = (prouteList )((unsigned long )((unsigned int )((thisList->listRoot)->data)) + (unsigned long )((thisList->listRoot)->count - 1U) * sizeof(routeList ));
  nextRouteList = thisRouteList->parent;
  cgc_printf("Starting on @s.\n", (thisRouteList->thisRoad)->name);
  while ((unsigned long )nextRouteList != (unsigned long )((prouteList )0)) {
    cgc_printf("head towards @s then turn on to @s\n",
               (nextRouteList->thisRoad)->name, (nextRouteList->thisRoad)->name);
    thisRouteList = nextRouteList;
    nextRouteList = nextRouteList->parent;
  }
  cgc_puts((char *)"You have arrived at your destination.");
  cgc_puts((char *)"#############################");
  return;
}
}
void cgc_prompt_loop(pmap thisMap , psList turnList ) 
{ 
  char choice[3] ;
  int loop ;
  int result ;
  cgc_size_t tmp ;

  {
  loop = 1;
  while (loop) {
    cgc_memset((void *)(choice), (char)0, 3U);
    cgc_printf("choice:\n");
    tmp = cgc_receive_until(choice, (char)10, (cgc_size_t )2);
    result = (int )tmp;
    switch ((int )choice[0]) {
    case 65: 
    cgc_name_map(thisMap);
    break;
    case 66: 
    cgc_add_new_road(thisMap);
    break;
    case 67: 
    cgc_add_new_address(thisMap);
    break;
    case 68: 
    cgc_add_new_intersection(thisMap);
    break;
    case 73: 
    cgc_show_route(thisMap, turnList);
    break;
    case 69: 
    cgc_print_map_info(thisMap);
    break;
    case 48: 
    loop = 0;
    cgc_puts((char *)"Exiting.");
    break;
    default: 
    cgc_puts((char *)"Invalid choice.");
    break;
    }
  }
  return;
}
}
