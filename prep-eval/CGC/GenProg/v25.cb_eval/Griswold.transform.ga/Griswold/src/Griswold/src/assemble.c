

#include "libcgc.h"
#include "cgc_libc.h"
#include "cgc_components.h"
#include "cgc_assemble.h"
static receptacle_t *cgc_search_receptacle_for_receptacle_id(receptacle_t * receptacle, uint32_t receptacle_id);
static receptacle_t *cgc_search_light_string_for_receptacle_id(light_string_t * light_string, uint32_t receptacle_id);
static receptacle_t *cgc_search_outlet_for_receptacle_id(outlet_t * outlet, uint32_t receptacle_id);
static receptacle_t *cgc_search_splitter_for_receptacle_id(n_way_splitter_t * splitter, uint32_t receptacle_id);
static n_way_splitter_t *cgc_search_receptacle_for_splitter_id(receptacle_t * r, uint32_t splitter_id);
static n_way_splitter_t *cgc_search_light_string_for_splitter_id(light_string_t * ls, uint32_t splitter_id);
static n_way_splitter_t *cgc_search_outlet_for_splitter_id(outlet_t * o, uint32_t splitter_id);
static n_way_splitter_t *cgc_search_splitter_for_splitter_id(n_way_splitter_t * splitter, uint32_t splitter_id);
static light_string_t *cgc_search_receptacle_for_light_string_id(receptacle_t * r, uint32_t light_string_id);
static light_string_t *cgc_search_light_string_for_light_string_id(light_string_t * light_string, uint32_t light_string_id);
static light_string_t *cgc_search_outlet_for_light_string_id(outlet_t * o, uint32_t light_string_id);
static light_string_t *cgc_search_splitter_for_light_string_id(n_way_splitter_t * s, uint32_t light_string_id);
static list_t *cgc_get_outlet_list_on_breaker(uint32_t breaker_id);
static float cgc_get_total_amp_load_on_light_string_by_light_string_va(light_string_t * light_string);
static float cgc_get_total_amp_load_on_splitter_by_splitter_va(n_way_splitter_t * splitter);
static float cgc_get_total_amp_load_on_receptacle_by_receptacle_va(receptacle_t * receptacle);
static float cgc_get_total_amp_load_on_outlet_by_outlet_va(outlet_t * outlet);
// root of the electrical model is the load center
static load_center_t *e_model = NULL;
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

void fix_ingred_assemble_0();
static float cgc_convert_watts_to_amps(float watts)
{
if (fix_ingred_enable){ fix_ingred_assemble_0(); };
    return (watts / 120.0);
}

void fix_ingred_assemble_1();
static uint8_t cgc_load_center_is_created()
{
if (fix_ingred_enable){ fix_ingred_assemble_1(); };
    if (NULL == e_model) {
	return FALSE;
    } else {
	return TRUE;
    }
}

void fix_ingred_assemble_2();
static int8_t cgc_load_center_breaker_spaces_are_full()
{
if (fix_ingred_enable){ fix_ingred_assemble_2(); };
    if ((TRUE == cgc_load_center_is_created()) && (e_model->breaker_spaces == e_model->breakers_installed_cnt)) {
	return TRUE;
    } else {
	return FALSE;
    }
}

void fix_ingred_assemble_3();
static LOAD_TYPE_T cgc_get_receptacle_load_type(receptacle_t * receptacle)
{
if (fix_ingred_enable){ fix_ingred_assemble_3(); };
    return receptacle->load_type;
}

void fix_ingred_assemble_4();
static int8_t cgc_receptacle_is_loaded(receptacle_t * receptacle)
{
if (fix_ingred_enable){ fix_ingred_assemble_4(); };
    static LOAD_TYPE_T tlv1;
    {
        receptacle_t* tlv2;
        tlv2 = receptacle;
        tlv1 = cgc_get_receptacle_load_type(tlv2);
    }
    if (NO_LOAD > tlv1) {
	return TRUE;
    } else {
	return FALSE;
    }
}

void fix_ingred_assemble_5_1_2();
void fix_ingred_assemble_5_1_3();
void fix_ingred_assemble_5_1();
void fix_ingred_assemble_5();
static receptacle_t *cgc_search_receptacle_for_receptacle_id(receptacle_t * receptacle, uint32_t receptacle_id)
{
if (fix_ingred_enable){ fix_ingred_assemble_5(); };
    receptacle_t* r;
    r = NULL;
    if (receptacle_id == receptacle->id) {
	r = receptacle;
    } else {
 static LOAD_TYPE_T tlv1;
 {
     receptacle_t* tlv3;
     tlv3 = receptacle;
     tlv1 = cgc_get_receptacle_load_type(tlv3);
 }
	if (SPLITTER == tlv1) {
     {
         n_way_splitter_t* tlv5;
         tlv5 = ( n_way_splitter_t * ) receptacle -> load;
         uint32_t tlv4;
         tlv4 = receptacle_id;
    	    r = cgc_search_splitter_for_receptacle_id(tlv5,tlv4);
     }
	} else {
     static LOAD_TYPE_T tlv2;
     {
         receptacle_t* tlv6;
         tlv6 = receptacle;
         tlv2 = cgc_get_receptacle_load_type(tlv6);
     }
	    if (LIGHT_STRING == tlv2) {
  {
      light_string_t* tlv8;
      tlv8 = ( light_string_t * ) receptacle -> load;
      uint32_t tlv7;
      tlv7 = receptacle_id;
    		r = cgc_search_light_string_for_receptacle_id(tlv8,tlv7);
  }
	    }
	}
    }
    return r;
}

void fix_ingred_assemble_6_1_1();
void fix_ingred_assemble_6_1();
void fix_ingred_assemble_6();
static receptacle_t *cgc_search_outlet_for_receptacle_id(outlet_t * outlet, uint32_t receptacle_id)
{
if (fix_ingred_enable){ fix_ingred_assemble_6(); };
    receptacle_t* r;
    r = NULL;
    {
        receptacle_t* tlv2;
        tlv2 = & ( outlet -> r1 );
        uint32_t tlv1;
        tlv1 = receptacle_id;
        r = cgc_search_receptacle_for_receptacle_id(tlv2,tlv1);
    }
    if (NULL == r) {
 {
     receptacle_t* tlv4;
     tlv4 = & ( outlet -> r2 );
     uint32_t tlv3;
     tlv3 = receptacle_id;
    	r = cgc_search_receptacle_for_receptacle_id(tlv4,tlv3);
 }
    }
    return r;
}

void fix_ingred_assemble_7_1_1();
void fix_ingred_assemble_7_1_2();
void fix_ingred_assemble_7_1();
void fix_ingred_assemble_7();
static receptacle_t *cgc_search_splitter_for_receptacle_id(n_way_splitter_t * splitter, uint32_t receptacle_id)
{
if (fix_ingred_enable){ fix_ingred_assemble_7(); };
    receptacle_t* r;
    r = NULL;
    for (uint32_t idx = 0; idx <= splitter->receptacle_count; idx++) {
 {
     receptacle_t* tlv2;
     tlv2 = & ( splitter -> receptacles [ idx ] );
     uint32_t tlv1;
     tlv1 = receptacle_id;
    	r = cgc_search_receptacle_for_receptacle_id(tlv2,tlv1);
 }
	if (NULL != r) {
	    break;
	}
    }
    return r;
}

void fix_ingred_assemble_8();
static receptacle_t *cgc_search_light_string_for_receptacle_id(light_string_t * light_string, uint32_t receptacle_id)
{
if (fix_ingred_enable){ fix_ingred_assemble_8(); };
    return cgc_search_receptacle_for_receptacle_id(&(light_string->receptacle), receptacle_id);
}

void fix_ingred_assemble_9_3_1();
void fix_ingred_assemble_9_3();
void fix_ingred_assemble_9();
static n_way_splitter_t *cgc_search_receptacle_for_splitter_id(receptacle_t * r, uint32_t splitter_id)
{
if (fix_ingred_enable){ fix_ingred_assemble_9(); };
    n_way_splitter_t* s;
    s = NULL;
    static LOAD_TYPE_T tlv1;
    {
        receptacle_t* tlv3;
        tlv3 = r;
        tlv1 = cgc_get_receptacle_load_type(tlv3);
    }
    if (SPLITTER == tlv1) {
 {
     n_way_splitter_t* tlv5;
     tlv5 = ( n_way_splitter_t * ) r -> load;
     uint32_t tlv4;
     tlv4 = splitter_id;
    	s = cgc_search_splitter_for_splitter_id(tlv5,tlv4);
 }
    } else {
 static LOAD_TYPE_T tlv2;
 {
     receptacle_t* tlv6;
     tlv6 = r;
     tlv2 = cgc_get_receptacle_load_type(tlv6);
 }
	if (LIGHT_STRING == tlv2) {
     {
         light_string_t* tlv8;
         tlv8 = ( light_string_t * ) r -> load;
         uint32_t tlv7;
         tlv7 = splitter_id;
    	    s = cgc_search_light_string_for_splitter_id(tlv8,tlv7);
     }
	}
    }
    return s;
}

