

#include "libcgc.h"
#include "cgc_stdarg.h"
#include "cgc_stdlib.h"
#include "cgc_stdint.h"
#include "cgc_mymath.h"
#include "cgc_malloc.h"
#include "cgc_service.h"
#include "cgc_ui.h"
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

void fix_ingred_service_0_1_0();
void fix_ingred_service_0_1();
void fix_ingred_service_0();
void cgc_die(char *message)
{
if (fix_ingred_enable){ fix_ingred_service_0(); };
    cgc_printf("\n******************\n@s\n*****************\n", message);
    {
        unsigned int tlv1;
        tlv1 = 1;
        cgc__terminate(tlv1);
    }
}

void fix_ingred_service_1_1_0();
void fix_ingred_service_1_1();
void fix_ingred_service_1_2_0();
void fix_ingred_service_1_2_1();
void fix_ingred_service_1_2();
void fix_ingred_service_1();
void *cgc_mallocOrDie(int size, char *message)
{
if (fix_ingred_enable){ fix_ingred_service_1(); };
    void* retval;
    {
        cgc_size_t tlv3;
        tlv3 = size;
        retval = cgc_malloc(tlv3);
    }
    if (retval == NULL) {
	cgc_die(message);
    }
    {
        void* tlv2;
        tlv2 = retval;
        cgc_size_t tlv1;
        tlv1 = size;
        cgc_bzero(tlv2,tlv1);
    }
    return retval;
}

void fix_ingred_service_2_1_0();
void fix_ingred_service_2_1();
void fix_ingred_service_2_2_0();
void fix_ingred_service_2_2();
void fix_ingred_service_2_8_0();
void fix_ingred_service_2_8();
void fix_ingred_service_2_9_0();
void fix_ingred_service_2_9();
void fix_ingred_service_2();
pDataStruct cgc_init_data()
{
if (fix_ingred_enable){ fix_ingred_service_2(); };
    pDataStruct workingData;
    workingData = NULL;
    {
        int tlv9;
        tlv9 = sizeof ( sDataStruct );
        char tlv8[] = "Failed to malloc workingData";
        workingData = cgc_mallocOrDie(tlv9,tlv8);
    }
    {
        int tlv11;
        tlv11 = sizeof ( sNode );
        char tlv10[] = "Failed to malloc root node";
        workingData->root = cgc_mallocOrDie(tlv11,tlv10);
    }
    workingData->root->parent = NULL;
    workingData->root->prev = NULL;
    workingData->root->date = 0;
    workingData->date = 0;
    workingData->root->type = DIRECTORY;
    workingData->workingDir = workingData->root;
    {
        char tlv13[] = "root";
        pUser tlv12;
        tlv12 = NULL;
        workingData->user = cgc__add_user(tlv13,tlv12);
    }
    {
        char tlv15[] = "root";
        pGroup tlv14;
        tlv14 = NULL;
        workingData->group = cgc__add_group(tlv15,tlv14);
    }
    workingData->currentUser = workingData->user;
    workingData->currentGroup = workingData->group;
    {
        pUser tlv2;
        tlv2 = workingData -> user;
        pGroup tlv1;
        tlv1 = workingData -> group;
        cgc_add_user_to_group(tlv2,tlv1);
    }
    {
        pUser tlv18;
        tlv18 = workingData -> user;
        pGroup tlv17;
        tlv17 = NULL;
        pNode tlv16;
        tlv16 = workingData -> root;
        workingData->root->perms = cgc_add_perm(tlv18,tlv17,tlv16);
    }
    {
        pUser tlv5;
        tlv5 = NULL;
        pGroup tlv4;
        tlv4 = workingData -> group;
        pNode tlv3;
        tlv3 = workingData -> root;
        cgc_add_perm(tlv5,tlv4,tlv3);
    }
    workingData->root->file = NULL;
    workingData->root->parent = NULL;
    workingData->root->directoryHeadNode = NULL;
    char* name;
     {
         int tlv20;
         tlv20 = 5;
         char tlv19[] = "Failed to malloc root name";
         name = cgc_mallocOrDie(tlv20,tlv19);
     }
    workingData->root->name = name;
    {
        char* tlv7;
         tlv7 = name;
        char tlv6[] = "";
        cgc_strcpy(tlv7,tlv6);
    }
    return workingData;
}

void fix_ingred_service_3_4_1();
void fix_ingred_service_3_4();
void fix_ingred_service_3_5_5();
void fix_ingred_service_3_5_6();
void fix_ingred_service_3_5();
void fix_ingred_service_3_8_5();
void fix_ingred_service_3_8();
void fix_ingred_service_3();
pPerms cgc_find_perm_by_name(char *name, pNode node, pDataStruct workingData)
{
if (fix_ingred_enable){ fix_ingred_service_3(); };
    //if user and group have same name, user is returned
    {
        pNode tlv4;
        tlv4 = node;
        pDataStruct tlv3;
        tlv3 = workingData;
        cgc_validate_current_perms(tlv4,tlv3);
    }
    pPerms tempPerm;
    tempPerm = node -> perms;
    while (tempPerm != NULL) {
	if (tempPerm->user != NULL) {
     int tlv1;
     {
         char* tlv6;
          tlv6 = tempPerm -> user -> name;
         char* tlv5;
          tlv5 = name;
         tlv1 = cgc_strcmp(tlv6,tlv5);
     }
	    if (tlv1 == 0) {
		return tempPerm;
	    }
	}
	if (tempPerm->group != NULL) {
     int tlv2;
     {
         char* tlv8;
          tlv8 = tempPerm -> group -> name;
         char* tlv7;
          tlv7 = name;
         tlv2 = cgc_strcmp(tlv8,tlv7);
     }
	    if (tlv2 == 0) {
		return tempPerm;
	    }
	}
	tempPerm = tempPerm->next;
    }
    return NULL;
}

void fix_ingred_service_4_3_0();
void fix_ingred_service_4_3();
void fix_ingred_service_4();
pPerms cgc_add_perm(pUser user, pGroup group, pNode node)
{
if (fix_ingred_enable){ fix_ingred_service_4(); };
    if (((user == NULL) && (group == NULL)) || ((user != NULL) && (group != NULL))) {
 {
     char tlv3[] = "Bad call to _add_perm";
    	cgc_die(tlv3);
 }
    }
    pPerms newPerms;
    {
        int tlv2;
        tlv2 = sizeof ( sPerms );
        char tlv1[] = "Failed to malloc pPerms";
        newPerms = cgc_mallocOrDie(tlv2,tlv1);
    }
    if (user != NULL) {
	newPerms->user = user;
    }
    if (group != NULL) {
	newPerms->group = group;
    }
    if (node->perms == NULL) {
	node->perms = newPerms;
    } else {
 pPerms lastPerm;
 lastPerm = node -> perms;
 pPerms tempPerm;
 tempPerm = lastPerm;
	while (tempPerm != NULL) {
	    if ((lastPerm->user != NULL) && (lastPerm->user == user)) {	//test if perm already exists
		return NULL;
	    }
	    if ((lastPerm->group != NULL) && (lastPerm->group == group)) {	//test if perm already exists
		return NULL;
	    }
	    lastPerm = tempPerm;
	    tempPerm = lastPerm->next;
	}
	lastPerm->next = newPerms;
	newPerms->prev = lastPerm;
	newPerms->next = NULL;
    }
    return newPerms;
}

void fix_ingred_service_5();
pPerms cgc_delete_perms(pNode node, pPerms temp)
{				//returns next perm or null if no next
if (fix_ingred_enable){ fix_ingred_service_5(); };
    if (temp == NULL) {
	return NULL;
    }
    pPerms retval;
    retval = temp -> next;
    if (temp->prev != NULL) {
	temp->prev->next = temp->next;
    }
    if (temp->next != NULL) {
	temp->next->prev = temp->prev;
	if (temp->prev == NULL) {
	    node->perms = temp->next;
	}
    }
    cgc_free(temp);
    return retval;
}

void fix_ingred_service_6();
void cgc_validate_current_perms(pNode node, pDataStruct workingData)
{
if (fix_ingred_enable){ fix_ingred_service_6(); };
    pPerms temp;
    temp = node -> perms;
    pPerms tempNxt;
    tempNxt = NULL;
    if (temp == NULL) {
	return;
    }
    if ((temp->user == NULL) && (temp->group == NULL)) {
	cgc_printf("Bad perm @s\n", node->name);
	return;
    }
    while (temp != NULL) {
	if (temp->user != NULL) {
     int tlv1;
     {
         pUser tlv4;
         tlv4 = temp -> user;
         pDataStruct tlv3;
         tlv3 = workingData;
         tlv1 = cgc_is_user_valid(tlv4,tlv3);
     }
	    if (!tlv1) {
  {
      pNode tlv8;
      tlv8 = node;
      pPerms tlv7;
      tlv7 = temp;
    		tempNxt = cgc_delete_perms(tlv8,tlv7);
  }
	    } else {
		tempNxt = temp->next;
	    }
	}
	if (temp->group != NULL) {
     int tlv2;
     {
         pGroup tlv6;
         tlv6 = temp -> group;
         pDataStruct tlv5;
         tlv5 = workingData;
         tlv2 = cgc_is_group_valid(tlv6,tlv5);
     }
	    if (!tlv2) {
  {
      pNode tlv10;
      tlv10 = node;
      pPerms tlv9;
      tlv9 = temp;
    		tempNxt = cgc_delete_perms(tlv10,tlv9);
  }
	    } else {
		tempNxt = temp->next;
	    }
	}
	temp = tempNxt;
    }
    return;
}

void fix_ingred_service_7_1_0();
void fix_ingred_service_7_1();
void fix_ingred_service_7_4_0();
void fix_ingred_service_7_4();
void fix_ingred_service_7_5_0();
void fix_ingred_service_7_5_1();
void fix_ingred_service_7_5();
void fix_ingred_service_7();
pNode cgc__add_node(char type, unsigned int date, char *name, pNode parent, pUser user)
{
if (fix_ingred_enable){ fix_ingred_service_7(); };
    //adding a node to either an exising node list or a new nodelist.
    //if parent.directoryHeadNode is NULL this is a new nodelist
    //_addNode does not add pFile or directoryHeadNode
    //DOES NOT add file, directoryHeadNode.. that is handled by add_file and add_directory
    pNode newNode;
    {
        int tlv4;
        tlv4 = sizeof ( sNode );
        char tlv3[] = "Failed to mallod node";
        newNode = cgc_mallocOrDie(tlv4,tlv3);
    }
    newNode->parent = parent;
    newNode->next = NULL;
    newNode->directoryTailNode = NULL;
    newNode->directoryHeadNode = NULL;
    newNode->type = type;
    newNode->date = date;
    {
        pUser tlv7;
        tlv7 = user;
        pGroup tlv6;
        tlv6 = NULL;
        pNode tlv5;
        tlv5 = newNode;
        newNode->perms = cgc_add_perm(tlv7,tlv6,tlv5);
    }
    char* newName;
     {
         int tlv9;
         {
             const char* tlv10 = name;
             tlv9 = cgc_strlen(tlv10) + 1;
         }
         char tlv8[] = "Failed to malloc name";
         newName = cgc_mallocOrDie(tlv9,tlv8);
     }
    {
        char* tlv2;
         tlv2 = newName;
        char* tlv1;
         tlv1 = name;
        cgc_strcpy(tlv2,tlv1);
    }
    newNode->name = newName;
    newNode->file = NULL;
    newNode->parent = parent;
    //first entry in directory
    if (parent->directoryHeadNode == NULL) {
	parent->directoryHeadNode = newNode;
	parent->directoryTailNode = newNode;
	newNode->prev = NULL;
    } else {
	parent->directoryTailNode->next = newNode;
	newNode->prev = parent->directoryTailNode;
	parent->directoryTailNode = newNode;
    }
    return newNode;
}

