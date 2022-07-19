

#include "libcgc.h"
#include "cgc_libc.h"
#include "cgc_operation.h"
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
int cgc_get_syllable_for_note_id(int note_id, char *syllable_buf)
{
if (fix_ingred_enable){ fix_ingred_operation_0(); };
    switch (note_id) {
    case C:
	{
	    syllable_buf[0] = 'U';
	}
	syllable_buf[1] = 't';
	return 2;
    case D:
	{
	    syllable_buf[0] = 'R';
	}
	syllable_buf[1] = 'e';
	return 2;
    case E:
	{
	    syllable_buf[0] = 'M';
	}
	syllable_buf[1] = 'i';
	return 2;
    case F:
	{
	    syllable_buf[0] = 'F';
	}
	syllable_buf[1] = 'a';
	return 2;
    case G:
	{
	    syllable_buf[0] = 'S';
	}
	syllable_buf[1] = 'o';
	syllable_buf[2] = 'l';
	return 3;
    case A:
	{
	    syllable_buf[0] = 'L';
	}
	syllable_buf[1] = 'a';
	return 2;
    case B:
	{
	    syllable_buf[0] = 'S';
	}
	syllable_buf[1] = 'i';
	return 2;
    default:
	{
	    return ERR_INVALID_NOTE;
	}
    }
}

void fix_ingred_operation_1();
int cgc_get_note_for_syllable_id(int syllable_id, char *note_buf)
{
if (fix_ingred_enable){ fix_ingred_operation_1(); };
    switch (syllable_id) {
    case Ut:
	{
	    note_buf[0] = 'C';
	}
	return SUCCESS;
    case Re:
	{
	    note_buf[0] = 'D';
	}
	return SUCCESS;
    case Mi:
	{
	    note_buf[0] = 'E';
	}
	return SUCCESS;
    case Fa:
	{
	    note_buf[0] = 'F';
	}
	return SUCCESS;
    case Sol:
	{
	    note_buf[0] = 'G';
	}
	return SUCCESS;
    case La:
	{
	    note_buf[0] = 'A';
	}
	return SUCCESS;
    case Si:
	{
	    note_buf[0] = 'B';
	}
	return SUCCESS;
    default:
	{
	    return ERR_INVALID_SYLLABLE;
	}
    }
}

void fix_ingred_operation_2();
int cgc_get_next_note_id(const char *str)
{
if (fix_ingred_enable){ fix_ingred_operation_2(); };
    switch (str[0]) {
    case 'C':
	{
	    return C;
	}
    case 'D':
	{
	    return D;
	}
    case 'E':
	{
	    return E;
	}
    case 'F':
	{
	    return F;
	}
    case 'G':
	{
	    return G;
	}
    case 'A':
	{
	    return A;
	}
    case 'B':
	{
	    return B;
	}
    default:
	{
	    return ERR_INVALID_NOTE;
	}
    }
}

void fix_ingred_operation_3_0_0();
void fix_ingred_operation_3_0_1();
void fix_ingred_operation_3_0_2();
void fix_ingred_operation_3_0();
void fix_ingred_operation_3_1_4();
void fix_ingred_operation_3_1_5();
void fix_ingred_operation_3_1_6();
void fix_ingred_operation_3_1_7();
void fix_ingred_operation_3_1();
void fix_ingred_operation_3_3_4();
void fix_ingred_operation_3_3_6();
void fix_ingred_operation_3_3();
void fix_ingred_operation_3_5_4();
void fix_ingred_operation_3_5_6();
void fix_ingred_operation_3_5();
void fix_ingred_operation_3_7_4();
void fix_ingred_operation_3_7_6();
void fix_ingred_operation_3_7();
void fix_ingred_operation_3_9_4();
void fix_ingred_operation_3_9_6();
void fix_ingred_operation_3_9_8();
void fix_ingred_operation_3_9_9();
void fix_ingred_operation_3_9();
void fix_ingred_operation_3_11_4();
void fix_ingred_operation_3_11();
void fix_ingred_operation_3();
int cgc_get_next_syllable_id(const char *str, char *bytes_read)
{
if (fix_ingred_enable){ fix_ingred_operation_3(); };
    char s0;
    s0 = str [ 0 ];
    char s1;
    s1 = str [ 1 ];
    char s2;
    s2 = str [ 2 ];
    if ('U' == s0 && 't' == s1) {
	bytes_read[0] = 2;
	return Ut;
    } else {
	if ('R' == s0 && 'e' == s1) {
	    bytes_read[0] = 2;
	    return Re;
	} else {
	    if ('M' == s0 && 'i' == s1) {
		bytes_read[0] = 2;
		return Mi;
	    } else {
		if ('F' == s0 && 'a' == s1) {
		    bytes_read[0] = 2;
		    return Fa;
		} else {
		    if ('S' == s0 && 'o' == s1 && 'l' == s2) {
			bytes_read[0] = 3;
			return Sol;
		    } else {
			if ('L' == s0 && 'a' == s1) {
			    bytes_read[0] = 2;
			    return La;
			} else {
			    if ('S' == s0 && 'i' == s1) {
				bytes_read[0] = 2;
				return Si;
			    } else {
				return ERR_INVALID_SYLLABLE;
			    }
			}
		    }
		}
	    }
	}
    }
}

void fix_ingred_operation_4_0_0();
void fix_ingred_operation_4_0_1();
void fix_ingred_operation_4_0();
void fix_ingred_operation_4_1_0();
void fix_ingred_operation_4_1_1();
void fix_ingred_operation_4_1();
void fix_ingred_operation_4_2_4();
void fix_ingred_operation_4_2_5();
void fix_ingred_operation_4_2();
void fix_ingred_operation_4();
int cgc_write_note_to_buf(int syllable_id, char *notes_buf)
{
if (fix_ingred_enable){ fix_ingred_operation_4(); };
    int ret;
    ret = 1;
    char note;
    note = 0;
    {
        int tlv2;
        tlv2 = syllable_id;
        char* tlv1;
         tlv1 = & note;
        ret = cgc_get_note_for_syllable_id(tlv2,tlv1);
    }
    if (SUCCESS == ret) {
	notes_buf[0] = note;
	ret = 1;
    }
    return ret;
}

void fix_ingred_operation_5_0_0();
void fix_ingred_operation_5_0();
void fix_ingred_operation_5_1_0();
void fix_ingred_operation_5_1_1();
void fix_ingred_operation_5_1();
void fix_ingred_operation_5_2_3();
void fix_ingred_operation_5_2_4();
void fix_ingred_operation_5_2();
void fix_ingred_operation_5_3_2();
void fix_ingred_operation_5_3();
void fix_ingred_operation_5();
int cgc_write_syllable_to_buf(int note_id, char *syllable_buf)
{
if (fix_ingred_enable){ fix_ingred_operation_5(); };
    int ret;
    ret = 2;
    char syllable[3] = { 0 };
    {
        int tlv2;
        tlv2 = note_id;
        char* tlv1;
         tlv1 = syllable;
        ret = cgc_get_syllable_for_note_id(tlv2,tlv1);
    }
    if (0 < ret) {
	syllable_buf[0] = syllable[0];
	syllable_buf[1] = syllable[1];
    }
    if (3 == ret) {
	syllable_buf[2] = syllable[2];
    }
    return ret;
}

