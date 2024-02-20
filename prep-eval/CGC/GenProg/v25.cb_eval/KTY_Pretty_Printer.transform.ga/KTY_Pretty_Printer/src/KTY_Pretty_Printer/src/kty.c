

#include "cgc_stdlib.h"
#include "cgc_string.h"
#include "cgc_kty.h"
#include "cgc_strdup.h"
#include "cgc_strncmp.h"
#include "cgc_strtod.h"
kty_parser_t *g_parser;
void cgc_kty_print_item(kty_item_t * item, int depth);
char *cgc_parse_item(kty_item_t * item, char *str);
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

void fix_ingred_kty_0();
char *cgc_eat_ws(char *str)
{
if (fix_ingred_enable){ fix_ingred_kty_0(); };
    while (str && str[0] && str[0] <= ' ')
    {
	str++;
    }
    return str;
}

void fix_ingred_kty_1_0_0();
void fix_ingred_kty_1_0();
void fix_ingred_kty_1_4_0();
void fix_ingred_kty_1_4();
void fix_ingred_kty_1();
void cgc_print_escaped(char *str, int len)
{
if (fix_ingred_enable){ fix_ingred_kty_1(); };
    int i;
    i = 0;
    char c[2]={0};
    char tmp[2]={0};
    char hex_nums[] = "0123456789ABCDEF";
    while (len--) {
	c[0] = str[i++];
	switch (c[0]) {
	case '"':
	    {
  {
      int tlv2;
      tlv2 = STDOUT;
      const char tlv1 [ ] = "\\\"";
    		cgc_fdprintf(tlv2,tlv1);
  }
	    }
	    break;
	case '\\':
	    {
  {
      int tlv4;
      tlv4 = STDOUT;
      const char tlv3 [ ] = "\\\\";
    		cgc_fdprintf(tlv4,tlv3);
  }
	    }
	    break;
	case '/':
	    {
  {
      int tlv6;
      tlv6 = STDOUT;
      const char tlv5 [ ] = "\\/";
    		cgc_fdprintf(tlv6,tlv5);
  }
	    }
	    break;
	case '\b':
	    {
  {
      int tlv8;
      tlv8 = STDOUT;
      const char tlv7 [ ] = "\\b";
    		cgc_fdprintf(tlv8,tlv7);
  }
	    }
	    break;
	case '\f':
	    {
  {
      int tlv10;
      tlv10 = STDOUT;
      const char tlv9 [ ] = "\\f";
    		cgc_fdprintf(tlv10,tlv9);
  }
	    }
	    break;
	case '\n':
	    {
  {
      int tlv12;
      tlv12 = STDOUT;
      const char tlv11 [ ] = "\\n";
    		cgc_fdprintf(tlv12,tlv11);
  }
	    }
	    break;
	case '\r':
	    {
  {
      int tlv14;
      tlv14 = STDOUT;
      const char tlv13 [ ] = "\\r";
    		cgc_fdprintf(tlv14,tlv13);
  }
	    }
	    break;
	case '\t':
	    {
  {
      int tlv16;
      tlv16 = STDOUT;
      const char tlv15 [ ] = "\\t";
    		cgc_fdprintf(tlv16,tlv15);
  }
	    }
	    break;
	default:
	    {
		cgc_fdprintf(STDOUT, "%s", c);
	    }
	    break;
	}
    }
}

void fix_ingred_kty_2_1_1();
void fix_ingred_kty_2_1_2();
void fix_ingred_kty_2_1();
void fix_ingred_kty_2();
void cgc_print_indent(int depth)
{
if (fix_ingred_enable){ fix_ingred_kty_2(); };
    int i;
    for (i = 0; i < depth * 2; ++i)
    {
 {
     int tlv2;
     tlv2 = STDOUT;
     const char tlv1 [ ] = " ";
    	cgc_fdprintf(tlv2,tlv1);
 }
    }
}

void fix_ingred_kty_3();
void cgc_kty_int_to_string(kty_item_t * item)
{
if (fix_ingred_enable){ fix_ingred_kty_3(); };
    cgc_fdprintf(STDOUT, "%d", item->item.i_int);
}

void fix_ingred_kty_4_0_1();
void fix_ingred_kty_4_0();
void fix_ingred_kty_4_1_3();
void fix_ingred_kty_4_1_4();
void fix_ingred_kty_4_1_5();
void fix_ingred_kty_4_1();
void fix_ingred_kty_4_2_0();
void fix_ingred_kty_4_2();
void fix_ingred_kty_4_3_0();
void fix_ingred_kty_4_3();
void fix_ingred_kty_4();
void cgc_kty_double_to_string(kty_item_t * item)
{
if (fix_ingred_enable){ fix_ingred_kty_4(); };
    int tmp;
    double val;
    val = item->item.i_double;
    tmp = (int) val;
    if (val < 0.0 && tmp == 0) {
 {
     int tlv2;
     tlv2 = STDOUT;
     const char tlv1 [ ] = "-";
    	cgc_fdprintf(tlv2,tlv1);
 }
    }
    cgc_fdprintf(STDOUT, "%d.", tmp);
    tmp = ((int) (val * 100.0)) % 100;
    if (tmp < 0) {
	tmp = -tmp;
    }
    cgc_fdprintf(STDOUT, "%02d", tmp);
}

void fix_ingred_kty_5_1_0();
void fix_ingred_kty_5_1();
void fix_ingred_kty_5();
void cgc_kty_string_to_string(kty_item_t * item)
{
if (fix_ingred_enable){ fix_ingred_kty_5(); };
    {
        int tlv2;
        tlv2 = STDOUT;
        const char tlv1 [ ] = "\"";
        cgc_fdprintf(tlv2,tlv1);
    }
    {
        char* tlv4;
         tlv4 = item -> item . i_string . s;
        int tlv3;
        tlv3 = item -> item . i_string . len;
        cgc_print_escaped(tlv4,tlv3);
    }
    {
        int tlv6;
        tlv6 = STDOUT;
        const char tlv5 [ ] = "\"";
        cgc_fdprintf(tlv6,tlv5);
    }
}

void fix_ingred_kty_6_0_0();
void fix_ingred_kty_6_0();
void fix_ingred_kty_6_1_0();
void fix_ingred_kty_6_1();
void fix_ingred_kty_6_5_6();
void fix_ingred_kty_6_5();
void fix_ingred_kty_6_7_0();
void fix_ingred_kty_6_7();
void fix_ingred_kty_6_9_0();
void fix_ingred_kty_6_9();
void fix_ingred_kty_6_10_0();
void fix_ingred_kty_6_10();
void fix_ingred_kty_6();
void cgc_kty_object_to_string(kty_item_t * item, int depth)
{
if (fix_ingred_enable){ fix_ingred_kty_6(); };
    int count;
    count = 0;
    htbl_t *table;
    entry_t *entry;
    {
        int tlv2;
        tlv2 = STDOUT;
        const char tlv1 [ ] = "{";
        cgc_fdprintf(tlv2,tlv1);
    }
    table = item->item.i_object;
    if (table) {
 {
     int tlv6;
     tlv6 = STDOUT;
     const char tlv5 [ ] = "\n";
    	cgc_fdprintf(tlv6,tlv5);
 }
	for (entry = table->head; entry != NULL; entry = entry->next) {
	    if (count > 0) {
  {
      int tlv19;
      tlv19 = STDOUT;
      const char tlv18 [ ] = ",\n";
    		cgc_fdprintf(tlv19,tlv18);
  }
	    }
	    count++;
     {
         int tlv9;
         tlv9 = depth + 1;
    	    cgc_print_indent(tlv9);
     }
     {
         int tlv11;
         tlv11 = STDOUT;
         const char tlv10 [ ] = "\"";
    	    cgc_fdprintf(tlv11,tlv10);
     }
     {
         char* tlv13;
          tlv13 = entry -> key;
         int tlv12;
         {
             const char* tlv20 = entry -> key;
             tlv12 = cgc_strlen(tlv20);
         }
    	    cgc_print_escaped(tlv13,tlv12);
     }
     {
         int tlv15;
         tlv15 = STDOUT;
         const char tlv14 [ ] = "\": ";
    	    cgc_fdprintf(tlv15,tlv14);
     }
     {
         kty_item_t* tlv17;
         tlv17 = entry -> val;
         int tlv16;
         tlv16 = depth + 1;
    	    cgc_kty_print_item(tlv17,tlv16);
     }
	}
    }
    if (count > 0) {
 {
     int tlv8;
     tlv8 = STDOUT;
     const char tlv7 [ ] = "\n";
    	cgc_fdprintf(tlv8,tlv7);
 }
	cgc_print_indent(depth);
    }
    {
        int tlv4;
        tlv4 = STDOUT;
        const char tlv3 [ ] = "}";
        cgc_fdprintf(tlv4,tlv3);
    }
}

void fix_ingred_kty_7_0_0();
void fix_ingred_kty_7_0();
void fix_ingred_kty_7_1_0();
void fix_ingred_kty_7_1();
void fix_ingred_kty_7_3_1();
void fix_ingred_kty_7_3();
void fix_ingred_kty_7_5_2();
void fix_ingred_kty_7_5();
void fix_ingred_kty_7_6_3();
void fix_ingred_kty_7_6();
void fix_ingred_kty_7_8_0();
void fix_ingred_kty_7_8();
void fix_ingred_kty_7();
void cgc_kty_array_to_string(kty_item_t * item, int depth)
{
if (fix_ingred_enable){ fix_ingred_kty_7(); };
    int i;
    int count;
    count = 0;
    kty_item_t *elem;
    {
        int tlv3;
        tlv3 = STDOUT;
        const char tlv2 [ ] = "[";
        cgc_fdprintf(tlv3,tlv2);
    }
    int tlv1;
    {
        array_t* tlv6;
        tlv6 = item -> item . i_array;
        tlv1 = cgc_array_length(tlv6);
    }
    if (tlv1 > 0) {
 {
     int tlv8;
     tlv8 = STDOUT;
     const char tlv7 [ ] = "\n";
    	cgc_fdprintf(tlv8,tlv7);
 }
    }
    for (i = 0; i < cgc_array_length(item->item.i_array); ++i) {
	if (count > 0) {
     {
         int tlv17;
         tlv17 = STDOUT;
         const char tlv16 [ ] = ",\n";
    	    cgc_fdprintf(tlv17,tlv16);
     }
	}
	count++;
 {
     int tlv9;
     tlv9 = depth + 1;
    	cgc_print_indent(tlv9);
 }
 {
     array_t* tlv15;
     tlv15 = item -> item . i_array;
     int tlv14;
     tlv14 = i;
    	elem = cgc_array_get(tlv15,tlv14);
 }
 {
     kty_item_t* tlv11;
     tlv11 = elem;
     int tlv10;
     tlv10 = depth + 1;
    	cgc_kty_print_item(tlv11,tlv10);
 }
    }
    if (count > 0) {
 {
     int tlv13;
     tlv13 = STDOUT;
     const char tlv12 [ ] = "\n";
    	cgc_fdprintf(tlv13,tlv12);
 }
	cgc_print_indent(depth);
    }
    {
        int tlv5;
        tlv5 = STDOUT;
        const char tlv4 [ ] = "]";
        cgc_fdprintf(tlv5,tlv4);
    }
}

void fix_ingred_kty_8();
void cgc_kty_boolean_to_string(kty_item_t * item)
{
if (fix_ingred_enable){ fix_ingred_kty_8(); };
    cgc_fdprintf(STDOUT, "%s", item->item.i_bool ? "true" : "false");
}

void fix_ingred_kty_9();
void cgc_kty_null_to_string(kty_item_t * item)
{
if (fix_ingred_enable){ fix_ingred_kty_9(); };
    {
        int tlv2;
        tlv2 = STDOUT;
        const char tlv1 [ ] = "null";
        cgc_fdprintf(tlv2,tlv1);
    }
}

void fix_ingred_kty_10();
void cgc_kty_cat_to_string(kty_item_t * item)
{
if (fix_ingred_enable){ fix_ingred_kty_10(); };
    g_parser->cats++;
    {
        int tlv2;
        tlv2 = STDOUT;
        const char tlv1 [ ] = "=^.^=";
        cgc_fdprintf(tlv2,tlv1);
    }
}

void fix_ingred_kty_11_6_1();
void fix_ingred_kty_11_6();
void fix_ingred_kty_11();
void cgc_kty_print_item(kty_item_t * item, int depth)
{
if (fix_ingred_enable){ fix_ingred_kty_11(); };
    switch (item->type) {
    case KTY_INT:
	{
	    cgc_kty_int_to_string(item);
	}
	break;
    case KTY_DOUBLE:
	{
	    cgc_kty_double_to_string(item);
	}
	break;
    case KTY_STRING:
	{
	    cgc_kty_string_to_string(item);
	}
	break;
    case KTY_OBJECT:
	{
     {
         kty_item_t* tlv2;
         tlv2 = item;
         int tlv1;
         tlv1 = depth;
    	    cgc_kty_object_to_string(tlv2,tlv1);
     }
	}
	break;
    case KTY_ARRAY:
	{
     {
         kty_item_t* tlv4;
         tlv4 = item;
         int tlv3;
         tlv3 = depth;
    	    cgc_kty_array_to_string(tlv4,tlv3);
     }
	}
	break;
    case KTY_BOOLEAN:
	{
	    cgc_kty_boolean_to_string(item);
	}
	break;
    case KTY_NULL:
	{
	    cgc_kty_null_to_string(item);
	}
	break;
    case KTY_CAT:
	{
	    cgc_kty_cat_to_string(item);
	}
	break;
    default:
	{
	    break;
	}
    }
}

void fix_ingred_kty_12_0_0();
void fix_ingred_kty_12_0();
void fix_ingred_kty_12();
void cgc_kty_dumps(kty_item_t * kty)
{
if (fix_ingred_enable){ fix_ingred_kty_12(); };
    int depth;
    depth = 0;
    g_parser->cats = 0;
    if (kty) {
 {
     kty_item_t* tlv2;
     tlv2 = kty;
     int tlv1;
     tlv1 = depth;
    	cgc_kty_print_item(tlv2,tlv1);
 }
    }
}

