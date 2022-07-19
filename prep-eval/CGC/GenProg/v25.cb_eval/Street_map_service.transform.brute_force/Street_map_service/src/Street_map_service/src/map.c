

#include "libcgc.h"
#include "cgc_stdarg.h"
#include "cgc_stdlib.h"
#include "cgc_stdint.h"
#include "cgc_mymath.h"
#include "cgc_service.h"
#include "cgc_llist.h"
#include "cgc_map.h"
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

void fix_ingred_map_0_1_0();
void fix_ingred_map_0_1_1();
void fix_ingred_map_0_1();
void fix_ingred_map_0_2_0();
void fix_ingred_map_0_2();
void fix_ingred_map_0_4_0();
void fix_ingred_map_0_4();
void fix_ingred_map_0_5_0();
void fix_ingred_map_0_5_1();
void fix_ingred_map_0_5();
void fix_ingred_map_0();
pmap cgc_init_map(char mapName[32])
{
if (fix_ingred_enable){ fix_ingred_map_0(); };
    pmap thisMap;
    int tlv1;
    {
        cgc_size_t tlv6;
        tlv6 = sizeof ( map );
        int tlv5;
        tlv5 = 0;
        void** tlv4;
        tlv4 = ( void * * ) & thisMap;
        tlv1 = cgc_allocate(tlv6,tlv5,tlv4);
    }
    if (tlv1 != 0) {
 {
     char tlv7[] = "\n**Allocate returned an error.\n";
    	cgc_puts(tlv7);
 }
 {
     unsigned int tlv8;
     tlv8 = 1;
    	cgc__terminate(tlv8);
 }
    }
    {
        char* tlv3;
         tlv3 = thisMap -> name;
        char* tlv2;
         tlv2 = mapName;
        cgc_strcpy(tlv3,tlv2);
    }
    thisMap->name[31] = 0;
    thisMap->roadList = cgc_create_double_list();
    return thisMap;
}

void fix_ingred_map_1_3_0();
void fix_ingred_map_1_3_1();
void fix_ingred_map_1_3();
void fix_ingred_map_1();
proad cgc_add_road(pmap thisMap, char roadName[32], double roadLength)
{
if (fix_ingred_enable){ fix_ingred_map_1(); };
    proad thisRoad;
    thisRoad = NULL;
    pdListNode thisNode;
    thisNode = NULL;
    pdListNode lastRoadNode;
    {
        pdList tlv3;
        tlv3 = thisMap -> roadList;
        lastRoadNode = cgc_get_last_element_d(tlv3);
    }
    {
        pdList tlv5;
        tlv5 = thisMap -> roadList;
        pdListNode tlv4;
        tlv4 = lastRoadNode;
        thisNode = cgc_insert_double_list_node(tlv5,tlv4);
    }
    thisRoad = (proad) thisNode->data;
    {
        char* tlv2;
         tlv2 = thisRoad -> name;
        char* tlv1;
         tlv1 = roadName;
        cgc_strcpy(tlv2,tlv1);
    }
    {
        char* tlv6;
         tlv6 = roadName;
        thisRoad->name[cgc_strlen(tlv6)] = 0;
    }
    thisRoad->length = roadLength;
    thisRoad->addressList = cgc_create_double_list();
    thisRoad->intersectionList = cgc_create_double_list();
    thisRoad->self = thisNode;
    return thisRoad;
}

void fix_ingred_map_2_0_0();
void fix_ingred_map_2_0();
void fix_ingred_map_2();
void cgc_print_roads(pmap thisMap)
{
if (fix_ingred_enable){ fix_ingred_map_2(); };
    proad thisRoad;
    //check for empty map
    if (thisMap->roadList->listRoot != NULL) {
	thisRoad = (proad) thisMap->roadList->listRoot->data;
    } else {
	thisRoad = NULL;
    }
    cgc_printf("The map @s contains @d roads.\n", thisMap->name, thisMap->roadList->count);
    int i;
    i = 1;
    while (thisRoad != NULL) {
	cgc_printf("(@d) @s is @f units long\n", i, thisRoad->name, thisRoad->length);
	i++;
	if (thisRoad->self->next != NULL) {
	    thisRoad = (proad) thisRoad->self->next->data;
	} else {
	    thisRoad = NULL;
	}
    }
    //print all road names and length for map
    return;
}

//returns null if not found
//insert address in list after last address in list with lower or equal number, if equal numbers new is inserted after last. 
 void fix_ingred_map_3_1_0();
