

#include "libcgc.h"
#include "cgc_libc.h"
#include "cgc_service.h"
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

void fix_ingred_service_0_0_0();
void fix_ingred_service_0_0_1();
void fix_ingred_service_0_0_2();
void fix_ingred_service_0_0();
void fix_ingred_service_0_1_6();
void fix_ingred_service_0_1_7();
void fix_ingred_service_0_1();
void fix_ingred_service_0_2_4();
void fix_ingred_service_0_2_13();
void fix_ingred_service_0_2();
void fix_ingred_service_0_3_0();
void fix_ingred_service_0_3();
void fix_ingred_service_0_4_0();
void fix_ingred_service_0_4_1();
void fix_ingred_service_0_4_2();
void fix_ingred_service_0_4();
void fix_ingred_service_0();
void cgc_newReport(Report * report)
{
if (fix_ingred_enable){ fix_ingred_service_0(); };
    char character;
    character = 0;
    char* string;
     string = NULL;
    short pos;
    pos = 0;
    short prev_pos;
    prev_pos = 0;
    short num_fields;
    num_fields = 0;
    Field* new_field;
    new_field = NULL;
    while (END_CHAR != character) {
	if (SPLIT_CHAR == character) {
     {
         cgc_size_t tlv5;
         tlv5 = sizeof ( Field );
    	    new_field = cgc_malloc(tlv5);
     }
	    new_field->start = prev_pos - num_fields;
	    new_field->size = pos - prev_pos - 1;
	    new_field->next = report->fields;
	    report->fields = new_field;
	    prev_pos = pos;
	    num_fields++;
	}
 {
     int tlv4;
     tlv4 = STDIN;
     char* tlv3;
      tlv3 = & character;
     cgc_size_t tlv2;
     tlv2 = sizeof ( character );
    	cgc_recv(tlv4,tlv3,tlv2);
 }
	pos++;
    }
    {
        cgc_size_t tlv1;
        tlv1 = sizeof ( Field );
        new_field = cgc_malloc(tlv1);
    }
    new_field->start = prev_pos - num_fields;
    new_field->size = pos - prev_pos - 1;
    new_field->next = report->fields;
    report->fields = new_field;
    num_fields++;
    report->record_size = pos - num_fields;
}

void fix_ingred_service_1_0_1();
void fix_ingred_service_1_0();
void fix_ingred_service_1_2_0();
void fix_ingred_service_1_2_1();
void fix_ingred_service_1_2();
void fix_ingred_service_1();
void cgc_sendReport(Report * report)
{
if (fix_ingred_enable){ fix_ingred_service_1(); };
    Record* nextRecord;
    nextRecord = NULL;
    int ret;
    ret = 0;
    for (nextRecord = report->head; nextRecord != NULL; nextRecord = nextRecord->next) {
 int tlv1;
 {
     int tlv4;
     tlv4 = STDOUT;
     const char* tlv3 = nextRecord -> data;
     cgc_size_t tlv2;
     tlv2 = report -> record_size;
     tlv1 = cgc_transmit_all(tlv4,tlv3,tlv2);
 }
	if (tlv1) {
	    cgc__terminate(TRANSMIT_ERROR);
	}
    }
}

void fix_ingred_service_2();
void cgc_splitReport(Record * source, Record ** front, Record ** back)
{
if (fix_ingred_enable){ fix_ingred_service_2(); };
    Record *fast;
    Record *slow;
    if (!source || !source->next) {
	*front = source;
	*back = NULL;
    } else {
	slow = source;
	fast = source->next;
	while (fast != NULL) {
	    fast = fast->next;
	    if (fast != NULL) {
		slow = slow->next;
		fast = fast->next;
	    }
	}
	*front = source;
	*back = slow->next;
	slow->next = NULL;
    }
}

void fix_ingred_service_3_3_0();
void fix_ingred_service_3_3();
void fix_ingred_service_3_4_2();
void fix_ingred_service_3_4_3();
void fix_ingred_service_3_4();
void fix_ingred_service_3();
Record *cgc_mergeReport(Record * a, Record * b, Field * field)
{
if (fix_ingred_enable){ fix_ingred_service_3(); };
    Record* result;
    result = NULL;
    int compare;
    if (!a) {
	return b;
    }
    if (!b) {
	return a;
    }
    {
        const char* tlv3 = & a -> data [ field -> start ];
        const char* tlv2 = & b -> data [ field -> start ];
        cgc_size_t tlv1;
        tlv1 = field -> size;
        compare = cgc_strncmp(tlv3,tlv2,tlv1);
    }
    if (compare <= 0) {
	result = a;
 {
     Record* tlv6;
     tlv6 = a -> next;
     Record* tlv5;
     tlv5 = b;
     Field* tlv4;
     tlv4 = field;
    	result->next = cgc_mergeReport(tlv6,tlv5,tlv4);
 }
    } else {
	result = b;
 {
     Record* tlv9;
     tlv9 = a;
     Record* tlv8;
     tlv8 = b -> next;
     Field* tlv7;
     tlv7 = field;
    	result->next = cgc_mergeReport(tlv9,tlv8,tlv7);
 }
    }
    return result;
}

void fix_ingred_service_4();
void cgc_sortReport(Record ** headRef, Field * field)
{
if (fix_ingred_enable){ fix_ingred_service_4(); };
    Record* head;
    head = * headRef;
    Record* a;
    a = NULL;
    Record* b;
    b = NULL;
    if (!head || !head->next) {
	return;
    }
    {
        Record* tlv3;
        tlv3 = head;
        Record** tlv2;
        tlv2 = & a;
        Record** tlv1;
        tlv1 = & b;
        cgc_splitReport(tlv3,tlv2,tlv1);
    }
    {
        Record** tlv5;
        tlv5 = & a;
        Field* tlv4;
        tlv4 = field;
        cgc_sortReport(tlv5,tlv4);
    }
    {
        Record** tlv7;
        tlv7 = & b;
        Field* tlv6;
        tlv6 = field;
        cgc_sortReport(tlv7,tlv6);
    }
    {
        Record* tlv10;
        tlv10 = a;
        Record* tlv9;
        tlv9 = b;
        Field* tlv8;
        tlv8 = field;
        *headRef = cgc_mergeReport(tlv10,tlv9,tlv8);
    }
}

void fix_ingred_service_5_0_2();
void fix_ingred_service_5_0();
void fix_ingred_service_5_3_0();
void fix_ingred_service_5_3();
void fix_ingred_service_5_5_0();
void fix_ingred_service_5_5();
void fix_ingred_service_5();
void cgc_filterReport(Report * report, Report * filteredReport, char *filterString)
{
if (fix_ingred_enable){ fix_ingred_service_5(); };
    Record* nextRecord;
    nextRecord = NULL;
    Field* nextField;
    nextField = NULL;
    int compare;
    compare = 0;
    for (nextRecord = report->head; nextRecord != NULL; nextRecord = nextRecord->next) {
	for (nextField = report->fields; nextField->next != NULL; nextField = nextField->next) {
     {
         const char* tlv3 = & nextRecord -> data [ nextField -> start ];
         const char* tlv2 = & filterString [ nextField -> start ];
         cgc_size_t tlv1;
         tlv1 = nextField -> size;
    	    compare = cgc_strncmp(tlv3,tlv2,tlv1);
     }
	    if (!compare) {
		Record *record;
  {
      cgc_size_t tlv4;
      tlv4 = sizeof ( Record );
    		record = cgc_malloc(tlv4);
  }
		record->next = filteredReport->head;
		record->data = nextRecord->data;
		filteredReport->head = record;
		break;
	    }
	}
    }
}

