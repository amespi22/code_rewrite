

#include "cgc_ctype.h"
#include "cgc_stdlib.h"
#include "cgc_stdint.h"
#include "cgc_string.h"
#include "cgc_modem.h"
#define PAGE_LINES 40
typedef struct thread {
    struct thread *next;
    struct message *messages;
    unsigned int id;
    char topic[64];
} thread_t;
typedef struct message {
    struct message *next;
    unsigned int id;
    char topic[64];
    const char *body;
} message_t;
static thread_t *g_threads;
static unsigned int g_next_id = 1000;
static struct {
#define S_MENU 0
#define S_LIST_THREAD 1
#define S_LIST_MESSAGE 2
#define S_POST_WAIT_TOPIC 3
#define S_POST_WAIT_BODY 4
    int state;
    union {
	struct {
	    thread_t *next_thread;
	    message_t *next_message;
	} list;
	struct {
	    thread_t *thread;
	    char topic[64];
	} post;
    };
} g_state;
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

void fix_ingred_bbs_0_2_0();
void fix_ingred_bbs_0_2();
void fix_ingred_bbs_0();
static void send_string(const char *str)
{
if (fix_ingred_enable){ fix_ingred_bbs_0(); };
    {
        uint8_t* tlv2;
        tlv2 = ( void * ) str;
        cgc_size_t tlv1;
        {
            const char* tlv3 = str;
            tlv1 = cgc_strlen(tlv3);
        }
        cgc_modem_output(tlv2,tlv1);
    }
}

void fix_ingred_bbs_1();
void cgc_bbs_help()
{
if (fix_ingred_enable){ fix_ingred_bbs_1(); };
    const static char help_text [ ] = "Available commands:\n" "\t(L)ist [thread-id]\n" "\t\tList all threads, or messages in a thread\n" "\t(P)ost [thread-id]\n" "\t\tPost a new thread, or a reply to a thread\n" "\t(R)ead message-id\n" "\t\tGet message contents\n" "\t(H)elp\n" "\t\tThis screen\n";
    send_string(help_text);
}

void fix_ingred_bbs_2();
void cgc_bbs_menu()
{
if (fix_ingred_enable){ fix_ingred_bbs_2(); };
    const static char menu_text [ ] = "(L)ist, (H)elp, (P)ost, (R)ead\n";
    send_string(menu_text);
}

void fix_ingred_bbs_3();
thread_t *cgc_find_thread(int id)
{
if (fix_ingred_enable){ fix_ingred_bbs_3(); };
    thread_t *t;
    for (t = g_threads; t != NULL; t = t->next) {
	if (t->id < id) {
	    break;
	}
	if (t->id == id) {
	    return t;
	}
    }
    return NULL;
}

void fix_ingred_bbs_4();
message_t *cgc_find_message(int id)
{
if (fix_ingred_enable){ fix_ingred_bbs_4(); };
    thread_t *t;
    message_t *m;
    for (t = g_threads; t != NULL; t = t->next) {
	for (m = t->messages; m != NULL; m = m->next) {
	    if (m->id < id) {
		break;
	    }
	    if (m->id == id) {
		return m;
	    }
	}
    }
    return NULL;
}

void fix_ingred_bbs_5();
void cgc_send_thread(thread_t * t)
{
if (fix_ingred_enable){ fix_ingred_bbs_5(); };
    char buf[100];
    cgc_sprintf(buf, "%08d - %s\n", t->id, t->topic);
    send_string(buf);
}

void fix_ingred_bbs_6();
void cgc_send_message_brief(message_t * m)
{
if (fix_ingred_enable){ fix_ingred_bbs_6(); };
    char buf[100];
    cgc_sprintf(buf, "%08d - %s\n", m->id, m->topic);
    send_string(buf);
}

void fix_ingred_bbs_7();
void cgc_send_message(message_t * m)
{
if (fix_ingred_enable){ fix_ingred_bbs_7(); };
    char buf[100];
    cgc_sprintf(buf, "%08d - %s\n", m->id, m->topic);
    send_string(buf);
    {
        const char* tlv1 = m -> body;
        send_string(tlv1);
    }
}