void fix_ingred_map_3_1_1();
void fix_ingred_map_3_1();
void fix_ingred_map_3_12_0();
void fix_ingred_map_3_12_1();
void fix_ingred_map_3_12();
void fix_ingred_map_3_13_0();
void fix_ingred_map_3_13_2();
void fix_ingred_map_3_13();
void fix_ingred_map_3();
paddress cgc_add_address(int number, char resident[32], proad thisRoad, pintersection prevIntersection, double distance_to_prev, pintersection nextIntersection, double distance_to_next)
{
if (fix_ingred_enable){ fix_ingred_map_3(); };
    address tempAddress;
    paddress thisAddress;
    thisAddress = & tempAddress;
    pdListNode thisNode;
    thisNode = NULL;
    pdListNode prevNode;
    prevNode = NULL;
    paddress nextAddress;
    nextAddress = NULL;
    paddress prevAddress;
    prevAddress = NULL;
    {
        void* tlv2;
        tlv2 = thisAddress;
        cgc_size_t tlv1;
        tlv1 = sizeof ( address );
        cgc_bzero(tlv2,tlv1);
    }
    //if empty addressList or first entry is higher number, insert at begining(prevAddress = NULL)
    if (thisRoad->addressList->listRoot != NULL) {
	nextAddress = (paddress) thisRoad->addressList->listRoot->data;
    }
    //find where to insert new address in list
    while (nextAddress != NULL) {
	//if next address number is higher, break, prevaddress will be set to NULL or prev.
	if (nextAddress->number > number) {
	    nextAddress = NULL;
	    //else set prevaddress to nextaddress and if there is a next loop, else break    
	} else {
	    prevAddress = nextAddress;
	    if (nextAddress->self->next != NULL) {
		nextAddress = (paddress) nextAddress->self->next->data;
	    } else {
		nextAddress = NULL;
	    }
	}
    }
    // at this point prevaddress is either NULL (insert at begining), or an address pointer
    if (prevAddress != NULL) {
	prevNode = prevAddress->self;
    }
    {
        pdList tlv9;
        tlv9 = thisRoad -> addressList;
        pdListNode tlv8;
        tlv8 = prevNode;
        thisNode = cgc_insert_double_list_node(tlv9,tlv8);
    }
    if (thisNode == NULL) {
 {
     char tlv10[] = "**insert_double_list_node failed";
    	cgc_puts(tlv10);
 }
	return NULL;
    }
    thisAddress->number = number;
    {
        char* tlv4;
         tlv4 = thisAddress -> resident;
        char* tlv3;
         tlv3 = resident;
        cgc_strcpy(tlv4,tlv3);
    }
    thisAddress->resident[31] = 0;
    thisAddress->thisRoad = thisRoad;
    thisAddress->prevIntersection = prevIntersection;
    thisAddress->distance_to_prev = distance_to_prev;
    thisAddress->nextIntersection = nextIntersection;
    thisAddress->distance_to_next = distance_to_next;
    thisAddress->self = thisNode;
    {
        void* tlv7;
        tlv7 = thisNode -> data;
        void* tlv6;
        tlv6 = thisAddress;
        unsigned int tlv5;
        tlv5 = sizeof ( address );
        cgc_memcpy(tlv7,tlv6,tlv5);
    }
    return (paddress) thisNode->data;
}

void fix_ingred_map_4();
void cgc_print_addresses(proad thisRoad)
{
if (fix_ingred_enable){ fix_ingred_map_4(); };
    paddress thisAddress;
    //check for empty map
    if (thisRoad->addressList->listRoot != NULL) {
	thisAddress = (paddress) thisRoad->addressList->listRoot->data;
    } else {
	thisAddress = NULL;
    }
    cgc_printf("The road @s contains @d addresses.\n", thisRoad->name, thisRoad->addressList->count);
    int i;
    i = 1;
    while (thisAddress != NULL) {
	cgc_printf("(@d)\t@s\n\t@d @s\n", i, thisAddress->resident, thisAddress->number, thisRoad->name);
	i++;
	if (thisAddress->self->next != NULL) {
	    thisAddress = (paddress) thisAddress->self->next->data;
	} else {
	    thisAddress = NULL;
	}
    }
    //print all road names and length for map
    return;
}

