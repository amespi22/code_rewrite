

#include "libcgc.h"
#include "cgc_stdarg.h"
#include "cgc_stdlib.h"
#include "cgc_string.h"
#include "cgc_gld.h"
// Global Variables
static qtree_t *g_conway_gld = NULL;	//Conway's Game of Life and Death
static int cgc_qt_insert(qtree_t * qt, conway_pixel_t px);
static conway_pixel_t *cgc_qt_get_pixel(qtree_t * qt, coord_t point);
static qtree_t *cgc_qt_create(int max_level, region_t valid_region);
static int cgc_qt_delete(qtree_t * qt, conway_pixel_t px);
static int cgc_cg_step(int num_steps);
static int cgc_shoot_pixel(coord_t point);
static int cgc_set_bomb(coord_t point);
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

void fix_ingred_gld_0();
static int cgc_within_region(coord_t point, region_t valid_region)
{
if (fix_ingred_enable){ fix_ingred_gld_0(); };
    return (point.x >= valid_region.start.x && point.x < valid_region.end.x && point.y >= valid_region.start.y && point.y < valid_region.end.y);
}

void fix_ingred_gld_1_13_0();
void fix_ingred_gld_1_13_1();
void fix_ingred_gld_1_13();
void fix_ingred_gld_1();
static pixel_list_t *cgc_create_cell_list(qtree_t * qt, cell_filter_e filter)
{
if (fix_ingred_enable){ fix_ingred_gld_1(); };
    pixel_list_t* list;
    list = NULL;
    pixel_list_t* temp;
    temp = NULL;
    if (qt->is_subdivided) {
 {
     qtree_t* tlv2;
     tlv2 = qt -> nw;
     cell_filter_e tlv1;
     tlv1 = filter;
    	temp = cgc_create_cell_list(tlv2,tlv1);
 }
	APPEND_LIST(pixel_list_t, list, temp);
 {
     qtree_t* tlv4;
     tlv4 = qt -> ne;
     cell_filter_e tlv3;
     tlv3 = filter;
    	temp = cgc_create_cell_list(tlv4,tlv3);
 }
	APPEND_LIST(pixel_list_t, list, temp);
 {
     qtree_t* tlv6;
     tlv6 = qt -> sw;
     cell_filter_e tlv5;
     tlv5 = filter;
    	temp = cgc_create_cell_list(tlv6,tlv5);
 }
	APPEND_LIST(pixel_list_t, list, temp);
 {
     qtree_t* tlv8;
     tlv8 = qt -> se;
     cell_filter_e tlv7;
     tlv7 = filter;
    	temp = cgc_create_cell_list(tlv8,tlv7);
 }
	APPEND_LIST(pixel_list_t, list, temp);
	return list;
    }
    pixel_list_t* pixel;
    pixel = qt -> pixels;
    while (pixel != NULL) {
	if (filter == LIVING_CELL && !pixel->px.is_alive) {;
	} else {
	    if (filter == BOMB && !pixel->px.bomb_set) {;
	    } else {
		if (filter == DEAD_CELL && (pixel->px.is_alive || pixel->px.bomb_set)) {;
		} else {
      {
          cgc_size_t tlv10;
          tlv10 = 1;
          cgc_size_t tlv9;
          tlv9 = sizeof ( pixel_list_t );
    		    temp = cgc_calloc(tlv10,tlv9);
      }
		    temp->px = pixel->px;
		    INSERT_ITEM(list, temp);
		}
	    }
	}
	pixel = pixel->next;
    }
    return list;
}

void fix_ingred_gld_2_1_0();
void fix_ingred_gld_2_1();
void fix_ingred_gld_2();
coord_t *cgc_create_adjacent_coords(coord_t coord)
{
if (fix_ingred_enable){ fix_ingred_gld_2(); };
    coord_t* adj_cells;
    {
        cgc_size_t tlv1;
        tlv1 = sizeof ( coord_t ) * 8;
        adj_cells = cgc_malloc(tlv1);
    }
    SET_COORD(adj_cells[0], coord.x - 1, coord.y - 1);
    SET_COORD(adj_cells[1], coord.x - 0, coord.y - 1);
    SET_COORD(adj_cells[2], coord.x + 1, coord.y - 1);
    SET_COORD(adj_cells[3], coord.x - 1, coord.y - 0);
    SET_COORD(adj_cells[4], coord.x + 1, coord.y - 0);
    SET_COORD(adj_cells[5], coord.x - 1, coord.y + 1);
    SET_COORD(adj_cells[6], coord.x - 0, coord.y + 1);
    SET_COORD(adj_cells[7], coord.x + 1, coord.y + 1);
    return adj_cells;
}

void fix_ingred_gld_3_0_1();
void fix_ingred_gld_3_0();
void fix_ingred_gld_3_1_5();
void fix_ingred_gld_3_1();
void fix_ingred_gld_3_4_0();
void fix_ingred_gld_3_4();
void fix_ingred_gld_3_5_0();
void fix_ingred_gld_3_5_1();
void fix_ingred_gld_3_5_2();
void fix_ingred_gld_3_5();
void fix_ingred_gld_3_7_13();
void fix_ingred_gld_3_7_14();
void fix_ingred_gld_3_7();
void fix_ingred_gld_3_10_1();
void fix_ingred_gld_3_10();
void fix_ingred_gld_3();
int cgc_bomb_collisions(pixel_list_t * bombs, pixel_list_t * living_cells)
{
if (fix_ingred_enable){ fix_ingred_gld_3(); };
    pixel_list_t* iter;
    iter = NULL;
    conway_pixel_t *dead_cell;
    int i;
    int total_score;
    total_score = 0;
    int score;
    score = 0;
    int cells_hit;
    cells_hit = 0;
    while (bombs != NULL) {
	score = 0;
	cells_hit = 0;
	if (bombs->px.bomb_set != 0) {
	    bombs = bombs->next;
	    continue;
	}
 coord_t* adj_cells;
 {
     coord_t tlv4;
     tlv4 = bombs -> px . point;
     adj_cells = cgc_create_adjacent_coords(tlv4);
 }
 coord_t* bomb_cells;
 {
     cgc_size_t tlv5;
     tlv5 = sizeof ( coord_t ) * 9;
     bomb_cells = cgc_malloc(tlv5);
 }
 {
     void* tlv3;
     tlv3 = bomb_cells;
     void* tlv2;
     tlv2 = adj_cells;
     cgc_size_t tlv1;
     tlv1 = sizeof ( coord_t ) * 8;
    	cgc_memcpy(tlv3,tlv2,tlv1);
 }
	bomb_cells[8] = bombs->px.point;
	cgc_free(adj_cells);
	iter = living_cells;
	while (iter != NULL) {
	    for (i = 0; i < 9; i++) {
		if (COORD_EQUALS(iter->px.point, bomb_cells[i])) {
		    // You get a multiplicative bonus for hitting multiple cells with 1 bomb
      {
          qtree_t* tlv7;
          tlv7 = g_conway_gld;
          coord_t tlv6;
          tlv6 = bomb_cells [ i ];
    		    dead_cell = cgc_qt_get_pixel(tlv7,tlv6);
      }
		    if (dead_cell->is_alive) {
			dead_cell->is_alive = FALSE;
			cells_hit++;
			score += 100 + cells_hit * score;
			if (!dead_cell->bomb_set) {
       {
           qtree_t* tlv9;
           tlv9 = g_conway_gld;
           conway_pixel_t tlv8;
           tlv8 = * dead_cell;
    			    cgc_qt_delete(tlv9,tlv8);
       }
			}
		    }
		    iter = iter->next;
		    break;
		}
	    }
	    if (i == 9) {
		iter = iter->next;
	    }
	}
	bombs = bombs->next;
	cgc_free(bomb_cells);
	total_score += score;
    }
    return total_score;
}

void fix_ingred_gld_4_0_0();
void fix_ingred_gld_4_0();
void fix_ingred_gld_4_2_2();
void fix_ingred_gld_4_2_3();
void fix_ingred_gld_4_2();
void fix_ingred_gld_4_5_1();
void fix_ingred_gld_4_5_2();
void fix_ingred_gld_4_5();
void fix_ingred_gld_4();
static int cgc_is_dead_cell_generation(coord_t coord)
{
if (fix_ingred_enable){ fix_ingred_gld_4(); };
    coord_t* adj_cells;
    {
        coord_t tlv1;
        tlv1 = coord;
        adj_cells = cgc_create_adjacent_coords(tlv1);
    }
    conway_pixel_t *pixel;
    int i;
    int num_living_cells;
    num_living_cells = 0;
    for (i = 0; i < 8; i++) {
 {
     qtree_t* tlv3;
     tlv3 = g_conway_gld;
     coord_t tlv2;
     tlv2 = adj_cells [ i ];
    	pixel = cgc_qt_get_pixel(tlv3,tlv2);
 }
	if (pixel != NULL && pixel->is_alive) {
	    num_living_cells++;
	}
    }
    cgc_free(adj_cells);
    if (num_living_cells == 3) {
	return TRUE;
    }
    return FALSE;
}