void fix_ingred_service_6_0_1();
void fix_ingred_service_6_0_2();
void fix_ingred_service_6_0();
void fix_ingred_service_6_1_0();
void fix_ingred_service_6_1();
void fix_ingred_service_6_2_0();
void fix_ingred_service_6_2();
void fix_ingred_service_6_4_0();
void fix_ingred_service_6_4_1();
void fix_ingred_service_6_4_2();
void fix_ingred_service_6_4();
void fix_ingred_service_6_5_0();
void fix_ingred_service_6_5();
void fix_ingred_service_6_6_0();
void fix_ingred_service_6_6();
void fix_ingred_service_6_7_0();
void fix_ingred_service_6_7_1();
void fix_ingred_service_6_7_2();
void fix_ingred_service_6_7();
void fix_ingred_service_6_9_0();
void fix_ingred_service_6_9();
void fix_ingred_service_6_20_11();
void fix_ingred_service_6_20_12();
void fix_ingred_service_6_20();
void fix_ingred_service_6_31_0();
void fix_ingred_service_6_31();
void fix_ingred_service_6();
int cgc_newRecord(Report * report)
{
if (fix_ingred_enable){ fix_ingred_service_6(); };
    Record* record;
    record = NULL;
    short second_field_size;
    second_field_size = 0;
    char* receive_buf;
     receive_buf = NULL;
    Field* nextField;
    nextField = NULL;
    short field_index;
    field_index = 0;
    {
        cgc_size_t tlv9;
        tlv9 = sizeof ( Record );
        record = cgc_malloc(tlv9);
    }
    record->next = NULL;
    {
        cgc_size_t tlv10;
        tlv10 = report -> record_size * 2;
        record->data = cgc_malloc(tlv10);
    }
    {
        cgc_size_t tlv11;
        tlv11 = report -> record_size * 2;
        receive_buf = cgc_malloc(tlv11);
    }
    {
        void* tlv8;
        tlv8 = record -> data;
        char tlv7;
        tlv7 = 0;
        cgc_size_t tlv6;
        tlv6 = report -> record_size;
        cgc_memset(tlv8,tlv7,tlv6);
    }

    for (nextField = report->fields; nextField != NULL; nextField = nextField->next) {
 {
     void* tlv16;
     tlv16 = receive_buf;
     char tlv15;
     tlv15 = 0;
     cgc_size_t tlv14;
     tlv14 = report -> record_size;
    	cgc_memset(tlv16,tlv15,tlv14);
 }
 {
     int tlv19;
     tlv19 = STDIN;
     char* tlv18;
      tlv18 = receive_buf;
     cgc_size_t tlv17;
     tlv17 = nextField -> size;
    	cgc_recv(tlv19,tlv18,tlv17);
 }
 {
     char* tlv21;
      tlv21 = & record -> data [ field_index ];
     char* tlv20;
      tlv20 = receive_buf;
    	cgc_strcpy(tlv21,tlv20);
 }
	field_index += nextField->size;
    }
    cgc_free(receive_buf);
    int tlv1;
    {
        char* tlv13;
         tlv13 = record -> data;
        char tlv12[] = "END";
        tlv1 = cgc_startswith(tlv13,tlv12);
    }
    if (tlv1) {
 {
     void* tlv22;
     tlv22 = record -> data;
    	cgc_free(tlv22);
 }
	cgc_free(record);
	return 0;
    } else {
 int tlv2;
 {
     char* tlv24;
      tlv24 = record -> data;
     char tlv23[] = "REPORT";
     tlv2 = cgc_startswith(tlv24,tlv23);
 }
	if (tlv2) {
	    cgc_sendReport(report);
     {
         void* tlv25;
         tlv25 = record -> data;
    	    cgc_free(tlv25);
     }
	    cgc_free(record);
	    return 1;
	} else {
     int tlv3;
     {
         char* tlv27;
          tlv27 = record -> data;
         char tlv26[] = "SORT";
         tlv3 = cgc_startswith(tlv27,tlv26);
     }
	    if (tlv3) {
		unsigned short field_index;
		Field *key;
		field_index = record->data[sizeof("SORT") - 1];
		for (key = report->fields; key != NULL; key = key->next) {
		    if (field_index == 0) {
			break;
		    }
		    field_index--;
		}
		if (key) {
      {
          Record** tlv32;
          tlv32 = & report -> head;
          Field* tlv31;
          tlv31 = key;
    		    cgc_sortReport(tlv32,tlv31);
      }
		}
  {
      void* tlv28;
      tlv28 = record -> data;
    		cgc_free(tlv28);
  }
		cgc_free(record);
		return 1;
	    } else {
  int tlv4;
  {
      char* tlv30;
       tlv30 = record -> data;
      char tlv29[] = "FREPORT";
      tlv4 = cgc_startswith(tlv30,tlv29);
  }
		if (tlv4) {
		    Report filteredReport = { NULL, 0, 0 };
		    filteredReport.record_size = report->record_size;
      {
          Report* tlv35;
          tlv35 = report;
          Report* tlv34;
          tlv34 = & filteredReport;
          char* tlv33;
           tlv33 = record -> data;
    		    cgc_filterReport(tlv35,tlv34,tlv33);
      }
      {
          Report* tlv36;
          tlv36 = & filteredReport;
    		    cgc_sendReport(tlv36);
      }
      {
          void* tlv37;
          tlv37 = record -> data;
    		    cgc_free(tlv37);
      }
		    cgc_free(record);
		    return 1;
		} else {
		    char *command;
		    command = &record->data[report->fields->start];
      int tlv5;
      {
          char* tlv39;
           tlv39 = command;
          char tlv38[] = "ERROR";
          tlv5 = cgc_startswith(tlv39,tlv38);
      }
		    if (tlv5) {
			cgc_free(command);
			cgc_free(record);
			return 1;
		    }
		}
	    }
	}
    }
    record->next = report->head;
    report->head = record;
    return 1;
}

void fix_ingred_service_7_0_0();
void fix_ingred_service_7_0();
void fix_ingred_service_7();
int main(int cgc_argc, char *cgc_argv[])
{
if (fix_ingred_enable){ fix_ingred_service_7(); };
    Report report = { NULL, 0, 0 };
    char* field;
     field = NULL;
    {
        Report* tlv1;
        tlv1 = & report;
        cgc_newReport(tlv1);
    }
    {
    while (cgc_newRecord(&report));
    }
    return 0;
}

