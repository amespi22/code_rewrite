

#include "cgc_stdlib.h"
#include "cgc_string.h"
#include "cgc_form.h"
#include "cgc_input.h"
extern page_t education;
static const char *cmd_lbls[NUM_CMDS] = {
    "NEXT",
    "PREV",
    "UPDATE",
    "HELP",
    "EXIT"
};

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

void fix_ingred_form_0_0_0();
void fix_ingred_form_0_0();
void fix_ingred_form_0_1_1();
void fix_ingred_form_0_1_2();
void fix_ingred_form_0_1_3();
void fix_ingred_form_0_1_4();
void fix_ingred_form_0_1();
void fix_ingred_form_0_2_1();
void fix_ingred_form_0_2_2();
void fix_ingred_form_0_2_3();
void fix_ingred_form_0_2();
void fix_ingred_form_0_3_0();
void fix_ingred_form_0_3_1();
void fix_ingred_form_0_3();
void fix_ingred_form_0_4_0();
void fix_ingred_form_0_4();
void fix_ingred_form_0_7_0();
void fix_ingred_form_0_7();
void fix_ingred_form_0_8_4();
void fix_ingred_form_0_8();
void fix_ingred_form_0();
static int cgc_handler_index(form_t * form, char *buf)
{
if (fix_ingred_enable){ fix_ingred_form_0(); };
    int i;
    char* p;
     p = buf;
    char cmd_buf[MAX_CMD_SIZE];
    while (*p == '*' && p - buf < 2)
    {
	p++;
    }
    for (i = 0; i < NUM_CMDS; i++) {
 {
     void* tlv4;
     tlv4 = cmd_buf;
     void* tlv3;
     tlv3 = p;
     cgc_size_t tlv2;
     {
         const char* tlv9 = cmd_lbls [ i ];
         tlv2 = cgc_strlen(tlv9);
     }
    	cgc_memcpy(tlv4,tlv3,tlv2);
 }
 {
     const char* tlv8 = cmd_lbls [ i ];
    	cmd_buf[cgc_strlen(tlv8)] = '\0';
 }
 int tlv1;
 {
     const char* tlv7 = cmd_buf;
     const char* tlv6 = cmd_lbls [ i ];
     cgc_size_t tlv5;
     {
         const char* tlv10 = cmd_lbls [ i ];
         tlv5 = cgc_strlen(tlv10);
     }
     tlv1 = cgc_strncasecmp(tlv7,tlv6,tlv5);
 }
	if (tlv1 == 0) {
	    return i;
	}
    }
    return -1;
}

void fix_ingred_form_1_1_0();
void fix_ingred_form_1_1();
void fix_ingred_form_1();
static int cgc_is_cmd(form_t * form, char *buf)
{
if (fix_ingred_enable){ fix_ingred_form_1(); };
    int tlv1;
    {
        const char tlv4 [ ] = "**";
        const char* tlv3 = buf;
        cgc_size_t tlv2;
        tlv2 = 2;
        tlv1 = cgc_strncmp(tlv4,tlv3,tlv2);
    }
    if (tlv1) {
	return 0;
    }
    return cgc_handler_index(form, buf) >= 0;
}

void fix_ingred_form_2_0_1();
void fix_ingred_form_2_0();
void fix_ingred_form_2_2_0();
void fix_ingred_form_2_2();
void fix_ingred_form_2();
static int page_complete(form_t * form)
{
if (fix_ingred_enable){ fix_ingred_form_2(); };
    question_t* cur;
    cur = form -> cur_page -> questions;
    int completed;
    completed = 1;
    while (cur != NULL)
    {
	if (!cur->optional && cur->answer == NULL) {
	    completed = 0;
	    break;
	} else {
	    cur = cur->next;
	}
    }
    return completed && form->cur_question == NULL;
}

void fix_ingred_form_3_1_0();
void fix_ingred_form_3_1();
void fix_ingred_form_3();
static void cgc_print_title(form_t * form)
{
if (fix_ingred_enable){ fix_ingred_form_3(); };
    int tlv1;
    {
        const char* tlv4 = form -> cur_page -> title;
        const char tlv3 [ ] = "Fin";
        cgc_size_t tlv2;
        tlv2 = 3;
        tlv1 = cgc_strncmp(tlv4,tlv3,tlv2);
    }
    if (tlv1 == 0) {
	cgc_printf("\nFinal Questions\n");
    } else {
	cgc_printf("\n%s Form\n", form->cur_page->title);
    }
}

void fix_ingred_form_4_2_0();
void fix_ingred_form_4_2();
void fix_ingred_form_4_3_0();
void fix_ingred_form_4_3_1();
void fix_ingred_form_4_3();
void fix_ingred_form_4_7_1();
void fix_ingred_form_4_7();
void fix_ingred_form_4_8_0();
void fix_ingred_form_4_8_2();
void fix_ingred_form_4_8();
void fix_ingred_form_4();
static int cgc_handle_cmd(form_t * form, char *buf)
{
if (fix_ingred_enable){ fix_ingred_form_4(); };
    char* arg;
     {
         cgc_size_t tlv3;
         {
             const char* tlv9 = buf;
             tlv3 = cgc_strlen(tlv9) + 1;
         }
         arg = cgc_malloc(tlv3);
     }
    int ret;
    if (arg == NULL) {
	return -1;
    }
    {
        char* tlv2;
         tlv2 = arg;
        const char* tlv1 = buf;
        cgc_strcpy(tlv2,tlv1);
    }
    {
        const char* tlv8 = buf;
        arg[cgc_strlen(tlv8)] = '\0';
    }
    char* cmd;
     {
         char** tlv5;
          tlv5 = & arg;
         const char tlv4 [ ] = " ";
         cmd = cgc_strsep(tlv5,tlv4);
     }
    int i;
    {
        form_t* tlv7;
        tlv7 = form;
        char* tlv6;
         tlv6 = cmd;
        i = cgc_handler_index(tlv7,tlv6);
    }
    if (i < 0) {
	ret = i;
	goto out;
    }
    ret = form->handlers[i] (form, arg);
  out:
    if (cmd != NULL) {
	cgc_free(cmd);
    }
    return ret;
}

void fix_ingred_form_5_5_0();
void fix_ingred_form_5_5();
void fix_ingred_form_5();
static int cgc_handle_answer(form_t * form, char *input)
{
if (fix_ingred_enable){ fix_ingred_form_5(); };
    if (!form->cur_question->validator(input)) {
	return 1;
    }
    if (form->cur_question->answer != NULL) {
 {
     void* tlv4;
     tlv4 = form -> cur_question -> answer;
    	cgc_free(tlv4);
 }
    }
    {
        cgc_size_t tlv3;
        {
            const char* tlv5 = input;
            tlv3 = cgc_strlen(tlv5) + 1;
        }
        form->cur_question->answer = cgc_malloc(tlv3);
    }
    if (form->cur_question->answer == NULL) {
	return -1;
    }
    {
        char* tlv2;
         tlv2 = form -> cur_question -> answer;
        const char* tlv1 = input;
        cgc_strcpy(tlv2,tlv1);
    }
    return 0;
}