void fix_ingred_kty_13_1_0();
void fix_ingred_kty_13_1();
void fix_ingred_kty_13_2_0();
void fix_ingred_kty_13_2_1();
void fix_ingred_kty_13_2();
void fix_ingred_kty_13_3_0();
void fix_ingred_kty_13_3();
void fix_ingred_kty_13_5_0();
void fix_ingred_kty_13_5();
void fix_ingred_kty_13_7_0();
void fix_ingred_kty_13_7();
void fix_ingred_kty_13_8_0();
void fix_ingred_kty_13_8();
void fix_ingred_kty_13_9_2();
void fix_ingred_kty_13_9();
void fix_ingred_kty_13_12_1();
void fix_ingred_kty_13_12();
void fix_ingred_kty_13();
char *cgc_parse_number(kty_item_t * item, char *str)
{
if (fix_ingred_enable){ fix_ingred_kty_13(); };
    char decimal[3] = { 0 };
    char *c1;
    char *c2;
    int i;
    double d;
    {
        const char* tlv2 = str;
        int tlv1;
        tlv1 = ' ';
        c1 = cgc_strchr(tlv2,tlv1);
    }
    if (c1 == NULL) {
 {
     const char* tlv6 = str;
     int tlv5;
     tlv5 = ',';
    	c1 = cgc_strchr(tlv6,tlv5);
 }
    }
    if (c1 == NULL) {
 {
     const char* tlv8 = str;
     int tlv7;
     tlv7 = ']';
    	c1 = cgc_strchr(tlv8,tlv7);
 }
    }
    if (c1 == NULL) {
 {
     const char* tlv10 = str;
     int tlv9;
     tlv9 = '}';
    	c1 = cgc_strchr(tlv10,tlv9);
 }
    }
    {
        const char* tlv4 = str;
        int tlv3;
        tlv3 = '.';
        c2 = cgc_strchr(tlv4,tlv3);
    }
    if ((c1 && c2 && c2 < c1) || (c2 && c1 == NULL)) {
	// Double
 {
     const char* tlv12 = str;
     char** tlv11;
      tlv11 = & str;
    	d = cgc_strtod(tlv12,tlv11);
 }
	item->type = KTY_DOUBLE;
	item->item.i_double = d;
    } else {
	// Int
 {
     const char* tlv15 = str;
     char** tlv14;
      tlv14 = & str;
     int tlv13;
     tlv13 = 10;
    	i = cgc_strtol(tlv15,tlv14,tlv13);
 }
	item->type = KTY_INT;
	item->item.i_int = i;
    }
    return str;
}

void fix_ingred_kty_14_0_0();
void fix_ingred_kty_14_0_2();
void fix_ingred_kty_14_0_6();
void fix_ingred_kty_14_0();
void fix_ingred_kty_14_1_5();
void fix_ingred_kty_14_1_6();
void fix_ingred_kty_14_1();
void fix_ingred_kty_14_2_5();
void fix_ingred_kty_14_2();
void fix_ingred_kty_14_3_8();
void fix_ingred_kty_14_3();
void fix_ingred_kty_14_4_5();
void fix_ingred_kty_14_4_6();
void fix_ingred_kty_14_4();
void fix_ingred_kty_14_5_0();
void fix_ingred_kty_14_5();
void fix_ingred_kty_14();
char *cgc_parse_string(kty_item_t * item, char *str)
{
if (fix_ingred_enable){ fix_ingred_kty_14(); };
    int cgc_read;
    cgc_read = 0;
    int len;
    len = 0;
    char* c;
     c = str + 1;
    item->type = KTY_STRING;
    item->item.i_string.s = NULL;
    if (str[0] != '\"') {
	return NULL;
    }
    while (c[0] && c[0] != '\"') {
	if (c[0] == '\\') {
	    c++;
	    cgc_read++;
	}
	c++;
	len++;
	cgc_read++;
    }
    if (len >= MAX_KTY_STRING) {
	return NULL;
    }
    {
        cgc_size_t tlv1;
        tlv1 = len + 1;
        item->item.i_string.s = cgc_malloc(tlv1);
    }
    if (item->item.i_string.s == NULL) {
	return NULL;
    }
    c = str + 1;
    cgc_read += 2;
    len = 0;
    while (c[0] && c[0] != '\"') {
	if (c[0] == '\\') {
	    c++;
	    switch (c[0]) {
	    case 'b':
		{
		    item->item.i_string.s[len] = '\b';
		}
		break;
	    case 'f':
		{
		    item->item.i_string.s[len] = '\f';
		}
		break;
	    case 'n':
		{
		    item->item.i_string.s[len] = '\n';
		}
		break;
	    case 'r':
		{
		    item->item.i_string.s[len] = '\r';
		}
		break;
	    case 't':
		{
		    item->item.i_string.s[len] = '\t';
		}
		break;
	    default:
		{
		    item->item.i_string.s[len] = c[0];
		}
		break;
	    }
	} else {
	    item->item.i_string.s[len] = c[0];
	}
	c++;
	len++;
    }
    item->item.i_string.s[len] = '\0';
    item->item.i_string.len = len;
    return str + cgc_read;
}

void fix_ingred_kty_15_1_0();
void fix_ingred_kty_15_1();
void fix_ingred_kty_15_2_2();
void fix_ingred_kty_15_2_3();
void fix_ingred_kty_15_2();
void fix_ingred_kty_15_3_0();
void fix_ingred_kty_15_3();
void fix_ingred_kty_15_5_0();
void fix_ingred_kty_15_5();
void fix_ingred_kty_15_9_0();
void fix_ingred_kty_15_9();
void fix_ingred_kty_15_10_3();
void fix_ingred_kty_15_10();
void fix_ingred_kty_15_11_1();
void fix_ingred_kty_15_11();
void fix_ingred_kty_15_12_5();
void fix_ingred_kty_15_12();
void fix_ingred_kty_15();
char *cgc_parse_array(kty_item_t * item, char *str)
{
if (fix_ingred_enable){ fix_ingred_kty_15(); };
    kty_item_t *new;
    item->type = KTY_ARRAY;
    item->item.i_array = NULL;
    {
        char* tlv3;
         tlv3 = str + 1;
        str = cgc_eat_ws(tlv3);
    }
    if (str[0] == ']') {
	return str + 1;
    }
    {
        cgc_size_t tlv7;
        tlv7 = sizeof ( kty_item_t );
        new = (kty_item_t *) cgc_malloc(tlv7);
    }
    if (new == NULL) {
	goto fail;
    }
    {
        int tlv5;
        tlv5 = 4;
        free_element_fn* tlv4 = cgc_free_kty_item;
        item->item.i_array = cgc_array_create(tlv5,tlv4);
    }
    if (item->item.i_array == NULL) {
	goto fail;
    }
    {
        char* tlv6;
         {
             kty_item_t* tlv13;
             tlv13 = new;
             char* tlv12;
              {
                  char* tlv16;
                   tlv16 = str;
                  tlv12 = cgc_eat_ws(tlv16);
              }
             tlv6 = cgc_parse_item(tlv13,tlv12);
         }
        str = cgc_eat_ws(tlv6);
    }
    if (str == NULL) {
	goto fail;
    }
    {
        array_t* tlv2;
        tlv2 = item -> item . i_array;
        void* tlv1;
        tlv1 = new;
        cgc_array_append(tlv2,tlv1);
    }
    new = NULL;
    while (str[0] == ',') {
 {
     cgc_size_t tlv11;
     tlv11 = sizeof ( kty_item_t );
    	new = (kty_item_t *) cgc_malloc(tlv11);
 }
	if (new == NULL) {
	    goto fail;
	}
	str++;
 {
     char* tlv10;
      {
          kty_item_t* tlv15;
          tlv15 = new;
          char* tlv14;
           {
               char* tlv17;
                tlv17 = str;
               tlv14 = cgc_eat_ws(tlv17);
           }
          tlv10 = cgc_parse_item(tlv15,tlv14);
      }
    	str = cgc_eat_ws(tlv10);
 }
	if (str == NULL) {
	    goto fail;
	}
 {
     array_t* tlv9;
     tlv9 = item -> item . i_array;
     void* tlv8;
     tlv8 = new;
    	cgc_array_append(tlv9,tlv8);
 }
	new = NULL;
    }
    if (str[0] == ']') {
	return str + 1;
    }
  fail:
    if (new) {
	cgc_free_kty_item(new);
    }
    return NULL;
}

void fix_ingred_kty_16_0_0();
void fix_ingred_kty_16_0();
void fix_ingred_kty_16_1_0();
void fix_ingred_kty_16_1();
void fix_ingred_kty_16_2_6();
void fix_ingred_kty_16_2_7();
void fix_ingred_kty_16_2();
void fix_ingred_kty_16_3_0();
void fix_ingred_kty_16_3();
void fix_ingred_kty_16_5_0();
void fix_ingred_kty_16_5();
void fix_ingred_kty_16_9_0();
void fix_ingred_kty_16_9();
void fix_ingred_kty_16_10_10();
void fix_ingred_kty_16_10();
void fix_ingred_kty_16_17_1();
void fix_ingred_kty_16_17_2();
void fix_ingred_kty_16_17();
void fix_ingred_kty_16_22_1();
void fix_ingred_kty_16_22();
void fix_ingred_kty_16_23_13();
void fix_ingred_kty_16_23();
void fix_ingred_kty_16();
char *cgc_parse_object(kty_item_t * item, char *str)
{
if (fix_ingred_enable){ fix_ingred_kty_16(); };
    char* key;
     key = NULL;
    kty_item_t* new;
    new = NULL;
    kty_item_t* k;
    k = NULL;
    kty_item_t* dup;
    dup = NULL;
    item->type = KTY_OBJECT;
    item->item.i_object = NULL;
    {
        char* tlv4;
         tlv4 = str + 1;
        str = cgc_eat_ws(tlv4);
    }
    if (str[0] == '}') {
	return str + 1;
    }
    {
        cgc_size_t tlv9;
        tlv9 = sizeof ( kty_item_t );
        k = (kty_item_t *) cgc_malloc(tlv9);
    }
    if (k == NULL) {
	goto fail;
    }
    {
        int tlv6;
        tlv6 = 4;
        free_value_fn* tlv5 = cgc_free_kty_item;
        item->item.i_object = cgc_htbl_create(tlv6,tlv5);
    }
    if (item->item.i_object == NULL) {
	goto fail;
    }
    {
        char* tlv7;
         {
             kty_item_t* tlv27;
             tlv27 = k;
             char* tlv26;
              {
                  char* tlv34;
                   tlv34 = str;
                  tlv26 = cgc_eat_ws(tlv34);
              }
             tlv7 = cgc_parse_string(tlv27,tlv26);
         }
        str = cgc_eat_ws(tlv7);
    }
    key = k->item.i_string.s;
    if (str == NULL || str[0] != ':') {
	goto fail;
    }
    str++;
    {
        cgc_size_t tlv10;
        tlv10 = sizeof ( kty_item_t );
        new = (kty_item_t *) cgc_malloc(tlv10);
    }
    if (new == NULL) {
	goto fail;
    }
    {
        char* tlv8;
         {
             kty_item_t* tlv29;
             tlv29 = new;
             char* tlv28;
              {
                  char* tlv35;
                   tlv35 = str;
                  tlv28 = cgc_eat_ws(tlv35);
              }
             tlv8 = cgc_parse_item(tlv29,tlv28);
         }
        str = cgc_eat_ws(tlv8);
    }
    if (str == NULL) {
	goto fail;
    }
    {
        htbl_t* tlv3;
        tlv3 = item -> item . i_object;
        char* tlv2;
         tlv2 = key;
        void* tlv1;
        tlv1 = new;
        cgc_htbl_put(tlv3,tlv2,tlv1);
    }
    if (cgc_strcmp("nyan_says", key) == 0 && new->type == KTY_STRING) {
 {
     cgc_size_t tlv19;
     tlv19 = sizeof ( kty_item_t );
    	dup = (kty_item_t *) cgc_malloc(tlv19);
 }
	if (dup == NULL) {
	    goto fail;
	}
	dup->type = new->type;
 {
     char* tlv16;
      tlv16 = new -> item . i_string . s;
    	dup->item.i_string.s = cgc_strdup(tlv16);
 }
	dup->item.i_string.len = new->item.i_string.len;
 {
     array_t* tlv12;
     tlv12 = g_parser -> nyan_says;
     void* tlv11;
     tlv11 = dup;
    	cgc_array_append(tlv12,tlv11);
 }
	dup = NULL;
    }
    cgc_free_kty_item(k);
    k = NULL;
    new = NULL;
    while (str[0] == ',') {
 {
     cgc_size_t tlv20;
     tlv20 = sizeof ( kty_item_t );
    	k = (kty_item_t *) cgc_malloc(tlv20);
 }
	if (k == NULL) {
	    goto fail;
	}
 {
     char* tlv17;
      {
          kty_item_t* tlv31;
          tlv31 = k;
          char* tlv30;
           {
               char* tlv36;
                tlv36 = str + 1;
               tlv30 = cgc_eat_ws(tlv36);
           }
          tlv17 = cgc_parse_string(tlv31,tlv30);
      }
    	str = cgc_eat_ws(tlv17);
 }
	key = k->item.i_string.s;
	if (str == NULL || str[0] != ':') {
	    goto fail;
	}
	str++;
 {
     cgc_size_t tlv21;
     tlv21 = sizeof ( kty_item_t );
    	new = (kty_item_t *) cgc_malloc(tlv21);
 }
	if (new == NULL) {
	    goto fail;
	}
 {
     char* tlv18;
      {
          kty_item_t* tlv33;
          tlv33 = new;
          char* tlv32;
           {
               char* tlv37;
                tlv37 = str;
               tlv32 = cgc_eat_ws(tlv37);
           }
          tlv18 = cgc_parse_item(tlv33,tlv32);
      }
    	str = cgc_eat_ws(tlv18);
 }
	if (str == NULL) {
	    goto fail;
	}
 {
     htbl_t* tlv15;
     tlv15 = item -> item . i_object;
     char* tlv14;
      tlv14 = key;
     void* tlv13;
     tlv13 = new;
    	cgc_htbl_put(tlv15,tlv14,tlv13);
 }
	if (cgc_strcmp("nyan_says", key) == 0 && new->type == KTY_STRING) {
     {
         cgc_size_t tlv25;
         tlv25 = sizeof ( kty_item_t );
    	    dup = (kty_item_t *) cgc_malloc(tlv25);
     }
	    if (dup == NULL) {
		goto fail;
	    }
	    dup->type = new->type;
     {
         char* tlv24;
          tlv24 = new -> item . i_string . s;
    	    dup->item.i_string.s = cgc_strdup(tlv24);
     }
	    dup->item.i_string.len = new->item.i_string.len;
     {
         array_t* tlv23;
         tlv23 = g_parser -> nyan_says;
         void* tlv22;
         tlv22 = dup;
    	    cgc_array_append(tlv23,tlv22);
     }
	    dup = NULL;
	}
	cgc_free_kty_item(k);
	k = NULL;
	new = NULL;
    }
    if (str[0] == '}') {
	return str + 1;
    }
  fail:
    if (new) {
	cgc_free_kty_item(new);
    }
    if (k) {
	cgc_free_kty_item(k);
    }
    if (dup) {
	cgc_free_kty_item(dup);
    }
    return NULL;
}