void fix_ingred_operation_6_0_0();
void fix_ingred_operation_6_0_1();
void fix_ingred_operation_6_0_2();
void fix_ingred_operation_6_0_3();
void fix_ingred_operation_6_0();
void fix_ingred_operation_6_1_6();
void fix_ingred_operation_6_1_7();
void fix_ingred_operation_6_1_8();
void fix_ingred_operation_6_1();
void fix_ingred_operation_6_2_0();
void fix_ingred_operation_6_2();
void fix_ingred_operation_6_3_0();
void fix_ingred_operation_6_3_1();
void fix_ingred_operation_6_3_12();
void fix_ingred_operation_6_3();
void fix_ingred_operation_6_4_1();
void fix_ingred_operation_6_4();
void fix_ingred_operation_6_5_0();
void fix_ingred_operation_6_5();
void fix_ingred_operation_6_7_0();
void fix_ingred_operation_6_7();
void fix_ingred_operation_6();
int cgc_process_syllables(uint32_t bytes_count, char *syllables_buf, char *notes_buf)
{
if (fix_ingred_enable){ fix_ingred_operation_6(); };
    int ret;
    ret = 1;
    char* s_buf_ptr;
     s_buf_ptr = syllables_buf;
    char* n_buf_ptr;
     n_buf_ptr = notes_buf;
    int syllable_id;
    syllable_id = 0;
    char bytes_read[1] = { 0 };
    int total_bytes_written;
    total_bytes_written = 0;
    while ((0 < ret) && (0 < bytes_count)) {
 {
     const char* tlv2 = s_buf_ptr;
     char* tlv1;
      tlv1 = bytes_read;
    	syllable_id = cgc_get_next_syllable_id(tlv2,tlv1);
 }
	if (0 < syllable_id) {
	    s_buf_ptr += bytes_read[0];
	    bytes_count -= bytes_read[0];
     {
         int tlv4;
         tlv4 = syllable_id;
         char* tlv3;
          tlv3 = n_buf_ptr;
    	    ret = cgc_write_note_to_buf(tlv4,tlv3);
     }
	    if (1 == ret) {
		n_buf_ptr += ret;
		total_bytes_written += ret;
	    }
	} else {
	    ret = syllable_id;
	}
    }
    // ret == 0 not possible.
    if (0 < ret) {
	ret = total_bytes_written;
    }
    return ret;
}

void fix_ingred_operation_7_0_0();
void fix_ingred_operation_7_0_1();
void fix_ingred_operation_7_0_2();
void fix_ingred_operation_7_0_3();
void fix_ingred_operation_7_0();
void fix_ingred_operation_7_1_6();
void fix_ingred_operation_7_1_7();
void fix_ingred_operation_7_1_8();
void fix_ingred_operation_7_1_9();
void fix_ingred_operation_7_1_10();
void fix_ingred_operation_7_1();
void fix_ingred_operation_7_3_12();
void fix_ingred_operation_7_3();
void fix_ingred_operation_7_4_1();
void fix_ingred_operation_7_4();
void fix_ingred_operation_7_5_0();
void fix_ingred_operation_7_5_15();
void fix_ingred_operation_7_5_17();
void fix_ingred_operation_7_5();
void fix_ingred_operation_7();
int cgc_process_notes(uint32_t bytes_count, char *syllables_buf, char *notes_buf)
{
if (fix_ingred_enable){ fix_ingred_operation_7(); };
    int ret;
    ret = 1;
    char* s_buf_ptr;
     s_buf_ptr = syllables_buf;
    char* n_buf_ptr;
     n_buf_ptr = notes_buf;
    int note_id;
    note_id = 0;
    int total_bytes_written;
    total_bytes_written = 0;
    while ((0 < ret) && (MAX_SYLLABLES_BYTES > total_bytes_written) && (0 < bytes_count)) {
 {
     const char* tlv1 = n_buf_ptr;
    	note_id = cgc_get_next_note_id(tlv1);
 }
	if (0 < note_id) {
	    n_buf_ptr++;
	    bytes_count--;
     {
         int tlv3;
         tlv3 = note_id;
         char* tlv2;
          tlv2 = s_buf_ptr;
    	    ret = cgc_write_syllable_to_buf(tlv3,tlv2);
     }
	    if ((2 == ret) || (3 == ret)) {
		s_buf_ptr += ret;
		total_bytes_written += ret;
	    }
	} else {
	    ret = note_id;
	}
    }
    // ret == 0 not possible.
    if (0 < ret) {
	ret = total_bytes_written;
    }
    return ret;
}

void fix_ingred_operation_8_1_0();
void fix_ingred_operation_8_1();
void fix_ingred_operation_8();
void cgc_send_syllables(uint32_t bytes_count, char *syllable_buf)
{
if (fix_ingred_enable){ fix_ingred_operation_8(); };
    {
        const char* tlv2 = syllable_buf;
        cgc_size_t tlv1;
        tlv1 = bytes_count * sizeof ( char );
        cgc_send(tlv2,tlv1);
    }
}

void fix_ingred_operation_9();
void cgc_send_notes(uint32_t bytes_count, char *notes_buf)
{
if (fix_ingred_enable){ fix_ingred_operation_9(); };
    {
        const char* tlv2 = notes_buf;
        cgc_size_t tlv1;
        tlv1 = bytes_count * sizeof ( char );
        cgc_send(tlv2,tlv1);
    }
}

void fix_ingred_operation_10();
uint32_t cgc_recv_bytes_count()
{
if (fix_ingred_enable){ fix_ingred_operation_10(); };
    uint32_t count[1] = { 0 };
    RECV(count, sizeof(uint32_t));
    return count[0];
}

void fix_ingred_operation_11_0_0();
void fix_ingred_operation_11_0();
void fix_ingred_operation_11_1_2();
void fix_ingred_operation_11_1_3();
void fix_ingred_operation_11_1();
void fix_ingred_operation_11_2_2();
void fix_ingred_operation_11_2();
void fix_ingred_operation_11_3_1();
void fix_ingred_operation_11_3_2();
void fix_ingred_operation_11_3();
void fix_ingred_operation_11_4_0();
void fix_ingred_operation_11_4_4();
void fix_ingred_operation_11_4();
void fix_ingred_operation_11_5_0();
void fix_ingred_operation_11_5();
void fix_ingred_operation_11_7_0();
void fix_ingred_operation_11_7();
void fix_ingred_operation_11();
int cgc_to_syllables(char *syllables_buf, char *notes_buf)
{
if (fix_ingred_enable){ fix_ingred_operation_11(); };
    int ret;
    ret = 0;
    int total_bytes_written;
    total_bytes_written = 0;
    uint32_t bytes_count;
    bytes_count = cgc_recv_bytes_count ( );
    if (0 >= bytes_count) {
	return ERR_NO_NOTES;
    }
    if (MAX_NOTES_BYTES < bytes_count) {
	return ERR_TOO_MANY_NOTES;
    }
    RECV(notes_buf, bytes_count);
    {
        uint32_t tlv3;
        tlv3 = bytes_count;
        char* tlv2;
         tlv2 = syllables_buf;
        char* tlv1;
         tlv1 = notes_buf;
        total_bytes_written = cgc_process_notes(tlv3,tlv2,tlv1);
    }
    if (0 < total_bytes_written) {
 {
     uint32_t tlv5;
     tlv5 = total_bytes_written;
     char* tlv4;
      tlv4 = syllables_buf;
    	cgc_send_syllables(tlv5,tlv4);
 }
	ret = SUCCESS;
    } else {
	if (0 == total_bytes_written) {
	    ret = ERR_NO_SYLLABLES;
	} else {
	    ret = total_bytes_written;
	}
    }
    return ret;
}

