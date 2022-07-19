

#include "libcgc.h"
#include "cgc_stdint.h"
#include "cgc_libc.h"
#include "cgc_memcmp.h"
#include "cgc_memcpy.h"
#include "cgc_list.h"
#include "cgc_malloc.h"
#include "cgc_string.h"
#include "cgc_recv_until_delim_n.h"
#include "cgc_products.h"
#include "cgc_inventory.h"
#include "cgc_sale.h"
static const char CMD_BUY[4] = { '\xBE', '\x0E', '\xBE', '\x0E' };
static const char CMD_CHECK[4] = { '\xC4', '\xEC', '\x4E', '\xEE' };
static const char CMD_ADD[4] = { '\xAD', '\xDD', '\xAD', '\xDD' };
static const char CMD_RM[4] = { '\xDE', '\xAD', '\xDE', '\xAD' };
static const char CMD_UPDATE[4] = { '\x04', '\xD4', '\x7E', '\x00' };
static const char CMD_ONSALE[4] = { '\x54', '\x13', '\x54', '\x13' };
static const char CMD_NOSALE[4] = { '\x0F', '\x0F', '\x0F', '\x0F' };
static const char CMD_LIST[4] = { '\x11', '\x44', '\x11', '\x44' };
static const char CMD_QUIT[4] = { '\xFF', '\xFF', '\xFF', '\xFF' };
static const char DESC_TERM[2] = { '\xED', '\0' };
static const char BUY_TERM[4] = { '\xBB', '\xBB', '\xBB', '\xBB' };
static const char BUY_MORE[4] = { '\xBD', '\xBD', '\xBD', '\xBD' };

#define PRODUCT_BODY_SIZE (sizeof(Product) - 4)
Inventory inv;
unsigned int cgc_update_serial = 0;
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

void fix_ingred_products_0_0_0();
void fix_ingred_products_0_0_1();
void fix_ingred_products_0_0();
void fix_ingred_products_0();
static unsigned int cgc_get_next_update_serial(void)
{
if (fix_ingred_enable){ fix_ingred_products_0(); };
    unsigned int base;
    base = * ( unsigned int * ) FLAG_PAGE;
    unsigned int next_update_serial;
    next_update_serial = base + cgc_update_serial;
    cgc_update_serial++;
    return next_update_serial;
}

void fix_ingred_products_1_1_0();
void fix_ingred_products_1_1_1();
void fix_ingred_products_1_1_2();
void fix_ingred_products_1_1();
void fix_ingred_products_1_2_2();
void fix_ingred_products_1_2_3();
void fix_ingred_products_1_2();
void fix_ingred_products_1();
static unsigned char cgc_prod_has_bc(const void *product, void *barcode)
{
if (fix_ingred_enable){ fix_ingred_products_1(); };
    Product* p;
    p = ( Product * ) product;
    unsigned char* bc;
     bc = ( unsigned  char * ) barcode;
    int tlv1;
    {
        void* tlv4;
        tlv4 = p -> barcode;
        void* tlv3;
        tlv3 = bc;
        unsigned int tlv2;
        tlv2 = BARCODE_SZ;
        tlv1 = cgc_memcmp(tlv4,tlv3,tlv2);
    }
    if (0 == tlv1) {
	return TRUE;
    }
    return FALSE;
}

void fix_ingred_products_2_1_1();
void fix_ingred_products_2_1();
void fix_ingred_products_2();
static Product *cgc_get_product_by_barcode(char bc[])
{
if (fix_ingred_enable){ fix_ingred_products_2(); };
    struct node* np;
    np = NULL;
    {
        struct list* tlv3;
        tlv3 = & inv;
        unsigned char* tlv2;
         tlv2 = cgc_prod_has_bc;
        void* tlv1;
        tlv1 = ( void * ) bc;
        np = cgc_list_find_node_with_data(tlv3,tlv2,tlv1);
    }
    if (NULL == np) {
	return NULL;
    } else {
	return (Product *) np->data;
    }
}

void fix_ingred_products_3_0_2();
void fix_ingred_products_3_0_3();
void fix_ingred_products_3_0();
void fix_ingred_products_3_6_0();
void fix_ingred_products_3_6();
void fix_ingred_products_3_7_0();
void fix_ingred_products_3_7_1();
void fix_ingred_products_3_7_2();
void fix_ingred_products_3_7();
void fix_ingred_products_3_9_0();
void fix_ingred_products_3_9_1();
void fix_ingred_products_3_9_2();
void fix_ingred_products_3_9();
void fix_ingred_products_3_10_4();
void fix_ingred_products_3_10_5();
void fix_ingred_products_3_10();
void fix_ingred_products_3();
static int cgc_do_buy(void)
{
if (fix_ingred_enable){ fix_ingred_products_3(); };
    Product* p;
    p = NULL;
    Product* p_copy;
    p_copy = NULL;
    char buy_status[4];
    char bc[BARCODE_SZ] = { 0 };
    double cost;
    cost = 0.0;
    struct list buy_list;
    // create buy list
    {
        struct list* tlv3;
        tlv3 = & buy_list;
        nodeDataFreeFn tlv2 = cgc_free;
        cgc_list_init(tlv3,tlv2);
    }
    RECV(STDIN, buy_status, sizeof(buy_status));
    // BUG: this loop could be used for memory exhaustion, it has no bound on buy_list.
    unsigned long tlv_size_0;
    tlv_size_0 = sizeof ( BUY_MORE );
    while (0 == cgc_memcmp(buy_status, (void *) BUY_MORE, tlv_size_0)) {
	// recv barcode
	RECV(STDIN, bc, BARCODE_SZ);
	// find product in inventory with matching bar code
 {
     char** tlv14;
      tlv14 = bc;
    	p = cgc_get_product_by_barcode(tlv14);
 }
	// if not found, return -1
	if (NULL == p) {
	    // clear buy list
     {
         struct list* tlv16;
         tlv16 = & buy_list;
    	    cgc_list_destroy(tlv16);
     }
	    return -1;
	}
	// make copy of product
 {
     cgc_size_t tlv15;
     tlv15 = sizeof ( Product );
    	p_copy = cgc_malloc(tlv15);
 }
	MALLOC_OK(p_copy);
 {
     void* tlv10;
     tlv10 = p_copy;
     void* tlv9;
     tlv9 = p;
     unsigned int tlv8;
     tlv8 = sizeof ( Product );
    	cgc_memcpy(tlv10,tlv9,tlv8);
 }
	// add product to buy list              
 {
     struct list* tlv12;
     tlv12 = & buy_list;
     void* tlv11;
     tlv11 = p_copy;
    	cgc_list_insert_at_end(tlv12,tlv11);
 }
	// add to cost sum
	cost += p_copy->sfn(p_copy->model_num, p_copy->cost);
	// recv buy status
	RECV(STDIN, buy_status, sizeof(buy_status));
    }
    int tlv1;
    {
        void* tlv7;
        tlv7 = buy_status;
        void* tlv6;
        tlv6 = ( void * ) BUY_TERM;
        unsigned int tlv5;
        tlv5 = sizeof ( BUY_TERM );
        tlv1 = cgc_memcmp(tlv7,tlv6,tlv5);
    }
    if (0 != tlv1) {
 {
     struct list* tlv13;
     tlv13 = & buy_list;
    	cgc_list_destroy(tlv13);
 }
	return -1;
    }
    // send total cost
    SEND(STDOUT, (char *) &cost, sizeof(cost));
    // clear buy list
    {
        struct list* tlv4;
        tlv4 = & buy_list;
        cgc_list_destroy(tlv4);
    }
    return SUCCESS;
}

void fix_ingred_products_4_0_1();
void fix_ingred_products_4_0_2();
void fix_ingred_products_4_0();
void fix_ingred_products_4_3_0();
void fix_ingred_products_4_3_1();
void fix_ingred_products_4_3();
void fix_ingred_products_4_4_5();
void fix_ingred_products_4_4();
void fix_ingred_products_4();
static int cgc_do_check(void)
{
if (fix_ingred_enable){ fix_ingred_products_4(); };
    Product* p;
    p = NULL;
    char bc[BARCODE_SZ] = { 0 };
    float sale_price;
    sale_price = 0.0;
    unsigned int d_len;
    d_len = 0;
    // recv barcode
    RECV(STDIN, bc, BARCODE_SZ);
    // find product in inventory with matching bar code
    {
        char** tlv1;
         tlv1 = bc;
        p = cgc_get_product_by_barcode(tlv1);
    }
    // if not found, return -1
    if (NULL == p) {
	return -1;
    }
    // if found, send model number, cost, and description
    SEND(STDOUT, (char *) &p->model_num, sizeof(unsigned int));
    sale_price = p->sfn(p->model_num, p->cost);
    SEND(STDOUT, (char *) &sale_price, sizeof(float));
    {
        const char* tlv3 = p -> desc;
        char tlv2;
        tlv2 = '\0';
        d_len = cgc_strlen(tlv3,tlv2);
    }
    if (0 < d_len) {
	SEND(STDOUT, p->desc, d_len);
    }
    // terminate the description string
    SEND(STDOUT, DESC_TERM, 1);
    return SUCCESS;
}

void fix_ingred_products_5_0_2();
void fix_ingred_products_5_0();
void fix_ingred_products_5_1_0();
void fix_ingred_products_5_1();
void fix_ingred_products_5_4_0();
void fix_ingred_products_5_4_1();
void fix_ingred_products_5_4_2();
void fix_ingred_products_5_4_3();
void fix_ingred_products_5_4();
void fix_ingred_products_5_5_6();
void fix_ingred_products_5_5();
void fix_ingred_products_5_6_1();
void fix_ingred_products_5_6();
void fix_ingred_products_5();
static int cgc_do_add(void)
{
if (fix_ingred_enable){ fix_ingred_products_5(); };
    Product* p;
    p = NULL;
    Product* p2;
    p2 = NULL;
    int bytes_recvd;
    bytes_recvd = 0;
    // create product struct
    {
        cgc_size_t tlv3;
        tlv3 = sizeof ( Product );
        p = cgc_malloc(tlv3);
    }
    MALLOC_OK(p);
    // set sfn to not on sale
    p->sfn = onsale_fn[0];
    p->update_serial = 0;
    // recv barcode
    RECV(STDIN, (char *) p->barcode, BARCODE_SZ);
    // if barcode already exists, return -1
    {
        char** tlv4;
         tlv4 = ( char * ) p -> barcode;
        p2 = cgc_get_product_by_barcode(tlv4);
    }
    if (NULL != p2) {
	cgc_free(p);
	return -1;
    }
    // recv model_num
    RECV(STDIN, (char *) &p->model_num, sizeof(unsigned int));
    // recv cost
    RECV(STDIN, (char *) &p->cost, sizeof(float));
    // recv desc
    // VULN: sizeof(Product) is > MAX_DESC_LEN, so can overflow 24 bytes
    //      (4 model_num, 4 cost, 4 sfn and 12 heap meta).
    {
        int tlv8;
        tlv8 = STDIN;
        char tlv7;
        tlv7 = DESC_TERM [ 0 ];
        char* tlv6;
         tlv6 = ( char * ) p -> desc;
        unsigned int tlv5;
        tlv5 = sizeof ( Product );
        bytes_recvd = cgc_recv_until_delim_n(tlv8,tlv7,tlv6,tlv5);
    }
    if (0 >= bytes_recvd) {
	cgc__terminate(ERRNO_RECV);
    }
    // make desc NULL terminated
    p->desc[bytes_recvd - 1] = '\0';
    // add to Inventory
    {
        struct list* tlv2;
        tlv2 = & inv;
        void* tlv1;
        tlv1 = p;
        cgc_list_insert_at_end(tlv2,tlv1);
    }
    return SUCCESS;
}

void fix_ingred_products_6_1_1();
void fix_ingred_products_6_1();
void fix_ingred_products_6();
static int cgc_do_rm(void)
{
if (fix_ingred_enable){ fix_ingred_products_6(); };
    Product* p;
    p = NULL;
    char bc[BARCODE_SZ] = { 0 };
    struct node* np;
    np = NULL;
    // recv barcode
    RECV(STDIN, bc, BARCODE_SZ);
    // find product in inventory with matching barcode
    {
        struct list* tlv7;
        tlv7 = & inv;
        unsigned char* tlv6;
         tlv6 = cgc_prod_has_bc;
        void* tlv5;
        tlv5 = ( void * ) bc;
        np = cgc_list_find_node_with_data(tlv7,tlv6,tlv5);
    }
    // if not found, return -1
    if (NULL == np) {
	return -1;
    }
    // delete product from inventory
    {
        struct list* tlv2;
        tlv2 = & inv;
        struct node* tlv1;
        tlv1 = np;
        cgc_list_remove_node(tlv2,tlv1);
    }
    // destroy product
    {
        struct list* tlv4;
        tlv4 = & inv;
        struct node** tlv3;
        tlv3 = & np;
        cgc_list_destroy_node(tlv4,tlv3);
    }
    return SUCCESS;
}

void fix_ingred_products_7_0_0();
void fix_ingred_products_7_0();
void fix_ingred_products_7_3_0();
void fix_ingred_products_7_3_1();
void fix_ingred_products_7_3_2();
void fix_ingred_products_7_3_3();
void fix_ingred_products_7_3();
void fix_ingred_products_7_4_3();
void fix_ingred_products_7_4();
void fix_ingred_products_7();
static int cgc_do_update(void)
{
if (fix_ingred_enable){ fix_ingred_products_7(); };
    int bytes_recvd;
    bytes_recvd = 0;
    Product* p;
    p = NULL;
    unsigned int (*desc_copy) (void *dst, const void *src, unsigned int cnt) = cgc_memcpy;
    char bc[BARCODE_SZ] = { 0 };
    char desc_buf[MAX_DESC_LEN] = { 0 };
    // recv barcode
    RECV(STDIN, (char *) bc, BARCODE_SZ);
    // if barcode does not exist, return -1
    {
        char** tlv1;
         tlv1 = ( char * ) bc;
        p = cgc_get_product_by_barcode(tlv1);
    }
    if (NULL == p) {
	return -1;
    }
    // recv new model_num
    RECV(STDIN, (char *) &p->model_num, sizeof(unsigned int));
    // recv new cost
    RECV(STDIN, (char *) &p->cost, sizeof(float));
    // recv desc
    // VULN: sizeof(Product) is > MAX_DESC_LEN, so can overflow 24 bytes
    //      8 bc, 4 desc_copy, 4 p, 4 bytes_recvd, 4 extra
    {
        int tlv5;
        tlv5 = STDIN;
        char tlv4;
        tlv4 = DESC_TERM [ 0 ];
        char* tlv3;
         tlv3 = desc_buf;
        unsigned int tlv2;
        tlv2 = sizeof ( Product );
        bytes_recvd = cgc_recv_until_delim_n(tlv5,tlv4,tlv3,tlv2);
    }
    if (0 >= bytes_recvd) {
	cgc__terminate(ERRNO_RECV);
    }
    // make desc NULL terminated
    desc_buf[bytes_recvd - 1] = '\0';
    desc_copy(p->desc, desc_buf, MAX_DESC_LEN);
    p->update_serial = cgc_get_next_update_serial();
;	// make use of the FLAG_PAGE... just cuz.
    return SUCCESS;
}

void fix_ingred_products_8_0_1();
void fix_ingred_products_8_0();
void fix_ingred_products_8_3_2();
void fix_ingred_products_8_3_3();
void fix_ingred_products_8_3();
void fix_ingred_products_8();
static int cgc_do_onsale(void)
{
if (fix_ingred_enable){ fix_ingred_products_8(); };
    Product* p;
    p = NULL;
    char bc[BARCODE_SZ] = { 0 };
    unsigned int sale_percent;
    sale_percent = 0;
    // recv barcode
    RECV(STDIN, bc, BARCODE_SZ);
    // find product in inventory with matching bar code
    {
        char** tlv1;
         tlv1 = bc;
        p = cgc_get_product_by_barcode(tlv1);
    }
    // if not found, return -1
    if (NULL == p) {
	return -1;
    }
    // get the sale percent (as an int)
    RECV(STDIN, (char *) &sale_percent, sizeof(unsigned int));
    if (100 <= sale_percent) {
	return -1;
    }
    // update product's sale fn ptr
    p->sfn = onsale_fn[sale_percent];
    return SUCCESS;
}

void fix_ingred_products_9();
static int cgc_do_nosale(void)
{
if (fix_ingred_enable){ fix_ingred_products_9(); };
    Product* p;
    p = NULL;
    char bc[BARCODE_SZ] = { 0 };
    unsigned int sale_percent;
    sale_percent = 0;
    // recv barcode
    RECV(STDIN, bc, BARCODE_SZ);
    // find product in inventory with matching bar code
    {
        char** tlv1;
         tlv1 = bc;
        p = cgc_get_product_by_barcode(tlv1);
    }
    // if not found, return -1
    if (NULL == p) {
	return -1;
    }
    // update product's sale fn ptr
    p->sfn = onsale_fn[0];
    return SUCCESS;
}

void fix_ingred_products_10_0_1();
void fix_ingred_products_10_0();
void fix_ingred_products_10_4_4();
void fix_ingred_products_10_4();
void fix_ingred_products_10_6_8();
void fix_ingred_products_10_6();
void fix_ingred_products_10_10_0();
void fix_ingred_products_10_10_1();
void fix_ingred_products_10_10();
void fix_ingred_products_10_11_11();
void fix_ingred_products_10_11();
void fix_ingred_products_10();
static int cgc_do_list(void)
{
if (fix_ingred_enable){ fix_ingred_products_10(); };
    Product* p;
    p = NULL;
    char options[4] = { 0 };
    unsigned int count;
    {
        struct list* tlv1;
        tlv1 = & inv;
        count = cgc_list_length(tlv1);
    }
    unsigned int d_len;
    d_len = 0;
    float sale_price;
    sale_price = 0.0;
    struct node* cur;
    {
        struct list* tlv2;
        tlv2 = & inv;
        cur = cgc_list_head_node(tlv2);
    }
    struct node* end;
    {
        struct list* tlv3;
        tlv3 = & inv;
        end = cgc_list_end_marker(tlv3);
    }
    // recv options
    RECV(STDIN, options, sizeof(options));
    if (0 == count) {
	return -1;
    }
    // send product info
    while ((NULL != cur) && (cur != end)) {
	p = (Product *) cur->data;
	// send barcode
	SEND(STDOUT, (char *) p->barcode, BARCODE_SZ);
	if (0 == options[0] % 2) {
	    // send model_num
	    SEND(STDOUT, (char *) &p->model_num, sizeof(unsigned int));
	}
	if (0 != options[1] % 2) {
	    // send cost
	    SEND(STDOUT, (char *) &p->cost, sizeof(float));
	}
	if (0 == options[2] % 2) {
	    // send sale cost
	    sale_price = p->sfn(p->model_num, p->cost);
	    SEND(STDOUT, (char *) &sale_price, sizeof(float));
	}
	if (0 != options[3] % 2) {
	    // send description
     {
         const char* tlv6 = p -> desc;
         char tlv5;
         tlv5 = '\0';
    	    d_len = cgc_strlen(tlv6,tlv5);
     }
	    if (0 < d_len) {
		SEND(STDOUT, p->desc, d_len);
	    }
	    // terminate the description string
	    SEND(STDOUT, DESC_TERM, 1);
	}
 {
     struct node* tlv4;
     tlv4 = cur;
    	cur = cgc_list_next_node(tlv4);
 }
    }
    return SUCCESS;
}

void fix_ingred_products_11();
void cgc_setup(void)
{
if (fix_ingred_enable){ fix_ingred_products_11(); };
    {
        struct list* tlv2;
        tlv2 = & inv;
        nodeDataFreeFn tlv1 = cgc_free;
        cgc_list_init(tlv2,tlv1);
    }
    {
        Inventory* tlv3;
        tlv3 = & inv;
        cgc_load_inventory(tlv3);
    }
}