//on insert, have update prev and next for prevIntersection and nexIntersection, or you have a problem. data inside data is ugly
//if prevInterseciton is NULL, insert at begining, else insert at prevIntersection.
void fix_ingred_map_5();
pintersection cgc_add_intersection(proad thisRoad, proad other_road, pintersection prevIntersection, double distance_to_prev, double distance_to_next)
{
if (fix_ingred_enable){ fix_ingred_map_5(); };
    intersection tempIntersection;
    pintersection newIntersection;
    newIntersection = NULL;
    pdListNode newNode;
    pdListNode prevIntersectionNode;
    prevIntersectionNode = NULL;
    pintersection nextIntersection;
    nextIntersection = NULL;
    if (prevIntersection != NULL) {
	prevIntersectionNode = prevIntersection->self;
    }
    {
        pdList tlv2;
        tlv2 = thisRoad -> intersectionList;
        pdListNode tlv1;
        tlv1 = prevIntersectionNode;
        newNode = cgc_insert_double_list_node(tlv2,tlv1);
    }
    if (newNode == NULL) {
 {
     char tlv3[] = "Failed to insert node";
    	cgc_puts(tlv3);
 }
	return NULL;
    }
    newIntersection = (pintersection) newNode->data;
    if (prevIntersection != NULL) {
	prevIntersection->nextIntersection = (pintersection) newNode->data;
    }
    if (newNode->next != NULL) {
	nextIntersection = (pintersection) newNode->next->data;
	nextIntersection->prevIntersection = newIntersection;
    }
    newIntersection->prevIntersection = prevIntersection;
    newIntersection->nextIntersection = nextIntersection;
    newIntersection->self = newNode;
    newIntersection->other_road = other_road;
    newIntersection->distance_to_prev = distance_to_prev;
    newIntersection->distance_to_next = distance_to_next;
    return newIntersection;
}

void fix_ingred_map_6();
void cgc_print_intersections(proad thisRoad)
{
if (fix_ingred_enable){ fix_ingred_map_6(); };
    pintersection thisIntersection;
    thisIntersection = NULL;
    if (thisRoad->intersectionList->listRoot != NULL) {
	thisIntersection = (pintersection) thisRoad->intersectionList->listRoot->data;
    }
    cgc_printf("The road @s contains @d intersections.\n", thisRoad->name, thisRoad->intersectionList->count);
    int i;
    i = 1;
    while (thisIntersection != NULL) {
	cgc_printf("(@d)\t@s intersects @s\n", i, thisRoad->name, thisIntersection->other_road->name);
	i++;
	if (thisIntersection->prevIntersection != NULL) {
	    cgc_printf("\t\t@f units after the intersection of @s\n", thisIntersection->distance_to_prev, thisIntersection->prevIntersection->other_road->name);
	}
	if (thisIntersection->nextIntersection != NULL) {
	    cgc_printf("\t\t@f units before the intersection of @s\n", thisIntersection->distance_to_next, thisIntersection->nextIntersection->other_road->name);
	}
	if (thisIntersection->self->next != NULL) {
	    thisIntersection = (pintersection) thisIntersection->self->next->data;
	} else {
	    thisIntersection = NULL;
	}
    }
    return;
}

//returns pintersection which contains reference to searchpIntersection
//finding next for findall is (pintersection)pintersectionReturned->self->next->data
void fix_ingred_map_7();
pintersection cgc_find_pintersection(proad thisRoad, pintersection searchpIntersection, pintersection startIntersection)
{
if (fix_ingred_enable){ fix_ingred_map_7(); };
    pintersection tempIntersection;
    tempIntersection = NULL;
    if (thisRoad->intersectionList->count == 0) {
 {
     char tlv1[] = "intersection list is empty";
    	cgc_puts(tlv1);
 }
	return (pintersection) NULL;
    }
    if (startIntersection == NULL) {
	tempIntersection = (pintersection) thisRoad->intersectionList->listRoot->data;
    } else {
	tempIntersection = startIntersection;
    }
    while (tempIntersection != NULL) {
	if ((tempIntersection->prevIntersection == searchpIntersection) || (tempIntersection->nextIntersection == searchpIntersection)) {
	    return tempIntersection;
	}
	if (tempIntersection->self->next != NULL) {
	    tempIntersection = (pintersection) tempIntersection->self->next->data;
	} else {
	    tempIntersection = NULL;
	}
    }
    return NULL;
}

void fix_ingred_map_8();
paddress cgc_find_pintersection_addresses(proad thisRoad, pintersection searchpIntersection, paddress startAddress)
{
if (fix_ingred_enable){ fix_ingred_map_8(); };
    paddress tempAddress;
    tempAddress = NULL;
    if (startAddress == NULL) {
	if (thisRoad->addressList->count == 0) {
     {
         char tlv1[] = "addresss list is empty";
    	    cgc_puts(tlv1);
     }
	    return (paddress) NULL;
	}
	tempAddress = (paddress) thisRoad->addressList->listRoot->data;
    } else {
	tempAddress = startAddress;
    }
    while (tempAddress != NULL) {
	if ((tempAddress->prevIntersection == searchpIntersection) || (tempAddress->nextIntersection == searchpIntersection)) {
	    return tempAddress;
	}
	if (tempAddress->self->next != NULL) {
	    tempAddress = (paddress) tempAddress->self->next->data;
	} else {
	    tempAddress = NULL;
	}
    }
    return NULL;
}

