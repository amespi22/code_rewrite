

#include "libcgc.h"
#include "cgc_libc.h"
#include "cgc_common.h"
#include "cgc_card.h"
#include "cgc_hand.h"
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

void fix_ingred_fishyxml_0_0_0();
void fix_ingred_fishyxml_0_0_2();
void fix_ingred_fishyxml_0_0_4();
void fix_ingred_fishyxml_0_0();
void fix_ingred_fishyxml_0_1_5();
void fix_ingred_fishyxml_0_1_6();
void fix_ingred_fishyxml_0_1();
void fix_ingred_fishyxml_0_2_0();
void fix_ingred_fishyxml_0_2_1();
void fix_ingred_fishyxml_0_2_7();
void fix_ingred_fishyxml_0_2();
void fix_ingred_fishyxml_0_3_9();
void fix_ingred_fishyxml_0_3();
void fix_ingred_fishyxml_0_5_7();
void fix_ingred_fishyxml_0_5();
void fix_ingred_fishyxml_0_8_9();
void fix_ingred_fishyxml_0_8();
void fix_ingred_fishyxml_0_11_9();
void fix_ingred_fishyxml_0_11();
void fix_ingred_fishyxml_0_15_0();
void fix_ingred_fishyxml_0_15_1();
void fix_ingred_fishyxml_0_15();
void fix_ingred_fishyxml_0();
int cgc_parse_xml_card(char *xml, struct card *cards[])
{
if (fix_ingred_enable){ fix_ingred_fishyxml_0(); };
    int have_rank;
    have_rank = FALSE;
    int have_suit;
    have_suit = FALSE;
    uint8_t rank;
    rank = 0;
    uint8_t suit;
    suit = 0;
    uint8_t chars_read;
    chars_read = 8;
    if (CARD != *xml) {
	return ERR_INVALID_XML;
    }
    xml++;
    if (RANK == *xml) {
	have_rank = TRUE;
	xml++;
	rank = *xml;
	xml++;
	if (END != *xml) {
	    return ERR_INVALID_XML;
	}
	xml++;
    } else {
	if (SUIT == *xml) {
	    have_suit = TRUE;
	    xml++;
	    suit = *xml;
	    xml++;
	    if (END != *xml) {
		return ERR_INVALID_XML;
	    }
	    xml++;
	} else {
	    return ERR_INVALID_XML;
	}
    }
    if ((RANK == *xml) && (FALSE == have_rank)) {
	xml++;
	rank = *xml;
	xml++;
	if (END != *xml) {
	    return ERR_INVALID_XML;
	}
	xml++;
    } else {
	if ((SUIT == *xml) && (FALSE == have_suit)) {
	    xml++;
	    suit = *xml;
	    xml++;
	    if (END != *xml) {
		return ERR_INVALID_XML;
	    }
	    xml++;
	} else {
	    return ERR_INVALID_XML;
	}
    }
    if (END != *xml) {
	return ERR_INVALID_XML;
    }
    {
        uint8_t tlv2;
        tlv2 = suit;
        uint8_t tlv1;
        tlv1 = rank;
        cards[0] = cgc_create_card(tlv2,tlv1);
    }
    if (NULL == cards[0]) {
	return ERR_INVALID_CARD;
    }
    return chars_read;
}

void fix_ingred_fishyxml_1_0_0();
void fix_ingred_fishyxml_1_0();
void fix_ingred_fishyxml_1();
uint8_t cgc_gen_xml_card(char *xml, struct card * c)
{
if (fix_ingred_enable){ fix_ingred_fishyxml_1(); };
    uint8_t bytes_written;
    bytes_written = 0;
    xml[bytes_written++] = CARD;
    xml[bytes_written++] = SUIT;
    xml[bytes_written++] = c->suit;
    xml[bytes_written++] = END;
    xml[bytes_written++] = RANK;
    xml[bytes_written++] = c->rank;
    xml[bytes_written++] = END;
    xml[bytes_written++] = END;
    return bytes_written;
}

void fix_ingred_fishyxml_2_0_0();
void fix_ingred_fishyxml_2_0_1();
void fix_ingred_fishyxml_2_0();
void fix_ingred_fishyxml_2_1_0();
void fix_ingred_fishyxml_2_1_1();
void fix_ingred_fishyxml_2_1();
void fix_ingred_fishyxml_2_2_0();
void fix_ingred_fishyxml_2_2_1();
void fix_ingred_fishyxml_2_2_2();
void fix_ingred_fishyxml_2_2_3();
void fix_ingred_fishyxml_2_2_4();
void fix_ingred_fishyxml_2_2_5();
void fix_ingred_fishyxml_2_2_6();
void fix_ingred_fishyxml_2_2_7();
void fix_ingred_fishyxml_2_2();
void fix_ingred_fishyxml_2_3_0();
void fix_ingred_fishyxml_2_3();
void fix_ingred_fishyxml_2_4_0();
void fix_ingred_fishyxml_2_4();
void fix_ingred_fishyxml_2_5_3();
void fix_ingred_fishyxml_2_5_9();
void fix_ingred_fishyxml_2_5();
void fix_ingred_fishyxml_2();
int cgc_parse_xml_player_name(char *xml, char **player_name, uint8_t len)
{
if (fix_ingred_enable){ fix_ingred_fishyxml_2(); };
    // xml[0] = START;
    // xml[1] = GAME;
    // xml[2] = PLAYER;
    // xml[3] = NAME;
    // xml[4 thru n - 5] = player_name;
    // xml[n - 4] = END;
    // xml[n - 3] = END;
    // xml[n - 2] = END;
    // xml[n - 1] = FIN;
    if (8 >= len) {
	return ERR_INVALID_XML;
    }
    if ((START != xml[0]) || (GAME != xml[1]) || (PLAYER != xml[2]) || (NAME != xml[3])) {
	return ERR_INVALID_XML;
    }
    char* name;
     name = NULL;
    uint8_t name_len;
    name_len = len - 8;
    {
        cgc_size_t tlv4;
        tlv4 = name_len;
        name = cgc_calloc(tlv4);
    }
    {
        char* tlv3;
         tlv3 = name;
        const char* tlv2 = & xml [ 4 ];
        cgc_size_t tlv1;
        tlv1 = name_len;
        cgc_strncpy(tlv3,tlv2,tlv1);
    }
    *player_name = name;
    if ((END != xml[len - 4]) || (END != xml[len - 3]) || (END != xml[len - 2]) || (FIN != xml[len - 1])) {
	return ERR_INVALID_XML;
    }
    return SUCCESS;
}

