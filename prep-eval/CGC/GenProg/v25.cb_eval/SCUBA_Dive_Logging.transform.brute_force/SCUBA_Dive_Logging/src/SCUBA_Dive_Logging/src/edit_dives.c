

#include "cgc_service.h"
#include "cgc_menu.h"
#include "cgc_stdlib.h"
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

void fix_ingred_edit_dives_0_0_1();
void fix_ingred_edit_dives_0_0_2();
void fix_ingred_edit_dives_0_0();
void fix_ingred_edit_dives_0_6_0();
void fix_ingred_edit_dives_0_6_1();
void fix_ingred_edit_dives_0_6();
void fix_ingred_edit_dives_0_7_3();
void fix_ingred_edit_dives_0_7();
void fix_ingred_edit_dives_0_9_6();
void fix_ingred_edit_dives_0_9_7();
void fix_ingred_edit_dives_0_9();
void fix_ingred_edit_dives_0();
int cgc_edit_dives(logbook_type * Info)
{
if (fix_ingred_enable){ fix_ingred_edit_dives_0(); };
    char buf[1024];
    int rcv_cnt;
    dive_log_type *next_dive;
    next_dive = Info->dives;
    int dive_count;
    dive_count = 1;
    int dive_number_to_edit;
    dive_number_to_edit = 0;
    if (next_dive == 0) {
 {
     const char tlv6 [ ] = "\n";
    	cgc_printf(tlv6);
 }
 {
     const char tlv7 [ ] = "Dive Log is empty\n";
    	cgc_printf(tlv7);
 }
	return 0;
    }
    cgc_list_dives(Info);
    {
        const char tlv1 [ ] = "\n";
        cgc_printf(tlv1);
    }
    {
        const char tlv2 [ ] = "Enter Dive # to edit: ";
        cgc_printf(tlv2);
    }
    {
        char* tlv4;
         tlv4 = buf;
        cgc_size_t tlv3;
        tlv3 = sizeof ( buf );
        rcv_cnt = cgc_getline(tlv4,tlv3);
    }

    if (rcv_cnt == 0) {
	return 0;
    }
    {
        const char* tlv5 = buf;
        dive_number_to_edit = cgc_atoi(tlv5);
    }
    next_dive = Info->dives;
    dive_count = 1;
    while (dive_count < dive_number_to_edit && next_dive != 0) {
	++dive_count;
	next_dive = next_dive->next;
    }
    if (dive_count == dive_number_to_edit && next_dive != 0) {
	cgc_printf("Editing dive number @d\n", dive_number_to_edit);
	// now display and allow for updating of the data
	cgc_update_dive(next_dive);
    } else {
 {
     const char tlv8 [ ] = "Invalid dive number entered\n";
    	cgc_printf(tlv8);
 }
    }

    return 0;
}

void fix_ingred_edit_dives_1_4_0();
void fix_ingred_edit_dives_1_4_1();
void fix_ingred_edit_dives_1_4();
void fix_ingred_edit_dives_1_5_0();
void fix_ingred_edit_dives_1_5_1();
void fix_ingred_edit_dives_1_5();
void fix_ingred_edit_dives_1_6_0();
void fix_ingred_edit_dives_1_6();
void fix_ingred_edit_dives_1_10_1();
void fix_ingred_edit_dives_1_10();
void fix_ingred_edit_dives_1_12_0();
void fix_ingred_edit_dives_1_12();
void fix_ingred_edit_dives_1_16_0();
void fix_ingred_edit_dives_1_16_1();
void fix_ingred_edit_dives_1_16();
void fix_ingred_edit_dives_1_18_0();
void fix_ingred_edit_dives_1_18();
void fix_ingred_edit_dives_1_19_1();
void fix_ingred_edit_dives_1_19();
void fix_ingred_edit_dives_1_21_1();
void fix_ingred_edit_dives_1_21();
void fix_ingred_edit_dives_1_26_1();
void fix_ingred_edit_dives_1_26();
void fix_ingred_edit_dives_1_28_0();
void fix_ingred_edit_dives_1_28();
void fix_ingred_edit_dives_1_44_1();
void fix_ingred_edit_dives_1_44();
void fix_ingred_edit_dives_1_50_1();
void fix_ingred_edit_dives_1_50();
void fix_ingred_edit_dives_1_56_1();
void fix_ingred_edit_dives_1_56();
void fix_ingred_edit_dives_1();
int cgc_update_dive(dive_log_type * dive)
{
if (fix_ingred_enable){ fix_ingred_edit_dives_1(); };
    char buffer[1024];
    char buf2[1024];
    cgc_size_t count;
    {
        const char tlv1 [ ] = "Dive Site";
        cgc_printf(tlv1);
    }
    if (dive->dive_site_name[0] != 0) {
	cgc_printf(" (@s)", dive->dive_site_name);
    }
    {
        const char tlv2 [ ] = ": ";
        cgc_printf(tlv2);
    }
    {
        char* tlv28;
         tlv28 = buffer;
        cgc_size_t tlv27;
        tlv27 = sizeof ( dive -> dive_site_name );
        count = cgc_getline(tlv28,tlv27);
    }
    if (count > 0) {
 {
     char* tlv51;
      tlv51 = dive -> dive_site_name;
     const char* tlv50 = buffer;
     cgc_size_t tlv49;
     tlv49 = sizeof ( dive -> dive_site_name );
    	cgc_strncpy(tlv51,tlv50,tlv49);
 }
    }
    {
        const char tlv3 [ ] = "Date";
        cgc_printf(tlv3);
    }
    if (dive->dive_date[0] != 0) {
	cgc_printf(" (@s)", dive->dive_date);
    }
    {
        const char tlv4 [ ] = ": ";
        cgc_printf(tlv4);
    }
    {
        char* tlv30;
         tlv30 = buffer;
        cgc_size_t tlv29;
        tlv29 = sizeof ( dive -> dive_date );
        count = cgc_getline(tlv30,tlv29);
    }
    if (count > 0) {
 {
     char* tlv54;
      tlv54 = dive -> dive_date;
     const char* tlv53 = buffer;
     cgc_size_t tlv52;
     tlv52 = sizeof ( dive -> dive_date );
    	cgc_strncpy(tlv54,tlv53,tlv52);
 }
    }
    {
        const char tlv5 [ ] = "Time";
        cgc_printf(tlv5);
    }
    if (dive->dive_time[0] != 0) {
	cgc_printf(" (@s)", dive->dive_time);
    }
    {
        const char tlv6 [ ] = ": ";
        cgc_printf(tlv6);
    }
    {
        char* tlv32;
         tlv32 = buf2;
        cgc_size_t tlv31;
        tlv31 = sizeof ( dive -> dive_time );
        count = cgc_getline(tlv32,tlv31);
    }
    if (count > 0) {
 {
     char* tlv57;
      tlv57 = dive -> dive_time;
     const char* tlv56 = buf2;
     cgc_size_t tlv55;
     tlv55 = sizeof ( dive -> dive_time );
    	cgc_strncpy(tlv57,tlv56,tlv55);
 }
    }
    {
        char* tlv9;
         tlv9 = buffer;
        const char tlv8 [ ] = " ";
        cgc_size_t tlv7;
        tlv7 = 1;
        cgc_strncat(tlv9,tlv8,tlv7);
    }
    {
        char* tlv12;
         tlv12 = buffer;
        const char* tlv11 = buf2;
        cgc_size_t tlv10;
        {
            char* tlv67;
             tlv67 = buf2;
            tlv10 = cgc_strlen(tlv67);
        }
        cgc_strncat(tlv12,tlv11,tlv10);
    }
    datetime_struct_type tm;
    {
        char* tlv34;
         tlv34 = buffer;
        datetime_struct_type* tlv33;
        tlv33 = & tm;
        dive->timestamp = cgc_str2datetime(tlv34,tlv33);
    }
    {
        const char tlv13 [ ] = "Location (area/city)";
        cgc_printf(tlv13);
    }
    if (dive->location[0] != 0) {
	cgc_printf(" (@s)", dive->location);
    }
    {
        const char tlv14 [ ] = ": ";
        cgc_printf(tlv14);
    }
    {
        char* tlv36;
         tlv36 = buffer;
        cgc_size_t tlv35;
        tlv35 = sizeof ( buffer );
        count = cgc_getline(tlv36,tlv35);
    }
    if (count > 0) {
 {
     char* tlv60;
      tlv60 = dive -> location;
     const char* tlv59 = buffer;
     cgc_size_t tlv58;
     tlv58 = count;
    	cgc_strncpy(tlv60,tlv59,tlv58);
 }
    }
    {
        const char tlv15 [ ] = "Max Depth in ft";
        cgc_printf(tlv15);
    }
    if (dive->max_depth != 0) {
	cgc_printf(" (@d)", dive->max_depth);
    }
    {
        const char tlv16 [ ] = ": ";
        cgc_printf(tlv16);
    }
    {
        char* tlv38;
         tlv38 = buffer;
        cgc_size_t tlv37;
        tlv37 = sizeof ( buffer );
        count = cgc_getline(tlv38,tlv37);
    }
    if (count > 0) {
 {
     const char* tlv61 = buffer;
    	dive->max_depth = cgc_atoi(tlv61);
 }
    }
    {
        const char tlv17 [ ] = "Avg Depth in ft";
        cgc_printf(tlv17);
    }
    if (dive->avg_depth != 0) {
	cgc_printf(" (@d)", dive->avg_depth);
    }
    {
        const char tlv18 [ ] = ": ";
        cgc_printf(tlv18);
    }
    {
        char* tlv40;
         tlv40 = buffer;
        cgc_size_t tlv39;
        tlv39 = sizeof ( buffer );
        count = cgc_getline(tlv40,tlv39);
    }
    if (count > 0) {
 {
     const char* tlv62 = buffer;
    	dive->avg_depth = cgc_atoi(tlv62);
 }
    }
    {
        const char tlv19 [ ] = "Dive Duration (mins)";
        cgc_printf(tlv19);
    }
    if (dive->dive_length != 0) {
	cgc_printf(" (@d)", dive->dive_length);
    }
    {
        const char tlv20 [ ] = ": ";
        cgc_printf(tlv20);
    }
    {
        char* tlv42;
         tlv42 = buffer;
        cgc_size_t tlv41;
        tlv41 = 13;
        count = cgc_getline(tlv42,tlv41);
    }
    if (count > 0) {
 {
     const char* tlv63 = buffer;
    	dive->dive_length = cgc_atoi(tlv63);
 }
    }
    {
        const char tlv21 [ ] = "O2 Percentage";
        cgc_printf(tlv21);
    }
    if (dive->O2_percent != 0) {
	cgc_printf(" (@d)", dive->O2_percent);
    }
    {
        const char tlv22 [ ] = ": ";
        cgc_printf(tlv22);
    }
    {
        char* tlv44;
         tlv44 = buffer;
        cgc_size_t tlv43;
        tlv43 = 11;
        count = cgc_getline(tlv44,tlv43);
    }
    if (count > 0) {
 {
     const char* tlv64 = buffer;
    	dive->O2_percent = cgc_atoi(tlv64);
 }
    }

    {
        const char tlv23 [ ] = "Pressure In (psi)";
        cgc_printf(tlv23);
    }
    if (dive->pressure_in != 0) {
	cgc_printf(" (@d)", dive->pressure_in);
    }
    {
        const char tlv24 [ ] = ": ";
        cgc_printf(tlv24);
    }
    {
        char* tlv46;
         tlv46 = buffer;
        cgc_size_t tlv45;
        tlv45 = 20;
        count = cgc_getline(tlv46,tlv45);
    }
    if (count > 0) {
 {
     const char* tlv65 = buffer;
    	dive->pressure_in = cgc_atoi(tlv65);
 }
    }
    {
        const char tlv25 [ ] = "Pressure Out (psi)";
        cgc_printf(tlv25);
    }
    if (dive->pressure_out != 0) {
	cgc_printf(" (@d)", dive->pressure_out);
    }
    {
        const char tlv26 [ ] = ": ";
        cgc_printf(tlv26);
    }
    {
        char* tlv48;
         tlv48 = buffer;
        cgc_size_t tlv47;
        tlv47 = 11;
        count = cgc_getline(tlv48,tlv47);
    }
    if (count > 0) {
 {
     const char* tlv66 = buffer;
    	dive->pressure_out = cgc_atoi(tlv66);
 }
    }
    return 0;
}

