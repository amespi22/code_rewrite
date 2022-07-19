

#include "libcgc.h"
#include "cgc_service.h"
#include "cgc_stdlib.h"
#include "cgc_malloc.h"
#include "cgc_dates.h"

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

void fix_ingred_download_dive_0_0_0();
void fix_ingred_download_dive_0_0();
void fix_ingred_download_dive_0_1_1();
void fix_ingred_download_dive_0_1();
void fix_ingred_download_dive_0_2_3();
void fix_ingred_download_dive_0_2();
void fix_ingred_download_dive_0_4_1();
void fix_ingred_download_dive_0_4();
void fix_ingred_download_dive_0_8_0();
void fix_ingred_download_dive_0_8_1();
void fix_ingred_download_dive_0_8();
void fix_ingred_download_dive_0_10_0();
void fix_ingred_download_dive_0_10();
void fix_ingred_download_dive_0_16_1();
void fix_ingred_download_dive_0_16();
void fix_ingred_download_dive_0_21_1();
void fix_ingred_download_dive_0_21();
void fix_ingred_download_dive_0_28_1();
void fix_ingred_download_dive_0_28();
void fix_ingred_download_dive_0_31_1();
void fix_ingred_download_dive_0_31();
void fix_ingred_download_dive_0_32_1();
void fix_ingred_download_dive_0_32();
void fix_ingred_download_dive_0_33_0();
void fix_ingred_download_dive_0_33_1();
void fix_ingred_download_dive_0_33();
void fix_ingred_download_dive_0_34_10();
void fix_ingred_download_dive_0_34_11();
void fix_ingred_download_dive_0_34();
void fix_ingred_download_dive_0_36_0();
void fix_ingred_download_dive_0_36();
void fix_ingred_download_dive_0_38_17();
void fix_ingred_download_dive_0_38_18();
void fix_ingred_download_dive_0_38();
void fix_ingred_download_dive_0_39_17();
void fix_ingred_download_dive_0_39();
void fix_ingred_download_dive_0_44_0();
void fix_ingred_download_dive_0_44_1();
void fix_ingred_download_dive_0_44();
void fix_ingred_download_dive_0_45_16();
void fix_ingred_download_dive_0_45_17();
void fix_ingred_download_dive_0_45();
void fix_ingred_download_dive_0_46_0();
void fix_ingred_download_dive_0_46();
void fix_ingred_download_dive_0_50_1();
void fix_ingred_download_dive_0_50();
void fix_ingred_download_dive_0_56_0();
void fix_ingred_download_dive_0_56_1();
void fix_ingred_download_dive_0_56();
void fix_ingred_download_dive_0_62_1();
void fix_ingred_download_dive_0_62();
void fix_ingred_download_dive_0_64_0();
void fix_ingred_download_dive_0_64();
void fix_ingred_download_dive_0_68_1();
void fix_ingred_download_dive_0_68();
void fix_ingred_download_dive_0_80_1();
void fix_ingred_download_dive_0_80();
void fix_ingred_download_dive_0_86_1();
void fix_ingred_download_dive_0_86();
void fix_ingred_download_dive_0_92_1();
void fix_ingred_download_dive_0_92();
void fix_ingred_download_dive_0();
int cgc_download_dive(logbook_type * Info)
{
if (fix_ingred_enable){ fix_ingred_download_dive_0(); };
    dive_log_type *next_dive;
    char buffer[1024];
    char buffer2[1024];
    cgc_size_t count;
    int ret_code;
    time_t sample_time;
    time_t first_sample;
    int sample_depth;
    struct dive_data *temp_ptr;
    datetime_struct_type tm;
    int max_depth;
    max_depth = 0;
    int sum_depth;
    sum_depth = 0;
    int count_samples;
    count_samples = 0;
    time_t delta_time;
    int *bins;
    int bin_number;
    int i;
    // receive the first samples outside of the loop to start the linked list
    {
        unsigned char* tlv28;
         tlv28 = ( unsigned  char * ) & first_sample;
        cgc_size_t tlv27;
        tlv27 = sizeof ( first_sample );
        ret_code = cgc_receive_bytes(tlv28,tlv27);
    }
    if (ret_code < 0) {
 {
     const char tlv55 [ ] = "received error code \n";
    	cgc_printf(tlv55);
 }
	return -1;
    }

    {
        unsigned char* tlv30;
         tlv30 = ( unsigned  char * ) & sample_depth;
        cgc_size_t tlv29;
        tlv29 = sizeof ( sample_depth );
        ret_code = cgc_receive_bytes(tlv30,tlv29);
    }
    if (ret_code < 0) {
 {
     const char tlv56 [ ] = "received error code or zero sample \n";
    	cgc_printf(tlv56);
 }
	return -1;
    }
    // ok we got a valid sample, so allocate the data for the new dive 
    // if its the first dive in the log
    if (Info->dives == 0) {
 {
     cgc_size_t tlv72;
     tlv72 = 1;
     cgc_size_t tlv71;
     tlv71 = sizeof ( dive_log_type );
    	Info->dives = cgc_calloc(tlv72,tlv71);
 }
	if (Info->dives == 0) {
     {
         unsigned int tlv87;
         tlv87 = - 1;
    	    cgc__terminate(tlv87);
     }
	}
	next_dive = Info->dives;
    }
    // otherwise, add it to the end of the log
    else {
	next_dive = Info->dives;
	while (next_dive->next != 0)
 {
	    next_dive = next_dive->next;
 }
 {
     cgc_size_t tlv74;
     tlv74 = 1;
     cgc_size_t tlv73;
     tlv73 = sizeof ( dive_log_type );
    	next_dive->next = cgc_calloc(tlv74,tlv73);
 }
	if (next_dive->next == 0) {
     {
         unsigned int tlv88;
         tlv88 = - 1;
    	    cgc__terminate(tlv88);
     }
	}
	next_dive = next_dive->next;
    }
    // now allocate memory for the first data point in the dive
    {
        cgc_size_t tlv32;
        tlv32 = 1;
        cgc_size_t tlv31;
        tlv31 = sizeof ( struct dive_data );
        next_dive->data = cgc_calloc(tlv32,tlv31);
    }
    if (next_dive->data == 0) {
 {
     unsigned int tlv57;
     tlv57 = - 1;
    	cgc__terminate(tlv57);
 }
    }
    temp_ptr = next_dive->data;
    temp_ptr->timestamp = first_sample;
    temp_ptr->depth = sample_depth;
    // if (sample_depth > max_depth)
    //      max_depth=sample_depth;
    // sum_depth+=sample_depth;
    // count_samples++;
    // convert the timestamp value into a broken out structure of the date/time
    // this will be used to fill out part of the meta data about the dive
    {
        time_t tlv2;
        tlv2 = first_sample;
        datetime_struct_type* tlv1;
        tlv1 = & tm;
        cgc_time_t2datetime(tlv2,tlv1);
    }
    // now loops and get more data samples
    while (1) {
 {
     unsigned char* tlv76;
      tlv76 = ( unsigned  char * ) & sample_time;
     cgc_size_t tlv75;
     tlv75 = sizeof ( sample_time );
    	ret_code = cgc_receive_bytes(tlv76,tlv75);
 }
	if (ret_code < 0) {
     {
         const char tlv89 [ ] = "received error code or zero timestamp \n";
    	    cgc_printf(tlv89);
     }
	    return -1;
	}
	// input is terminated by a zero timestamp value 
	if (sample_time == 0) {
	    break;
	}
 {
     unsigned char* tlv78;
      tlv78 = ( unsigned  char * ) & sample_depth;
     cgc_size_t tlv77;
     tlv77 = sizeof ( sample_depth );
    	ret_code = cgc_receive_bytes(tlv78,tlv77);
 }
	if (ret_code < 0) {
     {
         const char tlv90 [ ] = "received error code or zero sample \n";
    	    cgc_printf(tlv90);
     }
	    return -1;
	}
 {
     cgc_size_t tlv80;
     tlv80 = 1;
     cgc_size_t tlv79;
     tlv79 = sizeof ( dive_data_type );
    	temp_ptr->next = cgc_calloc(tlv80,tlv79);
 }
	if (temp_ptr->next == 0) {
     {
         unsigned int tlv91;
         tlv91 = - 1;
    	    cgc__terminate(tlv91);
     }
	}
	temp_ptr = temp_ptr->next;
	temp_ptr->timestamp = sample_time;
	temp_ptr->depth = sample_depth;
    }
    temp_ptr->next = 0;
    // calculate the start to finish duration of the dive in seconds
    delta_time = temp_ptr->timestamp - first_sample;
    // set the dive time to the first sample
    next_dive->timestamp = first_sample;
    {
        datetime_struct_type* tlv4;
        tlv4 = & tm;
        char* tlv3;
         tlv3 = next_dive -> dive_date;
        cgc_to_date_str(tlv4,tlv3);
    }
    {
        datetime_struct_type* tlv6;
        tlv6 = & tm;
        char* tlv5;
         tlv5 = next_dive -> dive_time;
        cgc_to_time_str(tlv6,tlv5);
    }
    //timestamps are in seconds, convert the delta to minutes for the dive log
    next_dive->dive_length = delta_time / 60;
    //setup bins per minute of the dive
    {
        cgc_size_t tlv34;
        tlv34 = next_dive -> dive_length + 1;
        cgc_size_t tlv33;
        tlv33 = sizeof ( int );
        bins = cgc_calloc(tlv34,tlv33);
    }
    if (bins == 0) {
 {
     unsigned int tlv58;
     tlv58 = - 1;
    	cgc__terminate(tlv58);
 }
    }
    // now run through the samples to collect meta data for the dive log
    max_depth = 0;
    sum_depth = 0;
    count_samples = 0;
    temp_ptr = next_dive->data;
    while (temp_ptr != 0) {
	if (temp_ptr->depth > max_depth) {
	    max_depth = temp_ptr->depth;
	}
	sum_depth += temp_ptr->depth;
	count_samples++;
	bin_number = (temp_ptr->timestamp - first_sample) / 60;
	bins[bin_number]++;
	temp_ptr = temp_ptr->next;
    }
    next_dive->bincount = 0;
    for (i = 0; i < next_dive->dive_length + 1; ++i)
    {
	next_dive->bincount += bins[i];
    }
    cgc_free(bins);
    next_dive->max_depth = max_depth;
    if (count_samples > 0) {
	next_dive->avg_depth = sum_depth / count_samples;
    } else {
	next_dive->avg_depth = 0;
    }
    // now prompt for the remaining entries, but also allow editing of stuff from the data
    {
        const char tlv7 [ ] = "Dive Site";
        cgc_printf(tlv7);
    }
    if (next_dive->dive_site_name[0] != 0) {
	cgc_printf(" (@s)", next_dive->dive_site_name);
    }
    {
        const char tlv8 [ ] = ": ";
        cgc_printf(tlv8);
    }
    {
        char* tlv36;
         tlv36 = buffer;
        cgc_size_t tlv35;
        tlv35 = sizeof ( next_dive -> dive_site_name );
        count = cgc_getline(tlv36,tlv35);
    }
    if (count > 0) {
 {
     char* tlv61;
      tlv61 = next_dive -> dive_site_name;
     const char* tlv60 = buffer;
     cgc_size_t tlv59;
     tlv59 = sizeof ( next_dive -> dive_site_name );
    	cgc_strncpy(tlv61,tlv60,tlv59);
 }
    }
    {
        const char tlv9 [ ] = "Date";
        cgc_printf(tlv9);
    }
    if (next_dive->dive_date[0] != 0) {
	cgc_printf(" (@s)", next_dive->dive_date);
    }
    {
        const char tlv10 [ ] = ": ";
        cgc_printf(tlv10);
    }
    {
        char* tlv38;
         tlv38 = buffer;
        cgc_size_t tlv37;
        tlv37 = sizeof ( next_dive -> dive_date );
        count = cgc_getline(tlv38,tlv37);
    }
    if (count > 0) {
 {
     char* tlv64;
      tlv64 = next_dive -> dive_date;
     const char* tlv63 = buffer;
     cgc_size_t tlv62;
     tlv62 = count;
    	cgc_strncpy(tlv64,tlv63,tlv62);
 }
    }
    {
        const char tlv11 [ ] = "Time";
        cgc_printf(tlv11);
    }
    if (next_dive->dive_time[0] != 0) {
	cgc_printf(" (@s)", next_dive->dive_time);
    }
    {
        const char tlv12 [ ] = ": ";
        cgc_printf(tlv12);
    }
    {
        char* tlv40;
         tlv40 = buffer2;
        cgc_size_t tlv39;
        tlv39 = sizeof ( next_dive -> dive_time );
        count = cgc_getline(tlv40,tlv39);
    }
    if (count > 0) {
 {
     char* tlv67;
      tlv67 = next_dive -> dive_time;
     const char* tlv66 = buffer2;
     cgc_size_t tlv65;
     tlv65 = count;
    	cgc_strncpy(tlv67,tlv66,tlv65);
 }
    }
    {
        const char tlv13 [ ] = "Location (area/city)";
        cgc_printf(tlv13);
    }
    if (next_dive->location[0] != 0) {
	cgc_printf(" (@s)", next_dive->location);
    }
    {
        const char tlv14 [ ] = ": ";
        cgc_printf(tlv14);
    }
    {
        char* tlv42;
         tlv42 = buffer;
        cgc_size_t tlv41;
        tlv41 = sizeof ( next_dive -> location );
        count = cgc_getline(tlv42,tlv41);
    }
    if (count > 0) {
 {
     char* tlv70;
      tlv70 = next_dive -> location;
     const char* tlv69 = buffer;
     cgc_size_t tlv68;
     tlv68 = count;
    	cgc_strncpy(tlv70,tlv69,tlv68);
 }
    }
    {
        const char tlv15 [ ] = "Max Depth in ft";
        cgc_printf(tlv15);
    }
    if (next_dive->max_depth != 0) {
	cgc_printf(" (@d)", next_dive->max_depth);
    }
    {
        const char tlv16 [ ] = ": ";
        cgc_printf(tlv16);
    }
    {
        char* tlv44;
         tlv44 = buffer;
        cgc_size_t tlv43;
        tlv43 = sizeof ( buffer );
        count = cgc_getline(tlv44,tlv43);
    }
    if (count > 0) {
 {
     const char* tlv81 = buffer;
    	next_dive->max_depth = cgc_atoi(tlv81);
 }
    }
    {
        const char tlv17 [ ] = "Avg Depth in ft";
        cgc_printf(tlv17);
    }
    if (next_dive->avg_depth != 0) {
	cgc_printf(" (@d)", next_dive->avg_depth);
    }
    {
        const char tlv18 [ ] = ": ";
        cgc_printf(tlv18);
    }
    {
        char* tlv46;
         tlv46 = buffer;
        cgc_size_t tlv45;
        tlv45 = sizeof ( buffer );
        count = cgc_getline(tlv46,tlv45);
    }
    if (count > 0) {
 {
     const char* tlv82 = buffer;
    	next_dive->avg_depth = cgc_atoi(tlv82);
 }
    }
    {
        const char tlv19 [ ] = "Dive Duration (mins)";
        cgc_printf(tlv19);
    }
    if (next_dive->dive_length != 0) {
	cgc_printf(" (@d)", next_dive->dive_length);
    }
    {
        const char tlv20 [ ] = ": ";
        cgc_printf(tlv20);
    }
    {
        char* tlv48;
         tlv48 = buffer;
        cgc_size_t tlv47;
        tlv47 = 13;
        count = cgc_getline(tlv48,tlv47);
    }
    if (count > 0) {
 {
     const char* tlv83 = buffer;
    	next_dive->dive_length = cgc_atoi(tlv83);
 }
    }
    {
        const char tlv21 [ ] = "O2 Percentage";
        cgc_printf(tlv21);
    }
    if (next_dive->O2_percent != 0) {
	cgc_printf(" (@d)", next_dive->O2_percent);
    }
    {
        const char tlv22 [ ] = ": ";
        cgc_printf(tlv22);
    }
    {
        char* tlv50;
         tlv50 = buffer;
        cgc_size_t tlv49;
        tlv49 = 11;
        count = cgc_getline(tlv50,tlv49);
    }
    if (count > 0) {
 {
     const char* tlv84 = buffer;
    	next_dive->O2_percent = cgc_atoi(tlv84);
 }
    }

    {
        const char tlv23 [ ] = "Pressure In (psi)";
        cgc_printf(tlv23);
    }
    if (next_dive->pressure_in != 0) {
	cgc_printf(" (@d)", next_dive->pressure_in);
    }
    {
        const char tlv24 [ ] = ": ";
        cgc_printf(tlv24);
    }
    {
        char* tlv52;
         tlv52 = buffer;
        cgc_size_t tlv51;
        tlv51 = 20;
        count = cgc_getline(tlv52,tlv51);
    }
    if (count > 0) {
 {
     const char* tlv85 = buffer;
    	next_dive->pressure_in = cgc_atoi(tlv85);
 }
    }
    {
        const char tlv25 [ ] = "Pressure Out (psi)";
        cgc_printf(tlv25);
    }
    if (next_dive->pressure_out != 0) {
	cgc_printf(" (@d)", next_dive->pressure_out);
    }
    {
        const char tlv26 [ ] = ": ";
        cgc_printf(tlv26);
    }
    {
        char* tlv54;
         tlv54 = buffer;
        cgc_size_t tlv53;
        tlv53 = 11;
        count = cgc_getline(tlv54,tlv53);
    }
    if (count > 0) {
 {
     const char* tlv86 = buffer;
    	next_dive->pressure_out = cgc_atoi(tlv86);
 }
    }
    next_dive->next = 0;
    return 0;
}