void fix_ingred_form_6();
static int cgc_next_question(form_t * form)
{
if (fix_ingred_enable){ fix_ingred_form_6(); };
    if (form->cur_question == NULL) {
	return -1;
    }
    if (form->cur_question->next == NULL) {
	form->cur_page->completed = 1;
    } else {
	form->cur_question = form->cur_question->next;
    }
    return 0;
}

void fix_ingred_form_7_1_0();
void fix_ingred_form_7_1();
void fix_ingred_form_7_2_1();
void fix_ingred_form_7_2_2();
void fix_ingred_form_7_2();
void fix_ingred_form_7_5_1();
void fix_ingred_form_7_5();
void fix_ingred_form_7_8_1();
void fix_ingred_form_7_8();
void fix_ingred_form_7();
static void cgc_print_page(form_t * form)
{
if (fix_ingred_enable){ fix_ingred_form_7(); };
    question_t* cur;
    cur = form -> cur_page -> questions;
    int tlv1;
    {
        const char* tlv6 = form -> cur_page -> title;
        const char tlv5 [ ] = "Edu";
        cgc_size_t tlv4;
        tlv4 = 3;
        tlv1 = cgc_strncmp(tlv6,tlv5,tlv4);
    }
    if (tlv1 == 0) {
	cgc_printf("\n*********Highest %s:*********\n", form->cur_page->title);
    } else {
 int tlv2;
 {
     const char* tlv9 = form -> cur_page -> title;
     const char tlv8 [ ] = "Emp";
     cgc_size_t tlv7;
     tlv7 = 3;
     tlv2 = cgc_strncmp(tlv9,tlv8,tlv7);
 }
	if (tlv2 == 0) {
	    cgc_printf("\n*********Most Recent Employer:*********\n", form->cur_page->title);
	} else {
     int tlv3;
     {
         const char* tlv12 = form -> cur_page -> title;
         const char tlv11 [ ] = "Fin";
         cgc_size_t tlv10;
         tlv10 = 3;
         tlv3 = cgc_strncmp(tlv12,tlv11,tlv10);
     }
	    if (tlv3 == 0) {
		cgc_printf("\n*********Final Screening:*********\n", form->cur_page->title);
	    } else {
		cgc_printf("\n*********%s:*********\n", form->cur_page->title);
	    }
	}
    }
    for (; cur != NULL; cur = cur->next)
    {
	if (cur->answer != NULL) {
	    cgc_printf("%s=%s\n", cur->title, cur->answer);
	} else {
	    cgc_printf("%s=\n", cur->title);
	}
    }
}

void fix_ingred_form_8();
static void cgc_prompt_next(void)
{
if (fix_ingred_enable){ fix_ingred_form_8(); };
    cgc_printf("\nType **next to continue\n");
}

void fix_ingred_form_9();
static int cgc_next_page(form_t * form)
{
if (fix_ingred_enable){ fix_ingred_form_9(); };
    if (form->cur_page == NULL) {
	return -1;
    }
    if (form->cur_page->next == NULL) {
	return 1;
    }
    form->cur_page = form->cur_page->next;
    form->cur_question = form->cur_page->questions;
    return 0;
}

void fix_ingred_form_10();
static void cgc_print_next_title(form_t * form)
{
if (fix_ingred_enable){ fix_ingred_form_10(); };
    if (form->cur_page->next->title == NULL) {
	cgc_printf("%s", form->ending);
    } else {
 int tlv1;
 {
     const char* tlv4 = form -> cur_page -> next -> title;
     const char tlv3 [ ] = "Fin";
     cgc_size_t tlv2;
     tlv2 = 3;
     tlv1 = cgc_strncmp(tlv4,tlv3,tlv2);
 }
	if (tlv1 == 0) {
	    cgc_printf("\nFinal Questions\n");
	} else {
	    cgc_printf("\n%s Form\n", form->cur_page->next->title);
	}
    }
}

void fix_ingred_form_11();
static void cgc_prompt_q(question_t * q)
{
if (fix_ingred_enable){ fix_ingred_form_11(); };
    if (q->hint != NULL) {
	cgc_printf("%s%s: ", q->title, q->hint);
    } else {
	cgc_printf("%s: ", q->title);
    }
}

void fix_ingred_form_12();
int cgc_handle_next(form_t * form, char *arg)
{
if (fix_ingred_enable){ fix_ingred_form_12(); };
    int ret;
    if (form->cur_page->title == NULL) {
	return 1;
    }
    if (!form->cur_page->completed) {
	cgc_print_next_title(form);
	cgc_printf("You must complete the previous page before proceeding to this page\n");
	return 1;
    }
    {
        form_t* tlv1;
        tlv1 = form;
        ret = cgc_next_page(tlv1);
    }
    if (ret < 0) {
	return -1;
    }
    if (ret != 0) {
	return 2;
    }
    while (form->cur_question != NULL && form->cur_question->next != NULL && form->cur_question->answer != NULL)
    {
	form->cur_question = form->cur_question->next;
    }
    return 1;
}

void fix_ingred_form_13();
int cgc_handle_exit(form_t * form, char *arg)
{
if (fix_ingred_enable){ fix_ingred_form_13(); };
    cgc_printf("Thank you!\n");
    cgc_exit(0);
    return 0;
}

void fix_ingred_form_14();
int cgc_handle_help(form_t * form, char *arg)
{
if (fix_ingred_enable){ fix_ingred_form_14(); };
    cgc_printf("%s", form->help);
    return 1;
}

void fix_ingred_form_15();
int cgc_handle_prev(form_t * form, char *arg)
{
if (fix_ingred_enable){ fix_ingred_form_15(); };
    if (form->cur_page == NULL) {
	return -1;
    }
    if (form->cur_page->prev == NULL) {
	cgc_print_title(form);
	return 0;
    }
    form->cur_page = form->cur_page->prev;
    form->cur_question = form->cur_page->questions;
    return 1;
}

