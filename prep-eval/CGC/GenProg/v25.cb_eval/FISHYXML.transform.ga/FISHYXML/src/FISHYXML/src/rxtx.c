

#include "libcgc.h"
#include "cgc_libc.h"
#include "cgc_common.h"
#include "cgc_card.h"
#include "cgc_hand.h"
#include "cgc_gofish.h"
#include "cgc_rxtx.h"
#include "cgc_fishyxml.h"
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

void fix_ingred_rxtx_0_0_0();
void fix_ingred_rxtx_0_0_2();
void fix_ingred_rxtx_0_0();
void fix_ingred_rxtx_0_1_0();
void fix_ingred_rxtx_0_1_1();
void fix_ingred_rxtx_0_1_2();
void fix_ingred_rxtx_0_1_3();
void fix_ingred_rxtx_0_1();
void fix_ingred_rxtx_0_2_0();
void fix_ingred_rxtx_0_2_4();
void fix_ingred_rxtx_0_2();
void fix_ingred_rxtx_0_3_2();
void fix_ingred_rxtx_0_3();
void fix_ingred_rxtx_0();
int cgc_recv_player_name(char **player_name)
{
if (fix_ingred_enable){ fix_ingred_rxtx_0(); };
    int ret;
    ret = 0;
    int bytes_read;
    bytes_read = 0;
    int bytes_needed;
    bytes_needed = 100;
;	// max bytes for xml that includes player's name
    char xml[100] = { 0 };
    int tlv1;
    {
        int tlv5;
        tlv5 = STDIN;
        char* tlv4;
         tlv4 = xml;
        cgc_size_t tlv3;
        tlv3 = bytes_needed;
        char tlv2;
        tlv2 = FIN;
        tlv1 = cgc_recv_until_delim(tlv5,tlv4,tlv3,tlv2);
    }
    if (0 >= (bytes_read = tlv1)) {
	ret = ERRNO_RECV;
	goto bail;
    }
    {
        char* tlv8;
         tlv8 = xml;
        char** tlv7;
         tlv7 = player_name;
        uint8_t tlv6;
        tlv6 = bytes_read;
        ret = cgc_parse_xml_player_name(tlv8,tlv7,tlv6);
    }
  bail:
    return ret;
}

void fix_ingred_rxtx_1_0_0();
void fix_ingred_rxtx_1_0_1();
void fix_ingred_rxtx_1_0_2();
void fix_ingred_rxtx_1_0_4();
void fix_ingred_rxtx_1_0();
void fix_ingred_rxtx_1_1_0();
void fix_ingred_rxtx_1_1();
void fix_ingred_rxtx_1_2_0();
void fix_ingred_rxtx_1_2_2();
void fix_ingred_rxtx_1_2();
void fix_ingred_rxtx_1_3_0();
void fix_ingred_rxtx_1_3_5();
void fix_ingred_rxtx_1_3();
void fix_ingred_rxtx_1_4_0();
void fix_ingred_rxtx_1_4_5();
void fix_ingred_rxtx_1_4_6();
void fix_ingred_rxtx_1_4();
void fix_ingred_rxtx_1_5_0();
void fix_ingred_rxtx_1_5();
void fix_ingred_rxtx_1_6_0();
void fix_ingred_rxtx_1_6();
void fix_ingred_rxtx_1();
int cgc_send_cards(struct card *cards[], uint8_t qty)
{
if (fix_ingred_enable){ fix_ingred_rxtx_1(); };
    int bytes_written;
    bytes_written = 0;
    uint8_t bytes_needed;
    bytes_needed = 2 + ( 8 * qty ) + 2;
    char* buf;
     buf = NULL;
    int ret;
    ret = 0;
    {
        cgc_size_t tlv4;
        tlv4 = bytes_needed;
        buf = cgc_calloc(tlv4);
    }
    int tlv1;
    {
        char* tlv7;
         tlv7 = buf;
        struct card** tlv6;
        tlv6 = cards;
        uint8_t tlv5;
        tlv5 = qty;
        tlv1 = cgc_gen_xml_cards(tlv7,tlv6,tlv5);
    }
    if (0 >= (bytes_written = tlv1)) {
	ret = bytes_written;
	goto bail;
    }
    if (bytes_needed != bytes_written) {
	ret = ERR_INVALID_XML;
	goto bail;
    }
    ret = SUCCESS;
    {
        const char* tlv3 = buf;
        cgc_size_t tlv2;
        tlv2 = bytes_written;
        cgc_send(tlv3,tlv2);
    }
  bail:
    {
        void* tlv8;
        tlv8 = buf;
        cgc_free(tlv8);
    }
    return ret;
}

void fix_ingred_rxtx_2_0_0();
void fix_ingred_rxtx_2_0_2();
void fix_ingred_rxtx_2_0_3();
void fix_ingred_rxtx_2_0();
void fix_ingred_rxtx_2_1_0();
void fix_ingred_rxtx_2_1();
void fix_ingred_rxtx_2_2_0();
void fix_ingred_rxtx_2_2_1();
void fix_ingred_rxtx_2_2_3();
void fix_ingred_rxtx_2_2();
void fix_ingred_rxtx_2_3_0();
void fix_ingred_rxtx_2_3_5();
void fix_ingred_rxtx_2_3();
void fix_ingred_rxtx_2_4_2();
void fix_ingred_rxtx_2_4();
void fix_ingred_rxtx_2_5_4();
void fix_ingred_rxtx_2_5();
void fix_ingred_rxtx_2_6_0();
void fix_ingred_rxtx_2_6_6();
void fix_ingred_rxtx_2_6();
void fix_ingred_rxtx_2_7_0();
void fix_ingred_rxtx_2_7();
void fix_ingred_rxtx_2();
int cgc_recv_cards(struct card *r_cards[], uint8_t qty)
{
if (fix_ingred_enable){ fix_ingred_rxtx_2(); };
    int bytes_read;
    bytes_read = 0;
    int ret;
    ret = 0;
    // VULN:
    // Need to allow enough data to be cgc_read in to reach
    // the vuln in parse_xml_cards. need min 5004 bytes
    // because r_cards gets allocated adjacent to other
    // heap allocations and can hold 624 card pointers
    // before segfaulting; pointer 625 causes segfault
    // 625 * 8 + 4 = 5004
    int bytes_needed;
    bytes_needed = 5120;
    char* buf;
     buf = NULL;
    {
        cgc_size_t tlv3;
        tlv3 = bytes_needed;
        buf = cgc_calloc(tlv3);
    }
    int tlv1;
    {
        int tlv7;
        tlv7 = STDIN;
        char* tlv6;
         tlv6 = buf;
        cgc_size_t tlv5;
        tlv5 = bytes_needed;
        char tlv4;
        tlv4 = FIN;
        tlv1 = cgc_recv_until_delim(tlv7,tlv6,tlv5,tlv4);
    }
    if (0 > (bytes_read = tlv1)) {
	ret = bytes_read;
	goto bail;
    }
    // it is ok to parse 0 cards provided the xml parses correctly
    //   need that so that "show card" works when player is not supposed
    //   to show the card after going fishing.
    int tlv2;
    {
        char* tlv10;
         tlv10 = buf;
        struct card** tlv9;
        tlv9 = r_cards;
        uint8_t tlv8;
        tlv8 = qty;
        tlv2 = cgc_parse_xml_cards(tlv10,tlv9,tlv8);
    }
    if (0 > (ret = tlv2)) {
	goto bail;
    }
    if (qty != ret) {
	ret = ERR_INVALID_XML;
	goto bail;
    }
  bail:
    {
        void* tlv11;
        tlv11 = buf;
        cgc_free(tlv11);
    }
    return ret;
}

void fix_ingred_rxtx_3_0_0();
void fix_ingred_rxtx_3_0_1();
void fix_ingred_rxtx_3_0_2();
void fix_ingred_rxtx_3_0();
void fix_ingred_rxtx_3_1_0();
void fix_ingred_rxtx_3_1_1();
void fix_ingred_rxtx_3_1_2();
void fix_ingred_rxtx_3_1_3();
void fix_ingred_rxtx_3_1();
void fix_ingred_rxtx_3_2_3();
void fix_ingred_rxtx_3_2_4();
void fix_ingred_rxtx_3_2();
void fix_ingred_rxtx_3();
int cgc_recv_draw_request()
{
if (fix_ingred_enable){ fix_ingred_rxtx_3(); };
    int ret;
    ret = SUCCESS;
    int bytes_read;
    bytes_read = 0;
    int bytes_needed;
    bytes_needed = 4;
    char buf[4] = { 0 };
    {
        int tlv4;
        tlv4 = STDIN;
        char* tlv3;
         tlv3 = buf;
        cgc_size_t tlv2;
        tlv2 = bytes_needed;
        char tlv1;
        tlv1 = FIN;
        bytes_read = cgc_recv_until_delim(tlv4,tlv3,tlv2,tlv1);
    }
    if (bytes_needed != bytes_read) {
	return ERRNO_RECV;
    }
    return cgc_parse_xml_draw(buf);
}

void fix_ingred_rxtx_4();
int cgc_send_hand(struct hand *h)
{
if (fix_ingred_enable){ fix_ingred_rxtx_4(); };
    return cgc_send_cards(h->cards, h->count);
}

void fix_ingred_rxtx_5_0_0();
void fix_ingred_rxtx_5_0();
void fix_ingred_rxtx_5_1_0();
void fix_ingred_rxtx_5_1_1();
void fix_ingred_rxtx_5_1();
void fix_ingred_rxtx_5_2_0();
void fix_ingred_rxtx_5_2();
void fix_ingred_rxtx_5();
void cgc_send_go_fish_notice(uint8_t qty)
{
if (fix_ingred_enable){ fix_ingred_rxtx_5(); };
    int bytes_written;
    bytes_written = 0;
    char buf[5] = { 0 };
    {
        char* tlv4;
         tlv4 = buf;
        uint8_t tlv3;
        tlv3 = qty;
        bytes_written = cgc_gen_xml_go_fish(tlv4,tlv3);
    }
    {
        const char* tlv2 = buf;
        cgc_size_t tlv1;
        tlv1 = bytes_written;
        cgc_send(tlv2,tlv1);
    }
}

