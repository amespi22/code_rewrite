

#include "cgc_planetParsers.h"
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

void fix_ingred_planetParsers_0_0_0();
void fix_ingred_planetParsers_0_0_1();
void fix_ingred_planetParsers_0_0();
void fix_ingred_planetParsers_0_3_0();
void fix_ingred_planetParsers_0_3_1();
void fix_ingred_planetParsers_0_3();
void fix_ingred_planetParsers_0_19_0();
void fix_ingred_planetParsers_0_19_1();
void fix_ingred_planetParsers_0_19_2();
void fix_ingred_planetParsers_0_19();
void fix_ingred_planetParsers_0_25_2();
void fix_ingred_planetParsers_0_25();
void fix_ingred_planetParsers_0_63_2();
void fix_ingred_planetParsers_0_63();
void fix_ingred_planetParsers_0_64_4();
void fix_ingred_planetParsers_0_64_5();
void fix_ingred_planetParsers_0_64();
void fix_ingred_planetParsers_0_68_0();
void fix_ingred_planetParsers_0_68();
void fix_ingred_planetParsers_0_69_4();
void fix_ingred_planetParsers_0_69();
void fix_ingred_planetParsers_0_74_9();
void fix_ingred_planetParsers_0_74();
void fix_ingred_planetParsers_0_80_8();
void fix_ingred_planetParsers_0_80();
void fix_ingred_planetParsers_0_86_8();
void fix_ingred_planetParsers_0_86();
void fix_ingred_planetParsers_0();
int cgc_planetMenu(pPlanet pl)
{
if (fix_ingred_enable){ fix_ingred_planetParsers_0(); };
    int choice;
    choice = 0;
    char selection[30];
    cgc_size_t length;
    length = 0;
    pCountry pc;
    pc = NULL;
    if (pl == NULL) {
	return 0;
    }
    while (1) {
 {
     void* tlv4;
     tlv4 = selection;
     cgc_size_t tlv3;
     tlv3 = 30;
    	cgc_bzero(tlv4,tlv3);
 }
	cgc_printf("\nPlanet: @s\n", pl->name);
 {
     const char tlv5 [ ] = "1) Display planet information\n";
    	cgc_printf(tlv5);
 }
 {
     const char tlv6 [ ] = "2) Set Period\n";
    	cgc_printf(tlv6);
 }
 {
     const char tlv7 [ ] = "3) Set Orbit Speed\n";
    	cgc_printf(tlv7);
 }
 {
     const char tlv8 [ ] = "4) Set Aphelion\n";
    	cgc_printf(tlv8);
 }
 {
     const char tlv9 [ ] = "5) Set Perihelion\n";
    	cgc_printf(tlv9);
 }
 {
     const char tlv10 [ ] = "6) Set Mean Radius\n";
    	cgc_printf(tlv10);
 }
 {
     const char tlv11 [ ] = "7) Set Equatorial Radius\n";
    	cgc_printf(tlv11);
 }
 {
     const char tlv12 [ ] = "8) Set Mass\n";
    	cgc_printf(tlv12);
 }
 {
     const char tlv13 [ ] = "9) Set Gravity\n";
    	cgc_printf(tlv13);
 }
 {
     const char tlv14 [ ] = "10) Set population\n";
    	cgc_printf(tlv14);
 }
 {
     const char tlv15 [ ] = "11) Add Country\n";
    	cgc_printf(tlv15);
 }
 {
     const char tlv16 [ ] = "12) Select country\n";
    	cgc_printf(tlv16);
 }
 {
     const char tlv17 [ ] = "13) Delete Planet and exit menu\n";
    	cgc_printf(tlv17);
 }
 {
     const char tlv18 [ ] = "14) Exit menu\n";
    	cgc_printf(tlv18);
 }
 {
     const char tlv19 [ ] = "Selection: ";
    	cgc_printf(tlv19);
 }
 {
     char* tlv22;
      tlv22 = selection;
     char tlv21;
     tlv21 = '\n';
     cgc_size_t tlv20;
     tlv20 = 3;
    	cgc_receive_until(tlv22,tlv21,tlv20);
 }
 {
     const char* tlv23 = selection;
    	choice = cgc_atoi(tlv23);
 }
	switch (choice) {
	case 1:
	    {
		cgc_printPlanetInfo(pl);
	    }
	    break;
	case 2:
	    {
  {
      const char tlv75 [ ] = "\n-> ";
    		cgc_printf(tlv75);
  }
	    }
     {
         char* tlv26;
          tlv26 = selection;
         char tlv25;
         tlv25 = '\n';
         cgc_size_t tlv24;
         tlv24 = 10;
    	    cgc_receive_until(tlv26,tlv25,tlv24);
     }
     {
         const char* tlv61 = selection;
    	    pl->period = cgc_atof(tlv61);
     }
	    break;
	case 3:
	    {
  {
      const char tlv76 [ ] = "\n-> ";
    		cgc_printf(tlv76);
  }
	    }
     {
         char* tlv29;
          tlv29 = selection;
         char tlv28;
         tlv28 = '\n';
         cgc_size_t tlv27;
         tlv27 = 10;
    	    cgc_receive_until(tlv29,tlv28,tlv27);
     }
     {
         const char* tlv62 = selection;
    	    pl->orbitspeed = cgc_atof(tlv62);
     }
	    break;
	case 4:
	    {
  {
      const char tlv77 [ ] = "\n-> ";
    		cgc_printf(tlv77);
  }
	    }
     {
         char* tlv32;
          tlv32 = selection;
         char tlv31;
         tlv31 = '\n';
         cgc_size_t tlv30;
         tlv30 = 10;
    	    cgc_receive_until(tlv32,tlv31,tlv30);
     }
     {
         const char* tlv63 = selection;
    	    pl->aphelion = cgc_atof(tlv63);
     }
	    break;
	case 5:
	    {
  {
      const char tlv78 [ ] = "\n-> ";
    		cgc_printf(tlv78);
  }
	    }
     {
         char* tlv35;
          tlv35 = selection;
         char tlv34;
         tlv34 = '\n';
         cgc_size_t tlv33;
         tlv33 = 10;
    	    cgc_receive_until(tlv35,tlv34,tlv33);
     }
     {
         const char* tlv64 = selection;
    	    pl->perihelion = cgc_atof(tlv64);
     }
	    break;
	case 6:
	    {
  {
      const char tlv79 [ ] = "\n-> ";
    		cgc_printf(tlv79);
  }
	    }
     {
         char* tlv38;
          tlv38 = selection;
         char tlv37;
         tlv37 = '\n';
         cgc_size_t tlv36;
         tlv36 = 10;
    	    cgc_receive_until(tlv38,tlv37,tlv36);
     }
     {
         const char* tlv65 = selection;
    	    pl->radius = cgc_atof(tlv65);
     }
	    break;
	case 7:
	    {
  {
      const char tlv80 [ ] = "\n-> ";
    		cgc_printf(tlv80);
  }
	    }
     {
         char* tlv41;
          tlv41 = selection;
         char tlv40;
         tlv40 = '\n';
         cgc_size_t tlv39;
         tlv39 = 10;
    	    cgc_receive_until(tlv41,tlv40,tlv39);
     }
     {
         const char* tlv66 = selection;
    	    pl->eradius = cgc_atof(tlv66);
     }
	    break;
	case 8:
	    {
  {
      const char tlv81 [ ] = "\n-> ";
    		cgc_printf(tlv81);
  }
	    }
     {
         char* tlv44;
          tlv44 = selection;
         char tlv43;
         tlv43 = '\n';
         cgc_size_t tlv42;
         tlv42 = 10;
    	    cgc_receive_until(tlv44,tlv43,tlv42);
     }
     {
         const char* tlv67 = selection;
    	    pl->mass = cgc_atof(tlv67);
     }
	    break;
	case 9:
	    {
  {
      const char tlv82 [ ] = "\n-> ";
    		cgc_printf(tlv82);
  }
	    }
     {
         char* tlv47;
          tlv47 = selection;
         char tlv46;
         tlv46 = '\n';
         cgc_size_t tlv45;
         tlv45 = 10;
    	    cgc_receive_until(tlv47,tlv46,tlv45);
     }
     {
         const char* tlv68 = selection;
    	    pl->gravity = cgc_atof(tlv68);
     }
	    break;
	case 10:
	    {
  {
      const char tlv83 [ ] = "\n-> ";
    		cgc_printf(tlv83);
  }
	    }
     {
         char* tlv50;
          tlv50 = selection;
         char tlv49;
         tlv49 = '\n';
         cgc_size_t tlv48;
         tlv48 = 10;
    	    cgc_receive_until(tlv50,tlv49,tlv48);
     }
     {
         const char* tlv69 = selection;
    	    pl->population = cgc_atoi(tlv69);
     }
	    break;
	case 11:
	    {
		if (pl->country_count >= COUNTRYMAX) {
      {
          const char tlv89 [ ] = "Too many countries\n";
    		    cgc_printf(tlv89);
      }
		    continue;
		}
	    }
     {
         const char tlv51 [ ] = "\nNew Name: ";
    	    cgc_printf(tlv51);
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
	    choice = 0;
	    while (choice < COUNTRYMAX) {
		if (pl->countries[choice] == NULL) {
		    break;
		}
		choice++;
	    }
	    if (choice == COUNTRYMAX) {
  {
      const char tlv84 [ ] = "!!No country slots\n";
    		cgc_printf(tlv84);
  }
		continue;
	    }
     int tlv1;
     {
         cgc_size_t tlv72;
         tlv72 = sizeof ( Country );
         int tlv71;
         tlv71 = 0;
         void** tlv70;
         tlv70 = ( void * * ) ( & pc );
         tlv1 = cgc_allocate(tlv72,tlv71,tlv70);
     }
	    if (tlv1 != 0) {
  {
      const char tlv85 [ ] = "!!Failed to allocate structure\n";
    		cgc_printf(tlv85);
  }
		continue;
	    }
	    cgc_initCountry(pc);
	    pl->countries[choice] = pc;
	    length = 0;

	    while (cgc_isalnum(selection[length])) {
		pc->name[length] = selection[length];
		length++;
	    }
	    pc->name[length] = '\x00';
	    pl->country_count++;
	    break;
	case 12:
	    {
  {
      const char tlv86 [ ] = "\nCountries:\n";
    		cgc_printf(tlv86);
  }
	    }
	    for (choice = 0; choice < pl->country_count; choice++) {
		if (pl->countries[choice] != NULL) {
		    cgc_printf("@d) @s\n", choice + 1, pl->countries[choice]);
		}
	    }
     {
         void* tlv56;
         tlv56 = selection;
         cgc_size_t tlv55;
         tlv55 = 30;
    	    cgc_bzero(tlv56,tlv55);
     }
     {
         const char tlv57 [ ] = "\n-> ";
    	    cgc_printf(tlv57);
     }
     {
         char* tlv60;
          tlv60 = selection;
         char tlv59;
         tlv59 = '\n';
         cgc_size_t tlv58;
         tlv58 = 3;
    	    cgc_receive_until(tlv60,tlv59,tlv58);
     }
     {
         const char* tlv73 = selection;
    	    choice = cgc_atoi(tlv73);
     }
	    if (choice < 1 || choice > COUNTRYMAX) {
  {
      const char tlv87 [ ] = "Invalid choice...\n";
    		cgc_printf(tlv87);
  }
		continue;
	    } else {
		if (pl->countries[choice - 1] == NULL) {
      {
          const char tlv90 [ ] = "Invalid choice...\n";
    		    cgc_printf(tlv90);
      }
		    continue;
		}
	    }
     int tlv2;
     {
         pCountry tlv74;
         tlv74 = pl -> countries [ choice - 1 ];
         tlv2 = cgc_countryMenu(tlv74);
     }
	    if (tlv2 == 0) {
		pl->countries[choice - 1] = NULL;
		pl->country_count--;
	    }
	    break;
	case 13:
	    {
		cgc_freePlanet(pl);
	    }
	    return 0;
	    break;
	case 14:
	    {
		return 1;
	    }
	    break;
	default:
	    {
  {
      const char tlv88 [ ] = "Invalid...\n";
    		cgc_printf(tlv88);
  }
	    }
	    break;
	};
    }
  end:
    return 1;
}

void fix_ingred_planetParsers_1_0_0();
void fix_ingred_planetParsers_1_0();
void fix_ingred_planetParsers_1_2_1();
void fix_ingred_planetParsers_1_2_2();
void fix_ingred_planetParsers_1_2();
void fix_ingred_planetParsers_1_5_0();
void fix_ingred_planetParsers_1_5_1();
void fix_ingred_planetParsers_1_5();
void fix_ingred_planetParsers_1();
void cgc_freePlanet(pPlanet pl)
{
if (fix_ingred_enable){ fix_ingred_planetParsers_1(); };
    int index;
    index = 0;
    if (pl == NULL) {
	return;
    }
    /// Free all of the associated countries
    while (index < COUNTRYMAX) {
	if (pl->countries[index] != NULL) {
	    /// This function also frees the pointer so freePlanet does not have to.
     {
         pCountry tlv3;
         tlv3 = pl -> countries [ index ];
    	    cgc_freeCountry(tlv3);
     }
	    pl->countries[index] = NULL;
	}
	index++;
    }

    {
        void* tlv2;
        tlv2 = pl;
        cgc_size_t tlv1;
        tlv1 = sizeof ( Planet );
        cgc_deallocate(tlv2,tlv1);
    }
    return;
}

void fix_ingred_planetParsers_2();
void cgc_printPlanetInfo(pPlanet pl)
{
if (fix_ingred_enable){ fix_ingred_planetParsers_2(); };
    int index;
    index = 0;
    if (pl == NULL) {
	return;
    }
    if (pl->name[0] == '\x00') {
 {
     const char tlv1 [ ] = "Name: Unknown\n";
    	cgc_printf(tlv1);
 }
    } else {
	cgc_printf("Name: @s\n", pl->name);
    }
    if (pl->population >= 0) {
	cgc_printf("\tPopulation: @d\n", pl->population);
    }
    if (pl->period >= 0.0) {
	cgc_printf("\tPeriod: @f\n", pl->period);
    }
    if (pl->orbitspeed >= 0.0) {
	cgc_printf("\tOrbit Speed: @f\n", pl->orbitspeed);
    }
    if (pl->aphelion >= 0.0) {
	cgc_printf("\tAphelion: @f\n", pl->aphelion);
    }
    if (pl->perihelion >= 0.0) {
	cgc_printf("\tPerihelion: @f\n", pl->perihelion);
    }
    if (pl->radius >= 0.0) {
	cgc_printf("\tRadius: @f\n", pl->radius);
    }
    if (pl->eradius >= 0.0) {
	cgc_printf("\tERadius: @f\n", pl->eradius);
    }
    if (pl->mass >= 0.0) {
	cgc_printf("\tMass: @f\n", pl->mass);
    }

    if (pl->gravity >= 0.0) {
	cgc_printf("\tGravity: @f\n", pl->gravity);
    }
    /// Print each country's information
    while (index < COUNTRYMAX) {
	if (pl->countries[index] != NULL) {
     {
         pCountry tlv2;
         tlv2 = pl -> countries [ index ];
    	    cgc_printCountryInfo(tlv2);
     }
	}
	index++;
    }
    return;
}

void fix_ingred_planetParsers_3_2_0();
void fix_ingred_planetParsers_3_2_1();
void fix_ingred_planetParsers_3_2();
void fix_ingred_planetParsers_3();
void cgc_initPlanet(pPlanet pl)
{
if (fix_ingred_enable){ fix_ingred_planetParsers_3(); };
    register int index;
    index = 0;
    if (pl == NULL) {
	return;
    }
    {
        void* tlv2;
        tlv2 = pl -> name;
        cgc_size_t tlv1;
        tlv1 = 20;
        cgc_bzero(tlv2,tlv1);
    }
    pl->period = -1.0;
    pl->orbitspeed = -1.0;
    pl->aphelion = -1.0;
    pl->perihelion = -1.0;
    pl->radius = -1.0;
    pl->eradius = -1.0;
    pl->mass = -1.0;
    pl->gravity = -1.0;
    pl->population = -1.0;
    pl->country_count = 0;
    while (index < COUNTRYMAX) {
	pl->countries[index] = NULL;
	index++;
    }
    return;
}

void fix_ingred_planetParsers_4_0_0();
void fix_ingred_planetParsers_4_0_3();
void fix_ingred_planetParsers_4_0_5();
void fix_ingred_planetParsers_4_0();
void fix_ingred_planetParsers_4_3_6();
void fix_ingred_planetParsers_4_3_7();
void fix_ingred_planetParsers_4_3();
void fix_ingred_planetParsers_4_5_0();
void fix_ingred_planetParsers_4_5();
void fix_ingred_planetParsers_4_6_7();
void fix_ingred_planetParsers_4_6();
void fix_ingred_planetParsers_4_8_1();
void fix_ingred_planetParsers_4_8();
void fix_ingred_planetParsers_4_9_7();
void fix_ingred_planetParsers_4_9();
void fix_ingred_planetParsers_4_11_0();
void fix_ingred_planetParsers_4_11();
void fix_ingred_planetParsers_4_12_1();
void fix_ingred_planetParsers_4_12();
void fix_ingred_planetParsers_4_17_0();
void fix_ingred_planetParsers_4_17_1();
void fix_ingred_planetParsers_4_17();
void fix_ingred_planetParsers_4_18_0();
void fix_ingred_planetParsers_4_18_2();
void fix_ingred_planetParsers_4_18();
void fix_ingred_planetParsers_4_20_1();
void fix_ingred_planetParsers_4_20();
void fix_ingred_planetParsers_4_55_1();
void fix_ingred_planetParsers_4_55();
void fix_ingred_planetParsers_4_59_7();
void fix_ingred_planetParsers_4_59();
void fix_ingred_planetParsers_4_60_1();
void fix_ingred_planetParsers_4_60();
void fix_ingred_planetParsers_4_64_7();
void fix_ingred_planetParsers_4_64_8();
void fix_ingred_planetParsers_4_64();
void fix_ingred_planetParsers_4_65_1();
void fix_ingred_planetParsers_4_65();
void fix_ingred_planetParsers_4_67_8();
void fix_ingred_planetParsers_4_67();
void fix_ingred_planetParsers_4_68_7();
void fix_ingred_planetParsers_4_68();
void fix_ingred_planetParsers_4_72_7();
void fix_ingred_planetParsers_4_72();
void fix_ingred_planetParsers_4_74_1();
void fix_ingred_planetParsers_4_74();
void fix_ingred_planetParsers_4_76_1();
void fix_ingred_planetParsers_4_76();
void fix_ingred_planetParsers_4();
pPlanet cgc_planetTopLevel(pstring topLevel)
{
if (fix_ingred_enable){ fix_ingred_planetParsers_4(); };
    int endIndex;
    endIndex = 0;
    int temp_index;
    temp_index = 0;
    pPlanet newPlanet;
    newPlanet = NULL;
    element el;
    char* fl;
     fl = NULL;
    int lastGood;
    lastGood = 0;
    if (topLevel == NULL) {
	goto end;
    }
    /// Skip any leading spaces
    cgc_skipWhiteSpace(topLevel);
    lastGood = topLevel->index;
    if (topLevel->maxlength < 9) {
	goto end;
    }
    char c[] = "{Planet}";
    for (int i = 0; i < 8; i++) {
	if (topLevel->buffer[topLevel->index + i] != c[i]) {
	    goto end;
	}
    }
    /// Skip 8 bytes of top level then any whitespace
    topLevel->index += 8;
    cgc_skipWhiteSpace(topLevel);
    /// Allocate a new planet structure
    int tlv1;
    {
        cgc_size_t tlv16;
        tlv16 = sizeof ( Planet );
        int tlv15;
        tlv15 = 0;
        void** tlv14;
        tlv14 = ( void * * ) & newPlanet;
        tlv1 = cgc_allocate(tlv16,tlv15,tlv14);
    }
    if (tlv1 != 0) {
	goto end;
    }
    cgc_initPlanet(newPlanet);
    /// Extract the next element name
    {
        pstring tlv17;
        tlv17 = topLevel;
        fl = cgc_pullNextElementName(tlv17);
    }
    {
        pstring tlv9;
        tlv9 = topLevel;
        int* tlv8;
        tlv8 = & lastGood;
        cgc_getIndex(tlv9,tlv8);
    }
    while (fl != NULL) {
	/// Convert the element name
 {
     char* tlv42;
      tlv42 = fl;
    	el = cgc_elementNameToEnum(tlv42);
 }
	/// The name is no longer needed so free it
 {
     void* tlv33;
     tlv33 = fl;
     cgc_size_t tlv32;
     {
         char* tlv62;
          tlv62 = fl;
         tlv32 = cgc_strlen(tlv62) + 1;
     }
    	cgc_deallocate(tlv33,tlv32);
 }
	switch (el) {
	case name:
	    {
  {
      pstring tlv52;
      tlv52 = topLevel;
    		fl = cgc_extractName(tlv52);
  }
	    }
	    if (fl == NULL) {
		goto error;
	    }
     {
         void* tlv45;
         tlv45 = newPlanet -> name;
         cgc_size_t tlv44;
         tlv44 = 20;
    	    cgc_bzero(tlv45,tlv44);
     }
     {
         char* tlv48;
          tlv48 = newPlanet -> name;
         char* tlv47;
          tlv47 = fl;
         cgc_size_t tlv46;
         tlv46 = 19;
    	    cgc_strncpy(tlv48,tlv47,tlv46);
     }
     {
         void* tlv50;
         tlv50 = fl;
         cgc_size_t tlv49;
         {
             char* tlv63;
              tlv63 = fl;
             tlv49 = cgc_strlen(tlv63) + 1;
         }
    	    cgc_deallocate(tlv50,tlv49);
     }
	    fl = NULL;
	    break;
	case population:
	    {
  {
      pstring tlv53;
      tlv53 = topLevel;
    		newPlanet->population = cgc_extractPopulation(tlv53);
  }
	    }
	    if (newPlanet->population < 0) {
		goto error;
	    }
	    break;
	case period:
	    /// Extract period and check result
	    {
  {
      pstring tlv54;
      tlv54 = topLevel;
    		newPlanet->period = cgc_extractPeriod(tlv54);
  }
	    }
	    if (newPlanet->period < 0.0) {
		goto error;
	    }
	    break;
	case orbitspeed:
	    {
  {
      pstring tlv55;
      tlv55 = topLevel;
    		newPlanet->orbitspeed = cgc_extractOrbitSpeed(tlv55);
  }
	    }
	    if (newPlanet->orbitspeed < 0.0) {
		goto error;
	    }
	    break;
	case aphelion:
	    {
  {
      pstring tlv56;
      tlv56 = topLevel;
    		newPlanet->aphelion = cgc_extractAphelion(tlv56);
  }
	    }
	    if (newPlanet->aphelion < 0.0) {
		goto error;
	    }
	    break;
	case perihelion:
	    {
  {
      pstring tlv57;
      tlv57 = topLevel;
    		newPlanet->perihelion = cgc_extractPerihelion(tlv57);
  }
	    }
	    if (newPlanet->perihelion < 0.0) {
		goto error;
	    }
	    break;
	case radius:
	    {
  {
      pstring tlv58;
      tlv58 = topLevel;
    		newPlanet->radius = cgc_extractRadius(tlv58);
  }
	    }
	    if (newPlanet->radius < 0.0) {
		goto error;
	    }
	    break;
	case eradius:
	    {
  {
      pstring tlv59;
      tlv59 = topLevel;
    		newPlanet->eradius = cgc_extractERadius(tlv59);
  }
	    }
	    if (newPlanet->eradius < 0.0) {
		goto error;
	    }
	    break;
	case mass:
	    {
  {
      pstring tlv60;
      tlv60 = topLevel;
    		newPlanet->mass = cgc_extractMass(tlv60);
  }
	    }
	    if (newPlanet->mass < 0.0) {
		goto error;
	    }
	    break;
	case gravity:
	    {
  {
      pstring tlv61;
      tlv61 = topLevel;
    		newPlanet->gravity = cgc_extractGravity(tlv61);
  }
	    }
	    if (newPlanet->gravity < 0.0) {
		goto error;
	    }
	    break;
	case country:
	    {
		if (newPlanet->country_count >= COUNTRYMAX) {
		    cgc_printf("!!Only @d countries allowed\n", COUNTRYMAX);
		    goto error;
		}
	    }
     {
         pstring tlv51;
         tlv51 = topLevel;
    	    newPlanet->countries[newPlanet->country_count] = cgc_countryTopLevel(tlv51);
     }
	    if (newPlanet->countries[newPlanet->country_count] == NULL) {
		goto error;
	    }
	    newPlanet->country_count++;
	    break;
	default:
	    {
		cgc_printf("Not allowed under Planet\n", fl);
	    }
	    goto error;
	    break;
	};
 {
     pstring tlv35;
     tlv35 = topLevel;
     int* tlv34;
     tlv34 = & lastGood;
    	cgc_getIndex(tlv35,tlv34);
 }
 {
     pstring tlv43;
     tlv43 = topLevel;
    	fl = cgc_pullNextElementName(tlv43);
 }
    }
    /// Since no more valid elements need to be parsed, check the closing element
    cgc_skipWhiteSpace(topLevel);
    int tlv2;
    {
        pstring tlv19;
        tlv19 = topLevel;
        char tlv18;
        tlv18 = '{';
        tlv2 = cgc_atChar(tlv19,tlv18);
    }
    if (!tlv2) {
 {
     const char tlv36 [ ] = "!!Closing value failed for Planet\n";
    	cgc_printf(tlv36);
 }
	goto error;
    }
    /// Skip the open brace
    int tlv3;
    {
        pstring tlv20;
        tlv20 = topLevel;
        tlv3 = cgc_incChar(tlv20);
    }
    if (tlv3 < 0) {
	goto error;
    }
    cgc_skipWhiteSpace(topLevel);
    int tlv4;
    {
        pstring tlv22;
        tlv22 = topLevel;
        char tlv21;
        tlv21 = '#';
        tlv4 = cgc_atChar(tlv22,tlv21);
    }
    if (!tlv4) {
 {
     const char tlv37 [ ] = "!!Malformed closing element\n";
    	cgc_printf(tlv37);
 }
	goto error;
    }
    /// Skip past #
    int tlv5;
    {
        pstring tlv23;
        tlv23 = topLevel;
        tlv5 = cgc_incChar(tlv23);
    }
    if (tlv5 == -1) {
	goto error;
    }
    {
        pstring tlv11;
        tlv11 = topLevel;
        int* tlv10;
        tlv10 = & temp_index;
        cgc_getIndex(tlv11,tlv10);
    }
    {
        pstring tlv24;
        tlv24 = topLevel;
        endIndex = cgc_skipAlpha(tlv24);
    }
    if (endIndex == -1) {
	endIndex = 0;
	goto error;
    }
    if (temp_index == endIndex) {
	goto error;
    }
    {
        pstring tlv27;
        tlv27 = topLevel;
        int tlv26;
        tlv26 = temp_index;
        int tlv25;
        tlv25 = endIndex;
        fl = cgc_copyData(tlv27,tlv26,tlv25);
    }
    if (fl == NULL) {
	goto error;
    }
    int tlv6;
    {
        const char* tlv29 = fl;
        const char tlv28 [ ] = "Planet";
        tlv6 = cgc_strcmp(tlv29,tlv28);
    }
    if (tlv6 != 0) {
 {
     const char tlv38 [ ] = "!!Closing element malformed\n";
    	cgc_printf(tlv38);
 }
 {
     void* tlv40;
     tlv40 = fl;
     cgc_size_t tlv39;
     tlv39 = ( endIndex - temp_index ) + 1;
    	cgc_deallocate(tlv40,tlv39);
 }
	goto error;
    }
    {
        void* tlv13;
        tlv13 = fl;
        cgc_size_t tlv12;
        tlv12 = ( endIndex - temp_index ) + 1;
        cgc_deallocate(tlv13,tlv12);
    }
    cgc_skipWhiteSpace(topLevel);
    int tlv7;
    {
        pstring tlv31;
        tlv31 = topLevel;
        char tlv30;
        tlv30 = '}';
        tlv7 = cgc_atChar(tlv31,tlv30);
    }
    if (!tlv7) {
 {
     const char tlv41 [ ] = "!!Failed to find final closing brace\n";
    	cgc_printf(tlv41);
 }
	goto error;
    }
    cgc_incChar(topLevel);

    goto end;
  error:
    topLevel->index = lastGood;
    cgc_printf("!!Error at: @s\n", topLevel->buffer + topLevel->index);
    if (newPlanet != NULL) {
	cgc_freePlanet(newPlanet);
	newPlanet = NULL;
    }
  end:
    return newPlanet;
}

void fix_ingred_planetParsers_5_0_0();
void fix_ingred_planetParsers_5_0_1();
void fix_ingred_planetParsers_5_0_2();
void fix_ingred_planetParsers_5_0();
void fix_ingred_planetParsers_5_2_1();
void fix_ingred_planetParsers_5_2();
void fix_ingred_planetParsers_5_5_1();
void fix_ingred_planetParsers_5_5();
void fix_ingred_planetParsers_5_6_6();
void fix_ingred_planetParsers_5_6_7();
void fix_ingred_planetParsers_5_6();
void fix_ingred_planetParsers_5_10_6();
void fix_ingred_planetParsers_5_10();
void fix_ingred_planetParsers_5_12_1();
void fix_ingred_planetParsers_5_12();
void fix_ingred_planetParsers_5_13_6();
void fix_ingred_planetParsers_5_13();
void fix_ingred_planetParsers_5_15_7();
void fix_ingred_planetParsers_5_15();
void fix_ingred_planetParsers_5_17_0();
void fix_ingred_planetParsers_5_17();
void fix_ingred_planetParsers_5_18_1();
void fix_ingred_planetParsers_5_18();
void fix_ingred_planetParsers_5_20_1();
void fix_ingred_planetParsers_5_20();
void fix_ingred_planetParsers_5_21_1();
void fix_ingred_planetParsers_5_21();
void fix_ingred_planetParsers_5_25_6();
void fix_ingred_planetParsers_5_25();
void fix_ingred_planetParsers_5_27_1();
void fix_ingred_planetParsers_5_27();
void fix_ingred_planetParsers_5_29_6();
void fix_ingred_planetParsers_5_29();
void fix_ingred_planetParsers_5_35_6();
void fix_ingred_planetParsers_5_35();
void fix_ingred_planetParsers_5_37_1();
void fix_ingred_planetParsers_5_37();
void fix_ingred_planetParsers_5_48_6();
void fix_ingred_planetParsers_5_48();
void fix_ingred_planetParsers_5_50_1();
void fix_ingred_planetParsers_5_50();
void fix_ingred_planetParsers_5_52_1();
void fix_ingred_planetParsers_5_52();
void fix_ingred_planetParsers_5_57_1();
void fix_ingred_planetParsers_5_57();
void fix_ingred_planetParsers_5_62_1();
void fix_ingred_planetParsers_5_62();
void fix_ingred_planetParsers_5();
double cgc_extractPeriod(pstring str)
{
if (fix_ingred_enable){ fix_ingred_planetParsers_5(); };
    char* temp;
     temp = NULL;
    double period;
    period = - 1.0;
    int start;
    start = 0;
    int end;
    end = 0;
    /// These will be used specifically for the data
    int ps;
    ps = 0;
    int pe;
    pe = 0;
    if (str == NULL) {
	return period;
    }
    cgc_skipWhiteSpace(str);
    int tlv1;
    {
        pstring tlv22;
        tlv22 = str;
        char tlv21;
        tlv21 = '{';
        tlv1 = cgc_atChar(tlv22,tlv21);
    }
    if (!tlv1) {
 {
     const char tlv57 [ ] = "!!Failed to locate opening brace\n";
    	cgc_printf(tlv57);
 }
	return period;
    }
    /// Skip past the curly brace
    int tlv2;
    {
        pstring tlv24;
        tlv24 = str;
        int tlv23;
        tlv23 = 1;
        tlv2 = cgc_skipLength(tlv24,tlv23);
    }
    if (tlv2 == -1) {
 {
     const char tlv58 [ ] = "!!Failed to skip opening brace\n";
    	cgc_printf(tlv58);
 }
	return period;
    }
    /// Skip any additional whitespace
    {
        pstring tlv25;
        tlv25 = str;
        start = cgc_skipWhiteSpace(tlv25);
    }
    /// This should skip any to either whitespace or a closing '}'
    {
        pstring tlv26;
        tlv26 = str;
        end = cgc_skipToNonAlphaNum(tlv26);
    }
    if (end == -1) {
 {
     const char tlv59 [ ] = "!!Failed to locate the end of the element id\n";
    	cgc_printf(tlv59);
 }
	return period;
    }
    /// Copy the element id from the string
    {
        pstring tlv29;
        tlv29 = str;
        int tlv28;
        tlv28 = start;
        int tlv27;
        tlv27 = end;
        temp = cgc_copyData(tlv29,tlv28,tlv27);
    }
    if (temp == NULL) {
	cgc_printf("!!Copy from @d to @d failed\n", start, end);
	return -1.0;
    }
    /// If the element id is not "Period" then this is the wrong function
    int tlv3;
    {
        const char* tlv31 = temp;
        const char tlv30 [ ] = "Period";
        tlv3 = cgc_strcmp(tlv31,tlv30);
    }
    if (tlv3 != 0) {
 {
     const char tlv60 [ ] = "!!Element id is not \"Period\"\n";
    	cgc_printf(tlv60);
 }
 {
     void* tlv62;
     tlv62 = temp;
     cgc_size_t tlv61;
     {
         char* tlv78;
          tlv78 = temp;
         tlv61 = cgc_strlen(tlv78) + 1;
     }
    	cgc_deallocate(tlv62,tlv61);
 }
	temp = NULL;
	return period;
    }
    /// The buffer is no longer needed so free it
    {
        void* tlv12;
        tlv12 = temp;
        cgc_size_t tlv11;
        {
            char* tlv75;
             tlv75 = temp;
            tlv11 = cgc_strlen(tlv75) + 1;
        }
        cgc_deallocate(tlv12,tlv11);
    }
    /// Skip to the end of the element id
    cgc_skipWhiteSpace(str);
    /// If it is not a closing brace then this is improperly formatted.
    int tlv4;
    {
        pstring tlv33;
        tlv33 = str;
        char tlv32;
        tlv32 = '}';
        tlv4 = cgc_atChar(tlv33,tlv32);
    }
    if (!tlv4) {
 {
     const char tlv63 [ ] = "!!Failed to locate initial closing brace\n";
    	cgc_printf(tlv63);
 }
	return -1.0;
    }
    /// Skip the closing brace as well as any whitespace
    int tlv5;
    {
        pstring tlv35;
        tlv35 = str;
        int tlv34;
        tlv34 = 1;
        tlv5 = cgc_skipLength(tlv35,tlv34);
    }
    if (tlv5 == -1) {
 {
     const char tlv64 [ ] = "!!Failed to skip initial closing brace\n";
    	cgc_printf(tlv64);
 }
	return period;
    }
    cgc_skipWhiteSpace(str);
    /// Copy the start index to store the data
    {
        pstring tlv14;
        tlv14 = str;
        int* tlv13;
        tlv13 = & ps;
        cgc_getIndex(tlv14,tlv13);
    }
    /// The period data must be a float
    {
        pstring tlv36;
        tlv36 = str;
        pe = cgc_skipFloat(tlv36);
    }
    if (pe == -1) {
 {
     const char tlv65 [ ] = "!!Failed to locate the end of the period data\n";
    	cgc_printf(tlv65);
 }
	return end;
    }
    /// The rest of this code is a check to ensure proper formatting except for the copy data
    cgc_skipWhiteSpace(str);
    /// If this is not an opening curly brace then fail
    int tlv6;
    {
        pstring tlv38;
        tlv38 = str;
        char tlv37;
        tlv37 = '{';
        tlv6 = cgc_atChar(tlv38,tlv37);
    }
    if (!tlv6) {
 {
     const char tlv66 [ ] = "!!Failed to locate the final opening brace\n";
    	cgc_printf(tlv66);
 }
	return -1.0;
    }
    /// Skip past the brace
    int tlv7;
    {
        pstring tlv40;
        tlv40 = str;
        int tlv39;
        tlv39 = 1;
        tlv7 = cgc_skipLength(tlv40,tlv39);
    }
    if (tlv7 == -1) {
 {
     const char tlv67 [ ] = "!!Failed to skip the final opening brace\n";
    	cgc_printf(tlv67);
 }
	return period;
    }

    cgc_skipWhiteSpace(str);
    /// If this is not a # indicating the closing brace then fail
    int tlv8;
    {
        pstring tlv42;
        tlv42 = str;
        char tlv41;
        tlv41 = '#';
        tlv8 = cgc_atChar(tlv42,tlv41);
    }
    if (!tlv8) {
 {
     const char tlv68 [ ] = "!!Failed to locate the closing mark\n";
    	cgc_printf(tlv68);
 }
	return -1.0;
    }
    /// Skip past the # but save the start
    {
        pstring tlv44;
        tlv44 = str;
        int tlv43;
        tlv43 = 1;
        start = cgc_skipLength(tlv44,tlv43);
    }
    if (start == -1) {
 {
     const char tlv69 [ ] = "!!Failed to skip closing mark\n";
    	cgc_printf(tlv69);
 }
	return period;
    }
    {
        pstring tlv45;
        tlv45 = str;
        end = cgc_skipToNonAlphaNum(tlv45);
    }
    if (end == -1) {
 {
     const char tlv70 [ ] = "!!Failed to locate the end of the closing element id\n";
    	cgc_printf(tlv70);
 }
	return -1.0;
    }

    {
        pstring tlv48;
        tlv48 = str;
        int tlv47;
        tlv47 = start;
        int tlv46;
        tlv46 = end;
        temp = cgc_copyData(tlv48,tlv47,tlv46);
    }
    int tlv9;
    {
        const char* tlv50 = temp;
        const char tlv49 [ ] = "Period";
        tlv9 = cgc_strcmp(tlv50,tlv49);
    }
    if (tlv9 != 0) {
	cgc_printf("!!Invalid closing element id: @s\n", temp);
 {
     void* tlv72;
     tlv72 = temp;
     cgc_size_t tlv71;
     {
         char* tlv79;
          tlv79 = temp;
         tlv71 = cgc_strlen(tlv79) + 1;
     }
    	cgc_deallocate(tlv72,tlv71);
 }
	return period;
    }
    {
        void* tlv16;
        tlv16 = temp;
        cgc_size_t tlv15;
        {
            char* tlv76;
             tlv76 = temp;
            tlv15 = cgc_strlen(tlv76) + 1;
        }
        cgc_deallocate(tlv16,tlv15);
    }
    cgc_skipWhiteSpace(str);
    /// Check the final curly brace
    int tlv10;
    {
        pstring tlv52;
        tlv52 = str;
        char tlv51;
        tlv51 = '}';
        tlv10 = cgc_atChar(tlv52,tlv51);
    }
    if (!tlv10) {
 {
     const char tlv73 [ ] = "!!Failed to locate final closing brace\n";
    	cgc_printf(tlv73);
 }
	return -1.0;
    }
    /// Skip past the closing brace
    {
        pstring tlv18;
        tlv18 = str;
        int tlv17;
        tlv17 = 1;
        cgc_skipLength(tlv18,tlv17);
    }

    /// Copy the name element data
    {
        pstring tlv55;
        tlv55 = str;
        int tlv54;
        tlv54 = ps;
        int tlv53;
        tlv53 = pe;
        temp = cgc_copyData(tlv55,tlv54,tlv53);
    }
    if (temp == NULL) {
 {
     const char tlv74 [ ] = "!!Failed to copy period data\n";
    	cgc_printf(tlv74);
 }
	return -1;
    }
    {
        const char* tlv56 = temp;
        period = cgc_atof(tlv56);
    }
    {
        void* tlv20;
        tlv20 = temp;
        cgc_size_t tlv19;
        {
            char* tlv77;
             tlv77 = temp;
            tlv19 = cgc_strlen(tlv77) + 1;
        }
        cgc_deallocate(tlv20,tlv19);
    }
    return period;
}

void fix_ingred_planetParsers_6_0_0();
void fix_ingred_planetParsers_6_0_1();
void fix_ingred_planetParsers_6_0_4();
void fix_ingred_planetParsers_6_0_6();
void fix_ingred_planetParsers_6_0();
void fix_ingred_planetParsers_6_3_1();
void fix_ingred_planetParsers_6_3();
void fix_ingred_planetParsers_6_6_1();
void fix_ingred_planetParsers_6_6();
void fix_ingred_planetParsers_6_7_6();
void fix_ingred_planetParsers_6_7_7();
void fix_ingred_planetParsers_6_7();
void fix_ingred_planetParsers_6_13_1();
void fix_ingred_planetParsers_6_13_2();
void fix_ingred_planetParsers_6_13();
void fix_ingred_planetParsers_6_14_6();
void fix_ingred_planetParsers_6_14();
void fix_ingred_planetParsers_6_16_7();
void fix_ingred_planetParsers_6_16();
void fix_ingred_planetParsers_6_18_0();
void fix_ingred_planetParsers_6_18();
void fix_ingred_planetParsers_6_19_1();
void fix_ingred_planetParsers_6_19();
void fix_ingred_planetParsers_6_21_1();
void fix_ingred_planetParsers_6_21();
void fix_ingred_planetParsers_6_23_1();
void fix_ingred_planetParsers_6_23();
void fix_ingred_planetParsers_6_25_1();
void fix_ingred_planetParsers_6_25();
void fix_ingred_planetParsers_6_26_1();
void fix_ingred_planetParsers_6_26();
void fix_ingred_planetParsers_6_30_6();
void fix_ingred_planetParsers_6_30();
void fix_ingred_planetParsers_6_33_7();
void fix_ingred_planetParsers_6_33();
void fix_ingred_planetParsers_6_39_7();
void fix_ingred_planetParsers_6_39();
void fix_ingred_planetParsers_6_41_1();
void fix_ingred_planetParsers_6_41();
void fix_ingred_planetParsers_6_52_7();
void fix_ingred_planetParsers_6_52();
void fix_ingred_planetParsers_6_54_1();
void fix_ingred_planetParsers_6_54();
void fix_ingred_planetParsers_6_56_1();
void fix_ingred_planetParsers_6_56();
void fix_ingred_planetParsers_6_58_1();
void fix_ingred_planetParsers_6_58();
void fix_ingred_planetParsers_6_60_1();
void fix_ingred_planetParsers_6_60();
void fix_ingred_planetParsers_6_65_1();
void fix_ingred_planetParsers_6_65();
void fix_ingred_planetParsers_6_70_1();
void fix_ingred_planetParsers_6_70();
void fix_ingred_planetParsers_6();
double cgc_extractOrbitSpeed(pstring str)
{
if (fix_ingred_enable){ fix_ingred_planetParsers_6(); };
    char* temp;
     temp = NULL;
    double speed;
    speed = - 1.0;
    register int start;
    start = 0;
    register int end;
    end = 0;
    int ss;
    ss = 0;
    int se;
    se = 0;
    if (str == NULL) {
	goto reterrvalue;
    }
    {
        pstring tlv23;
        tlv23 = str;
        start = cgc_skipWhiteSpace(tlv23);
    }
    int tlv1;
    {
        pstring tlv25;
        tlv25 = str;
        char tlv24;
        tlv24 = '{';
        tlv1 = cgc_atChar(tlv25,tlv24);
    }
    if (!(tlv1 & 1)) {
 {
     const char tlv60 [ ] = "!!Failed to locate opening brace\n";
    	cgc_printf(tlv60);
 }
	goto reterrspeed;
    }
    /// Skip past the curly brace
    int tlv2;
    {
        pstring tlv27;
        tlv27 = str;
        int tlv26;
        tlv26 = 1;
        tlv2 = cgc_skipLength(tlv27,tlv26);
    }
    if (tlv2 == -1) {
 {
     const char tlv61 [ ] = "!!Failed to skip opening brace\n";
    	cgc_printf(tlv61);
 }
	return speed;
    }
    /// Skip any additional whitespace
    {
        pstring tlv28;
        tlv28 = str;
        start = cgc_skipWhiteSpace(tlv28);
    }
    /// This should skip any to either whitespace or a closing '}'
    {
        pstring tlv29;
        tlv29 = str;
        end = cgc_skipToNonAlphaNum(tlv29);
    }
    if (end == -1) {
 {
     const char tlv62 [ ] = "!!Failed to locate the end of the element id\n";
    	cgc_printf(tlv62);
 }
	goto reterrvalue;
    }
    /// Copy the element id from the string
    {
        pstring tlv32;
        tlv32 = str;
        int tlv31;
        tlv31 = start;
        int tlv30;
        tlv30 = end;
        temp = cgc_copyData(tlv32,tlv31,tlv30);
    }
    if (temp == NULL) {
	cgc_printf("!!Copy from @d to @d failed\n", start, end);
	return -1.0;
    }
    /// If the element id is not "OrbitSpeed" then this is the wrong function
    int tlv3;
    {
        const char* tlv34 = temp;
        const char tlv33 [ ] = "OrbitSpeed";
        tlv3 = cgc_strcmp(tlv34,tlv33);
    }
    if (tlv3 != 0) {
 {
     const char tlv63 [ ] = "!!Element id is not \"OrbitSpeed\"\n";
    	cgc_printf(tlv63);
 }
 {
     void* tlv65;
     tlv65 = temp;
     cgc_size_t tlv64;
     {
         char* tlv87;
          tlv87 = temp;
         tlv64 = cgc_strlen(tlv87);
     }
    	cgc_bzero(tlv65,tlv64);
 }
 {
     void* tlv67;
     tlv67 = temp;
     cgc_size_t tlv66;
     {
         char* tlv88;
          tlv88 = temp;
         tlv66 = cgc_strlen(tlv88) + 1;
     }
    	cgc_deallocate(tlv67,tlv66);
 }
	temp = NULL;
	goto reterrvalue;
    }
    /// The buffer is no longer needed so free it
    {
        void* tlv12;
        tlv12 = temp;
        cgc_size_t tlv11;
        {
            char* tlv82;
             tlv82 = temp;
            tlv11 = cgc_strlen(tlv82) + 1;
        }
        cgc_bzero(tlv12,tlv11);
    }
    {
        void* tlv14;
        tlv14 = temp;
        cgc_size_t tlv13;
        {
            char* tlv83;
             tlv83 = temp;
            tlv13 = cgc_strlen(tlv83) + 1;
        }
        cgc_deallocate(tlv14,tlv13);
    }
    /// Skip to the end of the element id
    cgc_skipWhiteSpace(str);
    /// If it is not a closing brace then this is improperly formatted.
    int tlv4;
    {
        pstring tlv36;
        tlv36 = str;
        char tlv35;
        tlv35 = '}';
        tlv4 = cgc_atChar(tlv36,tlv35);
    }
    if (!tlv4) {
 {
     const char tlv68 [ ] = "!!Failed to locate initial closing brace\n";
    	cgc_printf(tlv68);
 }
	goto reterrspeed;
    }
    /// Skip the closing brace as well as any whitespace
    int tlv5;
    {
        pstring tlv38;
        tlv38 = str;
        int tlv37;
        tlv37 = 1;
        tlv5 = cgc_skipLength(tlv38,tlv37);
    }
    if (tlv5 == -1) {
 {
     const char tlv69 [ ] = "!!Failed to skip initial closing brace\n";
    	cgc_printf(tlv69);
 }
	goto retspeed;
    }
    cgc_skipWhiteSpace(str);
    /// Copy the start index to store the data
    ss = str->index;
    /// The period data must be a float
    {
        pstring tlv39;
        tlv39 = str;
        se = cgc_skipFloat(tlv39);
    }
    if (se == -1) {
 {
     const char tlv70 [ ] = "!!Failed to locate the end of the period data\n";
    	cgc_printf(tlv70);
 }
	return -1.0;
    }
    /// The rest of this code is a check to ensure proper formatting except for the copy data
    cgc_skipWhiteSpace(str);
    /// If this is not an opening curly brace then fail
    int tlv6;
    {
        pstring tlv41;
        tlv41 = str;
        char tlv40;
        tlv40 = '{';
        tlv6 = cgc_atChar(tlv41,tlv40);
    }
    if (!tlv6) {
 {
     const char tlv71 [ ] = "!!Failed to locate the final opening brace\n";
    	cgc_printf(tlv71);
 }
	goto reterrvalue;
    }
    /// Skip past the brace
    int tlv7;
    {
        pstring tlv43;
        tlv43 = str;
        int tlv42;
        tlv42 = 1;
        tlv7 = cgc_skipLength(tlv43,tlv42);
    }
    if (tlv7 == -1) {
 {
     const char tlv72 [ ] = "!!Failed to skip the final opening brace\n";
    	cgc_printf(tlv72);
 }
	goto reterrspeed;
    }

    cgc_skipWhiteSpace(str);
    /// If this is not a # indicating the closing brace then fail
    int tlv8;
    {
        pstring tlv45;
        tlv45 = str;
        char tlv44;
        tlv44 = '#';
        tlv8 = cgc_atChar(tlv45,tlv44);
    }
    if (!tlv8) {
 {
     const char tlv73 [ ] = "!!Failed to locate the closing mark\n";
    	cgc_printf(tlv73);
 }
	return -1.0;
    }
    /// Skip past the # but save the start
    {
        pstring tlv47;
        tlv47 = str;
        int tlv46;
        tlv46 = 1;
        start = cgc_skipLength(tlv47,tlv46);
    }
    if (start == -1) {
 {
     const char tlv74 [ ] = "!!Failed to skip closing mark\n";
    	cgc_printf(tlv74);
 }
	goto reterrvalue;
    }
    {
        pstring tlv48;
        tlv48 = str;
        end = cgc_skipToNonAlphaNum(tlv48);
    }
    if (end == -1) {
 {
     const char tlv75 [ ] = "!!Failed to locate the end of the closing element id\n";
    	cgc_printf(tlv75);
 }
	return -1.0;
    }

    {
        pstring tlv51;
        tlv51 = str;
        int tlv50;
        tlv50 = start;
        int tlv49;
        tlv49 = end;
        temp = cgc_copyData(tlv51,tlv50,tlv49);
    }
    int tlv9;
    {
        const char* tlv53 = temp;
        const char tlv52 [ ] = "OrbitSpeed";
        tlv9 = cgc_strcmp(tlv53,tlv52);
    }
    if (tlv9 != 0) {
	cgc_printf("!!Invalid closing element id: @s\n", temp);
 {
     void* tlv77;
     tlv77 = temp;
     cgc_size_t tlv76;
     {
         char* tlv89;
          tlv89 = temp;
         tlv76 = cgc_strlen(tlv89) + 1;
     }
    	cgc_bzero(tlv77,tlv76);
 }
 {
     void* tlv79;
     tlv79 = temp;
     cgc_size_t tlv78;
     {
         char* tlv90;
          tlv90 = temp;
         tlv78 = cgc_strlen(tlv90) + 1;
     }
    	cgc_deallocate(tlv79,tlv78);
 }
	return -1.0;
    }
    {
        void* tlv16;
        tlv16 = temp;
        cgc_size_t tlv15;
        {
            char* tlv84;
             tlv84 = temp;
            tlv15 = cgc_strlen(tlv84) + 1;
        }
        cgc_bzero(tlv16,tlv15);
    }
    {
        void* tlv18;
        tlv18 = temp;
        cgc_size_t tlv17;
        {
            char* tlv85;
             tlv85 = temp;
            tlv17 = cgc_strlen(tlv85) + 1;
        }
        cgc_deallocate(tlv18,tlv17);
    }
    cgc_skipWhiteSpace(str);
    /// Check the final curly brace
    int tlv10;
    {
        pstring tlv55;
        tlv55 = str;
        char tlv54;
        tlv54 = '}';
        tlv10 = cgc_atChar(tlv55,tlv54);
    }
    if (!tlv10) {
 {
     const char tlv80 [ ] = "!!Failed to locate final closing brace\n";
    	cgc_printf(tlv80);
 }
	goto reterrspeed;
    }
    /// Skip past the closing brace
    {
        pstring tlv20;
        tlv20 = str;
        int tlv19;
        tlv19 = 1;
        cgc_skipLength(tlv20,tlv19);
    }

    /// Copy the name element data
    {
        pstring tlv58;
        tlv58 = str;
        int tlv57;
        tlv57 = ss;
        int tlv56;
        tlv56 = se;
        temp = cgc_copyData(tlv58,tlv57,tlv56);
    }
    if (temp == NULL) {
 {
     const char tlv81 [ ] = "!!Failed to copy period data\n";
    	cgc_printf(tlv81);
 }
	goto retspeed;
    }
    {
        const char* tlv59 = temp;
        speed = cgc_atof(tlv59);
    }
    {
        void* tlv22;
        tlv22 = temp;
        cgc_size_t tlv21;
        {
            char* tlv86;
             tlv86 = temp;
            tlv21 = cgc_strlen(tlv86) + 1;
        }
        cgc_deallocate(tlv22,tlv21);
    }
    goto retspeed;
  reterrvalue:
    return -1.0;
  reterrspeed:
    speed = -1.0;
    return speed;
  retspeed:
    return speed;
}

void fix_ingred_planetParsers_7_0_0();
void fix_ingred_planetParsers_7_0_1();
void fix_ingred_planetParsers_7_0_2();
void fix_ingred_planetParsers_7_0();
void fix_ingred_planetParsers_7_3_1();
void fix_ingred_planetParsers_7_3();
void fix_ingred_planetParsers_7_6_1();
void fix_ingred_planetParsers_7_6();
void fix_ingred_planetParsers_7_7_6();
void fix_ingred_planetParsers_7_7_7();
void fix_ingred_planetParsers_7_7();
void fix_ingred_planetParsers_7_11_6();
void fix_ingred_planetParsers_7_11();
void fix_ingred_planetParsers_7_13_1();
void fix_ingred_planetParsers_7_13();
void fix_ingred_planetParsers_7_14_6();
void fix_ingred_planetParsers_7_14();
void fix_ingred_planetParsers_7_16_7();
void fix_ingred_planetParsers_7_16();
void fix_ingred_planetParsers_7_18_0();
void fix_ingred_planetParsers_7_18();
void fix_ingred_planetParsers_7_19_1();
void fix_ingred_planetParsers_7_19();
void fix_ingred_planetParsers_7_21_1();
void fix_ingred_planetParsers_7_21();
void fix_ingred_planetParsers_7_22_1();
void fix_ingred_planetParsers_7_22();
void fix_ingred_planetParsers_7_26_6();
void fix_ingred_planetParsers_7_26();
void fix_ingred_planetParsers_7_28_1();
void fix_ingred_planetParsers_7_28();
void fix_ingred_planetParsers_7_30_6();
void fix_ingred_planetParsers_7_30();
void fix_ingred_planetParsers_7_36_6();
void fix_ingred_planetParsers_7_36();
void fix_ingred_planetParsers_7_38_1();
void fix_ingred_planetParsers_7_38();
void fix_ingred_planetParsers_7_49_6();
void fix_ingred_planetParsers_7_49();
void fix_ingred_planetParsers_7_51_1();
void fix_ingred_planetParsers_7_51();
void fix_ingred_planetParsers_7_53_1();
void fix_ingred_planetParsers_7_53();
void fix_ingred_planetParsers_7_58_1();
void fix_ingred_planetParsers_7_58();
void fix_ingred_planetParsers_7_63_1();
void fix_ingred_planetParsers_7_63();
void fix_ingred_planetParsers_7();
double cgc_extractAphelion(pstring str)
{
if (fix_ingred_enable){ fix_ingred_planetParsers_7(); };
    char* temp;
     temp = NULL;
    double aphelion;
    aphelion = - 1.0;
    int start;
    start = 0;
    int end;
    end = 0;
    /// These will be used specifically for the data
    int ps;
    ps = 0;
    int pe;
    pe = 0;
    if (str == NULL) {
	return -1.0;
    }
    {
        pstring tlv21;
        tlv21 = str;
        start = cgc_skipWhiteSpace(tlv21);
    }
    int tlv1;
    {
        pstring tlv23;
        tlv23 = str;
        char tlv22;
        tlv22 = '{';
        tlv1 = cgc_atChar(tlv23,tlv22);
    }
    if (!tlv1) {
 {
     const char tlv58 [ ] = "!!Failed to locate opening brace\n";
    	cgc_printf(tlv58);
 }
	return aphelion;
    }
    /// Skip past the curly brace
    int tlv2;
    {
        pstring tlv25;
        tlv25 = str;
        int tlv24;
        tlv24 = 1;
        tlv2 = cgc_skipLength(tlv25,tlv24);
    }
    if (tlv2 == -1) {
 {
     const char tlv59 [ ] = "!!Failed to skip opening brace\n";
    	cgc_printf(tlv59);
 }
	return aphelion;
    }
    /// Skip any additional whitespace
    {
        pstring tlv26;
        tlv26 = str;
        start = cgc_skipWhiteSpace(tlv26);
    }
    /// This should skip any to either whitespace or a closing '}'
    {
        pstring tlv27;
        tlv27 = str;
        end = cgc_skipToNonAlphaNum(tlv27);
    }
    if (end == -1) {
 {
     const char tlv60 [ ] = "!!Failed to locate the end of the element id\n";
    	cgc_printf(tlv60);
 }
	return aphelion;
    }
    /// Copy the element id from the string
    {
        pstring tlv30;
        tlv30 = str;
        int tlv29;
        tlv29 = start;
        int tlv28;
        tlv28 = end;
        temp = cgc_copyData(tlv30,tlv29,tlv28);
    }
    if (temp == NULL) {
	cgc_printf("!!Copy from @d to @d failed\n", start, end);
	return -1.0;
    }
    /// If the element id is not "Aphelion" then this is the wrong function
    int tlv3;
    {
        const char* tlv32 = temp;
        const char tlv31 [ ] = "Aphelion";
        tlv3 = cgc_strcmp(tlv32,tlv31);
    }
    if (tlv3 != 0) {
 {
     const char tlv61 [ ] = "!!Element id is not \"Aphelion\"\n";
    	cgc_printf(tlv61);
 }
 {
     void* tlv63;
     tlv63 = temp;
     cgc_size_t tlv62;
     {
         char* tlv79;
          tlv79 = temp;
         tlv62 = cgc_strlen(tlv79) + 1;
     }
    	cgc_deallocate(tlv63,tlv62);
 }
	temp = NULL;
	return aphelion;
    }
    /// The buffer is no longer needed so free it
    {
        void* tlv12;
        tlv12 = temp;
        cgc_size_t tlv11;
        {
            char* tlv76;
             tlv76 = temp;
            tlv11 = cgc_strlen(tlv76) + 1;
        }
        cgc_deallocate(tlv12,tlv11);
    }
    /// Skip to the end of the element id
    cgc_skipWhiteSpace(str);
    /// If it is not a closing brace then this is improperly formatted.
    int tlv4;
    {
        pstring tlv34;
        tlv34 = str;
        char tlv33;
        tlv33 = '}';
        tlv4 = cgc_atChar(tlv34,tlv33);
    }
    if (!tlv4) {
 {
     const char tlv64 [ ] = "!!Failed to locate initial closing brace\n";
    	cgc_printf(tlv64);
 }
	return -1.0;
    }
    /// Skip the closing brace as well as any whitespace
    int tlv5;
    {
        pstring tlv36;
        tlv36 = str;
        int tlv35;
        tlv35 = 1;
        tlv5 = cgc_skipLength(tlv36,tlv35);
    }
    if (tlv5 == -1) {
 {
     const char tlv65 [ ] = "!!Failed to skip initial closing brace\n";
    	cgc_printf(tlv65);
 }
	return aphelion;
    }
    cgc_skipWhiteSpace(str);
    /// Copy the start index to store the data
    {
        pstring tlv14;
        tlv14 = str;
        int* tlv13;
        tlv13 = & ps;
        cgc_getIndex(tlv14,tlv13);
    }
    /// The period data must be a float
    {
        pstring tlv37;
        tlv37 = str;
        pe = cgc_skipFloat(tlv37);
    }
    if (pe == -1) {
 {
     const char tlv66 [ ] = "!!Failed to locate the end of the period data\n";
    	cgc_printf(tlv66);
 }
	return aphelion;
    }
    /// The rest of this code is a check to ensure proper formatting except for the copy data
    cgc_skipWhiteSpace(str);
    /// If this is not an opening curly brace then fail
    int tlv6;
    {
        pstring tlv39;
        tlv39 = str;
        char tlv38;
        tlv38 = '{';
        tlv6 = cgc_atChar(tlv39,tlv38);
    }
    if (!tlv6) {
 {
     const char tlv67 [ ] = "!!Failed to locate the final opening brace\n";
    	cgc_printf(tlv67);
 }
	return -1.0;
    }
    /// Skip past the brace
    int tlv7;
    {
        pstring tlv41;
        tlv41 = str;
        int tlv40;
        tlv40 = 1;
        tlv7 = cgc_skipLength(tlv41,tlv40);
    }
    if (tlv7 == -1) {
 {
     const char tlv68 [ ] = "!!Failed to skip the final opening brace\n";
    	cgc_printf(tlv68);
 }
	return aphelion;
    }

    cgc_skipWhiteSpace(str);
    /// If this is not a # indicating the closing brace then fail
    int tlv8;
    {
        pstring tlv43;
        tlv43 = str;
        char tlv42;
        tlv42 = '#';
        tlv8 = cgc_atChar(tlv43,tlv42);
    }
    if (!tlv8) {
 {
     const char tlv69 [ ] = "!!Failed to locate the closing mark\n";
    	cgc_printf(tlv69);
 }
	return -1.0;
    }
    /// Skip past the # but save the start
    {
        pstring tlv45;
        tlv45 = str;
        int tlv44;
        tlv44 = 1;
        start = cgc_skipLength(tlv45,tlv44);
    }
    if (start == -1) {
 {
     const char tlv70 [ ] = "!!Failed to skip closing mark\n";
    	cgc_printf(tlv70);
 }
	return aphelion;
    }
    {
        pstring tlv46;
        tlv46 = str;
        end = cgc_skipToNonAlphaNum(tlv46);
    }
    if (end == -1) {
 {
     const char tlv71 [ ] = "!!Failed to locate the end of the closing element id\n";
    	cgc_printf(tlv71);
 }
	return -1.0;
    }

    {
        pstring tlv49;
        tlv49 = str;
        int tlv48;
        tlv48 = start;
        int tlv47;
        tlv47 = end;
        temp = cgc_copyData(tlv49,tlv48,tlv47);
    }
    int tlv9;
    {
        const char* tlv51 = temp;
        const char tlv50 [ ] = "Aphelion";
        tlv9 = cgc_strcmp(tlv51,tlv50);
    }
    if (tlv9 != 0) {
	cgc_printf("!!Invalid closing element id: @s\n", temp);
 {
     void* tlv73;
     tlv73 = temp;
     cgc_size_t tlv72;
     {
         char* tlv80;
          tlv80 = temp;
         tlv72 = cgc_strlen(tlv80) + 1;
     }
    	cgc_deallocate(tlv73,tlv72);
 }
	return aphelion;
    }
    {
        void* tlv16;
        tlv16 = temp;
        cgc_size_t tlv15;
        {
            char* tlv77;
             tlv77 = temp;
            tlv15 = cgc_strlen(tlv77) + 1;
        }
        cgc_deallocate(tlv16,tlv15);
    }
    cgc_skipWhiteSpace(str);
    /// Check the final curly brace
    int tlv10;
    {
        pstring tlv53;
        tlv53 = str;
        char tlv52;
        tlv52 = '}';
        tlv10 = cgc_atChar(tlv53,tlv52);
    }
    if (!tlv10) {
 {
     const char tlv74 [ ] = "!!Failed to locate final closing brace\n";
    	cgc_printf(tlv74);
 }
	return -1.0;
    }
    /// Skip past the closing brace
    {
        pstring tlv18;
        tlv18 = str;
        int tlv17;
        tlv17 = 1;
        cgc_skipLength(tlv18,tlv17);
    }

    /// Copy the name element data
    {
        pstring tlv56;
        tlv56 = str;
        int tlv55;
        tlv55 = ps;
        int tlv54;
        tlv54 = pe;
        temp = cgc_copyData(tlv56,tlv55,tlv54);
    }
    if (temp == NULL) {
 {
     const char tlv75 [ ] = "!!Failed to copy period data\n";
    	cgc_printf(tlv75);
 }
	return -1;
    }
    {
        const char* tlv57 = temp;
        aphelion = cgc_atof(tlv57);
    }
    {
        void* tlv20;
        tlv20 = temp;
        cgc_size_t tlv19;
        {
            char* tlv78;
             tlv78 = temp;
            tlv19 = cgc_strlen(tlv78) + 1;
        }
        cgc_deallocate(tlv20,tlv19);
    }
    return aphelion;
}

void fix_ingred_planetParsers_8_0_1();
void fix_ingred_planetParsers_8_0();
void fix_ingred_planetParsers_8_21_1();
void fix_ingred_planetParsers_8_21();
void fix_ingred_planetParsers_8();
double cgc_extractPerihelion(pstring str)
{
if (fix_ingred_enable){ fix_ingred_planetParsers_8(); };
    char* temp;
     temp = NULL;
    double perihelion;
    perihelion = - 1.0;
    int start;
    start = 0;
    int end;
    end = 0;
    /// These will be used specifically for the data
    int ps;
    ps = 0;
    int pe;
    pe = 0;
    if (str == NULL) {
	return -1.0;
    }
    {
        pstring tlv21;
        tlv21 = str;
        start = cgc_skipWhiteSpace(tlv21);
    }
    int tlv1;
    {
        pstring tlv23;
        tlv23 = str;
        char tlv22;
        tlv22 = '{';
        tlv1 = cgc_atChar(tlv23,tlv22);
    }
    if (!tlv1) {
 {
     const char tlv57 [ ] = "!!Failed to locate opening brace\n";
    	cgc_printf(tlv57);
 }
	return perihelion;
    }
    /// Skip past the curly brace
    int tlv2;
    {
        pstring tlv25;
        tlv25 = str;
        int tlv24;
        tlv24 = 1;
        tlv2 = cgc_skipLength(tlv25,tlv24);
    }
    if (tlv2 == -1) {
 {
     const char tlv58 [ ] = "!!Failed to skip opening brace\n";
    	cgc_printf(tlv58);
 }
	return perihelion;
    }
    /// Skip any additional whitespace
    {
        pstring tlv26;
        tlv26 = str;
        start = cgc_skipWhiteSpace(tlv26);
    }
    /// This should skip any to either whitespace or a closing '}'
    {
        pstring tlv27;
        tlv27 = str;
        end = cgc_skipToNonAlphaNum(tlv27);
    }
    if (end == -1) {
 {
     const char tlv59 [ ] = "!!Failed to locate the end of the element id\n";
    	cgc_printf(tlv59);
 }
	return perihelion;
    }
    /// Copy the element id from the string
    {
        pstring tlv30;
        tlv30 = str;
        int tlv29;
        tlv29 = start;
        int tlv28;
        tlv28 = end;
        temp = cgc_copyData(tlv30,tlv29,tlv28);
    }
    if (temp == NULL) {
	cgc_printf("!!Copy from @d to @d failed\n", start, end);
	return -1.0;
    }
    /// If the element id is not "Perihelion" then this is the wrong function
    int tlv3;
    {
        const char* tlv32 = temp;
        const char tlv31 [ ] = "Perihelion";
        tlv3 = cgc_strcmp(tlv32,tlv31);
    }
    if (tlv3 != 0) {
 {
     const char tlv60 [ ] = "!!Element id is not \"Perihelion\"\n";
    	cgc_printf(tlv60);
 }
 {
     void* tlv62;
     tlv62 = temp;
     cgc_size_t tlv61;
     {
         char* tlv78;
          tlv78 = temp;
         tlv61 = cgc_strlen(tlv78) + 1;
     }
    	cgc_deallocate(tlv62,tlv61);
 }
	temp = NULL;
	return perihelion;
    }
    /// The buffer is no longer needed so free it
    {
        void* tlv12;
        tlv12 = temp;
        cgc_size_t tlv11;
        {
            char* tlv75;
             tlv75 = temp;
            tlv11 = cgc_strlen(tlv75) + 1;
        }
        cgc_deallocate(tlv12,tlv11);
    }
    /// Skip to the end of the element id
    cgc_skipWhiteSpace(str);
    /// If it is not a closing brace then this is improperly formatted.
    int tlv4;
    {
        pstring tlv34;
        tlv34 = str;
        char tlv33;
        tlv33 = '}';
        tlv4 = cgc_atChar(tlv34,tlv33);
    }
    if (!tlv4) {
 {
     const char tlv63 [ ] = "!!Failed to locate initial closing brace\n";
    	cgc_printf(tlv63);
 }
	return -1.0;
    }
    /// Skip the closing brace as well as any whitespace
    int tlv5;
    {
        pstring tlv36;
        tlv36 = str;
        int tlv35;
        tlv35 = 1;
        tlv5 = cgc_skipLength(tlv36,tlv35);
    }
    if (tlv5 == -1) {
 {
     const char tlv64 [ ] = "!!Failed to skip initial closing brace\n";
    	cgc_printf(tlv64);
 }
	return perihelion;
    }
    cgc_skipWhiteSpace(str);
    /// Copy the start index to store the data
    {
        pstring tlv14;
        tlv14 = str;
        int* tlv13;
        tlv13 = & ps;
        cgc_getIndex(tlv14,tlv13);
    }
    /// The period data must be a float
    {
        pstring tlv37;
        tlv37 = str;
        pe = cgc_skipFloat(tlv37);
    }
    if (pe == -1) {
 {
     const char tlv65 [ ] = "!!Failed to locate the end of the perihelion data\n";
    	cgc_printf(tlv65);
 }
	return perihelion;
    }
    /// The rest of this code is a check to ensure proper formatting except for the copy data
    cgc_skipWhiteSpace(str);
    /// If this is not an opening curly brace then fail
    int tlv6;
    {
        pstring tlv39;
        tlv39 = str;
        char tlv38;
        tlv38 = '{';
        tlv6 = cgc_atChar(tlv39,tlv38);
    }
    if (!tlv6) {
 {
     const char tlv66 [ ] = "!!Failed to locate the final opening brace\n";
    	cgc_printf(tlv66);
 }
	return -1.0;
    }
    /// Skip past the brace
    int tlv7;
    {
        pstring tlv40;
        tlv40 = str;
        tlv7 = cgc_incChar(tlv40);
    }
    if (tlv7 == -1) {
 {
     const char tlv67 [ ] = "!!Failed to skip the final opening brace\n";
    	cgc_printf(tlv67);
 }
	return perihelion;
    }

    cgc_skipWhiteSpace(str);
    /// If this is not a # indicating the closing brace then fail
    int tlv8;
    {
        pstring tlv42;
        tlv42 = str;
        char tlv41;
        tlv41 = '#';
        tlv8 = cgc_atChar(tlv42,tlv41);
    }
    if (!tlv8) {
 {
     const char tlv68 [ ] = "!!Failed to locate the closing mark\n";
    	cgc_printf(tlv68);
 }
	return -1.0;
    }
    /// Skip past the # but save the start
    {
        pstring tlv44;
        tlv44 = str;
        int tlv43;
        tlv43 = 1;
        start = cgc_skipLength(tlv44,tlv43);
    }
    if (start == -1) {
 {
     const char tlv69 [ ] = "!!Failed to skip closing mark\n";
    	cgc_printf(tlv69);
 }
	return perihelion;
    }
    {
        pstring tlv45;
        tlv45 = str;
        end = cgc_skipToNonAlphaNum(tlv45);
    }
    if (end == -1) {
 {
     const char tlv70 [ ] = "!!Failed to locate the end of the closing element id\n";
    	cgc_printf(tlv70);
 }
	return -1.0;
    }

    {
        pstring tlv48;
        tlv48 = str;
        int tlv47;
        tlv47 = start;
        int tlv46;
        tlv46 = end;
        temp = cgc_copyData(tlv48,tlv47,tlv46);
    }
    int tlv9;
    {
        const char* tlv50 = temp;
        const char tlv49 [ ] = "Perihelion";
        tlv9 = cgc_strcmp(tlv50,tlv49);
    }
    if (tlv9 != 0) {
	cgc_printf("!!Invalid closing element id: @s\n", temp);
 {
     void* tlv72;
     tlv72 = temp;
     cgc_size_t tlv71;
     {
         char* tlv79;
          tlv79 = temp;
         tlv71 = cgc_strlen(tlv79) + 1;
     }
    	cgc_deallocate(tlv72,tlv71);
 }
	return perihelion;
    }
    {
        void* tlv16;
        tlv16 = temp;
        cgc_size_t tlv15;
        {
            char* tlv76;
             tlv76 = temp;
            tlv15 = cgc_strlen(tlv76) + 1;
        }
        cgc_deallocate(tlv16,tlv15);
    }
    cgc_skipWhiteSpace(str);
    /// Check the final curly brace
    int tlv10;
    {
        pstring tlv52;
        tlv52 = str;
        char tlv51;
        tlv51 = '}';
        tlv10 = cgc_atChar(tlv52,tlv51);
    }
    if (!tlv10) {
 {
     const char tlv73 [ ] = "!!Failed to locate final closing brace\n";
    	cgc_printf(tlv73);
 }
	return -1.0;
    }
    /// Skip past the closing brace
    {
        pstring tlv18;
        tlv18 = str;
        int tlv17;
        tlv17 = 1;
        cgc_skipLength(tlv18,tlv17);
    }

    /// Copy the name element data
    {
        pstring tlv55;
        tlv55 = str;
        int tlv54;
        tlv54 = ps;
        int tlv53;
        tlv53 = pe;
        temp = cgc_copyData(tlv55,tlv54,tlv53);
    }
    if (temp == NULL) {
 {
     const char tlv74 [ ] = "!!Failed to copy perihelion data\n";
    	cgc_printf(tlv74);
 }
	return -1;
    }
    {
        const char* tlv56 = temp;
        perihelion = cgc_atof(tlv56);
    }
    {
        void* tlv20;
        tlv20 = temp;
        cgc_size_t tlv19;
        {
            char* tlv77;
             tlv77 = temp;
            tlv19 = cgc_strlen(tlv77) + 1;
        }
        cgc_deallocate(tlv20,tlv19);
    }
    return perihelion;
}

void fix_ingred_planetParsers_9_0_0();
void fix_ingred_planetParsers_9_0_1();
void fix_ingred_planetParsers_9_0_2();
void fix_ingred_planetParsers_9_0();
void fix_ingred_planetParsers_9_3_1();
void fix_ingred_planetParsers_9_3();
void fix_ingred_planetParsers_9_7_6();
void fix_ingred_planetParsers_9_7_7();
void fix_ingred_planetParsers_9_7();
void fix_ingred_planetParsers_9_11_6();
void fix_ingred_planetParsers_9_11();
void fix_ingred_planetParsers_9_13_1();
void fix_ingred_planetParsers_9_13();
void fix_ingred_planetParsers_9_14_6();
void fix_ingred_planetParsers_9_14();
void fix_ingred_planetParsers_9_16_7();
void fix_ingred_planetParsers_9_16();
void fix_ingred_planetParsers_9_18_0();
void fix_ingred_planetParsers_9_18();
void fix_ingred_planetParsers_9_19_1();
void fix_ingred_planetParsers_9_19();
void fix_ingred_planetParsers_9_21_1();
void fix_ingred_planetParsers_9_21();
void fix_ingred_planetParsers_9_22_1();
void fix_ingred_planetParsers_9_22();
void fix_ingred_planetParsers_9_26_6();
void fix_ingred_planetParsers_9_26();
void fix_ingred_planetParsers_9_28_1();
void fix_ingred_planetParsers_9_28();
void fix_ingred_planetParsers_9_30_6();
void fix_ingred_planetParsers_9_30();
void fix_ingred_planetParsers_9_36_6();
void fix_ingred_planetParsers_9_36();
void fix_ingred_planetParsers_9_38_1();
void fix_ingred_planetParsers_9_38();
void fix_ingred_planetParsers_9_49_6();
void fix_ingred_planetParsers_9_49();
void fix_ingred_planetParsers_9_51_1();
void fix_ingred_planetParsers_9_51();
void fix_ingred_planetParsers_9_53_1();
void fix_ingred_planetParsers_9_53();
void fix_ingred_planetParsers_9_57_1();
void fix_ingred_planetParsers_9_57();
void fix_ingred_planetParsers_9_58_1();
void fix_ingred_planetParsers_9_58();
void fix_ingred_planetParsers_9_63_1();
void fix_ingred_planetParsers_9_63();
void fix_ingred_planetParsers_9();
double cgc_extractRadius(pstring str)
{
if (fix_ingred_enable){ fix_ingred_planetParsers_9(); };
    char* temp;
     temp = NULL;
    double radius;
    radius = - 1.0;
    int start;
    start = 0;
    int end;
    end = 0;
    /// These will be used specifically for the data
    int rs;
    rs = 0;
    int re;
    re = 0;
    if (str == NULL) {
	return -1.0;
    }
    {
        pstring tlv21;
        tlv21 = str;
        start = cgc_skipWhiteSpace(tlv21);
    }
    int tlv1;
    {
        pstring tlv23;
        tlv23 = str;
        char tlv22;
        tlv22 = '{';
        tlv1 = cgc_atChar(tlv23,tlv22);
    }
    if (!tlv1) {
 {
     const char tlv54 [ ] = "!!Failed to locate opening brace\n";
    	cgc_printf(tlv54);
 }
	return radius;
    }
    /// Skip past the curly brace
    int tlv2;
    {
        pstring tlv24;
        tlv24 = str;
        tlv2 = cgc_incChar(tlv24);
    }
    if (tlv2 == -1) {
 {
     const char tlv55 [ ] = "!!Failed to skip opening brace\n";
    	cgc_printf(tlv55);
 }
	return radius;
    }
    /// Skip any additional whitespace
    {
        pstring tlv25;
        tlv25 = str;
        start = cgc_skipWhiteSpace(tlv25);
    }
    /// This should skip any to either whitespace or a closing '}'
    {
        pstring tlv26;
        tlv26 = str;
        end = cgc_skipToNonAlphaNum(tlv26);
    }
    if (end == -1) {
 {
     const char tlv56 [ ] = "!!Failed to locate the end of the element id\n";
    	cgc_printf(tlv56);
 }
	return radius;
    }
    /// Copy the element id from the string
    {
        pstring tlv29;
        tlv29 = str;
        int tlv28;
        tlv28 = start;
        int tlv27;
        tlv27 = end;
        temp = cgc_copyData(tlv29,tlv28,tlv27);
    }
    if (temp == NULL) {
	cgc_printf("!!Copy from @d to @d failed\n", start, end);
	return -1.0;
    }
    /// If the element id is not "Radius" then this is the wrong function
    int tlv3;
    {
        const char* tlv31 = temp;
        const char tlv30 [ ] = "Radius";
        tlv3 = cgc_strcmp(tlv31,tlv30);
    }
    if (tlv3 != 0) {
 {
     const char tlv57 [ ] = "!!Element id is not \"Radius\"\n";
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
	return radius;
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
        pstring tlv33;
        tlv33 = str;
        char tlv32;
        tlv32 = '}';
        tlv4 = cgc_atChar(tlv33,tlv32);
    }
    if (!tlv4) {
 {
     const char tlv60 [ ] = "!!Failed to locate initial closing brace\n";
    	cgc_printf(tlv60);
 }
	return -1.0;
    }
    /// Skip the closing brace as well as any whitespace
    int tlv5;
    {
        pstring tlv34;
        tlv34 = str;
        tlv5 = cgc_incChar(tlv34);
    }
    if (tlv5 == -1) {
 {
     const char tlv61 [ ] = "!!Failed to skip initial closing brace\n";
    	cgc_printf(tlv61);
 }
	return radius;
    }
    cgc_skipWhiteSpace(str);
    /// Copy the start index to store the data
    {
        pstring tlv14;
        tlv14 = str;
        int* tlv13;
        tlv13 = & rs;
        cgc_getIndex(tlv14,tlv13);
    }
    /// The radius data must be a float
    {
        pstring tlv35;
        tlv35 = str;
        re = cgc_skipFloat(tlv35);
    }
    if (re == -1) {
 {
     const char tlv62 [ ] = "!!Failed to locate the end of the radius data\n";
    	cgc_printf(tlv62);
 }
	return radius;
    }
    /// The rest of this code is a check to ensure proper formatting except for the copy data
    cgc_skipWhiteSpace(str);
    /// If this is not an opening curly brace then fail
    int tlv6;
    {
        pstring tlv37;
        tlv37 = str;
        char tlv36;
        tlv36 = '{';
        tlv6 = cgc_atChar(tlv37,tlv36);
    }
    if (!tlv6) {
 {
     const char tlv63 [ ] = "!!Failed to locate the final opening brace\n";
    	cgc_printf(tlv63);
 }
	return -1.0;
    }
    /// Skip past the brace
    int tlv7;
    {
        pstring tlv38;
        tlv38 = str;
        tlv7 = cgc_incChar(tlv38);
    }
    if (tlv7 == -1) {
 {
     const char tlv64 [ ] = "!!Failed to skip the final opening brace\n";
    	cgc_printf(tlv64);
 }
	return radius;
    }

    cgc_skipWhiteSpace(str);
    /// If this is not a # indicating the closing brace then fail
    int tlv8;
    {
        pstring tlv40;
        tlv40 = str;
        char tlv39;
        tlv39 = '#';
        tlv8 = cgc_atChar(tlv40,tlv39);
    }
    if (!tlv8) {
 {
     const char tlv65 [ ] = "!!Failed to locate the closing mark\n";
    	cgc_printf(tlv65);
 }
	return -1.0;
    }
    /// Skip past the # but save the start
    {
        pstring tlv41;
        tlv41 = str;
        start = cgc_incChar(tlv41);
    }
    if (start == -1) {
 {
     const char tlv66 [ ] = "!!Failed to skip closing mark\n";
    	cgc_printf(tlv66);
 }
	return radius;
    }
    {
        pstring tlv42;
        tlv42 = str;
        end = cgc_skipToNonAlphaNum(tlv42);
    }
    if (end == -1) {
 {
     const char tlv67 [ ] = "!!Failed to locate the end of the closing element id\n";
    	cgc_printf(tlv67);
 }
	return -1.0;
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
        const char tlv46 [ ] = "Radius";
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
	return radius;
    }
    {
        void* tlv16;
        tlv16 = temp;
        cgc_size_t tlv15;
        {
            char* tlv73;
             tlv73 = temp;
            tlv15 = cgc_strlen(tlv73) + 1;
        }
        cgc_deallocate(tlv16,tlv15);
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
	return -1.0;
    }
    /// Skip past the closing brace
    {
        pstring tlv18;
        tlv18 = str;
        int tlv17;
        tlv17 = 1;
        cgc_skipLength(tlv18,tlv17);
    }

    /// Copy the name element data
    {
        pstring tlv52;
        tlv52 = str;
        int tlv51;
        tlv51 = rs;
        int tlv50;
        tlv50 = re;
        temp = cgc_copyData(tlv52,tlv51,tlv50);
    }
    if (temp == NULL) {
 {
     const char tlv71 [ ] = "!!Failed to copy radius data\n";
    	cgc_printf(tlv71);
 }
	return -1.0;
    }
    {
        const char* tlv53 = temp;
        radius = cgc_atof(tlv53);
    }
    {
        void* tlv20;
        tlv20 = temp;
        cgc_size_t tlv19;
        {
            char* tlv74;
             tlv74 = temp;
            tlv19 = cgc_strlen(tlv74) + 1;
        }
        cgc_deallocate(tlv20,tlv19);
    }
    return radius;
}

void fix_ingred_planetParsers_10_0_0();
void fix_ingred_planetParsers_10_0_1();
void fix_ingred_planetParsers_10_0_2();
void fix_ingred_planetParsers_10_0();
void fix_ingred_planetParsers_10_3_1();
void fix_ingred_planetParsers_10_3();
void fix_ingred_planetParsers_10_6_1();
void fix_ingred_planetParsers_10_6();
void fix_ingred_planetParsers_10_7_6();
void fix_ingred_planetParsers_10_7_7();
void fix_ingred_planetParsers_10_7();
void fix_ingred_planetParsers_10_11_6();
void fix_ingred_planetParsers_10_11();
void fix_ingred_planetParsers_10_13_1();
void fix_ingred_planetParsers_10_13();
void fix_ingred_planetParsers_10_14_6();
void fix_ingred_planetParsers_10_14();
void fix_ingred_planetParsers_10_16_7();
void fix_ingred_planetParsers_10_16();
void fix_ingred_planetParsers_10_18_0();
void fix_ingred_planetParsers_10_18();
void fix_ingred_planetParsers_10_19_1();
void fix_ingred_planetParsers_10_19();
void fix_ingred_planetParsers_10_21_1();
void fix_ingred_planetParsers_10_21();
void fix_ingred_planetParsers_10_22_1();
void fix_ingred_planetParsers_10_22();
void fix_ingred_planetParsers_10_26_6();
void fix_ingred_planetParsers_10_26();
void fix_ingred_planetParsers_10_28_1();
void fix_ingred_planetParsers_10_28();
void fix_ingred_planetParsers_10_30_6();
void fix_ingred_planetParsers_10_30();
void fix_ingred_planetParsers_10_36_6();
void fix_ingred_planetParsers_10_36();
void fix_ingred_planetParsers_10_38_1();
void fix_ingred_planetParsers_10_38();
void fix_ingred_planetParsers_10_49_6();
void fix_ingred_planetParsers_10_49();
void fix_ingred_planetParsers_10_51_1();
void fix_ingred_planetParsers_10_51();
void fix_ingred_planetParsers_10_53_1();
void fix_ingred_planetParsers_10_53();
void fix_ingred_planetParsers_10_58_1();
void fix_ingred_planetParsers_10_58();
void fix_ingred_planetParsers_10_63_1();
void fix_ingred_planetParsers_10_63();
void fix_ingred_planetParsers_10();
double cgc_extractERadius(pstring str)
{
if (fix_ingred_enable){ fix_ingred_planetParsers_10(); };
    char* temp;
     temp = NULL;
    double eradius;
    eradius = - 1.0;
    int start;
    start = 0;
    int end;
    end = 0;
    /// These will be used specifically for the data
    int es;
    es = 0;
    int ee;
    ee = 0;
    if (str == NULL) {
	return -1.0;
    }
    {
        pstring tlv21;
        tlv21 = str;
        start = cgc_skipWhiteSpace(tlv21);
    }
    int tlv1;
    {
        pstring tlv23;
        tlv23 = str;
        char tlv22;
        tlv22 = '{';
        tlv1 = cgc_atChar(tlv23,tlv22);
    }
    if (!tlv1) {
 {
     const char tlv57 [ ] = "!!Failed to locate opening brace\n";
    	cgc_printf(tlv57);
 }
	return eradius;
    }
    /// Skip past the curly brace
    int tlv2;
    {
        pstring tlv25;
        tlv25 = str;
        int tlv24;
        tlv24 = 1;
        tlv2 = cgc_skipLength(tlv25,tlv24);
    }
    if (tlv2 == -1) {
 {
     const char tlv58 [ ] = "!!Failed to skip opening brace\n";
    	cgc_printf(tlv58);
 }
	return eradius;
    }
    /// Skip any additional whitespace
    {
        pstring tlv26;
        tlv26 = str;
        start = cgc_skipWhiteSpace(tlv26);
    }
    /// This should skip any to either whitespace or a closing '}'
    {
        pstring tlv27;
        tlv27 = str;
        end = cgc_skipToNonAlphaNum(tlv27);
    }
    if (end == -1) {
 {
     const char tlv59 [ ] = "!!Failed to locate the end of the element id\n";
    	cgc_printf(tlv59);
 }
	return eradius;
    }
    /// Copy the element id from the string
    {
        pstring tlv30;
        tlv30 = str;
        int tlv29;
        tlv29 = start;
        int tlv28;
        tlv28 = end;
        temp = cgc_copyData(tlv30,tlv29,tlv28);
    }
    if (temp == NULL) {
	cgc_printf("!!Copy from @d to @d failed\n", start, end);
	return -1.0;
    }
    /// If the element id is not "ERadius" then this is the wrong function
    int tlv3;
    {
        const char* tlv32 = temp;
        const char tlv31 [ ] = "ERadius";
        tlv3 = cgc_strcmp(tlv32,tlv31);
    }
    if (tlv3 != 0) {
 {
     const char tlv60 [ ] = "!!Element id is not \"ERadius\"\n";
    	cgc_printf(tlv60);
 }
 {
     void* tlv62;
     tlv62 = temp;
     cgc_size_t tlv61;
     {
         char* tlv78;
          tlv78 = temp;
         tlv61 = cgc_strlen(tlv78) + 1;
     }
    	cgc_deallocate(tlv62,tlv61);
 }
	temp = NULL;
	return eradius;
    }
    /// The buffer is no longer needed so free it
    {
        void* tlv12;
        tlv12 = temp;
        cgc_size_t tlv11;
        {
            char* tlv75;
             tlv75 = temp;
            tlv11 = cgc_strlen(tlv75) + 1;
        }
        cgc_deallocate(tlv12,tlv11);
    }
    /// Skip to the end of the element id
    cgc_skipWhiteSpace(str);
    /// If it is not a closing brace then this is improperly formatted.
    int tlv4;
    {
        pstring tlv34;
        tlv34 = str;
        char tlv33;
        tlv33 = '}';
        tlv4 = cgc_atChar(tlv34,tlv33);
    }
    if (!tlv4) {
 {
     const char tlv63 [ ] = "!!Failed to locate initial closing brace\n";
    	cgc_printf(tlv63);
 }
	return -1.0;
    }
    /// Skip the closing brace as well as any whitespace
    int tlv5;
    {
        pstring tlv36;
        tlv36 = str;
        int tlv35;
        tlv35 = 1;
        tlv5 = cgc_skipLength(tlv36,tlv35);
    }
    if (tlv5 == -1) {
 {
     const char tlv64 [ ] = "!!Failed to skip initial closing brace\n";
    	cgc_printf(tlv64);
 }
	return eradius;
    }
    cgc_skipWhiteSpace(str);
    /// Copy the start index to store the data
    {
        pstring tlv14;
        tlv14 = str;
        int* tlv13;
        tlv13 = & es;
        cgc_getIndex(tlv14,tlv13);
    }
    /// The eradius data must be a float
    {
        pstring tlv37;
        tlv37 = str;
        ee = cgc_skipFloat(tlv37);
    }
    if (ee == -1) {
 {
     const char tlv65 [ ] = "!!Failed to locate the end of the eradius data\n";
    	cgc_printf(tlv65);
 }
	return eradius;
    }
    /// The rest of this code is a check to ensure proper formatting except for the copy data
    cgc_skipWhiteSpace(str);
    /// If this is not an opening curly brace then fail
    int tlv6;
    {
        pstring tlv39;
        tlv39 = str;
        char tlv38;
        tlv38 = '{';
        tlv6 = cgc_atChar(tlv39,tlv38);
    }
    if (!tlv6) {
 {
     const char tlv66 [ ] = "!!Failed to locate the final opening brace\n";
    	cgc_printf(tlv66);
 }
	return -1.0;
    }
    /// Skip past the brace
    int tlv7;
    {
        pstring tlv40;
        tlv40 = str;
        tlv7 = cgc_incChar(tlv40);
    }
    if (tlv7 == -1) {
 {
     const char tlv67 [ ] = "!!Failed to skip the final opening brace\n";
    	cgc_printf(tlv67);
 }
	return eradius;
    }

    cgc_skipWhiteSpace(str);
    /// If this is not a # indicating the closing brace then fail
    int tlv8;
    {
        pstring tlv42;
        tlv42 = str;
        char tlv41;
        tlv41 = '#';
        tlv8 = cgc_atChar(tlv42,tlv41);
    }
    if (!tlv8) {
 {
     const char tlv68 [ ] = "!!Failed to locate the closing mark\n";
    	cgc_printf(tlv68);
 }
	return -1.0;
    }
    /// Skip past the # but save the start
    {
        pstring tlv44;
        tlv44 = str;
        int tlv43;
        tlv43 = 1;
        start = cgc_skipLength(tlv44,tlv43);
    }
    if (start == -1) {
 {
     const char tlv69 [ ] = "!!Failed to skip closing mark\n";
    	cgc_printf(tlv69);
 }
	return eradius;
    }
    {
        pstring tlv45;
        tlv45 = str;
        end = cgc_skipToNonAlphaNum(tlv45);
    }
    if (end == -1) {
 {
     const char tlv70 [ ] = "!!Failed to locate the end of the closing element id\n";
    	cgc_printf(tlv70);
 }
	return -1.0;
    }

    {
        pstring tlv48;
        tlv48 = str;
        int tlv47;
        tlv47 = start;
        int tlv46;
        tlv46 = end;
        temp = cgc_copyData(tlv48,tlv47,tlv46);
    }
    int tlv9;
    {
        const char* tlv50 = temp;
        const char tlv49 [ ] = "ERadius";
        tlv9 = cgc_strcmp(tlv50,tlv49);
    }
    if (tlv9 != 0) {
	cgc_printf("!!Invalid closing element id: @s\n", temp);
 {
     void* tlv72;
     tlv72 = temp;
     cgc_size_t tlv71;
     {
         char* tlv79;
          tlv79 = temp;
         tlv71 = cgc_strlen(tlv79) + 1;
     }
    	cgc_deallocate(tlv72,tlv71);
 }
	return eradius;
    }
    {
        void* tlv16;
        tlv16 = temp;
        cgc_size_t tlv15;
        {
            char* tlv76;
             tlv76 = temp;
            tlv15 = cgc_strlen(tlv76) + 1;
        }
        cgc_deallocate(tlv16,tlv15);
    }
    cgc_skipWhiteSpace(str);
    /// Check the final curly brace
    int tlv10;
    {
        pstring tlv52;
        tlv52 = str;
        char tlv51;
        tlv51 = '}';
        tlv10 = cgc_atChar(tlv52,tlv51);
    }
    if (!tlv10) {
 {
     const char tlv73 [ ] = "!!Failed to locate final closing brace\n";
    	cgc_printf(tlv73);
 }
	return -1.0;
    }
    /// Skip past the closing brace
    {
        pstring tlv18;
        tlv18 = str;
        int tlv17;
        tlv17 = 1;
        cgc_skipLength(tlv18,tlv17);
    }

    /// Copy the eradius element data
    {
        pstring tlv55;
        tlv55 = str;
        int tlv54;
        tlv54 = es;
        int tlv53;
        tlv53 = ee;
        temp = cgc_copyData(tlv55,tlv54,tlv53);
    }
    if (temp == NULL) {
 {
     const char tlv74 [ ] = "!!Failed to copy eradius data\n";
    	cgc_printf(tlv74);
 }
	return -1;
    }
    {
        const char* tlv56 = temp;
        eradius = cgc_atof(tlv56);
    }
    {
        void* tlv20;
        tlv20 = temp;
        cgc_size_t tlv19;
        {
            char* tlv77;
             tlv77 = temp;
            tlv19 = cgc_strlen(tlv77) + 1;
        }
        cgc_deallocate(tlv20,tlv19);
    }
    return eradius;
}

void fix_ingred_planetParsers_11_0_1();
void fix_ingred_planetParsers_11_0();
void fix_ingred_planetParsers_11();
double cgc_extractMass(pstring str)
{
if (fix_ingred_enable){ fix_ingred_planetParsers_11(); };
    char* temp;
     temp = NULL;
    double mass;
    mass = - 1.0;
    int start;
    start = 0;
    int end;
    end = 0;
    /// These will be used specifically for the data
    int es;
    es = 0;
    int ee;
    ee = 0;
    if (str == NULL) {
	return -1.0;
    }
    {
        pstring tlv21;
        tlv21 = str;
        start = cgc_skipWhiteSpace(tlv21);
    }
    int tlv1;
    {
        pstring tlv23;
        tlv23 = str;
        char tlv22;
        tlv22 = '{';
        tlv1 = cgc_atChar(tlv23,tlv22);
    }
    if (!tlv1) {
 {
     const char tlv57 [ ] = "!!Failed to locate opening brace\n";
    	cgc_printf(tlv57);
 }
	return mass;
    }
    /// Skip past the curly brace
    int tlv2;
    {
        pstring tlv25;
        tlv25 = str;
        int tlv24;
        tlv24 = 1;
        tlv2 = cgc_skipLength(tlv25,tlv24);
    }
    if (tlv2 == -1) {
 {
     const char tlv58 [ ] = "!!Failed to skip opening brace\n";
    	cgc_printf(tlv58);
 }
	return mass;
    }
    /// Skip any additional whitespace
    {
        pstring tlv26;
        tlv26 = str;
        start = cgc_skipWhiteSpace(tlv26);
    }
    /// This should skip any to either whitespace or a closing '}'
    {
        pstring tlv27;
        tlv27 = str;
        end = cgc_skipToNonAlphaNum(tlv27);
    }
    if (end == -1) {
 {
     const char tlv59 [ ] = "!!Failed to locate the end of the element id\n";
    	cgc_printf(tlv59);
 }
	return mass;
    }
    /// Copy the element id from the string
    {
        pstring tlv30;
        tlv30 = str;
        int tlv29;
        tlv29 = start;
        int tlv28;
        tlv28 = end;
        temp = cgc_copyData(tlv30,tlv29,tlv28);
    }
    if (temp == NULL) {
	cgc_printf("!!Copy from @d to @d failed\n", start, end);
	return -1.0;
    }
    /// If the element id is not "Mass" then this is the wrong function
    int tlv3;
    {
        const char* tlv32 = temp;
        const char tlv31 [ ] = "Mass";
        tlv3 = cgc_strcmp(tlv32,tlv31);
    }
    if (tlv3 != 0) {
 {
     const char tlv60 [ ] = "!!Element id is not \"Mass\"\n";
    	cgc_printf(tlv60);
 }
 {
     void* tlv62;
     tlv62 = temp;
     cgc_size_t tlv61;
     {
         char* tlv78;
          tlv78 = temp;
         tlv61 = cgc_strlen(tlv78) + 1;
     }
    	cgc_deallocate(tlv62,tlv61);
 }
	temp = NULL;
	return mass;
    }
    /// The buffer is no longer needed so free it
    {
        void* tlv12;
        tlv12 = temp;
        cgc_size_t tlv11;
        {
            char* tlv75;
             tlv75 = temp;
            tlv11 = cgc_strlen(tlv75) + 1;
        }
        cgc_deallocate(tlv12,tlv11);
    }
    /// Skip to the end of the element id
    cgc_skipWhiteSpace(str);
    /// If it is not a closing brace then this is improperly formatted.
    int tlv4;
    {
        pstring tlv34;
        tlv34 = str;
        char tlv33;
        tlv33 = '}';
        tlv4 = cgc_atChar(tlv34,tlv33);
    }
    if (!tlv4) {
 {
     const char tlv63 [ ] = "!!Failed to locate initial closing brace\n";
    	cgc_printf(tlv63);
 }
	return -1.0;
    }
    /// Skip the closing brace as well as any whitespace
    int tlv5;
    {
        pstring tlv36;
        tlv36 = str;
        int tlv35;
        tlv35 = 1;
        tlv5 = cgc_skipLength(tlv36,tlv35);
    }
    if (tlv5 == -1) {
 {
     const char tlv64 [ ] = "!!Failed to skip initial closing brace\n";
    	cgc_printf(tlv64);
 }
	return mass;
    }
    cgc_skipWhiteSpace(str);
    /// Copy the start index to store the data
    {
        pstring tlv14;
        tlv14 = str;
        int* tlv13;
        tlv13 = & es;
        cgc_getIndex(tlv14,tlv13);
    }
    /// The mass data must be a float
    {
        pstring tlv37;
        tlv37 = str;
        ee = cgc_skipFloat(tlv37);
    }
    if (ee == -1) {
 {
     const char tlv65 [ ] = "!!Failed to locate the end of the mass data\n";
    	cgc_printf(tlv65);
 }
	return mass;
    }
    /// The rest of this code is a check to ensure proper formatting except for the copy data
    cgc_skipWhiteSpace(str);
    /// If this is not an opening curly brace then fail
    int tlv6;
    {
        pstring tlv39;
        tlv39 = str;
        char tlv38;
        tlv38 = '{';
        tlv6 = cgc_atChar(tlv39,tlv38);
    }
    if (!tlv6) {
 {
     const char tlv66 [ ] = "!!Failed to locate the final opening brace\n";
    	cgc_printf(tlv66);
 }
	return -1.0;
    }
    /// Skip past the brace
    int tlv7;
    {
        pstring tlv40;
        tlv40 = str;
        tlv7 = cgc_incChar(tlv40);
    }
    if (tlv7 == -1) {
 {
     const char tlv67 [ ] = "!!Failed to skip the final opening brace\n";
    	cgc_printf(tlv67);
 }
	return mass;
    }

    cgc_skipWhiteSpace(str);
    /// If this is not a # indicating the closing brace then fail
    int tlv8;
    {
        pstring tlv42;
        tlv42 = str;
        char tlv41;
        tlv41 = '#';
        tlv8 = cgc_atChar(tlv42,tlv41);
    }
    if (!tlv8) {
 {
     const char tlv68 [ ] = "!!Failed to locate the closing mark\n";
    	cgc_printf(tlv68);
 }
	return -1.0;
    }
    /// Skip past the # but save the start
    {
        pstring tlv44;
        tlv44 = str;
        int tlv43;
        tlv43 = 1;
        start = cgc_skipLength(tlv44,tlv43);
    }
    if (start == -1) {
 {
     const char tlv69 [ ] = "!!Failed to skip closing mark\n";
    	cgc_printf(tlv69);
 }
	return mass;
    }
    {
        pstring tlv45;
        tlv45 = str;
        end = cgc_skipToNonAlphaNum(tlv45);
    }
    if (end == -1) {
 {
     const char tlv70 [ ] = "!!Failed to locate the end of the closing element id\n";
    	cgc_printf(tlv70);
 }
	return -1.0;
    }

    {
        pstring tlv48;
        tlv48 = str;
        int tlv47;
        tlv47 = start;
        int tlv46;
        tlv46 = end;
        temp = cgc_copyData(tlv48,tlv47,tlv46);
    }
    int tlv9;
    {
        const char* tlv50 = temp;
        const char tlv49 [ ] = "Mass";
        tlv9 = cgc_strcmp(tlv50,tlv49);
    }
    if (tlv9 != 0) {
	cgc_printf("!!Invalid closing element id: @s\n", temp);
 {
     void* tlv72;
     tlv72 = temp;
     cgc_size_t tlv71;
     {
         char* tlv79;
          tlv79 = temp;
         tlv71 = cgc_strlen(tlv79) + 1;
     }
    	cgc_deallocate(tlv72,tlv71);
 }
	return mass;
    }
    {
        void* tlv16;
        tlv16 = temp;
        cgc_size_t tlv15;
        {
            char* tlv76;
             tlv76 = temp;
            tlv15 = cgc_strlen(tlv76) + 1;
        }
        cgc_deallocate(tlv16,tlv15);
    }
    cgc_skipWhiteSpace(str);
    /// Check the final curly brace
    int tlv10;
    {
        pstring tlv52;
        tlv52 = str;
        char tlv51;
        tlv51 = '}';
        tlv10 = cgc_atChar(tlv52,tlv51);
    }
    if (!tlv10) {
 {
     const char tlv73 [ ] = "!!Failed to locate final closing brace\n";
    	cgc_printf(tlv73);
 }
	return -1.0;
    }
    /// Skip past the closing brace
    {
        pstring tlv18;
        tlv18 = str;
        int tlv17;
        tlv17 = 1;
        cgc_skipLength(tlv18,tlv17);
    }

    /// Copy the mass element data
    {
        pstring tlv55;
        tlv55 = str;
        int tlv54;
        tlv54 = es;
        int tlv53;
        tlv53 = ee;
        temp = cgc_copyData(tlv55,tlv54,tlv53);
    }
    if (temp == NULL) {
 {
     const char tlv74 [ ] = "!!Failed to copy mass data\n";
    	cgc_printf(tlv74);
 }
	return -1;
    }
    {
        const char* tlv56 = temp;
        mass = cgc_atof(tlv56);
    }
    {
        void* tlv20;
        tlv20 = temp;
        cgc_size_t tlv19;
        {
            char* tlv77;
             tlv77 = temp;
            tlv19 = cgc_strlen(tlv77) + 1;
        }
        cgc_deallocate(tlv20,tlv19);
    }
    return mass;
}

void fix_ingred_planetParsers_12_0_1();
void fix_ingred_planetParsers_12_0();
void fix_ingred_planetParsers_12();
double cgc_extractGravity(pstring str)
{
if (fix_ingred_enable){ fix_ingred_planetParsers_12(); };
    char* temp;
     temp = NULL;
    double gravity;
    gravity = - 1.0;
    int start;
    start = 0;
    int end;
    end = 0;
    /// These will be used specifically for the data
    int es;
    es = 0;
    int ee;
    ee = 0;
    if (str == NULL) {
	return -1.0;
    }
    {
        pstring tlv21;
        tlv21 = str;
        start = cgc_skipWhiteSpace(tlv21);
    }
    int tlv1;
    {
        pstring tlv23;
        tlv23 = str;
        char tlv22;
        tlv22 = '{';
        tlv1 = cgc_atChar(tlv23,tlv22);
    }
    if (!tlv1) {
 {
     const char tlv57 [ ] = "!!Failed to locate opening brace\n";
    	cgc_printf(tlv57);
 }
	return gravity;
    }
    /// Skip past the curly brace
    int tlv2;
    {
        pstring tlv25;
        tlv25 = str;
        int tlv24;
        tlv24 = 1;
        tlv2 = cgc_skipLength(tlv25,tlv24);
    }
    if (tlv2 == -1) {
 {
     const char tlv58 [ ] = "!!Failed to skip opening brace\n";
    	cgc_printf(tlv58);
 }
	return gravity;
    }
    /// Skip any additional whitespace
    {
        pstring tlv26;
        tlv26 = str;
        start = cgc_skipWhiteSpace(tlv26);
    }
    /// This should skip any to either whitespace or a closing '}'
    {
        pstring tlv27;
        tlv27 = str;
        end = cgc_skipToNonAlphaNum(tlv27);
    }
    if (end == -1) {
 {
     const char tlv59 [ ] = "!!Failed to locate the end of the element id\n";
    	cgc_printf(tlv59);
 }
	return gravity;
    }
    /// Copy the element id from the string
    {
        pstring tlv30;
        tlv30 = str;
        int tlv29;
        tlv29 = start;
        int tlv28;
        tlv28 = end;
        temp = cgc_copyData(tlv30,tlv29,tlv28);
    }
    if (temp == NULL) {
	cgc_printf("!!Copy from @d to @d failed\n", start, end);
	return -1.0;
    }
    /// If the element id is not "Gravity" then this is the wrong function
    int tlv3;
    {
        const char* tlv32 = temp;
        const char tlv31 [ ] = "Gravity";
        tlv3 = cgc_strcmp(tlv32,tlv31);
    }
    if (tlv3 != 0) {
 {
     const char tlv60 [ ] = "!!Element id is not \"Gravity\"\n";
    	cgc_printf(tlv60);
 }
 {
     void* tlv62;
     tlv62 = temp;
     cgc_size_t tlv61;
     {
         char* tlv78;
          tlv78 = temp;
         tlv61 = cgc_strlen(tlv78) + 1;
     }
    	cgc_deallocate(tlv62,tlv61);
 }
	temp = NULL;
	return gravity;
    }
    /// The buffer is no longer needed so free it
    {
        void* tlv12;
        tlv12 = temp;
        cgc_size_t tlv11;
        {
            char* tlv75;
             tlv75 = temp;
            tlv11 = cgc_strlen(tlv75) + 1;
        }
        cgc_deallocate(tlv12,tlv11);
    }
    /// Skip to the end of the element id
    cgc_skipWhiteSpace(str);
    /// If it is not a closing brace then this is improperly formatted.
    int tlv4;
    {
        pstring tlv34;
        tlv34 = str;
        char tlv33;
        tlv33 = '}';
        tlv4 = cgc_atChar(tlv34,tlv33);
    }
    if (!tlv4) {
 {
     const char tlv63 [ ] = "!!Failed to locate initial closing brace\n";
    	cgc_printf(tlv63);
 }
	return -1.0;
    }
    /// Skip the closing brace as well as any whitespace
    int tlv5;
    {
        pstring tlv36;
        tlv36 = str;
        int tlv35;
        tlv35 = 1;
        tlv5 = cgc_skipLength(tlv36,tlv35);
    }
    if (tlv5 == -1) {
 {
     const char tlv64 [ ] = "!!Failed to skip initial closing brace\n";
    	cgc_printf(tlv64);
 }
	return gravity;
    }
    cgc_skipWhiteSpace(str);
    /// Copy the start index to store the data
    {
        pstring tlv14;
        tlv14 = str;
        int* tlv13;
        tlv13 = & es;
        cgc_getIndex(tlv14,tlv13);
    }
    /// The gravity data must be a float
    {
        pstring tlv37;
        tlv37 = str;
        ee = cgc_skipFloat(tlv37);
    }
    if (ee == -1) {
 {
     const char tlv65 [ ] = "!!Failed to locate the end of the gravity data\n";
    	cgc_printf(tlv65);
 }
	return gravity;
    }
    /// The rest of this code is a check to ensure proper formatting except for the copy data
    cgc_skipWhiteSpace(str);
    /// If this is not an opening curly brace then fail
    int tlv6;
    {
        pstring tlv39;
        tlv39 = str;
        char tlv38;
        tlv38 = '{';
        tlv6 = cgc_atChar(tlv39,tlv38);
    }
    if (!tlv6) {
 {
     const char tlv66 [ ] = "!!Failed to locate the final opening brace\n";
    	cgc_printf(tlv66);
 }
	return -1.0;
    }
    /// Skip past the brace
    int tlv7;
    {
        pstring tlv40;
        tlv40 = str;
        tlv7 = cgc_incChar(tlv40);
    }
    if (tlv7 == -1) {
 {
     const char tlv67 [ ] = "!!Failed to skip the final opening brace\n";
    	cgc_printf(tlv67);
 }
	return gravity;
    }

    cgc_skipWhiteSpace(str);
    /// If this is not a # indicating the closing brace then fail
    int tlv8;
    {
        pstring tlv42;
        tlv42 = str;
        char tlv41;
        tlv41 = '#';
        tlv8 = cgc_atChar(tlv42,tlv41);
    }
    if (!tlv8) {
 {
     const char tlv68 [ ] = "!!Failed to locate the closing mark\n";
    	cgc_printf(tlv68);
 }
	return -1.0;
    }
    /// Skip past the # but save the start
    {
        pstring tlv44;
        tlv44 = str;
        int tlv43;
        tlv43 = 1;
        start = cgc_skipLength(tlv44,tlv43);
    }
    if (start == -1) {
 {
     const char tlv69 [ ] = "!!Failed to skip closing mark\n";
    	cgc_printf(tlv69);
 }
	return gravity;
    }
    {
        pstring tlv45;
        tlv45 = str;
        end = cgc_skipToNonAlphaNum(tlv45);
    }
    if (end == -1) {
 {
     const char tlv70 [ ] = "!!Failed to locate the end of the closing element id\n";
    	cgc_printf(tlv70);
 }
	return -1.0;
    }

    {
        pstring tlv48;
        tlv48 = str;
        int tlv47;
        tlv47 = start;
        int tlv46;
        tlv46 = end;
        temp = cgc_copyData(tlv48,tlv47,tlv46);
    }
    int tlv9;
    {
        const char* tlv50 = temp;
        const char tlv49 [ ] = "Gravity";
        tlv9 = cgc_strcmp(tlv50,tlv49);
    }
    if (tlv9 != 0) {
	cgc_printf("!!Invalid closing element id: @s\n", temp);
 {
     void* tlv72;
     tlv72 = temp;
     cgc_size_t tlv71;
     {
         char* tlv79;
          tlv79 = temp;
         tlv71 = cgc_strlen(tlv79) + 1;
     }
    	cgc_deallocate(tlv72,tlv71);
 }
	return gravity;
    }
    {
        void* tlv16;
        tlv16 = temp;
        cgc_size_t tlv15;
        {
            char* tlv76;
             tlv76 = temp;
            tlv15 = cgc_strlen(tlv76) + 1;
        }
        cgc_deallocate(tlv16,tlv15);
    }
    cgc_skipWhiteSpace(str);
    /// Check the final curly brace
    int tlv10;
    {
        pstring tlv52;
        tlv52 = str;
        char tlv51;
        tlv51 = '}';
        tlv10 = cgc_atChar(tlv52,tlv51);
    }
    if (!tlv10) {
 {
     const char tlv73 [ ] = "!!Failed to locate final closing brace\n";
    	cgc_printf(tlv73);
 }
	return -1.0;
    }
    /// Skip past the closing brace
    {
        pstring tlv18;
        tlv18 = str;
        int tlv17;
        tlv17 = 1;
        cgc_skipLength(tlv18,tlv17);
    }

    /// Copy the gravity element data
    {
        pstring tlv55;
        tlv55 = str;
        int tlv54;
        tlv54 = es;
        int tlv53;
        tlv53 = ee;
        temp = cgc_copyData(tlv55,tlv54,tlv53);
    }
    if (temp == NULL) {
 {
     const char tlv74 [ ] = "!!Failed to copy gravity data\n";
    	cgc_printf(tlv74);
 }
	return -1;
    }
    {
        const char* tlv56 = temp;
        gravity = cgc_atof(tlv56);
    }
    {
        void* tlv20;
        tlv20 = temp;
        cgc_size_t tlv19;
        {
            char* tlv77;
             tlv77 = temp;
            tlv19 = cgc_strlen(tlv77) + 1;
        }
        cgc_deallocate(tlv20,tlv19);
    }
    return gravity;
}

void fix_ingred_planetParsers_0_0_0(){
    {int choice; choice = (int)(0); }
    {char selection [ 30 ]; selection [ ( 30 )-1 ] = (char)(0); }
    {cgc_size_t length; length = (cgc_size_t)(0); }
    {void * tlv4; tlv4 = (void *)(0); }
    {cgc_size_t tlv3; tlv3 = (cgc_size_t)(0); }
    {char * tlv22; tlv22 = (char *)(0); }
    {char tlv21; tlv21 = (char)(0); }
    {cgc_size_t tlv20; tlv20 = (cgc_size_t)(0); }
    {int tlv1; tlv1 = (int)(0); }
    {int tlv2; tlv2 = (int)(0); }
    {char * tlv26; tlv26 = (char *)(0); }
    {char tlv25; tlv25 = (char)(0); }
    {cgc_size_t tlv24; tlv24 = (cgc_size_t)(0); }
    {char * tlv29; tlv29 = (char *)(0); }
    {char tlv28; tlv28 = (char)(0); }
    {cgc_size_t tlv27; tlv27 = (cgc_size_t)(0); }
    {char * tlv32; tlv32 = (char *)(0); }
    {char tlv31; tlv31 = (char)(0); }
    {cgc_size_t tlv30; tlv30 = (cgc_size_t)(0); }
    {char * tlv35; tlv35 = (char *)(0); }
    {char tlv34; tlv34 = (char)(0); }
    {cgc_size_t tlv33; tlv33 = (cgc_size_t)(0); }
    {char * tlv38; tlv38 = (char *)(0); }
    {char tlv37; tlv37 = (char)(0); }
    {cgc_size_t tlv36; tlv36 = (cgc_size_t)(0); }
    {char * tlv41; tlv41 = (char *)(0); }
    {char tlv40; tlv40 = (char)(0); }
    {cgc_size_t tlv39; tlv39 = (cgc_size_t)(0); }
    {char * tlv44; tlv44 = (char *)(0); }
    {char tlv43; tlv43 = (char)(0); }
    {cgc_size_t tlv42; tlv42 = (cgc_size_t)(0); }
    {char * tlv47; tlv47 = (char *)(0); }
    {char tlv46; tlv46 = (char)(0); }
    {cgc_size_t tlv45; tlv45 = (cgc_size_t)(0); }
    {char * tlv50; tlv50 = (char *)(0); }
    {char tlv49; tlv49 = (char)(0); }
    {cgc_size_t tlv48; tlv48 = (cgc_size_t)(0); }
    {char * tlv54; tlv54 = (char *)(0); }
    {char tlv53; tlv53 = (char)(0); }
    {cgc_size_t tlv52; tlv52 = (cgc_size_t)(0); }
    {cgc_size_t tlv72; tlv72 = (cgc_size_t)(0); }
    {int tlv71; tlv71 = (int)(0); }
    {void * tlv56; tlv56 = (void *)(0); }
    {cgc_size_t tlv55; tlv55 = (cgc_size_t)(0); }
    {char * tlv60; tlv60 = (char *)(0); }
    {char tlv59; tlv59 = (char)(0); }
    {cgc_size_t tlv58; tlv58 = (cgc_size_t)(0); }
}
void fix_ingred_planetParsers_0_0_1(){
    {int choice; choice = (int)(0); }
    {char selection [ 30 ]; selection [ ( 30 )-1 ] = (char)(0); }
    {cgc_size_t length; length = (cgc_size_t)(0); }
    {void * tlv4; tlv4 = (void *)(0); }
    {cgc_size_t tlv3; tlv3 = (cgc_size_t)(0); }
    {char * tlv22; tlv22 = (char *)(0); }
    {char tlv21; tlv21 = (char)(0); }
    {cgc_size_t tlv20; tlv20 = (cgc_size_t)(0); }
    {int tlv1; tlv1 = (int)(0); }
    {int tlv2; tlv2 = (int)(0); }
    {char * tlv26; tlv26 = (char *)(0); }
    {char tlv25; tlv25 = (char)(0); }
    {cgc_size_t tlv24; tlv24 = (cgc_size_t)(0); }
    {char * tlv29; tlv29 = (char *)(0); }
    {char tlv28; tlv28 = (char)(0); }
    {cgc_size_t tlv27; tlv27 = (cgc_size_t)(0); }
    {char * tlv32; tlv32 = (char *)(0); }
    {char tlv31; tlv31 = (char)(0); }
    {cgc_size_t tlv30; tlv30 = (cgc_size_t)(0); }
    {char * tlv35; tlv35 = (char *)(0); }
    {char tlv34; tlv34 = (char)(0); }
    {cgc_size_t tlv33; tlv33 = (cgc_size_t)(0); }
    {char * tlv38; tlv38 = (char *)(0); }
    {char tlv37; tlv37 = (char)(0); }
    {cgc_size_t tlv36; tlv36 = (cgc_size_t)(0); }
    {char * tlv41; tlv41 = (char *)(0); }
    {char tlv40; tlv40 = (char)(0); }
    {cgc_size_t tlv39; tlv39 = (cgc_size_t)(0); }
    {char * tlv44; tlv44 = (char *)(0); }
    {char tlv43; tlv43 = (char)(0); }
    {cgc_size_t tlv42; tlv42 = (cgc_size_t)(0); }
    {char * tlv47; tlv47 = (char *)(0); }
    {char tlv46; tlv46 = (char)(0); }
    {cgc_size_t tlv45; tlv45 = (cgc_size_t)(0); }
    {char * tlv50; tlv50 = (char *)(0); }
    {char tlv49; tlv49 = (char)(0); }
    {cgc_size_t tlv48; tlv48 = (cgc_size_t)(0); }
    {char * tlv54; tlv54 = (char *)(0); }
    {char tlv53; tlv53 = (char)(0); }
    {cgc_size_t tlv52; tlv52 = (cgc_size_t)(0); }
    {cgc_size_t tlv72; tlv72 = (cgc_size_t)(0); }
    {int tlv71; tlv71 = (int)(0); }
    {void * tlv56; tlv56 = (void *)(0); }
    {cgc_size_t tlv55; tlv55 = (cgc_size_t)(0); }
    {char * tlv60; tlv60 = (char *)(0); }
    {char tlv59; tlv59 = (char)(0); }
    {cgc_size_t tlv58; tlv58 = (cgc_size_t)(0); }
}
void fix_ingred_planetParsers_0_0(){
fix_ingred_planetParsers_0_0_0();
fix_ingred_planetParsers_0_0_1();
}
void fix_ingred_planetParsers_0_3_0(){
char selection [ 30 ];
    bzero(&selection,( 30 *sizeof(char) ) );
    {int choice; choice = (int)(selection); }
    {char selection [ 30 ]; selection [ ( 30 )-1 ] = (char)(selection); }
    {cgc_size_t length; length = (cgc_size_t)(selection); }
    {void * tlv4; tlv4 = (void *)(selection); }
    {cgc_size_t tlv3; tlv3 = (cgc_size_t)(selection); }
    {char * tlv22; tlv22 = (char *)(selection); }
    {char tlv21; tlv21 = (char)(selection); }
    {cgc_size_t tlv20; tlv20 = (cgc_size_t)(selection); }
    {int tlv1; tlv1 = (int)(selection); }
    {int tlv2; tlv2 = (int)(selection); }
    {char * tlv26; tlv26 = (char *)(selection); }
    {char tlv25; tlv25 = (char)(selection); }
    {cgc_size_t tlv24; tlv24 = (cgc_size_t)(selection); }
    {char * tlv29; tlv29 = (char *)(selection); }
    {char tlv28; tlv28 = (char)(selection); }
    {cgc_size_t tlv27; tlv27 = (cgc_size_t)(selection); }
    {char * tlv32; tlv32 = (char *)(selection); }
    {char tlv31; tlv31 = (char)(selection); }
    {cgc_size_t tlv30; tlv30 = (cgc_size_t)(selection); }
    {char * tlv35; tlv35 = (char *)(selection); }
    {char tlv34; tlv34 = (char)(selection); }
    {cgc_size_t tlv33; tlv33 = (cgc_size_t)(selection); }
    {char * tlv38; tlv38 = (char *)(selection); }
    {char tlv37; tlv37 = (char)(selection); }
    {cgc_size_t tlv36; tlv36 = (cgc_size_t)(selection); }
    {char * tlv41; tlv41 = (char *)(selection); }
    {char tlv40; tlv40 = (char)(selection); }
    {cgc_size_t tlv39; tlv39 = (cgc_size_t)(selection); }
    {char * tlv44; tlv44 = (char *)(selection); }
    {char tlv43; tlv43 = (char)(selection); }
    {cgc_size_t tlv42; tlv42 = (cgc_size_t)(selection); }
    {char * tlv47; tlv47 = (char *)(selection); }
    {char tlv46; tlv46 = (char)(selection); }
    {cgc_size_t tlv45; tlv45 = (cgc_size_t)(selection); }
    {char * tlv50; tlv50 = (char *)(selection); }
    {char tlv49; tlv49 = (char)(selection); }
    {cgc_size_t tlv48; tlv48 = (cgc_size_t)(selection); }
    {char * tlv54; tlv54 = (char *)(selection); }
    {char tlv53; tlv53 = (char)(selection); }
    {cgc_size_t tlv52; tlv52 = (cgc_size_t)(selection); }
    {cgc_size_t tlv72; tlv72 = (cgc_size_t)(selection); }
    {int tlv71; tlv71 = (int)(selection); }
    {void * tlv56; tlv56 = (void *)(selection); }
    {cgc_size_t tlv55; tlv55 = (cgc_size_t)(selection); }
    {char * tlv60; tlv60 = (char *)(selection); }
    {char tlv59; tlv59 = (char)(selection); }
    {cgc_size_t tlv58; tlv58 = (cgc_size_t)(selection); }
}
void fix_ingred_planetParsers_0_3_1(){
char selection [ 30 ];
    bzero(&selection,( 30 *sizeof(char) ) );
    {int choice; choice = (int)(30); }
    {char selection [ 30 ]; selection [ ( 30 )-1 ] = (char)(30); }
    {cgc_size_t length; length = (cgc_size_t)(30); }
    {void * tlv4; tlv4 = (void *)(30); }
    {cgc_size_t tlv3; tlv3 = (cgc_size_t)(30); }
    {char * tlv22; tlv22 = (char *)(30); }
    {char tlv21; tlv21 = (char)(30); }
    {cgc_size_t tlv20; tlv20 = (cgc_size_t)(30); }
    {int tlv1; tlv1 = (int)(30); }
    {int tlv2; tlv2 = (int)(30); }
    {char * tlv26; tlv26 = (char *)(30); }
    {char tlv25; tlv25 = (char)(30); }
    {cgc_size_t tlv24; tlv24 = (cgc_size_t)(30); }
    {char * tlv29; tlv29 = (char *)(30); }
    {char tlv28; tlv28 = (char)(30); }
    {cgc_size_t tlv27; tlv27 = (cgc_size_t)(30); }
    {char * tlv32; tlv32 = (char *)(30); }
    {char tlv31; tlv31 = (char)(30); }
    {cgc_size_t tlv30; tlv30 = (cgc_size_t)(30); }
    {char * tlv35; tlv35 = (char *)(30); }
    {char tlv34; tlv34 = (char)(30); }
    {cgc_size_t tlv33; tlv33 = (cgc_size_t)(30); }
    {char * tlv38; tlv38 = (char *)(30); }
    {char tlv37; tlv37 = (char)(30); }
    {cgc_size_t tlv36; tlv36 = (cgc_size_t)(30); }
    {char * tlv41; tlv41 = (char *)(30); }
    {char tlv40; tlv40 = (char)(30); }
    {cgc_size_t tlv39; tlv39 = (cgc_size_t)(30); }
    {char * tlv44; tlv44 = (char *)(30); }
    {char tlv43; tlv43 = (char)(30); }
    {cgc_size_t tlv42; tlv42 = (cgc_size_t)(30); }
    {char * tlv47; tlv47 = (char *)(30); }
    {char tlv46; tlv46 = (char)(30); }
    {cgc_size_t tlv45; tlv45 = (cgc_size_t)(30); }
    {char * tlv50; tlv50 = (char *)(30); }
    {char tlv49; tlv49 = (char)(30); }
    {cgc_size_t tlv48; tlv48 = (cgc_size_t)(30); }
    {char * tlv54; tlv54 = (char *)(30); }
    {char tlv53; tlv53 = (char)(30); }
    {cgc_size_t tlv52; tlv52 = (cgc_size_t)(30); }
    {cgc_size_t tlv72; tlv72 = (cgc_size_t)(30); }
    {int tlv71; tlv71 = (int)(30); }
    {void * tlv56; tlv56 = (void *)(30); }
    {cgc_size_t tlv55; tlv55 = (cgc_size_t)(30); }
    {char * tlv60; tlv60 = (char *)(30); }
    {char tlv59; tlv59 = (char)(30); }
    {cgc_size_t tlv58; tlv58 = (cgc_size_t)(30); }
}
void fix_ingred_planetParsers_0_3(){
fix_ingred_planetParsers_0_3_0();
fix_ingred_planetParsers_0_3_1();
}
void fix_ingred_planetParsers_0_19_0(){
char selection [ 30 ];
    bzero(&selection,( 30 *sizeof(char) ) );
    {int choice; choice = (int)(selection); }
    {char selection [ 30 ]; selection [ ( 30 )-1 ] = (char)(selection); }
    {cgc_size_t length; length = (cgc_size_t)(selection); }
    {void * tlv4; tlv4 = (void *)(selection); }
    {cgc_size_t tlv3; tlv3 = (cgc_size_t)(selection); }
    {char * tlv22; tlv22 = (char *)(selection); }
    {char tlv21; tlv21 = (char)(selection); }
    {cgc_size_t tlv20; tlv20 = (cgc_size_t)(selection); }
    {int tlv1; tlv1 = (int)(selection); }
    {int tlv2; tlv2 = (int)(selection); }
    {char * tlv26; tlv26 = (char *)(selection); }
    {char tlv25; tlv25 = (char)(selection); }
    {cgc_size_t tlv24; tlv24 = (cgc_size_t)(selection); }
    {char * tlv29; tlv29 = (char *)(selection); }
    {char tlv28; tlv28 = (char)(selection); }
    {cgc_size_t tlv27; tlv27 = (cgc_size_t)(selection); }
    {char * tlv32; tlv32 = (char *)(selection); }
    {char tlv31; tlv31 = (char)(selection); }
    {cgc_size_t tlv30; tlv30 = (cgc_size_t)(selection); }
    {char * tlv35; tlv35 = (char *)(selection); }
    {char tlv34; tlv34 = (char)(selection); }
    {cgc_size_t tlv33; tlv33 = (cgc_size_t)(selection); }
    {char * tlv38; tlv38 = (char *)(selection); }
    {char tlv37; tlv37 = (char)(selection); }
    {cgc_size_t tlv36; tlv36 = (cgc_size_t)(selection); }
    {char * tlv41; tlv41 = (char *)(selection); }
    {char tlv40; tlv40 = (char)(selection); }
    {cgc_size_t tlv39; tlv39 = (cgc_size_t)(selection); }
    {char * tlv44; tlv44 = (char *)(selection); }
    {char tlv43; tlv43 = (char)(selection); }
    {cgc_size_t tlv42; tlv42 = (cgc_size_t)(selection); }
    {char * tlv47; tlv47 = (char *)(selection); }
    {char tlv46; tlv46 = (char)(selection); }
    {cgc_size_t tlv45; tlv45 = (cgc_size_t)(selection); }
    {char * tlv50; tlv50 = (char *)(selection); }
    {char tlv49; tlv49 = (char)(selection); }
    {cgc_size_t tlv48; tlv48 = (cgc_size_t)(selection); }
    {char * tlv54; tlv54 = (char *)(selection); }
    {char tlv53; tlv53 = (char)(selection); }
    {cgc_size_t tlv52; tlv52 = (cgc_size_t)(selection); }
    {cgc_size_t tlv72; tlv72 = (cgc_size_t)(selection); }
    {int tlv71; tlv71 = (int)(selection); }
    {void * tlv56; tlv56 = (void *)(selection); }
    {cgc_size_t tlv55; tlv55 = (cgc_size_t)(selection); }
    {char * tlv60; tlv60 = (char *)(selection); }
    {char tlv59; tlv59 = (char)(selection); }
    {cgc_size_t tlv58; tlv58 = (cgc_size_t)(selection); }
}
void fix_ingred_planetParsers_0_19_1(){
char selection [ 30 ];
    bzero(&selection,( 30 *sizeof(char) ) );
    {int choice; choice = (int)('\n'); }
    {char selection [ 30 ]; selection [ ( 30 )-1 ] = (char)('\n'); }
    {cgc_size_t length; length = (cgc_size_t)('\n'); }
    {void * tlv4; tlv4 = (void *)('\n'); }
    {cgc_size_t tlv3; tlv3 = (cgc_size_t)('\n'); }
    {char * tlv22; tlv22 = (char *)('\n'); }
    {char tlv21; tlv21 = (char)('\n'); }
    {cgc_size_t tlv20; tlv20 = (cgc_size_t)('\n'); }
    {int tlv1; tlv1 = (int)('\n'); }
    {int tlv2; tlv2 = (int)('\n'); }
    {char * tlv26; tlv26 = (char *)('\n'); }
    {char tlv25; tlv25 = (char)('\n'); }
    {cgc_size_t tlv24; tlv24 = (cgc_size_t)('\n'); }
    {char * tlv29; tlv29 = (char *)('\n'); }
    {char tlv28; tlv28 = (char)('\n'); }
    {cgc_size_t tlv27; tlv27 = (cgc_size_t)('\n'); }
    {char * tlv32; tlv32 = (char *)('\n'); }
    {char tlv31; tlv31 = (char)('\n'); }
    {cgc_size_t tlv30; tlv30 = (cgc_size_t)('\n'); }
    {char * tlv35; tlv35 = (char *)('\n'); }
    {char tlv34; tlv34 = (char)('\n'); }
    {cgc_size_t tlv33; tlv33 = (cgc_size_t)('\n'); }
    {char * tlv38; tlv38 = (char *)('\n'); }
    {char tlv37; tlv37 = (char)('\n'); }
    {cgc_size_t tlv36; tlv36 = (cgc_size_t)('\n'); }
    {char * tlv41; tlv41 = (char *)('\n'); }
    {char tlv40; tlv40 = (char)('\n'); }
    {cgc_size_t tlv39; tlv39 = (cgc_size_t)('\n'); }
    {char * tlv44; tlv44 = (char *)('\n'); }
    {char tlv43; tlv43 = (char)('\n'); }
    {cgc_size_t tlv42; tlv42 = (cgc_size_t)('\n'); }
    {char * tlv47; tlv47 = (char *)('\n'); }
    {char tlv46; tlv46 = (char)('\n'); }
    {cgc_size_t tlv45; tlv45 = (cgc_size_t)('\n'); }
    {char * tlv50; tlv50 = (char *)('\n'); }
    {char tlv49; tlv49 = (char)('\n'); }
    {cgc_size_t tlv48; tlv48 = (cgc_size_t)('\n'); }
    {char * tlv54; tlv54 = (char *)('\n'); }
    {char tlv53; tlv53 = (char)('\n'); }
    {cgc_size_t tlv52; tlv52 = (cgc_size_t)('\n'); }
    {cgc_size_t tlv72; tlv72 = (cgc_size_t)('\n'); }
    {int tlv71; tlv71 = (int)('\n'); }
    {void * tlv56; tlv56 = (void *)('\n'); }
    {cgc_size_t tlv55; tlv55 = (cgc_size_t)('\n'); }
    {char * tlv60; tlv60 = (char *)('\n'); }
    {char tlv59; tlv59 = (char)('\n'); }
    {cgc_size_t tlv58; tlv58 = (cgc_size_t)('\n'); }
}
void fix_ingred_planetParsers_0_19_2(){
char selection [ 30 ];
    bzero(&selection,( 30 *sizeof(char) ) );
    {int choice; choice = (int)(3); }
    {char selection [ 30 ]; selection [ ( 30 )-1 ] = (char)(3); }
    {cgc_size_t length; length = (cgc_size_t)(3); }
    {void * tlv4; tlv4 = (void *)(3); }
    {cgc_size_t tlv3; tlv3 = (cgc_size_t)(3); }
    {char * tlv22; tlv22 = (char *)(3); }
    {char tlv21; tlv21 = (char)(3); }
    {cgc_size_t tlv20; tlv20 = (cgc_size_t)(3); }
    {int tlv1; tlv1 = (int)(3); }
    {int tlv2; tlv2 = (int)(3); }
    {char * tlv26; tlv26 = (char *)(3); }
    {char tlv25; tlv25 = (char)(3); }
    {cgc_size_t tlv24; tlv24 = (cgc_size_t)(3); }
    {char * tlv29; tlv29 = (char *)(3); }
    {char tlv28; tlv28 = (char)(3); }
    {cgc_size_t tlv27; tlv27 = (cgc_size_t)(3); }
    {char * tlv32; tlv32 = (char *)(3); }
    {char tlv31; tlv31 = (char)(3); }
    {cgc_size_t tlv30; tlv30 = (cgc_size_t)(3); }
    {char * tlv35; tlv35 = (char *)(3); }
    {char tlv34; tlv34 = (char)(3); }
    {cgc_size_t tlv33; tlv33 = (cgc_size_t)(3); }
    {char * tlv38; tlv38 = (char *)(3); }
    {char tlv37; tlv37 = (char)(3); }
    {cgc_size_t tlv36; tlv36 = (cgc_size_t)(3); }
    {char * tlv41; tlv41 = (char *)(3); }
    {char tlv40; tlv40 = (char)(3); }
    {cgc_size_t tlv39; tlv39 = (cgc_size_t)(3); }
    {char * tlv44; tlv44 = (char *)(3); }
    {char tlv43; tlv43 = (char)(3); }
    {cgc_size_t tlv42; tlv42 = (cgc_size_t)(3); }
    {char * tlv47; tlv47 = (char *)(3); }
    {char tlv46; tlv46 = (char)(3); }
    {cgc_size_t tlv45; tlv45 = (cgc_size_t)(3); }
    {char * tlv50; tlv50 = (char *)(3); }
    {char tlv49; tlv49 = (char)(3); }
    {cgc_size_t tlv48; tlv48 = (cgc_size_t)(3); }
    {char * tlv54; tlv54 = (char *)(3); }
    {char tlv53; tlv53 = (char)(3); }
    {cgc_size_t tlv52; tlv52 = (cgc_size_t)(3); }
    {cgc_size_t tlv72; tlv72 = (cgc_size_t)(3); }
    {int tlv71; tlv71 = (int)(3); }
    {void * tlv56; tlv56 = (void *)(3); }
    {cgc_size_t tlv55; tlv55 = (cgc_size_t)(3); }
    {char * tlv60; tlv60 = (char *)(3); }
    {char tlv59; tlv59 = (char)(3); }
    {cgc_size_t tlv58; tlv58 = (cgc_size_t)(3); }
}
void fix_ingred_planetParsers_0_19(){
fix_ingred_planetParsers_0_19_0();
fix_ingred_planetParsers_0_19_1();
fix_ingred_planetParsers_0_19_2();
}
void fix_ingred_planetParsers_0_25_2(){
    {int choice; choice = (int)(10); }
    {char selection [ 30 ]; selection [ ( 30 )-1 ] = (char)(10); }
    {cgc_size_t length; length = (cgc_size_t)(10); }
    {void * tlv4; tlv4 = (void *)(10); }
    {cgc_size_t tlv3; tlv3 = (cgc_size_t)(10); }
    {char * tlv22; tlv22 = (char *)(10); }
    {char tlv21; tlv21 = (char)(10); }
    {cgc_size_t tlv20; tlv20 = (cgc_size_t)(10); }
    {int tlv1; tlv1 = (int)(10); }
    {int tlv2; tlv2 = (int)(10); }
    {char * tlv26; tlv26 = (char *)(10); }
    {char tlv25; tlv25 = (char)(10); }
    {cgc_size_t tlv24; tlv24 = (cgc_size_t)(10); }
    {char * tlv29; tlv29 = (char *)(10); }
    {char tlv28; tlv28 = (char)(10); }
    {cgc_size_t tlv27; tlv27 = (cgc_size_t)(10); }
    {char * tlv32; tlv32 = (char *)(10); }
    {char tlv31; tlv31 = (char)(10); }
    {cgc_size_t tlv30; tlv30 = (cgc_size_t)(10); }
    {char * tlv35; tlv35 = (char *)(10); }
    {char tlv34; tlv34 = (char)(10); }
    {cgc_size_t tlv33; tlv33 = (cgc_size_t)(10); }
    {char * tlv38; tlv38 = (char *)(10); }
    {char tlv37; tlv37 = (char)(10); }
    {cgc_size_t tlv36; tlv36 = (cgc_size_t)(10); }
    {char * tlv41; tlv41 = (char *)(10); }
    {char tlv40; tlv40 = (char)(10); }
    {cgc_size_t tlv39; tlv39 = (cgc_size_t)(10); }
    {char * tlv44; tlv44 = (char *)(10); }
    {char tlv43; tlv43 = (char)(10); }
    {cgc_size_t tlv42; tlv42 = (cgc_size_t)(10); }
    {char * tlv47; tlv47 = (char *)(10); }
    {char tlv46; tlv46 = (char)(10); }
    {cgc_size_t tlv45; tlv45 = (cgc_size_t)(10); }
    {char * tlv50; tlv50 = (char *)(10); }
    {char tlv49; tlv49 = (char)(10); }
    {cgc_size_t tlv48; tlv48 = (cgc_size_t)(10); }
    {char * tlv54; tlv54 = (char *)(10); }
    {char tlv53; tlv53 = (char)(10); }
    {cgc_size_t tlv52; tlv52 = (cgc_size_t)(10); }
    {cgc_size_t tlv72; tlv72 = (cgc_size_t)(10); }
    {int tlv71; tlv71 = (int)(10); }
    {void * tlv56; tlv56 = (void *)(10); }
    {cgc_size_t tlv55; tlv55 = (cgc_size_t)(10); }
    {char * tlv60; tlv60 = (char *)(10); }
    {char tlv59; tlv59 = (char)(10); }
    {cgc_size_t tlv58; tlv58 = (cgc_size_t)(10); }
}
void fix_ingred_planetParsers_0_25(){
fix_ingred_planetParsers_0_25_2();
}
void fix_ingred_planetParsers_0_63_2(){
    {int choice; choice = (int)(19); }
    {char selection [ 30 ]; selection [ ( 30 )-1 ] = (char)(19); }
    {cgc_size_t length; length = (cgc_size_t)(19); }
    {void * tlv4; tlv4 = (void *)(19); }
    {cgc_size_t tlv3; tlv3 = (cgc_size_t)(19); }
    {char * tlv22; tlv22 = (char *)(19); }
    {char tlv21; tlv21 = (char)(19); }
    {cgc_size_t tlv20; tlv20 = (cgc_size_t)(19); }
    {int tlv1; tlv1 = (int)(19); }
    {int tlv2; tlv2 = (int)(19); }
    {char * tlv26; tlv26 = (char *)(19); }
    {char tlv25; tlv25 = (char)(19); }
    {cgc_size_t tlv24; tlv24 = (cgc_size_t)(19); }
    {char * tlv29; tlv29 = (char *)(19); }
    {char tlv28; tlv28 = (char)(19); }
    {cgc_size_t tlv27; tlv27 = (cgc_size_t)(19); }
    {char * tlv32; tlv32 = (char *)(19); }
    {char tlv31; tlv31 = (char)(19); }
    {cgc_size_t tlv30; tlv30 = (cgc_size_t)(19); }
    {char * tlv35; tlv35 = (char *)(19); }
    {char tlv34; tlv34 = (char)(19); }
    {cgc_size_t tlv33; tlv33 = (cgc_size_t)(19); }
    {char * tlv38; tlv38 = (char *)(19); }
    {char tlv37; tlv37 = (char)(19); }
    {cgc_size_t tlv36; tlv36 = (cgc_size_t)(19); }
    {char * tlv41; tlv41 = (char *)(19); }
    {char tlv40; tlv40 = (char)(19); }
    {cgc_size_t tlv39; tlv39 = (cgc_size_t)(19); }
    {char * tlv44; tlv44 = (char *)(19); }
    {char tlv43; tlv43 = (char)(19); }
    {cgc_size_t tlv42; tlv42 = (cgc_size_t)(19); }
    {char * tlv47; tlv47 = (char *)(19); }
    {char tlv46; tlv46 = (char)(19); }
    {cgc_size_t tlv45; tlv45 = (cgc_size_t)(19); }
    {char * tlv50; tlv50 = (char *)(19); }
    {char tlv49; tlv49 = (char)(19); }
    {cgc_size_t tlv48; tlv48 = (cgc_size_t)(19); }
    {char * tlv54; tlv54 = (char *)(19); }
    {char tlv53; tlv53 = (char)(19); }
    {cgc_size_t tlv52; tlv52 = (cgc_size_t)(19); }
    {cgc_size_t tlv72; tlv72 = (cgc_size_t)(19); }
    {int tlv71; tlv71 = (int)(19); }
    {void * tlv56; tlv56 = (void *)(19); }
    {cgc_size_t tlv55; tlv55 = (cgc_size_t)(19); }
    {char * tlv60; tlv60 = (char *)(19); }
    {char tlv59; tlv59 = (char)(19); }
    {cgc_size_t tlv58; tlv58 = (cgc_size_t)(19); }
}
void fix_ingred_planetParsers_0_63(){
fix_ingred_planetParsers_0_63_2();
}
void fix_ingred_planetParsers_0_64_4(){
int choice;
    bzero(&choice,sizeof(int));
    {char selection [ 30 ]; selection [ ( 30 )-1 ] = (char)(choice); }
    {cgc_size_t length; length = (cgc_size_t)(choice); }
    {void * tlv4; tlv4 = (void *)(choice); }
    {cgc_size_t tlv3; tlv3 = (cgc_size_t)(choice); }
    {char * tlv22; tlv22 = (char *)(choice); }
    {char tlv21; tlv21 = (char)(choice); }
    {cgc_size_t tlv20; tlv20 = (cgc_size_t)(choice); }
    {int tlv1; tlv1 = (int)(choice); }
    {int tlv2; tlv2 = (int)(choice); }
    {char * tlv26; tlv26 = (char *)(choice); }
    {char tlv25; tlv25 = (char)(choice); }
    {cgc_size_t tlv24; tlv24 = (cgc_size_t)(choice); }
    {char * tlv29; tlv29 = (char *)(choice); }
    {char tlv28; tlv28 = (char)(choice); }
    {cgc_size_t tlv27; tlv27 = (cgc_size_t)(choice); }
    {char * tlv32; tlv32 = (char *)(choice); }
    {char tlv31; tlv31 = (char)(choice); }
    {cgc_size_t tlv30; tlv30 = (cgc_size_t)(choice); }
    {char * tlv35; tlv35 = (char *)(choice); }
    {char tlv34; tlv34 = (char)(choice); }
    {cgc_size_t tlv33; tlv33 = (cgc_size_t)(choice); }
    {char * tlv38; tlv38 = (char *)(choice); }
    {char tlv37; tlv37 = (char)(choice); }
    {cgc_size_t tlv36; tlv36 = (cgc_size_t)(choice); }
    {char * tlv41; tlv41 = (char *)(choice); }
    {char tlv40; tlv40 = (char)(choice); }
    {cgc_size_t tlv39; tlv39 = (cgc_size_t)(choice); }
    {char * tlv44; tlv44 = (char *)(choice); }
    {char tlv43; tlv43 = (char)(choice); }
    {cgc_size_t tlv42; tlv42 = (cgc_size_t)(choice); }
    {char * tlv47; tlv47 = (char *)(choice); }
    {char tlv46; tlv46 = (char)(choice); }
    {cgc_size_t tlv45; tlv45 = (cgc_size_t)(choice); }
    {char * tlv50; tlv50 = (char *)(choice); }
    {char tlv49; tlv49 = (char)(choice); }
    {cgc_size_t tlv48; tlv48 = (cgc_size_t)(choice); }
    {char * tlv54; tlv54 = (char *)(choice); }
    {char tlv53; tlv53 = (char)(choice); }
    {cgc_size_t tlv52; tlv52 = (cgc_size_t)(choice); }
    {cgc_size_t tlv72; tlv72 = (cgc_size_t)(choice); }
    {int tlv71; tlv71 = (int)(choice); }
    {void * tlv56; tlv56 = (void *)(choice); }
    {cgc_size_t tlv55; tlv55 = (cgc_size_t)(choice); }
    {char * tlv60; tlv60 = (char *)(choice); }
    {char tlv59; tlv59 = (char)(choice); }
    {cgc_size_t tlv58; tlv58 = (cgc_size_t)(choice); }
}
void fix_ingred_planetParsers_0_64_5(){
int choice;
    bzero(&choice,sizeof(int));
    {int choice; choice = (int)(COUNTRYMAX); }
    {char selection [ 30 ]; selection [ ( 30 )-1 ] = (char)(COUNTRYMAX); }
    {cgc_size_t length; length = (cgc_size_t)(COUNTRYMAX); }
    {void * tlv4; tlv4 = (void *)(COUNTRYMAX); }
    {cgc_size_t tlv3; tlv3 = (cgc_size_t)(COUNTRYMAX); }
    {char * tlv22; tlv22 = (char *)(COUNTRYMAX); }
    {char tlv21; tlv21 = (char)(COUNTRYMAX); }
    {cgc_size_t tlv20; tlv20 = (cgc_size_t)(COUNTRYMAX); }
    {int tlv1; tlv1 = (int)(COUNTRYMAX); }
    {int tlv2; tlv2 = (int)(COUNTRYMAX); }
    {char * tlv26; tlv26 = (char *)(COUNTRYMAX); }
    {char tlv25; tlv25 = (char)(COUNTRYMAX); }
    {cgc_size_t tlv24; tlv24 = (cgc_size_t)(COUNTRYMAX); }
    {char * tlv29; tlv29 = (char *)(COUNTRYMAX); }
    {char tlv28; tlv28 = (char)(COUNTRYMAX); }
    {cgc_size_t tlv27; tlv27 = (cgc_size_t)(COUNTRYMAX); }
    {char * tlv32; tlv32 = (char *)(COUNTRYMAX); }
    {char tlv31; tlv31 = (char)(COUNTRYMAX); }
    {cgc_size_t tlv30; tlv30 = (cgc_size_t)(COUNTRYMAX); }
    {char * tlv35; tlv35 = (char *)(COUNTRYMAX); }
    {char tlv34; tlv34 = (char)(COUNTRYMAX); }
    {cgc_size_t tlv33; tlv33 = (cgc_size_t)(COUNTRYMAX); }
    {char * tlv38; tlv38 = (char *)(COUNTRYMAX); }
    {char tlv37; tlv37 = (char)(COUNTRYMAX); }
    {cgc_size_t tlv36; tlv36 = (cgc_size_t)(COUNTRYMAX); }
    {char * tlv41; tlv41 = (char *)(COUNTRYMAX); }
    {char tlv40; tlv40 = (char)(COUNTRYMAX); }
    {cgc_size_t tlv39; tlv39 = (cgc_size_t)(COUNTRYMAX); }
    {char * tlv44; tlv44 = (char *)(COUNTRYMAX); }
    {char tlv43; tlv43 = (char)(COUNTRYMAX); }
    {cgc_size_t tlv42; tlv42 = (cgc_size_t)(COUNTRYMAX); }
    {char * tlv47; tlv47 = (char *)(COUNTRYMAX); }
    {char tlv46; tlv46 = (char)(COUNTRYMAX); }
    {cgc_size_t tlv45; tlv45 = (cgc_size_t)(COUNTRYMAX); }
    {char * tlv50; tlv50 = (char *)(COUNTRYMAX); }
    {char tlv49; tlv49 = (char)(COUNTRYMAX); }
    {cgc_size_t tlv48; tlv48 = (cgc_size_t)(COUNTRYMAX); }
    {char * tlv54; tlv54 = (char *)(COUNTRYMAX); }
    {char tlv53; tlv53 = (char)(COUNTRYMAX); }
    {cgc_size_t tlv52; tlv52 = (cgc_size_t)(COUNTRYMAX); }
    {cgc_size_t tlv72; tlv72 = (cgc_size_t)(COUNTRYMAX); }
    {int tlv71; tlv71 = (int)(COUNTRYMAX); }
    {void * tlv56; tlv56 = (void *)(COUNTRYMAX); }
    {cgc_size_t tlv55; tlv55 = (cgc_size_t)(COUNTRYMAX); }
    {char * tlv60; tlv60 = (char *)(COUNTRYMAX); }
    {char tlv59; tlv59 = (char)(COUNTRYMAX); }
    {cgc_size_t tlv58; tlv58 = (cgc_size_t)(COUNTRYMAX); }
}
void fix_ingred_planetParsers_0_64(){
fix_ingred_planetParsers_0_64_4();
fix_ingred_planetParsers_0_64_5();
}
void fix_ingred_planetParsers_0_68_0(){
    {int choice; choice = (int)(sizeof ( Country )); }
    {char selection [ 30 ]; selection [ ( 30 )-1 ] = (char)(sizeof ( Country )); }
    {cgc_size_t length; length = (cgc_size_t)(sizeof ( Country )); }
    {void * tlv4; tlv4 = (void *)(sizeof ( Country )); }
    {cgc_size_t tlv3; tlv3 = (cgc_size_t)(sizeof ( Country )); }
    {char * tlv22; tlv22 = (char *)(sizeof ( Country )); }
    {char tlv21; tlv21 = (char)(sizeof ( Country )); }
    {cgc_size_t tlv20; tlv20 = (cgc_size_t)(sizeof ( Country )); }
    {int tlv1; tlv1 = (int)(sizeof ( Country )); }
    {int tlv2; tlv2 = (int)(sizeof ( Country )); }
    {char * tlv26; tlv26 = (char *)(sizeof ( Country )); }
    {char tlv25; tlv25 = (char)(sizeof ( Country )); }
    {cgc_size_t tlv24; tlv24 = (cgc_size_t)(sizeof ( Country )); }
    {char * tlv29; tlv29 = (char *)(sizeof ( Country )); }
    {char tlv28; tlv28 = (char)(sizeof ( Country )); }
    {cgc_size_t tlv27; tlv27 = (cgc_size_t)(sizeof ( Country )); }
    {char * tlv32; tlv32 = (char *)(sizeof ( Country )); }
    {char tlv31; tlv31 = (char)(sizeof ( Country )); }
    {cgc_size_t tlv30; tlv30 = (cgc_size_t)(sizeof ( Country )); }
    {char * tlv35; tlv35 = (char *)(sizeof ( Country )); }
    {char tlv34; tlv34 = (char)(sizeof ( Country )); }
    {cgc_size_t tlv33; tlv33 = (cgc_size_t)(sizeof ( Country )); }
    {char * tlv38; tlv38 = (char *)(sizeof ( Country )); }
    {char tlv37; tlv37 = (char)(sizeof ( Country )); }
    {cgc_size_t tlv36; tlv36 = (cgc_size_t)(sizeof ( Country )); }
    {char * tlv41; tlv41 = (char *)(sizeof ( Country )); }
    {char tlv40; tlv40 = (char)(sizeof ( Country )); }
    {cgc_size_t tlv39; tlv39 = (cgc_size_t)(sizeof ( Country )); }
    {char * tlv44; tlv44 = (char *)(sizeof ( Country )); }
    {char tlv43; tlv43 = (char)(sizeof ( Country )); }
    {cgc_size_t tlv42; tlv42 = (cgc_size_t)(sizeof ( Country )); }
    {char * tlv47; tlv47 = (char *)(sizeof ( Country )); }
    {char tlv46; tlv46 = (char)(sizeof ( Country )); }
    {cgc_size_t tlv45; tlv45 = (cgc_size_t)(sizeof ( Country )); }
    {char * tlv50; tlv50 = (char *)(sizeof ( Country )); }
    {char tlv49; tlv49 = (char)(sizeof ( Country )); }
    {cgc_size_t tlv48; tlv48 = (cgc_size_t)(sizeof ( Country )); }
    {char * tlv54; tlv54 = (char *)(sizeof ( Country )); }
    {char tlv53; tlv53 = (char)(sizeof ( Country )); }
    {cgc_size_t tlv52; tlv52 = (cgc_size_t)(sizeof ( Country )); }
    {cgc_size_t tlv72; tlv72 = (cgc_size_t)(sizeof ( Country )); }
    {int tlv71; tlv71 = (int)(sizeof ( Country )); }
    {void * tlv56; tlv56 = (void *)(sizeof ( Country )); }
    {cgc_size_t tlv55; tlv55 = (cgc_size_t)(sizeof ( Country )); }
    {char * tlv60; tlv60 = (char *)(sizeof ( Country )); }
    {char tlv59; tlv59 = (char)(sizeof ( Country )); }
    {cgc_size_t tlv58; tlv58 = (cgc_size_t)(sizeof ( Country )); }
}
void fix_ingred_planetParsers_0_68(){
fix_ingred_planetParsers_0_68_0();
}
void fix_ingred_planetParsers_0_69_4(){
int tlv1;
    bzero(&tlv1,sizeof(int));
    {int choice; choice = (int)(tlv1); }
    {char selection [ 30 ]; selection [ ( 30 )-1 ] = (char)(tlv1); }
    {cgc_size_t length; length = (cgc_size_t)(tlv1); }
    {void * tlv4; tlv4 = (void *)(tlv1); }
    {cgc_size_t tlv3; tlv3 = (cgc_size_t)(tlv1); }
    {char * tlv22; tlv22 = (char *)(tlv1); }
    {char tlv21; tlv21 = (char)(tlv1); }
    {cgc_size_t tlv20; tlv20 = (cgc_size_t)(tlv1); }
    {int tlv2; tlv2 = (int)(tlv1); }
    {char * tlv26; tlv26 = (char *)(tlv1); }
    {char tlv25; tlv25 = (char)(tlv1); }
    {cgc_size_t tlv24; tlv24 = (cgc_size_t)(tlv1); }
    {char * tlv29; tlv29 = (char *)(tlv1); }
    {char tlv28; tlv28 = (char)(tlv1); }
    {cgc_size_t tlv27; tlv27 = (cgc_size_t)(tlv1); }
    {char * tlv32; tlv32 = (char *)(tlv1); }
    {char tlv31; tlv31 = (char)(tlv1); }
    {cgc_size_t tlv30; tlv30 = (cgc_size_t)(tlv1); }
    {char * tlv35; tlv35 = (char *)(tlv1); }
    {char tlv34; tlv34 = (char)(tlv1); }
    {cgc_size_t tlv33; tlv33 = (cgc_size_t)(tlv1); }
    {char * tlv38; tlv38 = (char *)(tlv1); }
    {char tlv37; tlv37 = (char)(tlv1); }
    {cgc_size_t tlv36; tlv36 = (cgc_size_t)(tlv1); }
    {char * tlv41; tlv41 = (char *)(tlv1); }
    {char tlv40; tlv40 = (char)(tlv1); }
    {cgc_size_t tlv39; tlv39 = (cgc_size_t)(tlv1); }
    {char * tlv44; tlv44 = (char *)(tlv1); }
    {char tlv43; tlv43 = (char)(tlv1); }
    {cgc_size_t tlv42; tlv42 = (cgc_size_t)(tlv1); }
    {char * tlv47; tlv47 = (char *)(tlv1); }
    {char tlv46; tlv46 = (char)(tlv1); }
    {cgc_size_t tlv45; tlv45 = (cgc_size_t)(tlv1); }
    {char * tlv50; tlv50 = (char *)(tlv1); }
    {char tlv49; tlv49 = (char)(tlv1); }
    {cgc_size_t tlv48; tlv48 = (cgc_size_t)(tlv1); }
    {char * tlv54; tlv54 = (char *)(tlv1); }
    {char tlv53; tlv53 = (char)(tlv1); }
    {cgc_size_t tlv52; tlv52 = (cgc_size_t)(tlv1); }
    {cgc_size_t tlv72; tlv72 = (cgc_size_t)(tlv1); }
    {int tlv71; tlv71 = (int)(tlv1); }
    {void * tlv56; tlv56 = (void *)(tlv1); }
    {cgc_size_t tlv55; tlv55 = (cgc_size_t)(tlv1); }
    {char * tlv60; tlv60 = (char *)(tlv1); }
    {char tlv59; tlv59 = (char)(tlv1); }
    {cgc_size_t tlv58; tlv58 = (cgc_size_t)(tlv1); }
}
void fix_ingred_planetParsers_0_69(){
fix_ingred_planetParsers_0_69_4();
}
void fix_ingred_planetParsers_0_74_9(){
Planet pl_ref;
    bzero(&pl_ref,1*sizeof(Planet));
pPlanet pl = &pl_ref;
    {int choice; choice = (int)(pl -> country_count); }
    {char selection [ 30 ]; selection [ ( 30 )-1 ] = (char)(pl -> country_count); }
    {cgc_size_t length; length = (cgc_size_t)(pl -> country_count); }
    {void * tlv4; tlv4 = (void *)(pl -> country_count); }
    {cgc_size_t tlv3; tlv3 = (cgc_size_t)(pl -> country_count); }
    {char * tlv22; tlv22 = (char *)(pl -> country_count); }
    {char tlv21; tlv21 = (char)(pl -> country_count); }
    {cgc_size_t tlv20; tlv20 = (cgc_size_t)(pl -> country_count); }
    {int tlv1; tlv1 = (int)(pl -> country_count); }
    {int tlv2; tlv2 = (int)(pl -> country_count); }
    {char * tlv26; tlv26 = (char *)(pl -> country_count); }
    {char tlv25; tlv25 = (char)(pl -> country_count); }
    {cgc_size_t tlv24; tlv24 = (cgc_size_t)(pl -> country_count); }
    {char * tlv29; tlv29 = (char *)(pl -> country_count); }
    {char tlv28; tlv28 = (char)(pl -> country_count); }
    {cgc_size_t tlv27; tlv27 = (cgc_size_t)(pl -> country_count); }
    {char * tlv32; tlv32 = (char *)(pl -> country_count); }
    {char tlv31; tlv31 = (char)(pl -> country_count); }
    {cgc_size_t tlv30; tlv30 = (cgc_size_t)(pl -> country_count); }
    {char * tlv35; tlv35 = (char *)(pl -> country_count); }
    {char tlv34; tlv34 = (char)(pl -> country_count); }
    {cgc_size_t tlv33; tlv33 = (cgc_size_t)(pl -> country_count); }
    {char * tlv38; tlv38 = (char *)(pl -> country_count); }
    {char tlv37; tlv37 = (char)(pl -> country_count); }
    {cgc_size_t tlv36; tlv36 = (cgc_size_t)(pl -> country_count); }
    {char * tlv41; tlv41 = (char *)(pl -> country_count); }
    {char tlv40; tlv40 = (char)(pl -> country_count); }
    {cgc_size_t tlv39; tlv39 = (cgc_size_t)(pl -> country_count); }
    {char * tlv44; tlv44 = (char *)(pl -> country_count); }
    {char tlv43; tlv43 = (char)(pl -> country_count); }
    {cgc_size_t tlv42; tlv42 = (cgc_size_t)(pl -> country_count); }
    {char * tlv47; tlv47 = (char *)(pl -> country_count); }
    {char tlv46; tlv46 = (char)(pl -> country_count); }
    {cgc_size_t tlv45; tlv45 = (cgc_size_t)(pl -> country_count); }
    {char * tlv50; tlv50 = (char *)(pl -> country_count); }
    {char tlv49; tlv49 = (char)(pl -> country_count); }
    {cgc_size_t tlv48; tlv48 = (cgc_size_t)(pl -> country_count); }
    {char * tlv54; tlv54 = (char *)(pl -> country_count); }
    {char tlv53; tlv53 = (char)(pl -> country_count); }
    {cgc_size_t tlv52; tlv52 = (cgc_size_t)(pl -> country_count); }
    {cgc_size_t tlv72; tlv72 = (cgc_size_t)(pl -> country_count); }
    {int tlv71; tlv71 = (int)(pl -> country_count); }
    {void * tlv56; tlv56 = (void *)(pl -> country_count); }
    {cgc_size_t tlv55; tlv55 = (cgc_size_t)(pl -> country_count); }
    {char * tlv60; tlv60 = (char *)(pl -> country_count); }
    {char tlv59; tlv59 = (char)(pl -> country_count); }
    {cgc_size_t tlv58; tlv58 = (cgc_size_t)(pl -> country_count); }
}
void fix_ingred_planetParsers_0_74(){
fix_ingred_planetParsers_0_74_9();
}
void fix_ingred_planetParsers_0_80_8(){
    {int choice; choice = (int)(1); }
    {char selection [ 30 ]; selection [ ( 30 )-1 ] = (char)(1); }
    {cgc_size_t length; length = (cgc_size_t)(1); }
    {void * tlv4; tlv4 = (void *)(1); }
    {cgc_size_t tlv3; tlv3 = (cgc_size_t)(1); }
    {char * tlv22; tlv22 = (char *)(1); }
    {char tlv21; tlv21 = (char)(1); }
    {cgc_size_t tlv20; tlv20 = (cgc_size_t)(1); }
    {int tlv1; tlv1 = (int)(1); }
    {int tlv2; tlv2 = (int)(1); }
    {char * tlv26; tlv26 = (char *)(1); }
    {char tlv25; tlv25 = (char)(1); }
    {cgc_size_t tlv24; tlv24 = (cgc_size_t)(1); }
    {char * tlv29; tlv29 = (char *)(1); }
    {char tlv28; tlv28 = (char)(1); }
    {cgc_size_t tlv27; tlv27 = (cgc_size_t)(1); }
    {char * tlv32; tlv32 = (char *)(1); }
    {char tlv31; tlv31 = (char)(1); }
    {cgc_size_t tlv30; tlv30 = (cgc_size_t)(1); }
    {char * tlv35; tlv35 = (char *)(1); }
    {char tlv34; tlv34 = (char)(1); }
    {cgc_size_t tlv33; tlv33 = (cgc_size_t)(1); }
    {char * tlv38; tlv38 = (char *)(1); }
    {char tlv37; tlv37 = (char)(1); }
    {cgc_size_t tlv36; tlv36 = (cgc_size_t)(1); }
    {char * tlv41; tlv41 = (char *)(1); }
    {char tlv40; tlv40 = (char)(1); }
    {cgc_size_t tlv39; tlv39 = (cgc_size_t)(1); }
    {char * tlv44; tlv44 = (char *)(1); }
    {char tlv43; tlv43 = (char)(1); }
    {cgc_size_t tlv42; tlv42 = (cgc_size_t)(1); }
    {char * tlv47; tlv47 = (char *)(1); }
    {char tlv46; tlv46 = (char)(1); }
    {cgc_size_t tlv45; tlv45 = (cgc_size_t)(1); }
    {char * tlv50; tlv50 = (char *)(1); }
    {char tlv49; tlv49 = (char)(1); }
    {cgc_size_t tlv48; tlv48 = (cgc_size_t)(1); }
    {char * tlv54; tlv54 = (char *)(1); }
    {char tlv53; tlv53 = (char)(1); }
    {cgc_size_t tlv52; tlv52 = (cgc_size_t)(1); }
    {cgc_size_t tlv72; tlv72 = (cgc_size_t)(1); }
    {int tlv71; tlv71 = (int)(1); }
    {void * tlv56; tlv56 = (void *)(1); }
    {cgc_size_t tlv55; tlv55 = (cgc_size_t)(1); }
    {char * tlv60; tlv60 = (char *)(1); }
    {char tlv59; tlv59 = (char)(1); }
    {cgc_size_t tlv58; tlv58 = (cgc_size_t)(1); }
}
void fix_ingred_planetParsers_0_80(){
fix_ingred_planetParsers_0_80_8();
}
void fix_ingred_planetParsers_0_86_8(){
int tlv2;
    bzero(&tlv2,sizeof(int));
    {int choice; choice = (int)(tlv2); }
    {char selection [ 30 ]; selection [ ( 30 )-1 ] = (char)(tlv2); }
    {cgc_size_t length; length = (cgc_size_t)(tlv2); }
    {void * tlv4; tlv4 = (void *)(tlv2); }
    {cgc_size_t tlv3; tlv3 = (cgc_size_t)(tlv2); }
    {char * tlv22; tlv22 = (char *)(tlv2); }
    {char tlv21; tlv21 = (char)(tlv2); }
    {cgc_size_t tlv20; tlv20 = (cgc_size_t)(tlv2); }
    {int tlv1; tlv1 = (int)(tlv2); }
    {char * tlv26; tlv26 = (char *)(tlv2); }
    {char tlv25; tlv25 = (char)(tlv2); }
    {cgc_size_t tlv24; tlv24 = (cgc_size_t)(tlv2); }
    {char * tlv29; tlv29 = (char *)(tlv2); }
    {char tlv28; tlv28 = (char)(tlv2); }
    {cgc_size_t tlv27; tlv27 = (cgc_size_t)(tlv2); }
    {char * tlv32; tlv32 = (char *)(tlv2); }
    {char tlv31; tlv31 = (char)(tlv2); }
    {cgc_size_t tlv30; tlv30 = (cgc_size_t)(tlv2); }
    {char * tlv35; tlv35 = (char *)(tlv2); }
    {char tlv34; tlv34 = (char)(tlv2); }
    {cgc_size_t tlv33; tlv33 = (cgc_size_t)(tlv2); }
    {char * tlv38; tlv38 = (char *)(tlv2); }
    {char tlv37; tlv37 = (char)(tlv2); }
    {cgc_size_t tlv36; tlv36 = (cgc_size_t)(tlv2); }
    {char * tlv41; tlv41 = (char *)(tlv2); }
    {char tlv40; tlv40 = (char)(tlv2); }
    {cgc_size_t tlv39; tlv39 = (cgc_size_t)(tlv2); }
    {char * tlv44; tlv44 = (char *)(tlv2); }
    {char tlv43; tlv43 = (char)(tlv2); }
    {cgc_size_t tlv42; tlv42 = (cgc_size_t)(tlv2); }
    {char * tlv47; tlv47 = (char *)(tlv2); }
    {char tlv46; tlv46 = (char)(tlv2); }
    {cgc_size_t tlv45; tlv45 = (cgc_size_t)(tlv2); }
    {char * tlv50; tlv50 = (char *)(tlv2); }
    {char tlv49; tlv49 = (char)(tlv2); }
    {cgc_size_t tlv48; tlv48 = (cgc_size_t)(tlv2); }
    {char * tlv54; tlv54 = (char *)(tlv2); }
    {char tlv53; tlv53 = (char)(tlv2); }
    {cgc_size_t tlv52; tlv52 = (cgc_size_t)(tlv2); }
    {cgc_size_t tlv72; tlv72 = (cgc_size_t)(tlv2); }
    {int tlv71; tlv71 = (int)(tlv2); }
    {void * tlv56; tlv56 = (void *)(tlv2); }
    {cgc_size_t tlv55; tlv55 = (cgc_size_t)(tlv2); }
    {char * tlv60; tlv60 = (char *)(tlv2); }
    {char tlv59; tlv59 = (char)(tlv2); }
    {cgc_size_t tlv58; tlv58 = (cgc_size_t)(tlv2); }
}
void fix_ingred_planetParsers_0_86(){
fix_ingred_planetParsers_0_86_8();
}
void fix_ingred_planetParsers_0(){
fix_ingred_planetParsers_0_0();
fix_ingred_planetParsers_0_3();
fix_ingred_planetParsers_0_19();
fix_ingred_planetParsers_0_25();
fix_ingred_planetParsers_0_63();
fix_ingred_planetParsers_0_64();
fix_ingred_planetParsers_0_68();
fix_ingred_planetParsers_0_69();
fix_ingred_planetParsers_0_74();
fix_ingred_planetParsers_0_80();
fix_ingred_planetParsers_0_86();
}
void fix_ingred_planetParsers_1_0_0(){
    {int index; index = (int)(0); }
    {void * tlv2; tlv2 = (void *)(0); }
    {cgc_size_t tlv1; tlv1 = (cgc_size_t)(0); }
}
void fix_ingred_planetParsers_1_0(){
fix_ingred_planetParsers_1_0_0();
}
void fix_ingred_planetParsers_1_2_1(){
int index;
    bzero(&index,sizeof(int));
    {void * tlv2; tlv2 = (void *)(index); }
    {cgc_size_t tlv1; tlv1 = (cgc_size_t)(index); }
}
void fix_ingred_planetParsers_1_2_2(){
int index;
    bzero(&index,sizeof(int));
    {int index; index = (int)(COUNTRYMAX); }
    {void * tlv2; tlv2 = (void *)(COUNTRYMAX); }
    {cgc_size_t tlv1; tlv1 = (cgc_size_t)(COUNTRYMAX); }
}
void fix_ingred_planetParsers_1_2(){
fix_ingred_planetParsers_1_2_1();
fix_ingred_planetParsers_1_2_2();
}
void fix_ingred_planetParsers_1_5_0(){
Planet pl_ref;
    bzero(&pl_ref,1*sizeof(Planet));
pPlanet pl = &pl_ref;
    {int index; index = (int)(pl); }
    {void * tlv2; tlv2 = (void *)(pl); }
    {cgc_size_t tlv1; tlv1 = (cgc_size_t)(pl); }
}
void fix_ingred_planetParsers_1_5_1(){
Planet pl_ref;
    bzero(&pl_ref,1*sizeof(Planet));
pPlanet pl = &pl_ref;
    {int index; index = (int)(sizeof ( Planet )); }
    {void * tlv2; tlv2 = (void *)(sizeof ( Planet )); }
    {cgc_size_t tlv1; tlv1 = (cgc_size_t)(sizeof ( Planet )); }
}
void fix_ingred_planetParsers_1_5(){
fix_ingred_planetParsers_1_5_0();
fix_ingred_planetParsers_1_5_1();
}
void fix_ingred_planetParsers_1(){
fix_ingred_planetParsers_1_0();
fix_ingred_planetParsers_1_2();
fix_ingred_planetParsers_1_5();
}
void fix_ingred_planetParsers_2(){
}
void fix_ingred_planetParsers_3_2_0(){
Planet pl_ref;
    bzero(&pl_ref,1*sizeof(Planet));
pPlanet pl = &pl_ref;
    {void * tlv2; tlv2 = (void *)(pl -> name); }
    {cgc_size_t tlv1; tlv1 = (cgc_size_t)(pl -> name); }
}
void fix_ingred_planetParsers_3_2_1(){
Planet pl_ref;
    bzero(&pl_ref,1*sizeof(Planet));
pPlanet pl = &pl_ref;
    {void * tlv2; tlv2 = (void *)(20); }
    {cgc_size_t tlv1; tlv1 = (cgc_size_t)(20); }
}
void fix_ingred_planetParsers_3_2(){
fix_ingred_planetParsers_3_2_0();
fix_ingred_planetParsers_3_2_1();
}
void fix_ingred_planetParsers_3(){
fix_ingred_planetParsers_3_2();
}
void fix_ingred_planetParsers_4_0_0(){
string topLevel_ref;
    bzero(&topLevel_ref,1*sizeof(string));
pstring topLevel = &topLevel_ref;
    {int endIndex; endIndex = (int)(0); }
    {int temp_index; temp_index = (int)(0); }
    {char * fl; fl = (char *)(0); }
    {int lastGood; lastGood = (int)(0); }
    {char* c ; c  = (char*)(0); }
    {int tlv3; tlv3 = (int)(0); }
    {int tlv4; tlv4 = (int)(0); }
    {int tlv5; tlv5 = (int)(0); }
    {int tlv6; tlv6 = (int)(0); }
    {int tlv7; tlv7 = (int)(0); }
    {cgc_size_t tlv16; tlv16 = (cgc_size_t)(0); }
    {int tlv15; tlv15 = (int)(0); }
    {int * tlv8; tlv8 = (int *)(0); }
    {char tlv18; tlv18 = (char)(0); }
    {int * tlv10; tlv10 = (int *)(0); }
    {int tlv26; tlv26 = (int)(0); }
    {int tlv25; tlv25 = (int)(0); }
    {void * tlv13; tlv13 = (void *)(0); }
    {cgc_size_t tlv12; tlv12 = (cgc_size_t)(0); }
    {char tlv30; tlv30 = (char)(0); }
    {char * tlv42; tlv42 = (char *)(0); }
    {void * tlv33; tlv33 = (void *)(0); }
    {cgc_size_t tlv32; tlv32 = (cgc_size_t)(0); }
    {int * tlv34; tlv34 = (int *)(0); }
    {void * tlv40; tlv40 = (void *)(0); }
    {char * tlv62; tlv62 = (char *)(0); }
    {void * tlv45; tlv45 = (void *)(0); }
    {cgc_size_t tlv44; tlv44 = (cgc_size_t)(0); }
    {char * tlv48; tlv48 = (char *)(0); }
    {cgc_size_t tlv46; tlv46 = (cgc_size_t)(0); }
    {void * tlv50; tlv50 = (void *)(0); }
    {cgc_size_t tlv49; tlv49 = (cgc_size_t)(0); }
    {char * tlv63; tlv63 = (char *)(0); }
}
void fix_ingred_planetParsers_4_0_3(){
string topLevel_ref;
    bzero(&topLevel_ref,1*sizeof(string));
pstring topLevel = &topLevel_ref;
    {int endIndex; endIndex = (int)(NULL); }
    {int temp_index; temp_index = (int)(NULL); }
    {char * fl; fl = (char *)(NULL); }
    {int lastGood; lastGood = (int)(NULL); }
    {char* c ; c  = (char*)(NULL); }
    {int tlv1; tlv1 = (int)(NULL); }
    {int tlv2; tlv2 = (int)(NULL); }
    {int tlv3; tlv3 = (int)(NULL); }
    {int tlv4; tlv4 = (int)(NULL); }
    {int tlv5; tlv5 = (int)(NULL); }
    {int tlv6; tlv6 = (int)(NULL); }
    {int tlv7; tlv7 = (int)(NULL); }
    {cgc_size_t tlv16; tlv16 = (cgc_size_t)(NULL); }
    {int tlv15; tlv15 = (int)(NULL); }
    {int * tlv8; tlv8 = (int *)(NULL); }
    {char tlv18; tlv18 = (char)(NULL); }
    {char tlv21; tlv21 = (char)(NULL); }
    {int * tlv10; tlv10 = (int *)(NULL); }
    {int tlv26; tlv26 = (int)(NULL); }
    {int tlv25; tlv25 = (int)(NULL); }
    {void * tlv13; tlv13 = (void *)(NULL); }
    {cgc_size_t tlv12; tlv12 = (cgc_size_t)(NULL); }
    {char tlv30; tlv30 = (char)(NULL); }
    {char * tlv42; tlv42 = (char *)(NULL); }
    {void * tlv33; tlv33 = (void *)(NULL); }
    {cgc_size_t tlv32; tlv32 = (cgc_size_t)(NULL); }
    {int * tlv34; tlv34 = (int *)(NULL); }
    {void * tlv40; tlv40 = (void *)(NULL); }
    {cgc_size_t tlv39; tlv39 = (cgc_size_t)(NULL); }
    {char * tlv62; tlv62 = (char *)(NULL); }
    {void * tlv45; tlv45 = (void *)(NULL); }
    {cgc_size_t tlv44; tlv44 = (cgc_size_t)(NULL); }
    {char * tlv48; tlv48 = (char *)(NULL); }
    {char * tlv47; tlv47 = (char *)(NULL); }
    {cgc_size_t tlv46; tlv46 = (cgc_size_t)(NULL); }
    {void * tlv50; tlv50 = (void *)(NULL); }
    {cgc_size_t tlv49; tlv49 = (cgc_size_t)(NULL); }
    {char * tlv63; tlv63 = (char *)(NULL); }
}
void fix_ingred_planetParsers_4_0_5(){
string topLevel_ref;
    bzero(&topLevel_ref,1*sizeof(string));
pstring topLevel = &topLevel_ref;
    {int endIndex; endIndex = (int)(topLevel -> index); }
    {int temp_index; temp_index = (int)(topLevel -> index); }
    {char * fl; fl = (char *)(topLevel -> index); }
    {int lastGood; lastGood = (int)(topLevel -> index); }
    {char* c ; c  = (char*)(topLevel -> index); }
    {int tlv1; tlv1 = (int)(topLevel -> index); }
    {int tlv2; tlv2 = (int)(topLevel -> index); }
    {int tlv3; tlv3 = (int)(topLevel -> index); }
    {int tlv4; tlv4 = (int)(topLevel -> index); }
    {int tlv5; tlv5 = (int)(topLevel -> index); }
    {int tlv6; tlv6 = (int)(topLevel -> index); }
    {int tlv7; tlv7 = (int)(topLevel -> index); }
    {cgc_size_t tlv16; tlv16 = (cgc_size_t)(topLevel -> index); }
    {int tlv15; tlv15 = (int)(topLevel -> index); }
    {int * tlv8; tlv8 = (int *)(topLevel -> index); }
    {char tlv18; tlv18 = (char)(topLevel -> index); }
    {char tlv21; tlv21 = (char)(topLevel -> index); }
    {int * tlv10; tlv10 = (int *)(topLevel -> index); }
    {int tlv26; tlv26 = (int)(topLevel -> index); }
    {int tlv25; tlv25 = (int)(topLevel -> index); }
    {void * tlv13; tlv13 = (void *)(topLevel -> index); }
    {cgc_size_t tlv12; tlv12 = (cgc_size_t)(topLevel -> index); }
    {char tlv30; tlv30 = (char)(topLevel -> index); }
    {char * tlv42; tlv42 = (char *)(topLevel -> index); }
    {void * tlv33; tlv33 = (void *)(topLevel -> index); }
    {cgc_size_t tlv32; tlv32 = (cgc_size_t)(topLevel -> index); }
    {int * tlv34; tlv34 = (int *)(topLevel -> index); }
    {void * tlv40; tlv40 = (void *)(topLevel -> index); }
    {cgc_size_t tlv39; tlv39 = (cgc_size_t)(topLevel -> index); }
    {char * tlv62; tlv62 = (char *)(topLevel -> index); }
    {void * tlv45; tlv45 = (void *)(topLevel -> index); }
    {cgc_size_t tlv44; tlv44 = (cgc_size_t)(topLevel -> index); }
    {char * tlv48; tlv48 = (char *)(topLevel -> index); }
    {char * tlv47; tlv47 = (char *)(topLevel -> index); }
    {cgc_size_t tlv46; tlv46 = (cgc_size_t)(topLevel -> index); }
    {void * tlv50; tlv50 = (void *)(topLevel -> index); }
    {cgc_size_t tlv49; tlv49 = (cgc_size_t)(topLevel -> index); }
    {char * tlv63; tlv63 = (char *)(topLevel -> index); }
}
void fix_ingred_planetParsers_4_0(){
fix_ingred_planetParsers_4_0_0();
fix_ingred_planetParsers_4_0_3();
fix_ingred_planetParsers_4_0_5();
}
void fix_ingred_planetParsers_4_3_6(){
int i;
    bzero(&i,sizeof(int));
    {int endIndex; endIndex = (int)(i); }
    {int temp_index; temp_index = (int)(i); }
    {char * fl; fl = (char *)(i); }
    {int lastGood; lastGood = (int)(i); }
    {char* c ; c  = (char*)(i); }
    {int tlv1; tlv1 = (int)(i); }
    {int tlv2; tlv2 = (int)(i); }
    {int tlv3; tlv3 = (int)(i); }
    {int tlv4; tlv4 = (int)(i); }
    {int tlv5; tlv5 = (int)(i); }
    {int tlv6; tlv6 = (int)(i); }
    {int tlv7; tlv7 = (int)(i); }
    {cgc_size_t tlv16; tlv16 = (cgc_size_t)(i); }
    {int tlv15; tlv15 = (int)(i); }
    {int * tlv8; tlv8 = (int *)(i); }
    {char tlv18; tlv18 = (char)(i); }
    {char tlv21; tlv21 = (char)(i); }
    {int * tlv10; tlv10 = (int *)(i); }
    {int tlv26; tlv26 = (int)(i); }
    {int tlv25; tlv25 = (int)(i); }
    {void * tlv13; tlv13 = (void *)(i); }
    {cgc_size_t tlv12; tlv12 = (cgc_size_t)(i); }
    {char tlv30; tlv30 = (char)(i); }
    {char * tlv42; tlv42 = (char *)(i); }
    {void * tlv33; tlv33 = (void *)(i); }
    {cgc_size_t tlv32; tlv32 = (cgc_size_t)(i); }
    {int * tlv34; tlv34 = (int *)(i); }
    {void * tlv40; tlv40 = (void *)(i); }
    {cgc_size_t tlv39; tlv39 = (cgc_size_t)(i); }
    {char * tlv62; tlv62 = (char *)(i); }
    {void * tlv45; tlv45 = (void *)(i); }
    {cgc_size_t tlv44; tlv44 = (cgc_size_t)(i); }
    {char * tlv48; tlv48 = (char *)(i); }
    {char * tlv47; tlv47 = (char *)(i); }
    {cgc_size_t tlv46; tlv46 = (cgc_size_t)(i); }
    {void * tlv50; tlv50 = (void *)(i); }
    {cgc_size_t tlv49; tlv49 = (cgc_size_t)(i); }
    {char * tlv63; tlv63 = (char *)(i); }
}
void fix_ingred_planetParsers_4_3_7(){
int i;
    bzero(&i,sizeof(int));
    {int endIndex; endIndex = (int)(8); }
    {int temp_index; temp_index = (int)(8); }
    {char * fl; fl = (char *)(8); }
    {int lastGood; lastGood = (int)(8); }
    {char* c ; c  = (char*)(8); }
    {int tlv1; tlv1 = (int)(8); }
    {int tlv2; tlv2 = (int)(8); }
    {int tlv3; tlv3 = (int)(8); }
    {int tlv4; tlv4 = (int)(8); }
    {int tlv5; tlv5 = (int)(8); }
    {int tlv6; tlv6 = (int)(8); }
    {int tlv7; tlv7 = (int)(8); }
    {cgc_size_t tlv16; tlv16 = (cgc_size_t)(8); }
    {int tlv15; tlv15 = (int)(8); }
    {int * tlv8; tlv8 = (int *)(8); }
    {char tlv18; tlv18 = (char)(8); }
    {char tlv21; tlv21 = (char)(8); }
    {int * tlv10; tlv10 = (int *)(8); }
    {int tlv26; tlv26 = (int)(8); }
    {int tlv25; tlv25 = (int)(8); }
    {void * tlv13; tlv13 = (void *)(8); }
    {cgc_size_t tlv12; tlv12 = (cgc_size_t)(8); }
    {char tlv30; tlv30 = (char)(8); }
    {char * tlv42; tlv42 = (char *)(8); }
    {void * tlv33; tlv33 = (void *)(8); }
    {cgc_size_t tlv32; tlv32 = (cgc_size_t)(8); }
    {int * tlv34; tlv34 = (int *)(8); }
    {void * tlv40; tlv40 = (void *)(8); }
    {cgc_size_t tlv39; tlv39 = (cgc_size_t)(8); }
    {char * tlv62; tlv62 = (char *)(8); }
    {void * tlv45; tlv45 = (void *)(8); }
    {cgc_size_t tlv44; tlv44 = (cgc_size_t)(8); }
    {char * tlv48; tlv48 = (char *)(8); }
    {char * tlv47; tlv47 = (char *)(8); }
    {cgc_size_t tlv46; tlv46 = (cgc_size_t)(8); }
    {void * tlv50; tlv50 = (void *)(8); }
    {cgc_size_t tlv49; tlv49 = (cgc_size_t)(8); }
    {char * tlv63; tlv63 = (char *)(8); }
}
void fix_ingred_planetParsers_4_3(){
fix_ingred_planetParsers_4_3_6();
fix_ingred_planetParsers_4_3_7();
}
void fix_ingred_planetParsers_4_5_0(){
    {int endIndex; endIndex = (int)(sizeof ( Planet )); }
    {int temp_index; temp_index = (int)(sizeof ( Planet )); }
    {char * fl; fl = (char *)(sizeof ( Planet )); }
    {int lastGood; lastGood = (int)(sizeof ( Planet )); }
    {char* c ; c  = (char*)(sizeof ( Planet )); }
    {int tlv1; tlv1 = (int)(sizeof ( Planet )); }
    {int tlv2; tlv2 = (int)(sizeof ( Planet )); }
    {int tlv3; tlv3 = (int)(sizeof ( Planet )); }
    {int tlv4; tlv4 = (int)(sizeof ( Planet )); }
    {int tlv5; tlv5 = (int)(sizeof ( Planet )); }
    {int tlv6; tlv6 = (int)(sizeof ( Planet )); }
    {int tlv7; tlv7 = (int)(sizeof ( Planet )); }
    {cgc_size_t tlv16; tlv16 = (cgc_size_t)(sizeof ( Planet )); }
    {int tlv15; tlv15 = (int)(sizeof ( Planet )); }
    {int * tlv8; tlv8 = (int *)(sizeof ( Planet )); }
    {char tlv18; tlv18 = (char)(sizeof ( Planet )); }
    {char tlv21; tlv21 = (char)(sizeof ( Planet )); }
    {int * tlv10; tlv10 = (int *)(sizeof ( Planet )); }
    {int tlv26; tlv26 = (int)(sizeof ( Planet )); }
    {int tlv25; tlv25 = (int)(sizeof ( Planet )); }
    {void * tlv13; tlv13 = (void *)(sizeof ( Planet )); }
    {cgc_size_t tlv12; tlv12 = (cgc_size_t)(sizeof ( Planet )); }
    {char tlv30; tlv30 = (char)(sizeof ( Planet )); }
    {char * tlv42; tlv42 = (char *)(sizeof ( Planet )); }
    {void * tlv33; tlv33 = (void *)(sizeof ( Planet )); }
    {cgc_size_t tlv32; tlv32 = (cgc_size_t)(sizeof ( Planet )); }
    {int * tlv34; tlv34 = (int *)(sizeof ( Planet )); }
    {void * tlv40; tlv40 = (void *)(sizeof ( Planet )); }
    {cgc_size_t tlv39; tlv39 = (cgc_size_t)(sizeof ( Planet )); }
    {char * tlv62; tlv62 = (char *)(sizeof ( Planet )); }
    {void * tlv45; tlv45 = (void *)(sizeof ( Planet )); }
    {cgc_size_t tlv44; tlv44 = (cgc_size_t)(sizeof ( Planet )); }
    {char * tlv48; tlv48 = (char *)(sizeof ( Planet )); }
    {char * tlv47; tlv47 = (char *)(sizeof ( Planet )); }
    {cgc_size_t tlv46; tlv46 = (cgc_size_t)(sizeof ( Planet )); }
    {void * tlv50; tlv50 = (void *)(sizeof ( Planet )); }
    {cgc_size_t tlv49; tlv49 = (cgc_size_t)(sizeof ( Planet )); }
    {char * tlv63; tlv63 = (char *)(sizeof ( Planet )); }
}
void fix_ingred_planetParsers_4_5(){
fix_ingred_planetParsers_4_5_0();
}
void fix_ingred_planetParsers_4_6_7(){
int tlv1;
    bzero(&tlv1,sizeof(int));
    {int endIndex; endIndex = (int)(tlv1); }
    {int temp_index; temp_index = (int)(tlv1); }
    {char * fl; fl = (char *)(tlv1); }
    {int lastGood; lastGood = (int)(tlv1); }
    {char* c ; c  = (char*)(tlv1); }
    {int tlv3; tlv3 = (int)(tlv1); }
    {int tlv4; tlv4 = (int)(tlv1); }
    {int tlv5; tlv5 = (int)(tlv1); }
    {int tlv6; tlv6 = (int)(tlv1); }
    {int tlv7; tlv7 = (int)(tlv1); }
    {cgc_size_t tlv16; tlv16 = (cgc_size_t)(tlv1); }
    {int tlv15; tlv15 = (int)(tlv1); }
    {int * tlv8; tlv8 = (int *)(tlv1); }
    {char tlv18; tlv18 = (char)(tlv1); }
    {int * tlv10; tlv10 = (int *)(tlv1); }
    {int tlv26; tlv26 = (int)(tlv1); }
    {int tlv25; tlv25 = (int)(tlv1); }
    {void * tlv13; tlv13 = (void *)(tlv1); }
    {cgc_size_t tlv12; tlv12 = (cgc_size_t)(tlv1); }
    {char tlv30; tlv30 = (char)(tlv1); }
    {char * tlv42; tlv42 = (char *)(tlv1); }
    {void * tlv33; tlv33 = (void *)(tlv1); }
    {cgc_size_t tlv32; tlv32 = (cgc_size_t)(tlv1); }
    {int * tlv34; tlv34 = (int *)(tlv1); }
    {void * tlv40; tlv40 = (void *)(tlv1); }
    {char * tlv62; tlv62 = (char *)(tlv1); }
    {void * tlv45; tlv45 = (void *)(tlv1); }
    {cgc_size_t tlv44; tlv44 = (cgc_size_t)(tlv1); }
    {char * tlv48; tlv48 = (char *)(tlv1); }
    {cgc_size_t tlv46; tlv46 = (cgc_size_t)(tlv1); }
    {void * tlv50; tlv50 = (void *)(tlv1); }
    {cgc_size_t tlv49; tlv49 = (cgc_size_t)(tlv1); }
    {char * tlv63; tlv63 = (char *)(tlv1); }
}
void fix_ingred_planetParsers_4_6(){
fix_ingred_planetParsers_4_6_7();
}
void fix_ingred_planetParsers_4_8_1(){
int lastGood;
    bzero(&lastGood,sizeof(int));
    {int endIndex; endIndex = (int)(& lastGood); }
    {int temp_index; temp_index = (int)(& lastGood); }
    {char * fl; fl = (char *)(& lastGood); }
    {char* c ; c  = (char*)(& lastGood); }
    {int tlv1; tlv1 = (int)(& lastGood); }
    {int tlv2; tlv2 = (int)(& lastGood); }
    {int tlv3; tlv3 = (int)(& lastGood); }
    {int tlv4; tlv4 = (int)(& lastGood); }
    {int tlv5; tlv5 = (int)(& lastGood); }
    {int tlv6; tlv6 = (int)(& lastGood); }
    {int tlv7; tlv7 = (int)(& lastGood); }
    {cgc_size_t tlv16; tlv16 = (cgc_size_t)(& lastGood); }
    {int tlv15; tlv15 = (int)(& lastGood); }
    {int * tlv8; tlv8 = (int *)(& lastGood); }
    {char tlv18; tlv18 = (char)(& lastGood); }
    {char tlv21; tlv21 = (char)(& lastGood); }
    {int * tlv10; tlv10 = (int *)(& lastGood); }
    {int tlv26; tlv26 = (int)(& lastGood); }
    {int tlv25; tlv25 = (int)(& lastGood); }
    {void * tlv13; tlv13 = (void *)(& lastGood); }
    {cgc_size_t tlv12; tlv12 = (cgc_size_t)(& lastGood); }
    {char tlv30; tlv30 = (char)(& lastGood); }
    {char * tlv42; tlv42 = (char *)(& lastGood); }
    {void * tlv33; tlv33 = (void *)(& lastGood); }
    {cgc_size_t tlv32; tlv32 = (cgc_size_t)(& lastGood); }
    {int * tlv34; tlv34 = (int *)(& lastGood); }
    {void * tlv40; tlv40 = (void *)(& lastGood); }
    {cgc_size_t tlv39; tlv39 = (cgc_size_t)(& lastGood); }
    {char * tlv62; tlv62 = (char *)(& lastGood); }
    {void * tlv45; tlv45 = (void *)(& lastGood); }
    {cgc_size_t tlv44; tlv44 = (cgc_size_t)(& lastGood); }
    {char * tlv48; tlv48 = (char *)(& lastGood); }
    {char * tlv47; tlv47 = (char *)(& lastGood); }
    {cgc_size_t tlv46; tlv46 = (cgc_size_t)(& lastGood); }
    {void * tlv50; tlv50 = (void *)(& lastGood); }
    {cgc_size_t tlv49; tlv49 = (cgc_size_t)(& lastGood); }
    {char * tlv63; tlv63 = (char *)(& lastGood); }
}
void fix_ingred_planetParsers_4_8(){
fix_ingred_planetParsers_4_8_1();
}
void fix_ingred_planetParsers_4_9_7(){
char fl_ref;
    bzero(&fl_ref,1*sizeof(char));
char * fl = &fl_ref;
    {int endIndex; endIndex = (int)(fl); }
    {int temp_index; temp_index = (int)(fl); }
    {int lastGood; lastGood = (int)(fl); }
    {char* c ; c  = (char*)(fl); }
    {int tlv1; tlv1 = (int)(fl); }
    {int tlv2; tlv2 = (int)(fl); }
    {int tlv3; tlv3 = (int)(fl); }
    {int tlv4; tlv4 = (int)(fl); }
    {int tlv5; tlv5 = (int)(fl); }
    {int tlv6; tlv6 = (int)(fl); }
    {int tlv7; tlv7 = (int)(fl); }
    {cgc_size_t tlv16; tlv16 = (cgc_size_t)(fl); }
    {int tlv15; tlv15 = (int)(fl); }
    {int * tlv8; tlv8 = (int *)(fl); }
    {char tlv18; tlv18 = (char)(fl); }
    {char tlv21; tlv21 = (char)(fl); }
    {int * tlv10; tlv10 = (int *)(fl); }
    {int tlv26; tlv26 = (int)(fl); }
    {int tlv25; tlv25 = (int)(fl); }
    {void * tlv13; tlv13 = (void *)(fl); }
    {cgc_size_t tlv12; tlv12 = (cgc_size_t)(fl); }
    {char tlv30; tlv30 = (char)(fl); }
    {char * tlv42; tlv42 = (char *)(fl); }
    {void * tlv33; tlv33 = (void *)(fl); }
    {cgc_size_t tlv32; tlv32 = (cgc_size_t)(fl); }
    {int * tlv34; tlv34 = (int *)(fl); }
    {void * tlv40; tlv40 = (void *)(fl); }
    {cgc_size_t tlv39; tlv39 = (cgc_size_t)(fl); }
    {char * tlv62; tlv62 = (char *)(fl); }
    {void * tlv45; tlv45 = (void *)(fl); }
    {cgc_size_t tlv44; tlv44 = (cgc_size_t)(fl); }
    {char * tlv48; tlv48 = (char *)(fl); }
    {char * tlv47; tlv47 = (char *)(fl); }
    {cgc_size_t tlv46; tlv46 = (cgc_size_t)(fl); }
    {void * tlv50; tlv50 = (void *)(fl); }
    {cgc_size_t tlv49; tlv49 = (cgc_size_t)(fl); }
    {char * tlv63; tlv63 = (char *)(fl); }
}
void fix_ingred_planetParsers_4_9(){
fix_ingred_planetParsers_4_9_7();
}
void fix_ingred_planetParsers_4_11_0(){
char fl_ref;
    bzero(&fl_ref,1*sizeof(char));
char * fl = &fl_ref;
    {int endIndex; endIndex = (int)(fl); }
    {int temp_index; temp_index = (int)(fl); }
    {int lastGood; lastGood = (int)(fl); }
    {char* c ; c  = (char*)(fl); }
    {int tlv1; tlv1 = (int)(fl); }
    {int tlv2; tlv2 = (int)(fl); }
    {int tlv3; tlv3 = (int)(fl); }
    {int tlv4; tlv4 = (int)(fl); }
    {int tlv5; tlv5 = (int)(fl); }
    {int tlv6; tlv6 = (int)(fl); }
    {int tlv7; tlv7 = (int)(fl); }
    {cgc_size_t tlv16; tlv16 = (cgc_size_t)(fl); }
    {int tlv15; tlv15 = (int)(fl); }
    {int * tlv8; tlv8 = (int *)(fl); }
    {char tlv18; tlv18 = (char)(fl); }
    {char tlv21; tlv21 = (char)(fl); }
    {int * tlv10; tlv10 = (int *)(fl); }
    {int tlv26; tlv26 = (int)(fl); }
    {int tlv25; tlv25 = (int)(fl); }
    {void * tlv13; tlv13 = (void *)(fl); }
    {cgc_size_t tlv12; tlv12 = (cgc_size_t)(fl); }
    {char tlv30; tlv30 = (char)(fl); }
    {char * tlv42; tlv42 = (char *)(fl); }
    {void * tlv33; tlv33 = (void *)(fl); }
    {cgc_size_t tlv32; tlv32 = (cgc_size_t)(fl); }
    {int * tlv34; tlv34 = (int *)(fl); }
    {void * tlv40; tlv40 = (void *)(fl); }
    {cgc_size_t tlv39; tlv39 = (cgc_size_t)(fl); }
    {char * tlv62; tlv62 = (char *)(fl); }
    {void * tlv45; tlv45 = (void *)(fl); }
    {cgc_size_t tlv44; tlv44 = (cgc_size_t)(fl); }
    {char * tlv48; tlv48 = (char *)(fl); }
    {char * tlv47; tlv47 = (char *)(fl); }
    {cgc_size_t tlv46; tlv46 = (cgc_size_t)(fl); }
    {void * tlv50; tlv50 = (void *)(fl); }
    {cgc_size_t tlv49; tlv49 = (cgc_size_t)(fl); }
    {char * tlv63; tlv63 = (char *)(fl); }
}
void fix_ingred_planetParsers_4_11(){
fix_ingred_planetParsers_4_11_0();
}
void fix_ingred_planetParsers_4_12_1(){
char tlv62_ref;
    bzero(&tlv62_ref,1*sizeof(char));
char * tlv62 = &tlv62_ref;
    {int endIndex; endIndex = (int)(cgc_strlen ( tlv62 ) + 1); }
    {int temp_index; temp_index = (int)(cgc_strlen ( tlv62 ) + 1); }
    {char * fl; fl = (char *)(cgc_strlen ( tlv62 ) + 1); }
    {int lastGood; lastGood = (int)(cgc_strlen ( tlv62 ) + 1); }
    {char* c ; c  = (char*)(cgc_strlen ( tlv62 ) + 1); }
    {int tlv1; tlv1 = (int)(cgc_strlen ( tlv62 ) + 1); }
    {int tlv2; tlv2 = (int)(cgc_strlen ( tlv62 ) + 1); }
    {int tlv3; tlv3 = (int)(cgc_strlen ( tlv62 ) + 1); }
    {int tlv4; tlv4 = (int)(cgc_strlen ( tlv62 ) + 1); }
    {int tlv5; tlv5 = (int)(cgc_strlen ( tlv62 ) + 1); }
    {int tlv6; tlv6 = (int)(cgc_strlen ( tlv62 ) + 1); }
    {int tlv7; tlv7 = (int)(cgc_strlen ( tlv62 ) + 1); }
    {cgc_size_t tlv16; tlv16 = (cgc_size_t)(cgc_strlen ( tlv62 ) + 1); }
    {int tlv15; tlv15 = (int)(cgc_strlen ( tlv62 ) + 1); }
    {int * tlv8; tlv8 = (int *)(cgc_strlen ( tlv62 ) + 1); }
    {char tlv18; tlv18 = (char)(cgc_strlen ( tlv62 ) + 1); }
    {char tlv21; tlv21 = (char)(cgc_strlen ( tlv62 ) + 1); }
    {int * tlv10; tlv10 = (int *)(cgc_strlen ( tlv62 ) + 1); }
    {int tlv26; tlv26 = (int)(cgc_strlen ( tlv62 ) + 1); }
    {int tlv25; tlv25 = (int)(cgc_strlen ( tlv62 ) + 1); }
    {void * tlv13; tlv13 = (void *)(cgc_strlen ( tlv62 ) + 1); }
    {cgc_size_t tlv12; tlv12 = (cgc_size_t)(cgc_strlen ( tlv62 ) + 1); }
    {char tlv30; tlv30 = (char)(cgc_strlen ( tlv62 ) + 1); }
    {char * tlv42; tlv42 = (char *)(cgc_strlen ( tlv62 ) + 1); }
    {void * tlv33; tlv33 = (void *)(cgc_strlen ( tlv62 ) + 1); }
    {cgc_size_t tlv32; tlv32 = (cgc_size_t)(cgc_strlen ( tlv62 ) + 1); }
    {int * tlv34; tlv34 = (int *)(cgc_strlen ( tlv62 ) + 1); }
    {void * tlv40; tlv40 = (void *)(cgc_strlen ( tlv62 ) + 1); }
    {cgc_size_t tlv39; tlv39 = (cgc_size_t)(cgc_strlen ( tlv62 ) + 1); }
    {void * tlv45; tlv45 = (void *)(cgc_strlen ( tlv62 ) + 1); }
    {cgc_size_t tlv44; tlv44 = (cgc_size_t)(cgc_strlen ( tlv62 ) + 1); }
    {char * tlv48; tlv48 = (char *)(cgc_strlen ( tlv62 ) + 1); }
    {char * tlv47; tlv47 = (char *)(cgc_strlen ( tlv62 ) + 1); }
    {cgc_size_t tlv46; tlv46 = (cgc_size_t)(cgc_strlen ( tlv62 ) + 1); }
    {void * tlv50; tlv50 = (void *)(cgc_strlen ( tlv62 ) + 1); }
    {cgc_size_t tlv49; tlv49 = (cgc_size_t)(cgc_strlen ( tlv62 ) + 1); }
    {char * tlv63; tlv63 = (char *)(cgc_strlen ( tlv62 ) + 1); }
}
void fix_ingred_planetParsers_4_12(){
fix_ingred_planetParsers_4_12_1();
}
void fix_ingred_planetParsers_4_17_0(){
Planet newPlanet_ref;
    bzero(&newPlanet_ref,1*sizeof(Planet));
pPlanet newPlanet = &newPlanet_ref;
    {int endIndex; endIndex = (int)(newPlanet -> name); }
    {int temp_index; temp_index = (int)(newPlanet -> name); }
    {char * fl; fl = (char *)(newPlanet -> name); }
    {int lastGood; lastGood = (int)(newPlanet -> name); }
    {char* c ; c  = (char*)(newPlanet -> name); }
    {int tlv1; tlv1 = (int)(newPlanet -> name); }
    {int tlv2; tlv2 = (int)(newPlanet -> name); }
    {int tlv3; tlv3 = (int)(newPlanet -> name); }
    {int tlv4; tlv4 = (int)(newPlanet -> name); }
    {int tlv5; tlv5 = (int)(newPlanet -> name); }
    {int tlv6; tlv6 = (int)(newPlanet -> name); }
    {int tlv7; tlv7 = (int)(newPlanet -> name); }
    {cgc_size_t tlv16; tlv16 = (cgc_size_t)(newPlanet -> name); }
    {int tlv15; tlv15 = (int)(newPlanet -> name); }
    {int * tlv8; tlv8 = (int *)(newPlanet -> name); }
    {char tlv18; tlv18 = (char)(newPlanet -> name); }
    {char tlv21; tlv21 = (char)(newPlanet -> name); }
    {int * tlv10; tlv10 = (int *)(newPlanet -> name); }
    {int tlv26; tlv26 = (int)(newPlanet -> name); }
    {int tlv25; tlv25 = (int)(newPlanet -> name); }
    {void * tlv13; tlv13 = (void *)(newPlanet -> name); }
    {cgc_size_t tlv12; tlv12 = (cgc_size_t)(newPlanet -> name); }
    {char tlv30; tlv30 = (char)(newPlanet -> name); }
    {char * tlv42; tlv42 = (char *)(newPlanet -> name); }
    {void * tlv33; tlv33 = (void *)(newPlanet -> name); }
    {cgc_size_t tlv32; tlv32 = (cgc_size_t)(newPlanet -> name); }
    {int * tlv34; tlv34 = (int *)(newPlanet -> name); }
    {void * tlv40; tlv40 = (void *)(newPlanet -> name); }
    {cgc_size_t tlv39; tlv39 = (cgc_size_t)(newPlanet -> name); }
    {char * tlv62; tlv62 = (char *)(newPlanet -> name); }
    {void * tlv45; tlv45 = (void *)(newPlanet -> name); }
    {cgc_size_t tlv44; tlv44 = (cgc_size_t)(newPlanet -> name); }
    {char * tlv48; tlv48 = (char *)(newPlanet -> name); }
    {char * tlv47; tlv47 = (char *)(newPlanet -> name); }
    {cgc_size_t tlv46; tlv46 = (cgc_size_t)(newPlanet -> name); }
    {void * tlv50; tlv50 = (void *)(newPlanet -> name); }
    {cgc_size_t tlv49; tlv49 = (cgc_size_t)(newPlanet -> name); }
    {char * tlv63; tlv63 = (char *)(newPlanet -> name); }
}
void fix_ingred_planetParsers_4_17_1(){
Planet newPlanet_ref;
    bzero(&newPlanet_ref,1*sizeof(Planet));
pPlanet newPlanet = &newPlanet_ref;
    {int endIndex; endIndex = (int)(20); }
    {int temp_index; temp_index = (int)(20); }
    {char * fl; fl = (char *)(20); }
    {int lastGood; lastGood = (int)(20); }
    {char* c ; c  = (char*)(20); }
    {int tlv1; tlv1 = (int)(20); }
    {int tlv2; tlv2 = (int)(20); }
    {int tlv3; tlv3 = (int)(20); }
    {int tlv4; tlv4 = (int)(20); }
    {int tlv5; tlv5 = (int)(20); }
    {int tlv6; tlv6 = (int)(20); }
    {int tlv7; tlv7 = (int)(20); }
    {cgc_size_t tlv16; tlv16 = (cgc_size_t)(20); }
    {int tlv15; tlv15 = (int)(20); }
    {int * tlv8; tlv8 = (int *)(20); }
    {char tlv18; tlv18 = (char)(20); }
    {char tlv21; tlv21 = (char)(20); }
    {int * tlv10; tlv10 = (int *)(20); }
    {int tlv26; tlv26 = (int)(20); }
    {int tlv25; tlv25 = (int)(20); }
    {void * tlv13; tlv13 = (void *)(20); }
    {cgc_size_t tlv12; tlv12 = (cgc_size_t)(20); }
    {char tlv30; tlv30 = (char)(20); }
    {char * tlv42; tlv42 = (char *)(20); }
    {void * tlv33; tlv33 = (void *)(20); }
    {cgc_size_t tlv32; tlv32 = (cgc_size_t)(20); }
    {int * tlv34; tlv34 = (int *)(20); }
    {void * tlv40; tlv40 = (void *)(20); }
    {cgc_size_t tlv39; tlv39 = (cgc_size_t)(20); }
    {char * tlv62; tlv62 = (char *)(20); }
    {void * tlv45; tlv45 = (void *)(20); }
    {cgc_size_t tlv44; tlv44 = (cgc_size_t)(20); }
    {char * tlv48; tlv48 = (char *)(20); }
    {char * tlv47; tlv47 = (char *)(20); }
    {cgc_size_t tlv46; tlv46 = (cgc_size_t)(20); }
    {void * tlv50; tlv50 = (void *)(20); }
    {cgc_size_t tlv49; tlv49 = (cgc_size_t)(20); }
    {char * tlv63; tlv63 = (char *)(20); }
}
void fix_ingred_planetParsers_4_17(){
fix_ingred_planetParsers_4_17_0();
fix_ingred_planetParsers_4_17_1();
}
void fix_ingred_planetParsers_4_18_0(){
Planet newPlanet_ref;
    bzero(&newPlanet_ref,1*sizeof(Planet));
pPlanet newPlanet = &newPlanet_ref;
    {int endIndex; endIndex = (int)(newPlanet -> name); }
    {int temp_index; temp_index = (int)(newPlanet -> name); }
    {char * fl; fl = (char *)(newPlanet -> name); }
    {int lastGood; lastGood = (int)(newPlanet -> name); }
    {char* c ; c  = (char*)(newPlanet -> name); }
    {int tlv1; tlv1 = (int)(newPlanet -> name); }
    {int tlv2; tlv2 = (int)(newPlanet -> name); }
    {int tlv3; tlv3 = (int)(newPlanet -> name); }
    {int tlv4; tlv4 = (int)(newPlanet -> name); }
    {int tlv5; tlv5 = (int)(newPlanet -> name); }
    {int tlv6; tlv6 = (int)(newPlanet -> name); }
    {int tlv7; tlv7 = (int)(newPlanet -> name); }
    {cgc_size_t tlv16; tlv16 = (cgc_size_t)(newPlanet -> name); }
    {int tlv15; tlv15 = (int)(newPlanet -> name); }
    {int * tlv8; tlv8 = (int *)(newPlanet -> name); }
    {char tlv18; tlv18 = (char)(newPlanet -> name); }
    {char tlv21; tlv21 = (char)(newPlanet -> name); }
    {int * tlv10; tlv10 = (int *)(newPlanet -> name); }
    {int tlv26; tlv26 = (int)(newPlanet -> name); }
    {int tlv25; tlv25 = (int)(newPlanet -> name); }
    {void * tlv13; tlv13 = (void *)(newPlanet -> name); }
    {cgc_size_t tlv12; tlv12 = (cgc_size_t)(newPlanet -> name); }
    {char tlv30; tlv30 = (char)(newPlanet -> name); }
    {char * tlv42; tlv42 = (char *)(newPlanet -> name); }
    {void * tlv33; tlv33 = (void *)(newPlanet -> name); }
    {cgc_size_t tlv32; tlv32 = (cgc_size_t)(newPlanet -> name); }
    {int * tlv34; tlv34 = (int *)(newPlanet -> name); }
    {void * tlv40; tlv40 = (void *)(newPlanet -> name); }
    {cgc_size_t tlv39; tlv39 = (cgc_size_t)(newPlanet -> name); }
    {char * tlv62; tlv62 = (char *)(newPlanet -> name); }
    {void * tlv45; tlv45 = (void *)(newPlanet -> name); }
    {cgc_size_t tlv44; tlv44 = (cgc_size_t)(newPlanet -> name); }
    {char * tlv48; tlv48 = (char *)(newPlanet -> name); }
    {char * tlv47; tlv47 = (char *)(newPlanet -> name); }
    {cgc_size_t tlv46; tlv46 = (cgc_size_t)(newPlanet -> name); }
    {void * tlv50; tlv50 = (void *)(newPlanet -> name); }
    {cgc_size_t tlv49; tlv49 = (cgc_size_t)(newPlanet -> name); }
    {char * tlv63; tlv63 = (char *)(newPlanet -> name); }
}
void fix_ingred_planetParsers_4_18_2(){
Planet newPlanet_ref;
    bzero(&newPlanet_ref,1*sizeof(Planet));
pPlanet newPlanet = &newPlanet_ref;
    {int endIndex; endIndex = (int)(19); }
    {int temp_index; temp_index = (int)(19); }
    {char * fl; fl = (char *)(19); }
    {int lastGood; lastGood = (int)(19); }
    {char* c ; c  = (char*)(19); }
    {int tlv3; tlv3 = (int)(19); }
    {int tlv4; tlv4 = (int)(19); }
    {int tlv5; tlv5 = (int)(19); }
    {int tlv6; tlv6 = (int)(19); }
    {int tlv7; tlv7 = (int)(19); }
    {cgc_size_t tlv16; tlv16 = (cgc_size_t)(19); }
    {int tlv15; tlv15 = (int)(19); }
    {int * tlv8; tlv8 = (int *)(19); }
    {char tlv18; tlv18 = (char)(19); }
    {int * tlv10; tlv10 = (int *)(19); }
    {int tlv26; tlv26 = (int)(19); }
    {int tlv25; tlv25 = (int)(19); }
    {void * tlv13; tlv13 = (void *)(19); }
    {cgc_size_t tlv12; tlv12 = (cgc_size_t)(19); }
    {char tlv30; tlv30 = (char)(19); }
    {char * tlv42; tlv42 = (char *)(19); }
    {void * tlv33; tlv33 = (void *)(19); }
    {cgc_size_t tlv32; tlv32 = (cgc_size_t)(19); }
    {int * tlv34; tlv34 = (int *)(19); }
    {void * tlv40; tlv40 = (void *)(19); }
    {char * tlv62; tlv62 = (char *)(19); }
    {void * tlv45; tlv45 = (void *)(19); }
    {cgc_size_t tlv44; tlv44 = (cgc_size_t)(19); }
    {char * tlv48; tlv48 = (char *)(19); }
    {cgc_size_t tlv46; tlv46 = (cgc_size_t)(19); }
    {void * tlv50; tlv50 = (void *)(19); }
    {cgc_size_t tlv49; tlv49 = (cgc_size_t)(19); }
    {char * tlv63; tlv63 = (char *)(19); }
}
void fix_ingred_planetParsers_4_18(){
fix_ingred_planetParsers_4_18_0();
fix_ingred_planetParsers_4_18_2();
}
void fix_ingred_planetParsers_4_20_1(){
char tlv63_ref;
    bzero(&tlv63_ref,1*sizeof(char));
char * tlv63 = &tlv63_ref;
    {int endIndex; endIndex = (int)(cgc_strlen ( tlv63 ) + 1); }
    {int temp_index; temp_index = (int)(cgc_strlen ( tlv63 ) + 1); }
    {char * fl; fl = (char *)(cgc_strlen ( tlv63 ) + 1); }
    {int lastGood; lastGood = (int)(cgc_strlen ( tlv63 ) + 1); }
    {char* c ; c  = (char*)(cgc_strlen ( tlv63 ) + 1); }
    {int tlv1; tlv1 = (int)(cgc_strlen ( tlv63 ) + 1); }
    {int tlv2; tlv2 = (int)(cgc_strlen ( tlv63 ) + 1); }
    {int tlv3; tlv3 = (int)(cgc_strlen ( tlv63 ) + 1); }
    {int tlv4; tlv4 = (int)(cgc_strlen ( tlv63 ) + 1); }
    {int tlv5; tlv5 = (int)(cgc_strlen ( tlv63 ) + 1); }
    {int tlv6; tlv6 = (int)(cgc_strlen ( tlv63 ) + 1); }
    {int tlv7; tlv7 = (int)(cgc_strlen ( tlv63 ) + 1); }
    {cgc_size_t tlv16; tlv16 = (cgc_size_t)(cgc_strlen ( tlv63 ) + 1); }
    {int tlv15; tlv15 = (int)(cgc_strlen ( tlv63 ) + 1); }
    {int * tlv8; tlv8 = (int *)(cgc_strlen ( tlv63 ) + 1); }
    {char tlv18; tlv18 = (char)(cgc_strlen ( tlv63 ) + 1); }
    {char tlv21; tlv21 = (char)(cgc_strlen ( tlv63 ) + 1); }
    {int * tlv10; tlv10 = (int *)(cgc_strlen ( tlv63 ) + 1); }
    {int tlv26; tlv26 = (int)(cgc_strlen ( tlv63 ) + 1); }
    {int tlv25; tlv25 = (int)(cgc_strlen ( tlv63 ) + 1); }
    {void * tlv13; tlv13 = (void *)(cgc_strlen ( tlv63 ) + 1); }
    {cgc_size_t tlv12; tlv12 = (cgc_size_t)(cgc_strlen ( tlv63 ) + 1); }
    {char tlv30; tlv30 = (char)(cgc_strlen ( tlv63 ) + 1); }
    {char * tlv42; tlv42 = (char *)(cgc_strlen ( tlv63 ) + 1); }
    {void * tlv33; tlv33 = (void *)(cgc_strlen ( tlv63 ) + 1); }
    {cgc_size_t tlv32; tlv32 = (cgc_size_t)(cgc_strlen ( tlv63 ) + 1); }
    {int * tlv34; tlv34 = (int *)(cgc_strlen ( tlv63 ) + 1); }
    {void * tlv40; tlv40 = (void *)(cgc_strlen ( tlv63 ) + 1); }
    {cgc_size_t tlv39; tlv39 = (cgc_size_t)(cgc_strlen ( tlv63 ) + 1); }
    {char * tlv62; tlv62 = (char *)(cgc_strlen ( tlv63 ) + 1); }
    {void * tlv45; tlv45 = (void *)(cgc_strlen ( tlv63 ) + 1); }
    {cgc_size_t tlv44; tlv44 = (cgc_size_t)(cgc_strlen ( tlv63 ) + 1); }
    {char * tlv48; tlv48 = (char *)(cgc_strlen ( tlv63 ) + 1); }
    {char * tlv47; tlv47 = (char *)(cgc_strlen ( tlv63 ) + 1); }
    {cgc_size_t tlv46; tlv46 = (cgc_size_t)(cgc_strlen ( tlv63 ) + 1); }
    {void * tlv50; tlv50 = (void *)(cgc_strlen ( tlv63 ) + 1); }
    {cgc_size_t tlv49; tlv49 = (cgc_size_t)(cgc_strlen ( tlv63 ) + 1); }
}
void fix_ingred_planetParsers_4_20(){
fix_ingred_planetParsers_4_20_1();
}
void fix_ingred_planetParsers_4_55_1(){
    {int endIndex; endIndex = (int)('{'); }
    {int temp_index; temp_index = (int)('{'); }
    {char * fl; fl = (char *)('{'); }
    {int lastGood; lastGood = (int)('{'); }
    {char* c ; c  = (char*)('{'); }
    {int tlv1; tlv1 = (int)('{'); }
    {int tlv2; tlv2 = (int)('{'); }
    {int tlv3; tlv3 = (int)('{'); }
    {int tlv4; tlv4 = (int)('{'); }
    {int tlv5; tlv5 = (int)('{'); }
    {int tlv6; tlv6 = (int)('{'); }
    {int tlv7; tlv7 = (int)('{'); }
    {cgc_size_t tlv16; tlv16 = (cgc_size_t)('{'); }
    {int tlv15; tlv15 = (int)('{'); }
    {int * tlv8; tlv8 = (int *)('{'); }
    {char tlv18; tlv18 = (char)('{'); }
    {char tlv21; tlv21 = (char)('{'); }
    {int * tlv10; tlv10 = (int *)('{'); }
    {int tlv26; tlv26 = (int)('{'); }
    {int tlv25; tlv25 = (int)('{'); }
    {void * tlv13; tlv13 = (void *)('{'); }
    {cgc_size_t tlv12; tlv12 = (cgc_size_t)('{'); }
    {char tlv30; tlv30 = (char)('{'); }
    {char * tlv42; tlv42 = (char *)('{'); }
    {void * tlv33; tlv33 = (void *)('{'); }
    {cgc_size_t tlv32; tlv32 = (cgc_size_t)('{'); }
    {int * tlv34; tlv34 = (int *)('{'); }
    {void * tlv40; tlv40 = (void *)('{'); }
    {cgc_size_t tlv39; tlv39 = (cgc_size_t)('{'); }
    {char * tlv62; tlv62 = (char *)('{'); }
    {void * tlv45; tlv45 = (void *)('{'); }
    {cgc_size_t tlv44; tlv44 = (cgc_size_t)('{'); }
    {char * tlv48; tlv48 = (char *)('{'); }
    {char * tlv47; tlv47 = (char *)('{'); }
    {cgc_size_t tlv46; tlv46 = (cgc_size_t)('{'); }
    {void * tlv50; tlv50 = (void *)('{'); }
    {cgc_size_t tlv49; tlv49 = (cgc_size_t)('{'); }
    {char * tlv63; tlv63 = (char *)('{'); }
}
void fix_ingred_planetParsers_4_55(){
fix_ingred_planetParsers_4_55_1();
}
void fix_ingred_planetParsers_4_59_7(){
int tlv3;
    bzero(&tlv3,sizeof(int));
    {int endIndex; endIndex = (int)(tlv3); }
    {int temp_index; temp_index = (int)(tlv3); }
    {char * fl; fl = (char *)(tlv3); }
    {int lastGood; lastGood = (int)(tlv3); }
    {char* c ; c  = (char*)(tlv3); }
    {int tlv1; tlv1 = (int)(tlv3); }
    {int tlv2; tlv2 = (int)(tlv3); }
    {int tlv4; tlv4 = (int)(tlv3); }
    {int tlv5; tlv5 = (int)(tlv3); }
    {int tlv6; tlv6 = (int)(tlv3); }
    {int tlv7; tlv7 = (int)(tlv3); }
    {cgc_size_t tlv16; tlv16 = (cgc_size_t)(tlv3); }
    {int tlv15; tlv15 = (int)(tlv3); }
    {int * tlv8; tlv8 = (int *)(tlv3); }
    {char tlv18; tlv18 = (char)(tlv3); }
    {char tlv21; tlv21 = (char)(tlv3); }
    {int * tlv10; tlv10 = (int *)(tlv3); }
    {int tlv26; tlv26 = (int)(tlv3); }
    {int tlv25; tlv25 = (int)(tlv3); }
    {void * tlv13; tlv13 = (void *)(tlv3); }
    {cgc_size_t tlv12; tlv12 = (cgc_size_t)(tlv3); }
    {char tlv30; tlv30 = (char)(tlv3); }
    {char * tlv42; tlv42 = (char *)(tlv3); }
    {void * tlv33; tlv33 = (void *)(tlv3); }
    {cgc_size_t tlv32; tlv32 = (cgc_size_t)(tlv3); }
    {int * tlv34; tlv34 = (int *)(tlv3); }
    {void * tlv40; tlv40 = (void *)(tlv3); }
    {cgc_size_t tlv39; tlv39 = (cgc_size_t)(tlv3); }
    {char * tlv62; tlv62 = (char *)(tlv3); }
    {void * tlv45; tlv45 = (void *)(tlv3); }
    {cgc_size_t tlv44; tlv44 = (cgc_size_t)(tlv3); }
    {char * tlv48; tlv48 = (char *)(tlv3); }
    {char * tlv47; tlv47 = (char *)(tlv3); }
    {cgc_size_t tlv46; tlv46 = (cgc_size_t)(tlv3); }
    {void * tlv50; tlv50 = (void *)(tlv3); }
    {cgc_size_t tlv49; tlv49 = (cgc_size_t)(tlv3); }
    {char * tlv63; tlv63 = (char *)(tlv3); }
}
void fix_ingred_planetParsers_4_59(){
fix_ingred_planetParsers_4_59_7();
}
void fix_ingred_planetParsers_4_60_1(){
    {int endIndex; endIndex = (int)('#'); }
    {int temp_index; temp_index = (int)('#'); }
    {char * fl; fl = (char *)('#'); }
    {int lastGood; lastGood = (int)('#'); }
    {char* c ; c  = (char*)('#'); }
    {int tlv1; tlv1 = (int)('#'); }
    {int tlv2; tlv2 = (int)('#'); }
    {int tlv3; tlv3 = (int)('#'); }
    {int tlv4; tlv4 = (int)('#'); }
    {int tlv5; tlv5 = (int)('#'); }
    {int tlv6; tlv6 = (int)('#'); }
    {int tlv7; tlv7 = (int)('#'); }
    {cgc_size_t tlv16; tlv16 = (cgc_size_t)('#'); }
    {int tlv15; tlv15 = (int)('#'); }
    {int * tlv8; tlv8 = (int *)('#'); }
    {char tlv18; tlv18 = (char)('#'); }
    {char tlv21; tlv21 = (char)('#'); }
    {int * tlv10; tlv10 = (int *)('#'); }
    {int tlv26; tlv26 = (int)('#'); }
    {int tlv25; tlv25 = (int)('#'); }
    {void * tlv13; tlv13 = (void *)('#'); }
    {cgc_size_t tlv12; tlv12 = (cgc_size_t)('#'); }
    {char tlv30; tlv30 = (char)('#'); }
    {char * tlv42; tlv42 = (char *)('#'); }
    {void * tlv33; tlv33 = (void *)('#'); }
    {cgc_size_t tlv32; tlv32 = (cgc_size_t)('#'); }
    {int * tlv34; tlv34 = (int *)('#'); }
    {void * tlv40; tlv40 = (void *)('#'); }
    {cgc_size_t tlv39; tlv39 = (cgc_size_t)('#'); }
    {char * tlv62; tlv62 = (char *)('#'); }
    {void * tlv45; tlv45 = (void *)('#'); }
    {cgc_size_t tlv44; tlv44 = (cgc_size_t)('#'); }
    {char * tlv48; tlv48 = (char *)('#'); }
    {char * tlv47; tlv47 = (char *)('#'); }
    {cgc_size_t tlv46; tlv46 = (cgc_size_t)('#'); }
    {void * tlv50; tlv50 = (void *)('#'); }
    {cgc_size_t tlv49; tlv49 = (cgc_size_t)('#'); }
    {char * tlv63; tlv63 = (char *)('#'); }
}
void fix_ingred_planetParsers_4_60(){
fix_ingred_planetParsers_4_60_1();
}
void fix_ingred_planetParsers_4_64_7(){
int tlv5;
    bzero(&tlv5,sizeof(int));
    {int endIndex; endIndex = (int)(tlv5); }
    {int temp_index; temp_index = (int)(tlv5); }
    {char * fl; fl = (char *)(tlv5); }
    {int lastGood; lastGood = (int)(tlv5); }
    {char* c ; c  = (char*)(tlv5); }
    {int tlv1; tlv1 = (int)(tlv5); }
    {int tlv2; tlv2 = (int)(tlv5); }
    {int tlv3; tlv3 = (int)(tlv5); }
    {int tlv4; tlv4 = (int)(tlv5); }
    {int tlv6; tlv6 = (int)(tlv5); }
    {int tlv7; tlv7 = (int)(tlv5); }
    {cgc_size_t tlv16; tlv16 = (cgc_size_t)(tlv5); }
    {int tlv15; tlv15 = (int)(tlv5); }
    {int * tlv8; tlv8 = (int *)(tlv5); }
    {char tlv18; tlv18 = (char)(tlv5); }
    {char tlv21; tlv21 = (char)(tlv5); }
    {int * tlv10; tlv10 = (int *)(tlv5); }
    {int tlv26; tlv26 = (int)(tlv5); }
    {int tlv25; tlv25 = (int)(tlv5); }
    {void * tlv13; tlv13 = (void *)(tlv5); }
    {cgc_size_t tlv12; tlv12 = (cgc_size_t)(tlv5); }
    {char tlv30; tlv30 = (char)(tlv5); }
    {char * tlv42; tlv42 = (char *)(tlv5); }
    {void * tlv33; tlv33 = (void *)(tlv5); }
    {cgc_size_t tlv32; tlv32 = (cgc_size_t)(tlv5); }
    {int * tlv34; tlv34 = (int *)(tlv5); }
    {void * tlv40; tlv40 = (void *)(tlv5); }
    {cgc_size_t tlv39; tlv39 = (cgc_size_t)(tlv5); }
    {char * tlv62; tlv62 = (char *)(tlv5); }
    {void * tlv45; tlv45 = (void *)(tlv5); }
    {cgc_size_t tlv44; tlv44 = (cgc_size_t)(tlv5); }
    {char * tlv48; tlv48 = (char *)(tlv5); }
    {char * tlv47; tlv47 = (char *)(tlv5); }
    {cgc_size_t tlv46; tlv46 = (cgc_size_t)(tlv5); }
    {void * tlv50; tlv50 = (void *)(tlv5); }
    {cgc_size_t tlv49; tlv49 = (cgc_size_t)(tlv5); }
    {char * tlv63; tlv63 = (char *)(tlv5); }
}
void fix_ingred_planetParsers_4_64_8(){
int tlv5;
    bzero(&tlv5,sizeof(int));
    {int endIndex; endIndex = (int)(- 1); }
    {int temp_index; temp_index = (int)(- 1); }
    {char * fl; fl = (char *)(- 1); }
    {int lastGood; lastGood = (int)(- 1); }
    {char* c ; c  = (char*)(- 1); }
    {int tlv1; tlv1 = (int)(- 1); }
    {int tlv2; tlv2 = (int)(- 1); }
    {int tlv3; tlv3 = (int)(- 1); }
    {int tlv4; tlv4 = (int)(- 1); }
    {int tlv5; tlv5 = (int)(- 1); }
    {int tlv6; tlv6 = (int)(- 1); }
    {int tlv7; tlv7 = (int)(- 1); }
    {cgc_size_t tlv16; tlv16 = (cgc_size_t)(- 1); }
    {int tlv15; tlv15 = (int)(- 1); }
    {int * tlv8; tlv8 = (int *)(- 1); }
    {char tlv18; tlv18 = (char)(- 1); }
    {char tlv21; tlv21 = (char)(- 1); }
    {int * tlv10; tlv10 = (int *)(- 1); }
    {int tlv26; tlv26 = (int)(- 1); }
    {int tlv25; tlv25 = (int)(- 1); }
    {void * tlv13; tlv13 = (void *)(- 1); }
    {cgc_size_t tlv12; tlv12 = (cgc_size_t)(- 1); }
    {char tlv30; tlv30 = (char)(- 1); }
    {char * tlv42; tlv42 = (char *)(- 1); }
    {void * tlv33; tlv33 = (void *)(- 1); }
    {cgc_size_t tlv32; tlv32 = (cgc_size_t)(- 1); }
    {int * tlv34; tlv34 = (int *)(- 1); }
    {void * tlv40; tlv40 = (void *)(- 1); }
    {cgc_size_t tlv39; tlv39 = (cgc_size_t)(- 1); }
    {char * tlv62; tlv62 = (char *)(- 1); }
    {void * tlv45; tlv45 = (void *)(- 1); }
    {cgc_size_t tlv44; tlv44 = (cgc_size_t)(- 1); }
    {char * tlv48; tlv48 = (char *)(- 1); }
    {char * tlv47; tlv47 = (char *)(- 1); }
    {cgc_size_t tlv46; tlv46 = (cgc_size_t)(- 1); }
    {void * tlv50; tlv50 = (void *)(- 1); }
    {cgc_size_t tlv49; tlv49 = (cgc_size_t)(- 1); }
    {char * tlv63; tlv63 = (char *)(- 1); }
}
void fix_ingred_planetParsers_4_64(){
fix_ingred_planetParsers_4_64_7();
fix_ingred_planetParsers_4_64_8();
}
void fix_ingred_planetParsers_4_65_1(){
int temp_index;
    bzero(&temp_index,sizeof(int));
    {int endIndex; endIndex = (int)(& temp_index); }
    {char * fl; fl = (char *)(& temp_index); }
    {int lastGood; lastGood = (int)(& temp_index); }
    {char* c ; c  = (char*)(& temp_index); }
    {int tlv1; tlv1 = (int)(& temp_index); }
    {int tlv2; tlv2 = (int)(& temp_index); }
    {int tlv3; tlv3 = (int)(& temp_index); }
    {int tlv4; tlv4 = (int)(& temp_index); }
    {int tlv5; tlv5 = (int)(& temp_index); }
    {int tlv6; tlv6 = (int)(& temp_index); }
    {int tlv7; tlv7 = (int)(& temp_index); }
    {cgc_size_t tlv16; tlv16 = (cgc_size_t)(& temp_index); }
    {int tlv15; tlv15 = (int)(& temp_index); }
    {int * tlv8; tlv8 = (int *)(& temp_index); }
    {char tlv18; tlv18 = (char)(& temp_index); }
    {char tlv21; tlv21 = (char)(& temp_index); }
    {int * tlv10; tlv10 = (int *)(& temp_index); }
    {int tlv26; tlv26 = (int)(& temp_index); }
    {int tlv25; tlv25 = (int)(& temp_index); }
    {void * tlv13; tlv13 = (void *)(& temp_index); }
    {cgc_size_t tlv12; tlv12 = (cgc_size_t)(& temp_index); }
    {char tlv30; tlv30 = (char)(& temp_index); }
    {char * tlv42; tlv42 = (char *)(& temp_index); }
    {void * tlv33; tlv33 = (void *)(& temp_index); }
    {cgc_size_t tlv32; tlv32 = (cgc_size_t)(& temp_index); }
    {int * tlv34; tlv34 = (int *)(& temp_index); }
    {void * tlv40; tlv40 = (void *)(& temp_index); }
    {cgc_size_t tlv39; tlv39 = (cgc_size_t)(& temp_index); }
    {char * tlv62; tlv62 = (char *)(& temp_index); }
    {void * tlv45; tlv45 = (void *)(& temp_index); }
    {cgc_size_t tlv44; tlv44 = (cgc_size_t)(& temp_index); }
    {char * tlv48; tlv48 = (char *)(& temp_index); }
    {char * tlv47; tlv47 = (char *)(& temp_index); }
    {cgc_size_t tlv46; tlv46 = (cgc_size_t)(& temp_index); }
    {void * tlv50; tlv50 = (void *)(& temp_index); }
    {cgc_size_t tlv49; tlv49 = (cgc_size_t)(& temp_index); }
    {char * tlv63; tlv63 = (char *)(& temp_index); }
}
void fix_ingred_planetParsers_4_65(){
fix_ingred_planetParsers_4_65_1();
}
void fix_ingred_planetParsers_4_67_8(){
int endIndex;
    bzero(&endIndex,sizeof(int));
    {int temp_index; temp_index = (int)(endIndex); }
    {char * fl; fl = (char *)(endIndex); }
    {int lastGood; lastGood = (int)(endIndex); }
    {char* c ; c  = (char*)(endIndex); }
    {int tlv1; tlv1 = (int)(endIndex); }
    {int tlv2; tlv2 = (int)(endIndex); }
    {int tlv3; tlv3 = (int)(endIndex); }
    {int tlv4; tlv4 = (int)(endIndex); }
    {int tlv5; tlv5 = (int)(endIndex); }
    {int tlv6; tlv6 = (int)(endIndex); }
    {int tlv7; tlv7 = (int)(endIndex); }
    {cgc_size_t tlv16; tlv16 = (cgc_size_t)(endIndex); }
    {int tlv15; tlv15 = (int)(endIndex); }
    {int * tlv8; tlv8 = (int *)(endIndex); }
    {char tlv18; tlv18 = (char)(endIndex); }
    {char tlv21; tlv21 = (char)(endIndex); }
    {int * tlv10; tlv10 = (int *)(endIndex); }
    {int tlv26; tlv26 = (int)(endIndex); }
    {int tlv25; tlv25 = (int)(endIndex); }
    {void * tlv13; tlv13 = (void *)(endIndex); }
    {cgc_size_t tlv12; tlv12 = (cgc_size_t)(endIndex); }
    {char tlv30; tlv30 = (char)(endIndex); }
    {char * tlv42; tlv42 = (char *)(endIndex); }
    {void * tlv33; tlv33 = (void *)(endIndex); }
    {cgc_size_t tlv32; tlv32 = (cgc_size_t)(endIndex); }
    {int * tlv34; tlv34 = (int *)(endIndex); }
    {void * tlv40; tlv40 = (void *)(endIndex); }
    {cgc_size_t tlv39; tlv39 = (cgc_size_t)(endIndex); }
    {char * tlv62; tlv62 = (char *)(endIndex); }
    {void * tlv45; tlv45 = (void *)(endIndex); }
    {cgc_size_t tlv44; tlv44 = (cgc_size_t)(endIndex); }
    {char * tlv48; tlv48 = (char *)(endIndex); }
    {char * tlv47; tlv47 = (char *)(endIndex); }
    {cgc_size_t tlv46; tlv46 = (cgc_size_t)(endIndex); }
    {void * tlv50; tlv50 = (void *)(endIndex); }
    {cgc_size_t tlv49; tlv49 = (cgc_size_t)(endIndex); }
    {char * tlv63; tlv63 = (char *)(endIndex); }
}
void fix_ingred_planetParsers_4_67(){
fix_ingred_planetParsers_4_67_8();
}
void fix_ingred_planetParsers_4_68_7(){
int temp_index;
    bzero(&temp_index,sizeof(int));
    {int endIndex; endIndex = (int)(temp_index); }
    {char * fl; fl = (char *)(temp_index); }
    {int lastGood; lastGood = (int)(temp_index); }
    {char* c ; c  = (char*)(temp_index); }
    {int tlv1; tlv1 = (int)(temp_index); }
    {int tlv2; tlv2 = (int)(temp_index); }
    {int tlv3; tlv3 = (int)(temp_index); }
    {int tlv4; tlv4 = (int)(temp_index); }
    {int tlv5; tlv5 = (int)(temp_index); }
    {int tlv6; tlv6 = (int)(temp_index); }
    {int tlv7; tlv7 = (int)(temp_index); }
    {cgc_size_t tlv16; tlv16 = (cgc_size_t)(temp_index); }
    {int tlv15; tlv15 = (int)(temp_index); }
    {int * tlv8; tlv8 = (int *)(temp_index); }
    {char tlv18; tlv18 = (char)(temp_index); }
    {char tlv21; tlv21 = (char)(temp_index); }
    {int * tlv10; tlv10 = (int *)(temp_index); }
    {int tlv26; tlv26 = (int)(temp_index); }
    {int tlv25; tlv25 = (int)(temp_index); }
    {void * tlv13; tlv13 = (void *)(temp_index); }
    {cgc_size_t tlv12; tlv12 = (cgc_size_t)(temp_index); }
    {char tlv30; tlv30 = (char)(temp_index); }
    {char * tlv42; tlv42 = (char *)(temp_index); }
    {void * tlv33; tlv33 = (void *)(temp_index); }
    {cgc_size_t tlv32; tlv32 = (cgc_size_t)(temp_index); }
    {int * tlv34; tlv34 = (int *)(temp_index); }
    {void * tlv40; tlv40 = (void *)(temp_index); }
    {cgc_size_t tlv39; tlv39 = (cgc_size_t)(temp_index); }
    {char * tlv62; tlv62 = (char *)(temp_index); }
    {void * tlv45; tlv45 = (void *)(temp_index); }
    {cgc_size_t tlv44; tlv44 = (cgc_size_t)(temp_index); }
    {char * tlv48; tlv48 = (char *)(temp_index); }
    {char * tlv47; tlv47 = (char *)(temp_index); }
    {cgc_size_t tlv46; tlv46 = (cgc_size_t)(temp_index); }
    {void * tlv50; tlv50 = (void *)(temp_index); }
    {cgc_size_t tlv49; tlv49 = (cgc_size_t)(temp_index); }
    {char * tlv63; tlv63 = (char *)(temp_index); }
}
void fix_ingred_planetParsers_4_68(){
fix_ingred_planetParsers_4_68_7();
}
void fix_ingred_planetParsers_4_72_7(){
int tlv6;
    bzero(&tlv6,sizeof(int));
    {int endIndex; endIndex = (int)(tlv6); }
    {int temp_index; temp_index = (int)(tlv6); }
    {char * fl; fl = (char *)(tlv6); }
    {int lastGood; lastGood = (int)(tlv6); }
    {char* c ; c  = (char*)(tlv6); }
    {int tlv1; tlv1 = (int)(tlv6); }
    {int tlv2; tlv2 = (int)(tlv6); }
    {int tlv3; tlv3 = (int)(tlv6); }
    {int tlv4; tlv4 = (int)(tlv6); }
    {int tlv5; tlv5 = (int)(tlv6); }
    {int tlv7; tlv7 = (int)(tlv6); }
    {cgc_size_t tlv16; tlv16 = (cgc_size_t)(tlv6); }
    {int tlv15; tlv15 = (int)(tlv6); }
    {int * tlv8; tlv8 = (int *)(tlv6); }
    {char tlv18; tlv18 = (char)(tlv6); }
    {char tlv21; tlv21 = (char)(tlv6); }
    {int * tlv10; tlv10 = (int *)(tlv6); }
    {int tlv26; tlv26 = (int)(tlv6); }
    {int tlv25; tlv25 = (int)(tlv6); }
    {void * tlv13; tlv13 = (void *)(tlv6); }
    {cgc_size_t tlv12; tlv12 = (cgc_size_t)(tlv6); }
    {char tlv30; tlv30 = (char)(tlv6); }
    {char * tlv42; tlv42 = (char *)(tlv6); }
    {void * tlv33; tlv33 = (void *)(tlv6); }
    {cgc_size_t tlv32; tlv32 = (cgc_size_t)(tlv6); }
    {int * tlv34; tlv34 = (int *)(tlv6); }
    {void * tlv40; tlv40 = (void *)(tlv6); }
    {cgc_size_t tlv39; tlv39 = (cgc_size_t)(tlv6); }
    {char * tlv62; tlv62 = (char *)(tlv6); }
    {void * tlv45; tlv45 = (void *)(tlv6); }
    {cgc_size_t tlv44; tlv44 = (cgc_size_t)(tlv6); }
    {char * tlv48; tlv48 = (char *)(tlv6); }
    {char * tlv47; tlv47 = (char *)(tlv6); }
    {cgc_size_t tlv46; tlv46 = (cgc_size_t)(tlv6); }
    {void * tlv50; tlv50 = (void *)(tlv6); }
    {cgc_size_t tlv49; tlv49 = (cgc_size_t)(tlv6); }
    {char * tlv63; tlv63 = (char *)(tlv6); }
}
void fix_ingred_planetParsers_4_72(){
fix_ingred_planetParsers_4_72_7();
}
void fix_ingred_planetParsers_4_74_1(){
int endIndex;
    bzero(&endIndex,sizeof(int));
int temp_index;
    bzero(&temp_index,sizeof(int));
    {char * fl; fl = (char *)(( endIndex - temp_index ) + 1); }
    {int lastGood; lastGood = (int)(( endIndex - temp_index ) + 1); }
    {char* c ; c  = (char*)(( endIndex - temp_index ) + 1); }
    {int tlv1; tlv1 = (int)(( endIndex - temp_index ) + 1); }
    {int tlv2; tlv2 = (int)(( endIndex - temp_index ) + 1); }
    {int tlv3; tlv3 = (int)(( endIndex - temp_index ) + 1); }
    {int tlv4; tlv4 = (int)(( endIndex - temp_index ) + 1); }
    {int tlv5; tlv5 = (int)(( endIndex - temp_index ) + 1); }
    {int tlv6; tlv6 = (int)(( endIndex - temp_index ) + 1); }
    {int tlv7; tlv7 = (int)(( endIndex - temp_index ) + 1); }
    {cgc_size_t tlv16; tlv16 = (cgc_size_t)(( endIndex - temp_index ) + 1); }
    {int tlv15; tlv15 = (int)(( endIndex - temp_index ) + 1); }
    {int * tlv8; tlv8 = (int *)(( endIndex - temp_index ) + 1); }
    {char tlv18; tlv18 = (char)(( endIndex - temp_index ) + 1); }
    {char tlv21; tlv21 = (char)(( endIndex - temp_index ) + 1); }
    {int * tlv10; tlv10 = (int *)(( endIndex - temp_index ) + 1); }
    {int tlv26; tlv26 = (int)(( endIndex - temp_index ) + 1); }
    {int tlv25; tlv25 = (int)(( endIndex - temp_index ) + 1); }
    {void * tlv13; tlv13 = (void *)(( endIndex - temp_index ) + 1); }
    {cgc_size_t tlv12; tlv12 = (cgc_size_t)(( endIndex - temp_index ) + 1); }
    {char tlv30; tlv30 = (char)(( endIndex - temp_index ) + 1); }
    {char * tlv42; tlv42 = (char *)(( endIndex - temp_index ) + 1); }
    {void * tlv33; tlv33 = (void *)(( endIndex - temp_index ) + 1); }
    {cgc_size_t tlv32; tlv32 = (cgc_size_t)(( endIndex - temp_index ) + 1); }
    {int * tlv34; tlv34 = (int *)(( endIndex - temp_index ) + 1); }
    {void * tlv40; tlv40 = (void *)(( endIndex - temp_index ) + 1); }
    {cgc_size_t tlv39; tlv39 = (cgc_size_t)(( endIndex - temp_index ) + 1); }
    {char * tlv62; tlv62 = (char *)(( endIndex - temp_index ) + 1); }
    {void * tlv45; tlv45 = (void *)(( endIndex - temp_index ) + 1); }
    {cgc_size_t tlv44; tlv44 = (cgc_size_t)(( endIndex - temp_index ) + 1); }
    {char * tlv48; tlv48 = (char *)(( endIndex - temp_index ) + 1); }
    {char * tlv47; tlv47 = (char *)(( endIndex - temp_index ) + 1); }
    {cgc_size_t tlv46; tlv46 = (cgc_size_t)(( endIndex - temp_index ) + 1); }
    {void * tlv50; tlv50 = (void *)(( endIndex - temp_index ) + 1); }
    {cgc_size_t tlv49; tlv49 = (cgc_size_t)(( endIndex - temp_index ) + 1); }
    {char * tlv63; tlv63 = (char *)(( endIndex - temp_index ) + 1); }
}
void fix_ingred_planetParsers_4_74(){
fix_ingred_planetParsers_4_74_1();
}
void fix_ingred_planetParsers_4_76_1(){
    {int endIndex; endIndex = (int)('}'); }
    {int temp_index; temp_index = (int)('}'); }
    {char * fl; fl = (char *)('}'); }
    {int lastGood; lastGood = (int)('}'); }
    {char* c ; c  = (char*)('}'); }
    {int tlv1; tlv1 = (int)('}'); }
    {int tlv2; tlv2 = (int)('}'); }
    {int tlv3; tlv3 = (int)('}'); }
    {int tlv4; tlv4 = (int)('}'); }
    {int tlv5; tlv5 = (int)('}'); }
    {int tlv6; tlv6 = (int)('}'); }
    {int tlv7; tlv7 = (int)('}'); }
    {cgc_size_t tlv16; tlv16 = (cgc_size_t)('}'); }
    {int tlv15; tlv15 = (int)('}'); }
    {int * tlv8; tlv8 = (int *)('}'); }
    {char tlv18; tlv18 = (char)('}'); }
    {char tlv21; tlv21 = (char)('}'); }
    {int * tlv10; tlv10 = (int *)('}'); }
    {int tlv26; tlv26 = (int)('}'); }
    {int tlv25; tlv25 = (int)('}'); }
    {void * tlv13; tlv13 = (void *)('}'); }
    {cgc_size_t tlv12; tlv12 = (cgc_size_t)('}'); }
    {char tlv30; tlv30 = (char)('}'); }
    {char * tlv42; tlv42 = (char *)('}'); }
    {void * tlv33; tlv33 = (void *)('}'); }
    {cgc_size_t tlv32; tlv32 = (cgc_size_t)('}'); }
    {int * tlv34; tlv34 = (int *)('}'); }
    {void * tlv40; tlv40 = (void *)('}'); }
    {cgc_size_t tlv39; tlv39 = (cgc_size_t)('}'); }
    {char * tlv62; tlv62 = (char *)('}'); }
    {void * tlv45; tlv45 = (void *)('}'); }
    {cgc_size_t tlv44; tlv44 = (cgc_size_t)('}'); }
    {char * tlv48; tlv48 = (char *)('}'); }
    {char * tlv47; tlv47 = (char *)('}'); }
    {cgc_size_t tlv46; tlv46 = (cgc_size_t)('}'); }
    {void * tlv50; tlv50 = (void *)('}'); }
    {cgc_size_t tlv49; tlv49 = (cgc_size_t)('}'); }
    {char * tlv63; tlv63 = (char *)('}'); }
}
void fix_ingred_planetParsers_4_76(){
fix_ingred_planetParsers_4_76_1();
}
void fix_ingred_planetParsers_4(){
fix_ingred_planetParsers_4_0();
fix_ingred_planetParsers_4_3();
fix_ingred_planetParsers_4_5();
fix_ingred_planetParsers_4_6();
fix_ingred_planetParsers_4_8();
fix_ingred_planetParsers_4_9();
fix_ingred_planetParsers_4_11();
fix_ingred_planetParsers_4_12();
fix_ingred_planetParsers_4_17();
fix_ingred_planetParsers_4_18();
fix_ingred_planetParsers_4_20();
fix_ingred_planetParsers_4_55();
fix_ingred_planetParsers_4_59();
fix_ingred_planetParsers_4_60();
fix_ingred_planetParsers_4_64();
fix_ingred_planetParsers_4_65();
fix_ingred_planetParsers_4_67();
fix_ingred_planetParsers_4_68();
fix_ingred_planetParsers_4_72();
fix_ingred_planetParsers_4_74();
fix_ingred_planetParsers_4_76();
}
void fix_ingred_planetParsers_5_0_0(){
    {char * temp; temp = (char *)(NULL); }
    {int start; start = (int)(NULL); }
    {int end; end = (int)(NULL); }
    {int ps; ps = (int)(NULL); }
    {int pe; pe = (int)(NULL); }
    {int tlv8; tlv8 = (int)(NULL); }
    {int tlv9; tlv9 = (int)(NULL); }
    {int tlv10; tlv10 = (int)(NULL); }
    {int tlv23; tlv23 = (int)(NULL); }
    {int tlv28; tlv28 = (int)(NULL); }
    {int tlv27; tlv27 = (int)(NULL); }
    {void * tlv12; tlv12 = (void *)(NULL); }
    {cgc_size_t tlv11; tlv11 = (cgc_size_t)(NULL); }
    {char tlv32; tlv32 = (char)(NULL); }
    {int tlv34; tlv34 = (int)(NULL); }
    {int * tlv13; tlv13 = (int *)(NULL); }
    {char tlv37; tlv37 = (char)(NULL); }
    {int tlv39; tlv39 = (int)(NULL); }
    {char tlv41; tlv41 = (char)(NULL); }
    {int tlv43; tlv43 = (int)(NULL); }
    {int tlv47; tlv47 = (int)(NULL); }
    {int tlv46; tlv46 = (int)(NULL); }
    {void * tlv16; tlv16 = (void *)(NULL); }
    {cgc_size_t tlv15; tlv15 = (cgc_size_t)(NULL); }
    {char tlv51; tlv51 = (char)(NULL); }
    {int tlv17; tlv17 = (int)(NULL); }
    {int tlv54; tlv54 = (int)(NULL); }
    {int tlv53; tlv53 = (int)(NULL); }
    {void * tlv20; tlv20 = (void *)(NULL); }
    {cgc_size_t tlv19; tlv19 = (cgc_size_t)(NULL); }
    {char * tlv75; tlv75 = (char *)(NULL); }
    {char * tlv76; tlv76 = (char *)(NULL); }
    {char * tlv77; tlv77 = (char *)(NULL); }
    {void * tlv62; tlv62 = (void *)(NULL); }
    {cgc_size_t tlv61; tlv61 = (cgc_size_t)(NULL); }
    {void * tlv72; tlv72 = (void *)(NULL); }
    {cgc_size_t tlv71; tlv71 = (cgc_size_t)(NULL); }
    {char * tlv78; tlv78 = (char *)(NULL); }
    {char * tlv79; tlv79 = (char *)(NULL); }
}
void fix_ingred_planetParsers_5_0_1(){
    {double period; period = (double)(- 1.0); }
}
void fix_ingred_planetParsers_5_0_2(){
    {char * temp; temp = (char *)(0); }
    {int start; start = (int)(0); }
    {int end; end = (int)(0); }
    {int ps; ps = (int)(0); }
    {int pe; pe = (int)(0); }
    {int tlv8; tlv8 = (int)(0); }
    {int tlv9; tlv9 = (int)(0); }
    {int tlv10; tlv10 = (int)(0); }
    {int tlv23; tlv23 = (int)(0); }
    {int tlv28; tlv28 = (int)(0); }
    {int tlv27; tlv27 = (int)(0); }
    {void * tlv12; tlv12 = (void *)(0); }
    {cgc_size_t tlv11; tlv11 = (cgc_size_t)(0); }
    {char tlv32; tlv32 = (char)(0); }
    {int tlv34; tlv34 = (int)(0); }
    {int * tlv13; tlv13 = (int *)(0); }
    {int tlv39; tlv39 = (int)(0); }
    {char tlv41; tlv41 = (char)(0); }
    {int tlv43; tlv43 = (int)(0); }
    {int tlv47; tlv47 = (int)(0); }
    {int tlv46; tlv46 = (int)(0); }
    {void * tlv16; tlv16 = (void *)(0); }
    {cgc_size_t tlv15; tlv15 = (cgc_size_t)(0); }
    {char tlv51; tlv51 = (char)(0); }
    {int tlv17; tlv17 = (int)(0); }
    {int tlv54; tlv54 = (int)(0); }
    {int tlv53; tlv53 = (int)(0); }
    {void * tlv20; tlv20 = (void *)(0); }
    {cgc_size_t tlv19; tlv19 = (cgc_size_t)(0); }
    {char * tlv75; tlv75 = (char *)(0); }
    {char * tlv76; tlv76 = (char *)(0); }
    {char * tlv77; tlv77 = (char *)(0); }
    {void * tlv62; tlv62 = (void *)(0); }
    {cgc_size_t tlv61; tlv61 = (cgc_size_t)(0); }
    {void * tlv72; tlv72 = (void *)(0); }
    {cgc_size_t tlv71; tlv71 = (cgc_size_t)(0); }
    {char * tlv78; tlv78 = (char *)(0); }
    {char * tlv79; tlv79 = (char *)(0); }
}
void fix_ingred_planetParsers_5_0(){
fix_ingred_planetParsers_5_0_0();
fix_ingred_planetParsers_5_0_1();
fix_ingred_planetParsers_5_0_2();
}
void fix_ingred_planetParsers_5_2_1(){
    {char * temp; temp = (char *)('{'); }
    {int start; start = (int)('{'); }
    {int end; end = (int)('{'); }
    {int ps; ps = (int)('{'); }
    {int pe; pe = (int)('{'); }
    {int tlv8; tlv8 = (int)('{'); }
    {int tlv9; tlv9 = (int)('{'); }
    {int tlv10; tlv10 = (int)('{'); }
    {int tlv23; tlv23 = (int)('{'); }
    {int tlv28; tlv28 = (int)('{'); }
    {int tlv27; tlv27 = (int)('{'); }
    {void * tlv12; tlv12 = (void *)('{'); }
    {cgc_size_t tlv11; tlv11 = (cgc_size_t)('{'); }
    {char tlv32; tlv32 = (char)('{'); }
    {int tlv34; tlv34 = (int)('{'); }
    {int * tlv13; tlv13 = (int *)('{'); }
    {char tlv37; tlv37 = (char)('{'); }
    {int tlv39; tlv39 = (int)('{'); }
    {char tlv41; tlv41 = (char)('{'); }
    {int tlv43; tlv43 = (int)('{'); }
    {int tlv47; tlv47 = (int)('{'); }
    {int tlv46; tlv46 = (int)('{'); }
    {void * tlv16; tlv16 = (void *)('{'); }
    {cgc_size_t tlv15; tlv15 = (cgc_size_t)('{'); }
    {char tlv51; tlv51 = (char)('{'); }
    {int tlv17; tlv17 = (int)('{'); }
    {int tlv54; tlv54 = (int)('{'); }
    {int tlv53; tlv53 = (int)('{'); }
    {void * tlv20; tlv20 = (void *)('{'); }
    {cgc_size_t tlv19; tlv19 = (cgc_size_t)('{'); }
    {char * tlv75; tlv75 = (char *)('{'); }
    {char * tlv76; tlv76 = (char *)('{'); }
    {char * tlv77; tlv77 = (char *)('{'); }
    {void * tlv62; tlv62 = (void *)('{'); }
    {cgc_size_t tlv61; tlv61 = (cgc_size_t)('{'); }
    {void * tlv72; tlv72 = (void *)('{'); }
    {cgc_size_t tlv71; tlv71 = (cgc_size_t)('{'); }
    {char * tlv78; tlv78 = (char *)('{'); }
    {char * tlv79; tlv79 = (char *)('{'); }
}
void fix_ingred_planetParsers_5_2(){
fix_ingred_planetParsers_5_2_1();
}
void fix_ingred_planetParsers_5_5_1(){
    {char * temp; temp = (char *)(1); }
    {int start; start = (int)(1); }
    {int end; end = (int)(1); }
    {int ps; ps = (int)(1); }
    {int pe; pe = (int)(1); }
    {int tlv3; tlv3 = (int)(1); }
    {int tlv4; tlv4 = (int)(1); }
    {int tlv5; tlv5 = (int)(1); }
    {int tlv6; tlv6 = (int)(1); }
    {int tlv7; tlv7 = (int)(1); }
    {int tlv8; tlv8 = (int)(1); }
    {int tlv9; tlv9 = (int)(1); }
    {int tlv10; tlv10 = (int)(1); }
    {int tlv23; tlv23 = (int)(1); }
    {int tlv28; tlv28 = (int)(1); }
    {int tlv27; tlv27 = (int)(1); }
    {void * tlv12; tlv12 = (void *)(1); }
    {cgc_size_t tlv11; tlv11 = (cgc_size_t)(1); }
    {char tlv32; tlv32 = (char)(1); }
    {int tlv34; tlv34 = (int)(1); }
    {int * tlv13; tlv13 = (int *)(1); }
    {int tlv39; tlv39 = (int)(1); }
    {char tlv41; tlv41 = (char)(1); }
    {int tlv43; tlv43 = (int)(1); }
    {int tlv47; tlv47 = (int)(1); }
    {int tlv46; tlv46 = (int)(1); }
    {void * tlv16; tlv16 = (void *)(1); }
    {cgc_size_t tlv15; tlv15 = (cgc_size_t)(1); }
    {char tlv51; tlv51 = (char)(1); }
    {int tlv17; tlv17 = (int)(1); }
    {int tlv54; tlv54 = (int)(1); }
    {int tlv53; tlv53 = (int)(1); }
    {void * tlv20; tlv20 = (void *)(1); }
    {cgc_size_t tlv19; tlv19 = (cgc_size_t)(1); }
    {char * tlv75; tlv75 = (char *)(1); }
    {char * tlv76; tlv76 = (char *)(1); }
    {char * tlv77; tlv77 = (char *)(1); }
    {void * tlv62; tlv62 = (void *)(1); }
    {cgc_size_t tlv61; tlv61 = (cgc_size_t)(1); }
    {void * tlv72; tlv72 = (void *)(1); }
    {cgc_size_t tlv71; tlv71 = (cgc_size_t)(1); }
    {char * tlv78; tlv78 = (char *)(1); }
    {char * tlv79; tlv79 = (char *)(1); }
}
void fix_ingred_planetParsers_5_5(){
fix_ingred_planetParsers_5_5_1();
}
void fix_ingred_planetParsers_5_6_6(){
int tlv2;
    bzero(&tlv2,sizeof(int));
    {char * temp; temp = (char *)(tlv2); }
    {int start; start = (int)(tlv2); }
    {int end; end = (int)(tlv2); }
    {int ps; ps = (int)(tlv2); }
    {int pe; pe = (int)(tlv2); }
    {int tlv3; tlv3 = (int)(tlv2); }
    {int tlv4; tlv4 = (int)(tlv2); }
    {int tlv5; tlv5 = (int)(tlv2); }
    {int tlv6; tlv6 = (int)(tlv2); }
    {int tlv7; tlv7 = (int)(tlv2); }
    {int tlv8; tlv8 = (int)(tlv2); }
    {int tlv9; tlv9 = (int)(tlv2); }
    {int tlv10; tlv10 = (int)(tlv2); }
    {int tlv23; tlv23 = (int)(tlv2); }
    {int tlv28; tlv28 = (int)(tlv2); }
    {int tlv27; tlv27 = (int)(tlv2); }
    {void * tlv12; tlv12 = (void *)(tlv2); }
    {cgc_size_t tlv11; tlv11 = (cgc_size_t)(tlv2); }
    {char tlv32; tlv32 = (char)(tlv2); }
    {int tlv34; tlv34 = (int)(tlv2); }
    {int * tlv13; tlv13 = (int *)(tlv2); }
    {int tlv39; tlv39 = (int)(tlv2); }
    {char tlv41; tlv41 = (char)(tlv2); }
    {int tlv43; tlv43 = (int)(tlv2); }
    {int tlv47; tlv47 = (int)(tlv2); }
    {int tlv46; tlv46 = (int)(tlv2); }
    {void * tlv16; tlv16 = (void *)(tlv2); }
    {cgc_size_t tlv15; tlv15 = (cgc_size_t)(tlv2); }
    {char tlv51; tlv51 = (char)(tlv2); }
    {int tlv17; tlv17 = (int)(tlv2); }
    {int tlv54; tlv54 = (int)(tlv2); }
    {int tlv53; tlv53 = (int)(tlv2); }
    {void * tlv20; tlv20 = (void *)(tlv2); }
    {cgc_size_t tlv19; tlv19 = (cgc_size_t)(tlv2); }
    {char * tlv75; tlv75 = (char *)(tlv2); }
    {char * tlv76; tlv76 = (char *)(tlv2); }
    {char * tlv77; tlv77 = (char *)(tlv2); }
    {void * tlv62; tlv62 = (void *)(tlv2); }
    {cgc_size_t tlv61; tlv61 = (cgc_size_t)(tlv2); }
    {void * tlv72; tlv72 = (void *)(tlv2); }
    {cgc_size_t tlv71; tlv71 = (cgc_size_t)(tlv2); }
    {char * tlv78; tlv78 = (char *)(tlv2); }
    {char * tlv79; tlv79 = (char *)(tlv2); }
}
void fix_ingred_planetParsers_5_6_7(){
int tlv2;
    bzero(&tlv2,sizeof(int));
    {char * temp; temp = (char *)(- 1); }
    {int start; start = (int)(- 1); }
    {int end; end = (int)(- 1); }
    {int ps; ps = (int)(- 1); }
    {int pe; pe = (int)(- 1); }
    {int tlv8; tlv8 = (int)(- 1); }
    {int tlv9; tlv9 = (int)(- 1); }
    {int tlv10; tlv10 = (int)(- 1); }
    {int tlv23; tlv23 = (int)(- 1); }
    {int tlv28; tlv28 = (int)(- 1); }
    {int tlv27; tlv27 = (int)(- 1); }
    {void * tlv12; tlv12 = (void *)(- 1); }
    {cgc_size_t tlv11; tlv11 = (cgc_size_t)(- 1); }
    {char tlv32; tlv32 = (char)(- 1); }
    {int tlv34; tlv34 = (int)(- 1); }
    {int * tlv13; tlv13 = (int *)(- 1); }
    {char tlv37; tlv37 = (char)(- 1); }
    {int tlv39; tlv39 = (int)(- 1); }
    {char tlv41; tlv41 = (char)(- 1); }
    {int tlv43; tlv43 = (int)(- 1); }
    {int tlv47; tlv47 = (int)(- 1); }
    {int tlv46; tlv46 = (int)(- 1); }
    {void * tlv16; tlv16 = (void *)(- 1); }
    {cgc_size_t tlv15; tlv15 = (cgc_size_t)(- 1); }
    {char tlv51; tlv51 = (char)(- 1); }
    {int tlv17; tlv17 = (int)(- 1); }
    {int tlv54; tlv54 = (int)(- 1); }
    {int tlv53; tlv53 = (int)(- 1); }
    {void * tlv20; tlv20 = (void *)(- 1); }
    {cgc_size_t tlv19; tlv19 = (cgc_size_t)(- 1); }
    {char * tlv75; tlv75 = (char *)(- 1); }
    {char * tlv76; tlv76 = (char *)(- 1); }
    {char * tlv77; tlv77 = (char *)(- 1); }
    {void * tlv62; tlv62 = (void *)(- 1); }
    {cgc_size_t tlv61; tlv61 = (cgc_size_t)(- 1); }
    {void * tlv72; tlv72 = (void *)(- 1); }
    {cgc_size_t tlv71; tlv71 = (cgc_size_t)(- 1); }
    {char * tlv78; tlv78 = (char *)(- 1); }
    {char * tlv79; tlv79 = (char *)(- 1); }
}
void fix_ingred_planetParsers_5_6(){
fix_ingred_planetParsers_5_6_6();
fix_ingred_planetParsers_5_6_7();
}
void fix_ingred_planetParsers_5_10_6(){
int end;
    bzero(&end,sizeof(int));
    {char * temp; temp = (char *)(end); }
    {int start; start = (int)(end); }
    {int ps; ps = (int)(end); }
    {int pe; pe = (int)(end); }
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
    {char tlv21; tlv21 = (char)(end); }
    {int tlv23; tlv23 = (int)(end); }
    {int tlv28; tlv28 = (int)(end); }
    {int tlv27; tlv27 = (int)(end); }
    {void * tlv12; tlv12 = (void *)(end); }
    {cgc_size_t tlv11; tlv11 = (cgc_size_t)(end); }
    {char tlv32; tlv32 = (char)(end); }
    {int tlv34; tlv34 = (int)(end); }
    {int * tlv13; tlv13 = (int *)(end); }
    {char tlv37; tlv37 = (char)(end); }
    {int tlv39; tlv39 = (int)(end); }
    {char tlv41; tlv41 = (char)(end); }
    {int tlv43; tlv43 = (int)(end); }
    {int tlv47; tlv47 = (int)(end); }
    {int tlv46; tlv46 = (int)(end); }
    {void * tlv16; tlv16 = (void *)(end); }
    {cgc_size_t tlv15; tlv15 = (cgc_size_t)(end); }
    {char tlv51; tlv51 = (char)(end); }
    {int tlv17; tlv17 = (int)(end); }
    {int tlv54; tlv54 = (int)(end); }
    {int tlv53; tlv53 = (int)(end); }
    {void * tlv20; tlv20 = (void *)(end); }
    {cgc_size_t tlv19; tlv19 = (cgc_size_t)(end); }
    {char * tlv75; tlv75 = (char *)(end); }
    {char * tlv76; tlv76 = (char *)(end); }
    {char * tlv77; tlv77 = (char *)(end); }
    {void * tlv62; tlv62 = (void *)(end); }
    {cgc_size_t tlv61; tlv61 = (cgc_size_t)(end); }
    {void * tlv72; tlv72 = (void *)(end); }
    {cgc_size_t tlv71; tlv71 = (cgc_size_t)(end); }
    {char * tlv78; tlv78 = (char *)(end); }
    {char * tlv79; tlv79 = (char *)(end); }
}
void fix_ingred_planetParsers_5_10(){
fix_ingred_planetParsers_5_10_6();
}
void fix_ingred_planetParsers_5_12_1(){
int start;
    bzero(&start,sizeof(int));
    {char * temp; temp = (char *)(start); }
    {int end; end = (int)(start); }
    {int ps; ps = (int)(start); }
    {int pe; pe = (int)(start); }
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
    {char tlv21; tlv21 = (char)(start); }
    {int tlv23; tlv23 = (int)(start); }
    {int tlv28; tlv28 = (int)(start); }
    {int tlv27; tlv27 = (int)(start); }
    {void * tlv12; tlv12 = (void *)(start); }
    {cgc_size_t tlv11; tlv11 = (cgc_size_t)(start); }
    {char tlv32; tlv32 = (char)(start); }
    {int tlv34; tlv34 = (int)(start); }
    {int * tlv13; tlv13 = (int *)(start); }
    {char tlv37; tlv37 = (char)(start); }
    {int tlv39; tlv39 = (int)(start); }
    {char tlv41; tlv41 = (char)(start); }
    {int tlv43; tlv43 = (int)(start); }
    {int tlv47; tlv47 = (int)(start); }
    {int tlv46; tlv46 = (int)(start); }
    {void * tlv16; tlv16 = (void *)(start); }
    {cgc_size_t tlv15; tlv15 = (cgc_size_t)(start); }
    {char tlv51; tlv51 = (char)(start); }
    {int tlv17; tlv17 = (int)(start); }
    {int tlv54; tlv54 = (int)(start); }
    {int tlv53; tlv53 = (int)(start); }
    {void * tlv20; tlv20 = (void *)(start); }
    {cgc_size_t tlv19; tlv19 = (cgc_size_t)(start); }
    {char * tlv75; tlv75 = (char *)(start); }
    {char * tlv76; tlv76 = (char *)(start); }
    {char * tlv77; tlv77 = (char *)(start); }
    {void * tlv62; tlv62 = (void *)(start); }
    {cgc_size_t tlv61; tlv61 = (cgc_size_t)(start); }
    {void * tlv72; tlv72 = (void *)(start); }
    {cgc_size_t tlv71; tlv71 = (cgc_size_t)(start); }
    {char * tlv78; tlv78 = (char *)(start); }
    {char * tlv79; tlv79 = (char *)(start); }
}
void fix_ingred_planetParsers_5_12(){
fix_ingred_planetParsers_5_12_1();
}
void fix_ingred_planetParsers_5_13_6(){
char temp_ref;
    bzero(&temp_ref,1*sizeof(char));
char * temp = &temp_ref;
    {int start; start = (int)(temp); }
    {int end; end = (int)(temp); }
    {int ps; ps = (int)(temp); }
    {int pe; pe = (int)(temp); }
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
    {char tlv21; tlv21 = (char)(temp); }
    {int tlv23; tlv23 = (int)(temp); }
    {int tlv28; tlv28 = (int)(temp); }
    {int tlv27; tlv27 = (int)(temp); }
    {void * tlv12; tlv12 = (void *)(temp); }
    {cgc_size_t tlv11; tlv11 = (cgc_size_t)(temp); }
    {char tlv32; tlv32 = (char)(temp); }
    {int tlv34; tlv34 = (int)(temp); }
    {int * tlv13; tlv13 = (int *)(temp); }
    {char tlv37; tlv37 = (char)(temp); }
    {int tlv39; tlv39 = (int)(temp); }
    {char tlv41; tlv41 = (char)(temp); }
    {int tlv43; tlv43 = (int)(temp); }
    {int tlv47; tlv47 = (int)(temp); }
    {int tlv46; tlv46 = (int)(temp); }
    {void * tlv16; tlv16 = (void *)(temp); }
    {cgc_size_t tlv15; tlv15 = (cgc_size_t)(temp); }
    {char tlv51; tlv51 = (char)(temp); }
    {int tlv17; tlv17 = (int)(temp); }
    {int tlv54; tlv54 = (int)(temp); }
    {int tlv53; tlv53 = (int)(temp); }
    {void * tlv20; tlv20 = (void *)(temp); }
    {cgc_size_t tlv19; tlv19 = (cgc_size_t)(temp); }
    {char * tlv75; tlv75 = (char *)(temp); }
    {char * tlv76; tlv76 = (char *)(temp); }
    {char * tlv77; tlv77 = (char *)(temp); }
    {void * tlv62; tlv62 = (void *)(temp); }
    {cgc_size_t tlv61; tlv61 = (cgc_size_t)(temp); }
    {void * tlv72; tlv72 = (void *)(temp); }
    {cgc_size_t tlv71; tlv71 = (cgc_size_t)(temp); }
    {char * tlv78; tlv78 = (char *)(temp); }
    {char * tlv79; tlv79 = (char *)(temp); }
}
void fix_ingred_planetParsers_5_13(){
fix_ingred_planetParsers_5_13_6();
}
void fix_ingred_planetParsers_5_15_7(){
int tlv3;
    bzero(&tlv3,sizeof(int));
    {char * temp; temp = (char *)(tlv3); }
    {int start; start = (int)(tlv3); }
    {int end; end = (int)(tlv3); }
    {int ps; ps = (int)(tlv3); }
    {int pe; pe = (int)(tlv3); }
    {int tlv8; tlv8 = (int)(tlv3); }
    {int tlv9; tlv9 = (int)(tlv3); }
    {int tlv10; tlv10 = (int)(tlv3); }
    {int tlv23; tlv23 = (int)(tlv3); }
    {int tlv28; tlv28 = (int)(tlv3); }
    {int tlv27; tlv27 = (int)(tlv3); }
    {void * tlv12; tlv12 = (void *)(tlv3); }
    {cgc_size_t tlv11; tlv11 = (cgc_size_t)(tlv3); }
    {char tlv32; tlv32 = (char)(tlv3); }
    {int tlv34; tlv34 = (int)(tlv3); }
    {int * tlv13; tlv13 = (int *)(tlv3); }
    {char tlv37; tlv37 = (char)(tlv3); }
    {int tlv39; tlv39 = (int)(tlv3); }
    {char tlv41; tlv41 = (char)(tlv3); }
    {int tlv43; tlv43 = (int)(tlv3); }
    {int tlv47; tlv47 = (int)(tlv3); }
    {int tlv46; tlv46 = (int)(tlv3); }
    {void * tlv16; tlv16 = (void *)(tlv3); }
    {cgc_size_t tlv15; tlv15 = (cgc_size_t)(tlv3); }
    {char tlv51; tlv51 = (char)(tlv3); }
    {int tlv17; tlv17 = (int)(tlv3); }
    {int tlv54; tlv54 = (int)(tlv3); }
    {int tlv53; tlv53 = (int)(tlv3); }
    {void * tlv20; tlv20 = (void *)(tlv3); }
    {cgc_size_t tlv19; tlv19 = (cgc_size_t)(tlv3); }
    {char * tlv75; tlv75 = (char *)(tlv3); }
    {char * tlv76; tlv76 = (char *)(tlv3); }
    {char * tlv77; tlv77 = (char *)(tlv3); }
    {void * tlv62; tlv62 = (void *)(tlv3); }
    {cgc_size_t tlv61; tlv61 = (cgc_size_t)(tlv3); }
    {void * tlv72; tlv72 = (void *)(tlv3); }
    {cgc_size_t tlv71; tlv71 = (cgc_size_t)(tlv3); }
    {char * tlv78; tlv78 = (char *)(tlv3); }
    {char * tlv79; tlv79 = (char *)(tlv3); }
}
void fix_ingred_planetParsers_5_15(){
fix_ingred_planetParsers_5_15_7();
}
void fix_ingred_planetParsers_5_17_0(){
char temp_ref;
    bzero(&temp_ref,1*sizeof(char));
char * temp = &temp_ref;
    {int start; start = (int)(temp); }
    {int end; end = (int)(temp); }
    {int ps; ps = (int)(temp); }
    {int pe; pe = (int)(temp); }
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
    {char tlv21; tlv21 = (char)(temp); }
    {int tlv23; tlv23 = (int)(temp); }
    {int tlv28; tlv28 = (int)(temp); }
    {int tlv27; tlv27 = (int)(temp); }
    {void * tlv12; tlv12 = (void *)(temp); }
    {cgc_size_t tlv11; tlv11 = (cgc_size_t)(temp); }
    {char tlv32; tlv32 = (char)(temp); }
    {int tlv34; tlv34 = (int)(temp); }
    {int * tlv13; tlv13 = (int *)(temp); }
    {char tlv37; tlv37 = (char)(temp); }
    {int tlv39; tlv39 = (int)(temp); }
    {char tlv41; tlv41 = (char)(temp); }
    {int tlv43; tlv43 = (int)(temp); }
    {int tlv47; tlv47 = (int)(temp); }
    {int tlv46; tlv46 = (int)(temp); }
    {void * tlv16; tlv16 = (void *)(temp); }
    {cgc_size_t tlv15; tlv15 = (cgc_size_t)(temp); }
    {char tlv51; tlv51 = (char)(temp); }
    {int tlv17; tlv17 = (int)(temp); }
    {int tlv54; tlv54 = (int)(temp); }
    {int tlv53; tlv53 = (int)(temp); }
    {void * tlv20; tlv20 = (void *)(temp); }
    {cgc_size_t tlv19; tlv19 = (cgc_size_t)(temp); }
    {char * tlv75; tlv75 = (char *)(temp); }
    {char * tlv76; tlv76 = (char *)(temp); }
    {char * tlv77; tlv77 = (char *)(temp); }
    {void * tlv62; tlv62 = (void *)(temp); }
    {cgc_size_t tlv61; tlv61 = (cgc_size_t)(temp); }
    {void * tlv72; tlv72 = (void *)(temp); }
    {cgc_size_t tlv71; tlv71 = (cgc_size_t)(temp); }
    {char * tlv78; tlv78 = (char *)(temp); }
    {char * tlv79; tlv79 = (char *)(temp); }
}
void fix_ingred_planetParsers_5_17(){
fix_ingred_planetParsers_5_17_0();
}
void fix_ingred_planetParsers_5_18_1(){
char tlv78_ref;
    bzero(&tlv78_ref,1*sizeof(char));
char * tlv78 = &tlv78_ref;
    {char * temp; temp = (char *)(cgc_strlen ( tlv78 ) + 1); }
    {int start; start = (int)(cgc_strlen ( tlv78 ) + 1); }
    {int end; end = (int)(cgc_strlen ( tlv78 ) + 1); }
    {int ps; ps = (int)(cgc_strlen ( tlv78 ) + 1); }
    {int pe; pe = (int)(cgc_strlen ( tlv78 ) + 1); }
    {int tlv1; tlv1 = (int)(cgc_strlen ( tlv78 ) + 1); }
    {int tlv2; tlv2 = (int)(cgc_strlen ( tlv78 ) + 1); }
    {int tlv3; tlv3 = (int)(cgc_strlen ( tlv78 ) + 1); }
    {int tlv4; tlv4 = (int)(cgc_strlen ( tlv78 ) + 1); }
    {int tlv5; tlv5 = (int)(cgc_strlen ( tlv78 ) + 1); }
    {int tlv6; tlv6 = (int)(cgc_strlen ( tlv78 ) + 1); }
    {int tlv7; tlv7 = (int)(cgc_strlen ( tlv78 ) + 1); }
    {int tlv8; tlv8 = (int)(cgc_strlen ( tlv78 ) + 1); }
    {int tlv9; tlv9 = (int)(cgc_strlen ( tlv78 ) + 1); }
    {int tlv10; tlv10 = (int)(cgc_strlen ( tlv78 ) + 1); }
    {char tlv21; tlv21 = (char)(cgc_strlen ( tlv78 ) + 1); }
    {int tlv23; tlv23 = (int)(cgc_strlen ( tlv78 ) + 1); }
    {int tlv28; tlv28 = (int)(cgc_strlen ( tlv78 ) + 1); }
    {int tlv27; tlv27 = (int)(cgc_strlen ( tlv78 ) + 1); }
    {void * tlv12; tlv12 = (void *)(cgc_strlen ( tlv78 ) + 1); }
    {cgc_size_t tlv11; tlv11 = (cgc_size_t)(cgc_strlen ( tlv78 ) + 1); }
    {char tlv32; tlv32 = (char)(cgc_strlen ( tlv78 ) + 1); }
    {int tlv34; tlv34 = (int)(cgc_strlen ( tlv78 ) + 1); }
    {int * tlv13; tlv13 = (int *)(cgc_strlen ( tlv78 ) + 1); }
    {char tlv37; tlv37 = (char)(cgc_strlen ( tlv78 ) + 1); }
    {int tlv39; tlv39 = (int)(cgc_strlen ( tlv78 ) + 1); }
    {char tlv41; tlv41 = (char)(cgc_strlen ( tlv78 ) + 1); }
    {int tlv43; tlv43 = (int)(cgc_strlen ( tlv78 ) + 1); }
    {int tlv47; tlv47 = (int)(cgc_strlen ( tlv78 ) + 1); }
    {int tlv46; tlv46 = (int)(cgc_strlen ( tlv78 ) + 1); }
    {void * tlv16; tlv16 = (void *)(cgc_strlen ( tlv78 ) + 1); }
    {cgc_size_t tlv15; tlv15 = (cgc_size_t)(cgc_strlen ( tlv78 ) + 1); }
    {char tlv51; tlv51 = (char)(cgc_strlen ( tlv78 ) + 1); }
    {int tlv17; tlv17 = (int)(cgc_strlen ( tlv78 ) + 1); }
    {int tlv54; tlv54 = (int)(cgc_strlen ( tlv78 ) + 1); }
    {int tlv53; tlv53 = (int)(cgc_strlen ( tlv78 ) + 1); }
    {void * tlv20; tlv20 = (void *)(cgc_strlen ( tlv78 ) + 1); }
    {cgc_size_t tlv19; tlv19 = (cgc_size_t)(cgc_strlen ( tlv78 ) + 1); }
    {char * tlv75; tlv75 = (char *)(cgc_strlen ( tlv78 ) + 1); }
    {char * tlv76; tlv76 = (char *)(cgc_strlen ( tlv78 ) + 1); }
    {char * tlv77; tlv77 = (char *)(cgc_strlen ( tlv78 ) + 1); }
    {void * tlv62; tlv62 = (void *)(cgc_strlen ( tlv78 ) + 1); }
    {cgc_size_t tlv61; tlv61 = (cgc_size_t)(cgc_strlen ( tlv78 ) + 1); }
    {void * tlv72; tlv72 = (void *)(cgc_strlen ( tlv78 ) + 1); }
    {cgc_size_t tlv71; tlv71 = (cgc_size_t)(cgc_strlen ( tlv78 ) + 1); }
    {char * tlv79; tlv79 = (char *)(cgc_strlen ( tlv78 ) + 1); }
}
void fix_ingred_planetParsers_5_18(){
fix_ingred_planetParsers_5_18_1();
}
void fix_ingred_planetParsers_5_20_1(){
char tlv75_ref;
    bzero(&tlv75_ref,1*sizeof(char));
char * tlv75 = &tlv75_ref;
    {char * temp; temp = (char *)(cgc_strlen ( tlv75 ) + 1); }
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
    {char tlv21; tlv21 = (char)(cgc_strlen ( tlv75 ) + 1); }
    {int tlv23; tlv23 = (int)(cgc_strlen ( tlv75 ) + 1); }
    {int tlv28; tlv28 = (int)(cgc_strlen ( tlv75 ) + 1); }
    {int tlv27; tlv27 = (int)(cgc_strlen ( tlv75 ) + 1); }
    {void * tlv12; tlv12 = (void *)(cgc_strlen ( tlv75 ) + 1); }
    {cgc_size_t tlv11; tlv11 = (cgc_size_t)(cgc_strlen ( tlv75 ) + 1); }
    {char tlv32; tlv32 = (char)(cgc_strlen ( tlv75 ) + 1); }
    {int tlv34; tlv34 = (int)(cgc_strlen ( tlv75 ) + 1); }
    {int * tlv13; tlv13 = (int *)(cgc_strlen ( tlv75 ) + 1); }
    {char tlv37; tlv37 = (char)(cgc_strlen ( tlv75 ) + 1); }
    {int tlv39; tlv39 = (int)(cgc_strlen ( tlv75 ) + 1); }
    {char tlv41; tlv41 = (char)(cgc_strlen ( tlv75 ) + 1); }
    {int tlv43; tlv43 = (int)(cgc_strlen ( tlv75 ) + 1); }
    {int tlv47; tlv47 = (int)(cgc_strlen ( tlv75 ) + 1); }
    {int tlv46; tlv46 = (int)(cgc_strlen ( tlv75 ) + 1); }
    {void * tlv16; tlv16 = (void *)(cgc_strlen ( tlv75 ) + 1); }
    {cgc_size_t tlv15; tlv15 = (cgc_size_t)(cgc_strlen ( tlv75 ) + 1); }
    {char tlv51; tlv51 = (char)(cgc_strlen ( tlv75 ) + 1); }
    {int tlv17; tlv17 = (int)(cgc_strlen ( tlv75 ) + 1); }
    {int tlv54; tlv54 = (int)(cgc_strlen ( tlv75 ) + 1); }
    {int tlv53; tlv53 = (int)(cgc_strlen ( tlv75 ) + 1); }
    {void * tlv20; tlv20 = (void *)(cgc_strlen ( tlv75 ) + 1); }
    {cgc_size_t tlv19; tlv19 = (cgc_size_t)(cgc_strlen ( tlv75 ) + 1); }
    {char * tlv76; tlv76 = (char *)(cgc_strlen ( tlv75 ) + 1); }
    {char * tlv77; tlv77 = (char *)(cgc_strlen ( tlv75 ) + 1); }
    {void * tlv62; tlv62 = (void *)(cgc_strlen ( tlv75 ) + 1); }
    {cgc_size_t tlv61; tlv61 = (cgc_size_t)(cgc_strlen ( tlv75 ) + 1); }
    {void * tlv72; tlv72 = (void *)(cgc_strlen ( tlv75 ) + 1); }
    {cgc_size_t tlv71; tlv71 = (cgc_size_t)(cgc_strlen ( tlv75 ) + 1); }
    {char * tlv78; tlv78 = (char *)(cgc_strlen ( tlv75 ) + 1); }
    {char * tlv79; tlv79 = (char *)(cgc_strlen ( tlv75 ) + 1); }
}
void fix_ingred_planetParsers_5_20(){
fix_ingred_planetParsers_5_20_1();
}
void fix_ingred_planetParsers_5_21_1(){
    {char * temp; temp = (char *)('}'); }
    {int start; start = (int)('}'); }
    {int end; end = (int)('}'); }
    {int ps; ps = (int)('}'); }
    {int pe; pe = (int)('}'); }
    {int tlv8; tlv8 = (int)('}'); }
    {int tlv9; tlv9 = (int)('}'); }
    {int tlv10; tlv10 = (int)('}'); }
    {int tlv23; tlv23 = (int)('}'); }
    {int tlv28; tlv28 = (int)('}'); }
    {int tlv27; tlv27 = (int)('}'); }
    {void * tlv12; tlv12 = (void *)('}'); }
    {cgc_size_t tlv11; tlv11 = (cgc_size_t)('}'); }
    {char tlv32; tlv32 = (char)('}'); }
    {int tlv34; tlv34 = (int)('}'); }
    {int * tlv13; tlv13 = (int *)('}'); }
    {char tlv37; tlv37 = (char)('}'); }
    {int tlv39; tlv39 = (int)('}'); }
    {char tlv41; tlv41 = (char)('}'); }
    {int tlv43; tlv43 = (int)('}'); }
    {int tlv47; tlv47 = (int)('}'); }
    {int tlv46; tlv46 = (int)('}'); }
    {void * tlv16; tlv16 = (void *)('}'); }
    {cgc_size_t tlv15; tlv15 = (cgc_size_t)('}'); }
    {char tlv51; tlv51 = (char)('}'); }
    {int tlv17; tlv17 = (int)('}'); }
    {int tlv54; tlv54 = (int)('}'); }
    {int tlv53; tlv53 = (int)('}'); }
    {void * tlv20; tlv20 = (void *)('}'); }
    {cgc_size_t tlv19; tlv19 = (cgc_size_t)('}'); }
    {char * tlv75; tlv75 = (char *)('}'); }
    {char * tlv76; tlv76 = (char *)('}'); }
    {char * tlv77; tlv77 = (char *)('}'); }
    {void * tlv62; tlv62 = (void *)('}'); }
    {cgc_size_t tlv61; tlv61 = (cgc_size_t)('}'); }
    {void * tlv72; tlv72 = (void *)('}'); }
    {cgc_size_t tlv71; tlv71 = (cgc_size_t)('}'); }
    {char * tlv78; tlv78 = (char *)('}'); }
    {char * tlv79; tlv79 = (char *)('}'); }
}
void fix_ingred_planetParsers_5_21(){
fix_ingred_planetParsers_5_21_1();
}
void fix_ingred_planetParsers_5_25_6(){
int tlv5;
    bzero(&tlv5,sizeof(int));
    {char * temp; temp = (char *)(tlv5); }
    {int start; start = (int)(tlv5); }
    {int end; end = (int)(tlv5); }
    {int ps; ps = (int)(tlv5); }
    {int pe; pe = (int)(tlv5); }
    {int tlv8; tlv8 = (int)(tlv5); }
    {int tlv9; tlv9 = (int)(tlv5); }
    {int tlv10; tlv10 = (int)(tlv5); }
    {int tlv23; tlv23 = (int)(tlv5); }
    {int tlv28; tlv28 = (int)(tlv5); }
    {int tlv27; tlv27 = (int)(tlv5); }
    {void * tlv12; tlv12 = (void *)(tlv5); }
    {cgc_size_t tlv11; tlv11 = (cgc_size_t)(tlv5); }
    {char tlv32; tlv32 = (char)(tlv5); }
    {int tlv34; tlv34 = (int)(tlv5); }
    {int * tlv13; tlv13 = (int *)(tlv5); }
    {char tlv37; tlv37 = (char)(tlv5); }
    {int tlv39; tlv39 = (int)(tlv5); }
    {char tlv41; tlv41 = (char)(tlv5); }
    {int tlv43; tlv43 = (int)(tlv5); }
    {int tlv47; tlv47 = (int)(tlv5); }
    {int tlv46; tlv46 = (int)(tlv5); }
    {void * tlv16; tlv16 = (void *)(tlv5); }
    {cgc_size_t tlv15; tlv15 = (cgc_size_t)(tlv5); }
    {char tlv51; tlv51 = (char)(tlv5); }
    {int tlv17; tlv17 = (int)(tlv5); }
    {int tlv54; tlv54 = (int)(tlv5); }
    {int tlv53; tlv53 = (int)(tlv5); }
    {void * tlv20; tlv20 = (void *)(tlv5); }
    {cgc_size_t tlv19; tlv19 = (cgc_size_t)(tlv5); }
    {char * tlv75; tlv75 = (char *)(tlv5); }
    {char * tlv76; tlv76 = (char *)(tlv5); }
    {char * tlv77; tlv77 = (char *)(tlv5); }
    {void * tlv62; tlv62 = (void *)(tlv5); }
    {cgc_size_t tlv61; tlv61 = (cgc_size_t)(tlv5); }
    {void * tlv72; tlv72 = (void *)(tlv5); }
    {cgc_size_t tlv71; tlv71 = (cgc_size_t)(tlv5); }
    {char * tlv78; tlv78 = (char *)(tlv5); }
    {char * tlv79; tlv79 = (char *)(tlv5); }
}
void fix_ingred_planetParsers_5_25(){
fix_ingred_planetParsers_5_25_6();
}
void fix_ingred_planetParsers_5_27_1(){
int ps;
    bzero(&ps,sizeof(int));
    {char * temp; temp = (char *)(& ps); }
    {int start; start = (int)(& ps); }
    {int end; end = (int)(& ps); }
    {int pe; pe = (int)(& ps); }
    {int tlv1; tlv1 = (int)(& ps); }
    {int tlv2; tlv2 = (int)(& ps); }
    {int tlv3; tlv3 = (int)(& ps); }
    {int tlv4; tlv4 = (int)(& ps); }
    {int tlv5; tlv5 = (int)(& ps); }
    {int tlv6; tlv6 = (int)(& ps); }
    {int tlv7; tlv7 = (int)(& ps); }
    {int tlv8; tlv8 = (int)(& ps); }
    {int tlv9; tlv9 = (int)(& ps); }
    {int tlv10; tlv10 = (int)(& ps); }
    {char tlv21; tlv21 = (char)(& ps); }
    {int tlv23; tlv23 = (int)(& ps); }
    {int tlv28; tlv28 = (int)(& ps); }
    {int tlv27; tlv27 = (int)(& ps); }
    {void * tlv12; tlv12 = (void *)(& ps); }
    {cgc_size_t tlv11; tlv11 = (cgc_size_t)(& ps); }
    {char tlv32; tlv32 = (char)(& ps); }
    {int tlv34; tlv34 = (int)(& ps); }
    {int * tlv13; tlv13 = (int *)(& ps); }
    {char tlv37; tlv37 = (char)(& ps); }
    {int tlv39; tlv39 = (int)(& ps); }
    {char tlv41; tlv41 = (char)(& ps); }
    {int tlv43; tlv43 = (int)(& ps); }
    {int tlv47; tlv47 = (int)(& ps); }
    {int tlv46; tlv46 = (int)(& ps); }
    {void * tlv16; tlv16 = (void *)(& ps); }
    {cgc_size_t tlv15; tlv15 = (cgc_size_t)(& ps); }
    {char tlv51; tlv51 = (char)(& ps); }
    {int tlv17; tlv17 = (int)(& ps); }
    {int tlv54; tlv54 = (int)(& ps); }
    {int tlv53; tlv53 = (int)(& ps); }
    {void * tlv20; tlv20 = (void *)(& ps); }
    {cgc_size_t tlv19; tlv19 = (cgc_size_t)(& ps); }
    {char * tlv75; tlv75 = (char *)(& ps); }
    {char * tlv76; tlv76 = (char *)(& ps); }
    {char * tlv77; tlv77 = (char *)(& ps); }
    {void * tlv62; tlv62 = (void *)(& ps); }
    {cgc_size_t tlv61; tlv61 = (cgc_size_t)(& ps); }
    {void * tlv72; tlv72 = (void *)(& ps); }
    {cgc_size_t tlv71; tlv71 = (cgc_size_t)(& ps); }
    {char * tlv78; tlv78 = (char *)(& ps); }
    {char * tlv79; tlv79 = (char *)(& ps); }
}
void fix_ingred_planetParsers_5_27(){
fix_ingred_planetParsers_5_27_1();
}
void fix_ingred_planetParsers_5_29_6(){
int pe;
    bzero(&pe,sizeof(int));
    {char * temp; temp = (char *)(pe); }
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
    {char tlv21; tlv21 = (char)(pe); }
    {int tlv23; tlv23 = (int)(pe); }
    {int tlv28; tlv28 = (int)(pe); }
    {int tlv27; tlv27 = (int)(pe); }
    {void * tlv12; tlv12 = (void *)(pe); }
    {cgc_size_t tlv11; tlv11 = (cgc_size_t)(pe); }
    {char tlv32; tlv32 = (char)(pe); }
    {int tlv34; tlv34 = (int)(pe); }
    {int * tlv13; tlv13 = (int *)(pe); }
    {char tlv37; tlv37 = (char)(pe); }
    {int tlv39; tlv39 = (int)(pe); }
    {char tlv41; tlv41 = (char)(pe); }
    {int tlv43; tlv43 = (int)(pe); }
    {int tlv47; tlv47 = (int)(pe); }
    {int tlv46; tlv46 = (int)(pe); }
    {void * tlv16; tlv16 = (void *)(pe); }
    {cgc_size_t tlv15; tlv15 = (cgc_size_t)(pe); }
    {char tlv51; tlv51 = (char)(pe); }
    {int tlv17; tlv17 = (int)(pe); }
    {int tlv54; tlv54 = (int)(pe); }
    {int tlv53; tlv53 = (int)(pe); }
    {void * tlv20; tlv20 = (void *)(pe); }
    {cgc_size_t tlv19; tlv19 = (cgc_size_t)(pe); }
    {char * tlv75; tlv75 = (char *)(pe); }
    {char * tlv76; tlv76 = (char *)(pe); }
    {char * tlv77; tlv77 = (char *)(pe); }
    {void * tlv62; tlv62 = (void *)(pe); }
    {cgc_size_t tlv61; tlv61 = (cgc_size_t)(pe); }
    {void * tlv72; tlv72 = (void *)(pe); }
    {cgc_size_t tlv71; tlv71 = (cgc_size_t)(pe); }
    {char * tlv78; tlv78 = (char *)(pe); }
    {char * tlv79; tlv79 = (char *)(pe); }
}
void fix_ingred_planetParsers_5_29(){
fix_ingred_planetParsers_5_29_6();
}
void fix_ingred_planetParsers_5_35_6(){
int tlv7;
    bzero(&tlv7,sizeof(int));
    {char * temp; temp = (char *)(tlv7); }
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
    {char tlv21; tlv21 = (char)(tlv7); }
    {int tlv23; tlv23 = (int)(tlv7); }
    {int tlv28; tlv28 = (int)(tlv7); }
    {int tlv27; tlv27 = (int)(tlv7); }
    {void * tlv12; tlv12 = (void *)(tlv7); }
    {cgc_size_t tlv11; tlv11 = (cgc_size_t)(tlv7); }
    {char tlv32; tlv32 = (char)(tlv7); }
    {int tlv34; tlv34 = (int)(tlv7); }
    {int * tlv13; tlv13 = (int *)(tlv7); }
    {char tlv37; tlv37 = (char)(tlv7); }
    {int tlv39; tlv39 = (int)(tlv7); }
    {char tlv41; tlv41 = (char)(tlv7); }
    {int tlv43; tlv43 = (int)(tlv7); }
    {int tlv47; tlv47 = (int)(tlv7); }
    {int tlv46; tlv46 = (int)(tlv7); }
    {void * tlv16; tlv16 = (void *)(tlv7); }
    {cgc_size_t tlv15; tlv15 = (cgc_size_t)(tlv7); }
    {char tlv51; tlv51 = (char)(tlv7); }
    {int tlv17; tlv17 = (int)(tlv7); }
    {int tlv54; tlv54 = (int)(tlv7); }
    {int tlv53; tlv53 = (int)(tlv7); }
    {void * tlv20; tlv20 = (void *)(tlv7); }
    {cgc_size_t tlv19; tlv19 = (cgc_size_t)(tlv7); }
    {char * tlv75; tlv75 = (char *)(tlv7); }
    {char * tlv76; tlv76 = (char *)(tlv7); }
    {char * tlv77; tlv77 = (char *)(tlv7); }
    {void * tlv62; tlv62 = (void *)(tlv7); }
    {cgc_size_t tlv61; tlv61 = (cgc_size_t)(tlv7); }
    {void * tlv72; tlv72 = (void *)(tlv7); }
    {cgc_size_t tlv71; tlv71 = (cgc_size_t)(tlv7); }
    {char * tlv78; tlv78 = (char *)(tlv7); }
    {char * tlv79; tlv79 = (char *)(tlv7); }
}
void fix_ingred_planetParsers_5_35(){
fix_ingred_planetParsers_5_35_6();
}
void fix_ingred_planetParsers_5_37_1(){
    {char * temp; temp = (char *)('#'); }
    {int start; start = (int)('#'); }
    {int end; end = (int)('#'); }
    {int ps; ps = (int)('#'); }
    {int pe; pe = (int)('#'); }
    {int tlv8; tlv8 = (int)('#'); }
    {int tlv9; tlv9 = (int)('#'); }
    {int tlv10; tlv10 = (int)('#'); }
    {int tlv23; tlv23 = (int)('#'); }
    {int tlv28; tlv28 = (int)('#'); }
    {int tlv27; tlv27 = (int)('#'); }
    {void * tlv12; tlv12 = (void *)('#'); }
    {cgc_size_t tlv11; tlv11 = (cgc_size_t)('#'); }
    {char tlv32; tlv32 = (char)('#'); }
    {int tlv34; tlv34 = (int)('#'); }
    {int * tlv13; tlv13 = (int *)('#'); }
    {char tlv37; tlv37 = (char)('#'); }
    {int tlv39; tlv39 = (int)('#'); }
    {char tlv41; tlv41 = (char)('#'); }
    {int tlv43; tlv43 = (int)('#'); }
    {int tlv47; tlv47 = (int)('#'); }
    {int tlv46; tlv46 = (int)('#'); }
    {void * tlv16; tlv16 = (void *)('#'); }
    {cgc_size_t tlv15; tlv15 = (cgc_size_t)('#'); }
    {char tlv51; tlv51 = (char)('#'); }
    {int tlv17; tlv17 = (int)('#'); }
    {int tlv54; tlv54 = (int)('#'); }
    {int tlv53; tlv53 = (int)('#'); }
    {void * tlv20; tlv20 = (void *)('#'); }
    {cgc_size_t tlv19; tlv19 = (cgc_size_t)('#'); }
    {char * tlv75; tlv75 = (char *)('#'); }
    {char * tlv76; tlv76 = (char *)('#'); }
    {char * tlv77; tlv77 = (char *)('#'); }
    {void * tlv62; tlv62 = (void *)('#'); }
    {cgc_size_t tlv61; tlv61 = (cgc_size_t)('#'); }
    {void * tlv72; tlv72 = (void *)('#'); }
    {cgc_size_t tlv71; tlv71 = (cgc_size_t)('#'); }
    {char * tlv78; tlv78 = (char *)('#'); }
    {char * tlv79; tlv79 = (char *)('#'); }
}
void fix_ingred_planetParsers_5_37(){
fix_ingred_planetParsers_5_37_1();
}
void fix_ingred_planetParsers_5_48_6(){
int tlv9;
    bzero(&tlv9,sizeof(int));
    {char * temp; temp = (char *)(tlv9); }
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
    {char tlv21; tlv21 = (char)(tlv9); }
    {int tlv23; tlv23 = (int)(tlv9); }
    {int tlv28; tlv28 = (int)(tlv9); }
    {int tlv27; tlv27 = (int)(tlv9); }
    {void * tlv12; tlv12 = (void *)(tlv9); }
    {cgc_size_t tlv11; tlv11 = (cgc_size_t)(tlv9); }
    {char tlv32; tlv32 = (char)(tlv9); }
    {int tlv34; tlv34 = (int)(tlv9); }
    {int * tlv13; tlv13 = (int *)(tlv9); }
    {char tlv37; tlv37 = (char)(tlv9); }
    {int tlv39; tlv39 = (int)(tlv9); }
    {char tlv41; tlv41 = (char)(tlv9); }
    {int tlv43; tlv43 = (int)(tlv9); }
    {int tlv47; tlv47 = (int)(tlv9); }
    {int tlv46; tlv46 = (int)(tlv9); }
    {void * tlv16; tlv16 = (void *)(tlv9); }
    {cgc_size_t tlv15; tlv15 = (cgc_size_t)(tlv9); }
    {char tlv51; tlv51 = (char)(tlv9); }
    {int tlv17; tlv17 = (int)(tlv9); }
    {int tlv54; tlv54 = (int)(tlv9); }
    {int tlv53; tlv53 = (int)(tlv9); }
    {void * tlv20; tlv20 = (void *)(tlv9); }
    {cgc_size_t tlv19; tlv19 = (cgc_size_t)(tlv9); }
    {char * tlv75; tlv75 = (char *)(tlv9); }
    {char * tlv76; tlv76 = (char *)(tlv9); }
    {char * tlv77; tlv77 = (char *)(tlv9); }
    {void * tlv62; tlv62 = (void *)(tlv9); }
    {cgc_size_t tlv61; tlv61 = (cgc_size_t)(tlv9); }
    {void * tlv72; tlv72 = (void *)(tlv9); }
    {cgc_size_t tlv71; tlv71 = (cgc_size_t)(tlv9); }
    {char * tlv78; tlv78 = (char *)(tlv9); }
    {char * tlv79; tlv79 = (char *)(tlv9); }
}
void fix_ingred_planetParsers_5_48(){
fix_ingred_planetParsers_5_48_6();
}
void fix_ingred_planetParsers_5_50_1(){
char tlv79_ref;
    bzero(&tlv79_ref,1*sizeof(char));
char * tlv79 = &tlv79_ref;
    {char * temp; temp = (char *)(cgc_strlen ( tlv79 ) + 1); }
    {int start; start = (int)(cgc_strlen ( tlv79 ) + 1); }
    {int end; end = (int)(cgc_strlen ( tlv79 ) + 1); }
    {int ps; ps = (int)(cgc_strlen ( tlv79 ) + 1); }
    {int pe; pe = (int)(cgc_strlen ( tlv79 ) + 1); }
    {int tlv1; tlv1 = (int)(cgc_strlen ( tlv79 ) + 1); }
    {int tlv2; tlv2 = (int)(cgc_strlen ( tlv79 ) + 1); }
    {int tlv3; tlv3 = (int)(cgc_strlen ( tlv79 ) + 1); }
    {int tlv4; tlv4 = (int)(cgc_strlen ( tlv79 ) + 1); }
    {int tlv5; tlv5 = (int)(cgc_strlen ( tlv79 ) + 1); }
    {int tlv6; tlv6 = (int)(cgc_strlen ( tlv79 ) + 1); }
    {int tlv7; tlv7 = (int)(cgc_strlen ( tlv79 ) + 1); }
    {int tlv8; tlv8 = (int)(cgc_strlen ( tlv79 ) + 1); }
    {int tlv9; tlv9 = (int)(cgc_strlen ( tlv79 ) + 1); }
    {int tlv10; tlv10 = (int)(cgc_strlen ( tlv79 ) + 1); }
    {char tlv21; tlv21 = (char)(cgc_strlen ( tlv79 ) + 1); }
    {int tlv23; tlv23 = (int)(cgc_strlen ( tlv79 ) + 1); }
    {int tlv28; tlv28 = (int)(cgc_strlen ( tlv79 ) + 1); }
    {int tlv27; tlv27 = (int)(cgc_strlen ( tlv79 ) + 1); }
    {void * tlv12; tlv12 = (void *)(cgc_strlen ( tlv79 ) + 1); }
    {cgc_size_t tlv11; tlv11 = (cgc_size_t)(cgc_strlen ( tlv79 ) + 1); }
    {char tlv32; tlv32 = (char)(cgc_strlen ( tlv79 ) + 1); }
    {int tlv34; tlv34 = (int)(cgc_strlen ( tlv79 ) + 1); }
    {int * tlv13; tlv13 = (int *)(cgc_strlen ( tlv79 ) + 1); }
    {char tlv37; tlv37 = (char)(cgc_strlen ( tlv79 ) + 1); }
    {int tlv39; tlv39 = (int)(cgc_strlen ( tlv79 ) + 1); }
    {char tlv41; tlv41 = (char)(cgc_strlen ( tlv79 ) + 1); }
    {int tlv43; tlv43 = (int)(cgc_strlen ( tlv79 ) + 1); }
    {int tlv47; tlv47 = (int)(cgc_strlen ( tlv79 ) + 1); }
    {int tlv46; tlv46 = (int)(cgc_strlen ( tlv79 ) + 1); }
    {void * tlv16; tlv16 = (void *)(cgc_strlen ( tlv79 ) + 1); }
    {cgc_size_t tlv15; tlv15 = (cgc_size_t)(cgc_strlen ( tlv79 ) + 1); }
    {char tlv51; tlv51 = (char)(cgc_strlen ( tlv79 ) + 1); }
    {int tlv17; tlv17 = (int)(cgc_strlen ( tlv79 ) + 1); }
    {int tlv54; tlv54 = (int)(cgc_strlen ( tlv79 ) + 1); }
    {int tlv53; tlv53 = (int)(cgc_strlen ( tlv79 ) + 1); }
    {void * tlv20; tlv20 = (void *)(cgc_strlen ( tlv79 ) + 1); }
    {cgc_size_t tlv19; tlv19 = (cgc_size_t)(cgc_strlen ( tlv79 ) + 1); }
    {char * tlv75; tlv75 = (char *)(cgc_strlen ( tlv79 ) + 1); }
    {char * tlv76; tlv76 = (char *)(cgc_strlen ( tlv79 ) + 1); }
    {char * tlv77; tlv77 = (char *)(cgc_strlen ( tlv79 ) + 1); }
    {void * tlv62; tlv62 = (void *)(cgc_strlen ( tlv79 ) + 1); }
    {cgc_size_t tlv61; tlv61 = (cgc_size_t)(cgc_strlen ( tlv79 ) + 1); }
    {void * tlv72; tlv72 = (void *)(cgc_strlen ( tlv79 ) + 1); }
    {cgc_size_t tlv71; tlv71 = (cgc_size_t)(cgc_strlen ( tlv79 ) + 1); }
    {char * tlv78; tlv78 = (char *)(cgc_strlen ( tlv79 ) + 1); }
}
void fix_ingred_planetParsers_5_50(){
fix_ingred_planetParsers_5_50_1();
}
void fix_ingred_planetParsers_5_52_1(){
char tlv76_ref;
    bzero(&tlv76_ref,1*sizeof(char));
char * tlv76 = &tlv76_ref;
    {char * temp; temp = (char *)(cgc_strlen ( tlv76 ) + 1); }
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
    {char tlv21; tlv21 = (char)(cgc_strlen ( tlv76 ) + 1); }
    {int tlv23; tlv23 = (int)(cgc_strlen ( tlv76 ) + 1); }
    {int tlv28; tlv28 = (int)(cgc_strlen ( tlv76 ) + 1); }
    {int tlv27; tlv27 = (int)(cgc_strlen ( tlv76 ) + 1); }
    {void * tlv12; tlv12 = (void *)(cgc_strlen ( tlv76 ) + 1); }
    {cgc_size_t tlv11; tlv11 = (cgc_size_t)(cgc_strlen ( tlv76 ) + 1); }
    {char tlv32; tlv32 = (char)(cgc_strlen ( tlv76 ) + 1); }
    {int tlv34; tlv34 = (int)(cgc_strlen ( tlv76 ) + 1); }
    {int * tlv13; tlv13 = (int *)(cgc_strlen ( tlv76 ) + 1); }
    {char tlv37; tlv37 = (char)(cgc_strlen ( tlv76 ) + 1); }
    {int tlv39; tlv39 = (int)(cgc_strlen ( tlv76 ) + 1); }
    {char tlv41; tlv41 = (char)(cgc_strlen ( tlv76 ) + 1); }
    {int tlv43; tlv43 = (int)(cgc_strlen ( tlv76 ) + 1); }
    {int tlv47; tlv47 = (int)(cgc_strlen ( tlv76 ) + 1); }
    {int tlv46; tlv46 = (int)(cgc_strlen ( tlv76 ) + 1); }
    {void * tlv16; tlv16 = (void *)(cgc_strlen ( tlv76 ) + 1); }
    {cgc_size_t tlv15; tlv15 = (cgc_size_t)(cgc_strlen ( tlv76 ) + 1); }
    {char tlv51; tlv51 = (char)(cgc_strlen ( tlv76 ) + 1); }
    {int tlv17; tlv17 = (int)(cgc_strlen ( tlv76 ) + 1); }
    {int tlv54; tlv54 = (int)(cgc_strlen ( tlv76 ) + 1); }
    {int tlv53; tlv53 = (int)(cgc_strlen ( tlv76 ) + 1); }
    {void * tlv20; tlv20 = (void *)(cgc_strlen ( tlv76 ) + 1); }
    {cgc_size_t tlv19; tlv19 = (cgc_size_t)(cgc_strlen ( tlv76 ) + 1); }
    {char * tlv75; tlv75 = (char *)(cgc_strlen ( tlv76 ) + 1); }
    {char * tlv77; tlv77 = (char *)(cgc_strlen ( tlv76 ) + 1); }
    {void * tlv62; tlv62 = (void *)(cgc_strlen ( tlv76 ) + 1); }
    {cgc_size_t tlv61; tlv61 = (cgc_size_t)(cgc_strlen ( tlv76 ) + 1); }
    {void * tlv72; tlv72 = (void *)(cgc_strlen ( tlv76 ) + 1); }
    {cgc_size_t tlv71; tlv71 = (cgc_size_t)(cgc_strlen ( tlv76 ) + 1); }
    {char * tlv78; tlv78 = (char *)(cgc_strlen ( tlv76 ) + 1); }
    {char * tlv79; tlv79 = (char *)(cgc_strlen ( tlv76 ) + 1); }
}
void fix_ingred_planetParsers_5_52(){
fix_ingred_planetParsers_5_52_1();
}
void fix_ingred_planetParsers_5_57_1(){
int ps;
    bzero(&ps,sizeof(int));
    {char * temp; temp = (char *)(ps); }
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
    {char tlv21; tlv21 = (char)(ps); }
    {int tlv23; tlv23 = (int)(ps); }
    {int tlv28; tlv28 = (int)(ps); }
    {int tlv27; tlv27 = (int)(ps); }
    {void * tlv12; tlv12 = (void *)(ps); }
    {cgc_size_t tlv11; tlv11 = (cgc_size_t)(ps); }
    {char tlv32; tlv32 = (char)(ps); }
    {int tlv34; tlv34 = (int)(ps); }
    {int * tlv13; tlv13 = (int *)(ps); }
    {char tlv37; tlv37 = (char)(ps); }
    {int tlv39; tlv39 = (int)(ps); }
    {char tlv41; tlv41 = (char)(ps); }
    {int tlv43; tlv43 = (int)(ps); }
    {int tlv47; tlv47 = (int)(ps); }
    {int tlv46; tlv46 = (int)(ps); }
    {void * tlv16; tlv16 = (void *)(ps); }
    {cgc_size_t tlv15; tlv15 = (cgc_size_t)(ps); }
    {char tlv51; tlv51 = (char)(ps); }
    {int tlv17; tlv17 = (int)(ps); }
    {int tlv54; tlv54 = (int)(ps); }
    {int tlv53; tlv53 = (int)(ps); }
    {void * tlv20; tlv20 = (void *)(ps); }
    {cgc_size_t tlv19; tlv19 = (cgc_size_t)(ps); }
    {char * tlv75; tlv75 = (char *)(ps); }
    {char * tlv76; tlv76 = (char *)(ps); }
    {char * tlv77; tlv77 = (char *)(ps); }
    {void * tlv62; tlv62 = (void *)(ps); }
    {cgc_size_t tlv61; tlv61 = (cgc_size_t)(ps); }
    {void * tlv72; tlv72 = (void *)(ps); }
    {cgc_size_t tlv71; tlv71 = (cgc_size_t)(ps); }
    {char * tlv78; tlv78 = (char *)(ps); }
    {char * tlv79; tlv79 = (char *)(ps); }
}
void fix_ingred_planetParsers_5_57(){
fix_ingred_planetParsers_5_57_1();
}
void fix_ingred_planetParsers_5_62_1(){
char tlv77_ref;
    bzero(&tlv77_ref,1*sizeof(char));
char * tlv77 = &tlv77_ref;
    {char * temp; temp = (char *)(cgc_strlen ( tlv77 ) + 1); }
    {int start; start = (int)(cgc_strlen ( tlv77 ) + 1); }
    {int end; end = (int)(cgc_strlen ( tlv77 ) + 1); }
    {int ps; ps = (int)(cgc_strlen ( tlv77 ) + 1); }
    {int pe; pe = (int)(cgc_strlen ( tlv77 ) + 1); }
    {int tlv1; tlv1 = (int)(cgc_strlen ( tlv77 ) + 1); }
    {int tlv2; tlv2 = (int)(cgc_strlen ( tlv77 ) + 1); }
    {int tlv3; tlv3 = (int)(cgc_strlen ( tlv77 ) + 1); }
    {int tlv4; tlv4 = (int)(cgc_strlen ( tlv77 ) + 1); }
    {int tlv5; tlv5 = (int)(cgc_strlen ( tlv77 ) + 1); }
    {int tlv6; tlv6 = (int)(cgc_strlen ( tlv77 ) + 1); }
    {int tlv7; tlv7 = (int)(cgc_strlen ( tlv77 ) + 1); }
    {int tlv8; tlv8 = (int)(cgc_strlen ( tlv77 ) + 1); }
    {int tlv9; tlv9 = (int)(cgc_strlen ( tlv77 ) + 1); }
    {int tlv10; tlv10 = (int)(cgc_strlen ( tlv77 ) + 1); }
    {char tlv21; tlv21 = (char)(cgc_strlen ( tlv77 ) + 1); }
    {int tlv23; tlv23 = (int)(cgc_strlen ( tlv77 ) + 1); }
    {int tlv28; tlv28 = (int)(cgc_strlen ( tlv77 ) + 1); }
    {int tlv27; tlv27 = (int)(cgc_strlen ( tlv77 ) + 1); }
    {void * tlv12; tlv12 = (void *)(cgc_strlen ( tlv77 ) + 1); }
    {cgc_size_t tlv11; tlv11 = (cgc_size_t)(cgc_strlen ( tlv77 ) + 1); }
    {char tlv32; tlv32 = (char)(cgc_strlen ( tlv77 ) + 1); }
    {int tlv34; tlv34 = (int)(cgc_strlen ( tlv77 ) + 1); }
    {int * tlv13; tlv13 = (int *)(cgc_strlen ( tlv77 ) + 1); }
    {char tlv37; tlv37 = (char)(cgc_strlen ( tlv77 ) + 1); }
    {int tlv39; tlv39 = (int)(cgc_strlen ( tlv77 ) + 1); }
    {char tlv41; tlv41 = (char)(cgc_strlen ( tlv77 ) + 1); }
    {int tlv43; tlv43 = (int)(cgc_strlen ( tlv77 ) + 1); }
    {int tlv47; tlv47 = (int)(cgc_strlen ( tlv77 ) + 1); }
    {int tlv46; tlv46 = (int)(cgc_strlen ( tlv77 ) + 1); }
    {void * tlv16; tlv16 = (void *)(cgc_strlen ( tlv77 ) + 1); }
    {cgc_size_t tlv15; tlv15 = (cgc_size_t)(cgc_strlen ( tlv77 ) + 1); }
    {char tlv51; tlv51 = (char)(cgc_strlen ( tlv77 ) + 1); }
    {int tlv17; tlv17 = (int)(cgc_strlen ( tlv77 ) + 1); }
    {int tlv54; tlv54 = (int)(cgc_strlen ( tlv77 ) + 1); }
    {int tlv53; tlv53 = (int)(cgc_strlen ( tlv77 ) + 1); }
    {void * tlv20; tlv20 = (void *)(cgc_strlen ( tlv77 ) + 1); }
    {cgc_size_t tlv19; tlv19 = (cgc_size_t)(cgc_strlen ( tlv77 ) + 1); }
    {char * tlv75; tlv75 = (char *)(cgc_strlen ( tlv77 ) + 1); }
    {char * tlv76; tlv76 = (char *)(cgc_strlen ( tlv77 ) + 1); }
    {void * tlv62; tlv62 = (void *)(cgc_strlen ( tlv77 ) + 1); }
    {cgc_size_t tlv61; tlv61 = (cgc_size_t)(cgc_strlen ( tlv77 ) + 1); }
    {void * tlv72; tlv72 = (void *)(cgc_strlen ( tlv77 ) + 1); }
    {cgc_size_t tlv71; tlv71 = (cgc_size_t)(cgc_strlen ( tlv77 ) + 1); }
    {char * tlv78; tlv78 = (char *)(cgc_strlen ( tlv77 ) + 1); }
    {char * tlv79; tlv79 = (char *)(cgc_strlen ( tlv77 ) + 1); }
}
void fix_ingred_planetParsers_5_62(){
fix_ingred_planetParsers_5_62_1();
}
void fix_ingred_planetParsers_5(){
fix_ingred_planetParsers_5_0();
fix_ingred_planetParsers_5_2();
fix_ingred_planetParsers_5_5();
fix_ingred_planetParsers_5_6();
fix_ingred_planetParsers_5_10();
fix_ingred_planetParsers_5_12();
fix_ingred_planetParsers_5_13();
fix_ingred_planetParsers_5_15();
fix_ingred_planetParsers_5_17();
fix_ingred_planetParsers_5_18();
fix_ingred_planetParsers_5_20();
fix_ingred_planetParsers_5_21();
fix_ingred_planetParsers_5_25();
fix_ingred_planetParsers_5_27();
fix_ingred_planetParsers_5_29();
fix_ingred_planetParsers_5_35();
fix_ingred_planetParsers_5_37();
fix_ingred_planetParsers_5_48();
fix_ingred_planetParsers_5_50();
fix_ingred_planetParsers_5_52();
fix_ingred_planetParsers_5_57();
fix_ingred_planetParsers_5_62();
}
void fix_ingred_planetParsers_6_0_0(){
string str_ref;
    bzero(&str_ref,1*sizeof(string));
pstring str = &str_ref;
    {int ss; ss = (int)(NULL); }
    {int se; se = (int)(NULL); }
    {char tlv24; tlv24 = (char)(NULL); }
    {int tlv31; tlv31 = (int)(NULL); }
    {int tlv30; tlv30 = (int)(NULL); }
    {void * tlv14; tlv14 = (void *)(NULL); }
    {cgc_size_t tlv13; tlv13 = (cgc_size_t)(NULL); }
    {char tlv35; tlv35 = (char)(NULL); }
    {int tlv37; tlv37 = (int)(NULL); }
    {char tlv40; tlv40 = (char)(NULL); }
    {int tlv42; tlv42 = (int)(NULL); }
    {char tlv44; tlv44 = (char)(NULL); }
    {int tlv50; tlv50 = (int)(NULL); }
    {int tlv49; tlv49 = (int)(NULL); }
    {void * tlv18; tlv18 = (void *)(NULL); }
    {cgc_size_t tlv17; tlv17 = (cgc_size_t)(NULL); }
    {char tlv54; tlv54 = (char)(NULL); }
    {int tlv19; tlv19 = (int)(NULL); }
    {int tlv57; tlv57 = (int)(NULL); }
    {int tlv56; tlv56 = (int)(NULL); }
    {void * tlv22; tlv22 = (void *)(NULL); }
    {cgc_size_t tlv21; tlv21 = (cgc_size_t)(NULL); }
    {char * tlv82; tlv82 = (char *)(NULL); }
    {char * tlv83; tlv83 = (char *)(NULL); }
    {char * tlv84; tlv84 = (char *)(NULL); }
    {char * tlv85; tlv85 = (char *)(NULL); }
    {char * tlv86; tlv86 = (char *)(NULL); }
    {void * tlv65; tlv65 = (void *)(NULL); }
    {cgc_size_t tlv64; tlv64 = (cgc_size_t)(NULL); }
    {void * tlv67; tlv67 = (void *)(NULL); }
    {cgc_size_t tlv66; tlv66 = (cgc_size_t)(NULL); }
    {void * tlv77; tlv77 = (void *)(NULL); }
    {cgc_size_t tlv76; tlv76 = (cgc_size_t)(NULL); }
    {void * tlv79; tlv79 = (void *)(NULL); }
    {cgc_size_t tlv78; tlv78 = (cgc_size_t)(NULL); }
    {char * tlv87; tlv87 = (char *)(NULL); }
    {char * tlv88; tlv88 = (char *)(NULL); }
    {char * tlv89; tlv89 = (char *)(NULL); }
    {char * tlv90; tlv90 = (char *)(NULL); }
}
void fix_ingred_planetParsers_6_0_1(){
string str_ref;
    bzero(&str_ref,1*sizeof(string));
pstring str = &str_ref;
    {double speed; speed = (double)(- 1.0); }
}
void fix_ingred_planetParsers_6_0_4(){
string str_ref;
    bzero(&str_ref,1*sizeof(string));
pstring str = &str_ref;
    {int ss; ss = (int)(0); }
    {int se; se = (int)(0); }
    {char tlv24; tlv24 = (char)(0); }
    {int tlv31; tlv31 = (int)(0); }
    {int tlv30; tlv30 = (int)(0); }
    {void * tlv14; tlv14 = (void *)(0); }
    {cgc_size_t tlv13; tlv13 = (cgc_size_t)(0); }
    {char tlv35; tlv35 = (char)(0); }
    {int tlv37; tlv37 = (int)(0); }
    {int tlv42; tlv42 = (int)(0); }
    {char tlv44; tlv44 = (char)(0); }
    {int tlv50; tlv50 = (int)(0); }
    {int tlv49; tlv49 = (int)(0); }
    {void * tlv18; tlv18 = (void *)(0); }
    {cgc_size_t tlv17; tlv17 = (cgc_size_t)(0); }
    {char tlv54; tlv54 = (char)(0); }
    {int tlv19; tlv19 = (int)(0); }
    {int tlv57; tlv57 = (int)(0); }
    {int tlv56; tlv56 = (int)(0); }
    {void * tlv22; tlv22 = (void *)(0); }
    {cgc_size_t tlv21; tlv21 = (cgc_size_t)(0); }
    {char * tlv82; tlv82 = (char *)(0); }
    {char * tlv83; tlv83 = (char *)(0); }
    {char * tlv84; tlv84 = (char *)(0); }
    {char * tlv85; tlv85 = (char *)(0); }
    {char * tlv86; tlv86 = (char *)(0); }
    {void * tlv65; tlv65 = (void *)(0); }
    {cgc_size_t tlv64; tlv64 = (cgc_size_t)(0); }
    {void * tlv67; tlv67 = (void *)(0); }
    {cgc_size_t tlv66; tlv66 = (cgc_size_t)(0); }
    {void * tlv77; tlv77 = (void *)(0); }
    {cgc_size_t tlv76; tlv76 = (cgc_size_t)(0); }
    {void * tlv79; tlv79 = (void *)(0); }
    {cgc_size_t tlv78; tlv78 = (cgc_size_t)(0); }
    {char * tlv87; tlv87 = (char *)(0); }
    {char * tlv88; tlv88 = (char *)(0); }
    {char * tlv89; tlv89 = (char *)(0); }
    {char * tlv90; tlv90 = (char *)(0); }
}
void fix_ingred_planetParsers_6_0_6(){
string str_ref;
    bzero(&str_ref,1*sizeof(string));
pstring str = &str_ref;
    {char * temp; temp = (char *)(str -> index); }
    {int ss; ss = (int)(str -> index); }
    {int se; se = (int)(str -> index); }
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
    {char tlv24; tlv24 = (char)(str -> index); }
    {int tlv26; tlv26 = (int)(str -> index); }
    {int tlv31; tlv31 = (int)(str -> index); }
    {int tlv30; tlv30 = (int)(str -> index); }
    {void * tlv12; tlv12 = (void *)(str -> index); }
    {cgc_size_t tlv11; tlv11 = (cgc_size_t)(str -> index); }
    {void * tlv14; tlv14 = (void *)(str -> index); }
    {cgc_size_t tlv13; tlv13 = (cgc_size_t)(str -> index); }
    {char tlv35; tlv35 = (char)(str -> index); }
    {int tlv37; tlv37 = (int)(str -> index); }
    {char tlv40; tlv40 = (char)(str -> index); }
    {int tlv42; tlv42 = (int)(str -> index); }
    {char tlv44; tlv44 = (char)(str -> index); }
    {int tlv46; tlv46 = (int)(str -> index); }
    {int tlv50; tlv50 = (int)(str -> index); }
    {int tlv49; tlv49 = (int)(str -> index); }
    {void * tlv16; tlv16 = (void *)(str -> index); }
    {cgc_size_t tlv15; tlv15 = (cgc_size_t)(str -> index); }
    {void * tlv18; tlv18 = (void *)(str -> index); }
    {cgc_size_t tlv17; tlv17 = (cgc_size_t)(str -> index); }
    {char tlv54; tlv54 = (char)(str -> index); }
    {int tlv19; tlv19 = (int)(str -> index); }
    {int tlv57; tlv57 = (int)(str -> index); }
    {int tlv56; tlv56 = (int)(str -> index); }
    {void * tlv22; tlv22 = (void *)(str -> index); }
    {cgc_size_t tlv21; tlv21 = (cgc_size_t)(str -> index); }
    {char * tlv82; tlv82 = (char *)(str -> index); }
    {char * tlv83; tlv83 = (char *)(str -> index); }
    {char * tlv84; tlv84 = (char *)(str -> index); }
    {char * tlv85; tlv85 = (char *)(str -> index); }
    {char * tlv86; tlv86 = (char *)(str -> index); }
    {void * tlv65; tlv65 = (void *)(str -> index); }
    {cgc_size_t tlv64; tlv64 = (cgc_size_t)(str -> index); }
    {void * tlv67; tlv67 = (void *)(str -> index); }
    {cgc_size_t tlv66; tlv66 = (cgc_size_t)(str -> index); }
    {void * tlv77; tlv77 = (void *)(str -> index); }
    {cgc_size_t tlv76; tlv76 = (cgc_size_t)(str -> index); }
    {void * tlv79; tlv79 = (void *)(str -> index); }
    {cgc_size_t tlv78; tlv78 = (cgc_size_t)(str -> index); }
    {char * tlv87; tlv87 = (char *)(str -> index); }
    {char * tlv88; tlv88 = (char *)(str -> index); }
    {char * tlv89; tlv89 = (char *)(str -> index); }
    {char * tlv90; tlv90 = (char *)(str -> index); }
}
void fix_ingred_planetParsers_6_0(){
fix_ingred_planetParsers_6_0_0();
fix_ingred_planetParsers_6_0_1();
fix_ingred_planetParsers_6_0_4();
fix_ingred_planetParsers_6_0_6();
}
void fix_ingred_planetParsers_6_3_1(){
    {int ss; ss = (int)('{'); }
    {int se; se = (int)('{'); }
    {char tlv24; tlv24 = (char)('{'); }
    {int tlv31; tlv31 = (int)('{'); }
    {int tlv30; tlv30 = (int)('{'); }
    {void * tlv14; tlv14 = (void *)('{'); }
    {cgc_size_t tlv13; tlv13 = (cgc_size_t)('{'); }
    {char tlv35; tlv35 = (char)('{'); }
    {int tlv37; tlv37 = (int)('{'); }
    {char tlv40; tlv40 = (char)('{'); }
    {int tlv42; tlv42 = (int)('{'); }
    {char tlv44; tlv44 = (char)('{'); }
    {int tlv50; tlv50 = (int)('{'); }
    {int tlv49; tlv49 = (int)('{'); }
    {void * tlv18; tlv18 = (void *)('{'); }
    {cgc_size_t tlv17; tlv17 = (cgc_size_t)('{'); }
    {char tlv54; tlv54 = (char)('{'); }
    {int tlv19; tlv19 = (int)('{'); }
    {int tlv57; tlv57 = (int)('{'); }
    {int tlv56; tlv56 = (int)('{'); }
    {void * tlv22; tlv22 = (void *)('{'); }
    {cgc_size_t tlv21; tlv21 = (cgc_size_t)('{'); }
    {char * tlv82; tlv82 = (char *)('{'); }
    {char * tlv83; tlv83 = (char *)('{'); }
    {char * tlv84; tlv84 = (char *)('{'); }
    {char * tlv85; tlv85 = (char *)('{'); }
    {char * tlv86; tlv86 = (char *)('{'); }
    {void * tlv65; tlv65 = (void *)('{'); }
    {cgc_size_t tlv64; tlv64 = (cgc_size_t)('{'); }
    {void * tlv67; tlv67 = (void *)('{'); }
    {cgc_size_t tlv66; tlv66 = (cgc_size_t)('{'); }
    {void * tlv77; tlv77 = (void *)('{'); }
    {cgc_size_t tlv76; tlv76 = (cgc_size_t)('{'); }
    {void * tlv79; tlv79 = (void *)('{'); }
    {cgc_size_t tlv78; tlv78 = (cgc_size_t)('{'); }
    {char * tlv87; tlv87 = (char *)('{'); }
    {char * tlv88; tlv88 = (char *)('{'); }
    {char * tlv89; tlv89 = (char *)('{'); }
    {char * tlv90; tlv90 = (char *)('{'); }
}
void fix_ingred_planetParsers_6_3(){
fix_ingred_planetParsers_6_3_1();
}
void fix_ingred_planetParsers_6_6_1(){
    {int ss; ss = (int)(1); }
    {int se; se = (int)(1); }
    {char tlv24; tlv24 = (char)(1); }
    {int tlv26; tlv26 = (int)(1); }
    {int tlv31; tlv31 = (int)(1); }
    {int tlv30; tlv30 = (int)(1); }
    {void * tlv14; tlv14 = (void *)(1); }
    {cgc_size_t tlv13; tlv13 = (cgc_size_t)(1); }
    {char tlv35; tlv35 = (char)(1); }
    {int tlv37; tlv37 = (int)(1); }
    {int tlv42; tlv42 = (int)(1); }
    {char tlv44; tlv44 = (char)(1); }
    {int tlv50; tlv50 = (int)(1); }
    {int tlv49; tlv49 = (int)(1); }
    {void * tlv18; tlv18 = (void *)(1); }
    {cgc_size_t tlv17; tlv17 = (cgc_size_t)(1); }
    {char tlv54; tlv54 = (char)(1); }
    {int tlv19; tlv19 = (int)(1); }
    {int tlv57; tlv57 = (int)(1); }
    {int tlv56; tlv56 = (int)(1); }
    {void * tlv22; tlv22 = (void *)(1); }
    {cgc_size_t tlv21; tlv21 = (cgc_size_t)(1); }
    {char * tlv82; tlv82 = (char *)(1); }
    {char * tlv83; tlv83 = (char *)(1); }
    {char * tlv84; tlv84 = (char *)(1); }
    {char * tlv85; tlv85 = (char *)(1); }
    {char * tlv86; tlv86 = (char *)(1); }
    {void * tlv65; tlv65 = (void *)(1); }
    {cgc_size_t tlv64; tlv64 = (cgc_size_t)(1); }
    {void * tlv67; tlv67 = (void *)(1); }
    {cgc_size_t tlv66; tlv66 = (cgc_size_t)(1); }
    {void * tlv77; tlv77 = (void *)(1); }
    {cgc_size_t tlv76; tlv76 = (cgc_size_t)(1); }
    {void * tlv79; tlv79 = (void *)(1); }
    {cgc_size_t tlv78; tlv78 = (cgc_size_t)(1); }
    {char * tlv87; tlv87 = (char *)(1); }
    {char * tlv88; tlv88 = (char *)(1); }
    {char * tlv89; tlv89 = (char *)(1); }
    {char * tlv90; tlv90 = (char *)(1); }
}
void fix_ingred_planetParsers_6_6(){
fix_ingred_planetParsers_6_6_1();
}
void fix_ingred_planetParsers_6_7_6(){
int tlv2;
    bzero(&tlv2,sizeof(int));
    {int ss; ss = (int)(tlv2); }
    {int se; se = (int)(tlv2); }
    {char tlv24; tlv24 = (char)(tlv2); }
    {int tlv26; tlv26 = (int)(tlv2); }
    {int tlv31; tlv31 = (int)(tlv2); }
    {int tlv30; tlv30 = (int)(tlv2); }
    {void * tlv14; tlv14 = (void *)(tlv2); }
    {cgc_size_t tlv13; tlv13 = (cgc_size_t)(tlv2); }
    {char tlv35; tlv35 = (char)(tlv2); }
    {int tlv37; tlv37 = (int)(tlv2); }
    {int tlv42; tlv42 = (int)(tlv2); }
    {char tlv44; tlv44 = (char)(tlv2); }
    {int tlv50; tlv50 = (int)(tlv2); }
    {int tlv49; tlv49 = (int)(tlv2); }
    {void * tlv18; tlv18 = (void *)(tlv2); }
    {cgc_size_t tlv17; tlv17 = (cgc_size_t)(tlv2); }
    {char tlv54; tlv54 = (char)(tlv2); }
    {int tlv19; tlv19 = (int)(tlv2); }
    {int tlv57; tlv57 = (int)(tlv2); }
    {int tlv56; tlv56 = (int)(tlv2); }
    {void * tlv22; tlv22 = (void *)(tlv2); }
    {cgc_size_t tlv21; tlv21 = (cgc_size_t)(tlv2); }
    {char * tlv82; tlv82 = (char *)(tlv2); }
    {char * tlv83; tlv83 = (char *)(tlv2); }
    {char * tlv84; tlv84 = (char *)(tlv2); }
    {char * tlv85; tlv85 = (char *)(tlv2); }
    {char * tlv86; tlv86 = (char *)(tlv2); }
    {void * tlv65; tlv65 = (void *)(tlv2); }
    {cgc_size_t tlv64; tlv64 = (cgc_size_t)(tlv2); }
    {void * tlv67; tlv67 = (void *)(tlv2); }
    {cgc_size_t tlv66; tlv66 = (cgc_size_t)(tlv2); }
    {void * tlv77; tlv77 = (void *)(tlv2); }
    {cgc_size_t tlv76; tlv76 = (cgc_size_t)(tlv2); }
    {void * tlv79; tlv79 = (void *)(tlv2); }
    {cgc_size_t tlv78; tlv78 = (cgc_size_t)(tlv2); }
    {char * tlv87; tlv87 = (char *)(tlv2); }
    {char * tlv88; tlv88 = (char *)(tlv2); }
    {char * tlv89; tlv89 = (char *)(tlv2); }
    {char * tlv90; tlv90 = (char *)(tlv2); }
}
void fix_ingred_planetParsers_6_7_7(){
int tlv2;
    bzero(&tlv2,sizeof(int));
    {int ss; ss = (int)(- 1); }
    {int se; se = (int)(- 1); }
    {char tlv24; tlv24 = (char)(- 1); }
    {int tlv31; tlv31 = (int)(- 1); }
    {int tlv30; tlv30 = (int)(- 1); }
    {void * tlv14; tlv14 = (void *)(- 1); }
    {cgc_size_t tlv13; tlv13 = (cgc_size_t)(- 1); }
    {char tlv35; tlv35 = (char)(- 1); }
    {int tlv37; tlv37 = (int)(- 1); }
    {char tlv40; tlv40 = (char)(- 1); }
    {int tlv42; tlv42 = (int)(- 1); }
    {char tlv44; tlv44 = (char)(- 1); }
    {int tlv50; tlv50 = (int)(- 1); }
    {int tlv49; tlv49 = (int)(- 1); }
    {void * tlv18; tlv18 = (void *)(- 1); }
    {cgc_size_t tlv17; tlv17 = (cgc_size_t)(- 1); }
    {char tlv54; tlv54 = (char)(- 1); }
    {int tlv19; tlv19 = (int)(- 1); }
    {int tlv57; tlv57 = (int)(- 1); }
    {int tlv56; tlv56 = (int)(- 1); }
    {void * tlv22; tlv22 = (void *)(- 1); }
    {cgc_size_t tlv21; tlv21 = (cgc_size_t)(- 1); }
    {char * tlv82; tlv82 = (char *)(- 1); }
    {char * tlv83; tlv83 = (char *)(- 1); }
    {char * tlv84; tlv84 = (char *)(- 1); }
    {char * tlv85; tlv85 = (char *)(- 1); }
    {char * tlv86; tlv86 = (char *)(- 1); }
    {void * tlv65; tlv65 = (void *)(- 1); }
    {cgc_size_t tlv64; tlv64 = (cgc_size_t)(- 1); }
    {void * tlv67; tlv67 = (void *)(- 1); }
    {cgc_size_t tlv66; tlv66 = (cgc_size_t)(- 1); }
    {void * tlv77; tlv77 = (void *)(- 1); }
    {cgc_size_t tlv76; tlv76 = (cgc_size_t)(- 1); }
    {void * tlv79; tlv79 = (void *)(- 1); }
    {cgc_size_t tlv78; tlv78 = (cgc_size_t)(- 1); }
    {char * tlv87; tlv87 = (char *)(- 1); }
    {char * tlv88; tlv88 = (char *)(- 1); }
    {char * tlv89; tlv89 = (char *)(- 1); }
    {char * tlv90; tlv90 = (char *)(- 1); }
}
void fix_ingred_planetParsers_6_7(){
fix_ingred_planetParsers_6_7_6();
fix_ingred_planetParsers_6_7_7();
}
void fix_ingred_planetParsers_6_13_1(){
int start;
    bzero(&start,sizeof(int));
int end;
    bzero(&end,sizeof(int));
    {int ss; ss = (int)(start); }
    {int se; se = (int)(start); }
    {char tlv24; tlv24 = (char)(start); }
    {int tlv26; tlv26 = (int)(start); }
    {int tlv31; tlv31 = (int)(start); }
    {int tlv30; tlv30 = (int)(start); }
    {void * tlv14; tlv14 = (void *)(start); }
    {cgc_size_t tlv13; tlv13 = (cgc_size_t)(start); }
    {char tlv35; tlv35 = (char)(start); }
    {int tlv37; tlv37 = (int)(start); }
    {char tlv40; tlv40 = (char)(start); }
    {int tlv42; tlv42 = (int)(start); }
    {char tlv44; tlv44 = (char)(start); }
    {int tlv50; tlv50 = (int)(start); }
    {int tlv49; tlv49 = (int)(start); }
    {void * tlv18; tlv18 = (void *)(start); }
    {cgc_size_t tlv17; tlv17 = (cgc_size_t)(start); }
    {char tlv54; tlv54 = (char)(start); }
    {int tlv19; tlv19 = (int)(start); }
    {int tlv57; tlv57 = (int)(start); }
    {int tlv56; tlv56 = (int)(start); }
    {void * tlv22; tlv22 = (void *)(start); }
    {cgc_size_t tlv21; tlv21 = (cgc_size_t)(start); }
    {char * tlv82; tlv82 = (char *)(start); }
    {char * tlv83; tlv83 = (char *)(start); }
    {char * tlv84; tlv84 = (char *)(start); }
    {char * tlv85; tlv85 = (char *)(start); }
    {char * tlv86; tlv86 = (char *)(start); }
    {void * tlv65; tlv65 = (void *)(start); }
    {cgc_size_t tlv64; tlv64 = (cgc_size_t)(start); }
    {void * tlv67; tlv67 = (void *)(start); }
    {cgc_size_t tlv66; tlv66 = (cgc_size_t)(start); }
    {void * tlv77; tlv77 = (void *)(start); }
    {cgc_size_t tlv76; tlv76 = (cgc_size_t)(start); }
    {void * tlv79; tlv79 = (void *)(start); }
    {cgc_size_t tlv78; tlv78 = (cgc_size_t)(start); }
    {char * tlv87; tlv87 = (char *)(start); }
    {char * tlv88; tlv88 = (char *)(start); }
    {char * tlv89; tlv89 = (char *)(start); }
    {char * tlv90; tlv90 = (char *)(start); }
}
void fix_ingred_planetParsers_6_13_2(){
int start;
    bzero(&start,sizeof(int));
int end;
    bzero(&end,sizeof(int));
    {int ss; ss = (int)(end); }
    {int se; se = (int)(end); }
    {char tlv24; tlv24 = (char)(end); }
    {int tlv26; tlv26 = (int)(end); }
    {int tlv31; tlv31 = (int)(end); }
    {int tlv30; tlv30 = (int)(end); }
    {void * tlv14; tlv14 = (void *)(end); }
    {cgc_size_t tlv13; tlv13 = (cgc_size_t)(end); }
    {char tlv35; tlv35 = (char)(end); }
    {int tlv37; tlv37 = (int)(end); }
    {char tlv40; tlv40 = (char)(end); }
    {int tlv42; tlv42 = (int)(end); }
    {char tlv44; tlv44 = (char)(end); }
    {int tlv50; tlv50 = (int)(end); }
    {int tlv49; tlv49 = (int)(end); }
    {void * tlv18; tlv18 = (void *)(end); }
    {cgc_size_t tlv17; tlv17 = (cgc_size_t)(end); }
    {char tlv54; tlv54 = (char)(end); }
    {int tlv19; tlv19 = (int)(end); }
    {int tlv57; tlv57 = (int)(end); }
    {int tlv56; tlv56 = (int)(end); }
    {void * tlv22; tlv22 = (void *)(end); }
    {cgc_size_t tlv21; tlv21 = (cgc_size_t)(end); }
    {char * tlv82; tlv82 = (char *)(end); }
    {char * tlv83; tlv83 = (char *)(end); }
    {char * tlv84; tlv84 = (char *)(end); }
    {char * tlv85; tlv85 = (char *)(end); }
    {char * tlv86; tlv86 = (char *)(end); }
    {void * tlv65; tlv65 = (void *)(end); }
    {cgc_size_t tlv64; tlv64 = (cgc_size_t)(end); }
    {void * tlv67; tlv67 = (void *)(end); }
    {cgc_size_t tlv66; tlv66 = (cgc_size_t)(end); }
    {void * tlv77; tlv77 = (void *)(end); }
    {cgc_size_t tlv76; tlv76 = (cgc_size_t)(end); }
    {void * tlv79; tlv79 = (void *)(end); }
    {cgc_size_t tlv78; tlv78 = (cgc_size_t)(end); }
    {char * tlv87; tlv87 = (char *)(end); }
    {char * tlv88; tlv88 = (char *)(end); }
    {char * tlv89; tlv89 = (char *)(end); }
    {char * tlv90; tlv90 = (char *)(end); }
}
void fix_ingred_planetParsers_6_13(){
fix_ingred_planetParsers_6_13_1();
fix_ingred_planetParsers_6_13_2();
}
void fix_ingred_planetParsers_6_14_6(){
char temp_ref;
    bzero(&temp_ref,1*sizeof(char));
char * temp = &temp_ref;
    {int ss; ss = (int)(temp); }
    {int se; se = (int)(temp); }
    {char tlv24; tlv24 = (char)(temp); }
    {int tlv26; tlv26 = (int)(temp); }
    {int tlv31; tlv31 = (int)(temp); }
    {int tlv30; tlv30 = (int)(temp); }
    {void * tlv14; tlv14 = (void *)(temp); }
    {cgc_size_t tlv13; tlv13 = (cgc_size_t)(temp); }
    {char tlv35; tlv35 = (char)(temp); }
    {int tlv37; tlv37 = (int)(temp); }
    {char tlv40; tlv40 = (char)(temp); }
    {int tlv42; tlv42 = (int)(temp); }
    {char tlv44; tlv44 = (char)(temp); }
    {int tlv50; tlv50 = (int)(temp); }
    {int tlv49; tlv49 = (int)(temp); }
    {void * tlv18; tlv18 = (void *)(temp); }
    {cgc_size_t tlv17; tlv17 = (cgc_size_t)(temp); }
    {char tlv54; tlv54 = (char)(temp); }
    {int tlv19; tlv19 = (int)(temp); }
    {int tlv57; tlv57 = (int)(temp); }
    {int tlv56; tlv56 = (int)(temp); }
    {void * tlv22; tlv22 = (void *)(temp); }
    {cgc_size_t tlv21; tlv21 = (cgc_size_t)(temp); }
    {char * tlv82; tlv82 = (char *)(temp); }
    {char * tlv83; tlv83 = (char *)(temp); }
    {char * tlv84; tlv84 = (char *)(temp); }
    {char * tlv85; tlv85 = (char *)(temp); }
    {char * tlv86; tlv86 = (char *)(temp); }
    {void * tlv65; tlv65 = (void *)(temp); }
    {cgc_size_t tlv64; tlv64 = (cgc_size_t)(temp); }
    {void * tlv67; tlv67 = (void *)(temp); }
    {cgc_size_t tlv66; tlv66 = (cgc_size_t)(temp); }
    {void * tlv77; tlv77 = (void *)(temp); }
    {cgc_size_t tlv76; tlv76 = (cgc_size_t)(temp); }
    {void * tlv79; tlv79 = (void *)(temp); }
    {cgc_size_t tlv78; tlv78 = (cgc_size_t)(temp); }
    {char * tlv87; tlv87 = (char *)(temp); }
    {char * tlv88; tlv88 = (char *)(temp); }
    {char * tlv89; tlv89 = (char *)(temp); }
    {char * tlv90; tlv90 = (char *)(temp); }
}
void fix_ingred_planetParsers_6_14(){
fix_ingred_planetParsers_6_14_6();
}
void fix_ingred_planetParsers_6_16_7(){
int tlv3;
    bzero(&tlv3,sizeof(int));
    {int ss; ss = (int)(tlv3); }
    {int se; se = (int)(tlv3); }
    {char tlv24; tlv24 = (char)(tlv3); }
    {int tlv31; tlv31 = (int)(tlv3); }
    {int tlv30; tlv30 = (int)(tlv3); }
    {void * tlv14; tlv14 = (void *)(tlv3); }
    {cgc_size_t tlv13; tlv13 = (cgc_size_t)(tlv3); }
    {char tlv35; tlv35 = (char)(tlv3); }
    {int tlv37; tlv37 = (int)(tlv3); }
    {char tlv40; tlv40 = (char)(tlv3); }
    {int tlv42; tlv42 = (int)(tlv3); }
    {char tlv44; tlv44 = (char)(tlv3); }
    {int tlv50; tlv50 = (int)(tlv3); }
    {int tlv49; tlv49 = (int)(tlv3); }
    {void * tlv18; tlv18 = (void *)(tlv3); }
    {cgc_size_t tlv17; tlv17 = (cgc_size_t)(tlv3); }
    {char tlv54; tlv54 = (char)(tlv3); }
    {int tlv19; tlv19 = (int)(tlv3); }
    {int tlv57; tlv57 = (int)(tlv3); }
    {int tlv56; tlv56 = (int)(tlv3); }
    {void * tlv22; tlv22 = (void *)(tlv3); }
    {cgc_size_t tlv21; tlv21 = (cgc_size_t)(tlv3); }
    {char * tlv82; tlv82 = (char *)(tlv3); }
    {char * tlv83; tlv83 = (char *)(tlv3); }
    {char * tlv84; tlv84 = (char *)(tlv3); }
    {char * tlv85; tlv85 = (char *)(tlv3); }
    {char * tlv86; tlv86 = (char *)(tlv3); }
    {void * tlv65; tlv65 = (void *)(tlv3); }
    {cgc_size_t tlv64; tlv64 = (cgc_size_t)(tlv3); }
    {void * tlv67; tlv67 = (void *)(tlv3); }
    {cgc_size_t tlv66; tlv66 = (cgc_size_t)(tlv3); }
    {void * tlv77; tlv77 = (void *)(tlv3); }
    {cgc_size_t tlv76; tlv76 = (cgc_size_t)(tlv3); }
    {void * tlv79; tlv79 = (void *)(tlv3); }
    {cgc_size_t tlv78; tlv78 = (cgc_size_t)(tlv3); }
    {char * tlv87; tlv87 = (char *)(tlv3); }
    {char * tlv88; tlv88 = (char *)(tlv3); }
    {char * tlv89; tlv89 = (char *)(tlv3); }
    {char * tlv90; tlv90 = (char *)(tlv3); }
}
void fix_ingred_planetParsers_6_16(){
fix_ingred_planetParsers_6_16_7();
}
void fix_ingred_planetParsers_6_18_0(){
char temp_ref;
    bzero(&temp_ref,1*sizeof(char));
char * temp = &temp_ref;
    {int ss; ss = (int)(temp); }
    {int se; se = (int)(temp); }
    {char tlv24; tlv24 = (char)(temp); }
    {int tlv26; tlv26 = (int)(temp); }
    {int tlv31; tlv31 = (int)(temp); }
    {int tlv30; tlv30 = (int)(temp); }
    {void * tlv14; tlv14 = (void *)(temp); }
    {cgc_size_t tlv13; tlv13 = (cgc_size_t)(temp); }
    {char tlv35; tlv35 = (char)(temp); }
    {int tlv37; tlv37 = (int)(temp); }
    {char tlv40; tlv40 = (char)(temp); }
    {int tlv42; tlv42 = (int)(temp); }
    {char tlv44; tlv44 = (char)(temp); }
    {int tlv50; tlv50 = (int)(temp); }
    {int tlv49; tlv49 = (int)(temp); }
    {void * tlv18; tlv18 = (void *)(temp); }
    {cgc_size_t tlv17; tlv17 = (cgc_size_t)(temp); }
    {char tlv54; tlv54 = (char)(temp); }
    {int tlv19; tlv19 = (int)(temp); }
    {int tlv57; tlv57 = (int)(temp); }
    {int tlv56; tlv56 = (int)(temp); }
    {void * tlv22; tlv22 = (void *)(temp); }
    {cgc_size_t tlv21; tlv21 = (cgc_size_t)(temp); }
    {char * tlv82; tlv82 = (char *)(temp); }
    {char * tlv83; tlv83 = (char *)(temp); }
    {char * tlv84; tlv84 = (char *)(temp); }
    {char * tlv85; tlv85 = (char *)(temp); }
    {char * tlv86; tlv86 = (char *)(temp); }
    {void * tlv65; tlv65 = (void *)(temp); }
    {cgc_size_t tlv64; tlv64 = (cgc_size_t)(temp); }
    {void * tlv67; tlv67 = (void *)(temp); }
    {cgc_size_t tlv66; tlv66 = (cgc_size_t)(temp); }
    {void * tlv77; tlv77 = (void *)(temp); }
    {cgc_size_t tlv76; tlv76 = (cgc_size_t)(temp); }
    {void * tlv79; tlv79 = (void *)(temp); }
    {cgc_size_t tlv78; tlv78 = (cgc_size_t)(temp); }
    {char * tlv87; tlv87 = (char *)(temp); }
    {char * tlv88; tlv88 = (char *)(temp); }
    {char * tlv89; tlv89 = (char *)(temp); }
    {char * tlv90; tlv90 = (char *)(temp); }
}
void fix_ingred_planetParsers_6_18(){
fix_ingred_planetParsers_6_18_0();
}
void fix_ingred_planetParsers_6_19_1(){
char tlv87_ref;
    bzero(&tlv87_ref,1*sizeof(char));
char * tlv87 = &tlv87_ref;
    {char * temp; temp = (char *)(cgc_strlen ( tlv87 )); }
    {int ss; ss = (int)(cgc_strlen ( tlv87 )); }
    {int se; se = (int)(cgc_strlen ( tlv87 )); }
    {int tlv1; tlv1 = (int)(cgc_strlen ( tlv87 )); }
    {int tlv2; tlv2 = (int)(cgc_strlen ( tlv87 )); }
    {int tlv3; tlv3 = (int)(cgc_strlen ( tlv87 )); }
    {int tlv4; tlv4 = (int)(cgc_strlen ( tlv87 )); }
    {int tlv5; tlv5 = (int)(cgc_strlen ( tlv87 )); }
    {int tlv6; tlv6 = (int)(cgc_strlen ( tlv87 )); }
    {int tlv7; tlv7 = (int)(cgc_strlen ( tlv87 )); }
    {int tlv8; tlv8 = (int)(cgc_strlen ( tlv87 )); }
    {int tlv9; tlv9 = (int)(cgc_strlen ( tlv87 )); }
    {int tlv10; tlv10 = (int)(cgc_strlen ( tlv87 )); }
    {char tlv24; tlv24 = (char)(cgc_strlen ( tlv87 )); }
    {int tlv26; tlv26 = (int)(cgc_strlen ( tlv87 )); }
    {int tlv31; tlv31 = (int)(cgc_strlen ( tlv87 )); }
    {int tlv30; tlv30 = (int)(cgc_strlen ( tlv87 )); }
    {void * tlv12; tlv12 = (void *)(cgc_strlen ( tlv87 )); }
    {cgc_size_t tlv11; tlv11 = (cgc_size_t)(cgc_strlen ( tlv87 )); }
    {void * tlv14; tlv14 = (void *)(cgc_strlen ( tlv87 )); }
    {cgc_size_t tlv13; tlv13 = (cgc_size_t)(cgc_strlen ( tlv87 )); }
    {char tlv35; tlv35 = (char)(cgc_strlen ( tlv87 )); }
    {int tlv37; tlv37 = (int)(cgc_strlen ( tlv87 )); }
    {char tlv40; tlv40 = (char)(cgc_strlen ( tlv87 )); }
    {int tlv42; tlv42 = (int)(cgc_strlen ( tlv87 )); }
    {char tlv44; tlv44 = (char)(cgc_strlen ( tlv87 )); }
    {int tlv46; tlv46 = (int)(cgc_strlen ( tlv87 )); }
    {int tlv50; tlv50 = (int)(cgc_strlen ( tlv87 )); }
    {int tlv49; tlv49 = (int)(cgc_strlen ( tlv87 )); }
    {void * tlv16; tlv16 = (void *)(cgc_strlen ( tlv87 )); }
    {cgc_size_t tlv15; tlv15 = (cgc_size_t)(cgc_strlen ( tlv87 )); }
    {void * tlv18; tlv18 = (void *)(cgc_strlen ( tlv87 )); }
    {cgc_size_t tlv17; tlv17 = (cgc_size_t)(cgc_strlen ( tlv87 )); }
    {char tlv54; tlv54 = (char)(cgc_strlen ( tlv87 )); }
    {int tlv19; tlv19 = (int)(cgc_strlen ( tlv87 )); }
    {int tlv57; tlv57 = (int)(cgc_strlen ( tlv87 )); }
    {int tlv56; tlv56 = (int)(cgc_strlen ( tlv87 )); }
    {void * tlv22; tlv22 = (void *)(cgc_strlen ( tlv87 )); }
    {cgc_size_t tlv21; tlv21 = (cgc_size_t)(cgc_strlen ( tlv87 )); }
    {char * tlv82; tlv82 = (char *)(cgc_strlen ( tlv87 )); }
    {char * tlv83; tlv83 = (char *)(cgc_strlen ( tlv87 )); }
    {char * tlv84; tlv84 = (char *)(cgc_strlen ( tlv87 )); }
    {char * tlv85; tlv85 = (char *)(cgc_strlen ( tlv87 )); }
    {char * tlv86; tlv86 = (char *)(cgc_strlen ( tlv87 )); }
    {void * tlv65; tlv65 = (void *)(cgc_strlen ( tlv87 )); }
    {cgc_size_t tlv64; tlv64 = (cgc_size_t)(cgc_strlen ( tlv87 )); }
    {void * tlv67; tlv67 = (void *)(cgc_strlen ( tlv87 )); }
    {cgc_size_t tlv66; tlv66 = (cgc_size_t)(cgc_strlen ( tlv87 )); }
    {void * tlv77; tlv77 = (void *)(cgc_strlen ( tlv87 )); }
    {cgc_size_t tlv76; tlv76 = (cgc_size_t)(cgc_strlen ( tlv87 )); }
    {void * tlv79; tlv79 = (void *)(cgc_strlen ( tlv87 )); }
    {cgc_size_t tlv78; tlv78 = (cgc_size_t)(cgc_strlen ( tlv87 )); }
    {char * tlv88; tlv88 = (char *)(cgc_strlen ( tlv87 )); }
    {char * tlv89; tlv89 = (char *)(cgc_strlen ( tlv87 )); }
    {char * tlv90; tlv90 = (char *)(cgc_strlen ( tlv87 )); }
}
void fix_ingred_planetParsers_6_19(){
fix_ingred_planetParsers_6_19_1();
}
void fix_ingred_planetParsers_6_21_1(){
char tlv88_ref;
    bzero(&tlv88_ref,1*sizeof(char));
char * tlv88 = &tlv88_ref;
    {char * temp; temp = (char *)(cgc_strlen ( tlv88 ) + 1); }
    {int ss; ss = (int)(cgc_strlen ( tlv88 ) + 1); }
    {int se; se = (int)(cgc_strlen ( tlv88 ) + 1); }
    {int tlv1; tlv1 = (int)(cgc_strlen ( tlv88 ) + 1); }
    {int tlv2; tlv2 = (int)(cgc_strlen ( tlv88 ) + 1); }
    {int tlv3; tlv3 = (int)(cgc_strlen ( tlv88 ) + 1); }
    {int tlv4; tlv4 = (int)(cgc_strlen ( tlv88 ) + 1); }
    {int tlv5; tlv5 = (int)(cgc_strlen ( tlv88 ) + 1); }
    {int tlv6; tlv6 = (int)(cgc_strlen ( tlv88 ) + 1); }
    {int tlv7; tlv7 = (int)(cgc_strlen ( tlv88 ) + 1); }
    {int tlv8; tlv8 = (int)(cgc_strlen ( tlv88 ) + 1); }
    {int tlv9; tlv9 = (int)(cgc_strlen ( tlv88 ) + 1); }
    {int tlv10; tlv10 = (int)(cgc_strlen ( tlv88 ) + 1); }
    {char tlv24; tlv24 = (char)(cgc_strlen ( tlv88 ) + 1); }
    {int tlv26; tlv26 = (int)(cgc_strlen ( tlv88 ) + 1); }
    {int tlv31; tlv31 = (int)(cgc_strlen ( tlv88 ) + 1); }
    {int tlv30; tlv30 = (int)(cgc_strlen ( tlv88 ) + 1); }
    {void * tlv12; tlv12 = (void *)(cgc_strlen ( tlv88 ) + 1); }
    {cgc_size_t tlv11; tlv11 = (cgc_size_t)(cgc_strlen ( tlv88 ) + 1); }
    {void * tlv14; tlv14 = (void *)(cgc_strlen ( tlv88 ) + 1); }
    {cgc_size_t tlv13; tlv13 = (cgc_size_t)(cgc_strlen ( tlv88 ) + 1); }
    {char tlv35; tlv35 = (char)(cgc_strlen ( tlv88 ) + 1); }
    {int tlv37; tlv37 = (int)(cgc_strlen ( tlv88 ) + 1); }
    {char tlv40; tlv40 = (char)(cgc_strlen ( tlv88 ) + 1); }
    {int tlv42; tlv42 = (int)(cgc_strlen ( tlv88 ) + 1); }
    {char tlv44; tlv44 = (char)(cgc_strlen ( tlv88 ) + 1); }
    {int tlv46; tlv46 = (int)(cgc_strlen ( tlv88 ) + 1); }
    {int tlv50; tlv50 = (int)(cgc_strlen ( tlv88 ) + 1); }
    {int tlv49; tlv49 = (int)(cgc_strlen ( tlv88 ) + 1); }
    {void * tlv16; tlv16 = (void *)(cgc_strlen ( tlv88 ) + 1); }
    {cgc_size_t tlv15; tlv15 = (cgc_size_t)(cgc_strlen ( tlv88 ) + 1); }
    {void * tlv18; tlv18 = (void *)(cgc_strlen ( tlv88 ) + 1); }
    {cgc_size_t tlv17; tlv17 = (cgc_size_t)(cgc_strlen ( tlv88 ) + 1); }
    {char tlv54; tlv54 = (char)(cgc_strlen ( tlv88 ) + 1); }
    {int tlv19; tlv19 = (int)(cgc_strlen ( tlv88 ) + 1); }
    {int tlv57; tlv57 = (int)(cgc_strlen ( tlv88 ) + 1); }
    {int tlv56; tlv56 = (int)(cgc_strlen ( tlv88 ) + 1); }
    {void * tlv22; tlv22 = (void *)(cgc_strlen ( tlv88 ) + 1); }
    {cgc_size_t tlv21; tlv21 = (cgc_size_t)(cgc_strlen ( tlv88 ) + 1); }
    {char * tlv82; tlv82 = (char *)(cgc_strlen ( tlv88 ) + 1); }
    {char * tlv83; tlv83 = (char *)(cgc_strlen ( tlv88 ) + 1); }
    {char * tlv84; tlv84 = (char *)(cgc_strlen ( tlv88 ) + 1); }
    {char * tlv85; tlv85 = (char *)(cgc_strlen ( tlv88 ) + 1); }
    {char * tlv86; tlv86 = (char *)(cgc_strlen ( tlv88 ) + 1); }
    {void * tlv65; tlv65 = (void *)(cgc_strlen ( tlv88 ) + 1); }
    {cgc_size_t tlv64; tlv64 = (cgc_size_t)(cgc_strlen ( tlv88 ) + 1); }
    {void * tlv67; tlv67 = (void *)(cgc_strlen ( tlv88 ) + 1); }
    {cgc_size_t tlv66; tlv66 = (cgc_size_t)(cgc_strlen ( tlv88 ) + 1); }
    {void * tlv77; tlv77 = (void *)(cgc_strlen ( tlv88 ) + 1); }
    {cgc_size_t tlv76; tlv76 = (cgc_size_t)(cgc_strlen ( tlv88 ) + 1); }
    {void * tlv79; tlv79 = (void *)(cgc_strlen ( tlv88 ) + 1); }
    {cgc_size_t tlv78; tlv78 = (cgc_size_t)(cgc_strlen ( tlv88 ) + 1); }
    {char * tlv87; tlv87 = (char *)(cgc_strlen ( tlv88 ) + 1); }
    {char * tlv89; tlv89 = (char *)(cgc_strlen ( tlv88 ) + 1); }
    {char * tlv90; tlv90 = (char *)(cgc_strlen ( tlv88 ) + 1); }
}
void fix_ingred_planetParsers_6_21(){
fix_ingred_planetParsers_6_21_1();
}
void fix_ingred_planetParsers_6_23_1(){
char tlv82_ref;
    bzero(&tlv82_ref,1*sizeof(char));
char * tlv82 = &tlv82_ref;
    {char * temp; temp = (char *)(cgc_strlen ( tlv82 ) + 1); }
    {int ss; ss = (int)(cgc_strlen ( tlv82 ) + 1); }
    {int se; se = (int)(cgc_strlen ( tlv82 ) + 1); }
    {int tlv1; tlv1 = (int)(cgc_strlen ( tlv82 ) + 1); }
    {int tlv2; tlv2 = (int)(cgc_strlen ( tlv82 ) + 1); }
    {int tlv3; tlv3 = (int)(cgc_strlen ( tlv82 ) + 1); }
    {int tlv4; tlv4 = (int)(cgc_strlen ( tlv82 ) + 1); }
    {int tlv5; tlv5 = (int)(cgc_strlen ( tlv82 ) + 1); }
    {int tlv6; tlv6 = (int)(cgc_strlen ( tlv82 ) + 1); }
    {int tlv7; tlv7 = (int)(cgc_strlen ( tlv82 ) + 1); }
    {int tlv8; tlv8 = (int)(cgc_strlen ( tlv82 ) + 1); }
    {int tlv9; tlv9 = (int)(cgc_strlen ( tlv82 ) + 1); }
    {int tlv10; tlv10 = (int)(cgc_strlen ( tlv82 ) + 1); }
    {char tlv24; tlv24 = (char)(cgc_strlen ( tlv82 ) + 1); }
    {int tlv26; tlv26 = (int)(cgc_strlen ( tlv82 ) + 1); }
    {int tlv31; tlv31 = (int)(cgc_strlen ( tlv82 ) + 1); }
    {int tlv30; tlv30 = (int)(cgc_strlen ( tlv82 ) + 1); }
    {void * tlv12; tlv12 = (void *)(cgc_strlen ( tlv82 ) + 1); }
    {cgc_size_t tlv11; tlv11 = (cgc_size_t)(cgc_strlen ( tlv82 ) + 1); }
    {void * tlv14; tlv14 = (void *)(cgc_strlen ( tlv82 ) + 1); }
    {cgc_size_t tlv13; tlv13 = (cgc_size_t)(cgc_strlen ( tlv82 ) + 1); }
    {char tlv35; tlv35 = (char)(cgc_strlen ( tlv82 ) + 1); }
    {int tlv37; tlv37 = (int)(cgc_strlen ( tlv82 ) + 1); }
    {char tlv40; tlv40 = (char)(cgc_strlen ( tlv82 ) + 1); }
    {int tlv42; tlv42 = (int)(cgc_strlen ( tlv82 ) + 1); }
    {char tlv44; tlv44 = (char)(cgc_strlen ( tlv82 ) + 1); }
    {int tlv46; tlv46 = (int)(cgc_strlen ( tlv82 ) + 1); }
    {int tlv50; tlv50 = (int)(cgc_strlen ( tlv82 ) + 1); }
    {int tlv49; tlv49 = (int)(cgc_strlen ( tlv82 ) + 1); }
    {void * tlv16; tlv16 = (void *)(cgc_strlen ( tlv82 ) + 1); }
    {cgc_size_t tlv15; tlv15 = (cgc_size_t)(cgc_strlen ( tlv82 ) + 1); }
    {void * tlv18; tlv18 = (void *)(cgc_strlen ( tlv82 ) + 1); }
    {cgc_size_t tlv17; tlv17 = (cgc_size_t)(cgc_strlen ( tlv82 ) + 1); }
    {char tlv54; tlv54 = (char)(cgc_strlen ( tlv82 ) + 1); }
    {int tlv19; tlv19 = (int)(cgc_strlen ( tlv82 ) + 1); }
    {int tlv57; tlv57 = (int)(cgc_strlen ( tlv82 ) + 1); }
    {int tlv56; tlv56 = (int)(cgc_strlen ( tlv82 ) + 1); }
    {void * tlv22; tlv22 = (void *)(cgc_strlen ( tlv82 ) + 1); }
    {cgc_size_t tlv21; tlv21 = (cgc_size_t)(cgc_strlen ( tlv82 ) + 1); }
    {char * tlv83; tlv83 = (char *)(cgc_strlen ( tlv82 ) + 1); }
    {char * tlv84; tlv84 = (char *)(cgc_strlen ( tlv82 ) + 1); }
    {char * tlv85; tlv85 = (char *)(cgc_strlen ( tlv82 ) + 1); }
    {char * tlv86; tlv86 = (char *)(cgc_strlen ( tlv82 ) + 1); }
    {void * tlv65; tlv65 = (void *)(cgc_strlen ( tlv82 ) + 1); }
    {cgc_size_t tlv64; tlv64 = (cgc_size_t)(cgc_strlen ( tlv82 ) + 1); }
    {void * tlv67; tlv67 = (void *)(cgc_strlen ( tlv82 ) + 1); }
    {cgc_size_t tlv66; tlv66 = (cgc_size_t)(cgc_strlen ( tlv82 ) + 1); }
    {void * tlv77; tlv77 = (void *)(cgc_strlen ( tlv82 ) + 1); }
    {cgc_size_t tlv76; tlv76 = (cgc_size_t)(cgc_strlen ( tlv82 ) + 1); }
    {void * tlv79; tlv79 = (void *)(cgc_strlen ( tlv82 ) + 1); }
    {cgc_size_t tlv78; tlv78 = (cgc_size_t)(cgc_strlen ( tlv82 ) + 1); }
    {char * tlv87; tlv87 = (char *)(cgc_strlen ( tlv82 ) + 1); }
    {char * tlv88; tlv88 = (char *)(cgc_strlen ( tlv82 ) + 1); }
    {char * tlv89; tlv89 = (char *)(cgc_strlen ( tlv82 ) + 1); }
    {char * tlv90; tlv90 = (char *)(cgc_strlen ( tlv82 ) + 1); }
}
void fix_ingred_planetParsers_6_23(){
fix_ingred_planetParsers_6_23_1();
}
void fix_ingred_planetParsers_6_25_1(){
char tlv83_ref;
    bzero(&tlv83_ref,1*sizeof(char));
char * tlv83 = &tlv83_ref;
    {char * temp; temp = (char *)(cgc_strlen ( tlv83 ) + 1); }
    {int ss; ss = (int)(cgc_strlen ( tlv83 ) + 1); }
    {int se; se = (int)(cgc_strlen ( tlv83 ) + 1); }
    {int tlv1; tlv1 = (int)(cgc_strlen ( tlv83 ) + 1); }
    {int tlv2; tlv2 = (int)(cgc_strlen ( tlv83 ) + 1); }
    {int tlv3; tlv3 = (int)(cgc_strlen ( tlv83 ) + 1); }
    {int tlv4; tlv4 = (int)(cgc_strlen ( tlv83 ) + 1); }
    {int tlv5; tlv5 = (int)(cgc_strlen ( tlv83 ) + 1); }
    {int tlv6; tlv6 = (int)(cgc_strlen ( tlv83 ) + 1); }
    {int tlv7; tlv7 = (int)(cgc_strlen ( tlv83 ) + 1); }
    {int tlv8; tlv8 = (int)(cgc_strlen ( tlv83 ) + 1); }
    {int tlv9; tlv9 = (int)(cgc_strlen ( tlv83 ) + 1); }
    {int tlv10; tlv10 = (int)(cgc_strlen ( tlv83 ) + 1); }
    {char tlv24; tlv24 = (char)(cgc_strlen ( tlv83 ) + 1); }
    {int tlv26; tlv26 = (int)(cgc_strlen ( tlv83 ) + 1); }
    {int tlv31; tlv31 = (int)(cgc_strlen ( tlv83 ) + 1); }
    {int tlv30; tlv30 = (int)(cgc_strlen ( tlv83 ) + 1); }
    {void * tlv12; tlv12 = (void *)(cgc_strlen ( tlv83 ) + 1); }
    {cgc_size_t tlv11; tlv11 = (cgc_size_t)(cgc_strlen ( tlv83 ) + 1); }
    {void * tlv14; tlv14 = (void *)(cgc_strlen ( tlv83 ) + 1); }
    {cgc_size_t tlv13; tlv13 = (cgc_size_t)(cgc_strlen ( tlv83 ) + 1); }
    {char tlv35; tlv35 = (char)(cgc_strlen ( tlv83 ) + 1); }
    {int tlv37; tlv37 = (int)(cgc_strlen ( tlv83 ) + 1); }
    {char tlv40; tlv40 = (char)(cgc_strlen ( tlv83 ) + 1); }
    {int tlv42; tlv42 = (int)(cgc_strlen ( tlv83 ) + 1); }
    {char tlv44; tlv44 = (char)(cgc_strlen ( tlv83 ) + 1); }
    {int tlv46; tlv46 = (int)(cgc_strlen ( tlv83 ) + 1); }
    {int tlv50; tlv50 = (int)(cgc_strlen ( tlv83 ) + 1); }
    {int tlv49; tlv49 = (int)(cgc_strlen ( tlv83 ) + 1); }
    {void * tlv16; tlv16 = (void *)(cgc_strlen ( tlv83 ) + 1); }
    {cgc_size_t tlv15; tlv15 = (cgc_size_t)(cgc_strlen ( tlv83 ) + 1); }
    {void * tlv18; tlv18 = (void *)(cgc_strlen ( tlv83 ) + 1); }
    {cgc_size_t tlv17; tlv17 = (cgc_size_t)(cgc_strlen ( tlv83 ) + 1); }
    {char tlv54; tlv54 = (char)(cgc_strlen ( tlv83 ) + 1); }
    {int tlv19; tlv19 = (int)(cgc_strlen ( tlv83 ) + 1); }
    {int tlv57; tlv57 = (int)(cgc_strlen ( tlv83 ) + 1); }
    {int tlv56; tlv56 = (int)(cgc_strlen ( tlv83 ) + 1); }
    {void * tlv22; tlv22 = (void *)(cgc_strlen ( tlv83 ) + 1); }
    {cgc_size_t tlv21; tlv21 = (cgc_size_t)(cgc_strlen ( tlv83 ) + 1); }
    {char * tlv82; tlv82 = (char *)(cgc_strlen ( tlv83 ) + 1); }
    {char * tlv84; tlv84 = (char *)(cgc_strlen ( tlv83 ) + 1); }
    {char * tlv85; tlv85 = (char *)(cgc_strlen ( tlv83 ) + 1); }
    {char * tlv86; tlv86 = (char *)(cgc_strlen ( tlv83 ) + 1); }
    {void * tlv65; tlv65 = (void *)(cgc_strlen ( tlv83 ) + 1); }
    {cgc_size_t tlv64; tlv64 = (cgc_size_t)(cgc_strlen ( tlv83 ) + 1); }
    {void * tlv67; tlv67 = (void *)(cgc_strlen ( tlv83 ) + 1); }
    {cgc_size_t tlv66; tlv66 = (cgc_size_t)(cgc_strlen ( tlv83 ) + 1); }
    {void * tlv77; tlv77 = (void *)(cgc_strlen ( tlv83 ) + 1); }
    {cgc_size_t tlv76; tlv76 = (cgc_size_t)(cgc_strlen ( tlv83 ) + 1); }
    {void * tlv79; tlv79 = (void *)(cgc_strlen ( tlv83 ) + 1); }
    {cgc_size_t tlv78; tlv78 = (cgc_size_t)(cgc_strlen ( tlv83 ) + 1); }
    {char * tlv87; tlv87 = (char *)(cgc_strlen ( tlv83 ) + 1); }
    {char * tlv88; tlv88 = (char *)(cgc_strlen ( tlv83 ) + 1); }
    {char * tlv89; tlv89 = (char *)(cgc_strlen ( tlv83 ) + 1); }
    {char * tlv90; tlv90 = (char *)(cgc_strlen ( tlv83 ) + 1); }
}
void fix_ingred_planetParsers_6_25(){
fix_ingred_planetParsers_6_25_1();
}
void fix_ingred_planetParsers_6_26_1(){
    {int ss; ss = (int)('}'); }
    {int se; se = (int)('}'); }
    {char tlv24; tlv24 = (char)('}'); }
    {int tlv31; tlv31 = (int)('}'); }
    {int tlv30; tlv30 = (int)('}'); }
    {void * tlv14; tlv14 = (void *)('}'); }
    {cgc_size_t tlv13; tlv13 = (cgc_size_t)('}'); }
    {char tlv35; tlv35 = (char)('}'); }
    {int tlv37; tlv37 = (int)('}'); }
    {char tlv40; tlv40 = (char)('}'); }
    {int tlv42; tlv42 = (int)('}'); }
    {char tlv44; tlv44 = (char)('}'); }
    {int tlv50; tlv50 = (int)('}'); }
    {int tlv49; tlv49 = (int)('}'); }
    {void * tlv18; tlv18 = (void *)('}'); }
    {cgc_size_t tlv17; tlv17 = (cgc_size_t)('}'); }
    {char tlv54; tlv54 = (char)('}'); }
    {int tlv19; tlv19 = (int)('}'); }
    {int tlv57; tlv57 = (int)('}'); }
    {int tlv56; tlv56 = (int)('}'); }
    {void * tlv22; tlv22 = (void *)('}'); }
    {cgc_size_t tlv21; tlv21 = (cgc_size_t)('}'); }
    {char * tlv82; tlv82 = (char *)('}'); }
    {char * tlv83; tlv83 = (char *)('}'); }
    {char * tlv84; tlv84 = (char *)('}'); }
    {char * tlv85; tlv85 = (char *)('}'); }
    {char * tlv86; tlv86 = (char *)('}'); }
    {void * tlv65; tlv65 = (void *)('}'); }
    {cgc_size_t tlv64; tlv64 = (cgc_size_t)('}'); }
    {void * tlv67; tlv67 = (void *)('}'); }
    {cgc_size_t tlv66; tlv66 = (cgc_size_t)('}'); }
    {void * tlv77; tlv77 = (void *)('}'); }
    {cgc_size_t tlv76; tlv76 = (cgc_size_t)('}'); }
    {void * tlv79; tlv79 = (void *)('}'); }
    {cgc_size_t tlv78; tlv78 = (cgc_size_t)('}'); }
    {char * tlv87; tlv87 = (char *)('}'); }
    {char * tlv88; tlv88 = (char *)('}'); }
    {char * tlv89; tlv89 = (char *)('}'); }
    {char * tlv90; tlv90 = (char *)('}'); }
}
void fix_ingred_planetParsers_6_26(){
fix_ingred_planetParsers_6_26_1();
}
void fix_ingred_planetParsers_6_30_6(){
int tlv5;
    bzero(&tlv5,sizeof(int));
    {int ss; ss = (int)(tlv5); }
    {int se; se = (int)(tlv5); }
    {char tlv24; tlv24 = (char)(tlv5); }
    {int tlv31; tlv31 = (int)(tlv5); }
    {int tlv30; tlv30 = (int)(tlv5); }
    {void * tlv14; tlv14 = (void *)(tlv5); }
    {cgc_size_t tlv13; tlv13 = (cgc_size_t)(tlv5); }
    {char tlv35; tlv35 = (char)(tlv5); }
    {int tlv37; tlv37 = (int)(tlv5); }
    {char tlv40; tlv40 = (char)(tlv5); }
    {int tlv42; tlv42 = (int)(tlv5); }
    {char tlv44; tlv44 = (char)(tlv5); }
    {int tlv50; tlv50 = (int)(tlv5); }
    {int tlv49; tlv49 = (int)(tlv5); }
    {void * tlv18; tlv18 = (void *)(tlv5); }
    {cgc_size_t tlv17; tlv17 = (cgc_size_t)(tlv5); }
    {char tlv54; tlv54 = (char)(tlv5); }
    {int tlv19; tlv19 = (int)(tlv5); }
    {int tlv57; tlv57 = (int)(tlv5); }
    {int tlv56; tlv56 = (int)(tlv5); }
    {void * tlv22; tlv22 = (void *)(tlv5); }
    {cgc_size_t tlv21; tlv21 = (cgc_size_t)(tlv5); }
    {char * tlv82; tlv82 = (char *)(tlv5); }
    {char * tlv83; tlv83 = (char *)(tlv5); }
    {char * tlv84; tlv84 = (char *)(tlv5); }
    {char * tlv85; tlv85 = (char *)(tlv5); }
    {char * tlv86; tlv86 = (char *)(tlv5); }
    {void * tlv65; tlv65 = (void *)(tlv5); }
    {cgc_size_t tlv64; tlv64 = (cgc_size_t)(tlv5); }
    {void * tlv67; tlv67 = (void *)(tlv5); }
    {cgc_size_t tlv66; tlv66 = (cgc_size_t)(tlv5); }
    {void * tlv77; tlv77 = (void *)(tlv5); }
    {cgc_size_t tlv76; tlv76 = (cgc_size_t)(tlv5); }
    {void * tlv79; tlv79 = (void *)(tlv5); }
    {cgc_size_t tlv78; tlv78 = (cgc_size_t)(tlv5); }
    {char * tlv87; tlv87 = (char *)(tlv5); }
    {char * tlv88; tlv88 = (char *)(tlv5); }
    {char * tlv89; tlv89 = (char *)(tlv5); }
    {char * tlv90; tlv90 = (char *)(tlv5); }
}
void fix_ingred_planetParsers_6_30(){
fix_ingred_planetParsers_6_30_6();
}
void fix_ingred_planetParsers_6_33_7(){
int se;
    bzero(&se,sizeof(int));
    {char * temp; temp = (char *)(se); }
    {int ss; ss = (int)(se); }
    {int tlv1; tlv1 = (int)(se); }
    {int tlv2; tlv2 = (int)(se); }
    {int tlv3; tlv3 = (int)(se); }
    {int tlv4; tlv4 = (int)(se); }
    {int tlv5; tlv5 = (int)(se); }
    {int tlv6; tlv6 = (int)(se); }
    {int tlv7; tlv7 = (int)(se); }
    {int tlv8; tlv8 = (int)(se); }
    {int tlv9; tlv9 = (int)(se); }
    {int tlv10; tlv10 = (int)(se); }
    {char tlv24; tlv24 = (char)(se); }
    {int tlv26; tlv26 = (int)(se); }
    {int tlv31; tlv31 = (int)(se); }
    {int tlv30; tlv30 = (int)(se); }
    {void * tlv12; tlv12 = (void *)(se); }
    {cgc_size_t tlv11; tlv11 = (cgc_size_t)(se); }
    {void * tlv14; tlv14 = (void *)(se); }
    {cgc_size_t tlv13; tlv13 = (cgc_size_t)(se); }
    {char tlv35; tlv35 = (char)(se); }
    {int tlv37; tlv37 = (int)(se); }
    {char tlv40; tlv40 = (char)(se); }
    {int tlv42; tlv42 = (int)(se); }
    {char tlv44; tlv44 = (char)(se); }
    {int tlv46; tlv46 = (int)(se); }
    {int tlv50; tlv50 = (int)(se); }
    {int tlv49; tlv49 = (int)(se); }
    {void * tlv16; tlv16 = (void *)(se); }
    {cgc_size_t tlv15; tlv15 = (cgc_size_t)(se); }
    {void * tlv18; tlv18 = (void *)(se); }
    {cgc_size_t tlv17; tlv17 = (cgc_size_t)(se); }
    {char tlv54; tlv54 = (char)(se); }
    {int tlv19; tlv19 = (int)(se); }
    {int tlv57; tlv57 = (int)(se); }
    {int tlv56; tlv56 = (int)(se); }
    {void * tlv22; tlv22 = (void *)(se); }
    {cgc_size_t tlv21; tlv21 = (cgc_size_t)(se); }
    {char * tlv82; tlv82 = (char *)(se); }
    {char * tlv83; tlv83 = (char *)(se); }
    {char * tlv84; tlv84 = (char *)(se); }
    {char * tlv85; tlv85 = (char *)(se); }
    {char * tlv86; tlv86 = (char *)(se); }
    {void * tlv65; tlv65 = (void *)(se); }
    {cgc_size_t tlv64; tlv64 = (cgc_size_t)(se); }
    {void * tlv67; tlv67 = (void *)(se); }
    {cgc_size_t tlv66; tlv66 = (cgc_size_t)(se); }
    {void * tlv77; tlv77 = (void *)(se); }
    {cgc_size_t tlv76; tlv76 = (cgc_size_t)(se); }
    {void * tlv79; tlv79 = (void *)(se); }
    {cgc_size_t tlv78; tlv78 = (cgc_size_t)(se); }
    {char * tlv87; tlv87 = (char *)(se); }
    {char * tlv88; tlv88 = (char *)(se); }
    {char * tlv89; tlv89 = (char *)(se); }
    {char * tlv90; tlv90 = (char *)(se); }
}
void fix_ingred_planetParsers_6_33(){
fix_ingred_planetParsers_6_33_7();
}
void fix_ingred_planetParsers_6_39_7(){
int tlv7;
    bzero(&tlv7,sizeof(int));
    {int ss; ss = (int)(tlv7); }
    {int se; se = (int)(tlv7); }
    {char tlv24; tlv24 = (char)(tlv7); }
    {int tlv26; tlv26 = (int)(tlv7); }
    {int tlv31; tlv31 = (int)(tlv7); }
    {int tlv30; tlv30 = (int)(tlv7); }
    {void * tlv14; tlv14 = (void *)(tlv7); }
    {cgc_size_t tlv13; tlv13 = (cgc_size_t)(tlv7); }
    {char tlv35; tlv35 = (char)(tlv7); }
    {int tlv37; tlv37 = (int)(tlv7); }
    {char tlv40; tlv40 = (char)(tlv7); }
    {int tlv42; tlv42 = (int)(tlv7); }
    {char tlv44; tlv44 = (char)(tlv7); }
    {int tlv50; tlv50 = (int)(tlv7); }
    {int tlv49; tlv49 = (int)(tlv7); }
    {void * tlv18; tlv18 = (void *)(tlv7); }
    {cgc_size_t tlv17; tlv17 = (cgc_size_t)(tlv7); }
    {char tlv54; tlv54 = (char)(tlv7); }
    {int tlv19; tlv19 = (int)(tlv7); }
    {int tlv57; tlv57 = (int)(tlv7); }
    {int tlv56; tlv56 = (int)(tlv7); }
    {void * tlv22; tlv22 = (void *)(tlv7); }
    {cgc_size_t tlv21; tlv21 = (cgc_size_t)(tlv7); }
    {char * tlv82; tlv82 = (char *)(tlv7); }
    {char * tlv83; tlv83 = (char *)(tlv7); }
    {char * tlv84; tlv84 = (char *)(tlv7); }
    {char * tlv85; tlv85 = (char *)(tlv7); }
    {char * tlv86; tlv86 = (char *)(tlv7); }
    {void * tlv65; tlv65 = (void *)(tlv7); }
    {cgc_size_t tlv64; tlv64 = (cgc_size_t)(tlv7); }
    {void * tlv67; tlv67 = (void *)(tlv7); }
    {cgc_size_t tlv66; tlv66 = (cgc_size_t)(tlv7); }
    {void * tlv77; tlv77 = (void *)(tlv7); }
    {cgc_size_t tlv76; tlv76 = (cgc_size_t)(tlv7); }
    {void * tlv79; tlv79 = (void *)(tlv7); }
    {cgc_size_t tlv78; tlv78 = (cgc_size_t)(tlv7); }
    {char * tlv87; tlv87 = (char *)(tlv7); }
    {char * tlv88; tlv88 = (char *)(tlv7); }
    {char * tlv89; tlv89 = (char *)(tlv7); }
    {char * tlv90; tlv90 = (char *)(tlv7); }
}
void fix_ingred_planetParsers_6_39(){
fix_ingred_planetParsers_6_39_7();
}
void fix_ingred_planetParsers_6_41_1(){
    {int ss; ss = (int)('#'); }
    {int se; se = (int)('#'); }
    {char tlv24; tlv24 = (char)('#'); }
    {int tlv31; tlv31 = (int)('#'); }
    {int tlv30; tlv30 = (int)('#'); }
    {void * tlv14; tlv14 = (void *)('#'); }
    {cgc_size_t tlv13; tlv13 = (cgc_size_t)('#'); }
    {char tlv35; tlv35 = (char)('#'); }
    {int tlv37; tlv37 = (int)('#'); }
    {char tlv40; tlv40 = (char)('#'); }
    {int tlv42; tlv42 = (int)('#'); }
    {char tlv44; tlv44 = (char)('#'); }
    {int tlv50; tlv50 = (int)('#'); }
    {int tlv49; tlv49 = (int)('#'); }
    {void * tlv18; tlv18 = (void *)('#'); }
    {cgc_size_t tlv17; tlv17 = (cgc_size_t)('#'); }
    {char tlv54; tlv54 = (char)('#'); }
    {int tlv19; tlv19 = (int)('#'); }
    {int tlv57; tlv57 = (int)('#'); }
    {int tlv56; tlv56 = (int)('#'); }
    {void * tlv22; tlv22 = (void *)('#'); }
    {cgc_size_t tlv21; tlv21 = (cgc_size_t)('#'); }
    {char * tlv82; tlv82 = (char *)('#'); }
    {char * tlv83; tlv83 = (char *)('#'); }
    {char * tlv84; tlv84 = (char *)('#'); }
    {char * tlv85; tlv85 = (char *)('#'); }
    {char * tlv86; tlv86 = (char *)('#'); }
    {void * tlv65; tlv65 = (void *)('#'); }
    {cgc_size_t tlv64; tlv64 = (cgc_size_t)('#'); }
    {void * tlv67; tlv67 = (void *)('#'); }
    {cgc_size_t tlv66; tlv66 = (cgc_size_t)('#'); }
    {void * tlv77; tlv77 = (void *)('#'); }
    {cgc_size_t tlv76; tlv76 = (cgc_size_t)('#'); }
    {void * tlv79; tlv79 = (void *)('#'); }
    {cgc_size_t tlv78; tlv78 = (cgc_size_t)('#'); }
    {char * tlv87; tlv87 = (char *)('#'); }
    {char * tlv88; tlv88 = (char *)('#'); }
    {char * tlv89; tlv89 = (char *)('#'); }
    {char * tlv90; tlv90 = (char *)('#'); }
}
void fix_ingred_planetParsers_6_41(){
fix_ingred_planetParsers_6_41_1();
}
void fix_ingred_planetParsers_6_52_7(){
int tlv9;
    bzero(&tlv9,sizeof(int));
    {int ss; ss = (int)(tlv9); }
    {int se; se = (int)(tlv9); }
    {char tlv24; tlv24 = (char)(tlv9); }
    {int tlv26; tlv26 = (int)(tlv9); }
    {int tlv31; tlv31 = (int)(tlv9); }
    {int tlv30; tlv30 = (int)(tlv9); }
    {void * tlv14; tlv14 = (void *)(tlv9); }
    {cgc_size_t tlv13; tlv13 = (cgc_size_t)(tlv9); }
    {char tlv35; tlv35 = (char)(tlv9); }
    {int tlv37; tlv37 = (int)(tlv9); }
    {char tlv40; tlv40 = (char)(tlv9); }
    {int tlv42; tlv42 = (int)(tlv9); }
    {char tlv44; tlv44 = (char)(tlv9); }
    {int tlv50; tlv50 = (int)(tlv9); }
    {int tlv49; tlv49 = (int)(tlv9); }
    {void * tlv18; tlv18 = (void *)(tlv9); }
    {cgc_size_t tlv17; tlv17 = (cgc_size_t)(tlv9); }
    {char tlv54; tlv54 = (char)(tlv9); }
    {int tlv19; tlv19 = (int)(tlv9); }
    {int tlv57; tlv57 = (int)(tlv9); }
    {int tlv56; tlv56 = (int)(tlv9); }
    {void * tlv22; tlv22 = (void *)(tlv9); }
    {cgc_size_t tlv21; tlv21 = (cgc_size_t)(tlv9); }
    {char * tlv82; tlv82 = (char *)(tlv9); }
    {char * tlv83; tlv83 = (char *)(tlv9); }
    {char * tlv84; tlv84 = (char *)(tlv9); }
    {char * tlv85; tlv85 = (char *)(tlv9); }
    {char * tlv86; tlv86 = (char *)(tlv9); }
    {void * tlv65; tlv65 = (void *)(tlv9); }
    {cgc_size_t tlv64; tlv64 = (cgc_size_t)(tlv9); }
    {void * tlv67; tlv67 = (void *)(tlv9); }
    {cgc_size_t tlv66; tlv66 = (cgc_size_t)(tlv9); }
    {void * tlv77; tlv77 = (void *)(tlv9); }
    {cgc_size_t tlv76; tlv76 = (cgc_size_t)(tlv9); }
    {void * tlv79; tlv79 = (void *)(tlv9); }
    {cgc_size_t tlv78; tlv78 = (cgc_size_t)(tlv9); }
    {char * tlv87; tlv87 = (char *)(tlv9); }
    {char * tlv88; tlv88 = (char *)(tlv9); }
    {char * tlv89; tlv89 = (char *)(tlv9); }
    {char * tlv90; tlv90 = (char *)(tlv9); }
}
void fix_ingred_planetParsers_6_52(){
fix_ingred_planetParsers_6_52_7();
}
void fix_ingred_planetParsers_6_54_1(){
char tlv89_ref;
    bzero(&tlv89_ref,1*sizeof(char));
char * tlv89 = &tlv89_ref;
    {char * temp; temp = (char *)(cgc_strlen ( tlv89 ) + 1); }
    {int ss; ss = (int)(cgc_strlen ( tlv89 ) + 1); }
    {int se; se = (int)(cgc_strlen ( tlv89 ) + 1); }
    {int tlv1; tlv1 = (int)(cgc_strlen ( tlv89 ) + 1); }
    {int tlv2; tlv2 = (int)(cgc_strlen ( tlv89 ) + 1); }
    {int tlv3; tlv3 = (int)(cgc_strlen ( tlv89 ) + 1); }
    {int tlv4; tlv4 = (int)(cgc_strlen ( tlv89 ) + 1); }
    {int tlv5; tlv5 = (int)(cgc_strlen ( tlv89 ) + 1); }
    {int tlv6; tlv6 = (int)(cgc_strlen ( tlv89 ) + 1); }
    {int tlv7; tlv7 = (int)(cgc_strlen ( tlv89 ) + 1); }
    {int tlv8; tlv8 = (int)(cgc_strlen ( tlv89 ) + 1); }
    {int tlv9; tlv9 = (int)(cgc_strlen ( tlv89 ) + 1); }
    {int tlv10; tlv10 = (int)(cgc_strlen ( tlv89 ) + 1); }
    {char tlv24; tlv24 = (char)(cgc_strlen ( tlv89 ) + 1); }
    {int tlv26; tlv26 = (int)(cgc_strlen ( tlv89 ) + 1); }
    {int tlv31; tlv31 = (int)(cgc_strlen ( tlv89 ) + 1); }
    {int tlv30; tlv30 = (int)(cgc_strlen ( tlv89 ) + 1); }
    {void * tlv12; tlv12 = (void *)(cgc_strlen ( tlv89 ) + 1); }
    {cgc_size_t tlv11; tlv11 = (cgc_size_t)(cgc_strlen ( tlv89 ) + 1); }
    {void * tlv14; tlv14 = (void *)(cgc_strlen ( tlv89 ) + 1); }
    {cgc_size_t tlv13; tlv13 = (cgc_size_t)(cgc_strlen ( tlv89 ) + 1); }
    {char tlv35; tlv35 = (char)(cgc_strlen ( tlv89 ) + 1); }
    {int tlv37; tlv37 = (int)(cgc_strlen ( tlv89 ) + 1); }
    {char tlv40; tlv40 = (char)(cgc_strlen ( tlv89 ) + 1); }
    {int tlv42; tlv42 = (int)(cgc_strlen ( tlv89 ) + 1); }
    {char tlv44; tlv44 = (char)(cgc_strlen ( tlv89 ) + 1); }
    {int tlv46; tlv46 = (int)(cgc_strlen ( tlv89 ) + 1); }
    {int tlv50; tlv50 = (int)(cgc_strlen ( tlv89 ) + 1); }
    {int tlv49; tlv49 = (int)(cgc_strlen ( tlv89 ) + 1); }
    {void * tlv16; tlv16 = (void *)(cgc_strlen ( tlv89 ) + 1); }
    {cgc_size_t tlv15; tlv15 = (cgc_size_t)(cgc_strlen ( tlv89 ) + 1); }
    {void * tlv18; tlv18 = (void *)(cgc_strlen ( tlv89 ) + 1); }
    {cgc_size_t tlv17; tlv17 = (cgc_size_t)(cgc_strlen ( tlv89 ) + 1); }
    {char tlv54; tlv54 = (char)(cgc_strlen ( tlv89 ) + 1); }
    {int tlv19; tlv19 = (int)(cgc_strlen ( tlv89 ) + 1); }
    {int tlv57; tlv57 = (int)(cgc_strlen ( tlv89 ) + 1); }
    {int tlv56; tlv56 = (int)(cgc_strlen ( tlv89 ) + 1); }
    {void * tlv22; tlv22 = (void *)(cgc_strlen ( tlv89 ) + 1); }
    {cgc_size_t tlv21; tlv21 = (cgc_size_t)(cgc_strlen ( tlv89 ) + 1); }
    {char * tlv82; tlv82 = (char *)(cgc_strlen ( tlv89 ) + 1); }
    {char * tlv83; tlv83 = (char *)(cgc_strlen ( tlv89 ) + 1); }
    {char * tlv84; tlv84 = (char *)(cgc_strlen ( tlv89 ) + 1); }
    {char * tlv85; tlv85 = (char *)(cgc_strlen ( tlv89 ) + 1); }
    {char * tlv86; tlv86 = (char *)(cgc_strlen ( tlv89 ) + 1); }
    {void * tlv65; tlv65 = (void *)(cgc_strlen ( tlv89 ) + 1); }
    {cgc_size_t tlv64; tlv64 = (cgc_size_t)(cgc_strlen ( tlv89 ) + 1); }
    {void * tlv67; tlv67 = (void *)(cgc_strlen ( tlv89 ) + 1); }
    {cgc_size_t tlv66; tlv66 = (cgc_size_t)(cgc_strlen ( tlv89 ) + 1); }
    {void * tlv77; tlv77 = (void *)(cgc_strlen ( tlv89 ) + 1); }
    {cgc_size_t tlv76; tlv76 = (cgc_size_t)(cgc_strlen ( tlv89 ) + 1); }
    {void * tlv79; tlv79 = (void *)(cgc_strlen ( tlv89 ) + 1); }
    {cgc_size_t tlv78; tlv78 = (cgc_size_t)(cgc_strlen ( tlv89 ) + 1); }
    {char * tlv87; tlv87 = (char *)(cgc_strlen ( tlv89 ) + 1); }
    {char * tlv88; tlv88 = (char *)(cgc_strlen ( tlv89 ) + 1); }
    {char * tlv90; tlv90 = (char *)(cgc_strlen ( tlv89 ) + 1); }
}
void fix_ingred_planetParsers_6_54(){
fix_ingred_planetParsers_6_54_1();
}
void fix_ingred_planetParsers_6_56_1(){
char tlv90_ref;
    bzero(&tlv90_ref,1*sizeof(char));
char * tlv90 = &tlv90_ref;
    {char * temp; temp = (char *)(cgc_strlen ( tlv90 ) + 1); }
    {int ss; ss = (int)(cgc_strlen ( tlv90 ) + 1); }
    {int se; se = (int)(cgc_strlen ( tlv90 ) + 1); }
    {int tlv1; tlv1 = (int)(cgc_strlen ( tlv90 ) + 1); }
    {int tlv2; tlv2 = (int)(cgc_strlen ( tlv90 ) + 1); }
    {int tlv3; tlv3 = (int)(cgc_strlen ( tlv90 ) + 1); }
    {int tlv4; tlv4 = (int)(cgc_strlen ( tlv90 ) + 1); }
    {int tlv5; tlv5 = (int)(cgc_strlen ( tlv90 ) + 1); }
    {int tlv6; tlv6 = (int)(cgc_strlen ( tlv90 ) + 1); }
    {int tlv7; tlv7 = (int)(cgc_strlen ( tlv90 ) + 1); }
    {int tlv8; tlv8 = (int)(cgc_strlen ( tlv90 ) + 1); }
    {int tlv9; tlv9 = (int)(cgc_strlen ( tlv90 ) + 1); }
    {int tlv10; tlv10 = (int)(cgc_strlen ( tlv90 ) + 1); }
    {char tlv24; tlv24 = (char)(cgc_strlen ( tlv90 ) + 1); }
    {int tlv26; tlv26 = (int)(cgc_strlen ( tlv90 ) + 1); }
    {int tlv31; tlv31 = (int)(cgc_strlen ( tlv90 ) + 1); }
    {int tlv30; tlv30 = (int)(cgc_strlen ( tlv90 ) + 1); }
    {void * tlv12; tlv12 = (void *)(cgc_strlen ( tlv90 ) + 1); }
    {cgc_size_t tlv11; tlv11 = (cgc_size_t)(cgc_strlen ( tlv90 ) + 1); }
    {void * tlv14; tlv14 = (void *)(cgc_strlen ( tlv90 ) + 1); }
    {cgc_size_t tlv13; tlv13 = (cgc_size_t)(cgc_strlen ( tlv90 ) + 1); }
    {char tlv35; tlv35 = (char)(cgc_strlen ( tlv90 ) + 1); }
    {int tlv37; tlv37 = (int)(cgc_strlen ( tlv90 ) + 1); }
    {char tlv40; tlv40 = (char)(cgc_strlen ( tlv90 ) + 1); }
    {int tlv42; tlv42 = (int)(cgc_strlen ( tlv90 ) + 1); }
    {char tlv44; tlv44 = (char)(cgc_strlen ( tlv90 ) + 1); }
    {int tlv46; tlv46 = (int)(cgc_strlen ( tlv90 ) + 1); }
    {int tlv50; tlv50 = (int)(cgc_strlen ( tlv90 ) + 1); }
    {int tlv49; tlv49 = (int)(cgc_strlen ( tlv90 ) + 1); }
    {void * tlv16; tlv16 = (void *)(cgc_strlen ( tlv90 ) + 1); }
    {cgc_size_t tlv15; tlv15 = (cgc_size_t)(cgc_strlen ( tlv90 ) + 1); }
    {void * tlv18; tlv18 = (void *)(cgc_strlen ( tlv90 ) + 1); }
    {cgc_size_t tlv17; tlv17 = (cgc_size_t)(cgc_strlen ( tlv90 ) + 1); }
    {char tlv54; tlv54 = (char)(cgc_strlen ( tlv90 ) + 1); }
    {int tlv19; tlv19 = (int)(cgc_strlen ( tlv90 ) + 1); }
    {int tlv57; tlv57 = (int)(cgc_strlen ( tlv90 ) + 1); }
    {int tlv56; tlv56 = (int)(cgc_strlen ( tlv90 ) + 1); }
    {void * tlv22; tlv22 = (void *)(cgc_strlen ( tlv90 ) + 1); }
    {cgc_size_t tlv21; tlv21 = (cgc_size_t)(cgc_strlen ( tlv90 ) + 1); }
    {char * tlv82; tlv82 = (char *)(cgc_strlen ( tlv90 ) + 1); }
    {char * tlv83; tlv83 = (char *)(cgc_strlen ( tlv90 ) + 1); }
    {char * tlv84; tlv84 = (char *)(cgc_strlen ( tlv90 ) + 1); }
    {char * tlv85; tlv85 = (char *)(cgc_strlen ( tlv90 ) + 1); }
    {char * tlv86; tlv86 = (char *)(cgc_strlen ( tlv90 ) + 1); }
    {void * tlv65; tlv65 = (void *)(cgc_strlen ( tlv90 ) + 1); }
    {cgc_size_t tlv64; tlv64 = (cgc_size_t)(cgc_strlen ( tlv90 ) + 1); }
    {void * tlv67; tlv67 = (void *)(cgc_strlen ( tlv90 ) + 1); }
    {cgc_size_t tlv66; tlv66 = (cgc_size_t)(cgc_strlen ( tlv90 ) + 1); }
    {void * tlv77; tlv77 = (void *)(cgc_strlen ( tlv90 ) + 1); }
    {cgc_size_t tlv76; tlv76 = (cgc_size_t)(cgc_strlen ( tlv90 ) + 1); }
    {void * tlv79; tlv79 = (void *)(cgc_strlen ( tlv90 ) + 1); }
    {cgc_size_t tlv78; tlv78 = (cgc_size_t)(cgc_strlen ( tlv90 ) + 1); }
    {char * tlv87; tlv87 = (char *)(cgc_strlen ( tlv90 ) + 1); }
    {char * tlv88; tlv88 = (char *)(cgc_strlen ( tlv90 ) + 1); }
    {char * tlv89; tlv89 = (char *)(cgc_strlen ( tlv90 ) + 1); }
}
void fix_ingred_planetParsers_6_56(){
fix_ingred_planetParsers_6_56_1();
}
void fix_ingred_planetParsers_6_58_1(){
char tlv84_ref;
    bzero(&tlv84_ref,1*sizeof(char));
char * tlv84 = &tlv84_ref;
    {char * temp; temp = (char *)(cgc_strlen ( tlv84 ) + 1); }
    {int ss; ss = (int)(cgc_strlen ( tlv84 ) + 1); }
    {int se; se = (int)(cgc_strlen ( tlv84 ) + 1); }
    {int tlv1; tlv1 = (int)(cgc_strlen ( tlv84 ) + 1); }
    {int tlv2; tlv2 = (int)(cgc_strlen ( tlv84 ) + 1); }
    {int tlv3; tlv3 = (int)(cgc_strlen ( tlv84 ) + 1); }
    {int tlv4; tlv4 = (int)(cgc_strlen ( tlv84 ) + 1); }
    {int tlv5; tlv5 = (int)(cgc_strlen ( tlv84 ) + 1); }
    {int tlv6; tlv6 = (int)(cgc_strlen ( tlv84 ) + 1); }
    {int tlv7; tlv7 = (int)(cgc_strlen ( tlv84 ) + 1); }
    {int tlv8; tlv8 = (int)(cgc_strlen ( tlv84 ) + 1); }
    {int tlv9; tlv9 = (int)(cgc_strlen ( tlv84 ) + 1); }
    {int tlv10; tlv10 = (int)(cgc_strlen ( tlv84 ) + 1); }
    {char tlv24; tlv24 = (char)(cgc_strlen ( tlv84 ) + 1); }
    {int tlv26; tlv26 = (int)(cgc_strlen ( tlv84 ) + 1); }
    {int tlv31; tlv31 = (int)(cgc_strlen ( tlv84 ) + 1); }
    {int tlv30; tlv30 = (int)(cgc_strlen ( tlv84 ) + 1); }
    {void * tlv12; tlv12 = (void *)(cgc_strlen ( tlv84 ) + 1); }
    {cgc_size_t tlv11; tlv11 = (cgc_size_t)(cgc_strlen ( tlv84 ) + 1); }
    {void * tlv14; tlv14 = (void *)(cgc_strlen ( tlv84 ) + 1); }
    {cgc_size_t tlv13; tlv13 = (cgc_size_t)(cgc_strlen ( tlv84 ) + 1); }
    {char tlv35; tlv35 = (char)(cgc_strlen ( tlv84 ) + 1); }
    {int tlv37; tlv37 = (int)(cgc_strlen ( tlv84 ) + 1); }
    {char tlv40; tlv40 = (char)(cgc_strlen ( tlv84 ) + 1); }
    {int tlv42; tlv42 = (int)(cgc_strlen ( tlv84 ) + 1); }
    {char tlv44; tlv44 = (char)(cgc_strlen ( tlv84 ) + 1); }
    {int tlv46; tlv46 = (int)(cgc_strlen ( tlv84 ) + 1); }
    {int tlv50; tlv50 = (int)(cgc_strlen ( tlv84 ) + 1); }
    {int tlv49; tlv49 = (int)(cgc_strlen ( tlv84 ) + 1); }
    {void * tlv16; tlv16 = (void *)(cgc_strlen ( tlv84 ) + 1); }
    {cgc_size_t tlv15; tlv15 = (cgc_size_t)(cgc_strlen ( tlv84 ) + 1); }
    {void * tlv18; tlv18 = (void *)(cgc_strlen ( tlv84 ) + 1); }
    {cgc_size_t tlv17; tlv17 = (cgc_size_t)(cgc_strlen ( tlv84 ) + 1); }
    {char tlv54; tlv54 = (char)(cgc_strlen ( tlv84 ) + 1); }
    {int tlv19; tlv19 = (int)(cgc_strlen ( tlv84 ) + 1); }
    {int tlv57; tlv57 = (int)(cgc_strlen ( tlv84 ) + 1); }
    {int tlv56; tlv56 = (int)(cgc_strlen ( tlv84 ) + 1); }
    {void * tlv22; tlv22 = (void *)(cgc_strlen ( tlv84 ) + 1); }
    {cgc_size_t tlv21; tlv21 = (cgc_size_t)(cgc_strlen ( tlv84 ) + 1); }
    {char * tlv82; tlv82 = (char *)(cgc_strlen ( tlv84 ) + 1); }
    {char * tlv83; tlv83 = (char *)(cgc_strlen ( tlv84 ) + 1); }
    {char * tlv85; tlv85 = (char *)(cgc_strlen ( tlv84 ) + 1); }
    {char * tlv86; tlv86 = (char *)(cgc_strlen ( tlv84 ) + 1); }
    {void * tlv65; tlv65 = (void *)(cgc_strlen ( tlv84 ) + 1); }
    {cgc_size_t tlv64; tlv64 = (cgc_size_t)(cgc_strlen ( tlv84 ) + 1); }
    {void * tlv67; tlv67 = (void *)(cgc_strlen ( tlv84 ) + 1); }
    {cgc_size_t tlv66; tlv66 = (cgc_size_t)(cgc_strlen ( tlv84 ) + 1); }
    {void * tlv77; tlv77 = (void *)(cgc_strlen ( tlv84 ) + 1); }
    {cgc_size_t tlv76; tlv76 = (cgc_size_t)(cgc_strlen ( tlv84 ) + 1); }
    {void * tlv79; tlv79 = (void *)(cgc_strlen ( tlv84 ) + 1); }
    {cgc_size_t tlv78; tlv78 = (cgc_size_t)(cgc_strlen ( tlv84 ) + 1); }
    {char * tlv87; tlv87 = (char *)(cgc_strlen ( tlv84 ) + 1); }
    {char * tlv88; tlv88 = (char *)(cgc_strlen ( tlv84 ) + 1); }
    {char * tlv89; tlv89 = (char *)(cgc_strlen ( tlv84 ) + 1); }
    {char * tlv90; tlv90 = (char *)(cgc_strlen ( tlv84 ) + 1); }
}
void fix_ingred_planetParsers_6_58(){
fix_ingred_planetParsers_6_58_1();
}
void fix_ingred_planetParsers_6_60_1(){
char tlv85_ref;
    bzero(&tlv85_ref,1*sizeof(char));
char * tlv85 = &tlv85_ref;
    {char * temp; temp = (char *)(cgc_strlen ( tlv85 ) + 1); }
    {int ss; ss = (int)(cgc_strlen ( tlv85 ) + 1); }
    {int se; se = (int)(cgc_strlen ( tlv85 ) + 1); }
    {int tlv1; tlv1 = (int)(cgc_strlen ( tlv85 ) + 1); }
    {int tlv2; tlv2 = (int)(cgc_strlen ( tlv85 ) + 1); }
    {int tlv3; tlv3 = (int)(cgc_strlen ( tlv85 ) + 1); }
    {int tlv4; tlv4 = (int)(cgc_strlen ( tlv85 ) + 1); }
    {int tlv5; tlv5 = (int)(cgc_strlen ( tlv85 ) + 1); }
    {int tlv6; tlv6 = (int)(cgc_strlen ( tlv85 ) + 1); }
    {int tlv7; tlv7 = (int)(cgc_strlen ( tlv85 ) + 1); }
    {int tlv8; tlv8 = (int)(cgc_strlen ( tlv85 ) + 1); }
    {int tlv9; tlv9 = (int)(cgc_strlen ( tlv85 ) + 1); }
    {int tlv10; tlv10 = (int)(cgc_strlen ( tlv85 ) + 1); }
    {char tlv24; tlv24 = (char)(cgc_strlen ( tlv85 ) + 1); }
    {int tlv26; tlv26 = (int)(cgc_strlen ( tlv85 ) + 1); }
    {int tlv31; tlv31 = (int)(cgc_strlen ( tlv85 ) + 1); }
    {int tlv30; tlv30 = (int)(cgc_strlen ( tlv85 ) + 1); }
    {void * tlv12; tlv12 = (void *)(cgc_strlen ( tlv85 ) + 1); }
    {cgc_size_t tlv11; tlv11 = (cgc_size_t)(cgc_strlen ( tlv85 ) + 1); }
    {void * tlv14; tlv14 = (void *)(cgc_strlen ( tlv85 ) + 1); }
    {cgc_size_t tlv13; tlv13 = (cgc_size_t)(cgc_strlen ( tlv85 ) + 1); }
    {char tlv35; tlv35 = (char)(cgc_strlen ( tlv85 ) + 1); }
    {int tlv37; tlv37 = (int)(cgc_strlen ( tlv85 ) + 1); }
    {char tlv40; tlv40 = (char)(cgc_strlen ( tlv85 ) + 1); }
    {int tlv42; tlv42 = (int)(cgc_strlen ( tlv85 ) + 1); }
    {char tlv44; tlv44 = (char)(cgc_strlen ( tlv85 ) + 1); }
    {int tlv46; tlv46 = (int)(cgc_strlen ( tlv85 ) + 1); }
    {int tlv50; tlv50 = (int)(cgc_strlen ( tlv85 ) + 1); }
    {int tlv49; tlv49 = (int)(cgc_strlen ( tlv85 ) + 1); }
    {void * tlv16; tlv16 = (void *)(cgc_strlen ( tlv85 ) + 1); }
    {cgc_size_t tlv15; tlv15 = (cgc_size_t)(cgc_strlen ( tlv85 ) + 1); }
    {void * tlv18; tlv18 = (void *)(cgc_strlen ( tlv85 ) + 1); }
    {cgc_size_t tlv17; tlv17 = (cgc_size_t)(cgc_strlen ( tlv85 ) + 1); }
    {char tlv54; tlv54 = (char)(cgc_strlen ( tlv85 ) + 1); }
    {int tlv19; tlv19 = (int)(cgc_strlen ( tlv85 ) + 1); }
    {int tlv57; tlv57 = (int)(cgc_strlen ( tlv85 ) + 1); }
    {int tlv56; tlv56 = (int)(cgc_strlen ( tlv85 ) + 1); }
    {void * tlv22; tlv22 = (void *)(cgc_strlen ( tlv85 ) + 1); }
    {cgc_size_t tlv21; tlv21 = (cgc_size_t)(cgc_strlen ( tlv85 ) + 1); }
    {char * tlv82; tlv82 = (char *)(cgc_strlen ( tlv85 ) + 1); }
    {char * tlv83; tlv83 = (char *)(cgc_strlen ( tlv85 ) + 1); }
    {char * tlv84; tlv84 = (char *)(cgc_strlen ( tlv85 ) + 1); }
    {char * tlv86; tlv86 = (char *)(cgc_strlen ( tlv85 ) + 1); }
    {void * tlv65; tlv65 = (void *)(cgc_strlen ( tlv85 ) + 1); }
    {cgc_size_t tlv64; tlv64 = (cgc_size_t)(cgc_strlen ( tlv85 ) + 1); }
    {void * tlv67; tlv67 = (void *)(cgc_strlen ( tlv85 ) + 1); }
    {cgc_size_t tlv66; tlv66 = (cgc_size_t)(cgc_strlen ( tlv85 ) + 1); }
    {void * tlv77; tlv77 = (void *)(cgc_strlen ( tlv85 ) + 1); }
    {cgc_size_t tlv76; tlv76 = (cgc_size_t)(cgc_strlen ( tlv85 ) + 1); }
    {void * tlv79; tlv79 = (void *)(cgc_strlen ( tlv85 ) + 1); }
    {cgc_size_t tlv78; tlv78 = (cgc_size_t)(cgc_strlen ( tlv85 ) + 1); }
    {char * tlv87; tlv87 = (char *)(cgc_strlen ( tlv85 ) + 1); }
    {char * tlv88; tlv88 = (char *)(cgc_strlen ( tlv85 ) + 1); }
    {char * tlv89; tlv89 = (char *)(cgc_strlen ( tlv85 ) + 1); }
    {char * tlv90; tlv90 = (char *)(cgc_strlen ( tlv85 ) + 1); }
}
void fix_ingred_planetParsers_6_60(){
fix_ingred_planetParsers_6_60_1();
}
void fix_ingred_planetParsers_6_65_1(){
int ss;
    bzero(&ss,sizeof(int));
    {char * temp; temp = (char *)(ss); }
    {int se; se = (int)(ss); }
    {int tlv1; tlv1 = (int)(ss); }
    {int tlv2; tlv2 = (int)(ss); }
    {int tlv3; tlv3 = (int)(ss); }
    {int tlv4; tlv4 = (int)(ss); }
    {int tlv5; tlv5 = (int)(ss); }
    {int tlv6; tlv6 = (int)(ss); }
    {int tlv7; tlv7 = (int)(ss); }
    {int tlv8; tlv8 = (int)(ss); }
    {int tlv9; tlv9 = (int)(ss); }
    {int tlv10; tlv10 = (int)(ss); }
    {char tlv24; tlv24 = (char)(ss); }
    {int tlv26; tlv26 = (int)(ss); }
    {int tlv31; tlv31 = (int)(ss); }
    {int tlv30; tlv30 = (int)(ss); }
    {void * tlv12; tlv12 = (void *)(ss); }
    {cgc_size_t tlv11; tlv11 = (cgc_size_t)(ss); }
    {void * tlv14; tlv14 = (void *)(ss); }
    {cgc_size_t tlv13; tlv13 = (cgc_size_t)(ss); }
    {char tlv35; tlv35 = (char)(ss); }
    {int tlv37; tlv37 = (int)(ss); }
    {char tlv40; tlv40 = (char)(ss); }
    {int tlv42; tlv42 = (int)(ss); }
    {char tlv44; tlv44 = (char)(ss); }
    {int tlv46; tlv46 = (int)(ss); }
    {int tlv50; tlv50 = (int)(ss); }
    {int tlv49; tlv49 = (int)(ss); }
    {void * tlv16; tlv16 = (void *)(ss); }
    {cgc_size_t tlv15; tlv15 = (cgc_size_t)(ss); }
    {void * tlv18; tlv18 = (void *)(ss); }
    {cgc_size_t tlv17; tlv17 = (cgc_size_t)(ss); }
    {char tlv54; tlv54 = (char)(ss); }
    {int tlv19; tlv19 = (int)(ss); }
    {int tlv57; tlv57 = (int)(ss); }
    {int tlv56; tlv56 = (int)(ss); }
    {void * tlv22; tlv22 = (void *)(ss); }
    {cgc_size_t tlv21; tlv21 = (cgc_size_t)(ss); }
    {char * tlv82; tlv82 = (char *)(ss); }
    {char * tlv83; tlv83 = (char *)(ss); }
    {char * tlv84; tlv84 = (char *)(ss); }
    {char * tlv85; tlv85 = (char *)(ss); }
    {char * tlv86; tlv86 = (char *)(ss); }
    {void * tlv65; tlv65 = (void *)(ss); }
    {cgc_size_t tlv64; tlv64 = (cgc_size_t)(ss); }
    {void * tlv67; tlv67 = (void *)(ss); }
    {cgc_size_t tlv66; tlv66 = (cgc_size_t)(ss); }
    {void * tlv77; tlv77 = (void *)(ss); }
    {cgc_size_t tlv76; tlv76 = (cgc_size_t)(ss); }
    {void * tlv79; tlv79 = (void *)(ss); }
    {cgc_size_t tlv78; tlv78 = (cgc_size_t)(ss); }
    {char * tlv87; tlv87 = (char *)(ss); }
    {char * tlv88; tlv88 = (char *)(ss); }
    {char * tlv89; tlv89 = (char *)(ss); }
    {char * tlv90; tlv90 = (char *)(ss); }
}
void fix_ingred_planetParsers_6_65(){
fix_ingred_planetParsers_6_65_1();
}
void fix_ingred_planetParsers_6_70_1(){
char tlv86_ref;
    bzero(&tlv86_ref,1*sizeof(char));
char * tlv86 = &tlv86_ref;
    {char * temp; temp = (char *)(cgc_strlen ( tlv86 ) + 1); }
    {int ss; ss = (int)(cgc_strlen ( tlv86 ) + 1); }
    {int se; se = (int)(cgc_strlen ( tlv86 ) + 1); }
    {int tlv1; tlv1 = (int)(cgc_strlen ( tlv86 ) + 1); }
    {int tlv2; tlv2 = (int)(cgc_strlen ( tlv86 ) + 1); }
    {int tlv3; tlv3 = (int)(cgc_strlen ( tlv86 ) + 1); }
    {int tlv4; tlv4 = (int)(cgc_strlen ( tlv86 ) + 1); }
    {int tlv5; tlv5 = (int)(cgc_strlen ( tlv86 ) + 1); }
    {int tlv6; tlv6 = (int)(cgc_strlen ( tlv86 ) + 1); }
    {int tlv7; tlv7 = (int)(cgc_strlen ( tlv86 ) + 1); }
    {int tlv8; tlv8 = (int)(cgc_strlen ( tlv86 ) + 1); }
    {int tlv9; tlv9 = (int)(cgc_strlen ( tlv86 ) + 1); }
    {int tlv10; tlv10 = (int)(cgc_strlen ( tlv86 ) + 1); }
    {char tlv24; tlv24 = (char)(cgc_strlen ( tlv86 ) + 1); }
    {int tlv26; tlv26 = (int)(cgc_strlen ( tlv86 ) + 1); }
    {int tlv31; tlv31 = (int)(cgc_strlen ( tlv86 ) + 1); }
    {int tlv30; tlv30 = (int)(cgc_strlen ( tlv86 ) + 1); }
    {void * tlv12; tlv12 = (void *)(cgc_strlen ( tlv86 ) + 1); }
    {cgc_size_t tlv11; tlv11 = (cgc_size_t)(cgc_strlen ( tlv86 ) + 1); }
    {void * tlv14; tlv14 = (void *)(cgc_strlen ( tlv86 ) + 1); }
    {cgc_size_t tlv13; tlv13 = (cgc_size_t)(cgc_strlen ( tlv86 ) + 1); }
    {char tlv35; tlv35 = (char)(cgc_strlen ( tlv86 ) + 1); }
    {int tlv37; tlv37 = (int)(cgc_strlen ( tlv86 ) + 1); }
    {char tlv40; tlv40 = (char)(cgc_strlen ( tlv86 ) + 1); }
    {int tlv42; tlv42 = (int)(cgc_strlen ( tlv86 ) + 1); }
    {char tlv44; tlv44 = (char)(cgc_strlen ( tlv86 ) + 1); }
    {int tlv46; tlv46 = (int)(cgc_strlen ( tlv86 ) + 1); }
    {int tlv50; tlv50 = (int)(cgc_strlen ( tlv86 ) + 1); }
    {int tlv49; tlv49 = (int)(cgc_strlen ( tlv86 ) + 1); }
    {void * tlv16; tlv16 = (void *)(cgc_strlen ( tlv86 ) + 1); }
    {cgc_size_t tlv15; tlv15 = (cgc_size_t)(cgc_strlen ( tlv86 ) + 1); }
    {void * tlv18; tlv18 = (void *)(cgc_strlen ( tlv86 ) + 1); }
    {cgc_size_t tlv17; tlv17 = (cgc_size_t)(cgc_strlen ( tlv86 ) + 1); }
    {char tlv54; tlv54 = (char)(cgc_strlen ( tlv86 ) + 1); }
    {int tlv19; tlv19 = (int)(cgc_strlen ( tlv86 ) + 1); }
    {int tlv57; tlv57 = (int)(cgc_strlen ( tlv86 ) + 1); }
    {int tlv56; tlv56 = (int)(cgc_strlen ( tlv86 ) + 1); }
    {void * tlv22; tlv22 = (void *)(cgc_strlen ( tlv86 ) + 1); }
    {cgc_size_t tlv21; tlv21 = (cgc_size_t)(cgc_strlen ( tlv86 ) + 1); }
    {char * tlv82; tlv82 = (char *)(cgc_strlen ( tlv86 ) + 1); }
    {char * tlv83; tlv83 = (char *)(cgc_strlen ( tlv86 ) + 1); }
    {char * tlv84; tlv84 = (char *)(cgc_strlen ( tlv86 ) + 1); }
    {char * tlv85; tlv85 = (char *)(cgc_strlen ( tlv86 ) + 1); }
    {void * tlv65; tlv65 = (void *)(cgc_strlen ( tlv86 ) + 1); }
    {cgc_size_t tlv64; tlv64 = (cgc_size_t)(cgc_strlen ( tlv86 ) + 1); }
    {void * tlv67; tlv67 = (void *)(cgc_strlen ( tlv86 ) + 1); }
    {cgc_size_t tlv66; tlv66 = (cgc_size_t)(cgc_strlen ( tlv86 ) + 1); }
    {void * tlv77; tlv77 = (void *)(cgc_strlen ( tlv86 ) + 1); }
    {cgc_size_t tlv76; tlv76 = (cgc_size_t)(cgc_strlen ( tlv86 ) + 1); }
    {void * tlv79; tlv79 = (void *)(cgc_strlen ( tlv86 ) + 1); }
    {cgc_size_t tlv78; tlv78 = (cgc_size_t)(cgc_strlen ( tlv86 ) + 1); }
    {char * tlv87; tlv87 = (char *)(cgc_strlen ( tlv86 ) + 1); }
    {char * tlv88; tlv88 = (char *)(cgc_strlen ( tlv86 ) + 1); }
    {char * tlv89; tlv89 = (char *)(cgc_strlen ( tlv86 ) + 1); }
    {char * tlv90; tlv90 = (char *)(cgc_strlen ( tlv86 ) + 1); }
}
void fix_ingred_planetParsers_6_70(){
fix_ingred_planetParsers_6_70_1();
}
void fix_ingred_planetParsers_6(){
fix_ingred_planetParsers_6_0();
fix_ingred_planetParsers_6_3();
fix_ingred_planetParsers_6_6();
fix_ingred_planetParsers_6_7();
fix_ingred_planetParsers_6_13();
fix_ingred_planetParsers_6_14();
fix_ingred_planetParsers_6_16();
fix_ingred_planetParsers_6_18();
fix_ingred_planetParsers_6_19();
fix_ingred_planetParsers_6_21();
fix_ingred_planetParsers_6_23();
fix_ingred_planetParsers_6_25();
fix_ingred_planetParsers_6_26();
fix_ingred_planetParsers_6_30();
fix_ingred_planetParsers_6_33();
fix_ingred_planetParsers_6_39();
fix_ingred_planetParsers_6_41();
fix_ingred_planetParsers_6_52();
fix_ingred_planetParsers_6_54();
fix_ingred_planetParsers_6_56();
fix_ingred_planetParsers_6_58();
fix_ingred_planetParsers_6_60();
fix_ingred_planetParsers_6_65();
fix_ingred_planetParsers_6_70();
}
void fix_ingred_planetParsers_7_0_0(){
    {char tlv22; tlv22 = (char)(NULL); }
    {int tlv24; tlv24 = (int)(NULL); }
    {int tlv29; tlv29 = (int)(NULL); }
    {char tlv33; tlv33 = (char)(NULL); }
    {int tlv35; tlv35 = (int)(NULL); }
    {char tlv38; tlv38 = (char)(NULL); }
    {int tlv40; tlv40 = (int)(NULL); }
    {char tlv42; tlv42 = (char)(NULL); }
    {int tlv44; tlv44 = (int)(NULL); }
    {int tlv48; tlv48 = (int)(NULL); }
    {char tlv52; tlv52 = (char)(NULL); }
    {int tlv55; tlv55 = (int)(NULL); }
    {void * tlv63; tlv63 = (void *)(NULL); }
    {cgc_size_t tlv62; tlv62 = (cgc_size_t)(NULL); }
    {void * tlv73; tlv73 = (void *)(NULL); }
    {cgc_size_t tlv72; tlv72 = (cgc_size_t)(NULL); }
    {char * tlv80; tlv80 = (char *)(NULL); }
}
void fix_ingred_planetParsers_7_0_1(){
    {double aphelion; aphelion = (double)(- 1.0); }
}
void fix_ingred_planetParsers_7_0_2(){
    {char tlv22; tlv22 = (char)(0); }
    {int tlv24; tlv24 = (int)(0); }
    {int tlv29; tlv29 = (int)(0); }
    {char tlv33; tlv33 = (char)(0); }
    {int tlv35; tlv35 = (int)(0); }
    {char tlv38; tlv38 = (char)(0); }
    {int tlv40; tlv40 = (int)(0); }
    {char tlv42; tlv42 = (char)(0); }
    {int tlv44; tlv44 = (int)(0); }
    {int tlv48; tlv48 = (int)(0); }
    {char tlv52; tlv52 = (char)(0); }
    {int tlv55; tlv55 = (int)(0); }
    {void * tlv63; tlv63 = (void *)(0); }
    {cgc_size_t tlv62; tlv62 = (cgc_size_t)(0); }
    {void * tlv73; tlv73 = (void *)(0); }
    {char * tlv80; tlv80 = (char *)(0); }
}
void fix_ingred_planetParsers_7_0(){
fix_ingred_planetParsers_7_0_0();
fix_ingred_planetParsers_7_0_1();
fix_ingred_planetParsers_7_0_2();
}
void fix_ingred_planetParsers_7_3_1(){
    {char tlv22; tlv22 = (char)('{'); }
    {int tlv24; tlv24 = (int)('{'); }
    {int tlv29; tlv29 = (int)('{'); }
    {char tlv33; tlv33 = (char)('{'); }
    {int tlv35; tlv35 = (int)('{'); }
    {char tlv38; tlv38 = (char)('{'); }
    {int tlv40; tlv40 = (int)('{'); }
    {char tlv42; tlv42 = (char)('{'); }
    {int tlv44; tlv44 = (int)('{'); }
    {int tlv48; tlv48 = (int)('{'); }
    {char tlv52; tlv52 = (char)('{'); }
    {int tlv55; tlv55 = (int)('{'); }
    {void * tlv63; tlv63 = (void *)('{'); }
    {cgc_size_t tlv62; tlv62 = (cgc_size_t)('{'); }
    {void * tlv73; tlv73 = (void *)('{'); }
    {cgc_size_t tlv72; tlv72 = (cgc_size_t)('{'); }
    {char * tlv80; tlv80 = (char *)('{'); }
}
void fix_ingred_planetParsers_7_3(){
fix_ingred_planetParsers_7_3_1();
}
void fix_ingred_planetParsers_7_6_1(){
    {char tlv22; tlv22 = (char)(1); }
    {int tlv24; tlv24 = (int)(1); }
    {int tlv29; tlv29 = (int)(1); }
    {char tlv33; tlv33 = (char)(1); }
    {int tlv35; tlv35 = (int)(1); }
    {char tlv38; tlv38 = (char)(1); }
    {int tlv40; tlv40 = (int)(1); }
    {char tlv42; tlv42 = (char)(1); }
    {int tlv44; tlv44 = (int)(1); }
    {int tlv48; tlv48 = (int)(1); }
    {char tlv52; tlv52 = (char)(1); }
    {int tlv55; tlv55 = (int)(1); }
    {void * tlv63; tlv63 = (void *)(1); }
    {cgc_size_t tlv62; tlv62 = (cgc_size_t)(1); }
    {void * tlv73; tlv73 = (void *)(1); }
    {char * tlv80; tlv80 = (char *)(1); }
}
void fix_ingred_planetParsers_7_6(){
fix_ingred_planetParsers_7_6_1();
}
void fix_ingred_planetParsers_7_7_6(){
int tlv2;
    bzero(&tlv2,sizeof(int));
    {char tlv22; tlv22 = (char)(tlv2); }
    {int tlv24; tlv24 = (int)(tlv2); }
    {int tlv29; tlv29 = (int)(tlv2); }
    {char tlv33; tlv33 = (char)(tlv2); }
    {int tlv35; tlv35 = (int)(tlv2); }
    {char tlv38; tlv38 = (char)(tlv2); }
    {int tlv40; tlv40 = (int)(tlv2); }
    {char tlv42; tlv42 = (char)(tlv2); }
    {int tlv44; tlv44 = (int)(tlv2); }
    {int tlv48; tlv48 = (int)(tlv2); }
    {char tlv52; tlv52 = (char)(tlv2); }
    {int tlv55; tlv55 = (int)(tlv2); }
    {void * tlv63; tlv63 = (void *)(tlv2); }
    {cgc_size_t tlv62; tlv62 = (cgc_size_t)(tlv2); }
    {void * tlv73; tlv73 = (void *)(tlv2); }
    {char * tlv80; tlv80 = (char *)(tlv2); }
}
void fix_ingred_planetParsers_7_7_7(){
int tlv2;
    bzero(&tlv2,sizeof(int));
    {char tlv22; tlv22 = (char)(- 1); }
    {int tlv24; tlv24 = (int)(- 1); }
    {int tlv29; tlv29 = (int)(- 1); }
    {char tlv33; tlv33 = (char)(- 1); }
    {int tlv35; tlv35 = (int)(- 1); }
    {char tlv38; tlv38 = (char)(- 1); }
    {int tlv40; tlv40 = (int)(- 1); }
    {char tlv42; tlv42 = (char)(- 1); }
    {int tlv44; tlv44 = (int)(- 1); }
    {int tlv48; tlv48 = (int)(- 1); }
    {char tlv52; tlv52 = (char)(- 1); }
    {int tlv55; tlv55 = (int)(- 1); }
    {void * tlv63; tlv63 = (void *)(- 1); }
    {cgc_size_t tlv62; tlv62 = (cgc_size_t)(- 1); }
    {void * tlv73; tlv73 = (void *)(- 1); }
    {cgc_size_t tlv72; tlv72 = (cgc_size_t)(- 1); }
    {char * tlv80; tlv80 = (char *)(- 1); }
}
void fix_ingred_planetParsers_7_7(){
fix_ingred_planetParsers_7_7_6();
fix_ingred_planetParsers_7_7_7();
}
void fix_ingred_planetParsers_7_11_6(){
int end;
    bzero(&end,sizeof(int));
    {char tlv22; tlv22 = (char)(end); }
    {int tlv24; tlv24 = (int)(end); }
    {int tlv29; tlv29 = (int)(end); }
    {char tlv33; tlv33 = (char)(end); }
    {int tlv35; tlv35 = (int)(end); }
    {char tlv38; tlv38 = (char)(end); }
    {int tlv40; tlv40 = (int)(end); }
    {char tlv42; tlv42 = (char)(end); }
    {int tlv44; tlv44 = (int)(end); }
    {int tlv48; tlv48 = (int)(end); }
    {char tlv52; tlv52 = (char)(end); }
    {int tlv55; tlv55 = (int)(end); }
    {void * tlv63; tlv63 = (void *)(end); }
    {cgc_size_t tlv62; tlv62 = (cgc_size_t)(end); }
    {void * tlv73; tlv73 = (void *)(end); }
    {cgc_size_t tlv72; tlv72 = (cgc_size_t)(end); }
    {char * tlv80; tlv80 = (char *)(end); }
}
void fix_ingred_planetParsers_7_11(){
fix_ingred_planetParsers_7_11_6();
}
void fix_ingred_planetParsers_7_13_1(){
int start;
    bzero(&start,sizeof(int));
    {char tlv22; tlv22 = (char)(start); }
    {int tlv24; tlv24 = (int)(start); }
    {int tlv29; tlv29 = (int)(start); }
    {char tlv33; tlv33 = (char)(start); }
    {int tlv35; tlv35 = (int)(start); }
    {char tlv38; tlv38 = (char)(start); }
    {int tlv40; tlv40 = (int)(start); }
    {char tlv42; tlv42 = (char)(start); }
    {int tlv44; tlv44 = (int)(start); }
    {int tlv48; tlv48 = (int)(start); }
    {char tlv52; tlv52 = (char)(start); }
    {int tlv55; tlv55 = (int)(start); }
    {void * tlv63; tlv63 = (void *)(start); }
    {cgc_size_t tlv62; tlv62 = (cgc_size_t)(start); }
    {void * tlv73; tlv73 = (void *)(start); }
    {cgc_size_t tlv72; tlv72 = (cgc_size_t)(start); }
    {char * tlv80; tlv80 = (char *)(start); }
}
void fix_ingred_planetParsers_7_13(){
fix_ingred_planetParsers_7_13_1();
}
void fix_ingred_planetParsers_7_14_6(){
char temp_ref;
    bzero(&temp_ref,1*sizeof(char));
char * temp = &temp_ref;
    {char tlv22; tlv22 = (char)(temp); }
    {int tlv24; tlv24 = (int)(temp); }
    {int tlv29; tlv29 = (int)(temp); }
    {char tlv33; tlv33 = (char)(temp); }
    {int tlv35; tlv35 = (int)(temp); }
    {char tlv38; tlv38 = (char)(temp); }
    {int tlv40; tlv40 = (int)(temp); }
    {char tlv42; tlv42 = (char)(temp); }
    {int tlv44; tlv44 = (int)(temp); }
    {int tlv48; tlv48 = (int)(temp); }
    {char tlv52; tlv52 = (char)(temp); }
    {int tlv55; tlv55 = (int)(temp); }
    {void * tlv63; tlv63 = (void *)(temp); }
    {cgc_size_t tlv62; tlv62 = (cgc_size_t)(temp); }
    {void * tlv73; tlv73 = (void *)(temp); }
    {cgc_size_t tlv72; tlv72 = (cgc_size_t)(temp); }
    {char * tlv80; tlv80 = (char *)(temp); }
}
void fix_ingred_planetParsers_7_14(){
fix_ingred_planetParsers_7_14_6();
}
void fix_ingred_planetParsers_7_16_7(){
int tlv3;
    bzero(&tlv3,sizeof(int));
    {char tlv22; tlv22 = (char)(tlv3); }
    {int tlv24; tlv24 = (int)(tlv3); }
    {int tlv29; tlv29 = (int)(tlv3); }
    {char tlv33; tlv33 = (char)(tlv3); }
    {int tlv35; tlv35 = (int)(tlv3); }
    {char tlv38; tlv38 = (char)(tlv3); }
    {int tlv40; tlv40 = (int)(tlv3); }
    {char tlv42; tlv42 = (char)(tlv3); }
    {int tlv44; tlv44 = (int)(tlv3); }
    {int tlv48; tlv48 = (int)(tlv3); }
    {char tlv52; tlv52 = (char)(tlv3); }
    {int tlv55; tlv55 = (int)(tlv3); }
    {void * tlv63; tlv63 = (void *)(tlv3); }
    {cgc_size_t tlv62; tlv62 = (cgc_size_t)(tlv3); }
    {void * tlv73; tlv73 = (void *)(tlv3); }
    {cgc_size_t tlv72; tlv72 = (cgc_size_t)(tlv3); }
    {char * tlv80; tlv80 = (char *)(tlv3); }
}
void fix_ingred_planetParsers_7_16(){
fix_ingred_planetParsers_7_16_7();
}
void fix_ingred_planetParsers_7_18_0(){
char temp_ref;
    bzero(&temp_ref,1*sizeof(char));
char * temp = &temp_ref;
    {char tlv22; tlv22 = (char)(temp); }
    {int tlv24; tlv24 = (int)(temp); }
    {int tlv29; tlv29 = (int)(temp); }
    {char tlv33; tlv33 = (char)(temp); }
    {int tlv35; tlv35 = (int)(temp); }
    {char tlv38; tlv38 = (char)(temp); }
    {int tlv40; tlv40 = (int)(temp); }
    {char tlv42; tlv42 = (char)(temp); }
    {int tlv44; tlv44 = (int)(temp); }
    {int tlv48; tlv48 = (int)(temp); }
    {char tlv52; tlv52 = (char)(temp); }
    {int tlv55; tlv55 = (int)(temp); }
    {void * tlv63; tlv63 = (void *)(temp); }
    {cgc_size_t tlv62; tlv62 = (cgc_size_t)(temp); }
    {void * tlv73; tlv73 = (void *)(temp); }
    {cgc_size_t tlv72; tlv72 = (cgc_size_t)(temp); }
    {char * tlv80; tlv80 = (char *)(temp); }
}
void fix_ingred_planetParsers_7_18(){
fix_ingred_planetParsers_7_18_0();
}
void fix_ingred_planetParsers_7_19_1(){
char tlv79_ref;
    bzero(&tlv79_ref,1*sizeof(char));
char * tlv79 = &tlv79_ref;
    {char tlv22; tlv22 = (char)(cgc_strlen ( tlv79 ) + 1); }
    {int tlv24; tlv24 = (int)(cgc_strlen ( tlv79 ) + 1); }
    {int tlv29; tlv29 = (int)(cgc_strlen ( tlv79 ) + 1); }
    {char tlv33; tlv33 = (char)(cgc_strlen ( tlv79 ) + 1); }
    {int tlv35; tlv35 = (int)(cgc_strlen ( tlv79 ) + 1); }
    {char tlv38; tlv38 = (char)(cgc_strlen ( tlv79 ) + 1); }
    {int tlv40; tlv40 = (int)(cgc_strlen ( tlv79 ) + 1); }
    {char tlv42; tlv42 = (char)(cgc_strlen ( tlv79 ) + 1); }
    {int tlv44; tlv44 = (int)(cgc_strlen ( tlv79 ) + 1); }
    {int tlv48; tlv48 = (int)(cgc_strlen ( tlv79 ) + 1); }
    {char tlv52; tlv52 = (char)(cgc_strlen ( tlv79 ) + 1); }
    {int tlv55; tlv55 = (int)(cgc_strlen ( tlv79 ) + 1); }
    {void * tlv63; tlv63 = (void *)(cgc_strlen ( tlv79 ) + 1); }
    {cgc_size_t tlv62; tlv62 = (cgc_size_t)(cgc_strlen ( tlv79 ) + 1); }
    {void * tlv73; tlv73 = (void *)(cgc_strlen ( tlv79 ) + 1); }
    {cgc_size_t tlv72; tlv72 = (cgc_size_t)(cgc_strlen ( tlv79 ) + 1); }
    {char * tlv80; tlv80 = (char *)(cgc_strlen ( tlv79 ) + 1); }
}
void fix_ingred_planetParsers_7_19(){
fix_ingred_planetParsers_7_19_1();
}
void fix_ingred_planetParsers_7_21_1(){
char tlv76_ref;
    bzero(&tlv76_ref,1*sizeof(char));
char * tlv76 = &tlv76_ref;
    {char tlv22; tlv22 = (char)(cgc_strlen ( tlv76 ) + 1); }
    {int tlv24; tlv24 = (int)(cgc_strlen ( tlv76 ) + 1); }
    {int tlv29; tlv29 = (int)(cgc_strlen ( tlv76 ) + 1); }
    {char tlv33; tlv33 = (char)(cgc_strlen ( tlv76 ) + 1); }
    {int tlv35; tlv35 = (int)(cgc_strlen ( tlv76 ) + 1); }
    {char tlv38; tlv38 = (char)(cgc_strlen ( tlv76 ) + 1); }
    {int tlv40; tlv40 = (int)(cgc_strlen ( tlv76 ) + 1); }
    {char tlv42; tlv42 = (char)(cgc_strlen ( tlv76 ) + 1); }
    {int tlv44; tlv44 = (int)(cgc_strlen ( tlv76 ) + 1); }
    {int tlv48; tlv48 = (int)(cgc_strlen ( tlv76 ) + 1); }
    {char tlv52; tlv52 = (char)(cgc_strlen ( tlv76 ) + 1); }
    {int tlv55; tlv55 = (int)(cgc_strlen ( tlv76 ) + 1); }
    {void * tlv63; tlv63 = (void *)(cgc_strlen ( tlv76 ) + 1); }
    {cgc_size_t tlv62; tlv62 = (cgc_size_t)(cgc_strlen ( tlv76 ) + 1); }
    {void * tlv73; tlv73 = (void *)(cgc_strlen ( tlv76 ) + 1); }
    {cgc_size_t tlv72; tlv72 = (cgc_size_t)(cgc_strlen ( tlv76 ) + 1); }
    {char * tlv80; tlv80 = (char *)(cgc_strlen ( tlv76 ) + 1); }
}
void fix_ingred_planetParsers_7_21(){
fix_ingred_planetParsers_7_21_1();
}
void fix_ingred_planetParsers_7_22_1(){
    {char tlv22; tlv22 = (char)('}'); }
    {int tlv24; tlv24 = (int)('}'); }
    {int tlv29; tlv29 = (int)('}'); }
    {char tlv33; tlv33 = (char)('}'); }
    {int tlv35; tlv35 = (int)('}'); }
    {char tlv38; tlv38 = (char)('}'); }
    {int tlv40; tlv40 = (int)('}'); }
    {char tlv42; tlv42 = (char)('}'); }
    {int tlv44; tlv44 = (int)('}'); }
    {int tlv48; tlv48 = (int)('}'); }
    {char tlv52; tlv52 = (char)('}'); }
    {int tlv55; tlv55 = (int)('}'); }
    {void * tlv63; tlv63 = (void *)('}'); }
    {cgc_size_t tlv62; tlv62 = (cgc_size_t)('}'); }
    {void * tlv73; tlv73 = (void *)('}'); }
    {cgc_size_t tlv72; tlv72 = (cgc_size_t)('}'); }
    {char * tlv80; tlv80 = (char *)('}'); }
}
void fix_ingred_planetParsers_7_22(){
fix_ingred_planetParsers_7_22_1();
}
void fix_ingred_planetParsers_7_26_6(){
int tlv5;
    bzero(&tlv5,sizeof(int));
    {char tlv22; tlv22 = (char)(tlv5); }
    {int tlv24; tlv24 = (int)(tlv5); }
    {int tlv29; tlv29 = (int)(tlv5); }
    {char tlv33; tlv33 = (char)(tlv5); }
    {int tlv35; tlv35 = (int)(tlv5); }
    {char tlv38; tlv38 = (char)(tlv5); }
    {int tlv40; tlv40 = (int)(tlv5); }
    {char tlv42; tlv42 = (char)(tlv5); }
    {int tlv44; tlv44 = (int)(tlv5); }
    {int tlv48; tlv48 = (int)(tlv5); }
    {char tlv52; tlv52 = (char)(tlv5); }
    {int tlv55; tlv55 = (int)(tlv5); }
    {void * tlv63; tlv63 = (void *)(tlv5); }
    {cgc_size_t tlv62; tlv62 = (cgc_size_t)(tlv5); }
    {void * tlv73; tlv73 = (void *)(tlv5); }
    {cgc_size_t tlv72; tlv72 = (cgc_size_t)(tlv5); }
    {char * tlv80; tlv80 = (char *)(tlv5); }
}
void fix_ingred_planetParsers_7_26(){
fix_ingred_planetParsers_7_26_6();
}
void fix_ingred_planetParsers_7_28_1(){
int ps;
    bzero(&ps,sizeof(int));
    {char tlv22; tlv22 = (char)(& ps); }
    {int tlv24; tlv24 = (int)(& ps); }
    {int tlv29; tlv29 = (int)(& ps); }
    {char tlv33; tlv33 = (char)(& ps); }
    {int tlv35; tlv35 = (int)(& ps); }
    {char tlv38; tlv38 = (char)(& ps); }
    {int tlv40; tlv40 = (int)(& ps); }
    {char tlv42; tlv42 = (char)(& ps); }
    {int tlv44; tlv44 = (int)(& ps); }
    {int tlv48; tlv48 = (int)(& ps); }
    {char tlv52; tlv52 = (char)(& ps); }
    {int tlv55; tlv55 = (int)(& ps); }
    {void * tlv63; tlv63 = (void *)(& ps); }
    {cgc_size_t tlv62; tlv62 = (cgc_size_t)(& ps); }
    {void * tlv73; tlv73 = (void *)(& ps); }
    {cgc_size_t tlv72; tlv72 = (cgc_size_t)(& ps); }
    {char * tlv80; tlv80 = (char *)(& ps); }
}
void fix_ingred_planetParsers_7_28(){
fix_ingred_planetParsers_7_28_1();
}
void fix_ingred_planetParsers_7_30_6(){
int pe;
    bzero(&pe,sizeof(int));
    {char tlv22; tlv22 = (char)(pe); }
    {int tlv24; tlv24 = (int)(pe); }
    {int tlv29; tlv29 = (int)(pe); }
    {char tlv33; tlv33 = (char)(pe); }
    {int tlv35; tlv35 = (int)(pe); }
    {char tlv38; tlv38 = (char)(pe); }
    {int tlv40; tlv40 = (int)(pe); }
    {char tlv42; tlv42 = (char)(pe); }
    {int tlv44; tlv44 = (int)(pe); }
    {int tlv48; tlv48 = (int)(pe); }
    {char tlv52; tlv52 = (char)(pe); }
    {int tlv55; tlv55 = (int)(pe); }
    {void * tlv63; tlv63 = (void *)(pe); }
    {cgc_size_t tlv62; tlv62 = (cgc_size_t)(pe); }
    {void * tlv73; tlv73 = (void *)(pe); }
    {cgc_size_t tlv72; tlv72 = (cgc_size_t)(pe); }
    {char * tlv80; tlv80 = (char *)(pe); }
}
void fix_ingred_planetParsers_7_30(){
fix_ingred_planetParsers_7_30_6();
}
void fix_ingred_planetParsers_7_36_6(){
int tlv7;
    bzero(&tlv7,sizeof(int));
    {char tlv22; tlv22 = (char)(tlv7); }
    {int tlv24; tlv24 = (int)(tlv7); }
    {int tlv29; tlv29 = (int)(tlv7); }
    {char tlv33; tlv33 = (char)(tlv7); }
    {int tlv35; tlv35 = (int)(tlv7); }
    {char tlv38; tlv38 = (char)(tlv7); }
    {int tlv40; tlv40 = (int)(tlv7); }
    {char tlv42; tlv42 = (char)(tlv7); }
    {int tlv44; tlv44 = (int)(tlv7); }
    {int tlv48; tlv48 = (int)(tlv7); }
    {char tlv52; tlv52 = (char)(tlv7); }
    {int tlv55; tlv55 = (int)(tlv7); }
    {void * tlv63; tlv63 = (void *)(tlv7); }
    {cgc_size_t tlv62; tlv62 = (cgc_size_t)(tlv7); }
    {void * tlv73; tlv73 = (void *)(tlv7); }
    {cgc_size_t tlv72; tlv72 = (cgc_size_t)(tlv7); }
    {char * tlv80; tlv80 = (char *)(tlv7); }
}
void fix_ingred_planetParsers_7_36(){
fix_ingred_planetParsers_7_36_6();
}
void fix_ingred_planetParsers_7_38_1(){
    {char tlv22; tlv22 = (char)('#'); }
    {int tlv24; tlv24 = (int)('#'); }
    {int tlv29; tlv29 = (int)('#'); }
    {char tlv33; tlv33 = (char)('#'); }
    {int tlv35; tlv35 = (int)('#'); }
    {char tlv38; tlv38 = (char)('#'); }
    {int tlv40; tlv40 = (int)('#'); }
    {char tlv42; tlv42 = (char)('#'); }
    {int tlv44; tlv44 = (int)('#'); }
    {int tlv48; tlv48 = (int)('#'); }
    {char tlv52; tlv52 = (char)('#'); }
    {int tlv55; tlv55 = (int)('#'); }
    {void * tlv63; tlv63 = (void *)('#'); }
    {cgc_size_t tlv62; tlv62 = (cgc_size_t)('#'); }
    {void * tlv73; tlv73 = (void *)('#'); }
    {cgc_size_t tlv72; tlv72 = (cgc_size_t)('#'); }
    {char * tlv80; tlv80 = (char *)('#'); }
}
void fix_ingred_planetParsers_7_38(){
fix_ingred_planetParsers_7_38_1();
}
void fix_ingred_planetParsers_7_49_6(){
int tlv9;
    bzero(&tlv9,sizeof(int));
    {char tlv22; tlv22 = (char)(tlv9); }
    {int tlv24; tlv24 = (int)(tlv9); }
    {int tlv29; tlv29 = (int)(tlv9); }
    {char tlv33; tlv33 = (char)(tlv9); }
    {int tlv35; tlv35 = (int)(tlv9); }
    {char tlv38; tlv38 = (char)(tlv9); }
    {int tlv40; tlv40 = (int)(tlv9); }
    {char tlv42; tlv42 = (char)(tlv9); }
    {int tlv44; tlv44 = (int)(tlv9); }
    {int tlv48; tlv48 = (int)(tlv9); }
    {char tlv52; tlv52 = (char)(tlv9); }
    {int tlv55; tlv55 = (int)(tlv9); }
    {void * tlv63; tlv63 = (void *)(tlv9); }
    {cgc_size_t tlv62; tlv62 = (cgc_size_t)(tlv9); }
    {void * tlv73; tlv73 = (void *)(tlv9); }
    {cgc_size_t tlv72; tlv72 = (cgc_size_t)(tlv9); }
    {char * tlv80; tlv80 = (char *)(tlv9); }
}
void fix_ingred_planetParsers_7_49(){
fix_ingred_planetParsers_7_49_6();
}
void fix_ingred_planetParsers_7_51_1(){
char tlv80_ref;
    bzero(&tlv80_ref,1*sizeof(char));
char * tlv80 = &tlv80_ref;
    {char * temp; temp = (char *)(cgc_strlen ( tlv80 ) + 1); }
    {int start; start = (int)(cgc_strlen ( tlv80 ) + 1); }
    {int end; end = (int)(cgc_strlen ( tlv80 ) + 1); }
    {int ps; ps = (int)(cgc_strlen ( tlv80 ) + 1); }
    {int pe; pe = (int)(cgc_strlen ( tlv80 ) + 1); }
    {int tlv1; tlv1 = (int)(cgc_strlen ( tlv80 ) + 1); }
    {int tlv2; tlv2 = (int)(cgc_strlen ( tlv80 ) + 1); }
    {int tlv3; tlv3 = (int)(cgc_strlen ( tlv80 ) + 1); }
    {int tlv4; tlv4 = (int)(cgc_strlen ( tlv80 ) + 1); }
    {int tlv5; tlv5 = (int)(cgc_strlen ( tlv80 ) + 1); }
    {int tlv6; tlv6 = (int)(cgc_strlen ( tlv80 ) + 1); }
    {int tlv7; tlv7 = (int)(cgc_strlen ( tlv80 ) + 1); }
    {int tlv8; tlv8 = (int)(cgc_strlen ( tlv80 ) + 1); }
    {int tlv9; tlv9 = (int)(cgc_strlen ( tlv80 ) + 1); }
    {int tlv10; tlv10 = (int)(cgc_strlen ( tlv80 ) + 1); }
    {char tlv22; tlv22 = (char)(cgc_strlen ( tlv80 ) + 1); }
    {int tlv24; tlv24 = (int)(cgc_strlen ( tlv80 ) + 1); }
    {int tlv29; tlv29 = (int)(cgc_strlen ( tlv80 ) + 1); }
    {int tlv28; tlv28 = (int)(cgc_strlen ( tlv80 ) + 1); }
    {void * tlv12; tlv12 = (void *)(cgc_strlen ( tlv80 ) + 1); }
    {cgc_size_t tlv11; tlv11 = (cgc_size_t)(cgc_strlen ( tlv80 ) + 1); }
    {char tlv33; tlv33 = (char)(cgc_strlen ( tlv80 ) + 1); }
    {int tlv35; tlv35 = (int)(cgc_strlen ( tlv80 ) + 1); }
    {int * tlv13; tlv13 = (int *)(cgc_strlen ( tlv80 ) + 1); }
    {char tlv38; tlv38 = (char)(cgc_strlen ( tlv80 ) + 1); }
    {int tlv40; tlv40 = (int)(cgc_strlen ( tlv80 ) + 1); }
    {char tlv42; tlv42 = (char)(cgc_strlen ( tlv80 ) + 1); }
    {int tlv44; tlv44 = (int)(cgc_strlen ( tlv80 ) + 1); }
    {int tlv48; tlv48 = (int)(cgc_strlen ( tlv80 ) + 1); }
    {int tlv47; tlv47 = (int)(cgc_strlen ( tlv80 ) + 1); }
    {void * tlv16; tlv16 = (void *)(cgc_strlen ( tlv80 ) + 1); }
    {cgc_size_t tlv15; tlv15 = (cgc_size_t)(cgc_strlen ( tlv80 ) + 1); }
    {char tlv52; tlv52 = (char)(cgc_strlen ( tlv80 ) + 1); }
    {int tlv17; tlv17 = (int)(cgc_strlen ( tlv80 ) + 1); }
    {int tlv55; tlv55 = (int)(cgc_strlen ( tlv80 ) + 1); }
    {int tlv54; tlv54 = (int)(cgc_strlen ( tlv80 ) + 1); }
    {void * tlv20; tlv20 = (void *)(cgc_strlen ( tlv80 ) + 1); }
    {cgc_size_t tlv19; tlv19 = (cgc_size_t)(cgc_strlen ( tlv80 ) + 1); }
    {char * tlv76; tlv76 = (char *)(cgc_strlen ( tlv80 ) + 1); }
    {char * tlv77; tlv77 = (char *)(cgc_strlen ( tlv80 ) + 1); }
    {char * tlv78; tlv78 = (char *)(cgc_strlen ( tlv80 ) + 1); }
    {void * tlv63; tlv63 = (void *)(cgc_strlen ( tlv80 ) + 1); }
    {cgc_size_t tlv62; tlv62 = (cgc_size_t)(cgc_strlen ( tlv80 ) + 1); }
    {void * tlv73; tlv73 = (void *)(cgc_strlen ( tlv80 ) + 1); }
    {cgc_size_t tlv72; tlv72 = (cgc_size_t)(cgc_strlen ( tlv80 ) + 1); }
    {char * tlv79; tlv79 = (char *)(cgc_strlen ( tlv80 ) + 1); }
}
void fix_ingred_planetParsers_7_51(){
fix_ingred_planetParsers_7_51_1();
}
void fix_ingred_planetParsers_7_53_1(){
char tlv77_ref;
    bzero(&tlv77_ref,1*sizeof(char));
char * tlv77 = &tlv77_ref;
    {char tlv22; tlv22 = (char)(cgc_strlen ( tlv77 ) + 1); }
    {int tlv24; tlv24 = (int)(cgc_strlen ( tlv77 ) + 1); }
    {int tlv29; tlv29 = (int)(cgc_strlen ( tlv77 ) + 1); }
    {char tlv33; tlv33 = (char)(cgc_strlen ( tlv77 ) + 1); }
    {int tlv35; tlv35 = (int)(cgc_strlen ( tlv77 ) + 1); }
    {char tlv38; tlv38 = (char)(cgc_strlen ( tlv77 ) + 1); }
    {int tlv40; tlv40 = (int)(cgc_strlen ( tlv77 ) + 1); }
    {char tlv42; tlv42 = (char)(cgc_strlen ( tlv77 ) + 1); }
    {int tlv44; tlv44 = (int)(cgc_strlen ( tlv77 ) + 1); }
    {int tlv48; tlv48 = (int)(cgc_strlen ( tlv77 ) + 1); }
    {char tlv52; tlv52 = (char)(cgc_strlen ( tlv77 ) + 1); }
    {int tlv55; tlv55 = (int)(cgc_strlen ( tlv77 ) + 1); }
    {void * tlv63; tlv63 = (void *)(cgc_strlen ( tlv77 ) + 1); }
    {cgc_size_t tlv62; tlv62 = (cgc_size_t)(cgc_strlen ( tlv77 ) + 1); }
    {void * tlv73; tlv73 = (void *)(cgc_strlen ( tlv77 ) + 1); }
    {cgc_size_t tlv72; tlv72 = (cgc_size_t)(cgc_strlen ( tlv77 ) + 1); }
    {char * tlv80; tlv80 = (char *)(cgc_strlen ( tlv77 ) + 1); }
}
void fix_ingred_planetParsers_7_53(){
fix_ingred_planetParsers_7_53_1();
}
void fix_ingred_planetParsers_7_58_1(){
int ps;
    bzero(&ps,sizeof(int));
    {char tlv22; tlv22 = (char)(ps); }
    {int tlv24; tlv24 = (int)(ps); }
    {int tlv29; tlv29 = (int)(ps); }
    {char tlv33; tlv33 = (char)(ps); }
    {int tlv35; tlv35 = (int)(ps); }
    {char tlv38; tlv38 = (char)(ps); }
    {int tlv40; tlv40 = (int)(ps); }
    {char tlv42; tlv42 = (char)(ps); }
    {int tlv44; tlv44 = (int)(ps); }
    {int tlv48; tlv48 = (int)(ps); }
    {char tlv52; tlv52 = (char)(ps); }
    {int tlv55; tlv55 = (int)(ps); }
    {void * tlv63; tlv63 = (void *)(ps); }
    {cgc_size_t tlv62; tlv62 = (cgc_size_t)(ps); }
    {void * tlv73; tlv73 = (void *)(ps); }
    {cgc_size_t tlv72; tlv72 = (cgc_size_t)(ps); }
    {char * tlv80; tlv80 = (char *)(ps); }
}
void fix_ingred_planetParsers_7_58(){
fix_ingred_planetParsers_7_58_1();
}
void fix_ingred_planetParsers_7_63_1(){
char tlv78_ref;
    bzero(&tlv78_ref,1*sizeof(char));
char * tlv78 = &tlv78_ref;
    {char tlv22; tlv22 = (char)(cgc_strlen ( tlv78 ) + 1); }
    {int tlv24; tlv24 = (int)(cgc_strlen ( tlv78 ) + 1); }
    {int tlv29; tlv29 = (int)(cgc_strlen ( tlv78 ) + 1); }
    {char tlv33; tlv33 = (char)(cgc_strlen ( tlv78 ) + 1); }
    {int tlv35; tlv35 = (int)(cgc_strlen ( tlv78 ) + 1); }
    {char tlv38; tlv38 = (char)(cgc_strlen ( tlv78 ) + 1); }
    {int tlv40; tlv40 = (int)(cgc_strlen ( tlv78 ) + 1); }
    {char tlv42; tlv42 = (char)(cgc_strlen ( tlv78 ) + 1); }
    {int tlv44; tlv44 = (int)(cgc_strlen ( tlv78 ) + 1); }
    {int tlv48; tlv48 = (int)(cgc_strlen ( tlv78 ) + 1); }
    {char tlv52; tlv52 = (char)(cgc_strlen ( tlv78 ) + 1); }
    {int tlv55; tlv55 = (int)(cgc_strlen ( tlv78 ) + 1); }
    {void * tlv63; tlv63 = (void *)(cgc_strlen ( tlv78 ) + 1); }
    {cgc_size_t tlv62; tlv62 = (cgc_size_t)(cgc_strlen ( tlv78 ) + 1); }
    {void * tlv73; tlv73 = (void *)(cgc_strlen ( tlv78 ) + 1); }
    {cgc_size_t tlv72; tlv72 = (cgc_size_t)(cgc_strlen ( tlv78 ) + 1); }
    {char * tlv80; tlv80 = (char *)(cgc_strlen ( tlv78 ) + 1); }
}
void fix_ingred_planetParsers_7_63(){
fix_ingred_planetParsers_7_63_1();
}
void fix_ingred_planetParsers_7(){
fix_ingred_planetParsers_7_0();
fix_ingred_planetParsers_7_3();
fix_ingred_planetParsers_7_6();
fix_ingred_planetParsers_7_7();
fix_ingred_planetParsers_7_11();
fix_ingred_planetParsers_7_13();
fix_ingred_planetParsers_7_14();
fix_ingred_planetParsers_7_16();
fix_ingred_planetParsers_7_18();
fix_ingred_planetParsers_7_19();
fix_ingred_planetParsers_7_21();
fix_ingred_planetParsers_7_22();
fix_ingred_planetParsers_7_26();
fix_ingred_planetParsers_7_28();
fix_ingred_planetParsers_7_30();
fix_ingred_planetParsers_7_36();
fix_ingred_planetParsers_7_38();
fix_ingred_planetParsers_7_49();
fix_ingred_planetParsers_7_51();
fix_ingred_planetParsers_7_53();
fix_ingred_planetParsers_7_58();
fix_ingred_planetParsers_7_63();
}
void fix_ingred_planetParsers_8_0_1(){
    {double perihelion; perihelion = (double)(- 1.0); }
}
void fix_ingred_planetParsers_8_0(){
fix_ingred_planetParsers_8_0_1();
}
void fix_ingred_planetParsers_8_21_1(){
char tlv75_ref;
    bzero(&tlv75_ref,1*sizeof(char));
char * tlv75 = &tlv75_ref;
    {char tlv22; tlv22 = (char)(cgc_strlen ( tlv75 ) + 1); }
    {int tlv24; tlv24 = (int)(cgc_strlen ( tlv75 ) + 1); }
    {int tlv29; tlv29 = (int)(cgc_strlen ( tlv75 ) + 1); }
    {char tlv33; tlv33 = (char)(cgc_strlen ( tlv75 ) + 1); }
    {int tlv35; tlv35 = (int)(cgc_strlen ( tlv75 ) + 1); }
    {char tlv38; tlv38 = (char)(cgc_strlen ( tlv75 ) + 1); }
}
void fix_ingred_planetParsers_8_21(){
fix_ingred_planetParsers_8_21_1();
}
void fix_ingred_planetParsers_8(){
fix_ingred_planetParsers_8_0();
fix_ingred_planetParsers_8_21();
}
void fix_ingred_planetParsers_9_0_0(){
    {int rs; rs = (int)(NULL); }
    {int re; re = (int)(NULL); }
    {char tlv36; tlv36 = (char)(NULL); }
    {char tlv39; tlv39 = (char)(NULL); }
    {char tlv48; tlv48 = (char)(NULL); }
    {int tlv51; tlv51 = (int)(NULL); }
    {char * tlv72; tlv72 = (char *)(NULL); }
    {char * tlv73; tlv73 = (char *)(NULL); }
    {char * tlv74; tlv74 = (char *)(NULL); }
    {void * tlv59; tlv59 = (void *)(NULL); }
    {cgc_size_t tlv58; tlv58 = (cgc_size_t)(NULL); }
    {void * tlv69; tlv69 = (void *)(NULL); }
    {cgc_size_t tlv68; tlv68 = (cgc_size_t)(NULL); }
}
void fix_ingred_planetParsers_9_0_1(){
    {double radius; radius = (double)(- 1.0); }
}
void fix_ingred_planetParsers_9_0_2(){
    {int rs; rs = (int)(0); }
    {int re; re = (int)(0); }
    {char tlv36; tlv36 = (char)(0); }
    {char tlv39; tlv39 = (char)(0); }
    {char tlv48; tlv48 = (char)(0); }
    {int tlv51; tlv51 = (int)(0); }
    {char * tlv72; tlv72 = (char *)(0); }
    {char * tlv73; tlv73 = (char *)(0); }
    {char * tlv74; tlv74 = (char *)(0); }
    {void * tlv59; tlv59 = (void *)(0); }
    {void * tlv69; tlv69 = (void *)(0); }
    {cgc_size_t tlv68; tlv68 = (cgc_size_t)(0); }
}
void fix_ingred_planetParsers_9_0(){
fix_ingred_planetParsers_9_0_0();
fix_ingred_planetParsers_9_0_1();
fix_ingred_planetParsers_9_0_2();
}
void fix_ingred_planetParsers_9_3_1(){
    {int rs; rs = (int)('{'); }
    {int re; re = (int)('{'); }
    {char tlv36; tlv36 = (char)('{'); }
    {char tlv39; tlv39 = (char)('{'); }
    {char tlv48; tlv48 = (char)('{'); }
    {int tlv51; tlv51 = (int)('{'); }
    {char * tlv72; tlv72 = (char *)('{'); }
    {char * tlv73; tlv73 = (char *)('{'); }
    {char * tlv74; tlv74 = (char *)('{'); }
    {void * tlv59; tlv59 = (void *)('{'); }
    {cgc_size_t tlv58; tlv58 = (cgc_size_t)('{'); }
    {void * tlv69; tlv69 = (void *)('{'); }
    {cgc_size_t tlv68; tlv68 = (cgc_size_t)('{'); }
}
void fix_ingred_planetParsers_9_3(){
fix_ingred_planetParsers_9_3_1();
}
void fix_ingred_planetParsers_9_7_6(){
int tlv2;
    bzero(&tlv2,sizeof(int));
    {int rs; rs = (int)(tlv2); }
    {int re; re = (int)(tlv2); }
    {char tlv36; tlv36 = (char)(tlv2); }
    {char tlv39; tlv39 = (char)(tlv2); }
    {char tlv48; tlv48 = (char)(tlv2); }
    {int tlv51; tlv51 = (int)(tlv2); }
    {char * tlv72; tlv72 = (char *)(tlv2); }
    {char * tlv73; tlv73 = (char *)(tlv2); }
    {char * tlv74; tlv74 = (char *)(tlv2); }
    {void * tlv59; tlv59 = (void *)(tlv2); }
    {void * tlv69; tlv69 = (void *)(tlv2); }
    {cgc_size_t tlv68; tlv68 = (cgc_size_t)(tlv2); }
}
void fix_ingred_planetParsers_9_7_7(){
int tlv2;
    bzero(&tlv2,sizeof(int));
    {int rs; rs = (int)(- 1); }
    {int re; re = (int)(- 1); }
    {char tlv36; tlv36 = (char)(- 1); }
    {char tlv39; tlv39 = (char)(- 1); }
    {char tlv48; tlv48 = (char)(- 1); }
    {int tlv51; tlv51 = (int)(- 1); }
    {char * tlv72; tlv72 = (char *)(- 1); }
    {char * tlv73; tlv73 = (char *)(- 1); }
    {char * tlv74; tlv74 = (char *)(- 1); }
    {void * tlv59; tlv59 = (void *)(- 1); }
    {cgc_size_t tlv58; tlv58 = (cgc_size_t)(- 1); }
    {void * tlv69; tlv69 = (void *)(- 1); }
    {cgc_size_t tlv68; tlv68 = (cgc_size_t)(- 1); }
}
void fix_ingred_planetParsers_9_7(){
fix_ingred_planetParsers_9_7_6();
fix_ingred_planetParsers_9_7_7();
}
void fix_ingred_planetParsers_9_11_6(){
int end;
    bzero(&end,sizeof(int));
    {int rs; rs = (int)(end); }
    {int re; re = (int)(end); }
    {char tlv36; tlv36 = (char)(end); }
    {char tlv39; tlv39 = (char)(end); }
    {char tlv48; tlv48 = (char)(end); }
    {int tlv51; tlv51 = (int)(end); }
    {char * tlv72; tlv72 = (char *)(end); }
    {char * tlv73; tlv73 = (char *)(end); }
    {char * tlv74; tlv74 = (char *)(end); }
    {void * tlv59; tlv59 = (void *)(end); }
    {cgc_size_t tlv58; tlv58 = (cgc_size_t)(end); }
    {void * tlv69; tlv69 = (void *)(end); }
    {cgc_size_t tlv68; tlv68 = (cgc_size_t)(end); }
}
void fix_ingred_planetParsers_9_11(){
fix_ingred_planetParsers_9_11_6();
}
void fix_ingred_planetParsers_9_13_1(){
int start;
    bzero(&start,sizeof(int));
    {int rs; rs = (int)(start); }
    {int re; re = (int)(start); }
    {char tlv36; tlv36 = (char)(start); }
    {char tlv39; tlv39 = (char)(start); }
    {char tlv48; tlv48 = (char)(start); }
    {int tlv51; tlv51 = (int)(start); }
    {char * tlv72; tlv72 = (char *)(start); }
    {char * tlv73; tlv73 = (char *)(start); }
    {char * tlv74; tlv74 = (char *)(start); }
    {void * tlv59; tlv59 = (void *)(start); }
    {cgc_size_t tlv58; tlv58 = (cgc_size_t)(start); }
    {void * tlv69; tlv69 = (void *)(start); }
    {cgc_size_t tlv68; tlv68 = (cgc_size_t)(start); }
}
void fix_ingred_planetParsers_9_13(){
fix_ingred_planetParsers_9_13_1();
}
void fix_ingred_planetParsers_9_14_6(){
char temp_ref;
    bzero(&temp_ref,1*sizeof(char));
char * temp = &temp_ref;
    {int rs; rs = (int)(temp); }
    {int re; re = (int)(temp); }
    {char tlv36; tlv36 = (char)(temp); }
    {char tlv39; tlv39 = (char)(temp); }
    {char tlv48; tlv48 = (char)(temp); }
    {int tlv51; tlv51 = (int)(temp); }
    {char * tlv72; tlv72 = (char *)(temp); }
    {char * tlv73; tlv73 = (char *)(temp); }
    {char * tlv74; tlv74 = (char *)(temp); }
    {void * tlv59; tlv59 = (void *)(temp); }
    {cgc_size_t tlv58; tlv58 = (cgc_size_t)(temp); }
    {void * tlv69; tlv69 = (void *)(temp); }
    {cgc_size_t tlv68; tlv68 = (cgc_size_t)(temp); }
}
void fix_ingred_planetParsers_9_14(){
fix_ingred_planetParsers_9_14_6();
}
void fix_ingred_planetParsers_9_16_7(){
int tlv3;
    bzero(&tlv3,sizeof(int));
    {int rs; rs = (int)(tlv3); }
    {int re; re = (int)(tlv3); }
    {char tlv36; tlv36 = (char)(tlv3); }
    {char tlv39; tlv39 = (char)(tlv3); }
    {char tlv48; tlv48 = (char)(tlv3); }
    {int tlv51; tlv51 = (int)(tlv3); }
    {char * tlv72; tlv72 = (char *)(tlv3); }
    {char * tlv73; tlv73 = (char *)(tlv3); }
    {char * tlv74; tlv74 = (char *)(tlv3); }
    {void * tlv59; tlv59 = (void *)(tlv3); }
    {cgc_size_t tlv58; tlv58 = (cgc_size_t)(tlv3); }
    {void * tlv69; tlv69 = (void *)(tlv3); }
    {cgc_size_t tlv68; tlv68 = (cgc_size_t)(tlv3); }
}
void fix_ingred_planetParsers_9_16(){
fix_ingred_planetParsers_9_16_7();
}
void fix_ingred_planetParsers_9_18_0(){
char temp_ref;
    bzero(&temp_ref,1*sizeof(char));
char * temp = &temp_ref;
    {int rs; rs = (int)(temp); }
    {int re; re = (int)(temp); }
    {char tlv36; tlv36 = (char)(temp); }
    {char tlv39; tlv39 = (char)(temp); }
    {char tlv48; tlv48 = (char)(temp); }
    {int tlv51; tlv51 = (int)(temp); }
    {char * tlv72; tlv72 = (char *)(temp); }
    {char * tlv73; tlv73 = (char *)(temp); }
    {char * tlv74; tlv74 = (char *)(temp); }
    {void * tlv59; tlv59 = (void *)(temp); }
    {cgc_size_t tlv58; tlv58 = (cgc_size_t)(temp); }
    {void * tlv69; tlv69 = (void *)(temp); }
    {cgc_size_t tlv68; tlv68 = (cgc_size_t)(temp); }
}
void fix_ingred_planetParsers_9_18(){
fix_ingred_planetParsers_9_18_0();
}
void fix_ingred_planetParsers_9_19_1(){
char tlv75_ref;
    bzero(&tlv75_ref,1*sizeof(char));
char * tlv75 = &tlv75_ref;
    {int rs; rs = (int)(cgc_strlen ( tlv75 ) + 1); }
    {int re; re = (int)(cgc_strlen ( tlv75 ) + 1); }
    {char tlv36; tlv36 = (char)(cgc_strlen ( tlv75 ) + 1); }
    {char tlv39; tlv39 = (char)(cgc_strlen ( tlv75 ) + 1); }
    {int tlv44; tlv44 = (int)(cgc_strlen ( tlv75 ) + 1); }
    {char tlv48; tlv48 = (char)(cgc_strlen ( tlv75 ) + 1); }
    {int tlv51; tlv51 = (int)(cgc_strlen ( tlv75 ) + 1); }
    {int tlv50; tlv50 = (int)(cgc_strlen ( tlv75 ) + 1); }
    {char * tlv72; tlv72 = (char *)(cgc_strlen ( tlv75 ) + 1); }
    {char * tlv73; tlv73 = (char *)(cgc_strlen ( tlv75 ) + 1); }
    {char * tlv74; tlv74 = (char *)(cgc_strlen ( tlv75 ) + 1); }
    {void * tlv59; tlv59 = (void *)(cgc_strlen ( tlv75 ) + 1); }
    {cgc_size_t tlv58; tlv58 = (cgc_size_t)(cgc_strlen ( tlv75 ) + 1); }
    {void * tlv69; tlv69 = (void *)(cgc_strlen ( tlv75 ) + 1); }
    {cgc_size_t tlv68; tlv68 = (cgc_size_t)(cgc_strlen ( tlv75 ) + 1); }
}
void fix_ingred_planetParsers_9_19(){
fix_ingred_planetParsers_9_19_1();
}
void fix_ingred_planetParsers_9_21_1(){
char tlv72_ref;
    bzero(&tlv72_ref,1*sizeof(char));
char * tlv72 = &tlv72_ref;
    {char * temp; temp = (char *)(cgc_strlen ( tlv72 ) + 1); }
    {int start; start = (int)(cgc_strlen ( tlv72 ) + 1); }
    {int end; end = (int)(cgc_strlen ( tlv72 ) + 1); }
    {int rs; rs = (int)(cgc_strlen ( tlv72 ) + 1); }
    {int re; re = (int)(cgc_strlen ( tlv72 ) + 1); }
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
    {char tlv22; tlv22 = (char)(cgc_strlen ( tlv72 ) + 1); }
    {int tlv28; tlv28 = (int)(cgc_strlen ( tlv72 ) + 1); }
    {int tlv27; tlv27 = (int)(cgc_strlen ( tlv72 ) + 1); }
    {void * tlv12; tlv12 = (void *)(cgc_strlen ( tlv72 ) + 1); }
    {cgc_size_t tlv11; tlv11 = (cgc_size_t)(cgc_strlen ( tlv72 ) + 1); }
    {char tlv32; tlv32 = (char)(cgc_strlen ( tlv72 ) + 1); }
    {int * tlv13; tlv13 = (int *)(cgc_strlen ( tlv72 ) + 1); }
    {char tlv36; tlv36 = (char)(cgc_strlen ( tlv72 ) + 1); }
    {char tlv39; tlv39 = (char)(cgc_strlen ( tlv72 ) + 1); }
    {int tlv44; tlv44 = (int)(cgc_strlen ( tlv72 ) + 1); }
    {int tlv43; tlv43 = (int)(cgc_strlen ( tlv72 ) + 1); }
    {void * tlv16; tlv16 = (void *)(cgc_strlen ( tlv72 ) + 1); }
    {cgc_size_t tlv15; tlv15 = (cgc_size_t)(cgc_strlen ( tlv72 ) + 1); }
    {char tlv48; tlv48 = (char)(cgc_strlen ( tlv72 ) + 1); }
    {int tlv17; tlv17 = (int)(cgc_strlen ( tlv72 ) + 1); }
    {int tlv51; tlv51 = (int)(cgc_strlen ( tlv72 ) + 1); }
    {int tlv50; tlv50 = (int)(cgc_strlen ( tlv72 ) + 1); }
    {void * tlv20; tlv20 = (void *)(cgc_strlen ( tlv72 ) + 1); }
    {cgc_size_t tlv19; tlv19 = (cgc_size_t)(cgc_strlen ( tlv72 ) + 1); }
    {char * tlv73; tlv73 = (char *)(cgc_strlen ( tlv72 ) + 1); }
    {char * tlv74; tlv74 = (char *)(cgc_strlen ( tlv72 ) + 1); }
    {void * tlv59; tlv59 = (void *)(cgc_strlen ( tlv72 ) + 1); }
    {cgc_size_t tlv58; tlv58 = (cgc_size_t)(cgc_strlen ( tlv72 ) + 1); }
    {void * tlv69; tlv69 = (void *)(cgc_strlen ( tlv72 ) + 1); }
    {cgc_size_t tlv68; tlv68 = (cgc_size_t)(cgc_strlen ( tlv72 ) + 1); }
    {char * tlv75; tlv75 = (char *)(cgc_strlen ( tlv72 ) + 1); }
    {char * tlv76; tlv76 = (char *)(cgc_strlen ( tlv72 ) + 1); }
}
void fix_ingred_planetParsers_9_21(){
fix_ingred_planetParsers_9_21_1();
}
void fix_ingred_planetParsers_9_22_1(){
    {int rs; rs = (int)('}'); }
    {int re; re = (int)('}'); }
    {char tlv36; tlv36 = (char)('}'); }
    {char tlv39; tlv39 = (char)('}'); }
    {char tlv48; tlv48 = (char)('}'); }
    {int tlv51; tlv51 = (int)('}'); }
    {char * tlv72; tlv72 = (char *)('}'); }
    {char * tlv73; tlv73 = (char *)('}'); }
    {char * tlv74; tlv74 = (char *)('}'); }
    {void * tlv59; tlv59 = (void *)('}'); }
    {cgc_size_t tlv58; tlv58 = (cgc_size_t)('}'); }
    {void * tlv69; tlv69 = (void *)('}'); }
    {cgc_size_t tlv68; tlv68 = (cgc_size_t)('}'); }
}
void fix_ingred_planetParsers_9_22(){
fix_ingred_planetParsers_9_22_1();
}
void fix_ingred_planetParsers_9_26_6(){
int tlv5;
    bzero(&tlv5,sizeof(int));
    {int rs; rs = (int)(tlv5); }
    {int re; re = (int)(tlv5); }
    {char tlv36; tlv36 = (char)(tlv5); }
    {char tlv39; tlv39 = (char)(tlv5); }
    {char tlv48; tlv48 = (char)(tlv5); }
    {int tlv51; tlv51 = (int)(tlv5); }
    {char * tlv72; tlv72 = (char *)(tlv5); }
    {char * tlv73; tlv73 = (char *)(tlv5); }
    {char * tlv74; tlv74 = (char *)(tlv5); }
    {void * tlv59; tlv59 = (void *)(tlv5); }
    {cgc_size_t tlv58; tlv58 = (cgc_size_t)(tlv5); }
    {void * tlv69; tlv69 = (void *)(tlv5); }
    {cgc_size_t tlv68; tlv68 = (cgc_size_t)(tlv5); }
}
void fix_ingred_planetParsers_9_26(){
fix_ingred_planetParsers_9_26_6();
}
void fix_ingred_planetParsers_9_28_1(){
int rs;
    bzero(&rs,sizeof(int));
    {char * temp; temp = (char *)(& rs); }
    {int start; start = (int)(& rs); }
    {int end; end = (int)(& rs); }
    {int re; re = (int)(& rs); }
    {int tlv1; tlv1 = (int)(& rs); }
    {int tlv2; tlv2 = (int)(& rs); }
    {int tlv3; tlv3 = (int)(& rs); }
    {int tlv4; tlv4 = (int)(& rs); }
    {int tlv5; tlv5 = (int)(& rs); }
    {int tlv6; tlv6 = (int)(& rs); }
    {int tlv7; tlv7 = (int)(& rs); }
    {int tlv8; tlv8 = (int)(& rs); }
    {int tlv9; tlv9 = (int)(& rs); }
    {int tlv10; tlv10 = (int)(& rs); }
    {char tlv22; tlv22 = (char)(& rs); }
    {int tlv28; tlv28 = (int)(& rs); }
    {int tlv27; tlv27 = (int)(& rs); }
    {void * tlv12; tlv12 = (void *)(& rs); }
    {cgc_size_t tlv11; tlv11 = (cgc_size_t)(& rs); }
    {char tlv32; tlv32 = (char)(& rs); }
    {int * tlv13; tlv13 = (int *)(& rs); }
    {char tlv36; tlv36 = (char)(& rs); }
    {char tlv39; tlv39 = (char)(& rs); }
    {int tlv44; tlv44 = (int)(& rs); }
    {int tlv43; tlv43 = (int)(& rs); }
    {void * tlv16; tlv16 = (void *)(& rs); }
    {cgc_size_t tlv15; tlv15 = (cgc_size_t)(& rs); }
    {char tlv48; tlv48 = (char)(& rs); }
    {int tlv17; tlv17 = (int)(& rs); }
    {int tlv51; tlv51 = (int)(& rs); }
    {int tlv50; tlv50 = (int)(& rs); }
    {void * tlv20; tlv20 = (void *)(& rs); }
    {cgc_size_t tlv19; tlv19 = (cgc_size_t)(& rs); }
    {char * tlv72; tlv72 = (char *)(& rs); }
    {char * tlv73; tlv73 = (char *)(& rs); }
    {char * tlv74; tlv74 = (char *)(& rs); }
    {void * tlv59; tlv59 = (void *)(& rs); }
    {cgc_size_t tlv58; tlv58 = (cgc_size_t)(& rs); }
    {void * tlv69; tlv69 = (void *)(& rs); }
    {cgc_size_t tlv68; tlv68 = (cgc_size_t)(& rs); }
    {char * tlv75; tlv75 = (char *)(& rs); }
    {char * tlv76; tlv76 = (char *)(& rs); }
}
void fix_ingred_planetParsers_9_28(){
fix_ingred_planetParsers_9_28_1();
}
void fix_ingred_planetParsers_9_30_6(){
int re;
    bzero(&re,sizeof(int));
    {char * temp; temp = (char *)(re); }
    {int start; start = (int)(re); }
    {int end; end = (int)(re); }
    {int rs; rs = (int)(re); }
    {int tlv1; tlv1 = (int)(re); }
    {int tlv2; tlv2 = (int)(re); }
    {int tlv3; tlv3 = (int)(re); }
    {int tlv4; tlv4 = (int)(re); }
    {int tlv5; tlv5 = (int)(re); }
    {int tlv6; tlv6 = (int)(re); }
    {int tlv7; tlv7 = (int)(re); }
    {int tlv8; tlv8 = (int)(re); }
    {int tlv9; tlv9 = (int)(re); }
    {int tlv10; tlv10 = (int)(re); }
    {char tlv22; tlv22 = (char)(re); }
    {int tlv28; tlv28 = (int)(re); }
    {int tlv27; tlv27 = (int)(re); }
    {void * tlv12; tlv12 = (void *)(re); }
    {cgc_size_t tlv11; tlv11 = (cgc_size_t)(re); }
    {char tlv32; tlv32 = (char)(re); }
    {int * tlv13; tlv13 = (int *)(re); }
    {char tlv36; tlv36 = (char)(re); }
    {char tlv39; tlv39 = (char)(re); }
    {int tlv44; tlv44 = (int)(re); }
    {int tlv43; tlv43 = (int)(re); }
    {void * tlv16; tlv16 = (void *)(re); }
    {cgc_size_t tlv15; tlv15 = (cgc_size_t)(re); }
    {char tlv48; tlv48 = (char)(re); }
    {int tlv17; tlv17 = (int)(re); }
    {int tlv51; tlv51 = (int)(re); }
    {int tlv50; tlv50 = (int)(re); }
    {void * tlv20; tlv20 = (void *)(re); }
    {cgc_size_t tlv19; tlv19 = (cgc_size_t)(re); }
    {char * tlv72; tlv72 = (char *)(re); }
    {char * tlv73; tlv73 = (char *)(re); }
    {char * tlv74; tlv74 = (char *)(re); }
    {void * tlv59; tlv59 = (void *)(re); }
    {cgc_size_t tlv58; tlv58 = (cgc_size_t)(re); }
    {void * tlv69; tlv69 = (void *)(re); }
    {cgc_size_t tlv68; tlv68 = (cgc_size_t)(re); }
    {char * tlv75; tlv75 = (char *)(re); }
    {char * tlv76; tlv76 = (char *)(re); }
}
void fix_ingred_planetParsers_9_30(){
fix_ingred_planetParsers_9_30_6();
}
void fix_ingred_planetParsers_9_36_6(){
int tlv7;
    bzero(&tlv7,sizeof(int));
    {int rs; rs = (int)(tlv7); }
    {int re; re = (int)(tlv7); }
    {char tlv36; tlv36 = (char)(tlv7); }
    {char tlv39; tlv39 = (char)(tlv7); }
    {char tlv48; tlv48 = (char)(tlv7); }
    {int tlv51; tlv51 = (int)(tlv7); }
    {char * tlv72; tlv72 = (char *)(tlv7); }
    {char * tlv73; tlv73 = (char *)(tlv7); }
    {char * tlv74; tlv74 = (char *)(tlv7); }
    {void * tlv59; tlv59 = (void *)(tlv7); }
    {cgc_size_t tlv58; tlv58 = (cgc_size_t)(tlv7); }
    {void * tlv69; tlv69 = (void *)(tlv7); }
    {cgc_size_t tlv68; tlv68 = (cgc_size_t)(tlv7); }
}
void fix_ingred_planetParsers_9_36(){
fix_ingred_planetParsers_9_36_6();
}
void fix_ingred_planetParsers_9_38_1(){
    {int rs; rs = (int)('#'); }
    {int re; re = (int)('#'); }
    {char tlv36; tlv36 = (char)('#'); }
    {char tlv39; tlv39 = (char)('#'); }
    {char tlv48; tlv48 = (char)('#'); }
    {int tlv51; tlv51 = (int)('#'); }
    {char * tlv72; tlv72 = (char *)('#'); }
    {char * tlv73; tlv73 = (char *)('#'); }
    {char * tlv74; tlv74 = (char *)('#'); }
    {void * tlv59; tlv59 = (void *)('#'); }
    {cgc_size_t tlv58; tlv58 = (cgc_size_t)('#'); }
    {void * tlv69; tlv69 = (void *)('#'); }
    {cgc_size_t tlv68; tlv68 = (cgc_size_t)('#'); }
}
void fix_ingred_planetParsers_9_38(){
fix_ingred_planetParsers_9_38_1();
}
void fix_ingred_planetParsers_9_49_6(){
int tlv9;
    bzero(&tlv9,sizeof(int));
    {int rs; rs = (int)(tlv9); }
    {int re; re = (int)(tlv9); }
    {char tlv36; tlv36 = (char)(tlv9); }
    {char tlv39; tlv39 = (char)(tlv9); }
    {char tlv48; tlv48 = (char)(tlv9); }
    {int tlv51; tlv51 = (int)(tlv9); }
    {char * tlv72; tlv72 = (char *)(tlv9); }
    {char * tlv73; tlv73 = (char *)(tlv9); }
    {char * tlv74; tlv74 = (char *)(tlv9); }
    {void * tlv59; tlv59 = (void *)(tlv9); }
    {cgc_size_t tlv58; tlv58 = (cgc_size_t)(tlv9); }
    {void * tlv69; tlv69 = (void *)(tlv9); }
    {cgc_size_t tlv68; tlv68 = (cgc_size_t)(tlv9); }
}
void fix_ingred_planetParsers_9_49(){
fix_ingred_planetParsers_9_49_6();
}
void fix_ingred_planetParsers_9_51_1(){
char tlv76_ref;
    bzero(&tlv76_ref,1*sizeof(char));
char * tlv76 = &tlv76_ref;
    {int rs; rs = (int)(cgc_strlen ( tlv76 ) + 1); }
    {int re; re = (int)(cgc_strlen ( tlv76 ) + 1); }
    {char tlv36; tlv36 = (char)(cgc_strlen ( tlv76 ) + 1); }
    {char tlv39; tlv39 = (char)(cgc_strlen ( tlv76 ) + 1); }
    {char tlv48; tlv48 = (char)(cgc_strlen ( tlv76 ) + 1); }
    {int tlv51; tlv51 = (int)(cgc_strlen ( tlv76 ) + 1); }
    {int tlv50; tlv50 = (int)(cgc_strlen ( tlv76 ) + 1); }
    {char * tlv72; tlv72 = (char *)(cgc_strlen ( tlv76 ) + 1); }
    {char * tlv73; tlv73 = (char *)(cgc_strlen ( tlv76 ) + 1); }
    {char * tlv74; tlv74 = (char *)(cgc_strlen ( tlv76 ) + 1); }
    {void * tlv59; tlv59 = (void *)(cgc_strlen ( tlv76 ) + 1); }
    {cgc_size_t tlv58; tlv58 = (cgc_size_t)(cgc_strlen ( tlv76 ) + 1); }
    {void * tlv69; tlv69 = (void *)(cgc_strlen ( tlv76 ) + 1); }
    {cgc_size_t tlv68; tlv68 = (cgc_size_t)(cgc_strlen ( tlv76 ) + 1); }
}
void fix_ingred_planetParsers_9_51(){
fix_ingred_planetParsers_9_51_1();
}
void fix_ingred_planetParsers_9_53_1(){
char tlv73_ref;
    bzero(&tlv73_ref,1*sizeof(char));
char * tlv73 = &tlv73_ref;
    {char * temp; temp = (char *)(cgc_strlen ( tlv73 ) + 1); }
    {int start; start = (int)(cgc_strlen ( tlv73 ) + 1); }
    {int end; end = (int)(cgc_strlen ( tlv73 ) + 1); }
    {int rs; rs = (int)(cgc_strlen ( tlv73 ) + 1); }
    {int re; re = (int)(cgc_strlen ( tlv73 ) + 1); }
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
    {char tlv22; tlv22 = (char)(cgc_strlen ( tlv73 ) + 1); }
    {int tlv28; tlv28 = (int)(cgc_strlen ( tlv73 ) + 1); }
    {int tlv27; tlv27 = (int)(cgc_strlen ( tlv73 ) + 1); }
    {void * tlv12; tlv12 = (void *)(cgc_strlen ( tlv73 ) + 1); }
    {cgc_size_t tlv11; tlv11 = (cgc_size_t)(cgc_strlen ( tlv73 ) + 1); }
    {char tlv32; tlv32 = (char)(cgc_strlen ( tlv73 ) + 1); }
    {int * tlv13; tlv13 = (int *)(cgc_strlen ( tlv73 ) + 1); }
    {char tlv36; tlv36 = (char)(cgc_strlen ( tlv73 ) + 1); }
    {char tlv39; tlv39 = (char)(cgc_strlen ( tlv73 ) + 1); }
    {int tlv44; tlv44 = (int)(cgc_strlen ( tlv73 ) + 1); }
    {int tlv43; tlv43 = (int)(cgc_strlen ( tlv73 ) + 1); }
    {void * tlv16; tlv16 = (void *)(cgc_strlen ( tlv73 ) + 1); }
    {cgc_size_t tlv15; tlv15 = (cgc_size_t)(cgc_strlen ( tlv73 ) + 1); }
    {char tlv48; tlv48 = (char)(cgc_strlen ( tlv73 ) + 1); }
    {int tlv17; tlv17 = (int)(cgc_strlen ( tlv73 ) + 1); }
    {int tlv51; tlv51 = (int)(cgc_strlen ( tlv73 ) + 1); }
    {int tlv50; tlv50 = (int)(cgc_strlen ( tlv73 ) + 1); }
    {void * tlv20; tlv20 = (void *)(cgc_strlen ( tlv73 ) + 1); }
    {cgc_size_t tlv19; tlv19 = (cgc_size_t)(cgc_strlen ( tlv73 ) + 1); }
    {char * tlv72; tlv72 = (char *)(cgc_strlen ( tlv73 ) + 1); }
    {char * tlv74; tlv74 = (char *)(cgc_strlen ( tlv73 ) + 1); }
    {void * tlv59; tlv59 = (void *)(cgc_strlen ( tlv73 ) + 1); }
    {cgc_size_t tlv58; tlv58 = (cgc_size_t)(cgc_strlen ( tlv73 ) + 1); }
    {void * tlv69; tlv69 = (void *)(cgc_strlen ( tlv73 ) + 1); }
    {cgc_size_t tlv68; tlv68 = (cgc_size_t)(cgc_strlen ( tlv73 ) + 1); }
    {char * tlv75; tlv75 = (char *)(cgc_strlen ( tlv73 ) + 1); }
    {char * tlv76; tlv76 = (char *)(cgc_strlen ( tlv73 ) + 1); }
}
void fix_ingred_planetParsers_9_53(){
fix_ingred_planetParsers_9_53_1();
}
void fix_ingred_planetParsers_9_57_1(){
    {int rs; rs = (int)(1); }
    {int re; re = (int)(1); }
    {char tlv36; tlv36 = (char)(1); }
    {char tlv39; tlv39 = (char)(1); }
    {char tlv48; tlv48 = (char)(1); }
    {int tlv51; tlv51 = (int)(1); }
    {char * tlv72; tlv72 = (char *)(1); }
    {char * tlv73; tlv73 = (char *)(1); }
    {char * tlv74; tlv74 = (char *)(1); }
    {void * tlv59; tlv59 = (void *)(1); }
    {void * tlv69; tlv69 = (void *)(1); }
    {cgc_size_t tlv68; tlv68 = (cgc_size_t)(1); }
}
void fix_ingred_planetParsers_9_57(){
fix_ingred_planetParsers_9_57_1();
}
void fix_ingred_planetParsers_9_58_1(){
int rs;
    bzero(&rs,sizeof(int));
    {char * temp; temp = (char *)(rs); }
    {int start; start = (int)(rs); }
    {int end; end = (int)(rs); }
    {int re; re = (int)(rs); }
    {int tlv1; tlv1 = (int)(rs); }
    {int tlv2; tlv2 = (int)(rs); }
    {int tlv3; tlv3 = (int)(rs); }
    {int tlv4; tlv4 = (int)(rs); }
    {int tlv5; tlv5 = (int)(rs); }
    {int tlv6; tlv6 = (int)(rs); }
    {int tlv7; tlv7 = (int)(rs); }
    {int tlv8; tlv8 = (int)(rs); }
    {int tlv9; tlv9 = (int)(rs); }
    {int tlv10; tlv10 = (int)(rs); }
    {char tlv22; tlv22 = (char)(rs); }
    {int tlv28; tlv28 = (int)(rs); }
    {int tlv27; tlv27 = (int)(rs); }
    {void * tlv12; tlv12 = (void *)(rs); }
    {cgc_size_t tlv11; tlv11 = (cgc_size_t)(rs); }
    {char tlv32; tlv32 = (char)(rs); }
    {int * tlv13; tlv13 = (int *)(rs); }
    {char tlv36; tlv36 = (char)(rs); }
    {char tlv39; tlv39 = (char)(rs); }
    {int tlv44; tlv44 = (int)(rs); }
    {int tlv43; tlv43 = (int)(rs); }
    {void * tlv16; tlv16 = (void *)(rs); }
    {cgc_size_t tlv15; tlv15 = (cgc_size_t)(rs); }
    {char tlv48; tlv48 = (char)(rs); }
    {int tlv17; tlv17 = (int)(rs); }
    {int tlv51; tlv51 = (int)(rs); }
    {int tlv50; tlv50 = (int)(rs); }
    {void * tlv20; tlv20 = (void *)(rs); }
    {cgc_size_t tlv19; tlv19 = (cgc_size_t)(rs); }
    {char * tlv72; tlv72 = (char *)(rs); }
    {char * tlv73; tlv73 = (char *)(rs); }
    {char * tlv74; tlv74 = (char *)(rs); }
    {void * tlv59; tlv59 = (void *)(rs); }
    {cgc_size_t tlv58; tlv58 = (cgc_size_t)(rs); }
    {void * tlv69; tlv69 = (void *)(rs); }
    {cgc_size_t tlv68; tlv68 = (cgc_size_t)(rs); }
    {char * tlv75; tlv75 = (char *)(rs); }
    {char * tlv76; tlv76 = (char *)(rs); }
}
void fix_ingred_planetParsers_9_58(){
fix_ingred_planetParsers_9_58_1();
}
void fix_ingred_planetParsers_9_63_1(){
char tlv74_ref;
    bzero(&tlv74_ref,1*sizeof(char));
char * tlv74 = &tlv74_ref;
    {char * temp; temp = (char *)(cgc_strlen ( tlv74 ) + 1); }
    {int start; start = (int)(cgc_strlen ( tlv74 ) + 1); }
    {int end; end = (int)(cgc_strlen ( tlv74 ) + 1); }
    {int rs; rs = (int)(cgc_strlen ( tlv74 ) + 1); }
    {int re; re = (int)(cgc_strlen ( tlv74 ) + 1); }
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
    {char tlv22; tlv22 = (char)(cgc_strlen ( tlv74 ) + 1); }
    {int tlv28; tlv28 = (int)(cgc_strlen ( tlv74 ) + 1); }
    {int tlv27; tlv27 = (int)(cgc_strlen ( tlv74 ) + 1); }
    {void * tlv12; tlv12 = (void *)(cgc_strlen ( tlv74 ) + 1); }
    {cgc_size_t tlv11; tlv11 = (cgc_size_t)(cgc_strlen ( tlv74 ) + 1); }
    {char tlv32; tlv32 = (char)(cgc_strlen ( tlv74 ) + 1); }
    {int * tlv13; tlv13 = (int *)(cgc_strlen ( tlv74 ) + 1); }
    {char tlv36; tlv36 = (char)(cgc_strlen ( tlv74 ) + 1); }
    {char tlv39; tlv39 = (char)(cgc_strlen ( tlv74 ) + 1); }
    {int tlv44; tlv44 = (int)(cgc_strlen ( tlv74 ) + 1); }
    {int tlv43; tlv43 = (int)(cgc_strlen ( tlv74 ) + 1); }
    {void * tlv16; tlv16 = (void *)(cgc_strlen ( tlv74 ) + 1); }
    {cgc_size_t tlv15; tlv15 = (cgc_size_t)(cgc_strlen ( tlv74 ) + 1); }
    {char tlv48; tlv48 = (char)(cgc_strlen ( tlv74 ) + 1); }
    {int tlv17; tlv17 = (int)(cgc_strlen ( tlv74 ) + 1); }
    {int tlv51; tlv51 = (int)(cgc_strlen ( tlv74 ) + 1); }
    {int tlv50; tlv50 = (int)(cgc_strlen ( tlv74 ) + 1); }
    {void * tlv20; tlv20 = (void *)(cgc_strlen ( tlv74 ) + 1); }
    {cgc_size_t tlv19; tlv19 = (cgc_size_t)(cgc_strlen ( tlv74 ) + 1); }
    {char * tlv72; tlv72 = (char *)(cgc_strlen ( tlv74 ) + 1); }
    {char * tlv73; tlv73 = (char *)(cgc_strlen ( tlv74 ) + 1); }
    {void * tlv59; tlv59 = (void *)(cgc_strlen ( tlv74 ) + 1); }
    {cgc_size_t tlv58; tlv58 = (cgc_size_t)(cgc_strlen ( tlv74 ) + 1); }
    {void * tlv69; tlv69 = (void *)(cgc_strlen ( tlv74 ) + 1); }
    {cgc_size_t tlv68; tlv68 = (cgc_size_t)(cgc_strlen ( tlv74 ) + 1); }
    {char * tlv75; tlv75 = (char *)(cgc_strlen ( tlv74 ) + 1); }
    {char * tlv76; tlv76 = (char *)(cgc_strlen ( tlv74 ) + 1); }
}
void fix_ingred_planetParsers_9_63(){
fix_ingred_planetParsers_9_63_1();
}
void fix_ingred_planetParsers_9(){
fix_ingred_planetParsers_9_0();
fix_ingred_planetParsers_9_3();
fix_ingred_planetParsers_9_7();
fix_ingred_planetParsers_9_11();
fix_ingred_planetParsers_9_13();
fix_ingred_planetParsers_9_14();
fix_ingred_planetParsers_9_16();
fix_ingred_planetParsers_9_18();
fix_ingred_planetParsers_9_19();
fix_ingred_planetParsers_9_21();
fix_ingred_planetParsers_9_22();
fix_ingred_planetParsers_9_26();
fix_ingred_planetParsers_9_28();
fix_ingred_planetParsers_9_30();
fix_ingred_planetParsers_9_36();
fix_ingred_planetParsers_9_38();
fix_ingred_planetParsers_9_49();
fix_ingred_planetParsers_9_51();
fix_ingred_planetParsers_9_53();
fix_ingred_planetParsers_9_57();
fix_ingred_planetParsers_9_58();
fix_ingred_planetParsers_9_63();
}
void fix_ingred_planetParsers_10_0_0(){
    {int es; es = (int)(NULL); }
    {int ee; ee = (int)(NULL); }
}
void fix_ingred_planetParsers_10_0_1(){
    {double eradius; eradius = (double)(- 1.0); }
}
void fix_ingred_planetParsers_10_0_2(){
    {int es; es = (int)(0); }
    {int ee; ee = (int)(0); }
}
void fix_ingred_planetParsers_10_0(){
fix_ingred_planetParsers_10_0_0();
fix_ingred_planetParsers_10_0_1();
fix_ingred_planetParsers_10_0_2();
}
void fix_ingred_planetParsers_10_3_1(){
    {int es; es = (int)('{'); }
    {int ee; ee = (int)('{'); }
}
void fix_ingred_planetParsers_10_3(){
fix_ingred_planetParsers_10_3_1();
}
void fix_ingred_planetParsers_10_6_1(){
    {int es; es = (int)(1); }
    {int ee; ee = (int)(1); }
}
void fix_ingred_planetParsers_10_6(){
fix_ingred_planetParsers_10_6_1();
}
void fix_ingred_planetParsers_10_7_6(){
int tlv2;
    bzero(&tlv2,sizeof(int));
    {int es; es = (int)(tlv2); }
    {int ee; ee = (int)(tlv2); }
}
void fix_ingred_planetParsers_10_7_7(){
int tlv2;
    bzero(&tlv2,sizeof(int));
    {int es; es = (int)(- 1); }
    {int ee; ee = (int)(- 1); }
}
void fix_ingred_planetParsers_10_7(){
fix_ingred_planetParsers_10_7_6();
fix_ingred_planetParsers_10_7_7();
}
void fix_ingred_planetParsers_10_11_6(){
int end;
    bzero(&end,sizeof(int));
    {int es; es = (int)(end); }
    {int ee; ee = (int)(end); }
}
void fix_ingred_planetParsers_10_11(){
fix_ingred_planetParsers_10_11_6();
}
void fix_ingred_planetParsers_10_13_1(){
int start;
    bzero(&start,sizeof(int));
    {int es; es = (int)(start); }
    {int ee; ee = (int)(start); }
}
void fix_ingred_planetParsers_10_13(){
fix_ingred_planetParsers_10_13_1();
}
void fix_ingred_planetParsers_10_14_6(){
char temp_ref;
    bzero(&temp_ref,1*sizeof(char));
char * temp = &temp_ref;
    {int es; es = (int)(temp); }
    {int ee; ee = (int)(temp); }
}
void fix_ingred_planetParsers_10_14(){
fix_ingred_planetParsers_10_14_6();
}
void fix_ingred_planetParsers_10_16_7(){
int tlv3;
    bzero(&tlv3,sizeof(int));
    {int es; es = (int)(tlv3); }
    {int ee; ee = (int)(tlv3); }
}
void fix_ingred_planetParsers_10_16(){
fix_ingred_planetParsers_10_16_7();
}
void fix_ingred_planetParsers_10_18_0(){
char temp_ref;
    bzero(&temp_ref,1*sizeof(char));
char * temp = &temp_ref;
    {int es; es = (int)(temp); }
    {int ee; ee = (int)(temp); }
}
void fix_ingred_planetParsers_10_18(){
fix_ingred_planetParsers_10_18_0();
}
void fix_ingred_planetParsers_10_19_1(){
char tlv78_ref;
    bzero(&tlv78_ref,1*sizeof(char));
char * tlv78 = &tlv78_ref;
    {int es; es = (int)(cgc_strlen ( tlv78 ) + 1); }
    {int ee; ee = (int)(cgc_strlen ( tlv78 ) + 1); }
}
void fix_ingred_planetParsers_10_19(){
fix_ingred_planetParsers_10_19_1();
}
void fix_ingred_planetParsers_10_21_1(){
char tlv75_ref;
    bzero(&tlv75_ref,1*sizeof(char));
char * tlv75 = &tlv75_ref;
    {int es; es = (int)(cgc_strlen ( tlv75 ) + 1); }
    {int ee; ee = (int)(cgc_strlen ( tlv75 ) + 1); }
}
void fix_ingred_planetParsers_10_21(){
fix_ingred_planetParsers_10_21_1();
}
void fix_ingred_planetParsers_10_22_1(){
    {int es; es = (int)('}'); }
    {int ee; ee = (int)('}'); }
}
void fix_ingred_planetParsers_10_22(){
fix_ingred_planetParsers_10_22_1();
}
void fix_ingred_planetParsers_10_26_6(){
int tlv5;
    bzero(&tlv5,sizeof(int));
    {int es; es = (int)(tlv5); }
    {int ee; ee = (int)(tlv5); }
}
void fix_ingred_planetParsers_10_26(){
fix_ingred_planetParsers_10_26_6();
}
void fix_ingred_planetParsers_10_28_1(){
int es;
    bzero(&es,sizeof(int));
    {char * temp; temp = (char *)(& es); }
    {int start; start = (int)(& es); }
    {int end; end = (int)(& es); }
    {int ee; ee = (int)(& es); }
    {int tlv1; tlv1 = (int)(& es); }
    {int tlv2; tlv2 = (int)(& es); }
    {int tlv3; tlv3 = (int)(& es); }
    {int tlv4; tlv4 = (int)(& es); }
    {int tlv5; tlv5 = (int)(& es); }
    {int tlv6; tlv6 = (int)(& es); }
    {int tlv7; tlv7 = (int)(& es); }
    {int tlv8; tlv8 = (int)(& es); }
    {int tlv9; tlv9 = (int)(& es); }
    {int tlv10; tlv10 = (int)(& es); }
    {char tlv22; tlv22 = (char)(& es); }
    {int tlv24; tlv24 = (int)(& es); }
    {int tlv29; tlv29 = (int)(& es); }
    {int tlv28; tlv28 = (int)(& es); }
    {void * tlv12; tlv12 = (void *)(& es); }
    {cgc_size_t tlv11; tlv11 = (cgc_size_t)(& es); }
    {char tlv33; tlv33 = (char)(& es); }
    {int tlv35; tlv35 = (int)(& es); }
    {int * tlv13; tlv13 = (int *)(& es); }
    {char tlv38; tlv38 = (char)(& es); }
    {char tlv41; tlv41 = (char)(& es); }
    {int tlv43; tlv43 = (int)(& es); }
    {int tlv47; tlv47 = (int)(& es); }
    {int tlv46; tlv46 = (int)(& es); }
    {void * tlv16; tlv16 = (void *)(& es); }
    {cgc_size_t tlv15; tlv15 = (cgc_size_t)(& es); }
    {char tlv51; tlv51 = (char)(& es); }
    {int tlv17; tlv17 = (int)(& es); }
    {int tlv54; tlv54 = (int)(& es); }
    {int tlv53; tlv53 = (int)(& es); }
    {void * tlv20; tlv20 = (void *)(& es); }
    {cgc_size_t tlv19; tlv19 = (cgc_size_t)(& es); }
    {char * tlv75; tlv75 = (char *)(& es); }
    {char * tlv76; tlv76 = (char *)(& es); }
    {char * tlv77; tlv77 = (char *)(& es); }
    {void * tlv62; tlv62 = (void *)(& es); }
    {cgc_size_t tlv61; tlv61 = (cgc_size_t)(& es); }
    {void * tlv72; tlv72 = (void *)(& es); }
    {cgc_size_t tlv71; tlv71 = (cgc_size_t)(& es); }
    {char * tlv78; tlv78 = (char *)(& es); }
    {char * tlv79; tlv79 = (char *)(& es); }
}
void fix_ingred_planetParsers_10_28(){
fix_ingred_planetParsers_10_28_1();
}
void fix_ingred_planetParsers_10_30_6(){
int ee;
    bzero(&ee,sizeof(int));
    {char * temp; temp = (char *)(ee); }
    {int start; start = (int)(ee); }
    {int end; end = (int)(ee); }
    {int es; es = (int)(ee); }
    {int tlv1; tlv1 = (int)(ee); }
    {int tlv2; tlv2 = (int)(ee); }
    {int tlv3; tlv3 = (int)(ee); }
    {int tlv4; tlv4 = (int)(ee); }
    {int tlv5; tlv5 = (int)(ee); }
    {int tlv6; tlv6 = (int)(ee); }
    {int tlv7; tlv7 = (int)(ee); }
    {int tlv8; tlv8 = (int)(ee); }
    {int tlv9; tlv9 = (int)(ee); }
    {int tlv10; tlv10 = (int)(ee); }
    {char tlv22; tlv22 = (char)(ee); }
    {int tlv24; tlv24 = (int)(ee); }
    {int tlv29; tlv29 = (int)(ee); }
    {int tlv28; tlv28 = (int)(ee); }
    {void * tlv12; tlv12 = (void *)(ee); }
    {cgc_size_t tlv11; tlv11 = (cgc_size_t)(ee); }
    {char tlv33; tlv33 = (char)(ee); }
    {int tlv35; tlv35 = (int)(ee); }
    {int * tlv13; tlv13 = (int *)(ee); }
    {char tlv38; tlv38 = (char)(ee); }
    {char tlv41; tlv41 = (char)(ee); }
    {int tlv43; tlv43 = (int)(ee); }
    {int tlv47; tlv47 = (int)(ee); }
    {int tlv46; tlv46 = (int)(ee); }
    {void * tlv16; tlv16 = (void *)(ee); }
    {cgc_size_t tlv15; tlv15 = (cgc_size_t)(ee); }
    {char tlv51; tlv51 = (char)(ee); }
    {int tlv17; tlv17 = (int)(ee); }
    {int tlv54; tlv54 = (int)(ee); }
    {int tlv53; tlv53 = (int)(ee); }
    {void * tlv20; tlv20 = (void *)(ee); }
    {cgc_size_t tlv19; tlv19 = (cgc_size_t)(ee); }
    {char * tlv75; tlv75 = (char *)(ee); }
    {char * tlv76; tlv76 = (char *)(ee); }
    {char * tlv77; tlv77 = (char *)(ee); }
    {void * tlv62; tlv62 = (void *)(ee); }
    {cgc_size_t tlv61; tlv61 = (cgc_size_t)(ee); }
    {void * tlv72; tlv72 = (void *)(ee); }
    {cgc_size_t tlv71; tlv71 = (cgc_size_t)(ee); }
    {char * tlv78; tlv78 = (char *)(ee); }
    {char * tlv79; tlv79 = (char *)(ee); }
}
void fix_ingred_planetParsers_10_30(){
fix_ingred_planetParsers_10_30_6();
}
void fix_ingred_planetParsers_10_36_6(){
int tlv7;
    bzero(&tlv7,sizeof(int));
    {int es; es = (int)(tlv7); }
    {int ee; ee = (int)(tlv7); }
}
void fix_ingred_planetParsers_10_36(){
fix_ingred_planetParsers_10_36_6();
}
void fix_ingred_planetParsers_10_38_1(){
    {int es; es = (int)('#'); }
    {int ee; ee = (int)('#'); }
}
void fix_ingred_planetParsers_10_38(){
fix_ingred_planetParsers_10_38_1();
}
void fix_ingred_planetParsers_10_49_6(){
int tlv9;
    bzero(&tlv9,sizeof(int));
    {int es; es = (int)(tlv9); }
    {int ee; ee = (int)(tlv9); }
}
void fix_ingred_planetParsers_10_49(){
fix_ingred_planetParsers_10_49_6();
}
void fix_ingred_planetParsers_10_51_1(){
char tlv79_ref;
    bzero(&tlv79_ref,1*sizeof(char));
char * tlv79 = &tlv79_ref;
    {int es; es = (int)(cgc_strlen ( tlv79 ) + 1); }
    {int ee; ee = (int)(cgc_strlen ( tlv79 ) + 1); }
}
void fix_ingred_planetParsers_10_51(){
fix_ingred_planetParsers_10_51_1();
}
void fix_ingred_planetParsers_10_53_1(){
char tlv76_ref;
    bzero(&tlv76_ref,1*sizeof(char));
char * tlv76 = &tlv76_ref;
    {int es; es = (int)(cgc_strlen ( tlv76 ) + 1); }
    {int ee; ee = (int)(cgc_strlen ( tlv76 ) + 1); }
}
void fix_ingred_planetParsers_10_53(){
fix_ingred_planetParsers_10_53_1();
}
void fix_ingred_planetParsers_10_58_1(){
int es;
    bzero(&es,sizeof(int));
    {char * temp; temp = (char *)(es); }
    {int start; start = (int)(es); }
    {int end; end = (int)(es); }
    {int ee; ee = (int)(es); }
    {int tlv1; tlv1 = (int)(es); }
    {int tlv2; tlv2 = (int)(es); }
    {int tlv3; tlv3 = (int)(es); }
    {int tlv4; tlv4 = (int)(es); }
    {int tlv5; tlv5 = (int)(es); }
    {int tlv6; tlv6 = (int)(es); }
    {int tlv7; tlv7 = (int)(es); }
    {int tlv8; tlv8 = (int)(es); }
    {int tlv9; tlv9 = (int)(es); }
    {int tlv10; tlv10 = (int)(es); }
    {char tlv22; tlv22 = (char)(es); }
    {int tlv24; tlv24 = (int)(es); }
    {int tlv29; tlv29 = (int)(es); }
    {int tlv28; tlv28 = (int)(es); }
    {void * tlv12; tlv12 = (void *)(es); }
    {cgc_size_t tlv11; tlv11 = (cgc_size_t)(es); }
    {char tlv33; tlv33 = (char)(es); }
    {int tlv35; tlv35 = (int)(es); }
    {int * tlv13; tlv13 = (int *)(es); }
    {char tlv38; tlv38 = (char)(es); }
    {char tlv41; tlv41 = (char)(es); }
    {int tlv43; tlv43 = (int)(es); }
    {int tlv47; tlv47 = (int)(es); }
    {int tlv46; tlv46 = (int)(es); }
    {void * tlv16; tlv16 = (void *)(es); }
    {cgc_size_t tlv15; tlv15 = (cgc_size_t)(es); }
    {char tlv51; tlv51 = (char)(es); }
    {int tlv17; tlv17 = (int)(es); }
    {int tlv54; tlv54 = (int)(es); }
    {int tlv53; tlv53 = (int)(es); }
    {void * tlv20; tlv20 = (void *)(es); }
    {cgc_size_t tlv19; tlv19 = (cgc_size_t)(es); }
    {char * tlv75; tlv75 = (char *)(es); }
    {char * tlv76; tlv76 = (char *)(es); }
    {char * tlv77; tlv77 = (char *)(es); }
    {void * tlv62; tlv62 = (void *)(es); }
    {cgc_size_t tlv61; tlv61 = (cgc_size_t)(es); }
    {void * tlv72; tlv72 = (void *)(es); }
    {cgc_size_t tlv71; tlv71 = (cgc_size_t)(es); }
    {char * tlv78; tlv78 = (char *)(es); }
    {char * tlv79; tlv79 = (char *)(es); }
}
void fix_ingred_planetParsers_10_58(){
fix_ingred_planetParsers_10_58_1();
}
void fix_ingred_planetParsers_10_63_1(){
char tlv77_ref;
    bzero(&tlv77_ref,1*sizeof(char));
char * tlv77 = &tlv77_ref;
    {int es; es = (int)(cgc_strlen ( tlv77 ) + 1); }
    {int ee; ee = (int)(cgc_strlen ( tlv77 ) + 1); }
}
void fix_ingred_planetParsers_10_63(){
fix_ingred_planetParsers_10_63_1();
}
void fix_ingred_planetParsers_10(){
fix_ingred_planetParsers_10_0();
fix_ingred_planetParsers_10_3();
fix_ingred_planetParsers_10_6();
fix_ingred_planetParsers_10_7();
fix_ingred_planetParsers_10_11();
fix_ingred_planetParsers_10_13();
fix_ingred_planetParsers_10_14();
fix_ingred_planetParsers_10_16();
fix_ingred_planetParsers_10_18();
fix_ingred_planetParsers_10_19();
fix_ingred_planetParsers_10_21();
fix_ingred_planetParsers_10_22();
fix_ingred_planetParsers_10_26();
fix_ingred_planetParsers_10_28();
fix_ingred_planetParsers_10_30();
fix_ingred_planetParsers_10_36();
fix_ingred_planetParsers_10_38();
fix_ingred_planetParsers_10_49();
fix_ingred_planetParsers_10_51();
fix_ingred_planetParsers_10_53();
fix_ingred_planetParsers_10_58();
fix_ingred_planetParsers_10_63();
}
void fix_ingred_planetParsers_11_0_1(){
    {double mass; mass = (double)(- 1.0); }
}
void fix_ingred_planetParsers_11_0(){
fix_ingred_planetParsers_11_0_1();
}
void fix_ingred_planetParsers_11(){
fix_ingred_planetParsers_11_0();
}
void fix_ingred_planetParsers_12_0_1(){
    {double gravity; gravity = (double)(- 1.0); }
}
void fix_ingred_planetParsers_12_0(){
fix_ingred_planetParsers_12_0_1();
}
void fix_ingred_planetParsers_12(){
fix_ingred_planetParsers_12_0();
}