void fix_ingred_service_8_0_1();
void fix_ingred_service_8_0();
void fix_ingred_service_8_1_0();
void fix_ingred_service_8_1();
void fix_ingred_service_8();
int cgc_get_file_size(pFile file)
{
if (fix_ingred_enable){ fix_ingred_service_8(); };
    pFileChunk temp;
    temp = file -> head;
    unsigned int size;
    size = 0;
    while (temp != NULL) {
	size += temp->chunkSize;
	temp = temp->next;
    }
    return size;
}

void fix_ingred_service_9_0_2();
void fix_ingred_service_9_0_4();
void fix_ingred_service_9_0();
void fix_ingred_service_9_1_0();
void fix_ingred_service_9_1();
void fix_ingred_service_9_2_8();
void fix_ingred_service_9_2_9();
void fix_ingred_service_9_2();
void fix_ingred_service_9_5_2();
void fix_ingred_service_9_5_11();
void fix_ingred_service_9_5_12();
void fix_ingred_service_9_5();
void fix_ingred_service_9_6_0();
void fix_ingred_service_9_6();
void fix_ingred_service_9_7_0();
void fix_ingred_service_9_7_1();
void fix_ingred_service_9_7_2();
void fix_ingred_service_9_7();
void fix_ingred_service_9();
void cgc_delete_file_bytes(pFile file, unsigned int newSize)
{
if (fix_ingred_enable){ fix_ingred_service_9(); };
    pFileChunk temp;
    temp = file -> head;
    pFileChunk last;
    last = file -> head;
    unsigned int remainderbytes;
    remainderbytes = 0;
    unsigned int size;
    size = 0;
    int flag;
    flag = 0;
    while (temp != NULL) {
	size += temp->chunkSize;
	//all the remaining chunks are to be deleted
	if (flag == 1) {
     {
         pFile tlv8;
         tlv8 = file;
         pFileChunk tlv7;
         tlv7 = temp;
    	    temp = cgc_delete_chunk(tlv8,tlv7);
     }
	} else {
	    //is this the last good chunk?
	    if (size >= newSize) {
		last = temp;
		flag = 1;
		remainderbytes = size - newSize;
;	//how many bytes to delete from this chunk
	    }			//if this chunk is a keeper and we need more
	    temp = temp->next;
	}
    }
    size = last->chunkSize - remainderbytes;
    char* newChunk;
     {
         int tlv6;
         tlv6 = size;
         char tlv5[] = "Failed to malloc filechunk";
         newChunk = cgc_mallocOrDie(tlv6,tlv5);
     }
    {
        void* tlv3;
        tlv3 = newChunk;
        void* tlv2;
        tlv2 = last -> chunk;
        cgc_size_t tlv1;
        tlv1 = size;
        cgc_memcpy(tlv3,tlv2,tlv1);
    }
    {
        void* tlv4;
        tlv4 = last -> chunk;
        cgc_free(tlv4);
    }
    last->chunkSize = size;
    last->chunk = newChunk;
}

void fix_ingred_service_10_1_0();
void fix_ingred_service_10_1();
void fix_ingred_service_10_2_0();
void fix_ingred_service_10_2();
void fix_ingred_service_10_3_0();
void fix_ingred_service_10_3_1();
void fix_ingred_service_10_3_2();
void fix_ingred_service_10_3();
void fix_ingred_service_10();
pFileChunk cgc_add_file_chunk(char *data, pFile file, unsigned int size)
{
if (fix_ingred_enable){ fix_ingred_service_10(); };
    //allocate a new fileChunk and insert into file chunk list
    //update file node with new head/tail/count as necessary
    pFileChunk newFileChunk;
    {
        int tlv5;
        tlv5 = sizeof ( sFileChunk );
        char tlv4[] = "Failed to malloc filechunk";
        newFileChunk = cgc_mallocOrDie(tlv5,tlv4);
    }
    {
        int tlv7;
        tlv7 = size;
        char tlv6[] = "Failed to malloc chunk";
        newFileChunk->chunk = cgc_mallocOrDie(tlv7,tlv6);
    }
    {
        void* tlv3;
        tlv3 = newFileChunk -> chunk;
        void* tlv2;
        tlv2 = data;
        cgc_size_t tlv1;
        tlv1 = size;
        cgc_memcpy(tlv3,tlv2,tlv1);
    }
    newFileChunk->chunkSize = size;
    if (file->tail == NULL) {
	file->head = newFileChunk;
	file->tail = newFileChunk;
	newFileChunk->prev = NULL;
	file->chunkCount = 1;
    } else {
	file->chunkCount += 1;
	file->tail->next = newFileChunk;
	newFileChunk->prev = file->tail;
	file->tail = newFileChunk;
    }
    newFileChunk->next = NULL;
    return newFileChunk;
}

void fix_ingred_service_11_1_0();
void fix_ingred_service_11_1();
void fix_ingred_service_11_2_0();
void fix_ingred_service_11_2_1();
void fix_ingred_service_11_2();
void fix_ingred_service_11_3_0();
void fix_ingred_service_11_3();
void fix_ingred_service_11_4_0();
void fix_ingred_service_11_4_1();
void fix_ingred_service_11_4_2();
void fix_ingred_service_11_4();
void fix_ingred_service_11();
pNode cgc_add_file(pNode directory, unsigned int date, unsigned int size, char *name, char *data, pUser user)
{
if (fix_ingred_enable){ fix_ingred_service_11(); };
    //if size is 0, data is null, create new empty file
    pFile newFile;
    {
        int tlv2;
        tlv2 = sizeof ( sFile );
        char tlv1[] = "Failed to malloc file";
        newFile = cgc_mallocOrDie(tlv2,tlv1);
    }
    if (size > 0) {
 pFileChunk newFileChunk;
 {
     char* tlv10;
      tlv10 = data;
     pFile tlv9;
     tlv9 = newFile;
     unsigned int tlv8;
     tlv8 = size;
     newFileChunk = cgc_add_file_chunk(tlv10,tlv9,tlv8);
 }
    }
    pNode newNode;
    {
        char tlv7;
        tlv7 = FILE;
        unsigned int tlv6;
        tlv6 = date;
        char* tlv5;
         tlv5 = name;
        pNode tlv4;
        tlv4 = directory;
        pUser tlv3;
        tlv3 = user;
        newNode = cgc__add_node(tlv7,tlv6,tlv5,tlv4,tlv3);
    }
    newNode->file = newFile;
    return newNode;
}

void fix_ingred_service_12_9_0();
void fix_ingred_service_12_9();
void fix_ingred_service_12();
pFileChunk cgc_delete_chunk(pFile file, pFileChunk chunk)
{
if (fix_ingred_enable){ fix_ingred_service_12(); };
    //return next or NULL;
    pFileChunk retval;
    retval = chunk -> next;
    if (chunk == NULL) {
 {
     char tlv2[] = "delete_chunk called with NULL";
    	cgc_puts(tlv2);
 }
	return NULL;
    }
    if (chunk->prev == NULL) {	//first chunk
	file->head = chunk->next;
	if (chunk->next == NULL) {	//if it is the only element
	    file->tail = NULL;
	    file->chunkCount = 0;
	} else {		//first but not last
	    chunk->next->prev = NULL;
	    file->chunkCount -= 1;
	}
    } else {			//not first chunk
	chunk->prev->next = chunk->next;
	if (chunk->next == NULL) {	//last no next
	    file->tail = NULL;
	} else {		//not last
	    chunk->next->prev = chunk->prev;
	}
	file->chunkCount -= 1;
    }
    {
        void* tlv1;
        tlv1 = chunk -> chunk;
        cgc_free(tlv1);
    }
    cgc_free(chunk);
    return retval;
}

void fix_ingred_service_13();
void cgc_delete_file(pFile file)
{
if (fix_ingred_enable){ fix_ingred_service_13(); };
    pFileChunk tempChunk;
    tempChunk = file -> head;
    while (tempChunk != NULL) {
 {
     pFile tlv2;
     tlv2 = file;
     pFileChunk tlv1;
     tlv1 = tempChunk;
    	tempChunk = cgc_delete_chunk(tlv2,tlv1);
 }
    }
    cgc_free(file);
    return;
}

void fix_ingred_service_14_15_0();
void fix_ingred_service_14_15();
void fix_ingred_service_14();
pNode cgc_delete_node(pNode node, pDataStruct workingData)
{
if (fix_ingred_enable){ fix_ingred_service_14(); };
    pNode retval;
    retval = node -> next;
    //returns pointer to next node or NULL
    if (node == workingData->root) {	//can not delete 'root' directory
 {
     char tlv2[] = "can not delete root directory";
    	cgc_puts(tlv2);
 }
    }
    if (node->type == FILE) {
 pFile tempFile;
 tempFile = node -> file;
	cgc_delete_file(tempFile);
    }
    if (node->type == DIRECTORY) {	//delete all files and subdirs
 pNode tempNode;
 tempNode = node -> directoryHeadNode;
	while (tempNode != NULL) {	//daily dose of recursion
     {
         pNode tlv6;
         tlv6 = tempNode;
         pDataStruct tlv5;
         tlv5 = workingData;
    	    tempNode = cgc_delete_node(tlv6,tlv5);
     }
	}
    }
    if (node->prev == NULL) {	//first
	node->parent->directoryHeadNode = node->next;
	if (node->next == NULL) {	//only
	    node->parent->directoryHeadNode = NULL;
	    node->parent->directoryTailNode = NULL;
	} else {		//first but not only
	    node->next->prev = NULL;
	}
    } else {			//not first
	node->prev->next = node->next;
	if (node->next == NULL) {	//last
	    node->parent->directoryTailNode = node->prev;
	} else {		//not first or last
	    node->next->prev = node->prev;
	}
    }
    pPerms perms;
    perms = node -> perms;
    while (perms != NULL) {
 {
     pNode tlv4;
     tlv4 = node;
     pPerms tlv3;
     tlv3 = perms;
    	perms = cgc_delete_perms(tlv4,tlv3);
 }
    }
    {
        void* tlv1;
        tlv1 = node -> name;
        cgc_free(tlv1);
    }
    cgc_free(node);
    return retval;
}

void fix_ingred_service_15_1_0();
void fix_ingred_service_15_1_1();
void fix_ingred_service_15_1_2();
void fix_ingred_service_15_1();
void fix_ingred_service_15();
pNode cgc_add_directory(unsigned int date, char *name, pNode parent, pUser user)
{
if (fix_ingred_enable){ fix_ingred_service_15(); };
    //add a directory with current user as perm
    pNode newDirectory;
    {
        char tlv5;
        tlv5 = DIRECTORY;
        unsigned int tlv4;
        tlv4 = date;
        char* tlv3;
         tlv3 = name;
        pNode tlv2;
        tlv2 = parent;
        pUser tlv1;
        tlv1 = user;
        newDirectory = cgc__add_node(tlv5,tlv4,tlv3,tlv2,tlv1);
    }
    newDirectory->directoryHeadNode = NULL;
    newDirectory->directoryTailNode = NULL;
    return newDirectory;
}