void fix_ingred_bbs_8_1_0();
void fix_ingred_bbs_8_1_3();
void fix_ingred_bbs_8_1();
void fix_ingred_bbs_8();
void cgc_send_thread_list(thread_t * t)
{
if (fix_ingred_enable){ fix_ingred_bbs_8(); };
    int i;
    for (i = 0; i < PAGE_LINES && t != NULL; i++, t = t->next)
    {
	cgc_send_thread(t);
    }
    if (t) {
	g_state.state = S_LIST_THREAD;
	g_state.list.next_thread = t;
 {
     const char tlv1 [ ] = "(N)ext page, (Q)uit\n";
    	send_string(tlv1);
 }
    } else {
	g_state.state = S_MENU;
    }
}

void fix_ingred_bbs_9();
void cgc_send_message_list(message_t * t)
{
if (fix_ingred_enable){ fix_ingred_bbs_9(); };
    int i;
    for (i = 0; i < PAGE_LINES && t != NULL; i++, t = t->next)
    {
	cgc_send_message_brief(t);
    }
    if (t) {
	g_state.state = S_LIST_MESSAGE;
	g_state.list.next_message = t;
 {
     const char tlv1 [ ] = "(N)ext page, (Q)uit\n";
    	send_string(tlv1);
 }
    } else {
	g_state.state = S_MENU;
    }
}

void fix_ingred_bbs_10_2_1();
void fix_ingred_bbs_10_2();
void fix_ingred_bbs_10_3_0();
void fix_ingred_bbs_10_3();
void fix_ingred_bbs_10();
void cgc_do_list(const char *str)
{
if (fix_ingred_enable){ fix_ingred_bbs_10(); };
    if (str[1] == ' ') {
 int id;
 {
     const char* tlv3 = & str [ 2 ];
     char** tlv2;
      tlv2 = NULL;
     int tlv1;
     tlv1 = 10;
     id = cgc_strtol(tlv3,tlv2,tlv1);
 }
 thread_t* t;
 {
     int tlv4;
     tlv4 = id;
     t = cgc_find_thread(tlv4);
 }
	if (t) {
     {
         message_t* tlv5;
         tlv5 = t -> messages;
    	    cgc_send_message_list(tlv5);
     }
	} else {
     {
         const char tlv6 [ ] = "Thread ID not found.\n";
    	    send_string(tlv6);
     }
	}
    } else {
	cgc_send_thread_list(g_threads);
    }
}

void fix_ingred_bbs_11_2_1();
void fix_ingred_bbs_11_2();
void fix_ingred_bbs_11_3_0();
void fix_ingred_bbs_11_3();
void fix_ingred_bbs_11();
void cgc_do_post(const char *str)
{
if (fix_ingred_enable){ fix_ingred_bbs_11(); };
    thread_t* t;
    t = NULL;
    if (str[1] == ' ') {
 int id;
 {
     const char* tlv4 = & str [ 2 ];
     char** tlv3;
      tlv3 = NULL;
     int tlv2;
     tlv2 = 10;
     id = cgc_strtol(tlv4,tlv3,tlv2);
 }
 {
     int tlv5;
     tlv5 = id;
    	t = cgc_find_thread(tlv5);
 }
	if (t == NULL) {
     {
         const char tlv6 [ ] = "Thread ID not found.\n";
    	    send_string(tlv6);
     }
	    return;
	}
    }
    {
        const char tlv1 [ ] = "Subject?\n";
        send_string(tlv1);
    }
    g_state.state = S_POST_WAIT_TOPIC;
    g_state.post.thread = t;
}

void fix_ingred_bbs_12();
void cgc_do_read(const char *str)
{
if (fix_ingred_enable){ fix_ingred_bbs_12(); };
    if (str[1] != ' ') {
 {
     const char tlv5 [ ] = "Missing required argument.\n";
    	send_string(tlv5);
 }
	return;
    }
    int id;
    {
        const char* tlv3 = & str [ 2 ];
        char** tlv2;
         tlv2 = NULL;
        int tlv1;
        tlv1 = 10;
        id = cgc_strtol(tlv3,tlv2,tlv1);
    }
    message_t* m;
    {
        int tlv4;
        tlv4 = id;
        m = cgc_find_message(tlv4);
    }
    if (m) {
	cgc_send_message(m);
    } else {
 {
     const char tlv6 [ ] = "Message ID not found.\n";
    	send_string(tlv6);
 }
    }
}