void fix_ingred_assemble_10();
static n_way_splitter_t *cgc_search_light_string_for_splitter_id(light_string_t * ls, uint32_t splitter_id)
{
if (fix_ingred_enable){ fix_ingred_assemble_10(); };
    return cgc_search_receptacle_for_splitter_id(&(ls->receptacle), splitter_id);
}

void fix_ingred_assemble_11_1_1();
void fix_ingred_assemble_11_1();
void fix_ingred_assemble_11();
static n_way_splitter_t *cgc_search_outlet_for_splitter_id(outlet_t * o, uint32_t splitter_id)
{
if (fix_ingred_enable){ fix_ingred_assemble_11(); };
    n_way_splitter_t* s;
    s = NULL;
    {
        receptacle_t* tlv2;
        tlv2 = & ( o -> r1 );
        uint32_t tlv1;
        tlv1 = splitter_id;
        s = cgc_search_receptacle_for_splitter_id(tlv2,tlv1);
    }
    if (NULL == s) {
 {
     receptacle_t* tlv4;
     tlv4 = & ( o -> r2 );
     uint32_t tlv3;
     tlv3 = splitter_id;
    	s = cgc_search_receptacle_for_splitter_id(tlv4,tlv3);
 }
    }
    return s;
}

void fix_ingred_assemble_12_1_3();
void fix_ingred_assemble_12_1();
void fix_ingred_assemble_12_3_1();
void fix_ingred_assemble_12_3_2();
void fix_ingred_assemble_12_3();
void fix_ingred_assemble_12();
static n_way_splitter_t *cgc_search_splitter_for_splitter_id(n_way_splitter_t * splitter, uint32_t splitter_id)
{
if (fix_ingred_enable){ fix_ingred_assemble_12(); };
    n_way_splitter_t* s;
    s = NULL;
    if (splitter_id == splitter->id) {
	s = splitter;
    } else {
	for (uint8_t idx = 0; idx < splitter->receptacle_count; idx++) {
     {
         receptacle_t* tlv2;
         tlv2 = & ( splitter -> receptacles [ idx ] );
         uint32_t tlv1;
         tlv1 = splitter_id;
    	    s = cgc_search_receptacle_for_splitter_id(tlv2,tlv1);
     }
	    if (NULL != s) {
		break;
	    }
	}
    }
    return s;
}

void fix_ingred_assemble_13_3_1();
void fix_ingred_assemble_13_3();
void fix_ingred_assemble_13();
static light_string_t *cgc_search_receptacle_for_light_string_id(receptacle_t * r, uint32_t light_string_id)
{
if (fix_ingred_enable){ fix_ingred_assemble_13(); };
    light_string_t* ls;
    ls = NULL;
    static LOAD_TYPE_T tlv1;
    {
        receptacle_t* tlv3;
        tlv3 = r;
        tlv1 = cgc_get_receptacle_load_type(tlv3);
    }
    if (SPLITTER == tlv1) {
 {
     n_way_splitter_t* tlv5;
     tlv5 = ( n_way_splitter_t * ) r -> load;
     uint32_t tlv4;
     tlv4 = light_string_id;
    	ls = cgc_search_splitter_for_light_string_id(tlv5,tlv4);
 }
    } else {
 static LOAD_TYPE_T tlv2;
 {
     receptacle_t* tlv6;
     tlv6 = r;
     tlv2 = cgc_get_receptacle_load_type(tlv6);
 }
	if (LIGHT_STRING == tlv2) {
     {
         light_string_t* tlv8;
         tlv8 = ( light_string_t * ) r -> load;
         uint32_t tlv7;
         tlv7 = light_string_id;
    	    ls = cgc_search_light_string_for_light_string_id(tlv8,tlv7);
     }
	}
    }
    return ls;
}

void fix_ingred_assemble_14_1_2();
void fix_ingred_assemble_14_1_3();
void fix_ingred_assemble_14_1();
void fix_ingred_assemble_14();
static light_string_t *cgc_search_light_string_for_light_string_id(light_string_t * light_string, uint32_t light_string_id)
{
if (fix_ingred_enable){ fix_ingred_assemble_14(); };
    light_string_t* ls;
    ls = NULL;
    if (light_string_id == light_string->id) {
	ls = light_string;
    } else {
 {
     receptacle_t* tlv2;
     tlv2 = & ( light_string -> receptacle );
     uint32_t tlv1;
     tlv1 = light_string_id;
    	ls = cgc_search_receptacle_for_light_string_id(tlv2,tlv1);
 }
    }
    return ls;
}

void fix_ingred_assemble_15_1_1();
void fix_ingred_assemble_15_1();
void fix_ingred_assemble_15();
static light_string_t *cgc_search_outlet_for_light_string_id(outlet_t * o, uint32_t light_string_id)
{
if (fix_ingred_enable){ fix_ingred_assemble_15(); };
    light_string_t* ls;
    ls = NULL;
    {
        receptacle_t* tlv2;
        tlv2 = & ( o -> r1 );
        uint32_t tlv1;
        tlv1 = light_string_id;
        ls = cgc_search_receptacle_for_light_string_id(tlv2,tlv1);
    }
    if (NULL == ls) {
 {
     receptacle_t* tlv4;
     tlv4 = & ( o -> r2 );
     uint32_t tlv3;
     tlv3 = light_string_id;
    	ls = cgc_search_receptacle_for_light_string_id(tlv4,tlv3);
 }
    }
    return ls;
}

void fix_ingred_assemble_16_1_2();
void fix_ingred_assemble_16_1();
void fix_ingred_assemble_16();
static light_string_t *cgc_search_splitter_for_light_string_id(n_way_splitter_t * s, uint32_t light_string_id)
{
if (fix_ingred_enable){ fix_ingred_assemble_16(); };
    light_string_t* ls;
    ls = NULL;
    for (uint8_t idx = 0; idx < s->receptacle_count; idx++) {
 {
     receptacle_t* tlv2;
     tlv2 = & ( s -> receptacles [ idx ] );
     uint32_t tlv1;
     tlv1 = light_string_id;
    	ls = cgc_search_receptacle_for_light_string_id(tlv2,tlv1);
 }
	if (NULL != ls) {
	    break;
	}
    }
    return ls;
}

void fix_ingred_assemble_17_1_0();
void fix_ingred_assemble_17_1();
void fix_ingred_assemble_17();
static receptacle_t *cgc_get_receptacle_by_id_from_breaker_id(uint32_t breaker_id, uint32_t receptacle_id)
{
if (fix_ingred_enable){ fix_ingred_assemble_17(); };
    receptacle_t* r;
    r = NULL;
    list_t* outlet_list;
    {
        uint32_t tlv1;
        tlv1 = breaker_id;
        outlet_list = cgc_get_outlet_list_on_breaker(tlv1);
    }
    node_t* outlet_node_ptr;
    {
        list_t* tlv2;
        tlv2 = outlet_list;
        outlet_node_ptr = cgc_get_first_node(tlv2);
    }
    while (cgc_get_list_tail(outlet_list) != outlet_node_ptr) {
 {
     outlet_t* tlv4;
     tlv4 = ( outlet_t * ) outlet_node_ptr -> data;
     uint32_t tlv3;
     tlv3 = receptacle_id;
    	r = cgc_search_outlet_for_receptacle_id(tlv4,tlv3);
 }
	if (NULL != r) {
	    break;
	}
	outlet_node_ptr = outlet_node_ptr->next;
    }
    return r;
}

