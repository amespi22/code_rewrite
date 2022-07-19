

#include "cgc_cityParsers.h"
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

void fix_ingred_cityParsers_0_0_0();
void fix_ingred_cityParsers_0_0();
void fix_ingred_cityParsers_0_11_0();
void fix_ingred_cityParsers_0_11_1();
void fix_ingred_cityParsers_0_11();
void fix_ingred_cityParsers_0_12_0();
void fix_ingred_cityParsers_0_12_1();
void fix_ingred_cityParsers_0_12_2();
void fix_ingred_cityParsers_0_12();
void fix_ingred_cityParsers_0_19_2();
void fix_ingred_cityParsers_0_19();
void fix_ingred_cityParsers_0_20_4();
void fix_ingred_cityParsers_0_20_5();
void fix_ingred_cityParsers_0_20();
void fix_ingred_cityParsers_0_25_7();
void fix_ingred_cityParsers_0_25_9();
void fix_ingred_cityParsers_0_25();
void fix_ingred_cityParsers_0_34_0();
void fix_ingred_cityParsers_0_34();
void fix_ingred_cityParsers_0_35_7();
void fix_ingred_cityParsers_0_35();
void fix_ingred_cityParsers_0_38_2();
void fix_ingred_cityParsers_0_38();
void fix_ingred_cityParsers_0();
int cgc_cityMenu(pCity ci)
{
if (fix_ingred_enable){ fix_ingred_cityParsers_0(); };
    int choice;
    choice = 0;
    char selection[30];
    pBorder pb;
    pb = NULL;

    if (ci == NULL) {
	return 0;
    }
    while (1) {
	cgc_printf("\nCity: @s\n", ci->name);
 {
     const char tlv2 [ ] = "1) Display City Info\n";
    	cgc_printf(tlv2);
 }
 {
     const char tlv3 [ ] = "2) Set Mayor\n";
    	cgc_printf(tlv3);
 }
 {
     const char tlv4 [ ] = "3) Set Url\n";
    	cgc_printf(tlv4);
 }
 {
     const char tlv5 [ ] = "4) Set Population\n";
    	cgc_printf(tlv5);
 }
 {
     const char tlv6 [ ] = "5) Add Border\n";
    	cgc_printf(tlv6);
 }
 {
     const char tlv7 [ ] = "6) Delete City and Exit Menu\n";
    	cgc_printf(tlv7);
 }
 {
     const char tlv8 [ ] = "7) Exit Menu\n";
    	cgc_printf(tlv8);
 }
 {
     const char tlv9 [ ] = "Selection: ";
    	cgc_printf(tlv9);
 }
 {
     void* tlv11;
     tlv11 = selection;
     cgc_size_t tlv10;
     tlv10 = 30;
    	cgc_bzero(tlv11,tlv10);
 }
 {
     char* tlv14;
      tlv14 = selection;
     char tlv13;
     tlv13 = '\n';
     cgc_size_t tlv12;
     tlv12 = 4;
    	cgc_receive_until(tlv14,tlv13,tlv12);
 }
 {
     const char* tlv15 = selection;
    	choice = cgc_atoi(tlv15);
 }
	switch (choice) {
	case 1:
	    {
		cgc_printCityInfo(ci);
	    }
	    break;
	case 2:
	    {
  {
      const char tlv63 [ ] = "\n-> ";
    		cgc_printf(tlv63);
  }
	    }
     {
         void* tlv17;
         tlv17 = selection;
         cgc_size_t tlv16;
         tlv16 = 30;
    	    cgc_bzero(tlv17,tlv16);
     }
     {
         char* tlv20;
          tlv20 = selection;
         char tlv19;
         tlv19 = '\n';
         cgc_size_t tlv18;
         tlv18 = 29;
    	    cgc_receive_until(tlv20,tlv19,tlv18);
     }
	    choice = 0;
	    while (cgc_isalnum(selection[choice]) || selection[choice] == ' ') {
		ci->mayor[choice] = selection[choice];
		choice++;
	    }
	    ci->mayor[choice] = '\x00';
	    break;
	case 3:
	    {
  {
      const char tlv64 [ ] = "\n-> ";
    		cgc_printf(tlv64);
  }
	    }
     {
         void* tlv22;
         tlv22 = selection;
         cgc_size_t tlv21;
         tlv21 = 30;
    	    cgc_bzero(tlv22,tlv21);
     }
     {
         char* tlv25;
          tlv25 = selection;
         char tlv24;
         tlv24 = '\n';
         cgc_size_t tlv23;
         tlv23 = 29;
    	    cgc_receive_until(tlv25,tlv24,tlv23);
     }
	    /// While it is valid url data copy loop and copy it
	    /// Since the buffer is zeroed and the max received is 29 this loop
	    ///     should be safe
	    choice = 0;
	    while (cgc_isalnum(selection[choice]) || selection[choice] == ':' || selection[choice] == '.' || selection[choice] == '/') {
		ci->url[choice] = selection[choice];
		choice++;
	    }
	    ci->url[choice] = '\x00';
	    break;
	case 4:
	    {
  {
      const char tlv65 [ ] = "\n-> ";
    		cgc_printf(tlv65);
  }
	    }
     {
         void* tlv27;
         tlv27 = selection;
         cgc_size_t tlv26;
         tlv26 = 30;
    	    cgc_bzero(tlv27,tlv26);
     }
     {
         char* tlv30;
          tlv30 = selection;
         char tlv29;
         tlv29 = '\n';
         cgc_size_t tlv28;
         tlv28 = 29;
    	    cgc_receive_until(tlv30,tlv29,tlv28);
     }
     {
         const char* tlv55 = selection;
    	    ci->population = cgc_atoi(tlv55);
     }
	    break;
	case 5:
	    {
		if (ci->border_count > CITYBORDERMAX) {
      {
          const char tlv67 [ ] = "Max Borders\n";
    		    cgc_printf(tlv67);
      }
		    break;
		}
	    }
     int tlv1;
     {
         cgc_size_t tlv58;
         tlv58 = sizeof ( Border );
         int tlv57;
         tlv57 = 0;
         void** tlv56;
         tlv56 = ( void * * ) & pb;
         tlv1 = cgc_allocate(tlv58,tlv57,tlv56);
     }
	    if (tlv1 != 0) {
		pb = NULL;
		continue;
	    }
     {
         const char tlv31 [ ] = "Lat Start: ";
    	    cgc_printf(tlv31);
     }
     {
         void* tlv33;
         tlv33 = selection;
         cgc_size_t tlv32;
         tlv32 = 30;
    	    cgc_bzero(tlv33,tlv32);
     }
     {
         char* tlv36;
          tlv36 = selection;
         char tlv35;
         tlv35 = '\n';
         cgc_size_t tlv34;
         tlv34 = 19;
    	    cgc_receive_until(tlv36,tlv35,tlv34);
     }
     {
         const char* tlv59 = selection;
    	    pb->latStart = cgc_atof(tlv59);
     }
     {
         const char tlv37 [ ] = "Long Start: ";
    	    cgc_printf(tlv37);
     }
     {
         void* tlv39;
         tlv39 = selection;
         cgc_size_t tlv38;
         tlv38 = 30;
    	    cgc_bzero(tlv39,tlv38);
     }
     {
         char* tlv42;
          tlv42 = selection;
         char tlv41;
         tlv41 = '\n';
         cgc_size_t tlv40;
         tlv40 = 19;
    	    cgc_receive_until(tlv42,tlv41,tlv40);
     }
     {
         const char* tlv60 = selection;
    	    pb->lngStart = cgc_atof(tlv60);
     }
     {
         const char tlv43 [ ] = "Lat End: ";
    	    cgc_printf(tlv43);
     }
     {
         void* tlv45;
         tlv45 = selection;
         cgc_size_t tlv44;
         tlv44 = 30;
    	    cgc_bzero(tlv45,tlv44);
     }
     {
         char* tlv48;
          tlv48 = selection;
         char tlv47;
         tlv47 = '\n';
         cgc_size_t tlv46;
         tlv46 = 19;
    	    cgc_receive_until(tlv48,tlv47,tlv46);
     }
     {
         const char* tlv61 = selection;
    	    pb->latEnd = cgc_atof(tlv61);
     }
     {
         const char tlv49 [ ] = "Long End: ";
    	    cgc_printf(tlv49);
     }
     {
         void* tlv51;
         tlv51 = selection;
         cgc_size_t tlv50;
         tlv50 = 30;
    	    cgc_bzero(tlv51,tlv50);
     }
     {
         char* tlv54;
          tlv54 = selection;
         char tlv53;
         tlv53 = '\n';
         cgc_size_t tlv52;
         tlv52 = 19;
    	    cgc_receive_until(tlv54,tlv53,tlv52);
     }
     {
         const char* tlv62 = selection;
    	    pb->lngEnd = cgc_atof(tlv62);
     }
	    ci->borders[ci->border_count] = pb;
	    ci->border_count++;
	    break;
	case 6:
	    {
		cgc_freeCity(ci);
	    }
	    return 0;
	    break;
	case 7:
	    {
		return 1;
	    }
	    break;
	default:
	    {
  {
      const char tlv66 [ ] = "Invalid\n";
    		cgc_printf(tlv66);
  }
	    }
	    break;
	};
    }
    return 1;
}

void fix_ingred_cityParsers_1_2_0();
void fix_ingred_cityParsers_1_2_1();
void fix_ingred_cityParsers_1_2();
void fix_ingred_cityParsers_1_3_0();
void fix_ingred_cityParsers_1_3();
void fix_ingred_cityParsers_1_4_1();
void fix_ingred_cityParsers_1_4();
void fix_ingred_cityParsers_1();
void cgc_freeCharPtr(char **buffer)
{
if (fix_ingred_enable){ fix_ingred_cityParsers_1(); };
    if (buffer == NULL) {
	return;
    }
    if (*buffer == NULL) {
	return;
    }
    {
        void* tlv2;
        tlv2 = * buffer;
        cgc_size_t tlv1;
        {
            char* tlv3;
             tlv3 = * buffer;
            tlv1 = cgc_strlen(tlv3) + 1;
        }
        cgc_deallocate(tlv2,tlv1);
    }
    *buffer = NULL;
    return;
}

void fix_ingred_cityParsers_2_0_0();
void fix_ingred_cityParsers_2_0();
void fix_ingred_cityParsers_2_2_2();
void fix_ingred_cityParsers_2_2_3();
void fix_ingred_cityParsers_2_2();
void fix_ingred_cityParsers_2_3_0();
void fix_ingred_cityParsers_2_3_1();
void fix_ingred_cityParsers_2_3();
void fix_ingred_cityParsers_2_4_0();
void fix_ingred_cityParsers_2_4_1();
void fix_ingred_cityParsers_2_4();
void fix_ingred_cityParsers_2();
void cgc_freeCity(pCity ci)
{
if (fix_ingred_enable){ fix_ingred_cityParsers_2(); };
    int index;
    index = 0;
    if (ci == NULL) {
	return;
    }
    for (index = 0; index < ci->border_count; index++) {
 {
     void* tlv4;
     tlv4 = ci -> borders;
     cgc_size_t tlv3;
     tlv3 = sizeof ( Border );
    	cgc_deallocate(tlv4,tlv3);
 }
    }
    {
        void* tlv2;
        tlv2 = ci;
        cgc_size_t tlv1;
        tlv1 = sizeof ( City );
        cgc_deallocate(tlv2,tlv1);
    }
    return;
}

void fix_ingred_cityParsers_3_2_5();
void fix_ingred_cityParsers_3_2();
void fix_ingred_cityParsers_3_3_5();
void fix_ingred_cityParsers_3_3();
void fix_ingred_cityParsers_3();
void cgc_initCity(pCity ci)
{
if (fix_ingred_enable){ fix_ingred_cityParsers_3(); };
    int index;
    index = 0;
    if (ci == NULL) {
	return;
    }
    for (index = 0; index < CITYBORDERMAX; index++) {
	ci->name[index] = 0x00;
	ci->borders[index] = NULL;
    }
    for (index = 0; index < 30; index++) {
	ci->mayor[index] = 0;
	ci->url[index] = 0;
    }
    ci->population = -1;
    ci->border_count = 0;
    return;
}

void fix_ingred_cityParsers_4();
void cgc_printCityInfo(pCity ci)
{
if (fix_ingred_enable){ fix_ingred_cityParsers_4(); };
    int index;
    index = 0;
    pBorder b;
    b = NULL;
    if (ci == NULL) {
	return;
    }
    {
        const char tlv1 [ ] = "\t\t\t\tCity: ";
        cgc_printf(tlv1);
    }
    if (ci->name[0] != '\x00') {
	cgc_printf("@s\n", ci->name);
    } else {
 {
     const char tlv2 [ ] = "Unknown\n";
    	cgc_printf(tlv2);
 }
    }
    if (ci->population >= 0) {
	cgc_printf("\t\t\t\t\tPopulation: @d\n", ci->population);
    }
    if (ci->mayor[0] != '\x00') {
	cgc_printf("\t\t\t\t\tMayor: @s\n", ci->mayor);
    }
    if (ci->url[0] != '\x00') {
	cgc_printf("\t\t\t\t\tUrl: @s\n", ci->url);
    }
    for (index = 0; index < ci->border_count; index++) {
	b = ci->borders[index];
	if (b != NULL) {
	    cgc_printf("\t\t\t\t\tBorder: @f @f @f @f\n", b->latStart, b->lngStart, b->latEnd, b->lngEnd);
	}
    }
    return;
}

void fix_ingred_cityParsers_5_2_1();
void fix_ingred_cityParsers_5_2();
void fix_ingred_cityParsers_5_5_0();
void fix_ingred_cityParsers_5_5_1();
void fix_ingred_cityParsers_5_5();
void fix_ingred_cityParsers_5_7_1();
void fix_ingred_cityParsers_5_7();
void fix_ingred_cityParsers_5_10_0();
void fix_ingred_cityParsers_5_10();
void fix_ingred_cityParsers_5();
int cgc_skipOpen(pstring str, int ending)
{
if (fix_ingred_enable){ fix_ingred_cityParsers_5(); };
    if (str == NULL) {
	return 0;
    }
    cgc_skipWhiteSpace(str);
    int tlv1;
    {
        pstring tlv6;
        tlv6 = str;
        char tlv5;
        tlv5 = '{';
        tlv1 = cgc_atChar(tlv6,tlv5);
    }
    if (!tlv1) {
	return 0;
    }
    /// Skip the opening brace
    int tlv2;
    {
        pstring tlv7;
        tlv7 = str;
        tlv2 = cgc_incChar(tlv7);
    }
    if (tlv2 == -1) {
	return 0;
    }
    /// Skip to the element id value or '#' if it is an end
    cgc_skipWhiteSpace(str);
    if (ending) {
 int tlv3;
 {
     pstring tlv9;
     tlv9 = str;
     char tlv8;
     tlv8 = '#';
     tlv3 = cgc_atChar(tlv9,tlv8);
 }
	if (!tlv3) {
	    return 0;
	}
 int tlv4;
 {
     pstring tlv10;
     tlv10 = str;
     tlv4 = cgc_incChar(tlv10);
 }
	if (tlv4 == -1) {
	    return 0;
	}
    }
    return 1;
}

void fix_ingred_cityParsers_6_0_0();
void fix_ingred_cityParsers_6_0_4();
void fix_ingred_cityParsers_6_0_6();
void fix_ingred_cityParsers_6_0();
void fix_ingred_cityParsers_6_3_6();
void fix_ingred_cityParsers_6_3();
void fix_ingred_cityParsers_6_4_1();
void fix_ingred_cityParsers_6_4();
void fix_ingred_cityParsers_6_6_6();
void fix_ingred_cityParsers_6_6_7();
void fix_ingred_cityParsers_6_6();
void fix_ingred_cityParsers_6_7_6();
void fix_ingred_cityParsers_6_7();
void fix_ingred_cityParsers_6_9_6();
void fix_ingred_cityParsers_6_9();
void fix_ingred_cityParsers_6_11_6();
void fix_ingred_cityParsers_6_11();
void fix_ingred_cityParsers_6_12_0();
void fix_ingred_cityParsers_6_12();
void fix_ingred_cityParsers_6_13_1();
void fix_ingred_cityParsers_6_13();
void fix_ingred_cityParsers_6_15_1();
void fix_ingred_cityParsers_6_15();
void fix_ingred_cityParsers_6_16_1();
void fix_ingred_cityParsers_6_16();
void fix_ingred_cityParsers_6_18_0();
void fix_ingred_cityParsers_6_18();
void fix_ingred_cityParsers_6_19_8();
void fix_ingred_cityParsers_6_19();
void fix_ingred_cityParsers_6_24_1();
void fix_ingred_cityParsers_6_24();
void fix_ingred_cityParsers_6_25_1();
void fix_ingred_cityParsers_6_25();
void fix_ingred_cityParsers_6_29_0();
void fix_ingred_cityParsers_6_29_1();
void fix_ingred_cityParsers_6_29();
void fix_ingred_cityParsers_6_30_0();
void fix_ingred_cityParsers_6_30_2();
void fix_ingred_cityParsers_6_30();
void fix_ingred_cityParsers_6_32_1();
void fix_ingred_cityParsers_6_32();
void fix_ingred_cityParsers_6_36_0();
void fix_ingred_cityParsers_6_36_1();
void fix_ingred_cityParsers_6_36();
void fix_ingred_cityParsers_6_37_0();
void fix_ingred_cityParsers_6_37();
void fix_ingred_cityParsers_6_42_0();
void fix_ingred_cityParsers_6_42();
void fix_ingred_cityParsers_6_43_0();
void fix_ingred_cityParsers_6_43_2();
void fix_ingred_cityParsers_6_43();
void fix_ingred_cityParsers_6_55_1();
void fix_ingred_cityParsers_6_55();
void fix_ingred_cityParsers_6_56_7();
void fix_ingred_cityParsers_6_56();
void fix_ingred_cityParsers_6_65_7();
void fix_ingred_cityParsers_6_65();
void fix_ingred_cityParsers_6_67_1();
void fix_ingred_cityParsers_6_67();
void fix_ingred_cityParsers_6_69_1();
void fix_ingred_cityParsers_6_69();
void fix_ingred_cityParsers_6();
pCity cgc_cityTopLevel(pstring str)
{
if (fix_ingred_enable){ fix_ingred_cityParsers_6(); };
    int lastGood;
    lastGood = 0;
    pCity newCity;
    newCity = NULL;
    int startIndex;
    startIndex = 0;
    int endIndex;
    endIndex = 0;
    char* temp;
     temp = NULL;
    int tempInt;
    tempInt = 0;
    element el;
    if (str == NULL) {
	goto end;
    }
    /// Skip the opening "{"
    int tlv1;
    {
        pstring tlv17;
        tlv17 = str;
        int tlv16;
        tlv16 = 0;
        tlv1 = cgc_skipOpen(tlv17,tlv16);
    }
    if (tlv1 == 0) {
	goto end;
    }
    /// Get the start and end index of the element id
    {
        pstring tlv9;
        tlv9 = str;
        int* tlv8;
        tlv8 = & startIndex;
        cgc_getIndex(tlv9,tlv8);
    }
    {
        pstring tlv18;
        tlv18 = str;
        endIndex = cgc_skipAlpha(tlv18);
    }
    if (endIndex == -1) {
	goto end;
    }
    if (startIndex == endIndex) {
	goto end;
    }
    {
        pstring tlv21;
        tlv21 = str;
        int tlv20;
        tlv20 = startIndex;
        int tlv19;
        tlv19 = endIndex;
        temp = cgc_copyData(tlv21,tlv20,tlv19);
    }
    if (temp == NULL) {
	goto end;
    }
    int tlv2;
    {
        const char* tlv23 = temp;
        const char tlv22 [ ] = "City";
        tlv2 = cgc_strcmp(tlv23,tlv22);
    }
    if (tlv2 != 0) {
 {
     void* tlv41;
     tlv41 = temp;
     cgc_size_t tlv40;
     {
         char* tlv74;
          tlv74 = temp;
         tlv40 = cgc_strlen(tlv74) + 1;
     }
    	cgc_deallocate(tlv41,tlv40);
 }
	goto end;
    }
    {
        void* tlv11;
        tlv11 = temp;
        cgc_size_t tlv10;
        {
            char* tlv72;
             tlv72 = temp;
            tlv10 = cgc_strlen(tlv72) + 1;
        }
        cgc_deallocate(tlv11,tlv10);
    }
    cgc_skipWhiteSpace(str);
    int tlv3;
    {
        pstring tlv25;
        tlv25 = str;
        char tlv24;
        tlv24 = '}';
        tlv3 = cgc_atChar(tlv25,tlv24);
    }
    if (!tlv3) {
	goto end;
    }
    cgc_incChar(str);
    cgc_skipWhiteSpace(str);
    lastGood = str->index;
    int tlv4;
    {
        cgc_size_t tlv28;
        tlv28 = sizeof ( City );
        int tlv27;
        tlv27 = 0;
        void** tlv26;
        tlv26 = ( void * * ) & newCity;
        tlv4 = cgc_allocate(tlv28,tlv27,tlv26);
    }
    if (tlv4 != 0) {
	newCity = NULL;
	goto error;
    }
    cgc_initCity(newCity);
    {
        pstring tlv29;
        tlv29 = str;
        temp = cgc_pullNextElementName(tlv29);
    }
    while (temp != NULL) {
 {
     char* tlv46;
      tlv46 = temp;
    	el = cgc_elementNameToEnum(tlv46);
 }
 {
     void* tlv43;
     tlv43 = temp;
     cgc_size_t tlv42;
     {
         char* tlv75;
          tlv75 = temp;
         tlv42 = cgc_strlen(tlv75) + 1;
     }
    	cgc_deallocate(tlv43,tlv42);
 }
	switch (el) {
	case name:
	    {
  {
      pstring tlv68;
      tlv68 = str;
    		temp = cgc_extractName(tlv68);
  }
	    }
	    if (temp == NULL) {
		goto error;
	    }
	    /// Clear it out
     {
         void* tlv49;
         tlv49 = newCity -> name;
         cgc_size_t tlv48;
         tlv48 = 20;
    	    cgc_bzero(tlv49,tlv48);
     }
	    /// Copy the name data. It has already been filtered 
	    ///     for invalid characters.
     {
         char* tlv52;
          tlv52 = newCity -> name;
         char* tlv51;
          tlv51 = temp;
         cgc_size_t tlv50;
         tlv50 = 19;
    	    cgc_strncpy(tlv52,tlv51,tlv50);
     }
	    /// Free the buffer
     {
         void* tlv54;
         tlv54 = temp;
         cgc_size_t tlv53;
         {
             char* tlv77;
              tlv77 = temp;
             tlv53 = cgc_strlen(tlv77) + 1;
         }
    	    cgc_deallocate(tlv54,tlv53);
     }
	    temp = NULL;
	    break;
	case mayor:
	    {
  {
      pstring tlv69;
      tlv69 = str;
    		temp = cgc_extractMayor(tlv69);
  }
	    }
	    if (temp == NULL) {
		goto error;
	    }

     {
         void* tlv56;
         tlv56 = newCity -> mayor;
         cgc_size_t tlv55;
         tlv55 = 30;
    	    cgc_bzero(tlv56,tlv55);
     }
     {
         char* tlv58;
          tlv58 = newCity -> mayor;
         char* tlv57;
          tlv57 = temp;
    	    cgc_strcpy(tlv58,tlv57);
     }
     {
         char** tlv59;
          tlv59 = & temp;
    	    cgc_freeCharPtr(tlv59);
     }
	    break;
	case url:
	    {
  {
      pstring tlv70;
      tlv70 = str;
    		temp = cgc_extractUrl(tlv70);
  }
	    }
	    if (temp == NULL) {
		goto error;
	    }
     {
         void* tlv61;
         tlv61 = newCity -> url;
         cgc_size_t tlv60;
         tlv60 = 30;
    	    cgc_bzero(tlv61,tlv60);
     }
     {
         char* tlv64;
          tlv64 = newCity -> url;
         char* tlv63;
          tlv63 = temp;
         cgc_size_t tlv62;
         tlv62 = 29;
    	    cgc_strncpy(tlv64,tlv63,tlv62);
     }
     {
         char** tlv65;
          tlv65 = & temp;
    	    cgc_freeCharPtr(tlv65);
     }
	    break;
	case border:
	    {
		if (newCity->border_count >= CITYBORDERMAX) {
		    goto error;
		}
	    }
	    tempInt = newCity->border_count;
     {
         pstring tlv66;
         tlv66 = str;
    	    newCity->borders[tempInt] = cgc_extractBorder(tlv66);
     }
	    if (newCity->borders[tempInt] == NULL) {
		goto error;
	    }
	    newCity->border_count++;
	    break;
	case population:
	    {
  {
      pstring tlv71;
      tlv71 = str;
    		newCity->population = cgc_extractPopulation(tlv71);
  }
	    }
	    if (newCity->population < 0) {
		goto error;
	    }
	    break;
	default:
	    {
  {
      const char tlv67 [ ] = "!!Invalid element ID for City\n";
    		cgc_printf(tlv67);
  }
	    }
	    goto error;
	    break;
	};
	lastGood = str->index;
 {
     pstring tlv47;
     tlv47 = str;
    	temp = cgc_pullNextElementName(tlv47);
 }
    }
    int tlv5;
    {
        pstring tlv31;
        tlv31 = str;
        int tlv30;
        tlv30 = 1;
        tlv5 = cgc_skipOpen(tlv31,tlv30);
    }
    if (tlv5 == 0) {
	goto error;
    }
    {
        pstring tlv13;
        tlv13 = str;
        int* tlv12;
        tlv12 = & startIndex;
        cgc_getIndex(tlv13,tlv12);
    }
    {
        pstring tlv32;
        tlv32 = str;
        endIndex = cgc_skipAlpha(tlv32);
    }
    if (endIndex == -1) {
	goto error;
    } else {
	if (startIndex == endIndex) {
	    goto error;
	}
    }
    {
        pstring tlv35;
        tlv35 = str;
        int tlv34;
        tlv34 = startIndex;
        int tlv33;
        tlv33 = endIndex;
        temp = cgc_copyData(tlv35,tlv34,tlv33);
    }
    if (temp == NULL) {
	goto error;
    }
    int tlv6;
    {
        const char* tlv37 = temp;
        const char tlv36 [ ] = "City";
        tlv6 = cgc_strcmp(tlv37,tlv36);
    }
    if (tlv6 != 0) {
 {
     void* tlv45;
     tlv45 = temp;
     cgc_size_t tlv44;
     {
         char* tlv76;
          tlv76 = temp;
         tlv44 = cgc_strlen(tlv76) + 1;
     }
    	cgc_deallocate(tlv45,tlv44);
 }
	goto error;
    }
    {
        void* tlv15;
        tlv15 = temp;
        cgc_size_t tlv14;
        {
            char* tlv73;
             tlv73 = temp;
            tlv14 = cgc_strlen(tlv73) + 1;
        }
        cgc_deallocate(tlv15,tlv14);
    }
    cgc_skipWhiteSpace(str);
    int tlv7;
    {
        pstring tlv39;
        tlv39 = str;
        char tlv38;
        tlv38 = '}';
        tlv7 = cgc_atChar(tlv39,tlv38);
    }
    if (!tlv7) {
	goto error;
    }
    cgc_incChar(str);
    goto end;
  error:
    if (newCity) {
	cgc_freeCity(newCity);
	newCity = NULL;
    }
    cgc_printf("!!Error at: @s\n", str->buffer + lastGood);
    str->index = lastGood;
  end:
    return newCity;
}

void fix_ingred_cityParsers_7_0_0();
void fix_ingred_cityParsers_7_0();
void fix_ingred_cityParsers_7_2_1();
void fix_ingred_cityParsers_7_2();
void fix_ingred_cityParsers_7_3_4();
void fix_ingred_cityParsers_7_3();
void fix_ingred_cityParsers_7_6_1();
void fix_ingred_cityParsers_7_6_2();
void fix_ingred_cityParsers_7_6();
void fix_ingred_cityParsers_7_7_5();
void fix_ingred_cityParsers_7_7();
void fix_ingred_cityParsers_7_9_5();
void fix_ingred_cityParsers_7_9();
void fix_ingred_cityParsers_7_12_1();
void fix_ingred_cityParsers_7_12();
void fix_ingred_cityParsers_7_20_1();
void fix_ingred_cityParsers_7_20();
void fix_ingred_cityParsers_7_21_5();
void fix_ingred_cityParsers_7_21();
void fix_ingred_cityParsers_7_25_6();
void fix_ingred_cityParsers_7_25();
void fix_ingred_cityParsers_7_27_6();
void fix_ingred_cityParsers_7_27();
void fix_ingred_cityParsers_7();
char *cgc_extractMayor(pstring str)
{
if (fix_ingred_enable){ fix_ingred_cityParsers_7(); };
    char* mayor;
     mayor = NULL;
    register int startIndex;
    startIndex = 0;
    register int endIndex;
    endIndex = 0;
    char* temp;
     temp = NULL;
    if (!str) {
	return NULL;
    }
    /// This skips any whitespace and opening '{ '
    int tlv1;
    {
        pstring tlv9;
        tlv9 = str;
        int tlv8;
        tlv8 = 0;
        tlv1 = cgc_skipOpen(tlv9,tlv8);
    }
    if (tlv1 == 0) {
	return NULL;
    }
    startIndex = str->index;
    {
        pstring tlv10;
        tlv10 = str;
        endIndex = cgc_skipAlpha(tlv10);
    }
    if (endIndex == -1 || startIndex == endIndex) {
	return NULL;
    }
    {
        pstring tlv13;
        tlv13 = str;
        int tlv12;
        tlv12 = startIndex;
        int tlv11;
        tlv11 = endIndex;
        mayor = cgc_copyData(tlv13,tlv12,tlv11);
    }
    if (mayor == NULL) {
	return NULL;
    }
    int tlv2;
    {
        const char* tlv15 = mayor;
        const char tlv14 [ ] = "Mayor";
        tlv2 = cgc_strcmp(tlv15,tlv14);
    }
    if (tlv2 != 0) {
 {
     char** tlv34;
      tlv34 = & mayor;
    	cgc_freeCharPtr(tlv34);
 }
	return NULL;
    }
    {
        char** tlv7;
         tlv7 = & mayor;
        cgc_freeCharPtr(tlv7);
    }
    cgc_skipWhiteSpace(str);
    int tlv3;
    {
        pstring tlv17;
        tlv17 = str;
        char tlv16;
        tlv16 = '}';
        tlv3 = cgc_atChar(tlv17,tlv16);
    }
    if (!tlv3) {
	return NULL;
    }
    /// Skip the Closing brace
    cgc_incChar(str);
    {
        pstring tlv18;
        tlv18 = str;
        startIndex = cgc_skipWhiteSpace(tlv18);
    }
    /// Using this function allows things like Sir Winston Churchill 3rd
    {
        pstring tlv19;
        tlv19 = str;
        endIndex = cgc_skipToNonAlphaNumSpace(tlv19);
    }
    if (endIndex < 0 || startIndex == endIndex) {
	return NULL;
    }
    while (cgc_isspace(str->buffer[endIndex - 1])) {
	endIndex--;
    }
    {
        pstring tlv22;
        tlv22 = str;
        int tlv21;
        tlv21 = startIndex;
        int tlv20;
        tlv20 = endIndex;
        mayor = cgc_copyData(tlv22,tlv21,tlv20);
    }
    if (mayor == NULL) {
	return NULL;
    }
    cgc_skipWhiteSpace(str);
    /// Skip the opening brace and '#'
    int tlv4;
    {
        pstring tlv24;
        tlv24 = str;
        int tlv23;
        tlv23 = 1;
        tlv4 = cgc_skipOpen(tlv24,tlv23);
    }
    if (tlv4 == 0) {
	goto error;
    }
    startIndex = str->index;
    {
        pstring tlv25;
        tlv25 = str;
        endIndex = cgc_skipAlpha(tlv25);
    }
    if (endIndex == -1 || startIndex == endIndex) {
	goto error;
    }
    {
        pstring tlv28;
        tlv28 = str;
        int tlv27;
        tlv27 = startIndex;
        int tlv26;
        tlv26 = endIndex;
        temp = cgc_copyData(tlv28,tlv27,tlv26);
    }
    if (temp == NULL) {
	goto error;
    }
    int tlv5;
    {
        const char* tlv30 = temp;
        const char tlv29 [ ] = "Mayor";
        tlv5 = cgc_strcmp(tlv30,tlv29);
    }
    if (tlv5 != 0) {
 {
     char** tlv35;
      tlv35 = & temp;
    	cgc_freeCharPtr(tlv35);
 }
	goto error;
    }
    cgc_skipWhiteSpace(str);
    int tlv6;
    {
        pstring tlv32;
        tlv32 = str;
        char tlv31;
        tlv31 = '}';
        tlv6 = cgc_atChar(tlv32,tlv31);
    }
    if (!tlv6) {
	goto error;
    }
    cgc_incChar(str);

    goto end;
  error:
    {
        char** tlv33;
         tlv33 = & mayor;
        cgc_freeCharPtr(tlv33);
    }
  end:
    return mayor;
}