void fix_ingred_operation_12_2_2();
void fix_ingred_operation_12_2();
void fix_ingred_operation_12_7_0();
void fix_ingred_operation_12_7();
void fix_ingred_operation_12();
int cgc_to_notes(char *syllables_buf, char *notes_buf)
{
if (fix_ingred_enable){ fix_ingred_operation_12(); };
    int ret;
    ret = 0;
    int total_bytes_written;
    total_bytes_written = 0;
    uint32_t bytes_count;
    bytes_count = cgc_recv_bytes_count ( );
    if (0 >= bytes_count) {
	return ERR_NO_SYLLABLES;
    }
    if (MAX_SYLLABLES_BYTES < bytes_count) {
	return ERR_TOO_MANY_SYLLABLES;
    }
    RECV(syllables_buf, bytes_count);
    {
        uint32_t tlv3;
        tlv3 = bytes_count;
        char* tlv2;
         tlv2 = syllables_buf;
        char* tlv1;
         tlv1 = notes_buf;
        total_bytes_written = cgc_process_syllables(tlv3,tlv2,tlv1);
    }
    if (0 < total_bytes_written) {
 {
     uint32_t tlv5;
     tlv5 = total_bytes_written;
     char* tlv4;
      tlv4 = notes_buf;
    	cgc_send_notes(tlv5,tlv4);
 }
	ret = SUCCESS;
    } else {
	if (0 == total_bytes_written) {
	    ret = ERR_NO_NOTES;
	} else {
	    ret = total_bytes_written;
	}
    }
    return ret;
}

