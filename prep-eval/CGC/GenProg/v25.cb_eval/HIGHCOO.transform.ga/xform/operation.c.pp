

#include "libcgc.h"
#include "cgc_libc.h"
#include "cgc_operation.h"
list_t *cgc_haiku_list = NULL;
uint32_t next_haiku_id = INIT_HAIKU_ID;
uint32_t cgc_recv_uint32() {
    uint32_t num[1] = {0};
    RECV(num, sizeof(uint32_t));
	return num[0];
}
uint32_t cgc_recv_uint16() {
    uint16_t num[1] = {0};
    RECV(num, sizeof(uint16_t));
	return num[0];
}
uint8_t cgc_haiku_list_exists() {
	if (NULL == cgc_haiku_list) {
		return FALSE;
	} else {
		return TRUE;
	}
}
uint8_t cgc_is_haiku_list_empty() {
	if (0 == cgc_haiku_list->count) {
		return TRUE;
	} else {
		return FALSE;
	}
}
void cgc_init_haiku_list() {
	if (FALSE == cgc_haiku_list_exists()) {
		cgc_haiku_list = cgc_list_create();
	}
}
int cgc_get_count() {
	if (TRUE == cgc_haiku_list_exists()) {
		return cgc_haiku_list->count;
	} else {
		return ERR_LIST_NOT_EXIST;
	}
}
uint32_t cgc_get_id_from_haiku(node_t *haiku) {
	if (NULL != haiku->data) {
		struct haiku *h = (struct haiku *) haiku->data;
		return h->id;
	} else {
		return ERR_EMPTY_NODE;
	}
}
uint32_t cgc_get_next_haiku_id() {
	next_haiku_id++;
	return next_haiku_id - 1;
}
int cgc_get_random_idx(uint32_t *idx) {
	uint32_t random_idx = 0;
	int ret = 0;
	ret = cgc_rand((char *)&random_idx, 4);
	int32_t count = cgc_get_count();
	if (ERR_LIST_NOT_EXIST == count) {
		return count;
	} else if (0 == count) {
		return ERR_LIST_EMPTY;
	} else if (0 != ret) {
		return ERR_RAND_FAILED;
	} else {
		*idx = random_idx % (uint32_t)count;
		return SUCCESS;
	}
}
int cgc_populate_array_with_haiku_ids(uint32_t id_arr[], uint32_t count) {
	node_t *haiku_ptr = NULL;
	struct haiku *h = NULL;
	uint32_t id = 0;
	if (TRUE == cgc_haiku_list_exists()) {
		haiku_ptr = cgc_haiku_list->tail;
	} else {
		return ERR_LIST_NOT_EXIST;
	}
	if ((0 == count) || (NULL == haiku_ptr)) {
		return ERR_LIST_EMPTY;
	}
	while ((0 < count) && (NULL != haiku_ptr)) {
		h = (struct haiku *)haiku_ptr->data;
		id_arr[count - 1] = h->id;
		count--;
		haiku_ptr = haiku_ptr->prev;
	}
	return SUCCESS;
}
int cgc_find_haiku_with_id(struct haiku **h, uint32_t id) {
	node_t *haiku_ptr = NULL;
	struct haiku *tmp = NULL;
	int count = 0;
	bool_t found = FALSE;
	count = cgc_get_count();
	if (0 < count) {
		haiku_ptr = cgc_haiku_list->head;
	} else if (0 == count) {
		return ERR_LIST_EMPTY;
	} else {
		return ERR_LIST_NOT_EXIST;
	}
	while (NULL != haiku_ptr) {
		tmp = (struct haiku *)haiku_ptr->data;
		if (id == tmp->id) {
			*h = tmp;
			found = TRUE;
			break;
		}
		haiku_ptr = haiku_ptr->next;
	}
	if (TRUE == found) {
		return SUCCESS;
	} else {
		return ERR_INVALID_ID;
	}
}
void cgc_send_haiku(struct haiku *h) {
	uint32_t id = h->id;
	char *content = h->content;
	uint16_t length = h->length;
	cgc_send((char *)&id, sizeof(uint32_t));
	cgc_send((char *)&length, sizeof(uint16_t));
	cgc_send(content, length);
}
void cgc_send_easter_egg_haiku() {
	uint32_t id = EGG_ID;
	char *content = EGG_HAIKU;
	uint16_t length = cgc_strlen(content);
	cgc_send((char *)&id, sizeof(uint32_t));
	cgc_send((char *)&length, sizeof(uint16_t));
	cgc_send(content, length);
}
void cgc_send_haiku_id(uint32_t id) {
	SENDUI(id);
}
int cgc_add_haiku_to_list(struct haiku *h) {
	node_t *nd = cgc_node_create((void *)h);
	return cgc_list_push(cgc_haiku_list, nd);
}
int cgc_recv_haiku_line(char *haiku_content_ptr, int16_t bytes_remaining) {
	char temp_line_buf[MAX_HAIKU_LINE_LEN] = {0};
	int16_t bytes_received = 0;
	int16_t bytes_written = 0;
	// bytes_received includes line termination char, 
	//  but line term char is not written to temp_line_buf, a null is in its place.
	bytes_received = cgc_recvline(STDIN, temp_line_buf, MAX_HAIKU_LINE_LEN);
	//  this will make the creation of POV input harder to create 
	//   since it will need line termination chars at set intervals.
	if (0 > bytes_received) {
		return ERR_INVALID_HAIKU;
	}
	// VULN HERE
	// - if bytes_remaining goes neg, MAX_HAIKU_LINE_LEN chars can be written
	//  to haiku_content_ptr for each line of input.
	// +1 for trailing null
	bytes_written = cgc_snprintf(haiku_content_ptr, bytes_remaining + 1, "~c\x07", temp_line_buf);
	return bytes_written;
}
struct haiku *cgc_recv_haiku(uint16_t total_bytes) {
	struct haiku *h = NULL;
	char *haiku_content_ptr = NULL;
	int16_t bytes_remaining = 0;
	int16_t bytes_written = 0;
	bytes_remaining = (int16_t)total_bytes;
	ALLOC(sizeof(struct haiku) + total_bytes + 1, &h); // +1 for trailing null
	haiku_content_ptr = h->content;
	// VULN HERE - if something causes bytes_remaining to go negative, this loop will not stop.
	while (0 != bytes_remaining) {
		bytes_written = cgc_recv_haiku_line(haiku_content_ptr, bytes_remaining);
		if (0 > bytes_written) { // ERR_INVALID_HAIKU
			return NULL;
		}
		haiku_content_ptr += bytes_written;
		bytes_remaining -= bytes_written;
	}
	h->id = cgc_get_next_haiku_id();
	h->length = total_bytes;
	return h;
}
uint16_t cgc_recv_haiku_size() {
	return cgc_recv_uint16(); 
}
// Operation functions
int cgc_add_haiku() {
	int ret = SUCCESS;
	uint16_t total_bytes = 0; // number of bytes in haiku, including line termination chars.
	struct haiku *h = NULL;
	if (FALSE == cgc_haiku_list_exists()) {
		cgc_init_haiku_list();
	}
	total_bytes	= cgc_recv_haiku_size();
	if ((0 < total_bytes) && (MAX_HAIKU_LEN > total_bytes)) {
		h = cgc_recv_haiku(total_bytes);
		if (NULL == h) {
			ret = ERR_INVALID_HAIKU;
		} else {
			ret = cgc_add_haiku_to_list(h);
			cgc_send_haiku_id(h->id);			
		}
	} else {
		ret = ERR_INVALID_HAIKU_LEN;
	}
	return ret;
}
int cgc_get_haiku_by_id() {
	struct haiku *h = NULL;
	uint32_t id = 0;
	int res = 0;
	if (TRUE == cgc_haiku_list_exists()) {
		id = cgc_recv_uint32();
		if (EGG_ID == id) {
			cgc_send_easter_egg_haiku();
		} else {
			res = cgc_find_haiku_with_id(&h, id);
			if (SUCCESS == res) {
				cgc_send_haiku(h);
			}
		}
	} else {
		res = ERR_LIST_NOT_EXIST;
	}
	return res;
}
int cgc_get_haiku_cgc_random() {
	uint32_t random_idx = 0;
	uint32_t count = 0;
	uint32_t *id_arr = NULL;
	struct haiku *rand_haiku = NULL;
	int res = SUCCESS;
	if (TRUE == cgc_haiku_list_exists()) {
		count = cgc_get_count();
		if (0 == count) {
			return ERR_LIST_EMPTY;
		}
		ALLOC(count * sizeof(uint32_t), &id_arr);
		// these functions should not return error due to haiku_list existance or count <= 0.
		res = cgc_populate_array_with_haiku_ids(id_arr, count);
		res = cgc_get_random_idx(&random_idx);
		if (ERR_RAND_FAILED != res) {
			res = cgc_find_haiku_with_id(&rand_haiku, id_arr[random_idx]);
		}
		DEALLOC(id_arr, count * sizeof(uint32_t));
		if (SUCCESS == res) {
			cgc_send_haiku(rand_haiku);
		}
	} else {
		res = ERR_LIST_NOT_EXIST;
	}
	return res;
}
int cgc_get_haiku_count() {
	uint32_t count = 0;
	if (TRUE == cgc_haiku_list_exists()) {
		count = cgc_get_count();
		SENDUI(count);
		return SUCCESS;
	} else {
		return ERR_LIST_NOT_EXIST;
	}
}
int cgc_get_haiku_ids() {
	if (TRUE == cgc_haiku_list_exists()) {
		uint32_t count = (uint32_t)cgc_get_count();
		SENDUI(count);
		node_t *hl_ptr = cgc_haiku_list->head;
		while(NULL != hl_ptr) {
			uint32_t id = cgc_get_id_from_haiku(hl_ptr);
			SENDUI(id);
			hl_ptr = hl_ptr->next;
		}
	} else {
		return ERR_LIST_NOT_EXIST;
	}
	return SUCCESS;
}


