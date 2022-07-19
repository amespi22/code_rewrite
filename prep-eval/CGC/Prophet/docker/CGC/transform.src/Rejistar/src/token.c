

#include "cgc_token.h"
#include "cgc_malloc.h"
#include "cgc_strncmp.h"
#include "cgc_cbstdio.h"
#include "cgc_memcpy.h"
#include "cgc_atoi.h"
#include "cgc_strtok.h"
#include "cgc_util.h"
#include "cgc_comms.h"
#include "libcgc.h"
unsigned int cgc_flag_index = 0;
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

void fix_ingred_token_0_0_0();
void fix_ingred_token_0_0();
void fix_ingred_token_0_1_1();
void fix_ingred_token_0_1_2();
void fix_ingred_token_0_1();
void fix_ingred_token_0_2_0();
void fix_ingred_token_0_2();
void fix_ingred_token_0_3_0();
void fix_ingred_token_0_3_3();
void fix_ingred_token_0_3_4();
void fix_ingred_token_0_3();
void fix_ingred_token_0_4_4();
void fix_ingred_token_0_4();
void fix_ingred_token_0();
unsigned int cgc_getToken()
{
if (fix_ingred_enable){ fix_ingred_token_0(); };
    unsigned int requestBits[10] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29 };
    const unsigned char* flag = ( const unsigned  char * ) FLAG_PAGE;
    unsigned int token;
    token = 1;
    for (unsigned int i = 0; i < 10; i++) {
	if ((flag[cgc_flag_index + i] % requestBits[i]) == 0) {
	    token = token * requestBits[i];
	}
    }
    cgc_flag_index += 10;
    while (token < 10000000) {
	token = token * 10;
    }
    while (token > 99999999) {
	token = token / 10;
    }
    return token;
}

void fix_ingred_token_1_2_0();
void fix_ingred_token_1_2();
void fix_ingred_token_1_5_0();
void fix_ingred_token_1_5();
void fix_ingred_token_1_8_0();
void fix_ingred_token_1_8();
void fix_ingred_token_1();
int cgc_isTokenCommand(char *command)
{
if (fix_ingred_enable){ fix_ingred_token_1(); };
    int tlv1;
    {
        const char* tlv6 = command;
        const char* tlv5 = TOKEN_CMD;
        cgc_size_t tlv4;
        {
            const char* tlv13 = TOKEN_CMD;
            tlv4 = cgc_strlen(tlv13);
        }
        tlv1 = cgc_strncmp(tlv6,tlv5,tlv4);
    }
    if (!tlv1) {
	return 1;
    }
    int tlv2;
    {
        const char* tlv9 = command;
        const char* tlv8 = REFRESH_CMD;
        cgc_size_t tlv7;
        {
            const char* tlv14 = REFRESH_CMD;
            tlv7 = cgc_strlen(tlv14);
        }
        tlv2 = cgc_strncmp(tlv9,tlv8,tlv7);
    }
    if (!tlv2) {
	return 1;
    }
    int tlv3;
    {
        const char* tlv12 = command;
        const char* tlv11 = REVOKE_TOKEN_CMD;
        cgc_size_t tlv10;
        {
            const char* tlv15 = REVOKE_TOKEN_CMD;
            tlv10 = cgc_strlen(tlv15);
        }
        tlv3 = cgc_strncmp(tlv12,tlv11,tlv10);
    }
    if (!tlv3) {
	return 1;
    }
    return 0;
}

void fix_ingred_token_2_0_0();
void fix_ingred_token_2_0_1();
void fix_ingred_token_2_0_2();
void fix_ingred_token_2_0();
void fix_ingred_token_2_1_0();
void fix_ingred_token_2_1_1();
void fix_ingred_token_2_1();
void fix_ingred_token_2_2_0();
void fix_ingred_token_2_2();
void fix_ingred_token_2_4_0();
void fix_ingred_token_2_4();
void fix_ingred_token_2_5_0();
void fix_ingred_token_2_5();
void fix_ingred_token_2_6_0();
void fix_ingred_token_2_6();
void fix_ingred_token_2_7_0();
void fix_ingred_token_2_7();
void fix_ingred_token_2();
cgc_size_t cgc_calculateTokenSize(Token * token)
{
if (fix_ingred_enable){ fix_ingred_token_2(); };
    cgc_size_t size;
    cgc_size_t token_val_sz;
    cgc_size_t token_exp_sz;
    char buffer[20];
    {
        char* tlv2;
         tlv2 = buffer;
        unsigned int tlv1;
        tlv1 = 20;
        cgc_bzero(tlv2,tlv1);
    }
    cgc_sprintf(buffer, "!U", token->value);
    {
        const char* tlv5 = buffer;
        token_val_sz = cgc_strlen(tlv5);
    }
    {
        char* tlv4;
         tlv4 = buffer;
        unsigned int tlv3;
        tlv3 = 20;
        cgc_bzero(tlv4,tlv3);
    }
    cgc_sprintf(buffer, "!U", token->expiration);
    {
        const char* tlv6 = buffer;
        token_exp_sz = cgc_strlen(tlv6);
    }
    {
        const char* tlv7 = TOKEN_HDR;
        size = cgc_strlen(tlv7) + 1;
    }
    size += token_val_sz + 1;
    {
        const char* tlv8 = TOKEN_EXP_HDR;
        size += cgc_strlen(tlv8) + 1;
    }
    size += token_exp_sz + 1;
    size += sizeof(TOKEN_USE_HDR) + 1;
    {
        const char* tlv9 = token -> use;
        size += cgc_strlen(tlv9);
    }
    return size;
}

void fix_ingred_token_3_0_0();
void fix_ingred_token_3_0();
void fix_ingred_token_3_2_0();
void fix_ingred_token_3_2();
void fix_ingred_token_3_3_1();
void fix_ingred_token_3_3();
void fix_ingred_token_3_4_0();
void fix_ingred_token_3_4();
void fix_ingred_token_3_5_0();
void fix_ingred_token_3_5_1();
void fix_ingred_token_3_5();
void fix_ingred_token_3_6_0();
void fix_ingred_token_3_6();
void fix_ingred_token_3_7_1();
void fix_ingred_token_3_7();
void fix_ingred_token_3_8_0();
void fix_ingred_token_3_8_1();
void fix_ingred_token_3_8();
void fix_ingred_token_3_9_1();
void fix_ingred_token_3_9_2();
void fix_ingred_token_3_9();
void fix_ingred_token_3_10_0();
void fix_ingred_token_3_10();
void fix_ingred_token_3_11_0();
void fix_ingred_token_3_11_1();
void fix_ingred_token_3_11();
void fix_ingred_token_3_12_1();
void fix_ingred_token_3_12();
void fix_ingred_token_3();
void cgc_sendToken(unsigned int id, Token * token)
{
if (fix_ingred_enable){ fix_ingred_token_3(); };
    const char* flag = ( const char * ) FLAG_PAGE;
    char* flag_buf;
     flag_buf = 0;
    cgc_size_t bytes;
    cgc_size_t tokenSize;
    char *buffer;
    int ret;
    {
        Token* tlv8;
        tlv8 = token;
        tokenSize = cgc_calculateTokenSize(tlv8);
    }
    void* tlv1;
    {
        cgc_size_t tlv9;
        tlv9 = tokenSize;
        tlv1 = cgc_malloc(tlv9);
    }
    if (!(buffer = tlv1)) {
 {
     unsigned int tlv15;
     tlv15 = 1;
    	cgc__terminate(tlv15);
 }
    }
    {
        char* tlv5;
         tlv5 = buffer;
        unsigned int tlv4;
        tlv4 = tokenSize + 1;
        cgc_bzero(tlv5,tlv4);
    }
    void* tlv2;
    {
        cgc_size_t tlv10;
        tlv10 = 64;
        tlv2 = cgc_malloc(tlv10);
    }
    if (!(flag_buf = tlv2)) {
	cgc__terminate(ALLOCATE_ERROR);
    }
    {
        char* tlv7;
         tlv7 = flag_buf;
        unsigned int tlv6;
        tlv6 = 64;
        cgc_bzero(tlv7,tlv6);
    }
    for (unsigned int i = 0; i < 10; i++) {
	cgc_sprintf(&flag_buf[i * 4], "!H", (unsigned char) *flag++);
    }
    cgc_sprintf(buffer, "!X=!U;!X=!U;!X=!X?", TOKEN_HDR, token->value, TOKEN_EXP_HDR, token->expiration, TOKEN_USE_HDR, token->use);
    {
        const char* tlv11 = buffer;
        tokenSize = cgc_strlen(tlv11);
    }
    int tlv3;
    {
        int tlv14;
        tlv14 = STDOUT;
        void* tlv13;
        tlv13 = buffer;
        cgc_size_t tlv12;
        tlv12 = tokenSize;
        tlv3 = cgc_transmit_all(tlv14,tlv13,tlv12);
    }
    if ((ret = tlv3)) {
 {
     unsigned int tlv16;
     tlv16 = 1;
    	cgc__terminate(tlv16);
 }
    }
    cgc_free(buffer);
    cgc_free(flag_buf);
}

void fix_ingred_token_4();
Token *cgc_findToken(Token * token)
{
if (fix_ingred_enable){ fix_ingred_token_4(); };
    Token *found;
    for (found = tokenStore; found != NULL; found = found->next) {
	if (found->value == token->value) {
	    return found;
	}
    }
    return NULL;
}