void fix_ingred_form_16_2_0();
void fix_ingred_form_16_2_1();
void fix_ingred_form_16_2();
void fix_ingred_form_16_5_0();
void fix_ingred_form_16_5();
void fix_ingred_form_16_6_4();
void fix_ingred_form_16_6_5();
void fix_ingred_form_16_6();
void fix_ingred_form_16_8_0();
void fix_ingred_form_16_8();
void fix_ingred_form_16_9_1();
void fix_ingred_form_16_9();
void fix_ingred_form_16_11_1();
void fix_ingred_form_16_11();
void fix_ingred_form_16_15_0();
void fix_ingred_form_16_15();
void fix_ingred_form_16_21_0();
void fix_ingred_form_16_21();
void fix_ingred_form_16_22_1();
void fix_ingred_form_16_22();
void fix_ingred_form_16_23_0();
void fix_ingred_form_16_23();
void fix_ingred_form_16();
int cgc_handle_update(form_t * form, char *arg)
{
if (fix_ingred_enable){ fix_ingred_form_16(); };
    question_t *cur;
    char *input_buf;
    if (!form->cur_page->completed) {
	cgc_printf("Cannot update field until all fields are inputted\n");
	return 1;
    }
    if (arg == NULL) {
	return 1;
    }
    cur = form->cur_page->questions;
    for (; cur != NULL; cur = cur->next)
    {
 int tlv2;
 {
     const char* tlv8 = cur -> title;
     const char* tlv7 = arg;
     cgc_size_t tlv6;
     {
         const char* tlv16 = cur -> title;
         tlv6 = cgc_strlen(tlv16);
     }
     tlv2 = cgc_strncmp(tlv8,tlv7,tlv6);
 }
	if (tlv2 == 0) {
	    break;
	}
    }
    if (cur == NULL) {
	cgc_printf("Could not find specified field\n");
	cgc_printf("Update Unsuccessful\n");
	return 1;
    }
    {
        cgc_size_t tlv4;
        tlv4 = LINE_SIZE;
        input_buf = cgc_malloc(tlv4);
    }
    if (input_buf == NULL) {
	return -1;
    }
    cgc_prompt_q(cur);
    int tlv1;
    {
        char* tlv5;
         tlv5 = input_buf;
        tlv1 = cgc_read_line(tlv5);
    }
    if (tlv1 < 0) {
	return -1;
    }
    if ((cgc_strlen(input_buf) == 0) && cur->optional) {
	if (input_buf != NULL) {
	    cgc_free(input_buf);
	}
	if (cur->answer != NULL) {
     {
         void* tlv12;
         tlv12 = cur -> answer;
    	    cgc_free(tlv12);
     }
	}
	cur->answer = NULL;
	return 1;
    }
    if (!cur->validator(input_buf)) {
	if (input_buf != NULL) {
	    cgc_free(input_buf);
	}
	cgc_printf("Bad input.\n");
	cgc_printf("Update Unsuccessful\n");
	return 1;
    }
    if (cur->answer == NULL) {
	cur->answer = input_buf;
    } else {
 int tlv3;
 {
     const char* tlv11 = cur -> answer;
     const char* tlv10 = input_buf;
     cgc_size_t tlv9;
     {
         const char* tlv17 = cur -> answer;
         tlv9 = cgc_strlen(tlv17);
     }
     tlv3 = cgc_strncmp(tlv11,tlv10,tlv9);
 }
	if (tlv3 == 0) {
     {
         char* tlv14;
          tlv14 = cur -> answer;
         const char* tlv13 = input_buf;
    	    cgc_strcpy(tlv14,tlv13);
     }
	    cgc_free(input_buf);
	} else {
     {
         void* tlv15;
         tlv15 = cur -> answer;
    	    cgc_free(tlv15);
     }
	    cur->answer = input_buf;
	}
    }
    return 1;
}

void fix_ingred_form_17();
void cgc_print_prompt(form_t * form, int with_title, int done)
{
if (fix_ingred_enable){ fix_ingred_form_17(); };
    if (form->cur_page->title == NULL) {
	cgc_printf("%s", form->ending);
	return;
    }
    if (with_title) {
	cgc_print_title(form);
    }
    if (form->cur_page->completed) {
	cgc_print_page(form);
	cgc_prompt_next();
	return;
    }
    {
        question_t* tlv1;
        tlv1 = form -> cur_question;
        cgc_prompt_q(tlv1);
    }
}

void fix_ingred_form_18_1_1();
void fix_ingred_form_18_1();
void fix_ingred_form_18_4_0();
void fix_ingred_form_18_4();
void fix_ingred_form_18_5_0();
void fix_ingred_form_18_5_1();
void fix_ingred_form_18_5();
void fix_ingred_form_18_9_0();
void fix_ingred_form_18_9_1();
void fix_ingred_form_18_9();
void fix_ingred_form_18();
int cgc_handle_line(form_t * form, char *buf)
{
if (fix_ingred_enable){ fix_ingred_form_18(); };
    int ret;
    static int tlv1;
    {
        form_t* tlv4;
        tlv4 = form;
        char* tlv3;
         tlv3 = buf;
        tlv1 = cgc_is_cmd(tlv4,tlv3);
    }
    if (tlv1) {
	return cgc_handle_cmd(form, buf);
    }
    if (form->cur_page->completed || form->cur_question == NULL) {
	return 1;
    }
    cgc_size_t tlv2;
    {
        const char* tlv5 = buf;
        tlv2 = cgc_strlen(tlv5);
    }
    if (tlv2 == 0) {
	if (!form->cur_question->optional) {
	    return 0;
	}
    } else {
 {
     form_t* tlv8;
     tlv8 = form;
     char* tlv7;
      tlv7 = buf;
    	ret = cgc_handle_answer(tlv8,tlv7);
 }
	if (ret < 0) {
	    return -1;
	}
	if (ret != 0) {
	    return 0;
	}
    }
    {
        form_t* tlv6;
        tlv6 = form;
        ret = cgc_next_question(tlv6);
    }
    if (ret < 0) {
	return -1;
    } else {
	return 0;
    }
}

void fix_ingred_form_19();
void cgc_print_greeting(form_t * form)
{
if (fix_ingred_enable){ fix_ingred_form_19(); };
    cgc_printf("%s", form->greeting);
}

