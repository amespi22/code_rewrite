

#include "cgc_genericParsers.h"
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

void fix_ingred_genericParsers_0_0_0();
void fix_ingred_genericParsers_0_0_2();
void fix_ingred_genericParsers_0_0_4();
void fix_ingred_genericParsers_0_0();
void fix_ingred_genericParsers_0_2_0();
void fix_ingred_genericParsers_0_2();
void fix_ingred_genericParsers_0_3_5();
void fix_ingred_genericParsers_0_3();
void fix_ingred_genericParsers_0_4_1();
void fix_ingred_genericParsers_0_4();
void fix_ingred_genericParsers_0_7_1();
void fix_ingred_genericParsers_0_7();
void fix_ingred_genericParsers_0_8_4();
void fix_ingred_genericParsers_0_8_5();
void fix_ingred_genericParsers_0_8();
void fix_ingred_genericParsers_0_11_5();
void fix_ingred_genericParsers_0_11();
void fix_ingred_genericParsers_0_13_5();
void fix_ingred_genericParsers_0_13();
void fix_ingred_genericParsers_0_15_5();
void fix_ingred_genericParsers_0_15();
void fix_ingred_genericParsers_0_17_6();
void fix_ingred_genericParsers_0_17();
void fix_ingred_genericParsers_0_19_0();
void fix_ingred_genericParsers_0_19();
void fix_ingred_genericParsers_0_20_1();
void fix_ingred_genericParsers_0_20();
void fix_ingred_genericParsers_0_22_1();
void fix_ingred_genericParsers_0_22();
void fix_ingred_genericParsers_0_23_1();
void fix_ingred_genericParsers_0_23();
void fix_ingred_genericParsers_0_27_5();
void fix_ingred_genericParsers_0_27();
void fix_ingred_genericParsers_0_39_1();
void fix_ingred_genericParsers_0_39();
void fix_ingred_genericParsers_0_77_5();
void fix_ingred_genericParsers_0_77();
void fix_ingred_genericParsers_0_79_1();
void fix_ingred_genericParsers_0_79();
void fix_ingred_genericParsers_0_90_5();
void fix_ingred_genericParsers_0_90();
void fix_ingred_genericParsers_0_92_1();
void fix_ingred_genericParsers_0_92();
void fix_ingred_genericParsers_0_94_1();
void fix_ingred_genericParsers_0_94();
void fix_ingred_genericParsers_0_99_0();
void fix_ingred_genericParsers_0_99();
void fix_ingred_genericParsers_0();
Border *cgc_extractBorder(pstring str)
{
if (fix_ingred_enable){ fix_ingred_genericParsers_0(); };
    char* temp;
     temp = NULL;
    pBorder bor;
    bor = NULL;
    int start;
    start = 0;
    int end;
    end = 0;
    if (str == NULL) {
	return bor;
    }
    /// Allocate a new border structure
    int tlv1;
    {
        cgc_size_t tlv28;
        tlv28 = sizeof ( Border );
        int tlv27;
        tlv27 = 0;
        void** tlv26;
        tlv26 = ( void * * ) & bor;
        tlv1 = cgc_allocate(tlv28,tlv27,tlv26);
    }
    if (tlv1 != 0) {
	bor = NULL;
	return bor;
    }
    cgc_skipWhiteSpace(str);
    /// If it does not open with a '{' then it is invalid.
    int tlv2;
    {
        pstring tlv30;
        tlv30 = str;
        char tlv29;
        tlv29 = '{';
        tlv2 = cgc_atChar(tlv30,tlv29);
    }
    if (!tlv2) {
 {
     const char tlv85 [ ] = "!!Failed to locate opening brace\n";
    	cgc_printf(tlv85);
 }
	goto error;
    }
    /// Skip past the curly brace
    int tlv3;
    {
        pstring tlv32;
        tlv32 = str;
        int tlv31;
        tlv31 = 1;
        tlv3 = cgc_skipLength(tlv32,tlv31);
    }
    if (tlv3 == -1) {
 {
     const char tlv86 [ ] = "!!Failed to skip opening brace\n";
    	cgc_printf(tlv86);
 }
	goto error;
    }
    /// Skip any additional whitespace
    cgc_skipWhiteSpace(str);
    /// Save the index
    start = str->index;
    /// This should skip any to either whitespace or a closing '}'
    {
        pstring tlv33;
        tlv33 = str;
        end = cgc_skipAlpha(tlv33);
    }
    if (end == -1) {
 {
     const char tlv87 [ ] = "!!Failed to locate the end of the element id\n";
    	cgc_printf(tlv87);
 }
	goto error;
    }
    /// If start and end are then same then it is an invalid character
    if (start == end) {
	goto error;
    }
    /// Copy the element id from the string
    {
        pstring tlv36;
        tlv36 = str;
        int tlv35;
        tlv35 = start;
        int tlv34;
        tlv34 = end;
        temp = cgc_copyData(tlv36,tlv35,tlv34);
    }
    if (temp == NULL) {
	cgc_printf("!!Copy from @d to @d failed\n", start, end);
	goto error;
    }
    /// If the element id is not "Border" then this is the wrong function
    int tlv4;
    {
        const char* tlv38 = temp;
        const char tlv37 [ ] = "Border";
        tlv4 = cgc_strcmp(tlv38,tlv37);
    }
    if (tlv4 != 0) {
 {
     const char tlv88 [ ] = "!!Element id is not \"Border\"\n";
    	cgc_printf(tlv88);
 }
 {
     void* tlv90;
     tlv90 = temp;
     cgc_size_t tlv89;
     {
         char* tlv115;
          tlv115 = temp;
         tlv89 = cgc_strlen(tlv115) + 1;
     }
    	cgc_deallocate(tlv90,tlv89);
 }
	temp = NULL;
	goto error;
    }
    /// The buffer is no longer needed so free it
    {
        void* tlv13;
        tlv13 = temp;
        cgc_size_t tlv12;
        {
            char* tlv113;
             tlv113 = temp;
            tlv12 = cgc_strlen(tlv113) + 1;
        }
        cgc_deallocate(tlv13,tlv12);
    }
    /// Skip to the end of the element id
    cgc_skipWhiteSpace(str);
    /// If it is not a closing brace then this is improperly formatted.
    int tlv5;
    {
        pstring tlv40;
        tlv40 = str;
        char tlv39;
        tlv39 = '}';
        tlv5 = cgc_atChar(tlv40,tlv39);
    }
    if (!tlv5) {
 {
     const char tlv91 [ ] = "!!Failed to locate initial closing brace\n";
    	cgc_printf(tlv91);
 }
	goto error;
    }
    /// Skip the closing brace as well as any whitespace
    int tlv6;
    {
        pstring tlv42;
        tlv42 = str;
        int tlv41;
        tlv41 = 1;
        tlv6 = cgc_skipLength(tlv42,tlv41);
    }
    if (tlv6 == -1) {
 {
     const char tlv92 [ ] = "!!Failed to skip initial closing brace\n";
    	cgc_printf(tlv92);
 }
	goto error;
    }
    {
        pstring tlv43;
        tlv43 = str;
        start = cgc_skipWhiteSpace(tlv43);
    }
    /// The border data must be a float
    {
        pstring tlv44;
        tlv44 = str;
        end = cgc_skipFloat(tlv44);
    }
    if (start == end) {
 {
     const char tlv93 [ ] = "!!Failed to locate first lat\n";
    	cgc_printf(tlv93);
 }
	goto error;
    }
    if (end == -1) {
 {
     const char tlv94 [ ] = "!!Failed to locate the end of the first latitude float\n";
    	cgc_printf(tlv94);
 }
	goto error;
    }
    {
        pstring tlv47;
        tlv47 = str;
        int tlv46;
        tlv46 = start;
        int tlv45;
        tlv45 = end;
        temp = cgc_copyData(tlv47,tlv46,tlv45);
    }
    if (temp == NULL) {
 {
     const char tlv95 [ ] = "!!Failed to copy first latitude float\n";
    	cgc_printf(tlv95);
 }
	goto error;
    }
    /// Convert the first value
    {
        const char* tlv48 = temp;
        bor->latStart = cgc_atof(tlv48);
    }
    {
        void* tlv15;
        tlv15 = temp;
        cgc_size_t tlv14;
        tlv14 = ( end - start ) + 1;
        cgc_deallocate(tlv15,tlv14);
    }
    /// Skip to the next value
    {
        pstring tlv49;
        tlv49 = str;
        start = cgc_skipWhiteSpace(tlv49);
    }
    {
        pstring tlv50;
        tlv50 = str;
        end = cgc_skipFloat(tlv50);
    }
    if (start == end) {
 {
     const char tlv96 [ ] = "!!Failed to locate first long\n";
    	cgc_printf(tlv96);
 }
	goto error;
    }
    if (start == -1 || end == -1) {
 {
     const char tlv97 [ ] = "!!Failed to locate first longitude float\n";
    	cgc_printf(tlv97);
 }
	goto error;
    }
    {
        pstring tlv53;
        tlv53 = str;
        int tlv52;
        tlv52 = start;
        int tlv51;
        tlv51 = end;
        temp = cgc_copyData(tlv53,tlv52,tlv51);
    }
    if (temp == NULL) {
 {
     const char tlv98 [ ] = "!!Failed to copy first longitude float\n";
    	cgc_printf(tlv98);
 }
	goto error;
    }
    /// Convert the first long
    {
        const char* tlv54 = temp;
        bor->lngStart = cgc_atof(tlv54);
    }
    {
        void* tlv17;
        tlv17 = temp;
        cgc_size_t tlv16;
        tlv16 = ( end - start ) + 1;
        cgc_deallocate(tlv17,tlv16);
    }
    /// Skip to the next value
    {
        pstring tlv55;
        tlv55 = str;
        start = cgc_skipWhiteSpace(tlv55);
    }
    {
        pstring tlv56;
        tlv56 = str;
        end = cgc_skipFloat(tlv56);
    }
    if (start == end) {
 {
     const char tlv99 [ ] = "!!Failed to locate second lat\n";
    	cgc_printf(tlv99);
 }
	goto error;
    }
    if (start == -1 || end == -1) {
 {
     const char tlv100 [ ] = "!!Failed to locate second latitude float\n";
    	cgc_printf(tlv100);
 }
	goto error;
    }
    {
        pstring tlv59;
        tlv59 = str;
        int tlv58;
        tlv58 = start;
        int tlv57;
        tlv57 = end;
        temp = cgc_copyData(tlv59,tlv58,tlv57);
    }
    if (temp == NULL) {
 {
     const char tlv101 [ ] = "!!Failed to copy second latitude float\n";
    	cgc_printf(tlv101);
 }
	goto error;
    }
    /// Convert the second lat
    {
        const char* tlv60 = temp;
        bor->latEnd = cgc_atof(tlv60);
    }
    {
        void* tlv19;
        tlv19 = temp;
        cgc_size_t tlv18;
        tlv18 = ( end - start ) + 1;
        cgc_deallocate(tlv19,tlv18);
    }
    /// Skip to the next value
    {
        pstring tlv61;
        tlv61 = str;
        start = cgc_skipWhiteSpace(tlv61);
    }
    {
        pstring tlv62;
        tlv62 = str;
        end = cgc_skipFloat(tlv62);
    }
    if (start == end) {
 {
     const char tlv102 [ ] = "!!Failed to locate second long\n";
    	cgc_printf(tlv102);
 }
	goto error;
    }
    if (start == -1 || end == -1) {
 {
     const char tlv103 [ ] = "!!Failed to locate second longitude float\n";
    	cgc_printf(tlv103);
 }
	goto error;
    }
    {
        pstring tlv65;
        tlv65 = str;
        int tlv64;
        tlv64 = start;
        int tlv63;
        tlv63 = end;
        temp = cgc_copyData(tlv65,tlv64,tlv63);
    }
    if (temp == NULL) {
 {
     const char tlv104 [ ] = "!!Failed to copy second longitude float\n";
    	cgc_printf(tlv104);
 }
	goto error;
    }
    /// Convert the second long
    {
        const char* tlv66 = temp;
        bor->lngEnd = cgc_atof(tlv66);
    }
    {
        void* tlv21;
        tlv21 = temp;
        cgc_size_t tlv20;
        tlv20 = ( end - start ) + 1;
        cgc_deallocate(tlv21,tlv20);
    }
    cgc_skipWhiteSpace(str);
    /// If this is not an opening curly brace then fail
    int tlv7;
    {
        pstring tlv68;
        tlv68 = str;
        char tlv67;
        tlv67 = '{';
        tlv7 = cgc_atChar(tlv68,tlv67);
    }
    if (!tlv7) {
 {
     const char tlv105 [ ] = "!!Failed to locate the final opening brace\n";
    	cgc_printf(tlv105);
 }
	goto error;
    }
    /// Skip past the brace
    int tlv8;
    {
        pstring tlv70;
        tlv70 = str;
        int tlv69;
        tlv69 = 1;
        tlv8 = cgc_skipLength(tlv70,tlv69);
    }
    if (tlv8 == -1) {
 {
     const char tlv106 [ ] = "!!Failed to skip the final opening brace\n";
    	cgc_printf(tlv106);
 }
	goto error;
    }

    cgc_skipWhiteSpace(str);
    /// If this is not a # indicating the closing brace then fail
    int tlv9;
    {
        pstring tlv72;
        tlv72 = str;
        char tlv71;
        tlv71 = '#';
        tlv9 = cgc_atChar(tlv72,tlv71);
    }
    if (!tlv9) {
 {
     const char tlv107 [ ] = "!!Failed to locate the closing mark\n";
    	cgc_printf(tlv107);
 }
	goto error;
    }
    /// Skip past the # but save the start
    {
        pstring tlv74;
        tlv74 = str;
        int tlv73;
        tlv73 = 1;
        start = cgc_skipLength(tlv74,tlv73);
    }
    if (start == -1) {
 {
     const char tlv108 [ ] = "!!Failed to skip closing mark\n";
    	cgc_printf(tlv108);
 }
	goto error;
    }
    {
        pstring tlv75;
        tlv75 = str;
        end = cgc_skipAlpha(tlv75);
    }
    if (end == -1) {
 {
     const char tlv109 [ ] = "!!Failed to locate the end of the closing element id\n";
    	cgc_printf(tlv109);
 }
	goto error;
    }

    {
        pstring tlv78;
        tlv78 = str;
        int tlv77;
        tlv77 = start;
        int tlv76;
        tlv76 = end;
        temp = cgc_copyData(tlv78,tlv77,tlv76);
    }
    int tlv10;
    {
        const char* tlv80 = temp;
        const char tlv79 [ ] = "Border";
        tlv10 = cgc_strcmp(tlv80,tlv79);
    }
    if (tlv10 != 0) {
	cgc_printf("!!Invalid closing element id: @s\n", temp);
 {
     void* tlv111;
     tlv111 = temp;
     cgc_size_t tlv110;
     {
         char* tlv116;
          tlv116 = temp;
         tlv110 = cgc_strlen(tlv116) + 1;
     }
    	cgc_deallocate(tlv111,tlv110);
 }
	goto error;
    }
    {
        void* tlv23;
        tlv23 = temp;
        cgc_size_t tlv22;
        {
            char* tlv114;
             tlv114 = temp;
            tlv22 = cgc_strlen(tlv114) + 1;
        }
        cgc_deallocate(tlv23,tlv22);
    }
    cgc_skipWhiteSpace(str);
    /// Check the final curly brace
    int tlv11;
    {
        pstring tlv82;
        tlv82 = str;
        char tlv81;
        tlv81 = '}';
        tlv11 = cgc_atChar(tlv82,tlv81);
    }
    if (!tlv11) {
 {
     const char tlv112 [ ] = "!!Failed to locate final closing brace\n";
    	cgc_printf(tlv112);
 }
	goto error;
    }
    /// Skip past the closing brace
    {
        pstring tlv25;
        tlv25 = str;
        int tlv24;
        tlv24 = 1;
        cgc_skipLength(tlv25,tlv24);
    }
    /// Everything succeeded, skip error
    goto fin;

  error:
    {
        void* tlv84;
        tlv84 = bor;
        cgc_size_t tlv83;
        tlv83 = sizeof ( Border );
        cgc_deallocate(tlv84,tlv83);
    }
    bor = NULL;
  fin:
    return bor;
}

void fix_ingred_genericParsers_1_0_0();
void fix_ingred_genericParsers_1_0_1();
void fix_ingred_genericParsers_1_0_2();
void fix_ingred_genericParsers_1_0_6();
void fix_ingred_genericParsers_1_0();
void fix_ingred_genericParsers_1_2_1();
void fix_ingred_genericParsers_1_2();
void fix_ingred_genericParsers_1_5_1();
void fix_ingred_genericParsers_1_5();
void fix_ingred_genericParsers_1_6_6();
void fix_ingred_genericParsers_1_6();
void fix_ingred_genericParsers_1_9_7();
void fix_ingred_genericParsers_1_9();
void fix_ingred_genericParsers_1_11_1();
void fix_ingred_genericParsers_1_11();
void fix_ingred_genericParsers_1_12_7();
void fix_ingred_genericParsers_1_12();
void fix_ingred_genericParsers_1_14_8();
void fix_ingred_genericParsers_1_14();
void fix_ingred_genericParsers_1_16_0();
void fix_ingred_genericParsers_1_16();
void fix_ingred_genericParsers_1_17_1();
void fix_ingred_genericParsers_1_17();
void fix_ingred_genericParsers_1_19_1();
void fix_ingred_genericParsers_1_19();
void fix_ingred_genericParsers_1_20_1();
void fix_ingred_genericParsers_1_20();
void fix_ingred_genericParsers_1_24_7();
void fix_ingred_genericParsers_1_24();
void fix_ingred_genericParsers_1_27_8();
void fix_ingred_genericParsers_1_27();
void fix_ingred_genericParsers_1_33_8();
void fix_ingred_genericParsers_1_33();
void fix_ingred_genericParsers_1_35_1();
void fix_ingred_genericParsers_1_35();
void fix_ingred_genericParsers_1_46_8();
void fix_ingred_genericParsers_1_46();
void fix_ingred_genericParsers_1_48_1();
void fix_ingred_genericParsers_1_48();
void fix_ingred_genericParsers_1_50_1();
void fix_ingred_genericParsers_1_50();
void fix_ingred_genericParsers_1_55_1();
void fix_ingred_genericParsers_1_55();
void fix_ingred_genericParsers_1_60_1();
void fix_ingred_genericParsers_1_60();
void fix_ingred_genericParsers_1();
int cgc_extractPopulation(pstring str)
{
if (fix_ingred_enable){ fix_ingred_genericParsers_1(); };
    char* temp;
     temp = NULL;
    int pop;
    pop = - 1;
    int start;
    start = 0;
    int end;
    end = 0;
    /// These will be used specifically for the name data
    int ps;
    ps = 0;
    int pe;
    pe = 0;
    if (str == NULL) {
	return -1;
    }
    cgc_skipWhiteSpace(str);
    int tlv1;
    {
        pstring tlv20;
        tlv20 = str;
        char tlv19;
        tlv19 = '{';
        tlv1 = cgc_atChar(tlv20,tlv19);
    }
    if (!tlv1) {
 {
     const char tlv54 [ ] = "!!Failed to locate opening brace\n";
    	cgc_printf(tlv54);
 }
	return -1;
    }
    /// Skip past the curly brace
    int tlv2;
    {
        pstring tlv22;
        tlv22 = str;
        int tlv21;
        tlv21 = 1;
        tlv2 = cgc_skipLength(tlv22,tlv21);
    }
    if (tlv2 == -1) {
 {
     const char tlv55 [ ] = "!!Failed to skip opening brace\n";
    	cgc_printf(tlv55);
 }
	return -1;
    }
    /// Skip any additional whitespace
    cgc_skipWhiteSpace(str);
    /// Save the index
    start = str->index;
    /// This should skip any to either whitespace or a closing '}'
    {
        pstring tlv23;
        tlv23 = str;
        end = cgc_skipAlpha(tlv23);
    }
    if (end == -1) {
 {
     const char tlv56 [ ] = "!!Failed to locate the end of the element id\n";
    	cgc_printf(tlv56);
 }
	return -1;
    }
    /// Copy the element id from the string
    {
        pstring tlv26;
        tlv26 = str;
        int tlv25;
        tlv25 = start;
        int tlv24;
        tlv24 = end;
        temp = cgc_copyData(tlv26,tlv25,tlv24);
    }
    if (temp == NULL) {
	cgc_printf("!!Copy from @d to @d failed\n", start, end);
	return -1;
    }
    /// If the element id is not "Population" then this is the wrong function
    int tlv3;
    {
        const char* tlv28 = temp;
        const char tlv27 [ ] = "Population";
        tlv3 = cgc_strcmp(tlv28,tlv27);
    }
    if (tlv3 != 0) {
 {
     const char tlv57 [ ] = "!!Element id is not \"Population\"\n";
    	cgc_printf(tlv57);
 }
 {
     void* tlv59;
     tlv59 = temp;
     cgc_size_t tlv58;
     {
         char* tlv75;
          tlv75 = temp;
         tlv58 = cgc_strlen(tlv75) + 1;
     }
    	cgc_deallocate(tlv59,tlv58);
 }
	temp = NULL;
	return -1;
    }
    /// The buffer is no longer needed so free it
    {
        void* tlv12;
        tlv12 = temp;
        cgc_size_t tlv11;
        {
            char* tlv72;
             tlv72 = temp;
            tlv11 = cgc_strlen(tlv72) + 1;
        }
        cgc_deallocate(tlv12,tlv11);
    }
    /// Skip to the end of the element id
    cgc_skipWhiteSpace(str);
    /// If it is not a closing brace then this is improperly formatted.
    int tlv4;
    {
        pstring tlv30;
        tlv30 = str;
        char tlv29;
        tlv29 = '}';
        tlv4 = cgc_atChar(tlv30,tlv29);
    }
    if (!tlv4) {
 {
     const char tlv60 [ ] = "!!Failed to locate initial closing brace\n";
    	cgc_printf(tlv60);
 }
	return -1;
    }
    /// Skip the closing brace as well as any whitespace
    int tlv5;
    {
        pstring tlv32;
        tlv32 = str;
        int tlv31;
        tlv31 = 1;
        tlv5 = cgc_skipLength(tlv32,tlv31);
    }
    if (tlv5 == -1) {
 {
     const char tlv61 [ ] = "!!Failed to skip initial closing brace\n";
    	cgc_printf(tlv61);
 }
	return -1;
    }
    cgc_skipWhiteSpace(str);
    /// Copy the start index to store the data
    ps = str->index;
    /// The population data must be an integer
    {
        pstring tlv33;
        tlv33 = str;
        pe = cgc_skipInt(tlv33);
    }
    if (pe == -1) {
 {
     const char tlv62 [ ] = "!!Failed to locate the end of the population data\n";
    	cgc_printf(tlv62);
 }
	return end;
    }
    /// The rest of this code is a check to ensure proper formatting except for the copy data
    cgc_skipWhiteSpace(str);
    /// If this is not an opening curly brace then fail
    int tlv6;
    {
        pstring tlv35;
        tlv35 = str;
        char tlv34;
        tlv34 = '{';
        tlv6 = cgc_atChar(tlv35,tlv34);
    }
    if (!tlv6) {
 {
     const char tlv63 [ ] = "!!Failed to locate the final opening brace\n";
    	cgc_printf(tlv63);
 }
	return -1;
    }
    /// Skip past the brace
    int tlv7;
    {
        pstring tlv37;
        tlv37 = str;
        int tlv36;
        tlv36 = 1;
        tlv7 = cgc_skipLength(tlv37,tlv36);
    }
    if (tlv7 == -1) {
 {
     const char tlv64 [ ] = "!!Failed to skip the final opening brace\n";
    	cgc_printf(tlv64);
 }
	return -1;
    }

    cgc_skipWhiteSpace(str);
    /// If this is not a # indicating the closing brace then fail
    int tlv8;
    {
        pstring tlv39;
        tlv39 = str;
        char tlv38;
        tlv38 = '#';
        tlv8 = cgc_atChar(tlv39,tlv38);
    }
    if (!tlv8) {
 {
     const char tlv65 [ ] = "!!Failed to locate the closing mark\n";
    	cgc_printf(tlv65);
 }
	return -1;
    }
    /// Skip past the # but save the start
    {
        pstring tlv41;
        tlv41 = str;
        int tlv40;
        tlv40 = 1;
        start = cgc_skipLength(tlv41,tlv40);
    }
    if (start == -1) {
 {
     const char tlv66 [ ] = "!!Failed to skip closing mark\n";
    	cgc_printf(tlv66);
 }
	return start;
    }
    {
        pstring tlv42;
        tlv42 = str;
        end = cgc_skipAlpha(tlv42);
    }
    if (end == -1) {
 {
     const char tlv67 [ ] = "!!Failed to locate the end of the closing element id\n";
    	cgc_printf(tlv67);
 }
	return end;
    }

    {
        pstring tlv45;
        tlv45 = str;
        int tlv44;
        tlv44 = start;
        int tlv43;
        tlv43 = end;
        temp = cgc_copyData(tlv45,tlv44,tlv43);
    }
    int tlv9;
    {
        const char* tlv47 = temp;
        const char tlv46 [ ] = "Population";
        tlv9 = cgc_strcmp(tlv47,tlv46);
    }
    if (tlv9 != 0) {
	cgc_printf("!!Invalid closing element id: @s\n", temp);
 {
     void* tlv69;
     tlv69 = temp;
     cgc_size_t tlv68;
     {
         char* tlv76;
          tlv76 = temp;
         tlv68 = cgc_strlen(tlv76) + 1;
     }
    	cgc_deallocate(tlv69,tlv68);
 }
	return -1;
    }
    {
        void* tlv14;
        tlv14 = temp;
        cgc_size_t tlv13;
        {
            char* tlv73;
             tlv73 = temp;
            tlv13 = cgc_strlen(tlv73) + 1;
        }
        cgc_deallocate(tlv14,tlv13);
    }
    cgc_skipWhiteSpace(str);
    /// Check the final curly brace
    int tlv10;
    {
        pstring tlv49;
        tlv49 = str;
        char tlv48;
        tlv48 = '}';
        tlv10 = cgc_atChar(tlv49,tlv48);
    }
    if (!tlv10) {
 {
     const char tlv70 [ ] = "!!Failed to locate final closing brace\n";
    	cgc_printf(tlv70);
 }
	return -1;
    }
    /// Skip past the closing brace
    {
        pstring tlv16;
        tlv16 = str;
        int tlv15;
        tlv15 = 1;
        cgc_skipLength(tlv16,tlv15);
    }

    /// Copy the name element data
    {
        pstring tlv52;
        tlv52 = str;
        int tlv51;
        tlv51 = ps;
        int tlv50;
        tlv50 = pe;
        temp = cgc_copyData(tlv52,tlv51,tlv50);
    }
    if (temp == NULL) {
 {
     const char tlv71 [ ] = "!!Failed to copy population data\n";
    	cgc_printf(tlv71);
 }
	return -1;
    }
    {
        const char* tlv53 = temp;
        pop = cgc_atoi(tlv53);
    }
    {
        void* tlv18;
        tlv18 = temp;
        cgc_size_t tlv17;
        {
            char* tlv74;
             tlv74 = temp;
            tlv17 = cgc_strlen(tlv74) + 1;
        }
        cgc_deallocate(tlv18,tlv17);
    }
    return pop;
}

void fix_ingred_genericParsers_2_0_0();
void fix_ingred_genericParsers_2_0_2();
void fix_ingred_genericParsers_2_0_6();
void fix_ingred_genericParsers_2_0();
void fix_ingred_genericParsers_2_2_1();
void fix_ingred_genericParsers_2_2();
void fix_ingred_genericParsers_2_5_1();
void fix_ingred_genericParsers_2_5();
void fix_ingred_genericParsers_2_6_6();
void fix_ingred_genericParsers_2_6_7();
void fix_ingred_genericParsers_2_6();
void fix_ingred_genericParsers_2_9_7();
void fix_ingred_genericParsers_2_9();
void fix_ingred_genericParsers_2_11_1();
void fix_ingred_genericParsers_2_11();
void fix_ingred_genericParsers_2_12_7();
void fix_ingred_genericParsers_2_12();
void fix_ingred_genericParsers_2_14_8();
void fix_ingred_genericParsers_2_14();
void fix_ingred_genericParsers_2_16_0();
void fix_ingred_genericParsers_2_16();
void fix_ingred_genericParsers_2_17_1();
void fix_ingred_genericParsers_2_17();
void fix_ingred_genericParsers_2_19_1();
void fix_ingred_genericParsers_2_19();
void fix_ingred_genericParsers_2_20_1();
void fix_ingred_genericParsers_2_20();
void fix_ingred_genericParsers_2_24_7();
void fix_ingred_genericParsers_2_24();
void fix_ingred_genericParsers_2_27_8();
void fix_ingred_genericParsers_2_27();
void fix_ingred_genericParsers_2_33_8();
void fix_ingred_genericParsers_2_33();
void fix_ingred_genericParsers_2_35_1();
void fix_ingred_genericParsers_2_35();
void fix_ingred_genericParsers_2_46_8();
void fix_ingred_genericParsers_2_46();
void fix_ingred_genericParsers_2_48_1();
void fix_ingred_genericParsers_2_48();
void fix_ingred_genericParsers_2_50_1();
void fix_ingred_genericParsers_2_50();
void fix_ingred_genericParsers_2_55_1();
void fix_ingred_genericParsers_2_55();
void fix_ingred_genericParsers_2();
char *cgc_extractName(pstring str)
{
if (fix_ingred_enable){ fix_ingred_genericParsers_2(); };
    char* temp;
     temp = NULL;
    char* name;
     name = NULL;
    int start;
    start = 0;
    int end;
    end = 0;
    /// These will be used specifically for the name data
    int ns;
    ns = 0;
    int ne;
    ne = 0;
    if (str == NULL) {
	return name;
    }
    cgc_skipWhiteSpace(str);
    int tlv1;
    {
        pstring tlv18;
        tlv18 = str;
        char tlv17;
        tlv17 = '{';
        tlv1 = cgc_atChar(tlv18,tlv17);
    }
    if (!tlv1) {
 {
     const char tlv51 [ ] = "!!Failed to locate opening brace\n";
    	cgc_printf(tlv51);
 }
	return name;
    }
    /// Skip past the curly brace
    int tlv2;
    {
        pstring tlv20;
        tlv20 = str;
        int tlv19;
        tlv19 = 1;
        tlv2 = cgc_skipLength(tlv20,tlv19);
    }
    if (tlv2 == -1) {
 {
     const char tlv52 [ ] = "!!Failed to skip opening brace\n";
    	cgc_printf(tlv52);
 }
	return name;
    }
    /// Skip any additional whitespace
    cgc_skipWhiteSpace(str);
    /// Save the index
    start = str->index;
    /// This should skip any to either whitespace or a closing '}'
    {
        pstring tlv21;
        tlv21 = str;
        end = cgc_skipAlpha(tlv21);
    }
    if (end == -1) {
 {
     const char tlv53 [ ] = "!!Failed to locate the end of the element id\n";
    	cgc_printf(tlv53);
 }
	return NULL;
    }
    /// Copy the element id from the string
    {
        pstring tlv24;
        tlv24 = str;
        int tlv23;
        tlv23 = start;
        int tlv22;
        tlv22 = end;
        temp = cgc_copyData(tlv24,tlv23,tlv22);
    }
    if (temp == NULL) {
	cgc_printf("!!Copy from @d to @d failed\n", start, end);
	return NULL;
    }
    /// If the element id is not "Name" then this is the wrong function
    int tlv3;
    {
        const char* tlv26 = temp;
        const char tlv25 [ ] = "Name";
        tlv3 = cgc_strcmp(tlv26,tlv25);
    }
    if (tlv3 != 0) {
 {
     const char tlv54 [ ] = "!!Element id is not \"Name\"\n";
    	cgc_printf(tlv54);
 }
 {
     void* tlv56;
     tlv56 = temp;
     cgc_size_t tlv55;
     {
         char* tlv70;
          tlv70 = temp;
         tlv55 = cgc_strlen(tlv70) + 1;
     }
    	cgc_deallocate(tlv56,tlv55);
 }
	temp = NULL;
	return NULL;
    }
    /// The buffer is no longer needed so free it
    {
        void* tlv12;
        tlv12 = temp;
        cgc_size_t tlv11;
        {
            char* tlv68;
             tlv68 = temp;
            tlv11 = cgc_strlen(tlv68) + 1;
        }
        cgc_deallocate(tlv12,tlv11);
    }
    /// Skip to the end of the element id
    cgc_skipWhiteSpace(str);
    /// If it is not a closing brace then this is improperly formatted.
    int tlv4;
    {
        pstring tlv28;
        tlv28 = str;
        char tlv27;
        tlv27 = '}';
        tlv4 = cgc_atChar(tlv28,tlv27);
    }
    if (!tlv4) {
 {
     const char tlv57 [ ] = "!!Failed to locate initial closing brace\n";
    	cgc_printf(tlv57);
 }
	return NULL;
    }
    /// Skip the closing brace as well as any whitespace
    int tlv5;
    {
        pstring tlv30;
        tlv30 = str;
        int tlv29;
        tlv29 = 1;
        tlv5 = cgc_skipLength(tlv30,tlv29);
    }
    if (tlv5 == -1) {
 {
     const char tlv58 [ ] = "!!Failed to skip initial closing brace\n";
    	cgc_printf(tlv58);
 }
	return NULL;
    }
    cgc_skipWhiteSpace(str);
    /// Copy the start index to store the data
    ns = str->index;
    /// The name data must be alphanumeric
    {
        pstring tlv31;
        tlv31 = str;
        ne = cgc_skipToNonAlphaNum(tlv31);
    }
    if (ne == -1) {
 {
     const char tlv59 [ ] = "!!Failed to locate the end of the name data\n";
    	cgc_printf(tlv59);
 }
	return NULL;
    }
    /// The rest of this code is a check to ensure proper formatting except for the copy data
    cgc_skipWhiteSpace(str);
    /// If this is not an opening curly brace then fail
    int tlv6;
    {
        pstring tlv33;
        tlv33 = str;
        char tlv32;
        tlv32 = '{';
        tlv6 = cgc_atChar(tlv33,tlv32);
    }
    if (!tlv6) {
 {
     const char tlv60 [ ] = "!!Failed to locate the final opening brace\n";
    	cgc_printf(tlv60);
 }
	return NULL;
    }
    /// Skip past the brace
    int tlv7;
    {
        pstring tlv35;
        tlv35 = str;
        int tlv34;
        tlv34 = 1;
        tlv7 = cgc_skipLength(tlv35,tlv34);
    }
    if (tlv7 == -1) {
 {
     const char tlv61 [ ] = "!!Failed to skip the final opening brace\n";
    	cgc_printf(tlv61);
 }
	return NULL;
    }

    cgc_skipWhiteSpace(str);
    /// If this is not a # indicating the closing brace then fail
    int tlv8;
    {
        pstring tlv37;
        tlv37 = str;
        char tlv36;
        tlv36 = '#';
        tlv8 = cgc_atChar(tlv37,tlv36);
    }
    if (!tlv8) {
 {
     const char tlv62 [ ] = "!!Failed to locate the closing mark\n";
    	cgc_printf(tlv62);
 }
	return NULL;
    }
    /// Skip past the # but save the start
    {
        pstring tlv39;
        tlv39 = str;
        int tlv38;
        tlv38 = 1;
        start = cgc_skipLength(tlv39,tlv38);
    }
    if (start == -1) {
 {
     const char tlv63 [ ] = "!!Failed to skip closing mark\n";
    	cgc_printf(tlv63);
 }
	return NULL;
    }
    {
        pstring tlv40;
        tlv40 = str;
        end = cgc_skipAlpha(tlv40);
    }
    if (end == -1) {
 {
     const char tlv64 [ ] = "!!Failed to locate the end of the closing element id\n";
    	cgc_printf(tlv64);
 }
	return NULL;
    }

    {
        pstring tlv43;
        tlv43 = str;
        int tlv42;
        tlv42 = start;
        int tlv41;
        tlv41 = end;
        temp = cgc_copyData(tlv43,tlv42,tlv41);
    }
    int tlv9;
    {
        const char* tlv45 = temp;
        const char tlv44 [ ] = "Name";
        tlv9 = cgc_strcmp(tlv45,tlv44);
    }
    if (tlv9 != 0) {
	cgc_printf("!!Invalid closing element id: @s\n", temp);
 {
     void* tlv66;
     tlv66 = temp;
     cgc_size_t tlv65;
     {
         char* tlv71;
          tlv71 = temp;
         tlv65 = cgc_strlen(tlv71) + 1;
     }
    	cgc_deallocate(tlv66,tlv65);
 }
	return NULL;
    }
    {
        void* tlv14;
        tlv14 = temp;
        cgc_size_t tlv13;
        {
            char* tlv69;
             tlv69 = temp;
            tlv13 = cgc_strlen(tlv69) + 1;
        }
        cgc_deallocate(tlv14,tlv13);
    }
    cgc_skipWhiteSpace(str);
    /// Check the final curly brace
    int tlv10;
    {
        pstring tlv47;
        tlv47 = str;
        char tlv46;
        tlv46 = '}';
        tlv10 = cgc_atChar(tlv47,tlv46);
    }
    if (!tlv10) {
 {
     const char tlv67 [ ] = "!!Failed to locate final closing brace\n";
    	cgc_printf(tlv67);
 }
	return NULL;
    }
    /// Skip past the closing brace
    {
        pstring tlv16;
        tlv16 = str;
        int tlv15;
        tlv15 = 1;
        cgc_skipLength(tlv16,tlv15);
    }

    /// Copy the name element data
    {
        pstring tlv50;
        tlv50 = str;
        int tlv49;
        tlv49 = ns;
        int tlv48;
        tlv48 = ne;
        name = cgc_copyData(tlv50,tlv49,tlv48);
    }
    return name;
}