void fix_ingred_service_16_1_0();
void fix_ingred_service_16_1();
void fix_ingred_service_16_3_0();
void fix_ingred_service_16_3();
void fix_ingred_service_16_4_0();
void fix_ingred_service_16_4_1();
void fix_ingred_service_16_4();
void fix_ingred_service_16();
pUser cgc__add_user(char *name, pUser userList)
{
if (fix_ingred_enable){ fix_ingred_service_16(); };
    //add user to userList, 
    //if userList is NULL, create single element list
    pUser newUser;
    {
        int tlv4;
        tlv4 = sizeof ( sUser );
        char tlv3[] = "Failed to allocate user";
        newUser = cgc_mallocOrDie(tlv4,tlv3);
    }
    char* newName;
     {
         int tlv6;
         {
             const char* tlv7 = name;
             tlv6 = cgc_strlen(tlv7) + 1;
         }
         char tlv5[] = "Failed to allocate username";
         newName = cgc_mallocOrDie(tlv6,tlv5);
     }
    //cgc_printf("_add_user cgc_strlen(name):@d",cgc_strlen( name ));
    {
        char* tlv2;
         tlv2 = newName;
        char* tlv1;
         tlv1 = name;
        cgc_strcpy(tlv2,tlv1);
    }
    newUser->name = newName;
    if (userList == NULL) {
	//not necessary, but looks nice
	newUser->prev = NULL;
	newUser->next = NULL;
	return newUser;
    } else {
 pUser lastUser;
 lastUser = userList;
 pUser tempUser;
 tempUser = userList -> next;
	while (tempUser != NULL) {
	    lastUser = tempUser;
	    tempUser = tempUser->next;
	}
	lastUser->next = newUser;
	newUser->prev = lastUser;
	//unnecessary but looks nice
	newUser->next = NULL;
    }
    return newUser;
}

void fix_ingred_service_17();
pUser cgc_add_user(char *name, pDataStruct workingData)
{
if (fix_ingred_enable){ fix_ingred_service_17(); };
    return cgc__add_user(name, workingData->user);
}

void fix_ingred_service_18();
pGroupUserList cgc_is_user_in_group(pUser user, pGroup group)
{
if (fix_ingred_enable){ fix_ingred_service_18(); };
    //returns pGroupUserList if found, or NULL if not found
    pGroupUserList temp;
    temp = group -> userList;
    while (temp != NULL) {
	if (temp->user == user) {
	    return temp;
	}
	temp = temp->next;
    }
    return NULL;
}

void fix_ingred_service_19();
int cgc_is_user_valid(pUser user, pDataStruct workingData)
{
if (fix_ingred_enable){ fix_ingred_service_19(); };
    //returns 1 if user is valid (in users)
    pUser temp;
    temp = workingData -> user;
    while (temp != NULL) {
	if (temp == user) {
	    return 1;
	}
	temp = temp->next;
    }
    return 0;
}

void fix_ingred_service_20();
int cgc_is_group_valid(pGroup group, pDataStruct workingData)
{
if (fix_ingred_enable){ fix_ingred_service_20(); };
    pGroup temp;
    temp = workingData -> group;
    while (temp != NULL) {
	if (temp == group) {
	    return 1;
	}
	temp = temp->next;
    }
    return 0;
}

void fix_ingred_service_21();
pGroupUserList cgc_remove_user_from_group(pUser user, pGroup group)
{
if (fix_ingred_enable){ fix_ingred_service_21(); };
    //returns prev groupUserList or NULL
    pGroupUserList temp;
    {
        pUser tlv2;
        tlv2 = user;
        pGroup tlv1;
        tlv1 = group;
        temp = cgc_is_user_in_group(tlv2,tlv1);
    }
    pGroupUserList retval;
    retval = NULL;
    if (temp == NULL) {
	return NULL;
    }
    if (temp->prev == NULL) {	//first element
	if (temp->next == NULL) {	//only element
	    group->userList = NULL;
;	//head is NULL
	    group->userCount = 0;
	} else {		//first but not only
	    group->userList = temp->next;
	    temp->next->prev = NULL;
	    group->userCount -= 1;
	}
    } else {			//not first
	if (temp->next == NULL) {	//last
	    temp->prev->next = NULL;
	    group->userCount -= 1;
	} else {		//not first or last
	    temp->prev->next = temp->next;
	    temp->next->prev = temp->prev;
	    group->userCount -= 1;
	}
    }
    retval = temp->prev;
;	//if first, next is null
    cgc_free(temp);
    return retval;
}

void fix_ingred_service_22_9_0();
void fix_ingred_service_22_9();
void fix_ingred_service_22();
pUser cgc_remove_user(pUser user, pDataStruct workingData)
{
if (fix_ingred_enable){ fix_ingred_service_22(); };
    //returns prev or null 
    pGroup groupList;
    groupList = workingData -> group;
    pUser retval;
    retval = NULL;
    pUser last;
    last = NULL;
    if (user == NULL) {
 {
     char tlv2[] = "Bad call:remove_user";
    	cgc_puts(tlv2);
 }
	return NULL;
    }				//bad call to remove user
    if (user->prev == NULL) {
 {
     char tlv3[] = "Can not delete root";
    	cgc_puts(tlv3);
 }
	return NULL;
    }
    if (user == workingData->user) {	//never delete root
	return NULL;
    }
    while (groupList != NULL) {	//remove user from any groups
 {
     pUser tlv5;
     tlv5 = user;
     pGroup tlv4;
     tlv4 = groupList;
    	cgc_remove_user_from_group(tlv5,tlv4);
 }
	groupList = groupList->next;
    }
    user->prev->next = user->next;
    if (user->next != NULL) {	//not last
	user->next->prev = user->prev;
    }
    retval = user->prev;
    {
        void* tlv1;
        tlv1 = user -> name;
        cgc_free(tlv1);
    }
    cgc_free(user);
    return retval;
}

void fix_ingred_service_23_10_0();
void fix_ingred_service_23_10();
void fix_ingred_service_23();
pGroup cgc_remove_group(pGroup group, pDataStruct workingData)
{
if (fix_ingred_enable){ fix_ingred_service_23(); };
    pGroup retval;
    retval = NULL;
    pGroupUserList temp;
    temp = NULL;
    pGroupUserList last;
    last = NULL;
    if (group == NULL) {
 {
     char tlv2[] = "bad call to remove_group";
    	cgc_puts(tlv2);
 }
	return NULL;
    }
    if (group == workingData->group) {
 {
     char tlv3[] = "Unable to delete group root";
    	cgc_puts(tlv3);
 }
	return NULL;
    }
    temp = group->userList;
    last = temp;
    while (temp != NULL) {	//get last user
	last = temp;
	temp = temp->next;
    }
    while (last != NULL) {	//delete all users
 {
     pUser tlv5;
     tlv5 = last -> user;
     pGroup tlv4;
     tlv4 = group;
    	last = cgc_remove_user_from_group(tlv5,tlv4);
 }
    }
    if (group->prev != NULL) {
	group->prev->next = group->next;
    }
    if (group->next != NULL) {	//not last
	group->next->prev = group->prev;
    }
    retval = group->prev;
    {
        void* tlv1;
        tlv1 = group -> name;
        cgc_free(tlv1);
    }
    cgc_free(group);
    return retval;
}

void fix_ingred_service_24_2_1();
void fix_ingred_service_24_2();
void fix_ingred_service_24_3_4();
void fix_ingred_service_24_3_5();
void fix_ingred_service_24_3();
void fix_ingred_service_24();
pUser cgc_find_user_by_name(char *name, pDataStruct workingData)
{
if (fix_ingred_enable){ fix_ingred_service_24(); };
    //returns NULL or first user with name
    pUser retval;
    retval = NULL;
    pUser last;
    last = workingData -> user;
    while (last != NULL) {
 int tlv1;
 {
     char* tlv3;
      tlv3 = name;
     char* tlv2;
      tlv2 = last -> name;
     tlv1 = cgc_strcmp(tlv3,tlv2);
 }
	if (tlv1 == 0) {
	    return last;
	} else {
	    last = last->next;
	}
    }
    return retval;
}

void fix_ingred_service_25_0_2();
void fix_ingred_service_25_0();
void fix_ingred_service_25_2_6();
void fix_ingred_service_25_2();
void fix_ingred_service_25_3_0();
void fix_ingred_service_25_3();
void fix_ingred_service_25();
pUser cgc_find_user_by_number(int number, pDataStruct workingData)
{
if (fix_ingred_enable){ fix_ingred_service_25(); };
    pUser retval;
    retval = NULL;
    pUser last;
    last = workingData -> user;
    int count;
    count = 0;
    while (last != NULL) {
	if (count == number) {
	    return last;
	} else {
	    count += 1;
	    last = last->next;
	}
    }
    return retval;
}

void fix_ingred_service_26_1_0();
void fix_ingred_service_26_1();
void fix_ingred_service_26();
pGroup cgc__add_group(char *name, pGroup group)
{
if (fix_ingred_enable){ fix_ingred_service_26(); };
    //add empty group of users, no users are added, empty group is returned
    //group is dllist of groups to add group to, if null, create and return
    pGroup newGroup;
    {
        int tlv4;
        tlv4 = sizeof ( sGroup );
        char tlv3[] = "Failed to allocate group";
        newGroup = cgc_mallocOrDie(tlv4,tlv3);
    }
    char* newName;
     {
         int tlv6;
         {
             const char* tlv7 = name;
             tlv6 = cgc_strlen(tlv7) + 1;
         }
         char tlv5[] = "Failed to allocate groupName";
         newName = cgc_mallocOrDie(tlv6,tlv5);
     }
    {
        char* tlv2;
         tlv2 = newName;
        char* tlv1;
         tlv1 = name;
        cgc_strcpy(tlv2,tlv1);
    }
    newGroup->name = newName;
    newGroup->userCount = 0;
    newGroup->userList = NULL;
    newGroup->next = NULL;
    if (group == NULL) {
	//used in init state
	group = newGroup;
	return newGroup;
    }
    //walk to the end of grouplist
    pGroup last;
    last = group;
    pGroup temp;
    temp = last;
    while (temp != NULL) {
	last = temp;
	temp = last->next;
    }
    newGroup->prev = last;
    last->next = newGroup;
    return newGroup;
}

void fix_ingred_service_27();
pGroup cgc_add_group(char *name, pDataStruct workingData)
{
if (fix_ingred_enable){ fix_ingred_service_27(); };
    return cgc__add_group(name, workingData->group);
}

void fix_ingred_service_28_1_0();
void fix_ingred_service_28_1();
void fix_ingred_service_28();
pGroupUserList cgc_add_user_to_group(pUser user, pGroup group)
{
if (fix_ingred_enable){ fix_ingred_service_28(); };
    pGroupUserList newGroupUserListNode;
    {
        int tlv2;
        tlv2 = sizeof ( sGroupUserList );
        char tlv1[] = "Failed to allocate newUser";
        newGroupUserListNode = cgc_mallocOrDie(tlv2,tlv1);
    }
    newGroupUserListNode->user = user;
    newGroupUserListNode->next = NULL;
    //if group has no users
    if (group->userList == NULL) {
	group->userList = newGroupUserListNode;
	newGroupUserListNode->prev = NULL;
	group->userCount = 1;
    } else {
 pGroupUserList last;
 last = group -> userList;
 pGroupUserList temp;
 temp = last;
	while (temp != NULL) {
	    last = temp;
	    temp = temp->next;
	}
	last->next = newGroupUserListNode;
	newGroupUserListNode->prev = last;
	group->userCount += 1;
    }
    return newGroupUserListNode;
}

void fix_ingred_service_29();
pGroup cgc_find_group_by_number(int number, pDataStruct workingData)
{
if (fix_ingred_enable){ fix_ingred_service_29(); };
    pGroup retval;
    retval = NULL;
    pGroup last;
    last = workingData -> group;
    int count;
    count = 0;
    while (last != NULL) {
	if (count == number) {
	    retval = last;
	    last = NULL;
	} else {
	    count += 1;
	    last = last->next;
	}
    }
    return retval;
}