void fix_ingred_gld_5_0_0();
void fix_ingred_gld_5_0();
void fix_ingred_gld_5_2_6();
void fix_ingred_gld_5_2_7();
void fix_ingred_gld_5_2();
void fix_ingred_gld_5_9_0();
void fix_ingred_gld_5_9_1();
void fix_ingred_gld_5_9();
void fix_ingred_gld_5_12_1();
void fix_ingred_gld_5_12();
void fix_ingred_gld_5_18_8();
void fix_ingred_gld_5_18_9();
void fix_ingred_gld_5_18_11();
void fix_ingred_gld_5_18();
void fix_ingred_gld_5();
static void cgc_conway_step(conway_pixel_t cell, pixel_list_t ** pgenerated_cells, pixel_list_t ** pdeceased_cells, coord_list_t ** pchecked_coords)
{
if (fix_ingred_enable){ fix_ingred_gld_5(); };
    int i;
    i = 0;
    int num_living_cells;
    num_living_cells = 0;
    coord_list_t* cc_iter;
    cc_iter = * pchecked_coords;
    coord_t* adj_cells;
    {
        coord_t tlv2;
        tlv2 = cell . point;
        adj_cells = cgc_create_adjacent_coords(tlv2);
    }
    conway_pixel_t *pixel;
    pixel_list_t* generated_cell;
    generated_cell = NULL;
    coord_list_t* checked_coord;
    checked_coord = NULL;
    for (i = 0; i < 8; i++) {
	// Negative cells and out of bounds cells are not ignored
	if (adj_cells[i].x < 0 || adj_cells[i].y < 0 || adj_cells[i].x > MAX_BOARD_WIDTH || adj_cells[i].y > MAX_BOARD_WIDTH) {
	    continue;
	}
	//Skip cells we've already checked
	while (cc_iter != NULL) {
	    if (COORD_EQUALS(adj_cells[i], cc_iter->coord)) {
		break;
	    }
	    cc_iter = cc_iter->next;
	}
 {
     qtree_t* tlv8;
     tlv8 = g_conway_gld;
     coord_t tlv7;
     tlv7 = adj_cells [ i ];
    	pixel = cgc_qt_get_pixel(tlv8,tlv7);
 }
	if (pixel == NULL || !pixel->is_alive) {	//dead cell
	    if (cc_iter != NULL)	//Already checked
	    {
		continue;
	    }
     {
         cgc_size_t tlv10;
         tlv10 = 1;
         cgc_size_t tlv9;
         tlv9 = sizeof ( coord_list_t );
    	    checked_coord = cgc_calloc(tlv10,tlv9);
     }
	    checked_coord->coord = adj_cells[i];
	    INSERT_ITEM((*pchecked_coords), checked_coord);
     static int tlv1;
     {
         coord_t tlv11;
         tlv11 = adj_cells [ i ];
         tlv1 = cgc_is_dead_cell_generation(tlv11);
     }
	    if (tlv1) {
  {
      cgc_size_t tlv13;
      tlv13 = 1;
      cgc_size_t tlv12;
      tlv12 = sizeof ( pixel_list_t );
    		generated_cell = cgc_calloc(tlv13,tlv12);
  }
		if (pixel != NULL) {
		    generated_cell->px = *pixel;
		} else {
		    generated_cell->px.point = adj_cells[i];
		}
		generated_cell->px.is_alive = TRUE;
		INSERT_ITEM((*pgenerated_cells), generated_cell);
	    }
	} else {
	    num_living_cells++;
	}
    }
    {
        cgc_size_t tlv4;
        tlv4 = 1;
        cgc_size_t tlv3;
        tlv3 = sizeof ( coord_list_t );
        checked_coord = cgc_calloc(tlv4,tlv3);
    }
    checked_coord->coord = cell.point;
    INSERT_ITEM((*pchecked_coords), checked_coord);
    {
        cgc_size_t tlv6;
        tlv6 = 1;
        cgc_size_t tlv5;
        tlv5 = sizeof ( pixel_list_t );
        generated_cell = cgc_calloc(tlv6,tlv5);
    }
    generated_cell->px = cell;
    if (num_living_cells == 2 || num_living_cells == 3) {
	generated_cell->px.is_alive = TRUE;
	INSERT_ITEM((*pgenerated_cells), generated_cell);
    } else {
	generated_cell->px.is_alive = FALSE;
	INSERT_ITEM((*pdeceased_cells), generated_cell);
    }
    cgc_free(adj_cells);
}

void fix_ingred_gld_6();
static qtree_t *cgc_find_subregion_tree(qtree_t * qt, coord_t p)
{
if (fix_ingred_enable){ fix_ingred_gld_6(); };
    if (!qt->is_subdivided) {
	return NULL;
    }
    static int tlv1;
    {
        coord_t tlv6;
        tlv6 = p;
        region_t tlv5;
        tlv5 = qt -> nw -> valid_region;
        tlv1 = cgc_within_region(tlv6,tlv5);
    }
    if (tlv1) {
	return qt->nw;
    }
    static int tlv2;
    {
        coord_t tlv8;
        tlv8 = p;
        region_t tlv7;
        tlv7 = qt -> ne -> valid_region;
        tlv2 = cgc_within_region(tlv8,tlv7);
    }
    if (tlv2) {
	return qt->ne;
    }
    static int tlv3;
    {
        coord_t tlv10;
        tlv10 = p;
        region_t tlv9;
        tlv9 = qt -> sw -> valid_region;
        tlv3 = cgc_within_region(tlv10,tlv9);
    }
    if (tlv3) {
	return qt->sw;
    }
    static int tlv4;
    {
        coord_t tlv12;
        tlv12 = p;
        region_t tlv11;
        tlv11 = qt -> se -> valid_region;
        tlv4 = cgc_within_region(tlv12,tlv11);
    }
    if (tlv4) {
	return qt->se;
    }
    return NULL;
}

void fix_ingred_gld_7_0_0();
void fix_ingred_gld_7_0();
void fix_ingred_gld_7_2_0();
void fix_ingred_gld_7_2();
void fix_ingred_gld_7();
static int cgc_subdivide(qtree_t * qt)
{
if (fix_ingred_enable){ fix_ingred_gld_7(); };
    if (qt->max_levels == 0) {
	return -1;
    }				//should never get here
    region_t nw;
    region_t ne;
    region_t sw;
    region_t se;
    unsigned int width;
    width = 1 << ( qt -> max_levels - 1 );
    unsigned int startx;
    startx = qt -> valid_region . start . x;
    unsigned int starty;
    starty = qt -> valid_region . start . y;
    unsigned int endx;
    endx = qt -> valid_region . end . x;
    unsigned int endy;
    endy = qt -> valid_region . end . y;
    SET_REGION(nw, startx, starty, startx + width, starty + width);
    SET_REGION(ne, startx + width, starty, endx, starty + width);
    SET_REGION(sw, startx, starty + width, startx + width, endy);
    SET_REGION(se, startx + width, starty + width, endx, endy);
    {
        int tlv2;
        tlv2 = qt -> max_levels - 1;
        region_t tlv1;
        tlv1 = nw;
        qt->nw = cgc_qt_create(tlv2,tlv1);
    }
    {
        int tlv4;
        tlv4 = qt -> max_levels - 1;
        region_t tlv3;
        tlv3 = ne;
        qt->ne = cgc_qt_create(tlv4,tlv3);
    }
    {
        int tlv6;
        tlv6 = qt -> max_levels - 1;
        region_t tlv5;
        tlv5 = sw;
        qt->sw = cgc_qt_create(tlv6,tlv5);
    }
    {
        int tlv8;
        tlv8 = qt -> max_levels - 1;
        region_t tlv7;
        tlv7 = se;
        qt->se = cgc_qt_create(tlv8,tlv7);
    }
    qt->is_subdivided = TRUE;
    return 0;
}

void fix_ingred_gld_8();
static void cgc_move_pixels(qtree_t * qt, pixel_list_t * xfer_pixels, int num_pixels)
{
if (fix_ingred_enable){ fix_ingred_gld_8(); };
    if (num_pixels == 0) {
	return;
    }				//Successfully copied 0
    APPEND_LIST(pixel_list_t, qt->pixels, xfer_pixels);
    qt->num_pixels += num_pixels;
}