void fix_ingred_fishyxml_3_0_0();
void fix_ingred_fishyxml_3_0_1();
void fix_ingred_fishyxml_3_0();
void fix_ingred_fishyxml_3_1_3();
void fix_ingred_fishyxml_3_1_4();
void fix_ingred_fishyxml_3_1();
void fix_ingred_fishyxml_3_2_3();
void fix_ingred_fishyxml_3_2();
void fix_ingred_fishyxml_3_3_0();
void fix_ingred_fishyxml_3_3_5();
void fix_ingred_fishyxml_3_3();
void fix_ingred_fishyxml_3_4_0();
void fix_ingred_fishyxml_3_4();
void fix_ingred_fishyxml_3_5_6();
void fix_ingred_fishyxml_3_5();
void fix_ingred_fishyxml_3_7_3();
void fix_ingred_fishyxml_3_7();
void fix_ingred_fishyxml_3();
int cgc_parse_xml_cards(char *xml, struct card *cards[], uint8_t qty)
{
if (fix_ingred_enable){ fix_ingred_fishyxml_3(); };
    char* idx;
     idx = xml;
    int count;
    count = 0;
    int ret;
    ret = 0;
    struct card *card[1] = { 0 };
    if (START != *idx) {
	return ERR_INVALID_XML;
    }
    idx++;
    if (CARDS != *idx) {
	return ERR_INVALID_XML;
    }
    idx++;
    // VULN: not checking against expected qty or any upper bound, 
    //              so could send too many cards and overrun cards[] array.
    while (END != *idx) {
 {
     char* tlv2;
      tlv2 = idx;
     struct card*** tlv1;
     tlv1 = card;
    	ret = cgc_parse_xml_card(tlv2,tlv1);
 }
	if (0 > ret) {
	    return ret;
	}
	idx += ret;
	cards[count] = card[0];
	count++;
    }
    if (END != *idx) {
	return ERR_INVALID_XML;
    }
    idx++;
    if (FIN != *idx) {
	return ERR_INVALID_XML;
    }
    idx++;
    return count;
}

void fix_ingred_fishyxml_4_0_0();
void fix_ingred_fishyxml_4_0_2();
void fix_ingred_fishyxml_4_0();
void fix_ingred_fishyxml_4_1_6();
void fix_ingred_fishyxml_4_1_7();
void fix_ingred_fishyxml_4_1_8();
void fix_ingred_fishyxml_4_1();
void fix_ingred_fishyxml_4_2_0();
void fix_ingred_fishyxml_4_2();
void fix_ingred_fishyxml_4();
int cgc_gen_xml_cards(char *xml, struct card *cards[], uint8_t qty)
{
if (fix_ingred_enable){ fix_ingred_fishyxml_4(); };
    uint8_t bytes_written;
    bytes_written = 0;
    uint8_t cards_written;
    cards_written = 0;
    uint8_t bytes_needed;
    bytes_needed = 2 + ( qty * 8 ) + 2;
    xml[bytes_written++] = START;
    xml[bytes_written++] = CARDS;
    while ((0 < qty) && (bytes_needed > (bytes_written + 2))) {
 {
     char* tlv2;
      tlv2 = & xml [ bytes_written ];
     struct card* tlv1;
     tlv1 = cards [ cards_written ++ ];
    	bytes_written += cgc_gen_xml_card(tlv2,tlv1);
 }
    }
    xml[bytes_written++] = END;
    xml[bytes_written++] = FIN;
    return bytes_written;
}

void fix_ingred_fishyxml_5();
int cgc_parse_xml_draw(char *xml)
{
if (fix_ingred_enable){ fix_ingred_fishyxml_5(); };
    if ((START != xml[0]) || (DRAW != xml[1]) || (END != xml[2]) || (FIN != xml[3])) {
	return ERR_INVALID_XML;
    }
    return SUCCESS;
}

void fix_ingred_fishyxml_6();
int cgc_parse_xml_go_fish(char *xml)
{
if (fix_ingred_enable){ fix_ingred_fishyxml_6(); };
    if ((START != xml[0]) || (GO_FISH != xml[1]) || (END != xml[3]) || (FIN != xml[4])) {
	return ERR_INVALID_XML;
    }
    return xml[2];
}

void fix_ingred_fishyxml_7();
int cgc_gen_xml_go_fish(char *xml, uint8_t qty)
{
if (fix_ingred_enable){ fix_ingred_fishyxml_7(); };
    // alloc(5, xml);
    xml[0] = START;
    xml[1] = GO_FISH;
    xml[2] = qty;
    xml[3] = END;
    xml[4] = FIN;
    return 5;
}

void fix_ingred_fishyxml_8_1_0();
void fix_ingred_fishyxml_8_1_1();
void fix_ingred_fishyxml_8_1_2();
void fix_ingred_fishyxml_8_1_3();
void fix_ingred_fishyxml_8_1_4();
void fix_ingred_fishyxml_8_1_5();
void fix_ingred_fishyxml_8_1();
void fix_ingred_fishyxml_8_2_0();
void fix_ingred_fishyxml_8_2();
void fix_ingred_fishyxml_8_3_1();
void fix_ingred_fishyxml_8_3_2();
void fix_ingred_fishyxml_8_3();
void fix_ingred_fishyxml_8_4_1();
void fix_ingred_fishyxml_8_4_2();
void fix_ingred_fishyxml_8_4_4();
void fix_ingred_fishyxml_8_4_5();
void fix_ingred_fishyxml_8_4_6();
void fix_ingred_fishyxml_8_4();
void fix_ingred_fishyxml_8();
int cgc_parse_xml_ask(char *xml)
{
if (fix_ingred_enable){ fix_ingred_fishyxml_8(); };
    if ((START != xml[0]) || (ASK != xml[1]) || (RANK != xml[2])) {
	return ERR_INVALID_XML;
    }
    int8_t rank;
    rank = ( int8_t ) xml [ 3 ];
    int tlv1;
    {
        uint8_t tlv2;
        tlv2 = rank;
        tlv1 = cgc_is_valid_rank(tlv2);
    }
    if (FALSE == tlv1) {
	return ERR_INVALID_RANK;
    }
    if ((END != xml[4]) || (END != xml[5]) || (FIN != xml[6])) {
	return ERR_INVALID_XML;
    }
    return rank;
}

void fix_ingred_fishyxml_9();
int cgc_gen_xml_ask(char *xml, uint8_t rank)
{
if (fix_ingred_enable){ fix_ingred_fishyxml_9(); };
    // alloc(7, xml);
    xml[0] = START;
    xml[1] = ASK;
    xml[2] = RANK;
    xml[3] = rank;
    xml[4] = END;
    xml[5] = END;
    xml[6] = FIN;
    return 7;
}

void fix_ingred_fishyxml_10();
int cgc_parse_xml_fishing(char *xml)
{
if (fix_ingred_enable){ fix_ingred_fishyxml_10(); };
    if ((START != xml[0]) || (FISHING != xml[1]) || (END != xml[2]) || (FIN != xml[3])) {
	return ERR_INVALID_XML;
    }
    return SUCCESS;
}