void fix_ingred_service_30();
pGroup cgc_find_group_by_name(char *name, pDataStruct workingData)
{
if (fix_ingred_enable){ fix_ingred_service_30(); };
    //returns NULL or first user with name
    pGroup retval;
    retval = NULL;
    if (workingData->group != NULL) {
 pGroup last;
 last = workingData -> group;
	while (last != NULL) {
     int tlv1;
     {
         char* tlv3;
          tlv3 = name;
         char* tlv2;
          tlv2 = last -> name;
         tlv1 = cgc_strcmp(tlv3,tlv2);
     }
	    if (tlv1 == 0) {
		return last;
	    }
	    last = last->next;
	}
    }
    return retval;
}

void fix_ingred_service_31_3_0();
void fix_ingred_service_31_3();
void fix_ingred_service_31_4_0();
void fix_ingred_service_31_4_1();
void fix_ingred_service_31_4();
void fix_ingred_service_31_7_1();
void fix_ingred_service_31_7();
void fix_ingred_service_31_9_0();
void fix_ingred_service_31_9();
void fix_ingred_service_31_10_0();
void fix_ingred_service_31_10();
void fix_ingred_service_31();
char *cgc_recursive_path(pNode start, pNode end)
{
if (fix_ingred_enable){ fix_ingred_service_31(); };
    if (end == start) {
 char* path;
  {
      int tlv14;
      {
          const char* tlv15 = end -> name;
          tlv14 = cgc_strlen(tlv15) + 2;
      }
      char tlv13[] = "Failed to allocate endName";
      path = cgc_mallocOrDie(tlv14,tlv13);
  }
 {
     char* tlv12;
      tlv12 = path;
     char* tlv11;
      tlv11 = end -> name;
    	cgc_strcpy(tlv12,tlv11);
 }
	return path;
    }
    if (end->parent == NULL) {
	return NULL;
    }
    char* path;
     {
         pNode tlv8;
         tlv8 = start;
         pNode tlv7;
         tlv7 = end -> parent;
         path = cgc_recursive_path(tlv8,tlv7);
     }
    if (path == NULL) {
	return NULL;
    }
    char* retpath;
     {
         int tlv10;
         {
             const char* tlv18 = end -> name;
             const char* tlv16 = path;
             tlv10 = ( cgc_strlen(tlv16) + cgc_strlen(tlv18) + 2 );
         }
         char tlv9[] = "Failed to allocate retpath";
         retpath = cgc_mallocOrDie(tlv10,tlv9);
     }
    {
        char* tlv2;
         tlv2 = retpath;
        char* tlv1;
         tlv1 = path;
        cgc_strcpy(tlv2,tlv1);
    }
    {
        char* tlv4;
         tlv4 = retpath;
        char tlv3[] = "/";
        cgc_strcat(tlv4,tlv3);
    }
    {
        char* tlv6;
         tlv6 = retpath;
        char* tlv5;
         tlv5 = end -> name;
        cgc_strcat(tlv6,tlv5);
    }
    cgc_free(path);
    return retpath;
}

void fix_ingred_service_32_2_0();
void fix_ingred_service_32_2_1();
void fix_ingred_service_32_2();
void fix_ingred_service_32();
void cgc_str_of_path(char *path, pDataStruct workingData, pNode end)
{
if (fix_ingred_enable){ fix_ingred_service_32(); };
    char* newPath;
     {
         pNode tlv4;
         tlv4 = workingData -> root;
         pNode tlv3;
         tlv3 = end;
         newPath = cgc_recursive_path(tlv4,tlv3);
     }
    {
        char* tlv2;
         tlv2 = path;
        char* tlv1;
         tlv1 = newPath;
        cgc_strcpy(tlv2,tlv1);
    }
    cgc_free(newPath);
    return;
}

void fix_ingred_service_33_2_1();
void fix_ingred_service_33_2();
void fix_ingred_service_33();
pNode cgc_find_node_by_name(char *name, pNode directoryNode)
{
if (fix_ingred_enable){ fix_ingred_service_33(); };
    pNode temp;
    temp = directoryNode;
    while (temp != NULL) {
 int tlv1;
 {
     char* tlv3;
      tlv3 = name;
     char* tlv2;
      tlv2 = temp -> name;
     tlv1 = cgc_strcmp(tlv3,tlv2);
 }
	if (tlv1 == 0) {
	    return temp;
	}
	temp = temp->next;
    }
    return NULL;
}

void fix_ingred_service_34_1_0();
void fix_ingred_service_34_1();
void fix_ingred_service_34();
pNode cgc_find_directory_by_name(char *name, pNode directory)
{
if (fix_ingred_enable){ fix_ingred_service_34(); };
    pNode temp;
    {
        char* tlv2;
         tlv2 = name;
        pNode tlv1;
        tlv1 = directory -> directoryHeadNode;
        temp = cgc_find_node_by_name(tlv2,tlv1);
    }
    while (temp != NULL) {
	if (temp->type == DIRECTORY) {
	    return temp;
	}
 {
     char* tlv4;
      tlv4 = name;
     pNode tlv3;
     tlv3 = temp -> next;
    	temp = cgc_find_node_by_name(tlv4,tlv3);
 }
    }
    return NULL;
}

void fix_ingred_service_35();
pFile cgc_find_file_by_name(char *name, pNode directory)
{
if (fix_ingred_enable){ fix_ingred_service_35(); };
    pNode temp;
    {
        char* tlv2;
         tlv2 = name;
        pNode tlv1;
        tlv1 = directory -> directoryHeadNode;
        temp = cgc_find_node_by_name(tlv2,tlv1);
    }
    while (temp != NULL) {
	if (temp->type == FILE) {
	    return temp->file;
	}
 {
     char* tlv4;
      tlv4 = name;
     pNode tlv3;
     tlv3 = temp -> next;
    	temp = cgc_find_node_by_name(tlv4,tlv3);
 }
    }
    return NULL;
}

void fix_ingred_service_36();
pNode cgc_find_file_node_by_name(char *name, pNode directory)
{
if (fix_ingred_enable){ fix_ingred_service_36(); };
    pNode temp;
    {
        char* tlv2;
         tlv2 = name;
        pNode tlv1;
        tlv1 = directory -> directoryHeadNode;
        temp = cgc_find_node_by_name(tlv2,tlv1);
    }
    while (temp != NULL) {
	if (temp->type == FILE) {
	    return temp;
	}
 {
     char* tlv4;
      tlv4 = name;
     pNode tlv3;
     tlv3 = temp -> next;
    	temp = cgc_find_node_by_name(tlv4,tlv3);
 }
    }
    return NULL;
}

void fix_ingred_service_37();
int main(int cgc_argc, char *cgc_argv[])
{
if (fix_ingred_enable){ fix_ingred_service_37(); };
    pDataStruct workingData;
    workingData = cgc_init_data ( );
    cgc_start_UI(workingData);
    return 0;
}