void fix_ingred_bbs_13_7_0();
void fix_ingred_bbs_13_7();
void fix_ingred_bbs_13_9_0();
void fix_ingred_bbs_13_9();
void fix_ingred_bbs_13_10_0();
void fix_ingred_bbs_13_10();
void fix_ingred_bbs_13_12_0();
void fix_ingred_bbs_13_12();
void fix_ingred_bbs_13();
void cgc_handle_post(const char *str)
{
if (fix_ingred_enable){ fix_ingred_bbs_13(); };
    if (g_state.state == S_POST_WAIT_TOPIC) {
 {
     char* tlv3;
      tlv3 = g_state . post . topic;
     const char* tlv2 = str;
     cgc_size_t tlv1;
     tlv1 = sizeof ( g_state . post . topic ) - 1;
    	cgc_strncpy(tlv3,tlv2,tlv1);
 }
	g_state.post.topic[sizeof(g_state.post.topic) - 1] = 0;
 {
     const char tlv4 [ ] = "Body?\n";
    	send_string(tlv4);
 }
	g_state.state = S_POST_WAIT_BODY;
    } else {
	if (g_state.state == S_POST_WAIT_BODY) {
     thread_t* t;
     t = g_state . post . thread;
	    if (t == NULL) {
  {
      cgc_size_t tlv10;
      tlv10 = sizeof ( thread_t );
    		t = cgc_malloc(tlv10);
  }
		if (t == NULL) {
		    goto fail;
		}
  {
      char* tlv7;
       tlv7 = t -> topic;
      const char* tlv6 = g_state . post . topic;
    		cgc_strcpy(tlv7,tlv6);
  }
		t->id = g_next_id++;
		t->next = g_threads;
		t->messages = NULL;
		g_threads = t;
	    }
     message_t* m;
     {
         cgc_size_t tlv5;
         tlv5 = sizeof ( message_t );
         m = cgc_malloc(tlv5);
     }
	    if (m) {
		m->id = g_next_id++;
  {
      char* tlv9;
       tlv9 = m -> topic;
      const char* tlv8 = g_state . post . topic;
    		cgc_strcpy(tlv9,tlv8);
  }
  {
      const char* tlv11 = str;
    		m->body = cgc_strdup(tlv11);
  }
		if (m->body == NULL) {
		    goto fail;
		}
		m->next = t->messages;
		t->messages = m;
	    }
	  fail:
	    g_state.state = S_MENU;
	}
    }
}

void fix_ingred_bbs_14_1_0();
void fix_ingred_bbs_14_1();
void fix_ingred_bbs_14_2_1();
void fix_ingred_bbs_14_2_2();
void fix_ingred_bbs_14_2();
void fix_ingred_bbs_14_5_0();
void fix_ingred_bbs_14_5_1();
void fix_ingred_bbs_14_5();
void fix_ingred_bbs_14();
void cgc_handle_list(const char *str)
{
if (fix_ingred_enable){ fix_ingred_bbs_14(); };
    int tlv1;
    {
        int tlv3;
        tlv3 = str [ 0 ];
        tlv1 = cgc_tolower(tlv3);
    }
    if (tlv1 == 'q') {
	g_state.state = S_MENU;
    } else {
 int tlv2;
 {
     int tlv4;
     tlv4 = str [ 0 ];
     tlv2 = cgc_tolower(tlv4);
 }
	if (tlv2 == 'n') {
	    if (g_state.state == S_LIST_THREAD) {
  {
      thread_t* tlv6;
      tlv6 = g_state . list . next_thread;
    		cgc_send_thread_list(tlv6);
  }
	    } else {
  {
      message_t* tlv7;
      tlv7 = g_state . list . next_message;
    		cgc_send_message_list(tlv7);
  }
	    }
	} else {
     {
         const char tlv5 [ ] = "Bad input.\n";
    	    send_string(tlv5);
     }
	}
    }
}