void fix_ingred_fishyxml_11_0_0();
void fix_ingred_fishyxml_11_0();
void fix_ingred_fishyxml_11_1_0();
void fix_ingred_fishyxml_11_1_1();
void fix_ingred_fishyxml_11_1_2();
void fix_ingred_fishyxml_11_1_3();
void fix_ingred_fishyxml_11_1();
void fix_ingred_fishyxml_11_2_1();
void fix_ingred_fishyxml_11_2_2();
void fix_ingred_fishyxml_11_2_3();
void fix_ingred_fishyxml_11_2_4();
void fix_ingred_fishyxml_11_2();
void fix_ingred_fishyxml_11();
int cgc_parse_xml_books(char *xml)
{
if (fix_ingred_enable){ fix_ingred_fishyxml_11(); };
    if ((START != xml[0]) || (BOOKS != xml[1])) {
	return ERR_INVALID_XML;
    }
    uint8_t books;
    books = ( uint8_t ) xml [ 2 ];
    if ((END != xml[3]) || (FIN != xml[4])) {
	return ERR_INVALID_XML;
    }
    return books;
}

void fix_ingred_fishyxml_12();
int cgc_gen_xml_books(char *xml, uint8_t count)
{
if (fix_ingred_enable){ fix_ingred_fishyxml_12(); };
    // alloc(5, xml);
    xml[0] = START;
    xml[1] = BOOKS;
    xml[2] = count;
    xml[3] = END;
    xml[4] = FIN;
    return 5;
}

void fix_ingred_fishyxml_13();
int cgc_gen_xml_turn(char *xml, uint8_t player_id)
{
if (fix_ingred_enable){ fix_ingred_fishyxml_13(); };
    // alloc(9, xml);
    xml[0] = START;
    xml[1] = TURN;
    xml[2] = PLAYER;
    xml[3] = ID;
    xml[4] = player_id;
    xml[5] = END;
    xml[6] = END;
    xml[7] = END;
    xml[8] = FIN;
    return 9;
}

void fix_ingred_fishyxml_14();
int cgc_gen_xml_final_results(char *xml, uint8_t p0_books, uint8_t p1_books)
{
if (fix_ingred_enable){ fix_ingred_fishyxml_14(); };
    // alloc(20, xml);
    xml[0] = START;
    xml[1] = GAME;
    xml[2] = PLAYER;
    xml[3] = ID;
    xml[4] = (uint8_t) 0;
    xml[5] = END;
    xml[6] = BOOKS;
    xml[7] = p0_books;
    xml[8] = END;
    xml[9] = END;
    xml[10] = PLAYER;
    xml[11] = ID;
    xml[12] = (uint8_t) 1;
    xml[13] = END;
    xml[14] = BOOKS;
    xml[15] = p1_books;
    xml[16] = END;
    xml[17] = END;
    xml[18] = END;
    xml[19] = FIN;
    return 20;
}

void fix_ingred_fishyxml_15();
int cgc_gen_xml_error(char *xml, int8_t err_code)
{
if (fix_ingred_enable){ fix_ingred_fishyxml_15(); };
    // alloc(5, xml);
    xml[0] = START;
    xml[1] = ERROR;
    xml[2] = err_code;
    xml[3] = END;
    xml[4] = FIN;
    return 5;
}