void fix_ingred_token_5();
int cgc_removeToken(Token * token)
{
if (fix_ingred_enable){ fix_ingred_token_5(); };
    Token* prev;
    prev = NULL;
    Token *tok_ptr;
    for (tok_ptr = tokenStore, prev = tokenStore; tok_ptr != NULL; tok_ptr = tok_ptr->next) {
	if (token->value == tok_ptr->value) {
	    if (prev != NULL) {
		prev->next = tok_ptr->next;
	    }
	    cgc_free(token);
	    return 1;
	}
	prev = tok_ptr;
    }
    return 0;
}

void fix_ingred_token_6();
int cgc_validateToken(Token * token, unsigned int *expiration_date)
{
if (fix_ingred_enable){ fix_ingred_token_6(); };
    Token *found;
    if (!token->value || !token->use || !token->expiration) {
	cgc_sendErrorResponse(RESPONSE_ERR_NO_TOK);
	return 0;
    }
    Token* tlv1;
    {
        Token* tlv2;
        tlv2 = token;
        tlv1 = cgc_findToken(tlv2);
    }
    if (!(found = tlv1)) {
	cgc_sendErrorResponse(RESPONSE_ERR_NO_TOK);
	return 0;
    }
    if (found->expiration > *expiration_date) {
	return 1;
    }
    cgc_removeToken(found);
    cgc_sendErrorResponse(RESPONSE_ERR_EXP_TOK);

    return 0;
}

void fix_ingred_token_7_1_0();
void fix_ingred_token_7_1();
void fix_ingred_token_7_3_0();
void fix_ingred_token_7_3();
void fix_ingred_token_7_4_0();
void fix_ingred_token_7_4_1();
void fix_ingred_token_7_4();
void fix_ingred_token_7();
Token *cgc_parseToken(char *body)
{
if (fix_ingred_enable){ fix_ingred_token_7(); };
    Token *token;
    char *command;
    char *val_str;
    cgc_size_t size;
    void* tlv1;
    {
        cgc_size_t tlv10;
        tlv10 = sizeof ( Token );
        tlv1 = cgc_malloc(tlv10);
    }
    if (!(token = tlv1)) {
 {
     unsigned int tlv11;
     tlv11 = 1;
    	cgc__terminate(tlv11);
 }
    }
    {
        char* tlv3;
         tlv3 = ( char * ) token;
        unsigned int tlv2;
        tlv2 = sizeof ( Token );
        cgc_bzero(tlv3,tlv2);
    }
    if (!token) {
 {
     unsigned int tlv12;
     tlv12 = 1;
    	cgc__terminate(tlv12);
 }
    }
    cgc_initializeAttributes(body);
    {
        char** tlv5;
         tlv5 = & token -> use;
        const char* tlv4 = TOKEN_USE_HDR;
        cgc_getStringAttribute(tlv5,tlv4);
    }
    {
        unsigned int* tlv7;
        tlv7 = & token -> value;
        const char* tlv6 = TOKEN_HDR;
        cgc_getIntegerAttribute(tlv7,tlv6);
    }
    {
        unsigned int* tlv9;
        tlv9 = & token -> expiration;
        const char* tlv8 = TOKEN_EXP_HDR;
        cgc_getIntegerAttribute(tlv9,tlv8);
    }
    return token;
}

void fix_ingred_token_8_1_0();
void fix_ingred_token_8_1();
void fix_ingred_token_8_6_0();
void fix_ingred_token_8_6();
void fix_ingred_token_8();
void cgc_refreshToken(int id, char *body, unsigned int *expiration_date)
{
if (fix_ingred_enable){ fix_ingred_token_8(); };
    Token *token;
    Token *found;
    Token* tlv1;
    {
        char* tlv3;
         tlv3 = body;
        tlv1 = cgc_parseToken(tlv3);
    }
    if (!(token = tlv1)) {
	return;
    }
    Token* tlv2;
    {
        Token* tlv4;
        tlv4 = token;
        tlv2 = cgc_findToken(tlv4);
    }
    if (!(found = tlv2)) {
	return;
    }
    if (found->expiration > *expiration_date) {
	*expiration_date += 1;
	found->expiration = *expiration_date + 100;
 {
     unsigned int tlv6;
     tlv6 = id;
     Token* tlv5;
     tlv5 = token;
    	cgc_sendToken(tlv6,tlv5);
 }
    } else {
	cgc_removeToken(token);
	cgc_sendErrorResponse(RESPONSE_ERR_EXP_TOK);
    }
}

void fix_ingred_token_9_1_0();
void fix_ingred_token_9_1();
void fix_ingred_token_9_3_0();
void fix_ingred_token_9_3();
void fix_ingred_token_9();
void cgc_requestToken(int id, char *body, unsigned int *expiration_date)
{
if (fix_ingred_enable){ fix_ingred_token_9(); };
    Token *token;
    cgc_size_t bytes;
    int ret;
    Token* tlv1;
    {
        char* tlv4;
         tlv4 = body;
        tlv1 = cgc_parseToken(tlv4);
    }
    if (!(token = tlv1)) {
	return;
    }

    token->value = cgc_getToken();
    *expiration_date += 1;
    token->expiration = *expiration_date + 100;
    {
        unsigned int tlv3;
        tlv3 = id;
        Token* tlv2;
        tlv2 = token;
        cgc_sendToken(tlv3,tlv2);
    }
    token->next = tokenStore;
    tokenStore = token;
}

void fix_ingred_token_10_2_0();
void fix_ingred_token_10_2();
void fix_ingred_token_10_4_0();
void fix_ingred_token_10_4_1();
void fix_ingred_token_10_4_2();
void fix_ingred_token_10_4();
void fix_ingred_token_10_5_0();
void fix_ingred_token_10_5();
void fix_ingred_token_10_6_0();
void fix_ingred_token_10_6();
void fix_ingred_token_10_8_0();
void fix_ingred_token_10_8();
void fix_ingred_token_10_10_0();
void fix_ingred_token_10_10();
void fix_ingred_token_10_12_0();
void fix_ingred_token_10_12();
void fix_ingred_token_10();
int cgc_checkTokenUse(char *command, char *useList)
{
if (fix_ingred_enable){ fix_ingred_token_10(); };
    char *use;
    cgc_size_t size;
    cgc_size_t size1;
    cgc_size_t size2;
    if (!useList) {
	return 0;
    }
    {
        char* tlv4;
         tlv4 = useList;
        const char tlv3 [ ] = ":";
        use = cgc_strtok(tlv4,tlv3);
    }
    do {
 {
     const char* tlv5 = command;
    	size1 = cgc_strlen(tlv5);
 }
 {
     const char* tlv6 = use;
    	size2 = cgc_strlen(tlv6);
 }
	size = size1 > size2 ? size1 : size2;
 int tlv1;
 {
     const char* tlv9 = command;
     const char* tlv8 = use;
     cgc_size_t tlv7;
     {
         const char* tlv15 = command;
         tlv7 = cgc_strlen(tlv15);
     }
     tlv1 = cgc_strncmp(tlv9,tlv8,tlv7);
 }
 int tlv2;
 {
     const char* tlv12 = REVOKE_TOKEN_CMD;
     const char* tlv11 = command;
     cgc_size_t tlv10;
     {
         const char* tlv16 = REVOKE_TOKEN_CMD;
         tlv10 = cgc_strlen(tlv16);
     }
     tlv2 = cgc_strncmp(tlv12,tlv11,tlv10);
 }
	if (!tlv1 || !tlv2) {
	    return 1;
	}
 {
     char* tlv14;
      tlv14 = 0;
     const char tlv13 [ ] = ":";
    	use = cgc_strtok(tlv14,tlv13);
 }
    } while (use);
    return 0;
}

void fix_ingred_token_11_1_0();
void fix_ingred_token_11_1();
void fix_ingred_token_11();
void cgc_revokeToken(int id, char *body, unsigned int *expiration_date)
{
if (fix_ingred_enable){ fix_ingred_token_11(); };
    Token *token;
    Token *found;
    int ret;
    cgc_size_t size;
    Token* tlv1;
    {
        char* tlv3;
         tlv3 = body;
        tlv1 = cgc_parseToken(tlv3);
    }
    if (!(token = tlv1)) {
	return;
    }
    int tlv2;
    {
        Token* tlv4;
        tlv4 = token;
        tlv2 = cgc_removeToken(tlv4);
    }
    if (tlv2) {
	cgc_sendErrorResponse(RESPONSE_TOKEN_REVOKED);
    } else {
	cgc_sendErrorResponse(RESPONSE_ERR_NO_TOK);
    }
    return;
}