void fix_ingred_cityParsers_8_0_0();
void fix_ingred_cityParsers_8_0_1();
void fix_ingred_cityParsers_8_0();
void fix_ingred_cityParsers_8_3_3();
void fix_ingred_cityParsers_8_3();
void fix_ingred_cityParsers_8_4_1();
void fix_ingred_cityParsers_8_4();
void fix_ingred_cityParsers_8_5_1();
void fix_ingred_cityParsers_8_5_2();
void fix_ingred_cityParsers_8_5();
void fix_ingred_cityParsers_8_6_3();
void fix_ingred_cityParsers_8_6();
void fix_ingred_cityParsers_8_10_1();
void fix_ingred_cityParsers_8_10();
void fix_ingred_cityParsers_8_15_1();
void fix_ingred_cityParsers_8_15();
void fix_ingred_cityParsers_8_16_3();
void fix_ingred_cityParsers_8_16();
void fix_ingred_cityParsers_8_19_3();
void fix_ingred_cityParsers_8_19();
void fix_ingred_cityParsers_8_21_3();
void fix_ingred_cityParsers_8_21();
void fix_ingred_cityParsers_8();
char *cgc_extractUrl(pstring str)
{
if (fix_ingred_enable){ fix_ingred_cityParsers_8(); };
    char* url;
     url = NULL;
    int startIndex;
    startIndex = 0;
    char* temp;
     temp = NULL;
    if (str == NULL) {
	goto end;
    }
    int tlv1;
    {
        pstring tlv15;
        tlv15 = str;
        int tlv14;
        tlv14 = 0;
        tlv1 = cgc_skipOpen(tlv15,tlv14);
    }
    if (tlv1 == 0) {
	goto end;
    }
    {
        pstring tlv8;
        tlv8 = str;
        int* tlv7;
        tlv7 = & startIndex;
        cgc_getIndex(tlv8,tlv7);
    }
    cgc_skipAlpha(str);
    {
        pstring tlv18;
        tlv18 = str;
        int tlv17;
        tlv17 = startIndex;
        int tlv16;
        tlv16 = str -> index;
        url = cgc_copyData(tlv18,tlv17,tlv16);
    }
    if (url == NULL) {
	goto end;
    }
    int tlv2;
    {
        const char* tlv20 = url;
        const char tlv19 [ ] = "Url";
        tlv2 = cgc_strcmp(tlv20,tlv19);
    }
    if (tlv2) {
 {
     char** tlv35;
      tlv35 = & url;
    	cgc_freeCharPtr(tlv35);
 }
	goto end;
    }
    cgc_skipWhiteSpace(str);
    int tlv3;
    {
        pstring tlv22;
        tlv22 = str;
        char tlv21;
        tlv21 = '}';
        tlv3 = cgc_atChar(tlv22,tlv21);
    }
    if (!tlv3) {
	goto end;
    }
    cgc_incChar(str);
    cgc_skipWhiteSpace(str);
    {
        pstring tlv10;
        tlv10 = str;
        int* tlv9;
        tlv9 = & startIndex;
        cgc_getIndex(tlv10,tlv9);
    }
    cgc_skipUrl(str);
    {
        pstring tlv25;
        tlv25 = str;
        int tlv24;
        tlv24 = startIndex;
        int tlv23;
        tlv23 = str -> index;
        url = cgc_copyData(tlv25,tlv24,tlv23);
    }
    if (url == NULL) {
	goto end;
    }
    cgc_skipWhiteSpace(str);
    int tlv4;
    {
        pstring tlv27;
        tlv27 = str;
        int tlv26;
        tlv26 = 1;
        tlv4 = cgc_skipOpen(tlv27,tlv26);
    }
    if (tlv4 == 0) {
	goto error;
    }
    {
        pstring tlv12;
        tlv12 = str;
        int* tlv11;
        tlv11 = & startIndex;
        cgc_getIndex(tlv12,tlv11);
    }
    cgc_skipAlpha(str);
    {
        pstring tlv30;
        tlv30 = str;
        int tlv29;
        tlv29 = startIndex;
        int tlv28;
        tlv28 = str -> index;
        temp = cgc_copyData(tlv30,tlv29,tlv28);
    }
    if (temp == NULL) {
	goto error;
    }
    int tlv5;
    {
        const char* tlv32 = temp;
        const char tlv31 [ ] = "Url";
        tlv5 = cgc_strcmp(tlv32,tlv31);
    }
    if (tlv5 != 0) {
 {
     char** tlv36;
      tlv36 = & temp;
    	cgc_freeCharPtr(tlv36);
 }
	goto error;
    }
    {
        char** tlv13;
         tlv13 = & temp;
        cgc_freeCharPtr(tlv13);
    }
    cgc_skipWhiteSpace(str);
    int tlv6;
    {
        pstring tlv34;
        tlv34 = str;
        char tlv33;
        tlv33 = '}';
        tlv6 = cgc_atChar(tlv34,tlv33);
    }
    if (!tlv6) {
	goto error;
    }
    cgc_incChar(str);
    goto end;
  error:
    if (url) {
 {
     char** tlv37;
      tlv37 = & url;
    	cgc_freeCharPtr(tlv37);
 }
    }
  end:
    return url;
}