void fix_ingred_form_0_0_0(){
char buf_ref;
    bzero(&buf_ref,1*sizeof(char));
char * buf = &buf_ref;
    {int i; i = (int)(buf); }
    {char * p; p = (char *)(buf); }
    {char cmd_buf [ MAX_CMD_SIZE ]; cmd_buf [ ( MAX_CMD_SIZE )-1 ] = (char)(buf); }
    {int tlv1; tlv1 = (int)(buf); }
    {void * tlv4; tlv4 = (void *)(buf); }
    {void * tlv3; tlv3 = (void *)(buf); }
    {cgc_size_t tlv2; tlv2 = (cgc_size_t)(buf); }
    {cgc_size_t tlv5; tlv5 = (cgc_size_t)(buf); }
}
void fix_ingred_form_0_0(){
fix_ingred_form_0_0_0();
}
void fix_ingred_form_0_1_1(){
char p_ref;
    bzero(&p_ref,1*sizeof(char));
char * p = &p_ref;
char buf_ref;
    bzero(&buf_ref,1*sizeof(char));
char * buf = &buf_ref;
    {int i; i = (int)(* p); }
    {char cmd_buf [ MAX_CMD_SIZE ]; cmd_buf [ ( MAX_CMD_SIZE )-1 ] = (char)(* p); }
    {int tlv1; tlv1 = (int)(* p); }
    {void * tlv4; tlv4 = (void *)(* p); }
    {void * tlv3; tlv3 = (void *)(* p); }
    {cgc_size_t tlv2; tlv2 = (cgc_size_t)(* p); }
    {cgc_size_t tlv5; tlv5 = (cgc_size_t)(* p); }
}
void fix_ingred_form_0_1_2(){
char p_ref;
    bzero(&p_ref,1*sizeof(char));
char * p = &p_ref;
char buf_ref;
    bzero(&buf_ref,1*sizeof(char));
char * buf = &buf_ref;
    {int i; i = (int)('*'); }
    {char * p; p = (char *)('*'); }
    {char cmd_buf [ MAX_CMD_SIZE ]; cmd_buf [ ( MAX_CMD_SIZE )-1 ] = (char)('*'); }
    {int tlv1; tlv1 = (int)('*'); }
    {void * tlv4; tlv4 = (void *)('*'); }
    {void * tlv3; tlv3 = (void *)('*'); }
    {cgc_size_t tlv2; tlv2 = (cgc_size_t)('*'); }
    {cgc_size_t tlv5; tlv5 = (cgc_size_t)('*'); }
}
void fix_ingred_form_0_1_3(){
char p_ref;
    bzero(&p_ref,1*sizeof(char));
char * p = &p_ref;
char buf_ref;
    bzero(&buf_ref,1*sizeof(char));
char * buf = &buf_ref;
    {int i; i = (int)(p - buf); }
    {char cmd_buf [ MAX_CMD_SIZE ]; cmd_buf [ ( MAX_CMD_SIZE )-1 ] = (char)(p - buf); }
    {int tlv1; tlv1 = (int)(p - buf); }
    {void * tlv4; tlv4 = (void *)(p - buf); }
    {void * tlv3; tlv3 = (void *)(p - buf); }
    {cgc_size_t tlv2; tlv2 = (cgc_size_t)(p - buf); }
    {cgc_size_t tlv5; tlv5 = (cgc_size_t)(p - buf); }
}
void fix_ingred_form_0_1_4(){
char p_ref;
    bzero(&p_ref,1*sizeof(char));
char * p = &p_ref;
char buf_ref;
    bzero(&buf_ref,1*sizeof(char));
char * buf = &buf_ref;
    {int i; i = (int)(2); }
    {char * p; p = (char *)(2); }
    {char cmd_buf [ MAX_CMD_SIZE ]; cmd_buf [ ( MAX_CMD_SIZE )-1 ] = (char)(2); }
    {int tlv1; tlv1 = (int)(2); }
    {void * tlv4; tlv4 = (void *)(2); }
    {void * tlv3; tlv3 = (void *)(2); }
    {cgc_size_t tlv2; tlv2 = (cgc_size_t)(2); }
    {cgc_size_t tlv5; tlv5 = (cgc_size_t)(2); }
}
void fix_ingred_form_0_1(){
fix_ingred_form_0_1_1();
fix_ingred_form_0_1_2();
fix_ingred_form_0_1_3();
fix_ingred_form_0_1_4();
}
void fix_ingred_form_0_2_1(){
int i;
    bzero(&i,sizeof(int));
    {int i; i = (int)(0); }
    {char * p; p = (char *)(0); }
    {char cmd_buf [ MAX_CMD_SIZE ]; cmd_buf [ ( MAX_CMD_SIZE )-1 ] = (char)(0); }
    {int tlv1; tlv1 = (int)(0); }
    {void * tlv4; tlv4 = (void *)(0); }
    {void * tlv3; tlv3 = (void *)(0); }
    {cgc_size_t tlv2; tlv2 = (cgc_size_t)(0); }
    {cgc_size_t tlv5; tlv5 = (cgc_size_t)(0); }
}
void fix_ingred_form_0_2_2(){
int i;
    bzero(&i,sizeof(int));
    {char * p; p = (char *)(i); }
    {char cmd_buf [ MAX_CMD_SIZE ]; cmd_buf [ ( MAX_CMD_SIZE )-1 ] = (char)(i); }
    {int tlv1; tlv1 = (int)(i); }
    {void * tlv4; tlv4 = (void *)(i); }
    {void * tlv3; tlv3 = (void *)(i); }
    {cgc_size_t tlv2; tlv2 = (cgc_size_t)(i); }
    {cgc_size_t tlv5; tlv5 = (cgc_size_t)(i); }
}
void fix_ingred_form_0_2_3(){
int i;
    bzero(&i,sizeof(int));
    {int i; i = (int)(NUM_CMDS); }
    {char * p; p = (char *)(NUM_CMDS); }
    {char cmd_buf [ MAX_CMD_SIZE ]; cmd_buf [ ( MAX_CMD_SIZE )-1 ] = (char)(NUM_CMDS); }
    {int tlv1; tlv1 = (int)(NUM_CMDS); }
    {void * tlv4; tlv4 = (void *)(NUM_CMDS); }
    {void * tlv3; tlv3 = (void *)(NUM_CMDS); }
    {cgc_size_t tlv2; tlv2 = (cgc_size_t)(NUM_CMDS); }
    {cgc_size_t tlv5; tlv5 = (cgc_size_t)(NUM_CMDS); }
}
void fix_ingred_form_0_2(){
fix_ingred_form_0_2_1();
fix_ingred_form_0_2_2();
fix_ingred_form_0_2_3();
}
void fix_ingred_form_0_3_0(){
char cmd_buf [ MAX_CMD_SIZE ];
    bzero(&cmd_buf,( MAX_CMD_SIZE *sizeof(char) ) );
char p_ref;
    bzero(&p_ref,1*sizeof(char));
char * p = &p_ref;
    {int i; i = (int)(cmd_buf); }
    {char * p; p = (char *)(cmd_buf); }
    {char cmd_buf [ MAX_CMD_SIZE ]; cmd_buf [ ( MAX_CMD_SIZE )-1 ] = (char)(cmd_buf); }
    {int tlv1; tlv1 = (int)(cmd_buf); }
    {void * tlv4; tlv4 = (void *)(cmd_buf); }
    {void * tlv3; tlv3 = (void *)(cmd_buf); }
    {cgc_size_t tlv2; tlv2 = (cgc_size_t)(cmd_buf); }
    {cgc_size_t tlv5; tlv5 = (cgc_size_t)(cmd_buf); }
}
void fix_ingred_form_0_3_1(){
char cmd_buf [ MAX_CMD_SIZE ];
    bzero(&cmd_buf,( MAX_CMD_SIZE *sizeof(char) ) );
char p_ref;
    bzero(&p_ref,1*sizeof(char));
char * p = &p_ref;
    {int i; i = (int)(p); }
    {char cmd_buf [ MAX_CMD_SIZE ]; cmd_buf [ ( MAX_CMD_SIZE )-1 ] = (char)(p); }
    {int tlv1; tlv1 = (int)(p); }
    {void * tlv4; tlv4 = (void *)(p); }
    {void * tlv3; tlv3 = (void *)(p); }
    {cgc_size_t tlv2; tlv2 = (cgc_size_t)(p); }
    {cgc_size_t tlv5; tlv5 = (cgc_size_t)(p); }
}
void fix_ingred_form_0_3(){
fix_ingred_form_0_3_0();
fix_ingred_form_0_3_1();
}
void fix_ingred_form_0_4_0(){
char tlv9_ref;
    bzero(&tlv9_ref,1*sizeof(char));
const char * tlv9 = &tlv9_ref;
    {int i; i = (int)(cgc_strlen ( tlv9 )); }
    {char * p; p = (char *)(cgc_strlen ( tlv9 )); }
    {char cmd_buf [ MAX_CMD_SIZE ]; cmd_buf [ ( MAX_CMD_SIZE )-1 ] = (char)(cgc_strlen ( tlv9 )); }
    {int tlv1; tlv1 = (int)(cgc_strlen ( tlv9 )); }
    {void * tlv4; tlv4 = (void *)(cgc_strlen ( tlv9 )); }
    {void * tlv3; tlv3 = (void *)(cgc_strlen ( tlv9 )); }
    {cgc_size_t tlv2; tlv2 = (cgc_size_t)(cgc_strlen ( tlv9 )); }
    {cgc_size_t tlv5; tlv5 = (cgc_size_t)(cgc_strlen ( tlv9 )); }
}
void fix_ingred_form_0_4(){
fix_ingred_form_0_4_0();
}
void fix_ingred_form_0_7_0(){
char tlv10_ref;
    bzero(&tlv10_ref,1*sizeof(char));
const char * tlv10 = &tlv10_ref;
    {int i; i = (int)(cgc_strlen ( tlv10 )); }
    {char * p; p = (char *)(cgc_strlen ( tlv10 )); }
    {char cmd_buf [ MAX_CMD_SIZE ]; cmd_buf [ ( MAX_CMD_SIZE )-1 ] = (char)(cgc_strlen ( tlv10 )); }
    {int tlv1; tlv1 = (int)(cgc_strlen ( tlv10 )); }
    {void * tlv4; tlv4 = (void *)(cgc_strlen ( tlv10 )); }
    {void * tlv3; tlv3 = (void *)(cgc_strlen ( tlv10 )); }
    {cgc_size_t tlv2; tlv2 = (cgc_size_t)(cgc_strlen ( tlv10 )); }
    {cgc_size_t tlv5; tlv5 = (cgc_size_t)(cgc_strlen ( tlv10 )); }
}
void fix_ingred_form_0_7(){
fix_ingred_form_0_7_0();
}
void fix_ingred_form_0_8_4(){
int tlv1;
    bzero(&tlv1,sizeof(int));
    {int i; i = (int)(tlv1); }
    {char * p; p = (char *)(tlv1); }
    {char cmd_buf [ MAX_CMD_SIZE ]; cmd_buf [ ( MAX_CMD_SIZE )-1 ] = (char)(tlv1); }
    {void * tlv4; tlv4 = (void *)(tlv1); }
    {void * tlv3; tlv3 = (void *)(tlv1); }
    {cgc_size_t tlv2; tlv2 = (cgc_size_t)(tlv1); }
    {cgc_size_t tlv5; tlv5 = (cgc_size_t)(tlv1); }
}
void fix_ingred_form_0_8(){
fix_ingred_form_0_8_4();
}
void fix_ingred_form_0(){
fix_ingred_form_0_0();
fix_ingred_form_0_1();
fix_ingred_form_0_2();
fix_ingred_form_0_3();
fix_ingred_form_0_4();
fix_ingred_form_0_7();
fix_ingred_form_0_8();
}
void fix_ingred_form_1_1_0(){
    {int tlv1; tlv1 = (int)(2); }
    {cgc_size_t tlv2; tlv2 = (cgc_size_t)(2); }
}
void fix_ingred_form_1_1(){
fix_ingred_form_1_1_0();
}
void fix_ingred_form_1(){
fix_ingred_form_1_1();
}
void fix_ingred_form_2_0_1(){
    {int completed; completed = (int)(1); }
}
void fix_ingred_form_2_0(){
fix_ingred_form_2_0_1();
}
void fix_ingred_form_2_2_0(){
    {int completed; completed = (int)(0); }
}
void fix_ingred_form_2_2(){
fix_ingred_form_2_2_0();
}
void fix_ingred_form_2(){
fix_ingred_form_2_0();
fix_ingred_form_2_2();
}
void fix_ingred_form_3_1_0(){
    {int tlv1; tlv1 = (int)(3); }
    {cgc_size_t tlv2; tlv2 = (cgc_size_t)(3); }
}
void fix_ingred_form_3_1(){
fix_ingred_form_3_1_0();
}
void fix_ingred_form_3(){
fix_ingred_form_3_1();
}
void fix_ingred_form_4_2_0(){
char tlv9_ref;
    bzero(&tlv9_ref,1*sizeof(char));
const char * tlv9 = &tlv9_ref;
    {char * arg; arg = (char *)(cgc_strlen ( tlv9 ) + 1); }
    {int ret; ret = (int)(cgc_strlen ( tlv9 ) + 1); }
    {char * cmd; cmd = (char *)(cgc_strlen ( tlv9 ) + 1); }
    {int i; i = (int)(cgc_strlen ( tlv9 ) + 1); }
    {cgc_size_t tlv3; tlv3 = (cgc_size_t)(cgc_strlen ( tlv9 ) + 1); }
    {char * tlv2; tlv2 = (char *)(cgc_strlen ( tlv9 ) + 1); }
    {char * tlv6; tlv6 = (char *)(cgc_strlen ( tlv9 ) + 1); }
}
void fix_ingred_form_4_2(){
fix_ingred_form_4_2_0();
}
void fix_ingred_form_4_3_0(){
char arg_ref;
    bzero(&arg_ref,1*sizeof(char));
char * arg = &arg_ref;
    {int ret; ret = (int)(arg); }
    {char * cmd; cmd = (char *)(arg); }
    {int i; i = (int)(arg); }
    {cgc_size_t tlv3; tlv3 = (cgc_size_t)(arg); }
    {char * tlv2; tlv2 = (char *)(arg); }
    {char * tlv6; tlv6 = (char *)(arg); }
}
void fix_ingred_form_4_3_1(){
char arg_ref;
    bzero(&arg_ref,1*sizeof(char));
char * arg = &arg_ref;
    {char * arg; arg = (char *)(NULL); }
    {int ret; ret = (int)(NULL); }
    {char * cmd; cmd = (char *)(NULL); }
    {int i; i = (int)(NULL); }
    {cgc_size_t tlv3; tlv3 = (cgc_size_t)(NULL); }
    {char * tlv2; tlv2 = (char *)(NULL); }
    {char * tlv6; tlv6 = (char *)(NULL); }
}
void fix_ingred_form_4_3(){
fix_ingred_form_4_3_0();
fix_ingred_form_4_3_1();
}
void fix_ingred_form_4_7_1(){
char cmd_ref;
    bzero(&cmd_ref,1*sizeof(char));
char * cmd = &cmd_ref;
    {char * arg; arg = (char *)(cmd); }
    {int ret; ret = (int)(cmd); }
    {int i; i = (int)(cmd); }
    {cgc_size_t tlv3; tlv3 = (cgc_size_t)(cmd); }
    {char * tlv2; tlv2 = (char *)(cmd); }
    {char * tlv6; tlv6 = (char *)(cmd); }
}
void fix_ingred_form_4_7(){
fix_ingred_form_4_7_1();
}
void fix_ingred_form_4_8_0(){
int i;
    bzero(&i,sizeof(int));
    {char * arg; arg = (char *)(i); }
    {int ret; ret = (int)(i); }
    {char * cmd; cmd = (char *)(i); }
    {cgc_size_t tlv3; tlv3 = (cgc_size_t)(i); }
    {char * tlv2; tlv2 = (char *)(i); }
    {char * tlv6; tlv6 = (char *)(i); }
}
void fix_ingred_form_4_8_2(){
int i;
    bzero(&i,sizeof(int));
    {char * arg; arg = (char *)(0); }
    {int ret; ret = (int)(0); }
    {char * cmd; cmd = (char *)(0); }
    {cgc_size_t tlv3; tlv3 = (cgc_size_t)(0); }
    {char * tlv2; tlv2 = (char *)(0); }
    {char * tlv6; tlv6 = (char *)(0); }
}
void fix_ingred_form_4_8(){
fix_ingred_form_4_8_0();
fix_ingred_form_4_8_2();
}
void fix_ingred_form_4(){
fix_ingred_form_4_2();
fix_ingred_form_4_3();
fix_ingred_form_4_7();
fix_ingred_form_4_8();
}
void fix_ingred_form_5_5_0(){
char tlv5_ref;
    bzero(&tlv5_ref,1*sizeof(char));
const char * tlv5 = &tlv5_ref;
    {cgc_size_t tlv3; tlv3 = (cgc_size_t)(cgc_strlen ( tlv5 ) + 1); }
    {char * tlv2; tlv2 = (char *)(cgc_strlen ( tlv5 ) + 1); }
    {void * tlv4; tlv4 = (void *)(cgc_strlen ( tlv5 ) + 1); }
}
void fix_ingred_form_5_5(){
fix_ingred_form_5_5_0();
}
void fix_ingred_form_5(){
fix_ingred_form_5_5();
}
void fix_ingred_form_6(){
}
void fix_ingred_form_7_1_0(){
    {cgc_size_t tlv4; tlv4 = (cgc_size_t)(3); }
    {int tlv2; tlv2 = (int)(3); }
    {cgc_size_t tlv7; tlv7 = (cgc_size_t)(3); }
    {int tlv3; tlv3 = (int)(3); }
    {cgc_size_t tlv10; tlv10 = (cgc_size_t)(3); }
}
void fix_ingred_form_7_1(){
fix_ingred_form_7_1_0();
}
void fix_ingred_form_7_2_1(){
int tlv1;
    bzero(&tlv1,sizeof(int));
    {cgc_size_t tlv4; tlv4 = (cgc_size_t)(tlv1); }
    {int tlv2; tlv2 = (int)(tlv1); }
    {cgc_size_t tlv7; tlv7 = (cgc_size_t)(tlv1); }
    {int tlv3; tlv3 = (int)(tlv1); }
    {cgc_size_t tlv10; tlv10 = (cgc_size_t)(tlv1); }
}
void fix_ingred_form_7_2_2(){
int tlv1;
    bzero(&tlv1,sizeof(int));
    {cgc_size_t tlv4; tlv4 = (cgc_size_t)(0); }
    {int tlv2; tlv2 = (int)(0); }
    {cgc_size_t tlv7; tlv7 = (cgc_size_t)(0); }
    {int tlv3; tlv3 = (int)(0); }
    {cgc_size_t tlv10; tlv10 = (cgc_size_t)(0); }
}
void fix_ingred_form_7_2(){
fix_ingred_form_7_2_1();
fix_ingred_form_7_2_2();
}
void fix_ingred_form_7_5_1(){
int tlv2;
    bzero(&tlv2,sizeof(int));
    {int tlv1; tlv1 = (int)(tlv2); }
    {cgc_size_t tlv4; tlv4 = (cgc_size_t)(tlv2); }
    {cgc_size_t tlv7; tlv7 = (cgc_size_t)(tlv2); }
    {int tlv3; tlv3 = (int)(tlv2); }
    {cgc_size_t tlv10; tlv10 = (cgc_size_t)(tlv2); }
}
void fix_ingred_form_7_5(){
fix_ingred_form_7_5_1();
}
void fix_ingred_form_7_8_1(){
int tlv3;
    bzero(&tlv3,sizeof(int));
    {int tlv1; tlv1 = (int)(tlv3); }
    {cgc_size_t tlv4; tlv4 = (cgc_size_t)(tlv3); }
    {int tlv2; tlv2 = (int)(tlv3); }
    {cgc_size_t tlv7; tlv7 = (cgc_size_t)(tlv3); }
    {cgc_size_t tlv10; tlv10 = (cgc_size_t)(tlv3); }
}
void fix_ingred_form_7_8(){
fix_ingred_form_7_8_1();
}
void fix_ingred_form_7(){
fix_ingred_form_7_1();
fix_ingred_form_7_2();
fix_ingred_form_7_5();
fix_ingred_form_7_8();
}
void fix_ingred_form_8(){
}
void fix_ingred_form_9(){
}
void fix_ingred_form_10(){
}
void fix_ingred_form_11(){
}
void fix_ingred_form_12(){
}
void fix_ingred_form_13(){
}
void fix_ingred_form_14(){
}
void fix_ingred_form_15(){
}
void fix_ingred_form_16_2_0(){
char arg_ref;
    bzero(&arg_ref,1*sizeof(char));
char * arg = &arg_ref;
    {char * input_buf; input_buf = (char *)(arg); }
    {int tlv1; tlv1 = (int)(arg); }
    {cgc_size_t tlv4; tlv4 = (cgc_size_t)(arg); }
    {char * tlv5; tlv5 = (char *)(arg); }
    {int tlv2; tlv2 = (int)(arg); }
    {int tlv3; tlv3 = (int)(arg); }
    {cgc_size_t tlv6; tlv6 = (cgc_size_t)(arg); }
    {cgc_size_t tlv9; tlv9 = (cgc_size_t)(arg); }
    {void * tlv12; tlv12 = (void *)(arg); }
    {char * tlv14; tlv14 = (char *)(arg); }
    {void * tlv15; tlv15 = (void *)(arg); }
}
void fix_ingred_form_16_2_1(){
char arg_ref;
    bzero(&arg_ref,1*sizeof(char));
char * arg = &arg_ref;
    {char * input_buf; input_buf = (char *)(NULL); }
    {int tlv1; tlv1 = (int)(NULL); }
    {cgc_size_t tlv4; tlv4 = (cgc_size_t)(NULL); }
    {char * tlv5; tlv5 = (char *)(NULL); }
    {int tlv2; tlv2 = (int)(NULL); }
    {int tlv3; tlv3 = (int)(NULL); }
    {cgc_size_t tlv6; tlv6 = (cgc_size_t)(NULL); }
    {cgc_size_t tlv9; tlv9 = (cgc_size_t)(NULL); }
    {void * tlv12; tlv12 = (void *)(NULL); }
    {char * tlv14; tlv14 = (char *)(NULL); }
    {void * tlv15; tlv15 = (void *)(NULL); }
}
void fix_ingred_form_16_2(){
fix_ingred_form_16_2_0();
fix_ingred_form_16_2_1();
}
void fix_ingred_form_16_5_0(){
char tlv16_ref;
    bzero(&tlv16_ref,1*sizeof(char));
const char * tlv16 = &tlv16_ref;
    {char * input_buf; input_buf = (char *)(cgc_strlen ( tlv16 )); }
    {int tlv1; tlv1 = (int)(cgc_strlen ( tlv16 )); }
    {cgc_size_t tlv4; tlv4 = (cgc_size_t)(cgc_strlen ( tlv16 )); }
    {char * tlv5; tlv5 = (char *)(cgc_strlen ( tlv16 )); }
    {int tlv2; tlv2 = (int)(cgc_strlen ( tlv16 )); }
    {int tlv3; tlv3 = (int)(cgc_strlen ( tlv16 )); }
    {cgc_size_t tlv6; tlv6 = (cgc_size_t)(cgc_strlen ( tlv16 )); }
    {cgc_size_t tlv9; tlv9 = (cgc_size_t)(cgc_strlen ( tlv16 )); }
    {void * tlv12; tlv12 = (void *)(cgc_strlen ( tlv16 )); }
    {char * tlv14; tlv14 = (char *)(cgc_strlen ( tlv16 )); }
    {void * tlv15; tlv15 = (void *)(cgc_strlen ( tlv16 )); }
}
void fix_ingred_form_16_5(){
fix_ingred_form_16_5_0();
}
void fix_ingred_form_16_6_4(){
int tlv2;
    bzero(&tlv2,sizeof(int));
    {char * input_buf; input_buf = (char *)(tlv2); }
    {char * tlv5; tlv5 = (char *)(tlv2); }
    {cgc_size_t tlv6; tlv6 = (cgc_size_t)(tlv2); }
    {cgc_size_t tlv9; tlv9 = (cgc_size_t)(tlv2); }
    {void * tlv12; tlv12 = (void *)(tlv2); }
    {char * tlv14; tlv14 = (char *)(tlv2); }
    {void * tlv15; tlv15 = (void *)(tlv2); }
}
void fix_ingred_form_16_6_5(){
int tlv2;
    bzero(&tlv2,sizeof(int));
    {char * input_buf; input_buf = (char *)(0); }
    {char * tlv5; tlv5 = (char *)(0); }
    {cgc_size_t tlv6; tlv6 = (cgc_size_t)(0); }
    {cgc_size_t tlv9; tlv9 = (cgc_size_t)(0); }
    {void * tlv12; tlv12 = (void *)(0); }
    {char * tlv14; tlv14 = (char *)(0); }
    {void * tlv15; tlv15 = (void *)(0); }
}
void fix_ingred_form_16_6(){
fix_ingred_form_16_6_4();
fix_ingred_form_16_6_5();
}
void fix_ingred_form_16_8_0(){
    {char * input_buf; input_buf = (char *)(LINE_SIZE); }
    {int tlv1; tlv1 = (int)(LINE_SIZE); }
    {cgc_size_t tlv4; tlv4 = (cgc_size_t)(LINE_SIZE); }
    {char * tlv5; tlv5 = (char *)(LINE_SIZE); }
    {int tlv2; tlv2 = (int)(LINE_SIZE); }
    {int tlv3; tlv3 = (int)(LINE_SIZE); }
    {cgc_size_t tlv6; tlv6 = (cgc_size_t)(LINE_SIZE); }
    {cgc_size_t tlv9; tlv9 = (cgc_size_t)(LINE_SIZE); }
    {void * tlv12; tlv12 = (void *)(LINE_SIZE); }
    {char * tlv14; tlv14 = (char *)(LINE_SIZE); }
    {void * tlv15; tlv15 = (void *)(LINE_SIZE); }
}
void fix_ingred_form_16_8(){
fix_ingred_form_16_8_0();
}
void fix_ingred_form_16_9_1(){
char input_buf_ref;
    bzero(&input_buf_ref,1*sizeof(char));
char * input_buf = &input_buf_ref;
    {int tlv1; tlv1 = (int)(input_buf); }
    {cgc_size_t tlv4; tlv4 = (cgc_size_t)(input_buf); }
    {char * tlv5; tlv5 = (char *)(input_buf); }
    {int tlv2; tlv2 = (int)(input_buf); }
    {int tlv3; tlv3 = (int)(input_buf); }
    {cgc_size_t tlv6; tlv6 = (cgc_size_t)(input_buf); }
    {cgc_size_t tlv9; tlv9 = (cgc_size_t)(input_buf); }
    {void * tlv12; tlv12 = (void *)(input_buf); }
    {char * tlv14; tlv14 = (char *)(input_buf); }
    {void * tlv15; tlv15 = (void *)(input_buf); }
}
void fix_ingred_form_16_9(){
fix_ingred_form_16_9_1();
}
void fix_ingred_form_16_11_1(){
int tlv1;
    bzero(&tlv1,sizeof(int));
    {char * input_buf; input_buf = (char *)(tlv1); }
    {char * tlv5; tlv5 = (char *)(tlv1); }
    {cgc_size_t tlv6; tlv6 = (cgc_size_t)(tlv1); }
    {cgc_size_t tlv9; tlv9 = (cgc_size_t)(tlv1); }
    {void * tlv12; tlv12 = (void *)(tlv1); }
    {char * tlv14; tlv14 = (char *)(tlv1); }
    {void * tlv15; tlv15 = (void *)(tlv1); }
}
void fix_ingred_form_16_11(){
fix_ingred_form_16_11_1();
}
void fix_ingred_form_16_15_0(){
question_t cur_ref;
    bzero(&cur_ref,1*sizeof(question_t));
question_t * cur = &cur_ref;
    {char * input_buf; input_buf = (char *)(cur -> answer); }
    {int tlv1; tlv1 = (int)(cur -> answer); }
    {cgc_size_t tlv4; tlv4 = (cgc_size_t)(cur -> answer); }
    {char * tlv5; tlv5 = (char *)(cur -> answer); }
    {int tlv2; tlv2 = (int)(cur -> answer); }
    {int tlv3; tlv3 = (int)(cur -> answer); }
    {cgc_size_t tlv6; tlv6 = (cgc_size_t)(cur -> answer); }
    {cgc_size_t tlv9; tlv9 = (cgc_size_t)(cur -> answer); }
    {void * tlv12; tlv12 = (void *)(cur -> answer); }
    {char * tlv14; tlv14 = (char *)(cur -> answer); }
    {void * tlv15; tlv15 = (void *)(cur -> answer); }
}
void fix_ingred_form_16_15(){
fix_ingred_form_16_15_0();
}
void fix_ingred_form_16_21_0(){
char tlv17_ref;
    bzero(&tlv17_ref,1*sizeof(char));
const char * tlv17 = &tlv17_ref;
    {char * input_buf; input_buf = (char *)(cgc_strlen ( tlv17 )); }
    {int tlv1; tlv1 = (int)(cgc_strlen ( tlv17 )); }
    {cgc_size_t tlv4; tlv4 = (cgc_size_t)(cgc_strlen ( tlv17 )); }
    {char * tlv5; tlv5 = (char *)(cgc_strlen ( tlv17 )); }
    {int tlv2; tlv2 = (int)(cgc_strlen ( tlv17 )); }
    {int tlv3; tlv3 = (int)(cgc_strlen ( tlv17 )); }
    {cgc_size_t tlv6; tlv6 = (cgc_size_t)(cgc_strlen ( tlv17 )); }
    {cgc_size_t tlv9; tlv9 = (cgc_size_t)(cgc_strlen ( tlv17 )); }
    {void * tlv12; tlv12 = (void *)(cgc_strlen ( tlv17 )); }
    {char * tlv14; tlv14 = (char *)(cgc_strlen ( tlv17 )); }
    {void * tlv15; tlv15 = (void *)(cgc_strlen ( tlv17 )); }
}
void fix_ingred_form_16_21(){
fix_ingred_form_16_21_0();
}
void fix_ingred_form_16_22_1(){
int tlv3;
    bzero(&tlv3,sizeof(int));
    {char * input_buf; input_buf = (char *)(tlv3); }
    {char * tlv5; tlv5 = (char *)(tlv3); }
    {cgc_size_t tlv6; tlv6 = (cgc_size_t)(tlv3); }
    {cgc_size_t tlv9; tlv9 = (cgc_size_t)(tlv3); }
    {void * tlv12; tlv12 = (void *)(tlv3); }
    {char * tlv14; tlv14 = (char *)(tlv3); }
    {void * tlv15; tlv15 = (void *)(tlv3); }
}
void fix_ingred_form_16_22(){
fix_ingred_form_16_22_1();
}
void fix_ingred_form_16_23_0(){
question_t cur_ref;
    bzero(&cur_ref,1*sizeof(question_t));
question_t * cur = &cur_ref;
    {char * input_buf; input_buf = (char *)(cur -> answer); }
    {int tlv1; tlv1 = (int)(cur -> answer); }
    {cgc_size_t tlv4; tlv4 = (cgc_size_t)(cur -> answer); }
    {char * tlv5; tlv5 = (char *)(cur -> answer); }
    {int tlv2; tlv2 = (int)(cur -> answer); }
    {int tlv3; tlv3 = (int)(cur -> answer); }
    {cgc_size_t tlv6; tlv6 = (cgc_size_t)(cur -> answer); }
    {cgc_size_t tlv9; tlv9 = (cgc_size_t)(cur -> answer); }
    {void * tlv12; tlv12 = (void *)(cur -> answer); }
    {char * tlv14; tlv14 = (char *)(cur -> answer); }
    {void * tlv15; tlv15 = (void *)(cur -> answer); }
}
void fix_ingred_form_16_23(){
fix_ingred_form_16_23_0();
}
void fix_ingred_form_16(){
fix_ingred_form_16_2();
fix_ingred_form_16_5();
fix_ingred_form_16_6();
fix_ingred_form_16_8();
fix_ingred_form_16_9();
fix_ingred_form_16_11();
fix_ingred_form_16_15();
fix_ingred_form_16_21();
fix_ingred_form_16_22();
fix_ingred_form_16_23();
}
void fix_ingred_form_17(){
}
void fix_ingred_form_18_1_1(){
char buf_ref;
    bzero(&buf_ref,1*sizeof(char));
char * buf = &buf_ref;
    {int ret; ret = (int)(buf); }
    {char * tlv3; tlv3 = (char *)(buf); }
    {char * tlv7; tlv7 = (char *)(buf); }
}
void fix_ingred_form_18_1(){
fix_ingred_form_18_1_1();
}
void fix_ingred_form_18_4_0(){
char tlv5_ref;
    bzero(&tlv5_ref,1*sizeof(char));
const char * tlv5 = &tlv5_ref;
    {int ret; ret = (int)(cgc_strlen ( tlv5 )); }
    {cgc_size_t tlv2; tlv2 = (cgc_size_t)(cgc_strlen ( tlv5 )); }
    {char * tlv3; tlv3 = (char *)(cgc_strlen ( tlv5 )); }
    {char * tlv7; tlv7 = (char *)(cgc_strlen ( tlv5 )); }
}
void fix_ingred_form_18_4(){
fix_ingred_form_18_4_0();
}
void fix_ingred_form_18_5_0(){
cgc_size_t tlv2;
    bzero(&tlv2,sizeof(cgc_size_t));
    {int ret; ret = (int)(tlv2); }
    {char * tlv3; tlv3 = (char *)(tlv2); }
    {char * tlv7; tlv7 = (char *)(tlv2); }
}
void fix_ingred_form_18_5_1(){
cgc_size_t tlv2;
    bzero(&tlv2,sizeof(cgc_size_t));
    {int ret; ret = (int)(0); }
    {cgc_size_t tlv2; tlv2 = (cgc_size_t)(0); }
    {char * tlv3; tlv3 = (char *)(0); }
    {char * tlv7; tlv7 = (char *)(0); }
}
void fix_ingred_form_18_5(){
fix_ingred_form_18_5_0();
fix_ingred_form_18_5_1();
}
void fix_ingred_form_18_9_0(){
int ret;
    bzero(&ret,sizeof(int));
    {cgc_size_t tlv2; tlv2 = (cgc_size_t)(ret); }
    {char * tlv3; tlv3 = (char *)(ret); }
    {char * tlv7; tlv7 = (char *)(ret); }
}
void fix_ingred_form_18_9_1(){
int ret;
    bzero(&ret,sizeof(int));
    {char * tlv3; tlv3 = (char *)(0); }
    {char * tlv7; tlv7 = (char *)(0); }
}
void fix_ingred_form_18_9(){
fix_ingred_form_18_9_0();
fix_ingred_form_18_9_1();
}
void fix_ingred_form_18(){
fix_ingred_form_18_1();
fix_ingred_form_18_4();
fix_ingred_form_18_5();
fix_ingred_form_18_9();
}
void fix_ingred_form_19(){
}