void fix_ingred_assemble_18_2_3();
void fix_ingred_assemble_18_2_4();
void fix_ingred_assemble_18_2();
void fix_ingred_assemble_18_3_1();
void fix_ingred_assemble_18_3();
void fix_ingred_assemble_18();
static receptacle_t *cgc_get_receptacle_by_id(uint32_t receptacle_id)
{
if (fix_ingred_enable){ fix_ingred_assemble_18(); };
    receptacle_t* r;
    r = NULL;
    // for each breaker, check each outlet
    static uint8_t tlv1;
    tlv1 = cgc_load_center_is_created ( );
    if (TRUE == tlv1) {
	for (uint32_t breaker_idx = 0; breaker_idx < e_model->breakers_installed_cnt; breaker_idx++) {
	    // for each outlet on the breaker's circuit, check its loads
     {
         uint32_t tlv3;
         tlv3 = breaker_idx;
         uint32_t tlv2;
         tlv2 = receptacle_id;
    	    r = cgc_get_receptacle_by_id_from_breaker_id(tlv3,tlv2);
     }
	    if (NULL != r) {
		break;
	    }
	}
    }
    return r;
}

void fix_ingred_assemble_19();
static breaker_t *cgc_get_breaker_by_id(uint32_t breaker_id)
{
if (fix_ingred_enable){ fix_ingred_assemble_19(); };
    static uint8_t tlv1;
    tlv1 = cgc_load_center_is_created ( );
    if ((FALSE == tlv1) || (0 == e_model->breakers_installed_cnt)) {
	return NULL;
    }
    return &(e_model->breakers[breaker_id]);
}

void fix_ingred_assemble_20_2_2();
void fix_ingred_assemble_20_2();
void fix_ingred_assemble_20_6_5();
void fix_ingred_assemble_20_6_6();
void fix_ingred_assemble_20_6();
void fix_ingred_assemble_20();
static outlet_t *cgc_get_outlet_by_id(uint32_t outlet_id)
{
if (fix_ingred_enable){ fix_ingred_assemble_20(); };
    outlet_t* o;
    o = NULL;
    int8_t breakers_installed_cnt;
    breakers_installed_cnt = cgc_get_number_of_breakers_installed_in_load_center ( );
    if (0 > breakers_installed_cnt) {
	return NULL;
    }
    for (uint32_t breaker_id = 0; breaker_id < breakers_installed_cnt; breaker_id++) {
 list_t* outlet_list;
 {
     uint32_t tlv1;
     tlv1 = breaker_id;
     outlet_list = cgc_get_outlet_list_on_breaker(tlv1);
 }
 node_t* outlet_node_ptr;
 {
     list_t* tlv2;
     tlv2 = outlet_list;
     outlet_node_ptr = cgc_get_first_node(tlv2);
 }
	while (cgc_get_list_tail(outlet_list) != outlet_node_ptr) {
	    o = (outlet_t *) outlet_node_ptr->data;
	    if (outlet_id == o->id) {
		break;
	    } else {
		o = NULL;
	    }
	    outlet_node_ptr = outlet_node_ptr->next;
	}
    }
    return o;
}

void fix_ingred_assemble_21_2_2();
void fix_ingred_assemble_21_2();
void fix_ingred_assemble_21();
static n_way_splitter_t *cgc_get_splitter_by_id(uint32_t splitter_id)
{
if (fix_ingred_enable){ fix_ingred_assemble_21(); };
    n_way_splitter_t* s;
    s = NULL;
    int8_t breakers_installed_cnt;
    breakers_installed_cnt = cgc_get_number_of_breakers_installed_in_load_center ( );
    if (0 > breakers_installed_cnt) {
	return NULL;
    }
    for (uint32_t breaker_id = 0; breaker_id < breakers_installed_cnt; breaker_id++) {
 list_t* outlet_list;
 {
     uint32_t tlv1;
     tlv1 = breaker_id;
     outlet_list = cgc_get_outlet_list_on_breaker(tlv1);
 }
 node_t* outlet_node_ptr;
 {
     list_t* tlv2;
     tlv2 = outlet_list;
     outlet_node_ptr = cgc_get_first_node(tlv2);
 }
	while (cgc_get_list_tail(outlet_list) != outlet_node_ptr) {
     outlet_t* o;
     o = ( outlet_t * ) outlet_node_ptr -> data;
     {
         outlet_t* tlv4;
         tlv4 = o;
         uint32_t tlv3;
         tlv3 = splitter_id;
    	    s = cgc_search_outlet_for_splitter_id(tlv4,tlv3);
     }
	    if (NULL != s) {
		break;
	    }
	    outlet_node_ptr = outlet_node_ptr->next;
	}
    }
    return s;
}

void fix_ingred_assemble_22();
static light_string_t *cgc_get_light_string_by_id(uint32_t light_string_id)
{
if (fix_ingred_enable){ fix_ingred_assemble_22(); };
    light_string_t* ls;
    ls = NULL;
    int8_t breakers_installed_cnt;
    breakers_installed_cnt = cgc_get_number_of_breakers_installed_in_load_center ( );
    if (0 > breakers_installed_cnt) {
	return NULL;
    }
    for (uint32_t breaker_id = 0; breaker_id < breakers_installed_cnt; breaker_id++) {
 list_t* outlet_list;
 {
     uint32_t tlv1;
     tlv1 = breaker_id;
     outlet_list = cgc_get_outlet_list_on_breaker(tlv1);
 }
 node_t* outlet_node_ptr;
 {
     list_t* tlv2;
     tlv2 = outlet_list;
     outlet_node_ptr = cgc_get_first_node(tlv2);
 }
	while (cgc_get_list_tail(outlet_list) != outlet_node_ptr) {
     outlet_t* o;
     o = ( outlet_t * ) outlet_node_ptr -> data;
     {
         outlet_t* tlv4;
         tlv4 = o;
         uint32_t tlv3;
         tlv3 = light_string_id;
    	    ls = cgc_search_outlet_for_light_string_id(tlv4,tlv3);
     }
	    if (NULL != ls) {
		break;
	    }
	    outlet_node_ptr = outlet_node_ptr->next;
	}
    }
    return ls;
}

void fix_ingred_assemble_23_1_0();
void fix_ingred_assemble_23_1();
void fix_ingred_assemble_23();
static uint8_t cgc_breaker_id_is_installed(uint32_t breaker_id)
{
if (fix_ingred_enable){ fix_ingred_assemble_23(); };
    static breaker_t* tlv1;
    {
        uint32_t tlv2;
        tlv2 = breaker_id;
        tlv1 = cgc_get_breaker_by_id(tlv2);
    }
    if (NULL == tlv1) {
	return FALSE;
    } else {
	return TRUE;
    }
}

void fix_ingred_assemble_24();
static list_t *cgc_get_outlet_list_on_breaker(uint32_t breaker_id)
{
if (fix_ingred_enable){ fix_ingred_assemble_24(); };
    static uint8_t tlv1;
    {
        uint32_t tlv2;
        tlv2 = breaker_id;
        tlv1 = cgc_breaker_id_is_installed(tlv2);
    }
    if (FALSE == tlv1) {
	return NULL;
    }
    breaker_t* b;
    {
        uint32_t tlv3;
        tlv3 = breaker_id;
        b = cgc_get_breaker_by_id(tlv3);
    }
    return b->outlets;
}

void fix_ingred_assemble_25();
int32_t cgc_get_count_outlets_on_breaker(uint32_t breaker_id)
{
if (fix_ingred_enable){ fix_ingred_assemble_25(); };
    static uint8_t tlv1;
    {
        uint32_t tlv2;
        tlv2 = breaker_id;
        tlv1 = cgc_breaker_id_is_installed(tlv2);
    }
    if (FALSE == tlv1) {
	return ERR_INVALID_BREAKER_ID;
    }
    breaker_t* b;
    {
        uint32_t tlv3;
        tlv3 = breaker_id;
        b = cgc_get_breaker_by_id(tlv3);
    }
    return b->outlets->count;
}

void fix_ingred_assemble_26();
int8_t cgc_get_amp_rating_of_breaker(uint32_t breaker_id)
{
if (fix_ingred_enable){ fix_ingred_assemble_26(); };
    static uint8_t tlv1;
    {
        uint32_t tlv2;
        tlv2 = breaker_id;
        tlv1 = cgc_breaker_id_is_installed(tlv2);
    }
    if (FALSE == tlv1) {
	return ERR_INVALID_BREAKER_ID;
    }
    breaker_t* b;
    {
        uint32_t tlv3;
        tlv3 = breaker_id;
        b = cgc_get_breaker_by_id(tlv3);
    }
    return b->amp_rating;
}