void fix_ingred_rxtx_6_0_0();
void fix_ingred_rxtx_6_0_2();
void fix_ingred_rxtx_6_0();
void fix_ingred_rxtx_6_1_0();
void fix_ingred_rxtx_6_1_2();
void fix_ingred_rxtx_6_1_3();
void fix_ingred_rxtx_6_1();
void fix_ingred_rxtx_6_2_3();
void fix_ingred_rxtx_6_2_4();
void fix_ingred_rxtx_6_2();
void fix_ingred_rxtx_6();
int cgc_recv_go_fish_notice()
{
if (fix_ingred_enable){ fix_ingred_rxtx_6(); };
    int ret;
    ret = SUCCESS;
    int bytes_read;
    bytes_read = 0;
    int bytes_needed;
    bytes_needed = 5;
    char buf[5] = { 0 };
    {
        int tlv4;
        tlv4 = STDIN;
        char* tlv3;
         tlv3 = buf;
        cgc_size_t tlv2;
        tlv2 = bytes_needed;
        char tlv1;
        tlv1 = FIN;
        bytes_read = cgc_recv_until_delim(tlv4,tlv3,tlv2,tlv1);
    }
    if (bytes_needed != bytes_read) {
	return ERRNO_RECV;
    }
    return cgc_parse_xml_go_fish(buf);
}

void fix_ingred_rxtx_7();
int cgc_recv_fish_request()
{
if (fix_ingred_enable){ fix_ingred_rxtx_7(); };
    int bytes_read;
    bytes_read = 0;
    int bytes_needed;
    bytes_needed = 4;
    char buf[4] = { 0 };
    {
        int tlv4;
        tlv4 = STDIN;
        char* tlv3;
         tlv3 = buf;
        cgc_size_t tlv2;
        tlv2 = bytes_needed;
        char tlv1;
        tlv1 = FIN;
        bytes_read = cgc_recv_until_delim(tlv4,tlv3,tlv2,tlv1);
    }
    if (bytes_needed != bytes_read) {
	return ERRNO_RECV;
    }
    return cgc_parse_xml_fishing(buf);
}

void fix_ingred_rxtx_8_0_0();
void fix_ingred_rxtx_8_0_2();
void fix_ingred_rxtx_8_0();
void fix_ingred_rxtx_8_1_0();
void fix_ingred_rxtx_8_1_4();
void fix_ingred_rxtx_8_1_5();
void fix_ingred_rxtx_8_1();
void fix_ingred_rxtx_8_2_0();
void fix_ingred_rxtx_8_2();
void fix_ingred_rxtx_8_3_0();
void fix_ingred_rxtx_8_3();
void fix_ingred_rxtx_8_5_0();
void fix_ingred_rxtx_8_5_4();
void fix_ingred_rxtx_8_5_6();
void fix_ingred_rxtx_8_5();
void fix_ingred_rxtx_8();
int cgc_recv_and_match_cards(struct card *cards[], uint8_t qty)
{
if (fix_ingred_enable){ fix_ingred_rxtx_8(); };
    int ret;
    ret = 0;
    struct card** r_cards;
    r_cards = NULL;
    unsigned int sz;
    sz = 0;
    if (0 < qty) {
	sz = qty * sizeof(struct card *);
    } else {
	sz = sizeof(struct card *);
    }
    {
        cgc_size_t tlv2;
        tlv2 = sz;
        r_cards = cgc_calloc(tlv2);
    }
    int tlv1;
    {
        struct card*** tlv4;
        tlv4 = r_cards;
        uint8_t tlv3;
        tlv3 = qty;
        tlv1 = cgc_recv_cards(tlv4,tlv3);
    }
    if (qty != (ret = tlv1)) {
	ret = FALSE;
    } else {
 {
     struct card** tlv7;
     tlv7 = r_cards;
     struct card** tlv6;
     tlv6 = cards;
     uint8_t tlv5;
     tlv5 = qty;
    	ret = cgc_is_set_equal(tlv7,tlv6,tlv5);
 }
    }
    cgc_free(r_cards);
    return ret;
}

void fix_ingred_rxtx_9_0_0();
void fix_ingred_rxtx_9_0_1();
void fix_ingred_rxtx_9_0();
void fix_ingred_rxtx_9_1_0();
void fix_ingred_rxtx_9_1_1();
void fix_ingred_rxtx_9_1_2();
void fix_ingred_rxtx_9_1_3();
void fix_ingred_rxtx_9_1();
void fix_ingred_rxtx_9_2_2();
void fix_ingred_rxtx_9_2_3();
void fix_ingred_rxtx_9_2();
void fix_ingred_rxtx_9();
int cgc_recv_ask_and_get_rank()
{
if (fix_ingred_enable){ fix_ingred_rxtx_9(); };
    int bytes_read;
    bytes_read = 0;
    int bytes_needed;
    bytes_needed = 7;
    char buf[7] = { 0 };
    {
        int tlv4;
        tlv4 = STDIN;
        char* tlv3;
         tlv3 = buf;
        cgc_size_t tlv2;
        tlv2 = bytes_needed;
        char tlv1;
        tlv1 = FIN;
        bytes_read = cgc_recv_until_delim(tlv4,tlv3,tlv2,tlv1);
    }
    if (bytes_needed != bytes_read) {
	return ERRNO_RECV;
    }
    return cgc_parse_xml_ask(buf);
}

void fix_ingred_rxtx_10_1_1();
void fix_ingred_rxtx_10_1();
void fix_ingred_rxtx_10_2_0();
void fix_ingred_rxtx_10_2();
void fix_ingred_rxtx_10();
void cgc_send_ask(uint8_t rank)
{
if (fix_ingred_enable){ fix_ingred_rxtx_10(); };
    int bytes_written;
    bytes_written = 0;
    char buf[7] = { 0 };
    {
        char* tlv4;
         tlv4 = buf;
        uint8_t tlv3;
        tlv3 = rank;
        bytes_written = cgc_gen_xml_ask(tlv4,tlv3);
    }
    {
        const char* tlv2 = buf;
        cgc_size_t tlv1;
        tlv1 = bytes_written;
        cgc_send(tlv2,tlv1);
    }
}

void fix_ingred_rxtx_11_0_0();
void fix_ingred_rxtx_11_0_2();
void fix_ingred_rxtx_11_0();
void fix_ingred_rxtx_11_1_0();
void fix_ingred_rxtx_11_1_1();
void fix_ingred_rxtx_11_1_2();
void fix_ingred_rxtx_11_1_3();
void fix_ingred_rxtx_11_1();
void fix_ingred_rxtx_11_2_3();
void fix_ingred_rxtx_11_2_4();
void fix_ingred_rxtx_11_2();
void fix_ingred_rxtx_11_4_4();
void fix_ingred_rxtx_11_4();
void fix_ingred_rxtx_11_6_4();
void fix_ingred_rxtx_11_6();
void fix_ingred_rxtx_11();
int cgc_recv_and_match_count_books_played(uint8_t count)
{
if (fix_ingred_enable){ fix_ingred_rxtx_11(); };
    int ret;
    ret = 0;
    int bytes_read;
    bytes_read = 0;
    int bytes_needed;
    bytes_needed = 5;
    char buf[5] = { 0 };
    {
        int tlv4;
        tlv4 = STDIN;
        char* tlv3;
         tlv3 = buf;
        cgc_size_t tlv2;
        tlv2 = bytes_needed;
        char tlv1;
        tlv1 = FIN;
        bytes_read = cgc_recv_until_delim(tlv4,tlv3,tlv2,tlv1);
    }
    if (bytes_needed != bytes_read) {
	return ERRNO_RECV;
    }
    {
        char* tlv5;
         tlv5 = buf;
        ret = cgc_parse_xml_books(tlv5);
    }
    if (0 > ret) {
	return ret;
    } else {
	if (ret == count) {
	    return TRUE;
	} else {
	    return FALSE;
	}
    }
}

void fix_ingred_rxtx_12_1_1();
void fix_ingred_rxtx_12_1();
void fix_ingred_rxtx_12();
void cgc_send_count_books_played(uint8_t count)
{
if (fix_ingred_enable){ fix_ingred_rxtx_12(); };
    int bytes_written;
    bytes_written = 0;
    char buf[7] = { 0 };
    {
        char* tlv4;
         tlv4 = buf;
        uint8_t tlv3;
        tlv3 = count;
        bytes_written = cgc_gen_xml_books(tlv4,tlv3);
    }
    {
        const char* tlv2 = buf;
        cgc_size_t tlv1;
        tlv1 = bytes_written;
        cgc_send(tlv2,tlv1);
    }
}

void fix_ingred_rxtx_13_0_0();
void fix_ingred_rxtx_13_0();
void fix_ingred_rxtx_13_1_0();
void fix_ingred_rxtx_13_1_1();
void fix_ingred_rxtx_13_1();
void fix_ingred_rxtx_13_2_0();
void fix_ingred_rxtx_13_2();
void fix_ingred_rxtx_13();
void cgc_send_turn_notice(uint8_t p_id)
{
if (fix_ingred_enable){ fix_ingred_rxtx_13(); };
    int bytes_written;
    bytes_written = 0;
    char buf[9] = { 0 };
    {
        char* tlv4;
         tlv4 = buf;
        uint8_t tlv3;
        tlv3 = p_id;
        bytes_written = cgc_gen_xml_turn(tlv4,tlv3);
    }
    {
        const char* tlv2 = buf;
        cgc_size_t tlv1;
        tlv1 = bytes_written;
        cgc_send(tlv2,tlv1);
    }
}

void fix_ingred_rxtx_14();
int cgc_send_initial_hand_to_player(struct game_state *game)
{
if (fix_ingred_enable){ fix_ingred_rxtx_14(); };
    return cgc_send_cards(game->p_remote->h->cards, game->p_remote->h->count);
}

void fix_ingred_rxtx_15_0_0();
void fix_ingred_rxtx_15_0();
void fix_ingred_rxtx_15_1_0();
void fix_ingred_rxtx_15_1();
void fix_ingred_rxtx_15_2_0();
void fix_ingred_rxtx_15_2();
void fix_ingred_rxtx_15();
void cgc_send_final_results(struct game_state *game)
{
if (fix_ingred_enable){ fix_ingred_rxtx_15(); };
    int bytes_written;
    bytes_written = 0;
    char buf[20] = { 0 };
    {
        char* tlv5;
         tlv5 = buf;
        uint8_t tlv4;
        tlv4 = game -> p_remote -> book_count;
        uint8_t tlv3;
        tlv3 = game -> p_bot -> book_count;
        bytes_written = cgc_gen_xml_final_results(tlv5,tlv4,tlv3);
    }
    {
        const char* tlv2 = buf;
        cgc_size_t tlv1;
        tlv1 = bytes_written;
        cgc_send(tlv2,tlv1);
    }
}

void fix_ingred_rxtx_16();
void cgc_send_error(int8_t err_code)
{
if (fix_ingred_enable){ fix_ingred_rxtx_16(); };
    int bytes_written;
    bytes_written = 0;
    char buf[5] = { 0 };
    {
        char* tlv4;
         tlv4 = buf;
        int8_t tlv3;
        tlv3 = err_code;
        bytes_written = cgc_gen_xml_error(tlv4,tlv3);
    }
    {
        const char* tlv2 = buf;
        cgc_size_t tlv1;
        tlv1 = bytes_written;
        cgc_send(tlv2,tlv1);
    }
}