void fix_ingred_download_dive_0_0_0(){
    {char buffer [ 1024 ]; buffer [ ( 1024 )-1 ] = (char)(0); }
    {char buffer2 [ 1024 ]; buffer2 [ ( 1024 )-1 ] = (char)(0); }
    {cgc_size_t count; count = (cgc_size_t)(0); }
    {int ret_code; ret_code = (int)(0); }
    {int sample_depth; sample_depth = (int)(0); }
    {int max_depth; max_depth = (int)(0); }
    {int sum_depth; sum_depth = (int)(0); }
    {int count_samples; count_samples = (int)(0); }
    {int * bins; bins = (int *)(0); }
    {int bin_number; bin_number = (int)(0); }
    {int i; i = (int)(0); }
    {cgc_size_t tlv27; tlv27 = (cgc_size_t)(0); }
    {cgc_size_t tlv29; tlv29 = (cgc_size_t)(0); }
    {cgc_size_t tlv32; tlv32 = (cgc_size_t)(0); }
    {cgc_size_t tlv31; tlv31 = (cgc_size_t)(0); }
    {char * tlv3; tlv3 = (char *)(0); }
    {char * tlv5; tlv5 = (char *)(0); }
    {cgc_size_t tlv34; tlv34 = (cgc_size_t)(0); }
    {cgc_size_t tlv33; tlv33 = (cgc_size_t)(0); }
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
    {char * tlv50; tlv50 = (char *)(0); }
    {cgc_size_t tlv49; tlv49 = (cgc_size_t)(0); }
    {char * tlv52; tlv52 = (char *)(0); }
    {cgc_size_t tlv51; tlv51 = (cgc_size_t)(0); }
    {char * tlv54; tlv54 = (char *)(0); }
    {cgc_size_t tlv53; tlv53 = (cgc_size_t)(0); }
    {cgc_size_t tlv72; tlv72 = (cgc_size_t)(0); }
    {cgc_size_t tlv71; tlv71 = (cgc_size_t)(0); }
    {cgc_size_t tlv74; tlv74 = (cgc_size_t)(0); }
    {cgc_size_t tlv73; tlv73 = (cgc_size_t)(0); }
    {unsigned int tlv57; tlv57 = (unsigned int)(0); }
    {cgc_size_t tlv75; tlv75 = (cgc_size_t)(0); }
    {cgc_size_t tlv77; tlv77 = (cgc_size_t)(0); }
    {cgc_size_t tlv80; tlv80 = (cgc_size_t)(0); }
    {cgc_size_t tlv79; tlv79 = (cgc_size_t)(0); }
    {unsigned int tlv58; tlv58 = (unsigned int)(0); }
    {char * tlv61; tlv61 = (char *)(0); }
    {cgc_size_t tlv59; tlv59 = (cgc_size_t)(0); }
    {char * tlv64; tlv64 = (char *)(0); }
    {cgc_size_t tlv62; tlv62 = (cgc_size_t)(0); }
    {char * tlv67; tlv67 = (char *)(0); }
    {cgc_size_t tlv65; tlv65 = (cgc_size_t)(0); }
    {char * tlv70; tlv70 = (char *)(0); }
    {cgc_size_t tlv68; tlv68 = (cgc_size_t)(0); }
    {unsigned int tlv87; tlv87 = (unsigned int)(0); }
    {unsigned int tlv88; tlv88 = (unsigned int)(0); }
    {unsigned int tlv91; tlv91 = (unsigned int)(0); }
}
void fix_ingred_download_dive_0_0(){
fix_ingred_download_dive_0_0_0();
}
void fix_ingred_download_dive_0_1_1(){
time_t first_sample;
    bzero(&first_sample,sizeof(time_t));
    {char buffer [ 1024 ]; buffer [ ( 1024 )-1 ] = (char)(sizeof ( first_sample )); }
    {char buffer2 [ 1024 ]; buffer2 [ ( 1024 )-1 ] = (char)(sizeof ( first_sample )); }
    {cgc_size_t count; count = (cgc_size_t)(sizeof ( first_sample )); }
    {int ret_code; ret_code = (int)(sizeof ( first_sample )); }
    {int sample_depth; sample_depth = (int)(sizeof ( first_sample )); }
    {int max_depth; max_depth = (int)(sizeof ( first_sample )); }
    {int sum_depth; sum_depth = (int)(sizeof ( first_sample )); }
    {int count_samples; count_samples = (int)(sizeof ( first_sample )); }
    {int * bins; bins = (int *)(sizeof ( first_sample )); }
    {int bin_number; bin_number = (int)(sizeof ( first_sample )); }
    {int i; i = (int)(sizeof ( first_sample )); }
    {cgc_size_t tlv27; tlv27 = (cgc_size_t)(sizeof ( first_sample )); }
    {cgc_size_t tlv29; tlv29 = (cgc_size_t)(sizeof ( first_sample )); }
    {cgc_size_t tlv32; tlv32 = (cgc_size_t)(sizeof ( first_sample )); }
    {cgc_size_t tlv31; tlv31 = (cgc_size_t)(sizeof ( first_sample )); }
    {char * tlv3; tlv3 = (char *)(sizeof ( first_sample )); }
    {char * tlv5; tlv5 = (char *)(sizeof ( first_sample )); }
    {cgc_size_t tlv34; tlv34 = (cgc_size_t)(sizeof ( first_sample )); }
    {cgc_size_t tlv33; tlv33 = (cgc_size_t)(sizeof ( first_sample )); }
    {char * tlv36; tlv36 = (char *)(sizeof ( first_sample )); }
    {cgc_size_t tlv35; tlv35 = (cgc_size_t)(sizeof ( first_sample )); }
    {char * tlv38; tlv38 = (char *)(sizeof ( first_sample )); }
    {cgc_size_t tlv37; tlv37 = (cgc_size_t)(sizeof ( first_sample )); }
    {char * tlv40; tlv40 = (char *)(sizeof ( first_sample )); }
    {cgc_size_t tlv39; tlv39 = (cgc_size_t)(sizeof ( first_sample )); }
    {char * tlv42; tlv42 = (char *)(sizeof ( first_sample )); }
    {cgc_size_t tlv41; tlv41 = (cgc_size_t)(sizeof ( first_sample )); }
    {char * tlv44; tlv44 = (char *)(sizeof ( first_sample )); }
    {cgc_size_t tlv43; tlv43 = (cgc_size_t)(sizeof ( first_sample )); }
    {char * tlv46; tlv46 = (char *)(sizeof ( first_sample )); }
    {cgc_size_t tlv45; tlv45 = (cgc_size_t)(sizeof ( first_sample )); }
    {char * tlv48; tlv48 = (char *)(sizeof ( first_sample )); }
    {cgc_size_t tlv47; tlv47 = (cgc_size_t)(sizeof ( first_sample )); }
    {char * tlv50; tlv50 = (char *)(sizeof ( first_sample )); }
    {cgc_size_t tlv49; tlv49 = (cgc_size_t)(sizeof ( first_sample )); }
    {char * tlv52; tlv52 = (char *)(sizeof ( first_sample )); }
    {cgc_size_t tlv51; tlv51 = (cgc_size_t)(sizeof ( first_sample )); }
    {char * tlv54; tlv54 = (char *)(sizeof ( first_sample )); }
    {cgc_size_t tlv53; tlv53 = (cgc_size_t)(sizeof ( first_sample )); }
    {cgc_size_t tlv72; tlv72 = (cgc_size_t)(sizeof ( first_sample )); }
    {cgc_size_t tlv71; tlv71 = (cgc_size_t)(sizeof ( first_sample )); }
    {cgc_size_t tlv74; tlv74 = (cgc_size_t)(sizeof ( first_sample )); }
    {cgc_size_t tlv73; tlv73 = (cgc_size_t)(sizeof ( first_sample )); }
    {unsigned int tlv57; tlv57 = (unsigned int)(sizeof ( first_sample )); }
    {cgc_size_t tlv75; tlv75 = (cgc_size_t)(sizeof ( first_sample )); }
    {cgc_size_t tlv77; tlv77 = (cgc_size_t)(sizeof ( first_sample )); }
    {cgc_size_t tlv80; tlv80 = (cgc_size_t)(sizeof ( first_sample )); }
    {cgc_size_t tlv79; tlv79 = (cgc_size_t)(sizeof ( first_sample )); }
    {unsigned int tlv58; tlv58 = (unsigned int)(sizeof ( first_sample )); }
    {char * tlv61; tlv61 = (char *)(sizeof ( first_sample )); }
    {cgc_size_t tlv59; tlv59 = (cgc_size_t)(sizeof ( first_sample )); }
    {char * tlv64; tlv64 = (char *)(sizeof ( first_sample )); }
    {cgc_size_t tlv62; tlv62 = (cgc_size_t)(sizeof ( first_sample )); }
    {char * tlv67; tlv67 = (char *)(sizeof ( first_sample )); }
    {cgc_size_t tlv65; tlv65 = (cgc_size_t)(sizeof ( first_sample )); }
    {char * tlv70; tlv70 = (char *)(sizeof ( first_sample )); }
    {cgc_size_t tlv68; tlv68 = (cgc_size_t)(sizeof ( first_sample )); }
    {unsigned int tlv87; tlv87 = (unsigned int)(sizeof ( first_sample )); }
    {unsigned int tlv88; tlv88 = (unsigned int)(sizeof ( first_sample )); }
    {unsigned int tlv91; tlv91 = (unsigned int)(sizeof ( first_sample )); }
}
void fix_ingred_download_dive_0_1(){
fix_ingred_download_dive_0_1_1();
}
void fix_ingred_download_dive_0_2_3(){
int ret_code;
    bzero(&ret_code,sizeof(int));
    {char buffer [ 1024 ]; buffer [ ( 1024 )-1 ] = (char)(ret_code); }
    {char buffer2 [ 1024 ]; buffer2 [ ( 1024 )-1 ] = (char)(ret_code); }
    {cgc_size_t count; count = (cgc_size_t)(ret_code); }
    {int sample_depth; sample_depth = (int)(ret_code); }
    {int max_depth; max_depth = (int)(ret_code); }
    {int sum_depth; sum_depth = (int)(ret_code); }
    {int count_samples; count_samples = (int)(ret_code); }
    {int * bins; bins = (int *)(ret_code); }
    {int bin_number; bin_number = (int)(ret_code); }
    {int i; i = (int)(ret_code); }
    {cgc_size_t tlv27; tlv27 = (cgc_size_t)(ret_code); }
    {cgc_size_t tlv29; tlv29 = (cgc_size_t)(ret_code); }
    {cgc_size_t tlv32; tlv32 = (cgc_size_t)(ret_code); }
    {cgc_size_t tlv31; tlv31 = (cgc_size_t)(ret_code); }
    {char * tlv3; tlv3 = (char *)(ret_code); }
    {char * tlv5; tlv5 = (char *)(ret_code); }
    {cgc_size_t tlv34; tlv34 = (cgc_size_t)(ret_code); }
    {cgc_size_t tlv33; tlv33 = (cgc_size_t)(ret_code); }
    {char * tlv36; tlv36 = (char *)(ret_code); }
    {cgc_size_t tlv35; tlv35 = (cgc_size_t)(ret_code); }
    {char * tlv38; tlv38 = (char *)(ret_code); }
    {cgc_size_t tlv37; tlv37 = (cgc_size_t)(ret_code); }
    {char * tlv40; tlv40 = (char *)(ret_code); }
    {cgc_size_t tlv39; tlv39 = (cgc_size_t)(ret_code); }
    {char * tlv42; tlv42 = (char *)(ret_code); }
    {cgc_size_t tlv41; tlv41 = (cgc_size_t)(ret_code); }
    {char * tlv44; tlv44 = (char *)(ret_code); }
    {cgc_size_t tlv43; tlv43 = (cgc_size_t)(ret_code); }
    {char * tlv46; tlv46 = (char *)(ret_code); }
    {cgc_size_t tlv45; tlv45 = (cgc_size_t)(ret_code); }
    {char * tlv48; tlv48 = (char *)(ret_code); }
    {cgc_size_t tlv47; tlv47 = (cgc_size_t)(ret_code); }
    {char * tlv50; tlv50 = (char *)(ret_code); }
    {cgc_size_t tlv49; tlv49 = (cgc_size_t)(ret_code); }
    {char * tlv52; tlv52 = (char *)(ret_code); }
    {cgc_size_t tlv51; tlv51 = (cgc_size_t)(ret_code); }
    {char * tlv54; tlv54 = (char *)(ret_code); }
    {cgc_size_t tlv53; tlv53 = (cgc_size_t)(ret_code); }
    {cgc_size_t tlv72; tlv72 = (cgc_size_t)(ret_code); }
    {cgc_size_t tlv71; tlv71 = (cgc_size_t)(ret_code); }
    {cgc_size_t tlv74; tlv74 = (cgc_size_t)(ret_code); }
    {cgc_size_t tlv73; tlv73 = (cgc_size_t)(ret_code); }
    {unsigned int tlv57; tlv57 = (unsigned int)(ret_code); }
    {cgc_size_t tlv75; tlv75 = (cgc_size_t)(ret_code); }
    {cgc_size_t tlv77; tlv77 = (cgc_size_t)(ret_code); }
    {cgc_size_t tlv80; tlv80 = (cgc_size_t)(ret_code); }
    {cgc_size_t tlv79; tlv79 = (cgc_size_t)(ret_code); }
    {unsigned int tlv58; tlv58 = (unsigned int)(ret_code); }
    {char * tlv61; tlv61 = (char *)(ret_code); }
    {cgc_size_t tlv59; tlv59 = (cgc_size_t)(ret_code); }
    {char * tlv64; tlv64 = (char *)(ret_code); }
    {cgc_size_t tlv62; tlv62 = (cgc_size_t)(ret_code); }
    {char * tlv67; tlv67 = (char *)(ret_code); }
    {cgc_size_t tlv65; tlv65 = (cgc_size_t)(ret_code); }
    {char * tlv70; tlv70 = (char *)(ret_code); }
    {cgc_size_t tlv68; tlv68 = (cgc_size_t)(ret_code); }
    {unsigned int tlv87; tlv87 = (unsigned int)(ret_code); }
    {unsigned int tlv88; tlv88 = (unsigned int)(ret_code); }
    {unsigned int tlv91; tlv91 = (unsigned int)(ret_code); }
}
void fix_ingred_download_dive_0_2(){
fix_ingred_download_dive_0_2_3();
}
void fix_ingred_download_dive_0_4_1(){
int sample_depth;
    bzero(&sample_depth,sizeof(int));
    {char buffer [ 1024 ]; buffer [ ( 1024 )-1 ] = (char)(sizeof ( sample_depth )); }
    {char buffer2 [ 1024 ]; buffer2 [ ( 1024 )-1 ] = (char)(sizeof ( sample_depth )); }
    {cgc_size_t count; count = (cgc_size_t)(sizeof ( sample_depth )); }
    {int ret_code; ret_code = (int)(sizeof ( sample_depth )); }
    {int max_depth; max_depth = (int)(sizeof ( sample_depth )); }
    {int sum_depth; sum_depth = (int)(sizeof ( sample_depth )); }
    {int count_samples; count_samples = (int)(sizeof ( sample_depth )); }
    {int * bins; bins = (int *)(sizeof ( sample_depth )); }
    {int bin_number; bin_number = (int)(sizeof ( sample_depth )); }
    {int i; i = (int)(sizeof ( sample_depth )); }
    {cgc_size_t tlv27; tlv27 = (cgc_size_t)(sizeof ( sample_depth )); }
    {cgc_size_t tlv29; tlv29 = (cgc_size_t)(sizeof ( sample_depth )); }
    {cgc_size_t tlv32; tlv32 = (cgc_size_t)(sizeof ( sample_depth )); }
    {cgc_size_t tlv31; tlv31 = (cgc_size_t)(sizeof ( sample_depth )); }
    {char * tlv3; tlv3 = (char *)(sizeof ( sample_depth )); }
    {char * tlv5; tlv5 = (char *)(sizeof ( sample_depth )); }
    {cgc_size_t tlv34; tlv34 = (cgc_size_t)(sizeof ( sample_depth )); }
    {cgc_size_t tlv33; tlv33 = (cgc_size_t)(sizeof ( sample_depth )); }
    {char * tlv36; tlv36 = (char *)(sizeof ( sample_depth )); }
    {cgc_size_t tlv35; tlv35 = (cgc_size_t)(sizeof ( sample_depth )); }
    {char * tlv38; tlv38 = (char *)(sizeof ( sample_depth )); }
    {cgc_size_t tlv37; tlv37 = (cgc_size_t)(sizeof ( sample_depth )); }
    {char * tlv40; tlv40 = (char *)(sizeof ( sample_depth )); }
    {cgc_size_t tlv39; tlv39 = (cgc_size_t)(sizeof ( sample_depth )); }
    {char * tlv42; tlv42 = (char *)(sizeof ( sample_depth )); }
    {cgc_size_t tlv41; tlv41 = (cgc_size_t)(sizeof ( sample_depth )); }
    {char * tlv44; tlv44 = (char *)(sizeof ( sample_depth )); }
    {cgc_size_t tlv43; tlv43 = (cgc_size_t)(sizeof ( sample_depth )); }
    {char * tlv46; tlv46 = (char *)(sizeof ( sample_depth )); }
    {cgc_size_t tlv45; tlv45 = (cgc_size_t)(sizeof ( sample_depth )); }
    {char * tlv48; tlv48 = (char *)(sizeof ( sample_depth )); }
    {cgc_size_t tlv47; tlv47 = (cgc_size_t)(sizeof ( sample_depth )); }
    {char * tlv50; tlv50 = (char *)(sizeof ( sample_depth )); }
    {cgc_size_t tlv49; tlv49 = (cgc_size_t)(sizeof ( sample_depth )); }
    {char * tlv52; tlv52 = (char *)(sizeof ( sample_depth )); }
    {cgc_size_t tlv51; tlv51 = (cgc_size_t)(sizeof ( sample_depth )); }
    {char * tlv54; tlv54 = (char *)(sizeof ( sample_depth )); }
    {cgc_size_t tlv53; tlv53 = (cgc_size_t)(sizeof ( sample_depth )); }
    {cgc_size_t tlv72; tlv72 = (cgc_size_t)(sizeof ( sample_depth )); }
    {cgc_size_t tlv71; tlv71 = (cgc_size_t)(sizeof ( sample_depth )); }
    {cgc_size_t tlv74; tlv74 = (cgc_size_t)(sizeof ( sample_depth )); }
    {cgc_size_t tlv73; tlv73 = (cgc_size_t)(sizeof ( sample_depth )); }
    {unsigned int tlv57; tlv57 = (unsigned int)(sizeof ( sample_depth )); }
    {cgc_size_t tlv75; tlv75 = (cgc_size_t)(sizeof ( sample_depth )); }
    {cgc_size_t tlv77; tlv77 = (cgc_size_t)(sizeof ( sample_depth )); }
    {cgc_size_t tlv80; tlv80 = (cgc_size_t)(sizeof ( sample_depth )); }
    {cgc_size_t tlv79; tlv79 = (cgc_size_t)(sizeof ( sample_depth )); }
    {unsigned int tlv58; tlv58 = (unsigned int)(sizeof ( sample_depth )); }
    {char * tlv61; tlv61 = (char *)(sizeof ( sample_depth )); }
    {cgc_size_t tlv59; tlv59 = (cgc_size_t)(sizeof ( sample_depth )); }
    {char * tlv64; tlv64 = (char *)(sizeof ( sample_depth )); }
    {cgc_size_t tlv62; tlv62 = (cgc_size_t)(sizeof ( sample_depth )); }
    {char * tlv67; tlv67 = (char *)(sizeof ( sample_depth )); }
    {cgc_size_t tlv65; tlv65 = (cgc_size_t)(sizeof ( sample_depth )); }
    {char * tlv70; tlv70 = (char *)(sizeof ( sample_depth )); }
    {cgc_size_t tlv68; tlv68 = (cgc_size_t)(sizeof ( sample_depth )); }
    {unsigned int tlv87; tlv87 = (unsigned int)(sizeof ( sample_depth )); }
    {unsigned int tlv88; tlv88 = (unsigned int)(sizeof ( sample_depth )); }
    {unsigned int tlv91; tlv91 = (unsigned int)(sizeof ( sample_depth )); }
}
void fix_ingred_download_dive_0_4(){
fix_ingred_download_dive_0_4_1();
}
void fix_ingred_download_dive_0_8_0(){
    {char buffer [ 1024 ]; buffer [ ( 1024 )-1 ] = (char)(1); }
    {char buffer2 [ 1024 ]; buffer2 [ ( 1024 )-1 ] = (char)(1); }
    {cgc_size_t count; count = (cgc_size_t)(1); }
    {int ret_code; ret_code = (int)(1); }
    {int sample_depth; sample_depth = (int)(1); }
    {int max_depth; max_depth = (int)(1); }
    {int sum_depth; sum_depth = (int)(1); }
    {int count_samples; count_samples = (int)(1); }
    {int * bins; bins = (int *)(1); }
    {int bin_number; bin_number = (int)(1); }
    {int i; i = (int)(1); }
    {cgc_size_t tlv27; tlv27 = (cgc_size_t)(1); }
    {cgc_size_t tlv29; tlv29 = (cgc_size_t)(1); }
    {cgc_size_t tlv32; tlv32 = (cgc_size_t)(1); }
    {cgc_size_t tlv31; tlv31 = (cgc_size_t)(1); }
    {char * tlv3; tlv3 = (char *)(1); }
    {char * tlv5; tlv5 = (char *)(1); }
    {cgc_size_t tlv34; tlv34 = (cgc_size_t)(1); }
    {cgc_size_t tlv33; tlv33 = (cgc_size_t)(1); }
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
    {char * tlv50; tlv50 = (char *)(1); }
    {cgc_size_t tlv49; tlv49 = (cgc_size_t)(1); }
    {char * tlv52; tlv52 = (char *)(1); }
    {cgc_size_t tlv51; tlv51 = (cgc_size_t)(1); }
    {char * tlv54; tlv54 = (char *)(1); }
    {cgc_size_t tlv53; tlv53 = (cgc_size_t)(1); }
    {cgc_size_t tlv72; tlv72 = (cgc_size_t)(1); }
    {cgc_size_t tlv71; tlv71 = (cgc_size_t)(1); }
    {cgc_size_t tlv74; tlv74 = (cgc_size_t)(1); }
    {cgc_size_t tlv73; tlv73 = (cgc_size_t)(1); }
    {unsigned int tlv57; tlv57 = (unsigned int)(1); }
    {cgc_size_t tlv75; tlv75 = (cgc_size_t)(1); }
    {cgc_size_t tlv77; tlv77 = (cgc_size_t)(1); }
    {cgc_size_t tlv80; tlv80 = (cgc_size_t)(1); }
    {cgc_size_t tlv79; tlv79 = (cgc_size_t)(1); }
    {unsigned int tlv58; tlv58 = (unsigned int)(1); }
    {char * tlv61; tlv61 = (char *)(1); }
    {cgc_size_t tlv59; tlv59 = (cgc_size_t)(1); }
    {char * tlv64; tlv64 = (char *)(1); }
    {cgc_size_t tlv62; tlv62 = (cgc_size_t)(1); }
    {char * tlv67; tlv67 = (char *)(1); }
    {cgc_size_t tlv65; tlv65 = (cgc_size_t)(1); }
    {char * tlv70; tlv70 = (char *)(1); }
    {cgc_size_t tlv68; tlv68 = (cgc_size_t)(1); }
    {unsigned int tlv87; tlv87 = (unsigned int)(1); }
    {unsigned int tlv88; tlv88 = (unsigned int)(1); }
    {unsigned int tlv91; tlv91 = (unsigned int)(1); }
}
void fix_ingred_download_dive_0_8_1(){
    {char buffer [ 1024 ]; buffer [ ( 1024 )-1 ] = (char)(sizeof ( dive_log_type )); }
    {char buffer2 [ 1024 ]; buffer2 [ ( 1024 )-1 ] = (char)(sizeof ( dive_log_type )); }
    {cgc_size_t count; count = (cgc_size_t)(sizeof ( dive_log_type )); }
    {int ret_code; ret_code = (int)(sizeof ( dive_log_type )); }
    {int sample_depth; sample_depth = (int)(sizeof ( dive_log_type )); }
    {int max_depth; max_depth = (int)(sizeof ( dive_log_type )); }
    {int sum_depth; sum_depth = (int)(sizeof ( dive_log_type )); }
    {int count_samples; count_samples = (int)(sizeof ( dive_log_type )); }
    {int * bins; bins = (int *)(sizeof ( dive_log_type )); }
    {int bin_number; bin_number = (int)(sizeof ( dive_log_type )); }
    {int i; i = (int)(sizeof ( dive_log_type )); }
    {cgc_size_t tlv27; tlv27 = (cgc_size_t)(sizeof ( dive_log_type )); }
    {cgc_size_t tlv29; tlv29 = (cgc_size_t)(sizeof ( dive_log_type )); }
    {cgc_size_t tlv32; tlv32 = (cgc_size_t)(sizeof ( dive_log_type )); }
    {cgc_size_t tlv31; tlv31 = (cgc_size_t)(sizeof ( dive_log_type )); }
    {char * tlv3; tlv3 = (char *)(sizeof ( dive_log_type )); }
    {char * tlv5; tlv5 = (char *)(sizeof ( dive_log_type )); }
    {cgc_size_t tlv34; tlv34 = (cgc_size_t)(sizeof ( dive_log_type )); }
    {cgc_size_t tlv33; tlv33 = (cgc_size_t)(sizeof ( dive_log_type )); }
    {char * tlv36; tlv36 = (char *)(sizeof ( dive_log_type )); }
    {cgc_size_t tlv35; tlv35 = (cgc_size_t)(sizeof ( dive_log_type )); }
    {char * tlv38; tlv38 = (char *)(sizeof ( dive_log_type )); }
    {cgc_size_t tlv37; tlv37 = (cgc_size_t)(sizeof ( dive_log_type )); }
    {char * tlv40; tlv40 = (char *)(sizeof ( dive_log_type )); }
    {cgc_size_t tlv39; tlv39 = (cgc_size_t)(sizeof ( dive_log_type )); }
    {char * tlv42; tlv42 = (char *)(sizeof ( dive_log_type )); }
    {cgc_size_t tlv41; tlv41 = (cgc_size_t)(sizeof ( dive_log_type )); }
    {char * tlv44; tlv44 = (char *)(sizeof ( dive_log_type )); }
    {cgc_size_t tlv43; tlv43 = (cgc_size_t)(sizeof ( dive_log_type )); }
    {char * tlv46; tlv46 = (char *)(sizeof ( dive_log_type )); }
    {cgc_size_t tlv45; tlv45 = (cgc_size_t)(sizeof ( dive_log_type )); }
    {char * tlv48; tlv48 = (char *)(sizeof ( dive_log_type )); }
    {cgc_size_t tlv47; tlv47 = (cgc_size_t)(sizeof ( dive_log_type )); }
    {char * tlv50; tlv50 = (char *)(sizeof ( dive_log_type )); }
    {cgc_size_t tlv49; tlv49 = (cgc_size_t)(sizeof ( dive_log_type )); }
    {char * tlv52; tlv52 = (char *)(sizeof ( dive_log_type )); }
    {cgc_size_t tlv51; tlv51 = (cgc_size_t)(sizeof ( dive_log_type )); }
    {char * tlv54; tlv54 = (char *)(sizeof ( dive_log_type )); }
    {cgc_size_t tlv53; tlv53 = (cgc_size_t)(sizeof ( dive_log_type )); }
    {cgc_size_t tlv72; tlv72 = (cgc_size_t)(sizeof ( dive_log_type )); }
    {cgc_size_t tlv71; tlv71 = (cgc_size_t)(sizeof ( dive_log_type )); }
    {cgc_size_t tlv74; tlv74 = (cgc_size_t)(sizeof ( dive_log_type )); }
    {cgc_size_t tlv73; tlv73 = (cgc_size_t)(sizeof ( dive_log_type )); }
    {unsigned int tlv57; tlv57 = (unsigned int)(sizeof ( dive_log_type )); }
    {cgc_size_t tlv75; tlv75 = (cgc_size_t)(sizeof ( dive_log_type )); }
    {cgc_size_t tlv77; tlv77 = (cgc_size_t)(sizeof ( dive_log_type )); }
    {cgc_size_t tlv80; tlv80 = (cgc_size_t)(sizeof ( dive_log_type )); }
    {cgc_size_t tlv79; tlv79 = (cgc_size_t)(sizeof ( dive_log_type )); }
    {unsigned int tlv58; tlv58 = (unsigned int)(sizeof ( dive_log_type )); }
    {char * tlv61; tlv61 = (char *)(sizeof ( dive_log_type )); }
    {cgc_size_t tlv59; tlv59 = (cgc_size_t)(sizeof ( dive_log_type )); }
    {char * tlv64; tlv64 = (char *)(sizeof ( dive_log_type )); }
    {cgc_size_t tlv62; tlv62 = (cgc_size_t)(sizeof ( dive_log_type )); }
    {char * tlv67; tlv67 = (char *)(sizeof ( dive_log_type )); }
    {cgc_size_t tlv65; tlv65 = (cgc_size_t)(sizeof ( dive_log_type )); }
    {char * tlv70; tlv70 = (char *)(sizeof ( dive_log_type )); }
    {cgc_size_t tlv68; tlv68 = (cgc_size_t)(sizeof ( dive_log_type )); }
    {unsigned int tlv87; tlv87 = (unsigned int)(sizeof ( dive_log_type )); }
    {unsigned int tlv88; tlv88 = (unsigned int)(sizeof ( dive_log_type )); }
    {unsigned int tlv91; tlv91 = (unsigned int)(sizeof ( dive_log_type )); }
}
void fix_ingred_download_dive_0_8(){
fix_ingred_download_dive_0_8_0();
fix_ingred_download_dive_0_8_1();
}
void fix_ingred_download_dive_0_10_0(){
    {char buffer [ 1024 ]; buffer [ ( 1024 )-1 ] = (char)(- 1); }
    {char buffer2 [ 1024 ]; buffer2 [ ( 1024 )-1 ] = (char)(- 1); }
    {cgc_size_t count; count = (cgc_size_t)(- 1); }
    {int ret_code; ret_code = (int)(- 1); }
    {int sample_depth; sample_depth = (int)(- 1); }
    {int max_depth; max_depth = (int)(- 1); }
    {int sum_depth; sum_depth = (int)(- 1); }
    {int count_samples; count_samples = (int)(- 1); }
    {int * bins; bins = (int *)(- 1); }
    {int bin_number; bin_number = (int)(- 1); }
    {int i; i = (int)(- 1); }
    {cgc_size_t tlv27; tlv27 = (cgc_size_t)(- 1); }
    {cgc_size_t tlv29; tlv29 = (cgc_size_t)(- 1); }
    {cgc_size_t tlv32; tlv32 = (cgc_size_t)(- 1); }
    {cgc_size_t tlv31; tlv31 = (cgc_size_t)(- 1); }
    {char * tlv3; tlv3 = (char *)(- 1); }
    {char * tlv5; tlv5 = (char *)(- 1); }
    {cgc_size_t tlv34; tlv34 = (cgc_size_t)(- 1); }
    {cgc_size_t tlv33; tlv33 = (cgc_size_t)(- 1); }
    {char * tlv36; tlv36 = (char *)(- 1); }
    {cgc_size_t tlv35; tlv35 = (cgc_size_t)(- 1); }
    {char * tlv38; tlv38 = (char *)(- 1); }
    {cgc_size_t tlv37; tlv37 = (cgc_size_t)(- 1); }
    {char * tlv40; tlv40 = (char *)(- 1); }
    {cgc_size_t tlv39; tlv39 = (cgc_size_t)(- 1); }
    {char * tlv42; tlv42 = (char *)(- 1); }
    {cgc_size_t tlv41; tlv41 = (cgc_size_t)(- 1); }
    {char * tlv44; tlv44 = (char *)(- 1); }
    {cgc_size_t tlv43; tlv43 = (cgc_size_t)(- 1); }
    {char * tlv46; tlv46 = (char *)(- 1); }
    {cgc_size_t tlv45; tlv45 = (cgc_size_t)(- 1); }
    {char * tlv48; tlv48 = (char *)(- 1); }
    {cgc_size_t tlv47; tlv47 = (cgc_size_t)(- 1); }
    {char * tlv50; tlv50 = (char *)(- 1); }
    {cgc_size_t tlv49; tlv49 = (cgc_size_t)(- 1); }
    {char * tlv52; tlv52 = (char *)(- 1); }
    {cgc_size_t tlv51; tlv51 = (cgc_size_t)(- 1); }
    {char * tlv54; tlv54 = (char *)(- 1); }
    {cgc_size_t tlv53; tlv53 = (cgc_size_t)(- 1); }
    {cgc_size_t tlv72; tlv72 = (cgc_size_t)(- 1); }
    {cgc_size_t tlv71; tlv71 = (cgc_size_t)(- 1); }
    {cgc_size_t tlv74; tlv74 = (cgc_size_t)(- 1); }
    {cgc_size_t tlv73; tlv73 = (cgc_size_t)(- 1); }
    {unsigned int tlv57; tlv57 = (unsigned int)(- 1); }
    {cgc_size_t tlv75; tlv75 = (cgc_size_t)(- 1); }
    {cgc_size_t tlv77; tlv77 = (cgc_size_t)(- 1); }
    {cgc_size_t tlv80; tlv80 = (cgc_size_t)(- 1); }
    {cgc_size_t tlv79; tlv79 = (cgc_size_t)(- 1); }
    {unsigned int tlv58; tlv58 = (unsigned int)(- 1); }
    {char * tlv61; tlv61 = (char *)(- 1); }
    {cgc_size_t tlv59; tlv59 = (cgc_size_t)(- 1); }
    {char * tlv64; tlv64 = (char *)(- 1); }
    {cgc_size_t tlv62; tlv62 = (cgc_size_t)(- 1); }
    {char * tlv67; tlv67 = (char *)(- 1); }
    {cgc_size_t tlv65; tlv65 = (cgc_size_t)(- 1); }
    {char * tlv70; tlv70 = (char *)(- 1); }
    {cgc_size_t tlv68; tlv68 = (cgc_size_t)(- 1); }
    {unsigned int tlv87; tlv87 = (unsigned int)(- 1); }
    {unsigned int tlv88; tlv88 = (unsigned int)(- 1); }
    {unsigned int tlv91; tlv91 = (unsigned int)(- 1); }
}
void fix_ingred_download_dive_0_10(){
fix_ingred_download_dive_0_10_0();
}
void fix_ingred_download_dive_0_16_1(){
    {char buffer [ 1024 ]; buffer [ ( 1024 )-1 ] = (char)(sizeof ( struct dive_data )); }
    {char buffer2 [ 1024 ]; buffer2 [ ( 1024 )-1 ] = (char)(sizeof ( struct dive_data )); }
    {cgc_size_t count; count = (cgc_size_t)(sizeof ( struct dive_data )); }
    {int ret_code; ret_code = (int)(sizeof ( struct dive_data )); }
    {int sample_depth; sample_depth = (int)(sizeof ( struct dive_data )); }
    {int max_depth; max_depth = (int)(sizeof ( struct dive_data )); }
    {int sum_depth; sum_depth = (int)(sizeof ( struct dive_data )); }
    {int count_samples; count_samples = (int)(sizeof ( struct dive_data )); }
    {int * bins; bins = (int *)(sizeof ( struct dive_data )); }
    {int bin_number; bin_number = (int)(sizeof ( struct dive_data )); }
    {int i; i = (int)(sizeof ( struct dive_data )); }
    {cgc_size_t tlv27; tlv27 = (cgc_size_t)(sizeof ( struct dive_data )); }
    {cgc_size_t tlv29; tlv29 = (cgc_size_t)(sizeof ( struct dive_data )); }
    {cgc_size_t tlv32; tlv32 = (cgc_size_t)(sizeof ( struct dive_data )); }
    {cgc_size_t tlv31; tlv31 = (cgc_size_t)(sizeof ( struct dive_data )); }
    {char * tlv3; tlv3 = (char *)(sizeof ( struct dive_data )); }
    {char * tlv5; tlv5 = (char *)(sizeof ( struct dive_data )); }
    {cgc_size_t tlv34; tlv34 = (cgc_size_t)(sizeof ( struct dive_data )); }
    {cgc_size_t tlv33; tlv33 = (cgc_size_t)(sizeof ( struct dive_data )); }
    {char * tlv36; tlv36 = (char *)(sizeof ( struct dive_data )); }
    {cgc_size_t tlv35; tlv35 = (cgc_size_t)(sizeof ( struct dive_data )); }
    {char * tlv38; tlv38 = (char *)(sizeof ( struct dive_data )); }
    {cgc_size_t tlv37; tlv37 = (cgc_size_t)(sizeof ( struct dive_data )); }
    {char * tlv40; tlv40 = (char *)(sizeof ( struct dive_data )); }
    {cgc_size_t tlv39; tlv39 = (cgc_size_t)(sizeof ( struct dive_data )); }
    {char * tlv42; tlv42 = (char *)(sizeof ( struct dive_data )); }
    {cgc_size_t tlv41; tlv41 = (cgc_size_t)(sizeof ( struct dive_data )); }
    {char * tlv44; tlv44 = (char *)(sizeof ( struct dive_data )); }
    {cgc_size_t tlv43; tlv43 = (cgc_size_t)(sizeof ( struct dive_data )); }
    {char * tlv46; tlv46 = (char *)(sizeof ( struct dive_data )); }
    {cgc_size_t tlv45; tlv45 = (cgc_size_t)(sizeof ( struct dive_data )); }
    {char * tlv48; tlv48 = (char *)(sizeof ( struct dive_data )); }
    {cgc_size_t tlv47; tlv47 = (cgc_size_t)(sizeof ( struct dive_data )); }
    {char * tlv50; tlv50 = (char *)(sizeof ( struct dive_data )); }
    {cgc_size_t tlv49; tlv49 = (cgc_size_t)(sizeof ( struct dive_data )); }
    {char * tlv52; tlv52 = (char *)(sizeof ( struct dive_data )); }
    {cgc_size_t tlv51; tlv51 = (cgc_size_t)(sizeof ( struct dive_data )); }
    {char * tlv54; tlv54 = (char *)(sizeof ( struct dive_data )); }
    {cgc_size_t tlv53; tlv53 = (cgc_size_t)(sizeof ( struct dive_data )); }
    {cgc_size_t tlv72; tlv72 = (cgc_size_t)(sizeof ( struct dive_data )); }
    {cgc_size_t tlv71; tlv71 = (cgc_size_t)(sizeof ( struct dive_data )); }
    {cgc_size_t tlv74; tlv74 = (cgc_size_t)(sizeof ( struct dive_data )); }
    {cgc_size_t tlv73; tlv73 = (cgc_size_t)(sizeof ( struct dive_data )); }
    {unsigned int tlv57; tlv57 = (unsigned int)(sizeof ( struct dive_data )); }
    {cgc_size_t tlv75; tlv75 = (cgc_size_t)(sizeof ( struct dive_data )); }
    {cgc_size_t tlv77; tlv77 = (cgc_size_t)(sizeof ( struct dive_data )); }
    {cgc_size_t tlv80; tlv80 = (cgc_size_t)(sizeof ( struct dive_data )); }
    {cgc_size_t tlv79; tlv79 = (cgc_size_t)(sizeof ( struct dive_data )); }
    {unsigned int tlv58; tlv58 = (unsigned int)(sizeof ( struct dive_data )); }
    {char * tlv61; tlv61 = (char *)(sizeof ( struct dive_data )); }
    {cgc_size_t tlv59; tlv59 = (cgc_size_t)(sizeof ( struct dive_data )); }
    {char * tlv64; tlv64 = (char *)(sizeof ( struct dive_data )); }
    {cgc_size_t tlv62; tlv62 = (cgc_size_t)(sizeof ( struct dive_data )); }
    {char * tlv67; tlv67 = (char *)(sizeof ( struct dive_data )); }
    {cgc_size_t tlv65; tlv65 = (cgc_size_t)(sizeof ( struct dive_data )); }
    {char * tlv70; tlv70 = (char *)(sizeof ( struct dive_data )); }
    {cgc_size_t tlv68; tlv68 = (cgc_size_t)(sizeof ( struct dive_data )); }
    {unsigned int tlv87; tlv87 = (unsigned int)(sizeof ( struct dive_data )); }
    {unsigned int tlv88; tlv88 = (unsigned int)(sizeof ( struct dive_data )); }
    {unsigned int tlv91; tlv91 = (unsigned int)(sizeof ( struct dive_data )); }
}
void fix_ingred_download_dive_0_16(){
fix_ingred_download_dive_0_16_1();
}
void fix_ingred_download_dive_0_21_1(){
time_t sample_time;
    bzero(&sample_time,sizeof(time_t));
    {char buffer [ 1024 ]; buffer [ ( 1024 )-1 ] = (char)(sizeof ( sample_time )); }
    {char buffer2 [ 1024 ]; buffer2 [ ( 1024 )-1 ] = (char)(sizeof ( sample_time )); }
    {cgc_size_t count; count = (cgc_size_t)(sizeof ( sample_time )); }
    {int ret_code; ret_code = (int)(sizeof ( sample_time )); }
    {int sample_depth; sample_depth = (int)(sizeof ( sample_time )); }
    {int max_depth; max_depth = (int)(sizeof ( sample_time )); }
    {int sum_depth; sum_depth = (int)(sizeof ( sample_time )); }
    {int count_samples; count_samples = (int)(sizeof ( sample_time )); }
    {int * bins; bins = (int *)(sizeof ( sample_time )); }
    {int bin_number; bin_number = (int)(sizeof ( sample_time )); }
    {int i; i = (int)(sizeof ( sample_time )); }
    {cgc_size_t tlv27; tlv27 = (cgc_size_t)(sizeof ( sample_time )); }
    {cgc_size_t tlv29; tlv29 = (cgc_size_t)(sizeof ( sample_time )); }
    {cgc_size_t tlv32; tlv32 = (cgc_size_t)(sizeof ( sample_time )); }
    {cgc_size_t tlv31; tlv31 = (cgc_size_t)(sizeof ( sample_time )); }
    {char * tlv3; tlv3 = (char *)(sizeof ( sample_time )); }
    {char * tlv5; tlv5 = (char *)(sizeof ( sample_time )); }
    {cgc_size_t tlv34; tlv34 = (cgc_size_t)(sizeof ( sample_time )); }
    {cgc_size_t tlv33; tlv33 = (cgc_size_t)(sizeof ( sample_time )); }
    {char * tlv36; tlv36 = (char *)(sizeof ( sample_time )); }
    {cgc_size_t tlv35; tlv35 = (cgc_size_t)(sizeof ( sample_time )); }
    {char * tlv38; tlv38 = (char *)(sizeof ( sample_time )); }
    {cgc_size_t tlv37; tlv37 = (cgc_size_t)(sizeof ( sample_time )); }
    {char * tlv40; tlv40 = (char *)(sizeof ( sample_time )); }
    {cgc_size_t tlv39; tlv39 = (cgc_size_t)(sizeof ( sample_time )); }
    {char * tlv42; tlv42 = (char *)(sizeof ( sample_time )); }
    {cgc_size_t tlv41; tlv41 = (cgc_size_t)(sizeof ( sample_time )); }
    {char * tlv44; tlv44 = (char *)(sizeof ( sample_time )); }
    {cgc_size_t tlv43; tlv43 = (cgc_size_t)(sizeof ( sample_time )); }
    {char * tlv46; tlv46 = (char *)(sizeof ( sample_time )); }
    {cgc_size_t tlv45; tlv45 = (cgc_size_t)(sizeof ( sample_time )); }
    {char * tlv48; tlv48 = (char *)(sizeof ( sample_time )); }
    {cgc_size_t tlv47; tlv47 = (cgc_size_t)(sizeof ( sample_time )); }
    {char * tlv50; tlv50 = (char *)(sizeof ( sample_time )); }
    {cgc_size_t tlv49; tlv49 = (cgc_size_t)(sizeof ( sample_time )); }
    {char * tlv52; tlv52 = (char *)(sizeof ( sample_time )); }
    {cgc_size_t tlv51; tlv51 = (cgc_size_t)(sizeof ( sample_time )); }
    {char * tlv54; tlv54 = (char *)(sizeof ( sample_time )); }
    {cgc_size_t tlv53; tlv53 = (cgc_size_t)(sizeof ( sample_time )); }
    {cgc_size_t tlv72; tlv72 = (cgc_size_t)(sizeof ( sample_time )); }
    {cgc_size_t tlv71; tlv71 = (cgc_size_t)(sizeof ( sample_time )); }
    {cgc_size_t tlv74; tlv74 = (cgc_size_t)(sizeof ( sample_time )); }
    {cgc_size_t tlv73; tlv73 = (cgc_size_t)(sizeof ( sample_time )); }
    {unsigned int tlv57; tlv57 = (unsigned int)(sizeof ( sample_time )); }
    {cgc_size_t tlv75; tlv75 = (cgc_size_t)(sizeof ( sample_time )); }
    {cgc_size_t tlv77; tlv77 = (cgc_size_t)(sizeof ( sample_time )); }
    {cgc_size_t tlv80; tlv80 = (cgc_size_t)(sizeof ( sample_time )); }
    {cgc_size_t tlv79; tlv79 = (cgc_size_t)(sizeof ( sample_time )); }
    {unsigned int tlv58; tlv58 = (unsigned int)(sizeof ( sample_time )); }
    {char * tlv61; tlv61 = (char *)(sizeof ( sample_time )); }
    {cgc_size_t tlv59; tlv59 = (cgc_size_t)(sizeof ( sample_time )); }
    {char * tlv64; tlv64 = (char *)(sizeof ( sample_time )); }
    {cgc_size_t tlv62; tlv62 = (cgc_size_t)(sizeof ( sample_time )); }
    {char * tlv67; tlv67 = (char *)(sizeof ( sample_time )); }
    {cgc_size_t tlv65; tlv65 = (cgc_size_t)(sizeof ( sample_time )); }
    {char * tlv70; tlv70 = (char *)(sizeof ( sample_time )); }
    {cgc_size_t tlv68; tlv68 = (cgc_size_t)(sizeof ( sample_time )); }
    {unsigned int tlv87; tlv87 = (unsigned int)(sizeof ( sample_time )); }
    {unsigned int tlv88; tlv88 = (unsigned int)(sizeof ( sample_time )); }
    {unsigned int tlv91; tlv91 = (unsigned int)(sizeof ( sample_time )); }
}
void fix_ingred_download_dive_0_21(){
fix_ingred_download_dive_0_21_1();
}
void fix_ingred_download_dive_0_28_1(){
    {char buffer [ 1024 ]; buffer [ ( 1024 )-1 ] = (char)(sizeof ( dive_data_type )); }
    {char buffer2 [ 1024 ]; buffer2 [ ( 1024 )-1 ] = (char)(sizeof ( dive_data_type )); }
    {cgc_size_t count; count = (cgc_size_t)(sizeof ( dive_data_type )); }
    {int ret_code; ret_code = (int)(sizeof ( dive_data_type )); }
    {int sample_depth; sample_depth = (int)(sizeof ( dive_data_type )); }
    {int max_depth; max_depth = (int)(sizeof ( dive_data_type )); }
    {int sum_depth; sum_depth = (int)(sizeof ( dive_data_type )); }
    {int count_samples; count_samples = (int)(sizeof ( dive_data_type )); }
    {int * bins; bins = (int *)(sizeof ( dive_data_type )); }
    {int bin_number; bin_number = (int)(sizeof ( dive_data_type )); }
    {int i; i = (int)(sizeof ( dive_data_type )); }
    {cgc_size_t tlv27; tlv27 = (cgc_size_t)(sizeof ( dive_data_type )); }
    {cgc_size_t tlv29; tlv29 = (cgc_size_t)(sizeof ( dive_data_type )); }
    {cgc_size_t tlv32; tlv32 = (cgc_size_t)(sizeof ( dive_data_type )); }
    {cgc_size_t tlv31; tlv31 = (cgc_size_t)(sizeof ( dive_data_type )); }
    {char * tlv3; tlv3 = (char *)(sizeof ( dive_data_type )); }
    {char * tlv5; tlv5 = (char *)(sizeof ( dive_data_type )); }
    {cgc_size_t tlv34; tlv34 = (cgc_size_t)(sizeof ( dive_data_type )); }
    {cgc_size_t tlv33; tlv33 = (cgc_size_t)(sizeof ( dive_data_type )); }
    {char * tlv36; tlv36 = (char *)(sizeof ( dive_data_type )); }
    {cgc_size_t tlv35; tlv35 = (cgc_size_t)(sizeof ( dive_data_type )); }
    {char * tlv38; tlv38 = (char *)(sizeof ( dive_data_type )); }
    {cgc_size_t tlv37; tlv37 = (cgc_size_t)(sizeof ( dive_data_type )); }
    {char * tlv40; tlv40 = (char *)(sizeof ( dive_data_type )); }
    {cgc_size_t tlv39; tlv39 = (cgc_size_t)(sizeof ( dive_data_type )); }
    {char * tlv42; tlv42 = (char *)(sizeof ( dive_data_type )); }
    {cgc_size_t tlv41; tlv41 = (cgc_size_t)(sizeof ( dive_data_type )); }
    {char * tlv44; tlv44 = (char *)(sizeof ( dive_data_type )); }
    {cgc_size_t tlv43; tlv43 = (cgc_size_t)(sizeof ( dive_data_type )); }
    {char * tlv46; tlv46 = (char *)(sizeof ( dive_data_type )); }
    {cgc_size_t tlv45; tlv45 = (cgc_size_t)(sizeof ( dive_data_type )); }
    {char * tlv48; tlv48 = (char *)(sizeof ( dive_data_type )); }
    {cgc_size_t tlv47; tlv47 = (cgc_size_t)(sizeof ( dive_data_type )); }
    {char * tlv50; tlv50 = (char *)(sizeof ( dive_data_type )); }
    {cgc_size_t tlv49; tlv49 = (cgc_size_t)(sizeof ( dive_data_type )); }
    {char * tlv52; tlv52 = (char *)(sizeof ( dive_data_type )); }
    {cgc_size_t tlv51; tlv51 = (cgc_size_t)(sizeof ( dive_data_type )); }
    {char * tlv54; tlv54 = (char *)(sizeof ( dive_data_type )); }
    {cgc_size_t tlv53; tlv53 = (cgc_size_t)(sizeof ( dive_data_type )); }
    {cgc_size_t tlv72; tlv72 = (cgc_size_t)(sizeof ( dive_data_type )); }
    {cgc_size_t tlv71; tlv71 = (cgc_size_t)(sizeof ( dive_data_type )); }
    {cgc_size_t tlv74; tlv74 = (cgc_size_t)(sizeof ( dive_data_type )); }
    {cgc_size_t tlv73; tlv73 = (cgc_size_t)(sizeof ( dive_data_type )); }
    {unsigned int tlv57; tlv57 = (unsigned int)(sizeof ( dive_data_type )); }
    {cgc_size_t tlv75; tlv75 = (cgc_size_t)(sizeof ( dive_data_type )); }
    {cgc_size_t tlv77; tlv77 = (cgc_size_t)(sizeof ( dive_data_type )); }
    {cgc_size_t tlv80; tlv80 = (cgc_size_t)(sizeof ( dive_data_type )); }
    {cgc_size_t tlv79; tlv79 = (cgc_size_t)(sizeof ( dive_data_type )); }
    {unsigned int tlv58; tlv58 = (unsigned int)(sizeof ( dive_data_type )); }
    {char * tlv61; tlv61 = (char *)(sizeof ( dive_data_type )); }
    {cgc_size_t tlv59; tlv59 = (cgc_size_t)(sizeof ( dive_data_type )); }
    {char * tlv64; tlv64 = (char *)(sizeof ( dive_data_type )); }
    {cgc_size_t tlv62; tlv62 = (cgc_size_t)(sizeof ( dive_data_type )); }
    {char * tlv67; tlv67 = (char *)(sizeof ( dive_data_type )); }
    {cgc_size_t tlv65; tlv65 = (cgc_size_t)(sizeof ( dive_data_type )); }
    {char * tlv70; tlv70 = (char *)(sizeof ( dive_data_type )); }
    {cgc_size_t tlv68; tlv68 = (cgc_size_t)(sizeof ( dive_data_type )); }
    {unsigned int tlv87; tlv87 = (unsigned int)(sizeof ( dive_data_type )); }
    {unsigned int tlv88; tlv88 = (unsigned int)(sizeof ( dive_data_type )); }
    {unsigned int tlv91; tlv91 = (unsigned int)(sizeof ( dive_data_type )); }
}
void fix_ingred_download_dive_0_28(){
fix_ingred_download_dive_0_28_1();
}
void fix_ingred_download_dive_0_31_1(){
dive_log_type next_dive_ref;
    bzero(&next_dive_ref,1*sizeof(dive_log_type));
dive_log_type * next_dive = &next_dive_ref;
    {char buffer [ 1024 ]; buffer [ ( 1024 )-1 ] = (char)(next_dive -> dive_date); }
    {char buffer2 [ 1024 ]; buffer2 [ ( 1024 )-1 ] = (char)(next_dive -> dive_date); }
    {cgc_size_t count; count = (cgc_size_t)(next_dive -> dive_date); }
    {int ret_code; ret_code = (int)(next_dive -> dive_date); }
    {int sample_depth; sample_depth = (int)(next_dive -> dive_date); }
    {int max_depth; max_depth = (int)(next_dive -> dive_date); }
    {int sum_depth; sum_depth = (int)(next_dive -> dive_date); }
    {int count_samples; count_samples = (int)(next_dive -> dive_date); }
    {int * bins; bins = (int *)(next_dive -> dive_date); }
    {int bin_number; bin_number = (int)(next_dive -> dive_date); }
    {int i; i = (int)(next_dive -> dive_date); }
    {cgc_size_t tlv27; tlv27 = (cgc_size_t)(next_dive -> dive_date); }
    {cgc_size_t tlv29; tlv29 = (cgc_size_t)(next_dive -> dive_date); }
    {cgc_size_t tlv32; tlv32 = (cgc_size_t)(next_dive -> dive_date); }
    {cgc_size_t tlv31; tlv31 = (cgc_size_t)(next_dive -> dive_date); }
    {char * tlv3; tlv3 = (char *)(next_dive -> dive_date); }
    {char * tlv5; tlv5 = (char *)(next_dive -> dive_date); }
    {cgc_size_t tlv34; tlv34 = (cgc_size_t)(next_dive -> dive_date); }
    {cgc_size_t tlv33; tlv33 = (cgc_size_t)(next_dive -> dive_date); }
    {char * tlv36; tlv36 = (char *)(next_dive -> dive_date); }
    {cgc_size_t tlv35; tlv35 = (cgc_size_t)(next_dive -> dive_date); }
    {char * tlv38; tlv38 = (char *)(next_dive -> dive_date); }
    {cgc_size_t tlv37; tlv37 = (cgc_size_t)(next_dive -> dive_date); }
    {char * tlv40; tlv40 = (char *)(next_dive -> dive_date); }
    {cgc_size_t tlv39; tlv39 = (cgc_size_t)(next_dive -> dive_date); }
    {char * tlv42; tlv42 = (char *)(next_dive -> dive_date); }
    {cgc_size_t tlv41; tlv41 = (cgc_size_t)(next_dive -> dive_date); }
    {char * tlv44; tlv44 = (char *)(next_dive -> dive_date); }
    {cgc_size_t tlv43; tlv43 = (cgc_size_t)(next_dive -> dive_date); }
    {char * tlv46; tlv46 = (char *)(next_dive -> dive_date); }
    {cgc_size_t tlv45; tlv45 = (cgc_size_t)(next_dive -> dive_date); }
    {char * tlv48; tlv48 = (char *)(next_dive -> dive_date); }
    {cgc_size_t tlv47; tlv47 = (cgc_size_t)(next_dive -> dive_date); }
    {char * tlv50; tlv50 = (char *)(next_dive -> dive_date); }
    {cgc_size_t tlv49; tlv49 = (cgc_size_t)(next_dive -> dive_date); }
    {char * tlv52; tlv52 = (char *)(next_dive -> dive_date); }
    {cgc_size_t tlv51; tlv51 = (cgc_size_t)(next_dive -> dive_date); }
    {char * tlv54; tlv54 = (char *)(next_dive -> dive_date); }
    {cgc_size_t tlv53; tlv53 = (cgc_size_t)(next_dive -> dive_date); }
    {cgc_size_t tlv72; tlv72 = (cgc_size_t)(next_dive -> dive_date); }
    {cgc_size_t tlv71; tlv71 = (cgc_size_t)(next_dive -> dive_date); }
    {cgc_size_t tlv74; tlv74 = (cgc_size_t)(next_dive -> dive_date); }
    {cgc_size_t tlv73; tlv73 = (cgc_size_t)(next_dive -> dive_date); }
    {unsigned int tlv57; tlv57 = (unsigned int)(next_dive -> dive_date); }
    {cgc_size_t tlv75; tlv75 = (cgc_size_t)(next_dive -> dive_date); }
    {cgc_size_t tlv77; tlv77 = (cgc_size_t)(next_dive -> dive_date); }
    {cgc_size_t tlv80; tlv80 = (cgc_size_t)(next_dive -> dive_date); }
    {cgc_size_t tlv79; tlv79 = (cgc_size_t)(next_dive -> dive_date); }
    {unsigned int tlv58; tlv58 = (unsigned int)(next_dive -> dive_date); }
    {char * tlv61; tlv61 = (char *)(next_dive -> dive_date); }
    {cgc_size_t tlv59; tlv59 = (cgc_size_t)(next_dive -> dive_date); }
    {char * tlv64; tlv64 = (char *)(next_dive -> dive_date); }
    {cgc_size_t tlv62; tlv62 = (cgc_size_t)(next_dive -> dive_date); }
    {char * tlv67; tlv67 = (char *)(next_dive -> dive_date); }
    {cgc_size_t tlv65; tlv65 = (cgc_size_t)(next_dive -> dive_date); }
    {char * tlv70; tlv70 = (char *)(next_dive -> dive_date); }
    {cgc_size_t tlv68; tlv68 = (cgc_size_t)(next_dive -> dive_date); }
    {unsigned int tlv87; tlv87 = (unsigned int)(next_dive -> dive_date); }
    {unsigned int tlv88; tlv88 = (unsigned int)(next_dive -> dive_date); }
    {unsigned int tlv91; tlv91 = (unsigned int)(next_dive -> dive_date); }
}
void fix_ingred_download_dive_0_31(){
fix_ingred_download_dive_0_31_1();
}
void fix_ingred_download_dive_0_32_1(){
dive_log_type next_dive_ref;
    bzero(&next_dive_ref,1*sizeof(dive_log_type));
dive_log_type * next_dive = &next_dive_ref;
    {char buffer [ 1024 ]; buffer [ ( 1024 )-1 ] = (char)(next_dive -> dive_time); }
    {char buffer2 [ 1024 ]; buffer2 [ ( 1024 )-1 ] = (char)(next_dive -> dive_time); }
    {cgc_size_t count; count = (cgc_size_t)(next_dive -> dive_time); }
    {int ret_code; ret_code = (int)(next_dive -> dive_time); }
    {int sample_depth; sample_depth = (int)(next_dive -> dive_time); }
    {int max_depth; max_depth = (int)(next_dive -> dive_time); }
    {int sum_depth; sum_depth = (int)(next_dive -> dive_time); }
    {int count_samples; count_samples = (int)(next_dive -> dive_time); }
    {int * bins; bins = (int *)(next_dive -> dive_time); }
    {int bin_number; bin_number = (int)(next_dive -> dive_time); }
    {int i; i = (int)(next_dive -> dive_time); }
    {cgc_size_t tlv27; tlv27 = (cgc_size_t)(next_dive -> dive_time); }
    {cgc_size_t tlv29; tlv29 = (cgc_size_t)(next_dive -> dive_time); }
    {cgc_size_t tlv32; tlv32 = (cgc_size_t)(next_dive -> dive_time); }
    {cgc_size_t tlv31; tlv31 = (cgc_size_t)(next_dive -> dive_time); }
    {char * tlv3; tlv3 = (char *)(next_dive -> dive_time); }
    {char * tlv5; tlv5 = (char *)(next_dive -> dive_time); }
    {cgc_size_t tlv34; tlv34 = (cgc_size_t)(next_dive -> dive_time); }
    {cgc_size_t tlv33; tlv33 = (cgc_size_t)(next_dive -> dive_time); }
    {char * tlv36; tlv36 = (char *)(next_dive -> dive_time); }
    {cgc_size_t tlv35; tlv35 = (cgc_size_t)(next_dive -> dive_time); }
    {char * tlv38; tlv38 = (char *)(next_dive -> dive_time); }
    {cgc_size_t tlv37; tlv37 = (cgc_size_t)(next_dive -> dive_time); }
    {char * tlv40; tlv40 = (char *)(next_dive -> dive_time); }
    {cgc_size_t tlv39; tlv39 = (cgc_size_t)(next_dive -> dive_time); }
    {char * tlv42; tlv42 = (char *)(next_dive -> dive_time); }
    {cgc_size_t tlv41; tlv41 = (cgc_size_t)(next_dive -> dive_time); }
    {char * tlv44; tlv44 = (char *)(next_dive -> dive_time); }
    {cgc_size_t tlv43; tlv43 = (cgc_size_t)(next_dive -> dive_time); }
    {char * tlv46; tlv46 = (char *)(next_dive -> dive_time); }
    {cgc_size_t tlv45; tlv45 = (cgc_size_t)(next_dive -> dive_time); }
    {char * tlv48; tlv48 = (char *)(next_dive -> dive_time); }
    {cgc_size_t tlv47; tlv47 = (cgc_size_t)(next_dive -> dive_time); }
    {char * tlv50; tlv50 = (char *)(next_dive -> dive_time); }
    {cgc_size_t tlv49; tlv49 = (cgc_size_t)(next_dive -> dive_time); }
    {char * tlv52; tlv52 = (char *)(next_dive -> dive_time); }
    {cgc_size_t tlv51; tlv51 = (cgc_size_t)(next_dive -> dive_time); }
    {char * tlv54; tlv54 = (char *)(next_dive -> dive_time); }
    {cgc_size_t tlv53; tlv53 = (cgc_size_t)(next_dive -> dive_time); }
    {cgc_size_t tlv72; tlv72 = (cgc_size_t)(next_dive -> dive_time); }
    {cgc_size_t tlv71; tlv71 = (cgc_size_t)(next_dive -> dive_time); }
    {cgc_size_t tlv74; tlv74 = (cgc_size_t)(next_dive -> dive_time); }
    {cgc_size_t tlv73; tlv73 = (cgc_size_t)(next_dive -> dive_time); }
    {unsigned int tlv57; tlv57 = (unsigned int)(next_dive -> dive_time); }
    {cgc_size_t tlv75; tlv75 = (cgc_size_t)(next_dive -> dive_time); }
    {cgc_size_t tlv77; tlv77 = (cgc_size_t)(next_dive -> dive_time); }
    {cgc_size_t tlv80; tlv80 = (cgc_size_t)(next_dive -> dive_time); }
    {cgc_size_t tlv79; tlv79 = (cgc_size_t)(next_dive -> dive_time); }
    {unsigned int tlv58; tlv58 = (unsigned int)(next_dive -> dive_time); }
    {char * tlv61; tlv61 = (char *)(next_dive -> dive_time); }
    {cgc_size_t tlv59; tlv59 = (cgc_size_t)(next_dive -> dive_time); }
    {char * tlv64; tlv64 = (char *)(next_dive -> dive_time); }
    {cgc_size_t tlv62; tlv62 = (cgc_size_t)(next_dive -> dive_time); }
    {char * tlv67; tlv67 = (char *)(next_dive -> dive_time); }
    {cgc_size_t tlv65; tlv65 = (cgc_size_t)(next_dive -> dive_time); }
    {char * tlv70; tlv70 = (char *)(next_dive -> dive_time); }
    {cgc_size_t tlv68; tlv68 = (cgc_size_t)(next_dive -> dive_time); }
    {unsigned int tlv87; tlv87 = (unsigned int)(next_dive -> dive_time); }
    {unsigned int tlv88; tlv88 = (unsigned int)(next_dive -> dive_time); }
    {unsigned int tlv91; tlv91 = (unsigned int)(next_dive -> dive_time); }
}
void fix_ingred_download_dive_0_32(){
fix_ingred_download_dive_0_32_1();
}
void fix_ingred_download_dive_0_33_0(){
dive_log_type next_dive_ref;
    bzero(&next_dive_ref,1*sizeof(dive_log_type));
dive_log_type * next_dive = &next_dive_ref;
    {char buffer [ 1024 ]; buffer [ ( 1024 )-1 ] = (char)(next_dive -> dive_length + 1); }
    {char buffer2 [ 1024 ]; buffer2 [ ( 1024 )-1 ] = (char)(next_dive -> dive_length + 1); }
    {cgc_size_t count; count = (cgc_size_t)(next_dive -> dive_length + 1); }
    {int ret_code; ret_code = (int)(next_dive -> dive_length + 1); }
    {int sample_depth; sample_depth = (int)(next_dive -> dive_length + 1); }
    {int max_depth; max_depth = (int)(next_dive -> dive_length + 1); }
    {int sum_depth; sum_depth = (int)(next_dive -> dive_length + 1); }
    {int count_samples; count_samples = (int)(next_dive -> dive_length + 1); }
    {int * bins; bins = (int *)(next_dive -> dive_length + 1); }
    {int bin_number; bin_number = (int)(next_dive -> dive_length + 1); }
    {int i; i = (int)(next_dive -> dive_length + 1); }
    {cgc_size_t tlv27; tlv27 = (cgc_size_t)(next_dive -> dive_length + 1); }
    {cgc_size_t tlv29; tlv29 = (cgc_size_t)(next_dive -> dive_length + 1); }
    {cgc_size_t tlv32; tlv32 = (cgc_size_t)(next_dive -> dive_length + 1); }
    {cgc_size_t tlv31; tlv31 = (cgc_size_t)(next_dive -> dive_length + 1); }
    {char * tlv3; tlv3 = (char *)(next_dive -> dive_length + 1); }
    {char * tlv5; tlv5 = (char *)(next_dive -> dive_length + 1); }
    {cgc_size_t tlv34; tlv34 = (cgc_size_t)(next_dive -> dive_length + 1); }
    {cgc_size_t tlv33; tlv33 = (cgc_size_t)(next_dive -> dive_length + 1); }
    {char * tlv36; tlv36 = (char *)(next_dive -> dive_length + 1); }
    {cgc_size_t tlv35; tlv35 = (cgc_size_t)(next_dive -> dive_length + 1); }
    {char * tlv38; tlv38 = (char *)(next_dive -> dive_length + 1); }
    {cgc_size_t tlv37; tlv37 = (cgc_size_t)(next_dive -> dive_length + 1); }
    {char * tlv40; tlv40 = (char *)(next_dive -> dive_length + 1); }
    {cgc_size_t tlv39; tlv39 = (cgc_size_t)(next_dive -> dive_length + 1); }
    {char * tlv42; tlv42 = (char *)(next_dive -> dive_length + 1); }
    {cgc_size_t tlv41; tlv41 = (cgc_size_t)(next_dive -> dive_length + 1); }
    {char * tlv44; tlv44 = (char *)(next_dive -> dive_length + 1); }
    {cgc_size_t tlv43; tlv43 = (cgc_size_t)(next_dive -> dive_length + 1); }
    {char * tlv46; tlv46 = (char *)(next_dive -> dive_length + 1); }
    {cgc_size_t tlv45; tlv45 = (cgc_size_t)(next_dive -> dive_length + 1); }
    {char * tlv48; tlv48 = (char *)(next_dive -> dive_length + 1); }
    {cgc_size_t tlv47; tlv47 = (cgc_size_t)(next_dive -> dive_length + 1); }
    {char * tlv50; tlv50 = (char *)(next_dive -> dive_length + 1); }
    {cgc_size_t tlv49; tlv49 = (cgc_size_t)(next_dive -> dive_length + 1); }
    {char * tlv52; tlv52 = (char *)(next_dive -> dive_length + 1); }
    {cgc_size_t tlv51; tlv51 = (cgc_size_t)(next_dive -> dive_length + 1); }
    {char * tlv54; tlv54 = (char *)(next_dive -> dive_length + 1); }
    {cgc_size_t tlv53; tlv53 = (cgc_size_t)(next_dive -> dive_length + 1); }
    {cgc_size_t tlv72; tlv72 = (cgc_size_t)(next_dive -> dive_length + 1); }
    {cgc_size_t tlv71; tlv71 = (cgc_size_t)(next_dive -> dive_length + 1); }
    {cgc_size_t tlv74; tlv74 = (cgc_size_t)(next_dive -> dive_length + 1); }
    {cgc_size_t tlv73; tlv73 = (cgc_size_t)(next_dive -> dive_length + 1); }
    {unsigned int tlv57; tlv57 = (unsigned int)(next_dive -> dive_length + 1); }
    {cgc_size_t tlv75; tlv75 = (cgc_size_t)(next_dive -> dive_length + 1); }
    {cgc_size_t tlv77; tlv77 = (cgc_size_t)(next_dive -> dive_length + 1); }
    {cgc_size_t tlv80; tlv80 = (cgc_size_t)(next_dive -> dive_length + 1); }
    {cgc_size_t tlv79; tlv79 = (cgc_size_t)(next_dive -> dive_length + 1); }
    {unsigned int tlv58; tlv58 = (unsigned int)(next_dive -> dive_length + 1); }
    {char * tlv61; tlv61 = (char *)(next_dive -> dive_length + 1); }
    {cgc_size_t tlv59; tlv59 = (cgc_size_t)(next_dive -> dive_length + 1); }
    {char * tlv64; tlv64 = (char *)(next_dive -> dive_length + 1); }
    {cgc_size_t tlv62; tlv62 = (cgc_size_t)(next_dive -> dive_length + 1); }
    {char * tlv67; tlv67 = (char *)(next_dive -> dive_length + 1); }
    {cgc_size_t tlv65; tlv65 = (cgc_size_t)(next_dive -> dive_length + 1); }
    {char * tlv70; tlv70 = (char *)(next_dive -> dive_length + 1); }
    {cgc_size_t tlv68; tlv68 = (cgc_size_t)(next_dive -> dive_length + 1); }
    {unsigned int tlv87; tlv87 = (unsigned int)(next_dive -> dive_length + 1); }
    {unsigned int tlv88; tlv88 = (unsigned int)(next_dive -> dive_length + 1); }
    {unsigned int tlv91; tlv91 = (unsigned int)(next_dive -> dive_length + 1); }
}
void fix_ingred_download_dive_0_33_1(){
dive_log_type next_dive_ref;
    bzero(&next_dive_ref,1*sizeof(dive_log_type));
dive_log_type * next_dive = &next_dive_ref;
    {char buffer [ 1024 ]; buffer [ ( 1024 )-1 ] = (char)(sizeof ( int )); }
    {char buffer2 [ 1024 ]; buffer2 [ ( 1024 )-1 ] = (char)(sizeof ( int )); }
    {cgc_size_t count; count = (cgc_size_t)(sizeof ( int )); }
    {int ret_code; ret_code = (int)(sizeof ( int )); }
    {int sample_depth; sample_depth = (int)(sizeof ( int )); }
    {int max_depth; max_depth = (int)(sizeof ( int )); }
    {int sum_depth; sum_depth = (int)(sizeof ( int )); }
    {int count_samples; count_samples = (int)(sizeof ( int )); }
    {int * bins; bins = (int *)(sizeof ( int )); }
    {int bin_number; bin_number = (int)(sizeof ( int )); }
    {int i; i = (int)(sizeof ( int )); }
    {cgc_size_t tlv27; tlv27 = (cgc_size_t)(sizeof ( int )); }
    {cgc_size_t tlv29; tlv29 = (cgc_size_t)(sizeof ( int )); }
    {cgc_size_t tlv32; tlv32 = (cgc_size_t)(sizeof ( int )); }
    {cgc_size_t tlv31; tlv31 = (cgc_size_t)(sizeof ( int )); }
    {char * tlv3; tlv3 = (char *)(sizeof ( int )); }
    {char * tlv5; tlv5 = (char *)(sizeof ( int )); }
    {cgc_size_t tlv34; tlv34 = (cgc_size_t)(sizeof ( int )); }
    {cgc_size_t tlv33; tlv33 = (cgc_size_t)(sizeof ( int )); }
    {char * tlv36; tlv36 = (char *)(sizeof ( int )); }
    {cgc_size_t tlv35; tlv35 = (cgc_size_t)(sizeof ( int )); }
    {char * tlv38; tlv38 = (char *)(sizeof ( int )); }
    {cgc_size_t tlv37; tlv37 = (cgc_size_t)(sizeof ( int )); }
    {char * tlv40; tlv40 = (char *)(sizeof ( int )); }
    {cgc_size_t tlv39; tlv39 = (cgc_size_t)(sizeof ( int )); }
    {char * tlv42; tlv42 = (char *)(sizeof ( int )); }
    {cgc_size_t tlv41; tlv41 = (cgc_size_t)(sizeof ( int )); }
    {char * tlv44; tlv44 = (char *)(sizeof ( int )); }
    {cgc_size_t tlv43; tlv43 = (cgc_size_t)(sizeof ( int )); }
    {char * tlv46; tlv46 = (char *)(sizeof ( int )); }
    {cgc_size_t tlv45; tlv45 = (cgc_size_t)(sizeof ( int )); }
    {char * tlv48; tlv48 = (char *)(sizeof ( int )); }
    {cgc_size_t tlv47; tlv47 = (cgc_size_t)(sizeof ( int )); }
    {char * tlv50; tlv50 = (char *)(sizeof ( int )); }
    {cgc_size_t tlv49; tlv49 = (cgc_size_t)(sizeof ( int )); }
    {char * tlv52; tlv52 = (char *)(sizeof ( int )); }
    {cgc_size_t tlv51; tlv51 = (cgc_size_t)(sizeof ( int )); }
    {char * tlv54; tlv54 = (char *)(sizeof ( int )); }
    {cgc_size_t tlv53; tlv53 = (cgc_size_t)(sizeof ( int )); }
    {cgc_size_t tlv72; tlv72 = (cgc_size_t)(sizeof ( int )); }
    {cgc_size_t tlv71; tlv71 = (cgc_size_t)(sizeof ( int )); }
    {cgc_size_t tlv74; tlv74 = (cgc_size_t)(sizeof ( int )); }
    {cgc_size_t tlv73; tlv73 = (cgc_size_t)(sizeof ( int )); }
    {unsigned int tlv57; tlv57 = (unsigned int)(sizeof ( int )); }
    {cgc_size_t tlv75; tlv75 = (cgc_size_t)(sizeof ( int )); }
    {cgc_size_t tlv77; tlv77 = (cgc_size_t)(sizeof ( int )); }
    {cgc_size_t tlv80; tlv80 = (cgc_size_t)(sizeof ( int )); }
    {cgc_size_t tlv79; tlv79 = (cgc_size_t)(sizeof ( int )); }
    {unsigned int tlv58; tlv58 = (unsigned int)(sizeof ( int )); }
    {char * tlv61; tlv61 = (char *)(sizeof ( int )); }
    {cgc_size_t tlv59; tlv59 = (cgc_size_t)(sizeof ( int )); }
    {char * tlv64; tlv64 = (char *)(sizeof ( int )); }
    {cgc_size_t tlv62; tlv62 = (cgc_size_t)(sizeof ( int )); }
    {char * tlv67; tlv67 = (char *)(sizeof ( int )); }
    {cgc_size_t tlv65; tlv65 = (cgc_size_t)(sizeof ( int )); }
    {char * tlv70; tlv70 = (char *)(sizeof ( int )); }
    {cgc_size_t tlv68; tlv68 = (cgc_size_t)(sizeof ( int )); }
    {unsigned int tlv87; tlv87 = (unsigned int)(sizeof ( int )); }
    {unsigned int tlv88; tlv88 = (unsigned int)(sizeof ( int )); }
    {unsigned int tlv91; tlv91 = (unsigned int)(sizeof ( int )); }
}
void fix_ingred_download_dive_0_33(){
fix_ingred_download_dive_0_33_0();
fix_ingred_download_dive_0_33_1();
}
void fix_ingred_download_dive_0_34_10(){
int bins_ref;
    bzero(&bins_ref,1*sizeof(int));
int * bins = &bins_ref;
    {char buffer [ 1024 ]; buffer [ ( 1024 )-1 ] = (char)(bins); }
    {char buffer2 [ 1024 ]; buffer2 [ ( 1024 )-1 ] = (char)(bins); }
    {cgc_size_t count; count = (cgc_size_t)(bins); }
    {int ret_code; ret_code = (int)(bins); }
    {int sample_depth; sample_depth = (int)(bins); }
    {int max_depth; max_depth = (int)(bins); }
    {int sum_depth; sum_depth = (int)(bins); }
    {int count_samples; count_samples = (int)(bins); }
    {int bin_number; bin_number = (int)(bins); }
    {int i; i = (int)(bins); }
    {cgc_size_t tlv27; tlv27 = (cgc_size_t)(bins); }
    {cgc_size_t tlv29; tlv29 = (cgc_size_t)(bins); }
    {cgc_size_t tlv32; tlv32 = (cgc_size_t)(bins); }
    {cgc_size_t tlv31; tlv31 = (cgc_size_t)(bins); }
    {char * tlv3; tlv3 = (char *)(bins); }
    {char * tlv5; tlv5 = (char *)(bins); }
    {cgc_size_t tlv34; tlv34 = (cgc_size_t)(bins); }
    {cgc_size_t tlv33; tlv33 = (cgc_size_t)(bins); }
    {char * tlv36; tlv36 = (char *)(bins); }
    {cgc_size_t tlv35; tlv35 = (cgc_size_t)(bins); }
    {char * tlv38; tlv38 = (char *)(bins); }
    {cgc_size_t tlv37; tlv37 = (cgc_size_t)(bins); }
    {char * tlv40; tlv40 = (char *)(bins); }
    {cgc_size_t tlv39; tlv39 = (cgc_size_t)(bins); }
    {char * tlv42; tlv42 = (char *)(bins); }
    {cgc_size_t tlv41; tlv41 = (cgc_size_t)(bins); }
    {char * tlv44; tlv44 = (char *)(bins); }
    {cgc_size_t tlv43; tlv43 = (cgc_size_t)(bins); }
    {char * tlv46; tlv46 = (char *)(bins); }
    {cgc_size_t tlv45; tlv45 = (cgc_size_t)(bins); }
    {char * tlv48; tlv48 = (char *)(bins); }
    {cgc_size_t tlv47; tlv47 = (cgc_size_t)(bins); }
    {char * tlv50; tlv50 = (char *)(bins); }
    {cgc_size_t tlv49; tlv49 = (cgc_size_t)(bins); }
    {char * tlv52; tlv52 = (char *)(bins); }
    {cgc_size_t tlv51; tlv51 = (cgc_size_t)(bins); }
    {char * tlv54; tlv54 = (char *)(bins); }
    {cgc_size_t tlv53; tlv53 = (cgc_size_t)(bins); }
    {cgc_size_t tlv72; tlv72 = (cgc_size_t)(bins); }
    {cgc_size_t tlv71; tlv71 = (cgc_size_t)(bins); }
    {cgc_size_t tlv74; tlv74 = (cgc_size_t)(bins); }
    {cgc_size_t tlv73; tlv73 = (cgc_size_t)(bins); }
    {unsigned int tlv57; tlv57 = (unsigned int)(bins); }
    {cgc_size_t tlv75; tlv75 = (cgc_size_t)(bins); }
    {cgc_size_t tlv77; tlv77 = (cgc_size_t)(bins); }
    {cgc_size_t tlv80; tlv80 = (cgc_size_t)(bins); }
    {cgc_size_t tlv79; tlv79 = (cgc_size_t)(bins); }
    {unsigned int tlv58; tlv58 = (unsigned int)(bins); }
    {char * tlv61; tlv61 = (char *)(bins); }
    {cgc_size_t tlv59; tlv59 = (cgc_size_t)(bins); }
    {char * tlv64; tlv64 = (char *)(bins); }
    {cgc_size_t tlv62; tlv62 = (cgc_size_t)(bins); }
    {char * tlv67; tlv67 = (char *)(bins); }
    {cgc_size_t tlv65; tlv65 = (cgc_size_t)(bins); }
    {char * tlv70; tlv70 = (char *)(bins); }
    {cgc_size_t tlv68; tlv68 = (cgc_size_t)(bins); }
    {unsigned int tlv87; tlv87 = (unsigned int)(bins); }
    {unsigned int tlv88; tlv88 = (unsigned int)(bins); }
    {unsigned int tlv91; tlv91 = (unsigned int)(bins); }
}
void fix_ingred_download_dive_0_34_11(){
int bins_ref;
    bzero(&bins_ref,1*sizeof(int));
int * bins = &bins_ref;
    {char buffer [ 1024 ]; buffer [ ( 1024 )-1 ] = (char)(0); }
    {char buffer2 [ 1024 ]; buffer2 [ ( 1024 )-1 ] = (char)(0); }
    {cgc_size_t count; count = (cgc_size_t)(0); }
    {int ret_code; ret_code = (int)(0); }
    {int sample_depth; sample_depth = (int)(0); }
    {int max_depth; max_depth = (int)(0); }
    {int sum_depth; sum_depth = (int)(0); }
    {int count_samples; count_samples = (int)(0); }
    {int * bins; bins = (int *)(0); }
    {int bin_number; bin_number = (int)(0); }
    {int i; i = (int)(0); }
    {cgc_size_t tlv27; tlv27 = (cgc_size_t)(0); }
    {cgc_size_t tlv29; tlv29 = (cgc_size_t)(0); }
    {cgc_size_t tlv32; tlv32 = (cgc_size_t)(0); }
    {cgc_size_t tlv31; tlv31 = (cgc_size_t)(0); }
    {char * tlv3; tlv3 = (char *)(0); }
    {char * tlv5; tlv5 = (char *)(0); }
    {cgc_size_t tlv34; tlv34 = (cgc_size_t)(0); }
    {cgc_size_t tlv33; tlv33 = (cgc_size_t)(0); }
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
    {char * tlv50; tlv50 = (char *)(0); }
    {cgc_size_t tlv49; tlv49 = (cgc_size_t)(0); }
    {char * tlv52; tlv52 = (char *)(0); }
    {cgc_size_t tlv51; tlv51 = (cgc_size_t)(0); }
    {char * tlv54; tlv54 = (char *)(0); }
    {cgc_size_t tlv53; tlv53 = (cgc_size_t)(0); }
    {cgc_size_t tlv72; tlv72 = (cgc_size_t)(0); }
    {cgc_size_t tlv71; tlv71 = (cgc_size_t)(0); }
    {cgc_size_t tlv74; tlv74 = (cgc_size_t)(0); }
    {cgc_size_t tlv73; tlv73 = (cgc_size_t)(0); }
    {unsigned int tlv57; tlv57 = (unsigned int)(0); }
    {cgc_size_t tlv75; tlv75 = (cgc_size_t)(0); }
    {cgc_size_t tlv77; tlv77 = (cgc_size_t)(0); }
    {cgc_size_t tlv80; tlv80 = (cgc_size_t)(0); }
    {cgc_size_t tlv79; tlv79 = (cgc_size_t)(0); }
    {unsigned int tlv58; tlv58 = (unsigned int)(0); }
    {char * tlv61; tlv61 = (char *)(0); }
    {cgc_size_t tlv59; tlv59 = (cgc_size_t)(0); }
    {char * tlv64; tlv64 = (char *)(0); }
    {cgc_size_t tlv62; tlv62 = (cgc_size_t)(0); }
    {char * tlv67; tlv67 = (char *)(0); }
    {cgc_size_t tlv65; tlv65 = (cgc_size_t)(0); }
    {char * tlv70; tlv70 = (char *)(0); }
    {cgc_size_t tlv68; tlv68 = (cgc_size_t)(0); }
    {unsigned int tlv87; tlv87 = (unsigned int)(0); }
    {unsigned int tlv88; tlv88 = (unsigned int)(0); }
    {unsigned int tlv91; tlv91 = (unsigned int)(0); }
}
void fix_ingred_download_dive_0_34(){
fix_ingred_download_dive_0_34_10();
fix_ingred_download_dive_0_34_11();
}
void fix_ingred_download_dive_0_36_0(){
struct dive_data temp_ptr_ref;
    bzero(&temp_ptr_ref,1*sizeof(struct dive_data));
struct dive_data * temp_ptr = &temp_ptr_ref;
time_t first_sample;
    bzero(&first_sample,sizeof(time_t));
    {char buffer [ 1024 ]; buffer [ ( 1024 )-1 ] = (char)(temp_ptr -> depth); }
    {char buffer2 [ 1024 ]; buffer2 [ ( 1024 )-1 ] = (char)(temp_ptr -> depth); }
    {cgc_size_t count; count = (cgc_size_t)(temp_ptr -> depth); }
    {int ret_code; ret_code = (int)(temp_ptr -> depth); }
    {int sample_depth; sample_depth = (int)(temp_ptr -> depth); }
    {int max_depth; max_depth = (int)(temp_ptr -> depth); }
    {int sum_depth; sum_depth = (int)(temp_ptr -> depth); }
    {int count_samples; count_samples = (int)(temp_ptr -> depth); }
    {int * bins; bins = (int *)(temp_ptr -> depth); }
    {int bin_number; bin_number = (int)(temp_ptr -> depth); }
    {int i; i = (int)(temp_ptr -> depth); }
    {cgc_size_t tlv27; tlv27 = (cgc_size_t)(temp_ptr -> depth); }
    {cgc_size_t tlv29; tlv29 = (cgc_size_t)(temp_ptr -> depth); }
    {cgc_size_t tlv32; tlv32 = (cgc_size_t)(temp_ptr -> depth); }
    {cgc_size_t tlv31; tlv31 = (cgc_size_t)(temp_ptr -> depth); }
    {char * tlv3; tlv3 = (char *)(temp_ptr -> depth); }
    {char * tlv5; tlv5 = (char *)(temp_ptr -> depth); }
    {cgc_size_t tlv34; tlv34 = (cgc_size_t)(temp_ptr -> depth); }
    {cgc_size_t tlv33; tlv33 = (cgc_size_t)(temp_ptr -> depth); }
    {char * tlv36; tlv36 = (char *)(temp_ptr -> depth); }
    {cgc_size_t tlv35; tlv35 = (cgc_size_t)(temp_ptr -> depth); }
    {char * tlv38; tlv38 = (char *)(temp_ptr -> depth); }
    {cgc_size_t tlv37; tlv37 = (cgc_size_t)(temp_ptr -> depth); }
    {char * tlv40; tlv40 = (char *)(temp_ptr -> depth); }
    {cgc_size_t tlv39; tlv39 = (cgc_size_t)(temp_ptr -> depth); }
    {char * tlv42; tlv42 = (char *)(temp_ptr -> depth); }
    {cgc_size_t tlv41; tlv41 = (cgc_size_t)(temp_ptr -> depth); }
    {char * tlv44; tlv44 = (char *)(temp_ptr -> depth); }
    {cgc_size_t tlv43; tlv43 = (cgc_size_t)(temp_ptr -> depth); }
    {char * tlv46; tlv46 = (char *)(temp_ptr -> depth); }
    {cgc_size_t tlv45; tlv45 = (cgc_size_t)(temp_ptr -> depth); }
    {char * tlv48; tlv48 = (char *)(temp_ptr -> depth); }
    {cgc_size_t tlv47; tlv47 = (cgc_size_t)(temp_ptr -> depth); }
    {char * tlv50; tlv50 = (char *)(temp_ptr -> depth); }
    {cgc_size_t tlv49; tlv49 = (cgc_size_t)(temp_ptr -> depth); }
    {char * tlv52; tlv52 = (char *)(temp_ptr -> depth); }
    {cgc_size_t tlv51; tlv51 = (cgc_size_t)(temp_ptr -> depth); }
    {char * tlv54; tlv54 = (char *)(temp_ptr -> depth); }
    {cgc_size_t tlv53; tlv53 = (cgc_size_t)(temp_ptr -> depth); }
    {cgc_size_t tlv72; tlv72 = (cgc_size_t)(temp_ptr -> depth); }
    {cgc_size_t tlv71; tlv71 = (cgc_size_t)(temp_ptr -> depth); }
    {cgc_size_t tlv74; tlv74 = (cgc_size_t)(temp_ptr -> depth); }
    {cgc_size_t tlv73; tlv73 = (cgc_size_t)(temp_ptr -> depth); }
    {unsigned int tlv57; tlv57 = (unsigned int)(temp_ptr -> depth); }
    {cgc_size_t tlv75; tlv75 = (cgc_size_t)(temp_ptr -> depth); }
    {cgc_size_t tlv77; tlv77 = (cgc_size_t)(temp_ptr -> depth); }
    {cgc_size_t tlv80; tlv80 = (cgc_size_t)(temp_ptr -> depth); }
    {cgc_size_t tlv79; tlv79 = (cgc_size_t)(temp_ptr -> depth); }
    {unsigned int tlv58; tlv58 = (unsigned int)(temp_ptr -> depth); }
    {char * tlv61; tlv61 = (char *)(temp_ptr -> depth); }
    {cgc_size_t tlv59; tlv59 = (cgc_size_t)(temp_ptr -> depth); }
    {char * tlv64; tlv64 = (char *)(temp_ptr -> depth); }
    {cgc_size_t tlv62; tlv62 = (cgc_size_t)(temp_ptr -> depth); }
    {char * tlv67; tlv67 = (char *)(temp_ptr -> depth); }
    {cgc_size_t tlv65; tlv65 = (cgc_size_t)(temp_ptr -> depth); }
    {char * tlv70; tlv70 = (char *)(temp_ptr -> depth); }
    {cgc_size_t tlv68; tlv68 = (cgc_size_t)(temp_ptr -> depth); }
    {unsigned int tlv87; tlv87 = (unsigned int)(temp_ptr -> depth); }
    {unsigned int tlv88; tlv88 = (unsigned int)(temp_ptr -> depth); }
    {unsigned int tlv91; tlv91 = (unsigned int)(temp_ptr -> depth); }
}
void fix_ingred_download_dive_0_36(){
fix_ingred_download_dive_0_36_0();
}
void fix_ingred_download_dive_0_38_17(){
int i;
    bzero(&i,sizeof(int));
dive_log_type next_dive_ref;
    bzero(&next_dive_ref,1*sizeof(dive_log_type));
dive_log_type * next_dive = &next_dive_ref;
    {char buffer [ 1024 ]; buffer [ ( 1024 )-1 ] = (char)(i); }
    {char buffer2 [ 1024 ]; buffer2 [ ( 1024 )-1 ] = (char)(i); }
    {cgc_size_t count; count = (cgc_size_t)(i); }
    {int ret_code; ret_code = (int)(i); }
    {int sample_depth; sample_depth = (int)(i); }
    {int max_depth; max_depth = (int)(i); }
    {int sum_depth; sum_depth = (int)(i); }
    {int count_samples; count_samples = (int)(i); }
    {int * bins; bins = (int *)(i); }
    {int bin_number; bin_number = (int)(i); }
    {cgc_size_t tlv27; tlv27 = (cgc_size_t)(i); }
    {cgc_size_t tlv29; tlv29 = (cgc_size_t)(i); }
    {cgc_size_t tlv32; tlv32 = (cgc_size_t)(i); }
    {cgc_size_t tlv31; tlv31 = (cgc_size_t)(i); }
    {char * tlv3; tlv3 = (char *)(i); }
    {char * tlv5; tlv5 = (char *)(i); }
    {cgc_size_t tlv34; tlv34 = (cgc_size_t)(i); }
    {cgc_size_t tlv33; tlv33 = (cgc_size_t)(i); }
    {char * tlv36; tlv36 = (char *)(i); }
    {cgc_size_t tlv35; tlv35 = (cgc_size_t)(i); }
    {char * tlv38; tlv38 = (char *)(i); }
    {cgc_size_t tlv37; tlv37 = (cgc_size_t)(i); }
    {char * tlv40; tlv40 = (char *)(i); }
    {cgc_size_t tlv39; tlv39 = (cgc_size_t)(i); }
    {char * tlv42; tlv42 = (char *)(i); }
    {cgc_size_t tlv41; tlv41 = (cgc_size_t)(i); }
    {char * tlv44; tlv44 = (char *)(i); }
    {cgc_size_t tlv43; tlv43 = (cgc_size_t)(i); }
    {char * tlv46; tlv46 = (char *)(i); }
    {cgc_size_t tlv45; tlv45 = (cgc_size_t)(i); }
    {char * tlv48; tlv48 = (char *)(i); }
    {cgc_size_t tlv47; tlv47 = (cgc_size_t)(i); }
    {char * tlv50; tlv50 = (char *)(i); }
    {cgc_size_t tlv49; tlv49 = (cgc_size_t)(i); }
    {char * tlv52; tlv52 = (char *)(i); }
    {cgc_size_t tlv51; tlv51 = (cgc_size_t)(i); }
    {char * tlv54; tlv54 = (char *)(i); }
    {cgc_size_t tlv53; tlv53 = (cgc_size_t)(i); }
    {cgc_size_t tlv72; tlv72 = (cgc_size_t)(i); }
    {cgc_size_t tlv71; tlv71 = (cgc_size_t)(i); }
    {cgc_size_t tlv74; tlv74 = (cgc_size_t)(i); }
    {cgc_size_t tlv73; tlv73 = (cgc_size_t)(i); }
    {unsigned int tlv57; tlv57 = (unsigned int)(i); }
    {cgc_size_t tlv75; tlv75 = (cgc_size_t)(i); }
    {cgc_size_t tlv77; tlv77 = (cgc_size_t)(i); }
    {cgc_size_t tlv80; tlv80 = (cgc_size_t)(i); }
    {cgc_size_t tlv79; tlv79 = (cgc_size_t)(i); }
    {unsigned int tlv58; tlv58 = (unsigned int)(i); }
    {char * tlv61; tlv61 = (char *)(i); }
    {cgc_size_t tlv59; tlv59 = (cgc_size_t)(i); }
    {char * tlv64; tlv64 = (char *)(i); }
    {cgc_size_t tlv62; tlv62 = (cgc_size_t)(i); }
    {char * tlv67; tlv67 = (char *)(i); }
    {cgc_size_t tlv65; tlv65 = (cgc_size_t)(i); }
    {char * tlv70; tlv70 = (char *)(i); }
    {cgc_size_t tlv68; tlv68 = (cgc_size_t)(i); }
    {unsigned int tlv87; tlv87 = (unsigned int)(i); }
    {unsigned int tlv88; tlv88 = (unsigned int)(i); }
    {unsigned int tlv91; tlv91 = (unsigned int)(i); }
}
void fix_ingred_download_dive_0_38_18(){
int i;
    bzero(&i,sizeof(int));
dive_log_type next_dive_ref;
    bzero(&next_dive_ref,1*sizeof(dive_log_type));
dive_log_type * next_dive = &next_dive_ref;
    {char buffer [ 1024 ]; buffer [ ( 1024 )-1 ] = (char)(next_dive -> dive_length + 1); }
    {char buffer2 [ 1024 ]; buffer2 [ ( 1024 )-1 ] = (char)(next_dive -> dive_length + 1); }
    {cgc_size_t count; count = (cgc_size_t)(next_dive -> dive_length + 1); }
    {int ret_code; ret_code = (int)(next_dive -> dive_length + 1); }
    {int sample_depth; sample_depth = (int)(next_dive -> dive_length + 1); }
    {int max_depth; max_depth = (int)(next_dive -> dive_length + 1); }
    {int sum_depth; sum_depth = (int)(next_dive -> dive_length + 1); }
    {int count_samples; count_samples = (int)(next_dive -> dive_length + 1); }
    {int * bins; bins = (int *)(next_dive -> dive_length + 1); }
    {int bin_number; bin_number = (int)(next_dive -> dive_length + 1); }
    {int i; i = (int)(next_dive -> dive_length + 1); }
    {cgc_size_t tlv27; tlv27 = (cgc_size_t)(next_dive -> dive_length + 1); }
    {cgc_size_t tlv29; tlv29 = (cgc_size_t)(next_dive -> dive_length + 1); }
    {cgc_size_t tlv32; tlv32 = (cgc_size_t)(next_dive -> dive_length + 1); }
    {cgc_size_t tlv31; tlv31 = (cgc_size_t)(next_dive -> dive_length + 1); }
    {char * tlv3; tlv3 = (char *)(next_dive -> dive_length + 1); }
    {char * tlv5; tlv5 = (char *)(next_dive -> dive_length + 1); }
    {cgc_size_t tlv34; tlv34 = (cgc_size_t)(next_dive -> dive_length + 1); }
    {cgc_size_t tlv33; tlv33 = (cgc_size_t)(next_dive -> dive_length + 1); }
    {char * tlv36; tlv36 = (char *)(next_dive -> dive_length + 1); }
    {cgc_size_t tlv35; tlv35 = (cgc_size_t)(next_dive -> dive_length + 1); }
    {char * tlv38; tlv38 = (char *)(next_dive -> dive_length + 1); }
    {cgc_size_t tlv37; tlv37 = (cgc_size_t)(next_dive -> dive_length + 1); }
    {char * tlv40; tlv40 = (char *)(next_dive -> dive_length + 1); }
    {cgc_size_t tlv39; tlv39 = (cgc_size_t)(next_dive -> dive_length + 1); }
    {char * tlv42; tlv42 = (char *)(next_dive -> dive_length + 1); }
    {cgc_size_t tlv41; tlv41 = (cgc_size_t)(next_dive -> dive_length + 1); }
    {char * tlv44; tlv44 = (char *)(next_dive -> dive_length + 1); }
    {cgc_size_t tlv43; tlv43 = (cgc_size_t)(next_dive -> dive_length + 1); }
    {char * tlv46; tlv46 = (char *)(next_dive -> dive_length + 1); }
    {cgc_size_t tlv45; tlv45 = (cgc_size_t)(next_dive -> dive_length + 1); }
    {char * tlv48; tlv48 = (char *)(next_dive -> dive_length + 1); }
    {cgc_size_t tlv47; tlv47 = (cgc_size_t)(next_dive -> dive_length + 1); }
    {char * tlv50; tlv50 = (char *)(next_dive -> dive_length + 1); }
    {cgc_size_t tlv49; tlv49 = (cgc_size_t)(next_dive -> dive_length + 1); }
    {char * tlv52; tlv52 = (char *)(next_dive -> dive_length + 1); }
    {cgc_size_t tlv51; tlv51 = (cgc_size_t)(next_dive -> dive_length + 1); }
    {char * tlv54; tlv54 = (char *)(next_dive -> dive_length + 1); }
    {cgc_size_t tlv53; tlv53 = (cgc_size_t)(next_dive -> dive_length + 1); }
    {cgc_size_t tlv72; tlv72 = (cgc_size_t)(next_dive -> dive_length + 1); }
    {cgc_size_t tlv71; tlv71 = (cgc_size_t)(next_dive -> dive_length + 1); }
    {cgc_size_t tlv74; tlv74 = (cgc_size_t)(next_dive -> dive_length + 1); }
    {cgc_size_t tlv73; tlv73 = (cgc_size_t)(next_dive -> dive_length + 1); }
    {unsigned int tlv57; tlv57 = (unsigned int)(next_dive -> dive_length + 1); }
    {cgc_size_t tlv75; tlv75 = (cgc_size_t)(next_dive -> dive_length + 1); }
    {cgc_size_t tlv77; tlv77 = (cgc_size_t)(next_dive -> dive_length + 1); }
    {cgc_size_t tlv80; tlv80 = (cgc_size_t)(next_dive -> dive_length + 1); }
    {cgc_size_t tlv79; tlv79 = (cgc_size_t)(next_dive -> dive_length + 1); }
    {unsigned int tlv58; tlv58 = (unsigned int)(next_dive -> dive_length + 1); }
    {char * tlv61; tlv61 = (char *)(next_dive -> dive_length + 1); }
    {cgc_size_t tlv59; tlv59 = (cgc_size_t)(next_dive -> dive_length + 1); }
    {char * tlv64; tlv64 = (char *)(next_dive -> dive_length + 1); }
    {cgc_size_t tlv62; tlv62 = (cgc_size_t)(next_dive -> dive_length + 1); }
    {char * tlv67; tlv67 = (char *)(next_dive -> dive_length + 1); }
    {cgc_size_t tlv65; tlv65 = (cgc_size_t)(next_dive -> dive_length + 1); }
    {char * tlv70; tlv70 = (char *)(next_dive -> dive_length + 1); }
    {cgc_size_t tlv68; tlv68 = (cgc_size_t)(next_dive -> dive_length + 1); }
    {unsigned int tlv87; tlv87 = (unsigned int)(next_dive -> dive_length + 1); }
    {unsigned int tlv88; tlv88 = (unsigned int)(next_dive -> dive_length + 1); }
    {unsigned int tlv91; tlv91 = (unsigned int)(next_dive -> dive_length + 1); }
}
void fix_ingred_download_dive_0_38(){
fix_ingred_download_dive_0_38_17();
fix_ingred_download_dive_0_38_18();
}
void fix_ingred_download_dive_0_39_17(){
int count_samples;
    bzero(&count_samples,sizeof(int));
    {char buffer [ 1024 ]; buffer [ ( 1024 )-1 ] = (char)(count_samples); }
    {char buffer2 [ 1024 ]; buffer2 [ ( 1024 )-1 ] = (char)(count_samples); }
    {cgc_size_t count; count = (cgc_size_t)(count_samples); }
    {int ret_code; ret_code = (int)(count_samples); }
    {int sample_depth; sample_depth = (int)(count_samples); }
    {int max_depth; max_depth = (int)(count_samples); }
    {int sum_depth; sum_depth = (int)(count_samples); }
    {int * bins; bins = (int *)(count_samples); }
    {int bin_number; bin_number = (int)(count_samples); }
    {int i; i = (int)(count_samples); }
    {cgc_size_t tlv27; tlv27 = (cgc_size_t)(count_samples); }
    {cgc_size_t tlv29; tlv29 = (cgc_size_t)(count_samples); }
    {cgc_size_t tlv32; tlv32 = (cgc_size_t)(count_samples); }
    {cgc_size_t tlv31; tlv31 = (cgc_size_t)(count_samples); }
    {char * tlv3; tlv3 = (char *)(count_samples); }
    {char * tlv5; tlv5 = (char *)(count_samples); }
    {cgc_size_t tlv34; tlv34 = (cgc_size_t)(count_samples); }
    {cgc_size_t tlv33; tlv33 = (cgc_size_t)(count_samples); }
    {char * tlv36; tlv36 = (char *)(count_samples); }
    {cgc_size_t tlv35; tlv35 = (cgc_size_t)(count_samples); }
    {char * tlv38; tlv38 = (char *)(count_samples); }
    {cgc_size_t tlv37; tlv37 = (cgc_size_t)(count_samples); }
    {char * tlv40; tlv40 = (char *)(count_samples); }
    {cgc_size_t tlv39; tlv39 = (cgc_size_t)(count_samples); }
    {char * tlv42; tlv42 = (char *)(count_samples); }
    {cgc_size_t tlv41; tlv41 = (cgc_size_t)(count_samples); }
    {char * tlv44; tlv44 = (char *)(count_samples); }
    {cgc_size_t tlv43; tlv43 = (cgc_size_t)(count_samples); }
    {char * tlv46; tlv46 = (char *)(count_samples); }
    {cgc_size_t tlv45; tlv45 = (cgc_size_t)(count_samples); }
    {char * tlv48; tlv48 = (char *)(count_samples); }
    {cgc_size_t tlv47; tlv47 = (cgc_size_t)(count_samples); }
    {char * tlv50; tlv50 = (char *)(count_samples); }
    {cgc_size_t tlv49; tlv49 = (cgc_size_t)(count_samples); }
    {char * tlv52; tlv52 = (char *)(count_samples); }
    {cgc_size_t tlv51; tlv51 = (cgc_size_t)(count_samples); }
    {char * tlv54; tlv54 = (char *)(count_samples); }
    {cgc_size_t tlv53; tlv53 = (cgc_size_t)(count_samples); }
    {cgc_size_t tlv72; tlv72 = (cgc_size_t)(count_samples); }
    {cgc_size_t tlv71; tlv71 = (cgc_size_t)(count_samples); }
    {cgc_size_t tlv74; tlv74 = (cgc_size_t)(count_samples); }
    {cgc_size_t tlv73; tlv73 = (cgc_size_t)(count_samples); }
    {unsigned int tlv57; tlv57 = (unsigned int)(count_samples); }
    {cgc_size_t tlv75; tlv75 = (cgc_size_t)(count_samples); }
    {cgc_size_t tlv77; tlv77 = (cgc_size_t)(count_samples); }
    {cgc_size_t tlv80; tlv80 = (cgc_size_t)(count_samples); }
    {cgc_size_t tlv79; tlv79 = (cgc_size_t)(count_samples); }
    {unsigned int tlv58; tlv58 = (unsigned int)(count_samples); }
    {char * tlv61; tlv61 = (char *)(count_samples); }
    {cgc_size_t tlv59; tlv59 = (cgc_size_t)(count_samples); }
    {char * tlv64; tlv64 = (char *)(count_samples); }
    {cgc_size_t tlv62; tlv62 = (cgc_size_t)(count_samples); }
    {char * tlv67; tlv67 = (char *)(count_samples); }
    {cgc_size_t tlv65; tlv65 = (cgc_size_t)(count_samples); }
    {char * tlv70; tlv70 = (char *)(count_samples); }
    {cgc_size_t tlv68; tlv68 = (cgc_size_t)(count_samples); }
    {unsigned int tlv87; tlv87 = (unsigned int)(count_samples); }
    {unsigned int tlv88; tlv88 = (unsigned int)(count_samples); }
    {unsigned int tlv91; tlv91 = (unsigned int)(count_samples); }
}
void fix_ingred_download_dive_0_39(){
fix_ingred_download_dive_0_39_17();
}
void fix_ingred_download_dive_0_44_0(){
char buffer [ 1024 ];
    bzero(&buffer,( 1024 *sizeof(char) ) );
dive_log_type next_dive_ref;
    bzero(&next_dive_ref,1*sizeof(dive_log_type));
dive_log_type * next_dive = &next_dive_ref;
    {char buffer [ 1024 ]; buffer [ ( 1024 )-1 ] = (char)(buffer); }
    {char buffer2 [ 1024 ]; buffer2 [ ( 1024 )-1 ] = (char)(buffer); }
    {cgc_size_t count; count = (cgc_size_t)(buffer); }
    {int ret_code; ret_code = (int)(buffer); }
    {int sample_depth; sample_depth = (int)(buffer); }
    {int max_depth; max_depth = (int)(buffer); }
    {int sum_depth; sum_depth = (int)(buffer); }
    {int count_samples; count_samples = (int)(buffer); }
    {int * bins; bins = (int *)(buffer); }
    {int bin_number; bin_number = (int)(buffer); }
    {int i; i = (int)(buffer); }
    {cgc_size_t tlv27; tlv27 = (cgc_size_t)(buffer); }
    {cgc_size_t tlv29; tlv29 = (cgc_size_t)(buffer); }
    {cgc_size_t tlv32; tlv32 = (cgc_size_t)(buffer); }
    {cgc_size_t tlv31; tlv31 = (cgc_size_t)(buffer); }
    {char * tlv3; tlv3 = (char *)(buffer); }
    {char * tlv5; tlv5 = (char *)(buffer); }
    {cgc_size_t tlv34; tlv34 = (cgc_size_t)(buffer); }
    {cgc_size_t tlv33; tlv33 = (cgc_size_t)(buffer); }
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
    {char * tlv50; tlv50 = (char *)(buffer); }
    {cgc_size_t tlv49; tlv49 = (cgc_size_t)(buffer); }
    {char * tlv52; tlv52 = (char *)(buffer); }
    {cgc_size_t tlv51; tlv51 = (cgc_size_t)(buffer); }
    {char * tlv54; tlv54 = (char *)(buffer); }
    {cgc_size_t tlv53; tlv53 = (cgc_size_t)(buffer); }
    {cgc_size_t tlv72; tlv72 = (cgc_size_t)(buffer); }
    {cgc_size_t tlv71; tlv71 = (cgc_size_t)(buffer); }
    {cgc_size_t tlv74; tlv74 = (cgc_size_t)(buffer); }
    {cgc_size_t tlv73; tlv73 = (cgc_size_t)(buffer); }
    {unsigned int tlv57; tlv57 = (unsigned int)(buffer); }
    {cgc_size_t tlv75; tlv75 = (cgc_size_t)(buffer); }
    {cgc_size_t tlv77; tlv77 = (cgc_size_t)(buffer); }
    {cgc_size_t tlv80; tlv80 = (cgc_size_t)(buffer); }
    {cgc_size_t tlv79; tlv79 = (cgc_size_t)(buffer); }
    {unsigned int tlv58; tlv58 = (unsigned int)(buffer); }
    {char * tlv61; tlv61 = (char *)(buffer); }
    {cgc_size_t tlv59; tlv59 = (cgc_size_t)(buffer); }
    {char * tlv64; tlv64 = (char *)(buffer); }
    {cgc_size_t tlv62; tlv62 = (cgc_size_t)(buffer); }
    {char * tlv67; tlv67 = (char *)(buffer); }
    {cgc_size_t tlv65; tlv65 = (cgc_size_t)(buffer); }
    {char * tlv70; tlv70 = (char *)(buffer); }
    {cgc_size_t tlv68; tlv68 = (cgc_size_t)(buffer); }
    {unsigned int tlv87; tlv87 = (unsigned int)(buffer); }
    {unsigned int tlv88; tlv88 = (unsigned int)(buffer); }
    {unsigned int tlv91; tlv91 = (unsigned int)(buffer); }
}
void fix_ingred_download_dive_0_44_1(){
char buffer [ 1024 ];
    bzero(&buffer,( 1024 *sizeof(char) ) );
dive_log_type next_dive_ref;
    bzero(&next_dive_ref,1*sizeof(dive_log_type));
dive_log_type * next_dive = &next_dive_ref;
    {char buffer [ 1024 ]; buffer [ ( 1024 )-1 ] = (char)(sizeof ( next_dive -> dive_site_name )); }
    {char buffer2 [ 1024 ]; buffer2 [ ( 1024 )-1 ] = (char)(sizeof ( next_dive -> dive_site_name )); }
    {cgc_size_t count; count = (cgc_size_t)(sizeof ( next_dive -> dive_site_name )); }
    {int ret_code; ret_code = (int)(sizeof ( next_dive -> dive_site_name )); }
    {int sample_depth; sample_depth = (int)(sizeof ( next_dive -> dive_site_name )); }
    {int max_depth; max_depth = (int)(sizeof ( next_dive -> dive_site_name )); }
    {int sum_depth; sum_depth = (int)(sizeof ( next_dive -> dive_site_name )); }
    {int count_samples; count_samples = (int)(sizeof ( next_dive -> dive_site_name )); }
    {int * bins; bins = (int *)(sizeof ( next_dive -> dive_site_name )); }
    {int bin_number; bin_number = (int)(sizeof ( next_dive -> dive_site_name )); }
    {int i; i = (int)(sizeof ( next_dive -> dive_site_name )); }
    {cgc_size_t tlv27; tlv27 = (cgc_size_t)(sizeof ( next_dive -> dive_site_name )); }
    {cgc_size_t tlv29; tlv29 = (cgc_size_t)(sizeof ( next_dive -> dive_site_name )); }
    {cgc_size_t tlv32; tlv32 = (cgc_size_t)(sizeof ( next_dive -> dive_site_name )); }
    {cgc_size_t tlv31; tlv31 = (cgc_size_t)(sizeof ( next_dive -> dive_site_name )); }
    {char * tlv3; tlv3 = (char *)(sizeof ( next_dive -> dive_site_name )); }
    {char * tlv5; tlv5 = (char *)(sizeof ( next_dive -> dive_site_name )); }
    {cgc_size_t tlv34; tlv34 = (cgc_size_t)(sizeof ( next_dive -> dive_site_name )); }
    {cgc_size_t tlv33; tlv33 = (cgc_size_t)(sizeof ( next_dive -> dive_site_name )); }
    {char * tlv36; tlv36 = (char *)(sizeof ( next_dive -> dive_site_name )); }
    {cgc_size_t tlv35; tlv35 = (cgc_size_t)(sizeof ( next_dive -> dive_site_name )); }
    {char * tlv38; tlv38 = (char *)(sizeof ( next_dive -> dive_site_name )); }
    {cgc_size_t tlv37; tlv37 = (cgc_size_t)(sizeof ( next_dive -> dive_site_name )); }
    {char * tlv40; tlv40 = (char *)(sizeof ( next_dive -> dive_site_name )); }
    {cgc_size_t tlv39; tlv39 = (cgc_size_t)(sizeof ( next_dive -> dive_site_name )); }
    {char * tlv42; tlv42 = (char *)(sizeof ( next_dive -> dive_site_name )); }
    {cgc_size_t tlv41; tlv41 = (cgc_size_t)(sizeof ( next_dive -> dive_site_name )); }
    {char * tlv44; tlv44 = (char *)(sizeof ( next_dive -> dive_site_name )); }
    {cgc_size_t tlv43; tlv43 = (cgc_size_t)(sizeof ( next_dive -> dive_site_name )); }
    {char * tlv46; tlv46 = (char *)(sizeof ( next_dive -> dive_site_name )); }
    {cgc_size_t tlv45; tlv45 = (cgc_size_t)(sizeof ( next_dive -> dive_site_name )); }
    {char * tlv48; tlv48 = (char *)(sizeof ( next_dive -> dive_site_name )); }
    {cgc_size_t tlv47; tlv47 = (cgc_size_t)(sizeof ( next_dive -> dive_site_name )); }
    {char * tlv50; tlv50 = (char *)(sizeof ( next_dive -> dive_site_name )); }
    {cgc_size_t tlv49; tlv49 = (cgc_size_t)(sizeof ( next_dive -> dive_site_name )); }
    {char * tlv52; tlv52 = (char *)(sizeof ( next_dive -> dive_site_name )); }
    {cgc_size_t tlv51; tlv51 = (cgc_size_t)(sizeof ( next_dive -> dive_site_name )); }
    {char * tlv54; tlv54 = (char *)(sizeof ( next_dive -> dive_site_name )); }
    {cgc_size_t tlv53; tlv53 = (cgc_size_t)(sizeof ( next_dive -> dive_site_name )); }
    {cgc_size_t tlv72; tlv72 = (cgc_size_t)(sizeof ( next_dive -> dive_site_name )); }
    {cgc_size_t tlv71; tlv71 = (cgc_size_t)(sizeof ( next_dive -> dive_site_name )); }
    {cgc_size_t tlv74; tlv74 = (cgc_size_t)(sizeof ( next_dive -> dive_site_name )); }
    {cgc_size_t tlv73; tlv73 = (cgc_size_t)(sizeof ( next_dive -> dive_site_name )); }
    {unsigned int tlv57; tlv57 = (unsigned int)(sizeof ( next_dive -> dive_site_name )); }
    {cgc_size_t tlv75; tlv75 = (cgc_size_t)(sizeof ( next_dive -> dive_site_name )); }
    {cgc_size_t tlv77; tlv77 = (cgc_size_t)(sizeof ( next_dive -> dive_site_name )); }
    {cgc_size_t tlv80; tlv80 = (cgc_size_t)(sizeof ( next_dive -> dive_site_name )); }
    {cgc_size_t tlv79; tlv79 = (cgc_size_t)(sizeof ( next_dive -> dive_site_name )); }
    {unsigned int tlv58; tlv58 = (unsigned int)(sizeof ( next_dive -> dive_site_name )); }
    {char * tlv61; tlv61 = (char *)(sizeof ( next_dive -> dive_site_name )); }
    {cgc_size_t tlv59; tlv59 = (cgc_size_t)(sizeof ( next_dive -> dive_site_name )); }
    {char * tlv64; tlv64 = (char *)(sizeof ( next_dive -> dive_site_name )); }
    {cgc_size_t tlv62; tlv62 = (cgc_size_t)(sizeof ( next_dive -> dive_site_name )); }
    {char * tlv67; tlv67 = (char *)(sizeof ( next_dive -> dive_site_name )); }
    {cgc_size_t tlv65; tlv65 = (cgc_size_t)(sizeof ( next_dive -> dive_site_name )); }
    {char * tlv70; tlv70 = (char *)(sizeof ( next_dive -> dive_site_name )); }
    {cgc_size_t tlv68; tlv68 = (cgc_size_t)(sizeof ( next_dive -> dive_site_name )); }
    {unsigned int tlv87; tlv87 = (unsigned int)(sizeof ( next_dive -> dive_site_name )); }
    {unsigned int tlv88; tlv88 = (unsigned int)(sizeof ( next_dive -> dive_site_name )); }
    {unsigned int tlv91; tlv91 = (unsigned int)(sizeof ( next_dive -> dive_site_name )); }
}
void fix_ingred_download_dive_0_44(){
fix_ingred_download_dive_0_44_0();
fix_ingred_download_dive_0_44_1();
}
void fix_ingred_download_dive_0_45_16(){
cgc_size_t count;
    bzero(&count,sizeof(cgc_size_t));
    {char buffer [ 1024 ]; buffer [ ( 1024 )-1 ] = (char)(count); }
    {char buffer2 [ 1024 ]; buffer2 [ ( 1024 )-1 ] = (char)(count); }
    {int ret_code; ret_code = (int)(count); }
    {int sample_depth; sample_depth = (int)(count); }
    {int max_depth; max_depth = (int)(count); }
    {int sum_depth; sum_depth = (int)(count); }
    {int count_samples; count_samples = (int)(count); }
    {int * bins; bins = (int *)(count); }
    {int bin_number; bin_number = (int)(count); }
    {int i; i = (int)(count); }
    {cgc_size_t tlv27; tlv27 = (cgc_size_t)(count); }
    {cgc_size_t tlv29; tlv29 = (cgc_size_t)(count); }
    {cgc_size_t tlv32; tlv32 = (cgc_size_t)(count); }
    {cgc_size_t tlv31; tlv31 = (cgc_size_t)(count); }
    {char * tlv3; tlv3 = (char *)(count); }
    {char * tlv5; tlv5 = (char *)(count); }
    {cgc_size_t tlv34; tlv34 = (cgc_size_t)(count); }
    {cgc_size_t tlv33; tlv33 = (cgc_size_t)(count); }
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
    {char * tlv50; tlv50 = (char *)(count); }
    {cgc_size_t tlv49; tlv49 = (cgc_size_t)(count); }
    {char * tlv52; tlv52 = (char *)(count); }
    {cgc_size_t tlv51; tlv51 = (cgc_size_t)(count); }
    {char * tlv54; tlv54 = (char *)(count); }
    {cgc_size_t tlv53; tlv53 = (cgc_size_t)(count); }
    {cgc_size_t tlv72; tlv72 = (cgc_size_t)(count); }
    {cgc_size_t tlv71; tlv71 = (cgc_size_t)(count); }
    {cgc_size_t tlv74; tlv74 = (cgc_size_t)(count); }
    {cgc_size_t tlv73; tlv73 = (cgc_size_t)(count); }
    {unsigned int tlv57; tlv57 = (unsigned int)(count); }
    {cgc_size_t tlv75; tlv75 = (cgc_size_t)(count); }
    {cgc_size_t tlv77; tlv77 = (cgc_size_t)(count); }
    {cgc_size_t tlv80; tlv80 = (cgc_size_t)(count); }
    {cgc_size_t tlv79; tlv79 = (cgc_size_t)(count); }
    {unsigned int tlv58; tlv58 = (unsigned int)(count); }
    {char * tlv61; tlv61 = (char *)(count); }
    {cgc_size_t tlv59; tlv59 = (cgc_size_t)(count); }
    {char * tlv64; tlv64 = (char *)(count); }
    {cgc_size_t tlv62; tlv62 = (cgc_size_t)(count); }
    {char * tlv67; tlv67 = (char *)(count); }
    {cgc_size_t tlv65; tlv65 = (cgc_size_t)(count); }
    {char * tlv70; tlv70 = (char *)(count); }
    {cgc_size_t tlv68; tlv68 = (cgc_size_t)(count); }
    {unsigned int tlv87; tlv87 = (unsigned int)(count); }
    {unsigned int tlv88; tlv88 = (unsigned int)(count); }
    {unsigned int tlv91; tlv91 = (unsigned int)(count); }
}
void fix_ingred_download_dive_0_45_17(){
cgc_size_t count;
    bzero(&count,sizeof(cgc_size_t));
    {char buffer [ 1024 ]; buffer [ ( 1024 )-1 ] = (char)(0); }
    {char buffer2 [ 1024 ]; buffer2 [ ( 1024 )-1 ] = (char)(0); }
    {cgc_size_t count; count = (cgc_size_t)(0); }
    {int ret_code; ret_code = (int)(0); }
    {int sample_depth; sample_depth = (int)(0); }
    {int max_depth; max_depth = (int)(0); }
    {int sum_depth; sum_depth = (int)(0); }
    {int count_samples; count_samples = (int)(0); }
    {int * bins; bins = (int *)(0); }
    {int bin_number; bin_number = (int)(0); }
    {int i; i = (int)(0); }
    {cgc_size_t tlv27; tlv27 = (cgc_size_t)(0); }
    {cgc_size_t tlv29; tlv29 = (cgc_size_t)(0); }
    {cgc_size_t tlv32; tlv32 = (cgc_size_t)(0); }
    {cgc_size_t tlv31; tlv31 = (cgc_size_t)(0); }
    {char * tlv3; tlv3 = (char *)(0); }
    {char * tlv5; tlv5 = (char *)(0); }
    {cgc_size_t tlv34; tlv34 = (cgc_size_t)(0); }
    {cgc_size_t tlv33; tlv33 = (cgc_size_t)(0); }
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
    {char * tlv50; tlv50 = (char *)(0); }
    {cgc_size_t tlv49; tlv49 = (cgc_size_t)(0); }
    {char * tlv52; tlv52 = (char *)(0); }
    {cgc_size_t tlv51; tlv51 = (cgc_size_t)(0); }
    {char * tlv54; tlv54 = (char *)(0); }
    {cgc_size_t tlv53; tlv53 = (cgc_size_t)(0); }
    {cgc_size_t tlv72; tlv72 = (cgc_size_t)(0); }
    {cgc_size_t tlv71; tlv71 = (cgc_size_t)(0); }
    {cgc_size_t tlv74; tlv74 = (cgc_size_t)(0); }
    {cgc_size_t tlv73; tlv73 = (cgc_size_t)(0); }
    {unsigned int tlv57; tlv57 = (unsigned int)(0); }
    {cgc_size_t tlv75; tlv75 = (cgc_size_t)(0); }
    {cgc_size_t tlv77; tlv77 = (cgc_size_t)(0); }
    {cgc_size_t tlv80; tlv80 = (cgc_size_t)(0); }
    {cgc_size_t tlv79; tlv79 = (cgc_size_t)(0); }
    {unsigned int tlv58; tlv58 = (unsigned int)(0); }
    {char * tlv61; tlv61 = (char *)(0); }
    {cgc_size_t tlv59; tlv59 = (cgc_size_t)(0); }
    {char * tlv64; tlv64 = (char *)(0); }
    {cgc_size_t tlv62; tlv62 = (cgc_size_t)(0); }
    {char * tlv67; tlv67 = (char *)(0); }
    {cgc_size_t tlv65; tlv65 = (cgc_size_t)(0); }
    {char * tlv70; tlv70 = (char *)(0); }
    {cgc_size_t tlv68; tlv68 = (cgc_size_t)(0); }
    {unsigned int tlv87; tlv87 = (unsigned int)(0); }
    {unsigned int tlv88; tlv88 = (unsigned int)(0); }
    {unsigned int tlv91; tlv91 = (unsigned int)(0); }
}
void fix_ingred_download_dive_0_45(){
fix_ingred_download_dive_0_45_16();
fix_ingred_download_dive_0_45_17();
}
void fix_ingred_download_dive_0_46_0(){
dive_log_type next_dive_ref;
    bzero(&next_dive_ref,1*sizeof(dive_log_type));
dive_log_type * next_dive = &next_dive_ref;
    {char buffer [ 1024 ]; buffer [ ( 1024 )-1 ] = (char)(next_dive -> dive_site_name); }
    {char buffer2 [ 1024 ]; buffer2 [ ( 1024 )-1 ] = (char)(next_dive -> dive_site_name); }
    {cgc_size_t count; count = (cgc_size_t)(next_dive -> dive_site_name); }
    {int ret_code; ret_code = (int)(next_dive -> dive_site_name); }
    {int sample_depth; sample_depth = (int)(next_dive -> dive_site_name); }
    {int max_depth; max_depth = (int)(next_dive -> dive_site_name); }
    {int sum_depth; sum_depth = (int)(next_dive -> dive_site_name); }
    {int count_samples; count_samples = (int)(next_dive -> dive_site_name); }
    {int * bins; bins = (int *)(next_dive -> dive_site_name); }
    {int bin_number; bin_number = (int)(next_dive -> dive_site_name); }
    {int i; i = (int)(next_dive -> dive_site_name); }
    {cgc_size_t tlv27; tlv27 = (cgc_size_t)(next_dive -> dive_site_name); }
    {cgc_size_t tlv29; tlv29 = (cgc_size_t)(next_dive -> dive_site_name); }
    {cgc_size_t tlv32; tlv32 = (cgc_size_t)(next_dive -> dive_site_name); }
    {cgc_size_t tlv31; tlv31 = (cgc_size_t)(next_dive -> dive_site_name); }
    {char * tlv3; tlv3 = (char *)(next_dive -> dive_site_name); }
    {char * tlv5; tlv5 = (char *)(next_dive -> dive_site_name); }
    {cgc_size_t tlv34; tlv34 = (cgc_size_t)(next_dive -> dive_site_name); }
    {cgc_size_t tlv33; tlv33 = (cgc_size_t)(next_dive -> dive_site_name); }
    {char * tlv36; tlv36 = (char *)(next_dive -> dive_site_name); }
    {cgc_size_t tlv35; tlv35 = (cgc_size_t)(next_dive -> dive_site_name); }
    {char * tlv38; tlv38 = (char *)(next_dive -> dive_site_name); }
    {cgc_size_t tlv37; tlv37 = (cgc_size_t)(next_dive -> dive_site_name); }
    {char * tlv40; tlv40 = (char *)(next_dive -> dive_site_name); }
    {cgc_size_t tlv39; tlv39 = (cgc_size_t)(next_dive -> dive_site_name); }
    {char * tlv42; tlv42 = (char *)(next_dive -> dive_site_name); }
    {cgc_size_t tlv41; tlv41 = (cgc_size_t)(next_dive -> dive_site_name); }
    {char * tlv44; tlv44 = (char *)(next_dive -> dive_site_name); }
    {cgc_size_t tlv43; tlv43 = (cgc_size_t)(next_dive -> dive_site_name); }
    {char * tlv46; tlv46 = (char *)(next_dive -> dive_site_name); }
    {cgc_size_t tlv45; tlv45 = (cgc_size_t)(next_dive -> dive_site_name); }
    {char * tlv48; tlv48 = (char *)(next_dive -> dive_site_name); }
    {cgc_size_t tlv47; tlv47 = (cgc_size_t)(next_dive -> dive_site_name); }
    {char * tlv50; tlv50 = (char *)(next_dive -> dive_site_name); }
    {cgc_size_t tlv49; tlv49 = (cgc_size_t)(next_dive -> dive_site_name); }
    {char * tlv52; tlv52 = (char *)(next_dive -> dive_site_name); }
    {cgc_size_t tlv51; tlv51 = (cgc_size_t)(next_dive -> dive_site_name); }
    {char * tlv54; tlv54 = (char *)(next_dive -> dive_site_name); }
    {cgc_size_t tlv53; tlv53 = (cgc_size_t)(next_dive -> dive_site_name); }
    {cgc_size_t tlv72; tlv72 = (cgc_size_t)(next_dive -> dive_site_name); }
    {cgc_size_t tlv71; tlv71 = (cgc_size_t)(next_dive -> dive_site_name); }
    {cgc_size_t tlv74; tlv74 = (cgc_size_t)(next_dive -> dive_site_name); }
    {cgc_size_t tlv73; tlv73 = (cgc_size_t)(next_dive -> dive_site_name); }
    {unsigned int tlv57; tlv57 = (unsigned int)(next_dive -> dive_site_name); }
    {cgc_size_t tlv75; tlv75 = (cgc_size_t)(next_dive -> dive_site_name); }
    {cgc_size_t tlv77; tlv77 = (cgc_size_t)(next_dive -> dive_site_name); }
    {cgc_size_t tlv80; tlv80 = (cgc_size_t)(next_dive -> dive_site_name); }
    {cgc_size_t tlv79; tlv79 = (cgc_size_t)(next_dive -> dive_site_name); }
    {unsigned int tlv58; tlv58 = (unsigned int)(next_dive -> dive_site_name); }
    {char * tlv61; tlv61 = (char *)(next_dive -> dive_site_name); }
    {cgc_size_t tlv59; tlv59 = (cgc_size_t)(next_dive -> dive_site_name); }
    {char * tlv64; tlv64 = (char *)(next_dive -> dive_site_name); }
    {cgc_size_t tlv62; tlv62 = (cgc_size_t)(next_dive -> dive_site_name); }
    {char * tlv67; tlv67 = (char *)(next_dive -> dive_site_name); }
    {cgc_size_t tlv65; tlv65 = (cgc_size_t)(next_dive -> dive_site_name); }
    {char * tlv70; tlv70 = (char *)(next_dive -> dive_site_name); }
    {cgc_size_t tlv68; tlv68 = (cgc_size_t)(next_dive -> dive_site_name); }
    {unsigned int tlv87; tlv87 = (unsigned int)(next_dive -> dive_site_name); }
    {unsigned int tlv88; tlv88 = (unsigned int)(next_dive -> dive_site_name); }
    {unsigned int tlv91; tlv91 = (unsigned int)(next_dive -> dive_site_name); }
}
void fix_ingred_download_dive_0_46(){
fix_ingred_download_dive_0_46_0();
}
void fix_ingred_download_dive_0_50_1(){
dive_log_type next_dive_ref;
    bzero(&next_dive_ref,1*sizeof(dive_log_type));
dive_log_type * next_dive = &next_dive_ref;
    {char buffer [ 1024 ]; buffer [ ( 1024 )-1 ] = (char)(sizeof ( next_dive -> dive_date )); }
    {char buffer2 [ 1024 ]; buffer2 [ ( 1024 )-1 ] = (char)(sizeof ( next_dive -> dive_date )); }
    {cgc_size_t count; count = (cgc_size_t)(sizeof ( next_dive -> dive_date )); }
    {int ret_code; ret_code = (int)(sizeof ( next_dive -> dive_date )); }
    {int sample_depth; sample_depth = (int)(sizeof ( next_dive -> dive_date )); }
    {int max_depth; max_depth = (int)(sizeof ( next_dive -> dive_date )); }
    {int sum_depth; sum_depth = (int)(sizeof ( next_dive -> dive_date )); }
    {int count_samples; count_samples = (int)(sizeof ( next_dive -> dive_date )); }
    {int * bins; bins = (int *)(sizeof ( next_dive -> dive_date )); }
    {int bin_number; bin_number = (int)(sizeof ( next_dive -> dive_date )); }
    {int i; i = (int)(sizeof ( next_dive -> dive_date )); }
    {cgc_size_t tlv27; tlv27 = (cgc_size_t)(sizeof ( next_dive -> dive_date )); }
    {cgc_size_t tlv29; tlv29 = (cgc_size_t)(sizeof ( next_dive -> dive_date )); }
    {cgc_size_t tlv32; tlv32 = (cgc_size_t)(sizeof ( next_dive -> dive_date )); }
    {cgc_size_t tlv31; tlv31 = (cgc_size_t)(sizeof ( next_dive -> dive_date )); }
    {char * tlv3; tlv3 = (char *)(sizeof ( next_dive -> dive_date )); }
    {char * tlv5; tlv5 = (char *)(sizeof ( next_dive -> dive_date )); }
    {cgc_size_t tlv34; tlv34 = (cgc_size_t)(sizeof ( next_dive -> dive_date )); }
    {cgc_size_t tlv33; tlv33 = (cgc_size_t)(sizeof ( next_dive -> dive_date )); }
    {char * tlv36; tlv36 = (char *)(sizeof ( next_dive -> dive_date )); }
    {cgc_size_t tlv35; tlv35 = (cgc_size_t)(sizeof ( next_dive -> dive_date )); }
    {char * tlv38; tlv38 = (char *)(sizeof ( next_dive -> dive_date )); }
    {cgc_size_t tlv37; tlv37 = (cgc_size_t)(sizeof ( next_dive -> dive_date )); }
    {char * tlv40; tlv40 = (char *)(sizeof ( next_dive -> dive_date )); }
    {cgc_size_t tlv39; tlv39 = (cgc_size_t)(sizeof ( next_dive -> dive_date )); }
    {char * tlv42; tlv42 = (char *)(sizeof ( next_dive -> dive_date )); }
    {cgc_size_t tlv41; tlv41 = (cgc_size_t)(sizeof ( next_dive -> dive_date )); }
    {char * tlv44; tlv44 = (char *)(sizeof ( next_dive -> dive_date )); }
    {cgc_size_t tlv43; tlv43 = (cgc_size_t)(sizeof ( next_dive -> dive_date )); }
    {char * tlv46; tlv46 = (char *)(sizeof ( next_dive -> dive_date )); }
    {cgc_size_t tlv45; tlv45 = (cgc_size_t)(sizeof ( next_dive -> dive_date )); }
    {char * tlv48; tlv48 = (char *)(sizeof ( next_dive -> dive_date )); }
    {cgc_size_t tlv47; tlv47 = (cgc_size_t)(sizeof ( next_dive -> dive_date )); }
    {char * tlv50; tlv50 = (char *)(sizeof ( next_dive -> dive_date )); }
    {cgc_size_t tlv49; tlv49 = (cgc_size_t)(sizeof ( next_dive -> dive_date )); }
    {char * tlv52; tlv52 = (char *)(sizeof ( next_dive -> dive_date )); }
    {cgc_size_t tlv51; tlv51 = (cgc_size_t)(sizeof ( next_dive -> dive_date )); }
    {char * tlv54; tlv54 = (char *)(sizeof ( next_dive -> dive_date )); }
    {cgc_size_t tlv53; tlv53 = (cgc_size_t)(sizeof ( next_dive -> dive_date )); }
    {cgc_size_t tlv72; tlv72 = (cgc_size_t)(sizeof ( next_dive -> dive_date )); }
    {cgc_size_t tlv71; tlv71 = (cgc_size_t)(sizeof ( next_dive -> dive_date )); }
    {cgc_size_t tlv74; tlv74 = (cgc_size_t)(sizeof ( next_dive -> dive_date )); }
    {cgc_size_t tlv73; tlv73 = (cgc_size_t)(sizeof ( next_dive -> dive_date )); }
    {unsigned int tlv57; tlv57 = (unsigned int)(sizeof ( next_dive -> dive_date )); }
    {cgc_size_t tlv75; tlv75 = (cgc_size_t)(sizeof ( next_dive -> dive_date )); }
    {cgc_size_t tlv77; tlv77 = (cgc_size_t)(sizeof ( next_dive -> dive_date )); }
    {cgc_size_t tlv80; tlv80 = (cgc_size_t)(sizeof ( next_dive -> dive_date )); }
    {cgc_size_t tlv79; tlv79 = (cgc_size_t)(sizeof ( next_dive -> dive_date )); }
    {unsigned int tlv58; tlv58 = (unsigned int)(sizeof ( next_dive -> dive_date )); }
    {char * tlv61; tlv61 = (char *)(sizeof ( next_dive -> dive_date )); }
    {cgc_size_t tlv59; tlv59 = (cgc_size_t)(sizeof ( next_dive -> dive_date )); }
    {char * tlv64; tlv64 = (char *)(sizeof ( next_dive -> dive_date )); }
    {cgc_size_t tlv62; tlv62 = (cgc_size_t)(sizeof ( next_dive -> dive_date )); }
    {char * tlv67; tlv67 = (char *)(sizeof ( next_dive -> dive_date )); }
    {cgc_size_t tlv65; tlv65 = (cgc_size_t)(sizeof ( next_dive -> dive_date )); }
    {char * tlv70; tlv70 = (char *)(sizeof ( next_dive -> dive_date )); }
    {cgc_size_t tlv68; tlv68 = (cgc_size_t)(sizeof ( next_dive -> dive_date )); }
    {unsigned int tlv87; tlv87 = (unsigned int)(sizeof ( next_dive -> dive_date )); }
    {unsigned int tlv88; tlv88 = (unsigned int)(sizeof ( next_dive -> dive_date )); }
    {unsigned int tlv91; tlv91 = (unsigned int)(sizeof ( next_dive -> dive_date )); }
}
void fix_ingred_download_dive_0_50(){
fix_ingred_download_dive_0_50_1();
}
void fix_ingred_download_dive_0_56_0(){
char buffer2 [ 1024 ];
    bzero(&buffer2,( 1024 *sizeof(char) ) );
dive_log_type next_dive_ref;
    bzero(&next_dive_ref,1*sizeof(dive_log_type));
dive_log_type * next_dive = &next_dive_ref;
    {char buffer [ 1024 ]; buffer [ ( 1024 )-1 ] = (char)(buffer2); }
    {char buffer2 [ 1024 ]; buffer2 [ ( 1024 )-1 ] = (char)(buffer2); }
    {cgc_size_t count; count = (cgc_size_t)(buffer2); }
    {int ret_code; ret_code = (int)(buffer2); }
    {int sample_depth; sample_depth = (int)(buffer2); }
    {int max_depth; max_depth = (int)(buffer2); }
    {int sum_depth; sum_depth = (int)(buffer2); }
    {int count_samples; count_samples = (int)(buffer2); }
    {int * bins; bins = (int *)(buffer2); }
    {int bin_number; bin_number = (int)(buffer2); }
    {int i; i = (int)(buffer2); }
    {cgc_size_t tlv27; tlv27 = (cgc_size_t)(buffer2); }
    {cgc_size_t tlv29; tlv29 = (cgc_size_t)(buffer2); }
    {cgc_size_t tlv32; tlv32 = (cgc_size_t)(buffer2); }
    {cgc_size_t tlv31; tlv31 = (cgc_size_t)(buffer2); }
    {char * tlv3; tlv3 = (char *)(buffer2); }
    {char * tlv5; tlv5 = (char *)(buffer2); }
    {cgc_size_t tlv34; tlv34 = (cgc_size_t)(buffer2); }
    {cgc_size_t tlv33; tlv33 = (cgc_size_t)(buffer2); }
    {char * tlv36; tlv36 = (char *)(buffer2); }
    {cgc_size_t tlv35; tlv35 = (cgc_size_t)(buffer2); }
    {char * tlv38; tlv38 = (char *)(buffer2); }
    {cgc_size_t tlv37; tlv37 = (cgc_size_t)(buffer2); }
    {char * tlv40; tlv40 = (char *)(buffer2); }
    {cgc_size_t tlv39; tlv39 = (cgc_size_t)(buffer2); }
    {char * tlv42; tlv42 = (char *)(buffer2); }
    {cgc_size_t tlv41; tlv41 = (cgc_size_t)(buffer2); }
    {char * tlv44; tlv44 = (char *)(buffer2); }
    {cgc_size_t tlv43; tlv43 = (cgc_size_t)(buffer2); }
    {char * tlv46; tlv46 = (char *)(buffer2); }
    {cgc_size_t tlv45; tlv45 = (cgc_size_t)(buffer2); }
    {char * tlv48; tlv48 = (char *)(buffer2); }
    {cgc_size_t tlv47; tlv47 = (cgc_size_t)(buffer2); }
    {char * tlv50; tlv50 = (char *)(buffer2); }
    {cgc_size_t tlv49; tlv49 = (cgc_size_t)(buffer2); }
    {char * tlv52; tlv52 = (char *)(buffer2); }
    {cgc_size_t tlv51; tlv51 = (cgc_size_t)(buffer2); }
    {char * tlv54; tlv54 = (char *)(buffer2); }
    {cgc_size_t tlv53; tlv53 = (cgc_size_t)(buffer2); }
    {cgc_size_t tlv72; tlv72 = (cgc_size_t)(buffer2); }
    {cgc_size_t tlv71; tlv71 = (cgc_size_t)(buffer2); }
    {cgc_size_t tlv74; tlv74 = (cgc_size_t)(buffer2); }
    {cgc_size_t tlv73; tlv73 = (cgc_size_t)(buffer2); }
    {unsigned int tlv57; tlv57 = (unsigned int)(buffer2); }
    {cgc_size_t tlv75; tlv75 = (cgc_size_t)(buffer2); }
    {cgc_size_t tlv77; tlv77 = (cgc_size_t)(buffer2); }
    {cgc_size_t tlv80; tlv80 = (cgc_size_t)(buffer2); }
    {cgc_size_t tlv79; tlv79 = (cgc_size_t)(buffer2); }
    {unsigned int tlv58; tlv58 = (unsigned int)(buffer2); }
    {char * tlv61; tlv61 = (char *)(buffer2); }
    {cgc_size_t tlv59; tlv59 = (cgc_size_t)(buffer2); }
    {char * tlv64; tlv64 = (char *)(buffer2); }
    {cgc_size_t tlv62; tlv62 = (cgc_size_t)(buffer2); }
    {char * tlv67; tlv67 = (char *)(buffer2); }
    {cgc_size_t tlv65; tlv65 = (cgc_size_t)(buffer2); }
    {char * tlv70; tlv70 = (char *)(buffer2); }
    {cgc_size_t tlv68; tlv68 = (cgc_size_t)(buffer2); }
    {unsigned int tlv87; tlv87 = (unsigned int)(buffer2); }
    {unsigned int tlv88; tlv88 = (unsigned int)(buffer2); }
    {unsigned int tlv91; tlv91 = (unsigned int)(buffer2); }
}
void fix_ingred_download_dive_0_56_1(){
char buffer2 [ 1024 ];
    bzero(&buffer2,( 1024 *sizeof(char) ) );
dive_log_type next_dive_ref;
    bzero(&next_dive_ref,1*sizeof(dive_log_type));
dive_log_type * next_dive = &next_dive_ref;
    {char buffer [ 1024 ]; buffer [ ( 1024 )-1 ] = (char)(sizeof ( next_dive -> dive_time )); }
    {char buffer2 [ 1024 ]; buffer2 [ ( 1024 )-1 ] = (char)(sizeof ( next_dive -> dive_time )); }
    {cgc_size_t count; count = (cgc_size_t)(sizeof ( next_dive -> dive_time )); }
    {int ret_code; ret_code = (int)(sizeof ( next_dive -> dive_time )); }
    {int sample_depth; sample_depth = (int)(sizeof ( next_dive -> dive_time )); }
    {int max_depth; max_depth = (int)(sizeof ( next_dive -> dive_time )); }
    {int sum_depth; sum_depth = (int)(sizeof ( next_dive -> dive_time )); }
    {int count_samples; count_samples = (int)(sizeof ( next_dive -> dive_time )); }
    {int * bins; bins = (int *)(sizeof ( next_dive -> dive_time )); }
    {int bin_number; bin_number = (int)(sizeof ( next_dive -> dive_time )); }
    {int i; i = (int)(sizeof ( next_dive -> dive_time )); }
    {cgc_size_t tlv27; tlv27 = (cgc_size_t)(sizeof ( next_dive -> dive_time )); }
    {cgc_size_t tlv29; tlv29 = (cgc_size_t)(sizeof ( next_dive -> dive_time )); }
    {cgc_size_t tlv32; tlv32 = (cgc_size_t)(sizeof ( next_dive -> dive_time )); }
    {cgc_size_t tlv31; tlv31 = (cgc_size_t)(sizeof ( next_dive -> dive_time )); }
    {char * tlv3; tlv3 = (char *)(sizeof ( next_dive -> dive_time )); }
    {char * tlv5; tlv5 = (char *)(sizeof ( next_dive -> dive_time )); }
    {cgc_size_t tlv34; tlv34 = (cgc_size_t)(sizeof ( next_dive -> dive_time )); }
    {cgc_size_t tlv33; tlv33 = (cgc_size_t)(sizeof ( next_dive -> dive_time )); }
    {char * tlv36; tlv36 = (char *)(sizeof ( next_dive -> dive_time )); }
    {cgc_size_t tlv35; tlv35 = (cgc_size_t)(sizeof ( next_dive -> dive_time )); }
    {char * tlv38; tlv38 = (char *)(sizeof ( next_dive -> dive_time )); }
    {cgc_size_t tlv37; tlv37 = (cgc_size_t)(sizeof ( next_dive -> dive_time )); }
    {char * tlv40; tlv40 = (char *)(sizeof ( next_dive -> dive_time )); }
    {cgc_size_t tlv39; tlv39 = (cgc_size_t)(sizeof ( next_dive -> dive_time )); }
    {char * tlv42; tlv42 = (char *)(sizeof ( next_dive -> dive_time )); }
    {cgc_size_t tlv41; tlv41 = (cgc_size_t)(sizeof ( next_dive -> dive_time )); }
    {char * tlv44; tlv44 = (char *)(sizeof ( next_dive -> dive_time )); }
    {cgc_size_t tlv43; tlv43 = (cgc_size_t)(sizeof ( next_dive -> dive_time )); }
    {char * tlv46; tlv46 = (char *)(sizeof ( next_dive -> dive_time )); }
    {cgc_size_t tlv45; tlv45 = (cgc_size_t)(sizeof ( next_dive -> dive_time )); }
    {char * tlv48; tlv48 = (char *)(sizeof ( next_dive -> dive_time )); }
    {cgc_size_t tlv47; tlv47 = (cgc_size_t)(sizeof ( next_dive -> dive_time )); }
    {char * tlv50; tlv50 = (char *)(sizeof ( next_dive -> dive_time )); }
    {cgc_size_t tlv49; tlv49 = (cgc_size_t)(sizeof ( next_dive -> dive_time )); }
    {char * tlv52; tlv52 = (char *)(sizeof ( next_dive -> dive_time )); }
    {cgc_size_t tlv51; tlv51 = (cgc_size_t)(sizeof ( next_dive -> dive_time )); }
    {char * tlv54; tlv54 = (char *)(sizeof ( next_dive -> dive_time )); }
    {cgc_size_t tlv53; tlv53 = (cgc_size_t)(sizeof ( next_dive -> dive_time )); }
    {cgc_size_t tlv72; tlv72 = (cgc_size_t)(sizeof ( next_dive -> dive_time )); }
    {cgc_size_t tlv71; tlv71 = (cgc_size_t)(sizeof ( next_dive -> dive_time )); }
    {cgc_size_t tlv74; tlv74 = (cgc_size_t)(sizeof ( next_dive -> dive_time )); }
    {cgc_size_t tlv73; tlv73 = (cgc_size_t)(sizeof ( next_dive -> dive_time )); }
    {unsigned int tlv57; tlv57 = (unsigned int)(sizeof ( next_dive -> dive_time )); }
    {cgc_size_t tlv75; tlv75 = (cgc_size_t)(sizeof ( next_dive -> dive_time )); }
    {cgc_size_t tlv77; tlv77 = (cgc_size_t)(sizeof ( next_dive -> dive_time )); }
    {cgc_size_t tlv80; tlv80 = (cgc_size_t)(sizeof ( next_dive -> dive_time )); }
    {cgc_size_t tlv79; tlv79 = (cgc_size_t)(sizeof ( next_dive -> dive_time )); }
    {unsigned int tlv58; tlv58 = (unsigned int)(sizeof ( next_dive -> dive_time )); }
    {char * tlv61; tlv61 = (char *)(sizeof ( next_dive -> dive_time )); }
    {cgc_size_t tlv59; tlv59 = (cgc_size_t)(sizeof ( next_dive -> dive_time )); }
    {char * tlv64; tlv64 = (char *)(sizeof ( next_dive -> dive_time )); }
    {cgc_size_t tlv62; tlv62 = (cgc_size_t)(sizeof ( next_dive -> dive_time )); }
    {char * tlv67; tlv67 = (char *)(sizeof ( next_dive -> dive_time )); }
    {cgc_size_t tlv65; tlv65 = (cgc_size_t)(sizeof ( next_dive -> dive_time )); }
    {char * tlv70; tlv70 = (char *)(sizeof ( next_dive -> dive_time )); }
    {cgc_size_t tlv68; tlv68 = (cgc_size_t)(sizeof ( next_dive -> dive_time )); }
    {unsigned int tlv87; tlv87 = (unsigned int)(sizeof ( next_dive -> dive_time )); }
    {unsigned int tlv88; tlv88 = (unsigned int)(sizeof ( next_dive -> dive_time )); }
    {unsigned int tlv91; tlv91 = (unsigned int)(sizeof ( next_dive -> dive_time )); }
}
void fix_ingred_download_dive_0_56(){
fix_ingred_download_dive_0_56_0();
fix_ingred_download_dive_0_56_1();
}
void fix_ingred_download_dive_0_62_1(){
dive_log_type next_dive_ref;
    bzero(&next_dive_ref,1*sizeof(dive_log_type));
dive_log_type * next_dive = &next_dive_ref;
    {char buffer [ 1024 ]; buffer [ ( 1024 )-1 ] = (char)(sizeof ( next_dive -> location )); }
    {char buffer2 [ 1024 ]; buffer2 [ ( 1024 )-1 ] = (char)(sizeof ( next_dive -> location )); }
    {cgc_size_t count; count = (cgc_size_t)(sizeof ( next_dive -> location )); }
    {int ret_code; ret_code = (int)(sizeof ( next_dive -> location )); }
    {int sample_depth; sample_depth = (int)(sizeof ( next_dive -> location )); }
    {int max_depth; max_depth = (int)(sizeof ( next_dive -> location )); }
    {int sum_depth; sum_depth = (int)(sizeof ( next_dive -> location )); }
    {int count_samples; count_samples = (int)(sizeof ( next_dive -> location )); }
    {int * bins; bins = (int *)(sizeof ( next_dive -> location )); }
    {int bin_number; bin_number = (int)(sizeof ( next_dive -> location )); }
    {int i; i = (int)(sizeof ( next_dive -> location )); }
    {cgc_size_t tlv27; tlv27 = (cgc_size_t)(sizeof ( next_dive -> location )); }
    {cgc_size_t tlv29; tlv29 = (cgc_size_t)(sizeof ( next_dive -> location )); }
    {cgc_size_t tlv32; tlv32 = (cgc_size_t)(sizeof ( next_dive -> location )); }
    {cgc_size_t tlv31; tlv31 = (cgc_size_t)(sizeof ( next_dive -> location )); }
    {char * tlv3; tlv3 = (char *)(sizeof ( next_dive -> location )); }
    {char * tlv5; tlv5 = (char *)(sizeof ( next_dive -> location )); }
    {cgc_size_t tlv34; tlv34 = (cgc_size_t)(sizeof ( next_dive -> location )); }
    {cgc_size_t tlv33; tlv33 = (cgc_size_t)(sizeof ( next_dive -> location )); }
    {char * tlv36; tlv36 = (char *)(sizeof ( next_dive -> location )); }
    {cgc_size_t tlv35; tlv35 = (cgc_size_t)(sizeof ( next_dive -> location )); }
    {char * tlv38; tlv38 = (char *)(sizeof ( next_dive -> location )); }
    {cgc_size_t tlv37; tlv37 = (cgc_size_t)(sizeof ( next_dive -> location )); }
    {char * tlv40; tlv40 = (char *)(sizeof ( next_dive -> location )); }
    {cgc_size_t tlv39; tlv39 = (cgc_size_t)(sizeof ( next_dive -> location )); }
    {char * tlv42; tlv42 = (char *)(sizeof ( next_dive -> location )); }
    {cgc_size_t tlv41; tlv41 = (cgc_size_t)(sizeof ( next_dive -> location )); }
    {char * tlv44; tlv44 = (char *)(sizeof ( next_dive -> location )); }
    {cgc_size_t tlv43; tlv43 = (cgc_size_t)(sizeof ( next_dive -> location )); }
    {char * tlv46; tlv46 = (char *)(sizeof ( next_dive -> location )); }
    {cgc_size_t tlv45; tlv45 = (cgc_size_t)(sizeof ( next_dive -> location )); }
    {char * tlv48; tlv48 = (char *)(sizeof ( next_dive -> location )); }
    {cgc_size_t tlv47; tlv47 = (cgc_size_t)(sizeof ( next_dive -> location )); }
    {char * tlv50; tlv50 = (char *)(sizeof ( next_dive -> location )); }
    {cgc_size_t tlv49; tlv49 = (cgc_size_t)(sizeof ( next_dive -> location )); }
    {char * tlv52; tlv52 = (char *)(sizeof ( next_dive -> location )); }
    {cgc_size_t tlv51; tlv51 = (cgc_size_t)(sizeof ( next_dive -> location )); }
    {char * tlv54; tlv54 = (char *)(sizeof ( next_dive -> location )); }
    {cgc_size_t tlv53; tlv53 = (cgc_size_t)(sizeof ( next_dive -> location )); }
    {cgc_size_t tlv72; tlv72 = (cgc_size_t)(sizeof ( next_dive -> location )); }
    {cgc_size_t tlv71; tlv71 = (cgc_size_t)(sizeof ( next_dive -> location )); }
    {cgc_size_t tlv74; tlv74 = (cgc_size_t)(sizeof ( next_dive -> location )); }
    {cgc_size_t tlv73; tlv73 = (cgc_size_t)(sizeof ( next_dive -> location )); }
    {unsigned int tlv57; tlv57 = (unsigned int)(sizeof ( next_dive -> location )); }
    {cgc_size_t tlv75; tlv75 = (cgc_size_t)(sizeof ( next_dive -> location )); }
    {cgc_size_t tlv77; tlv77 = (cgc_size_t)(sizeof ( next_dive -> location )); }
    {cgc_size_t tlv80; tlv80 = (cgc_size_t)(sizeof ( next_dive -> location )); }
    {cgc_size_t tlv79; tlv79 = (cgc_size_t)(sizeof ( next_dive -> location )); }
    {unsigned int tlv58; tlv58 = (unsigned int)(sizeof ( next_dive -> location )); }
    {char * tlv61; tlv61 = (char *)(sizeof ( next_dive -> location )); }
    {cgc_size_t tlv59; tlv59 = (cgc_size_t)(sizeof ( next_dive -> location )); }
    {char * tlv64; tlv64 = (char *)(sizeof ( next_dive -> location )); }
    {cgc_size_t tlv62; tlv62 = (cgc_size_t)(sizeof ( next_dive -> location )); }
    {char * tlv67; tlv67 = (char *)(sizeof ( next_dive -> location )); }
    {cgc_size_t tlv65; tlv65 = (cgc_size_t)(sizeof ( next_dive -> location )); }
    {char * tlv70; tlv70 = (char *)(sizeof ( next_dive -> location )); }
    {cgc_size_t tlv68; tlv68 = (cgc_size_t)(sizeof ( next_dive -> location )); }
    {unsigned int tlv87; tlv87 = (unsigned int)(sizeof ( next_dive -> location )); }
    {unsigned int tlv88; tlv88 = (unsigned int)(sizeof ( next_dive -> location )); }
    {unsigned int tlv91; tlv91 = (unsigned int)(sizeof ( next_dive -> location )); }
}
void fix_ingred_download_dive_0_62(){
fix_ingred_download_dive_0_62_1();
}
void fix_ingred_download_dive_0_64_0(){
dive_log_type next_dive_ref;
    bzero(&next_dive_ref,1*sizeof(dive_log_type));
dive_log_type * next_dive = &next_dive_ref;
    {char buffer [ 1024 ]; buffer [ ( 1024 )-1 ] = (char)(next_dive -> location); }
    {char buffer2 [ 1024 ]; buffer2 [ ( 1024 )-1 ] = (char)(next_dive -> location); }
    {cgc_size_t count; count = (cgc_size_t)(next_dive -> location); }
    {int ret_code; ret_code = (int)(next_dive -> location); }
    {int sample_depth; sample_depth = (int)(next_dive -> location); }
    {int max_depth; max_depth = (int)(next_dive -> location); }
    {int sum_depth; sum_depth = (int)(next_dive -> location); }
    {int count_samples; count_samples = (int)(next_dive -> location); }
    {int * bins; bins = (int *)(next_dive -> location); }
    {int bin_number; bin_number = (int)(next_dive -> location); }
    {int i; i = (int)(next_dive -> location); }
    {cgc_size_t tlv27; tlv27 = (cgc_size_t)(next_dive -> location); }
    {cgc_size_t tlv29; tlv29 = (cgc_size_t)(next_dive -> location); }
    {cgc_size_t tlv32; tlv32 = (cgc_size_t)(next_dive -> location); }
    {cgc_size_t tlv31; tlv31 = (cgc_size_t)(next_dive -> location); }
    {char * tlv3; tlv3 = (char *)(next_dive -> location); }
    {char * tlv5; tlv5 = (char *)(next_dive -> location); }
    {cgc_size_t tlv34; tlv34 = (cgc_size_t)(next_dive -> location); }
    {cgc_size_t tlv33; tlv33 = (cgc_size_t)(next_dive -> location); }
    {char * tlv36; tlv36 = (char *)(next_dive -> location); }
    {cgc_size_t tlv35; tlv35 = (cgc_size_t)(next_dive -> location); }
    {char * tlv38; tlv38 = (char *)(next_dive -> location); }
    {cgc_size_t tlv37; tlv37 = (cgc_size_t)(next_dive -> location); }
    {char * tlv40; tlv40 = (char *)(next_dive -> location); }
    {cgc_size_t tlv39; tlv39 = (cgc_size_t)(next_dive -> location); }
    {char * tlv42; tlv42 = (char *)(next_dive -> location); }
    {cgc_size_t tlv41; tlv41 = (cgc_size_t)(next_dive -> location); }
    {char * tlv44; tlv44 = (char *)(next_dive -> location); }
    {cgc_size_t tlv43; tlv43 = (cgc_size_t)(next_dive -> location); }
    {char * tlv46; tlv46 = (char *)(next_dive -> location); }
    {cgc_size_t tlv45; tlv45 = (cgc_size_t)(next_dive -> location); }
    {char * tlv48; tlv48 = (char *)(next_dive -> location); }
    {cgc_size_t tlv47; tlv47 = (cgc_size_t)(next_dive -> location); }
    {char * tlv50; tlv50 = (char *)(next_dive -> location); }
    {cgc_size_t tlv49; tlv49 = (cgc_size_t)(next_dive -> location); }
    {char * tlv52; tlv52 = (char *)(next_dive -> location); }
    {cgc_size_t tlv51; tlv51 = (cgc_size_t)(next_dive -> location); }
    {char * tlv54; tlv54 = (char *)(next_dive -> location); }
    {cgc_size_t tlv53; tlv53 = (cgc_size_t)(next_dive -> location); }
    {cgc_size_t tlv72; tlv72 = (cgc_size_t)(next_dive -> location); }
    {cgc_size_t tlv71; tlv71 = (cgc_size_t)(next_dive -> location); }
    {cgc_size_t tlv74; tlv74 = (cgc_size_t)(next_dive -> location); }
    {cgc_size_t tlv73; tlv73 = (cgc_size_t)(next_dive -> location); }
    {unsigned int tlv57; tlv57 = (unsigned int)(next_dive -> location); }
    {cgc_size_t tlv75; tlv75 = (cgc_size_t)(next_dive -> location); }
    {cgc_size_t tlv77; tlv77 = (cgc_size_t)(next_dive -> location); }
    {cgc_size_t tlv80; tlv80 = (cgc_size_t)(next_dive -> location); }
    {cgc_size_t tlv79; tlv79 = (cgc_size_t)(next_dive -> location); }
    {unsigned int tlv58; tlv58 = (unsigned int)(next_dive -> location); }
    {char * tlv61; tlv61 = (char *)(next_dive -> location); }
    {cgc_size_t tlv59; tlv59 = (cgc_size_t)(next_dive -> location); }
    {char * tlv64; tlv64 = (char *)(next_dive -> location); }
    {cgc_size_t tlv62; tlv62 = (cgc_size_t)(next_dive -> location); }
    {char * tlv67; tlv67 = (char *)(next_dive -> location); }
    {cgc_size_t tlv65; tlv65 = (cgc_size_t)(next_dive -> location); }
    {char * tlv70; tlv70 = (char *)(next_dive -> location); }
    {cgc_size_t tlv68; tlv68 = (cgc_size_t)(next_dive -> location); }
    {unsigned int tlv87; tlv87 = (unsigned int)(next_dive -> location); }
    {unsigned int tlv88; tlv88 = (unsigned int)(next_dive -> location); }
    {unsigned int tlv91; tlv91 = (unsigned int)(next_dive -> location); }
}
void fix_ingred_download_dive_0_64(){
fix_ingred_download_dive_0_64_0();
}
void fix_ingred_download_dive_0_68_1(){
char buffer [ 1024 ];
    bzero(&buffer,( 1024 *sizeof(char) ) );
    {char buffer [ 1024 ]; buffer [ ( 1024 )-1 ] = (char)(sizeof ( buffer )); }
    {char buffer2 [ 1024 ]; buffer2 [ ( 1024 )-1 ] = (char)(sizeof ( buffer )); }
    {cgc_size_t count; count = (cgc_size_t)(sizeof ( buffer )); }
    {int ret_code; ret_code = (int)(sizeof ( buffer )); }
    {int sample_depth; sample_depth = (int)(sizeof ( buffer )); }
    {int max_depth; max_depth = (int)(sizeof ( buffer )); }
    {int sum_depth; sum_depth = (int)(sizeof ( buffer )); }
    {int count_samples; count_samples = (int)(sizeof ( buffer )); }
    {int * bins; bins = (int *)(sizeof ( buffer )); }
    {int bin_number; bin_number = (int)(sizeof ( buffer )); }
    {int i; i = (int)(sizeof ( buffer )); }
    {cgc_size_t tlv27; tlv27 = (cgc_size_t)(sizeof ( buffer )); }
    {cgc_size_t tlv29; tlv29 = (cgc_size_t)(sizeof ( buffer )); }
    {cgc_size_t tlv32; tlv32 = (cgc_size_t)(sizeof ( buffer )); }
    {cgc_size_t tlv31; tlv31 = (cgc_size_t)(sizeof ( buffer )); }
    {char * tlv3; tlv3 = (char *)(sizeof ( buffer )); }
    {char * tlv5; tlv5 = (char *)(sizeof ( buffer )); }
    {cgc_size_t tlv34; tlv34 = (cgc_size_t)(sizeof ( buffer )); }
    {cgc_size_t tlv33; tlv33 = (cgc_size_t)(sizeof ( buffer )); }
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
    {char * tlv50; tlv50 = (char *)(sizeof ( buffer )); }
    {cgc_size_t tlv49; tlv49 = (cgc_size_t)(sizeof ( buffer )); }
    {char * tlv52; tlv52 = (char *)(sizeof ( buffer )); }
    {cgc_size_t tlv51; tlv51 = (cgc_size_t)(sizeof ( buffer )); }
    {char * tlv54; tlv54 = (char *)(sizeof ( buffer )); }
    {cgc_size_t tlv53; tlv53 = (cgc_size_t)(sizeof ( buffer )); }
    {cgc_size_t tlv72; tlv72 = (cgc_size_t)(sizeof ( buffer )); }
    {cgc_size_t tlv71; tlv71 = (cgc_size_t)(sizeof ( buffer )); }
    {cgc_size_t tlv74; tlv74 = (cgc_size_t)(sizeof ( buffer )); }
    {cgc_size_t tlv73; tlv73 = (cgc_size_t)(sizeof ( buffer )); }
    {unsigned int tlv57; tlv57 = (unsigned int)(sizeof ( buffer )); }
    {cgc_size_t tlv75; tlv75 = (cgc_size_t)(sizeof ( buffer )); }
    {cgc_size_t tlv77; tlv77 = (cgc_size_t)(sizeof ( buffer )); }
    {cgc_size_t tlv80; tlv80 = (cgc_size_t)(sizeof ( buffer )); }
    {cgc_size_t tlv79; tlv79 = (cgc_size_t)(sizeof ( buffer )); }
    {unsigned int tlv58; tlv58 = (unsigned int)(sizeof ( buffer )); }
    {char * tlv61; tlv61 = (char *)(sizeof ( buffer )); }
    {cgc_size_t tlv59; tlv59 = (cgc_size_t)(sizeof ( buffer )); }
    {char * tlv64; tlv64 = (char *)(sizeof ( buffer )); }
    {cgc_size_t tlv62; tlv62 = (cgc_size_t)(sizeof ( buffer )); }
    {char * tlv67; tlv67 = (char *)(sizeof ( buffer )); }
    {cgc_size_t tlv65; tlv65 = (cgc_size_t)(sizeof ( buffer )); }
    {char * tlv70; tlv70 = (char *)(sizeof ( buffer )); }
    {cgc_size_t tlv68; tlv68 = (cgc_size_t)(sizeof ( buffer )); }
    {unsigned int tlv87; tlv87 = (unsigned int)(sizeof ( buffer )); }
    {unsigned int tlv88; tlv88 = (unsigned int)(sizeof ( buffer )); }
    {unsigned int tlv91; tlv91 = (unsigned int)(sizeof ( buffer )); }
}
void fix_ingred_download_dive_0_68(){
fix_ingred_download_dive_0_68_1();
}
void fix_ingred_download_dive_0_80_1(){
    {char buffer [ 1024 ]; buffer [ ( 1024 )-1 ] = (char)(13); }
    {char buffer2 [ 1024 ]; buffer2 [ ( 1024 )-1 ] = (char)(13); }
    {cgc_size_t count; count = (cgc_size_t)(13); }
    {int ret_code; ret_code = (int)(13); }
    {int sample_depth; sample_depth = (int)(13); }
    {int max_depth; max_depth = (int)(13); }
    {int sum_depth; sum_depth = (int)(13); }
    {int count_samples; count_samples = (int)(13); }
    {int * bins; bins = (int *)(13); }
    {int bin_number; bin_number = (int)(13); }
    {int i; i = (int)(13); }
    {cgc_size_t tlv27; tlv27 = (cgc_size_t)(13); }
    {cgc_size_t tlv29; tlv29 = (cgc_size_t)(13); }
    {cgc_size_t tlv32; tlv32 = (cgc_size_t)(13); }
    {cgc_size_t tlv31; tlv31 = (cgc_size_t)(13); }
    {char * tlv3; tlv3 = (char *)(13); }
    {char * tlv5; tlv5 = (char *)(13); }
    {cgc_size_t tlv34; tlv34 = (cgc_size_t)(13); }
    {cgc_size_t tlv33; tlv33 = (cgc_size_t)(13); }
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
    {char * tlv50; tlv50 = (char *)(13); }
    {cgc_size_t tlv49; tlv49 = (cgc_size_t)(13); }
    {char * tlv52; tlv52 = (char *)(13); }
    {cgc_size_t tlv51; tlv51 = (cgc_size_t)(13); }
    {char * tlv54; tlv54 = (char *)(13); }
    {cgc_size_t tlv53; tlv53 = (cgc_size_t)(13); }
    {cgc_size_t tlv72; tlv72 = (cgc_size_t)(13); }
    {cgc_size_t tlv71; tlv71 = (cgc_size_t)(13); }
    {cgc_size_t tlv74; tlv74 = (cgc_size_t)(13); }
    {cgc_size_t tlv73; tlv73 = (cgc_size_t)(13); }
    {unsigned int tlv57; tlv57 = (unsigned int)(13); }
    {cgc_size_t tlv75; tlv75 = (cgc_size_t)(13); }
    {cgc_size_t tlv77; tlv77 = (cgc_size_t)(13); }
    {cgc_size_t tlv80; tlv80 = (cgc_size_t)(13); }
    {cgc_size_t tlv79; tlv79 = (cgc_size_t)(13); }
    {unsigned int tlv58; tlv58 = (unsigned int)(13); }
    {char * tlv61; tlv61 = (char *)(13); }
    {cgc_size_t tlv59; tlv59 = (cgc_size_t)(13); }
    {char * tlv64; tlv64 = (char *)(13); }
    {cgc_size_t tlv62; tlv62 = (cgc_size_t)(13); }
    {char * tlv67; tlv67 = (char *)(13); }
    {cgc_size_t tlv65; tlv65 = (cgc_size_t)(13); }
    {char * tlv70; tlv70 = (char *)(13); }
    {cgc_size_t tlv68; tlv68 = (cgc_size_t)(13); }
    {unsigned int tlv87; tlv87 = (unsigned int)(13); }
    {unsigned int tlv88; tlv88 = (unsigned int)(13); }
    {unsigned int tlv91; tlv91 = (unsigned int)(13); }
}
void fix_ingred_download_dive_0_80(){
fix_ingred_download_dive_0_80_1();
}
void fix_ingred_download_dive_0_86_1(){
    {char buffer [ 1024 ]; buffer [ ( 1024 )-1 ] = (char)(11); }
    {char buffer2 [ 1024 ]; buffer2 [ ( 1024 )-1 ] = (char)(11); }
    {cgc_size_t count; count = (cgc_size_t)(11); }
    {int ret_code; ret_code = (int)(11); }
    {int sample_depth; sample_depth = (int)(11); }
    {int max_depth; max_depth = (int)(11); }
    {int sum_depth; sum_depth = (int)(11); }
    {int count_samples; count_samples = (int)(11); }
    {int * bins; bins = (int *)(11); }
    {int bin_number; bin_number = (int)(11); }
    {int i; i = (int)(11); }
    {cgc_size_t tlv27; tlv27 = (cgc_size_t)(11); }
    {cgc_size_t tlv29; tlv29 = (cgc_size_t)(11); }
    {cgc_size_t tlv32; tlv32 = (cgc_size_t)(11); }
    {cgc_size_t tlv31; tlv31 = (cgc_size_t)(11); }
    {char * tlv3; tlv3 = (char *)(11); }
    {char * tlv5; tlv5 = (char *)(11); }
    {cgc_size_t tlv34; tlv34 = (cgc_size_t)(11); }
    {cgc_size_t tlv33; tlv33 = (cgc_size_t)(11); }
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
    {char * tlv50; tlv50 = (char *)(11); }
    {cgc_size_t tlv49; tlv49 = (cgc_size_t)(11); }
    {char * tlv52; tlv52 = (char *)(11); }
    {cgc_size_t tlv51; tlv51 = (cgc_size_t)(11); }
    {char * tlv54; tlv54 = (char *)(11); }
    {cgc_size_t tlv53; tlv53 = (cgc_size_t)(11); }
    {cgc_size_t tlv72; tlv72 = (cgc_size_t)(11); }
    {cgc_size_t tlv71; tlv71 = (cgc_size_t)(11); }
    {cgc_size_t tlv74; tlv74 = (cgc_size_t)(11); }
    {cgc_size_t tlv73; tlv73 = (cgc_size_t)(11); }
    {unsigned int tlv57; tlv57 = (unsigned int)(11); }
    {cgc_size_t tlv75; tlv75 = (cgc_size_t)(11); }
    {cgc_size_t tlv77; tlv77 = (cgc_size_t)(11); }
    {cgc_size_t tlv80; tlv80 = (cgc_size_t)(11); }
    {cgc_size_t tlv79; tlv79 = (cgc_size_t)(11); }
    {unsigned int tlv58; tlv58 = (unsigned int)(11); }
    {char * tlv61; tlv61 = (char *)(11); }
    {cgc_size_t tlv59; tlv59 = (cgc_size_t)(11); }
    {char * tlv64; tlv64 = (char *)(11); }
    {cgc_size_t tlv62; tlv62 = (cgc_size_t)(11); }
    {char * tlv67; tlv67 = (char *)(11); }
    {cgc_size_t tlv65; tlv65 = (cgc_size_t)(11); }
    {char * tlv70; tlv70 = (char *)(11); }
    {cgc_size_t tlv68; tlv68 = (cgc_size_t)(11); }
    {unsigned int tlv87; tlv87 = (unsigned int)(11); }
    {unsigned int tlv88; tlv88 = (unsigned int)(11); }
    {unsigned int tlv91; tlv91 = (unsigned int)(11); }
}
void fix_ingred_download_dive_0_86(){
fix_ingred_download_dive_0_86_1();
}
void fix_ingred_download_dive_0_92_1(){
    {char buffer [ 1024 ]; buffer [ ( 1024 )-1 ] = (char)(20); }
    {char buffer2 [ 1024 ]; buffer2 [ ( 1024 )-1 ] = (char)(20); }
    {cgc_size_t count; count = (cgc_size_t)(20); }
    {int ret_code; ret_code = (int)(20); }
    {int sample_depth; sample_depth = (int)(20); }
    {int max_depth; max_depth = (int)(20); }
    {int sum_depth; sum_depth = (int)(20); }
    {int count_samples; count_samples = (int)(20); }
    {int * bins; bins = (int *)(20); }
    {int bin_number; bin_number = (int)(20); }
    {int i; i = (int)(20); }
    {cgc_size_t tlv27; tlv27 = (cgc_size_t)(20); }
    {cgc_size_t tlv29; tlv29 = (cgc_size_t)(20); }
    {cgc_size_t tlv32; tlv32 = (cgc_size_t)(20); }
    {cgc_size_t tlv31; tlv31 = (cgc_size_t)(20); }
    {char * tlv3; tlv3 = (char *)(20); }
    {char * tlv5; tlv5 = (char *)(20); }
    {cgc_size_t tlv34; tlv34 = (cgc_size_t)(20); }
    {cgc_size_t tlv33; tlv33 = (cgc_size_t)(20); }
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
    {char * tlv50; tlv50 = (char *)(20); }
    {cgc_size_t tlv49; tlv49 = (cgc_size_t)(20); }
    {char * tlv52; tlv52 = (char *)(20); }
    {cgc_size_t tlv51; tlv51 = (cgc_size_t)(20); }
    {char * tlv54; tlv54 = (char *)(20); }
    {cgc_size_t tlv53; tlv53 = (cgc_size_t)(20); }
    {cgc_size_t tlv72; tlv72 = (cgc_size_t)(20); }
    {cgc_size_t tlv71; tlv71 = (cgc_size_t)(20); }
    {cgc_size_t tlv74; tlv74 = (cgc_size_t)(20); }
    {cgc_size_t tlv73; tlv73 = (cgc_size_t)(20); }
    {unsigned int tlv57; tlv57 = (unsigned int)(20); }
    {cgc_size_t tlv75; tlv75 = (cgc_size_t)(20); }
    {cgc_size_t tlv77; tlv77 = (cgc_size_t)(20); }
    {cgc_size_t tlv80; tlv80 = (cgc_size_t)(20); }
    {cgc_size_t tlv79; tlv79 = (cgc_size_t)(20); }
    {unsigned int tlv58; tlv58 = (unsigned int)(20); }
    {char * tlv61; tlv61 = (char *)(20); }
    {cgc_size_t tlv59; tlv59 = (cgc_size_t)(20); }
    {char * tlv64; tlv64 = (char *)(20); }
    {cgc_size_t tlv62; tlv62 = (cgc_size_t)(20); }
    {char * tlv67; tlv67 = (char *)(20); }
    {cgc_size_t tlv65; tlv65 = (cgc_size_t)(20); }
    {char * tlv70; tlv70 = (char *)(20); }
    {cgc_size_t tlv68; tlv68 = (cgc_size_t)(20); }
    {unsigned int tlv87; tlv87 = (unsigned int)(20); }
    {unsigned int tlv88; tlv88 = (unsigned int)(20); }
    {unsigned int tlv91; tlv91 = (unsigned int)(20); }
}
void fix_ingred_download_dive_0_92(){
fix_ingred_download_dive_0_92_1();
}
void fix_ingred_download_dive_0(){
fix_ingred_download_dive_0_0();
fix_ingred_download_dive_0_1();
fix_ingred_download_dive_0_2();
fix_ingred_download_dive_0_4();
fix_ingred_download_dive_0_8();
fix_ingred_download_dive_0_10();
fix_ingred_download_dive_0_16();
fix_ingred_download_dive_0_21();
fix_ingred_download_dive_0_28();
fix_ingred_download_dive_0_31();
fix_ingred_download_dive_0_32();
fix_ingred_download_dive_0_33();
fix_ingred_download_dive_0_34();
fix_ingred_download_dive_0_36();
fix_ingred_download_dive_0_38();
fix_ingred_download_dive_0_39();
fix_ingred_download_dive_0_44();
fix_ingred_download_dive_0_45();
fix_ingred_download_dive_0_46();
fix_ingred_download_dive_0_50();
fix_ingred_download_dive_0_56();
fix_ingred_download_dive_0_62();
fix_ingred_download_dive_0_64();
fix_ingred_download_dive_0_68();
fix_ingred_download_dive_0_80();
fix_ingred_download_dive_0_86();
fix_ingred_download_dive_0_92();
}