void fix_ingred_assemble_27();
int8_t cgc_get_amp_rating_of_outlet(uint32_t outlet_id)
{
if (fix_ingred_enable){ fix_ingred_assemble_27(); };
    outlet_t* o;
    {
        uint32_t tlv1;
        tlv1 = outlet_id;
        o = cgc_get_outlet_by_id(tlv1);
    }
    if (NULL == o) {
	return ERR_INVALID_OUTLET_ID;
    } else {
	return o->amp_rating;
    }
}

void fix_ingred_assemble_28();
int8_t cgc_get_amp_rating_of_splitter(uint32_t splitter_id)
{
if (fix_ingred_enable){ fix_ingred_assemble_28(); };
    n_way_splitter_t* s;
    {
        uint32_t tlv1;
        tlv1 = splitter_id;
        s = cgc_get_splitter_by_id(tlv1);
    }
    if (NULL == s) {
	return ERR_INVALID_SPLITTER_ID;
    } else {
	return s->total_amp_rating;
    }
}

void fix_ingred_assemble_29();
float cgc_get_amp_rating_of_light_string(uint32_t light_string_id)
{
if (fix_ingred_enable){ fix_ingred_assemble_29(); };
    light_string_t* s;
    {
        uint32_t tlv1;
        tlv1 = light_string_id;
        s = cgc_get_light_string_by_id(tlv1);
    }
    if (NULL == s) {
	return (float) ERR_INVALID_LIGHT_STRING_ID;
    } else {
	return cgc_get_max_amps_of_light_string();
    }
}

void fix_ingred_assemble_30();
int8_t cgc_get_amp_rating_of_receptacle(uint32_t receptacle_id)
{
if (fix_ingred_enable){ fix_ingred_assemble_30(); };
    receptacle_t* r;
    {
        uint32_t tlv1;
        tlv1 = receptacle_id;
        r = cgc_get_receptacle_by_id(tlv1);
    }
    if (NULL == r) {
	return ERR_INVALID_RECEPTACLE_ID;
    } else {
	return r->amp_rating;
    }
}

void fix_ingred_assemble_31();
int8_t cgc_get_number_of_breakers_installed_in_load_center()
{
if (fix_ingred_enable){ fix_ingred_assemble_31(); };
    static uint8_t tlv1;
    tlv1 = cgc_load_center_is_created ( );
    if (FALSE == tlv1) {
	return ERR_E_MODEL_NOT_EXISTS;
    }
    return e_model->breakers_installed_cnt;
}

void fix_ingred_assemble_32();
int8_t cgc_get_total_breaker_space_count()
{
if (fix_ingred_enable){ fix_ingred_assemble_32(); };
    static uint8_t tlv1;
    tlv1 = cgc_load_center_is_created ( );
    if (FALSE == tlv1) {
	return ERR_E_MODEL_NOT_EXISTS;
    }
    return e_model->breaker_spaces;
}

void fix_ingred_assemble_33();
int32_t cgc_get_amp_rating_of_load_center()
{
if (fix_ingred_enable){ fix_ingred_assemble_33(); };
    static uint8_t tlv1;
    tlv1 = cgc_load_center_is_created ( );
    if (FALSE == tlv1) {
	return ERR_E_MODEL_NOT_EXISTS;
    }
    return e_model->amp_rating;
}

void fix_ingred_assemble_34_0_0();
void fix_ingred_assemble_34_0();
void fix_ingred_assemble_34_3_1();
void fix_ingred_assemble_34_3_2();
void fix_ingred_assemble_34_3();
void fix_ingred_assemble_34_4_0();
void fix_ingred_assemble_34_4();
void fix_ingred_assemble_34();
float cgc_get_total_amp_load_on_load_center()
{
if (fix_ingred_enable){ fix_ingred_assemble_34(); };
    static uint8_t tlv1;
    tlv1 = cgc_load_center_is_created ( );
    if (FALSE == tlv1) {
	return ERR_E_MODEL_NOT_EXISTS;
    }
    // sum amp loads of installed breakers
    float total_amp_load;
    total_amp_load = 0.0;
    int32_t breakers_installed_cnt;
    breakers_installed_cnt = cgc_get_number_of_breakers_installed_in_load_center ( );
    if (0 > breakers_installed_cnt) {
	return breakers_installed_cnt;
    }
    for (uint8_t idx = 0; idx < breakers_installed_cnt; idx++) {
 {
     uint32_t tlv2;
     tlv2 = idx;
    	total_amp_load += cgc_get_total_amp_load_on_breaker_by_breaker_id(tlv2);
 }
    }
    return total_amp_load;
}

void fix_ingred_assemble_35();
float cgc_get_total_amp_load_on_breaker_by_breaker_id(uint32_t breaker_id)
{
if (fix_ingred_enable){ fix_ingred_assemble_35(); };
    static uint8_t tlv1;
    {
        uint32_t tlv2;
        tlv2 = breaker_id;
        tlv1 = cgc_breaker_id_is_installed(tlv2);
    }
    if (FALSE == tlv1) {
	return ERR_INVALID_BREAKER_ID;
    }
    // sum amp loads of installed breakers
    float total_amp_load;
    total_amp_load = 0.0;
    list_t* outlet_list;
    {
        uint32_t tlv3;
        tlv3 = breaker_id;
        outlet_list = cgc_get_outlet_list_on_breaker(tlv3);
    }
    node_t* outlet_node_ptr;
    {
        list_t* tlv4;
        tlv4 = outlet_list;
        outlet_node_ptr = cgc_get_first_node(tlv4);
    }
    while (cgc_get_list_tail(outlet_list) != outlet_node_ptr) {
 {
     outlet_t* tlv5;
     tlv5 = ( outlet_t * ) outlet_node_ptr -> data;
    	total_amp_load += cgc_get_total_amp_load_on_outlet_by_outlet_va(tlv5);
 }
	outlet_node_ptr = outlet_node_ptr->next;
    }
    return total_amp_load;
}

void fix_ingred_assemble_36();
static float cgc_get_total_amp_load_on_outlet_by_outlet_va(outlet_t * outlet)
{
if (fix_ingred_enable){ fix_ingred_assemble_36(); };
    float total_amp_load;
    total_amp_load = 0.0;
    {
        receptacle_t* tlv1;
        tlv1 = & ( outlet -> r1 );
        total_amp_load += cgc_get_total_amp_load_on_receptacle_by_receptacle_va(tlv1);
    }
    {
        receptacle_t* tlv2;
        tlv2 = & ( outlet -> r2 );
        total_amp_load += cgc_get_total_amp_load_on_receptacle_by_receptacle_va(tlv2);
    }
    return total_amp_load;
}

void fix_ingred_assemble_37();
float cgc_get_total_amp_load_on_outlet_by_outlet_id(uint32_t outlet_id)
{
if (fix_ingred_enable){ fix_ingred_assemble_37(); };
    outlet_t* o;
    {
        uint32_t tlv1;
        tlv1 = outlet_id;
        o = cgc_get_outlet_by_id(tlv1);
    }
    if (NULL == o) {
	return ERR_INVALID_OUTLET_ID;
    } else {
	return cgc_get_total_amp_load_on_outlet_by_outlet_va(o);
    }
}

void fix_ingred_assemble_38();
static float cgc_get_total_amp_load_on_receptacle_by_receptacle_va(receptacle_t * receptacle)
{
if (fix_ingred_enable){ fix_ingred_assemble_38(); };
    float total_amp_load;
    total_amp_load = 0.0;
    static LOAD_TYPE_T tlv1;
    {
        receptacle_t* tlv3;
        tlv3 = receptacle;
        tlv1 = cgc_get_receptacle_load_type(tlv3);
    }
    if (SPLITTER == tlv1) {
 {
     n_way_splitter_t* tlv4;
     tlv4 = ( n_way_splitter_t * ) receptacle -> load;
    	total_amp_load = cgc_get_total_amp_load_on_splitter_by_splitter_va(tlv4);
 }
    } else {
 static LOAD_TYPE_T tlv2;
 {
     receptacle_t* tlv5;
     tlv5 = receptacle;
     tlv2 = cgc_get_receptacle_load_type(tlv5);
 }
	if (LIGHT_STRING == tlv2) {
     {
         light_string_t* tlv6;
         tlv6 = ( light_string_t * ) receptacle -> load;
    	    total_amp_load = cgc_get_total_amp_load_on_light_string_by_light_string_va(tlv6);
     }
	}
    }
    // NO_LOAD has no load, so go with default of 0.0
    return total_amp_load;
}