void fix_ingred_gld_9_8_0();
void fix_ingred_gld_9_8();
void fix_ingred_gld_9_9_0();
void fix_ingred_gld_9_9();
void fix_ingred_gld_9_10_0();
void fix_ingred_gld_9_10();
void fix_ingred_gld_9_11_0();
void fix_ingred_gld_9_11();
void fix_ingred_gld_9();
static int cgc_qt_undivide(qtree_t * qt)
{
if (fix_ingred_enable){ fix_ingred_gld_9(); };
    if (!qt->is_subdivided) {
	return -1;
    }
    //If any node is subdivided, there is n+1 objects --> no collapse
    if (qt->nw->is_subdivided || qt->ne->is_subdivided || qt->sw->is_subdivided || qt->se->is_subdivided) {
	return -1;
    }
    if ((qt->num_pixels + qt->nw->num_pixels + qt->ne->num_pixels + qt->sw->num_pixels + qt->se->num_pixels) > qt->max_pixels) {
	return -1;
    }
    //Ready to undivide
    {
        qtree_t* tlv3;
        tlv3 = qt;
        pixel_list_t* tlv2;
        tlv2 = qt -> nw -> pixels;
        int tlv1;
        tlv1 = qt -> nw -> num_pixels;
        cgc_move_pixels(tlv3,tlv2,tlv1);
    }
    {
        qtree_t* tlv6;
        tlv6 = qt;
        pixel_list_t* tlv5;
        tlv5 = qt -> ne -> pixels;
        int tlv4;
        tlv4 = qt -> ne -> num_pixels;
        cgc_move_pixels(tlv6,tlv5,tlv4);
    }
    {
        qtree_t* tlv9;
        tlv9 = qt;
        pixel_list_t* tlv8;
        tlv8 = qt -> sw -> pixels;
        int tlv7;
        tlv7 = qt -> sw -> num_pixels;
        cgc_move_pixels(tlv9,tlv8,tlv7);
    }
    {
        qtree_t* tlv12;
        tlv12 = qt;
        pixel_list_t* tlv11;
        tlv11 = qt -> se -> pixels;
        int tlv10;
        tlv10 = qt -> se -> num_pixels;
        cgc_move_pixels(tlv12,tlv11,tlv10);
    }
    {
        void* tlv13;
        tlv13 = qt -> nw;
        cgc_free(tlv13);
    }
    {
        void* tlv14;
        tlv14 = qt -> ne;
        cgc_free(tlv14);
    }
    {
        void* tlv15;
        tlv15 = qt -> sw;
        cgc_free(tlv15);
    }
    {
        void* tlv16;
        tlv16 = qt -> se;
        cgc_free(tlv16);
    }
    qt->nw = NULL;
    qt->ne = NULL;
    qt->sw = NULL;
    qt->se = NULL;
    qt->is_subdivided = FALSE;
    return 0;
}

void fix_ingred_gld_10();
static int cgc_qt_delete(qtree_t * qt, conway_pixel_t px)
{
if (fix_ingred_enable){ fix_ingred_gld_10(); };
    static int tlv1;
    {
        coord_t tlv4;
        tlv4 = px . point;
        region_t tlv3;
        tlv3 = qt -> valid_region;
        tlv1 = cgc_within_region(tlv4,tlv3);
    }
    if (!tlv1) {
	return -1;
    }
    qtree_t* subtree;
    {
        qtree_t* tlv6;
        tlv6 = qt;
        coord_t tlv5;
        tlv5 = px . point;
        subtree = cgc_find_subregion_tree(tlv6,tlv5);
    }
    if (subtree != NULL) {
 static int tlv2;
 {
     qtree_t* tlv8;
     tlv8 = subtree;
     conway_pixel_t tlv7;
     tlv7 = px;
     tlv2 = cgc_qt_delete(tlv8,tlv7);
 }
	if (tlv2 == 0) {
	    return cgc_qt_undivide(qt);
	} else {
	    return -1;
	}
    }
    pixel_list_t* pixel;
    pixel = qt -> pixels;
    while (pixel != NULL) {
	if (COORD_EQUALS(px.point, pixel->px.point)) {
	    FREE_ITEM(qt->pixels, pixel);
	    qt->num_pixels--;
	    return 0;
	}
	pixel = pixel->next;
    }
    return -1;
}

void fix_ingred_gld_11_1_0();
void fix_ingred_gld_11_1();
void fix_ingred_gld_11();
static qtree_t *cgc_qt_create(int max_level, region_t valid_region)
{
if (fix_ingred_enable){ fix_ingred_gld_11(); };
    qtree_t *qt;
    {
        cgc_size_t tlv1;
        tlv1 = sizeof ( qtree_t );
        qt = cgc_malloc(tlv1);
    }
    qt->max_levels = max_level;
    qt->max_pixels = PIXELS_PER_TRIE;
    qt->num_pixels = 0;
    qt->pixels = NULL;
    qt->valid_region = valid_region;
    qt->is_subdivided = FALSE;
    // Functions
    qt->insert = cgc_qt_insert;
    qt->get_pixel = cgc_qt_get_pixel;
    qt->step = cgc_cg_step;
    qt->shoot_pixel = cgc_shoot_pixel;
    qt->set_bomb = cgc_set_bomb;
    qt->nw = NULL;
    qt->ne = NULL;
    qt->sw = NULL;
    qt->se = NULL;
    return qt;
}

void fix_ingred_gld_12_8_0();
void fix_ingred_gld_12_8_1();
void fix_ingred_gld_12_8();
void fix_ingred_gld_12();
static int cgc_qt_insert(qtree_t * qt, conway_pixel_t px)
{
if (fix_ingred_enable){ fix_ingred_gld_12(); };
    static int tlv1;
    {
        coord_t tlv5;
        tlv5 = px . point;
        region_t tlv4;
        tlv4 = qt -> valid_region;
        tlv1 = cgc_within_region(tlv5,tlv4);
    }
    if (!tlv1) {
	return -1;
    }
    qtree_t* subtree;
    {
        qtree_t* tlv7;
        tlv7 = qt;
        coord_t tlv6;
        tlv6 = px . point;
        subtree = cgc_find_subregion_tree(tlv7,tlv6);
    }
    if (subtree != NULL) {
	return cgc_qt_insert(subtree, px);
    }
    pixel_list_t* pixel;
    pixel = qt -> pixels;
    while (pixel != NULL) {
	if (COORD_EQUALS(px.point, pixel->px.point)) {
	    pixel->px = px;
	    return 0;
;		//Updated Pixel, no insert
	}
	pixel = pixel->next;
    }
    if (qt->num_pixels < qt->max_pixels) {
 pixel_list_t* new_pixel;
 {
     cgc_size_t tlv9;
     tlv9 = 1;
     cgc_size_t tlv8;
     tlv8 = sizeof ( pixel_list_t );
     new_pixel = cgc_calloc(tlv9,tlv8);
 }
	new_pixel->px = px;
	INSERT_ITEM(qt->pixels, new_pixel);
	qt->num_pixels++;
	return 0;
    } else {			//Subdivide and spread pixels accoss the nodes
 static int tlv2;
 {
     qtree_t* tlv10;
     tlv10 = qt;
     tlv2 = cgc_subdivide(tlv10);
 }
	if (tlv2 != 0) {
	    return -1;
	}
	//Insert all existing pixels
	pixel = qt->pixels;
	while (pixel != NULL) {
     {
         qtree_t* tlv14;
         tlv14 = qt;
         coord_t tlv13;
         tlv13 = pixel -> px . point;
    	    subtree = cgc_find_subregion_tree(tlv14,tlv13);
     }
     static int tlv3;
     {
         qtree_t* tlv16;
         tlv16 = subtree;
         conway_pixel_t tlv15;
         tlv15 = pixel -> px;
         tlv3 = cgc_qt_insert(tlv16,tlv15);
     }
	    if (tlv3 != 0) {
		return -1;
	    }
	    pixel = pixel->next;
	}
	FREE_LIST(pixel_list_t, qt->pixels);
	qt->pixels = NULL;
	qt->num_pixels = 0;
	//Finally - Insert the original pixel
 {
     qtree_t* tlv12;
     tlv12 = qt;
     coord_t tlv11;
     tlv11 = px . point;
    	subtree = cgc_find_subregion_tree(tlv12,tlv11);
 }
	return cgc_qt_insert(subtree, px);
    }
}

