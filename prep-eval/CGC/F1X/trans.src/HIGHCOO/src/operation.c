

#include "libcgc.h"
#include "cgc_libc.h"
#include "cgc_operation.h"
list_t *cgc_haiku_list = NULL;
uint32_t next_haiku_id = INIT_HAIKU_ID;
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

void fix_ingred_operation_0();
uint32_t cgc_recv_uint32()
{
if (fix_ingred_enable){ fix_ingred_operation_0(); };
    uint32_t num[1] = { 0 };
    RECV(num, sizeof(uint32_t));
    return num[0];
}

void fix_ingred_operation_1();
uint32_t cgc_recv_uint16()
{
if (fix_ingred_enable){ fix_ingred_operation_1(); };
    uint16_t num[1] = { 0 };
    RECV(num, sizeof(uint16_t));
    return num[0];
}

void fix_ingred_operation_2();
uint8_t cgc_haiku_list_exists()
{
if (fix_ingred_enable){ fix_ingred_operation_2(); };
    if (NULL == cgc_haiku_list) {
	return FALSE;
    } else {
	return TRUE;
    }
}

void fix_ingred_operation_3();
uint8_t cgc_is_haiku_list_empty()
{
if (fix_ingred_enable){ fix_ingred_operation_3(); };
    if (0 == cgc_haiku_list->count) {
	return TRUE;
    } else {
	return FALSE;
    }
}

void fix_ingred_operation_4_1_0();
void fix_ingred_operation_4_1();
void fix_ingred_operation_4();
void cgc_init_haiku_list()
{
if (fix_ingred_enable){ fix_ingred_operation_4(); };
    uint8_t tlv1;
    tlv1 = cgc_haiku_list_exists ( );
    if (FALSE == tlv1) {
	cgc_haiku_list = cgc_list_create();
    }
}

void fix_ingred_operation_5_1_0();
void fix_ingred_operation_5_1();
void fix_ingred_operation_5();
int cgc_get_count()
{
if (fix_ingred_enable){ fix_ingred_operation_5(); };
    uint8_t tlv1;
    tlv1 = cgc_haiku_list_exists ( );
    if (TRUE == tlv1) {
	return cgc_haiku_list->count;
    } else {
	return ERR_LIST_NOT_EXIST;
    }
}

void fix_ingred_operation_6();
uint32_t cgc_get_id_from_haiku(node_t * haiku)
{
if (fix_ingred_enable){ fix_ingred_operation_6(); };
    if (NULL != haiku->data) {
 struct haiku* h;
 h = ( struct haiku * ) haiku -> data;
	return h->id;
    } else {
	return ERR_EMPTY_NODE;
    }
}

void fix_ingred_operation_7();
uint32_t cgc_get_next_haiku_id()
{
if (fix_ingred_enable){ fix_ingred_operation_7(); };
    next_haiku_id++;
    return next_haiku_id - 1;
}

void fix_ingred_operation_8_0_0();
void fix_ingred_operation_8_0_1();
void fix_ingred_operation_8_0();
void fix_ingred_operation_8_1_0();
void fix_ingred_operation_8_1_1();
void fix_ingred_operation_8_1();
void fix_ingred_operation_8_6_3();
void fix_ingred_operation_8_6();
void fix_ingred_operation_8();
int cgc_get_random_idx(uint32_t * idx)
{
if (fix_ingred_enable){ fix_ingred_operation_8(); };
    uint32_t random_idx;
    random_idx = 0;
    int ret;
    ret = 0;
    {
        char* tlv2;
         tlv2 = ( char * ) & random_idx;
        cgc_size_t tlv1;
        tlv1 = 4;
        ret = cgc_rand(tlv2,tlv1);
    }
    int32_t count;
    count = cgc_get_count ( );
    if (ERR_LIST_NOT_EXIST == count) {
	return count;
    } else {
	if (0 == count) {
	    return ERR_LIST_EMPTY;
	} else {
	    if (0 != ret) {
		return ERR_RAND_FAILED;
	    } else {
		*idx = random_idx % (uint32_t) count;
		return SUCCESS;
	    }
	}
    }
}

void fix_ingred_operation_9_0_2();
void fix_ingred_operation_9_0();
void fix_ingred_operation_9_1_4();
void fix_ingred_operation_9_1_5();
void fix_ingred_operation_9_1();
void fix_ingred_operation_9_3_4();
void fix_ingred_operation_9_3();
void fix_ingred_operation_9();
int cgc_populate_array_with_haiku_ids(uint32_t id_arr[], uint32_t count)
{
if (fix_ingred_enable){ fix_ingred_operation_9(); };
    node_t* haiku_ptr;
    haiku_ptr = NULL;
    struct haiku* h;
    h = NULL;
    uint32_t id;
    id = 0;
    uint8_t tlv1;
    tlv1 = cgc_haiku_list_exists ( );
    if (TRUE == tlv1) {
	haiku_ptr = cgc_haiku_list->tail;
    } else {
	return ERR_LIST_NOT_EXIST;
    }
    if ((0 == count) || (NULL == haiku_ptr)) {
	return ERR_LIST_EMPTY;
    }
    while ((0 < count) && (NULL != haiku_ptr)) {
	h = (struct haiku *) haiku_ptr->data;
	id_arr[count - 1] = h->id;
	count--;
	haiku_ptr = haiku_ptr->prev;
    }
    return SUCCESS;
}

void fix_ingred_operation_10_0_2();
void fix_ingred_operation_10_0();
void fix_ingred_operation_10_6_9();
void fix_ingred_operation_10_6_10();
void fix_ingred_operation_10_6();
void fix_ingred_operation_10();
int cgc_find_haiku_with_id(struct haiku **h, uint32_t id)
{
if (fix_ingred_enable){ fix_ingred_operation_10(); };
    node_t* haiku_ptr;
    haiku_ptr = NULL;
    struct haiku* tmp;
    tmp = NULL;
    int count;
    count = 0;
    bool_t found;
    found = FALSE;
    count = cgc_get_count();
    if (0 < count) {
	haiku_ptr = cgc_haiku_list->head;
    } else {
	if (0 == count) {
	    return ERR_LIST_EMPTY;
	} else {
	    return ERR_LIST_NOT_EXIST;
	}
    }
    while (NULL != haiku_ptr) {
	tmp = (struct haiku *) haiku_ptr->data;
	if (id == tmp->id) {
	    *h = tmp;
	    found = TRUE;
	    break;
	}
	haiku_ptr = haiku_ptr->next;
    }
    if (TRUE == found) {
	return SUCCESS;
    } else {
	return ERR_INVALID_ID;
    }
}