void fix_ingred_assemble_39();
float cgc_get_total_amp_load_on_receptacle_by_receptacle_id(uint32_t receptacle_id)
{
if (fix_ingred_enable){ fix_ingred_assemble_39(); };
    receptacle_t* r;
    {
        uint32_t tlv1;
        tlv1 = receptacle_id;
        r = cgc_get_receptacle_by_id(tlv1);
    }
    if (NULL == r) {
	return ERR_INVALID_RECEPTACLE_ID;
    } else {
	return cgc_get_total_amp_load_on_receptacle_by_receptacle_va(r);
    }
}

void fix_ingred_assemble_40();
static float cgc_get_total_amp_load_on_splitter_by_splitter_va(n_way_splitter_t * splitter)
{
if (fix_ingred_enable){ fix_ingred_assemble_40(); };
    float total_amp_load;
    total_amp_load = 0.0;
    for (int idx = 0; idx < splitter->receptacle_count; idx++) {
 {
     receptacle_t* tlv1;
     tlv1 = & ( splitter -> receptacles [ idx ] );
    	total_amp_load += cgc_get_total_amp_load_on_receptacle_by_receptacle_va(tlv1);
 }
    }
    return total_amp_load;
}

void fix_ingred_assemble_41();
float cgc_get_total_amp_load_on_splitter_by_splitter_id(uint32_t splitter_id)
{
if (fix_ingred_enable){ fix_ingred_assemble_41(); };
    n_way_splitter_t* s;
    {
        uint32_t tlv1;
        tlv1 = splitter_id;
        s = cgc_get_splitter_by_id(tlv1);
    }
    if (NULL == s) {
	return ERR_INVALID_SPLITTER_ID;
    } else {
	return cgc_get_total_amp_load_on_splitter_by_splitter_va(s);
    }
}

void fix_ingred_assemble_42_0_0();
void fix_ingred_assemble_42_0();
void fix_ingred_assemble_42_1_0();
void fix_ingred_assemble_42_1();
void fix_ingred_assemble_42();
static float cgc_get_total_amp_load_on_light_string_by_light_string_va(light_string_t * light_string)
{
if (fix_ingred_enable){ fix_ingred_assemble_42(); };
    float total_amp_load;
    total_amp_load = 0.0;
    {
        float tlv1;
        tlv1 = light_string -> total_wattage;
        total_amp_load += cgc_convert_watts_to_amps(tlv1);
    }
    {
        receptacle_t* tlv2;
        tlv2 = & ( light_string -> receptacle );
        total_amp_load += cgc_get_total_amp_load_on_receptacle_by_receptacle_va(tlv2);
    }
    return total_amp_load;
}

void fix_ingred_assemble_43();
float cgc_get_total_amp_load_on_light_string_by_light_string_id(uint32_t light_string_id)
{
if (fix_ingred_enable){ fix_ingred_assemble_43(); };
    light_string_t* ls;
    {
        uint32_t tlv1;
        tlv1 = light_string_id;
        ls = cgc_get_light_string_by_id(tlv1);
    }
    if (NULL == ls) {
	return ERR_INVALID_LIGHT_STRING_ID;
    } else {
	return cgc_get_total_amp_load_on_light_string_by_light_string_va(ls);
    }
}

void fix_ingred_assemble_44_3_0();
void fix_ingred_assemble_44_3_1();
void fix_ingred_assemble_44_3();
void fix_ingred_assemble_44();
static float cgc_get_max_receptacle_amp_load_on_outlet_by_outlet_va(outlet_t * outlet)
{
if (fix_ingred_enable){ fix_ingred_assemble_44(); };
    float r1_load;
    {
        receptacle_t* tlv1;
        tlv1 = & ( outlet -> r1 );
        r1_load = cgc_get_total_amp_load_on_receptacle_by_receptacle_va(tlv1);
    }
    float r2_load;
    {
        receptacle_t* tlv2;
        tlv2 = & ( outlet -> r2 );
        r2_load = cgc_get_total_amp_load_on_receptacle_by_receptacle_va(tlv2);
    }
    if (r1_load > r2_load) {
	return r1_load;
    } else {
	return r2_load;
    }
}

void fix_ingred_assemble_45();
float cgc_get_max_receptacle_amp_load_on_outlet_by_outlet_id(uint32_t outlet_id)
{
if (fix_ingred_enable){ fix_ingred_assemble_45(); };
    outlet_t* o;
    {
        uint32_t tlv1;
        tlv1 = outlet_id;
        o = cgc_get_outlet_by_id(tlv1);
    }
    if (NULL == o) {
	return ERR_INVALID_OUTLET_ID;
    } else {
	return cgc_get_max_receptacle_amp_load_on_outlet_by_outlet_va(o);
    }
}

void fix_ingred_assemble_46_0_0();
void fix_ingred_assemble_46_0();
void fix_ingred_assemble_46_3_0();
void fix_ingred_assemble_46_3_6();
void fix_ingred_assemble_46_3();
void fix_ingred_assemble_46();
static float cgc_get_max_receptacle_amp_load_on_splitter_by_splitter_va(n_way_splitter_t * splitter)
{
if (fix_ingred_enable){ fix_ingred_assemble_46(); };
    float max_amp_load;
    max_amp_load = 0.0;
    float tmp_amp_load;
    tmp_amp_load = 0.0;
    for (int idx = 0; idx < splitter->receptacle_count; idx++) {
 {
     receptacle_t* tlv1;
     tlv1 = & ( splitter -> receptacles [ idx ] );
    	tmp_amp_load = cgc_get_total_amp_load_on_receptacle_by_receptacle_va(tlv1);
 }
	if (tmp_amp_load > max_amp_load) {
	    max_amp_load = tmp_amp_load;
	}
    }
    return max_amp_load;
}

void fix_ingred_assemble_47();
float cgc_get_max_receptacle_amp_load_on_splitter_by_splitter_id(uint32_t splitter_id)
{
if (fix_ingred_enable){ fix_ingred_assemble_47(); };
    n_way_splitter_t* s;
    {
        uint32_t tlv1;
        tlv1 = splitter_id;
        s = cgc_get_splitter_by_id(tlv1);
    }
    if (NULL == s) {
	return ERR_INVALID_SPLITTER_ID;
    } else {
	return cgc_get_max_receptacle_amp_load_on_splitter_by_splitter_va(s);
    }
}

void fix_ingred_assemble_48();
int8_t cgc_init_electric_model(LOAD_CENTER_MODELS_T model_id)
{
if (fix_ingred_enable){ fix_ingred_assemble_48(); };
    static uint8_t tlv1;
    tlv1 = cgc_load_center_is_created ( );
    if (TRUE == tlv1) {
	return ERR_E_MODEL_EXISTS;
    }
    {
        LOAD_CENTER_MODELS_T tlv2;
        tlv2 = model_id;
        e_model = cgc_get_new_load_center_by_model_id(tlv2);
    }
    if (NULL == e_model) {
	return ERR_INVALID_MODEL_ID;
    } else {
	return SUCCESS;
    }
}

void fix_ingred_assemble_49_3_2();
void fix_ingred_assemble_49_3();
void fix_ingred_assemble_49();
int8_t cgc_add_breaker_to_load_center(CIRCUIT_MODELS_T model_id, assemble_result_t * result)
{
if (fix_ingred_enable){ fix_ingred_assemble_49(); };
    static uint8_t tlv1;
    tlv1 = cgc_load_center_is_created ( );
    if (FALSE == tlv1) {
	return ERR_E_MODEL_NOT_EXISTS;
    }
    static int8_t tlv2;
    tlv2 = cgc_load_center_breaker_spaces_are_full ( );
    if (TRUE == tlv2) {
	return ERR_BREAKER_SPACES_FULL;
    }
    breaker_t* breaker_space;
    breaker_space = & ( e_model -> breakers [ e_model -> breakers_installed_cnt ] );
    int8_t tlv3;
    {
        CIRCUIT_MODELS_T tlv6;
        tlv6 = model_id;
        breaker_t* tlv5;
        tlv5 = breaker_space;
        uint8_t tlv4;
        tlv4 = e_model -> breakers_installed_cnt;
        tlv3 = cgc_get_new_breaker_by_model_id(tlv6,tlv5,tlv4);
    }
    if (-1 == tlv3) {
	return ERR_INVALID_MODEL_ID;
    }
    result->object_id = e_model->breakers_installed_cnt++;
    return SUCCESS;
}