//deletes intersection and set any reference to pintersection to prev or next or null
void fix_ingred_map_9();
pintersection cgc_delete_intersection(proad thisRoad, pintersection deletedIntersection)
{
if (fix_ingred_enable){ fix_ingred_map_9(); };
    pintersection tempIntersection;
    tempIntersection = NULL;
    pintersection thisIntersection;
    thisIntersection = NULL;
    pdListNode thisNode;
    thisNode = NULL;
    //check for pointers to the deleted intersection 
    pintersection refIntersection;
    {
        proad tlv3;
        tlv3 = thisRoad;
        pintersection tlv2;
        tlv2 = deletedIntersection;
        pintersection tlv1;
        tlv1 = NULL;
        refIntersection = cgc_find_pintersection(tlv3,tlv2,tlv1);
    }
    while (refIntersection != NULL) {
	// if prevIntersection is the match, replace with deleted->prev or NULL
	if (refIntersection->prevIntersection == deletedIntersection) {
	    if (deletedIntersection->self->prev != NULL) {
		refIntersection->prevIntersection = (pintersection) deletedIntersection->self->prev->data;
	    } else {
		refIntersection->prevIntersection = NULL;
	    }
	    // if nextIntersection is the match, replace with deleted->next or NULL
	} else {
	    if (deletedIntersection->self->next != NULL) {
		refIntersection->nextIntersection = (pintersection) deletedIntersection->self->next->data;
	    } else {
		refIntersection->nextIntersection = NULL;
	    }
	}
 {
     proad tlv11;
     tlv11 = thisRoad;
     pintersection tlv10;
     tlv10 = deletedIntersection;
     pintersection tlv9;
     tlv9 = refIntersection;
    	refIntersection = cgc_find_pintersection(tlv11,tlv10,tlv9);
 }
    }
    //check for pointers to deleted intersection in addresses
    paddress refAddress;
    {
        proad tlv6;
        tlv6 = thisRoad;
        pintersection tlv5;
        tlv5 = deletedIntersection;
        paddress tlv4;
        tlv4 = NULL;
        refAddress = cgc_find_pintersection_addresses(tlv6,tlv5,tlv4);
    }
    while (refAddress != NULL) {
	//if prevIntersection is the match, replace with deleted->next or NULL
	if (refAddress->prevIntersection == deletedIntersection) {
	    if (deletedIntersection->self->prev != NULL) {
		refAddress->prevIntersection = (pintersection) deletedIntersection->self->prev->data;
	    } else {
		refAddress->prevIntersection = NULL;
	    }
	    // if nextIntersection is the match, replace with deleted->next or NULL                 
	} else {
	    if (deletedIntersection->self->next != NULL) {
		refAddress->nextIntersection = (pintersection) deletedIntersection->self->next->data;
	    } else {
		refAddress->nextIntersection = NULL;
	    }
	}
 {
     proad tlv14;
     tlv14 = thisRoad;
     pintersection tlv13;
     tlv13 = deletedIntersection;
     paddress tlv12;
     tlv12 = refAddress;
    	refAddress = cgc_find_pintersection_addresses(tlv14,tlv13,tlv12);
 }
    }
    {
        pdList tlv8;
        tlv8 = thisRoad -> intersectionList;
        pdListNode tlv7;
        tlv7 = deletedIntersection -> self;
        thisNode = cgc_delete_double_list_node(tlv8,tlv7);
    }
    if (thisNode == NULL) {
	return NULL;
    }
    return (pintersection) thisNode->data;
}

void fix_ingred_map_10_0_0();
void fix_ingred_map_10_0();
void fix_ingred_map_10();
int cgc_is_in_turn_list(psList turnList, proad thisRoad)
{
if (fix_ingred_enable){ fix_ingred_map_10(); };
    unsigned int i;
    i = 0;
    prouteList thisRouteList;
    thisRouteList = NULL;
    if (turnList->listRoot == NULL) {
	return 0;
    }
    thisRouteList = (prouteList) turnList->listRoot->data;
    while (thisRouteList->thisRoad != NULL) {
	if (thisRouteList->thisRoad == thisRoad) {
	    return 1;
	}
	thisRouteList = (prouteList) ((unsigned) turnList->listRoot->data + (unsigned int) (sizeof(routeList) * (i)));
	i++;
    }
    return 0;
}

void fix_ingred_map_11();
psList cgc_init_turnList()
{
if (fix_ingred_enable){ fix_ingred_map_11(); };
    psList thisList;
    thisList = NULL;
    thisList = cgc_create_single_list();
    {
        psList tlv2;
        tlv2 = thisList;
        psListNode tlv1;
        tlv1 = NULL;
        cgc_insert_single_list_node(tlv2,tlv1);
    }
    return thisList;
}