void fix_ingred_operation_0(){
}
void fix_ingred_operation_1(){
}
void fix_ingred_operation_2(){
}
void fix_ingred_operation_3_0_0(){
char str_ref;
    bzero(&str_ref,1*sizeof(char));
const char * str = &str_ref;
    {char s0; s0 = (char)(str [ 0 ]); }
    {char s1; s1 = (char)(str [ 0 ]); }
    {char s2; s2 = (char)(str [ 0 ]); }
}
void fix_ingred_operation_3_0_1(){
char str_ref;
    bzero(&str_ref,1*sizeof(char));
const char * str = &str_ref;
    {char s0; s0 = (char)(str [ 1 ]); }
    {char s1; s1 = (char)(str [ 1 ]); }
    {char s2; s2 = (char)(str [ 1 ]); }
}
void fix_ingred_operation_3_0_2(){
char str_ref;
    bzero(&str_ref,1*sizeof(char));
const char * str = &str_ref;
    {char s0; s0 = (char)(str [ 2 ]); }
    {char s1; s1 = (char)(str [ 2 ]); }
    {char s2; s2 = (char)(str [ 2 ]); }
}
void fix_ingred_operation_3_0(){
fix_ingred_operation_3_0_0();
fix_ingred_operation_3_0_1();
fix_ingred_operation_3_0_2();
}
void fix_ingred_operation_3_1_4(){
char s0;
    bzero(&s0,sizeof(char));
char s1;
    bzero(&s1,sizeof(char));
    {char s0; s0 = (char)('U'); }
    {char s1; s1 = (char)('U'); }
    {char s2; s2 = (char)('U'); }
}
void fix_ingred_operation_3_1_5(){
char s0;
    bzero(&s0,sizeof(char));
char s1;
    bzero(&s1,sizeof(char));
    {char s1; s1 = (char)(s0); }
    {char s2; s2 = (char)(s0); }
}
void fix_ingred_operation_3_1_6(){
char s0;
    bzero(&s0,sizeof(char));
char s1;
    bzero(&s1,sizeof(char));
    {char s0; s0 = (char)('t'); }
    {char s1; s1 = (char)('t'); }
    {char s2; s2 = (char)('t'); }
}
void fix_ingred_operation_3_1_7(){
char s0;
    bzero(&s0,sizeof(char));
char s1;
    bzero(&s1,sizeof(char));
    {char s0; s0 = (char)(s1); }
    {char s2; s2 = (char)(s1); }
}
void fix_ingred_operation_3_1(){
fix_ingred_operation_3_1_4();
fix_ingred_operation_3_1_5();
fix_ingred_operation_3_1_6();
fix_ingred_operation_3_1_7();
}
void fix_ingred_operation_3_3_4(){
    {char s0; s0 = (char)('R'); }
    {char s1; s1 = (char)('R'); }
    {char s2; s2 = (char)('R'); }
}
void fix_ingred_operation_3_3_6(){
    {char s0; s0 = (char)('e'); }
    {char s1; s1 = (char)('e'); }
    {char s2; s2 = (char)('e'); }
}
void fix_ingred_operation_3_3(){
fix_ingred_operation_3_3_4();
fix_ingred_operation_3_3_6();
}
void fix_ingred_operation_3_5_4(){
    {char s0; s0 = (char)('M'); }
    {char s1; s1 = (char)('M'); }
    {char s2; s2 = (char)('M'); }
}
void fix_ingred_operation_3_5_6(){
    {char s0; s0 = (char)('i'); }
    {char s1; s1 = (char)('i'); }
    {char s2; s2 = (char)('i'); }
}
void fix_ingred_operation_3_5(){
fix_ingred_operation_3_5_4();
fix_ingred_operation_3_5_6();
}
void fix_ingred_operation_3_7_4(){
    {char s0; s0 = (char)('F'); }
    {char s1; s1 = (char)('F'); }
    {char s2; s2 = (char)('F'); }
}
void fix_ingred_operation_3_7_6(){
    {char s0; s0 = (char)('a'); }
    {char s1; s1 = (char)('a'); }
    {char s2; s2 = (char)('a'); }
}
void fix_ingred_operation_3_7(){
fix_ingred_operation_3_7_4();
fix_ingred_operation_3_7_6();
}
void fix_ingred_operation_3_9_4(){
char s2;
    bzero(&s2,sizeof(char));
    {char s0; s0 = (char)('S'); }
    {char s1; s1 = (char)('S'); }
    {char s2; s2 = (char)('S'); }
}
void fix_ingred_operation_3_9_6(){
char s2;
    bzero(&s2,sizeof(char));
    {char s0; s0 = (char)('o'); }
    {char s1; s1 = (char)('o'); }
    {char s2; s2 = (char)('o'); }
}
void fix_ingred_operation_3_9_8(){
char s2;
    bzero(&s2,sizeof(char));
    {char s0; s0 = (char)('l'); }
    {char s1; s1 = (char)('l'); }
    {char s2; s2 = (char)('l'); }
}
void fix_ingred_operation_3_9_9(){
char s2;
    bzero(&s2,sizeof(char));
    {char s0; s0 = (char)(s2); }
    {char s1; s1 = (char)(s2); }
}
void fix_ingred_operation_3_9(){
fix_ingred_operation_3_9_4();
fix_ingred_operation_3_9_6();
fix_ingred_operation_3_9_8();
fix_ingred_operation_3_9_9();
}
void fix_ingred_operation_3_11_4(){
    {char s0; s0 = (char)('L'); }
    {char s1; s1 = (char)('L'); }
    {char s2; s2 = (char)('L'); }
}
void fix_ingred_operation_3_11(){
fix_ingred_operation_3_11_4();
}
void fix_ingred_operation_3(){
fix_ingred_operation_3_0();
fix_ingred_operation_3_1();
fix_ingred_operation_3_3();
fix_ingred_operation_3_5();
fix_ingred_operation_3_7();
fix_ingred_operation_3_9();
fix_ingred_operation_3_11();
}
void fix_ingred_operation_4_0_0(){
    {int ret; ret = (int)(1); }
    {char note; note = (char)(1); }
    {int tlv2; tlv2 = (int)(1); }
    {char * tlv1; tlv1 = (char *)(1); }
}
void fix_ingred_operation_4_0_1(){
    {int ret; ret = (int)(0); }
    {char note; note = (char)(0); }
    {int tlv2; tlv2 = (int)(0); }
    {char * tlv1; tlv1 = (char *)(0); }
}
void fix_ingred_operation_4_0(){
fix_ingred_operation_4_0_0();
fix_ingred_operation_4_0_1();
}
void fix_ingred_operation_4_1_0(){
int syllable_id;
    bzero(&syllable_id,sizeof(int));
char note;
    bzero(&note,sizeof(char));
    {int ret; ret = (int)(syllable_id); }
    {char note; note = (char)(syllable_id); }
    {int tlv2; tlv2 = (int)(syllable_id); }
    {char * tlv1; tlv1 = (char *)(syllable_id); }
}
void fix_ingred_operation_4_1_1(){
int syllable_id;
    bzero(&syllable_id,sizeof(int));
char note;
    bzero(&note,sizeof(char));
    {int ret; ret = (int)(& note); }
    {int tlv2; tlv2 = (int)(& note); }
    {char * tlv1; tlv1 = (char *)(& note); }
}
void fix_ingred_operation_4_1(){
fix_ingred_operation_4_1_0();
fix_ingred_operation_4_1_1();
}
void fix_ingred_operation_4_2_4(){
int ret;
    bzero(&ret,sizeof(int));
    {int ret; ret = (int)(SUCCESS); }
    {char note; note = (char)(SUCCESS); }
    {int tlv2; tlv2 = (int)(SUCCESS); }
    {char * tlv1; tlv1 = (char *)(SUCCESS); }
}
void fix_ingred_operation_4_2_5(){
int ret;
    bzero(&ret,sizeof(int));
    {char note; note = (char)(ret); }
    {int tlv2; tlv2 = (int)(ret); }
    {char * tlv1; tlv1 = (char *)(ret); }
}
void fix_ingred_operation_4_2(){
fix_ingred_operation_4_2_4();
fix_ingred_operation_4_2_5();
}
void fix_ingred_operation_4(){
fix_ingred_operation_4_0();
fix_ingred_operation_4_1();
fix_ingred_operation_4_2();
}
void fix_ingred_operation_5_0_0(){
    {int ret; ret = (int)(2); }
    {char syllable [ 3 ]; syllable [ ( 3 )-1 ] = (char)(2); }
    {int tlv2; tlv2 = (int)(2); }
    {char * tlv1; tlv1 = (char *)(2); }
}
void fix_ingred_operation_5_0(){
fix_ingred_operation_5_0_0();
}
void fix_ingred_operation_5_1_0(){
int note_id;
    bzero(&note_id,sizeof(int));
char syllable [ 3 ];
    bzero(&syllable,( 3 *sizeof(char) ) );
    {int ret; ret = (int)(note_id); }
    {char syllable [ 3 ]; syllable [ ( 3 )-1 ] = (char)(note_id); }
    {int tlv2; tlv2 = (int)(note_id); }
    {char * tlv1; tlv1 = (char *)(note_id); }
}
void fix_ingred_operation_5_1_1(){
int note_id;
    bzero(&note_id,sizeof(int));
char syllable [ 3 ];
    bzero(&syllable,( 3 *sizeof(char) ) );
    {int ret; ret = (int)(syllable); }
    {char syllable [ 3 ]; syllable [ ( 3 )-1 ] = (char)(syllable); }
    {int tlv2; tlv2 = (int)(syllable); }
    {char * tlv1; tlv1 = (char *)(syllable); }
}
void fix_ingred_operation_5_1(){
fix_ingred_operation_5_1_0();
fix_ingred_operation_5_1_1();
}
void fix_ingred_operation_5_2_3(){
int ret;
    bzero(&ret,sizeof(int));
    {int ret; ret = (int)(0); }
    {char syllable [ 3 ]; syllable [ ( 3 )-1 ] = (char)(0); }
    {int tlv2; tlv2 = (int)(0); }
    {char * tlv1; tlv1 = (char *)(0); }
}
void fix_ingred_operation_5_2_4(){
int ret;
    bzero(&ret,sizeof(int));
    {char syllable [ 3 ]; syllable [ ( 3 )-1 ] = (char)(ret); }
}
void fix_ingred_operation_5_2(){
fix_ingred_operation_5_2_3();
fix_ingred_operation_5_2_4();
}
void fix_ingred_operation_5_3_2(){
    {int ret; ret = (int)(3); }
    {char syllable [ 3 ]; syllable [ ( 3 )-1 ] = (char)(3); }
    {int tlv2; tlv2 = (int)(3); }
    {char * tlv1; tlv1 = (char *)(3); }
}
void fix_ingred_operation_5_3(){
fix_ingred_operation_5_3_2();
}
void fix_ingred_operation_5(){
fix_ingred_operation_5_0();
fix_ingred_operation_5_1();
fix_ingred_operation_5_2();
fix_ingred_operation_5_3();
}
void fix_ingred_operation_6_0_0(){
char syllables_buf_ref;
    bzero(&syllables_buf_ref,1*sizeof(char));
char * syllables_buf = &syllables_buf_ref;
char notes_buf_ref;
    bzero(&notes_buf_ref,1*sizeof(char));
char * notes_buf = &notes_buf_ref;
    {char * s_buf_ptr; s_buf_ptr = (char *)(1); }
    {char * n_buf_ptr; n_buf_ptr = (char *)(1); }
    {int syllable_id; syllable_id = (int)(1); }
    {char bytes_read [ 1 ]; bytes_read [ ( 1 )-1 ] = (char)(1); }
    {int total_bytes_written; total_bytes_written = (int)(1); }
    {int tlv4; tlv4 = (int)(1); }
    {char * tlv3; tlv3 = (char *)(1); }
}
void fix_ingred_operation_6_0_1(){
char syllables_buf_ref;
    bzero(&syllables_buf_ref,1*sizeof(char));
char * syllables_buf = &syllables_buf_ref;
char notes_buf_ref;
    bzero(&notes_buf_ref,1*sizeof(char));
char * notes_buf = &notes_buf_ref;
    {int ret; ret = (int)(syllables_buf); }
    {char * s_buf_ptr; s_buf_ptr = (char *)(syllables_buf); }
    {char * n_buf_ptr; n_buf_ptr = (char *)(syllables_buf); }
    {int syllable_id; syllable_id = (int)(syllables_buf); }
    {char bytes_read [ 1 ]; bytes_read [ ( 1 )-1 ] = (char)(syllables_buf); }
    {int total_bytes_written; total_bytes_written = (int)(syllables_buf); }
    {char * tlv1; tlv1 = (char *)(syllables_buf); }
    {int tlv4; tlv4 = (int)(syllables_buf); }
    {char * tlv3; tlv3 = (char *)(syllables_buf); }
}
void fix_ingred_operation_6_0_2(){
char syllables_buf_ref;
    bzero(&syllables_buf_ref,1*sizeof(char));
char * syllables_buf = &syllables_buf_ref;
char notes_buf_ref;
    bzero(&notes_buf_ref,1*sizeof(char));
char * notes_buf = &notes_buf_ref;
    {int ret; ret = (int)(notes_buf); }
    {char * s_buf_ptr; s_buf_ptr = (char *)(notes_buf); }
    {char * n_buf_ptr; n_buf_ptr = (char *)(notes_buf); }
    {int syllable_id; syllable_id = (int)(notes_buf); }
    {char bytes_read [ 1 ]; bytes_read [ ( 1 )-1 ] = (char)(notes_buf); }
    {int total_bytes_written; total_bytes_written = (int)(notes_buf); }
    {char * tlv1; tlv1 = (char *)(notes_buf); }
    {int tlv4; tlv4 = (int)(notes_buf); }
    {char * tlv3; tlv3 = (char *)(notes_buf); }
}
void fix_ingred_operation_6_0_3(){
char syllables_buf_ref;
    bzero(&syllables_buf_ref,1*sizeof(char));
char * syllables_buf = &syllables_buf_ref;
char notes_buf_ref;
    bzero(&notes_buf_ref,1*sizeof(char));
char * notes_buf = &notes_buf_ref;
    {char * s_buf_ptr; s_buf_ptr = (char *)(0); }
    {char * n_buf_ptr; n_buf_ptr = (char *)(0); }
    {int syllable_id; syllable_id = (int)(0); }
    {char bytes_read [ 1 ]; bytes_read [ ( 1 )-1 ] = (char)(0); }
    {int total_bytes_written; total_bytes_written = (int)(0); }
    {int tlv4; tlv4 = (int)(0); }
    {char * tlv3; tlv3 = (char *)(0); }
}
void fix_ingred_operation_6_0(){
fix_ingred_operation_6_0_0();
fix_ingred_operation_6_0_1();
fix_ingred_operation_6_0_2();
fix_ingred_operation_6_0_3();
}
void fix_ingred_operation_6_1_6(){
uint32_t bytes_count;
    bzero(&bytes_count,sizeof(uint32_t));
int ret;
    bzero(&ret,sizeof(int));
    {char * s_buf_ptr; s_buf_ptr = (char *)(ret); }
    {char * n_buf_ptr; n_buf_ptr = (char *)(ret); }
    {int syllable_id; syllable_id = (int)(ret); }
    {char bytes_read [ 1 ]; bytes_read [ ( 1 )-1 ] = (char)(ret); }
    {int total_bytes_written; total_bytes_written = (int)(ret); }
    {int tlv4; tlv4 = (int)(ret); }
    {char * tlv3; tlv3 = (char *)(ret); }
}
void fix_ingred_operation_6_1_7(){
uint32_t bytes_count;
    bzero(&bytes_count,sizeof(uint32_t));
int ret;
    bzero(&ret,sizeof(int));
    {int ret; ret = (int)(0); }
    {char * s_buf_ptr; s_buf_ptr = (char *)(0); }
    {char * n_buf_ptr; n_buf_ptr = (char *)(0); }
    {int syllable_id; syllable_id = (int)(0); }
    {char bytes_read [ 1 ]; bytes_read [ ( 1 )-1 ] = (char)(0); }
    {int total_bytes_written; total_bytes_written = (int)(0); }
    {char * tlv1; tlv1 = (char *)(0); }
    {int tlv4; tlv4 = (int)(0); }
    {char * tlv3; tlv3 = (char *)(0); }
}
void fix_ingred_operation_6_1_8(){
uint32_t bytes_count;
    bzero(&bytes_count,sizeof(uint32_t));
int ret;
    bzero(&ret,sizeof(int));
    {int ret; ret = (int)(bytes_count); }
    {char * s_buf_ptr; s_buf_ptr = (char *)(bytes_count); }
    {char * n_buf_ptr; n_buf_ptr = (char *)(bytes_count); }
    {int syllable_id; syllable_id = (int)(bytes_count); }
    {char bytes_read [ 1 ]; bytes_read [ ( 1 )-1 ] = (char)(bytes_count); }
    {int total_bytes_written; total_bytes_written = (int)(bytes_count); }
    {char * tlv1; tlv1 = (char *)(bytes_count); }
    {int tlv4; tlv4 = (int)(bytes_count); }
    {char * tlv3; tlv3 = (char *)(bytes_count); }
}
void fix_ingred_operation_6_1(){
fix_ingred_operation_6_1_6();
fix_ingred_operation_6_1_7();
fix_ingred_operation_6_1_8();
}
void fix_ingred_operation_6_2_0(){
char bytes_read [ 1 ];
    bzero(&bytes_read,( 1 *sizeof(char) ) );
    {int ret; ret = (int)(bytes_read); }
    {char * s_buf_ptr; s_buf_ptr = (char *)(bytes_read); }
    {char * n_buf_ptr; n_buf_ptr = (char *)(bytes_read); }
    {int syllable_id; syllable_id = (int)(bytes_read); }
    {char bytes_read [ 1 ]; bytes_read [ ( 1 )-1 ] = (char)(bytes_read); }
    {int total_bytes_written; total_bytes_written = (int)(bytes_read); }
    {char * tlv1; tlv1 = (char *)(bytes_read); }
    {int tlv4; tlv4 = (int)(bytes_read); }
    {char * tlv3; tlv3 = (char *)(bytes_read); }
}
void fix_ingred_operation_6_2(){
fix_ingred_operation_6_2_0();
}
void fix_ingred_operation_6_3_0(){
char bytes_read [ 1 ];
    bzero(&bytes_read,( 1 *sizeof(char) ) );
int syllable_id;
    bzero(&syllable_id,sizeof(int));
    {if (bytes_read){int ret; ret = (int)(bytes_read [ 0 ]); }}
    {if (bytes_read){char * s_buf_ptr; s_buf_ptr = (char *)(bytes_read [ 0 ]); }}
    {if (bytes_read){char * n_buf_ptr; n_buf_ptr = (char *)(bytes_read [ 0 ]); }}
    {if (bytes_read){int syllable_id; syllable_id = (int)(bytes_read [ 0 ]); }}
    {if (bytes_read){char bytes_read [ 1 ]; bytes_read [ ( 1 )-1 ] = (char)(bytes_read [ 0 ]); }}
    {if (bytes_read){int total_bytes_written; total_bytes_written = (int)(bytes_read [ 0 ]); }}
    {if (bytes_read){char * tlv1; tlv1 = (char *)(bytes_read [ 0 ]); }}
    {if (bytes_read){int tlv4; tlv4 = (int)(bytes_read [ 0 ]); }}
    {if (bytes_read){char * tlv3; tlv3 = (char *)(bytes_read [ 0 ]); }}
}
void fix_ingred_operation_6_3_1(){
char bytes_read [ 1 ];
    bzero(&bytes_read,( 1 *sizeof(char) ) );
int syllable_id;
    bzero(&syllable_id,sizeof(int));
    {if (bytes_read){int ret; ret = (int)(bytes_read [ 0 ]); }}
    {if (bytes_read){char * s_buf_ptr; s_buf_ptr = (char *)(bytes_read [ 0 ]); }}
    {if (bytes_read){char * n_buf_ptr; n_buf_ptr = (char *)(bytes_read [ 0 ]); }}
    {if (bytes_read){int syllable_id; syllable_id = (int)(bytes_read [ 0 ]); }}
    {if (bytes_read){char bytes_read [ 1 ]; bytes_read [ ( 1 )-1 ] = (char)(bytes_read [ 0 ]); }}
    {if (bytes_read){int total_bytes_written; total_bytes_written = (int)(bytes_read [ 0 ]); }}
    {if (bytes_read){char * tlv1; tlv1 = (char *)(bytes_read [ 0 ]); }}
    {if (bytes_read){int tlv4; tlv4 = (int)(bytes_read [ 0 ]); }}
    {if (bytes_read){char * tlv3; tlv3 = (char *)(bytes_read [ 0 ]); }}
}
void fix_ingred_operation_6_3_12(){
char bytes_read [ 1 ];
    bzero(&bytes_read,( 1 *sizeof(char) ) );
int syllable_id;
    bzero(&syllable_id,sizeof(int));
    {char * s_buf_ptr; s_buf_ptr = (char *)(syllable_id); }
    {char * n_buf_ptr; n_buf_ptr = (char *)(syllable_id); }
    {char bytes_read [ 1 ]; bytes_read [ ( 1 )-1 ] = (char)(syllable_id); }
    {int total_bytes_written; total_bytes_written = (int)(syllable_id); }
    {int tlv4; tlv4 = (int)(syllable_id); }
    {char * tlv3; tlv3 = (char *)(syllable_id); }
}
void fix_ingred_operation_6_3(){
fix_ingred_operation_6_3_0();
fix_ingred_operation_6_3_1();
fix_ingred_operation_6_3_12();
}
void fix_ingred_operation_6_4_1(){
char n_buf_ptr_ref;
    bzero(&n_buf_ptr_ref,1*sizeof(char));
char * n_buf_ptr = &n_buf_ptr_ref;
    {int ret; ret = (int)(n_buf_ptr); }
    {char * s_buf_ptr; s_buf_ptr = (char *)(n_buf_ptr); }
    {int syllable_id; syllable_id = (int)(n_buf_ptr); }
    {char bytes_read [ 1 ]; bytes_read [ ( 1 )-1 ] = (char)(n_buf_ptr); }
    {int total_bytes_written; total_bytes_written = (int)(n_buf_ptr); }
    {char * tlv1; tlv1 = (char *)(n_buf_ptr); }
    {int tlv4; tlv4 = (int)(n_buf_ptr); }
    {char * tlv3; tlv3 = (char *)(n_buf_ptr); }
}
void fix_ingred_operation_6_4(){
fix_ingred_operation_6_4_1();
}
void fix_ingred_operation_6_5_0(){
int ret;
    bzero(&ret,sizeof(int));
    {char * s_buf_ptr; s_buf_ptr = (char *)(ret); }
    {char * n_buf_ptr; n_buf_ptr = (char *)(ret); }
    {int syllable_id; syllable_id = (int)(ret); }
    {char bytes_read [ 1 ]; bytes_read [ ( 1 )-1 ] = (char)(ret); }
    {int total_bytes_written; total_bytes_written = (int)(ret); }
    {char * tlv1; tlv1 = (char *)(ret); }
    {int tlv4; tlv4 = (int)(ret); }
    {char * tlv3; tlv3 = (char *)(ret); }
}
void fix_ingred_operation_6_5(){
fix_ingred_operation_6_5_0();
}
void fix_ingred_operation_6_7_0(){
int total_bytes_written;
    bzero(&total_bytes_written,sizeof(int));
    {int ret; ret = (int)(total_bytes_written); }
    {char * s_buf_ptr; s_buf_ptr = (char *)(total_bytes_written); }
    {char * n_buf_ptr; n_buf_ptr = (char *)(total_bytes_written); }
    {int syllable_id; syllable_id = (int)(total_bytes_written); }
    {char bytes_read [ 1 ]; bytes_read [ ( 1 )-1 ] = (char)(total_bytes_written); }
    {char * tlv1; tlv1 = (char *)(total_bytes_written); }
    {int tlv4; tlv4 = (int)(total_bytes_written); }
    {char * tlv3; tlv3 = (char *)(total_bytes_written); }
}
void fix_ingred_operation_6_7(){
fix_ingred_operation_6_7_0();
}
void fix_ingred_operation_6(){
fix_ingred_operation_6_0();
fix_ingred_operation_6_1();
fix_ingred_operation_6_2();
fix_ingred_operation_6_3();
fix_ingred_operation_6_4();
fix_ingred_operation_6_5();
fix_ingred_operation_6_7();
}
void fix_ingred_operation_7_0_0(){
char syllables_buf_ref;
    bzero(&syllables_buf_ref,1*sizeof(char));
char * syllables_buf = &syllables_buf_ref;
char notes_buf_ref;
    bzero(&notes_buf_ref,1*sizeof(char));
char * notes_buf = &notes_buf_ref;
    {int note_id; note_id = (int)(1); }
    {int tlv3; tlv3 = (int)(1); }
    {char * tlv2; tlv2 = (char *)(1); }
}
void fix_ingred_operation_7_0_1(){
char syllables_buf_ref;
    bzero(&syllables_buf_ref,1*sizeof(char));
char * syllables_buf = &syllables_buf_ref;
char notes_buf_ref;
    bzero(&notes_buf_ref,1*sizeof(char));
char * notes_buf = &notes_buf_ref;
    {int note_id; note_id = (int)(syllables_buf); }
    {int tlv3; tlv3 = (int)(syllables_buf); }
    {char * tlv2; tlv2 = (char *)(syllables_buf); }
}
void fix_ingred_operation_7_0_2(){
char syllables_buf_ref;
    bzero(&syllables_buf_ref,1*sizeof(char));
char * syllables_buf = &syllables_buf_ref;
char notes_buf_ref;
    bzero(&notes_buf_ref,1*sizeof(char));
char * notes_buf = &notes_buf_ref;
    {int note_id; note_id = (int)(notes_buf); }
    {int tlv3; tlv3 = (int)(notes_buf); }
    {char * tlv2; tlv2 = (char *)(notes_buf); }
}
void fix_ingred_operation_7_0_3(){
char syllables_buf_ref;
    bzero(&syllables_buf_ref,1*sizeof(char));
char * syllables_buf = &syllables_buf_ref;
char notes_buf_ref;
    bzero(&notes_buf_ref,1*sizeof(char));
char * notes_buf = &notes_buf_ref;
    {int note_id; note_id = (int)(0); }
    {int tlv3; tlv3 = (int)(0); }
    {char * tlv2; tlv2 = (char *)(0); }
}
void fix_ingred_operation_7_0(){
fix_ingred_operation_7_0_0();
fix_ingred_operation_7_0_1();
fix_ingred_operation_7_0_2();
fix_ingred_operation_7_0_3();
}
void fix_ingred_operation_7_1_6(){
int ret;
    bzero(&ret,sizeof(int));
int total_bytes_written;
    bzero(&total_bytes_written,sizeof(int));
uint32_t bytes_count;
    bzero(&bytes_count,sizeof(uint32_t));
    {int note_id; note_id = (int)(ret); }
    {int tlv3; tlv3 = (int)(ret); }
    {char * tlv2; tlv2 = (char *)(ret); }
}
void fix_ingred_operation_7_1_7(){
int ret;
    bzero(&ret,sizeof(int));
int total_bytes_written;
    bzero(&total_bytes_written,sizeof(int));
uint32_t bytes_count;
    bzero(&bytes_count,sizeof(uint32_t));
    {int ret; ret = (int)(MAX_SYLLABLES_BYTES); }
    {char * s_buf_ptr; s_buf_ptr = (char *)(MAX_SYLLABLES_BYTES); }
    {char * n_buf_ptr; n_buf_ptr = (char *)(MAX_SYLLABLES_BYTES); }
    {int note_id; note_id = (int)(MAX_SYLLABLES_BYTES); }
    {int total_bytes_written; total_bytes_written = (int)(MAX_SYLLABLES_BYTES); }
    {int tlv3; tlv3 = (int)(MAX_SYLLABLES_BYTES); }
    {char * tlv2; tlv2 = (char *)(MAX_SYLLABLES_BYTES); }
}
void fix_ingred_operation_7_1_8(){
int ret;
    bzero(&ret,sizeof(int));
int total_bytes_written;
    bzero(&total_bytes_written,sizeof(int));
uint32_t bytes_count;
    bzero(&bytes_count,sizeof(uint32_t));
    {int note_id; note_id = (int)(total_bytes_written); }
    {int tlv3; tlv3 = (int)(total_bytes_written); }
    {char * tlv2; tlv2 = (char *)(total_bytes_written); }
}
void fix_ingred_operation_7_1_9(){
int ret;
    bzero(&ret,sizeof(int));
int total_bytes_written;
    bzero(&total_bytes_written,sizeof(int));
uint32_t bytes_count;
    bzero(&bytes_count,sizeof(uint32_t));
    {int note_id; note_id = (int)(0); }
    {int tlv3; tlv3 = (int)(0); }
    {char * tlv2; tlv2 = (char *)(0); }
}
void fix_ingred_operation_7_1_10(){
int ret;
    bzero(&ret,sizeof(int));
int total_bytes_written;
    bzero(&total_bytes_written,sizeof(int));
uint32_t bytes_count;
    bzero(&bytes_count,sizeof(uint32_t));
    {int note_id; note_id = (int)(bytes_count); }
    {int tlv3; tlv3 = (int)(bytes_count); }
    {char * tlv2; tlv2 = (char *)(bytes_count); }
}
void fix_ingred_operation_7_1(){
fix_ingred_operation_7_1_6();
fix_ingred_operation_7_1_7();
fix_ingred_operation_7_1_8();
fix_ingred_operation_7_1_9();
fix_ingred_operation_7_1_10();
}
void fix_ingred_operation_7_3_12(){
int note_id;
    bzero(&note_id,sizeof(int));
    {char * s_buf_ptr; s_buf_ptr = (char *)(note_id); }
    {char * n_buf_ptr; n_buf_ptr = (char *)(note_id); }
    {int total_bytes_written; total_bytes_written = (int)(note_id); }
    {int tlv3; tlv3 = (int)(note_id); }
    {char * tlv2; tlv2 = (char *)(note_id); }
}
void fix_ingred_operation_7_3(){
fix_ingred_operation_7_3_12();
}
void fix_ingred_operation_7_4_1(){
char s_buf_ptr_ref;
    bzero(&s_buf_ptr_ref,1*sizeof(char));
char * s_buf_ptr = &s_buf_ptr_ref;
    {int ret; ret = (int)(s_buf_ptr); }
    {char * n_buf_ptr; n_buf_ptr = (char *)(s_buf_ptr); }
    {int note_id; note_id = (int)(s_buf_ptr); }
    {int total_bytes_written; total_bytes_written = (int)(s_buf_ptr); }
    {int tlv3; tlv3 = (int)(s_buf_ptr); }
    {char * tlv2; tlv2 = (char *)(s_buf_ptr); }
}
void fix_ingred_operation_7_4(){
fix_ingred_operation_7_4_1();
}
void fix_ingred_operation_7_5_0(){
int ret;
    bzero(&ret,sizeof(int));
    {int note_id; note_id = (int)(ret); }
    {int tlv3; tlv3 = (int)(ret); }
    {char * tlv2; tlv2 = (char *)(ret); }
}
void fix_ingred_operation_7_5_15(){
int ret;
    bzero(&ret,sizeof(int));
    {char * s_buf_ptr; s_buf_ptr = (char *)(2); }
    {char * n_buf_ptr; n_buf_ptr = (char *)(2); }
    {int note_id; note_id = (int)(2); }
    {int total_bytes_written; total_bytes_written = (int)(2); }
    {int tlv3; tlv3 = (int)(2); }
    {char * tlv2; tlv2 = (char *)(2); }
}
void fix_ingred_operation_7_5_17(){
int ret;
    bzero(&ret,sizeof(int));
    {char * s_buf_ptr; s_buf_ptr = (char *)(3); }
    {char * n_buf_ptr; n_buf_ptr = (char *)(3); }
    {int note_id; note_id = (int)(3); }
    {int total_bytes_written; total_bytes_written = (int)(3); }
    {int tlv3; tlv3 = (int)(3); }
    {char * tlv2; tlv2 = (char *)(3); }
}
void fix_ingred_operation_7_5(){
fix_ingred_operation_7_5_0();
fix_ingred_operation_7_5_15();
fix_ingred_operation_7_5_17();
}
void fix_ingred_operation_7(){
fix_ingred_operation_7_0();
fix_ingred_operation_7_1();
fix_ingred_operation_7_3();
fix_ingred_operation_7_4();
fix_ingred_operation_7_5();
}
void fix_ingred_operation_8_1_0(){
uint32_t bytes_count;
    bzero(&bytes_count,sizeof(uint32_t));
    {cgc_size_t tlv1; tlv1 = (cgc_size_t)(bytes_count * sizeof ( char )); }
}
void fix_ingred_operation_8_1(){
fix_ingred_operation_8_1_0();
}
void fix_ingred_operation_8(){
fix_ingred_operation_8_1();
}
void fix_ingred_operation_9(){
}
void fix_ingred_operation_10(){
}
void fix_ingred_operation_11_0_0(){
    {uint32_t bytes_count; bytes_count = (uint32_t)(0); }
    {uint32_t tlv3; tlv3 = (uint32_t)(0); }
    {uint32_t tlv5; tlv5 = (uint32_t)(0); }
    {char * tlv4; tlv4 = (char *)(0); }
}
void fix_ingred_operation_11_0(){
fix_ingred_operation_11_0_0();
}
void fix_ingred_operation_11_1_2(){
uint32_t bytes_count;
    bzero(&bytes_count,sizeof(uint32_t));
    {uint32_t bytes_count; bytes_count = (uint32_t)(0); }
    {uint32_t tlv3; tlv3 = (uint32_t)(0); }
    {uint32_t tlv5; tlv5 = (uint32_t)(0); }
    {char * tlv4; tlv4 = (char *)(0); }
}
void fix_ingred_operation_11_1_3(){
uint32_t bytes_count;
    bzero(&bytes_count,sizeof(uint32_t));
    {uint32_t tlv3; tlv3 = (uint32_t)(bytes_count); }
    {uint32_t tlv5; tlv5 = (uint32_t)(bytes_count); }
    {char * tlv4; tlv4 = (char *)(bytes_count); }
}
void fix_ingred_operation_11_1(){
fix_ingred_operation_11_1_2();
fix_ingred_operation_11_1_3();
}
void fix_ingred_operation_11_2_2(){
    {int ret; ret = (int)(MAX_NOTES_BYTES); }
    {int total_bytes_written; total_bytes_written = (int)(MAX_NOTES_BYTES); }
    {uint32_t bytes_count; bytes_count = (uint32_t)(MAX_NOTES_BYTES); }
    {uint32_t tlv3; tlv3 = (uint32_t)(MAX_NOTES_BYTES); }
    {char * tlv2; tlv2 = (char *)(MAX_NOTES_BYTES); }
    {char * tlv1; tlv1 = (char *)(MAX_NOTES_BYTES); }
    {uint32_t tlv5; tlv5 = (uint32_t)(MAX_NOTES_BYTES); }
    {char * tlv4; tlv4 = (char *)(MAX_NOTES_BYTES); }
}
void fix_ingred_operation_11_2(){
fix_ingred_operation_11_2_2();
}
void fix_ingred_operation_11_3_1(){
char syllables_buf_ref;
    bzero(&syllables_buf_ref,1*sizeof(char));
char * syllables_buf = &syllables_buf_ref;
char notes_buf_ref;
    bzero(&notes_buf_ref,1*sizeof(char));
char * notes_buf = &notes_buf_ref;
    {uint32_t bytes_count; bytes_count = (uint32_t)(syllables_buf); }
    {uint32_t tlv3; tlv3 = (uint32_t)(syllables_buf); }
    {uint32_t tlv5; tlv5 = (uint32_t)(syllables_buf); }
    {char * tlv4; tlv4 = (char *)(syllables_buf); }
}
void fix_ingred_operation_11_3_2(){
char syllables_buf_ref;
    bzero(&syllables_buf_ref,1*sizeof(char));
char * syllables_buf = &syllables_buf_ref;
char notes_buf_ref;
    bzero(&notes_buf_ref,1*sizeof(char));
char * notes_buf = &notes_buf_ref;
    {uint32_t bytes_count; bytes_count = (uint32_t)(notes_buf); }
    {uint32_t tlv3; tlv3 = (uint32_t)(notes_buf); }
    {uint32_t tlv5; tlv5 = (uint32_t)(notes_buf); }
    {char * tlv4; tlv4 = (char *)(notes_buf); }
}
void fix_ingred_operation_11_3(){
fix_ingred_operation_11_3_1();
fix_ingred_operation_11_3_2();
}
void fix_ingred_operation_11_4_0(){
int total_bytes_written;
    bzero(&total_bytes_written,sizeof(int));
    {int total_bytes_written; total_bytes_written = (int)(SUCCESS); }
    {uint32_t bytes_count; bytes_count = (uint32_t)(SUCCESS); }
    {uint32_t tlv3; tlv3 = (uint32_t)(SUCCESS); }
    {char * tlv2; tlv2 = (char *)(SUCCESS); }
    {uint32_t tlv5; tlv5 = (uint32_t)(SUCCESS); }
    {char * tlv4; tlv4 = (char *)(SUCCESS); }
}
void fix_ingred_operation_11_4_4(){
int total_bytes_written;
    bzero(&total_bytes_written,sizeof(int));
    {uint32_t bytes_count; bytes_count = (uint32_t)(total_bytes_written); }
    {uint32_t tlv3; tlv3 = (uint32_t)(total_bytes_written); }
    {uint32_t tlv5; tlv5 = (uint32_t)(total_bytes_written); }
    {char * tlv4; tlv4 = (char *)(total_bytes_written); }
}
void fix_ingred_operation_11_4(){
fix_ingred_operation_11_4_0();
fix_ingred_operation_11_4_4();
}
void fix_ingred_operation_11_5_0(){
int total_bytes_written;
    bzero(&total_bytes_written,sizeof(int));
    {int ret; ret = (int)(total_bytes_written); }
    {uint32_t bytes_count; bytes_count = (uint32_t)(total_bytes_written); }
    {uint32_t tlv3; tlv3 = (uint32_t)(total_bytes_written); }
    {char * tlv2; tlv2 = (char *)(total_bytes_written); }
    {char * tlv1; tlv1 = (char *)(total_bytes_written); }
    {uint32_t tlv5; tlv5 = (uint32_t)(total_bytes_written); }
    {char * tlv4; tlv4 = (char *)(total_bytes_written); }
}
void fix_ingred_operation_11_5(){
fix_ingred_operation_11_5_0();
}
void fix_ingred_operation_11_7_0(){
    {int ret; ret = (int)(ERR_NO_SYLLABLES); }
    {int total_bytes_written; total_bytes_written = (int)(ERR_NO_SYLLABLES); }
    {uint32_t bytes_count; bytes_count = (uint32_t)(ERR_NO_SYLLABLES); }
    {uint32_t tlv3; tlv3 = (uint32_t)(ERR_NO_SYLLABLES); }
    {char * tlv2; tlv2 = (char *)(ERR_NO_SYLLABLES); }
    {char * tlv1; tlv1 = (char *)(ERR_NO_SYLLABLES); }
    {uint32_t tlv5; tlv5 = (uint32_t)(ERR_NO_SYLLABLES); }
    {char * tlv4; tlv4 = (char *)(ERR_NO_SYLLABLES); }
}
void fix_ingred_operation_11_7(){
fix_ingred_operation_11_7_0();
}
void fix_ingred_operation_11(){
fix_ingred_operation_11_0();
fix_ingred_operation_11_1();
fix_ingred_operation_11_2();
fix_ingred_operation_11_3();
fix_ingred_operation_11_4();
fix_ingred_operation_11_5();
fix_ingred_operation_11_7();
}
void fix_ingred_operation_12_2_2(){
    {int ret; ret = (int)(MAX_SYLLABLES_BYTES); }
    {int total_bytes_written; total_bytes_written = (int)(MAX_SYLLABLES_BYTES); }
    {uint32_t bytes_count; bytes_count = (uint32_t)(MAX_SYLLABLES_BYTES); }
    {uint32_t tlv3; tlv3 = (uint32_t)(MAX_SYLLABLES_BYTES); }
    {char * tlv2; tlv2 = (char *)(MAX_SYLLABLES_BYTES); }
    {char * tlv1; tlv1 = (char *)(MAX_SYLLABLES_BYTES); }
    {uint32_t tlv5; tlv5 = (uint32_t)(MAX_SYLLABLES_BYTES); }
    {char * tlv4; tlv4 = (char *)(MAX_SYLLABLES_BYTES); }
}
void fix_ingred_operation_12_2(){
fix_ingred_operation_12_2_2();
}
void fix_ingred_operation_12_7_0(){
    {int ret; ret = (int)(ERR_NO_NOTES); }
    {int total_bytes_written; total_bytes_written = (int)(ERR_NO_NOTES); }
    {uint32_t bytes_count; bytes_count = (uint32_t)(ERR_NO_NOTES); }
    {uint32_t tlv3; tlv3 = (uint32_t)(ERR_NO_NOTES); }
    {char * tlv2; tlv2 = (char *)(ERR_NO_NOTES); }
    {char * tlv1; tlv1 = (char *)(ERR_NO_NOTES); }
    {uint32_t tlv5; tlv5 = (uint32_t)(ERR_NO_NOTES); }
    {char * tlv4; tlv4 = (char *)(ERR_NO_NOTES); }
}
void fix_ingred_operation_12_7(){
fix_ingred_operation_12_7_0();
}
void fix_ingred_operation_12(){
fix_ingred_operation_12_2();
fix_ingred_operation_12_7();
}