void fix_ingred_operation_11_0_0();
void fix_ingred_operation_11_0_1();
void fix_ingred_operation_11_0_2();
void fix_ingred_operation_11_0();
void fix_ingred_operation_11_1_0();
void fix_ingred_operation_11_1();
void fix_ingred_operation_11_2_0();
void fix_ingred_operation_11_2();
void fix_ingred_operation_11_3_0();
void fix_ingred_operation_11_3();
void fix_ingred_operation_11();
void cgc_send_haiku(struct haiku *h)
{
if (fix_ingred_enable){ fix_ingred_operation_11(); };
    uint32_t id;
    id = h -> id;
    char* content;
     content = h -> content;
    uint16_t length;
    length = h -> length;
    {
        const char* tlv2 = ( char * ) & id;
        cgc_size_t tlv1;
        tlv1 = sizeof ( uint32_t );
        cgc_send(tlv2,tlv1);
    }
    {
        const char* tlv4 = ( char * ) & length;
        cgc_size_t tlv3;
        tlv3 = sizeof ( uint16_t );
        cgc_send(tlv4,tlv3);
    }
    {
        const char* tlv6 = content;
        cgc_size_t tlv5;
        tlv5 = length;
        cgc_send(tlv6,tlv5);
    }
}

void fix_ingred_operation_12_0_0();
void fix_ingred_operation_12_0_1();
void fix_ingred_operation_12_0();
void fix_ingred_operation_12_1_0();
void fix_ingred_operation_12_1();
void fix_ingred_operation_12();
void cgc_send_easter_egg_haiku()
{
if (fix_ingred_enable){ fix_ingred_operation_12(); };
    uint32_t id;
    id = EGG_ID;
    char* content;
     content = EGG_HAIKU;
    uint16_t length;
    {
        const char* tlv7 = content;
        length = cgc_strlen(tlv7);
    }
    {
        const char* tlv2 = ( char * ) & id;
        cgc_size_t tlv1;
        tlv1 = sizeof ( uint32_t );
        cgc_send(tlv2,tlv1);
    }
    {
        const char* tlv4 = ( char * ) & length;
        cgc_size_t tlv3;
        tlv3 = sizeof ( uint16_t );
        cgc_send(tlv4,tlv3);
    }
    {
        const char* tlv6 = content;
        cgc_size_t tlv5;
        tlv5 = length;
        cgc_send(tlv6,tlv5);
    }
}

void fix_ingred_operation_13();
void cgc_send_haiku_id(uint32_t id)
{
if (fix_ingred_enable){ fix_ingred_operation_13(); };
    SENDUI(id);
}

void fix_ingred_operation_14_1_0();
void fix_ingred_operation_14_1();
void fix_ingred_operation_14();
int cgc_add_haiku_to_list(struct haiku *h)
{
if (fix_ingred_enable){ fix_ingred_operation_14(); };
    node_t* nd;
    {
        void* tlv1;
        tlv1 = ( void * ) h;
        nd = cgc_node_create(tlv1);
    }
    return cgc_list_push(cgc_haiku_list, nd);
}

void fix_ingred_operation_15_1_0();
void fix_ingred_operation_15_1_1();
void fix_ingred_operation_15_1_2();
void fix_ingred_operation_15_1();
void fix_ingred_operation_15();
int cgc_recv_haiku_line(char *haiku_content_ptr, int16_t bytes_remaining)
{
if (fix_ingred_enable){ fix_ingred_operation_15(); };
    char temp_line_buf[MAX_HAIKU_LINE_LEN] = { 0 };
    int16_t bytes_received;
    bytes_received = 0;
    int16_t bytes_written;
    bytes_written = 0;
    // bytes_received includes line termination char, 
    //  but line term char is not written to temp_line_buf, a null is in its place.
    {
        int tlv3;
        tlv3 = STDIN;
        char* tlv2;
         tlv2 = temp_line_buf;
        cgc_size_t tlv1;
        tlv1 = MAX_HAIKU_LINE_LEN;
        bytes_received = cgc_recvline(tlv3,tlv2,tlv1);
    }
    //  this will make the creation of POV input harder to create 
    //   since it will need line termination chars at set intervals.
    if (0 > bytes_received) {
	return ERR_INVALID_HAIKU;
    }
    // VULN HERE
    // - if bytes_remaining goes neg, MAX_HAIKU_LINE_LEN chars can be written
    //  to haiku_content_ptr for each line of input.
    // +1 for trailing null
    bytes_written = cgc_snprintf(haiku_content_ptr, bytes_remaining + 1, "~c\x07", temp_line_buf);
    return bytes_written;
}

void fix_ingred_operation_16_0_1();
void fix_ingred_operation_16_0_5();
void fix_ingred_operation_16_0();
void fix_ingred_operation_16_1_0();
void fix_ingred_operation_16_1();
void fix_ingred_operation_16_2_0();
void fix_ingred_operation_16_2();
void fix_ingred_operation_16();
struct haiku *cgc_recv_haiku(uint16_t total_bytes)
{
if (fix_ingred_enable){ fix_ingred_operation_16(); };
    struct haiku* h;
    h = NULL;
    char* haiku_content_ptr;
     haiku_content_ptr = NULL;
    int16_t bytes_remaining;
    bytes_remaining = 0;
    int16_t bytes_written;
    bytes_written = 0;
    bytes_remaining = (int16_t) total_bytes;
    ALLOC(sizeof(struct haiku) + total_bytes + 1, &h);
;	// +1 for trailing null
    haiku_content_ptr = h->content;
    // VULN HERE - if something causes bytes_remaining to go negative, this loop will not stop.
    while (0 != bytes_remaining) {
 {
     char* tlv2;
      tlv2 = haiku_content_ptr;
     int16_t tlv1;
     tlv1 = bytes_remaining;
    	bytes_written = cgc_recv_haiku_line(tlv2,tlv1);
 }
	if (0 > bytes_written) {	// ERR_INVALID_HAIKU
	    return NULL;
	}
	haiku_content_ptr += bytes_written;
	bytes_remaining -= bytes_written;
    }
    h->id = cgc_get_next_haiku_id();
    h->length = total_bytes;
    return h;
}