void fix_ingred_kty_17_1_0();
void fix_ingred_kty_17_1();
void fix_ingred_kty_17_2_0();
void fix_ingred_kty_17_2_1();
void fix_ingred_kty_17_2();
void fix_ingred_kty_17_3_3();
void fix_ingred_kty_17_3_4();
void fix_ingred_kty_17_3();
void fix_ingred_kty_17_4_1();
void fix_ingred_kty_17_4();
void fix_ingred_kty_17_5_3();
void fix_ingred_kty_17_5();
void fix_ingred_kty_17_7_2();
void fix_ingred_kty_17_7();
void fix_ingred_kty_17_9_2();
void fix_ingred_kty_17_9();
void fix_ingred_kty_17();
char *cgc_parse_item(kty_item_t * item, char *str)
{
if (fix_ingred_enable){ fix_ingred_kty_17(); };
    char c;
    if (item && str) {
	c = str[0];
 int tlv1;
 {
     char* tlv7;
      tlv7 = str;
     char tlv6[] = "true";
     int tlv5;
     tlv5 = 4;
     tlv1 = cgc_strncmp(tlv7,tlv6,tlv5);
 }
	if (tlv1 == 0) {
	    item->type = KTY_BOOLEAN;
	    item->item.i_bool = 1;
	    return str + 4;
	}
 int tlv2;
 {
     char* tlv10;
      tlv10 = str;
     char tlv9[] = "false";
     int tlv8;
     tlv8 = 5;
     tlv2 = cgc_strncmp(tlv10,tlv9,tlv8);
 }
	if (tlv2 == 0) {
	    item->type = KTY_BOOLEAN;
	    item->item.i_bool = 0;
	    return str + 5;
	}
 int tlv3;
 {
     char* tlv13;
      tlv13 = str;
     char tlv12[] = "null";
     int tlv11;
     tlv11 = 4;
     tlv3 = cgc_strncmp(tlv13,tlv12,tlv11);
 }
	if (tlv3 == 0) {
	    item->type = KTY_NULL;
	    return str + 4;
	}
 int tlv4;
 {
     char* tlv16;
      tlv16 = str;
     char tlv15[] = "=^.^=";
     int tlv14;
     tlv14 = 5;
     tlv4 = cgc_strncmp(tlv16,tlv15,tlv14);
 }
	if (tlv4 == 0) {
	    item->type = KTY_CAT;
	    return str + 5;
	}
	switch (c) {
	case '[':
	    {
		return cgc_parse_array(item, str);
	    }
	case '{':
	    {
		return cgc_parse_object(item, str);
	    }
	case '-':{
	case '0':{
	case '1':  {
	case '2':	{
	case '3':	    {
	case '4':
				{
	case '5':		    {
	case '6':			{
	case '7':			    {
	case '8':				{
	case '9':				    {
	case '+':
							{
							    return cgc_parse_number(item, str);
							}
						    }
						}
					    }
					}
				    }
				}
			    }
			}
		    }
		}
	    }
	case '\"':
	    {
		return cgc_parse_string(item, str);
	    }
	}
    }
    return NULL;
}

void fix_ingred_kty_18_0_0();
void fix_ingred_kty_18_0_2();
void fix_ingred_kty_18_0();
void fix_ingred_kty_18_1_0();
void fix_ingred_kty_18_1_1();
void fix_ingred_kty_18_1();
void fix_ingred_kty_18_5_0();
void fix_ingred_kty_18_5();
void fix_ingred_kty_18_8_0();
void fix_ingred_kty_18_8();
void fix_ingred_kty_18_9_3();
void fix_ingred_kty_18_9_4();
void fix_ingred_kty_18_9();
void fix_ingred_kty_18();
kty_item_t *cgc_kty_loads(char *str)
{
if (fix_ingred_enable){ fix_ingred_kty_18(); };
    char *c;
    char string[MAX_KTY_STRING];
    int i;
    i = 0;
    int init;
    init = 0;
    int state;
    state = - 1;
    kty_item_t *root;
    {
        cgc_size_t tlv6;
        tlv6 = 1;
        cgc_size_t tlv5;
        tlv5 = sizeof ( kty_item_t );
        root = (kty_item_t *) cgc_calloc(tlv6,tlv5);
    }
    if (root == NULL) {
	goto fail;
    }
    if (g_parser->nyan_says) {
 {
     array_t* tlv7;
     tlv7 = g_parser -> nyan_says;
    	cgc_array_destroy(tlv7);
 }
    }
    {
        int tlv2;
        tlv2 = 16;
        free_element_fn* tlv1 = cgc_free_kty_item;
        g_parser->nyan_says = cgc_array_create(tlv2,tlv1);
    }
    if (g_parser->nyan_says == NULL) {
	goto fail;
    }
    {
        kty_item_t* tlv4;
        tlv4 = root;
        char* tlv3;
         {
             char* tlv8;
              tlv8 = str;
             tlv3 = cgc_eat_ws(tlv8);
         }
        c = cgc_parse_item(tlv4,tlv3);
    }
    if (c == NULL) {
	goto fail;
    }
    return root;
  fail:
    if (root) {
	cgc_free_kty_item(root);
    }
    return NULL;
}

void fix_ingred_kty_19();
int cgc_kty_init(kty_parser_t * parser)
{
if (fix_ingred_enable){ fix_ingred_kty_19(); };
    if (parser) {
	parser->cats = 0;
	parser->nyan_says = NULL;
	parser->dumps = cgc_kty_dumps;
	parser->loads = cgc_kty_loads;
	g_parser = parser;
	return 0;
    }
    return -1;
}

void fix_ingred_kty_20();
void cgc_free_kty_item(void *e)
{
if (fix_ingred_enable){ fix_ingred_kty_20(); };
    if (e) {
 kty_item_t* item;
 item = ( kty_item_t * ) e;
	switch (item->type) {
	case KTY_STRING:
	    {
		if (item->item.i_string.s) {
      {
          void* tlv3;
          tlv3 = item -> item . i_string . s;
    		    cgc_free(tlv3);
      }
		}
	    }
	    break;
	case KTY_ARRAY:
	    {
  {
      array_t* tlv1;
      tlv1 = item -> item . i_array;
    		cgc_array_destroy(tlv1);
  }
	    }
	    break;
	case KTY_OBJECT:
	    {
  {
      htbl_t* tlv2;
      tlv2 = item -> item . i_object;
    		cgc_htbl_destroy(tlv2);
  }
	    }
	    break;
	default:
	    {
		break;
	    }
	}
	cgc_free(item);
    }
}