void fix_ingred_edit_dives_0_0_1(){
    {char buf [ 1024 ]; buf [ ( 1024 )-1 ] = (char)(1); }
    {int rcv_cnt; rcv_cnt = (int)(1); }
    {int dive_count; dive_count = (int)(1); }
    {int dive_number_to_edit; dive_number_to_edit = (int)(1); }
    {char * tlv4; tlv4 = (char *)(1); }
    {cgc_size_t tlv3; tlv3 = (cgc_size_t)(1); }
}
void fix_ingred_edit_dives_0_0_2(){
    {char buf [ 1024 ]; buf [ ( 1024 )-1 ] = (char)(0); }
    {int rcv_cnt; rcv_cnt = (int)(0); }
    {int dive_count; dive_count = (int)(0); }
    {int dive_number_to_edit; dive_number_to_edit = (int)(0); }
    {char * tlv4; tlv4 = (char *)(0); }
    {cgc_size_t tlv3; tlv3 = (cgc_size_t)(0); }
}
void fix_ingred_edit_dives_0_0(){
fix_ingred_edit_dives_0_0_1();
fix_ingred_edit_dives_0_0_2();
}
void fix_ingred_edit_dives_0_6_0(){
char buf [ 1024 ];
    bzero(&buf,( 1024 *sizeof(char) ) );
    {char buf [ 1024 ]; buf [ ( 1024 )-1 ] = (char)(buf); }
    {int rcv_cnt; rcv_cnt = (int)(buf); }
    {int dive_count; dive_count = (int)(buf); }
    {int dive_number_to_edit; dive_number_to_edit = (int)(buf); }
    {char * tlv4; tlv4 = (char *)(buf); }
    {cgc_size_t tlv3; tlv3 = (cgc_size_t)(buf); }
}
void fix_ingred_edit_dives_0_6_1(){
char buf [ 1024 ];
    bzero(&buf,( 1024 *sizeof(char) ) );
    {char buf [ 1024 ]; buf [ ( 1024 )-1 ] = (char)(sizeof ( buf )); }
    {int rcv_cnt; rcv_cnt = (int)(sizeof ( buf )); }
    {int dive_count; dive_count = (int)(sizeof ( buf )); }
    {int dive_number_to_edit; dive_number_to_edit = (int)(sizeof ( buf )); }
    {char * tlv4; tlv4 = (char *)(sizeof ( buf )); }
    {cgc_size_t tlv3; tlv3 = (cgc_size_t)(sizeof ( buf )); }
}
void fix_ingred_edit_dives_0_6(){
fix_ingred_edit_dives_0_6_0();
fix_ingred_edit_dives_0_6_1();
}
void fix_ingred_edit_dives_0_7_3(){
int rcv_cnt;
    bzero(&rcv_cnt,sizeof(int));
    {char buf [ 1024 ]; buf [ ( 1024 )-1 ] = (char)(rcv_cnt); }
    {int dive_count; dive_count = (int)(rcv_cnt); }
    {int dive_number_to_edit; dive_number_to_edit = (int)(rcv_cnt); }
    {char * tlv4; tlv4 = (char *)(rcv_cnt); }
    {cgc_size_t tlv3; tlv3 = (cgc_size_t)(rcv_cnt); }
}
void fix_ingred_edit_dives_0_7(){
fix_ingred_edit_dives_0_7_3();
}
void fix_ingred_edit_dives_0_9_6(){
int dive_count;
    bzero(&dive_count,sizeof(int));
int dive_number_to_edit;
    bzero(&dive_number_to_edit,sizeof(int));
    {char buf [ 1024 ]; buf [ ( 1024 )-1 ] = (char)(dive_count); }
    {int rcv_cnt; rcv_cnt = (int)(dive_count); }
    {int dive_number_to_edit; dive_number_to_edit = (int)(dive_count); }
    {char * tlv4; tlv4 = (char *)(dive_count); }
    {cgc_size_t tlv3; tlv3 = (cgc_size_t)(dive_count); }
}
void fix_ingred_edit_dives_0_9_7(){
int dive_count;
    bzero(&dive_count,sizeof(int));
int dive_number_to_edit;
    bzero(&dive_number_to_edit,sizeof(int));
    {char buf [ 1024 ]; buf [ ( 1024 )-1 ] = (char)(dive_number_to_edit); }
    {int rcv_cnt; rcv_cnt = (int)(dive_number_to_edit); }
    {int dive_count; dive_count = (int)(dive_number_to_edit); }
    {char * tlv4; tlv4 = (char *)(dive_number_to_edit); }
    {cgc_size_t tlv3; tlv3 = (cgc_size_t)(dive_number_to_edit); }
}
void fix_ingred_edit_dives_0_9(){
fix_ingred_edit_dives_0_9_6();
fix_ingred_edit_dives_0_9_7();
}
void fix_ingred_edit_dives_0(){
fix_ingred_edit_dives_0_0();
fix_ingred_edit_dives_0_6();
fix_ingred_edit_dives_0_7();
fix_ingred_edit_dives_0_9();
}
void fix_ingred_edit_dives_1_4_0(){
char buffer [ 1024 ];
    bzero(&buffer,( 1024 *sizeof(char) ) );
dive_log_type dive_ref;
    bzero(&dive_ref,1*sizeof(dive_log_type));
dive_log_type * dive = &dive_ref;
    {char buffer [ 1024 ]; buffer [ ( 1024 )-1 ] = (char)(buffer); }
    {char buf2 [ 1024 ]; buf2 [ ( 1024 )-1 ] = (char)(buffer); }
    {cgc_size_t count; count = (cgc_size_t)(buffer); }
    {char * tlv28; tlv28 = (char *)(buffer); }
    {cgc_size_t tlv27; tlv27 = (cgc_size_t)(buffer); }
    {char * tlv30; tlv30 = (char *)(buffer); }
    {cgc_size_t tlv29; tlv29 = (cgc_size_t)(buffer); }
    {char * tlv32; tlv32 = (char *)(buffer); }
    {cgc_size_t tlv31; tlv31 = (cgc_size_t)(buffer); }
    {char * tlv9; tlv9 = (char *)(buffer); }
    {cgc_size_t tlv7; tlv7 = (cgc_size_t)(buffer); }
    {char * tlv12; tlv12 = (char *)(buffer); }
    {cgc_size_t tlv10; tlv10 = (cgc_size_t)(buffer); }
    {char * tlv34; tlv34 = (char *)(buffer); }
    {char * tlv36; tlv36 = (char *)(buffer); }
    {cgc_size_t tlv35; tlv35 = (cgc_size_t)(buffer); }
    {char * tlv38; tlv38 = (char *)(buffer); }
    {cgc_size_t tlv37; tlv37 = (cgc_size_t)(buffer); }
    {char * tlv40; tlv40 = (char *)(buffer); }
    {cgc_size_t tlv39; tlv39 = (cgc_size_t)(buffer); }
    {char * tlv42; tlv42 = (char *)(buffer); }
    {cgc_size_t tlv41; tlv41 = (cgc_size_t)(buffer); }
    {char * tlv44; tlv44 = (char *)(buffer); }
    {cgc_size_t tlv43; tlv43 = (cgc_size_t)(buffer); }
    {char * tlv46; tlv46 = (char *)(buffer); }
    {cgc_size_t tlv45; tlv45 = (cgc_size_t)(buffer); }
    {char * tlv48; tlv48 = (char *)(buffer); }
    {cgc_size_t tlv47; tlv47 = (cgc_size_t)(buffer); }
    {char * tlv67; tlv67 = (char *)(buffer); }
    {char * tlv51; tlv51 = (char *)(buffer); }
    {cgc_size_t tlv49; tlv49 = (cgc_size_t)(buffer); }
    {char * tlv54; tlv54 = (char *)(buffer); }
    {cgc_size_t tlv52; tlv52 = (cgc_size_t)(buffer); }
    {char * tlv57; tlv57 = (char *)(buffer); }
    {cgc_size_t tlv55; tlv55 = (cgc_size_t)(buffer); }
    {char * tlv60; tlv60 = (char *)(buffer); }
    {cgc_size_t tlv58; tlv58 = (cgc_size_t)(buffer); }
}
void fix_ingred_edit_dives_1_4_1(){
char buffer [ 1024 ];
    bzero(&buffer,( 1024 *sizeof(char) ) );
dive_log_type dive_ref;
    bzero(&dive_ref,1*sizeof(dive_log_type));
dive_log_type * dive = &dive_ref;
    {char buffer [ 1024 ]; buffer [ ( 1024 )-1 ] = (char)(sizeof ( dive -> dive_site_name )); }
    {char buf2 [ 1024 ]; buf2 [ ( 1024 )-1 ] = (char)(sizeof ( dive -> dive_site_name )); }
    {cgc_size_t count; count = (cgc_size_t)(sizeof ( dive -> dive_site_name )); }
    {char * tlv28; tlv28 = (char *)(sizeof ( dive -> dive_site_name )); }
    {cgc_size_t tlv27; tlv27 = (cgc_size_t)(sizeof ( dive -> dive_site_name )); }
    {char * tlv30; tlv30 = (char *)(sizeof ( dive -> dive_site_name )); }
    {cgc_size_t tlv29; tlv29 = (cgc_size_t)(sizeof ( dive -> dive_site_name )); }
    {char * tlv32; tlv32 = (char *)(sizeof ( dive -> dive_site_name )); }
    {cgc_size_t tlv31; tlv31 = (cgc_size_t)(sizeof ( dive -> dive_site_name )); }
    {char * tlv9; tlv9 = (char *)(sizeof ( dive -> dive_site_name )); }
    {cgc_size_t tlv7; tlv7 = (cgc_size_t)(sizeof ( dive -> dive_site_name )); }
    {char * tlv12; tlv12 = (char *)(sizeof ( dive -> dive_site_name )); }
    {cgc_size_t tlv10; tlv10 = (cgc_size_t)(sizeof ( dive -> dive_site_name )); }
    {char * tlv34; tlv34 = (char *)(sizeof ( dive -> dive_site_name )); }
    {char * tlv36; tlv36 = (char *)(sizeof ( dive -> dive_site_name )); }
    {cgc_size_t tlv35; tlv35 = (cgc_size_t)(sizeof ( dive -> dive_site_name )); }
    {char * tlv38; tlv38 = (char *)(sizeof ( dive -> dive_site_name )); }
    {cgc_size_t tlv37; tlv37 = (cgc_size_t)(sizeof ( dive -> dive_site_name )); }
    {char * tlv40; tlv40 = (char *)(sizeof ( dive -> dive_site_name )); }
    {cgc_size_t tlv39; tlv39 = (cgc_size_t)(sizeof ( dive -> dive_site_name )); }
    {char * tlv42; tlv42 = (char *)(sizeof ( dive -> dive_site_name )); }
    {cgc_size_t tlv41; tlv41 = (cgc_size_t)(sizeof ( dive -> dive_site_name )); }
    {char * tlv44; tlv44 = (char *)(sizeof ( dive -> dive_site_name )); }
    {cgc_size_t tlv43; tlv43 = (cgc_size_t)(sizeof ( dive -> dive_site_name )); }
    {char * tlv46; tlv46 = (char *)(sizeof ( dive -> dive_site_name )); }
    {cgc_size_t tlv45; tlv45 = (cgc_size_t)(sizeof ( dive -> dive_site_name )); }
    {char * tlv48; tlv48 = (char *)(sizeof ( dive -> dive_site_name )); }
    {cgc_size_t tlv47; tlv47 = (cgc_size_t)(sizeof ( dive -> dive_site_name )); }
    {char * tlv67; tlv67 = (char *)(sizeof ( dive -> dive_site_name )); }
    {char * tlv51; tlv51 = (char *)(sizeof ( dive -> dive_site_name )); }
    {cgc_size_t tlv49; tlv49 = (cgc_size_t)(sizeof ( dive -> dive_site_name )); }
    {char * tlv54; tlv54 = (char *)(sizeof ( dive -> dive_site_name )); }
    {cgc_size_t tlv52; tlv52 = (cgc_size_t)(sizeof ( dive -> dive_site_name )); }
    {char * tlv57; tlv57 = (char *)(sizeof ( dive -> dive_site_name )); }
    {cgc_size_t tlv55; tlv55 = (cgc_size_t)(sizeof ( dive -> dive_site_name )); }
    {char * tlv60; tlv60 = (char *)(sizeof ( dive -> dive_site_name )); }
    {cgc_size_t tlv58; tlv58 = (cgc_size_t)(sizeof ( dive -> dive_site_name )); }
}
void fix_ingred_edit_dives_1_4(){
fix_ingred_edit_dives_1_4_0();
fix_ingred_edit_dives_1_4_1();
}
void fix_ingred_edit_dives_1_5_0(){
cgc_size_t count;
    bzero(&count,sizeof(cgc_size_t));
    {char buffer [ 1024 ]; buffer [ ( 1024 )-1 ] = (char)(count); }
    {char buf2 [ 1024 ]; buf2 [ ( 1024 )-1 ] = (char)(count); }
    {char * tlv28; tlv28 = (char *)(count); }
    {cgc_size_t tlv27; tlv27 = (cgc_size_t)(count); }
    {char * tlv30; tlv30 = (char *)(count); }
    {cgc_size_t tlv29; tlv29 = (cgc_size_t)(count); }
    {char * tlv32; tlv32 = (char *)(count); }
    {cgc_size_t tlv31; tlv31 = (cgc_size_t)(count); }
    {char * tlv9; tlv9 = (char *)(count); }
    {cgc_size_t tlv7; tlv7 = (cgc_size_t)(count); }
    {char * tlv12; tlv12 = (char *)(count); }
    {cgc_size_t tlv10; tlv10 = (cgc_size_t)(count); }
    {char * tlv34; tlv34 = (char *)(count); }
    {char * tlv36; tlv36 = (char *)(count); }
    {cgc_size_t tlv35; tlv35 = (cgc_size_t)(count); }
    {char * tlv38; tlv38 = (char *)(count); }
    {cgc_size_t tlv37; tlv37 = (cgc_size_t)(count); }
    {char * tlv40; tlv40 = (char *)(count); }
    {cgc_size_t tlv39; tlv39 = (cgc_size_t)(count); }
    {char * tlv42; tlv42 = (char *)(count); }
    {cgc_size_t tlv41; tlv41 = (cgc_size_t)(count); }
    {char * tlv44; tlv44 = (char *)(count); }
    {cgc_size_t tlv43; tlv43 = (cgc_size_t)(count); }
    {char * tlv46; tlv46 = (char *)(count); }
    {cgc_size_t tlv45; tlv45 = (cgc_size_t)(count); }
    {char * tlv48; tlv48 = (char *)(count); }
    {cgc_size_t tlv47; tlv47 = (cgc_size_t)(count); }
    {char * tlv67; tlv67 = (char *)(count); }
    {char * tlv51; tlv51 = (char *)(count); }
    {cgc_size_t tlv49; tlv49 = (cgc_size_t)(count); }
    {char * tlv54; tlv54 = (char *)(count); }
    {cgc_size_t tlv52; tlv52 = (cgc_size_t)(count); }
    {char * tlv57; tlv57 = (char *)(count); }
    {cgc_size_t tlv55; tlv55 = (cgc_size_t)(count); }
    {char * tlv60; tlv60 = (char *)(count); }
    {cgc_size_t tlv58; tlv58 = (cgc_size_t)(count); }
}
void fix_ingred_edit_dives_1_5_1(){
cgc_size_t count;
    bzero(&count,sizeof(cgc_size_t));
    {char buffer [ 1024 ]; buffer [ ( 1024 )-1 ] = (char)(0); }
    {char buf2 [ 1024 ]; buf2 [ ( 1024 )-1 ] = (char)(0); }
    {cgc_size_t count; count = (cgc_size_t)(0); }
    {char * tlv28; tlv28 = (char *)(0); }
    {cgc_size_t tlv27; tlv27 = (cgc_size_t)(0); }
    {char * tlv30; tlv30 = (char *)(0); }
    {cgc_size_t tlv29; tlv29 = (cgc_size_t)(0); }
    {char * tlv32; tlv32 = (char *)(0); }
    {cgc_size_t tlv31; tlv31 = (cgc_size_t)(0); }
    {char * tlv9; tlv9 = (char *)(0); }
    {cgc_size_t tlv7; tlv7 = (cgc_size_t)(0); }
    {char * tlv12; tlv12 = (char *)(0); }
    {cgc_size_t tlv10; tlv10 = (cgc_size_t)(0); }
    {char * tlv34; tlv34 = (char *)(0); }
    {char * tlv36; tlv36 = (char *)(0); }
    {cgc_size_t tlv35; tlv35 = (cgc_size_t)(0); }
    {char * tlv38; tlv38 = (char *)(0); }
    {cgc_size_t tlv37; tlv37 = (cgc_size_t)(0); }
    {char * tlv40; tlv40 = (char *)(0); }
    {cgc_size_t tlv39; tlv39 = (cgc_size_t)(0); }
    {char * tlv42; tlv42 = (char *)(0); }
    {cgc_size_t tlv41; tlv41 = (cgc_size_t)(0); }
    {char * tlv44; tlv44 = (char *)(0); }
    {cgc_size_t tlv43; tlv43 = (cgc_size_t)(0); }
    {char * tlv46; tlv46 = (char *)(0); }
    {cgc_size_t tlv45; tlv45 = (cgc_size_t)(0); }
    {char * tlv48; tlv48 = (char *)(0); }
    {cgc_size_t tlv47; tlv47 = (cgc_size_t)(0); }
    {char * tlv67; tlv67 = (char *)(0); }
    {char * tlv51; tlv51 = (char *)(0); }
    {cgc_size_t tlv49; tlv49 = (cgc_size_t)(0); }
    {char * tlv54; tlv54 = (char *)(0); }
    {cgc_size_t tlv52; tlv52 = (cgc_size_t)(0); }
    {char * tlv57; tlv57 = (char *)(0); }
    {cgc_size_t tlv55; tlv55 = (cgc_size_t)(0); }
    {char * tlv60; tlv60 = (char *)(0); }
    {cgc_size_t tlv58; tlv58 = (cgc_size_t)(0); }
}
void fix_ingred_edit_dives_1_5(){
fix_ingred_edit_dives_1_5_0();
fix_ingred_edit_dives_1_5_1();
}
void fix_ingred_edit_dives_1_6_0(){
dive_log_type dive_ref;
    bzero(&dive_ref,1*sizeof(dive_log_type));
dive_log_type * dive = &dive_ref;
    {char buffer [ 1024 ]; buffer [ ( 1024 )-1 ] = (char)(dive -> dive_site_name); }
    {char buf2 [ 1024 ]; buf2 [ ( 1024 )-1 ] = (char)(dive -> dive_site_name); }
    {cgc_size_t count; count = (cgc_size_t)(dive -> dive_site_name); }
    {char * tlv28; tlv28 = (char *)(dive -> dive_site_name); }
    {cgc_size_t tlv27; tlv27 = (cgc_size_t)(dive -> dive_site_name); }
    {char * tlv30; tlv30 = (char *)(dive -> dive_site_name); }
    {cgc_size_t tlv29; tlv29 = (cgc_size_t)(dive -> dive_site_name); }
    {char * tlv32; tlv32 = (char *)(dive -> dive_site_name); }
    {cgc_size_t tlv31; tlv31 = (cgc_size_t)(dive -> dive_site_name); }
    {char * tlv9; tlv9 = (char *)(dive -> dive_site_name); }
    {cgc_size_t tlv7; tlv7 = (cgc_size_t)(dive -> dive_site_name); }
    {char * tlv12; tlv12 = (char *)(dive -> dive_site_name); }
    {cgc_size_t tlv10; tlv10 = (cgc_size_t)(dive -> dive_site_name); }
    {char * tlv34; tlv34 = (char *)(dive -> dive_site_name); }
    {char * tlv36; tlv36 = (char *)(dive -> dive_site_name); }
    {cgc_size_t tlv35; tlv35 = (cgc_size_t)(dive -> dive_site_name); }
    {char * tlv38; tlv38 = (char *)(dive -> dive_site_name); }
    {cgc_size_t tlv37; tlv37 = (cgc_size_t)(dive -> dive_site_name); }
    {char * tlv40; tlv40 = (char *)(dive -> dive_site_name); }
    {cgc_size_t tlv39; tlv39 = (cgc_size_t)(dive -> dive_site_name); }
    {char * tlv42; tlv42 = (char *)(dive -> dive_site_name); }
    {cgc_size_t tlv41; tlv41 = (cgc_size_t)(dive -> dive_site_name); }
    {char * tlv44; tlv44 = (char *)(dive -> dive_site_name); }
    {cgc_size_t tlv43; tlv43 = (cgc_size_t)(dive -> dive_site_name); }
    {char * tlv46; tlv46 = (char *)(dive -> dive_site_name); }
    {cgc_size_t tlv45; tlv45 = (cgc_size_t)(dive -> dive_site_name); }
    {char * tlv48; tlv48 = (char *)(dive -> dive_site_name); }
    {cgc_size_t tlv47; tlv47 = (cgc_size_t)(dive -> dive_site_name); }
    {char * tlv67; tlv67 = (char *)(dive -> dive_site_name); }
    {char * tlv51; tlv51 = (char *)(dive -> dive_site_name); }
    {cgc_size_t tlv49; tlv49 = (cgc_size_t)(dive -> dive_site_name); }
    {char * tlv54; tlv54 = (char *)(dive -> dive_site_name); }
    {cgc_size_t tlv52; tlv52 = (cgc_size_t)(dive -> dive_site_name); }
    {char * tlv57; tlv57 = (char *)(dive -> dive_site_name); }
    {cgc_size_t tlv55; tlv55 = (cgc_size_t)(dive -> dive_site_name); }
    {char * tlv60; tlv60 = (char *)(dive -> dive_site_name); }
    {cgc_size_t tlv58; tlv58 = (cgc_size_t)(dive -> dive_site_name); }
}
void fix_ingred_edit_dives_1_6(){
fix_ingred_edit_dives_1_6_0();
}
void fix_ingred_edit_dives_1_10_1(){
dive_log_type dive_ref;
    bzero(&dive_ref,1*sizeof(dive_log_type));
dive_log_type * dive = &dive_ref;
    {char buffer [ 1024 ]; buffer [ ( 1024 )-1 ] = (char)(sizeof ( dive -> dive_date )); }
    {char buf2 [ 1024 ]; buf2 [ ( 1024 )-1 ] = (char)(sizeof ( dive -> dive_date )); }
    {cgc_size_t count; count = (cgc_size_t)(sizeof ( dive -> dive_date )); }
    {char * tlv28; tlv28 = (char *)(sizeof ( dive -> dive_date )); }
    {cgc_size_t tlv27; tlv27 = (cgc_size_t)(sizeof ( dive -> dive_date )); }
    {char * tlv30; tlv30 = (char *)(sizeof ( dive -> dive_date )); }
    {cgc_size_t tlv29; tlv29 = (cgc_size_t)(sizeof ( dive -> dive_date )); }
    {char * tlv32; tlv32 = (char *)(sizeof ( dive -> dive_date )); }
    {cgc_size_t tlv31; tlv31 = (cgc_size_t)(sizeof ( dive -> dive_date )); }
    {char * tlv9; tlv9 = (char *)(sizeof ( dive -> dive_date )); }
    {cgc_size_t tlv7; tlv7 = (cgc_size_t)(sizeof ( dive -> dive_date )); }
    {char * tlv12; tlv12 = (char *)(sizeof ( dive -> dive_date )); }
    {cgc_size_t tlv10; tlv10 = (cgc_size_t)(sizeof ( dive -> dive_date )); }
    {char * tlv34; tlv34 = (char *)(sizeof ( dive -> dive_date )); }
    {char * tlv36; tlv36 = (char *)(sizeof ( dive -> dive_date )); }
    {cgc_size_t tlv35; tlv35 = (cgc_size_t)(sizeof ( dive -> dive_date )); }
    {char * tlv38; tlv38 = (char *)(sizeof ( dive -> dive_date )); }
    {cgc_size_t tlv37; tlv37 = (cgc_size_t)(sizeof ( dive -> dive_date )); }
    {char * tlv40; tlv40 = (char *)(sizeof ( dive -> dive_date )); }
    {cgc_size_t tlv39; tlv39 = (cgc_size_t)(sizeof ( dive -> dive_date )); }
    {char * tlv42; tlv42 = (char *)(sizeof ( dive -> dive_date )); }
    {cgc_size_t tlv41; tlv41 = (cgc_size_t)(sizeof ( dive -> dive_date )); }
    {char * tlv44; tlv44 = (char *)(sizeof ( dive -> dive_date )); }
    {cgc_size_t tlv43; tlv43 = (cgc_size_t)(sizeof ( dive -> dive_date )); }
    {char * tlv46; tlv46 = (char *)(sizeof ( dive -> dive_date )); }
    {cgc_size_t tlv45; tlv45 = (cgc_size_t)(sizeof ( dive -> dive_date )); }
    {char * tlv48; tlv48 = (char *)(sizeof ( dive -> dive_date )); }
    {cgc_size_t tlv47; tlv47 = (cgc_size_t)(sizeof ( dive -> dive_date )); }
    {char * tlv67; tlv67 = (char *)(sizeof ( dive -> dive_date )); }
    {char * tlv51; tlv51 = (char *)(sizeof ( dive -> dive_date )); }
    {cgc_size_t tlv49; tlv49 = (cgc_size_t)(sizeof ( dive -> dive_date )); }
    {char * tlv54; tlv54 = (char *)(sizeof ( dive -> dive_date )); }
    {cgc_size_t tlv52; tlv52 = (cgc_size_t)(sizeof ( dive -> dive_date )); }
    {char * tlv57; tlv57 = (char *)(sizeof ( dive -> dive_date )); }
    {cgc_size_t tlv55; tlv55 = (cgc_size_t)(sizeof ( dive -> dive_date )); }
    {char * tlv60; tlv60 = (char *)(sizeof ( dive -> dive_date )); }
    {cgc_size_t tlv58; tlv58 = (cgc_size_t)(sizeof ( dive -> dive_date )); }
}
void fix_ingred_edit_dives_1_10(){
fix_ingred_edit_dives_1_10_1();
}
void fix_ingred_edit_dives_1_12_0(){
dive_log_type dive_ref;
    bzero(&dive_ref,1*sizeof(dive_log_type));
dive_log_type * dive = &dive_ref;
    {char buffer [ 1024 ]; buffer [ ( 1024 )-1 ] = (char)(dive -> dive_date); }
    {char buf2 [ 1024 ]; buf2 [ ( 1024 )-1 ] = (char)(dive -> dive_date); }
    {cgc_size_t count; count = (cgc_size_t)(dive -> dive_date); }
    {char * tlv28; tlv28 = (char *)(dive -> dive_date); }
    {cgc_size_t tlv27; tlv27 = (cgc_size_t)(dive -> dive_date); }
    {char * tlv30; tlv30 = (char *)(dive -> dive_date); }
    {cgc_size_t tlv29; tlv29 = (cgc_size_t)(dive -> dive_date); }
    {char * tlv32; tlv32 = (char *)(dive -> dive_date); }
    {cgc_size_t tlv31; tlv31 = (cgc_size_t)(dive -> dive_date); }
    {char * tlv9; tlv9 = (char *)(dive -> dive_date); }
    {cgc_size_t tlv7; tlv7 = (cgc_size_t)(dive -> dive_date); }
    {char * tlv12; tlv12 = (char *)(dive -> dive_date); }
    {cgc_size_t tlv10; tlv10 = (cgc_size_t)(dive -> dive_date); }
    {char * tlv34; tlv34 = (char *)(dive -> dive_date); }
    {char * tlv36; tlv36 = (char *)(dive -> dive_date); }
    {cgc_size_t tlv35; tlv35 = (cgc_size_t)(dive -> dive_date); }
    {char * tlv38; tlv38 = (char *)(dive -> dive_date); }
    {cgc_size_t tlv37; tlv37 = (cgc_size_t)(dive -> dive_date); }
    {char * tlv40; tlv40 = (char *)(dive -> dive_date); }
    {cgc_size_t tlv39; tlv39 = (cgc_size_t)(dive -> dive_date); }
    {char * tlv42; tlv42 = (char *)(dive -> dive_date); }
    {cgc_size_t tlv41; tlv41 = (cgc_size_t)(dive -> dive_date); }
    {char * tlv44; tlv44 = (char *)(dive -> dive_date); }
    {cgc_size_t tlv43; tlv43 = (cgc_size_t)(dive -> dive_date); }
    {char * tlv46; tlv46 = (char *)(dive -> dive_date); }
    {cgc_size_t tlv45; tlv45 = (cgc_size_t)(dive -> dive_date); }
    {char * tlv48; tlv48 = (char *)(dive -> dive_date); }
    {cgc_size_t tlv47; tlv47 = (cgc_size_t)(dive -> dive_date); }
    {char * tlv67; tlv67 = (char *)(dive -> dive_date); }
    {char * tlv51; tlv51 = (char *)(dive -> dive_date); }
    {cgc_size_t tlv49; tlv49 = (cgc_size_t)(dive -> dive_date); }
    {char * tlv54; tlv54 = (char *)(dive -> dive_date); }
    {cgc_size_t tlv52; tlv52 = (cgc_size_t)(dive -> dive_date); }
    {char * tlv57; tlv57 = (char *)(dive -> dive_date); }
    {cgc_size_t tlv55; tlv55 = (cgc_size_t)(dive -> dive_date); }
    {char * tlv60; tlv60 = (char *)(dive -> dive_date); }
    {cgc_size_t tlv58; tlv58 = (cgc_size_t)(dive -> dive_date); }
}
void fix_ingred_edit_dives_1_12(){
fix_ingred_edit_dives_1_12_0();
}
void fix_ingred_edit_dives_1_16_0(){
char buf2 [ 1024 ];
    bzero(&buf2,( 1024 *sizeof(char) ) );
dive_log_type dive_ref;
    bzero(&dive_ref,1*sizeof(dive_log_type));
dive_log_type * dive = &dive_ref;
    {char buffer [ 1024 ]; buffer [ ( 1024 )-1 ] = (char)(buf2); }
    {char buf2 [ 1024 ]; buf2 [ ( 1024 )-1 ] = (char)(buf2); }
    {cgc_size_t count; count = (cgc_size_t)(buf2); }
    {char * tlv28; tlv28 = (char *)(buf2); }
    {cgc_size_t tlv27; tlv27 = (cgc_size_t)(buf2); }
    {char * tlv30; tlv30 = (char *)(buf2); }
    {cgc_size_t tlv29; tlv29 = (cgc_size_t)(buf2); }
    {char * tlv32; tlv32 = (char *)(buf2); }
    {cgc_size_t tlv31; tlv31 = (cgc_size_t)(buf2); }
    {char * tlv9; tlv9 = (char *)(buf2); }
    {cgc_size_t tlv7; tlv7 = (cgc_size_t)(buf2); }
    {char * tlv12; tlv12 = (char *)(buf2); }
    {cgc_size_t tlv10; tlv10 = (cgc_size_t)(buf2); }
    {char * tlv34; tlv34 = (char *)(buf2); }
    {char * tlv36; tlv36 = (char *)(buf2); }
    {cgc_size_t tlv35; tlv35 = (cgc_size_t)(buf2); }
    {char * tlv38; tlv38 = (char *)(buf2); }
    {cgc_size_t tlv37; tlv37 = (cgc_size_t)(buf2); }
    {char * tlv40; tlv40 = (char *)(buf2); }
    {cgc_size_t tlv39; tlv39 = (cgc_size_t)(buf2); }
    {char * tlv42; tlv42 = (char *)(buf2); }
    {cgc_size_t tlv41; tlv41 = (cgc_size_t)(buf2); }
    {char * tlv44; tlv44 = (char *)(buf2); }
    {cgc_size_t tlv43; tlv43 = (cgc_size_t)(buf2); }
    {char * tlv46; tlv46 = (char *)(buf2); }
    {cgc_size_t tlv45; tlv45 = (cgc_size_t)(buf2); }
    {char * tlv48; tlv48 = (char *)(buf2); }
    {cgc_size_t tlv47; tlv47 = (cgc_size_t)(buf2); }
    {char * tlv67; tlv67 = (char *)(buf2); }
    {char * tlv51; tlv51 = (char *)(buf2); }
    {cgc_size_t tlv49; tlv49 = (cgc_size_t)(buf2); }
    {char * tlv54; tlv54 = (char *)(buf2); }
    {cgc_size_t tlv52; tlv52 = (cgc_size_t)(buf2); }
    {char * tlv57; tlv57 = (char *)(buf2); }
    {cgc_size_t tlv55; tlv55 = (cgc_size_t)(buf2); }
    {char * tlv60; tlv60 = (char *)(buf2); }
    {cgc_size_t tlv58; tlv58 = (cgc_size_t)(buf2); }
}
void fix_ingred_edit_dives_1_16_1(){
char buf2 [ 1024 ];
    bzero(&buf2,( 1024 *sizeof(char) ) );
dive_log_type dive_ref;
    bzero(&dive_ref,1*sizeof(dive_log_type));
dive_log_type * dive = &dive_ref;
    {char buffer [ 1024 ]; buffer [ ( 1024 )-1 ] = (char)(sizeof ( dive -> dive_time )); }
    {char buf2 [ 1024 ]; buf2 [ ( 1024 )-1 ] = (char)(sizeof ( dive -> dive_time )); }
    {cgc_size_t count; count = (cgc_size_t)(sizeof ( dive -> dive_time )); }
    {char * tlv28; tlv28 = (char *)(sizeof ( dive -> dive_time )); }
    {cgc_size_t tlv27; tlv27 = (cgc_size_t)(sizeof ( dive -> dive_time )); }
    {char * tlv30; tlv30 = (char *)(sizeof ( dive -> dive_time )); }
    {cgc_size_t tlv29; tlv29 = (cgc_size_t)(sizeof ( dive -> dive_time )); }
    {char * tlv32; tlv32 = (char *)(sizeof ( dive -> dive_time )); }
    {cgc_size_t tlv31; tlv31 = (cgc_size_t)(sizeof ( dive -> dive_time )); }
    {char * tlv9; tlv9 = (char *)(sizeof ( dive -> dive_time )); }
    {cgc_size_t tlv7; tlv7 = (cgc_size_t)(sizeof ( dive -> dive_time )); }
    {char * tlv12; tlv12 = (char *)(sizeof ( dive -> dive_time )); }
    {cgc_size_t tlv10; tlv10 = (cgc_size_t)(sizeof ( dive -> dive_time )); }
    {char * tlv34; tlv34 = (char *)(sizeof ( dive -> dive_time )); }
    {char * tlv36; tlv36 = (char *)(sizeof ( dive -> dive_time )); }
    {cgc_size_t tlv35; tlv35 = (cgc_size_t)(sizeof ( dive -> dive_time )); }
    {char * tlv38; tlv38 = (char *)(sizeof ( dive -> dive_time )); }
    {cgc_size_t tlv37; tlv37 = (cgc_size_t)(sizeof ( dive -> dive_time )); }
    {char * tlv40; tlv40 = (char *)(sizeof ( dive -> dive_time )); }
    {cgc_size_t tlv39; tlv39 = (cgc_size_t)(sizeof ( dive -> dive_time )); }
    {char * tlv42; tlv42 = (char *)(sizeof ( dive -> dive_time )); }
    {cgc_size_t tlv41; tlv41 = (cgc_size_t)(sizeof ( dive -> dive_time )); }
    {char * tlv44; tlv44 = (char *)(sizeof ( dive -> dive_time )); }
    {cgc_size_t tlv43; tlv43 = (cgc_size_t)(sizeof ( dive -> dive_time )); }
    {char * tlv46; tlv46 = (char *)(sizeof ( dive -> dive_time )); }
    {cgc_size_t tlv45; tlv45 = (cgc_size_t)(sizeof ( dive -> dive_time )); }
    {char * tlv48; tlv48 = (char *)(sizeof ( dive -> dive_time )); }
    {cgc_size_t tlv47; tlv47 = (cgc_size_t)(sizeof ( dive -> dive_time )); }
    {char * tlv67; tlv67 = (char *)(sizeof ( dive -> dive_time )); }
    {char * tlv51; tlv51 = (char *)(sizeof ( dive -> dive_time )); }
    {cgc_size_t tlv49; tlv49 = (cgc_size_t)(sizeof ( dive -> dive_time )); }
    {char * tlv54; tlv54 = (char *)(sizeof ( dive -> dive_time )); }
    {cgc_size_t tlv52; tlv52 = (cgc_size_t)(sizeof ( dive -> dive_time )); }
    {char * tlv57; tlv57 = (char *)(sizeof ( dive -> dive_time )); }
    {cgc_size_t tlv55; tlv55 = (cgc_size_t)(sizeof ( dive -> dive_time )); }
    {char * tlv60; tlv60 = (char *)(sizeof ( dive -> dive_time )); }
    {cgc_size_t tlv58; tlv58 = (cgc_size_t)(sizeof ( dive -> dive_time )); }
}
void fix_ingred_edit_dives_1_16(){
fix_ingred_edit_dives_1_16_0();
fix_ingred_edit_dives_1_16_1();
}
void fix_ingred_edit_dives_1_18_0(){
dive_log_type dive_ref;
    bzero(&dive_ref,1*sizeof(dive_log_type));
dive_log_type * dive = &dive_ref;
    {char buffer [ 1024 ]; buffer [ ( 1024 )-1 ] = (char)(dive -> dive_time); }
    {char buf2 [ 1024 ]; buf2 [ ( 1024 )-1 ] = (char)(dive -> dive_time); }
    {cgc_size_t count; count = (cgc_size_t)(dive -> dive_time); }
    {char * tlv28; tlv28 = (char *)(dive -> dive_time); }
    {cgc_size_t tlv27; tlv27 = (cgc_size_t)(dive -> dive_time); }
    {char * tlv30; tlv30 = (char *)(dive -> dive_time); }
    {cgc_size_t tlv29; tlv29 = (cgc_size_t)(dive -> dive_time); }
    {char * tlv32; tlv32 = (char *)(dive -> dive_time); }
    {cgc_size_t tlv31; tlv31 = (cgc_size_t)(dive -> dive_time); }
    {char * tlv9; tlv9 = (char *)(dive -> dive_time); }
    {cgc_size_t tlv7; tlv7 = (cgc_size_t)(dive -> dive_time); }
    {char * tlv12; tlv12 = (char *)(dive -> dive_time); }
    {cgc_size_t tlv10; tlv10 = (cgc_size_t)(dive -> dive_time); }
    {char * tlv34; tlv34 = (char *)(dive -> dive_time); }
    {char * tlv36; tlv36 = (char *)(dive -> dive_time); }
    {cgc_size_t tlv35; tlv35 = (cgc_size_t)(dive -> dive_time); }
    {char * tlv38; tlv38 = (char *)(dive -> dive_time); }
    {cgc_size_t tlv37; tlv37 = (cgc_size_t)(dive -> dive_time); }
    {char * tlv40; tlv40 = (char *)(dive -> dive_time); }
    {cgc_size_t tlv39; tlv39 = (cgc_size_t)(dive -> dive_time); }
    {char * tlv42; tlv42 = (char *)(dive -> dive_time); }
    {cgc_size_t tlv41; tlv41 = (cgc_size_t)(dive -> dive_time); }
    {char * tlv44; tlv44 = (char *)(dive -> dive_time); }
    {cgc_size_t tlv43; tlv43 = (cgc_size_t)(dive -> dive_time); }
    {char * tlv46; tlv46 = (char *)(dive -> dive_time); }
    {cgc_size_t tlv45; tlv45 = (cgc_size_t)(dive -> dive_time); }
    {char * tlv48; tlv48 = (char *)(dive -> dive_time); }
    {cgc_size_t tlv47; tlv47 = (cgc_size_t)(dive -> dive_time); }
    {char * tlv67; tlv67 = (char *)(dive -> dive_time); }
    {char * tlv51; tlv51 = (char *)(dive -> dive_time); }
    {cgc_size_t tlv49; tlv49 = (cgc_size_t)(dive -> dive_time); }
    {char * tlv54; tlv54 = (char *)(dive -> dive_time); }
    {cgc_size_t tlv52; tlv52 = (cgc_size_t)(dive -> dive_time); }
    {char * tlv57; tlv57 = (char *)(dive -> dive_time); }
    {cgc_size_t tlv55; tlv55 = (cgc_size_t)(dive -> dive_time); }
    {char * tlv60; tlv60 = (char *)(dive -> dive_time); }
    {cgc_size_t tlv58; tlv58 = (cgc_size_t)(dive -> dive_time); }
}
void fix_ingred_edit_dives_1_18(){
fix_ingred_edit_dives_1_18_0();
}
void fix_ingred_edit_dives_1_19_1(){
    {char buffer [ 1024 ]; buffer [ ( 1024 )-1 ] = (char)(1); }
    {char buf2 [ 1024 ]; buf2 [ ( 1024 )-1 ] = (char)(1); }
    {cgc_size_t count; count = (cgc_size_t)(1); }
    {char * tlv28; tlv28 = (char *)(1); }
    {cgc_size_t tlv27; tlv27 = (cgc_size_t)(1); }
    {char * tlv30; tlv30 = (char *)(1); }
    {cgc_size_t tlv29; tlv29 = (cgc_size_t)(1); }
    {char * tlv32; tlv32 = (char *)(1); }
    {cgc_size_t tlv31; tlv31 = (cgc_size_t)(1); }
    {char * tlv9; tlv9 = (char *)(1); }
    {cgc_size_t tlv7; tlv7 = (cgc_size_t)(1); }
    {char * tlv12; tlv12 = (char *)(1); }
    {cgc_size_t tlv10; tlv10 = (cgc_size_t)(1); }
    {char * tlv34; tlv34 = (char *)(1); }
    {char * tlv36; tlv36 = (char *)(1); }
    {cgc_size_t tlv35; tlv35 = (cgc_size_t)(1); }
    {char * tlv38; tlv38 = (char *)(1); }
    {cgc_size_t tlv37; tlv37 = (cgc_size_t)(1); }
    {char * tlv40; tlv40 = (char *)(1); }
    {cgc_size_t tlv39; tlv39 = (cgc_size_t)(1); }
    {char * tlv42; tlv42 = (char *)(1); }
    {cgc_size_t tlv41; tlv41 = (cgc_size_t)(1); }
    {char * tlv44; tlv44 = (char *)(1); }
    {cgc_size_t tlv43; tlv43 = (cgc_size_t)(1); }
    {char * tlv46; tlv46 = (char *)(1); }
    {cgc_size_t tlv45; tlv45 = (cgc_size_t)(1); }
    {char * tlv48; tlv48 = (char *)(1); }
    {cgc_size_t tlv47; tlv47 = (cgc_size_t)(1); }
    {char * tlv67; tlv67 = (char *)(1); }
    {char * tlv51; tlv51 = (char *)(1); }
    {cgc_size_t tlv49; tlv49 = (cgc_size_t)(1); }
    {char * tlv54; tlv54 = (char *)(1); }
    {cgc_size_t tlv52; tlv52 = (cgc_size_t)(1); }
    {char * tlv57; tlv57 = (char *)(1); }
    {cgc_size_t tlv55; tlv55 = (cgc_size_t)(1); }
    {char * tlv60; tlv60 = (char *)(1); }
    {cgc_size_t tlv58; tlv58 = (cgc_size_t)(1); }
}
void fix_ingred_edit_dives_1_19(){
fix_ingred_edit_dives_1_19_1();
}
void fix_ingred_edit_dives_1_21_1(){
char tlv67_ref;
    bzero(&tlv67_ref,1*sizeof(char));
char * tlv67 = &tlv67_ref;
    {char buffer [ 1024 ]; buffer [ ( 1024 )-1 ] = (char)(cgc_strlen ( tlv67 )); }
    {char buf2 [ 1024 ]; buf2 [ ( 1024 )-1 ] = (char)(cgc_strlen ( tlv67 )); }
    {cgc_size_t count; count = (cgc_size_t)(cgc_strlen ( tlv67 )); }
    {char * tlv28; tlv28 = (char *)(cgc_strlen ( tlv67 )); }
    {cgc_size_t tlv27; tlv27 = (cgc_size_t)(cgc_strlen ( tlv67 )); }
    {char * tlv30; tlv30 = (char *)(cgc_strlen ( tlv67 )); }
    {cgc_size_t tlv29; tlv29 = (cgc_size_t)(cgc_strlen ( tlv67 )); }
    {char * tlv32; tlv32 = (char *)(cgc_strlen ( tlv67 )); }
    {cgc_size_t tlv31; tlv31 = (cgc_size_t)(cgc_strlen ( tlv67 )); }
    {char * tlv9; tlv9 = (char *)(cgc_strlen ( tlv67 )); }
    {cgc_size_t tlv7; tlv7 = (cgc_size_t)(cgc_strlen ( tlv67 )); }
    {char * tlv12; tlv12 = (char *)(cgc_strlen ( tlv67 )); }
    {cgc_size_t tlv10; tlv10 = (cgc_size_t)(cgc_strlen ( tlv67 )); }
    {char * tlv34; tlv34 = (char *)(cgc_strlen ( tlv67 )); }
    {char * tlv36; tlv36 = (char *)(cgc_strlen ( tlv67 )); }
    {cgc_size_t tlv35; tlv35 = (cgc_size_t)(cgc_strlen ( tlv67 )); }
    {char * tlv38; tlv38 = (char *)(cgc_strlen ( tlv67 )); }
    {cgc_size_t tlv37; tlv37 = (cgc_size_t)(cgc_strlen ( tlv67 )); }
    {char * tlv40; tlv40 = (char *)(cgc_strlen ( tlv67 )); }
    {cgc_size_t tlv39; tlv39 = (cgc_size_t)(cgc_strlen ( tlv67 )); }
    {char * tlv42; tlv42 = (char *)(cgc_strlen ( tlv67 )); }
    {cgc_size_t tlv41; tlv41 = (cgc_size_t)(cgc_strlen ( tlv67 )); }
    {char * tlv44; tlv44 = (char *)(cgc_strlen ( tlv67 )); }
    {cgc_size_t tlv43; tlv43 = (cgc_size_t)(cgc_strlen ( tlv67 )); }
    {char * tlv46; tlv46 = (char *)(cgc_strlen ( tlv67 )); }
    {cgc_size_t tlv45; tlv45 = (cgc_size_t)(cgc_strlen ( tlv67 )); }
    {char * tlv48; tlv48 = (char *)(cgc_strlen ( tlv67 )); }
    {cgc_size_t tlv47; tlv47 = (cgc_size_t)(cgc_strlen ( tlv67 )); }
    {char * tlv51; tlv51 = (char *)(cgc_strlen ( tlv67 )); }
    {cgc_size_t tlv49; tlv49 = (cgc_size_t)(cgc_strlen ( tlv67 )); }
    {char * tlv54; tlv54 = (char *)(cgc_strlen ( tlv67 )); }
    {cgc_size_t tlv52; tlv52 = (cgc_size_t)(cgc_strlen ( tlv67 )); }
    {char * tlv57; tlv57 = (char *)(cgc_strlen ( tlv67 )); }
    {cgc_size_t tlv55; tlv55 = (cgc_size_t)(cgc_strlen ( tlv67 )); }
    {char * tlv60; tlv60 = (char *)(cgc_strlen ( tlv67 )); }
    {cgc_size_t tlv58; tlv58 = (cgc_size_t)(cgc_strlen ( tlv67 )); }
}
void fix_ingred_edit_dives_1_21(){
fix_ingred_edit_dives_1_21_1();
}
void fix_ingred_edit_dives_1_26_1(){
char buffer [ 1024 ];
    bzero(&buffer,( 1024 *sizeof(char) ) );
    {char buffer [ 1024 ]; buffer [ ( 1024 )-1 ] = (char)(sizeof ( buffer )); }
    {char buf2 [ 1024 ]; buf2 [ ( 1024 )-1 ] = (char)(sizeof ( buffer )); }
    {cgc_size_t count; count = (cgc_size_t)(sizeof ( buffer )); }
    {char * tlv28; tlv28 = (char *)(sizeof ( buffer )); }
    {cgc_size_t tlv27; tlv27 = (cgc_size_t)(sizeof ( buffer )); }
    {char * tlv30; tlv30 = (char *)(sizeof ( buffer )); }
    {cgc_size_t tlv29; tlv29 = (cgc_size_t)(sizeof ( buffer )); }
    {char * tlv32; tlv32 = (char *)(sizeof ( buffer )); }
    {cgc_size_t tlv31; tlv31 = (cgc_size_t)(sizeof ( buffer )); }
    {char * tlv9; tlv9 = (char *)(sizeof ( buffer )); }
    {cgc_size_t tlv7; tlv7 = (cgc_size_t)(sizeof ( buffer )); }
    {char * tlv12; tlv12 = (char *)(sizeof ( buffer )); }
    {cgc_size_t tlv10; tlv10 = (cgc_size_t)(sizeof ( buffer )); }
    {char * tlv34; tlv34 = (char *)(sizeof ( buffer )); }
    {char * tlv36; tlv36 = (char *)(sizeof ( buffer )); }
    {cgc_size_t tlv35; tlv35 = (cgc_size_t)(sizeof ( buffer )); }
    {char * tlv38; tlv38 = (char *)(sizeof ( buffer )); }
    {cgc_size_t tlv37; tlv37 = (cgc_size_t)(sizeof ( buffer )); }
    {char * tlv40; tlv40 = (char *)(sizeof ( buffer )); }
    {cgc_size_t tlv39; tlv39 = (cgc_size_t)(sizeof ( buffer )); }
    {char * tlv42; tlv42 = (char *)(sizeof ( buffer )); }
    {cgc_size_t tlv41; tlv41 = (cgc_size_t)(sizeof ( buffer )); }
    {char * tlv44; tlv44 = (char *)(sizeof ( buffer )); }
    {cgc_size_t tlv43; tlv43 = (cgc_size_t)(sizeof ( buffer )); }
    {char * tlv46; tlv46 = (char *)(sizeof ( buffer )); }
    {cgc_size_t tlv45; tlv45 = (cgc_size_t)(sizeof ( buffer )); }
    {char * tlv48; tlv48 = (char *)(sizeof ( buffer )); }
    {cgc_size_t tlv47; tlv47 = (cgc_size_t)(sizeof ( buffer )); }
    {char * tlv67; tlv67 = (char *)(sizeof ( buffer )); }
    {char * tlv51; tlv51 = (char *)(sizeof ( buffer )); }
    {cgc_size_t tlv49; tlv49 = (cgc_size_t)(sizeof ( buffer )); }
    {char * tlv54; tlv54 = (char *)(sizeof ( buffer )); }
    {cgc_size_t tlv52; tlv52 = (cgc_size_t)(sizeof ( buffer )); }
    {char * tlv57; tlv57 = (char *)(sizeof ( buffer )); }
    {cgc_size_t tlv55; tlv55 = (cgc_size_t)(sizeof ( buffer )); }
    {char * tlv60; tlv60 = (char *)(sizeof ( buffer )); }
    {cgc_size_t tlv58; tlv58 = (cgc_size_t)(sizeof ( buffer )); }
}
void fix_ingred_edit_dives_1_26(){
fix_ingred_edit_dives_1_26_1();
}
void fix_ingred_edit_dives_1_28_0(){
dive_log_type dive_ref;
    bzero(&dive_ref,1*sizeof(dive_log_type));
dive_log_type * dive = &dive_ref;
    {char buffer [ 1024 ]; buffer [ ( 1024 )-1 ] = (char)(dive -> location); }
    {char buf2 [ 1024 ]; buf2 [ ( 1024 )-1 ] = (char)(dive -> location); }
    {cgc_size_t count; count = (cgc_size_t)(dive -> location); }
    {char * tlv28; tlv28 = (char *)(dive -> location); }
    {cgc_size_t tlv27; tlv27 = (cgc_size_t)(dive -> location); }
    {char * tlv30; tlv30 = (char *)(dive -> location); }
    {cgc_size_t tlv29; tlv29 = (cgc_size_t)(dive -> location); }
    {char * tlv32; tlv32 = (char *)(dive -> location); }
    {cgc_size_t tlv31; tlv31 = (cgc_size_t)(dive -> location); }
    {char * tlv9; tlv9 = (char *)(dive -> location); }
    {cgc_size_t tlv7; tlv7 = (cgc_size_t)(dive -> location); }
    {char * tlv12; tlv12 = (char *)(dive -> location); }
    {cgc_size_t tlv10; tlv10 = (cgc_size_t)(dive -> location); }
    {char * tlv34; tlv34 = (char *)(dive -> location); }
    {char * tlv36; tlv36 = (char *)(dive -> location); }
    {cgc_size_t tlv35; tlv35 = (cgc_size_t)(dive -> location); }
    {char * tlv38; tlv38 = (char *)(dive -> location); }
    {cgc_size_t tlv37; tlv37 = (cgc_size_t)(dive -> location); }
    {char * tlv40; tlv40 = (char *)(dive -> location); }
    {cgc_size_t tlv39; tlv39 = (cgc_size_t)(dive -> location); }
    {char * tlv42; tlv42 = (char *)(dive -> location); }
    {cgc_size_t tlv41; tlv41 = (cgc_size_t)(dive -> location); }
    {char * tlv44; tlv44 = (char *)(dive -> location); }
    {cgc_size_t tlv43; tlv43 = (cgc_size_t)(dive -> location); }
    {char * tlv46; tlv46 = (char *)(dive -> location); }
    {cgc_size_t tlv45; tlv45 = (cgc_size_t)(dive -> location); }
    {char * tlv48; tlv48 = (char *)(dive -> location); }
    {cgc_size_t tlv47; tlv47 = (cgc_size_t)(dive -> location); }
    {char * tlv67; tlv67 = (char *)(dive -> location); }
    {char * tlv51; tlv51 = (char *)(dive -> location); }
    {cgc_size_t tlv49; tlv49 = (cgc_size_t)(dive -> location); }
    {char * tlv54; tlv54 = (char *)(dive -> location); }
    {cgc_size_t tlv52; tlv52 = (cgc_size_t)(dive -> location); }
    {char * tlv57; tlv57 = (char *)(dive -> location); }
    {cgc_size_t tlv55; tlv55 = (cgc_size_t)(dive -> location); }
    {char * tlv60; tlv60 = (char *)(dive -> location); }
    {cgc_size_t tlv58; tlv58 = (cgc_size_t)(dive -> location); }
}
void fix_ingred_edit_dives_1_28(){
fix_ingred_edit_dives_1_28_0();
}
void fix_ingred_edit_dives_1_44_1(){
    {char buffer [ 1024 ]; buffer [ ( 1024 )-1 ] = (char)(13); }
    {char buf2 [ 1024 ]; buf2 [ ( 1024 )-1 ] = (char)(13); }
    {cgc_size_t count; count = (cgc_size_t)(13); }
    {char * tlv28; tlv28 = (char *)(13); }
    {cgc_size_t tlv27; tlv27 = (cgc_size_t)(13); }
    {char * tlv30; tlv30 = (char *)(13); }
    {cgc_size_t tlv29; tlv29 = (cgc_size_t)(13); }
    {char * tlv32; tlv32 = (char *)(13); }
    {cgc_size_t tlv31; tlv31 = (cgc_size_t)(13); }
    {char * tlv9; tlv9 = (char *)(13); }
    {cgc_size_t tlv7; tlv7 = (cgc_size_t)(13); }
    {char * tlv12; tlv12 = (char *)(13); }
    {cgc_size_t tlv10; tlv10 = (cgc_size_t)(13); }
    {char * tlv34; tlv34 = (char *)(13); }
    {char * tlv36; tlv36 = (char *)(13); }
    {cgc_size_t tlv35; tlv35 = (cgc_size_t)(13); }
    {char * tlv38; tlv38 = (char *)(13); }
    {cgc_size_t tlv37; tlv37 = (cgc_size_t)(13); }
    {char * tlv40; tlv40 = (char *)(13); }
    {cgc_size_t tlv39; tlv39 = (cgc_size_t)(13); }
    {char * tlv42; tlv42 = (char *)(13); }
    {cgc_size_t tlv41; tlv41 = (cgc_size_t)(13); }
    {char * tlv44; tlv44 = (char *)(13); }
    {cgc_size_t tlv43; tlv43 = (cgc_size_t)(13); }
    {char * tlv46; tlv46 = (char *)(13); }
    {cgc_size_t tlv45; tlv45 = (cgc_size_t)(13); }
    {char * tlv48; tlv48 = (char *)(13); }
    {cgc_size_t tlv47; tlv47 = (cgc_size_t)(13); }
    {char * tlv67; tlv67 = (char *)(13); }
    {char * tlv51; tlv51 = (char *)(13); }
    {cgc_size_t tlv49; tlv49 = (cgc_size_t)(13); }
    {char * tlv54; tlv54 = (char *)(13); }
    {cgc_size_t tlv52; tlv52 = (cgc_size_t)(13); }
    {char * tlv57; tlv57 = (char *)(13); }
    {cgc_size_t tlv55; tlv55 = (cgc_size_t)(13); }
    {char * tlv60; tlv60 = (char *)(13); }
    {cgc_size_t tlv58; tlv58 = (cgc_size_t)(13); }
}
void fix_ingred_edit_dives_1_44(){
fix_ingred_edit_dives_1_44_1();
}
void fix_ingred_edit_dives_1_50_1(){
    {char buffer [ 1024 ]; buffer [ ( 1024 )-1 ] = (char)(11); }
    {char buf2 [ 1024 ]; buf2 [ ( 1024 )-1 ] = (char)(11); }
    {cgc_size_t count; count = (cgc_size_t)(11); }
    {char * tlv28; tlv28 = (char *)(11); }
    {cgc_size_t tlv27; tlv27 = (cgc_size_t)(11); }
    {char * tlv30; tlv30 = (char *)(11); }
    {cgc_size_t tlv29; tlv29 = (cgc_size_t)(11); }
    {char * tlv32; tlv32 = (char *)(11); }
    {cgc_size_t tlv31; tlv31 = (cgc_size_t)(11); }
    {char * tlv9; tlv9 = (char *)(11); }
    {cgc_size_t tlv7; tlv7 = (cgc_size_t)(11); }
    {char * tlv12; tlv12 = (char *)(11); }
    {cgc_size_t tlv10; tlv10 = (cgc_size_t)(11); }
    {char * tlv34; tlv34 = (char *)(11); }
    {char * tlv36; tlv36 = (char *)(11); }
    {cgc_size_t tlv35; tlv35 = (cgc_size_t)(11); }
    {char * tlv38; tlv38 = (char *)(11); }
    {cgc_size_t tlv37; tlv37 = (cgc_size_t)(11); }
    {char * tlv40; tlv40 = (char *)(11); }
    {cgc_size_t tlv39; tlv39 = (cgc_size_t)(11); }
    {char * tlv42; tlv42 = (char *)(11); }
    {cgc_size_t tlv41; tlv41 = (cgc_size_t)(11); }
    {char * tlv44; tlv44 = (char *)(11); }
    {cgc_size_t tlv43; tlv43 = (cgc_size_t)(11); }
    {char * tlv46; tlv46 = (char *)(11); }
    {cgc_size_t tlv45; tlv45 = (cgc_size_t)(11); }
    {char * tlv48; tlv48 = (char *)(11); }
    {cgc_size_t tlv47; tlv47 = (cgc_size_t)(11); }
    {char * tlv67; tlv67 = (char *)(11); }
    {char * tlv51; tlv51 = (char *)(11); }
    {cgc_size_t tlv49; tlv49 = (cgc_size_t)(11); }
    {char * tlv54; tlv54 = (char *)(11); }
    {cgc_size_t tlv52; tlv52 = (cgc_size_t)(11); }
    {char * tlv57; tlv57 = (char *)(11); }
    {cgc_size_t tlv55; tlv55 = (cgc_size_t)(11); }
    {char * tlv60; tlv60 = (char *)(11); }
    {cgc_size_t tlv58; tlv58 = (cgc_size_t)(11); }
}
void fix_ingred_edit_dives_1_50(){
fix_ingred_edit_dives_1_50_1();
}
void fix_ingred_edit_dives_1_56_1(){
    {char buffer [ 1024 ]; buffer [ ( 1024 )-1 ] = (char)(20); }
    {char buf2 [ 1024 ]; buf2 [ ( 1024 )-1 ] = (char)(20); }
    {cgc_size_t count; count = (cgc_size_t)(20); }
    {char * tlv28; tlv28 = (char *)(20); }
    {cgc_size_t tlv27; tlv27 = (cgc_size_t)(20); }
    {char * tlv30; tlv30 = (char *)(20); }
    {cgc_size_t tlv29; tlv29 = (cgc_size_t)(20); }
    {char * tlv32; tlv32 = (char *)(20); }
    {cgc_size_t tlv31; tlv31 = (cgc_size_t)(20); }
    {char * tlv9; tlv9 = (char *)(20); }
    {cgc_size_t tlv7; tlv7 = (cgc_size_t)(20); }
    {char * tlv12; tlv12 = (char *)(20); }
    {cgc_size_t tlv10; tlv10 = (cgc_size_t)(20); }
    {char * tlv34; tlv34 = (char *)(20); }
    {char * tlv36; tlv36 = (char *)(20); }
    {cgc_size_t tlv35; tlv35 = (cgc_size_t)(20); }
    {char * tlv38; tlv38 = (char *)(20); }
    {cgc_size_t tlv37; tlv37 = (cgc_size_t)(20); }
    {char * tlv40; tlv40 = (char *)(20); }
    {cgc_size_t tlv39; tlv39 = (cgc_size_t)(20); }
    {char * tlv42; tlv42 = (char *)(20); }
    {cgc_size_t tlv41; tlv41 = (cgc_size_t)(20); }
    {char * tlv44; tlv44 = (char *)(20); }
    {cgc_size_t tlv43; tlv43 = (cgc_size_t)(20); }
    {char * tlv46; tlv46 = (char *)(20); }
    {cgc_size_t tlv45; tlv45 = (cgc_size_t)(20); }
    {char * tlv48; tlv48 = (char *)(20); }
    {cgc_size_t tlv47; tlv47 = (cgc_size_t)(20); }
    {char * tlv67; tlv67 = (char *)(20); }
    {char * tlv51; tlv51 = (char *)(20); }
    {cgc_size_t tlv49; tlv49 = (cgc_size_t)(20); }
    {char * tlv54; tlv54 = (char *)(20); }
    {cgc_size_t tlv52; tlv52 = (cgc_size_t)(20); }
    {char * tlv57; tlv57 = (char *)(20); }
    {cgc_size_t tlv55; tlv55 = (cgc_size_t)(20); }
    {char * tlv60; tlv60 = (char *)(20); }
    {cgc_size_t tlv58; tlv58 = (cgc_size_t)(20); }
}
void fix_ingred_edit_dives_1_56(){
fix_ingred_edit_dives_1_56_1();
}
void fix_ingred_edit_dives_1(){
fix_ingred_edit_dives_1_4();
fix_ingred_edit_dives_1_5();
fix_ingred_edit_dives_1_6();
fix_ingred_edit_dives_1_10();
fix_ingred_edit_dives_1_12();
fix_ingred_edit_dives_1_16();
fix_ingred_edit_dives_1_18();
fix_ingred_edit_dives_1_19();
fix_ingred_edit_dives_1_21();
fix_ingred_edit_dives_1_26();
fix_ingred_edit_dives_1_28();
fix_ingred_edit_dives_1_44();
fix_ingred_edit_dives_1_50();
fix_ingred_edit_dives_1_56();
}