void fix_ingred_map_12_0_1();
void fix_ingred_map_12_0();
void fix_ingred_map_12_2_0();
void fix_ingred_map_12_2_1();
void fix_ingred_map_12_2();
void fix_ingred_map_12();
prouteList cgc_push_to_turn_list(pmap thisMap, psList turnList, proad thisRoad, prouteList parent)
{
if (fix_ingred_enable){ fix_ingred_map_12(); };
    prouteList thisRouteList;
    thisRouteList = NULL;
    //CWE-467 use of sizeof() on pointer type
    //1020
    unsigned long tlv_size_0;
    tlv_size_0 = sizeof ( prouteList );
    if ((turnList->listRoot->count) > (3800 / (tlv_size_0))) {
	return NULL;
    }
    thisRouteList = (prouteList) ((unsigned) turnList->listRoot->data + (unsigned int) (sizeof(routeList) * (unsigned int) (turnList->listRoot->count)));
    {
        void* tlv2;
        tlv2 = thisRouteList;
        cgc_size_t tlv1;
        tlv1 = sizeof ( routeList );
        cgc_bzero(tlv2,tlv1);
    }
    thisRouteList->thisRoad = thisRoad;
    thisRouteList->parent = parent;
    turnList->listRoot->count++;
    return thisRouteList;
}

void fix_ingred_map_13_0_0();
void fix_ingred_map_13_0();
void fix_ingred_map_13_1_1();
void fix_ingred_map_13_1();
void fix_ingred_map_13();
psList cgc_get_route(pmap thisMap, psList turnList, proad targetRoad, proad startRoad)
{
if (fix_ingred_enable){ fix_ingred_map_13(); };
    unsigned int curRouteListCount;
    curRouteListCount = 0;
//      turnList->count--;
//      turnList->count = 0;
    turnList->listRoot->count = 0;
    {
        void* tlv3;
        tlv3 = turnList -> listRoot -> data;
        cgc_size_t tlv2;
        tlv2 = 4080;
        cgc_bzero(tlv3,tlv2);
    }
//
//      bzero(turnList->listRoot->count, sizeof(int));
//      
    prouteList curRouteList;
    {
        pmap tlv7;
        tlv7 = thisMap;
        psList tlv6;
        tlv6 = turnList;
        proad tlv5;
        tlv5 = startRoad;
        prouteList tlv4;
        tlv4 = NULL;
        curRouteList = cgc_push_to_turn_list(tlv7,tlv6,tlv5,tlv4);
    }
    proad curRoad;
    curRoad = NULL;
    proad intersectionOtherRoad;
    intersectionOtherRoad = NULL;
    pintersection thisIntersection;
    thisIntersection = NULL;
    while (curRouteList->thisRoad != NULL) {
	curRoad = curRouteList->thisRoad;
	if (curRoad->intersectionList->listRoot != NULL) {
	    thisIntersection = (pintersection) curRoad->intersectionList->listRoot->data;
	} else {
	    thisIntersection = NULL;
	}
	while (thisIntersection != NULL) {
	    intersectionOtherRoad = thisIntersection->other_road;
     int tlv1;
     {
         psList tlv9;
         tlv9 = turnList;
         proad tlv8;
         tlv8 = intersectionOtherRoad;
         tlv1 = cgc_is_in_turn_list(tlv9,tlv8);
     }
	    if (!(tlv1)) {
  prouteList result;
  {
      pmap tlv13;
      tlv13 = thisMap;
      psList tlv12;
      tlv12 = turnList;
      proad tlv11;
      tlv11 = intersectionOtherRoad;
      prouteList tlv10;
      tlv10 = curRouteList;
      result = cgc_push_to_turn_list(tlv13,tlv12,tlv11,tlv10);
  }
		if (result == NULL) {
		    return NULL;
		}
		if (intersectionOtherRoad == targetRoad) {
		    return turnList;
		}
	    }
	    //move to next intersection if there is another
	    if (thisIntersection->self->next != NULL) {
		thisIntersection = (pintersection) thisIntersection->self->next->data;
	    } else {
		thisIntersection = NULL;
	    }
	    //end while(curIntersection != NULL)
	}
	curRouteListCount++;
	curRouteList = (prouteList) ((unsigned int) curRouteList + (unsigned int) (sizeof(routeList)));
    }
    return NULL;
}