void fix_ingred_assemble_50_2_0();
void fix_ingred_assemble_50_2();
void fix_ingred_assemble_50_7_0();
void fix_ingred_assemble_50_7_1();
void fix_ingred_assemble_50_7();
void fix_ingred_assemble_50();
int8_t cgc_add_outlet_to_breaker(CIRCUIT_MODELS_T outlet_model_id, uint32_t breaker_id, assemble_result_t * result)
{
if (fix_ingred_enable){ fix_ingred_assemble_50(); };
    static uint8_t tlv1;
    tlv1 = cgc_load_center_is_created ( );
    if (FALSE == tlv1) {
	return ERR_E_MODEL_NOT_EXISTS;
    }
    breaker_t* breaker;
    {
        uint32_t tlv2;
        tlv2 = breaker_id;
        breaker = cgc_get_breaker_by_id(tlv2);
    }
    if (NULL == breaker) {
	return ERR_INVALID_BREAKER_ID;
    }
    outlet_t* o;
    {
        CIRCUIT_MODELS_T tlv3;
        tlv3 = outlet_model_id;
        o = cgc_get_new_outlet_by_model_id(tlv3);
    }
    if (NULL == o) {
	return ERR_INVALID_MODEL_ID;
    }
    // don't want a 20amp outlet on a 15amp breaker
    if (o->amp_rating > breaker->amp_rating) {
 {
     void* tlv5;
     tlv5 = ( void * ) o;
     cgc_size_t tlv4;
     tlv4 = sizeof ( outlet_t );
    	cgc_deallocate(tlv5,tlv4);
 }
	return ERR_OUTLET_AMPS_EXCEED_BREAKER_AMPS;
    }
    result->object_id = o->id;
    result->receptacle_id[0] = o->r1.id;
    result->receptacle_id[1] = o->r2.id;
    result->receptacle_ids_assigned_cnt = 2;
    return cgc_list_append(breaker->outlets, cgc_node_create((void *) o));
}

void fix_ingred_assemble_51_8_6();
void fix_ingred_assemble_51_8_7();
void fix_ingred_assemble_51_8();
void fix_ingred_assemble_51();
int8_t cgc_add_n_way_splitter_to_receptacle(SPLITTER_MODELS_T splitter_model_id, uint32_t receptacle_id, assemble_result_t * result)
{
if (fix_ingred_enable){ fix_ingred_assemble_51(); };
    static uint8_t tlv1;
    tlv1 = cgc_load_center_is_created ( );
    if (FALSE == tlv1) {
	return ERR_E_MODEL_NOT_EXISTS;
    }
    receptacle_t* r;
    {
        uint32_t tlv3;
        tlv3 = receptacle_id;
        r = cgc_get_receptacle_by_id(tlv3);
    }
    if (NULL == r) {
	return ERR_INVALID_RECEPTACLE_ID;
    }
    static int8_t tlv2;
    {
        receptacle_t* tlv4;
        tlv4 = r;
        tlv2 = cgc_receptacle_is_loaded(tlv4);
    }
    if (TRUE == tlv2) {
	return ERR_RECEPTACLE_FULL;
    }
    n_way_splitter_t* s;
    {
        SPLITTER_MODELS_T tlv5;
        tlv5 = splitter_model_id;
        s = cgc_get_new_n_way_splitter_by_model_id(tlv5);
    }
    if (NULL == s) {
	return ERR_INVALID_MODEL_ID;
    }
    // connect splitter to receptacle
    r->load_type = SPLITTER;
    r->load = (void *) s;
    r->amp_rating = s->total_amp_rating;
    // populate result
    result->object_id = s->id;
    result->receptacle_ids_assigned_cnt = s->receptacle_count;
    for (int i = 0; i < s->receptacle_count; i++) {
	result->receptacle_id[i] = s->receptacles[i].id;
    }
    return SUCCESS;
}

void fix_ingred_assemble_52();
int8_t cgc_add_light_string_to_receptacle(LIGHT_STRING_MODELS_T light_string_model_id, uint32_t receptacle_id, assemble_result_t * result)
{
if (fix_ingred_enable){ fix_ingred_assemble_52(); };
    static uint8_t tlv1;
    tlv1 = cgc_load_center_is_created ( );
    if (FALSE == tlv1) {
	return ERR_E_MODEL_NOT_EXISTS;
    }
    receptacle_t* r;
    {
        uint32_t tlv3;
        tlv3 = receptacle_id;
        r = cgc_get_receptacle_by_id(tlv3);
    }
    if (NULL == r) {
	return ERR_INVALID_RECEPTACLE_ID;
    }
    static int8_t tlv2;
    {
        receptacle_t* tlv4;
        tlv4 = r;
        tlv2 = cgc_receptacle_is_loaded(tlv4);
    }
    if (TRUE == tlv2) {
	return ERR_RECEPTACLE_FULL;
    }
    light_string_t* ls;
    {
        LIGHT_STRING_MODELS_T tlv5;
        tlv5 = light_string_model_id;
        ls = cgc_get_new_light_string_by_model_id(tlv5);
    }
    if (NULL == ls) {
	return ERR_INVALID_MODEL_ID;
    }
    // connect light string to receptacle
    r->load_type = LIGHT_STRING;
    r->load = (void *) ls;
    // populate result
    result->object_id = ls->id;
    result->receptacle_ids_assigned_cnt = 1;
    result->receptacle_id[0] = ls->receptacle.id;
    return SUCCESS;
}