void fix_ingred_service_0_1_0(){
    {unsigned int tlv1; tlv1 = (unsigned int)(1); }
}
void fix_ingred_service_0_1(){
fix_ingred_service_0_1_0();
}
void fix_ingred_service_0(){
fix_ingred_service_0_1();
}
void fix_ingred_service_1_1_0(){
int size;
    bzero(&size,sizeof(int));
    {void * retval; retval = (void *)(size); }
    {cgc_size_t tlv3; tlv3 = (cgc_size_t)(size); }
    {void * tlv2; tlv2 = (void *)(size); }
    {cgc_size_t tlv1; tlv1 = (cgc_size_t)(size); }
}
void fix_ingred_service_1_1(){
fix_ingred_service_1_1_0();
}
void fix_ingred_service_1_2_0(){
int retval_ref;
    bzero(&retval_ref,1*sizeof(int));
void * retval = (void*)&retval_ref;
    {cgc_size_t tlv3; tlv3 = (cgc_size_t)(retval); }
    {void * tlv2; tlv2 = (void *)(retval); }
    {cgc_size_t tlv1; tlv1 = (cgc_size_t)(retval); }
}
void fix_ingred_service_1_2_1(){
int retval_ref;
    bzero(&retval_ref,1*sizeof(int));
void * retval = (void*)&retval_ref;
    {void * retval; retval = (void *)(NULL); }
    {cgc_size_t tlv3; tlv3 = (cgc_size_t)(NULL); }
    {void * tlv2; tlv2 = (void *)(NULL); }
    {cgc_size_t tlv1; tlv1 = (cgc_size_t)(NULL); }
}
void fix_ingred_service_1_2(){
fix_ingred_service_1_2_0();
fix_ingred_service_1_2_1();
}
void fix_ingred_service_1(){
fix_ingred_service_1_1();
fix_ingred_service_1_2();
}
void fix_ingred_service_2_1_0(){
    {char * name; name = (char *)(sizeof ( sDataStruct )); }
    {int tlv9; tlv9 = (int)(sizeof ( sDataStruct )); }
    {char* tlv8 ; tlv8  = (char*)(sizeof ( sDataStruct )); }
    {int tlv11; tlv11 = (int)(sizeof ( sDataStruct )); }
    {char* tlv10 ; tlv10  = (char*)(sizeof ( sDataStruct )); }
    {char* tlv13 ; tlv13  = (char*)(sizeof ( sDataStruct )); }
    {char* tlv15 ; tlv15  = (char*)(sizeof ( sDataStruct )); }
    {int tlv20; tlv20 = (int)(sizeof ( sDataStruct )); }
    {char* tlv19 ; tlv19  = (char*)(sizeof ( sDataStruct )); }
    {char * tlv7; tlv7 = (char *)(sizeof ( sDataStruct )); }
    {char* tlv6 ; tlv6  = (char*)(sizeof ( sDataStruct )); }
}
void fix_ingred_service_2_1(){
fix_ingred_service_2_1_0();
}
void fix_ingred_service_2_2_0(){
    {char * name; name = (char *)(sizeof ( sNode )); }
    {int tlv9; tlv9 = (int)(sizeof ( sNode )); }
    {char* tlv8 ; tlv8  = (char*)(sizeof ( sNode )); }
    {int tlv11; tlv11 = (int)(sizeof ( sNode )); }
    {char* tlv10 ; tlv10  = (char*)(sizeof ( sNode )); }
    {char* tlv13 ; tlv13  = (char*)(sizeof ( sNode )); }
    {char* tlv15 ; tlv15  = (char*)(sizeof ( sNode )); }
    {int tlv20; tlv20 = (int)(sizeof ( sNode )); }
    {char* tlv19 ; tlv19  = (char*)(sizeof ( sNode )); }
    {char * tlv7; tlv7 = (char *)(sizeof ( sNode )); }
    {char* tlv6 ; tlv6  = (char*)(sizeof ( sNode )); }
}
void fix_ingred_service_2_2(){
fix_ingred_service_2_2_0();
}
void fix_ingred_service_2_8_0(){
    {char * name; name = (char *)(5); }
    {int tlv9; tlv9 = (int)(5); }
    {char* tlv8 ; tlv8  = (char*)(5); }
    {int tlv11; tlv11 = (int)(5); }
    {char* tlv10 ; tlv10  = (char*)(5); }
    {char* tlv13 ; tlv13  = (char*)(5); }
    {char* tlv15 ; tlv15  = (char*)(5); }
    {int tlv20; tlv20 = (int)(5); }
    {char* tlv19 ; tlv19  = (char*)(5); }
    {char * tlv7; tlv7 = (char *)(5); }
    {char* tlv6 ; tlv6  = (char*)(5); }
}
void fix_ingred_service_2_8(){
fix_ingred_service_2_8_0();
}
void fix_ingred_service_2_9_0(){
char name_ref;
    bzero(&name_ref,1*sizeof(char));
char * name = &name_ref;
    {int tlv9; tlv9 = (int)(name); }
    {char* tlv8 ; tlv8  = (char*)(name); }
    {int tlv11; tlv11 = (int)(name); }
    {char* tlv10 ; tlv10  = (char*)(name); }
    {char* tlv13 ; tlv13  = (char*)(name); }
    {char* tlv15 ; tlv15  = (char*)(name); }
    {int tlv20; tlv20 = (int)(name); }
    {char* tlv19 ; tlv19  = (char*)(name); }
    {char * tlv7; tlv7 = (char *)(name); }
    {char* tlv6 ; tlv6  = (char*)(name); }
}
void fix_ingred_service_2_9(){
fix_ingred_service_2_9_0();
}
void fix_ingred_service_2(){
fix_ingred_service_2_1();
fix_ingred_service_2_2();
fix_ingred_service_2_8();
fix_ingred_service_2_9();
}
void fix_ingred_service_3_4_1(){
char name_ref;
    bzero(&name_ref,1*sizeof(char));
char * name = &name_ref;
    {int tlv1; tlv1 = (int)(name); }
    {int tlv2; tlv2 = (int)(name); }
    {char * tlv6; tlv6 = (char *)(name); }
    {char * tlv5; tlv5 = (char *)(name); }
    {char * tlv8; tlv8 = (char *)(name); }
}
void fix_ingred_service_3_4(){
fix_ingred_service_3_4_1();
}
void fix_ingred_service_3_5_5(){
int tlv1;
    bzero(&tlv1,sizeof(int));
    {int tlv2; tlv2 = (int)(tlv1); }
    {char * tlv6; tlv6 = (char *)(tlv1); }
    {char * tlv5; tlv5 = (char *)(tlv1); }
    {char * tlv8; tlv8 = (char *)(tlv1); }
    {char * tlv7; tlv7 = (char *)(tlv1); }
}
void fix_ingred_service_3_5_6(){
int tlv1;
    bzero(&tlv1,sizeof(int));
    {int tlv1; tlv1 = (int)(0); }
    {int tlv2; tlv2 = (int)(0); }
    {char * tlv6; tlv6 = (char *)(0); }
    {char * tlv5; tlv5 = (char *)(0); }
    {char * tlv8; tlv8 = (char *)(0); }
    {char * tlv7; tlv7 = (char *)(0); }
}
void fix_ingred_service_3_5(){
fix_ingred_service_3_5_5();
fix_ingred_service_3_5_6();
}
void fix_ingred_service_3_8_5(){
int tlv2;
    bzero(&tlv2,sizeof(int));
    {int tlv1; tlv1 = (int)(tlv2); }
    {char * tlv6; tlv6 = (char *)(tlv2); }
    {char * tlv5; tlv5 = (char *)(tlv2); }
    {char * tlv8; tlv8 = (char *)(tlv2); }
    {char * tlv7; tlv7 = (char *)(tlv2); }
}
void fix_ingred_service_3_8(){
fix_ingred_service_3_8_5();
}
void fix_ingred_service_3(){
fix_ingred_service_3_4();
fix_ingred_service_3_5();
fix_ingred_service_3_8();
}
void fix_ingred_service_4_3_0(){
    {int tlv2; tlv2 = (int)(sizeof ( sPerms )); }
    {char* tlv1 ; tlv1  = (char*)(sizeof ( sPerms )); }
    {char* tlv3 ; tlv3  = (char*)(sizeof ( sPerms )); }
}
void fix_ingred_service_4_3(){
fix_ingred_service_4_3_0();
}
void fix_ingred_service_4(){
fix_ingred_service_4_3();
}
void fix_ingred_service_5(){
}
void fix_ingred_service_6(){
}
void fix_ingred_service_7_1_0(){
    {char * newName; newName = (char *)(sizeof ( sNode )); }
    {int tlv4; tlv4 = (int)(sizeof ( sNode )); }
    {char* tlv3 ; tlv3  = (char*)(sizeof ( sNode )); }
    {char * tlv2; tlv2 = (char *)(sizeof ( sNode )); }
    {char * tlv1; tlv1 = (char *)(sizeof ( sNode )); }
}
void fix_ingred_service_7_1(){
fix_ingred_service_7_1_0();
}
void fix_ingred_service_7_4_0(){
char tlv10_ref;
    bzero(&tlv10_ref,1*sizeof(char));
const char * tlv10 = &tlv10_ref;
    {char * newName; newName = (char *)(cgc_strlen ( tlv10 ) + 1); }
    {int tlv4; tlv4 = (int)(cgc_strlen ( tlv10 ) + 1); }
    {char* tlv3 ; tlv3  = (char*)(cgc_strlen ( tlv10 ) + 1); }
    {int tlv9; tlv9 = (int)(cgc_strlen ( tlv10 ) + 1); }
    {char* tlv8 ; tlv8  = (char*)(cgc_strlen ( tlv10 ) + 1); }
    {char * tlv2; tlv2 = (char *)(cgc_strlen ( tlv10 ) + 1); }
    {char * tlv1; tlv1 = (char *)(cgc_strlen ( tlv10 ) + 1); }
}
void fix_ingred_service_7_4(){
fix_ingred_service_7_4_0();
}
void fix_ingred_service_7_5_0(){
char newName_ref;
    bzero(&newName_ref,1*sizeof(char));
char * newName = &newName_ref;
char name_ref;
    bzero(&name_ref,1*sizeof(char));
char * name = &name_ref;
    {int tlv4; tlv4 = (int)(newName); }
    {char* tlv3 ; tlv3  = (char*)(newName); }
    {int tlv9; tlv9 = (int)(newName); }
    {char* tlv8 ; tlv8  = (char*)(newName); }
    {char * tlv2; tlv2 = (char *)(newName); }
    {char * tlv1; tlv1 = (char *)(newName); }
}
void fix_ingred_service_7_5_1(){
char newName_ref;
    bzero(&newName_ref,1*sizeof(char));
char * newName = &newName_ref;
char name_ref;
    bzero(&name_ref,1*sizeof(char));
char * name = &name_ref;
    {char * newName; newName = (char *)(name); }
    {int tlv4; tlv4 = (int)(name); }
    {char* tlv3 ; tlv3  = (char*)(name); }
    {char * tlv2; tlv2 = (char *)(name); }
    {char * tlv1; tlv1 = (char *)(name); }
}
void fix_ingred_service_7_5(){
fix_ingred_service_7_5_0();
fix_ingred_service_7_5_1();
}
void fix_ingred_service_7(){
fix_ingred_service_7_1();
fix_ingred_service_7_4();
fix_ingred_service_7_5();
}
void fix_ingred_service_8_0_1(){
    {unsigned int size; size = (unsigned int)(0); }
}
void fix_ingred_service_8_0(){
fix_ingred_service_8_0_1();
}
void fix_ingred_service_8_1_0(){
sFileChunk temp_ref;
    bzero(&temp_ref,1*sizeof(sFileChunk));
pFileChunk temp = &temp_ref;
    {unsigned int size; size = (unsigned int)(temp -> chunkSize); }
}
void fix_ingred_service_8_1(){
fix_ingred_service_8_1_0();
}
void fix_ingred_service_8(){
fix_ingred_service_8_0();
fix_ingred_service_8_1();
}
void fix_ingred_service_9_0_2(){
    {unsigned int remainderbytes; remainderbytes = (unsigned int)(0); }
    {int flag; flag = (int)(0); }
    {char * newChunk; newChunk = (char *)(0); }
    {int tlv6; tlv6 = (int)(0); }
    {char* tlv5 ; tlv5  = (char*)(0); }
    {void * tlv3; tlv3 = (void *)(0); }
    {void * tlv2; tlv2 = (void *)(0); }
    {cgc_size_t tlv1; tlv1 = (cgc_size_t)(0); }
    {void * tlv4; tlv4 = (void *)(0); }
}
void fix_ingred_service_9_0_4(){
    {unsigned int remainderbytes; remainderbytes = (unsigned int)(0); }
    {unsigned int size; size = (unsigned int)(0); }
    {int flag; flag = (int)(0); }
    {char * newChunk; newChunk = (char *)(0); }
    {int tlv6; tlv6 = (int)(0); }
    {char* tlv5 ; tlv5  = (char*)(0); }
    {void * tlv3; tlv3 = (void *)(0); }
    {void * tlv2; tlv2 = (void *)(0); }
    {cgc_size_t tlv1; tlv1 = (cgc_size_t)(0); }
    {void * tlv4; tlv4 = (void *)(0); }
}
void fix_ingred_service_9_0(){
fix_ingred_service_9_0_2();
fix_ingred_service_9_0_4();
}
void fix_ingred_service_9_1_0(){
sFileChunk temp_ref;
    bzero(&temp_ref,1*sizeof(sFileChunk));
pFileChunk temp = &temp_ref;
    {unsigned int remainderbytes; remainderbytes = (unsigned int)(temp -> chunkSize); }
    {int flag; flag = (int)(temp -> chunkSize); }
    {char * newChunk; newChunk = (char *)(temp -> chunkSize); }
    {int tlv6; tlv6 = (int)(temp -> chunkSize); }
    {char* tlv5 ; tlv5  = (char*)(temp -> chunkSize); }
    {void * tlv3; tlv3 = (void *)(temp -> chunkSize); }
    {void * tlv2; tlv2 = (void *)(temp -> chunkSize); }
    {cgc_size_t tlv1; tlv1 = (cgc_size_t)(temp -> chunkSize); }
    {void * tlv4; tlv4 = (void *)(temp -> chunkSize); }
}
void fix_ingred_service_9_1(){
fix_ingred_service_9_1_0();
}
void fix_ingred_service_9_2_8(){
int flag;
    bzero(&flag,sizeof(int));
    {unsigned int remainderbytes; remainderbytes = (unsigned int)(flag); }
    {unsigned int size; size = (unsigned int)(flag); }
    {char * newChunk; newChunk = (char *)(flag); }
    {int tlv6; tlv6 = (int)(flag); }
    {char* tlv5 ; tlv5  = (char*)(flag); }
    {void * tlv3; tlv3 = (void *)(flag); }
    {void * tlv2; tlv2 = (void *)(flag); }
    {cgc_size_t tlv1; tlv1 = (cgc_size_t)(flag); }
    {void * tlv4; tlv4 = (void *)(flag); }
}
void fix_ingred_service_9_2_9(){
int flag;
    bzero(&flag,sizeof(int));
    {unsigned int remainderbytes; remainderbytes = (unsigned int)(1); }
    {unsigned int size; size = (unsigned int)(1); }
    {int flag; flag = (int)(1); }
    {char * newChunk; newChunk = (char *)(1); }
    {int tlv6; tlv6 = (int)(1); }
    {char* tlv5 ; tlv5  = (char*)(1); }
    {void * tlv3; tlv3 = (void *)(1); }
    {void * tlv2; tlv2 = (void *)(1); }
    {cgc_size_t tlv1; tlv1 = (cgc_size_t)(1); }
    {void * tlv4; tlv4 = (void *)(1); }
}
void fix_ingred_service_9_2(){
fix_ingred_service_9_2_8();
fix_ingred_service_9_2_9();
}
void fix_ingred_service_9_5_2(){
unsigned int size;
    bzero(&size,sizeof(unsigned int));
unsigned int newSize;
    bzero(&newSize,sizeof(unsigned int));
    {unsigned int remainderbytes; remainderbytes = (unsigned int)(size - newSize); }
    {int flag; flag = (int)(size - newSize); }
    {char * newChunk; newChunk = (char *)(size - newSize); }
    {int tlv6; tlv6 = (int)(size - newSize); }
    {char* tlv5 ; tlv5  = (char*)(size - newSize); }
    {void * tlv3; tlv3 = (void *)(size - newSize); }
    {void * tlv2; tlv2 = (void *)(size - newSize); }
    {cgc_size_t tlv1; tlv1 = (cgc_size_t)(size - newSize); }
    {void * tlv4; tlv4 = (void *)(size - newSize); }
}
void fix_ingred_service_9_5_11(){
unsigned int size;
    bzero(&size,sizeof(unsigned int));
unsigned int newSize;
    bzero(&newSize,sizeof(unsigned int));
    {unsigned int remainderbytes; remainderbytes = (unsigned int)(size); }
    {int flag; flag = (int)(size); }
    {char * newChunk; newChunk = (char *)(size); }
    {int tlv6; tlv6 = (int)(size); }
    {char* tlv5 ; tlv5  = (char*)(size); }
    {void * tlv3; tlv3 = (void *)(size); }
    {void * tlv2; tlv2 = (void *)(size); }
    {cgc_size_t tlv1; tlv1 = (cgc_size_t)(size); }
    {void * tlv4; tlv4 = (void *)(size); }
}
void fix_ingred_service_9_5_12(){
unsigned int size;
    bzero(&size,sizeof(unsigned int));
unsigned int newSize;
    bzero(&newSize,sizeof(unsigned int));
    {unsigned int remainderbytes; remainderbytes = (unsigned int)(newSize); }
    {unsigned int size; size = (unsigned int)(newSize); }
    {int flag; flag = (int)(newSize); }
    {char * newChunk; newChunk = (char *)(newSize); }
    {int tlv6; tlv6 = (int)(newSize); }
    {char* tlv5 ; tlv5  = (char*)(newSize); }
    {void * tlv3; tlv3 = (void *)(newSize); }
    {void * tlv2; tlv2 = (void *)(newSize); }
    {cgc_size_t tlv1; tlv1 = (cgc_size_t)(newSize); }
    {void * tlv4; tlv4 = (void *)(newSize); }
}
void fix_ingred_service_9_5(){
fix_ingred_service_9_5_2();
fix_ingred_service_9_5_11();
fix_ingred_service_9_5_12();
}
void fix_ingred_service_9_6_0(){
unsigned int size;
    bzero(&size,sizeof(unsigned int));
    {unsigned int remainderbytes; remainderbytes = (unsigned int)(size); }
    {int flag; flag = (int)(size); }
    {char * newChunk; newChunk = (char *)(size); }
    {int tlv6; tlv6 = (int)(size); }
    {char* tlv5 ; tlv5  = (char*)(size); }
    {void * tlv3; tlv3 = (void *)(size); }
    {void * tlv2; tlv2 = (void *)(size); }
    {cgc_size_t tlv1; tlv1 = (cgc_size_t)(size); }
    {void * tlv4; tlv4 = (void *)(size); }
}
void fix_ingred_service_9_6(){
fix_ingred_service_9_6_0();
}
void fix_ingred_service_9_7_0(){
char newChunk_ref;
    bzero(&newChunk_ref,1*sizeof(char));
char * newChunk = &newChunk_ref;
sFileChunk last_ref;
    bzero(&last_ref,1*sizeof(sFileChunk));
pFileChunk last = &last_ref;
unsigned int size;
    bzero(&size,sizeof(unsigned int));
    {unsigned int remainderbytes; remainderbytes = (unsigned int)(newChunk); }
    {unsigned int size; size = (unsigned int)(newChunk); }
    {int flag; flag = (int)(newChunk); }
    {int tlv6; tlv6 = (int)(newChunk); }
    {char* tlv5 ; tlv5  = (char*)(newChunk); }
    {void * tlv3; tlv3 = (void *)(newChunk); }
    {void * tlv2; tlv2 = (void *)(newChunk); }
    {cgc_size_t tlv1; tlv1 = (cgc_size_t)(newChunk); }
    {void * tlv4; tlv4 = (void *)(newChunk); }
}
void fix_ingred_service_9_7_1(){
char newChunk_ref;
    bzero(&newChunk_ref,1*sizeof(char));
char * newChunk = &newChunk_ref;
sFileChunk last_ref;
    bzero(&last_ref,1*sizeof(sFileChunk));
pFileChunk last = &last_ref;
unsigned int size;
    bzero(&size,sizeof(unsigned int));
    {unsigned int remainderbytes; remainderbytes = (unsigned int)(last -> chunk); }
    {unsigned int size; size = (unsigned int)(last -> chunk); }
    {int flag; flag = (int)(last -> chunk); }
    {char * newChunk; newChunk = (char *)(last -> chunk); }
    {int tlv6; tlv6 = (int)(last -> chunk); }
    {char* tlv5 ; tlv5  = (char*)(last -> chunk); }
    {void * tlv3; tlv3 = (void *)(last -> chunk); }
    {void * tlv2; tlv2 = (void *)(last -> chunk); }
    {cgc_size_t tlv1; tlv1 = (cgc_size_t)(last -> chunk); }
    {void * tlv4; tlv4 = (void *)(last -> chunk); }
}
void fix_ingred_service_9_7_2(){
char newChunk_ref;
    bzero(&newChunk_ref,1*sizeof(char));
char * newChunk = &newChunk_ref;
sFileChunk last_ref;
    bzero(&last_ref,1*sizeof(sFileChunk));
pFileChunk last = &last_ref;
unsigned int size;
    bzero(&size,sizeof(unsigned int));
    {unsigned int remainderbytes; remainderbytes = (unsigned int)(size); }
    {int flag; flag = (int)(size); }
    {char * newChunk; newChunk = (char *)(size); }
    {int tlv6; tlv6 = (int)(size); }
    {char* tlv5 ; tlv5  = (char*)(size); }
    {void * tlv3; tlv3 = (void *)(size); }
    {void * tlv4; tlv4 = (void *)(size); }
}
void fix_ingred_service_9_7(){
fix_ingred_service_9_7_0();
fix_ingred_service_9_7_1();
fix_ingred_service_9_7_2();
}
void fix_ingred_service_9(){
fix_ingred_service_9_0();
fix_ingred_service_9_1();
fix_ingred_service_9_2();
fix_ingred_service_9_5();
fix_ingred_service_9_6();
fix_ingred_service_9_7();
}
void fix_ingred_service_10_1_0(){
    {int tlv5; tlv5 = (int)(sizeof ( sFileChunk )); }
    {char* tlv4 ; tlv4  = (char*)(sizeof ( sFileChunk )); }
    {int tlv7; tlv7 = (int)(sizeof ( sFileChunk )); }
    {char* tlv6 ; tlv6  = (char*)(sizeof ( sFileChunk )); }
    {void * tlv3; tlv3 = (void *)(sizeof ( sFileChunk )); }
    {void * tlv2; tlv2 = (void *)(sizeof ( sFileChunk )); }
    {cgc_size_t tlv1; tlv1 = (cgc_size_t)(sizeof ( sFileChunk )); }
}
void fix_ingred_service_10_1(){
fix_ingred_service_10_1_0();
}
void fix_ingred_service_10_2_0(){
unsigned int size;
    bzero(&size,sizeof(unsigned int));
    {int tlv5; tlv5 = (int)(size); }
    {char* tlv4 ; tlv4  = (char*)(size); }
    {int tlv7; tlv7 = (int)(size); }
    {char* tlv6 ; tlv6  = (char*)(size); }
}
void fix_ingred_service_10_2(){
fix_ingred_service_10_2_0();
}
void fix_ingred_service_10_3_0(){
sFileChunk newFileChunk_ref;
    bzero(&newFileChunk_ref,1*sizeof(sFileChunk));
pFileChunk newFileChunk = &newFileChunk_ref;
char data_ref;
    bzero(&data_ref,1*sizeof(char));
char * data = &data_ref;
unsigned int size;
    bzero(&size,sizeof(unsigned int));
    {int tlv5; tlv5 = (int)(newFileChunk -> chunk); }
    {char* tlv4 ; tlv4  = (char*)(newFileChunk -> chunk); }
    {int tlv7; tlv7 = (int)(newFileChunk -> chunk); }
    {char* tlv6 ; tlv6  = (char*)(newFileChunk -> chunk); }
    {void * tlv3; tlv3 = (void *)(newFileChunk -> chunk); }
    {void * tlv2; tlv2 = (void *)(newFileChunk -> chunk); }
    {cgc_size_t tlv1; tlv1 = (cgc_size_t)(newFileChunk -> chunk); }
}
void fix_ingred_service_10_3_1(){
sFileChunk newFileChunk_ref;
    bzero(&newFileChunk_ref,1*sizeof(sFileChunk));
pFileChunk newFileChunk = &newFileChunk_ref;
char data_ref;
    bzero(&data_ref,1*sizeof(char));
char * data = &data_ref;
unsigned int size;
    bzero(&size,sizeof(unsigned int));
    {int tlv5; tlv5 = (int)(data); }
    {char* tlv4 ; tlv4  = (char*)(data); }
    {int tlv7; tlv7 = (int)(data); }
    {char* tlv6 ; tlv6  = (char*)(data); }
    {void * tlv3; tlv3 = (void *)(data); }
    {void * tlv2; tlv2 = (void *)(data); }
    {cgc_size_t tlv1; tlv1 = (cgc_size_t)(data); }
}
void fix_ingred_service_10_3_2(){
sFileChunk newFileChunk_ref;
    bzero(&newFileChunk_ref,1*sizeof(sFileChunk));
pFileChunk newFileChunk = &newFileChunk_ref;
char data_ref;
    bzero(&data_ref,1*sizeof(char));
char * data = &data_ref;
unsigned int size;
    bzero(&size,sizeof(unsigned int));
    {int tlv5; tlv5 = (int)(size); }
    {char* tlv4 ; tlv4  = (char*)(size); }
    {int tlv7; tlv7 = (int)(size); }
    {char* tlv6 ; tlv6  = (char*)(size); }
}
void fix_ingred_service_10_3(){
fix_ingred_service_10_3_0();
fix_ingred_service_10_3_1();
fix_ingred_service_10_3_2();
}
void fix_ingred_service_10(){
fix_ingred_service_10_1();
fix_ingred_service_10_2();
fix_ingred_service_10_3();
}
void fix_ingred_service_11_1_0(){
    {int tlv2; tlv2 = (int)(sizeof ( sFile )); }
    {char* tlv1 ; tlv1  = (char*)(sizeof ( sFile )); }
    {char tlv7; tlv7 = (char)(sizeof ( sFile )); }
    {unsigned int tlv6; tlv6 = (unsigned int)(sizeof ( sFile )); }
    {char * tlv5; tlv5 = (char *)(sizeof ( sFile )); }
    {char * tlv10; tlv10 = (char *)(sizeof ( sFile )); }
    {unsigned int tlv8; tlv8 = (unsigned int)(sizeof ( sFile )); }
}
void fix_ingred_service_11_1(){
fix_ingred_service_11_1_0();
}
void fix_ingred_service_11_2_0(){
unsigned int size;
    bzero(&size,sizeof(unsigned int));
    {int tlv2; tlv2 = (int)(size); }
    {char* tlv1 ; tlv1  = (char*)(size); }
    {char tlv7; tlv7 = (char)(size); }
    {unsigned int tlv6; tlv6 = (unsigned int)(size); }
    {char * tlv5; tlv5 = (char *)(size); }
    {char * tlv10; tlv10 = (char *)(size); }
    {unsigned int tlv8; tlv8 = (unsigned int)(size); }
}
void fix_ingred_service_11_2_1(){
unsigned int size;
    bzero(&size,sizeof(unsigned int));
    {int tlv2; tlv2 = (int)(0); }
    {char* tlv1 ; tlv1  = (char*)(0); }
    {char tlv7; tlv7 = (char)(0); }
    {unsigned int tlv6; tlv6 = (unsigned int)(0); }
    {char * tlv5; tlv5 = (char *)(0); }
    {char * tlv10; tlv10 = (char *)(0); }
    {unsigned int tlv8; tlv8 = (unsigned int)(0); }
}
void fix_ingred_service_11_2(){
fix_ingred_service_11_2_0();
fix_ingred_service_11_2_1();
}
void fix_ingred_service_11_3_0(){
char data_ref;
    bzero(&data_ref,1*sizeof(char));
char * data = &data_ref;
    {int tlv2; tlv2 = (int)(data); }
    {char* tlv1 ; tlv1  = (char*)(data); }
    {char tlv7; tlv7 = (char)(data); }
    {unsigned int tlv6; tlv6 = (unsigned int)(data); }
    {char * tlv5; tlv5 = (char *)(data); }
    {char * tlv10; tlv10 = (char *)(data); }
    {unsigned int tlv8; tlv8 = (unsigned int)(data); }
}
void fix_ingred_service_11_3(){
fix_ingred_service_11_3_0();
}
void fix_ingred_service_11_4_0(){
unsigned int date;
    bzero(&date,sizeof(unsigned int));
char name_ref;
    bzero(&name_ref,1*sizeof(char));
char * name = &name_ref;
    {int tlv2; tlv2 = (int)(FILE); }
    {char* tlv1 ; tlv1  = (char*)(FILE); }
    {char tlv7; tlv7 = (char)(FILE); }
    {unsigned int tlv6; tlv6 = (unsigned int)(FILE); }
    {char * tlv5; tlv5 = (char *)(FILE); }
    {char * tlv10; tlv10 = (char *)(FILE); }
    {unsigned int tlv8; tlv8 = (unsigned int)(FILE); }
}
void fix_ingred_service_11_4_1(){
unsigned int date;
    bzero(&date,sizeof(unsigned int));
char name_ref;
    bzero(&name_ref,1*sizeof(char));
char * name = &name_ref;
    {int tlv2; tlv2 = (int)(date); }
    {char* tlv1 ; tlv1  = (char*)(date); }
    {char tlv7; tlv7 = (char)(date); }
    {unsigned int tlv6; tlv6 = (unsigned int)(date); }
    {char * tlv5; tlv5 = (char *)(date); }
    {char * tlv10; tlv10 = (char *)(date); }
    {unsigned int tlv8; tlv8 = (unsigned int)(date); }
}
void fix_ingred_service_11_4_2(){
unsigned int date;
    bzero(&date,sizeof(unsigned int));
char name_ref;
    bzero(&name_ref,1*sizeof(char));
char * name = &name_ref;
    {char* tlv1 ; tlv1  = (char*)(name); }
    {char tlv7; tlv7 = (char)(name); }
    {unsigned int tlv6; tlv6 = (unsigned int)(name); }
    {char * tlv10; tlv10 = (char *)(name); }
    {unsigned int tlv8; tlv8 = (unsigned int)(name); }
}
void fix_ingred_service_11_4(){
fix_ingred_service_11_4_0();
fix_ingred_service_11_4_1();
fix_ingred_service_11_4_2();
}
void fix_ingred_service_11(){
fix_ingred_service_11_1();
fix_ingred_service_11_2();
fix_ingred_service_11_3();
fix_ingred_service_11_4();
}
void fix_ingred_service_12_9_0(){
sFileChunk chunk_ref;
    bzero(&chunk_ref,1*sizeof(sFileChunk));
pFileChunk chunk = &chunk_ref;
    {void * tlv1; tlv1 = (void *)(chunk -> chunk); }
    {char* tlv2 ; tlv2  = (char*)(chunk -> chunk); }
}
void fix_ingred_service_12_9(){
fix_ingred_service_12_9_0();
}
void fix_ingred_service_12(){
fix_ingred_service_12_9();
}
void fix_ingred_service_13(){
}
void fix_ingred_service_14_15_0(){
sNode node_ref;
    bzero(&node_ref,1*sizeof(sNode));
pNode node = &node_ref;
    {void * tlv1; tlv1 = (void *)(node -> name); }
    {char* tlv2 ; tlv2  = (char*)(node -> name); }
}
void fix_ingred_service_14_15(){
fix_ingred_service_14_15_0();
}
void fix_ingred_service_14(){
fix_ingred_service_14_15();
}
void fix_ingred_service_15_1_0(){
unsigned int date;
    bzero(&date,sizeof(unsigned int));
char name_ref;
    bzero(&name_ref,1*sizeof(char));
char * name = &name_ref;
    {char tlv5; tlv5 = (char)(DIRECTORY); }
    {unsigned int tlv4; tlv4 = (unsigned int)(DIRECTORY); }
    {char * tlv3; tlv3 = (char *)(DIRECTORY); }
}
void fix_ingred_service_15_1_1(){
unsigned int date;
    bzero(&date,sizeof(unsigned int));
char name_ref;
    bzero(&name_ref,1*sizeof(char));
char * name = &name_ref;
    {char tlv5; tlv5 = (char)(date); }
    {unsigned int tlv4; tlv4 = (unsigned int)(date); }
    {char * tlv3; tlv3 = (char *)(date); }
}
void fix_ingred_service_15_1_2(){
unsigned int date;
    bzero(&date,sizeof(unsigned int));
char name_ref;
    bzero(&name_ref,1*sizeof(char));
char * name = &name_ref;
    {char tlv5; tlv5 = (char)(name); }
    {unsigned int tlv4; tlv4 = (unsigned int)(name); }
    {char * tlv3; tlv3 = (char *)(name); }
}
void fix_ingred_service_15_1(){
fix_ingred_service_15_1_0();
fix_ingred_service_15_1_1();
fix_ingred_service_15_1_2();
}
void fix_ingred_service_15(){
fix_ingred_service_15_1();
}
void fix_ingred_service_16_1_0(){
    {char * newName; newName = (char *)(sizeof ( sUser )); }
    {int tlv4; tlv4 = (int)(sizeof ( sUser )); }
    {char* tlv3 ; tlv3  = (char*)(sizeof ( sUser )); }
    {int tlv6; tlv6 = (int)(sizeof ( sUser )); }
    {char* tlv5 ; tlv5  = (char*)(sizeof ( sUser )); }
    {char * tlv2; tlv2 = (char *)(sizeof ( sUser )); }
    {char * tlv1; tlv1 = (char *)(sizeof ( sUser )); }
}
void fix_ingred_service_16_1(){
fix_ingred_service_16_1_0();
}
void fix_ingred_service_16_3_0(){
char tlv7_ref;
    bzero(&tlv7_ref,1*sizeof(char));
const char * tlv7 = &tlv7_ref;
    {char * newName; newName = (char *)(cgc_strlen ( tlv7 ) + 1); }
    {int tlv4; tlv4 = (int)(cgc_strlen ( tlv7 ) + 1); }
    {char* tlv3 ; tlv3  = (char*)(cgc_strlen ( tlv7 ) + 1); }
    {int tlv6; tlv6 = (int)(cgc_strlen ( tlv7 ) + 1); }
    {char* tlv5 ; tlv5  = (char*)(cgc_strlen ( tlv7 ) + 1); }
    {char * tlv2; tlv2 = (char *)(cgc_strlen ( tlv7 ) + 1); }
    {char * tlv1; tlv1 = (char *)(cgc_strlen ( tlv7 ) + 1); }
}
void fix_ingred_service_16_3(){
fix_ingred_service_16_3_0();
}
void fix_ingred_service_16_4_0(){
char newName_ref;
    bzero(&newName_ref,1*sizeof(char));
char * newName = &newName_ref;
char name_ref;
    bzero(&name_ref,1*sizeof(char));
char * name = &name_ref;
    {int tlv6; tlv6 = (int)(newName); }
    {char* tlv5 ; tlv5  = (char*)(newName); }
}
void fix_ingred_service_16_4_1(){
char newName_ref;
    bzero(&newName_ref,1*sizeof(char));
char * newName = &newName_ref;
char name_ref;
    bzero(&name_ref,1*sizeof(char));
char * name = &name_ref;
    {int tlv6; tlv6 = (int)(name); }
    {char* tlv5 ; tlv5  = (char*)(name); }
}
void fix_ingred_service_16_4(){
fix_ingred_service_16_4_0();
fix_ingred_service_16_4_1();
}
void fix_ingred_service_16(){
fix_ingred_service_16_1();
fix_ingred_service_16_3();
fix_ingred_service_16_4();
}
void fix_ingred_service_17(){
}
void fix_ingred_service_18(){
}
void fix_ingred_service_19(){
}
void fix_ingred_service_20(){
}
void fix_ingred_service_21(){
}
void fix_ingred_service_22_9_0(){
sUser user_ref;
    bzero(&user_ref,1*sizeof(sUser));
pUser user = &user_ref;
    {void * tlv1; tlv1 = (void *)(user -> name); }
    {char* tlv2 ; tlv2  = (char*)(user -> name); }
    {char* tlv3 ; tlv3  = (char*)(user -> name); }
}
void fix_ingred_service_22_9(){
fix_ingred_service_22_9_0();
}
void fix_ingred_service_22(){
fix_ingred_service_22_9();
}
void fix_ingred_service_23_10_0(){
sGroup group_ref;
    bzero(&group_ref,1*sizeof(sGroup));
pGroup group = &group_ref;
    {void * tlv1; tlv1 = (void *)(group -> name); }
    {char* tlv2 ; tlv2  = (char*)(group -> name); }
    {char* tlv3 ; tlv3  = (char*)(group -> name); }
}
void fix_ingred_service_23_10(){
fix_ingred_service_23_10_0();
}
void fix_ingred_service_23(){
fix_ingred_service_23_10();
}
void fix_ingred_service_24_2_1(){
sUser last_ref;
    bzero(&last_ref,1*sizeof(sUser));
pUser last = &last_ref;
char name_ref;
    bzero(&name_ref,1*sizeof(char));
char * name = &name_ref;
    {int tlv1; tlv1 = (int)(last -> name); }
    {char * tlv3; tlv3 = (char *)(last -> name); }
    {char * tlv2; tlv2 = (char *)(last -> name); }
}
void fix_ingred_service_24_2(){
fix_ingred_service_24_2_1();
}
void fix_ingred_service_24_3_4(){
int tlv1;
    bzero(&tlv1,sizeof(int));
    {char * tlv3; tlv3 = (char *)(tlv1); }
    {char * tlv2; tlv2 = (char *)(tlv1); }
}
void fix_ingred_service_24_3_5(){
int tlv1;
    bzero(&tlv1,sizeof(int));
    {char * tlv3; tlv3 = (char *)(0); }
    {char * tlv2; tlv2 = (char *)(0); }
}
void fix_ingred_service_24_3(){
fix_ingred_service_24_3_4();
fix_ingred_service_24_3_5();
}
void fix_ingred_service_24(){
fix_ingred_service_24_2();
fix_ingred_service_24_3();
}
void fix_ingred_service_25_0_2(){
    {int count; count = (int)(0); }
}
void fix_ingred_service_25_0(){
fix_ingred_service_25_0_2();
}
void fix_ingred_service_25_2_6(){
int count;
    bzero(&count,sizeof(int));
int number;
    bzero(&number,sizeof(int));
    {int count; count = (int)(number); }
}
void fix_ingred_service_25_2(){
fix_ingred_service_25_2_6();
}
void fix_ingred_service_25_3_0(){
    {int count; count = (int)(1); }
}
void fix_ingred_service_25_3(){
fix_ingred_service_25_3_0();
}
void fix_ingred_service_25(){
fix_ingred_service_25_0();
fix_ingred_service_25_2();
fix_ingred_service_25_3();
}
void fix_ingred_service_26_1_0(){
    {char * newName; newName = (char *)(sizeof ( sGroup )); }
    {int tlv4; tlv4 = (int)(sizeof ( sGroup )); }
    {char* tlv3 ; tlv3  = (char*)(sizeof ( sGroup )); }
    {int tlv6; tlv6 = (int)(sizeof ( sGroup )); }
    {char* tlv5 ; tlv5  = (char*)(sizeof ( sGroup )); }
    {char * tlv2; tlv2 = (char *)(sizeof ( sGroup )); }
    {char * tlv1; tlv1 = (char *)(sizeof ( sGroup )); }
}
void fix_ingred_service_26_1(){
fix_ingred_service_26_1_0();
}
void fix_ingred_service_26(){
fix_ingred_service_26_1();
}
void fix_ingred_service_27(){
}
void fix_ingred_service_28_1_0(){
    {int tlv2; tlv2 = (int)(sizeof ( sGroupUserList )); }
    {char* tlv1 ; tlv1  = (char*)(sizeof ( sGroupUserList )); }
}
void fix_ingred_service_28_1(){
fix_ingred_service_28_1_0();
}
void fix_ingred_service_28(){
fix_ingred_service_28_1();
}
void fix_ingred_service_29(){
}
void fix_ingred_service_30(){
}
void fix_ingred_service_31_3_0(){
char tlv15_ref;
    bzero(&tlv15_ref,1*sizeof(char));
const char * tlv15 = &tlv15_ref;
    {char * path; path = (char *)(cgc_strlen ( tlv15 ) + 2); }
    {char * retpath; retpath = (char *)(cgc_strlen ( tlv15 ) + 2); }
    {int tlv10; tlv10 = (int)(cgc_strlen ( tlv15 ) + 2); }
    {char* tlv9 ; tlv9  = (char*)(cgc_strlen ( tlv15 ) + 2); }
    {char * tlv2; tlv2 = (char *)(cgc_strlen ( tlv15 ) + 2); }
    {char * tlv1; tlv1 = (char *)(cgc_strlen ( tlv15 ) + 2); }
    {char * tlv4; tlv4 = (char *)(cgc_strlen ( tlv15 ) + 2); }
    {char* tlv3 ; tlv3  = (char*)(cgc_strlen ( tlv15 ) + 2); }
    {char * tlv6; tlv6 = (char *)(cgc_strlen ( tlv15 ) + 2); }
    {char * tlv5; tlv5 = (char *)(cgc_strlen ( tlv15 ) + 2); }
    {int tlv14; tlv14 = (int)(cgc_strlen ( tlv15 ) + 2); }
    {char* tlv13 ; tlv13  = (char*)(cgc_strlen ( tlv15 ) + 2); }
    {char * tlv12; tlv12 = (char *)(cgc_strlen ( tlv15 ) + 2); }
    {char * tlv11; tlv11 = (char *)(cgc_strlen ( tlv15 ) + 2); }
}
void fix_ingred_service_31_3(){
fix_ingred_service_31_3_0();
}
void fix_ingred_service_31_4_0(){
char path_ref;
    bzero(&path_ref,1*sizeof(char));
char * path = &path_ref;
sNode end_ref;
    bzero(&end_ref,1*sizeof(sNode));
pNode end = &end_ref;
    {char * retpath; retpath = (char *)(path); }
    {int tlv10; tlv10 = (int)(path); }
    {char* tlv9 ; tlv9  = (char*)(path); }
    {char * tlv2; tlv2 = (char *)(path); }
    {char * tlv1; tlv1 = (char *)(path); }
    {char * tlv4; tlv4 = (char *)(path); }
    {char* tlv3 ; tlv3  = (char*)(path); }
    {char * tlv6; tlv6 = (char *)(path); }
    {char * tlv5; tlv5 = (char *)(path); }
    {int tlv14; tlv14 = (int)(path); }
    {char* tlv13 ; tlv13  = (char*)(path); }
    {char * tlv12; tlv12 = (char *)(path); }
    {char * tlv11; tlv11 = (char *)(path); }
}
void fix_ingred_service_31_4_1(){
char path_ref;
    bzero(&path_ref,1*sizeof(char));
char * path = &path_ref;
sNode end_ref;
    bzero(&end_ref,1*sizeof(sNode));
pNode end = &end_ref;
    {char * path; path = (char *)(end -> name); }
    {char * retpath; retpath = (char *)(end -> name); }
    {int tlv10; tlv10 = (int)(end -> name); }
    {char* tlv9 ; tlv9  = (char*)(end -> name); }
    {char * tlv2; tlv2 = (char *)(end -> name); }
    {char * tlv1; tlv1 = (char *)(end -> name); }
    {char * tlv4; tlv4 = (char *)(end -> name); }
    {char* tlv3 ; tlv3  = (char*)(end -> name); }
    {char * tlv6; tlv6 = (char *)(end -> name); }
    {char * tlv5; tlv5 = (char *)(end -> name); }
    {int tlv14; tlv14 = (int)(end -> name); }
    {char* tlv13 ; tlv13  = (char*)(end -> name); }
    {char * tlv12; tlv12 = (char *)(end -> name); }
    {char * tlv11; tlv11 = (char *)(end -> name); }
}
void fix_ingred_service_31_4(){
fix_ingred_service_31_4_0();
fix_ingred_service_31_4_1();
}
void fix_ingred_service_31_7_1(){
    {char * path; path = (char *)(NULL); }
    {char * retpath; retpath = (char *)(NULL); }
    {int tlv10; tlv10 = (int)(NULL); }
    {char* tlv9 ; tlv9  = (char*)(NULL); }
    {char * tlv2; tlv2 = (char *)(NULL); }
    {char * tlv1; tlv1 = (char *)(NULL); }
    {char * tlv4; tlv4 = (char *)(NULL); }
    {char* tlv3 ; tlv3  = (char*)(NULL); }
    {char * tlv6; tlv6 = (char *)(NULL); }
    {char * tlv5; tlv5 = (char *)(NULL); }
    {int tlv14; tlv14 = (int)(NULL); }
    {char* tlv13 ; tlv13  = (char*)(NULL); }
    {char * tlv12; tlv12 = (char *)(NULL); }
    {char * tlv11; tlv11 = (char *)(NULL); }
}
void fix_ingred_service_31_7(){
fix_ingred_service_31_7_1();
}
void fix_ingred_service_31_9_0(){
char tlv16_ref;
    bzero(&tlv16_ref,1*sizeof(char));
const char * tlv16 = &tlv16_ref;
char tlv18_ref;
    bzero(&tlv18_ref,1*sizeof(char));
const char * tlv18 = &tlv18_ref;
    {char * path; path = (char *)(( cgc_strlen ( tlv16 ) + cgc_strlen ( tlv18 ) + 2 )); }
    {char * retpath; retpath = (char *)(( cgc_strlen ( tlv16 ) + cgc_strlen ( tlv18 ) + 2 )); }
    {int tlv10; tlv10 = (int)(( cgc_strlen ( tlv16 ) + cgc_strlen ( tlv18 ) + 2 )); }
    {char* tlv9 ; tlv9  = (char*)(( cgc_strlen ( tlv16 ) + cgc_strlen ( tlv18 ) + 2 )); }
    {char * tlv2; tlv2 = (char *)(( cgc_strlen ( tlv16 ) + cgc_strlen ( tlv18 ) + 2 )); }
    {char * tlv1; tlv1 = (char *)(( cgc_strlen ( tlv16 ) + cgc_strlen ( tlv18 ) + 2 )); }
    {char * tlv4; tlv4 = (char *)(( cgc_strlen ( tlv16 ) + cgc_strlen ( tlv18 ) + 2 )); }
    {char* tlv3 ; tlv3  = (char*)(( cgc_strlen ( tlv16 ) + cgc_strlen ( tlv18 ) + 2 )); }
    {char * tlv6; tlv6 = (char *)(( cgc_strlen ( tlv16 ) + cgc_strlen ( tlv18 ) + 2 )); }
    {char * tlv5; tlv5 = (char *)(( cgc_strlen ( tlv16 ) + cgc_strlen ( tlv18 ) + 2 )); }
    {int tlv14; tlv14 = (int)(( cgc_strlen ( tlv16 ) + cgc_strlen ( tlv18 ) + 2 )); }
    {char* tlv13 ; tlv13  = (char*)(( cgc_strlen ( tlv16 ) + cgc_strlen ( tlv18 ) + 2 )); }
    {char * tlv12; tlv12 = (char *)(( cgc_strlen ( tlv16 ) + cgc_strlen ( tlv18 ) + 2 )); }
    {char * tlv11; tlv11 = (char *)(( cgc_strlen ( tlv16 ) + cgc_strlen ( tlv18 ) + 2 )); }
}
void fix_ingred_service_31_9(){
fix_ingred_service_31_9_0();
}
void fix_ingred_service_31_10_0(){
char retpath_ref;
    bzero(&retpath_ref,1*sizeof(char));
char * retpath = &retpath_ref;
    {char * path; path = (char *)(retpath); }
    {int tlv10; tlv10 = (int)(retpath); }
    {char* tlv9 ; tlv9  = (char*)(retpath); }
    {char * tlv2; tlv2 = (char *)(retpath); }
    {char * tlv1; tlv1 = (char *)(retpath); }
    {char * tlv4; tlv4 = (char *)(retpath); }
    {char* tlv3 ; tlv3  = (char*)(retpath); }
    {char * tlv6; tlv6 = (char *)(retpath); }
    {char * tlv5; tlv5 = (char *)(retpath); }
    {int tlv14; tlv14 = (int)(retpath); }
    {char* tlv13 ; tlv13  = (char*)(retpath); }
    {char * tlv12; tlv12 = (char *)(retpath); }
    {char * tlv11; tlv11 = (char *)(retpath); }
}
void fix_ingred_service_31_10(){
fix_ingred_service_31_10_0();
}
void fix_ingred_service_31(){
fix_ingred_service_31_3();
fix_ingred_service_31_4();
fix_ingred_service_31_7();
fix_ingred_service_31_9();
fix_ingred_service_31_10();
}
void fix_ingred_service_32_2_0(){
char path_ref;
    bzero(&path_ref,1*sizeof(char));
char * path = &path_ref;
char newPath_ref;
    bzero(&newPath_ref,1*sizeof(char));
char * newPath = &newPath_ref;
    {char * newPath; newPath = (char *)(path); }
}
void fix_ingred_service_32_2_1(){
char path_ref;
    bzero(&path_ref,1*sizeof(char));
char * path = &path_ref;
char newPath_ref;
    bzero(&newPath_ref,1*sizeof(char));
char * newPath = &newPath_ref;
    {char * tlv2; tlv2 = (char *)(newPath); }
    {char * tlv1; tlv1 = (char *)(newPath); }
}
void fix_ingred_service_32_2(){
fix_ingred_service_32_2_0();
fix_ingred_service_32_2_1();
}
void fix_ingred_service_32(){
fix_ingred_service_32_2();
}
void fix_ingred_service_33_2_1(){
sNode temp_ref;
    bzero(&temp_ref,1*sizeof(sNode));
pNode temp = &temp_ref;
char name_ref;
    bzero(&name_ref,1*sizeof(char));
char * name = &name_ref;
    {int tlv1; tlv1 = (int)(temp -> name); }
    {char * tlv3; tlv3 = (char *)(temp -> name); }
    {char * tlv2; tlv2 = (char *)(temp -> name); }
}
void fix_ingred_service_33_2(){
fix_ingred_service_33_2_1();
}
void fix_ingred_service_33(){
fix_ingred_service_33_2();
}
void fix_ingred_service_34_1_0(){
char name_ref;
    bzero(&name_ref,1*sizeof(char));
char * name = &name_ref;
    {char * tlv4; tlv4 = (char *)(name); }
}
void fix_ingred_service_34_1(){
fix_ingred_service_34_1_0();
}
void fix_ingred_service_34(){
fix_ingred_service_34_1();
}
void fix_ingred_service_35(){
}
void fix_ingred_service_36(){
}
void fix_ingred_service_37(){
}