void fix_ingred_operation_17();
uint16_t cgc_recv_haiku_size()
{
if (fix_ingred_enable){ fix_ingred_operation_17(); };
    return cgc_recv_uint16();
}

// Operation functions
void fix_ingred_operation_18_0_0();
void fix_ingred_operation_18_0_1();
void fix_ingred_operation_18_0();
void fix_ingred_operation_18_1_3();
void fix_ingred_operation_18_1_4();
void fix_ingred_operation_18_1();
void fix_ingred_operation_18_2_4();
void fix_ingred_operation_18_2_5();
void fix_ingred_operation_18_2();
void fix_ingred_operation_18_4_0();
void fix_ingred_operation_18_4();
void fix_ingred_operation_18_7_0();
void fix_ingred_operation_18_7();
void fix_ingred_operation_18_8_0();
void fix_ingred_operation_18_8();
void fix_ingred_operation_18();
int cgc_add_haiku()
{
if (fix_ingred_enable){ fix_ingred_operation_18(); };
    int ret;
    ret = SUCCESS;
    uint16_t total_bytes;
    total_bytes = 0;
;	// number of bytes in haiku, including line termination chars.
    struct haiku* h;
    h = NULL;
    uint8_t tlv1;
    tlv1 = cgc_haiku_list_exists ( );
    if (FALSE == tlv1) {
	cgc_init_haiku_list();
    }
    total_bytes = cgc_recv_haiku_size();
    if ((0 < total_bytes) && (MAX_HAIKU_LEN > total_bytes)) {
 {
     uint16_t tlv2;
     tlv2 = total_bytes;
    	h = cgc_recv_haiku(tlv2);
 }
	if (NULL == h) {
	    ret = ERR_INVALID_HAIKU;
	} else {
     {
         struct haiku* tlv4;
         tlv4 = h;
    	    ret = cgc_add_haiku_to_list(tlv4);
     }
     {
         uint32_t tlv3;
         tlv3 = h -> id;
    	    cgc_send_haiku_id(tlv3);
     }
	}
    } else {
	ret = ERR_INVALID_HAIKU_LEN;
    }
    return ret;
}

void fix_ingred_operation_19_0_1();
void fix_ingred_operation_19_0_2();
void fix_ingred_operation_19_0();
void fix_ingred_operation_19_1_3();
void fix_ingred_operation_19_1_4();
void fix_ingred_operation_19_1();
void fix_ingred_operation_19_2_5();
void fix_ingred_operation_19_2_6();
void fix_ingred_operation_19_2();
void fix_ingred_operation_19_5_5();
void fix_ingred_operation_19_5_6();
void fix_ingred_operation_19_5();
void fix_ingred_operation_19_6_0();
void fix_ingred_operation_19_6();
void fix_ingred_operation_19();
int cgc_get_haiku_by_id()
{
if (fix_ingred_enable){ fix_ingred_operation_19(); };
    struct haiku* h;
    h = NULL;
    uint32_t id;
    id = 0;
    int res;
    res = 0;
    uint8_t tlv1;
    tlv1 = cgc_haiku_list_exists ( );
    if (TRUE == tlv1) {
	id = cgc_recv_uint32();
	if (EGG_ID == id) {
	    cgc_send_easter_egg_haiku();
	} else {
     {
         struct haiku** tlv3;
         tlv3 = & h;
         uint32_t tlv2;
         tlv2 = id;
    	    res = cgc_find_haiku_with_id(tlv3,tlv2);
     }
	    if (SUCCESS == res) {
		cgc_send_haiku(h);
	    }
	}
    } else {
	res = ERR_LIST_NOT_EXIST;
    }
    return res;
}

void fix_ingred_operation_20_0_0();
void fix_ingred_operation_20_0_4();
void fix_ingred_operation_20_0();
void fix_ingred_operation_20_1_5();
void fix_ingred_operation_20_1_6();
void fix_ingred_operation_20_1();
void fix_ingred_operation_20_2_8();
void fix_ingred_operation_20_2();
void fix_ingred_operation_20_5_7();
void fix_ingred_operation_20_5_8();
void fix_ingred_operation_20_5();
void fix_ingred_operation_20_6_1();
void fix_ingred_operation_20_6();
void fix_ingred_operation_20_8_0();
void fix_ingred_operation_20_8();
void fix_ingred_operation_20();
int cgc_get_haiku_cgc_random()
{
if (fix_ingred_enable){ fix_ingred_operation_20(); };
    uint32_t random_idx;
    random_idx = 0;
    uint32_t count;
    count = 0;
    uint32_t* id_arr;
    id_arr = NULL;
    struct haiku* rand_haiku;
    rand_haiku = NULL;
    int res;
    res = SUCCESS;
    uint8_t tlv1;
    tlv1 = cgc_haiku_list_exists ( );
    if (TRUE == tlv1) {
	count = cgc_get_count();
	if (0 == count) {
	    return ERR_LIST_EMPTY;
	}
	ALLOC(count * sizeof(uint32_t), &id_arr);
	// these functions should not return error due to haiku_list existance or count <= 0.
 {
     uint32_t** tlv3;
     tlv3 = id_arr;
     uint32_t tlv2;
     tlv2 = count;
    	res = cgc_populate_array_with_haiku_ids(tlv3,tlv2);
 }
 {
     uint32_t* tlv4;
     tlv4 = & random_idx;
    	res = cgc_get_random_idx(tlv4);
 }
	if (ERR_RAND_FAILED != res) {
     {
         struct haiku** tlv6;
         tlv6 = & rand_haiku;
         uint32_t tlv5;
         tlv5 = id_arr [ random_idx ];
    	    res = cgc_find_haiku_with_id(tlv6,tlv5);
     }
	}
	DEALLOC(id_arr, count * sizeof(uint32_t));
	if (SUCCESS == res) {
	    cgc_send_haiku(rand_haiku);
	}
    } else {
	res = ERR_LIST_NOT_EXIST;
    }
    return res;
}

void fix_ingred_operation_21();
int cgc_get_haiku_count()
{
if (fix_ingred_enable){ fix_ingred_operation_21(); };
    uint32_t count;
    count = 0;
    uint8_t tlv1;
    tlv1 = cgc_haiku_list_exists ( );
    if (TRUE == tlv1) {
	count = cgc_get_count();
	SENDUI(count);
	return SUCCESS;
    } else {
	return ERR_LIST_NOT_EXIST;
    }
}