void fix_ingred_cityParsers_0_0_0(){
    {int choice; choice = (int)(0); }
    {char selection [ 30 ]; selection [ ( 30 )-1 ] = (char)(0); }
    {void * tlv11; tlv11 = (void *)(0); }
    {cgc_size_t tlv10; tlv10 = (cgc_size_t)(0); }
    {char * tlv14; tlv14 = (char *)(0); }
    {char tlv13; tlv13 = (char)(0); }
    {cgc_size_t tlv12; tlv12 = (cgc_size_t)(0); }
    {int tlv1; tlv1 = (int)(0); }
    {void * tlv17; tlv17 = (void *)(0); }
    {cgc_size_t tlv16; tlv16 = (cgc_size_t)(0); }
    {char * tlv20; tlv20 = (char *)(0); }
    {char tlv19; tlv19 = (char)(0); }
    {cgc_size_t tlv18; tlv18 = (cgc_size_t)(0); }
    {void * tlv22; tlv22 = (void *)(0); }
    {cgc_size_t tlv21; tlv21 = (cgc_size_t)(0); }
    {char * tlv25; tlv25 = (char *)(0); }
    {char tlv24; tlv24 = (char)(0); }
    {cgc_size_t tlv23; tlv23 = (cgc_size_t)(0); }
    {void * tlv27; tlv27 = (void *)(0); }
    {cgc_size_t tlv26; tlv26 = (cgc_size_t)(0); }
    {char * tlv30; tlv30 = (char *)(0); }
    {char tlv29; tlv29 = (char)(0); }
    {cgc_size_t tlv28; tlv28 = (cgc_size_t)(0); }
    {cgc_size_t tlv58; tlv58 = (cgc_size_t)(0); }
    {int tlv57; tlv57 = (int)(0); }
    {void * tlv33; tlv33 = (void *)(0); }
    {cgc_size_t tlv32; tlv32 = (cgc_size_t)(0); }
    {char * tlv36; tlv36 = (char *)(0); }
    {char tlv35; tlv35 = (char)(0); }
    {cgc_size_t tlv34; tlv34 = (cgc_size_t)(0); }
    {void * tlv39; tlv39 = (void *)(0); }
    {cgc_size_t tlv38; tlv38 = (cgc_size_t)(0); }
    {char * tlv42; tlv42 = (char *)(0); }
    {char tlv41; tlv41 = (char)(0); }
    {cgc_size_t tlv40; tlv40 = (cgc_size_t)(0); }
    {void * tlv45; tlv45 = (void *)(0); }
    {cgc_size_t tlv44; tlv44 = (cgc_size_t)(0); }
    {char * tlv48; tlv48 = (char *)(0); }
    {char tlv47; tlv47 = (char)(0); }
    {cgc_size_t tlv46; tlv46 = (cgc_size_t)(0); }
    {void * tlv51; tlv51 = (void *)(0); }
    {cgc_size_t tlv50; tlv50 = (cgc_size_t)(0); }
    {char * tlv54; tlv54 = (char *)(0); }
    {char tlv53; tlv53 = (char)(0); }
    {cgc_size_t tlv52; tlv52 = (cgc_size_t)(0); }
}
void fix_ingred_cityParsers_0_0(){
fix_ingred_cityParsers_0_0_0();
}
void fix_ingred_cityParsers_0_11_0(){
char selection [ 30 ];
    bzero(&selection,( 30 *sizeof(char) ) );
    {int choice; choice = (int)(selection); }
    {char selection [ 30 ]; selection [ ( 30 )-1 ] = (char)(selection); }
    {void * tlv11; tlv11 = (void *)(selection); }
    {cgc_size_t tlv10; tlv10 = (cgc_size_t)(selection); }
    {char * tlv14; tlv14 = (char *)(selection); }
    {char tlv13; tlv13 = (char)(selection); }
    {cgc_size_t tlv12; tlv12 = (cgc_size_t)(selection); }
    {int tlv1; tlv1 = (int)(selection); }
    {void * tlv17; tlv17 = (void *)(selection); }
    {cgc_size_t tlv16; tlv16 = (cgc_size_t)(selection); }
    {char * tlv20; tlv20 = (char *)(selection); }
    {char tlv19; tlv19 = (char)(selection); }
    {cgc_size_t tlv18; tlv18 = (cgc_size_t)(selection); }
    {void * tlv22; tlv22 = (void *)(selection); }
    {cgc_size_t tlv21; tlv21 = (cgc_size_t)(selection); }
    {char * tlv25; tlv25 = (char *)(selection); }
    {char tlv24; tlv24 = (char)(selection); }
    {cgc_size_t tlv23; tlv23 = (cgc_size_t)(selection); }
    {void * tlv27; tlv27 = (void *)(selection); }
    {cgc_size_t tlv26; tlv26 = (cgc_size_t)(selection); }
    {char * tlv30; tlv30 = (char *)(selection); }
    {char tlv29; tlv29 = (char)(selection); }
    {cgc_size_t tlv28; tlv28 = (cgc_size_t)(selection); }
    {cgc_size_t tlv58; tlv58 = (cgc_size_t)(selection); }
    {int tlv57; tlv57 = (int)(selection); }
    {void * tlv33; tlv33 = (void *)(selection); }
    {cgc_size_t tlv32; tlv32 = (cgc_size_t)(selection); }
    {char * tlv36; tlv36 = (char *)(selection); }
    {char tlv35; tlv35 = (char)(selection); }
    {cgc_size_t tlv34; tlv34 = (cgc_size_t)(selection); }
    {void * tlv39; tlv39 = (void *)(selection); }
    {cgc_size_t tlv38; tlv38 = (cgc_size_t)(selection); }
    {char * tlv42; tlv42 = (char *)(selection); }
    {char tlv41; tlv41 = (char)(selection); }
    {cgc_size_t tlv40; tlv40 = (cgc_size_t)(selection); }
    {void * tlv45; tlv45 = (void *)(selection); }
    {cgc_size_t tlv44; tlv44 = (cgc_size_t)(selection); }
    {char * tlv48; tlv48 = (char *)(selection); }
    {char tlv47; tlv47 = (char)(selection); }
    {cgc_size_t tlv46; tlv46 = (cgc_size_t)(selection); }
    {void * tlv51; tlv51 = (void *)(selection); }
    {cgc_size_t tlv50; tlv50 = (cgc_size_t)(selection); }
    {char * tlv54; tlv54 = (char *)(selection); }
    {char tlv53; tlv53 = (char)(selection); }
    {cgc_size_t tlv52; tlv52 = (cgc_size_t)(selection); }
}
void fix_ingred_cityParsers_0_11_1(){
char selection [ 30 ];
    bzero(&selection,( 30 *sizeof(char) ) );
    {int choice; choice = (int)(30); }
    {char selection [ 30 ]; selection [ ( 30 )-1 ] = (char)(30); }
    {void * tlv11; tlv11 = (void *)(30); }
    {cgc_size_t tlv10; tlv10 = (cgc_size_t)(30); }
    {char * tlv14; tlv14 = (char *)(30); }
    {char tlv13; tlv13 = (char)(30); }
    {cgc_size_t tlv12; tlv12 = (cgc_size_t)(30); }
    {int tlv1; tlv1 = (int)(30); }
    {void * tlv17; tlv17 = (void *)(30); }
    {cgc_size_t tlv16; tlv16 = (cgc_size_t)(30); }
    {char * tlv20; tlv20 = (char *)(30); }
    {char tlv19; tlv19 = (char)(30); }
    {cgc_size_t tlv18; tlv18 = (cgc_size_t)(30); }
    {void * tlv22; tlv22 = (void *)(30); }
    {cgc_size_t tlv21; tlv21 = (cgc_size_t)(30); }
    {char * tlv25; tlv25 = (char *)(30); }
    {char tlv24; tlv24 = (char)(30); }
    {cgc_size_t tlv23; tlv23 = (cgc_size_t)(30); }
    {void * tlv27; tlv27 = (void *)(30); }
    {cgc_size_t tlv26; tlv26 = (cgc_size_t)(30); }
    {char * tlv30; tlv30 = (char *)(30); }
    {char tlv29; tlv29 = (char)(30); }
    {cgc_size_t tlv28; tlv28 = (cgc_size_t)(30); }
    {cgc_size_t tlv58; tlv58 = (cgc_size_t)(30); }
    {int tlv57; tlv57 = (int)(30); }
    {void * tlv33; tlv33 = (void *)(30); }
    {cgc_size_t tlv32; tlv32 = (cgc_size_t)(30); }
    {char * tlv36; tlv36 = (char *)(30); }
    {char tlv35; tlv35 = (char)(30); }
    {cgc_size_t tlv34; tlv34 = (cgc_size_t)(30); }
    {void * tlv39; tlv39 = (void *)(30); }
    {cgc_size_t tlv38; tlv38 = (cgc_size_t)(30); }
    {char * tlv42; tlv42 = (char *)(30); }
    {char tlv41; tlv41 = (char)(30); }
    {cgc_size_t tlv40; tlv40 = (cgc_size_t)(30); }
    {void * tlv45; tlv45 = (void *)(30); }
    {cgc_size_t tlv44; tlv44 = (cgc_size_t)(30); }
    {char * tlv48; tlv48 = (char *)(30); }
    {char tlv47; tlv47 = (char)(30); }
    {cgc_size_t tlv46; tlv46 = (cgc_size_t)(30); }
    {void * tlv51; tlv51 = (void *)(30); }
    {cgc_size_t tlv50; tlv50 = (cgc_size_t)(30); }
    {char * tlv54; tlv54 = (char *)(30); }
    {char tlv53; tlv53 = (char)(30); }
    {cgc_size_t tlv52; tlv52 = (cgc_size_t)(30); }
}
void fix_ingred_cityParsers_0_11(){
fix_ingred_cityParsers_0_11_0();
fix_ingred_cityParsers_0_11_1();
}
void fix_ingred_cityParsers_0_12_0(){
char selection [ 30 ];
    bzero(&selection,( 30 *sizeof(char) ) );
    {int choice; choice = (int)(selection); }
    {char selection [ 30 ]; selection [ ( 30 )-1 ] = (char)(selection); }
    {void * tlv11; tlv11 = (void *)(selection); }
    {cgc_size_t tlv10; tlv10 = (cgc_size_t)(selection); }
    {char * tlv14; tlv14 = (char *)(selection); }
    {char tlv13; tlv13 = (char)(selection); }
    {cgc_size_t tlv12; tlv12 = (cgc_size_t)(selection); }
    {int tlv1; tlv1 = (int)(selection); }
    {void * tlv17; tlv17 = (void *)(selection); }
    {cgc_size_t tlv16; tlv16 = (cgc_size_t)(selection); }
    {char * tlv20; tlv20 = (char *)(selection); }
    {char tlv19; tlv19 = (char)(selection); }
    {cgc_size_t tlv18; tlv18 = (cgc_size_t)(selection); }
    {void * tlv22; tlv22 = (void *)(selection); }
    {cgc_size_t tlv21; tlv21 = (cgc_size_t)(selection); }
    {char * tlv25; tlv25 = (char *)(selection); }
    {char tlv24; tlv24 = (char)(selection); }
    {cgc_size_t tlv23; tlv23 = (cgc_size_t)(selection); }
    {void * tlv27; tlv27 = (void *)(selection); }
    {cgc_size_t tlv26; tlv26 = (cgc_size_t)(selection); }
    {char * tlv30; tlv30 = (char *)(selection); }
    {char tlv29; tlv29 = (char)(selection); }
    {cgc_size_t tlv28; tlv28 = (cgc_size_t)(selection); }
    {cgc_size_t tlv58; tlv58 = (cgc_size_t)(selection); }
    {int tlv57; tlv57 = (int)(selection); }
    {void * tlv33; tlv33 = (void *)(selection); }
    {cgc_size_t tlv32; tlv32 = (cgc_size_t)(selection); }
    {char * tlv36; tlv36 = (char *)(selection); }
    {char tlv35; tlv35 = (char)(selection); }
    {cgc_size_t tlv34; tlv34 = (cgc_size_t)(selection); }
    {void * tlv39; tlv39 = (void *)(selection); }
    {cgc_size_t tlv38; tlv38 = (cgc_size_t)(selection); }
    {char * tlv42; tlv42 = (char *)(selection); }
    {char tlv41; tlv41 = (char)(selection); }
    {cgc_size_t tlv40; tlv40 = (cgc_size_t)(selection); }
    {void * tlv45; tlv45 = (void *)(selection); }
    {cgc_size_t tlv44; tlv44 = (cgc_size_t)(selection); }
    {char * tlv48; tlv48 = (char *)(selection); }
    {char tlv47; tlv47 = (char)(selection); }
    {cgc_size_t tlv46; tlv46 = (cgc_size_t)(selection); }
    {void * tlv51; tlv51 = (void *)(selection); }
    {cgc_size_t tlv50; tlv50 = (cgc_size_t)(selection); }
    {char * tlv54; tlv54 = (char *)(selection); }
    {char tlv53; tlv53 = (char)(selection); }
    {cgc_size_t tlv52; tlv52 = (cgc_size_t)(selection); }
}
void fix_ingred_cityParsers_0_12_1(){
char selection [ 30 ];
    bzero(&selection,( 30 *sizeof(char) ) );
    {int choice; choice = (int)('\n'); }
    {char selection [ 30 ]; selection [ ( 30 )-1 ] = (char)('\n'); }
    {void * tlv11; tlv11 = (void *)('\n'); }
    {cgc_size_t tlv10; tlv10 = (cgc_size_t)('\n'); }
    {char * tlv14; tlv14 = (char *)('\n'); }
    {char tlv13; tlv13 = (char)('\n'); }
    {cgc_size_t tlv12; tlv12 = (cgc_size_t)('\n'); }
    {int tlv1; tlv1 = (int)('\n'); }
    {void * tlv17; tlv17 = (void *)('\n'); }
    {cgc_size_t tlv16; tlv16 = (cgc_size_t)('\n'); }
    {char * tlv20; tlv20 = (char *)('\n'); }
    {char tlv19; tlv19 = (char)('\n'); }
    {cgc_size_t tlv18; tlv18 = (cgc_size_t)('\n'); }
    {void * tlv22; tlv22 = (void *)('\n'); }
    {cgc_size_t tlv21; tlv21 = (cgc_size_t)('\n'); }
    {char * tlv25; tlv25 = (char *)('\n'); }
    {char tlv24; tlv24 = (char)('\n'); }
    {cgc_size_t tlv23; tlv23 = (cgc_size_t)('\n'); }
    {void * tlv27; tlv27 = (void *)('\n'); }
    {cgc_size_t tlv26; tlv26 = (cgc_size_t)('\n'); }
    {char * tlv30; tlv30 = (char *)('\n'); }
    {char tlv29; tlv29 = (char)('\n'); }
    {cgc_size_t tlv28; tlv28 = (cgc_size_t)('\n'); }
    {cgc_size_t tlv58; tlv58 = (cgc_size_t)('\n'); }
    {int tlv57; tlv57 = (int)('\n'); }
    {void * tlv33; tlv33 = (void *)('\n'); }
    {cgc_size_t tlv32; tlv32 = (cgc_size_t)('\n'); }
    {char * tlv36; tlv36 = (char *)('\n'); }
    {char tlv35; tlv35 = (char)('\n'); }
    {cgc_size_t tlv34; tlv34 = (cgc_size_t)('\n'); }
    {void * tlv39; tlv39 = (void *)('\n'); }
    {cgc_size_t tlv38; tlv38 = (cgc_size_t)('\n'); }
    {char * tlv42; tlv42 = (char *)('\n'); }
    {char tlv41; tlv41 = (char)('\n'); }
    {cgc_size_t tlv40; tlv40 = (cgc_size_t)('\n'); }
    {void * tlv45; tlv45 = (void *)('\n'); }
    {cgc_size_t tlv44; tlv44 = (cgc_size_t)('\n'); }
    {char * tlv48; tlv48 = (char *)('\n'); }
    {char tlv47; tlv47 = (char)('\n'); }
    {cgc_size_t tlv46; tlv46 = (cgc_size_t)('\n'); }
    {void * tlv51; tlv51 = (void *)('\n'); }
    {cgc_size_t tlv50; tlv50 = (cgc_size_t)('\n'); }
    {char * tlv54; tlv54 = (char *)('\n'); }
    {char tlv53; tlv53 = (char)('\n'); }
    {cgc_size_t tlv52; tlv52 = (cgc_size_t)('\n'); }
}
void fix_ingred_cityParsers_0_12_2(){
char selection [ 30 ];
    bzero(&selection,( 30 *sizeof(char) ) );
    {int choice; choice = (int)(4); }
    {char selection [ 30 ]; selection [ ( 30 )-1 ] = (char)(4); }
    {void * tlv11; tlv11 = (void *)(4); }
    {cgc_size_t tlv10; tlv10 = (cgc_size_t)(4); }
    {char * tlv14; tlv14 = (char *)(4); }
    {char tlv13; tlv13 = (char)(4); }
    {cgc_size_t tlv12; tlv12 = (cgc_size_t)(4); }
    {int tlv1; tlv1 = (int)(4); }
    {void * tlv17; tlv17 = (void *)(4); }
    {cgc_size_t tlv16; tlv16 = (cgc_size_t)(4); }
    {char * tlv20; tlv20 = (char *)(4); }
    {char tlv19; tlv19 = (char)(4); }
    {cgc_size_t tlv18; tlv18 = (cgc_size_t)(4); }
    {void * tlv22; tlv22 = (void *)(4); }
    {cgc_size_t tlv21; tlv21 = (cgc_size_t)(4); }
    {char * tlv25; tlv25 = (char *)(4); }
    {char tlv24; tlv24 = (char)(4); }
    {cgc_size_t tlv23; tlv23 = (cgc_size_t)(4); }
    {void * tlv27; tlv27 = (void *)(4); }
    {cgc_size_t tlv26; tlv26 = (cgc_size_t)(4); }
    {char * tlv30; tlv30 = (char *)(4); }
    {char tlv29; tlv29 = (char)(4); }
    {cgc_size_t tlv28; tlv28 = (cgc_size_t)(4); }
    {cgc_size_t tlv58; tlv58 = (cgc_size_t)(4); }
    {int tlv57; tlv57 = (int)(4); }
    {void * tlv33; tlv33 = (void *)(4); }
    {cgc_size_t tlv32; tlv32 = (cgc_size_t)(4); }
    {char * tlv36; tlv36 = (char *)(4); }
    {char tlv35; tlv35 = (char)(4); }
    {cgc_size_t tlv34; tlv34 = (cgc_size_t)(4); }
    {void * tlv39; tlv39 = (void *)(4); }
    {cgc_size_t tlv38; tlv38 = (cgc_size_t)(4); }
    {char * tlv42; tlv42 = (char *)(4); }
    {char tlv41; tlv41 = (char)(4); }
    {cgc_size_t tlv40; tlv40 = (cgc_size_t)(4); }
    {void * tlv45; tlv45 = (void *)(4); }
    {cgc_size_t tlv44; tlv44 = (cgc_size_t)(4); }
    {char * tlv48; tlv48 = (char *)(4); }
    {char tlv47; tlv47 = (char)(4); }
    {cgc_size_t tlv46; tlv46 = (cgc_size_t)(4); }
    {void * tlv51; tlv51 = (void *)(4); }
    {cgc_size_t tlv50; tlv50 = (cgc_size_t)(4); }
    {char * tlv54; tlv54 = (char *)(4); }
    {char tlv53; tlv53 = (char)(4); }
    {cgc_size_t tlv52; tlv52 = (cgc_size_t)(4); }
}
void fix_ingred_cityParsers_0_12(){
fix_ingred_cityParsers_0_12_0();
fix_ingred_cityParsers_0_12_1();
fix_ingred_cityParsers_0_12_2();
}
void fix_ingred_cityParsers_0_19_2(){
    {int choice; choice = (int)(29); }
    {char selection [ 30 ]; selection [ ( 30 )-1 ] = (char)(29); }
    {void * tlv11; tlv11 = (void *)(29); }
    {cgc_size_t tlv10; tlv10 = (cgc_size_t)(29); }
    {char * tlv14; tlv14 = (char *)(29); }
    {char tlv13; tlv13 = (char)(29); }
    {cgc_size_t tlv12; tlv12 = (cgc_size_t)(29); }
    {int tlv1; tlv1 = (int)(29); }
    {void * tlv17; tlv17 = (void *)(29); }
    {cgc_size_t tlv16; tlv16 = (cgc_size_t)(29); }
    {char * tlv20; tlv20 = (char *)(29); }
    {char tlv19; tlv19 = (char)(29); }
    {cgc_size_t tlv18; tlv18 = (cgc_size_t)(29); }
    {void * tlv22; tlv22 = (void *)(29); }
    {cgc_size_t tlv21; tlv21 = (cgc_size_t)(29); }
    {char * tlv25; tlv25 = (char *)(29); }
    {char tlv24; tlv24 = (char)(29); }
    {cgc_size_t tlv23; tlv23 = (cgc_size_t)(29); }
    {void * tlv27; tlv27 = (void *)(29); }
    {cgc_size_t tlv26; tlv26 = (cgc_size_t)(29); }
    {char * tlv30; tlv30 = (char *)(29); }
    {char tlv29; tlv29 = (char)(29); }
    {cgc_size_t tlv28; tlv28 = (cgc_size_t)(29); }
    {cgc_size_t tlv58; tlv58 = (cgc_size_t)(29); }
    {int tlv57; tlv57 = (int)(29); }
    {void * tlv33; tlv33 = (void *)(29); }
    {cgc_size_t tlv32; tlv32 = (cgc_size_t)(29); }
    {char * tlv36; tlv36 = (char *)(29); }
    {char tlv35; tlv35 = (char)(29); }
    {cgc_size_t tlv34; tlv34 = (cgc_size_t)(29); }
    {void * tlv39; tlv39 = (void *)(29); }
    {cgc_size_t tlv38; tlv38 = (cgc_size_t)(29); }
    {char * tlv42; tlv42 = (char *)(29); }
    {char tlv41; tlv41 = (char)(29); }
    {cgc_size_t tlv40; tlv40 = (cgc_size_t)(29); }
    {void * tlv45; tlv45 = (void *)(29); }
    {cgc_size_t tlv44; tlv44 = (cgc_size_t)(29); }
    {char * tlv48; tlv48 = (char *)(29); }
    {char tlv47; tlv47 = (char)(29); }
    {cgc_size_t tlv46; tlv46 = (cgc_size_t)(29); }
    {void * tlv51; tlv51 = (void *)(29); }
    {cgc_size_t tlv50; tlv50 = (cgc_size_t)(29); }
    {char * tlv54; tlv54 = (char *)(29); }
    {char tlv53; tlv53 = (char)(29); }
    {cgc_size_t tlv52; tlv52 = (cgc_size_t)(29); }
}
void fix_ingred_cityParsers_0_19(){
fix_ingred_cityParsers_0_19_2();
}
void fix_ingred_cityParsers_0_20_4(){
char selection [ 30 ];
    bzero(&selection,( 30 *sizeof(char) ) );
int choice;
    bzero(&choice,sizeof(int));
    {if (selection){    choice = 0;
         char selection [ 30 ]; selection [ ( 30 )-1 ] = (char)(selection [ choice ]); }}
    {if (selection){    choice = 0;
         void * tlv11; tlv11 = (void *)(selection [ choice ]); }}
    {if (selection){    choice = 0;
         cgc_size_t tlv10; tlv10 = (cgc_size_t)(selection [ choice ]); }}
    {if (selection){    choice = 0;
         char * tlv14; tlv14 = (char *)(selection [ choice ]); }}
    {if (selection){    choice = 0;
         char tlv13; tlv13 = (char)(selection [ choice ]); }}
    {if (selection){    choice = 0;
         cgc_size_t tlv12; tlv12 = (cgc_size_t)(selection [ choice ]); }}
    {if (selection){    choice = 0;
         int tlv1; tlv1 = (int)(selection [ choice ]); }}
    {if (selection){    choice = 0;
         void * tlv17; tlv17 = (void *)(selection [ choice ]); }}
    {if (selection){    choice = 0;
         cgc_size_t tlv16; tlv16 = (cgc_size_t)(selection [ choice ]); }}
    {if (selection){    choice = 0;
         char * tlv20; tlv20 = (char *)(selection [ choice ]); }}
    {if (selection){    choice = 0;
         char tlv19; tlv19 = (char)(selection [ choice ]); }}
    {if (selection){    choice = 0;
         cgc_size_t tlv18; tlv18 = (cgc_size_t)(selection [ choice ]); }}
    {if (selection){    choice = 0;
         void * tlv22; tlv22 = (void *)(selection [ choice ]); }}
    {if (selection){    choice = 0;
         cgc_size_t tlv21; tlv21 = (cgc_size_t)(selection [ choice ]); }}
    {if (selection){    choice = 0;
         char * tlv25; tlv25 = (char *)(selection [ choice ]); }}
    {if (selection){    choice = 0;
         char tlv24; tlv24 = (char)(selection [ choice ]); }}
    {if (selection){    choice = 0;
         cgc_size_t tlv23; tlv23 = (cgc_size_t)(selection [ choice ]); }}
    {if (selection){    choice = 0;
         void * tlv27; tlv27 = (void *)(selection [ choice ]); }}
    {if (selection){    choice = 0;
         cgc_size_t tlv26; tlv26 = (cgc_size_t)(selection [ choice ]); }}
    {if (selection){    choice = 0;
         char * tlv30; tlv30 = (char *)(selection [ choice ]); }}
    {if (selection){    choice = 0;
         char tlv29; tlv29 = (char)(selection [ choice ]); }}
    {if (selection){    choice = 0;
         cgc_size_t tlv28; tlv28 = (cgc_size_t)(selection [ choice ]); }}
    {if (selection){    choice = 0;
         cgc_size_t tlv58; tlv58 = (cgc_size_t)(selection [ choice ]); }}
    {if (selection){    choice = 0;
         int tlv57; tlv57 = (int)(selection [ choice ]); }}
    {if (selection){    choice = 0;
         void * tlv33; tlv33 = (void *)(selection [ choice ]); }}
    {if (selection){    choice = 0;
         cgc_size_t tlv32; tlv32 = (cgc_size_t)(selection [ choice ]); }}
    {if (selection){    choice = 0;
         char * tlv36; tlv36 = (char *)(selection [ choice ]); }}
    {if (selection){    choice = 0;
         char tlv35; tlv35 = (char)(selection [ choice ]); }}
    {if (selection){    choice = 0;
         cgc_size_t tlv34; tlv34 = (cgc_size_t)(selection [ choice ]); }}
    {if (selection){    choice = 0;
         void * tlv39; tlv39 = (void *)(selection [ choice ]); }}
    {if (selection){    choice = 0;
         cgc_size_t tlv38; tlv38 = (cgc_size_t)(selection [ choice ]); }}
    {if (selection){    choice = 0;
         char * tlv42; tlv42 = (char *)(selection [ choice ]); }}
    {if (selection){    choice = 0;
         char tlv41; tlv41 = (char)(selection [ choice ]); }}
    {if (selection){    choice = 0;
         cgc_size_t tlv40; tlv40 = (cgc_size_t)(selection [ choice ]); }}
    {if (selection){    choice = 0;
         void * tlv45; tlv45 = (void *)(selection [ choice ]); }}
    {if (selection){    choice = 0;
         cgc_size_t tlv44; tlv44 = (cgc_size_t)(selection [ choice ]); }}
    {if (selection){    choice = 0;
         char * tlv48; tlv48 = (char *)(selection [ choice ]); }}
    {if (selection){    choice = 0;
         char tlv47; tlv47 = (char)(selection [ choice ]); }}
    {if (selection){    choice = 0;
         cgc_size_t tlv46; tlv46 = (cgc_size_t)(selection [ choice ]); }}
    {if (selection){    choice = 0;
         void * tlv51; tlv51 = (void *)(selection [ choice ]); }}
    {if (selection){    choice = 0;
         cgc_size_t tlv50; tlv50 = (cgc_size_t)(selection [ choice ]); }}
    {if (selection){    choice = 0;
         char * tlv54; tlv54 = (char *)(selection [ choice ]); }}
    {if (selection){    choice = 0;
         char tlv53; tlv53 = (char)(selection [ choice ]); }}
    {if (selection){    choice = 0;
         cgc_size_t tlv52; tlv52 = (cgc_size_t)(selection [ choice ]); }}
}
void fix_ingred_cityParsers_0_20_5(){
char selection [ 30 ];
    bzero(&selection,( 30 *sizeof(char) ) );
int choice;
    bzero(&choice,sizeof(int));
    {int choice; choice = (int)(' '); }
    {char selection [ 30 ]; selection [ ( 30 )-1 ] = (char)(' '); }
    {void * tlv11; tlv11 = (void *)(' '); }
    {cgc_size_t tlv10; tlv10 = (cgc_size_t)(' '); }
    {char * tlv14; tlv14 = (char *)(' '); }
    {char tlv13; tlv13 = (char)(' '); }
    {cgc_size_t tlv12; tlv12 = (cgc_size_t)(' '); }
    {int tlv1; tlv1 = (int)(' '); }
    {void * tlv17; tlv17 = (void *)(' '); }
    {cgc_size_t tlv16; tlv16 = (cgc_size_t)(' '); }
    {char * tlv20; tlv20 = (char *)(' '); }
    {char tlv19; tlv19 = (char)(' '); }
    {cgc_size_t tlv18; tlv18 = (cgc_size_t)(' '); }
    {void * tlv22; tlv22 = (void *)(' '); }
    {cgc_size_t tlv21; tlv21 = (cgc_size_t)(' '); }
    {char * tlv25; tlv25 = (char *)(' '); }
    {char tlv24; tlv24 = (char)(' '); }
    {cgc_size_t tlv23; tlv23 = (cgc_size_t)(' '); }
    {void * tlv27; tlv27 = (void *)(' '); }
    {cgc_size_t tlv26; tlv26 = (cgc_size_t)(' '); }
    {char * tlv30; tlv30 = (char *)(' '); }
    {char tlv29; tlv29 = (char)(' '); }
    {cgc_size_t tlv28; tlv28 = (cgc_size_t)(' '); }
    {cgc_size_t tlv58; tlv58 = (cgc_size_t)(' '); }
    {int tlv57; tlv57 = (int)(' '); }
    {void * tlv33; tlv33 = (void *)(' '); }
    {cgc_size_t tlv32; tlv32 = (cgc_size_t)(' '); }
    {char * tlv36; tlv36 = (char *)(' '); }
    {char tlv35; tlv35 = (char)(' '); }
    {cgc_size_t tlv34; tlv34 = (cgc_size_t)(' '); }
    {void * tlv39; tlv39 = (void *)(' '); }
    {cgc_size_t tlv38; tlv38 = (cgc_size_t)(' '); }
    {char * tlv42; tlv42 = (char *)(' '); }
    {char tlv41; tlv41 = (char)(' '); }
    {cgc_size_t tlv40; tlv40 = (cgc_size_t)(' '); }
    {void * tlv45; tlv45 = (void *)(' '); }
    {cgc_size_t tlv44; tlv44 = (cgc_size_t)(' '); }
    {char * tlv48; tlv48 = (char *)(' '); }
    {char tlv47; tlv47 = (char)(' '); }
    {cgc_size_t tlv46; tlv46 = (cgc_size_t)(' '); }
    {void * tlv51; tlv51 = (void *)(' '); }
    {cgc_size_t tlv50; tlv50 = (cgc_size_t)(' '); }
    {char * tlv54; tlv54 = (char *)(' '); }
    {char tlv53; tlv53 = (char)(' '); }
    {cgc_size_t tlv52; tlv52 = (cgc_size_t)(' '); }
}
void fix_ingred_cityParsers_0_20(){
fix_ingred_cityParsers_0_20_4();
fix_ingred_cityParsers_0_20_5();
}
void fix_ingred_cityParsers_0_25_7(){
    {int choice; choice = (int)(':'); }
    {char selection [ 30 ]; selection [ ( 30 )-1 ] = (char)(':'); }
    {void * tlv11; tlv11 = (void *)(':'); }
    {cgc_size_t tlv10; tlv10 = (cgc_size_t)(':'); }
    {char * tlv14; tlv14 = (char *)(':'); }
    {char tlv13; tlv13 = (char)(':'); }
    {cgc_size_t tlv12; tlv12 = (cgc_size_t)(':'); }
    {int tlv1; tlv1 = (int)(':'); }
    {void * tlv17; tlv17 = (void *)(':'); }
    {cgc_size_t tlv16; tlv16 = (cgc_size_t)(':'); }
    {char * tlv20; tlv20 = (char *)(':'); }
    {char tlv19; tlv19 = (char)(':'); }
    {cgc_size_t tlv18; tlv18 = (cgc_size_t)(':'); }
    {void * tlv22; tlv22 = (void *)(':'); }
    {cgc_size_t tlv21; tlv21 = (cgc_size_t)(':'); }
    {char * tlv25; tlv25 = (char *)(':'); }
    {char tlv24; tlv24 = (char)(':'); }
    {cgc_size_t tlv23; tlv23 = (cgc_size_t)(':'); }
    {void * tlv27; tlv27 = (void *)(':'); }
    {cgc_size_t tlv26; tlv26 = (cgc_size_t)(':'); }
    {char * tlv30; tlv30 = (char *)(':'); }
    {char tlv29; tlv29 = (char)(':'); }
    {cgc_size_t tlv28; tlv28 = (cgc_size_t)(':'); }
    {cgc_size_t tlv58; tlv58 = (cgc_size_t)(':'); }
    {int tlv57; tlv57 = (int)(':'); }
    {void * tlv33; tlv33 = (void *)(':'); }
    {cgc_size_t tlv32; tlv32 = (cgc_size_t)(':'); }
    {char * tlv36; tlv36 = (char *)(':'); }
    {char tlv35; tlv35 = (char)(':'); }
    {cgc_size_t tlv34; tlv34 = (cgc_size_t)(':'); }
    {void * tlv39; tlv39 = (void *)(':'); }
    {cgc_size_t tlv38; tlv38 = (cgc_size_t)(':'); }
    {char * tlv42; tlv42 = (char *)(':'); }
    {char tlv41; tlv41 = (char)(':'); }
    {cgc_size_t tlv40; tlv40 = (cgc_size_t)(':'); }
    {void * tlv45; tlv45 = (void *)(':'); }
    {cgc_size_t tlv44; tlv44 = (cgc_size_t)(':'); }
    {char * tlv48; tlv48 = (char *)(':'); }
    {char tlv47; tlv47 = (char)(':'); }
    {cgc_size_t tlv46; tlv46 = (cgc_size_t)(':'); }
    {void * tlv51; tlv51 = (void *)(':'); }
    {cgc_size_t tlv50; tlv50 = (cgc_size_t)(':'); }
    {char * tlv54; tlv54 = (char *)(':'); }
    {char tlv53; tlv53 = (char)(':'); }
    {cgc_size_t tlv52; tlv52 = (cgc_size_t)(':'); }
}
void fix_ingred_cityParsers_0_25_9(){
    {int choice; choice = (int)('.'); }
    {char selection [ 30 ]; selection [ ( 30 )-1 ] = (char)('.'); }
    {void * tlv11; tlv11 = (void *)('.'); }
    {cgc_size_t tlv10; tlv10 = (cgc_size_t)('.'); }
    {char * tlv14; tlv14 = (char *)('.'); }
    {char tlv13; tlv13 = (char)('.'); }
    {cgc_size_t tlv12; tlv12 = (cgc_size_t)('.'); }
    {int tlv1; tlv1 = (int)('.'); }
    {void * tlv17; tlv17 = (void *)('.'); }
    {cgc_size_t tlv16; tlv16 = (cgc_size_t)('.'); }
    {char * tlv20; tlv20 = (char *)('.'); }
    {char tlv19; tlv19 = (char)('.'); }
    {cgc_size_t tlv18; tlv18 = (cgc_size_t)('.'); }
    {void * tlv22; tlv22 = (void *)('.'); }
    {cgc_size_t tlv21; tlv21 = (cgc_size_t)('.'); }
    {char * tlv25; tlv25 = (char *)('.'); }
    {char tlv24; tlv24 = (char)('.'); }
    {cgc_size_t tlv23; tlv23 = (cgc_size_t)('.'); }
    {void * tlv27; tlv27 = (void *)('.'); }
    {cgc_size_t tlv26; tlv26 = (cgc_size_t)('.'); }
    {char * tlv30; tlv30 = (char *)('.'); }
    {char tlv29; tlv29 = (char)('.'); }
    {cgc_size_t tlv28; tlv28 = (cgc_size_t)('.'); }
    {cgc_size_t tlv58; tlv58 = (cgc_size_t)('.'); }
    {int tlv57; tlv57 = (int)('.'); }
    {void * tlv33; tlv33 = (void *)('.'); }
    {cgc_size_t tlv32; tlv32 = (cgc_size_t)('.'); }
    {char * tlv36; tlv36 = (char *)('.'); }
    {char tlv35; tlv35 = (char)('.'); }
    {cgc_size_t tlv34; tlv34 = (cgc_size_t)('.'); }
    {void * tlv39; tlv39 = (void *)('.'); }
    {cgc_size_t tlv38; tlv38 = (cgc_size_t)('.'); }
    {char * tlv42; tlv42 = (char *)('.'); }
    {char tlv41; tlv41 = (char)('.'); }
    {cgc_size_t tlv40; tlv40 = (cgc_size_t)('.'); }
    {void * tlv45; tlv45 = (void *)('.'); }
    {cgc_size_t tlv44; tlv44 = (cgc_size_t)('.'); }
    {char * tlv48; tlv48 = (char *)('.'); }
    {char tlv47; tlv47 = (char)('.'); }
    {cgc_size_t tlv46; tlv46 = (cgc_size_t)('.'); }
    {void * tlv51; tlv51 = (void *)('.'); }
    {cgc_size_t tlv50; tlv50 = (cgc_size_t)('.'); }
    {char * tlv54; tlv54 = (char *)('.'); }
    {char tlv53; tlv53 = (char)('.'); }
    {cgc_size_t tlv52; tlv52 = (cgc_size_t)('.'); }
}
void fix_ingred_cityParsers_0_25(){
fix_ingred_cityParsers_0_25_7();
fix_ingred_cityParsers_0_25_9();
}
void fix_ingred_cityParsers_0_34_0(){
    {int choice; choice = (int)(sizeof ( Border )); }
    {char selection [ 30 ]; selection [ ( 30 )-1 ] = (char)(sizeof ( Border )); }
    {void * tlv11; tlv11 = (void *)(sizeof ( Border )); }
    {cgc_size_t tlv10; tlv10 = (cgc_size_t)(sizeof ( Border )); }
    {char * tlv14; tlv14 = (char *)(sizeof ( Border )); }
    {char tlv13; tlv13 = (char)(sizeof ( Border )); }
    {cgc_size_t tlv12; tlv12 = (cgc_size_t)(sizeof ( Border )); }
    {int tlv1; tlv1 = (int)(sizeof ( Border )); }
    {void * tlv17; tlv17 = (void *)(sizeof ( Border )); }
    {cgc_size_t tlv16; tlv16 = (cgc_size_t)(sizeof ( Border )); }
    {char * tlv20; tlv20 = (char *)(sizeof ( Border )); }
    {char tlv19; tlv19 = (char)(sizeof ( Border )); }
    {cgc_size_t tlv18; tlv18 = (cgc_size_t)(sizeof ( Border )); }
    {void * tlv22; tlv22 = (void *)(sizeof ( Border )); }
    {cgc_size_t tlv21; tlv21 = (cgc_size_t)(sizeof ( Border )); }
    {char * tlv25; tlv25 = (char *)(sizeof ( Border )); }
    {char tlv24; tlv24 = (char)(sizeof ( Border )); }
    {cgc_size_t tlv23; tlv23 = (cgc_size_t)(sizeof ( Border )); }
    {void * tlv27; tlv27 = (void *)(sizeof ( Border )); }
    {cgc_size_t tlv26; tlv26 = (cgc_size_t)(sizeof ( Border )); }
    {char * tlv30; tlv30 = (char *)(sizeof ( Border )); }
    {char tlv29; tlv29 = (char)(sizeof ( Border )); }
    {cgc_size_t tlv28; tlv28 = (cgc_size_t)(sizeof ( Border )); }
    {cgc_size_t tlv58; tlv58 = (cgc_size_t)(sizeof ( Border )); }
    {int tlv57; tlv57 = (int)(sizeof ( Border )); }
    {void * tlv33; tlv33 = (void *)(sizeof ( Border )); }
    {cgc_size_t tlv32; tlv32 = (cgc_size_t)(sizeof ( Border )); }
    {char * tlv36; tlv36 = (char *)(sizeof ( Border )); }
    {char tlv35; tlv35 = (char)(sizeof ( Border )); }
    {cgc_size_t tlv34; tlv34 = (cgc_size_t)(sizeof ( Border )); }
    {void * tlv39; tlv39 = (void *)(sizeof ( Border )); }
    {cgc_size_t tlv38; tlv38 = (cgc_size_t)(sizeof ( Border )); }
    {char * tlv42; tlv42 = (char *)(sizeof ( Border )); }
    {char tlv41; tlv41 = (char)(sizeof ( Border )); }
    {cgc_size_t tlv40; tlv40 = (cgc_size_t)(sizeof ( Border )); }
    {void * tlv45; tlv45 = (void *)(sizeof ( Border )); }
    {cgc_size_t tlv44; tlv44 = (cgc_size_t)(sizeof ( Border )); }
    {char * tlv48; tlv48 = (char *)(sizeof ( Border )); }
    {char tlv47; tlv47 = (char)(sizeof ( Border )); }
    {cgc_size_t tlv46; tlv46 = (cgc_size_t)(sizeof ( Border )); }
    {void * tlv51; tlv51 = (void *)(sizeof ( Border )); }
    {cgc_size_t tlv50; tlv50 = (cgc_size_t)(sizeof ( Border )); }
    {char * tlv54; tlv54 = (char *)(sizeof ( Border )); }
    {char tlv53; tlv53 = (char)(sizeof ( Border )); }
    {cgc_size_t tlv52; tlv52 = (cgc_size_t)(sizeof ( Border )); }
}
void fix_ingred_cityParsers_0_34(){
fix_ingred_cityParsers_0_34_0();
}
void fix_ingred_cityParsers_0_35_7(){
int tlv1;
    bzero(&tlv1,sizeof(int));
    {int choice; choice = (int)(tlv1); }
    {char selection [ 30 ]; selection [ ( 30 )-1 ] = (char)(tlv1); }
    {void * tlv11; tlv11 = (void *)(tlv1); }
    {cgc_size_t tlv10; tlv10 = (cgc_size_t)(tlv1); }
    {char * tlv14; tlv14 = (char *)(tlv1); }
    {char tlv13; tlv13 = (char)(tlv1); }
    {cgc_size_t tlv12; tlv12 = (cgc_size_t)(tlv1); }
    {void * tlv17; tlv17 = (void *)(tlv1); }
    {cgc_size_t tlv16; tlv16 = (cgc_size_t)(tlv1); }
    {char * tlv20; tlv20 = (char *)(tlv1); }
    {char tlv19; tlv19 = (char)(tlv1); }
    {cgc_size_t tlv18; tlv18 = (cgc_size_t)(tlv1); }
    {void * tlv22; tlv22 = (void *)(tlv1); }
    {cgc_size_t tlv21; tlv21 = (cgc_size_t)(tlv1); }
    {char * tlv25; tlv25 = (char *)(tlv1); }
    {char tlv24; tlv24 = (char)(tlv1); }
    {cgc_size_t tlv23; tlv23 = (cgc_size_t)(tlv1); }
    {void * tlv27; tlv27 = (void *)(tlv1); }
    {cgc_size_t tlv26; tlv26 = (cgc_size_t)(tlv1); }
    {char * tlv30; tlv30 = (char *)(tlv1); }
    {char tlv29; tlv29 = (char)(tlv1); }
    {cgc_size_t tlv28; tlv28 = (cgc_size_t)(tlv1); }
    {cgc_size_t tlv58; tlv58 = (cgc_size_t)(tlv1); }
    {int tlv57; tlv57 = (int)(tlv1); }
    {void * tlv33; tlv33 = (void *)(tlv1); }
    {cgc_size_t tlv32; tlv32 = (cgc_size_t)(tlv1); }
    {char * tlv36; tlv36 = (char *)(tlv1); }
    {char tlv35; tlv35 = (char)(tlv1); }
    {cgc_size_t tlv34; tlv34 = (cgc_size_t)(tlv1); }
    {void * tlv39; tlv39 = (void *)(tlv1); }
    {cgc_size_t tlv38; tlv38 = (cgc_size_t)(tlv1); }
    {char * tlv42; tlv42 = (char *)(tlv1); }
    {char tlv41; tlv41 = (char)(tlv1); }
    {cgc_size_t tlv40; tlv40 = (cgc_size_t)(tlv1); }
    {void * tlv45; tlv45 = (void *)(tlv1); }
    {cgc_size_t tlv44; tlv44 = (cgc_size_t)(tlv1); }
    {char * tlv48; tlv48 = (char *)(tlv1); }
    {char tlv47; tlv47 = (char)(tlv1); }
    {cgc_size_t tlv46; tlv46 = (cgc_size_t)(tlv1); }
    {void * tlv51; tlv51 = (void *)(tlv1); }
    {cgc_size_t tlv50; tlv50 = (cgc_size_t)(tlv1); }
    {char * tlv54; tlv54 = (char *)(tlv1); }
    {char tlv53; tlv53 = (char)(tlv1); }
    {cgc_size_t tlv52; tlv52 = (cgc_size_t)(tlv1); }
}
void fix_ingred_cityParsers_0_35(){
fix_ingred_cityParsers_0_35_7();
}
void fix_ingred_cityParsers_0_38_2(){
    {int choice; choice = (int)(19); }
    {char selection [ 30 ]; selection [ ( 30 )-1 ] = (char)(19); }
    {void * tlv11; tlv11 = (void *)(19); }
    {cgc_size_t tlv10; tlv10 = (cgc_size_t)(19); }
    {char * tlv14; tlv14 = (char *)(19); }
    {char tlv13; tlv13 = (char)(19); }
    {cgc_size_t tlv12; tlv12 = (cgc_size_t)(19); }
    {int tlv1; tlv1 = (int)(19); }
    {void * tlv17; tlv17 = (void *)(19); }
    {cgc_size_t tlv16; tlv16 = (cgc_size_t)(19); }
    {char * tlv20; tlv20 = (char *)(19); }
    {char tlv19; tlv19 = (char)(19); }
    {cgc_size_t tlv18; tlv18 = (cgc_size_t)(19); }
    {void * tlv22; tlv22 = (void *)(19); }
    {cgc_size_t tlv21; tlv21 = (cgc_size_t)(19); }
    {char * tlv25; tlv25 = (char *)(19); }
    {char tlv24; tlv24 = (char)(19); }
    {cgc_size_t tlv23; tlv23 = (cgc_size_t)(19); }
    {void * tlv27; tlv27 = (void *)(19); }
    {cgc_size_t tlv26; tlv26 = (cgc_size_t)(19); }
    {char * tlv30; tlv30 = (char *)(19); }
    {char tlv29; tlv29 = (char)(19); }
    {cgc_size_t tlv28; tlv28 = (cgc_size_t)(19); }
    {cgc_size_t tlv58; tlv58 = (cgc_size_t)(19); }
    {int tlv57; tlv57 = (int)(19); }
    {void * tlv33; tlv33 = (void *)(19); }
    {cgc_size_t tlv32; tlv32 = (cgc_size_t)(19); }
    {char * tlv36; tlv36 = (char *)(19); }
    {char tlv35; tlv35 = (char)(19); }
    {cgc_size_t tlv34; tlv34 = (cgc_size_t)(19); }
    {void * tlv39; tlv39 = (void *)(19); }
    {cgc_size_t tlv38; tlv38 = (cgc_size_t)(19); }
    {char * tlv42; tlv42 = (char *)(19); }
    {char tlv41; tlv41 = (char)(19); }
    {cgc_size_t tlv40; tlv40 = (cgc_size_t)(19); }
    {void * tlv45; tlv45 = (void *)(19); }
    {cgc_size_t tlv44; tlv44 = (cgc_size_t)(19); }
    {char * tlv48; tlv48 = (char *)(19); }
    {char tlv47; tlv47 = (char)(19); }
    {cgc_size_t tlv46; tlv46 = (cgc_size_t)(19); }
    {void * tlv51; tlv51 = (void *)(19); }
    {cgc_size_t tlv50; tlv50 = (cgc_size_t)(19); }
    {char * tlv54; tlv54 = (char *)(19); }
    {char tlv53; tlv53 = (char)(19); }
    {cgc_size_t tlv52; tlv52 = (cgc_size_t)(19); }
}
void fix_ingred_cityParsers_0_38(){
fix_ingred_cityParsers_0_38_2();
}
void fix_ingred_cityParsers_0(){
fix_ingred_cityParsers_0_0();
fix_ingred_cityParsers_0_11();
fix_ingred_cityParsers_0_12();
fix_ingred_cityParsers_0_19();
fix_ingred_cityParsers_0_20();
fix_ingred_cityParsers_0_25();
fix_ingred_cityParsers_0_34();
fix_ingred_cityParsers_0_35();
fix_ingred_cityParsers_0_38();
}
void fix_ingred_cityParsers_1_2_0(){
char buffer_ref;
    bzero(&buffer_ref,1*sizeof(char));
char * * buffer = &buffer_ref;
    {void * tlv2; tlv2 = (void *)(* buffer); }
    {cgc_size_t tlv1; tlv1 = (cgc_size_t)(* buffer); }
    {char * tlv3; tlv3 = (char *)(* buffer); }
}
void fix_ingred_cityParsers_1_2_1(){
char buffer_ref;
    bzero(&buffer_ref,1*sizeof(char));
char * * buffer = &buffer_ref;
    {void * tlv2; tlv2 = (void *)(NULL); }
    {cgc_size_t tlv1; tlv1 = (cgc_size_t)(NULL); }
    {char * tlv3; tlv3 = (char *)(NULL); }
}
void fix_ingred_cityParsers_1_2(){
fix_ingred_cityParsers_1_2_0();
fix_ingred_cityParsers_1_2_1();
}
void fix_ingred_cityParsers_1_3_0(){
char buffer_ref;
    bzero(&buffer_ref,1*sizeof(char));
char * * buffer = &buffer_ref;
    {void * tlv2; tlv2 = (void *)(* buffer); }
    {cgc_size_t tlv1; tlv1 = (cgc_size_t)(* buffer); }
    {char * tlv3; tlv3 = (char *)(* buffer); }
}
void fix_ingred_cityParsers_1_3(){
fix_ingred_cityParsers_1_3_0();
}
void fix_ingred_cityParsers_1_4_1(){
char tlv3_ref;
    bzero(&tlv3_ref,1*sizeof(char));
char * tlv3 = &tlv3_ref;
    {void * tlv2; tlv2 = (void *)(cgc_strlen ( tlv3 ) + 1); }
    {cgc_size_t tlv1; tlv1 = (cgc_size_t)(cgc_strlen ( tlv3 ) + 1); }
}
void fix_ingred_cityParsers_1_4(){
fix_ingred_cityParsers_1_4_1();
}
void fix_ingred_cityParsers_1(){
fix_ingred_cityParsers_1_2();
fix_ingred_cityParsers_1_3();
fix_ingred_cityParsers_1_4();
}
void fix_ingred_cityParsers_2_0_0(){
    {int index; index = (int)(0); }
    {void * tlv2; tlv2 = (void *)(0); }
    {cgc_size_t tlv1; tlv1 = (cgc_size_t)(0); }
    {void * tlv4; tlv4 = (void *)(0); }
    {cgc_size_t tlv3; tlv3 = (cgc_size_t)(0); }
}
void fix_ingred_cityParsers_2_0(){
fix_ingred_cityParsers_2_0_0();
}
void fix_ingred_cityParsers_2_2_2(){
int index;
    bzero(&index,sizeof(int));
City ci_ref;
    bzero(&ci_ref,1*sizeof(City));
pCity ci = &ci_ref;
    {void * tlv2; tlv2 = (void *)(index); }
    {cgc_size_t tlv1; tlv1 = (cgc_size_t)(index); }
    {void * tlv4; tlv4 = (void *)(index); }
    {cgc_size_t tlv3; tlv3 = (cgc_size_t)(index); }
}
void fix_ingred_cityParsers_2_2_3(){
int index;
    bzero(&index,sizeof(int));
City ci_ref;
    bzero(&ci_ref,1*sizeof(City));
pCity ci = &ci_ref;
    {int index; index = (int)(ci -> border_count); }
    {void * tlv2; tlv2 = (void *)(ci -> border_count); }
    {cgc_size_t tlv1; tlv1 = (cgc_size_t)(ci -> border_count); }
    {void * tlv4; tlv4 = (void *)(ci -> border_count); }
    {cgc_size_t tlv3; tlv3 = (cgc_size_t)(ci -> border_count); }
}
void fix_ingred_cityParsers_2_2(){
fix_ingred_cityParsers_2_2_2();
fix_ingred_cityParsers_2_2_3();
}
void fix_ingred_cityParsers_2_3_0(){
City ci_ref;
    bzero(&ci_ref,1*sizeof(City));
pCity ci = &ci_ref;
    {int index; index = (int)(ci -> borders); }
    {void * tlv2; tlv2 = (void *)(ci -> borders); }
    {cgc_size_t tlv1; tlv1 = (cgc_size_t)(ci -> borders); }
    {void * tlv4; tlv4 = (void *)(ci -> borders); }
    {cgc_size_t tlv3; tlv3 = (cgc_size_t)(ci -> borders); }
}
void fix_ingred_cityParsers_2_3_1(){
City ci_ref;
    bzero(&ci_ref,1*sizeof(City));
pCity ci = &ci_ref;
    {int index; index = (int)(sizeof ( Border )); }
    {void * tlv2; tlv2 = (void *)(sizeof ( Border )); }
    {cgc_size_t tlv1; tlv1 = (cgc_size_t)(sizeof ( Border )); }
    {void * tlv4; tlv4 = (void *)(sizeof ( Border )); }
    {cgc_size_t tlv3; tlv3 = (cgc_size_t)(sizeof ( Border )); }
}
void fix_ingred_cityParsers_2_3(){
fix_ingred_cityParsers_2_3_0();
fix_ingred_cityParsers_2_3_1();
}
void fix_ingred_cityParsers_2_4_0(){
City ci_ref;
    bzero(&ci_ref,1*sizeof(City));
pCity ci = &ci_ref;
    {int index; index = (int)(ci); }
    {void * tlv2; tlv2 = (void *)(ci); }
    {cgc_size_t tlv1; tlv1 = (cgc_size_t)(ci); }
    {void * tlv4; tlv4 = (void *)(ci); }
    {cgc_size_t tlv3; tlv3 = (cgc_size_t)(ci); }
}
void fix_ingred_cityParsers_2_4_1(){
City ci_ref;
    bzero(&ci_ref,1*sizeof(City));
pCity ci = &ci_ref;
    {int index; index = (int)(sizeof ( City )); }
    {void * tlv2; tlv2 = (void *)(sizeof ( City )); }
    {cgc_size_t tlv1; tlv1 = (cgc_size_t)(sizeof ( City )); }
    {void * tlv4; tlv4 = (void *)(sizeof ( City )); }
    {cgc_size_t tlv3; tlv3 = (cgc_size_t)(sizeof ( City )); }
}
void fix_ingred_cityParsers_2_4(){
fix_ingred_cityParsers_2_4_0();
fix_ingred_cityParsers_2_4_1();
}
void fix_ingred_cityParsers_2(){
fix_ingred_cityParsers_2_0();
fix_ingred_cityParsers_2_2();
fix_ingred_cityParsers_2_3();
fix_ingred_cityParsers_2_4();
}
void fix_ingred_cityParsers_3_2_5(){
    {int index; index = (int)(CITYBORDERMAX); }
}
void fix_ingred_cityParsers_3_2(){
fix_ingred_cityParsers_3_2_5();
}
void fix_ingred_cityParsers_3_3_5(){
    {int index; index = (int)(30); }
}
void fix_ingred_cityParsers_3_3(){
fix_ingred_cityParsers_3_3_5();
}
void fix_ingred_cityParsers_3(){
fix_ingred_cityParsers_3_2();
fix_ingred_cityParsers_3_3();
}
void fix_ingred_cityParsers_4(){
}
void fix_ingred_cityParsers_5_2_1(){
    {int tlv1; tlv1 = (int)('{'); }
    {int tlv2; tlv2 = (int)('{'); }
    {char tlv5; tlv5 = (char)('{'); }
    {int tlv3; tlv3 = (int)('{'); }
    {int tlv4; tlv4 = (int)('{'); }
    {char tlv8; tlv8 = (char)('{'); }
}
void fix_ingred_cityParsers_5_2(){
fix_ingred_cityParsers_5_2_1();
}
void fix_ingred_cityParsers_5_5_0(){
int tlv2;
    bzero(&tlv2,sizeof(int));
    {int tlv1; tlv1 = (int)(tlv2); }
    {char tlv5; tlv5 = (char)(tlv2); }
    {int tlv3; tlv3 = (int)(tlv2); }
    {int tlv4; tlv4 = (int)(tlv2); }
    {char tlv8; tlv8 = (char)(tlv2); }
}
void fix_ingred_cityParsers_5_5_1(){
int tlv2;
    bzero(&tlv2,sizeof(int));
    {int tlv1; tlv1 = (int)(- 1); }
    {int tlv2; tlv2 = (int)(- 1); }
    {char tlv5; tlv5 = (char)(- 1); }
    {int tlv3; tlv3 = (int)(- 1); }
    {int tlv4; tlv4 = (int)(- 1); }
    {char tlv8; tlv8 = (char)(- 1); }
}
void fix_ingred_cityParsers_5_5(){
fix_ingred_cityParsers_5_5_0();
fix_ingred_cityParsers_5_5_1();
}
void fix_ingred_cityParsers_5_7_1(){
    {int tlv1; tlv1 = (int)('#'); }
    {int tlv2; tlv2 = (int)('#'); }
    {char tlv5; tlv5 = (char)('#'); }
    {int tlv3; tlv3 = (int)('#'); }
    {int tlv4; tlv4 = (int)('#'); }
    {char tlv8; tlv8 = (char)('#'); }
}
void fix_ingred_cityParsers_5_7(){
fix_ingred_cityParsers_5_7_1();
}
void fix_ingred_cityParsers_5_10_0(){
int tlv4;
    bzero(&tlv4,sizeof(int));
    {int tlv1; tlv1 = (int)(tlv4); }
    {int tlv2; tlv2 = (int)(tlv4); }
    {char tlv5; tlv5 = (char)(tlv4); }
    {int tlv3; tlv3 = (int)(tlv4); }
    {char tlv8; tlv8 = (char)(tlv4); }
}
void fix_ingred_cityParsers_5_10(){
fix_ingred_cityParsers_5_10_0();
}
void fix_ingred_cityParsers_5(){
fix_ingred_cityParsers_5_2();
fix_ingred_cityParsers_5_5();
fix_ingred_cityParsers_5_7();
fix_ingred_cityParsers_5_10();
}
void fix_ingred_cityParsers_6_0_0(){
string str_ref;
    bzero(&str_ref,1*sizeof(string));
pstring str = &str_ref;
    {int lastGood; lastGood = (int)(0); }
    {int startIndex; startIndex = (int)(0); }
    {int endIndex; endIndex = (int)(0); }
    {char * temp; temp = (char *)(0); }
    {int tempInt; tempInt = (int)(0); }
    {int tlv2; tlv2 = (int)(0); }
    {int tlv3; tlv3 = (int)(0); }
    {int tlv4; tlv4 = (int)(0); }
    {int tlv5; tlv5 = (int)(0); }
    {int tlv6; tlv6 = (int)(0); }
    {int tlv7; tlv7 = (int)(0); }
    {int tlv16; tlv16 = (int)(0); }
    {int * tlv8; tlv8 = (int *)(0); }
    {int tlv20; tlv20 = (int)(0); }
    {int tlv19; tlv19 = (int)(0); }
    {int tlv27; tlv27 = (int)(0); }
    {int tlv30; tlv30 = (int)(0); }
    {int * tlv12; tlv12 = (int *)(0); }
    {int tlv34; tlv34 = (int)(0); }
    {int tlv33; tlv33 = (int)(0); }
    {void * tlv15; tlv15 = (void *)(0); }
    {cgc_size_t tlv14; tlv14 = (cgc_size_t)(0); }
    {char tlv38; tlv38 = (char)(0); }
    {char * tlv72; tlv72 = (char *)(0); }
    {char * tlv73; tlv73 = (char *)(0); }
    {void * tlv41; tlv41 = (void *)(0); }
    {char * tlv46; tlv46 = (char *)(0); }
    {void * tlv43; tlv43 = (void *)(0); }
    {cgc_size_t tlv42; tlv42 = (cgc_size_t)(0); }
    {char * tlv74; tlv74 = (char *)(0); }
    {char * tlv75; tlv75 = (char *)(0); }
    {char * tlv76; tlv76 = (char *)(0); }
    {void * tlv49; tlv49 = (void *)(0); }
    {cgc_size_t tlv48; tlv48 = (cgc_size_t)(0); }
    {char * tlv52; tlv52 = (char *)(0); }
    {char * tlv51; tlv51 = (char *)(0); }
    {void * tlv54; tlv54 = (void *)(0); }
    {cgc_size_t tlv53; tlv53 = (cgc_size_t)(0); }
    {void * tlv56; tlv56 = (void *)(0); }
    {cgc_size_t tlv55; tlv55 = (cgc_size_t)(0); }
    {char * tlv58; tlv58 = (char *)(0); }
    {char * tlv57; tlv57 = (char *)(0); }
    {void * tlv61; tlv61 = (void *)(0); }
    {cgc_size_t tlv60; tlv60 = (cgc_size_t)(0); }
    {char * tlv64; tlv64 = (char *)(0); }
    {char * tlv63; tlv63 = (char *)(0); }
    {cgc_size_t tlv62; tlv62 = (cgc_size_t)(0); }
    {char * tlv77; tlv77 = (char *)(0); }
}
void fix_ingred_cityParsers_6_0_4(){
string str_ref;
    bzero(&str_ref,1*sizeof(string));
pstring str = &str_ref;
    {int lastGood; lastGood = (int)(NULL); }
    {int startIndex; startIndex = (int)(NULL); }
    {int endIndex; endIndex = (int)(NULL); }
    {char * temp; temp = (char *)(NULL); }
    {int tempInt; tempInt = (int)(NULL); }
    {int tlv1; tlv1 = (int)(NULL); }
    {int tlv2; tlv2 = (int)(NULL); }
    {int tlv3; tlv3 = (int)(NULL); }
    {int tlv4; tlv4 = (int)(NULL); }
    {int tlv5; tlv5 = (int)(NULL); }
    {int tlv6; tlv6 = (int)(NULL); }
    {int tlv7; tlv7 = (int)(NULL); }
    {int tlv16; tlv16 = (int)(NULL); }
    {int * tlv8; tlv8 = (int *)(NULL); }
    {int tlv20; tlv20 = (int)(NULL); }
    {int tlv19; tlv19 = (int)(NULL); }
    {void * tlv11; tlv11 = (void *)(NULL); }
    {cgc_size_t tlv10; tlv10 = (cgc_size_t)(NULL); }
    {char tlv24; tlv24 = (char)(NULL); }
    {cgc_size_t tlv28; tlv28 = (cgc_size_t)(NULL); }
    {int tlv27; tlv27 = (int)(NULL); }
    {int tlv30; tlv30 = (int)(NULL); }
    {int * tlv12; tlv12 = (int *)(NULL); }
    {int tlv34; tlv34 = (int)(NULL); }
    {int tlv33; tlv33 = (int)(NULL); }
    {void * tlv15; tlv15 = (void *)(NULL); }
    {cgc_size_t tlv14; tlv14 = (cgc_size_t)(NULL); }
    {char tlv38; tlv38 = (char)(NULL); }
    {char * tlv72; tlv72 = (char *)(NULL); }
    {char * tlv73; tlv73 = (char *)(NULL); }
    {void * tlv41; tlv41 = (void *)(NULL); }
    {cgc_size_t tlv40; tlv40 = (cgc_size_t)(NULL); }
    {char * tlv46; tlv46 = (char *)(NULL); }
    {void * tlv43; tlv43 = (void *)(NULL); }
    {cgc_size_t tlv42; tlv42 = (cgc_size_t)(NULL); }
    {void * tlv45; tlv45 = (void *)(NULL); }
    {cgc_size_t tlv44; tlv44 = (cgc_size_t)(NULL); }
    {char * tlv74; tlv74 = (char *)(NULL); }
    {char * tlv75; tlv75 = (char *)(NULL); }
    {char * tlv76; tlv76 = (char *)(NULL); }
    {void * tlv49; tlv49 = (void *)(NULL); }
    {cgc_size_t tlv48; tlv48 = (cgc_size_t)(NULL); }
    {char * tlv52; tlv52 = (char *)(NULL); }
    {char * tlv51; tlv51 = (char *)(NULL); }
    {cgc_size_t tlv50; tlv50 = (cgc_size_t)(NULL); }
    {void * tlv54; tlv54 = (void *)(NULL); }
    {cgc_size_t tlv53; tlv53 = (cgc_size_t)(NULL); }
    {void * tlv56; tlv56 = (void *)(NULL); }
    {cgc_size_t tlv55; tlv55 = (cgc_size_t)(NULL); }
    {char * tlv58; tlv58 = (char *)(NULL); }
    {char * tlv57; tlv57 = (char *)(NULL); }
    {void * tlv61; tlv61 = (void *)(NULL); }
    {cgc_size_t tlv60; tlv60 = (cgc_size_t)(NULL); }
    {char * tlv64; tlv64 = (char *)(NULL); }
    {char * tlv63; tlv63 = (char *)(NULL); }
    {cgc_size_t tlv62; tlv62 = (cgc_size_t)(NULL); }
    {char * tlv77; tlv77 = (char *)(NULL); }
}
void fix_ingred_cityParsers_6_0_6(){
string str_ref;
    bzero(&str_ref,1*sizeof(string));
pstring str = &str_ref;
    {int lastGood; lastGood = (int)(str -> index); }
    {int startIndex; startIndex = (int)(str -> index); }
    {int endIndex; endIndex = (int)(str -> index); }
    {char * temp; temp = (char *)(str -> index); }
    {int tempInt; tempInt = (int)(str -> index); }
    {int tlv1; tlv1 = (int)(str -> index); }
    {int tlv2; tlv2 = (int)(str -> index); }
    {int tlv3; tlv3 = (int)(str -> index); }
    {int tlv4; tlv4 = (int)(str -> index); }
    {int tlv5; tlv5 = (int)(str -> index); }
    {int tlv6; tlv6 = (int)(str -> index); }
    {int tlv7; tlv7 = (int)(str -> index); }
    {int tlv16; tlv16 = (int)(str -> index); }
    {int * tlv8; tlv8 = (int *)(str -> index); }
    {int tlv20; tlv20 = (int)(str -> index); }
    {int tlv19; tlv19 = (int)(str -> index); }
    {void * tlv11; tlv11 = (void *)(str -> index); }
    {cgc_size_t tlv10; tlv10 = (cgc_size_t)(str -> index); }
    {char tlv24; tlv24 = (char)(str -> index); }
    {cgc_size_t tlv28; tlv28 = (cgc_size_t)(str -> index); }
    {int tlv27; tlv27 = (int)(str -> index); }
    {int tlv30; tlv30 = (int)(str -> index); }
    {int * tlv12; tlv12 = (int *)(str -> index); }
    {int tlv34; tlv34 = (int)(str -> index); }
    {int tlv33; tlv33 = (int)(str -> index); }
    {void * tlv15; tlv15 = (void *)(str -> index); }
    {cgc_size_t tlv14; tlv14 = (cgc_size_t)(str -> index); }
    {char tlv38; tlv38 = (char)(str -> index); }
    {char * tlv72; tlv72 = (char *)(str -> index); }
    {char * tlv73; tlv73 = (char *)(str -> index); }
    {void * tlv41; tlv41 = (void *)(str -> index); }
    {cgc_size_t tlv40; tlv40 = (cgc_size_t)(str -> index); }
    {char * tlv46; tlv46 = (char *)(str -> index); }
    {void * tlv43; tlv43 = (void *)(str -> index); }
    {cgc_size_t tlv42; tlv42 = (cgc_size_t)(str -> index); }
    {void * tlv45; tlv45 = (void *)(str -> index); }
    {cgc_size_t tlv44; tlv44 = (cgc_size_t)(str -> index); }
    {char * tlv74; tlv74 = (char *)(str -> index); }
    {char * tlv75; tlv75 = (char *)(str -> index); }
    {char * tlv76; tlv76 = (char *)(str -> index); }
    {void * tlv49; tlv49 = (void *)(str -> index); }
    {cgc_size_t tlv48; tlv48 = (cgc_size_t)(str -> index); }
    {char * tlv52; tlv52 = (char *)(str -> index); }
    {char * tlv51; tlv51 = (char *)(str -> index); }
    {cgc_size_t tlv50; tlv50 = (cgc_size_t)(str -> index); }
    {void * tlv54; tlv54 = (void *)(str -> index); }
    {cgc_size_t tlv53; tlv53 = (cgc_size_t)(str -> index); }
    {void * tlv56; tlv56 = (void *)(str -> index); }
    {cgc_size_t tlv55; tlv55 = (cgc_size_t)(str -> index); }
    {char * tlv58; tlv58 = (char *)(str -> index); }
    {char * tlv57; tlv57 = (char *)(str -> index); }
    {void * tlv61; tlv61 = (void *)(str -> index); }
    {cgc_size_t tlv60; tlv60 = (cgc_size_t)(str -> index); }
    {char * tlv64; tlv64 = (char *)(str -> index); }
    {char * tlv63; tlv63 = (char *)(str -> index); }
    {cgc_size_t tlv62; tlv62 = (cgc_size_t)(str -> index); }
    {char * tlv77; tlv77 = (char *)(str -> index); }
}
void fix_ingred_cityParsers_6_0(){
fix_ingred_cityParsers_6_0_0();
fix_ingred_cityParsers_6_0_4();
fix_ingred_cityParsers_6_0_6();
}
void fix_ingred_cityParsers_6_3_6(){
int tlv1;
    bzero(&tlv1,sizeof(int));
    {int lastGood; lastGood = (int)(tlv1); }
    {int startIndex; startIndex = (int)(tlv1); }
    {int endIndex; endIndex = (int)(tlv1); }
    {char * temp; temp = (char *)(tlv1); }
    {int tempInt; tempInt = (int)(tlv1); }
    {int tlv2; tlv2 = (int)(tlv1); }
    {int tlv3; tlv3 = (int)(tlv1); }
    {int tlv4; tlv4 = (int)(tlv1); }
    {int tlv5; tlv5 = (int)(tlv1); }
    {int tlv6; tlv6 = (int)(tlv1); }
    {int tlv7; tlv7 = (int)(tlv1); }
    {int tlv16; tlv16 = (int)(tlv1); }
    {int * tlv8; tlv8 = (int *)(tlv1); }
    {int tlv20; tlv20 = (int)(tlv1); }
    {int tlv19; tlv19 = (int)(tlv1); }
    {int tlv27; tlv27 = (int)(tlv1); }
    {int tlv30; tlv30 = (int)(tlv1); }
    {int * tlv12; tlv12 = (int *)(tlv1); }
    {int tlv34; tlv34 = (int)(tlv1); }
    {int tlv33; tlv33 = (int)(tlv1); }
    {void * tlv15; tlv15 = (void *)(tlv1); }
    {cgc_size_t tlv14; tlv14 = (cgc_size_t)(tlv1); }
    {char tlv38; tlv38 = (char)(tlv1); }
    {char * tlv72; tlv72 = (char *)(tlv1); }
    {char * tlv73; tlv73 = (char *)(tlv1); }
    {void * tlv41; tlv41 = (void *)(tlv1); }
    {char * tlv46; tlv46 = (char *)(tlv1); }
    {void * tlv43; tlv43 = (void *)(tlv1); }
    {cgc_size_t tlv42; tlv42 = (cgc_size_t)(tlv1); }
    {char * tlv74; tlv74 = (char *)(tlv1); }
    {char * tlv75; tlv75 = (char *)(tlv1); }
    {char * tlv76; tlv76 = (char *)(tlv1); }
    {void * tlv49; tlv49 = (void *)(tlv1); }
    {cgc_size_t tlv48; tlv48 = (cgc_size_t)(tlv1); }
    {char * tlv52; tlv52 = (char *)(tlv1); }
    {char * tlv51; tlv51 = (char *)(tlv1); }
    {void * tlv54; tlv54 = (void *)(tlv1); }
    {cgc_size_t tlv53; tlv53 = (cgc_size_t)(tlv1); }
    {void * tlv56; tlv56 = (void *)(tlv1); }
    {cgc_size_t tlv55; tlv55 = (cgc_size_t)(tlv1); }
    {char * tlv58; tlv58 = (char *)(tlv1); }
    {char * tlv57; tlv57 = (char *)(tlv1); }
    {void * tlv61; tlv61 = (void *)(tlv1); }
    {cgc_size_t tlv60; tlv60 = (cgc_size_t)(tlv1); }
    {char * tlv64; tlv64 = (char *)(tlv1); }
    {char * tlv63; tlv63 = (char *)(tlv1); }
    {cgc_size_t tlv62; tlv62 = (cgc_size_t)(tlv1); }
    {char * tlv77; tlv77 = (char *)(tlv1); }
}
void fix_ingred_cityParsers_6_3(){
fix_ingred_cityParsers_6_3_6();
}
void fix_ingred_cityParsers_6_4_1(){
int startIndex;
    bzero(&startIndex,sizeof(int));
    {int lastGood; lastGood = (int)(& startIndex); }
    {int endIndex; endIndex = (int)(& startIndex); }
    {char * temp; temp = (char *)(& startIndex); }
    {int tempInt; tempInt = (int)(& startIndex); }
    {int tlv1; tlv1 = (int)(& startIndex); }
    {int tlv2; tlv2 = (int)(& startIndex); }
    {int tlv3; tlv3 = (int)(& startIndex); }
    {int tlv4; tlv4 = (int)(& startIndex); }
    {int tlv5; tlv5 = (int)(& startIndex); }
    {int tlv6; tlv6 = (int)(& startIndex); }
    {int tlv7; tlv7 = (int)(& startIndex); }
    {int tlv16; tlv16 = (int)(& startIndex); }
    {int * tlv8; tlv8 = (int *)(& startIndex); }
    {int tlv20; tlv20 = (int)(& startIndex); }
    {int tlv19; tlv19 = (int)(& startIndex); }
    {void * tlv11; tlv11 = (void *)(& startIndex); }
    {cgc_size_t tlv10; tlv10 = (cgc_size_t)(& startIndex); }
    {char tlv24; tlv24 = (char)(& startIndex); }
    {cgc_size_t tlv28; tlv28 = (cgc_size_t)(& startIndex); }
    {int tlv27; tlv27 = (int)(& startIndex); }
    {int tlv30; tlv30 = (int)(& startIndex); }
    {int * tlv12; tlv12 = (int *)(& startIndex); }
    {int tlv34; tlv34 = (int)(& startIndex); }
    {int tlv33; tlv33 = (int)(& startIndex); }
    {void * tlv15; tlv15 = (void *)(& startIndex); }
    {cgc_size_t tlv14; tlv14 = (cgc_size_t)(& startIndex); }
    {char tlv38; tlv38 = (char)(& startIndex); }
    {char * tlv72; tlv72 = (char *)(& startIndex); }
    {char * tlv73; tlv73 = (char *)(& startIndex); }
    {void * tlv41; tlv41 = (void *)(& startIndex); }
    {cgc_size_t tlv40; tlv40 = (cgc_size_t)(& startIndex); }
    {char * tlv46; tlv46 = (char *)(& startIndex); }
    {void * tlv43; tlv43 = (void *)(& startIndex); }
    {cgc_size_t tlv42; tlv42 = (cgc_size_t)(& startIndex); }
    {void * tlv45; tlv45 = (void *)(& startIndex); }
    {cgc_size_t tlv44; tlv44 = (cgc_size_t)(& startIndex); }
    {char * tlv74; tlv74 = (char *)(& startIndex); }
    {char * tlv75; tlv75 = (char *)(& startIndex); }
    {char * tlv76; tlv76 = (char *)(& startIndex); }
    {void * tlv49; tlv49 = (void *)(& startIndex); }
    {cgc_size_t tlv48; tlv48 = (cgc_size_t)(& startIndex); }
    {char * tlv52; tlv52 = (char *)(& startIndex); }
    {char * tlv51; tlv51 = (char *)(& startIndex); }
    {cgc_size_t tlv50; tlv50 = (cgc_size_t)(& startIndex); }
    {void * tlv54; tlv54 = (void *)(& startIndex); }
    {cgc_size_t tlv53; tlv53 = (cgc_size_t)(& startIndex); }
    {void * tlv56; tlv56 = (void *)(& startIndex); }
    {cgc_size_t tlv55; tlv55 = (cgc_size_t)(& startIndex); }
    {char * tlv58; tlv58 = (char *)(& startIndex); }
    {char * tlv57; tlv57 = (char *)(& startIndex); }
    {void * tlv61; tlv61 = (void *)(& startIndex); }
    {cgc_size_t tlv60; tlv60 = (cgc_size_t)(& startIndex); }
    {char * tlv64; tlv64 = (char *)(& startIndex); }
    {char * tlv63; tlv63 = (char *)(& startIndex); }
    {cgc_size_t tlv62; tlv62 = (cgc_size_t)(& startIndex); }
    {char * tlv77; tlv77 = (char *)(& startIndex); }
}
void fix_ingred_cityParsers_6_4(){
fix_ingred_cityParsers_6_4_1();
}
void fix_ingred_cityParsers_6_6_6(){
int endIndex;
    bzero(&endIndex,sizeof(int));
    {int lastGood; lastGood = (int)(endIndex); }
    {int startIndex; startIndex = (int)(endIndex); }
    {char * temp; temp = (char *)(endIndex); }
    {int tempInt; tempInt = (int)(endIndex); }
    {int tlv1; tlv1 = (int)(endIndex); }
    {int tlv2; tlv2 = (int)(endIndex); }
    {int tlv3; tlv3 = (int)(endIndex); }
    {int tlv4; tlv4 = (int)(endIndex); }
    {int tlv5; tlv5 = (int)(endIndex); }
    {int tlv6; tlv6 = (int)(endIndex); }
    {int tlv7; tlv7 = (int)(endIndex); }
    {int tlv16; tlv16 = (int)(endIndex); }
    {int * tlv8; tlv8 = (int *)(endIndex); }
    {int tlv20; tlv20 = (int)(endIndex); }
    {int tlv19; tlv19 = (int)(endIndex); }
    {void * tlv11; tlv11 = (void *)(endIndex); }
    {cgc_size_t tlv10; tlv10 = (cgc_size_t)(endIndex); }
    {char tlv24; tlv24 = (char)(endIndex); }
    {cgc_size_t tlv28; tlv28 = (cgc_size_t)(endIndex); }
    {int tlv27; tlv27 = (int)(endIndex); }
    {int tlv30; tlv30 = (int)(endIndex); }
    {int * tlv12; tlv12 = (int *)(endIndex); }
    {int tlv34; tlv34 = (int)(endIndex); }
    {int tlv33; tlv33 = (int)(endIndex); }
    {void * tlv15; tlv15 = (void *)(endIndex); }
    {cgc_size_t tlv14; tlv14 = (cgc_size_t)(endIndex); }
    {char tlv38; tlv38 = (char)(endIndex); }
    {char * tlv72; tlv72 = (char *)(endIndex); }
    {char * tlv73; tlv73 = (char *)(endIndex); }
    {void * tlv41; tlv41 = (void *)(endIndex); }
    {cgc_size_t tlv40; tlv40 = (cgc_size_t)(endIndex); }
    {char * tlv46; tlv46 = (char *)(endIndex); }
    {void * tlv43; tlv43 = (void *)(endIndex); }
    {cgc_size_t tlv42; tlv42 = (cgc_size_t)(endIndex); }
    {void * tlv45; tlv45 = (void *)(endIndex); }
    {cgc_size_t tlv44; tlv44 = (cgc_size_t)(endIndex); }
    {char * tlv74; tlv74 = (char *)(endIndex); }
    {char * tlv75; tlv75 = (char *)(endIndex); }
    {char * tlv76; tlv76 = (char *)(endIndex); }
    {void * tlv49; tlv49 = (void *)(endIndex); }
    {cgc_size_t tlv48; tlv48 = (cgc_size_t)(endIndex); }
    {char * tlv52; tlv52 = (char *)(endIndex); }
    {char * tlv51; tlv51 = (char *)(endIndex); }
    {cgc_size_t tlv50; tlv50 = (cgc_size_t)(endIndex); }
    {void * tlv54; tlv54 = (void *)(endIndex); }
    {cgc_size_t tlv53; tlv53 = (cgc_size_t)(endIndex); }
    {void * tlv56; tlv56 = (void *)(endIndex); }
    {cgc_size_t tlv55; tlv55 = (cgc_size_t)(endIndex); }
    {char * tlv58; tlv58 = (char *)(endIndex); }
    {char * tlv57; tlv57 = (char *)(endIndex); }
    {void * tlv61; tlv61 = (void *)(endIndex); }
    {cgc_size_t tlv60; tlv60 = (cgc_size_t)(endIndex); }
    {char * tlv64; tlv64 = (char *)(endIndex); }
    {char * tlv63; tlv63 = (char *)(endIndex); }
    {cgc_size_t tlv62; tlv62 = (cgc_size_t)(endIndex); }
    {char * tlv77; tlv77 = (char *)(endIndex); }
}
void fix_ingred_cityParsers_6_6_7(){
int endIndex;
    bzero(&endIndex,sizeof(int));
    {int lastGood; lastGood = (int)(- 1); }
    {int startIndex; startIndex = (int)(- 1); }
    {int endIndex; endIndex = (int)(- 1); }
    {char * temp; temp = (char *)(- 1); }
    {int tempInt; tempInt = (int)(- 1); }
    {int tlv5; tlv5 = (int)(- 1); }
    {int tlv6; tlv6 = (int)(- 1); }
    {int tlv7; tlv7 = (int)(- 1); }
    {int tlv16; tlv16 = (int)(- 1); }
    {int * tlv8; tlv8 = (int *)(- 1); }
    {int tlv20; tlv20 = (int)(- 1); }
    {int tlv19; tlv19 = (int)(- 1); }
    {void * tlv11; tlv11 = (void *)(- 1); }
    {cgc_size_t tlv10; tlv10 = (cgc_size_t)(- 1); }
    {char tlv24; tlv24 = (char)(- 1); }
    {cgc_size_t tlv28; tlv28 = (cgc_size_t)(- 1); }
    {int tlv27; tlv27 = (int)(- 1); }
    {int tlv30; tlv30 = (int)(- 1); }
    {int * tlv12; tlv12 = (int *)(- 1); }
    {int tlv34; tlv34 = (int)(- 1); }
    {int tlv33; tlv33 = (int)(- 1); }
    {void * tlv15; tlv15 = (void *)(- 1); }
    {cgc_size_t tlv14; tlv14 = (cgc_size_t)(- 1); }
    {char tlv38; tlv38 = (char)(- 1); }
    {char * tlv72; tlv72 = (char *)(- 1); }
    {char * tlv73; tlv73 = (char *)(- 1); }
    {void * tlv41; tlv41 = (void *)(- 1); }
    {cgc_size_t tlv40; tlv40 = (cgc_size_t)(- 1); }
    {char * tlv46; tlv46 = (char *)(- 1); }
    {void * tlv43; tlv43 = (void *)(- 1); }
    {cgc_size_t tlv42; tlv42 = (cgc_size_t)(- 1); }
    {void * tlv45; tlv45 = (void *)(- 1); }
    {cgc_size_t tlv44; tlv44 = (cgc_size_t)(- 1); }
    {char * tlv74; tlv74 = (char *)(- 1); }
    {char * tlv75; tlv75 = (char *)(- 1); }
    {char * tlv76; tlv76 = (char *)(- 1); }
    {void * tlv49; tlv49 = (void *)(- 1); }
    {cgc_size_t tlv48; tlv48 = (cgc_size_t)(- 1); }
    {char * tlv52; tlv52 = (char *)(- 1); }
    {char * tlv51; tlv51 = (char *)(- 1); }
    {cgc_size_t tlv50; tlv50 = (cgc_size_t)(- 1); }
    {void * tlv54; tlv54 = (void *)(- 1); }
    {cgc_size_t tlv53; tlv53 = (cgc_size_t)(- 1); }
    {void * tlv56; tlv56 = (void *)(- 1); }
    {cgc_size_t tlv55; tlv55 = (cgc_size_t)(- 1); }
    {char * tlv58; tlv58 = (char *)(- 1); }
    {char * tlv57; tlv57 = (char *)(- 1); }
    {void * tlv61; tlv61 = (void *)(- 1); }
    {cgc_size_t tlv60; tlv60 = (cgc_size_t)(- 1); }
    {char * tlv64; tlv64 = (char *)(- 1); }
    {char * tlv63; tlv63 = (char *)(- 1); }
    {cgc_size_t tlv62; tlv62 = (cgc_size_t)(- 1); }
    {char * tlv77; tlv77 = (char *)(- 1); }
}
void fix_ingred_cityParsers_6_6(){
fix_ingred_cityParsers_6_6_6();
fix_ingred_cityParsers_6_6_7();
}
void fix_ingred_cityParsers_6_7_6(){
int startIndex;
    bzero(&startIndex,sizeof(int));
    {int lastGood; lastGood = (int)(startIndex); }
    {int endIndex; endIndex = (int)(startIndex); }
    {char * temp; temp = (char *)(startIndex); }
    {int tempInt; tempInt = (int)(startIndex); }
    {int tlv1; tlv1 = (int)(startIndex); }
    {int tlv2; tlv2 = (int)(startIndex); }
    {int tlv3; tlv3 = (int)(startIndex); }
    {int tlv4; tlv4 = (int)(startIndex); }
    {int tlv5; tlv5 = (int)(startIndex); }
    {int tlv6; tlv6 = (int)(startIndex); }
    {int tlv7; tlv7 = (int)(startIndex); }
    {int tlv16; tlv16 = (int)(startIndex); }
    {int * tlv8; tlv8 = (int *)(startIndex); }
    {int tlv20; tlv20 = (int)(startIndex); }
    {int tlv19; tlv19 = (int)(startIndex); }
    {void * tlv11; tlv11 = (void *)(startIndex); }
    {cgc_size_t tlv10; tlv10 = (cgc_size_t)(startIndex); }
    {char tlv24; tlv24 = (char)(startIndex); }
    {cgc_size_t tlv28; tlv28 = (cgc_size_t)(startIndex); }
    {int tlv27; tlv27 = (int)(startIndex); }
    {int tlv30; tlv30 = (int)(startIndex); }
    {int * tlv12; tlv12 = (int *)(startIndex); }
    {int tlv34; tlv34 = (int)(startIndex); }
    {int tlv33; tlv33 = (int)(startIndex); }
    {void * tlv15; tlv15 = (void *)(startIndex); }
    {cgc_size_t tlv14; tlv14 = (cgc_size_t)(startIndex); }
    {char tlv38; tlv38 = (char)(startIndex); }
    {char * tlv72; tlv72 = (char *)(startIndex); }
    {char * tlv73; tlv73 = (char *)(startIndex); }
    {void * tlv41; tlv41 = (void *)(startIndex); }
    {cgc_size_t tlv40; tlv40 = (cgc_size_t)(startIndex); }
    {char * tlv46; tlv46 = (char *)(startIndex); }
    {void * tlv43; tlv43 = (void *)(startIndex); }
    {cgc_size_t tlv42; tlv42 = (cgc_size_t)(startIndex); }
    {void * tlv45; tlv45 = (void *)(startIndex); }
    {cgc_size_t tlv44; tlv44 = (cgc_size_t)(startIndex); }
    {char * tlv74; tlv74 = (char *)(startIndex); }
    {char * tlv75; tlv75 = (char *)(startIndex); }
    {char * tlv76; tlv76 = (char *)(startIndex); }
    {void * tlv49; tlv49 = (void *)(startIndex); }
    {cgc_size_t tlv48; tlv48 = (cgc_size_t)(startIndex); }
    {char * tlv52; tlv52 = (char *)(startIndex); }
    {char * tlv51; tlv51 = (char *)(startIndex); }
    {cgc_size_t tlv50; tlv50 = (cgc_size_t)(startIndex); }
    {void * tlv54; tlv54 = (void *)(startIndex); }
    {cgc_size_t tlv53; tlv53 = (cgc_size_t)(startIndex); }
    {void * tlv56; tlv56 = (void *)(startIndex); }
    {cgc_size_t tlv55; tlv55 = (cgc_size_t)(startIndex); }
    {char * tlv58; tlv58 = (char *)(startIndex); }
    {char * tlv57; tlv57 = (char *)(startIndex); }
    {void * tlv61; tlv61 = (void *)(startIndex); }
    {cgc_size_t tlv60; tlv60 = (cgc_size_t)(startIndex); }
    {char * tlv64; tlv64 = (char *)(startIndex); }
    {char * tlv63; tlv63 = (char *)(startIndex); }
    {cgc_size_t tlv62; tlv62 = (cgc_size_t)(startIndex); }
    {char * tlv77; tlv77 = (char *)(startIndex); }
}
void fix_ingred_cityParsers_6_7(){
fix_ingred_cityParsers_6_7_6();
}
void fix_ingred_cityParsers_6_9_6(){
char temp_ref;
    bzero(&temp_ref,1*sizeof(char));
char * temp = &temp_ref;
    {int lastGood; lastGood = (int)(temp); }
    {int startIndex; startIndex = (int)(temp); }
    {int endIndex; endIndex = (int)(temp); }
    {int tempInt; tempInt = (int)(temp); }
    {int tlv1; tlv1 = (int)(temp); }
    {int tlv2; tlv2 = (int)(temp); }
    {int tlv3; tlv3 = (int)(temp); }
    {int tlv4; tlv4 = (int)(temp); }
    {int tlv5; tlv5 = (int)(temp); }
    {int tlv6; tlv6 = (int)(temp); }
    {int tlv7; tlv7 = (int)(temp); }
    {int tlv16; tlv16 = (int)(temp); }
    {int * tlv8; tlv8 = (int *)(temp); }
    {int tlv20; tlv20 = (int)(temp); }
    {int tlv19; tlv19 = (int)(temp); }
    {void * tlv11; tlv11 = (void *)(temp); }
    {cgc_size_t tlv10; tlv10 = (cgc_size_t)(temp); }
    {char tlv24; tlv24 = (char)(temp); }
    {cgc_size_t tlv28; tlv28 = (cgc_size_t)(temp); }
    {int tlv27; tlv27 = (int)(temp); }
    {int tlv30; tlv30 = (int)(temp); }
    {int * tlv12; tlv12 = (int *)(temp); }
    {int tlv34; tlv34 = (int)(temp); }
    {int tlv33; tlv33 = (int)(temp); }
    {void * tlv15; tlv15 = (void *)(temp); }
    {cgc_size_t tlv14; tlv14 = (cgc_size_t)(temp); }
    {char tlv38; tlv38 = (char)(temp); }
    {char * tlv72; tlv72 = (char *)(temp); }
    {char * tlv73; tlv73 = (char *)(temp); }
    {void * tlv41; tlv41 = (void *)(temp); }
    {cgc_size_t tlv40; tlv40 = (cgc_size_t)(temp); }
    {char * tlv46; tlv46 = (char *)(temp); }
    {void * tlv43; tlv43 = (void *)(temp); }
    {cgc_size_t tlv42; tlv42 = (cgc_size_t)(temp); }
    {void * tlv45; tlv45 = (void *)(temp); }
    {cgc_size_t tlv44; tlv44 = (cgc_size_t)(temp); }
    {char * tlv74; tlv74 = (char *)(temp); }
    {char * tlv75; tlv75 = (char *)(temp); }
    {char * tlv76; tlv76 = (char *)(temp); }
    {void * tlv49; tlv49 = (void *)(temp); }
    {cgc_size_t tlv48; tlv48 = (cgc_size_t)(temp); }
    {char * tlv52; tlv52 = (char *)(temp); }
    {char * tlv51; tlv51 = (char *)(temp); }
    {cgc_size_t tlv50; tlv50 = (cgc_size_t)(temp); }
    {void * tlv54; tlv54 = (void *)(temp); }
    {cgc_size_t tlv53; tlv53 = (cgc_size_t)(temp); }
    {void * tlv56; tlv56 = (void *)(temp); }
    {cgc_size_t tlv55; tlv55 = (cgc_size_t)(temp); }
    {char * tlv58; tlv58 = (char *)(temp); }
    {char * tlv57; tlv57 = (char *)(temp); }
    {void * tlv61; tlv61 = (void *)(temp); }
    {cgc_size_t tlv60; tlv60 = (cgc_size_t)(temp); }
    {char * tlv64; tlv64 = (char *)(temp); }
    {char * tlv63; tlv63 = (char *)(temp); }
    {cgc_size_t tlv62; tlv62 = (cgc_size_t)(temp); }
    {char * tlv77; tlv77 = (char *)(temp); }
}
void fix_ingred_cityParsers_6_9(){
fix_ingred_cityParsers_6_9_6();
}
void fix_ingred_cityParsers_6_11_6(){
int tlv2;
    bzero(&tlv2,sizeof(int));
    {int lastGood; lastGood = (int)(tlv2); }
    {int startIndex; startIndex = (int)(tlv2); }
    {int endIndex; endIndex = (int)(tlv2); }
    {char * temp; temp = (char *)(tlv2); }
    {int tempInt; tempInt = (int)(tlv2); }
    {int tlv5; tlv5 = (int)(tlv2); }
    {int tlv6; tlv6 = (int)(tlv2); }
    {int tlv7; tlv7 = (int)(tlv2); }
    {int tlv16; tlv16 = (int)(tlv2); }
    {int * tlv8; tlv8 = (int *)(tlv2); }
    {int tlv20; tlv20 = (int)(tlv2); }
    {int tlv19; tlv19 = (int)(tlv2); }
    {void * tlv11; tlv11 = (void *)(tlv2); }
    {cgc_size_t tlv10; tlv10 = (cgc_size_t)(tlv2); }
    {char tlv24; tlv24 = (char)(tlv2); }
    {cgc_size_t tlv28; tlv28 = (cgc_size_t)(tlv2); }
    {int tlv27; tlv27 = (int)(tlv2); }
    {int tlv30; tlv30 = (int)(tlv2); }
    {int * tlv12; tlv12 = (int *)(tlv2); }
    {int tlv34; tlv34 = (int)(tlv2); }
    {int tlv33; tlv33 = (int)(tlv2); }
    {void * tlv15; tlv15 = (void *)(tlv2); }
    {cgc_size_t tlv14; tlv14 = (cgc_size_t)(tlv2); }
    {char tlv38; tlv38 = (char)(tlv2); }
    {char * tlv72; tlv72 = (char *)(tlv2); }
    {char * tlv73; tlv73 = (char *)(tlv2); }
    {void * tlv41; tlv41 = (void *)(tlv2); }
    {cgc_size_t tlv40; tlv40 = (cgc_size_t)(tlv2); }
    {char * tlv46; tlv46 = (char *)(tlv2); }
    {void * tlv43; tlv43 = (void *)(tlv2); }
    {cgc_size_t tlv42; tlv42 = (cgc_size_t)(tlv2); }
    {void * tlv45; tlv45 = (void *)(tlv2); }
    {cgc_size_t tlv44; tlv44 = (cgc_size_t)(tlv2); }
    {char * tlv74; tlv74 = (char *)(tlv2); }
    {char * tlv75; tlv75 = (char *)(tlv2); }
    {char * tlv76; tlv76 = (char *)(tlv2); }
    {void * tlv49; tlv49 = (void *)(tlv2); }
    {cgc_size_t tlv48; tlv48 = (cgc_size_t)(tlv2); }
    {char * tlv52; tlv52 = (char *)(tlv2); }
    {char * tlv51; tlv51 = (char *)(tlv2); }
    {cgc_size_t tlv50; tlv50 = (cgc_size_t)(tlv2); }
    {void * tlv54; tlv54 = (void *)(tlv2); }
    {cgc_size_t tlv53; tlv53 = (cgc_size_t)(tlv2); }
    {void * tlv56; tlv56 = (void *)(tlv2); }
    {cgc_size_t tlv55; tlv55 = (cgc_size_t)(tlv2); }
    {char * tlv58; tlv58 = (char *)(tlv2); }
    {char * tlv57; tlv57 = (char *)(tlv2); }
    {void * tlv61; tlv61 = (void *)(tlv2); }
    {cgc_size_t tlv60; tlv60 = (cgc_size_t)(tlv2); }
    {char * tlv64; tlv64 = (char *)(tlv2); }
    {char * tlv63; tlv63 = (char *)(tlv2); }
    {cgc_size_t tlv62; tlv62 = (cgc_size_t)(tlv2); }
    {char * tlv77; tlv77 = (char *)(tlv2); }
}
void fix_ingred_cityParsers_6_11(){
fix_ingred_cityParsers_6_11_6();
}
void fix_ingred_cityParsers_6_12_0(){
char temp_ref;
    bzero(&temp_ref,1*sizeof(char));
char * temp = &temp_ref;
    {int lastGood; lastGood = (int)(temp); }
    {int startIndex; startIndex = (int)(temp); }
    {int endIndex; endIndex = (int)(temp); }
    {int tempInt; tempInt = (int)(temp); }
    {int tlv1; tlv1 = (int)(temp); }
    {int tlv2; tlv2 = (int)(temp); }
    {int tlv3; tlv3 = (int)(temp); }
    {int tlv4; tlv4 = (int)(temp); }
    {int tlv5; tlv5 = (int)(temp); }
    {int tlv6; tlv6 = (int)(temp); }
    {int tlv7; tlv7 = (int)(temp); }
    {int tlv16; tlv16 = (int)(temp); }
    {int * tlv8; tlv8 = (int *)(temp); }
    {int tlv20; tlv20 = (int)(temp); }
    {int tlv19; tlv19 = (int)(temp); }
    {void * tlv11; tlv11 = (void *)(temp); }
    {cgc_size_t tlv10; tlv10 = (cgc_size_t)(temp); }
    {char tlv24; tlv24 = (char)(temp); }
    {cgc_size_t tlv28; tlv28 = (cgc_size_t)(temp); }
    {int tlv27; tlv27 = (int)(temp); }
    {int tlv30; tlv30 = (int)(temp); }
    {int * tlv12; tlv12 = (int *)(temp); }
    {int tlv34; tlv34 = (int)(temp); }
    {int tlv33; tlv33 = (int)(temp); }
    {void * tlv15; tlv15 = (void *)(temp); }
    {cgc_size_t tlv14; tlv14 = (cgc_size_t)(temp); }
    {char tlv38; tlv38 = (char)(temp); }
    {char * tlv72; tlv72 = (char *)(temp); }
    {char * tlv73; tlv73 = (char *)(temp); }
    {void * tlv41; tlv41 = (void *)(temp); }
    {cgc_size_t tlv40; tlv40 = (cgc_size_t)(temp); }
    {char * tlv46; tlv46 = (char *)(temp); }
    {void * tlv43; tlv43 = (void *)(temp); }
    {cgc_size_t tlv42; tlv42 = (cgc_size_t)(temp); }
    {void * tlv45; tlv45 = (void *)(temp); }
    {cgc_size_t tlv44; tlv44 = (cgc_size_t)(temp); }
    {char * tlv74; tlv74 = (char *)(temp); }
    {char * tlv75; tlv75 = (char *)(temp); }
    {char * tlv76; tlv76 = (char *)(temp); }
    {void * tlv49; tlv49 = (void *)(temp); }
    {cgc_size_t tlv48; tlv48 = (cgc_size_t)(temp); }
    {char * tlv52; tlv52 = (char *)(temp); }
    {char * tlv51; tlv51 = (char *)(temp); }
    {cgc_size_t tlv50; tlv50 = (cgc_size_t)(temp); }
    {void * tlv54; tlv54 = (void *)(temp); }
    {cgc_size_t tlv53; tlv53 = (cgc_size_t)(temp); }
    {void * tlv56; tlv56 = (void *)(temp); }
    {cgc_size_t tlv55; tlv55 = (cgc_size_t)(temp); }
    {char * tlv58; tlv58 = (char *)(temp); }
    {char * tlv57; tlv57 = (char *)(temp); }
    {void * tlv61; tlv61 = (void *)(temp); }
    {cgc_size_t tlv60; tlv60 = (cgc_size_t)(temp); }
    {char * tlv64; tlv64 = (char *)(temp); }
    {char * tlv63; tlv63 = (char *)(temp); }
    {cgc_size_t tlv62; tlv62 = (cgc_size_t)(temp); }
    {char * tlv77; tlv77 = (char *)(temp); }
}
void fix_ingred_cityParsers_6_12(){
fix_ingred_cityParsers_6_12_0();
}
void fix_ingred_cityParsers_6_13_1(){
char tlv74_ref;
    bzero(&tlv74_ref,1*sizeof(char));
char * tlv74 = &tlv74_ref;
    {int lastGood; lastGood = (int)(cgc_strlen ( tlv74 ) + 1); }
    {int startIndex; startIndex = (int)(cgc_strlen ( tlv74 ) + 1); }
    {int endIndex; endIndex = (int)(cgc_strlen ( tlv74 ) + 1); }
    {char * temp; temp = (char *)(cgc_strlen ( tlv74 ) + 1); }
    {int tempInt; tempInt = (int)(cgc_strlen ( tlv74 ) + 1); }
    {int tlv1; tlv1 = (int)(cgc_strlen ( tlv74 ) + 1); }
    {int tlv2; tlv2 = (int)(cgc_strlen ( tlv74 ) + 1); }
    {int tlv3; tlv3 = (int)(cgc_strlen ( tlv74 ) + 1); }
    {int tlv4; tlv4 = (int)(cgc_strlen ( tlv74 ) + 1); }
    {int tlv5; tlv5 = (int)(cgc_strlen ( tlv74 ) + 1); }
    {int tlv6; tlv6 = (int)(cgc_strlen ( tlv74 ) + 1); }
    {int tlv7; tlv7 = (int)(cgc_strlen ( tlv74 ) + 1); }
    {int tlv16; tlv16 = (int)(cgc_strlen ( tlv74 ) + 1); }
    {int * tlv8; tlv8 = (int *)(cgc_strlen ( tlv74 ) + 1); }
    {int tlv20; tlv20 = (int)(cgc_strlen ( tlv74 ) + 1); }
    {int tlv19; tlv19 = (int)(cgc_strlen ( tlv74 ) + 1); }
    {void * tlv11; tlv11 = (void *)(cgc_strlen ( tlv74 ) + 1); }
    {cgc_size_t tlv10; tlv10 = (cgc_size_t)(cgc_strlen ( tlv74 ) + 1); }
    {char tlv24; tlv24 = (char)(cgc_strlen ( tlv74 ) + 1); }
    {cgc_size_t tlv28; tlv28 = (cgc_size_t)(cgc_strlen ( tlv74 ) + 1); }
    {int tlv27; tlv27 = (int)(cgc_strlen ( tlv74 ) + 1); }
    {int tlv30; tlv30 = (int)(cgc_strlen ( tlv74 ) + 1); }
    {int * tlv12; tlv12 = (int *)(cgc_strlen ( tlv74 ) + 1); }
    {int tlv34; tlv34 = (int)(cgc_strlen ( tlv74 ) + 1); }
    {int tlv33; tlv33 = (int)(cgc_strlen ( tlv74 ) + 1); }
    {void * tlv15; tlv15 = (void *)(cgc_strlen ( tlv74 ) + 1); }
    {cgc_size_t tlv14; tlv14 = (cgc_size_t)(cgc_strlen ( tlv74 ) + 1); }
    {char tlv38; tlv38 = (char)(cgc_strlen ( tlv74 ) + 1); }
    {char * tlv72; tlv72 = (char *)(cgc_strlen ( tlv74 ) + 1); }
    {char * tlv73; tlv73 = (char *)(cgc_strlen ( tlv74 ) + 1); }
    {void * tlv41; tlv41 = (void *)(cgc_strlen ( tlv74 ) + 1); }
    {cgc_size_t tlv40; tlv40 = (cgc_size_t)(cgc_strlen ( tlv74 ) + 1); }
    {char * tlv46; tlv46 = (char *)(cgc_strlen ( tlv74 ) + 1); }
    {void * tlv43; tlv43 = (void *)(cgc_strlen ( tlv74 ) + 1); }
    {cgc_size_t tlv42; tlv42 = (cgc_size_t)(cgc_strlen ( tlv74 ) + 1); }
    {void * tlv45; tlv45 = (void *)(cgc_strlen ( tlv74 ) + 1); }
    {cgc_size_t tlv44; tlv44 = (cgc_size_t)(cgc_strlen ( tlv74 ) + 1); }
    {char * tlv75; tlv75 = (char *)(cgc_strlen ( tlv74 ) + 1); }
    {char * tlv76; tlv76 = (char *)(cgc_strlen ( tlv74 ) + 1); }
    {void * tlv49; tlv49 = (void *)(cgc_strlen ( tlv74 ) + 1); }
    {cgc_size_t tlv48; tlv48 = (cgc_size_t)(cgc_strlen ( tlv74 ) + 1); }
    {char * tlv52; tlv52 = (char *)(cgc_strlen ( tlv74 ) + 1); }
    {char * tlv51; tlv51 = (char *)(cgc_strlen ( tlv74 ) + 1); }
    {cgc_size_t tlv50; tlv50 = (cgc_size_t)(cgc_strlen ( tlv74 ) + 1); }
    {void * tlv54; tlv54 = (void *)(cgc_strlen ( tlv74 ) + 1); }
    {cgc_size_t tlv53; tlv53 = (cgc_size_t)(cgc_strlen ( tlv74 ) + 1); }
    {void * tlv56; tlv56 = (void *)(cgc_strlen ( tlv74 ) + 1); }
    {cgc_size_t tlv55; tlv55 = (cgc_size_t)(cgc_strlen ( tlv74 ) + 1); }
    {char * tlv58; tlv58 = (char *)(cgc_strlen ( tlv74 ) + 1); }
    {char * tlv57; tlv57 = (char *)(cgc_strlen ( tlv74 ) + 1); }
    {void * tlv61; tlv61 = (void *)(cgc_strlen ( tlv74 ) + 1); }
    {cgc_size_t tlv60; tlv60 = (cgc_size_t)(cgc_strlen ( tlv74 ) + 1); }
    {char * tlv64; tlv64 = (char *)(cgc_strlen ( tlv74 ) + 1); }
    {char * tlv63; tlv63 = (char *)(cgc_strlen ( tlv74 ) + 1); }
    {cgc_size_t tlv62; tlv62 = (cgc_size_t)(cgc_strlen ( tlv74 ) + 1); }
    {char * tlv77; tlv77 = (char *)(cgc_strlen ( tlv74 ) + 1); }
}
void fix_ingred_cityParsers_6_13(){
fix_ingred_cityParsers_6_13_1();
}
void fix_ingred_cityParsers_6_15_1(){
char tlv72_ref;
    bzero(&tlv72_ref,1*sizeof(char));
char * tlv72 = &tlv72_ref;
    {int lastGood; lastGood = (int)(cgc_strlen ( tlv72 ) + 1); }
    {int startIndex; startIndex = (int)(cgc_strlen ( tlv72 ) + 1); }
    {int endIndex; endIndex = (int)(cgc_strlen ( tlv72 ) + 1); }
    {char * temp; temp = (char *)(cgc_strlen ( tlv72 ) + 1); }
    {int tempInt; tempInt = (int)(cgc_strlen ( tlv72 ) + 1); }
    {int tlv1; tlv1 = (int)(cgc_strlen ( tlv72 ) + 1); }
    {int tlv2; tlv2 = (int)(cgc_strlen ( tlv72 ) + 1); }
    {int tlv3; tlv3 = (int)(cgc_strlen ( tlv72 ) + 1); }
    {int tlv4; tlv4 = (int)(cgc_strlen ( tlv72 ) + 1); }
    {int tlv5; tlv5 = (int)(cgc_strlen ( tlv72 ) + 1); }
    {int tlv6; tlv6 = (int)(cgc_strlen ( tlv72 ) + 1); }
    {int tlv7; tlv7 = (int)(cgc_strlen ( tlv72 ) + 1); }
    {int tlv16; tlv16 = (int)(cgc_strlen ( tlv72 ) + 1); }
    {int * tlv8; tlv8 = (int *)(cgc_strlen ( tlv72 ) + 1); }
    {int tlv20; tlv20 = (int)(cgc_strlen ( tlv72 ) + 1); }
    {int tlv19; tlv19 = (int)(cgc_strlen ( tlv72 ) + 1); }
    {void * tlv11; tlv11 = (void *)(cgc_strlen ( tlv72 ) + 1); }
    {cgc_size_t tlv10; tlv10 = (cgc_size_t)(cgc_strlen ( tlv72 ) + 1); }
    {char tlv24; tlv24 = (char)(cgc_strlen ( tlv72 ) + 1); }
    {cgc_size_t tlv28; tlv28 = (cgc_size_t)(cgc_strlen ( tlv72 ) + 1); }
    {int tlv27; tlv27 = (int)(cgc_strlen ( tlv72 ) + 1); }
    {int tlv30; tlv30 = (int)(cgc_strlen ( tlv72 ) + 1); }
    {int * tlv12; tlv12 = (int *)(cgc_strlen ( tlv72 ) + 1); }
    {int tlv34; tlv34 = (int)(cgc_strlen ( tlv72 ) + 1); }
    {int tlv33; tlv33 = (int)(cgc_strlen ( tlv72 ) + 1); }
    {void * tlv15; tlv15 = (void *)(cgc_strlen ( tlv72 ) + 1); }
    {cgc_size_t tlv14; tlv14 = (cgc_size_t)(cgc_strlen ( tlv72 ) + 1); }
    {char tlv38; tlv38 = (char)(cgc_strlen ( tlv72 ) + 1); }
    {char * tlv73; tlv73 = (char *)(cgc_strlen ( tlv72 ) + 1); }
    {void * tlv41; tlv41 = (void *)(cgc_strlen ( tlv72 ) + 1); }
    {cgc_size_t tlv40; tlv40 = (cgc_size_t)(cgc_strlen ( tlv72 ) + 1); }
    {char * tlv46; tlv46 = (char *)(cgc_strlen ( tlv72 ) + 1); }
    {void * tlv43; tlv43 = (void *)(cgc_strlen ( tlv72 ) + 1); }
    {cgc_size_t tlv42; tlv42 = (cgc_size_t)(cgc_strlen ( tlv72 ) + 1); }
    {void * tlv45; tlv45 = (void *)(cgc_strlen ( tlv72 ) + 1); }
    {cgc_size_t tlv44; tlv44 = (cgc_size_t)(cgc_strlen ( tlv72 ) + 1); }
    {char * tlv74; tlv74 = (char *)(cgc_strlen ( tlv72 ) + 1); }
    {char * tlv75; tlv75 = (char *)(cgc_strlen ( tlv72 ) + 1); }
    {char * tlv76; tlv76 = (char *)(cgc_strlen ( tlv72 ) + 1); }
    {void * tlv49; tlv49 = (void *)(cgc_strlen ( tlv72 ) + 1); }
    {cgc_size_t tlv48; tlv48 = (cgc_size_t)(cgc_strlen ( tlv72 ) + 1); }
    {char * tlv52; tlv52 = (char *)(cgc_strlen ( tlv72 ) + 1); }
    {char * tlv51; tlv51 = (char *)(cgc_strlen ( tlv72 ) + 1); }
    {cgc_size_t tlv50; tlv50 = (cgc_size_t)(cgc_strlen ( tlv72 ) + 1); }
    {void * tlv54; tlv54 = (void *)(cgc_strlen ( tlv72 ) + 1); }
    {cgc_size_t tlv53; tlv53 = (cgc_size_t)(cgc_strlen ( tlv72 ) + 1); }
    {void * tlv56; tlv56 = (void *)(cgc_strlen ( tlv72 ) + 1); }
    {cgc_size_t tlv55; tlv55 = (cgc_size_t)(cgc_strlen ( tlv72 ) + 1); }
    {char * tlv58; tlv58 = (char *)(cgc_strlen ( tlv72 ) + 1); }
    {char * tlv57; tlv57 = (char *)(cgc_strlen ( tlv72 ) + 1); }
    {void * tlv61; tlv61 = (void *)(cgc_strlen ( tlv72 ) + 1); }
    {cgc_size_t tlv60; tlv60 = (cgc_size_t)(cgc_strlen ( tlv72 ) + 1); }
    {char * tlv64; tlv64 = (char *)(cgc_strlen ( tlv72 ) + 1); }
    {char * tlv63; tlv63 = (char *)(cgc_strlen ( tlv72 ) + 1); }
    {cgc_size_t tlv62; tlv62 = (cgc_size_t)(cgc_strlen ( tlv72 ) + 1); }
    {char * tlv77; tlv77 = (char *)(cgc_strlen ( tlv72 ) + 1); }
}
void fix_ingred_cityParsers_6_15(){
fix_ingred_cityParsers_6_15_1();
}
void fix_ingred_cityParsers_6_16_1(){
    {int lastGood; lastGood = (int)('}'); }
    {int startIndex; startIndex = (int)('}'); }
    {int endIndex; endIndex = (int)('}'); }
    {char * temp; temp = (char *)('}'); }
    {int tempInt; tempInt = (int)('}'); }
    {int tlv1; tlv1 = (int)('}'); }
    {int tlv2; tlv2 = (int)('}'); }
    {int tlv3; tlv3 = (int)('}'); }
    {int tlv4; tlv4 = (int)('}'); }
    {int tlv5; tlv5 = (int)('}'); }
    {int tlv6; tlv6 = (int)('}'); }
    {int tlv7; tlv7 = (int)('}'); }
    {int tlv16; tlv16 = (int)('}'); }
    {int * tlv8; tlv8 = (int *)('}'); }
    {int tlv20; tlv20 = (int)('}'); }
    {int tlv19; tlv19 = (int)('}'); }
    {void * tlv11; tlv11 = (void *)('}'); }
    {cgc_size_t tlv10; tlv10 = (cgc_size_t)('}'); }
    {char tlv24; tlv24 = (char)('}'); }
    {cgc_size_t tlv28; tlv28 = (cgc_size_t)('}'); }
    {int tlv27; tlv27 = (int)('}'); }
    {int tlv30; tlv30 = (int)('}'); }
    {int * tlv12; tlv12 = (int *)('}'); }
    {int tlv34; tlv34 = (int)('}'); }
    {int tlv33; tlv33 = (int)('}'); }
    {void * tlv15; tlv15 = (void *)('}'); }
    {cgc_size_t tlv14; tlv14 = (cgc_size_t)('}'); }
    {char tlv38; tlv38 = (char)('}'); }
    {char * tlv72; tlv72 = (char *)('}'); }
    {char * tlv73; tlv73 = (char *)('}'); }
    {void * tlv41; tlv41 = (void *)('}'); }
    {cgc_size_t tlv40; tlv40 = (cgc_size_t)('}'); }
    {char * tlv46; tlv46 = (char *)('}'); }
    {void * tlv43; tlv43 = (void *)('}'); }
    {cgc_size_t tlv42; tlv42 = (cgc_size_t)('}'); }
    {void * tlv45; tlv45 = (void *)('}'); }
    {cgc_size_t tlv44; tlv44 = (cgc_size_t)('}'); }
    {char * tlv74; tlv74 = (char *)('}'); }
    {char * tlv75; tlv75 = (char *)('}'); }
    {char * tlv76; tlv76 = (char *)('}'); }
    {void * tlv49; tlv49 = (void *)('}'); }
    {cgc_size_t tlv48; tlv48 = (cgc_size_t)('}'); }
    {char * tlv52; tlv52 = (char *)('}'); }
    {char * tlv51; tlv51 = (char *)('}'); }
    {cgc_size_t tlv50; tlv50 = (cgc_size_t)('}'); }
    {void * tlv54; tlv54 = (void *)('}'); }
    {cgc_size_t tlv53; tlv53 = (cgc_size_t)('}'); }
    {void * tlv56; tlv56 = (void *)('}'); }
    {cgc_size_t tlv55; tlv55 = (cgc_size_t)('}'); }
    {char * tlv58; tlv58 = (char *)('}'); }
    {char * tlv57; tlv57 = (char *)('}'); }
    {void * tlv61; tlv61 = (void *)('}'); }
    {cgc_size_t tlv60; tlv60 = (cgc_size_t)('}'); }
    {char * tlv64; tlv64 = (char *)('}'); }
    {char * tlv63; tlv63 = (char *)('}'); }
    {cgc_size_t tlv62; tlv62 = (cgc_size_t)('}'); }
    {char * tlv77; tlv77 = (char *)('}'); }
}
void fix_ingred_cityParsers_6_16(){
fix_ingred_cityParsers_6_16_1();
}
void fix_ingred_cityParsers_6_18_0(){
    {int lastGood; lastGood = (int)(sizeof ( City )); }
    {int startIndex; startIndex = (int)(sizeof ( City )); }
    {int endIndex; endIndex = (int)(sizeof ( City )); }
    {char * temp; temp = (char *)(sizeof ( City )); }
    {int tempInt; tempInt = (int)(sizeof ( City )); }
    {int tlv1; tlv1 = (int)(sizeof ( City )); }
    {int tlv2; tlv2 = (int)(sizeof ( City )); }
    {int tlv3; tlv3 = (int)(sizeof ( City )); }
    {int tlv4; tlv4 = (int)(sizeof ( City )); }
    {int tlv5; tlv5 = (int)(sizeof ( City )); }
    {int tlv6; tlv6 = (int)(sizeof ( City )); }
    {int tlv7; tlv7 = (int)(sizeof ( City )); }
    {int tlv16; tlv16 = (int)(sizeof ( City )); }
    {int * tlv8; tlv8 = (int *)(sizeof ( City )); }
    {int tlv20; tlv20 = (int)(sizeof ( City )); }
    {int tlv19; tlv19 = (int)(sizeof ( City )); }
    {void * tlv11; tlv11 = (void *)(sizeof ( City )); }
    {cgc_size_t tlv10; tlv10 = (cgc_size_t)(sizeof ( City )); }
    {char tlv24; tlv24 = (char)(sizeof ( City )); }
    {cgc_size_t tlv28; tlv28 = (cgc_size_t)(sizeof ( City )); }
    {int tlv27; tlv27 = (int)(sizeof ( City )); }
    {int tlv30; tlv30 = (int)(sizeof ( City )); }
    {int * tlv12; tlv12 = (int *)(sizeof ( City )); }
    {int tlv34; tlv34 = (int)(sizeof ( City )); }
    {int tlv33; tlv33 = (int)(sizeof ( City )); }
    {void * tlv15; tlv15 = (void *)(sizeof ( City )); }
    {cgc_size_t tlv14; tlv14 = (cgc_size_t)(sizeof ( City )); }
    {char tlv38; tlv38 = (char)(sizeof ( City )); }
    {char * tlv72; tlv72 = (char *)(sizeof ( City )); }
    {char * tlv73; tlv73 = (char *)(sizeof ( City )); }
    {void * tlv41; tlv41 = (void *)(sizeof ( City )); }
    {cgc_size_t tlv40; tlv40 = (cgc_size_t)(sizeof ( City )); }
    {char * tlv46; tlv46 = (char *)(sizeof ( City )); }
    {void * tlv43; tlv43 = (void *)(sizeof ( City )); }
    {cgc_size_t tlv42; tlv42 = (cgc_size_t)(sizeof ( City )); }
    {void * tlv45; tlv45 = (void *)(sizeof ( City )); }
    {cgc_size_t tlv44; tlv44 = (cgc_size_t)(sizeof ( City )); }
    {char * tlv74; tlv74 = (char *)(sizeof ( City )); }
    {char * tlv75; tlv75 = (char *)(sizeof ( City )); }
    {char * tlv76; tlv76 = (char *)(sizeof ( City )); }
    {void * tlv49; tlv49 = (void *)(sizeof ( City )); }
    {cgc_size_t tlv48; tlv48 = (cgc_size_t)(sizeof ( City )); }
    {char * tlv52; tlv52 = (char *)(sizeof ( City )); }
    {char * tlv51; tlv51 = (char *)(sizeof ( City )); }
    {cgc_size_t tlv50; tlv50 = (cgc_size_t)(sizeof ( City )); }
    {void * tlv54; tlv54 = (void *)(sizeof ( City )); }
    {cgc_size_t tlv53; tlv53 = (cgc_size_t)(sizeof ( City )); }
    {void * tlv56; tlv56 = (void *)(sizeof ( City )); }
    {cgc_size_t tlv55; tlv55 = (cgc_size_t)(sizeof ( City )); }
    {char * tlv58; tlv58 = (char *)(sizeof ( City )); }
    {char * tlv57; tlv57 = (char *)(sizeof ( City )); }
    {void * tlv61; tlv61 = (void *)(sizeof ( City )); }
    {cgc_size_t tlv60; tlv60 = (cgc_size_t)(sizeof ( City )); }
    {char * tlv64; tlv64 = (char *)(sizeof ( City )); }
    {char * tlv63; tlv63 = (char *)(sizeof ( City )); }
    {cgc_size_t tlv62; tlv62 = (cgc_size_t)(sizeof ( City )); }
    {char * tlv77; tlv77 = (char *)(sizeof ( City )); }
}
void fix_ingred_cityParsers_6_18(){
fix_ingred_cityParsers_6_18_0();
}
void fix_ingred_cityParsers_6_19_8(){
int tlv4;
    bzero(&tlv4,sizeof(int));
    {int lastGood; lastGood = (int)(tlv4); }
    {int startIndex; startIndex = (int)(tlv4); }
    {int endIndex; endIndex = (int)(tlv4); }
    {char * temp; temp = (char *)(tlv4); }
    {int tempInt; tempInt = (int)(tlv4); }
    {int tlv5; tlv5 = (int)(tlv4); }
    {int tlv6; tlv6 = (int)(tlv4); }
    {int tlv7; tlv7 = (int)(tlv4); }
    {int tlv16; tlv16 = (int)(tlv4); }
    {int * tlv8; tlv8 = (int *)(tlv4); }
    {int tlv20; tlv20 = (int)(tlv4); }
    {int tlv19; tlv19 = (int)(tlv4); }
    {void * tlv11; tlv11 = (void *)(tlv4); }
    {cgc_size_t tlv10; tlv10 = (cgc_size_t)(tlv4); }
    {char tlv24; tlv24 = (char)(tlv4); }
    {cgc_size_t tlv28; tlv28 = (cgc_size_t)(tlv4); }
    {int tlv27; tlv27 = (int)(tlv4); }
    {int tlv30; tlv30 = (int)(tlv4); }
    {int * tlv12; tlv12 = (int *)(tlv4); }
    {int tlv34; tlv34 = (int)(tlv4); }
    {int tlv33; tlv33 = (int)(tlv4); }
    {void * tlv15; tlv15 = (void *)(tlv4); }
    {cgc_size_t tlv14; tlv14 = (cgc_size_t)(tlv4); }
    {char tlv38; tlv38 = (char)(tlv4); }
    {char * tlv72; tlv72 = (char *)(tlv4); }
    {char * tlv73; tlv73 = (char *)(tlv4); }
    {void * tlv41; tlv41 = (void *)(tlv4); }
    {cgc_size_t tlv40; tlv40 = (cgc_size_t)(tlv4); }
    {char * tlv46; tlv46 = (char *)(tlv4); }
    {void * tlv43; tlv43 = (void *)(tlv4); }
    {cgc_size_t tlv42; tlv42 = (cgc_size_t)(tlv4); }
    {void * tlv45; tlv45 = (void *)(tlv4); }
    {cgc_size_t tlv44; tlv44 = (cgc_size_t)(tlv4); }
    {char * tlv74; tlv74 = (char *)(tlv4); }
    {char * tlv75; tlv75 = (char *)(tlv4); }
    {char * tlv76; tlv76 = (char *)(tlv4); }
    {void * tlv49; tlv49 = (void *)(tlv4); }
    {cgc_size_t tlv48; tlv48 = (cgc_size_t)(tlv4); }
    {char * tlv52; tlv52 = (char *)(tlv4); }
    {char * tlv51; tlv51 = (char *)(tlv4); }
    {cgc_size_t tlv50; tlv50 = (cgc_size_t)(tlv4); }
    {void * tlv54; tlv54 = (void *)(tlv4); }
    {cgc_size_t tlv53; tlv53 = (cgc_size_t)(tlv4); }
    {void * tlv56; tlv56 = (void *)(tlv4); }
    {cgc_size_t tlv55; tlv55 = (cgc_size_t)(tlv4); }
    {char * tlv58; tlv58 = (char *)(tlv4); }
    {char * tlv57; tlv57 = (char *)(tlv4); }
    {void * tlv61; tlv61 = (void *)(tlv4); }
    {cgc_size_t tlv60; tlv60 = (cgc_size_t)(tlv4); }
    {char * tlv64; tlv64 = (char *)(tlv4); }
    {char * tlv63; tlv63 = (char *)(tlv4); }
    {cgc_size_t tlv62; tlv62 = (cgc_size_t)(tlv4); }
    {char * tlv77; tlv77 = (char *)(tlv4); }
}
void fix_ingred_cityParsers_6_19(){
fix_ingred_cityParsers_6_19_8();
}
void fix_ingred_cityParsers_6_24_1(){
char tlv75_ref;
    bzero(&tlv75_ref,1*sizeof(char));
char * tlv75 = &tlv75_ref;
    {int lastGood; lastGood = (int)(cgc_strlen ( tlv75 ) + 1); }
    {int startIndex; startIndex = (int)(cgc_strlen ( tlv75 ) + 1); }
    {int endIndex; endIndex = (int)(cgc_strlen ( tlv75 ) + 1); }
    {char * temp; temp = (char *)(cgc_strlen ( tlv75 ) + 1); }
    {int tempInt; tempInt = (int)(cgc_strlen ( tlv75 ) + 1); }
    {int tlv1; tlv1 = (int)(cgc_strlen ( tlv75 ) + 1); }
    {int tlv2; tlv2 = (int)(cgc_strlen ( tlv75 ) + 1); }
    {int tlv3; tlv3 = (int)(cgc_strlen ( tlv75 ) + 1); }
    {int tlv4; tlv4 = (int)(cgc_strlen ( tlv75 ) + 1); }
    {int tlv5; tlv5 = (int)(cgc_strlen ( tlv75 ) + 1); }
    {int tlv6; tlv6 = (int)(cgc_strlen ( tlv75 ) + 1); }
    {int tlv7; tlv7 = (int)(cgc_strlen ( tlv75 ) + 1); }
    {int tlv16; tlv16 = (int)(cgc_strlen ( tlv75 ) + 1); }
    {int * tlv8; tlv8 = (int *)(cgc_strlen ( tlv75 ) + 1); }
    {int tlv20; tlv20 = (int)(cgc_strlen ( tlv75 ) + 1); }
    {int tlv19; tlv19 = (int)(cgc_strlen ( tlv75 ) + 1); }
    {void * tlv11; tlv11 = (void *)(cgc_strlen ( tlv75 ) + 1); }
    {cgc_size_t tlv10; tlv10 = (cgc_size_t)(cgc_strlen ( tlv75 ) + 1); }
    {char tlv24; tlv24 = (char)(cgc_strlen ( tlv75 ) + 1); }
    {cgc_size_t tlv28; tlv28 = (cgc_size_t)(cgc_strlen ( tlv75 ) + 1); }
    {int tlv27; tlv27 = (int)(cgc_strlen ( tlv75 ) + 1); }
    {int tlv30; tlv30 = (int)(cgc_strlen ( tlv75 ) + 1); }
    {int * tlv12; tlv12 = (int *)(cgc_strlen ( tlv75 ) + 1); }
    {int tlv34; tlv34 = (int)(cgc_strlen ( tlv75 ) + 1); }
    {int tlv33; tlv33 = (int)(cgc_strlen ( tlv75 ) + 1); }
    {void * tlv15; tlv15 = (void *)(cgc_strlen ( tlv75 ) + 1); }
    {cgc_size_t tlv14; tlv14 = (cgc_size_t)(cgc_strlen ( tlv75 ) + 1); }
    {char tlv38; tlv38 = (char)(cgc_strlen ( tlv75 ) + 1); }
    {char * tlv72; tlv72 = (char *)(cgc_strlen ( tlv75 ) + 1); }
    {char * tlv73; tlv73 = (char *)(cgc_strlen ( tlv75 ) + 1); }
    {void * tlv41; tlv41 = (void *)(cgc_strlen ( tlv75 ) + 1); }
    {cgc_size_t tlv40; tlv40 = (cgc_size_t)(cgc_strlen ( tlv75 ) + 1); }
    {char * tlv46; tlv46 = (char *)(cgc_strlen ( tlv75 ) + 1); }
    {void * tlv43; tlv43 = (void *)(cgc_strlen ( tlv75 ) + 1); }
    {cgc_size_t tlv42; tlv42 = (cgc_size_t)(cgc_strlen ( tlv75 ) + 1); }
    {void * tlv45; tlv45 = (void *)(cgc_strlen ( tlv75 ) + 1); }
    {cgc_size_t tlv44; tlv44 = (cgc_size_t)(cgc_strlen ( tlv75 ) + 1); }
    {char * tlv74; tlv74 = (char *)(cgc_strlen ( tlv75 ) + 1); }
    {char * tlv76; tlv76 = (char *)(cgc_strlen ( tlv75 ) + 1); }
    {void * tlv49; tlv49 = (void *)(cgc_strlen ( tlv75 ) + 1); }
    {cgc_size_t tlv48; tlv48 = (cgc_size_t)(cgc_strlen ( tlv75 ) + 1); }
    {char * tlv52; tlv52 = (char *)(cgc_strlen ( tlv75 ) + 1); }
    {char * tlv51; tlv51 = (char *)(cgc_strlen ( tlv75 ) + 1); }
    {cgc_size_t tlv50; tlv50 = (cgc_size_t)(cgc_strlen ( tlv75 ) + 1); }
    {void * tlv54; tlv54 = (void *)(cgc_strlen ( tlv75 ) + 1); }
    {cgc_size_t tlv53; tlv53 = (cgc_size_t)(cgc_strlen ( tlv75 ) + 1); }
    {void * tlv56; tlv56 = (void *)(cgc_strlen ( tlv75 ) + 1); }
    {cgc_size_t tlv55; tlv55 = (cgc_size_t)(cgc_strlen ( tlv75 ) + 1); }
    {char * tlv58; tlv58 = (char *)(cgc_strlen ( tlv75 ) + 1); }
    {char * tlv57; tlv57 = (char *)(cgc_strlen ( tlv75 ) + 1); }
    {void * tlv61; tlv61 = (void *)(cgc_strlen ( tlv75 ) + 1); }
    {cgc_size_t tlv60; tlv60 = (cgc_size_t)(cgc_strlen ( tlv75 ) + 1); }
    {char * tlv64; tlv64 = (char *)(cgc_strlen ( tlv75 ) + 1); }
    {char * tlv63; tlv63 = (char *)(cgc_strlen ( tlv75 ) + 1); }
    {cgc_size_t tlv62; tlv62 = (cgc_size_t)(cgc_strlen ( tlv75 ) + 1); }
    {char * tlv77; tlv77 = (char *)(cgc_strlen ( tlv75 ) + 1); }
}
void fix_ingred_cityParsers_6_24(){
fix_ingred_cityParsers_6_24_1();
}
void fix_ingred_cityParsers_6_25_1(){
City newCity_ref;
    bzero(&newCity_ref,1*sizeof(City));
pCity newCity = &newCity_ref;
    {int lastGood; lastGood = (int)(newCity -> border_count); }
    {int startIndex; startIndex = (int)(newCity -> border_count); }
    {int endIndex; endIndex = (int)(newCity -> border_count); }
    {char * temp; temp = (char *)(newCity -> border_count); }
    {int tempInt; tempInt = (int)(newCity -> border_count); }
    {int tlv1; tlv1 = (int)(newCity -> border_count); }
    {int tlv2; tlv2 = (int)(newCity -> border_count); }
    {int tlv3; tlv3 = (int)(newCity -> border_count); }
    {int tlv4; tlv4 = (int)(newCity -> border_count); }
    {int tlv5; tlv5 = (int)(newCity -> border_count); }
    {int tlv6; tlv6 = (int)(newCity -> border_count); }
    {int tlv7; tlv7 = (int)(newCity -> border_count); }
    {int tlv16; tlv16 = (int)(newCity -> border_count); }
    {int * tlv8; tlv8 = (int *)(newCity -> border_count); }
    {int tlv20; tlv20 = (int)(newCity -> border_count); }
    {int tlv19; tlv19 = (int)(newCity -> border_count); }
    {void * tlv11; tlv11 = (void *)(newCity -> border_count); }
    {cgc_size_t tlv10; tlv10 = (cgc_size_t)(newCity -> border_count); }
    {char tlv24; tlv24 = (char)(newCity -> border_count); }
    {cgc_size_t tlv28; tlv28 = (cgc_size_t)(newCity -> border_count); }
    {int tlv27; tlv27 = (int)(newCity -> border_count); }
    {int tlv30; tlv30 = (int)(newCity -> border_count); }
    {int * tlv12; tlv12 = (int *)(newCity -> border_count); }
    {int tlv34; tlv34 = (int)(newCity -> border_count); }
    {int tlv33; tlv33 = (int)(newCity -> border_count); }
    {void * tlv15; tlv15 = (void *)(newCity -> border_count); }
    {cgc_size_t tlv14; tlv14 = (cgc_size_t)(newCity -> border_count); }
    {char tlv38; tlv38 = (char)(newCity -> border_count); }
    {char * tlv72; tlv72 = (char *)(newCity -> border_count); }
    {char * tlv73; tlv73 = (char *)(newCity -> border_count); }
    {void * tlv41; tlv41 = (void *)(newCity -> border_count); }
    {cgc_size_t tlv40; tlv40 = (cgc_size_t)(newCity -> border_count); }
    {char * tlv46; tlv46 = (char *)(newCity -> border_count); }
    {void * tlv43; tlv43 = (void *)(newCity -> border_count); }
    {cgc_size_t tlv42; tlv42 = (cgc_size_t)(newCity -> border_count); }
    {void * tlv45; tlv45 = (void *)(newCity -> border_count); }
    {cgc_size_t tlv44; tlv44 = (cgc_size_t)(newCity -> border_count); }
    {char * tlv74; tlv74 = (char *)(newCity -> border_count); }
    {char * tlv75; tlv75 = (char *)(newCity -> border_count); }
    {char * tlv76; tlv76 = (char *)(newCity -> border_count); }
    {void * tlv49; tlv49 = (void *)(newCity -> border_count); }
    {cgc_size_t tlv48; tlv48 = (cgc_size_t)(newCity -> border_count); }
    {char * tlv52; tlv52 = (char *)(newCity -> border_count); }
    {char * tlv51; tlv51 = (char *)(newCity -> border_count); }
    {cgc_size_t tlv50; tlv50 = (cgc_size_t)(newCity -> border_count); }
    {void * tlv54; tlv54 = (void *)(newCity -> border_count); }
    {cgc_size_t tlv53; tlv53 = (cgc_size_t)(newCity -> border_count); }
    {void * tlv56; tlv56 = (void *)(newCity -> border_count); }
    {cgc_size_t tlv55; tlv55 = (cgc_size_t)(newCity -> border_count); }
    {char * tlv58; tlv58 = (char *)(newCity -> border_count); }
    {char * tlv57; tlv57 = (char *)(newCity -> border_count); }
    {void * tlv61; tlv61 = (void *)(newCity -> border_count); }
    {cgc_size_t tlv60; tlv60 = (cgc_size_t)(newCity -> border_count); }
    {char * tlv64; tlv64 = (char *)(newCity -> border_count); }
    {char * tlv63; tlv63 = (char *)(newCity -> border_count); }
    {cgc_size_t tlv62; tlv62 = (cgc_size_t)(newCity -> border_count); }
    {char * tlv77; tlv77 = (char *)(newCity -> border_count); }
}
void fix_ingred_cityParsers_6_25(){
fix_ingred_cityParsers_6_25_1();
}
void fix_ingred_cityParsers_6_29_0(){
City newCity_ref;
    bzero(&newCity_ref,1*sizeof(City));
pCity newCity = &newCity_ref;
    {int lastGood; lastGood = (int)(newCity -> name); }
    {int startIndex; startIndex = (int)(newCity -> name); }
    {int endIndex; endIndex = (int)(newCity -> name); }
    {char * temp; temp = (char *)(newCity -> name); }
    {int tempInt; tempInt = (int)(newCity -> name); }
    {int tlv1; tlv1 = (int)(newCity -> name); }
    {int tlv2; tlv2 = (int)(newCity -> name); }
    {int tlv3; tlv3 = (int)(newCity -> name); }
    {int tlv4; tlv4 = (int)(newCity -> name); }
    {int tlv5; tlv5 = (int)(newCity -> name); }
    {int tlv6; tlv6 = (int)(newCity -> name); }
    {int tlv7; tlv7 = (int)(newCity -> name); }
    {int tlv16; tlv16 = (int)(newCity -> name); }
    {int * tlv8; tlv8 = (int *)(newCity -> name); }
    {int tlv20; tlv20 = (int)(newCity -> name); }
    {int tlv19; tlv19 = (int)(newCity -> name); }
    {void * tlv11; tlv11 = (void *)(newCity -> name); }
    {cgc_size_t tlv10; tlv10 = (cgc_size_t)(newCity -> name); }
    {char tlv24; tlv24 = (char)(newCity -> name); }
    {cgc_size_t tlv28; tlv28 = (cgc_size_t)(newCity -> name); }
    {int tlv27; tlv27 = (int)(newCity -> name); }
    {int tlv30; tlv30 = (int)(newCity -> name); }
    {int * tlv12; tlv12 = (int *)(newCity -> name); }
    {int tlv34; tlv34 = (int)(newCity -> name); }
    {int tlv33; tlv33 = (int)(newCity -> name); }
    {void * tlv15; tlv15 = (void *)(newCity -> name); }
    {cgc_size_t tlv14; tlv14 = (cgc_size_t)(newCity -> name); }
    {char tlv38; tlv38 = (char)(newCity -> name); }
    {char * tlv72; tlv72 = (char *)(newCity -> name); }
    {char * tlv73; tlv73 = (char *)(newCity -> name); }
    {void * tlv41; tlv41 = (void *)(newCity -> name); }
    {cgc_size_t tlv40; tlv40 = (cgc_size_t)(newCity -> name); }
    {char * tlv46; tlv46 = (char *)(newCity -> name); }
    {void * tlv43; tlv43 = (void *)(newCity -> name); }
    {cgc_size_t tlv42; tlv42 = (cgc_size_t)(newCity -> name); }
    {void * tlv45; tlv45 = (void *)(newCity -> name); }
    {cgc_size_t tlv44; tlv44 = (cgc_size_t)(newCity -> name); }
    {char * tlv74; tlv74 = (char *)(newCity -> name); }
    {char * tlv75; tlv75 = (char *)(newCity -> name); }
    {char * tlv76; tlv76 = (char *)(newCity -> name); }
    {void * tlv49; tlv49 = (void *)(newCity -> name); }
    {cgc_size_t tlv48; tlv48 = (cgc_size_t)(newCity -> name); }
    {char * tlv52; tlv52 = (char *)(newCity -> name); }
    {char * tlv51; tlv51 = (char *)(newCity -> name); }
    {cgc_size_t tlv50; tlv50 = (cgc_size_t)(newCity -> name); }
    {void * tlv54; tlv54 = (void *)(newCity -> name); }
    {cgc_size_t tlv53; tlv53 = (cgc_size_t)(newCity -> name); }
    {void * tlv56; tlv56 = (void *)(newCity -> name); }
    {cgc_size_t tlv55; tlv55 = (cgc_size_t)(newCity -> name); }
    {char * tlv58; tlv58 = (char *)(newCity -> name); }
    {char * tlv57; tlv57 = (char *)(newCity -> name); }
    {void * tlv61; tlv61 = (void *)(newCity -> name); }
    {cgc_size_t tlv60; tlv60 = (cgc_size_t)(newCity -> name); }
    {char * tlv64; tlv64 = (char *)(newCity -> name); }
    {char * tlv63; tlv63 = (char *)(newCity -> name); }
    {cgc_size_t tlv62; tlv62 = (cgc_size_t)(newCity -> name); }
    {char * tlv77; tlv77 = (char *)(newCity -> name); }
}
void fix_ingred_cityParsers_6_29_1(){
City newCity_ref;
    bzero(&newCity_ref,1*sizeof(City));
pCity newCity = &newCity_ref;
    {int lastGood; lastGood = (int)(20); }
    {int startIndex; startIndex = (int)(20); }
    {int endIndex; endIndex = (int)(20); }
    {char * temp; temp = (char *)(20); }
    {int tempInt; tempInt = (int)(20); }
    {int tlv1; tlv1 = (int)(20); }
    {int tlv2; tlv2 = (int)(20); }
    {int tlv3; tlv3 = (int)(20); }
    {int tlv4; tlv4 = (int)(20); }
    {int tlv5; tlv5 = (int)(20); }
    {int tlv6; tlv6 = (int)(20); }
    {int tlv7; tlv7 = (int)(20); }
    {int tlv16; tlv16 = (int)(20); }
    {int * tlv8; tlv8 = (int *)(20); }
    {int tlv20; tlv20 = (int)(20); }
    {int tlv19; tlv19 = (int)(20); }
    {void * tlv11; tlv11 = (void *)(20); }
    {cgc_size_t tlv10; tlv10 = (cgc_size_t)(20); }
    {char tlv24; tlv24 = (char)(20); }
    {cgc_size_t tlv28; tlv28 = (cgc_size_t)(20); }
    {int tlv27; tlv27 = (int)(20); }
    {int tlv30; tlv30 = (int)(20); }
    {int * tlv12; tlv12 = (int *)(20); }
    {int tlv34; tlv34 = (int)(20); }
    {int tlv33; tlv33 = (int)(20); }
    {void * tlv15; tlv15 = (void *)(20); }
    {cgc_size_t tlv14; tlv14 = (cgc_size_t)(20); }
    {char tlv38; tlv38 = (char)(20); }
    {char * tlv72; tlv72 = (char *)(20); }
    {char * tlv73; tlv73 = (char *)(20); }
    {void * tlv41; tlv41 = (void *)(20); }
    {cgc_size_t tlv40; tlv40 = (cgc_size_t)(20); }
    {char * tlv46; tlv46 = (char *)(20); }
    {void * tlv43; tlv43 = (void *)(20); }
    {cgc_size_t tlv42; tlv42 = (cgc_size_t)(20); }
    {void * tlv45; tlv45 = (void *)(20); }
    {cgc_size_t tlv44; tlv44 = (cgc_size_t)(20); }
    {char * tlv74; tlv74 = (char *)(20); }
    {char * tlv75; tlv75 = (char *)(20); }
    {char * tlv76; tlv76 = (char *)(20); }
    {void * tlv49; tlv49 = (void *)(20); }
    {cgc_size_t tlv48; tlv48 = (cgc_size_t)(20); }
    {char * tlv52; tlv52 = (char *)(20); }
    {char * tlv51; tlv51 = (char *)(20); }
    {cgc_size_t tlv50; tlv50 = (cgc_size_t)(20); }
    {void * tlv54; tlv54 = (void *)(20); }
    {cgc_size_t tlv53; tlv53 = (cgc_size_t)(20); }
    {void * tlv56; tlv56 = (void *)(20); }
    {cgc_size_t tlv55; tlv55 = (cgc_size_t)(20); }
    {char * tlv58; tlv58 = (char *)(20); }
    {char * tlv57; tlv57 = (char *)(20); }
    {void * tlv61; tlv61 = (void *)(20); }
    {cgc_size_t tlv60; tlv60 = (cgc_size_t)(20); }
    {char * tlv64; tlv64 = (char *)(20); }
    {char * tlv63; tlv63 = (char *)(20); }
    {cgc_size_t tlv62; tlv62 = (cgc_size_t)(20); }
    {char * tlv77; tlv77 = (char *)(20); }
}
void fix_ingred_cityParsers_6_29(){
fix_ingred_cityParsers_6_29_0();
fix_ingred_cityParsers_6_29_1();
}
void fix_ingred_cityParsers_6_30_0(){
City newCity_ref;
    bzero(&newCity_ref,1*sizeof(City));
pCity newCity = &newCity_ref;
    {int lastGood; lastGood = (int)(newCity -> name); }
    {int startIndex; startIndex = (int)(newCity -> name); }
    {int endIndex; endIndex = (int)(newCity -> name); }
    {char * temp; temp = (char *)(newCity -> name); }
    {int tempInt; tempInt = (int)(newCity -> name); }
    {int tlv1; tlv1 = (int)(newCity -> name); }
    {int tlv2; tlv2 = (int)(newCity -> name); }
    {int tlv3; tlv3 = (int)(newCity -> name); }
    {int tlv4; tlv4 = (int)(newCity -> name); }
    {int tlv5; tlv5 = (int)(newCity -> name); }
    {int tlv6; tlv6 = (int)(newCity -> name); }
    {int tlv7; tlv7 = (int)(newCity -> name); }
    {int tlv16; tlv16 = (int)(newCity -> name); }
    {int * tlv8; tlv8 = (int *)(newCity -> name); }
    {int tlv20; tlv20 = (int)(newCity -> name); }
    {int tlv19; tlv19 = (int)(newCity -> name); }
    {void * tlv11; tlv11 = (void *)(newCity -> name); }
    {cgc_size_t tlv10; tlv10 = (cgc_size_t)(newCity -> name); }
    {char tlv24; tlv24 = (char)(newCity -> name); }
    {cgc_size_t tlv28; tlv28 = (cgc_size_t)(newCity -> name); }
    {int tlv27; tlv27 = (int)(newCity -> name); }
    {int tlv30; tlv30 = (int)(newCity -> name); }
    {int * tlv12; tlv12 = (int *)(newCity -> name); }
    {int tlv34; tlv34 = (int)(newCity -> name); }
    {int tlv33; tlv33 = (int)(newCity -> name); }
    {void * tlv15; tlv15 = (void *)(newCity -> name); }
    {cgc_size_t tlv14; tlv14 = (cgc_size_t)(newCity -> name); }
    {char tlv38; tlv38 = (char)(newCity -> name); }
    {char * tlv72; tlv72 = (char *)(newCity -> name); }
    {char * tlv73; tlv73 = (char *)(newCity -> name); }
    {void * tlv41; tlv41 = (void *)(newCity -> name); }
    {cgc_size_t tlv40; tlv40 = (cgc_size_t)(newCity -> name); }
    {char * tlv46; tlv46 = (char *)(newCity -> name); }
    {void * tlv43; tlv43 = (void *)(newCity -> name); }
    {cgc_size_t tlv42; tlv42 = (cgc_size_t)(newCity -> name); }
    {void * tlv45; tlv45 = (void *)(newCity -> name); }
    {cgc_size_t tlv44; tlv44 = (cgc_size_t)(newCity -> name); }
    {char * tlv74; tlv74 = (char *)(newCity -> name); }
    {char * tlv75; tlv75 = (char *)(newCity -> name); }
    {char * tlv76; tlv76 = (char *)(newCity -> name); }
    {void * tlv49; tlv49 = (void *)(newCity -> name); }
    {cgc_size_t tlv48; tlv48 = (cgc_size_t)(newCity -> name); }
    {char * tlv52; tlv52 = (char *)(newCity -> name); }
    {char * tlv51; tlv51 = (char *)(newCity -> name); }
    {cgc_size_t tlv50; tlv50 = (cgc_size_t)(newCity -> name); }
    {void * tlv54; tlv54 = (void *)(newCity -> name); }
    {cgc_size_t tlv53; tlv53 = (cgc_size_t)(newCity -> name); }
    {void * tlv56; tlv56 = (void *)(newCity -> name); }
    {cgc_size_t tlv55; tlv55 = (cgc_size_t)(newCity -> name); }
    {char * tlv58; tlv58 = (char *)(newCity -> name); }
    {char * tlv57; tlv57 = (char *)(newCity -> name); }
    {void * tlv61; tlv61 = (void *)(newCity -> name); }
    {cgc_size_t tlv60; tlv60 = (cgc_size_t)(newCity -> name); }
    {char * tlv64; tlv64 = (char *)(newCity -> name); }
    {char * tlv63; tlv63 = (char *)(newCity -> name); }
    {cgc_size_t tlv62; tlv62 = (cgc_size_t)(newCity -> name); }
    {char * tlv77; tlv77 = (char *)(newCity -> name); }
}
void fix_ingred_cityParsers_6_30_2(){
City newCity_ref;
    bzero(&newCity_ref,1*sizeof(City));
pCity newCity = &newCity_ref;
    {int lastGood; lastGood = (int)(19); }
    {int startIndex; startIndex = (int)(19); }
    {int endIndex; endIndex = (int)(19); }
    {char * temp; temp = (char *)(19); }
    {int tempInt; tempInt = (int)(19); }
    {int tlv2; tlv2 = (int)(19); }
    {int tlv3; tlv3 = (int)(19); }
    {int tlv4; tlv4 = (int)(19); }
    {int tlv5; tlv5 = (int)(19); }
    {int tlv6; tlv6 = (int)(19); }
    {int tlv7; tlv7 = (int)(19); }
    {int tlv16; tlv16 = (int)(19); }
    {int * tlv8; tlv8 = (int *)(19); }
    {int tlv20; tlv20 = (int)(19); }
    {int tlv19; tlv19 = (int)(19); }
    {int tlv27; tlv27 = (int)(19); }
    {int tlv30; tlv30 = (int)(19); }
    {int * tlv12; tlv12 = (int *)(19); }
    {int tlv34; tlv34 = (int)(19); }
    {int tlv33; tlv33 = (int)(19); }
    {void * tlv15; tlv15 = (void *)(19); }
    {cgc_size_t tlv14; tlv14 = (cgc_size_t)(19); }
    {char tlv38; tlv38 = (char)(19); }
    {char * tlv72; tlv72 = (char *)(19); }
    {char * tlv73; tlv73 = (char *)(19); }
    {void * tlv41; tlv41 = (void *)(19); }
    {char * tlv46; tlv46 = (char *)(19); }
    {void * tlv43; tlv43 = (void *)(19); }
    {cgc_size_t tlv42; tlv42 = (cgc_size_t)(19); }
    {char * tlv74; tlv74 = (char *)(19); }
    {char * tlv75; tlv75 = (char *)(19); }
    {char * tlv76; tlv76 = (char *)(19); }
    {void * tlv49; tlv49 = (void *)(19); }
    {cgc_size_t tlv48; tlv48 = (cgc_size_t)(19); }
    {char * tlv52; tlv52 = (char *)(19); }
    {char * tlv51; tlv51 = (char *)(19); }
    {void * tlv54; tlv54 = (void *)(19); }
    {cgc_size_t tlv53; tlv53 = (cgc_size_t)(19); }
    {void * tlv56; tlv56 = (void *)(19); }
    {cgc_size_t tlv55; tlv55 = (cgc_size_t)(19); }
    {char * tlv58; tlv58 = (char *)(19); }
    {char * tlv57; tlv57 = (char *)(19); }
    {void * tlv61; tlv61 = (void *)(19); }
    {cgc_size_t tlv60; tlv60 = (cgc_size_t)(19); }
    {char * tlv64; tlv64 = (char *)(19); }
    {char * tlv63; tlv63 = (char *)(19); }
    {cgc_size_t tlv62; tlv62 = (cgc_size_t)(19); }
    {char * tlv77; tlv77 = (char *)(19); }
}
void fix_ingred_cityParsers_6_30(){
fix_ingred_cityParsers_6_30_0();
fix_ingred_cityParsers_6_30_2();
}
void fix_ingred_cityParsers_6_32_1(){
char tlv77_ref;
    bzero(&tlv77_ref,1*sizeof(char));
char * tlv77 = &tlv77_ref;
    {int lastGood; lastGood = (int)(cgc_strlen ( tlv77 ) + 1); }
    {int startIndex; startIndex = (int)(cgc_strlen ( tlv77 ) + 1); }
    {int endIndex; endIndex = (int)(cgc_strlen ( tlv77 ) + 1); }
    {char * temp; temp = (char *)(cgc_strlen ( tlv77 ) + 1); }
    {int tempInt; tempInt = (int)(cgc_strlen ( tlv77 ) + 1); }
    {int tlv1; tlv1 = (int)(cgc_strlen ( tlv77 ) + 1); }
    {int tlv2; tlv2 = (int)(cgc_strlen ( tlv77 ) + 1); }
    {int tlv3; tlv3 = (int)(cgc_strlen ( tlv77 ) + 1); }
    {int tlv4; tlv4 = (int)(cgc_strlen ( tlv77 ) + 1); }
    {int tlv5; tlv5 = (int)(cgc_strlen ( tlv77 ) + 1); }
    {int tlv6; tlv6 = (int)(cgc_strlen ( tlv77 ) + 1); }
    {int tlv7; tlv7 = (int)(cgc_strlen ( tlv77 ) + 1); }
    {int tlv16; tlv16 = (int)(cgc_strlen ( tlv77 ) + 1); }
    {int * tlv8; tlv8 = (int *)(cgc_strlen ( tlv77 ) + 1); }
    {int tlv20; tlv20 = (int)(cgc_strlen ( tlv77 ) + 1); }
    {int tlv19; tlv19 = (int)(cgc_strlen ( tlv77 ) + 1); }
    {void * tlv11; tlv11 = (void *)(cgc_strlen ( tlv77 ) + 1); }
    {cgc_size_t tlv10; tlv10 = (cgc_size_t)(cgc_strlen ( tlv77 ) + 1); }
    {char tlv24; tlv24 = (char)(cgc_strlen ( tlv77 ) + 1); }
    {cgc_size_t tlv28; tlv28 = (cgc_size_t)(cgc_strlen ( tlv77 ) + 1); }
    {int tlv27; tlv27 = (int)(cgc_strlen ( tlv77 ) + 1); }
    {int tlv30; tlv30 = (int)(cgc_strlen ( tlv77 ) + 1); }
    {int * tlv12; tlv12 = (int *)(cgc_strlen ( tlv77 ) + 1); }
    {int tlv34; tlv34 = (int)(cgc_strlen ( tlv77 ) + 1); }
    {int tlv33; tlv33 = (int)(cgc_strlen ( tlv77 ) + 1); }
    {void * tlv15; tlv15 = (void *)(cgc_strlen ( tlv77 ) + 1); }
    {cgc_size_t tlv14; tlv14 = (cgc_size_t)(cgc_strlen ( tlv77 ) + 1); }
    {char tlv38; tlv38 = (char)(cgc_strlen ( tlv77 ) + 1); }
    {char * tlv72; tlv72 = (char *)(cgc_strlen ( tlv77 ) + 1); }
    {char * tlv73; tlv73 = (char *)(cgc_strlen ( tlv77 ) + 1); }
    {void * tlv41; tlv41 = (void *)(cgc_strlen ( tlv77 ) + 1); }
    {cgc_size_t tlv40; tlv40 = (cgc_size_t)(cgc_strlen ( tlv77 ) + 1); }
    {char * tlv46; tlv46 = (char *)(cgc_strlen ( tlv77 ) + 1); }
    {void * tlv43; tlv43 = (void *)(cgc_strlen ( tlv77 ) + 1); }
    {cgc_size_t tlv42; tlv42 = (cgc_size_t)(cgc_strlen ( tlv77 ) + 1); }
    {void * tlv45; tlv45 = (void *)(cgc_strlen ( tlv77 ) + 1); }
    {cgc_size_t tlv44; tlv44 = (cgc_size_t)(cgc_strlen ( tlv77 ) + 1); }
    {char * tlv74; tlv74 = (char *)(cgc_strlen ( tlv77 ) + 1); }
    {char * tlv75; tlv75 = (char *)(cgc_strlen ( tlv77 ) + 1); }
    {char * tlv76; tlv76 = (char *)(cgc_strlen ( tlv77 ) + 1); }
    {void * tlv49; tlv49 = (void *)(cgc_strlen ( tlv77 ) + 1); }
    {cgc_size_t tlv48; tlv48 = (cgc_size_t)(cgc_strlen ( tlv77 ) + 1); }
    {char * tlv52; tlv52 = (char *)(cgc_strlen ( tlv77 ) + 1); }
    {char * tlv51; tlv51 = (char *)(cgc_strlen ( tlv77 ) + 1); }
    {cgc_size_t tlv50; tlv50 = (cgc_size_t)(cgc_strlen ( tlv77 ) + 1); }
    {void * tlv54; tlv54 = (void *)(cgc_strlen ( tlv77 ) + 1); }
    {cgc_size_t tlv53; tlv53 = (cgc_size_t)(cgc_strlen ( tlv77 ) + 1); }
    {void * tlv56; tlv56 = (void *)(cgc_strlen ( tlv77 ) + 1); }
    {cgc_size_t tlv55; tlv55 = (cgc_size_t)(cgc_strlen ( tlv77 ) + 1); }
    {char * tlv58; tlv58 = (char *)(cgc_strlen ( tlv77 ) + 1); }
    {char * tlv57; tlv57 = (char *)(cgc_strlen ( tlv77 ) + 1); }
    {void * tlv61; tlv61 = (void *)(cgc_strlen ( tlv77 ) + 1); }
    {cgc_size_t tlv60; tlv60 = (cgc_size_t)(cgc_strlen ( tlv77 ) + 1); }
    {char * tlv64; tlv64 = (char *)(cgc_strlen ( tlv77 ) + 1); }
    {char * tlv63; tlv63 = (char *)(cgc_strlen ( tlv77 ) + 1); }
    {cgc_size_t tlv62; tlv62 = (cgc_size_t)(cgc_strlen ( tlv77 ) + 1); }
}
void fix_ingred_cityParsers_6_32(){
fix_ingred_cityParsers_6_32_1();
}
void fix_ingred_cityParsers_6_36_0(){
City newCity_ref;
    bzero(&newCity_ref,1*sizeof(City));
pCity newCity = &newCity_ref;
    {int lastGood; lastGood = (int)(newCity -> mayor); }
    {int startIndex; startIndex = (int)(newCity -> mayor); }
    {int endIndex; endIndex = (int)(newCity -> mayor); }
    {char * temp; temp = (char *)(newCity -> mayor); }
    {int tempInt; tempInt = (int)(newCity -> mayor); }
    {int tlv1; tlv1 = (int)(newCity -> mayor); }
    {int tlv2; tlv2 = (int)(newCity -> mayor); }
    {int tlv3; tlv3 = (int)(newCity -> mayor); }
    {int tlv4; tlv4 = (int)(newCity -> mayor); }
    {int tlv5; tlv5 = (int)(newCity -> mayor); }
    {int tlv6; tlv6 = (int)(newCity -> mayor); }
    {int tlv7; tlv7 = (int)(newCity -> mayor); }
    {int tlv16; tlv16 = (int)(newCity -> mayor); }
    {int * tlv8; tlv8 = (int *)(newCity -> mayor); }
    {int tlv20; tlv20 = (int)(newCity -> mayor); }
    {int tlv19; tlv19 = (int)(newCity -> mayor); }
    {void * tlv11; tlv11 = (void *)(newCity -> mayor); }
    {cgc_size_t tlv10; tlv10 = (cgc_size_t)(newCity -> mayor); }
    {char tlv24; tlv24 = (char)(newCity -> mayor); }
    {cgc_size_t tlv28; tlv28 = (cgc_size_t)(newCity -> mayor); }
    {int tlv27; tlv27 = (int)(newCity -> mayor); }
    {int tlv30; tlv30 = (int)(newCity -> mayor); }
    {int * tlv12; tlv12 = (int *)(newCity -> mayor); }
    {int tlv34; tlv34 = (int)(newCity -> mayor); }
    {int tlv33; tlv33 = (int)(newCity -> mayor); }
    {void * tlv15; tlv15 = (void *)(newCity -> mayor); }
    {cgc_size_t tlv14; tlv14 = (cgc_size_t)(newCity -> mayor); }
    {char tlv38; tlv38 = (char)(newCity -> mayor); }
    {char * tlv72; tlv72 = (char *)(newCity -> mayor); }
    {char * tlv73; tlv73 = (char *)(newCity -> mayor); }
    {void * tlv41; tlv41 = (void *)(newCity -> mayor); }
    {cgc_size_t tlv40; tlv40 = (cgc_size_t)(newCity -> mayor); }
    {char * tlv46; tlv46 = (char *)(newCity -> mayor); }
    {void * tlv43; tlv43 = (void *)(newCity -> mayor); }
    {cgc_size_t tlv42; tlv42 = (cgc_size_t)(newCity -> mayor); }
    {void * tlv45; tlv45 = (void *)(newCity -> mayor); }
    {cgc_size_t tlv44; tlv44 = (cgc_size_t)(newCity -> mayor); }
    {char * tlv74; tlv74 = (char *)(newCity -> mayor); }
    {char * tlv75; tlv75 = (char *)(newCity -> mayor); }
    {char * tlv76; tlv76 = (char *)(newCity -> mayor); }
    {void * tlv49; tlv49 = (void *)(newCity -> mayor); }
    {cgc_size_t tlv48; tlv48 = (cgc_size_t)(newCity -> mayor); }
    {char * tlv52; tlv52 = (char *)(newCity -> mayor); }
    {char * tlv51; tlv51 = (char *)(newCity -> mayor); }
    {cgc_size_t tlv50; tlv50 = (cgc_size_t)(newCity -> mayor); }
    {void * tlv54; tlv54 = (void *)(newCity -> mayor); }
    {cgc_size_t tlv53; tlv53 = (cgc_size_t)(newCity -> mayor); }
    {void * tlv56; tlv56 = (void *)(newCity -> mayor); }
    {cgc_size_t tlv55; tlv55 = (cgc_size_t)(newCity -> mayor); }
    {char * tlv58; tlv58 = (char *)(newCity -> mayor); }
    {char * tlv57; tlv57 = (char *)(newCity -> mayor); }
    {void * tlv61; tlv61 = (void *)(newCity -> mayor); }
    {cgc_size_t tlv60; tlv60 = (cgc_size_t)(newCity -> mayor); }
    {char * tlv64; tlv64 = (char *)(newCity -> mayor); }
    {char * tlv63; tlv63 = (char *)(newCity -> mayor); }
    {cgc_size_t tlv62; tlv62 = (cgc_size_t)(newCity -> mayor); }
    {char * tlv77; tlv77 = (char *)(newCity -> mayor); }
}
void fix_ingred_cityParsers_6_36_1(){
City newCity_ref;
    bzero(&newCity_ref,1*sizeof(City));
pCity newCity = &newCity_ref;
    {int lastGood; lastGood = (int)(30); }
    {int startIndex; startIndex = (int)(30); }
    {int endIndex; endIndex = (int)(30); }
    {char * temp; temp = (char *)(30); }
    {int tempInt; tempInt = (int)(30); }
    {int tlv2; tlv2 = (int)(30); }
    {int tlv3; tlv3 = (int)(30); }
    {int tlv4; tlv4 = (int)(30); }
    {int tlv5; tlv5 = (int)(30); }
    {int tlv6; tlv6 = (int)(30); }
    {int tlv7; tlv7 = (int)(30); }
    {int tlv16; tlv16 = (int)(30); }
    {int * tlv8; tlv8 = (int *)(30); }
    {int tlv20; tlv20 = (int)(30); }
    {int tlv19; tlv19 = (int)(30); }
    {int tlv27; tlv27 = (int)(30); }
    {int tlv30; tlv30 = (int)(30); }
    {int * tlv12; tlv12 = (int *)(30); }
    {int tlv34; tlv34 = (int)(30); }
    {int tlv33; tlv33 = (int)(30); }
    {void * tlv15; tlv15 = (void *)(30); }
    {cgc_size_t tlv14; tlv14 = (cgc_size_t)(30); }
    {char tlv38; tlv38 = (char)(30); }
    {char * tlv72; tlv72 = (char *)(30); }
    {char * tlv73; tlv73 = (char *)(30); }
    {void * tlv41; tlv41 = (void *)(30); }
    {char * tlv46; tlv46 = (char *)(30); }
    {void * tlv43; tlv43 = (void *)(30); }
    {cgc_size_t tlv42; tlv42 = (cgc_size_t)(30); }
    {char * tlv74; tlv74 = (char *)(30); }
    {char * tlv75; tlv75 = (char *)(30); }
    {char * tlv76; tlv76 = (char *)(30); }
    {void * tlv49; tlv49 = (void *)(30); }
    {cgc_size_t tlv48; tlv48 = (cgc_size_t)(30); }
    {char * tlv52; tlv52 = (char *)(30); }
    {char * tlv51; tlv51 = (char *)(30); }
    {void * tlv54; tlv54 = (void *)(30); }
    {cgc_size_t tlv53; tlv53 = (cgc_size_t)(30); }
    {void * tlv56; tlv56 = (void *)(30); }
    {cgc_size_t tlv55; tlv55 = (cgc_size_t)(30); }
    {char * tlv58; tlv58 = (char *)(30); }
    {char * tlv57; tlv57 = (char *)(30); }
    {void * tlv61; tlv61 = (void *)(30); }
    {cgc_size_t tlv60; tlv60 = (cgc_size_t)(30); }
    {char * tlv64; tlv64 = (char *)(30); }
    {char * tlv63; tlv63 = (char *)(30); }
    {cgc_size_t tlv62; tlv62 = (cgc_size_t)(30); }
    {char * tlv77; tlv77 = (char *)(30); }
}
void fix_ingred_cityParsers_6_36(){
fix_ingred_cityParsers_6_36_0();
fix_ingred_cityParsers_6_36_1();
}
void fix_ingred_cityParsers_6_37_0(){
City newCity_ref;
    bzero(&newCity_ref,1*sizeof(City));
pCity newCity = &newCity_ref;
    {int lastGood; lastGood = (int)(newCity -> mayor); }
    {int startIndex; startIndex = (int)(newCity -> mayor); }
    {int endIndex; endIndex = (int)(newCity -> mayor); }
    {char * temp; temp = (char *)(newCity -> mayor); }
    {int tempInt; tempInt = (int)(newCity -> mayor); }
    {int tlv1; tlv1 = (int)(newCity -> mayor); }
    {int tlv2; tlv2 = (int)(newCity -> mayor); }
    {int tlv3; tlv3 = (int)(newCity -> mayor); }
    {int tlv4; tlv4 = (int)(newCity -> mayor); }
    {int tlv5; tlv5 = (int)(newCity -> mayor); }
    {int tlv6; tlv6 = (int)(newCity -> mayor); }
    {int tlv7; tlv7 = (int)(newCity -> mayor); }
    {int tlv16; tlv16 = (int)(newCity -> mayor); }
    {int * tlv8; tlv8 = (int *)(newCity -> mayor); }
    {int tlv20; tlv20 = (int)(newCity -> mayor); }
    {int tlv19; tlv19 = (int)(newCity -> mayor); }
    {void * tlv11; tlv11 = (void *)(newCity -> mayor); }
    {cgc_size_t tlv10; tlv10 = (cgc_size_t)(newCity -> mayor); }
    {char tlv24; tlv24 = (char)(newCity -> mayor); }
    {cgc_size_t tlv28; tlv28 = (cgc_size_t)(newCity -> mayor); }
    {int tlv27; tlv27 = (int)(newCity -> mayor); }
    {int tlv30; tlv30 = (int)(newCity -> mayor); }
    {int * tlv12; tlv12 = (int *)(newCity -> mayor); }
    {int tlv34; tlv34 = (int)(newCity -> mayor); }
    {int tlv33; tlv33 = (int)(newCity -> mayor); }
    {void * tlv15; tlv15 = (void *)(newCity -> mayor); }
    {cgc_size_t tlv14; tlv14 = (cgc_size_t)(newCity -> mayor); }
    {char tlv38; tlv38 = (char)(newCity -> mayor); }
    {char * tlv72; tlv72 = (char *)(newCity -> mayor); }
    {char * tlv73; tlv73 = (char *)(newCity -> mayor); }
    {void * tlv41; tlv41 = (void *)(newCity -> mayor); }
    {cgc_size_t tlv40; tlv40 = (cgc_size_t)(newCity -> mayor); }
    {char * tlv46; tlv46 = (char *)(newCity -> mayor); }
    {void * tlv43; tlv43 = (void *)(newCity -> mayor); }
    {cgc_size_t tlv42; tlv42 = (cgc_size_t)(newCity -> mayor); }
    {void * tlv45; tlv45 = (void *)(newCity -> mayor); }
    {cgc_size_t tlv44; tlv44 = (cgc_size_t)(newCity -> mayor); }
    {char * tlv74; tlv74 = (char *)(newCity -> mayor); }
    {char * tlv75; tlv75 = (char *)(newCity -> mayor); }
    {char * tlv76; tlv76 = (char *)(newCity -> mayor); }
    {void * tlv49; tlv49 = (void *)(newCity -> mayor); }
    {cgc_size_t tlv48; tlv48 = (cgc_size_t)(newCity -> mayor); }
    {char * tlv52; tlv52 = (char *)(newCity -> mayor); }
    {char * tlv51; tlv51 = (char *)(newCity -> mayor); }
    {cgc_size_t tlv50; tlv50 = (cgc_size_t)(newCity -> mayor); }
    {void * tlv54; tlv54 = (void *)(newCity -> mayor); }
    {cgc_size_t tlv53; tlv53 = (cgc_size_t)(newCity -> mayor); }
    {void * tlv56; tlv56 = (void *)(newCity -> mayor); }
    {cgc_size_t tlv55; tlv55 = (cgc_size_t)(newCity -> mayor); }
    {char * tlv58; tlv58 = (char *)(newCity -> mayor); }
    {char * tlv57; tlv57 = (char *)(newCity -> mayor); }
    {void * tlv61; tlv61 = (void *)(newCity -> mayor); }
    {cgc_size_t tlv60; tlv60 = (cgc_size_t)(newCity -> mayor); }
    {char * tlv64; tlv64 = (char *)(newCity -> mayor); }
    {char * tlv63; tlv63 = (char *)(newCity -> mayor); }
    {cgc_size_t tlv62; tlv62 = (cgc_size_t)(newCity -> mayor); }
    {char * tlv77; tlv77 = (char *)(newCity -> mayor); }
}
void fix_ingred_cityParsers_6_37(){
fix_ingred_cityParsers_6_37_0();
}
void fix_ingred_cityParsers_6_42_0(){
City newCity_ref;
    bzero(&newCity_ref,1*sizeof(City));
pCity newCity = &newCity_ref;
    {int lastGood; lastGood = (int)(newCity -> url); }
    {int startIndex; startIndex = (int)(newCity -> url); }
    {int endIndex; endIndex = (int)(newCity -> url); }
    {char * temp; temp = (char *)(newCity -> url); }
    {int tempInt; tempInt = (int)(newCity -> url); }
    {int tlv1; tlv1 = (int)(newCity -> url); }
    {int tlv2; tlv2 = (int)(newCity -> url); }
    {int tlv3; tlv3 = (int)(newCity -> url); }
    {int tlv4; tlv4 = (int)(newCity -> url); }
    {int tlv5; tlv5 = (int)(newCity -> url); }
    {int tlv6; tlv6 = (int)(newCity -> url); }
    {int tlv7; tlv7 = (int)(newCity -> url); }
    {int tlv16; tlv16 = (int)(newCity -> url); }
    {int * tlv8; tlv8 = (int *)(newCity -> url); }
    {int tlv20; tlv20 = (int)(newCity -> url); }
    {int tlv19; tlv19 = (int)(newCity -> url); }
    {void * tlv11; tlv11 = (void *)(newCity -> url); }
    {cgc_size_t tlv10; tlv10 = (cgc_size_t)(newCity -> url); }
    {char tlv24; tlv24 = (char)(newCity -> url); }
    {cgc_size_t tlv28; tlv28 = (cgc_size_t)(newCity -> url); }
    {int tlv27; tlv27 = (int)(newCity -> url); }
    {int tlv30; tlv30 = (int)(newCity -> url); }
    {int * tlv12; tlv12 = (int *)(newCity -> url); }
    {int tlv34; tlv34 = (int)(newCity -> url); }
    {int tlv33; tlv33 = (int)(newCity -> url); }
    {void * tlv15; tlv15 = (void *)(newCity -> url); }
    {cgc_size_t tlv14; tlv14 = (cgc_size_t)(newCity -> url); }
    {char tlv38; tlv38 = (char)(newCity -> url); }
    {char * tlv72; tlv72 = (char *)(newCity -> url); }
    {char * tlv73; tlv73 = (char *)(newCity -> url); }
    {void * tlv41; tlv41 = (void *)(newCity -> url); }
    {cgc_size_t tlv40; tlv40 = (cgc_size_t)(newCity -> url); }
    {char * tlv46; tlv46 = (char *)(newCity -> url); }
    {void * tlv43; tlv43 = (void *)(newCity -> url); }
    {cgc_size_t tlv42; tlv42 = (cgc_size_t)(newCity -> url); }
    {void * tlv45; tlv45 = (void *)(newCity -> url); }
    {cgc_size_t tlv44; tlv44 = (cgc_size_t)(newCity -> url); }
    {char * tlv74; tlv74 = (char *)(newCity -> url); }
    {char * tlv75; tlv75 = (char *)(newCity -> url); }
    {char * tlv76; tlv76 = (char *)(newCity -> url); }
    {void * tlv49; tlv49 = (void *)(newCity -> url); }
    {cgc_size_t tlv48; tlv48 = (cgc_size_t)(newCity -> url); }
    {char * tlv52; tlv52 = (char *)(newCity -> url); }
    {char * tlv51; tlv51 = (char *)(newCity -> url); }
    {cgc_size_t tlv50; tlv50 = (cgc_size_t)(newCity -> url); }
    {void * tlv54; tlv54 = (void *)(newCity -> url); }
    {cgc_size_t tlv53; tlv53 = (cgc_size_t)(newCity -> url); }
    {void * tlv56; tlv56 = (void *)(newCity -> url); }
    {cgc_size_t tlv55; tlv55 = (cgc_size_t)(newCity -> url); }
    {char * tlv58; tlv58 = (char *)(newCity -> url); }
    {char * tlv57; tlv57 = (char *)(newCity -> url); }
    {void * tlv61; tlv61 = (void *)(newCity -> url); }
    {cgc_size_t tlv60; tlv60 = (cgc_size_t)(newCity -> url); }
    {char * tlv64; tlv64 = (char *)(newCity -> url); }
    {char * tlv63; tlv63 = (char *)(newCity -> url); }
    {cgc_size_t tlv62; tlv62 = (cgc_size_t)(newCity -> url); }
    {char * tlv77; tlv77 = (char *)(newCity -> url); }
}
void fix_ingred_cityParsers_6_42(){
fix_ingred_cityParsers_6_42_0();
}
void fix_ingred_cityParsers_6_43_0(){
City newCity_ref;
    bzero(&newCity_ref,1*sizeof(City));
pCity newCity = &newCity_ref;
    {int lastGood; lastGood = (int)(newCity -> url); }
    {int startIndex; startIndex = (int)(newCity -> url); }
    {int endIndex; endIndex = (int)(newCity -> url); }
    {char * temp; temp = (char *)(newCity -> url); }
    {int tempInt; tempInt = (int)(newCity -> url); }
    {int tlv1; tlv1 = (int)(newCity -> url); }
    {int tlv2; tlv2 = (int)(newCity -> url); }
    {int tlv3; tlv3 = (int)(newCity -> url); }
    {int tlv4; tlv4 = (int)(newCity -> url); }
    {int tlv5; tlv5 = (int)(newCity -> url); }
    {int tlv6; tlv6 = (int)(newCity -> url); }
    {int tlv7; tlv7 = (int)(newCity -> url); }
    {int tlv16; tlv16 = (int)(newCity -> url); }
    {int * tlv8; tlv8 = (int *)(newCity -> url); }
    {int tlv20; tlv20 = (int)(newCity -> url); }
    {int tlv19; tlv19 = (int)(newCity -> url); }
    {void * tlv11; tlv11 = (void *)(newCity -> url); }
    {cgc_size_t tlv10; tlv10 = (cgc_size_t)(newCity -> url); }
    {char tlv24; tlv24 = (char)(newCity -> url); }
    {cgc_size_t tlv28; tlv28 = (cgc_size_t)(newCity -> url); }
    {int tlv27; tlv27 = (int)(newCity -> url); }
    {int tlv30; tlv30 = (int)(newCity -> url); }
    {int * tlv12; tlv12 = (int *)(newCity -> url); }
    {int tlv34; tlv34 = (int)(newCity -> url); }
    {int tlv33; tlv33 = (int)(newCity -> url); }
    {void * tlv15; tlv15 = (void *)(newCity -> url); }
    {cgc_size_t tlv14; tlv14 = (cgc_size_t)(newCity -> url); }
    {char tlv38; tlv38 = (char)(newCity -> url); }
    {char * tlv72; tlv72 = (char *)(newCity -> url); }
    {char * tlv73; tlv73 = (char *)(newCity -> url); }
    {void * tlv41; tlv41 = (void *)(newCity -> url); }
    {cgc_size_t tlv40; tlv40 = (cgc_size_t)(newCity -> url); }
    {char * tlv46; tlv46 = (char *)(newCity -> url); }
    {void * tlv43; tlv43 = (void *)(newCity -> url); }
    {cgc_size_t tlv42; tlv42 = (cgc_size_t)(newCity -> url); }
    {void * tlv45; tlv45 = (void *)(newCity -> url); }
    {cgc_size_t tlv44; tlv44 = (cgc_size_t)(newCity -> url); }
    {char * tlv74; tlv74 = (char *)(newCity -> url); }
    {char * tlv75; tlv75 = (char *)(newCity -> url); }
    {char * tlv76; tlv76 = (char *)(newCity -> url); }
    {void * tlv49; tlv49 = (void *)(newCity -> url); }
    {cgc_size_t tlv48; tlv48 = (cgc_size_t)(newCity -> url); }
    {char * tlv52; tlv52 = (char *)(newCity -> url); }
    {char * tlv51; tlv51 = (char *)(newCity -> url); }
    {cgc_size_t tlv50; tlv50 = (cgc_size_t)(newCity -> url); }
    {void * tlv54; tlv54 = (void *)(newCity -> url); }
    {cgc_size_t tlv53; tlv53 = (cgc_size_t)(newCity -> url); }
    {void * tlv56; tlv56 = (void *)(newCity -> url); }
    {cgc_size_t tlv55; tlv55 = (cgc_size_t)(newCity -> url); }
    {char * tlv58; tlv58 = (char *)(newCity -> url); }
    {char * tlv57; tlv57 = (char *)(newCity -> url); }
    {void * tlv61; tlv61 = (void *)(newCity -> url); }
    {cgc_size_t tlv60; tlv60 = (cgc_size_t)(newCity -> url); }
    {char * tlv64; tlv64 = (char *)(newCity -> url); }
    {char * tlv63; tlv63 = (char *)(newCity -> url); }
    {cgc_size_t tlv62; tlv62 = (cgc_size_t)(newCity -> url); }
    {char * tlv77; tlv77 = (char *)(newCity -> url); }
}
void fix_ingred_cityParsers_6_43_2(){
City newCity_ref;
    bzero(&newCity_ref,1*sizeof(City));
pCity newCity = &newCity_ref;
    {int lastGood; lastGood = (int)(29); }
    {int startIndex; startIndex = (int)(29); }
    {int endIndex; endIndex = (int)(29); }
    {char * temp; temp = (char *)(29); }
    {int tempInt; tempInt = (int)(29); }
    {int tlv2; tlv2 = (int)(29); }
    {int tlv3; tlv3 = (int)(29); }
    {int tlv4; tlv4 = (int)(29); }
    {int tlv5; tlv5 = (int)(29); }
    {int tlv6; tlv6 = (int)(29); }
    {int tlv7; tlv7 = (int)(29); }
    {int tlv16; tlv16 = (int)(29); }
    {int * tlv8; tlv8 = (int *)(29); }
    {int tlv20; tlv20 = (int)(29); }
    {int tlv19; tlv19 = (int)(29); }
    {int tlv27; tlv27 = (int)(29); }
    {int tlv30; tlv30 = (int)(29); }
    {int * tlv12; tlv12 = (int *)(29); }
    {int tlv34; tlv34 = (int)(29); }
    {int tlv33; tlv33 = (int)(29); }
    {void * tlv15; tlv15 = (void *)(29); }
    {cgc_size_t tlv14; tlv14 = (cgc_size_t)(29); }
    {char tlv38; tlv38 = (char)(29); }
    {char * tlv72; tlv72 = (char *)(29); }
    {char * tlv73; tlv73 = (char *)(29); }
    {void * tlv41; tlv41 = (void *)(29); }
    {char * tlv46; tlv46 = (char *)(29); }
    {void * tlv43; tlv43 = (void *)(29); }
    {cgc_size_t tlv42; tlv42 = (cgc_size_t)(29); }
    {char * tlv74; tlv74 = (char *)(29); }
    {char * tlv75; tlv75 = (char *)(29); }
    {char * tlv76; tlv76 = (char *)(29); }
    {void * tlv49; tlv49 = (void *)(29); }
    {cgc_size_t tlv48; tlv48 = (cgc_size_t)(29); }
    {char * tlv52; tlv52 = (char *)(29); }
    {char * tlv51; tlv51 = (char *)(29); }
    {void * tlv54; tlv54 = (void *)(29); }
    {cgc_size_t tlv53; tlv53 = (cgc_size_t)(29); }
    {void * tlv56; tlv56 = (void *)(29); }
    {cgc_size_t tlv55; tlv55 = (cgc_size_t)(29); }
    {char * tlv58; tlv58 = (char *)(29); }
    {char * tlv57; tlv57 = (char *)(29); }
    {void * tlv61; tlv61 = (void *)(29); }
    {cgc_size_t tlv60; tlv60 = (cgc_size_t)(29); }
    {char * tlv64; tlv64 = (char *)(29); }
    {char * tlv63; tlv63 = (char *)(29); }
    {cgc_size_t tlv62; tlv62 = (cgc_size_t)(29); }
    {char * tlv77; tlv77 = (char *)(29); }
}
void fix_ingred_cityParsers_6_43(){
fix_ingred_cityParsers_6_43_0();
fix_ingred_cityParsers_6_43_2();
}
void fix_ingred_cityParsers_6_55_1(){
    {int lastGood; lastGood = (int)(1); }
    {int startIndex; startIndex = (int)(1); }
    {int endIndex; endIndex = (int)(1); }
    {char * temp; temp = (char *)(1); }
    {int tempInt; tempInt = (int)(1); }
    {int tlv1; tlv1 = (int)(1); }
    {int tlv2; tlv2 = (int)(1); }
    {int tlv3; tlv3 = (int)(1); }
    {int tlv4; tlv4 = (int)(1); }
    {int tlv5; tlv5 = (int)(1); }
    {int tlv6; tlv6 = (int)(1); }
    {int tlv7; tlv7 = (int)(1); }
    {int tlv16; tlv16 = (int)(1); }
    {int * tlv8; tlv8 = (int *)(1); }
    {int tlv20; tlv20 = (int)(1); }
    {int tlv19; tlv19 = (int)(1); }
    {void * tlv11; tlv11 = (void *)(1); }
    {cgc_size_t tlv10; tlv10 = (cgc_size_t)(1); }
    {char tlv24; tlv24 = (char)(1); }
    {cgc_size_t tlv28; tlv28 = (cgc_size_t)(1); }
    {int tlv27; tlv27 = (int)(1); }
    {int tlv30; tlv30 = (int)(1); }
    {int * tlv12; tlv12 = (int *)(1); }
    {int tlv34; tlv34 = (int)(1); }
    {int tlv33; tlv33 = (int)(1); }
    {void * tlv15; tlv15 = (void *)(1); }
    {cgc_size_t tlv14; tlv14 = (cgc_size_t)(1); }
    {char tlv38; tlv38 = (char)(1); }
    {char * tlv72; tlv72 = (char *)(1); }
    {char * tlv73; tlv73 = (char *)(1); }
    {void * tlv41; tlv41 = (void *)(1); }
    {cgc_size_t tlv40; tlv40 = (cgc_size_t)(1); }
    {char * tlv46; tlv46 = (char *)(1); }
    {void * tlv43; tlv43 = (void *)(1); }
    {cgc_size_t tlv42; tlv42 = (cgc_size_t)(1); }
    {void * tlv45; tlv45 = (void *)(1); }
    {cgc_size_t tlv44; tlv44 = (cgc_size_t)(1); }
    {char * tlv74; tlv74 = (char *)(1); }
    {char * tlv75; tlv75 = (char *)(1); }
    {char * tlv76; tlv76 = (char *)(1); }
    {void * tlv49; tlv49 = (void *)(1); }
    {cgc_size_t tlv48; tlv48 = (cgc_size_t)(1); }
    {char * tlv52; tlv52 = (char *)(1); }
    {char * tlv51; tlv51 = (char *)(1); }
    {cgc_size_t tlv50; tlv50 = (cgc_size_t)(1); }
    {void * tlv54; tlv54 = (void *)(1); }
    {cgc_size_t tlv53; tlv53 = (cgc_size_t)(1); }
    {void * tlv56; tlv56 = (void *)(1); }
    {cgc_size_t tlv55; tlv55 = (cgc_size_t)(1); }
    {char * tlv58; tlv58 = (char *)(1); }
    {char * tlv57; tlv57 = (char *)(1); }
    {void * tlv61; tlv61 = (void *)(1); }
    {cgc_size_t tlv60; tlv60 = (cgc_size_t)(1); }
    {char * tlv64; tlv64 = (char *)(1); }
    {char * tlv63; tlv63 = (char *)(1); }
    {cgc_size_t tlv62; tlv62 = (cgc_size_t)(1); }
    {char * tlv77; tlv77 = (char *)(1); }
}
void fix_ingred_cityParsers_6_55(){
fix_ingred_cityParsers_6_55_1();
}
void fix_ingred_cityParsers_6_56_7(){
int tlv5;
    bzero(&tlv5,sizeof(int));
    {int lastGood; lastGood = (int)(tlv5); }
    {int startIndex; startIndex = (int)(tlv5); }
    {int endIndex; endIndex = (int)(tlv5); }
    {char * temp; temp = (char *)(tlv5); }
    {int tempInt; tempInt = (int)(tlv5); }
    {int tlv1; tlv1 = (int)(tlv5); }
    {int tlv2; tlv2 = (int)(tlv5); }
    {int tlv3; tlv3 = (int)(tlv5); }
    {int tlv4; tlv4 = (int)(tlv5); }
    {int tlv6; tlv6 = (int)(tlv5); }
    {int tlv7; tlv7 = (int)(tlv5); }
    {int tlv16; tlv16 = (int)(tlv5); }
    {int * tlv8; tlv8 = (int *)(tlv5); }
    {int tlv20; tlv20 = (int)(tlv5); }
    {int tlv19; tlv19 = (int)(tlv5); }
    {void * tlv11; tlv11 = (void *)(tlv5); }
    {cgc_size_t tlv10; tlv10 = (cgc_size_t)(tlv5); }
    {char tlv24; tlv24 = (char)(tlv5); }
    {cgc_size_t tlv28; tlv28 = (cgc_size_t)(tlv5); }
    {int tlv27; tlv27 = (int)(tlv5); }
    {int tlv30; tlv30 = (int)(tlv5); }
    {int * tlv12; tlv12 = (int *)(tlv5); }
    {int tlv34; tlv34 = (int)(tlv5); }
    {int tlv33; tlv33 = (int)(tlv5); }
    {void * tlv15; tlv15 = (void *)(tlv5); }
    {cgc_size_t tlv14; tlv14 = (cgc_size_t)(tlv5); }
    {char tlv38; tlv38 = (char)(tlv5); }
    {char * tlv72; tlv72 = (char *)(tlv5); }
    {char * tlv73; tlv73 = (char *)(tlv5); }
    {void * tlv41; tlv41 = (void *)(tlv5); }
    {cgc_size_t tlv40; tlv40 = (cgc_size_t)(tlv5); }
    {char * tlv46; tlv46 = (char *)(tlv5); }
    {void * tlv43; tlv43 = (void *)(tlv5); }
    {cgc_size_t tlv42; tlv42 = (cgc_size_t)(tlv5); }
    {void * tlv45; tlv45 = (void *)(tlv5); }
    {cgc_size_t tlv44; tlv44 = (cgc_size_t)(tlv5); }
    {char * tlv74; tlv74 = (char *)(tlv5); }
    {char * tlv75; tlv75 = (char *)(tlv5); }
    {char * tlv76; tlv76 = (char *)(tlv5); }
    {void * tlv49; tlv49 = (void *)(tlv5); }
    {cgc_size_t tlv48; tlv48 = (cgc_size_t)(tlv5); }
    {char * tlv52; tlv52 = (char *)(tlv5); }
    {char * tlv51; tlv51 = (char *)(tlv5); }
    {cgc_size_t tlv50; tlv50 = (cgc_size_t)(tlv5); }
    {void * tlv54; tlv54 = (void *)(tlv5); }
    {cgc_size_t tlv53; tlv53 = (cgc_size_t)(tlv5); }
    {void * tlv56; tlv56 = (void *)(tlv5); }
    {cgc_size_t tlv55; tlv55 = (cgc_size_t)(tlv5); }
    {char * tlv58; tlv58 = (char *)(tlv5); }
    {char * tlv57; tlv57 = (char *)(tlv5); }
    {void * tlv61; tlv61 = (void *)(tlv5); }
    {cgc_size_t tlv60; tlv60 = (cgc_size_t)(tlv5); }
    {char * tlv64; tlv64 = (char *)(tlv5); }
    {char * tlv63; tlv63 = (char *)(tlv5); }
    {cgc_size_t tlv62; tlv62 = (cgc_size_t)(tlv5); }
    {char * tlv77; tlv77 = (char *)(tlv5); }
}
void fix_ingred_cityParsers_6_56(){
fix_ingred_cityParsers_6_56_7();
}
void fix_ingred_cityParsers_6_65_7(){
int tlv6;
    bzero(&tlv6,sizeof(int));
    {int lastGood; lastGood = (int)(tlv6); }
    {int startIndex; startIndex = (int)(tlv6); }
    {int endIndex; endIndex = (int)(tlv6); }
    {char * temp; temp = (char *)(tlv6); }
    {int tempInt; tempInt = (int)(tlv6); }
    {int tlv1; tlv1 = (int)(tlv6); }
    {int tlv2; tlv2 = (int)(tlv6); }
    {int tlv3; tlv3 = (int)(tlv6); }
    {int tlv4; tlv4 = (int)(tlv6); }
    {int tlv5; tlv5 = (int)(tlv6); }
    {int tlv7; tlv7 = (int)(tlv6); }
    {int tlv16; tlv16 = (int)(tlv6); }
    {int * tlv8; tlv8 = (int *)(tlv6); }
    {int tlv20; tlv20 = (int)(tlv6); }
    {int tlv19; tlv19 = (int)(tlv6); }
    {void * tlv11; tlv11 = (void *)(tlv6); }
    {cgc_size_t tlv10; tlv10 = (cgc_size_t)(tlv6); }
    {char tlv24; tlv24 = (char)(tlv6); }
    {cgc_size_t tlv28; tlv28 = (cgc_size_t)(tlv6); }
    {int tlv27; tlv27 = (int)(tlv6); }
    {int tlv30; tlv30 = (int)(tlv6); }
    {int * tlv12; tlv12 = (int *)(tlv6); }
    {int tlv34; tlv34 = (int)(tlv6); }
    {int tlv33; tlv33 = (int)(tlv6); }
    {void * tlv15; tlv15 = (void *)(tlv6); }
    {cgc_size_t tlv14; tlv14 = (cgc_size_t)(tlv6); }
    {char tlv38; tlv38 = (char)(tlv6); }
    {char * tlv72; tlv72 = (char *)(tlv6); }
    {char * tlv73; tlv73 = (char *)(tlv6); }
    {void * tlv41; tlv41 = (void *)(tlv6); }
    {cgc_size_t tlv40; tlv40 = (cgc_size_t)(tlv6); }
    {char * tlv46; tlv46 = (char *)(tlv6); }
    {void * tlv43; tlv43 = (void *)(tlv6); }
    {cgc_size_t tlv42; tlv42 = (cgc_size_t)(tlv6); }
    {void * tlv45; tlv45 = (void *)(tlv6); }
    {cgc_size_t tlv44; tlv44 = (cgc_size_t)(tlv6); }
    {char * tlv74; tlv74 = (char *)(tlv6); }
    {char * tlv75; tlv75 = (char *)(tlv6); }
    {char * tlv76; tlv76 = (char *)(tlv6); }
    {void * tlv49; tlv49 = (void *)(tlv6); }
    {cgc_size_t tlv48; tlv48 = (cgc_size_t)(tlv6); }
    {char * tlv52; tlv52 = (char *)(tlv6); }
    {char * tlv51; tlv51 = (char *)(tlv6); }
    {cgc_size_t tlv50; tlv50 = (cgc_size_t)(tlv6); }
    {void * tlv54; tlv54 = (void *)(tlv6); }
    {cgc_size_t tlv53; tlv53 = (cgc_size_t)(tlv6); }
    {void * tlv56; tlv56 = (void *)(tlv6); }
    {cgc_size_t tlv55; tlv55 = (cgc_size_t)(tlv6); }
    {char * tlv58; tlv58 = (char *)(tlv6); }
    {char * tlv57; tlv57 = (char *)(tlv6); }
    {void * tlv61; tlv61 = (void *)(tlv6); }
    {cgc_size_t tlv60; tlv60 = (cgc_size_t)(tlv6); }
    {char * tlv64; tlv64 = (char *)(tlv6); }
    {char * tlv63; tlv63 = (char *)(tlv6); }
    {cgc_size_t tlv62; tlv62 = (cgc_size_t)(tlv6); }
    {char * tlv77; tlv77 = (char *)(tlv6); }
}
void fix_ingred_cityParsers_6_65(){
fix_ingred_cityParsers_6_65_7();
}
void fix_ingred_cityParsers_6_67_1(){
char tlv76_ref;
    bzero(&tlv76_ref,1*sizeof(char));
char * tlv76 = &tlv76_ref;
    {int lastGood; lastGood = (int)(cgc_strlen ( tlv76 ) + 1); }
    {int startIndex; startIndex = (int)(cgc_strlen ( tlv76 ) + 1); }
    {int endIndex; endIndex = (int)(cgc_strlen ( tlv76 ) + 1); }
    {char * temp; temp = (char *)(cgc_strlen ( tlv76 ) + 1); }
    {int tempInt; tempInt = (int)(cgc_strlen ( tlv76 ) + 1); }
    {int tlv1; tlv1 = (int)(cgc_strlen ( tlv76 ) + 1); }
    {int tlv2; tlv2 = (int)(cgc_strlen ( tlv76 ) + 1); }
    {int tlv3; tlv3 = (int)(cgc_strlen ( tlv76 ) + 1); }
    {int tlv4; tlv4 = (int)(cgc_strlen ( tlv76 ) + 1); }
    {int tlv5; tlv5 = (int)(cgc_strlen ( tlv76 ) + 1); }
    {int tlv6; tlv6 = (int)(cgc_strlen ( tlv76 ) + 1); }
    {int tlv7; tlv7 = (int)(cgc_strlen ( tlv76 ) + 1); }
    {int tlv16; tlv16 = (int)(cgc_strlen ( tlv76 ) + 1); }
    {int * tlv8; tlv8 = (int *)(cgc_strlen ( tlv76 ) + 1); }
    {int tlv20; tlv20 = (int)(cgc_strlen ( tlv76 ) + 1); }
    {int tlv19; tlv19 = (int)(cgc_strlen ( tlv76 ) + 1); }
    {void * tlv11; tlv11 = (void *)(cgc_strlen ( tlv76 ) + 1); }
    {cgc_size_t tlv10; tlv10 = (cgc_size_t)(cgc_strlen ( tlv76 ) + 1); }
    {char tlv24; tlv24 = (char)(cgc_strlen ( tlv76 ) + 1); }
    {cgc_size_t tlv28; tlv28 = (cgc_size_t)(cgc_strlen ( tlv76 ) + 1); }
    {int tlv27; tlv27 = (int)(cgc_strlen ( tlv76 ) + 1); }
    {int tlv30; tlv30 = (int)(cgc_strlen ( tlv76 ) + 1); }
    {int * tlv12; tlv12 = (int *)(cgc_strlen ( tlv76 ) + 1); }
    {int tlv34; tlv34 = (int)(cgc_strlen ( tlv76 ) + 1); }
    {int tlv33; tlv33 = (int)(cgc_strlen ( tlv76 ) + 1); }
    {void * tlv15; tlv15 = (void *)(cgc_strlen ( tlv76 ) + 1); }
    {cgc_size_t tlv14; tlv14 = (cgc_size_t)(cgc_strlen ( tlv76 ) + 1); }
    {char tlv38; tlv38 = (char)(cgc_strlen ( tlv76 ) + 1); }
    {char * tlv72; tlv72 = (char *)(cgc_strlen ( tlv76 ) + 1); }
    {char * tlv73; tlv73 = (char *)(cgc_strlen ( tlv76 ) + 1); }
    {void * tlv41; tlv41 = (void *)(cgc_strlen ( tlv76 ) + 1); }
    {cgc_size_t tlv40; tlv40 = (cgc_size_t)(cgc_strlen ( tlv76 ) + 1); }
    {char * tlv46; tlv46 = (char *)(cgc_strlen ( tlv76 ) + 1); }
    {void * tlv43; tlv43 = (void *)(cgc_strlen ( tlv76 ) + 1); }
    {cgc_size_t tlv42; tlv42 = (cgc_size_t)(cgc_strlen ( tlv76 ) + 1); }
    {void * tlv45; tlv45 = (void *)(cgc_strlen ( tlv76 ) + 1); }
    {cgc_size_t tlv44; tlv44 = (cgc_size_t)(cgc_strlen ( tlv76 ) + 1); }
    {char * tlv74; tlv74 = (char *)(cgc_strlen ( tlv76 ) + 1); }
    {char * tlv75; tlv75 = (char *)(cgc_strlen ( tlv76 ) + 1); }
    {void * tlv49; tlv49 = (void *)(cgc_strlen ( tlv76 ) + 1); }
    {cgc_size_t tlv48; tlv48 = (cgc_size_t)(cgc_strlen ( tlv76 ) + 1); }
    {char * tlv52; tlv52 = (char *)(cgc_strlen ( tlv76 ) + 1); }
    {char * tlv51; tlv51 = (char *)(cgc_strlen ( tlv76 ) + 1); }
    {cgc_size_t tlv50; tlv50 = (cgc_size_t)(cgc_strlen ( tlv76 ) + 1); }
    {void * tlv54; tlv54 = (void *)(cgc_strlen ( tlv76 ) + 1); }
    {cgc_size_t tlv53; tlv53 = (cgc_size_t)(cgc_strlen ( tlv76 ) + 1); }
    {void * tlv56; tlv56 = (void *)(cgc_strlen ( tlv76 ) + 1); }
    {cgc_size_t tlv55; tlv55 = (cgc_size_t)(cgc_strlen ( tlv76 ) + 1); }
    {char * tlv58; tlv58 = (char *)(cgc_strlen ( tlv76 ) + 1); }
    {char * tlv57; tlv57 = (char *)(cgc_strlen ( tlv76 ) + 1); }
    {void * tlv61; tlv61 = (void *)(cgc_strlen ( tlv76 ) + 1); }
    {cgc_size_t tlv60; tlv60 = (cgc_size_t)(cgc_strlen ( tlv76 ) + 1); }
    {char * tlv64; tlv64 = (char *)(cgc_strlen ( tlv76 ) + 1); }
    {char * tlv63; tlv63 = (char *)(cgc_strlen ( tlv76 ) + 1); }
    {cgc_size_t tlv62; tlv62 = (cgc_size_t)(cgc_strlen ( tlv76 ) + 1); }
    {char * tlv77; tlv77 = (char *)(cgc_strlen ( tlv76 ) + 1); }
}
void fix_ingred_cityParsers_6_67(){
fix_ingred_cityParsers_6_67_1();
}
void fix_ingred_cityParsers_6_69_1(){
char tlv73_ref;
    bzero(&tlv73_ref,1*sizeof(char));
char * tlv73 = &tlv73_ref;
    {int lastGood; lastGood = (int)(cgc_strlen ( tlv73 ) + 1); }
    {int startIndex; startIndex = (int)(cgc_strlen ( tlv73 ) + 1); }
    {int endIndex; endIndex = (int)(cgc_strlen ( tlv73 ) + 1); }
    {char * temp; temp = (char *)(cgc_strlen ( tlv73 ) + 1); }
    {int tempInt; tempInt = (int)(cgc_strlen ( tlv73 ) + 1); }
    {int tlv1; tlv1 = (int)(cgc_strlen ( tlv73 ) + 1); }
    {int tlv2; tlv2 = (int)(cgc_strlen ( tlv73 ) + 1); }
    {int tlv3; tlv3 = (int)(cgc_strlen ( tlv73 ) + 1); }
    {int tlv4; tlv4 = (int)(cgc_strlen ( tlv73 ) + 1); }
    {int tlv5; tlv5 = (int)(cgc_strlen ( tlv73 ) + 1); }
    {int tlv6; tlv6 = (int)(cgc_strlen ( tlv73 ) + 1); }
    {int tlv7; tlv7 = (int)(cgc_strlen ( tlv73 ) + 1); }
    {int tlv16; tlv16 = (int)(cgc_strlen ( tlv73 ) + 1); }
    {int * tlv8; tlv8 = (int *)(cgc_strlen ( tlv73 ) + 1); }
    {int tlv20; tlv20 = (int)(cgc_strlen ( tlv73 ) + 1); }
    {int tlv19; tlv19 = (int)(cgc_strlen ( tlv73 ) + 1); }
    {void * tlv11; tlv11 = (void *)(cgc_strlen ( tlv73 ) + 1); }
    {cgc_size_t tlv10; tlv10 = (cgc_size_t)(cgc_strlen ( tlv73 ) + 1); }
    {char tlv24; tlv24 = (char)(cgc_strlen ( tlv73 ) + 1); }
    {cgc_size_t tlv28; tlv28 = (cgc_size_t)(cgc_strlen ( tlv73 ) + 1); }
    {int tlv27; tlv27 = (int)(cgc_strlen ( tlv73 ) + 1); }
    {int tlv30; tlv30 = (int)(cgc_strlen ( tlv73 ) + 1); }
    {int * tlv12; tlv12 = (int *)(cgc_strlen ( tlv73 ) + 1); }
    {int tlv34; tlv34 = (int)(cgc_strlen ( tlv73 ) + 1); }
    {int tlv33; tlv33 = (int)(cgc_strlen ( tlv73 ) + 1); }
    {void * tlv15; tlv15 = (void *)(cgc_strlen ( tlv73 ) + 1); }
    {cgc_size_t tlv14; tlv14 = (cgc_size_t)(cgc_strlen ( tlv73 ) + 1); }
    {char tlv38; tlv38 = (char)(cgc_strlen ( tlv73 ) + 1); }
    {char * tlv72; tlv72 = (char *)(cgc_strlen ( tlv73 ) + 1); }
    {void * tlv41; tlv41 = (void *)(cgc_strlen ( tlv73 ) + 1); }
    {cgc_size_t tlv40; tlv40 = (cgc_size_t)(cgc_strlen ( tlv73 ) + 1); }
    {char * tlv46; tlv46 = (char *)(cgc_strlen ( tlv73 ) + 1); }
    {void * tlv43; tlv43 = (void *)(cgc_strlen ( tlv73 ) + 1); }
    {cgc_size_t tlv42; tlv42 = (cgc_size_t)(cgc_strlen ( tlv73 ) + 1); }
    {void * tlv45; tlv45 = (void *)(cgc_strlen ( tlv73 ) + 1); }
    {cgc_size_t tlv44; tlv44 = (cgc_size_t)(cgc_strlen ( tlv73 ) + 1); }
    {char * tlv74; tlv74 = (char *)(cgc_strlen ( tlv73 ) + 1); }
    {char * tlv75; tlv75 = (char *)(cgc_strlen ( tlv73 ) + 1); }
    {char * tlv76; tlv76 = (char *)(cgc_strlen ( tlv73 ) + 1); }
    {void * tlv49; tlv49 = (void *)(cgc_strlen ( tlv73 ) + 1); }
    {cgc_size_t tlv48; tlv48 = (cgc_size_t)(cgc_strlen ( tlv73 ) + 1); }
    {char * tlv52; tlv52 = (char *)(cgc_strlen ( tlv73 ) + 1); }
    {char * tlv51; tlv51 = (char *)(cgc_strlen ( tlv73 ) + 1); }
    {cgc_size_t tlv50; tlv50 = (cgc_size_t)(cgc_strlen ( tlv73 ) + 1); }
    {void * tlv54; tlv54 = (void *)(cgc_strlen ( tlv73 ) + 1); }
    {cgc_size_t tlv53; tlv53 = (cgc_size_t)(cgc_strlen ( tlv73 ) + 1); }
    {void * tlv56; tlv56 = (void *)(cgc_strlen ( tlv73 ) + 1); }
    {cgc_size_t tlv55; tlv55 = (cgc_size_t)(cgc_strlen ( tlv73 ) + 1); }
    {char * tlv58; tlv58 = (char *)(cgc_strlen ( tlv73 ) + 1); }
    {char * tlv57; tlv57 = (char *)(cgc_strlen ( tlv73 ) + 1); }
    {void * tlv61; tlv61 = (void *)(cgc_strlen ( tlv73 ) + 1); }
    {cgc_size_t tlv60; tlv60 = (cgc_size_t)(cgc_strlen ( tlv73 ) + 1); }
    {char * tlv64; tlv64 = (char *)(cgc_strlen ( tlv73 ) + 1); }
    {char * tlv63; tlv63 = (char *)(cgc_strlen ( tlv73 ) + 1); }
    {cgc_size_t tlv62; tlv62 = (cgc_size_t)(cgc_strlen ( tlv73 ) + 1); }
    {char * tlv77; tlv77 = (char *)(cgc_strlen ( tlv73 ) + 1); }
}
void fix_ingred_cityParsers_6_69(){
fix_ingred_cityParsers_6_69_1();
}
void fix_ingred_cityParsers_6(){
fix_ingred_cityParsers_6_0();
fix_ingred_cityParsers_6_3();
fix_ingred_cityParsers_6_4();
fix_ingred_cityParsers_6_6();
fix_ingred_cityParsers_6_7();
fix_ingred_cityParsers_6_9();
fix_ingred_cityParsers_6_11();
fix_ingred_cityParsers_6_12();
fix_ingred_cityParsers_6_13();
fix_ingred_cityParsers_6_15();
fix_ingred_cityParsers_6_16();
fix_ingred_cityParsers_6_18();
fix_ingred_cityParsers_6_19();
fix_ingred_cityParsers_6_24();
fix_ingred_cityParsers_6_25();
fix_ingred_cityParsers_6_29();
fix_ingred_cityParsers_6_30();
fix_ingred_cityParsers_6_32();
fix_ingred_cityParsers_6_36();
fix_ingred_cityParsers_6_37();
fix_ingred_cityParsers_6_42();
fix_ingred_cityParsers_6_43();
fix_ingred_cityParsers_6_55();
fix_ingred_cityParsers_6_56();
fix_ingred_cityParsers_6_65();
fix_ingred_cityParsers_6_67();
fix_ingred_cityParsers_6_69();
}
void fix_ingred_cityParsers_7_0_0(){
    {char * mayor; mayor = (char *)(NULL); }
    {int tlv8; tlv8 = (int)(NULL); }
    {int tlv12; tlv12 = (int)(NULL); }
    {int tlv11; tlv11 = (int)(NULL); }
    {char tlv16; tlv16 = (char)(NULL); }
    {int tlv21; tlv21 = (int)(NULL); }
    {int tlv23; tlv23 = (int)(NULL); }
    {int tlv26; tlv26 = (int)(NULL); }
    {char tlv31; tlv31 = (char)(NULL); }
}
void fix_ingred_cityParsers_7_0(){
fix_ingred_cityParsers_7_0_0();
}
void fix_ingred_cityParsers_7_2_1(){
    {char * mayor; mayor = (char *)(0); }
    {int tlv8; tlv8 = (int)(0); }
    {int tlv12; tlv12 = (int)(0); }
    {int tlv11; tlv11 = (int)(0); }
    {char tlv16; tlv16 = (char)(0); }
    {int tlv21; tlv21 = (int)(0); }
    {int tlv23; tlv23 = (int)(0); }
    {int tlv26; tlv26 = (int)(0); }
    {char tlv31; tlv31 = (char)(0); }
}
void fix_ingred_cityParsers_7_2(){
fix_ingred_cityParsers_7_2_1();
}
void fix_ingred_cityParsers_7_3_4(){
int tlv1;
    bzero(&tlv1,sizeof(int));
    {char * mayor; mayor = (char *)(tlv1); }
    {int tlv8; tlv8 = (int)(tlv1); }
    {int tlv12; tlv12 = (int)(tlv1); }
    {int tlv11; tlv11 = (int)(tlv1); }
    {char tlv16; tlv16 = (char)(tlv1); }
    {int tlv21; tlv21 = (int)(tlv1); }
    {int tlv23; tlv23 = (int)(tlv1); }
    {int tlv26; tlv26 = (int)(tlv1); }
    {char tlv31; tlv31 = (char)(tlv1); }
}
void fix_ingred_cityParsers_7_3(){
fix_ingred_cityParsers_7_3_4();
}
void fix_ingred_cityParsers_7_6_1(){
int startIndex;
    bzero(&startIndex,sizeof(int));
int endIndex;
    bzero(&endIndex,sizeof(int));
    {char * mayor; mayor = (char *)(startIndex); }
    {int tlv8; tlv8 = (int)(startIndex); }
    {int tlv12; tlv12 = (int)(startIndex); }
    {int tlv11; tlv11 = (int)(startIndex); }
    {char tlv16; tlv16 = (char)(startIndex); }
    {int tlv21; tlv21 = (int)(startIndex); }
    {int tlv23; tlv23 = (int)(startIndex); }
    {int tlv26; tlv26 = (int)(startIndex); }
    {char tlv31; tlv31 = (char)(startIndex); }
}
void fix_ingred_cityParsers_7_6_2(){
int startIndex;
    bzero(&startIndex,sizeof(int));
int endIndex;
    bzero(&endIndex,sizeof(int));
    {char * mayor; mayor = (char *)(endIndex); }
    {int tlv8; tlv8 = (int)(endIndex); }
    {int tlv12; tlv12 = (int)(endIndex); }
    {int tlv11; tlv11 = (int)(endIndex); }
    {char tlv16; tlv16 = (char)(endIndex); }
    {int tlv21; tlv21 = (int)(endIndex); }
    {int tlv23; tlv23 = (int)(endIndex); }
    {int tlv26; tlv26 = (int)(endIndex); }
    {char tlv31; tlv31 = (char)(endIndex); }
}
void fix_ingred_cityParsers_7_6(){
fix_ingred_cityParsers_7_6_1();
fix_ingred_cityParsers_7_6_2();
}
void fix_ingred_cityParsers_7_7_5(){
char mayor_ref;
    bzero(&mayor_ref,1*sizeof(char));
char * mayor = &mayor_ref;
    {char * temp; temp = (char *)(mayor); }
    {int tlv1; tlv1 = (int)(mayor); }
    {int tlv2; tlv2 = (int)(mayor); }
    {int tlv3; tlv3 = (int)(mayor); }
    {int tlv4; tlv4 = (int)(mayor); }
    {int tlv5; tlv5 = (int)(mayor); }
    {int tlv6; tlv6 = (int)(mayor); }
    {int tlv8; tlv8 = (int)(mayor); }
    {int tlv12; tlv12 = (int)(mayor); }
    {int tlv11; tlv11 = (int)(mayor); }
    {char tlv16; tlv16 = (char)(mayor); }
    {int tlv21; tlv21 = (int)(mayor); }
    {int tlv20; tlv20 = (int)(mayor); }
    {int tlv23; tlv23 = (int)(mayor); }
    {int tlv27; tlv27 = (int)(mayor); }
    {int tlv26; tlv26 = (int)(mayor); }
    {char tlv31; tlv31 = (char)(mayor); }
}
void fix_ingred_cityParsers_7_7(){
fix_ingred_cityParsers_7_7_5();
}
void fix_ingred_cityParsers_7_9_5(){
int tlv2;
    bzero(&tlv2,sizeof(int));
    {char * mayor; mayor = (char *)(tlv2); }
    {int tlv8; tlv8 = (int)(tlv2); }
    {int tlv12; tlv12 = (int)(tlv2); }
    {int tlv11; tlv11 = (int)(tlv2); }
    {char tlv16; tlv16 = (char)(tlv2); }
    {int tlv21; tlv21 = (int)(tlv2); }
    {int tlv23; tlv23 = (int)(tlv2); }
    {int tlv26; tlv26 = (int)(tlv2); }
    {char tlv31; tlv31 = (char)(tlv2); }
}
void fix_ingred_cityParsers_7_9(){
fix_ingred_cityParsers_7_9_5();
}
void fix_ingred_cityParsers_7_12_1(){
    {char * mayor; mayor = (char *)('}'); }
    {int tlv8; tlv8 = (int)('}'); }
    {int tlv12; tlv12 = (int)('}'); }
    {int tlv11; tlv11 = (int)('}'); }
    {char tlv16; tlv16 = (char)('}'); }
    {int tlv21; tlv21 = (int)('}'); }
    {int tlv23; tlv23 = (int)('}'); }
    {int tlv26; tlv26 = (int)('}'); }
    {char tlv31; tlv31 = (char)('}'); }
}
void fix_ingred_cityParsers_7_12(){
fix_ingred_cityParsers_7_12_1();
}
void fix_ingred_cityParsers_7_20_1(){
    {char * mayor; mayor = (char *)(1); }
    {int tlv8; tlv8 = (int)(1); }
    {int tlv12; tlv12 = (int)(1); }
    {int tlv11; tlv11 = (int)(1); }
    {char tlv16; tlv16 = (char)(1); }
    {int tlv21; tlv21 = (int)(1); }
    {int tlv23; tlv23 = (int)(1); }
    {int tlv26; tlv26 = (int)(1); }
    {char tlv31; tlv31 = (char)(1); }
}
void fix_ingred_cityParsers_7_20(){
fix_ingred_cityParsers_7_20_1();
}
void fix_ingred_cityParsers_7_21_5(){
int tlv4;
    bzero(&tlv4,sizeof(int));
    {char * mayor; mayor = (char *)(tlv4); }
    {int tlv8; tlv8 = (int)(tlv4); }
    {int tlv12; tlv12 = (int)(tlv4); }
    {int tlv11; tlv11 = (int)(tlv4); }
    {char tlv16; tlv16 = (char)(tlv4); }
    {int tlv21; tlv21 = (int)(tlv4); }
    {int tlv23; tlv23 = (int)(tlv4); }
    {int tlv26; tlv26 = (int)(tlv4); }
    {char tlv31; tlv31 = (char)(tlv4); }
}
void fix_ingred_cityParsers_7_21(){
fix_ingred_cityParsers_7_21_5();
}
void fix_ingred_cityParsers_7_25_6(){
char temp_ref;
    bzero(&temp_ref,1*sizeof(char));
char * temp = &temp_ref;
    {char * mayor; mayor = (char *)(temp); }
    {int tlv8; tlv8 = (int)(temp); }
    {int tlv12; tlv12 = (int)(temp); }
    {int tlv11; tlv11 = (int)(temp); }
    {char tlv16; tlv16 = (char)(temp); }
    {int tlv21; tlv21 = (int)(temp); }
    {int tlv23; tlv23 = (int)(temp); }
    {int tlv26; tlv26 = (int)(temp); }
    {char tlv31; tlv31 = (char)(temp); }
}
void fix_ingred_cityParsers_7_25(){
fix_ingred_cityParsers_7_25_6();
}
void fix_ingred_cityParsers_7_27_6(){
int tlv5;
    bzero(&tlv5,sizeof(int));
    {char * mayor; mayor = (char *)(tlv5); }
    {int tlv8; tlv8 = (int)(tlv5); }
    {int tlv12; tlv12 = (int)(tlv5); }
    {int tlv11; tlv11 = (int)(tlv5); }
    {char tlv16; tlv16 = (char)(tlv5); }
    {int tlv21; tlv21 = (int)(tlv5); }
    {int tlv23; tlv23 = (int)(tlv5); }
    {int tlv26; tlv26 = (int)(tlv5); }
    {char tlv31; tlv31 = (char)(tlv5); }
}
void fix_ingred_cityParsers_7_27(){
fix_ingred_cityParsers_7_27_6();
}
void fix_ingred_cityParsers_7(){
fix_ingred_cityParsers_7_0();
fix_ingred_cityParsers_7_2();
fix_ingred_cityParsers_7_3();
fix_ingred_cityParsers_7_6();
fix_ingred_cityParsers_7_7();
fix_ingred_cityParsers_7_9();
fix_ingred_cityParsers_7_12();
fix_ingred_cityParsers_7_20();
fix_ingred_cityParsers_7_21();
fix_ingred_cityParsers_7_25();
fix_ingred_cityParsers_7_27();
}
void fix_ingred_cityParsers_8_0_0(){
    {char * url; url = (char *)(NULL); }
    {int tlv14; tlv14 = (int)(NULL); }
    {int * tlv7; tlv7 = (int *)(NULL); }
    {int tlv17; tlv17 = (int)(NULL); }
    {char tlv21; tlv21 = (char)(NULL); }
    {int * tlv9; tlv9 = (int *)(NULL); }
    {int tlv24; tlv24 = (int)(NULL); }
    {int * tlv11; tlv11 = (int *)(NULL); }
    {int tlv29; tlv29 = (int)(NULL); }
    {int tlv28; tlv28 = (int)(NULL); }
    {char tlv33; tlv33 = (char)(NULL); }
}
void fix_ingred_cityParsers_8_0_1(){
    {char * url; url = (char *)(0); }
    {int tlv14; tlv14 = (int)(0); }
    {int * tlv7; tlv7 = (int *)(0); }
    {int tlv17; tlv17 = (int)(0); }
    {char tlv21; tlv21 = (char)(0); }
    {int * tlv9; tlv9 = (int *)(0); }
    {int tlv24; tlv24 = (int)(0); }
    {int * tlv11; tlv11 = (int *)(0); }
    {int tlv29; tlv29 = (int)(0); }
    {int tlv28; tlv28 = (int)(0); }
    {char tlv33; tlv33 = (char)(0); }
}
void fix_ingred_cityParsers_8_0(){
fix_ingred_cityParsers_8_0_0();
fix_ingred_cityParsers_8_0_1();
}
void fix_ingred_cityParsers_8_3_3(){
int tlv1;
    bzero(&tlv1,sizeof(int));
    {char * url; url = (char *)(tlv1); }
    {int tlv14; tlv14 = (int)(tlv1); }
    {int * tlv7; tlv7 = (int *)(tlv1); }
    {int tlv17; tlv17 = (int)(tlv1); }
    {char tlv21; tlv21 = (char)(tlv1); }
    {int * tlv9; tlv9 = (int *)(tlv1); }
    {int tlv24; tlv24 = (int)(tlv1); }
    {int * tlv11; tlv11 = (int *)(tlv1); }
    {int tlv29; tlv29 = (int)(tlv1); }
    {int tlv28; tlv28 = (int)(tlv1); }
    {char tlv33; tlv33 = (char)(tlv1); }
}
void fix_ingred_cityParsers_8_3(){
fix_ingred_cityParsers_8_3_3();
}
void fix_ingred_cityParsers_8_4_1(){
int startIndex;
    bzero(&startIndex,sizeof(int));
    {char * url; url = (char *)(& startIndex); }
    {int tlv14; tlv14 = (int)(& startIndex); }
    {int * tlv7; tlv7 = (int *)(& startIndex); }
    {int tlv17; tlv17 = (int)(& startIndex); }
    {char tlv21; tlv21 = (char)(& startIndex); }
    {int * tlv9; tlv9 = (int *)(& startIndex); }
    {int tlv24; tlv24 = (int)(& startIndex); }
    {int tlv23; tlv23 = (int)(& startIndex); }
    {int tlv26; tlv26 = (int)(& startIndex); }
    {int * tlv11; tlv11 = (int *)(& startIndex); }
    {int tlv29; tlv29 = (int)(& startIndex); }
    {int tlv28; tlv28 = (int)(& startIndex); }
    {char tlv33; tlv33 = (char)(& startIndex); }
}
void fix_ingred_cityParsers_8_4(){
fix_ingred_cityParsers_8_4_1();
}
void fix_ingred_cityParsers_8_5_1(){
int startIndex;
    bzero(&startIndex,sizeof(int));
string str_ref;
    bzero(&str_ref,1*sizeof(string));
pstring str = &str_ref;
    {char * url; url = (char *)(startIndex); }
    {int tlv14; tlv14 = (int)(startIndex); }
    {int * tlv7; tlv7 = (int *)(startIndex); }
    {int tlv17; tlv17 = (int)(startIndex); }
    {char tlv21; tlv21 = (char)(startIndex); }
    {int * tlv9; tlv9 = (int *)(startIndex); }
    {int tlv24; tlv24 = (int)(startIndex); }
    {int * tlv11; tlv11 = (int *)(startIndex); }
    {int tlv29; tlv29 = (int)(startIndex); }
    {int tlv28; tlv28 = (int)(startIndex); }
    {char tlv33; tlv33 = (char)(startIndex); }
}
void fix_ingred_cityParsers_8_5_2(){
int startIndex;
    bzero(&startIndex,sizeof(int));
string str_ref;
    bzero(&str_ref,1*sizeof(string));
pstring str = &str_ref;
    {char * url; url = (char *)(str -> index); }
    {int tlv14; tlv14 = (int)(str -> index); }
    {int * tlv7; tlv7 = (int *)(str -> index); }
    {int tlv17; tlv17 = (int)(str -> index); }
    {char tlv21; tlv21 = (char)(str -> index); }
    {int * tlv9; tlv9 = (int *)(str -> index); }
    {int tlv24; tlv24 = (int)(str -> index); }
    {int tlv23; tlv23 = (int)(str -> index); }
    {int tlv26; tlv26 = (int)(str -> index); }
    {int * tlv11; tlv11 = (int *)(str -> index); }
    {int tlv29; tlv29 = (int)(str -> index); }
    {int tlv28; tlv28 = (int)(str -> index); }
    {char tlv33; tlv33 = (char)(str -> index); }
}
void fix_ingred_cityParsers_8_5(){
fix_ingred_cityParsers_8_5_1();
fix_ingred_cityParsers_8_5_2();
}
void fix_ingred_cityParsers_8_6_3(){
char url_ref;
    bzero(&url_ref,1*sizeof(char));
char * url = &url_ref;
    {int startIndex; startIndex = (int)(url); }
    {char * temp; temp = (char *)(url); }
    {int tlv1; tlv1 = (int)(url); }
    {int tlv2; tlv2 = (int)(url); }
    {int tlv3; tlv3 = (int)(url); }
    {int tlv4; tlv4 = (int)(url); }
    {int tlv5; tlv5 = (int)(url); }
    {int tlv6; tlv6 = (int)(url); }
    {int tlv14; tlv14 = (int)(url); }
    {int * tlv7; tlv7 = (int *)(url); }
    {int tlv17; tlv17 = (int)(url); }
    {int tlv16; tlv16 = (int)(url); }
    {char tlv21; tlv21 = (char)(url); }
    {int * tlv9; tlv9 = (int *)(url); }
    {int tlv24; tlv24 = (int)(url); }
    {int tlv23; tlv23 = (int)(url); }
    {int tlv26; tlv26 = (int)(url); }
    {int * tlv11; tlv11 = (int *)(url); }
    {int tlv29; tlv29 = (int)(url); }
    {int tlv28; tlv28 = (int)(url); }
    {char tlv33; tlv33 = (char)(url); }
}
void fix_ingred_cityParsers_8_6(){
fix_ingred_cityParsers_8_6_3();
}
void fix_ingred_cityParsers_8_10_1(){
    {char * url; url = (char *)('}'); }
    {int tlv14; tlv14 = (int)('}'); }
    {int * tlv7; tlv7 = (int *)('}'); }
    {int tlv17; tlv17 = (int)('}'); }
    {char tlv21; tlv21 = (char)('}'); }
    {int * tlv9; tlv9 = (int *)('}'); }
    {int tlv24; tlv24 = (int)('}'); }
    {int * tlv11; tlv11 = (int *)('}'); }
    {int tlv29; tlv29 = (int)('}'); }
    {int tlv28; tlv28 = (int)('}'); }
    {char tlv33; tlv33 = (char)('}'); }
}
void fix_ingred_cityParsers_8_10(){
fix_ingred_cityParsers_8_10_1();
}
void fix_ingred_cityParsers_8_15_1(){
    {char * url; url = (char *)(1); }
    {int tlv14; tlv14 = (int)(1); }
    {int * tlv7; tlv7 = (int *)(1); }
    {int tlv17; tlv17 = (int)(1); }
    {char tlv21; tlv21 = (char)(1); }
    {int * tlv9; tlv9 = (int *)(1); }
    {int tlv24; tlv24 = (int)(1); }
    {int * tlv11; tlv11 = (int *)(1); }
    {int tlv29; tlv29 = (int)(1); }
    {int tlv28; tlv28 = (int)(1); }
    {char tlv33; tlv33 = (char)(1); }
}
void fix_ingred_cityParsers_8_15(){
fix_ingred_cityParsers_8_15_1();
}
void fix_ingred_cityParsers_8_16_3(){
int tlv4;
    bzero(&tlv4,sizeof(int));
    {char * url; url = (char *)(tlv4); }
    {int tlv14; tlv14 = (int)(tlv4); }
    {int * tlv7; tlv7 = (int *)(tlv4); }
    {int tlv17; tlv17 = (int)(tlv4); }
    {char tlv21; tlv21 = (char)(tlv4); }
    {int * tlv9; tlv9 = (int *)(tlv4); }
    {int tlv24; tlv24 = (int)(tlv4); }
    {int * tlv11; tlv11 = (int *)(tlv4); }
    {int tlv29; tlv29 = (int)(tlv4); }
    {int tlv28; tlv28 = (int)(tlv4); }
    {char tlv33; tlv33 = (char)(tlv4); }
}
void fix_ingred_cityParsers_8_16(){
fix_ingred_cityParsers_8_16_3();
}
void fix_ingred_cityParsers_8_19_3(){
char temp_ref;
    bzero(&temp_ref,1*sizeof(char));
char * temp = &temp_ref;
    {char * url; url = (char *)(temp); }
    {int tlv14; tlv14 = (int)(temp); }
    {int * tlv7; tlv7 = (int *)(temp); }
    {int tlv17; tlv17 = (int)(temp); }
    {char tlv21; tlv21 = (char)(temp); }
    {int * tlv9; tlv9 = (int *)(temp); }
    {int tlv24; tlv24 = (int)(temp); }
    {int * tlv11; tlv11 = (int *)(temp); }
    {int tlv29; tlv29 = (int)(temp); }
    {int tlv28; tlv28 = (int)(temp); }
    {char tlv33; tlv33 = (char)(temp); }
}
void fix_ingred_cityParsers_8_19(){
fix_ingred_cityParsers_8_19_3();
}
void fix_ingred_cityParsers_8_21_3(){
int tlv5;
    bzero(&tlv5,sizeof(int));
    {char * url; url = (char *)(tlv5); }
    {int tlv14; tlv14 = (int)(tlv5); }
    {int * tlv7; tlv7 = (int *)(tlv5); }
    {int tlv17; tlv17 = (int)(tlv5); }
    {char tlv21; tlv21 = (char)(tlv5); }
    {int * tlv9; tlv9 = (int *)(tlv5); }
    {int tlv24; tlv24 = (int)(tlv5); }
    {int * tlv11; tlv11 = (int *)(tlv5); }
    {int tlv29; tlv29 = (int)(tlv5); }
    {int tlv28; tlv28 = (int)(tlv5); }
    {char tlv33; tlv33 = (char)(tlv5); }
}
void fix_ingred_cityParsers_8_21(){
fix_ingred_cityParsers_8_21_3();
}
void fix_ingred_cityParsers_8(){
fix_ingred_cityParsers_8_0();
fix_ingred_cityParsers_8_3();
fix_ingred_cityParsers_8_4();
fix_ingred_cityParsers_8_5();
fix_ingred_cityParsers_8_6();
fix_ingred_cityParsers_8_10();
fix_ingred_cityParsers_8_15();
fix_ingred_cityParsers_8_16();
fix_ingred_cityParsers_8_19();
fix_ingred_cityParsers_8_21();
}