void fix_ingred_gld_13();
static conway_pixel_t *cgc_qt_get_pixel(qtree_t * qt, coord_t point)
{
if (fix_ingred_enable){ fix_ingred_gld_13(); };
    static int tlv1;
    {
        coord_t tlv3;
        tlv3 = point;
        region_t tlv2;
        tlv2 = qt -> valid_region;
        tlv1 = cgc_within_region(tlv3,tlv2);
    }
    if (!tlv1) {
	return NULL;
    }
    qtree_t* subtree;
    {
        qtree_t* tlv5;
        tlv5 = qt;
        coord_t tlv4;
        tlv4 = point;
        subtree = cgc_find_subregion_tree(tlv5,tlv4);
    }
    if (subtree != NULL) {
	return cgc_qt_get_pixel(subtree, point);
    }
    pixel_list_t* pixel;
    pixel = qt -> pixels;
    while (pixel != NULL) {
	if (COORD_EQUALS(point, pixel->px.point)) {
	    return &pixel->px;
	}
	pixel = pixel->next;
    }
    return NULL;
}

void fix_ingred_gld_14_0_0();
void fix_ingred_gld_14_0();
void fix_ingred_gld_14_1_17();
void fix_ingred_gld_14_1_18();
void fix_ingred_gld_14_1();
void fix_ingred_gld_14_12_0();
void fix_ingred_gld_14_12_1();
void fix_ingred_gld_14_12();
void fix_ingred_gld_14();
static int cgc_cg_step(int num_steps)
{
if (fix_ingred_enable){ fix_ingred_gld_14(); };
    int i;
    int total_score;
    total_score = 0;
    pixel_list_t* bombs;
    bombs = NULL;
    pixel_list_t* living_cells;
    living_cells = NULL;
    pixel_list_t* generated_cells;
    generated_cells = NULL;
    pixel_list_t* deceased_cells;
    deceased_cells = NULL;
    coord_list_t* checked_coords;
    checked_coords = NULL;
    pixel_list_t* bombs_ordered;
    bombs_ordered = NULL;
    pixel_list_t* temp;
    temp = NULL;
    pixel_list_t* iter;
    iter = NULL;
    for (i = 0; i < num_steps; i++) {
 {
     qtree_t* tlv2;
     tlv2 = g_conway_gld;
     cell_filter_e tlv1;
     tlv1 = LIVING_CELL;
    	living_cells = cgc_create_cell_list(tlv2,tlv1);
 }
	iter = living_cells;
	while (iter != NULL) {
     {
         conway_pixel_t tlv14;
         tlv14 = iter -> px;
         pixel_list_t** tlv13;
         tlv13 = & generated_cells;
         pixel_list_t** tlv12;
         tlv12 = & deceased_cells;
         coord_list_t** tlv11;
         tlv11 = & checked_coords;
    	    cgc_conway_step(tlv14,tlv13,tlv12,tlv11);
     }
	    iter = iter->next;
	}
	FREE_LIST(pixel_list_t, living_cells);
	FREE_LIST(coord_list_t, checked_coords);
	iter = generated_cells;
	while (iter != NULL) {
     {
         qtree_t* tlv16;
         tlv16 = g_conway_gld;
         conway_pixel_t tlv15;
         tlv15 = iter -> px;
    	    cgc_qt_insert(tlv16,tlv15);
     }
	    iter = iter->next;
	}
	FREE_LIST(pixel_list_t, generated_cells);
	iter = deceased_cells;
	while (iter != NULL) {
     {
         qtree_t* tlv18;
         tlv18 = g_conway_gld;
         conway_pixel_t tlv17;
         tlv17 = iter -> px;
    	    cgc_qt_insert(tlv18,tlv17);
     }
	    iter = iter->next;
	}
	FREE_LIST(pixel_list_t, deceased_cells);
 {
     qtree_t* tlv4;
     tlv4 = g_conway_gld;
     cell_filter_e tlv3;
     tlv3 = BOMB;
    	bombs = cgc_create_cell_list(tlv4,tlv3);
 }
	iter = bombs;
	while (iter != NULL) {
	    iter->px.bomb_set--;
     {
         qtree_t* tlv20;
         tlv20 = g_conway_gld;
         conway_pixel_t tlv19;
         tlv19 = iter -> px;
    	    cgc_qt_insert(tlv20,tlv19);
     }
     {
         cgc_size_t tlv24;
         tlv24 = 1;
         cgc_size_t tlv23;
         tlv23 = sizeof ( pixel_list_t );
    	    temp = cgc_calloc(tlv24,tlv23);
     }
	    temp->px = iter->px;
	    INSERT_PIXEL_IN_ORDER((bombs_ordered), temp);
	    iter = iter->next;
	}
	FREE_LIST(pixel_list_t, bombs);
	bombs = bombs_ordered;
	bombs_ordered = NULL;
 {
     qtree_t* tlv6;
     tlv6 = g_conway_gld;
     cell_filter_e tlv5;
     tlv5 = LIVING_CELL;
    	living_cells = cgc_create_cell_list(tlv6,tlv5);
 }
 {
     pixel_list_t* tlv8;
     tlv8 = bombs;
     pixel_list_t* tlv7;
     tlv7 = living_cells;
    	total_score += cgc_bomb_collisions(tlv8,tlv7);
 }
	FREE_LIST(pixel_list_t, living_cells);
	FREE_LIST(pixel_list_t, bombs);
 {
     qtree_t* tlv10;
     tlv10 = g_conway_gld;
     cell_filter_e tlv9;
     tlv9 = DEAD_CELL;
    	deceased_cells = cgc_create_cell_list(tlv10,tlv9);
 }
	iter = deceased_cells;
	while (iter != NULL) {
     {
         qtree_t* tlv22;
         tlv22 = g_conway_gld;
         conway_pixel_t tlv21;
         tlv21 = iter -> px;
    	    cgc_qt_delete(tlv22,tlv21);
     }
	    iter = iter->next;
	}
	FREE_LIST(pixel_list_t, deceased_cells);
    }
    return total_score;
}

void fix_ingred_gld_15();
static int cgc_shoot_pixel(coord_t point)
{
if (fix_ingred_enable){ fix_ingred_gld_15(); };
    conway_pixel_t *dead_cell;
    {
        qtree_t* tlv2;
        tlv2 = g_conway_gld;
        coord_t tlv1;
        tlv1 = point;
        dead_cell = cgc_qt_get_pixel(tlv2,tlv1);
    }
    if (dead_cell != NULL && dead_cell->is_alive) {
	dead_cell->is_alive = FALSE;
	if (!dead_cell->bomb_set) {
     {
         qtree_t* tlv4;
         tlv4 = g_conway_gld;
         conway_pixel_t tlv3;
         tlv3 = * dead_cell;
    	    cgc_qt_delete(tlv4,tlv3);
     }
	}
	return 100;
    }
    return 0;
}

void fix_ingred_gld_16();
static int cgc_set_bomb(coord_t point)
{
if (fix_ingred_enable){ fix_ingred_gld_16(); };
    conway_pixel_t *bomb;
    conway_pixel_t new_bomb;
    {
        qtree_t* tlv2;
        tlv2 = g_conway_gld;
        coord_t tlv1;
        tlv1 = point;
        bomb = cgc_qt_get_pixel(tlv2,tlv1);
    }
    if (bomb == NULL) {
	new_bomb.point = point;
	new_bomb.is_alive = FALSE;
	new_bomb.bomb_set = 10;
	return (cgc_qt_insert(g_conway_gld, new_bomb) == 0);
    } else {
	if (!bomb->bomb_set) {
	    bomb->bomb_set = 10;
	    return TRUE;
	} else {
	    return FALSE;
	}
    }
}

void fix_ingred_gld_17_2_0();
void fix_ingred_gld_17_2();
void fix_ingred_gld_17();
qtree_t *cgc_gld_init_game()
{
if (fix_ingred_enable){ fix_ingred_gld_17(); };
    if (g_conway_gld == NULL) {
	region_t valid_region;
	SET_REGION(valid_region, 0, 0, MAX_BOARD_WIDTH, MAX_BOARD_WIDTH);
 {
     int tlv2;
     tlv2 = MAX_LEVELS;
     region_t tlv1;
     tlv1 = valid_region;
    	g_conway_gld = cgc_qt_create(tlv2,tlv1);
 }
    }
    return g_conway_gld;
}