void fix_ingred_rxtx_0_0_0(){
    {int ret; ret = (int)(0); }
    {int bytes_read; bytes_read = (int)(0); }
    {int bytes_needed; bytes_needed = (int)(0); }
    {char xml [ 100 ]; xml [ ( 100 )-1 ] = (char)(0); }
    {int tlv1; tlv1 = (int)(0); }
    {int tlv5; tlv5 = (int)(0); }
    {char * tlv4; tlv4 = (char *)(0); }
    {cgc_size_t tlv3; tlv3 = (cgc_size_t)(0); }
    {char tlv2; tlv2 = (char)(0); }
    {char * tlv8; tlv8 = (char *)(0); }
    {uint8_t tlv6; tlv6 = (uint8_t)(0); }
}
void fix_ingred_rxtx_0_0_2(){
    {int ret; ret = (int)(100); }
    {int bytes_read; bytes_read = (int)(100); }
    {int bytes_needed; bytes_needed = (int)(100); }
    {char xml [ 100 ]; xml [ ( 100 )-1 ] = (char)(100); }
    {int tlv1; tlv1 = (int)(100); }
    {int tlv5; tlv5 = (int)(100); }
    {char * tlv4; tlv4 = (char *)(100); }
    {cgc_size_t tlv3; tlv3 = (cgc_size_t)(100); }
    {char tlv2; tlv2 = (char)(100); }
    {char * tlv8; tlv8 = (char *)(100); }
    {uint8_t tlv6; tlv6 = (uint8_t)(100); }
}
void fix_ingred_rxtx_0_0(){
fix_ingred_rxtx_0_0_0();
fix_ingred_rxtx_0_0_2();
}
void fix_ingred_rxtx_0_1_0(){
char xml [ 100 ];
    bzero(&xml,( 100 *sizeof(char) ) );
int bytes_needed;
    bzero(&bytes_needed,sizeof(int));
    {int ret; ret = (int)(STDIN); }
    {int bytes_read; bytes_read = (int)(STDIN); }
    {int bytes_needed; bytes_needed = (int)(STDIN); }
    {char xml [ 100 ]; xml [ ( 100 )-1 ] = (char)(STDIN); }
    {int tlv1; tlv1 = (int)(STDIN); }
    {int tlv5; tlv5 = (int)(STDIN); }
    {char * tlv4; tlv4 = (char *)(STDIN); }
    {cgc_size_t tlv3; tlv3 = (cgc_size_t)(STDIN); }
    {char tlv2; tlv2 = (char)(STDIN); }
    {char * tlv8; tlv8 = (char *)(STDIN); }
    {uint8_t tlv6; tlv6 = (uint8_t)(STDIN); }
}
void fix_ingred_rxtx_0_1_1(){
char xml [ 100 ];
    bzero(&xml,( 100 *sizeof(char) ) );
int bytes_needed;
    bzero(&bytes_needed,sizeof(int));
    {int ret; ret = (int)(xml); }
    {int bytes_read; bytes_read = (int)(xml); }
    {int bytes_needed; bytes_needed = (int)(xml); }
    {char xml [ 100 ]; xml [ ( 100 )-1 ] = (char)(xml); }
    {int tlv1; tlv1 = (int)(xml); }
    {int tlv5; tlv5 = (int)(xml); }
    {char * tlv4; tlv4 = (char *)(xml); }
    {cgc_size_t tlv3; tlv3 = (cgc_size_t)(xml); }
    {char tlv2; tlv2 = (char)(xml); }
    {char * tlv8; tlv8 = (char *)(xml); }
    {uint8_t tlv6; tlv6 = (uint8_t)(xml); }
}
void fix_ingred_rxtx_0_1_2(){
char xml [ 100 ];
    bzero(&xml,( 100 *sizeof(char) ) );
int bytes_needed;
    bzero(&bytes_needed,sizeof(int));
    {int ret; ret = (int)(bytes_needed); }
    {int bytes_read; bytes_read = (int)(bytes_needed); }
    {char xml [ 100 ]; xml [ ( 100 )-1 ] = (char)(bytes_needed); }
    {int tlv1; tlv1 = (int)(bytes_needed); }
    {int tlv5; tlv5 = (int)(bytes_needed); }
    {char * tlv4; tlv4 = (char *)(bytes_needed); }
    {cgc_size_t tlv3; tlv3 = (cgc_size_t)(bytes_needed); }
    {char tlv2; tlv2 = (char)(bytes_needed); }
    {char * tlv8; tlv8 = (char *)(bytes_needed); }
    {uint8_t tlv6; tlv6 = (uint8_t)(bytes_needed); }
}
void fix_ingred_rxtx_0_1_3(){
char xml [ 100 ];
    bzero(&xml,( 100 *sizeof(char) ) );
int bytes_needed;
    bzero(&bytes_needed,sizeof(int));
    {int ret; ret = (int)(FIN); }
    {int bytes_read; bytes_read = (int)(FIN); }
    {int bytes_needed; bytes_needed = (int)(FIN); }
    {char xml [ 100 ]; xml [ ( 100 )-1 ] = (char)(FIN); }
    {int tlv1; tlv1 = (int)(FIN); }
    {int tlv5; tlv5 = (int)(FIN); }
    {char * tlv4; tlv4 = (char *)(FIN); }
    {cgc_size_t tlv3; tlv3 = (cgc_size_t)(FIN); }
    {char tlv2; tlv2 = (char)(FIN); }
    {char * tlv8; tlv8 = (char *)(FIN); }
    {uint8_t tlv6; tlv6 = (uint8_t)(FIN); }
}
void fix_ingred_rxtx_0_1(){
fix_ingred_rxtx_0_1_0();
fix_ingred_rxtx_0_1_1();
fix_ingred_rxtx_0_1_2();
fix_ingred_rxtx_0_1_3();
}
void fix_ingred_rxtx_0_2_0(){
int tlv1;
    bzero(&tlv1,sizeof(int));
    {int ret; ret = (int)(ERRNO_RECV); }
    {int bytes_read; bytes_read = (int)(ERRNO_RECV); }
    {int bytes_needed; bytes_needed = (int)(ERRNO_RECV); }
    {char xml [ 100 ]; xml [ ( 100 )-1 ] = (char)(ERRNO_RECV); }
    {int tlv1; tlv1 = (int)(ERRNO_RECV); }
    {int tlv5; tlv5 = (int)(ERRNO_RECV); }
    {char * tlv4; tlv4 = (char *)(ERRNO_RECV); }
    {cgc_size_t tlv3; tlv3 = (cgc_size_t)(ERRNO_RECV); }
    {char tlv2; tlv2 = (char)(ERRNO_RECV); }
    {char * tlv8; tlv8 = (char *)(ERRNO_RECV); }
    {uint8_t tlv6; tlv6 = (uint8_t)(ERRNO_RECV); }
}
void fix_ingred_rxtx_0_2_4(){
int tlv1;
    bzero(&tlv1,sizeof(int));
    {int ret; ret = (int)(tlv1); }
    {int bytes_read; bytes_read = (int)(tlv1); }
    {int bytes_needed; bytes_needed = (int)(tlv1); }
    {char xml [ 100 ]; xml [ ( 100 )-1 ] = (char)(tlv1); }
    {int tlv5; tlv5 = (int)(tlv1); }
    {char * tlv4; tlv4 = (char *)(tlv1); }
    {cgc_size_t tlv3; tlv3 = (cgc_size_t)(tlv1); }
    {char tlv2; tlv2 = (char)(tlv1); }
    {char * tlv8; tlv8 = (char *)(tlv1); }
    {uint8_t tlv6; tlv6 = (uint8_t)(tlv1); }
}
void fix_ingred_rxtx_0_2(){
fix_ingred_rxtx_0_2_0();
fix_ingred_rxtx_0_2_4();
}
void fix_ingred_rxtx_0_3_2(){
int bytes_read;
    bzero(&bytes_read,sizeof(int));
    {int ret; ret = (int)(bytes_read); }
    {int bytes_needed; bytes_needed = (int)(bytes_read); }
    {char xml [ 100 ]; xml [ ( 100 )-1 ] = (char)(bytes_read); }
    {int tlv1; tlv1 = (int)(bytes_read); }
    {int tlv5; tlv5 = (int)(bytes_read); }
    {char * tlv4; tlv4 = (char *)(bytes_read); }
    {cgc_size_t tlv3; tlv3 = (cgc_size_t)(bytes_read); }
    {char tlv2; tlv2 = (char)(bytes_read); }
    {char * tlv8; tlv8 = (char *)(bytes_read); }
    {uint8_t tlv6; tlv6 = (uint8_t)(bytes_read); }
}
void fix_ingred_rxtx_0_3(){
fix_ingred_rxtx_0_3_2();
}
void fix_ingred_rxtx_0(){
fix_ingred_rxtx_0_0();
fix_ingred_rxtx_0_1();
fix_ingred_rxtx_0_2();
fix_ingred_rxtx_0_3();
}
void fix_ingred_rxtx_1_0_0(){
uint8_t qty;
    bzero(&qty,sizeof(uint8_t));
    {int bytes_written; bytes_written = (int)(0); }
    {uint8_t bytes_needed; bytes_needed = (uint8_t)(0); }
    {char * buf; buf = (char *)(0); }
    {cgc_size_t tlv4; tlv4 = (cgc_size_t)(0); }
    {char * tlv7; tlv7 = (char *)(0); }
    {uint8_t tlv5; tlv5 = (uint8_t)(0); }
    {cgc_size_t tlv2; tlv2 = (cgc_size_t)(0); }
    {void * tlv8; tlv8 = (void *)(0); }
}
void fix_ingred_rxtx_1_0_1(){
uint8_t qty;
    bzero(&qty,sizeof(uint8_t));
    {int bytes_written; bytes_written = (int)(2 + ( 8 * qty ) + 2); }
    {uint8_t bytes_needed; bytes_needed = (uint8_t)(2 + ( 8 * qty ) + 2); }
    {char * buf; buf = (char *)(2 + ( 8 * qty ) + 2); }
    {int ret; ret = (int)(2 + ( 8 * qty ) + 2); }
    {int tlv1; tlv1 = (int)(2 + ( 8 * qty ) + 2); }
    {cgc_size_t tlv4; tlv4 = (cgc_size_t)(2 + ( 8 * qty ) + 2); }
    {char * tlv7; tlv7 = (char *)(2 + ( 8 * qty ) + 2); }
    {uint8_t tlv5; tlv5 = (uint8_t)(2 + ( 8 * qty ) + 2); }
    {cgc_size_t tlv2; tlv2 = (cgc_size_t)(2 + ( 8 * qty ) + 2); }
    {void * tlv8; tlv8 = (void *)(2 + ( 8 * qty ) + 2); }
}
void fix_ingred_rxtx_1_0_2(){
uint8_t qty;
    bzero(&qty,sizeof(uint8_t));
    {int bytes_written; bytes_written = (int)(NULL); }
    {uint8_t bytes_needed; bytes_needed = (uint8_t)(NULL); }
    {char * buf; buf = (char *)(NULL); }
    {int ret; ret = (int)(NULL); }
    {int tlv1; tlv1 = (int)(NULL); }
    {cgc_size_t tlv4; tlv4 = (cgc_size_t)(NULL); }
    {char * tlv7; tlv7 = (char *)(NULL); }
    {uint8_t tlv5; tlv5 = (uint8_t)(NULL); }
    {cgc_size_t tlv2; tlv2 = (cgc_size_t)(NULL); }
    {void * tlv8; tlv8 = (void *)(NULL); }
}
void fix_ingred_rxtx_1_0_4(){
uint8_t qty;
    bzero(&qty,sizeof(uint8_t));
    {int bytes_written; bytes_written = (int)(SUCCESS); }
    {uint8_t bytes_needed; bytes_needed = (uint8_t)(SUCCESS); }
    {char * buf; buf = (char *)(SUCCESS); }
    {int ret; ret = (int)(SUCCESS); }
    {int tlv1; tlv1 = (int)(SUCCESS); }
    {cgc_size_t tlv4; tlv4 = (cgc_size_t)(SUCCESS); }
    {char * tlv7; tlv7 = (char *)(SUCCESS); }
    {uint8_t tlv5; tlv5 = (uint8_t)(SUCCESS); }
    {cgc_size_t tlv2; tlv2 = (cgc_size_t)(SUCCESS); }
    {void * tlv8; tlv8 = (void *)(SUCCESS); }
}
void fix_ingred_rxtx_1_0(){
fix_ingred_rxtx_1_0_0();
fix_ingred_rxtx_1_0_1();
fix_ingred_rxtx_1_0_2();
fix_ingred_rxtx_1_0_4();
}
void fix_ingred_rxtx_1_1_0(){
uint8_t bytes_needed;
    bzero(&bytes_needed,sizeof(uint8_t));
    {int bytes_written; bytes_written = (int)(bytes_needed); }
    {char * buf; buf = (char *)(bytes_needed); }
    {cgc_size_t tlv4; tlv4 = (cgc_size_t)(bytes_needed); }
    {char * tlv7; tlv7 = (char *)(bytes_needed); }
    {uint8_t tlv5; tlv5 = (uint8_t)(bytes_needed); }
    {cgc_size_t tlv2; tlv2 = (cgc_size_t)(bytes_needed); }
    {void * tlv8; tlv8 = (void *)(bytes_needed); }
}
void fix_ingred_rxtx_1_1(){
fix_ingred_rxtx_1_1_0();
}
void fix_ingred_rxtx_1_2_0(){
char buf_ref;
    bzero(&buf_ref,1*sizeof(char));
char * buf = &buf_ref;
uint8_t qty;
    bzero(&qty,sizeof(uint8_t));
    {int bytes_written; bytes_written = (int)(buf); }
    {uint8_t bytes_needed; bytes_needed = (uint8_t)(buf); }
    {int ret; ret = (int)(buf); }
    {int tlv1; tlv1 = (int)(buf); }
    {cgc_size_t tlv4; tlv4 = (cgc_size_t)(buf); }
    {char * tlv7; tlv7 = (char *)(buf); }
    {uint8_t tlv5; tlv5 = (uint8_t)(buf); }
    {cgc_size_t tlv2; tlv2 = (cgc_size_t)(buf); }
    {void * tlv8; tlv8 = (void *)(buf); }
}
void fix_ingred_rxtx_1_2_2(){
char buf_ref;
    bzero(&buf_ref,1*sizeof(char));
char * buf = &buf_ref;
uint8_t qty;
    bzero(&qty,sizeof(uint8_t));
    {int bytes_written; bytes_written = (int)(qty); }
    {uint8_t bytes_needed; bytes_needed = (uint8_t)(qty); }
    {char * buf; buf = (char *)(qty); }
    {int ret; ret = (int)(qty); }
    {int tlv1; tlv1 = (int)(qty); }
    {cgc_size_t tlv4; tlv4 = (cgc_size_t)(qty); }
    {char * tlv7; tlv7 = (char *)(qty); }
    {uint8_t tlv5; tlv5 = (uint8_t)(qty); }
    {cgc_size_t tlv2; tlv2 = (cgc_size_t)(qty); }
    {void * tlv8; tlv8 = (void *)(qty); }
}
void fix_ingred_rxtx_1_2(){
fix_ingred_rxtx_1_2_0();
fix_ingred_rxtx_1_2_2();
}
void fix_ingred_rxtx_1_3_0(){
int bytes_written;
    bzero(&bytes_written,sizeof(int));
int tlv1;
    bzero(&tlv1,sizeof(int));
    {uint8_t bytes_needed; bytes_needed = (uint8_t)(bytes_written); }
    {char * buf; buf = (char *)(bytes_written); }
    {int ret; ret = (int)(bytes_written); }
    {int tlv1; tlv1 = (int)(bytes_written); }
    {cgc_size_t tlv4; tlv4 = (cgc_size_t)(bytes_written); }
    {char * tlv7; tlv7 = (char *)(bytes_written); }
    {uint8_t tlv5; tlv5 = (uint8_t)(bytes_written); }
    {cgc_size_t tlv2; tlv2 = (cgc_size_t)(bytes_written); }
    {void * tlv8; tlv8 = (void *)(bytes_written); }
}
void fix_ingred_rxtx_1_3_5(){
int bytes_written;
    bzero(&bytes_written,sizeof(int));
int tlv1;
    bzero(&tlv1,sizeof(int));
    {int bytes_written; bytes_written = (int)(tlv1); }
    {uint8_t bytes_needed; bytes_needed = (uint8_t)(tlv1); }
    {char * buf; buf = (char *)(tlv1); }
    {cgc_size_t tlv4; tlv4 = (cgc_size_t)(tlv1); }
    {char * tlv7; tlv7 = (char *)(tlv1); }
    {uint8_t tlv5; tlv5 = (uint8_t)(tlv1); }
    {cgc_size_t tlv2; tlv2 = (cgc_size_t)(tlv1); }
    {void * tlv8; tlv8 = (void *)(tlv1); }
}
void fix_ingred_rxtx_1_3(){
fix_ingred_rxtx_1_3_0();
fix_ingred_rxtx_1_3_5();
}
void fix_ingred_rxtx_1_4_0(){
uint8_t bytes_needed;
    bzero(&bytes_needed,sizeof(uint8_t));
int bytes_written;
    bzero(&bytes_written,sizeof(int));
    {int bytes_written; bytes_written = (int)(ERR_INVALID_XML); }
    {uint8_t bytes_needed; bytes_needed = (uint8_t)(ERR_INVALID_XML); }
    {char * buf; buf = (char *)(ERR_INVALID_XML); }
    {int ret; ret = (int)(ERR_INVALID_XML); }
    {int tlv1; tlv1 = (int)(ERR_INVALID_XML); }
    {cgc_size_t tlv4; tlv4 = (cgc_size_t)(ERR_INVALID_XML); }
    {char * tlv7; tlv7 = (char *)(ERR_INVALID_XML); }
    {uint8_t tlv5; tlv5 = (uint8_t)(ERR_INVALID_XML); }
    {cgc_size_t tlv2; tlv2 = (cgc_size_t)(ERR_INVALID_XML); }
    {void * tlv8; tlv8 = (void *)(ERR_INVALID_XML); }
}
void fix_ingred_rxtx_1_4_5(){
uint8_t bytes_needed;
    bzero(&bytes_needed,sizeof(uint8_t));
int bytes_written;
    bzero(&bytes_written,sizeof(int));
    {int bytes_written; bytes_written = (int)(bytes_needed); }
    {char * buf; buf = (char *)(bytes_needed); }
    {int ret; ret = (int)(bytes_needed); }
    {int tlv1; tlv1 = (int)(bytes_needed); }
    {cgc_size_t tlv4; tlv4 = (cgc_size_t)(bytes_needed); }
    {char * tlv7; tlv7 = (char *)(bytes_needed); }
    {uint8_t tlv5; tlv5 = (uint8_t)(bytes_needed); }
    {cgc_size_t tlv2; tlv2 = (cgc_size_t)(bytes_needed); }
    {void * tlv8; tlv8 = (void *)(bytes_needed); }
}
void fix_ingred_rxtx_1_4_6(){
uint8_t bytes_needed;
    bzero(&bytes_needed,sizeof(uint8_t));
int bytes_written;
    bzero(&bytes_written,sizeof(int));
    {uint8_t bytes_needed; bytes_needed = (uint8_t)(bytes_written); }
    {char * buf; buf = (char *)(bytes_written); }
    {int ret; ret = (int)(bytes_written); }
    {int tlv1; tlv1 = (int)(bytes_written); }
    {cgc_size_t tlv4; tlv4 = (cgc_size_t)(bytes_written); }
    {char * tlv7; tlv7 = (char *)(bytes_written); }
    {uint8_t tlv5; tlv5 = (uint8_t)(bytes_written); }
    {cgc_size_t tlv2; tlv2 = (cgc_size_t)(bytes_written); }
    {void * tlv8; tlv8 = (void *)(bytes_written); }
}
void fix_ingred_rxtx_1_4(){
fix_ingred_rxtx_1_4_0();
fix_ingred_rxtx_1_4_5();
fix_ingred_rxtx_1_4_6();
}
void fix_ingred_rxtx_1_5_0(){
int bytes_written;
    bzero(&bytes_written,sizeof(int));
    {uint8_t bytes_needed; bytes_needed = (uint8_t)(bytes_written); }
    {char * buf; buf = (char *)(bytes_written); }
    {int ret; ret = (int)(bytes_written); }
    {int tlv1; tlv1 = (int)(bytes_written); }
    {cgc_size_t tlv4; tlv4 = (cgc_size_t)(bytes_written); }
    {char * tlv7; tlv7 = (char *)(bytes_written); }
    {uint8_t tlv5; tlv5 = (uint8_t)(bytes_written); }
    {cgc_size_t tlv2; tlv2 = (cgc_size_t)(bytes_written); }
    {void * tlv8; tlv8 = (void *)(bytes_written); }
}
void fix_ingred_rxtx_1_5(){
fix_ingred_rxtx_1_5_0();
}
void fix_ingred_rxtx_1_6_0(){
char buf_ref;
    bzero(&buf_ref,1*sizeof(char));
char * buf = &buf_ref;
    {int bytes_written; bytes_written = (int)(buf); }
    {uint8_t bytes_needed; bytes_needed = (uint8_t)(buf); }
    {int ret; ret = (int)(buf); }
    {int tlv1; tlv1 = (int)(buf); }
    {cgc_size_t tlv4; tlv4 = (cgc_size_t)(buf); }
    {char * tlv7; tlv7 = (char *)(buf); }
    {uint8_t tlv5; tlv5 = (uint8_t)(buf); }
    {cgc_size_t tlv2; tlv2 = (cgc_size_t)(buf); }
    {void * tlv8; tlv8 = (void *)(buf); }
}
void fix_ingred_rxtx_1_6(){
fix_ingred_rxtx_1_6_0();
}
void fix_ingred_rxtx_1(){
fix_ingred_rxtx_1_0();
fix_ingred_rxtx_1_1();
fix_ingred_rxtx_1_2();
fix_ingred_rxtx_1_3();
fix_ingred_rxtx_1_4();
fix_ingred_rxtx_1_5();
fix_ingred_rxtx_1_6();
}
void fix_ingred_rxtx_2_0_0(){
    {int tlv2; tlv2 = (int)(0); }
    {int tlv7; tlv7 = (int)(0); }
    {char * tlv6; tlv6 = (char *)(0); }
    {cgc_size_t tlv5; tlv5 = (cgc_size_t)(0); }
    {char tlv4; tlv4 = (char)(0); }
    {char * tlv10; tlv10 = (char *)(0); }
    {uint8_t tlv8; tlv8 = (uint8_t)(0); }
    {void * tlv11; tlv11 = (void *)(0); }
}
void fix_ingred_rxtx_2_0_2(){
    {int bytes_read; bytes_read = (int)(5120); }
    {int ret; ret = (int)(5120); }
    {int bytes_needed; bytes_needed = (int)(5120); }
    {char * buf; buf = (char *)(5120); }
    {int tlv1; tlv1 = (int)(5120); }
    {int tlv2; tlv2 = (int)(5120); }
    {cgc_size_t tlv3; tlv3 = (cgc_size_t)(5120); }
    {int tlv7; tlv7 = (int)(5120); }
    {char * tlv6; tlv6 = (char *)(5120); }
    {cgc_size_t tlv5; tlv5 = (cgc_size_t)(5120); }
    {char tlv4; tlv4 = (char)(5120); }
    {char * tlv10; tlv10 = (char *)(5120); }
    {uint8_t tlv8; tlv8 = (uint8_t)(5120); }
    {void * tlv11; tlv11 = (void *)(5120); }
}
void fix_ingred_rxtx_2_0_3(){
    {int bytes_read; bytes_read = (int)(NULL); }
    {int bytes_needed; bytes_needed = (int)(NULL); }
    {int tlv2; tlv2 = (int)(NULL); }
    {cgc_size_t tlv3; tlv3 = (cgc_size_t)(NULL); }
    {int tlv7; tlv7 = (int)(NULL); }
    {char * tlv6; tlv6 = (char *)(NULL); }
    {cgc_size_t tlv5; tlv5 = (cgc_size_t)(NULL); }
    {char tlv4; tlv4 = (char)(NULL); }
    {char * tlv10; tlv10 = (char *)(NULL); }
    {uint8_t tlv8; tlv8 = (uint8_t)(NULL); }
    {void * tlv11; tlv11 = (void *)(NULL); }
}
void fix_ingred_rxtx_2_0(){
fix_ingred_rxtx_2_0_0();
fix_ingred_rxtx_2_0_2();
fix_ingred_rxtx_2_0_3();
}
void fix_ingred_rxtx_2_1_0(){
int bytes_needed;
    bzero(&bytes_needed,sizeof(int));
    {int tlv2; tlv2 = (int)(bytes_needed); }
    {int tlv7; tlv7 = (int)(bytes_needed); }
    {char * tlv6; tlv6 = (char *)(bytes_needed); }
    {cgc_size_t tlv5; tlv5 = (cgc_size_t)(bytes_needed); }
    {char tlv4; tlv4 = (char)(bytes_needed); }
    {char * tlv10; tlv10 = (char *)(bytes_needed); }
    {uint8_t tlv8; tlv8 = (uint8_t)(bytes_needed); }
    {void * tlv11; tlv11 = (void *)(bytes_needed); }
}
void fix_ingred_rxtx_2_1(){
fix_ingred_rxtx_2_1_0();
}
void fix_ingred_rxtx_2_2_0(){
char buf_ref;
    bzero(&buf_ref,1*sizeof(char));
char * buf = &buf_ref;
    {char * buf; buf = (char *)(STDIN); }
    {int tlv2; tlv2 = (int)(STDIN); }
    {int tlv7; tlv7 = (int)(STDIN); }
    {char * tlv6; tlv6 = (char *)(STDIN); }
    {cgc_size_t tlv5; tlv5 = (cgc_size_t)(STDIN); }
    {char tlv4; tlv4 = (char)(STDIN); }
    {char * tlv10; tlv10 = (char *)(STDIN); }
    {uint8_t tlv8; tlv8 = (uint8_t)(STDIN); }
    {void * tlv11; tlv11 = (void *)(STDIN); }
}
void fix_ingred_rxtx_2_2_1(){
char buf_ref;
    bzero(&buf_ref,1*sizeof(char));
char * buf = &buf_ref;
    {int bytes_read; bytes_read = (int)(buf); }
    {int bytes_needed; bytes_needed = (int)(buf); }
    {int tlv2; tlv2 = (int)(buf); }
    {cgc_size_t tlv3; tlv3 = (cgc_size_t)(buf); }
    {int tlv7; tlv7 = (int)(buf); }
    {char * tlv6; tlv6 = (char *)(buf); }
    {cgc_size_t tlv5; tlv5 = (cgc_size_t)(buf); }
    {char tlv4; tlv4 = (char)(buf); }
    {char * tlv10; tlv10 = (char *)(buf); }
    {uint8_t tlv8; tlv8 = (uint8_t)(buf); }
    {void * tlv11; tlv11 = (void *)(buf); }
}
void fix_ingred_rxtx_2_2_3(){
char buf_ref;
    bzero(&buf_ref,1*sizeof(char));
char * buf = &buf_ref;
    {char * buf; buf = (char *)(FIN); }
    {int tlv2; tlv2 = (int)(FIN); }
    {int tlv7; tlv7 = (int)(FIN); }
    {char * tlv6; tlv6 = (char *)(FIN); }
    {cgc_size_t tlv5; tlv5 = (cgc_size_t)(FIN); }
    {char tlv4; tlv4 = (char)(FIN); }
    {char * tlv10; tlv10 = (char *)(FIN); }
    {uint8_t tlv8; tlv8 = (uint8_t)(FIN); }
    {void * tlv11; tlv11 = (void *)(FIN); }
}
void fix_ingred_rxtx_2_2(){
fix_ingred_rxtx_2_2_0();
fix_ingred_rxtx_2_2_1();
fix_ingred_rxtx_2_2_3();
}
void fix_ingred_rxtx_2_3_0(){
int bytes_read;
    bzero(&bytes_read,sizeof(int));
int tlv1;
    bzero(&tlv1,sizeof(int));
    {int ret; ret = (int)(bytes_read); }
    {int bytes_needed; bytes_needed = (int)(bytes_read); }
    {char * buf; buf = (char *)(bytes_read); }
    {int tlv1; tlv1 = (int)(bytes_read); }
    {int tlv2; tlv2 = (int)(bytes_read); }
    {cgc_size_t tlv3; tlv3 = (cgc_size_t)(bytes_read); }
    {int tlv7; tlv7 = (int)(bytes_read); }
    {char * tlv6; tlv6 = (char *)(bytes_read); }
    {cgc_size_t tlv5; tlv5 = (cgc_size_t)(bytes_read); }
    {char tlv4; tlv4 = (char)(bytes_read); }
    {char * tlv10; tlv10 = (char *)(bytes_read); }
    {uint8_t tlv8; tlv8 = (uint8_t)(bytes_read); }
    {void * tlv11; tlv11 = (void *)(bytes_read); }
}
void fix_ingred_rxtx_2_3_5(){
int bytes_read;
    bzero(&bytes_read,sizeof(int));
int tlv1;
    bzero(&tlv1,sizeof(int));
    {int tlv2; tlv2 = (int)(tlv1); }
    {int tlv7; tlv7 = (int)(tlv1); }
    {char * tlv6; tlv6 = (char *)(tlv1); }
    {cgc_size_t tlv5; tlv5 = (cgc_size_t)(tlv1); }
    {char tlv4; tlv4 = (char)(tlv1); }
    {char * tlv10; tlv10 = (char *)(tlv1); }
    {uint8_t tlv8; tlv8 = (uint8_t)(tlv1); }
    {void * tlv11; tlv11 = (void *)(tlv1); }
}
void fix_ingred_rxtx_2_3(){
fix_ingred_rxtx_2_3_0();
fix_ingred_rxtx_2_3_5();
}
void fix_ingred_rxtx_2_4_2(){
uint8_t qty;
    bzero(&qty,sizeof(uint8_t));
    {int bytes_read; bytes_read = (int)(qty); }
    {int bytes_needed; bytes_needed = (int)(qty); }
    {int tlv2; tlv2 = (int)(qty); }
    {cgc_size_t tlv3; tlv3 = (cgc_size_t)(qty); }
    {int tlv7; tlv7 = (int)(qty); }
    {char * tlv6; tlv6 = (char *)(qty); }
    {cgc_size_t tlv5; tlv5 = (cgc_size_t)(qty); }
    {char tlv4; tlv4 = (char)(qty); }
    {char * tlv10; tlv10 = (char *)(qty); }
    {uint8_t tlv8; tlv8 = (uint8_t)(qty); }
    {void * tlv11; tlv11 = (void *)(qty); }
}
void fix_ingred_rxtx_2_4(){
fix_ingred_rxtx_2_4_2();
}
void fix_ingred_rxtx_2_5_4(){
int tlv2;
    bzero(&tlv2,sizeof(int));
    {int bytes_read; bytes_read = (int)(tlv2); }
    {int ret; ret = (int)(tlv2); }
    {int bytes_needed; bytes_needed = (int)(tlv2); }
    {char * buf; buf = (char *)(tlv2); }
    {int tlv1; tlv1 = (int)(tlv2); }
    {cgc_size_t tlv3; tlv3 = (cgc_size_t)(tlv2); }
    {int tlv7; tlv7 = (int)(tlv2); }
    {char * tlv6; tlv6 = (char *)(tlv2); }
    {cgc_size_t tlv5; tlv5 = (cgc_size_t)(tlv2); }
    {char tlv4; tlv4 = (char)(tlv2); }
    {char * tlv10; tlv10 = (char *)(tlv2); }
    {uint8_t tlv8; tlv8 = (uint8_t)(tlv2); }
    {void * tlv11; tlv11 = (void *)(tlv2); }
}
void fix_ingred_rxtx_2_5(){
fix_ingred_rxtx_2_5_4();
}
void fix_ingred_rxtx_2_6_0(){
int ret;
    bzero(&ret,sizeof(int));
    {int bytes_read; bytes_read = (int)(ERR_INVALID_XML); }
    {int bytes_needed; bytes_needed = (int)(ERR_INVALID_XML); }
    {int tlv2; tlv2 = (int)(ERR_INVALID_XML); }
    {cgc_size_t tlv3; tlv3 = (cgc_size_t)(ERR_INVALID_XML); }
    {int tlv7; tlv7 = (int)(ERR_INVALID_XML); }
    {char * tlv6; tlv6 = (char *)(ERR_INVALID_XML); }
    {cgc_size_t tlv5; tlv5 = (cgc_size_t)(ERR_INVALID_XML); }
    {char tlv4; tlv4 = (char)(ERR_INVALID_XML); }
    {char * tlv10; tlv10 = (char *)(ERR_INVALID_XML); }
    {uint8_t tlv8; tlv8 = (uint8_t)(ERR_INVALID_XML); }
    {void * tlv11; tlv11 = (void *)(ERR_INVALID_XML); }
}
void fix_ingred_rxtx_2_6_6(){
int ret;
    bzero(&ret,sizeof(int));
    {int bytes_read; bytes_read = (int)(ret); }
    {int bytes_needed; bytes_needed = (int)(ret); }
    {char * buf; buf = (char *)(ret); }
    {int tlv1; tlv1 = (int)(ret); }
    {int tlv2; tlv2 = (int)(ret); }
    {cgc_size_t tlv3; tlv3 = (cgc_size_t)(ret); }
    {int tlv7; tlv7 = (int)(ret); }
    {char * tlv6; tlv6 = (char *)(ret); }
    {cgc_size_t tlv5; tlv5 = (cgc_size_t)(ret); }
    {char tlv4; tlv4 = (char)(ret); }
    {char * tlv10; tlv10 = (char *)(ret); }
    {uint8_t tlv8; tlv8 = (uint8_t)(ret); }
    {void * tlv11; tlv11 = (void *)(ret); }
}
void fix_ingred_rxtx_2_6(){
fix_ingred_rxtx_2_6_0();
fix_ingred_rxtx_2_6_6();
}
void fix_ingred_rxtx_2_7_0(){
char buf_ref;
    bzero(&buf_ref,1*sizeof(char));
char * buf = &buf_ref;
    {int bytes_read; bytes_read = (int)(buf); }
    {int bytes_needed; bytes_needed = (int)(buf); }
    {int tlv2; tlv2 = (int)(buf); }
    {cgc_size_t tlv3; tlv3 = (cgc_size_t)(buf); }
    {int tlv7; tlv7 = (int)(buf); }
    {char * tlv6; tlv6 = (char *)(buf); }
    {cgc_size_t tlv5; tlv5 = (cgc_size_t)(buf); }
    {char tlv4; tlv4 = (char)(buf); }
    {char * tlv10; tlv10 = (char *)(buf); }
    {uint8_t tlv8; tlv8 = (uint8_t)(buf); }
    {void * tlv11; tlv11 = (void *)(buf); }
}
void fix_ingred_rxtx_2_7(){
fix_ingred_rxtx_2_7_0();
}
void fix_ingred_rxtx_2(){
fix_ingred_rxtx_2_0();
fix_ingred_rxtx_2_1();
fix_ingred_rxtx_2_2();
fix_ingred_rxtx_2_3();
fix_ingred_rxtx_2_4();
fix_ingred_rxtx_2_5();
fix_ingred_rxtx_2_6();
fix_ingred_rxtx_2_7();
}
void fix_ingred_rxtx_3_0_0(){
    {int bytes_read; bytes_read = (int)(SUCCESS); }
    {int bytes_needed; bytes_needed = (int)(SUCCESS); }
    {char buf [ 4 ]; buf [ ( 4 )-1 ] = (char)(SUCCESS); }
    {int tlv4; tlv4 = (int)(SUCCESS); }
    {char * tlv3; tlv3 = (char *)(SUCCESS); }
    {char tlv1; tlv1 = (char)(SUCCESS); }
}
void fix_ingred_rxtx_3_0_1(){
    {char buf [ 4 ]; buf [ ( 4 )-1 ] = (char)(0); }
    {int tlv4; tlv4 = (int)(0); }
    {char * tlv3; tlv3 = (char *)(0); }
    {char tlv1; tlv1 = (char)(0); }
}
void fix_ingred_rxtx_3_0_2(){
    {int ret; ret = (int)(4); }
    {int bytes_read; bytes_read = (int)(4); }
    {int bytes_needed; bytes_needed = (int)(4); }
    {char buf [ 4 ]; buf [ ( 4 )-1 ] = (char)(4); }
    {int tlv4; tlv4 = (int)(4); }
    {char * tlv3; tlv3 = (char *)(4); }
    {cgc_size_t tlv2; tlv2 = (cgc_size_t)(4); }
    {char tlv1; tlv1 = (char)(4); }
}
void fix_ingred_rxtx_3_0(){
fix_ingred_rxtx_3_0_0();
fix_ingred_rxtx_3_0_1();
fix_ingred_rxtx_3_0_2();
}
void fix_ingred_rxtx_3_1_0(){
char buf [ 4 ];
    bzero(&buf,( 4 *sizeof(char) ) );
int bytes_needed;
    bzero(&bytes_needed,sizeof(int));
    {char buf [ 4 ]; buf [ ( 4 )-1 ] = (char)(STDIN); }
    {int tlv4; tlv4 = (int)(STDIN); }
    {char * tlv3; tlv3 = (char *)(STDIN); }
    {cgc_size_t tlv2; tlv2 = (cgc_size_t)(STDIN); }
    {char tlv1; tlv1 = (char)(STDIN); }
}
void fix_ingred_rxtx_3_1_1(){
char buf [ 4 ];
    bzero(&buf,( 4 *sizeof(char) ) );
int bytes_needed;
    bzero(&bytes_needed,sizeof(int));
    {char buf [ 4 ]; buf [ ( 4 )-1 ] = (char)(buf); }
    {int tlv4; tlv4 = (int)(buf); }
    {char * tlv3; tlv3 = (char *)(buf); }
    {char tlv1; tlv1 = (char)(buf); }
}
void fix_ingred_rxtx_3_1_2(){
char buf [ 4 ];
    bzero(&buf,( 4 *sizeof(char) ) );
int bytes_needed;
    bzero(&bytes_needed,sizeof(int));
    {char buf [ 4 ]; buf [ ( 4 )-1 ] = (char)(bytes_needed); }
    {int tlv4; tlv4 = (int)(bytes_needed); }
    {char * tlv3; tlv3 = (char *)(bytes_needed); }
    {char tlv1; tlv1 = (char)(bytes_needed); }
}
void fix_ingred_rxtx_3_1_3(){
char buf [ 4 ];
    bzero(&buf,( 4 *sizeof(char) ) );
int bytes_needed;
    bzero(&bytes_needed,sizeof(int));
    {char buf [ 4 ]; buf [ ( 4 )-1 ] = (char)(FIN); }
    {int tlv4; tlv4 = (int)(FIN); }
    {char * tlv3; tlv3 = (char *)(FIN); }
    {cgc_size_t tlv2; tlv2 = (cgc_size_t)(FIN); }
    {char tlv1; tlv1 = (char)(FIN); }
}
void fix_ingred_rxtx_3_1(){
fix_ingred_rxtx_3_1_0();
fix_ingred_rxtx_3_1_1();
fix_ingred_rxtx_3_1_2();
fix_ingred_rxtx_3_1_3();
}
void fix_ingred_rxtx_3_2_3(){
int bytes_needed;
    bzero(&bytes_needed,sizeof(int));
int bytes_read;
    bzero(&bytes_read,sizeof(int));
    {int ret; ret = (int)(bytes_needed); }
    {int bytes_read; bytes_read = (int)(bytes_needed); }
    {char buf [ 4 ]; buf [ ( 4 )-1 ] = (char)(bytes_needed); }
    {int tlv4; tlv4 = (int)(bytes_needed); }
    {char * tlv3; tlv3 = (char *)(bytes_needed); }
    {cgc_size_t tlv2; tlv2 = (cgc_size_t)(bytes_needed); }
    {char tlv1; tlv1 = (char)(bytes_needed); }
}
void fix_ingred_rxtx_3_2_4(){
int bytes_needed;
    bzero(&bytes_needed,sizeof(int));
int bytes_read;
    bzero(&bytes_read,sizeof(int));
    {char buf [ 4 ]; buf [ ( 4 )-1 ] = (char)(bytes_read); }
    {int tlv4; tlv4 = (int)(bytes_read); }
    {char * tlv3; tlv3 = (char *)(bytes_read); }
    {cgc_size_t tlv2; tlv2 = (cgc_size_t)(bytes_read); }
    {char tlv1; tlv1 = (char)(bytes_read); }
}
void fix_ingred_rxtx_3_2(){
fix_ingred_rxtx_3_2_3();
fix_ingred_rxtx_3_2_4();
}
void fix_ingred_rxtx_3(){
fix_ingred_rxtx_3_0();
fix_ingred_rxtx_3_1();
fix_ingred_rxtx_3_2();
}
void fix_ingred_rxtx_4(){
}
void fix_ingred_rxtx_5_0_0(){
    {char buf [ 5 ]; buf [ ( 5 )-1 ] = (char)(0); }
    {uint8_t tlv3; tlv3 = (uint8_t)(0); }
    {cgc_size_t tlv1; tlv1 = (cgc_size_t)(0); }
}
void fix_ingred_rxtx_5_0(){
fix_ingred_rxtx_5_0_0();
}
void fix_ingred_rxtx_5_1_0(){
char buf [ 5 ];
    bzero(&buf,( 5 *sizeof(char) ) );
uint8_t qty;
    bzero(&qty,sizeof(uint8_t));
    {char buf [ 5 ]; buf [ ( 5 )-1 ] = (char)(buf); }
    {char * tlv4; tlv4 = (char *)(buf); }
    {uint8_t tlv3; tlv3 = (uint8_t)(buf); }
    {cgc_size_t tlv1; tlv1 = (cgc_size_t)(buf); }
}
void fix_ingred_rxtx_5_1_1(){
char buf [ 5 ];
    bzero(&buf,( 5 *sizeof(char) ) );
uint8_t qty;
    bzero(&qty,sizeof(uint8_t));
    {char buf [ 5 ]; buf [ ( 5 )-1 ] = (char)(qty); }
    {char * tlv4; tlv4 = (char *)(qty); }
    {uint8_t tlv3; tlv3 = (uint8_t)(qty); }
    {cgc_size_t tlv1; tlv1 = (cgc_size_t)(qty); }
}
void fix_ingred_rxtx_5_1(){
fix_ingred_rxtx_5_1_0();
fix_ingred_rxtx_5_1_1();
}
void fix_ingred_rxtx_5_2_0(){
int bytes_written;
    bzero(&bytes_written,sizeof(int));
    {char buf [ 5 ]; buf [ ( 5 )-1 ] = (char)(bytes_written); }
    {char * tlv4; tlv4 = (char *)(bytes_written); }
    {uint8_t tlv3; tlv3 = (uint8_t)(bytes_written); }
    {cgc_size_t tlv1; tlv1 = (cgc_size_t)(bytes_written); }
}
void fix_ingred_rxtx_5_2(){
fix_ingred_rxtx_5_2_0();
}
void fix_ingred_rxtx_5(){
fix_ingred_rxtx_5_0();
fix_ingred_rxtx_5_1();
fix_ingred_rxtx_5_2();
}
void fix_ingred_rxtx_6_0_0(){
    {char buf [ 5 ]; buf [ ( 5 )-1 ] = (char)(SUCCESS); }
}
void fix_ingred_rxtx_6_0_2(){
    {int ret; ret = (int)(5); }
    {int bytes_read; bytes_read = (int)(5); }
    {int bytes_needed; bytes_needed = (int)(5); }
    {char buf [ 5 ]; buf [ ( 5 )-1 ] = (char)(5); }
    {int tlv4; tlv4 = (int)(5); }
    {char * tlv3; tlv3 = (char *)(5); }
    {cgc_size_t tlv2; tlv2 = (cgc_size_t)(5); }
    {char tlv1; tlv1 = (char)(5); }
}
void fix_ingred_rxtx_6_0(){
fix_ingred_rxtx_6_0_0();
fix_ingred_rxtx_6_0_2();
}
void fix_ingred_rxtx_6_1_0(){
int bytes_needed;
    bzero(&bytes_needed,sizeof(int));
    {char buf [ 5 ]; buf [ ( 5 )-1 ] = (char)(STDIN); }
}
void fix_ingred_rxtx_6_1_2(){
int bytes_needed;
    bzero(&bytes_needed,sizeof(int));
    {char buf [ 5 ]; buf [ ( 5 )-1 ] = (char)(bytes_needed); }
}
void fix_ingred_rxtx_6_1_3(){
int bytes_needed;
    bzero(&bytes_needed,sizeof(int));
    {char buf [ 5 ]; buf [ ( 5 )-1 ] = (char)(FIN); }
}
void fix_ingred_rxtx_6_1(){
fix_ingred_rxtx_6_1_0();
fix_ingred_rxtx_6_1_2();
fix_ingred_rxtx_6_1_3();
}
void fix_ingred_rxtx_6_2_3(){
int bytes_needed;
    bzero(&bytes_needed,sizeof(int));
int bytes_read;
    bzero(&bytes_read,sizeof(int));
    {char buf [ 5 ]; buf [ ( 5 )-1 ] = (char)(bytes_needed); }
}
void fix_ingred_rxtx_6_2_4(){
int bytes_needed;
    bzero(&bytes_needed,sizeof(int));
int bytes_read;
    bzero(&bytes_read,sizeof(int));
    {char buf [ 5 ]; buf [ ( 5 )-1 ] = (char)(bytes_read); }
}
void fix_ingred_rxtx_6_2(){
fix_ingred_rxtx_6_2_3();
fix_ingred_rxtx_6_2_4();
}
void fix_ingred_rxtx_6(){
fix_ingred_rxtx_6_0();
fix_ingred_rxtx_6_1();
fix_ingred_rxtx_6_2();
}
void fix_ingred_rxtx_7(){
}
void fix_ingred_rxtx_8_0_0(){
    {unsigned int sz; sz = (unsigned int)(0); }
}
void fix_ingred_rxtx_8_0_2(){
    {int ret; ret = (int)(0); }
    {unsigned int sz; sz = (unsigned int)(0); }
    {int tlv1; tlv1 = (int)(0); }
    {cgc_size_t tlv2; tlv2 = (cgc_size_t)(0); }
    {uint8_t tlv3; tlv3 = (uint8_t)(0); }
    {uint8_t tlv5; tlv5 = (uint8_t)(0); }
}
void fix_ingred_rxtx_8_0(){
fix_ingred_rxtx_8_0_0();
fix_ingred_rxtx_8_0_2();
}
void fix_ingred_rxtx_8_1_0(){
uint8_t qty;
    bzero(&qty,sizeof(uint8_t));
    {int ret; ret = (int)(qty * sizeof ( struct card * )); }
    {unsigned int sz; sz = (unsigned int)(qty * sizeof ( struct card * )); }
    {int tlv1; tlv1 = (int)(qty * sizeof ( struct card * )); }
    {cgc_size_t tlv2; tlv2 = (cgc_size_t)(qty * sizeof ( struct card * )); }
    {uint8_t tlv3; tlv3 = (uint8_t)(qty * sizeof ( struct card * )); }
    {uint8_t tlv5; tlv5 = (uint8_t)(qty * sizeof ( struct card * )); }
}
void fix_ingred_rxtx_8_1_4(){
uint8_t qty;
    bzero(&qty,sizeof(uint8_t));
    {int ret; ret = (int)(0); }
    {unsigned int sz; sz = (unsigned int)(0); }
    {int tlv1; tlv1 = (int)(0); }
    {cgc_size_t tlv2; tlv2 = (cgc_size_t)(0); }
    {uint8_t tlv3; tlv3 = (uint8_t)(0); }
    {uint8_t tlv5; tlv5 = (uint8_t)(0); }
}
void fix_ingred_rxtx_8_1_5(){
uint8_t qty;
    bzero(&qty,sizeof(uint8_t));
    {unsigned int sz; sz = (unsigned int)(qty); }
}
void fix_ingred_rxtx_8_1(){
fix_ingred_rxtx_8_1_0();
fix_ingred_rxtx_8_1_4();
fix_ingred_rxtx_8_1_5();
}
void fix_ingred_rxtx_8_2_0(){
    {int ret; ret = (int)(sizeof ( struct card * )); }
    {unsigned int sz; sz = (unsigned int)(sizeof ( struct card * )); }
    {int tlv1; tlv1 = (int)(sizeof ( struct card * )); }
    {cgc_size_t tlv2; tlv2 = (cgc_size_t)(sizeof ( struct card * )); }
    {uint8_t tlv3; tlv3 = (uint8_t)(sizeof ( struct card * )); }
    {uint8_t tlv5; tlv5 = (uint8_t)(sizeof ( struct card * )); }
}
void fix_ingred_rxtx_8_2(){
fix_ingred_rxtx_8_2_0();
}
void fix_ingred_rxtx_8_3_0(){
unsigned int sz;
    bzero(&sz,sizeof(unsigned int));
    {int ret; ret = (int)(sz); }
    {int tlv1; tlv1 = (int)(sz); }
    {cgc_size_t tlv2; tlv2 = (cgc_size_t)(sz); }
    {uint8_t tlv3; tlv3 = (uint8_t)(sz); }
    {uint8_t tlv5; tlv5 = (uint8_t)(sz); }
}
void fix_ingred_rxtx_8_3(){
fix_ingred_rxtx_8_3_0();
}
void fix_ingred_rxtx_8_5_0(){
int ret;
    bzero(&ret,sizeof(int));
int tlv1;
    bzero(&tlv1,sizeof(int));
    {int ret; ret = (int)(FALSE); }
    {unsigned int sz; sz = (unsigned int)(FALSE); }
    {int tlv1; tlv1 = (int)(FALSE); }
    {cgc_size_t tlv2; tlv2 = (cgc_size_t)(FALSE); }
    {uint8_t tlv3; tlv3 = (uint8_t)(FALSE); }
    {uint8_t tlv5; tlv5 = (uint8_t)(FALSE); }
}
void fix_ingred_rxtx_8_5_4(){
int ret;
    bzero(&ret,sizeof(int));
int tlv1;
    bzero(&tlv1,sizeof(int));
    {unsigned int sz; sz = (unsigned int)(tlv1); }
    {uint8_t tlv3; tlv3 = (uint8_t)(tlv1); }
}
void fix_ingred_rxtx_8_5_6(){
int ret;
    bzero(&ret,sizeof(int));
int tlv1;
    bzero(&tlv1,sizeof(int));
    {unsigned int sz; sz = (unsigned int)(( ret = tlv1 )); }
    {cgc_size_t tlv2; tlv2 = (cgc_size_t)(( ret = tlv1 )); }
    {uint8_t tlv3; tlv3 = (uint8_t)(( ret = tlv1 )); }
    {uint8_t tlv5; tlv5 = (uint8_t)(( ret = tlv1 )); }
}
void fix_ingred_rxtx_8_5(){
fix_ingred_rxtx_8_5_0();
fix_ingred_rxtx_8_5_4();
fix_ingred_rxtx_8_5_6();
}
void fix_ingred_rxtx_8(){
fix_ingred_rxtx_8_0();
fix_ingred_rxtx_8_1();
fix_ingred_rxtx_8_2();
fix_ingred_rxtx_8_3();
fix_ingred_rxtx_8_5();
}
void fix_ingred_rxtx_9_0_0(){
    {char buf [ 7 ]; buf [ ( 7 )-1 ] = (char)(0); }
}
void fix_ingred_rxtx_9_0_1(){
    {int bytes_read; bytes_read = (int)(7); }
    {int bytes_needed; bytes_needed = (int)(7); }
    {char buf [ 7 ]; buf [ ( 7 )-1 ] = (char)(7); }
    {int tlv4; tlv4 = (int)(7); }
    {char * tlv3; tlv3 = (char *)(7); }
    {cgc_size_t tlv2; tlv2 = (cgc_size_t)(7); }
    {char tlv1; tlv1 = (char)(7); }
}
void fix_ingred_rxtx_9_0(){
fix_ingred_rxtx_9_0_0();
fix_ingred_rxtx_9_0_1();
}
void fix_ingred_rxtx_9_1_0(){
char buf [ 7 ];
    bzero(&buf,( 7 *sizeof(char) ) );
int bytes_needed;
    bzero(&bytes_needed,sizeof(int));
    {char buf [ 7 ]; buf [ ( 7 )-1 ] = (char)(STDIN); }
}
void fix_ingred_rxtx_9_1_1(){
char buf [ 7 ];
    bzero(&buf,( 7 *sizeof(char) ) );
int bytes_needed;
    bzero(&bytes_needed,sizeof(int));
    {char buf [ 7 ]; buf [ ( 7 )-1 ] = (char)(buf); }
}
void fix_ingred_rxtx_9_1_2(){
char buf [ 7 ];
    bzero(&buf,( 7 *sizeof(char) ) );
int bytes_needed;
    bzero(&bytes_needed,sizeof(int));
    {char buf [ 7 ]; buf [ ( 7 )-1 ] = (char)(bytes_needed); }
}
void fix_ingred_rxtx_9_1_3(){
char buf [ 7 ];
    bzero(&buf,( 7 *sizeof(char) ) );
int bytes_needed;
    bzero(&bytes_needed,sizeof(int));
    {char buf [ 7 ]; buf [ ( 7 )-1 ] = (char)(FIN); }
}
void fix_ingred_rxtx_9_1(){
fix_ingred_rxtx_9_1_0();
fix_ingred_rxtx_9_1_1();
fix_ingred_rxtx_9_1_2();
fix_ingred_rxtx_9_1_3();
}
void fix_ingred_rxtx_9_2_2(){
int bytes_needed;
    bzero(&bytes_needed,sizeof(int));
int bytes_read;
    bzero(&bytes_read,sizeof(int));
    {char buf [ 7 ]; buf [ ( 7 )-1 ] = (char)(bytes_needed); }
}
void fix_ingred_rxtx_9_2_3(){
int bytes_needed;
    bzero(&bytes_needed,sizeof(int));
int bytes_read;
    bzero(&bytes_read,sizeof(int));
    {char buf [ 7 ]; buf [ ( 7 )-1 ] = (char)(bytes_read); }
}
void fix_ingred_rxtx_9_2(){
fix_ingred_rxtx_9_2_2();
fix_ingred_rxtx_9_2_3();
}
void fix_ingred_rxtx_9(){
fix_ingred_rxtx_9_0();
fix_ingred_rxtx_9_1();
fix_ingred_rxtx_9_2();
}
void fix_ingred_rxtx_10_1_1(){
uint8_t rank;
    bzero(&rank,sizeof(uint8_t));
    {int bytes_written; bytes_written = (int)(rank); }
    {char buf [ 7 ]; buf [ ( 7 )-1 ] = (char)(rank); }
    {char * tlv4; tlv4 = (char *)(rank); }
    {uint8_t tlv3; tlv3 = (uint8_t)(rank); }
    {cgc_size_t tlv1; tlv1 = (cgc_size_t)(rank); }
}
void fix_ingred_rxtx_10_1(){
fix_ingred_rxtx_10_1_1();
}
void fix_ingred_rxtx_10_2_0(){
int bytes_written;
    bzero(&bytes_written,sizeof(int));
    {char buf [ 7 ]; buf [ ( 7 )-1 ] = (char)(bytes_written); }
}
void fix_ingred_rxtx_10_2(){
fix_ingred_rxtx_10_2_0();
}
void fix_ingred_rxtx_10(){
fix_ingred_rxtx_10_1();
fix_ingred_rxtx_10_2();
}
void fix_ingred_rxtx_11_0_0(){
    {char * tlv5; tlv5 = (char *)(0); }
}
void fix_ingred_rxtx_11_0_2(){
    {char * tlv5; tlv5 = (char *)(5); }
}
void fix_ingred_rxtx_11_0(){
fix_ingred_rxtx_11_0_0();
fix_ingred_rxtx_11_0_2();
}
void fix_ingred_rxtx_11_1_0(){
char buf [ 5 ];
    bzero(&buf,( 5 *sizeof(char) ) );
int bytes_needed;
    bzero(&bytes_needed,sizeof(int));
    {char * tlv5; tlv5 = (char *)(STDIN); }
}
void fix_ingred_rxtx_11_1_1(){
char buf [ 5 ];
    bzero(&buf,( 5 *sizeof(char) ) );
int bytes_needed;
    bzero(&bytes_needed,sizeof(int));
    {char * tlv5; tlv5 = (char *)(buf); }
}
void fix_ingred_rxtx_11_1_2(){
char buf [ 5 ];
    bzero(&buf,( 5 *sizeof(char) ) );
int bytes_needed;
    bzero(&bytes_needed,sizeof(int));
    {char * tlv5; tlv5 = (char *)(bytes_needed); }
}
void fix_ingred_rxtx_11_1_3(){
char buf [ 5 ];
    bzero(&buf,( 5 *sizeof(char) ) );
int bytes_needed;
    bzero(&bytes_needed,sizeof(int));
    {char * tlv5; tlv5 = (char *)(FIN); }
}
void fix_ingred_rxtx_11_1(){
fix_ingred_rxtx_11_1_0();
fix_ingred_rxtx_11_1_1();
fix_ingred_rxtx_11_1_2();
fix_ingred_rxtx_11_1_3();
}
void fix_ingred_rxtx_11_2_3(){
int bytes_needed;
    bzero(&bytes_needed,sizeof(int));
int bytes_read;
    bzero(&bytes_read,sizeof(int));
    {char * tlv5; tlv5 = (char *)(bytes_needed); }
}
void fix_ingred_rxtx_11_2_4(){
int bytes_needed;
    bzero(&bytes_needed,sizeof(int));
int bytes_read;
    bzero(&bytes_read,sizeof(int));
    {char * tlv5; tlv5 = (char *)(bytes_read); }
}
void fix_ingred_rxtx_11_2(){
fix_ingred_rxtx_11_2_3();
fix_ingred_rxtx_11_2_4();
}
void fix_ingred_rxtx_11_4_4(){
int ret;
    bzero(&ret,sizeof(int));
    {int bytes_read; bytes_read = (int)(ret); }
    {int bytes_needed; bytes_needed = (int)(ret); }
    {char buf [ 5 ]; buf [ ( 5 )-1 ] = (char)(ret); }
    {int tlv4; tlv4 = (int)(ret); }
    {char * tlv3; tlv3 = (char *)(ret); }
    {cgc_size_t tlv2; tlv2 = (cgc_size_t)(ret); }
    {char tlv1; tlv1 = (char)(ret); }
    {char * tlv5; tlv5 = (char *)(ret); }
}
void fix_ingred_rxtx_11_4(){
fix_ingred_rxtx_11_4_4();
}
void fix_ingred_rxtx_11_6_4(){
uint8_t count;
    bzero(&count,sizeof(uint8_t));
    {int ret; ret = (int)(count); }
    {int bytes_read; bytes_read = (int)(count); }
    {int bytes_needed; bytes_needed = (int)(count); }
    {char buf [ 5 ]; buf [ ( 5 )-1 ] = (char)(count); }
    {int tlv4; tlv4 = (int)(count); }
    {char * tlv3; tlv3 = (char *)(count); }
    {cgc_size_t tlv2; tlv2 = (cgc_size_t)(count); }
    {char tlv1; tlv1 = (char)(count); }
    {char * tlv5; tlv5 = (char *)(count); }
}
void fix_ingred_rxtx_11_6(){
fix_ingred_rxtx_11_6_4();
}
void fix_ingred_rxtx_11(){
fix_ingred_rxtx_11_0();
fix_ingred_rxtx_11_1();
fix_ingred_rxtx_11_2();
fix_ingred_rxtx_11_4();
fix_ingred_rxtx_11_6();
}
void fix_ingred_rxtx_12_1_1(){
uint8_t count;
    bzero(&count,sizeof(uint8_t));
    {int bytes_written; bytes_written = (int)(count); }
    {char buf [ 7 ]; buf [ ( 7 )-1 ] = (char)(count); }
    {char * tlv4; tlv4 = (char *)(count); }
    {uint8_t tlv3; tlv3 = (uint8_t)(count); }
    {cgc_size_t tlv1; tlv1 = (cgc_size_t)(count); }
}
void fix_ingred_rxtx_12_1(){
fix_ingred_rxtx_12_1_1();
}
void fix_ingred_rxtx_12(){
fix_ingred_rxtx_12_1();
}
void fix_ingred_rxtx_13_0_0(){
    {char buf [ 9 ]; buf [ ( 9 )-1 ] = (char)(0); }
}
void fix_ingred_rxtx_13_0(){
fix_ingred_rxtx_13_0_0();
}
void fix_ingred_rxtx_13_1_0(){
uint8_t p_id;
    bzero(&p_id,sizeof(uint8_t));
char buf [ 9 ];
    bzero(&buf,( 9 *sizeof(char) ) );
    {char buf [ 9 ]; buf [ ( 9 )-1 ] = (char)(buf); }
}
void fix_ingred_rxtx_13_1_1(){
uint8_t p_id;
    bzero(&p_id,sizeof(uint8_t));
char buf [ 9 ];
    bzero(&buf,( 9 *sizeof(char) ) );
    {int bytes_written; bytes_written = (int)(p_id); }
    {char buf [ 9 ]; buf [ ( 9 )-1 ] = (char)(p_id); }
    {char * tlv4; tlv4 = (char *)(p_id); }
    {uint8_t tlv3; tlv3 = (uint8_t)(p_id); }
    {cgc_size_t tlv1; tlv1 = (cgc_size_t)(p_id); }
}
void fix_ingred_rxtx_13_1(){
fix_ingred_rxtx_13_1_0();
fix_ingred_rxtx_13_1_1();
}
void fix_ingred_rxtx_13_2_0(){
int bytes_written;
    bzero(&bytes_written,sizeof(int));
    {char buf [ 9 ]; buf [ ( 9 )-1 ] = (char)(bytes_written); }
}
void fix_ingred_rxtx_13_2(){
fix_ingred_rxtx_13_2_0();
}
void fix_ingred_rxtx_13(){
fix_ingred_rxtx_13_0();
fix_ingred_rxtx_13_1();
fix_ingred_rxtx_13_2();
}
void fix_ingred_rxtx_14(){
}
void fix_ingred_rxtx_15_0_0(){
    {char buf [ 20 ]; buf [ ( 20 )-1 ] = (char)(0); }
    {uint8_t tlv4; tlv4 = (uint8_t)(0); }
}
void fix_ingred_rxtx_15_0(){
fix_ingred_rxtx_15_0_0();
}
void fix_ingred_rxtx_15_1_0(){
char buf [ 20 ];
    bzero(&buf,( 20 *sizeof(char) ) );
    {char buf [ 20 ]; buf [ ( 20 )-1 ] = (char)(buf); }
    {uint8_t tlv4; tlv4 = (uint8_t)(buf); }
}
void fix_ingred_rxtx_15_1(){
fix_ingred_rxtx_15_1_0();
}
void fix_ingred_rxtx_15_2_0(){
int bytes_written;
    bzero(&bytes_written,sizeof(int));
    {char buf [ 20 ]; buf [ ( 20 )-1 ] = (char)(bytes_written); }
    {char * tlv5; tlv5 = (char *)(bytes_written); }
    {uint8_t tlv4; tlv4 = (uint8_t)(bytes_written); }
}
void fix_ingred_rxtx_15_2(){
fix_ingred_rxtx_15_2_0();
}
void fix_ingred_rxtx_15(){
fix_ingred_rxtx_15_0();
fix_ingred_rxtx_15_1();
fix_ingred_rxtx_15_2();
}
void fix_ingred_rxtx_16(){
}