void fix_ingred_bbs_15_0_0();
void fix_ingred_bbs_15_0();
void fix_ingred_bbs_15_1_0();
void fix_ingred_bbs_15_1();
void fix_ingred_bbs_15();
void cgc_handle_menu(const char *str)
{
if (fix_ingred_enable){ fix_ingred_bbs_15(); };
    int cmd;
    cmd = str [ 0 ];

    if (str[1] != 0 && str[1] != ' ') {
	cmd = 0;
    }
    switch (cmd) {
    case 'H':
	{
    case 'h':
	    {
    case '?':
		{
		    cgc_bbs_help();
		}
	    }
	}
	break;
    case 'L':
	{
    case 'l':
	    {
		cgc_do_list(str);
	    }
	}
	break;
    case 'P':
	{
    case 'p':
	    {
		cgc_do_post(str);
	    }
	}
	break;
    case 'R':
	{
    case 'r':
	    {
		cgc_do_read(str);
	    }
	}
	break;
    case 'Q':
	{
    case 'q':
	    {
		cgc_exit(0);
	    }
	}
	break;
    default:
	{
     {
         const char tlv1 [ ] = "Bad input. Unknown command.\n";
    	    send_string(tlv1);
     }
	}
	break;
    }
}

void fix_ingred_bbs_16_1_0();
void fix_ingred_bbs_16_1_1();
void fix_ingred_bbs_16_1_2();
void fix_ingred_bbs_16_1();
void fix_ingred_bbs_16_2_0();
void fix_ingred_bbs_16_2();
void fix_ingred_bbs_16_3_1();
void fix_ingred_bbs_16_3_2();
void fix_ingred_bbs_16_3();
void fix_ingred_bbs_16();
void cgc_bbs_rx(const uint8_t * data, cgc_size_t count)
{
if (fix_ingred_enable){ fix_ingred_bbs_16(); };
    char str[101];
    {
        void* tlv4;
        tlv4 = str;
        void* tlv3;
        tlv3 = data;
        cgc_size_t tlv2;
        tlv2 = count;
        cgc_memcpy(tlv4,tlv3,tlv2);
    }
    str[count] = 0;
;		// make sure string is NULL-terminated
    cgc_size_t tlv1;
    {
        const char* tlv5 = str;
        tlv1 = cgc_strlen(tlv5);
    }
    if (tlv1 == 0) {
	return;
    }
    if (g_state.state == S_MENU) {
	cgc_handle_menu(str);
    } else {
	if (g_state.state == S_LIST_THREAD || g_state.state == S_LIST_MESSAGE) {
	    cgc_handle_list(str);
	} else {
	    if (g_state.state == S_POST_WAIT_TOPIC || g_state.state == S_POST_WAIT_BODY) {
		cgc_handle_post(str);
	    }
	}
    }
    if (g_state.state == S_MENU) {
	cgc_bbs_menu();
    }
}

void fix_ingred_bbs_17();
int main(int cgc_argc, char *cgc_argv[])
{
if (fix_ingred_enable){ fix_ingred_bbs_17(); };
    cgc_modem_init();
    cgc_bbs_menu();
    cgc_modem_loop(cgc_bbs_rx);
    return 0;
}