void fix_ingred_gld_18();
void cgc_gld_clear_board()
{
if (fix_ingred_enable){ fix_ingred_gld_18(); };
    if (g_conway_gld == NULL) {
	return;
    }
    pixel_list_t* all_cells;
    {
        qtree_t* tlv2;
        tlv2 = g_conway_gld;
        cell_filter_e tlv1;
        tlv1 = ALL;
        all_cells = cgc_create_cell_list(tlv2,tlv1);
    }
    pixel_list_t *iter;
    iter = all_cells;
    while (iter != NULL) {
 {
     qtree_t* tlv4;
     tlv4 = g_conway_gld;
     conway_pixel_t tlv3;
     tlv3 = iter -> px;
    	cgc_qt_delete(tlv4,tlv3);
 }
	iter = iter->next;
    }
    FREE_LIST(pixel_list_t, all_cells);
}

void fix_ingred_gld_19();
static void cgc_print_board_helper(qtree_t * qt, pixel_list_t ** list)
{
if (fix_ingred_enable){ fix_ingred_gld_19(); };
    if (qt->is_subdivided) {
 {
     qtree_t* tlv2;
     tlv2 = qt -> nw;
     pixel_list_t** tlv1;
     tlv1 = list;
    	cgc_print_board_helper(tlv2,tlv1);
 }
 {
     qtree_t* tlv4;
     tlv4 = qt -> ne;
     pixel_list_t** tlv3;
     tlv3 = list;
    	cgc_print_board_helper(tlv4,tlv3);
 }
 {
     qtree_t* tlv6;
     tlv6 = qt -> sw;
     pixel_list_t** tlv5;
     tlv5 = list;
    	cgc_print_board_helper(tlv6,tlv5);
 }
 {
     qtree_t* tlv8;
     tlv8 = qt -> se;
     pixel_list_t** tlv7;
     tlv7 = list;
    	cgc_print_board_helper(tlv8,tlv7);
 }
    }
    pixel_list_t* pixel;
    pixel = qt -> pixels;
    pixel_list_t *temp;
    while (pixel != NULL) {
	if (pixel->px.is_alive || pixel->px.bomb_set) {
     {
         cgc_size_t tlv10;
         tlv10 = 1;
         cgc_size_t tlv9;
         tlv9 = sizeof ( pixel_list_t );
    	    temp = cgc_calloc(tlv10,tlv9);
     }
	    temp->px = pixel->px;
	    INSERT_PIXEL_IN_ORDER((*list), temp);
	}
	pixel = pixel->next;
    }
}

void fix_ingred_gld_20();
void cgc_gld_print_board(char *str)
{
if (fix_ingred_enable){ fix_ingred_gld_20(); };
    pixel_list_t* list;
    list = NULL;
    pixel_list_t* iter;
    iter = NULL;
    {
        qtree_t* tlv2;
        tlv2 = g_conway_gld;
        pixel_list_t** tlv1;
        tlv1 = & list;
        cgc_print_board_helper(tlv2,tlv1);
    }
    iter = list;
    cgc_printf("%s", str);
    while (iter != NULL) {
	cgc_printf("--| (x,y) = (%d,%d) | Alive=%d | Bomb=%d |\n", iter->px.point.x, iter->px.point.y, iter->px.is_alive, iter->px.bomb_set);
	iter = iter->next;
    }
    FREE_LIST(pixel_list_t, list);
}

void fix_ingred_gld_21_2_0();
void fix_ingred_gld_21_2();
void fix_ingred_gld_21_4_7();
void fix_ingred_gld_21_4_8();
void fix_ingred_gld_21_4();
void fix_ingred_gld_21();
void cgc_qt_debug_print_tree(qtree_t * qt, char *str)
{
if (fix_ingred_enable){ fix_ingred_gld_21(); };
    if (qt == NULL) {
	return;
    }
    if (qt->num_pixels > 0) {
	cgc_printf("Level: %d, ID: %s\n", MAX_LEVELS - qt->max_levels, str);
 int i;
 i = 0;
 pixel_list_t* iter;
 iter = qt -> pixels;
	while (iter != NULL) {
	    for (i = 0; i < MAX_LEVELS - qt->max_levels; i++)
     {
		cgc_printf("    >");
     }
	    cgc_printf("--| (x,y) = (%d,%d) | Alive=%d | Bomb=%d |\n", iter->px.point.x, iter->px.point.y, iter->px.is_alive, iter->px.bomb_set);
	    iter = iter->next;
	}
    }
    {
        qtree_t* tlv2;
        tlv2 = qt -> nw;
        char tlv1[] = "NW";
        cgc_qt_debug_print_tree(tlv2,tlv1);
    }
    {
        qtree_t* tlv4;
        tlv4 = qt -> ne;
        char tlv3[] = "NE";
        cgc_qt_debug_print_tree(tlv4,tlv3);
    }
    {
        qtree_t* tlv6;
        tlv6 = qt -> sw;
        char tlv5[] = "SW";
        cgc_qt_debug_print_tree(tlv6,tlv5);
    }
    {
        qtree_t* tlv8;
        tlv8 = qt -> se;
        char tlv7[] = "SE";
        cgc_qt_debug_print_tree(tlv8,tlv7);
    }
}