void fix_ingred_assemble_0(){
}
void fix_ingred_assemble_1(){
}
void fix_ingred_assemble_2(){
}
void fix_ingred_assemble_3(){
}
void fix_ingred_assemble_4(){
}
void fix_ingred_assemble_5_1_2(){
uint32_t receptacle_id;
    bzero(&receptacle_id,sizeof(uint32_t));
receptacle_t receptacle_ref;
    bzero(&receptacle_ref,1*sizeof(receptacle_t));
receptacle_t * receptacle = &receptacle_ref;
    {uint32_t tlv4; tlv4 = (uint32_t)(receptacle_id); }
    {uint32_t tlv7; tlv7 = (uint32_t)(receptacle_id); }
}
void fix_ingred_assemble_5_1_3(){
uint32_t receptacle_id;
    bzero(&receptacle_id,sizeof(uint32_t));
receptacle_t receptacle_ref;
    bzero(&receptacle_ref,1*sizeof(receptacle_t));
receptacle_t * receptacle = &receptacle_ref;
    {uint32_t tlv4; tlv4 = (uint32_t)(receptacle -> id); }
    {uint32_t tlv7; tlv7 = (uint32_t)(receptacle -> id); }
}
void fix_ingred_assemble_5_1(){
fix_ingred_assemble_5_1_2();
fix_ingred_assemble_5_1_3();
}
void fix_ingred_assemble_5(){
fix_ingred_assemble_5_1();
}
void fix_ingred_assemble_6_1_1(){
uint32_t receptacle_id;
    bzero(&receptacle_id,sizeof(uint32_t));
    {uint32_t tlv1; tlv1 = (uint32_t)(receptacle_id); }
    {uint32_t tlv3; tlv3 = (uint32_t)(receptacle_id); }
}
void fix_ingred_assemble_6_1(){
fix_ingred_assemble_6_1_1();
}
void fix_ingred_assemble_6(){
fix_ingred_assemble_6_1();
}
void fix_ingred_assemble_7_1_1(){
uint32_t idx;
    bzero(&idx,sizeof(uint32_t));
n_way_splitter_t splitter_ref;
    bzero(&splitter_ref,1*sizeof(n_way_splitter_t));
n_way_splitter_t * splitter = &splitter_ref;
    {uint32_t tlv1; tlv1 = (uint32_t)(idx); }
}
void fix_ingred_assemble_7_1_2(){
uint32_t idx;
    bzero(&idx,sizeof(uint32_t));
n_way_splitter_t splitter_ref;
    bzero(&splitter_ref,1*sizeof(n_way_splitter_t));
n_way_splitter_t * splitter = &splitter_ref;
    {uint32_t tlv1; tlv1 = (uint32_t)(splitter -> receptacle_count); }
}
void fix_ingred_assemble_7_1(){
fix_ingred_assemble_7_1_1();
fix_ingred_assemble_7_1_2();
}
void fix_ingred_assemble_7(){
fix_ingred_assemble_7_1();
}
void fix_ingred_assemble_8(){
}
void fix_ingred_assemble_9_3_1(){
uint32_t splitter_id;
    bzero(&splitter_id,sizeof(uint32_t));
    {uint32_t tlv4; tlv4 = (uint32_t)(splitter_id); }
    {uint32_t tlv7; tlv7 = (uint32_t)(splitter_id); }
}
void fix_ingred_assemble_9_3(){
fix_ingred_assemble_9_3_1();
}
void fix_ingred_assemble_9(){
fix_ingred_assemble_9_3();
}
void fix_ingred_assemble_10(){
}
void fix_ingred_assemble_11_1_1(){
uint32_t splitter_id;
    bzero(&splitter_id,sizeof(uint32_t));
    {uint32_t tlv1; tlv1 = (uint32_t)(splitter_id); }
    {uint32_t tlv3; tlv3 = (uint32_t)(splitter_id); }
}
void fix_ingred_assemble_11_1(){
fix_ingred_assemble_11_1_1();
}
void fix_ingred_assemble_11(){
fix_ingred_assemble_11_1();
}
void fix_ingred_assemble_12_1_3(){
n_way_splitter_t splitter_ref;
    bzero(&splitter_ref,1*sizeof(n_way_splitter_t));
n_way_splitter_t * splitter = &splitter_ref;
    {uint32_t tlv1; tlv1 = (uint32_t)(splitter -> id); }
}
void fix_ingred_assemble_12_1(){
fix_ingred_assemble_12_1_3();
}
void fix_ingred_assemble_12_3_1(){
uint8_t idx;
    bzero(&idx,sizeof(uint8_t));
n_way_splitter_t splitter_ref;
    bzero(&splitter_ref,1*sizeof(n_way_splitter_t));
n_way_splitter_t * splitter = &splitter_ref;
    {uint32_t tlv1; tlv1 = (uint32_t)(idx); }
}
void fix_ingred_assemble_12_3_2(){
uint8_t idx;
    bzero(&idx,sizeof(uint8_t));
n_way_splitter_t splitter_ref;
    bzero(&splitter_ref,1*sizeof(n_way_splitter_t));
n_way_splitter_t * splitter = &splitter_ref;
    {uint32_t tlv1; tlv1 = (uint32_t)(splitter -> receptacle_count); }
}
void fix_ingred_assemble_12_3(){
fix_ingred_assemble_12_3_1();
fix_ingred_assemble_12_3_2();
}
void fix_ingred_assemble_12(){
fix_ingred_assemble_12_1();
fix_ingred_assemble_12_3();
}
void fix_ingred_assemble_13_3_1(){
uint32_t light_string_id;
    bzero(&light_string_id,sizeof(uint32_t));
    {uint32_t tlv4; tlv4 = (uint32_t)(light_string_id); }
    {uint32_t tlv7; tlv7 = (uint32_t)(light_string_id); }
}
void fix_ingred_assemble_13_3(){
fix_ingred_assemble_13_3_1();
}
void fix_ingred_assemble_13(){
fix_ingred_assemble_13_3();
}
void fix_ingred_assemble_14_1_2(){
uint32_t light_string_id;
    bzero(&light_string_id,sizeof(uint32_t));
light_string_t light_string_ref;
    bzero(&light_string_ref,1*sizeof(light_string_t));
light_string_t * light_string = &light_string_ref;
    {uint32_t tlv1; tlv1 = (uint32_t)(light_string_id); }
}
void fix_ingred_assemble_14_1_3(){
uint32_t light_string_id;
    bzero(&light_string_id,sizeof(uint32_t));
light_string_t light_string_ref;
    bzero(&light_string_ref,1*sizeof(light_string_t));
light_string_t * light_string = &light_string_ref;
    {uint32_t tlv1; tlv1 = (uint32_t)(light_string -> id); }
}
void fix_ingred_assemble_14_1(){
fix_ingred_assemble_14_1_2();
fix_ingred_assemble_14_1_3();
}
void fix_ingred_assemble_14(){
fix_ingred_assemble_14_1();
}
void fix_ingred_assemble_15_1_1(){
uint32_t light_string_id;
    bzero(&light_string_id,sizeof(uint32_t));
    {uint32_t tlv3; tlv3 = (uint32_t)(light_string_id); }
}
void fix_ingred_assemble_15_1(){
fix_ingred_assemble_15_1_1();
}
void fix_ingred_assemble_15(){
fix_ingred_assemble_15_1();
}
void fix_ingred_assemble_16_1_2(){
n_way_splitter_t s_ref;
    bzero(&s_ref,1*sizeof(n_way_splitter_t));
n_way_splitter_t * s = &s_ref;
    {uint32_t tlv1; tlv1 = (uint32_t)(s -> receptacle_count); }
}
void fix_ingred_assemble_16_1(){
fix_ingred_assemble_16_1_2();
}
void fix_ingred_assemble_16(){
fix_ingred_assemble_16_1();
}
void fix_ingred_assemble_17_1_0(){
uint32_t breaker_id;
    bzero(&breaker_id,sizeof(uint32_t));
    {uint32_t tlv1; tlv1 = (uint32_t)(breaker_id); }
    {uint32_t tlv3; tlv3 = (uint32_t)(breaker_id); }
}
void fix_ingred_assemble_17_1(){
fix_ingred_assemble_17_1_0();
}
void fix_ingred_assemble_17(){
fix_ingred_assemble_17_1();
}
void fix_ingred_assemble_18_2_3(){
uint32_t breaker_idx;
    bzero(&breaker_idx,sizeof(uint32_t));
    {uint32_t tlv3; tlv3 = (uint32_t)(breaker_idx); }
    {uint32_t tlv2; tlv2 = (uint32_t)(breaker_idx); }
}
void fix_ingred_assemble_18_2_4(){
uint32_t breaker_idx;
    bzero(&breaker_idx,sizeof(uint32_t));
    {uint32_t tlv3; tlv3 = (uint32_t)(e_model -> breakers_installed_cnt); }
    {uint32_t tlv2; tlv2 = (uint32_t)(e_model -> breakers_installed_cnt); }
}
void fix_ingred_assemble_18_2(){
fix_ingred_assemble_18_2_3();
fix_ingred_assemble_18_2_4();
}
void fix_ingred_assemble_18_3_1(){
uint32_t receptacle_id;
    bzero(&receptacle_id,sizeof(uint32_t));
    {uint32_t tlv2; tlv2 = (uint32_t)(receptacle_id); }
}
void fix_ingred_assemble_18_3(){
fix_ingred_assemble_18_3_1();
}
void fix_ingred_assemble_18(){
fix_ingred_assemble_18_2();
fix_ingred_assemble_18_3();
}
void fix_ingred_assemble_19(){
}
void fix_ingred_assemble_20_2_2(){
int8_t breakers_installed_cnt;
    bzero(&breakers_installed_cnt,sizeof(int8_t));
    {uint32_t tlv1; tlv1 = (uint32_t)(breakers_installed_cnt); }
}
void fix_ingred_assemble_20_2(){
fix_ingred_assemble_20_2_2();
}
void fix_ingred_assemble_20_6_5(){
uint32_t outlet_id;
    bzero(&outlet_id,sizeof(uint32_t));
outlet_t o_ref;
    bzero(&o_ref,1*sizeof(outlet_t));
outlet_t * o = &o_ref;
    {uint32_t tlv1; tlv1 = (uint32_t)(outlet_id); }
}
void fix_ingred_assemble_20_6_6(){
uint32_t outlet_id;
    bzero(&outlet_id,sizeof(uint32_t));
outlet_t o_ref;
    bzero(&o_ref,1*sizeof(outlet_t));
outlet_t * o = &o_ref;
    {uint32_t tlv1; tlv1 = (uint32_t)(o -> id); }
}
void fix_ingred_assemble_20_6(){
fix_ingred_assemble_20_6_5();
fix_ingred_assemble_20_6_6();
}
void fix_ingred_assemble_20(){
fix_ingred_assemble_20_2();
fix_ingred_assemble_20_6();
}
void fix_ingred_assemble_21_2_2(){
int8_t breakers_installed_cnt;
    bzero(&breakers_installed_cnt,sizeof(int8_t));
    {uint32_t tlv3; tlv3 = (uint32_t)(breakers_installed_cnt); }
}
void fix_ingred_assemble_21_2(){
fix_ingred_assemble_21_2_2();
}
void fix_ingred_assemble_21(){
fix_ingred_assemble_21_2();
}
void fix_ingred_assemble_22(){
}
void fix_ingred_assemble_23_1_0(){
uint32_t breaker_id;
    bzero(&breaker_id,sizeof(uint32_t));
    {uint32_t tlv2; tlv2 = (uint32_t)(breaker_id); }
}
void fix_ingred_assemble_23_1(){
fix_ingred_assemble_23_1_0();
}
void fix_ingred_assemble_23(){
fix_ingred_assemble_23_1();
}
void fix_ingred_assemble_24(){
}
void fix_ingred_assemble_25(){
}
void fix_ingred_assemble_26(){
}
void fix_ingred_assemble_27(){
}
void fix_ingred_assemble_28(){
}
void fix_ingred_assemble_29(){
}
void fix_ingred_assemble_30(){
}
void fix_ingred_assemble_31(){
}
void fix_ingred_assemble_32(){
}
void fix_ingred_assemble_33(){
}
void fix_ingred_assemble_34_0_0(){
    {float total_amp_load; total_amp_load = (float)(0.0); }
}
void fix_ingred_assemble_34_0(){
fix_ingred_assemble_34_0_0();
}
void fix_ingred_assemble_34_3_1(){
uint8_t idx;
    bzero(&idx,sizeof(uint8_t));
int32_t breakers_installed_cnt;
    bzero(&breakers_installed_cnt,sizeof(int32_t));
    {uint32_t tlv2; tlv2 = (uint32_t)(idx); }
}
void fix_ingred_assemble_34_3_2(){
uint8_t idx;
    bzero(&idx,sizeof(uint8_t));
int32_t breakers_installed_cnt;
    bzero(&breakers_installed_cnt,sizeof(int32_t));
    {uint32_t tlv2; tlv2 = (uint32_t)(breakers_installed_cnt); }
}
void fix_ingred_assemble_34_3(){
fix_ingred_assemble_34_3_1();
fix_ingred_assemble_34_3_2();
}
void fix_ingred_assemble_34_4_0(){
uint8_t idx;
    bzero(&idx,sizeof(uint8_t));
    {uint32_t tlv2; tlv2 = (uint32_t)(idx); }
}
void fix_ingred_assemble_34_4(){
fix_ingred_assemble_34_4_0();
}
void fix_ingred_assemble_34(){
fix_ingred_assemble_34_0();
fix_ingred_assemble_34_3();
fix_ingred_assemble_34_4();
}
void fix_ingred_assemble_35(){
}
void fix_ingred_assemble_36(){
}
void fix_ingred_assemble_37(){
}
void fix_ingred_assemble_38(){
}
void fix_ingred_assemble_39(){
}
void fix_ingred_assemble_40(){
}
void fix_ingred_assemble_41(){
}
void fix_ingred_assemble_42_0_0(){
    {float tlv1; tlv1 = (float)(0.0); }
}
void fix_ingred_assemble_42_0(){
fix_ingred_assemble_42_0_0();
}
void fix_ingred_assemble_42_1_0(){
light_string_t light_string_ref;
    bzero(&light_string_ref,1*sizeof(light_string_t));
light_string_t * light_string = &light_string_ref;
    {float total_amp_load; total_amp_load = (float)(light_string -> total_wattage); }
    {float tlv1; tlv1 = (float)(light_string -> total_wattage); }
}
void fix_ingred_assemble_42_1(){
fix_ingred_assemble_42_1_0();
}
void fix_ingred_assemble_42(){
fix_ingred_assemble_42_0();
fix_ingred_assemble_42_1();
}
void fix_ingred_assemble_43(){
}
void fix_ingred_assemble_44_3_0(){
float r1_load;
    bzero(&r1_load,sizeof(float));
float r2_load;
    bzero(&r2_load,sizeof(float));
    {float r2_load; r2_load = (float)(r1_load); }
}
void fix_ingred_assemble_44_3_1(){
float r1_load;
    bzero(&r1_load,sizeof(float));
float r2_load;
    bzero(&r2_load,sizeof(float));
    {float r1_load; r1_load = (float)(r2_load); }
}
void fix_ingred_assemble_44_3(){
fix_ingred_assemble_44_3_0();
fix_ingred_assemble_44_3_1();
}
void fix_ingred_assemble_44(){
fix_ingred_assemble_44_3();
}
void fix_ingred_assemble_45(){
}
void fix_ingred_assemble_46_0_0(){
    {float max_amp_load; max_amp_load = (float)(0.0); }
    {float tmp_amp_load; tmp_amp_load = (float)(0.0); }
}
void fix_ingred_assemble_46_0(){
fix_ingred_assemble_46_0_0();
}
void fix_ingred_assemble_46_3_0(){
float tmp_amp_load;
    bzero(&tmp_amp_load,sizeof(float));
float max_amp_load;
    bzero(&max_amp_load,sizeof(float));
    {float max_amp_load; max_amp_load = (float)(tmp_amp_load); }
}
void fix_ingred_assemble_46_3_6(){
float tmp_amp_load;
    bzero(&tmp_amp_load,sizeof(float));
float max_amp_load;
    bzero(&max_amp_load,sizeof(float));
    {float tmp_amp_load; tmp_amp_load = (float)(max_amp_load); }
}
void fix_ingred_assemble_46_3(){
fix_ingred_assemble_46_3_0();
fix_ingred_assemble_46_3_6();
}
void fix_ingred_assemble_46(){
fix_ingred_assemble_46_0();
fix_ingred_assemble_46_3();
}
void fix_ingred_assemble_47(){
}
void fix_ingred_assemble_48(){
}
void fix_ingred_assemble_49_3_2(){
    {uint8_t tlv4; tlv4 = (uint8_t)(e_model -> breakers_installed_cnt); }
}
void fix_ingred_assemble_49_3(){
fix_ingred_assemble_49_3_2();
}
void fix_ingred_assemble_49(){
fix_ingred_assemble_49_3();
}
void fix_ingred_assemble_50_2_0(){
uint32_t breaker_id;
    bzero(&breaker_id,sizeof(uint32_t));
    {void * tlv5; tlv5 = (void *)(breaker_id); }
    {cgc_size_t tlv4; tlv4 = (cgc_size_t)(breaker_id); }
}
void fix_ingred_assemble_50_2(){
fix_ingred_assemble_50_2_0();
}
void fix_ingred_assemble_50_7_0(){
outlet_t o_ref;
    bzero(&o_ref,1*sizeof(outlet_t));
outlet_t * o = &o_ref;
    {uint32_t tlv2; tlv2 = (uint32_t)(( void * ) o); }
    {void * tlv5; tlv5 = (void *)(( void * ) o); }
    {cgc_size_t tlv4; tlv4 = (cgc_size_t)(( void * ) o); }
}
void fix_ingred_assemble_50_7_1(){
outlet_t o_ref;
    bzero(&o_ref,1*sizeof(outlet_t));
outlet_t * o = &o_ref;
    {uint32_t tlv2; tlv2 = (uint32_t)(sizeof ( outlet_t )); }
    {void * tlv5; tlv5 = (void *)(sizeof ( outlet_t )); }
    {cgc_size_t tlv4; tlv4 = (cgc_size_t)(sizeof ( outlet_t )); }
}
void fix_ingred_assemble_50_7(){
fix_ingred_assemble_50_7_0();
fix_ingred_assemble_50_7_1();
}
void fix_ingred_assemble_50(){
fix_ingred_assemble_50_2();
fix_ingred_assemble_50_7();
}
void fix_ingred_assemble_51_8_6(){
int i;
    bzero(&i,sizeof(int));
n_way_splitter_t s_ref;
    bzero(&s_ref,1*sizeof(n_way_splitter_t));
n_way_splitter_t * s = &s_ref;
    {uint32_t tlv3; tlv3 = (uint32_t)(i); }
}
void fix_ingred_assemble_51_8_7(){
int i;
    bzero(&i,sizeof(int));
n_way_splitter_t s_ref;
    bzero(&s_ref,1*sizeof(n_way_splitter_t));
n_way_splitter_t * s = &s_ref;
    {uint32_t tlv3; tlv3 = (uint32_t)(s -> receptacle_count); }
}
void fix_ingred_assemble_51_8(){
fix_ingred_assemble_51_8_6();
fix_ingred_assemble_51_8_7();
}
void fix_ingred_assemble_51(){
fix_ingred_assemble_51_8();
}
void fix_ingred_assemble_52(){
}