void fix_ingred_service_0_0_0(){
    {char character; character = (char)(0); }
    {char * string; string = (char *)(0); }
    {short pos; pos = (short)(0); }
    {short prev_pos; prev_pos = (short)(0); }
    {short num_fields; num_fields = (short)(0); }
    {cgc_size_t tlv1; tlv1 = (cgc_size_t)(0); }
    {int tlv4; tlv4 = (int)(0); }
    {char * tlv3; tlv3 = (char *)(0); }
    {cgc_size_t tlv2; tlv2 = (cgc_size_t)(0); }
    {cgc_size_t tlv5; tlv5 = (cgc_size_t)(0); }
}
void fix_ingred_service_0_0_1(){
    {char character; character = (char)(NULL); }
    {char * string; string = (char *)(NULL); }
    {short pos; pos = (short)(NULL); }
    {short prev_pos; prev_pos = (short)(NULL); }
    {short num_fields; num_fields = (short)(NULL); }
    {cgc_size_t tlv1; tlv1 = (cgc_size_t)(NULL); }
    {int tlv4; tlv4 = (int)(NULL); }
    {char * tlv3; tlv3 = (char *)(NULL); }
    {cgc_size_t tlv2; tlv2 = (cgc_size_t)(NULL); }
    {cgc_size_t tlv5; tlv5 = (cgc_size_t)(NULL); }
}
void fix_ingred_service_0_0_2(){
    {char character; character = (char)(0); }
    {char * string; string = (char *)(0); }
    {short pos; pos = (short)(0); }
    {short prev_pos; prev_pos = (short)(0); }
    {short num_fields; num_fields = (short)(0); }
    {cgc_size_t tlv1; tlv1 = (cgc_size_t)(0); }
    {int tlv4; tlv4 = (int)(0); }
    {char * tlv3; tlv3 = (char *)(0); }
    {cgc_size_t tlv2; tlv2 = (cgc_size_t)(0); }
    {cgc_size_t tlv5; tlv5 = (cgc_size_t)(0); }
}
void fix_ingred_service_0_0(){
fix_ingred_service_0_0_0();
fix_ingred_service_0_0_1();
fix_ingred_service_0_0_2();
}
void fix_ingred_service_0_1_6(){
char character;
    bzero(&character,sizeof(char));
    {char character; character = (char)(END_CHAR); }
    {char * string; string = (char *)(END_CHAR); }
    {short pos; pos = (short)(END_CHAR); }
    {short prev_pos; prev_pos = (short)(END_CHAR); }
    {short num_fields; num_fields = (short)(END_CHAR); }
    {cgc_size_t tlv1; tlv1 = (cgc_size_t)(END_CHAR); }
    {int tlv4; tlv4 = (int)(END_CHAR); }
    {char * tlv3; tlv3 = (char *)(END_CHAR); }
    {cgc_size_t tlv2; tlv2 = (cgc_size_t)(END_CHAR); }
    {cgc_size_t tlv5; tlv5 = (cgc_size_t)(END_CHAR); }
}
void fix_ingred_service_0_1_7(){
char character;
    bzero(&character,sizeof(char));
    {char * string; string = (char *)(character); }
    {short pos; pos = (short)(character); }
    {short prev_pos; prev_pos = (short)(character); }
    {short num_fields; num_fields = (short)(character); }
    {cgc_size_t tlv1; tlv1 = (cgc_size_t)(character); }
    {int tlv4; tlv4 = (int)(character); }
    {char * tlv3; tlv3 = (char *)(character); }
    {cgc_size_t tlv2; tlv2 = (cgc_size_t)(character); }
    {cgc_size_t tlv5; tlv5 = (cgc_size_t)(character); }
}
void fix_ingred_service_0_1(){
fix_ingred_service_0_1_6();
fix_ingred_service_0_1_7();
}
void fix_ingred_service_0_2_4(){
short pos;
    bzero(&pos,sizeof(short));
    {char character; character = (char)(pos); }
    {char * string; string = (char *)(pos); }
    {short prev_pos; prev_pos = (short)(pos); }
    {short num_fields; num_fields = (short)(pos); }
    {cgc_size_t tlv1; tlv1 = (cgc_size_t)(pos); }
    {int tlv4; tlv4 = (int)(pos); }
    {char * tlv3; tlv3 = (char *)(pos); }
    {cgc_size_t tlv2; tlv2 = (cgc_size_t)(pos); }
    {cgc_size_t tlv5; tlv5 = (cgc_size_t)(pos); }
}
void fix_ingred_service_0_2_13(){
short pos;
    bzero(&pos,sizeof(short));
    {char character; character = (char)(SPLIT_CHAR); }
    {char * string; string = (char *)(SPLIT_CHAR); }
    {short pos; pos = (short)(SPLIT_CHAR); }
    {short prev_pos; prev_pos = (short)(SPLIT_CHAR); }
    {short num_fields; num_fields = (short)(SPLIT_CHAR); }
    {cgc_size_t tlv1; tlv1 = (cgc_size_t)(SPLIT_CHAR); }
    {int tlv4; tlv4 = (int)(SPLIT_CHAR); }
    {char * tlv3; tlv3 = (char *)(SPLIT_CHAR); }
    {cgc_size_t tlv2; tlv2 = (cgc_size_t)(SPLIT_CHAR); }
    {cgc_size_t tlv5; tlv5 = (cgc_size_t)(SPLIT_CHAR); }
}
void fix_ingred_service_0_2(){
fix_ingred_service_0_2_4();
fix_ingred_service_0_2_13();
}
void fix_ingred_service_0_3_0(){
    {char character; character = (char)(sizeof ( Field )); }
    {char * string; string = (char *)(sizeof ( Field )); }
    {short pos; pos = (short)(sizeof ( Field )); }
    {short prev_pos; prev_pos = (short)(sizeof ( Field )); }
    {short num_fields; num_fields = (short)(sizeof ( Field )); }
    {cgc_size_t tlv1; tlv1 = (cgc_size_t)(sizeof ( Field )); }
    {int tlv4; tlv4 = (int)(sizeof ( Field )); }
    {char * tlv3; tlv3 = (char *)(sizeof ( Field )); }
    {cgc_size_t tlv2; tlv2 = (cgc_size_t)(sizeof ( Field )); }
    {cgc_size_t tlv5; tlv5 = (cgc_size_t)(sizeof ( Field )); }
}
void fix_ingred_service_0_3(){
fix_ingred_service_0_3_0();
}
void fix_ingred_service_0_4_0(){
char character;
    bzero(&character,sizeof(char));
    {char character; character = (char)(STDIN); }
    {char * string; string = (char *)(STDIN); }
    {short pos; pos = (short)(STDIN); }
    {short prev_pos; prev_pos = (short)(STDIN); }
    {short num_fields; num_fields = (short)(STDIN); }
    {cgc_size_t tlv1; tlv1 = (cgc_size_t)(STDIN); }
    {int tlv4; tlv4 = (int)(STDIN); }
    {char * tlv3; tlv3 = (char *)(STDIN); }
    {cgc_size_t tlv2; tlv2 = (cgc_size_t)(STDIN); }
    {cgc_size_t tlv5; tlv5 = (cgc_size_t)(STDIN); }
}
void fix_ingred_service_0_4_1(){
char character;
    bzero(&character,sizeof(char));
    {char * string; string = (char *)(& character); }
    {short pos; pos = (short)(& character); }
    {short prev_pos; prev_pos = (short)(& character); }
    {short num_fields; num_fields = (short)(& character); }
    {cgc_size_t tlv1; tlv1 = (cgc_size_t)(& character); }
    {int tlv4; tlv4 = (int)(& character); }
    {char * tlv3; tlv3 = (char *)(& character); }
    {cgc_size_t tlv2; tlv2 = (cgc_size_t)(& character); }
    {cgc_size_t tlv5; tlv5 = (cgc_size_t)(& character); }
}
void fix_ingred_service_0_4_2(){
char character;
    bzero(&character,sizeof(char));
    {char * string; string = (char *)(sizeof ( character )); }
    {short pos; pos = (short)(sizeof ( character )); }
    {short prev_pos; prev_pos = (short)(sizeof ( character )); }
    {short num_fields; num_fields = (short)(sizeof ( character )); }
    {cgc_size_t tlv1; tlv1 = (cgc_size_t)(sizeof ( character )); }
    {int tlv4; tlv4 = (int)(sizeof ( character )); }
    {char * tlv3; tlv3 = (char *)(sizeof ( character )); }
    {cgc_size_t tlv2; tlv2 = (cgc_size_t)(sizeof ( character )); }
    {cgc_size_t tlv5; tlv5 = (cgc_size_t)(sizeof ( character )); }
}
void fix_ingred_service_0_4(){
fix_ingred_service_0_4_0();
fix_ingred_service_0_4_1();
fix_ingred_service_0_4_2();
}
void fix_ingred_service_0(){
fix_ingred_service_0_0();
fix_ingred_service_0_1();
fix_ingred_service_0_2();
fix_ingred_service_0_3();
fix_ingred_service_0_4();
}
void fix_ingred_service_1_0_1(){
    {int ret; ret = (int)(0); }
    {int tlv1; tlv1 = (int)(0); }
    {int tlv4; tlv4 = (int)(0); }
    {cgc_size_t tlv2; tlv2 = (cgc_size_t)(0); }
}
void fix_ingred_service_1_0(){
fix_ingred_service_1_0_1();
}
void fix_ingred_service_1_2_0(){
Report report_ref;
    bzero(&report_ref,1*sizeof(Report));
Report * report = &report_ref;
    {int ret; ret = (int)(STDOUT); }
    {int tlv1; tlv1 = (int)(STDOUT); }
    {int tlv4; tlv4 = (int)(STDOUT); }
    {cgc_size_t tlv2; tlv2 = (cgc_size_t)(STDOUT); }
}
void fix_ingred_service_1_2_1(){
Report report_ref;
    bzero(&report_ref,1*sizeof(Report));
Report * report = &report_ref;
    {int ret; ret = (int)(report -> record_size); }
    {int tlv1; tlv1 = (int)(report -> record_size); }
    {int tlv4; tlv4 = (int)(report -> record_size); }
    {cgc_size_t tlv2; tlv2 = (cgc_size_t)(report -> record_size); }
}
void fix_ingred_service_1_2(){
fix_ingred_service_1_2_0();
fix_ingred_service_1_2_1();
}
void fix_ingred_service_1(){
fix_ingred_service_1_0();
fix_ingred_service_1_2();
}
void fix_ingred_service_2(){
}
void fix_ingred_service_3_3_0(){
Field field_ref;
    bzero(&field_ref,1*sizeof(Field));
Field * field = &field_ref;
    {int compare; compare = (int)(field -> size); }
    {cgc_size_t tlv1; tlv1 = (cgc_size_t)(field -> size); }
}
void fix_ingred_service_3_3(){
fix_ingred_service_3_3_0();
}
void fix_ingred_service_3_4_2(){
int compare;
    bzero(&compare,sizeof(int));
    {cgc_size_t tlv1; tlv1 = (cgc_size_t)(compare); }
}
void fix_ingred_service_3_4_3(){
int compare;
    bzero(&compare,sizeof(int));
    {int compare; compare = (int)(0); }
    {cgc_size_t tlv1; tlv1 = (cgc_size_t)(0); }
}
void fix_ingred_service_3_4(){
fix_ingred_service_3_4_2();
fix_ingred_service_3_4_3();
}
void fix_ingred_service_3(){
fix_ingred_service_3_3();
fix_ingred_service_3_4();
}
void fix_ingred_service_4(){
}
void fix_ingred_service_5_0_2(){
    {cgc_size_t tlv4; tlv4 = (cgc_size_t)(0); }
}
void fix_ingred_service_5_0(){
fix_ingred_service_5_0_2();
}
void fix_ingred_service_5_3_0(){
Field nextField_ref;
    bzero(&nextField_ref,1*sizeof(Field));
Field * nextField = &nextField_ref;
    {int compare; compare = (int)(nextField -> size); }
    {cgc_size_t tlv1; tlv1 = (cgc_size_t)(nextField -> size); }
    {cgc_size_t tlv4; tlv4 = (cgc_size_t)(nextField -> size); }
}
void fix_ingred_service_5_3(){
fix_ingred_service_5_3_0();
}
void fix_ingred_service_5_5_0(){
    {int compare; compare = (int)(sizeof ( Record )); }
    {cgc_size_t tlv1; tlv1 = (cgc_size_t)(sizeof ( Record )); }
    {cgc_size_t tlv4; tlv4 = (cgc_size_t)(sizeof ( Record )); }
}
void fix_ingred_service_5_5(){
fix_ingred_service_5_5_0();
}
void fix_ingred_service_5(){
fix_ingred_service_5_0();
fix_ingred_service_5_3();
fix_ingred_service_5_5();
}
void fix_ingred_service_6_0_1(){
    {short second_field_size; second_field_size = (short)(0); }
    {char * receive_buf; receive_buf = (char *)(0); }
    {short field_index; field_index = (short)(0); }
    {int tlv1; tlv1 = (int)(0); }
    {cgc_size_t tlv9; tlv9 = (cgc_size_t)(0); }
    {cgc_size_t tlv10; tlv10 = (cgc_size_t)(0); }
    {cgc_size_t tlv11; tlv11 = (cgc_size_t)(0); }
    {void * tlv8; tlv8 = (void *)(0); }
    {char tlv7; tlv7 = (char)(0); }
    {cgc_size_t tlv6; tlv6 = (cgc_size_t)(0); }
    {char * tlv13; tlv13 = (char *)(0); }
    {char* tlv12 ; tlv12  = (char*)(0); }
    {int tlv2; tlv2 = (int)(0); }
    {void * tlv16; tlv16 = (void *)(0); }
    {char tlv15; tlv15 = (char)(0); }
    {cgc_size_t tlv14; tlv14 = (cgc_size_t)(0); }
    {int tlv19; tlv19 = (int)(0); }
    {char * tlv18; tlv18 = (char *)(0); }
    {cgc_size_t tlv17; tlv17 = (cgc_size_t)(0); }
    {char * tlv21; tlv21 = (char *)(0); }
    {char * tlv20; tlv20 = (char *)(0); }
    {void * tlv22; tlv22 = (void *)(0); }
    {char * tlv24; tlv24 = (char *)(0); }
    {char* tlv23 ; tlv23  = (char*)(0); }
    {int tlv3; tlv3 = (int)(0); }
    {void * tlv25; tlv25 = (void *)(0); }
    {char * tlv27; tlv27 = (char *)(0); }
    {char* tlv26 ; tlv26  = (char*)(0); }
    {unsigned short field_index; field_index = (unsigned short)(0); }
    {void * tlv28; tlv28 = (void *)(0); }
    {char * tlv30; tlv30 = (char *)(0); }
    {char* tlv29 ; tlv29  = (char*)(0); }
    {char * command; command = (char *)(0); }
    {int tlv5; tlv5 = (int)(0); }
    {char * tlv33; tlv33 = (char *)(0); }
    {void * tlv37; tlv37 = (void *)(0); }
    {char * tlv39; tlv39 = (char *)(0); }
    {char* tlv38 ; tlv38  = (char*)(0); }
}
void fix_ingred_service_6_0_2(){
    {short second_field_size; second_field_size = (short)(NULL); }
    {char * receive_buf; receive_buf = (char *)(NULL); }
    {short field_index; field_index = (short)(NULL); }
    {int tlv1; tlv1 = (int)(NULL); }
    {cgc_size_t tlv9; tlv9 = (cgc_size_t)(NULL); }
    {cgc_size_t tlv10; tlv10 = (cgc_size_t)(NULL); }
    {cgc_size_t tlv11; tlv11 = (cgc_size_t)(NULL); }
    {void * tlv8; tlv8 = (void *)(NULL); }
    {char tlv7; tlv7 = (char)(NULL); }
    {cgc_size_t tlv6; tlv6 = (cgc_size_t)(NULL); }
    {char * tlv13; tlv13 = (char *)(NULL); }
    {char* tlv12 ; tlv12  = (char*)(NULL); }
    {int tlv2; tlv2 = (int)(NULL); }
    {void * tlv16; tlv16 = (void *)(NULL); }
    {char tlv15; tlv15 = (char)(NULL); }
    {cgc_size_t tlv14; tlv14 = (cgc_size_t)(NULL); }
    {int tlv19; tlv19 = (int)(NULL); }
    {char * tlv18; tlv18 = (char *)(NULL); }
    {cgc_size_t tlv17; tlv17 = (cgc_size_t)(NULL); }
    {char * tlv21; tlv21 = (char *)(NULL); }
    {char * tlv20; tlv20 = (char *)(NULL); }
    {void * tlv22; tlv22 = (void *)(NULL); }
    {char * tlv24; tlv24 = (char *)(NULL); }
    {char* tlv23 ; tlv23  = (char*)(NULL); }
    {int tlv3; tlv3 = (int)(NULL); }
    {void * tlv25; tlv25 = (void *)(NULL); }
    {char * tlv27; tlv27 = (char *)(NULL); }
    {char* tlv26 ; tlv26  = (char*)(NULL); }
    {unsigned short field_index; field_index = (unsigned short)(NULL); }
    {void * tlv28; tlv28 = (void *)(NULL); }
    {char * tlv30; tlv30 = (char *)(NULL); }
    {char* tlv29 ; tlv29  = (char*)(NULL); }
    {char * command; command = (char *)(NULL); }
    {int tlv5; tlv5 = (int)(NULL); }
    {char * tlv33; tlv33 = (char *)(NULL); }
    {void * tlv37; tlv37 = (void *)(NULL); }
    {char * tlv39; tlv39 = (char *)(NULL); }
    {char* tlv38 ; tlv38  = (char*)(NULL); }
}
void fix_ingred_service_6_0(){
fix_ingred_service_6_0_1();
fix_ingred_service_6_0_2();
}
void fix_ingred_service_6_1_0(){
    {short second_field_size; second_field_size = (short)(sizeof ( Record )); }
    {char * receive_buf; receive_buf = (char *)(sizeof ( Record )); }
    {short field_index; field_index = (short)(sizeof ( Record )); }
    {int tlv1; tlv1 = (int)(sizeof ( Record )); }
    {cgc_size_t tlv9; tlv9 = (cgc_size_t)(sizeof ( Record )); }
    {cgc_size_t tlv10; tlv10 = (cgc_size_t)(sizeof ( Record )); }
    {cgc_size_t tlv11; tlv11 = (cgc_size_t)(sizeof ( Record )); }
    {void * tlv8; tlv8 = (void *)(sizeof ( Record )); }
    {char tlv7; tlv7 = (char)(sizeof ( Record )); }
    {cgc_size_t tlv6; tlv6 = (cgc_size_t)(sizeof ( Record )); }
    {char * tlv13; tlv13 = (char *)(sizeof ( Record )); }
    {char* tlv12 ; tlv12  = (char*)(sizeof ( Record )); }
    {int tlv2; tlv2 = (int)(sizeof ( Record )); }
    {void * tlv16; tlv16 = (void *)(sizeof ( Record )); }
    {char tlv15; tlv15 = (char)(sizeof ( Record )); }
    {cgc_size_t tlv14; tlv14 = (cgc_size_t)(sizeof ( Record )); }
    {int tlv19; tlv19 = (int)(sizeof ( Record )); }
    {char * tlv18; tlv18 = (char *)(sizeof ( Record )); }
    {cgc_size_t tlv17; tlv17 = (cgc_size_t)(sizeof ( Record )); }
    {char * tlv21; tlv21 = (char *)(sizeof ( Record )); }
    {char * tlv20; tlv20 = (char *)(sizeof ( Record )); }
    {void * tlv22; tlv22 = (void *)(sizeof ( Record )); }
    {char * tlv24; tlv24 = (char *)(sizeof ( Record )); }
    {char* tlv23 ; tlv23  = (char*)(sizeof ( Record )); }
    {int tlv3; tlv3 = (int)(sizeof ( Record )); }
    {void * tlv25; tlv25 = (void *)(sizeof ( Record )); }
    {char * tlv27; tlv27 = (char *)(sizeof ( Record )); }
    {char* tlv26 ; tlv26  = (char*)(sizeof ( Record )); }
    {unsigned short field_index; field_index = (unsigned short)(sizeof ( Record )); }
    {int tlv4; tlv4 = (int)(sizeof ( Record )); }
    {void * tlv28; tlv28 = (void *)(sizeof ( Record )); }
    {char * tlv30; tlv30 = (char *)(sizeof ( Record )); }
    {char* tlv29 ; tlv29  = (char*)(sizeof ( Record )); }
    {char * command; command = (char *)(sizeof ( Record )); }
    {int tlv5; tlv5 = (int)(sizeof ( Record )); }
    {char * tlv33; tlv33 = (char *)(sizeof ( Record )); }
    {void * tlv37; tlv37 = (void *)(sizeof ( Record )); }
    {char * tlv39; tlv39 = (char *)(sizeof ( Record )); }
    {char* tlv38 ; tlv38  = (char*)(sizeof ( Record )); }
}
void fix_ingred_service_6_1(){
fix_ingred_service_6_1_0();
}
void fix_ingred_service_6_2_0(){
Report report_ref;
    bzero(&report_ref,1*sizeof(Report));
Report * report = &report_ref;
    {short second_field_size; second_field_size = (short)(report -> record_size * 2); }
    {char * receive_buf; receive_buf = (char *)(report -> record_size * 2); }
    {short field_index; field_index = (short)(report -> record_size * 2); }
    {int tlv1; tlv1 = (int)(report -> record_size * 2); }
    {cgc_size_t tlv9; tlv9 = (cgc_size_t)(report -> record_size * 2); }
    {cgc_size_t tlv10; tlv10 = (cgc_size_t)(report -> record_size * 2); }
    {cgc_size_t tlv11; tlv11 = (cgc_size_t)(report -> record_size * 2); }
    {void * tlv8; tlv8 = (void *)(report -> record_size * 2); }
    {char tlv7; tlv7 = (char)(report -> record_size * 2); }
    {cgc_size_t tlv6; tlv6 = (cgc_size_t)(report -> record_size * 2); }
    {char * tlv13; tlv13 = (char *)(report -> record_size * 2); }
    {char* tlv12 ; tlv12  = (char*)(report -> record_size * 2); }
    {int tlv2; tlv2 = (int)(report -> record_size * 2); }
    {void * tlv16; tlv16 = (void *)(report -> record_size * 2); }
    {char tlv15; tlv15 = (char)(report -> record_size * 2); }
    {cgc_size_t tlv14; tlv14 = (cgc_size_t)(report -> record_size * 2); }
    {int tlv19; tlv19 = (int)(report -> record_size * 2); }
    {char * tlv18; tlv18 = (char *)(report -> record_size * 2); }
    {cgc_size_t tlv17; tlv17 = (cgc_size_t)(report -> record_size * 2); }
    {char * tlv21; tlv21 = (char *)(report -> record_size * 2); }
    {char * tlv20; tlv20 = (char *)(report -> record_size * 2); }
    {void * tlv22; tlv22 = (void *)(report -> record_size * 2); }
    {char * tlv24; tlv24 = (char *)(report -> record_size * 2); }
    {char* tlv23 ; tlv23  = (char*)(report -> record_size * 2); }
    {int tlv3; tlv3 = (int)(report -> record_size * 2); }
    {void * tlv25; tlv25 = (void *)(report -> record_size * 2); }
    {char * tlv27; tlv27 = (char *)(report -> record_size * 2); }
    {char* tlv26 ; tlv26  = (char*)(report -> record_size * 2); }
    {unsigned short field_index; field_index = (unsigned short)(report -> record_size * 2); }
    {int tlv4; tlv4 = (int)(report -> record_size * 2); }
    {void * tlv28; tlv28 = (void *)(report -> record_size * 2); }
    {char * tlv30; tlv30 = (char *)(report -> record_size * 2); }
    {char* tlv29 ; tlv29  = (char*)(report -> record_size * 2); }
    {char * command; command = (char *)(report -> record_size * 2); }
    {int tlv5; tlv5 = (int)(report -> record_size * 2); }
    {char * tlv33; tlv33 = (char *)(report -> record_size * 2); }
    {void * tlv37; tlv37 = (void *)(report -> record_size * 2); }
    {char * tlv39; tlv39 = (char *)(report -> record_size * 2); }
    {char* tlv38 ; tlv38  = (char*)(report -> record_size * 2); }
}
void fix_ingred_service_6_2(){
fix_ingred_service_6_2_0();
}
void fix_ingred_service_6_4_0(){
Record record_ref;
    bzero(&record_ref,1*sizeof(Record));
Record * record = &record_ref;
Report report_ref;
    bzero(&report_ref,1*sizeof(Report));
Report * report = &report_ref;
    {short second_field_size; second_field_size = (short)(record -> data); }
    {char * receive_buf; receive_buf = (char *)(record -> data); }
    {short field_index; field_index = (short)(record -> data); }
    {int tlv1; tlv1 = (int)(record -> data); }
    {cgc_size_t tlv9; tlv9 = (cgc_size_t)(record -> data); }
    {cgc_size_t tlv10; tlv10 = (cgc_size_t)(record -> data); }
    {cgc_size_t tlv11; tlv11 = (cgc_size_t)(record -> data); }
    {void * tlv8; tlv8 = (void *)(record -> data); }
    {char tlv7; tlv7 = (char)(record -> data); }
    {cgc_size_t tlv6; tlv6 = (cgc_size_t)(record -> data); }
    {char * tlv13; tlv13 = (char *)(record -> data); }
    {char* tlv12 ; tlv12  = (char*)(record -> data); }
    {int tlv2; tlv2 = (int)(record -> data); }
    {void * tlv16; tlv16 = (void *)(record -> data); }
    {char tlv15; tlv15 = (char)(record -> data); }
    {cgc_size_t tlv14; tlv14 = (cgc_size_t)(record -> data); }
    {int tlv19; tlv19 = (int)(record -> data); }
    {char * tlv18; tlv18 = (char *)(record -> data); }
    {cgc_size_t tlv17; tlv17 = (cgc_size_t)(record -> data); }
    {char * tlv21; tlv21 = (char *)(record -> data); }
    {char * tlv20; tlv20 = (char *)(record -> data); }
    {void * tlv22; tlv22 = (void *)(record -> data); }
    {char * tlv24; tlv24 = (char *)(record -> data); }
    {char* tlv23 ; tlv23  = (char*)(record -> data); }
    {int tlv3; tlv3 = (int)(record -> data); }
    {void * tlv25; tlv25 = (void *)(record -> data); }
    {char * tlv27; tlv27 = (char *)(record -> data); }
    {char* tlv26 ; tlv26  = (char*)(record -> data); }
    {unsigned short field_index; field_index = (unsigned short)(record -> data); }
    {int tlv4; tlv4 = (int)(record -> data); }
    {void * tlv28; tlv28 = (void *)(record -> data); }
    {char * tlv30; tlv30 = (char *)(record -> data); }
    {char* tlv29 ; tlv29  = (char*)(record -> data); }
    {char * command; command = (char *)(record -> data); }
    {int tlv5; tlv5 = (int)(record -> data); }
    {char * tlv33; tlv33 = (char *)(record -> data); }
    {void * tlv37; tlv37 = (void *)(record -> data); }
    {char * tlv39; tlv39 = (char *)(record -> data); }
    {char* tlv38 ; tlv38  = (char*)(record -> data); }
}
void fix_ingred_service_6_4_1(){
Record record_ref;
    bzero(&record_ref,1*sizeof(Record));
Record * record = &record_ref;
Report report_ref;
    bzero(&report_ref,1*sizeof(Report));
Report * report = &report_ref;
    {short second_field_size; second_field_size = (short)(0); }
    {char * receive_buf; receive_buf = (char *)(0); }
    {short field_index; field_index = (short)(0); }
    {int tlv1; tlv1 = (int)(0); }
    {cgc_size_t tlv9; tlv9 = (cgc_size_t)(0); }
    {cgc_size_t tlv10; tlv10 = (cgc_size_t)(0); }
    {cgc_size_t tlv11; tlv11 = (cgc_size_t)(0); }
    {void * tlv8; tlv8 = (void *)(0); }
    {char tlv7; tlv7 = (char)(0); }
    {cgc_size_t tlv6; tlv6 = (cgc_size_t)(0); }
    {char * tlv13; tlv13 = (char *)(0); }
    {char* tlv12 ; tlv12  = (char*)(0); }
    {int tlv2; tlv2 = (int)(0); }
    {void * tlv16; tlv16 = (void *)(0); }
    {char tlv15; tlv15 = (char)(0); }
    {cgc_size_t tlv14; tlv14 = (cgc_size_t)(0); }
    {int tlv19; tlv19 = (int)(0); }
    {char * tlv18; tlv18 = (char *)(0); }
    {cgc_size_t tlv17; tlv17 = (cgc_size_t)(0); }
    {char * tlv21; tlv21 = (char *)(0); }
    {char * tlv20; tlv20 = (char *)(0); }
    {void * tlv22; tlv22 = (void *)(0); }
    {char * tlv24; tlv24 = (char *)(0); }
    {char* tlv23 ; tlv23  = (char*)(0); }
    {int tlv3; tlv3 = (int)(0); }
    {void * tlv25; tlv25 = (void *)(0); }
    {char * tlv27; tlv27 = (char *)(0); }
    {char* tlv26 ; tlv26  = (char*)(0); }
    {unsigned short field_index; field_index = (unsigned short)(0); }
    {void * tlv28; tlv28 = (void *)(0); }
    {char * tlv30; tlv30 = (char *)(0); }
    {char* tlv29 ; tlv29  = (char*)(0); }
    {char * command; command = (char *)(0); }
    {int tlv5; tlv5 = (int)(0); }
    {char * tlv33; tlv33 = (char *)(0); }
    {void * tlv37; tlv37 = (void *)(0); }
    {char * tlv39; tlv39 = (char *)(0); }
    {char* tlv38 ; tlv38  = (char*)(0); }
}
void fix_ingred_service_6_4_2(){
Record record_ref;
    bzero(&record_ref,1*sizeof(Record));
Record * record = &record_ref;
Report report_ref;
    bzero(&report_ref,1*sizeof(Report));
Report * report = &report_ref;
    {short second_field_size; second_field_size = (short)(report -> record_size); }
    {char * receive_buf; receive_buf = (char *)(report -> record_size); }
    {short field_index; field_index = (short)(report -> record_size); }
    {cgc_size_t tlv9; tlv9 = (cgc_size_t)(report -> record_size); }
    {cgc_size_t tlv10; tlv10 = (cgc_size_t)(report -> record_size); }
    {cgc_size_t tlv11; tlv11 = (cgc_size_t)(report -> record_size); }
    {void * tlv8; tlv8 = (void *)(report -> record_size); }
    {char tlv7; tlv7 = (char)(report -> record_size); }
    {cgc_size_t tlv6; tlv6 = (cgc_size_t)(report -> record_size); }
    {char * tlv13; tlv13 = (char *)(report -> record_size); }
    {char* tlv12 ; tlv12  = (char*)(report -> record_size); }
    {int tlv2; tlv2 = (int)(report -> record_size); }
    {void * tlv16; tlv16 = (void *)(report -> record_size); }
    {char tlv15; tlv15 = (char)(report -> record_size); }
    {cgc_size_t tlv14; tlv14 = (cgc_size_t)(report -> record_size); }
    {int tlv19; tlv19 = (int)(report -> record_size); }
    {char * tlv18; tlv18 = (char *)(report -> record_size); }
    {cgc_size_t tlv17; tlv17 = (cgc_size_t)(report -> record_size); }
    {char * tlv21; tlv21 = (char *)(report -> record_size); }
    {char * tlv20; tlv20 = (char *)(report -> record_size); }
    {void * tlv22; tlv22 = (void *)(report -> record_size); }
    {char * tlv24; tlv24 = (char *)(report -> record_size); }
    {char* tlv23 ; tlv23  = (char*)(report -> record_size); }
    {int tlv3; tlv3 = (int)(report -> record_size); }
    {void * tlv25; tlv25 = (void *)(report -> record_size); }
    {char * tlv27; tlv27 = (char *)(report -> record_size); }
    {char* tlv26 ; tlv26  = (char*)(report -> record_size); }
    {unsigned short field_index; field_index = (unsigned short)(report -> record_size); }
    {void * tlv28; tlv28 = (void *)(report -> record_size); }
    {char * tlv30; tlv30 = (char *)(report -> record_size); }
    {char* tlv29 ; tlv29  = (char*)(report -> record_size); }
    {char * command; command = (char *)(report -> record_size); }
    {int tlv5; tlv5 = (int)(report -> record_size); }
    {char * tlv33; tlv33 = (char *)(report -> record_size); }
    {void * tlv37; tlv37 = (void *)(report -> record_size); }
    {char * tlv39; tlv39 = (char *)(report -> record_size); }
    {char* tlv38 ; tlv38  = (char*)(report -> record_size); }
}
void fix_ingred_service_6_4(){
fix_ingred_service_6_4_0();
fix_ingred_service_6_4_1();
fix_ingred_service_6_4_2();
}
void fix_ingred_service_6_5_0(){
Field nextField_ref;
    bzero(&nextField_ref,1*sizeof(Field));
Field * nextField = &nextField_ref;
    {short second_field_size; second_field_size = (short)(nextField -> size); }
    {char * receive_buf; receive_buf = (char *)(nextField -> size); }
    {short field_index; field_index = (short)(nextField -> size); }
    {int tlv1; tlv1 = (int)(nextField -> size); }
    {cgc_size_t tlv9; tlv9 = (cgc_size_t)(nextField -> size); }
    {cgc_size_t tlv10; tlv10 = (cgc_size_t)(nextField -> size); }
    {cgc_size_t tlv11; tlv11 = (cgc_size_t)(nextField -> size); }
    {void * tlv8; tlv8 = (void *)(nextField -> size); }
    {char tlv7; tlv7 = (char)(nextField -> size); }
    {cgc_size_t tlv6; tlv6 = (cgc_size_t)(nextField -> size); }
    {char * tlv13; tlv13 = (char *)(nextField -> size); }
    {char* tlv12 ; tlv12  = (char*)(nextField -> size); }
    {int tlv2; tlv2 = (int)(nextField -> size); }
    {void * tlv16; tlv16 = (void *)(nextField -> size); }
    {char tlv15; tlv15 = (char)(nextField -> size); }
    {cgc_size_t tlv14; tlv14 = (cgc_size_t)(nextField -> size); }
    {int tlv19; tlv19 = (int)(nextField -> size); }
    {char * tlv18; tlv18 = (char *)(nextField -> size); }
    {cgc_size_t tlv17; tlv17 = (cgc_size_t)(nextField -> size); }
    {char * tlv21; tlv21 = (char *)(nextField -> size); }
    {char * tlv20; tlv20 = (char *)(nextField -> size); }
    {void * tlv22; tlv22 = (void *)(nextField -> size); }
    {char * tlv24; tlv24 = (char *)(nextField -> size); }
    {char* tlv23 ; tlv23  = (char*)(nextField -> size); }
    {int tlv3; tlv3 = (int)(nextField -> size); }
    {void * tlv25; tlv25 = (void *)(nextField -> size); }
    {char * tlv27; tlv27 = (char *)(nextField -> size); }
    {char* tlv26 ; tlv26  = (char*)(nextField -> size); }
    {unsigned short field_index; field_index = (unsigned short)(nextField -> size); }
    {int tlv4; tlv4 = (int)(nextField -> size); }
    {void * tlv28; tlv28 = (void *)(nextField -> size); }
    {char * tlv30; tlv30 = (char *)(nextField -> size); }
    {char* tlv29 ; tlv29  = (char*)(nextField -> size); }
    {char * command; command = (char *)(nextField -> size); }
    {int tlv5; tlv5 = (int)(nextField -> size); }
    {char * tlv33; tlv33 = (char *)(nextField -> size); }
    {void * tlv37; tlv37 = (void *)(nextField -> size); }
    {char * tlv39; tlv39 = (char *)(nextField -> size); }
    {char* tlv38 ; tlv38  = (char*)(nextField -> size); }
}
void fix_ingred_service_6_5(){
fix_ingred_service_6_5_0();
}
void fix_ingred_service_6_6_0(){
char receive_buf_ref;
    bzero(&receive_buf_ref,1*sizeof(char));
char * receive_buf = &receive_buf_ref;
    {short second_field_size; second_field_size = (short)(receive_buf); }
    {short field_index; field_index = (short)(receive_buf); }
    {int tlv1; tlv1 = (int)(receive_buf); }
    {cgc_size_t tlv9; tlv9 = (cgc_size_t)(receive_buf); }
    {cgc_size_t tlv10; tlv10 = (cgc_size_t)(receive_buf); }
    {cgc_size_t tlv11; tlv11 = (cgc_size_t)(receive_buf); }
    {void * tlv8; tlv8 = (void *)(receive_buf); }
    {char tlv7; tlv7 = (char)(receive_buf); }
    {cgc_size_t tlv6; tlv6 = (cgc_size_t)(receive_buf); }
    {char * tlv13; tlv13 = (char *)(receive_buf); }
    {char* tlv12 ; tlv12  = (char*)(receive_buf); }
    {int tlv2; tlv2 = (int)(receive_buf); }
    {void * tlv16; tlv16 = (void *)(receive_buf); }
    {char tlv15; tlv15 = (char)(receive_buf); }
    {cgc_size_t tlv14; tlv14 = (cgc_size_t)(receive_buf); }
    {int tlv19; tlv19 = (int)(receive_buf); }
    {char * tlv18; tlv18 = (char *)(receive_buf); }
    {cgc_size_t tlv17; tlv17 = (cgc_size_t)(receive_buf); }
    {char * tlv21; tlv21 = (char *)(receive_buf); }
    {char * tlv20; tlv20 = (char *)(receive_buf); }
    {void * tlv22; tlv22 = (void *)(receive_buf); }
    {char * tlv24; tlv24 = (char *)(receive_buf); }
    {char* tlv23 ; tlv23  = (char*)(receive_buf); }
    {int tlv3; tlv3 = (int)(receive_buf); }
    {void * tlv25; tlv25 = (void *)(receive_buf); }
    {char * tlv27; tlv27 = (char *)(receive_buf); }
    {char* tlv26 ; tlv26  = (char*)(receive_buf); }
    {unsigned short field_index; field_index = (unsigned short)(receive_buf); }
    {int tlv4; tlv4 = (int)(receive_buf); }
    {void * tlv28; tlv28 = (void *)(receive_buf); }
    {char * tlv30; tlv30 = (char *)(receive_buf); }
    {char* tlv29 ; tlv29  = (char*)(receive_buf); }
    {char * command; command = (char *)(receive_buf); }
    {int tlv5; tlv5 = (int)(receive_buf); }
    {char * tlv33; tlv33 = (char *)(receive_buf); }
    {void * tlv37; tlv37 = (void *)(receive_buf); }
    {char * tlv39; tlv39 = (char *)(receive_buf); }
    {char* tlv38 ; tlv38  = (char*)(receive_buf); }
}
void fix_ingred_service_6_6(){
fix_ingred_service_6_6_0();
}
void fix_ingred_service_6_7_0(){
char receive_buf_ref;
    bzero(&receive_buf_ref,1*sizeof(char));
char * receive_buf = &receive_buf_ref;
Field nextField_ref;
    bzero(&nextField_ref,1*sizeof(Field));
Field * nextField = &nextField_ref;
    {short second_field_size; second_field_size = (short)(STDIN); }
    {char * receive_buf; receive_buf = (char *)(STDIN); }
    {short field_index; field_index = (short)(STDIN); }
    {int tlv1; tlv1 = (int)(STDIN); }
    {cgc_size_t tlv9; tlv9 = (cgc_size_t)(STDIN); }
    {cgc_size_t tlv10; tlv10 = (cgc_size_t)(STDIN); }
    {cgc_size_t tlv11; tlv11 = (cgc_size_t)(STDIN); }
    {void * tlv8; tlv8 = (void *)(STDIN); }
    {char tlv7; tlv7 = (char)(STDIN); }
    {cgc_size_t tlv6; tlv6 = (cgc_size_t)(STDIN); }
    {char * tlv13; tlv13 = (char *)(STDIN); }
    {char* tlv12 ; tlv12  = (char*)(STDIN); }
    {int tlv2; tlv2 = (int)(STDIN); }
    {void * tlv16; tlv16 = (void *)(STDIN); }
    {char tlv15; tlv15 = (char)(STDIN); }
    {cgc_size_t tlv14; tlv14 = (cgc_size_t)(STDIN); }
    {int tlv19; tlv19 = (int)(STDIN); }
    {char * tlv18; tlv18 = (char *)(STDIN); }
    {cgc_size_t tlv17; tlv17 = (cgc_size_t)(STDIN); }
    {char * tlv21; tlv21 = (char *)(STDIN); }
    {char * tlv20; tlv20 = (char *)(STDIN); }
    {void * tlv22; tlv22 = (void *)(STDIN); }
    {char * tlv24; tlv24 = (char *)(STDIN); }
    {char* tlv23 ; tlv23  = (char*)(STDIN); }
    {int tlv3; tlv3 = (int)(STDIN); }
    {void * tlv25; tlv25 = (void *)(STDIN); }
    {char * tlv27; tlv27 = (char *)(STDIN); }
    {char* tlv26 ; tlv26  = (char*)(STDIN); }
    {unsigned short field_index; field_index = (unsigned short)(STDIN); }
    {void * tlv28; tlv28 = (void *)(STDIN); }
    {char * tlv30; tlv30 = (char *)(STDIN); }
    {char* tlv29 ; tlv29  = (char*)(STDIN); }
    {char * command; command = (char *)(STDIN); }
    {int tlv5; tlv5 = (int)(STDIN); }
    {char * tlv33; tlv33 = (char *)(STDIN); }
    {void * tlv37; tlv37 = (void *)(STDIN); }
    {char * tlv39; tlv39 = (char *)(STDIN); }
    {char* tlv38 ; tlv38  = (char*)(STDIN); }
}
void fix_ingred_service_6_7_1(){
char receive_buf_ref;
    bzero(&receive_buf_ref,1*sizeof(char));
char * receive_buf = &receive_buf_ref;
Field nextField_ref;
    bzero(&nextField_ref,1*sizeof(Field));
Field * nextField = &nextField_ref;
    {short second_field_size; second_field_size = (short)(receive_buf); }
    {short field_index; field_index = (short)(receive_buf); }
    {int tlv1; tlv1 = (int)(receive_buf); }
    {cgc_size_t tlv9; tlv9 = (cgc_size_t)(receive_buf); }
    {cgc_size_t tlv10; tlv10 = (cgc_size_t)(receive_buf); }
    {cgc_size_t tlv11; tlv11 = (cgc_size_t)(receive_buf); }
    {void * tlv8; tlv8 = (void *)(receive_buf); }
    {char tlv7; tlv7 = (char)(receive_buf); }
    {cgc_size_t tlv6; tlv6 = (cgc_size_t)(receive_buf); }
    {char * tlv13; tlv13 = (char *)(receive_buf); }
    {char* tlv12 ; tlv12  = (char*)(receive_buf); }
    {int tlv2; tlv2 = (int)(receive_buf); }
    {void * tlv16; tlv16 = (void *)(receive_buf); }
    {char tlv15; tlv15 = (char)(receive_buf); }
    {cgc_size_t tlv14; tlv14 = (cgc_size_t)(receive_buf); }
    {int tlv19; tlv19 = (int)(receive_buf); }
    {char * tlv18; tlv18 = (char *)(receive_buf); }
    {cgc_size_t tlv17; tlv17 = (cgc_size_t)(receive_buf); }
    {char * tlv21; tlv21 = (char *)(receive_buf); }
    {char * tlv20; tlv20 = (char *)(receive_buf); }
    {void * tlv22; tlv22 = (void *)(receive_buf); }
    {char * tlv24; tlv24 = (char *)(receive_buf); }
    {char* tlv23 ; tlv23  = (char*)(receive_buf); }
    {int tlv3; tlv3 = (int)(receive_buf); }
    {void * tlv25; tlv25 = (void *)(receive_buf); }
    {char * tlv27; tlv27 = (char *)(receive_buf); }
    {char* tlv26 ; tlv26  = (char*)(receive_buf); }
    {unsigned short field_index; field_index = (unsigned short)(receive_buf); }
    {int tlv4; tlv4 = (int)(receive_buf); }
    {void * tlv28; tlv28 = (void *)(receive_buf); }
    {char * tlv30; tlv30 = (char *)(receive_buf); }
    {char* tlv29 ; tlv29  = (char*)(receive_buf); }
    {char * command; command = (char *)(receive_buf); }
    {int tlv5; tlv5 = (int)(receive_buf); }
    {char * tlv33; tlv33 = (char *)(receive_buf); }
    {void * tlv37; tlv37 = (void *)(receive_buf); }
    {char * tlv39; tlv39 = (char *)(receive_buf); }
    {char* tlv38 ; tlv38  = (char*)(receive_buf); }
}
void fix_ingred_service_6_7_2(){
char receive_buf_ref;
    bzero(&receive_buf_ref,1*sizeof(char));
char * receive_buf = &receive_buf_ref;
Field nextField_ref;
    bzero(&nextField_ref,1*sizeof(Field));
Field * nextField = &nextField_ref;
    {short second_field_size; second_field_size = (short)(nextField -> size); }
    {char * receive_buf; receive_buf = (char *)(nextField -> size); }
    {short field_index; field_index = (short)(nextField -> size); }
    {int tlv1; tlv1 = (int)(nextField -> size); }
    {cgc_size_t tlv9; tlv9 = (cgc_size_t)(nextField -> size); }
    {cgc_size_t tlv10; tlv10 = (cgc_size_t)(nextField -> size); }
    {cgc_size_t tlv11; tlv11 = (cgc_size_t)(nextField -> size); }
    {void * tlv8; tlv8 = (void *)(nextField -> size); }
    {char tlv7; tlv7 = (char)(nextField -> size); }
    {cgc_size_t tlv6; tlv6 = (cgc_size_t)(nextField -> size); }
    {char * tlv13; tlv13 = (char *)(nextField -> size); }
    {char* tlv12 ; tlv12  = (char*)(nextField -> size); }
    {int tlv2; tlv2 = (int)(nextField -> size); }
    {void * tlv16; tlv16 = (void *)(nextField -> size); }
    {char tlv15; tlv15 = (char)(nextField -> size); }
    {cgc_size_t tlv14; tlv14 = (cgc_size_t)(nextField -> size); }
    {int tlv19; tlv19 = (int)(nextField -> size); }
    {char * tlv18; tlv18 = (char *)(nextField -> size); }
    {cgc_size_t tlv17; tlv17 = (cgc_size_t)(nextField -> size); }
    {char * tlv21; tlv21 = (char *)(nextField -> size); }
    {char * tlv20; tlv20 = (char *)(nextField -> size); }
    {void * tlv22; tlv22 = (void *)(nextField -> size); }
    {char * tlv24; tlv24 = (char *)(nextField -> size); }
    {char* tlv23 ; tlv23  = (char*)(nextField -> size); }
    {int tlv3; tlv3 = (int)(nextField -> size); }
    {void * tlv25; tlv25 = (void *)(nextField -> size); }
    {char * tlv27; tlv27 = (char *)(nextField -> size); }
    {char* tlv26 ; tlv26  = (char*)(nextField -> size); }
    {unsigned short field_index; field_index = (unsigned short)(nextField -> size); }
    {int tlv4; tlv4 = (int)(nextField -> size); }
    {void * tlv28; tlv28 = (void *)(nextField -> size); }
    {char * tlv30; tlv30 = (char *)(nextField -> size); }
    {char* tlv29 ; tlv29  = (char*)(nextField -> size); }
    {char * command; command = (char *)(nextField -> size); }
    {int tlv5; tlv5 = (int)(nextField -> size); }
    {char * tlv33; tlv33 = (char *)(nextField -> size); }
    {void * tlv37; tlv37 = (void *)(nextField -> size); }
    {char * tlv39; tlv39 = (char *)(nextField -> size); }
    {char* tlv38 ; tlv38  = (char*)(nextField -> size); }
}
void fix_ingred_service_6_7(){
fix_ingred_service_6_7_0();
fix_ingred_service_6_7_1();
fix_ingred_service_6_7_2();
}
void fix_ingred_service_6_9_0(){
Record record_ref;
    bzero(&record_ref,1*sizeof(Record));
Record * record = &record_ref;
    {short second_field_size; second_field_size = (short)(record -> data); }
    {char * receive_buf; receive_buf = (char *)(record -> data); }
    {short field_index; field_index = (short)(record -> data); }
    {int tlv1; tlv1 = (int)(record -> data); }
    {cgc_size_t tlv9; tlv9 = (cgc_size_t)(record -> data); }
    {cgc_size_t tlv10; tlv10 = (cgc_size_t)(record -> data); }
    {cgc_size_t tlv11; tlv11 = (cgc_size_t)(record -> data); }
    {void * tlv8; tlv8 = (void *)(record -> data); }
    {char tlv7; tlv7 = (char)(record -> data); }
    {cgc_size_t tlv6; tlv6 = (cgc_size_t)(record -> data); }
    {char * tlv13; tlv13 = (char *)(record -> data); }
    {char* tlv12 ; tlv12  = (char*)(record -> data); }
    {int tlv2; tlv2 = (int)(record -> data); }
    {void * tlv16; tlv16 = (void *)(record -> data); }
    {char tlv15; tlv15 = (char)(record -> data); }
    {cgc_size_t tlv14; tlv14 = (cgc_size_t)(record -> data); }
    {int tlv19; tlv19 = (int)(record -> data); }
    {char * tlv18; tlv18 = (char *)(record -> data); }
    {cgc_size_t tlv17; tlv17 = (cgc_size_t)(record -> data); }
    {char * tlv21; tlv21 = (char *)(record -> data); }
    {char * tlv20; tlv20 = (char *)(record -> data); }
    {void * tlv22; tlv22 = (void *)(record -> data); }
    {char * tlv24; tlv24 = (char *)(record -> data); }
    {char* tlv23 ; tlv23  = (char*)(record -> data); }
    {int tlv3; tlv3 = (int)(record -> data); }
    {void * tlv25; tlv25 = (void *)(record -> data); }
    {char * tlv27; tlv27 = (char *)(record -> data); }
    {char* tlv26 ; tlv26  = (char*)(record -> data); }
    {unsigned short field_index; field_index = (unsigned short)(record -> data); }
    {int tlv4; tlv4 = (int)(record -> data); }
    {void * tlv28; tlv28 = (void *)(record -> data); }
    {char * tlv30; tlv30 = (char *)(record -> data); }
    {char* tlv29 ; tlv29  = (char*)(record -> data); }
    {char * command; command = (char *)(record -> data); }
    {int tlv5; tlv5 = (int)(record -> data); }
    {char * tlv33; tlv33 = (char *)(record -> data); }
    {void * tlv37; tlv37 = (void *)(record -> data); }
    {char * tlv39; tlv39 = (char *)(record -> data); }
    {char* tlv38 ; tlv38  = (char*)(record -> data); }
}
void fix_ingred_service_6_9(){
fix_ingred_service_6_9_0();
}
void fix_ingred_service_6_20_11(){
unsigned short field_index;
    bzero(&field_index,sizeof(unsigned short));
    {short second_field_size; second_field_size = (short)(field_index); }
    {char * receive_buf; receive_buf = (char *)(field_index); }
    {int tlv1; tlv1 = (int)(field_index); }
    {cgc_size_t tlv9; tlv9 = (cgc_size_t)(field_index); }
    {cgc_size_t tlv10; tlv10 = (cgc_size_t)(field_index); }
    {cgc_size_t tlv11; tlv11 = (cgc_size_t)(field_index); }
    {void * tlv8; tlv8 = (void *)(field_index); }
    {char tlv7; tlv7 = (char)(field_index); }
    {cgc_size_t tlv6; tlv6 = (cgc_size_t)(field_index); }
    {char * tlv13; tlv13 = (char *)(field_index); }
    {char* tlv12 ; tlv12  = (char*)(field_index); }
    {int tlv2; tlv2 = (int)(field_index); }
    {void * tlv16; tlv16 = (void *)(field_index); }
    {char tlv15; tlv15 = (char)(field_index); }
    {cgc_size_t tlv14; tlv14 = (cgc_size_t)(field_index); }
    {int tlv19; tlv19 = (int)(field_index); }
    {char * tlv18; tlv18 = (char *)(field_index); }
    {cgc_size_t tlv17; tlv17 = (cgc_size_t)(field_index); }
    {char * tlv21; tlv21 = (char *)(field_index); }
    {char * tlv20; tlv20 = (char *)(field_index); }
    {void * tlv22; tlv22 = (void *)(field_index); }
    {char * tlv24; tlv24 = (char *)(field_index); }
    {char* tlv23 ; tlv23  = (char*)(field_index); }
    {int tlv3; tlv3 = (int)(field_index); }
    {void * tlv25; tlv25 = (void *)(field_index); }
    {char * tlv27; tlv27 = (char *)(field_index); }
    {char* tlv26 ; tlv26  = (char*)(field_index); }
    {int tlv4; tlv4 = (int)(field_index); }
    {void * tlv28; tlv28 = (void *)(field_index); }
    {char * tlv30; tlv30 = (char *)(field_index); }
    {char* tlv29 ; tlv29  = (char*)(field_index); }
    {char * command; command = (char *)(field_index); }
    {int tlv5; tlv5 = (int)(field_index); }
    {char * tlv33; tlv33 = (char *)(field_index); }
    {void * tlv37; tlv37 = (void *)(field_index); }
    {char * tlv39; tlv39 = (char *)(field_index); }
    {char* tlv38 ; tlv38  = (char*)(field_index); }
}
void fix_ingred_service_6_20_12(){
unsigned short field_index;
    bzero(&field_index,sizeof(unsigned short));
    {short second_field_size; second_field_size = (short)(0); }
    {char * receive_buf; receive_buf = (char *)(0); }
    {short field_index; field_index = (short)(0); }
    {int tlv1; tlv1 = (int)(0); }
    {cgc_size_t tlv9; tlv9 = (cgc_size_t)(0); }
    {cgc_size_t tlv10; tlv10 = (cgc_size_t)(0); }
    {cgc_size_t tlv11; tlv11 = (cgc_size_t)(0); }
    {void * tlv8; tlv8 = (void *)(0); }
    {char tlv7; tlv7 = (char)(0); }
    {cgc_size_t tlv6; tlv6 = (cgc_size_t)(0); }
    {char * tlv13; tlv13 = (char *)(0); }
    {char* tlv12 ; tlv12  = (char*)(0); }
    {int tlv2; tlv2 = (int)(0); }
    {void * tlv16; tlv16 = (void *)(0); }
    {char tlv15; tlv15 = (char)(0); }
    {cgc_size_t tlv14; tlv14 = (cgc_size_t)(0); }
    {int tlv19; tlv19 = (int)(0); }
    {char * tlv18; tlv18 = (char *)(0); }
    {cgc_size_t tlv17; tlv17 = (cgc_size_t)(0); }
    {char * tlv21; tlv21 = (char *)(0); }
    {char * tlv20; tlv20 = (char *)(0); }
    {void * tlv22; tlv22 = (void *)(0); }
    {char * tlv24; tlv24 = (char *)(0); }
    {char* tlv23 ; tlv23  = (char*)(0); }
    {int tlv3; tlv3 = (int)(0); }
    {void * tlv25; tlv25 = (void *)(0); }
    {char * tlv27; tlv27 = (char *)(0); }
    {char* tlv26 ; tlv26  = (char*)(0); }
    {unsigned short field_index; field_index = (unsigned short)(0); }
    {int tlv4; tlv4 = (int)(0); }
    {void * tlv28; tlv28 = (void *)(0); }
    {char * tlv30; tlv30 = (char *)(0); }
    {char* tlv29 ; tlv29  = (char*)(0); }
    {char * command; command = (char *)(0); }
    {int tlv5; tlv5 = (int)(0); }
    {char * tlv33; tlv33 = (char *)(0); }
    {void * tlv37; tlv37 = (void *)(0); }
    {char * tlv39; tlv39 = (char *)(0); }
    {char* tlv38 ; tlv38  = (char*)(0); }
}
void fix_ingred_service_6_20(){
fix_ingred_service_6_20_11();
fix_ingred_service_6_20_12();
}
void fix_ingred_service_6_31_0(){
char command_ref;
    bzero(&command_ref,1*sizeof(char));
char * command = &command_ref;
    {short second_field_size; second_field_size = (short)(command); }
    {char * receive_buf; receive_buf = (char *)(command); }
    {short field_index; field_index = (short)(command); }
    {int tlv1; tlv1 = (int)(command); }
    {cgc_size_t tlv9; tlv9 = (cgc_size_t)(command); }
    {cgc_size_t tlv10; tlv10 = (cgc_size_t)(command); }
    {cgc_size_t tlv11; tlv11 = (cgc_size_t)(command); }
    {void * tlv8; tlv8 = (void *)(command); }
    {char tlv7; tlv7 = (char)(command); }
    {cgc_size_t tlv6; tlv6 = (cgc_size_t)(command); }
    {char * tlv13; tlv13 = (char *)(command); }
    {char* tlv12 ; tlv12  = (char*)(command); }
    {int tlv2; tlv2 = (int)(command); }
    {void * tlv16; tlv16 = (void *)(command); }
    {char tlv15; tlv15 = (char)(command); }
    {cgc_size_t tlv14; tlv14 = (cgc_size_t)(command); }
    {int tlv19; tlv19 = (int)(command); }
    {char * tlv18; tlv18 = (char *)(command); }
    {cgc_size_t tlv17; tlv17 = (cgc_size_t)(command); }
    {char * tlv21; tlv21 = (char *)(command); }
    {char * tlv20; tlv20 = (char *)(command); }
    {void * tlv22; tlv22 = (void *)(command); }
    {char * tlv24; tlv24 = (char *)(command); }
    {char* tlv23 ; tlv23  = (char*)(command); }
    {int tlv3; tlv3 = (int)(command); }
    {void * tlv25; tlv25 = (void *)(command); }
    {char * tlv27; tlv27 = (char *)(command); }
    {char* tlv26 ; tlv26  = (char*)(command); }
    {unsigned short field_index; field_index = (unsigned short)(command); }
    {int tlv4; tlv4 = (int)(command); }
    {void * tlv28; tlv28 = (void *)(command); }
    {char * tlv30; tlv30 = (char *)(command); }
    {char* tlv29 ; tlv29  = (char*)(command); }
    {int tlv5; tlv5 = (int)(command); }
    {char * tlv33; tlv33 = (char *)(command); }
    {void * tlv37; tlv37 = (void *)(command); }
    {char * tlv39; tlv39 = (char *)(command); }
    {char* tlv38 ; tlv38  = (char*)(command); }
}
void fix_ingred_service_6_31(){
fix_ingred_service_6_31_0();
}
void fix_ingred_service_6(){
fix_ingred_service_6_0();
fix_ingred_service_6_1();
fix_ingred_service_6_2();
fix_ingred_service_6_4();
fix_ingred_service_6_5();
fix_ingred_service_6_6();
fix_ingred_service_6_7();
fix_ingred_service_6_9();
fix_ingred_service_6_20();
fix_ingred_service_6_31();
}
void fix_ingred_service_7_0_0(){
    {char * field; field = (char *)(NULL); }
}
void fix_ingred_service_7_0(){
fix_ingred_service_7_0_0();
}
void fix_ingred_service_7(){
fix_ingred_service_7_0();
}