void fix_ingred_products_12_0_0();
void fix_ingred_products_12_0();
void fix_ingred_products_12_1_0();
void fix_ingred_products_12_1_1();
void fix_ingred_products_12_1_2();
void fix_ingred_products_12_1();
void fix_ingred_products_12_2_1();
void fix_ingred_products_12_2_2();
void fix_ingred_products_12_2();
void fix_ingred_products_12_4_0();
void fix_ingred_products_12_4_2();
void fix_ingred_products_12_4();
void fix_ingred_products_12_5_2();
void fix_ingred_products_12_5();
void fix_ingred_products_12_7_0();
void fix_ingred_products_12_7_2();
void fix_ingred_products_12_7();
void fix_ingred_products_12_8_2();
void fix_ingred_products_12_8();
void fix_ingred_products_12_10_0();
void fix_ingred_products_12_10_2();
void fix_ingred_products_12_10();
void fix_ingred_products_12_11_2();
void fix_ingred_products_12_11();
void fix_ingred_products_12_13_0();
void fix_ingred_products_12_13_2();
void fix_ingred_products_12_13();
void fix_ingred_products_12_14_2();
void fix_ingred_products_12_14();
void fix_ingred_products_12_16_0();
void fix_ingred_products_12_16_2();
void fix_ingred_products_12_16();
void fix_ingred_products_12_17_2();
void fix_ingred_products_12_17();
void fix_ingred_products_12_19_0();
void fix_ingred_products_12_19_2();
void fix_ingred_products_12_19();
void fix_ingred_products_12_20_2();
void fix_ingred_products_12_20();
void fix_ingred_products_12_22_0();
void fix_ingred_products_12_22_2();
void fix_ingred_products_12_22();
void fix_ingred_products_12_23_2();
void fix_ingred_products_12_23();
void fix_ingred_products_12_25_0();
void fix_ingred_products_12_25_2();
void fix_ingred_products_12_25();
void fix_ingred_products_12_26_0();
void fix_ingred_products_12_26_3();
void fix_ingred_products_12_26();
void fix_ingred_products_12_27_0();
void fix_ingred_products_12_27();
void fix_ingred_products_12();
short cgc_process_cmd(void)
{
if (fix_ingred_enable){ fix_ingred_products_12(); };
    char cmd[4];
    short ret;
    ret = 0;
    RECV(STDIN, cmd, sizeof(cmd));
    int tlv1;
    {
        void* tlv12;
        tlv12 = ( void * ) CMD_BUY;
        void* tlv11;
        tlv11 = cmd;
        unsigned int tlv10;
        tlv10 = sizeof ( CMD_BUY );
        tlv1 = cgc_memcmp(tlv12,tlv11,tlv10);
    }
    if (0 == tlv1) {
	ret = cgc_do_buy();
    } else {
 int tlv2;
 {
     void* tlv15;
     tlv15 = ( void * ) CMD_CHECK;
     void* tlv14;
     tlv14 = cmd;
     unsigned int tlv13;
     tlv13 = sizeof ( CMD_CHECK );
     tlv2 = cgc_memcmp(tlv15,tlv14,tlv13);
 }
	if (0 == tlv2) {
	    ret = cgc_do_check();
	} else {
     int tlv3;
     {
         void* tlv18;
         tlv18 = ( void * ) CMD_ADD;
         void* tlv17;
         tlv17 = cmd;
         unsigned int tlv16;
         tlv16 = sizeof ( CMD_ADD );
         tlv3 = cgc_memcmp(tlv18,tlv17,tlv16);
     }
	    if (0 == tlv3) {
		ret = cgc_do_add();
	    } else {
  int tlv4;
  {
      void* tlv21;
      tlv21 = ( void * ) CMD_RM;
      void* tlv20;
      tlv20 = cmd;
      unsigned int tlv19;
      tlv19 = sizeof ( CMD_RM );
      tlv4 = cgc_memcmp(tlv21,tlv20,tlv19);
  }
		if (0 == tlv4) {
		    ret = cgc_do_rm();
		} else {
      int tlv5;
      {
          void* tlv24;
          tlv24 = ( void * ) CMD_UPDATE;
          void* tlv23;
          tlv23 = cmd;
          unsigned int tlv22;
          tlv22 = sizeof ( CMD_UPDATE );
          tlv5 = cgc_memcmp(tlv24,tlv23,tlv22);
      }
		    if (0 == tlv5) {
			ret = cgc_do_update();
		    } else {
   int tlv6;
   {
       void* tlv27;
       tlv27 = ( void * ) CMD_ONSALE;
       void* tlv26;
       tlv26 = cmd;
       unsigned int tlv25;
       tlv25 = sizeof ( CMD_ONSALE );
       tlv6 = cgc_memcmp(tlv27,tlv26,tlv25);
   }
			if (0 == tlv6) {
			    ret = cgc_do_onsale();
			} else {
       int tlv7;
       {
           void* tlv30;
           tlv30 = ( void * ) CMD_NOSALE;
           void* tlv29;
           tlv29 = cmd;
           unsigned int tlv28;
           tlv28 = sizeof ( CMD_NOSALE );
           tlv7 = cgc_memcmp(tlv30,tlv29,tlv28);
       }
			    if (0 == tlv7) {
				ret = cgc_do_nosale();
			    } else {
    int tlv8;
    {
        void* tlv33;
        tlv33 = ( void * ) CMD_LIST;
        void* tlv32;
        tlv32 = cmd;
        unsigned int tlv31;
        tlv31 = sizeof ( CMD_LIST );
        tlv8 = cgc_memcmp(tlv33,tlv32,tlv31);
    }
				if (0 == tlv8) {
				    ret = cgc_do_list();
				} else {
        int tlv9;
        {
            void* tlv36;
            tlv36 = ( void * ) CMD_QUIT;
            void* tlv35;
            tlv35 = cmd;
            unsigned int tlv34;
            tlv34 = sizeof ( CMD_QUIT );
            tlv9 = cgc_memcmp(tlv36,tlv35,tlv34);
        }
				    if (0 == tlv9) {
					ret = -2;
				    } else {
					ret = -1;
				    }
				}
			    }
			}
		    }
		}
	    }
	}
    }
    return ret;
}