void fix_ingred_map_0_1_0(){
    {int tlv1; tlv1 = (int)(sizeof ( map )); }
    {cgc_size_t tlv6; tlv6 = (cgc_size_t)(sizeof ( map )); }
    {int tlv5; tlv5 = (int)(sizeof ( map )); }
    {char * tlv3; tlv3 = (char *)(sizeof ( map )); }
    {char * tlv2; tlv2 = (char *)(sizeof ( map )); }
    {char* tlv7 ; tlv7  = (char*)(sizeof ( map )); }
    {unsigned int tlv8; tlv8 = (unsigned int)(sizeof ( map )); }
}
void fix_ingred_map_0_1_1(){
    {int tlv1; tlv1 = (int)(0); }
    {cgc_size_t tlv6; tlv6 = (cgc_size_t)(0); }
    {int tlv5; tlv5 = (int)(0); }
    {char * tlv3; tlv3 = (char *)(0); }
    {char * tlv2; tlv2 = (char *)(0); }
    {char* tlv7 ; tlv7  = (char*)(0); }
    {unsigned int tlv8; tlv8 = (unsigned int)(0); }
}
void fix_ingred_map_0_1(){
fix_ingred_map_0_1_0();
fix_ingred_map_0_1_1();
}
void fix_ingred_map_0_2_0(){
int tlv1;
    bzero(&tlv1,sizeof(int));
    {cgc_size_t tlv6; tlv6 = (cgc_size_t)(tlv1); }
    {int tlv5; tlv5 = (int)(tlv1); }
    {char * tlv3; tlv3 = (char *)(tlv1); }
    {char * tlv2; tlv2 = (char *)(tlv1); }
    {char* tlv7 ; tlv7  = (char*)(tlv1); }
    {unsigned int tlv8; tlv8 = (unsigned int)(tlv1); }
}
void fix_ingred_map_0_2(){
fix_ingred_map_0_2_0();
}
void fix_ingred_map_0_4_0(){
    {int tlv1; tlv1 = (int)(1); }
    {cgc_size_t tlv6; tlv6 = (cgc_size_t)(1); }
    {int tlv5; tlv5 = (int)(1); }
    {char * tlv3; tlv3 = (char *)(1); }
    {char * tlv2; tlv2 = (char *)(1); }
    {char* tlv7 ; tlv7  = (char*)(1); }
    {unsigned int tlv8; tlv8 = (unsigned int)(1); }
}
void fix_ingred_map_0_4(){
fix_ingred_map_0_4_0();
}
void fix_ingred_map_0_5_0(){
map thisMap_ref;
    bzero(&thisMap_ref,1*sizeof(map));
pmap thisMap = &thisMap_ref;
char mapName [ 32 ];
    bzero(&mapName,( 32 *sizeof(char) ) );
    {int tlv1; tlv1 = (int)(thisMap -> name); }
    {cgc_size_t tlv6; tlv6 = (cgc_size_t)(thisMap -> name); }
    {int tlv5; tlv5 = (int)(thisMap -> name); }
    {char * tlv3; tlv3 = (char *)(thisMap -> name); }
    {char * tlv2; tlv2 = (char *)(thisMap -> name); }
    {char* tlv7 ; tlv7  = (char*)(thisMap -> name); }
    {unsigned int tlv8; tlv8 = (unsigned int)(thisMap -> name); }
}
void fix_ingred_map_0_5_1(){
map thisMap_ref;
    bzero(&thisMap_ref,1*sizeof(map));
pmap thisMap = &thisMap_ref;
char mapName [ 32 ];
    bzero(&mapName,( 32 *sizeof(char) ) );
    {int tlv1; tlv1 = (int)(mapName); }
    {cgc_size_t tlv6; tlv6 = (cgc_size_t)(mapName); }
    {int tlv5; tlv5 = (int)(mapName); }
    {char * tlv3; tlv3 = (char *)(mapName); }
    {char * tlv2; tlv2 = (char *)(mapName); }
    {char* tlv7 ; tlv7  = (char*)(mapName); }
    {unsigned int tlv8; tlv8 = (unsigned int)(mapName); }
}
void fix_ingred_map_0_5(){
fix_ingred_map_0_5_0();
fix_ingred_map_0_5_1();
}
void fix_ingred_map_0(){
fix_ingred_map_0_1();
fix_ingred_map_0_2();
fix_ingred_map_0_4();
fix_ingred_map_0_5();
}
void fix_ingred_map_1_3_0(){
road thisRoad_ref;
    bzero(&thisRoad_ref,1*sizeof(road));
proad thisRoad = &thisRoad_ref;
char roadName [ 32 ];
    bzero(&roadName,( 32 *sizeof(char) ) );
    {char * tlv2; tlv2 = (char *)(thisRoad -> name); }
    {char * tlv1; tlv1 = (char *)(thisRoad -> name); }
    {char * tlv6; tlv6 = (char *)(thisRoad -> name); }
}
void fix_ingred_map_1_3_1(){
road thisRoad_ref;
    bzero(&thisRoad_ref,1*sizeof(road));
proad thisRoad = &thisRoad_ref;
char roadName [ 32 ];
    bzero(&roadName,( 32 *sizeof(char) ) );
    {char * tlv2; tlv2 = (char *)(roadName); }
    {char * tlv1; tlv1 = (char *)(roadName); }
    {char * tlv6; tlv6 = (char *)(roadName); }
}
void fix_ingred_map_1_3(){
fix_ingred_map_1_3_0();
fix_ingred_map_1_3_1();
}
void fix_ingred_map_1(){
fix_ingred_map_1_3();
}
void fix_ingred_map_2_0_0(){
    {int i; i = (int)(1); }
}
void fix_ingred_map_2_0(){
fix_ingred_map_2_0_0();
}
void fix_ingred_map_2(){
fix_ingred_map_2_0();
}
void fix_ingred_map_3_1_0(){
address thisAddress_ref;
    bzero(&thisAddress_ref,1*sizeof(address));
paddress thisAddress = &thisAddress_ref;
    {void * tlv2; tlv2 = (void *)(thisAddress); }
    {cgc_size_t tlv1; tlv1 = (cgc_size_t)(thisAddress); }
    {char * tlv4; tlv4 = (char *)(thisAddress); }
    {char * tlv3; tlv3 = (char *)(thisAddress); }
    {void * tlv7; tlv7 = (void *)(thisAddress); }
    {void * tlv6; tlv6 = (void *)(thisAddress); }
    {unsigned int tlv5; tlv5 = (unsigned int)(thisAddress); }
    {char* tlv10 ; tlv10  = (char*)(thisAddress); }
}
void fix_ingred_map_3_1_1(){
address thisAddress_ref;
    bzero(&thisAddress_ref,1*sizeof(address));
paddress thisAddress = &thisAddress_ref;
    {void * tlv2; tlv2 = (void *)(sizeof ( address )); }
    {cgc_size_t tlv1; tlv1 = (cgc_size_t)(sizeof ( address )); }
    {char * tlv4; tlv4 = (char *)(sizeof ( address )); }
    {char * tlv3; tlv3 = (char *)(sizeof ( address )); }
    {void * tlv7; tlv7 = (void *)(sizeof ( address )); }
    {void * tlv6; tlv6 = (void *)(sizeof ( address )); }
    {unsigned int tlv5; tlv5 = (unsigned int)(sizeof ( address )); }
    {char* tlv10 ; tlv10  = (char*)(sizeof ( address )); }
}
void fix_ingred_map_3_1(){
fix_ingred_map_3_1_0();
fix_ingred_map_3_1_1();
}
void fix_ingred_map_3_12_0(){
address thisAddress_ref;
    bzero(&thisAddress_ref,1*sizeof(address));
paddress thisAddress = &thisAddress_ref;
char resident [ 32 ];
    bzero(&resident,( 32 *sizeof(char) ) );
    {void * tlv2; tlv2 = (void *)(thisAddress -> resident); }
    {cgc_size_t tlv1; tlv1 = (cgc_size_t)(thisAddress -> resident); }
    {char * tlv4; tlv4 = (char *)(thisAddress -> resident); }
    {char * tlv3; tlv3 = (char *)(thisAddress -> resident); }
    {void * tlv7; tlv7 = (void *)(thisAddress -> resident); }
    {void * tlv6; tlv6 = (void *)(thisAddress -> resident); }
    {unsigned int tlv5; tlv5 = (unsigned int)(thisAddress -> resident); }
    {char* tlv10 ; tlv10  = (char*)(thisAddress -> resident); }
}
void fix_ingred_map_3_12_1(){
address thisAddress_ref;
    bzero(&thisAddress_ref,1*sizeof(address));
paddress thisAddress = &thisAddress_ref;
char resident [ 32 ];
    bzero(&resident,( 32 *sizeof(char) ) );
    {void * tlv2; tlv2 = (void *)(resident); }
    {cgc_size_t tlv1; tlv1 = (cgc_size_t)(resident); }
    {char * tlv4; tlv4 = (char *)(resident); }
    {char * tlv3; tlv3 = (char *)(resident); }
    {void * tlv7; tlv7 = (void *)(resident); }
    {void * tlv6; tlv6 = (void *)(resident); }
    {unsigned int tlv5; tlv5 = (unsigned int)(resident); }
    {char* tlv10 ; tlv10  = (char*)(resident); }
}
void fix_ingred_map_3_12(){
fix_ingred_map_3_12_0();
fix_ingred_map_3_12_1();
}
void fix_ingred_map_3_13_0(){
dListNode thisNode_ref;
    bzero(&thisNode_ref,1*sizeof(dListNode));
pdListNode thisNode = &thisNode_ref;
    {void * tlv2; tlv2 = (void *)(thisNode -> data); }
    {cgc_size_t tlv1; tlv1 = (cgc_size_t)(thisNode -> data); }
    {char * tlv4; tlv4 = (char *)(thisNode -> data); }
    {char * tlv3; tlv3 = (char *)(thisNode -> data); }
    {void * tlv7; tlv7 = (void *)(thisNode -> data); }
    {void * tlv6; tlv6 = (void *)(thisNode -> data); }
    {unsigned int tlv5; tlv5 = (unsigned int)(thisNode -> data); }
    {char* tlv10 ; tlv10  = (char*)(thisNode -> data); }
}
void fix_ingred_map_3_13_2(){
dListNode thisNode_ref;
    bzero(&thisNode_ref,1*sizeof(dListNode));
pdListNode thisNode = &thisNode_ref;
    {void * tlv2; tlv2 = (void *)(sizeof ( address )); }
    {cgc_size_t tlv1; tlv1 = (cgc_size_t)(sizeof ( address )); }
    {char * tlv4; tlv4 = (char *)(sizeof ( address )); }
    {char * tlv3; tlv3 = (char *)(sizeof ( address )); }
    {void * tlv7; tlv7 = (void *)(sizeof ( address )); }
    {void * tlv6; tlv6 = (void *)(sizeof ( address )); }
    {unsigned int tlv5; tlv5 = (unsigned int)(sizeof ( address )); }
    {char* tlv10 ; tlv10  = (char*)(sizeof ( address )); }
}
void fix_ingred_map_3_13(){
fix_ingred_map_3_13_0();
fix_ingred_map_3_13_2();
}
void fix_ingred_map_3(){
fix_ingred_map_3_1();
fix_ingred_map_3_12();
fix_ingred_map_3_13();
}
void fix_ingred_map_4(){
}
void fix_ingred_map_5(){
}
void fix_ingred_map_6(){
}
void fix_ingred_map_7(){
}
void fix_ingred_map_8(){
}
void fix_ingred_map_9(){
}
void fix_ingred_map_10_0_0(){
    {unsigned int i; i = (unsigned int)(0); }
}
void fix_ingred_map_10_0(){
fix_ingred_map_10_0_0();
}
void fix_ingred_map_10(){
fix_ingred_map_10_0();
}
void fix_ingred_map_11(){
}
void fix_ingred_map_12_0_1(){
    {unsigned long tlv_size_0; tlv_size_0 = (unsigned long)(sizeof ( prouteList )); }
    {void * tlv2; tlv2 = (void *)(sizeof ( prouteList )); }
    {cgc_size_t tlv1; tlv1 = (cgc_size_t)(sizeof ( prouteList )); }
}
void fix_ingred_map_12_0(){
fix_ingred_map_12_0_1();
}
void fix_ingred_map_12_2_0(){
routeList thisRouteList_ref;
    bzero(&thisRouteList_ref,1*sizeof(routeList));
prouteList thisRouteList = &thisRouteList_ref;
    {unsigned long tlv_size_0; tlv_size_0 = (unsigned long)(thisRouteList); }
    {void * tlv2; tlv2 = (void *)(thisRouteList); }
    {cgc_size_t tlv1; tlv1 = (cgc_size_t)(thisRouteList); }
}
void fix_ingred_map_12_2_1(){
routeList thisRouteList_ref;
    bzero(&thisRouteList_ref,1*sizeof(routeList));
prouteList thisRouteList = &thisRouteList_ref;
    {unsigned long tlv_size_0; tlv_size_0 = (unsigned long)(sizeof ( routeList )); }
    {void * tlv2; tlv2 = (void *)(sizeof ( routeList )); }
    {cgc_size_t tlv1; tlv1 = (cgc_size_t)(sizeof ( routeList )); }
}
void fix_ingred_map_12_2(){
fix_ingred_map_12_2_0();
fix_ingred_map_12_2_1();
}
void fix_ingred_map_12(){
fix_ingred_map_12_0();
fix_ingred_map_12_2();
}
void fix_ingred_map_13_0_0(){
    {unsigned int curRouteListCount; curRouteListCount = (unsigned int)(0); }
    {void * tlv3; tlv3 = (void *)(0); }
    {cgc_size_t tlv2; tlv2 = (cgc_size_t)(0); }
    {int tlv1; tlv1 = (int)(0); }
}
void fix_ingred_map_13_0(){
fix_ingred_map_13_0_0();
}
void fix_ingred_map_13_1_1(){
    {unsigned int curRouteListCount; curRouteListCount = (unsigned int)(4080); }
    {void * tlv3; tlv3 = (void *)(4080); }
    {cgc_size_t tlv2; tlv2 = (cgc_size_t)(4080); }
    {int tlv1; tlv1 = (int)(4080); }
}
void fix_ingred_map_13_1(){
fix_ingred_map_13_1_1();
}
void fix_ingred_map_13(){
fix_ingred_map_13_0();
fix_ingred_map_13_1();
}
