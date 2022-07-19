

#include "cgc_service.h"
#include "cgc_cbstring.h"
#include "cgc_cbstdio.h"
#include "cgc_atox.h"
#include "libcgc.h"
#include "cgc_comms.h"
#include "cgc_memcpy.h"
#include "cgc_malloc.h"
#include "cgc_strtok.h"
#include "cgc_atoi.h"
#include "cgc_strncmp.h"
#include "cgc_certificate.h"
#include "cgc_token.h"
#include "cgc_util.h"
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

void fix_ingred_service_0_1_0();
void fix_ingred_service_0_1();
void fix_ingred_service_0_3_0();
void fix_ingred_service_0_3_1();
void fix_ingred_service_0_3();
void fix_ingred_service_0_4_0();
void fix_ingred_service_0_4();
void fix_ingred_service_0_5_0();
void fix_ingred_service_0_5();
void fix_ingred_service_0_7_0();
void fix_ingred_service_0_7_1();
void fix_ingred_service_0_7();
void fix_ingred_service_0_8_0();
void fix_ingred_service_0_8_1();
void fix_ingred_service_0_8_2();
void fix_ingred_service_0_8();
void fix_ingred_service_0();
void cgc_addService(Service ** services, char *name, void (*callback) (int, char *, unsigned int *))
{
if (fix_ingred_enable){ fix_ingred_service_0(); };
    cgc_size_t size;
    Service *newService;
    void* tlv1;
    {
        cgc_size_t tlv10;
        tlv10 = sizeof ( Service );
        tlv1 = cgc_malloc(tlv10);
    }
    if (!(newService = tlv1)) {
	cgc__terminate(ALLOCATE_ERROR);
    }
    {
        char* tlv4;
         tlv4 = ( char * ) newService;
        unsigned int tlv3;
        tlv3 = sizeof ( Service );
        cgc_bzero(tlv4,tlv3);
    }
    newService->callback = callback;
    {
        const char* tlv11 = name;
        size = cgc_strlen(tlv11);
    }
    void* tlv2;
    {
        cgc_size_t tlv12;
        tlv12 = size + 1;
        tlv2 = cgc_malloc(tlv12);
    }
    if (!(newService->name = tlv2)) {
	cgc__terminate(ALLOCATE_ERROR);
    }
    {
        char* tlv6;
         tlv6 = newService -> name;
        unsigned int tlv5;
        tlv5 = size + 1;
        cgc_bzero(tlv6,tlv5);
    }
    {
        void* tlv9;
        tlv9 = newService -> name;
        void* tlv8;
        tlv8 = name;
        cgc_size_t tlv7;
        tlv7 = size;
        cgc_memcpy(tlv9,tlv8,tlv7);
    }
    newService->next = *services;
    *services = newService;
}

void fix_ingred_service_1_1_1();
void fix_ingred_service_1_1();
void fix_ingred_service_1_2_1();
void fix_ingred_service_1_2();
void fix_ingred_service_1_3_1();
void fix_ingred_service_1_3();
void fix_ingred_service_1_4_1();
void fix_ingred_service_1_4();
void fix_ingred_service_1_5_1();
void fix_ingred_service_1_5();
void fix_ingred_service_1_6_1();
void fix_ingred_service_1_6();
void fix_ingred_service_1_7_1();
void fix_ingred_service_1_7();
void fix_ingred_service_1();
void cgc_initServices(Service ** services)
{
if (fix_ingred_enable){ fix_ingred_service_1(); };
    {
        Service** tlv3;
        tlv3 = services;
        char* tlv2;
         tlv2 = TOKEN_CMD;
        void* tlv1 = cgc_requestToken;
        cgc_addService(tlv3,tlv2,tlv1);
    }
    {
        Service** tlv6;
        tlv6 = services;
        char* tlv5;
         tlv5 = ENROLL_CMD;
        void* tlv4 = cgc_enroll;
        cgc_addService(tlv6,tlv5,tlv4);
    }
    {
        Service** tlv9;
        tlv9 = services;
        char* tlv8;
         tlv8 = REENROLL_CMD;
        void* tlv7 = cgc_reenroll;
        cgc_addService(tlv9,tlv8,tlv7);
    }
    {
        Service** tlv12;
        tlv12 = services;
        char* tlv11;
         tlv11 = CERTS_CMD;
        void* tlv10 = cgc_crls;
        cgc_addService(tlv12,tlv11,tlv10);
    }
    {
        Service** tlv15;
        tlv15 = services;
        char* tlv14;
         tlv14 = REVOKE_CERT_CMD;
        void* tlv13 = cgc_revokeCert;
        cgc_addService(tlv15,tlv14,tlv13);
    }
    {
        Service** tlv18;
        tlv18 = services;
        char* tlv17;
         tlv17 = REVOKE_TOKEN_CMD;
        void* tlv16 = cgc_revokeToken;
        cgc_addService(tlv18,tlv17,tlv16);
    }
    {
        Service** tlv21;
        tlv21 = services;
        char* tlv20;
         tlv20 = REFRESH_CMD;
        void* tlv19 = cgc_refreshToken;
        cgc_addService(tlv21,tlv20,tlv19);
    }
}

void fix_ingred_service_2_1_0();
void fix_ingred_service_2_1();
void fix_ingred_service_2_2_0();
void fix_ingred_service_2_2();
void fix_ingred_service_2();
void cgc_freeMessage(Message * message)
{
if (fix_ingred_enable){ fix_ingred_service_2(); };
    {
        void* tlv1;
        tlv1 = message -> credential;
        cgc_free(tlv1);
    }
    {
        void* tlv2;
        tlv2 = message -> body;
        cgc_free(tlv2);
    }
    cgc_free(message);
}

void fix_ingred_service_3_1_0();
void fix_ingred_service_3_1_1();
void fix_ingred_service_3_1();
void fix_ingred_service_3_2_0();
void fix_ingred_service_3_2();
void fix_ingred_service_3_4_0();
void fix_ingred_service_3_4_1();
void fix_ingred_service_3_4();
void fix_ingred_service_3_6_0();
void fix_ingred_service_3_6();
void fix_ingred_service_3_7_0();
void fix_ingred_service_3_7_2();
void fix_ingred_service_3_7_3();
void fix_ingred_service_3_7();
void fix_ingred_service_3_9_0();
void fix_ingred_service_3_9();
void fix_ingred_service_3_12_0();
void fix_ingred_service_3_12();
void fix_ingred_service_3_13_0();
void fix_ingred_service_3_13_1();
void fix_ingred_service_3_13();
void fix_ingred_service_3_14_0();
void fix_ingred_service_3_14();
void fix_ingred_service_3_16_0();
void fix_ingred_service_3_16_1();
void fix_ingred_service_3_16();
void fix_ingred_service_3_17_0();
void fix_ingred_service_3_17_1();
void fix_ingred_service_3_17();
void fix_ingred_service_3_18_0();
void fix_ingred_service_3_18();
void fix_ingred_service_3_20_0();
void fix_ingred_service_3_20();
void fix_ingred_service_3_21_0();
void fix_ingred_service_3_21();
void fix_ingred_service_3_22_0();
void fix_ingred_service_3_22_1();
void fix_ingred_service_3_22();
void fix_ingred_service_3_25_0();
void fix_ingred_service_3_25();
void fix_ingred_service_3_29_0();
void fix_ingred_service_3_29();
void fix_ingred_service_3_32_0();
void fix_ingred_service_3_32();
void fix_ingred_service_3_33_0();
void fix_ingred_service_3_33_1();
void fix_ingred_service_3_33();
void fix_ingred_service_3_36_0();
void fix_ingred_service_3_36();
void fix_ingred_service_3_39_0();
void fix_ingred_service_3_39();
void fix_ingred_service_3_40_0();
void fix_ingred_service_3_40_1();
void fix_ingred_service_3_40();
void fix_ingred_service_3();
Message *cgc_getMessage()
{
if (fix_ingred_enable){ fix_ingred_service_3(); };
    cgc_size_t bytes;
    cgc_size_t size;
    Message *message;
    char *cmd_str;
    char *auth_str;
    char *id_str;
    char *cred_str;
    char *body_str;
    char buffer[1024];
    {
        char* tlv7;
         tlv7 = buffer;
        unsigned int tlv6;
        tlv6 = 1024;
        cgc_bzero(tlv7,tlv6);
    }
    void* tlv1;
    {
        cgc_size_t tlv23;
        tlv23 = sizeof ( Message );
        tlv1 = cgc_malloc(tlv23);
    }
    if (!(message = tlv1)) {
	cgc__terminate(ALLOCATE_ERROR);
    }
    {
        char* tlv9;
         tlv9 = ( char * ) message;
        unsigned int tlv8;
        tlv8 = sizeof ( Message );
        cgc_bzero(tlv9,tlv8);
    }
    if (!message) {
 {
     unsigned int tlv44;
     tlv44 = 1;
    	cgc__terminate(tlv44);
 }
    }
    int tlv2;
    {
        unsigned int tlv28;
        tlv28 = STDIN;
        char* tlv27;
         tlv27 = buffer;
        char tlv26;
        tlv26 = '!';
        cgc_size_t tlv25;
        tlv25 = sizeof ( buffer );
        cgc_size_t* tlv24;
        tlv24 = & bytes;
        tlv2 = cgc_read_until_delim_or_n(tlv28,tlv27,tlv26,tlv25,tlv24);
    }
    if (tlv2) {
 {
     unsigned int tlv45;
     tlv45 = 2;
    	cgc__terminate(tlv45);
 }
    }
    {
        char* tlv30;
         tlv30 = buffer;
        const char tlv29 [ ] = ",";
        cmd_str = cgc_strtok(tlv30,tlv29);
    }
    if (!cmd_str) {
	return NULL;
    }
    {
        const char* tlv31 = cmd_str;
        size = cgc_strlen(tlv31);
    }
    if (size > MAX_CMD_SIZE) {
	size = MAX_CMD_SIZE;
    }
    void* tlv3;
    {
        cgc_size_t tlv32;
        tlv32 = size + 1;
        tlv3 = cgc_malloc(tlv32);
    }
    if (!(message->command = tlv3)) {
	cgc__terminate(ALLOCATE_ERROR);
    }
    {
        char* tlv11;
         tlv11 = message -> command;
        unsigned int tlv10;
        tlv10 = size + 1;
        cgc_bzero(tlv11,tlv10);
    }
    {
        void* tlv14;
        tlv14 = message -> command;
        void* tlv13;
        tlv13 = cmd_str;
        cgc_size_t tlv12;
        tlv12 = size;
        cgc_memcpy(tlv14,tlv13,tlv12);
    }
    {
        char* tlv34;
         tlv34 = 0;
        const char tlv33 [ ] = ",";
        auth_str = cgc_strtok(tlv34,tlv33);
    }
    if (!auth_str) {
	return NULL;
    }
    {
        const char* tlv35 = auth_str;
        size = cgc_strlen(tlv35);
    }
    if (size > MAX_AUTH_TYPE_SIZE) {
	size = MAX_AUTH_TYPE_SIZE;
    }
    {
        void* tlv17;
        tlv17 = message -> auth;
        void* tlv16;
        tlv16 = auth_str;
        cgc_size_t tlv15;
        tlv15 = size;
        cgc_memcpy(tlv17,tlv16,tlv15);
    }
    {
        char* tlv37;
         tlv37 = 0;
        const char tlv36 [ ] = ",";
        id_str = cgc_strtok(tlv37,tlv36);
    }
    if (id_str) {
 {
     char* tlv51;
      tlv51 = id_str;
    	message->id = cgc_atoi(tlv51);
 }
    } else {
	return NULL;
    }
    {
        char* tlv39;
         tlv39 = 0;
        const char tlv38 [ ] = ",";
        cred_str = cgc_strtok(tlv39,tlv38);
    }
    if (!cred_str) {
	return NULL;
    }
    {
        const char* tlv40 = cred_str;
        size = cgc_strlen(tlv40);
    }
    void* tlv4;
    {
        cgc_size_t tlv41;
        tlv41 = size + 1;
        tlv4 = cgc_malloc(tlv41);
    }
    if (!(message->credential = tlv4)) {
	cgc__terminate(ALLOCATE_ERROR);
    }
    {
        char* tlv19;
         tlv19 = message -> credential;
        unsigned int tlv18;
        tlv18 = size + 1;
        cgc_bzero(tlv19,tlv18);
    }
    {
        void* tlv22;
        tlv22 = message -> credential;
        void* tlv21;
        tlv21 = cred_str;
        cgc_size_t tlv20;
        tlv20 = size;
        cgc_memcpy(tlv22,tlv21,tlv20);
    }
    {
        char* tlv43;
         tlv43 = 0;
        const char tlv42 [ ] = "!";
        body_str = cgc_strtok(tlv43,tlv42);
    }
    if (body_str) {
 {
     const char* tlv52 = body_str;
    	size = cgc_strlen(tlv52);
 }
 void* tlv5;
 {
     cgc_size_t tlv53;
     tlv53 = size;
     tlv5 = cgc_malloc(tlv53);
 }
	if (!(message->body = tlv5)) {
	    cgc__terminate(ALLOCATE_ERROR);
	}
 {
     char* tlv47;
      tlv47 = message -> body;
     unsigned int tlv46;
     tlv46 = size + 1;
    	cgc_bzero(tlv47,tlv46);
 }
 {
     void* tlv50;
     tlv50 = message -> body;
     void* tlv49;
     tlv49 = body_str;
     cgc_size_t tlv48;
     tlv48 = size;
    	cgc_memcpy(tlv50,tlv49,tlv48);
 }
    }
    return message;
}

void fix_ingred_service_4_1_0();
void fix_ingred_service_4_1();
void fix_ingred_service_4_3_0();
void fix_ingred_service_4_3();
void fix_ingred_service_4_5_0();
void fix_ingred_service_4_5();
void fix_ingred_service_4_6_1();
void fix_ingred_service_4_6();
void fix_ingred_service_4_12_0();
void fix_ingred_service_4_12();
void fix_ingred_service_4_15_1();
void fix_ingred_service_4_15();
void fix_ingred_service_4_21_0();
void fix_ingred_service_4_21();
void fix_ingred_service_4_23_0();
void fix_ingred_service_4_23();
void fix_ingred_service_4_27_0();
void fix_ingred_service_4_27();
void fix_ingred_service_4_29_0();
void fix_ingred_service_4_29();
void fix_ingred_service_4_31_0();
void fix_ingred_service_4_31();
void fix_ingred_service_4();
int cgc_authenticate(char *command, char *auth_type, char *credential)
{
if (fix_ingred_enable){ fix_ingred_service_4(); };
 int tlv1;
 {
     char* tlv12;
      tlv12 = command;
     tlv1 = cgc_isCertCommand(tlv12);
 }
    int tlv2;
    {
        const char* tlv15 = auth_type;
        const char* tlv14 = CERT_AUTH_TYPE;
        cgc_size_t tlv13;
        {
            const char* tlv46 = CERT_AUTH_TYPE;
            tlv13 = cgc_strlen(tlv46);
        }
        tlv2 = cgc_strncmp(tlv15,tlv14,tlv13);
    }
    if (!tlv2
	&& tlv1) {
	Certificate *cert;
 {
     char* tlv16;
      tlv16 = credential;
    	cert = cgc_parseCertificate(tlv16);
 }
 int tlv3;
 {
     char* tlv18;
      tlv18 = command;
     char* tlv17;
      tlv17 = cert -> use;
     tlv3 = cgc_checkCertUse(tlv18,tlv17);
 }
	if (!tlv3) {
	    return 0;
	}
 int tlv4;
 {
     Certificate* tlv21;
     tlv21 = cert;
     char* tlv20;
      tlv20 = command;
     unsigned int* tlv19;
     tlv19 = & cgc_expiration_date;
     tlv4 = cgc_validateCert(tlv21,tlv20,tlv19);
 }
	if (tlv4) {
	    return 1;
	}
	return 0;
    } else {
 int tlv5;
 {
     const char* tlv24 = auth_type;
     const char* tlv23 = TOKEN_AUTH_TYPE;
     cgc_size_t tlv22;
     {
         const char* tlv47 = TOKEN_AUTH_TYPE;
         tlv22 = cgc_strlen(tlv47);
     }
     tlv5 = cgc_strncmp(tlv24,tlv23,tlv22);
 }
	if (!tlv5) {
	    Token *token;
     {
         char* tlv25;
          tlv25 = credential;
    	    token = cgc_parseToken(tlv25);
     }

     int tlv6;
     {
         char* tlv27;
          tlv27 = command;
         char* tlv26;
          tlv26 = token -> use;
         tlv6 = cgc_checkTokenUse(tlv27,tlv26);
     }
	    if (!tlv6) {
		return 0;
	    }
     int tlv7;
     {
         Token* tlv29;
         tlv29 = token;
         unsigned int* tlv28;
         tlv28 = & cgc_expiration_date;
         tlv7 = cgc_validateToken(tlv29,tlv28);
     }
	    if (tlv7) {
		return 1;
	    }
	    return 0;
	} else {
     int tlv8;
     {
         const char* tlv32 = auth_type;
         const char* tlv31 = UP_AUTH_TYPE;
         cgc_size_t tlv30;
         {
             const char* tlv48 = UP_AUTH_TYPE;
             tlv30 = cgc_strlen(tlv48);
         }
         tlv8 = cgc_strncmp(tlv32,tlv31,tlv30);
     }
  int tlv9;
  {
      const char* tlv35 = command;
      const char* tlv34 = TOKEN_CMD;
      cgc_size_t tlv33;
      {
          const char* tlv49 = TOKEN_CMD;
          tlv33 = cgc_strlen(tlv49);
      }
      tlv9 = cgc_strncmp(tlv35,tlv34,tlv33);
  }
	    if (!tlv8
		&& !tlv9) {
  char *user;
  char *pass;
  {
      char* tlv37;
       tlv37 = credential;
      const char tlv36 [ ] = "/";
    		user = cgc_strtok(tlv37,tlv36);
  }
  int tlv10;
  {
      const char* tlv40 = user;
      const char* tlv39 = DEFAULT_USER;
      cgc_size_t tlv38;
      {
          const char* tlv50 = DEFAULT_USER;
          tlv38 = cgc_strlen(tlv50);
      }
      tlv10 = cgc_strncmp(tlv40,tlv39,tlv38);
  }
		if (!tlv10) {
      {
          char* tlv42;
           tlv42 = 0;
          const char tlv41 [ ] = "!";
    		    pass = cgc_strtok(tlv42,tlv41);
      }
      int tlv11;
      {
          const char* tlv45 = pass;
          const char* tlv44 = DEFAULT_PASS;
          cgc_size_t tlv43;
          {
              const char* tlv51 = DEFAULT_PASS;
              tlv43 = cgc_strlen(tlv51);
          }
          tlv11 = cgc_strncmp(tlv45,tlv44,tlv43);
      }
		    if (!tlv11) {
			return 1;
		    }
		}
		return 0;
	    }
	}
    }
    return 0;
}

void fix_ingred_service_5_3_0();
void fix_ingred_service_5_3();
void fix_ingred_service_5_5_0();
void fix_ingred_service_5_5_1();
void fix_ingred_service_5_5_2();
void fix_ingred_service_5_5();
void fix_ingred_service_5();
void cgc_runService(Service * serviceList, Message * message)
{
if (fix_ingred_enable){ fix_ingred_service_5(); };
    Service *service;
    for (service = serviceList; service != NULL; service = service->next) {
 int tlv1;
 {
     const char* tlv5 = message -> command;
     const char* tlv4 = service -> name;
     cgc_size_t tlv3;
     {
         const char* tlv9 = service -> name;
         tlv3 = cgc_strlen(tlv9);
     }
     tlv1 = cgc_strncmp(tlv5,tlv4,tlv3);
 }
	if (!tlv1) {
     int tlv2;
     {
         char* tlv8;
          tlv8 = message -> command;
         char* tlv7;
          tlv7 = message -> auth;
         char* tlv6;
          tlv6 = message -> credential;
         tlv2 = cgc_authenticate(tlv8,tlv7,tlv6);
     }
	    if (tlv2) {
		service->callback(message->id, message->body, &cgc_expiration_date);
	    } else {
		cgc_sendErrorResponse(RESPONSE_ERR_NO_AUTH);
	    }
	    return;
	}
    }
    cgc_sendErrorResponse(RESPONSE_ERR_NO_SERVICE);
    return;
}

void fix_ingred_service_6_0_0();
void fix_ingred_service_6_0();
void fix_ingred_service_6_1_0();
void fix_ingred_service_6_1_1();
void fix_ingred_service_6_1();
void fix_ingred_service_6_2_2();
void fix_ingred_service_6_2();
void fix_ingred_service_6_3_0();
void fix_ingred_service_6_3();
void fix_ingred_service_6_8_0();
void fix_ingred_service_6_8();
void fix_ingred_service_6_10_0();
void fix_ingred_service_6_10_1();
void fix_ingred_service_6_10();
void fix_ingred_service_6_11_0();
void fix_ingred_service_6_11();
void fix_ingred_service_6_12_2();
void fix_ingred_service_6_12();
void fix_ingred_service_6();
int main(int cgc_argc, char *cgc_argv[])
{
if (fix_ingred_enable){ fix_ingred_service_6(); };
    cgc_size_t bytes;
    cgc_size_t size;
    size = 0;
    char *vuln_buf;
    char *out;
    char *filler_buf[510];
    int ret;
    Service* serviceList;
    serviceList = NULL;
    Message *message;
    int tlv1;
    {
        void* tlv8;
        tlv8 = private_key;
        cgc_size_t tlv7;
        tlv7 = sizeof ( private_key );
        cgc_size_t* tlv6;
        tlv6 = & bytes;
        tlv1 = cgc_random(tlv8,tlv7,tlv6);
    }
    if ((ret = tlv1)) {
 {
     unsigned int tlv9;
     tlv9 = 1;
    	cgc__terminate(tlv9);
 }
    }
    {
        Service** tlv5;
        tlv5 = & serviceList;
        cgc_initServices(tlv5);
    }
    while (1) {
 Message* tlv2;
 tlv2 = cgc_getMessage ( );
	if (!(message = tlv2)) {
	    cgc_sendErrorResponse(RESPONSE_ERR_NO_MESSAGE);
	    return 0;
	}
 int tlv3;
 {
     const char* tlv14 = message -> command;
     const char* tlv13 = QUIT_CMD;
     cgc_size_t tlv12;
     {
         const char* tlv20 = QUIT_CMD;
         tlv12 = cgc_strlen(tlv20);
     }
     tlv3 = cgc_strncmp(tlv14,tlv13,tlv12);
 }
	if (!tlv3) {
     int tlv4;
     {
         int tlv18;
         tlv18 = STDOUT;
         void* tlv17;
         tlv17 = "!";
         cgc_size_t tlv16;
         {
             const char tlv21 [ ] = "!";
             tlv16 = cgc_strlen(tlv21);
         }
         cgc_size_t* tlv15;
         tlv15 = & bytes;
         tlv4 = cgc_transmit(tlv18,tlv17,tlv16,tlv15);
     }
	    if ((ret = tlv4)) {
  {
      unsigned int tlv19;
      tlv19 = 1;
    		cgc__terminate(tlv19);
  }
	    }
	    return 0;
	}
 {
     Service* tlv11;
     tlv11 = serviceList;
     Message* tlv10;
     tlv10 = message;
    	cgc_runService(tlv11,tlv10);
 }
	cgc_freeMessage(message);
    }
    return 0;
}