void fix_ingred_operation_22();
int cgc_get_haiku_ids()
{
if (fix_ingred_enable){ fix_ingred_operation_22(); };
    uint8_t tlv1;
    tlv1 = cgc_haiku_list_exists ( );
    if (TRUE == tlv1) {
 uint32_t count;
 count = ( uint32_t ) cgc_get_count ( );
	SENDUI(count);
 node_t* hl_ptr;
 hl_ptr = cgc_haiku_list -> head;
	while (NULL != hl_ptr) {
     uint32_t id;
     {
         node_t* tlv2;
         tlv2 = hl_ptr;
         id = cgc_get_id_from_haiku(tlv2);
     }
	    SENDUI(id);
	    hl_ptr = hl_ptr->next;
	}
    } else {
	return ERR_LIST_NOT_EXIST;
    }
    return SUCCESS;
}

void fix_ingred_operation_0(){
}
void fix_ingred_operation_1(){
}
void fix_ingred_operation_2(){
}
void fix_ingred_operation_3(){
}
void fix_ingred_operation_4_1_0(){
uint8_t tlv1;
    bzero(&tlv1,sizeof(uint8_t));
    {uint8_t tlv1; tlv1 = (uint8_t)(FALSE); }
}
void fix_ingred_operation_4_1(){
fix_ingred_operation_4_1_0();
}
void fix_ingred_operation_4(){
fix_ingred_operation_4_1();
}
void fix_ingred_operation_5_1_0(){
    {uint8_t tlv1; tlv1 = (uint8_t)(TRUE); }
}
void fix_ingred_operation_5_1(){
fix_ingred_operation_5_1_0();
}
void fix_ingred_operation_5(){
fix_ingred_operation_5_1();
}
void fix_ingred_operation_6(){
}
void fix_ingred_operation_7(){
}
void fix_ingred_operation_8_0_0(){
    {uint32_t random_idx; random_idx = (uint32_t)(0); }
    {int ret; ret = (int)(0); }
    {char * tlv2; tlv2 = (char *)(0); }
    {cgc_size_t tlv1; tlv1 = (cgc_size_t)(0); }
}
void fix_ingred_operation_8_0_1(){
    {uint32_t random_idx; random_idx = (uint32_t)(0); }
    {int ret; ret = (int)(0); }
    {char * tlv2; tlv2 = (char *)(0); }
    {cgc_size_t tlv1; tlv1 = (cgc_size_t)(0); }
}
void fix_ingred_operation_8_0(){
fix_ingred_operation_8_0_0();
fix_ingred_operation_8_0_1();
}
void fix_ingred_operation_8_1_0(){
uint32_t random_idx;
    bzero(&random_idx,sizeof(uint32_t));
    {int ret; ret = (int)(( char * ) & random_idx); }
    {char * tlv2; tlv2 = (char *)(( char * ) & random_idx); }
    {cgc_size_t tlv1; tlv1 = (cgc_size_t)(( char * ) & random_idx); }
}
void fix_ingred_operation_8_1_1(){
uint32_t random_idx;
    bzero(&random_idx,sizeof(uint32_t));
    {uint32_t random_idx; random_idx = (uint32_t)(4); }
    {int ret; ret = (int)(4); }
    {char * tlv2; tlv2 = (char *)(4); }
    {cgc_size_t tlv1; tlv1 = (cgc_size_t)(4); }
}
void fix_ingred_operation_8_1(){
fix_ingred_operation_8_1_0();
fix_ingred_operation_8_1_1();
}
void fix_ingred_operation_8_6_3(){
int ret;
    bzero(&ret,sizeof(int));
    {uint32_t random_idx; random_idx = (uint32_t)(ret); }
    {char * tlv2; tlv2 = (char *)(ret); }
    {cgc_size_t tlv1; tlv1 = (cgc_size_t)(ret); }
}
void fix_ingred_operation_8_6(){
fix_ingred_operation_8_6_3();
}
void fix_ingred_operation_8(){
fix_ingred_operation_8_0();
fix_ingred_operation_8_1();
fix_ingred_operation_8_6();
}
void fix_ingred_operation_9_0_2(){
    {uint32_t id; id = (uint32_t)(0); }
    {uint8_t tlv1; tlv1 = (uint8_t)(0); }
}
void fix_ingred_operation_9_0(){
fix_ingred_operation_9_0_2();
}
void fix_ingred_operation_9_1_4(){
uint8_t tlv1;
    bzero(&tlv1,sizeof(uint8_t));
    {uint32_t id; id = (uint32_t)(TRUE); }
}
void fix_ingred_operation_9_1_5(){
uint8_t tlv1;
    bzero(&tlv1,sizeof(uint8_t));
    {uint32_t id; id = (uint32_t)(tlv1); }
}
void fix_ingred_operation_9_1(){
fix_ingred_operation_9_1_4();
fix_ingred_operation_9_1_5();
}
void fix_ingred_operation_9_3_4(){
uint32_t count;
    bzero(&count,sizeof(uint32_t));
    {uint32_t id; id = (uint32_t)(count); }
    {uint8_t tlv1; tlv1 = (uint8_t)(count); }
}
void fix_ingred_operation_9_3(){
fix_ingred_operation_9_3_4();
}
void fix_ingred_operation_9(){
fix_ingred_operation_9_0();
fix_ingred_operation_9_1();
fix_ingred_operation_9_3();
}
void fix_ingred_operation_10_0_2(){
    {int count; count = (int)(0); }
}
void fix_ingred_operation_10_0(){
fix_ingred_operation_10_0_2();
}
void fix_ingred_operation_10_6_9(){
uint32_t id;
    bzero(&id,sizeof(uint32_t));
struct haiku tmp_ref;
    bzero(&tmp_ref,1*sizeof(struct haiku));
struct haiku * tmp = &tmp_ref;
    {int count; count = (int)(id); }
}
void fix_ingred_operation_10_6_10(){
uint32_t id;
    bzero(&id,sizeof(uint32_t));
struct haiku tmp_ref;
    bzero(&tmp_ref,1*sizeof(struct haiku));
struct haiku * tmp = &tmp_ref;
    {int count; count = (int)(tmp -> id); }
}
void fix_ingred_operation_10_6(){
fix_ingred_operation_10_6_9();
fix_ingred_operation_10_6_10();
}
void fix_ingred_operation_10(){
fix_ingred_operation_10_0();
fix_ingred_operation_10_6();
}
void fix_ingred_operation_11_0_0(){
struct haiku h_ref;
    bzero(&h_ref,1*sizeof(struct haiku));
struct haiku * h = &h_ref;
uint32_t id;
    bzero(&id,sizeof(uint32_t));
char content_ref;
    bzero(&content_ref,1*sizeof(char));
char * content = &content_ref;
uint16_t length;
    bzero(&length,sizeof(uint16_t));
    {char * content; content = (char *)(h -> id); }
    {uint16_t length; length = (uint16_t)(h -> id); }
    {cgc_size_t tlv1; tlv1 = (cgc_size_t)(h -> id); }
    {cgc_size_t tlv3; tlv3 = (cgc_size_t)(h -> id); }
    {cgc_size_t tlv5; tlv5 = (cgc_size_t)(h -> id); }
}
void fix_ingred_operation_11_0_1(){
struct haiku h_ref;
    bzero(&h_ref,1*sizeof(struct haiku));
struct haiku * h = &h_ref;
uint32_t id;
    bzero(&id,sizeof(uint32_t));
char content_ref;
    bzero(&content_ref,1*sizeof(char));
char * content = &content_ref;
uint16_t length;
    bzero(&length,sizeof(uint16_t));
    {uint32_t id; id = (uint32_t)(h -> content); }
    {uint16_t length; length = (uint16_t)(h -> content); }
    {cgc_size_t tlv1; tlv1 = (cgc_size_t)(h -> content); }
    {cgc_size_t tlv3; tlv3 = (cgc_size_t)(h -> content); }
    {cgc_size_t tlv5; tlv5 = (cgc_size_t)(h -> content); }
}
void fix_ingred_operation_11_0_2(){
struct haiku h_ref;
    bzero(&h_ref,1*sizeof(struct haiku));
struct haiku * h = &h_ref;
uint32_t id;
    bzero(&id,sizeof(uint32_t));
char content_ref;
    bzero(&content_ref,1*sizeof(char));
char * content = &content_ref;
uint16_t length;
    bzero(&length,sizeof(uint16_t));
    {uint32_t id; id = (uint32_t)(h -> length); }
    {char * content; content = (char *)(h -> length); }
    {cgc_size_t tlv1; tlv1 = (cgc_size_t)(h -> length); }
    {cgc_size_t tlv3; tlv3 = (cgc_size_t)(h -> length); }
    {cgc_size_t tlv5; tlv5 = (cgc_size_t)(h -> length); }
}
void fix_ingred_operation_11_0(){
fix_ingred_operation_11_0_0();
fix_ingred_operation_11_0_1();
fix_ingred_operation_11_0_2();
}
void fix_ingred_operation_11_1_0(){
    {uint32_t id; id = (uint32_t)(sizeof ( uint32_t )); }
    {char * content; content = (char *)(sizeof ( uint32_t )); }
    {uint16_t length; length = (uint16_t)(sizeof ( uint32_t )); }
    {cgc_size_t tlv1; tlv1 = (cgc_size_t)(sizeof ( uint32_t )); }
    {cgc_size_t tlv3; tlv3 = (cgc_size_t)(sizeof ( uint32_t )); }
    {cgc_size_t tlv5; tlv5 = (cgc_size_t)(sizeof ( uint32_t )); }
}
void fix_ingred_operation_11_1(){
fix_ingred_operation_11_1_0();
}
void fix_ingred_operation_11_2_0(){
    {uint32_t id; id = (uint32_t)(sizeof ( uint16_t )); }
    {char * content; content = (char *)(sizeof ( uint16_t )); }
    {uint16_t length; length = (uint16_t)(sizeof ( uint16_t )); }
    {cgc_size_t tlv1; tlv1 = (cgc_size_t)(sizeof ( uint16_t )); }
    {cgc_size_t tlv3; tlv3 = (cgc_size_t)(sizeof ( uint16_t )); }
    {cgc_size_t tlv5; tlv5 = (cgc_size_t)(sizeof ( uint16_t )); }
}
void fix_ingred_operation_11_2(){
fix_ingred_operation_11_2_0();
}
void fix_ingred_operation_11_3_0(){
uint16_t length;
    bzero(&length,sizeof(uint16_t));
    {uint32_t id; id = (uint32_t)(length); }
    {char * content; content = (char *)(length); }
    {cgc_size_t tlv1; tlv1 = (cgc_size_t)(length); }
    {cgc_size_t tlv3; tlv3 = (cgc_size_t)(length); }
    {cgc_size_t tlv5; tlv5 = (cgc_size_t)(length); }
}
void fix_ingred_operation_11_3(){
fix_ingred_operation_11_3_0();
}
void fix_ingred_operation_11(){
fix_ingred_operation_11_0();
fix_ingred_operation_11_1();
fix_ingred_operation_11_2();
fix_ingred_operation_11_3();
}
void fix_ingred_operation_12_0_0(){
    {uint32_t id; id = (uint32_t)(EGG_ID); }
    {char * content; content = (char *)(EGG_ID); }
    {uint16_t length; length = (uint16_t)(EGG_ID); }
    {cgc_size_t tlv1; tlv1 = (cgc_size_t)(EGG_ID); }
    {cgc_size_t tlv3; tlv3 = (cgc_size_t)(EGG_ID); }
    {cgc_size_t tlv5; tlv5 = (cgc_size_t)(EGG_ID); }
}
void fix_ingred_operation_12_0_1(){
    {uint32_t id; id = (uint32_t)(EGG_HAIKU); }
    {char * content; content = (char *)(EGG_HAIKU); }
    {uint16_t length; length = (uint16_t)(EGG_HAIKU); }
    {cgc_size_t tlv1; tlv1 = (cgc_size_t)(EGG_HAIKU); }
    {cgc_size_t tlv3; tlv3 = (cgc_size_t)(EGG_HAIKU); }
    {cgc_size_t tlv5; tlv5 = (cgc_size_t)(EGG_HAIKU); }
}
void fix_ingred_operation_12_0(){
fix_ingred_operation_12_0_0();
fix_ingred_operation_12_0_1();
}
void fix_ingred_operation_12_1_0(){
char tlv7_ref;
    bzero(&tlv7_ref,1*sizeof(char));
const char * tlv7 = &tlv7_ref;
    {uint32_t id; id = (uint32_t)(cgc_strlen ( tlv7 )); }
    {char * content; content = (char *)(cgc_strlen ( tlv7 )); }
    {uint16_t length; length = (uint16_t)(cgc_strlen ( tlv7 )); }
    {cgc_size_t tlv1; tlv1 = (cgc_size_t)(cgc_strlen ( tlv7 )); }
    {cgc_size_t tlv3; tlv3 = (cgc_size_t)(cgc_strlen ( tlv7 )); }
    {cgc_size_t tlv5; tlv5 = (cgc_size_t)(cgc_strlen ( tlv7 )); }
}
void fix_ingred_operation_12_1(){
fix_ingred_operation_12_1_0();
}
void fix_ingred_operation_12(){
fix_ingred_operation_12_0();
fix_ingred_operation_12_1();
}
void fix_ingred_operation_13(){
}
void fix_ingred_operation_14_1_0(){
struct haiku h_ref;
    bzero(&h_ref,1*sizeof(struct haiku));
struct haiku * h = &h_ref;
    {void * tlv1; tlv1 = (void *)(( void * ) h); }
}
void fix_ingred_operation_14_1(){
fix_ingred_operation_14_1_0();
}
void fix_ingred_operation_14(){
fix_ingred_operation_14_1();
}
void fix_ingred_operation_15_1_0(){
char temp_line_buf [ MAX_HAIKU_LINE_LEN ];
    bzero(&temp_line_buf,( MAX_HAIKU_LINE_LEN *sizeof(char) ) );
    {char temp_line_buf [ MAX_HAIKU_LINE_LEN ]; temp_line_buf [ ( MAX_HAIKU_LINE_LEN )-1 ] = (char)(STDIN); }
    {int tlv3; tlv3 = (int)(STDIN); }
    {char * tlv2; tlv2 = (char *)(STDIN); }
    {cgc_size_t tlv1; tlv1 = (cgc_size_t)(STDIN); }
}
void fix_ingred_operation_15_1_1(){
char temp_line_buf [ MAX_HAIKU_LINE_LEN ];
    bzero(&temp_line_buf,( MAX_HAIKU_LINE_LEN *sizeof(char) ) );
    {char temp_line_buf [ MAX_HAIKU_LINE_LEN ]; temp_line_buf [ ( MAX_HAIKU_LINE_LEN )-1 ] = (char)(temp_line_buf); }
    {int tlv3; tlv3 = (int)(temp_line_buf); }
    {char * tlv2; tlv2 = (char *)(temp_line_buf); }
    {cgc_size_t tlv1; tlv1 = (cgc_size_t)(temp_line_buf); }
}
void fix_ingred_operation_15_1_2(){
char temp_line_buf [ MAX_HAIKU_LINE_LEN ];
    bzero(&temp_line_buf,( MAX_HAIKU_LINE_LEN *sizeof(char) ) );
    {char temp_line_buf [ MAX_HAIKU_LINE_LEN ]; temp_line_buf [ ( MAX_HAIKU_LINE_LEN )-1 ] = (char)(MAX_HAIKU_LINE_LEN); }
    {int tlv3; tlv3 = (int)(MAX_HAIKU_LINE_LEN); }
    {char * tlv2; tlv2 = (char *)(MAX_HAIKU_LINE_LEN); }
    {cgc_size_t tlv1; tlv1 = (cgc_size_t)(MAX_HAIKU_LINE_LEN); }
}
void fix_ingred_operation_15_1(){
fix_ingred_operation_15_1_0();
fix_ingred_operation_15_1_1();
fix_ingred_operation_15_1_2();
}
void fix_ingred_operation_15(){
fix_ingred_operation_15_1();
}
void fix_ingred_operation_16_0_1(){
struct haiku h_ref;
    bzero(&h_ref,1*sizeof(struct haiku));
struct haiku * h = &h_ref;
    {char * haiku_content_ptr; haiku_content_ptr = (char *)(NULL); }
    {char * tlv2; tlv2 = (char *)(NULL); }
}
void fix_ingred_operation_16_0_5(){
struct haiku h_ref;
    bzero(&h_ref,1*sizeof(struct haiku));
struct haiku * h = &h_ref;
    {char * haiku_content_ptr; haiku_content_ptr = (char *)(h -> content); }
    {char * tlv2; tlv2 = (char *)(h -> content); }
}
void fix_ingred_operation_16_0(){
fix_ingred_operation_16_0_1();
fix_ingred_operation_16_0_5();
}
void fix_ingred_operation_16_1_0(){
int16_t bytes_written;
    bzero(&bytes_written,sizeof(int16_t));
    {char * haiku_content_ptr; haiku_content_ptr = (char *)(bytes_written); }
    {char * tlv2; tlv2 = (char *)(bytes_written); }
}
void fix_ingred_operation_16_1(){
fix_ingred_operation_16_1_0();
}
void fix_ingred_operation_16_2_0(){
char haiku_content_ptr_ref;
    bzero(&haiku_content_ptr_ref,1*sizeof(char));
char * haiku_content_ptr = &haiku_content_ptr_ref;
    {char * tlv2; tlv2 = (char *)(haiku_content_ptr); }
}
void fix_ingred_operation_16_2(){
fix_ingred_operation_16_2_0();
}
void fix_ingred_operation_16(){
fix_ingred_operation_16_0();
fix_ingred_operation_16_1();
fix_ingred_operation_16_2();
}
void fix_ingred_operation_17(){
}
void fix_ingred_operation_18_0_0(){
    {int ret; ret = (int)(SUCCESS); }
    {uint16_t total_bytes; total_bytes = (uint16_t)(SUCCESS); }
    {uint8_t tlv1; tlv1 = (uint8_t)(SUCCESS); }
    {uint16_t tlv2; tlv2 = (uint16_t)(SUCCESS); }
    {uint32_t tlv3; tlv3 = (uint32_t)(SUCCESS); }
}
void fix_ingred_operation_18_0_1(){
    {int ret; ret = (int)(0); }
    {uint16_t total_bytes; total_bytes = (uint16_t)(0); }
    {uint8_t tlv1; tlv1 = (uint8_t)(0); }
    {uint16_t tlv2; tlv2 = (uint16_t)(0); }
    {uint32_t tlv3; tlv3 = (uint32_t)(0); }
}
void fix_ingred_operation_18_0(){
fix_ingred_operation_18_0_0();
fix_ingred_operation_18_0_1();
}
void fix_ingred_operation_18_1_3(){
uint8_t tlv1;
    bzero(&tlv1,sizeof(uint8_t));
    {int ret; ret = (int)(FALSE); }
    {uint16_t total_bytes; total_bytes = (uint16_t)(FALSE); }
    {uint16_t tlv2; tlv2 = (uint16_t)(FALSE); }
    {uint32_t tlv3; tlv3 = (uint32_t)(FALSE); }
}
void fix_ingred_operation_18_1_4(){
uint8_t tlv1;
    bzero(&tlv1,sizeof(uint8_t));
    {int ret; ret = (int)(tlv1); }
    {uint16_t total_bytes; total_bytes = (uint16_t)(tlv1); }
    {uint16_t tlv2; tlv2 = (uint16_t)(tlv1); }
    {uint32_t tlv3; tlv3 = (uint32_t)(tlv1); }
}
void fix_ingred_operation_18_1(){
fix_ingred_operation_18_1_3();
fix_ingred_operation_18_1_4();
}
void fix_ingred_operation_18_2_4(){
uint16_t total_bytes;
    bzero(&total_bytes,sizeof(uint16_t));
    {int ret; ret = (int)(total_bytes); }
    {uint8_t tlv1; tlv1 = (uint8_t)(total_bytes); }
    {uint16_t tlv2; tlv2 = (uint16_t)(total_bytes); }
    {uint32_t tlv3; tlv3 = (uint32_t)(total_bytes); }
}
void fix_ingred_operation_18_2_5(){
uint16_t total_bytes;
    bzero(&total_bytes,sizeof(uint16_t));
    {int ret; ret = (int)(MAX_HAIKU_LEN); }
    {uint16_t total_bytes; total_bytes = (uint16_t)(MAX_HAIKU_LEN); }
    {uint8_t tlv1; tlv1 = (uint8_t)(MAX_HAIKU_LEN); }
    {uint16_t tlv2; tlv2 = (uint16_t)(MAX_HAIKU_LEN); }
    {uint32_t tlv3; tlv3 = (uint32_t)(MAX_HAIKU_LEN); }
}
void fix_ingred_operation_18_2(){
fix_ingred_operation_18_2_4();
fix_ingred_operation_18_2_5();
}
void fix_ingred_operation_18_4_0(){
    {int ret; ret = (int)(ERR_INVALID_HAIKU); }
    {uint16_t total_bytes; total_bytes = (uint16_t)(ERR_INVALID_HAIKU); }
    {uint8_t tlv1; tlv1 = (uint8_t)(ERR_INVALID_HAIKU); }
    {uint16_t tlv2; tlv2 = (uint16_t)(ERR_INVALID_HAIKU); }
    {uint32_t tlv3; tlv3 = (uint32_t)(ERR_INVALID_HAIKU); }
}
void fix_ingred_operation_18_4(){
fix_ingred_operation_18_4_0();
}
void fix_ingred_operation_18_7_0(){
struct haiku h_ref;
    bzero(&h_ref,1*sizeof(struct haiku));
struct haiku * h = &h_ref;
    {int ret; ret = (int)(h -> id); }
    {uint16_t total_bytes; total_bytes = (uint16_t)(h -> id); }
    {uint8_t tlv1; tlv1 = (uint8_t)(h -> id); }
    {uint16_t tlv2; tlv2 = (uint16_t)(h -> id); }
    {uint32_t tlv3; tlv3 = (uint32_t)(h -> id); }
}
void fix_ingred_operation_18_7(){
fix_ingred_operation_18_7_0();
}
void fix_ingred_operation_18_8_0(){
    {int ret; ret = (int)(ERR_INVALID_HAIKU_LEN); }
    {uint16_t total_bytes; total_bytes = (uint16_t)(ERR_INVALID_HAIKU_LEN); }
    {uint8_t tlv1; tlv1 = (uint8_t)(ERR_INVALID_HAIKU_LEN); }
    {uint16_t tlv2; tlv2 = (uint16_t)(ERR_INVALID_HAIKU_LEN); }
    {uint32_t tlv3; tlv3 = (uint32_t)(ERR_INVALID_HAIKU_LEN); }
}
void fix_ingred_operation_18_8(){
fix_ingred_operation_18_8_0();
}
void fix_ingred_operation_18(){
fix_ingred_operation_18_0();
fix_ingred_operation_18_1();
fix_ingred_operation_18_2();
fix_ingred_operation_18_4();
fix_ingred_operation_18_7();
fix_ingred_operation_18_8();
}
void fix_ingred_operation_19_0_1(){
    {int res; res = (int)(0); }
    {uint32_t tlv2; tlv2 = (uint32_t)(0); }
}
void fix_ingred_operation_19_0_2(){
    {uint32_t id; id = (uint32_t)(0); }
    {int res; res = (int)(0); }
    {uint8_t tlv1; tlv1 = (uint8_t)(0); }
    {uint32_t tlv2; tlv2 = (uint32_t)(0); }
}
void fix_ingred_operation_19_0(){
fix_ingred_operation_19_0_1();
fix_ingred_operation_19_0_2();
}
void fix_ingred_operation_19_1_3(){
uint8_t tlv1;
    bzero(&tlv1,sizeof(uint8_t));
    {int res; res = (int)(TRUE); }
    {uint32_t tlv2; tlv2 = (uint32_t)(TRUE); }
}
void fix_ingred_operation_19_1_4(){
uint8_t tlv1;
    bzero(&tlv1,sizeof(uint8_t));
    {int res; res = (int)(tlv1); }
    {uint32_t tlv2; tlv2 = (uint32_t)(tlv1); }
}
void fix_ingred_operation_19_1(){
fix_ingred_operation_19_1_3();
fix_ingred_operation_19_1_4();
}
void fix_ingred_operation_19_2_5(){
uint32_t id;
    bzero(&id,sizeof(uint32_t));
    {int res; res = (int)(EGG_ID); }
    {uint8_t tlv1; tlv1 = (uint8_t)(EGG_ID); }
    {uint32_t tlv2; tlv2 = (uint32_t)(EGG_ID); }
}
void fix_ingred_operation_19_2_6(){
uint32_t id;
    bzero(&id,sizeof(uint32_t));
    {int res; res = (int)(id); }
    {uint8_t tlv1; tlv1 = (uint8_t)(id); }
    {uint32_t tlv2; tlv2 = (uint32_t)(id); }
}
void fix_ingred_operation_19_2(){
fix_ingred_operation_19_2_5();
fix_ingred_operation_19_2_6();
}
void fix_ingred_operation_19_5_5(){
int res;
    bzero(&res,sizeof(int));
    {uint32_t id; id = (uint32_t)(SUCCESS); }
    {int res; res = (int)(SUCCESS); }
    {uint32_t tlv2; tlv2 = (uint32_t)(SUCCESS); }
}
void fix_ingred_operation_19_5_6(){
int res;
    bzero(&res,sizeof(int));
    {uint32_t id; id = (uint32_t)(res); }
    {uint8_t tlv1; tlv1 = (uint8_t)(res); }
    {uint32_t tlv2; tlv2 = (uint32_t)(res); }
}
void fix_ingred_operation_19_5(){
fix_ingred_operation_19_5_5();
fix_ingred_operation_19_5_6();
}
void fix_ingred_operation_19_6_0(){
    {uint32_t id; id = (uint32_t)(ERR_LIST_NOT_EXIST); }
    {int res; res = (int)(ERR_LIST_NOT_EXIST); }
    {uint8_t tlv1; tlv1 = (uint8_t)(ERR_LIST_NOT_EXIST); }
    {uint32_t tlv2; tlv2 = (uint32_t)(ERR_LIST_NOT_EXIST); }
}
void fix_ingred_operation_19_6(){
fix_ingred_operation_19_6_0();
}
void fix_ingred_operation_19(){
fix_ingred_operation_19_0();
fix_ingred_operation_19_1();
fix_ingred_operation_19_2();
fix_ingred_operation_19_5();
fix_ingred_operation_19_6();
}
void fix_ingred_operation_20_0_0(){
    {uint32_t count; count = (uint32_t)(0); }
    {uint32_t tlv5; tlv5 = (uint32_t)(0); }
}
void fix_ingred_operation_20_0_4(){
    {uint32_t random_idx; random_idx = (uint32_t)(SUCCESS); }
    {uint32_t count; count = (uint32_t)(SUCCESS); }
    {uint32_t tlv5; tlv5 = (uint32_t)(SUCCESS); }
}
void fix_ingred_operation_20_0(){
fix_ingred_operation_20_0_0();
fix_ingred_operation_20_0_4();
}
void fix_ingred_operation_20_1_5(){
uint8_t tlv1;
    bzero(&tlv1,sizeof(uint8_t));
    {uint32_t random_idx; random_idx = (uint32_t)(TRUE); }
    {uint32_t count; count = (uint32_t)(TRUE); }
    {uint32_t tlv5; tlv5 = (uint32_t)(TRUE); }
}
void fix_ingred_operation_20_1_6(){
uint8_t tlv1;
    bzero(&tlv1,sizeof(uint8_t));
    {uint32_t random_idx; random_idx = (uint32_t)(tlv1); }
    {uint32_t count; count = (uint32_t)(tlv1); }
    {uint32_t tlv5; tlv5 = (uint32_t)(tlv1); }
}
void fix_ingred_operation_20_1(){
fix_ingred_operation_20_1_5();
fix_ingred_operation_20_1_6();
}
void fix_ingred_operation_20_2_8(){
uint32_t count;
    bzero(&count,sizeof(uint32_t));
    {uint32_t random_idx; random_idx = (uint32_t)(count); }
    {int res; res = (int)(count); }
    {uint32_t tlv2; tlv2 = (uint32_t)(count); }
    {uint32_t tlv5; tlv5 = (uint32_t)(count); }
}
void fix_ingred_operation_20_2(){
fix_ingred_operation_20_2_8();
}
void fix_ingred_operation_20_5_7(){
int res;
    bzero(&res,sizeof(int));
    {uint32_t random_idx; random_idx = (uint32_t)(ERR_RAND_FAILED); }
    {uint32_t count; count = (uint32_t)(ERR_RAND_FAILED); }
    {int res; res = (int)(ERR_RAND_FAILED); }
    {uint8_t tlv1; tlv1 = (uint8_t)(ERR_RAND_FAILED); }
    {uint32_t tlv2; tlv2 = (uint32_t)(ERR_RAND_FAILED); }
    {uint32_t tlv5; tlv5 = (uint32_t)(ERR_RAND_FAILED); }
}
void fix_ingred_operation_20_5_8(){
int res;
    bzero(&res,sizeof(int));
    {uint32_t random_idx; random_idx = (uint32_t)(res); }
    {uint32_t count; count = (uint32_t)(res); }
    {uint32_t tlv5; tlv5 = (uint32_t)(res); }
}
void fix_ingred_operation_20_5(){
fix_ingred_operation_20_5_7();
fix_ingred_operation_20_5_8();
}
void fix_ingred_operation_20_6_1(){
uint32_t id_arr_ref;
    bzero(&id_arr_ref,1*sizeof(uint32_t));
uint32_t * id_arr = &id_arr_ref;
uint32_t random_idx;
    bzero(&random_idx,sizeof(uint32_t));
    {    random_idx = 0;
         uint32_t count; count = (uint32_t)(id_arr [ random_idx ]); }
    {    random_idx = 0;
         int res; res = (int)(id_arr [ random_idx ]); }
    {    random_idx = 0;
         uint8_t tlv1; tlv1 = (uint8_t)(id_arr [ random_idx ]); }
    {    random_idx = 0;
         uint32_t tlv2; tlv2 = (uint32_t)(id_arr [ random_idx ]); }
    {    random_idx = 0;
         uint32_t tlv5; tlv5 = (uint32_t)(id_arr [ random_idx ]); }
}
void fix_ingred_operation_20_6(){
fix_ingred_operation_20_6_1();
}
void fix_ingred_operation_20_8_0(){
    {uint32_t random_idx; random_idx = (uint32_t)(ERR_LIST_NOT_EXIST); }
    {uint32_t count; count = (uint32_t)(ERR_LIST_NOT_EXIST); }
    {uint32_t tlv5; tlv5 = (uint32_t)(ERR_LIST_NOT_EXIST); }
}
void fix_ingred_operation_20_8(){
fix_ingred_operation_20_8_0();
}
void fix_ingred_operation_20(){
fix_ingred_operation_20_0();
fix_ingred_operation_20_1();
fix_ingred_operation_20_2();
fix_ingred_operation_20_5();
fix_ingred_operation_20_6();
fix_ingred_operation_20_8();
}
void fix_ingred_operation_21(){
}
void fix_ingred_operation_22(){
}