void fix_ingred_gld_0(){
}
void fix_ingred_gld_1_13_0(){
    {cgc_size_t tlv10; tlv10 = (cgc_size_t)(1); }
    {cgc_size_t tlv9; tlv9 = (cgc_size_t)(1); }
}
void fix_ingred_gld_1_13_1(){
    {cgc_size_t tlv10; tlv10 = (cgc_size_t)(sizeof ( pixel_list_t )); }
    {cgc_size_t tlv9; tlv9 = (cgc_size_t)(sizeof ( pixel_list_t )); }
}
void fix_ingred_gld_1_13(){
fix_ingred_gld_1_13_0();
fix_ingred_gld_1_13_1();
}
void fix_ingred_gld_1(){
fix_ingred_gld_1_13();
}
void fix_ingred_gld_2_1_0(){
    {cgc_size_t tlv1; tlv1 = (cgc_size_t)(sizeof ( coord_t ) * 8); }
}
void fix_ingred_gld_2_1(){
fix_ingred_gld_2_1_0();
}
void fix_ingred_gld_2(){
fix_ingred_gld_2_1();
}
void fix_ingred_gld_3_0_1(){
    {int i; i = (int)(0); }
    {int total_score; total_score = (int)(0); }
    {int score; score = (int)(0); }
    {int cells_hit; cells_hit = (int)(0); }
    {cgc_size_t tlv5; tlv5 = (cgc_size_t)(0); }
    {void * tlv3; tlv3 = (void *)(0); }
    {void * tlv2; tlv2 = (void *)(0); }
    {cgc_size_t tlv1; tlv1 = (cgc_size_t)(0); }
}
void fix_ingred_gld_3_0(){
fix_ingred_gld_3_0_1();
}
void fix_ingred_gld_3_1_5(){
int score;
    bzero(&score,sizeof(int));
    {int i; i = (int)(score); }
    {int total_score; total_score = (int)(score); }
    {int cells_hit; cells_hit = (int)(score); }
    {cgc_size_t tlv5; tlv5 = (cgc_size_t)(score); }
    {void * tlv3; tlv3 = (void *)(score); }
    {void * tlv2; tlv2 = (void *)(score); }
    {cgc_size_t tlv1; tlv1 = (cgc_size_t)(score); }
}
void fix_ingred_gld_3_1(){
fix_ingred_gld_3_1_5();
}
void fix_ingred_gld_3_4_0(){
    {int i; i = (int)(sizeof ( coord_t ) * 9); }
    {int total_score; total_score = (int)(sizeof ( coord_t ) * 9); }
    {int score; score = (int)(sizeof ( coord_t ) * 9); }
    {int cells_hit; cells_hit = (int)(sizeof ( coord_t ) * 9); }
    {cgc_size_t tlv5; tlv5 = (cgc_size_t)(sizeof ( coord_t ) * 9); }
    {void * tlv3; tlv3 = (void *)(sizeof ( coord_t ) * 9); }
    {void * tlv2; tlv2 = (void *)(sizeof ( coord_t ) * 9); }
    {cgc_size_t tlv1; tlv1 = (cgc_size_t)(sizeof ( coord_t ) * 9); }
}
void fix_ingred_gld_3_4(){
fix_ingred_gld_3_4_0();
}
void fix_ingred_gld_3_5_0(){
coord_t bomb_cells_ref;
    bzero(&bomb_cells_ref,1*sizeof(coord_t));
coord_t * bomb_cells = &bomb_cells_ref;
coord_t adj_cells_ref;
    bzero(&adj_cells_ref,1*sizeof(coord_t));
coord_t * adj_cells = &adj_cells_ref;
    {int i; i = (int)(bomb_cells); }
    {int total_score; total_score = (int)(bomb_cells); }
    {int score; score = (int)(bomb_cells); }
    {int cells_hit; cells_hit = (int)(bomb_cells); }
    {cgc_size_t tlv5; tlv5 = (cgc_size_t)(bomb_cells); }
    {void * tlv3; tlv3 = (void *)(bomb_cells); }
    {void * tlv2; tlv2 = (void *)(bomb_cells); }
    {cgc_size_t tlv1; tlv1 = (cgc_size_t)(bomb_cells); }
}
void fix_ingred_gld_3_5_1(){
coord_t bomb_cells_ref;
    bzero(&bomb_cells_ref,1*sizeof(coord_t));
coord_t * bomb_cells = &bomb_cells_ref;
coord_t adj_cells_ref;
    bzero(&adj_cells_ref,1*sizeof(coord_t));
coord_t * adj_cells = &adj_cells_ref;
    {int i; i = (int)(adj_cells); }
    {int total_score; total_score = (int)(adj_cells); }
    {int score; score = (int)(adj_cells); }
    {int cells_hit; cells_hit = (int)(adj_cells); }
    {cgc_size_t tlv5; tlv5 = (cgc_size_t)(adj_cells); }
    {void * tlv3; tlv3 = (void *)(adj_cells); }
    {void * tlv2; tlv2 = (void *)(adj_cells); }
    {cgc_size_t tlv1; tlv1 = (cgc_size_t)(adj_cells); }
}
void fix_ingred_gld_3_5_2(){
coord_t bomb_cells_ref;
    bzero(&bomb_cells_ref,1*sizeof(coord_t));
coord_t * bomb_cells = &bomb_cells_ref;
coord_t adj_cells_ref;
    bzero(&adj_cells_ref,1*sizeof(coord_t));
coord_t * adj_cells = &adj_cells_ref;
    {int i; i = (int)(sizeof ( coord_t ) * 8); }
    {int total_score; total_score = (int)(sizeof ( coord_t ) * 8); }
    {int score; score = (int)(sizeof ( coord_t ) * 8); }
    {int cells_hit; cells_hit = (int)(sizeof ( coord_t ) * 8); }
    {cgc_size_t tlv5; tlv5 = (cgc_size_t)(sizeof ( coord_t ) * 8); }
    {void * tlv3; tlv3 = (void *)(sizeof ( coord_t ) * 8); }
    {void * tlv2; tlv2 = (void *)(sizeof ( coord_t ) * 8); }
}
void fix_ingred_gld_3_5(){
fix_ingred_gld_3_5_0();
fix_ingred_gld_3_5_1();
fix_ingred_gld_3_5_2();
}
void fix_ingred_gld_3_7_13(){
int i;
    bzero(&i,sizeof(int));
    {int total_score; total_score = (int)(i); }
    {int score; score = (int)(i); }
    {int cells_hit; cells_hit = (int)(i); }
    {cgc_size_t tlv5; tlv5 = (cgc_size_t)(i); }
    {void * tlv3; tlv3 = (void *)(i); }
    {void * tlv2; tlv2 = (void *)(i); }
    {cgc_size_t tlv1; tlv1 = (cgc_size_t)(i); }
}
void fix_ingred_gld_3_7_14(){
int i;
    bzero(&i,sizeof(int));
    {int i; i = (int)(9); }
    {int total_score; total_score = (int)(9); }
    {int score; score = (int)(9); }
    {int cells_hit; cells_hit = (int)(9); }
    {cgc_size_t tlv5; tlv5 = (cgc_size_t)(9); }
    {void * tlv3; tlv3 = (void *)(9); }
    {void * tlv2; tlv2 = (void *)(9); }
    {cgc_size_t tlv1; tlv1 = (cgc_size_t)(9); }
}
void fix_ingred_gld_3_7(){
fix_ingred_gld_3_7_13();
fix_ingred_gld_3_7_14();
}
void fix_ingred_gld_3_10_1(){
int cells_hit;
    bzero(&cells_hit,sizeof(int));
int score;
    bzero(&score,sizeof(int));
    {int i; i = (int)(100 + cells_hit * score); }
    {int total_score; total_score = (int)(100 + cells_hit * score); }
    {cgc_size_t tlv5; tlv5 = (cgc_size_t)(100 + cells_hit * score); }
    {void * tlv3; tlv3 = (void *)(100 + cells_hit * score); }
    {void * tlv2; tlv2 = (void *)(100 + cells_hit * score); }
    {cgc_size_t tlv1; tlv1 = (cgc_size_t)(100 + cells_hit * score); }
}
void fix_ingred_gld_3_10(){
fix_ingred_gld_3_10_1();
}
void fix_ingred_gld_3(){
fix_ingred_gld_3_0();
fix_ingred_gld_3_1();
fix_ingred_gld_3_4();
fix_ingred_gld_3_5();
fix_ingred_gld_3_7();
fix_ingred_gld_3_10();
}
void fix_ingred_gld_4_0_0(){
    {int num_living_cells; num_living_cells = (int)(0); }
}
void fix_ingred_gld_4_0(){
fix_ingred_gld_4_0_0();
}
void fix_ingred_gld_4_2_2(){
int i;
    bzero(&i,sizeof(int));
    {int num_living_cells; num_living_cells = (int)(i); }
}
void fix_ingred_gld_4_2_3(){
int i;
    bzero(&i,sizeof(int));
    {int i; i = (int)(8); }
    {int num_living_cells; num_living_cells = (int)(8); }
}
void fix_ingred_gld_4_2(){
fix_ingred_gld_4_2_2();
fix_ingred_gld_4_2_3();
}
void fix_ingred_gld_4_5_1(){
int num_living_cells;
    bzero(&num_living_cells,sizeof(int));
    {int i; i = (int)(num_living_cells); }
}
void fix_ingred_gld_4_5_2(){
int num_living_cells;
    bzero(&num_living_cells,sizeof(int));
    {int i; i = (int)(3); }
    {int num_living_cells; num_living_cells = (int)(3); }
}
void fix_ingred_gld_4_5(){
fix_ingred_gld_4_5_1();
fix_ingred_gld_4_5_2();
}
void fix_ingred_gld_4(){
fix_ingred_gld_4_0();
fix_ingred_gld_4_2();
fix_ingred_gld_4_5();
}
void fix_ingred_gld_5_0_0(){
    {cgc_size_t tlv4; tlv4 = (cgc_size_t)(0); }
    {cgc_size_t tlv3; tlv3 = (cgc_size_t)(0); }
    {cgc_size_t tlv6; tlv6 = (cgc_size_t)(0); }
    {cgc_size_t tlv10; tlv10 = (cgc_size_t)(0); }
    {cgc_size_t tlv9; tlv9 = (cgc_size_t)(0); }
    {cgc_size_t tlv13; tlv13 = (cgc_size_t)(0); }
    {cgc_size_t tlv12; tlv12 = (cgc_size_t)(0); }
}
void fix_ingred_gld_5_0(){
fix_ingred_gld_5_0_0();
}
void fix_ingred_gld_5_2_6(){
int i;
    bzero(&i,sizeof(int));
    {cgc_size_t tlv4; tlv4 = (cgc_size_t)(i); }
    {cgc_size_t tlv3; tlv3 = (cgc_size_t)(i); }
    {cgc_size_t tlv6; tlv6 = (cgc_size_t)(i); }
    {cgc_size_t tlv10; tlv10 = (cgc_size_t)(i); }
    {cgc_size_t tlv9; tlv9 = (cgc_size_t)(i); }
    {cgc_size_t tlv13; tlv13 = (cgc_size_t)(i); }
    {cgc_size_t tlv12; tlv12 = (cgc_size_t)(i); }
}
void fix_ingred_gld_5_2_7(){
int i;
    bzero(&i,sizeof(int));
    {cgc_size_t tlv4; tlv4 = (cgc_size_t)(8); }
    {cgc_size_t tlv3; tlv3 = (cgc_size_t)(8); }
    {cgc_size_t tlv6; tlv6 = (cgc_size_t)(8); }
    {cgc_size_t tlv5; tlv5 = (cgc_size_t)(8); }
    {cgc_size_t tlv10; tlv10 = (cgc_size_t)(8); }
    {cgc_size_t tlv9; tlv9 = (cgc_size_t)(8); }
    {cgc_size_t tlv13; tlv13 = (cgc_size_t)(8); }
    {cgc_size_t tlv12; tlv12 = (cgc_size_t)(8); }
}
void fix_ingred_gld_5_2(){
fix_ingred_gld_5_2_6();
fix_ingred_gld_5_2_7();
}
void fix_ingred_gld_5_9_0(){
    {int i; i = (int)(1); }
    {int num_living_cells; num_living_cells = (int)(1); }
    {cgc_size_t tlv4; tlv4 = (cgc_size_t)(1); }
    {cgc_size_t tlv3; tlv3 = (cgc_size_t)(1); }
    {cgc_size_t tlv6; tlv6 = (cgc_size_t)(1); }
    {cgc_size_t tlv5; tlv5 = (cgc_size_t)(1); }
    {cgc_size_t tlv13; tlv13 = (cgc_size_t)(1); }
    {cgc_size_t tlv12; tlv12 = (cgc_size_t)(1); }
}
void fix_ingred_gld_5_9_1(){
    {int i; i = (int)(sizeof ( coord_list_t )); }
    {int num_living_cells; num_living_cells = (int)(sizeof ( coord_list_t )); }
    {cgc_size_t tlv4; tlv4 = (cgc_size_t)(sizeof ( coord_list_t )); }
    {cgc_size_t tlv3; tlv3 = (cgc_size_t)(sizeof ( coord_list_t )); }
    {cgc_size_t tlv6; tlv6 = (cgc_size_t)(sizeof ( coord_list_t )); }
    {cgc_size_t tlv5; tlv5 = (cgc_size_t)(sizeof ( coord_list_t )); }
    {cgc_size_t tlv10; tlv10 = (cgc_size_t)(sizeof ( coord_list_t )); }
    {cgc_size_t tlv9; tlv9 = (cgc_size_t)(sizeof ( coord_list_t )); }
    {cgc_size_t tlv13; tlv13 = (cgc_size_t)(sizeof ( coord_list_t )); }
    {cgc_size_t tlv12; tlv12 = (cgc_size_t)(sizeof ( coord_list_t )); }
}
void fix_ingred_gld_5_9(){
fix_ingred_gld_5_9_0();
fix_ingred_gld_5_9_1();
}
void fix_ingred_gld_5_12_1(){
    {int i; i = (int)(sizeof ( pixel_list_t )); }
    {int num_living_cells; num_living_cells = (int)(sizeof ( pixel_list_t )); }
    {cgc_size_t tlv4; tlv4 = (cgc_size_t)(sizeof ( pixel_list_t )); }
    {cgc_size_t tlv3; tlv3 = (cgc_size_t)(sizeof ( pixel_list_t )); }
    {cgc_size_t tlv6; tlv6 = (cgc_size_t)(sizeof ( pixel_list_t )); }
    {cgc_size_t tlv5; tlv5 = (cgc_size_t)(sizeof ( pixel_list_t )); }
    {cgc_size_t tlv13; tlv13 = (cgc_size_t)(sizeof ( pixel_list_t )); }
    {cgc_size_t tlv12; tlv12 = (cgc_size_t)(sizeof ( pixel_list_t )); }
}
void fix_ingred_gld_5_12(){
fix_ingred_gld_5_12_1();
}
void fix_ingred_gld_5_18_8(){
int num_living_cells;
    bzero(&num_living_cells,sizeof(int));
    {cgc_size_t tlv4; tlv4 = (cgc_size_t)(num_living_cells); }
    {cgc_size_t tlv3; tlv3 = (cgc_size_t)(num_living_cells); }
    {cgc_size_t tlv6; tlv6 = (cgc_size_t)(num_living_cells); }
    {cgc_size_t tlv5; tlv5 = (cgc_size_t)(num_living_cells); }
    {cgc_size_t tlv10; tlv10 = (cgc_size_t)(num_living_cells); }
    {cgc_size_t tlv9; tlv9 = (cgc_size_t)(num_living_cells); }
    {cgc_size_t tlv13; tlv13 = (cgc_size_t)(num_living_cells); }
    {cgc_size_t tlv12; tlv12 = (cgc_size_t)(num_living_cells); }
}
void fix_ingred_gld_5_18_9(){
int num_living_cells;
    bzero(&num_living_cells,sizeof(int));
    {int i; i = (int)(2); }
    {int num_living_cells; num_living_cells = (int)(2); }
    {cgc_size_t tlv4; tlv4 = (cgc_size_t)(2); }
    {cgc_size_t tlv3; tlv3 = (cgc_size_t)(2); }
    {cgc_size_t tlv6; tlv6 = (cgc_size_t)(2); }
    {cgc_size_t tlv5; tlv5 = (cgc_size_t)(2); }
    {cgc_size_t tlv10; tlv10 = (cgc_size_t)(2); }
    {cgc_size_t tlv9; tlv9 = (cgc_size_t)(2); }
    {cgc_size_t tlv13; tlv13 = (cgc_size_t)(2); }
    {cgc_size_t tlv12; tlv12 = (cgc_size_t)(2); }
}
void fix_ingred_gld_5_18_11(){
int num_living_cells;
    bzero(&num_living_cells,sizeof(int));
    {cgc_size_t tlv4; tlv4 = (cgc_size_t)(3); }
    {cgc_size_t tlv3; tlv3 = (cgc_size_t)(3); }
    {cgc_size_t tlv6; tlv6 = (cgc_size_t)(3); }
    {cgc_size_t tlv5; tlv5 = (cgc_size_t)(3); }
    {cgc_size_t tlv10; tlv10 = (cgc_size_t)(3); }
    {cgc_size_t tlv9; tlv9 = (cgc_size_t)(3); }
    {cgc_size_t tlv13; tlv13 = (cgc_size_t)(3); }
    {cgc_size_t tlv12; tlv12 = (cgc_size_t)(3); }
}
void fix_ingred_gld_5_18(){
fix_ingred_gld_5_18_8();
fix_ingred_gld_5_18_9();
fix_ingred_gld_5_18_11();
}
void fix_ingred_gld_5(){
fix_ingred_gld_5_0();
fix_ingred_gld_5_2();
fix_ingred_gld_5_9();
fix_ingred_gld_5_12();
fix_ingred_gld_5_18();
}
void fix_ingred_gld_6(){
}
void fix_ingred_gld_7_0_0(){
qtree_t qt_ref;
    bzero(&qt_ref,1*sizeof(qtree_t));
qtree_t * qt = &qt_ref;
    {unsigned int width; width = (unsigned int)(1 << ( qt -> max_levels - 1 )); }
    {unsigned int startx; startx = (unsigned int)(1 << ( qt -> max_levels - 1 )); }
    {unsigned int starty; starty = (unsigned int)(1 << ( qt -> max_levels - 1 )); }
    {unsigned int endx; endx = (unsigned int)(1 << ( qt -> max_levels - 1 )); }
    {unsigned int endy; endy = (unsigned int)(1 << ( qt -> max_levels - 1 )); }
    {int tlv2; tlv2 = (int)(1 << ( qt -> max_levels - 1 )); }
    {int tlv4; tlv4 = (int)(1 << ( qt -> max_levels - 1 )); }
    {int tlv6; tlv6 = (int)(1 << ( qt -> max_levels - 1 )); }
    {int tlv8; tlv8 = (int)(1 << ( qt -> max_levels - 1 )); }
}
void fix_ingred_gld_7_0(){
fix_ingred_gld_7_0_0();
}
void fix_ingred_gld_7_2_0(){
qtree_t qt_ref;
    bzero(&qt_ref,1*sizeof(qtree_t));
qtree_t * qt = &qt_ref;
    {unsigned int width; width = (unsigned int)(qt -> max_levels - 1); }
    {unsigned int startx; startx = (unsigned int)(qt -> max_levels - 1); }
    {unsigned int starty; starty = (unsigned int)(qt -> max_levels - 1); }
    {unsigned int endx; endx = (unsigned int)(qt -> max_levels - 1); }
    {unsigned int endy; endy = (unsigned int)(qt -> max_levels - 1); }
    {int tlv2; tlv2 = (int)(qt -> max_levels - 1); }
    {int tlv4; tlv4 = (int)(qt -> max_levels - 1); }
    {int tlv6; tlv6 = (int)(qt -> max_levels - 1); }
    {int tlv8; tlv8 = (int)(qt -> max_levels - 1); }
}
void fix_ingred_gld_7_2(){
fix_ingred_gld_7_2_0();
}
void fix_ingred_gld_7(){
fix_ingred_gld_7_0();
fix_ingred_gld_7_2();
}
void fix_ingred_gld_8(){
}
void fix_ingred_gld_9_8_0(){
qtree_t qt_ref;
    bzero(&qt_ref,1*sizeof(qtree_t));
qtree_t * qt = &qt_ref;
    {int tlv1; tlv1 = (int)(qt -> nw); }
    {int tlv4; tlv4 = (int)(qt -> nw); }
    {int tlv7; tlv7 = (int)(qt -> nw); }
    {int tlv10; tlv10 = (int)(qt -> nw); }
    {void * tlv13; tlv13 = (void *)(qt -> nw); }
    {void * tlv14; tlv14 = (void *)(qt -> nw); }
    {void * tlv15; tlv15 = (void *)(qt -> nw); }
    {void * tlv16; tlv16 = (void *)(qt -> nw); }
}
void fix_ingred_gld_9_8(){
fix_ingred_gld_9_8_0();
}
void fix_ingred_gld_9_9_0(){
qtree_t qt_ref;
    bzero(&qt_ref,1*sizeof(qtree_t));
qtree_t * qt = &qt_ref;
    {int tlv1; tlv1 = (int)(qt -> ne); }
    {int tlv4; tlv4 = (int)(qt -> ne); }
    {int tlv7; tlv7 = (int)(qt -> ne); }
    {int tlv10; tlv10 = (int)(qt -> ne); }
    {void * tlv13; tlv13 = (void *)(qt -> ne); }
    {void * tlv14; tlv14 = (void *)(qt -> ne); }
    {void * tlv15; tlv15 = (void *)(qt -> ne); }
    {void * tlv16; tlv16 = (void *)(qt -> ne); }
}
void fix_ingred_gld_9_9(){
fix_ingred_gld_9_9_0();
}
void fix_ingred_gld_9_10_0(){
qtree_t qt_ref;
    bzero(&qt_ref,1*sizeof(qtree_t));
qtree_t * qt = &qt_ref;
    {int tlv1; tlv1 = (int)(qt -> sw); }
    {int tlv4; tlv4 = (int)(qt -> sw); }
    {int tlv7; tlv7 = (int)(qt -> sw); }
    {int tlv10; tlv10 = (int)(qt -> sw); }
    {void * tlv13; tlv13 = (void *)(qt -> sw); }
    {void * tlv14; tlv14 = (void *)(qt -> sw); }
    {void * tlv15; tlv15 = (void *)(qt -> sw); }
    {void * tlv16; tlv16 = (void *)(qt -> sw); }
}
void fix_ingred_gld_9_10(){
fix_ingred_gld_9_10_0();
}
void fix_ingred_gld_9_11_0(){
qtree_t qt_ref;
    bzero(&qt_ref,1*sizeof(qtree_t));
qtree_t * qt = &qt_ref;
    {int tlv1; tlv1 = (int)(qt -> se); }
    {int tlv4; tlv4 = (int)(qt -> se); }
    {int tlv7; tlv7 = (int)(qt -> se); }
    {int tlv10; tlv10 = (int)(qt -> se); }
    {void * tlv13; tlv13 = (void *)(qt -> se); }
    {void * tlv14; tlv14 = (void *)(qt -> se); }
    {void * tlv15; tlv15 = (void *)(qt -> se); }
    {void * tlv16; tlv16 = (void *)(qt -> se); }
}
void fix_ingred_gld_9_11(){
fix_ingred_gld_9_11_0();
}
void fix_ingred_gld_9(){
fix_ingred_gld_9_8();
fix_ingred_gld_9_9();
fix_ingred_gld_9_10();
fix_ingred_gld_9_11();
}
void fix_ingred_gld_10(){
}
void fix_ingred_gld_11_1_0(){
    {cgc_size_t tlv1; tlv1 = (cgc_size_t)(sizeof ( qtree_t )); }
}
void fix_ingred_gld_11_1(){
fix_ingred_gld_11_1_0();
}
void fix_ingred_gld_11(){
fix_ingred_gld_11_1();
}
void fix_ingred_gld_12_8_0(){
    {cgc_size_t tlv8; tlv8 = (cgc_size_t)(1); }
}
void fix_ingred_gld_12_8_1(){
    {cgc_size_t tlv8; tlv8 = (cgc_size_t)(sizeof ( pixel_list_t )); }
}
void fix_ingred_gld_12_8(){
fix_ingred_gld_12_8_0();
fix_ingred_gld_12_8_1();
}
void fix_ingred_gld_12(){
fix_ingred_gld_12_8();
}
void fix_ingred_gld_13(){
}
void fix_ingred_gld_14_0_0(){
    {cgc_size_t tlv24; tlv24 = (cgc_size_t)(0); }
    {cgc_size_t tlv23; tlv23 = (cgc_size_t)(0); }
}
void fix_ingred_gld_14_0(){
fix_ingred_gld_14_0_0();
}
void fix_ingred_gld_14_1_17(){
int num_steps;
    bzero(&num_steps,sizeof(int));
int i;
    bzero(&i,sizeof(int));
    {cgc_size_t tlv24; tlv24 = (cgc_size_t)(i); }
    {cgc_size_t tlv23; tlv23 = (cgc_size_t)(i); }
}
void fix_ingred_gld_14_1_18(){
int num_steps;
    bzero(&num_steps,sizeof(int));
int i;
    bzero(&i,sizeof(int));
    {int i; i = (int)(num_steps); }
    {int total_score; total_score = (int)(num_steps); }
    {cgc_size_t tlv24; tlv24 = (cgc_size_t)(num_steps); }
    {cgc_size_t tlv23; tlv23 = (cgc_size_t)(num_steps); }
}
void fix_ingred_gld_14_1(){
fix_ingred_gld_14_1_17();
fix_ingred_gld_14_1_18();
}
void fix_ingred_gld_14_12_0(){
    {int total_score; total_score = (int)(1); }
    {cgc_size_t tlv24; tlv24 = (cgc_size_t)(1); }
    {cgc_size_t tlv23; tlv23 = (cgc_size_t)(1); }
}
void fix_ingred_gld_14_12_1(){
    {int total_score; total_score = (int)(sizeof ( pixel_list_t )); }
    {cgc_size_t tlv24; tlv24 = (cgc_size_t)(sizeof ( pixel_list_t )); }
    {cgc_size_t tlv23; tlv23 = (cgc_size_t)(sizeof ( pixel_list_t )); }
}
void fix_ingred_gld_14_12(){
fix_ingred_gld_14_12_0();
fix_ingred_gld_14_12_1();
}
void fix_ingred_gld_14(){
fix_ingred_gld_14_0();
fix_ingred_gld_14_1();
fix_ingred_gld_14_12();
}
void fix_ingred_gld_15(){
}
void fix_ingred_gld_16(){
}
void fix_ingred_gld_17_2_0(){
    {int tlv2; tlv2 = (int)(MAX_LEVELS); }
}
void fix_ingred_gld_17_2(){
fix_ingred_gld_17_2_0();
}
void fix_ingred_gld_17(){
fix_ingred_gld_17_2();
}
void fix_ingred_gld_18(){
}
void fix_ingred_gld_19(){
}
void fix_ingred_gld_20(){
}
void fix_ingred_gld_21_2_0(){
    {char* tlv1 ; tlv1  = (char*)(0); }
    {char* tlv3 ; tlv3  = (char*)(0); }
    {char* tlv5 ; tlv5  = (char*)(0); }
    {char* tlv7 ; tlv7  = (char*)(0); }
}
void fix_ingred_gld_21_2(){
fix_ingred_gld_21_2_0();
}
void fix_ingred_gld_21_4_7(){
int i;
    bzero(&i,sizeof(int));
qtree_t qt_ref;
    bzero(&qt_ref,1*sizeof(qtree_t));
qtree_t * qt = &qt_ref;
    {char* tlv1 ; tlv1  = (char*)(i); }
    {char* tlv3 ; tlv3  = (char*)(i); }
    {char* tlv5 ; tlv5  = (char*)(i); }
    {char* tlv7 ; tlv7  = (char*)(i); }
}
void fix_ingred_gld_21_4_8(){
int i;
    bzero(&i,sizeof(int));
qtree_t qt_ref;
    bzero(&qt_ref,1*sizeof(qtree_t));
qtree_t * qt = &qt_ref;
    {char* tlv1 ; tlv1  = (char*)(MAX_LEVELS - qt -> max_levels); }
    {char* tlv3 ; tlv3  = (char*)(MAX_LEVELS - qt -> max_levels); }
    {char* tlv5 ; tlv5  = (char*)(MAX_LEVELS - qt -> max_levels); }
    {char* tlv7 ; tlv7  = (char*)(MAX_LEVELS - qt -> max_levels); }
    {int i; i = (int)(MAX_LEVELS - qt -> max_levels); }
}
void fix_ingred_gld_21_4(){
fix_ingred_gld_21_4_7();
fix_ingred_gld_21_4_8();
}
void fix_ingred_gld_21(){
fix_ingred_gld_21_2();
fix_ingred_gld_21_4();
}