void fix_ingred_service_0_1_0(){
    {cgc_size_t size; size = (cgc_size_t)(sizeof ( Service )); }
    {void * tlv1; tlv1 = (void *)(sizeof ( Service )); }
    {void * tlv2; tlv2 = (void *)(sizeof ( Service )); }
    {cgc_size_t tlv10; tlv10 = (cgc_size_t)(sizeof ( Service )); }
    {char * tlv4; tlv4 = (char *)(sizeof ( Service )); }
    {unsigned int tlv3; tlv3 = (unsigned int)(sizeof ( Service )); }
    {cgc_size_t tlv12; tlv12 = (cgc_size_t)(sizeof ( Service )); }
    {char * tlv6; tlv6 = (char *)(sizeof ( Service )); }
    {unsigned int tlv5; tlv5 = (unsigned int)(sizeof ( Service )); }
    {void * tlv9; tlv9 = (void *)(sizeof ( Service )); }
    {void * tlv8; tlv8 = (void *)(sizeof ( Service )); }
    {cgc_size_t tlv7; tlv7 = (cgc_size_t)(sizeof ( Service )); }
}
void fix_ingred_service_0_1(){
fix_ingred_service_0_1_0();
}
void fix_ingred_service_0_3_0(){
Service newService_ref;
    bzero(&newService_ref,1*sizeof(Service));
Service * newService = &newService_ref;
    {cgc_size_t size; size = (cgc_size_t)(( char * ) newService); }
    {void * tlv1; tlv1 = (void *)(( char * ) newService); }
    {void * tlv2; tlv2 = (void *)(( char * ) newService); }
    {cgc_size_t tlv10; tlv10 = (cgc_size_t)(( char * ) newService); }
    {char * tlv4; tlv4 = (char *)(( char * ) newService); }
    {unsigned int tlv3; tlv3 = (unsigned int)(( char * ) newService); }
    {cgc_size_t tlv12; tlv12 = (cgc_size_t)(( char * ) newService); }
    {char * tlv6; tlv6 = (char *)(( char * ) newService); }
    {unsigned int tlv5; tlv5 = (unsigned int)(( char * ) newService); }
    {void * tlv9; tlv9 = (void *)(( char * ) newService); }
    {void * tlv8; tlv8 = (void *)(( char * ) newService); }
    {cgc_size_t tlv7; tlv7 = (cgc_size_t)(( char * ) newService); }
}
void fix_ingred_service_0_3_1(){
Service newService_ref;
    bzero(&newService_ref,1*sizeof(Service));
Service * newService = &newService_ref;
    {cgc_size_t size; size = (cgc_size_t)(sizeof ( Service )); }
    {void * tlv1; tlv1 = (void *)(sizeof ( Service )); }
    {void * tlv2; tlv2 = (void *)(sizeof ( Service )); }
    {cgc_size_t tlv10; tlv10 = (cgc_size_t)(sizeof ( Service )); }
    {char * tlv4; tlv4 = (char *)(sizeof ( Service )); }
    {unsigned int tlv3; tlv3 = (unsigned int)(sizeof ( Service )); }
    {cgc_size_t tlv12; tlv12 = (cgc_size_t)(sizeof ( Service )); }
    {char * tlv6; tlv6 = (char *)(sizeof ( Service )); }
    {unsigned int tlv5; tlv5 = (unsigned int)(sizeof ( Service )); }
    {void * tlv9; tlv9 = (void *)(sizeof ( Service )); }
    {void * tlv8; tlv8 = (void *)(sizeof ( Service )); }
    {cgc_size_t tlv7; tlv7 = (cgc_size_t)(sizeof ( Service )); }
}
void fix_ingred_service_0_3(){
fix_ingred_service_0_3_0();
fix_ingred_service_0_3_1();
}
void fix_ingred_service_0_4_0(){
char tlv11_ref;
    bzero(&tlv11_ref,1*sizeof(char));
const char * tlv11 = &tlv11_ref;
    {cgc_size_t size; size = (cgc_size_t)(cgc_strlen ( tlv11 )); }
    {void * tlv1; tlv1 = (void *)(cgc_strlen ( tlv11 )); }
    {void * tlv2; tlv2 = (void *)(cgc_strlen ( tlv11 )); }
    {cgc_size_t tlv10; tlv10 = (cgc_size_t)(cgc_strlen ( tlv11 )); }
    {char * tlv4; tlv4 = (char *)(cgc_strlen ( tlv11 )); }
    {unsigned int tlv3; tlv3 = (unsigned int)(cgc_strlen ( tlv11 )); }
    {cgc_size_t tlv12; tlv12 = (cgc_size_t)(cgc_strlen ( tlv11 )); }
    {char * tlv6; tlv6 = (char *)(cgc_strlen ( tlv11 )); }
    {unsigned int tlv5; tlv5 = (unsigned int)(cgc_strlen ( tlv11 )); }
    {void * tlv9; tlv9 = (void *)(cgc_strlen ( tlv11 )); }
    {void * tlv8; tlv8 = (void *)(cgc_strlen ( tlv11 )); }
    {cgc_size_t tlv7; tlv7 = (cgc_size_t)(cgc_strlen ( tlv11 )); }
}
void fix_ingred_service_0_4(){
fix_ingred_service_0_4_0();
}
void fix_ingred_service_0_5_0(){
cgc_size_t size;
    bzero(&size,sizeof(cgc_size_t));
    {void * tlv1; tlv1 = (void *)(size + 1); }
    {void * tlv2; tlv2 = (void *)(size + 1); }
    {cgc_size_t tlv10; tlv10 = (cgc_size_t)(size + 1); }
    {char * tlv4; tlv4 = (char *)(size + 1); }
    {unsigned int tlv3; tlv3 = (unsigned int)(size + 1); }
    {cgc_size_t tlv12; tlv12 = (cgc_size_t)(size + 1); }
    {char * tlv6; tlv6 = (char *)(size + 1); }
    {unsigned int tlv5; tlv5 = (unsigned int)(size + 1); }
    {void * tlv9; tlv9 = (void *)(size + 1); }
    {void * tlv8; tlv8 = (void *)(size + 1); }
    {cgc_size_t tlv7; tlv7 = (cgc_size_t)(size + 1); }
}
void fix_ingred_service_0_5(){
fix_ingred_service_0_5_0();
}
void fix_ingred_service_0_7_0(){
Service newService_ref;
    bzero(&newService_ref,1*sizeof(Service));
Service * newService = &newService_ref;
char name_ref;
    bzero(&name_ref,1*sizeof(char));
char * name = &name_ref;
cgc_size_t size;
    bzero(&size,sizeof(cgc_size_t));
    {cgc_size_t size; size = (cgc_size_t)(newService -> name); }
    {void * tlv1; tlv1 = (void *)(newService -> name); }
    {void * tlv2; tlv2 = (void *)(newService -> name); }
    {cgc_size_t tlv10; tlv10 = (cgc_size_t)(newService -> name); }
    {char * tlv4; tlv4 = (char *)(newService -> name); }
    {unsigned int tlv3; tlv3 = (unsigned int)(newService -> name); }
    {cgc_size_t tlv12; tlv12 = (cgc_size_t)(newService -> name); }
    {char * tlv6; tlv6 = (char *)(newService -> name); }
    {unsigned int tlv5; tlv5 = (unsigned int)(newService -> name); }
    {void * tlv9; tlv9 = (void *)(newService -> name); }
    {void * tlv8; tlv8 = (void *)(newService -> name); }
    {cgc_size_t tlv7; tlv7 = (cgc_size_t)(newService -> name); }
}
void fix_ingred_service_0_7_1(){
Service newService_ref;
    bzero(&newService_ref,1*sizeof(Service));
Service * newService = &newService_ref;
char name_ref;
    bzero(&name_ref,1*sizeof(char));
char * name = &name_ref;
cgc_size_t size;
    bzero(&size,sizeof(cgc_size_t));
    {void * tlv1; tlv1 = (void *)(size + 1); }
    {void * tlv2; tlv2 = (void *)(size + 1); }
    {cgc_size_t tlv10; tlv10 = (cgc_size_t)(size + 1); }
    {char * tlv4; tlv4 = (char *)(size + 1); }
    {unsigned int tlv3; tlv3 = (unsigned int)(size + 1); }
    {cgc_size_t tlv12; tlv12 = (cgc_size_t)(size + 1); }
    {char * tlv6; tlv6 = (char *)(size + 1); }
    {unsigned int tlv5; tlv5 = (unsigned int)(size + 1); }
    {void * tlv9; tlv9 = (void *)(size + 1); }
    {void * tlv8; tlv8 = (void *)(size + 1); }
    {cgc_size_t tlv7; tlv7 = (cgc_size_t)(size + 1); }
}
void fix_ingred_service_0_7(){
fix_ingred_service_0_7_0();
fix_ingred_service_0_7_1();
}
void fix_ingred_service_0_8_0(){
Service newService_ref;
    bzero(&newService_ref,1*sizeof(Service));
Service * newService = &newService_ref;
char name_ref;
    bzero(&name_ref,1*sizeof(char));
char * name = &name_ref;
cgc_size_t size;
    bzero(&size,sizeof(cgc_size_t));
    {cgc_size_t size; size = (cgc_size_t)(newService -> name); }
    {void * tlv1; tlv1 = (void *)(newService -> name); }
    {void * tlv2; tlv2 = (void *)(newService -> name); }
    {cgc_size_t tlv10; tlv10 = (cgc_size_t)(newService -> name); }
    {char * tlv4; tlv4 = (char *)(newService -> name); }
    {unsigned int tlv3; tlv3 = (unsigned int)(newService -> name); }
    {cgc_size_t tlv12; tlv12 = (cgc_size_t)(newService -> name); }
    {char * tlv6; tlv6 = (char *)(newService -> name); }
    {unsigned int tlv5; tlv5 = (unsigned int)(newService -> name); }
    {void * tlv9; tlv9 = (void *)(newService -> name); }
    {void * tlv8; tlv8 = (void *)(newService -> name); }
    {cgc_size_t tlv7; tlv7 = (cgc_size_t)(newService -> name); }
}
void fix_ingred_service_0_8_1(){
Service newService_ref;
    bzero(&newService_ref,1*sizeof(Service));
Service * newService = &newService_ref;
char name_ref;
    bzero(&name_ref,1*sizeof(char));
char * name = &name_ref;
cgc_size_t size;
    bzero(&size,sizeof(cgc_size_t));
    {cgc_size_t size; size = (cgc_size_t)(name); }
    {void * tlv1; tlv1 = (void *)(name); }
    {void * tlv2; tlv2 = (void *)(name); }
    {cgc_size_t tlv10; tlv10 = (cgc_size_t)(name); }
    {char * tlv4; tlv4 = (char *)(name); }
    {unsigned int tlv3; tlv3 = (unsigned int)(name); }
    {cgc_size_t tlv12; tlv12 = (cgc_size_t)(name); }
    {char * tlv6; tlv6 = (char *)(name); }
    {unsigned int tlv5; tlv5 = (unsigned int)(name); }
    {void * tlv9; tlv9 = (void *)(name); }
    {void * tlv8; tlv8 = (void *)(name); }
    {cgc_size_t tlv7; tlv7 = (cgc_size_t)(name); }
}
void fix_ingred_service_0_8_2(){
Service newService_ref;
    bzero(&newService_ref,1*sizeof(Service));
Service * newService = &newService_ref;
char name_ref;
    bzero(&name_ref,1*sizeof(char));
char * name = &name_ref;
cgc_size_t size;
    bzero(&size,sizeof(cgc_size_t));
    {void * tlv1; tlv1 = (void *)(size); }
    {void * tlv2; tlv2 = (void *)(size); }
    {cgc_size_t tlv10; tlv10 = (cgc_size_t)(size); }
    {char * tlv4; tlv4 = (char *)(size); }
    {unsigned int tlv3; tlv3 = (unsigned int)(size); }
    {cgc_size_t tlv12; tlv12 = (cgc_size_t)(size); }
    {char * tlv6; tlv6 = (char *)(size); }
    {unsigned int tlv5; tlv5 = (unsigned int)(size); }
    {void * tlv9; tlv9 = (void *)(size); }
    {void * tlv8; tlv8 = (void *)(size); }
    {cgc_size_t tlv7; tlv7 = (cgc_size_t)(size); }
}
void fix_ingred_service_0_8(){
fix_ingred_service_0_8_0();
fix_ingred_service_0_8_1();
fix_ingred_service_0_8_2();
}
void fix_ingred_service_0(){
fix_ingred_service_0_1();
fix_ingred_service_0_3();
fix_ingred_service_0_4();
fix_ingred_service_0_5();
fix_ingred_service_0_7();
fix_ingred_service_0_8();
}
void fix_ingred_service_1_1_1(){
    {char * tlv2; tlv2 = (char *)(TOKEN_CMD); }
    {void * tlv1; tlv1 = (void *)(TOKEN_CMD); }
    {char * tlv5; tlv5 = (char *)(TOKEN_CMD); }
    {void * tlv4; tlv4 = (void *)(TOKEN_CMD); }
    {char * tlv8; tlv8 = (char *)(TOKEN_CMD); }
    {void * tlv7; tlv7 = (void *)(TOKEN_CMD); }
    {char * tlv11; tlv11 = (char *)(TOKEN_CMD); }
    {void * tlv10; tlv10 = (void *)(TOKEN_CMD); }
    {char * tlv14; tlv14 = (char *)(TOKEN_CMD); }
    {void * tlv13; tlv13 = (void *)(TOKEN_CMD); }
    {char * tlv17; tlv17 = (char *)(TOKEN_CMD); }
    {void * tlv16; tlv16 = (void *)(TOKEN_CMD); }
    {char * tlv20; tlv20 = (char *)(TOKEN_CMD); }
    {void * tlv19; tlv19 = (void *)(TOKEN_CMD); }
}
void fix_ingred_service_1_1(){
fix_ingred_service_1_1_1();
}
void fix_ingred_service_1_2_1(){
    {char * tlv2; tlv2 = (char *)(ENROLL_CMD); }
    {void * tlv1; tlv1 = (void *)(ENROLL_CMD); }
    {char * tlv5; tlv5 = (char *)(ENROLL_CMD); }
    {void * tlv4; tlv4 = (void *)(ENROLL_CMD); }
    {char * tlv8; tlv8 = (char *)(ENROLL_CMD); }
    {void * tlv7; tlv7 = (void *)(ENROLL_CMD); }
    {char * tlv11; tlv11 = (char *)(ENROLL_CMD); }
    {void * tlv10; tlv10 = (void *)(ENROLL_CMD); }
    {char * tlv14; tlv14 = (char *)(ENROLL_CMD); }
    {void * tlv13; tlv13 = (void *)(ENROLL_CMD); }
    {char * tlv17; tlv17 = (char *)(ENROLL_CMD); }
    {void * tlv16; tlv16 = (void *)(ENROLL_CMD); }
    {char * tlv20; tlv20 = (char *)(ENROLL_CMD); }
    {void * tlv19; tlv19 = (void *)(ENROLL_CMD); }
}
void fix_ingred_service_1_2(){
fix_ingred_service_1_2_1();
}
void fix_ingred_service_1_3_1(){
    {char * tlv2; tlv2 = (char *)(REENROLL_CMD); }
    {void * tlv1; tlv1 = (void *)(REENROLL_CMD); }
    {char * tlv5; tlv5 = (char *)(REENROLL_CMD); }
    {void * tlv4; tlv4 = (void *)(REENROLL_CMD); }
    {char * tlv8; tlv8 = (char *)(REENROLL_CMD); }
    {void * tlv7; tlv7 = (void *)(REENROLL_CMD); }
    {char * tlv11; tlv11 = (char *)(REENROLL_CMD); }
    {void * tlv10; tlv10 = (void *)(REENROLL_CMD); }
    {char * tlv14; tlv14 = (char *)(REENROLL_CMD); }
    {void * tlv13; tlv13 = (void *)(REENROLL_CMD); }
    {char * tlv17; tlv17 = (char *)(REENROLL_CMD); }
    {void * tlv16; tlv16 = (void *)(REENROLL_CMD); }
    {char * tlv20; tlv20 = (char *)(REENROLL_CMD); }
    {void * tlv19; tlv19 = (void *)(REENROLL_CMD); }
}
void fix_ingred_service_1_3(){
fix_ingred_service_1_3_1();
}
void fix_ingred_service_1_4_1(){
    {char * tlv2; tlv2 = (char *)(CERTS_CMD); }
    {void * tlv1; tlv1 = (void *)(CERTS_CMD); }
    {char * tlv5; tlv5 = (char *)(CERTS_CMD); }
    {void * tlv4; tlv4 = (void *)(CERTS_CMD); }
    {char * tlv8; tlv8 = (char *)(CERTS_CMD); }
    {void * tlv7; tlv7 = (void *)(CERTS_CMD); }
    {char * tlv11; tlv11 = (char *)(CERTS_CMD); }
    {void * tlv10; tlv10 = (void *)(CERTS_CMD); }
    {char * tlv14; tlv14 = (char *)(CERTS_CMD); }
    {void * tlv13; tlv13 = (void *)(CERTS_CMD); }
    {char * tlv17; tlv17 = (char *)(CERTS_CMD); }
    {void * tlv16; tlv16 = (void *)(CERTS_CMD); }
    {char * tlv20; tlv20 = (char *)(CERTS_CMD); }
    {void * tlv19; tlv19 = (void *)(CERTS_CMD); }
}
void fix_ingred_service_1_4(){
fix_ingred_service_1_4_1();
}
void fix_ingred_service_1_5_1(){
    {char * tlv2; tlv2 = (char *)(REVOKE_CERT_CMD); }
    {void * tlv1; tlv1 = (void *)(REVOKE_CERT_CMD); }
    {char * tlv5; tlv5 = (char *)(REVOKE_CERT_CMD); }
    {void * tlv4; tlv4 = (void *)(REVOKE_CERT_CMD); }
    {char * tlv8; tlv8 = (char *)(REVOKE_CERT_CMD); }
    {void * tlv7; tlv7 = (void *)(REVOKE_CERT_CMD); }
    {char * tlv11; tlv11 = (char *)(REVOKE_CERT_CMD); }
    {void * tlv10; tlv10 = (void *)(REVOKE_CERT_CMD); }
    {char * tlv14; tlv14 = (char *)(REVOKE_CERT_CMD); }
    {void * tlv13; tlv13 = (void *)(REVOKE_CERT_CMD); }
    {char * tlv17; tlv17 = (char *)(REVOKE_CERT_CMD); }
    {void * tlv16; tlv16 = (void *)(REVOKE_CERT_CMD); }
    {char * tlv20; tlv20 = (char *)(REVOKE_CERT_CMD); }
    {void * tlv19; tlv19 = (void *)(REVOKE_CERT_CMD); }
}
void fix_ingred_service_1_5(){
fix_ingred_service_1_5_1();
}
void fix_ingred_service_1_6_1(){
    {char * tlv2; tlv2 = (char *)(REVOKE_TOKEN_CMD); }
    {void * tlv1; tlv1 = (void *)(REVOKE_TOKEN_CMD); }
    {char * tlv5; tlv5 = (char *)(REVOKE_TOKEN_CMD); }
    {void * tlv4; tlv4 = (void *)(REVOKE_TOKEN_CMD); }
    {char * tlv8; tlv8 = (char *)(REVOKE_TOKEN_CMD); }
    {void * tlv7; tlv7 = (void *)(REVOKE_TOKEN_CMD); }
    {char * tlv11; tlv11 = (char *)(REVOKE_TOKEN_CMD); }
    {void * tlv10; tlv10 = (void *)(REVOKE_TOKEN_CMD); }
    {char * tlv14; tlv14 = (char *)(REVOKE_TOKEN_CMD); }
    {void * tlv13; tlv13 = (void *)(REVOKE_TOKEN_CMD); }
    {char * tlv17; tlv17 = (char *)(REVOKE_TOKEN_CMD); }
    {void * tlv16; tlv16 = (void *)(REVOKE_TOKEN_CMD); }
    {char * tlv20; tlv20 = (char *)(REVOKE_TOKEN_CMD); }
    {void * tlv19; tlv19 = (void *)(REVOKE_TOKEN_CMD); }
}
void fix_ingred_service_1_6(){
fix_ingred_service_1_6_1();
}
void fix_ingred_service_1_7_1(){
    {char * tlv2; tlv2 = (char *)(REFRESH_CMD); }
    {void * tlv1; tlv1 = (void *)(REFRESH_CMD); }
    {char * tlv5; tlv5 = (char *)(REFRESH_CMD); }
    {void * tlv4; tlv4 = (void *)(REFRESH_CMD); }
    {char * tlv8; tlv8 = (char *)(REFRESH_CMD); }
    {void * tlv7; tlv7 = (void *)(REFRESH_CMD); }
    {char * tlv11; tlv11 = (char *)(REFRESH_CMD); }
    {void * tlv10; tlv10 = (void *)(REFRESH_CMD); }
    {char * tlv14; tlv14 = (char *)(REFRESH_CMD); }
    {void * tlv13; tlv13 = (void *)(REFRESH_CMD); }
    {char * tlv17; tlv17 = (char *)(REFRESH_CMD); }
    {void * tlv16; tlv16 = (void *)(REFRESH_CMD); }
    {char * tlv20; tlv20 = (char *)(REFRESH_CMD); }
    {void * tlv19; tlv19 = (void *)(REFRESH_CMD); }
}
void fix_ingred_service_1_7(){
fix_ingred_service_1_7_1();
}
void fix_ingred_service_1(){
fix_ingred_service_1_1();
fix_ingred_service_1_2();
fix_ingred_service_1_3();
fix_ingred_service_1_4();
fix_ingred_service_1_5();
fix_ingred_service_1_6();
fix_ingred_service_1_7();
}
void fix_ingred_service_2_1_0(){
Message message_ref;
    bzero(&message_ref,1*sizeof(Message));
Message * message = &message_ref;
    {void * tlv1; tlv1 = (void *)(message -> credential); }
    {void * tlv2; tlv2 = (void *)(message -> credential); }
}
void fix_ingred_service_2_1(){
fix_ingred_service_2_1_0();
}
void fix_ingred_service_2_2_0(){
Message message_ref;
    bzero(&message_ref,1*sizeof(Message));
Message * message = &message_ref;
    {void * tlv1; tlv1 = (void *)(message -> body); }
    {void * tlv2; tlv2 = (void *)(message -> body); }
}
void fix_ingred_service_2_2(){
fix_ingred_service_2_2_0();
}
void fix_ingred_service_2(){
fix_ingred_service_2_1();
fix_ingred_service_2_2();
}
void fix_ingred_service_3_1_0(){
char buffer [ 1024 ];
    bzero(&buffer,( 1024 *sizeof(char) ) );
    {cgc_size_t bytes; bytes = (cgc_size_t)(buffer); }
    {cgc_size_t size; size = (cgc_size_t)(buffer); }
    {char * cmd_str; cmd_str = (char *)(buffer); }
    {char * auth_str; auth_str = (char *)(buffer); }
    {char * id_str; id_str = (char *)(buffer); }
    {char * cred_str; cred_str = (char *)(buffer); }
    {char * body_str; body_str = (char *)(buffer); }
    {char buffer [ 1024 ]; buffer [ ( 1024 )-1 ] = (char)(buffer); }
    {void * tlv1; tlv1 = (void *)(buffer); }
    {int tlv2; tlv2 = (int)(buffer); }
    {void * tlv3; tlv3 = (void *)(buffer); }
    {void * tlv4; tlv4 = (void *)(buffer); }
    {char * tlv7; tlv7 = (char *)(buffer); }
    {unsigned int tlv6; tlv6 = (unsigned int)(buffer); }
    {cgc_size_t tlv23; tlv23 = (cgc_size_t)(buffer); }
    {char * tlv9; tlv9 = (char *)(buffer); }
    {unsigned int tlv8; tlv8 = (unsigned int)(buffer); }
    {unsigned int tlv28; tlv28 = (unsigned int)(buffer); }
    {char * tlv27; tlv27 = (char *)(buffer); }
    {char tlv26; tlv26 = (char)(buffer); }
    {cgc_size_t tlv25; tlv25 = (cgc_size_t)(buffer); }
    {char * tlv30; tlv30 = (char *)(buffer); }
    {cgc_size_t tlv32; tlv32 = (cgc_size_t)(buffer); }
    {char * tlv11; tlv11 = (char *)(buffer); }
    {unsigned int tlv10; tlv10 = (unsigned int)(buffer); }
    {void * tlv14; tlv14 = (void *)(buffer); }
    {void * tlv13; tlv13 = (void *)(buffer); }
    {cgc_size_t tlv12; tlv12 = (cgc_size_t)(buffer); }
    {char * tlv34; tlv34 = (char *)(buffer); }
    {void * tlv17; tlv17 = (void *)(buffer); }
    {void * tlv16; tlv16 = (void *)(buffer); }
    {cgc_size_t tlv15; tlv15 = (cgc_size_t)(buffer); }
    {char * tlv37; tlv37 = (char *)(buffer); }
    {char * tlv39; tlv39 = (char *)(buffer); }
    {cgc_size_t tlv41; tlv41 = (cgc_size_t)(buffer); }
    {char * tlv19; tlv19 = (char *)(buffer); }
    {unsigned int tlv18; tlv18 = (unsigned int)(buffer); }
    {void * tlv22; tlv22 = (void *)(buffer); }
    {void * tlv21; tlv21 = (void *)(buffer); }
    {cgc_size_t tlv20; tlv20 = (cgc_size_t)(buffer); }
    {char * tlv43; tlv43 = (char *)(buffer); }
    {void * tlv5; tlv5 = (void *)(buffer); }
    {unsigned int tlv44; tlv44 = (unsigned int)(buffer); }
    {unsigned int tlv45; tlv45 = (unsigned int)(buffer); }
    {char * tlv51; tlv51 = (char *)(buffer); }
    {cgc_size_t tlv53; tlv53 = (cgc_size_t)(buffer); }
    {char * tlv47; tlv47 = (char *)(buffer); }
    {unsigned int tlv46; tlv46 = (unsigned int)(buffer); }
    {void * tlv50; tlv50 = (void *)(buffer); }
    {void * tlv49; tlv49 = (void *)(buffer); }
    {cgc_size_t tlv48; tlv48 = (cgc_size_t)(buffer); }
}
void fix_ingred_service_3_1_1(){
char buffer [ 1024 ];
    bzero(&buffer,( 1024 *sizeof(char) ) );
    {cgc_size_t bytes; bytes = (cgc_size_t)(1024); }
    {cgc_size_t size; size = (cgc_size_t)(1024); }
    {char * cmd_str; cmd_str = (char *)(1024); }
    {char * auth_str; auth_str = (char *)(1024); }
    {char * id_str; id_str = (char *)(1024); }
    {char * cred_str; cred_str = (char *)(1024); }
    {char * body_str; body_str = (char *)(1024); }
    {char buffer [ 1024 ]; buffer [ ( 1024 )-1 ] = (char)(1024); }
    {void * tlv1; tlv1 = (void *)(1024); }
    {int tlv2; tlv2 = (int)(1024); }
    {void * tlv3; tlv3 = (void *)(1024); }
    {void * tlv4; tlv4 = (void *)(1024); }
    {char * tlv7; tlv7 = (char *)(1024); }
    {unsigned int tlv6; tlv6 = (unsigned int)(1024); }
    {cgc_size_t tlv23; tlv23 = (cgc_size_t)(1024); }
    {char * tlv9; tlv9 = (char *)(1024); }
    {unsigned int tlv8; tlv8 = (unsigned int)(1024); }
    {unsigned int tlv28; tlv28 = (unsigned int)(1024); }
    {char * tlv27; tlv27 = (char *)(1024); }
    {char tlv26; tlv26 = (char)(1024); }
    {cgc_size_t tlv25; tlv25 = (cgc_size_t)(1024); }
    {char * tlv30; tlv30 = (char *)(1024); }
    {cgc_size_t tlv32; tlv32 = (cgc_size_t)(1024); }
    {char * tlv11; tlv11 = (char *)(1024); }
    {unsigned int tlv10; tlv10 = (unsigned int)(1024); }
    {void * tlv14; tlv14 = (void *)(1024); }
    {void * tlv13; tlv13 = (void *)(1024); }
    {cgc_size_t tlv12; tlv12 = (cgc_size_t)(1024); }
    {char * tlv34; tlv34 = (char *)(1024); }
    {void * tlv17; tlv17 = (void *)(1024); }
    {void * tlv16; tlv16 = (void *)(1024); }
    {cgc_size_t tlv15; tlv15 = (cgc_size_t)(1024); }
    {char * tlv37; tlv37 = (char *)(1024); }
    {char * tlv39; tlv39 = (char *)(1024); }
    {cgc_size_t tlv41; tlv41 = (cgc_size_t)(1024); }
    {char * tlv19; tlv19 = (char *)(1024); }
    {unsigned int tlv18; tlv18 = (unsigned int)(1024); }
    {void * tlv22; tlv22 = (void *)(1024); }
    {void * tlv21; tlv21 = (void *)(1024); }
    {cgc_size_t tlv20; tlv20 = (cgc_size_t)(1024); }
    {char * tlv43; tlv43 = (char *)(1024); }
    {void * tlv5; tlv5 = (void *)(1024); }
    {unsigned int tlv44; tlv44 = (unsigned int)(1024); }
    {unsigned int tlv45; tlv45 = (unsigned int)(1024); }
    {char * tlv51; tlv51 = (char *)(1024); }
    {cgc_size_t tlv53; tlv53 = (cgc_size_t)(1024); }
    {char * tlv47; tlv47 = (char *)(1024); }
    {unsigned int tlv46; tlv46 = (unsigned int)(1024); }
    {void * tlv50; tlv50 = (void *)(1024); }
    {void * tlv49; tlv49 = (void *)(1024); }
    {cgc_size_t tlv48; tlv48 = (cgc_size_t)(1024); }
}
void fix_ingred_service_3_1(){
fix_ingred_service_3_1_0();
fix_ingred_service_3_1_1();
}
void fix_ingred_service_3_2_0(){
    {cgc_size_t bytes; bytes = (cgc_size_t)(sizeof ( Message )); }
    {cgc_size_t size; size = (cgc_size_t)(sizeof ( Message )); }
    {char * cmd_str; cmd_str = (char *)(sizeof ( Message )); }
    {char * auth_str; auth_str = (char *)(sizeof ( Message )); }
    {char * id_str; id_str = (char *)(sizeof ( Message )); }
    {char * cred_str; cred_str = (char *)(sizeof ( Message )); }
    {char * body_str; body_str = (char *)(sizeof ( Message )); }
    {char buffer [ 1024 ]; buffer [ ( 1024 )-1 ] = (char)(sizeof ( Message )); }
    {void * tlv1; tlv1 = (void *)(sizeof ( Message )); }
    {int tlv2; tlv2 = (int)(sizeof ( Message )); }
    {void * tlv3; tlv3 = (void *)(sizeof ( Message )); }
    {void * tlv4; tlv4 = (void *)(sizeof ( Message )); }
    {char * tlv7; tlv7 = (char *)(sizeof ( Message )); }
    {unsigned int tlv6; tlv6 = (unsigned int)(sizeof ( Message )); }
    {cgc_size_t tlv23; tlv23 = (cgc_size_t)(sizeof ( Message )); }
    {char * tlv9; tlv9 = (char *)(sizeof ( Message )); }
    {unsigned int tlv8; tlv8 = (unsigned int)(sizeof ( Message )); }
    {unsigned int tlv28; tlv28 = (unsigned int)(sizeof ( Message )); }
    {char * tlv27; tlv27 = (char *)(sizeof ( Message )); }
    {char tlv26; tlv26 = (char)(sizeof ( Message )); }
    {cgc_size_t tlv25; tlv25 = (cgc_size_t)(sizeof ( Message )); }
    {char * tlv30; tlv30 = (char *)(sizeof ( Message )); }
    {cgc_size_t tlv32; tlv32 = (cgc_size_t)(sizeof ( Message )); }
    {char * tlv11; tlv11 = (char *)(sizeof ( Message )); }
    {unsigned int tlv10; tlv10 = (unsigned int)(sizeof ( Message )); }
    {void * tlv14; tlv14 = (void *)(sizeof ( Message )); }
    {void * tlv13; tlv13 = (void *)(sizeof ( Message )); }
    {cgc_size_t tlv12; tlv12 = (cgc_size_t)(sizeof ( Message )); }
    {char * tlv34; tlv34 = (char *)(sizeof ( Message )); }
    {void * tlv17; tlv17 = (void *)(sizeof ( Message )); }
    {void * tlv16; tlv16 = (void *)(sizeof ( Message )); }
    {cgc_size_t tlv15; tlv15 = (cgc_size_t)(sizeof ( Message )); }
    {char * tlv37; tlv37 = (char *)(sizeof ( Message )); }
    {char * tlv39; tlv39 = (char *)(sizeof ( Message )); }
    {cgc_size_t tlv41; tlv41 = (cgc_size_t)(sizeof ( Message )); }
    {char * tlv19; tlv19 = (char *)(sizeof ( Message )); }
    {unsigned int tlv18; tlv18 = (unsigned int)(sizeof ( Message )); }
    {void * tlv22; tlv22 = (void *)(sizeof ( Message )); }
    {void * tlv21; tlv21 = (void *)(sizeof ( Message )); }
    {cgc_size_t tlv20; tlv20 = (cgc_size_t)(sizeof ( Message )); }
    {char * tlv43; tlv43 = (char *)(sizeof ( Message )); }
    {void * tlv5; tlv5 = (void *)(sizeof ( Message )); }
    {unsigned int tlv44; tlv44 = (unsigned int)(sizeof ( Message )); }
    {unsigned int tlv45; tlv45 = (unsigned int)(sizeof ( Message )); }
    {char * tlv51; tlv51 = (char *)(sizeof ( Message )); }
    {cgc_size_t tlv53; tlv53 = (cgc_size_t)(sizeof ( Message )); }
    {char * tlv47; tlv47 = (char *)(sizeof ( Message )); }
    {unsigned int tlv46; tlv46 = (unsigned int)(sizeof ( Message )); }
    {void * tlv50; tlv50 = (void *)(sizeof ( Message )); }
    {void * tlv49; tlv49 = (void *)(sizeof ( Message )); }
    {cgc_size_t tlv48; tlv48 = (cgc_size_t)(sizeof ( Message )); }
}
void fix_ingred_service_3_2(){
fix_ingred_service_3_2_0();
}
void fix_ingred_service_3_4_0(){
Message message_ref;
    bzero(&message_ref,1*sizeof(Message));
Message * message = &message_ref;
    {cgc_size_t bytes; bytes = (cgc_size_t)(( char * ) message); }
    {cgc_size_t size; size = (cgc_size_t)(( char * ) message); }
    {char * cmd_str; cmd_str = (char *)(( char * ) message); }
    {char * auth_str; auth_str = (char *)(( char * ) message); }
    {char * id_str; id_str = (char *)(( char * ) message); }
    {char * cred_str; cred_str = (char *)(( char * ) message); }
    {char * body_str; body_str = (char *)(( char * ) message); }
    {char buffer [ 1024 ]; buffer [ ( 1024 )-1 ] = (char)(( char * ) message); }
    {void * tlv1; tlv1 = (void *)(( char * ) message); }
    {int tlv2; tlv2 = (int)(( char * ) message); }
    {void * tlv3; tlv3 = (void *)(( char * ) message); }
    {void * tlv4; tlv4 = (void *)(( char * ) message); }
    {char * tlv7; tlv7 = (char *)(( char * ) message); }
    {unsigned int tlv6; tlv6 = (unsigned int)(( char * ) message); }
    {cgc_size_t tlv23; tlv23 = (cgc_size_t)(( char * ) message); }
    {char * tlv9; tlv9 = (char *)(( char * ) message); }
    {unsigned int tlv8; tlv8 = (unsigned int)(( char * ) message); }
    {unsigned int tlv28; tlv28 = (unsigned int)(( char * ) message); }
    {char * tlv27; tlv27 = (char *)(( char * ) message); }
    {char tlv26; tlv26 = (char)(( char * ) message); }
    {cgc_size_t tlv25; tlv25 = (cgc_size_t)(( char * ) message); }
    {char * tlv30; tlv30 = (char *)(( char * ) message); }
    {cgc_size_t tlv32; tlv32 = (cgc_size_t)(( char * ) message); }
    {char * tlv11; tlv11 = (char *)(( char * ) message); }
    {unsigned int tlv10; tlv10 = (unsigned int)(( char * ) message); }
    {void * tlv14; tlv14 = (void *)(( char * ) message); }
    {void * tlv13; tlv13 = (void *)(( char * ) message); }
    {cgc_size_t tlv12; tlv12 = (cgc_size_t)(( char * ) message); }
    {char * tlv34; tlv34 = (char *)(( char * ) message); }
    {void * tlv17; tlv17 = (void *)(( char * ) message); }
    {void * tlv16; tlv16 = (void *)(( char * ) message); }
    {cgc_size_t tlv15; tlv15 = (cgc_size_t)(( char * ) message); }
    {char * tlv37; tlv37 = (char *)(( char * ) message); }
    {char * tlv39; tlv39 = (char *)(( char * ) message); }
    {cgc_size_t tlv41; tlv41 = (cgc_size_t)(( char * ) message); }
    {char * tlv19; tlv19 = (char *)(( char * ) message); }
    {unsigned int tlv18; tlv18 = (unsigned int)(( char * ) message); }
    {void * tlv22; tlv22 = (void *)(( char * ) message); }
    {void * tlv21; tlv21 = (void *)(( char * ) message); }
    {cgc_size_t tlv20; tlv20 = (cgc_size_t)(( char * ) message); }
    {char * tlv43; tlv43 = (char *)(( char * ) message); }
    {void * tlv5; tlv5 = (void *)(( char * ) message); }
    {unsigned int tlv44; tlv44 = (unsigned int)(( char * ) message); }
    {unsigned int tlv45; tlv45 = (unsigned int)(( char * ) message); }
    {char * tlv51; tlv51 = (char *)(( char * ) message); }
    {cgc_size_t tlv53; tlv53 = (cgc_size_t)(( char * ) message); }
    {char * tlv47; tlv47 = (char *)(( char * ) message); }
    {unsigned int tlv46; tlv46 = (unsigned int)(( char * ) message); }
    {void * tlv50; tlv50 = (void *)(( char * ) message); }
    {void * tlv49; tlv49 = (void *)(( char * ) message); }
    {cgc_size_t tlv48; tlv48 = (cgc_size_t)(( char * ) message); }
}
void fix_ingred_service_3_4_1(){
Message message_ref;
    bzero(&message_ref,1*sizeof(Message));
Message * message = &message_ref;
    {cgc_size_t bytes; bytes = (cgc_size_t)(sizeof ( Message )); }
    {cgc_size_t size; size = (cgc_size_t)(sizeof ( Message )); }
    {char * cmd_str; cmd_str = (char *)(sizeof ( Message )); }
    {char * auth_str; auth_str = (char *)(sizeof ( Message )); }
    {char * id_str; id_str = (char *)(sizeof ( Message )); }
    {char * cred_str; cred_str = (char *)(sizeof ( Message )); }
    {char * body_str; body_str = (char *)(sizeof ( Message )); }
    {char buffer [ 1024 ]; buffer [ ( 1024 )-1 ] = (char)(sizeof ( Message )); }
    {void * tlv1; tlv1 = (void *)(sizeof ( Message )); }
    {int tlv2; tlv2 = (int)(sizeof ( Message )); }
    {void * tlv3; tlv3 = (void *)(sizeof ( Message )); }
    {void * tlv4; tlv4 = (void *)(sizeof ( Message )); }
    {char * tlv7; tlv7 = (char *)(sizeof ( Message )); }
    {unsigned int tlv6; tlv6 = (unsigned int)(sizeof ( Message )); }
    {cgc_size_t tlv23; tlv23 = (cgc_size_t)(sizeof ( Message )); }
    {char * tlv9; tlv9 = (char *)(sizeof ( Message )); }
    {unsigned int tlv8; tlv8 = (unsigned int)(sizeof ( Message )); }
    {unsigned int tlv28; tlv28 = (unsigned int)(sizeof ( Message )); }
    {char * tlv27; tlv27 = (char *)(sizeof ( Message )); }
    {char tlv26; tlv26 = (char)(sizeof ( Message )); }
    {cgc_size_t tlv25; tlv25 = (cgc_size_t)(sizeof ( Message )); }
    {char * tlv30; tlv30 = (char *)(sizeof ( Message )); }
    {cgc_size_t tlv32; tlv32 = (cgc_size_t)(sizeof ( Message )); }
    {char * tlv11; tlv11 = (char *)(sizeof ( Message )); }
    {unsigned int tlv10; tlv10 = (unsigned int)(sizeof ( Message )); }
    {void * tlv14; tlv14 = (void *)(sizeof ( Message )); }
    {void * tlv13; tlv13 = (void *)(sizeof ( Message )); }
    {cgc_size_t tlv12; tlv12 = (cgc_size_t)(sizeof ( Message )); }
    {char * tlv34; tlv34 = (char *)(sizeof ( Message )); }
    {void * tlv17; tlv17 = (void *)(sizeof ( Message )); }
    {void * tlv16; tlv16 = (void *)(sizeof ( Message )); }
    {cgc_size_t tlv15; tlv15 = (cgc_size_t)(sizeof ( Message )); }
    {char * tlv37; tlv37 = (char *)(sizeof ( Message )); }
    {char * tlv39; tlv39 = (char *)(sizeof ( Message )); }
    {cgc_size_t tlv41; tlv41 = (cgc_size_t)(sizeof ( Message )); }
    {char * tlv19; tlv19 = (char *)(sizeof ( Message )); }
    {unsigned int tlv18; tlv18 = (unsigned int)(sizeof ( Message )); }
    {void * tlv22; tlv22 = (void *)(sizeof ( Message )); }
    {void * tlv21; tlv21 = (void *)(sizeof ( Message )); }
    {cgc_size_t tlv20; tlv20 = (cgc_size_t)(sizeof ( Message )); }
    {char * tlv43; tlv43 = (char *)(sizeof ( Message )); }
    {void * tlv5; tlv5 = (void *)(sizeof ( Message )); }
    {unsigned int tlv44; tlv44 = (unsigned int)(sizeof ( Message )); }
    {unsigned int tlv45; tlv45 = (unsigned int)(sizeof ( Message )); }
    {char * tlv51; tlv51 = (char *)(sizeof ( Message )); }
    {cgc_size_t tlv53; tlv53 = (cgc_size_t)(sizeof ( Message )); }
    {char * tlv47; tlv47 = (char *)(sizeof ( Message )); }
    {unsigned int tlv46; tlv46 = (unsigned int)(sizeof ( Message )); }
    {void * tlv50; tlv50 = (void *)(sizeof ( Message )); }
    {void * tlv49; tlv49 = (void *)(sizeof ( Message )); }
    {cgc_size_t tlv48; tlv48 = (cgc_size_t)(sizeof ( Message )); }
}
void fix_ingred_service_3_4(){
fix_ingred_service_3_4_0();
fix_ingred_service_3_4_1();
}
void fix_ingred_service_3_6_0(){
    {cgc_size_t bytes; bytes = (cgc_size_t)(1); }
    {cgc_size_t size; size = (cgc_size_t)(1); }
    {char * cmd_str; cmd_str = (char *)(1); }
    {char * auth_str; auth_str = (char *)(1); }
    {char * id_str; id_str = (char *)(1); }
    {char * cred_str; cred_str = (char *)(1); }
    {char * body_str; body_str = (char *)(1); }
    {char buffer [ 1024 ]; buffer [ ( 1024 )-1 ] = (char)(1); }
    {void * tlv1; tlv1 = (void *)(1); }
    {int tlv2; tlv2 = (int)(1); }
    {void * tlv3; tlv3 = (void *)(1); }
    {void * tlv4; tlv4 = (void *)(1); }
    {char * tlv7; tlv7 = (char *)(1); }
    {unsigned int tlv6; tlv6 = (unsigned int)(1); }
    {cgc_size_t tlv23; tlv23 = (cgc_size_t)(1); }
    {char * tlv9; tlv9 = (char *)(1); }
    {unsigned int tlv8; tlv8 = (unsigned int)(1); }
    {unsigned int tlv28; tlv28 = (unsigned int)(1); }
    {char * tlv27; tlv27 = (char *)(1); }
    {char tlv26; tlv26 = (char)(1); }
    {cgc_size_t tlv25; tlv25 = (cgc_size_t)(1); }
    {char * tlv30; tlv30 = (char *)(1); }
    {cgc_size_t tlv32; tlv32 = (cgc_size_t)(1); }
    {char * tlv11; tlv11 = (char *)(1); }
    {unsigned int tlv10; tlv10 = (unsigned int)(1); }
    {void * tlv14; tlv14 = (void *)(1); }
    {void * tlv13; tlv13 = (void *)(1); }
    {cgc_size_t tlv12; tlv12 = (cgc_size_t)(1); }
    {char * tlv34; tlv34 = (char *)(1); }
    {void * tlv17; tlv17 = (void *)(1); }
    {void * tlv16; tlv16 = (void *)(1); }
    {cgc_size_t tlv15; tlv15 = (cgc_size_t)(1); }
    {char * tlv37; tlv37 = (char *)(1); }
    {char * tlv39; tlv39 = (char *)(1); }
    {cgc_size_t tlv41; tlv41 = (cgc_size_t)(1); }
    {char * tlv19; tlv19 = (char *)(1); }
    {unsigned int tlv18; tlv18 = (unsigned int)(1); }
    {void * tlv22; tlv22 = (void *)(1); }
    {void * tlv21; tlv21 = (void *)(1); }
    {cgc_size_t tlv20; tlv20 = (cgc_size_t)(1); }
    {char * tlv43; tlv43 = (char *)(1); }
    {void * tlv5; tlv5 = (void *)(1); }
    {unsigned int tlv44; tlv44 = (unsigned int)(1); }
    {unsigned int tlv45; tlv45 = (unsigned int)(1); }
    {char * tlv51; tlv51 = (char *)(1); }
    {cgc_size_t tlv53; tlv53 = (cgc_size_t)(1); }
    {char * tlv47; tlv47 = (char *)(1); }
    {unsigned int tlv46; tlv46 = (unsigned int)(1); }
    {void * tlv50; tlv50 = (void *)(1); }
    {void * tlv49; tlv49 = (void *)(1); }
    {cgc_size_t tlv48; tlv48 = (cgc_size_t)(1); }
}
void fix_ingred_service_3_6(){
fix_ingred_service_3_6_0();
}
void fix_ingred_service_3_7_0(){
char buffer [ 1024 ];
    bzero(&buffer,( 1024 *sizeof(char) ) );
    {cgc_size_t bytes; bytes = (cgc_size_t)(STDIN); }
    {cgc_size_t size; size = (cgc_size_t)(STDIN); }
    {char * cmd_str; cmd_str = (char *)(STDIN); }
    {char * auth_str; auth_str = (char *)(STDIN); }
    {char * id_str; id_str = (char *)(STDIN); }
    {char * cred_str; cred_str = (char *)(STDIN); }
    {char * body_str; body_str = (char *)(STDIN); }
    {char buffer [ 1024 ]; buffer [ ( 1024 )-1 ] = (char)(STDIN); }
    {void * tlv1; tlv1 = (void *)(STDIN); }
    {int tlv2; tlv2 = (int)(STDIN); }
    {void * tlv3; tlv3 = (void *)(STDIN); }
    {void * tlv4; tlv4 = (void *)(STDIN); }
    {char * tlv7; tlv7 = (char *)(STDIN); }
    {unsigned int tlv6; tlv6 = (unsigned int)(STDIN); }
    {cgc_size_t tlv23; tlv23 = (cgc_size_t)(STDIN); }
    {char * tlv9; tlv9 = (char *)(STDIN); }
    {unsigned int tlv8; tlv8 = (unsigned int)(STDIN); }
    {unsigned int tlv28; tlv28 = (unsigned int)(STDIN); }
    {char * tlv27; tlv27 = (char *)(STDIN); }
    {char tlv26; tlv26 = (char)(STDIN); }
    {cgc_size_t tlv25; tlv25 = (cgc_size_t)(STDIN); }
    {char * tlv30; tlv30 = (char *)(STDIN); }
    {cgc_size_t tlv32; tlv32 = (cgc_size_t)(STDIN); }
    {char * tlv11; tlv11 = (char *)(STDIN); }
    {unsigned int tlv10; tlv10 = (unsigned int)(STDIN); }
    {void * tlv14; tlv14 = (void *)(STDIN); }
    {void * tlv13; tlv13 = (void *)(STDIN); }
    {cgc_size_t tlv12; tlv12 = (cgc_size_t)(STDIN); }
    {char * tlv34; tlv34 = (char *)(STDIN); }
    {void * tlv17; tlv17 = (void *)(STDIN); }
    {void * tlv16; tlv16 = (void *)(STDIN); }
    {cgc_size_t tlv15; tlv15 = (cgc_size_t)(STDIN); }
    {char * tlv37; tlv37 = (char *)(STDIN); }
    {char * tlv39; tlv39 = (char *)(STDIN); }
    {cgc_size_t tlv41; tlv41 = (cgc_size_t)(STDIN); }
    {char * tlv19; tlv19 = (char *)(STDIN); }
    {unsigned int tlv18; tlv18 = (unsigned int)(STDIN); }
    {void * tlv22; tlv22 = (void *)(STDIN); }
    {void * tlv21; tlv21 = (void *)(STDIN); }
    {cgc_size_t tlv20; tlv20 = (cgc_size_t)(STDIN); }
    {char * tlv43; tlv43 = (char *)(STDIN); }
    {void * tlv5; tlv5 = (void *)(STDIN); }
    {unsigned int tlv44; tlv44 = (unsigned int)(STDIN); }
    {unsigned int tlv45; tlv45 = (unsigned int)(STDIN); }
    {char * tlv51; tlv51 = (char *)(STDIN); }
    {cgc_size_t tlv53; tlv53 = (cgc_size_t)(STDIN); }
    {char * tlv47; tlv47 = (char *)(STDIN); }
    {unsigned int tlv46; tlv46 = (unsigned int)(STDIN); }
    {void * tlv50; tlv50 = (void *)(STDIN); }
    {void * tlv49; tlv49 = (void *)(STDIN); }
    {cgc_size_t tlv48; tlv48 = (cgc_size_t)(STDIN); }
}
void fix_ingred_service_3_7_2(){
char buffer [ 1024 ];
    bzero(&buffer,( 1024 *sizeof(char) ) );
    {cgc_size_t bytes; bytes = (cgc_size_t)('!'); }
    {cgc_size_t size; size = (cgc_size_t)('!'); }
    {char * cmd_str; cmd_str = (char *)('!'); }
    {char * auth_str; auth_str = (char *)('!'); }
    {char * id_str; id_str = (char *)('!'); }
    {char * cred_str; cred_str = (char *)('!'); }
    {char * body_str; body_str = (char *)('!'); }
    {char buffer [ 1024 ]; buffer [ ( 1024 )-1 ] = (char)('!'); }
    {void * tlv1; tlv1 = (void *)('!'); }
    {int tlv2; tlv2 = (int)('!'); }
    {void * tlv3; tlv3 = (void *)('!'); }
    {void * tlv4; tlv4 = (void *)('!'); }
    {char * tlv7; tlv7 = (char *)('!'); }
    {unsigned int tlv6; tlv6 = (unsigned int)('!'); }
    {cgc_size_t tlv23; tlv23 = (cgc_size_t)('!'); }
    {char * tlv9; tlv9 = (char *)('!'); }
    {unsigned int tlv8; tlv8 = (unsigned int)('!'); }
    {unsigned int tlv28; tlv28 = (unsigned int)('!'); }
    {char * tlv27; tlv27 = (char *)('!'); }
    {char tlv26; tlv26 = (char)('!'); }
    {cgc_size_t tlv25; tlv25 = (cgc_size_t)('!'); }
    {char * tlv30; tlv30 = (char *)('!'); }
    {cgc_size_t tlv32; tlv32 = (cgc_size_t)('!'); }
    {char * tlv11; tlv11 = (char *)('!'); }
    {unsigned int tlv10; tlv10 = (unsigned int)('!'); }
    {void * tlv14; tlv14 = (void *)('!'); }
    {void * tlv13; tlv13 = (void *)('!'); }
    {cgc_size_t tlv12; tlv12 = (cgc_size_t)('!'); }
    {char * tlv34; tlv34 = (char *)('!'); }
    {void * tlv17; tlv17 = (void *)('!'); }
    {void * tlv16; tlv16 = (void *)('!'); }
    {cgc_size_t tlv15; tlv15 = (cgc_size_t)('!'); }
    {char * tlv37; tlv37 = (char *)('!'); }
    {char * tlv39; tlv39 = (char *)('!'); }
    {cgc_size_t tlv41; tlv41 = (cgc_size_t)('!'); }
    {char * tlv19; tlv19 = (char *)('!'); }
    {unsigned int tlv18; tlv18 = (unsigned int)('!'); }
    {void * tlv22; tlv22 = (void *)('!'); }
    {void * tlv21; tlv21 = (void *)('!'); }
    {cgc_size_t tlv20; tlv20 = (cgc_size_t)('!'); }
    {char * tlv43; tlv43 = (char *)('!'); }
    {void * tlv5; tlv5 = (void *)('!'); }
    {unsigned int tlv44; tlv44 = (unsigned int)('!'); }
    {unsigned int tlv45; tlv45 = (unsigned int)('!'); }
    {char * tlv51; tlv51 = (char *)('!'); }
    {cgc_size_t tlv53; tlv53 = (cgc_size_t)('!'); }
    {char * tlv47; tlv47 = (char *)('!'); }
    {unsigned int tlv46; tlv46 = (unsigned int)('!'); }
    {void * tlv50; tlv50 = (void *)('!'); }
    {void * tlv49; tlv49 = (void *)('!'); }
    {cgc_size_t tlv48; tlv48 = (cgc_size_t)('!'); }
}
void fix_ingred_service_3_7_3(){
char buffer [ 1024 ];
    bzero(&buffer,( 1024 *sizeof(char) ) );
    {cgc_size_t bytes; bytes = (cgc_size_t)(sizeof ( buffer )); }
    {cgc_size_t size; size = (cgc_size_t)(sizeof ( buffer )); }
    {char * cmd_str; cmd_str = (char *)(sizeof ( buffer )); }
    {char * auth_str; auth_str = (char *)(sizeof ( buffer )); }
    {char * id_str; id_str = (char *)(sizeof ( buffer )); }
    {char * cred_str; cred_str = (char *)(sizeof ( buffer )); }
    {char * body_str; body_str = (char *)(sizeof ( buffer )); }
    {char buffer [ 1024 ]; buffer [ ( 1024 )-1 ] = (char)(sizeof ( buffer )); }
    {void * tlv1; tlv1 = (void *)(sizeof ( buffer )); }
    {int tlv2; tlv2 = (int)(sizeof ( buffer )); }
    {void * tlv3; tlv3 = (void *)(sizeof ( buffer )); }
    {void * tlv4; tlv4 = (void *)(sizeof ( buffer )); }
    {char * tlv7; tlv7 = (char *)(sizeof ( buffer )); }
    {unsigned int tlv6; tlv6 = (unsigned int)(sizeof ( buffer )); }
    {cgc_size_t tlv23; tlv23 = (cgc_size_t)(sizeof ( buffer )); }
    {char * tlv9; tlv9 = (char *)(sizeof ( buffer )); }
    {unsigned int tlv8; tlv8 = (unsigned int)(sizeof ( buffer )); }
    {unsigned int tlv28; tlv28 = (unsigned int)(sizeof ( buffer )); }
    {char * tlv27; tlv27 = (char *)(sizeof ( buffer )); }
    {char tlv26; tlv26 = (char)(sizeof ( buffer )); }
    {cgc_size_t tlv25; tlv25 = (cgc_size_t)(sizeof ( buffer )); }
    {char * tlv30; tlv30 = (char *)(sizeof ( buffer )); }
    {cgc_size_t tlv32; tlv32 = (cgc_size_t)(sizeof ( buffer )); }
    {char * tlv11; tlv11 = (char *)(sizeof ( buffer )); }
    {unsigned int tlv10; tlv10 = (unsigned int)(sizeof ( buffer )); }
    {void * tlv14; tlv14 = (void *)(sizeof ( buffer )); }
    {void * tlv13; tlv13 = (void *)(sizeof ( buffer )); }
    {cgc_size_t tlv12; tlv12 = (cgc_size_t)(sizeof ( buffer )); }
    {char * tlv34; tlv34 = (char *)(sizeof ( buffer )); }
    {void * tlv17; tlv17 = (void *)(sizeof ( buffer )); }
    {void * tlv16; tlv16 = (void *)(sizeof ( buffer )); }
    {cgc_size_t tlv15; tlv15 = (cgc_size_t)(sizeof ( buffer )); }
    {char * tlv37; tlv37 = (char *)(sizeof ( buffer )); }
    {char * tlv39; tlv39 = (char *)(sizeof ( buffer )); }
    {cgc_size_t tlv41; tlv41 = (cgc_size_t)(sizeof ( buffer )); }
    {char * tlv19; tlv19 = (char *)(sizeof ( buffer )); }
    {unsigned int tlv18; tlv18 = (unsigned int)(sizeof ( buffer )); }
    {void * tlv22; tlv22 = (void *)(sizeof ( buffer )); }
    {void * tlv21; tlv21 = (void *)(sizeof ( buffer )); }
    {cgc_size_t tlv20; tlv20 = (cgc_size_t)(sizeof ( buffer )); }
    {char * tlv43; tlv43 = (char *)(sizeof ( buffer )); }
    {void * tlv5; tlv5 = (void *)(sizeof ( buffer )); }
    {unsigned int tlv44; tlv44 = (unsigned int)(sizeof ( buffer )); }
    {unsigned int tlv45; tlv45 = (unsigned int)(sizeof ( buffer )); }
    {char * tlv51; tlv51 = (char *)(sizeof ( buffer )); }
    {cgc_size_t tlv53; tlv53 = (cgc_size_t)(sizeof ( buffer )); }
    {char * tlv47; tlv47 = (char *)(sizeof ( buffer )); }
    {unsigned int tlv46; tlv46 = (unsigned int)(sizeof ( buffer )); }
    {void * tlv50; tlv50 = (void *)(sizeof ( buffer )); }
    {void * tlv49; tlv49 = (void *)(sizeof ( buffer )); }
    {cgc_size_t tlv48; tlv48 = (cgc_size_t)(sizeof ( buffer )); }
}
void fix_ingred_service_3_7(){
fix_ingred_service_3_7_0();
fix_ingred_service_3_7_2();
fix_ingred_service_3_7_3();
}
void fix_ingred_service_3_9_0(){
    {cgc_size_t bytes; bytes = (cgc_size_t)(2); }
    {cgc_size_t size; size = (cgc_size_t)(2); }
    {char * cmd_str; cmd_str = (char *)(2); }
    {char * auth_str; auth_str = (char *)(2); }
    {char * id_str; id_str = (char *)(2); }
    {char * cred_str; cred_str = (char *)(2); }
    {char * body_str; body_str = (char *)(2); }
    {char buffer [ 1024 ]; buffer [ ( 1024 )-1 ] = (char)(2); }
    {void * tlv1; tlv1 = (void *)(2); }
    {int tlv2; tlv2 = (int)(2); }
    {void * tlv3; tlv3 = (void *)(2); }
    {void * tlv4; tlv4 = (void *)(2); }
    {char * tlv7; tlv7 = (char *)(2); }
    {unsigned int tlv6; tlv6 = (unsigned int)(2); }
    {cgc_size_t tlv23; tlv23 = (cgc_size_t)(2); }
    {char * tlv9; tlv9 = (char *)(2); }
    {unsigned int tlv8; tlv8 = (unsigned int)(2); }
    {unsigned int tlv28; tlv28 = (unsigned int)(2); }
    {char * tlv27; tlv27 = (char *)(2); }
    {char tlv26; tlv26 = (char)(2); }
    {cgc_size_t tlv25; tlv25 = (cgc_size_t)(2); }
    {char * tlv30; tlv30 = (char *)(2); }
    {cgc_size_t tlv32; tlv32 = (cgc_size_t)(2); }
    {char * tlv11; tlv11 = (char *)(2); }
    {unsigned int tlv10; tlv10 = (unsigned int)(2); }
    {void * tlv14; tlv14 = (void *)(2); }
    {void * tlv13; tlv13 = (void *)(2); }
    {cgc_size_t tlv12; tlv12 = (cgc_size_t)(2); }
    {char * tlv34; tlv34 = (char *)(2); }
    {void * tlv17; tlv17 = (void *)(2); }
    {void * tlv16; tlv16 = (void *)(2); }
    {cgc_size_t tlv15; tlv15 = (cgc_size_t)(2); }
    {char * tlv37; tlv37 = (char *)(2); }
    {char * tlv39; tlv39 = (char *)(2); }
    {cgc_size_t tlv41; tlv41 = (cgc_size_t)(2); }
    {char * tlv19; tlv19 = (char *)(2); }
    {unsigned int tlv18; tlv18 = (unsigned int)(2); }
    {void * tlv22; tlv22 = (void *)(2); }
    {void * tlv21; tlv21 = (void *)(2); }
    {cgc_size_t tlv20; tlv20 = (cgc_size_t)(2); }
    {char * tlv43; tlv43 = (char *)(2); }
    {void * tlv5; tlv5 = (void *)(2); }
    {unsigned int tlv44; tlv44 = (unsigned int)(2); }
    {unsigned int tlv45; tlv45 = (unsigned int)(2); }
    {char * tlv51; tlv51 = (char *)(2); }
    {cgc_size_t tlv53; tlv53 = (cgc_size_t)(2); }
    {char * tlv47; tlv47 = (char *)(2); }
    {unsigned int tlv46; tlv46 = (unsigned int)(2); }
    {void * tlv50; tlv50 = (void *)(2); }
    {void * tlv49; tlv49 = (void *)(2); }
    {cgc_size_t tlv48; tlv48 = (cgc_size_t)(2); }
}
void fix_ingred_service_3_9(){
fix_ingred_service_3_9_0();
}
void fix_ingred_service_3_12_0(){
char tlv31_ref;
    bzero(&tlv31_ref,1*sizeof(char));
const char * tlv31 = &tlv31_ref;
    {cgc_size_t bytes; bytes = (cgc_size_t)(cgc_strlen ( tlv31 )); }
    {cgc_size_t size; size = (cgc_size_t)(cgc_strlen ( tlv31 )); }
    {char * cmd_str; cmd_str = (char *)(cgc_strlen ( tlv31 )); }
    {char * auth_str; auth_str = (char *)(cgc_strlen ( tlv31 )); }
    {char * id_str; id_str = (char *)(cgc_strlen ( tlv31 )); }
    {char * cred_str; cred_str = (char *)(cgc_strlen ( tlv31 )); }
    {char * body_str; body_str = (char *)(cgc_strlen ( tlv31 )); }
    {char buffer [ 1024 ]; buffer [ ( 1024 )-1 ] = (char)(cgc_strlen ( tlv31 )); }
    {void * tlv1; tlv1 = (void *)(cgc_strlen ( tlv31 )); }
    {int tlv2; tlv2 = (int)(cgc_strlen ( tlv31 )); }
    {void * tlv3; tlv3 = (void *)(cgc_strlen ( tlv31 )); }
    {void * tlv4; tlv4 = (void *)(cgc_strlen ( tlv31 )); }
    {char * tlv7; tlv7 = (char *)(cgc_strlen ( tlv31 )); }
    {unsigned int tlv6; tlv6 = (unsigned int)(cgc_strlen ( tlv31 )); }
    {cgc_size_t tlv23; tlv23 = (cgc_size_t)(cgc_strlen ( tlv31 )); }
    {char * tlv9; tlv9 = (char *)(cgc_strlen ( tlv31 )); }
    {unsigned int tlv8; tlv8 = (unsigned int)(cgc_strlen ( tlv31 )); }
    {unsigned int tlv28; tlv28 = (unsigned int)(cgc_strlen ( tlv31 )); }
    {char * tlv27; tlv27 = (char *)(cgc_strlen ( tlv31 )); }
    {char tlv26; tlv26 = (char)(cgc_strlen ( tlv31 )); }
    {cgc_size_t tlv25; tlv25 = (cgc_size_t)(cgc_strlen ( tlv31 )); }
    {char * tlv30; tlv30 = (char *)(cgc_strlen ( tlv31 )); }
    {cgc_size_t tlv32; tlv32 = (cgc_size_t)(cgc_strlen ( tlv31 )); }
    {char * tlv11; tlv11 = (char *)(cgc_strlen ( tlv31 )); }
    {unsigned int tlv10; tlv10 = (unsigned int)(cgc_strlen ( tlv31 )); }
    {void * tlv14; tlv14 = (void *)(cgc_strlen ( tlv31 )); }
    {void * tlv13; tlv13 = (void *)(cgc_strlen ( tlv31 )); }
    {cgc_size_t tlv12; tlv12 = (cgc_size_t)(cgc_strlen ( tlv31 )); }
    {char * tlv34; tlv34 = (char *)(cgc_strlen ( tlv31 )); }
    {void * tlv17; tlv17 = (void *)(cgc_strlen ( tlv31 )); }
    {void * tlv16; tlv16 = (void *)(cgc_strlen ( tlv31 )); }
    {cgc_size_t tlv15; tlv15 = (cgc_size_t)(cgc_strlen ( tlv31 )); }
    {char * tlv37; tlv37 = (char *)(cgc_strlen ( tlv31 )); }
    {char * tlv39; tlv39 = (char *)(cgc_strlen ( tlv31 )); }
    {cgc_size_t tlv41; tlv41 = (cgc_size_t)(cgc_strlen ( tlv31 )); }
    {char * tlv19; tlv19 = (char *)(cgc_strlen ( tlv31 )); }
    {unsigned int tlv18; tlv18 = (unsigned int)(cgc_strlen ( tlv31 )); }
    {void * tlv22; tlv22 = (void *)(cgc_strlen ( tlv31 )); }
    {void * tlv21; tlv21 = (void *)(cgc_strlen ( tlv31 )); }
    {cgc_size_t tlv20; tlv20 = (cgc_size_t)(cgc_strlen ( tlv31 )); }
    {char * tlv43; tlv43 = (char *)(cgc_strlen ( tlv31 )); }
    {void * tlv5; tlv5 = (void *)(cgc_strlen ( tlv31 )); }
    {unsigned int tlv44; tlv44 = (unsigned int)(cgc_strlen ( tlv31 )); }
    {unsigned int tlv45; tlv45 = (unsigned int)(cgc_strlen ( tlv31 )); }
    {char * tlv51; tlv51 = (char *)(cgc_strlen ( tlv31 )); }
    {cgc_size_t tlv53; tlv53 = (cgc_size_t)(cgc_strlen ( tlv31 )); }
    {char * tlv47; tlv47 = (char *)(cgc_strlen ( tlv31 )); }
    {unsigned int tlv46; tlv46 = (unsigned int)(cgc_strlen ( tlv31 )); }
    {void * tlv50; tlv50 = (void *)(cgc_strlen ( tlv31 )); }
    {void * tlv49; tlv49 = (void *)(cgc_strlen ( tlv31 )); }
    {cgc_size_t tlv48; tlv48 = (cgc_size_t)(cgc_strlen ( tlv31 )); }
}
void fix_ingred_service_3_12(){
fix_ingred_service_3_12_0();
}
void fix_ingred_service_3_13_0(){
cgc_size_t size;
    bzero(&size,sizeof(cgc_size_t));
    {cgc_size_t bytes; bytes = (cgc_size_t)(MAX_CMD_SIZE); }
    {cgc_size_t size; size = (cgc_size_t)(MAX_CMD_SIZE); }
    {char * cmd_str; cmd_str = (char *)(MAX_CMD_SIZE); }
    {char * auth_str; auth_str = (char *)(MAX_CMD_SIZE); }
    {char * id_str; id_str = (char *)(MAX_CMD_SIZE); }
    {char * cred_str; cred_str = (char *)(MAX_CMD_SIZE); }
    {char * body_str; body_str = (char *)(MAX_CMD_SIZE); }
    {char buffer [ 1024 ]; buffer [ ( 1024 )-1 ] = (char)(MAX_CMD_SIZE); }
    {void * tlv1; tlv1 = (void *)(MAX_CMD_SIZE); }
    {int tlv2; tlv2 = (int)(MAX_CMD_SIZE); }
    {void * tlv3; tlv3 = (void *)(MAX_CMD_SIZE); }
    {void * tlv4; tlv4 = (void *)(MAX_CMD_SIZE); }
    {char * tlv7; tlv7 = (char *)(MAX_CMD_SIZE); }
    {unsigned int tlv6; tlv6 = (unsigned int)(MAX_CMD_SIZE); }
    {cgc_size_t tlv23; tlv23 = (cgc_size_t)(MAX_CMD_SIZE); }
    {char * tlv9; tlv9 = (char *)(MAX_CMD_SIZE); }
    {unsigned int tlv8; tlv8 = (unsigned int)(MAX_CMD_SIZE); }
    {unsigned int tlv28; tlv28 = (unsigned int)(MAX_CMD_SIZE); }
    {char * tlv27; tlv27 = (char *)(MAX_CMD_SIZE); }
    {char tlv26; tlv26 = (char)(MAX_CMD_SIZE); }
    {cgc_size_t tlv25; tlv25 = (cgc_size_t)(MAX_CMD_SIZE); }
    {char * tlv30; tlv30 = (char *)(MAX_CMD_SIZE); }
    {cgc_size_t tlv32; tlv32 = (cgc_size_t)(MAX_CMD_SIZE); }
    {char * tlv11; tlv11 = (char *)(MAX_CMD_SIZE); }
    {unsigned int tlv10; tlv10 = (unsigned int)(MAX_CMD_SIZE); }
    {void * tlv14; tlv14 = (void *)(MAX_CMD_SIZE); }
    {void * tlv13; tlv13 = (void *)(MAX_CMD_SIZE); }
    {cgc_size_t tlv12; tlv12 = (cgc_size_t)(MAX_CMD_SIZE); }
    {char * tlv34; tlv34 = (char *)(MAX_CMD_SIZE); }
    {void * tlv17; tlv17 = (void *)(MAX_CMD_SIZE); }
    {void * tlv16; tlv16 = (void *)(MAX_CMD_SIZE); }
    {cgc_size_t tlv15; tlv15 = (cgc_size_t)(MAX_CMD_SIZE); }
    {char * tlv37; tlv37 = (char *)(MAX_CMD_SIZE); }
    {char * tlv39; tlv39 = (char *)(MAX_CMD_SIZE); }
    {cgc_size_t tlv41; tlv41 = (cgc_size_t)(MAX_CMD_SIZE); }
    {char * tlv19; tlv19 = (char *)(MAX_CMD_SIZE); }
    {unsigned int tlv18; tlv18 = (unsigned int)(MAX_CMD_SIZE); }
    {void * tlv22; tlv22 = (void *)(MAX_CMD_SIZE); }
    {void * tlv21; tlv21 = (void *)(MAX_CMD_SIZE); }
    {cgc_size_t tlv20; tlv20 = (cgc_size_t)(MAX_CMD_SIZE); }
    {char * tlv43; tlv43 = (char *)(MAX_CMD_SIZE); }
    {void * tlv5; tlv5 = (void *)(MAX_CMD_SIZE); }
    {unsigned int tlv44; tlv44 = (unsigned int)(MAX_CMD_SIZE); }
    {unsigned int tlv45; tlv45 = (unsigned int)(MAX_CMD_SIZE); }
    {char * tlv51; tlv51 = (char *)(MAX_CMD_SIZE); }
    {cgc_size_t tlv53; tlv53 = (cgc_size_t)(MAX_CMD_SIZE); }
    {char * tlv47; tlv47 = (char *)(MAX_CMD_SIZE); }
    {unsigned int tlv46; tlv46 = (unsigned int)(MAX_CMD_SIZE); }
    {void * tlv50; tlv50 = (void *)(MAX_CMD_SIZE); }
    {void * tlv49; tlv49 = (void *)(MAX_CMD_SIZE); }
    {cgc_size_t tlv48; tlv48 = (cgc_size_t)(MAX_CMD_SIZE); }
}
void fix_ingred_service_3_13_1(){
cgc_size_t size;
    bzero(&size,sizeof(cgc_size_t));
    {cgc_size_t bytes; bytes = (cgc_size_t)(size); }
    {char * cmd_str; cmd_str = (char *)(size); }
    {char * auth_str; auth_str = (char *)(size); }
    {char * id_str; id_str = (char *)(size); }
    {char * cred_str; cred_str = (char *)(size); }
    {char * body_str; body_str = (char *)(size); }
    {char buffer [ 1024 ]; buffer [ ( 1024 )-1 ] = (char)(size); }
    {int tlv2; tlv2 = (int)(size); }
    {void * tlv3; tlv3 = (void *)(size); }
    {void * tlv4; tlv4 = (void *)(size); }
    {char * tlv7; tlv7 = (char *)(size); }
    {unsigned int tlv6; tlv6 = (unsigned int)(size); }
    {cgc_size_t tlv23; tlv23 = (cgc_size_t)(size); }
    {char * tlv9; tlv9 = (char *)(size); }
    {unsigned int tlv8; tlv8 = (unsigned int)(size); }
    {unsigned int tlv28; tlv28 = (unsigned int)(size); }
    {char * tlv27; tlv27 = (char *)(size); }
    {char tlv26; tlv26 = (char)(size); }
    {cgc_size_t tlv25; tlv25 = (cgc_size_t)(size); }
    {char * tlv30; tlv30 = (char *)(size); }
    {cgc_size_t tlv32; tlv32 = (cgc_size_t)(size); }
    {char * tlv11; tlv11 = (char *)(size); }
    {unsigned int tlv10; tlv10 = (unsigned int)(size); }
    {void * tlv14; tlv14 = (void *)(size); }
    {void * tlv13; tlv13 = (void *)(size); }
    {char * tlv34; tlv34 = (char *)(size); }
    {void * tlv17; tlv17 = (void *)(size); }
    {void * tlv16; tlv16 = (void *)(size); }
    {cgc_size_t tlv15; tlv15 = (cgc_size_t)(size); }
    {char * tlv37; tlv37 = (char *)(size); }
    {char * tlv39; tlv39 = (char *)(size); }
    {cgc_size_t tlv41; tlv41 = (cgc_size_t)(size); }
    {char * tlv19; tlv19 = (char *)(size); }
    {unsigned int tlv18; tlv18 = (unsigned int)(size); }
    {void * tlv22; tlv22 = (void *)(size); }
    {void * tlv21; tlv21 = (void *)(size); }
    {cgc_size_t tlv20; tlv20 = (cgc_size_t)(size); }
    {char * tlv43; tlv43 = (char *)(size); }
    {void * tlv5; tlv5 = (void *)(size); }
    {unsigned int tlv44; tlv44 = (unsigned int)(size); }
    {unsigned int tlv45; tlv45 = (unsigned int)(size); }
    {char * tlv51; tlv51 = (char *)(size); }
    {cgc_size_t tlv53; tlv53 = (cgc_size_t)(size); }
    {char * tlv47; tlv47 = (char *)(size); }
    {unsigned int tlv46; tlv46 = (unsigned int)(size); }
    {void * tlv50; tlv50 = (void *)(size); }
    {void * tlv49; tlv49 = (void *)(size); }
    {cgc_size_t tlv48; tlv48 = (cgc_size_t)(size); }
}
void fix_ingred_service_3_13(){
fix_ingred_service_3_13_0();
fix_ingred_service_3_13_1();
}
void fix_ingred_service_3_14_0(){
cgc_size_t size;
    bzero(&size,sizeof(cgc_size_t));
    {cgc_size_t bytes; bytes = (cgc_size_t)(size + 1); }
    {char * cmd_str; cmd_str = (char *)(size + 1); }
    {char * auth_str; auth_str = (char *)(size + 1); }
    {char * id_str; id_str = (char *)(size + 1); }
    {char * cred_str; cred_str = (char *)(size + 1); }
    {char * body_str; body_str = (char *)(size + 1); }
    {char buffer [ 1024 ]; buffer [ ( 1024 )-1 ] = (char)(size + 1); }
    {int tlv2; tlv2 = (int)(size + 1); }
    {void * tlv3; tlv3 = (void *)(size + 1); }
    {void * tlv4; tlv4 = (void *)(size + 1); }
    {char * tlv7; tlv7 = (char *)(size + 1); }
    {unsigned int tlv6; tlv6 = (unsigned int)(size + 1); }
    {cgc_size_t tlv23; tlv23 = (cgc_size_t)(size + 1); }
    {char * tlv9; tlv9 = (char *)(size + 1); }
    {unsigned int tlv8; tlv8 = (unsigned int)(size + 1); }
    {unsigned int tlv28; tlv28 = (unsigned int)(size + 1); }
    {char * tlv27; tlv27 = (char *)(size + 1); }
    {char tlv26; tlv26 = (char)(size + 1); }
    {cgc_size_t tlv25; tlv25 = (cgc_size_t)(size + 1); }
    {char * tlv30; tlv30 = (char *)(size + 1); }
    {cgc_size_t tlv32; tlv32 = (cgc_size_t)(size + 1); }
    {char * tlv11; tlv11 = (char *)(size + 1); }
    {unsigned int tlv10; tlv10 = (unsigned int)(size + 1); }
    {void * tlv14; tlv14 = (void *)(size + 1); }
    {void * tlv13; tlv13 = (void *)(size + 1); }
    {char * tlv34; tlv34 = (char *)(size + 1); }
    {void * tlv17; tlv17 = (void *)(size + 1); }
    {void * tlv16; tlv16 = (void *)(size + 1); }
    {cgc_size_t tlv15; tlv15 = (cgc_size_t)(size + 1); }
    {char * tlv37; tlv37 = (char *)(size + 1); }
    {char * tlv39; tlv39 = (char *)(size + 1); }
    {cgc_size_t tlv41; tlv41 = (cgc_size_t)(size + 1); }
    {char * tlv19; tlv19 = (char *)(size + 1); }
    {unsigned int tlv18; tlv18 = (unsigned int)(size + 1); }
    {void * tlv22; tlv22 = (void *)(size + 1); }
    {void * tlv21; tlv21 = (void *)(size + 1); }
    {cgc_size_t tlv20; tlv20 = (cgc_size_t)(size + 1); }
    {char * tlv43; tlv43 = (char *)(size + 1); }
    {void * tlv5; tlv5 = (void *)(size + 1); }
    {unsigned int tlv44; tlv44 = (unsigned int)(size + 1); }
    {unsigned int tlv45; tlv45 = (unsigned int)(size + 1); }
    {char * tlv51; tlv51 = (char *)(size + 1); }
    {cgc_size_t tlv53; tlv53 = (cgc_size_t)(size + 1); }
    {char * tlv47; tlv47 = (char *)(size + 1); }
    {unsigned int tlv46; tlv46 = (unsigned int)(size + 1); }
    {void * tlv50; tlv50 = (void *)(size + 1); }
    {void * tlv49; tlv49 = (void *)(size + 1); }
    {cgc_size_t tlv48; tlv48 = (cgc_size_t)(size + 1); }
}
void fix_ingred_service_3_14(){
fix_ingred_service_3_14_0();
}
void fix_ingred_service_3_16_0(){
Message message_ref;
    bzero(&message_ref,1*sizeof(Message));
Message * message = &message_ref;
cgc_size_t size;
    bzero(&size,sizeof(cgc_size_t));
    {cgc_size_t bytes; bytes = (cgc_size_t)(message -> command); }
    {cgc_size_t size; size = (cgc_size_t)(message -> command); }
    {char * cmd_str; cmd_str = (char *)(message -> command); }
    {char * auth_str; auth_str = (char *)(message -> command); }
    {char * id_str; id_str = (char *)(message -> command); }
    {char * cred_str; cred_str = (char *)(message -> command); }
    {char * body_str; body_str = (char *)(message -> command); }
    {char buffer [ 1024 ]; buffer [ ( 1024 )-1 ] = (char)(message -> command); }
    {void * tlv1; tlv1 = (void *)(message -> command); }
    {int tlv2; tlv2 = (int)(message -> command); }
    {void * tlv3; tlv3 = (void *)(message -> command); }
    {void * tlv4; tlv4 = (void *)(message -> command); }
    {char * tlv7; tlv7 = (char *)(message -> command); }
    {unsigned int tlv6; tlv6 = (unsigned int)(message -> command); }
    {cgc_size_t tlv23; tlv23 = (cgc_size_t)(message -> command); }
    {char * tlv9; tlv9 = (char *)(message -> command); }
    {unsigned int tlv8; tlv8 = (unsigned int)(message -> command); }
    {unsigned int tlv28; tlv28 = (unsigned int)(message -> command); }
    {char * tlv27; tlv27 = (char *)(message -> command); }
    {char tlv26; tlv26 = (char)(message -> command); }
    {cgc_size_t tlv25; tlv25 = (cgc_size_t)(message -> command); }
    {char * tlv30; tlv30 = (char *)(message -> command); }
    {cgc_size_t tlv32; tlv32 = (cgc_size_t)(message -> command); }
    {char * tlv11; tlv11 = (char *)(message -> command); }
    {unsigned int tlv10; tlv10 = (unsigned int)(message -> command); }
    {void * tlv14; tlv14 = (void *)(message -> command); }
    {void * tlv13; tlv13 = (void *)(message -> command); }
    {cgc_size_t tlv12; tlv12 = (cgc_size_t)(message -> command); }
    {char * tlv34; tlv34 = (char *)(message -> command); }
    {void * tlv17; tlv17 = (void *)(message -> command); }
    {void * tlv16; tlv16 = (void *)(message -> command); }
    {cgc_size_t tlv15; tlv15 = (cgc_size_t)(message -> command); }
    {char * tlv37; tlv37 = (char *)(message -> command); }
    {char * tlv39; tlv39 = (char *)(message -> command); }
    {cgc_size_t tlv41; tlv41 = (cgc_size_t)(message -> command); }
    {char * tlv19; tlv19 = (char *)(message -> command); }
    {unsigned int tlv18; tlv18 = (unsigned int)(message -> command); }
    {void * tlv22; tlv22 = (void *)(message -> command); }
    {void * tlv21; tlv21 = (void *)(message -> command); }
    {cgc_size_t tlv20; tlv20 = (cgc_size_t)(message -> command); }
    {char * tlv43; tlv43 = (char *)(message -> command); }
    {void * tlv5; tlv5 = (void *)(message -> command); }
    {unsigned int tlv44; tlv44 = (unsigned int)(message -> command); }
    {unsigned int tlv45; tlv45 = (unsigned int)(message -> command); }
    {char * tlv51; tlv51 = (char *)(message -> command); }
    {cgc_size_t tlv53; tlv53 = (cgc_size_t)(message -> command); }
    {char * tlv47; tlv47 = (char *)(message -> command); }
    {unsigned int tlv46; tlv46 = (unsigned int)(message -> command); }
    {void * tlv50; tlv50 = (void *)(message -> command); }
    {void * tlv49; tlv49 = (void *)(message -> command); }
    {cgc_size_t tlv48; tlv48 = (cgc_size_t)(message -> command); }
}
void fix_ingred_service_3_16_1(){
Message message_ref;
    bzero(&message_ref,1*sizeof(Message));
Message * message = &message_ref;
cgc_size_t size;
    bzero(&size,sizeof(cgc_size_t));
    {cgc_size_t bytes; bytes = (cgc_size_t)(size + 1); }
    {char * cmd_str; cmd_str = (char *)(size + 1); }
    {char * auth_str; auth_str = (char *)(size + 1); }
    {char * id_str; id_str = (char *)(size + 1); }
    {char * cred_str; cred_str = (char *)(size + 1); }
    {char * body_str; body_str = (char *)(size + 1); }
    {char buffer [ 1024 ]; buffer [ ( 1024 )-1 ] = (char)(size + 1); }
    {int tlv2; tlv2 = (int)(size + 1); }
    {void * tlv3; tlv3 = (void *)(size + 1); }
    {void * tlv4; tlv4 = (void *)(size + 1); }
    {char * tlv7; tlv7 = (char *)(size + 1); }
    {unsigned int tlv6; tlv6 = (unsigned int)(size + 1); }
    {cgc_size_t tlv23; tlv23 = (cgc_size_t)(size + 1); }
    {char * tlv9; tlv9 = (char *)(size + 1); }
    {unsigned int tlv8; tlv8 = (unsigned int)(size + 1); }
    {unsigned int tlv28; tlv28 = (unsigned int)(size + 1); }
    {char * tlv27; tlv27 = (char *)(size + 1); }
    {char tlv26; tlv26 = (char)(size + 1); }
    {cgc_size_t tlv25; tlv25 = (cgc_size_t)(size + 1); }
    {char * tlv30; tlv30 = (char *)(size + 1); }
    {cgc_size_t tlv32; tlv32 = (cgc_size_t)(size + 1); }
    {char * tlv11; tlv11 = (char *)(size + 1); }
    {unsigned int tlv10; tlv10 = (unsigned int)(size + 1); }
    {void * tlv14; tlv14 = (void *)(size + 1); }
    {void * tlv13; tlv13 = (void *)(size + 1); }
    {char * tlv34; tlv34 = (char *)(size + 1); }
    {void * tlv17; tlv17 = (void *)(size + 1); }
    {void * tlv16; tlv16 = (void *)(size + 1); }
    {cgc_size_t tlv15; tlv15 = (cgc_size_t)(size + 1); }
    {char * tlv37; tlv37 = (char *)(size + 1); }
    {char * tlv39; tlv39 = (char *)(size + 1); }
    {cgc_size_t tlv41; tlv41 = (cgc_size_t)(size + 1); }
    {char * tlv19; tlv19 = (char *)(size + 1); }
    {unsigned int tlv18; tlv18 = (unsigned int)(size + 1); }
    {void * tlv22; tlv22 = (void *)(size + 1); }
    {void * tlv21; tlv21 = (void *)(size + 1); }
    {cgc_size_t tlv20; tlv20 = (cgc_size_t)(size + 1); }
    {char * tlv43; tlv43 = (char *)(size + 1); }
    {void * tlv5; tlv5 = (void *)(size + 1); }
    {unsigned int tlv44; tlv44 = (unsigned int)(size + 1); }
    {unsigned int tlv45; tlv45 = (unsigned int)(size + 1); }
    {char * tlv51; tlv51 = (char *)(size + 1); }
    {cgc_size_t tlv53; tlv53 = (cgc_size_t)(size + 1); }
    {char * tlv47; tlv47 = (char *)(size + 1); }
    {unsigned int tlv46; tlv46 = (unsigned int)(size + 1); }
    {void * tlv50; tlv50 = (void *)(size + 1); }
    {void * tlv49; tlv49 = (void *)(size + 1); }
    {cgc_size_t tlv48; tlv48 = (cgc_size_t)(size + 1); }
}
void fix_ingred_service_3_16(){
fix_ingred_service_3_16_0();
fix_ingred_service_3_16_1();
}
void fix_ingred_service_3_17_0(){
Message message_ref;
    bzero(&message_ref,1*sizeof(Message));
Message * message = &message_ref;
char cmd_str_ref;
    bzero(&cmd_str_ref,1*sizeof(char));
char * cmd_str = &cmd_str_ref;
    {cgc_size_t bytes; bytes = (cgc_size_t)(message -> command); }
    {cgc_size_t size; size = (cgc_size_t)(message -> command); }
    {char * cmd_str; cmd_str = (char *)(message -> command); }
    {char * auth_str; auth_str = (char *)(message -> command); }
    {char * id_str; id_str = (char *)(message -> command); }
    {char * cred_str; cred_str = (char *)(message -> command); }
    {char * body_str; body_str = (char *)(message -> command); }
    {char buffer [ 1024 ]; buffer [ ( 1024 )-1 ] = (char)(message -> command); }
    {void * tlv1; tlv1 = (void *)(message -> command); }
    {int tlv2; tlv2 = (int)(message -> command); }
    {void * tlv3; tlv3 = (void *)(message -> command); }
    {void * tlv4; tlv4 = (void *)(message -> command); }
    {char * tlv7; tlv7 = (char *)(message -> command); }
    {unsigned int tlv6; tlv6 = (unsigned int)(message -> command); }
    {cgc_size_t tlv23; tlv23 = (cgc_size_t)(message -> command); }
    {char * tlv9; tlv9 = (char *)(message -> command); }
    {unsigned int tlv8; tlv8 = (unsigned int)(message -> command); }
    {unsigned int tlv28; tlv28 = (unsigned int)(message -> command); }
    {char * tlv27; tlv27 = (char *)(message -> command); }
    {char tlv26; tlv26 = (char)(message -> command); }
    {cgc_size_t tlv25; tlv25 = (cgc_size_t)(message -> command); }
    {char * tlv30; tlv30 = (char *)(message -> command); }
    {cgc_size_t tlv32; tlv32 = (cgc_size_t)(message -> command); }
    {char * tlv11; tlv11 = (char *)(message -> command); }
    {unsigned int tlv10; tlv10 = (unsigned int)(message -> command); }
    {void * tlv14; tlv14 = (void *)(message -> command); }
    {void * tlv13; tlv13 = (void *)(message -> command); }
    {cgc_size_t tlv12; tlv12 = (cgc_size_t)(message -> command); }
    {char * tlv34; tlv34 = (char *)(message -> command); }
    {void * tlv17; tlv17 = (void *)(message -> command); }
    {void * tlv16; tlv16 = (void *)(message -> command); }
    {cgc_size_t tlv15; tlv15 = (cgc_size_t)(message -> command); }
    {char * tlv37; tlv37 = (char *)(message -> command); }
    {char * tlv39; tlv39 = (char *)(message -> command); }
    {cgc_size_t tlv41; tlv41 = (cgc_size_t)(message -> command); }
    {char * tlv19; tlv19 = (char *)(message -> command); }
    {unsigned int tlv18; tlv18 = (unsigned int)(message -> command); }
    {void * tlv22; tlv22 = (void *)(message -> command); }
    {void * tlv21; tlv21 = (void *)(message -> command); }
    {cgc_size_t tlv20; tlv20 = (cgc_size_t)(message -> command); }
    {char * tlv43; tlv43 = (char *)(message -> command); }
    {void * tlv5; tlv5 = (void *)(message -> command); }
    {unsigned int tlv44; tlv44 = (unsigned int)(message -> command); }
    {unsigned int tlv45; tlv45 = (unsigned int)(message -> command); }
    {char * tlv51; tlv51 = (char *)(message -> command); }
    {cgc_size_t tlv53; tlv53 = (cgc_size_t)(message -> command); }
    {char * tlv47; tlv47 = (char *)(message -> command); }
    {unsigned int tlv46; tlv46 = (unsigned int)(message -> command); }
    {void * tlv50; tlv50 = (void *)(message -> command); }
    {void * tlv49; tlv49 = (void *)(message -> command); }
    {cgc_size_t tlv48; tlv48 = (cgc_size_t)(message -> command); }
}
void fix_ingred_service_3_17_1(){
Message message_ref;
    bzero(&message_ref,1*sizeof(Message));
Message * message = &message_ref;
char cmd_str_ref;
    bzero(&cmd_str_ref,1*sizeof(char));
char * cmd_str = &cmd_str_ref;
    {cgc_size_t bytes; bytes = (cgc_size_t)(cmd_str); }
    {cgc_size_t size; size = (cgc_size_t)(cmd_str); }
    {char * auth_str; auth_str = (char *)(cmd_str); }
    {char * id_str; id_str = (char *)(cmd_str); }
    {char * cred_str; cred_str = (char *)(cmd_str); }
    {char * body_str; body_str = (char *)(cmd_str); }
    {char buffer [ 1024 ]; buffer [ ( 1024 )-1 ] = (char)(cmd_str); }
    {void * tlv1; tlv1 = (void *)(cmd_str); }
    {int tlv2; tlv2 = (int)(cmd_str); }
    {void * tlv3; tlv3 = (void *)(cmd_str); }
    {void * tlv4; tlv4 = (void *)(cmd_str); }
    {char * tlv7; tlv7 = (char *)(cmd_str); }
    {unsigned int tlv6; tlv6 = (unsigned int)(cmd_str); }
    {cgc_size_t tlv23; tlv23 = (cgc_size_t)(cmd_str); }
    {char * tlv9; tlv9 = (char *)(cmd_str); }
    {unsigned int tlv8; tlv8 = (unsigned int)(cmd_str); }
    {unsigned int tlv28; tlv28 = (unsigned int)(cmd_str); }
    {char * tlv27; tlv27 = (char *)(cmd_str); }
    {char tlv26; tlv26 = (char)(cmd_str); }
    {cgc_size_t tlv25; tlv25 = (cgc_size_t)(cmd_str); }
    {char * tlv30; tlv30 = (char *)(cmd_str); }
    {cgc_size_t tlv32; tlv32 = (cgc_size_t)(cmd_str); }
    {char * tlv11; tlv11 = (char *)(cmd_str); }
    {unsigned int tlv10; tlv10 = (unsigned int)(cmd_str); }
    {void * tlv14; tlv14 = (void *)(cmd_str); }
    {void * tlv13; tlv13 = (void *)(cmd_str); }
    {cgc_size_t tlv12; tlv12 = (cgc_size_t)(cmd_str); }
    {char * tlv34; tlv34 = (char *)(cmd_str); }
    {void * tlv17; tlv17 = (void *)(cmd_str); }
    {void * tlv16; tlv16 = (void *)(cmd_str); }
    {cgc_size_t tlv15; tlv15 = (cgc_size_t)(cmd_str); }
    {char * tlv37; tlv37 = (char *)(cmd_str); }
    {char * tlv39; tlv39 = (char *)(cmd_str); }
    {cgc_size_t tlv41; tlv41 = (cgc_size_t)(cmd_str); }
    {char * tlv19; tlv19 = (char *)(cmd_str); }
    {unsigned int tlv18; tlv18 = (unsigned int)(cmd_str); }
    {void * tlv22; tlv22 = (void *)(cmd_str); }
    {void * tlv21; tlv21 = (void *)(cmd_str); }
    {cgc_size_t tlv20; tlv20 = (cgc_size_t)(cmd_str); }
    {char * tlv43; tlv43 = (char *)(cmd_str); }
    {void * tlv5; tlv5 = (void *)(cmd_str); }
    {unsigned int tlv44; tlv44 = (unsigned int)(cmd_str); }
    {unsigned int tlv45; tlv45 = (unsigned int)(cmd_str); }
    {char * tlv51; tlv51 = (char *)(cmd_str); }
    {cgc_size_t tlv53; tlv53 = (cgc_size_t)(cmd_str); }
    {char * tlv47; tlv47 = (char *)(cmd_str); }
    {unsigned int tlv46; tlv46 = (unsigned int)(cmd_str); }
    {void * tlv50; tlv50 = (void *)(cmd_str); }
    {void * tlv49; tlv49 = (void *)(cmd_str); }
    {cgc_size_t tlv48; tlv48 = (cgc_size_t)(cmd_str); }
}
void fix_ingred_service_3_17(){
fix_ingred_service_3_17_0();
fix_ingred_service_3_17_1();
}
void fix_ingred_service_3_18_0(){
    {cgc_size_t bytes; bytes = (cgc_size_t)(0); }
    {cgc_size_t size; size = (cgc_size_t)(0); }
    {char * cmd_str; cmd_str = (char *)(0); }
    {char * auth_str; auth_str = (char *)(0); }
    {char * id_str; id_str = (char *)(0); }
    {char * cred_str; cred_str = (char *)(0); }
    {char * body_str; body_str = (char *)(0); }
    {char buffer [ 1024 ]; buffer [ ( 1024 )-1 ] = (char)(0); }
    {void * tlv1; tlv1 = (void *)(0); }
    {int tlv2; tlv2 = (int)(0); }
    {void * tlv3; tlv3 = (void *)(0); }
    {void * tlv4; tlv4 = (void *)(0); }
    {char * tlv7; tlv7 = (char *)(0); }
    {unsigned int tlv6; tlv6 = (unsigned int)(0); }
    {cgc_size_t tlv23; tlv23 = (cgc_size_t)(0); }
    {char * tlv9; tlv9 = (char *)(0); }
    {unsigned int tlv8; tlv8 = (unsigned int)(0); }
    {unsigned int tlv28; tlv28 = (unsigned int)(0); }
    {char * tlv27; tlv27 = (char *)(0); }
    {char tlv26; tlv26 = (char)(0); }
    {cgc_size_t tlv25; tlv25 = (cgc_size_t)(0); }
    {char * tlv30; tlv30 = (char *)(0); }
    {cgc_size_t tlv32; tlv32 = (cgc_size_t)(0); }
    {char * tlv11; tlv11 = (char *)(0); }
    {unsigned int tlv10; tlv10 = (unsigned int)(0); }
    {void * tlv14; tlv14 = (void *)(0); }
    {void * tlv13; tlv13 = (void *)(0); }
    {cgc_size_t tlv12; tlv12 = (cgc_size_t)(0); }
    {char * tlv34; tlv34 = (char *)(0); }
    {void * tlv17; tlv17 = (void *)(0); }
    {void * tlv16; tlv16 = (void *)(0); }
    {cgc_size_t tlv15; tlv15 = (cgc_size_t)(0); }
    {char * tlv37; tlv37 = (char *)(0); }
    {char * tlv39; tlv39 = (char *)(0); }
    {cgc_size_t tlv41; tlv41 = (cgc_size_t)(0); }
    {char * tlv19; tlv19 = (char *)(0); }
    {unsigned int tlv18; tlv18 = (unsigned int)(0); }
    {void * tlv22; tlv22 = (void *)(0); }
    {void * tlv21; tlv21 = (void *)(0); }
    {cgc_size_t tlv20; tlv20 = (cgc_size_t)(0); }
    {char * tlv43; tlv43 = (char *)(0); }
    {void * tlv5; tlv5 = (void *)(0); }
    {unsigned int tlv44; tlv44 = (unsigned int)(0); }
    {unsigned int tlv45; tlv45 = (unsigned int)(0); }
    {char * tlv51; tlv51 = (char *)(0); }
    {cgc_size_t tlv53; tlv53 = (cgc_size_t)(0); }
    {char * tlv47; tlv47 = (char *)(0); }
    {unsigned int tlv46; tlv46 = (unsigned int)(0); }
    {void * tlv50; tlv50 = (void *)(0); }
    {void * tlv49; tlv49 = (void *)(0); }
    {cgc_size_t tlv48; tlv48 = (cgc_size_t)(0); }
}
void fix_ingred_service_3_18(){
fix_ingred_service_3_18_0();
}
void fix_ingred_service_3_20_0(){
char tlv35_ref;
    bzero(&tlv35_ref,1*sizeof(char));
const char * tlv35 = &tlv35_ref;
    {cgc_size_t bytes; bytes = (cgc_size_t)(cgc_strlen ( tlv35 )); }
    {cgc_size_t size; size = (cgc_size_t)(cgc_strlen ( tlv35 )); }
    {char * cmd_str; cmd_str = (char *)(cgc_strlen ( tlv35 )); }
    {char * auth_str; auth_str = (char *)(cgc_strlen ( tlv35 )); }
    {char * id_str; id_str = (char *)(cgc_strlen ( tlv35 )); }
    {char * cred_str; cred_str = (char *)(cgc_strlen ( tlv35 )); }
    {char * body_str; body_str = (char *)(cgc_strlen ( tlv35 )); }
    {char buffer [ 1024 ]; buffer [ ( 1024 )-1 ] = (char)(cgc_strlen ( tlv35 )); }
    {void * tlv1; tlv1 = (void *)(cgc_strlen ( tlv35 )); }
    {int tlv2; tlv2 = (int)(cgc_strlen ( tlv35 )); }
    {void * tlv3; tlv3 = (void *)(cgc_strlen ( tlv35 )); }
    {void * tlv4; tlv4 = (void *)(cgc_strlen ( tlv35 )); }
    {char * tlv7; tlv7 = (char *)(cgc_strlen ( tlv35 )); }
    {unsigned int tlv6; tlv6 = (unsigned int)(cgc_strlen ( tlv35 )); }
    {cgc_size_t tlv23; tlv23 = (cgc_size_t)(cgc_strlen ( tlv35 )); }
    {char * tlv9; tlv9 = (char *)(cgc_strlen ( tlv35 )); }
    {unsigned int tlv8; tlv8 = (unsigned int)(cgc_strlen ( tlv35 )); }
    {unsigned int tlv28; tlv28 = (unsigned int)(cgc_strlen ( tlv35 )); }
    {char * tlv27; tlv27 = (char *)(cgc_strlen ( tlv35 )); }
    {char tlv26; tlv26 = (char)(cgc_strlen ( tlv35 )); }
    {cgc_size_t tlv25; tlv25 = (cgc_size_t)(cgc_strlen ( tlv35 )); }
    {char * tlv30; tlv30 = (char *)(cgc_strlen ( tlv35 )); }
    {cgc_size_t tlv32; tlv32 = (cgc_size_t)(cgc_strlen ( tlv35 )); }
    {char * tlv11; tlv11 = (char *)(cgc_strlen ( tlv35 )); }
    {unsigned int tlv10; tlv10 = (unsigned int)(cgc_strlen ( tlv35 )); }
    {void * tlv14; tlv14 = (void *)(cgc_strlen ( tlv35 )); }
    {void * tlv13; tlv13 = (void *)(cgc_strlen ( tlv35 )); }
    {cgc_size_t tlv12; tlv12 = (cgc_size_t)(cgc_strlen ( tlv35 )); }
    {char * tlv34; tlv34 = (char *)(cgc_strlen ( tlv35 )); }
    {void * tlv17; tlv17 = (void *)(cgc_strlen ( tlv35 )); }
    {void * tlv16; tlv16 = (void *)(cgc_strlen ( tlv35 )); }
    {cgc_size_t tlv15; tlv15 = (cgc_size_t)(cgc_strlen ( tlv35 )); }
    {char * tlv37; tlv37 = (char *)(cgc_strlen ( tlv35 )); }
    {char * tlv39; tlv39 = (char *)(cgc_strlen ( tlv35 )); }
    {cgc_size_t tlv41; tlv41 = (cgc_size_t)(cgc_strlen ( tlv35 )); }
    {char * tlv19; tlv19 = (char *)(cgc_strlen ( tlv35 )); }
    {unsigned int tlv18; tlv18 = (unsigned int)(cgc_strlen ( tlv35 )); }
    {void * tlv22; tlv22 = (void *)(cgc_strlen ( tlv35 )); }
    {void * tlv21; tlv21 = (void *)(cgc_strlen ( tlv35 )); }
    {cgc_size_t tlv20; tlv20 = (cgc_size_t)(cgc_strlen ( tlv35 )); }
    {char * tlv43; tlv43 = (char *)(cgc_strlen ( tlv35 )); }
    {void * tlv5; tlv5 = (void *)(cgc_strlen ( tlv35 )); }
    {unsigned int tlv44; tlv44 = (unsigned int)(cgc_strlen ( tlv35 )); }
    {unsigned int tlv45; tlv45 = (unsigned int)(cgc_strlen ( tlv35 )); }
    {char * tlv51; tlv51 = (char *)(cgc_strlen ( tlv35 )); }
    {cgc_size_t tlv53; tlv53 = (cgc_size_t)(cgc_strlen ( tlv35 )); }
    {char * tlv47; tlv47 = (char *)(cgc_strlen ( tlv35 )); }
    {unsigned int tlv46; tlv46 = (unsigned int)(cgc_strlen ( tlv35 )); }
    {void * tlv50; tlv50 = (void *)(cgc_strlen ( tlv35 )); }
    {void * tlv49; tlv49 = (void *)(cgc_strlen ( tlv35 )); }
    {cgc_size_t tlv48; tlv48 = (cgc_size_t)(cgc_strlen ( tlv35 )); }
}
void fix_ingred_service_3_20(){
fix_ingred_service_3_20_0();
}
void fix_ingred_service_3_21_0(){
    {cgc_size_t bytes; bytes = (cgc_size_t)(MAX_AUTH_TYPE_SIZE); }
    {cgc_size_t size; size = (cgc_size_t)(MAX_AUTH_TYPE_SIZE); }
    {char * cmd_str; cmd_str = (char *)(MAX_AUTH_TYPE_SIZE); }
    {char * auth_str; auth_str = (char *)(MAX_AUTH_TYPE_SIZE); }
    {char * id_str; id_str = (char *)(MAX_AUTH_TYPE_SIZE); }
    {char * cred_str; cred_str = (char *)(MAX_AUTH_TYPE_SIZE); }
    {char * body_str; body_str = (char *)(MAX_AUTH_TYPE_SIZE); }
    {char buffer [ 1024 ]; buffer [ ( 1024 )-1 ] = (char)(MAX_AUTH_TYPE_SIZE); }
    {void * tlv1; tlv1 = (void *)(MAX_AUTH_TYPE_SIZE); }
    {int tlv2; tlv2 = (int)(MAX_AUTH_TYPE_SIZE); }
    {void * tlv3; tlv3 = (void *)(MAX_AUTH_TYPE_SIZE); }
    {void * tlv4; tlv4 = (void *)(MAX_AUTH_TYPE_SIZE); }
    {char * tlv7; tlv7 = (char *)(MAX_AUTH_TYPE_SIZE); }
    {unsigned int tlv6; tlv6 = (unsigned int)(MAX_AUTH_TYPE_SIZE); }
    {cgc_size_t tlv23; tlv23 = (cgc_size_t)(MAX_AUTH_TYPE_SIZE); }
    {char * tlv9; tlv9 = (char *)(MAX_AUTH_TYPE_SIZE); }
    {unsigned int tlv8; tlv8 = (unsigned int)(MAX_AUTH_TYPE_SIZE); }
    {unsigned int tlv28; tlv28 = (unsigned int)(MAX_AUTH_TYPE_SIZE); }
    {char * tlv27; tlv27 = (char *)(MAX_AUTH_TYPE_SIZE); }
    {char tlv26; tlv26 = (char)(MAX_AUTH_TYPE_SIZE); }
    {cgc_size_t tlv25; tlv25 = (cgc_size_t)(MAX_AUTH_TYPE_SIZE); }
    {char * tlv30; tlv30 = (char *)(MAX_AUTH_TYPE_SIZE); }
    {cgc_size_t tlv32; tlv32 = (cgc_size_t)(MAX_AUTH_TYPE_SIZE); }
    {char * tlv11; tlv11 = (char *)(MAX_AUTH_TYPE_SIZE); }
    {unsigned int tlv10; tlv10 = (unsigned int)(MAX_AUTH_TYPE_SIZE); }
    {void * tlv14; tlv14 = (void *)(MAX_AUTH_TYPE_SIZE); }
    {void * tlv13; tlv13 = (void *)(MAX_AUTH_TYPE_SIZE); }
    {cgc_size_t tlv12; tlv12 = (cgc_size_t)(MAX_AUTH_TYPE_SIZE); }
    {char * tlv34; tlv34 = (char *)(MAX_AUTH_TYPE_SIZE); }
    {void * tlv17; tlv17 = (void *)(MAX_AUTH_TYPE_SIZE); }
    {void * tlv16; tlv16 = (void *)(MAX_AUTH_TYPE_SIZE); }
    {cgc_size_t tlv15; tlv15 = (cgc_size_t)(MAX_AUTH_TYPE_SIZE); }
    {char * tlv37; tlv37 = (char *)(MAX_AUTH_TYPE_SIZE); }
    {char * tlv39; tlv39 = (char *)(MAX_AUTH_TYPE_SIZE); }
    {cgc_size_t tlv41; tlv41 = (cgc_size_t)(MAX_AUTH_TYPE_SIZE); }
    {char * tlv19; tlv19 = (char *)(MAX_AUTH_TYPE_SIZE); }
    {unsigned int tlv18; tlv18 = (unsigned int)(MAX_AUTH_TYPE_SIZE); }
    {void * tlv22; tlv22 = (void *)(MAX_AUTH_TYPE_SIZE); }
    {void * tlv21; tlv21 = (void *)(MAX_AUTH_TYPE_SIZE); }
    {cgc_size_t tlv20; tlv20 = (cgc_size_t)(MAX_AUTH_TYPE_SIZE); }
    {char * tlv43; tlv43 = (char *)(MAX_AUTH_TYPE_SIZE); }
    {void * tlv5; tlv5 = (void *)(MAX_AUTH_TYPE_SIZE); }
    {unsigned int tlv44; tlv44 = (unsigned int)(MAX_AUTH_TYPE_SIZE); }
    {unsigned int tlv45; tlv45 = (unsigned int)(MAX_AUTH_TYPE_SIZE); }
    {char * tlv51; tlv51 = (char *)(MAX_AUTH_TYPE_SIZE); }
    {cgc_size_t tlv53; tlv53 = (cgc_size_t)(MAX_AUTH_TYPE_SIZE); }
    {char * tlv47; tlv47 = (char *)(MAX_AUTH_TYPE_SIZE); }
    {unsigned int tlv46; tlv46 = (unsigned int)(MAX_AUTH_TYPE_SIZE); }
    {void * tlv50; tlv50 = (void *)(MAX_AUTH_TYPE_SIZE); }
    {void * tlv49; tlv49 = (void *)(MAX_AUTH_TYPE_SIZE); }
    {cgc_size_t tlv48; tlv48 = (cgc_size_t)(MAX_AUTH_TYPE_SIZE); }
}
void fix_ingred_service_3_21(){
fix_ingred_service_3_21_0();
}
void fix_ingred_service_3_22_0(){
Message message_ref;
    bzero(&message_ref,1*sizeof(Message));
Message * message = &message_ref;
char auth_str_ref;
    bzero(&auth_str_ref,1*sizeof(char));
char * auth_str = &auth_str_ref;
    {cgc_size_t bytes; bytes = (cgc_size_t)(message -> auth); }
    {cgc_size_t size; size = (cgc_size_t)(message -> auth); }
    {char * cmd_str; cmd_str = (char *)(message -> auth); }
    {char * auth_str; auth_str = (char *)(message -> auth); }
    {char * id_str; id_str = (char *)(message -> auth); }
    {char * cred_str; cred_str = (char *)(message -> auth); }
    {char * body_str; body_str = (char *)(message -> auth); }
    {char buffer [ 1024 ]; buffer [ ( 1024 )-1 ] = (char)(message -> auth); }
    {void * tlv1; tlv1 = (void *)(message -> auth); }
    {int tlv2; tlv2 = (int)(message -> auth); }
    {void * tlv3; tlv3 = (void *)(message -> auth); }
    {void * tlv4; tlv4 = (void *)(message -> auth); }
    {char * tlv7; tlv7 = (char *)(message -> auth); }
    {unsigned int tlv6; tlv6 = (unsigned int)(message -> auth); }
    {cgc_size_t tlv23; tlv23 = (cgc_size_t)(message -> auth); }
    {char * tlv9; tlv9 = (char *)(message -> auth); }
    {unsigned int tlv8; tlv8 = (unsigned int)(message -> auth); }
    {unsigned int tlv28; tlv28 = (unsigned int)(message -> auth); }
    {char * tlv27; tlv27 = (char *)(message -> auth); }
    {char tlv26; tlv26 = (char)(message -> auth); }
    {cgc_size_t tlv25; tlv25 = (cgc_size_t)(message -> auth); }
    {char * tlv30; tlv30 = (char *)(message -> auth); }
    {cgc_size_t tlv32; tlv32 = (cgc_size_t)(message -> auth); }
    {char * tlv11; tlv11 = (char *)(message -> auth); }
    {unsigned int tlv10; tlv10 = (unsigned int)(message -> auth); }
    {void * tlv14; tlv14 = (void *)(message -> auth); }
    {void * tlv13; tlv13 = (void *)(message -> auth); }
    {cgc_size_t tlv12; tlv12 = (cgc_size_t)(message -> auth); }
    {char * tlv34; tlv34 = (char *)(message -> auth); }
    {void * tlv17; tlv17 = (void *)(message -> auth); }
    {void * tlv16; tlv16 = (void *)(message -> auth); }
    {cgc_size_t tlv15; tlv15 = (cgc_size_t)(message -> auth); }
    {char * tlv37; tlv37 = (char *)(message -> auth); }
    {char * tlv39; tlv39 = (char *)(message -> auth); }
    {cgc_size_t tlv41; tlv41 = (cgc_size_t)(message -> auth); }
    {char * tlv19; tlv19 = (char *)(message -> auth); }
    {unsigned int tlv18; tlv18 = (unsigned int)(message -> auth); }
    {void * tlv22; tlv22 = (void *)(message -> auth); }
    {void * tlv21; tlv21 = (void *)(message -> auth); }
    {cgc_size_t tlv20; tlv20 = (cgc_size_t)(message -> auth); }
    {char * tlv43; tlv43 = (char *)(message -> auth); }
    {void * tlv5; tlv5 = (void *)(message -> auth); }
    {unsigned int tlv44; tlv44 = (unsigned int)(message -> auth); }
    {unsigned int tlv45; tlv45 = (unsigned int)(message -> auth); }
    {char * tlv51; tlv51 = (char *)(message -> auth); }
    {cgc_size_t tlv53; tlv53 = (cgc_size_t)(message -> auth); }
    {char * tlv47; tlv47 = (char *)(message -> auth); }
    {unsigned int tlv46; tlv46 = (unsigned int)(message -> auth); }
    {void * tlv50; tlv50 = (void *)(message -> auth); }
    {void * tlv49; tlv49 = (void *)(message -> auth); }
    {cgc_size_t tlv48; tlv48 = (cgc_size_t)(message -> auth); }
}
void fix_ingred_service_3_22_1(){
Message message_ref;
    bzero(&message_ref,1*sizeof(Message));
Message * message = &message_ref;
char auth_str_ref;
    bzero(&auth_str_ref,1*sizeof(char));
char * auth_str = &auth_str_ref;
    {cgc_size_t bytes; bytes = (cgc_size_t)(auth_str); }
    {cgc_size_t size; size = (cgc_size_t)(auth_str); }
    {char * cmd_str; cmd_str = (char *)(auth_str); }
    {char * id_str; id_str = (char *)(auth_str); }
    {char * cred_str; cred_str = (char *)(auth_str); }
    {char * body_str; body_str = (char *)(auth_str); }
    {char buffer [ 1024 ]; buffer [ ( 1024 )-1 ] = (char)(auth_str); }
    {void * tlv1; tlv1 = (void *)(auth_str); }
    {int tlv2; tlv2 = (int)(auth_str); }
    {void * tlv3; tlv3 = (void *)(auth_str); }
    {void * tlv4; tlv4 = (void *)(auth_str); }
    {char * tlv7; tlv7 = (char *)(auth_str); }
    {unsigned int tlv6; tlv6 = (unsigned int)(auth_str); }
    {cgc_size_t tlv23; tlv23 = (cgc_size_t)(auth_str); }
    {char * tlv9; tlv9 = (char *)(auth_str); }
    {unsigned int tlv8; tlv8 = (unsigned int)(auth_str); }
    {unsigned int tlv28; tlv28 = (unsigned int)(auth_str); }
    {char * tlv27; tlv27 = (char *)(auth_str); }
    {char tlv26; tlv26 = (char)(auth_str); }
    {cgc_size_t tlv25; tlv25 = (cgc_size_t)(auth_str); }
    {char * tlv30; tlv30 = (char *)(auth_str); }
    {cgc_size_t tlv32; tlv32 = (cgc_size_t)(auth_str); }
    {char * tlv11; tlv11 = (char *)(auth_str); }
    {unsigned int tlv10; tlv10 = (unsigned int)(auth_str); }
    {void * tlv14; tlv14 = (void *)(auth_str); }
    {void * tlv13; tlv13 = (void *)(auth_str); }
    {cgc_size_t tlv12; tlv12 = (cgc_size_t)(auth_str); }
    {char * tlv34; tlv34 = (char *)(auth_str); }
    {void * tlv17; tlv17 = (void *)(auth_str); }
    {void * tlv16; tlv16 = (void *)(auth_str); }
    {cgc_size_t tlv15; tlv15 = (cgc_size_t)(auth_str); }
    {char * tlv37; tlv37 = (char *)(auth_str); }
    {char * tlv39; tlv39 = (char *)(auth_str); }
    {cgc_size_t tlv41; tlv41 = (cgc_size_t)(auth_str); }
    {char * tlv19; tlv19 = (char *)(auth_str); }
    {unsigned int tlv18; tlv18 = (unsigned int)(auth_str); }
    {void * tlv22; tlv22 = (void *)(auth_str); }
    {void * tlv21; tlv21 = (void *)(auth_str); }
    {cgc_size_t tlv20; tlv20 = (cgc_size_t)(auth_str); }
    {char * tlv43; tlv43 = (char *)(auth_str); }
    {void * tlv5; tlv5 = (void *)(auth_str); }
    {unsigned int tlv44; tlv44 = (unsigned int)(auth_str); }
    {unsigned int tlv45; tlv45 = (unsigned int)(auth_str); }
    {char * tlv51; tlv51 = (char *)(auth_str); }
    {cgc_size_t tlv53; tlv53 = (cgc_size_t)(auth_str); }
    {char * tlv47; tlv47 = (char *)(auth_str); }
    {unsigned int tlv46; tlv46 = (unsigned int)(auth_str); }
    {void * tlv50; tlv50 = (void *)(auth_str); }
    {void * tlv49; tlv49 = (void *)(auth_str); }
    {cgc_size_t tlv48; tlv48 = (cgc_size_t)(auth_str); }
}
void fix_ingred_service_3_22(){
fix_ingred_service_3_22_0();
fix_ingred_service_3_22_1();
}
void fix_ingred_service_3_25_0(){
char id_str_ref;
    bzero(&id_str_ref,1*sizeof(char));
char * id_str = &id_str_ref;
    {cgc_size_t bytes; bytes = (cgc_size_t)(id_str); }
    {cgc_size_t size; size = (cgc_size_t)(id_str); }
    {char * cmd_str; cmd_str = (char *)(id_str); }
    {char * auth_str; auth_str = (char *)(id_str); }
    {char * cred_str; cred_str = (char *)(id_str); }
    {char * body_str; body_str = (char *)(id_str); }
    {char buffer [ 1024 ]; buffer [ ( 1024 )-1 ] = (char)(id_str); }
    {void * tlv1; tlv1 = (void *)(id_str); }
    {int tlv2; tlv2 = (int)(id_str); }
    {void * tlv3; tlv3 = (void *)(id_str); }
    {void * tlv4; tlv4 = (void *)(id_str); }
    {char * tlv7; tlv7 = (char *)(id_str); }
    {unsigned int tlv6; tlv6 = (unsigned int)(id_str); }
    {cgc_size_t tlv23; tlv23 = (cgc_size_t)(id_str); }
    {char * tlv9; tlv9 = (char *)(id_str); }
    {unsigned int tlv8; tlv8 = (unsigned int)(id_str); }
    {unsigned int tlv28; tlv28 = (unsigned int)(id_str); }
    {char * tlv27; tlv27 = (char *)(id_str); }
    {char tlv26; tlv26 = (char)(id_str); }
    {cgc_size_t tlv25; tlv25 = (cgc_size_t)(id_str); }
    {char * tlv30; tlv30 = (char *)(id_str); }
    {cgc_size_t tlv32; tlv32 = (cgc_size_t)(id_str); }
    {char * tlv11; tlv11 = (char *)(id_str); }
    {unsigned int tlv10; tlv10 = (unsigned int)(id_str); }
    {void * tlv14; tlv14 = (void *)(id_str); }
    {void * tlv13; tlv13 = (void *)(id_str); }
    {cgc_size_t tlv12; tlv12 = (cgc_size_t)(id_str); }
    {char * tlv34; tlv34 = (char *)(id_str); }
    {void * tlv17; tlv17 = (void *)(id_str); }
    {void * tlv16; tlv16 = (void *)(id_str); }
    {cgc_size_t tlv15; tlv15 = (cgc_size_t)(id_str); }
    {char * tlv37; tlv37 = (char *)(id_str); }
    {char * tlv39; tlv39 = (char *)(id_str); }
    {cgc_size_t tlv41; tlv41 = (cgc_size_t)(id_str); }
    {char * tlv19; tlv19 = (char *)(id_str); }
    {unsigned int tlv18; tlv18 = (unsigned int)(id_str); }
    {void * tlv22; tlv22 = (void *)(id_str); }
    {void * tlv21; tlv21 = (void *)(id_str); }
    {cgc_size_t tlv20; tlv20 = (cgc_size_t)(id_str); }
    {char * tlv43; tlv43 = (char *)(id_str); }
    {void * tlv5; tlv5 = (void *)(id_str); }
    {unsigned int tlv44; tlv44 = (unsigned int)(id_str); }
    {unsigned int tlv45; tlv45 = (unsigned int)(id_str); }
    {char * tlv51; tlv51 = (char *)(id_str); }
    {cgc_size_t tlv53; tlv53 = (cgc_size_t)(id_str); }
    {char * tlv47; tlv47 = (char *)(id_str); }
    {unsigned int tlv46; tlv46 = (unsigned int)(id_str); }
    {void * tlv50; tlv50 = (void *)(id_str); }
    {void * tlv49; tlv49 = (void *)(id_str); }
    {cgc_size_t tlv48; tlv48 = (cgc_size_t)(id_str); }
}
void fix_ingred_service_3_25(){
fix_ingred_service_3_25_0();
}
void fix_ingred_service_3_29_0(){
char tlv40_ref;
    bzero(&tlv40_ref,1*sizeof(char));
const char * tlv40 = &tlv40_ref;
    {cgc_size_t bytes; bytes = (cgc_size_t)(cgc_strlen ( tlv40 )); }
    {cgc_size_t size; size = (cgc_size_t)(cgc_strlen ( tlv40 )); }
    {char * cmd_str; cmd_str = (char *)(cgc_strlen ( tlv40 )); }
    {char * auth_str; auth_str = (char *)(cgc_strlen ( tlv40 )); }
    {char * id_str; id_str = (char *)(cgc_strlen ( tlv40 )); }
    {char * cred_str; cred_str = (char *)(cgc_strlen ( tlv40 )); }
    {char * body_str; body_str = (char *)(cgc_strlen ( tlv40 )); }
    {char buffer [ 1024 ]; buffer [ ( 1024 )-1 ] = (char)(cgc_strlen ( tlv40 )); }
    {void * tlv1; tlv1 = (void *)(cgc_strlen ( tlv40 )); }
    {int tlv2; tlv2 = (int)(cgc_strlen ( tlv40 )); }
    {void * tlv3; tlv3 = (void *)(cgc_strlen ( tlv40 )); }
    {void * tlv4; tlv4 = (void *)(cgc_strlen ( tlv40 )); }
    {char * tlv7; tlv7 = (char *)(cgc_strlen ( tlv40 )); }
    {unsigned int tlv6; tlv6 = (unsigned int)(cgc_strlen ( tlv40 )); }
    {cgc_size_t tlv23; tlv23 = (cgc_size_t)(cgc_strlen ( tlv40 )); }
    {char * tlv9; tlv9 = (char *)(cgc_strlen ( tlv40 )); }
    {unsigned int tlv8; tlv8 = (unsigned int)(cgc_strlen ( tlv40 )); }
    {unsigned int tlv28; tlv28 = (unsigned int)(cgc_strlen ( tlv40 )); }
    {char * tlv27; tlv27 = (char *)(cgc_strlen ( tlv40 )); }
    {char tlv26; tlv26 = (char)(cgc_strlen ( tlv40 )); }
    {cgc_size_t tlv25; tlv25 = (cgc_size_t)(cgc_strlen ( tlv40 )); }
    {char * tlv30; tlv30 = (char *)(cgc_strlen ( tlv40 )); }
    {cgc_size_t tlv32; tlv32 = (cgc_size_t)(cgc_strlen ( tlv40 )); }
    {char * tlv11; tlv11 = (char *)(cgc_strlen ( tlv40 )); }
    {unsigned int tlv10; tlv10 = (unsigned int)(cgc_strlen ( tlv40 )); }
    {void * tlv14; tlv14 = (void *)(cgc_strlen ( tlv40 )); }
    {void * tlv13; tlv13 = (void *)(cgc_strlen ( tlv40 )); }
    {cgc_size_t tlv12; tlv12 = (cgc_size_t)(cgc_strlen ( tlv40 )); }
    {char * tlv34; tlv34 = (char *)(cgc_strlen ( tlv40 )); }
    {void * tlv17; tlv17 = (void *)(cgc_strlen ( tlv40 )); }
    {void * tlv16; tlv16 = (void *)(cgc_strlen ( tlv40 )); }
    {cgc_size_t tlv15; tlv15 = (cgc_size_t)(cgc_strlen ( tlv40 )); }
    {char * tlv37; tlv37 = (char *)(cgc_strlen ( tlv40 )); }
    {char * tlv39; tlv39 = (char *)(cgc_strlen ( tlv40 )); }
    {cgc_size_t tlv41; tlv41 = (cgc_size_t)(cgc_strlen ( tlv40 )); }
    {char * tlv19; tlv19 = (char *)(cgc_strlen ( tlv40 )); }
    {unsigned int tlv18; tlv18 = (unsigned int)(cgc_strlen ( tlv40 )); }
    {void * tlv22; tlv22 = (void *)(cgc_strlen ( tlv40 )); }
    {void * tlv21; tlv21 = (void *)(cgc_strlen ( tlv40 )); }
    {cgc_size_t tlv20; tlv20 = (cgc_size_t)(cgc_strlen ( tlv40 )); }
    {char * tlv43; tlv43 = (char *)(cgc_strlen ( tlv40 )); }
    {void * tlv5; tlv5 = (void *)(cgc_strlen ( tlv40 )); }
    {unsigned int tlv44; tlv44 = (unsigned int)(cgc_strlen ( tlv40 )); }
    {unsigned int tlv45; tlv45 = (unsigned int)(cgc_strlen ( tlv40 )); }
    {char * tlv51; tlv51 = (char *)(cgc_strlen ( tlv40 )); }
    {cgc_size_t tlv53; tlv53 = (cgc_size_t)(cgc_strlen ( tlv40 )); }
    {char * tlv47; tlv47 = (char *)(cgc_strlen ( tlv40 )); }
    {unsigned int tlv46; tlv46 = (unsigned int)(cgc_strlen ( tlv40 )); }
    {void * tlv50; tlv50 = (void *)(cgc_strlen ( tlv40 )); }
    {void * tlv49; tlv49 = (void *)(cgc_strlen ( tlv40 )); }
    {cgc_size_t tlv48; tlv48 = (cgc_size_t)(cgc_strlen ( tlv40 )); }
}
void fix_ingred_service_3_29(){
fix_ingred_service_3_29_0();
}
void fix_ingred_service_3_32_0(){
Message message_ref;
    bzero(&message_ref,1*sizeof(Message));
Message * message = &message_ref;
    {cgc_size_t bytes; bytes = (cgc_size_t)(message -> credential); }
    {cgc_size_t size; size = (cgc_size_t)(message -> credential); }
    {char * cmd_str; cmd_str = (char *)(message -> credential); }
    {char * auth_str; auth_str = (char *)(message -> credential); }
    {char * id_str; id_str = (char *)(message -> credential); }
    {char * cred_str; cred_str = (char *)(message -> credential); }
    {char * body_str; body_str = (char *)(message -> credential); }
    {char buffer [ 1024 ]; buffer [ ( 1024 )-1 ] = (char)(message -> credential); }
    {void * tlv1; tlv1 = (void *)(message -> credential); }
    {int tlv2; tlv2 = (int)(message -> credential); }
    {void * tlv3; tlv3 = (void *)(message -> credential); }
    {void * tlv4; tlv4 = (void *)(message -> credential); }
    {char * tlv7; tlv7 = (char *)(message -> credential); }
    {unsigned int tlv6; tlv6 = (unsigned int)(message -> credential); }
    {cgc_size_t tlv23; tlv23 = (cgc_size_t)(message -> credential); }
    {char * tlv9; tlv9 = (char *)(message -> credential); }
    {unsigned int tlv8; tlv8 = (unsigned int)(message -> credential); }
    {unsigned int tlv28; tlv28 = (unsigned int)(message -> credential); }
    {char * tlv27; tlv27 = (char *)(message -> credential); }
    {char tlv26; tlv26 = (char)(message -> credential); }
    {cgc_size_t tlv25; tlv25 = (cgc_size_t)(message -> credential); }
    {char * tlv30; tlv30 = (char *)(message -> credential); }
    {cgc_size_t tlv32; tlv32 = (cgc_size_t)(message -> credential); }
    {char * tlv11; tlv11 = (char *)(message -> credential); }
    {unsigned int tlv10; tlv10 = (unsigned int)(message -> credential); }
    {void * tlv14; tlv14 = (void *)(message -> credential); }
    {void * tlv13; tlv13 = (void *)(message -> credential); }
    {cgc_size_t tlv12; tlv12 = (cgc_size_t)(message -> credential); }
    {char * tlv34; tlv34 = (char *)(message -> credential); }
    {void * tlv17; tlv17 = (void *)(message -> credential); }
    {void * tlv16; tlv16 = (void *)(message -> credential); }
    {cgc_size_t tlv15; tlv15 = (cgc_size_t)(message -> credential); }
    {char * tlv37; tlv37 = (char *)(message -> credential); }
    {char * tlv39; tlv39 = (char *)(message -> credential); }
    {cgc_size_t tlv41; tlv41 = (cgc_size_t)(message -> credential); }
    {char * tlv19; tlv19 = (char *)(message -> credential); }
    {unsigned int tlv18; tlv18 = (unsigned int)(message -> credential); }
    {void * tlv22; tlv22 = (void *)(message -> credential); }
    {void * tlv21; tlv21 = (void *)(message -> credential); }
    {cgc_size_t tlv20; tlv20 = (cgc_size_t)(message -> credential); }
    {char * tlv43; tlv43 = (char *)(message -> credential); }
    {void * tlv5; tlv5 = (void *)(message -> credential); }
    {unsigned int tlv44; tlv44 = (unsigned int)(message -> credential); }
    {unsigned int tlv45; tlv45 = (unsigned int)(message -> credential); }
    {char * tlv51; tlv51 = (char *)(message -> credential); }
    {cgc_size_t tlv53; tlv53 = (cgc_size_t)(message -> credential); }
    {char * tlv47; tlv47 = (char *)(message -> credential); }
    {unsigned int tlv46; tlv46 = (unsigned int)(message -> credential); }
    {void * tlv50; tlv50 = (void *)(message -> credential); }
    {void * tlv49; tlv49 = (void *)(message -> credential); }
    {cgc_size_t tlv48; tlv48 = (cgc_size_t)(message -> credential); }
}
void fix_ingred_service_3_32(){
fix_ingred_service_3_32_0();
}
void fix_ingred_service_3_33_0(){
Message message_ref;
    bzero(&message_ref,1*sizeof(Message));
Message * message = &message_ref;
char cred_str_ref;
    bzero(&cred_str_ref,1*sizeof(char));
char * cred_str = &cred_str_ref;
    {cgc_size_t bytes; bytes = (cgc_size_t)(message -> credential); }
    {cgc_size_t size; size = (cgc_size_t)(message -> credential); }
    {char * cmd_str; cmd_str = (char *)(message -> credential); }
    {char * auth_str; auth_str = (char *)(message -> credential); }
    {char * id_str; id_str = (char *)(message -> credential); }
    {char * cred_str; cred_str = (char *)(message -> credential); }
    {char * body_str; body_str = (char *)(message -> credential); }
    {char buffer [ 1024 ]; buffer [ ( 1024 )-1 ] = (char)(message -> credential); }
    {int tlv2; tlv2 = (int)(message -> credential); }
    {void * tlv3; tlv3 = (void *)(message -> credential); }
    {void * tlv4; tlv4 = (void *)(message -> credential); }
    {char * tlv7; tlv7 = (char *)(message -> credential); }
    {unsigned int tlv6; tlv6 = (unsigned int)(message -> credential); }
    {cgc_size_t tlv23; tlv23 = (cgc_size_t)(message -> credential); }
    {char * tlv9; tlv9 = (char *)(message -> credential); }
    {unsigned int tlv8; tlv8 = (unsigned int)(message -> credential); }
    {unsigned int tlv28; tlv28 = (unsigned int)(message -> credential); }
    {char * tlv27; tlv27 = (char *)(message -> credential); }
    {char tlv26; tlv26 = (char)(message -> credential); }
    {cgc_size_t tlv25; tlv25 = (cgc_size_t)(message -> credential); }
    {char * tlv30; tlv30 = (char *)(message -> credential); }
    {cgc_size_t tlv32; tlv32 = (cgc_size_t)(message -> credential); }
    {char * tlv11; tlv11 = (char *)(message -> credential); }
    {unsigned int tlv10; tlv10 = (unsigned int)(message -> credential); }
    {void * tlv14; tlv14 = (void *)(message -> credential); }
    {void * tlv13; tlv13 = (void *)(message -> credential); }
    {cgc_size_t tlv12; tlv12 = (cgc_size_t)(message -> credential); }
    {char * tlv34; tlv34 = (char *)(message -> credential); }
    {void * tlv17; tlv17 = (void *)(message -> credential); }
    {void * tlv16; tlv16 = (void *)(message -> credential); }
    {cgc_size_t tlv15; tlv15 = (cgc_size_t)(message -> credential); }
    {char * tlv37; tlv37 = (char *)(message -> credential); }
    {char * tlv39; tlv39 = (char *)(message -> credential); }
    {cgc_size_t tlv41; tlv41 = (cgc_size_t)(message -> credential); }
    {char * tlv19; tlv19 = (char *)(message -> credential); }
    {unsigned int tlv18; tlv18 = (unsigned int)(message -> credential); }
    {void * tlv22; tlv22 = (void *)(message -> credential); }
    {void * tlv21; tlv21 = (void *)(message -> credential); }
    {cgc_size_t tlv20; tlv20 = (cgc_size_t)(message -> credential); }
    {char * tlv43; tlv43 = (char *)(message -> credential); }
    {void * tlv5; tlv5 = (void *)(message -> credential); }
    {unsigned int tlv44; tlv44 = (unsigned int)(message -> credential); }
    {unsigned int tlv45; tlv45 = (unsigned int)(message -> credential); }
    {char * tlv51; tlv51 = (char *)(message -> credential); }
    {cgc_size_t tlv53; tlv53 = (cgc_size_t)(message -> credential); }
    {char * tlv47; tlv47 = (char *)(message -> credential); }
    {unsigned int tlv46; tlv46 = (unsigned int)(message -> credential); }
    {void * tlv50; tlv50 = (void *)(message -> credential); }
    {void * tlv49; tlv49 = (void *)(message -> credential); }
    {cgc_size_t tlv48; tlv48 = (cgc_size_t)(message -> credential); }
}
void fix_ingred_service_3_33_1(){
Message message_ref;
    bzero(&message_ref,1*sizeof(Message));
Message * message = &message_ref;
char cred_str_ref;
    bzero(&cred_str_ref,1*sizeof(char));
char * cred_str = &cred_str_ref;
    {cgc_size_t bytes; bytes = (cgc_size_t)(cred_str); }
    {cgc_size_t size; size = (cgc_size_t)(cred_str); }
    {char * cmd_str; cmd_str = (char *)(cred_str); }
    {char * auth_str; auth_str = (char *)(cred_str); }
    {char * id_str; id_str = (char *)(cred_str); }
    {char * body_str; body_str = (char *)(cred_str); }
    {char buffer [ 1024 ]; buffer [ ( 1024 )-1 ] = (char)(cred_str); }
    {void * tlv1; tlv1 = (void *)(cred_str); }
    {int tlv2; tlv2 = (int)(cred_str); }
    {void * tlv3; tlv3 = (void *)(cred_str); }
    {void * tlv4; tlv4 = (void *)(cred_str); }
    {char * tlv7; tlv7 = (char *)(cred_str); }
    {unsigned int tlv6; tlv6 = (unsigned int)(cred_str); }
    {cgc_size_t tlv23; tlv23 = (cgc_size_t)(cred_str); }
    {char * tlv9; tlv9 = (char *)(cred_str); }
    {unsigned int tlv8; tlv8 = (unsigned int)(cred_str); }
    {unsigned int tlv28; tlv28 = (unsigned int)(cred_str); }
    {char * tlv27; tlv27 = (char *)(cred_str); }
    {char tlv26; tlv26 = (char)(cred_str); }
    {cgc_size_t tlv25; tlv25 = (cgc_size_t)(cred_str); }
    {char * tlv30; tlv30 = (char *)(cred_str); }
    {cgc_size_t tlv32; tlv32 = (cgc_size_t)(cred_str); }
    {char * tlv11; tlv11 = (char *)(cred_str); }
    {unsigned int tlv10; tlv10 = (unsigned int)(cred_str); }
    {void * tlv14; tlv14 = (void *)(cred_str); }
    {void * tlv13; tlv13 = (void *)(cred_str); }
    {cgc_size_t tlv12; tlv12 = (cgc_size_t)(cred_str); }
    {char * tlv34; tlv34 = (char *)(cred_str); }
    {void * tlv17; tlv17 = (void *)(cred_str); }
    {void * tlv16; tlv16 = (void *)(cred_str); }
    {cgc_size_t tlv15; tlv15 = (cgc_size_t)(cred_str); }
    {char * tlv37; tlv37 = (char *)(cred_str); }
    {char * tlv39; tlv39 = (char *)(cred_str); }
    {cgc_size_t tlv41; tlv41 = (cgc_size_t)(cred_str); }
    {char * tlv19; tlv19 = (char *)(cred_str); }
    {unsigned int tlv18; tlv18 = (unsigned int)(cred_str); }
    {void * tlv22; tlv22 = (void *)(cred_str); }
    {void * tlv21; tlv21 = (void *)(cred_str); }
    {cgc_size_t tlv20; tlv20 = (cgc_size_t)(cred_str); }
    {char * tlv43; tlv43 = (char *)(cred_str); }
    {void * tlv5; tlv5 = (void *)(cred_str); }
    {unsigned int tlv44; tlv44 = (unsigned int)(cred_str); }
    {unsigned int tlv45; tlv45 = (unsigned int)(cred_str); }
    {char * tlv51; tlv51 = (char *)(cred_str); }
    {cgc_size_t tlv53; tlv53 = (cgc_size_t)(cred_str); }
    {char * tlv47; tlv47 = (char *)(cred_str); }
    {unsigned int tlv46; tlv46 = (unsigned int)(cred_str); }
    {void * tlv50; tlv50 = (void *)(cred_str); }
    {void * tlv49; tlv49 = (void *)(cred_str); }
    {cgc_size_t tlv48; tlv48 = (cgc_size_t)(cred_str); }
}
void fix_ingred_service_3_33(){
fix_ingred_service_3_33_0();
fix_ingred_service_3_33_1();
}
void fix_ingred_service_3_36_0(){
char tlv52_ref;
    bzero(&tlv52_ref,1*sizeof(char));
const char * tlv52 = &tlv52_ref;
    {cgc_size_t bytes; bytes = (cgc_size_t)(cgc_strlen ( tlv52 )); }
    {cgc_size_t size; size = (cgc_size_t)(cgc_strlen ( tlv52 )); }
    {char * cmd_str; cmd_str = (char *)(cgc_strlen ( tlv52 )); }
    {char * auth_str; auth_str = (char *)(cgc_strlen ( tlv52 )); }
    {char * id_str; id_str = (char *)(cgc_strlen ( tlv52 )); }
    {char * cred_str; cred_str = (char *)(cgc_strlen ( tlv52 )); }
    {char * body_str; body_str = (char *)(cgc_strlen ( tlv52 )); }
    {char buffer [ 1024 ]; buffer [ ( 1024 )-1 ] = (char)(cgc_strlen ( tlv52 )); }
    {void * tlv1; tlv1 = (void *)(cgc_strlen ( tlv52 )); }
    {int tlv2; tlv2 = (int)(cgc_strlen ( tlv52 )); }
    {void * tlv3; tlv3 = (void *)(cgc_strlen ( tlv52 )); }
    {void * tlv4; tlv4 = (void *)(cgc_strlen ( tlv52 )); }
    {char * tlv7; tlv7 = (char *)(cgc_strlen ( tlv52 )); }
    {unsigned int tlv6; tlv6 = (unsigned int)(cgc_strlen ( tlv52 )); }
    {cgc_size_t tlv23; tlv23 = (cgc_size_t)(cgc_strlen ( tlv52 )); }
    {char * tlv9; tlv9 = (char *)(cgc_strlen ( tlv52 )); }
    {unsigned int tlv8; tlv8 = (unsigned int)(cgc_strlen ( tlv52 )); }
    {unsigned int tlv28; tlv28 = (unsigned int)(cgc_strlen ( tlv52 )); }
    {char * tlv27; tlv27 = (char *)(cgc_strlen ( tlv52 )); }
    {char tlv26; tlv26 = (char)(cgc_strlen ( tlv52 )); }
    {cgc_size_t tlv25; tlv25 = (cgc_size_t)(cgc_strlen ( tlv52 )); }
    {char * tlv30; tlv30 = (char *)(cgc_strlen ( tlv52 )); }
    {cgc_size_t tlv32; tlv32 = (cgc_size_t)(cgc_strlen ( tlv52 )); }
    {char * tlv11; tlv11 = (char *)(cgc_strlen ( tlv52 )); }
    {unsigned int tlv10; tlv10 = (unsigned int)(cgc_strlen ( tlv52 )); }
    {void * tlv14; tlv14 = (void *)(cgc_strlen ( tlv52 )); }
    {void * tlv13; tlv13 = (void *)(cgc_strlen ( tlv52 )); }
    {cgc_size_t tlv12; tlv12 = (cgc_size_t)(cgc_strlen ( tlv52 )); }
    {char * tlv34; tlv34 = (char *)(cgc_strlen ( tlv52 )); }
    {void * tlv17; tlv17 = (void *)(cgc_strlen ( tlv52 )); }
    {void * tlv16; tlv16 = (void *)(cgc_strlen ( tlv52 )); }
    {cgc_size_t tlv15; tlv15 = (cgc_size_t)(cgc_strlen ( tlv52 )); }
    {char * tlv37; tlv37 = (char *)(cgc_strlen ( tlv52 )); }
    {char * tlv39; tlv39 = (char *)(cgc_strlen ( tlv52 )); }
    {cgc_size_t tlv41; tlv41 = (cgc_size_t)(cgc_strlen ( tlv52 )); }
    {char * tlv19; tlv19 = (char *)(cgc_strlen ( tlv52 )); }
    {unsigned int tlv18; tlv18 = (unsigned int)(cgc_strlen ( tlv52 )); }
    {void * tlv22; tlv22 = (void *)(cgc_strlen ( tlv52 )); }
    {void * tlv21; tlv21 = (void *)(cgc_strlen ( tlv52 )); }
    {cgc_size_t tlv20; tlv20 = (cgc_size_t)(cgc_strlen ( tlv52 )); }
    {char * tlv43; tlv43 = (char *)(cgc_strlen ( tlv52 )); }
    {void * tlv5; tlv5 = (void *)(cgc_strlen ( tlv52 )); }
    {unsigned int tlv44; tlv44 = (unsigned int)(cgc_strlen ( tlv52 )); }
    {unsigned int tlv45; tlv45 = (unsigned int)(cgc_strlen ( tlv52 )); }
    {char * tlv51; tlv51 = (char *)(cgc_strlen ( tlv52 )); }
    {cgc_size_t tlv53; tlv53 = (cgc_size_t)(cgc_strlen ( tlv52 )); }
    {char * tlv47; tlv47 = (char *)(cgc_strlen ( tlv52 )); }
    {unsigned int tlv46; tlv46 = (unsigned int)(cgc_strlen ( tlv52 )); }
    {void * tlv50; tlv50 = (void *)(cgc_strlen ( tlv52 )); }
    {void * tlv49; tlv49 = (void *)(cgc_strlen ( tlv52 )); }
    {cgc_size_t tlv48; tlv48 = (cgc_size_t)(cgc_strlen ( tlv52 )); }
}
void fix_ingred_service_3_36(){
fix_ingred_service_3_36_0();
}
void fix_ingred_service_3_39_0(){
Message message_ref;
    bzero(&message_ref,1*sizeof(Message));
Message * message = &message_ref;
    {cgc_size_t bytes; bytes = (cgc_size_t)(message -> body); }
    {cgc_size_t size; size = (cgc_size_t)(message -> body); }
    {char * cmd_str; cmd_str = (char *)(message -> body); }
    {char * auth_str; auth_str = (char *)(message -> body); }
    {char * id_str; id_str = (char *)(message -> body); }
    {char * cred_str; cred_str = (char *)(message -> body); }
    {char * body_str; body_str = (char *)(message -> body); }
    {char buffer [ 1024 ]; buffer [ ( 1024 )-1 ] = (char)(message -> body); }
    {void * tlv1; tlv1 = (void *)(message -> body); }
    {int tlv2; tlv2 = (int)(message -> body); }
    {void * tlv3; tlv3 = (void *)(message -> body); }
    {void * tlv4; tlv4 = (void *)(message -> body); }
    {char * tlv7; tlv7 = (char *)(message -> body); }
    {unsigned int tlv6; tlv6 = (unsigned int)(message -> body); }
    {cgc_size_t tlv23; tlv23 = (cgc_size_t)(message -> body); }
    {char * tlv9; tlv9 = (char *)(message -> body); }
    {unsigned int tlv8; tlv8 = (unsigned int)(message -> body); }
    {unsigned int tlv28; tlv28 = (unsigned int)(message -> body); }
    {char * tlv27; tlv27 = (char *)(message -> body); }
    {char tlv26; tlv26 = (char)(message -> body); }
    {cgc_size_t tlv25; tlv25 = (cgc_size_t)(message -> body); }
    {char * tlv30; tlv30 = (char *)(message -> body); }
    {cgc_size_t tlv32; tlv32 = (cgc_size_t)(message -> body); }
    {char * tlv11; tlv11 = (char *)(message -> body); }
    {unsigned int tlv10; tlv10 = (unsigned int)(message -> body); }
    {void * tlv14; tlv14 = (void *)(message -> body); }
    {void * tlv13; tlv13 = (void *)(message -> body); }
    {cgc_size_t tlv12; tlv12 = (cgc_size_t)(message -> body); }
    {char * tlv34; tlv34 = (char *)(message -> body); }
    {void * tlv17; tlv17 = (void *)(message -> body); }
    {void * tlv16; tlv16 = (void *)(message -> body); }
    {cgc_size_t tlv15; tlv15 = (cgc_size_t)(message -> body); }
    {char * tlv37; tlv37 = (char *)(message -> body); }
    {char * tlv39; tlv39 = (char *)(message -> body); }
    {cgc_size_t tlv41; tlv41 = (cgc_size_t)(message -> body); }
    {char * tlv19; tlv19 = (char *)(message -> body); }
    {unsigned int tlv18; tlv18 = (unsigned int)(message -> body); }
    {void * tlv22; tlv22 = (void *)(message -> body); }
    {void * tlv21; tlv21 = (void *)(message -> body); }
    {cgc_size_t tlv20; tlv20 = (cgc_size_t)(message -> body); }
    {char * tlv43; tlv43 = (char *)(message -> body); }
    {void * tlv5; tlv5 = (void *)(message -> body); }
    {unsigned int tlv44; tlv44 = (unsigned int)(message -> body); }
    {unsigned int tlv45; tlv45 = (unsigned int)(message -> body); }
    {char * tlv51; tlv51 = (char *)(message -> body); }
    {cgc_size_t tlv53; tlv53 = (cgc_size_t)(message -> body); }
    {char * tlv47; tlv47 = (char *)(message -> body); }
    {unsigned int tlv46; tlv46 = (unsigned int)(message -> body); }
    {void * tlv50; tlv50 = (void *)(message -> body); }
    {void * tlv49; tlv49 = (void *)(message -> body); }
    {cgc_size_t tlv48; tlv48 = (cgc_size_t)(message -> body); }
}
void fix_ingred_service_3_39(){
fix_ingred_service_3_39_0();
}
void fix_ingred_service_3_40_0(){
Message message_ref;
    bzero(&message_ref,1*sizeof(Message));
Message * message = &message_ref;
char body_str_ref;
    bzero(&body_str_ref,1*sizeof(char));
char * body_str = &body_str_ref;
    {cgc_size_t bytes; bytes = (cgc_size_t)(message -> body); }
    {cgc_size_t size; size = (cgc_size_t)(message -> body); }
    {char * cmd_str; cmd_str = (char *)(message -> body); }
    {char * auth_str; auth_str = (char *)(message -> body); }
    {char * id_str; id_str = (char *)(message -> body); }
    {char * cred_str; cred_str = (char *)(message -> body); }
    {char * body_str; body_str = (char *)(message -> body); }
    {char buffer [ 1024 ]; buffer [ ( 1024 )-1 ] = (char)(message -> body); }
    {int tlv2; tlv2 = (int)(message -> body); }
    {void * tlv3; tlv3 = (void *)(message -> body); }
    {void * tlv4; tlv4 = (void *)(message -> body); }
    {char * tlv7; tlv7 = (char *)(message -> body); }
    {unsigned int tlv6; tlv6 = (unsigned int)(message -> body); }
    {cgc_size_t tlv23; tlv23 = (cgc_size_t)(message -> body); }
    {char * tlv9; tlv9 = (char *)(message -> body); }
    {unsigned int tlv8; tlv8 = (unsigned int)(message -> body); }
    {unsigned int tlv28; tlv28 = (unsigned int)(message -> body); }
    {char * tlv27; tlv27 = (char *)(message -> body); }
    {char tlv26; tlv26 = (char)(message -> body); }
    {cgc_size_t tlv25; tlv25 = (cgc_size_t)(message -> body); }
    {char * tlv30; tlv30 = (char *)(message -> body); }
    {cgc_size_t tlv32; tlv32 = (cgc_size_t)(message -> body); }
    {char * tlv11; tlv11 = (char *)(message -> body); }
    {unsigned int tlv10; tlv10 = (unsigned int)(message -> body); }
    {void * tlv14; tlv14 = (void *)(message -> body); }
    {void * tlv13; tlv13 = (void *)(message -> body); }
    {cgc_size_t tlv12; tlv12 = (cgc_size_t)(message -> body); }
    {char * tlv34; tlv34 = (char *)(message -> body); }
    {void * tlv17; tlv17 = (void *)(message -> body); }
    {void * tlv16; tlv16 = (void *)(message -> body); }
    {cgc_size_t tlv15; tlv15 = (cgc_size_t)(message -> body); }
    {char * tlv37; tlv37 = (char *)(message -> body); }
    {char * tlv39; tlv39 = (char *)(message -> body); }
    {cgc_size_t tlv41; tlv41 = (cgc_size_t)(message -> body); }
    {char * tlv19; tlv19 = (char *)(message -> body); }
    {unsigned int tlv18; tlv18 = (unsigned int)(message -> body); }
    {void * tlv22; tlv22 = (void *)(message -> body); }
    {void * tlv21; tlv21 = (void *)(message -> body); }
    {cgc_size_t tlv20; tlv20 = (cgc_size_t)(message -> body); }
    {char * tlv43; tlv43 = (char *)(message -> body); }
    {void * tlv5; tlv5 = (void *)(message -> body); }
    {unsigned int tlv44; tlv44 = (unsigned int)(message -> body); }
    {unsigned int tlv45; tlv45 = (unsigned int)(message -> body); }
    {char * tlv51; tlv51 = (char *)(message -> body); }
    {cgc_size_t tlv53; tlv53 = (cgc_size_t)(message -> body); }
    {char * tlv47; tlv47 = (char *)(message -> body); }
    {unsigned int tlv46; tlv46 = (unsigned int)(message -> body); }
    {void * tlv50; tlv50 = (void *)(message -> body); }
    {void * tlv49; tlv49 = (void *)(message -> body); }
    {cgc_size_t tlv48; tlv48 = (cgc_size_t)(message -> body); }
}
void fix_ingred_service_3_40_1(){
Message message_ref;
    bzero(&message_ref,1*sizeof(Message));
Message * message = &message_ref;
char body_str_ref;
    bzero(&body_str_ref,1*sizeof(char));
char * body_str = &body_str_ref;
    {cgc_size_t bytes; bytes = (cgc_size_t)(body_str); }
    {cgc_size_t size; size = (cgc_size_t)(body_str); }
    {char * cmd_str; cmd_str = (char *)(body_str); }
    {char * auth_str; auth_str = (char *)(body_str); }
    {char * id_str; id_str = (char *)(body_str); }
    {char * cred_str; cred_str = (char *)(body_str); }
    {char buffer [ 1024 ]; buffer [ ( 1024 )-1 ] = (char)(body_str); }
    {void * tlv1; tlv1 = (void *)(body_str); }
    {int tlv2; tlv2 = (int)(body_str); }
    {void * tlv3; tlv3 = (void *)(body_str); }
    {void * tlv4; tlv4 = (void *)(body_str); }
    {char * tlv7; tlv7 = (char *)(body_str); }
    {unsigned int tlv6; tlv6 = (unsigned int)(body_str); }
    {cgc_size_t tlv23; tlv23 = (cgc_size_t)(body_str); }
    {char * tlv9; tlv9 = (char *)(body_str); }
    {unsigned int tlv8; tlv8 = (unsigned int)(body_str); }
    {unsigned int tlv28; tlv28 = (unsigned int)(body_str); }
    {char * tlv27; tlv27 = (char *)(body_str); }
    {char tlv26; tlv26 = (char)(body_str); }
    {cgc_size_t tlv25; tlv25 = (cgc_size_t)(body_str); }
    {char * tlv30; tlv30 = (char *)(body_str); }
    {cgc_size_t tlv32; tlv32 = (cgc_size_t)(body_str); }
    {char * tlv11; tlv11 = (char *)(body_str); }
    {unsigned int tlv10; tlv10 = (unsigned int)(body_str); }
    {void * tlv14; tlv14 = (void *)(body_str); }
    {void * tlv13; tlv13 = (void *)(body_str); }
    {cgc_size_t tlv12; tlv12 = (cgc_size_t)(body_str); }
    {char * tlv34; tlv34 = (char *)(body_str); }
    {void * tlv17; tlv17 = (void *)(body_str); }
    {void * tlv16; tlv16 = (void *)(body_str); }
    {cgc_size_t tlv15; tlv15 = (cgc_size_t)(body_str); }
    {char * tlv37; tlv37 = (char *)(body_str); }
    {char * tlv39; tlv39 = (char *)(body_str); }
    {cgc_size_t tlv41; tlv41 = (cgc_size_t)(body_str); }
    {char * tlv19; tlv19 = (char *)(body_str); }
    {unsigned int tlv18; tlv18 = (unsigned int)(body_str); }
    {void * tlv22; tlv22 = (void *)(body_str); }
    {void * tlv21; tlv21 = (void *)(body_str); }
    {cgc_size_t tlv20; tlv20 = (cgc_size_t)(body_str); }
    {char * tlv43; tlv43 = (char *)(body_str); }
    {void * tlv5; tlv5 = (void *)(body_str); }
    {unsigned int tlv44; tlv44 = (unsigned int)(body_str); }
    {unsigned int tlv45; tlv45 = (unsigned int)(body_str); }
    {char * tlv51; tlv51 = (char *)(body_str); }
    {cgc_size_t tlv53; tlv53 = (cgc_size_t)(body_str); }
    {char * tlv47; tlv47 = (char *)(body_str); }
    {unsigned int tlv46; tlv46 = (unsigned int)(body_str); }
    {void * tlv50; tlv50 = (void *)(body_str); }
    {void * tlv49; tlv49 = (void *)(body_str); }
    {cgc_size_t tlv48; tlv48 = (cgc_size_t)(body_str); }
}
void fix_ingred_service_3_40(){
fix_ingred_service_3_40_0();
fix_ingred_service_3_40_1();
}
void fix_ingred_service_3(){
fix_ingred_service_3_1();
fix_ingred_service_3_2();
fix_ingred_service_3_4();
fix_ingred_service_3_6();
fix_ingred_service_3_7();
fix_ingred_service_3_9();
fix_ingred_service_3_12();
fix_ingred_service_3_13();
fix_ingred_service_3_14();
fix_ingred_service_3_16();
fix_ingred_service_3_17();
fix_ingred_service_3_18();
fix_ingred_service_3_20();
fix_ingred_service_3_21();
fix_ingred_service_3_22();
fix_ingred_service_3_25();
fix_ingred_service_3_29();
fix_ingred_service_3_32();
fix_ingred_service_3_33();
fix_ingred_service_3_36();
fix_ingred_service_3_39();
fix_ingred_service_3_40();
}
void fix_ingred_service_4_1_0(){
char command_ref;
    bzero(&command_ref,1*sizeof(char));
char * command = &command_ref;
    {int tlv1; tlv1 = (int)(command); }
    {int tlv2; tlv2 = (int)(command); }
    {char * tlv12; tlv12 = (char *)(command); }
    {cgc_size_t tlv13; tlv13 = (cgc_size_t)(command); }
    {int tlv3; tlv3 = (int)(command); }
    {int tlv4; tlv4 = (int)(command); }
    {int tlv5; tlv5 = (int)(command); }
    {char * tlv16; tlv16 = (char *)(command); }
    {char * tlv18; tlv18 = (char *)(command); }
    {char * tlv17; tlv17 = (char *)(command); }
    {char * tlv20; tlv20 = (char *)(command); }
    {cgc_size_t tlv22; tlv22 = (cgc_size_t)(command); }
    {int tlv6; tlv6 = (int)(command); }
    {int tlv7; tlv7 = (int)(command); }
    {int tlv8; tlv8 = (int)(command); }
    {int tlv9; tlv9 = (int)(command); }
    {char * tlv25; tlv25 = (char *)(command); }
    {char * tlv27; tlv27 = (char *)(command); }
    {char * tlv26; tlv26 = (char *)(command); }
    {cgc_size_t tlv30; tlv30 = (cgc_size_t)(command); }
    {cgc_size_t tlv33; tlv33 = (cgc_size_t)(command); }
    {char * user; user = (char *)(command); }
    {char * pass; pass = (char *)(command); }
    {int tlv10; tlv10 = (int)(command); }
    {char * tlv37; tlv37 = (char *)(command); }
    {cgc_size_t tlv38; tlv38 = (cgc_size_t)(command); }
    {int tlv11; tlv11 = (int)(command); }
    {char * tlv42; tlv42 = (char *)(command); }
    {cgc_size_t tlv43; tlv43 = (cgc_size_t)(command); }
}
void fix_ingred_service_4_1(){
fix_ingred_service_4_1_0();
}
void fix_ingred_service_4_3_0(){
char tlv46_ref;
    bzero(&tlv46_ref,1*sizeof(char));
const char * tlv46 = &tlv46_ref;
    {int tlv1; tlv1 = (int)(cgc_strlen ( tlv46 )); }
    {int tlv2; tlv2 = (int)(cgc_strlen ( tlv46 )); }
    {char * tlv12; tlv12 = (char *)(cgc_strlen ( tlv46 )); }
    {cgc_size_t tlv13; tlv13 = (cgc_size_t)(cgc_strlen ( tlv46 )); }
    {int tlv3; tlv3 = (int)(cgc_strlen ( tlv46 )); }
    {int tlv4; tlv4 = (int)(cgc_strlen ( tlv46 )); }
    {int tlv5; tlv5 = (int)(cgc_strlen ( tlv46 )); }
    {char * tlv16; tlv16 = (char *)(cgc_strlen ( tlv46 )); }
    {char * tlv18; tlv18 = (char *)(cgc_strlen ( tlv46 )); }
    {char * tlv17; tlv17 = (char *)(cgc_strlen ( tlv46 )); }
    {char * tlv20; tlv20 = (char *)(cgc_strlen ( tlv46 )); }
    {cgc_size_t tlv22; tlv22 = (cgc_size_t)(cgc_strlen ( tlv46 )); }
    {int tlv6; tlv6 = (int)(cgc_strlen ( tlv46 )); }
    {int tlv7; tlv7 = (int)(cgc_strlen ( tlv46 )); }
    {int tlv8; tlv8 = (int)(cgc_strlen ( tlv46 )); }
    {int tlv9; tlv9 = (int)(cgc_strlen ( tlv46 )); }
    {char * tlv25; tlv25 = (char *)(cgc_strlen ( tlv46 )); }
    {char * tlv27; tlv27 = (char *)(cgc_strlen ( tlv46 )); }
    {char * tlv26; tlv26 = (char *)(cgc_strlen ( tlv46 )); }
    {cgc_size_t tlv30; tlv30 = (cgc_size_t)(cgc_strlen ( tlv46 )); }
    {cgc_size_t tlv33; tlv33 = (cgc_size_t)(cgc_strlen ( tlv46 )); }
    {char * user; user = (char *)(cgc_strlen ( tlv46 )); }
    {char * pass; pass = (char *)(cgc_strlen ( tlv46 )); }
    {int tlv10; tlv10 = (int)(cgc_strlen ( tlv46 )); }
    {char * tlv37; tlv37 = (char *)(cgc_strlen ( tlv46 )); }
    {cgc_size_t tlv38; tlv38 = (cgc_size_t)(cgc_strlen ( tlv46 )); }
    {int tlv11; tlv11 = (int)(cgc_strlen ( tlv46 )); }
    {char * tlv42; tlv42 = (char *)(cgc_strlen ( tlv46 )); }
    {cgc_size_t tlv43; tlv43 = (cgc_size_t)(cgc_strlen ( tlv46 )); }
}
void fix_ingred_service_4_3(){
fix_ingred_service_4_3_0();
}
void fix_ingred_service_4_5_0(){
char credential_ref;
    bzero(&credential_ref,1*sizeof(char));
char * credential = &credential_ref;
    {int tlv1; tlv1 = (int)(credential); }
    {int tlv2; tlv2 = (int)(credential); }
    {char * tlv12; tlv12 = (char *)(credential); }
    {cgc_size_t tlv13; tlv13 = (cgc_size_t)(credential); }
    {int tlv3; tlv3 = (int)(credential); }
    {int tlv4; tlv4 = (int)(credential); }
    {int tlv5; tlv5 = (int)(credential); }
    {char * tlv16; tlv16 = (char *)(credential); }
    {char * tlv18; tlv18 = (char *)(credential); }
    {char * tlv17; tlv17 = (char *)(credential); }
    {char * tlv20; tlv20 = (char *)(credential); }
    {cgc_size_t tlv22; tlv22 = (cgc_size_t)(credential); }
    {int tlv6; tlv6 = (int)(credential); }
    {int tlv7; tlv7 = (int)(credential); }
    {int tlv8; tlv8 = (int)(credential); }
    {int tlv9; tlv9 = (int)(credential); }
    {char * tlv25; tlv25 = (char *)(credential); }
    {char * tlv27; tlv27 = (char *)(credential); }
    {char * tlv26; tlv26 = (char *)(credential); }
    {cgc_size_t tlv30; tlv30 = (cgc_size_t)(credential); }
    {cgc_size_t tlv33; tlv33 = (cgc_size_t)(credential); }
    {char * user; user = (char *)(credential); }
    {char * pass; pass = (char *)(credential); }
    {int tlv10; tlv10 = (int)(credential); }
    {char * tlv37; tlv37 = (char *)(credential); }
    {cgc_size_t tlv38; tlv38 = (cgc_size_t)(credential); }
    {int tlv11; tlv11 = (int)(credential); }
    {char * tlv42; tlv42 = (char *)(credential); }
    {cgc_size_t tlv43; tlv43 = (cgc_size_t)(credential); }
}
void fix_ingred_service_4_5(){
fix_ingred_service_4_5_0();
}
void fix_ingred_service_4_6_1(){
Certificate cert_ref;
    bzero(&cert_ref,1*sizeof(Certificate));
Certificate * cert = &cert_ref;
    {int tlv1; tlv1 = (int)(cert -> use); }
    {int tlv2; tlv2 = (int)(cert -> use); }
    {char * tlv12; tlv12 = (char *)(cert -> use); }
    {cgc_size_t tlv13; tlv13 = (cgc_size_t)(cert -> use); }
    {int tlv3; tlv3 = (int)(cert -> use); }
    {int tlv4; tlv4 = (int)(cert -> use); }
    {int tlv5; tlv5 = (int)(cert -> use); }
    {char * tlv16; tlv16 = (char *)(cert -> use); }
    {char * tlv18; tlv18 = (char *)(cert -> use); }
    {char * tlv17; tlv17 = (char *)(cert -> use); }
    {char * tlv20; tlv20 = (char *)(cert -> use); }
    {cgc_size_t tlv22; tlv22 = (cgc_size_t)(cert -> use); }
    {int tlv6; tlv6 = (int)(cert -> use); }
    {int tlv7; tlv7 = (int)(cert -> use); }
    {int tlv8; tlv8 = (int)(cert -> use); }
    {int tlv9; tlv9 = (int)(cert -> use); }
    {char * tlv25; tlv25 = (char *)(cert -> use); }
    {char * tlv27; tlv27 = (char *)(cert -> use); }
    {char * tlv26; tlv26 = (char *)(cert -> use); }
    {cgc_size_t tlv30; tlv30 = (cgc_size_t)(cert -> use); }
    {cgc_size_t tlv33; tlv33 = (cgc_size_t)(cert -> use); }
    {char * user; user = (char *)(cert -> use); }
    {char * pass; pass = (char *)(cert -> use); }
    {int tlv10; tlv10 = (int)(cert -> use); }
    {char * tlv37; tlv37 = (char *)(cert -> use); }
    {cgc_size_t tlv38; tlv38 = (cgc_size_t)(cert -> use); }
    {int tlv11; tlv11 = (int)(cert -> use); }
    {char * tlv42; tlv42 = (char *)(cert -> use); }
    {cgc_size_t tlv43; tlv43 = (cgc_size_t)(cert -> use); }
}
void fix_ingred_service_4_6(){
fix_ingred_service_4_6_1();
}
void fix_ingred_service_4_12_0(){
char tlv47_ref;
    bzero(&tlv47_ref,1*sizeof(char));
const char * tlv47 = &tlv47_ref;
    {int tlv1; tlv1 = (int)(cgc_strlen ( tlv47 )); }
    {int tlv2; tlv2 = (int)(cgc_strlen ( tlv47 )); }
    {char * tlv12; tlv12 = (char *)(cgc_strlen ( tlv47 )); }
    {cgc_size_t tlv13; tlv13 = (cgc_size_t)(cgc_strlen ( tlv47 )); }
    {int tlv3; tlv3 = (int)(cgc_strlen ( tlv47 )); }
    {int tlv4; tlv4 = (int)(cgc_strlen ( tlv47 )); }
    {int tlv5; tlv5 = (int)(cgc_strlen ( tlv47 )); }
    {char * tlv16; tlv16 = (char *)(cgc_strlen ( tlv47 )); }
    {char * tlv18; tlv18 = (char *)(cgc_strlen ( tlv47 )); }
    {char * tlv17; tlv17 = (char *)(cgc_strlen ( tlv47 )); }
    {char * tlv20; tlv20 = (char *)(cgc_strlen ( tlv47 )); }
    {cgc_size_t tlv22; tlv22 = (cgc_size_t)(cgc_strlen ( tlv47 )); }
    {int tlv6; tlv6 = (int)(cgc_strlen ( tlv47 )); }
    {int tlv7; tlv7 = (int)(cgc_strlen ( tlv47 )); }
    {int tlv8; tlv8 = (int)(cgc_strlen ( tlv47 )); }
    {int tlv9; tlv9 = (int)(cgc_strlen ( tlv47 )); }
    {char * tlv25; tlv25 = (char *)(cgc_strlen ( tlv47 )); }
    {char * tlv27; tlv27 = (char *)(cgc_strlen ( tlv47 )); }
    {char * tlv26; tlv26 = (char *)(cgc_strlen ( tlv47 )); }
    {cgc_size_t tlv30; tlv30 = (cgc_size_t)(cgc_strlen ( tlv47 )); }
    {cgc_size_t tlv33; tlv33 = (cgc_size_t)(cgc_strlen ( tlv47 )); }
    {char * user; user = (char *)(cgc_strlen ( tlv47 )); }
    {char * pass; pass = (char *)(cgc_strlen ( tlv47 )); }
    {int tlv10; tlv10 = (int)(cgc_strlen ( tlv47 )); }
    {char * tlv37; tlv37 = (char *)(cgc_strlen ( tlv47 )); }
    {cgc_size_t tlv38; tlv38 = (cgc_size_t)(cgc_strlen ( tlv47 )); }
    {int tlv11; tlv11 = (int)(cgc_strlen ( tlv47 )); }
    {char * tlv42; tlv42 = (char *)(cgc_strlen ( tlv47 )); }
    {cgc_size_t tlv43; tlv43 = (cgc_size_t)(cgc_strlen ( tlv47 )); }
}
void fix_ingred_service_4_12(){
fix_ingred_service_4_12_0();
}
void fix_ingred_service_4_15_1(){
Token token_ref;
    bzero(&token_ref,1*sizeof(Token));
Token * token = &token_ref;
    {int tlv1; tlv1 = (int)(token -> use); }
    {int tlv2; tlv2 = (int)(token -> use); }
    {char * tlv12; tlv12 = (char *)(token -> use); }
    {cgc_size_t tlv13; tlv13 = (cgc_size_t)(token -> use); }
    {int tlv3; tlv3 = (int)(token -> use); }
    {int tlv4; tlv4 = (int)(token -> use); }
    {int tlv5; tlv5 = (int)(token -> use); }
    {char * tlv16; tlv16 = (char *)(token -> use); }
    {char * tlv18; tlv18 = (char *)(token -> use); }
    {char * tlv17; tlv17 = (char *)(token -> use); }
    {char * tlv20; tlv20 = (char *)(token -> use); }
    {cgc_size_t tlv22; tlv22 = (cgc_size_t)(token -> use); }
    {int tlv6; tlv6 = (int)(token -> use); }
    {int tlv7; tlv7 = (int)(token -> use); }
    {int tlv8; tlv8 = (int)(token -> use); }
    {int tlv9; tlv9 = (int)(token -> use); }
    {char * tlv25; tlv25 = (char *)(token -> use); }
    {char * tlv27; tlv27 = (char *)(token -> use); }
    {char * tlv26; tlv26 = (char *)(token -> use); }
    {cgc_size_t tlv30; tlv30 = (cgc_size_t)(token -> use); }
    {cgc_size_t tlv33; tlv33 = (cgc_size_t)(token -> use); }
    {char * user; user = (char *)(token -> use); }
    {char * pass; pass = (char *)(token -> use); }
    {int tlv10; tlv10 = (int)(token -> use); }
    {char * tlv37; tlv37 = (char *)(token -> use); }
    {cgc_size_t tlv38; tlv38 = (cgc_size_t)(token -> use); }
    {int tlv11; tlv11 = (int)(token -> use); }
    {char * tlv42; tlv42 = (char *)(token -> use); }
    {cgc_size_t tlv43; tlv43 = (cgc_size_t)(token -> use); }
}
void fix_ingred_service_4_15(){
fix_ingred_service_4_15_1();
}
void fix_ingred_service_4_21_0(){
char tlv48_ref;
    bzero(&tlv48_ref,1*sizeof(char));
const char * tlv48 = &tlv48_ref;
    {int tlv1; tlv1 = (int)(cgc_strlen ( tlv48 )); }
    {int tlv2; tlv2 = (int)(cgc_strlen ( tlv48 )); }
    {char * tlv12; tlv12 = (char *)(cgc_strlen ( tlv48 )); }
    {cgc_size_t tlv13; tlv13 = (cgc_size_t)(cgc_strlen ( tlv48 )); }
    {int tlv3; tlv3 = (int)(cgc_strlen ( tlv48 )); }
    {int tlv4; tlv4 = (int)(cgc_strlen ( tlv48 )); }
    {int tlv5; tlv5 = (int)(cgc_strlen ( tlv48 )); }
    {char * tlv16; tlv16 = (char *)(cgc_strlen ( tlv48 )); }
    {char * tlv18; tlv18 = (char *)(cgc_strlen ( tlv48 )); }
    {char * tlv17; tlv17 = (char *)(cgc_strlen ( tlv48 )); }
    {char * tlv20; tlv20 = (char *)(cgc_strlen ( tlv48 )); }
    {cgc_size_t tlv22; tlv22 = (cgc_size_t)(cgc_strlen ( tlv48 )); }
    {int tlv6; tlv6 = (int)(cgc_strlen ( tlv48 )); }
    {int tlv7; tlv7 = (int)(cgc_strlen ( tlv48 )); }
    {int tlv8; tlv8 = (int)(cgc_strlen ( tlv48 )); }
    {int tlv9; tlv9 = (int)(cgc_strlen ( tlv48 )); }
    {char * tlv25; tlv25 = (char *)(cgc_strlen ( tlv48 )); }
    {char * tlv27; tlv27 = (char *)(cgc_strlen ( tlv48 )); }
    {char * tlv26; tlv26 = (char *)(cgc_strlen ( tlv48 )); }
    {cgc_size_t tlv30; tlv30 = (cgc_size_t)(cgc_strlen ( tlv48 )); }
    {cgc_size_t tlv33; tlv33 = (cgc_size_t)(cgc_strlen ( tlv48 )); }
    {char * user; user = (char *)(cgc_strlen ( tlv48 )); }
    {char * pass; pass = (char *)(cgc_strlen ( tlv48 )); }
    {int tlv10; tlv10 = (int)(cgc_strlen ( tlv48 )); }
    {char * tlv37; tlv37 = (char *)(cgc_strlen ( tlv48 )); }
    {cgc_size_t tlv38; tlv38 = (cgc_size_t)(cgc_strlen ( tlv48 )); }
    {int tlv11; tlv11 = (int)(cgc_strlen ( tlv48 )); }
    {char * tlv42; tlv42 = (char *)(cgc_strlen ( tlv48 )); }
    {cgc_size_t tlv43; tlv43 = (cgc_size_t)(cgc_strlen ( tlv48 )); }
}
void fix_ingred_service_4_21(){
fix_ingred_service_4_21_0();
}
void fix_ingred_service_4_23_0(){
char tlv49_ref;
    bzero(&tlv49_ref,1*sizeof(char));
const char * tlv49 = &tlv49_ref;
    {int tlv1; tlv1 = (int)(cgc_strlen ( tlv49 )); }
    {int tlv2; tlv2 = (int)(cgc_strlen ( tlv49 )); }
    {char * tlv12; tlv12 = (char *)(cgc_strlen ( tlv49 )); }
    {cgc_size_t tlv13; tlv13 = (cgc_size_t)(cgc_strlen ( tlv49 )); }
    {int tlv3; tlv3 = (int)(cgc_strlen ( tlv49 )); }
    {int tlv4; tlv4 = (int)(cgc_strlen ( tlv49 )); }
    {int tlv5; tlv5 = (int)(cgc_strlen ( tlv49 )); }
    {char * tlv16; tlv16 = (char *)(cgc_strlen ( tlv49 )); }
    {char * tlv18; tlv18 = (char *)(cgc_strlen ( tlv49 )); }
    {char * tlv17; tlv17 = (char *)(cgc_strlen ( tlv49 )); }
    {char * tlv20; tlv20 = (char *)(cgc_strlen ( tlv49 )); }
    {cgc_size_t tlv22; tlv22 = (cgc_size_t)(cgc_strlen ( tlv49 )); }
    {int tlv6; tlv6 = (int)(cgc_strlen ( tlv49 )); }
    {int tlv7; tlv7 = (int)(cgc_strlen ( tlv49 )); }
    {int tlv8; tlv8 = (int)(cgc_strlen ( tlv49 )); }
    {int tlv9; tlv9 = (int)(cgc_strlen ( tlv49 )); }
    {char * tlv25; tlv25 = (char *)(cgc_strlen ( tlv49 )); }
    {char * tlv27; tlv27 = (char *)(cgc_strlen ( tlv49 )); }
    {char * tlv26; tlv26 = (char *)(cgc_strlen ( tlv49 )); }
    {cgc_size_t tlv30; tlv30 = (cgc_size_t)(cgc_strlen ( tlv49 )); }
    {cgc_size_t tlv33; tlv33 = (cgc_size_t)(cgc_strlen ( tlv49 )); }
    {char * user; user = (char *)(cgc_strlen ( tlv49 )); }
    {char * pass; pass = (char *)(cgc_strlen ( tlv49 )); }
    {int tlv10; tlv10 = (int)(cgc_strlen ( tlv49 )); }
    {char * tlv37; tlv37 = (char *)(cgc_strlen ( tlv49 )); }
    {cgc_size_t tlv38; tlv38 = (cgc_size_t)(cgc_strlen ( tlv49 )); }
    {int tlv11; tlv11 = (int)(cgc_strlen ( tlv49 )); }
    {char * tlv42; tlv42 = (char *)(cgc_strlen ( tlv49 )); }
    {cgc_size_t tlv43; tlv43 = (cgc_size_t)(cgc_strlen ( tlv49 )); }
}
void fix_ingred_service_4_23(){
fix_ingred_service_4_23_0();
}
void fix_ingred_service_4_27_0(){
char tlv50_ref;
    bzero(&tlv50_ref,1*sizeof(char));
const char * tlv50 = &tlv50_ref;
    {int tlv1; tlv1 = (int)(cgc_strlen ( tlv50 )); }
    {int tlv2; tlv2 = (int)(cgc_strlen ( tlv50 )); }
    {char * tlv12; tlv12 = (char *)(cgc_strlen ( tlv50 )); }
    {cgc_size_t tlv13; tlv13 = (cgc_size_t)(cgc_strlen ( tlv50 )); }
    {int tlv3; tlv3 = (int)(cgc_strlen ( tlv50 )); }
    {int tlv4; tlv4 = (int)(cgc_strlen ( tlv50 )); }
    {int tlv5; tlv5 = (int)(cgc_strlen ( tlv50 )); }
    {char * tlv16; tlv16 = (char *)(cgc_strlen ( tlv50 )); }
    {char * tlv18; tlv18 = (char *)(cgc_strlen ( tlv50 )); }
    {char * tlv17; tlv17 = (char *)(cgc_strlen ( tlv50 )); }
    {char * tlv20; tlv20 = (char *)(cgc_strlen ( tlv50 )); }
    {cgc_size_t tlv22; tlv22 = (cgc_size_t)(cgc_strlen ( tlv50 )); }
    {int tlv6; tlv6 = (int)(cgc_strlen ( tlv50 )); }
    {int tlv7; tlv7 = (int)(cgc_strlen ( tlv50 )); }
    {int tlv8; tlv8 = (int)(cgc_strlen ( tlv50 )); }
    {int tlv9; tlv9 = (int)(cgc_strlen ( tlv50 )); }
    {char * tlv25; tlv25 = (char *)(cgc_strlen ( tlv50 )); }
    {char * tlv27; tlv27 = (char *)(cgc_strlen ( tlv50 )); }
    {char * tlv26; tlv26 = (char *)(cgc_strlen ( tlv50 )); }
    {cgc_size_t tlv30; tlv30 = (cgc_size_t)(cgc_strlen ( tlv50 )); }
    {cgc_size_t tlv33; tlv33 = (cgc_size_t)(cgc_strlen ( tlv50 )); }
    {char * user; user = (char *)(cgc_strlen ( tlv50 )); }
    {char * pass; pass = (char *)(cgc_strlen ( tlv50 )); }
    {int tlv10; tlv10 = (int)(cgc_strlen ( tlv50 )); }
    {char * tlv37; tlv37 = (char *)(cgc_strlen ( tlv50 )); }
    {cgc_size_t tlv38; tlv38 = (cgc_size_t)(cgc_strlen ( tlv50 )); }
    {int tlv11; tlv11 = (int)(cgc_strlen ( tlv50 )); }
    {char * tlv42; tlv42 = (char *)(cgc_strlen ( tlv50 )); }
    {cgc_size_t tlv43; tlv43 = (cgc_size_t)(cgc_strlen ( tlv50 )); }
}
void fix_ingred_service_4_27(){
fix_ingred_service_4_27_0();
}
void fix_ingred_service_4_29_0(){
    {int tlv1; tlv1 = (int)(0); }
    {char * tlv12; tlv12 = (char *)(0); }
    {cgc_size_t tlv13; tlv13 = (cgc_size_t)(0); }
    {int tlv3; tlv3 = (int)(0); }
    {int tlv4; tlv4 = (int)(0); }
    {int tlv5; tlv5 = (int)(0); }
    {char * tlv16; tlv16 = (char *)(0); }
    {char * tlv18; tlv18 = (char *)(0); }
    {char * tlv17; tlv17 = (char *)(0); }
    {char * tlv20; tlv20 = (char *)(0); }
    {cgc_size_t tlv22; tlv22 = (cgc_size_t)(0); }
    {int tlv6; tlv6 = (int)(0); }
    {int tlv7; tlv7 = (int)(0); }
    {int tlv8; tlv8 = (int)(0); }
    {int tlv9; tlv9 = (int)(0); }
    {char * tlv25; tlv25 = (char *)(0); }
    {char * tlv26; tlv26 = (char *)(0); }
    {cgc_size_t tlv30; tlv30 = (cgc_size_t)(0); }
    {cgc_size_t tlv33; tlv33 = (cgc_size_t)(0); }
    {char * user; user = (char *)(0); }
    {char * pass; pass = (char *)(0); }
    {int tlv10; tlv10 = (int)(0); }
    {cgc_size_t tlv38; tlv38 = (cgc_size_t)(0); }
    {int tlv11; tlv11 = (int)(0); }
    {char * tlv42; tlv42 = (char *)(0); }
    {cgc_size_t tlv43; tlv43 = (cgc_size_t)(0); }
}
void fix_ingred_service_4_29(){
fix_ingred_service_4_29_0();
}
void fix_ingred_service_4_31_0(){
char tlv51_ref;
    bzero(&tlv51_ref,1*sizeof(char));
const char * tlv51 = &tlv51_ref;
    {int tlv1; tlv1 = (int)(cgc_strlen ( tlv51 )); }
    {int tlv2; tlv2 = (int)(cgc_strlen ( tlv51 )); }
    {char * tlv12; tlv12 = (char *)(cgc_strlen ( tlv51 )); }
    {cgc_size_t tlv13; tlv13 = (cgc_size_t)(cgc_strlen ( tlv51 )); }
    {int tlv3; tlv3 = (int)(cgc_strlen ( tlv51 )); }
    {int tlv4; tlv4 = (int)(cgc_strlen ( tlv51 )); }
    {int tlv5; tlv5 = (int)(cgc_strlen ( tlv51 )); }
    {char * tlv16; tlv16 = (char *)(cgc_strlen ( tlv51 )); }
    {char * tlv18; tlv18 = (char *)(cgc_strlen ( tlv51 )); }
    {char * tlv17; tlv17 = (char *)(cgc_strlen ( tlv51 )); }
    {char * tlv20; tlv20 = (char *)(cgc_strlen ( tlv51 )); }
    {cgc_size_t tlv22; tlv22 = (cgc_size_t)(cgc_strlen ( tlv51 )); }
    {int tlv6; tlv6 = (int)(cgc_strlen ( tlv51 )); }
    {int tlv7; tlv7 = (int)(cgc_strlen ( tlv51 )); }
    {int tlv8; tlv8 = (int)(cgc_strlen ( tlv51 )); }
    {int tlv9; tlv9 = (int)(cgc_strlen ( tlv51 )); }
    {char * tlv25; tlv25 = (char *)(cgc_strlen ( tlv51 )); }
    {char * tlv27; tlv27 = (char *)(cgc_strlen ( tlv51 )); }
    {char * tlv26; tlv26 = (char *)(cgc_strlen ( tlv51 )); }
    {cgc_size_t tlv30; tlv30 = (cgc_size_t)(cgc_strlen ( tlv51 )); }
    {cgc_size_t tlv33; tlv33 = (cgc_size_t)(cgc_strlen ( tlv51 )); }
    {char * user; user = (char *)(cgc_strlen ( tlv51 )); }
    {char * pass; pass = (char *)(cgc_strlen ( tlv51 )); }
    {int tlv10; tlv10 = (int)(cgc_strlen ( tlv51 )); }
    {char * tlv37; tlv37 = (char *)(cgc_strlen ( tlv51 )); }
    {cgc_size_t tlv38; tlv38 = (cgc_size_t)(cgc_strlen ( tlv51 )); }
    {int tlv11; tlv11 = (int)(cgc_strlen ( tlv51 )); }
    {char * tlv42; tlv42 = (char *)(cgc_strlen ( tlv51 )); }
    {cgc_size_t tlv43; tlv43 = (cgc_size_t)(cgc_strlen ( tlv51 )); }
}
void fix_ingred_service_4_31(){
fix_ingred_service_4_31_0();
}
void fix_ingred_service_4(){
fix_ingred_service_4_1();
fix_ingred_service_4_3();
fix_ingred_service_4_5();
fix_ingred_service_4_6();
fix_ingred_service_4_12();
fix_ingred_service_4_15();
fix_ingred_service_4_21();
fix_ingred_service_4_23();
fix_ingred_service_4_27();
fix_ingred_service_4_29();
fix_ingred_service_4_31();
}
void fix_ingred_service_5_3_0(){
char tlv9_ref;
    bzero(&tlv9_ref,1*sizeof(char));
const char * tlv9 = &tlv9_ref;
    {int tlv1; tlv1 = (int)(cgc_strlen ( tlv9 )); }
    {cgc_size_t tlv3; tlv3 = (cgc_size_t)(cgc_strlen ( tlv9 )); }
    {int tlv2; tlv2 = (int)(cgc_strlen ( tlv9 )); }
    {char * tlv8; tlv8 = (char *)(cgc_strlen ( tlv9 )); }
    {char * tlv7; tlv7 = (char *)(cgc_strlen ( tlv9 )); }
    {char * tlv6; tlv6 = (char *)(cgc_strlen ( tlv9 )); }
}
void fix_ingred_service_5_3(){
fix_ingred_service_5_3_0();
}
void fix_ingred_service_5_5_0(){
Message message_ref;
    bzero(&message_ref,1*sizeof(Message));
Message * message = &message_ref;
    {int tlv1; tlv1 = (int)(message -> command); }
    {cgc_size_t tlv3; tlv3 = (cgc_size_t)(message -> command); }
    {char * tlv8; tlv8 = (char *)(message -> command); }
    {char * tlv6; tlv6 = (char *)(message -> command); }
}
void fix_ingred_service_5_5_1(){
Message message_ref;
    bzero(&message_ref,1*sizeof(Message));
Message * message = &message_ref;
    {int tlv1; tlv1 = (int)(message -> auth); }
    {cgc_size_t tlv3; tlv3 = (cgc_size_t)(message -> auth); }
    {int tlv2; tlv2 = (int)(message -> auth); }
    {char * tlv8; tlv8 = (char *)(message -> auth); }
    {char * tlv7; tlv7 = (char *)(message -> auth); }
    {char * tlv6; tlv6 = (char *)(message -> auth); }
}
void fix_ingred_service_5_5_2(){
Message message_ref;
    bzero(&message_ref,1*sizeof(Message));
Message * message = &message_ref;
    {int tlv1; tlv1 = (int)(message -> credential); }
    {cgc_size_t tlv3; tlv3 = (cgc_size_t)(message -> credential); }
    {char * tlv8; tlv8 = (char *)(message -> credential); }
    {char * tlv6; tlv6 = (char *)(message -> credential); }
}
void fix_ingred_service_5_5(){
fix_ingred_service_5_5_0();
fix_ingred_service_5_5_1();
fix_ingred_service_5_5_2();
}
void fix_ingred_service_5(){
fix_ingred_service_5_3();
fix_ingred_service_5_5();
}
void fix_ingred_service_6_0_0(){
    {cgc_size_t bytes; bytes = (cgc_size_t)(0); }
    {cgc_size_t size; size = (cgc_size_t)(0); }
    {char * vuln_buf; vuln_buf = (char *)(0); }
    {char * out; out = (char *)(0); }
    {char * filler_buf [ 510 ]; filler_buf [ ( 510 )-1 ] = (char *)(0); }
    {int ret; ret = (int)(0); }
    {int tlv1; tlv1 = (int)(0); }
    {void * tlv8; tlv8 = (void *)(0); }
    {cgc_size_t tlv7; tlv7 = (cgc_size_t)(0); }
    {int tlv3; tlv3 = (int)(0); }
    {unsigned int tlv9; tlv9 = (unsigned int)(0); }
    {cgc_size_t tlv12; tlv12 = (cgc_size_t)(0); }
    {int tlv4; tlv4 = (int)(0); }
    {int tlv18; tlv18 = (int)(0); }
    {void * tlv17; tlv17 = (void *)(0); }
    {cgc_size_t tlv16; tlv16 = (cgc_size_t)(0); }
    {unsigned int tlv19; tlv19 = (unsigned int)(0); }
}
void fix_ingred_service_6_0(){
fix_ingred_service_6_0_0();
}
void fix_ingred_service_6_1_0(){
    {cgc_size_t bytes; bytes = (cgc_size_t)(private_key); }
    {cgc_size_t size; size = (cgc_size_t)(private_key); }
    {char * vuln_buf; vuln_buf = (char *)(private_key); }
    {char * out; out = (char *)(private_key); }
    {char * filler_buf [ 510 ]; filler_buf [ ( 510 )-1 ] = (char *)(private_key); }
    {int ret; ret = (int)(private_key); }
    {int tlv1; tlv1 = (int)(private_key); }
    {void * tlv8; tlv8 = (void *)(private_key); }
    {cgc_size_t tlv7; tlv7 = (cgc_size_t)(private_key); }
    {int tlv3; tlv3 = (int)(private_key); }
    {unsigned int tlv9; tlv9 = (unsigned int)(private_key); }
    {cgc_size_t tlv12; tlv12 = (cgc_size_t)(private_key); }
    {int tlv4; tlv4 = (int)(private_key); }
    {int tlv18; tlv18 = (int)(private_key); }
    {void * tlv17; tlv17 = (void *)(private_key); }
    {cgc_size_t tlv16; tlv16 = (cgc_size_t)(private_key); }
    {unsigned int tlv19; tlv19 = (unsigned int)(private_key); }
}
void fix_ingred_service_6_1_1(){
    {cgc_size_t bytes; bytes = (cgc_size_t)(sizeof ( private_key )); }
    {cgc_size_t size; size = (cgc_size_t)(sizeof ( private_key )); }
    {char * vuln_buf; vuln_buf = (char *)(sizeof ( private_key )); }
    {char * out; out = (char *)(sizeof ( private_key )); }
    {char * filler_buf [ 510 ]; filler_buf [ ( 510 )-1 ] = (char *)(sizeof ( private_key )); }
    {int ret; ret = (int)(sizeof ( private_key )); }
    {int tlv1; tlv1 = (int)(sizeof ( private_key )); }
    {void * tlv8; tlv8 = (void *)(sizeof ( private_key )); }
    {cgc_size_t tlv7; tlv7 = (cgc_size_t)(sizeof ( private_key )); }
    {int tlv3; tlv3 = (int)(sizeof ( private_key )); }
    {unsigned int tlv9; tlv9 = (unsigned int)(sizeof ( private_key )); }
    {cgc_size_t tlv12; tlv12 = (cgc_size_t)(sizeof ( private_key )); }
    {int tlv4; tlv4 = (int)(sizeof ( private_key )); }
    {int tlv18; tlv18 = (int)(sizeof ( private_key )); }
    {void * tlv17; tlv17 = (void *)(sizeof ( private_key )); }
    {cgc_size_t tlv16; tlv16 = (cgc_size_t)(sizeof ( private_key )); }
    {unsigned int tlv19; tlv19 = (unsigned int)(sizeof ( private_key )); }
}
void fix_ingred_service_6_1(){
fix_ingred_service_6_1_0();
fix_ingred_service_6_1_1();
}
void fix_ingred_service_6_2_2(){
int tlv1;
    bzero(&tlv1,sizeof(int));
    {cgc_size_t bytes; bytes = (cgc_size_t)(tlv1); }
    {cgc_size_t size; size = (cgc_size_t)(tlv1); }
    {char * vuln_buf; vuln_buf = (char *)(tlv1); }
    {char * out; out = (char *)(tlv1); }
    {char * filler_buf [ 510 ]; filler_buf [ ( 510 )-1 ] = (char *)(tlv1); }
    {int ret; ret = (int)(tlv1); }
    {void * tlv8; tlv8 = (void *)(tlv1); }
    {cgc_size_t tlv7; tlv7 = (cgc_size_t)(tlv1); }
    {int tlv3; tlv3 = (int)(tlv1); }
    {unsigned int tlv9; tlv9 = (unsigned int)(tlv1); }
    {cgc_size_t tlv12; tlv12 = (cgc_size_t)(tlv1); }
    {int tlv4; tlv4 = (int)(tlv1); }
    {int tlv18; tlv18 = (int)(tlv1); }
    {void * tlv17; tlv17 = (void *)(tlv1); }
    {cgc_size_t tlv16; tlv16 = (cgc_size_t)(tlv1); }
    {unsigned int tlv19; tlv19 = (unsigned int)(tlv1); }
}
void fix_ingred_service_6_2(){
fix_ingred_service_6_2_2();
}
void fix_ingred_service_6_3_0(){
    {char * vuln_buf; vuln_buf = (char *)(1); }
    {char * out; out = (char *)(1); }
    {char * filler_buf [ 510 ]; filler_buf [ ( 510 )-1 ] = (char *)(1); }
    {int ret; ret = (int)(1); }
    {int tlv1; tlv1 = (int)(1); }
    {void * tlv8; tlv8 = (void *)(1); }
    {cgc_size_t tlv7; tlv7 = (cgc_size_t)(1); }
    {int tlv3; tlv3 = (int)(1); }
    {unsigned int tlv9; tlv9 = (unsigned int)(1); }
    {int tlv4; tlv4 = (int)(1); }
    {int tlv18; tlv18 = (int)(1); }
    {cgc_size_t tlv16; tlv16 = (cgc_size_t)(1); }
    {unsigned int tlv19; tlv19 = (unsigned int)(1); }
}
void fix_ingred_service_6_3(){
fix_ingred_service_6_3_0();
}
void fix_ingred_service_6_8_0(){
char tlv20_ref;
    bzero(&tlv20_ref,1*sizeof(char));
const char * tlv20 = &tlv20_ref;
    {cgc_size_t bytes; bytes = (cgc_size_t)(cgc_strlen ( tlv20 )); }
    {cgc_size_t size; size = (cgc_size_t)(cgc_strlen ( tlv20 )); }
    {char * vuln_buf; vuln_buf = (char *)(cgc_strlen ( tlv20 )); }
    {char * out; out = (char *)(cgc_strlen ( tlv20 )); }
    {char * filler_buf [ 510 ]; filler_buf [ ( 510 )-1 ] = (char *)(cgc_strlen ( tlv20 )); }
    {int ret; ret = (int)(cgc_strlen ( tlv20 )); }
    {int tlv1; tlv1 = (int)(cgc_strlen ( tlv20 )); }
    {void * tlv8; tlv8 = (void *)(cgc_strlen ( tlv20 )); }
    {cgc_size_t tlv7; tlv7 = (cgc_size_t)(cgc_strlen ( tlv20 )); }
    {int tlv3; tlv3 = (int)(cgc_strlen ( tlv20 )); }
    {unsigned int tlv9; tlv9 = (unsigned int)(cgc_strlen ( tlv20 )); }
    {cgc_size_t tlv12; tlv12 = (cgc_size_t)(cgc_strlen ( tlv20 )); }
    {int tlv4; tlv4 = (int)(cgc_strlen ( tlv20 )); }
    {int tlv18; tlv18 = (int)(cgc_strlen ( tlv20 )); }
    {void * tlv17; tlv17 = (void *)(cgc_strlen ( tlv20 )); }
    {cgc_size_t tlv16; tlv16 = (cgc_size_t)(cgc_strlen ( tlv20 )); }
    {unsigned int tlv19; tlv19 = (unsigned int)(cgc_strlen ( tlv20 )); }
}
void fix_ingred_service_6_8(){
fix_ingred_service_6_8_0();
}
void fix_ingred_service_6_10_0(){
    {cgc_size_t bytes; bytes = (cgc_size_t)(STDOUT); }
    {cgc_size_t size; size = (cgc_size_t)(STDOUT); }
    {char * vuln_buf; vuln_buf = (char *)(STDOUT); }
    {char * out; out = (char *)(STDOUT); }
    {char * filler_buf [ 510 ]; filler_buf [ ( 510 )-1 ] = (char *)(STDOUT); }
    {int ret; ret = (int)(STDOUT); }
    {int tlv1; tlv1 = (int)(STDOUT); }
    {void * tlv8; tlv8 = (void *)(STDOUT); }
    {cgc_size_t tlv7; tlv7 = (cgc_size_t)(STDOUT); }
    {int tlv3; tlv3 = (int)(STDOUT); }
    {unsigned int tlv9; tlv9 = (unsigned int)(STDOUT); }
    {cgc_size_t tlv12; tlv12 = (cgc_size_t)(STDOUT); }
    {int tlv4; tlv4 = (int)(STDOUT); }
    {int tlv18; tlv18 = (int)(STDOUT); }
    {void * tlv17; tlv17 = (void *)(STDOUT); }
    {cgc_size_t tlv16; tlv16 = (cgc_size_t)(STDOUT); }
    {unsigned int tlv19; tlv19 = (unsigned int)(STDOUT); }
}
void fix_ingred_service_6_10_1(){
    {cgc_size_t bytes; bytes = (cgc_size_t)("!"); }
    {cgc_size_t size; size = (cgc_size_t)("!"); }
    {char * vuln_buf; vuln_buf = (char *)("!"); }
    {char * out; out = (char *)("!"); }
    {char * filler_buf [ 510 ]; filler_buf [ ( 510 )-1 ] = (char *)("!"); }
    {int ret; ret = (int)("!"); }
    {int tlv1; tlv1 = (int)("!"); }
    {void * tlv8; tlv8 = (void *)("!"); }
    {cgc_size_t tlv7; tlv7 = (cgc_size_t)("!"); }
    {int tlv3; tlv3 = (int)("!"); }
    {unsigned int tlv9; tlv9 = (unsigned int)("!"); }
    {cgc_size_t tlv12; tlv12 = (cgc_size_t)("!"); }
    {int tlv4; tlv4 = (int)("!"); }
    {int tlv18; tlv18 = (int)("!"); }
    {void * tlv17; tlv17 = (void *)("!"); }
    {cgc_size_t tlv16; tlv16 = (cgc_size_t)("!"); }
    {unsigned int tlv19; tlv19 = (unsigned int)("!"); }
}
void fix_ingred_service_6_10(){
fix_ingred_service_6_10_0();
fix_ingred_service_6_10_1();
}
void fix_ingred_service_6_11_0(){
const char tlv21 [0];
    bzero(&tlv21 [0],sizeof(char));
    {cgc_size_t bytes; bytes = (cgc_size_t)(cgc_strlen ( tlv21 )); }
    {cgc_size_t size; size = (cgc_size_t)(cgc_strlen ( tlv21 )); }
    {char * vuln_buf; vuln_buf = (char *)(cgc_strlen ( tlv21 )); }
    {char * out; out = (char *)(cgc_strlen ( tlv21 )); }
    {char * filler_buf [ 510 ]; filler_buf [ ( 510 )-1 ] = (char *)(cgc_strlen ( tlv21 )); }
    {int ret; ret = (int)(cgc_strlen ( tlv21 )); }
    {int tlv1; tlv1 = (int)(cgc_strlen ( tlv21 )); }
    {void * tlv8; tlv8 = (void *)(cgc_strlen ( tlv21 )); }
    {cgc_size_t tlv7; tlv7 = (cgc_size_t)(cgc_strlen ( tlv21 )); }
    {int tlv3; tlv3 = (int)(cgc_strlen ( tlv21 )); }
    {unsigned int tlv9; tlv9 = (unsigned int)(cgc_strlen ( tlv21 )); }
    {cgc_size_t tlv12; tlv12 = (cgc_size_t)(cgc_strlen ( tlv21 )); }
    {int tlv4; tlv4 = (int)(cgc_strlen ( tlv21 )); }
    {int tlv18; tlv18 = (int)(cgc_strlen ( tlv21 )); }
    {void * tlv17; tlv17 = (void *)(cgc_strlen ( tlv21 )); }
    {cgc_size_t tlv16; tlv16 = (cgc_size_t)(cgc_strlen ( tlv21 )); }
    {unsigned int tlv19; tlv19 = (unsigned int)(cgc_strlen ( tlv21 )); }
}
void fix_ingred_service_6_11(){
fix_ingred_service_6_11_0();
}
void fix_ingred_service_6_12_2(){
int tlv4;
    bzero(&tlv4,sizeof(int));
    {cgc_size_t bytes; bytes = (cgc_size_t)(tlv4); }
    {cgc_size_t size; size = (cgc_size_t)(tlv4); }
    {char * vuln_buf; vuln_buf = (char *)(tlv4); }
    {char * out; out = (char *)(tlv4); }
    {char * filler_buf [ 510 ]; filler_buf [ ( 510 )-1 ] = (char *)(tlv4); }
    {int ret; ret = (int)(tlv4); }
    {int tlv1; tlv1 = (int)(tlv4); }
    {void * tlv8; tlv8 = (void *)(tlv4); }
    {cgc_size_t tlv7; tlv7 = (cgc_size_t)(tlv4); }
    {int tlv3; tlv3 = (int)(tlv4); }
    {unsigned int tlv9; tlv9 = (unsigned int)(tlv4); }
    {cgc_size_t tlv12; tlv12 = (cgc_size_t)(tlv4); }
    {int tlv18; tlv18 = (int)(tlv4); }
    {void * tlv17; tlv17 = (void *)(tlv4); }
    {cgc_size_t tlv16; tlv16 = (cgc_size_t)(tlv4); }
    {unsigned int tlv19; tlv19 = (unsigned int)(tlv4); }
}
void fix_ingred_service_6_12(){
fix_ingred_service_6_12_2();
}
void fix_ingred_service_6(){
fix_ingred_service_6_0();
fix_ingred_service_6_1();
fix_ingred_service_6_2();
fix_ingred_service_6_3();
fix_ingred_service_6_8();
fix_ingred_service_6_10();
fix_ingred_service_6_11();
fix_ingred_service_6_12();
}