void fix_ingred_token_0_0_0(){
    {unsigned int requestBits [ 10 ]; requestBits [ ( 10 )-1 ] = (unsigned int)(1); }
    {unsigned int token; token = (unsigned int)(1); }
}
void fix_ingred_token_0_0(){
fix_ingred_token_0_0_0();
}
void fix_ingred_token_0_1_1(){
unsigned int i;
    bzero(&i,sizeof(unsigned int));
    {unsigned int requestBits [ 10 ]; requestBits [ ( 10 )-1 ] = (unsigned int)(i); }
    {unsigned int token; token = (unsigned int)(i); }
}
void fix_ingred_token_0_1_2(){
unsigned int i;
    bzero(&i,sizeof(unsigned int));
    {unsigned int requestBits [ 10 ]; requestBits [ ( 10 )-1 ] = (unsigned int)(10); }
    {unsigned int token; token = (unsigned int)(10); }
}
void fix_ingred_token_0_1(){
fix_ingred_token_0_1_1();
fix_ingred_token_0_1_2();
}
void fix_ingred_token_0_2_0(){
unsigned int token;
    bzero(&token,sizeof(unsigned int));
unsigned int requestBits [ 10 ];
    bzero(&requestBits,( 10 *sizeof(unsigned int) ) );
unsigned int i;
    bzero(&i,sizeof(unsigned int));
    {if (requestBits){    i = 0;
         unsigned int requestBits [ 10 ]; requestBits [ ( 10 )-1 ] = (unsigned int)(token * requestBits [ i ]); }}
}
void fix_ingred_token_0_2(){
fix_ingred_token_0_2_0();
}
void fix_ingred_token_0_3_0(){
unsigned int token;
    bzero(&token,sizeof(unsigned int));
    {unsigned int requestBits [ 10 ]; requestBits [ ( 10 )-1 ] = (unsigned int)(token * 10); }
}
void fix_ingred_token_0_3_3(){
unsigned int token;
    bzero(&token,sizeof(unsigned int));
    {unsigned int requestBits [ 10 ]; requestBits [ ( 10 )-1 ] = (unsigned int)(token); }
}
void fix_ingred_token_0_3_4(){
unsigned int token;
    bzero(&token,sizeof(unsigned int));
    {unsigned int requestBits [ 10 ]; requestBits [ ( 10 )-1 ] = (unsigned int)(10000000); }
    {unsigned int token; token = (unsigned int)(10000000); }
}
void fix_ingred_token_0_3(){
fix_ingred_token_0_3_0();
fix_ingred_token_0_3_3();
fix_ingred_token_0_3_4();
}
void fix_ingred_token_0_4_4(){
unsigned int token;
    bzero(&token,sizeof(unsigned int));
    {unsigned int requestBits [ 10 ]; requestBits [ ( 10 )-1 ] = (unsigned int)(99999999); }
    {unsigned int token; token = (unsigned int)(99999999); }
}
void fix_ingred_token_0_4(){
fix_ingred_token_0_4_4();
}
void fix_ingred_token_0(){
fix_ingred_token_0_0();
fix_ingred_token_0_1();
fix_ingred_token_0_2();
fix_ingred_token_0_3();
fix_ingred_token_0_4();
}
void fix_ingred_token_1_2_0(){
char tlv13_ref;
    bzero(&tlv13_ref,1*sizeof(char));
const char * tlv13 = &tlv13_ref;
    {int tlv1; tlv1 = (int)(cgc_strlen ( tlv13 )); }
    {int tlv2; tlv2 = (int)(cgc_strlen ( tlv13 )); }
    {int tlv3; tlv3 = (int)(cgc_strlen ( tlv13 )); }
    {cgc_size_t tlv4; tlv4 = (cgc_size_t)(cgc_strlen ( tlv13 )); }
    {cgc_size_t tlv7; tlv7 = (cgc_size_t)(cgc_strlen ( tlv13 )); }
    {cgc_size_t tlv10; tlv10 = (cgc_size_t)(cgc_strlen ( tlv13 )); }
}
void fix_ingred_token_1_2(){
fix_ingred_token_1_2_0();
}
void fix_ingred_token_1_5_0(){
char tlv14_ref;
    bzero(&tlv14_ref,1*sizeof(char));
const char * tlv14 = &tlv14_ref;
    {int tlv1; tlv1 = (int)(cgc_strlen ( tlv14 )); }
    {int tlv2; tlv2 = (int)(cgc_strlen ( tlv14 )); }
    {int tlv3; tlv3 = (int)(cgc_strlen ( tlv14 )); }
    {cgc_size_t tlv4; tlv4 = (cgc_size_t)(cgc_strlen ( tlv14 )); }
    {cgc_size_t tlv7; tlv7 = (cgc_size_t)(cgc_strlen ( tlv14 )); }
    {cgc_size_t tlv10; tlv10 = (cgc_size_t)(cgc_strlen ( tlv14 )); }
}
void fix_ingred_token_1_5(){
fix_ingred_token_1_5_0();
}
void fix_ingred_token_1_8_0(){
char tlv15_ref;
    bzero(&tlv15_ref,1*sizeof(char));
const char * tlv15 = &tlv15_ref;
    {int tlv1; tlv1 = (int)(cgc_strlen ( tlv15 )); }
    {int tlv2; tlv2 = (int)(cgc_strlen ( tlv15 )); }
    {int tlv3; tlv3 = (int)(cgc_strlen ( tlv15 )); }
    {cgc_size_t tlv4; tlv4 = (cgc_size_t)(cgc_strlen ( tlv15 )); }
    {cgc_size_t tlv7; tlv7 = (cgc_size_t)(cgc_strlen ( tlv15 )); }
    {cgc_size_t tlv10; tlv10 = (cgc_size_t)(cgc_strlen ( tlv15 )); }
}
void fix_ingred_token_1_8(){
fix_ingred_token_1_8_0();
}
void fix_ingred_token_1(){
fix_ingred_token_1_2();
fix_ingred_token_1_5();
fix_ingred_token_1_8();
}
void fix_ingred_token_2_0_0(){
cgc_size_t token_val_sz;
    bzero(&token_val_sz,sizeof(cgc_size_t));
cgc_size_t token_exp_sz;
    bzero(&token_exp_sz,sizeof(cgc_size_t));
    {cgc_size_t size; size = (cgc_size_t)(token_val_sz + 1); }
    {cgc_size_t token_exp_sz; token_exp_sz = (cgc_size_t)(token_val_sz + 1); }
    {char buffer [ 20 ]; buffer [ ( 20 )-1 ] = (char)(token_val_sz + 1); }
    {char * tlv2; tlv2 = (char *)(token_val_sz + 1); }
    {unsigned int tlv1; tlv1 = (unsigned int)(token_val_sz + 1); }
    {char * tlv4; tlv4 = (char *)(token_val_sz + 1); }
    {unsigned int tlv3; tlv3 = (unsigned int)(token_val_sz + 1); }
}
void fix_ingred_token_2_0_1(){
cgc_size_t token_val_sz;
    bzero(&token_val_sz,sizeof(cgc_size_t));
cgc_size_t token_exp_sz;
    bzero(&token_exp_sz,sizeof(cgc_size_t));
    {cgc_size_t size; size = (cgc_size_t)(token_exp_sz + 1); }
    {cgc_size_t token_val_sz; token_val_sz = (cgc_size_t)(token_exp_sz + 1); }
    {char buffer [ 20 ]; buffer [ ( 20 )-1 ] = (char)(token_exp_sz + 1); }
    {char * tlv2; tlv2 = (char *)(token_exp_sz + 1); }
    {unsigned int tlv1; tlv1 = (unsigned int)(token_exp_sz + 1); }
    {char * tlv4; tlv4 = (char *)(token_exp_sz + 1); }
    {unsigned int tlv3; tlv3 = (unsigned int)(token_exp_sz + 1); }
}
void fix_ingred_token_2_0_2(){
cgc_size_t token_val_sz;
    bzero(&token_val_sz,sizeof(cgc_size_t));
cgc_size_t token_exp_sz;
    bzero(&token_exp_sz,sizeof(cgc_size_t));
    {cgc_size_t size; size = (cgc_size_t)(sizeof ( TOKEN_USE_HDR ) + 1); }
    {cgc_size_t token_val_sz; token_val_sz = (cgc_size_t)(sizeof ( TOKEN_USE_HDR ) + 1); }
    {cgc_size_t token_exp_sz; token_exp_sz = (cgc_size_t)(sizeof ( TOKEN_USE_HDR ) + 1); }
    {char buffer [ 20 ]; buffer [ ( 20 )-1 ] = (char)(sizeof ( TOKEN_USE_HDR ) + 1); }
    {char * tlv2; tlv2 = (char *)(sizeof ( TOKEN_USE_HDR ) + 1); }
    {unsigned int tlv1; tlv1 = (unsigned int)(sizeof ( TOKEN_USE_HDR ) + 1); }
    {char * tlv4; tlv4 = (char *)(sizeof ( TOKEN_USE_HDR ) + 1); }
    {unsigned int tlv3; tlv3 = (unsigned int)(sizeof ( TOKEN_USE_HDR ) + 1); }
}
void fix_ingred_token_2_0(){
fix_ingred_token_2_0_0();
fix_ingred_token_2_0_1();
fix_ingred_token_2_0_2();
}
void fix_ingred_token_2_1_0(){
char buffer [ 20 ];
    bzero(&buffer,( 20 *sizeof(char) ) );
    {cgc_size_t size; size = (cgc_size_t)(buffer); }
    {cgc_size_t token_val_sz; token_val_sz = (cgc_size_t)(buffer); }
    {cgc_size_t token_exp_sz; token_exp_sz = (cgc_size_t)(buffer); }
    {char buffer [ 20 ]; buffer [ ( 20 )-1 ] = (char)(buffer); }
    {char * tlv2; tlv2 = (char *)(buffer); }
    {unsigned int tlv1; tlv1 = (unsigned int)(buffer); }
    {char * tlv4; tlv4 = (char *)(buffer); }
    {unsigned int tlv3; tlv3 = (unsigned int)(buffer); }
}
void fix_ingred_token_2_1_1(){
char buffer [ 20 ];
    bzero(&buffer,( 20 *sizeof(char) ) );
    {cgc_size_t size; size = (cgc_size_t)(20); }
    {cgc_size_t token_val_sz; token_val_sz = (cgc_size_t)(20); }
    {cgc_size_t token_exp_sz; token_exp_sz = (cgc_size_t)(20); }
    {char buffer [ 20 ]; buffer [ ( 20 )-1 ] = (char)(20); }
    {char * tlv2; tlv2 = (char *)(20); }
    {unsigned int tlv1; tlv1 = (unsigned int)(20); }
    {char * tlv4; tlv4 = (char *)(20); }
    {unsigned int tlv3; tlv3 = (unsigned int)(20); }
}
void fix_ingred_token_2_1(){
fix_ingred_token_2_1_0();
fix_ingred_token_2_1_1();
}
void fix_ingred_token_2_2_0(){
char tlv5_ref;
    bzero(&tlv5_ref,1*sizeof(char));
const char * tlv5 = &tlv5_ref;
    {cgc_size_t size; size = (cgc_size_t)(cgc_strlen ( tlv5 )); }
    {cgc_size_t token_val_sz; token_val_sz = (cgc_size_t)(cgc_strlen ( tlv5 )); }
    {cgc_size_t token_exp_sz; token_exp_sz = (cgc_size_t)(cgc_strlen ( tlv5 )); }
    {char buffer [ 20 ]; buffer [ ( 20 )-1 ] = (char)(cgc_strlen ( tlv5 )); }
    {char * tlv2; tlv2 = (char *)(cgc_strlen ( tlv5 )); }
    {unsigned int tlv1; tlv1 = (unsigned int)(cgc_strlen ( tlv5 )); }
    {char * tlv4; tlv4 = (char *)(cgc_strlen ( tlv5 )); }
    {unsigned int tlv3; tlv3 = (unsigned int)(cgc_strlen ( tlv5 )); }
}
void fix_ingred_token_2_2(){
fix_ingred_token_2_2_0();
}
void fix_ingred_token_2_4_0(){
char tlv6_ref;
    bzero(&tlv6_ref,1*sizeof(char));
const char * tlv6 = &tlv6_ref;
    {cgc_size_t size; size = (cgc_size_t)(cgc_strlen ( tlv6 )); }
    {cgc_size_t token_val_sz; token_val_sz = (cgc_size_t)(cgc_strlen ( tlv6 )); }
    {cgc_size_t token_exp_sz; token_exp_sz = (cgc_size_t)(cgc_strlen ( tlv6 )); }
    {char buffer [ 20 ]; buffer [ ( 20 )-1 ] = (char)(cgc_strlen ( tlv6 )); }
    {char * tlv2; tlv2 = (char *)(cgc_strlen ( tlv6 )); }
    {unsigned int tlv1; tlv1 = (unsigned int)(cgc_strlen ( tlv6 )); }
    {char * tlv4; tlv4 = (char *)(cgc_strlen ( tlv6 )); }
    {unsigned int tlv3; tlv3 = (unsigned int)(cgc_strlen ( tlv6 )); }
}
void fix_ingred_token_2_4(){
fix_ingred_token_2_4_0();
}
void fix_ingred_token_2_5_0(){
char tlv7_ref;
    bzero(&tlv7_ref,1*sizeof(char));
const char * tlv7 = &tlv7_ref;
    {cgc_size_t size; size = (cgc_size_t)(cgc_strlen ( tlv7 ) + 1); }
    {cgc_size_t token_val_sz; token_val_sz = (cgc_size_t)(cgc_strlen ( tlv7 ) + 1); }
    {cgc_size_t token_exp_sz; token_exp_sz = (cgc_size_t)(cgc_strlen ( tlv7 ) + 1); }
    {char buffer [ 20 ]; buffer [ ( 20 )-1 ] = (char)(cgc_strlen ( tlv7 ) + 1); }
    {char * tlv2; tlv2 = (char *)(cgc_strlen ( tlv7 ) + 1); }
    {unsigned int tlv1; tlv1 = (unsigned int)(cgc_strlen ( tlv7 ) + 1); }
    {char * tlv4; tlv4 = (char *)(cgc_strlen ( tlv7 ) + 1); }
    {unsigned int tlv3; tlv3 = (unsigned int)(cgc_strlen ( tlv7 ) + 1); }
}
void fix_ingred_token_2_5(){
fix_ingred_token_2_5_0();
}
void fix_ingred_token_2_6_0(){
char tlv8_ref;
    bzero(&tlv8_ref,1*sizeof(char));
const char * tlv8 = &tlv8_ref;
    {cgc_size_t size; size = (cgc_size_t)(cgc_strlen ( tlv8 ) + 1); }
    {cgc_size_t token_val_sz; token_val_sz = (cgc_size_t)(cgc_strlen ( tlv8 ) + 1); }
    {cgc_size_t token_exp_sz; token_exp_sz = (cgc_size_t)(cgc_strlen ( tlv8 ) + 1); }
    {char buffer [ 20 ]; buffer [ ( 20 )-1 ] = (char)(cgc_strlen ( tlv8 ) + 1); }
    {char * tlv2; tlv2 = (char *)(cgc_strlen ( tlv8 ) + 1); }
    {unsigned int tlv1; tlv1 = (unsigned int)(cgc_strlen ( tlv8 ) + 1); }
    {char * tlv4; tlv4 = (char *)(cgc_strlen ( tlv8 ) + 1); }
    {unsigned int tlv3; tlv3 = (unsigned int)(cgc_strlen ( tlv8 ) + 1); }
}
void fix_ingred_token_2_6(){
fix_ingred_token_2_6_0();
}
void fix_ingred_token_2_7_0(){
char tlv9_ref;
    bzero(&tlv9_ref,1*sizeof(char));
const char * tlv9 = &tlv9_ref;
    {cgc_size_t size; size = (cgc_size_t)(cgc_strlen ( tlv9 )); }
    {cgc_size_t token_val_sz; token_val_sz = (cgc_size_t)(cgc_strlen ( tlv9 )); }
    {cgc_size_t token_exp_sz; token_exp_sz = (cgc_size_t)(cgc_strlen ( tlv9 )); }
    {char buffer [ 20 ]; buffer [ ( 20 )-1 ] = (char)(cgc_strlen ( tlv9 )); }
    {char * tlv2; tlv2 = (char *)(cgc_strlen ( tlv9 )); }
    {unsigned int tlv1; tlv1 = (unsigned int)(cgc_strlen ( tlv9 )); }
    {char * tlv4; tlv4 = (char *)(cgc_strlen ( tlv9 )); }
    {unsigned int tlv3; tlv3 = (unsigned int)(cgc_strlen ( tlv9 )); }
}
void fix_ingred_token_2_7(){
fix_ingred_token_2_7_0();
}
void fix_ingred_token_2(){
fix_ingred_token_2_0();
fix_ingred_token_2_1();
fix_ingred_token_2_2();
fix_ingred_token_2_4();
fix_ingred_token_2_5();
fix_ingred_token_2_6();
fix_ingred_token_2_7();
}
void fix_ingred_token_3_0_0(){
    {char * flag_buf; flag_buf = (char *)(0); }
    {cgc_size_t bytes; bytes = (cgc_size_t)(0); }
    {cgc_size_t tokenSize; tokenSize = (cgc_size_t)(0); }
    {char * buffer; buffer = (char *)(0); }
    {int ret; ret = (int)(0); }
    {void * tlv1; tlv1 = (void *)(0); }
    {void * tlv2; tlv2 = (void *)(0); }
    {int tlv3; tlv3 = (int)(0); }
    {cgc_size_t tlv9; tlv9 = (cgc_size_t)(0); }
    {char * tlv5; tlv5 = (char *)(0); }
    {unsigned int tlv4; tlv4 = (unsigned int)(0); }
    {cgc_size_t tlv10; tlv10 = (cgc_size_t)(0); }
    {char * tlv7; tlv7 = (char *)(0); }
    {unsigned int tlv6; tlv6 = (unsigned int)(0); }
    {int tlv14; tlv14 = (int)(0); }
    {void * tlv13; tlv13 = (void *)(0); }
    {cgc_size_t tlv12; tlv12 = (cgc_size_t)(0); }
    {unsigned int tlv15; tlv15 = (unsigned int)(0); }
    {unsigned int tlv16; tlv16 = (unsigned int)(0); }
}
void fix_ingred_token_3_0(){
fix_ingred_token_3_0_0();
}
void fix_ingred_token_3_2_0(){
cgc_size_t tokenSize;
    bzero(&tokenSize,sizeof(cgc_size_t));
    {char * flag_buf; flag_buf = (char *)(tokenSize); }
    {cgc_size_t bytes; bytes = (cgc_size_t)(tokenSize); }
    {char * buffer; buffer = (char *)(tokenSize); }
    {int ret; ret = (int)(tokenSize); }
    {void * tlv1; tlv1 = (void *)(tokenSize); }
    {void * tlv2; tlv2 = (void *)(tokenSize); }
    {int tlv3; tlv3 = (int)(tokenSize); }
    {cgc_size_t tlv9; tlv9 = (cgc_size_t)(tokenSize); }
    {char * tlv5; tlv5 = (char *)(tokenSize); }
    {unsigned int tlv4; tlv4 = (unsigned int)(tokenSize); }
    {cgc_size_t tlv10; tlv10 = (cgc_size_t)(tokenSize); }
    {char * tlv7; tlv7 = (char *)(tokenSize); }
    {unsigned int tlv6; tlv6 = (unsigned int)(tokenSize); }
    {int tlv14; tlv14 = (int)(tokenSize); }
    {void * tlv13; tlv13 = (void *)(tokenSize); }
    {cgc_size_t tlv12; tlv12 = (cgc_size_t)(tokenSize); }
    {unsigned int tlv15; tlv15 = (unsigned int)(tokenSize); }
    {unsigned int tlv16; tlv16 = (unsigned int)(tokenSize); }
}
void fix_ingred_token_3_2(){
fix_ingred_token_3_2_0();
}
void fix_ingred_token_3_3_1(){
int tlv1_ref;
    bzero(&tlv1_ref,1*sizeof(int));
void * tlv1 = (void*)&tlv1_ref;
    {char * flag_buf; flag_buf = (char *)(tlv1); }
    {cgc_size_t bytes; bytes = (cgc_size_t)(tlv1); }
    {cgc_size_t tokenSize; tokenSize = (cgc_size_t)(tlv1); }
    {char * buffer; buffer = (char *)(tlv1); }
    {int ret; ret = (int)(tlv1); }
    {void * tlv2; tlv2 = (void *)(tlv1); }
    {int tlv3; tlv3 = (int)(tlv1); }
    {cgc_size_t tlv9; tlv9 = (cgc_size_t)(tlv1); }
    {char * tlv5; tlv5 = (char *)(tlv1); }
    {unsigned int tlv4; tlv4 = (unsigned int)(tlv1); }
    {cgc_size_t tlv10; tlv10 = (cgc_size_t)(tlv1); }
    {char * tlv7; tlv7 = (char *)(tlv1); }
    {unsigned int tlv6; tlv6 = (unsigned int)(tlv1); }
    {int tlv14; tlv14 = (int)(tlv1); }
    {void * tlv13; tlv13 = (void *)(tlv1); }
    {cgc_size_t tlv12; tlv12 = (cgc_size_t)(tlv1); }
    {unsigned int tlv15; tlv15 = (unsigned int)(tlv1); }
    {unsigned int tlv16; tlv16 = (unsigned int)(tlv1); }
}
void fix_ingred_token_3_3(){
fix_ingred_token_3_3_1();
}
void fix_ingred_token_3_4_0(){
    {char * flag_buf; flag_buf = (char *)(1); }
    {cgc_size_t bytes; bytes = (cgc_size_t)(1); }
    {cgc_size_t tokenSize; tokenSize = (cgc_size_t)(1); }
    {char * buffer; buffer = (char *)(1); }
    {int ret; ret = (int)(1); }
    {void * tlv1; tlv1 = (void *)(1); }
    {void * tlv2; tlv2 = (void *)(1); }
    {int tlv3; tlv3 = (int)(1); }
    {cgc_size_t tlv9; tlv9 = (cgc_size_t)(1); }
    {char * tlv5; tlv5 = (char *)(1); }
    {unsigned int tlv4; tlv4 = (unsigned int)(1); }
    {cgc_size_t tlv10; tlv10 = (cgc_size_t)(1); }
    {char * tlv7; tlv7 = (char *)(1); }
    {unsigned int tlv6; tlv6 = (unsigned int)(1); }
    {int tlv14; tlv14 = (int)(1); }
    {void * tlv13; tlv13 = (void *)(1); }
    {cgc_size_t tlv12; tlv12 = (cgc_size_t)(1); }
    {unsigned int tlv15; tlv15 = (unsigned int)(1); }
    {unsigned int tlv16; tlv16 = (unsigned int)(1); }
}
void fix_ingred_token_3_4(){
fix_ingred_token_3_4_0();
}
void fix_ingred_token_3_5_0(){
char buffer_ref;
    bzero(&buffer_ref,1*sizeof(char));
char * buffer = &buffer_ref;
cgc_size_t tokenSize;
    bzero(&tokenSize,sizeof(cgc_size_t));
    {char * flag_buf; flag_buf = (char *)(buffer); }
    {cgc_size_t bytes; bytes = (cgc_size_t)(buffer); }
    {cgc_size_t tokenSize; tokenSize = (cgc_size_t)(buffer); }
    {int ret; ret = (int)(buffer); }
    {void * tlv1; tlv1 = (void *)(buffer); }
    {void * tlv2; tlv2 = (void *)(buffer); }
    {int tlv3; tlv3 = (int)(buffer); }
    {cgc_size_t tlv9; tlv9 = (cgc_size_t)(buffer); }
    {char * tlv5; tlv5 = (char *)(buffer); }
    {unsigned int tlv4; tlv4 = (unsigned int)(buffer); }
    {cgc_size_t tlv10; tlv10 = (cgc_size_t)(buffer); }
    {char * tlv7; tlv7 = (char *)(buffer); }
    {unsigned int tlv6; tlv6 = (unsigned int)(buffer); }
    {int tlv14; tlv14 = (int)(buffer); }
    {void * tlv13; tlv13 = (void *)(buffer); }
    {cgc_size_t tlv12; tlv12 = (cgc_size_t)(buffer); }
    {unsigned int tlv15; tlv15 = (unsigned int)(buffer); }
    {unsigned int tlv16; tlv16 = (unsigned int)(buffer); }
}
void fix_ingred_token_3_5_1(){
char buffer_ref;
    bzero(&buffer_ref,1*sizeof(char));
char * buffer = &buffer_ref;
cgc_size_t tokenSize;
    bzero(&tokenSize,sizeof(cgc_size_t));
    {char * flag_buf; flag_buf = (char *)(tokenSize + 1); }
    {cgc_size_t bytes; bytes = (cgc_size_t)(tokenSize + 1); }
    {char * buffer; buffer = (char *)(tokenSize + 1); }
    {int ret; ret = (int)(tokenSize + 1); }
    {void * tlv1; tlv1 = (void *)(tokenSize + 1); }
    {void * tlv2; tlv2 = (void *)(tokenSize + 1); }
    {int tlv3; tlv3 = (int)(tokenSize + 1); }
    {cgc_size_t tlv9; tlv9 = (cgc_size_t)(tokenSize + 1); }
    {char * tlv5; tlv5 = (char *)(tokenSize + 1); }
    {unsigned int tlv4; tlv4 = (unsigned int)(tokenSize + 1); }
    {cgc_size_t tlv10; tlv10 = (cgc_size_t)(tokenSize + 1); }
    {char * tlv7; tlv7 = (char *)(tokenSize + 1); }
    {unsigned int tlv6; tlv6 = (unsigned int)(tokenSize + 1); }
    {int tlv14; tlv14 = (int)(tokenSize + 1); }
    {void * tlv13; tlv13 = (void *)(tokenSize + 1); }
    {cgc_size_t tlv12; tlv12 = (cgc_size_t)(tokenSize + 1); }
    {unsigned int tlv15; tlv15 = (unsigned int)(tokenSize + 1); }
    {unsigned int tlv16; tlv16 = (unsigned int)(tokenSize + 1); }
}
void fix_ingred_token_3_5(){
fix_ingred_token_3_5_0();
fix_ingred_token_3_5_1();
}
void fix_ingred_token_3_6_0(){
    {char * flag_buf; flag_buf = (char *)(64); }
    {cgc_size_t bytes; bytes = (cgc_size_t)(64); }
    {cgc_size_t tokenSize; tokenSize = (cgc_size_t)(64); }
    {char * buffer; buffer = (char *)(64); }
    {int ret; ret = (int)(64); }
    {void * tlv1; tlv1 = (void *)(64); }
    {void * tlv2; tlv2 = (void *)(64); }
    {int tlv3; tlv3 = (int)(64); }
    {cgc_size_t tlv9; tlv9 = (cgc_size_t)(64); }
    {char * tlv5; tlv5 = (char *)(64); }
    {unsigned int tlv4; tlv4 = (unsigned int)(64); }
    {cgc_size_t tlv10; tlv10 = (cgc_size_t)(64); }
    {char * tlv7; tlv7 = (char *)(64); }
    {unsigned int tlv6; tlv6 = (unsigned int)(64); }
    {int tlv14; tlv14 = (int)(64); }
    {void * tlv13; tlv13 = (void *)(64); }
    {cgc_size_t tlv12; tlv12 = (cgc_size_t)(64); }
    {unsigned int tlv15; tlv15 = (unsigned int)(64); }
    {unsigned int tlv16; tlv16 = (unsigned int)(64); }
}
void fix_ingred_token_3_6(){
fix_ingred_token_3_6_0();
}
void fix_ingred_token_3_7_1(){
int tlv2_ref;
    bzero(&tlv2_ref,1*sizeof(int));
void * tlv2 = (void*)&tlv2_ref;
    {char * flag_buf; flag_buf = (char *)(tlv2); }
    {cgc_size_t bytes; bytes = (cgc_size_t)(tlv2); }
    {cgc_size_t tokenSize; tokenSize = (cgc_size_t)(tlv2); }
    {char * buffer; buffer = (char *)(tlv2); }
    {int ret; ret = (int)(tlv2); }
    {void * tlv1; tlv1 = (void *)(tlv2); }
    {int tlv3; tlv3 = (int)(tlv2); }
    {cgc_size_t tlv9; tlv9 = (cgc_size_t)(tlv2); }
    {char * tlv5; tlv5 = (char *)(tlv2); }
    {unsigned int tlv4; tlv4 = (unsigned int)(tlv2); }
    {cgc_size_t tlv10; tlv10 = (cgc_size_t)(tlv2); }
    {char * tlv7; tlv7 = (char *)(tlv2); }
    {unsigned int tlv6; tlv6 = (unsigned int)(tlv2); }
    {int tlv14; tlv14 = (int)(tlv2); }
    {void * tlv13; tlv13 = (void *)(tlv2); }
    {cgc_size_t tlv12; tlv12 = (cgc_size_t)(tlv2); }
    {unsigned int tlv15; tlv15 = (unsigned int)(tlv2); }
    {unsigned int tlv16; tlv16 = (unsigned int)(tlv2); }
}
void fix_ingred_token_3_7(){
fix_ingred_token_3_7_1();
}
void fix_ingred_token_3_8_0(){
char flag_buf_ref;
    bzero(&flag_buf_ref,1*sizeof(char));
char * flag_buf = &flag_buf_ref;
    {cgc_size_t bytes; bytes = (cgc_size_t)(flag_buf); }
    {cgc_size_t tokenSize; tokenSize = (cgc_size_t)(flag_buf); }
    {char * buffer; buffer = (char *)(flag_buf); }
    {int ret; ret = (int)(flag_buf); }
    {void * tlv1; tlv1 = (void *)(flag_buf); }
    {void * tlv2; tlv2 = (void *)(flag_buf); }
    {int tlv3; tlv3 = (int)(flag_buf); }
    {cgc_size_t tlv9; tlv9 = (cgc_size_t)(flag_buf); }
    {char * tlv5; tlv5 = (char *)(flag_buf); }
    {unsigned int tlv4; tlv4 = (unsigned int)(flag_buf); }
    {cgc_size_t tlv10; tlv10 = (cgc_size_t)(flag_buf); }
    {char * tlv7; tlv7 = (char *)(flag_buf); }
    {unsigned int tlv6; tlv6 = (unsigned int)(flag_buf); }
    {int tlv14; tlv14 = (int)(flag_buf); }
    {void * tlv13; tlv13 = (void *)(flag_buf); }
    {cgc_size_t tlv12; tlv12 = (cgc_size_t)(flag_buf); }
    {unsigned int tlv15; tlv15 = (unsigned int)(flag_buf); }
    {unsigned int tlv16; tlv16 = (unsigned int)(flag_buf); }
}
void fix_ingred_token_3_8_1(){
char flag_buf_ref;
    bzero(&flag_buf_ref,1*sizeof(char));
char * flag_buf = &flag_buf_ref;
    {char * flag_buf; flag_buf = (char *)(64); }
    {cgc_size_t bytes; bytes = (cgc_size_t)(64); }
    {cgc_size_t tokenSize; tokenSize = (cgc_size_t)(64); }
    {char * buffer; buffer = (char *)(64); }
    {int ret; ret = (int)(64); }
    {void * tlv1; tlv1 = (void *)(64); }
    {void * tlv2; tlv2 = (void *)(64); }
    {int tlv3; tlv3 = (int)(64); }
    {cgc_size_t tlv9; tlv9 = (cgc_size_t)(64); }
    {char * tlv5; tlv5 = (char *)(64); }
    {unsigned int tlv4; tlv4 = (unsigned int)(64); }
    {cgc_size_t tlv10; tlv10 = (cgc_size_t)(64); }
    {char * tlv7; tlv7 = (char *)(64); }
    {unsigned int tlv6; tlv6 = (unsigned int)(64); }
    {int tlv14; tlv14 = (int)(64); }
    {void * tlv13; tlv13 = (void *)(64); }
    {cgc_size_t tlv12; tlv12 = (cgc_size_t)(64); }
    {unsigned int tlv15; tlv15 = (unsigned int)(64); }
    {unsigned int tlv16; tlv16 = (unsigned int)(64); }
}
void fix_ingred_token_3_8(){
fix_ingred_token_3_8_0();
fix_ingred_token_3_8_1();
}
void fix_ingred_token_3_9_1(){
unsigned int i;
    bzero(&i,sizeof(unsigned int));
    {char * flag_buf; flag_buf = (char *)(i); }
    {cgc_size_t bytes; bytes = (cgc_size_t)(i); }
    {cgc_size_t tokenSize; tokenSize = (cgc_size_t)(i); }
    {char * buffer; buffer = (char *)(i); }
    {int ret; ret = (int)(i); }
    {void * tlv1; tlv1 = (void *)(i); }
    {void * tlv2; tlv2 = (void *)(i); }
    {int tlv3; tlv3 = (int)(i); }
    {cgc_size_t tlv9; tlv9 = (cgc_size_t)(i); }
    {char * tlv5; tlv5 = (char *)(i); }
    {unsigned int tlv4; tlv4 = (unsigned int)(i); }
    {cgc_size_t tlv10; tlv10 = (cgc_size_t)(i); }
    {char * tlv7; tlv7 = (char *)(i); }
    {unsigned int tlv6; tlv6 = (unsigned int)(i); }
    {int tlv14; tlv14 = (int)(i); }
    {void * tlv13; tlv13 = (void *)(i); }
    {cgc_size_t tlv12; tlv12 = (cgc_size_t)(i); }
    {unsigned int tlv15; tlv15 = (unsigned int)(i); }
    {unsigned int tlv16; tlv16 = (unsigned int)(i); }
}
void fix_ingred_token_3_9_2(){
unsigned int i;
    bzero(&i,sizeof(unsigned int));
    {char * flag_buf; flag_buf = (char *)(10); }
    {cgc_size_t bytes; bytes = (cgc_size_t)(10); }
    {cgc_size_t tokenSize; tokenSize = (cgc_size_t)(10); }
    {char * buffer; buffer = (char *)(10); }
    {int ret; ret = (int)(10); }
    {void * tlv1; tlv1 = (void *)(10); }
    {void * tlv2; tlv2 = (void *)(10); }
    {int tlv3; tlv3 = (int)(10); }
    {cgc_size_t tlv9; tlv9 = (cgc_size_t)(10); }
    {char * tlv5; tlv5 = (char *)(10); }
    {unsigned int tlv4; tlv4 = (unsigned int)(10); }
    {cgc_size_t tlv10; tlv10 = (cgc_size_t)(10); }
    {char * tlv7; tlv7 = (char *)(10); }
    {unsigned int tlv6; tlv6 = (unsigned int)(10); }
    {int tlv14; tlv14 = (int)(10); }
    {void * tlv13; tlv13 = (void *)(10); }
    {cgc_size_t tlv12; tlv12 = (cgc_size_t)(10); }
    {unsigned int tlv15; tlv15 = (unsigned int)(10); }
    {unsigned int tlv16; tlv16 = (unsigned int)(10); }
}
void fix_ingred_token_3_9(){
fix_ingred_token_3_9_1();
fix_ingred_token_3_9_2();
}
void fix_ingred_token_3_10_0(){
char tlv11_ref;
    bzero(&tlv11_ref,1*sizeof(char));
const char * tlv11 = &tlv11_ref;
    {char * flag_buf; flag_buf = (char *)(cgc_strlen ( tlv11 )); }
    {cgc_size_t bytes; bytes = (cgc_size_t)(cgc_strlen ( tlv11 )); }
    {cgc_size_t tokenSize; tokenSize = (cgc_size_t)(cgc_strlen ( tlv11 )); }
    {char * buffer; buffer = (char *)(cgc_strlen ( tlv11 )); }
    {int ret; ret = (int)(cgc_strlen ( tlv11 )); }
    {void * tlv1; tlv1 = (void *)(cgc_strlen ( tlv11 )); }
    {void * tlv2; tlv2 = (void *)(cgc_strlen ( tlv11 )); }
    {int tlv3; tlv3 = (int)(cgc_strlen ( tlv11 )); }
    {cgc_size_t tlv9; tlv9 = (cgc_size_t)(cgc_strlen ( tlv11 )); }
    {char * tlv5; tlv5 = (char *)(cgc_strlen ( tlv11 )); }
    {unsigned int tlv4; tlv4 = (unsigned int)(cgc_strlen ( tlv11 )); }
    {cgc_size_t tlv10; tlv10 = (cgc_size_t)(cgc_strlen ( tlv11 )); }
    {char * tlv7; tlv7 = (char *)(cgc_strlen ( tlv11 )); }
    {unsigned int tlv6; tlv6 = (unsigned int)(cgc_strlen ( tlv11 )); }
    {int tlv14; tlv14 = (int)(cgc_strlen ( tlv11 )); }
    {void * tlv13; tlv13 = (void *)(cgc_strlen ( tlv11 )); }
    {cgc_size_t tlv12; tlv12 = (cgc_size_t)(cgc_strlen ( tlv11 )); }
    {unsigned int tlv15; tlv15 = (unsigned int)(cgc_strlen ( tlv11 )); }
    {unsigned int tlv16; tlv16 = (unsigned int)(cgc_strlen ( tlv11 )); }
}
void fix_ingred_token_3_10(){
fix_ingred_token_3_10_0();
}
void fix_ingred_token_3_11_0(){
char buffer_ref;
    bzero(&buffer_ref,1*sizeof(char));
char * buffer = &buffer_ref;
    {char * flag_buf; flag_buf = (char *)(STDOUT); }
    {cgc_size_t bytes; bytes = (cgc_size_t)(STDOUT); }
    {cgc_size_t tokenSize; tokenSize = (cgc_size_t)(STDOUT); }
    {char * buffer; buffer = (char *)(STDOUT); }
    {int ret; ret = (int)(STDOUT); }
    {void * tlv1; tlv1 = (void *)(STDOUT); }
    {void * tlv2; tlv2 = (void *)(STDOUT); }
    {int tlv3; tlv3 = (int)(STDOUT); }
    {cgc_size_t tlv9; tlv9 = (cgc_size_t)(STDOUT); }
    {char * tlv5; tlv5 = (char *)(STDOUT); }
    {unsigned int tlv4; tlv4 = (unsigned int)(STDOUT); }
    {cgc_size_t tlv10; tlv10 = (cgc_size_t)(STDOUT); }
    {char * tlv7; tlv7 = (char *)(STDOUT); }
    {unsigned int tlv6; tlv6 = (unsigned int)(STDOUT); }
    {int tlv14; tlv14 = (int)(STDOUT); }
    {void * tlv13; tlv13 = (void *)(STDOUT); }
    {cgc_size_t tlv12; tlv12 = (cgc_size_t)(STDOUT); }
    {unsigned int tlv15; tlv15 = (unsigned int)(STDOUT); }
    {unsigned int tlv16; tlv16 = (unsigned int)(STDOUT); }
}
void fix_ingred_token_3_11_1(){
char buffer_ref;
    bzero(&buffer_ref,1*sizeof(char));
char * buffer = &buffer_ref;
    {char * flag_buf; flag_buf = (char *)(buffer); }
    {cgc_size_t bytes; bytes = (cgc_size_t)(buffer); }
    {cgc_size_t tokenSize; tokenSize = (cgc_size_t)(buffer); }
    {int ret; ret = (int)(buffer); }
    {void * tlv1; tlv1 = (void *)(buffer); }
    {void * tlv2; tlv2 = (void *)(buffer); }
    {int tlv3; tlv3 = (int)(buffer); }
    {cgc_size_t tlv9; tlv9 = (cgc_size_t)(buffer); }
    {char * tlv5; tlv5 = (char *)(buffer); }
    {unsigned int tlv4; tlv4 = (unsigned int)(buffer); }
    {cgc_size_t tlv10; tlv10 = (cgc_size_t)(buffer); }
    {char * tlv7; tlv7 = (char *)(buffer); }
    {unsigned int tlv6; tlv6 = (unsigned int)(buffer); }
    {int tlv14; tlv14 = (int)(buffer); }
    {void * tlv13; tlv13 = (void *)(buffer); }
    {cgc_size_t tlv12; tlv12 = (cgc_size_t)(buffer); }
    {unsigned int tlv15; tlv15 = (unsigned int)(buffer); }
    {unsigned int tlv16; tlv16 = (unsigned int)(buffer); }
}
void fix_ingred_token_3_11(){
fix_ingred_token_3_11_0();
fix_ingred_token_3_11_1();
}
void fix_ingred_token_3_12_1(){
int tlv3;
    bzero(&tlv3,sizeof(int));
    {char * flag_buf; flag_buf = (char *)(tlv3); }
    {cgc_size_t bytes; bytes = (cgc_size_t)(tlv3); }
    {cgc_size_t tokenSize; tokenSize = (cgc_size_t)(tlv3); }
    {char * buffer; buffer = (char *)(tlv3); }
    {int ret; ret = (int)(tlv3); }
    {void * tlv1; tlv1 = (void *)(tlv3); }
    {void * tlv2; tlv2 = (void *)(tlv3); }
    {cgc_size_t tlv9; tlv9 = (cgc_size_t)(tlv3); }
    {char * tlv5; tlv5 = (char *)(tlv3); }
    {unsigned int tlv4; tlv4 = (unsigned int)(tlv3); }
    {cgc_size_t tlv10; tlv10 = (cgc_size_t)(tlv3); }
    {char * tlv7; tlv7 = (char *)(tlv3); }
    {unsigned int tlv6; tlv6 = (unsigned int)(tlv3); }
    {int tlv14; tlv14 = (int)(tlv3); }
    {void * tlv13; tlv13 = (void *)(tlv3); }
    {cgc_size_t tlv12; tlv12 = (cgc_size_t)(tlv3); }
    {unsigned int tlv15; tlv15 = (unsigned int)(tlv3); }
    {unsigned int tlv16; tlv16 = (unsigned int)(tlv3); }
}
void fix_ingred_token_3_12(){
fix_ingred_token_3_12_1();
}
void fix_ingred_token_3(){
fix_ingred_token_3_0();
fix_ingred_token_3_2();
fix_ingred_token_3_3();
fix_ingred_token_3_4();
fix_ingred_token_3_5();
fix_ingred_token_3_6();
fix_ingred_token_3_7();
fix_ingred_token_3_8();
fix_ingred_token_3_9();
fix_ingred_token_3_10();
fix_ingred_token_3_11();
fix_ingred_token_3_12();
}
void fix_ingred_token_4(){
}
void fix_ingred_token_5(){
}
void fix_ingred_token_6(){
}
void fix_ingred_token_7_1_0(){
    {char * command; command = (char *)(sizeof ( Token )); }
    {char * val_str; val_str = (char *)(sizeof ( Token )); }
    {cgc_size_t size; size = (cgc_size_t)(sizeof ( Token )); }
    {void * tlv1; tlv1 = (void *)(sizeof ( Token )); }
    {cgc_size_t tlv10; tlv10 = (cgc_size_t)(sizeof ( Token )); }
    {char * tlv3; tlv3 = (char *)(sizeof ( Token )); }
    {unsigned int tlv2; tlv2 = (unsigned int)(sizeof ( Token )); }
    {unsigned int tlv11; tlv11 = (unsigned int)(sizeof ( Token )); }
    {unsigned int tlv12; tlv12 = (unsigned int)(sizeof ( Token )); }
}
void fix_ingred_token_7_1(){
fix_ingred_token_7_1_0();
}
void fix_ingred_token_7_3_0(){
    {char * command; command = (char *)(1); }
    {char * val_str; val_str = (char *)(1); }
    {cgc_size_t size; size = (cgc_size_t)(1); }
    {char * tlv3; tlv3 = (char *)(1); }
    {unsigned int tlv2; tlv2 = (unsigned int)(1); }
    {unsigned int tlv11; tlv11 = (unsigned int)(1); }
    {unsigned int tlv12; tlv12 = (unsigned int)(1); }
}
void fix_ingred_token_7_3(){
fix_ingred_token_7_3_0();
}
void fix_ingred_token_7_4_0(){
Token token_ref;
    bzero(&token_ref,1*sizeof(Token));
Token * token = &token_ref;
    {char * command; command = (char *)(( char * ) token); }
    {char * val_str; val_str = (char *)(( char * ) token); }
    {cgc_size_t size; size = (cgc_size_t)(( char * ) token); }
    {void * tlv1; tlv1 = (void *)(( char * ) token); }
    {cgc_size_t tlv10; tlv10 = (cgc_size_t)(( char * ) token); }
    {char * tlv3; tlv3 = (char *)(( char * ) token); }
    {unsigned int tlv2; tlv2 = (unsigned int)(( char * ) token); }
    {unsigned int tlv11; tlv11 = (unsigned int)(( char * ) token); }
    {unsigned int tlv12; tlv12 = (unsigned int)(( char * ) token); }
}
void fix_ingred_token_7_4_1(){
Token token_ref;
    bzero(&token_ref,1*sizeof(Token));
Token * token = &token_ref;
    {char * command; command = (char *)(sizeof ( Token )); }
    {char * val_str; val_str = (char *)(sizeof ( Token )); }
    {cgc_size_t size; size = (cgc_size_t)(sizeof ( Token )); }
    {void * tlv1; tlv1 = (void *)(sizeof ( Token )); }
    {cgc_size_t tlv10; tlv10 = (cgc_size_t)(sizeof ( Token )); }
    {char * tlv3; tlv3 = (char *)(sizeof ( Token )); }
    {unsigned int tlv2; tlv2 = (unsigned int)(sizeof ( Token )); }
    {unsigned int tlv11; tlv11 = (unsigned int)(sizeof ( Token )); }
    {unsigned int tlv12; tlv12 = (unsigned int)(sizeof ( Token )); }
}
void fix_ingred_token_7_4(){
fix_ingred_token_7_4_0();
fix_ingred_token_7_4_1();
}
void fix_ingred_token_7(){
fix_ingred_token_7_1();
fix_ingred_token_7_3();
fix_ingred_token_7_4();
}
void fix_ingred_token_8_1_0(){
char body_ref;
    bzero(&body_ref,1*sizeof(char));
char * body = &body_ref;
    {char * tlv3; tlv3 = (char *)(body); }
    {unsigned int tlv6; tlv6 = (unsigned int)(body); }
}
void fix_ingred_token_8_1(){
fix_ingred_token_8_1_0();
}
void fix_ingred_token_8_6_0(){
int id;
    bzero(&id,sizeof(int));
    {char * tlv3; tlv3 = (char *)(id); }
    {unsigned int tlv6; tlv6 = (unsigned int)(id); }
}
void fix_ingred_token_8_6(){
fix_ingred_token_8_6_0();
}
void fix_ingred_token_8(){
fix_ingred_token_8_1();
fix_ingred_token_8_6();
}
void fix_ingred_token_9_1_0(){
char body_ref;
    bzero(&body_ref,1*sizeof(char));
char * body = &body_ref;
    {cgc_size_t bytes; bytes = (cgc_size_t)(body); }
    {int ret; ret = (int)(body); }
    {char * tlv4; tlv4 = (char *)(body); }
    {unsigned int tlv3; tlv3 = (unsigned int)(body); }
}
void fix_ingred_token_9_1(){
fix_ingred_token_9_1_0();
}
void fix_ingred_token_9_3_0(){
int id;
    bzero(&id,sizeof(int));
    {cgc_size_t bytes; bytes = (cgc_size_t)(id); }
    {int ret; ret = (int)(id); }
    {char * tlv4; tlv4 = (char *)(id); }
    {unsigned int tlv3; tlv3 = (unsigned int)(id); }
}
void fix_ingred_token_9_3(){
fix_ingred_token_9_3_0();
}
void fix_ingred_token_9(){
fix_ingred_token_9_1();
fix_ingred_token_9_3();
}
void fix_ingred_token_10_2_0(){
char useList_ref;
    bzero(&useList_ref,1*sizeof(char));
char * useList = &useList_ref;
    {char * use; use = (char *)(useList); }
    {cgc_size_t size; size = (cgc_size_t)(useList); }
    {cgc_size_t size1; size1 = (cgc_size_t)(useList); }
    {cgc_size_t size2; size2 = (cgc_size_t)(useList); }
    {char * tlv4; tlv4 = (char *)(useList); }
    {int tlv1; tlv1 = (int)(useList); }
    {int tlv2; tlv2 = (int)(useList); }
    {cgc_size_t tlv7; tlv7 = (cgc_size_t)(useList); }
    {cgc_size_t tlv10; tlv10 = (cgc_size_t)(useList); }
    {char * tlv14; tlv14 = (char *)(useList); }
}
void fix_ingred_token_10_2(){
fix_ingred_token_10_2_0();
}
void fix_ingred_token_10_4_0(){
cgc_size_t size1;
    bzero(&size1,sizeof(cgc_size_t));
cgc_size_t size2;
    bzero(&size2,sizeof(cgc_size_t));
    {char * use; use = (char *)(size1 > size2 ? size1 : size2); }
    {cgc_size_t size; size = (cgc_size_t)(size1 > size2 ? size1 : size2); }
    {char * tlv4; tlv4 = (char *)(size1 > size2 ? size1 : size2); }
    {int tlv1; tlv1 = (int)(size1 > size2 ? size1 : size2); }
    {int tlv2; tlv2 = (int)(size1 > size2 ? size1 : size2); }
    {cgc_size_t tlv7; tlv7 = (cgc_size_t)(size1 > size2 ? size1 : size2); }
    {cgc_size_t tlv10; tlv10 = (cgc_size_t)(size1 > size2 ? size1 : size2); }
    {char * tlv14; tlv14 = (char *)(size1 > size2 ? size1 : size2); }
}
void fix_ingred_token_10_4_1(){
cgc_size_t size1;
    bzero(&size1,sizeof(cgc_size_t));
cgc_size_t size2;
    bzero(&size2,sizeof(cgc_size_t));
    {char * use; use = (char *)(size1); }
    {cgc_size_t size; size = (cgc_size_t)(size1); }
    {cgc_size_t size2; size2 = (cgc_size_t)(size1); }
    {char * tlv4; tlv4 = (char *)(size1); }
    {int tlv1; tlv1 = (int)(size1); }
    {int tlv2; tlv2 = (int)(size1); }
    {cgc_size_t tlv7; tlv7 = (cgc_size_t)(size1); }
    {cgc_size_t tlv10; tlv10 = (cgc_size_t)(size1); }
    {char * tlv14; tlv14 = (char *)(size1); }
}
void fix_ingred_token_10_4_2(){
cgc_size_t size1;
    bzero(&size1,sizeof(cgc_size_t));
cgc_size_t size2;
    bzero(&size2,sizeof(cgc_size_t));
    {char * use; use = (char *)(size2); }
    {cgc_size_t size; size = (cgc_size_t)(size2); }
    {cgc_size_t size1; size1 = (cgc_size_t)(size2); }
    {char * tlv4; tlv4 = (char *)(size2); }
    {int tlv1; tlv1 = (int)(size2); }
    {int tlv2; tlv2 = (int)(size2); }
    {cgc_size_t tlv7; tlv7 = (cgc_size_t)(size2); }
    {cgc_size_t tlv10; tlv10 = (cgc_size_t)(size2); }
    {char * tlv14; tlv14 = (char *)(size2); }
}
void fix_ingred_token_10_4(){
fix_ingred_token_10_4_0();
fix_ingred_token_10_4_1();
fix_ingred_token_10_4_2();
}
void fix_ingred_token_10_5_0(){
char tlv5_ref;
    bzero(&tlv5_ref,1*sizeof(char));
const char * tlv5 = &tlv5_ref;
    {char * use; use = (char *)(cgc_strlen ( tlv5 )); }
    {cgc_size_t size1; size1 = (cgc_size_t)(cgc_strlen ( tlv5 )); }
    {cgc_size_t size2; size2 = (cgc_size_t)(cgc_strlen ( tlv5 )); }
    {int tlv1; tlv1 = (int)(cgc_strlen ( tlv5 )); }
    {int tlv2; tlv2 = (int)(cgc_strlen ( tlv5 )); }
    {cgc_size_t tlv7; tlv7 = (cgc_size_t)(cgc_strlen ( tlv5 )); }
    {cgc_size_t tlv10; tlv10 = (cgc_size_t)(cgc_strlen ( tlv5 )); }
    {char * tlv14; tlv14 = (char *)(cgc_strlen ( tlv5 )); }
}
void fix_ingred_token_10_5(){
fix_ingred_token_10_5_0();
}
void fix_ingred_token_10_6_0(){
char tlv6_ref;
    bzero(&tlv6_ref,1*sizeof(char));
const char * tlv6 = &tlv6_ref;
    {char * use; use = (char *)(cgc_strlen ( tlv6 )); }
    {cgc_size_t size1; size1 = (cgc_size_t)(cgc_strlen ( tlv6 )); }
    {cgc_size_t size2; size2 = (cgc_size_t)(cgc_strlen ( tlv6 )); }
    {int tlv1; tlv1 = (int)(cgc_strlen ( tlv6 )); }
    {int tlv2; tlv2 = (int)(cgc_strlen ( tlv6 )); }
    {cgc_size_t tlv7; tlv7 = (cgc_size_t)(cgc_strlen ( tlv6 )); }
    {cgc_size_t tlv10; tlv10 = (cgc_size_t)(cgc_strlen ( tlv6 )); }
    {char * tlv14; tlv14 = (char *)(cgc_strlen ( tlv6 )); }
}
void fix_ingred_token_10_6(){
fix_ingred_token_10_6_0();
}
void fix_ingred_token_10_8_0(){
char tlv15_ref;
    bzero(&tlv15_ref,1*sizeof(char));
const char * tlv15 = &tlv15_ref;
    {char * use; use = (char *)(cgc_strlen ( tlv15 )); }
    {cgc_size_t size; size = (cgc_size_t)(cgc_strlen ( tlv15 )); }
    {cgc_size_t size1; size1 = (cgc_size_t)(cgc_strlen ( tlv15 )); }
    {cgc_size_t size2; size2 = (cgc_size_t)(cgc_strlen ( tlv15 )); }
    {char * tlv4; tlv4 = (char *)(cgc_strlen ( tlv15 )); }
    {char * tlv14; tlv14 = (char *)(cgc_strlen ( tlv15 )); }
}
void fix_ingred_token_10_8(){
fix_ingred_token_10_8_0();
}
void fix_ingred_token_10_10_0(){
char tlv16_ref;
    bzero(&tlv16_ref,1*sizeof(char));
const char * tlv16 = &tlv16_ref;
    {char * use; use = (char *)(cgc_strlen ( tlv16 )); }
    {cgc_size_t size; size = (cgc_size_t)(cgc_strlen ( tlv16 )); }
    {cgc_size_t size1; size1 = (cgc_size_t)(cgc_strlen ( tlv16 )); }
    {cgc_size_t size2; size2 = (cgc_size_t)(cgc_strlen ( tlv16 )); }
    {char * tlv4; tlv4 = (char *)(cgc_strlen ( tlv16 )); }
    {int tlv1; tlv1 = (int)(cgc_strlen ( tlv16 )); }
    {int tlv2; tlv2 = (int)(cgc_strlen ( tlv16 )); }
    {cgc_size_t tlv7; tlv7 = (cgc_size_t)(cgc_strlen ( tlv16 )); }
    {cgc_size_t tlv10; tlv10 = (cgc_size_t)(cgc_strlen ( tlv16 )); }
    {char * tlv14; tlv14 = (char *)(cgc_strlen ( tlv16 )); }
}
void fix_ingred_token_10_10(){
fix_ingred_token_10_10_0();
}
void fix_ingred_token_10_12_0(){
    {char * use; use = (char *)(0); }
    {cgc_size_t size; size = (cgc_size_t)(0); }
    {cgc_size_t size1; size1 = (cgc_size_t)(0); }
    {cgc_size_t size2; size2 = (cgc_size_t)(0); }
    {char * tlv4; tlv4 = (char *)(0); }
    {int tlv1; tlv1 = (int)(0); }
    {int tlv2; tlv2 = (int)(0); }
    {cgc_size_t tlv7; tlv7 = (cgc_size_t)(0); }
    {char * tlv14; tlv14 = (char *)(0); }
}
void fix_ingred_token_10_12(){
fix_ingred_token_10_12_0();
}
void fix_ingred_token_10(){
fix_ingred_token_10_2();
fix_ingred_token_10_4();
fix_ingred_token_10_5();
fix_ingred_token_10_6();
fix_ingred_token_10_8();
fix_ingred_token_10_10();
fix_ingred_token_10_12();
}
void fix_ingred_token_11_1_0(){
char body_ref;
    bzero(&body_ref,1*sizeof(char));
char * body = &body_ref;
    {cgc_size_t size; size = (cgc_size_t)(body); }
    {int tlv2; tlv2 = (int)(body); }
}
void fix_ingred_token_11_1(){
fix_ingred_token_11_1_0();
}
void fix_ingred_token_11(){
fix_ingred_token_11_1();
}