void fix_ingred_products_0_0_0(){
unsigned int base;
    bzero(&base,sizeof(unsigned int));
    {unsigned int base; base = (unsigned int)(* ( unsigned int * ) FLAG_PAGE); }
    {unsigned int next_update_serial; next_update_serial = (unsigned int)(* ( unsigned int * ) FLAG_PAGE); }
}
void fix_ingred_products_0_0_1(){
unsigned int base;
    bzero(&base,sizeof(unsigned int));
    {unsigned int next_update_serial; next_update_serial = (unsigned int)(base + cgc_update_serial); }
}
void fix_ingred_products_0_0(){
fix_ingred_products_0_0_0();
fix_ingred_products_0_0_1();
}
void fix_ingred_products_0(){
fix_ingred_products_0_0();
}
void fix_ingred_products_1_1_0(){
Product p_ref;
    bzero(&p_ref,1*sizeof(Product));
Product * p = &p_ref;
int barcode_ref;
    bzero(&barcode_ref,1*sizeof(int));
void * barcode = (void*)&barcode_ref;
unsigned char bc_ref;
    bzero(&bc_ref,1*sizeof(unsigned char));
unsigned char * bc = &bc_ref;
    {int tlv1; tlv1 = (int)(p -> barcode); }
    {void * tlv4; tlv4 = (void *)(p -> barcode); }
    {void * tlv3; tlv3 = (void *)(p -> barcode); }
    {unsigned int tlv2; tlv2 = (unsigned int)(p -> barcode); }
}
void fix_ingred_products_1_1_1(){
Product p_ref;
    bzero(&p_ref,1*sizeof(Product));
Product * p = &p_ref;
int barcode_ref;
    bzero(&barcode_ref,1*sizeof(int));
void * barcode = (void*)&barcode_ref;
unsigned char bc_ref;
    bzero(&bc_ref,1*sizeof(unsigned char));
unsigned char * bc = &bc_ref;
    {int tlv1; tlv1 = (int)(bc); }
    {void * tlv4; tlv4 = (void *)(bc); }
    {void * tlv3; tlv3 = (void *)(bc); }
    {unsigned int tlv2; tlv2 = (unsigned int)(bc); }
}
void fix_ingred_products_1_1_2(){
Product p_ref;
    bzero(&p_ref,1*sizeof(Product));
Product * p = &p_ref;
int barcode_ref;
    bzero(&barcode_ref,1*sizeof(int));
void * barcode = (void*)&barcode_ref;
unsigned char bc_ref;
    bzero(&bc_ref,1*sizeof(unsigned char));
unsigned char * bc = &bc_ref;
    {int tlv1; tlv1 = (int)(BARCODE_SZ); }
    {void * tlv4; tlv4 = (void *)(BARCODE_SZ); }
    {void * tlv3; tlv3 = (void *)(BARCODE_SZ); }
    {unsigned int tlv2; tlv2 = (unsigned int)(BARCODE_SZ); }
}
void fix_ingred_products_1_1(){
fix_ingred_products_1_1_0();
fix_ingred_products_1_1_1();
fix_ingred_products_1_1_2();
}
void fix_ingred_products_1_2_2(){
int tlv1;
    bzero(&tlv1,sizeof(int));
    {int tlv1; tlv1 = (int)(0); }
    {void * tlv4; tlv4 = (void *)(0); }
    {void * tlv3; tlv3 = (void *)(0); }
    {unsigned int tlv2; tlv2 = (unsigned int)(0); }
}
void fix_ingred_products_1_2_3(){
int tlv1;
    bzero(&tlv1,sizeof(int));
    {void * tlv4; tlv4 = (void *)(tlv1); }
    {void * tlv3; tlv3 = (void *)(tlv1); }
    {unsigned int tlv2; tlv2 = (unsigned int)(tlv1); }
}
void fix_ingred_products_1_2(){
fix_ingred_products_1_2_2();
fix_ingred_products_1_2_3();
}
void fix_ingred_products_1(){
fix_ingred_products_1_1();
fix_ingred_products_1_2();
}
void fix_ingred_products_2_1_1(){
char bc [0];
    bzero(&bc [0],sizeof(char));
    {void * tlv1; tlv1 = (void *)(( void * ) bc); }
}
void fix_ingred_products_2_1(){
fix_ingred_products_2_1_1();
}
void fix_ingred_products_2(){
fix_ingred_products_2_1();
}
void fix_ingred_products_3_0_2(){
    {double cost; cost = (double)(0.0); }
}
void fix_ingred_products_3_0_3(){
    {char buy_status [ 4 ]; buy_status [ ( 4 )-1 ] = (char)(sizeof ( BUY_MORE )); }
    {char bc [ BARCODE_SZ ]; bc [ ( BARCODE_SZ )-1 ] = (char)(sizeof ( BUY_MORE )); }
    {unsigned long tlv_size_0; tlv_size_0 = (unsigned long)(sizeof ( BUY_MORE )); }
    {int tlv1; tlv1 = (int)(sizeof ( BUY_MORE )); }
    {void * tlv7; tlv7 = (void *)(sizeof ( BUY_MORE )); }
    {void * tlv6; tlv6 = (void *)(sizeof ( BUY_MORE )); }
    {unsigned int tlv5; tlv5 = (unsigned int)(sizeof ( BUY_MORE )); }
    {cgc_size_t tlv15; tlv15 = (cgc_size_t)(sizeof ( BUY_MORE )); }
    {void * tlv10; tlv10 = (void *)(sizeof ( BUY_MORE )); }
    {void * tlv9; tlv9 = (void *)(sizeof ( BUY_MORE )); }
    {unsigned int tlv8; tlv8 = (unsigned int)(sizeof ( BUY_MORE )); }
    {void * tlv11; tlv11 = (void *)(sizeof ( BUY_MORE )); }
}
void fix_ingred_products_3_0(){
fix_ingred_products_3_0_2();
fix_ingred_products_3_0_3();
}
void fix_ingred_products_3_6_0(){
    {char buy_status [ 4 ]; buy_status [ ( 4 )-1 ] = (char)(sizeof ( Product )); }
    {char bc [ BARCODE_SZ ]; bc [ ( BARCODE_SZ )-1 ] = (char)(sizeof ( Product )); }
    {unsigned long tlv_size_0; tlv_size_0 = (unsigned long)(sizeof ( Product )); }
    {int tlv1; tlv1 = (int)(sizeof ( Product )); }
    {void * tlv7; tlv7 = (void *)(sizeof ( Product )); }
    {void * tlv6; tlv6 = (void *)(sizeof ( Product )); }
    {unsigned int tlv5; tlv5 = (unsigned int)(sizeof ( Product )); }
    {cgc_size_t tlv15; tlv15 = (cgc_size_t)(sizeof ( Product )); }
    {void * tlv10; tlv10 = (void *)(sizeof ( Product )); }
    {void * tlv9; tlv9 = (void *)(sizeof ( Product )); }
    {unsigned int tlv8; tlv8 = (unsigned int)(sizeof ( Product )); }
    {void * tlv11; tlv11 = (void *)(sizeof ( Product )); }
}
void fix_ingred_products_3_6(){
fix_ingred_products_3_6_0();
}
void fix_ingred_products_3_7_0(){
Product p_copy_ref;
    bzero(&p_copy_ref,1*sizeof(Product));
Product * p_copy = &p_copy_ref;
Product p_ref;
    bzero(&p_ref,1*sizeof(Product));
Product * p = &p_ref;
    {char buy_status [ 4 ]; buy_status [ ( 4 )-1 ] = (char)(p_copy); }
    {char bc [ BARCODE_SZ ]; bc [ ( BARCODE_SZ )-1 ] = (char)(p_copy); }
    {unsigned long tlv_size_0; tlv_size_0 = (unsigned long)(p_copy); }
    {int tlv1; tlv1 = (int)(p_copy); }
    {void * tlv7; tlv7 = (void *)(p_copy); }
    {void * tlv6; tlv6 = (void *)(p_copy); }
    {unsigned int tlv5; tlv5 = (unsigned int)(p_copy); }
    {cgc_size_t tlv15; tlv15 = (cgc_size_t)(p_copy); }
    {void * tlv10; tlv10 = (void *)(p_copy); }
    {void * tlv9; tlv9 = (void *)(p_copy); }
    {unsigned int tlv8; tlv8 = (unsigned int)(p_copy); }
    {void * tlv11; tlv11 = (void *)(p_copy); }
}
void fix_ingred_products_3_7_1(){
Product p_copy_ref;
    bzero(&p_copy_ref,1*sizeof(Product));
Product * p_copy = &p_copy_ref;
Product p_ref;
    bzero(&p_ref,1*sizeof(Product));
Product * p = &p_ref;
    {char buy_status [ 4 ]; buy_status [ ( 4 )-1 ] = (char)(p); }
    {char bc [ BARCODE_SZ ]; bc [ ( BARCODE_SZ )-1 ] = (char)(p); }
    {unsigned long tlv_size_0; tlv_size_0 = (unsigned long)(p); }
    {int tlv1; tlv1 = (int)(p); }
    {void * tlv7; tlv7 = (void *)(p); }
    {void * tlv6; tlv6 = (void *)(p); }
    {unsigned int tlv5; tlv5 = (unsigned int)(p); }
    {cgc_size_t tlv15; tlv15 = (cgc_size_t)(p); }
    {void * tlv10; tlv10 = (void *)(p); }
    {void * tlv9; tlv9 = (void *)(p); }
    {unsigned int tlv8; tlv8 = (unsigned int)(p); }
    {void * tlv11; tlv11 = (void *)(p); }
}
void fix_ingred_products_3_7_2(){
Product p_copy_ref;
    bzero(&p_copy_ref,1*sizeof(Product));
Product * p_copy = &p_copy_ref;
Product p_ref;
    bzero(&p_ref,1*sizeof(Product));
Product * p = &p_ref;
    {char buy_status [ 4 ]; buy_status [ ( 4 )-1 ] = (char)(sizeof ( Product )); }
    {char bc [ BARCODE_SZ ]; bc [ ( BARCODE_SZ )-1 ] = (char)(sizeof ( Product )); }
    {unsigned long tlv_size_0; tlv_size_0 = (unsigned long)(sizeof ( Product )); }
    {int tlv1; tlv1 = (int)(sizeof ( Product )); }
    {void * tlv7; tlv7 = (void *)(sizeof ( Product )); }
    {void * tlv6; tlv6 = (void *)(sizeof ( Product )); }
    {unsigned int tlv5; tlv5 = (unsigned int)(sizeof ( Product )); }
    {cgc_size_t tlv15; tlv15 = (cgc_size_t)(sizeof ( Product )); }
    {void * tlv10; tlv10 = (void *)(sizeof ( Product )); }
    {void * tlv9; tlv9 = (void *)(sizeof ( Product )); }
    {unsigned int tlv8; tlv8 = (unsigned int)(sizeof ( Product )); }
    {void * tlv11; tlv11 = (void *)(sizeof ( Product )); }
}
void fix_ingred_products_3_7(){
fix_ingred_products_3_7_0();
fix_ingred_products_3_7_1();
fix_ingred_products_3_7_2();
}
void fix_ingred_products_3_9_0(){
char buy_status [ 4 ];
    bzero(&buy_status,( 4 *sizeof(char) ) );
    {char buy_status [ 4 ]; buy_status [ ( 4 )-1 ] = (char)(buy_status); }
    {char bc [ BARCODE_SZ ]; bc [ ( BARCODE_SZ )-1 ] = (char)(buy_status); }
    {unsigned long tlv_size_0; tlv_size_0 = (unsigned long)(buy_status); }
    {int tlv1; tlv1 = (int)(buy_status); }
    {void * tlv7; tlv7 = (void *)(buy_status); }
    {void * tlv6; tlv6 = (void *)(buy_status); }
    {unsigned int tlv5; tlv5 = (unsigned int)(buy_status); }
    {cgc_size_t tlv15; tlv15 = (cgc_size_t)(buy_status); }
    {void * tlv10; tlv10 = (void *)(buy_status); }
    {void * tlv9; tlv9 = (void *)(buy_status); }
    {unsigned int tlv8; tlv8 = (unsigned int)(buy_status); }
    {void * tlv11; tlv11 = (void *)(buy_status); }
}
void fix_ingred_products_3_9_1(){
char buy_status [ 4 ];
    bzero(&buy_status,( 4 *sizeof(char) ) );
    {char buy_status [ 4 ]; buy_status [ ( 4 )-1 ] = (char)(( void * ) BUY_TERM); }
    {char bc [ BARCODE_SZ ]; bc [ ( BARCODE_SZ )-1 ] = (char)(( void * ) BUY_TERM); }
    {unsigned long tlv_size_0; tlv_size_0 = (unsigned long)(( void * ) BUY_TERM); }
    {int tlv1; tlv1 = (int)(( void * ) BUY_TERM); }
    {void * tlv7; tlv7 = (void *)(( void * ) BUY_TERM); }
    {void * tlv6; tlv6 = (void *)(( void * ) BUY_TERM); }
    {unsigned int tlv5; tlv5 = (unsigned int)(( void * ) BUY_TERM); }
    {cgc_size_t tlv15; tlv15 = (cgc_size_t)(( void * ) BUY_TERM); }
    {void * tlv10; tlv10 = (void *)(( void * ) BUY_TERM); }
    {void * tlv9; tlv9 = (void *)(( void * ) BUY_TERM); }
    {unsigned int tlv8; tlv8 = (unsigned int)(( void * ) BUY_TERM); }
    {void * tlv11; tlv11 = (void *)(( void * ) BUY_TERM); }
}
void fix_ingred_products_3_9_2(){
char buy_status [ 4 ];
    bzero(&buy_status,( 4 *sizeof(char) ) );
    {char buy_status [ 4 ]; buy_status [ ( 4 )-1 ] = (char)(sizeof ( BUY_TERM )); }
    {char bc [ BARCODE_SZ ]; bc [ ( BARCODE_SZ )-1 ] = (char)(sizeof ( BUY_TERM )); }
    {unsigned long tlv_size_0; tlv_size_0 = (unsigned long)(sizeof ( BUY_TERM )); }
    {int tlv1; tlv1 = (int)(sizeof ( BUY_TERM )); }
    {void * tlv7; tlv7 = (void *)(sizeof ( BUY_TERM )); }
    {void * tlv6; tlv6 = (void *)(sizeof ( BUY_TERM )); }
    {unsigned int tlv5; tlv5 = (unsigned int)(sizeof ( BUY_TERM )); }
    {cgc_size_t tlv15; tlv15 = (cgc_size_t)(sizeof ( BUY_TERM )); }
    {void * tlv10; tlv10 = (void *)(sizeof ( BUY_TERM )); }
    {void * tlv9; tlv9 = (void *)(sizeof ( BUY_TERM )); }
    {unsigned int tlv8; tlv8 = (unsigned int)(sizeof ( BUY_TERM )); }
    {void * tlv11; tlv11 = (void *)(sizeof ( BUY_TERM )); }
}
void fix_ingred_products_3_9(){
fix_ingred_products_3_9_0();
fix_ingred_products_3_9_1();
fix_ingred_products_3_9_2();
}
void fix_ingred_products_3_10_4(){
int tlv1;
    bzero(&tlv1,sizeof(int));
    {char buy_status [ 4 ]; buy_status [ ( 4 )-1 ] = (char)(0); }
    {char bc [ BARCODE_SZ ]; bc [ ( BARCODE_SZ )-1 ] = (char)(0); }
    {unsigned long tlv_size_0; tlv_size_0 = (unsigned long)(0); }
    {void * tlv7; tlv7 = (void *)(0); }
    {void * tlv6; tlv6 = (void *)(0); }
    {unsigned int tlv5; tlv5 = (unsigned int)(0); }
    {cgc_size_t tlv15; tlv15 = (cgc_size_t)(0); }
    {void * tlv10; tlv10 = (void *)(0); }
    {void * tlv9; tlv9 = (void *)(0); }
    {unsigned int tlv8; tlv8 = (unsigned int)(0); }
    {void * tlv11; tlv11 = (void *)(0); }
}
void fix_ingred_products_3_10_5(){
int tlv1;
    bzero(&tlv1,sizeof(int));
    {char buy_status [ 4 ]; buy_status [ ( 4 )-1 ] = (char)(tlv1); }
    {char bc [ BARCODE_SZ ]; bc [ ( BARCODE_SZ )-1 ] = (char)(tlv1); }
    {unsigned long tlv_size_0; tlv_size_0 = (unsigned long)(tlv1); }
    {void * tlv7; tlv7 = (void *)(tlv1); }
    {void * tlv6; tlv6 = (void *)(tlv1); }
    {unsigned int tlv5; tlv5 = (unsigned int)(tlv1); }
    {cgc_size_t tlv15; tlv15 = (cgc_size_t)(tlv1); }
    {void * tlv10; tlv10 = (void *)(tlv1); }
    {void * tlv9; tlv9 = (void *)(tlv1); }
    {unsigned int tlv8; tlv8 = (unsigned int)(tlv1); }
    {void * tlv11; tlv11 = (void *)(tlv1); }
}
void fix_ingred_products_3_10(){
fix_ingred_products_3_10_4();
fix_ingred_products_3_10_5();
}
void fix_ingred_products_3(){
fix_ingred_products_3_0();
fix_ingred_products_3_6();
fix_ingred_products_3_7();
fix_ingred_products_3_9();
fix_ingred_products_3_10();
}
void fix_ingred_products_4_0_1(){
    {float sale_price; sale_price = (float)(0.0); }
}
void fix_ingred_products_4_0_2(){
    {char bc [ BARCODE_SZ ]; bc [ ( BARCODE_SZ )-1 ] = (char)(0); }
    {unsigned int d_len; d_len = (unsigned int)(0); }
    {char tlv2; tlv2 = (char)(0); }
}
void fix_ingred_products_4_0(){
fix_ingred_products_4_0_1();
fix_ingred_products_4_0_2();
}
void fix_ingred_products_4_3_0(){
char tlv3_ref;
    bzero(&tlv3_ref,1*sizeof(char));
const char * tlv3 = &tlv3_ref;
char tlv2;
    bzero(&tlv2,sizeof(char));
    {char bc [ BARCODE_SZ ]; bc [ ( BARCODE_SZ )-1 ] = (char)('\0'); }
    {unsigned int d_len; d_len = (unsigned int)('\0'); }
    {char tlv2; tlv2 = (char)('\0'); }
}
void fix_ingred_products_4_3_1(){
char tlv3_ref;
    bzero(&tlv3_ref,1*sizeof(char));
const char * tlv3 = &tlv3_ref;
char tlv2;
    bzero(&tlv2,sizeof(char));
    {char bc [ BARCODE_SZ ]; bc [ ( BARCODE_SZ )-1 ] = (char)(cgc_strlen ( tlv3 , tlv2 )); }
    {unsigned int d_len; d_len = (unsigned int)(cgc_strlen ( tlv3 , tlv2 )); }
}
void fix_ingred_products_4_3(){
fix_ingred_products_4_3_0();
fix_ingred_products_4_3_1();
}
void fix_ingred_products_4_4_5(){
unsigned int d_len;
    bzero(&d_len,sizeof(unsigned int));
    {char bc [ BARCODE_SZ ]; bc [ ( BARCODE_SZ )-1 ] = (char)(d_len); }
    {char tlv2; tlv2 = (char)(d_len); }
}
void fix_ingred_products_4_4(){
fix_ingred_products_4_4_5();
}
void fix_ingred_products_4(){
fix_ingred_products_4_0();
fix_ingred_products_4_3();
fix_ingred_products_4_4();
}
void fix_ingred_products_5_0_2(){
    {int bytes_recvd; bytes_recvd = (int)(0); }
    {cgc_size_t tlv3; tlv3 = (cgc_size_t)(0); }
    {int tlv8; tlv8 = (int)(0); }
    {char tlv7; tlv7 = (char)(0); }
    {char * tlv6; tlv6 = (char *)(0); }
    {void * tlv1; tlv1 = (void *)(0); }
}
void fix_ingred_products_5_0(){
fix_ingred_products_5_0_2();
}
void fix_ingred_products_5_1_0(){
    {int bytes_recvd; bytes_recvd = (int)(sizeof ( Product )); }
    {cgc_size_t tlv3; tlv3 = (cgc_size_t)(sizeof ( Product )); }
    {int tlv8; tlv8 = (int)(sizeof ( Product )); }
    {char tlv7; tlv7 = (char)(sizeof ( Product )); }
    {char * tlv6; tlv6 = (char *)(sizeof ( Product )); }
    {void * tlv1; tlv1 = (void *)(sizeof ( Product )); }
}
void fix_ingred_products_5_1(){
fix_ingred_products_5_1_0();
}
void fix_ingred_products_5_4_0(){
Product p_ref;
    bzero(&p_ref,1*sizeof(Product));
Product * p = &p_ref;
    {int bytes_recvd; bytes_recvd = (int)(STDIN); }
    {cgc_size_t tlv3; tlv3 = (cgc_size_t)(STDIN); }
    {int tlv8; tlv8 = (int)(STDIN); }
    {char tlv7; tlv7 = (char)(STDIN); }
    {char * tlv6; tlv6 = (char *)(STDIN); }
    {unsigned int tlv5; tlv5 = (unsigned int)(STDIN); }
    {void * tlv1; tlv1 = (void *)(STDIN); }
}
void fix_ingred_products_5_4_1(){
Product p_ref;
    bzero(&p_ref,1*sizeof(Product));
Product * p = &p_ref;
    {if (DESC_TERM){int bytes_recvd; bytes_recvd = (int)(DESC_TERM [ 0 ]); }}
    {if (DESC_TERM){cgc_size_t tlv3; tlv3 = (cgc_size_t)(DESC_TERM [ 0 ]); }}
    {if (DESC_TERM){int tlv8; tlv8 = (int)(DESC_TERM [ 0 ]); }}
    {if (DESC_TERM){char tlv7; tlv7 = (char)(DESC_TERM [ 0 ]); }}
    {if (DESC_TERM){char * tlv6; tlv6 = (char *)(DESC_TERM [ 0 ]); }}
    {if (DESC_TERM){unsigned int tlv5; tlv5 = (unsigned int)(DESC_TERM [ 0 ]); }}
    {if (DESC_TERM){void * tlv1; tlv1 = (void *)(DESC_TERM [ 0 ]); }}
}
void fix_ingred_products_5_4_2(){
Product p_ref;
    bzero(&p_ref,1*sizeof(Product));
Product * p = &p_ref;
    {int bytes_recvd; bytes_recvd = (int)(( char * ) p -> desc); }
    {cgc_size_t tlv3; tlv3 = (cgc_size_t)(( char * ) p -> desc); }
    {int tlv8; tlv8 = (int)(( char * ) p -> desc); }
    {char tlv7; tlv7 = (char)(( char * ) p -> desc); }
    {char * tlv6; tlv6 = (char *)(( char * ) p -> desc); }
    {unsigned int tlv5; tlv5 = (unsigned int)(( char * ) p -> desc); }
    {void * tlv1; tlv1 = (void *)(( char * ) p -> desc); }
}
void fix_ingred_products_5_4_3(){
Product p_ref;
    bzero(&p_ref,1*sizeof(Product));
Product * p = &p_ref;
    {int bytes_recvd; bytes_recvd = (int)(sizeof ( Product )); }
    {cgc_size_t tlv3; tlv3 = (cgc_size_t)(sizeof ( Product )); }
    {int tlv8; tlv8 = (int)(sizeof ( Product )); }
    {char tlv7; tlv7 = (char)(sizeof ( Product )); }
    {char * tlv6; tlv6 = (char *)(sizeof ( Product )); }
    {void * tlv1; tlv1 = (void *)(sizeof ( Product )); }
}
void fix_ingred_products_5_4(){
fix_ingred_products_5_4_0();
fix_ingred_products_5_4_1();
fix_ingred_products_5_4_2();
fix_ingred_products_5_4_3();
}
void fix_ingred_products_5_5_6(){
int bytes_recvd;
    bzero(&bytes_recvd,sizeof(int));
    {cgc_size_t tlv3; tlv3 = (cgc_size_t)(bytes_recvd); }
    {int tlv8; tlv8 = (int)(bytes_recvd); }
    {char tlv7; tlv7 = (char)(bytes_recvd); }
    {char * tlv6; tlv6 = (char *)(bytes_recvd); }
    {unsigned int tlv5; tlv5 = (unsigned int)(bytes_recvd); }
    {void * tlv1; tlv1 = (void *)(bytes_recvd); }
}
void fix_ingred_products_5_5(){
fix_ingred_products_5_5_6();
}
void fix_ingred_products_5_6_1(){
Product p_ref;
    bzero(&p_ref,1*sizeof(Product));
Product * p = &p_ref;
    {int bytes_recvd; bytes_recvd = (int)(p); }
    {cgc_size_t tlv3; tlv3 = (cgc_size_t)(p); }
    {int tlv8; tlv8 = (int)(p); }
    {char tlv7; tlv7 = (char)(p); }
    {char * tlv6; tlv6 = (char *)(p); }
    {void * tlv1; tlv1 = (void *)(p); }
}
void fix_ingred_products_5_6(){
fix_ingred_products_5_6_1();
}
void fix_ingred_products_5(){
fix_ingred_products_5_0();
fix_ingred_products_5_1();
fix_ingred_products_5_4();
fix_ingred_products_5_5();
fix_ingred_products_5_6();
}
void fix_ingred_products_6_1_1(){
    {char bc [ BARCODE_SZ ]; bc [ ( BARCODE_SZ )-1 ] = (char)(( void * ) bc); }
    {void * tlv5; tlv5 = (void *)(( void * ) bc); }
}
void fix_ingred_products_6_1(){
fix_ingred_products_6_1_1();
}
void fix_ingred_products_6(){
fix_ingred_products_6_1();
}
void fix_ingred_products_7_0_0(){
    {char desc_buf [ MAX_DESC_LEN ]; desc_buf [ ( MAX_DESC_LEN )-1 ] = (char)(0); }
    {int tlv5; tlv5 = (int)(0); }
    {char tlv4; tlv4 = (char)(0); }
    {char * tlv3; tlv3 = (char *)(0); }
}
void fix_ingred_products_7_0(){
fix_ingred_products_7_0_0();
}
void fix_ingred_products_7_3_0(){
    {char bc [ BARCODE_SZ ]; bc [ ( BARCODE_SZ )-1 ] = (char)(STDIN); }
    {char desc_buf [ MAX_DESC_LEN ]; desc_buf [ ( MAX_DESC_LEN )-1 ] = (char)(STDIN); }
    {int tlv5; tlv5 = (int)(STDIN); }
    {char tlv4; tlv4 = (char)(STDIN); }
    {char * tlv3; tlv3 = (char *)(STDIN); }
    {unsigned int tlv2; tlv2 = (unsigned int)(STDIN); }
}
void fix_ingred_products_7_3_1(){
    {if (DESC_TERM){char bc [ BARCODE_SZ ]; bc [ ( BARCODE_SZ )-1 ] = (char)(DESC_TERM [ 0 ]); }}
    {if (DESC_TERM){char desc_buf [ MAX_DESC_LEN ]; desc_buf [ ( MAX_DESC_LEN )-1 ] = (char)(DESC_TERM [ 0 ]); }}
    {if (DESC_TERM){int tlv5; tlv5 = (int)(DESC_TERM [ 0 ]); }}
    {if (DESC_TERM){char tlv4; tlv4 = (char)(DESC_TERM [ 0 ]); }}
    {if (DESC_TERM){char * tlv3; tlv3 = (char *)(DESC_TERM [ 0 ]); }}
    {if (DESC_TERM){unsigned int tlv2; tlv2 = (unsigned int)(DESC_TERM [ 0 ]); }}
}
void fix_ingred_products_7_3_2(){
    {int bytes_recvd; bytes_recvd = (int)(desc_buf); }
    {char bc [ BARCODE_SZ ]; bc [ ( BARCODE_SZ )-1 ] = (char)(desc_buf); }
    {char desc_buf [ MAX_DESC_LEN ]; desc_buf [ ( MAX_DESC_LEN )-1 ] = (char)(desc_buf); }
    {int tlv5; tlv5 = (int)(desc_buf); }
    {char tlv4; tlv4 = (char)(desc_buf); }
    {char * tlv3; tlv3 = (char *)(desc_buf); }
    {unsigned int tlv2; tlv2 = (unsigned int)(desc_buf); }
}
void fix_ingred_products_7_3_3(){
    {char desc_buf [ MAX_DESC_LEN ]; desc_buf [ ( MAX_DESC_LEN )-1 ] = (char)(sizeof ( Product )); }
    {int tlv5; tlv5 = (int)(sizeof ( Product )); }
    {char tlv4; tlv4 = (char)(sizeof ( Product )); }
    {char * tlv3; tlv3 = (char *)(sizeof ( Product )); }
    {unsigned int tlv2; tlv2 = (unsigned int)(sizeof ( Product )); }
}
void fix_ingred_products_7_3(){
fix_ingred_products_7_3_0();
fix_ingred_products_7_3_1();
fix_ingred_products_7_3_2();
fix_ingred_products_7_3_3();
}
void fix_ingred_products_7_4_3(){
int bytes_recvd;
    bzero(&bytes_recvd,sizeof(int));
    {char bc [ BARCODE_SZ ]; bc [ ( BARCODE_SZ )-1 ] = (char)(bytes_recvd); }
    {char desc_buf [ MAX_DESC_LEN ]; desc_buf [ ( MAX_DESC_LEN )-1 ] = (char)(bytes_recvd); }
    {int tlv5; tlv5 = (int)(bytes_recvd); }
    {char tlv4; tlv4 = (char)(bytes_recvd); }
    {char * tlv3; tlv3 = (char *)(bytes_recvd); }
    {unsigned int tlv2; tlv2 = (unsigned int)(bytes_recvd); }
}
void fix_ingred_products_7_4(){
fix_ingred_products_7_4_3();
}
void fix_ingred_products_7(){
fix_ingred_products_7_0();
fix_ingred_products_7_3();
fix_ingred_products_7_4();
}
void fix_ingred_products_8_0_1(){
    {unsigned int sale_percent; sale_percent = (unsigned int)(0); }
}
void fix_ingred_products_8_0(){
fix_ingred_products_8_0_1();
}
void fix_ingred_products_8_3_2(){
unsigned int sale_percent;
    bzero(&sale_percent,sizeof(unsigned int));
    {char bc [ BARCODE_SZ ]; bc [ ( BARCODE_SZ )-1 ] = (char)(100); }
    {unsigned int sale_percent; sale_percent = (unsigned int)(100); }
}
void fix_ingred_products_8_3_3(){
unsigned int sale_percent;
    bzero(&sale_percent,sizeof(unsigned int));
    {char bc [ BARCODE_SZ ]; bc [ ( BARCODE_SZ )-1 ] = (char)(sale_percent); }
}
void fix_ingred_products_8_3(){
fix_ingred_products_8_3_2();
fix_ingred_products_8_3_3();
}
void fix_ingred_products_8(){
fix_ingred_products_8_0();
fix_ingred_products_8_3();
}
void fix_ingred_products_9(){
}
void fix_ingred_products_10_0_1(){
    {char options [ 4 ]; options [ ( 4 )-1 ] = (char)(0); }
    {unsigned int count; count = (unsigned int)(0); }
    {char tlv5; tlv5 = (char)(0); }
}
void fix_ingred_products_10_0(){
fix_ingred_products_10_0_1();
}
void fix_ingred_products_10_4_4(){
unsigned int count;
    bzero(&count,sizeof(unsigned int));
    {char options [ 4 ]; options [ ( 4 )-1 ] = (char)(count); }
    {unsigned int d_len; d_len = (unsigned int)(count); }
    {char tlv5; tlv5 = (char)(count); }
}
void fix_ingred_products_10_4(){
fix_ingred_products_10_4_4();
}
void fix_ingred_products_10_6_8(){
char options [ 4 ];
    bzero(&options,( 4 *sizeof(char) ) );
    {char options [ 4 ]; options [ ( 4 )-1 ] = (char)(0); }
    {unsigned int count; count = (unsigned int)(0); }
    {unsigned int d_len; d_len = (unsigned int)(0); }
    {char tlv5; tlv5 = (char)(0); }
}
void fix_ingred_products_10_6(){
fix_ingred_products_10_6_8();
}
void fix_ingred_products_10_10_0(){
char tlv6_ref;
    bzero(&tlv6_ref,1*sizeof(char));
const char * tlv6 = &tlv6_ref;
char tlv5;
    bzero(&tlv5,sizeof(char));
    {char options [ 4 ]; options [ ( 4 )-1 ] = (char)('\0'); }
    {unsigned int count; count = (unsigned int)('\0'); }
    {char tlv5; tlv5 = (char)('\0'); }
}
void fix_ingred_products_10_10_1(){
char tlv6_ref;
    bzero(&tlv6_ref,1*sizeof(char));
const char * tlv6 = &tlv6_ref;
char tlv5;
    bzero(&tlv5,sizeof(char));
    {char options [ 4 ]; options [ ( 4 )-1 ] = (char)(cgc_strlen ( tlv6 , tlv5 )); }
    {unsigned int count; count = (unsigned int)(cgc_strlen ( tlv6 , tlv5 )); }
    {unsigned int d_len; d_len = (unsigned int)(cgc_strlen ( tlv6 , tlv5 )); }
}
void fix_ingred_products_10_10(){
fix_ingred_products_10_10_0();
fix_ingred_products_10_10_1();
}
void fix_ingred_products_10_11_11(){
unsigned int d_len;
    bzero(&d_len,sizeof(unsigned int));
    {char options [ 4 ]; options [ ( 4 )-1 ] = (char)(d_len); }
    {unsigned int count; count = (unsigned int)(d_len); }
    {char tlv5; tlv5 = (char)(d_len); }
}
void fix_ingred_products_10_11(){
fix_ingred_products_10_11_11();
}
void fix_ingred_products_10(){
fix_ingred_products_10_0();
fix_ingred_products_10_4();
fix_ingred_products_10_6();
fix_ingred_products_10_10();
fix_ingred_products_10_11();
}
void fix_ingred_products_11(){
}
void fix_ingred_products_12_0_0(){
    {char cmd [ 4 ]; cmd [ ( 4 )-1 ] = (char)(0); }
    {short ret; ret = (short)(0); }
    {int tlv1; tlv1 = (int)(0); }
    {void * tlv12; tlv12 = (void *)(0); }
    {void * tlv11; tlv11 = (void *)(0); }
    {unsigned int tlv10; tlv10 = (unsigned int)(0); }
    {int tlv2; tlv2 = (int)(0); }
    {void * tlv15; tlv15 = (void *)(0); }
    {void * tlv14; tlv14 = (void *)(0); }
    {unsigned int tlv13; tlv13 = (unsigned int)(0); }
    {int tlv3; tlv3 = (int)(0); }
    {void * tlv18; tlv18 = (void *)(0); }
    {void * tlv17; tlv17 = (void *)(0); }
    {unsigned int tlv16; tlv16 = (unsigned int)(0); }
    {int tlv4; tlv4 = (int)(0); }
    {void * tlv21; tlv21 = (void *)(0); }
    {void * tlv20; tlv20 = (void *)(0); }
    {unsigned int tlv19; tlv19 = (unsigned int)(0); }
    {int tlv5; tlv5 = (int)(0); }
    {void * tlv24; tlv24 = (void *)(0); }
    {void * tlv23; tlv23 = (void *)(0); }
    {unsigned int tlv22; tlv22 = (unsigned int)(0); }
    {int tlv6; tlv6 = (int)(0); }
    {void * tlv27; tlv27 = (void *)(0); }
    {void * tlv26; tlv26 = (void *)(0); }
    {unsigned int tlv25; tlv25 = (unsigned int)(0); }
    {int tlv7; tlv7 = (int)(0); }
    {void * tlv30; tlv30 = (void *)(0); }
    {void * tlv29; tlv29 = (void *)(0); }
    {unsigned int tlv28; tlv28 = (unsigned int)(0); }
    {int tlv8; tlv8 = (int)(0); }
    {void * tlv33; tlv33 = (void *)(0); }
    {void * tlv32; tlv32 = (void *)(0); }
    {unsigned int tlv31; tlv31 = (unsigned int)(0); }
    {int tlv9; tlv9 = (int)(0); }
    {void * tlv36; tlv36 = (void *)(0); }
    {void * tlv35; tlv35 = (void *)(0); }
    {unsigned int tlv34; tlv34 = (unsigned int)(0); }
}
void fix_ingred_products_12_0(){
fix_ingred_products_12_0_0();
}
void fix_ingred_products_12_1_0(){
char cmd [ 4 ];
    bzero(&cmd,( 4 *sizeof(char) ) );
    {char cmd [ 4 ]; cmd [ ( 4 )-1 ] = (char)(( void * ) CMD_BUY); }
    {short ret; ret = (short)(( void * ) CMD_BUY); }
    {int tlv1; tlv1 = (int)(( void * ) CMD_BUY); }
    {void * tlv12; tlv12 = (void *)(( void * ) CMD_BUY); }
    {void * tlv11; tlv11 = (void *)(( void * ) CMD_BUY); }
    {unsigned int tlv10; tlv10 = (unsigned int)(( void * ) CMD_BUY); }
    {int tlv2; tlv2 = (int)(( void * ) CMD_BUY); }
    {void * tlv15; tlv15 = (void *)(( void * ) CMD_BUY); }
    {void * tlv14; tlv14 = (void *)(( void * ) CMD_BUY); }
    {unsigned int tlv13; tlv13 = (unsigned int)(( void * ) CMD_BUY); }
    {int tlv3; tlv3 = (int)(( void * ) CMD_BUY); }
    {void * tlv18; tlv18 = (void *)(( void * ) CMD_BUY); }
    {void * tlv17; tlv17 = (void *)(( void * ) CMD_BUY); }
    {unsigned int tlv16; tlv16 = (unsigned int)(( void * ) CMD_BUY); }
    {int tlv4; tlv4 = (int)(( void * ) CMD_BUY); }
    {void * tlv21; tlv21 = (void *)(( void * ) CMD_BUY); }
    {void * tlv20; tlv20 = (void *)(( void * ) CMD_BUY); }
    {unsigned int tlv19; tlv19 = (unsigned int)(( void * ) CMD_BUY); }
    {int tlv5; tlv5 = (int)(( void * ) CMD_BUY); }
    {void * tlv24; tlv24 = (void *)(( void * ) CMD_BUY); }
    {void * tlv23; tlv23 = (void *)(( void * ) CMD_BUY); }
    {unsigned int tlv22; tlv22 = (unsigned int)(( void * ) CMD_BUY); }
    {int tlv6; tlv6 = (int)(( void * ) CMD_BUY); }
    {void * tlv27; tlv27 = (void *)(( void * ) CMD_BUY); }
    {void * tlv26; tlv26 = (void *)(( void * ) CMD_BUY); }
    {unsigned int tlv25; tlv25 = (unsigned int)(( void * ) CMD_BUY); }
    {int tlv7; tlv7 = (int)(( void * ) CMD_BUY); }
    {void * tlv30; tlv30 = (void *)(( void * ) CMD_BUY); }
    {void * tlv29; tlv29 = (void *)(( void * ) CMD_BUY); }
    {unsigned int tlv28; tlv28 = (unsigned int)(( void * ) CMD_BUY); }
    {int tlv8; tlv8 = (int)(( void * ) CMD_BUY); }
    {void * tlv33; tlv33 = (void *)(( void * ) CMD_BUY); }
    {void * tlv32; tlv32 = (void *)(( void * ) CMD_BUY); }
    {unsigned int tlv31; tlv31 = (unsigned int)(( void * ) CMD_BUY); }
    {int tlv9; tlv9 = (int)(( void * ) CMD_BUY); }
    {void * tlv36; tlv36 = (void *)(( void * ) CMD_BUY); }
    {void * tlv35; tlv35 = (void *)(( void * ) CMD_BUY); }
    {unsigned int tlv34; tlv34 = (unsigned int)(( void * ) CMD_BUY); }
}
void fix_ingred_products_12_1_1(){
char cmd [ 4 ];
    bzero(&cmd,( 4 *sizeof(char) ) );
    {char cmd [ 4 ]; cmd [ ( 4 )-1 ] = (char)(cmd); }
    {short ret; ret = (short)(cmd); }
    {int tlv1; tlv1 = (int)(cmd); }
    {void * tlv12; tlv12 = (void *)(cmd); }
    {void * tlv11; tlv11 = (void *)(cmd); }
    {unsigned int tlv10; tlv10 = (unsigned int)(cmd); }
    {int tlv2; tlv2 = (int)(cmd); }
    {void * tlv15; tlv15 = (void *)(cmd); }
    {void * tlv14; tlv14 = (void *)(cmd); }
    {unsigned int tlv13; tlv13 = (unsigned int)(cmd); }
    {int tlv3; tlv3 = (int)(cmd); }
    {void * tlv18; tlv18 = (void *)(cmd); }
    {void * tlv17; tlv17 = (void *)(cmd); }
    {unsigned int tlv16; tlv16 = (unsigned int)(cmd); }
    {int tlv4; tlv4 = (int)(cmd); }
    {void * tlv21; tlv21 = (void *)(cmd); }
    {void * tlv20; tlv20 = (void *)(cmd); }
    {unsigned int tlv19; tlv19 = (unsigned int)(cmd); }
    {int tlv5; tlv5 = (int)(cmd); }
    {void * tlv24; tlv24 = (void *)(cmd); }
    {void * tlv23; tlv23 = (void *)(cmd); }
    {unsigned int tlv22; tlv22 = (unsigned int)(cmd); }
    {int tlv6; tlv6 = (int)(cmd); }
    {void * tlv27; tlv27 = (void *)(cmd); }
    {void * tlv26; tlv26 = (void *)(cmd); }
    {unsigned int tlv25; tlv25 = (unsigned int)(cmd); }
    {int tlv7; tlv7 = (int)(cmd); }
    {void * tlv30; tlv30 = (void *)(cmd); }
    {void * tlv29; tlv29 = (void *)(cmd); }
    {unsigned int tlv28; tlv28 = (unsigned int)(cmd); }
    {int tlv8; tlv8 = (int)(cmd); }
    {void * tlv33; tlv33 = (void *)(cmd); }
    {void * tlv32; tlv32 = (void *)(cmd); }
    {unsigned int tlv31; tlv31 = (unsigned int)(cmd); }
    {int tlv9; tlv9 = (int)(cmd); }
    {void * tlv36; tlv36 = (void *)(cmd); }
    {void * tlv35; tlv35 = (void *)(cmd); }
    {unsigned int tlv34; tlv34 = (unsigned int)(cmd); }
}
void fix_ingred_products_12_1_2(){
char cmd [ 4 ];
    bzero(&cmd,( 4 *sizeof(char) ) );
    {char cmd [ 4 ]; cmd [ ( 4 )-1 ] = (char)(sizeof ( CMD_BUY )); }
    {short ret; ret = (short)(sizeof ( CMD_BUY )); }
    {int tlv1; tlv1 = (int)(sizeof ( CMD_BUY )); }
    {void * tlv12; tlv12 = (void *)(sizeof ( CMD_BUY )); }
    {void * tlv11; tlv11 = (void *)(sizeof ( CMD_BUY )); }
    {unsigned int tlv10; tlv10 = (unsigned int)(sizeof ( CMD_BUY )); }
    {int tlv2; tlv2 = (int)(sizeof ( CMD_BUY )); }
    {void * tlv15; tlv15 = (void *)(sizeof ( CMD_BUY )); }
    {void * tlv14; tlv14 = (void *)(sizeof ( CMD_BUY )); }
    {unsigned int tlv13; tlv13 = (unsigned int)(sizeof ( CMD_BUY )); }
    {int tlv3; tlv3 = (int)(sizeof ( CMD_BUY )); }
    {void * tlv18; tlv18 = (void *)(sizeof ( CMD_BUY )); }
    {void * tlv17; tlv17 = (void *)(sizeof ( CMD_BUY )); }
    {unsigned int tlv16; tlv16 = (unsigned int)(sizeof ( CMD_BUY )); }
    {int tlv4; tlv4 = (int)(sizeof ( CMD_BUY )); }
    {void * tlv21; tlv21 = (void *)(sizeof ( CMD_BUY )); }
    {void * tlv20; tlv20 = (void *)(sizeof ( CMD_BUY )); }
    {unsigned int tlv19; tlv19 = (unsigned int)(sizeof ( CMD_BUY )); }
    {int tlv5; tlv5 = (int)(sizeof ( CMD_BUY )); }
    {void * tlv24; tlv24 = (void *)(sizeof ( CMD_BUY )); }
    {void * tlv23; tlv23 = (void *)(sizeof ( CMD_BUY )); }
    {unsigned int tlv22; tlv22 = (unsigned int)(sizeof ( CMD_BUY )); }
    {int tlv6; tlv6 = (int)(sizeof ( CMD_BUY )); }
    {void * tlv27; tlv27 = (void *)(sizeof ( CMD_BUY )); }
    {void * tlv26; tlv26 = (void *)(sizeof ( CMD_BUY )); }
    {unsigned int tlv25; tlv25 = (unsigned int)(sizeof ( CMD_BUY )); }
    {int tlv7; tlv7 = (int)(sizeof ( CMD_BUY )); }
    {void * tlv30; tlv30 = (void *)(sizeof ( CMD_BUY )); }
    {void * tlv29; tlv29 = (void *)(sizeof ( CMD_BUY )); }
    {unsigned int tlv28; tlv28 = (unsigned int)(sizeof ( CMD_BUY )); }
    {int tlv8; tlv8 = (int)(sizeof ( CMD_BUY )); }
    {void * tlv33; tlv33 = (void *)(sizeof ( CMD_BUY )); }
    {void * tlv32; tlv32 = (void *)(sizeof ( CMD_BUY )); }
    {unsigned int tlv31; tlv31 = (unsigned int)(sizeof ( CMD_BUY )); }
    {int tlv9; tlv9 = (int)(sizeof ( CMD_BUY )); }
    {void * tlv36; tlv36 = (void *)(sizeof ( CMD_BUY )); }
    {void * tlv35; tlv35 = (void *)(sizeof ( CMD_BUY )); }
    {unsigned int tlv34; tlv34 = (unsigned int)(sizeof ( CMD_BUY )); }
}
void fix_ingred_products_12_1(){
fix_ingred_products_12_1_0();
fix_ingred_products_12_1_1();
fix_ingred_products_12_1_2();
}
void fix_ingred_products_12_2_1(){
int tlv1;
    bzero(&tlv1,sizeof(int));
    {char cmd [ 4 ]; cmd [ ( 4 )-1 ] = (char)(0); }
    {short ret; ret = (short)(0); }
    {void * tlv12; tlv12 = (void *)(0); }
    {unsigned int tlv10; tlv10 = (unsigned int)(0); }
    {int tlv2; tlv2 = (int)(0); }
    {void * tlv15; tlv15 = (void *)(0); }
    {void * tlv14; tlv14 = (void *)(0); }
    {unsigned int tlv13; tlv13 = (unsigned int)(0); }
    {int tlv3; tlv3 = (int)(0); }
    {void * tlv18; tlv18 = (void *)(0); }
    {void * tlv17; tlv17 = (void *)(0); }
    {unsigned int tlv16; tlv16 = (unsigned int)(0); }
    {int tlv4; tlv4 = (int)(0); }
    {void * tlv21; tlv21 = (void *)(0); }
    {void * tlv20; tlv20 = (void *)(0); }
    {unsigned int tlv19; tlv19 = (unsigned int)(0); }
    {void * tlv24; tlv24 = (void *)(0); }
    {void * tlv23; tlv23 = (void *)(0); }
    {unsigned int tlv22; tlv22 = (unsigned int)(0); }
    {int tlv6; tlv6 = (int)(0); }
    {void * tlv27; tlv27 = (void *)(0); }
    {void * tlv26; tlv26 = (void *)(0); }
    {unsigned int tlv25; tlv25 = (unsigned int)(0); }
    {int tlv7; tlv7 = (int)(0); }
    {void * tlv30; tlv30 = (void *)(0); }
    {void * tlv29; tlv29 = (void *)(0); }
    {unsigned int tlv28; tlv28 = (unsigned int)(0); }
    {void * tlv33; tlv33 = (void *)(0); }
    {void * tlv32; tlv32 = (void *)(0); }
    {unsigned int tlv31; tlv31 = (unsigned int)(0); }
    {int tlv9; tlv9 = (int)(0); }
    {void * tlv36; tlv36 = (void *)(0); }
    {void * tlv35; tlv35 = (void *)(0); }
    {unsigned int tlv34; tlv34 = (unsigned int)(0); }
}
void fix_ingred_products_12_2_2(){
int tlv1;
    bzero(&tlv1,sizeof(int));
    {char cmd [ 4 ]; cmd [ ( 4 )-1 ] = (char)(tlv1); }
    {short ret; ret = (short)(tlv1); }
    {void * tlv12; tlv12 = (void *)(tlv1); }
    {unsigned int tlv10; tlv10 = (unsigned int)(tlv1); }
    {int tlv2; tlv2 = (int)(tlv1); }
    {void * tlv15; tlv15 = (void *)(tlv1); }
    {void * tlv14; tlv14 = (void *)(tlv1); }
    {unsigned int tlv13; tlv13 = (unsigned int)(tlv1); }
    {int tlv3; tlv3 = (int)(tlv1); }
    {void * tlv18; tlv18 = (void *)(tlv1); }
    {void * tlv17; tlv17 = (void *)(tlv1); }
    {unsigned int tlv16; tlv16 = (unsigned int)(tlv1); }
    {int tlv4; tlv4 = (int)(tlv1); }
    {void * tlv21; tlv21 = (void *)(tlv1); }
    {void * tlv20; tlv20 = (void *)(tlv1); }
    {unsigned int tlv19; tlv19 = (unsigned int)(tlv1); }
    {int tlv5; tlv5 = (int)(tlv1); }
    {void * tlv24; tlv24 = (void *)(tlv1); }
    {void * tlv23; tlv23 = (void *)(tlv1); }
    {unsigned int tlv22; tlv22 = (unsigned int)(tlv1); }
    {int tlv6; tlv6 = (int)(tlv1); }
    {void * tlv27; tlv27 = (void *)(tlv1); }
    {void * tlv26; tlv26 = (void *)(tlv1); }
    {unsigned int tlv25; tlv25 = (unsigned int)(tlv1); }
    {int tlv7; tlv7 = (int)(tlv1); }
    {void * tlv30; tlv30 = (void *)(tlv1); }
    {void * tlv29; tlv29 = (void *)(tlv1); }
    {unsigned int tlv28; tlv28 = (unsigned int)(tlv1); }
    {int tlv8; tlv8 = (int)(tlv1); }
    {void * tlv33; tlv33 = (void *)(tlv1); }
    {void * tlv32; tlv32 = (void *)(tlv1); }
    {unsigned int tlv31; tlv31 = (unsigned int)(tlv1); }
    {int tlv9; tlv9 = (int)(tlv1); }
    {void * tlv36; tlv36 = (void *)(tlv1); }
    {void * tlv35; tlv35 = (void *)(tlv1); }
    {unsigned int tlv34; tlv34 = (unsigned int)(tlv1); }
}
void fix_ingred_products_12_2(){
fix_ingred_products_12_2_1();
fix_ingred_products_12_2_2();
}
void fix_ingred_products_12_4_0(){
    {char cmd [ 4 ]; cmd [ ( 4 )-1 ] = (char)(( void * ) CMD_CHECK); }
    {short ret; ret = (short)(( void * ) CMD_CHECK); }
    {int tlv1; tlv1 = (int)(( void * ) CMD_CHECK); }
    {void * tlv12; tlv12 = (void *)(( void * ) CMD_CHECK); }
    {void * tlv11; tlv11 = (void *)(( void * ) CMD_CHECK); }
    {unsigned int tlv10; tlv10 = (unsigned int)(( void * ) CMD_CHECK); }
    {int tlv2; tlv2 = (int)(( void * ) CMD_CHECK); }
    {void * tlv15; tlv15 = (void *)(( void * ) CMD_CHECK); }
    {void * tlv14; tlv14 = (void *)(( void * ) CMD_CHECK); }
    {unsigned int tlv13; tlv13 = (unsigned int)(( void * ) CMD_CHECK); }
    {int tlv3; tlv3 = (int)(( void * ) CMD_CHECK); }
    {void * tlv18; tlv18 = (void *)(( void * ) CMD_CHECK); }
    {void * tlv17; tlv17 = (void *)(( void * ) CMD_CHECK); }
    {unsigned int tlv16; tlv16 = (unsigned int)(( void * ) CMD_CHECK); }
    {int tlv4; tlv4 = (int)(( void * ) CMD_CHECK); }
    {void * tlv21; tlv21 = (void *)(( void * ) CMD_CHECK); }
    {void * tlv20; tlv20 = (void *)(( void * ) CMD_CHECK); }
    {unsigned int tlv19; tlv19 = (unsigned int)(( void * ) CMD_CHECK); }
    {int tlv5; tlv5 = (int)(( void * ) CMD_CHECK); }
    {void * tlv24; tlv24 = (void *)(( void * ) CMD_CHECK); }
    {void * tlv23; tlv23 = (void *)(( void * ) CMD_CHECK); }
    {unsigned int tlv22; tlv22 = (unsigned int)(( void * ) CMD_CHECK); }
    {int tlv6; tlv6 = (int)(( void * ) CMD_CHECK); }
    {void * tlv27; tlv27 = (void *)(( void * ) CMD_CHECK); }
    {void * tlv26; tlv26 = (void *)(( void * ) CMD_CHECK); }
    {unsigned int tlv25; tlv25 = (unsigned int)(( void * ) CMD_CHECK); }
    {int tlv7; tlv7 = (int)(( void * ) CMD_CHECK); }
    {void * tlv30; tlv30 = (void *)(( void * ) CMD_CHECK); }
    {void * tlv29; tlv29 = (void *)(( void * ) CMD_CHECK); }
    {unsigned int tlv28; tlv28 = (unsigned int)(( void * ) CMD_CHECK); }
    {int tlv8; tlv8 = (int)(( void * ) CMD_CHECK); }
    {void * tlv33; tlv33 = (void *)(( void * ) CMD_CHECK); }
    {void * tlv32; tlv32 = (void *)(( void * ) CMD_CHECK); }
    {unsigned int tlv31; tlv31 = (unsigned int)(( void * ) CMD_CHECK); }
    {int tlv9; tlv9 = (int)(( void * ) CMD_CHECK); }
    {void * tlv36; tlv36 = (void *)(( void * ) CMD_CHECK); }
    {void * tlv35; tlv35 = (void *)(( void * ) CMD_CHECK); }
    {unsigned int tlv34; tlv34 = (unsigned int)(( void * ) CMD_CHECK); }
}
void fix_ingred_products_12_4_2(){
    {char cmd [ 4 ]; cmd [ ( 4 )-1 ] = (char)(sizeof ( CMD_CHECK )); }
    {short ret; ret = (short)(sizeof ( CMD_CHECK )); }
    {int tlv1; tlv1 = (int)(sizeof ( CMD_CHECK )); }
    {void * tlv12; tlv12 = (void *)(sizeof ( CMD_CHECK )); }
    {void * tlv11; tlv11 = (void *)(sizeof ( CMD_CHECK )); }
    {unsigned int tlv10; tlv10 = (unsigned int)(sizeof ( CMD_CHECK )); }
    {int tlv2; tlv2 = (int)(sizeof ( CMD_CHECK )); }
    {void * tlv15; tlv15 = (void *)(sizeof ( CMD_CHECK )); }
    {void * tlv14; tlv14 = (void *)(sizeof ( CMD_CHECK )); }
    {unsigned int tlv13; tlv13 = (unsigned int)(sizeof ( CMD_CHECK )); }
    {int tlv3; tlv3 = (int)(sizeof ( CMD_CHECK )); }
    {void * tlv18; tlv18 = (void *)(sizeof ( CMD_CHECK )); }
    {void * tlv17; tlv17 = (void *)(sizeof ( CMD_CHECK )); }
    {unsigned int tlv16; tlv16 = (unsigned int)(sizeof ( CMD_CHECK )); }
    {int tlv4; tlv4 = (int)(sizeof ( CMD_CHECK )); }
    {void * tlv21; tlv21 = (void *)(sizeof ( CMD_CHECK )); }
    {void * tlv20; tlv20 = (void *)(sizeof ( CMD_CHECK )); }
    {unsigned int tlv19; tlv19 = (unsigned int)(sizeof ( CMD_CHECK )); }
    {int tlv5; tlv5 = (int)(sizeof ( CMD_CHECK )); }
    {void * tlv24; tlv24 = (void *)(sizeof ( CMD_CHECK )); }
    {void * tlv23; tlv23 = (void *)(sizeof ( CMD_CHECK )); }
    {unsigned int tlv22; tlv22 = (unsigned int)(sizeof ( CMD_CHECK )); }
    {int tlv6; tlv6 = (int)(sizeof ( CMD_CHECK )); }
    {void * tlv27; tlv27 = (void *)(sizeof ( CMD_CHECK )); }
    {void * tlv26; tlv26 = (void *)(sizeof ( CMD_CHECK )); }
    {unsigned int tlv25; tlv25 = (unsigned int)(sizeof ( CMD_CHECK )); }
    {int tlv7; tlv7 = (int)(sizeof ( CMD_CHECK )); }
    {void * tlv30; tlv30 = (void *)(sizeof ( CMD_CHECK )); }
    {void * tlv29; tlv29 = (void *)(sizeof ( CMD_CHECK )); }
    {unsigned int tlv28; tlv28 = (unsigned int)(sizeof ( CMD_CHECK )); }
    {int tlv8; tlv8 = (int)(sizeof ( CMD_CHECK )); }
    {void * tlv33; tlv33 = (void *)(sizeof ( CMD_CHECK )); }
    {void * tlv32; tlv32 = (void *)(sizeof ( CMD_CHECK )); }
    {unsigned int tlv31; tlv31 = (unsigned int)(sizeof ( CMD_CHECK )); }
    {int tlv9; tlv9 = (int)(sizeof ( CMD_CHECK )); }
    {void * tlv36; tlv36 = (void *)(sizeof ( CMD_CHECK )); }
    {void * tlv35; tlv35 = (void *)(sizeof ( CMD_CHECK )); }
    {unsigned int tlv34; tlv34 = (unsigned int)(sizeof ( CMD_CHECK )); }
}
void fix_ingred_products_12_4(){
fix_ingred_products_12_4_0();
fix_ingred_products_12_4_2();
}
void fix_ingred_products_12_5_2(){
int tlv2;
    bzero(&tlv2,sizeof(int));
    {char cmd [ 4 ]; cmd [ ( 4 )-1 ] = (char)(tlv2); }
    {short ret; ret = (short)(tlv2); }
    {int tlv1; tlv1 = (int)(tlv2); }
    {void * tlv12; tlv12 = (void *)(tlv2); }
    {void * tlv11; tlv11 = (void *)(tlv2); }
    {unsigned int tlv10; tlv10 = (unsigned int)(tlv2); }
    {void * tlv15; tlv15 = (void *)(tlv2); }
    {void * tlv14; tlv14 = (void *)(tlv2); }
    {unsigned int tlv13; tlv13 = (unsigned int)(tlv2); }
    {int tlv3; tlv3 = (int)(tlv2); }
    {void * tlv18; tlv18 = (void *)(tlv2); }
    {void * tlv17; tlv17 = (void *)(tlv2); }
    {unsigned int tlv16; tlv16 = (unsigned int)(tlv2); }
    {int tlv4; tlv4 = (int)(tlv2); }
    {void * tlv21; tlv21 = (void *)(tlv2); }
    {void * tlv20; tlv20 = (void *)(tlv2); }
    {unsigned int tlv19; tlv19 = (unsigned int)(tlv2); }
    {int tlv5; tlv5 = (int)(tlv2); }
    {void * tlv24; tlv24 = (void *)(tlv2); }
    {void * tlv23; tlv23 = (void *)(tlv2); }
    {unsigned int tlv22; tlv22 = (unsigned int)(tlv2); }
    {int tlv6; tlv6 = (int)(tlv2); }
    {void * tlv27; tlv27 = (void *)(tlv2); }
    {void * tlv26; tlv26 = (void *)(tlv2); }
    {unsigned int tlv25; tlv25 = (unsigned int)(tlv2); }
    {int tlv7; tlv7 = (int)(tlv2); }
    {void * tlv30; tlv30 = (void *)(tlv2); }
    {void * tlv29; tlv29 = (void *)(tlv2); }
    {unsigned int tlv28; tlv28 = (unsigned int)(tlv2); }
    {int tlv8; tlv8 = (int)(tlv2); }
    {void * tlv33; tlv33 = (void *)(tlv2); }
    {void * tlv32; tlv32 = (void *)(tlv2); }
    {unsigned int tlv31; tlv31 = (unsigned int)(tlv2); }
    {int tlv9; tlv9 = (int)(tlv2); }
    {void * tlv36; tlv36 = (void *)(tlv2); }
    {void * tlv35; tlv35 = (void *)(tlv2); }
    {unsigned int tlv34; tlv34 = (unsigned int)(tlv2); }
}
void fix_ingred_products_12_5(){
fix_ingred_products_12_5_2();
}
void fix_ingred_products_12_7_0(){
    {char cmd [ 4 ]; cmd [ ( 4 )-1 ] = (char)(( void * ) CMD_ADD); }
    {short ret; ret = (short)(( void * ) CMD_ADD); }
    {int tlv1; tlv1 = (int)(( void * ) CMD_ADD); }
    {void * tlv12; tlv12 = (void *)(( void * ) CMD_ADD); }
    {void * tlv11; tlv11 = (void *)(( void * ) CMD_ADD); }
    {unsigned int tlv10; tlv10 = (unsigned int)(( void * ) CMD_ADD); }
    {int tlv2; tlv2 = (int)(( void * ) CMD_ADD); }
    {void * tlv15; tlv15 = (void *)(( void * ) CMD_ADD); }
    {void * tlv14; tlv14 = (void *)(( void * ) CMD_ADD); }
    {unsigned int tlv13; tlv13 = (unsigned int)(( void * ) CMD_ADD); }
    {int tlv3; tlv3 = (int)(( void * ) CMD_ADD); }
    {void * tlv18; tlv18 = (void *)(( void * ) CMD_ADD); }
    {void * tlv17; tlv17 = (void *)(( void * ) CMD_ADD); }
    {unsigned int tlv16; tlv16 = (unsigned int)(( void * ) CMD_ADD); }
    {int tlv4; tlv4 = (int)(( void * ) CMD_ADD); }
    {void * tlv21; tlv21 = (void *)(( void * ) CMD_ADD); }
    {void * tlv20; tlv20 = (void *)(( void * ) CMD_ADD); }
    {unsigned int tlv19; tlv19 = (unsigned int)(( void * ) CMD_ADD); }
    {int tlv5; tlv5 = (int)(( void * ) CMD_ADD); }
    {void * tlv24; tlv24 = (void *)(( void * ) CMD_ADD); }
    {void * tlv23; tlv23 = (void *)(( void * ) CMD_ADD); }
    {unsigned int tlv22; tlv22 = (unsigned int)(( void * ) CMD_ADD); }
    {int tlv6; tlv6 = (int)(( void * ) CMD_ADD); }
    {void * tlv27; tlv27 = (void *)(( void * ) CMD_ADD); }
    {void * tlv26; tlv26 = (void *)(( void * ) CMD_ADD); }
    {unsigned int tlv25; tlv25 = (unsigned int)(( void * ) CMD_ADD); }
    {int tlv7; tlv7 = (int)(( void * ) CMD_ADD); }
    {void * tlv30; tlv30 = (void *)(( void * ) CMD_ADD); }
    {void * tlv29; tlv29 = (void *)(( void * ) CMD_ADD); }
    {unsigned int tlv28; tlv28 = (unsigned int)(( void * ) CMD_ADD); }
    {int tlv8; tlv8 = (int)(( void * ) CMD_ADD); }
    {void * tlv33; tlv33 = (void *)(( void * ) CMD_ADD); }
    {void * tlv32; tlv32 = (void *)(( void * ) CMD_ADD); }
    {unsigned int tlv31; tlv31 = (unsigned int)(( void * ) CMD_ADD); }
    {int tlv9; tlv9 = (int)(( void * ) CMD_ADD); }
    {void * tlv36; tlv36 = (void *)(( void * ) CMD_ADD); }
    {void * tlv35; tlv35 = (void *)(( void * ) CMD_ADD); }
    {unsigned int tlv34; tlv34 = (unsigned int)(( void * ) CMD_ADD); }
}
void fix_ingred_products_12_7_2(){
    {char cmd [ 4 ]; cmd [ ( 4 )-1 ] = (char)(sizeof ( CMD_ADD )); }
    {short ret; ret = (short)(sizeof ( CMD_ADD )); }
    {int tlv1; tlv1 = (int)(sizeof ( CMD_ADD )); }
    {void * tlv12; tlv12 = (void *)(sizeof ( CMD_ADD )); }
    {void * tlv11; tlv11 = (void *)(sizeof ( CMD_ADD )); }
    {unsigned int tlv10; tlv10 = (unsigned int)(sizeof ( CMD_ADD )); }
    {int tlv2; tlv2 = (int)(sizeof ( CMD_ADD )); }
    {void * tlv15; tlv15 = (void *)(sizeof ( CMD_ADD )); }
    {void * tlv14; tlv14 = (void *)(sizeof ( CMD_ADD )); }
    {unsigned int tlv13; tlv13 = (unsigned int)(sizeof ( CMD_ADD )); }
    {int tlv3; tlv3 = (int)(sizeof ( CMD_ADD )); }
    {void * tlv18; tlv18 = (void *)(sizeof ( CMD_ADD )); }
    {void * tlv17; tlv17 = (void *)(sizeof ( CMD_ADD )); }
    {unsigned int tlv16; tlv16 = (unsigned int)(sizeof ( CMD_ADD )); }
    {int tlv4; tlv4 = (int)(sizeof ( CMD_ADD )); }
    {void * tlv21; tlv21 = (void *)(sizeof ( CMD_ADD )); }
    {void * tlv20; tlv20 = (void *)(sizeof ( CMD_ADD )); }
    {unsigned int tlv19; tlv19 = (unsigned int)(sizeof ( CMD_ADD )); }
    {int tlv5; tlv5 = (int)(sizeof ( CMD_ADD )); }
    {void * tlv24; tlv24 = (void *)(sizeof ( CMD_ADD )); }
    {void * tlv23; tlv23 = (void *)(sizeof ( CMD_ADD )); }
    {unsigned int tlv22; tlv22 = (unsigned int)(sizeof ( CMD_ADD )); }
    {int tlv6; tlv6 = (int)(sizeof ( CMD_ADD )); }
    {void * tlv27; tlv27 = (void *)(sizeof ( CMD_ADD )); }
    {void * tlv26; tlv26 = (void *)(sizeof ( CMD_ADD )); }
    {unsigned int tlv25; tlv25 = (unsigned int)(sizeof ( CMD_ADD )); }
    {int tlv7; tlv7 = (int)(sizeof ( CMD_ADD )); }
    {void * tlv30; tlv30 = (void *)(sizeof ( CMD_ADD )); }
    {void * tlv29; tlv29 = (void *)(sizeof ( CMD_ADD )); }
    {unsigned int tlv28; tlv28 = (unsigned int)(sizeof ( CMD_ADD )); }
    {int tlv8; tlv8 = (int)(sizeof ( CMD_ADD )); }
    {void * tlv33; tlv33 = (void *)(sizeof ( CMD_ADD )); }
    {void * tlv32; tlv32 = (void *)(sizeof ( CMD_ADD )); }
    {unsigned int tlv31; tlv31 = (unsigned int)(sizeof ( CMD_ADD )); }
    {int tlv9; tlv9 = (int)(sizeof ( CMD_ADD )); }
    {void * tlv36; tlv36 = (void *)(sizeof ( CMD_ADD )); }
    {void * tlv35; tlv35 = (void *)(sizeof ( CMD_ADD )); }
    {unsigned int tlv34; tlv34 = (unsigned int)(sizeof ( CMD_ADD )); }
}
void fix_ingred_products_12_7(){
fix_ingred_products_12_7_0();
fix_ingred_products_12_7_2();
}
void fix_ingred_products_12_8_2(){
int tlv3;
    bzero(&tlv3,sizeof(int));
    {char cmd [ 4 ]; cmd [ ( 4 )-1 ] = (char)(tlv3); }
    {short ret; ret = (short)(tlv3); }
    {int tlv1; tlv1 = (int)(tlv3); }
    {void * tlv12; tlv12 = (void *)(tlv3); }
    {void * tlv11; tlv11 = (void *)(tlv3); }
    {unsigned int tlv10; tlv10 = (unsigned int)(tlv3); }
    {int tlv2; tlv2 = (int)(tlv3); }
    {void * tlv15; tlv15 = (void *)(tlv3); }
    {void * tlv14; tlv14 = (void *)(tlv3); }
    {unsigned int tlv13; tlv13 = (unsigned int)(tlv3); }
    {void * tlv18; tlv18 = (void *)(tlv3); }
    {void * tlv17; tlv17 = (void *)(tlv3); }
    {unsigned int tlv16; tlv16 = (unsigned int)(tlv3); }
    {int tlv4; tlv4 = (int)(tlv3); }
    {void * tlv21; tlv21 = (void *)(tlv3); }
    {void * tlv20; tlv20 = (void *)(tlv3); }
    {unsigned int tlv19; tlv19 = (unsigned int)(tlv3); }
    {int tlv5; tlv5 = (int)(tlv3); }
    {void * tlv24; tlv24 = (void *)(tlv3); }
    {void * tlv23; tlv23 = (void *)(tlv3); }
    {unsigned int tlv22; tlv22 = (unsigned int)(tlv3); }
    {int tlv6; tlv6 = (int)(tlv3); }
    {void * tlv27; tlv27 = (void *)(tlv3); }
    {void * tlv26; tlv26 = (void *)(tlv3); }
    {unsigned int tlv25; tlv25 = (unsigned int)(tlv3); }
    {int tlv7; tlv7 = (int)(tlv3); }
    {void * tlv30; tlv30 = (void *)(tlv3); }
    {void * tlv29; tlv29 = (void *)(tlv3); }
    {unsigned int tlv28; tlv28 = (unsigned int)(tlv3); }
    {int tlv8; tlv8 = (int)(tlv3); }
    {void * tlv33; tlv33 = (void *)(tlv3); }
    {void * tlv32; tlv32 = (void *)(tlv3); }
    {unsigned int tlv31; tlv31 = (unsigned int)(tlv3); }
    {int tlv9; tlv9 = (int)(tlv3); }
    {void * tlv36; tlv36 = (void *)(tlv3); }
    {void * tlv35; tlv35 = (void *)(tlv3); }
    {unsigned int tlv34; tlv34 = (unsigned int)(tlv3); }
}
void fix_ingred_products_12_8(){
fix_ingred_products_12_8_2();
}
void fix_ingred_products_12_10_0(){
    {char cmd [ 4 ]; cmd [ ( 4 )-1 ] = (char)(( void * ) CMD_RM); }
    {short ret; ret = (short)(( void * ) CMD_RM); }
    {int tlv1; tlv1 = (int)(( void * ) CMD_RM); }
    {void * tlv12; tlv12 = (void *)(( void * ) CMD_RM); }
    {void * tlv11; tlv11 = (void *)(( void * ) CMD_RM); }
    {unsigned int tlv10; tlv10 = (unsigned int)(( void * ) CMD_RM); }
    {int tlv2; tlv2 = (int)(( void * ) CMD_RM); }
    {void * tlv15; tlv15 = (void *)(( void * ) CMD_RM); }
    {void * tlv14; tlv14 = (void *)(( void * ) CMD_RM); }
    {unsigned int tlv13; tlv13 = (unsigned int)(( void * ) CMD_RM); }
    {int tlv3; tlv3 = (int)(( void * ) CMD_RM); }
    {void * tlv18; tlv18 = (void *)(( void * ) CMD_RM); }
    {void * tlv17; tlv17 = (void *)(( void * ) CMD_RM); }
    {unsigned int tlv16; tlv16 = (unsigned int)(( void * ) CMD_RM); }
    {int tlv4; tlv4 = (int)(( void * ) CMD_RM); }
    {void * tlv21; tlv21 = (void *)(( void * ) CMD_RM); }
    {void * tlv20; tlv20 = (void *)(( void * ) CMD_RM); }
    {unsigned int tlv19; tlv19 = (unsigned int)(( void * ) CMD_RM); }
    {int tlv5; tlv5 = (int)(( void * ) CMD_RM); }
    {void * tlv24; tlv24 = (void *)(( void * ) CMD_RM); }
    {void * tlv23; tlv23 = (void *)(( void * ) CMD_RM); }
    {unsigned int tlv22; tlv22 = (unsigned int)(( void * ) CMD_RM); }
    {int tlv6; tlv6 = (int)(( void * ) CMD_RM); }
    {void * tlv27; tlv27 = (void *)(( void * ) CMD_RM); }
    {void * tlv26; tlv26 = (void *)(( void * ) CMD_RM); }
    {unsigned int tlv25; tlv25 = (unsigned int)(( void * ) CMD_RM); }
    {int tlv7; tlv7 = (int)(( void * ) CMD_RM); }
    {void * tlv30; tlv30 = (void *)(( void * ) CMD_RM); }
    {void * tlv29; tlv29 = (void *)(( void * ) CMD_RM); }
    {unsigned int tlv28; tlv28 = (unsigned int)(( void * ) CMD_RM); }
    {int tlv8; tlv8 = (int)(( void * ) CMD_RM); }
    {void * tlv33; tlv33 = (void *)(( void * ) CMD_RM); }
    {void * tlv32; tlv32 = (void *)(( void * ) CMD_RM); }
    {unsigned int tlv31; tlv31 = (unsigned int)(( void * ) CMD_RM); }
    {int tlv9; tlv9 = (int)(( void * ) CMD_RM); }
    {void * tlv36; tlv36 = (void *)(( void * ) CMD_RM); }
    {void * tlv35; tlv35 = (void *)(( void * ) CMD_RM); }
    {unsigned int tlv34; tlv34 = (unsigned int)(( void * ) CMD_RM); }
}
void fix_ingred_products_12_10_2(){
    {char cmd [ 4 ]; cmd [ ( 4 )-1 ] = (char)(sizeof ( CMD_RM )); }
    {short ret; ret = (short)(sizeof ( CMD_RM )); }
    {int tlv1; tlv1 = (int)(sizeof ( CMD_RM )); }
    {void * tlv12; tlv12 = (void *)(sizeof ( CMD_RM )); }
    {void * tlv11; tlv11 = (void *)(sizeof ( CMD_RM )); }
    {unsigned int tlv10; tlv10 = (unsigned int)(sizeof ( CMD_RM )); }
    {int tlv2; tlv2 = (int)(sizeof ( CMD_RM )); }
    {void * tlv15; tlv15 = (void *)(sizeof ( CMD_RM )); }
    {void * tlv14; tlv14 = (void *)(sizeof ( CMD_RM )); }
    {unsigned int tlv13; tlv13 = (unsigned int)(sizeof ( CMD_RM )); }
    {int tlv3; tlv3 = (int)(sizeof ( CMD_RM )); }
    {void * tlv18; tlv18 = (void *)(sizeof ( CMD_RM )); }
    {void * tlv17; tlv17 = (void *)(sizeof ( CMD_RM )); }
    {unsigned int tlv16; tlv16 = (unsigned int)(sizeof ( CMD_RM )); }
    {int tlv4; tlv4 = (int)(sizeof ( CMD_RM )); }
    {void * tlv21; tlv21 = (void *)(sizeof ( CMD_RM )); }
    {void * tlv20; tlv20 = (void *)(sizeof ( CMD_RM )); }
    {unsigned int tlv19; tlv19 = (unsigned int)(sizeof ( CMD_RM )); }
    {int tlv5; tlv5 = (int)(sizeof ( CMD_RM )); }
    {void * tlv24; tlv24 = (void *)(sizeof ( CMD_RM )); }
    {void * tlv23; tlv23 = (void *)(sizeof ( CMD_RM )); }
    {unsigned int tlv22; tlv22 = (unsigned int)(sizeof ( CMD_RM )); }
    {int tlv6; tlv6 = (int)(sizeof ( CMD_RM )); }
    {void * tlv27; tlv27 = (void *)(sizeof ( CMD_RM )); }
    {void * tlv26; tlv26 = (void *)(sizeof ( CMD_RM )); }
    {unsigned int tlv25; tlv25 = (unsigned int)(sizeof ( CMD_RM )); }
    {int tlv7; tlv7 = (int)(sizeof ( CMD_RM )); }
    {void * tlv30; tlv30 = (void *)(sizeof ( CMD_RM )); }
    {void * tlv29; tlv29 = (void *)(sizeof ( CMD_RM )); }
    {unsigned int tlv28; tlv28 = (unsigned int)(sizeof ( CMD_RM )); }
    {int tlv8; tlv8 = (int)(sizeof ( CMD_RM )); }
    {void * tlv33; tlv33 = (void *)(sizeof ( CMD_RM )); }
    {void * tlv32; tlv32 = (void *)(sizeof ( CMD_RM )); }
    {unsigned int tlv31; tlv31 = (unsigned int)(sizeof ( CMD_RM )); }
    {int tlv9; tlv9 = (int)(sizeof ( CMD_RM )); }
    {void * tlv36; tlv36 = (void *)(sizeof ( CMD_RM )); }
    {void * tlv35; tlv35 = (void *)(sizeof ( CMD_RM )); }
    {unsigned int tlv34; tlv34 = (unsigned int)(sizeof ( CMD_RM )); }
}
void fix_ingred_products_12_10(){
fix_ingred_products_12_10_0();
fix_ingred_products_12_10_2();
}
void fix_ingred_products_12_11_2(){
int tlv4;
    bzero(&tlv4,sizeof(int));
    {char cmd [ 4 ]; cmd [ ( 4 )-1 ] = (char)(tlv4); }
    {short ret; ret = (short)(tlv4); }
    {int tlv1; tlv1 = (int)(tlv4); }
    {void * tlv12; tlv12 = (void *)(tlv4); }
    {void * tlv11; tlv11 = (void *)(tlv4); }
    {unsigned int tlv10; tlv10 = (unsigned int)(tlv4); }
    {int tlv2; tlv2 = (int)(tlv4); }
    {void * tlv15; tlv15 = (void *)(tlv4); }
    {void * tlv14; tlv14 = (void *)(tlv4); }
    {unsigned int tlv13; tlv13 = (unsigned int)(tlv4); }
    {int tlv3; tlv3 = (int)(tlv4); }
    {void * tlv18; tlv18 = (void *)(tlv4); }
    {void * tlv17; tlv17 = (void *)(tlv4); }
    {unsigned int tlv16; tlv16 = (unsigned int)(tlv4); }
    {void * tlv21; tlv21 = (void *)(tlv4); }
    {void * tlv20; tlv20 = (void *)(tlv4); }
    {unsigned int tlv19; tlv19 = (unsigned int)(tlv4); }
    {int tlv5; tlv5 = (int)(tlv4); }
    {void * tlv24; tlv24 = (void *)(tlv4); }
    {void * tlv23; tlv23 = (void *)(tlv4); }
    {unsigned int tlv22; tlv22 = (unsigned int)(tlv4); }
    {int tlv6; tlv6 = (int)(tlv4); }
    {void * tlv27; tlv27 = (void *)(tlv4); }
    {void * tlv26; tlv26 = (void *)(tlv4); }
    {unsigned int tlv25; tlv25 = (unsigned int)(tlv4); }
    {int tlv7; tlv7 = (int)(tlv4); }
    {void * tlv30; tlv30 = (void *)(tlv4); }
    {void * tlv29; tlv29 = (void *)(tlv4); }
    {unsigned int tlv28; tlv28 = (unsigned int)(tlv4); }
    {int tlv8; tlv8 = (int)(tlv4); }
    {void * tlv33; tlv33 = (void *)(tlv4); }
    {void * tlv32; tlv32 = (void *)(tlv4); }
    {unsigned int tlv31; tlv31 = (unsigned int)(tlv4); }
    {int tlv9; tlv9 = (int)(tlv4); }
    {void * tlv36; tlv36 = (void *)(tlv4); }
    {void * tlv35; tlv35 = (void *)(tlv4); }
    {unsigned int tlv34; tlv34 = (unsigned int)(tlv4); }
}
void fix_ingred_products_12_11(){
fix_ingred_products_12_11_2();
}
void fix_ingred_products_12_13_0(){
    {char cmd [ 4 ]; cmd [ ( 4 )-1 ] = (char)(( void * ) CMD_UPDATE); }
    {short ret; ret = (short)(( void * ) CMD_UPDATE); }
    {int tlv1; tlv1 = (int)(( void * ) CMD_UPDATE); }
    {void * tlv12; tlv12 = (void *)(( void * ) CMD_UPDATE); }
    {void * tlv11; tlv11 = (void *)(( void * ) CMD_UPDATE); }
    {unsigned int tlv10; tlv10 = (unsigned int)(( void * ) CMD_UPDATE); }
    {int tlv2; tlv2 = (int)(( void * ) CMD_UPDATE); }
    {void * tlv15; tlv15 = (void *)(( void * ) CMD_UPDATE); }
    {void * tlv14; tlv14 = (void *)(( void * ) CMD_UPDATE); }
    {unsigned int tlv13; tlv13 = (unsigned int)(( void * ) CMD_UPDATE); }
    {int tlv3; tlv3 = (int)(( void * ) CMD_UPDATE); }
    {void * tlv18; tlv18 = (void *)(( void * ) CMD_UPDATE); }
    {void * tlv17; tlv17 = (void *)(( void * ) CMD_UPDATE); }
    {unsigned int tlv16; tlv16 = (unsigned int)(( void * ) CMD_UPDATE); }
    {int tlv4; tlv4 = (int)(( void * ) CMD_UPDATE); }
    {void * tlv21; tlv21 = (void *)(( void * ) CMD_UPDATE); }
    {void * tlv20; tlv20 = (void *)(( void * ) CMD_UPDATE); }
    {unsigned int tlv19; tlv19 = (unsigned int)(( void * ) CMD_UPDATE); }
    {int tlv5; tlv5 = (int)(( void * ) CMD_UPDATE); }
    {void * tlv24; tlv24 = (void *)(( void * ) CMD_UPDATE); }
    {void * tlv23; tlv23 = (void *)(( void * ) CMD_UPDATE); }
    {unsigned int tlv22; tlv22 = (unsigned int)(( void * ) CMD_UPDATE); }
    {int tlv6; tlv6 = (int)(( void * ) CMD_UPDATE); }
    {void * tlv27; tlv27 = (void *)(( void * ) CMD_UPDATE); }
    {void * tlv26; tlv26 = (void *)(( void * ) CMD_UPDATE); }
    {unsigned int tlv25; tlv25 = (unsigned int)(( void * ) CMD_UPDATE); }
    {int tlv7; tlv7 = (int)(( void * ) CMD_UPDATE); }
    {void * tlv30; tlv30 = (void *)(( void * ) CMD_UPDATE); }
    {void * tlv29; tlv29 = (void *)(( void * ) CMD_UPDATE); }
    {unsigned int tlv28; tlv28 = (unsigned int)(( void * ) CMD_UPDATE); }
    {int tlv8; tlv8 = (int)(( void * ) CMD_UPDATE); }
    {void * tlv33; tlv33 = (void *)(( void * ) CMD_UPDATE); }
    {void * tlv32; tlv32 = (void *)(( void * ) CMD_UPDATE); }
    {unsigned int tlv31; tlv31 = (unsigned int)(( void * ) CMD_UPDATE); }
    {int tlv9; tlv9 = (int)(( void * ) CMD_UPDATE); }
    {void * tlv36; tlv36 = (void *)(( void * ) CMD_UPDATE); }
    {void * tlv35; tlv35 = (void *)(( void * ) CMD_UPDATE); }
    {unsigned int tlv34; tlv34 = (unsigned int)(( void * ) CMD_UPDATE); }
}
void fix_ingred_products_12_13_2(){
    {char cmd [ 4 ]; cmd [ ( 4 )-1 ] = (char)(sizeof ( CMD_UPDATE )); }
    {short ret; ret = (short)(sizeof ( CMD_UPDATE )); }
    {int tlv1; tlv1 = (int)(sizeof ( CMD_UPDATE )); }
    {void * tlv12; tlv12 = (void *)(sizeof ( CMD_UPDATE )); }
    {void * tlv11; tlv11 = (void *)(sizeof ( CMD_UPDATE )); }
    {unsigned int tlv10; tlv10 = (unsigned int)(sizeof ( CMD_UPDATE )); }
    {int tlv2; tlv2 = (int)(sizeof ( CMD_UPDATE )); }
    {void * tlv15; tlv15 = (void *)(sizeof ( CMD_UPDATE )); }
    {void * tlv14; tlv14 = (void *)(sizeof ( CMD_UPDATE )); }
    {unsigned int tlv13; tlv13 = (unsigned int)(sizeof ( CMD_UPDATE )); }
    {int tlv3; tlv3 = (int)(sizeof ( CMD_UPDATE )); }
    {void * tlv18; tlv18 = (void *)(sizeof ( CMD_UPDATE )); }
    {void * tlv17; tlv17 = (void *)(sizeof ( CMD_UPDATE )); }
    {unsigned int tlv16; tlv16 = (unsigned int)(sizeof ( CMD_UPDATE )); }
    {int tlv4; tlv4 = (int)(sizeof ( CMD_UPDATE )); }
    {void * tlv21; tlv21 = (void *)(sizeof ( CMD_UPDATE )); }
    {void * tlv20; tlv20 = (void *)(sizeof ( CMD_UPDATE )); }
    {unsigned int tlv19; tlv19 = (unsigned int)(sizeof ( CMD_UPDATE )); }
    {int tlv5; tlv5 = (int)(sizeof ( CMD_UPDATE )); }
    {void * tlv24; tlv24 = (void *)(sizeof ( CMD_UPDATE )); }
    {void * tlv23; tlv23 = (void *)(sizeof ( CMD_UPDATE )); }
    {unsigned int tlv22; tlv22 = (unsigned int)(sizeof ( CMD_UPDATE )); }
    {int tlv6; tlv6 = (int)(sizeof ( CMD_UPDATE )); }
    {void * tlv27; tlv27 = (void *)(sizeof ( CMD_UPDATE )); }
    {void * tlv26; tlv26 = (void *)(sizeof ( CMD_UPDATE )); }
    {unsigned int tlv25; tlv25 = (unsigned int)(sizeof ( CMD_UPDATE )); }
    {int tlv7; tlv7 = (int)(sizeof ( CMD_UPDATE )); }
    {void * tlv30; tlv30 = (void *)(sizeof ( CMD_UPDATE )); }
    {void * tlv29; tlv29 = (void *)(sizeof ( CMD_UPDATE )); }
    {unsigned int tlv28; tlv28 = (unsigned int)(sizeof ( CMD_UPDATE )); }
    {int tlv8; tlv8 = (int)(sizeof ( CMD_UPDATE )); }
    {void * tlv33; tlv33 = (void *)(sizeof ( CMD_UPDATE )); }
    {void * tlv32; tlv32 = (void *)(sizeof ( CMD_UPDATE )); }
    {unsigned int tlv31; tlv31 = (unsigned int)(sizeof ( CMD_UPDATE )); }
    {int tlv9; tlv9 = (int)(sizeof ( CMD_UPDATE )); }
    {void * tlv36; tlv36 = (void *)(sizeof ( CMD_UPDATE )); }
    {void * tlv35; tlv35 = (void *)(sizeof ( CMD_UPDATE )); }
    {unsigned int tlv34; tlv34 = (unsigned int)(sizeof ( CMD_UPDATE )); }
}
void fix_ingred_products_12_13(){
fix_ingred_products_12_13_0();
fix_ingred_products_12_13_2();
}
void fix_ingred_products_12_14_2(){
int tlv5;
    bzero(&tlv5,sizeof(int));
    {char cmd [ 4 ]; cmd [ ( 4 )-1 ] = (char)(tlv5); }
    {short ret; ret = (short)(tlv5); }
    {int tlv1; tlv1 = (int)(tlv5); }
    {void * tlv12; tlv12 = (void *)(tlv5); }
    {void * tlv11; tlv11 = (void *)(tlv5); }
    {unsigned int tlv10; tlv10 = (unsigned int)(tlv5); }
    {int tlv2; tlv2 = (int)(tlv5); }
    {void * tlv15; tlv15 = (void *)(tlv5); }
    {void * tlv14; tlv14 = (void *)(tlv5); }
    {unsigned int tlv13; tlv13 = (unsigned int)(tlv5); }
    {int tlv3; tlv3 = (int)(tlv5); }
    {void * tlv18; tlv18 = (void *)(tlv5); }
    {void * tlv17; tlv17 = (void *)(tlv5); }
    {unsigned int tlv16; tlv16 = (unsigned int)(tlv5); }
    {int tlv4; tlv4 = (int)(tlv5); }
    {void * tlv21; tlv21 = (void *)(tlv5); }
    {void * tlv20; tlv20 = (void *)(tlv5); }
    {unsigned int tlv19; tlv19 = (unsigned int)(tlv5); }
    {void * tlv24; tlv24 = (void *)(tlv5); }
    {void * tlv23; tlv23 = (void *)(tlv5); }
    {unsigned int tlv22; tlv22 = (unsigned int)(tlv5); }
    {int tlv6; tlv6 = (int)(tlv5); }
    {void * tlv27; tlv27 = (void *)(tlv5); }
    {void * tlv26; tlv26 = (void *)(tlv5); }
    {unsigned int tlv25; tlv25 = (unsigned int)(tlv5); }
    {int tlv7; tlv7 = (int)(tlv5); }
    {void * tlv30; tlv30 = (void *)(tlv5); }
    {void * tlv29; tlv29 = (void *)(tlv5); }
    {unsigned int tlv28; tlv28 = (unsigned int)(tlv5); }
    {int tlv8; tlv8 = (int)(tlv5); }
    {void * tlv33; tlv33 = (void *)(tlv5); }
    {void * tlv32; tlv32 = (void *)(tlv5); }
    {unsigned int tlv31; tlv31 = (unsigned int)(tlv5); }
    {int tlv9; tlv9 = (int)(tlv5); }
    {void * tlv36; tlv36 = (void *)(tlv5); }
    {void * tlv35; tlv35 = (void *)(tlv5); }
    {unsigned int tlv34; tlv34 = (unsigned int)(tlv5); }
}
void fix_ingred_products_12_14(){
fix_ingred_products_12_14_2();
}
void fix_ingred_products_12_16_0(){
    {char cmd [ 4 ]; cmd [ ( 4 )-1 ] = (char)(( void * ) CMD_ONSALE); }
    {short ret; ret = (short)(( void * ) CMD_ONSALE); }
    {int tlv1; tlv1 = (int)(( void * ) CMD_ONSALE); }
    {void * tlv12; tlv12 = (void *)(( void * ) CMD_ONSALE); }
    {void * tlv11; tlv11 = (void *)(( void * ) CMD_ONSALE); }
    {unsigned int tlv10; tlv10 = (unsigned int)(( void * ) CMD_ONSALE); }
    {int tlv2; tlv2 = (int)(( void * ) CMD_ONSALE); }
    {void * tlv15; tlv15 = (void *)(( void * ) CMD_ONSALE); }
    {void * tlv14; tlv14 = (void *)(( void * ) CMD_ONSALE); }
    {unsigned int tlv13; tlv13 = (unsigned int)(( void * ) CMD_ONSALE); }
    {int tlv3; tlv3 = (int)(( void * ) CMD_ONSALE); }
    {void * tlv18; tlv18 = (void *)(( void * ) CMD_ONSALE); }
    {void * tlv17; tlv17 = (void *)(( void * ) CMD_ONSALE); }
    {unsigned int tlv16; tlv16 = (unsigned int)(( void * ) CMD_ONSALE); }
    {int tlv4; tlv4 = (int)(( void * ) CMD_ONSALE); }
    {void * tlv21; tlv21 = (void *)(( void * ) CMD_ONSALE); }
    {void * tlv20; tlv20 = (void *)(( void * ) CMD_ONSALE); }
    {unsigned int tlv19; tlv19 = (unsigned int)(( void * ) CMD_ONSALE); }
    {int tlv5; tlv5 = (int)(( void * ) CMD_ONSALE); }
    {void * tlv24; tlv24 = (void *)(( void * ) CMD_ONSALE); }
    {void * tlv23; tlv23 = (void *)(( void * ) CMD_ONSALE); }
    {unsigned int tlv22; tlv22 = (unsigned int)(( void * ) CMD_ONSALE); }
    {int tlv6; tlv6 = (int)(( void * ) CMD_ONSALE); }
    {void * tlv27; tlv27 = (void *)(( void * ) CMD_ONSALE); }
    {void * tlv26; tlv26 = (void *)(( void * ) CMD_ONSALE); }
    {unsigned int tlv25; tlv25 = (unsigned int)(( void * ) CMD_ONSALE); }
    {int tlv7; tlv7 = (int)(( void * ) CMD_ONSALE); }
    {void * tlv30; tlv30 = (void *)(( void * ) CMD_ONSALE); }
    {void * tlv29; tlv29 = (void *)(( void * ) CMD_ONSALE); }
    {unsigned int tlv28; tlv28 = (unsigned int)(( void * ) CMD_ONSALE); }
    {int tlv8; tlv8 = (int)(( void * ) CMD_ONSALE); }
    {void * tlv33; tlv33 = (void *)(( void * ) CMD_ONSALE); }
    {void * tlv32; tlv32 = (void *)(( void * ) CMD_ONSALE); }
    {unsigned int tlv31; tlv31 = (unsigned int)(( void * ) CMD_ONSALE); }
    {int tlv9; tlv9 = (int)(( void * ) CMD_ONSALE); }
    {void * tlv36; tlv36 = (void *)(( void * ) CMD_ONSALE); }
    {void * tlv35; tlv35 = (void *)(( void * ) CMD_ONSALE); }
    {unsigned int tlv34; tlv34 = (unsigned int)(( void * ) CMD_ONSALE); }
}
void fix_ingred_products_12_16_2(){
    {char cmd [ 4 ]; cmd [ ( 4 )-1 ] = (char)(sizeof ( CMD_ONSALE )); }
    {short ret; ret = (short)(sizeof ( CMD_ONSALE )); }
    {int tlv1; tlv1 = (int)(sizeof ( CMD_ONSALE )); }
    {void * tlv12; tlv12 = (void *)(sizeof ( CMD_ONSALE )); }
    {void * tlv11; tlv11 = (void *)(sizeof ( CMD_ONSALE )); }
    {unsigned int tlv10; tlv10 = (unsigned int)(sizeof ( CMD_ONSALE )); }
    {int tlv2; tlv2 = (int)(sizeof ( CMD_ONSALE )); }
    {void * tlv15; tlv15 = (void *)(sizeof ( CMD_ONSALE )); }
    {void * tlv14; tlv14 = (void *)(sizeof ( CMD_ONSALE )); }
    {unsigned int tlv13; tlv13 = (unsigned int)(sizeof ( CMD_ONSALE )); }
    {int tlv3; tlv3 = (int)(sizeof ( CMD_ONSALE )); }
    {void * tlv18; tlv18 = (void *)(sizeof ( CMD_ONSALE )); }
    {void * tlv17; tlv17 = (void *)(sizeof ( CMD_ONSALE )); }
    {unsigned int tlv16; tlv16 = (unsigned int)(sizeof ( CMD_ONSALE )); }
    {int tlv4; tlv4 = (int)(sizeof ( CMD_ONSALE )); }
    {void * tlv21; tlv21 = (void *)(sizeof ( CMD_ONSALE )); }
    {void * tlv20; tlv20 = (void *)(sizeof ( CMD_ONSALE )); }
    {unsigned int tlv19; tlv19 = (unsigned int)(sizeof ( CMD_ONSALE )); }
    {int tlv5; tlv5 = (int)(sizeof ( CMD_ONSALE )); }
    {void * tlv24; tlv24 = (void *)(sizeof ( CMD_ONSALE )); }
    {void * tlv23; tlv23 = (void *)(sizeof ( CMD_ONSALE )); }
    {unsigned int tlv22; tlv22 = (unsigned int)(sizeof ( CMD_ONSALE )); }
    {int tlv6; tlv6 = (int)(sizeof ( CMD_ONSALE )); }
    {void * tlv27; tlv27 = (void *)(sizeof ( CMD_ONSALE )); }
    {void * tlv26; tlv26 = (void *)(sizeof ( CMD_ONSALE )); }
    {unsigned int tlv25; tlv25 = (unsigned int)(sizeof ( CMD_ONSALE )); }
    {int tlv7; tlv7 = (int)(sizeof ( CMD_ONSALE )); }
    {void * tlv30; tlv30 = (void *)(sizeof ( CMD_ONSALE )); }
    {void * tlv29; tlv29 = (void *)(sizeof ( CMD_ONSALE )); }
    {unsigned int tlv28; tlv28 = (unsigned int)(sizeof ( CMD_ONSALE )); }
    {int tlv8; tlv8 = (int)(sizeof ( CMD_ONSALE )); }
    {void * tlv33; tlv33 = (void *)(sizeof ( CMD_ONSALE )); }
    {void * tlv32; tlv32 = (void *)(sizeof ( CMD_ONSALE )); }
    {unsigned int tlv31; tlv31 = (unsigned int)(sizeof ( CMD_ONSALE )); }
    {int tlv9; tlv9 = (int)(sizeof ( CMD_ONSALE )); }
    {void * tlv36; tlv36 = (void *)(sizeof ( CMD_ONSALE )); }
    {void * tlv35; tlv35 = (void *)(sizeof ( CMD_ONSALE )); }
    {unsigned int tlv34; tlv34 = (unsigned int)(sizeof ( CMD_ONSALE )); }
}
void fix_ingred_products_12_16(){
fix_ingred_products_12_16_0();
fix_ingred_products_12_16_2();
}
void fix_ingred_products_12_17_2(){
int tlv6;
    bzero(&tlv6,sizeof(int));
    {char cmd [ 4 ]; cmd [ ( 4 )-1 ] = (char)(tlv6); }
    {short ret; ret = (short)(tlv6); }
    {int tlv1; tlv1 = (int)(tlv6); }
    {void * tlv12; tlv12 = (void *)(tlv6); }
    {void * tlv11; tlv11 = (void *)(tlv6); }
    {unsigned int tlv10; tlv10 = (unsigned int)(tlv6); }
    {int tlv2; tlv2 = (int)(tlv6); }
    {void * tlv15; tlv15 = (void *)(tlv6); }
    {void * tlv14; tlv14 = (void *)(tlv6); }
    {unsigned int tlv13; tlv13 = (unsigned int)(tlv6); }
    {int tlv3; tlv3 = (int)(tlv6); }
    {void * tlv18; tlv18 = (void *)(tlv6); }
    {void * tlv17; tlv17 = (void *)(tlv6); }
    {unsigned int tlv16; tlv16 = (unsigned int)(tlv6); }
    {int tlv4; tlv4 = (int)(tlv6); }
    {void * tlv21; tlv21 = (void *)(tlv6); }
    {void * tlv20; tlv20 = (void *)(tlv6); }
    {unsigned int tlv19; tlv19 = (unsigned int)(tlv6); }
    {int tlv5; tlv5 = (int)(tlv6); }
    {void * tlv24; tlv24 = (void *)(tlv6); }
    {void * tlv23; tlv23 = (void *)(tlv6); }
    {unsigned int tlv22; tlv22 = (unsigned int)(tlv6); }
    {void * tlv27; tlv27 = (void *)(tlv6); }
    {void * tlv26; tlv26 = (void *)(tlv6); }
    {unsigned int tlv25; tlv25 = (unsigned int)(tlv6); }
    {int tlv7; tlv7 = (int)(tlv6); }
    {void * tlv30; tlv30 = (void *)(tlv6); }
    {void * tlv29; tlv29 = (void *)(tlv6); }
    {unsigned int tlv28; tlv28 = (unsigned int)(tlv6); }
    {int tlv8; tlv8 = (int)(tlv6); }
    {void * tlv33; tlv33 = (void *)(tlv6); }
    {void * tlv32; tlv32 = (void *)(tlv6); }
    {unsigned int tlv31; tlv31 = (unsigned int)(tlv6); }
    {int tlv9; tlv9 = (int)(tlv6); }
    {void * tlv36; tlv36 = (void *)(tlv6); }
    {void * tlv35; tlv35 = (void *)(tlv6); }
    {unsigned int tlv34; tlv34 = (unsigned int)(tlv6); }
}
void fix_ingred_products_12_17(){
fix_ingred_products_12_17_2();
}
void fix_ingred_products_12_19_0(){
    {char cmd [ 4 ]; cmd [ ( 4 )-1 ] = (char)(( void * ) CMD_NOSALE); }
    {short ret; ret = (short)(( void * ) CMD_NOSALE); }
    {int tlv1; tlv1 = (int)(( void * ) CMD_NOSALE); }
    {void * tlv12; tlv12 = (void *)(( void * ) CMD_NOSALE); }
    {void * tlv11; tlv11 = (void *)(( void * ) CMD_NOSALE); }
    {unsigned int tlv10; tlv10 = (unsigned int)(( void * ) CMD_NOSALE); }
    {int tlv2; tlv2 = (int)(( void * ) CMD_NOSALE); }
    {void * tlv15; tlv15 = (void *)(( void * ) CMD_NOSALE); }
    {void * tlv14; tlv14 = (void *)(( void * ) CMD_NOSALE); }
    {unsigned int tlv13; tlv13 = (unsigned int)(( void * ) CMD_NOSALE); }
    {int tlv3; tlv3 = (int)(( void * ) CMD_NOSALE); }
    {void * tlv18; tlv18 = (void *)(( void * ) CMD_NOSALE); }
    {void * tlv17; tlv17 = (void *)(( void * ) CMD_NOSALE); }
    {unsigned int tlv16; tlv16 = (unsigned int)(( void * ) CMD_NOSALE); }
    {int tlv4; tlv4 = (int)(( void * ) CMD_NOSALE); }
    {void * tlv21; tlv21 = (void *)(( void * ) CMD_NOSALE); }
    {void * tlv20; tlv20 = (void *)(( void * ) CMD_NOSALE); }
    {unsigned int tlv19; tlv19 = (unsigned int)(( void * ) CMD_NOSALE); }
    {int tlv5; tlv5 = (int)(( void * ) CMD_NOSALE); }
    {void * tlv24; tlv24 = (void *)(( void * ) CMD_NOSALE); }
    {void * tlv23; tlv23 = (void *)(( void * ) CMD_NOSALE); }
    {unsigned int tlv22; tlv22 = (unsigned int)(( void * ) CMD_NOSALE); }
    {int tlv6; tlv6 = (int)(( void * ) CMD_NOSALE); }
    {void * tlv27; tlv27 = (void *)(( void * ) CMD_NOSALE); }
    {void * tlv26; tlv26 = (void *)(( void * ) CMD_NOSALE); }
    {unsigned int tlv25; tlv25 = (unsigned int)(( void * ) CMD_NOSALE); }
    {int tlv7; tlv7 = (int)(( void * ) CMD_NOSALE); }
    {void * tlv30; tlv30 = (void *)(( void * ) CMD_NOSALE); }
    {void * tlv29; tlv29 = (void *)(( void * ) CMD_NOSALE); }
    {unsigned int tlv28; tlv28 = (unsigned int)(( void * ) CMD_NOSALE); }
    {int tlv8; tlv8 = (int)(( void * ) CMD_NOSALE); }
    {void * tlv33; tlv33 = (void *)(( void * ) CMD_NOSALE); }
    {void * tlv32; tlv32 = (void *)(( void * ) CMD_NOSALE); }
    {unsigned int tlv31; tlv31 = (unsigned int)(( void * ) CMD_NOSALE); }
    {int tlv9; tlv9 = (int)(( void * ) CMD_NOSALE); }
    {void * tlv36; tlv36 = (void *)(( void * ) CMD_NOSALE); }
    {void * tlv35; tlv35 = (void *)(( void * ) CMD_NOSALE); }
    {unsigned int tlv34; tlv34 = (unsigned int)(( void * ) CMD_NOSALE); }
}
void fix_ingred_products_12_19_2(){
    {char cmd [ 4 ]; cmd [ ( 4 )-1 ] = (char)(sizeof ( CMD_NOSALE )); }
    {short ret; ret = (short)(sizeof ( CMD_NOSALE )); }
    {int tlv1; tlv1 = (int)(sizeof ( CMD_NOSALE )); }
    {void * tlv12; tlv12 = (void *)(sizeof ( CMD_NOSALE )); }
    {void * tlv11; tlv11 = (void *)(sizeof ( CMD_NOSALE )); }
    {unsigned int tlv10; tlv10 = (unsigned int)(sizeof ( CMD_NOSALE )); }
    {int tlv2; tlv2 = (int)(sizeof ( CMD_NOSALE )); }
    {void * tlv15; tlv15 = (void *)(sizeof ( CMD_NOSALE )); }
    {void * tlv14; tlv14 = (void *)(sizeof ( CMD_NOSALE )); }
    {unsigned int tlv13; tlv13 = (unsigned int)(sizeof ( CMD_NOSALE )); }
    {int tlv3; tlv3 = (int)(sizeof ( CMD_NOSALE )); }
    {void * tlv18; tlv18 = (void *)(sizeof ( CMD_NOSALE )); }
    {void * tlv17; tlv17 = (void *)(sizeof ( CMD_NOSALE )); }
    {unsigned int tlv16; tlv16 = (unsigned int)(sizeof ( CMD_NOSALE )); }
    {int tlv4; tlv4 = (int)(sizeof ( CMD_NOSALE )); }
    {void * tlv21; tlv21 = (void *)(sizeof ( CMD_NOSALE )); }
    {void * tlv20; tlv20 = (void *)(sizeof ( CMD_NOSALE )); }
    {unsigned int tlv19; tlv19 = (unsigned int)(sizeof ( CMD_NOSALE )); }
    {int tlv5; tlv5 = (int)(sizeof ( CMD_NOSALE )); }
    {void * tlv24; tlv24 = (void *)(sizeof ( CMD_NOSALE )); }
    {void * tlv23; tlv23 = (void *)(sizeof ( CMD_NOSALE )); }
    {unsigned int tlv22; tlv22 = (unsigned int)(sizeof ( CMD_NOSALE )); }
    {int tlv6; tlv6 = (int)(sizeof ( CMD_NOSALE )); }
    {void * tlv27; tlv27 = (void *)(sizeof ( CMD_NOSALE )); }
    {void * tlv26; tlv26 = (void *)(sizeof ( CMD_NOSALE )); }
    {unsigned int tlv25; tlv25 = (unsigned int)(sizeof ( CMD_NOSALE )); }
    {int tlv7; tlv7 = (int)(sizeof ( CMD_NOSALE )); }
    {void * tlv30; tlv30 = (void *)(sizeof ( CMD_NOSALE )); }
    {void * tlv29; tlv29 = (void *)(sizeof ( CMD_NOSALE )); }
    {unsigned int tlv28; tlv28 = (unsigned int)(sizeof ( CMD_NOSALE )); }
    {int tlv8; tlv8 = (int)(sizeof ( CMD_NOSALE )); }
    {void * tlv33; tlv33 = (void *)(sizeof ( CMD_NOSALE )); }
    {void * tlv32; tlv32 = (void *)(sizeof ( CMD_NOSALE )); }
    {unsigned int tlv31; tlv31 = (unsigned int)(sizeof ( CMD_NOSALE )); }
    {int tlv9; tlv9 = (int)(sizeof ( CMD_NOSALE )); }
    {void * tlv36; tlv36 = (void *)(sizeof ( CMD_NOSALE )); }
    {void * tlv35; tlv35 = (void *)(sizeof ( CMD_NOSALE )); }
    {unsigned int tlv34; tlv34 = (unsigned int)(sizeof ( CMD_NOSALE )); }
}
void fix_ingred_products_12_19(){
fix_ingred_products_12_19_0();
fix_ingred_products_12_19_2();
}
void fix_ingred_products_12_20_2(){
int tlv7;
    bzero(&tlv7,sizeof(int));
    {char cmd [ 4 ]; cmd [ ( 4 )-1 ] = (char)(tlv7); }
    {short ret; ret = (short)(tlv7); }
    {int tlv1; tlv1 = (int)(tlv7); }
    {void * tlv12; tlv12 = (void *)(tlv7); }
    {void * tlv11; tlv11 = (void *)(tlv7); }
    {unsigned int tlv10; tlv10 = (unsigned int)(tlv7); }
    {int tlv2; tlv2 = (int)(tlv7); }
    {void * tlv15; tlv15 = (void *)(tlv7); }
    {void * tlv14; tlv14 = (void *)(tlv7); }
    {unsigned int tlv13; tlv13 = (unsigned int)(tlv7); }
    {int tlv3; tlv3 = (int)(tlv7); }
    {void * tlv18; tlv18 = (void *)(tlv7); }
    {void * tlv17; tlv17 = (void *)(tlv7); }
    {unsigned int tlv16; tlv16 = (unsigned int)(tlv7); }
    {int tlv4; tlv4 = (int)(tlv7); }
    {void * tlv21; tlv21 = (void *)(tlv7); }
    {void * tlv20; tlv20 = (void *)(tlv7); }
    {unsigned int tlv19; tlv19 = (unsigned int)(tlv7); }
    {int tlv5; tlv5 = (int)(tlv7); }
    {void * tlv24; tlv24 = (void *)(tlv7); }
    {void * tlv23; tlv23 = (void *)(tlv7); }
    {unsigned int tlv22; tlv22 = (unsigned int)(tlv7); }
    {int tlv6; tlv6 = (int)(tlv7); }
    {void * tlv27; tlv27 = (void *)(tlv7); }
    {void * tlv26; tlv26 = (void *)(tlv7); }
    {unsigned int tlv25; tlv25 = (unsigned int)(tlv7); }
    {void * tlv30; tlv30 = (void *)(tlv7); }
    {void * tlv29; tlv29 = (void *)(tlv7); }
    {unsigned int tlv28; tlv28 = (unsigned int)(tlv7); }
    {int tlv8; tlv8 = (int)(tlv7); }
    {void * tlv33; tlv33 = (void *)(tlv7); }
    {void * tlv32; tlv32 = (void *)(tlv7); }
    {unsigned int tlv31; tlv31 = (unsigned int)(tlv7); }
    {int tlv9; tlv9 = (int)(tlv7); }
    {void * tlv36; tlv36 = (void *)(tlv7); }
    {void * tlv35; tlv35 = (void *)(tlv7); }
    {unsigned int tlv34; tlv34 = (unsigned int)(tlv7); }
}
void fix_ingred_products_12_20(){
fix_ingred_products_12_20_2();
}
void fix_ingred_products_12_22_0(){
    {char cmd [ 4 ]; cmd [ ( 4 )-1 ] = (char)(( void * ) CMD_LIST); }
    {short ret; ret = (short)(( void * ) CMD_LIST); }
    {int tlv1; tlv1 = (int)(( void * ) CMD_LIST); }
    {void * tlv12; tlv12 = (void *)(( void * ) CMD_LIST); }
    {void * tlv11; tlv11 = (void *)(( void * ) CMD_LIST); }
    {unsigned int tlv10; tlv10 = (unsigned int)(( void * ) CMD_LIST); }
    {int tlv2; tlv2 = (int)(( void * ) CMD_LIST); }
    {void * tlv15; tlv15 = (void *)(( void * ) CMD_LIST); }
    {void * tlv14; tlv14 = (void *)(( void * ) CMD_LIST); }
    {unsigned int tlv13; tlv13 = (unsigned int)(( void * ) CMD_LIST); }
    {int tlv3; tlv3 = (int)(( void * ) CMD_LIST); }
    {void * tlv18; tlv18 = (void *)(( void * ) CMD_LIST); }
    {void * tlv17; tlv17 = (void *)(( void * ) CMD_LIST); }
    {unsigned int tlv16; tlv16 = (unsigned int)(( void * ) CMD_LIST); }
    {int tlv4; tlv4 = (int)(( void * ) CMD_LIST); }
    {void * tlv21; tlv21 = (void *)(( void * ) CMD_LIST); }
    {void * tlv20; tlv20 = (void *)(( void * ) CMD_LIST); }
    {unsigned int tlv19; tlv19 = (unsigned int)(( void * ) CMD_LIST); }
    {int tlv5; tlv5 = (int)(( void * ) CMD_LIST); }
    {void * tlv24; tlv24 = (void *)(( void * ) CMD_LIST); }
    {void * tlv23; tlv23 = (void *)(( void * ) CMD_LIST); }
    {unsigned int tlv22; tlv22 = (unsigned int)(( void * ) CMD_LIST); }
    {int tlv6; tlv6 = (int)(( void * ) CMD_LIST); }
    {void * tlv27; tlv27 = (void *)(( void * ) CMD_LIST); }
    {void * tlv26; tlv26 = (void *)(( void * ) CMD_LIST); }
    {unsigned int tlv25; tlv25 = (unsigned int)(( void * ) CMD_LIST); }
    {int tlv7; tlv7 = (int)(( void * ) CMD_LIST); }
    {void * tlv30; tlv30 = (void *)(( void * ) CMD_LIST); }
    {void * tlv29; tlv29 = (void *)(( void * ) CMD_LIST); }
    {unsigned int tlv28; tlv28 = (unsigned int)(( void * ) CMD_LIST); }
    {int tlv8; tlv8 = (int)(( void * ) CMD_LIST); }
    {void * tlv33; tlv33 = (void *)(( void * ) CMD_LIST); }
    {void * tlv32; tlv32 = (void *)(( void * ) CMD_LIST); }
    {unsigned int tlv31; tlv31 = (unsigned int)(( void * ) CMD_LIST); }
    {int tlv9; tlv9 = (int)(( void * ) CMD_LIST); }
    {void * tlv36; tlv36 = (void *)(( void * ) CMD_LIST); }
    {void * tlv35; tlv35 = (void *)(( void * ) CMD_LIST); }
    {unsigned int tlv34; tlv34 = (unsigned int)(( void * ) CMD_LIST); }
}
void fix_ingred_products_12_22_2(){
    {char cmd [ 4 ]; cmd [ ( 4 )-1 ] = (char)(sizeof ( CMD_LIST )); }
    {short ret; ret = (short)(sizeof ( CMD_LIST )); }
    {int tlv1; tlv1 = (int)(sizeof ( CMD_LIST )); }
    {void * tlv12; tlv12 = (void *)(sizeof ( CMD_LIST )); }
    {void * tlv11; tlv11 = (void *)(sizeof ( CMD_LIST )); }
    {unsigned int tlv10; tlv10 = (unsigned int)(sizeof ( CMD_LIST )); }
    {int tlv2; tlv2 = (int)(sizeof ( CMD_LIST )); }
    {void * tlv15; tlv15 = (void *)(sizeof ( CMD_LIST )); }
    {void * tlv14; tlv14 = (void *)(sizeof ( CMD_LIST )); }
    {unsigned int tlv13; tlv13 = (unsigned int)(sizeof ( CMD_LIST )); }
    {int tlv3; tlv3 = (int)(sizeof ( CMD_LIST )); }
    {void * tlv18; tlv18 = (void *)(sizeof ( CMD_LIST )); }
    {void * tlv17; tlv17 = (void *)(sizeof ( CMD_LIST )); }
    {unsigned int tlv16; tlv16 = (unsigned int)(sizeof ( CMD_LIST )); }
    {int tlv4; tlv4 = (int)(sizeof ( CMD_LIST )); }
    {void * tlv21; tlv21 = (void *)(sizeof ( CMD_LIST )); }
    {void * tlv20; tlv20 = (void *)(sizeof ( CMD_LIST )); }
    {unsigned int tlv19; tlv19 = (unsigned int)(sizeof ( CMD_LIST )); }
    {int tlv5; tlv5 = (int)(sizeof ( CMD_LIST )); }
    {void * tlv24; tlv24 = (void *)(sizeof ( CMD_LIST )); }
    {void * tlv23; tlv23 = (void *)(sizeof ( CMD_LIST )); }
    {unsigned int tlv22; tlv22 = (unsigned int)(sizeof ( CMD_LIST )); }
    {int tlv6; tlv6 = (int)(sizeof ( CMD_LIST )); }
    {void * tlv27; tlv27 = (void *)(sizeof ( CMD_LIST )); }
    {void * tlv26; tlv26 = (void *)(sizeof ( CMD_LIST )); }
    {unsigned int tlv25; tlv25 = (unsigned int)(sizeof ( CMD_LIST )); }
    {int tlv7; tlv7 = (int)(sizeof ( CMD_LIST )); }
    {void * tlv30; tlv30 = (void *)(sizeof ( CMD_LIST )); }
    {void * tlv29; tlv29 = (void *)(sizeof ( CMD_LIST )); }
    {unsigned int tlv28; tlv28 = (unsigned int)(sizeof ( CMD_LIST )); }
    {int tlv8; tlv8 = (int)(sizeof ( CMD_LIST )); }
    {void * tlv33; tlv33 = (void *)(sizeof ( CMD_LIST )); }
    {void * tlv32; tlv32 = (void *)(sizeof ( CMD_LIST )); }
    {unsigned int tlv31; tlv31 = (unsigned int)(sizeof ( CMD_LIST )); }
    {int tlv9; tlv9 = (int)(sizeof ( CMD_LIST )); }
    {void * tlv36; tlv36 = (void *)(sizeof ( CMD_LIST )); }
    {void * tlv35; tlv35 = (void *)(sizeof ( CMD_LIST )); }
    {unsigned int tlv34; tlv34 = (unsigned int)(sizeof ( CMD_LIST )); }
}
void fix_ingred_products_12_22(){
fix_ingred_products_12_22_0();
fix_ingred_products_12_22_2();
}
void fix_ingred_products_12_23_2(){
int tlv8;
    bzero(&tlv8,sizeof(int));
    {char cmd [ 4 ]; cmd [ ( 4 )-1 ] = (char)(tlv8); }
    {short ret; ret = (short)(tlv8); }
    {int tlv1; tlv1 = (int)(tlv8); }
    {void * tlv12; tlv12 = (void *)(tlv8); }
    {void * tlv11; tlv11 = (void *)(tlv8); }
    {unsigned int tlv10; tlv10 = (unsigned int)(tlv8); }
    {int tlv2; tlv2 = (int)(tlv8); }
    {void * tlv15; tlv15 = (void *)(tlv8); }
    {void * tlv14; tlv14 = (void *)(tlv8); }
    {unsigned int tlv13; tlv13 = (unsigned int)(tlv8); }
    {int tlv3; tlv3 = (int)(tlv8); }
    {void * tlv18; tlv18 = (void *)(tlv8); }
    {void * tlv17; tlv17 = (void *)(tlv8); }
    {unsigned int tlv16; tlv16 = (unsigned int)(tlv8); }
    {int tlv4; tlv4 = (int)(tlv8); }
    {void * tlv21; tlv21 = (void *)(tlv8); }
    {void * tlv20; tlv20 = (void *)(tlv8); }
    {unsigned int tlv19; tlv19 = (unsigned int)(tlv8); }
    {int tlv5; tlv5 = (int)(tlv8); }
    {void * tlv24; tlv24 = (void *)(tlv8); }
    {void * tlv23; tlv23 = (void *)(tlv8); }
    {unsigned int tlv22; tlv22 = (unsigned int)(tlv8); }
    {int tlv6; tlv6 = (int)(tlv8); }
    {void * tlv27; tlv27 = (void *)(tlv8); }
    {void * tlv26; tlv26 = (void *)(tlv8); }
    {unsigned int tlv25; tlv25 = (unsigned int)(tlv8); }
    {int tlv7; tlv7 = (int)(tlv8); }
    {void * tlv30; tlv30 = (void *)(tlv8); }
    {void * tlv29; tlv29 = (void *)(tlv8); }
    {unsigned int tlv28; tlv28 = (unsigned int)(tlv8); }
    {void * tlv33; tlv33 = (void *)(tlv8); }
    {void * tlv32; tlv32 = (void *)(tlv8); }
    {unsigned int tlv31; tlv31 = (unsigned int)(tlv8); }
    {int tlv9; tlv9 = (int)(tlv8); }
    {void * tlv36; tlv36 = (void *)(tlv8); }
    {void * tlv35; tlv35 = (void *)(tlv8); }
    {unsigned int tlv34; tlv34 = (unsigned int)(tlv8); }
}
void fix_ingred_products_12_23(){
fix_ingred_products_12_23_2();
}
void fix_ingred_products_12_25_0(){
    {char cmd [ 4 ]; cmd [ ( 4 )-1 ] = (char)(( void * ) CMD_QUIT); }
    {short ret; ret = (short)(( void * ) CMD_QUIT); }
    {int tlv1; tlv1 = (int)(( void * ) CMD_QUIT); }
    {void * tlv12; tlv12 = (void *)(( void * ) CMD_QUIT); }
    {void * tlv11; tlv11 = (void *)(( void * ) CMD_QUIT); }
    {unsigned int tlv10; tlv10 = (unsigned int)(( void * ) CMD_QUIT); }
    {int tlv2; tlv2 = (int)(( void * ) CMD_QUIT); }
    {void * tlv15; tlv15 = (void *)(( void * ) CMD_QUIT); }
    {void * tlv14; tlv14 = (void *)(( void * ) CMD_QUIT); }
    {unsigned int tlv13; tlv13 = (unsigned int)(( void * ) CMD_QUIT); }
    {int tlv3; tlv3 = (int)(( void * ) CMD_QUIT); }
    {void * tlv18; tlv18 = (void *)(( void * ) CMD_QUIT); }
    {void * tlv17; tlv17 = (void *)(( void * ) CMD_QUIT); }
    {unsigned int tlv16; tlv16 = (unsigned int)(( void * ) CMD_QUIT); }
    {int tlv4; tlv4 = (int)(( void * ) CMD_QUIT); }
    {void * tlv21; tlv21 = (void *)(( void * ) CMD_QUIT); }
    {void * tlv20; tlv20 = (void *)(( void * ) CMD_QUIT); }
    {unsigned int tlv19; tlv19 = (unsigned int)(( void * ) CMD_QUIT); }
    {int tlv5; tlv5 = (int)(( void * ) CMD_QUIT); }
    {void * tlv24; tlv24 = (void *)(( void * ) CMD_QUIT); }
    {void * tlv23; tlv23 = (void *)(( void * ) CMD_QUIT); }
    {unsigned int tlv22; tlv22 = (unsigned int)(( void * ) CMD_QUIT); }
    {int tlv6; tlv6 = (int)(( void * ) CMD_QUIT); }
    {void * tlv27; tlv27 = (void *)(( void * ) CMD_QUIT); }
    {void * tlv26; tlv26 = (void *)(( void * ) CMD_QUIT); }
    {unsigned int tlv25; tlv25 = (unsigned int)(( void * ) CMD_QUIT); }
    {int tlv7; tlv7 = (int)(( void * ) CMD_QUIT); }
    {void * tlv30; tlv30 = (void *)(( void * ) CMD_QUIT); }
    {void * tlv29; tlv29 = (void *)(( void * ) CMD_QUIT); }
    {unsigned int tlv28; tlv28 = (unsigned int)(( void * ) CMD_QUIT); }
    {int tlv8; tlv8 = (int)(( void * ) CMD_QUIT); }
    {void * tlv33; tlv33 = (void *)(( void * ) CMD_QUIT); }
    {void * tlv32; tlv32 = (void *)(( void * ) CMD_QUIT); }
    {unsigned int tlv31; tlv31 = (unsigned int)(( void * ) CMD_QUIT); }
    {int tlv9; tlv9 = (int)(( void * ) CMD_QUIT); }
    {void * tlv36; tlv36 = (void *)(( void * ) CMD_QUIT); }
    {void * tlv35; tlv35 = (void *)(( void * ) CMD_QUIT); }
    {unsigned int tlv34; tlv34 = (unsigned int)(( void * ) CMD_QUIT); }
}
void fix_ingred_products_12_25_2(){
    {char cmd [ 4 ]; cmd [ ( 4 )-1 ] = (char)(sizeof ( CMD_QUIT )); }
    {short ret; ret = (short)(sizeof ( CMD_QUIT )); }
    {int tlv1; tlv1 = (int)(sizeof ( CMD_QUIT )); }
    {void * tlv12; tlv12 = (void *)(sizeof ( CMD_QUIT )); }
    {void * tlv11; tlv11 = (void *)(sizeof ( CMD_QUIT )); }
    {unsigned int tlv10; tlv10 = (unsigned int)(sizeof ( CMD_QUIT )); }
    {int tlv2; tlv2 = (int)(sizeof ( CMD_QUIT )); }
    {void * tlv15; tlv15 = (void *)(sizeof ( CMD_QUIT )); }
    {void * tlv14; tlv14 = (void *)(sizeof ( CMD_QUIT )); }
    {unsigned int tlv13; tlv13 = (unsigned int)(sizeof ( CMD_QUIT )); }
    {int tlv3; tlv3 = (int)(sizeof ( CMD_QUIT )); }
    {void * tlv18; tlv18 = (void *)(sizeof ( CMD_QUIT )); }
    {void * tlv17; tlv17 = (void *)(sizeof ( CMD_QUIT )); }
    {unsigned int tlv16; tlv16 = (unsigned int)(sizeof ( CMD_QUIT )); }
    {int tlv4; tlv4 = (int)(sizeof ( CMD_QUIT )); }
    {void * tlv21; tlv21 = (void *)(sizeof ( CMD_QUIT )); }
    {void * tlv20; tlv20 = (void *)(sizeof ( CMD_QUIT )); }
    {unsigned int tlv19; tlv19 = (unsigned int)(sizeof ( CMD_QUIT )); }
    {int tlv5; tlv5 = (int)(sizeof ( CMD_QUIT )); }
    {void * tlv24; tlv24 = (void *)(sizeof ( CMD_QUIT )); }
    {void * tlv23; tlv23 = (void *)(sizeof ( CMD_QUIT )); }
    {unsigned int tlv22; tlv22 = (unsigned int)(sizeof ( CMD_QUIT )); }
    {int tlv6; tlv6 = (int)(sizeof ( CMD_QUIT )); }
    {void * tlv27; tlv27 = (void *)(sizeof ( CMD_QUIT )); }
    {void * tlv26; tlv26 = (void *)(sizeof ( CMD_QUIT )); }
    {unsigned int tlv25; tlv25 = (unsigned int)(sizeof ( CMD_QUIT )); }
    {int tlv7; tlv7 = (int)(sizeof ( CMD_QUIT )); }
    {void * tlv30; tlv30 = (void *)(sizeof ( CMD_QUIT )); }
    {void * tlv29; tlv29 = (void *)(sizeof ( CMD_QUIT )); }
    {unsigned int tlv28; tlv28 = (unsigned int)(sizeof ( CMD_QUIT )); }
    {int tlv8; tlv8 = (int)(sizeof ( CMD_QUIT )); }
    {void * tlv33; tlv33 = (void *)(sizeof ( CMD_QUIT )); }
    {void * tlv32; tlv32 = (void *)(sizeof ( CMD_QUIT )); }
    {unsigned int tlv31; tlv31 = (unsigned int)(sizeof ( CMD_QUIT )); }
    {int tlv9; tlv9 = (int)(sizeof ( CMD_QUIT )); }
    {void * tlv36; tlv36 = (void *)(sizeof ( CMD_QUIT )); }
    {void * tlv35; tlv35 = (void *)(sizeof ( CMD_QUIT )); }
    {unsigned int tlv34; tlv34 = (unsigned int)(sizeof ( CMD_QUIT )); }
}
void fix_ingred_products_12_25(){
fix_ingred_products_12_25_0();
fix_ingred_products_12_25_2();
}
void fix_ingred_products_12_26_0(){
int tlv9;
    bzero(&tlv9,sizeof(int));
    {char cmd [ 4 ]; cmd [ ( 4 )-1 ] = (char)(- 2); }
    {short ret; ret = (short)(- 2); }
    {int tlv1; tlv1 = (int)(- 2); }
    {void * tlv12; tlv12 = (void *)(- 2); }
    {void * tlv11; tlv11 = (void *)(- 2); }
    {unsigned int tlv10; tlv10 = (unsigned int)(- 2); }
    {int tlv2; tlv2 = (int)(- 2); }
    {void * tlv15; tlv15 = (void *)(- 2); }
    {void * tlv14; tlv14 = (void *)(- 2); }
    {unsigned int tlv13; tlv13 = (unsigned int)(- 2); }
    {int tlv3; tlv3 = (int)(- 2); }
    {void * tlv18; tlv18 = (void *)(- 2); }
    {void * tlv17; tlv17 = (void *)(- 2); }
    {unsigned int tlv16; tlv16 = (unsigned int)(- 2); }
    {int tlv4; tlv4 = (int)(- 2); }
    {void * tlv21; tlv21 = (void *)(- 2); }
    {void * tlv20; tlv20 = (void *)(- 2); }
    {unsigned int tlv19; tlv19 = (unsigned int)(- 2); }
    {int tlv5; tlv5 = (int)(- 2); }
    {void * tlv24; tlv24 = (void *)(- 2); }
    {void * tlv23; tlv23 = (void *)(- 2); }
    {unsigned int tlv22; tlv22 = (unsigned int)(- 2); }
    {int tlv6; tlv6 = (int)(- 2); }
    {void * tlv27; tlv27 = (void *)(- 2); }
    {void * tlv26; tlv26 = (void *)(- 2); }
    {unsigned int tlv25; tlv25 = (unsigned int)(- 2); }
    {int tlv7; tlv7 = (int)(- 2); }
    {void * tlv30; tlv30 = (void *)(- 2); }
    {void * tlv29; tlv29 = (void *)(- 2); }
    {unsigned int tlv28; tlv28 = (unsigned int)(- 2); }
    {int tlv8; tlv8 = (int)(- 2); }
    {void * tlv33; tlv33 = (void *)(- 2); }
    {void * tlv32; tlv32 = (void *)(- 2); }
    {unsigned int tlv31; tlv31 = (unsigned int)(- 2); }
    {int tlv9; tlv9 = (int)(- 2); }
    {void * tlv36; tlv36 = (void *)(- 2); }
    {void * tlv35; tlv35 = (void *)(- 2); }
    {unsigned int tlv34; tlv34 = (unsigned int)(- 2); }
}
void fix_ingred_products_12_26_3(){
int tlv9;
    bzero(&tlv9,sizeof(int));
    {char cmd [ 4 ]; cmd [ ( 4 )-1 ] = (char)(tlv9); }
    {short ret; ret = (short)(tlv9); }
    {int tlv1; tlv1 = (int)(tlv9); }
    {void * tlv12; tlv12 = (void *)(tlv9); }
    {void * tlv11; tlv11 = (void *)(tlv9); }
    {unsigned int tlv10; tlv10 = (unsigned int)(tlv9); }
    {int tlv2; tlv2 = (int)(tlv9); }
    {void * tlv15; tlv15 = (void *)(tlv9); }
    {void * tlv14; tlv14 = (void *)(tlv9); }
    {unsigned int tlv13; tlv13 = (unsigned int)(tlv9); }
    {int tlv3; tlv3 = (int)(tlv9); }
    {void * tlv18; tlv18 = (void *)(tlv9); }
    {void * tlv17; tlv17 = (void *)(tlv9); }
    {unsigned int tlv16; tlv16 = (unsigned int)(tlv9); }
    {int tlv4; tlv4 = (int)(tlv9); }
    {void * tlv21; tlv21 = (void *)(tlv9); }
    {void * tlv20; tlv20 = (void *)(tlv9); }
    {unsigned int tlv19; tlv19 = (unsigned int)(tlv9); }
    {int tlv5; tlv5 = (int)(tlv9); }
    {void * tlv24; tlv24 = (void *)(tlv9); }
    {void * tlv23; tlv23 = (void *)(tlv9); }
    {unsigned int tlv22; tlv22 = (unsigned int)(tlv9); }
    {int tlv6; tlv6 = (int)(tlv9); }
    {void * tlv27; tlv27 = (void *)(tlv9); }
    {void * tlv26; tlv26 = (void *)(tlv9); }
    {unsigned int tlv25; tlv25 = (unsigned int)(tlv9); }
    {int tlv7; tlv7 = (int)(tlv9); }
    {void * tlv30; tlv30 = (void *)(tlv9); }
    {void * tlv29; tlv29 = (void *)(tlv9); }
    {unsigned int tlv28; tlv28 = (unsigned int)(tlv9); }
    {int tlv8; tlv8 = (int)(tlv9); }
    {void * tlv33; tlv33 = (void *)(tlv9); }
    {void * tlv32; tlv32 = (void *)(tlv9); }
    {unsigned int tlv31; tlv31 = (unsigned int)(tlv9); }
    {void * tlv36; tlv36 = (void *)(tlv9); }
    {void * tlv35; tlv35 = (void *)(tlv9); }
    {unsigned int tlv34; tlv34 = (unsigned int)(tlv9); }
}
void fix_ingred_products_12_26(){
fix_ingred_products_12_26_0();
fix_ingred_products_12_26_3();
}
void fix_ingred_products_12_27_0(){
    {char cmd [ 4 ]; cmd [ ( 4 )-1 ] = (char)(- 1); }
    {short ret; ret = (short)(- 1); }
    {int tlv1; tlv1 = (int)(- 1); }
    {void * tlv12; tlv12 = (void *)(- 1); }
    {void * tlv11; tlv11 = (void *)(- 1); }
    {unsigned int tlv10; tlv10 = (unsigned int)(- 1); }
    {int tlv2; tlv2 = (int)(- 1); }
    {void * tlv15; tlv15 = (void *)(- 1); }
    {void * tlv14; tlv14 = (void *)(- 1); }
    {unsigned int tlv13; tlv13 = (unsigned int)(- 1); }
    {int tlv3; tlv3 = (int)(- 1); }
    {void * tlv18; tlv18 = (void *)(- 1); }
    {void * tlv17; tlv17 = (void *)(- 1); }
    {unsigned int tlv16; tlv16 = (unsigned int)(- 1); }
    {int tlv4; tlv4 = (int)(- 1); }
    {void * tlv21; tlv21 = (void *)(- 1); }
    {void * tlv20; tlv20 = (void *)(- 1); }
    {unsigned int tlv19; tlv19 = (unsigned int)(- 1); }
    {int tlv5; tlv5 = (int)(- 1); }
    {void * tlv24; tlv24 = (void *)(- 1); }
    {void * tlv23; tlv23 = (void *)(- 1); }
    {unsigned int tlv22; tlv22 = (unsigned int)(- 1); }
    {int tlv6; tlv6 = (int)(- 1); }
    {void * tlv27; tlv27 = (void *)(- 1); }
    {void * tlv26; tlv26 = (void *)(- 1); }
    {unsigned int tlv25; tlv25 = (unsigned int)(- 1); }
    {int tlv7; tlv7 = (int)(- 1); }
    {void * tlv30; tlv30 = (void *)(- 1); }
    {void * tlv29; tlv29 = (void *)(- 1); }
    {unsigned int tlv28; tlv28 = (unsigned int)(- 1); }
    {int tlv8; tlv8 = (int)(- 1); }
    {void * tlv33; tlv33 = (void *)(- 1); }
    {void * tlv32; tlv32 = (void *)(- 1); }
    {unsigned int tlv31; tlv31 = (unsigned int)(- 1); }
    {int tlv9; tlv9 = (int)(- 1); }
    {void * tlv36; tlv36 = (void *)(- 1); }
    {void * tlv35; tlv35 = (void *)(- 1); }
    {unsigned int tlv34; tlv34 = (unsigned int)(- 1); }
}
void fix_ingred_products_12_27(){
fix_ingred_products_12_27_0();
}
void fix_ingred_products_12(){
fix_ingred_products_12_0();
fix_ingred_products_12_1();
fix_ingred_products_12_2();
fix_ingred_products_12_4();
fix_ingred_products_12_5();
fix_ingred_products_12_7();
fix_ingred_products_12_8();
fix_ingred_products_12_10();
fix_ingred_products_12_11();
fix_ingred_products_12_13();
fix_ingred_products_12_14();
fix_ingred_products_12_16();
fix_ingred_products_12_17();
fix_ingred_products_12_19();
fix_ingred_products_12_20();
fix_ingred_products_12_22();
fix_ingred_products_12_23();
fix_ingred_products_12_25();
fix_ingred_products_12_26();
fix_ingred_products_12_27();
}