void fix_ingred_kty_0(){
}
void fix_ingred_kty_1_0_0(){
    {int i; i = (int)(0); }
    {char c [ 2 ]; c [ ( 2 )-1 ] = (char)(0); }
    {char tmp [ 2 ]; tmp [ ( 2 )-1 ] = (char)(0); }
    {char* hex_nums ; hex_nums  = (char*)(0); }
    {int tlv2; tlv2 = (int)(0); }
    {int tlv4; tlv4 = (int)(0); }
    {int tlv6; tlv6 = (int)(0); }
    {int tlv8; tlv8 = (int)(0); }
    {int tlv10; tlv10 = (int)(0); }
    {int tlv12; tlv12 = (int)(0); }
    {int tlv14; tlv14 = (int)(0); }
    {int tlv16; tlv16 = (int)(0); }
}
void fix_ingred_kty_1_0(){
fix_ingred_kty_1_0_0();
}
void fix_ingred_kty_1_4_0(){
    {int i; i = (int)(STDOUT); }
    {char c [ 2 ]; c [ ( 2 )-1 ] = (char)(STDOUT); }
    {char tmp [ 2 ]; tmp [ ( 2 )-1 ] = (char)(STDOUT); }
    {char* hex_nums ; hex_nums  = (char*)(STDOUT); }
    {int tlv2; tlv2 = (int)(STDOUT); }
    {int tlv4; tlv4 = (int)(STDOUT); }
    {int tlv6; tlv6 = (int)(STDOUT); }
    {int tlv8; tlv8 = (int)(STDOUT); }
    {int tlv10; tlv10 = (int)(STDOUT); }
    {int tlv12; tlv12 = (int)(STDOUT); }
    {int tlv14; tlv14 = (int)(STDOUT); }
    {int tlv16; tlv16 = (int)(STDOUT); }
}
void fix_ingred_kty_1_4(){
fix_ingred_kty_1_4_0();
}
void fix_ingred_kty_1(){
fix_ingred_kty_1_0();
fix_ingred_kty_1_4();
}
void fix_ingred_kty_2_1_1(){
int i;
    bzero(&i,sizeof(int));
int depth;
    bzero(&depth,sizeof(int));
    {int tlv2; tlv2 = (int)(i); }
}
void fix_ingred_kty_2_1_2(){
int i;
    bzero(&i,sizeof(int));
int depth;
    bzero(&depth,sizeof(int));
    {int i; i = (int)(depth * 2); }
    {int tlv2; tlv2 = (int)(depth * 2); }
}
void fix_ingred_kty_2_1(){
fix_ingred_kty_2_1_1();
fix_ingred_kty_2_1_2();
}
void fix_ingred_kty_2(){
fix_ingred_kty_2_1();
}
void fix_ingred_kty_3(){
}
void fix_ingred_kty_4_0_1(){
double val;
    bzero(&val,sizeof(double));
    {int tmp; tmp = (int)(( int ) val); }
    {int tlv2; tlv2 = (int)(( int ) val); }
}
void fix_ingred_kty_4_0(){
fix_ingred_kty_4_0_1();
}
void fix_ingred_kty_4_1_3(){
int tmp;
    bzero(&tmp,sizeof(int));
double val;
    bzero(&val,sizeof(double));
    {double val; val = (double)(0.0); }
}
void fix_ingred_kty_4_1_4(){
int tmp;
    bzero(&tmp,sizeof(int));
double val;
    bzero(&val,sizeof(double));
    {int tlv2; tlv2 = (int)(tmp); }
}
void fix_ingred_kty_4_1_5(){
int tmp;
    bzero(&tmp,sizeof(int));
double val;
    bzero(&val,sizeof(double));
    {int tmp; tmp = (int)(0); }
}
void fix_ingred_kty_4_1(){
fix_ingred_kty_4_1_3();
fix_ingred_kty_4_1_4();
fix_ingred_kty_4_1_5();
}
void fix_ingred_kty_4_2_0(){
    {int tmp; tmp = (int)(STDOUT); }
}
void fix_ingred_kty_4_2(){
fix_ingred_kty_4_2_0();
}
void fix_ingred_kty_4_3_0(){
int tmp;
    bzero(&tmp,sizeof(int));
    {int tlv2; tlv2 = (int)(- tmp); }
}
void fix_ingred_kty_4_3(){
fix_ingred_kty_4_3_0();
}
void fix_ingred_kty_4(){
fix_ingred_kty_4_0();
fix_ingred_kty_4_1();
fix_ingred_kty_4_2();
fix_ingred_kty_4_3();
}
void fix_ingred_kty_5_1_0(){
    {char * tlv4; tlv4 = (char *)(STDOUT); }
    {int tlv3; tlv3 = (int)(STDOUT); }
}
void fix_ingred_kty_5_1(){
fix_ingred_kty_5_1_0();
}
void fix_ingred_kty_5(){
fix_ingred_kty_5_1();
}
void fix_ingred_kty_6_0_0(){
    {int count; count = (int)(0); }
    {int tlv9; tlv9 = (int)(0); }
    {int tlv11; tlv11 = (int)(0); }
    {char * tlv13; tlv13 = (char *)(0); }
    {int tlv15; tlv15 = (int)(0); }
    {int tlv19; tlv19 = (int)(0); }
}
void fix_ingred_kty_6_0(){
fix_ingred_kty_6_0_0();
}
void fix_ingred_kty_6_1_0(){
    {int count; count = (int)(STDOUT); }
    {int tlv9; tlv9 = (int)(STDOUT); }
    {int tlv11; tlv11 = (int)(STDOUT); }
    {char * tlv13; tlv13 = (char *)(STDOUT); }
    {int tlv15; tlv15 = (int)(STDOUT); }
    {int tlv19; tlv19 = (int)(STDOUT); }
}
void fix_ingred_kty_6_1(){
fix_ingred_kty_6_1_0();
}
void fix_ingred_kty_6_5_6(){
int count;
    bzero(&count,sizeof(int));
    {int tlv2; tlv2 = (int)(count); }
    {int tlv4; tlv4 = (int)(count); }
    {int tlv6; tlv6 = (int)(count); }
    {int tlv8; tlv8 = (int)(count); }
    {int tlv9; tlv9 = (int)(count); }
    {int tlv11; tlv11 = (int)(count); }
    {char * tlv13; tlv13 = (char *)(count); }
    {int tlv12; tlv12 = (int)(count); }
    {int tlv15; tlv15 = (int)(count); }
    {int tlv16; tlv16 = (int)(count); }
    {int tlv19; tlv19 = (int)(count); }
}
void fix_ingred_kty_6_5(){
fix_ingred_kty_6_5_6();
}
void fix_ingred_kty_6_7_0(){
int depth;
    bzero(&depth,sizeof(int));
    {int count; count = (int)(depth + 1); }
    {int tlv2; tlv2 = (int)(depth + 1); }
    {int tlv4; tlv4 = (int)(depth + 1); }
    {int tlv6; tlv6 = (int)(depth + 1); }
    {int tlv8; tlv8 = (int)(depth + 1); }
    {int tlv9; tlv9 = (int)(depth + 1); }
    {int tlv11; tlv11 = (int)(depth + 1); }
    {char * tlv13; tlv13 = (char *)(depth + 1); }
    {int tlv12; tlv12 = (int)(depth + 1); }
    {int tlv15; tlv15 = (int)(depth + 1); }
    {int tlv16; tlv16 = (int)(depth + 1); }
    {int tlv19; tlv19 = (int)(depth + 1); }
}
void fix_ingred_kty_6_7(){
fix_ingred_kty_6_7_0();
}
void fix_ingred_kty_6_9_0(){
entry_t entry_ref;
    bzero(&entry_ref,1*sizeof(entry_t));
entry_t * entry = &entry_ref;
    {int count; count = (int)(entry -> key); }
    {int tlv2; tlv2 = (int)(entry -> key); }
    {int tlv4; tlv4 = (int)(entry -> key); }
    {int tlv6; tlv6 = (int)(entry -> key); }
    {int tlv8; tlv8 = (int)(entry -> key); }
    {int tlv9; tlv9 = (int)(entry -> key); }
    {int tlv11; tlv11 = (int)(entry -> key); }
    {char * tlv13; tlv13 = (char *)(entry -> key); }
    {int tlv12; tlv12 = (int)(entry -> key); }
    {int tlv15; tlv15 = (int)(entry -> key); }
    {int tlv16; tlv16 = (int)(entry -> key); }
    {int tlv19; tlv19 = (int)(entry -> key); }
}
void fix_ingred_kty_6_9(){
fix_ingred_kty_6_9_0();
}
void fix_ingred_kty_6_10_0(){
char tlv20_ref;
    bzero(&tlv20_ref,1*sizeof(char));
const char * tlv20 = &tlv20_ref;
    {int count; count = (int)(cgc_strlen ( tlv20 )); }
    {int tlv2; tlv2 = (int)(cgc_strlen ( tlv20 )); }
    {int tlv4; tlv4 = (int)(cgc_strlen ( tlv20 )); }
    {int tlv6; tlv6 = (int)(cgc_strlen ( tlv20 )); }
    {int tlv8; tlv8 = (int)(cgc_strlen ( tlv20 )); }
    {int tlv9; tlv9 = (int)(cgc_strlen ( tlv20 )); }
    {int tlv11; tlv11 = (int)(cgc_strlen ( tlv20 )); }
    {char * tlv13; tlv13 = (char *)(cgc_strlen ( tlv20 )); }
    {int tlv12; tlv12 = (int)(cgc_strlen ( tlv20 )); }
    {int tlv15; tlv15 = (int)(cgc_strlen ( tlv20 )); }
    {int tlv16; tlv16 = (int)(cgc_strlen ( tlv20 )); }
    {int tlv19; tlv19 = (int)(cgc_strlen ( tlv20 )); }
}
void fix_ingred_kty_6_10(){
fix_ingred_kty_6_10_0();
}
void fix_ingred_kty_6(){
fix_ingred_kty_6_0();
fix_ingred_kty_6_1();
fix_ingred_kty_6_5();
fix_ingred_kty_6_7();
fix_ingred_kty_6_9();
fix_ingred_kty_6_10();
}
void fix_ingred_kty_7_0_0(){
    {int tlv1; tlv1 = (int)(0); }
    {int tlv3; tlv3 = (int)(0); }
    {int tlv5; tlv5 = (int)(0); }
    {int tlv13; tlv13 = (int)(0); }
    {int tlv17; tlv17 = (int)(0); }
}
void fix_ingred_kty_7_0(){
fix_ingred_kty_7_0_0();
}
void fix_ingred_kty_7_1_0(){
    {int tlv1; tlv1 = (int)(STDOUT); }
    {int tlv5; tlv5 = (int)(STDOUT); }
    {int tlv13; tlv13 = (int)(STDOUT); }
    {int tlv17; tlv17 = (int)(STDOUT); }
}
void fix_ingred_kty_7_1(){
fix_ingred_kty_7_1_0();
}
void fix_ingred_kty_7_3_1(){
int tlv1;
    bzero(&tlv1,sizeof(int));
    {int i; i = (int)(tlv1); }
    {int count; count = (int)(tlv1); }
    {int tlv3; tlv3 = (int)(tlv1); }
    {int tlv5; tlv5 = (int)(tlv1); }
    {int tlv8; tlv8 = (int)(tlv1); }
    {int tlv9; tlv9 = (int)(tlv1); }
    {int tlv14; tlv14 = (int)(tlv1); }
    {int tlv10; tlv10 = (int)(tlv1); }
    {int tlv13; tlv13 = (int)(tlv1); }
    {int tlv17; tlv17 = (int)(tlv1); }
}
void fix_ingred_kty_7_3(){
fix_ingred_kty_7_3_1();
}
void fix_ingred_kty_7_5_2(){
int i;
    bzero(&i,sizeof(int));
    {int count; count = (int)(i); }
    {int tlv1; tlv1 = (int)(i); }
    {int tlv3; tlv3 = (int)(i); }
    {int tlv5; tlv5 = (int)(i); }
    {int tlv8; tlv8 = (int)(i); }
    {int tlv9; tlv9 = (int)(i); }
    {int tlv14; tlv14 = (int)(i); }
    {int tlv10; tlv10 = (int)(i); }
    {int tlv13; tlv13 = (int)(i); }
    {int tlv17; tlv17 = (int)(i); }
}
void fix_ingred_kty_7_5(){
fix_ingred_kty_7_5_2();
}
void fix_ingred_kty_7_6_3(){
int count;
    bzero(&count,sizeof(int));
    {int i; i = (int)(count); }
    {int tlv1; tlv1 = (int)(count); }
    {int tlv3; tlv3 = (int)(count); }
    {int tlv5; tlv5 = (int)(count); }
    {int tlv14; tlv14 = (int)(count); }
    {int tlv10; tlv10 = (int)(count); }
    {int tlv13; tlv13 = (int)(count); }
    {int tlv17; tlv17 = (int)(count); }
}
void fix_ingred_kty_7_6(){
fix_ingred_kty_7_6_3();
}
void fix_ingred_kty_7_8_0(){
int depth;
    bzero(&depth,sizeof(int));
    {int i; i = (int)(depth + 1); }
    {int tlv1; tlv1 = (int)(depth + 1); }
    {int tlv3; tlv3 = (int)(depth + 1); }
    {int tlv5; tlv5 = (int)(depth + 1); }
    {int tlv14; tlv14 = (int)(depth + 1); }
    {int tlv10; tlv10 = (int)(depth + 1); }
    {int tlv13; tlv13 = (int)(depth + 1); }
    {int tlv17; tlv17 = (int)(depth + 1); }
}
void fix_ingred_kty_7_8(){
fix_ingred_kty_7_8_0();
}
void fix_ingred_kty_7(){
fix_ingred_kty_7_0();
fix_ingred_kty_7_1();
fix_ingred_kty_7_3();
fix_ingred_kty_7_5();
fix_ingred_kty_7_6();
fix_ingred_kty_7_8();
}
void fix_ingred_kty_8(){
}
void fix_ingred_kty_9(){
}
void fix_ingred_kty_10(){
}
void fix_ingred_kty_11_6_1(){
int depth;
    bzero(&depth,sizeof(int));
    {int tlv1; tlv1 = (int)(depth); }
    {int tlv3; tlv3 = (int)(depth); }
}
void fix_ingred_kty_11_6(){
fix_ingred_kty_11_6_1();
}
void fix_ingred_kty_11(){
fix_ingred_kty_11_6();
}
void fix_ingred_kty_12_0_0(){
    {int depth; depth = (int)(0); }
}
void fix_ingred_kty_12_0(){
fix_ingred_kty_12_0_0();
}
void fix_ingred_kty_12(){
fix_ingred_kty_12_0();
}
void fix_ingred_kty_13_1_0(){
    {char decimal [ 3 ]; decimal [ ( 3 )-1 ] = (char)(' '); }
    {char * c1; c1 = (char *)(' '); }
    {char * c2; c2 = (char *)(' '); }
    {int i; i = (int)(' '); }
    {int tlv1; tlv1 = (int)(' '); }
    {int tlv3; tlv3 = (int)(' '); }
    {int tlv5; tlv5 = (int)(' '); }
    {int tlv7; tlv7 = (int)(' '); }
    {int tlv9; tlv9 = (int)(' '); }
    {int tlv13; tlv13 = (int)(' '); }
}
void fix_ingred_kty_13_1(){
fix_ingred_kty_13_1_0();
}
void fix_ingred_kty_13_2_0(){
char c1_ref;
    bzero(&c1_ref,1*sizeof(char));
char * c1 = &c1_ref;
    {char decimal [ 3 ]; decimal [ ( 3 )-1 ] = (char)(c1); }
    {char * c2; c2 = (char *)(c1); }
    {int i; i = (int)(c1); }
    {int tlv1; tlv1 = (int)(c1); }
    {int tlv3; tlv3 = (int)(c1); }
    {int tlv5; tlv5 = (int)(c1); }
    {int tlv7; tlv7 = (int)(c1); }
    {int tlv9; tlv9 = (int)(c1); }
    {int tlv13; tlv13 = (int)(c1); }
}
void fix_ingred_kty_13_2_1(){
char c1_ref;
    bzero(&c1_ref,1*sizeof(char));
char * c1 = &c1_ref;
    {char decimal [ 3 ]; decimal [ ( 3 )-1 ] = (char)(NULL); }
    {char * c1; c1 = (char *)(NULL); }
    {char * c2; c2 = (char *)(NULL); }
    {int i; i = (int)(NULL); }
    {int tlv1; tlv1 = (int)(NULL); }
    {int tlv3; tlv3 = (int)(NULL); }
    {int tlv5; tlv5 = (int)(NULL); }
    {int tlv7; tlv7 = (int)(NULL); }
    {int tlv9; tlv9 = (int)(NULL); }
    {int tlv13; tlv13 = (int)(NULL); }
}
void fix_ingred_kty_13_2(){
fix_ingred_kty_13_2_0();
fix_ingred_kty_13_2_1();
}
void fix_ingred_kty_13_3_0(){
    {char decimal [ 3 ]; decimal [ ( 3 )-1 ] = (char)(','); }
    {char * c1; c1 = (char *)(','); }
    {char * c2; c2 = (char *)(','); }
    {int i; i = (int)(','); }
    {int tlv1; tlv1 = (int)(','); }
    {int tlv3; tlv3 = (int)(','); }
    {int tlv5; tlv5 = (int)(','); }
    {int tlv7; tlv7 = (int)(','); }
    {int tlv9; tlv9 = (int)(','); }
    {int tlv13; tlv13 = (int)(','); }
}
void fix_ingred_kty_13_3(){
fix_ingred_kty_13_3_0();
}
void fix_ingred_kty_13_5_0(){
    {char decimal [ 3 ]; decimal [ ( 3 )-1 ] = (char)(']'); }
    {char * c1; c1 = (char *)(']'); }
    {char * c2; c2 = (char *)(']'); }
    {int i; i = (int)(']'); }
    {int tlv1; tlv1 = (int)(']'); }
    {int tlv3; tlv3 = (int)(']'); }
    {int tlv5; tlv5 = (int)(']'); }
    {int tlv7; tlv7 = (int)(']'); }
    {int tlv9; tlv9 = (int)(']'); }
    {int tlv13; tlv13 = (int)(']'); }
}
void fix_ingred_kty_13_5(){
fix_ingred_kty_13_5_0();
}
void fix_ingred_kty_13_7_0(){
    {char decimal [ 3 ]; decimal [ ( 3 )-1 ] = (char)('}'); }
    {char * c1; c1 = (char *)('}'); }
    {char * c2; c2 = (char *)('}'); }
    {int i; i = (int)('}'); }
    {int tlv1; tlv1 = (int)('}'); }
    {int tlv3; tlv3 = (int)('}'); }
    {int tlv5; tlv5 = (int)('}'); }
    {int tlv7; tlv7 = (int)('}'); }
    {int tlv9; tlv9 = (int)('}'); }
    {int tlv13; tlv13 = (int)('}'); }
}
void fix_ingred_kty_13_7(){
fix_ingred_kty_13_7_0();
}
void fix_ingred_kty_13_8_0(){
    {char decimal [ 3 ]; decimal [ ( 3 )-1 ] = (char)('.'); }
    {char * c1; c1 = (char *)('.'); }
    {char * c2; c2 = (char *)('.'); }
    {int i; i = (int)('.'); }
    {int tlv1; tlv1 = (int)('.'); }
    {int tlv3; tlv3 = (int)('.'); }
    {int tlv5; tlv5 = (int)('.'); }
    {int tlv7; tlv7 = (int)('.'); }
    {int tlv9; tlv9 = (int)('.'); }
    {int tlv13; tlv13 = (int)('.'); }
}
void fix_ingred_kty_13_8(){
fix_ingred_kty_13_8_0();
}
void fix_ingred_kty_13_9_2(){
char c2_ref;
    bzero(&c2_ref,1*sizeof(char));
char * c2 = &c2_ref;
    {char decimal [ 3 ]; decimal [ ( 3 )-1 ] = (char)(c2); }
    {char * c1; c1 = (char *)(c2); }
    {int i; i = (int)(c2); }
    {int tlv1; tlv1 = (int)(c2); }
    {int tlv3; tlv3 = (int)(c2); }
    {int tlv5; tlv5 = (int)(c2); }
    {int tlv7; tlv7 = (int)(c2); }
    {int tlv9; tlv9 = (int)(c2); }
    {int tlv13; tlv13 = (int)(c2); }
}
void fix_ingred_kty_13_9(){
fix_ingred_kty_13_9_2();
}
void fix_ingred_kty_13_12_1(){
    {char decimal [ 3 ]; decimal [ ( 3 )-1 ] = (char)(10); }
    {char * c1; c1 = (char *)(10); }
    {char * c2; c2 = (char *)(10); }
    {int i; i = (int)(10); }
    {int tlv1; tlv1 = (int)(10); }
    {int tlv3; tlv3 = (int)(10); }
    {int tlv5; tlv5 = (int)(10); }
    {int tlv7; tlv7 = (int)(10); }
    {int tlv9; tlv9 = (int)(10); }
    {int tlv13; tlv13 = (int)(10); }
}
void fix_ingred_kty_13_12(){
fix_ingred_kty_13_12_1();
}
void fix_ingred_kty_13(){
fix_ingred_kty_13_1();
fix_ingred_kty_13_2();
fix_ingred_kty_13_3();
fix_ingred_kty_13_5();
fix_ingred_kty_13_7();
fix_ingred_kty_13_8();
fix_ingred_kty_13_9();
fix_ingred_kty_13_12();
}
void fix_ingred_kty_14_0_0(){
char str_ref;
    bzero(&str_ref,1*sizeof(char));
char * str = &str_ref;
    {int cgc_read; cgc_read = (int)(0); }
    {int len; len = (int)(0); }
    {char * c; c = (char *)(0); }
    {cgc_size_t tlv1; tlv1 = (cgc_size_t)(0); }
}
void fix_ingred_kty_14_0_2(){
char str_ref;
    bzero(&str_ref,1*sizeof(char));
char * str = &str_ref;
    {int cgc_read; cgc_read = (int)(str + 1); }
    {int len; len = (int)(str + 1); }
    {char * c; c = (char *)(str + 1); }
    {cgc_size_t tlv1; tlv1 = (cgc_size_t)(str + 1); }
}
void fix_ingred_kty_14_0_6(){
char str_ref;
    bzero(&str_ref,1*sizeof(char));
char * str = &str_ref;
    {int cgc_read; cgc_read = (int)(2); }
    {int len; len = (int)(2); }
    {char * c; c = (char *)(2); }
    {cgc_size_t tlv1; tlv1 = (cgc_size_t)(2); }
}
void fix_ingred_kty_14_0(){
fix_ingred_kty_14_0_0();
fix_ingred_kty_14_0_2();
fix_ingred_kty_14_0_6();
}
void fix_ingred_kty_14_1_5(){
char str_ref;
    bzero(&str_ref,1*sizeof(char));
char * str = &str_ref;
    {int cgc_read; cgc_read = (int)(str [ 0 ]); }
    {int len; len = (int)(str [ 0 ]); }
    {char * c; c = (char *)(str [ 0 ]); }
    {cgc_size_t tlv1; tlv1 = (cgc_size_t)(str [ 0 ]); }
}
void fix_ingred_kty_14_1_6(){
char str_ref;
    bzero(&str_ref,1*sizeof(char));
char * str = &str_ref;
    {int cgc_read; cgc_read = (int)('\"'); }
    {int len; len = (int)('\"'); }
    {char * c; c = (char *)('\"'); }
    {cgc_size_t tlv1; tlv1 = (cgc_size_t)('\"'); }
}
void fix_ingred_kty_14_1(){
fix_ingred_kty_14_1_5();
fix_ingred_kty_14_1_6();
}
void fix_ingred_kty_14_2_5(){
char c_ref;
    bzero(&c_ref,1*sizeof(char));
char * c = &c_ref;
    {int cgc_read; cgc_read = (int)(c [ 0 ]); }
    {int len; len = (int)(c [ 0 ]); }
    {cgc_size_t tlv1; tlv1 = (cgc_size_t)(c [ 0 ]); }
}
void fix_ingred_kty_14_2(){
fix_ingred_kty_14_2_5();
}
void fix_ingred_kty_14_3_8(){
    {int cgc_read; cgc_read = (int)('\\'); }
    {int len; len = (int)('\\'); }
    {char * c; c = (char *)('\\'); }
    {cgc_size_t tlv1; tlv1 = (cgc_size_t)('\\'); }
}
void fix_ingred_kty_14_3(){
fix_ingred_kty_14_3_8();
}
void fix_ingred_kty_14_4_5(){
int len;
    bzero(&len,sizeof(int));
    {int cgc_read; cgc_read = (int)(len); }
    {char * c; c = (char *)(len); }
    {cgc_size_t tlv1; tlv1 = (cgc_size_t)(len); }
}
void fix_ingred_kty_14_4_6(){
int len;
    bzero(&len,sizeof(int));
    {int cgc_read; cgc_read = (int)(MAX_KTY_STRING); }
    {int len; len = (int)(MAX_KTY_STRING); }
    {char * c; c = (char *)(MAX_KTY_STRING); }
    {cgc_size_t tlv1; tlv1 = (cgc_size_t)(MAX_KTY_STRING); }
}
void fix_ingred_kty_14_4(){
fix_ingred_kty_14_4_5();
fix_ingred_kty_14_4_6();
}
void fix_ingred_kty_14_5_0(){
int len;
    bzero(&len,sizeof(int));
    {int cgc_read; cgc_read = (int)(len + 1); }
    {char * c; c = (char *)(len + 1); }
    {cgc_size_t tlv1; tlv1 = (cgc_size_t)(len + 1); }
}
void fix_ingred_kty_14_5(){
fix_ingred_kty_14_5_0();
}
void fix_ingred_kty_14(){
fix_ingred_kty_14_0();
fix_ingred_kty_14_1();
fix_ingred_kty_14_2();
fix_ingred_kty_14_3();
fix_ingred_kty_14_4();
fix_ingred_kty_14_5();
}
void fix_ingred_kty_15_1_0(){
char str_ref;
    bzero(&str_ref,1*sizeof(char));
char * str = &str_ref;
    {char * tlv3; tlv3 = (char *)(str + 1); }
    {cgc_size_t tlv7; tlv7 = (cgc_size_t)(str + 1); }
    {int tlv5; tlv5 = (int)(str + 1); }
    {char * tlv6; tlv6 = (char *)(str + 1); }
    {void * tlv1; tlv1 = (void *)(str + 1); }
    {char * tlv12; tlv12 = (char *)(str + 1); }
    {cgc_size_t tlv11; tlv11 = (cgc_size_t)(str + 1); }
    {char * tlv10; tlv10 = (char *)(str + 1); }
    {void * tlv8; tlv8 = (void *)(str + 1); }
    {char * tlv16; tlv16 = (char *)(str + 1); }
    {char * tlv14; tlv14 = (char *)(str + 1); }
    {char * tlv17; tlv17 = (char *)(str + 1); }
}
void fix_ingred_kty_15_1(){
fix_ingred_kty_15_1_0();
}
void fix_ingred_kty_15_2_2(){
char str_ref;
    bzero(&str_ref,1*sizeof(char));
char * str = &str_ref;
    {char * tlv3; tlv3 = (char *)(str [ 0 ]); }
    {cgc_size_t tlv7; tlv7 = (cgc_size_t)(str [ 0 ]); }
    {int tlv5; tlv5 = (int)(str [ 0 ]); }
    {char * tlv6; tlv6 = (char *)(str [ 0 ]); }
    {void * tlv1; tlv1 = (void *)(str [ 0 ]); }
    {char * tlv12; tlv12 = (char *)(str [ 0 ]); }
    {cgc_size_t tlv11; tlv11 = (cgc_size_t)(str [ 0 ]); }
    {char * tlv10; tlv10 = (char *)(str [ 0 ]); }
    {void * tlv8; tlv8 = (void *)(str [ 0 ]); }
    {char * tlv16; tlv16 = (char *)(str [ 0 ]); }
    {char * tlv14; tlv14 = (char *)(str [ 0 ]); }
    {char * tlv17; tlv17 = (char *)(str [ 0 ]); }
}
void fix_ingred_kty_15_2_3(){
char str_ref;
    bzero(&str_ref,1*sizeof(char));
char * str = &str_ref;
    {char * tlv3; tlv3 = (char *)(']'); }
    {cgc_size_t tlv7; tlv7 = (cgc_size_t)(']'); }
    {int tlv5; tlv5 = (int)(']'); }
    {char * tlv6; tlv6 = (char *)(']'); }
    {void * tlv1; tlv1 = (void *)(']'); }
    {char * tlv12; tlv12 = (char *)(']'); }
    {cgc_size_t tlv11; tlv11 = (cgc_size_t)(']'); }
    {char * tlv10; tlv10 = (char *)(']'); }
    {void * tlv8; tlv8 = (void *)(']'); }
    {char * tlv16; tlv16 = (char *)(']'); }
    {char * tlv14; tlv14 = (char *)(']'); }
    {char * tlv17; tlv17 = (char *)(']'); }
}
void fix_ingred_kty_15_2(){
fix_ingred_kty_15_2_2();
fix_ingred_kty_15_2_3();
}
void fix_ingred_kty_15_3_0(){
    {char * tlv3; tlv3 = (char *)(sizeof ( kty_item_t )); }
    {cgc_size_t tlv7; tlv7 = (cgc_size_t)(sizeof ( kty_item_t )); }
    {int tlv5; tlv5 = (int)(sizeof ( kty_item_t )); }
    {char * tlv6; tlv6 = (char *)(sizeof ( kty_item_t )); }
    {void * tlv1; tlv1 = (void *)(sizeof ( kty_item_t )); }
    {char * tlv12; tlv12 = (char *)(sizeof ( kty_item_t )); }
    {cgc_size_t tlv11; tlv11 = (cgc_size_t)(sizeof ( kty_item_t )); }
    {char * tlv10; tlv10 = (char *)(sizeof ( kty_item_t )); }
    {void * tlv8; tlv8 = (void *)(sizeof ( kty_item_t )); }
    {char * tlv16; tlv16 = (char *)(sizeof ( kty_item_t )); }
    {char * tlv14; tlv14 = (char *)(sizeof ( kty_item_t )); }
    {char * tlv17; tlv17 = (char *)(sizeof ( kty_item_t )); }
}
void fix_ingred_kty_15_3(){
fix_ingred_kty_15_3_0();
}
void fix_ingred_kty_15_5_0(){
    {char * tlv3; tlv3 = (char *)(4); }
    {cgc_size_t tlv7; tlv7 = (cgc_size_t)(4); }
    {int tlv5; tlv5 = (int)(4); }
    {char * tlv6; tlv6 = (char *)(4); }
    {void * tlv1; tlv1 = (void *)(4); }
    {char * tlv12; tlv12 = (char *)(4); }
    {cgc_size_t tlv11; tlv11 = (cgc_size_t)(4); }
    {char * tlv10; tlv10 = (char *)(4); }
    {void * tlv8; tlv8 = (void *)(4); }
    {char * tlv16; tlv16 = (char *)(4); }
    {char * tlv14; tlv14 = (char *)(4); }
    {char * tlv17; tlv17 = (char *)(4); }
}
void fix_ingred_kty_15_5(){
fix_ingred_kty_15_5_0();
}
void fix_ingred_kty_15_9_0(){
char str_ref;
    bzero(&str_ref,1*sizeof(char));
char * str = &str_ref;
    {char * tlv3; tlv3 = (char *)(str); }
    {cgc_size_t tlv7; tlv7 = (cgc_size_t)(str); }
    {int tlv5; tlv5 = (int)(str); }
    {char * tlv6; tlv6 = (char *)(str); }
    {void * tlv1; tlv1 = (void *)(str); }
    {char * tlv12; tlv12 = (char *)(str); }
    {cgc_size_t tlv11; tlv11 = (cgc_size_t)(str); }
    {char * tlv10; tlv10 = (char *)(str); }
    {void * tlv8; tlv8 = (void *)(str); }
    {char * tlv16; tlv16 = (char *)(str); }
    {char * tlv14; tlv14 = (char *)(str); }
    {char * tlv17; tlv17 = (char *)(str); }
}
void fix_ingred_kty_15_9(){
fix_ingred_kty_15_9_0();
}
void fix_ingred_kty_15_10_3(){
    {char * tlv3; tlv3 = (char *)(NULL); }
    {cgc_size_t tlv7; tlv7 = (cgc_size_t)(NULL); }
    {char * tlv6; tlv6 = (char *)(NULL); }
    {void * tlv1; tlv1 = (void *)(NULL); }
    {char * tlv12; tlv12 = (char *)(NULL); }
    {cgc_size_t tlv11; tlv11 = (cgc_size_t)(NULL); }
    {char * tlv10; tlv10 = (char *)(NULL); }
    {void * tlv8; tlv8 = (void *)(NULL); }
    {char * tlv16; tlv16 = (char *)(NULL); }
    {char * tlv14; tlv14 = (char *)(NULL); }
    {char * tlv17; tlv17 = (char *)(NULL); }
}
void fix_ingred_kty_15_10(){
fix_ingred_kty_15_10_3();
}
void fix_ingred_kty_15_11_1(){
kty_item_t new_ref;
    bzero(&new_ref,1*sizeof(kty_item_t));
kty_item_t * new = &new_ref;
    {char * tlv3; tlv3 = (char *)(new); }
    {cgc_size_t tlv7; tlv7 = (cgc_size_t)(new); }
    {int tlv5; tlv5 = (int)(new); }
    {char * tlv6; tlv6 = (char *)(new); }
    {void * tlv1; tlv1 = (void *)(new); }
    {char * tlv12; tlv12 = (char *)(new); }
    {cgc_size_t tlv11; tlv11 = (cgc_size_t)(new); }
    {char * tlv10; tlv10 = (char *)(new); }
    {void * tlv8; tlv8 = (void *)(new); }
    {char * tlv16; tlv16 = (char *)(new); }
    {char * tlv14; tlv14 = (char *)(new); }
    {char * tlv17; tlv17 = (char *)(new); }
}
void fix_ingred_kty_15_11(){
fix_ingred_kty_15_11_1();
}
void fix_ingred_kty_15_12_5(){
    {char * tlv3; tlv3 = (char *)(','); }
    {cgc_size_t tlv7; tlv7 = (cgc_size_t)(','); }
    {int tlv5; tlv5 = (int)(','); }
    {char * tlv6; tlv6 = (char *)(','); }
    {void * tlv1; tlv1 = (void *)(','); }
    {char * tlv12; tlv12 = (char *)(','); }
    {cgc_size_t tlv11; tlv11 = (cgc_size_t)(','); }
    {char * tlv10; tlv10 = (char *)(','); }
    {void * tlv8; tlv8 = (void *)(','); }
    {char * tlv16; tlv16 = (char *)(','); }
    {char * tlv14; tlv14 = (char *)(','); }
    {char * tlv17; tlv17 = (char *)(','); }
}
void fix_ingred_kty_15_12(){
fix_ingred_kty_15_12_5();
}
void fix_ingred_kty_15(){
fix_ingred_kty_15_1();
fix_ingred_kty_15_2();
fix_ingred_kty_15_3();
fix_ingred_kty_15_5();
fix_ingred_kty_15_9();
fix_ingred_kty_15_10();
fix_ingred_kty_15_11();
fix_ingred_kty_15_12();
}
void fix_ingred_kty_16_0_0(){
    {char * key; key = (char *)(NULL); }
    {char * tlv4; tlv4 = (char *)(NULL); }
    {cgc_size_t tlv9; tlv9 = (cgc_size_t)(NULL); }
    {int tlv6; tlv6 = (int)(NULL); }
    {char * tlv7; tlv7 = (char *)(NULL); }
    {cgc_size_t tlv10; tlv10 = (cgc_size_t)(NULL); }
    {char * tlv8; tlv8 = (char *)(NULL); }
    {char * tlv2; tlv2 = (char *)(NULL); }
    {char * tlv26; tlv26 = (char *)(NULL); }
    {char * tlv28; tlv28 = (char *)(NULL); }
    {cgc_size_t tlv19; tlv19 = (cgc_size_t)(NULL); }
    {void * tlv11; tlv11 = (void *)(NULL); }
    {cgc_size_t tlv20; tlv20 = (cgc_size_t)(NULL); }
    {cgc_size_t tlv21; tlv21 = (cgc_size_t)(NULL); }
    {char * tlv18; tlv18 = (char *)(NULL); }
    {void * tlv13; tlv13 = (void *)(NULL); }
    {char * tlv34; tlv34 = (char *)(NULL); }
    {char * tlv35; tlv35 = (char *)(NULL); }
    {char * tlv30; tlv30 = (char *)(NULL); }
    {char * tlv32; tlv32 = (char *)(NULL); }
    {cgc_size_t tlv25; tlv25 = (cgc_size_t)(NULL); }
    {char * tlv24; tlv24 = (char *)(NULL); }
    {void * tlv22; tlv22 = (void *)(NULL); }
    {char * tlv36; tlv36 = (char *)(NULL); }
    {char * tlv37; tlv37 = (char *)(NULL); }
}
void fix_ingred_kty_16_0(){
fix_ingred_kty_16_0_0();
}
void fix_ingred_kty_16_1_0(){
char str_ref;
    bzero(&str_ref,1*sizeof(char));
char * str = &str_ref;
    {char * key; key = (char *)(str + 1); }
    {char * tlv4; tlv4 = (char *)(str + 1); }
    {cgc_size_t tlv9; tlv9 = (cgc_size_t)(str + 1); }
    {int tlv6; tlv6 = (int)(str + 1); }
    {char * tlv7; tlv7 = (char *)(str + 1); }
    {cgc_size_t tlv10; tlv10 = (cgc_size_t)(str + 1); }
    {char * tlv8; tlv8 = (char *)(str + 1); }
    {char * tlv2; tlv2 = (char *)(str + 1); }
    {char * tlv26; tlv26 = (char *)(str + 1); }
    {char * tlv28; tlv28 = (char *)(str + 1); }
    {cgc_size_t tlv19; tlv19 = (cgc_size_t)(str + 1); }
    {void * tlv11; tlv11 = (void *)(str + 1); }
    {cgc_size_t tlv20; tlv20 = (cgc_size_t)(str + 1); }
    {cgc_size_t tlv21; tlv21 = (cgc_size_t)(str + 1); }
    {char * tlv18; tlv18 = (char *)(str + 1); }
    {void * tlv13; tlv13 = (void *)(str + 1); }
    {char * tlv34; tlv34 = (char *)(str + 1); }
    {char * tlv35; tlv35 = (char *)(str + 1); }
    {char * tlv30; tlv30 = (char *)(str + 1); }
    {char * tlv32; tlv32 = (char *)(str + 1); }
    {cgc_size_t tlv25; tlv25 = (cgc_size_t)(str + 1); }
    {char * tlv24; tlv24 = (char *)(str + 1); }
    {void * tlv22; tlv22 = (void *)(str + 1); }
    {char * tlv36; tlv36 = (char *)(str + 1); }
    {char * tlv37; tlv37 = (char *)(str + 1); }
}
void fix_ingred_kty_16_1(){
fix_ingred_kty_16_1_0();
}
void fix_ingred_kty_16_2_6(){
char str_ref;
    bzero(&str_ref,1*sizeof(char));
char * str = &str_ref;
    {char * key; key = (char *)(str [ 0 ]); }
    {char * tlv4; tlv4 = (char *)(str [ 0 ]); }
    {cgc_size_t tlv9; tlv9 = (cgc_size_t)(str [ 0 ]); }
    {int tlv6; tlv6 = (int)(str [ 0 ]); }
    {char * tlv7; tlv7 = (char *)(str [ 0 ]); }
    {cgc_size_t tlv10; tlv10 = (cgc_size_t)(str [ 0 ]); }
    {char * tlv8; tlv8 = (char *)(str [ 0 ]); }
    {char * tlv2; tlv2 = (char *)(str [ 0 ]); }
    {char * tlv26; tlv26 = (char *)(str [ 0 ]); }
    {char * tlv28; tlv28 = (char *)(str [ 0 ]); }
    {cgc_size_t tlv19; tlv19 = (cgc_size_t)(str [ 0 ]); }
    {void * tlv11; tlv11 = (void *)(str [ 0 ]); }
    {cgc_size_t tlv20; tlv20 = (cgc_size_t)(str [ 0 ]); }
    {cgc_size_t tlv21; tlv21 = (cgc_size_t)(str [ 0 ]); }
    {char * tlv18; tlv18 = (char *)(str [ 0 ]); }
    {void * tlv13; tlv13 = (void *)(str [ 0 ]); }
    {char * tlv34; tlv34 = (char *)(str [ 0 ]); }
    {char * tlv35; tlv35 = (char *)(str [ 0 ]); }
    {char * tlv30; tlv30 = (char *)(str [ 0 ]); }
    {char * tlv32; tlv32 = (char *)(str [ 0 ]); }
    {cgc_size_t tlv25; tlv25 = (cgc_size_t)(str [ 0 ]); }
    {char * tlv24; tlv24 = (char *)(str [ 0 ]); }
    {void * tlv22; tlv22 = (void *)(str [ 0 ]); }
    {char * tlv36; tlv36 = (char *)(str [ 0 ]); }
    {char * tlv37; tlv37 = (char *)(str [ 0 ]); }
}
void fix_ingred_kty_16_2_7(){
char str_ref;
    bzero(&str_ref,1*sizeof(char));
char * str = &str_ref;
    {char * key; key = (char *)('}'); }
    {char * tlv4; tlv4 = (char *)('}'); }
    {cgc_size_t tlv9; tlv9 = (cgc_size_t)('}'); }
    {int tlv6; tlv6 = (int)('}'); }
    {char * tlv7; tlv7 = (char *)('}'); }
    {cgc_size_t tlv10; tlv10 = (cgc_size_t)('}'); }
    {char * tlv8; tlv8 = (char *)('}'); }
    {char * tlv2; tlv2 = (char *)('}'); }
    {void * tlv1; tlv1 = (void *)('}'); }
    {char * tlv26; tlv26 = (char *)('}'); }
    {char * tlv28; tlv28 = (char *)('}'); }
    {cgc_size_t tlv19; tlv19 = (cgc_size_t)('}'); }
    {char * tlv16; tlv16 = (char *)('}'); }
    {void * tlv11; tlv11 = (void *)('}'); }
    {cgc_size_t tlv20; tlv20 = (cgc_size_t)('}'); }
    {char * tlv17; tlv17 = (char *)('}'); }
    {cgc_size_t tlv21; tlv21 = (cgc_size_t)('}'); }
    {char * tlv18; tlv18 = (char *)('}'); }
    {char * tlv14; tlv14 = (char *)('}'); }
    {void * tlv13; tlv13 = (void *)('}'); }
    {char * tlv34; tlv34 = (char *)('}'); }
    {char * tlv35; tlv35 = (char *)('}'); }
    {char * tlv30; tlv30 = (char *)('}'); }
    {char * tlv32; tlv32 = (char *)('}'); }
    {cgc_size_t tlv25; tlv25 = (cgc_size_t)('}'); }
    {char * tlv24; tlv24 = (char *)('}'); }
    {void * tlv22; tlv22 = (void *)('}'); }
    {char * tlv36; tlv36 = (char *)('}'); }
    {char * tlv37; tlv37 = (char *)('}'); }
}
void fix_ingred_kty_16_2(){
fix_ingred_kty_16_2_6();
fix_ingred_kty_16_2_7();
}
void fix_ingred_kty_16_3_0(){
    {char * key; key = (char *)(sizeof ( kty_item_t )); }
    {char * tlv4; tlv4 = (char *)(sizeof ( kty_item_t )); }
    {cgc_size_t tlv9; tlv9 = (cgc_size_t)(sizeof ( kty_item_t )); }
    {int tlv6; tlv6 = (int)(sizeof ( kty_item_t )); }
    {char * tlv7; tlv7 = (char *)(sizeof ( kty_item_t )); }
    {cgc_size_t tlv10; tlv10 = (cgc_size_t)(sizeof ( kty_item_t )); }
    {char * tlv8; tlv8 = (char *)(sizeof ( kty_item_t )); }
    {char * tlv2; tlv2 = (char *)(sizeof ( kty_item_t )); }
    {char * tlv26; tlv26 = (char *)(sizeof ( kty_item_t )); }
    {char * tlv28; tlv28 = (char *)(sizeof ( kty_item_t )); }
    {cgc_size_t tlv19; tlv19 = (cgc_size_t)(sizeof ( kty_item_t )); }
    {void * tlv11; tlv11 = (void *)(sizeof ( kty_item_t )); }
    {cgc_size_t tlv20; tlv20 = (cgc_size_t)(sizeof ( kty_item_t )); }
    {cgc_size_t tlv21; tlv21 = (cgc_size_t)(sizeof ( kty_item_t )); }
    {char * tlv18; tlv18 = (char *)(sizeof ( kty_item_t )); }
    {void * tlv13; tlv13 = (void *)(sizeof ( kty_item_t )); }
    {char * tlv34; tlv34 = (char *)(sizeof ( kty_item_t )); }
    {char * tlv35; tlv35 = (char *)(sizeof ( kty_item_t )); }
    {char * tlv30; tlv30 = (char *)(sizeof ( kty_item_t )); }
    {char * tlv32; tlv32 = (char *)(sizeof ( kty_item_t )); }
    {cgc_size_t tlv25; tlv25 = (cgc_size_t)(sizeof ( kty_item_t )); }
    {char * tlv24; tlv24 = (char *)(sizeof ( kty_item_t )); }
    {void * tlv22; tlv22 = (void *)(sizeof ( kty_item_t )); }
    {char * tlv36; tlv36 = (char *)(sizeof ( kty_item_t )); }
    {char * tlv37; tlv37 = (char *)(sizeof ( kty_item_t )); }
}
void fix_ingred_kty_16_3(){
fix_ingred_kty_16_3_0();
}
void fix_ingred_kty_16_5_0(){
    {char * key; key = (char *)(4); }
    {char * tlv4; tlv4 = (char *)(4); }
    {cgc_size_t tlv9; tlv9 = (cgc_size_t)(4); }
    {int tlv6; tlv6 = (int)(4); }
    {char * tlv7; tlv7 = (char *)(4); }
    {cgc_size_t tlv10; tlv10 = (cgc_size_t)(4); }
    {char * tlv8; tlv8 = (char *)(4); }
    {char * tlv2; tlv2 = (char *)(4); }
    {char * tlv26; tlv26 = (char *)(4); }
    {char * tlv28; tlv28 = (char *)(4); }
    {cgc_size_t tlv19; tlv19 = (cgc_size_t)(4); }
    {void * tlv11; tlv11 = (void *)(4); }
    {cgc_size_t tlv20; tlv20 = (cgc_size_t)(4); }
    {cgc_size_t tlv21; tlv21 = (cgc_size_t)(4); }
    {char * tlv18; tlv18 = (char *)(4); }
    {void * tlv13; tlv13 = (void *)(4); }
    {char * tlv34; tlv34 = (char *)(4); }
    {char * tlv35; tlv35 = (char *)(4); }
    {char * tlv30; tlv30 = (char *)(4); }
    {char * tlv32; tlv32 = (char *)(4); }
    {cgc_size_t tlv25; tlv25 = (cgc_size_t)(4); }
    {char * tlv24; tlv24 = (char *)(4); }
    {void * tlv22; tlv22 = (void *)(4); }
    {char * tlv36; tlv36 = (char *)(4); }
    {char * tlv37; tlv37 = (char *)(4); }
}
void fix_ingred_kty_16_5(){
fix_ingred_kty_16_5_0();
}
void fix_ingred_kty_16_9_0(){
char str_ref;
    bzero(&str_ref,1*sizeof(char));
char * str = &str_ref;
    {char * key; key = (char *)(str); }
    {char * tlv4; tlv4 = (char *)(str); }
    {cgc_size_t tlv9; tlv9 = (cgc_size_t)(str); }
    {int tlv6; tlv6 = (int)(str); }
    {char * tlv7; tlv7 = (char *)(str); }
    {cgc_size_t tlv10; tlv10 = (cgc_size_t)(str); }
    {char * tlv8; tlv8 = (char *)(str); }
    {char * tlv2; tlv2 = (char *)(str); }
    {char * tlv26; tlv26 = (char *)(str); }
    {char * tlv28; tlv28 = (char *)(str); }
    {cgc_size_t tlv19; tlv19 = (cgc_size_t)(str); }
    {void * tlv11; tlv11 = (void *)(str); }
    {cgc_size_t tlv20; tlv20 = (cgc_size_t)(str); }
    {cgc_size_t tlv21; tlv21 = (cgc_size_t)(str); }
    {char * tlv18; tlv18 = (char *)(str); }
    {void * tlv13; tlv13 = (void *)(str); }
    {char * tlv34; tlv34 = (char *)(str); }
    {char * tlv35; tlv35 = (char *)(str); }
    {char * tlv30; tlv30 = (char *)(str); }
    {char * tlv32; tlv32 = (char *)(str); }
    {cgc_size_t tlv25; tlv25 = (cgc_size_t)(str); }
    {char * tlv24; tlv24 = (char *)(str); }
    {void * tlv22; tlv22 = (void *)(str); }
    {char * tlv36; tlv36 = (char *)(str); }
    {char * tlv37; tlv37 = (char *)(str); }
}
void fix_ingred_kty_16_9(){
fix_ingred_kty_16_9_0();
}
void fix_ingred_kty_16_10_10(){
    {char * key; key = (char *)(':'); }
    {char * tlv4; tlv4 = (char *)(':'); }
    {cgc_size_t tlv9; tlv9 = (cgc_size_t)(':'); }
    {int tlv6; tlv6 = (int)(':'); }
    {char * tlv7; tlv7 = (char *)(':'); }
    {cgc_size_t tlv10; tlv10 = (cgc_size_t)(':'); }
    {char * tlv8; tlv8 = (char *)(':'); }
    {char * tlv2; tlv2 = (char *)(':'); }
    {void * tlv1; tlv1 = (void *)(':'); }
    {char * tlv26; tlv26 = (char *)(':'); }
    {char * tlv28; tlv28 = (char *)(':'); }
    {cgc_size_t tlv19; tlv19 = (cgc_size_t)(':'); }
    {char * tlv16; tlv16 = (char *)(':'); }
    {void * tlv11; tlv11 = (void *)(':'); }
    {cgc_size_t tlv20; tlv20 = (cgc_size_t)(':'); }
    {char * tlv17; tlv17 = (char *)(':'); }
    {cgc_size_t tlv21; tlv21 = (cgc_size_t)(':'); }
    {char * tlv18; tlv18 = (char *)(':'); }
    {char * tlv14; tlv14 = (char *)(':'); }
    {void * tlv13; tlv13 = (void *)(':'); }
    {char * tlv34; tlv34 = (char *)(':'); }
    {char * tlv35; tlv35 = (char *)(':'); }
    {char * tlv30; tlv30 = (char *)(':'); }
    {char * tlv32; tlv32 = (char *)(':'); }
    {cgc_size_t tlv25; tlv25 = (cgc_size_t)(':'); }
    {char * tlv24; tlv24 = (char *)(':'); }
    {void * tlv22; tlv22 = (void *)(':'); }
    {char * tlv36; tlv36 = (char *)(':'); }
    {char * tlv37; tlv37 = (char *)(':'); }
}
void fix_ingred_kty_16_10(){
fix_ingred_kty_16_10_10();
}
void fix_ingred_kty_16_17_1(){
char key_ref;
    bzero(&key_ref,1*sizeof(char));
char * key = &key_ref;
kty_item_t new_ref;
    bzero(&new_ref,1*sizeof(kty_item_t));
kty_item_t * new = &new_ref;
    {char * tlv4; tlv4 = (char *)(key); }
    {cgc_size_t tlv9; tlv9 = (cgc_size_t)(key); }
    {int tlv6; tlv6 = (int)(key); }
    {char * tlv7; tlv7 = (char *)(key); }
    {cgc_size_t tlv10; tlv10 = (cgc_size_t)(key); }
    {char * tlv8; tlv8 = (char *)(key); }
    {char * tlv2; tlv2 = (char *)(key); }
    {void * tlv1; tlv1 = (void *)(key); }
    {char * tlv26; tlv26 = (char *)(key); }
    {char * tlv28; tlv28 = (char *)(key); }
    {cgc_size_t tlv19; tlv19 = (cgc_size_t)(key); }
    {char * tlv16; tlv16 = (char *)(key); }
    {void * tlv11; tlv11 = (void *)(key); }
    {cgc_size_t tlv20; tlv20 = (cgc_size_t)(key); }
    {char * tlv17; tlv17 = (char *)(key); }
    {cgc_size_t tlv21; tlv21 = (cgc_size_t)(key); }
    {char * tlv18; tlv18 = (char *)(key); }
    {char * tlv14; tlv14 = (char *)(key); }
    {void * tlv13; tlv13 = (void *)(key); }
    {char * tlv34; tlv34 = (char *)(key); }
    {char * tlv35; tlv35 = (char *)(key); }
    {char * tlv30; tlv30 = (char *)(key); }
    {char * tlv32; tlv32 = (char *)(key); }
    {cgc_size_t tlv25; tlv25 = (cgc_size_t)(key); }
    {char * tlv24; tlv24 = (char *)(key); }
    {void * tlv22; tlv22 = (void *)(key); }
    {char * tlv36; tlv36 = (char *)(key); }
    {char * tlv37; tlv37 = (char *)(key); }
}
void fix_ingred_kty_16_17_2(){
char key_ref;
    bzero(&key_ref,1*sizeof(char));
char * key = &key_ref;
kty_item_t new_ref;
    bzero(&new_ref,1*sizeof(kty_item_t));
kty_item_t * new = &new_ref;
    {char * key; key = (char *)(new); }
    {char * tlv4; tlv4 = (char *)(new); }
    {cgc_size_t tlv9; tlv9 = (cgc_size_t)(new); }
    {int tlv6; tlv6 = (int)(new); }
    {char * tlv7; tlv7 = (char *)(new); }
    {cgc_size_t tlv10; tlv10 = (cgc_size_t)(new); }
    {char * tlv8; tlv8 = (char *)(new); }
    {char * tlv2; tlv2 = (char *)(new); }
    {char * tlv26; tlv26 = (char *)(new); }
    {char * tlv28; tlv28 = (char *)(new); }
    {cgc_size_t tlv19; tlv19 = (cgc_size_t)(new); }
    {void * tlv11; tlv11 = (void *)(new); }
    {cgc_size_t tlv20; tlv20 = (cgc_size_t)(new); }
    {cgc_size_t tlv21; tlv21 = (cgc_size_t)(new); }
    {char * tlv18; tlv18 = (char *)(new); }
    {void * tlv13; tlv13 = (void *)(new); }
    {char * tlv34; tlv34 = (char *)(new); }
    {char * tlv35; tlv35 = (char *)(new); }
    {char * tlv30; tlv30 = (char *)(new); }
    {char * tlv32; tlv32 = (char *)(new); }
    {cgc_size_t tlv25; tlv25 = (cgc_size_t)(new); }
    {char * tlv24; tlv24 = (char *)(new); }
    {void * tlv22; tlv22 = (void *)(new); }
    {char * tlv36; tlv36 = (char *)(new); }
    {char * tlv37; tlv37 = (char *)(new); }
}
void fix_ingred_kty_16_17(){
fix_ingred_kty_16_17_1();
fix_ingred_kty_16_17_2();
}
void fix_ingred_kty_16_22_1(){
kty_item_t dup_ref;
    bzero(&dup_ref,1*sizeof(kty_item_t));
kty_item_t * dup = &dup_ref;
    {char * key; key = (char *)(dup); }
    {char * tlv4; tlv4 = (char *)(dup); }
    {cgc_size_t tlv9; tlv9 = (cgc_size_t)(dup); }
    {int tlv6; tlv6 = (int)(dup); }
    {char * tlv7; tlv7 = (char *)(dup); }
    {cgc_size_t tlv10; tlv10 = (cgc_size_t)(dup); }
    {char * tlv8; tlv8 = (char *)(dup); }
    {char * tlv2; tlv2 = (char *)(dup); }
    {void * tlv1; tlv1 = (void *)(dup); }
    {char * tlv26; tlv26 = (char *)(dup); }
    {char * tlv28; tlv28 = (char *)(dup); }
    {cgc_size_t tlv19; tlv19 = (cgc_size_t)(dup); }
    {char * tlv16; tlv16 = (char *)(dup); }
    {void * tlv11; tlv11 = (void *)(dup); }
    {cgc_size_t tlv20; tlv20 = (cgc_size_t)(dup); }
    {char * tlv17; tlv17 = (char *)(dup); }
    {cgc_size_t tlv21; tlv21 = (cgc_size_t)(dup); }
    {char * tlv18; tlv18 = (char *)(dup); }
    {char * tlv14; tlv14 = (char *)(dup); }
    {void * tlv13; tlv13 = (void *)(dup); }
    {char * tlv34; tlv34 = (char *)(dup); }
    {char * tlv35; tlv35 = (char *)(dup); }
    {char * tlv30; tlv30 = (char *)(dup); }
    {char * tlv32; tlv32 = (char *)(dup); }
    {cgc_size_t tlv25; tlv25 = (cgc_size_t)(dup); }
    {char * tlv24; tlv24 = (char *)(dup); }
    {void * tlv22; tlv22 = (void *)(dup); }
    {char * tlv36; tlv36 = (char *)(dup); }
    {char * tlv37; tlv37 = (char *)(dup); }
}
void fix_ingred_kty_16_22(){
fix_ingred_kty_16_22_1();
}
void fix_ingred_kty_16_23_13(){
    {char * key; key = (char *)(','); }
    {char * tlv4; tlv4 = (char *)(','); }
    {cgc_size_t tlv9; tlv9 = (cgc_size_t)(','); }
    {int tlv6; tlv6 = (int)(','); }
    {char * tlv7; tlv7 = (char *)(','); }
    {cgc_size_t tlv10; tlv10 = (cgc_size_t)(','); }
    {char * tlv8; tlv8 = (char *)(','); }
    {char * tlv2; tlv2 = (char *)(','); }
    {char * tlv26; tlv26 = (char *)(','); }
    {char * tlv28; tlv28 = (char *)(','); }
    {cgc_size_t tlv19; tlv19 = (cgc_size_t)(','); }
    {void * tlv11; tlv11 = (void *)(','); }
    {cgc_size_t tlv20; tlv20 = (cgc_size_t)(','); }
    {cgc_size_t tlv21; tlv21 = (cgc_size_t)(','); }
    {char * tlv18; tlv18 = (char *)(','); }
    {void * tlv13; tlv13 = (void *)(','); }
    {char * tlv34; tlv34 = (char *)(','); }
    {char * tlv35; tlv35 = (char *)(','); }
    {char * tlv30; tlv30 = (char *)(','); }
    {char * tlv32; tlv32 = (char *)(','); }
    {cgc_size_t tlv25; tlv25 = (cgc_size_t)(','); }
    {char * tlv24; tlv24 = (char *)(','); }
    {void * tlv22; tlv22 = (void *)(','); }
    {char * tlv36; tlv36 = (char *)(','); }
    {char * tlv37; tlv37 = (char *)(','); }
}
void fix_ingred_kty_16_23(){
fix_ingred_kty_16_23_13();
}
void fix_ingred_kty_16(){
fix_ingred_kty_16_0();
fix_ingred_kty_16_1();
fix_ingred_kty_16_2();
fix_ingred_kty_16_3();
fix_ingred_kty_16_5();
fix_ingred_kty_16_9();
fix_ingred_kty_16_10();
fix_ingred_kty_16_17();
fix_ingred_kty_16_22();
fix_ingred_kty_16_23();
}
void fix_ingred_kty_17_1_0(){
char str_ref;
    bzero(&str_ref,1*sizeof(char));
char * str = &str_ref;
    {char c; c = (char)(str [ 0 ]); }
    {int tlv1; tlv1 = (int)(str [ 0 ]); }
    {int tlv2; tlv2 = (int)(str [ 0 ]); }
    {int tlv3; tlv3 = (int)(str [ 0 ]); }
    {int tlv4; tlv4 = (int)(str [ 0 ]); }
    {char * tlv7; tlv7 = (char *)(str [ 0 ]); }
    {char* tlv6 ; tlv6  = (char*)(str [ 0 ]); }
    {int tlv5; tlv5 = (int)(str [ 0 ]); }
    {char * tlv10; tlv10 = (char *)(str [ 0 ]); }
    {char* tlv9 ; tlv9  = (char*)(str [ 0 ]); }
    {int tlv8; tlv8 = (int)(str [ 0 ]); }
    {char * tlv13; tlv13 = (char *)(str [ 0 ]); }
    {char* tlv12 ; tlv12  = (char*)(str [ 0 ]); }
    {int tlv11; tlv11 = (int)(str [ 0 ]); }
    {char * tlv16; tlv16 = (char *)(str [ 0 ]); }
    {char* tlv15 ; tlv15  = (char*)(str [ 0 ]); }
    {int tlv14; tlv14 = (int)(str [ 0 ]); }
}
void fix_ingred_kty_17_1(){
fix_ingred_kty_17_1_0();
}
void fix_ingred_kty_17_2_0(){
char str_ref;
    bzero(&str_ref,1*sizeof(char));
char * str = &str_ref;
    {char c; c = (char)(str); }
    {int tlv1; tlv1 = (int)(str); }
    {int tlv2; tlv2 = (int)(str); }
    {int tlv3; tlv3 = (int)(str); }
    {int tlv4; tlv4 = (int)(str); }
    {char* tlv6 ; tlv6  = (char*)(str); }
    {char* tlv9 ; tlv9  = (char*)(str); }
    {int tlv8; tlv8 = (int)(str); }
    {char * tlv13; tlv13 = (char *)(str); }
    {char* tlv12 ; tlv12  = (char*)(str); }
    {int tlv11; tlv11 = (int)(str); }
    {char* tlv15 ; tlv15  = (char*)(str); }
    {int tlv14; tlv14 = (int)(str); }
}
void fix_ingred_kty_17_2_1(){
char str_ref;
    bzero(&str_ref,1*sizeof(char));
char * str = &str_ref;
    {char c; c = (char)(4); }
    {int tlv1; tlv1 = (int)(4); }
    {int tlv2; tlv2 = (int)(4); }
    {int tlv3; tlv3 = (int)(4); }
    {int tlv4; tlv4 = (int)(4); }
    {char* tlv6 ; tlv6  = (char*)(4); }
    {char* tlv9 ; tlv9  = (char*)(4); }
    {int tlv8; tlv8 = (int)(4); }
    {char * tlv13; tlv13 = (char *)(4); }
    {char* tlv12 ; tlv12  = (char*)(4); }
    {int tlv11; tlv11 = (int)(4); }
    {char* tlv15 ; tlv15  = (char*)(4); }
    {int tlv14; tlv14 = (int)(4); }
}
void fix_ingred_kty_17_2(){
fix_ingred_kty_17_2_0();
fix_ingred_kty_17_2_1();
}
void fix_ingred_kty_17_3_3(){
int tlv1;
    bzero(&tlv1,sizeof(int));
    {char c; c = (char)(tlv1); }
    {int tlv2; tlv2 = (int)(tlv1); }
    {int tlv4; tlv4 = (int)(tlv1); }
    {char * tlv7; tlv7 = (char *)(tlv1); }
    {char* tlv6 ; tlv6  = (char*)(tlv1); }
    {char * tlv10; tlv10 = (char *)(tlv1); }
    {char* tlv9 ; tlv9  = (char*)(tlv1); }
    {char * tlv13; tlv13 = (char *)(tlv1); }
    {char* tlv12 ; tlv12  = (char*)(tlv1); }
    {int tlv11; tlv11 = (int)(tlv1); }
    {char * tlv16; tlv16 = (char *)(tlv1); }
    {char* tlv15 ; tlv15  = (char*)(tlv1); }
}
void fix_ingred_kty_17_3_4(){
int tlv1;
    bzero(&tlv1,sizeof(int));
    {char c; c = (char)(0); }
    {char * tlv7; tlv7 = (char *)(0); }
    {char* tlv6 ; tlv6  = (char*)(0); }
    {char * tlv10; tlv10 = (char *)(0); }
    {char* tlv9 ; tlv9  = (char*)(0); }
    {char* tlv12 ; tlv12  = (char*)(0); }
    {char * tlv16; tlv16 = (char *)(0); }
    {char* tlv15 ; tlv15  = (char*)(0); }
}
void fix_ingred_kty_17_3(){
fix_ingred_kty_17_3_3();
fix_ingred_kty_17_3_4();
}
void fix_ingred_kty_17_4_1(){
    {char c; c = (char)(5); }
    {int tlv1; tlv1 = (int)(5); }
    {int tlv2; tlv2 = (int)(5); }
    {int tlv3; tlv3 = (int)(5); }
    {int tlv4; tlv4 = (int)(5); }
    {char * tlv7; tlv7 = (char *)(5); }
    {char* tlv6 ; tlv6  = (char*)(5); }
    {int tlv5; tlv5 = (int)(5); }
    {char * tlv10; tlv10 = (char *)(5); }
    {char* tlv9 ; tlv9  = (char*)(5); }
    {int tlv8; tlv8 = (int)(5); }
    {char * tlv13; tlv13 = (char *)(5); }
    {char* tlv12 ; tlv12  = (char*)(5); }
    {int tlv11; tlv11 = (int)(5); }
    {char * tlv16; tlv16 = (char *)(5); }
    {char* tlv15 ; tlv15  = (char*)(5); }
    {int tlv14; tlv14 = (int)(5); }
}
void fix_ingred_kty_17_4(){
fix_ingred_kty_17_4_1();
}
void fix_ingred_kty_17_5_3(){
int tlv2;
    bzero(&tlv2,sizeof(int));
    {char c; c = (char)(tlv2); }
    {int tlv1; tlv1 = (int)(tlv2); }
    {int tlv3; tlv3 = (int)(tlv2); }
    {int tlv4; tlv4 = (int)(tlv2); }
    {char * tlv7; tlv7 = (char *)(tlv2); }
    {char* tlv6 ; tlv6  = (char*)(tlv2); }
    {int tlv5; tlv5 = (int)(tlv2); }
    {char * tlv10; tlv10 = (char *)(tlv2); }
    {char* tlv9 ; tlv9  = (char*)(tlv2); }
    {int tlv8; tlv8 = (int)(tlv2); }
    {char * tlv13; tlv13 = (char *)(tlv2); }
    {char* tlv12 ; tlv12  = (char*)(tlv2); }
    {int tlv11; tlv11 = (int)(tlv2); }
    {char * tlv16; tlv16 = (char *)(tlv2); }
    {char* tlv15 ; tlv15  = (char*)(tlv2); }
    {int tlv14; tlv14 = (int)(tlv2); }
}
void fix_ingred_kty_17_5(){
fix_ingred_kty_17_5_3();
}
void fix_ingred_kty_17_7_2(){
int tlv3;
    bzero(&tlv3,sizeof(int));
    {char c; c = (char)(tlv3); }
    {int tlv1; tlv1 = (int)(tlv3); }
    {int tlv2; tlv2 = (int)(tlv3); }
    {int tlv4; tlv4 = (int)(tlv3); }
    {char * tlv7; tlv7 = (char *)(tlv3); }
    {char* tlv6 ; tlv6  = (char*)(tlv3); }
    {int tlv5; tlv5 = (int)(tlv3); }
    {char * tlv10; tlv10 = (char *)(tlv3); }
    {char* tlv9 ; tlv9  = (char*)(tlv3); }
    {int tlv8; tlv8 = (int)(tlv3); }
    {char * tlv13; tlv13 = (char *)(tlv3); }
    {char* tlv12 ; tlv12  = (char*)(tlv3); }
    {int tlv11; tlv11 = (int)(tlv3); }
    {char * tlv16; tlv16 = (char *)(tlv3); }
    {char* tlv15 ; tlv15  = (char*)(tlv3); }
    {int tlv14; tlv14 = (int)(tlv3); }
}
void fix_ingred_kty_17_7(){
fix_ingred_kty_17_7_2();
}
void fix_ingred_kty_17_9_2(){
int tlv4;
    bzero(&tlv4,sizeof(int));
    {char c; c = (char)(tlv4); }
    {int tlv1; tlv1 = (int)(tlv4); }
    {int tlv2; tlv2 = (int)(tlv4); }
    {int tlv3; tlv3 = (int)(tlv4); }
    {char * tlv7; tlv7 = (char *)(tlv4); }
    {char* tlv6 ; tlv6  = (char*)(tlv4); }
    {int tlv5; tlv5 = (int)(tlv4); }
    {char * tlv10; tlv10 = (char *)(tlv4); }
    {char* tlv9 ; tlv9  = (char*)(tlv4); }
    {int tlv8; tlv8 = (int)(tlv4); }
    {char * tlv13; tlv13 = (char *)(tlv4); }
    {char* tlv12 ; tlv12  = (char*)(tlv4); }
    {int tlv11; tlv11 = (int)(tlv4); }
    {char * tlv16; tlv16 = (char *)(tlv4); }
    {char* tlv15 ; tlv15  = (char*)(tlv4); }
    {int tlv14; tlv14 = (int)(tlv4); }
}
void fix_ingred_kty_17_9(){
fix_ingred_kty_17_9_2();
}
void fix_ingred_kty_17(){
fix_ingred_kty_17_1();
fix_ingred_kty_17_2();
fix_ingred_kty_17_3();
fix_ingred_kty_17_4();
fix_ingred_kty_17_5();
fix_ingred_kty_17_7();
fix_ingred_kty_17_9();
}
void fix_ingred_kty_18_0_0(){
    {char string [ MAX_KTY_STRING ]; string [ ( MAX_KTY_STRING )-1 ] = (char)(0); }
    {int init; init = (int)(0); }
    {int state; state = (int)(0); }
    {cgc_size_t tlv6; tlv6 = (cgc_size_t)(0); }
    {cgc_size_t tlv5; tlv5 = (cgc_size_t)(0); }
    {char * tlv3; tlv3 = (char *)(0); }
    {char * tlv8; tlv8 = (char *)(0); }
}
void fix_ingred_kty_18_0_2(){
    {char * c; c = (char *)(- 1); }
    {char string [ MAX_KTY_STRING ]; string [ ( MAX_KTY_STRING )-1 ] = (char)(- 1); }
    {int i; i = (int)(- 1); }
    {int init; init = (int)(- 1); }
    {int state; state = (int)(- 1); }
    {cgc_size_t tlv6; tlv6 = (cgc_size_t)(- 1); }
    {cgc_size_t tlv5; tlv5 = (cgc_size_t)(- 1); }
    {int tlv2; tlv2 = (int)(- 1); }
    {char * tlv3; tlv3 = (char *)(- 1); }
    {char * tlv8; tlv8 = (char *)(- 1); }
}
void fix_ingred_kty_18_0(){
fix_ingred_kty_18_0_0();
fix_ingred_kty_18_0_2();
}
void fix_ingred_kty_18_1_0(){
    {char * c; c = (char *)(1); }
    {char string [ MAX_KTY_STRING ]; string [ ( MAX_KTY_STRING )-1 ] = (char)(1); }
    {int i; i = (int)(1); }
    {int init; init = (int)(1); }
    {int state; state = (int)(1); }
    {cgc_size_t tlv6; tlv6 = (cgc_size_t)(1); }
    {cgc_size_t tlv5; tlv5 = (cgc_size_t)(1); }
    {int tlv2; tlv2 = (int)(1); }
    {char * tlv3; tlv3 = (char *)(1); }
    {char * tlv8; tlv8 = (char *)(1); }
}
void fix_ingred_kty_18_1_1(){
    {char * c; c = (char *)(sizeof ( kty_item_t )); }
    {char string [ MAX_KTY_STRING ]; string [ ( MAX_KTY_STRING )-1 ] = (char)(sizeof ( kty_item_t )); }
    {int i; i = (int)(sizeof ( kty_item_t )); }
    {int init; init = (int)(sizeof ( kty_item_t )); }
    {int state; state = (int)(sizeof ( kty_item_t )); }
    {cgc_size_t tlv6; tlv6 = (cgc_size_t)(sizeof ( kty_item_t )); }
    {cgc_size_t tlv5; tlv5 = (cgc_size_t)(sizeof ( kty_item_t )); }
    {int tlv2; tlv2 = (int)(sizeof ( kty_item_t )); }
}
void fix_ingred_kty_18_1(){
fix_ingred_kty_18_1_0();
fix_ingred_kty_18_1_1();
}
void fix_ingred_kty_18_5_0(){
    {char * c; c = (char *)(16); }
    {char string [ MAX_KTY_STRING ]; string [ ( MAX_KTY_STRING )-1 ] = (char)(16); }
    {int i; i = (int)(16); }
    {int init; init = (int)(16); }
    {int state; state = (int)(16); }
    {cgc_size_t tlv6; tlv6 = (cgc_size_t)(16); }
    {cgc_size_t tlv5; tlv5 = (cgc_size_t)(16); }
    {int tlv2; tlv2 = (int)(16); }
    {char * tlv3; tlv3 = (char *)(16); }
    {char * tlv8; tlv8 = (char *)(16); }
}
void fix_ingred_kty_18_5(){
fix_ingred_kty_18_5_0();
}
void fix_ingred_kty_18_8_0(){
char str_ref;
    bzero(&str_ref,1*sizeof(char));
char * str = &str_ref;
    {char * c; c = (char *)(str); }
    {char string [ MAX_KTY_STRING ]; string [ ( MAX_KTY_STRING )-1 ] = (char)(str); }
    {int i; i = (int)(str); }
    {int init; init = (int)(str); }
    {int state; state = (int)(str); }
    {cgc_size_t tlv6; tlv6 = (cgc_size_t)(str); }
    {cgc_size_t tlv5; tlv5 = (cgc_size_t)(str); }
}
void fix_ingred_kty_18_8(){
fix_ingred_kty_18_8_0();
}
void fix_ingred_kty_18_9_3(){
char c_ref;
    bzero(&c_ref,1*sizeof(char));
char * c = &c_ref;
    {char string [ MAX_KTY_STRING ]; string [ ( MAX_KTY_STRING )-1 ] = (char)(c); }
    {int i; i = (int)(c); }
    {int init; init = (int)(c); }
    {int state; state = (int)(c); }
    {cgc_size_t tlv6; tlv6 = (cgc_size_t)(c); }
    {cgc_size_t tlv5; tlv5 = (cgc_size_t)(c); }
    {int tlv2; tlv2 = (int)(c); }
    {char * tlv3; tlv3 = (char *)(c); }
    {char * tlv8; tlv8 = (char *)(c); }
}
void fix_ingred_kty_18_9_4(){
char c_ref;
    bzero(&c_ref,1*sizeof(char));
char * c = &c_ref;
    {char * c; c = (char *)(NULL); }
    {char string [ MAX_KTY_STRING ]; string [ ( MAX_KTY_STRING )-1 ] = (char)(NULL); }
    {int init; init = (int)(NULL); }
    {int state; state = (int)(NULL); }
    {cgc_size_t tlv6; tlv6 = (cgc_size_t)(NULL); }
    {cgc_size_t tlv5; tlv5 = (cgc_size_t)(NULL); }
    {int tlv2; tlv2 = (int)(NULL); }
}
void fix_ingred_kty_18_9(){
fix_ingred_kty_18_9_3();
fix_ingred_kty_18_9_4();
}
void fix_ingred_kty_18(){
fix_ingred_kty_18_0();
fix_ingred_kty_18_1();
fix_ingred_kty_18_5();
fix_ingred_kty_18_8();
fix_ingred_kty_18_9();
}
void fix_ingred_kty_19(){
}
void fix_ingred_kty_20(){
}