void fix_ingred_bbs_0_2_0(){
char tlv3_ref;
    bzero(&tlv3_ref,1*sizeof(char));
const char * tlv3 = &tlv3_ref;
    {cgc_size_t tlv1; tlv1 = (cgc_size_t)(cgc_strlen ( tlv3 )); }
}
void fix_ingred_bbs_0_2(){
fix_ingred_bbs_0_2_0();
}
void fix_ingred_bbs_0(){
fix_ingred_bbs_0_2();
}
void fix_ingred_bbs_1(){
}
void fix_ingred_bbs_2(){
}
void fix_ingred_bbs_3(){
}
void fix_ingred_bbs_4(){
}
void fix_ingred_bbs_5(){
}
void fix_ingred_bbs_6(){
}
void fix_ingred_bbs_7(){
}
void fix_ingred_bbs_8_1_0(){
int i;
    bzero(&i,sizeof(int));
    {int i; i = (int)(0); }
}
void fix_ingred_bbs_8_1_3(){
int i;
    bzero(&i,sizeof(int));
    {int i; i = (int)(PAGE_LINES); }
}
void fix_ingred_bbs_8_1(){
fix_ingred_bbs_8_1_0();
fix_ingred_bbs_8_1_3();
}
void fix_ingred_bbs_8(){
fix_ingred_bbs_8_1();
}
void fix_ingred_bbs_9(){
}
void fix_ingred_bbs_10_2_1(){
    {int id; id = (int)(10); }
    {int tlv1; tlv1 = (int)(10); }
    {int tlv4; tlv4 = (int)(10); }
}
void fix_ingred_bbs_10_2(){
fix_ingred_bbs_10_2_1();
}
void fix_ingred_bbs_10_3_0(){
int id;
    bzero(&id,sizeof(int));
    {int tlv1; tlv1 = (int)(id); }
    {int tlv4; tlv4 = (int)(id); }
}
void fix_ingred_bbs_10_3(){
fix_ingred_bbs_10_3_0();
}
void fix_ingred_bbs_10(){
fix_ingred_bbs_10_2();
fix_ingred_bbs_10_3();
}
void fix_ingred_bbs_11_2_1(){
    {int tlv2; tlv2 = (int)(10); }
    {int tlv5; tlv5 = (int)(10); }
}
void fix_ingred_bbs_11_2(){
fix_ingred_bbs_11_2_1();
}
void fix_ingred_bbs_11_3_0(){
int id;
    bzero(&id,sizeof(int));
    {int tlv2; tlv2 = (int)(id); }
    {int tlv5; tlv5 = (int)(id); }
}
void fix_ingred_bbs_11_3(){
fix_ingred_bbs_11_3_0();
}
void fix_ingred_bbs_11(){
fix_ingred_bbs_11_2();
fix_ingred_bbs_11_3();
}
void fix_ingred_bbs_12(){
}
void fix_ingred_bbs_13_7_0(){
    {char * tlv3; tlv3 = (char *)(sizeof ( thread_t )); }
    {cgc_size_t tlv1; tlv1 = (cgc_size_t)(sizeof ( thread_t )); }
    {cgc_size_t tlv5; tlv5 = (cgc_size_t)(sizeof ( thread_t )); }
    {cgc_size_t tlv10; tlv10 = (cgc_size_t)(sizeof ( thread_t )); }
    {char * tlv7; tlv7 = (char *)(sizeof ( thread_t )); }
    {char * tlv9; tlv9 = (char *)(sizeof ( thread_t )); }
}
void fix_ingred_bbs_13_7(){
fix_ingred_bbs_13_7_0();
}
void fix_ingred_bbs_13_9_0(){
thread_t t_ref;
    bzero(&t_ref,1*sizeof(thread_t));
thread_t * t = &t_ref;
    {char * tlv3; tlv3 = (char *)(t -> topic); }
    {cgc_size_t tlv1; tlv1 = (cgc_size_t)(t -> topic); }
    {cgc_size_t tlv5; tlv5 = (cgc_size_t)(t -> topic); }
    {cgc_size_t tlv10; tlv10 = (cgc_size_t)(t -> topic); }
    {char * tlv7; tlv7 = (char *)(t -> topic); }
    {char * tlv9; tlv9 = (char *)(t -> topic); }
}
void fix_ingred_bbs_13_9(){
fix_ingred_bbs_13_9_0();
}
void fix_ingred_bbs_13_10_0(){
    {char * tlv3; tlv3 = (char *)(sizeof ( message_t )); }
    {cgc_size_t tlv1; tlv1 = (cgc_size_t)(sizeof ( message_t )); }
    {cgc_size_t tlv5; tlv5 = (cgc_size_t)(sizeof ( message_t )); }
    {cgc_size_t tlv10; tlv10 = (cgc_size_t)(sizeof ( message_t )); }
    {char * tlv7; tlv7 = (char *)(sizeof ( message_t )); }
    {char * tlv9; tlv9 = (char *)(sizeof ( message_t )); }
}
void fix_ingred_bbs_13_10(){
fix_ingred_bbs_13_10_0();
}
void fix_ingred_bbs_13_12_0(){
message_t m_ref;
    bzero(&m_ref,1*sizeof(message_t));
message_t * m = &m_ref;
    {char * tlv3; tlv3 = (char *)(m -> topic); }
    {cgc_size_t tlv1; tlv1 = (cgc_size_t)(m -> topic); }
    {cgc_size_t tlv5; tlv5 = (cgc_size_t)(m -> topic); }
    {cgc_size_t tlv10; tlv10 = (cgc_size_t)(m -> topic); }
    {char * tlv7; tlv7 = (char *)(m -> topic); }
    {char * tlv9; tlv9 = (char *)(m -> topic); }
}
void fix_ingred_bbs_13_12(){
fix_ingred_bbs_13_12_0();
}
void fix_ingred_bbs_13(){
fix_ingred_bbs_13_7();
fix_ingred_bbs_13_9();
fix_ingred_bbs_13_10();
fix_ingred_bbs_13_12();
}
void fix_ingred_bbs_14_1_0(){
char str_ref;
    bzero(&str_ref,1*sizeof(char));
const char * str = &str_ref;
    {int tlv1; tlv1 = (int)(str [ 0 ]); }
    {int tlv3; tlv3 = (int)(str [ 0 ]); }
    {int tlv2; tlv2 = (int)(str [ 0 ]); }
    {int tlv4; tlv4 = (int)(str [ 0 ]); }
}
void fix_ingred_bbs_14_1(){
fix_ingred_bbs_14_1_0();
}
void fix_ingred_bbs_14_2_1(){
int tlv1;
    bzero(&tlv1,sizeof(int));
    {int tlv3; tlv3 = (int)(tlv1); }
    {int tlv2; tlv2 = (int)(tlv1); }
    {int tlv4; tlv4 = (int)(tlv1); }
}
void fix_ingred_bbs_14_2_2(){
int tlv1;
    bzero(&tlv1,sizeof(int));
    {int tlv1; tlv1 = (int)('q'); }
    {int tlv3; tlv3 = (int)('q'); }
    {int tlv2; tlv2 = (int)('q'); }
    {int tlv4; tlv4 = (int)('q'); }
}
void fix_ingred_bbs_14_2(){
fix_ingred_bbs_14_2_1();
fix_ingred_bbs_14_2_2();
}
void fix_ingred_bbs_14_5_0(){
int tlv2;
    bzero(&tlv2,sizeof(int));
    {int tlv1; tlv1 = (int)(tlv2); }
    {int tlv3; tlv3 = (int)(tlv2); }
    {int tlv4; tlv4 = (int)(tlv2); }
}
void fix_ingred_bbs_14_5_1(){
int tlv2;
    bzero(&tlv2,sizeof(int));
    {int tlv1; tlv1 = (int)('n'); }
    {int tlv3; tlv3 = (int)('n'); }
    {int tlv2; tlv2 = (int)('n'); }
    {int tlv4; tlv4 = (int)('n'); }
}
void fix_ingred_bbs_14_5(){
fix_ingred_bbs_14_5_0();
fix_ingred_bbs_14_5_1();
}
void fix_ingred_bbs_14(){
fix_ingred_bbs_14_1();
fix_ingred_bbs_14_2();
fix_ingred_bbs_14_5();
}
void fix_ingred_bbs_15_0_0(){
char str_ref;
    bzero(&str_ref,1*sizeof(char));
const char * str = &str_ref;
    {int cmd; cmd = (int)(str [ 0 ]); }
}
void fix_ingred_bbs_15_0(){
fix_ingred_bbs_15_0_0();
}
void fix_ingred_bbs_15_1_0(){
    {int cmd; cmd = (int)(0); }
}
void fix_ingred_bbs_15_1(){
fix_ingred_bbs_15_1_0();
}
void fix_ingred_bbs_15(){
fix_ingred_bbs_15_0();
fix_ingred_bbs_15_1();
}
void fix_ingred_bbs_16_1_0(){
char str [ 101 ];
    bzero(&str,( 101 *sizeof(char) ) );
uint8_t data_ref;
    bzero(&data_ref,1*sizeof(uint8_t));
const uint8_t * data = &data_ref;
cgc_size_t count;
    bzero(&count,sizeof(cgc_size_t));
    {char str [ 101 ]; str [ ( 101 )-1 ] = (char)(str); }
    {cgc_size_t tlv1; tlv1 = (cgc_size_t)(str); }
    {void * tlv4; tlv4 = (void *)(str); }
    {void * tlv3; tlv3 = (void *)(str); }
    {cgc_size_t tlv2; tlv2 = (cgc_size_t)(str); }
}
void fix_ingred_bbs_16_1_1(){
char str [ 101 ];
    bzero(&str,( 101 *sizeof(char) ) );
uint8_t data_ref;
    bzero(&data_ref,1*sizeof(uint8_t));
const uint8_t * data = &data_ref;
cgc_size_t count;
    bzero(&count,sizeof(cgc_size_t));
    {char str [ 101 ]; str [ ( 101 )-1 ] = (char)(data); }
    {cgc_size_t tlv1; tlv1 = (cgc_size_t)(data); }
    {void * tlv4; tlv4 = (void *)(data); }
    {void * tlv3; tlv3 = (void *)(data); }
    {cgc_size_t tlv2; tlv2 = (cgc_size_t)(data); }
}
void fix_ingred_bbs_16_1_2(){
char str [ 101 ];
    bzero(&str,( 101 *sizeof(char) ) );
uint8_t data_ref;
    bzero(&data_ref,1*sizeof(uint8_t));
const uint8_t * data = &data_ref;
cgc_size_t count;
    bzero(&count,sizeof(cgc_size_t));
    {char str [ 101 ]; str [ ( 101 )-1 ] = (char)(count); }
    {cgc_size_t tlv1; tlv1 = (cgc_size_t)(count); }
    {void * tlv4; tlv4 = (void *)(count); }
    {void * tlv3; tlv3 = (void *)(count); }
    {cgc_size_t tlv2; tlv2 = (cgc_size_t)(count); }
}
void fix_ingred_bbs_16_1(){
fix_ingred_bbs_16_1_0();
fix_ingred_bbs_16_1_1();
fix_ingred_bbs_16_1_2();
}
void fix_ingred_bbs_16_2_0(){
char tlv5_ref;
    bzero(&tlv5_ref,1*sizeof(char));
const char * tlv5 = &tlv5_ref;
    {char str [ 101 ]; str [ ( 101 )-1 ] = (char)(cgc_strlen ( tlv5 )); }
    {cgc_size_t tlv1; tlv1 = (cgc_size_t)(cgc_strlen ( tlv5 )); }
    {void * tlv4; tlv4 = (void *)(cgc_strlen ( tlv5 )); }
    {void * tlv3; tlv3 = (void *)(cgc_strlen ( tlv5 )); }
    {cgc_size_t tlv2; tlv2 = (cgc_size_t)(cgc_strlen ( tlv5 )); }
}
void fix_ingred_bbs_16_2(){
fix_ingred_bbs_16_2_0();
}
void fix_ingred_bbs_16_3_1(){
cgc_size_t tlv1;
    bzero(&tlv1,sizeof(cgc_size_t));
    {char str [ 101 ]; str [ ( 101 )-1 ] = (char)(tlv1); }
    {void * tlv4; tlv4 = (void *)(tlv1); }
    {void * tlv3; tlv3 = (void *)(tlv1); }
    {cgc_size_t tlv2; tlv2 = (cgc_size_t)(tlv1); }
}
void fix_ingred_bbs_16_3_2(){
cgc_size_t tlv1;
    bzero(&tlv1,sizeof(cgc_size_t));
    {char str [ 101 ]; str [ ( 101 )-1 ] = (char)(0); }
    {cgc_size_t tlv1; tlv1 = (cgc_size_t)(0); }
    {void * tlv4; tlv4 = (void *)(0); }
    {void * tlv3; tlv3 = (void *)(0); }
    {cgc_size_t tlv2; tlv2 = (cgc_size_t)(0); }
}
void fix_ingred_bbs_16_3(){
fix_ingred_bbs_16_3_1();
fix_ingred_bbs_16_3_2();
}
void fix_ingred_bbs_16(){
fix_ingred_bbs_16_1();
fix_ingred_bbs_16_2();
fix_ingred_bbs_16_3();
}
void fix_ingred_bbs_17(){
}