void fix_ingred_fishyxml_0_0_0(){
    {int have_rank; have_rank = (int)(FALSE); }
    {int have_suit; have_suit = (int)(FALSE); }
    {uint8_t rank; rank = (uint8_t)(FALSE); }
    {uint8_t suit; suit = (uint8_t)(FALSE); }
    {uint8_t chars_read; chars_read = (uint8_t)(FALSE); }
    {uint8_t tlv2; tlv2 = (uint8_t)(FALSE); }
    {uint8_t tlv1; tlv1 = (uint8_t)(FALSE); }
}
void fix_ingred_fishyxml_0_0_2(){
    {int have_rank; have_rank = (int)(0); }
    {int have_suit; have_suit = (int)(0); }
    {uint8_t rank; rank = (uint8_t)(0); }
    {uint8_t suit; suit = (uint8_t)(0); }
    {uint8_t chars_read; chars_read = (uint8_t)(0); }
    {uint8_t tlv2; tlv2 = (uint8_t)(0); }
    {uint8_t tlv1; tlv1 = (uint8_t)(0); }
}
void fix_ingred_fishyxml_0_0_4(){
    {int have_rank; have_rank = (int)(8); }
    {int have_suit; have_suit = (int)(8); }
    {uint8_t rank; rank = (uint8_t)(8); }
    {uint8_t suit; suit = (uint8_t)(8); }
    {uint8_t chars_read; chars_read = (uint8_t)(8); }
    {uint8_t tlv2; tlv2 = (uint8_t)(8); }
    {uint8_t tlv1; tlv1 = (uint8_t)(8); }
}
void fix_ingred_fishyxml_0_0(){
fix_ingred_fishyxml_0_0_0();
fix_ingred_fishyxml_0_0_2();
fix_ingred_fishyxml_0_0_4();
}
void fix_ingred_fishyxml_0_1_5(){
char xml_ref;
    bzero(&xml_ref,1*sizeof(char));
char * xml = &xml_ref;
    {int have_rank; have_rank = (int)(CARD); }
    {int have_suit; have_suit = (int)(CARD); }
    {uint8_t rank; rank = (uint8_t)(CARD); }
    {uint8_t suit; suit = (uint8_t)(CARD); }
    {uint8_t chars_read; chars_read = (uint8_t)(CARD); }
    {uint8_t tlv2; tlv2 = (uint8_t)(CARD); }
    {uint8_t tlv1; tlv1 = (uint8_t)(CARD); }
}
void fix_ingred_fishyxml_0_1_6(){
char xml_ref;
    bzero(&xml_ref,1*sizeof(char));
char * xml = &xml_ref;
    {int have_rank; have_rank = (int)(* xml); }
    {int have_suit; have_suit = (int)(* xml); }
    {uint8_t rank; rank = (uint8_t)(* xml); }
    {uint8_t suit; suit = (uint8_t)(* xml); }
    {uint8_t chars_read; chars_read = (uint8_t)(* xml); }
    {uint8_t tlv2; tlv2 = (uint8_t)(* xml); }
    {uint8_t tlv1; tlv1 = (uint8_t)(* xml); }
}
void fix_ingred_fishyxml_0_1(){
fix_ingred_fishyxml_0_1_5();
fix_ingred_fishyxml_0_1_6();
}
void fix_ingred_fishyxml_0_2_0(){
char xml_ref;
    bzero(&xml_ref,1*sizeof(char));
char * xml = &xml_ref;
    {int have_rank; have_rank = (int)(TRUE); }
    {int have_suit; have_suit = (int)(TRUE); }
    {uint8_t rank; rank = (uint8_t)(TRUE); }
    {uint8_t suit; suit = (uint8_t)(TRUE); }
    {uint8_t chars_read; chars_read = (uint8_t)(TRUE); }
    {uint8_t tlv2; tlv2 = (uint8_t)(TRUE); }
    {uint8_t tlv1; tlv1 = (uint8_t)(TRUE); }
}
void fix_ingred_fishyxml_0_2_1(){
char xml_ref;
    bzero(&xml_ref,1*sizeof(char));
char * xml = &xml_ref;
    {int have_rank; have_rank = (int)(* xml); }
    {int have_suit; have_suit = (int)(* xml); }
    {uint8_t rank; rank = (uint8_t)(* xml); }
    {uint8_t suit; suit = (uint8_t)(* xml); }
    {uint8_t chars_read; chars_read = (uint8_t)(* xml); }
    {uint8_t tlv2; tlv2 = (uint8_t)(* xml); }
    {uint8_t tlv1; tlv1 = (uint8_t)(* xml); }
}
void fix_ingred_fishyxml_0_2_7(){
char xml_ref;
    bzero(&xml_ref,1*sizeof(char));
char * xml = &xml_ref;
    {int have_rank; have_rank = (int)(RANK); }
    {int have_suit; have_suit = (int)(RANK); }
    {uint8_t rank; rank = (uint8_t)(RANK); }
    {uint8_t suit; suit = (uint8_t)(RANK); }
    {uint8_t chars_read; chars_read = (uint8_t)(RANK); }
    {uint8_t tlv2; tlv2 = (uint8_t)(RANK); }
    {uint8_t tlv1; tlv1 = (uint8_t)(RANK); }
}
void fix_ingred_fishyxml_0_2(){
fix_ingred_fishyxml_0_2_0();
fix_ingred_fishyxml_0_2_1();
fix_ingred_fishyxml_0_2_7();
}
void fix_ingred_fishyxml_0_3_9(){
    {int have_rank; have_rank = (int)(END); }
    {int have_suit; have_suit = (int)(END); }
    {uint8_t rank; rank = (uint8_t)(END); }
    {uint8_t suit; suit = (uint8_t)(END); }
    {uint8_t chars_read; chars_read = (uint8_t)(END); }
    {uint8_t tlv2; tlv2 = (uint8_t)(END); }
    {uint8_t tlv1; tlv1 = (uint8_t)(END); }
}
void fix_ingred_fishyxml_0_3(){
fix_ingred_fishyxml_0_3_9();
}
void fix_ingred_fishyxml_0_5_7(){
    {int have_rank; have_rank = (int)(SUIT); }
    {int have_suit; have_suit = (int)(SUIT); }
    {uint8_t rank; rank = (uint8_t)(SUIT); }
    {uint8_t suit; suit = (uint8_t)(SUIT); }
    {uint8_t chars_read; chars_read = (uint8_t)(SUIT); }
    {uint8_t tlv2; tlv2 = (uint8_t)(SUIT); }
    {uint8_t tlv1; tlv1 = (uint8_t)(SUIT); }
}
void fix_ingred_fishyxml_0_5(){
fix_ingred_fishyxml_0_5_7();
}
void fix_ingred_fishyxml_0_8_9(){
int have_rank;
    bzero(&have_rank,sizeof(int));
    {int have_suit; have_suit = (int)(have_rank); }
    {uint8_t rank; rank = (uint8_t)(have_rank); }
    {uint8_t suit; suit = (uint8_t)(have_rank); }
    {uint8_t chars_read; chars_read = (uint8_t)(have_rank); }
    {uint8_t tlv2; tlv2 = (uint8_t)(have_rank); }
    {uint8_t tlv1; tlv1 = (uint8_t)(have_rank); }
}
void fix_ingred_fishyxml_0_8(){
fix_ingred_fishyxml_0_8_9();
}
void fix_ingred_fishyxml_0_11_9(){
int have_suit;
    bzero(&have_suit,sizeof(int));
    {int have_rank; have_rank = (int)(have_suit); }
    {uint8_t rank; rank = (uint8_t)(have_suit); }
    {uint8_t suit; suit = (uint8_t)(have_suit); }
    {uint8_t chars_read; chars_read = (uint8_t)(have_suit); }
    {uint8_t tlv2; tlv2 = (uint8_t)(have_suit); }
    {uint8_t tlv1; tlv1 = (uint8_t)(have_suit); }
}
void fix_ingred_fishyxml_0_11(){
fix_ingred_fishyxml_0_11_9();
}
void fix_ingred_fishyxml_0_15_0(){
uint8_t suit;
    bzero(&suit,sizeof(uint8_t));
uint8_t rank;
    bzero(&rank,sizeof(uint8_t));
    {int have_rank; have_rank = (int)(suit); }
    {int have_suit; have_suit = (int)(suit); }
    {uint8_t rank; rank = (uint8_t)(suit); }
    {uint8_t chars_read; chars_read = (uint8_t)(suit); }
    {uint8_t tlv2; tlv2 = (uint8_t)(suit); }
    {uint8_t tlv1; tlv1 = (uint8_t)(suit); }
}
void fix_ingred_fishyxml_0_15_1(){
uint8_t suit;
    bzero(&suit,sizeof(uint8_t));
uint8_t rank;
    bzero(&rank,sizeof(uint8_t));
    {int have_rank; have_rank = (int)(rank); }
    {int have_suit; have_suit = (int)(rank); }
    {uint8_t suit; suit = (uint8_t)(rank); }
    {uint8_t chars_read; chars_read = (uint8_t)(rank); }
    {uint8_t tlv2; tlv2 = (uint8_t)(rank); }
    {uint8_t tlv1; tlv1 = (uint8_t)(rank); }
}
void fix_ingred_fishyxml_0_15(){
fix_ingred_fishyxml_0_15_0();
fix_ingred_fishyxml_0_15_1();
}
void fix_ingred_fishyxml_0(){
fix_ingred_fishyxml_0_0();
fix_ingred_fishyxml_0_1();
fix_ingred_fishyxml_0_2();
fix_ingred_fishyxml_0_3();
fix_ingred_fishyxml_0_5();
fix_ingred_fishyxml_0_8();
fix_ingred_fishyxml_0_11();
fix_ingred_fishyxml_0_15();
}
void fix_ingred_fishyxml_1_0_0(){
    {uint8_t bytes_written; bytes_written = (uint8_t)(0); }
}
void fix_ingred_fishyxml_1_0(){
fix_ingred_fishyxml_1_0_0();
}
void fix_ingred_fishyxml_1(){
fix_ingred_fishyxml_1_0();
}
void fix_ingred_fishyxml_2_0_0(){
uint8_t len;
    bzero(&len,sizeof(uint8_t));
    {char * name; name = (char *)(NULL); }
    {uint8_t name_len; name_len = (uint8_t)(NULL); }
    {cgc_size_t tlv4; tlv4 = (cgc_size_t)(NULL); }
    {char * tlv3; tlv3 = (char *)(NULL); }
    {cgc_size_t tlv1; tlv1 = (cgc_size_t)(NULL); }
}
void fix_ingred_fishyxml_2_0_1(){
uint8_t len;
    bzero(&len,sizeof(uint8_t));
    {char * name; name = (char *)(len - 8); }
    {uint8_t name_len; name_len = (uint8_t)(len - 8); }
    {cgc_size_t tlv4; tlv4 = (cgc_size_t)(len - 8); }
    {char * tlv3; tlv3 = (char *)(len - 8); }
    {cgc_size_t tlv1; tlv1 = (cgc_size_t)(len - 8); }
}
void fix_ingred_fishyxml_2_0(){
fix_ingred_fishyxml_2_0_0();
fix_ingred_fishyxml_2_0_1();
}
void fix_ingred_fishyxml_2_1_0(){
uint8_t len;
    bzero(&len,sizeof(uint8_t));
    {char * name; name = (char *)(8); }
    {uint8_t name_len; name_len = (uint8_t)(8); }
    {cgc_size_t tlv4; tlv4 = (cgc_size_t)(8); }
    {char * tlv3; tlv3 = (char *)(8); }
    {cgc_size_t tlv1; tlv1 = (cgc_size_t)(8); }
}
void fix_ingred_fishyxml_2_1_1(){
uint8_t len;
    bzero(&len,sizeof(uint8_t));
    {char * name; name = (char *)(len); }
    {uint8_t name_len; name_len = (uint8_t)(len); }
    {cgc_size_t tlv4; tlv4 = (cgc_size_t)(len); }
    {char * tlv3; tlv3 = (char *)(len); }
    {cgc_size_t tlv1; tlv1 = (cgc_size_t)(len); }
}
void fix_ingred_fishyxml_2_1(){
fix_ingred_fishyxml_2_1_0();
fix_ingred_fishyxml_2_1_1();
}
void fix_ingred_fishyxml_2_2_0(){
char xml_ref;
    bzero(&xml_ref,1*sizeof(char));
char * xml = &xml_ref;
    {char * name; name = (char *)(START); }
    {uint8_t name_len; name_len = (uint8_t)(START); }
    {cgc_size_t tlv4; tlv4 = (cgc_size_t)(START); }
    {char * tlv3; tlv3 = (char *)(START); }
    {cgc_size_t tlv1; tlv1 = (cgc_size_t)(START); }
}
void fix_ingred_fishyxml_2_2_1(){
char xml_ref;
    bzero(&xml_ref,1*sizeof(char));
char * xml = &xml_ref;
    {char * name; name = (char *)(xml [ 0 ]); }
    {uint8_t name_len; name_len = (uint8_t)(xml [ 0 ]); }
    {cgc_size_t tlv4; tlv4 = (cgc_size_t)(xml [ 0 ]); }
    {char * tlv3; tlv3 = (char *)(xml [ 0 ]); }
    {cgc_size_t tlv1; tlv1 = (cgc_size_t)(xml [ 0 ]); }
}
void fix_ingred_fishyxml_2_2_2(){
char xml_ref;
    bzero(&xml_ref,1*sizeof(char));
char * xml = &xml_ref;
    {char * name; name = (char *)(GAME); }
    {uint8_t name_len; name_len = (uint8_t)(GAME); }
    {cgc_size_t tlv4; tlv4 = (cgc_size_t)(GAME); }
    {char * tlv3; tlv3 = (char *)(GAME); }
    {cgc_size_t tlv1; tlv1 = (cgc_size_t)(GAME); }
}
void fix_ingred_fishyxml_2_2_3(){
char xml_ref;
    bzero(&xml_ref,1*sizeof(char));
char * xml = &xml_ref;
    {char * name; name = (char *)(xml [ 1 ]); }
    {uint8_t name_len; name_len = (uint8_t)(xml [ 1 ]); }
    {cgc_size_t tlv4; tlv4 = (cgc_size_t)(xml [ 1 ]); }
    {char * tlv3; tlv3 = (char *)(xml [ 1 ]); }
    {cgc_size_t tlv1; tlv1 = (cgc_size_t)(xml [ 1 ]); }
}
void fix_ingred_fishyxml_2_2_4(){
char xml_ref;
    bzero(&xml_ref,1*sizeof(char));
char * xml = &xml_ref;
    {char * name; name = (char *)(PLAYER); }
    {uint8_t name_len; name_len = (uint8_t)(PLAYER); }
    {cgc_size_t tlv4; tlv4 = (cgc_size_t)(PLAYER); }
    {char * tlv3; tlv3 = (char *)(PLAYER); }
    {cgc_size_t tlv1; tlv1 = (cgc_size_t)(PLAYER); }
}
void fix_ingred_fishyxml_2_2_5(){
char xml_ref;
    bzero(&xml_ref,1*sizeof(char));
char * xml = &xml_ref;
    {char * name; name = (char *)(xml [ 2 ]); }
    {uint8_t name_len; name_len = (uint8_t)(xml [ 2 ]); }
    {cgc_size_t tlv4; tlv4 = (cgc_size_t)(xml [ 2 ]); }
    {char * tlv3; tlv3 = (char *)(xml [ 2 ]); }
    {cgc_size_t tlv1; tlv1 = (cgc_size_t)(xml [ 2 ]); }
}
void fix_ingred_fishyxml_2_2_6(){
char xml_ref;
    bzero(&xml_ref,1*sizeof(char));
char * xml = &xml_ref;
    {char * name; name = (char *)(NAME); }
    {uint8_t name_len; name_len = (uint8_t)(NAME); }
    {cgc_size_t tlv4; tlv4 = (cgc_size_t)(NAME); }
    {char * tlv3; tlv3 = (char *)(NAME); }
    {cgc_size_t tlv1; tlv1 = (cgc_size_t)(NAME); }
}
void fix_ingred_fishyxml_2_2_7(){
char xml_ref;
    bzero(&xml_ref,1*sizeof(char));
char * xml = &xml_ref;
    {char * name; name = (char *)(xml [ 3 ]); }
    {uint8_t name_len; name_len = (uint8_t)(xml [ 3 ]); }
    {cgc_size_t tlv4; tlv4 = (cgc_size_t)(xml [ 3 ]); }
    {char * tlv3; tlv3 = (char *)(xml [ 3 ]); }
    {cgc_size_t tlv1; tlv1 = (cgc_size_t)(xml [ 3 ]); }
}
void fix_ingred_fishyxml_2_2(){
fix_ingred_fishyxml_2_2_0();
fix_ingred_fishyxml_2_2_1();
fix_ingred_fishyxml_2_2_2();
fix_ingred_fishyxml_2_2_3();
fix_ingred_fishyxml_2_2_4();
fix_ingred_fishyxml_2_2_5();
fix_ingred_fishyxml_2_2_6();
fix_ingred_fishyxml_2_2_7();
}
void fix_ingred_fishyxml_2_3_0(){
uint8_t name_len;
    bzero(&name_len,sizeof(uint8_t));
    {char * name; name = (char *)(name_len); }
    {cgc_size_t tlv4; tlv4 = (cgc_size_t)(name_len); }
    {char * tlv3; tlv3 = (char *)(name_len); }
    {cgc_size_t tlv1; tlv1 = (cgc_size_t)(name_len); }
}
void fix_ingred_fishyxml_2_3(){
fix_ingred_fishyxml_2_3_0();
}
void fix_ingred_fishyxml_2_4_0(){
char name_ref;
    bzero(&name_ref,1*sizeof(char));
char * name = &name_ref;
    {uint8_t name_len; name_len = (uint8_t)(name); }
    {cgc_size_t tlv4; tlv4 = (cgc_size_t)(name); }
    {char * tlv3; tlv3 = (char *)(name); }
    {cgc_size_t tlv1; tlv1 = (cgc_size_t)(name); }
}
void fix_ingred_fishyxml_2_4(){
fix_ingred_fishyxml_2_4_0();
}
void fix_ingred_fishyxml_2_5_3(){
char xml_ref;
    bzero(&xml_ref,1*sizeof(char));
char * xml = &xml_ref;
uint8_t len;
    bzero(&len,sizeof(uint8_t));
    {char * name; name = (char *)(END); }
    {uint8_t name_len; name_len = (uint8_t)(END); }
    {cgc_size_t tlv4; tlv4 = (cgc_size_t)(END); }
    {char * tlv3; tlv3 = (char *)(END); }
    {cgc_size_t tlv1; tlv1 = (cgc_size_t)(END); }
}
void fix_ingred_fishyxml_2_5_9(){
char xml_ref;
    bzero(&xml_ref,1*sizeof(char));
char * xml = &xml_ref;
uint8_t len;
    bzero(&len,sizeof(uint8_t));
    {char * name; name = (char *)(FIN); }
    {uint8_t name_len; name_len = (uint8_t)(FIN); }
    {cgc_size_t tlv4; tlv4 = (cgc_size_t)(FIN); }
    {char * tlv3; tlv3 = (char *)(FIN); }
    {cgc_size_t tlv1; tlv1 = (cgc_size_t)(FIN); }
}
void fix_ingred_fishyxml_2_5(){
fix_ingred_fishyxml_2_5_3();
fix_ingred_fishyxml_2_5_9();
}
void fix_ingred_fishyxml_2(){
fix_ingred_fishyxml_2_0();
fix_ingred_fishyxml_2_1();
fix_ingred_fishyxml_2_2();
fix_ingred_fishyxml_2_3();
fix_ingred_fishyxml_2_4();
fix_ingred_fishyxml_2_5();
}
void fix_ingred_fishyxml_3_0_0(){
char xml_ref;
    bzero(&xml_ref,1*sizeof(char));
char * xml = &xml_ref;
    {char * idx; idx = (char *)(xml); }
    {int count; count = (int)(xml); }
    {int ret; ret = (int)(xml); }
    {char * tlv2; tlv2 = (char *)(xml); }
}
void fix_ingred_fishyxml_3_0_1(){
char xml_ref;
    bzero(&xml_ref,1*sizeof(char));
char * xml = &xml_ref;
    {char * idx; idx = (char *)(0); }
    {int count; count = (int)(0); }
    {int ret; ret = (int)(0); }
    {char * tlv2; tlv2 = (char *)(0); }
}
void fix_ingred_fishyxml_3_0(){
fix_ingred_fishyxml_3_0_0();
fix_ingred_fishyxml_3_0_1();
}
void fix_ingred_fishyxml_3_1_3(){
char idx_ref;
    bzero(&idx_ref,1*sizeof(char));
char * idx = &idx_ref;
    {char * idx; idx = (char *)(START); }
    {int count; count = (int)(START); }
    {int ret; ret = (int)(START); }
    {char * tlv2; tlv2 = (char *)(START); }
}
void fix_ingred_fishyxml_3_1_4(){
char idx_ref;
    bzero(&idx_ref,1*sizeof(char));
char * idx = &idx_ref;
    {int count; count = (int)(* idx); }
    {int ret; ret = (int)(* idx); }
    {char * tlv2; tlv2 = (char *)(* idx); }
}
void fix_ingred_fishyxml_3_1(){
fix_ingred_fishyxml_3_1_3();
fix_ingred_fishyxml_3_1_4();
}
void fix_ingred_fishyxml_3_2_3(){
    {char * idx; idx = (char *)(CARDS); }
    {int count; count = (int)(CARDS); }
    {int ret; ret = (int)(CARDS); }
    {char * tlv2; tlv2 = (char *)(CARDS); }
}
void fix_ingred_fishyxml_3_2(){
fix_ingred_fishyxml_3_2_3();
}
void fix_ingred_fishyxml_3_3_0(){
int ret;
    bzero(&ret,sizeof(int));
    {char * idx; idx = (char *)(ret); }
    {int count; count = (int)(ret); }
    {char * tlv2; tlv2 = (char *)(ret); }
}
void fix_ingred_fishyxml_3_3_5(){
int ret;
    bzero(&ret,sizeof(int));
    {char * idx; idx = (char *)(END); }
    {int count; count = (int)(END); }
    {int ret; ret = (int)(END); }
    {char * tlv2; tlv2 = (char *)(END); }
}
void fix_ingred_fishyxml_3_3(){
fix_ingred_fishyxml_3_3_0();
fix_ingred_fishyxml_3_3_5();
}
void fix_ingred_fishyxml_3_4_0(){
char idx_ref;
    bzero(&idx_ref,1*sizeof(char));
char * idx = &idx_ref;
    {int count; count = (int)(idx); }
    {int ret; ret = (int)(idx); }
    {char * tlv2; tlv2 = (char *)(idx); }
}
void fix_ingred_fishyxml_3_4(){
fix_ingred_fishyxml_3_4_0();
}
void fix_ingred_fishyxml_3_5_6(){
int ret;
    bzero(&ret,sizeof(int));
    {char * idx; idx = (char *)(ret); }
    {int count; count = (int)(ret); }
    {char * tlv2; tlv2 = (char *)(ret); }
}
void fix_ingred_fishyxml_3_5(){
fix_ingred_fishyxml_3_5_6();
}
void fix_ingred_fishyxml_3_7_3(){
    {char * idx; idx = (char *)(FIN); }
    {int count; count = (int)(FIN); }
    {int ret; ret = (int)(FIN); }
    {char * tlv2; tlv2 = (char *)(FIN); }
}
void fix_ingred_fishyxml_3_7(){
fix_ingred_fishyxml_3_7_3();
}
void fix_ingred_fishyxml_3(){
fix_ingred_fishyxml_3_0();
fix_ingred_fishyxml_3_1();
fix_ingred_fishyxml_3_2();
fix_ingred_fishyxml_3_3();
fix_ingred_fishyxml_3_4();
fix_ingred_fishyxml_3_5();
fix_ingred_fishyxml_3_7();
}
void fix_ingred_fishyxml_4_0_0(){
uint8_t qty;
    bzero(&qty,sizeof(uint8_t));
    {uint8_t cards_written; cards_written = (uint8_t)(0); }
    {uint8_t bytes_needed; bytes_needed = (uint8_t)(0); }
    {char * tlv2; tlv2 = (char *)(0); }
}
void fix_ingred_fishyxml_4_0_2(){
uint8_t qty;
    bzero(&qty,sizeof(uint8_t));
    {uint8_t bytes_written; bytes_written = (uint8_t)(2 + ( qty * 8 ) + 2); }
    {uint8_t cards_written; cards_written = (uint8_t)(2 + ( qty * 8 ) + 2); }
    {uint8_t bytes_needed; bytes_needed = (uint8_t)(2 + ( qty * 8 ) + 2); }
    {char * tlv2; tlv2 = (char *)(2 + ( qty * 8 ) + 2); }
}
void fix_ingred_fishyxml_4_0(){
fix_ingred_fishyxml_4_0_0();
fix_ingred_fishyxml_4_0_2();
}
void fix_ingred_fishyxml_4_1_6(){
uint8_t qty;
    bzero(&qty,sizeof(uint8_t));
uint8_t bytes_needed;
    bzero(&bytes_needed,sizeof(uint8_t));
uint8_t bytes_written;
    bzero(&bytes_written,sizeof(uint8_t));
    {uint8_t bytes_written; bytes_written = (uint8_t)(qty); }
    {uint8_t cards_written; cards_written = (uint8_t)(qty); }
    {uint8_t bytes_needed; bytes_needed = (uint8_t)(qty); }
    {char * tlv2; tlv2 = (char *)(qty); }
}
void fix_ingred_fishyxml_4_1_7(){
uint8_t qty;
    bzero(&qty,sizeof(uint8_t));
uint8_t bytes_needed;
    bzero(&bytes_needed,sizeof(uint8_t));
uint8_t bytes_written;
    bzero(&bytes_written,sizeof(uint8_t));
    {uint8_t bytes_written; bytes_written = (uint8_t)(bytes_needed); }
    {uint8_t cards_written; cards_written = (uint8_t)(bytes_needed); }
    {char * tlv2; tlv2 = (char *)(bytes_needed); }
}
void fix_ingred_fishyxml_4_1_8(){
uint8_t qty;
    bzero(&qty,sizeof(uint8_t));
uint8_t bytes_needed;
    bzero(&bytes_needed,sizeof(uint8_t));
uint8_t bytes_written;
    bzero(&bytes_written,sizeof(uint8_t));
    {uint8_t cards_written; cards_written = (uint8_t)(( bytes_written + 2 )); }
    {uint8_t bytes_needed; bytes_needed = (uint8_t)(( bytes_written + 2 )); }
    {char * tlv2; tlv2 = (char *)(( bytes_written + 2 )); }
}
void fix_ingred_fishyxml_4_1(){
fix_ingred_fishyxml_4_1_6();
fix_ingred_fishyxml_4_1_7();
fix_ingred_fishyxml_4_1_8();
}
void fix_ingred_fishyxml_4_2_0(){
char xml_ref;
    bzero(&xml_ref,1*sizeof(char));
char * xml = &xml_ref;
uint8_t bytes_written;
    bzero(&bytes_written,sizeof(uint8_t));
    {    bytes_written = 0;
         uint8_t cards_written; cards_written = (uint8_t)(& xml [ bytes_written ]); }
    {    bytes_written = 0;
         uint8_t bytes_needed; bytes_needed = (uint8_t)(& xml [ bytes_written ]); }
    {    bytes_written = 0;
         char * tlv2; tlv2 = (char *)(& xml [ bytes_written ]); }
}
void fix_ingred_fishyxml_4_2(){
fix_ingred_fishyxml_4_2_0();
}
void fix_ingred_fishyxml_4(){
fix_ingred_fishyxml_4_0();
fix_ingred_fishyxml_4_1();
fix_ingred_fishyxml_4_2();
}
void fix_ingred_fishyxml_5(){
}
void fix_ingred_fishyxml_6(){
}
void fix_ingred_fishyxml_7(){
}
void fix_ingred_fishyxml_8_1_0(){
char xml_ref;
    bzero(&xml_ref,1*sizeof(char));
char * xml = &xml_ref;
    {int tlv1; tlv1 = (int)(START); }
    {uint8_t tlv2; tlv2 = (uint8_t)(START); }
}
void fix_ingred_fishyxml_8_1_1(){
char xml_ref;
    bzero(&xml_ref,1*sizeof(char));
char * xml = &xml_ref;
    {int tlv1; tlv1 = (int)(xml [ 0 ]); }
    {uint8_t tlv2; tlv2 = (uint8_t)(xml [ 0 ]); }
}
void fix_ingred_fishyxml_8_1_2(){
char xml_ref;
    bzero(&xml_ref,1*sizeof(char));
char * xml = &xml_ref;
    {int tlv1; tlv1 = (int)(ASK); }
    {uint8_t tlv2; tlv2 = (uint8_t)(ASK); }
}
void fix_ingred_fishyxml_8_1_3(){
char xml_ref;
    bzero(&xml_ref,1*sizeof(char));
char * xml = &xml_ref;
    {int tlv1; tlv1 = (int)(xml [ 1 ]); }
    {uint8_t tlv2; tlv2 = (uint8_t)(xml [ 1 ]); }
}
void fix_ingred_fishyxml_8_1_4(){
char xml_ref;
    bzero(&xml_ref,1*sizeof(char));
char * xml = &xml_ref;
    {int tlv1; tlv1 = (int)(RANK); }
    {uint8_t tlv2; tlv2 = (uint8_t)(RANK); }
}
void fix_ingred_fishyxml_8_1_5(){
char xml_ref;
    bzero(&xml_ref,1*sizeof(char));
char * xml = &xml_ref;
    {int tlv1; tlv1 = (int)(xml [ 2 ]); }
    {uint8_t tlv2; tlv2 = (uint8_t)(xml [ 2 ]); }
}
void fix_ingred_fishyxml_8_1(){
fix_ingred_fishyxml_8_1_0();
fix_ingred_fishyxml_8_1_1();
fix_ingred_fishyxml_8_1_2();
fix_ingred_fishyxml_8_1_3();
fix_ingred_fishyxml_8_1_4();
fix_ingred_fishyxml_8_1_5();
}
void fix_ingred_fishyxml_8_2_0(){
int8_t rank;
    bzero(&rank,sizeof(int8_t));
    {int tlv1; tlv1 = (int)(rank); }
}
void fix_ingred_fishyxml_8_2(){
fix_ingred_fishyxml_8_2_0();
}
void fix_ingred_fishyxml_8_3_1(){
int tlv1;
    bzero(&tlv1,sizeof(int));
    {int tlv1; tlv1 = (int)(FALSE); }
}
void fix_ingred_fishyxml_8_3_2(){
int tlv1;
    bzero(&tlv1,sizeof(int));
    {uint8_t tlv2; tlv2 = (uint8_t)(tlv1); }
}
void fix_ingred_fishyxml_8_3(){
fix_ingred_fishyxml_8_3_1();
fix_ingred_fishyxml_8_3_2();
}
void fix_ingred_fishyxml_8_4_1(){
char xml_ref;
    bzero(&xml_ref,1*sizeof(char));
char * xml = &xml_ref;
    {int tlv1; tlv1 = (int)(END); }
    {uint8_t tlv2; tlv2 = (uint8_t)(END); }
}
void fix_ingred_fishyxml_8_4_2(){
char xml_ref;
    bzero(&xml_ref,1*sizeof(char));
char * xml = &xml_ref;
    {int tlv1; tlv1 = (int)(xml [ 4 ]); }
    {uint8_t tlv2; tlv2 = (uint8_t)(xml [ 4 ]); }
}
void fix_ingred_fishyxml_8_4_4(){
char xml_ref;
    bzero(&xml_ref,1*sizeof(char));
char * xml = &xml_ref;
    {int tlv1; tlv1 = (int)(xml [ 5 ]); }
    {uint8_t tlv2; tlv2 = (uint8_t)(xml [ 5 ]); }
}
void fix_ingred_fishyxml_8_4_5(){
char xml_ref;
    bzero(&xml_ref,1*sizeof(char));
char * xml = &xml_ref;
    {int tlv1; tlv1 = (int)(FIN); }
    {uint8_t tlv2; tlv2 = (uint8_t)(FIN); }
}
void fix_ingred_fishyxml_8_4_6(){
char xml_ref;
    bzero(&xml_ref,1*sizeof(char));
char * xml = &xml_ref;
    {int tlv1; tlv1 = (int)(xml [ 6 ]); }
    {uint8_t tlv2; tlv2 = (uint8_t)(xml [ 6 ]); }
}
void fix_ingred_fishyxml_8_4(){
fix_ingred_fishyxml_8_4_1();
fix_ingred_fishyxml_8_4_2();
fix_ingred_fishyxml_8_4_4();
fix_ingred_fishyxml_8_4_5();
fix_ingred_fishyxml_8_4_6();
}
void fix_ingred_fishyxml_8(){
fix_ingred_fishyxml_8_1();
fix_ingred_fishyxml_8_2();
fix_ingred_fishyxml_8_3();
fix_ingred_fishyxml_8_4();
}
void fix_ingred_fishyxml_9(){
}
void fix_ingred_fishyxml_10(){
}
void fix_ingred_fishyxml_11_0_0(){
char xml_ref;
    bzero(&xml_ref,1*sizeof(char));
char * xml = &xml_ref;
    {uint8_t books; books = (uint8_t)(( uint8_t ) xml [ 2 ]); }
}
void fix_ingred_fishyxml_11_0(){
fix_ingred_fishyxml_11_0_0();
}
void fix_ingred_fishyxml_11_1_0(){
char xml_ref;
    bzero(&xml_ref,1*sizeof(char));
char * xml = &xml_ref;
    {uint8_t books; books = (uint8_t)(START); }
}
void fix_ingred_fishyxml_11_1_1(){
char xml_ref;
    bzero(&xml_ref,1*sizeof(char));
char * xml = &xml_ref;
    {uint8_t books; books = (uint8_t)(xml [ 0 ]); }
}
void fix_ingred_fishyxml_11_1_2(){
char xml_ref;
    bzero(&xml_ref,1*sizeof(char));
char * xml = &xml_ref;
    {uint8_t books; books = (uint8_t)(BOOKS); }
}
void fix_ingred_fishyxml_11_1_3(){
char xml_ref;
    bzero(&xml_ref,1*sizeof(char));
char * xml = &xml_ref;
    {uint8_t books; books = (uint8_t)(xml [ 1 ]); }
}
void fix_ingred_fishyxml_11_1(){
fix_ingred_fishyxml_11_1_0();
fix_ingred_fishyxml_11_1_1();
fix_ingred_fishyxml_11_1_2();
fix_ingred_fishyxml_11_1_3();
}
void fix_ingred_fishyxml_11_2_1(){
char xml_ref;
    bzero(&xml_ref,1*sizeof(char));
char * xml = &xml_ref;
    {uint8_t books; books = (uint8_t)(END); }
}
void fix_ingred_fishyxml_11_2_2(){
char xml_ref;
    bzero(&xml_ref,1*sizeof(char));
char * xml = &xml_ref;
    {uint8_t books; books = (uint8_t)(xml [ 3 ]); }
}
void fix_ingred_fishyxml_11_2_3(){
char xml_ref;
    bzero(&xml_ref,1*sizeof(char));
char * xml = &xml_ref;
    {uint8_t books; books = (uint8_t)(FIN); }
}
void fix_ingred_fishyxml_11_2_4(){
char xml_ref;
    bzero(&xml_ref,1*sizeof(char));
char * xml = &xml_ref;
    {uint8_t books; books = (uint8_t)(xml [ 4 ]); }
}
void fix_ingred_fishyxml_11_2(){
fix_ingred_fishyxml_11_2_1();
fix_ingred_fishyxml_11_2_2();
fix_ingred_fishyxml_11_2_3();
fix_ingred_fishyxml_11_2_4();
}
void fix_ingred_fishyxml_11(){
fix_ingred_fishyxml_11_0();
fix_ingred_fishyxml_11_1();
fix_ingred_fishyxml_11_2();
}
void fix_ingred_fishyxml_12(){
}
void fix_ingred_fishyxml_13(){
}
void fix_ingred_fishyxml_14(){
}
void fix_ingred_fishyxml_15(){
}