void fix_ingred_genericParsers_0_0_0(){
string str_ref;
    bzero(&str_ref,1*sizeof(string));
pstring str = &str_ref;
    {char * temp; temp = (char *)(NULL); }
    {int start; start = (int)(NULL); }
    {int end; end = (int)(NULL); }
    {int tlv1; tlv1 = (int)(NULL); }
    {int tlv2; tlv2 = (int)(NULL); }
    {int tlv3; tlv3 = (int)(NULL); }
    {int tlv4; tlv4 = (int)(NULL); }
    {int tlv5; tlv5 = (int)(NULL); }
    {int tlv6; tlv6 = (int)(NULL); }
    {int tlv7; tlv7 = (int)(NULL); }
    {int tlv8; tlv8 = (int)(NULL); }
    {int tlv9; tlv9 = (int)(NULL); }
    {int tlv10; tlv10 = (int)(NULL); }
    {int tlv11; tlv11 = (int)(NULL); }
    {cgc_size_t tlv28; tlv28 = (cgc_size_t)(NULL); }
    {int tlv27; tlv27 = (int)(NULL); }
    {char tlv29; tlv29 = (char)(NULL); }
    {int tlv31; tlv31 = (int)(NULL); }
    {int tlv35; tlv35 = (int)(NULL); }
    {int tlv34; tlv34 = (int)(NULL); }
    {void * tlv13; tlv13 = (void *)(NULL); }
    {cgc_size_t tlv12; tlv12 = (cgc_size_t)(NULL); }
    {char tlv39; tlv39 = (char)(NULL); }
    {int tlv41; tlv41 = (int)(NULL); }
    {int tlv46; tlv46 = (int)(NULL); }
    {int tlv45; tlv45 = (int)(NULL); }
    {void * tlv15; tlv15 = (void *)(NULL); }
    {cgc_size_t tlv14; tlv14 = (cgc_size_t)(NULL); }
    {int tlv52; tlv52 = (int)(NULL); }
    {int tlv51; tlv51 = (int)(NULL); }
    {void * tlv17; tlv17 = (void *)(NULL); }
    {cgc_size_t tlv16; tlv16 = (cgc_size_t)(NULL); }
    {int tlv58; tlv58 = (int)(NULL); }
    {int tlv57; tlv57 = (int)(NULL); }
    {void * tlv19; tlv19 = (void *)(NULL); }
    {cgc_size_t tlv18; tlv18 = (cgc_size_t)(NULL); }
    {int tlv64; tlv64 = (int)(NULL); }
    {int tlv63; tlv63 = (int)(NULL); }
    {void * tlv21; tlv21 = (void *)(NULL); }
    {cgc_size_t tlv20; tlv20 = (cgc_size_t)(NULL); }
    {char tlv67; tlv67 = (char)(NULL); }
    {int tlv69; tlv69 = (int)(NULL); }
    {char tlv71; tlv71 = (char)(NULL); }
    {int tlv73; tlv73 = (int)(NULL); }
    {int tlv77; tlv77 = (int)(NULL); }
    {int tlv76; tlv76 = (int)(NULL); }
    {void * tlv23; tlv23 = (void *)(NULL); }
    {cgc_size_t tlv22; tlv22 = (cgc_size_t)(NULL); }
    {char tlv81; tlv81 = (char)(NULL); }
    {int tlv24; tlv24 = (int)(NULL); }
    {void * tlv84; tlv84 = (void *)(NULL); }
    {cgc_size_t tlv83; tlv83 = (cgc_size_t)(NULL); }
    {char * tlv113; tlv113 = (char *)(NULL); }
    {char * tlv114; tlv114 = (char *)(NULL); }
    {void * tlv90; tlv90 = (void *)(NULL); }
    {cgc_size_t tlv89; tlv89 = (cgc_size_t)(NULL); }
    {void * tlv111; tlv111 = (void *)(NULL); }
    {cgc_size_t tlv110; tlv110 = (cgc_size_t)(NULL); }
    {char * tlv115; tlv115 = (char *)(NULL); }
    {char * tlv116; tlv116 = (char *)(NULL); }
}
void fix_ingred_genericParsers_0_0_2(){
string str_ref;
    bzero(&str_ref,1*sizeof(string));
pstring str = &str_ref;
    {char * temp; temp = (char *)(0); }
    {int start; start = (int)(0); }
    {int end; end = (int)(0); }
    {int tlv1; tlv1 = (int)(0); }
    {int tlv2; tlv2 = (int)(0); }
    {int tlv3; tlv3 = (int)(0); }
    {int tlv4; tlv4 = (int)(0); }
    {int tlv5; tlv5 = (int)(0); }
    {int tlv6; tlv6 = (int)(0); }
    {int tlv7; tlv7 = (int)(0); }
    {int tlv8; tlv8 = (int)(0); }
    {int tlv9; tlv9 = (int)(0); }
    {int tlv10; tlv10 = (int)(0); }
    {int tlv11; tlv11 = (int)(0); }
    {cgc_size_t tlv28; tlv28 = (cgc_size_t)(0); }
    {int tlv27; tlv27 = (int)(0); }
    {char tlv29; tlv29 = (char)(0); }
    {int tlv31; tlv31 = (int)(0); }
    {int tlv35; tlv35 = (int)(0); }
    {int tlv34; tlv34 = (int)(0); }
    {void * tlv13; tlv13 = (void *)(0); }
    {cgc_size_t tlv12; tlv12 = (cgc_size_t)(0); }
    {char tlv39; tlv39 = (char)(0); }
    {int tlv41; tlv41 = (int)(0); }
    {int tlv46; tlv46 = (int)(0); }
    {int tlv45; tlv45 = (int)(0); }
    {void * tlv15; tlv15 = (void *)(0); }
    {cgc_size_t tlv14; tlv14 = (cgc_size_t)(0); }
    {int tlv52; tlv52 = (int)(0); }
    {int tlv51; tlv51 = (int)(0); }
    {void * tlv17; tlv17 = (void *)(0); }
    {cgc_size_t tlv16; tlv16 = (cgc_size_t)(0); }
    {int tlv58; tlv58 = (int)(0); }
    {int tlv57; tlv57 = (int)(0); }
    {void * tlv19; tlv19 = (void *)(0); }
    {cgc_size_t tlv18; tlv18 = (cgc_size_t)(0); }
    {int tlv64; tlv64 = (int)(0); }
    {int tlv63; tlv63 = (int)(0); }
    {void * tlv21; tlv21 = (void *)(0); }
    {cgc_size_t tlv20; tlv20 = (cgc_size_t)(0); }
    {char tlv67; tlv67 = (char)(0); }
    {int tlv69; tlv69 = (int)(0); }
    {char tlv71; tlv71 = (char)(0); }
    {int tlv73; tlv73 = (int)(0); }
    {int tlv77; tlv77 = (int)(0); }
    {int tlv76; tlv76 = (int)(0); }
    {void * tlv23; tlv23 = (void *)(0); }
    {cgc_size_t tlv22; tlv22 = (cgc_size_t)(0); }
    {char tlv81; tlv81 = (char)(0); }
    {int tlv24; tlv24 = (int)(0); }
    {void * tlv84; tlv84 = (void *)(0); }
    {cgc_size_t tlv83; tlv83 = (cgc_size_t)(0); }
    {char * tlv113; tlv113 = (char *)(0); }
    {char * tlv114; tlv114 = (char *)(0); }
    {void * tlv90; tlv90 = (void *)(0); }
    {cgc_size_t tlv89; tlv89 = (cgc_size_t)(0); }
    {void * tlv111; tlv111 = (void *)(0); }
    {cgc_size_t tlv110; tlv110 = (cgc_size_t)(0); }
    {char * tlv115; tlv115 = (char *)(0); }
    {char * tlv116; tlv116 = (char *)(0); }
}
void fix_ingred_genericParsers_0_0_4(){
string str_ref;
    bzero(&str_ref,1*sizeof(string));
pstring str = &str_ref;
    {char * temp; temp = (char *)(str -> index); }
    {int start; start = (int)(str -> index); }
    {int end; end = (int)(str -> index); }
    {int tlv1; tlv1 = (int)(str -> index); }
    {int tlv2; tlv2 = (int)(str -> index); }
    {int tlv3; tlv3 = (int)(str -> index); }
    {int tlv4; tlv4 = (int)(str -> index); }
    {int tlv5; tlv5 = (int)(str -> index); }
    {int tlv6; tlv6 = (int)(str -> index); }
    {int tlv7; tlv7 = (int)(str -> index); }
    {int tlv8; tlv8 = (int)(str -> index); }
    {int tlv9; tlv9 = (int)(str -> index); }
    {int tlv10; tlv10 = (int)(str -> index); }
    {int tlv11; tlv11 = (int)(str -> index); }
    {cgc_size_t tlv28; tlv28 = (cgc_size_t)(str -> index); }
    {int tlv27; tlv27 = (int)(str -> index); }
    {char tlv29; tlv29 = (char)(str -> index); }
    {int tlv31; tlv31 = (int)(str -> index); }
    {int tlv35; tlv35 = (int)(str -> index); }
    {int tlv34; tlv34 = (int)(str -> index); }
    {void * tlv13; tlv13 = (void *)(str -> index); }
    {cgc_size_t tlv12; tlv12 = (cgc_size_t)(str -> index); }
    {char tlv39; tlv39 = (char)(str -> index); }
    {int tlv41; tlv41 = (int)(str -> index); }
    {int tlv46; tlv46 = (int)(str -> index); }
    {int tlv45; tlv45 = (int)(str -> index); }
    {void * tlv15; tlv15 = (void *)(str -> index); }
    {cgc_size_t tlv14; tlv14 = (cgc_size_t)(str -> index); }
    {int tlv52; tlv52 = (int)(str -> index); }
    {int tlv51; tlv51 = (int)(str -> index); }
    {void * tlv17; tlv17 = (void *)(str -> index); }
    {cgc_size_t tlv16; tlv16 = (cgc_size_t)(str -> index); }
    {int tlv58; tlv58 = (int)(str -> index); }
    {int tlv57; tlv57 = (int)(str -> index); }
    {void * tlv19; tlv19 = (void *)(str -> index); }
    {cgc_size_t tlv18; tlv18 = (cgc_size_t)(str -> index); }
    {int tlv64; tlv64 = (int)(str -> index); }
    {int tlv63; tlv63 = (int)(str -> index); }
    {void * tlv21; tlv21 = (void *)(str -> index); }
    {cgc_size_t tlv20; tlv20 = (cgc_size_t)(str -> index); }
    {char tlv67; tlv67 = (char)(str -> index); }
    {int tlv69; tlv69 = (int)(str -> index); }
    {char tlv71; tlv71 = (char)(str -> index); }
    {int tlv73; tlv73 = (int)(str -> index); }
    {int tlv77; tlv77 = (int)(str -> index); }
    {int tlv76; tlv76 = (int)(str -> index); }
    {void * tlv23; tlv23 = (void *)(str -> index); }
    {cgc_size_t tlv22; tlv22 = (cgc_size_t)(str -> index); }
    {char tlv81; tlv81 = (char)(str -> index); }
    {int tlv24; tlv24 = (int)(str -> index); }
    {void * tlv84; tlv84 = (void *)(str -> index); }
    {cgc_size_t tlv83; tlv83 = (cgc_size_t)(str -> index); }
    {char * tlv113; tlv113 = (char *)(str -> index); }
    {char * tlv114; tlv114 = (char *)(str -> index); }
    {void * tlv90; tlv90 = (void *)(str -> index); }
    {cgc_size_t tlv89; tlv89 = (cgc_size_t)(str -> index); }
    {void * tlv111; tlv111 = (void *)(str -> index); }
    {cgc_size_t tlv110; tlv110 = (cgc_size_t)(str -> index); }
    {char * tlv115; tlv115 = (char *)(str -> index); }
    {char * tlv116; tlv116 = (char *)(str -> index); }
}
void fix_ingred_genericParsers_0_0(){
fix_ingred_genericParsers_0_0_0();
fix_ingred_genericParsers_0_0_2();
fix_ingred_genericParsers_0_0_4();
}
void fix_ingred_genericParsers_0_2_0(){
    {char * temp; temp = (char *)(sizeof ( Border )); }
    {int start; start = (int)(sizeof ( Border )); }
    {int end; end = (int)(sizeof ( Border )); }
    {int tlv1; tlv1 = (int)(sizeof ( Border )); }
    {int tlv2; tlv2 = (int)(sizeof ( Border )); }
    {int tlv3; tlv3 = (int)(sizeof ( Border )); }
    {int tlv4; tlv4 = (int)(sizeof ( Border )); }
    {int tlv5; tlv5 = (int)(sizeof ( Border )); }
    {int tlv6; tlv6 = (int)(sizeof ( Border )); }
    {int tlv7; tlv7 = (int)(sizeof ( Border )); }
    {int tlv8; tlv8 = (int)(sizeof ( Border )); }
    {int tlv9; tlv9 = (int)(sizeof ( Border )); }
    {int tlv10; tlv10 = (int)(sizeof ( Border )); }
    {int tlv11; tlv11 = (int)(sizeof ( Border )); }
    {cgc_size_t tlv28; tlv28 = (cgc_size_t)(sizeof ( Border )); }
    {int tlv27; tlv27 = (int)(sizeof ( Border )); }
    {char tlv29; tlv29 = (char)(sizeof ( Border )); }
    {int tlv31; tlv31 = (int)(sizeof ( Border )); }
    {int tlv35; tlv35 = (int)(sizeof ( Border )); }
    {int tlv34; tlv34 = (int)(sizeof ( Border )); }
    {void * tlv13; tlv13 = (void *)(sizeof ( Border )); }
    {cgc_size_t tlv12; tlv12 = (cgc_size_t)(sizeof ( Border )); }
    {char tlv39; tlv39 = (char)(sizeof ( Border )); }
    {int tlv41; tlv41 = (int)(sizeof ( Border )); }
    {int tlv46; tlv46 = (int)(sizeof ( Border )); }
    {int tlv45; tlv45 = (int)(sizeof ( Border )); }
    {void * tlv15; tlv15 = (void *)(sizeof ( Border )); }
    {cgc_size_t tlv14; tlv14 = (cgc_size_t)(sizeof ( Border )); }
    {int tlv52; tlv52 = (int)(sizeof ( Border )); }
    {int tlv51; tlv51 = (int)(sizeof ( Border )); }
    {void * tlv17; tlv17 = (void *)(sizeof ( Border )); }
    {cgc_size_t tlv16; tlv16 = (cgc_size_t)(sizeof ( Border )); }
    {int tlv58; tlv58 = (int)(sizeof ( Border )); }
    {int tlv57; tlv57 = (int)(sizeof ( Border )); }
    {void * tlv19; tlv19 = (void *)(sizeof ( Border )); }
    {cgc_size_t tlv18; tlv18 = (cgc_size_t)(sizeof ( Border )); }
    {int tlv64; tlv64 = (int)(sizeof ( Border )); }
    {int tlv63; tlv63 = (int)(sizeof ( Border )); }
    {void * tlv21; tlv21 = (void *)(sizeof ( Border )); }
    {cgc_size_t tlv20; tlv20 = (cgc_size_t)(sizeof ( Border )); }
    {char tlv67; tlv67 = (char)(sizeof ( Border )); }
    {int tlv69; tlv69 = (int)(sizeof ( Border )); }
    {char tlv71; tlv71 = (char)(sizeof ( Border )); }
    {int tlv73; tlv73 = (int)(sizeof ( Border )); }
    {int tlv77; tlv77 = (int)(sizeof ( Border )); }
    {int tlv76; tlv76 = (int)(sizeof ( Border )); }
    {void * tlv23; tlv23 = (void *)(sizeof ( Border )); }
    {cgc_size_t tlv22; tlv22 = (cgc_size_t)(sizeof ( Border )); }
    {char tlv81; tlv81 = (char)(sizeof ( Border )); }
    {int tlv24; tlv24 = (int)(sizeof ( Border )); }
    {void * tlv84; tlv84 = (void *)(sizeof ( Border )); }
    {cgc_size_t tlv83; tlv83 = (cgc_size_t)(sizeof ( Border )); }
    {char * tlv113; tlv113 = (char *)(sizeof ( Border )); }
    {char * tlv114; tlv114 = (char *)(sizeof ( Border )); }
    {void * tlv90; tlv90 = (void *)(sizeof ( Border )); }
    {cgc_size_t tlv89; tlv89 = (cgc_size_t)(sizeof ( Border )); }
    {void * tlv111; tlv111 = (void *)(sizeof ( Border )); }
    {cgc_size_t tlv110; tlv110 = (cgc_size_t)(sizeof ( Border )); }
    {char * tlv115; tlv115 = (char *)(sizeof ( Border )); }
    {char * tlv116; tlv116 = (char *)(sizeof ( Border )); }
}
void fix_ingred_genericParsers_0_2(){
fix_ingred_genericParsers_0_2_0();
}
void fix_ingred_genericParsers_0_3_5(){
int tlv1;
    bzero(&tlv1,sizeof(int));
    {char * temp; temp = (char *)(tlv1); }
    {int start; start = (int)(tlv1); }
    {int end; end = (int)(tlv1); }
    {int tlv2; tlv2 = (int)(tlv1); }
    {int tlv3; tlv3 = (int)(tlv1); }
    {int tlv4; tlv4 = (int)(tlv1); }
    {int tlv5; tlv5 = (int)(tlv1); }
    {int tlv6; tlv6 = (int)(tlv1); }
    {int tlv7; tlv7 = (int)(tlv1); }
    {int tlv8; tlv8 = (int)(tlv1); }
    {int tlv9; tlv9 = (int)(tlv1); }
    {int tlv10; tlv10 = (int)(tlv1); }
    {int tlv11; tlv11 = (int)(tlv1); }
    {cgc_size_t tlv28; tlv28 = (cgc_size_t)(tlv1); }
    {int tlv27; tlv27 = (int)(tlv1); }
    {char tlv29; tlv29 = (char)(tlv1); }
    {int tlv31; tlv31 = (int)(tlv1); }
    {int tlv35; tlv35 = (int)(tlv1); }
    {int tlv34; tlv34 = (int)(tlv1); }
    {void * tlv13; tlv13 = (void *)(tlv1); }
    {cgc_size_t tlv12; tlv12 = (cgc_size_t)(tlv1); }
    {char tlv39; tlv39 = (char)(tlv1); }
    {int tlv41; tlv41 = (int)(tlv1); }
    {int tlv46; tlv46 = (int)(tlv1); }
    {int tlv45; tlv45 = (int)(tlv1); }
    {void * tlv15; tlv15 = (void *)(tlv1); }
    {cgc_size_t tlv14; tlv14 = (cgc_size_t)(tlv1); }
    {int tlv52; tlv52 = (int)(tlv1); }
    {int tlv51; tlv51 = (int)(tlv1); }
    {void * tlv17; tlv17 = (void *)(tlv1); }
    {cgc_size_t tlv16; tlv16 = (cgc_size_t)(tlv1); }
    {int tlv58; tlv58 = (int)(tlv1); }
    {int tlv57; tlv57 = (int)(tlv1); }
    {void * tlv19; tlv19 = (void *)(tlv1); }
    {cgc_size_t tlv18; tlv18 = (cgc_size_t)(tlv1); }
    {int tlv64; tlv64 = (int)(tlv1); }
    {int tlv63; tlv63 = (int)(tlv1); }
    {void * tlv21; tlv21 = (void *)(tlv1); }
    {cgc_size_t tlv20; tlv20 = (cgc_size_t)(tlv1); }
    {char tlv67; tlv67 = (char)(tlv1); }
    {int tlv69; tlv69 = (int)(tlv1); }
    {char tlv71; tlv71 = (char)(tlv1); }
    {int tlv73; tlv73 = (int)(tlv1); }
    {int tlv77; tlv77 = (int)(tlv1); }
    {int tlv76; tlv76 = (int)(tlv1); }
    {void * tlv23; tlv23 = (void *)(tlv1); }
    {cgc_size_t tlv22; tlv22 = (cgc_size_t)(tlv1); }
    {char tlv81; tlv81 = (char)(tlv1); }
    {int tlv24; tlv24 = (int)(tlv1); }
    {void * tlv84; tlv84 = (void *)(tlv1); }
    {cgc_size_t tlv83; tlv83 = (cgc_size_t)(tlv1); }
    {char * tlv113; tlv113 = (char *)(tlv1); }
    {char * tlv114; tlv114 = (char *)(tlv1); }
    {void * tlv90; tlv90 = (void *)(tlv1); }
    {cgc_size_t tlv89; tlv89 = (cgc_size_t)(tlv1); }
    {void * tlv111; tlv111 = (void *)(tlv1); }
    {cgc_size_t tlv110; tlv110 = (cgc_size_t)(tlv1); }
    {char * tlv115; tlv115 = (char *)(tlv1); }
    {char * tlv116; tlv116 = (char *)(tlv1); }
}
void fix_ingred_genericParsers_0_3(){
fix_ingred_genericParsers_0_3_5();
}
void fix_ingred_genericParsers_0_4_1(){
    {char * temp; temp = (char *)('{'); }
    {int start; start = (int)('{'); }
    {int end; end = (int)('{'); }
    {int tlv1; tlv1 = (int)('{'); }
    {int tlv2; tlv2 = (int)('{'); }
    {int tlv3; tlv3 = (int)('{'); }
    {int tlv4; tlv4 = (int)('{'); }
    {int tlv5; tlv5 = (int)('{'); }
    {int tlv6; tlv6 = (int)('{'); }
    {int tlv7; tlv7 = (int)('{'); }
    {int tlv8; tlv8 = (int)('{'); }
    {int tlv9; tlv9 = (int)('{'); }
    {int tlv10; tlv10 = (int)('{'); }
    {int tlv11; tlv11 = (int)('{'); }
    {cgc_size_t tlv28; tlv28 = (cgc_size_t)('{'); }
    {int tlv27; tlv27 = (int)('{'); }
    {char tlv29; tlv29 = (char)('{'); }
    {int tlv31; tlv31 = (int)('{'); }
    {int tlv35; tlv35 = (int)('{'); }
    {int tlv34; tlv34 = (int)('{'); }
    {void * tlv13; tlv13 = (void *)('{'); }
    {cgc_size_t tlv12; tlv12 = (cgc_size_t)('{'); }
    {char tlv39; tlv39 = (char)('{'); }
    {int tlv41; tlv41 = (int)('{'); }
    {int tlv46; tlv46 = (int)('{'); }
    {int tlv45; tlv45 = (int)('{'); }
    {void * tlv15; tlv15 = (void *)('{'); }
    {cgc_size_t tlv14; tlv14 = (cgc_size_t)('{'); }
    {int tlv52; tlv52 = (int)('{'); }
    {int tlv51; tlv51 = (int)('{'); }
    {void * tlv17; tlv17 = (void *)('{'); }
    {cgc_size_t tlv16; tlv16 = (cgc_size_t)('{'); }
    {int tlv58; tlv58 = (int)('{'); }
    {int tlv57; tlv57 = (int)('{'); }
    {void * tlv19; tlv19 = (void *)('{'); }
    {cgc_size_t tlv18; tlv18 = (cgc_size_t)('{'); }
    {int tlv64; tlv64 = (int)('{'); }
    {int tlv63; tlv63 = (int)('{'); }
    {void * tlv21; tlv21 = (void *)('{'); }
    {cgc_size_t tlv20; tlv20 = (cgc_size_t)('{'); }
    {char tlv67; tlv67 = (char)('{'); }
    {int tlv69; tlv69 = (int)('{'); }
    {char tlv71; tlv71 = (char)('{'); }
    {int tlv73; tlv73 = (int)('{'); }
    {int tlv77; tlv77 = (int)('{'); }
    {int tlv76; tlv76 = (int)('{'); }
    {void * tlv23; tlv23 = (void *)('{'); }
    {cgc_size_t tlv22; tlv22 = (cgc_size_t)('{'); }
    {char tlv81; tlv81 = (char)('{'); }
    {int tlv24; tlv24 = (int)('{'); }
    {void * tlv84; tlv84 = (void *)('{'); }
    {cgc_size_t tlv83; tlv83 = (cgc_size_t)('{'); }
    {char * tlv113; tlv113 = (char *)('{'); }
    {char * tlv114; tlv114 = (char *)('{'); }
    {void * tlv90; tlv90 = (void *)('{'); }
    {cgc_size_t tlv89; tlv89 = (cgc_size_t)('{'); }
    {void * tlv111; tlv111 = (void *)('{'); }
    {cgc_size_t tlv110; tlv110 = (cgc_size_t)('{'); }
    {char * tlv115; tlv115 = (char *)('{'); }
    {char * tlv116; tlv116 = (char *)('{'); }
}
void fix_ingred_genericParsers_0_4(){
fix_ingred_genericParsers_0_4_1();
}
void fix_ingred_genericParsers_0_7_1(){
    {char * temp; temp = (char *)(1); }
    {int start; start = (int)(1); }
    {int end; end = (int)(1); }
    {int tlv1; tlv1 = (int)(1); }
    {int tlv2; tlv2 = (int)(1); }
    {int tlv3; tlv3 = (int)(1); }
    {int tlv4; tlv4 = (int)(1); }
    {int tlv5; tlv5 = (int)(1); }
    {int tlv6; tlv6 = (int)(1); }
    {int tlv7; tlv7 = (int)(1); }
    {int tlv8; tlv8 = (int)(1); }
    {int tlv9; tlv9 = (int)(1); }
    {int tlv10; tlv10 = (int)(1); }
    {int tlv11; tlv11 = (int)(1); }
    {cgc_size_t tlv28; tlv28 = (cgc_size_t)(1); }
    {int tlv27; tlv27 = (int)(1); }
    {char tlv29; tlv29 = (char)(1); }
    {int tlv31; tlv31 = (int)(1); }
    {int tlv35; tlv35 = (int)(1); }
    {int tlv34; tlv34 = (int)(1); }
    {void * tlv13; tlv13 = (void *)(1); }
    {cgc_size_t tlv12; tlv12 = (cgc_size_t)(1); }
    {char tlv39; tlv39 = (char)(1); }
    {int tlv41; tlv41 = (int)(1); }
    {int tlv46; tlv46 = (int)(1); }
    {int tlv45; tlv45 = (int)(1); }
    {void * tlv15; tlv15 = (void *)(1); }
    {cgc_size_t tlv14; tlv14 = (cgc_size_t)(1); }
    {int tlv52; tlv52 = (int)(1); }
    {int tlv51; tlv51 = (int)(1); }
    {void * tlv17; tlv17 = (void *)(1); }
    {cgc_size_t tlv16; tlv16 = (cgc_size_t)(1); }
    {int tlv58; tlv58 = (int)(1); }
    {int tlv57; tlv57 = (int)(1); }
    {void * tlv19; tlv19 = (void *)(1); }
    {cgc_size_t tlv18; tlv18 = (cgc_size_t)(1); }
    {int tlv64; tlv64 = (int)(1); }
    {int tlv63; tlv63 = (int)(1); }
    {void * tlv21; tlv21 = (void *)(1); }
    {cgc_size_t tlv20; tlv20 = (cgc_size_t)(1); }
    {char tlv67; tlv67 = (char)(1); }
    {int tlv69; tlv69 = (int)(1); }
    {char tlv71; tlv71 = (char)(1); }
    {int tlv73; tlv73 = (int)(1); }
    {int tlv77; tlv77 = (int)(1); }
    {int tlv76; tlv76 = (int)(1); }
    {void * tlv23; tlv23 = (void *)(1); }
    {cgc_size_t tlv22; tlv22 = (cgc_size_t)(1); }
    {char tlv81; tlv81 = (char)(1); }
    {int tlv24; tlv24 = (int)(1); }
    {void * tlv84; tlv84 = (void *)(1); }
    {cgc_size_t tlv83; tlv83 = (cgc_size_t)(1); }
    {char * tlv113; tlv113 = (char *)(1); }
    {char * tlv114; tlv114 = (char *)(1); }
    {void * tlv90; tlv90 = (void *)(1); }
    {cgc_size_t tlv89; tlv89 = (cgc_size_t)(1); }
    {void * tlv111; tlv111 = (void *)(1); }
    {cgc_size_t tlv110; tlv110 = (cgc_size_t)(1); }
    {char * tlv115; tlv115 = (char *)(1); }
    {char * tlv116; tlv116 = (char *)(1); }
}
void fix_ingred_genericParsers_0_7(){
fix_ingred_genericParsers_0_7_1();
}
void fix_ingred_genericParsers_0_8_4(){
int tlv3;
    bzero(&tlv3,sizeof(int));
    {char * temp; temp = (char *)(tlv3); }
    {int start; start = (int)(tlv3); }
    {int end; end = (int)(tlv3); }
    {int tlv1; tlv1 = (int)(tlv3); }
    {int tlv2; tlv2 = (int)(tlv3); }
    {int tlv4; tlv4 = (int)(tlv3); }
    {int tlv5; tlv5 = (int)(tlv3); }
    {int tlv6; tlv6 = (int)(tlv3); }
    {int tlv7; tlv7 = (int)(tlv3); }
    {int tlv8; tlv8 = (int)(tlv3); }
    {int tlv9; tlv9 = (int)(tlv3); }
    {int tlv10; tlv10 = (int)(tlv3); }
    {int tlv11; tlv11 = (int)(tlv3); }
    {cgc_size_t tlv28; tlv28 = (cgc_size_t)(tlv3); }
    {int tlv27; tlv27 = (int)(tlv3); }
    {char tlv29; tlv29 = (char)(tlv3); }
    {int tlv31; tlv31 = (int)(tlv3); }
    {int tlv35; tlv35 = (int)(tlv3); }
    {int tlv34; tlv34 = (int)(tlv3); }
    {void * tlv13; tlv13 = (void *)(tlv3); }
    {cgc_size_t tlv12; tlv12 = (cgc_size_t)(tlv3); }
    {char tlv39; tlv39 = (char)(tlv3); }
    {int tlv41; tlv41 = (int)(tlv3); }
    {int tlv46; tlv46 = (int)(tlv3); }
    {int tlv45; tlv45 = (int)(tlv3); }
    {void * tlv15; tlv15 = (void *)(tlv3); }
    {cgc_size_t tlv14; tlv14 = (cgc_size_t)(tlv3); }
    {int tlv52; tlv52 = (int)(tlv3); }
    {int tlv51; tlv51 = (int)(tlv3); }
    {void * tlv17; tlv17 = (void *)(tlv3); }
    {cgc_size_t tlv16; tlv16 = (cgc_size_t)(tlv3); }
    {int tlv58; tlv58 = (int)(tlv3); }
    {int tlv57; tlv57 = (int)(tlv3); }
    {void * tlv19; tlv19 = (void *)(tlv3); }
    {cgc_size_t tlv18; tlv18 = (cgc_size_t)(tlv3); }
    {int tlv64; tlv64 = (int)(tlv3); }
    {int tlv63; tlv63 = (int)(tlv3); }
    {void * tlv21; tlv21 = (void *)(tlv3); }
    {cgc_size_t tlv20; tlv20 = (cgc_size_t)(tlv3); }
    {char tlv67; tlv67 = (char)(tlv3); }
    {int tlv69; tlv69 = (int)(tlv3); }
    {char tlv71; tlv71 = (char)(tlv3); }
    {int tlv73; tlv73 = (int)(tlv3); }
    {int tlv77; tlv77 = (int)(tlv3); }
    {int tlv76; tlv76 = (int)(tlv3); }
    {void * tlv23; tlv23 = (void *)(tlv3); }
    {cgc_size_t tlv22; tlv22 = (cgc_size_t)(tlv3); }
    {char tlv81; tlv81 = (char)(tlv3); }
    {int tlv24; tlv24 = (int)(tlv3); }
    {void * tlv84; tlv84 = (void *)(tlv3); }
    {cgc_size_t tlv83; tlv83 = (cgc_size_t)(tlv3); }
    {char * tlv113; tlv113 = (char *)(tlv3); }
    {char * tlv114; tlv114 = (char *)(tlv3); }
    {void * tlv90; tlv90 = (void *)(tlv3); }
    {cgc_size_t tlv89; tlv89 = (cgc_size_t)(tlv3); }
    {void * tlv111; tlv111 = (void *)(tlv3); }
    {cgc_size_t tlv110; tlv110 = (cgc_size_t)(tlv3); }
    {char * tlv115; tlv115 = (char *)(tlv3); }
    {char * tlv116; tlv116 = (char *)(tlv3); }
}
void fix_ingred_genericParsers_0_8_5(){
int tlv3;
    bzero(&tlv3,sizeof(int));
    {char * temp; temp = (char *)(- 1); }
    {int start; start = (int)(- 1); }
    {int end; end = (int)(- 1); }
    {int tlv1; tlv1 = (int)(- 1); }
    {int tlv2; tlv2 = (int)(- 1); }
    {int tlv3; tlv3 = (int)(- 1); }
    {int tlv4; tlv4 = (int)(- 1); }
    {int tlv5; tlv5 = (int)(- 1); }
    {int tlv6; tlv6 = (int)(- 1); }
    {int tlv7; tlv7 = (int)(- 1); }
    {int tlv8; tlv8 = (int)(- 1); }
    {int tlv9; tlv9 = (int)(- 1); }
    {int tlv10; tlv10 = (int)(- 1); }
    {int tlv11; tlv11 = (int)(- 1); }
    {cgc_size_t tlv28; tlv28 = (cgc_size_t)(- 1); }
    {int tlv27; tlv27 = (int)(- 1); }
    {char tlv29; tlv29 = (char)(- 1); }
    {int tlv31; tlv31 = (int)(- 1); }
    {int tlv35; tlv35 = (int)(- 1); }
    {int tlv34; tlv34 = (int)(- 1); }
    {void * tlv13; tlv13 = (void *)(- 1); }
    {cgc_size_t tlv12; tlv12 = (cgc_size_t)(- 1); }
    {char tlv39; tlv39 = (char)(- 1); }
    {int tlv41; tlv41 = (int)(- 1); }
    {int tlv46; tlv46 = (int)(- 1); }
    {int tlv45; tlv45 = (int)(- 1); }
    {void * tlv15; tlv15 = (void *)(- 1); }
    {cgc_size_t tlv14; tlv14 = (cgc_size_t)(- 1); }
    {int tlv52; tlv52 = (int)(- 1); }
    {int tlv51; tlv51 = (int)(- 1); }
    {void * tlv17; tlv17 = (void *)(- 1); }
    {cgc_size_t tlv16; tlv16 = (cgc_size_t)(- 1); }
    {int tlv58; tlv58 = (int)(- 1); }
    {int tlv57; tlv57 = (int)(- 1); }
    {void * tlv19; tlv19 = (void *)(- 1); }
    {cgc_size_t tlv18; tlv18 = (cgc_size_t)(- 1); }
    {int tlv64; tlv64 = (int)(- 1); }
    {int tlv63; tlv63 = (int)(- 1); }
    {void * tlv21; tlv21 = (void *)(- 1); }
    {cgc_size_t tlv20; tlv20 = (cgc_size_t)(- 1); }
    {char tlv67; tlv67 = (char)(- 1); }
    {int tlv69; tlv69 = (int)(- 1); }
    {char tlv71; tlv71 = (char)(- 1); }
    {int tlv73; tlv73 = (int)(- 1); }
    {int tlv77; tlv77 = (int)(- 1); }
    {int tlv76; tlv76 = (int)(- 1); }
    {void * tlv23; tlv23 = (void *)(- 1); }
    {cgc_size_t tlv22; tlv22 = (cgc_size_t)(- 1); }
    {char tlv81; tlv81 = (char)(- 1); }
    {int tlv24; tlv24 = (int)(- 1); }
    {void * tlv84; tlv84 = (void *)(- 1); }
    {cgc_size_t tlv83; tlv83 = (cgc_size_t)(- 1); }
    {char * tlv113; tlv113 = (char *)(- 1); }
    {char * tlv114; tlv114 = (char *)(- 1); }
    {void * tlv90; tlv90 = (void *)(- 1); }
    {cgc_size_t tlv89; tlv89 = (cgc_size_t)(- 1); }
    {void * tlv111; tlv111 = (void *)(- 1); }
    {cgc_size_t tlv110; tlv110 = (cgc_size_t)(- 1); }
    {char * tlv115; tlv115 = (char *)(- 1); }
    {char * tlv116; tlv116 = (char *)(- 1); }
}
void fix_ingred_genericParsers_0_8(){
fix_ingred_genericParsers_0_8_4();
fix_ingred_genericParsers_0_8_5();
}
void fix_ingred_genericParsers_0_11_5(){
int end;
    bzero(&end,sizeof(int));
    {char * temp; temp = (char *)(end); }
    {int start; start = (int)(end); }
    {int tlv1; tlv1 = (int)(end); }
    {int tlv2; tlv2 = (int)(end); }
    {int tlv3; tlv3 = (int)(end); }
    {int tlv4; tlv4 = (int)(end); }
    {int tlv5; tlv5 = (int)(end); }
    {int tlv6; tlv6 = (int)(end); }
    {int tlv7; tlv7 = (int)(end); }
    {int tlv8; tlv8 = (int)(end); }
    {int tlv9; tlv9 = (int)(end); }
    {int tlv10; tlv10 = (int)(end); }
    {int tlv11; tlv11 = (int)(end); }
    {cgc_size_t tlv28; tlv28 = (cgc_size_t)(end); }
    {int tlv27; tlv27 = (int)(end); }
    {char tlv29; tlv29 = (char)(end); }
    {int tlv31; tlv31 = (int)(end); }
    {int tlv35; tlv35 = (int)(end); }
    {int tlv34; tlv34 = (int)(end); }
    {void * tlv13; tlv13 = (void *)(end); }
    {cgc_size_t tlv12; tlv12 = (cgc_size_t)(end); }
    {char tlv39; tlv39 = (char)(end); }
    {int tlv41; tlv41 = (int)(end); }
    {int tlv46; tlv46 = (int)(end); }
    {int tlv45; tlv45 = (int)(end); }
    {void * tlv15; tlv15 = (void *)(end); }
    {cgc_size_t tlv14; tlv14 = (cgc_size_t)(end); }
    {int tlv52; tlv52 = (int)(end); }
    {int tlv51; tlv51 = (int)(end); }
    {void * tlv17; tlv17 = (void *)(end); }
    {cgc_size_t tlv16; tlv16 = (cgc_size_t)(end); }
    {int tlv58; tlv58 = (int)(end); }
    {int tlv57; tlv57 = (int)(end); }
    {void * tlv19; tlv19 = (void *)(end); }
    {cgc_size_t tlv18; tlv18 = (cgc_size_t)(end); }
    {int tlv64; tlv64 = (int)(end); }
    {int tlv63; tlv63 = (int)(end); }
    {void * tlv21; tlv21 = (void *)(end); }
    {cgc_size_t tlv20; tlv20 = (cgc_size_t)(end); }
    {char tlv67; tlv67 = (char)(end); }
    {int tlv69; tlv69 = (int)(end); }
    {char tlv71; tlv71 = (char)(end); }
    {int tlv73; tlv73 = (int)(end); }
    {int tlv77; tlv77 = (int)(end); }
    {int tlv76; tlv76 = (int)(end); }
    {void * tlv23; tlv23 = (void *)(end); }
    {cgc_size_t tlv22; tlv22 = (cgc_size_t)(end); }
    {char tlv81; tlv81 = (char)(end); }
    {int tlv24; tlv24 = (int)(end); }
    {void * tlv84; tlv84 = (void *)(end); }
    {cgc_size_t tlv83; tlv83 = (cgc_size_t)(end); }
    {char * tlv113; tlv113 = (char *)(end); }
    {char * tlv114; tlv114 = (char *)(end); }
    {void * tlv90; tlv90 = (void *)(end); }
    {cgc_size_t tlv89; tlv89 = (cgc_size_t)(end); }
    {void * tlv111; tlv111 = (void *)(end); }
    {cgc_size_t tlv110; tlv110 = (cgc_size_t)(end); }
    {char * tlv115; tlv115 = (char *)(end); }
    {char * tlv116; tlv116 = (char *)(end); }
}
void fix_ingred_genericParsers_0_11(){
fix_ingred_genericParsers_0_11_5();
}
void fix_ingred_genericParsers_0_13_5(){
int start;
    bzero(&start,sizeof(int));
    {char * temp; temp = (char *)(start); }
    {int end; end = (int)(start); }
    {int tlv1; tlv1 = (int)(start); }
    {int tlv2; tlv2 = (int)(start); }
    {int tlv3; tlv3 = (int)(start); }
    {int tlv4; tlv4 = (int)(start); }
    {int tlv5; tlv5 = (int)(start); }
    {int tlv6; tlv6 = (int)(start); }
    {int tlv7; tlv7 = (int)(start); }
    {int tlv8; tlv8 = (int)(start); }
    {int tlv9; tlv9 = (int)(start); }
    {int tlv10; tlv10 = (int)(start); }
    {int tlv11; tlv11 = (int)(start); }
    {cgc_size_t tlv28; tlv28 = (cgc_size_t)(start); }
    {int tlv27; tlv27 = (int)(start); }
    {char tlv29; tlv29 = (char)(start); }
    {int tlv31; tlv31 = (int)(start); }
    {int tlv35; tlv35 = (int)(start); }
    {int tlv34; tlv34 = (int)(start); }
    {void * tlv13; tlv13 = (void *)(start); }
    {cgc_size_t tlv12; tlv12 = (cgc_size_t)(start); }
    {char tlv39; tlv39 = (char)(start); }
    {int tlv41; tlv41 = (int)(start); }
    {int tlv46; tlv46 = (int)(start); }
    {int tlv45; tlv45 = (int)(start); }
    {void * tlv15; tlv15 = (void *)(start); }
    {cgc_size_t tlv14; tlv14 = (cgc_size_t)(start); }
    {int tlv52; tlv52 = (int)(start); }
    {int tlv51; tlv51 = (int)(start); }
    {void * tlv17; tlv17 = (void *)(start); }
    {cgc_size_t tlv16; tlv16 = (cgc_size_t)(start); }
    {int tlv58; tlv58 = (int)(start); }
    {int tlv57; tlv57 = (int)(start); }
    {void * tlv19; tlv19 = (void *)(start); }
    {cgc_size_t tlv18; tlv18 = (cgc_size_t)(start); }
    {int tlv64; tlv64 = (int)(start); }
    {int tlv63; tlv63 = (int)(start); }
    {void * tlv21; tlv21 = (void *)(start); }
    {cgc_size_t tlv20; tlv20 = (cgc_size_t)(start); }
    {char tlv67; tlv67 = (char)(start); }
    {int tlv69; tlv69 = (int)(start); }
    {char tlv71; tlv71 = (char)(start); }
    {int tlv73; tlv73 = (int)(start); }
    {int tlv77; tlv77 = (int)(start); }
    {int tlv76; tlv76 = (int)(start); }
    {void * tlv23; tlv23 = (void *)(start); }
    {cgc_size_t tlv22; tlv22 = (cgc_size_t)(start); }
    {char tlv81; tlv81 = (char)(start); }
    {int tlv24; tlv24 = (int)(start); }
    {void * tlv84; tlv84 = (void *)(start); }
    {cgc_size_t tlv83; tlv83 = (cgc_size_t)(start); }
    {char * tlv113; tlv113 = (char *)(start); }
    {char * tlv114; tlv114 = (char *)(start); }
    {void * tlv90; tlv90 = (void *)(start); }
    {cgc_size_t tlv89; tlv89 = (cgc_size_t)(start); }
    {void * tlv111; tlv111 = (void *)(start); }
    {cgc_size_t tlv110; tlv110 = (cgc_size_t)(start); }
    {char * tlv115; tlv115 = (char *)(start); }
    {char * tlv116; tlv116 = (char *)(start); }
}
void fix_ingred_genericParsers_0_13(){
fix_ingred_genericParsers_0_13_5();
}
void fix_ingred_genericParsers_0_15_5(){
char temp_ref;
    bzero(&temp_ref,1*sizeof(char));
char * temp = &temp_ref;
    {int start; start = (int)(temp); }
    {int end; end = (int)(temp); }
    {int tlv1; tlv1 = (int)(temp); }
    {int tlv2; tlv2 = (int)(temp); }
    {int tlv3; tlv3 = (int)(temp); }
    {int tlv4; tlv4 = (int)(temp); }
    {int tlv5; tlv5 = (int)(temp); }
    {int tlv6; tlv6 = (int)(temp); }
    {int tlv7; tlv7 = (int)(temp); }
    {int tlv8; tlv8 = (int)(temp); }
    {int tlv9; tlv9 = (int)(temp); }
    {int tlv10; tlv10 = (int)(temp); }
    {int tlv11; tlv11 = (int)(temp); }
    {cgc_size_t tlv28; tlv28 = (cgc_size_t)(temp); }
    {int tlv27; tlv27 = (int)(temp); }
    {char tlv29; tlv29 = (char)(temp); }
    {int tlv31; tlv31 = (int)(temp); }
    {int tlv35; tlv35 = (int)(temp); }
    {int tlv34; tlv34 = (int)(temp); }
    {void * tlv13; tlv13 = (void *)(temp); }
    {cgc_size_t tlv12; tlv12 = (cgc_size_t)(temp); }
    {char tlv39; tlv39 = (char)(temp); }
    {int tlv41; tlv41 = (int)(temp); }
    {int tlv46; tlv46 = (int)(temp); }
    {int tlv45; tlv45 = (int)(temp); }
    {void * tlv15; tlv15 = (void *)(temp); }
    {cgc_size_t tlv14; tlv14 = (cgc_size_t)(temp); }
    {int tlv52; tlv52 = (int)(temp); }
    {int tlv51; tlv51 = (int)(temp); }
    {void * tlv17; tlv17 = (void *)(temp); }
    {cgc_size_t tlv16; tlv16 = (cgc_size_t)(temp); }
    {int tlv58; tlv58 = (int)(temp); }
    {int tlv57; tlv57 = (int)(temp); }
    {void * tlv19; tlv19 = (void *)(temp); }
    {cgc_size_t tlv18; tlv18 = (cgc_size_t)(temp); }
    {int tlv64; tlv64 = (int)(temp); }
    {int tlv63; tlv63 = (int)(temp); }
    {void * tlv21; tlv21 = (void *)(temp); }
    {cgc_size_t tlv20; tlv20 = (cgc_size_t)(temp); }
    {char tlv67; tlv67 = (char)(temp); }
    {int tlv69; tlv69 = (int)(temp); }
    {char tlv71; tlv71 = (char)(temp); }
    {int tlv73; tlv73 = (int)(temp); }
    {int tlv77; tlv77 = (int)(temp); }
    {int tlv76; tlv76 = (int)(temp); }
    {void * tlv23; tlv23 = (void *)(temp); }
    {cgc_size_t tlv22; tlv22 = (cgc_size_t)(temp); }
    {char tlv81; tlv81 = (char)(temp); }
    {int tlv24; tlv24 = (int)(temp); }
    {void * tlv84; tlv84 = (void *)(temp); }
    {cgc_size_t tlv83; tlv83 = (cgc_size_t)(temp); }
    {char * tlv113; tlv113 = (char *)(temp); }
    {char * tlv114; tlv114 = (char *)(temp); }
    {void * tlv90; tlv90 = (void *)(temp); }
    {cgc_size_t tlv89; tlv89 = (cgc_size_t)(temp); }
    {void * tlv111; tlv111 = (void *)(temp); }
    {cgc_size_t tlv110; tlv110 = (cgc_size_t)(temp); }
    {char * tlv115; tlv115 = (char *)(temp); }
    {char * tlv116; tlv116 = (char *)(temp); }
}
void fix_ingred_genericParsers_0_15(){
fix_ingred_genericParsers_0_15_5();
}
void fix_ingred_genericParsers_0_17_6(){
int tlv4;
    bzero(&tlv4,sizeof(int));
    {char * temp; temp = (char *)(tlv4); }
    {int start; start = (int)(tlv4); }
    {int end; end = (int)(tlv4); }
    {int tlv1; tlv1 = (int)(tlv4); }
    {int tlv2; tlv2 = (int)(tlv4); }
    {int tlv3; tlv3 = (int)(tlv4); }
    {int tlv5; tlv5 = (int)(tlv4); }
    {int tlv6; tlv6 = (int)(tlv4); }
    {int tlv7; tlv7 = (int)(tlv4); }
    {int tlv8; tlv8 = (int)(tlv4); }
    {int tlv9; tlv9 = (int)(tlv4); }
    {int tlv10; tlv10 = (int)(tlv4); }
    {int tlv11; tlv11 = (int)(tlv4); }
    {cgc_size_t tlv28; tlv28 = (cgc_size_t)(tlv4); }
    {int tlv27; tlv27 = (int)(tlv4); }
    {char tlv29; tlv29 = (char)(tlv4); }
    {int tlv31; tlv31 = (int)(tlv4); }
    {int tlv35; tlv35 = (int)(tlv4); }
    {int tlv34; tlv34 = (int)(tlv4); }
    {void * tlv13; tlv13 = (void *)(tlv4); }
    {cgc_size_t tlv12; tlv12 = (cgc_size_t)(tlv4); }
    {char tlv39; tlv39 = (char)(tlv4); }
    {int tlv41; tlv41 = (int)(tlv4); }
    {int tlv46; tlv46 = (int)(tlv4); }
    {int tlv45; tlv45 = (int)(tlv4); }
    {void * tlv15; tlv15 = (void *)(tlv4); }
    {cgc_size_t tlv14; tlv14 = (cgc_size_t)(tlv4); }
    {int tlv52; tlv52 = (int)(tlv4); }
    {int tlv51; tlv51 = (int)(tlv4); }
    {void * tlv17; tlv17 = (void *)(tlv4); }
    {cgc_size_t tlv16; tlv16 = (cgc_size_t)(tlv4); }
    {int tlv58; tlv58 = (int)(tlv4); }
    {int tlv57; tlv57 = (int)(tlv4); }
    {void * tlv19; tlv19 = (void *)(tlv4); }
    {cgc_size_t tlv18; tlv18 = (cgc_size_t)(tlv4); }
    {int tlv64; tlv64 = (int)(tlv4); }
    {int tlv63; tlv63 = (int)(tlv4); }
    {void * tlv21; tlv21 = (void *)(tlv4); }
    {cgc_size_t tlv20; tlv20 = (cgc_size_t)(tlv4); }
    {char tlv67; tlv67 = (char)(tlv4); }
    {int tlv69; tlv69 = (int)(tlv4); }
    {char tlv71; tlv71 = (char)(tlv4); }
    {int tlv73; tlv73 = (int)(tlv4); }
    {int tlv77; tlv77 = (int)(tlv4); }
    {int tlv76; tlv76 = (int)(tlv4); }
    {void * tlv23; tlv23 = (void *)(tlv4); }
    {cgc_size_t tlv22; tlv22 = (cgc_size_t)(tlv4); }
    {char tlv81; tlv81 = (char)(tlv4); }
    {int tlv24; tlv24 = (int)(tlv4); }
    {void * tlv84; tlv84 = (void *)(tlv4); }
    {cgc_size_t tlv83; tlv83 = (cgc_size_t)(tlv4); }
    {char * tlv113; tlv113 = (char *)(tlv4); }
    {char * tlv114; tlv114 = (char *)(tlv4); }
    {void * tlv90; tlv90 = (void *)(tlv4); }
    {cgc_size_t tlv89; tlv89 = (cgc_size_t)(tlv4); }
    {void * tlv111; tlv111 = (void *)(tlv4); }
    {cgc_size_t tlv110; tlv110 = (cgc_size_t)(tlv4); }
    {char * tlv115; tlv115 = (char *)(tlv4); }
    {char * tlv116; tlv116 = (char *)(tlv4); }
}
void fix_ingred_genericParsers_0_17(){
fix_ingred_genericParsers_0_17_6();
}
void fix_ingred_genericParsers_0_19_0(){
char temp_ref;
    bzero(&temp_ref,1*sizeof(char));
char * temp = &temp_ref;
    {int start; start = (int)(temp); }
    {int end; end = (int)(temp); }
    {int tlv1; tlv1 = (int)(temp); }
    {int tlv2; tlv2 = (int)(temp); }
    {int tlv3; tlv3 = (int)(temp); }
    {int tlv4; tlv4 = (int)(temp); }
    {int tlv5; tlv5 = (int)(temp); }
    {int tlv6; tlv6 = (int)(temp); }
    {int tlv7; tlv7 = (int)(temp); }
    {int tlv8; tlv8 = (int)(temp); }
    {int tlv9; tlv9 = (int)(temp); }
    {int tlv10; tlv10 = (int)(temp); }
    {int tlv11; tlv11 = (int)(temp); }
    {cgc_size_t tlv28; tlv28 = (cgc_size_t)(temp); }
    {int tlv27; tlv27 = (int)(temp); }
    {char tlv29; tlv29 = (char)(temp); }
    {int tlv31; tlv31 = (int)(temp); }
    {int tlv35; tlv35 = (int)(temp); }
    {int tlv34; tlv34 = (int)(temp); }
    {void * tlv13; tlv13 = (void *)(temp); }
    {cgc_size_t tlv12; tlv12 = (cgc_size_t)(temp); }
    {char tlv39; tlv39 = (char)(temp); }
    {int tlv41; tlv41 = (int)(temp); }
    {int tlv46; tlv46 = (int)(temp); }
    {int tlv45; tlv45 = (int)(temp); }
    {void * tlv15; tlv15 = (void *)(temp); }
    {cgc_size_t tlv14; tlv14 = (cgc_size_t)(temp); }
    {int tlv52; tlv52 = (int)(temp); }
    {int tlv51; tlv51 = (int)(temp); }
    {void * tlv17; tlv17 = (void *)(temp); }
    {cgc_size_t tlv16; tlv16 = (cgc_size_t)(temp); }
    {int tlv58; tlv58 = (int)(temp); }
    {int tlv57; tlv57 = (int)(temp); }
    {void * tlv19; tlv19 = (void *)(temp); }
    {cgc_size_t tlv18; tlv18 = (cgc_size_t)(temp); }
    {int tlv64; tlv64 = (int)(temp); }
    {int tlv63; tlv63 = (int)(temp); }
    {void * tlv21; tlv21 = (void *)(temp); }
    {cgc_size_t tlv20; tlv20 = (cgc_size_t)(temp); }
    {char tlv67; tlv67 = (char)(temp); }
    {int tlv69; tlv69 = (int)(temp); }
    {char tlv71; tlv71 = (char)(temp); }
    {int tlv73; tlv73 = (int)(temp); }
    {int tlv77; tlv77 = (int)(temp); }
    {int tlv76; tlv76 = (int)(temp); }
    {void * tlv23; tlv23 = (void *)(temp); }
    {cgc_size_t tlv22; tlv22 = (cgc_size_t)(temp); }
    {char tlv81; tlv81 = (char)(temp); }
    {int tlv24; tlv24 = (int)(temp); }
    {void * tlv84; tlv84 = (void *)(temp); }
    {cgc_size_t tlv83; tlv83 = (cgc_size_t)(temp); }
    {char * tlv113; tlv113 = (char *)(temp); }
    {char * tlv114; tlv114 = (char *)(temp); }
    {void * tlv90; tlv90 = (void *)(temp); }
    {cgc_size_t tlv89; tlv89 = (cgc_size_t)(temp); }
    {void * tlv111; tlv111 = (void *)(temp); }
    {cgc_size_t tlv110; tlv110 = (cgc_size_t)(temp); }
    {char * tlv115; tlv115 = (char *)(temp); }
    {char * tlv116; tlv116 = (char *)(temp); }
}
void fix_ingred_genericParsers_0_19(){
fix_ingred_genericParsers_0_19_0();
}
void fix_ingred_genericParsers_0_20_1(){
char tlv115_ref;
    bzero(&tlv115_ref,1*sizeof(char));
char * tlv115 = &tlv115_ref;
    {char * temp; temp = (char *)(cgc_strlen ( tlv115 ) + 1); }
    {int start; start = (int)(cgc_strlen ( tlv115 ) + 1); }
    {int end; end = (int)(cgc_strlen ( tlv115 ) + 1); }
    {int tlv1; tlv1 = (int)(cgc_strlen ( tlv115 ) + 1); }
    {int tlv2; tlv2 = (int)(cgc_strlen ( tlv115 ) + 1); }
    {int tlv3; tlv3 = (int)(cgc_strlen ( tlv115 ) + 1); }
    {int tlv4; tlv4 = (int)(cgc_strlen ( tlv115 ) + 1); }
    {int tlv5; tlv5 = (int)(cgc_strlen ( tlv115 ) + 1); }
    {int tlv6; tlv6 = (int)(cgc_strlen ( tlv115 ) + 1); }
    {int tlv7; tlv7 = (int)(cgc_strlen ( tlv115 ) + 1); }
    {int tlv8; tlv8 = (int)(cgc_strlen ( tlv115 ) + 1); }
    {int tlv9; tlv9 = (int)(cgc_strlen ( tlv115 ) + 1); }
    {int tlv10; tlv10 = (int)(cgc_strlen ( tlv115 ) + 1); }
    {int tlv11; tlv11 = (int)(cgc_strlen ( tlv115 ) + 1); }
    {cgc_size_t tlv28; tlv28 = (cgc_size_t)(cgc_strlen ( tlv115 ) + 1); }
    {int tlv27; tlv27 = (int)(cgc_strlen ( tlv115 ) + 1); }
    {char tlv29; tlv29 = (char)(cgc_strlen ( tlv115 ) + 1); }
    {int tlv31; tlv31 = (int)(cgc_strlen ( tlv115 ) + 1); }
    {int tlv35; tlv35 = (int)(cgc_strlen ( tlv115 ) + 1); }
    {int tlv34; tlv34 = (int)(cgc_strlen ( tlv115 ) + 1); }
    {void * tlv13; tlv13 = (void *)(cgc_strlen ( tlv115 ) + 1); }
    {cgc_size_t tlv12; tlv12 = (cgc_size_t)(cgc_strlen ( tlv115 ) + 1); }
    {char tlv39; tlv39 = (char)(cgc_strlen ( tlv115 ) + 1); }
    {int tlv41; tlv41 = (int)(cgc_strlen ( tlv115 ) + 1); }
    {int tlv46; tlv46 = (int)(cgc_strlen ( tlv115 ) + 1); }
    {int tlv45; tlv45 = (int)(cgc_strlen ( tlv115 ) + 1); }
    {void * tlv15; tlv15 = (void *)(cgc_strlen ( tlv115 ) + 1); }
    {cgc_size_t tlv14; tlv14 = (cgc_size_t)(cgc_strlen ( tlv115 ) + 1); }
    {int tlv52; tlv52 = (int)(cgc_strlen ( tlv115 ) + 1); }
    {int tlv51; tlv51 = (int)(cgc_strlen ( tlv115 ) + 1); }
    {void * tlv17; tlv17 = (void *)(cgc_strlen ( tlv115 ) + 1); }
    {cgc_size_t tlv16; tlv16 = (cgc_size_t)(cgc_strlen ( tlv115 ) + 1); }
    {int tlv58; tlv58 = (int)(cgc_strlen ( tlv115 ) + 1); }
    {int tlv57; tlv57 = (int)(cgc_strlen ( tlv115 ) + 1); }
    {void * tlv19; tlv19 = (void *)(cgc_strlen ( tlv115 ) + 1); }
    {cgc_size_t tlv18; tlv18 = (cgc_size_t)(cgc_strlen ( tlv115 ) + 1); }
    {int tlv64; tlv64 = (int)(cgc_strlen ( tlv115 ) + 1); }
    {int tlv63; tlv63 = (int)(cgc_strlen ( tlv115 ) + 1); }
    {void * tlv21; tlv21 = (void *)(cgc_strlen ( tlv115 ) + 1); }
    {cgc_size_t tlv20; tlv20 = (cgc_size_t)(cgc_strlen ( tlv115 ) + 1); }
    {char tlv67; tlv67 = (char)(cgc_strlen ( tlv115 ) + 1); }
    {int tlv69; tlv69 = (int)(cgc_strlen ( tlv115 ) + 1); }
    {char tlv71; tlv71 = (char)(cgc_strlen ( tlv115 ) + 1); }
    {int tlv73; tlv73 = (int)(cgc_strlen ( tlv115 ) + 1); }
    {int tlv77; tlv77 = (int)(cgc_strlen ( tlv115 ) + 1); }
    {int tlv76; tlv76 = (int)(cgc_strlen ( tlv115 ) + 1); }
    {void * tlv23; tlv23 = (void *)(cgc_strlen ( tlv115 ) + 1); }
    {cgc_size_t tlv22; tlv22 = (cgc_size_t)(cgc_strlen ( tlv115 ) + 1); }
    {char tlv81; tlv81 = (char)(cgc_strlen ( tlv115 ) + 1); }
    {int tlv24; tlv24 = (int)(cgc_strlen ( tlv115 ) + 1); }
    {void * tlv84; tlv84 = (void *)(cgc_strlen ( tlv115 ) + 1); }
    {cgc_size_t tlv83; tlv83 = (cgc_size_t)(cgc_strlen ( tlv115 ) + 1); }
    {char * tlv113; tlv113 = (char *)(cgc_strlen ( tlv115 ) + 1); }
    {char * tlv114; tlv114 = (char *)(cgc_strlen ( tlv115 ) + 1); }
    {void * tlv90; tlv90 = (void *)(cgc_strlen ( tlv115 ) + 1); }
    {cgc_size_t tlv89; tlv89 = (cgc_size_t)(cgc_strlen ( tlv115 ) + 1); }
    {void * tlv111; tlv111 = (void *)(cgc_strlen ( tlv115 ) + 1); }
    {cgc_size_t tlv110; tlv110 = (cgc_size_t)(cgc_strlen ( tlv115 ) + 1); }
    {char * tlv116; tlv116 = (char *)(cgc_strlen ( tlv115 ) + 1); }
}
void fix_ingred_genericParsers_0_20(){
fix_ingred_genericParsers_0_20_1();
}
void fix_ingred_genericParsers_0_22_1(){
char tlv113_ref;
    bzero(&tlv113_ref,1*sizeof(char));
char * tlv113 = &tlv113_ref;
    {char * temp; temp = (char *)(cgc_strlen ( tlv113 ) + 1); }
    {int start; start = (int)(cgc_strlen ( tlv113 ) + 1); }
    {int end; end = (int)(cgc_strlen ( tlv113 ) + 1); }
    {int tlv1; tlv1 = (int)(cgc_strlen ( tlv113 ) + 1); }
    {int tlv2; tlv2 = (int)(cgc_strlen ( tlv113 ) + 1); }
    {int tlv3; tlv3 = (int)(cgc_strlen ( tlv113 ) + 1); }
    {int tlv4; tlv4 = (int)(cgc_strlen ( tlv113 ) + 1); }
    {int tlv5; tlv5 = (int)(cgc_strlen ( tlv113 ) + 1); }
    {int tlv6; tlv6 = (int)(cgc_strlen ( tlv113 ) + 1); }
    {int tlv7; tlv7 = (int)(cgc_strlen ( tlv113 ) + 1); }
    {int tlv8; tlv8 = (int)(cgc_strlen ( tlv113 ) + 1); }
    {int tlv9; tlv9 = (int)(cgc_strlen ( tlv113 ) + 1); }
    {int tlv10; tlv10 = (int)(cgc_strlen ( tlv113 ) + 1); }
    {int tlv11; tlv11 = (int)(cgc_strlen ( tlv113 ) + 1); }
    {cgc_size_t tlv28; tlv28 = (cgc_size_t)(cgc_strlen ( tlv113 ) + 1); }
    {int tlv27; tlv27 = (int)(cgc_strlen ( tlv113 ) + 1); }
    {char tlv29; tlv29 = (char)(cgc_strlen ( tlv113 ) + 1); }
    {int tlv31; tlv31 = (int)(cgc_strlen ( tlv113 ) + 1); }
    {int tlv35; tlv35 = (int)(cgc_strlen ( tlv113 ) + 1); }
    {int tlv34; tlv34 = (int)(cgc_strlen ( tlv113 ) + 1); }
    {void * tlv13; tlv13 = (void *)(cgc_strlen ( tlv113 ) + 1); }
    {cgc_size_t tlv12; tlv12 = (cgc_size_t)(cgc_strlen ( tlv113 ) + 1); }
    {char tlv39; tlv39 = (char)(cgc_strlen ( tlv113 ) + 1); }
    {int tlv41; tlv41 = (int)(cgc_strlen ( tlv113 ) + 1); }
    {int tlv46; tlv46 = (int)(cgc_strlen ( tlv113 ) + 1); }
    {int tlv45; tlv45 = (int)(cgc_strlen ( tlv113 ) + 1); }
    {void * tlv15; tlv15 = (void *)(cgc_strlen ( tlv113 ) + 1); }
    {cgc_size_t tlv14; tlv14 = (cgc_size_t)(cgc_strlen ( tlv113 ) + 1); }
    {int tlv52; tlv52 = (int)(cgc_strlen ( tlv113 ) + 1); }
    {int tlv51; tlv51 = (int)(cgc_strlen ( tlv113 ) + 1); }
    {void * tlv17; tlv17 = (void *)(cgc_strlen ( tlv113 ) + 1); }
    {cgc_size_t tlv16; tlv16 = (cgc_size_t)(cgc_strlen ( tlv113 ) + 1); }
    {int tlv58; tlv58 = (int)(cgc_strlen ( tlv113 ) + 1); }
    {int tlv57; tlv57 = (int)(cgc_strlen ( tlv113 ) + 1); }
    {void * tlv19; tlv19 = (void *)(cgc_strlen ( tlv113 ) + 1); }
    {cgc_size_t tlv18; tlv18 = (cgc_size_t)(cgc_strlen ( tlv113 ) + 1); }
    {int tlv64; tlv64 = (int)(cgc_strlen ( tlv113 ) + 1); }
    {int tlv63; tlv63 = (int)(cgc_strlen ( tlv113 ) + 1); }
    {void * tlv21; tlv21 = (void *)(cgc_strlen ( tlv113 ) + 1); }
    {cgc_size_t tlv20; tlv20 = (cgc_size_t)(cgc_strlen ( tlv113 ) + 1); }
    {char tlv67; tlv67 = (char)(cgc_strlen ( tlv113 ) + 1); }
    {int tlv69; tlv69 = (int)(cgc_strlen ( tlv113 ) + 1); }
    {char tlv71; tlv71 = (char)(cgc_strlen ( tlv113 ) + 1); }
    {int tlv73; tlv73 = (int)(cgc_strlen ( tlv113 ) + 1); }
    {int tlv77; tlv77 = (int)(cgc_strlen ( tlv113 ) + 1); }
    {int tlv76; tlv76 = (int)(cgc_strlen ( tlv113 ) + 1); }
    {void * tlv23; tlv23 = (void *)(cgc_strlen ( tlv113 ) + 1); }
    {cgc_size_t tlv22; tlv22 = (cgc_size_t)(cgc_strlen ( tlv113 ) + 1); }
    {char tlv81; tlv81 = (char)(cgc_strlen ( tlv113 ) + 1); }
    {int tlv24; tlv24 = (int)(cgc_strlen ( tlv113 ) + 1); }
    {void * tlv84; tlv84 = (void *)(cgc_strlen ( tlv113 ) + 1); }
    {cgc_size_t tlv83; tlv83 = (cgc_size_t)(cgc_strlen ( tlv113 ) + 1); }
    {char * tlv114; tlv114 = (char *)(cgc_strlen ( tlv113 ) + 1); }
    {void * tlv90; tlv90 = (void *)(cgc_strlen ( tlv113 ) + 1); }
    {cgc_size_t tlv89; tlv89 = (cgc_size_t)(cgc_strlen ( tlv113 ) + 1); }
    {void * tlv111; tlv111 = (void *)(cgc_strlen ( tlv113 ) + 1); }
    {cgc_size_t tlv110; tlv110 = (cgc_size_t)(cgc_strlen ( tlv113 ) + 1); }
    {char * tlv115; tlv115 = (char *)(cgc_strlen ( tlv113 ) + 1); }
    {char * tlv116; tlv116 = (char *)(cgc_strlen ( tlv113 ) + 1); }
}
void fix_ingred_genericParsers_0_22(){
fix_ingred_genericParsers_0_22_1();
}
void fix_ingred_genericParsers_0_23_1(){
    {char * temp; temp = (char *)('}'); }
    {int start; start = (int)('}'); }
    {int end; end = (int)('}'); }
    {int tlv1; tlv1 = (int)('}'); }
    {int tlv2; tlv2 = (int)('}'); }
    {int tlv3; tlv3 = (int)('}'); }
    {int tlv4; tlv4 = (int)('}'); }
    {int tlv5; tlv5 = (int)('}'); }
    {int tlv6; tlv6 = (int)('}'); }
    {int tlv7; tlv7 = (int)('}'); }
    {int tlv8; tlv8 = (int)('}'); }
    {int tlv9; tlv9 = (int)('}'); }
    {int tlv10; tlv10 = (int)('}'); }
    {int tlv11; tlv11 = (int)('}'); }
    {cgc_size_t tlv28; tlv28 = (cgc_size_t)('}'); }
    {int tlv27; tlv27 = (int)('}'); }
    {char tlv29; tlv29 = (char)('}'); }
    {int tlv31; tlv31 = (int)('}'); }
    {int tlv35; tlv35 = (int)('}'); }
    {int tlv34; tlv34 = (int)('}'); }
    {void * tlv13; tlv13 = (void *)('}'); }
    {cgc_size_t tlv12; tlv12 = (cgc_size_t)('}'); }
    {char tlv39; tlv39 = (char)('}'); }
    {int tlv41; tlv41 = (int)('}'); }
    {int tlv46; tlv46 = (int)('}'); }
    {int tlv45; tlv45 = (int)('}'); }
    {void * tlv15; tlv15 = (void *)('}'); }
    {cgc_size_t tlv14; tlv14 = (cgc_size_t)('}'); }
    {int tlv52; tlv52 = (int)('}'); }
    {int tlv51; tlv51 = (int)('}'); }
    {void * tlv17; tlv17 = (void *)('}'); }
    {cgc_size_t tlv16; tlv16 = (cgc_size_t)('}'); }
    {int tlv58; tlv58 = (int)('}'); }
    {int tlv57; tlv57 = (int)('}'); }
    {void * tlv19; tlv19 = (void *)('}'); }
    {cgc_size_t tlv18; tlv18 = (cgc_size_t)('}'); }
    {int tlv64; tlv64 = (int)('}'); }
    {int tlv63; tlv63 = (int)('}'); }
    {void * tlv21; tlv21 = (void *)('}'); }
    {cgc_size_t tlv20; tlv20 = (cgc_size_t)('}'); }
    {char tlv67; tlv67 = (char)('}'); }
    {int tlv69; tlv69 = (int)('}'); }
    {char tlv71; tlv71 = (char)('}'); }
    {int tlv73; tlv73 = (int)('}'); }
    {int tlv77; tlv77 = (int)('}'); }
    {int tlv76; tlv76 = (int)('}'); }
    {void * tlv23; tlv23 = (void *)('}'); }
    {cgc_size_t tlv22; tlv22 = (cgc_size_t)('}'); }
    {char tlv81; tlv81 = (char)('}'); }
    {int tlv24; tlv24 = (int)('}'); }
    {void * tlv84; tlv84 = (void *)('}'); }
    {cgc_size_t tlv83; tlv83 = (cgc_size_t)('}'); }
    {char * tlv113; tlv113 = (char *)('}'); }
    {char * tlv114; tlv114 = (char *)('}'); }
    {void * tlv90; tlv90 = (void *)('}'); }
    {cgc_size_t tlv89; tlv89 = (cgc_size_t)('}'); }
    {void * tlv111; tlv111 = (void *)('}'); }
    {cgc_size_t tlv110; tlv110 = (cgc_size_t)('}'); }
    {char * tlv115; tlv115 = (char *)('}'); }
    {char * tlv116; tlv116 = (char *)('}'); }
}
void fix_ingred_genericParsers_0_23(){
fix_ingred_genericParsers_0_23_1();
}
void fix_ingred_genericParsers_0_27_5(){
int tlv6;
    bzero(&tlv6,sizeof(int));
    {char * temp; temp = (char *)(tlv6); }
    {int start; start = (int)(tlv6); }
    {int end; end = (int)(tlv6); }
    {int tlv1; tlv1 = (int)(tlv6); }
    {int tlv2; tlv2 = (int)(tlv6); }
    {int tlv3; tlv3 = (int)(tlv6); }
    {int tlv4; tlv4 = (int)(tlv6); }
    {int tlv5; tlv5 = (int)(tlv6); }
    {int tlv7; tlv7 = (int)(tlv6); }
    {int tlv8; tlv8 = (int)(tlv6); }
    {int tlv9; tlv9 = (int)(tlv6); }
    {int tlv10; tlv10 = (int)(tlv6); }
    {int tlv11; tlv11 = (int)(tlv6); }
    {cgc_size_t tlv28; tlv28 = (cgc_size_t)(tlv6); }
    {int tlv27; tlv27 = (int)(tlv6); }
    {char tlv29; tlv29 = (char)(tlv6); }
    {int tlv31; tlv31 = (int)(tlv6); }
    {int tlv35; tlv35 = (int)(tlv6); }
    {int tlv34; tlv34 = (int)(tlv6); }
    {void * tlv13; tlv13 = (void *)(tlv6); }
    {cgc_size_t tlv12; tlv12 = (cgc_size_t)(tlv6); }
    {char tlv39; tlv39 = (char)(tlv6); }
    {int tlv41; tlv41 = (int)(tlv6); }
    {int tlv46; tlv46 = (int)(tlv6); }
    {int tlv45; tlv45 = (int)(tlv6); }
    {void * tlv15; tlv15 = (void *)(tlv6); }
    {cgc_size_t tlv14; tlv14 = (cgc_size_t)(tlv6); }
    {int tlv52; tlv52 = (int)(tlv6); }
    {int tlv51; tlv51 = (int)(tlv6); }
    {void * tlv17; tlv17 = (void *)(tlv6); }
    {cgc_size_t tlv16; tlv16 = (cgc_size_t)(tlv6); }
    {int tlv58; tlv58 = (int)(tlv6); }
    {int tlv57; tlv57 = (int)(tlv6); }
    {void * tlv19; tlv19 = (void *)(tlv6); }
    {cgc_size_t tlv18; tlv18 = (cgc_size_t)(tlv6); }
    {int tlv64; tlv64 = (int)(tlv6); }
    {int tlv63; tlv63 = (int)(tlv6); }
    {void * tlv21; tlv21 = (void *)(tlv6); }
    {cgc_size_t tlv20; tlv20 = (cgc_size_t)(tlv6); }
    {char tlv67; tlv67 = (char)(tlv6); }
    {int tlv69; tlv69 = (int)(tlv6); }
    {char tlv71; tlv71 = (char)(tlv6); }
    {int tlv73; tlv73 = (int)(tlv6); }
    {int tlv77; tlv77 = (int)(tlv6); }
    {int tlv76; tlv76 = (int)(tlv6); }
    {void * tlv23; tlv23 = (void *)(tlv6); }
    {cgc_size_t tlv22; tlv22 = (cgc_size_t)(tlv6); }
    {char tlv81; tlv81 = (char)(tlv6); }
    {int tlv24; tlv24 = (int)(tlv6); }
    {void * tlv84; tlv84 = (void *)(tlv6); }
    {cgc_size_t tlv83; tlv83 = (cgc_size_t)(tlv6); }
    {char * tlv113; tlv113 = (char *)(tlv6); }
    {char * tlv114; tlv114 = (char *)(tlv6); }
    {void * tlv90; tlv90 = (void *)(tlv6); }
    {cgc_size_t tlv89; tlv89 = (cgc_size_t)(tlv6); }
    {void * tlv111; tlv111 = (void *)(tlv6); }
    {cgc_size_t tlv110; tlv110 = (cgc_size_t)(tlv6); }
    {char * tlv115; tlv115 = (char *)(tlv6); }
    {char * tlv116; tlv116 = (char *)(tlv6); }
}
void fix_ingred_genericParsers_0_27(){
fix_ingred_genericParsers_0_27_5();
}
void fix_ingred_genericParsers_0_39_1(){
int end;
    bzero(&end,sizeof(int));
int start;
    bzero(&start,sizeof(int));
    {char * temp; temp = (char *)(( end - start ) + 1); }
    {int tlv1; tlv1 = (int)(( end - start ) + 1); }
    {int tlv2; tlv2 = (int)(( end - start ) + 1); }
    {int tlv3; tlv3 = (int)(( end - start ) + 1); }
    {int tlv4; tlv4 = (int)(( end - start ) + 1); }
    {int tlv5; tlv5 = (int)(( end - start ) + 1); }
    {int tlv6; tlv6 = (int)(( end - start ) + 1); }
    {int tlv7; tlv7 = (int)(( end - start ) + 1); }
    {int tlv8; tlv8 = (int)(( end - start ) + 1); }
    {int tlv9; tlv9 = (int)(( end - start ) + 1); }
    {int tlv10; tlv10 = (int)(( end - start ) + 1); }
    {int tlv11; tlv11 = (int)(( end - start ) + 1); }
    {cgc_size_t tlv28; tlv28 = (cgc_size_t)(( end - start ) + 1); }
    {int tlv27; tlv27 = (int)(( end - start ) + 1); }
    {char tlv29; tlv29 = (char)(( end - start ) + 1); }
    {int tlv31; tlv31 = (int)(( end - start ) + 1); }
    {int tlv35; tlv35 = (int)(( end - start ) + 1); }
    {int tlv34; tlv34 = (int)(( end - start ) + 1); }
    {void * tlv13; tlv13 = (void *)(( end - start ) + 1); }
    {cgc_size_t tlv12; tlv12 = (cgc_size_t)(( end - start ) + 1); }
    {char tlv39; tlv39 = (char)(( end - start ) + 1); }
    {int tlv41; tlv41 = (int)(( end - start ) + 1); }
    {int tlv46; tlv46 = (int)(( end - start ) + 1); }
    {int tlv45; tlv45 = (int)(( end - start ) + 1); }
    {void * tlv15; tlv15 = (void *)(( end - start ) + 1); }
    {cgc_size_t tlv14; tlv14 = (cgc_size_t)(( end - start ) + 1); }
    {int tlv52; tlv52 = (int)(( end - start ) + 1); }
    {int tlv51; tlv51 = (int)(( end - start ) + 1); }
    {void * tlv17; tlv17 = (void *)(( end - start ) + 1); }
    {cgc_size_t tlv16; tlv16 = (cgc_size_t)(( end - start ) + 1); }
    {int tlv58; tlv58 = (int)(( end - start ) + 1); }
    {int tlv57; tlv57 = (int)(( end - start ) + 1); }
    {void * tlv19; tlv19 = (void *)(( end - start ) + 1); }
    {cgc_size_t tlv18; tlv18 = (cgc_size_t)(( end - start ) + 1); }
    {int tlv64; tlv64 = (int)(( end - start ) + 1); }
    {int tlv63; tlv63 = (int)(( end - start ) + 1); }
    {void * tlv21; tlv21 = (void *)(( end - start ) + 1); }
    {cgc_size_t tlv20; tlv20 = (cgc_size_t)(( end - start ) + 1); }
    {char tlv67; tlv67 = (char)(( end - start ) + 1); }
    {int tlv69; tlv69 = (int)(( end - start ) + 1); }
    {char tlv71; tlv71 = (char)(( end - start ) + 1); }
    {int tlv73; tlv73 = (int)(( end - start ) + 1); }
    {int tlv77; tlv77 = (int)(( end - start ) + 1); }
    {int tlv76; tlv76 = (int)(( end - start ) + 1); }
    {void * tlv23; tlv23 = (void *)(( end - start ) + 1); }
    {cgc_size_t tlv22; tlv22 = (cgc_size_t)(( end - start ) + 1); }
    {char tlv81; tlv81 = (char)(( end - start ) + 1); }
    {int tlv24; tlv24 = (int)(( end - start ) + 1); }
    {void * tlv84; tlv84 = (void *)(( end - start ) + 1); }
    {cgc_size_t tlv83; tlv83 = (cgc_size_t)(( end - start ) + 1); }
    {char * tlv113; tlv113 = (char *)(( end - start ) + 1); }
    {char * tlv114; tlv114 = (char *)(( end - start ) + 1); }
    {void * tlv90; tlv90 = (void *)(( end - start ) + 1); }
    {cgc_size_t tlv89; tlv89 = (cgc_size_t)(( end - start ) + 1); }
    {void * tlv111; tlv111 = (void *)(( end - start ) + 1); }
    {cgc_size_t tlv110; tlv110 = (cgc_size_t)(( end - start ) + 1); }
    {char * tlv115; tlv115 = (char *)(( end - start ) + 1); }
    {char * tlv116; tlv116 = (char *)(( end - start ) + 1); }
}
void fix_ingred_genericParsers_0_39(){
fix_ingred_genericParsers_0_39_1();
}
void fix_ingred_genericParsers_0_77_5(){
int tlv8;
    bzero(&tlv8,sizeof(int));
    {char * temp; temp = (char *)(tlv8); }
    {int start; start = (int)(tlv8); }
    {int end; end = (int)(tlv8); }
    {int tlv1; tlv1 = (int)(tlv8); }
    {int tlv2; tlv2 = (int)(tlv8); }
    {int tlv3; tlv3 = (int)(tlv8); }
    {int tlv4; tlv4 = (int)(tlv8); }
    {int tlv5; tlv5 = (int)(tlv8); }
    {int tlv6; tlv6 = (int)(tlv8); }
    {int tlv7; tlv7 = (int)(tlv8); }
    {int tlv9; tlv9 = (int)(tlv8); }
    {int tlv10; tlv10 = (int)(tlv8); }
    {int tlv11; tlv11 = (int)(tlv8); }
    {cgc_size_t tlv28; tlv28 = (cgc_size_t)(tlv8); }
    {int tlv27; tlv27 = (int)(tlv8); }
    {char tlv29; tlv29 = (char)(tlv8); }
    {int tlv31; tlv31 = (int)(tlv8); }
    {int tlv35; tlv35 = (int)(tlv8); }
    {int tlv34; tlv34 = (int)(tlv8); }
    {void * tlv13; tlv13 = (void *)(tlv8); }
    {cgc_size_t tlv12; tlv12 = (cgc_size_t)(tlv8); }
    {char tlv39; tlv39 = (char)(tlv8); }
    {int tlv41; tlv41 = (int)(tlv8); }
    {int tlv46; tlv46 = (int)(tlv8); }
    {int tlv45; tlv45 = (int)(tlv8); }
    {void * tlv15; tlv15 = (void *)(tlv8); }
    {cgc_size_t tlv14; tlv14 = (cgc_size_t)(tlv8); }
    {int tlv52; tlv52 = (int)(tlv8); }
    {int tlv51; tlv51 = (int)(tlv8); }
    {void * tlv17; tlv17 = (void *)(tlv8); }
    {cgc_size_t tlv16; tlv16 = (cgc_size_t)(tlv8); }
    {int tlv58; tlv58 = (int)(tlv8); }
    {int tlv57; tlv57 = (int)(tlv8); }
    {void * tlv19; tlv19 = (void *)(tlv8); }
    {cgc_size_t tlv18; tlv18 = (cgc_size_t)(tlv8); }
    {int tlv64; tlv64 = (int)(tlv8); }
    {int tlv63; tlv63 = (int)(tlv8); }
    {void * tlv21; tlv21 = (void *)(tlv8); }
    {cgc_size_t tlv20; tlv20 = (cgc_size_t)(tlv8); }
    {char tlv67; tlv67 = (char)(tlv8); }
    {int tlv69; tlv69 = (int)(tlv8); }
    {char tlv71; tlv71 = (char)(tlv8); }
    {int tlv73; tlv73 = (int)(tlv8); }
    {int tlv77; tlv77 = (int)(tlv8); }
    {int tlv76; tlv76 = (int)(tlv8); }
    {void * tlv23; tlv23 = (void *)(tlv8); }
    {cgc_size_t tlv22; tlv22 = (cgc_size_t)(tlv8); }
    {char tlv81; tlv81 = (char)(tlv8); }
    {int tlv24; tlv24 = (int)(tlv8); }
    {void * tlv84; tlv84 = (void *)(tlv8); }
    {cgc_size_t tlv83; tlv83 = (cgc_size_t)(tlv8); }
    {char * tlv113; tlv113 = (char *)(tlv8); }
    {char * tlv114; tlv114 = (char *)(tlv8); }
    {void * tlv90; tlv90 = (void *)(tlv8); }
    {cgc_size_t tlv89; tlv89 = (cgc_size_t)(tlv8); }
    {void * tlv111; tlv111 = (void *)(tlv8); }
    {cgc_size_t tlv110; tlv110 = (cgc_size_t)(tlv8); }
    {char * tlv115; tlv115 = (char *)(tlv8); }
    {char * tlv116; tlv116 = (char *)(tlv8); }
}
void fix_ingred_genericParsers_0_77(){
fix_ingred_genericParsers_0_77_5();
}
void fix_ingred_genericParsers_0_79_1(){
    {char * temp; temp = (char *)('#'); }
    {int start; start = (int)('#'); }
    {int end; end = (int)('#'); }
    {int tlv1; tlv1 = (int)('#'); }
    {int tlv2; tlv2 = (int)('#'); }
    {int tlv3; tlv3 = (int)('#'); }
    {int tlv4; tlv4 = (int)('#'); }
    {int tlv5; tlv5 = (int)('#'); }
    {int tlv6; tlv6 = (int)('#'); }
    {int tlv7; tlv7 = (int)('#'); }
    {int tlv8; tlv8 = (int)('#'); }
    {int tlv9; tlv9 = (int)('#'); }
    {int tlv10; tlv10 = (int)('#'); }
    {int tlv11; tlv11 = (int)('#'); }
    {cgc_size_t tlv28; tlv28 = (cgc_size_t)('#'); }
    {int tlv27; tlv27 = (int)('#'); }
    {char tlv29; tlv29 = (char)('#'); }
    {int tlv31; tlv31 = (int)('#'); }
    {int tlv35; tlv35 = (int)('#'); }
    {int tlv34; tlv34 = (int)('#'); }
    {void * tlv13; tlv13 = (void *)('#'); }
    {cgc_size_t tlv12; tlv12 = (cgc_size_t)('#'); }
    {char tlv39; tlv39 = (char)('#'); }
    {int tlv41; tlv41 = (int)('#'); }
    {int tlv46; tlv46 = (int)('#'); }
    {int tlv45; tlv45 = (int)('#'); }
    {void * tlv15; tlv15 = (void *)('#'); }
    {cgc_size_t tlv14; tlv14 = (cgc_size_t)('#'); }
    {int tlv52; tlv52 = (int)('#'); }
    {int tlv51; tlv51 = (int)('#'); }
    {void * tlv17; tlv17 = (void *)('#'); }
    {cgc_size_t tlv16; tlv16 = (cgc_size_t)('#'); }
    {int tlv58; tlv58 = (int)('#'); }
    {int tlv57; tlv57 = (int)('#'); }
    {void * tlv19; tlv19 = (void *)('#'); }
    {cgc_size_t tlv18; tlv18 = (cgc_size_t)('#'); }
    {int tlv64; tlv64 = (int)('#'); }
    {int tlv63; tlv63 = (int)('#'); }
    {void * tlv21; tlv21 = (void *)('#'); }
    {cgc_size_t tlv20; tlv20 = (cgc_size_t)('#'); }
    {char tlv67; tlv67 = (char)('#'); }
    {int tlv69; tlv69 = (int)('#'); }
    {char tlv71; tlv71 = (char)('#'); }
    {int tlv73; tlv73 = (int)('#'); }
    {int tlv77; tlv77 = (int)('#'); }
    {int tlv76; tlv76 = (int)('#'); }
    {void * tlv23; tlv23 = (void *)('#'); }
    {cgc_size_t tlv22; tlv22 = (cgc_size_t)('#'); }
    {char tlv81; tlv81 = (char)('#'); }
    {int tlv24; tlv24 = (int)('#'); }
    {void * tlv84; tlv84 = (void *)('#'); }
    {cgc_size_t tlv83; tlv83 = (cgc_size_t)('#'); }
    {char * tlv113; tlv113 = (char *)('#'); }
    {char * tlv114; tlv114 = (char *)('#'); }
    {void * tlv90; tlv90 = (void *)('#'); }
    {cgc_size_t tlv89; tlv89 = (cgc_size_t)('#'); }
    {void * tlv111; tlv111 = (void *)('#'); }
    {cgc_size_t tlv110; tlv110 = (cgc_size_t)('#'); }
    {char * tlv115; tlv115 = (char *)('#'); }
    {char * tlv116; tlv116 = (char *)('#'); }
}
void fix_ingred_genericParsers_0_79(){
fix_ingred_genericParsers_0_79_1();
}
void fix_ingred_genericParsers_0_90_5(){
int tlv10;
    bzero(&tlv10,sizeof(int));
    {char * temp; temp = (char *)(tlv10); }
    {int start; start = (int)(tlv10); }
    {int end; end = (int)(tlv10); }
    {int tlv1; tlv1 = (int)(tlv10); }
    {int tlv2; tlv2 = (int)(tlv10); }
    {int tlv3; tlv3 = (int)(tlv10); }
    {int tlv4; tlv4 = (int)(tlv10); }
    {int tlv5; tlv5 = (int)(tlv10); }
    {int tlv6; tlv6 = (int)(tlv10); }
    {int tlv7; tlv7 = (int)(tlv10); }
    {int tlv8; tlv8 = (int)(tlv10); }
    {int tlv9; tlv9 = (int)(tlv10); }
    {int tlv11; tlv11 = (int)(tlv10); }
    {cgc_size_t tlv28; tlv28 = (cgc_size_t)(tlv10); }
    {int tlv27; tlv27 = (int)(tlv10); }
    {char tlv29; tlv29 = (char)(tlv10); }
    {int tlv31; tlv31 = (int)(tlv10); }
    {int tlv35; tlv35 = (int)(tlv10); }
    {int tlv34; tlv34 = (int)(tlv10); }
    {void * tlv13; tlv13 = (void *)(tlv10); }
    {cgc_size_t tlv12; tlv12 = (cgc_size_t)(tlv10); }
    {char tlv39; tlv39 = (char)(tlv10); }
    {int tlv41; tlv41 = (int)(tlv10); }
    {int tlv46; tlv46 = (int)(tlv10); }
    {int tlv45; tlv45 = (int)(tlv10); }
    {void * tlv15; tlv15 = (void *)(tlv10); }
    {cgc_size_t tlv14; tlv14 = (cgc_size_t)(tlv10); }
    {int tlv52; tlv52 = (int)(tlv10); }
    {int tlv51; tlv51 = (int)(tlv10); }
    {void * tlv17; tlv17 = (void *)(tlv10); }
    {cgc_size_t tlv16; tlv16 = (cgc_size_t)(tlv10); }
    {int tlv58; tlv58 = (int)(tlv10); }
    {int tlv57; tlv57 = (int)(tlv10); }
    {void * tlv19; tlv19 = (void *)(tlv10); }
    {cgc_size_t tlv18; tlv18 = (cgc_size_t)(tlv10); }
    {int tlv64; tlv64 = (int)(tlv10); }
    {int tlv63; tlv63 = (int)(tlv10); }
    {void * tlv21; tlv21 = (void *)(tlv10); }
    {cgc_size_t tlv20; tlv20 = (cgc_size_t)(tlv10); }
    {char tlv67; tlv67 = (char)(tlv10); }
    {int tlv69; tlv69 = (int)(tlv10); }
    {char tlv71; tlv71 = (char)(tlv10); }
    {int tlv73; tlv73 = (int)(tlv10); }
    {int tlv77; tlv77 = (int)(tlv10); }
    {int tlv76; tlv76 = (int)(tlv10); }
    {void * tlv23; tlv23 = (void *)(tlv10); }
    {cgc_size_t tlv22; tlv22 = (cgc_size_t)(tlv10); }
    {char tlv81; tlv81 = (char)(tlv10); }
    {int tlv24; tlv24 = (int)(tlv10); }
    {void * tlv84; tlv84 = (void *)(tlv10); }
    {cgc_size_t tlv83; tlv83 = (cgc_size_t)(tlv10); }
    {char * tlv113; tlv113 = (char *)(tlv10); }
    {char * tlv114; tlv114 = (char *)(tlv10); }
    {void * tlv90; tlv90 = (void *)(tlv10); }
    {cgc_size_t tlv89; tlv89 = (cgc_size_t)(tlv10); }
    {void * tlv111; tlv111 = (void *)(tlv10); }
    {cgc_size_t tlv110; tlv110 = (cgc_size_t)(tlv10); }
    {char * tlv115; tlv115 = (char *)(tlv10); }
    {char * tlv116; tlv116 = (char *)(tlv10); }
}
void fix_ingred_genericParsers_0_90(){
fix_ingred_genericParsers_0_90_5();
}
void fix_ingred_genericParsers_0_92_1(){
char tlv116_ref;
    bzero(&tlv116_ref,1*sizeof(char));
char * tlv116 = &tlv116_ref;
    {char * temp; temp = (char *)(cgc_strlen ( tlv116 ) + 1); }
    {int start; start = (int)(cgc_strlen ( tlv116 ) + 1); }
    {int end; end = (int)(cgc_strlen ( tlv116 ) + 1); }
    {int tlv1; tlv1 = (int)(cgc_strlen ( tlv116 ) + 1); }
    {int tlv2; tlv2 = (int)(cgc_strlen ( tlv116 ) + 1); }
    {int tlv3; tlv3 = (int)(cgc_strlen ( tlv116 ) + 1); }
    {int tlv4; tlv4 = (int)(cgc_strlen ( tlv116 ) + 1); }
    {int tlv5; tlv5 = (int)(cgc_strlen ( tlv116 ) + 1); }
    {int tlv6; tlv6 = (int)(cgc_strlen ( tlv116 ) + 1); }
    {int tlv7; tlv7 = (int)(cgc_strlen ( tlv116 ) + 1); }
    {int tlv8; tlv8 = (int)(cgc_strlen ( tlv116 ) + 1); }
    {int tlv9; tlv9 = (int)(cgc_strlen ( tlv116 ) + 1); }
    {int tlv10; tlv10 = (int)(cgc_strlen ( tlv116 ) + 1); }
    {int tlv11; tlv11 = (int)(cgc_strlen ( tlv116 ) + 1); }
    {cgc_size_t tlv28; tlv28 = (cgc_size_t)(cgc_strlen ( tlv116 ) + 1); }
    {int tlv27; tlv27 = (int)(cgc_strlen ( tlv116 ) + 1); }
    {char tlv29; tlv29 = (char)(cgc_strlen ( tlv116 ) + 1); }
    {int tlv31; tlv31 = (int)(cgc_strlen ( tlv116 ) + 1); }
    {int tlv35; tlv35 = (int)(cgc_strlen ( tlv116 ) + 1); }
    {int tlv34; tlv34 = (int)(cgc_strlen ( tlv116 ) + 1); }
    {void * tlv13; tlv13 = (void *)(cgc_strlen ( tlv116 ) + 1); }
    {cgc_size_t tlv12; tlv12 = (cgc_size_t)(cgc_strlen ( tlv116 ) + 1); }
    {char tlv39; tlv39 = (char)(cgc_strlen ( tlv116 ) + 1); }
    {int tlv41; tlv41 = (int)(cgc_strlen ( tlv116 ) + 1); }
    {int tlv46; tlv46 = (int)(cgc_strlen ( tlv116 ) + 1); }
    {int tlv45; tlv45 = (int)(cgc_strlen ( tlv116 ) + 1); }
    {void * tlv15; tlv15 = (void *)(cgc_strlen ( tlv116 ) + 1); }
    {cgc_size_t tlv14; tlv14 = (cgc_size_t)(cgc_strlen ( tlv116 ) + 1); }
    {int tlv52; tlv52 = (int)(cgc_strlen ( tlv116 ) + 1); }
    {int tlv51; tlv51 = (int)(cgc_strlen ( tlv116 ) + 1); }
    {void * tlv17; tlv17 = (void *)(cgc_strlen ( tlv116 ) + 1); }
    {cgc_size_t tlv16; tlv16 = (cgc_size_t)(cgc_strlen ( tlv116 ) + 1); }
    {int tlv58; tlv58 = (int)(cgc_strlen ( tlv116 ) + 1); }
    {int tlv57; tlv57 = (int)(cgc_strlen ( tlv116 ) + 1); }
    {void * tlv19; tlv19 = (void *)(cgc_strlen ( tlv116 ) + 1); }
    {cgc_size_t tlv18; tlv18 = (cgc_size_t)(cgc_strlen ( tlv116 ) + 1); }
    {int tlv64; tlv64 = (int)(cgc_strlen ( tlv116 ) + 1); }
    {int tlv63; tlv63 = (int)(cgc_strlen ( tlv116 ) + 1); }
    {void * tlv21; tlv21 = (void *)(cgc_strlen ( tlv116 ) + 1); }
    {cgc_size_t tlv20; tlv20 = (cgc_size_t)(cgc_strlen ( tlv116 ) + 1); }
    {char tlv67; tlv67 = (char)(cgc_strlen ( tlv116 ) + 1); }
    {int tlv69; tlv69 = (int)(cgc_strlen ( tlv116 ) + 1); }
    {char tlv71; tlv71 = (char)(cgc_strlen ( tlv116 ) + 1); }
    {int tlv73; tlv73 = (int)(cgc_strlen ( tlv116 ) + 1); }
    {int tlv77; tlv77 = (int)(cgc_strlen ( tlv116 ) + 1); }
    {int tlv76; tlv76 = (int)(cgc_strlen ( tlv116 ) + 1); }
    {void * tlv23; tlv23 = (void *)(cgc_strlen ( tlv116 ) + 1); }
    {cgc_size_t tlv22; tlv22 = (cgc_size_t)(cgc_strlen ( tlv116 ) + 1); }
    {char tlv81; tlv81 = (char)(cgc_strlen ( tlv116 ) + 1); }
    {int tlv24; tlv24 = (int)(cgc_strlen ( tlv116 ) + 1); }
    {void * tlv84; tlv84 = (void *)(cgc_strlen ( tlv116 ) + 1); }
    {cgc_size_t tlv83; tlv83 = (cgc_size_t)(cgc_strlen ( tlv116 ) + 1); }
    {char * tlv113; tlv113 = (char *)(cgc_strlen ( tlv116 ) + 1); }
    {char * tlv114; tlv114 = (char *)(cgc_strlen ( tlv116 ) + 1); }
    {void * tlv90; tlv90 = (void *)(cgc_strlen ( tlv116 ) + 1); }
    {cgc_size_t tlv89; tlv89 = (cgc_size_t)(cgc_strlen ( tlv116 ) + 1); }
    {void * tlv111; tlv111 = (void *)(cgc_strlen ( tlv116 ) + 1); }
    {cgc_size_t tlv110; tlv110 = (cgc_size_t)(cgc_strlen ( tlv116 ) + 1); }
    {char * tlv115; tlv115 = (char *)(cgc_strlen ( tlv116 ) + 1); }
}
void fix_ingred_genericParsers_0_92(){
fix_ingred_genericParsers_0_92_1();
}
void fix_ingred_genericParsers_0_94_1(){
char tlv114_ref;
    bzero(&tlv114_ref,1*sizeof(char));
char * tlv114 = &tlv114_ref;
    {char * temp; temp = (char *)(cgc_strlen ( tlv114 ) + 1); }
    {int start; start = (int)(cgc_strlen ( tlv114 ) + 1); }
    {int end; end = (int)(cgc_strlen ( tlv114 ) + 1); }
    {int tlv1; tlv1 = (int)(cgc_strlen ( tlv114 ) + 1); }
    {int tlv2; tlv2 = (int)(cgc_strlen ( tlv114 ) + 1); }
    {int tlv3; tlv3 = (int)(cgc_strlen ( tlv114 ) + 1); }
    {int tlv4; tlv4 = (int)(cgc_strlen ( tlv114 ) + 1); }
    {int tlv5; tlv5 = (int)(cgc_strlen ( tlv114 ) + 1); }
    {int tlv6; tlv6 = (int)(cgc_strlen ( tlv114 ) + 1); }
    {int tlv7; tlv7 = (int)(cgc_strlen ( tlv114 ) + 1); }
    {int tlv8; tlv8 = (int)(cgc_strlen ( tlv114 ) + 1); }
    {int tlv9; tlv9 = (int)(cgc_strlen ( tlv114 ) + 1); }
    {int tlv10; tlv10 = (int)(cgc_strlen ( tlv114 ) + 1); }
    {int tlv11; tlv11 = (int)(cgc_strlen ( tlv114 ) + 1); }
    {cgc_size_t tlv28; tlv28 = (cgc_size_t)(cgc_strlen ( tlv114 ) + 1); }
    {int tlv27; tlv27 = (int)(cgc_strlen ( tlv114 ) + 1); }
    {char tlv29; tlv29 = (char)(cgc_strlen ( tlv114 ) + 1); }
    {int tlv31; tlv31 = (int)(cgc_strlen ( tlv114 ) + 1); }
    {int tlv35; tlv35 = (int)(cgc_strlen ( tlv114 ) + 1); }
    {int tlv34; tlv34 = (int)(cgc_strlen ( tlv114 ) + 1); }
    {void * tlv13; tlv13 = (void *)(cgc_strlen ( tlv114 ) + 1); }
    {cgc_size_t tlv12; tlv12 = (cgc_size_t)(cgc_strlen ( tlv114 ) + 1); }
    {char tlv39; tlv39 = (char)(cgc_strlen ( tlv114 ) + 1); }
    {int tlv41; tlv41 = (int)(cgc_strlen ( tlv114 ) + 1); }
    {int tlv46; tlv46 = (int)(cgc_strlen ( tlv114 ) + 1); }
    {int tlv45; tlv45 = (int)(cgc_strlen ( tlv114 ) + 1); }
    {void * tlv15; tlv15 = (void *)(cgc_strlen ( tlv114 ) + 1); }
    {cgc_size_t tlv14; tlv14 = (cgc_size_t)(cgc_strlen ( tlv114 ) + 1); }
    {int tlv52; tlv52 = (int)(cgc_strlen ( tlv114 ) + 1); }
    {int tlv51; tlv51 = (int)(cgc_strlen ( tlv114 ) + 1); }
    {void * tlv17; tlv17 = (void *)(cgc_strlen ( tlv114 ) + 1); }
    {cgc_size_t tlv16; tlv16 = (cgc_size_t)(cgc_strlen ( tlv114 ) + 1); }
    {int tlv58; tlv58 = (int)(cgc_strlen ( tlv114 ) + 1); }
    {int tlv57; tlv57 = (int)(cgc_strlen ( tlv114 ) + 1); }
    {void * tlv19; tlv19 = (void *)(cgc_strlen ( tlv114 ) + 1); }
    {cgc_size_t tlv18; tlv18 = (cgc_size_t)(cgc_strlen ( tlv114 ) + 1); }
    {int tlv64; tlv64 = (int)(cgc_strlen ( tlv114 ) + 1); }
    {int tlv63; tlv63 = (int)(cgc_strlen ( tlv114 ) + 1); }
    {void * tlv21; tlv21 = (void *)(cgc_strlen ( tlv114 ) + 1); }
    {cgc_size_t tlv20; tlv20 = (cgc_size_t)(cgc_strlen ( tlv114 ) + 1); }
    {char tlv67; tlv67 = (char)(cgc_strlen ( tlv114 ) + 1); }
    {int tlv69; tlv69 = (int)(cgc_strlen ( tlv114 ) + 1); }
    {char tlv71; tlv71 = (char)(cgc_strlen ( tlv114 ) + 1); }
    {int tlv73; tlv73 = (int)(cgc_strlen ( tlv114 ) + 1); }
    {int tlv77; tlv77 = (int)(cgc_strlen ( tlv114 ) + 1); }
    {int tlv76; tlv76 = (int)(cgc_strlen ( tlv114 ) + 1); }
    {void * tlv23; tlv23 = (void *)(cgc_strlen ( tlv114 ) + 1); }
    {cgc_size_t tlv22; tlv22 = (cgc_size_t)(cgc_strlen ( tlv114 ) + 1); }
    {char tlv81; tlv81 = (char)(cgc_strlen ( tlv114 ) + 1); }
    {int tlv24; tlv24 = (int)(cgc_strlen ( tlv114 ) + 1); }
    {void * tlv84; tlv84 = (void *)(cgc_strlen ( tlv114 ) + 1); }
    {cgc_size_t tlv83; tlv83 = (cgc_size_t)(cgc_strlen ( tlv114 ) + 1); }
    {char * tlv113; tlv113 = (char *)(cgc_strlen ( tlv114 ) + 1); }
    {void * tlv90; tlv90 = (void *)(cgc_strlen ( tlv114 ) + 1); }
    {cgc_size_t tlv89; tlv89 = (cgc_size_t)(cgc_strlen ( tlv114 ) + 1); }
    {void * tlv111; tlv111 = (void *)(cgc_strlen ( tlv114 ) + 1); }
    {cgc_size_t tlv110; tlv110 = (cgc_size_t)(cgc_strlen ( tlv114 ) + 1); }
    {char * tlv115; tlv115 = (char *)(cgc_strlen ( tlv114 ) + 1); }
    {char * tlv116; tlv116 = (char *)(cgc_strlen ( tlv114 ) + 1); }
}
void fix_ingred_genericParsers_0_94(){
fix_ingred_genericParsers_0_94_1();
}
void fix_ingred_genericParsers_0_99_0(){
Border bor_ref;
    bzero(&bor_ref,1*sizeof(Border));
pBorder bor = &bor_ref;
    {char * temp; temp = (char *)(bor); }
    {int start; start = (int)(bor); }
    {int end; end = (int)(bor); }
    {int tlv1; tlv1 = (int)(bor); }
    {int tlv2; tlv2 = (int)(bor); }
    {int tlv3; tlv3 = (int)(bor); }
    {int tlv4; tlv4 = (int)(bor); }
    {int tlv5; tlv5 = (int)(bor); }
    {int tlv6; tlv6 = (int)(bor); }
    {int tlv7; tlv7 = (int)(bor); }
    {int tlv8; tlv8 = (int)(bor); }
    {int tlv9; tlv9 = (int)(bor); }
    {int tlv10; tlv10 = (int)(bor); }
    {int tlv11; tlv11 = (int)(bor); }
    {cgc_size_t tlv28; tlv28 = (cgc_size_t)(bor); }
    {int tlv27; tlv27 = (int)(bor); }
    {char tlv29; tlv29 = (char)(bor); }
    {int tlv31; tlv31 = (int)(bor); }
    {int tlv35; tlv35 = (int)(bor); }
    {int tlv34; tlv34 = (int)(bor); }
    {void * tlv13; tlv13 = (void *)(bor); }
    {cgc_size_t tlv12; tlv12 = (cgc_size_t)(bor); }
    {char tlv39; tlv39 = (char)(bor); }
    {int tlv41; tlv41 = (int)(bor); }
    {int tlv46; tlv46 = (int)(bor); }
    {int tlv45; tlv45 = (int)(bor); }
    {void * tlv15; tlv15 = (void *)(bor); }
    {cgc_size_t tlv14; tlv14 = (cgc_size_t)(bor); }
    {int tlv52; tlv52 = (int)(bor); }
    {int tlv51; tlv51 = (int)(bor); }
    {void * tlv17; tlv17 = (void *)(bor); }
    {cgc_size_t tlv16; tlv16 = (cgc_size_t)(bor); }
    {int tlv58; tlv58 = (int)(bor); }
    {int tlv57; tlv57 = (int)(bor); }
    {void * tlv19; tlv19 = (void *)(bor); }
    {cgc_size_t tlv18; tlv18 = (cgc_size_t)(bor); }
    {int tlv64; tlv64 = (int)(bor); }
    {int tlv63; tlv63 = (int)(bor); }
    {void * tlv21; tlv21 = (void *)(bor); }
    {cgc_size_t tlv20; tlv20 = (cgc_size_t)(bor); }
    {char tlv67; tlv67 = (char)(bor); }
    {int tlv69; tlv69 = (int)(bor); }
    {char tlv71; tlv71 = (char)(bor); }
    {int tlv73; tlv73 = (int)(bor); }
    {int tlv77; tlv77 = (int)(bor); }
    {int tlv76; tlv76 = (int)(bor); }
    {void * tlv23; tlv23 = (void *)(bor); }
    {cgc_size_t tlv22; tlv22 = (cgc_size_t)(bor); }
    {char tlv81; tlv81 = (char)(bor); }
    {int tlv24; tlv24 = (int)(bor); }
    {void * tlv84; tlv84 = (void *)(bor); }
    {cgc_size_t tlv83; tlv83 = (cgc_size_t)(bor); }
    {char * tlv113; tlv113 = (char *)(bor); }
    {char * tlv114; tlv114 = (char *)(bor); }
    {void * tlv90; tlv90 = (void *)(bor); }
    {cgc_size_t tlv89; tlv89 = (cgc_size_t)(bor); }
    {void * tlv111; tlv111 = (void *)(bor); }
    {cgc_size_t tlv110; tlv110 = (cgc_size_t)(bor); }
    {char * tlv115; tlv115 = (char *)(bor); }
    {char * tlv116; tlv116 = (char *)(bor); }
}
void fix_ingred_genericParsers_0_99(){
fix_ingred_genericParsers_0_99_0();
}
void fix_ingred_genericParsers_0(){
fix_ingred_genericParsers_0_0();
fix_ingred_genericParsers_0_2();
fix_ingred_genericParsers_0_3();
fix_ingred_genericParsers_0_4();
fix_ingred_genericParsers_0_7();
fix_ingred_genericParsers_0_8();
fix_ingred_genericParsers_0_11();
fix_ingred_genericParsers_0_13();
fix_ingred_genericParsers_0_15();
fix_ingred_genericParsers_0_17();
fix_ingred_genericParsers_0_19();
fix_ingred_genericParsers_0_20();
fix_ingred_genericParsers_0_22();
fix_ingred_genericParsers_0_23();
fix_ingred_genericParsers_0_27();
fix_ingred_genericParsers_0_39();
fix_ingred_genericParsers_0_77();
fix_ingred_genericParsers_0_79();
fix_ingred_genericParsers_0_90();
fix_ingred_genericParsers_0_92();
fix_ingred_genericParsers_0_94();
fix_ingred_genericParsers_0_99();
}
void fix_ingred_genericParsers_1_0_0(){
string str_ref;
    bzero(&str_ref,1*sizeof(string));
pstring str = &str_ref;
    {int pop; pop = (int)(NULL); }
    {int ps; ps = (int)(NULL); }
    {int pe; pe = (int)(NULL); }
    {char tlv19; tlv19 = (char)(NULL); }
    {int tlv21; tlv21 = (int)(NULL); }
    {int tlv25; tlv25 = (int)(NULL); }
    {void * tlv12; tlv12 = (void *)(NULL); }
    {cgc_size_t tlv11; tlv11 = (cgc_size_t)(NULL); }
    {char tlv34; tlv34 = (char)(NULL); }
    {int tlv36; tlv36 = (int)(NULL); }
    {char tlv38; tlv38 = (char)(NULL); }
    {int tlv40; tlv40 = (int)(NULL); }
    {int tlv44; tlv44 = (int)(NULL); }
    {int tlv43; tlv43 = (int)(NULL); }
    {void * tlv14; tlv14 = (void *)(NULL); }
    {cgc_size_t tlv13; tlv13 = (cgc_size_t)(NULL); }
    {char tlv48; tlv48 = (char)(NULL); }
    {int tlv15; tlv15 = (int)(NULL); }
    {int tlv50; tlv50 = (int)(NULL); }
    {void * tlv18; tlv18 = (void *)(NULL); }
    {cgc_size_t tlv17; tlv17 = (cgc_size_t)(NULL); }
    {char * tlv72; tlv72 = (char *)(NULL); }
    {char * tlv73; tlv73 = (char *)(NULL); }
    {char * tlv74; tlv74 = (char *)(NULL); }
    {void * tlv59; tlv59 = (void *)(NULL); }
    {cgc_size_t tlv58; tlv58 = (cgc_size_t)(NULL); }
    {void * tlv69; tlv69 = (void *)(NULL); }
    {cgc_size_t tlv68; tlv68 = (cgc_size_t)(NULL); }
    {char * tlv75; tlv75 = (char *)(NULL); }
    {char * tlv76; tlv76 = (char *)(NULL); }
}
void fix_ingred_genericParsers_1_0_1(){
string str_ref;
    bzero(&str_ref,1*sizeof(string));
pstring str = &str_ref;
    {int pop; pop = (int)(- 1); }
    {int ps; ps = (int)(- 1); }
    {int pe; pe = (int)(- 1); }
    {char tlv19; tlv19 = (char)(- 1); }
    {int tlv21; tlv21 = (int)(- 1); }
    {int tlv25; tlv25 = (int)(- 1); }
    {void * tlv12; tlv12 = (void *)(- 1); }
    {cgc_size_t tlv11; tlv11 = (cgc_size_t)(- 1); }
    {char tlv34; tlv34 = (char)(- 1); }
    {int tlv36; tlv36 = (int)(- 1); }
    {char tlv38; tlv38 = (char)(- 1); }
    {int tlv40; tlv40 = (int)(- 1); }
    {int tlv44; tlv44 = (int)(- 1); }
    {int tlv43; tlv43 = (int)(- 1); }
    {void * tlv14; tlv14 = (void *)(- 1); }
    {cgc_size_t tlv13; tlv13 = (cgc_size_t)(- 1); }
    {char tlv48; tlv48 = (char)(- 1); }
    {int tlv15; tlv15 = (int)(- 1); }
    {int tlv50; tlv50 = (int)(- 1); }
    {void * tlv18; tlv18 = (void *)(- 1); }
    {cgc_size_t tlv17; tlv17 = (cgc_size_t)(- 1); }
    {char * tlv72; tlv72 = (char *)(- 1); }
    {char * tlv73; tlv73 = (char *)(- 1); }
    {char * tlv74; tlv74 = (char *)(- 1); }
    {void * tlv59; tlv59 = (void *)(- 1); }
    {cgc_size_t tlv58; tlv58 = (cgc_size_t)(- 1); }
    {void * tlv69; tlv69 = (void *)(- 1); }
    {cgc_size_t tlv68; tlv68 = (cgc_size_t)(- 1); }
    {char * tlv75; tlv75 = (char *)(- 1); }
    {char * tlv76; tlv76 = (char *)(- 1); }
}
void fix_ingred_genericParsers_1_0_2(){
string str_ref;
    bzero(&str_ref,1*sizeof(string));
pstring str = &str_ref;
    {int pop; pop = (int)(0); }
    {int ps; ps = (int)(0); }
    {int pe; pe = (int)(0); }
    {char tlv19; tlv19 = (char)(0); }
    {int tlv21; tlv21 = (int)(0); }
    {int tlv25; tlv25 = (int)(0); }
    {void * tlv12; tlv12 = (void *)(0); }
    {cgc_size_t tlv11; tlv11 = (cgc_size_t)(0); }
    {char tlv34; tlv34 = (char)(0); }
    {int tlv36; tlv36 = (int)(0); }
    {char tlv38; tlv38 = (char)(0); }
    {int tlv40; tlv40 = (int)(0); }
    {int tlv44; tlv44 = (int)(0); }
    {int tlv43; tlv43 = (int)(0); }
    {void * tlv14; tlv14 = (void *)(0); }
    {cgc_size_t tlv13; tlv13 = (cgc_size_t)(0); }
    {char tlv48; tlv48 = (char)(0); }
    {int tlv15; tlv15 = (int)(0); }
    {int tlv50; tlv50 = (int)(0); }
    {void * tlv18; tlv18 = (void *)(0); }
    {cgc_size_t tlv17; tlv17 = (cgc_size_t)(0); }
    {char * tlv72; tlv72 = (char *)(0); }
    {char * tlv73; tlv73 = (char *)(0); }
    {char * tlv74; tlv74 = (char *)(0); }
    {void * tlv59; tlv59 = (void *)(0); }
    {cgc_size_t tlv58; tlv58 = (cgc_size_t)(0); }
    {void * tlv69; tlv69 = (void *)(0); }
    {cgc_size_t tlv68; tlv68 = (cgc_size_t)(0); }
    {char * tlv75; tlv75 = (char *)(0); }
    {char * tlv76; tlv76 = (char *)(0); }
}
void fix_ingred_genericParsers_1_0_6(){
string str_ref;
    bzero(&str_ref,1*sizeof(string));
pstring str = &str_ref;
    {int pop; pop = (int)(str -> index); }
    {int ps; ps = (int)(str -> index); }
    {int pe; pe = (int)(str -> index); }
    {char tlv19; tlv19 = (char)(str -> index); }
    {int tlv21; tlv21 = (int)(str -> index); }
    {int tlv25; tlv25 = (int)(str -> index); }
    {void * tlv12; tlv12 = (void *)(str -> index); }
    {cgc_size_t tlv11; tlv11 = (cgc_size_t)(str -> index); }
    {char tlv34; tlv34 = (char)(str -> index); }
    {int tlv36; tlv36 = (int)(str -> index); }
    {char tlv38; tlv38 = (char)(str -> index); }
    {int tlv40; tlv40 = (int)(str -> index); }
    {int tlv44; tlv44 = (int)(str -> index); }
    {int tlv43; tlv43 = (int)(str -> index); }
    {void * tlv14; tlv14 = (void *)(str -> index); }
    {cgc_size_t tlv13; tlv13 = (cgc_size_t)(str -> index); }
    {char tlv48; tlv48 = (char)(str -> index); }
    {int tlv15; tlv15 = (int)(str -> index); }
    {int tlv50; tlv50 = (int)(str -> index); }
    {void * tlv18; tlv18 = (void *)(str -> index); }
    {cgc_size_t tlv17; tlv17 = (cgc_size_t)(str -> index); }
    {char * tlv72; tlv72 = (char *)(str -> index); }
    {char * tlv73; tlv73 = (char *)(str -> index); }
    {char * tlv74; tlv74 = (char *)(str -> index); }
    {void * tlv59; tlv59 = (void *)(str -> index); }
    {cgc_size_t tlv58; tlv58 = (cgc_size_t)(str -> index); }
    {void * tlv69; tlv69 = (void *)(str -> index); }
    {cgc_size_t tlv68; tlv68 = (cgc_size_t)(str -> index); }
    {char * tlv75; tlv75 = (char *)(str -> index); }
    {char * tlv76; tlv76 = (char *)(str -> index); }
}
void fix_ingred_genericParsers_1_0(){
fix_ingred_genericParsers_1_0_0();
fix_ingred_genericParsers_1_0_1();
fix_ingred_genericParsers_1_0_2();
fix_ingred_genericParsers_1_0_6();
}
void fix_ingred_genericParsers_1_2_1(){
    {int pop; pop = (int)('{'); }
    {int ps; ps = (int)('{'); }
    {int pe; pe = (int)('{'); }
    {char tlv19; tlv19 = (char)('{'); }
    {int tlv21; tlv21 = (int)('{'); }
    {int tlv25; tlv25 = (int)('{'); }
    {void * tlv12; tlv12 = (void *)('{'); }
    {cgc_size_t tlv11; tlv11 = (cgc_size_t)('{'); }
    {char tlv34; tlv34 = (char)('{'); }
    {int tlv36; tlv36 = (int)('{'); }
    {char tlv38; tlv38 = (char)('{'); }
    {int tlv40; tlv40 = (int)('{'); }
    {int tlv44; tlv44 = (int)('{'); }
    {int tlv43; tlv43 = (int)('{'); }
    {void * tlv14; tlv14 = (void *)('{'); }
    {cgc_size_t tlv13; tlv13 = (cgc_size_t)('{'); }
    {char tlv48; tlv48 = (char)('{'); }
    {int tlv15; tlv15 = (int)('{'); }
    {int tlv50; tlv50 = (int)('{'); }
    {void * tlv18; tlv18 = (void *)('{'); }
    {cgc_size_t tlv17; tlv17 = (cgc_size_t)('{'); }
    {char * tlv72; tlv72 = (char *)('{'); }
    {char * tlv73; tlv73 = (char *)('{'); }
    {char * tlv74; tlv74 = (char *)('{'); }
    {void * tlv59; tlv59 = (void *)('{'); }
    {cgc_size_t tlv58; tlv58 = (cgc_size_t)('{'); }
    {void * tlv69; tlv69 = (void *)('{'); }
    {cgc_size_t tlv68; tlv68 = (cgc_size_t)('{'); }
    {char * tlv75; tlv75 = (char *)('{'); }
    {char * tlv76; tlv76 = (char *)('{'); }
}
void fix_ingred_genericParsers_1_2(){
fix_ingred_genericParsers_1_2_1();
}
void fix_ingred_genericParsers_1_5_1(){
    {int pop; pop = (int)(1); }
    {int ps; ps = (int)(1); }
    {int pe; pe = (int)(1); }
    {char tlv19; tlv19 = (char)(1); }
    {int tlv21; tlv21 = (int)(1); }
    {int tlv25; tlv25 = (int)(1); }
    {void * tlv12; tlv12 = (void *)(1); }
    {cgc_size_t tlv11; tlv11 = (cgc_size_t)(1); }
    {char tlv34; tlv34 = (char)(1); }
    {int tlv36; tlv36 = (int)(1); }
    {char tlv38; tlv38 = (char)(1); }
    {int tlv40; tlv40 = (int)(1); }
    {int tlv44; tlv44 = (int)(1); }
    {int tlv43; tlv43 = (int)(1); }
    {void * tlv14; tlv14 = (void *)(1); }
    {cgc_size_t tlv13; tlv13 = (cgc_size_t)(1); }
    {char tlv48; tlv48 = (char)(1); }
    {int tlv15; tlv15 = (int)(1); }
    {int tlv50; tlv50 = (int)(1); }
    {void * tlv18; tlv18 = (void *)(1); }
    {cgc_size_t tlv17; tlv17 = (cgc_size_t)(1); }
    {char * tlv72; tlv72 = (char *)(1); }
    {char * tlv73; tlv73 = (char *)(1); }
    {char * tlv74; tlv74 = (char *)(1); }
    {void * tlv59; tlv59 = (void *)(1); }
    {cgc_size_t tlv58; tlv58 = (cgc_size_t)(1); }
    {void * tlv69; tlv69 = (void *)(1); }
    {cgc_size_t tlv68; tlv68 = (cgc_size_t)(1); }
    {char * tlv75; tlv75 = (char *)(1); }
    {char * tlv76; tlv76 = (char *)(1); }
}
void fix_ingred_genericParsers_1_5(){
fix_ingred_genericParsers_1_5_1();
}
void fix_ingred_genericParsers_1_6_6(){
int tlv2;
    bzero(&tlv2,sizeof(int));
    {char * temp; temp = (char *)(tlv2); }
    {int pop; pop = (int)(tlv2); }
    {int start; start = (int)(tlv2); }
    {int end; end = (int)(tlv2); }
    {int ps; ps = (int)(tlv2); }
    {int pe; pe = (int)(tlv2); }
    {int tlv1; tlv1 = (int)(tlv2); }
    {int tlv3; tlv3 = (int)(tlv2); }
    {int tlv4; tlv4 = (int)(tlv2); }
    {int tlv5; tlv5 = (int)(tlv2); }
    {int tlv6; tlv6 = (int)(tlv2); }
    {int tlv7; tlv7 = (int)(tlv2); }
    {int tlv8; tlv8 = (int)(tlv2); }
    {int tlv9; tlv9 = (int)(tlv2); }
    {int tlv10; tlv10 = (int)(tlv2); }
    {char tlv19; tlv19 = (char)(tlv2); }
    {int tlv21; tlv21 = (int)(tlv2); }
    {int tlv25; tlv25 = (int)(tlv2); }
    {int tlv24; tlv24 = (int)(tlv2); }
    {void * tlv12; tlv12 = (void *)(tlv2); }
    {cgc_size_t tlv11; tlv11 = (cgc_size_t)(tlv2); }
    {char tlv29; tlv29 = (char)(tlv2); }
    {int tlv31; tlv31 = (int)(tlv2); }
    {char tlv34; tlv34 = (char)(tlv2); }
    {int tlv36; tlv36 = (int)(tlv2); }
    {char tlv38; tlv38 = (char)(tlv2); }
    {int tlv40; tlv40 = (int)(tlv2); }
    {int tlv44; tlv44 = (int)(tlv2); }
    {int tlv43; tlv43 = (int)(tlv2); }
    {void * tlv14; tlv14 = (void *)(tlv2); }
    {cgc_size_t tlv13; tlv13 = (cgc_size_t)(tlv2); }
    {char tlv48; tlv48 = (char)(tlv2); }
    {int tlv15; tlv15 = (int)(tlv2); }
    {int tlv51; tlv51 = (int)(tlv2); }
    {int tlv50; tlv50 = (int)(tlv2); }
    {void * tlv18; tlv18 = (void *)(tlv2); }
    {cgc_size_t tlv17; tlv17 = (cgc_size_t)(tlv2); }
    {char * tlv72; tlv72 = (char *)(tlv2); }
    {char * tlv73; tlv73 = (char *)(tlv2); }
    {char * tlv74; tlv74 = (char *)(tlv2); }
    {void * tlv59; tlv59 = (void *)(tlv2); }
    {cgc_size_t tlv58; tlv58 = (cgc_size_t)(tlv2); }
    {void * tlv69; tlv69 = (void *)(tlv2); }
    {cgc_size_t tlv68; tlv68 = (cgc_size_t)(tlv2); }
    {char * tlv75; tlv75 = (char *)(tlv2); }
    {char * tlv76; tlv76 = (char *)(tlv2); }
}
void fix_ingred_genericParsers_1_6(){
fix_ingred_genericParsers_1_6_6();
}
void fix_ingred_genericParsers_1_9_7(){
int end;
    bzero(&end,sizeof(int));
    {int pop; pop = (int)(end); }
    {int ps; ps = (int)(end); }
    {int pe; pe = (int)(end); }
    {char tlv19; tlv19 = (char)(end); }
    {int tlv21; tlv21 = (int)(end); }
    {int tlv25; tlv25 = (int)(end); }
    {void * tlv12; tlv12 = (void *)(end); }
    {cgc_size_t tlv11; tlv11 = (cgc_size_t)(end); }
    {char tlv34; tlv34 = (char)(end); }
    {int tlv36; tlv36 = (int)(end); }
    {char tlv38; tlv38 = (char)(end); }
    {int tlv40; tlv40 = (int)(end); }
    {int tlv44; tlv44 = (int)(end); }
    {int tlv43; tlv43 = (int)(end); }
    {void * tlv14; tlv14 = (void *)(end); }
    {cgc_size_t tlv13; tlv13 = (cgc_size_t)(end); }
    {char tlv48; tlv48 = (char)(end); }
    {int tlv15; tlv15 = (int)(end); }
    {int tlv50; tlv50 = (int)(end); }
    {void * tlv18; tlv18 = (void *)(end); }
    {cgc_size_t tlv17; tlv17 = (cgc_size_t)(end); }
    {char * tlv72; tlv72 = (char *)(end); }
    {char * tlv73; tlv73 = (char *)(end); }
    {char * tlv74; tlv74 = (char *)(end); }
    {void * tlv59; tlv59 = (void *)(end); }
    {cgc_size_t tlv58; tlv58 = (cgc_size_t)(end); }
    {void * tlv69; tlv69 = (void *)(end); }
    {cgc_size_t tlv68; tlv68 = (cgc_size_t)(end); }
    {char * tlv75; tlv75 = (char *)(end); }
    {char * tlv76; tlv76 = (char *)(end); }
}
void fix_ingred_genericParsers_1_9(){
fix_ingred_genericParsers_1_9_7();
}
void fix_ingred_genericParsers_1_11_1(){
int start;
    bzero(&start,sizeof(int));
    {int pop; pop = (int)(start); }
    {int ps; ps = (int)(start); }
    {int pe; pe = (int)(start); }
    {char tlv19; tlv19 = (char)(start); }
    {int tlv21; tlv21 = (int)(start); }
    {int tlv25; tlv25 = (int)(start); }
    {void * tlv12; tlv12 = (void *)(start); }
    {cgc_size_t tlv11; tlv11 = (cgc_size_t)(start); }
    {char tlv34; tlv34 = (char)(start); }
    {int tlv36; tlv36 = (int)(start); }
    {char tlv38; tlv38 = (char)(start); }
    {int tlv40; tlv40 = (int)(start); }
    {int tlv44; tlv44 = (int)(start); }
    {int tlv43; tlv43 = (int)(start); }
    {void * tlv14; tlv14 = (void *)(start); }
    {cgc_size_t tlv13; tlv13 = (cgc_size_t)(start); }
    {char tlv48; tlv48 = (char)(start); }
    {int tlv15; tlv15 = (int)(start); }
    {int tlv50; tlv50 = (int)(start); }
    {void * tlv18; tlv18 = (void *)(start); }
    {cgc_size_t tlv17; tlv17 = (cgc_size_t)(start); }
    {char * tlv72; tlv72 = (char *)(start); }
    {char * tlv73; tlv73 = (char *)(start); }
    {char * tlv74; tlv74 = (char *)(start); }
    {void * tlv59; tlv59 = (void *)(start); }
    {cgc_size_t tlv58; tlv58 = (cgc_size_t)(start); }
    {void * tlv69; tlv69 = (void *)(start); }
    {cgc_size_t tlv68; tlv68 = (cgc_size_t)(start); }
    {char * tlv75; tlv75 = (char *)(start); }
    {char * tlv76; tlv76 = (char *)(start); }
}
void fix_ingred_genericParsers_1_11(){
fix_ingred_genericParsers_1_11_1();
}
void fix_ingred_genericParsers_1_12_7(){
char temp_ref;
    bzero(&temp_ref,1*sizeof(char));
char * temp = &temp_ref;
    {int pop; pop = (int)(temp); }
    {int ps; ps = (int)(temp); }
    {int pe; pe = (int)(temp); }
    {char tlv19; tlv19 = (char)(temp); }
    {int tlv21; tlv21 = (int)(temp); }
    {int tlv25; tlv25 = (int)(temp); }
    {void * tlv12; tlv12 = (void *)(temp); }
    {cgc_size_t tlv11; tlv11 = (cgc_size_t)(temp); }
    {char tlv34; tlv34 = (char)(temp); }
    {int tlv36; tlv36 = (int)(temp); }
    {char tlv38; tlv38 = (char)(temp); }
    {int tlv40; tlv40 = (int)(temp); }
    {int tlv44; tlv44 = (int)(temp); }
    {int tlv43; tlv43 = (int)(temp); }
    {void * tlv14; tlv14 = (void *)(temp); }
    {cgc_size_t tlv13; tlv13 = (cgc_size_t)(temp); }
    {char tlv48; tlv48 = (char)(temp); }
    {int tlv15; tlv15 = (int)(temp); }
    {int tlv50; tlv50 = (int)(temp); }
    {void * tlv18; tlv18 = (void *)(temp); }
    {cgc_size_t tlv17; tlv17 = (cgc_size_t)(temp); }
    {char * tlv72; tlv72 = (char *)(temp); }
    {char * tlv73; tlv73 = (char *)(temp); }
    {char * tlv74; tlv74 = (char *)(temp); }
    {void * tlv59; tlv59 = (void *)(temp); }
    {cgc_size_t tlv58; tlv58 = (cgc_size_t)(temp); }
    {void * tlv69; tlv69 = (void *)(temp); }
    {cgc_size_t tlv68; tlv68 = (cgc_size_t)(temp); }
    {char * tlv75; tlv75 = (char *)(temp); }
    {char * tlv76; tlv76 = (char *)(temp); }
}
void fix_ingred_genericParsers_1_12(){
fix_ingred_genericParsers_1_12_7();
}
void fix_ingred_genericParsers_1_14_8(){
int tlv3;
    bzero(&tlv3,sizeof(int));
    {int pop; pop = (int)(tlv3); }
    {int ps; ps = (int)(tlv3); }
    {int pe; pe = (int)(tlv3); }
    {char tlv19; tlv19 = (char)(tlv3); }
    {int tlv21; tlv21 = (int)(tlv3); }
    {int tlv25; tlv25 = (int)(tlv3); }
    {void * tlv12; tlv12 = (void *)(tlv3); }
    {cgc_size_t tlv11; tlv11 = (cgc_size_t)(tlv3); }
    {char tlv34; tlv34 = (char)(tlv3); }
    {int tlv36; tlv36 = (int)(tlv3); }
    {char tlv38; tlv38 = (char)(tlv3); }
    {int tlv40; tlv40 = (int)(tlv3); }
    {int tlv44; tlv44 = (int)(tlv3); }
    {int tlv43; tlv43 = (int)(tlv3); }
    {void * tlv14; tlv14 = (void *)(tlv3); }
    {cgc_size_t tlv13; tlv13 = (cgc_size_t)(tlv3); }
    {char tlv48; tlv48 = (char)(tlv3); }
    {int tlv15; tlv15 = (int)(tlv3); }
    {int tlv50; tlv50 = (int)(tlv3); }
    {void * tlv18; tlv18 = (void *)(tlv3); }
    {cgc_size_t tlv17; tlv17 = (cgc_size_t)(tlv3); }
    {char * tlv72; tlv72 = (char *)(tlv3); }
    {char * tlv73; tlv73 = (char *)(tlv3); }
    {char * tlv74; tlv74 = (char *)(tlv3); }
    {void * tlv59; tlv59 = (void *)(tlv3); }
    {cgc_size_t tlv58; tlv58 = (cgc_size_t)(tlv3); }
    {void * tlv69; tlv69 = (void *)(tlv3); }
    {cgc_size_t tlv68; tlv68 = (cgc_size_t)(tlv3); }
    {char * tlv75; tlv75 = (char *)(tlv3); }
    {char * tlv76; tlv76 = (char *)(tlv3); }
}
void fix_ingred_genericParsers_1_14(){
fix_ingred_genericParsers_1_14_8();
}
void fix_ingred_genericParsers_1_16_0(){
char temp_ref;
    bzero(&temp_ref,1*sizeof(char));
char * temp = &temp_ref;
    {int pop; pop = (int)(temp); }
    {int ps; ps = (int)(temp); }
    {int pe; pe = (int)(temp); }
    {char tlv19; tlv19 = (char)(temp); }
    {int tlv21; tlv21 = (int)(temp); }
    {int tlv25; tlv25 = (int)(temp); }
    {void * tlv12; tlv12 = (void *)(temp); }
    {cgc_size_t tlv11; tlv11 = (cgc_size_t)(temp); }
    {char tlv34; tlv34 = (char)(temp); }
    {int tlv36; tlv36 = (int)(temp); }
    {char tlv38; tlv38 = (char)(temp); }
    {int tlv40; tlv40 = (int)(temp); }
    {int tlv44; tlv44 = (int)(temp); }
    {int tlv43; tlv43 = (int)(temp); }
    {void * tlv14; tlv14 = (void *)(temp); }
    {cgc_size_t tlv13; tlv13 = (cgc_size_t)(temp); }
    {char tlv48; tlv48 = (char)(temp); }
    {int tlv15; tlv15 = (int)(temp); }
    {int tlv50; tlv50 = (int)(temp); }
    {void * tlv18; tlv18 = (void *)(temp); }
    {cgc_size_t tlv17; tlv17 = (cgc_size_t)(temp); }
    {char * tlv72; tlv72 = (char *)(temp); }
    {char * tlv73; tlv73 = (char *)(temp); }
    {char * tlv74; tlv74 = (char *)(temp); }
    {void * tlv59; tlv59 = (void *)(temp); }
    {cgc_size_t tlv58; tlv58 = (cgc_size_t)(temp); }
    {void * tlv69; tlv69 = (void *)(temp); }
    {cgc_size_t tlv68; tlv68 = (cgc_size_t)(temp); }
    {char * tlv75; tlv75 = (char *)(temp); }
    {char * tlv76; tlv76 = (char *)(temp); }
}
void fix_ingred_genericParsers_1_16(){
fix_ingred_genericParsers_1_16_0();
}
void fix_ingred_genericParsers_1_17_1(){
char tlv75_ref;
    bzero(&tlv75_ref,1*sizeof(char));
char * tlv75 = &tlv75_ref;
    {char * temp; temp = (char *)(cgc_strlen ( tlv75 ) + 1); }
    {int pop; pop = (int)(cgc_strlen ( tlv75 ) + 1); }
    {int start; start = (int)(cgc_strlen ( tlv75 ) + 1); }
    {int end; end = (int)(cgc_strlen ( tlv75 ) + 1); }
    {int ps; ps = (int)(cgc_strlen ( tlv75 ) + 1); }
    {int pe; pe = (int)(cgc_strlen ( tlv75 ) + 1); }
    {int tlv1; tlv1 = (int)(cgc_strlen ( tlv75 ) + 1); }
    {int tlv2; tlv2 = (int)(cgc_strlen ( tlv75 ) + 1); }
    {int tlv3; tlv3 = (int)(cgc_strlen ( tlv75 ) + 1); }
    {int tlv4; tlv4 = (int)(cgc_strlen ( tlv75 ) + 1); }
    {int tlv5; tlv5 = (int)(cgc_strlen ( tlv75 ) + 1); }
    {int tlv6; tlv6 = (int)(cgc_strlen ( tlv75 ) + 1); }
    {int tlv7; tlv7 = (int)(cgc_strlen ( tlv75 ) + 1); }
    {int tlv8; tlv8 = (int)(cgc_strlen ( tlv75 ) + 1); }
    {int tlv9; tlv9 = (int)(cgc_strlen ( tlv75 ) + 1); }
    {int tlv10; tlv10 = (int)(cgc_strlen ( tlv75 ) + 1); }
    {char tlv19; tlv19 = (char)(cgc_strlen ( tlv75 ) + 1); }
    {int tlv21; tlv21 = (int)(cgc_strlen ( tlv75 ) + 1); }
    {int tlv25; tlv25 = (int)(cgc_strlen ( tlv75 ) + 1); }
    {int tlv24; tlv24 = (int)(cgc_strlen ( tlv75 ) + 1); }
    {void * tlv12; tlv12 = (void *)(cgc_strlen ( tlv75 ) + 1); }
    {cgc_size_t tlv11; tlv11 = (cgc_size_t)(cgc_strlen ( tlv75 ) + 1); }
    {char tlv29; tlv29 = (char)(cgc_strlen ( tlv75 ) + 1); }
    {int tlv31; tlv31 = (int)(cgc_strlen ( tlv75 ) + 1); }
    {char tlv34; tlv34 = (char)(cgc_strlen ( tlv75 ) + 1); }
    {int tlv36; tlv36 = (int)(cgc_strlen ( tlv75 ) + 1); }
    {char tlv38; tlv38 = (char)(cgc_strlen ( tlv75 ) + 1); }
    {int tlv40; tlv40 = (int)(cgc_strlen ( tlv75 ) + 1); }
    {int tlv44; tlv44 = (int)(cgc_strlen ( tlv75 ) + 1); }
    {int tlv43; tlv43 = (int)(cgc_strlen ( tlv75 ) + 1); }
    {void * tlv14; tlv14 = (void *)(cgc_strlen ( tlv75 ) + 1); }
    {cgc_size_t tlv13; tlv13 = (cgc_size_t)(cgc_strlen ( tlv75 ) + 1); }
    {char tlv48; tlv48 = (char)(cgc_strlen ( tlv75 ) + 1); }
    {int tlv15; tlv15 = (int)(cgc_strlen ( tlv75 ) + 1); }
    {int tlv51; tlv51 = (int)(cgc_strlen ( tlv75 ) + 1); }
    {int tlv50; tlv50 = (int)(cgc_strlen ( tlv75 ) + 1); }
    {void * tlv18; tlv18 = (void *)(cgc_strlen ( tlv75 ) + 1); }
    {cgc_size_t tlv17; tlv17 = (cgc_size_t)(cgc_strlen ( tlv75 ) + 1); }
    {char * tlv72; tlv72 = (char *)(cgc_strlen ( tlv75 ) + 1); }
    {char * tlv73; tlv73 = (char *)(cgc_strlen ( tlv75 ) + 1); }
    {char * tlv74; tlv74 = (char *)(cgc_strlen ( tlv75 ) + 1); }
    {void * tlv59; tlv59 = (void *)(cgc_strlen ( tlv75 ) + 1); }
    {cgc_size_t tlv58; tlv58 = (cgc_size_t)(cgc_strlen ( tlv75 ) + 1); }
    {void * tlv69; tlv69 = (void *)(cgc_strlen ( tlv75 ) + 1); }
    {cgc_size_t tlv68; tlv68 = (cgc_size_t)(cgc_strlen ( tlv75 ) + 1); }
    {char * tlv76; tlv76 = (char *)(cgc_strlen ( tlv75 ) + 1); }
}
void fix_ingred_genericParsers_1_17(){
fix_ingred_genericParsers_1_17_1();
}
void fix_ingred_genericParsers_1_19_1(){
char tlv72_ref;
    bzero(&tlv72_ref,1*sizeof(char));
char * tlv72 = &tlv72_ref;
    {char * temp; temp = (char *)(cgc_strlen ( tlv72 ) + 1); }
    {int pop; pop = (int)(cgc_strlen ( tlv72 ) + 1); }
    {int start; start = (int)(cgc_strlen ( tlv72 ) + 1); }
    {int end; end = (int)(cgc_strlen ( tlv72 ) + 1); }
    {int ps; ps = (int)(cgc_strlen ( tlv72 ) + 1); }
    {int pe; pe = (int)(cgc_strlen ( tlv72 ) + 1); }
    {int tlv1; tlv1 = (int)(cgc_strlen ( tlv72 ) + 1); }
    {int tlv2; tlv2 = (int)(cgc_strlen ( tlv72 ) + 1); }
    {int tlv3; tlv3 = (int)(cgc_strlen ( tlv72 ) + 1); }
    {int tlv4; tlv4 = (int)(cgc_strlen ( tlv72 ) + 1); }
    {int tlv5; tlv5 = (int)(cgc_strlen ( tlv72 ) + 1); }
    {int tlv6; tlv6 = (int)(cgc_strlen ( tlv72 ) + 1); }
    {int tlv7; tlv7 = (int)(cgc_strlen ( tlv72 ) + 1); }
    {int tlv8; tlv8 = (int)(cgc_strlen ( tlv72 ) + 1); }
    {int tlv9; tlv9 = (int)(cgc_strlen ( tlv72 ) + 1); }
    {int tlv10; tlv10 = (int)(cgc_strlen ( tlv72 ) + 1); }
    {char tlv19; tlv19 = (char)(cgc_strlen ( tlv72 ) + 1); }
    {int tlv21; tlv21 = (int)(cgc_strlen ( tlv72 ) + 1); }
    {int tlv25; tlv25 = (int)(cgc_strlen ( tlv72 ) + 1); }
    {int tlv24; tlv24 = (int)(cgc_strlen ( tlv72 ) + 1); }
    {void * tlv12; tlv12 = (void *)(cgc_strlen ( tlv72 ) + 1); }
    {cgc_size_t tlv11; tlv11 = (cgc_size_t)(cgc_strlen ( tlv72 ) + 1); }
    {char tlv29; tlv29 = (char)(cgc_strlen ( tlv72 ) + 1); }
    {int tlv31; tlv31 = (int)(cgc_strlen ( tlv72 ) + 1); }
    {char tlv34; tlv34 = (char)(cgc_strlen ( tlv72 ) + 1); }
    {int tlv36; tlv36 = (int)(cgc_strlen ( tlv72 ) + 1); }
    {char tlv38; tlv38 = (char)(cgc_strlen ( tlv72 ) + 1); }
    {int tlv40; tlv40 = (int)(cgc_strlen ( tlv72 ) + 1); }
    {int tlv44; tlv44 = (int)(cgc_strlen ( tlv72 ) + 1); }
    {int tlv43; tlv43 = (int)(cgc_strlen ( tlv72 ) + 1); }
    {void * tlv14; tlv14 = (void *)(cgc_strlen ( tlv72 ) + 1); }
    {cgc_size_t tlv13; tlv13 = (cgc_size_t)(cgc_strlen ( tlv72 ) + 1); }
    {char tlv48; tlv48 = (char)(cgc_strlen ( tlv72 ) + 1); }
    {int tlv15; tlv15 = (int)(cgc_strlen ( tlv72 ) + 1); }
    {int tlv51; tlv51 = (int)(cgc_strlen ( tlv72 ) + 1); }
    {int tlv50; tlv50 = (int)(cgc_strlen ( tlv72 ) + 1); }
    {void * tlv18; tlv18 = (void *)(cgc_strlen ( tlv72 ) + 1); }
    {cgc_size_t tlv17; tlv17 = (cgc_size_t)(cgc_strlen ( tlv72 ) + 1); }
    {char * tlv73; tlv73 = (char *)(cgc_strlen ( tlv72 ) + 1); }
    {char * tlv74; tlv74 = (char *)(cgc_strlen ( tlv72 ) + 1); }
    {void * tlv59; tlv59 = (void *)(cgc_strlen ( tlv72 ) + 1); }
    {cgc_size_t tlv58; tlv58 = (cgc_size_t)(cgc_strlen ( tlv72 ) + 1); }
    {void * tlv69; tlv69 = (void *)(cgc_strlen ( tlv72 ) + 1); }
    {cgc_size_t tlv68; tlv68 = (cgc_size_t)(cgc_strlen ( tlv72 ) + 1); }
    {char * tlv75; tlv75 = (char *)(cgc_strlen ( tlv72 ) + 1); }
    {char * tlv76; tlv76 = (char *)(cgc_strlen ( tlv72 ) + 1); }
}
void fix_ingred_genericParsers_1_19(){
fix_ingred_genericParsers_1_19_1();
}
void fix_ingred_genericParsers_1_20_1(){
    {int pop; pop = (int)('}'); }
    {int ps; ps = (int)('}'); }
    {int pe; pe = (int)('}'); }
    {char tlv19; tlv19 = (char)('}'); }
    {int tlv21; tlv21 = (int)('}'); }
    {int tlv25; tlv25 = (int)('}'); }
    {void * tlv12; tlv12 = (void *)('}'); }
    {cgc_size_t tlv11; tlv11 = (cgc_size_t)('}'); }
    {char tlv34; tlv34 = (char)('}'); }
    {int tlv36; tlv36 = (int)('}'); }
    {char tlv38; tlv38 = (char)('}'); }
    {int tlv40; tlv40 = (int)('}'); }
    {int tlv44; tlv44 = (int)('}'); }
    {int tlv43; tlv43 = (int)('}'); }
    {void * tlv14; tlv14 = (void *)('}'); }
    {cgc_size_t tlv13; tlv13 = (cgc_size_t)('}'); }
    {char tlv48; tlv48 = (char)('}'); }
    {int tlv15; tlv15 = (int)('}'); }
    {int tlv50; tlv50 = (int)('}'); }
    {void * tlv18; tlv18 = (void *)('}'); }
    {cgc_size_t tlv17; tlv17 = (cgc_size_t)('}'); }
    {char * tlv72; tlv72 = (char *)('}'); }
    {char * tlv73; tlv73 = (char *)('}'); }
    {char * tlv74; tlv74 = (char *)('}'); }
    {void * tlv59; tlv59 = (void *)('}'); }
    {cgc_size_t tlv58; tlv58 = (cgc_size_t)('}'); }
    {void * tlv69; tlv69 = (void *)('}'); }
    {cgc_size_t tlv68; tlv68 = (cgc_size_t)('}'); }
    {char * tlv75; tlv75 = (char *)('}'); }
    {char * tlv76; tlv76 = (char *)('}'); }
}
void fix_ingred_genericParsers_1_20(){
fix_ingred_genericParsers_1_20_1();
}
void fix_ingred_genericParsers_1_24_7(){
int tlv5;
    bzero(&tlv5,sizeof(int));
    {char * temp; temp = (char *)(tlv5); }
    {int pop; pop = (int)(tlv5); }
    {int start; start = (int)(tlv5); }
    {int end; end = (int)(tlv5); }
    {int ps; ps = (int)(tlv5); }
    {int pe; pe = (int)(tlv5); }
    {int tlv1; tlv1 = (int)(tlv5); }
    {int tlv2; tlv2 = (int)(tlv5); }
    {int tlv3; tlv3 = (int)(tlv5); }
    {int tlv4; tlv4 = (int)(tlv5); }
    {int tlv6; tlv6 = (int)(tlv5); }
    {int tlv7; tlv7 = (int)(tlv5); }
    {int tlv8; tlv8 = (int)(tlv5); }
    {int tlv9; tlv9 = (int)(tlv5); }
    {int tlv10; tlv10 = (int)(tlv5); }
    {char tlv19; tlv19 = (char)(tlv5); }
    {int tlv21; tlv21 = (int)(tlv5); }
    {int tlv25; tlv25 = (int)(tlv5); }
    {int tlv24; tlv24 = (int)(tlv5); }
    {void * tlv12; tlv12 = (void *)(tlv5); }
    {cgc_size_t tlv11; tlv11 = (cgc_size_t)(tlv5); }
    {char tlv29; tlv29 = (char)(tlv5); }
    {int tlv31; tlv31 = (int)(tlv5); }
    {char tlv34; tlv34 = (char)(tlv5); }
    {int tlv36; tlv36 = (int)(tlv5); }
    {char tlv38; tlv38 = (char)(tlv5); }
    {int tlv40; tlv40 = (int)(tlv5); }
    {int tlv44; tlv44 = (int)(tlv5); }
    {int tlv43; tlv43 = (int)(tlv5); }
    {void * tlv14; tlv14 = (void *)(tlv5); }
    {cgc_size_t tlv13; tlv13 = (cgc_size_t)(tlv5); }
    {char tlv48; tlv48 = (char)(tlv5); }
    {int tlv15; tlv15 = (int)(tlv5); }
    {int tlv51; tlv51 = (int)(tlv5); }
    {int tlv50; tlv50 = (int)(tlv5); }
    {void * tlv18; tlv18 = (void *)(tlv5); }
    {cgc_size_t tlv17; tlv17 = (cgc_size_t)(tlv5); }
    {char * tlv72; tlv72 = (char *)(tlv5); }
    {char * tlv73; tlv73 = (char *)(tlv5); }
    {char * tlv74; tlv74 = (char *)(tlv5); }
    {void * tlv59; tlv59 = (void *)(tlv5); }
    {cgc_size_t tlv58; tlv58 = (cgc_size_t)(tlv5); }
    {void * tlv69; tlv69 = (void *)(tlv5); }
    {cgc_size_t tlv68; tlv68 = (cgc_size_t)(tlv5); }
    {char * tlv75; tlv75 = (char *)(tlv5); }
    {char * tlv76; tlv76 = (char *)(tlv5); }
}
void fix_ingred_genericParsers_1_24(){
fix_ingred_genericParsers_1_24_7();
}
void fix_ingred_genericParsers_1_27_8(){
int pe;
    bzero(&pe,sizeof(int));
    {char * temp; temp = (char *)(pe); }
    {int pop; pop = (int)(pe); }
    {int start; start = (int)(pe); }
    {int end; end = (int)(pe); }
    {int ps; ps = (int)(pe); }
    {int tlv1; tlv1 = (int)(pe); }
    {int tlv2; tlv2 = (int)(pe); }
    {int tlv3; tlv3 = (int)(pe); }
    {int tlv4; tlv4 = (int)(pe); }
    {int tlv5; tlv5 = (int)(pe); }
    {int tlv6; tlv6 = (int)(pe); }
    {int tlv7; tlv7 = (int)(pe); }
    {int tlv8; tlv8 = (int)(pe); }
    {int tlv9; tlv9 = (int)(pe); }
    {int tlv10; tlv10 = (int)(pe); }
    {char tlv19; tlv19 = (char)(pe); }
    {int tlv21; tlv21 = (int)(pe); }
    {int tlv25; tlv25 = (int)(pe); }
    {int tlv24; tlv24 = (int)(pe); }
    {void * tlv12; tlv12 = (void *)(pe); }
    {cgc_size_t tlv11; tlv11 = (cgc_size_t)(pe); }
    {char tlv29; tlv29 = (char)(pe); }
    {int tlv31; tlv31 = (int)(pe); }
    {char tlv34; tlv34 = (char)(pe); }
    {int tlv36; tlv36 = (int)(pe); }
    {char tlv38; tlv38 = (char)(pe); }
    {int tlv40; tlv40 = (int)(pe); }
    {int tlv44; tlv44 = (int)(pe); }
    {int tlv43; tlv43 = (int)(pe); }
    {void * tlv14; tlv14 = (void *)(pe); }
    {cgc_size_t tlv13; tlv13 = (cgc_size_t)(pe); }
    {char tlv48; tlv48 = (char)(pe); }
    {int tlv15; tlv15 = (int)(pe); }
    {int tlv51; tlv51 = (int)(pe); }
    {int tlv50; tlv50 = (int)(pe); }
    {void * tlv18; tlv18 = (void *)(pe); }
    {cgc_size_t tlv17; tlv17 = (cgc_size_t)(pe); }
    {char * tlv72; tlv72 = (char *)(pe); }
    {char * tlv73; tlv73 = (char *)(pe); }
    {char * tlv74; tlv74 = (char *)(pe); }
    {void * tlv59; tlv59 = (void *)(pe); }
    {cgc_size_t tlv58; tlv58 = (cgc_size_t)(pe); }
    {void * tlv69; tlv69 = (void *)(pe); }
    {cgc_size_t tlv68; tlv68 = (cgc_size_t)(pe); }
    {char * tlv75; tlv75 = (char *)(pe); }
    {char * tlv76; tlv76 = (char *)(pe); }
}
void fix_ingred_genericParsers_1_27(){
fix_ingred_genericParsers_1_27_8();
}
void fix_ingred_genericParsers_1_33_8(){
int tlv7;
    bzero(&tlv7,sizeof(int));
    {char * temp; temp = (char *)(tlv7); }
    {int pop; pop = (int)(tlv7); }
    {int start; start = (int)(tlv7); }
    {int end; end = (int)(tlv7); }
    {int ps; ps = (int)(tlv7); }
    {int pe; pe = (int)(tlv7); }
    {int tlv1; tlv1 = (int)(tlv7); }
    {int tlv2; tlv2 = (int)(tlv7); }
    {int tlv3; tlv3 = (int)(tlv7); }
    {int tlv4; tlv4 = (int)(tlv7); }
    {int tlv5; tlv5 = (int)(tlv7); }
    {int tlv6; tlv6 = (int)(tlv7); }
    {int tlv8; tlv8 = (int)(tlv7); }
    {int tlv9; tlv9 = (int)(tlv7); }
    {int tlv10; tlv10 = (int)(tlv7); }
    {char tlv19; tlv19 = (char)(tlv7); }
    {int tlv21; tlv21 = (int)(tlv7); }
    {int tlv25; tlv25 = (int)(tlv7); }
    {int tlv24; tlv24 = (int)(tlv7); }
    {void * tlv12; tlv12 = (void *)(tlv7); }
    {cgc_size_t tlv11; tlv11 = (cgc_size_t)(tlv7); }
    {char tlv29; tlv29 = (char)(tlv7); }
    {int tlv31; tlv31 = (int)(tlv7); }
    {char tlv34; tlv34 = (char)(tlv7); }
    {int tlv36; tlv36 = (int)(tlv7); }
    {char tlv38; tlv38 = (char)(tlv7); }
    {int tlv40; tlv40 = (int)(tlv7); }
    {int tlv44; tlv44 = (int)(tlv7); }
    {int tlv43; tlv43 = (int)(tlv7); }
    {void * tlv14; tlv14 = (void *)(tlv7); }
    {cgc_size_t tlv13; tlv13 = (cgc_size_t)(tlv7); }
    {char tlv48; tlv48 = (char)(tlv7); }
    {int tlv15; tlv15 = (int)(tlv7); }
    {int tlv51; tlv51 = (int)(tlv7); }
    {int tlv50; tlv50 = (int)(tlv7); }
    {void * tlv18; tlv18 = (void *)(tlv7); }
    {cgc_size_t tlv17; tlv17 = (cgc_size_t)(tlv7); }
    {char * tlv72; tlv72 = (char *)(tlv7); }
    {char * tlv73; tlv73 = (char *)(tlv7); }
    {char * tlv74; tlv74 = (char *)(tlv7); }
    {void * tlv59; tlv59 = (void *)(tlv7); }
    {cgc_size_t tlv58; tlv58 = (cgc_size_t)(tlv7); }
    {void * tlv69; tlv69 = (void *)(tlv7); }
    {cgc_size_t tlv68; tlv68 = (cgc_size_t)(tlv7); }
    {char * tlv75; tlv75 = (char *)(tlv7); }
    {char * tlv76; tlv76 = (char *)(tlv7); }
}
void fix_ingred_genericParsers_1_33(){
fix_ingred_genericParsers_1_33_8();
}
void fix_ingred_genericParsers_1_35_1(){
    {int pop; pop = (int)('#'); }
    {int ps; ps = (int)('#'); }
    {int pe; pe = (int)('#'); }
    {char tlv19; tlv19 = (char)('#'); }
    {int tlv21; tlv21 = (int)('#'); }
    {int tlv25; tlv25 = (int)('#'); }
    {void * tlv12; tlv12 = (void *)('#'); }
    {cgc_size_t tlv11; tlv11 = (cgc_size_t)('#'); }
    {char tlv34; tlv34 = (char)('#'); }
    {int tlv36; tlv36 = (int)('#'); }
    {char tlv38; tlv38 = (char)('#'); }
    {int tlv40; tlv40 = (int)('#'); }
    {int tlv44; tlv44 = (int)('#'); }
    {int tlv43; tlv43 = (int)('#'); }
    {void * tlv14; tlv14 = (void *)('#'); }
    {cgc_size_t tlv13; tlv13 = (cgc_size_t)('#'); }
    {char tlv48; tlv48 = (char)('#'); }
    {int tlv15; tlv15 = (int)('#'); }
    {int tlv50; tlv50 = (int)('#'); }
    {void * tlv18; tlv18 = (void *)('#'); }
    {cgc_size_t tlv17; tlv17 = (cgc_size_t)('#'); }
    {char * tlv72; tlv72 = (char *)('#'); }
    {char * tlv73; tlv73 = (char *)('#'); }
    {char * tlv74; tlv74 = (char *)('#'); }
    {void * tlv59; tlv59 = (void *)('#'); }
    {cgc_size_t tlv58; tlv58 = (cgc_size_t)('#'); }
    {void * tlv69; tlv69 = (void *)('#'); }
    {cgc_size_t tlv68; tlv68 = (cgc_size_t)('#'); }
    {char * tlv75; tlv75 = (char *)('#'); }
    {char * tlv76; tlv76 = (char *)('#'); }
}
void fix_ingred_genericParsers_1_35(){
fix_ingred_genericParsers_1_35_1();
}
void fix_ingred_genericParsers_1_46_8(){
int tlv9;
    bzero(&tlv9,sizeof(int));
    {char * temp; temp = (char *)(tlv9); }
    {int pop; pop = (int)(tlv9); }
    {int start; start = (int)(tlv9); }
    {int end; end = (int)(tlv9); }
    {int ps; ps = (int)(tlv9); }
    {int pe; pe = (int)(tlv9); }
    {int tlv1; tlv1 = (int)(tlv9); }
    {int tlv2; tlv2 = (int)(tlv9); }
    {int tlv3; tlv3 = (int)(tlv9); }
    {int tlv4; tlv4 = (int)(tlv9); }
    {int tlv5; tlv5 = (int)(tlv9); }
    {int tlv6; tlv6 = (int)(tlv9); }
    {int tlv7; tlv7 = (int)(tlv9); }
    {int tlv8; tlv8 = (int)(tlv9); }
    {int tlv10; tlv10 = (int)(tlv9); }
    {char tlv19; tlv19 = (char)(tlv9); }
    {int tlv21; tlv21 = (int)(tlv9); }
    {int tlv25; tlv25 = (int)(tlv9); }
    {int tlv24; tlv24 = (int)(tlv9); }
    {void * tlv12; tlv12 = (void *)(tlv9); }
    {cgc_size_t tlv11; tlv11 = (cgc_size_t)(tlv9); }
    {char tlv29; tlv29 = (char)(tlv9); }
    {int tlv31; tlv31 = (int)(tlv9); }
    {char tlv34; tlv34 = (char)(tlv9); }
    {int tlv36; tlv36 = (int)(tlv9); }
    {char tlv38; tlv38 = (char)(tlv9); }
    {int tlv40; tlv40 = (int)(tlv9); }
    {int tlv44; tlv44 = (int)(tlv9); }
    {int tlv43; tlv43 = (int)(tlv9); }
    {void * tlv14; tlv14 = (void *)(tlv9); }
    {cgc_size_t tlv13; tlv13 = (cgc_size_t)(tlv9); }
    {char tlv48; tlv48 = (char)(tlv9); }
    {int tlv15; tlv15 = (int)(tlv9); }
    {int tlv51; tlv51 = (int)(tlv9); }
    {int tlv50; tlv50 = (int)(tlv9); }
    {void * tlv18; tlv18 = (void *)(tlv9); }
    {cgc_size_t tlv17; tlv17 = (cgc_size_t)(tlv9); }
    {char * tlv72; tlv72 = (char *)(tlv9); }
    {char * tlv73; tlv73 = (char *)(tlv9); }
    {char * tlv74; tlv74 = (char *)(tlv9); }
    {void * tlv59; tlv59 = (void *)(tlv9); }
    {cgc_size_t tlv58; tlv58 = (cgc_size_t)(tlv9); }
    {void * tlv69; tlv69 = (void *)(tlv9); }
    {cgc_size_t tlv68; tlv68 = (cgc_size_t)(tlv9); }
    {char * tlv75; tlv75 = (char *)(tlv9); }
    {char * tlv76; tlv76 = (char *)(tlv9); }
}
void fix_ingred_genericParsers_1_46(){
fix_ingred_genericParsers_1_46_8();
}
void fix_ingred_genericParsers_1_48_1(){
char tlv76_ref;
    bzero(&tlv76_ref,1*sizeof(char));
char * tlv76 = &tlv76_ref;
    {char * temp; temp = (char *)(cgc_strlen ( tlv76 ) + 1); }
    {int pop; pop = (int)(cgc_strlen ( tlv76 ) + 1); }
    {int start; start = (int)(cgc_strlen ( tlv76 ) + 1); }
    {int end; end = (int)(cgc_strlen ( tlv76 ) + 1); }
    {int ps; ps = (int)(cgc_strlen ( tlv76 ) + 1); }
    {int pe; pe = (int)(cgc_strlen ( tlv76 ) + 1); }
    {int tlv1; tlv1 = (int)(cgc_strlen ( tlv76 ) + 1); }
    {int tlv2; tlv2 = (int)(cgc_strlen ( tlv76 ) + 1); }
    {int tlv3; tlv3 = (int)(cgc_strlen ( tlv76 ) + 1); }
    {int tlv4; tlv4 = (int)(cgc_strlen ( tlv76 ) + 1); }
    {int tlv5; tlv5 = (int)(cgc_strlen ( tlv76 ) + 1); }
    {int tlv6; tlv6 = (int)(cgc_strlen ( tlv76 ) + 1); }
    {int tlv7; tlv7 = (int)(cgc_strlen ( tlv76 ) + 1); }
    {int tlv8; tlv8 = (int)(cgc_strlen ( tlv76 ) + 1); }
    {int tlv9; tlv9 = (int)(cgc_strlen ( tlv76 ) + 1); }
    {int tlv10; tlv10 = (int)(cgc_strlen ( tlv76 ) + 1); }
    {char tlv19; tlv19 = (char)(cgc_strlen ( tlv76 ) + 1); }
    {int tlv21; tlv21 = (int)(cgc_strlen ( tlv76 ) + 1); }
    {int tlv25; tlv25 = (int)(cgc_strlen ( tlv76 ) + 1); }
    {int tlv24; tlv24 = (int)(cgc_strlen ( tlv76 ) + 1); }
    {void * tlv12; tlv12 = (void *)(cgc_strlen ( tlv76 ) + 1); }
    {cgc_size_t tlv11; tlv11 = (cgc_size_t)(cgc_strlen ( tlv76 ) + 1); }
    {char tlv29; tlv29 = (char)(cgc_strlen ( tlv76 ) + 1); }
    {int tlv31; tlv31 = (int)(cgc_strlen ( tlv76 ) + 1); }
    {char tlv34; tlv34 = (char)(cgc_strlen ( tlv76 ) + 1); }
    {int tlv36; tlv36 = (int)(cgc_strlen ( tlv76 ) + 1); }
    {char tlv38; tlv38 = (char)(cgc_strlen ( tlv76 ) + 1); }
    {int tlv40; tlv40 = (int)(cgc_strlen ( tlv76 ) + 1); }
    {int tlv44; tlv44 = (int)(cgc_strlen ( tlv76 ) + 1); }
    {int tlv43; tlv43 = (int)(cgc_strlen ( tlv76 ) + 1); }
    {void * tlv14; tlv14 = (void *)(cgc_strlen ( tlv76 ) + 1); }
    {cgc_size_t tlv13; tlv13 = (cgc_size_t)(cgc_strlen ( tlv76 ) + 1); }
    {char tlv48; tlv48 = (char)(cgc_strlen ( tlv76 ) + 1); }
    {int tlv15; tlv15 = (int)(cgc_strlen ( tlv76 ) + 1); }
    {int tlv51; tlv51 = (int)(cgc_strlen ( tlv76 ) + 1); }
    {int tlv50; tlv50 = (int)(cgc_strlen ( tlv76 ) + 1); }
    {void * tlv18; tlv18 = (void *)(cgc_strlen ( tlv76 ) + 1); }
    {cgc_size_t tlv17; tlv17 = (cgc_size_t)(cgc_strlen ( tlv76 ) + 1); }
    {char * tlv72; tlv72 = (char *)(cgc_strlen ( tlv76 ) + 1); }
    {char * tlv73; tlv73 = (char *)(cgc_strlen ( tlv76 ) + 1); }
    {char * tlv74; tlv74 = (char *)(cgc_strlen ( tlv76 ) + 1); }
    {void * tlv59; tlv59 = (void *)(cgc_strlen ( tlv76 ) + 1); }
    {cgc_size_t tlv58; tlv58 = (cgc_size_t)(cgc_strlen ( tlv76 ) + 1); }
    {void * tlv69; tlv69 = (void *)(cgc_strlen ( tlv76 ) + 1); }
    {cgc_size_t tlv68; tlv68 = (cgc_size_t)(cgc_strlen ( tlv76 ) + 1); }
    {char * tlv75; tlv75 = (char *)(cgc_strlen ( tlv76 ) + 1); }
}
void fix_ingred_genericParsers_1_48(){
fix_ingred_genericParsers_1_48_1();
}
void fix_ingred_genericParsers_1_50_1(){
char tlv73_ref;
    bzero(&tlv73_ref,1*sizeof(char));
char * tlv73 = &tlv73_ref;
    {char * temp; temp = (char *)(cgc_strlen ( tlv73 ) + 1); }
    {int pop; pop = (int)(cgc_strlen ( tlv73 ) + 1); }
    {int start; start = (int)(cgc_strlen ( tlv73 ) + 1); }
    {int end; end = (int)(cgc_strlen ( tlv73 ) + 1); }
    {int ps; ps = (int)(cgc_strlen ( tlv73 ) + 1); }
    {int pe; pe = (int)(cgc_strlen ( tlv73 ) + 1); }
    {int tlv1; tlv1 = (int)(cgc_strlen ( tlv73 ) + 1); }
    {int tlv2; tlv2 = (int)(cgc_strlen ( tlv73 ) + 1); }
    {int tlv3; tlv3 = (int)(cgc_strlen ( tlv73 ) + 1); }
    {int tlv4; tlv4 = (int)(cgc_strlen ( tlv73 ) + 1); }
    {int tlv5; tlv5 = (int)(cgc_strlen ( tlv73 ) + 1); }
    {int tlv6; tlv6 = (int)(cgc_strlen ( tlv73 ) + 1); }
    {int tlv7; tlv7 = (int)(cgc_strlen ( tlv73 ) + 1); }
    {int tlv8; tlv8 = (int)(cgc_strlen ( tlv73 ) + 1); }
    {int tlv9; tlv9 = (int)(cgc_strlen ( tlv73 ) + 1); }
    {int tlv10; tlv10 = (int)(cgc_strlen ( tlv73 ) + 1); }
    {char tlv19; tlv19 = (char)(cgc_strlen ( tlv73 ) + 1); }
    {int tlv21; tlv21 = (int)(cgc_strlen ( tlv73 ) + 1); }
    {int tlv25; tlv25 = (int)(cgc_strlen ( tlv73 ) + 1); }
    {int tlv24; tlv24 = (int)(cgc_strlen ( tlv73 ) + 1); }
    {void * tlv12; tlv12 = (void *)(cgc_strlen ( tlv73 ) + 1); }
    {cgc_size_t tlv11; tlv11 = (cgc_size_t)(cgc_strlen ( tlv73 ) + 1); }
    {char tlv29; tlv29 = (char)(cgc_strlen ( tlv73 ) + 1); }
    {int tlv31; tlv31 = (int)(cgc_strlen ( tlv73 ) + 1); }
    {char tlv34; tlv34 = (char)(cgc_strlen ( tlv73 ) + 1); }
    {int tlv36; tlv36 = (int)(cgc_strlen ( tlv73 ) + 1); }
    {char tlv38; tlv38 = (char)(cgc_strlen ( tlv73 ) + 1); }
    {int tlv40; tlv40 = (int)(cgc_strlen ( tlv73 ) + 1); }
    {int tlv44; tlv44 = (int)(cgc_strlen ( tlv73 ) + 1); }
    {int tlv43; tlv43 = (int)(cgc_strlen ( tlv73 ) + 1); }
    {void * tlv14; tlv14 = (void *)(cgc_strlen ( tlv73 ) + 1); }
    {cgc_size_t tlv13; tlv13 = (cgc_size_t)(cgc_strlen ( tlv73 ) + 1); }
    {char tlv48; tlv48 = (char)(cgc_strlen ( tlv73 ) + 1); }
    {int tlv15; tlv15 = (int)(cgc_strlen ( tlv73 ) + 1); }
    {int tlv51; tlv51 = (int)(cgc_strlen ( tlv73 ) + 1); }
    {int tlv50; tlv50 = (int)(cgc_strlen ( tlv73 ) + 1); }
    {void * tlv18; tlv18 = (void *)(cgc_strlen ( tlv73 ) + 1); }
    {cgc_size_t tlv17; tlv17 = (cgc_size_t)(cgc_strlen ( tlv73 ) + 1); }
    {char * tlv72; tlv72 = (char *)(cgc_strlen ( tlv73 ) + 1); }
    {char * tlv74; tlv74 = (char *)(cgc_strlen ( tlv73 ) + 1); }
    {void * tlv59; tlv59 = (void *)(cgc_strlen ( tlv73 ) + 1); }
    {cgc_size_t tlv58; tlv58 = (cgc_size_t)(cgc_strlen ( tlv73 ) + 1); }
    {void * tlv69; tlv69 = (void *)(cgc_strlen ( tlv73 ) + 1); }
    {cgc_size_t tlv68; tlv68 = (cgc_size_t)(cgc_strlen ( tlv73 ) + 1); }
    {char * tlv75; tlv75 = (char *)(cgc_strlen ( tlv73 ) + 1); }
    {char * tlv76; tlv76 = (char *)(cgc_strlen ( tlv73 ) + 1); }
}
void fix_ingred_genericParsers_1_50(){
fix_ingred_genericParsers_1_50_1();
}
void fix_ingred_genericParsers_1_55_1(){
int ps;
    bzero(&ps,sizeof(int));
    {char * temp; temp = (char *)(ps); }
    {int pop; pop = (int)(ps); }
    {int start; start = (int)(ps); }
    {int end; end = (int)(ps); }
    {int pe; pe = (int)(ps); }
    {int tlv1; tlv1 = (int)(ps); }
    {int tlv2; tlv2 = (int)(ps); }
    {int tlv3; tlv3 = (int)(ps); }
    {int tlv4; tlv4 = (int)(ps); }
    {int tlv5; tlv5 = (int)(ps); }
    {int tlv6; tlv6 = (int)(ps); }
    {int tlv7; tlv7 = (int)(ps); }
    {int tlv8; tlv8 = (int)(ps); }
    {int tlv9; tlv9 = (int)(ps); }
    {int tlv10; tlv10 = (int)(ps); }
    {char tlv19; tlv19 = (char)(ps); }
    {int tlv21; tlv21 = (int)(ps); }
    {int tlv25; tlv25 = (int)(ps); }
    {int tlv24; tlv24 = (int)(ps); }
    {void * tlv12; tlv12 = (void *)(ps); }
    {cgc_size_t tlv11; tlv11 = (cgc_size_t)(ps); }
    {char tlv29; tlv29 = (char)(ps); }
    {int tlv31; tlv31 = (int)(ps); }
    {char tlv34; tlv34 = (char)(ps); }
    {int tlv36; tlv36 = (int)(ps); }
    {char tlv38; tlv38 = (char)(ps); }
    {int tlv40; tlv40 = (int)(ps); }
    {int tlv44; tlv44 = (int)(ps); }
    {int tlv43; tlv43 = (int)(ps); }
    {void * tlv14; tlv14 = (void *)(ps); }
    {cgc_size_t tlv13; tlv13 = (cgc_size_t)(ps); }
    {char tlv48; tlv48 = (char)(ps); }
    {int tlv15; tlv15 = (int)(ps); }
    {int tlv51; tlv51 = (int)(ps); }
    {int tlv50; tlv50 = (int)(ps); }
    {void * tlv18; tlv18 = (void *)(ps); }
    {cgc_size_t tlv17; tlv17 = (cgc_size_t)(ps); }
    {char * tlv72; tlv72 = (char *)(ps); }
    {char * tlv73; tlv73 = (char *)(ps); }
    {char * tlv74; tlv74 = (char *)(ps); }
    {void * tlv59; tlv59 = (void *)(ps); }
    {cgc_size_t tlv58; tlv58 = (cgc_size_t)(ps); }
    {void * tlv69; tlv69 = (void *)(ps); }
    {cgc_size_t tlv68; tlv68 = (cgc_size_t)(ps); }
    {char * tlv75; tlv75 = (char *)(ps); }
    {char * tlv76; tlv76 = (char *)(ps); }
}
void fix_ingred_genericParsers_1_55(){
fix_ingred_genericParsers_1_55_1();
}
void fix_ingred_genericParsers_1_60_1(){
char tlv74_ref;
    bzero(&tlv74_ref,1*sizeof(char));
char * tlv74 = &tlv74_ref;
    {char * temp; temp = (char *)(cgc_strlen ( tlv74 ) + 1); }
    {int pop; pop = (int)(cgc_strlen ( tlv74 ) + 1); }
    {int start; start = (int)(cgc_strlen ( tlv74 ) + 1); }
    {int end; end = (int)(cgc_strlen ( tlv74 ) + 1); }
    {int ps; ps = (int)(cgc_strlen ( tlv74 ) + 1); }
    {int pe; pe = (int)(cgc_strlen ( tlv74 ) + 1); }
    {int tlv1; tlv1 = (int)(cgc_strlen ( tlv74 ) + 1); }
    {int tlv2; tlv2 = (int)(cgc_strlen ( tlv74 ) + 1); }
    {int tlv3; tlv3 = (int)(cgc_strlen ( tlv74 ) + 1); }
    {int tlv4; tlv4 = (int)(cgc_strlen ( tlv74 ) + 1); }
    {int tlv5; tlv5 = (int)(cgc_strlen ( tlv74 ) + 1); }
    {int tlv6; tlv6 = (int)(cgc_strlen ( tlv74 ) + 1); }
    {int tlv7; tlv7 = (int)(cgc_strlen ( tlv74 ) + 1); }
    {int tlv8; tlv8 = (int)(cgc_strlen ( tlv74 ) + 1); }
    {int tlv9; tlv9 = (int)(cgc_strlen ( tlv74 ) + 1); }
    {int tlv10; tlv10 = (int)(cgc_strlen ( tlv74 ) + 1); }
    {char tlv19; tlv19 = (char)(cgc_strlen ( tlv74 ) + 1); }
    {int tlv21; tlv21 = (int)(cgc_strlen ( tlv74 ) + 1); }
    {int tlv25; tlv25 = (int)(cgc_strlen ( tlv74 ) + 1); }
    {int tlv24; tlv24 = (int)(cgc_strlen ( tlv74 ) + 1); }
    {void * tlv12; tlv12 = (void *)(cgc_strlen ( tlv74 ) + 1); }
    {cgc_size_t tlv11; tlv11 = (cgc_size_t)(cgc_strlen ( tlv74 ) + 1); }
    {char tlv29; tlv29 = (char)(cgc_strlen ( tlv74 ) + 1); }
    {int tlv31; tlv31 = (int)(cgc_strlen ( tlv74 ) + 1); }
    {char tlv34; tlv34 = (char)(cgc_strlen ( tlv74 ) + 1); }
    {int tlv36; tlv36 = (int)(cgc_strlen ( tlv74 ) + 1); }
    {char tlv38; tlv38 = (char)(cgc_strlen ( tlv74 ) + 1); }
    {int tlv40; tlv40 = (int)(cgc_strlen ( tlv74 ) + 1); }
    {int tlv44; tlv44 = (int)(cgc_strlen ( tlv74 ) + 1); }
    {int tlv43; tlv43 = (int)(cgc_strlen ( tlv74 ) + 1); }
    {void * tlv14; tlv14 = (void *)(cgc_strlen ( tlv74 ) + 1); }
    {cgc_size_t tlv13; tlv13 = (cgc_size_t)(cgc_strlen ( tlv74 ) + 1); }
    {char tlv48; tlv48 = (char)(cgc_strlen ( tlv74 ) + 1); }
    {int tlv15; tlv15 = (int)(cgc_strlen ( tlv74 ) + 1); }
    {int tlv51; tlv51 = (int)(cgc_strlen ( tlv74 ) + 1); }
    {int tlv50; tlv50 = (int)(cgc_strlen ( tlv74 ) + 1); }
    {void * tlv18; tlv18 = (void *)(cgc_strlen ( tlv74 ) + 1); }
    {cgc_size_t tlv17; tlv17 = (cgc_size_t)(cgc_strlen ( tlv74 ) + 1); }
    {char * tlv72; tlv72 = (char *)(cgc_strlen ( tlv74 ) + 1); }
    {char * tlv73; tlv73 = (char *)(cgc_strlen ( tlv74 ) + 1); }
    {void * tlv59; tlv59 = (void *)(cgc_strlen ( tlv74 ) + 1); }
    {cgc_size_t tlv58; tlv58 = (cgc_size_t)(cgc_strlen ( tlv74 ) + 1); }
    {void * tlv69; tlv69 = (void *)(cgc_strlen ( tlv74 ) + 1); }
    {cgc_size_t tlv68; tlv68 = (cgc_size_t)(cgc_strlen ( tlv74 ) + 1); }
    {char * tlv75; tlv75 = (char *)(cgc_strlen ( tlv74 ) + 1); }
    {char * tlv76; tlv76 = (char *)(cgc_strlen ( tlv74 ) + 1); }
}
void fix_ingred_genericParsers_1_60(){
fix_ingred_genericParsers_1_60_1();
}
void fix_ingred_genericParsers_1(){
fix_ingred_genericParsers_1_0();
fix_ingred_genericParsers_1_2();
fix_ingred_genericParsers_1_5();
fix_ingred_genericParsers_1_6();
fix_ingred_genericParsers_1_9();
fix_ingred_genericParsers_1_11();
fix_ingred_genericParsers_1_12();
fix_ingred_genericParsers_1_14();
fix_ingred_genericParsers_1_16();
fix_ingred_genericParsers_1_17();
fix_ingred_genericParsers_1_19();
fix_ingred_genericParsers_1_20();
fix_ingred_genericParsers_1_24();
fix_ingred_genericParsers_1_27();
fix_ingred_genericParsers_1_33();
fix_ingred_genericParsers_1_35();
fix_ingred_genericParsers_1_46();
fix_ingred_genericParsers_1_48();
fix_ingred_genericParsers_1_50();
fix_ingred_genericParsers_1_55();
fix_ingred_genericParsers_1_60();
}
void fix_ingred_genericParsers_2_0_0(){
string str_ref;
    bzero(&str_ref,1*sizeof(string));
pstring str = &str_ref;
    {char * name; name = (char *)(NULL); }
    {int ns; ns = (int)(NULL); }
    {int ne; ne = (int)(NULL); }
    {char tlv17; tlv17 = (char)(NULL); }
    {int tlv19; tlv19 = (int)(NULL); }
    {int tlv23; tlv23 = (int)(NULL); }
    {int tlv22; tlv22 = (int)(NULL); }
    {char tlv27; tlv27 = (char)(NULL); }
    {int tlv29; tlv29 = (int)(NULL); }
    {char tlv32; tlv32 = (char)(NULL); }
    {char tlv36; tlv36 = (char)(NULL); }
    {int tlv38; tlv38 = (int)(NULL); }
    {int tlv42; tlv42 = (int)(NULL); }
    {char tlv46; tlv46 = (char)(NULL); }
    {int tlv49; tlv49 = (int)(NULL); }
    {int tlv48; tlv48 = (int)(NULL); }
    {char * tlv68; tlv68 = (char *)(NULL); }
    {char * tlv69; tlv69 = (char *)(NULL); }
    {void * tlv56; tlv56 = (void *)(NULL); }
    {cgc_size_t tlv55; tlv55 = (cgc_size_t)(NULL); }
    {void * tlv66; tlv66 = (void *)(NULL); }
    {cgc_size_t tlv65; tlv65 = (cgc_size_t)(NULL); }
    {char * tlv70; tlv70 = (char *)(NULL); }
    {char * tlv71; tlv71 = (char *)(NULL); }
}
void fix_ingred_genericParsers_2_0_2(){
string str_ref;
    bzero(&str_ref,1*sizeof(string));
pstring str = &str_ref;
    {char * name; name = (char *)(0); }
    {int ns; ns = (int)(0); }
    {int ne; ne = (int)(0); }
    {char tlv17; tlv17 = (char)(0); }
    {int tlv19; tlv19 = (int)(0); }
    {int tlv23; tlv23 = (int)(0); }
    {int tlv22; tlv22 = (int)(0); }
    {char tlv27; tlv27 = (char)(0); }
    {int tlv29; tlv29 = (int)(0); }
    {char tlv32; tlv32 = (char)(0); }
    {char tlv36; tlv36 = (char)(0); }
    {int tlv38; tlv38 = (int)(0); }
    {int tlv42; tlv42 = (int)(0); }
    {char tlv46; tlv46 = (char)(0); }
    {int tlv49; tlv49 = (int)(0); }
    {int tlv48; tlv48 = (int)(0); }
    {char * tlv68; tlv68 = (char *)(0); }
    {char * tlv69; tlv69 = (char *)(0); }
    {void * tlv56; tlv56 = (void *)(0); }
    {cgc_size_t tlv55; tlv55 = (cgc_size_t)(0); }
    {void * tlv66; tlv66 = (void *)(0); }
    {cgc_size_t tlv65; tlv65 = (cgc_size_t)(0); }
    {char * tlv70; tlv70 = (char *)(0); }
    {char * tlv71; tlv71 = (char *)(0); }
}
void fix_ingred_genericParsers_2_0_6(){
string str_ref;
    bzero(&str_ref,1*sizeof(string));
pstring str = &str_ref;
    {char * name; name = (char *)(str -> index); }
    {int ns; ns = (int)(str -> index); }
    {int ne; ne = (int)(str -> index); }
    {char tlv17; tlv17 = (char)(str -> index); }
    {int tlv19; tlv19 = (int)(str -> index); }
    {int tlv23; tlv23 = (int)(str -> index); }
    {int tlv22; tlv22 = (int)(str -> index); }
    {char tlv27; tlv27 = (char)(str -> index); }
    {int tlv29; tlv29 = (int)(str -> index); }
    {char tlv32; tlv32 = (char)(str -> index); }
    {char tlv36; tlv36 = (char)(str -> index); }
    {int tlv38; tlv38 = (int)(str -> index); }
    {int tlv42; tlv42 = (int)(str -> index); }
    {char tlv46; tlv46 = (char)(str -> index); }
    {int tlv49; tlv49 = (int)(str -> index); }
    {int tlv48; tlv48 = (int)(str -> index); }
    {char * tlv68; tlv68 = (char *)(str -> index); }
    {char * tlv69; tlv69 = (char *)(str -> index); }
    {void * tlv56; tlv56 = (void *)(str -> index); }
    {cgc_size_t tlv55; tlv55 = (cgc_size_t)(str -> index); }
    {void * tlv66; tlv66 = (void *)(str -> index); }
    {cgc_size_t tlv65; tlv65 = (cgc_size_t)(str -> index); }
    {char * tlv70; tlv70 = (char *)(str -> index); }
    {char * tlv71; tlv71 = (char *)(str -> index); }
}
void fix_ingred_genericParsers_2_0(){
fix_ingred_genericParsers_2_0_0();
fix_ingred_genericParsers_2_0_2();
fix_ingred_genericParsers_2_0_6();
}
void fix_ingred_genericParsers_2_2_1(){
    {char * name; name = (char *)('{'); }
    {int ns; ns = (int)('{'); }
    {int ne; ne = (int)('{'); }
    {char tlv17; tlv17 = (char)('{'); }
    {int tlv19; tlv19 = (int)('{'); }
    {int tlv23; tlv23 = (int)('{'); }
    {int tlv22; tlv22 = (int)('{'); }
    {char tlv27; tlv27 = (char)('{'); }
    {int tlv29; tlv29 = (int)('{'); }
    {char tlv32; tlv32 = (char)('{'); }
    {char tlv36; tlv36 = (char)('{'); }
    {int tlv38; tlv38 = (int)('{'); }
    {int tlv42; tlv42 = (int)('{'); }
    {char tlv46; tlv46 = (char)('{'); }
    {int tlv49; tlv49 = (int)('{'); }
    {int tlv48; tlv48 = (int)('{'); }
    {char * tlv68; tlv68 = (char *)('{'); }
    {char * tlv69; tlv69 = (char *)('{'); }
    {void * tlv56; tlv56 = (void *)('{'); }
    {cgc_size_t tlv55; tlv55 = (cgc_size_t)('{'); }
    {void * tlv66; tlv66 = (void *)('{'); }
    {cgc_size_t tlv65; tlv65 = (cgc_size_t)('{'); }
    {char * tlv70; tlv70 = (char *)('{'); }
    {char * tlv71; tlv71 = (char *)('{'); }
}
void fix_ingred_genericParsers_2_2(){
fix_ingred_genericParsers_2_2_1();
}
void fix_ingred_genericParsers_2_5_1(){
    {char * name; name = (char *)(1); }
    {int ns; ns = (int)(1); }
    {int ne; ne = (int)(1); }
    {char tlv17; tlv17 = (char)(1); }
    {int tlv19; tlv19 = (int)(1); }
    {int tlv23; tlv23 = (int)(1); }
    {int tlv22; tlv22 = (int)(1); }
    {char tlv27; tlv27 = (char)(1); }
    {int tlv29; tlv29 = (int)(1); }
    {char tlv32; tlv32 = (char)(1); }
    {char tlv36; tlv36 = (char)(1); }
    {int tlv38; tlv38 = (int)(1); }
    {int tlv42; tlv42 = (int)(1); }
    {char tlv46; tlv46 = (char)(1); }
    {int tlv49; tlv49 = (int)(1); }
    {int tlv48; tlv48 = (int)(1); }
    {char * tlv68; tlv68 = (char *)(1); }
    {char * tlv69; tlv69 = (char *)(1); }
    {void * tlv56; tlv56 = (void *)(1); }
    {cgc_size_t tlv55; tlv55 = (cgc_size_t)(1); }
    {void * tlv66; tlv66 = (void *)(1); }
    {cgc_size_t tlv65; tlv65 = (cgc_size_t)(1); }
    {char * tlv70; tlv70 = (char *)(1); }
    {char * tlv71; tlv71 = (char *)(1); }
}
void fix_ingred_genericParsers_2_5(){
fix_ingred_genericParsers_2_5_1();
}
void fix_ingred_genericParsers_2_6_6(){
int tlv2;
    bzero(&tlv2,sizeof(int));
    {char * name; name = (char *)(tlv2); }
    {int ns; ns = (int)(tlv2); }
    {int ne; ne = (int)(tlv2); }
    {char tlv17; tlv17 = (char)(tlv2); }
    {int tlv19; tlv19 = (int)(tlv2); }
    {int tlv23; tlv23 = (int)(tlv2); }
    {int tlv22; tlv22 = (int)(tlv2); }
    {char tlv27; tlv27 = (char)(tlv2); }
    {int tlv29; tlv29 = (int)(tlv2); }
    {char tlv32; tlv32 = (char)(tlv2); }
    {int tlv34; tlv34 = (int)(tlv2); }
    {char tlv36; tlv36 = (char)(tlv2); }
    {int tlv38; tlv38 = (int)(tlv2); }
    {int tlv42; tlv42 = (int)(tlv2); }
    {int tlv41; tlv41 = (int)(tlv2); }
    {char tlv46; tlv46 = (char)(tlv2); }
    {int tlv49; tlv49 = (int)(tlv2); }
    {int tlv48; tlv48 = (int)(tlv2); }
    {char * tlv68; tlv68 = (char *)(tlv2); }
    {char * tlv69; tlv69 = (char *)(tlv2); }
    {void * tlv56; tlv56 = (void *)(tlv2); }
    {cgc_size_t tlv55; tlv55 = (cgc_size_t)(tlv2); }
    {void * tlv66; tlv66 = (void *)(tlv2); }
    {cgc_size_t tlv65; tlv65 = (cgc_size_t)(tlv2); }
    {char * tlv70; tlv70 = (char *)(tlv2); }
    {char * tlv71; tlv71 = (char *)(tlv2); }
}
void fix_ingred_genericParsers_2_6_7(){
int tlv2;
    bzero(&tlv2,sizeof(int));
    {char * name; name = (char *)(- 1); }
    {int ns; ns = (int)(- 1); }
    {int ne; ne = (int)(- 1); }
    {char tlv17; tlv17 = (char)(- 1); }
    {int tlv19; tlv19 = (int)(- 1); }
    {int tlv23; tlv23 = (int)(- 1); }
    {int tlv22; tlv22 = (int)(- 1); }
    {char tlv27; tlv27 = (char)(- 1); }
    {int tlv29; tlv29 = (int)(- 1); }
    {char tlv32; tlv32 = (char)(- 1); }
    {char tlv36; tlv36 = (char)(- 1); }
    {int tlv38; tlv38 = (int)(- 1); }
    {int tlv42; tlv42 = (int)(- 1); }
    {char tlv46; tlv46 = (char)(- 1); }
    {int tlv49; tlv49 = (int)(- 1); }
    {int tlv48; tlv48 = (int)(- 1); }
    {char * tlv68; tlv68 = (char *)(- 1); }
    {char * tlv69; tlv69 = (char *)(- 1); }
    {void * tlv56; tlv56 = (void *)(- 1); }
    {cgc_size_t tlv55; tlv55 = (cgc_size_t)(- 1); }
    {void * tlv66; tlv66 = (void *)(- 1); }
    {cgc_size_t tlv65; tlv65 = (cgc_size_t)(- 1); }
    {char * tlv70; tlv70 = (char *)(- 1); }
    {char * tlv71; tlv71 = (char *)(- 1); }
}
void fix_ingred_genericParsers_2_6(){
fix_ingred_genericParsers_2_6_6();
fix_ingred_genericParsers_2_6_7();
}
void fix_ingred_genericParsers_2_9_7(){
int end;
    bzero(&end,sizeof(int));
    {char * name; name = (char *)(end); }
    {int ns; ns = (int)(end); }
    {int ne; ne = (int)(end); }
    {char tlv17; tlv17 = (char)(end); }
    {int tlv19; tlv19 = (int)(end); }
    {int tlv23; tlv23 = (int)(end); }
    {int tlv22; tlv22 = (int)(end); }
    {char tlv27; tlv27 = (char)(end); }
    {int tlv29; tlv29 = (int)(end); }
    {char tlv32; tlv32 = (char)(end); }
    {char tlv36; tlv36 = (char)(end); }
    {int tlv38; tlv38 = (int)(end); }
    {int tlv42; tlv42 = (int)(end); }
    {char tlv46; tlv46 = (char)(end); }
    {int tlv49; tlv49 = (int)(end); }
    {int tlv48; tlv48 = (int)(end); }
    {char * tlv68; tlv68 = (char *)(end); }
    {char * tlv69; tlv69 = (char *)(end); }
    {void * tlv56; tlv56 = (void *)(end); }
    {cgc_size_t tlv55; tlv55 = (cgc_size_t)(end); }
    {void * tlv66; tlv66 = (void *)(end); }
    {cgc_size_t tlv65; tlv65 = (cgc_size_t)(end); }
    {char * tlv70; tlv70 = (char *)(end); }
    {char * tlv71; tlv71 = (char *)(end); }
}
void fix_ingred_genericParsers_2_9(){
fix_ingred_genericParsers_2_9_7();
}
void fix_ingred_genericParsers_2_11_1(){
int start;
    bzero(&start,sizeof(int));
    {char * name; name = (char *)(start); }
    {int ns; ns = (int)(start); }
    {int ne; ne = (int)(start); }
    {char tlv17; tlv17 = (char)(start); }
    {int tlv19; tlv19 = (int)(start); }
    {int tlv23; tlv23 = (int)(start); }
    {int tlv22; tlv22 = (int)(start); }
    {char tlv27; tlv27 = (char)(start); }
    {int tlv29; tlv29 = (int)(start); }
    {char tlv32; tlv32 = (char)(start); }
    {char tlv36; tlv36 = (char)(start); }
    {int tlv38; tlv38 = (int)(start); }
    {int tlv42; tlv42 = (int)(start); }
    {char tlv46; tlv46 = (char)(start); }
    {int tlv49; tlv49 = (int)(start); }
    {int tlv48; tlv48 = (int)(start); }
    {char * tlv68; tlv68 = (char *)(start); }
    {char * tlv69; tlv69 = (char *)(start); }
    {void * tlv56; tlv56 = (void *)(start); }
    {cgc_size_t tlv55; tlv55 = (cgc_size_t)(start); }
    {void * tlv66; tlv66 = (void *)(start); }
    {cgc_size_t tlv65; tlv65 = (cgc_size_t)(start); }
    {char * tlv70; tlv70 = (char *)(start); }
    {char * tlv71; tlv71 = (char *)(start); }
}
void fix_ingred_genericParsers_2_11(){
fix_ingred_genericParsers_2_11_1();
}
void fix_ingred_genericParsers_2_12_7(){
char temp_ref;
    bzero(&temp_ref,1*sizeof(char));
char * temp = &temp_ref;
    {char * name; name = (char *)(temp); }
    {int ns; ns = (int)(temp); }
    {int ne; ne = (int)(temp); }
    {char tlv17; tlv17 = (char)(temp); }
    {int tlv19; tlv19 = (int)(temp); }
    {int tlv23; tlv23 = (int)(temp); }
    {int tlv22; tlv22 = (int)(temp); }
    {char tlv27; tlv27 = (char)(temp); }
    {int tlv29; tlv29 = (int)(temp); }
    {char tlv32; tlv32 = (char)(temp); }
    {char tlv36; tlv36 = (char)(temp); }
    {int tlv38; tlv38 = (int)(temp); }
    {int tlv42; tlv42 = (int)(temp); }
    {char tlv46; tlv46 = (char)(temp); }
    {int tlv49; tlv49 = (int)(temp); }
    {int tlv48; tlv48 = (int)(temp); }
    {char * tlv68; tlv68 = (char *)(temp); }
    {char * tlv69; tlv69 = (char *)(temp); }
    {void * tlv56; tlv56 = (void *)(temp); }
    {cgc_size_t tlv55; tlv55 = (cgc_size_t)(temp); }
    {void * tlv66; tlv66 = (void *)(temp); }
    {cgc_size_t tlv65; tlv65 = (cgc_size_t)(temp); }
    {char * tlv70; tlv70 = (char *)(temp); }
    {char * tlv71; tlv71 = (char *)(temp); }
}
void fix_ingred_genericParsers_2_12(){
fix_ingred_genericParsers_2_12_7();
}
void fix_ingred_genericParsers_2_14_8(){
int tlv3;
    bzero(&tlv3,sizeof(int));
    {char * name; name = (char *)(tlv3); }
    {int ns; ns = (int)(tlv3); }
    {int ne; ne = (int)(tlv3); }
    {char tlv17; tlv17 = (char)(tlv3); }
    {int tlv19; tlv19 = (int)(tlv3); }
    {int tlv23; tlv23 = (int)(tlv3); }
    {int tlv22; tlv22 = (int)(tlv3); }
    {char tlv27; tlv27 = (char)(tlv3); }
    {int tlv29; tlv29 = (int)(tlv3); }
    {char tlv32; tlv32 = (char)(tlv3); }
    {char tlv36; tlv36 = (char)(tlv3); }
    {int tlv38; tlv38 = (int)(tlv3); }
    {int tlv42; tlv42 = (int)(tlv3); }
    {char tlv46; tlv46 = (char)(tlv3); }
    {int tlv49; tlv49 = (int)(tlv3); }
    {int tlv48; tlv48 = (int)(tlv3); }
    {char * tlv68; tlv68 = (char *)(tlv3); }
    {char * tlv69; tlv69 = (char *)(tlv3); }
    {void * tlv56; tlv56 = (void *)(tlv3); }
    {cgc_size_t tlv55; tlv55 = (cgc_size_t)(tlv3); }
    {void * tlv66; tlv66 = (void *)(tlv3); }
    {cgc_size_t tlv65; tlv65 = (cgc_size_t)(tlv3); }
    {char * tlv70; tlv70 = (char *)(tlv3); }
    {char * tlv71; tlv71 = (char *)(tlv3); }
}
void fix_ingred_genericParsers_2_14(){
fix_ingred_genericParsers_2_14_8();
}
void fix_ingred_genericParsers_2_16_0(){
char temp_ref;
    bzero(&temp_ref,1*sizeof(char));
char * temp = &temp_ref;
    {char * name; name = (char *)(temp); }
    {int ns; ns = (int)(temp); }
    {int ne; ne = (int)(temp); }
    {char tlv17; tlv17 = (char)(temp); }
    {int tlv19; tlv19 = (int)(temp); }
    {int tlv23; tlv23 = (int)(temp); }
    {int tlv22; tlv22 = (int)(temp); }
    {char tlv27; tlv27 = (char)(temp); }
    {int tlv29; tlv29 = (int)(temp); }
    {char tlv32; tlv32 = (char)(temp); }
    {char tlv36; tlv36 = (char)(temp); }
    {int tlv38; tlv38 = (int)(temp); }
    {int tlv42; tlv42 = (int)(temp); }
    {char tlv46; tlv46 = (char)(temp); }
    {int tlv49; tlv49 = (int)(temp); }
    {int tlv48; tlv48 = (int)(temp); }
    {char * tlv68; tlv68 = (char *)(temp); }
    {char * tlv69; tlv69 = (char *)(temp); }
    {void * tlv56; tlv56 = (void *)(temp); }
    {cgc_size_t tlv55; tlv55 = (cgc_size_t)(temp); }
    {void * tlv66; tlv66 = (void *)(temp); }
    {cgc_size_t tlv65; tlv65 = (cgc_size_t)(temp); }
    {char * tlv70; tlv70 = (char *)(temp); }
    {char * tlv71; tlv71 = (char *)(temp); }
}
void fix_ingred_genericParsers_2_16(){
fix_ingred_genericParsers_2_16_0();
}
void fix_ingred_genericParsers_2_17_1(){
char tlv70_ref;
    bzero(&tlv70_ref,1*sizeof(char));
char * tlv70 = &tlv70_ref;
    {char * temp; temp = (char *)(cgc_strlen ( tlv70 ) + 1); }
    {char * name; name = (char *)(cgc_strlen ( tlv70 ) + 1); }
    {int start; start = (int)(cgc_strlen ( tlv70 ) + 1); }
    {int end; end = (int)(cgc_strlen ( tlv70 ) + 1); }
    {int ns; ns = (int)(cgc_strlen ( tlv70 ) + 1); }
    {int ne; ne = (int)(cgc_strlen ( tlv70 ) + 1); }
    {int tlv1; tlv1 = (int)(cgc_strlen ( tlv70 ) + 1); }
    {int tlv2; tlv2 = (int)(cgc_strlen ( tlv70 ) + 1); }
    {int tlv3; tlv3 = (int)(cgc_strlen ( tlv70 ) + 1); }
    {int tlv4; tlv4 = (int)(cgc_strlen ( tlv70 ) + 1); }
    {int tlv5; tlv5 = (int)(cgc_strlen ( tlv70 ) + 1); }
    {int tlv6; tlv6 = (int)(cgc_strlen ( tlv70 ) + 1); }
    {int tlv7; tlv7 = (int)(cgc_strlen ( tlv70 ) + 1); }
    {int tlv8; tlv8 = (int)(cgc_strlen ( tlv70 ) + 1); }
    {int tlv9; tlv9 = (int)(cgc_strlen ( tlv70 ) + 1); }
    {int tlv10; tlv10 = (int)(cgc_strlen ( tlv70 ) + 1); }
    {char tlv17; tlv17 = (char)(cgc_strlen ( tlv70 ) + 1); }
    {int tlv19; tlv19 = (int)(cgc_strlen ( tlv70 ) + 1); }
    {int tlv23; tlv23 = (int)(cgc_strlen ( tlv70 ) + 1); }
    {int tlv22; tlv22 = (int)(cgc_strlen ( tlv70 ) + 1); }
    {void * tlv12; tlv12 = (void *)(cgc_strlen ( tlv70 ) + 1); }
    {cgc_size_t tlv11; tlv11 = (cgc_size_t)(cgc_strlen ( tlv70 ) + 1); }
    {char tlv27; tlv27 = (char)(cgc_strlen ( tlv70 ) + 1); }
    {int tlv29; tlv29 = (int)(cgc_strlen ( tlv70 ) + 1); }
    {char tlv32; tlv32 = (char)(cgc_strlen ( tlv70 ) + 1); }
    {int tlv34; tlv34 = (int)(cgc_strlen ( tlv70 ) + 1); }
    {char tlv36; tlv36 = (char)(cgc_strlen ( tlv70 ) + 1); }
    {int tlv38; tlv38 = (int)(cgc_strlen ( tlv70 ) + 1); }
    {int tlv42; tlv42 = (int)(cgc_strlen ( tlv70 ) + 1); }
    {int tlv41; tlv41 = (int)(cgc_strlen ( tlv70 ) + 1); }
    {void * tlv14; tlv14 = (void *)(cgc_strlen ( tlv70 ) + 1); }
    {cgc_size_t tlv13; tlv13 = (cgc_size_t)(cgc_strlen ( tlv70 ) + 1); }
    {char tlv46; tlv46 = (char)(cgc_strlen ( tlv70 ) + 1); }
    {int tlv15; tlv15 = (int)(cgc_strlen ( tlv70 ) + 1); }
    {int tlv49; tlv49 = (int)(cgc_strlen ( tlv70 ) + 1); }
    {int tlv48; tlv48 = (int)(cgc_strlen ( tlv70 ) + 1); }
    {char * tlv68; tlv68 = (char *)(cgc_strlen ( tlv70 ) + 1); }
    {char * tlv69; tlv69 = (char *)(cgc_strlen ( tlv70 ) + 1); }
    {void * tlv56; tlv56 = (void *)(cgc_strlen ( tlv70 ) + 1); }
    {cgc_size_t tlv55; tlv55 = (cgc_size_t)(cgc_strlen ( tlv70 ) + 1); }
    {void * tlv66; tlv66 = (void *)(cgc_strlen ( tlv70 ) + 1); }
    {cgc_size_t tlv65; tlv65 = (cgc_size_t)(cgc_strlen ( tlv70 ) + 1); }
    {char * tlv71; tlv71 = (char *)(cgc_strlen ( tlv70 ) + 1); }
}
void fix_ingred_genericParsers_2_17(){
fix_ingred_genericParsers_2_17_1();
}
void fix_ingred_genericParsers_2_19_1(){
char tlv68_ref;
    bzero(&tlv68_ref,1*sizeof(char));
char * tlv68 = &tlv68_ref;
    {char * temp; temp = (char *)(cgc_strlen ( tlv68 ) + 1); }
    {char * name; name = (char *)(cgc_strlen ( tlv68 ) + 1); }
    {int start; start = (int)(cgc_strlen ( tlv68 ) + 1); }
    {int end; end = (int)(cgc_strlen ( tlv68 ) + 1); }
    {int ns; ns = (int)(cgc_strlen ( tlv68 ) + 1); }
    {int ne; ne = (int)(cgc_strlen ( tlv68 ) + 1); }
    {int tlv1; tlv1 = (int)(cgc_strlen ( tlv68 ) + 1); }
    {int tlv2; tlv2 = (int)(cgc_strlen ( tlv68 ) + 1); }
    {int tlv3; tlv3 = (int)(cgc_strlen ( tlv68 ) + 1); }
    {int tlv4; tlv4 = (int)(cgc_strlen ( tlv68 ) + 1); }
    {int tlv5; tlv5 = (int)(cgc_strlen ( tlv68 ) + 1); }
    {int tlv6; tlv6 = (int)(cgc_strlen ( tlv68 ) + 1); }
    {int tlv7; tlv7 = (int)(cgc_strlen ( tlv68 ) + 1); }
    {int tlv8; tlv8 = (int)(cgc_strlen ( tlv68 ) + 1); }
    {int tlv9; tlv9 = (int)(cgc_strlen ( tlv68 ) + 1); }
    {int tlv10; tlv10 = (int)(cgc_strlen ( tlv68 ) + 1); }
    {char tlv17; tlv17 = (char)(cgc_strlen ( tlv68 ) + 1); }
    {int tlv19; tlv19 = (int)(cgc_strlen ( tlv68 ) + 1); }
    {int tlv23; tlv23 = (int)(cgc_strlen ( tlv68 ) + 1); }
    {int tlv22; tlv22 = (int)(cgc_strlen ( tlv68 ) + 1); }
    {void * tlv12; tlv12 = (void *)(cgc_strlen ( tlv68 ) + 1); }
    {cgc_size_t tlv11; tlv11 = (cgc_size_t)(cgc_strlen ( tlv68 ) + 1); }
    {char tlv27; tlv27 = (char)(cgc_strlen ( tlv68 ) + 1); }
    {int tlv29; tlv29 = (int)(cgc_strlen ( tlv68 ) + 1); }
    {char tlv32; tlv32 = (char)(cgc_strlen ( tlv68 ) + 1); }
    {int tlv34; tlv34 = (int)(cgc_strlen ( tlv68 ) + 1); }
    {char tlv36; tlv36 = (char)(cgc_strlen ( tlv68 ) + 1); }
    {int tlv38; tlv38 = (int)(cgc_strlen ( tlv68 ) + 1); }
    {int tlv42; tlv42 = (int)(cgc_strlen ( tlv68 ) + 1); }
    {int tlv41; tlv41 = (int)(cgc_strlen ( tlv68 ) + 1); }
    {void * tlv14; tlv14 = (void *)(cgc_strlen ( tlv68 ) + 1); }
    {cgc_size_t tlv13; tlv13 = (cgc_size_t)(cgc_strlen ( tlv68 ) + 1); }
    {char tlv46; tlv46 = (char)(cgc_strlen ( tlv68 ) + 1); }
    {int tlv15; tlv15 = (int)(cgc_strlen ( tlv68 ) + 1); }
    {int tlv49; tlv49 = (int)(cgc_strlen ( tlv68 ) + 1); }
    {int tlv48; tlv48 = (int)(cgc_strlen ( tlv68 ) + 1); }
    {char * tlv69; tlv69 = (char *)(cgc_strlen ( tlv68 ) + 1); }
    {void * tlv56; tlv56 = (void *)(cgc_strlen ( tlv68 ) + 1); }
    {cgc_size_t tlv55; tlv55 = (cgc_size_t)(cgc_strlen ( tlv68 ) + 1); }
    {void * tlv66; tlv66 = (void *)(cgc_strlen ( tlv68 ) + 1); }
    {cgc_size_t tlv65; tlv65 = (cgc_size_t)(cgc_strlen ( tlv68 ) + 1); }
    {char * tlv70; tlv70 = (char *)(cgc_strlen ( tlv68 ) + 1); }
    {char * tlv71; tlv71 = (char *)(cgc_strlen ( tlv68 ) + 1); }
}
void fix_ingred_genericParsers_2_19(){
fix_ingred_genericParsers_2_19_1();
}
void fix_ingred_genericParsers_2_20_1(){
    {char * name; name = (char *)('}'); }
    {int ns; ns = (int)('}'); }
    {int ne; ne = (int)('}'); }
    {char tlv17; tlv17 = (char)('}'); }
    {int tlv19; tlv19 = (int)('}'); }
    {int tlv23; tlv23 = (int)('}'); }
    {int tlv22; tlv22 = (int)('}'); }
    {char tlv27; tlv27 = (char)('}'); }
    {int tlv29; tlv29 = (int)('}'); }
    {char tlv32; tlv32 = (char)('}'); }
    {char tlv36; tlv36 = (char)('}'); }
    {int tlv38; tlv38 = (int)('}'); }
    {int tlv42; tlv42 = (int)('}'); }
    {char tlv46; tlv46 = (char)('}'); }
    {int tlv49; tlv49 = (int)('}'); }
    {int tlv48; tlv48 = (int)('}'); }
    {char * tlv68; tlv68 = (char *)('}'); }
    {char * tlv69; tlv69 = (char *)('}'); }
    {void * tlv56; tlv56 = (void *)('}'); }
    {cgc_size_t tlv55; tlv55 = (cgc_size_t)('}'); }
    {void * tlv66; tlv66 = (void *)('}'); }
    {cgc_size_t tlv65; tlv65 = (cgc_size_t)('}'); }
    {char * tlv70; tlv70 = (char *)('}'); }
    {char * tlv71; tlv71 = (char *)('}'); }
}
void fix_ingred_genericParsers_2_20(){
fix_ingred_genericParsers_2_20_1();
}
void fix_ingred_genericParsers_2_24_7(){
int tlv5;
    bzero(&tlv5,sizeof(int));
    {char * name; name = (char *)(tlv5); }
    {int ns; ns = (int)(tlv5); }
    {int ne; ne = (int)(tlv5); }
    {char tlv17; tlv17 = (char)(tlv5); }
    {int tlv19; tlv19 = (int)(tlv5); }
    {int tlv23; tlv23 = (int)(tlv5); }
    {int tlv22; tlv22 = (int)(tlv5); }
    {char tlv27; tlv27 = (char)(tlv5); }
    {int tlv29; tlv29 = (int)(tlv5); }
    {char tlv32; tlv32 = (char)(tlv5); }
    {int tlv34; tlv34 = (int)(tlv5); }
    {char tlv36; tlv36 = (char)(tlv5); }
    {int tlv38; tlv38 = (int)(tlv5); }
    {int tlv42; tlv42 = (int)(tlv5); }
    {int tlv41; tlv41 = (int)(tlv5); }
    {char tlv46; tlv46 = (char)(tlv5); }
    {int tlv49; tlv49 = (int)(tlv5); }
    {int tlv48; tlv48 = (int)(tlv5); }
    {char * tlv68; tlv68 = (char *)(tlv5); }
    {char * tlv69; tlv69 = (char *)(tlv5); }
    {void * tlv56; tlv56 = (void *)(tlv5); }
    {cgc_size_t tlv55; tlv55 = (cgc_size_t)(tlv5); }
    {void * tlv66; tlv66 = (void *)(tlv5); }
    {cgc_size_t tlv65; tlv65 = (cgc_size_t)(tlv5); }
    {char * tlv70; tlv70 = (char *)(tlv5); }
    {char * tlv71; tlv71 = (char *)(tlv5); }
}
void fix_ingred_genericParsers_2_24(){
fix_ingred_genericParsers_2_24_7();
}
void fix_ingred_genericParsers_2_27_8(){
int ne;
    bzero(&ne,sizeof(int));
    {char * temp; temp = (char *)(ne); }
    {char * name; name = (char *)(ne); }
    {int start; start = (int)(ne); }
    {int end; end = (int)(ne); }
    {int ns; ns = (int)(ne); }
    {int tlv1; tlv1 = (int)(ne); }
    {int tlv2; tlv2 = (int)(ne); }
    {int tlv3; tlv3 = (int)(ne); }
    {int tlv4; tlv4 = (int)(ne); }
    {int tlv5; tlv5 = (int)(ne); }
    {int tlv6; tlv6 = (int)(ne); }
    {int tlv7; tlv7 = (int)(ne); }
    {int tlv8; tlv8 = (int)(ne); }
    {int tlv9; tlv9 = (int)(ne); }
    {int tlv10; tlv10 = (int)(ne); }
    {char tlv17; tlv17 = (char)(ne); }
    {int tlv19; tlv19 = (int)(ne); }
    {int tlv23; tlv23 = (int)(ne); }
    {int tlv22; tlv22 = (int)(ne); }
    {void * tlv12; tlv12 = (void *)(ne); }
    {cgc_size_t tlv11; tlv11 = (cgc_size_t)(ne); }
    {char tlv27; tlv27 = (char)(ne); }
    {int tlv29; tlv29 = (int)(ne); }
    {char tlv32; tlv32 = (char)(ne); }
    {int tlv34; tlv34 = (int)(ne); }
    {char tlv36; tlv36 = (char)(ne); }
    {int tlv38; tlv38 = (int)(ne); }
    {int tlv42; tlv42 = (int)(ne); }
    {int tlv41; tlv41 = (int)(ne); }
    {void * tlv14; tlv14 = (void *)(ne); }
    {cgc_size_t tlv13; tlv13 = (cgc_size_t)(ne); }
    {char tlv46; tlv46 = (char)(ne); }
    {int tlv15; tlv15 = (int)(ne); }
    {int tlv49; tlv49 = (int)(ne); }
    {int tlv48; tlv48 = (int)(ne); }
    {char * tlv68; tlv68 = (char *)(ne); }
    {char * tlv69; tlv69 = (char *)(ne); }
    {void * tlv56; tlv56 = (void *)(ne); }
    {cgc_size_t tlv55; tlv55 = (cgc_size_t)(ne); }
    {void * tlv66; tlv66 = (void *)(ne); }
    {cgc_size_t tlv65; tlv65 = (cgc_size_t)(ne); }
    {char * tlv70; tlv70 = (char *)(ne); }
    {char * tlv71; tlv71 = (char *)(ne); }
}
void fix_ingred_genericParsers_2_27(){
fix_ingred_genericParsers_2_27_8();
}
void fix_ingred_genericParsers_2_33_8(){
int tlv7;
    bzero(&tlv7,sizeof(int));
    {char * name; name = (char *)(tlv7); }
    {int ns; ns = (int)(tlv7); }
    {int ne; ne = (int)(tlv7); }
    {char tlv17; tlv17 = (char)(tlv7); }
    {int tlv19; tlv19 = (int)(tlv7); }
    {int tlv23; tlv23 = (int)(tlv7); }
    {int tlv22; tlv22 = (int)(tlv7); }
    {char tlv27; tlv27 = (char)(tlv7); }
    {int tlv29; tlv29 = (int)(tlv7); }
    {char tlv32; tlv32 = (char)(tlv7); }
    {int tlv34; tlv34 = (int)(tlv7); }
    {char tlv36; tlv36 = (char)(tlv7); }
    {int tlv38; tlv38 = (int)(tlv7); }
    {int tlv42; tlv42 = (int)(tlv7); }
    {int tlv41; tlv41 = (int)(tlv7); }
    {char tlv46; tlv46 = (char)(tlv7); }
    {int tlv49; tlv49 = (int)(tlv7); }
    {int tlv48; tlv48 = (int)(tlv7); }
    {char * tlv68; tlv68 = (char *)(tlv7); }
    {char * tlv69; tlv69 = (char *)(tlv7); }
    {void * tlv56; tlv56 = (void *)(tlv7); }
    {cgc_size_t tlv55; tlv55 = (cgc_size_t)(tlv7); }
    {void * tlv66; tlv66 = (void *)(tlv7); }
    {cgc_size_t tlv65; tlv65 = (cgc_size_t)(tlv7); }
    {char * tlv70; tlv70 = (char *)(tlv7); }
    {char * tlv71; tlv71 = (char *)(tlv7); }
}
void fix_ingred_genericParsers_2_33(){
fix_ingred_genericParsers_2_33_8();
}
void fix_ingred_genericParsers_2_35_1(){
    {char * name; name = (char *)('#'); }
    {int ns; ns = (int)('#'); }
    {int ne; ne = (int)('#'); }
    {char tlv17; tlv17 = (char)('#'); }
    {int tlv19; tlv19 = (int)('#'); }
    {int tlv23; tlv23 = (int)('#'); }
    {int tlv22; tlv22 = (int)('#'); }
    {char tlv27; tlv27 = (char)('#'); }
    {int tlv29; tlv29 = (int)('#'); }
    {char tlv32; tlv32 = (char)('#'); }
    {char tlv36; tlv36 = (char)('#'); }
    {int tlv38; tlv38 = (int)('#'); }
    {int tlv42; tlv42 = (int)('#'); }
    {char tlv46; tlv46 = (char)('#'); }
    {int tlv49; tlv49 = (int)('#'); }
    {int tlv48; tlv48 = (int)('#'); }
    {char * tlv68; tlv68 = (char *)('#'); }
    {char * tlv69; tlv69 = (char *)('#'); }
    {void * tlv56; tlv56 = (void *)('#'); }
    {cgc_size_t tlv55; tlv55 = (cgc_size_t)('#'); }
    {void * tlv66; tlv66 = (void *)('#'); }
    {cgc_size_t tlv65; tlv65 = (cgc_size_t)('#'); }
    {char * tlv70; tlv70 = (char *)('#'); }
    {char * tlv71; tlv71 = (char *)('#'); }
}
void fix_ingred_genericParsers_2_35(){
fix_ingred_genericParsers_2_35_1();
}
void fix_ingred_genericParsers_2_46_8(){
int tlv9;
    bzero(&tlv9,sizeof(int));
    {char * name; name = (char *)(tlv9); }
    {int ns; ns = (int)(tlv9); }
    {int ne; ne = (int)(tlv9); }
    {char tlv17; tlv17 = (char)(tlv9); }
    {int tlv19; tlv19 = (int)(tlv9); }
    {int tlv23; tlv23 = (int)(tlv9); }
    {int tlv22; tlv22 = (int)(tlv9); }
    {char tlv27; tlv27 = (char)(tlv9); }
    {int tlv29; tlv29 = (int)(tlv9); }
    {char tlv32; tlv32 = (char)(tlv9); }
    {int tlv34; tlv34 = (int)(tlv9); }
    {char tlv36; tlv36 = (char)(tlv9); }
    {int tlv38; tlv38 = (int)(tlv9); }
    {int tlv42; tlv42 = (int)(tlv9); }
    {int tlv41; tlv41 = (int)(tlv9); }
    {char tlv46; tlv46 = (char)(tlv9); }
    {int tlv49; tlv49 = (int)(tlv9); }
    {int tlv48; tlv48 = (int)(tlv9); }
    {char * tlv68; tlv68 = (char *)(tlv9); }
    {char * tlv69; tlv69 = (char *)(tlv9); }
    {void * tlv56; tlv56 = (void *)(tlv9); }
    {cgc_size_t tlv55; tlv55 = (cgc_size_t)(tlv9); }
    {void * tlv66; tlv66 = (void *)(tlv9); }
    {cgc_size_t tlv65; tlv65 = (cgc_size_t)(tlv9); }
    {char * tlv70; tlv70 = (char *)(tlv9); }
    {char * tlv71; tlv71 = (char *)(tlv9); }
}
void fix_ingred_genericParsers_2_46(){
fix_ingred_genericParsers_2_46_8();
}
void fix_ingred_genericParsers_2_48_1(){
char tlv71_ref;
    bzero(&tlv71_ref,1*sizeof(char));
char * tlv71 = &tlv71_ref;
    {char * temp; temp = (char *)(cgc_strlen ( tlv71 ) + 1); }
    {char * name; name = (char *)(cgc_strlen ( tlv71 ) + 1); }
    {int start; start = (int)(cgc_strlen ( tlv71 ) + 1); }
    {int end; end = (int)(cgc_strlen ( tlv71 ) + 1); }
    {int ns; ns = (int)(cgc_strlen ( tlv71 ) + 1); }
    {int ne; ne = (int)(cgc_strlen ( tlv71 ) + 1); }
    {int tlv1; tlv1 = (int)(cgc_strlen ( tlv71 ) + 1); }
    {int tlv2; tlv2 = (int)(cgc_strlen ( tlv71 ) + 1); }
    {int tlv3; tlv3 = (int)(cgc_strlen ( tlv71 ) + 1); }
    {int tlv4; tlv4 = (int)(cgc_strlen ( tlv71 ) + 1); }
    {int tlv5; tlv5 = (int)(cgc_strlen ( tlv71 ) + 1); }
    {int tlv6; tlv6 = (int)(cgc_strlen ( tlv71 ) + 1); }
    {int tlv7; tlv7 = (int)(cgc_strlen ( tlv71 ) + 1); }
    {int tlv8; tlv8 = (int)(cgc_strlen ( tlv71 ) + 1); }
    {int tlv9; tlv9 = (int)(cgc_strlen ( tlv71 ) + 1); }
    {int tlv10; tlv10 = (int)(cgc_strlen ( tlv71 ) + 1); }
    {char tlv17; tlv17 = (char)(cgc_strlen ( tlv71 ) + 1); }
    {int tlv19; tlv19 = (int)(cgc_strlen ( tlv71 ) + 1); }
    {int tlv23; tlv23 = (int)(cgc_strlen ( tlv71 ) + 1); }
    {int tlv22; tlv22 = (int)(cgc_strlen ( tlv71 ) + 1); }
    {void * tlv12; tlv12 = (void *)(cgc_strlen ( tlv71 ) + 1); }
    {cgc_size_t tlv11; tlv11 = (cgc_size_t)(cgc_strlen ( tlv71 ) + 1); }
    {char tlv27; tlv27 = (char)(cgc_strlen ( tlv71 ) + 1); }
    {int tlv29; tlv29 = (int)(cgc_strlen ( tlv71 ) + 1); }
    {char tlv32; tlv32 = (char)(cgc_strlen ( tlv71 ) + 1); }
    {int tlv34; tlv34 = (int)(cgc_strlen ( tlv71 ) + 1); }
    {char tlv36; tlv36 = (char)(cgc_strlen ( tlv71 ) + 1); }
    {int tlv38; tlv38 = (int)(cgc_strlen ( tlv71 ) + 1); }
    {int tlv42; tlv42 = (int)(cgc_strlen ( tlv71 ) + 1); }
    {int tlv41; tlv41 = (int)(cgc_strlen ( tlv71 ) + 1); }
    {void * tlv14; tlv14 = (void *)(cgc_strlen ( tlv71 ) + 1); }
    {cgc_size_t tlv13; tlv13 = (cgc_size_t)(cgc_strlen ( tlv71 ) + 1); }
    {char tlv46; tlv46 = (char)(cgc_strlen ( tlv71 ) + 1); }
    {int tlv15; tlv15 = (int)(cgc_strlen ( tlv71 ) + 1); }
    {int tlv49; tlv49 = (int)(cgc_strlen ( tlv71 ) + 1); }
    {int tlv48; tlv48 = (int)(cgc_strlen ( tlv71 ) + 1); }
    {char * tlv68; tlv68 = (char *)(cgc_strlen ( tlv71 ) + 1); }
    {char * tlv69; tlv69 = (char *)(cgc_strlen ( tlv71 ) + 1); }
    {void * tlv56; tlv56 = (void *)(cgc_strlen ( tlv71 ) + 1); }
    {cgc_size_t tlv55; tlv55 = (cgc_size_t)(cgc_strlen ( tlv71 ) + 1); }
    {void * tlv66; tlv66 = (void *)(cgc_strlen ( tlv71 ) + 1); }
    {cgc_size_t tlv65; tlv65 = (cgc_size_t)(cgc_strlen ( tlv71 ) + 1); }
    {char * tlv70; tlv70 = (char *)(cgc_strlen ( tlv71 ) + 1); }
}
void fix_ingred_genericParsers_2_48(){
fix_ingred_genericParsers_2_48_1();
}
void fix_ingred_genericParsers_2_50_1(){
char tlv69_ref;
    bzero(&tlv69_ref,1*sizeof(char));
char * tlv69 = &tlv69_ref;
    {char * temp; temp = (char *)(cgc_strlen ( tlv69 ) + 1); }
    {char * name; name = (char *)(cgc_strlen ( tlv69 ) + 1); }
    {int start; start = (int)(cgc_strlen ( tlv69 ) + 1); }
    {int end; end = (int)(cgc_strlen ( tlv69 ) + 1); }
    {int ns; ns = (int)(cgc_strlen ( tlv69 ) + 1); }
    {int ne; ne = (int)(cgc_strlen ( tlv69 ) + 1); }
    {int tlv1; tlv1 = (int)(cgc_strlen ( tlv69 ) + 1); }
    {int tlv2; tlv2 = (int)(cgc_strlen ( tlv69 ) + 1); }
    {int tlv3; tlv3 = (int)(cgc_strlen ( tlv69 ) + 1); }
    {int tlv4; tlv4 = (int)(cgc_strlen ( tlv69 ) + 1); }
    {int tlv5; tlv5 = (int)(cgc_strlen ( tlv69 ) + 1); }
    {int tlv6; tlv6 = (int)(cgc_strlen ( tlv69 ) + 1); }
    {int tlv7; tlv7 = (int)(cgc_strlen ( tlv69 ) + 1); }
    {int tlv8; tlv8 = (int)(cgc_strlen ( tlv69 ) + 1); }
    {int tlv9; tlv9 = (int)(cgc_strlen ( tlv69 ) + 1); }
    {int tlv10; tlv10 = (int)(cgc_strlen ( tlv69 ) + 1); }
    {char tlv17; tlv17 = (char)(cgc_strlen ( tlv69 ) + 1); }
    {int tlv19; tlv19 = (int)(cgc_strlen ( tlv69 ) + 1); }
    {int tlv23; tlv23 = (int)(cgc_strlen ( tlv69 ) + 1); }
    {int tlv22; tlv22 = (int)(cgc_strlen ( tlv69 ) + 1); }
    {void * tlv12; tlv12 = (void *)(cgc_strlen ( tlv69 ) + 1); }
    {cgc_size_t tlv11; tlv11 = (cgc_size_t)(cgc_strlen ( tlv69 ) + 1); }
    {char tlv27; tlv27 = (char)(cgc_strlen ( tlv69 ) + 1); }
    {int tlv29; tlv29 = (int)(cgc_strlen ( tlv69 ) + 1); }
    {char tlv32; tlv32 = (char)(cgc_strlen ( tlv69 ) + 1); }
    {int tlv34; tlv34 = (int)(cgc_strlen ( tlv69 ) + 1); }
    {char tlv36; tlv36 = (char)(cgc_strlen ( tlv69 ) + 1); }
    {int tlv38; tlv38 = (int)(cgc_strlen ( tlv69 ) + 1); }
    {int tlv42; tlv42 = (int)(cgc_strlen ( tlv69 ) + 1); }
    {int tlv41; tlv41 = (int)(cgc_strlen ( tlv69 ) + 1); }
    {void * tlv14; tlv14 = (void *)(cgc_strlen ( tlv69 ) + 1); }
    {cgc_size_t tlv13; tlv13 = (cgc_size_t)(cgc_strlen ( tlv69 ) + 1); }
    {char tlv46; tlv46 = (char)(cgc_strlen ( tlv69 ) + 1); }
    {int tlv15; tlv15 = (int)(cgc_strlen ( tlv69 ) + 1); }
    {int tlv49; tlv49 = (int)(cgc_strlen ( tlv69 ) + 1); }
    {int tlv48; tlv48 = (int)(cgc_strlen ( tlv69 ) + 1); }
    {char * tlv68; tlv68 = (char *)(cgc_strlen ( tlv69 ) + 1); }
    {void * tlv56; tlv56 = (void *)(cgc_strlen ( tlv69 ) + 1); }
    {cgc_size_t tlv55; tlv55 = (cgc_size_t)(cgc_strlen ( tlv69 ) + 1); }
    {void * tlv66; tlv66 = (void *)(cgc_strlen ( tlv69 ) + 1); }
    {cgc_size_t tlv65; tlv65 = (cgc_size_t)(cgc_strlen ( tlv69 ) + 1); }
    {char * tlv70; tlv70 = (char *)(cgc_strlen ( tlv69 ) + 1); }
    {char * tlv71; tlv71 = (char *)(cgc_strlen ( tlv69 ) + 1); }
}
void fix_ingred_genericParsers_2_50(){
fix_ingred_genericParsers_2_50_1();
}
void fix_ingred_genericParsers_2_55_1(){
int ns;
    bzero(&ns,sizeof(int));
    {char * temp; temp = (char *)(ns); }
    {char * name; name = (char *)(ns); }
    {int start; start = (int)(ns); }
    {int end; end = (int)(ns); }
    {int ne; ne = (int)(ns); }
    {int tlv1; tlv1 = (int)(ns); }
    {int tlv2; tlv2 = (int)(ns); }
    {int tlv3; tlv3 = (int)(ns); }
    {int tlv4; tlv4 = (int)(ns); }
    {int tlv5; tlv5 = (int)(ns); }
    {int tlv6; tlv6 = (int)(ns); }
    {int tlv7; tlv7 = (int)(ns); }
    {int tlv8; tlv8 = (int)(ns); }
    {int tlv9; tlv9 = (int)(ns); }
    {int tlv10; tlv10 = (int)(ns); }
    {char tlv17; tlv17 = (char)(ns); }
    {int tlv19; tlv19 = (int)(ns); }
    {int tlv23; tlv23 = (int)(ns); }
    {int tlv22; tlv22 = (int)(ns); }
    {void * tlv12; tlv12 = (void *)(ns); }
    {cgc_size_t tlv11; tlv11 = (cgc_size_t)(ns); }
    {char tlv27; tlv27 = (char)(ns); }
    {int tlv29; tlv29 = (int)(ns); }
    {char tlv32; tlv32 = (char)(ns); }
    {int tlv34; tlv34 = (int)(ns); }
    {char tlv36; tlv36 = (char)(ns); }
    {int tlv38; tlv38 = (int)(ns); }
    {int tlv42; tlv42 = (int)(ns); }
    {int tlv41; tlv41 = (int)(ns); }
    {void * tlv14; tlv14 = (void *)(ns); }
    {cgc_size_t tlv13; tlv13 = (cgc_size_t)(ns); }
    {char tlv46; tlv46 = (char)(ns); }
    {int tlv15; tlv15 = (int)(ns); }
    {int tlv49; tlv49 = (int)(ns); }
    {int tlv48; tlv48 = (int)(ns); }
    {char * tlv68; tlv68 = (char *)(ns); }
    {char * tlv69; tlv69 = (char *)(ns); }
    {void * tlv56; tlv56 = (void *)(ns); }
    {cgc_size_t tlv55; tlv55 = (cgc_size_t)(ns); }
    {void * tlv66; tlv66 = (void *)(ns); }
    {cgc_size_t tlv65; tlv65 = (cgc_size_t)(ns); }
    {char * tlv70; tlv70 = (char *)(ns); }
    {char * tlv71; tlv71 = (char *)(ns); }
}
void fix_ingred_genericParsers_2_55(){
fix_ingred_genericParsers_2_55_1();
}
void fix_ingred_genericParsers_2(){
fix_ingred_genericParsers_2_0();
fix_ingred_genericParsers_2_2();
fix_ingred_genericParsers_2_5();
fix_ingred_genericParsers_2_6();
fix_ingred_genericParsers_2_9();
fix_ingred_genericParsers_2_11();
fix_ingred_genericParsers_2_12();
fix_ingred_genericParsers_2_14();
fix_ingred_genericParsers_2_16();
fix_ingred_genericParsers_2_17();
fix_ingred_genericParsers_2_19();
fix_ingred_genericParsers_2_20();
fix_ingred_genericParsers_2_24();
fix_ingred_genericParsers_2_27();
fix_ingred_genericParsers_2_33();
fix_ingred_genericParsers_2_35();
fix_ingred_genericParsers_2_46();
fix_ingred_genericParsers_2_48();
fix_ingred_genericParsers_2_50();
fix_ingred_genericParsers_2_55();
}
