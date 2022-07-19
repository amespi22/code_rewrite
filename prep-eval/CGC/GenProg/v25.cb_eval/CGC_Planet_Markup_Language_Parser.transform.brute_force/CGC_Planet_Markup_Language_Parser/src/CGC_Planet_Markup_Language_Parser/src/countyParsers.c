

#include "cgc_countyParsers.h"
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

void fix_ingred_countyParsers_0_0_0();
void fix_ingred_countyParsers_0_0();
void fix_ingred_countyParsers_0_14_0();
void fix_ingred_countyParsers_0_14_1();
void fix_ingred_countyParsers_0_14();
void fix_ingred_countyParsers_0_15_0();
void fix_ingred_countyParsers_0_15_1();
void fix_ingred_countyParsers_0_15_2();
void fix_ingred_countyParsers_0_15();
void fix_ingred_countyParsers_0_17_1();
void fix_ingred_countyParsers_0_17();
void fix_ingred_countyParsers_0_22_2();
void fix_ingred_countyParsers_0_22();
void fix_ingred_countyParsers_0_39_0();
void fix_ingred_countyParsers_0_39();
void fix_ingred_countyParsers_0_40_6();
void fix_ingred_countyParsers_0_40();
void fix_ingred_countyParsers_0_58_6();
void fix_ingred_countyParsers_0_58_7();
void fix_ingred_countyParsers_0_58();
void fix_ingred_countyParsers_0_62_0();
void fix_ingred_countyParsers_0_62();
void fix_ingred_countyParsers_0_63_7();
void fix_ingred_countyParsers_0_63();
void fix_ingred_countyParsers_0_74_10();
void fix_ingred_countyParsers_0_74();
void fix_ingred_countyParsers_0_77_10();
void fix_ingred_countyParsers_0_77();
void fix_ingred_countyParsers_0();
int cgc_countyMenu(pCounty co)
{
if (fix_ingred_enable){ fix_ingred_countyParsers_0(); };
    int choice;
    choice = 0;
    char selection[30];
    pBorder pb;
    pb = NULL;
    pCity pc;
    pc = NULL;
    if (co == NULL) {
	return 0;
    }
    while (1) {
	cgc_printf("County: @s\n", co->name);
 {
     const char tlv4 [ ] = "1) Display County Info\n";
    	cgc_printf(tlv4);
 }
 {
     const char tlv5 [ ] = "2) Set Seat\n";
    	cgc_printf(tlv5);
 }
 {
     const char tlv6 [ ] = "3) Set Population\n";
    	cgc_printf(tlv6);
 }
 {
     const char tlv7 [ ] = "4) Set Area\n";
    	cgc_printf(tlv7);
 }
 {
     const char tlv8 [ ] = "5) Set Density\n";
    	cgc_printf(tlv8);
 }
 {
     const char tlv9 [ ] = "6) Add Border\n";
    	cgc_printf(tlv9);
 }
 {
     const char tlv10 [ ] = "7) Add City\n";
    	cgc_printf(tlv10);
 }
 {
     const char tlv11 [ ] = "8) Select City\n";
    	cgc_printf(tlv11);
 }
 {
     const char tlv12 [ ] = "9) Delete County and Exit Menu\n";
    	cgc_printf(tlv12);
 }
 {
     const char tlv13 [ ] = "10) Exit Menu\n";
    	cgc_printf(tlv13);
 }
 {
     const char tlv14 [ ] = "Selection: ";
    	cgc_printf(tlv14);
 }
 {
     void* tlv16;
     tlv16 = selection;
     cgc_size_t tlv15;
     tlv15 = 4;
    	cgc_bzero(tlv16,tlv15);
 }
 {
     char* tlv19;
      tlv19 = selection;
     char tlv18;
     tlv18 = '\n';
     cgc_size_t tlv17;
     tlv17 = 3;
    	cgc_receive_until(tlv19,tlv18,tlv17);
 }
 {
     const char* tlv22 = selection;
    	choice = cgc_atoi(tlv22);
 }
 {
     void* tlv21;
     tlv21 = selection;
     cgc_size_t tlv20;
     tlv20 = 30;
    	cgc_bzero(tlv21,tlv20);
 }
	switch (choice) {
	case 1:
	    {
		cgc_printCountyInfo(co);
	    }
	    break;
	case 2:		// Set Seat
	    {
  {
      const char tlv84 [ ] = "\n-> ";
    		cgc_printf(tlv84);
  }
	    }
     {
         char* tlv25;
          tlv25 = selection;
         char tlv24;
         tlv24 = '\n';
         cgc_size_t tlv23;
         tlv23 = 19;
    	    cgc_receive_until(tlv25,tlv24,tlv23);
     }

	    choice = 0;
	    while (cgc_isalpha(selection[choice])) {
		co->seat[choice] = selection[choice];
		choice++;
	    }

	    /// NULL terminated
	    co->seat[choice] = '\x00';
	    break;
	case 3:		// Set Population
	    {
  {
      const char tlv85 [ ] = "\n-> ";
    		cgc_printf(tlv85);
  }
	    }
     {
         char* tlv28;
          tlv28 = selection;
         char tlv27;
         tlv27 = '\n';
         cgc_size_t tlv26;
         tlv26 = 19;
    	    cgc_receive_until(tlv28,tlv27,tlv26);
     }
     {
         const char* tlv69 = selection;
    	    co->population = cgc_atoi(tlv69);
     }
	    break;
	case 4:		/// Set Area
	    {
  {
      const char tlv86 [ ] = "\n-> ";
    		cgc_printf(tlv86);
  }
	    }
     {
         char* tlv31;
          tlv31 = selection;
         char tlv30;
         tlv30 = '\n';
         cgc_size_t tlv29;
         tlv29 = 19;
    	    cgc_receive_until(tlv31,tlv30,tlv29);
     }
     {
         const char* tlv70 = selection;
    	    co->area = cgc_atof(tlv70);
     }
	    break;
	case 5:		/// Set Density
	    {
  {
      const char tlv87 [ ] = "\n-> ";
    		cgc_printf(tlv87);
  }
	    }
     {
         char* tlv34;
          tlv34 = selection;
         char tlv33;
         tlv33 = '\n';
         cgc_size_t tlv32;
         tlv32 = 19;
    	    cgc_receive_until(tlv34,tlv33,tlv32);
     }
     {
         const char* tlv71 = selection;
    	    co->density = cgc_atof(tlv71);
     }
	    break;
	case 6:		/// Add border
	    {
		if (co->border_count >= COUNTYBORDERMAX) {
      {
          const char tlv91 [ ] = "!!Max borders reached\n";
    		    cgc_printf(tlv91);
      }
		    break;
		}
	    }
     int tlv1;
     {
         cgc_size_t tlv74;
         tlv74 = sizeof ( Border );
         int tlv73;
         tlv73 = 0;
         void** tlv72;
         tlv72 = ( void * * ) & pb;
         tlv1 = cgc_allocate(tlv74,tlv73,tlv72);
     }
	    if (tlv1 != 0) {
		pb = NULL;
		break;
	    }
     {
         const char tlv35 [ ] = "Lat Start: ";
    	    cgc_printf(tlv35);
     }
     {
         void* tlv37;
         tlv37 = selection;
         cgc_size_t tlv36;
         tlv36 = 30;
    	    cgc_bzero(tlv37,tlv36);
     }
     {
         char* tlv40;
          tlv40 = selection;
         char tlv39;
         tlv39 = '\n';
         cgc_size_t tlv38;
         tlv38 = 19;
    	    cgc_receive_until(tlv40,tlv39,tlv38);
     }
     {
         const char* tlv75 = selection;
    	    pb->latStart = cgc_atof(tlv75);
     }
     {
         const char tlv41 [ ] = "Long Start: ";
    	    cgc_printf(tlv41);
     }
     {
         void* tlv43;
         tlv43 = selection;
         cgc_size_t tlv42;
         tlv42 = 30;
    	    cgc_bzero(tlv43,tlv42);
     }
     {
         char* tlv46;
          tlv46 = selection;
         char tlv45;
         tlv45 = '\n';
         cgc_size_t tlv44;
         tlv44 = 19;
    	    cgc_receive_until(tlv46,tlv45,tlv44);
     }
     {
         const char* tlv76 = selection;
    	    pb->lngStart = cgc_atof(tlv76);
     }
     {
         const char tlv47 [ ] = "Lat End: ";
    	    cgc_printf(tlv47);
     }
     {
         void* tlv49;
         tlv49 = selection;
         cgc_size_t tlv48;
         tlv48 = 30;
    	    cgc_bzero(tlv49,tlv48);
     }
     {
         char* tlv52;
          tlv52 = selection;
         char tlv51;
         tlv51 = '\n';
         cgc_size_t tlv50;
         tlv50 = 19;
    	    cgc_receive_until(tlv52,tlv51,tlv50);
     }
     {
         const char* tlv77 = selection;
    	    pb->latEnd = cgc_atof(tlv77);
     }
     {
         const char tlv53 [ ] = "Long End: ";
    	    cgc_printf(tlv53);
     }
     {
         void* tlv55;
         tlv55 = selection;
         cgc_size_t tlv54;
         tlv54 = 30;
    	    cgc_bzero(tlv55,tlv54);
     }
     {
         char* tlv58;
          tlv58 = selection;
         char tlv57;
         tlv57 = '\n';
         cgc_size_t tlv56;
         tlv56 = 19;
    	    cgc_receive_until(tlv58,tlv57,tlv56);
     }
     {
         const char* tlv78 = selection;
    	    pb->lngEnd = cgc_atof(tlv78);
     }
	    co->borders[co->border_count] = pb;
	    co->border_count++;
	    break;
	case 7:
	    /// Add City
	    /// Find a free slot
	    {
		choice = 0;
	    }
	    while (choice < COUNTYCITYMAX) {
		if (co->cities[choice] == NULL) {
		    break;
		}
		choice++;
	    }
	    if (choice == COUNTYCITYMAX) {
  {
      const char tlv88 [ ] = "!!Max cities reached\n";
    		cgc_printf(tlv88);
  }
		continue;
	    }
     int tlv2;
     {
         cgc_size_t tlv81;
         tlv81 = sizeof ( City );
         int tlv80;
         tlv80 = 0;
         void** tlv79;
         tlv79 = ( void * * ) ( & pc );
         tlv2 = cgc_allocate(tlv81,tlv80,tlv79);
     }
	    if (tlv2 != 0) {
		pc = NULL;
		continue;
	    }
	    cgc_initCity(pc);
	    co->cities[choice] = pc;
     {
         const char tlv59 [ ] = "New City Name: ";
    	    cgc_printf(tlv59);
     }
     {
         char* tlv62;
          tlv62 = selection;
         char tlv61;
         tlv61 = '\n';
         cgc_size_t tlv60;
         tlv60 = 19;
    	    cgc_receive_until(tlv62,tlv61,tlv60);
     }
	    choice = 0;
	    while (cgc_isalnum(selection[choice])) {
		pc->name[choice] = selection[choice];
		choice++;
	    }
	    pc->name[choice] = '\x00';
	    co->city_count++;
	    break;
	case 8:
	    /// cgc_select city
	    {
		for (choice = 0; choice < COUNTYCITYMAX; choice++) {
		    if (co->cities[choice] != NULL) {
			cgc_printf("@d) @s\n", choice + 1, co->cities[choice]);
		    }
		}
	    }
     {
         const char tlv63 [ ] = "\n-> ";
    	    cgc_printf(tlv63);
     }
     {
         void* tlv65;
         tlv65 = selection;
         cgc_size_t tlv64;
         tlv64 = 30;
    	    cgc_bzero(tlv65,tlv64);
     }
     {
         char* tlv68;
          tlv68 = selection;
         char tlv67;
         tlv67 = '\n';
         cgc_size_t tlv66;
         tlv66 = 4;
    	    cgc_receive_until(tlv68,tlv67,tlv66);
     }
     {
         const char* tlv82 = selection;
    	    choice = cgc_atoi(tlv82);
     }
	    if (choice < 1 || choice > COUNTYCITYMAX || co->cities[choice - 1] == NULL) {
  {
      const char tlv89 [ ] = "Invalid choice\n";
    		cgc_printf(tlv89);
  }
		continue;
	    }
     int tlv3;
     {
         pCity tlv83;
         tlv83 = co -> cities [ choice - 1 ];
         tlv3 = cgc_cityMenu(tlv83);
     }
	    if (tlv3 == 0) {
		co->cities[choice - 1] = NULL;
		co->city_count--;
	    }
	    break;
	case 9:
	    {
		cgc_freeCounty(co);
	    }
	    return 0;
	    break;
	case 10:
	    {
		return 1;
	    }
	    break;
	default:
	    {
  {
      const char tlv90 [ ] = "Invalid choice\n";
    		cgc_printf(tlv90);
  }
	    }
	    continue;
	};
    }
    return 1;
}

void fix_ingred_countyParsers_1_0_0();
void fix_ingred_countyParsers_1_0();
void fix_ingred_countyParsers_1_2_2();
void fix_ingred_countyParsers_1_2_3();
void fix_ingred_countyParsers_1_2();
void fix_ingred_countyParsers_1_4_1();
void fix_ingred_countyParsers_1_4();
void fix_ingred_countyParsers_1_5_4();
void fix_ingred_countyParsers_1_5();
void fix_ingred_countyParsers_1_7_0();
void fix_ingred_countyParsers_1_7_1();
void fix_ingred_countyParsers_1_7();
void fix_ingred_countyParsers_1();
void cgc_freeCounty(pCounty co)
{
if (fix_ingred_enable){ fix_ingred_countyParsers_1(); };
    int index;
    index = 0;
    if (co == NULL) {
	return;
    }
    for (index = 0; index < co->border_count; index++) {
	if (co->borders[index] != NULL) {
     {
         void* tlv5;
         tlv5 = co -> borders [ index ];
         cgc_size_t tlv4;
         tlv4 = sizeof ( Border );
    	    cgc_deallocate(tlv5,tlv4);
     }
	    co->borders[index] = NULL;
	}
    }
    for (index = 0; index < COUNTYCITYMAX; index++) {
 {
     pCity tlv3;
     tlv3 = co -> cities [ index ];
    	cgc_freeCity(tlv3);
 }
	co->cities[index] = NULL;
    }
    {
        void* tlv2;
        tlv2 = co;
        cgc_size_t tlv1;
        tlv1 = sizeof ( County );
        cgc_deallocate(tlv2,tlv1);
    }

    return;
}

void fix_ingred_countyParsers_2_2_7();
void fix_ingred_countyParsers_2_2();
void fix_ingred_countyParsers_2();
void cgc_initCounty(pCounty co)
{
if (fix_ingred_enable){ fix_ingred_countyParsers_2(); };
    int index;
    index = 0;
    if (co == NULL) {
	return;
    }
    for (index = 0; index < 20; index++) {
	co->name[index] = 0;
	co->seat[index] = 0;
	co->cities[index] = NULL;
	co->borders[index] = NULL;
    }
    co->population = -1;
    co->area = -1.0;
    co->density = -1.0;
    co->city_count = 0;
    co->border_count = 0;
    return;
}

void fix_ingred_countyParsers_3();
void cgc_printCountyInfo(pCounty co)
{
if (fix_ingred_enable){ fix_ingred_countyParsers_3(); };
    int index;
    index = 0;
    if (co == NULL) {
	return;
    }
    {
        const char tlv1 [ ] = "\t\t\tCounty: ";
        cgc_printf(tlv1);
    }
    if (co->name[0] == '\x00') {
 {
     const char tlv3 [ ] = "Unknown\n";
    	cgc_printf(tlv3);
 }
    } else {
	cgc_printf("@s\n", co->name);
    }
    {
        const char tlv2 [ ] = "\t\t\t\tSeat: ";
        cgc_printf(tlv2);
    }
    if (co->seat[0] == '\x00') {
 {
     const char tlv4 [ ] = "Unknown\n";
    	cgc_printf(tlv4);
 }
    } else {
	cgc_printf("@s\n", co->seat);
    }
    if (co->population >= 0) {
	cgc_printf("\t\t\t\tPopulation: @d\n", co->population);
    }
    if (co->area >= 0) {
	cgc_printf("\t\t\t\tArea: @f\n", co->area);
    }
    if (co->density >= 0) {
	cgc_printf("\t\t\t\tDensity: @f\n", co->density);
    }
    for (index = 0; index < co->border_count; index++) {
	cgc_printf("\t\t\t\tBorder: @f @f @f @f\n", co->borders[index]->latStart, co->borders[index]->lngStart, co->borders[index]->latEnd, co->borders[index]->lngEnd);
    }
    for (index = 0; index < COUNTYCITYMAX; index++) {
	if (co->cities[index] != NULL) {
     {
         pCity tlv5;
         tlv5 = co -> cities [ index ];
    	    cgc_printCityInfo(tlv5);
     }
	}
    }
    return;
}

void fix_ingred_countyParsers_4_0_1();
void fix_ingred_countyParsers_4_0_5();
void fix_ingred_countyParsers_4_0_6();
void fix_ingred_countyParsers_4_0();
void fix_ingred_countyParsers_4_2_1();
void fix_ingred_countyParsers_4_2();
void fix_ingred_countyParsers_4_4_1();
void fix_ingred_countyParsers_4_4();
void fix_ingred_countyParsers_4_6_7();
void fix_ingred_countyParsers_4_6_8();
void fix_ingred_countyParsers_4_6();
void fix_ingred_countyParsers_4_7_7();
void fix_ingred_countyParsers_4_7();
void fix_ingred_countyParsers_4_9_7();
void fix_ingred_countyParsers_4_9();
void fix_ingred_countyParsers_4_11_7();
void fix_ingred_countyParsers_4_11();
void fix_ingred_countyParsers_4_12_0();
void fix_ingred_countyParsers_4_12_1();
void fix_ingred_countyParsers_4_12();
void fix_ingred_countyParsers_4_13_1();
void fix_ingred_countyParsers_4_13();
void fix_ingred_countyParsers_4_15_0();
void fix_ingred_countyParsers_4_15();
void fix_ingred_countyParsers_4_16_8();
void fix_ingred_countyParsers_4_16();
void fix_ingred_countyParsers_4_21_1();
void fix_ingred_countyParsers_4_21();
void fix_ingred_countyParsers_4_26_0();
void fix_ingred_countyParsers_4_26_1();
void fix_ingred_countyParsers_4_26();
void fix_ingred_countyParsers_4_27_0();
void fix_ingred_countyParsers_4_27_2();
void fix_ingred_countyParsers_4_27();
void fix_ingred_countyParsers_4_29_1();
void fix_ingred_countyParsers_4_29();
void fix_ingred_countyParsers_4_33_0();
void fix_ingred_countyParsers_4_33();
void fix_ingred_countyParsers_4_34_0();
void fix_ingred_countyParsers_4_34();
void fix_ingred_countyParsers_4_36_1();
void fix_ingred_countyParsers_4_36();
void fix_ingred_countyParsers_4_46_0();
void fix_ingred_countyParsers_4_46();
void fix_ingred_countyParsers_4_47_12();
void fix_ingred_countyParsers_4_47_13();
void fix_ingred_countyParsers_4_47();
void fix_ingred_countyParsers_4_50_0();
void fix_ingred_countyParsers_4_50();
void fix_ingred_countyParsers_4_51_13();
void fix_ingred_countyParsers_4_51();
void fix_ingred_countyParsers_4_56_1();
void fix_ingred_countyParsers_4_56();
void fix_ingred_countyParsers_4_60_1();
void fix_ingred_countyParsers_4_60();
void fix_ingred_countyParsers_4_61_1();
void fix_ingred_countyParsers_4_61();
void fix_ingred_countyParsers_4_65_1();
void fix_ingred_countyParsers_4_65();
void fix_ingred_countyParsers_4_71_8();
void fix_ingred_countyParsers_4_71();
void fix_ingred_countyParsers_4_73_1();
void fix_ingred_countyParsers_4_73();
void fix_ingred_countyParsers_4_75_1();
void fix_ingred_countyParsers_4_75();
void fix_ingred_countyParsers_4();
pCounty cgc_countyTopLevel(pstring str)
{
if (fix_ingred_enable){ fix_ingred_countyParsers_4(); };
    pCounty newCounty;
    newCounty = NULL;
    int startIndex;
    startIndex = 0;
    int endIndex;
    endIndex = 0;
    int lastGood;
    lastGood = 0;
    int tempInt;
    tempInt = 0;
    char* tempChar;
     tempChar = NULL;
    element el;
    if (str == NULL) {
	return NULL;
    }
    cgc_skipWhiteSpace(str);
    lastGood = str->index;
    int tlv1;
    {
        pstring tlv24;
        tlv24 = str;
        char tlv23;
        tlv23 = '{';
        tlv1 = cgc_atChar(tlv24,tlv23);
    }
    if (!tlv1) {
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
    {
        pstring tlv25;
        tlv25 = str;
        endIndex = cgc_skipAlpha(tlv25);
    }
    if (endIndex == -1) {
	goto end;
    }
    if (startIndex == endIndex) {
	goto end;
    }
    {
        pstring tlv28;
        tlv28 = str;
        int tlv27;
        tlv27 = startIndex;
        int tlv26;
        tlv26 = endIndex;
        tempChar = cgc_copyData(tlv28,tlv27,tlv26);
    }
    if (tempChar == NULL) {
	goto end;
    }
    int tlv2;
    {
        const char* tlv30 = tempChar;
        const char tlv29 [ ] = "County";
        tlv2 = cgc_strcmp(tlv30,tlv29);
    }
    if (tlv2 != 0) {
	goto end;
    }
    {
        void* tlv12;
        tlv12 = tempChar;
        cgc_size_t tlv11;
        tlv11 = ( endIndex - startIndex ) + 1;
        cgc_deallocate(tlv12,tlv11);
    }
    cgc_skipWhiteSpace(str);
    int tlv3;
    {
        pstring tlv32;
        tlv32 = str;
        char tlv31;
        tlv31 = '}';
        tlv3 = cgc_atChar(tlv32,tlv31);
    }
    if (!tlv3) {
	goto end;
    }
    cgc_skipWhiteSpace(str);
    /// Skip past the closing brace
    cgc_incChar(str);
    int tlv4;
    {
        cgc_size_t tlv35;
        tlv35 = sizeof ( County );
        int tlv34;
        tlv34 = 0;
        void** tlv33;
        tlv33 = ( void * * ) & newCounty;
        tlv4 = cgc_allocate(tlv35,tlv34,tlv33);
    }
    if (tlv4 != 0) {
	newCounty = NULL;
	goto end;
    }
    lastGood = str->index;
    cgc_initCounty(newCounty);
    {
        pstring tlv36;
        tlv36 = str;
        tempChar = cgc_pullNextElementName(tlv36);
    }
    while (tempChar != NULL) {
 {
     char* tlv54;
      tlv54 = tempChar;
    	el = cgc_elementNameToEnum(tlv54);
 }
 {
     void* tlv49;
     tlv49 = tempChar;
     cgc_size_t tlv48;
     {
         char* tlv79;
          tlv79 = tempChar;
         tlv48 = cgc_strlen(tlv79) + 1;
     }
    	cgc_deallocate(tlv49,tlv48);
 }
	switch (el) {
	case name:
	    {
  {
      pstring tlv73;
      tlv73 = str;
    		tempChar = cgc_extractName(tlv73);
  }
	    }
	    if (tempChar == NULL) {
		goto error;
	    }

     {
         void* tlv57;
         tlv57 = newCounty -> name;
         cgc_size_t tlv56;
         tlv56 = 20;
    	    cgc_bzero(tlv57,tlv56);
     }
     {
         char* tlv60;
          tlv60 = newCounty -> name;
         char* tlv59;
          tlv59 = tempChar;
         cgc_size_t tlv58;
         tlv58 = 19;
    	    cgc_strncpy(tlv60,tlv59,tlv58);
     }
     {
         void* tlv62;
         tlv62 = tempChar;
         cgc_size_t tlv61;
         {
             char* tlv81;
              tlv81 = tempChar;
             tlv61 = cgc_strlen(tlv81) + 1;
         }
    	    cgc_deallocate(tlv62,tlv61);
     }
	    tempChar = NULL;
	    break;
	case seat:
	    {
  {
      pstring tlv74;
      tlv74 = str;
    		tempChar = cgc_extractSeat(tlv74);
  }
	    }
	    if (tempChar == NULL) {
		goto error;
	    }
     {
         void* tlv64;
         tlv64 = newCounty -> seat;
         cgc_size_t tlv63;
         tlv63 = 20;
    	    cgc_bzero(tlv64,tlv63);
     }
     {
         char* tlv67;
          tlv67 = newCounty -> seat;
         char* tlv66;
          tlv66 = tempChar;
         cgc_size_t tlv65;
         tlv65 = 19;
    	    cgc_strncpy(tlv67,tlv66,tlv65);
     }
     {
         void* tlv69;
         tlv69 = tempChar;
         cgc_size_t tlv68;
         {
             char* tlv82;
              tlv82 = tempChar;
             tlv68 = cgc_strlen(tlv82) + 1;
         }
    	    cgc_deallocate(tlv69,tlv68);
     }
	    tempChar = NULL;
	    break;
	case density:
	    {
  {
      pstring tlv75;
      tlv75 = str;
    		newCounty->density = cgc_extractDensity(tlv75);
  }
	    }
	    if (newCounty->density < 0.0) {
		goto error;
	    }
	    break;
	case population:
	    {
  {
      pstring tlv76;
      tlv76 = str;
    		newCounty->population = cgc_extractPopulation(tlv76);
  }
	    }
	    if (newCounty->population < 0) {
		goto error;
	    }
	    break;
	case area:
	    {
  {
      pstring tlv77;
      tlv77 = str;
    		newCounty->area = cgc_extractArea(tlv77);
  }
	    }
	    if (newCounty->area < 0.0) {
		goto error;
	    }
	    break;
	case border:
	    {
		tempInt = newCounty->border_count;
	    }
	    if (tempInt >= COUNTYBORDERMAX) {
		goto error;
	    }
     {
         pstring tlv70;
         tlv70 = str;
    	    newCounty->borders[tempInt] = cgc_extractBorder(tlv70);
     }
	    if (newCounty->borders[tempInt] == NULL) {
		goto error;
	    }
	    newCounty->border_count++;
	    break;
	case city:
	    {
		tempInt = newCounty->city_count;
	    }
	    if (tempInt >= COUNTYCITYMAX) {
		goto error;
	    }
     {
         pstring tlv71;
         tlv71 = str;
    	    newCounty->cities[tempInt] = cgc_cityTopLevel(tlv71);
     }
	    if (newCounty->cities[tempInt] == NULL) {
		goto error;
	    }
	    newCounty->city_count++;
	    break;
	default:
	    {
  {
      const char tlv72 [ ] = "!!Element not allowed\n";
    		cgc_printf(tlv72);
  }
	    }
	    goto error;
	    break;

	};
 {
     pstring tlv51;
     tlv51 = str;
     int* tlv50;
     tlv50 = & lastGood;
    	cgc_getIndex(tlv51,tlv50);
 }
 {
     pstring tlv55;
     tlv55 = str;
    	tempChar = cgc_pullNextElementName(tlv55);
 }
    }
    /// Skip any residual white space
    cgc_skipWhiteSpace(str);
    /// It must be at the final opening brace
    int tlv5;
    {
        pstring tlv38;
        tlv38 = str;
        char tlv37;
        tlv37 = '{';
        tlv5 = cgc_atChar(tlv38,tlv37);
    }
    if (!tlv5) {
	goto error;
    }
    {
        pstring tlv14;
        tlv14 = str;
        int tlv13;
        tlv13 = 1;
        cgc_skipLength(tlv14,tlv13);
    }
    cgc_skipWhiteSpace(str);
    int tlv6;
    {
        pstring tlv40;
        tlv40 = str;
        char tlv39;
        tlv39 = '#';
        tlv6 = cgc_atChar(tlv40,tlv39);
    }
    if (!tlv6) {
	goto error;
    }
    {
        pstring tlv16;
        tlv16 = str;
        int tlv15;
        tlv15 = 1;
        cgc_skipLength(tlv16,tlv15);
    }

    {
        pstring tlv18;
        tlv18 = str;
        int* tlv17;
        tlv17 = & startIndex;
        cgc_getIndex(tlv18,tlv17);
    }
    cgc_skipAlpha(str);
    {
        pstring tlv20;
        tlv20 = str;
        int* tlv19;
        tlv19 = & endIndex;
        cgc_getIndex(tlv20,tlv19);
    }
    if (startIndex == endIndex) {
	goto error;
    } else {
	if (endIndex == -1) {
	    goto error;
	}
    }
    {
        pstring tlv43;
        tlv43 = str;
        int tlv42;
        tlv42 = startIndex;
        int tlv41;
        tlv41 = endIndex;
        tempChar = cgc_copyData(tlv43,tlv42,tlv41);
    }
    int tlv7;
    {
        const char* tlv45 = tempChar;
        const char tlv44 [ ] = "County";
        tlv7 = cgc_strcmp(tlv45,tlv44);
    }
    if (tlv7 != 0) {
 {
     void* tlv53;
     tlv53 = tempChar;
     cgc_size_t tlv52;
     {
         char* tlv80;
          tlv80 = tempChar;
         tlv52 = cgc_strlen(tlv80) + 1;
     }
    	cgc_deallocate(tlv53,tlv52);
 }
	goto error;
    }
    {
        void* tlv22;
        tlv22 = tempChar;
        cgc_size_t tlv21;
        {
            char* tlv78;
             tlv78 = tempChar;
            tlv21 = cgc_strlen(tlv78) + 1;
        }
        cgc_deallocate(tlv22,tlv21);
    }
    cgc_skipWhiteSpace(str);

    int tlv8;
    {
        pstring tlv47;
        tlv47 = str;
        char tlv46;
        tlv46 = '}';
        tlv8 = cgc_atChar(tlv47,tlv46);
    }
    if (!tlv8) {
	goto error;
    }
    cgc_incChar(str);
    goto end;
  error:
    if (newCounty) {
	cgc_freeCounty(newCounty);
	newCounty = NULL;
    }
    cgc_printf("!!Error at: @s\n", str->buffer + lastGood);
    str->index = lastGood;
  end:
    return newCounty;
}

void fix_ingred_countyParsers_5_0_0();
void fix_ingred_countyParsers_5_0_3();
void fix_ingred_countyParsers_5_0_4();
void fix_ingred_countyParsers_5_0();
void fix_ingred_countyParsers_5_2_1();
void fix_ingred_countyParsers_5_2();
void fix_ingred_countyParsers_5_4_4();
void fix_ingred_countyParsers_5_4();
void fix_ingred_countyParsers_5_5_1();
void fix_ingred_countyParsers_5_5();
void fix_ingred_countyParsers_5_9_4();
void fix_ingred_countyParsers_5_9_5();
void fix_ingred_countyParsers_5_9();
void fix_ingred_countyParsers_5_11_4();
void fix_ingred_countyParsers_5_11();
void fix_ingred_countyParsers_5_15_4();
void fix_ingred_countyParsers_5_15();
void fix_ingred_countyParsers_5_16_0();
void fix_ingred_countyParsers_5_16();
void fix_ingred_countyParsers_5_17_0();
void fix_ingred_countyParsers_5_17_1();
void fix_ingred_countyParsers_5_17();
void fix_ingred_countyParsers_5_19_1();
void fix_ingred_countyParsers_5_19();
void fix_ingred_countyParsers_5();
int cgc_checkId(pstring str, char *id, int ending)
{
if (fix_ingred_enable){ fix_ingred_countyParsers_5(); };
    int retval;
    retval = 0;
    int startIndex;
    startIndex = 0;
    int endIndex;
    endIndex = 0;
    char* temp;
     temp = NULL;
    if (str == NULL) {
	goto end;
    }
    cgc_skipWhiteSpace(str);

    int tlv1;
    {
        pstring tlv7;
        tlv7 = str;
        char tlv6;
        tlv6 = '{';
        tlv1 = cgc_atChar(tlv7,tlv6);
    }
    if (!tlv1) {
	goto end;
    }
    cgc_incChar(str);
    /// If it is the end check for #
    if (ending == 1) {
	cgc_skipWhiteSpace(str);
 int tlv3;
 {
     pstring tlv18;
     tlv18 = str;
     char tlv17;
     tlv17 = '#';
     tlv3 = cgc_atChar(tlv18,tlv17);
 }
	if (!tlv3) {
	    goto end;
	}
	cgc_incChar(str);
    }
    {
        pstring tlv8;
        tlv8 = str;
        startIndex = cgc_skipWhiteSpace(tlv8);
    }
    {
        pstring tlv9;
        tlv9 = str;
        endIndex = cgc_skipAlpha(tlv9);
    }
    if (endIndex == -1) {
	goto end;
    } else {
	if (startIndex == endIndex) {
	    goto end;
	}
    }
    {
        pstring tlv12;
        tlv12 = str;
        int tlv11;
        tlv11 = startIndex;
        int tlv10;
        tlv10 = endIndex;
        temp = cgc_copyData(tlv12,tlv11,tlv10);
    }
    if (!temp) {
	goto end;
    }
    int tlv2;
    {
        const char* tlv14 = temp;
        const char* tlv13 = id;
        tlv2 = cgc_strcmp(tlv14,tlv13);
    }
    if (tlv2 != 0) {
 {
     void* tlv16;
     tlv16 = temp;
     cgc_size_t tlv15;
     {
         char* tlv20;
          tlv20 = temp;
         tlv15 = cgc_strlen(tlv20) + 1;
     }
    	cgc_deallocate(tlv16,tlv15);
 }
	goto end;
    }
    {
        void* tlv5;
        tlv5 = temp;
        cgc_size_t tlv4;
        {
            char* tlv19;
             tlv19 = temp;
            tlv4 = cgc_strlen(tlv19) + 1;
        }
        cgc_deallocate(tlv5,tlv4);
    }
    cgc_skipWhiteSpace(str);
    if (str->buffer[str->index] != '}') {
	goto end;
    }
    cgc_incChar(str);
    retval = 1;
  end:
    return retval;
}

void fix_ingred_countyParsers_6_0_0();
void fix_ingred_countyParsers_6_0_3();
void fix_ingred_countyParsers_6_0_4();
void fix_ingred_countyParsers_6_0();
void fix_ingred_countyParsers_6_2_1();
void fix_ingred_countyParsers_6_2();
void fix_ingred_countyParsers_6_4_5();
void fix_ingred_countyParsers_6_4();
void fix_ingred_countyParsers_6_9_1();
void fix_ingred_countyParsers_6_9_2();
void fix_ingred_countyParsers_6_9();
void fix_ingred_countyParsers_6_10_5();
void fix_ingred_countyParsers_6_10();
void fix_ingred_countyParsers_6_12_0();
void fix_ingred_countyParsers_6_12_1();
void fix_ingred_countyParsers_6_12();
void fix_ingred_countyParsers_6_13_1();
void fix_ingred_countyParsers_6_13();
void fix_ingred_countyParsers_6_14_6();
void fix_ingred_countyParsers_6_14();
void fix_ingred_countyParsers_6();
double cgc_extractDensity(pstring str)
{
if (fix_ingred_enable){ fix_ingred_countyParsers_6(); };
    double density;
    density = - 1.0;
    register int startIndex;
    startIndex = 0;
    register int endIndex;
    endIndex = 0;
    char* temp;
     temp = NULL;
    int lastGood;
    lastGood = 0;
    if (str == NULL) {
	goto end;
    }
    {
        pstring tlv4;
        tlv4 = str;
        int* tlv3;
        tlv3 = & lastGood;
        cgc_getIndex(tlv4,tlv3);
    }
    int tlv1;
    {
        pstring tlv9;
        tlv9 = str;
        char tlv8[] = "Density";
        int tlv7;
        tlv7 = 0;
        tlv1 = cgc_checkId(tlv9,tlv8,tlv7);
    }
    if (tlv1 == 0) {
	goto error;
    }
    {
        pstring tlv10;
        tlv10 = str;
        startIndex = cgc_skipWhiteSpace(tlv10);
    }
    {
        pstring tlv11;
        tlv11 = str;
        endIndex = cgc_skipFloat(tlv11);
    }
    if (startIndex == endIndex) {
	goto end;
    }
    if (endIndex == -1) {
	goto end;
    }
    {
        pstring tlv14;
        tlv14 = str;
        int tlv13;
        tlv13 = startIndex;
        int tlv12;
        tlv12 = endIndex;
        temp = cgc_copyData(tlv14,tlv13,tlv12);
    }
    if (temp == NULL) {
	goto end;
    }
    {
        const char* tlv15 = temp;
        density = cgc_atof(tlv15);
    }
    {
        void* tlv6;
        tlv6 = temp;
        cgc_size_t tlv5;
        tlv5 = ( endIndex - startIndex ) + 1;
        cgc_deallocate(tlv6,tlv5);
    }
    temp = NULL;
    int tlv2;
    {
        pstring tlv18;
        tlv18 = str;
        char tlv17[] = "Density";
        int tlv16;
        tlv16 = 1;
        tlv2 = cgc_checkId(tlv18,tlv17,tlv16);
    }
    if (tlv2 == 0) {
	goto error;
    }
    goto end;

  error:
    str->index = lastGood;
    density = -1.0;
  end:
    return density;
}

void fix_ingred_countyParsers_7_0_0();
void fix_ingred_countyParsers_7_0_1();
void fix_ingred_countyParsers_7_0_3();
void fix_ingred_countyParsers_7_0();
void fix_ingred_countyParsers_7_2_1();
void fix_ingred_countyParsers_7_2();
void fix_ingred_countyParsers_7_4_1();
void fix_ingred_countyParsers_7_4();
void fix_ingred_countyParsers_7_6_5();
void fix_ingred_countyParsers_7_6_6();
void fix_ingred_countyParsers_7_6_7();
void fix_ingred_countyParsers_7_6();
void fix_ingred_countyParsers_7_10_5();
void fix_ingred_countyParsers_7_10();
void fix_ingred_countyParsers_7_11_0();
void fix_ingred_countyParsers_7_11();
void fix_ingred_countyParsers_7_12_0();
void fix_ingred_countyParsers_7_12_1();
void fix_ingred_countyParsers_7_12();
void fix_ingred_countyParsers_7_14_1();
void fix_ingred_countyParsers_7_14();
void fix_ingred_countyParsers_7_23_1();
void fix_ingred_countyParsers_7_23();
void fix_ingred_countyParsers_7_24_1();
void fix_ingred_countyParsers_7_24();
void fix_ingred_countyParsers_7_26_1();
void fix_ingred_countyParsers_7_26();
void fix_ingred_countyParsers_7_33_6();
void fix_ingred_countyParsers_7_33();
void fix_ingred_countyParsers_7_35_1();
void fix_ingred_countyParsers_7_35();
void fix_ingred_countyParsers_7_37_1();
void fix_ingred_countyParsers_7_37();
void fix_ingred_countyParsers_7_38_1();
void fix_ingred_countyParsers_7_38();
void fix_ingred_countyParsers_7();
double cgc_extractArea(pstring str)
{
if (fix_ingred_enable){ fix_ingred_countyParsers_7(); };
    double area;
    area = - 1.0;
    int startIndex;
    startIndex = 0;
    int endIndex;
    endIndex = 0;
    char* temp;
     temp = NULL;
    int lastGood;
    lastGood = 0;
    if (str == NULL) {
	goto end;
    }
    cgc_skipWhiteSpace(str);
    {
        pstring tlv7;
        tlv7 = str;
        int* tlv6;
        tlv6 = & lastGood;
        cgc_getIndex(tlv7,tlv6);
    }

    if (str->buffer[str->index] != '{') {
	goto end;
    }
    cgc_incChar(str);
    cgc_skipWhiteSpace(str);
    {
        pstring tlv9;
        tlv9 = str;
        int* tlv8;
        tlv8 = & startIndex;
        cgc_getIndex(tlv9,tlv8);
    }
    {
        pstring tlv16;
        tlv16 = str;
        endIndex = cgc_skipAlpha(tlv16);
    }
    if (endIndex == -1 || startIndex == endIndex) {
	goto end;
    }
    {
        pstring tlv19;
        tlv19 = str;
        int tlv18;
        tlv18 = startIndex;
        int tlv17;
        tlv17 = endIndex;
        temp = cgc_copyData(tlv19,tlv18,tlv17);
    }
    if (!temp) {
	goto end;
    }
    int tlv1;
    {
        const char* tlv21 = temp;
        const char tlv20 [ ] = "Area";
        tlv1 = cgc_strcmp(tlv21,tlv20);
    }
    if (tlv1 != 0) {
 {
     void* tlv42;
     tlv42 = temp;
     cgc_size_t tlv41;
     {
         char* tlv47;
          tlv47 = temp;
         tlv41 = cgc_strlen(tlv47) + 1;
     }
    	cgc_deallocate(tlv42,tlv41);
 }
	goto end;
    }
    {
        void* tlv11;
        tlv11 = temp;
        cgc_size_t tlv10;
        {
            char* tlv45;
             tlv45 = temp;
            tlv10 = cgc_strlen(tlv45) + 1;
        }
        cgc_deallocate(tlv11,tlv10);
    }
    cgc_skipWhiteSpace(str);
    if (str->buffer[str->index] != '}') {
	goto end;
    }
    cgc_incChar(str);
    {
        pstring tlv22;
        tlv22 = str;
        startIndex = cgc_skipWhiteSpace(tlv22);
    }
    {
        pstring tlv23;
        tlv23 = str;
        endIndex = cgc_skipFloat(tlv23);
    }
    if (startIndex == endIndex) {
	goto end;
    }
    if (endIndex == -1) {
	goto end;
    }
    {
        pstring tlv26;
        tlv26 = str;
        int tlv25;
        tlv25 = startIndex;
        int tlv24;
        tlv24 = endIndex;
        temp = cgc_copyData(tlv26,tlv25,tlv24);
    }
    if (temp == NULL) {
	goto end;
    }
    {
        const char* tlv27 = temp;
        area = cgc_atof(tlv27);
    }
    {
        void* tlv13;
        tlv13 = temp;
        cgc_size_t tlv12;
        tlv12 = ( endIndex - startIndex ) + 1;
        cgc_deallocate(tlv13,tlv12);
    }
    temp = NULL;
    cgc_skipWhiteSpace(str);
    int tlv2;
    {
        pstring tlv29;
        tlv29 = str;
        char tlv28;
        tlv28 = '{';
        tlv2 = cgc_atChar(tlv29,tlv28);
    }
    if (!tlv2) {
	goto error;
    }
    cgc_incChar(str);
    cgc_skipWhiteSpace(str);
    int tlv3;
    {
        pstring tlv31;
        tlv31 = str;
        char tlv30;
        tlv30 = '#';
        tlv3 = cgc_atChar(tlv31,tlv30);
    }
    if (!tlv3) {
	goto error;
    }
    {
        pstring tlv32;
        tlv32 = str;
        startIndex = cgc_incChar(tlv32);
    }
    {
        pstring tlv33;
        tlv33 = str;
        endIndex = cgc_skipAlpha(tlv33);
    }
    {
        pstring tlv36;
        tlv36 = str;
        int tlv35;
        tlv35 = startIndex;
        int tlv34;
        tlv34 = endIndex;
        temp = cgc_copyData(tlv36,tlv35,tlv34);
    }
    if (temp == NULL) {
	goto error;
    }
    int tlv4;
    {
        const char* tlv38 = temp;
        const char tlv37 [ ] = "Area";
        tlv4 = cgc_strcmp(tlv38,tlv37);
    }
    if (tlv4 != 0) {
 {
     void* tlv44;
     tlv44 = temp;
     cgc_size_t tlv43;
     {
         char* tlv48;
          tlv48 = temp;
         tlv43 = cgc_strlen(tlv48) + 1;
     }
    	cgc_deallocate(tlv44,tlv43);
 }
	goto error;
    }
    {
        void* tlv15;
        tlv15 = temp;
        cgc_size_t tlv14;
        {
            char* tlv46;
             tlv46 = temp;
            tlv14 = cgc_strlen(tlv46) + 1;
        }
        cgc_deallocate(tlv15,tlv14);
    }
    cgc_skipWhiteSpace(str);
    int tlv5;
    {
        pstring tlv40;
        tlv40 = str;
        char tlv39;
        tlv39 = '}';
        tlv5 = cgc_atChar(tlv40,tlv39);
    }
    if (!tlv5) {
	goto error;
    }
    cgc_incChar(str);

    goto end;

  error:
    str->index = lastGood;
    area = -1.0;
  end:
    return area;
}

void fix_ingred_countyParsers_8_0_0();
void fix_ingred_countyParsers_8_0_1();
void fix_ingred_countyParsers_8_0();
void fix_ingred_countyParsers_8_2_1();
void fix_ingred_countyParsers_8_2();
void fix_ingred_countyParsers_8_4_1();
void fix_ingred_countyParsers_8_4();
void fix_ingred_countyParsers_8_6_5();
void fix_ingred_countyParsers_8_6_6();
void fix_ingred_countyParsers_8_6_7();
void fix_ingred_countyParsers_8_6();
void fix_ingred_countyParsers_8_10_5();
void fix_ingred_countyParsers_8_10();
void fix_ingred_countyParsers_8_11_0();
void fix_ingred_countyParsers_8_11();
void fix_ingred_countyParsers_8_12_0();
void fix_ingred_countyParsers_8_12_1();
void fix_ingred_countyParsers_8_12();
void fix_ingred_countyParsers_8_14_1();
void fix_ingred_countyParsers_8_14();
void fix_ingred_countyParsers_8_21_5();
void fix_ingred_countyParsers_8_21();
void fix_ingred_countyParsers_8_22_1();
void fix_ingred_countyParsers_8_22();
void fix_ingred_countyParsers_8_24_1();
void fix_ingred_countyParsers_8_24();
void fix_ingred_countyParsers_8_33_5();
void fix_ingred_countyParsers_8_33();
void fix_ingred_countyParsers_8_35_1();
void fix_ingred_countyParsers_8_35();
void fix_ingred_countyParsers_8_37_1();
void fix_ingred_countyParsers_8_37();
void fix_ingred_countyParsers_8_38_1();
void fix_ingred_countyParsers_8_38();
void fix_ingred_countyParsers_8_41_0();
void fix_ingred_countyParsers_8_41();
void fix_ingred_countyParsers_8_42_1();
void fix_ingred_countyParsers_8_42();
void fix_ingred_countyParsers_8();
char *cgc_extractSeat(pstring str)
{
if (fix_ingred_enable){ fix_ingred_countyParsers_8(); };
    char* seat;
     seat = NULL;
    int startIndex;
    startIndex = 0;
    int endIndex;
    endIndex = 0;
    char* temp;
     temp = NULL;
    int lastGood;
    lastGood = 0;
    if (str == NULL) {
	goto end;
    }
    cgc_skipWhiteSpace(str);
    {
        pstring tlv7;
        tlv7 = str;
        int* tlv6;
        tlv6 = & lastGood;
        cgc_getIndex(tlv7,tlv6);
    }

    if (str->buffer[str->index] != '{') {
	goto end;
    }
    cgc_incChar(str);
    cgc_skipWhiteSpace(str);
    {
        pstring tlv9;
        tlv9 = str;
        int* tlv8;
        tlv8 = & startIndex;
        cgc_getIndex(tlv9,tlv8);
    }
    {
        pstring tlv14;
        tlv14 = str;
        endIndex = cgc_skipAlpha(tlv14);
    }
    if (endIndex == -1 || startIndex == endIndex) {
	goto end;
    }
    {
        pstring tlv17;
        tlv17 = str;
        int tlv16;
        tlv16 = startIndex;
        int tlv15;
        tlv15 = endIndex;
        temp = cgc_copyData(tlv17,tlv16,tlv15);
    }
    if (!temp) {
	goto end;
    }
    int tlv1;
    {
        const char* tlv19 = temp;
        const char tlv18 [ ] = "Seat";
        tlv1 = cgc_strcmp(tlv19,tlv18);
    }
    if (tlv1 != 0) {
 {
     void* tlv39;
     tlv39 = temp;
     cgc_size_t tlv38;
     {
         char* tlv46;
          tlv46 = temp;
         tlv38 = cgc_strlen(tlv46) + 1;
     }
    	cgc_deallocate(tlv39,tlv38);
 }
	goto end;
    }
    {
        void* tlv11;
        tlv11 = temp;
        cgc_size_t tlv10;
        {
            char* tlv44;
             tlv44 = temp;
            tlv10 = cgc_strlen(tlv44) + 1;
        }
        cgc_deallocate(tlv11,tlv10);
    }
    cgc_skipWhiteSpace(str);
    if (str->buffer[str->index] != '}') {
	goto end;
    }
    cgc_incChar(str);
    {
        pstring tlv20;
        tlv20 = str;
        startIndex = cgc_skipWhiteSpace(tlv20);
    }
    {
        pstring tlv21;
        tlv21 = str;
        endIndex = cgc_skipAlpha(tlv21);
    }
    if (startIndex == endIndex) {
	goto end;
    }
    if (endIndex == -1) {
	goto end;
    }
    {
        pstring tlv24;
        tlv24 = str;
        int tlv23;
        tlv23 = startIndex;
        int tlv22;
        tlv22 = endIndex;
        seat = cgc_copyData(tlv24,tlv23,tlv22);
    }
    if (seat == NULL) {
	goto end;
    }
    cgc_skipWhiteSpace(str);
    int tlv2;
    {
        pstring tlv26;
        tlv26 = str;
        char tlv25;
        tlv25 = '{';
        tlv2 = cgc_atChar(tlv26,tlv25);
    }
    if (!tlv2) {
	goto error;
    }
    cgc_incChar(str);
    cgc_skipWhiteSpace(str);
    int tlv3;
    {
        pstring tlv28;
        tlv28 = str;
        char tlv27;
        tlv27 = '#';
        tlv3 = cgc_atChar(tlv28,tlv27);
    }
    if (!tlv3) {
	goto error;
    }
    {
        pstring tlv29;
        tlv29 = str;
        startIndex = cgc_incChar(tlv29);
    }
    {
        pstring tlv30;
        tlv30 = str;
        endIndex = cgc_skipAlpha(tlv30);
    }
    if (startIndex == endIndex) {
	goto error;
    }
    if (endIndex == -1) {
	goto error;
    }
    {
        pstring tlv33;
        tlv33 = str;
        int tlv32;
        tlv32 = startIndex;
        int tlv31;
        tlv31 = endIndex;
        temp = cgc_copyData(tlv33,tlv32,tlv31);
    }
    if (temp == NULL) {
	goto error;
    }
    int tlv4;
    {
        const char* tlv35 = temp;
        const char tlv34 [ ] = "Seat";
        tlv4 = cgc_strcmp(tlv35,tlv34);
    }
    if (tlv4 != 0) {
 {
     void* tlv41;
     tlv41 = temp;
     cgc_size_t tlv40;
     {
         char* tlv47;
          tlv47 = temp;
         tlv40 = cgc_strlen(tlv47) + 1;
     }
    	cgc_deallocate(tlv41,tlv40);
 }
	goto error;
    }
    {
        void* tlv13;
        tlv13 = temp;
        cgc_size_t tlv12;
        {
            char* tlv45;
             tlv45 = temp;
            tlv12 = cgc_strlen(tlv45) + 1;
        }
        cgc_deallocate(tlv13,tlv12);
    }
    cgc_skipWhiteSpace(str);
    int tlv5;
    {
        pstring tlv37;
        tlv37 = str;
        char tlv36;
        tlv36 = '}';
        tlv5 = cgc_atChar(tlv37,tlv36);
    }
    if (!tlv5) {
	goto error;
    }
    cgc_incChar(str);

    goto end;

  error:
    if (seat) {
 {
     void* tlv43;
     tlv43 = seat;
     cgc_size_t tlv42;
     {
         char* tlv48;
          tlv48 = seat;
         tlv42 = cgc_strlen(tlv48) + 1;
     }
    	cgc_deallocate(tlv43,tlv42);
 }
	seat = NULL;
    }
    str->index = lastGood;
  end:
    return seat;
}

void fix_ingred_countyParsers_0_0_0(){
    {int choice; choice = (int)(0); }
    {char selection [ 30 ]; selection [ ( 30 )-1 ] = (char)(0); }
    {void * tlv16; tlv16 = (void *)(0); }
    {cgc_size_t tlv15; tlv15 = (cgc_size_t)(0); }
    {char * tlv19; tlv19 = (char *)(0); }
    {char tlv18; tlv18 = (char)(0); }
    {cgc_size_t tlv17; tlv17 = (cgc_size_t)(0); }
    {void * tlv21; tlv21 = (void *)(0); }
    {cgc_size_t tlv20; tlv20 = (cgc_size_t)(0); }
    {int tlv1; tlv1 = (int)(0); }
    {int tlv2; tlv2 = (int)(0); }
    {int tlv3; tlv3 = (int)(0); }
    {char * tlv25; tlv25 = (char *)(0); }
    {char tlv24; tlv24 = (char)(0); }
    {cgc_size_t tlv23; tlv23 = (cgc_size_t)(0); }
    {char * tlv28; tlv28 = (char *)(0); }
    {char tlv27; tlv27 = (char)(0); }
    {cgc_size_t tlv26; tlv26 = (cgc_size_t)(0); }
    {char * tlv31; tlv31 = (char *)(0); }
    {char tlv30; tlv30 = (char)(0); }
    {cgc_size_t tlv29; tlv29 = (cgc_size_t)(0); }
    {char * tlv34; tlv34 = (char *)(0); }
    {char tlv33; tlv33 = (char)(0); }
    {cgc_size_t tlv32; tlv32 = (cgc_size_t)(0); }
    {cgc_size_t tlv74; tlv74 = (cgc_size_t)(0); }
    {int tlv73; tlv73 = (int)(0); }
    {void * tlv37; tlv37 = (void *)(0); }
    {cgc_size_t tlv36; tlv36 = (cgc_size_t)(0); }
    {char * tlv40; tlv40 = (char *)(0); }
    {char tlv39; tlv39 = (char)(0); }
    {cgc_size_t tlv38; tlv38 = (cgc_size_t)(0); }
    {void * tlv43; tlv43 = (void *)(0); }
    {cgc_size_t tlv42; tlv42 = (cgc_size_t)(0); }
    {char * tlv46; tlv46 = (char *)(0); }
    {char tlv45; tlv45 = (char)(0); }
    {cgc_size_t tlv44; tlv44 = (cgc_size_t)(0); }
    {void * tlv49; tlv49 = (void *)(0); }
    {cgc_size_t tlv48; tlv48 = (cgc_size_t)(0); }
    {char * tlv52; tlv52 = (char *)(0); }
    {char tlv51; tlv51 = (char)(0); }
    {cgc_size_t tlv50; tlv50 = (cgc_size_t)(0); }
    {void * tlv55; tlv55 = (void *)(0); }
    {cgc_size_t tlv54; tlv54 = (cgc_size_t)(0); }
    {char * tlv58; tlv58 = (char *)(0); }
    {char tlv57; tlv57 = (char)(0); }
    {cgc_size_t tlv56; tlv56 = (cgc_size_t)(0); }
    {cgc_size_t tlv81; tlv81 = (cgc_size_t)(0); }
    {int tlv80; tlv80 = (int)(0); }
    {char * tlv62; tlv62 = (char *)(0); }
    {char tlv61; tlv61 = (char)(0); }
    {cgc_size_t tlv60; tlv60 = (cgc_size_t)(0); }
    {void * tlv65; tlv65 = (void *)(0); }
    {cgc_size_t tlv64; tlv64 = (cgc_size_t)(0); }
    {char * tlv68; tlv68 = (char *)(0); }
    {char tlv67; tlv67 = (char)(0); }
    {cgc_size_t tlv66; tlv66 = (cgc_size_t)(0); }
}
void fix_ingred_countyParsers_0_0(){
fix_ingred_countyParsers_0_0_0();
}
void fix_ingred_countyParsers_0_14_0(){
char selection [ 30 ];
    bzero(&selection,( 30 *sizeof(char) ) );
    {int choice; choice = (int)(selection); }
    {char selection [ 30 ]; selection [ ( 30 )-1 ] = (char)(selection); }
    {void * tlv16; tlv16 = (void *)(selection); }
    {cgc_size_t tlv15; tlv15 = (cgc_size_t)(selection); }
    {char * tlv19; tlv19 = (char *)(selection); }
    {char tlv18; tlv18 = (char)(selection); }
    {cgc_size_t tlv17; tlv17 = (cgc_size_t)(selection); }
    {void * tlv21; tlv21 = (void *)(selection); }
    {cgc_size_t tlv20; tlv20 = (cgc_size_t)(selection); }
    {int tlv1; tlv1 = (int)(selection); }
    {int tlv2; tlv2 = (int)(selection); }
    {int tlv3; tlv3 = (int)(selection); }
    {char * tlv25; tlv25 = (char *)(selection); }
    {char tlv24; tlv24 = (char)(selection); }
    {cgc_size_t tlv23; tlv23 = (cgc_size_t)(selection); }
    {char * tlv28; tlv28 = (char *)(selection); }
    {char tlv27; tlv27 = (char)(selection); }
    {cgc_size_t tlv26; tlv26 = (cgc_size_t)(selection); }
    {char * tlv31; tlv31 = (char *)(selection); }
    {char tlv30; tlv30 = (char)(selection); }
    {cgc_size_t tlv29; tlv29 = (cgc_size_t)(selection); }
    {char * tlv34; tlv34 = (char *)(selection); }
    {char tlv33; tlv33 = (char)(selection); }
    {cgc_size_t tlv32; tlv32 = (cgc_size_t)(selection); }
    {cgc_size_t tlv74; tlv74 = (cgc_size_t)(selection); }
    {int tlv73; tlv73 = (int)(selection); }
    {void * tlv37; tlv37 = (void *)(selection); }
    {cgc_size_t tlv36; tlv36 = (cgc_size_t)(selection); }
    {char * tlv40; tlv40 = (char *)(selection); }
    {char tlv39; tlv39 = (char)(selection); }
    {cgc_size_t tlv38; tlv38 = (cgc_size_t)(selection); }
    {void * tlv43; tlv43 = (void *)(selection); }
    {cgc_size_t tlv42; tlv42 = (cgc_size_t)(selection); }
    {char * tlv46; tlv46 = (char *)(selection); }
    {char tlv45; tlv45 = (char)(selection); }
    {cgc_size_t tlv44; tlv44 = (cgc_size_t)(selection); }
    {void * tlv49; tlv49 = (void *)(selection); }
    {cgc_size_t tlv48; tlv48 = (cgc_size_t)(selection); }
    {char * tlv52; tlv52 = (char *)(selection); }
    {char tlv51; tlv51 = (char)(selection); }
    {cgc_size_t tlv50; tlv50 = (cgc_size_t)(selection); }
    {void * tlv55; tlv55 = (void *)(selection); }
    {cgc_size_t tlv54; tlv54 = (cgc_size_t)(selection); }
    {char * tlv58; tlv58 = (char *)(selection); }
    {char tlv57; tlv57 = (char)(selection); }
    {cgc_size_t tlv56; tlv56 = (cgc_size_t)(selection); }
    {cgc_size_t tlv81; tlv81 = (cgc_size_t)(selection); }
    {int tlv80; tlv80 = (int)(selection); }
    {char * tlv62; tlv62 = (char *)(selection); }
    {char tlv61; tlv61 = (char)(selection); }
    {cgc_size_t tlv60; tlv60 = (cgc_size_t)(selection); }
    {void * tlv65; tlv65 = (void *)(selection); }
    {cgc_size_t tlv64; tlv64 = (cgc_size_t)(selection); }
    {char * tlv68; tlv68 = (char *)(selection); }
    {char tlv67; tlv67 = (char)(selection); }
    {cgc_size_t tlv66; tlv66 = (cgc_size_t)(selection); }
}
void fix_ingred_countyParsers_0_14_1(){
char selection [ 30 ];
    bzero(&selection,( 30 *sizeof(char) ) );
    {int choice; choice = (int)(4); }
    {char selection [ 30 ]; selection [ ( 30 )-1 ] = (char)(4); }
    {void * tlv16; tlv16 = (void *)(4); }
    {cgc_size_t tlv15; tlv15 = (cgc_size_t)(4); }
    {char * tlv19; tlv19 = (char *)(4); }
    {char tlv18; tlv18 = (char)(4); }
    {cgc_size_t tlv17; tlv17 = (cgc_size_t)(4); }
    {void * tlv21; tlv21 = (void *)(4); }
    {cgc_size_t tlv20; tlv20 = (cgc_size_t)(4); }
    {int tlv1; tlv1 = (int)(4); }
    {int tlv2; tlv2 = (int)(4); }
    {int tlv3; tlv3 = (int)(4); }
    {char * tlv25; tlv25 = (char *)(4); }
    {char tlv24; tlv24 = (char)(4); }
    {cgc_size_t tlv23; tlv23 = (cgc_size_t)(4); }
    {char * tlv28; tlv28 = (char *)(4); }
    {char tlv27; tlv27 = (char)(4); }
    {cgc_size_t tlv26; tlv26 = (cgc_size_t)(4); }
    {char * tlv31; tlv31 = (char *)(4); }
    {char tlv30; tlv30 = (char)(4); }
    {cgc_size_t tlv29; tlv29 = (cgc_size_t)(4); }
    {char * tlv34; tlv34 = (char *)(4); }
    {char tlv33; tlv33 = (char)(4); }
    {cgc_size_t tlv32; tlv32 = (cgc_size_t)(4); }
    {cgc_size_t tlv74; tlv74 = (cgc_size_t)(4); }
    {int tlv73; tlv73 = (int)(4); }
    {void * tlv37; tlv37 = (void *)(4); }
    {cgc_size_t tlv36; tlv36 = (cgc_size_t)(4); }
    {char * tlv40; tlv40 = (char *)(4); }
    {char tlv39; tlv39 = (char)(4); }
    {cgc_size_t tlv38; tlv38 = (cgc_size_t)(4); }
    {void * tlv43; tlv43 = (void *)(4); }
    {cgc_size_t tlv42; tlv42 = (cgc_size_t)(4); }
    {char * tlv46; tlv46 = (char *)(4); }
    {char tlv45; tlv45 = (char)(4); }
    {cgc_size_t tlv44; tlv44 = (cgc_size_t)(4); }
    {void * tlv49; tlv49 = (void *)(4); }
    {cgc_size_t tlv48; tlv48 = (cgc_size_t)(4); }
    {char * tlv52; tlv52 = (char *)(4); }
    {char tlv51; tlv51 = (char)(4); }
    {cgc_size_t tlv50; tlv50 = (cgc_size_t)(4); }
    {void * tlv55; tlv55 = (void *)(4); }
    {cgc_size_t tlv54; tlv54 = (cgc_size_t)(4); }
    {char * tlv58; tlv58 = (char *)(4); }
    {char tlv57; tlv57 = (char)(4); }
    {cgc_size_t tlv56; tlv56 = (cgc_size_t)(4); }
    {cgc_size_t tlv81; tlv81 = (cgc_size_t)(4); }
    {int tlv80; tlv80 = (int)(4); }
    {char * tlv62; tlv62 = (char *)(4); }
    {char tlv61; tlv61 = (char)(4); }
    {cgc_size_t tlv60; tlv60 = (cgc_size_t)(4); }
    {void * tlv65; tlv65 = (void *)(4); }
    {cgc_size_t tlv64; tlv64 = (cgc_size_t)(4); }
    {char * tlv68; tlv68 = (char *)(4); }
    {char tlv67; tlv67 = (char)(4); }
    {cgc_size_t tlv66; tlv66 = (cgc_size_t)(4); }
}
void fix_ingred_countyParsers_0_14(){
fix_ingred_countyParsers_0_14_0();
fix_ingred_countyParsers_0_14_1();
}
void fix_ingred_countyParsers_0_15_0(){
char selection [ 30 ];
    bzero(&selection,( 30 *sizeof(char) ) );
    {int choice; choice = (int)(selection); }
    {char selection [ 30 ]; selection [ ( 30 )-1 ] = (char)(selection); }
    {void * tlv16; tlv16 = (void *)(selection); }
    {cgc_size_t tlv15; tlv15 = (cgc_size_t)(selection); }
    {char * tlv19; tlv19 = (char *)(selection); }
    {char tlv18; tlv18 = (char)(selection); }
    {cgc_size_t tlv17; tlv17 = (cgc_size_t)(selection); }
    {void * tlv21; tlv21 = (void *)(selection); }
    {cgc_size_t tlv20; tlv20 = (cgc_size_t)(selection); }
    {int tlv1; tlv1 = (int)(selection); }
    {int tlv2; tlv2 = (int)(selection); }
    {int tlv3; tlv3 = (int)(selection); }
    {char * tlv25; tlv25 = (char *)(selection); }
    {char tlv24; tlv24 = (char)(selection); }
    {cgc_size_t tlv23; tlv23 = (cgc_size_t)(selection); }
    {char * tlv28; tlv28 = (char *)(selection); }
    {char tlv27; tlv27 = (char)(selection); }
    {cgc_size_t tlv26; tlv26 = (cgc_size_t)(selection); }
    {char * tlv31; tlv31 = (char *)(selection); }
    {char tlv30; tlv30 = (char)(selection); }
    {cgc_size_t tlv29; tlv29 = (cgc_size_t)(selection); }
    {char * tlv34; tlv34 = (char *)(selection); }
    {char tlv33; tlv33 = (char)(selection); }
    {cgc_size_t tlv32; tlv32 = (cgc_size_t)(selection); }
    {cgc_size_t tlv74; tlv74 = (cgc_size_t)(selection); }
    {int tlv73; tlv73 = (int)(selection); }
    {void * tlv37; tlv37 = (void *)(selection); }
    {cgc_size_t tlv36; tlv36 = (cgc_size_t)(selection); }
    {char * tlv40; tlv40 = (char *)(selection); }
    {char tlv39; tlv39 = (char)(selection); }
    {cgc_size_t tlv38; tlv38 = (cgc_size_t)(selection); }
    {void * tlv43; tlv43 = (void *)(selection); }
    {cgc_size_t tlv42; tlv42 = (cgc_size_t)(selection); }
    {char * tlv46; tlv46 = (char *)(selection); }
    {char tlv45; tlv45 = (char)(selection); }
    {cgc_size_t tlv44; tlv44 = (cgc_size_t)(selection); }
    {void * tlv49; tlv49 = (void *)(selection); }
    {cgc_size_t tlv48; tlv48 = (cgc_size_t)(selection); }
    {char * tlv52; tlv52 = (char *)(selection); }
    {char tlv51; tlv51 = (char)(selection); }
    {cgc_size_t tlv50; tlv50 = (cgc_size_t)(selection); }
    {void * tlv55; tlv55 = (void *)(selection); }
    {cgc_size_t tlv54; tlv54 = (cgc_size_t)(selection); }
    {char * tlv58; tlv58 = (char *)(selection); }
    {char tlv57; tlv57 = (char)(selection); }
    {cgc_size_t tlv56; tlv56 = (cgc_size_t)(selection); }
    {cgc_size_t tlv81; tlv81 = (cgc_size_t)(selection); }
    {int tlv80; tlv80 = (int)(selection); }
    {char * tlv62; tlv62 = (char *)(selection); }
    {char tlv61; tlv61 = (char)(selection); }
    {cgc_size_t tlv60; tlv60 = (cgc_size_t)(selection); }
    {void * tlv65; tlv65 = (void *)(selection); }
    {cgc_size_t tlv64; tlv64 = (cgc_size_t)(selection); }
    {char * tlv68; tlv68 = (char *)(selection); }
    {char tlv67; tlv67 = (char)(selection); }
    {cgc_size_t tlv66; tlv66 = (cgc_size_t)(selection); }
}
void fix_ingred_countyParsers_0_15_1(){
char selection [ 30 ];
    bzero(&selection,( 30 *sizeof(char) ) );
    {int choice; choice = (int)('\n'); }
    {char selection [ 30 ]; selection [ ( 30 )-1 ] = (char)('\n'); }
    {void * tlv16; tlv16 = (void *)('\n'); }
    {cgc_size_t tlv15; tlv15 = (cgc_size_t)('\n'); }
    {char * tlv19; tlv19 = (char *)('\n'); }
    {char tlv18; tlv18 = (char)('\n'); }
    {cgc_size_t tlv17; tlv17 = (cgc_size_t)('\n'); }
    {void * tlv21; tlv21 = (void *)('\n'); }
    {cgc_size_t tlv20; tlv20 = (cgc_size_t)('\n'); }
    {int tlv1; tlv1 = (int)('\n'); }
    {int tlv2; tlv2 = (int)('\n'); }
    {int tlv3; tlv3 = (int)('\n'); }
    {char * tlv25; tlv25 = (char *)('\n'); }
    {char tlv24; tlv24 = (char)('\n'); }
    {cgc_size_t tlv23; tlv23 = (cgc_size_t)('\n'); }
    {char * tlv28; tlv28 = (char *)('\n'); }
    {char tlv27; tlv27 = (char)('\n'); }
    {cgc_size_t tlv26; tlv26 = (cgc_size_t)('\n'); }
    {char * tlv31; tlv31 = (char *)('\n'); }
    {char tlv30; tlv30 = (char)('\n'); }
    {cgc_size_t tlv29; tlv29 = (cgc_size_t)('\n'); }
    {char * tlv34; tlv34 = (char *)('\n'); }
    {char tlv33; tlv33 = (char)('\n'); }
    {cgc_size_t tlv32; tlv32 = (cgc_size_t)('\n'); }
    {cgc_size_t tlv74; tlv74 = (cgc_size_t)('\n'); }
    {int tlv73; tlv73 = (int)('\n'); }
    {void * tlv37; tlv37 = (void *)('\n'); }
    {cgc_size_t tlv36; tlv36 = (cgc_size_t)('\n'); }
    {char * tlv40; tlv40 = (char *)('\n'); }
    {char tlv39; tlv39 = (char)('\n'); }
    {cgc_size_t tlv38; tlv38 = (cgc_size_t)('\n'); }
    {void * tlv43; tlv43 = (void *)('\n'); }
    {cgc_size_t tlv42; tlv42 = (cgc_size_t)('\n'); }
    {char * tlv46; tlv46 = (char *)('\n'); }
    {char tlv45; tlv45 = (char)('\n'); }
    {cgc_size_t tlv44; tlv44 = (cgc_size_t)('\n'); }
    {void * tlv49; tlv49 = (void *)('\n'); }
    {cgc_size_t tlv48; tlv48 = (cgc_size_t)('\n'); }
    {char * tlv52; tlv52 = (char *)('\n'); }
    {char tlv51; tlv51 = (char)('\n'); }
    {cgc_size_t tlv50; tlv50 = (cgc_size_t)('\n'); }
    {void * tlv55; tlv55 = (void *)('\n'); }
    {cgc_size_t tlv54; tlv54 = (cgc_size_t)('\n'); }
    {char * tlv58; tlv58 = (char *)('\n'); }
    {char tlv57; tlv57 = (char)('\n'); }
    {cgc_size_t tlv56; tlv56 = (cgc_size_t)('\n'); }
    {cgc_size_t tlv81; tlv81 = (cgc_size_t)('\n'); }
    {int tlv80; tlv80 = (int)('\n'); }
    {char * tlv62; tlv62 = (char *)('\n'); }
    {char tlv61; tlv61 = (char)('\n'); }
    {cgc_size_t tlv60; tlv60 = (cgc_size_t)('\n'); }
    {void * tlv65; tlv65 = (void *)('\n'); }
    {cgc_size_t tlv64; tlv64 = (cgc_size_t)('\n'); }
    {char * tlv68; tlv68 = (char *)('\n'); }
    {char tlv67; tlv67 = (char)('\n'); }
    {cgc_size_t tlv66; tlv66 = (cgc_size_t)('\n'); }
}
void fix_ingred_countyParsers_0_15_2(){
char selection [ 30 ];
    bzero(&selection,( 30 *sizeof(char) ) );
    {int choice; choice = (int)(3); }
    {char selection [ 30 ]; selection [ ( 30 )-1 ] = (char)(3); }
    {void * tlv16; tlv16 = (void *)(3); }
    {cgc_size_t tlv15; tlv15 = (cgc_size_t)(3); }
    {char * tlv19; tlv19 = (char *)(3); }
    {char tlv18; tlv18 = (char)(3); }
    {cgc_size_t tlv17; tlv17 = (cgc_size_t)(3); }
    {void * tlv21; tlv21 = (void *)(3); }
    {cgc_size_t tlv20; tlv20 = (cgc_size_t)(3); }
    {int tlv1; tlv1 = (int)(3); }
    {int tlv2; tlv2 = (int)(3); }
    {int tlv3; tlv3 = (int)(3); }
    {char * tlv25; tlv25 = (char *)(3); }
    {char tlv24; tlv24 = (char)(3); }
    {cgc_size_t tlv23; tlv23 = (cgc_size_t)(3); }
    {char * tlv28; tlv28 = (char *)(3); }
    {char tlv27; tlv27 = (char)(3); }
    {cgc_size_t tlv26; tlv26 = (cgc_size_t)(3); }
    {char * tlv31; tlv31 = (char *)(3); }
    {char tlv30; tlv30 = (char)(3); }
    {cgc_size_t tlv29; tlv29 = (cgc_size_t)(3); }
    {char * tlv34; tlv34 = (char *)(3); }
    {char tlv33; tlv33 = (char)(3); }
    {cgc_size_t tlv32; tlv32 = (cgc_size_t)(3); }
    {cgc_size_t tlv74; tlv74 = (cgc_size_t)(3); }
    {int tlv73; tlv73 = (int)(3); }
    {void * tlv37; tlv37 = (void *)(3); }
    {cgc_size_t tlv36; tlv36 = (cgc_size_t)(3); }
    {char * tlv40; tlv40 = (char *)(3); }
    {char tlv39; tlv39 = (char)(3); }
    {cgc_size_t tlv38; tlv38 = (cgc_size_t)(3); }
    {void * tlv43; tlv43 = (void *)(3); }
    {cgc_size_t tlv42; tlv42 = (cgc_size_t)(3); }
    {char * tlv46; tlv46 = (char *)(3); }
    {char tlv45; tlv45 = (char)(3); }
    {cgc_size_t tlv44; tlv44 = (cgc_size_t)(3); }
    {void * tlv49; tlv49 = (void *)(3); }
    {cgc_size_t tlv48; tlv48 = (cgc_size_t)(3); }
    {char * tlv52; tlv52 = (char *)(3); }
    {char tlv51; tlv51 = (char)(3); }
    {cgc_size_t tlv50; tlv50 = (cgc_size_t)(3); }
    {void * tlv55; tlv55 = (void *)(3); }
    {cgc_size_t tlv54; tlv54 = (cgc_size_t)(3); }
    {char * tlv58; tlv58 = (char *)(3); }
    {char tlv57; tlv57 = (char)(3); }
    {cgc_size_t tlv56; tlv56 = (cgc_size_t)(3); }
    {cgc_size_t tlv81; tlv81 = (cgc_size_t)(3); }
    {int tlv80; tlv80 = (int)(3); }
    {char * tlv62; tlv62 = (char *)(3); }
    {char tlv61; tlv61 = (char)(3); }
    {cgc_size_t tlv60; tlv60 = (cgc_size_t)(3); }
    {void * tlv65; tlv65 = (void *)(3); }
    {cgc_size_t tlv64; tlv64 = (cgc_size_t)(3); }
    {char * tlv68; tlv68 = (char *)(3); }
    {char tlv67; tlv67 = (char)(3); }
    {cgc_size_t tlv66; tlv66 = (cgc_size_t)(3); }
}
void fix_ingred_countyParsers_0_15(){
fix_ingred_countyParsers_0_15_0();
fix_ingred_countyParsers_0_15_1();
fix_ingred_countyParsers_0_15_2();
}
void fix_ingred_countyParsers_0_17_1(){
    {int choice; choice = (int)(30); }
    {char selection [ 30 ]; selection [ ( 30 )-1 ] = (char)(30); }
    {void * tlv16; tlv16 = (void *)(30); }
    {cgc_size_t tlv15; tlv15 = (cgc_size_t)(30); }
    {char * tlv19; tlv19 = (char *)(30); }
    {char tlv18; tlv18 = (char)(30); }
    {cgc_size_t tlv17; tlv17 = (cgc_size_t)(30); }
    {void * tlv21; tlv21 = (void *)(30); }
    {cgc_size_t tlv20; tlv20 = (cgc_size_t)(30); }
    {int tlv1; tlv1 = (int)(30); }
    {int tlv2; tlv2 = (int)(30); }
    {int tlv3; tlv3 = (int)(30); }
    {char * tlv25; tlv25 = (char *)(30); }
    {char tlv24; tlv24 = (char)(30); }
    {cgc_size_t tlv23; tlv23 = (cgc_size_t)(30); }
    {char * tlv28; tlv28 = (char *)(30); }
    {char tlv27; tlv27 = (char)(30); }
    {cgc_size_t tlv26; tlv26 = (cgc_size_t)(30); }
    {char * tlv31; tlv31 = (char *)(30); }
    {char tlv30; tlv30 = (char)(30); }
    {cgc_size_t tlv29; tlv29 = (cgc_size_t)(30); }
    {char * tlv34; tlv34 = (char *)(30); }
    {char tlv33; tlv33 = (char)(30); }
    {cgc_size_t tlv32; tlv32 = (cgc_size_t)(30); }
    {cgc_size_t tlv74; tlv74 = (cgc_size_t)(30); }
    {int tlv73; tlv73 = (int)(30); }
    {void * tlv37; tlv37 = (void *)(30); }
    {cgc_size_t tlv36; tlv36 = (cgc_size_t)(30); }
    {char * tlv40; tlv40 = (char *)(30); }
    {char tlv39; tlv39 = (char)(30); }
    {cgc_size_t tlv38; tlv38 = (cgc_size_t)(30); }
    {void * tlv43; tlv43 = (void *)(30); }
    {cgc_size_t tlv42; tlv42 = (cgc_size_t)(30); }
    {char * tlv46; tlv46 = (char *)(30); }
    {char tlv45; tlv45 = (char)(30); }
    {cgc_size_t tlv44; tlv44 = (cgc_size_t)(30); }
    {void * tlv49; tlv49 = (void *)(30); }
    {cgc_size_t tlv48; tlv48 = (cgc_size_t)(30); }
    {char * tlv52; tlv52 = (char *)(30); }
    {char tlv51; tlv51 = (char)(30); }
    {cgc_size_t tlv50; tlv50 = (cgc_size_t)(30); }
    {void * tlv55; tlv55 = (void *)(30); }
    {cgc_size_t tlv54; tlv54 = (cgc_size_t)(30); }
    {char * tlv58; tlv58 = (char *)(30); }
    {char tlv57; tlv57 = (char)(30); }
    {cgc_size_t tlv56; tlv56 = (cgc_size_t)(30); }
    {cgc_size_t tlv81; tlv81 = (cgc_size_t)(30); }
    {int tlv80; tlv80 = (int)(30); }
    {char * tlv62; tlv62 = (char *)(30); }
    {char tlv61; tlv61 = (char)(30); }
    {cgc_size_t tlv60; tlv60 = (cgc_size_t)(30); }
    {void * tlv65; tlv65 = (void *)(30); }
    {cgc_size_t tlv64; tlv64 = (cgc_size_t)(30); }
    {char * tlv68; tlv68 = (char *)(30); }
    {char tlv67; tlv67 = (char)(30); }
    {cgc_size_t tlv66; tlv66 = (cgc_size_t)(30); }
}
void fix_ingred_countyParsers_0_17(){
fix_ingred_countyParsers_0_17_1();
}
void fix_ingred_countyParsers_0_22_2(){
    {int choice; choice = (int)(19); }
    {char selection [ 30 ]; selection [ ( 30 )-1 ] = (char)(19); }
    {void * tlv16; tlv16 = (void *)(19); }
    {cgc_size_t tlv15; tlv15 = (cgc_size_t)(19); }
    {char * tlv19; tlv19 = (char *)(19); }
    {char tlv18; tlv18 = (char)(19); }
    {cgc_size_t tlv17; tlv17 = (cgc_size_t)(19); }
    {void * tlv21; tlv21 = (void *)(19); }
    {cgc_size_t tlv20; tlv20 = (cgc_size_t)(19); }
    {int tlv1; tlv1 = (int)(19); }
    {int tlv2; tlv2 = (int)(19); }
    {int tlv3; tlv3 = (int)(19); }
    {char * tlv25; tlv25 = (char *)(19); }
    {char tlv24; tlv24 = (char)(19); }
    {cgc_size_t tlv23; tlv23 = (cgc_size_t)(19); }
    {char * tlv28; tlv28 = (char *)(19); }
    {char tlv27; tlv27 = (char)(19); }
    {cgc_size_t tlv26; tlv26 = (cgc_size_t)(19); }
    {char * tlv31; tlv31 = (char *)(19); }
    {char tlv30; tlv30 = (char)(19); }
    {cgc_size_t tlv29; tlv29 = (cgc_size_t)(19); }
    {char * tlv34; tlv34 = (char *)(19); }
    {char tlv33; tlv33 = (char)(19); }
    {cgc_size_t tlv32; tlv32 = (cgc_size_t)(19); }
    {cgc_size_t tlv74; tlv74 = (cgc_size_t)(19); }
    {int tlv73; tlv73 = (int)(19); }
    {void * tlv37; tlv37 = (void *)(19); }
    {cgc_size_t tlv36; tlv36 = (cgc_size_t)(19); }
    {char * tlv40; tlv40 = (char *)(19); }
    {char tlv39; tlv39 = (char)(19); }
    {cgc_size_t tlv38; tlv38 = (cgc_size_t)(19); }
    {void * tlv43; tlv43 = (void *)(19); }
    {cgc_size_t tlv42; tlv42 = (cgc_size_t)(19); }
    {char * tlv46; tlv46 = (char *)(19); }
    {char tlv45; tlv45 = (char)(19); }
    {cgc_size_t tlv44; tlv44 = (cgc_size_t)(19); }
    {void * tlv49; tlv49 = (void *)(19); }
    {cgc_size_t tlv48; tlv48 = (cgc_size_t)(19); }
    {char * tlv52; tlv52 = (char *)(19); }
    {char tlv51; tlv51 = (char)(19); }
    {cgc_size_t tlv50; tlv50 = (cgc_size_t)(19); }
    {void * tlv55; tlv55 = (void *)(19); }
    {cgc_size_t tlv54; tlv54 = (cgc_size_t)(19); }
    {char * tlv58; tlv58 = (char *)(19); }
    {char tlv57; tlv57 = (char)(19); }
    {cgc_size_t tlv56; tlv56 = (cgc_size_t)(19); }
    {cgc_size_t tlv81; tlv81 = (cgc_size_t)(19); }
    {int tlv80; tlv80 = (int)(19); }
    {char * tlv62; tlv62 = (char *)(19); }
    {char tlv61; tlv61 = (char)(19); }
    {cgc_size_t tlv60; tlv60 = (cgc_size_t)(19); }
    {void * tlv65; tlv65 = (void *)(19); }
    {cgc_size_t tlv64; tlv64 = (cgc_size_t)(19); }
    {char * tlv68; tlv68 = (char *)(19); }
    {char tlv67; tlv67 = (char)(19); }
    {cgc_size_t tlv66; tlv66 = (cgc_size_t)(19); }
}
void fix_ingred_countyParsers_0_22(){
fix_ingred_countyParsers_0_22_2();
}
void fix_ingred_countyParsers_0_39_0(){
    {int choice; choice = (int)(sizeof ( Border )); }
    {char selection [ 30 ]; selection [ ( 30 )-1 ] = (char)(sizeof ( Border )); }
    {void * tlv16; tlv16 = (void *)(sizeof ( Border )); }
    {cgc_size_t tlv15; tlv15 = (cgc_size_t)(sizeof ( Border )); }
    {char * tlv19; tlv19 = (char *)(sizeof ( Border )); }
    {char tlv18; tlv18 = (char)(sizeof ( Border )); }
    {cgc_size_t tlv17; tlv17 = (cgc_size_t)(sizeof ( Border )); }
    {void * tlv21; tlv21 = (void *)(sizeof ( Border )); }
    {cgc_size_t tlv20; tlv20 = (cgc_size_t)(sizeof ( Border )); }
    {int tlv1; tlv1 = (int)(sizeof ( Border )); }
    {int tlv2; tlv2 = (int)(sizeof ( Border )); }
    {int tlv3; tlv3 = (int)(sizeof ( Border )); }
    {char * tlv25; tlv25 = (char *)(sizeof ( Border )); }
    {char tlv24; tlv24 = (char)(sizeof ( Border )); }
    {cgc_size_t tlv23; tlv23 = (cgc_size_t)(sizeof ( Border )); }
    {char * tlv28; tlv28 = (char *)(sizeof ( Border )); }
    {char tlv27; tlv27 = (char)(sizeof ( Border )); }
    {cgc_size_t tlv26; tlv26 = (cgc_size_t)(sizeof ( Border )); }
    {char * tlv31; tlv31 = (char *)(sizeof ( Border )); }
    {char tlv30; tlv30 = (char)(sizeof ( Border )); }
    {cgc_size_t tlv29; tlv29 = (cgc_size_t)(sizeof ( Border )); }
    {char * tlv34; tlv34 = (char *)(sizeof ( Border )); }
    {char tlv33; tlv33 = (char)(sizeof ( Border )); }
    {cgc_size_t tlv32; tlv32 = (cgc_size_t)(sizeof ( Border )); }
    {cgc_size_t tlv74; tlv74 = (cgc_size_t)(sizeof ( Border )); }
    {int tlv73; tlv73 = (int)(sizeof ( Border )); }
    {void * tlv37; tlv37 = (void *)(sizeof ( Border )); }
    {cgc_size_t tlv36; tlv36 = (cgc_size_t)(sizeof ( Border )); }
    {char * tlv40; tlv40 = (char *)(sizeof ( Border )); }
    {char tlv39; tlv39 = (char)(sizeof ( Border )); }
    {cgc_size_t tlv38; tlv38 = (cgc_size_t)(sizeof ( Border )); }
    {void * tlv43; tlv43 = (void *)(sizeof ( Border )); }
    {cgc_size_t tlv42; tlv42 = (cgc_size_t)(sizeof ( Border )); }
    {char * tlv46; tlv46 = (char *)(sizeof ( Border )); }
    {char tlv45; tlv45 = (char)(sizeof ( Border )); }
    {cgc_size_t tlv44; tlv44 = (cgc_size_t)(sizeof ( Border )); }
    {void * tlv49; tlv49 = (void *)(sizeof ( Border )); }
    {cgc_size_t tlv48; tlv48 = (cgc_size_t)(sizeof ( Border )); }
    {char * tlv52; tlv52 = (char *)(sizeof ( Border )); }
    {char tlv51; tlv51 = (char)(sizeof ( Border )); }
    {cgc_size_t tlv50; tlv50 = (cgc_size_t)(sizeof ( Border )); }
    {void * tlv55; tlv55 = (void *)(sizeof ( Border )); }
    {cgc_size_t tlv54; tlv54 = (cgc_size_t)(sizeof ( Border )); }
    {char * tlv58; tlv58 = (char *)(sizeof ( Border )); }
    {char tlv57; tlv57 = (char)(sizeof ( Border )); }
    {cgc_size_t tlv56; tlv56 = (cgc_size_t)(sizeof ( Border )); }
    {cgc_size_t tlv81; tlv81 = (cgc_size_t)(sizeof ( Border )); }
    {int tlv80; tlv80 = (int)(sizeof ( Border )); }
    {char * tlv62; tlv62 = (char *)(sizeof ( Border )); }
    {char tlv61; tlv61 = (char)(sizeof ( Border )); }
    {cgc_size_t tlv60; tlv60 = (cgc_size_t)(sizeof ( Border )); }
    {void * tlv65; tlv65 = (void *)(sizeof ( Border )); }
    {cgc_size_t tlv64; tlv64 = (cgc_size_t)(sizeof ( Border )); }
    {char * tlv68; tlv68 = (char *)(sizeof ( Border )); }
    {char tlv67; tlv67 = (char)(sizeof ( Border )); }
    {cgc_size_t tlv66; tlv66 = (cgc_size_t)(sizeof ( Border )); }
}
void fix_ingred_countyParsers_0_39(){
fix_ingred_countyParsers_0_39_0();
}
void fix_ingred_countyParsers_0_40_6(){
int tlv1;
    bzero(&tlv1,sizeof(int));
    {int choice; choice = (int)(tlv1); }
    {char selection [ 30 ]; selection [ ( 30 )-1 ] = (char)(tlv1); }
    {void * tlv16; tlv16 = (void *)(tlv1); }
    {cgc_size_t tlv15; tlv15 = (cgc_size_t)(tlv1); }
    {char * tlv19; tlv19 = (char *)(tlv1); }
    {char tlv18; tlv18 = (char)(tlv1); }
    {cgc_size_t tlv17; tlv17 = (cgc_size_t)(tlv1); }
    {void * tlv21; tlv21 = (void *)(tlv1); }
    {cgc_size_t tlv20; tlv20 = (cgc_size_t)(tlv1); }
    {int tlv2; tlv2 = (int)(tlv1); }
    {int tlv3; tlv3 = (int)(tlv1); }
    {char * tlv25; tlv25 = (char *)(tlv1); }
    {char tlv24; tlv24 = (char)(tlv1); }
    {cgc_size_t tlv23; tlv23 = (cgc_size_t)(tlv1); }
    {char * tlv28; tlv28 = (char *)(tlv1); }
    {char tlv27; tlv27 = (char)(tlv1); }
    {cgc_size_t tlv26; tlv26 = (cgc_size_t)(tlv1); }
    {char * tlv31; tlv31 = (char *)(tlv1); }
    {char tlv30; tlv30 = (char)(tlv1); }
    {cgc_size_t tlv29; tlv29 = (cgc_size_t)(tlv1); }
    {char * tlv34; tlv34 = (char *)(tlv1); }
    {char tlv33; tlv33 = (char)(tlv1); }
    {cgc_size_t tlv32; tlv32 = (cgc_size_t)(tlv1); }
    {cgc_size_t tlv74; tlv74 = (cgc_size_t)(tlv1); }
    {int tlv73; tlv73 = (int)(tlv1); }
    {void * tlv37; tlv37 = (void *)(tlv1); }
    {cgc_size_t tlv36; tlv36 = (cgc_size_t)(tlv1); }
    {char * tlv40; tlv40 = (char *)(tlv1); }
    {char tlv39; tlv39 = (char)(tlv1); }
    {cgc_size_t tlv38; tlv38 = (cgc_size_t)(tlv1); }
    {void * tlv43; tlv43 = (void *)(tlv1); }
    {cgc_size_t tlv42; tlv42 = (cgc_size_t)(tlv1); }
    {char * tlv46; tlv46 = (char *)(tlv1); }
    {char tlv45; tlv45 = (char)(tlv1); }
    {cgc_size_t tlv44; tlv44 = (cgc_size_t)(tlv1); }
    {void * tlv49; tlv49 = (void *)(tlv1); }
    {cgc_size_t tlv48; tlv48 = (cgc_size_t)(tlv1); }
    {char * tlv52; tlv52 = (char *)(tlv1); }
    {char tlv51; tlv51 = (char)(tlv1); }
    {cgc_size_t tlv50; tlv50 = (cgc_size_t)(tlv1); }
    {void * tlv55; tlv55 = (void *)(tlv1); }
    {cgc_size_t tlv54; tlv54 = (cgc_size_t)(tlv1); }
    {char * tlv58; tlv58 = (char *)(tlv1); }
    {char tlv57; tlv57 = (char)(tlv1); }
    {cgc_size_t tlv56; tlv56 = (cgc_size_t)(tlv1); }
    {cgc_size_t tlv81; tlv81 = (cgc_size_t)(tlv1); }
    {int tlv80; tlv80 = (int)(tlv1); }
    {char * tlv62; tlv62 = (char *)(tlv1); }
    {char tlv61; tlv61 = (char)(tlv1); }
    {cgc_size_t tlv60; tlv60 = (cgc_size_t)(tlv1); }
    {void * tlv65; tlv65 = (void *)(tlv1); }
    {cgc_size_t tlv64; tlv64 = (cgc_size_t)(tlv1); }
    {char * tlv68; tlv68 = (char *)(tlv1); }
    {char tlv67; tlv67 = (char)(tlv1); }
    {cgc_size_t tlv66; tlv66 = (cgc_size_t)(tlv1); }
}
void fix_ingred_countyParsers_0_40(){
fix_ingred_countyParsers_0_40_6();
}
void fix_ingred_countyParsers_0_58_6(){
int choice;
    bzero(&choice,sizeof(int));
    {char selection [ 30 ]; selection [ ( 30 )-1 ] = (char)(choice); }
    {void * tlv16; tlv16 = (void *)(choice); }
    {cgc_size_t tlv15; tlv15 = (cgc_size_t)(choice); }
    {char * tlv19; tlv19 = (char *)(choice); }
    {char tlv18; tlv18 = (char)(choice); }
    {cgc_size_t tlv17; tlv17 = (cgc_size_t)(choice); }
    {void * tlv21; tlv21 = (void *)(choice); }
    {cgc_size_t tlv20; tlv20 = (cgc_size_t)(choice); }
    {int tlv1; tlv1 = (int)(choice); }
    {int tlv2; tlv2 = (int)(choice); }
    {int tlv3; tlv3 = (int)(choice); }
    {char * tlv25; tlv25 = (char *)(choice); }
    {char tlv24; tlv24 = (char)(choice); }
    {cgc_size_t tlv23; tlv23 = (cgc_size_t)(choice); }
    {char * tlv28; tlv28 = (char *)(choice); }
    {char tlv27; tlv27 = (char)(choice); }
    {cgc_size_t tlv26; tlv26 = (cgc_size_t)(choice); }
    {char * tlv31; tlv31 = (char *)(choice); }
    {char tlv30; tlv30 = (char)(choice); }
    {cgc_size_t tlv29; tlv29 = (cgc_size_t)(choice); }
    {char * tlv34; tlv34 = (char *)(choice); }
    {char tlv33; tlv33 = (char)(choice); }
    {cgc_size_t tlv32; tlv32 = (cgc_size_t)(choice); }
    {cgc_size_t tlv74; tlv74 = (cgc_size_t)(choice); }
    {int tlv73; tlv73 = (int)(choice); }
    {void * tlv37; tlv37 = (void *)(choice); }
    {cgc_size_t tlv36; tlv36 = (cgc_size_t)(choice); }
    {char * tlv40; tlv40 = (char *)(choice); }
    {char tlv39; tlv39 = (char)(choice); }
    {cgc_size_t tlv38; tlv38 = (cgc_size_t)(choice); }
    {void * tlv43; tlv43 = (void *)(choice); }
    {cgc_size_t tlv42; tlv42 = (cgc_size_t)(choice); }
    {char * tlv46; tlv46 = (char *)(choice); }
    {char tlv45; tlv45 = (char)(choice); }
    {cgc_size_t tlv44; tlv44 = (cgc_size_t)(choice); }
    {void * tlv49; tlv49 = (void *)(choice); }
    {cgc_size_t tlv48; tlv48 = (cgc_size_t)(choice); }
    {char * tlv52; tlv52 = (char *)(choice); }
    {char tlv51; tlv51 = (char)(choice); }
    {cgc_size_t tlv50; tlv50 = (cgc_size_t)(choice); }
    {void * tlv55; tlv55 = (void *)(choice); }
    {cgc_size_t tlv54; tlv54 = (cgc_size_t)(choice); }
    {char * tlv58; tlv58 = (char *)(choice); }
    {char tlv57; tlv57 = (char)(choice); }
    {cgc_size_t tlv56; tlv56 = (cgc_size_t)(choice); }
    {cgc_size_t tlv81; tlv81 = (cgc_size_t)(choice); }
    {int tlv80; tlv80 = (int)(choice); }
    {char * tlv62; tlv62 = (char *)(choice); }
    {char tlv61; tlv61 = (char)(choice); }
    {cgc_size_t tlv60; tlv60 = (cgc_size_t)(choice); }
    {void * tlv65; tlv65 = (void *)(choice); }
    {cgc_size_t tlv64; tlv64 = (cgc_size_t)(choice); }
    {char * tlv68; tlv68 = (char *)(choice); }
    {char tlv67; tlv67 = (char)(choice); }
    {cgc_size_t tlv66; tlv66 = (cgc_size_t)(choice); }
}
void fix_ingred_countyParsers_0_58_7(){
int choice;
    bzero(&choice,sizeof(int));
    {int choice; choice = (int)(COUNTYCITYMAX); }
    {char selection [ 30 ]; selection [ ( 30 )-1 ] = (char)(COUNTYCITYMAX); }
    {void * tlv16; tlv16 = (void *)(COUNTYCITYMAX); }
    {cgc_size_t tlv15; tlv15 = (cgc_size_t)(COUNTYCITYMAX); }
    {char * tlv19; tlv19 = (char *)(COUNTYCITYMAX); }
    {char tlv18; tlv18 = (char)(COUNTYCITYMAX); }
    {cgc_size_t tlv17; tlv17 = (cgc_size_t)(COUNTYCITYMAX); }
    {void * tlv21; tlv21 = (void *)(COUNTYCITYMAX); }
    {cgc_size_t tlv20; tlv20 = (cgc_size_t)(COUNTYCITYMAX); }
    {int tlv1; tlv1 = (int)(COUNTYCITYMAX); }
    {int tlv2; tlv2 = (int)(COUNTYCITYMAX); }
    {int tlv3; tlv3 = (int)(COUNTYCITYMAX); }
    {char * tlv25; tlv25 = (char *)(COUNTYCITYMAX); }
    {char tlv24; tlv24 = (char)(COUNTYCITYMAX); }
    {cgc_size_t tlv23; tlv23 = (cgc_size_t)(COUNTYCITYMAX); }
    {char * tlv28; tlv28 = (char *)(COUNTYCITYMAX); }
    {char tlv27; tlv27 = (char)(COUNTYCITYMAX); }
    {cgc_size_t tlv26; tlv26 = (cgc_size_t)(COUNTYCITYMAX); }
    {char * tlv31; tlv31 = (char *)(COUNTYCITYMAX); }
    {char tlv30; tlv30 = (char)(COUNTYCITYMAX); }
    {cgc_size_t tlv29; tlv29 = (cgc_size_t)(COUNTYCITYMAX); }
    {char * tlv34; tlv34 = (char *)(COUNTYCITYMAX); }
    {char tlv33; tlv33 = (char)(COUNTYCITYMAX); }
    {cgc_size_t tlv32; tlv32 = (cgc_size_t)(COUNTYCITYMAX); }
    {cgc_size_t tlv74; tlv74 = (cgc_size_t)(COUNTYCITYMAX); }
    {int tlv73; tlv73 = (int)(COUNTYCITYMAX); }
    {void * tlv37; tlv37 = (void *)(COUNTYCITYMAX); }
    {cgc_size_t tlv36; tlv36 = (cgc_size_t)(COUNTYCITYMAX); }
    {char * tlv40; tlv40 = (char *)(COUNTYCITYMAX); }
    {char tlv39; tlv39 = (char)(COUNTYCITYMAX); }
    {cgc_size_t tlv38; tlv38 = (cgc_size_t)(COUNTYCITYMAX); }
    {void * tlv43; tlv43 = (void *)(COUNTYCITYMAX); }
    {cgc_size_t tlv42; tlv42 = (cgc_size_t)(COUNTYCITYMAX); }
    {char * tlv46; tlv46 = (char *)(COUNTYCITYMAX); }
    {char tlv45; tlv45 = (char)(COUNTYCITYMAX); }
    {cgc_size_t tlv44; tlv44 = (cgc_size_t)(COUNTYCITYMAX); }
    {void * tlv49; tlv49 = (void *)(COUNTYCITYMAX); }
    {cgc_size_t tlv48; tlv48 = (cgc_size_t)(COUNTYCITYMAX); }
    {char * tlv52; tlv52 = (char *)(COUNTYCITYMAX); }
    {char tlv51; tlv51 = (char)(COUNTYCITYMAX); }
    {cgc_size_t tlv50; tlv50 = (cgc_size_t)(COUNTYCITYMAX); }
    {void * tlv55; tlv55 = (void *)(COUNTYCITYMAX); }
    {cgc_size_t tlv54; tlv54 = (cgc_size_t)(COUNTYCITYMAX); }
    {char * tlv58; tlv58 = (char *)(COUNTYCITYMAX); }
    {char tlv57; tlv57 = (char)(COUNTYCITYMAX); }
    {cgc_size_t tlv56; tlv56 = (cgc_size_t)(COUNTYCITYMAX); }
    {cgc_size_t tlv81; tlv81 = (cgc_size_t)(COUNTYCITYMAX); }
    {int tlv80; tlv80 = (int)(COUNTYCITYMAX); }
    {char * tlv62; tlv62 = (char *)(COUNTYCITYMAX); }
    {char tlv61; tlv61 = (char)(COUNTYCITYMAX); }
    {cgc_size_t tlv60; tlv60 = (cgc_size_t)(COUNTYCITYMAX); }
    {void * tlv65; tlv65 = (void *)(COUNTYCITYMAX); }
    {cgc_size_t tlv64; tlv64 = (cgc_size_t)(COUNTYCITYMAX); }
    {char * tlv68; tlv68 = (char *)(COUNTYCITYMAX); }
    {char tlv67; tlv67 = (char)(COUNTYCITYMAX); }
    {cgc_size_t tlv66; tlv66 = (cgc_size_t)(COUNTYCITYMAX); }
}
void fix_ingred_countyParsers_0_58(){
fix_ingred_countyParsers_0_58_6();
fix_ingred_countyParsers_0_58_7();
}
void fix_ingred_countyParsers_0_62_0(){
    {int choice; choice = (int)(sizeof ( City )); }
    {char selection [ 30 ]; selection [ ( 30 )-1 ] = (char)(sizeof ( City )); }
    {void * tlv16; tlv16 = (void *)(sizeof ( City )); }
    {cgc_size_t tlv15; tlv15 = (cgc_size_t)(sizeof ( City )); }
    {char * tlv19; tlv19 = (char *)(sizeof ( City )); }
    {char tlv18; tlv18 = (char)(sizeof ( City )); }
    {cgc_size_t tlv17; tlv17 = (cgc_size_t)(sizeof ( City )); }
    {void * tlv21; tlv21 = (void *)(sizeof ( City )); }
    {cgc_size_t tlv20; tlv20 = (cgc_size_t)(sizeof ( City )); }
    {int tlv1; tlv1 = (int)(sizeof ( City )); }
    {int tlv2; tlv2 = (int)(sizeof ( City )); }
    {int tlv3; tlv3 = (int)(sizeof ( City )); }
    {char * tlv25; tlv25 = (char *)(sizeof ( City )); }
    {char tlv24; tlv24 = (char)(sizeof ( City )); }
    {cgc_size_t tlv23; tlv23 = (cgc_size_t)(sizeof ( City )); }
    {char * tlv28; tlv28 = (char *)(sizeof ( City )); }
    {char tlv27; tlv27 = (char)(sizeof ( City )); }
    {cgc_size_t tlv26; tlv26 = (cgc_size_t)(sizeof ( City )); }
    {char * tlv31; tlv31 = (char *)(sizeof ( City )); }
    {char tlv30; tlv30 = (char)(sizeof ( City )); }
    {cgc_size_t tlv29; tlv29 = (cgc_size_t)(sizeof ( City )); }
    {char * tlv34; tlv34 = (char *)(sizeof ( City )); }
    {char tlv33; tlv33 = (char)(sizeof ( City )); }
    {cgc_size_t tlv32; tlv32 = (cgc_size_t)(sizeof ( City )); }
    {cgc_size_t tlv74; tlv74 = (cgc_size_t)(sizeof ( City )); }
    {int tlv73; tlv73 = (int)(sizeof ( City )); }
    {void * tlv37; tlv37 = (void *)(sizeof ( City )); }
    {cgc_size_t tlv36; tlv36 = (cgc_size_t)(sizeof ( City )); }
    {char * tlv40; tlv40 = (char *)(sizeof ( City )); }
    {char tlv39; tlv39 = (char)(sizeof ( City )); }
    {cgc_size_t tlv38; tlv38 = (cgc_size_t)(sizeof ( City )); }
    {void * tlv43; tlv43 = (void *)(sizeof ( City )); }
    {cgc_size_t tlv42; tlv42 = (cgc_size_t)(sizeof ( City )); }
    {char * tlv46; tlv46 = (char *)(sizeof ( City )); }
    {char tlv45; tlv45 = (char)(sizeof ( City )); }
    {cgc_size_t tlv44; tlv44 = (cgc_size_t)(sizeof ( City )); }
    {void * tlv49; tlv49 = (void *)(sizeof ( City )); }
    {cgc_size_t tlv48; tlv48 = (cgc_size_t)(sizeof ( City )); }
    {char * tlv52; tlv52 = (char *)(sizeof ( City )); }
    {char tlv51; tlv51 = (char)(sizeof ( City )); }
    {cgc_size_t tlv50; tlv50 = (cgc_size_t)(sizeof ( City )); }
    {void * tlv55; tlv55 = (void *)(sizeof ( City )); }
    {cgc_size_t tlv54; tlv54 = (cgc_size_t)(sizeof ( City )); }
    {char * tlv58; tlv58 = (char *)(sizeof ( City )); }
    {char tlv57; tlv57 = (char)(sizeof ( City )); }
    {cgc_size_t tlv56; tlv56 = (cgc_size_t)(sizeof ( City )); }
    {cgc_size_t tlv81; tlv81 = (cgc_size_t)(sizeof ( City )); }
    {int tlv80; tlv80 = (int)(sizeof ( City )); }
    {char * tlv62; tlv62 = (char *)(sizeof ( City )); }
    {char tlv61; tlv61 = (char)(sizeof ( City )); }
    {cgc_size_t tlv60; tlv60 = (cgc_size_t)(sizeof ( City )); }
    {void * tlv65; tlv65 = (void *)(sizeof ( City )); }
    {cgc_size_t tlv64; tlv64 = (cgc_size_t)(sizeof ( City )); }
    {char * tlv68; tlv68 = (char *)(sizeof ( City )); }
    {char tlv67; tlv67 = (char)(sizeof ( City )); }
    {cgc_size_t tlv66; tlv66 = (cgc_size_t)(sizeof ( City )); }
}
void fix_ingred_countyParsers_0_62(){
fix_ingred_countyParsers_0_62_0();
}
void fix_ingred_countyParsers_0_63_7(){
int tlv2;
    bzero(&tlv2,sizeof(int));
    {int choice; choice = (int)(tlv2); }
    {char selection [ 30 ]; selection [ ( 30 )-1 ] = (char)(tlv2); }
    {void * tlv16; tlv16 = (void *)(tlv2); }
    {cgc_size_t tlv15; tlv15 = (cgc_size_t)(tlv2); }
    {char * tlv19; tlv19 = (char *)(tlv2); }
    {char tlv18; tlv18 = (char)(tlv2); }
    {cgc_size_t tlv17; tlv17 = (cgc_size_t)(tlv2); }
    {void * tlv21; tlv21 = (void *)(tlv2); }
    {cgc_size_t tlv20; tlv20 = (cgc_size_t)(tlv2); }
    {int tlv1; tlv1 = (int)(tlv2); }
    {int tlv3; tlv3 = (int)(tlv2); }
    {char * tlv25; tlv25 = (char *)(tlv2); }
    {char tlv24; tlv24 = (char)(tlv2); }
    {cgc_size_t tlv23; tlv23 = (cgc_size_t)(tlv2); }
    {char * tlv28; tlv28 = (char *)(tlv2); }
    {char tlv27; tlv27 = (char)(tlv2); }
    {cgc_size_t tlv26; tlv26 = (cgc_size_t)(tlv2); }
    {char * tlv31; tlv31 = (char *)(tlv2); }
    {char tlv30; tlv30 = (char)(tlv2); }
    {cgc_size_t tlv29; tlv29 = (cgc_size_t)(tlv2); }
    {char * tlv34; tlv34 = (char *)(tlv2); }
    {char tlv33; tlv33 = (char)(tlv2); }
    {cgc_size_t tlv32; tlv32 = (cgc_size_t)(tlv2); }
    {cgc_size_t tlv74; tlv74 = (cgc_size_t)(tlv2); }
    {int tlv73; tlv73 = (int)(tlv2); }
    {void * tlv37; tlv37 = (void *)(tlv2); }
    {cgc_size_t tlv36; tlv36 = (cgc_size_t)(tlv2); }
    {char * tlv40; tlv40 = (char *)(tlv2); }
    {char tlv39; tlv39 = (char)(tlv2); }
    {cgc_size_t tlv38; tlv38 = (cgc_size_t)(tlv2); }
    {void * tlv43; tlv43 = (void *)(tlv2); }
    {cgc_size_t tlv42; tlv42 = (cgc_size_t)(tlv2); }
    {char * tlv46; tlv46 = (char *)(tlv2); }
    {char tlv45; tlv45 = (char)(tlv2); }
    {cgc_size_t tlv44; tlv44 = (cgc_size_t)(tlv2); }
    {void * tlv49; tlv49 = (void *)(tlv2); }
    {cgc_size_t tlv48; tlv48 = (cgc_size_t)(tlv2); }
    {char * tlv52; tlv52 = (char *)(tlv2); }
    {char tlv51; tlv51 = (char)(tlv2); }
    {cgc_size_t tlv50; tlv50 = (cgc_size_t)(tlv2); }
    {void * tlv55; tlv55 = (void *)(tlv2); }
    {cgc_size_t tlv54; tlv54 = (cgc_size_t)(tlv2); }
    {char * tlv58; tlv58 = (char *)(tlv2); }
    {char tlv57; tlv57 = (char)(tlv2); }
    {cgc_size_t tlv56; tlv56 = (cgc_size_t)(tlv2); }
    {cgc_size_t tlv81; tlv81 = (cgc_size_t)(tlv2); }
    {int tlv80; tlv80 = (int)(tlv2); }
    {char * tlv62; tlv62 = (char *)(tlv2); }
    {char tlv61; tlv61 = (char)(tlv2); }
    {cgc_size_t tlv60; tlv60 = (cgc_size_t)(tlv2); }
    {void * tlv65; tlv65 = (void *)(tlv2); }
    {cgc_size_t tlv64; tlv64 = (cgc_size_t)(tlv2); }
    {char * tlv68; tlv68 = (char *)(tlv2); }
    {char tlv67; tlv67 = (char)(tlv2); }
    {cgc_size_t tlv66; tlv66 = (cgc_size_t)(tlv2); }
}
void fix_ingred_countyParsers_0_63(){
fix_ingred_countyParsers_0_63_7();
}
void fix_ingred_countyParsers_0_74_10(){
    {int choice; choice = (int)(1); }
    {char selection [ 30 ]; selection [ ( 30 )-1 ] = (char)(1); }
    {void * tlv16; tlv16 = (void *)(1); }
    {cgc_size_t tlv15; tlv15 = (cgc_size_t)(1); }
    {char * tlv19; tlv19 = (char *)(1); }
    {char tlv18; tlv18 = (char)(1); }
    {cgc_size_t tlv17; tlv17 = (cgc_size_t)(1); }
    {void * tlv21; tlv21 = (void *)(1); }
    {cgc_size_t tlv20; tlv20 = (cgc_size_t)(1); }
    {int tlv1; tlv1 = (int)(1); }
    {int tlv2; tlv2 = (int)(1); }
    {int tlv3; tlv3 = (int)(1); }
    {char * tlv25; tlv25 = (char *)(1); }
    {char tlv24; tlv24 = (char)(1); }
    {cgc_size_t tlv23; tlv23 = (cgc_size_t)(1); }
    {char * tlv28; tlv28 = (char *)(1); }
    {char tlv27; tlv27 = (char)(1); }
    {cgc_size_t tlv26; tlv26 = (cgc_size_t)(1); }
    {char * tlv31; tlv31 = (char *)(1); }
    {char tlv30; tlv30 = (char)(1); }
    {cgc_size_t tlv29; tlv29 = (cgc_size_t)(1); }
    {char * tlv34; tlv34 = (char *)(1); }
    {char tlv33; tlv33 = (char)(1); }
    {cgc_size_t tlv32; tlv32 = (cgc_size_t)(1); }
    {cgc_size_t tlv74; tlv74 = (cgc_size_t)(1); }
    {int tlv73; tlv73 = (int)(1); }
    {void * tlv37; tlv37 = (void *)(1); }
    {cgc_size_t tlv36; tlv36 = (cgc_size_t)(1); }
    {char * tlv40; tlv40 = (char *)(1); }
    {char tlv39; tlv39 = (char)(1); }
    {cgc_size_t tlv38; tlv38 = (cgc_size_t)(1); }
    {void * tlv43; tlv43 = (void *)(1); }
    {cgc_size_t tlv42; tlv42 = (cgc_size_t)(1); }
    {char * tlv46; tlv46 = (char *)(1); }
    {char tlv45; tlv45 = (char)(1); }
    {cgc_size_t tlv44; tlv44 = (cgc_size_t)(1); }
    {void * tlv49; tlv49 = (void *)(1); }
    {cgc_size_t tlv48; tlv48 = (cgc_size_t)(1); }
    {char * tlv52; tlv52 = (char *)(1); }
    {char tlv51; tlv51 = (char)(1); }
    {cgc_size_t tlv50; tlv50 = (cgc_size_t)(1); }
    {void * tlv55; tlv55 = (void *)(1); }
    {cgc_size_t tlv54; tlv54 = (cgc_size_t)(1); }
    {char * tlv58; tlv58 = (char *)(1); }
    {char tlv57; tlv57 = (char)(1); }
    {cgc_size_t tlv56; tlv56 = (cgc_size_t)(1); }
    {cgc_size_t tlv81; tlv81 = (cgc_size_t)(1); }
    {int tlv80; tlv80 = (int)(1); }
    {char * tlv62; tlv62 = (char *)(1); }
    {char tlv61; tlv61 = (char)(1); }
    {cgc_size_t tlv60; tlv60 = (cgc_size_t)(1); }
    {void * tlv65; tlv65 = (void *)(1); }
    {cgc_size_t tlv64; tlv64 = (cgc_size_t)(1); }
    {char * tlv68; tlv68 = (char *)(1); }
    {char tlv67; tlv67 = (char)(1); }
    {cgc_size_t tlv66; tlv66 = (cgc_size_t)(1); }
}
void fix_ingred_countyParsers_0_74(){
fix_ingred_countyParsers_0_74_10();
}
void fix_ingred_countyParsers_0_77_10(){
int tlv3;
    bzero(&tlv3,sizeof(int));
    {int choice; choice = (int)(tlv3); }
    {char selection [ 30 ]; selection [ ( 30 )-1 ] = (char)(tlv3); }
    {void * tlv16; tlv16 = (void *)(tlv3); }
    {cgc_size_t tlv15; tlv15 = (cgc_size_t)(tlv3); }
    {char * tlv19; tlv19 = (char *)(tlv3); }
    {char tlv18; tlv18 = (char)(tlv3); }
    {cgc_size_t tlv17; tlv17 = (cgc_size_t)(tlv3); }
    {void * tlv21; tlv21 = (void *)(tlv3); }
    {cgc_size_t tlv20; tlv20 = (cgc_size_t)(tlv3); }
    {int tlv1; tlv1 = (int)(tlv3); }
    {int tlv2; tlv2 = (int)(tlv3); }
    {char * tlv25; tlv25 = (char *)(tlv3); }
    {char tlv24; tlv24 = (char)(tlv3); }
    {cgc_size_t tlv23; tlv23 = (cgc_size_t)(tlv3); }
    {char * tlv28; tlv28 = (char *)(tlv3); }
    {char tlv27; tlv27 = (char)(tlv3); }
    {cgc_size_t tlv26; tlv26 = (cgc_size_t)(tlv3); }
    {char * tlv31; tlv31 = (char *)(tlv3); }
    {char tlv30; tlv30 = (char)(tlv3); }
    {cgc_size_t tlv29; tlv29 = (cgc_size_t)(tlv3); }
    {char * tlv34; tlv34 = (char *)(tlv3); }
    {char tlv33; tlv33 = (char)(tlv3); }
    {cgc_size_t tlv32; tlv32 = (cgc_size_t)(tlv3); }
    {cgc_size_t tlv74; tlv74 = (cgc_size_t)(tlv3); }
    {int tlv73; tlv73 = (int)(tlv3); }
    {void * tlv37; tlv37 = (void *)(tlv3); }
    {cgc_size_t tlv36; tlv36 = (cgc_size_t)(tlv3); }
    {char * tlv40; tlv40 = (char *)(tlv3); }
    {char tlv39; tlv39 = (char)(tlv3); }
    {cgc_size_t tlv38; tlv38 = (cgc_size_t)(tlv3); }
    {void * tlv43; tlv43 = (void *)(tlv3); }
    {cgc_size_t tlv42; tlv42 = (cgc_size_t)(tlv3); }
    {char * tlv46; tlv46 = (char *)(tlv3); }
    {char tlv45; tlv45 = (char)(tlv3); }
    {cgc_size_t tlv44; tlv44 = (cgc_size_t)(tlv3); }
    {void * tlv49; tlv49 = (void *)(tlv3); }
    {cgc_size_t tlv48; tlv48 = (cgc_size_t)(tlv3); }
    {char * tlv52; tlv52 = (char *)(tlv3); }
    {char tlv51; tlv51 = (char)(tlv3); }
    {cgc_size_t tlv50; tlv50 = (cgc_size_t)(tlv3); }
    {void * tlv55; tlv55 = (void *)(tlv3); }
    {cgc_size_t tlv54; tlv54 = (cgc_size_t)(tlv3); }
    {char * tlv58; tlv58 = (char *)(tlv3); }
    {char tlv57; tlv57 = (char)(tlv3); }
    {cgc_size_t tlv56; tlv56 = (cgc_size_t)(tlv3); }
    {cgc_size_t tlv81; tlv81 = (cgc_size_t)(tlv3); }
    {int tlv80; tlv80 = (int)(tlv3); }
    {char * tlv62; tlv62 = (char *)(tlv3); }
    {char tlv61; tlv61 = (char)(tlv3); }
    {cgc_size_t tlv60; tlv60 = (cgc_size_t)(tlv3); }
    {void * tlv65; tlv65 = (void *)(tlv3); }
    {cgc_size_t tlv64; tlv64 = (cgc_size_t)(tlv3); }
    {char * tlv68; tlv68 = (char *)(tlv3); }
    {char tlv67; tlv67 = (char)(tlv3); }
    {cgc_size_t tlv66; tlv66 = (cgc_size_t)(tlv3); }
}
void fix_ingred_countyParsers_0_77(){
fix_ingred_countyParsers_0_77_10();
}
void fix_ingred_countyParsers_0(){
fix_ingred_countyParsers_0_0();
fix_ingred_countyParsers_0_14();
fix_ingred_countyParsers_0_15();
fix_ingred_countyParsers_0_17();
fix_ingred_countyParsers_0_22();
fix_ingred_countyParsers_0_39();
fix_ingred_countyParsers_0_40();
fix_ingred_countyParsers_0_58();
fix_ingred_countyParsers_0_62();
fix_ingred_countyParsers_0_63();
fix_ingred_countyParsers_0_74();
fix_ingred_countyParsers_0_77();
}
void fix_ingred_countyParsers_1_0_0(){
    {int index; index = (int)(0); }
    {void * tlv2; tlv2 = (void *)(0); }
    {cgc_size_t tlv1; tlv1 = (cgc_size_t)(0); }
    {void * tlv5; tlv5 = (void *)(0); }
    {cgc_size_t tlv4; tlv4 = (cgc_size_t)(0); }
}
void fix_ingred_countyParsers_1_0(){
fix_ingred_countyParsers_1_0_0();
}
void fix_ingred_countyParsers_1_2_2(){
int index;
    bzero(&index,sizeof(int));
County co_ref;
    bzero(&co_ref,1*sizeof(County));
pCounty co = &co_ref;
    {void * tlv2; tlv2 = (void *)(index); }
    {cgc_size_t tlv1; tlv1 = (cgc_size_t)(index); }
    {void * tlv5; tlv5 = (void *)(index); }
    {cgc_size_t tlv4; tlv4 = (cgc_size_t)(index); }
}
void fix_ingred_countyParsers_1_2_3(){
int index;
    bzero(&index,sizeof(int));
County co_ref;
    bzero(&co_ref,1*sizeof(County));
pCounty co = &co_ref;
    {int index; index = (int)(co -> border_count); }
    {void * tlv2; tlv2 = (void *)(co -> border_count); }
    {cgc_size_t tlv1; tlv1 = (cgc_size_t)(co -> border_count); }
    {void * tlv5; tlv5 = (void *)(co -> border_count); }
    {cgc_size_t tlv4; tlv4 = (cgc_size_t)(co -> border_count); }
}
void fix_ingred_countyParsers_1_2(){
fix_ingred_countyParsers_1_2_2();
fix_ingred_countyParsers_1_2_3();
}
void fix_ingred_countyParsers_1_4_1(){
    {int index; index = (int)(sizeof ( Border )); }
    {void * tlv2; tlv2 = (void *)(sizeof ( Border )); }
    {cgc_size_t tlv1; tlv1 = (cgc_size_t)(sizeof ( Border )); }
    {void * tlv5; tlv5 = (void *)(sizeof ( Border )); }
    {cgc_size_t tlv4; tlv4 = (cgc_size_t)(sizeof ( Border )); }
}
void fix_ingred_countyParsers_1_4(){
fix_ingred_countyParsers_1_4_1();
}
void fix_ingred_countyParsers_1_5_4(){
    {int index; index = (int)(COUNTYCITYMAX); }
    {void * tlv2; tlv2 = (void *)(COUNTYCITYMAX); }
    {cgc_size_t tlv1; tlv1 = (cgc_size_t)(COUNTYCITYMAX); }
    {void * tlv5; tlv5 = (void *)(COUNTYCITYMAX); }
    {cgc_size_t tlv4; tlv4 = (cgc_size_t)(COUNTYCITYMAX); }
}
void fix_ingred_countyParsers_1_5(){
fix_ingred_countyParsers_1_5_4();
}
void fix_ingred_countyParsers_1_7_0(){
County co_ref;
    bzero(&co_ref,1*sizeof(County));
pCounty co = &co_ref;
    {int index; index = (int)(co); }
    {void * tlv2; tlv2 = (void *)(co); }
    {cgc_size_t tlv1; tlv1 = (cgc_size_t)(co); }
    {void * tlv5; tlv5 = (void *)(co); }
    {cgc_size_t tlv4; tlv4 = (cgc_size_t)(co); }
}
void fix_ingred_countyParsers_1_7_1(){
County co_ref;
    bzero(&co_ref,1*sizeof(County));
pCounty co = &co_ref;
    {int index; index = (int)(sizeof ( County )); }
    {void * tlv2; tlv2 = (void *)(sizeof ( County )); }
    {cgc_size_t tlv1; tlv1 = (cgc_size_t)(sizeof ( County )); }
    {void * tlv5; tlv5 = (void *)(sizeof ( County )); }
    {cgc_size_t tlv4; tlv4 = (cgc_size_t)(sizeof ( County )); }
}
void fix_ingred_countyParsers_1_7(){
fix_ingred_countyParsers_1_7_0();
fix_ingred_countyParsers_1_7_1();
}
void fix_ingred_countyParsers_1(){
fix_ingred_countyParsers_1_0();
fix_ingred_countyParsers_1_2();
fix_ingred_countyParsers_1_4();
fix_ingred_countyParsers_1_5();
fix_ingred_countyParsers_1_7();
}
void fix_ingred_countyParsers_2_2_7(){
    {int index; index = (int)(20); }
}
void fix_ingred_countyParsers_2_2(){
fix_ingred_countyParsers_2_2_7();
}
void fix_ingred_countyParsers_2(){
fix_ingred_countyParsers_2_2();
}
void fix_ingred_countyParsers_3(){
}
void fix_ingred_countyParsers_4_0_1(){
string str_ref;
    bzero(&str_ref,1*sizeof(string));
pstring str = &str_ref;
    {int startIndex; startIndex = (int)(0); }
    {int endIndex; endIndex = (int)(0); }
    {int lastGood; lastGood = (int)(0); }
    {int tempInt; tempInt = (int)(0); }
    {char * tempChar; tempChar = (char *)(0); }
    {int tlv4; tlv4 = (int)(0); }
    {int tlv5; tlv5 = (int)(0); }
    {int tlv6; tlv6 = (int)(0); }
    {int tlv7; tlv7 = (int)(0); }
    {int tlv8; tlv8 = (int)(0); }
    {char tlv23; tlv23 = (char)(0); }
    {int * tlv9; tlv9 = (int *)(0); }
    {int tlv27; tlv27 = (int)(0); }
    {int tlv26; tlv26 = (int)(0); }
    {void * tlv12; tlv12 = (void *)(0); }
    {cgc_size_t tlv11; tlv11 = (cgc_size_t)(0); }
    {char tlv31; tlv31 = (char)(0); }
    {cgc_size_t tlv35; tlv35 = (cgc_size_t)(0); }
    {int tlv34; tlv34 = (int)(0); }
    {char tlv37; tlv37 = (char)(0); }
    {int tlv13; tlv13 = (int)(0); }
    {int tlv15; tlv15 = (int)(0); }
    {int * tlv17; tlv17 = (int *)(0); }
    {int * tlv19; tlv19 = (int *)(0); }
    {int tlv42; tlv42 = (int)(0); }
    {int tlv41; tlv41 = (int)(0); }
    {void * tlv22; tlv22 = (void *)(0); }
    {cgc_size_t tlv21; tlv21 = (cgc_size_t)(0); }
    {char tlv46; tlv46 = (char)(0); }
    {char * tlv78; tlv78 = (char *)(0); }
    {char * tlv54; tlv54 = (char *)(0); }
    {int * tlv50; tlv50 = (int *)(0); }
    {void * tlv53; tlv53 = (void *)(0); }
    {cgc_size_t tlv52; tlv52 = (cgc_size_t)(0); }
    {char * tlv79; tlv79 = (char *)(0); }
    {char * tlv80; tlv80 = (char *)(0); }
    {void * tlv57; tlv57 = (void *)(0); }
    {char * tlv60; tlv60 = (char *)(0); }
    {char * tlv59; tlv59 = (char *)(0); }
    {cgc_size_t tlv58; tlv58 = (cgc_size_t)(0); }
    {void * tlv62; tlv62 = (void *)(0); }
    {cgc_size_t tlv61; tlv61 = (cgc_size_t)(0); }
    {void * tlv64; tlv64 = (void *)(0); }
    {cgc_size_t tlv63; tlv63 = (cgc_size_t)(0); }
    {char * tlv67; tlv67 = (char *)(0); }
    {char * tlv66; tlv66 = (char *)(0); }
    {cgc_size_t tlv65; tlv65 = (cgc_size_t)(0); }
    {void * tlv69; tlv69 = (void *)(0); }
    {cgc_size_t tlv68; tlv68 = (cgc_size_t)(0); }
    {char * tlv81; tlv81 = (char *)(0); }
    {char * tlv82; tlv82 = (char *)(0); }
}
void fix_ingred_countyParsers_4_0_5(){
string str_ref;
    bzero(&str_ref,1*sizeof(string));
pstring str = &str_ref;
    {int startIndex; startIndex = (int)(NULL); }
    {int endIndex; endIndex = (int)(NULL); }
    {int lastGood; lastGood = (int)(NULL); }
    {int tempInt; tempInt = (int)(NULL); }
    {char * tempChar; tempChar = (char *)(NULL); }
    {int tlv1; tlv1 = (int)(NULL); }
    {int tlv2; tlv2 = (int)(NULL); }
    {int tlv3; tlv3 = (int)(NULL); }
    {int tlv4; tlv4 = (int)(NULL); }
    {int tlv5; tlv5 = (int)(NULL); }
    {int tlv6; tlv6 = (int)(NULL); }
    {int tlv7; tlv7 = (int)(NULL); }
    {int tlv8; tlv8 = (int)(NULL); }
    {char tlv23; tlv23 = (char)(NULL); }
    {int * tlv9; tlv9 = (int *)(NULL); }
    {int tlv27; tlv27 = (int)(NULL); }
    {int tlv26; tlv26 = (int)(NULL); }
    {void * tlv12; tlv12 = (void *)(NULL); }
    {cgc_size_t tlv11; tlv11 = (cgc_size_t)(NULL); }
    {char tlv31; tlv31 = (char)(NULL); }
    {cgc_size_t tlv35; tlv35 = (cgc_size_t)(NULL); }
    {int tlv34; tlv34 = (int)(NULL); }
    {char tlv37; tlv37 = (char)(NULL); }
    {int tlv13; tlv13 = (int)(NULL); }
    {char tlv39; tlv39 = (char)(NULL); }
    {int tlv15; tlv15 = (int)(NULL); }
    {int * tlv17; tlv17 = (int *)(NULL); }
    {int * tlv19; tlv19 = (int *)(NULL); }
    {int tlv42; tlv42 = (int)(NULL); }
    {int tlv41; tlv41 = (int)(NULL); }
    {void * tlv22; tlv22 = (void *)(NULL); }
    {cgc_size_t tlv21; tlv21 = (cgc_size_t)(NULL); }
    {char tlv46; tlv46 = (char)(NULL); }
    {char * tlv78; tlv78 = (char *)(NULL); }
    {char * tlv54; tlv54 = (char *)(NULL); }
    {void * tlv49; tlv49 = (void *)(NULL); }
    {cgc_size_t tlv48; tlv48 = (cgc_size_t)(NULL); }
    {int * tlv50; tlv50 = (int *)(NULL); }
    {void * tlv53; tlv53 = (void *)(NULL); }
    {cgc_size_t tlv52; tlv52 = (cgc_size_t)(NULL); }
    {char * tlv79; tlv79 = (char *)(NULL); }
    {char * tlv80; tlv80 = (char *)(NULL); }
    {void * tlv57; tlv57 = (void *)(NULL); }
    {cgc_size_t tlv56; tlv56 = (cgc_size_t)(NULL); }
    {char * tlv60; tlv60 = (char *)(NULL); }
    {char * tlv59; tlv59 = (char *)(NULL); }
    {cgc_size_t tlv58; tlv58 = (cgc_size_t)(NULL); }
    {void * tlv62; tlv62 = (void *)(NULL); }
    {cgc_size_t tlv61; tlv61 = (cgc_size_t)(NULL); }
    {void * tlv64; tlv64 = (void *)(NULL); }
    {cgc_size_t tlv63; tlv63 = (cgc_size_t)(NULL); }
    {char * tlv67; tlv67 = (char *)(NULL); }
    {char * tlv66; tlv66 = (char *)(NULL); }
    {cgc_size_t tlv65; tlv65 = (cgc_size_t)(NULL); }
    {void * tlv69; tlv69 = (void *)(NULL); }
    {cgc_size_t tlv68; tlv68 = (cgc_size_t)(NULL); }
    {char * tlv81; tlv81 = (char *)(NULL); }
    {char * tlv82; tlv82 = (char *)(NULL); }
}
void fix_ingred_countyParsers_4_0_6(){
string str_ref;
    bzero(&str_ref,1*sizeof(string));
pstring str = &str_ref;
    {int startIndex; startIndex = (int)(str -> index); }
    {int endIndex; endIndex = (int)(str -> index); }
    {int lastGood; lastGood = (int)(str -> index); }
    {int tempInt; tempInt = (int)(str -> index); }
    {char * tempChar; tempChar = (char *)(str -> index); }
    {int tlv1; tlv1 = (int)(str -> index); }
    {int tlv2; tlv2 = (int)(str -> index); }
    {int tlv3; tlv3 = (int)(str -> index); }
    {int tlv4; tlv4 = (int)(str -> index); }
    {int tlv5; tlv5 = (int)(str -> index); }
    {int tlv6; tlv6 = (int)(str -> index); }
    {int tlv7; tlv7 = (int)(str -> index); }
    {int tlv8; tlv8 = (int)(str -> index); }
    {char tlv23; tlv23 = (char)(str -> index); }
    {int * tlv9; tlv9 = (int *)(str -> index); }
    {int tlv27; tlv27 = (int)(str -> index); }
    {int tlv26; tlv26 = (int)(str -> index); }
    {void * tlv12; tlv12 = (void *)(str -> index); }
    {cgc_size_t tlv11; tlv11 = (cgc_size_t)(str -> index); }
    {char tlv31; tlv31 = (char)(str -> index); }
    {cgc_size_t tlv35; tlv35 = (cgc_size_t)(str -> index); }
    {int tlv34; tlv34 = (int)(str -> index); }
    {char tlv37; tlv37 = (char)(str -> index); }
    {int tlv13; tlv13 = (int)(str -> index); }
    {char tlv39; tlv39 = (char)(str -> index); }
    {int tlv15; tlv15 = (int)(str -> index); }
    {int * tlv17; tlv17 = (int *)(str -> index); }
    {int * tlv19; tlv19 = (int *)(str -> index); }
    {int tlv42; tlv42 = (int)(str -> index); }
    {int tlv41; tlv41 = (int)(str -> index); }
    {void * tlv22; tlv22 = (void *)(str -> index); }
    {cgc_size_t tlv21; tlv21 = (cgc_size_t)(str -> index); }
    {char tlv46; tlv46 = (char)(str -> index); }
    {char * tlv78; tlv78 = (char *)(str -> index); }
    {char * tlv54; tlv54 = (char *)(str -> index); }
    {void * tlv49; tlv49 = (void *)(str -> index); }
    {cgc_size_t tlv48; tlv48 = (cgc_size_t)(str -> index); }
    {int * tlv50; tlv50 = (int *)(str -> index); }
    {void * tlv53; tlv53 = (void *)(str -> index); }
    {cgc_size_t tlv52; tlv52 = (cgc_size_t)(str -> index); }
    {char * tlv79; tlv79 = (char *)(str -> index); }
    {char * tlv80; tlv80 = (char *)(str -> index); }
    {void * tlv57; tlv57 = (void *)(str -> index); }
    {cgc_size_t tlv56; tlv56 = (cgc_size_t)(str -> index); }
    {char * tlv60; tlv60 = (char *)(str -> index); }
    {char * tlv59; tlv59 = (char *)(str -> index); }
    {cgc_size_t tlv58; tlv58 = (cgc_size_t)(str -> index); }
    {void * tlv62; tlv62 = (void *)(str -> index); }
    {cgc_size_t tlv61; tlv61 = (cgc_size_t)(str -> index); }
    {void * tlv64; tlv64 = (void *)(str -> index); }
    {cgc_size_t tlv63; tlv63 = (cgc_size_t)(str -> index); }
    {char * tlv67; tlv67 = (char *)(str -> index); }
    {char * tlv66; tlv66 = (char *)(str -> index); }
    {cgc_size_t tlv65; tlv65 = (cgc_size_t)(str -> index); }
    {void * tlv69; tlv69 = (void *)(str -> index); }
    {cgc_size_t tlv68; tlv68 = (cgc_size_t)(str -> index); }
    {char * tlv81; tlv81 = (char *)(str -> index); }
    {char * tlv82; tlv82 = (char *)(str -> index); }
}
void fix_ingred_countyParsers_4_0(){
fix_ingred_countyParsers_4_0_1();
fix_ingred_countyParsers_4_0_5();
fix_ingred_countyParsers_4_0_6();
}
void fix_ingred_countyParsers_4_2_1(){
    {int startIndex; startIndex = (int)('{'); }
    {int endIndex; endIndex = (int)('{'); }
    {int lastGood; lastGood = (int)('{'); }
    {int tempInt; tempInt = (int)('{'); }
    {char * tempChar; tempChar = (char *)('{'); }
    {int tlv1; tlv1 = (int)('{'); }
    {int tlv2; tlv2 = (int)('{'); }
    {int tlv3; tlv3 = (int)('{'); }
    {int tlv4; tlv4 = (int)('{'); }
    {int tlv5; tlv5 = (int)('{'); }
    {int tlv6; tlv6 = (int)('{'); }
    {int tlv7; tlv7 = (int)('{'); }
    {int tlv8; tlv8 = (int)('{'); }
    {char tlv23; tlv23 = (char)('{'); }
    {int * tlv9; tlv9 = (int *)('{'); }
    {int tlv27; tlv27 = (int)('{'); }
    {int tlv26; tlv26 = (int)('{'); }
    {void * tlv12; tlv12 = (void *)('{'); }
    {cgc_size_t tlv11; tlv11 = (cgc_size_t)('{'); }
    {char tlv31; tlv31 = (char)('{'); }
    {cgc_size_t tlv35; tlv35 = (cgc_size_t)('{'); }
    {int tlv34; tlv34 = (int)('{'); }
    {char tlv37; tlv37 = (char)('{'); }
    {int tlv13; tlv13 = (int)('{'); }
    {char tlv39; tlv39 = (char)('{'); }
    {int tlv15; tlv15 = (int)('{'); }
    {int * tlv17; tlv17 = (int *)('{'); }
    {int * tlv19; tlv19 = (int *)('{'); }
    {int tlv42; tlv42 = (int)('{'); }
    {int tlv41; tlv41 = (int)('{'); }
    {void * tlv22; tlv22 = (void *)('{'); }
    {cgc_size_t tlv21; tlv21 = (cgc_size_t)('{'); }
    {char tlv46; tlv46 = (char)('{'); }
    {char * tlv78; tlv78 = (char *)('{'); }
    {char * tlv54; tlv54 = (char *)('{'); }
    {void * tlv49; tlv49 = (void *)('{'); }
    {cgc_size_t tlv48; tlv48 = (cgc_size_t)('{'); }
    {int * tlv50; tlv50 = (int *)('{'); }
    {void * tlv53; tlv53 = (void *)('{'); }
    {cgc_size_t tlv52; tlv52 = (cgc_size_t)('{'); }
    {char * tlv79; tlv79 = (char *)('{'); }
    {char * tlv80; tlv80 = (char *)('{'); }
    {void * tlv57; tlv57 = (void *)('{'); }
    {cgc_size_t tlv56; tlv56 = (cgc_size_t)('{'); }
    {char * tlv60; tlv60 = (char *)('{'); }
    {char * tlv59; tlv59 = (char *)('{'); }
    {cgc_size_t tlv58; tlv58 = (cgc_size_t)('{'); }
    {void * tlv62; tlv62 = (void *)('{'); }
    {cgc_size_t tlv61; tlv61 = (cgc_size_t)('{'); }
    {void * tlv64; tlv64 = (void *)('{'); }
    {cgc_size_t tlv63; tlv63 = (cgc_size_t)('{'); }
    {char * tlv67; tlv67 = (char *)('{'); }
    {char * tlv66; tlv66 = (char *)('{'); }
    {cgc_size_t tlv65; tlv65 = (cgc_size_t)('{'); }
    {void * tlv69; tlv69 = (void *)('{'); }
    {cgc_size_t tlv68; tlv68 = (cgc_size_t)('{'); }
    {char * tlv81; tlv81 = (char *)('{'); }
    {char * tlv82; tlv82 = (char *)('{'); }
}
void fix_ingred_countyParsers_4_2(){
fix_ingred_countyParsers_4_2_1();
}
void fix_ingred_countyParsers_4_4_1(){
int startIndex;
    bzero(&startIndex,sizeof(int));
    {int endIndex; endIndex = (int)(& startIndex); }
    {int lastGood; lastGood = (int)(& startIndex); }
    {int tempInt; tempInt = (int)(& startIndex); }
    {char * tempChar; tempChar = (char *)(& startIndex); }
    {int tlv1; tlv1 = (int)(& startIndex); }
    {int tlv2; tlv2 = (int)(& startIndex); }
    {int tlv3; tlv3 = (int)(& startIndex); }
    {int tlv4; tlv4 = (int)(& startIndex); }
    {int tlv5; tlv5 = (int)(& startIndex); }
    {int tlv6; tlv6 = (int)(& startIndex); }
    {int tlv7; tlv7 = (int)(& startIndex); }
    {int tlv8; tlv8 = (int)(& startIndex); }
    {char tlv23; tlv23 = (char)(& startIndex); }
    {int * tlv9; tlv9 = (int *)(& startIndex); }
    {int tlv27; tlv27 = (int)(& startIndex); }
    {int tlv26; tlv26 = (int)(& startIndex); }
    {void * tlv12; tlv12 = (void *)(& startIndex); }
    {cgc_size_t tlv11; tlv11 = (cgc_size_t)(& startIndex); }
    {char tlv31; tlv31 = (char)(& startIndex); }
    {cgc_size_t tlv35; tlv35 = (cgc_size_t)(& startIndex); }
    {int tlv34; tlv34 = (int)(& startIndex); }
    {char tlv37; tlv37 = (char)(& startIndex); }
    {int tlv13; tlv13 = (int)(& startIndex); }
    {char tlv39; tlv39 = (char)(& startIndex); }
    {int tlv15; tlv15 = (int)(& startIndex); }
    {int * tlv17; tlv17 = (int *)(& startIndex); }
    {int * tlv19; tlv19 = (int *)(& startIndex); }
    {int tlv42; tlv42 = (int)(& startIndex); }
    {int tlv41; tlv41 = (int)(& startIndex); }
    {void * tlv22; tlv22 = (void *)(& startIndex); }
    {cgc_size_t tlv21; tlv21 = (cgc_size_t)(& startIndex); }
    {char tlv46; tlv46 = (char)(& startIndex); }
    {char * tlv78; tlv78 = (char *)(& startIndex); }
    {char * tlv54; tlv54 = (char *)(& startIndex); }
    {void * tlv49; tlv49 = (void *)(& startIndex); }
    {cgc_size_t tlv48; tlv48 = (cgc_size_t)(& startIndex); }
    {int * tlv50; tlv50 = (int *)(& startIndex); }
    {void * tlv53; tlv53 = (void *)(& startIndex); }
    {cgc_size_t tlv52; tlv52 = (cgc_size_t)(& startIndex); }
    {char * tlv79; tlv79 = (char *)(& startIndex); }
    {char * tlv80; tlv80 = (char *)(& startIndex); }
    {void * tlv57; tlv57 = (void *)(& startIndex); }
    {cgc_size_t tlv56; tlv56 = (cgc_size_t)(& startIndex); }
    {char * tlv60; tlv60 = (char *)(& startIndex); }
    {char * tlv59; tlv59 = (char *)(& startIndex); }
    {cgc_size_t tlv58; tlv58 = (cgc_size_t)(& startIndex); }
    {void * tlv62; tlv62 = (void *)(& startIndex); }
    {cgc_size_t tlv61; tlv61 = (cgc_size_t)(& startIndex); }
    {void * tlv64; tlv64 = (void *)(& startIndex); }
    {cgc_size_t tlv63; tlv63 = (cgc_size_t)(& startIndex); }
    {char * tlv67; tlv67 = (char *)(& startIndex); }
    {char * tlv66; tlv66 = (char *)(& startIndex); }
    {cgc_size_t tlv65; tlv65 = (cgc_size_t)(& startIndex); }
    {void * tlv69; tlv69 = (void *)(& startIndex); }
    {cgc_size_t tlv68; tlv68 = (cgc_size_t)(& startIndex); }
    {char * tlv81; tlv81 = (char *)(& startIndex); }
    {char * tlv82; tlv82 = (char *)(& startIndex); }
}
void fix_ingred_countyParsers_4_4(){
fix_ingred_countyParsers_4_4_1();
}
void fix_ingred_countyParsers_4_6_7(){
int endIndex;
    bzero(&endIndex,sizeof(int));
    {int startIndex; startIndex = (int)(endIndex); }
    {int lastGood; lastGood = (int)(endIndex); }
    {int tempInt; tempInt = (int)(endIndex); }
    {char * tempChar; tempChar = (char *)(endIndex); }
    {int tlv1; tlv1 = (int)(endIndex); }
    {int tlv2; tlv2 = (int)(endIndex); }
    {int tlv3; tlv3 = (int)(endIndex); }
    {int tlv4; tlv4 = (int)(endIndex); }
    {int tlv5; tlv5 = (int)(endIndex); }
    {int tlv6; tlv6 = (int)(endIndex); }
    {int tlv7; tlv7 = (int)(endIndex); }
    {int tlv8; tlv8 = (int)(endIndex); }
    {char tlv23; tlv23 = (char)(endIndex); }
    {int * tlv9; tlv9 = (int *)(endIndex); }
    {int tlv27; tlv27 = (int)(endIndex); }
    {int tlv26; tlv26 = (int)(endIndex); }
    {void * tlv12; tlv12 = (void *)(endIndex); }
    {cgc_size_t tlv11; tlv11 = (cgc_size_t)(endIndex); }
    {char tlv31; tlv31 = (char)(endIndex); }
    {cgc_size_t tlv35; tlv35 = (cgc_size_t)(endIndex); }
    {int tlv34; tlv34 = (int)(endIndex); }
    {char tlv37; tlv37 = (char)(endIndex); }
    {int tlv13; tlv13 = (int)(endIndex); }
    {char tlv39; tlv39 = (char)(endIndex); }
    {int tlv15; tlv15 = (int)(endIndex); }
    {int * tlv17; tlv17 = (int *)(endIndex); }
    {int * tlv19; tlv19 = (int *)(endIndex); }
    {int tlv42; tlv42 = (int)(endIndex); }
    {int tlv41; tlv41 = (int)(endIndex); }
    {void * tlv22; tlv22 = (void *)(endIndex); }
    {cgc_size_t tlv21; tlv21 = (cgc_size_t)(endIndex); }
    {char tlv46; tlv46 = (char)(endIndex); }
    {char * tlv78; tlv78 = (char *)(endIndex); }
    {char * tlv54; tlv54 = (char *)(endIndex); }
    {void * tlv49; tlv49 = (void *)(endIndex); }
    {cgc_size_t tlv48; tlv48 = (cgc_size_t)(endIndex); }
    {int * tlv50; tlv50 = (int *)(endIndex); }
    {void * tlv53; tlv53 = (void *)(endIndex); }
    {cgc_size_t tlv52; tlv52 = (cgc_size_t)(endIndex); }
    {char * tlv79; tlv79 = (char *)(endIndex); }
    {char * tlv80; tlv80 = (char *)(endIndex); }
    {void * tlv57; tlv57 = (void *)(endIndex); }
    {cgc_size_t tlv56; tlv56 = (cgc_size_t)(endIndex); }
    {char * tlv60; tlv60 = (char *)(endIndex); }
    {char * tlv59; tlv59 = (char *)(endIndex); }
    {cgc_size_t tlv58; tlv58 = (cgc_size_t)(endIndex); }
    {void * tlv62; tlv62 = (void *)(endIndex); }
    {cgc_size_t tlv61; tlv61 = (cgc_size_t)(endIndex); }
    {void * tlv64; tlv64 = (void *)(endIndex); }
    {cgc_size_t tlv63; tlv63 = (cgc_size_t)(endIndex); }
    {char * tlv67; tlv67 = (char *)(endIndex); }
    {char * tlv66; tlv66 = (char *)(endIndex); }
    {cgc_size_t tlv65; tlv65 = (cgc_size_t)(endIndex); }
    {void * tlv69; tlv69 = (void *)(endIndex); }
    {cgc_size_t tlv68; tlv68 = (cgc_size_t)(endIndex); }
    {char * tlv81; tlv81 = (char *)(endIndex); }
    {char * tlv82; tlv82 = (char *)(endIndex); }
}
void fix_ingred_countyParsers_4_6_8(){
int endIndex;
    bzero(&endIndex,sizeof(int));
    {int startIndex; startIndex = (int)(- 1); }
    {int endIndex; endIndex = (int)(- 1); }
    {int lastGood; lastGood = (int)(- 1); }
    {int tempInt; tempInt = (int)(- 1); }
    {char * tempChar; tempChar = (char *)(- 1); }
    {int tlv1; tlv1 = (int)(- 1); }
    {int tlv2; tlv2 = (int)(- 1); }
    {int tlv3; tlv3 = (int)(- 1); }
    {int tlv4; tlv4 = (int)(- 1); }
    {int tlv5; tlv5 = (int)(- 1); }
    {int tlv6; tlv6 = (int)(- 1); }
    {int tlv7; tlv7 = (int)(- 1); }
    {int tlv8; tlv8 = (int)(- 1); }
    {char tlv23; tlv23 = (char)(- 1); }
    {int * tlv9; tlv9 = (int *)(- 1); }
    {int tlv27; tlv27 = (int)(- 1); }
    {int tlv26; tlv26 = (int)(- 1); }
    {void * tlv12; tlv12 = (void *)(- 1); }
    {cgc_size_t tlv11; tlv11 = (cgc_size_t)(- 1); }
    {char tlv31; tlv31 = (char)(- 1); }
    {cgc_size_t tlv35; tlv35 = (cgc_size_t)(- 1); }
    {int tlv34; tlv34 = (int)(- 1); }
    {char tlv37; tlv37 = (char)(- 1); }
    {int tlv13; tlv13 = (int)(- 1); }
    {char tlv39; tlv39 = (char)(- 1); }
    {int tlv15; tlv15 = (int)(- 1); }
    {int * tlv17; tlv17 = (int *)(- 1); }
    {int * tlv19; tlv19 = (int *)(- 1); }
    {int tlv42; tlv42 = (int)(- 1); }
    {int tlv41; tlv41 = (int)(- 1); }
    {void * tlv22; tlv22 = (void *)(- 1); }
    {cgc_size_t tlv21; tlv21 = (cgc_size_t)(- 1); }
    {char tlv46; tlv46 = (char)(- 1); }
    {char * tlv78; tlv78 = (char *)(- 1); }
    {char * tlv54; tlv54 = (char *)(- 1); }
    {void * tlv49; tlv49 = (void *)(- 1); }
    {cgc_size_t tlv48; tlv48 = (cgc_size_t)(- 1); }
    {int * tlv50; tlv50 = (int *)(- 1); }
    {void * tlv53; tlv53 = (void *)(- 1); }
    {cgc_size_t tlv52; tlv52 = (cgc_size_t)(- 1); }
    {char * tlv79; tlv79 = (char *)(- 1); }
    {char * tlv80; tlv80 = (char *)(- 1); }
    {void * tlv57; tlv57 = (void *)(- 1); }
    {cgc_size_t tlv56; tlv56 = (cgc_size_t)(- 1); }
    {char * tlv60; tlv60 = (char *)(- 1); }
    {char * tlv59; tlv59 = (char *)(- 1); }
    {cgc_size_t tlv58; tlv58 = (cgc_size_t)(- 1); }
    {void * tlv62; tlv62 = (void *)(- 1); }
    {cgc_size_t tlv61; tlv61 = (cgc_size_t)(- 1); }
    {void * tlv64; tlv64 = (void *)(- 1); }
    {cgc_size_t tlv63; tlv63 = (cgc_size_t)(- 1); }
    {char * tlv67; tlv67 = (char *)(- 1); }
    {char * tlv66; tlv66 = (char *)(- 1); }
    {cgc_size_t tlv65; tlv65 = (cgc_size_t)(- 1); }
    {void * tlv69; tlv69 = (void *)(- 1); }
    {cgc_size_t tlv68; tlv68 = (cgc_size_t)(- 1); }
    {char * tlv81; tlv81 = (char *)(- 1); }
    {char * tlv82; tlv82 = (char *)(- 1); }
}
void fix_ingred_countyParsers_4_6(){
fix_ingred_countyParsers_4_6_7();
fix_ingred_countyParsers_4_6_8();
}
void fix_ingred_countyParsers_4_7_7(){
int startIndex;
    bzero(&startIndex,sizeof(int));
    {int endIndex; endIndex = (int)(startIndex); }
    {int lastGood; lastGood = (int)(startIndex); }
    {int tempInt; tempInt = (int)(startIndex); }
    {char * tempChar; tempChar = (char *)(startIndex); }
    {int tlv1; tlv1 = (int)(startIndex); }
    {int tlv2; tlv2 = (int)(startIndex); }
    {int tlv3; tlv3 = (int)(startIndex); }
    {int tlv4; tlv4 = (int)(startIndex); }
    {int tlv5; tlv5 = (int)(startIndex); }
    {int tlv6; tlv6 = (int)(startIndex); }
    {int tlv7; tlv7 = (int)(startIndex); }
    {int tlv8; tlv8 = (int)(startIndex); }
    {char tlv23; tlv23 = (char)(startIndex); }
    {int * tlv9; tlv9 = (int *)(startIndex); }
    {int tlv27; tlv27 = (int)(startIndex); }
    {int tlv26; tlv26 = (int)(startIndex); }
    {void * tlv12; tlv12 = (void *)(startIndex); }
    {cgc_size_t tlv11; tlv11 = (cgc_size_t)(startIndex); }
    {char tlv31; tlv31 = (char)(startIndex); }
    {cgc_size_t tlv35; tlv35 = (cgc_size_t)(startIndex); }
    {int tlv34; tlv34 = (int)(startIndex); }
    {char tlv37; tlv37 = (char)(startIndex); }
    {int tlv13; tlv13 = (int)(startIndex); }
    {char tlv39; tlv39 = (char)(startIndex); }
    {int tlv15; tlv15 = (int)(startIndex); }
    {int * tlv17; tlv17 = (int *)(startIndex); }
    {int * tlv19; tlv19 = (int *)(startIndex); }
    {int tlv42; tlv42 = (int)(startIndex); }
    {int tlv41; tlv41 = (int)(startIndex); }
    {void * tlv22; tlv22 = (void *)(startIndex); }
    {cgc_size_t tlv21; tlv21 = (cgc_size_t)(startIndex); }
    {char tlv46; tlv46 = (char)(startIndex); }
    {char * tlv78; tlv78 = (char *)(startIndex); }
    {char * tlv54; tlv54 = (char *)(startIndex); }
    {void * tlv49; tlv49 = (void *)(startIndex); }
    {cgc_size_t tlv48; tlv48 = (cgc_size_t)(startIndex); }
    {int * tlv50; tlv50 = (int *)(startIndex); }
    {void * tlv53; tlv53 = (void *)(startIndex); }
    {cgc_size_t tlv52; tlv52 = (cgc_size_t)(startIndex); }
    {char * tlv79; tlv79 = (char *)(startIndex); }
    {char * tlv80; tlv80 = (char *)(startIndex); }
    {void * tlv57; tlv57 = (void *)(startIndex); }
    {cgc_size_t tlv56; tlv56 = (cgc_size_t)(startIndex); }
    {char * tlv60; tlv60 = (char *)(startIndex); }
    {char * tlv59; tlv59 = (char *)(startIndex); }
    {cgc_size_t tlv58; tlv58 = (cgc_size_t)(startIndex); }
    {void * tlv62; tlv62 = (void *)(startIndex); }
    {cgc_size_t tlv61; tlv61 = (cgc_size_t)(startIndex); }
    {void * tlv64; tlv64 = (void *)(startIndex); }
    {cgc_size_t tlv63; tlv63 = (cgc_size_t)(startIndex); }
    {char * tlv67; tlv67 = (char *)(startIndex); }
    {char * tlv66; tlv66 = (char *)(startIndex); }
    {cgc_size_t tlv65; tlv65 = (cgc_size_t)(startIndex); }
    {void * tlv69; tlv69 = (void *)(startIndex); }
    {cgc_size_t tlv68; tlv68 = (cgc_size_t)(startIndex); }
    {char * tlv81; tlv81 = (char *)(startIndex); }
    {char * tlv82; tlv82 = (char *)(startIndex); }
}
void fix_ingred_countyParsers_4_7(){
fix_ingred_countyParsers_4_7_7();
}
void fix_ingred_countyParsers_4_9_7(){
char tempChar_ref;
    bzero(&tempChar_ref,1*sizeof(char));
char * tempChar = &tempChar_ref;
    {int startIndex; startIndex = (int)(tempChar); }
    {int endIndex; endIndex = (int)(tempChar); }
    {int lastGood; lastGood = (int)(tempChar); }
    {int tempInt; tempInt = (int)(tempChar); }
    {int tlv1; tlv1 = (int)(tempChar); }
    {int tlv2; tlv2 = (int)(tempChar); }
    {int tlv3; tlv3 = (int)(tempChar); }
    {int tlv4; tlv4 = (int)(tempChar); }
    {int tlv5; tlv5 = (int)(tempChar); }
    {int tlv6; tlv6 = (int)(tempChar); }
    {int tlv7; tlv7 = (int)(tempChar); }
    {int tlv8; tlv8 = (int)(tempChar); }
    {char tlv23; tlv23 = (char)(tempChar); }
    {int * tlv9; tlv9 = (int *)(tempChar); }
    {int tlv27; tlv27 = (int)(tempChar); }
    {int tlv26; tlv26 = (int)(tempChar); }
    {void * tlv12; tlv12 = (void *)(tempChar); }
    {cgc_size_t tlv11; tlv11 = (cgc_size_t)(tempChar); }
    {char tlv31; tlv31 = (char)(tempChar); }
    {cgc_size_t tlv35; tlv35 = (cgc_size_t)(tempChar); }
    {int tlv34; tlv34 = (int)(tempChar); }
    {char tlv37; tlv37 = (char)(tempChar); }
    {int tlv13; tlv13 = (int)(tempChar); }
    {char tlv39; tlv39 = (char)(tempChar); }
    {int tlv15; tlv15 = (int)(tempChar); }
    {int * tlv17; tlv17 = (int *)(tempChar); }
    {int * tlv19; tlv19 = (int *)(tempChar); }
    {int tlv42; tlv42 = (int)(tempChar); }
    {int tlv41; tlv41 = (int)(tempChar); }
    {void * tlv22; tlv22 = (void *)(tempChar); }
    {cgc_size_t tlv21; tlv21 = (cgc_size_t)(tempChar); }
    {char tlv46; tlv46 = (char)(tempChar); }
    {char * tlv78; tlv78 = (char *)(tempChar); }
    {char * tlv54; tlv54 = (char *)(tempChar); }
    {void * tlv49; tlv49 = (void *)(tempChar); }
    {cgc_size_t tlv48; tlv48 = (cgc_size_t)(tempChar); }
    {int * tlv50; tlv50 = (int *)(tempChar); }
    {void * tlv53; tlv53 = (void *)(tempChar); }
    {cgc_size_t tlv52; tlv52 = (cgc_size_t)(tempChar); }
    {char * tlv79; tlv79 = (char *)(tempChar); }
    {char * tlv80; tlv80 = (char *)(tempChar); }
    {void * tlv57; tlv57 = (void *)(tempChar); }
    {cgc_size_t tlv56; tlv56 = (cgc_size_t)(tempChar); }
    {char * tlv60; tlv60 = (char *)(tempChar); }
    {char * tlv59; tlv59 = (char *)(tempChar); }
    {cgc_size_t tlv58; tlv58 = (cgc_size_t)(tempChar); }
    {void * tlv62; tlv62 = (void *)(tempChar); }
    {cgc_size_t tlv61; tlv61 = (cgc_size_t)(tempChar); }
    {void * tlv64; tlv64 = (void *)(tempChar); }
    {cgc_size_t tlv63; tlv63 = (cgc_size_t)(tempChar); }
    {char * tlv67; tlv67 = (char *)(tempChar); }
    {char * tlv66; tlv66 = (char *)(tempChar); }
    {cgc_size_t tlv65; tlv65 = (cgc_size_t)(tempChar); }
    {void * tlv69; tlv69 = (void *)(tempChar); }
    {cgc_size_t tlv68; tlv68 = (cgc_size_t)(tempChar); }
    {char * tlv81; tlv81 = (char *)(tempChar); }
    {char * tlv82; tlv82 = (char *)(tempChar); }
}
void fix_ingred_countyParsers_4_9(){
fix_ingred_countyParsers_4_9_7();
}
void fix_ingred_countyParsers_4_11_7(){
int tlv2;
    bzero(&tlv2,sizeof(int));
    {int startIndex; startIndex = (int)(tlv2); }
    {int endIndex; endIndex = (int)(tlv2); }
    {int lastGood; lastGood = (int)(tlv2); }
    {int tempInt; tempInt = (int)(tlv2); }
    {char * tempChar; tempChar = (char *)(tlv2); }
    {int tlv4; tlv4 = (int)(tlv2); }
    {int tlv5; tlv5 = (int)(tlv2); }
    {int tlv6; tlv6 = (int)(tlv2); }
    {int tlv7; tlv7 = (int)(tlv2); }
    {int tlv8; tlv8 = (int)(tlv2); }
    {char tlv23; tlv23 = (char)(tlv2); }
    {int * tlv9; tlv9 = (int *)(tlv2); }
    {int tlv27; tlv27 = (int)(tlv2); }
    {int tlv26; tlv26 = (int)(tlv2); }
    {void * tlv12; tlv12 = (void *)(tlv2); }
    {cgc_size_t tlv11; tlv11 = (cgc_size_t)(tlv2); }
    {char tlv31; tlv31 = (char)(tlv2); }
    {cgc_size_t tlv35; tlv35 = (cgc_size_t)(tlv2); }
    {int tlv34; tlv34 = (int)(tlv2); }
    {char tlv37; tlv37 = (char)(tlv2); }
    {int tlv13; tlv13 = (int)(tlv2); }
    {int tlv15; tlv15 = (int)(tlv2); }
    {int * tlv17; tlv17 = (int *)(tlv2); }
    {int * tlv19; tlv19 = (int *)(tlv2); }
    {int tlv42; tlv42 = (int)(tlv2); }
    {int tlv41; tlv41 = (int)(tlv2); }
    {void * tlv22; tlv22 = (void *)(tlv2); }
    {cgc_size_t tlv21; tlv21 = (cgc_size_t)(tlv2); }
    {char tlv46; tlv46 = (char)(tlv2); }
    {char * tlv78; tlv78 = (char *)(tlv2); }
    {char * tlv54; tlv54 = (char *)(tlv2); }
    {int * tlv50; tlv50 = (int *)(tlv2); }
    {void * tlv53; tlv53 = (void *)(tlv2); }
    {cgc_size_t tlv52; tlv52 = (cgc_size_t)(tlv2); }
    {char * tlv79; tlv79 = (char *)(tlv2); }
    {char * tlv80; tlv80 = (char *)(tlv2); }
    {void * tlv57; tlv57 = (void *)(tlv2); }
    {char * tlv60; tlv60 = (char *)(tlv2); }
    {char * tlv59; tlv59 = (char *)(tlv2); }
    {cgc_size_t tlv58; tlv58 = (cgc_size_t)(tlv2); }
    {void * tlv62; tlv62 = (void *)(tlv2); }
    {cgc_size_t tlv61; tlv61 = (cgc_size_t)(tlv2); }
    {void * tlv64; tlv64 = (void *)(tlv2); }
    {cgc_size_t tlv63; tlv63 = (cgc_size_t)(tlv2); }
    {char * tlv67; tlv67 = (char *)(tlv2); }
    {char * tlv66; tlv66 = (char *)(tlv2); }
    {cgc_size_t tlv65; tlv65 = (cgc_size_t)(tlv2); }
    {void * tlv69; tlv69 = (void *)(tlv2); }
    {cgc_size_t tlv68; tlv68 = (cgc_size_t)(tlv2); }
    {char * tlv81; tlv81 = (char *)(tlv2); }
    {char * tlv82; tlv82 = (char *)(tlv2); }
}
void fix_ingred_countyParsers_4_11(){
fix_ingred_countyParsers_4_11_7();
}
void fix_ingred_countyParsers_4_12_0(){
char tempChar_ref;
    bzero(&tempChar_ref,1*sizeof(char));
char * tempChar = &tempChar_ref;
int endIndex;
    bzero(&endIndex,sizeof(int));
int startIndex;
    bzero(&startIndex,sizeof(int));
    {int startIndex; startIndex = (int)(tempChar); }
    {int endIndex; endIndex = (int)(tempChar); }
    {int lastGood; lastGood = (int)(tempChar); }
    {int tempInt; tempInt = (int)(tempChar); }
    {int tlv1; tlv1 = (int)(tempChar); }
    {int tlv2; tlv2 = (int)(tempChar); }
    {int tlv3; tlv3 = (int)(tempChar); }
    {int tlv4; tlv4 = (int)(tempChar); }
    {int tlv5; tlv5 = (int)(tempChar); }
    {int tlv6; tlv6 = (int)(tempChar); }
    {int tlv7; tlv7 = (int)(tempChar); }
    {int tlv8; tlv8 = (int)(tempChar); }
    {char tlv23; tlv23 = (char)(tempChar); }
    {int * tlv9; tlv9 = (int *)(tempChar); }
    {int tlv27; tlv27 = (int)(tempChar); }
    {int tlv26; tlv26 = (int)(tempChar); }
    {void * tlv12; tlv12 = (void *)(tempChar); }
    {cgc_size_t tlv11; tlv11 = (cgc_size_t)(tempChar); }
    {char tlv31; tlv31 = (char)(tempChar); }
    {cgc_size_t tlv35; tlv35 = (cgc_size_t)(tempChar); }
    {int tlv34; tlv34 = (int)(tempChar); }
    {char tlv37; tlv37 = (char)(tempChar); }
    {int tlv13; tlv13 = (int)(tempChar); }
    {char tlv39; tlv39 = (char)(tempChar); }
    {int tlv15; tlv15 = (int)(tempChar); }
    {int * tlv17; tlv17 = (int *)(tempChar); }
    {int * tlv19; tlv19 = (int *)(tempChar); }
    {int tlv42; tlv42 = (int)(tempChar); }
    {int tlv41; tlv41 = (int)(tempChar); }
    {void * tlv22; tlv22 = (void *)(tempChar); }
    {cgc_size_t tlv21; tlv21 = (cgc_size_t)(tempChar); }
    {char tlv46; tlv46 = (char)(tempChar); }
    {char * tlv78; tlv78 = (char *)(tempChar); }
    {char * tlv54; tlv54 = (char *)(tempChar); }
    {void * tlv49; tlv49 = (void *)(tempChar); }
    {cgc_size_t tlv48; tlv48 = (cgc_size_t)(tempChar); }
    {int * tlv50; tlv50 = (int *)(tempChar); }
    {void * tlv53; tlv53 = (void *)(tempChar); }
    {cgc_size_t tlv52; tlv52 = (cgc_size_t)(tempChar); }
    {char * tlv79; tlv79 = (char *)(tempChar); }
    {char * tlv80; tlv80 = (char *)(tempChar); }
    {void * tlv57; tlv57 = (void *)(tempChar); }
    {cgc_size_t tlv56; tlv56 = (cgc_size_t)(tempChar); }
    {char * tlv60; tlv60 = (char *)(tempChar); }
    {char * tlv59; tlv59 = (char *)(tempChar); }
    {cgc_size_t tlv58; tlv58 = (cgc_size_t)(tempChar); }
    {void * tlv62; tlv62 = (void *)(tempChar); }
    {cgc_size_t tlv61; tlv61 = (cgc_size_t)(tempChar); }
    {void * tlv64; tlv64 = (void *)(tempChar); }
    {cgc_size_t tlv63; tlv63 = (cgc_size_t)(tempChar); }
    {char * tlv67; tlv67 = (char *)(tempChar); }
    {char * tlv66; tlv66 = (char *)(tempChar); }
    {cgc_size_t tlv65; tlv65 = (cgc_size_t)(tempChar); }
    {void * tlv69; tlv69 = (void *)(tempChar); }
    {cgc_size_t tlv68; tlv68 = (cgc_size_t)(tempChar); }
    {char * tlv81; tlv81 = (char *)(tempChar); }
    {char * tlv82; tlv82 = (char *)(tempChar); }
}
void fix_ingred_countyParsers_4_12_1(){
char tempChar_ref;
    bzero(&tempChar_ref,1*sizeof(char));
char * tempChar = &tempChar_ref;
int endIndex;
    bzero(&endIndex,sizeof(int));
int startIndex;
    bzero(&startIndex,sizeof(int));
    {int lastGood; lastGood = (int)(( endIndex - startIndex ) + 1); }
    {int tempInt; tempInt = (int)(( endIndex - startIndex ) + 1); }
    {char * tempChar; tempChar = (char *)(( endIndex - startIndex ) + 1); }
    {int tlv1; tlv1 = (int)(( endIndex - startIndex ) + 1); }
    {int tlv2; tlv2 = (int)(( endIndex - startIndex ) + 1); }
    {int tlv3; tlv3 = (int)(( endIndex - startIndex ) + 1); }
    {int tlv4; tlv4 = (int)(( endIndex - startIndex ) + 1); }
    {int tlv5; tlv5 = (int)(( endIndex - startIndex ) + 1); }
    {int tlv6; tlv6 = (int)(( endIndex - startIndex ) + 1); }
    {int tlv7; tlv7 = (int)(( endIndex - startIndex ) + 1); }
    {int tlv8; tlv8 = (int)(( endIndex - startIndex ) + 1); }
    {char tlv23; tlv23 = (char)(( endIndex - startIndex ) + 1); }
    {int * tlv9; tlv9 = (int *)(( endIndex - startIndex ) + 1); }
    {int tlv27; tlv27 = (int)(( endIndex - startIndex ) + 1); }
    {int tlv26; tlv26 = (int)(( endIndex - startIndex ) + 1); }
    {void * tlv12; tlv12 = (void *)(( endIndex - startIndex ) + 1); }
    {cgc_size_t tlv11; tlv11 = (cgc_size_t)(( endIndex - startIndex ) + 1); }
    {char tlv31; tlv31 = (char)(( endIndex - startIndex ) + 1); }
    {cgc_size_t tlv35; tlv35 = (cgc_size_t)(( endIndex - startIndex ) + 1); }
    {int tlv34; tlv34 = (int)(( endIndex - startIndex ) + 1); }
    {char tlv37; tlv37 = (char)(( endIndex - startIndex ) + 1); }
    {int tlv13; tlv13 = (int)(( endIndex - startIndex ) + 1); }
    {char tlv39; tlv39 = (char)(( endIndex - startIndex ) + 1); }
    {int tlv15; tlv15 = (int)(( endIndex - startIndex ) + 1); }
    {int * tlv17; tlv17 = (int *)(( endIndex - startIndex ) + 1); }
    {int * tlv19; tlv19 = (int *)(( endIndex - startIndex ) + 1); }
    {int tlv42; tlv42 = (int)(( endIndex - startIndex ) + 1); }
    {int tlv41; tlv41 = (int)(( endIndex - startIndex ) + 1); }
    {void * tlv22; tlv22 = (void *)(( endIndex - startIndex ) + 1); }
    {cgc_size_t tlv21; tlv21 = (cgc_size_t)(( endIndex - startIndex ) + 1); }
    {char tlv46; tlv46 = (char)(( endIndex - startIndex ) + 1); }
    {char * tlv78; tlv78 = (char *)(( endIndex - startIndex ) + 1); }
    {char * tlv54; tlv54 = (char *)(( endIndex - startIndex ) + 1); }
    {void * tlv49; tlv49 = (void *)(( endIndex - startIndex ) + 1); }
    {cgc_size_t tlv48; tlv48 = (cgc_size_t)(( endIndex - startIndex ) + 1); }
    {int * tlv50; tlv50 = (int *)(( endIndex - startIndex ) + 1); }
    {void * tlv53; tlv53 = (void *)(( endIndex - startIndex ) + 1); }
    {cgc_size_t tlv52; tlv52 = (cgc_size_t)(( endIndex - startIndex ) + 1); }
    {char * tlv79; tlv79 = (char *)(( endIndex - startIndex ) + 1); }
    {char * tlv80; tlv80 = (char *)(( endIndex - startIndex ) + 1); }
    {void * tlv57; tlv57 = (void *)(( endIndex - startIndex ) + 1); }
    {cgc_size_t tlv56; tlv56 = (cgc_size_t)(( endIndex - startIndex ) + 1); }
    {char * tlv60; tlv60 = (char *)(( endIndex - startIndex ) + 1); }
    {char * tlv59; tlv59 = (char *)(( endIndex - startIndex ) + 1); }
    {cgc_size_t tlv58; tlv58 = (cgc_size_t)(( endIndex - startIndex ) + 1); }
    {void * tlv62; tlv62 = (void *)(( endIndex - startIndex ) + 1); }
    {cgc_size_t tlv61; tlv61 = (cgc_size_t)(( endIndex - startIndex ) + 1); }
    {void * tlv64; tlv64 = (void *)(( endIndex - startIndex ) + 1); }
    {cgc_size_t tlv63; tlv63 = (cgc_size_t)(( endIndex - startIndex ) + 1); }
    {char * tlv67; tlv67 = (char *)(( endIndex - startIndex ) + 1); }
    {char * tlv66; tlv66 = (char *)(( endIndex - startIndex ) + 1); }
    {cgc_size_t tlv65; tlv65 = (cgc_size_t)(( endIndex - startIndex ) + 1); }
    {void * tlv69; tlv69 = (void *)(( endIndex - startIndex ) + 1); }
    {cgc_size_t tlv68; tlv68 = (cgc_size_t)(( endIndex - startIndex ) + 1); }
    {char * tlv81; tlv81 = (char *)(( endIndex - startIndex ) + 1); }
    {char * tlv82; tlv82 = (char *)(( endIndex - startIndex ) + 1); }
}
void fix_ingred_countyParsers_4_12(){
fix_ingred_countyParsers_4_12_0();
fix_ingred_countyParsers_4_12_1();
}
void fix_ingred_countyParsers_4_13_1(){
    {int startIndex; startIndex = (int)('}'); }
    {int endIndex; endIndex = (int)('}'); }
    {int lastGood; lastGood = (int)('}'); }
    {int tempInt; tempInt = (int)('}'); }
    {char * tempChar; tempChar = (char *)('}'); }
    {int tlv1; tlv1 = (int)('}'); }
    {int tlv2; tlv2 = (int)('}'); }
    {int tlv3; tlv3 = (int)('}'); }
    {int tlv4; tlv4 = (int)('}'); }
    {int tlv5; tlv5 = (int)('}'); }
    {int tlv6; tlv6 = (int)('}'); }
    {int tlv7; tlv7 = (int)('}'); }
    {int tlv8; tlv8 = (int)('}'); }
    {char tlv23; tlv23 = (char)('}'); }
    {int * tlv9; tlv9 = (int *)('}'); }
    {int tlv27; tlv27 = (int)('}'); }
    {int tlv26; tlv26 = (int)('}'); }
    {void * tlv12; tlv12 = (void *)('}'); }
    {cgc_size_t tlv11; tlv11 = (cgc_size_t)('}'); }
    {char tlv31; tlv31 = (char)('}'); }
    {cgc_size_t tlv35; tlv35 = (cgc_size_t)('}'); }
    {int tlv34; tlv34 = (int)('}'); }
    {char tlv37; tlv37 = (char)('}'); }
    {int tlv13; tlv13 = (int)('}'); }
    {char tlv39; tlv39 = (char)('}'); }
    {int tlv15; tlv15 = (int)('}'); }
    {int * tlv17; tlv17 = (int *)('}'); }
    {int * tlv19; tlv19 = (int *)('}'); }
    {int tlv42; tlv42 = (int)('}'); }
    {int tlv41; tlv41 = (int)('}'); }
    {void * tlv22; tlv22 = (void *)('}'); }
    {cgc_size_t tlv21; tlv21 = (cgc_size_t)('}'); }
    {char tlv46; tlv46 = (char)('}'); }
    {char * tlv78; tlv78 = (char *)('}'); }
    {char * tlv54; tlv54 = (char *)('}'); }
    {void * tlv49; tlv49 = (void *)('}'); }
    {cgc_size_t tlv48; tlv48 = (cgc_size_t)('}'); }
    {int * tlv50; tlv50 = (int *)('}'); }
    {void * tlv53; tlv53 = (void *)('}'); }
    {cgc_size_t tlv52; tlv52 = (cgc_size_t)('}'); }
    {char * tlv79; tlv79 = (char *)('}'); }
    {char * tlv80; tlv80 = (char *)('}'); }
    {void * tlv57; tlv57 = (void *)('}'); }
    {cgc_size_t tlv56; tlv56 = (cgc_size_t)('}'); }
    {char * tlv60; tlv60 = (char *)('}'); }
    {char * tlv59; tlv59 = (char *)('}'); }
    {cgc_size_t tlv58; tlv58 = (cgc_size_t)('}'); }
    {void * tlv62; tlv62 = (void *)('}'); }
    {cgc_size_t tlv61; tlv61 = (cgc_size_t)('}'); }
    {void * tlv64; tlv64 = (void *)('}'); }
    {cgc_size_t tlv63; tlv63 = (cgc_size_t)('}'); }
    {char * tlv67; tlv67 = (char *)('}'); }
    {char * tlv66; tlv66 = (char *)('}'); }
    {cgc_size_t tlv65; tlv65 = (cgc_size_t)('}'); }
    {void * tlv69; tlv69 = (void *)('}'); }
    {cgc_size_t tlv68; tlv68 = (cgc_size_t)('}'); }
    {char * tlv81; tlv81 = (char *)('}'); }
    {char * tlv82; tlv82 = (char *)('}'); }
}
void fix_ingred_countyParsers_4_13(){
fix_ingred_countyParsers_4_13_1();
}
void fix_ingred_countyParsers_4_15_0(){
    {int startIndex; startIndex = (int)(sizeof ( County )); }
    {int endIndex; endIndex = (int)(sizeof ( County )); }
    {int lastGood; lastGood = (int)(sizeof ( County )); }
    {int tempInt; tempInt = (int)(sizeof ( County )); }
    {char * tempChar; tempChar = (char *)(sizeof ( County )); }
    {int tlv1; tlv1 = (int)(sizeof ( County )); }
    {int tlv2; tlv2 = (int)(sizeof ( County )); }
    {int tlv3; tlv3 = (int)(sizeof ( County )); }
    {int tlv4; tlv4 = (int)(sizeof ( County )); }
    {int tlv5; tlv5 = (int)(sizeof ( County )); }
    {int tlv6; tlv6 = (int)(sizeof ( County )); }
    {int tlv7; tlv7 = (int)(sizeof ( County )); }
    {int tlv8; tlv8 = (int)(sizeof ( County )); }
    {char tlv23; tlv23 = (char)(sizeof ( County )); }
    {int * tlv9; tlv9 = (int *)(sizeof ( County )); }
    {int tlv27; tlv27 = (int)(sizeof ( County )); }
    {int tlv26; tlv26 = (int)(sizeof ( County )); }
    {void * tlv12; tlv12 = (void *)(sizeof ( County )); }
    {cgc_size_t tlv11; tlv11 = (cgc_size_t)(sizeof ( County )); }
    {char tlv31; tlv31 = (char)(sizeof ( County )); }
    {cgc_size_t tlv35; tlv35 = (cgc_size_t)(sizeof ( County )); }
    {int tlv34; tlv34 = (int)(sizeof ( County )); }
    {char tlv37; tlv37 = (char)(sizeof ( County )); }
    {int tlv13; tlv13 = (int)(sizeof ( County )); }
    {char tlv39; tlv39 = (char)(sizeof ( County )); }
    {int tlv15; tlv15 = (int)(sizeof ( County )); }
    {int * tlv17; tlv17 = (int *)(sizeof ( County )); }
    {int * tlv19; tlv19 = (int *)(sizeof ( County )); }
    {int tlv42; tlv42 = (int)(sizeof ( County )); }
    {int tlv41; tlv41 = (int)(sizeof ( County )); }
    {void * tlv22; tlv22 = (void *)(sizeof ( County )); }
    {cgc_size_t tlv21; tlv21 = (cgc_size_t)(sizeof ( County )); }
    {char tlv46; tlv46 = (char)(sizeof ( County )); }
    {char * tlv78; tlv78 = (char *)(sizeof ( County )); }
    {char * tlv54; tlv54 = (char *)(sizeof ( County )); }
    {void * tlv49; tlv49 = (void *)(sizeof ( County )); }
    {cgc_size_t tlv48; tlv48 = (cgc_size_t)(sizeof ( County )); }
    {int * tlv50; tlv50 = (int *)(sizeof ( County )); }
    {void * tlv53; tlv53 = (void *)(sizeof ( County )); }
    {cgc_size_t tlv52; tlv52 = (cgc_size_t)(sizeof ( County )); }
    {char * tlv79; tlv79 = (char *)(sizeof ( County )); }
    {char * tlv80; tlv80 = (char *)(sizeof ( County )); }
    {void * tlv57; tlv57 = (void *)(sizeof ( County )); }
    {cgc_size_t tlv56; tlv56 = (cgc_size_t)(sizeof ( County )); }
    {char * tlv60; tlv60 = (char *)(sizeof ( County )); }
    {char * tlv59; tlv59 = (char *)(sizeof ( County )); }
    {cgc_size_t tlv58; tlv58 = (cgc_size_t)(sizeof ( County )); }
    {void * tlv62; tlv62 = (void *)(sizeof ( County )); }
    {cgc_size_t tlv61; tlv61 = (cgc_size_t)(sizeof ( County )); }
    {void * tlv64; tlv64 = (void *)(sizeof ( County )); }
    {cgc_size_t tlv63; tlv63 = (cgc_size_t)(sizeof ( County )); }
    {char * tlv67; tlv67 = (char *)(sizeof ( County )); }
    {char * tlv66; tlv66 = (char *)(sizeof ( County )); }
    {cgc_size_t tlv65; tlv65 = (cgc_size_t)(sizeof ( County )); }
    {void * tlv69; tlv69 = (void *)(sizeof ( County )); }
    {cgc_size_t tlv68; tlv68 = (cgc_size_t)(sizeof ( County )); }
    {char * tlv81; tlv81 = (char *)(sizeof ( County )); }
    {char * tlv82; tlv82 = (char *)(sizeof ( County )); }
}
void fix_ingred_countyParsers_4_15(){
fix_ingred_countyParsers_4_15_0();
}
void fix_ingred_countyParsers_4_16_8(){
int tlv4;
    bzero(&tlv4,sizeof(int));
    {int startIndex; startIndex = (int)(tlv4); }
    {int endIndex; endIndex = (int)(tlv4); }
    {int lastGood; lastGood = (int)(tlv4); }
    {int tempInt; tempInt = (int)(tlv4); }
    {char * tempChar; tempChar = (char *)(tlv4); }
    {int tlv1; tlv1 = (int)(tlv4); }
    {int tlv2; tlv2 = (int)(tlv4); }
    {int tlv3; tlv3 = (int)(tlv4); }
    {int tlv5; tlv5 = (int)(tlv4); }
    {int tlv6; tlv6 = (int)(tlv4); }
    {int tlv7; tlv7 = (int)(tlv4); }
    {int tlv8; tlv8 = (int)(tlv4); }
    {char tlv23; tlv23 = (char)(tlv4); }
    {int * tlv9; tlv9 = (int *)(tlv4); }
    {int tlv27; tlv27 = (int)(tlv4); }
    {int tlv26; tlv26 = (int)(tlv4); }
    {void * tlv12; tlv12 = (void *)(tlv4); }
    {cgc_size_t tlv11; tlv11 = (cgc_size_t)(tlv4); }
    {char tlv31; tlv31 = (char)(tlv4); }
    {cgc_size_t tlv35; tlv35 = (cgc_size_t)(tlv4); }
    {int tlv34; tlv34 = (int)(tlv4); }
    {char tlv37; tlv37 = (char)(tlv4); }
    {int tlv13; tlv13 = (int)(tlv4); }
    {char tlv39; tlv39 = (char)(tlv4); }
    {int tlv15; tlv15 = (int)(tlv4); }
    {int * tlv17; tlv17 = (int *)(tlv4); }
    {int * tlv19; tlv19 = (int *)(tlv4); }
    {int tlv42; tlv42 = (int)(tlv4); }
    {int tlv41; tlv41 = (int)(tlv4); }
    {void * tlv22; tlv22 = (void *)(tlv4); }
    {cgc_size_t tlv21; tlv21 = (cgc_size_t)(tlv4); }
    {char tlv46; tlv46 = (char)(tlv4); }
    {char * tlv78; tlv78 = (char *)(tlv4); }
    {char * tlv54; tlv54 = (char *)(tlv4); }
    {void * tlv49; tlv49 = (void *)(tlv4); }
    {cgc_size_t tlv48; tlv48 = (cgc_size_t)(tlv4); }
    {int * tlv50; tlv50 = (int *)(tlv4); }
    {void * tlv53; tlv53 = (void *)(tlv4); }
    {cgc_size_t tlv52; tlv52 = (cgc_size_t)(tlv4); }
    {char * tlv79; tlv79 = (char *)(tlv4); }
    {char * tlv80; tlv80 = (char *)(tlv4); }
    {void * tlv57; tlv57 = (void *)(tlv4); }
    {cgc_size_t tlv56; tlv56 = (cgc_size_t)(tlv4); }
    {char * tlv60; tlv60 = (char *)(tlv4); }
    {char * tlv59; tlv59 = (char *)(tlv4); }
    {cgc_size_t tlv58; tlv58 = (cgc_size_t)(tlv4); }
    {void * tlv62; tlv62 = (void *)(tlv4); }
    {cgc_size_t tlv61; tlv61 = (cgc_size_t)(tlv4); }
    {void * tlv64; tlv64 = (void *)(tlv4); }
    {cgc_size_t tlv63; tlv63 = (cgc_size_t)(tlv4); }
    {char * tlv67; tlv67 = (char *)(tlv4); }
    {char * tlv66; tlv66 = (char *)(tlv4); }
    {cgc_size_t tlv65; tlv65 = (cgc_size_t)(tlv4); }
    {void * tlv69; tlv69 = (void *)(tlv4); }
    {cgc_size_t tlv68; tlv68 = (cgc_size_t)(tlv4); }
    {char * tlv81; tlv81 = (char *)(tlv4); }
    {char * tlv82; tlv82 = (char *)(tlv4); }
}
void fix_ingred_countyParsers_4_16(){
fix_ingred_countyParsers_4_16_8();
}
void fix_ingred_countyParsers_4_21_1(){
char tlv79_ref;
    bzero(&tlv79_ref,1*sizeof(char));
char * tlv79 = &tlv79_ref;
    {int startIndex; startIndex = (int)(cgc_strlen ( tlv79 ) + 1); }
    {int endIndex; endIndex = (int)(cgc_strlen ( tlv79 ) + 1); }
    {int lastGood; lastGood = (int)(cgc_strlen ( tlv79 ) + 1); }
    {int tempInt; tempInt = (int)(cgc_strlen ( tlv79 ) + 1); }
    {char * tempChar; tempChar = (char *)(cgc_strlen ( tlv79 ) + 1); }
    {int tlv1; tlv1 = (int)(cgc_strlen ( tlv79 ) + 1); }
    {int tlv2; tlv2 = (int)(cgc_strlen ( tlv79 ) + 1); }
    {int tlv3; tlv3 = (int)(cgc_strlen ( tlv79 ) + 1); }
    {int tlv4; tlv4 = (int)(cgc_strlen ( tlv79 ) + 1); }
    {int tlv5; tlv5 = (int)(cgc_strlen ( tlv79 ) + 1); }
    {int tlv6; tlv6 = (int)(cgc_strlen ( tlv79 ) + 1); }
    {int tlv7; tlv7 = (int)(cgc_strlen ( tlv79 ) + 1); }
    {int tlv8; tlv8 = (int)(cgc_strlen ( tlv79 ) + 1); }
    {char tlv23; tlv23 = (char)(cgc_strlen ( tlv79 ) + 1); }
    {int * tlv9; tlv9 = (int *)(cgc_strlen ( tlv79 ) + 1); }
    {int tlv27; tlv27 = (int)(cgc_strlen ( tlv79 ) + 1); }
    {int tlv26; tlv26 = (int)(cgc_strlen ( tlv79 ) + 1); }
    {void * tlv12; tlv12 = (void *)(cgc_strlen ( tlv79 ) + 1); }
    {cgc_size_t tlv11; tlv11 = (cgc_size_t)(cgc_strlen ( tlv79 ) + 1); }
    {char tlv31; tlv31 = (char)(cgc_strlen ( tlv79 ) + 1); }
    {cgc_size_t tlv35; tlv35 = (cgc_size_t)(cgc_strlen ( tlv79 ) + 1); }
    {int tlv34; tlv34 = (int)(cgc_strlen ( tlv79 ) + 1); }
    {char tlv37; tlv37 = (char)(cgc_strlen ( tlv79 ) + 1); }
    {int tlv13; tlv13 = (int)(cgc_strlen ( tlv79 ) + 1); }
    {char tlv39; tlv39 = (char)(cgc_strlen ( tlv79 ) + 1); }
    {int tlv15; tlv15 = (int)(cgc_strlen ( tlv79 ) + 1); }
    {int * tlv17; tlv17 = (int *)(cgc_strlen ( tlv79 ) + 1); }
    {int * tlv19; tlv19 = (int *)(cgc_strlen ( tlv79 ) + 1); }
    {int tlv42; tlv42 = (int)(cgc_strlen ( tlv79 ) + 1); }
    {int tlv41; tlv41 = (int)(cgc_strlen ( tlv79 ) + 1); }
    {void * tlv22; tlv22 = (void *)(cgc_strlen ( tlv79 ) + 1); }
    {cgc_size_t tlv21; tlv21 = (cgc_size_t)(cgc_strlen ( tlv79 ) + 1); }
    {char tlv46; tlv46 = (char)(cgc_strlen ( tlv79 ) + 1); }
    {char * tlv78; tlv78 = (char *)(cgc_strlen ( tlv79 ) + 1); }
    {char * tlv54; tlv54 = (char *)(cgc_strlen ( tlv79 ) + 1); }
    {void * tlv49; tlv49 = (void *)(cgc_strlen ( tlv79 ) + 1); }
    {cgc_size_t tlv48; tlv48 = (cgc_size_t)(cgc_strlen ( tlv79 ) + 1); }
    {int * tlv50; tlv50 = (int *)(cgc_strlen ( tlv79 ) + 1); }
    {void * tlv53; tlv53 = (void *)(cgc_strlen ( tlv79 ) + 1); }
    {cgc_size_t tlv52; tlv52 = (cgc_size_t)(cgc_strlen ( tlv79 ) + 1); }
    {char * tlv80; tlv80 = (char *)(cgc_strlen ( tlv79 ) + 1); }
    {void * tlv57; tlv57 = (void *)(cgc_strlen ( tlv79 ) + 1); }
    {cgc_size_t tlv56; tlv56 = (cgc_size_t)(cgc_strlen ( tlv79 ) + 1); }
    {char * tlv60; tlv60 = (char *)(cgc_strlen ( tlv79 ) + 1); }
    {char * tlv59; tlv59 = (char *)(cgc_strlen ( tlv79 ) + 1); }
    {cgc_size_t tlv58; tlv58 = (cgc_size_t)(cgc_strlen ( tlv79 ) + 1); }
    {void * tlv62; tlv62 = (void *)(cgc_strlen ( tlv79 ) + 1); }
    {cgc_size_t tlv61; tlv61 = (cgc_size_t)(cgc_strlen ( tlv79 ) + 1); }
    {void * tlv64; tlv64 = (void *)(cgc_strlen ( tlv79 ) + 1); }
    {cgc_size_t tlv63; tlv63 = (cgc_size_t)(cgc_strlen ( tlv79 ) + 1); }
    {char * tlv67; tlv67 = (char *)(cgc_strlen ( tlv79 ) + 1); }
    {char * tlv66; tlv66 = (char *)(cgc_strlen ( tlv79 ) + 1); }
    {cgc_size_t tlv65; tlv65 = (cgc_size_t)(cgc_strlen ( tlv79 ) + 1); }
    {void * tlv69; tlv69 = (void *)(cgc_strlen ( tlv79 ) + 1); }
    {cgc_size_t tlv68; tlv68 = (cgc_size_t)(cgc_strlen ( tlv79 ) + 1); }
    {char * tlv81; tlv81 = (char *)(cgc_strlen ( tlv79 ) + 1); }
    {char * tlv82; tlv82 = (char *)(cgc_strlen ( tlv79 ) + 1); }
}
void fix_ingred_countyParsers_4_21(){
fix_ingred_countyParsers_4_21_1();
}
void fix_ingred_countyParsers_4_26_0(){
County newCounty_ref;
    bzero(&newCounty_ref,1*sizeof(County));
pCounty newCounty = &newCounty_ref;
    {int startIndex; startIndex = (int)(newCounty -> name); }
    {int endIndex; endIndex = (int)(newCounty -> name); }
    {int lastGood; lastGood = (int)(newCounty -> name); }
    {int tempInt; tempInt = (int)(newCounty -> name); }
    {char * tempChar; tempChar = (char *)(newCounty -> name); }
    {int tlv1; tlv1 = (int)(newCounty -> name); }
    {int tlv2; tlv2 = (int)(newCounty -> name); }
    {int tlv3; tlv3 = (int)(newCounty -> name); }
    {int tlv4; tlv4 = (int)(newCounty -> name); }
    {int tlv5; tlv5 = (int)(newCounty -> name); }
    {int tlv6; tlv6 = (int)(newCounty -> name); }
    {int tlv7; tlv7 = (int)(newCounty -> name); }
    {int tlv8; tlv8 = (int)(newCounty -> name); }
    {char tlv23; tlv23 = (char)(newCounty -> name); }
    {int * tlv9; tlv9 = (int *)(newCounty -> name); }
    {int tlv27; tlv27 = (int)(newCounty -> name); }
    {int tlv26; tlv26 = (int)(newCounty -> name); }
    {void * tlv12; tlv12 = (void *)(newCounty -> name); }
    {cgc_size_t tlv11; tlv11 = (cgc_size_t)(newCounty -> name); }
    {char tlv31; tlv31 = (char)(newCounty -> name); }
    {cgc_size_t tlv35; tlv35 = (cgc_size_t)(newCounty -> name); }
    {int tlv34; tlv34 = (int)(newCounty -> name); }
    {char tlv37; tlv37 = (char)(newCounty -> name); }
    {int tlv13; tlv13 = (int)(newCounty -> name); }
    {char tlv39; tlv39 = (char)(newCounty -> name); }
    {int tlv15; tlv15 = (int)(newCounty -> name); }
    {int * tlv17; tlv17 = (int *)(newCounty -> name); }
    {int * tlv19; tlv19 = (int *)(newCounty -> name); }
    {int tlv42; tlv42 = (int)(newCounty -> name); }
    {int tlv41; tlv41 = (int)(newCounty -> name); }
    {void * tlv22; tlv22 = (void *)(newCounty -> name); }
    {cgc_size_t tlv21; tlv21 = (cgc_size_t)(newCounty -> name); }
    {char tlv46; tlv46 = (char)(newCounty -> name); }
    {char * tlv78; tlv78 = (char *)(newCounty -> name); }
    {char * tlv54; tlv54 = (char *)(newCounty -> name); }
    {void * tlv49; tlv49 = (void *)(newCounty -> name); }
    {cgc_size_t tlv48; tlv48 = (cgc_size_t)(newCounty -> name); }
    {int * tlv50; tlv50 = (int *)(newCounty -> name); }
    {void * tlv53; tlv53 = (void *)(newCounty -> name); }
    {cgc_size_t tlv52; tlv52 = (cgc_size_t)(newCounty -> name); }
    {char * tlv79; tlv79 = (char *)(newCounty -> name); }
    {char * tlv80; tlv80 = (char *)(newCounty -> name); }
    {void * tlv57; tlv57 = (void *)(newCounty -> name); }
    {cgc_size_t tlv56; tlv56 = (cgc_size_t)(newCounty -> name); }
    {char * tlv60; tlv60 = (char *)(newCounty -> name); }
    {char * tlv59; tlv59 = (char *)(newCounty -> name); }
    {cgc_size_t tlv58; tlv58 = (cgc_size_t)(newCounty -> name); }
    {void * tlv62; tlv62 = (void *)(newCounty -> name); }
    {cgc_size_t tlv61; tlv61 = (cgc_size_t)(newCounty -> name); }
    {void * tlv64; tlv64 = (void *)(newCounty -> name); }
    {cgc_size_t tlv63; tlv63 = (cgc_size_t)(newCounty -> name); }
    {char * tlv67; tlv67 = (char *)(newCounty -> name); }
    {char * tlv66; tlv66 = (char *)(newCounty -> name); }
    {cgc_size_t tlv65; tlv65 = (cgc_size_t)(newCounty -> name); }
    {void * tlv69; tlv69 = (void *)(newCounty -> name); }
    {cgc_size_t tlv68; tlv68 = (cgc_size_t)(newCounty -> name); }
    {char * tlv81; tlv81 = (char *)(newCounty -> name); }
    {char * tlv82; tlv82 = (char *)(newCounty -> name); }
}
void fix_ingred_countyParsers_4_26_1(){
County newCounty_ref;
    bzero(&newCounty_ref,1*sizeof(County));
pCounty newCounty = &newCounty_ref;
    {int startIndex; startIndex = (int)(20); }
    {int endIndex; endIndex = (int)(20); }
    {int lastGood; lastGood = (int)(20); }
    {int tempInt; tempInt = (int)(20); }
    {char * tempChar; tempChar = (char *)(20); }
    {int tlv1; tlv1 = (int)(20); }
    {int tlv2; tlv2 = (int)(20); }
    {int tlv3; tlv3 = (int)(20); }
    {int tlv4; tlv4 = (int)(20); }
    {int tlv5; tlv5 = (int)(20); }
    {int tlv6; tlv6 = (int)(20); }
    {int tlv7; tlv7 = (int)(20); }
    {int tlv8; tlv8 = (int)(20); }
    {char tlv23; tlv23 = (char)(20); }
    {int * tlv9; tlv9 = (int *)(20); }
    {int tlv27; tlv27 = (int)(20); }
    {int tlv26; tlv26 = (int)(20); }
    {void * tlv12; tlv12 = (void *)(20); }
    {cgc_size_t tlv11; tlv11 = (cgc_size_t)(20); }
    {char tlv31; tlv31 = (char)(20); }
    {cgc_size_t tlv35; tlv35 = (cgc_size_t)(20); }
    {int tlv34; tlv34 = (int)(20); }
    {char tlv37; tlv37 = (char)(20); }
    {int tlv13; tlv13 = (int)(20); }
    {char tlv39; tlv39 = (char)(20); }
    {int tlv15; tlv15 = (int)(20); }
    {int * tlv17; tlv17 = (int *)(20); }
    {int * tlv19; tlv19 = (int *)(20); }
    {int tlv42; tlv42 = (int)(20); }
    {int tlv41; tlv41 = (int)(20); }
    {void * tlv22; tlv22 = (void *)(20); }
    {cgc_size_t tlv21; tlv21 = (cgc_size_t)(20); }
    {char tlv46; tlv46 = (char)(20); }
    {char * tlv78; tlv78 = (char *)(20); }
    {char * tlv54; tlv54 = (char *)(20); }
    {void * tlv49; tlv49 = (void *)(20); }
    {cgc_size_t tlv48; tlv48 = (cgc_size_t)(20); }
    {int * tlv50; tlv50 = (int *)(20); }
    {void * tlv53; tlv53 = (void *)(20); }
    {cgc_size_t tlv52; tlv52 = (cgc_size_t)(20); }
    {char * tlv79; tlv79 = (char *)(20); }
    {char * tlv80; tlv80 = (char *)(20); }
    {void * tlv57; tlv57 = (void *)(20); }
    {cgc_size_t tlv56; tlv56 = (cgc_size_t)(20); }
    {char * tlv60; tlv60 = (char *)(20); }
    {char * tlv59; tlv59 = (char *)(20); }
    {cgc_size_t tlv58; tlv58 = (cgc_size_t)(20); }
    {void * tlv62; tlv62 = (void *)(20); }
    {cgc_size_t tlv61; tlv61 = (cgc_size_t)(20); }
    {void * tlv64; tlv64 = (void *)(20); }
    {cgc_size_t tlv63; tlv63 = (cgc_size_t)(20); }
    {char * tlv67; tlv67 = (char *)(20); }
    {char * tlv66; tlv66 = (char *)(20); }
    {cgc_size_t tlv65; tlv65 = (cgc_size_t)(20); }
    {void * tlv69; tlv69 = (void *)(20); }
    {cgc_size_t tlv68; tlv68 = (cgc_size_t)(20); }
    {char * tlv81; tlv81 = (char *)(20); }
    {char * tlv82; tlv82 = (char *)(20); }
}
void fix_ingred_countyParsers_4_26(){
fix_ingred_countyParsers_4_26_0();
fix_ingred_countyParsers_4_26_1();
}
void fix_ingred_countyParsers_4_27_0(){
County newCounty_ref;
    bzero(&newCounty_ref,1*sizeof(County));
pCounty newCounty = &newCounty_ref;
    {int startIndex; startIndex = (int)(newCounty -> name); }
    {int endIndex; endIndex = (int)(newCounty -> name); }
    {int lastGood; lastGood = (int)(newCounty -> name); }
    {int tempInt; tempInt = (int)(newCounty -> name); }
    {char * tempChar; tempChar = (char *)(newCounty -> name); }
    {int tlv1; tlv1 = (int)(newCounty -> name); }
    {int tlv2; tlv2 = (int)(newCounty -> name); }
    {int tlv3; tlv3 = (int)(newCounty -> name); }
    {int tlv4; tlv4 = (int)(newCounty -> name); }
    {int tlv5; tlv5 = (int)(newCounty -> name); }
    {int tlv6; tlv6 = (int)(newCounty -> name); }
    {int tlv7; tlv7 = (int)(newCounty -> name); }
    {int tlv8; tlv8 = (int)(newCounty -> name); }
    {char tlv23; tlv23 = (char)(newCounty -> name); }
    {int * tlv9; tlv9 = (int *)(newCounty -> name); }
    {int tlv27; tlv27 = (int)(newCounty -> name); }
    {int tlv26; tlv26 = (int)(newCounty -> name); }
    {void * tlv12; tlv12 = (void *)(newCounty -> name); }
    {cgc_size_t tlv11; tlv11 = (cgc_size_t)(newCounty -> name); }
    {char tlv31; tlv31 = (char)(newCounty -> name); }
    {cgc_size_t tlv35; tlv35 = (cgc_size_t)(newCounty -> name); }
    {int tlv34; tlv34 = (int)(newCounty -> name); }
    {char tlv37; tlv37 = (char)(newCounty -> name); }
    {int tlv13; tlv13 = (int)(newCounty -> name); }
    {char tlv39; tlv39 = (char)(newCounty -> name); }
    {int tlv15; tlv15 = (int)(newCounty -> name); }
    {int * tlv17; tlv17 = (int *)(newCounty -> name); }
    {int * tlv19; tlv19 = (int *)(newCounty -> name); }
    {int tlv42; tlv42 = (int)(newCounty -> name); }
    {int tlv41; tlv41 = (int)(newCounty -> name); }
    {void * tlv22; tlv22 = (void *)(newCounty -> name); }
    {cgc_size_t tlv21; tlv21 = (cgc_size_t)(newCounty -> name); }
    {char tlv46; tlv46 = (char)(newCounty -> name); }
    {char * tlv78; tlv78 = (char *)(newCounty -> name); }
    {char * tlv54; tlv54 = (char *)(newCounty -> name); }
    {void * tlv49; tlv49 = (void *)(newCounty -> name); }
    {cgc_size_t tlv48; tlv48 = (cgc_size_t)(newCounty -> name); }
    {int * tlv50; tlv50 = (int *)(newCounty -> name); }
    {void * tlv53; tlv53 = (void *)(newCounty -> name); }
    {cgc_size_t tlv52; tlv52 = (cgc_size_t)(newCounty -> name); }
    {char * tlv79; tlv79 = (char *)(newCounty -> name); }
    {char * tlv80; tlv80 = (char *)(newCounty -> name); }
    {void * tlv57; tlv57 = (void *)(newCounty -> name); }
    {cgc_size_t tlv56; tlv56 = (cgc_size_t)(newCounty -> name); }
    {char * tlv60; tlv60 = (char *)(newCounty -> name); }
    {char * tlv59; tlv59 = (char *)(newCounty -> name); }
    {cgc_size_t tlv58; tlv58 = (cgc_size_t)(newCounty -> name); }
    {void * tlv62; tlv62 = (void *)(newCounty -> name); }
    {cgc_size_t tlv61; tlv61 = (cgc_size_t)(newCounty -> name); }
    {void * tlv64; tlv64 = (void *)(newCounty -> name); }
    {cgc_size_t tlv63; tlv63 = (cgc_size_t)(newCounty -> name); }
    {char * tlv67; tlv67 = (char *)(newCounty -> name); }
    {char * tlv66; tlv66 = (char *)(newCounty -> name); }
    {cgc_size_t tlv65; tlv65 = (cgc_size_t)(newCounty -> name); }
    {void * tlv69; tlv69 = (void *)(newCounty -> name); }
    {cgc_size_t tlv68; tlv68 = (cgc_size_t)(newCounty -> name); }
    {char * tlv81; tlv81 = (char *)(newCounty -> name); }
    {char * tlv82; tlv82 = (char *)(newCounty -> name); }
}
void fix_ingred_countyParsers_4_27_2(){
County newCounty_ref;
    bzero(&newCounty_ref,1*sizeof(County));
pCounty newCounty = &newCounty_ref;
    {int startIndex; startIndex = (int)(19); }
    {int endIndex; endIndex = (int)(19); }
    {int lastGood; lastGood = (int)(19); }
    {int tempInt; tempInt = (int)(19); }
    {char * tempChar; tempChar = (char *)(19); }
    {int tlv4; tlv4 = (int)(19); }
    {int tlv5; tlv5 = (int)(19); }
    {int tlv6; tlv6 = (int)(19); }
    {int tlv7; tlv7 = (int)(19); }
    {int tlv8; tlv8 = (int)(19); }
    {char tlv23; tlv23 = (char)(19); }
    {int * tlv9; tlv9 = (int *)(19); }
    {int tlv27; tlv27 = (int)(19); }
    {int tlv26; tlv26 = (int)(19); }
    {void * tlv12; tlv12 = (void *)(19); }
    {cgc_size_t tlv11; tlv11 = (cgc_size_t)(19); }
    {char tlv31; tlv31 = (char)(19); }
    {cgc_size_t tlv35; tlv35 = (cgc_size_t)(19); }
    {int tlv34; tlv34 = (int)(19); }
    {char tlv37; tlv37 = (char)(19); }
    {int tlv13; tlv13 = (int)(19); }
    {int tlv15; tlv15 = (int)(19); }
    {int * tlv17; tlv17 = (int *)(19); }
    {int * tlv19; tlv19 = (int *)(19); }
    {int tlv42; tlv42 = (int)(19); }
    {int tlv41; tlv41 = (int)(19); }
    {void * tlv22; tlv22 = (void *)(19); }
    {cgc_size_t tlv21; tlv21 = (cgc_size_t)(19); }
    {char tlv46; tlv46 = (char)(19); }
    {char * tlv78; tlv78 = (char *)(19); }
    {char * tlv54; tlv54 = (char *)(19); }
    {int * tlv50; tlv50 = (int *)(19); }
    {void * tlv53; tlv53 = (void *)(19); }
    {cgc_size_t tlv52; tlv52 = (cgc_size_t)(19); }
    {char * tlv79; tlv79 = (char *)(19); }
    {char * tlv80; tlv80 = (char *)(19); }
    {void * tlv57; tlv57 = (void *)(19); }
    {char * tlv60; tlv60 = (char *)(19); }
    {char * tlv59; tlv59 = (char *)(19); }
    {cgc_size_t tlv58; tlv58 = (cgc_size_t)(19); }
    {void * tlv62; tlv62 = (void *)(19); }
    {cgc_size_t tlv61; tlv61 = (cgc_size_t)(19); }
    {void * tlv64; tlv64 = (void *)(19); }
    {cgc_size_t tlv63; tlv63 = (cgc_size_t)(19); }
    {char * tlv67; tlv67 = (char *)(19); }
    {char * tlv66; tlv66 = (char *)(19); }
    {cgc_size_t tlv65; tlv65 = (cgc_size_t)(19); }
    {void * tlv69; tlv69 = (void *)(19); }
    {cgc_size_t tlv68; tlv68 = (cgc_size_t)(19); }
    {char * tlv81; tlv81 = (char *)(19); }
    {char * tlv82; tlv82 = (char *)(19); }
}
void fix_ingred_countyParsers_4_27(){
fix_ingred_countyParsers_4_27_0();
fix_ingred_countyParsers_4_27_2();
}
void fix_ingred_countyParsers_4_29_1(){
char tlv81_ref;
    bzero(&tlv81_ref,1*sizeof(char));
char * tlv81 = &tlv81_ref;
    {int startIndex; startIndex = (int)(cgc_strlen ( tlv81 ) + 1); }
    {int endIndex; endIndex = (int)(cgc_strlen ( tlv81 ) + 1); }
    {int lastGood; lastGood = (int)(cgc_strlen ( tlv81 ) + 1); }
    {int tempInt; tempInt = (int)(cgc_strlen ( tlv81 ) + 1); }
    {char * tempChar; tempChar = (char *)(cgc_strlen ( tlv81 ) + 1); }
    {int tlv1; tlv1 = (int)(cgc_strlen ( tlv81 ) + 1); }
    {int tlv2; tlv2 = (int)(cgc_strlen ( tlv81 ) + 1); }
    {int tlv3; tlv3 = (int)(cgc_strlen ( tlv81 ) + 1); }
    {int tlv4; tlv4 = (int)(cgc_strlen ( tlv81 ) + 1); }
    {int tlv5; tlv5 = (int)(cgc_strlen ( tlv81 ) + 1); }
    {int tlv6; tlv6 = (int)(cgc_strlen ( tlv81 ) + 1); }
    {int tlv7; tlv7 = (int)(cgc_strlen ( tlv81 ) + 1); }
    {int tlv8; tlv8 = (int)(cgc_strlen ( tlv81 ) + 1); }
    {char tlv23; tlv23 = (char)(cgc_strlen ( tlv81 ) + 1); }
    {int * tlv9; tlv9 = (int *)(cgc_strlen ( tlv81 ) + 1); }
    {int tlv27; tlv27 = (int)(cgc_strlen ( tlv81 ) + 1); }
    {int tlv26; tlv26 = (int)(cgc_strlen ( tlv81 ) + 1); }
    {void * tlv12; tlv12 = (void *)(cgc_strlen ( tlv81 ) + 1); }
    {cgc_size_t tlv11; tlv11 = (cgc_size_t)(cgc_strlen ( tlv81 ) + 1); }
    {char tlv31; tlv31 = (char)(cgc_strlen ( tlv81 ) + 1); }
    {cgc_size_t tlv35; tlv35 = (cgc_size_t)(cgc_strlen ( tlv81 ) + 1); }
    {int tlv34; tlv34 = (int)(cgc_strlen ( tlv81 ) + 1); }
    {char tlv37; tlv37 = (char)(cgc_strlen ( tlv81 ) + 1); }
    {int tlv13; tlv13 = (int)(cgc_strlen ( tlv81 ) + 1); }
    {char tlv39; tlv39 = (char)(cgc_strlen ( tlv81 ) + 1); }
    {int tlv15; tlv15 = (int)(cgc_strlen ( tlv81 ) + 1); }
    {int * tlv17; tlv17 = (int *)(cgc_strlen ( tlv81 ) + 1); }
    {int * tlv19; tlv19 = (int *)(cgc_strlen ( tlv81 ) + 1); }
    {int tlv42; tlv42 = (int)(cgc_strlen ( tlv81 ) + 1); }
    {int tlv41; tlv41 = (int)(cgc_strlen ( tlv81 ) + 1); }
    {void * tlv22; tlv22 = (void *)(cgc_strlen ( tlv81 ) + 1); }
    {cgc_size_t tlv21; tlv21 = (cgc_size_t)(cgc_strlen ( tlv81 ) + 1); }
    {char tlv46; tlv46 = (char)(cgc_strlen ( tlv81 ) + 1); }
    {char * tlv78; tlv78 = (char *)(cgc_strlen ( tlv81 ) + 1); }
    {char * tlv54; tlv54 = (char *)(cgc_strlen ( tlv81 ) + 1); }
    {void * tlv49; tlv49 = (void *)(cgc_strlen ( tlv81 ) + 1); }
    {cgc_size_t tlv48; tlv48 = (cgc_size_t)(cgc_strlen ( tlv81 ) + 1); }
    {int * tlv50; tlv50 = (int *)(cgc_strlen ( tlv81 ) + 1); }
    {void * tlv53; tlv53 = (void *)(cgc_strlen ( tlv81 ) + 1); }
    {cgc_size_t tlv52; tlv52 = (cgc_size_t)(cgc_strlen ( tlv81 ) + 1); }
    {char * tlv79; tlv79 = (char *)(cgc_strlen ( tlv81 ) + 1); }
    {char * tlv80; tlv80 = (char *)(cgc_strlen ( tlv81 ) + 1); }
    {void * tlv57; tlv57 = (void *)(cgc_strlen ( tlv81 ) + 1); }
    {cgc_size_t tlv56; tlv56 = (cgc_size_t)(cgc_strlen ( tlv81 ) + 1); }
    {char * tlv60; tlv60 = (char *)(cgc_strlen ( tlv81 ) + 1); }
    {char * tlv59; tlv59 = (char *)(cgc_strlen ( tlv81 ) + 1); }
    {cgc_size_t tlv58; tlv58 = (cgc_size_t)(cgc_strlen ( tlv81 ) + 1); }
    {void * tlv62; tlv62 = (void *)(cgc_strlen ( tlv81 ) + 1); }
    {cgc_size_t tlv61; tlv61 = (cgc_size_t)(cgc_strlen ( tlv81 ) + 1); }
    {void * tlv64; tlv64 = (void *)(cgc_strlen ( tlv81 ) + 1); }
    {cgc_size_t tlv63; tlv63 = (cgc_size_t)(cgc_strlen ( tlv81 ) + 1); }
    {char * tlv67; tlv67 = (char *)(cgc_strlen ( tlv81 ) + 1); }
    {char * tlv66; tlv66 = (char *)(cgc_strlen ( tlv81 ) + 1); }
    {cgc_size_t tlv65; tlv65 = (cgc_size_t)(cgc_strlen ( tlv81 ) + 1); }
    {void * tlv69; tlv69 = (void *)(cgc_strlen ( tlv81 ) + 1); }
    {cgc_size_t tlv68; tlv68 = (cgc_size_t)(cgc_strlen ( tlv81 ) + 1); }
    {char * tlv82; tlv82 = (char *)(cgc_strlen ( tlv81 ) + 1); }
}
void fix_ingred_countyParsers_4_29(){
fix_ingred_countyParsers_4_29_1();
}
void fix_ingred_countyParsers_4_33_0(){
County newCounty_ref;
    bzero(&newCounty_ref,1*sizeof(County));
pCounty newCounty = &newCounty_ref;
    {int startIndex; startIndex = (int)(newCounty -> seat); }
    {int endIndex; endIndex = (int)(newCounty -> seat); }
    {int lastGood; lastGood = (int)(newCounty -> seat); }
    {int tempInt; tempInt = (int)(newCounty -> seat); }
    {char * tempChar; tempChar = (char *)(newCounty -> seat); }
    {int tlv1; tlv1 = (int)(newCounty -> seat); }
    {int tlv2; tlv2 = (int)(newCounty -> seat); }
    {int tlv3; tlv3 = (int)(newCounty -> seat); }
    {int tlv4; tlv4 = (int)(newCounty -> seat); }
    {int tlv5; tlv5 = (int)(newCounty -> seat); }
    {int tlv6; tlv6 = (int)(newCounty -> seat); }
    {int tlv7; tlv7 = (int)(newCounty -> seat); }
    {int tlv8; tlv8 = (int)(newCounty -> seat); }
    {char tlv23; tlv23 = (char)(newCounty -> seat); }
    {int * tlv9; tlv9 = (int *)(newCounty -> seat); }
    {int tlv27; tlv27 = (int)(newCounty -> seat); }
    {int tlv26; tlv26 = (int)(newCounty -> seat); }
    {void * tlv12; tlv12 = (void *)(newCounty -> seat); }
    {cgc_size_t tlv11; tlv11 = (cgc_size_t)(newCounty -> seat); }
    {char tlv31; tlv31 = (char)(newCounty -> seat); }
    {cgc_size_t tlv35; tlv35 = (cgc_size_t)(newCounty -> seat); }
    {int tlv34; tlv34 = (int)(newCounty -> seat); }
    {char tlv37; tlv37 = (char)(newCounty -> seat); }
    {int tlv13; tlv13 = (int)(newCounty -> seat); }
    {char tlv39; tlv39 = (char)(newCounty -> seat); }
    {int tlv15; tlv15 = (int)(newCounty -> seat); }
    {int * tlv17; tlv17 = (int *)(newCounty -> seat); }
    {int * tlv19; tlv19 = (int *)(newCounty -> seat); }
    {int tlv42; tlv42 = (int)(newCounty -> seat); }
    {int tlv41; tlv41 = (int)(newCounty -> seat); }
    {void * tlv22; tlv22 = (void *)(newCounty -> seat); }
    {cgc_size_t tlv21; tlv21 = (cgc_size_t)(newCounty -> seat); }
    {char tlv46; tlv46 = (char)(newCounty -> seat); }
    {char * tlv78; tlv78 = (char *)(newCounty -> seat); }
    {char * tlv54; tlv54 = (char *)(newCounty -> seat); }
    {void * tlv49; tlv49 = (void *)(newCounty -> seat); }
    {cgc_size_t tlv48; tlv48 = (cgc_size_t)(newCounty -> seat); }
    {int * tlv50; tlv50 = (int *)(newCounty -> seat); }
    {void * tlv53; tlv53 = (void *)(newCounty -> seat); }
    {cgc_size_t tlv52; tlv52 = (cgc_size_t)(newCounty -> seat); }
    {char * tlv79; tlv79 = (char *)(newCounty -> seat); }
    {char * tlv80; tlv80 = (char *)(newCounty -> seat); }
    {void * tlv57; tlv57 = (void *)(newCounty -> seat); }
    {cgc_size_t tlv56; tlv56 = (cgc_size_t)(newCounty -> seat); }
    {char * tlv60; tlv60 = (char *)(newCounty -> seat); }
    {char * tlv59; tlv59 = (char *)(newCounty -> seat); }
    {cgc_size_t tlv58; tlv58 = (cgc_size_t)(newCounty -> seat); }
    {void * tlv62; tlv62 = (void *)(newCounty -> seat); }
    {cgc_size_t tlv61; tlv61 = (cgc_size_t)(newCounty -> seat); }
    {void * tlv64; tlv64 = (void *)(newCounty -> seat); }
    {cgc_size_t tlv63; tlv63 = (cgc_size_t)(newCounty -> seat); }
    {char * tlv67; tlv67 = (char *)(newCounty -> seat); }
    {char * tlv66; tlv66 = (char *)(newCounty -> seat); }
    {cgc_size_t tlv65; tlv65 = (cgc_size_t)(newCounty -> seat); }
    {void * tlv69; tlv69 = (void *)(newCounty -> seat); }
    {cgc_size_t tlv68; tlv68 = (cgc_size_t)(newCounty -> seat); }
    {char * tlv81; tlv81 = (char *)(newCounty -> seat); }
    {char * tlv82; tlv82 = (char *)(newCounty -> seat); }
}
void fix_ingred_countyParsers_4_33(){
fix_ingred_countyParsers_4_33_0();
}
void fix_ingred_countyParsers_4_34_0(){
County newCounty_ref;
    bzero(&newCounty_ref,1*sizeof(County));
pCounty newCounty = &newCounty_ref;
    {int startIndex; startIndex = (int)(newCounty -> seat); }
    {int endIndex; endIndex = (int)(newCounty -> seat); }
    {int lastGood; lastGood = (int)(newCounty -> seat); }
    {int tempInt; tempInt = (int)(newCounty -> seat); }
    {char * tempChar; tempChar = (char *)(newCounty -> seat); }
    {int tlv1; tlv1 = (int)(newCounty -> seat); }
    {int tlv2; tlv2 = (int)(newCounty -> seat); }
    {int tlv3; tlv3 = (int)(newCounty -> seat); }
    {int tlv4; tlv4 = (int)(newCounty -> seat); }
    {int tlv5; tlv5 = (int)(newCounty -> seat); }
    {int tlv6; tlv6 = (int)(newCounty -> seat); }
    {int tlv7; tlv7 = (int)(newCounty -> seat); }
    {int tlv8; tlv8 = (int)(newCounty -> seat); }
    {char tlv23; tlv23 = (char)(newCounty -> seat); }
    {int * tlv9; tlv9 = (int *)(newCounty -> seat); }
    {int tlv27; tlv27 = (int)(newCounty -> seat); }
    {int tlv26; tlv26 = (int)(newCounty -> seat); }
    {void * tlv12; tlv12 = (void *)(newCounty -> seat); }
    {cgc_size_t tlv11; tlv11 = (cgc_size_t)(newCounty -> seat); }
    {char tlv31; tlv31 = (char)(newCounty -> seat); }
    {cgc_size_t tlv35; tlv35 = (cgc_size_t)(newCounty -> seat); }
    {int tlv34; tlv34 = (int)(newCounty -> seat); }
    {char tlv37; tlv37 = (char)(newCounty -> seat); }
    {int tlv13; tlv13 = (int)(newCounty -> seat); }
    {char tlv39; tlv39 = (char)(newCounty -> seat); }
    {int tlv15; tlv15 = (int)(newCounty -> seat); }
    {int * tlv17; tlv17 = (int *)(newCounty -> seat); }
    {int * tlv19; tlv19 = (int *)(newCounty -> seat); }
    {int tlv42; tlv42 = (int)(newCounty -> seat); }
    {int tlv41; tlv41 = (int)(newCounty -> seat); }
    {void * tlv22; tlv22 = (void *)(newCounty -> seat); }
    {cgc_size_t tlv21; tlv21 = (cgc_size_t)(newCounty -> seat); }
    {char tlv46; tlv46 = (char)(newCounty -> seat); }
    {char * tlv78; tlv78 = (char *)(newCounty -> seat); }
    {char * tlv54; tlv54 = (char *)(newCounty -> seat); }
    {void * tlv49; tlv49 = (void *)(newCounty -> seat); }
    {cgc_size_t tlv48; tlv48 = (cgc_size_t)(newCounty -> seat); }
    {int * tlv50; tlv50 = (int *)(newCounty -> seat); }
    {void * tlv53; tlv53 = (void *)(newCounty -> seat); }
    {cgc_size_t tlv52; tlv52 = (cgc_size_t)(newCounty -> seat); }
    {char * tlv79; tlv79 = (char *)(newCounty -> seat); }
    {char * tlv80; tlv80 = (char *)(newCounty -> seat); }
    {void * tlv57; tlv57 = (void *)(newCounty -> seat); }
    {cgc_size_t tlv56; tlv56 = (cgc_size_t)(newCounty -> seat); }
    {char * tlv60; tlv60 = (char *)(newCounty -> seat); }
    {char * tlv59; tlv59 = (char *)(newCounty -> seat); }
    {cgc_size_t tlv58; tlv58 = (cgc_size_t)(newCounty -> seat); }
    {void * tlv62; tlv62 = (void *)(newCounty -> seat); }
    {cgc_size_t tlv61; tlv61 = (cgc_size_t)(newCounty -> seat); }
    {void * tlv64; tlv64 = (void *)(newCounty -> seat); }
    {cgc_size_t tlv63; tlv63 = (cgc_size_t)(newCounty -> seat); }
    {char * tlv67; tlv67 = (char *)(newCounty -> seat); }
    {char * tlv66; tlv66 = (char *)(newCounty -> seat); }
    {cgc_size_t tlv65; tlv65 = (cgc_size_t)(newCounty -> seat); }
    {void * tlv69; tlv69 = (void *)(newCounty -> seat); }
    {cgc_size_t tlv68; tlv68 = (cgc_size_t)(newCounty -> seat); }
    {char * tlv81; tlv81 = (char *)(newCounty -> seat); }
    {char * tlv82; tlv82 = (char *)(newCounty -> seat); }
}
void fix_ingred_countyParsers_4_34(){
fix_ingred_countyParsers_4_34_0();
}
void fix_ingred_countyParsers_4_36_1(){
char tlv82_ref;
    bzero(&tlv82_ref,1*sizeof(char));
char * tlv82 = &tlv82_ref;
    {int startIndex; startIndex = (int)(cgc_strlen ( tlv82 ) + 1); }
    {int endIndex; endIndex = (int)(cgc_strlen ( tlv82 ) + 1); }
    {int lastGood; lastGood = (int)(cgc_strlen ( tlv82 ) + 1); }
    {int tempInt; tempInt = (int)(cgc_strlen ( tlv82 ) + 1); }
    {char * tempChar; tempChar = (char *)(cgc_strlen ( tlv82 ) + 1); }
    {int tlv1; tlv1 = (int)(cgc_strlen ( tlv82 ) + 1); }
    {int tlv2; tlv2 = (int)(cgc_strlen ( tlv82 ) + 1); }
    {int tlv3; tlv3 = (int)(cgc_strlen ( tlv82 ) + 1); }
    {int tlv4; tlv4 = (int)(cgc_strlen ( tlv82 ) + 1); }
    {int tlv5; tlv5 = (int)(cgc_strlen ( tlv82 ) + 1); }
    {int tlv6; tlv6 = (int)(cgc_strlen ( tlv82 ) + 1); }
    {int tlv7; tlv7 = (int)(cgc_strlen ( tlv82 ) + 1); }
    {int tlv8; tlv8 = (int)(cgc_strlen ( tlv82 ) + 1); }
    {char tlv23; tlv23 = (char)(cgc_strlen ( tlv82 ) + 1); }
    {int * tlv9; tlv9 = (int *)(cgc_strlen ( tlv82 ) + 1); }
    {int tlv27; tlv27 = (int)(cgc_strlen ( tlv82 ) + 1); }
    {int tlv26; tlv26 = (int)(cgc_strlen ( tlv82 ) + 1); }
    {void * tlv12; tlv12 = (void *)(cgc_strlen ( tlv82 ) + 1); }
    {cgc_size_t tlv11; tlv11 = (cgc_size_t)(cgc_strlen ( tlv82 ) + 1); }
    {char tlv31; tlv31 = (char)(cgc_strlen ( tlv82 ) + 1); }
    {cgc_size_t tlv35; tlv35 = (cgc_size_t)(cgc_strlen ( tlv82 ) + 1); }
    {int tlv34; tlv34 = (int)(cgc_strlen ( tlv82 ) + 1); }
    {char tlv37; tlv37 = (char)(cgc_strlen ( tlv82 ) + 1); }
    {int tlv13; tlv13 = (int)(cgc_strlen ( tlv82 ) + 1); }
    {char tlv39; tlv39 = (char)(cgc_strlen ( tlv82 ) + 1); }
    {int tlv15; tlv15 = (int)(cgc_strlen ( tlv82 ) + 1); }
    {int * tlv17; tlv17 = (int *)(cgc_strlen ( tlv82 ) + 1); }
    {int * tlv19; tlv19 = (int *)(cgc_strlen ( tlv82 ) + 1); }
    {int tlv42; tlv42 = (int)(cgc_strlen ( tlv82 ) + 1); }
    {int tlv41; tlv41 = (int)(cgc_strlen ( tlv82 ) + 1); }
    {void * tlv22; tlv22 = (void *)(cgc_strlen ( tlv82 ) + 1); }
    {cgc_size_t tlv21; tlv21 = (cgc_size_t)(cgc_strlen ( tlv82 ) + 1); }
    {char tlv46; tlv46 = (char)(cgc_strlen ( tlv82 ) + 1); }
    {char * tlv78; tlv78 = (char *)(cgc_strlen ( tlv82 ) + 1); }
    {char * tlv54; tlv54 = (char *)(cgc_strlen ( tlv82 ) + 1); }
    {void * tlv49; tlv49 = (void *)(cgc_strlen ( tlv82 ) + 1); }
    {cgc_size_t tlv48; tlv48 = (cgc_size_t)(cgc_strlen ( tlv82 ) + 1); }
    {int * tlv50; tlv50 = (int *)(cgc_strlen ( tlv82 ) + 1); }
    {void * tlv53; tlv53 = (void *)(cgc_strlen ( tlv82 ) + 1); }
    {cgc_size_t tlv52; tlv52 = (cgc_size_t)(cgc_strlen ( tlv82 ) + 1); }
    {char * tlv79; tlv79 = (char *)(cgc_strlen ( tlv82 ) + 1); }
    {char * tlv80; tlv80 = (char *)(cgc_strlen ( tlv82 ) + 1); }
    {void * tlv57; tlv57 = (void *)(cgc_strlen ( tlv82 ) + 1); }
    {cgc_size_t tlv56; tlv56 = (cgc_size_t)(cgc_strlen ( tlv82 ) + 1); }
    {char * tlv60; tlv60 = (char *)(cgc_strlen ( tlv82 ) + 1); }
    {char * tlv59; tlv59 = (char *)(cgc_strlen ( tlv82 ) + 1); }
    {cgc_size_t tlv58; tlv58 = (cgc_size_t)(cgc_strlen ( tlv82 ) + 1); }
    {void * tlv62; tlv62 = (void *)(cgc_strlen ( tlv82 ) + 1); }
    {cgc_size_t tlv61; tlv61 = (cgc_size_t)(cgc_strlen ( tlv82 ) + 1); }
    {void * tlv64; tlv64 = (void *)(cgc_strlen ( tlv82 ) + 1); }
    {cgc_size_t tlv63; tlv63 = (cgc_size_t)(cgc_strlen ( tlv82 ) + 1); }
    {char * tlv67; tlv67 = (char *)(cgc_strlen ( tlv82 ) + 1); }
    {char * tlv66; tlv66 = (char *)(cgc_strlen ( tlv82 ) + 1); }
    {cgc_size_t tlv65; tlv65 = (cgc_size_t)(cgc_strlen ( tlv82 ) + 1); }
    {void * tlv69; tlv69 = (void *)(cgc_strlen ( tlv82 ) + 1); }
    {cgc_size_t tlv68; tlv68 = (cgc_size_t)(cgc_strlen ( tlv82 ) + 1); }
    {char * tlv81; tlv81 = (char *)(cgc_strlen ( tlv82 ) + 1); }
}
void fix_ingred_countyParsers_4_36(){
fix_ingred_countyParsers_4_36_1();
}
void fix_ingred_countyParsers_4_46_0(){
County newCounty_ref;
    bzero(&newCounty_ref,1*sizeof(County));
pCounty newCounty = &newCounty_ref;
    {int startIndex; startIndex = (int)(newCounty -> border_count); }
    {int endIndex; endIndex = (int)(newCounty -> border_count); }
    {int lastGood; lastGood = (int)(newCounty -> border_count); }
    {int tempInt; tempInt = (int)(newCounty -> border_count); }
    {char * tempChar; tempChar = (char *)(newCounty -> border_count); }
    {int tlv1; tlv1 = (int)(newCounty -> border_count); }
    {int tlv2; tlv2 = (int)(newCounty -> border_count); }
    {int tlv3; tlv3 = (int)(newCounty -> border_count); }
    {int tlv4; tlv4 = (int)(newCounty -> border_count); }
    {int tlv5; tlv5 = (int)(newCounty -> border_count); }
    {int tlv6; tlv6 = (int)(newCounty -> border_count); }
    {int tlv7; tlv7 = (int)(newCounty -> border_count); }
    {int tlv8; tlv8 = (int)(newCounty -> border_count); }
    {char tlv23; tlv23 = (char)(newCounty -> border_count); }
    {int * tlv9; tlv9 = (int *)(newCounty -> border_count); }
    {int tlv27; tlv27 = (int)(newCounty -> border_count); }
    {int tlv26; tlv26 = (int)(newCounty -> border_count); }
    {void * tlv12; tlv12 = (void *)(newCounty -> border_count); }
    {cgc_size_t tlv11; tlv11 = (cgc_size_t)(newCounty -> border_count); }
    {char tlv31; tlv31 = (char)(newCounty -> border_count); }
    {cgc_size_t tlv35; tlv35 = (cgc_size_t)(newCounty -> border_count); }
    {int tlv34; tlv34 = (int)(newCounty -> border_count); }
    {char tlv37; tlv37 = (char)(newCounty -> border_count); }
    {int tlv13; tlv13 = (int)(newCounty -> border_count); }
    {char tlv39; tlv39 = (char)(newCounty -> border_count); }
    {int tlv15; tlv15 = (int)(newCounty -> border_count); }
    {int * tlv17; tlv17 = (int *)(newCounty -> border_count); }
    {int * tlv19; tlv19 = (int *)(newCounty -> border_count); }
    {int tlv42; tlv42 = (int)(newCounty -> border_count); }
    {int tlv41; tlv41 = (int)(newCounty -> border_count); }
    {void * tlv22; tlv22 = (void *)(newCounty -> border_count); }
    {cgc_size_t tlv21; tlv21 = (cgc_size_t)(newCounty -> border_count); }
    {char tlv46; tlv46 = (char)(newCounty -> border_count); }
    {char * tlv78; tlv78 = (char *)(newCounty -> border_count); }
    {char * tlv54; tlv54 = (char *)(newCounty -> border_count); }
    {void * tlv49; tlv49 = (void *)(newCounty -> border_count); }
    {cgc_size_t tlv48; tlv48 = (cgc_size_t)(newCounty -> border_count); }
    {int * tlv50; tlv50 = (int *)(newCounty -> border_count); }
    {void * tlv53; tlv53 = (void *)(newCounty -> border_count); }
    {cgc_size_t tlv52; tlv52 = (cgc_size_t)(newCounty -> border_count); }
    {char * tlv79; tlv79 = (char *)(newCounty -> border_count); }
    {char * tlv80; tlv80 = (char *)(newCounty -> border_count); }
    {void * tlv57; tlv57 = (void *)(newCounty -> border_count); }
    {cgc_size_t tlv56; tlv56 = (cgc_size_t)(newCounty -> border_count); }
    {char * tlv60; tlv60 = (char *)(newCounty -> border_count); }
    {char * tlv59; tlv59 = (char *)(newCounty -> border_count); }
    {cgc_size_t tlv58; tlv58 = (cgc_size_t)(newCounty -> border_count); }
    {void * tlv62; tlv62 = (void *)(newCounty -> border_count); }
    {cgc_size_t tlv61; tlv61 = (cgc_size_t)(newCounty -> border_count); }
    {void * tlv64; tlv64 = (void *)(newCounty -> border_count); }
    {cgc_size_t tlv63; tlv63 = (cgc_size_t)(newCounty -> border_count); }
    {char * tlv67; tlv67 = (char *)(newCounty -> border_count); }
    {char * tlv66; tlv66 = (char *)(newCounty -> border_count); }
    {cgc_size_t tlv65; tlv65 = (cgc_size_t)(newCounty -> border_count); }
    {void * tlv69; tlv69 = (void *)(newCounty -> border_count); }
    {cgc_size_t tlv68; tlv68 = (cgc_size_t)(newCounty -> border_count); }
    {char * tlv81; tlv81 = (char *)(newCounty -> border_count); }
    {char * tlv82; tlv82 = (char *)(newCounty -> border_count); }
}
void fix_ingred_countyParsers_4_46(){
fix_ingred_countyParsers_4_46_0();
}
void fix_ingred_countyParsers_4_47_12(){
int tempInt;
    bzero(&tempInt,sizeof(int));
    {int startIndex; startIndex = (int)(tempInt); }
    {int endIndex; endIndex = (int)(tempInt); }
    {int lastGood; lastGood = (int)(tempInt); }
    {char * tempChar; tempChar = (char *)(tempInt); }
    {int tlv1; tlv1 = (int)(tempInt); }
    {int tlv2; tlv2 = (int)(tempInt); }
    {int tlv3; tlv3 = (int)(tempInt); }
    {int tlv4; tlv4 = (int)(tempInt); }
    {int tlv5; tlv5 = (int)(tempInt); }
    {int tlv6; tlv6 = (int)(tempInt); }
    {int tlv7; tlv7 = (int)(tempInt); }
    {int tlv8; tlv8 = (int)(tempInt); }
    {char tlv23; tlv23 = (char)(tempInt); }
    {int * tlv9; tlv9 = (int *)(tempInt); }
    {int tlv27; tlv27 = (int)(tempInt); }
    {int tlv26; tlv26 = (int)(tempInt); }
    {void * tlv12; tlv12 = (void *)(tempInt); }
    {cgc_size_t tlv11; tlv11 = (cgc_size_t)(tempInt); }
    {char tlv31; tlv31 = (char)(tempInt); }
    {cgc_size_t tlv35; tlv35 = (cgc_size_t)(tempInt); }
    {int tlv34; tlv34 = (int)(tempInt); }
    {char tlv37; tlv37 = (char)(tempInt); }
    {int tlv13; tlv13 = (int)(tempInt); }
    {char tlv39; tlv39 = (char)(tempInt); }
    {int tlv15; tlv15 = (int)(tempInt); }
    {int * tlv17; tlv17 = (int *)(tempInt); }
    {int * tlv19; tlv19 = (int *)(tempInt); }
    {int tlv42; tlv42 = (int)(tempInt); }
    {int tlv41; tlv41 = (int)(tempInt); }
    {void * tlv22; tlv22 = (void *)(tempInt); }
    {cgc_size_t tlv21; tlv21 = (cgc_size_t)(tempInt); }
    {char tlv46; tlv46 = (char)(tempInt); }
    {char * tlv78; tlv78 = (char *)(tempInt); }
    {char * tlv54; tlv54 = (char *)(tempInt); }
    {void * tlv49; tlv49 = (void *)(tempInt); }
    {cgc_size_t tlv48; tlv48 = (cgc_size_t)(tempInt); }
    {int * tlv50; tlv50 = (int *)(tempInt); }
    {void * tlv53; tlv53 = (void *)(tempInt); }
    {cgc_size_t tlv52; tlv52 = (cgc_size_t)(tempInt); }
    {char * tlv79; tlv79 = (char *)(tempInt); }
    {char * tlv80; tlv80 = (char *)(tempInt); }
    {void * tlv57; tlv57 = (void *)(tempInt); }
    {cgc_size_t tlv56; tlv56 = (cgc_size_t)(tempInt); }
    {char * tlv60; tlv60 = (char *)(tempInt); }
    {char * tlv59; tlv59 = (char *)(tempInt); }
    {cgc_size_t tlv58; tlv58 = (cgc_size_t)(tempInt); }
    {void * tlv62; tlv62 = (void *)(tempInt); }
    {cgc_size_t tlv61; tlv61 = (cgc_size_t)(tempInt); }
    {void * tlv64; tlv64 = (void *)(tempInt); }
    {cgc_size_t tlv63; tlv63 = (cgc_size_t)(tempInt); }
    {char * tlv67; tlv67 = (char *)(tempInt); }
    {char * tlv66; tlv66 = (char *)(tempInt); }
    {cgc_size_t tlv65; tlv65 = (cgc_size_t)(tempInt); }
    {void * tlv69; tlv69 = (void *)(tempInt); }
    {cgc_size_t tlv68; tlv68 = (cgc_size_t)(tempInt); }
    {char * tlv81; tlv81 = (char *)(tempInt); }
    {char * tlv82; tlv82 = (char *)(tempInt); }
}
void fix_ingred_countyParsers_4_47_13(){
int tempInt;
    bzero(&tempInt,sizeof(int));
    {int startIndex; startIndex = (int)(COUNTYBORDERMAX); }
    {int endIndex; endIndex = (int)(COUNTYBORDERMAX); }
    {int lastGood; lastGood = (int)(COUNTYBORDERMAX); }
    {int tempInt; tempInt = (int)(COUNTYBORDERMAX); }
    {char * tempChar; tempChar = (char *)(COUNTYBORDERMAX); }
    {int tlv1; tlv1 = (int)(COUNTYBORDERMAX); }
    {int tlv2; tlv2 = (int)(COUNTYBORDERMAX); }
    {int tlv3; tlv3 = (int)(COUNTYBORDERMAX); }
    {int tlv4; tlv4 = (int)(COUNTYBORDERMAX); }
    {int tlv5; tlv5 = (int)(COUNTYBORDERMAX); }
    {int tlv6; tlv6 = (int)(COUNTYBORDERMAX); }
    {int tlv7; tlv7 = (int)(COUNTYBORDERMAX); }
    {int tlv8; tlv8 = (int)(COUNTYBORDERMAX); }
    {char tlv23; tlv23 = (char)(COUNTYBORDERMAX); }
    {int * tlv9; tlv9 = (int *)(COUNTYBORDERMAX); }
    {int tlv27; tlv27 = (int)(COUNTYBORDERMAX); }
    {int tlv26; tlv26 = (int)(COUNTYBORDERMAX); }
    {void * tlv12; tlv12 = (void *)(COUNTYBORDERMAX); }
    {cgc_size_t tlv11; tlv11 = (cgc_size_t)(COUNTYBORDERMAX); }
    {char tlv31; tlv31 = (char)(COUNTYBORDERMAX); }
    {cgc_size_t tlv35; tlv35 = (cgc_size_t)(COUNTYBORDERMAX); }
    {int tlv34; tlv34 = (int)(COUNTYBORDERMAX); }
    {char tlv37; tlv37 = (char)(COUNTYBORDERMAX); }
    {int tlv13; tlv13 = (int)(COUNTYBORDERMAX); }
    {char tlv39; tlv39 = (char)(COUNTYBORDERMAX); }
    {int tlv15; tlv15 = (int)(COUNTYBORDERMAX); }
    {int * tlv17; tlv17 = (int *)(COUNTYBORDERMAX); }
    {int * tlv19; tlv19 = (int *)(COUNTYBORDERMAX); }
    {int tlv42; tlv42 = (int)(COUNTYBORDERMAX); }
    {int tlv41; tlv41 = (int)(COUNTYBORDERMAX); }
    {void * tlv22; tlv22 = (void *)(COUNTYBORDERMAX); }
    {cgc_size_t tlv21; tlv21 = (cgc_size_t)(COUNTYBORDERMAX); }
    {char tlv46; tlv46 = (char)(COUNTYBORDERMAX); }
    {char * tlv78; tlv78 = (char *)(COUNTYBORDERMAX); }
    {char * tlv54; tlv54 = (char *)(COUNTYBORDERMAX); }
    {void * tlv49; tlv49 = (void *)(COUNTYBORDERMAX); }
    {cgc_size_t tlv48; tlv48 = (cgc_size_t)(COUNTYBORDERMAX); }
    {int * tlv50; tlv50 = (int *)(COUNTYBORDERMAX); }
    {void * tlv53; tlv53 = (void *)(COUNTYBORDERMAX); }
    {cgc_size_t tlv52; tlv52 = (cgc_size_t)(COUNTYBORDERMAX); }
    {char * tlv79; tlv79 = (char *)(COUNTYBORDERMAX); }
    {char * tlv80; tlv80 = (char *)(COUNTYBORDERMAX); }
    {void * tlv57; tlv57 = (void *)(COUNTYBORDERMAX); }
    {cgc_size_t tlv56; tlv56 = (cgc_size_t)(COUNTYBORDERMAX); }
    {char * tlv60; tlv60 = (char *)(COUNTYBORDERMAX); }
    {char * tlv59; tlv59 = (char *)(COUNTYBORDERMAX); }
    {cgc_size_t tlv58; tlv58 = (cgc_size_t)(COUNTYBORDERMAX); }
    {void * tlv62; tlv62 = (void *)(COUNTYBORDERMAX); }
    {cgc_size_t tlv61; tlv61 = (cgc_size_t)(COUNTYBORDERMAX); }
    {void * tlv64; tlv64 = (void *)(COUNTYBORDERMAX); }
    {cgc_size_t tlv63; tlv63 = (cgc_size_t)(COUNTYBORDERMAX); }
    {char * tlv67; tlv67 = (char *)(COUNTYBORDERMAX); }
    {char * tlv66; tlv66 = (char *)(COUNTYBORDERMAX); }
    {cgc_size_t tlv65; tlv65 = (cgc_size_t)(COUNTYBORDERMAX); }
    {void * tlv69; tlv69 = (void *)(COUNTYBORDERMAX); }
    {cgc_size_t tlv68; tlv68 = (cgc_size_t)(COUNTYBORDERMAX); }
    {char * tlv81; tlv81 = (char *)(COUNTYBORDERMAX); }
    {char * tlv82; tlv82 = (char *)(COUNTYBORDERMAX); }
}
void fix_ingred_countyParsers_4_47(){
fix_ingred_countyParsers_4_47_12();
fix_ingred_countyParsers_4_47_13();
}
void fix_ingred_countyParsers_4_50_0(){
County newCounty_ref;
    bzero(&newCounty_ref,1*sizeof(County));
pCounty newCounty = &newCounty_ref;
    {int startIndex; startIndex = (int)(newCounty -> city_count); }
    {int endIndex; endIndex = (int)(newCounty -> city_count); }
    {int lastGood; lastGood = (int)(newCounty -> city_count); }
    {int tempInt; tempInt = (int)(newCounty -> city_count); }
    {char * tempChar; tempChar = (char *)(newCounty -> city_count); }
    {int tlv1; tlv1 = (int)(newCounty -> city_count); }
    {int tlv2; tlv2 = (int)(newCounty -> city_count); }
    {int tlv3; tlv3 = (int)(newCounty -> city_count); }
    {int tlv4; tlv4 = (int)(newCounty -> city_count); }
    {int tlv5; tlv5 = (int)(newCounty -> city_count); }
    {int tlv6; tlv6 = (int)(newCounty -> city_count); }
    {int tlv7; tlv7 = (int)(newCounty -> city_count); }
    {int tlv8; tlv8 = (int)(newCounty -> city_count); }
    {char tlv23; tlv23 = (char)(newCounty -> city_count); }
    {int * tlv9; tlv9 = (int *)(newCounty -> city_count); }
    {int tlv27; tlv27 = (int)(newCounty -> city_count); }
    {int tlv26; tlv26 = (int)(newCounty -> city_count); }
    {void * tlv12; tlv12 = (void *)(newCounty -> city_count); }
    {cgc_size_t tlv11; tlv11 = (cgc_size_t)(newCounty -> city_count); }
    {char tlv31; tlv31 = (char)(newCounty -> city_count); }
    {cgc_size_t tlv35; tlv35 = (cgc_size_t)(newCounty -> city_count); }
    {int tlv34; tlv34 = (int)(newCounty -> city_count); }
    {char tlv37; tlv37 = (char)(newCounty -> city_count); }
    {int tlv13; tlv13 = (int)(newCounty -> city_count); }
    {char tlv39; tlv39 = (char)(newCounty -> city_count); }
    {int tlv15; tlv15 = (int)(newCounty -> city_count); }
    {int * tlv17; tlv17 = (int *)(newCounty -> city_count); }
    {int * tlv19; tlv19 = (int *)(newCounty -> city_count); }
    {int tlv42; tlv42 = (int)(newCounty -> city_count); }
    {int tlv41; tlv41 = (int)(newCounty -> city_count); }
    {void * tlv22; tlv22 = (void *)(newCounty -> city_count); }
    {cgc_size_t tlv21; tlv21 = (cgc_size_t)(newCounty -> city_count); }
    {char tlv46; tlv46 = (char)(newCounty -> city_count); }
    {char * tlv78; tlv78 = (char *)(newCounty -> city_count); }
    {char * tlv54; tlv54 = (char *)(newCounty -> city_count); }
    {void * tlv49; tlv49 = (void *)(newCounty -> city_count); }
    {cgc_size_t tlv48; tlv48 = (cgc_size_t)(newCounty -> city_count); }
    {int * tlv50; tlv50 = (int *)(newCounty -> city_count); }
    {void * tlv53; tlv53 = (void *)(newCounty -> city_count); }
    {cgc_size_t tlv52; tlv52 = (cgc_size_t)(newCounty -> city_count); }
    {char * tlv79; tlv79 = (char *)(newCounty -> city_count); }
    {char * tlv80; tlv80 = (char *)(newCounty -> city_count); }
    {void * tlv57; tlv57 = (void *)(newCounty -> city_count); }
    {cgc_size_t tlv56; tlv56 = (cgc_size_t)(newCounty -> city_count); }
    {char * tlv60; tlv60 = (char *)(newCounty -> city_count); }
    {char * tlv59; tlv59 = (char *)(newCounty -> city_count); }
    {cgc_size_t tlv58; tlv58 = (cgc_size_t)(newCounty -> city_count); }
    {void * tlv62; tlv62 = (void *)(newCounty -> city_count); }
    {cgc_size_t tlv61; tlv61 = (cgc_size_t)(newCounty -> city_count); }
    {void * tlv64; tlv64 = (void *)(newCounty -> city_count); }
    {cgc_size_t tlv63; tlv63 = (cgc_size_t)(newCounty -> city_count); }
    {char * tlv67; tlv67 = (char *)(newCounty -> city_count); }
    {char * tlv66; tlv66 = (char *)(newCounty -> city_count); }
    {cgc_size_t tlv65; tlv65 = (cgc_size_t)(newCounty -> city_count); }
    {void * tlv69; tlv69 = (void *)(newCounty -> city_count); }
    {cgc_size_t tlv68; tlv68 = (cgc_size_t)(newCounty -> city_count); }
    {char * tlv81; tlv81 = (char *)(newCounty -> city_count); }
    {char * tlv82; tlv82 = (char *)(newCounty -> city_count); }
}
void fix_ingred_countyParsers_4_50(){
fix_ingred_countyParsers_4_50_0();
}
void fix_ingred_countyParsers_4_51_13(){
    {int startIndex; startIndex = (int)(COUNTYCITYMAX); }
    {int endIndex; endIndex = (int)(COUNTYCITYMAX); }
    {int lastGood; lastGood = (int)(COUNTYCITYMAX); }
    {int tempInt; tempInt = (int)(COUNTYCITYMAX); }
    {char * tempChar; tempChar = (char *)(COUNTYCITYMAX); }
    {int tlv4; tlv4 = (int)(COUNTYCITYMAX); }
    {int tlv5; tlv5 = (int)(COUNTYCITYMAX); }
    {int tlv6; tlv6 = (int)(COUNTYCITYMAX); }
    {int tlv7; tlv7 = (int)(COUNTYCITYMAX); }
    {int tlv8; tlv8 = (int)(COUNTYCITYMAX); }
    {char tlv23; tlv23 = (char)(COUNTYCITYMAX); }
    {int * tlv9; tlv9 = (int *)(COUNTYCITYMAX); }
    {int tlv27; tlv27 = (int)(COUNTYCITYMAX); }
    {int tlv26; tlv26 = (int)(COUNTYCITYMAX); }
    {void * tlv12; tlv12 = (void *)(COUNTYCITYMAX); }
    {cgc_size_t tlv11; tlv11 = (cgc_size_t)(COUNTYCITYMAX); }
    {char tlv31; tlv31 = (char)(COUNTYCITYMAX); }
    {cgc_size_t tlv35; tlv35 = (cgc_size_t)(COUNTYCITYMAX); }
    {int tlv34; tlv34 = (int)(COUNTYCITYMAX); }
    {char tlv37; tlv37 = (char)(COUNTYCITYMAX); }
    {int tlv13; tlv13 = (int)(COUNTYCITYMAX); }
    {int tlv15; tlv15 = (int)(COUNTYCITYMAX); }
    {int * tlv17; tlv17 = (int *)(COUNTYCITYMAX); }
    {int * tlv19; tlv19 = (int *)(COUNTYCITYMAX); }
    {int tlv42; tlv42 = (int)(COUNTYCITYMAX); }
    {int tlv41; tlv41 = (int)(COUNTYCITYMAX); }
    {void * tlv22; tlv22 = (void *)(COUNTYCITYMAX); }
    {cgc_size_t tlv21; tlv21 = (cgc_size_t)(COUNTYCITYMAX); }
    {char tlv46; tlv46 = (char)(COUNTYCITYMAX); }
    {char * tlv78; tlv78 = (char *)(COUNTYCITYMAX); }
    {char * tlv54; tlv54 = (char *)(COUNTYCITYMAX); }
    {int * tlv50; tlv50 = (int *)(COUNTYCITYMAX); }
    {void * tlv53; tlv53 = (void *)(COUNTYCITYMAX); }
    {cgc_size_t tlv52; tlv52 = (cgc_size_t)(COUNTYCITYMAX); }
    {char * tlv79; tlv79 = (char *)(COUNTYCITYMAX); }
    {char * tlv80; tlv80 = (char *)(COUNTYCITYMAX); }
    {void * tlv57; tlv57 = (void *)(COUNTYCITYMAX); }
    {char * tlv60; tlv60 = (char *)(COUNTYCITYMAX); }
    {char * tlv59; tlv59 = (char *)(COUNTYCITYMAX); }
    {cgc_size_t tlv58; tlv58 = (cgc_size_t)(COUNTYCITYMAX); }
    {void * tlv62; tlv62 = (void *)(COUNTYCITYMAX); }
    {cgc_size_t tlv61; tlv61 = (cgc_size_t)(COUNTYCITYMAX); }
    {void * tlv64; tlv64 = (void *)(COUNTYCITYMAX); }
    {cgc_size_t tlv63; tlv63 = (cgc_size_t)(COUNTYCITYMAX); }
    {char * tlv67; tlv67 = (char *)(COUNTYCITYMAX); }
    {char * tlv66; tlv66 = (char *)(COUNTYCITYMAX); }
    {cgc_size_t tlv65; tlv65 = (cgc_size_t)(COUNTYCITYMAX); }
    {void * tlv69; tlv69 = (void *)(COUNTYCITYMAX); }
    {cgc_size_t tlv68; tlv68 = (cgc_size_t)(COUNTYCITYMAX); }
    {char * tlv81; tlv81 = (char *)(COUNTYCITYMAX); }
    {char * tlv82; tlv82 = (char *)(COUNTYCITYMAX); }
}
void fix_ingred_countyParsers_4_51(){
fix_ingred_countyParsers_4_51_13();
}
void fix_ingred_countyParsers_4_56_1(){
int lastGood;
    bzero(&lastGood,sizeof(int));
    {int startIndex; startIndex = (int)(& lastGood); }
    {int endIndex; endIndex = (int)(& lastGood); }
    {int tempInt; tempInt = (int)(& lastGood); }
    {char * tempChar; tempChar = (char *)(& lastGood); }
    {int tlv1; tlv1 = (int)(& lastGood); }
    {int tlv2; tlv2 = (int)(& lastGood); }
    {int tlv3; tlv3 = (int)(& lastGood); }
    {int tlv4; tlv4 = (int)(& lastGood); }
    {int tlv5; tlv5 = (int)(& lastGood); }
    {int tlv6; tlv6 = (int)(& lastGood); }
    {int tlv7; tlv7 = (int)(& lastGood); }
    {int tlv8; tlv8 = (int)(& lastGood); }
    {char tlv23; tlv23 = (char)(& lastGood); }
    {int * tlv9; tlv9 = (int *)(& lastGood); }
    {int tlv27; tlv27 = (int)(& lastGood); }
    {int tlv26; tlv26 = (int)(& lastGood); }
    {void * tlv12; tlv12 = (void *)(& lastGood); }
    {cgc_size_t tlv11; tlv11 = (cgc_size_t)(& lastGood); }
    {char tlv31; tlv31 = (char)(& lastGood); }
    {cgc_size_t tlv35; tlv35 = (cgc_size_t)(& lastGood); }
    {int tlv34; tlv34 = (int)(& lastGood); }
    {char tlv37; tlv37 = (char)(& lastGood); }
    {int tlv13; tlv13 = (int)(& lastGood); }
    {char tlv39; tlv39 = (char)(& lastGood); }
    {int tlv15; tlv15 = (int)(& lastGood); }
    {int * tlv17; tlv17 = (int *)(& lastGood); }
    {int * tlv19; tlv19 = (int *)(& lastGood); }
    {int tlv42; tlv42 = (int)(& lastGood); }
    {int tlv41; tlv41 = (int)(& lastGood); }
    {void * tlv22; tlv22 = (void *)(& lastGood); }
    {cgc_size_t tlv21; tlv21 = (cgc_size_t)(& lastGood); }
    {char tlv46; tlv46 = (char)(& lastGood); }
    {char * tlv78; tlv78 = (char *)(& lastGood); }
    {char * tlv54; tlv54 = (char *)(& lastGood); }
    {void * tlv49; tlv49 = (void *)(& lastGood); }
    {cgc_size_t tlv48; tlv48 = (cgc_size_t)(& lastGood); }
    {int * tlv50; tlv50 = (int *)(& lastGood); }
    {void * tlv53; tlv53 = (void *)(& lastGood); }
    {cgc_size_t tlv52; tlv52 = (cgc_size_t)(& lastGood); }
    {char * tlv79; tlv79 = (char *)(& lastGood); }
    {char * tlv80; tlv80 = (char *)(& lastGood); }
    {void * tlv57; tlv57 = (void *)(& lastGood); }
    {cgc_size_t tlv56; tlv56 = (cgc_size_t)(& lastGood); }
    {char * tlv60; tlv60 = (char *)(& lastGood); }
    {char * tlv59; tlv59 = (char *)(& lastGood); }
    {cgc_size_t tlv58; tlv58 = (cgc_size_t)(& lastGood); }
    {void * tlv62; tlv62 = (void *)(& lastGood); }
    {cgc_size_t tlv61; tlv61 = (cgc_size_t)(& lastGood); }
    {void * tlv64; tlv64 = (void *)(& lastGood); }
    {cgc_size_t tlv63; tlv63 = (cgc_size_t)(& lastGood); }
    {char * tlv67; tlv67 = (char *)(& lastGood); }
    {char * tlv66; tlv66 = (char *)(& lastGood); }
    {cgc_size_t tlv65; tlv65 = (cgc_size_t)(& lastGood); }
    {void * tlv69; tlv69 = (void *)(& lastGood); }
    {cgc_size_t tlv68; tlv68 = (cgc_size_t)(& lastGood); }
    {char * tlv81; tlv81 = (char *)(& lastGood); }
    {char * tlv82; tlv82 = (char *)(& lastGood); }
}
void fix_ingred_countyParsers_4_56(){
fix_ingred_countyParsers_4_56_1();
}
void fix_ingred_countyParsers_4_60_1(){
    {int startIndex; startIndex = (int)(1); }
    {int endIndex; endIndex = (int)(1); }
    {int lastGood; lastGood = (int)(1); }
    {int tempInt; tempInt = (int)(1); }
    {char * tempChar; tempChar = (char *)(1); }
    {int tlv4; tlv4 = (int)(1); }
    {int tlv5; tlv5 = (int)(1); }
    {int tlv6; tlv6 = (int)(1); }
    {int tlv7; tlv7 = (int)(1); }
    {int tlv8; tlv8 = (int)(1); }
    {char tlv23; tlv23 = (char)(1); }
    {int * tlv9; tlv9 = (int *)(1); }
    {int tlv27; tlv27 = (int)(1); }
    {int tlv26; tlv26 = (int)(1); }
    {void * tlv12; tlv12 = (void *)(1); }
    {cgc_size_t tlv11; tlv11 = (cgc_size_t)(1); }
    {char tlv31; tlv31 = (char)(1); }
    {cgc_size_t tlv35; tlv35 = (cgc_size_t)(1); }
    {int tlv34; tlv34 = (int)(1); }
    {char tlv37; tlv37 = (char)(1); }
    {int tlv13; tlv13 = (int)(1); }
    {int tlv15; tlv15 = (int)(1); }
    {int * tlv17; tlv17 = (int *)(1); }
    {int * tlv19; tlv19 = (int *)(1); }
    {int tlv42; tlv42 = (int)(1); }
    {int tlv41; tlv41 = (int)(1); }
    {void * tlv22; tlv22 = (void *)(1); }
    {cgc_size_t tlv21; tlv21 = (cgc_size_t)(1); }
    {char tlv46; tlv46 = (char)(1); }
    {char * tlv78; tlv78 = (char *)(1); }
    {char * tlv54; tlv54 = (char *)(1); }
    {int * tlv50; tlv50 = (int *)(1); }
    {void * tlv53; tlv53 = (void *)(1); }
    {cgc_size_t tlv52; tlv52 = (cgc_size_t)(1); }
    {char * tlv79; tlv79 = (char *)(1); }
    {char * tlv80; tlv80 = (char *)(1); }
    {void * tlv57; tlv57 = (void *)(1); }
    {char * tlv60; tlv60 = (char *)(1); }
    {char * tlv59; tlv59 = (char *)(1); }
    {cgc_size_t tlv58; tlv58 = (cgc_size_t)(1); }
    {void * tlv62; tlv62 = (void *)(1); }
    {cgc_size_t tlv61; tlv61 = (cgc_size_t)(1); }
    {void * tlv64; tlv64 = (void *)(1); }
    {cgc_size_t tlv63; tlv63 = (cgc_size_t)(1); }
    {char * tlv67; tlv67 = (char *)(1); }
    {char * tlv66; tlv66 = (char *)(1); }
    {cgc_size_t tlv65; tlv65 = (cgc_size_t)(1); }
    {void * tlv69; tlv69 = (void *)(1); }
    {cgc_size_t tlv68; tlv68 = (cgc_size_t)(1); }
    {char * tlv81; tlv81 = (char *)(1); }
    {char * tlv82; tlv82 = (char *)(1); }
}
void fix_ingred_countyParsers_4_60(){
fix_ingred_countyParsers_4_60_1();
}
void fix_ingred_countyParsers_4_61_1(){
    {int startIndex; startIndex = (int)('#'); }
    {int endIndex; endIndex = (int)('#'); }
    {int lastGood; lastGood = (int)('#'); }
    {int tempInt; tempInt = (int)('#'); }
    {char * tempChar; tempChar = (char *)('#'); }
    {int tlv1; tlv1 = (int)('#'); }
    {int tlv2; tlv2 = (int)('#'); }
    {int tlv3; tlv3 = (int)('#'); }
    {int tlv4; tlv4 = (int)('#'); }
    {int tlv5; tlv5 = (int)('#'); }
    {int tlv6; tlv6 = (int)('#'); }
    {int tlv7; tlv7 = (int)('#'); }
    {int tlv8; tlv8 = (int)('#'); }
    {char tlv23; tlv23 = (char)('#'); }
    {int * tlv9; tlv9 = (int *)('#'); }
    {int tlv27; tlv27 = (int)('#'); }
    {int tlv26; tlv26 = (int)('#'); }
    {void * tlv12; tlv12 = (void *)('#'); }
    {cgc_size_t tlv11; tlv11 = (cgc_size_t)('#'); }
    {char tlv31; tlv31 = (char)('#'); }
    {cgc_size_t tlv35; tlv35 = (cgc_size_t)('#'); }
    {int tlv34; tlv34 = (int)('#'); }
    {char tlv37; tlv37 = (char)('#'); }
    {int tlv13; tlv13 = (int)('#'); }
    {char tlv39; tlv39 = (char)('#'); }
    {int tlv15; tlv15 = (int)('#'); }
    {int * tlv17; tlv17 = (int *)('#'); }
    {int * tlv19; tlv19 = (int *)('#'); }
    {int tlv42; tlv42 = (int)('#'); }
    {int tlv41; tlv41 = (int)('#'); }
    {void * tlv22; tlv22 = (void *)('#'); }
    {cgc_size_t tlv21; tlv21 = (cgc_size_t)('#'); }
    {char tlv46; tlv46 = (char)('#'); }
    {char * tlv78; tlv78 = (char *)('#'); }
    {char * tlv54; tlv54 = (char *)('#'); }
    {void * tlv49; tlv49 = (void *)('#'); }
    {cgc_size_t tlv48; tlv48 = (cgc_size_t)('#'); }
    {int * tlv50; tlv50 = (int *)('#'); }
    {void * tlv53; tlv53 = (void *)('#'); }
    {cgc_size_t tlv52; tlv52 = (cgc_size_t)('#'); }
    {char * tlv79; tlv79 = (char *)('#'); }
    {char * tlv80; tlv80 = (char *)('#'); }
    {void * tlv57; tlv57 = (void *)('#'); }
    {cgc_size_t tlv56; tlv56 = (cgc_size_t)('#'); }
    {char * tlv60; tlv60 = (char *)('#'); }
    {char * tlv59; tlv59 = (char *)('#'); }
    {cgc_size_t tlv58; tlv58 = (cgc_size_t)('#'); }
    {void * tlv62; tlv62 = (void *)('#'); }
    {cgc_size_t tlv61; tlv61 = (cgc_size_t)('#'); }
    {void * tlv64; tlv64 = (void *)('#'); }
    {cgc_size_t tlv63; tlv63 = (cgc_size_t)('#'); }
    {char * tlv67; tlv67 = (char *)('#'); }
    {char * tlv66; tlv66 = (char *)('#'); }
    {cgc_size_t tlv65; tlv65 = (cgc_size_t)('#'); }
    {void * tlv69; tlv69 = (void *)('#'); }
    {cgc_size_t tlv68; tlv68 = (cgc_size_t)('#'); }
    {char * tlv81; tlv81 = (char *)('#'); }
    {char * tlv82; tlv82 = (char *)('#'); }
}
void fix_ingred_countyParsers_4_61(){
fix_ingred_countyParsers_4_61_1();
}
void fix_ingred_countyParsers_4_65_1(){
int endIndex;
    bzero(&endIndex,sizeof(int));
    {int startIndex; startIndex = (int)(& endIndex); }
    {int lastGood; lastGood = (int)(& endIndex); }
    {int tempInt; tempInt = (int)(& endIndex); }
    {char * tempChar; tempChar = (char *)(& endIndex); }
    {int tlv1; tlv1 = (int)(& endIndex); }
    {int tlv2; tlv2 = (int)(& endIndex); }
    {int tlv3; tlv3 = (int)(& endIndex); }
    {int tlv4; tlv4 = (int)(& endIndex); }
    {int tlv5; tlv5 = (int)(& endIndex); }
    {int tlv6; tlv6 = (int)(& endIndex); }
    {int tlv7; tlv7 = (int)(& endIndex); }
    {int tlv8; tlv8 = (int)(& endIndex); }
    {char tlv23; tlv23 = (char)(& endIndex); }
    {int * tlv9; tlv9 = (int *)(& endIndex); }
    {int tlv27; tlv27 = (int)(& endIndex); }
    {int tlv26; tlv26 = (int)(& endIndex); }
    {void * tlv12; tlv12 = (void *)(& endIndex); }
    {cgc_size_t tlv11; tlv11 = (cgc_size_t)(& endIndex); }
    {char tlv31; tlv31 = (char)(& endIndex); }
    {cgc_size_t tlv35; tlv35 = (cgc_size_t)(& endIndex); }
    {int tlv34; tlv34 = (int)(& endIndex); }
    {char tlv37; tlv37 = (char)(& endIndex); }
    {int tlv13; tlv13 = (int)(& endIndex); }
    {char tlv39; tlv39 = (char)(& endIndex); }
    {int tlv15; tlv15 = (int)(& endIndex); }
    {int * tlv17; tlv17 = (int *)(& endIndex); }
    {int * tlv19; tlv19 = (int *)(& endIndex); }
    {int tlv42; tlv42 = (int)(& endIndex); }
    {int tlv41; tlv41 = (int)(& endIndex); }
    {void * tlv22; tlv22 = (void *)(& endIndex); }
    {cgc_size_t tlv21; tlv21 = (cgc_size_t)(& endIndex); }
    {char tlv46; tlv46 = (char)(& endIndex); }
    {char * tlv78; tlv78 = (char *)(& endIndex); }
    {char * tlv54; tlv54 = (char *)(& endIndex); }
    {void * tlv49; tlv49 = (void *)(& endIndex); }
    {cgc_size_t tlv48; tlv48 = (cgc_size_t)(& endIndex); }
    {int * tlv50; tlv50 = (int *)(& endIndex); }
    {void * tlv53; tlv53 = (void *)(& endIndex); }
    {cgc_size_t tlv52; tlv52 = (cgc_size_t)(& endIndex); }
    {char * tlv79; tlv79 = (char *)(& endIndex); }
    {char * tlv80; tlv80 = (char *)(& endIndex); }
    {void * tlv57; tlv57 = (void *)(& endIndex); }
    {cgc_size_t tlv56; tlv56 = (cgc_size_t)(& endIndex); }
    {char * tlv60; tlv60 = (char *)(& endIndex); }
    {char * tlv59; tlv59 = (char *)(& endIndex); }
    {cgc_size_t tlv58; tlv58 = (cgc_size_t)(& endIndex); }
    {void * tlv62; tlv62 = (void *)(& endIndex); }
    {cgc_size_t tlv61; tlv61 = (cgc_size_t)(& endIndex); }
    {void * tlv64; tlv64 = (void *)(& endIndex); }
    {cgc_size_t tlv63; tlv63 = (cgc_size_t)(& endIndex); }
    {char * tlv67; tlv67 = (char *)(& endIndex); }
    {char * tlv66; tlv66 = (char *)(& endIndex); }
    {cgc_size_t tlv65; tlv65 = (cgc_size_t)(& endIndex); }
    {void * tlv69; tlv69 = (void *)(& endIndex); }
    {cgc_size_t tlv68; tlv68 = (cgc_size_t)(& endIndex); }
    {char * tlv81; tlv81 = (char *)(& endIndex); }
    {char * tlv82; tlv82 = (char *)(& endIndex); }
}
void fix_ingred_countyParsers_4_65(){
fix_ingred_countyParsers_4_65_1();
}
void fix_ingred_countyParsers_4_71_8(){
int tlv7;
    bzero(&tlv7,sizeof(int));
    {int startIndex; startIndex = (int)(tlv7); }
    {int endIndex; endIndex = (int)(tlv7); }
    {int lastGood; lastGood = (int)(tlv7); }
    {int tempInt; tempInt = (int)(tlv7); }
    {char * tempChar; tempChar = (char *)(tlv7); }
    {int tlv1; tlv1 = (int)(tlv7); }
    {int tlv2; tlv2 = (int)(tlv7); }
    {int tlv3; tlv3 = (int)(tlv7); }
    {int tlv4; tlv4 = (int)(tlv7); }
    {int tlv5; tlv5 = (int)(tlv7); }
    {int tlv6; tlv6 = (int)(tlv7); }
    {int tlv8; tlv8 = (int)(tlv7); }
    {char tlv23; tlv23 = (char)(tlv7); }
    {int * tlv9; tlv9 = (int *)(tlv7); }
    {int tlv27; tlv27 = (int)(tlv7); }
    {int tlv26; tlv26 = (int)(tlv7); }
    {void * tlv12; tlv12 = (void *)(tlv7); }
    {cgc_size_t tlv11; tlv11 = (cgc_size_t)(tlv7); }
    {char tlv31; tlv31 = (char)(tlv7); }
    {cgc_size_t tlv35; tlv35 = (cgc_size_t)(tlv7); }
    {int tlv34; tlv34 = (int)(tlv7); }
    {char tlv37; tlv37 = (char)(tlv7); }
    {int tlv13; tlv13 = (int)(tlv7); }
    {char tlv39; tlv39 = (char)(tlv7); }
    {int tlv15; tlv15 = (int)(tlv7); }
    {int * tlv17; tlv17 = (int *)(tlv7); }
    {int * tlv19; tlv19 = (int *)(tlv7); }
    {int tlv42; tlv42 = (int)(tlv7); }
    {int tlv41; tlv41 = (int)(tlv7); }
    {void * tlv22; tlv22 = (void *)(tlv7); }
    {cgc_size_t tlv21; tlv21 = (cgc_size_t)(tlv7); }
    {char tlv46; tlv46 = (char)(tlv7); }
    {char * tlv78; tlv78 = (char *)(tlv7); }
    {char * tlv54; tlv54 = (char *)(tlv7); }
    {void * tlv49; tlv49 = (void *)(tlv7); }
    {cgc_size_t tlv48; tlv48 = (cgc_size_t)(tlv7); }
    {int * tlv50; tlv50 = (int *)(tlv7); }
    {void * tlv53; tlv53 = (void *)(tlv7); }
    {cgc_size_t tlv52; tlv52 = (cgc_size_t)(tlv7); }
    {char * tlv79; tlv79 = (char *)(tlv7); }
    {char * tlv80; tlv80 = (char *)(tlv7); }
    {void * tlv57; tlv57 = (void *)(tlv7); }
    {cgc_size_t tlv56; tlv56 = (cgc_size_t)(tlv7); }
    {char * tlv60; tlv60 = (char *)(tlv7); }
    {char * tlv59; tlv59 = (char *)(tlv7); }
    {cgc_size_t tlv58; tlv58 = (cgc_size_t)(tlv7); }
    {void * tlv62; tlv62 = (void *)(tlv7); }
    {cgc_size_t tlv61; tlv61 = (cgc_size_t)(tlv7); }
    {void * tlv64; tlv64 = (void *)(tlv7); }
    {cgc_size_t tlv63; tlv63 = (cgc_size_t)(tlv7); }
    {char * tlv67; tlv67 = (char *)(tlv7); }
    {char * tlv66; tlv66 = (char *)(tlv7); }
    {cgc_size_t tlv65; tlv65 = (cgc_size_t)(tlv7); }
    {void * tlv69; tlv69 = (void *)(tlv7); }
    {cgc_size_t tlv68; tlv68 = (cgc_size_t)(tlv7); }
    {char * tlv81; tlv81 = (char *)(tlv7); }
    {char * tlv82; tlv82 = (char *)(tlv7); }
}
void fix_ingred_countyParsers_4_71(){
fix_ingred_countyParsers_4_71_8();
}
void fix_ingred_countyParsers_4_73_1(){
char tlv80_ref;
    bzero(&tlv80_ref,1*sizeof(char));
char * tlv80 = &tlv80_ref;
    {int startIndex; startIndex = (int)(cgc_strlen ( tlv80 ) + 1); }
    {int endIndex; endIndex = (int)(cgc_strlen ( tlv80 ) + 1); }
    {int lastGood; lastGood = (int)(cgc_strlen ( tlv80 ) + 1); }
    {int tempInt; tempInt = (int)(cgc_strlen ( tlv80 ) + 1); }
    {char * tempChar; tempChar = (char *)(cgc_strlen ( tlv80 ) + 1); }
    {int tlv1; tlv1 = (int)(cgc_strlen ( tlv80 ) + 1); }
    {int tlv2; tlv2 = (int)(cgc_strlen ( tlv80 ) + 1); }
    {int tlv3; tlv3 = (int)(cgc_strlen ( tlv80 ) + 1); }
    {int tlv4; tlv4 = (int)(cgc_strlen ( tlv80 ) + 1); }
    {int tlv5; tlv5 = (int)(cgc_strlen ( tlv80 ) + 1); }
    {int tlv6; tlv6 = (int)(cgc_strlen ( tlv80 ) + 1); }
    {int tlv7; tlv7 = (int)(cgc_strlen ( tlv80 ) + 1); }
    {int tlv8; tlv8 = (int)(cgc_strlen ( tlv80 ) + 1); }
    {char tlv23; tlv23 = (char)(cgc_strlen ( tlv80 ) + 1); }
    {int * tlv9; tlv9 = (int *)(cgc_strlen ( tlv80 ) + 1); }
    {int tlv27; tlv27 = (int)(cgc_strlen ( tlv80 ) + 1); }
    {int tlv26; tlv26 = (int)(cgc_strlen ( tlv80 ) + 1); }
    {void * tlv12; tlv12 = (void *)(cgc_strlen ( tlv80 ) + 1); }
    {cgc_size_t tlv11; tlv11 = (cgc_size_t)(cgc_strlen ( tlv80 ) + 1); }
    {char tlv31; tlv31 = (char)(cgc_strlen ( tlv80 ) + 1); }
    {cgc_size_t tlv35; tlv35 = (cgc_size_t)(cgc_strlen ( tlv80 ) + 1); }
    {int tlv34; tlv34 = (int)(cgc_strlen ( tlv80 ) + 1); }
    {char tlv37; tlv37 = (char)(cgc_strlen ( tlv80 ) + 1); }
    {int tlv13; tlv13 = (int)(cgc_strlen ( tlv80 ) + 1); }
    {char tlv39; tlv39 = (char)(cgc_strlen ( tlv80 ) + 1); }
    {int tlv15; tlv15 = (int)(cgc_strlen ( tlv80 ) + 1); }
    {int * tlv17; tlv17 = (int *)(cgc_strlen ( tlv80 ) + 1); }
    {int * tlv19; tlv19 = (int *)(cgc_strlen ( tlv80 ) + 1); }
    {int tlv42; tlv42 = (int)(cgc_strlen ( tlv80 ) + 1); }
    {int tlv41; tlv41 = (int)(cgc_strlen ( tlv80 ) + 1); }
    {void * tlv22; tlv22 = (void *)(cgc_strlen ( tlv80 ) + 1); }
    {cgc_size_t tlv21; tlv21 = (cgc_size_t)(cgc_strlen ( tlv80 ) + 1); }
    {char tlv46; tlv46 = (char)(cgc_strlen ( tlv80 ) + 1); }
    {char * tlv78; tlv78 = (char *)(cgc_strlen ( tlv80 ) + 1); }
    {char * tlv54; tlv54 = (char *)(cgc_strlen ( tlv80 ) + 1); }
    {void * tlv49; tlv49 = (void *)(cgc_strlen ( tlv80 ) + 1); }
    {cgc_size_t tlv48; tlv48 = (cgc_size_t)(cgc_strlen ( tlv80 ) + 1); }
    {int * tlv50; tlv50 = (int *)(cgc_strlen ( tlv80 ) + 1); }
    {void * tlv53; tlv53 = (void *)(cgc_strlen ( tlv80 ) + 1); }
    {cgc_size_t tlv52; tlv52 = (cgc_size_t)(cgc_strlen ( tlv80 ) + 1); }
    {char * tlv79; tlv79 = (char *)(cgc_strlen ( tlv80 ) + 1); }
    {void * tlv57; tlv57 = (void *)(cgc_strlen ( tlv80 ) + 1); }
    {cgc_size_t tlv56; tlv56 = (cgc_size_t)(cgc_strlen ( tlv80 ) + 1); }
    {char * tlv60; tlv60 = (char *)(cgc_strlen ( tlv80 ) + 1); }
    {char * tlv59; tlv59 = (char *)(cgc_strlen ( tlv80 ) + 1); }
    {cgc_size_t tlv58; tlv58 = (cgc_size_t)(cgc_strlen ( tlv80 ) + 1); }
    {void * tlv62; tlv62 = (void *)(cgc_strlen ( tlv80 ) + 1); }
    {cgc_size_t tlv61; tlv61 = (cgc_size_t)(cgc_strlen ( tlv80 ) + 1); }
    {void * tlv64; tlv64 = (void *)(cgc_strlen ( tlv80 ) + 1); }
    {cgc_size_t tlv63; tlv63 = (cgc_size_t)(cgc_strlen ( tlv80 ) + 1); }
    {char * tlv67; tlv67 = (char *)(cgc_strlen ( tlv80 ) + 1); }
    {char * tlv66; tlv66 = (char *)(cgc_strlen ( tlv80 ) + 1); }
    {cgc_size_t tlv65; tlv65 = (cgc_size_t)(cgc_strlen ( tlv80 ) + 1); }
    {void * tlv69; tlv69 = (void *)(cgc_strlen ( tlv80 ) + 1); }
    {cgc_size_t tlv68; tlv68 = (cgc_size_t)(cgc_strlen ( tlv80 ) + 1); }
    {char * tlv81; tlv81 = (char *)(cgc_strlen ( tlv80 ) + 1); }
    {char * tlv82; tlv82 = (char *)(cgc_strlen ( tlv80 ) + 1); }
}
void fix_ingred_countyParsers_4_73(){
fix_ingred_countyParsers_4_73_1();
}
void fix_ingred_countyParsers_4_75_1(){
char tlv78_ref;
    bzero(&tlv78_ref,1*sizeof(char));
char * tlv78 = &tlv78_ref;
    {int startIndex; startIndex = (int)(cgc_strlen ( tlv78 ) + 1); }
    {int endIndex; endIndex = (int)(cgc_strlen ( tlv78 ) + 1); }
    {int lastGood; lastGood = (int)(cgc_strlen ( tlv78 ) + 1); }
    {int tempInt; tempInt = (int)(cgc_strlen ( tlv78 ) + 1); }
    {char * tempChar; tempChar = (char *)(cgc_strlen ( tlv78 ) + 1); }
    {int tlv1; tlv1 = (int)(cgc_strlen ( tlv78 ) + 1); }
    {int tlv2; tlv2 = (int)(cgc_strlen ( tlv78 ) + 1); }
    {int tlv3; tlv3 = (int)(cgc_strlen ( tlv78 ) + 1); }
    {int tlv4; tlv4 = (int)(cgc_strlen ( tlv78 ) + 1); }
    {int tlv5; tlv5 = (int)(cgc_strlen ( tlv78 ) + 1); }
    {int tlv6; tlv6 = (int)(cgc_strlen ( tlv78 ) + 1); }
    {int tlv7; tlv7 = (int)(cgc_strlen ( tlv78 ) + 1); }
    {int tlv8; tlv8 = (int)(cgc_strlen ( tlv78 ) + 1); }
    {char tlv23; tlv23 = (char)(cgc_strlen ( tlv78 ) + 1); }
    {int * tlv9; tlv9 = (int *)(cgc_strlen ( tlv78 ) + 1); }
    {int tlv27; tlv27 = (int)(cgc_strlen ( tlv78 ) + 1); }
    {int tlv26; tlv26 = (int)(cgc_strlen ( tlv78 ) + 1); }
    {void * tlv12; tlv12 = (void *)(cgc_strlen ( tlv78 ) + 1); }
    {cgc_size_t tlv11; tlv11 = (cgc_size_t)(cgc_strlen ( tlv78 ) + 1); }
    {char tlv31; tlv31 = (char)(cgc_strlen ( tlv78 ) + 1); }
    {cgc_size_t tlv35; tlv35 = (cgc_size_t)(cgc_strlen ( tlv78 ) + 1); }
    {int tlv34; tlv34 = (int)(cgc_strlen ( tlv78 ) + 1); }
    {char tlv37; tlv37 = (char)(cgc_strlen ( tlv78 ) + 1); }
    {int tlv13; tlv13 = (int)(cgc_strlen ( tlv78 ) + 1); }
    {char tlv39; tlv39 = (char)(cgc_strlen ( tlv78 ) + 1); }
    {int tlv15; tlv15 = (int)(cgc_strlen ( tlv78 ) + 1); }
    {int * tlv17; tlv17 = (int *)(cgc_strlen ( tlv78 ) + 1); }
    {int * tlv19; tlv19 = (int *)(cgc_strlen ( tlv78 ) + 1); }
    {int tlv42; tlv42 = (int)(cgc_strlen ( tlv78 ) + 1); }
    {int tlv41; tlv41 = (int)(cgc_strlen ( tlv78 ) + 1); }
    {void * tlv22; tlv22 = (void *)(cgc_strlen ( tlv78 ) + 1); }
    {cgc_size_t tlv21; tlv21 = (cgc_size_t)(cgc_strlen ( tlv78 ) + 1); }
    {char tlv46; tlv46 = (char)(cgc_strlen ( tlv78 ) + 1); }
    {char * tlv54; tlv54 = (char *)(cgc_strlen ( tlv78 ) + 1); }
    {void * tlv49; tlv49 = (void *)(cgc_strlen ( tlv78 ) + 1); }
    {cgc_size_t tlv48; tlv48 = (cgc_size_t)(cgc_strlen ( tlv78 ) + 1); }
    {int * tlv50; tlv50 = (int *)(cgc_strlen ( tlv78 ) + 1); }
    {void * tlv53; tlv53 = (void *)(cgc_strlen ( tlv78 ) + 1); }
    {cgc_size_t tlv52; tlv52 = (cgc_size_t)(cgc_strlen ( tlv78 ) + 1); }
    {char * tlv79; tlv79 = (char *)(cgc_strlen ( tlv78 ) + 1); }
    {char * tlv80; tlv80 = (char *)(cgc_strlen ( tlv78 ) + 1); }
    {void * tlv57; tlv57 = (void *)(cgc_strlen ( tlv78 ) + 1); }
    {cgc_size_t tlv56; tlv56 = (cgc_size_t)(cgc_strlen ( tlv78 ) + 1); }
    {char * tlv60; tlv60 = (char *)(cgc_strlen ( tlv78 ) + 1); }
    {char * tlv59; tlv59 = (char *)(cgc_strlen ( tlv78 ) + 1); }
    {cgc_size_t tlv58; tlv58 = (cgc_size_t)(cgc_strlen ( tlv78 ) + 1); }
    {void * tlv62; tlv62 = (void *)(cgc_strlen ( tlv78 ) + 1); }
    {cgc_size_t tlv61; tlv61 = (cgc_size_t)(cgc_strlen ( tlv78 ) + 1); }
    {void * tlv64; tlv64 = (void *)(cgc_strlen ( tlv78 ) + 1); }
    {cgc_size_t tlv63; tlv63 = (cgc_size_t)(cgc_strlen ( tlv78 ) + 1); }
    {char * tlv67; tlv67 = (char *)(cgc_strlen ( tlv78 ) + 1); }
    {char * tlv66; tlv66 = (char *)(cgc_strlen ( tlv78 ) + 1); }
    {cgc_size_t tlv65; tlv65 = (cgc_size_t)(cgc_strlen ( tlv78 ) + 1); }
    {void * tlv69; tlv69 = (void *)(cgc_strlen ( tlv78 ) + 1); }
    {cgc_size_t tlv68; tlv68 = (cgc_size_t)(cgc_strlen ( tlv78 ) + 1); }
    {char * tlv81; tlv81 = (char *)(cgc_strlen ( tlv78 ) + 1); }
    {char * tlv82; tlv82 = (char *)(cgc_strlen ( tlv78 ) + 1); }
}
void fix_ingred_countyParsers_4_75(){
fix_ingred_countyParsers_4_75_1();
}
void fix_ingred_countyParsers_4(){
fix_ingred_countyParsers_4_0();
fix_ingred_countyParsers_4_2();
fix_ingred_countyParsers_4_4();
fix_ingred_countyParsers_4_6();
fix_ingred_countyParsers_4_7();
fix_ingred_countyParsers_4_9();
fix_ingred_countyParsers_4_11();
fix_ingred_countyParsers_4_12();
fix_ingred_countyParsers_4_13();
fix_ingred_countyParsers_4_15();
fix_ingred_countyParsers_4_16();
fix_ingred_countyParsers_4_21();
fix_ingred_countyParsers_4_26();
fix_ingred_countyParsers_4_27();
fix_ingred_countyParsers_4_29();
fix_ingred_countyParsers_4_33();
fix_ingred_countyParsers_4_34();
fix_ingred_countyParsers_4_36();
fix_ingred_countyParsers_4_46();
fix_ingred_countyParsers_4_47();
fix_ingred_countyParsers_4_50();
fix_ingred_countyParsers_4_51();
fix_ingred_countyParsers_4_56();
fix_ingred_countyParsers_4_60();
fix_ingred_countyParsers_4_61();
fix_ingred_countyParsers_4_65();
fix_ingred_countyParsers_4_71();
fix_ingred_countyParsers_4_73();
fix_ingred_countyParsers_4_75();
}
void fix_ingred_countyParsers_5_0_0(){
    {int retval; retval = (int)(0); }
    {char * temp; temp = (char *)(0); }
    {char tlv6; tlv6 = (char)(0); }
    {int tlv11; tlv11 = (int)(0); }
    {int tlv10; tlv10 = (int)(0); }
    {char tlv17; tlv17 = (char)(0); }
    {char * tlv20; tlv20 = (char *)(0); }
}
void fix_ingred_countyParsers_5_0_3(){
    {int retval; retval = (int)(NULL); }
    {char * temp; temp = (char *)(NULL); }
    {char tlv6; tlv6 = (char)(NULL); }
    {int tlv11; tlv11 = (int)(NULL); }
    {int tlv10; tlv10 = (int)(NULL); }
    {void * tlv5; tlv5 = (void *)(NULL); }
    {cgc_size_t tlv4; tlv4 = (cgc_size_t)(NULL); }
    {char * tlv19; tlv19 = (char *)(NULL); }
    {char tlv17; tlv17 = (char)(NULL); }
    {void * tlv16; tlv16 = (void *)(NULL); }
    {cgc_size_t tlv15; tlv15 = (cgc_size_t)(NULL); }
    {char * tlv20; tlv20 = (char *)(NULL); }
}
void fix_ingred_countyParsers_5_0_4(){
    {int retval; retval = (int)(1); }
    {char * temp; temp = (char *)(1); }
    {char tlv6; tlv6 = (char)(1); }
    {int tlv11; tlv11 = (int)(1); }
    {int tlv10; tlv10 = (int)(1); }
    {void * tlv5; tlv5 = (void *)(1); }
    {cgc_size_t tlv4; tlv4 = (cgc_size_t)(1); }
    {char tlv17; tlv17 = (char)(1); }
    {char * tlv20; tlv20 = (char *)(1); }
}
void fix_ingred_countyParsers_5_0(){
fix_ingred_countyParsers_5_0_0();
fix_ingred_countyParsers_5_0_3();
fix_ingred_countyParsers_5_0_4();
}
void fix_ingred_countyParsers_5_2_1(){
    {int retval; retval = (int)('{'); }
    {char * temp; temp = (char *)('{'); }
    {char tlv6; tlv6 = (char)('{'); }
    {int tlv11; tlv11 = (int)('{'); }
    {int tlv10; tlv10 = (int)('{'); }
    {void * tlv5; tlv5 = (void *)('{'); }
    {cgc_size_t tlv4; tlv4 = (cgc_size_t)('{'); }
    {char * tlv19; tlv19 = (char *)('{'); }
    {char tlv17; tlv17 = (char)('{'); }
    {void * tlv16; tlv16 = (void *)('{'); }
    {cgc_size_t tlv15; tlv15 = (cgc_size_t)('{'); }
    {char * tlv20; tlv20 = (char *)('{'); }
}
void fix_ingred_countyParsers_5_2(){
fix_ingred_countyParsers_5_2_1();
}
void fix_ingred_countyParsers_5_4_4(){
int ending;
    bzero(&ending,sizeof(int));
    {int retval; retval = (int)(ending); }
    {int startIndex; startIndex = (int)(ending); }
    {int endIndex; endIndex = (int)(ending); }
    {char * temp; temp = (char *)(ending); }
    {int tlv1; tlv1 = (int)(ending); }
    {int tlv2; tlv2 = (int)(ending); }
    {char tlv6; tlv6 = (char)(ending); }
    {int tlv11; tlv11 = (int)(ending); }
    {int tlv10; tlv10 = (int)(ending); }
    {void * tlv5; tlv5 = (void *)(ending); }
    {cgc_size_t tlv4; tlv4 = (cgc_size_t)(ending); }
    {int tlv3; tlv3 = (int)(ending); }
    {char * tlv19; tlv19 = (char *)(ending); }
    {char tlv17; tlv17 = (char)(ending); }
    {void * tlv16; tlv16 = (void *)(ending); }
    {cgc_size_t tlv15; tlv15 = (cgc_size_t)(ending); }
    {char * tlv20; tlv20 = (char *)(ending); }
}
void fix_ingred_countyParsers_5_4(){
fix_ingred_countyParsers_5_4_4();
}
void fix_ingred_countyParsers_5_5_1(){
    {int retval; retval = (int)('#'); }
    {char * temp; temp = (char *)('#'); }
    {char tlv6; tlv6 = (char)('#'); }
    {int tlv11; tlv11 = (int)('#'); }
    {int tlv10; tlv10 = (int)('#'); }
    {void * tlv5; tlv5 = (void *)('#'); }
    {cgc_size_t tlv4; tlv4 = (cgc_size_t)('#'); }
    {char * tlv19; tlv19 = (char *)('#'); }
    {char tlv17; tlv17 = (char)('#'); }
    {void * tlv16; tlv16 = (void *)('#'); }
    {cgc_size_t tlv15; tlv15 = (cgc_size_t)('#'); }
    {char * tlv20; tlv20 = (char *)('#'); }
}
void fix_ingred_countyParsers_5_5(){
fix_ingred_countyParsers_5_5_1();
}
void fix_ingred_countyParsers_5_9_4(){
int endIndex;
    bzero(&endIndex,sizeof(int));
    {int retval; retval = (int)(endIndex); }
    {char * temp; temp = (char *)(endIndex); }
    {char tlv6; tlv6 = (char)(endIndex); }
    {int tlv11; tlv11 = (int)(endIndex); }
    {int tlv10; tlv10 = (int)(endIndex); }
    {void * tlv5; tlv5 = (void *)(endIndex); }
    {cgc_size_t tlv4; tlv4 = (cgc_size_t)(endIndex); }
    {char * tlv19; tlv19 = (char *)(endIndex); }
    {char tlv17; tlv17 = (char)(endIndex); }
    {void * tlv16; tlv16 = (void *)(endIndex); }
    {cgc_size_t tlv15; tlv15 = (cgc_size_t)(endIndex); }
    {char * tlv20; tlv20 = (char *)(endIndex); }
}
void fix_ingred_countyParsers_5_9_5(){
int endIndex;
    bzero(&endIndex,sizeof(int));
    {int retval; retval = (int)(- 1); }
    {char * temp; temp = (char *)(- 1); }
    {char tlv6; tlv6 = (char)(- 1); }
    {int tlv11; tlv11 = (int)(- 1); }
    {int tlv10; tlv10 = (int)(- 1); }
    {void * tlv5; tlv5 = (void *)(- 1); }
    {cgc_size_t tlv4; tlv4 = (cgc_size_t)(- 1); }
    {char * tlv19; tlv19 = (char *)(- 1); }
    {char tlv17; tlv17 = (char)(- 1); }
    {void * tlv16; tlv16 = (void *)(- 1); }
    {cgc_size_t tlv15; tlv15 = (cgc_size_t)(- 1); }
    {char * tlv20; tlv20 = (char *)(- 1); }
}
void fix_ingred_countyParsers_5_9(){
fix_ingred_countyParsers_5_9_4();
fix_ingred_countyParsers_5_9_5();
}
void fix_ingred_countyParsers_5_11_4(){
int startIndex;
    bzero(&startIndex,sizeof(int));
    {int retval; retval = (int)(startIndex); }
    {char * temp; temp = (char *)(startIndex); }
    {char tlv6; tlv6 = (char)(startIndex); }
    {int tlv11; tlv11 = (int)(startIndex); }
    {int tlv10; tlv10 = (int)(startIndex); }
    {void * tlv5; tlv5 = (void *)(startIndex); }
    {cgc_size_t tlv4; tlv4 = (cgc_size_t)(startIndex); }
    {char * tlv19; tlv19 = (char *)(startIndex); }
    {char tlv17; tlv17 = (char)(startIndex); }
    {void * tlv16; tlv16 = (void *)(startIndex); }
    {cgc_size_t tlv15; tlv15 = (cgc_size_t)(startIndex); }
    {char * tlv20; tlv20 = (char *)(startIndex); }
}
void fix_ingred_countyParsers_5_11(){
fix_ingred_countyParsers_5_11_4();
}
void fix_ingred_countyParsers_5_15_4(){
int tlv2;
    bzero(&tlv2,sizeof(int));
    {int retval; retval = (int)(tlv2); }
    {char * temp; temp = (char *)(tlv2); }
    {char tlv6; tlv6 = (char)(tlv2); }
    {int tlv11; tlv11 = (int)(tlv2); }
    {int tlv10; tlv10 = (int)(tlv2); }
    {void * tlv5; tlv5 = (void *)(tlv2); }
    {cgc_size_t tlv4; tlv4 = (cgc_size_t)(tlv2); }
    {char tlv17; tlv17 = (char)(tlv2); }
    {char * tlv20; tlv20 = (char *)(tlv2); }
}
void fix_ingred_countyParsers_5_15(){
fix_ingred_countyParsers_5_15_4();
}
void fix_ingred_countyParsers_5_16_0(){
char temp_ref;
    bzero(&temp_ref,1*sizeof(char));
char * temp = &temp_ref;
    {int retval; retval = (int)(temp); }
    {int startIndex; startIndex = (int)(temp); }
    {int endIndex; endIndex = (int)(temp); }
    {int tlv1; tlv1 = (int)(temp); }
    {int tlv2; tlv2 = (int)(temp); }
    {char tlv6; tlv6 = (char)(temp); }
    {int tlv11; tlv11 = (int)(temp); }
    {int tlv10; tlv10 = (int)(temp); }
    {void * tlv5; tlv5 = (void *)(temp); }
    {cgc_size_t tlv4; tlv4 = (cgc_size_t)(temp); }
    {int tlv3; tlv3 = (int)(temp); }
    {char * tlv19; tlv19 = (char *)(temp); }
    {char tlv17; tlv17 = (char)(temp); }
    {void * tlv16; tlv16 = (void *)(temp); }
    {cgc_size_t tlv15; tlv15 = (cgc_size_t)(temp); }
    {char * tlv20; tlv20 = (char *)(temp); }
}
void fix_ingred_countyParsers_5_16(){
fix_ingred_countyParsers_5_16_0();
}
void fix_ingred_countyParsers_5_17_0(){
char temp_ref;
    bzero(&temp_ref,1*sizeof(char));
char * temp = &temp_ref;
char tlv20_ref;
    bzero(&tlv20_ref,1*sizeof(char));
char * tlv20 = &tlv20_ref;
    {int retval; retval = (int)(temp); }
    {int startIndex; startIndex = (int)(temp); }
    {int endIndex; endIndex = (int)(temp); }
    {int tlv1; tlv1 = (int)(temp); }
    {int tlv2; tlv2 = (int)(temp); }
    {char tlv6; tlv6 = (char)(temp); }
    {int tlv11; tlv11 = (int)(temp); }
    {int tlv10; tlv10 = (int)(temp); }
    {void * tlv5; tlv5 = (void *)(temp); }
    {cgc_size_t tlv4; tlv4 = (cgc_size_t)(temp); }
    {int tlv3; tlv3 = (int)(temp); }
    {char * tlv19; tlv19 = (char *)(temp); }
    {char tlv17; tlv17 = (char)(temp); }
    {void * tlv16; tlv16 = (void *)(temp); }
    {cgc_size_t tlv15; tlv15 = (cgc_size_t)(temp); }
    {char * tlv20; tlv20 = (char *)(temp); }
}
void fix_ingred_countyParsers_5_17_1(){
char temp_ref;
    bzero(&temp_ref,1*sizeof(char));
char * temp = &temp_ref;
char tlv20_ref;
    bzero(&tlv20_ref,1*sizeof(char));
char * tlv20 = &tlv20_ref;
    {int retval; retval = (int)(cgc_strlen ( tlv20 ) + 1); }
    {int startIndex; startIndex = (int)(cgc_strlen ( tlv20 ) + 1); }
    {int endIndex; endIndex = (int)(cgc_strlen ( tlv20 ) + 1); }
    {char * temp; temp = (char *)(cgc_strlen ( tlv20 ) + 1); }
    {int tlv1; tlv1 = (int)(cgc_strlen ( tlv20 ) + 1); }
    {int tlv2; tlv2 = (int)(cgc_strlen ( tlv20 ) + 1); }
    {char tlv6; tlv6 = (char)(cgc_strlen ( tlv20 ) + 1); }
    {int tlv11; tlv11 = (int)(cgc_strlen ( tlv20 ) + 1); }
    {int tlv10; tlv10 = (int)(cgc_strlen ( tlv20 ) + 1); }
    {void * tlv5; tlv5 = (void *)(cgc_strlen ( tlv20 ) + 1); }
    {cgc_size_t tlv4; tlv4 = (cgc_size_t)(cgc_strlen ( tlv20 ) + 1); }
    {int tlv3; tlv3 = (int)(cgc_strlen ( tlv20 ) + 1); }
    {char * tlv19; tlv19 = (char *)(cgc_strlen ( tlv20 ) + 1); }
    {char tlv17; tlv17 = (char)(cgc_strlen ( tlv20 ) + 1); }
    {void * tlv16; tlv16 = (void *)(cgc_strlen ( tlv20 ) + 1); }
    {cgc_size_t tlv15; tlv15 = (cgc_size_t)(cgc_strlen ( tlv20 ) + 1); }
}
void fix_ingred_countyParsers_5_17(){
fix_ingred_countyParsers_5_17_0();
fix_ingred_countyParsers_5_17_1();
}
void fix_ingred_countyParsers_5_19_1(){
char tlv19_ref;
    bzero(&tlv19_ref,1*sizeof(char));
char * tlv19 = &tlv19_ref;
    {int retval; retval = (int)(cgc_strlen ( tlv19 ) + 1); }
    {int startIndex; startIndex = (int)(cgc_strlen ( tlv19 ) + 1); }
    {int endIndex; endIndex = (int)(cgc_strlen ( tlv19 ) + 1); }
    {char * temp; temp = (char *)(cgc_strlen ( tlv19 ) + 1); }
    {int tlv1; tlv1 = (int)(cgc_strlen ( tlv19 ) + 1); }
    {int tlv2; tlv2 = (int)(cgc_strlen ( tlv19 ) + 1); }
    {char tlv6; tlv6 = (char)(cgc_strlen ( tlv19 ) + 1); }
    {int tlv11; tlv11 = (int)(cgc_strlen ( tlv19 ) + 1); }
    {int tlv10; tlv10 = (int)(cgc_strlen ( tlv19 ) + 1); }
    {void * tlv5; tlv5 = (void *)(cgc_strlen ( tlv19 ) + 1); }
    {cgc_size_t tlv4; tlv4 = (cgc_size_t)(cgc_strlen ( tlv19 ) + 1); }
    {int tlv3; tlv3 = (int)(cgc_strlen ( tlv19 ) + 1); }
    {char tlv17; tlv17 = (char)(cgc_strlen ( tlv19 ) + 1); }
    {void * tlv16; tlv16 = (void *)(cgc_strlen ( tlv19 ) + 1); }
    {cgc_size_t tlv15; tlv15 = (cgc_size_t)(cgc_strlen ( tlv19 ) + 1); }
    {char * tlv20; tlv20 = (char *)(cgc_strlen ( tlv19 ) + 1); }
}
void fix_ingred_countyParsers_5_19(){
fix_ingred_countyParsers_5_19_1();
}
void fix_ingred_countyParsers_5(){
fix_ingred_countyParsers_5_0();
fix_ingred_countyParsers_5_2();
fix_ingred_countyParsers_5_4();
fix_ingred_countyParsers_5_5();
fix_ingred_countyParsers_5_9();
fix_ingred_countyParsers_5_11();
fix_ingred_countyParsers_5_15();
fix_ingred_countyParsers_5_16();
fix_ingred_countyParsers_5_17();
fix_ingred_countyParsers_5_19();
}
void fix_ingred_countyParsers_6_0_0(){
    {double density; density = (double)(- 1.0); }
}
void fix_ingred_countyParsers_6_0_3(){
    {int * tlv3; tlv3 = (int *)(NULL); }
    {char* tlv8 ; tlv8  = (char*)(NULL); }
    {int tlv12; tlv12 = (int)(NULL); }
    {void * tlv6; tlv6 = (void *)(NULL); }
    {cgc_size_t tlv5; tlv5 = (cgc_size_t)(NULL); }
    {char* tlv17 ; tlv17  = (char*)(NULL); }
    {int tlv16; tlv16 = (int)(NULL); }
}
void fix_ingred_countyParsers_6_0_4(){
    {int * tlv3; tlv3 = (int *)(0); }
    {char* tlv8 ; tlv8  = (char*)(0); }
    {int tlv12; tlv12 = (int)(0); }
    {void * tlv6; tlv6 = (void *)(0); }
    {cgc_size_t tlv5; tlv5 = (cgc_size_t)(0); }
    {char* tlv17 ; tlv17  = (char*)(0); }
    {int tlv16; tlv16 = (int)(0); }
}
void fix_ingred_countyParsers_6_0(){
fix_ingred_countyParsers_6_0_0();
fix_ingred_countyParsers_6_0_3();
fix_ingred_countyParsers_6_0_4();
}
void fix_ingred_countyParsers_6_2_1(){
int lastGood;
    bzero(&lastGood,sizeof(int));
    {char * temp; temp = (char *)(& lastGood); }
    {int * tlv3; tlv3 = (int *)(& lastGood); }
    {char* tlv8 ; tlv8  = (char*)(& lastGood); }
    {int tlv12; tlv12 = (int)(& lastGood); }
    {void * tlv6; tlv6 = (void *)(& lastGood); }
    {cgc_size_t tlv5; tlv5 = (cgc_size_t)(& lastGood); }
    {char* tlv17 ; tlv17  = (char*)(& lastGood); }
    {int tlv16; tlv16 = (int)(& lastGood); }
}
void fix_ingred_countyParsers_6_2(){
fix_ingred_countyParsers_6_2_1();
}
void fix_ingred_countyParsers_6_4_5(){
int tlv1;
    bzero(&tlv1,sizeof(int));
    {char * temp; temp = (char *)(tlv1); }
    {int lastGood; lastGood = (int)(tlv1); }
    {int * tlv3; tlv3 = (int *)(tlv1); }
    {char* tlv8 ; tlv8  = (char*)(tlv1); }
    {int tlv7; tlv7 = (int)(tlv1); }
    {int tlv13; tlv13 = (int)(tlv1); }
    {int tlv12; tlv12 = (int)(tlv1); }
    {void * tlv6; tlv6 = (void *)(tlv1); }
    {cgc_size_t tlv5; tlv5 = (cgc_size_t)(tlv1); }
    {char* tlv17 ; tlv17  = (char*)(tlv1); }
    {int tlv16; tlv16 = (int)(tlv1); }
}
void fix_ingred_countyParsers_6_4(){
fix_ingred_countyParsers_6_4_5();
}
void fix_ingred_countyParsers_6_9_1(){
int startIndex;
    bzero(&startIndex,sizeof(int));
int endIndex;
    bzero(&endIndex,sizeof(int));
    {int * tlv3; tlv3 = (int *)(startIndex); }
    {char* tlv8 ; tlv8  = (char*)(startIndex); }
    {int tlv12; tlv12 = (int)(startIndex); }
    {void * tlv6; tlv6 = (void *)(startIndex); }
    {cgc_size_t tlv5; tlv5 = (cgc_size_t)(startIndex); }
    {char* tlv17 ; tlv17  = (char*)(startIndex); }
    {int tlv16; tlv16 = (int)(startIndex); }
}
void fix_ingred_countyParsers_6_9_2(){
int startIndex;
    bzero(&startIndex,sizeof(int));
int endIndex;
    bzero(&endIndex,sizeof(int));
    {int * tlv3; tlv3 = (int *)(endIndex); }
    {char* tlv8 ; tlv8  = (char*)(endIndex); }
    {int tlv12; tlv12 = (int)(endIndex); }
    {void * tlv6; tlv6 = (void *)(endIndex); }
    {cgc_size_t tlv5; tlv5 = (cgc_size_t)(endIndex); }
    {char* tlv17 ; tlv17  = (char*)(endIndex); }
    {int tlv16; tlv16 = (int)(endIndex); }
}
void fix_ingred_countyParsers_6_9(){
fix_ingred_countyParsers_6_9_1();
fix_ingred_countyParsers_6_9_2();
}
void fix_ingred_countyParsers_6_10_5(){
char temp_ref;
    bzero(&temp_ref,1*sizeof(char));
char * temp = &temp_ref;
    {int lastGood; lastGood = (int)(temp); }
    {int * tlv3; tlv3 = (int *)(temp); }
    {char* tlv8 ; tlv8  = (char*)(temp); }
    {int tlv7; tlv7 = (int)(temp); }
    {int tlv13; tlv13 = (int)(temp); }
    {int tlv12; tlv12 = (int)(temp); }
    {void * tlv6; tlv6 = (void *)(temp); }
    {cgc_size_t tlv5; tlv5 = (cgc_size_t)(temp); }
    {char* tlv17 ; tlv17  = (char*)(temp); }
    {int tlv16; tlv16 = (int)(temp); }
}
void fix_ingred_countyParsers_6_10(){
fix_ingred_countyParsers_6_10_5();
}
void fix_ingred_countyParsers_6_12_0(){
int endIndex;
    bzero(&endIndex,sizeof(int));
int startIndex;
    bzero(&startIndex,sizeof(int));
char temp_ref;
    bzero(&temp_ref,1*sizeof(char));
char * temp = &temp_ref;
    {int lastGood; lastGood = (int)(temp); }
    {int * tlv3; tlv3 = (int *)(temp); }
    {char* tlv8 ; tlv8  = (char*)(temp); }
    {int tlv7; tlv7 = (int)(temp); }
    {int tlv13; tlv13 = (int)(temp); }
    {int tlv12; tlv12 = (int)(temp); }
    {void * tlv6; tlv6 = (void *)(temp); }
    {cgc_size_t tlv5; tlv5 = (cgc_size_t)(temp); }
    {char* tlv17 ; tlv17  = (char*)(temp); }
    {int tlv16; tlv16 = (int)(temp); }
}
void fix_ingred_countyParsers_6_12_1(){
int endIndex;
    bzero(&endIndex,sizeof(int));
int startIndex;
    bzero(&startIndex,sizeof(int));
char temp_ref;
    bzero(&temp_ref,1*sizeof(char));
char * temp = &temp_ref;
    {char * temp; temp = (char *)(( endIndex - startIndex ) + 1); }
    {int * tlv3; tlv3 = (int *)(( endIndex - startIndex ) + 1); }
    {char* tlv8 ; tlv8  = (char*)(( endIndex - startIndex ) + 1); }
    {int tlv12; tlv12 = (int)(( endIndex - startIndex ) + 1); }
    {void * tlv6; tlv6 = (void *)(( endIndex - startIndex ) + 1); }
    {cgc_size_t tlv5; tlv5 = (cgc_size_t)(( endIndex - startIndex ) + 1); }
    {char* tlv17 ; tlv17  = (char*)(( endIndex - startIndex ) + 1); }
    {int tlv16; tlv16 = (int)(( endIndex - startIndex ) + 1); }
}
void fix_ingred_countyParsers_6_12(){
fix_ingred_countyParsers_6_12_0();
fix_ingred_countyParsers_6_12_1();
}
void fix_ingred_countyParsers_6_13_1(){
    {int * tlv3; tlv3 = (int *)(1); }
    {char* tlv8 ; tlv8  = (char*)(1); }
    {int tlv12; tlv12 = (int)(1); }
    {void * tlv6; tlv6 = (void *)(1); }
    {cgc_size_t tlv5; tlv5 = (cgc_size_t)(1); }
    {char* tlv17 ; tlv17  = (char*)(1); }
    {int tlv16; tlv16 = (int)(1); }
}
void fix_ingred_countyParsers_6_13(){
fix_ingred_countyParsers_6_13_1();
}
void fix_ingred_countyParsers_6_14_6(){
int tlv2;
    bzero(&tlv2,sizeof(int));
    {int * tlv3; tlv3 = (int *)(tlv2); }
    {char* tlv8 ; tlv8  = (char*)(tlv2); }
    {int tlv12; tlv12 = (int)(tlv2); }
    {void * tlv6; tlv6 = (void *)(tlv2); }
    {cgc_size_t tlv5; tlv5 = (cgc_size_t)(tlv2); }
    {char* tlv17 ; tlv17  = (char*)(tlv2); }
    {int tlv16; tlv16 = (int)(tlv2); }
}
void fix_ingred_countyParsers_6_14(){
fix_ingred_countyParsers_6_14_6();
}
void fix_ingred_countyParsers_6(){
fix_ingred_countyParsers_6_0();
fix_ingred_countyParsers_6_2();
fix_ingred_countyParsers_6_4();
fix_ingred_countyParsers_6_9();
fix_ingred_countyParsers_6_10();
fix_ingred_countyParsers_6_12();
fix_ingred_countyParsers_6_13();
fix_ingred_countyParsers_6_14();
}
void fix_ingred_countyParsers_7_0_0(){
    {double area; area = (double)(- 1.0); }
}
void fix_ingred_countyParsers_7_0_1(){
    {int * tlv6; tlv6 = (int *)(0); }
    {int * tlv8; tlv8 = (int *)(0); }
    {int tlv18; tlv18 = (int)(0); }
    {int tlv17; tlv17 = (int)(0); }
    {void * tlv11; tlv11 = (void *)(0); }
    {cgc_size_t tlv10; tlv10 = (cgc_size_t)(0); }
    {int tlv25; tlv25 = (int)(0); }
    {int tlv24; tlv24 = (int)(0); }
    {void * tlv13; tlv13 = (void *)(0); }
    {cgc_size_t tlv12; tlv12 = (cgc_size_t)(0); }
    {char tlv28; tlv28 = (char)(0); }
    {int tlv35; tlv35 = (int)(0); }
    {void * tlv15; tlv15 = (void *)(0); }
    {cgc_size_t tlv14; tlv14 = (cgc_size_t)(0); }
    {char * tlv45; tlv45 = (char *)(0); }
    {void * tlv42; tlv42 = (void *)(0); }
    {cgc_size_t tlv41; tlv41 = (cgc_size_t)(0); }
    {void * tlv44; tlv44 = (void *)(0); }
    {cgc_size_t tlv43; tlv43 = (cgc_size_t)(0); }
    {char * tlv47; tlv47 = (char *)(0); }
    {char * tlv48; tlv48 = (char *)(0); }
}
void fix_ingred_countyParsers_7_0_3(){
    {int * tlv6; tlv6 = (int *)(NULL); }
    {int * tlv8; tlv8 = (int *)(NULL); }
    {int tlv18; tlv18 = (int)(NULL); }
    {int tlv17; tlv17 = (int)(NULL); }
    {void * tlv11; tlv11 = (void *)(NULL); }
    {cgc_size_t tlv10; tlv10 = (cgc_size_t)(NULL); }
    {int tlv25; tlv25 = (int)(NULL); }
    {int tlv24; tlv24 = (int)(NULL); }
    {void * tlv13; tlv13 = (void *)(NULL); }
    {cgc_size_t tlv12; tlv12 = (cgc_size_t)(NULL); }
    {char tlv28; tlv28 = (char)(NULL); }
    {char tlv30; tlv30 = (char)(NULL); }
    {int tlv35; tlv35 = (int)(NULL); }
    {void * tlv15; tlv15 = (void *)(NULL); }
    {cgc_size_t tlv14; tlv14 = (cgc_size_t)(NULL); }
    {char * tlv45; tlv45 = (char *)(NULL); }
    {char * tlv46; tlv46 = (char *)(NULL); }
    {void * tlv42; tlv42 = (void *)(NULL); }
    {cgc_size_t tlv41; tlv41 = (cgc_size_t)(NULL); }
    {void * tlv44; tlv44 = (void *)(NULL); }
    {cgc_size_t tlv43; tlv43 = (cgc_size_t)(NULL); }
    {char * tlv47; tlv47 = (char *)(NULL); }
    {char * tlv48; tlv48 = (char *)(NULL); }
}
void fix_ingred_countyParsers_7_0(){
fix_ingred_countyParsers_7_0_0();
fix_ingred_countyParsers_7_0_1();
fix_ingred_countyParsers_7_0_3();
}
void fix_ingred_countyParsers_7_2_1(){
int lastGood;
    bzero(&lastGood,sizeof(int));
    {int * tlv6; tlv6 = (int *)(& lastGood); }
    {int * tlv8; tlv8 = (int *)(& lastGood); }
    {int tlv18; tlv18 = (int)(& lastGood); }
    {int tlv17; tlv17 = (int)(& lastGood); }
    {void * tlv11; tlv11 = (void *)(& lastGood); }
    {cgc_size_t tlv10; tlv10 = (cgc_size_t)(& lastGood); }
    {int tlv25; tlv25 = (int)(& lastGood); }
    {int tlv24; tlv24 = (int)(& lastGood); }
    {void * tlv13; tlv13 = (void *)(& lastGood); }
    {cgc_size_t tlv12; tlv12 = (cgc_size_t)(& lastGood); }
    {char tlv28; tlv28 = (char)(& lastGood); }
    {char tlv30; tlv30 = (char)(& lastGood); }
    {int tlv35; tlv35 = (int)(& lastGood); }
    {void * tlv15; tlv15 = (void *)(& lastGood); }
    {cgc_size_t tlv14; tlv14 = (cgc_size_t)(& lastGood); }
    {char * tlv45; tlv45 = (char *)(& lastGood); }
    {char * tlv46; tlv46 = (char *)(& lastGood); }
    {void * tlv42; tlv42 = (void *)(& lastGood); }
    {cgc_size_t tlv41; tlv41 = (cgc_size_t)(& lastGood); }
    {void * tlv44; tlv44 = (void *)(& lastGood); }
    {cgc_size_t tlv43; tlv43 = (cgc_size_t)(& lastGood); }
    {char * tlv47; tlv47 = (char *)(& lastGood); }
    {char * tlv48; tlv48 = (char *)(& lastGood); }
}
void fix_ingred_countyParsers_7_2(){
fix_ingred_countyParsers_7_2_1();
}
void fix_ingred_countyParsers_7_4_1(){
int startIndex;
    bzero(&startIndex,sizeof(int));
    {char * temp; temp = (char *)(& startIndex); }
    {int * tlv6; tlv6 = (int *)(& startIndex); }
    {int * tlv8; tlv8 = (int *)(& startIndex); }
    {int tlv18; tlv18 = (int)(& startIndex); }
    {int tlv17; tlv17 = (int)(& startIndex); }
    {void * tlv11; tlv11 = (void *)(& startIndex); }
    {cgc_size_t tlv10; tlv10 = (cgc_size_t)(& startIndex); }
    {int tlv25; tlv25 = (int)(& startIndex); }
    {int tlv24; tlv24 = (int)(& startIndex); }
    {void * tlv13; tlv13 = (void *)(& startIndex); }
    {cgc_size_t tlv12; tlv12 = (cgc_size_t)(& startIndex); }
    {char tlv28; tlv28 = (char)(& startIndex); }
    {char tlv30; tlv30 = (char)(& startIndex); }
    {int tlv35; tlv35 = (int)(& startIndex); }
    {void * tlv15; tlv15 = (void *)(& startIndex); }
    {cgc_size_t tlv14; tlv14 = (cgc_size_t)(& startIndex); }
    {char * tlv45; tlv45 = (char *)(& startIndex); }
    {char * tlv46; tlv46 = (char *)(& startIndex); }
    {void * tlv42; tlv42 = (void *)(& startIndex); }
    {cgc_size_t tlv41; tlv41 = (cgc_size_t)(& startIndex); }
    {void * tlv44; tlv44 = (void *)(& startIndex); }
    {cgc_size_t tlv43; tlv43 = (cgc_size_t)(& startIndex); }
    {char * tlv47; tlv47 = (char *)(& startIndex); }
    {char * tlv48; tlv48 = (char *)(& startIndex); }
}
void fix_ingred_countyParsers_7_4(){
fix_ingred_countyParsers_7_4_1();
}
void fix_ingred_countyParsers_7_6_5(){
int endIndex;
    bzero(&endIndex,sizeof(int));
int startIndex;
    bzero(&startIndex,sizeof(int));
    {int * tlv6; tlv6 = (int *)(endIndex); }
    {int * tlv8; tlv8 = (int *)(endIndex); }
    {int tlv18; tlv18 = (int)(endIndex); }
    {int tlv17; tlv17 = (int)(endIndex); }
    {void * tlv11; tlv11 = (void *)(endIndex); }
    {cgc_size_t tlv10; tlv10 = (cgc_size_t)(endIndex); }
    {int tlv25; tlv25 = (int)(endIndex); }
    {int tlv24; tlv24 = (int)(endIndex); }
    {void * tlv13; tlv13 = (void *)(endIndex); }
    {cgc_size_t tlv12; tlv12 = (cgc_size_t)(endIndex); }
    {char tlv28; tlv28 = (char)(endIndex); }
    {char tlv30; tlv30 = (char)(endIndex); }
    {int tlv35; tlv35 = (int)(endIndex); }
    {void * tlv15; tlv15 = (void *)(endIndex); }
    {cgc_size_t tlv14; tlv14 = (cgc_size_t)(endIndex); }
    {char * tlv45; tlv45 = (char *)(endIndex); }
    {char * tlv46; tlv46 = (char *)(endIndex); }
    {void * tlv42; tlv42 = (void *)(endIndex); }
    {cgc_size_t tlv41; tlv41 = (cgc_size_t)(endIndex); }
    {void * tlv44; tlv44 = (void *)(endIndex); }
    {cgc_size_t tlv43; tlv43 = (cgc_size_t)(endIndex); }
    {char * tlv47; tlv47 = (char *)(endIndex); }
    {char * tlv48; tlv48 = (char *)(endIndex); }
}
void fix_ingred_countyParsers_7_6_6(){
int endIndex;
    bzero(&endIndex,sizeof(int));
int startIndex;
    bzero(&startIndex,sizeof(int));
    {int * tlv6; tlv6 = (int *)(- 1); }
    {int * tlv8; tlv8 = (int *)(- 1); }
    {int tlv18; tlv18 = (int)(- 1); }
    {int tlv17; tlv17 = (int)(- 1); }
    {void * tlv11; tlv11 = (void *)(- 1); }
    {cgc_size_t tlv10; tlv10 = (cgc_size_t)(- 1); }
    {int tlv25; tlv25 = (int)(- 1); }
    {int tlv24; tlv24 = (int)(- 1); }
    {void * tlv13; tlv13 = (void *)(- 1); }
    {cgc_size_t tlv12; tlv12 = (cgc_size_t)(- 1); }
    {char tlv28; tlv28 = (char)(- 1); }
    {char tlv30; tlv30 = (char)(- 1); }
    {int tlv35; tlv35 = (int)(- 1); }
    {void * tlv15; tlv15 = (void *)(- 1); }
    {cgc_size_t tlv14; tlv14 = (cgc_size_t)(- 1); }
    {char * tlv45; tlv45 = (char *)(- 1); }
    {char * tlv46; tlv46 = (char *)(- 1); }
    {void * tlv42; tlv42 = (void *)(- 1); }
    {cgc_size_t tlv41; tlv41 = (cgc_size_t)(- 1); }
    {void * tlv44; tlv44 = (void *)(- 1); }
    {cgc_size_t tlv43; tlv43 = (cgc_size_t)(- 1); }
    {char * tlv47; tlv47 = (char *)(- 1); }
    {char * tlv48; tlv48 = (char *)(- 1); }
}
void fix_ingred_countyParsers_7_6_7(){
int endIndex;
    bzero(&endIndex,sizeof(int));
int startIndex;
    bzero(&startIndex,sizeof(int));
    {int * tlv6; tlv6 = (int *)(startIndex); }
    {int * tlv8; tlv8 = (int *)(startIndex); }
    {int tlv18; tlv18 = (int)(startIndex); }
    {int tlv17; tlv17 = (int)(startIndex); }
    {void * tlv11; tlv11 = (void *)(startIndex); }
    {cgc_size_t tlv10; tlv10 = (cgc_size_t)(startIndex); }
    {int tlv25; tlv25 = (int)(startIndex); }
    {int tlv24; tlv24 = (int)(startIndex); }
    {void * tlv13; tlv13 = (void *)(startIndex); }
    {cgc_size_t tlv12; tlv12 = (cgc_size_t)(startIndex); }
    {char tlv28; tlv28 = (char)(startIndex); }
    {char tlv30; tlv30 = (char)(startIndex); }
    {int tlv35; tlv35 = (int)(startIndex); }
    {void * tlv15; tlv15 = (void *)(startIndex); }
    {cgc_size_t tlv14; tlv14 = (cgc_size_t)(startIndex); }
    {char * tlv45; tlv45 = (char *)(startIndex); }
    {char * tlv46; tlv46 = (char *)(startIndex); }
    {void * tlv42; tlv42 = (void *)(startIndex); }
    {cgc_size_t tlv41; tlv41 = (cgc_size_t)(startIndex); }
    {void * tlv44; tlv44 = (void *)(startIndex); }
    {cgc_size_t tlv43; tlv43 = (cgc_size_t)(startIndex); }
    {char * tlv47; tlv47 = (char *)(startIndex); }
    {char * tlv48; tlv48 = (char *)(startIndex); }
}
void fix_ingred_countyParsers_7_6(){
fix_ingred_countyParsers_7_6_5();
fix_ingred_countyParsers_7_6_6();
fix_ingred_countyParsers_7_6_7();
}
void fix_ingred_countyParsers_7_10_5(){
int tlv1;
    bzero(&tlv1,sizeof(int));
    {int startIndex; startIndex = (int)(tlv1); }
    {int endIndex; endIndex = (int)(tlv1); }
    {int tlv4; tlv4 = (int)(tlv1); }
    {int tlv5; tlv5 = (int)(tlv1); }
    {int * tlv6; tlv6 = (int *)(tlv1); }
    {int * tlv8; tlv8 = (int *)(tlv1); }
    {int tlv18; tlv18 = (int)(tlv1); }
    {int tlv17; tlv17 = (int)(tlv1); }
    {void * tlv11; tlv11 = (void *)(tlv1); }
    {cgc_size_t tlv10; tlv10 = (cgc_size_t)(tlv1); }
    {int tlv25; tlv25 = (int)(tlv1); }
    {int tlv24; tlv24 = (int)(tlv1); }
    {void * tlv13; tlv13 = (void *)(tlv1); }
    {cgc_size_t tlv12; tlv12 = (cgc_size_t)(tlv1); }
    {char tlv28; tlv28 = (char)(tlv1); }
    {int tlv35; tlv35 = (int)(tlv1); }
    {int tlv34; tlv34 = (int)(tlv1); }
    {void * tlv15; tlv15 = (void *)(tlv1); }
    {cgc_size_t tlv14; tlv14 = (cgc_size_t)(tlv1); }
    {char * tlv45; tlv45 = (char *)(tlv1); }
    {void * tlv42; tlv42 = (void *)(tlv1); }
    {cgc_size_t tlv41; tlv41 = (cgc_size_t)(tlv1); }
    {void * tlv44; tlv44 = (void *)(tlv1); }
    {cgc_size_t tlv43; tlv43 = (cgc_size_t)(tlv1); }
    {char * tlv47; tlv47 = (char *)(tlv1); }
    {char * tlv48; tlv48 = (char *)(tlv1); }
}
void fix_ingred_countyParsers_7_10(){
fix_ingred_countyParsers_7_10_5();
}
void fix_ingred_countyParsers_7_11_0(){
char temp_ref;
    bzero(&temp_ref,1*sizeof(char));
char * temp = &temp_ref;
    {int tlv4; tlv4 = (int)(temp); }
    {int tlv5; tlv5 = (int)(temp); }
    {int * tlv6; tlv6 = (int *)(temp); }
    {int * tlv8; tlv8 = (int *)(temp); }
    {int tlv18; tlv18 = (int)(temp); }
    {int tlv17; tlv17 = (int)(temp); }
    {void * tlv11; tlv11 = (void *)(temp); }
    {cgc_size_t tlv10; tlv10 = (cgc_size_t)(temp); }
    {int tlv25; tlv25 = (int)(temp); }
    {int tlv24; tlv24 = (int)(temp); }
    {void * tlv13; tlv13 = (void *)(temp); }
    {cgc_size_t tlv12; tlv12 = (cgc_size_t)(temp); }
    {char tlv28; tlv28 = (char)(temp); }
    {char tlv30; tlv30 = (char)(temp); }
    {int tlv35; tlv35 = (int)(temp); }
    {int tlv34; tlv34 = (int)(temp); }
    {void * tlv15; tlv15 = (void *)(temp); }
    {cgc_size_t tlv14; tlv14 = (cgc_size_t)(temp); }
    {char tlv39; tlv39 = (char)(temp); }
    {char * tlv45; tlv45 = (char *)(temp); }
    {char * tlv46; tlv46 = (char *)(temp); }
    {void * tlv42; tlv42 = (void *)(temp); }
    {cgc_size_t tlv41; tlv41 = (cgc_size_t)(temp); }
    {void * tlv44; tlv44 = (void *)(temp); }
    {cgc_size_t tlv43; tlv43 = (cgc_size_t)(temp); }
    {char * tlv47; tlv47 = (char *)(temp); }
    {char * tlv48; tlv48 = (char *)(temp); }
}
void fix_ingred_countyParsers_7_11(){
fix_ingred_countyParsers_7_11_0();
}
void fix_ingred_countyParsers_7_12_0(){
char tlv47_ref;
    bzero(&tlv47_ref,1*sizeof(char));
char * tlv47 = &tlv47_ref;
char temp_ref;
    bzero(&temp_ref,1*sizeof(char));
char * temp = &temp_ref;
    {int tlv4; tlv4 = (int)(temp); }
    {int tlv5; tlv5 = (int)(temp); }
    {int * tlv6; tlv6 = (int *)(temp); }
    {int * tlv8; tlv8 = (int *)(temp); }
    {int tlv18; tlv18 = (int)(temp); }
    {int tlv17; tlv17 = (int)(temp); }
    {void * tlv11; tlv11 = (void *)(temp); }
    {cgc_size_t tlv10; tlv10 = (cgc_size_t)(temp); }
    {int tlv25; tlv25 = (int)(temp); }
    {int tlv24; tlv24 = (int)(temp); }
    {void * tlv13; tlv13 = (void *)(temp); }
    {cgc_size_t tlv12; tlv12 = (cgc_size_t)(temp); }
    {char tlv28; tlv28 = (char)(temp); }
    {char tlv30; tlv30 = (char)(temp); }
    {int tlv35; tlv35 = (int)(temp); }
    {int tlv34; tlv34 = (int)(temp); }
    {void * tlv15; tlv15 = (void *)(temp); }
    {cgc_size_t tlv14; tlv14 = (cgc_size_t)(temp); }
    {char tlv39; tlv39 = (char)(temp); }
    {char * tlv45; tlv45 = (char *)(temp); }
    {char * tlv46; tlv46 = (char *)(temp); }
    {void * tlv42; tlv42 = (void *)(temp); }
    {cgc_size_t tlv41; tlv41 = (cgc_size_t)(temp); }
    {void * tlv44; tlv44 = (void *)(temp); }
    {cgc_size_t tlv43; tlv43 = (cgc_size_t)(temp); }
    {char * tlv47; tlv47 = (char *)(temp); }
    {char * tlv48; tlv48 = (char *)(temp); }
}
void fix_ingred_countyParsers_7_12_1(){
char tlv47_ref;
    bzero(&tlv47_ref,1*sizeof(char));
char * tlv47 = &tlv47_ref;
char temp_ref;
    bzero(&temp_ref,1*sizeof(char));
char * temp = &temp_ref;
    {int startIndex; startIndex = (int)(cgc_strlen ( tlv47 ) + 1); }
    {int endIndex; endIndex = (int)(cgc_strlen ( tlv47 ) + 1); }
    {char * temp; temp = (char *)(cgc_strlen ( tlv47 ) + 1); }
    {int lastGood; lastGood = (int)(cgc_strlen ( tlv47 ) + 1); }
    {int tlv1; tlv1 = (int)(cgc_strlen ( tlv47 ) + 1); }
    {int tlv2; tlv2 = (int)(cgc_strlen ( tlv47 ) + 1); }
    {int tlv3; tlv3 = (int)(cgc_strlen ( tlv47 ) + 1); }
    {int tlv4; tlv4 = (int)(cgc_strlen ( tlv47 ) + 1); }
    {int tlv5; tlv5 = (int)(cgc_strlen ( tlv47 ) + 1); }
    {int * tlv6; tlv6 = (int *)(cgc_strlen ( tlv47 ) + 1); }
    {int * tlv8; tlv8 = (int *)(cgc_strlen ( tlv47 ) + 1); }
    {int tlv18; tlv18 = (int)(cgc_strlen ( tlv47 ) + 1); }
    {int tlv17; tlv17 = (int)(cgc_strlen ( tlv47 ) + 1); }
    {void * tlv11; tlv11 = (void *)(cgc_strlen ( tlv47 ) + 1); }
    {cgc_size_t tlv10; tlv10 = (cgc_size_t)(cgc_strlen ( tlv47 ) + 1); }
    {int tlv25; tlv25 = (int)(cgc_strlen ( tlv47 ) + 1); }
    {int tlv24; tlv24 = (int)(cgc_strlen ( tlv47 ) + 1); }
    {void * tlv13; tlv13 = (void *)(cgc_strlen ( tlv47 ) + 1); }
    {cgc_size_t tlv12; tlv12 = (cgc_size_t)(cgc_strlen ( tlv47 ) + 1); }
    {char tlv28; tlv28 = (char)(cgc_strlen ( tlv47 ) + 1); }
    {char tlv30; tlv30 = (char)(cgc_strlen ( tlv47 ) + 1); }
    {int tlv35; tlv35 = (int)(cgc_strlen ( tlv47 ) + 1); }
    {int tlv34; tlv34 = (int)(cgc_strlen ( tlv47 ) + 1); }
    {void * tlv15; tlv15 = (void *)(cgc_strlen ( tlv47 ) + 1); }
    {cgc_size_t tlv14; tlv14 = (cgc_size_t)(cgc_strlen ( tlv47 ) + 1); }
    {char tlv39; tlv39 = (char)(cgc_strlen ( tlv47 ) + 1); }
    {char * tlv45; tlv45 = (char *)(cgc_strlen ( tlv47 ) + 1); }
    {char * tlv46; tlv46 = (char *)(cgc_strlen ( tlv47 ) + 1); }
    {void * tlv42; tlv42 = (void *)(cgc_strlen ( tlv47 ) + 1); }
    {cgc_size_t tlv41; tlv41 = (cgc_size_t)(cgc_strlen ( tlv47 ) + 1); }
    {void * tlv44; tlv44 = (void *)(cgc_strlen ( tlv47 ) + 1); }
    {cgc_size_t tlv43; tlv43 = (cgc_size_t)(cgc_strlen ( tlv47 ) + 1); }
    {char * tlv48; tlv48 = (char *)(cgc_strlen ( tlv47 ) + 1); }
}
void fix_ingred_countyParsers_7_12(){
fix_ingred_countyParsers_7_12_0();
fix_ingred_countyParsers_7_12_1();
}
void fix_ingred_countyParsers_7_14_1(){
char tlv45_ref;
    bzero(&tlv45_ref,1*sizeof(char));
char * tlv45 = &tlv45_ref;
    {int startIndex; startIndex = (int)(cgc_strlen ( tlv45 ) + 1); }
    {int endIndex; endIndex = (int)(cgc_strlen ( tlv45 ) + 1); }
    {char * temp; temp = (char *)(cgc_strlen ( tlv45 ) + 1); }
    {int lastGood; lastGood = (int)(cgc_strlen ( tlv45 ) + 1); }
    {int tlv1; tlv1 = (int)(cgc_strlen ( tlv45 ) + 1); }
    {int tlv2; tlv2 = (int)(cgc_strlen ( tlv45 ) + 1); }
    {int tlv3; tlv3 = (int)(cgc_strlen ( tlv45 ) + 1); }
    {int tlv4; tlv4 = (int)(cgc_strlen ( tlv45 ) + 1); }
    {int tlv5; tlv5 = (int)(cgc_strlen ( tlv45 ) + 1); }
    {int * tlv6; tlv6 = (int *)(cgc_strlen ( tlv45 ) + 1); }
    {int * tlv8; tlv8 = (int *)(cgc_strlen ( tlv45 ) + 1); }
    {int tlv18; tlv18 = (int)(cgc_strlen ( tlv45 ) + 1); }
    {int tlv17; tlv17 = (int)(cgc_strlen ( tlv45 ) + 1); }
    {void * tlv11; tlv11 = (void *)(cgc_strlen ( tlv45 ) + 1); }
    {cgc_size_t tlv10; tlv10 = (cgc_size_t)(cgc_strlen ( tlv45 ) + 1); }
    {int tlv25; tlv25 = (int)(cgc_strlen ( tlv45 ) + 1); }
    {int tlv24; tlv24 = (int)(cgc_strlen ( tlv45 ) + 1); }
    {void * tlv13; tlv13 = (void *)(cgc_strlen ( tlv45 ) + 1); }
    {cgc_size_t tlv12; tlv12 = (cgc_size_t)(cgc_strlen ( tlv45 ) + 1); }
    {char tlv28; tlv28 = (char)(cgc_strlen ( tlv45 ) + 1); }
    {char tlv30; tlv30 = (char)(cgc_strlen ( tlv45 ) + 1); }
    {int tlv35; tlv35 = (int)(cgc_strlen ( tlv45 ) + 1); }
    {int tlv34; tlv34 = (int)(cgc_strlen ( tlv45 ) + 1); }
    {void * tlv15; tlv15 = (void *)(cgc_strlen ( tlv45 ) + 1); }
    {cgc_size_t tlv14; tlv14 = (cgc_size_t)(cgc_strlen ( tlv45 ) + 1); }
    {char tlv39; tlv39 = (char)(cgc_strlen ( tlv45 ) + 1); }
    {char * tlv46; tlv46 = (char *)(cgc_strlen ( tlv45 ) + 1); }
    {void * tlv42; tlv42 = (void *)(cgc_strlen ( tlv45 ) + 1); }
    {cgc_size_t tlv41; tlv41 = (cgc_size_t)(cgc_strlen ( tlv45 ) + 1); }
    {void * tlv44; tlv44 = (void *)(cgc_strlen ( tlv45 ) + 1); }
    {cgc_size_t tlv43; tlv43 = (cgc_size_t)(cgc_strlen ( tlv45 ) + 1); }
    {char * tlv47; tlv47 = (char *)(cgc_strlen ( tlv45 ) + 1); }
    {char * tlv48; tlv48 = (char *)(cgc_strlen ( tlv45 ) + 1); }
}
void fix_ingred_countyParsers_7_14(){
fix_ingred_countyParsers_7_14_1();
}
void fix_ingred_countyParsers_7_23_1(){
int endIndex;
    bzero(&endIndex,sizeof(int));
int startIndex;
    bzero(&startIndex,sizeof(int));
    {int * tlv6; tlv6 = (int *)(( endIndex - startIndex ) + 1); }
    {int * tlv8; tlv8 = (int *)(( endIndex - startIndex ) + 1); }
    {int tlv18; tlv18 = (int)(( endIndex - startIndex ) + 1); }
    {int tlv17; tlv17 = (int)(( endIndex - startIndex ) + 1); }
    {void * tlv11; tlv11 = (void *)(( endIndex - startIndex ) + 1); }
    {cgc_size_t tlv10; tlv10 = (cgc_size_t)(( endIndex - startIndex ) + 1); }
    {int tlv25; tlv25 = (int)(( endIndex - startIndex ) + 1); }
    {int tlv24; tlv24 = (int)(( endIndex - startIndex ) + 1); }
    {void * tlv13; tlv13 = (void *)(( endIndex - startIndex ) + 1); }
    {cgc_size_t tlv12; tlv12 = (cgc_size_t)(( endIndex - startIndex ) + 1); }
    {char tlv28; tlv28 = (char)(( endIndex - startIndex ) + 1); }
    {char tlv30; tlv30 = (char)(( endIndex - startIndex ) + 1); }
    {int tlv35; tlv35 = (int)(( endIndex - startIndex ) + 1); }
    {void * tlv15; tlv15 = (void *)(( endIndex - startIndex ) + 1); }
    {cgc_size_t tlv14; tlv14 = (cgc_size_t)(( endIndex - startIndex ) + 1); }
    {char * tlv45; tlv45 = (char *)(( endIndex - startIndex ) + 1); }
    {char * tlv46; tlv46 = (char *)(( endIndex - startIndex ) + 1); }
    {void * tlv42; tlv42 = (void *)(( endIndex - startIndex ) + 1); }
    {cgc_size_t tlv41; tlv41 = (cgc_size_t)(( endIndex - startIndex ) + 1); }
    {void * tlv44; tlv44 = (void *)(( endIndex - startIndex ) + 1); }
    {cgc_size_t tlv43; tlv43 = (cgc_size_t)(( endIndex - startIndex ) + 1); }
    {char * tlv47; tlv47 = (char *)(( endIndex - startIndex ) + 1); }
    {char * tlv48; tlv48 = (char *)(( endIndex - startIndex ) + 1); }
}
void fix_ingred_countyParsers_7_23(){
fix_ingred_countyParsers_7_23_1();
}
void fix_ingred_countyParsers_7_24_1(){
    {int * tlv6; tlv6 = (int *)('{'); }
    {int * tlv8; tlv8 = (int *)('{'); }
    {int tlv18; tlv18 = (int)('{'); }
    {int tlv17; tlv17 = (int)('{'); }
    {void * tlv11; tlv11 = (void *)('{'); }
    {cgc_size_t tlv10; tlv10 = (cgc_size_t)('{'); }
    {int tlv25; tlv25 = (int)('{'); }
    {int tlv24; tlv24 = (int)('{'); }
    {void * tlv13; tlv13 = (void *)('{'); }
    {cgc_size_t tlv12; tlv12 = (cgc_size_t)('{'); }
    {char tlv28; tlv28 = (char)('{'); }
    {char tlv30; tlv30 = (char)('{'); }
    {int tlv35; tlv35 = (int)('{'); }
    {void * tlv15; tlv15 = (void *)('{'); }
    {cgc_size_t tlv14; tlv14 = (cgc_size_t)('{'); }
    {char * tlv45; tlv45 = (char *)('{'); }
    {char * tlv46; tlv46 = (char *)('{'); }
    {void * tlv42; tlv42 = (void *)('{'); }
    {cgc_size_t tlv41; tlv41 = (cgc_size_t)('{'); }
    {void * tlv44; tlv44 = (void *)('{'); }
    {cgc_size_t tlv43; tlv43 = (cgc_size_t)('{'); }
    {char * tlv47; tlv47 = (char *)('{'); }
    {char * tlv48; tlv48 = (char *)('{'); }
}
void fix_ingred_countyParsers_7_24(){
fix_ingred_countyParsers_7_24_1();
}
void fix_ingred_countyParsers_7_26_1(){
    {int * tlv6; tlv6 = (int *)('#'); }
    {int * tlv8; tlv8 = (int *)('#'); }
    {int tlv18; tlv18 = (int)('#'); }
    {int tlv17; tlv17 = (int)('#'); }
    {void * tlv11; tlv11 = (void *)('#'); }
    {cgc_size_t tlv10; tlv10 = (cgc_size_t)('#'); }
    {int tlv25; tlv25 = (int)('#'); }
    {int tlv24; tlv24 = (int)('#'); }
    {void * tlv13; tlv13 = (void *)('#'); }
    {cgc_size_t tlv12; tlv12 = (cgc_size_t)('#'); }
    {char tlv28; tlv28 = (char)('#'); }
    {char tlv30; tlv30 = (char)('#'); }
    {int tlv35; tlv35 = (int)('#'); }
    {void * tlv15; tlv15 = (void *)('#'); }
    {cgc_size_t tlv14; tlv14 = (cgc_size_t)('#'); }
    {char * tlv45; tlv45 = (char *)('#'); }
    {char * tlv46; tlv46 = (char *)('#'); }
    {void * tlv42; tlv42 = (void *)('#'); }
    {cgc_size_t tlv41; tlv41 = (cgc_size_t)('#'); }
    {void * tlv44; tlv44 = (void *)('#'); }
    {cgc_size_t tlv43; tlv43 = (cgc_size_t)('#'); }
    {char * tlv47; tlv47 = (char *)('#'); }
    {char * tlv48; tlv48 = (char *)('#'); }
}
void fix_ingred_countyParsers_7_26(){
fix_ingred_countyParsers_7_26_1();
}
void fix_ingred_countyParsers_7_33_6(){
int tlv4;
    bzero(&tlv4,sizeof(int));
    {char * temp; temp = (char *)(tlv4); }
    {int * tlv6; tlv6 = (int *)(tlv4); }
    {int * tlv8; tlv8 = (int *)(tlv4); }
    {int tlv18; tlv18 = (int)(tlv4); }
    {int tlv17; tlv17 = (int)(tlv4); }
    {void * tlv11; tlv11 = (void *)(tlv4); }
    {cgc_size_t tlv10; tlv10 = (cgc_size_t)(tlv4); }
    {int tlv25; tlv25 = (int)(tlv4); }
    {int tlv24; tlv24 = (int)(tlv4); }
    {void * tlv13; tlv13 = (void *)(tlv4); }
    {cgc_size_t tlv12; tlv12 = (cgc_size_t)(tlv4); }
    {char tlv28; tlv28 = (char)(tlv4); }
    {char tlv30; tlv30 = (char)(tlv4); }
    {int tlv35; tlv35 = (int)(tlv4); }
    {void * tlv15; tlv15 = (void *)(tlv4); }
    {cgc_size_t tlv14; tlv14 = (cgc_size_t)(tlv4); }
    {char * tlv45; tlv45 = (char *)(tlv4); }
    {char * tlv46; tlv46 = (char *)(tlv4); }
    {void * tlv42; tlv42 = (void *)(tlv4); }
    {cgc_size_t tlv41; tlv41 = (cgc_size_t)(tlv4); }
    {void * tlv44; tlv44 = (void *)(tlv4); }
    {cgc_size_t tlv43; tlv43 = (cgc_size_t)(tlv4); }
    {char * tlv47; tlv47 = (char *)(tlv4); }
    {char * tlv48; tlv48 = (char *)(tlv4); }
}
void fix_ingred_countyParsers_7_33(){
fix_ingred_countyParsers_7_33_6();
}
void fix_ingred_countyParsers_7_35_1(){
char tlv48_ref;
    bzero(&tlv48_ref,1*sizeof(char));
char * tlv48 = &tlv48_ref;
    {int startIndex; startIndex = (int)(cgc_strlen ( tlv48 ) + 1); }
    {int endIndex; endIndex = (int)(cgc_strlen ( tlv48 ) + 1); }
    {char * temp; temp = (char *)(cgc_strlen ( tlv48 ) + 1); }
    {int lastGood; lastGood = (int)(cgc_strlen ( tlv48 ) + 1); }
    {int tlv1; tlv1 = (int)(cgc_strlen ( tlv48 ) + 1); }
    {int tlv2; tlv2 = (int)(cgc_strlen ( tlv48 ) + 1); }
    {int tlv3; tlv3 = (int)(cgc_strlen ( tlv48 ) + 1); }
    {int tlv4; tlv4 = (int)(cgc_strlen ( tlv48 ) + 1); }
    {int tlv5; tlv5 = (int)(cgc_strlen ( tlv48 ) + 1); }
    {int * tlv6; tlv6 = (int *)(cgc_strlen ( tlv48 ) + 1); }
    {int * tlv8; tlv8 = (int *)(cgc_strlen ( tlv48 ) + 1); }
    {int tlv18; tlv18 = (int)(cgc_strlen ( tlv48 ) + 1); }
    {int tlv17; tlv17 = (int)(cgc_strlen ( tlv48 ) + 1); }
    {void * tlv11; tlv11 = (void *)(cgc_strlen ( tlv48 ) + 1); }
    {cgc_size_t tlv10; tlv10 = (cgc_size_t)(cgc_strlen ( tlv48 ) + 1); }
    {int tlv25; tlv25 = (int)(cgc_strlen ( tlv48 ) + 1); }
    {int tlv24; tlv24 = (int)(cgc_strlen ( tlv48 ) + 1); }
    {void * tlv13; tlv13 = (void *)(cgc_strlen ( tlv48 ) + 1); }
    {cgc_size_t tlv12; tlv12 = (cgc_size_t)(cgc_strlen ( tlv48 ) + 1); }
    {char tlv28; tlv28 = (char)(cgc_strlen ( tlv48 ) + 1); }
    {char tlv30; tlv30 = (char)(cgc_strlen ( tlv48 ) + 1); }
    {int tlv35; tlv35 = (int)(cgc_strlen ( tlv48 ) + 1); }
    {int tlv34; tlv34 = (int)(cgc_strlen ( tlv48 ) + 1); }
    {void * tlv15; tlv15 = (void *)(cgc_strlen ( tlv48 ) + 1); }
    {cgc_size_t tlv14; tlv14 = (cgc_size_t)(cgc_strlen ( tlv48 ) + 1); }
    {char tlv39; tlv39 = (char)(cgc_strlen ( tlv48 ) + 1); }
    {char * tlv45; tlv45 = (char *)(cgc_strlen ( tlv48 ) + 1); }
    {char * tlv46; tlv46 = (char *)(cgc_strlen ( tlv48 ) + 1); }
    {void * tlv42; tlv42 = (void *)(cgc_strlen ( tlv48 ) + 1); }
    {cgc_size_t tlv41; tlv41 = (cgc_size_t)(cgc_strlen ( tlv48 ) + 1); }
    {void * tlv44; tlv44 = (void *)(cgc_strlen ( tlv48 ) + 1); }
    {cgc_size_t tlv43; tlv43 = (cgc_size_t)(cgc_strlen ( tlv48 ) + 1); }
    {char * tlv47; tlv47 = (char *)(cgc_strlen ( tlv48 ) + 1); }
}
void fix_ingred_countyParsers_7_35(){
fix_ingred_countyParsers_7_35_1();
}
void fix_ingred_countyParsers_7_37_1(){
char tlv46_ref;
    bzero(&tlv46_ref,1*sizeof(char));
char * tlv46 = &tlv46_ref;
    {int startIndex; startIndex = (int)(cgc_strlen ( tlv46 ) + 1); }
    {int endIndex; endIndex = (int)(cgc_strlen ( tlv46 ) + 1); }
    {char * temp; temp = (char *)(cgc_strlen ( tlv46 ) + 1); }
    {int lastGood; lastGood = (int)(cgc_strlen ( tlv46 ) + 1); }
    {int tlv1; tlv1 = (int)(cgc_strlen ( tlv46 ) + 1); }
    {int tlv2; tlv2 = (int)(cgc_strlen ( tlv46 ) + 1); }
    {int tlv3; tlv3 = (int)(cgc_strlen ( tlv46 ) + 1); }
    {int tlv4; tlv4 = (int)(cgc_strlen ( tlv46 ) + 1); }
    {int tlv5; tlv5 = (int)(cgc_strlen ( tlv46 ) + 1); }
    {int * tlv6; tlv6 = (int *)(cgc_strlen ( tlv46 ) + 1); }
    {int * tlv8; tlv8 = (int *)(cgc_strlen ( tlv46 ) + 1); }
    {int tlv18; tlv18 = (int)(cgc_strlen ( tlv46 ) + 1); }
    {int tlv17; tlv17 = (int)(cgc_strlen ( tlv46 ) + 1); }
    {void * tlv11; tlv11 = (void *)(cgc_strlen ( tlv46 ) + 1); }
    {cgc_size_t tlv10; tlv10 = (cgc_size_t)(cgc_strlen ( tlv46 ) + 1); }
    {int tlv25; tlv25 = (int)(cgc_strlen ( tlv46 ) + 1); }
    {int tlv24; tlv24 = (int)(cgc_strlen ( tlv46 ) + 1); }
    {void * tlv13; tlv13 = (void *)(cgc_strlen ( tlv46 ) + 1); }
    {cgc_size_t tlv12; tlv12 = (cgc_size_t)(cgc_strlen ( tlv46 ) + 1); }
    {char tlv28; tlv28 = (char)(cgc_strlen ( tlv46 ) + 1); }
    {char tlv30; tlv30 = (char)(cgc_strlen ( tlv46 ) + 1); }
    {int tlv35; tlv35 = (int)(cgc_strlen ( tlv46 ) + 1); }
    {int tlv34; tlv34 = (int)(cgc_strlen ( tlv46 ) + 1); }
    {void * tlv15; tlv15 = (void *)(cgc_strlen ( tlv46 ) + 1); }
    {cgc_size_t tlv14; tlv14 = (cgc_size_t)(cgc_strlen ( tlv46 ) + 1); }
    {char tlv39; tlv39 = (char)(cgc_strlen ( tlv46 ) + 1); }
    {char * tlv45; tlv45 = (char *)(cgc_strlen ( tlv46 ) + 1); }
    {void * tlv42; tlv42 = (void *)(cgc_strlen ( tlv46 ) + 1); }
    {cgc_size_t tlv41; tlv41 = (cgc_size_t)(cgc_strlen ( tlv46 ) + 1); }
    {void * tlv44; tlv44 = (void *)(cgc_strlen ( tlv46 ) + 1); }
    {cgc_size_t tlv43; tlv43 = (cgc_size_t)(cgc_strlen ( tlv46 ) + 1); }
    {char * tlv47; tlv47 = (char *)(cgc_strlen ( tlv46 ) + 1); }
    {char * tlv48; tlv48 = (char *)(cgc_strlen ( tlv46 ) + 1); }
}
void fix_ingred_countyParsers_7_37(){
fix_ingred_countyParsers_7_37_1();
}
void fix_ingred_countyParsers_7_38_1(){
    {char * temp; temp = (char *)('}'); }
    {int * tlv6; tlv6 = (int *)('}'); }
    {int * tlv8; tlv8 = (int *)('}'); }
    {int tlv18; tlv18 = (int)('}'); }
    {int tlv17; tlv17 = (int)('}'); }
    {void * tlv11; tlv11 = (void *)('}'); }
    {cgc_size_t tlv10; tlv10 = (cgc_size_t)('}'); }
    {int tlv25; tlv25 = (int)('}'); }
    {int tlv24; tlv24 = (int)('}'); }
    {void * tlv13; tlv13 = (void *)('}'); }
    {cgc_size_t tlv12; tlv12 = (cgc_size_t)('}'); }
    {char tlv28; tlv28 = (char)('}'); }
    {char tlv30; tlv30 = (char)('}'); }
    {int tlv35; tlv35 = (int)('}'); }
    {void * tlv15; tlv15 = (void *)('}'); }
    {cgc_size_t tlv14; tlv14 = (cgc_size_t)('}'); }
    {char * tlv45; tlv45 = (char *)('}'); }
    {char * tlv46; tlv46 = (char *)('}'); }
    {void * tlv42; tlv42 = (void *)('}'); }
    {cgc_size_t tlv41; tlv41 = (cgc_size_t)('}'); }
    {void * tlv44; tlv44 = (void *)('}'); }
    {cgc_size_t tlv43; tlv43 = (cgc_size_t)('}'); }
    {char * tlv47; tlv47 = (char *)('}'); }
    {char * tlv48; tlv48 = (char *)('}'); }
}
void fix_ingred_countyParsers_7_38(){
fix_ingred_countyParsers_7_38_1();
}
void fix_ingred_countyParsers_7(){
fix_ingred_countyParsers_7_0();
fix_ingred_countyParsers_7_2();
fix_ingred_countyParsers_7_4();
fix_ingred_countyParsers_7_6();
fix_ingred_countyParsers_7_10();
fix_ingred_countyParsers_7_11();
fix_ingred_countyParsers_7_12();
fix_ingred_countyParsers_7_14();
fix_ingred_countyParsers_7_23();
fix_ingred_countyParsers_7_24();
fix_ingred_countyParsers_7_26();
fix_ingred_countyParsers_7_33();
fix_ingred_countyParsers_7_35();
fix_ingred_countyParsers_7_37();
fix_ingred_countyParsers_7_38();
}
void fix_ingred_countyParsers_8_0_0(){
    {char * seat; seat = (char *)(NULL); }
    {int tlv23; tlv23 = (int)(NULL); }
    {int tlv22; tlv22 = (int)(NULL); }
    {char tlv25; tlv25 = (char)(NULL); }
    {char tlv27; tlv27 = (char)(NULL); }
    {int tlv32; tlv32 = (int)(NULL); }
    {int tlv31; tlv31 = (int)(NULL); }
    {char tlv36; tlv36 = (char)(NULL); }
    {char * tlv44; tlv44 = (char *)(NULL); }
    {void * tlv39; tlv39 = (void *)(NULL); }
    {cgc_size_t tlv38; tlv38 = (cgc_size_t)(NULL); }
    {void * tlv41; tlv41 = (void *)(NULL); }
    {cgc_size_t tlv40; tlv40 = (cgc_size_t)(NULL); }
    {void * tlv43; tlv43 = (void *)(NULL); }
    {cgc_size_t tlv42; tlv42 = (cgc_size_t)(NULL); }
}
void fix_ingred_countyParsers_8_0_1(){
    {char * seat; seat = (char *)(0); }
    {int tlv23; tlv23 = (int)(0); }
    {int tlv22; tlv22 = (int)(0); }
    {char tlv25; tlv25 = (char)(0); }
    {int tlv32; tlv32 = (int)(0); }
    {int tlv31; tlv31 = (int)(0); }
    {char tlv36; tlv36 = (char)(0); }
    {char * tlv44; tlv44 = (char *)(0); }
    {void * tlv39; tlv39 = (void *)(0); }
    {void * tlv41; tlv41 = (void *)(0); }
    {cgc_size_t tlv40; tlv40 = (cgc_size_t)(0); }
}
void fix_ingred_countyParsers_8_0(){
fix_ingred_countyParsers_8_0_0();
fix_ingred_countyParsers_8_0_1();
}
void fix_ingred_countyParsers_8_2_1(){
int lastGood;
    bzero(&lastGood,sizeof(int));
    {char * seat; seat = (char *)(& lastGood); }
    {int tlv23; tlv23 = (int)(& lastGood); }
    {int tlv22; tlv22 = (int)(& lastGood); }
    {char tlv25; tlv25 = (char)(& lastGood); }
    {char tlv27; tlv27 = (char)(& lastGood); }
    {int tlv32; tlv32 = (int)(& lastGood); }
    {int tlv31; tlv31 = (int)(& lastGood); }
    {char tlv36; tlv36 = (char)(& lastGood); }
    {char * tlv44; tlv44 = (char *)(& lastGood); }
    {void * tlv39; tlv39 = (void *)(& lastGood); }
    {cgc_size_t tlv38; tlv38 = (cgc_size_t)(& lastGood); }
    {void * tlv41; tlv41 = (void *)(& lastGood); }
    {cgc_size_t tlv40; tlv40 = (cgc_size_t)(& lastGood); }
    {void * tlv43; tlv43 = (void *)(& lastGood); }
    {cgc_size_t tlv42; tlv42 = (cgc_size_t)(& lastGood); }
}
void fix_ingred_countyParsers_8_2(){
fix_ingred_countyParsers_8_2_1();
}
void fix_ingred_countyParsers_8_4_1(){
int startIndex;
    bzero(&startIndex,sizeof(int));
    {char * seat; seat = (char *)(& startIndex); }
    {int tlv16; tlv16 = (int)(& startIndex); }
    {int tlv23; tlv23 = (int)(& startIndex); }
    {int tlv22; tlv22 = (int)(& startIndex); }
    {char tlv25; tlv25 = (char)(& startIndex); }
    {char tlv27; tlv27 = (char)(& startIndex); }
    {int tlv32; tlv32 = (int)(& startIndex); }
    {int tlv31; tlv31 = (int)(& startIndex); }
    {char tlv36; tlv36 = (char)(& startIndex); }
    {char * tlv44; tlv44 = (char *)(& startIndex); }
    {void * tlv39; tlv39 = (void *)(& startIndex); }
    {cgc_size_t tlv38; tlv38 = (cgc_size_t)(& startIndex); }
    {void * tlv41; tlv41 = (void *)(& startIndex); }
    {cgc_size_t tlv40; tlv40 = (cgc_size_t)(& startIndex); }
    {void * tlv43; tlv43 = (void *)(& startIndex); }
    {cgc_size_t tlv42; tlv42 = (cgc_size_t)(& startIndex); }
}
void fix_ingred_countyParsers_8_4(){
fix_ingred_countyParsers_8_4_1();
}
void fix_ingred_countyParsers_8_6_5(){
int endIndex;
    bzero(&endIndex,sizeof(int));
int startIndex;
    bzero(&startIndex,sizeof(int));
    {char * seat; seat = (char *)(endIndex); }
    {int tlv23; tlv23 = (int)(endIndex); }
    {int tlv22; tlv22 = (int)(endIndex); }
    {char tlv25; tlv25 = (char)(endIndex); }
    {char tlv27; tlv27 = (char)(endIndex); }
    {int tlv32; tlv32 = (int)(endIndex); }
    {int tlv31; tlv31 = (int)(endIndex); }
    {char tlv36; tlv36 = (char)(endIndex); }
    {char * tlv44; tlv44 = (char *)(endIndex); }
    {void * tlv39; tlv39 = (void *)(endIndex); }
    {cgc_size_t tlv38; tlv38 = (cgc_size_t)(endIndex); }
    {void * tlv41; tlv41 = (void *)(endIndex); }
    {cgc_size_t tlv40; tlv40 = (cgc_size_t)(endIndex); }
    {void * tlv43; tlv43 = (void *)(endIndex); }
    {cgc_size_t tlv42; tlv42 = (cgc_size_t)(endIndex); }
}
void fix_ingred_countyParsers_8_6_6(){
int endIndex;
    bzero(&endIndex,sizeof(int));
int startIndex;
    bzero(&startIndex,sizeof(int));
    {char * seat; seat = (char *)(- 1); }
    {int tlv16; tlv16 = (int)(- 1); }
    {int tlv23; tlv23 = (int)(- 1); }
    {int tlv22; tlv22 = (int)(- 1); }
    {char tlv25; tlv25 = (char)(- 1); }
    {char tlv27; tlv27 = (char)(- 1); }
    {int tlv32; tlv32 = (int)(- 1); }
    {int tlv31; tlv31 = (int)(- 1); }
    {char tlv36; tlv36 = (char)(- 1); }
    {char * tlv44; tlv44 = (char *)(- 1); }
    {void * tlv39; tlv39 = (void *)(- 1); }
    {cgc_size_t tlv38; tlv38 = (cgc_size_t)(- 1); }
    {void * tlv41; tlv41 = (void *)(- 1); }
    {cgc_size_t tlv40; tlv40 = (cgc_size_t)(- 1); }
    {void * tlv43; tlv43 = (void *)(- 1); }
    {cgc_size_t tlv42; tlv42 = (cgc_size_t)(- 1); }
}
void fix_ingred_countyParsers_8_6_7(){
int endIndex;
    bzero(&endIndex,sizeof(int));
int startIndex;
    bzero(&startIndex,sizeof(int));
    {char * seat; seat = (char *)(startIndex); }
    {int tlv23; tlv23 = (int)(startIndex); }
    {int tlv22; tlv22 = (int)(startIndex); }
    {char tlv25; tlv25 = (char)(startIndex); }
    {char tlv27; tlv27 = (char)(startIndex); }
    {int tlv32; tlv32 = (int)(startIndex); }
    {int tlv31; tlv31 = (int)(startIndex); }
    {char tlv36; tlv36 = (char)(startIndex); }
    {char * tlv44; tlv44 = (char *)(startIndex); }
    {void * tlv39; tlv39 = (void *)(startIndex); }
    {cgc_size_t tlv38; tlv38 = (cgc_size_t)(startIndex); }
    {void * tlv41; tlv41 = (void *)(startIndex); }
    {cgc_size_t tlv40; tlv40 = (cgc_size_t)(startIndex); }
    {void * tlv43; tlv43 = (void *)(startIndex); }
    {cgc_size_t tlv42; tlv42 = (cgc_size_t)(startIndex); }
}
void fix_ingred_countyParsers_8_6(){
fix_ingred_countyParsers_8_6_5();
fix_ingred_countyParsers_8_6_6();
fix_ingred_countyParsers_8_6_7();
}
void fix_ingred_countyParsers_8_10_5(){
int tlv1;
    bzero(&tlv1,sizeof(int));
    {char * seat; seat = (char *)(tlv1); }
    {int tlv15; tlv15 = (int)(tlv1); }
    {int tlv23; tlv23 = (int)(tlv1); }
    {int tlv22; tlv22 = (int)(tlv1); }
    {char tlv25; tlv25 = (char)(tlv1); }
    {int tlv32; tlv32 = (int)(tlv1); }
    {int tlv31; tlv31 = (int)(tlv1); }
    {char tlv36; tlv36 = (char)(tlv1); }
    {char * tlv44; tlv44 = (char *)(tlv1); }
    {void * tlv39; tlv39 = (void *)(tlv1); }
    {void * tlv41; tlv41 = (void *)(tlv1); }
    {cgc_size_t tlv40; tlv40 = (cgc_size_t)(tlv1); }
}
void fix_ingred_countyParsers_8_10(){
fix_ingred_countyParsers_8_10_5();
}
void fix_ingred_countyParsers_8_11_0(){
char temp_ref;
    bzero(&temp_ref,1*sizeof(char));
char * temp = &temp_ref;
    {char * seat; seat = (char *)(temp); }
    {int tlv15; tlv15 = (int)(temp); }
    {int tlv23; tlv23 = (int)(temp); }
    {int tlv22; tlv22 = (int)(temp); }
    {char tlv25; tlv25 = (char)(temp); }
    {char tlv27; tlv27 = (char)(temp); }
    {int tlv32; tlv32 = (int)(temp); }
    {int tlv31; tlv31 = (int)(temp); }
    {char tlv36; tlv36 = (char)(temp); }
    {char * tlv44; tlv44 = (char *)(temp); }
    {void * tlv39; tlv39 = (void *)(temp); }
    {cgc_size_t tlv38; tlv38 = (cgc_size_t)(temp); }
    {void * tlv41; tlv41 = (void *)(temp); }
    {cgc_size_t tlv40; tlv40 = (cgc_size_t)(temp); }
    {void * tlv43; tlv43 = (void *)(temp); }
    {cgc_size_t tlv42; tlv42 = (cgc_size_t)(temp); }
}
void fix_ingred_countyParsers_8_11(){
fix_ingred_countyParsers_8_11_0();
}
void fix_ingred_countyParsers_8_12_0(){
char temp_ref;
    bzero(&temp_ref,1*sizeof(char));
char * temp = &temp_ref;
char tlv46_ref;
    bzero(&tlv46_ref,1*sizeof(char));
char * tlv46 = &tlv46_ref;
    {char * seat; seat = (char *)(temp); }
    {int tlv15; tlv15 = (int)(temp); }
    {int tlv23; tlv23 = (int)(temp); }
    {int tlv22; tlv22 = (int)(temp); }
    {char tlv25; tlv25 = (char)(temp); }
    {char tlv27; tlv27 = (char)(temp); }
    {int tlv32; tlv32 = (int)(temp); }
    {int tlv31; tlv31 = (int)(temp); }
    {char tlv36; tlv36 = (char)(temp); }
    {char * tlv44; tlv44 = (char *)(temp); }
    {void * tlv39; tlv39 = (void *)(temp); }
    {cgc_size_t tlv38; tlv38 = (cgc_size_t)(temp); }
    {void * tlv41; tlv41 = (void *)(temp); }
    {cgc_size_t tlv40; tlv40 = (cgc_size_t)(temp); }
    {void * tlv43; tlv43 = (void *)(temp); }
    {cgc_size_t tlv42; tlv42 = (cgc_size_t)(temp); }
}
void fix_ingred_countyParsers_8_12_1(){
char temp_ref;
    bzero(&temp_ref,1*sizeof(char));
char * temp = &temp_ref;
char tlv46_ref;
    bzero(&tlv46_ref,1*sizeof(char));
char * tlv46 = &tlv46_ref;
    {char * seat; seat = (char *)(cgc_strlen ( tlv46 ) + 1); }
    {int tlv16; tlv16 = (int)(cgc_strlen ( tlv46 ) + 1); }
    {int tlv15; tlv15 = (int)(cgc_strlen ( tlv46 ) + 1); }
    {int tlv23; tlv23 = (int)(cgc_strlen ( tlv46 ) + 1); }
    {int tlv22; tlv22 = (int)(cgc_strlen ( tlv46 ) + 1); }
    {char tlv25; tlv25 = (char)(cgc_strlen ( tlv46 ) + 1); }
    {char tlv27; tlv27 = (char)(cgc_strlen ( tlv46 ) + 1); }
    {int tlv32; tlv32 = (int)(cgc_strlen ( tlv46 ) + 1); }
    {int tlv31; tlv31 = (int)(cgc_strlen ( tlv46 ) + 1); }
    {char tlv36; tlv36 = (char)(cgc_strlen ( tlv46 ) + 1); }
    {char * tlv44; tlv44 = (char *)(cgc_strlen ( tlv46 ) + 1); }
    {void * tlv39; tlv39 = (void *)(cgc_strlen ( tlv46 ) + 1); }
    {cgc_size_t tlv38; tlv38 = (cgc_size_t)(cgc_strlen ( tlv46 ) + 1); }
    {void * tlv41; tlv41 = (void *)(cgc_strlen ( tlv46 ) + 1); }
    {cgc_size_t tlv40; tlv40 = (cgc_size_t)(cgc_strlen ( tlv46 ) + 1); }
    {void * tlv43; tlv43 = (void *)(cgc_strlen ( tlv46 ) + 1); }
    {cgc_size_t tlv42; tlv42 = (cgc_size_t)(cgc_strlen ( tlv46 ) + 1); }
}
void fix_ingred_countyParsers_8_12(){
fix_ingred_countyParsers_8_12_0();
fix_ingred_countyParsers_8_12_1();
}
void fix_ingred_countyParsers_8_14_1(){
char tlv44_ref;
    bzero(&tlv44_ref,1*sizeof(char));
char * tlv44 = &tlv44_ref;
    {char * seat; seat = (char *)(cgc_strlen ( tlv44 ) + 1); }
    {int startIndex; startIndex = (int)(cgc_strlen ( tlv44 ) + 1); }
    {int endIndex; endIndex = (int)(cgc_strlen ( tlv44 ) + 1); }
    {char * temp; temp = (char *)(cgc_strlen ( tlv44 ) + 1); }
    {int lastGood; lastGood = (int)(cgc_strlen ( tlv44 ) + 1); }
    {int tlv1; tlv1 = (int)(cgc_strlen ( tlv44 ) + 1); }
    {int tlv2; tlv2 = (int)(cgc_strlen ( tlv44 ) + 1); }
    {int tlv3; tlv3 = (int)(cgc_strlen ( tlv44 ) + 1); }
    {int tlv4; tlv4 = (int)(cgc_strlen ( tlv44 ) + 1); }
    {int tlv5; tlv5 = (int)(cgc_strlen ( tlv44 ) + 1); }
    {int * tlv6; tlv6 = (int *)(cgc_strlen ( tlv44 ) + 1); }
    {int * tlv8; tlv8 = (int *)(cgc_strlen ( tlv44 ) + 1); }
    {int tlv16; tlv16 = (int)(cgc_strlen ( tlv44 ) + 1); }
    {int tlv15; tlv15 = (int)(cgc_strlen ( tlv44 ) + 1); }
    {void * tlv11; tlv11 = (void *)(cgc_strlen ( tlv44 ) + 1); }
    {cgc_size_t tlv10; tlv10 = (cgc_size_t)(cgc_strlen ( tlv44 ) + 1); }
    {int tlv23; tlv23 = (int)(cgc_strlen ( tlv44 ) + 1); }
    {int tlv22; tlv22 = (int)(cgc_strlen ( tlv44 ) + 1); }
    {char tlv25; tlv25 = (char)(cgc_strlen ( tlv44 ) + 1); }
    {char tlv27; tlv27 = (char)(cgc_strlen ( tlv44 ) + 1); }
    {int tlv32; tlv32 = (int)(cgc_strlen ( tlv44 ) + 1); }
    {int tlv31; tlv31 = (int)(cgc_strlen ( tlv44 ) + 1); }
    {void * tlv13; tlv13 = (void *)(cgc_strlen ( tlv44 ) + 1); }
    {cgc_size_t tlv12; tlv12 = (cgc_size_t)(cgc_strlen ( tlv44 ) + 1); }
    {char tlv36; tlv36 = (char)(cgc_strlen ( tlv44 ) + 1); }
    {char * tlv45; tlv45 = (char *)(cgc_strlen ( tlv44 ) + 1); }
    {void * tlv39; tlv39 = (void *)(cgc_strlen ( tlv44 ) + 1); }
    {cgc_size_t tlv38; tlv38 = (cgc_size_t)(cgc_strlen ( tlv44 ) + 1); }
    {void * tlv41; tlv41 = (void *)(cgc_strlen ( tlv44 ) + 1); }
    {cgc_size_t tlv40; tlv40 = (cgc_size_t)(cgc_strlen ( tlv44 ) + 1); }
    {void * tlv43; tlv43 = (void *)(cgc_strlen ( tlv44 ) + 1); }
    {cgc_size_t tlv42; tlv42 = (cgc_size_t)(cgc_strlen ( tlv44 ) + 1); }
    {char * tlv46; tlv46 = (char *)(cgc_strlen ( tlv44 ) + 1); }
    {char * tlv47; tlv47 = (char *)(cgc_strlen ( tlv44 ) + 1); }
    {char * tlv48; tlv48 = (char *)(cgc_strlen ( tlv44 ) + 1); }
}
void fix_ingred_countyParsers_8_14(){
fix_ingred_countyParsers_8_14_1();
}
void fix_ingred_countyParsers_8_21_5(){
char seat_ref;
    bzero(&seat_ref,1*sizeof(char));
char * seat = &seat_ref;
    {int startIndex; startIndex = (int)(seat); }
    {int endIndex; endIndex = (int)(seat); }
    {char * temp; temp = (char *)(seat); }
    {int lastGood; lastGood = (int)(seat); }
    {int tlv1; tlv1 = (int)(seat); }
    {int tlv2; tlv2 = (int)(seat); }
    {int tlv3; tlv3 = (int)(seat); }
    {int tlv4; tlv4 = (int)(seat); }
    {int tlv5; tlv5 = (int)(seat); }
    {int * tlv6; tlv6 = (int *)(seat); }
    {int * tlv8; tlv8 = (int *)(seat); }
    {int tlv16; tlv16 = (int)(seat); }
    {int tlv15; tlv15 = (int)(seat); }
    {void * tlv11; tlv11 = (void *)(seat); }
    {cgc_size_t tlv10; tlv10 = (cgc_size_t)(seat); }
    {int tlv23; tlv23 = (int)(seat); }
    {int tlv22; tlv22 = (int)(seat); }
    {char tlv25; tlv25 = (char)(seat); }
    {char tlv27; tlv27 = (char)(seat); }
    {int tlv32; tlv32 = (int)(seat); }
    {int tlv31; tlv31 = (int)(seat); }
    {void * tlv13; tlv13 = (void *)(seat); }
    {cgc_size_t tlv12; tlv12 = (cgc_size_t)(seat); }
    {char tlv36; tlv36 = (char)(seat); }
    {char * tlv44; tlv44 = (char *)(seat); }
    {char * tlv45; tlv45 = (char *)(seat); }
    {void * tlv39; tlv39 = (void *)(seat); }
    {cgc_size_t tlv38; tlv38 = (cgc_size_t)(seat); }
    {void * tlv41; tlv41 = (void *)(seat); }
    {cgc_size_t tlv40; tlv40 = (cgc_size_t)(seat); }
    {void * tlv43; tlv43 = (void *)(seat); }
    {cgc_size_t tlv42; tlv42 = (cgc_size_t)(seat); }
    {char * tlv46; tlv46 = (char *)(seat); }
    {char * tlv47; tlv47 = (char *)(seat); }
    {char * tlv48; tlv48 = (char *)(seat); }
}
void fix_ingred_countyParsers_8_21(){
fix_ingred_countyParsers_8_21_5();
}
void fix_ingred_countyParsers_8_22_1(){
    {char * seat; seat = (char *)('{'); }
    {int tlv16; tlv16 = (int)('{'); }
    {int tlv23; tlv23 = (int)('{'); }
    {int tlv22; tlv22 = (int)('{'); }
    {char tlv25; tlv25 = (char)('{'); }
    {char tlv27; tlv27 = (char)('{'); }
    {int tlv32; tlv32 = (int)('{'); }
    {int tlv31; tlv31 = (int)('{'); }
    {char tlv36; tlv36 = (char)('{'); }
    {char * tlv44; tlv44 = (char *)('{'); }
    {void * tlv39; tlv39 = (void *)('{'); }
    {cgc_size_t tlv38; tlv38 = (cgc_size_t)('{'); }
    {void * tlv41; tlv41 = (void *)('{'); }
    {cgc_size_t tlv40; tlv40 = (cgc_size_t)('{'); }
    {void * tlv43; tlv43 = (void *)('{'); }
    {cgc_size_t tlv42; tlv42 = (cgc_size_t)('{'); }
}
void fix_ingred_countyParsers_8_22(){
fix_ingred_countyParsers_8_22_1();
}
void fix_ingred_countyParsers_8_24_1(){
    {char * seat; seat = (char *)('#'); }
    {int tlv16; tlv16 = (int)('#'); }
    {int tlv23; tlv23 = (int)('#'); }
    {int tlv22; tlv22 = (int)('#'); }
    {char tlv25; tlv25 = (char)('#'); }
    {char tlv27; tlv27 = (char)('#'); }
    {int tlv32; tlv32 = (int)('#'); }
    {int tlv31; tlv31 = (int)('#'); }
    {char tlv36; tlv36 = (char)('#'); }
    {char * tlv44; tlv44 = (char *)('#'); }
    {void * tlv39; tlv39 = (void *)('#'); }
    {cgc_size_t tlv38; tlv38 = (cgc_size_t)('#'); }
    {void * tlv41; tlv41 = (void *)('#'); }
    {cgc_size_t tlv40; tlv40 = (cgc_size_t)('#'); }
    {void * tlv43; tlv43 = (void *)('#'); }
    {cgc_size_t tlv42; tlv42 = (cgc_size_t)('#'); }
}
void fix_ingred_countyParsers_8_24(){
fix_ingred_countyParsers_8_24_1();
}
void fix_ingred_countyParsers_8_33_5(){
int tlv4;
    bzero(&tlv4,sizeof(int));
    {char * seat; seat = (char *)(tlv4); }
    {int tlv16; tlv16 = (int)(tlv4); }
    {int tlv23; tlv23 = (int)(tlv4); }
    {int tlv22; tlv22 = (int)(tlv4); }
    {char tlv25; tlv25 = (char)(tlv4); }
    {char tlv27; tlv27 = (char)(tlv4); }
    {int tlv32; tlv32 = (int)(tlv4); }
    {int tlv31; tlv31 = (int)(tlv4); }
    {char tlv36; tlv36 = (char)(tlv4); }
    {char * tlv44; tlv44 = (char *)(tlv4); }
    {void * tlv39; tlv39 = (void *)(tlv4); }
    {cgc_size_t tlv38; tlv38 = (cgc_size_t)(tlv4); }
    {void * tlv41; tlv41 = (void *)(tlv4); }
    {cgc_size_t tlv40; tlv40 = (cgc_size_t)(tlv4); }
    {void * tlv43; tlv43 = (void *)(tlv4); }
    {cgc_size_t tlv42; tlv42 = (cgc_size_t)(tlv4); }
}
void fix_ingred_countyParsers_8_33(){
fix_ingred_countyParsers_8_33_5();
}
void fix_ingred_countyParsers_8_35_1(){
char tlv47_ref;
    bzero(&tlv47_ref,1*sizeof(char));
char * tlv47 = &tlv47_ref;
    {char * seat; seat = (char *)(cgc_strlen ( tlv47 ) + 1); }
    {int tlv16; tlv16 = (int)(cgc_strlen ( tlv47 ) + 1); }
    {int tlv15; tlv15 = (int)(cgc_strlen ( tlv47 ) + 1); }
    {int tlv23; tlv23 = (int)(cgc_strlen ( tlv47 ) + 1); }
    {int tlv22; tlv22 = (int)(cgc_strlen ( tlv47 ) + 1); }
    {char tlv25; tlv25 = (char)(cgc_strlen ( tlv47 ) + 1); }
    {char tlv27; tlv27 = (char)(cgc_strlen ( tlv47 ) + 1); }
    {int tlv32; tlv32 = (int)(cgc_strlen ( tlv47 ) + 1); }
    {int tlv31; tlv31 = (int)(cgc_strlen ( tlv47 ) + 1); }
    {char tlv36; tlv36 = (char)(cgc_strlen ( tlv47 ) + 1); }
    {char * tlv44; tlv44 = (char *)(cgc_strlen ( tlv47 ) + 1); }
    {void * tlv39; tlv39 = (void *)(cgc_strlen ( tlv47 ) + 1); }
    {cgc_size_t tlv38; tlv38 = (cgc_size_t)(cgc_strlen ( tlv47 ) + 1); }
    {void * tlv41; tlv41 = (void *)(cgc_strlen ( tlv47 ) + 1); }
    {cgc_size_t tlv40; tlv40 = (cgc_size_t)(cgc_strlen ( tlv47 ) + 1); }
    {void * tlv43; tlv43 = (void *)(cgc_strlen ( tlv47 ) + 1); }
    {cgc_size_t tlv42; tlv42 = (cgc_size_t)(cgc_strlen ( tlv47 ) + 1); }
}
void fix_ingred_countyParsers_8_35(){
fix_ingred_countyParsers_8_35_1();
}
void fix_ingred_countyParsers_8_37_1(){
char tlv45_ref;
    bzero(&tlv45_ref,1*sizeof(char));
char * tlv45 = &tlv45_ref;
    {char * seat; seat = (char *)(cgc_strlen ( tlv45 ) + 1); }
    {int tlv16; tlv16 = (int)(cgc_strlen ( tlv45 ) + 1); }
    {int tlv15; tlv15 = (int)(cgc_strlen ( tlv45 ) + 1); }
    {int tlv23; tlv23 = (int)(cgc_strlen ( tlv45 ) + 1); }
    {int tlv22; tlv22 = (int)(cgc_strlen ( tlv45 ) + 1); }
    {char tlv25; tlv25 = (char)(cgc_strlen ( tlv45 ) + 1); }
    {char tlv27; tlv27 = (char)(cgc_strlen ( tlv45 ) + 1); }
    {int tlv32; tlv32 = (int)(cgc_strlen ( tlv45 ) + 1); }
    {int tlv31; tlv31 = (int)(cgc_strlen ( tlv45 ) + 1); }
    {char tlv36; tlv36 = (char)(cgc_strlen ( tlv45 ) + 1); }
    {char * tlv44; tlv44 = (char *)(cgc_strlen ( tlv45 ) + 1); }
    {void * tlv39; tlv39 = (void *)(cgc_strlen ( tlv45 ) + 1); }
    {cgc_size_t tlv38; tlv38 = (cgc_size_t)(cgc_strlen ( tlv45 ) + 1); }
    {void * tlv41; tlv41 = (void *)(cgc_strlen ( tlv45 ) + 1); }
    {cgc_size_t tlv40; tlv40 = (cgc_size_t)(cgc_strlen ( tlv45 ) + 1); }
    {void * tlv43; tlv43 = (void *)(cgc_strlen ( tlv45 ) + 1); }
    {cgc_size_t tlv42; tlv42 = (cgc_size_t)(cgc_strlen ( tlv45 ) + 1); }
}
void fix_ingred_countyParsers_8_37(){
fix_ingred_countyParsers_8_37_1();
}
void fix_ingred_countyParsers_8_38_1(){
    {char * seat; seat = (char *)('}'); }
    {int tlv16; tlv16 = (int)('}'); }
    {int tlv23; tlv23 = (int)('}'); }
    {int tlv22; tlv22 = (int)('}'); }
    {char tlv25; tlv25 = (char)('}'); }
    {char tlv27; tlv27 = (char)('}'); }
    {int tlv32; tlv32 = (int)('}'); }
    {int tlv31; tlv31 = (int)('}'); }
    {char tlv36; tlv36 = (char)('}'); }
    {char * tlv44; tlv44 = (char *)('}'); }
    {void * tlv39; tlv39 = (void *)('}'); }
    {cgc_size_t tlv38; tlv38 = (cgc_size_t)('}'); }
    {void * tlv41; tlv41 = (void *)('}'); }
    {cgc_size_t tlv40; tlv40 = (cgc_size_t)('}'); }
    {void * tlv43; tlv43 = (void *)('}'); }
    {cgc_size_t tlv42; tlv42 = (cgc_size_t)('}'); }
}
void fix_ingred_countyParsers_8_38(){
fix_ingred_countyParsers_8_38_1();
}
void fix_ingred_countyParsers_8_41_0(){
char seat_ref;
    bzero(&seat_ref,1*sizeof(char));
char * seat = &seat_ref;
    {int startIndex; startIndex = (int)(seat); }
    {int endIndex; endIndex = (int)(seat); }
    {char * temp; temp = (char *)(seat); }
    {int lastGood; lastGood = (int)(seat); }
    {int tlv1; tlv1 = (int)(seat); }
    {int tlv2; tlv2 = (int)(seat); }
    {int tlv3; tlv3 = (int)(seat); }
    {int tlv4; tlv4 = (int)(seat); }
    {int tlv5; tlv5 = (int)(seat); }
    {int * tlv6; tlv6 = (int *)(seat); }
    {int * tlv8; tlv8 = (int *)(seat); }
    {int tlv16; tlv16 = (int)(seat); }
    {int tlv15; tlv15 = (int)(seat); }
    {void * tlv11; tlv11 = (void *)(seat); }
    {cgc_size_t tlv10; tlv10 = (cgc_size_t)(seat); }
    {int tlv23; tlv23 = (int)(seat); }
    {int tlv22; tlv22 = (int)(seat); }
    {char tlv25; tlv25 = (char)(seat); }
    {char tlv27; tlv27 = (char)(seat); }
    {int tlv32; tlv32 = (int)(seat); }
    {int tlv31; tlv31 = (int)(seat); }
    {void * tlv13; tlv13 = (void *)(seat); }
    {cgc_size_t tlv12; tlv12 = (cgc_size_t)(seat); }
    {char tlv36; tlv36 = (char)(seat); }
    {char * tlv44; tlv44 = (char *)(seat); }
    {char * tlv45; tlv45 = (char *)(seat); }
    {void * tlv39; tlv39 = (void *)(seat); }
    {cgc_size_t tlv38; tlv38 = (cgc_size_t)(seat); }
    {void * tlv41; tlv41 = (void *)(seat); }
    {cgc_size_t tlv40; tlv40 = (cgc_size_t)(seat); }
    {void * tlv43; tlv43 = (void *)(seat); }
    {cgc_size_t tlv42; tlv42 = (cgc_size_t)(seat); }
    {char * tlv46; tlv46 = (char *)(seat); }
    {char * tlv47; tlv47 = (char *)(seat); }
    {char * tlv48; tlv48 = (char *)(seat); }
}
void fix_ingred_countyParsers_8_41(){
fix_ingred_countyParsers_8_41_0();
}
void fix_ingred_countyParsers_8_42_1(){
char tlv48_ref;
    bzero(&tlv48_ref,1*sizeof(char));
char * tlv48 = &tlv48_ref;
    {char * seat; seat = (char *)(cgc_strlen ( tlv48 ) + 1); }
    {int tlv16; tlv16 = (int)(cgc_strlen ( tlv48 ) + 1); }
    {int tlv15; tlv15 = (int)(cgc_strlen ( tlv48 ) + 1); }
    {int tlv23; tlv23 = (int)(cgc_strlen ( tlv48 ) + 1); }
    {int tlv22; tlv22 = (int)(cgc_strlen ( tlv48 ) + 1); }
    {char tlv25; tlv25 = (char)(cgc_strlen ( tlv48 ) + 1); }
    {char tlv27; tlv27 = (char)(cgc_strlen ( tlv48 ) + 1); }
    {int tlv32; tlv32 = (int)(cgc_strlen ( tlv48 ) + 1); }
    {int tlv31; tlv31 = (int)(cgc_strlen ( tlv48 ) + 1); }
    {char tlv36; tlv36 = (char)(cgc_strlen ( tlv48 ) + 1); }
    {char * tlv44; tlv44 = (char *)(cgc_strlen ( tlv48 ) + 1); }
    {void * tlv39; tlv39 = (void *)(cgc_strlen ( tlv48 ) + 1); }
    {cgc_size_t tlv38; tlv38 = (cgc_size_t)(cgc_strlen ( tlv48 ) + 1); }
    {void * tlv41; tlv41 = (void *)(cgc_strlen ( tlv48 ) + 1); }
    {cgc_size_t tlv40; tlv40 = (cgc_size_t)(cgc_strlen ( tlv48 ) + 1); }
    {void * tlv43; tlv43 = (void *)(cgc_strlen ( tlv48 ) + 1); }
    {cgc_size_t tlv42; tlv42 = (cgc_size_t)(cgc_strlen ( tlv48 ) + 1); }
}
void fix_ingred_countyParsers_8_42(){
fix_ingred_countyParsers_8_42_1();
}
void fix_ingred_countyParsers_8(){
fix_ingred_countyParsers_8_0();
fix_ingred_countyParsers_8_2();
fix_ingred_countyParsers_8_4();
fix_ingred_countyParsers_8_6();
fix_ingred_countyParsers_8_10();
fix_ingred_countyParsers_8_11();
fix_ingred_countyParsers_8_12();
fix_ingred_countyParsers_8_14();
fix_ingred_countyParsers_8_21();
fix_ingred_countyParsers_8_22();
fix_ingred_countyParsers_8_24();
fix_ingred_countyParsers_8_33();
fix_ingred_countyParsers_8_35();
fix_ingred_countyParsers_8_37();
fix_ingred_countyParsers_8_38();
fix_ingred_countyParsers_8_41();
fix_ingred_countyParsers_8_42();
}
