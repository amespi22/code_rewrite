

#include "libcgc.h"
#include "cgc_stdarg.h"
#include "cgc_stdlib.h"
#include "cgc_string.h"
#include "cgc_movie.h"
void cgc_quit();
void cgc_print_movie_detail(int, movie_t *);
movie_t default_movies[] = {
    {"The Shawshank Redemption", "Two imprisoned men bond over a number of years, finding solace and eventual\n     redemption through acts of common decency.", 1994, 93, G_OTHER, R_R, NULL},
    {"The Godfather", "The aging patriarch of an organized crime dynasty transfers control of his clandestine\n     empire to his reluctant son.", 1972, 92, G_OTHER, R_R, NULL},
    {"The Dark Knight", "When Batman, Gordon have Harvey Dent launch an assault on the mob, they let the clown\n     out of the box, the Joker, bent on turning Gotham on itself and bringing any heroes\n     down to his level.", 2008, 90, G_ACTION, R_PG13, NULL},
    {"Inception", "A thief who steals corporate secrets through use of dream-sharing technology is given the\n     inverse task of planting an idea into the mind of a CEO.", 2010, 88, G_ACTION, R_PG13, NULL},
    {"The Matrix", "A computer hacker learns from mysterious rebels about the true nature of his reality and\n     his role in the war against its controllers.", 1999, 87, G_ACTION, R_R, NULL},
    {"Modern Times", "The Tramp struggles to live in modern industrial society with the help of a young\n     homeless woman.", 1936, 86, G_COMEDY, R_G, NULL},
    {"About Time", "At the age of 21, Tim discovers he can travel in time and change what happens and has\n     happened in his own life. His decision to make his world a better place by getting\n     a girlfriend turns out not to be as easy as you might think.", 2013, 78, G_ROMANCE, R_R, NULL},
    {"Yes Man", "A guy challenges himself to say \"yes\" to everything for an entire year.", 2008, 69, G_COMEDY, R_PG13, NULL},
    {"The Conjuring", "Paranormal investigators Ed and Lorraine Warren work to help a family terrorized\n     by a dark presence in their farmhouse.", 2013, 75, G_HORROR, R_R, NULL},
    {"The Lion King", "Lion cub and future king Simba searches for his identity. His eagerness to please others\n     and penchant for testing his boundaries sometimes gets him into trouble.", 1994, 85, G_OTHER, R_G, NULL},
};

char g_password[21];
unsigned int cgc_g_num_movies = 0;
movie_list_t movies_full;
movie_list_t movies_rented;
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

void fix_ingred_main_0_2_1();
void fix_ingred_main_0_2_2();
void fix_ingred_main_0_2_3();
void fix_ingred_main_0_2();
void fix_ingred_main_0_3_0();
void fix_ingred_main_0_3_1();
void fix_ingred_main_0_3();
void fix_ingred_main_0_4_0();
void fix_ingred_main_0_4_1();
void fix_ingred_main_0_4();
void fix_ingred_main_0_8_0();
void fix_ingred_main_0_8();
void fix_ingred_main_0_10_0();
void fix_ingred_main_0_10_1();
void fix_ingred_main_0_10();
void fix_ingred_main_0_12_0();
void fix_ingred_main_0_12();
void fix_ingred_main_0_14_0();
void fix_ingred_main_0_14();
void fix_ingred_main_0_16_0();
void fix_ingred_main_0_16();
void fix_ingred_main_0_17_0();
void fix_ingred_main_0_17();
void fix_ingred_main_0();
void cgc_initialize()
{
if (fix_ingred_enable){ fix_ingred_main_0(); };
    unsigned int i;
    unsigned int rand;
    char c;
    movie_t *movie;
    {
        const char tlv1 [ ] = "\n   . . . Initializing the inventory . . .\n         (movie info from IMDb.com)\n";
        cgc_printf(tlv1);
    }
    unsigned long tlv_size_0;
    tlv_size_0 = sizeof ( g_password ) / sizeof ( g_password [ 0 ] );
    for (i = 0; i <= tlv_size_0; ++i) {
 {
     void* tlv5;
     tlv5 = & c;
     cgc_size_t tlv4;
     tlv4 = sizeof ( c );
     cgc_size_t* tlv3;
     tlv3 = NULL;
    	cgc_random(tlv5,tlv4,tlv3);
 }
 {
     void* tlv8;
     tlv8 = & rand;
     cgc_size_t tlv7;
     tlv7 = sizeof ( rand );
     cgc_size_t* tlv6;
     tlv6 = NULL;
    	cgc_random(tlv8,tlv7,tlv6);
 }
	if (c & 1) {
	    g_password[i] = 'A' + (rand % 26);
	} else {
	    g_password[i] = 'a' + (rand % 26);
	}
    }
    g_password[i] = '\0';
    tlv_size_0= sizeof(default_movies)/sizeof(default_movies[0]);
    for (i = 0; i < tlv_size_0; ++i) {
 {
     cgc_size_t tlv18;
     tlv18 = sizeof ( movie_t );
    	movie = (movie_t *) cgc_malloc(tlv18);
 }
	if (movie == NULL) {
	    goto fail;
	}
 {
     void* tlv11;
     tlv11 = movie;
     int tlv10;
     tlv10 = '\0';
     cgc_size_t tlv9;
     tlv9 = sizeof ( movie_t );
    	cgc_memset(tlv11,tlv10,tlv9);
 }
 {
     cgc_size_t tlv19;
     {
         const char* tlv21 = default_movies [ i ] . title;
         tlv19 = cgc_strlen(tlv21) + 1;
     }
    	movie->title = (char *) cgc_malloc(tlv19);
 }
 {
     cgc_size_t tlv20;
     {
         const char* tlv22 = default_movies [ i ] . desc;
         tlv20 = cgc_strlen(tlv22) + 1;
     }
    	movie->desc = (char *) cgc_malloc(tlv20);
 }
	if (movie->title == NULL || movie->desc == NULL) {
	    goto fail;
	}
 {
     char* tlv13;
      tlv13 = movie -> title;
     const char* tlv12 = default_movies [ i ] . title;
    	cgc_strcpy(tlv13,tlv12);
 }
 {
     char* tlv15;
      tlv15 = movie -> desc;
     const char* tlv14 = default_movies [ i ] . desc;
    	cgc_strcpy(tlv15,tlv14);
 }
	movie->year = default_movies[i].year;
	movie->score = default_movies[i].score;
	movie->genre = default_movies[i].genre;
	movie->rating = default_movies[i].rating;
	movie->print_info = &cgc_print_movie_detail;
 {
     movie_list_t* tlv17;
     tlv17 = & movies_full;
     movie_t* tlv16;
     tlv16 = movie;
    	cgc_movie_add(tlv17,tlv16);
 }
    }
    return;
  fail:
    {
        const char tlv2 [ ] = "[ERROR] Initialization failed. Exit.\n";
        cgc_printf(tlv2);
    }
    cgc_quit();
}

void fix_ingred_main_1_0_0();
void fix_ingred_main_1_0();
void fix_ingred_main_1_1_1();
void fix_ingred_main_1_1_2();
void fix_ingred_main_1_1_3();
void fix_ingred_main_1_1();
void fix_ingred_main_1_2_0();
void fix_ingred_main_1_2_1();
void fix_ingred_main_1_2_2();
void fix_ingred_main_1_2();
void fix_ingred_main_1_3_4();
void fix_ingred_main_1_3_5();
void fix_ingred_main_1_3_6();
void fix_ingred_main_1_3();
void fix_ingred_main_1_4_4();
void fix_ingred_main_1_4_5();
void fix_ingred_main_1_4();
void fix_ingred_main_1();
int cgc_readuntil(int fd, char *buf, cgc_size_t len, char delim)
{
if (fix_ingred_enable){ fix_ingred_main_1(); };
    cgc_size_t i;
    char* c;
     c = buf;
    for (i = 0; i < len; ++i) {
	cgc_size_t rx;
 int tlv1;
 {
     int tlv5;
     tlv5 = fd;
     void* tlv4;
     tlv4 = c;
     cgc_size_t tlv3;
     tlv3 = 1;
     cgc_size_t* tlv2;
     tlv2 = & rx;
     tlv1 = cgc_receive(tlv5,tlv4,tlv3,tlv2);
 }
	if (tlv1 != 0 || rx == 0) {
	    break;
	}
	if (*(c++) == delim) {
	    break;
	}
    }
    *(c - 1) = '\0';
    return c - buf;
}

void fix_ingred_main_2_3_0();
void fix_ingred_main_2_3();
void fix_ingred_main_2_4_0();
void fix_ingred_main_2_4();
void fix_ingred_main_2_5_0();
void fix_ingred_main_2_5();
void fix_ingred_main_2_6_0();
void fix_ingred_main_2_6();
void fix_ingred_main_2_7_0();
void fix_ingred_main_2_7();
void fix_ingred_main_2_9_0();
void fix_ingred_main_2_9();
void fix_ingred_main_2_10_0();
void fix_ingred_main_2_10();
void fix_ingred_main_2_11_0();
void fix_ingred_main_2_11();
void fix_ingred_main_2_12_0();
void fix_ingred_main_2_12();
void fix_ingred_main_2_13_0();
void fix_ingred_main_2_13();
void fix_ingred_main_2();
void cgc_print_movie_detail(int id, movie_t * movie)
{
if (fix_ingred_enable){ fix_ingred_main_2(); };
    char *rating_str;
    char *genre_str;
    char format[] = "[%d] %s (%d, %s) - %s [%d/100]\n  => %s\n";
    if (movie) {
	switch (movie->rating) {
	case R_G:
	    {
		rating_str = "G";
	    }
	    break;
	case R_PG:
	    {
		rating_str = "PG";
	    }
	    break;
	case R_PG13:
	    {
		rating_str = "PG13";
	    }
	    break;
	case R_R:
	    {
		rating_str = "R";
	    }
	    break;
	default:
	    {
		rating_str = "Unknown";
	    }
	    break;
	}
	switch (movie->genre) {
	case G_ACTION:
	    {
		genre_str = "Action";
	    }
	    break;
	case G_ROMANCE:
	    {
		genre_str = "Romance";
	    }
	    break;
	case G_COMEDY:
	    {
		genre_str = "Comedy";
	    }
	    break;
	case G_HORROR:
	    {
		genre_str = "Horror";
	    }
	    break;
	default:
	    {
		genre_str = "Other";
	    }
	    break;
	}
	cgc_printf(format, id, movie->title, movie->year, rating_str, genre_str, movie->score, movie->desc);
    }
}

void fix_ingred_main_3_0_0();
void fix_ingred_main_3_0();
void fix_ingred_main_3();
void cgc_list_movies()
{
if (fix_ingred_enable){ fix_ingred_main_3(); };
    int num_movies;
    num_movies = 0;
    movie_node_t *node;

    {
        const char tlv1 [ ] = "\nMovies (Full)\n--------------\n";
        cgc_printf(tlv1);
    }
    for (node = movies_full; node != NULL; node = node->next) {
	num_movies++;
	node->movie->print_info(num_movies, node->movie);
    }
    cgc_printf("--------------\n%d movie(s)\n", num_movies);

    num_movies = 0;
    {
        const char tlv2 [ ] = "\nMovies (Rented)\n--------------\n";
        cgc_printf(tlv2);
    }
    for (node = movies_rented; node != NULL; node = node->next) {
	num_movies++;
	node->movie->print_info(num_movies, node->movie);
    }
    cgc_printf("--------------\n%d movie(s)\n", num_movies);
}

void fix_ingred_main_4_0_0();
void fix_ingred_main_4_0();
void fix_ingred_main_4_3_1();
void fix_ingred_main_4_3();
void fix_ingred_main_4_7_0();
void fix_ingred_main_4_7_1();
void fix_ingred_main_4_7_2();
void fix_ingred_main_4_7_3();
void fix_ingred_main_4_7();
void fix_ingred_main_4_8_1();
void fix_ingred_main_4_8_2();
void fix_ingred_main_4_8();
void fix_ingred_main_4_9_1();
void fix_ingred_main_4_9();
void fix_ingred_main_4_10_1();
void fix_ingred_main_4_10_2();
void fix_ingred_main_4_10();
void fix_ingred_main_4_12_1();
void fix_ingred_main_4_12();
void fix_ingred_main_4_13_1();
void fix_ingred_main_4_13();
void fix_ingred_main_4_17_2();
void fix_ingred_main_4_17();
void fix_ingred_main_4();
void cgc_rent_movie()
{
if (fix_ingred_enable){ fix_ingred_main_4(); };
    movie_node_t *node;
    unsigned int movie_id;
    unsigned int num_movies;
    num_movies = 0;
    char buf[256];

    {
        const char tlv3 [ ] = "\nMovies (Full)\n--------------\n";
        cgc_printf(tlv3);
    }
    for (node = movies_full; node != NULL; node = node->next) {
	num_movies++;
	node->movie->print_info(num_movies, node->movie);
    }
    cgc_printf("--------------\n%d movie(s)\n", num_movies);
    if (num_movies == 0) {

 {
     const char tlv12 [ ] = "[ERROR] Movie list is empty. Please try again later.\n";
    	cgc_printf(tlv12);
 }
	return;
    }

    while (1) {
 {
     const char tlv13 [ ] = "Enter movie id: ";
    	cgc_printf(tlv13);
 }
 int tlv2;
 {
     int tlv19;
     tlv19 = STDIN;
     char* tlv18;
      tlv18 = buf;
     cgc_size_t tlv17;
     tlv17 = sizeof ( buf );
     char tlv16;
     tlv16 = '\n';
     tlv2 = cgc_readuntil(tlv19,tlv18,tlv17,tlv16);
 }
	if (tlv2 < 0) {
	    return;
	}
 {
     const char* tlv22 = buf;
     char** tlv21;
      tlv21 = NULL;
     int tlv20;
     tlv20 = 10;
    	movie_id = cgc_strtoul(tlv22,tlv21,tlv20);
 }
	if (movie_id >= 1 && movie_id <= num_movies) {
	    break;
	}
 {
     const char tlv14 [ ] = "[ERROR] Invalid movie id. Try again.\n";
    	cgc_printf(tlv14);
 }
    }

    movie_node_t* tmp;
    {
        movie_list_t tlv5;
        tlv5 = movies_full;
        int tlv4;
        tlv4 = movie_id;
        tmp = cgc_movie_find_by_id(tlv5,tlv4);
    }
    movie_t* movie;
    movie = tmp -> movie;
    {
        movie_list_t tlv7;
        tlv7 = movies_rented;
        char* tlv6;
         tlv6 = movie -> title;
        tmp = cgc_movie_find(tlv7,tlv6);
    }
    if (tmp) {
	cgc_printf("Sorry, [%s] is already rented at this time. Please try again later.\n", tmp->movie->title);
	return;
    }

    {
        movie_list_t tlv9;
        tlv9 = movies_full;
        int tlv8;
        tlv8 = movie_id;
        tmp = cgc_movie_find_by_id(tlv9,tlv8);
    }
    int tlv1;
    {
        movie_list_t* tlv11;
        tlv11 = & movies_rented;
        movie_t* tlv10;
        tlv10 = tmp -> movie;
        tlv1 = cgc_movie_add(tlv11,tlv10);
    }
    if (tlv1 != 0) {
 {
     const char tlv15 [ ] = "[ERROR] Failed to rent. Please try again later.\n";
    	cgc_printf(tlv15);
 }
    } else {
	cgc_printf("Successfully rented [%s]! Enjoy!\n", tmp->movie->title);
    }
}

void fix_ingred_main_5_0_0();
void fix_ingred_main_5_0();
void fix_ingred_main_5_3_1();
void fix_ingred_main_5_3();
void fix_ingred_main_5_7_0();
void fix_ingred_main_5_7_1();
void fix_ingred_main_5_7_2();
void fix_ingred_main_5_7_3();
void fix_ingred_main_5_7();
void fix_ingred_main_5_8_1();
void fix_ingred_main_5_8_2();
void fix_ingred_main_5_8();
void fix_ingred_main_5_9_1();
void fix_ingred_main_5_9();
void fix_ingred_main_5_10_1();
void fix_ingred_main_5_10_2();
void fix_ingred_main_5_10();
void fix_ingred_main_5_12_1();
void fix_ingred_main_5_12();
void fix_ingred_main_5_16_1();
void fix_ingred_main_5_16();
void fix_ingred_main_5();
void cgc_return_movie()
{
if (fix_ingred_enable){ fix_ingred_main_5(); };
    char buf[256];
    unsigned int movie_id;
    unsigned int num_movies;
    num_movies = 0;
    movie_node_t *node;

    {
        const char tlv3 [ ] = "\nMovies (Rented)\n--------------\n";
        cgc_printf(tlv3);
    }
    for (node = movies_rented; node != NULL; node = node->next) {
	num_movies++;
	node->movie->print_info(num_movies, node->movie);
    }
    cgc_printf("--------------\n%d movie(s)\n", num_movies);
    if (num_movies == 0) {
 {
     const char tlv8 [ ] = "[ERROR] All the movies are in our inventory.\n";
    	cgc_printf(tlv8);
 }
	return;
    }

    while (1) {
 {
     const char tlv9 [ ] = "Enter movie id: ";
    	cgc_printf(tlv9);
 }
 int tlv2;
 {
     int tlv16;
     tlv16 = STDIN;
     char* tlv15;
      tlv15 = buf;
     cgc_size_t tlv14;
     tlv14 = sizeof ( buf );
     char tlv13;
     tlv13 = '\n';
     tlv2 = cgc_readuntil(tlv16,tlv15,tlv14,tlv13);
 }
	if (tlv2 < 0) {
	    return;
	}
 {
     const char* tlv19 = buf;
     char** tlv18;
      tlv18 = NULL;
     int tlv17;
     tlv17 = 10;
    	movie_id = cgc_strtoul(tlv19,tlv18,tlv17);
 }
	//if (movie_id >= 1 && movie_id <= g_num_movies)
	//  break;
	if (movie_id >= 1 && movie_id <= num_movies) {
	    break;
	}
 {
     const char tlv10 [ ] = "[ERROR] Invalid movie id. Try again.\n";
    	cgc_printf(tlv10);
 }
    }

    movie_node_t* tmp;
    {
        movie_list_t tlv5;
        tlv5 = movies_rented;
        int tlv4;
        tlv4 = movie_id;
        tmp = cgc_movie_find_by_id(tlv5,tlv4);
    }
    if (tmp == NULL) {

 {
     const char tlv11 [ ] = "Sorry, we have some issues here. Please try again later.\n";
    	cgc_printf(tlv11);
 }
	return;
    }
    int tlv1;
    {
        movie_list_t* tlv7;
        tlv7 = & movies_rented;
        int tlv6;
        tlv6 = movie_id;
        tlv1 = cgc_movie_delete(tlv7,tlv6);
    }
    if (tlv1 != 0) {

 {
     const char tlv12 [ ] = "[ERROR] Failed to return the movie. Please try again.\n";
    	cgc_printf(tlv12);
 }
	return;
    }
    cgc_printf("Successfully returned [%s]! Thank you!\n", tmp->movie->title);
}

void fix_ingred_main_6_0_0();
void fix_ingred_main_6_0_1();
void fix_ingred_main_6_0();
void fix_ingred_main_6_2_0();
void fix_ingred_main_6_2_1();
void fix_ingred_main_6_2_2();
void fix_ingred_main_6_2_3();
void fix_ingred_main_6_2();
void fix_ingred_main_6_4_1();
void fix_ingred_main_6_4();
void fix_ingred_main_6_7_2();
void fix_ingred_main_6_7();
void fix_ingred_main_6_9_1();
void fix_ingred_main_6_9();
void fix_ingred_main_6();
int cgc_login()
{
if (fix_ingred_enable){ fix_ingred_main_6(); };
    int admin;
    admin = 0;
    char buf[64];
    char username[] = "admin";
    {
        const char tlv3 [ ] = "username: ";
        cgc_printf(tlv3);
    }
    {
        int tlv7;
        tlv7 = STDIN;
        char* tlv6;
         tlv6 = buf;
        cgc_size_t tlv5;
        tlv5 = sizeof ( buf );
        char tlv4;
        tlv4 = '\n';
        cgc_readuntil(tlv7,tlv6,tlv5,tlv4);
    }
    int tlv1;
    {
        const char* tlv15 = username;
        const char* tlv14 = buf;
        tlv1 = cgc_strcmp(tlv15,tlv14);
    }
    if (tlv1 != 0) {
 {
     const char tlv18 [ ] = "[ERROR] Permission Denied: Wrong credentials\n";
    	cgc_printf(tlv18);
 }
	return admin;
    }
    {
        const char tlv8 [ ] = "password: ";
        cgc_printf(tlv8);
    }
    {
        int tlv12;
        tlv12 = STDIN;
        char* tlv11;
         tlv11 = buf;
        cgc_size_t tlv10;
        tlv10 = sizeof ( buf ) + 4;
        char tlv9;
        tlv9 = '\n';
        cgc_readuntil(tlv12,tlv11,tlv10,tlv9);
    }
    int tlv2;
    {
        const char* tlv17 = g_password;
        const char* tlv16 = buf;
        tlv2 = cgc_strcmp(tlv17,tlv16);
    }
    if (tlv2 != 0) {
 {
     const char tlv19 [ ] = "[ERROR] Permission Denied: Wrong credentials\n";
    	cgc_printf(tlv19);
 }
	return admin;
    }
    {
        const char tlv13 [ ] = "\nWelcome, admin!\n";
        cgc_printf(tlv13);
    }
    admin = 1;
    return admin;
}

void fix_ingred_main_7_0_0();
void fix_ingred_main_7_0();
void fix_ingred_main_7_1_0();
void fix_ingred_main_7_1();
void fix_ingred_main_7_5_0();
void fix_ingred_main_7_5_1();
void fix_ingred_main_7_5_2();
void fix_ingred_main_7_5_3();
void fix_ingred_main_7_5();
void fix_ingred_main_7_6_0();
void fix_ingred_main_7_6();
void fix_ingred_main_7_8_0();
void fix_ingred_main_7_8();
void fix_ingred_main_7_10_0();
void fix_ingred_main_7_10();
void fix_ingred_main_7_13_0();
void fix_ingred_main_7_13();
void fix_ingred_main_7_15_0();
void fix_ingred_main_7_15();
void fix_ingred_main_7_17_0();
void fix_ingred_main_7_17();
void fix_ingred_main_7_21_0();
void fix_ingred_main_7_21();
void fix_ingred_main_7_22_1();
void fix_ingred_main_7_22();
void fix_ingred_main_7_28_0();
void fix_ingred_main_7_28();
void fix_ingred_main_7_32_0();
void fix_ingred_main_7_32();
void fix_ingred_main_7_35_1();
void fix_ingred_main_7_35();
void fix_ingred_main_7_48_2();
void fix_ingred_main_7_48();
void fix_ingred_main_7_59_2();
void fix_ingred_main_7_59();
void fix_ingred_main_7_63_0();
void fix_ingred_main_7_63();
void fix_ingred_main_7_65_0();
void fix_ingred_main_7_65();
void fix_ingred_main_7();
void cgc_add_movie()
{
if (fix_ingred_enable){ fix_ingred_main_7(); };
    char buf[1024];
    movie_t *movie;
    {
        cgc_size_t tlv25;
        tlv25 = sizeof ( movie_t );
        movie = (movie_t *) cgc_malloc(tlv25);
    }
    if (!movie) {
	return;
    }
    {
        const char tlv8 [ ] = "Add a movie\n--------------\n";
        cgc_printf(tlv8);
    }
    {
        const char tlv9 [ ] = "Enter Title: ";
        cgc_printf(tlv9);
    }
    int tlv1;
    {
        int tlv18;
        tlv18 = STDIN;
        char* tlv17;
         tlv17 = buf;
        cgc_size_t tlv16;
        tlv16 = sizeof ( buf );
        char tlv15;
        tlv15 = '\n';
        tlv1 = cgc_readuntil(tlv18,tlv17,tlv16,tlv15);
    }
    if (tlv1 < 0) {
	goto fail;
    }
    {
        cgc_size_t tlv26;
        {
            const char* tlv67 = buf;
            tlv26 = cgc_strlen(tlv67) + 1;
        }
        movie->title = (char *) cgc_malloc(tlv26);
    }
    if (movie->title == NULL) {
	goto fail;
    }
    {
        char* tlv11;
         tlv11 = movie -> title;
        const char* tlv10 = buf;
        cgc_strcpy(tlv11,tlv10);
    }
    {
        const char tlv12 [ ] = "Enter Description: ";
        cgc_printf(tlv12);
    }
    int tlv2;
    {
        int tlv22;
        tlv22 = STDIN;
        char* tlv21;
         tlv21 = buf;
        cgc_size_t tlv20;
        tlv20 = sizeof ( buf );
        char tlv19;
        tlv19 = '\n';
        tlv2 = cgc_readuntil(tlv22,tlv21,tlv20,tlv19);
    }
    if (tlv2 < 0) {
	goto fail;
    }
    {
        cgc_size_t tlv27;
        {
            const char* tlv68 = buf;
            tlv27 = cgc_strlen(tlv68) + 1;
        }
        movie->desc = (char *) cgc_malloc(tlv27);
    }
    if (movie->desc == NULL) {
	goto fail;
    }
    {
        char* tlv14;
         tlv14 = movie -> desc;
        const char* tlv13 = buf;
        cgc_strcpy(tlv14,tlv13);
    }
    while (1) {
 {
     const char tlv28 [ ] = "Enter Year (1800-2015): ";
    	cgc_printf(tlv28);
 }
 int tlv4;
 {
     int tlv38;
     tlv38 = STDIN;
     char* tlv37;
      tlv37 = buf;
     cgc_size_t tlv36;
     tlv36 = sizeof ( buf );
     char tlv35;
     tlv35 = '\n';
     tlv4 = cgc_readuntil(tlv38,tlv37,tlv36,tlv35);
 }
	if (tlv4 < 0) {
	    goto fail;
	}
 {
     const char* tlv41 = buf;
     char** tlv40;
      tlv40 = NULL;
     int tlv39;
     tlv39 = 10;
    	movie->year = cgc_strtoul(tlv41,tlv40,tlv39);
 }
	if (movie->year >= 1800 && movie->year <= 2015) {
	    break;
	}
 {
     const char tlv29 [ ] = "[ERROR] Invalid year. Try again.\n";
    	cgc_printf(tlv29);
 }
    }
    while (1) {
 {
     const char tlv30 [ ] = "Enter Review score (0-100): ";
    	cgc_printf(tlv30);
 }
 int tlv5;
 {
     int tlv45;
     tlv45 = STDIN;
     char* tlv44;
      tlv44 = buf;
     cgc_size_t tlv43;
     tlv43 = sizeof ( buf );
     char tlv42;
     tlv42 = '\n';
     tlv5 = cgc_readuntil(tlv45,tlv44,tlv43,tlv42);
 }
	if (tlv5 < 0) {
	    goto fail;
	}
 {
     const char* tlv48 = buf;
     char** tlv47;
      tlv47 = NULL;
     int tlv46;
     tlv46 = 10;
    	movie->score = cgc_strtoul(tlv48,tlv47,tlv46);
 }
	if (movie->score >= 0 && movie->score <= 100) {
	    break;
	}
 {
     const char tlv31 [ ] = "[ERROR] Invalid rating. Try again.\n";
    	cgc_printf(tlv31);
 }
    }
    int finish;
    finish = 0;
    while (!finish) {
 {
     const char tlv32 [ ] = "Select a genre\n 1. Action\n 2. Romance\n 3. Comeda\n 4. Horror\n 5. Other\nChoice: ";
    	cgc_printf(tlv32);
 }
 int tlv6;
 {
     int tlv52;
     tlv52 = STDIN;
     char* tlv51;
      tlv51 = buf;
     cgc_size_t tlv50;
     tlv50 = sizeof ( buf );
     char tlv49;
     tlv49 = '\n';
     tlv6 = cgc_readuntil(tlv52,tlv51,tlv50,tlv49);
 }
	if (tlv6 < 0) {
	    goto fail;
	}
 unsigned int genre;
 {
     const char* tlv55 = buf;
     char** tlv54;
      tlv54 = NULL;
     int tlv53;
     tlv53 = 10;
     genre = cgc_strtoul(tlv55,tlv54,tlv53);
 }
	finish = 1;
	switch (genre) {
	case 1:
	    {
		movie->genre = G_ACTION;
	    }
	    break;
	case 2:
	    {
		movie->genre = G_ROMANCE;
	    }
	    break;
	case 3:
	    {
		movie->genre = G_COMEDY;
	    }
	    break;
	case 4:
	    {
		movie->genre = G_HORROR;
	    }
	    break;
	case 5:
	    {
		movie->genre = G_OTHER;
	    }
	    break;
	default:
	    {
		finish = 0;
	    }
     {
         const char tlv63 [ ] = "[ERROR] Invalid genre. Try again.\n";
    	    cgc_printf(tlv63);
     }
	    break;
	}
    }
    finish = 0;
    while (!finish) {
 {
     const char tlv33 [ ] = "Select a film rating\n 1. G\n 2. PG\n 3. PG-13\n 4. R\n 5. Unknown\nChoice: ";
    	cgc_printf(tlv33);
 }
 int tlv7;
 {
     int tlv59;
     tlv59 = STDIN;
     char* tlv58;
      tlv58 = buf;
     cgc_size_t tlv57;
     tlv57 = sizeof ( buf );
     char tlv56;
     tlv56 = '\n';
     tlv7 = cgc_readuntil(tlv59,tlv58,tlv57,tlv56);
 }
	if (tlv7 < 0) {
	    goto fail;
	}
 unsigned int rating;
 {
     const char* tlv62 = buf;
     char** tlv61;
      tlv61 = NULL;
     int tlv60;
     tlv60 = 10;
     rating = cgc_strtoul(tlv62,tlv61,tlv60);
 }
	finish = 1;
	switch (rating) {
	case 1:
	    {
		movie->rating = R_G;
	    }
	    break;
	case 2:
	    {
		movie->rating = R_PG;
	    }
	    break;
	case 3:
	    {
		movie->rating = R_PG13;
	    }
	    break;
	case 4:
	    {
		movie->rating = R_R;
	    }
	    break;
	case 5:
	    {
		movie->rating = R_UNKNOWN;
	    }
	    break;
	default:
	    {
		finish = 0;
	    }
     {
         const char tlv64 [ ] = "[ERROR] Invalid film rating. Try again.\n";
    	    cgc_printf(tlv64);
     }
	    break;
	}
    }
    //movie->id = ++g_num_movies;
    movie->print_info = &cgc_print_movie_detail;
    int tlv3;
    {
        movie_list_t* tlv24;
        tlv24 = & movies_full;
        movie_t* tlv23;
        tlv23 = movie;
        tlv3 = cgc_movie_add(tlv24,tlv23);
    }
    if (tlv3 != 0) {
 {
     const char tlv34 [ ] = "[ERROR] Failed to add a movie.\n";
    	cgc_printf(tlv34);
 }
	goto fail;
    }
    return;
  fail:
    if (movie) {
	if (movie->desc) {
     {
         void* tlv65;
         tlv65 = movie -> desc;
    	    cgc_free(tlv65);
     }
	}
	if (movie->title) {
     {
         void* tlv66;
         tlv66 = movie -> title;
    	    cgc_free(tlv66);
     }
	}
	cgc_free(movie);
    }
    return;
}

void fix_ingred_main_8();
void cgc_remove_movie()
{
if (fix_ingred_enable){ fix_ingred_main_8(); };
    char buf[256];
    unsigned int num_movies;
    num_movies = 0;
    unsigned int movie_id;
    movie_node_t *node;

    {
        const char tlv3 [ ] = "\nMovies (Full)\n--------------\n";
        cgc_printf(tlv3);
    }
    for (node = movies_full; node != NULL; node = node->next) {
	num_movies++;
	node->movie->print_info(num_movies, node->movie);
    }
    cgc_printf("--------------\n%d movie(s)\n", num_movies);
    if (num_movies == 0) {
 {
     const char tlv8 [ ] = "[ERROR] Movie list is empty.\n";
    	cgc_printf(tlv8);
 }
	return;
    }

    while (1) {
 {
     const char tlv9 [ ] = "Enter movie id: ";
    	cgc_printf(tlv9);
 }
 int tlv2;
 {
     int tlv16;
     tlv16 = STDIN;
     char* tlv15;
      tlv15 = buf;
     cgc_size_t tlv14;
     tlv14 = sizeof ( buf );
     char tlv13;
     tlv13 = '\n';
     tlv2 = cgc_readuntil(tlv16,tlv15,tlv14,tlv13);
 }
	if (tlv2 < 0) {
	    return;
	}
 {
     const char* tlv19 = buf;
     char** tlv18;
      tlv18 = NULL;
     int tlv17;
     tlv17 = 10;
    	movie_id = cgc_strtoul(tlv19,tlv18,tlv17);
 }
	if (movie_id >= 1 && movie_id <= num_movies) {
	    break;
	}
 {
     const char tlv10 [ ] = "[ERROR] Invalid movie id. Try again.\n";
    	cgc_printf(tlv10);
 }
    }
    {
        movie_list_t tlv5;
        tlv5 = movies_full;
        int tlv4;
        tlv4 = movie_id;
        node = cgc_movie_find_by_id(tlv5,tlv4);
    }
    movie_t* movie;
    movie = node -> movie;
    int tlv1;
    {
        movie_list_t* tlv7;
        tlv7 = & movies_full;
        int tlv6;
        tlv6 = movie_id;
        tlv1 = cgc_movie_delete(tlv7,tlv6);
    }
    if (tlv1 != 0) {
 {
     const char tlv11 [ ] = "[ERROR] Failed to remove.\n";
    	cgc_printf(tlv11);
 }
    } else {
	cgc_g_num_movies--;
	cgc_free_movie(movie);
 {
     const char tlv12 [ ] = "Successfully removed the movie!\n";
    	cgc_printf(tlv12);
 }
    }
}

void fix_ingred_main_9_0_0();
void fix_ingred_main_9_0_2();
void fix_ingred_main_9_0();
void fix_ingred_main_9_3_1();
void fix_ingred_main_9_3();
void fix_ingred_main_9_7_0();
void fix_ingred_main_9_7_1();
void fix_ingred_main_9_7_2();
void fix_ingred_main_9_7_3();
void fix_ingred_main_9_7();
void fix_ingred_main_9_8_1();
void fix_ingred_main_9_8();
void fix_ingred_main_9_9_1();
void fix_ingred_main_9_9();
void fix_ingred_main_9_10_1();
void fix_ingred_main_9_10_2();
void fix_ingred_main_9_10();
void fix_ingred_main_9_12_1();
void fix_ingred_main_9_12();
void fix_ingred_main_9_15_2();
void fix_ingred_main_9_15();
void fix_ingred_main_9_16_0();
void fix_ingred_main_9_16();
void fix_ingred_main_9_17_3();
void fix_ingred_main_9_17_4();
void fix_ingred_main_9_17();
void fix_ingred_main_9_19_0();
void fix_ingred_main_9_19();
void fix_ingred_main_9_20_4();
void fix_ingred_main_9_20_5();
void fix_ingred_main_9_20();
void fix_ingred_main_9_22_0();
void fix_ingred_main_9_22();
void fix_ingred_main_9_24_2();
void fix_ingred_main_9_24();
void fix_ingred_main_9_25_0();
void fix_ingred_main_9_25();
void fix_ingred_main_9_26_3();
void fix_ingred_main_9_26();
void fix_ingred_main_9_28_0();
void fix_ingred_main_9_28();
void fix_ingred_main_9_29_4();
void fix_ingred_main_9_29();
void fix_ingred_main_9_31_0();
void fix_ingred_main_9_31();
void fix_ingred_main_9_34_2();
void fix_ingred_main_9_34();
void fix_ingred_main_9_35_0();
void fix_ingred_main_9_35();
void fix_ingred_main_9_36_2();
void fix_ingred_main_9_36();
void fix_ingred_main_9_38_5();
void fix_ingred_main_9_38_6();
void fix_ingred_main_9_38_8();
void fix_ingred_main_9_38();
void fix_ingred_main_9_43_2();
void fix_ingred_main_9_43();
void fix_ingred_main_9_44_0();
void fix_ingred_main_9_44();
void fix_ingred_main_9_45_2();
void fix_ingred_main_9_45();
void fix_ingred_main_9_47_5();
void fix_ingred_main_9_47_8();
void fix_ingred_main_9_47();
void fix_ingred_main_9_52_3();
void fix_ingred_main_9_52();
void fix_ingred_main_9_53_0();
void fix_ingred_main_9_53();
void fix_ingred_main_9_54_0();
void fix_ingred_main_9_54_4();
void fix_ingred_main_9_54();
void fix_ingred_main_9_67_4();
void fix_ingred_main_9_67();
void fix_ingred_main_9_68_0();
void fix_ingred_main_9_68();
void fix_ingred_main_9_69_5();
void fix_ingred_main_9_69();
void fix_ingred_main_9();
void cgc_update_movie()
{
if (fix_ingred_enable){ fix_ingred_main_9(); };
    unsigned int movie_id;
    unsigned int num_movies;
    num_movies = 0;
    char *new_title;
    char *new_desc;
    char buf[1024];
    movie_node_t *node;
    movie_t *movie;

    {
        const char tlv14 [ ] = "\nMovies (Full)\n--------------\n";
        cgc_printf(tlv14);
    }
    for (node = movies_full; node != NULL; node = node->next) {
	num_movies++;
	node->movie->print_info(num_movies, node->movie);
    }
    cgc_printf("--------------\n%d movie(s)\n", num_movies);
    if (num_movies == 0) {
 {
     const char tlv29 [ ] = "[ERROR] Nothing to update.\n";
    	cgc_printf(tlv29);
 }
	return;
    }

    while (1) {
 {
     const char tlv30 [ ] = "Enter movie id: ";
    	cgc_printf(tlv30);
 }
 int tlv5;
 {
     int tlv41;
     tlv41 = STDIN;
     char* tlv40;
      tlv40 = buf;
     cgc_size_t tlv39;
     tlv39 = sizeof ( buf );
     char tlv38;
     tlv38 = '\n';
     tlv5 = cgc_readuntil(tlv41,tlv40,tlv39,tlv38);
 }
	if (tlv5 < 0) {
	    return;
	}
 {
     const char* tlv44 = buf;
     char** tlv43;
      tlv43 = NULL;
     int tlv42;
     tlv42 = 10;
    	movie_id = cgc_strtoul(tlv44,tlv43,tlv42);
 }
	if (movie_id >= 1 && movie_id <= num_movies) {
	    break;
	}
 {
     const char tlv31 [ ] = "[ERROR] Invalid movie id. Try again.\n";
    	cgc_printf(tlv31);
 }
    }
    {
        movie_list_t tlv18;
        tlv18 = movies_full;
        int tlv17;
        tlv17 = movie_id;
        node = cgc_movie_find_by_id(tlv18,tlv17);
    }
    movie = node->movie;
    {
        const char tlv15 [ ] = "\nUpdate a movie\n--------------\nJust leave it empty to keep the old value.\n";
        cgc_printf(tlv15);
    }
    cgc_printf("Enter new title (current: [%s]): ", movie->title);
    int tlv1;
    {
        int tlv22;
        tlv22 = STDIN;
        char* tlv21;
         tlv21 = buf;
        cgc_size_t tlv20;
        tlv20 = sizeof ( buf );
        char tlv19;
        tlv19 = '\n';
        tlv1 = cgc_readuntil(tlv22,tlv21,tlv20,tlv19);
    }
    if (tlv1 < 0) {
	return;
    }
    cgc_size_t tlv2;
    {
        const char* tlv23 = buf;
        tlv2 = cgc_strlen(tlv23);
    }
    if (tlv2 != 0) {
 {
     cgc_size_t tlv65;
     {
         const char* tlv83 = buf;
         tlv65 = cgc_strlen(tlv83) + 1;
     }
    	new_title = (char *) cgc_malloc(tlv65);
 }
	if (new_title == NULL) {
	    goto fail;
	}
 {
     char* tlv33;
      tlv33 = new_title;
     const char* tlv32 = buf;
    	cgc_strcpy(tlv33,tlv32);
 }
 {
     void* tlv34;
     tlv34 = movie -> title;
    	cgc_free(tlv34);
 }
	movie->title = new_title;
    }
    cgc_printf("Enter new description (current: [%s]): ", movie->desc);
    int tlv3;
    {
        int tlv27;
        tlv27 = STDIN;
        char* tlv26;
         tlv26 = buf;
        cgc_size_t tlv25;
        tlv25 = sizeof ( buf );
        char tlv24;
        tlv24 = '\n';
        tlv3 = cgc_readuntil(tlv27,tlv26,tlv25,tlv24);
    }
    if (tlv3 < 0) {
	return;
    }
    cgc_size_t tlv4;
    {
        const char* tlv28 = buf;
        tlv4 = cgc_strlen(tlv28);
    }
    if (tlv4 != 0) {
 {
     cgc_size_t tlv66;
     {
         const char* tlv84 = buf;
         tlv66 = cgc_strlen(tlv84) + 1;
     }
    	new_desc = (char *) cgc_malloc(tlv66);
 }
	if (new_desc == NULL) {
	    goto fail;
	}
 {
     char* tlv36;
      tlv36 = new_desc;
     const char* tlv35 = buf;
    	cgc_strcpy(tlv36,tlv35);
 }
 {
     void* tlv37;
     tlv37 = movie -> desc;
    	cgc_free(tlv37);
 }
	movie->desc = new_desc;
    }
    while (1) {
	cgc_printf("Enter new year (1800-2015) (current: [%d]): ", movie->year);
 int tlv6;
 {
     int tlv48;
     tlv48 = STDIN;
     char* tlv47;
      tlv47 = buf;
     cgc_size_t tlv46;
     tlv46 = sizeof ( buf );
     char tlv45;
     tlv45 = '\n';
     tlv6 = cgc_readuntil(tlv48,tlv47,tlv46,tlv45);
 }
	if (tlv6 < 0) {
	    goto fail;
	}
 cgc_size_t tlv7;
 {
     const char* tlv49 = buf;
     tlv7 = cgc_strlen(tlv49);
 }
	if (tlv7 != 0) {
     int new_year;
     {
         const char* tlv71 = buf;
         char** tlv70;
          tlv70 = NULL;
         int tlv69;
         tlv69 = 10;
         new_year = cgc_strtoul(tlv71,tlv70,tlv69);
     }
	    if (new_year >= 1800 && new_year <= 2015) {
		movie->year = new_year;
		break;
	    }
     {
         const char tlv67 [ ] = "[ERROR] Invalid year. Try again.\n";
    	    cgc_printf(tlv67);
     }
	} else {
	    break;
	}
    }
    while (1) {
	cgc_printf("Enter new review score (0-100) (current: [%d/100]: ", movie->score);
 int tlv8;
 {
     int tlv53;
     tlv53 = STDIN;
     char* tlv52;
      tlv52 = buf;
     cgc_size_t tlv51;
     tlv51 = sizeof ( buf );
     char tlv50;
     tlv50 = '\n';
     tlv8 = cgc_readuntil(tlv53,tlv52,tlv51,tlv50);
 }
	if (tlv8 < 0) {
	    goto fail;
	}
 cgc_size_t tlv9;
 {
     const char* tlv54 = buf;
     tlv9 = cgc_strlen(tlv54);
 }
	if (tlv9 != 0) {
     int new_score;
     {
         const char* tlv74 = buf;
         char** tlv73;
          tlv73 = NULL;
         int tlv72;
         tlv72 = 10;
         new_score = cgc_strtoul(tlv74,tlv73,tlv72);
     }
	    if (new_score >= 0 && new_score <= 100) {
		movie->score = new_score;
		break;
	    }
     {
         const char tlv68 [ ] = "[ERROR] Invalid rating. Try again.\n";
    	    cgc_printf(tlv68);
     }
	} else {
	    break;
	}
    }
    int finish;
    finish = 0;
    while (!finish) {
	cgc_printf("Select a genre (current: [%s])\n 1. Action\n 2. Romance\n 3. Comeda\n 4. Horror\n 5. Other\nChoice: ", cgc_movie_g2s(movie->genre));
 int tlv10;
 {
     int tlv58;
     tlv58 = STDIN;
     char* tlv57;
      tlv57 = buf;
     cgc_size_t tlv56;
     tlv56 = sizeof ( buf );
     char tlv55;
     tlv55 = '\n';
     tlv10 = cgc_readuntil(tlv58,tlv57,tlv56,tlv55);
 }
	if (tlv10 < 0) {
	    goto fail;
	}
 cgc_size_t tlv11;
 {
     const char* tlv59 = buf;
     tlv11 = cgc_strlen(tlv59);
 }
	if (tlv11 != 0) {
     unsigned int genre;
     {
         const char* tlv77 = buf;
         char** tlv76;
          tlv76 = NULL;
         int tlv75;
         tlv75 = 10;
         genre = cgc_strtoul(tlv77,tlv76,tlv75);
     }
	    finish = 1;
	    switch (genre) {
	    case 1:
		{
		    movie->genre = G_ACTION;
		}
		break;
	    case 2:
		{
		    movie->genre = G_ROMANCE;
		}
		break;
	    case 3:
		{
		    movie->genre = G_COMEDY;
		}
		break;
	    case 4:
		{
		    movie->genre = G_HORROR;
		}
		break;
	    case 5:
		{
		    movie->genre = G_OTHER;
		}
		break;
	    default:
		{
		    finish = 0;
		}
  {
      const char tlv81 [ ] = "[ERROR] Invalid genre. Try again.\n";
    		cgc_printf(tlv81);
  }
		break;
	    }
	} else {
	    break;
	}
    }
    finish = 0;
    while (!finish) {
	cgc_printf("Select a film rating (current: [%s]\n 1. G\n 2. PG\n 3. PG-13\n 4. R\n 5. Unknown\nChoice: ", cgc_movie_r2s(movie->rating));
 int tlv12;
 {
     int tlv63;
     tlv63 = STDIN;
     char* tlv62;
      tlv62 = buf;
     cgc_size_t tlv61;
     tlv61 = sizeof ( buf );
     char tlv60;
     tlv60 = '\n';
     tlv12 = cgc_readuntil(tlv63,tlv62,tlv61,tlv60);
 }
	if (tlv12 < 0) {
	    goto fail;
	}
 cgc_size_t tlv13;
 {
     const char* tlv64 = buf;
     tlv13 = cgc_strlen(tlv64);
 }
	if (tlv13 != 0) {
     unsigned int rating;
     {
         const char* tlv80 = buf;
         char** tlv79;
          tlv79 = NULL;
         int tlv78;
         tlv78 = 10;
         rating = cgc_strtoul(tlv80,tlv79,tlv78);
     }
	    finish = 1;
	    switch (rating) {
	    case 1:
		{
		    movie->rating = R_G;
		}
		break;
	    case 2:
		{
		    movie->rating = R_PG;
		}
		break;
	    case 3:
		{
		    movie->rating = R_PG13;
		}
		break;
	    case 4:
		{
		    movie->rating = R_R;
		}
		break;
	    case 5:
		{
		    movie->rating = R_UNKNOWN;
		}
		break;
	    default:
		{
		    finish = 0;
		}
  {
      const char tlv82 [ ] = "[ERROR] Invalid film rating. Try again.\n";
    		cgc_printf(tlv82);
  }
		break;
	    }
	} else {
	    break;
	}
    }
    {
        const char tlv16 [ ] = "Successfully updated the movie information!\n";
        cgc_printf(tlv16);
    }
    return;
  fail:
    if (new_title) {
	cgc_free(new_title);
    }
    if (new_desc) {
	cgc_free(new_desc);
    }
    if (movie) {
	cgc_free(movie);
    }
}

void fix_ingred_main_10();
void cgc_quit()
{
if (fix_ingred_enable){ fix_ingred_main_10(); };
    {
        const char tlv1 [ ] = "Bye!\n";
        cgc_printf(tlv1);
    }
    cgc_exit(0);
}

void fix_ingred_main_11_0_0();
void fix_ingred_main_11_0();
void fix_ingred_main_11_4_0();
void fix_ingred_main_11_4_1();
void fix_ingred_main_11_4_2();
void fix_ingred_main_11_4_3();
void fix_ingred_main_11_4();
void fix_ingred_main_11_5_1();
void fix_ingred_main_11_5();
void fix_ingred_main_11_15_1();
void fix_ingred_main_11_15();
void fix_ingred_main_11();
int main(int cgc_argc, char *cgc_argv[])
{
if (fix_ingred_enable){ fix_ingred_main_11(); };
    int admin_mode;
    admin_mode = 0;
    char buf[4096];
    char welcome[] = "========= Movie Rental Service v0.1 =========";
    char menu[] = "\n1. List movies\n2. Rent movie\n3. Return movie\n4. Admin mode\n5. Exit\n\nChoice: ";
    char admin_menu[] = "\n1. Add movie\n2. Remove movie\n3. Update movie\n4. Quit admin mode\n\nChoice: ";
    cgc_printf(welcome);
    cgc_initialize();
    {
        const char tlv3 [ ] = "=============================================";
        cgc_printf(tlv3);
    }
    while (1) {
	if (admin_mode) {
	    cgc_printf(admin_menu);
     int tlv1;
     {
         int tlv7;
         tlv7 = STDIN;
         char* tlv6;
          tlv6 = buf;
         cgc_size_t tlv5;
         tlv5 = sizeof ( buf );
         char tlv4;
         tlv4 = '\n';
         tlv1 = cgc_readuntil(tlv7,tlv6,tlv5,tlv4);
     }
	    if (tlv1 < 0) {
		cgc_quit();
	    }
	    switch (buf[0]) {
	    case '1':
		{
		    cgc_add_movie();
		}
		break;
	    case '2':
		{
		    cgc_remove_movie();
		}
		break;
	    case '3':
		{
		    cgc_update_movie();
		}
		break;
	    case '4':
		{
		    admin_mode = 0;
		}
		break;
	    default:
		{
      {
          const char tlv12 [ ] = "[ERROR] Invalid menu. Please select again.\n";
    		    cgc_printf(tlv12);
      }
		}
		break;
	    }
	} else {
	    cgc_printf(menu);
     int tlv2;
     {
         int tlv11;
         tlv11 = STDIN;
         char* tlv10;
          tlv10 = buf;
         cgc_size_t tlv9;
         tlv9 = sizeof ( buf );
         char tlv8;
         tlv8 = '\n';
         tlv2 = cgc_readuntil(tlv11,tlv10,tlv9,tlv8);
     }
	    if (tlv2 < 0) {
		cgc_quit();
	    }
	    switch (buf[0]) {
	    case '1':
		{
		    cgc_list_movies();
		}
		break;
	    case '2':
		{
		    cgc_rent_movie();
		}
		break;
	    case '3':
		{
		    cgc_return_movie();
		}
		break;
	    case '4':
		{
		    admin_mode = cgc_login();
		}
		break;
	    case '5':
		{
		    cgc_quit();
		}
		break;
	    default:
		{
      {
          const char tlv13 [ ] = "[ERROR] Invalid menu. Please select again.\n";
    		    cgc_printf(tlv13);
      }
		}
		break;
	    }
	}
    }
    return 0;
}

void fix_ingred_main_0_2_1(){
unsigned int i;
    bzero(&i,sizeof(unsigned int));
unsigned long tlv_size_0;
    bzero(&tlv_size_0,sizeof(unsigned long));
    {unsigned int i; i = (unsigned int)(0); }
    {unsigned int rand; rand = (unsigned int)(0); }
    {char c; c = (char)(0); }
    {unsigned long tlv_size_0; tlv_size_0 = (unsigned long)(0); }
    {void * tlv5; tlv5 = (void *)(0); }
    {cgc_size_t tlv4; tlv4 = (cgc_size_t)(0); }
    {void * tlv8; tlv8 = (void *)(0); }
    {cgc_size_t tlv7; tlv7 = (cgc_size_t)(0); }
    {cgc_size_t tlv18; tlv18 = (cgc_size_t)(0); }
    {void * tlv11; tlv11 = (void *)(0); }
    {int tlv10; tlv10 = (int)(0); }
    {cgc_size_t tlv9; tlv9 = (cgc_size_t)(0); }
    {cgc_size_t tlv19; tlv19 = (cgc_size_t)(0); }
    {cgc_size_t tlv20; tlv20 = (cgc_size_t)(0); }
    {char * tlv13; tlv13 = (char *)(0); }
    {char * tlv15; tlv15 = (char *)(0); }
}
void fix_ingred_main_0_2_2(){
unsigned int i;
    bzero(&i,sizeof(unsigned int));
unsigned long tlv_size_0;
    bzero(&tlv_size_0,sizeof(unsigned long));
    {unsigned int rand; rand = (unsigned int)(i); }
    {char c; c = (char)(i); }
    {unsigned long tlv_size_0; tlv_size_0 = (unsigned long)(i); }
    {void * tlv5; tlv5 = (void *)(i); }
    {cgc_size_t tlv4; tlv4 = (cgc_size_t)(i); }
    {void * tlv8; tlv8 = (void *)(i); }
    {cgc_size_t tlv7; tlv7 = (cgc_size_t)(i); }
    {cgc_size_t tlv18; tlv18 = (cgc_size_t)(i); }
    {void * tlv11; tlv11 = (void *)(i); }
    {int tlv10; tlv10 = (int)(i); }
    {cgc_size_t tlv9; tlv9 = (cgc_size_t)(i); }
    {cgc_size_t tlv19; tlv19 = (cgc_size_t)(i); }
    {cgc_size_t tlv20; tlv20 = (cgc_size_t)(i); }
    {char * tlv13; tlv13 = (char *)(i); }
    {char * tlv15; tlv15 = (char *)(i); }
}
void fix_ingred_main_0_2_3(){
unsigned int i;
    bzero(&i,sizeof(unsigned int));
unsigned long tlv_size_0;
    bzero(&tlv_size_0,sizeof(unsigned long));
    {unsigned int i; i = (unsigned int)(tlv_size_0); }
    {unsigned int rand; rand = (unsigned int)(tlv_size_0); }
    {char c; c = (char)(tlv_size_0); }
    {void * tlv5; tlv5 = (void *)(tlv_size_0); }
    {cgc_size_t tlv4; tlv4 = (cgc_size_t)(tlv_size_0); }
    {void * tlv8; tlv8 = (void *)(tlv_size_0); }
    {cgc_size_t tlv7; tlv7 = (cgc_size_t)(tlv_size_0); }
    {cgc_size_t tlv18; tlv18 = (cgc_size_t)(tlv_size_0); }
    {void * tlv11; tlv11 = (void *)(tlv_size_0); }
    {int tlv10; tlv10 = (int)(tlv_size_0); }
    {cgc_size_t tlv9; tlv9 = (cgc_size_t)(tlv_size_0); }
    {cgc_size_t tlv19; tlv19 = (cgc_size_t)(tlv_size_0); }
    {cgc_size_t tlv20; tlv20 = (cgc_size_t)(tlv_size_0); }
    {char * tlv13; tlv13 = (char *)(tlv_size_0); }
    {char * tlv15; tlv15 = (char *)(tlv_size_0); }
}
void fix_ingred_main_0_2(){
fix_ingred_main_0_2_1();
fix_ingred_main_0_2_2();
fix_ingred_main_0_2_3();
}
void fix_ingred_main_0_3_0(){
char c;
    bzero(&c,sizeof(char));
    {unsigned int i; i = (unsigned int)(& c); }
    {unsigned int rand; rand = (unsigned int)(& c); }
    {unsigned long tlv_size_0; tlv_size_0 = (unsigned long)(& c); }
    {void * tlv5; tlv5 = (void *)(& c); }
    {cgc_size_t tlv4; tlv4 = (cgc_size_t)(& c); }
    {void * tlv8; tlv8 = (void *)(& c); }
    {cgc_size_t tlv7; tlv7 = (cgc_size_t)(& c); }
    {cgc_size_t tlv18; tlv18 = (cgc_size_t)(& c); }
    {void * tlv11; tlv11 = (void *)(& c); }
    {int tlv10; tlv10 = (int)(& c); }
    {cgc_size_t tlv9; tlv9 = (cgc_size_t)(& c); }
    {cgc_size_t tlv19; tlv19 = (cgc_size_t)(& c); }
    {cgc_size_t tlv20; tlv20 = (cgc_size_t)(& c); }
    {char * tlv13; tlv13 = (char *)(& c); }
    {char * tlv15; tlv15 = (char *)(& c); }
}
void fix_ingred_main_0_3_1(){
char c;
    bzero(&c,sizeof(char));
    {unsigned int i; i = (unsigned int)(sizeof ( c )); }
    {unsigned int rand; rand = (unsigned int)(sizeof ( c )); }
    {unsigned long tlv_size_0; tlv_size_0 = (unsigned long)(sizeof ( c )); }
    {void * tlv5; tlv5 = (void *)(sizeof ( c )); }
    {cgc_size_t tlv4; tlv4 = (cgc_size_t)(sizeof ( c )); }
    {void * tlv8; tlv8 = (void *)(sizeof ( c )); }
    {cgc_size_t tlv7; tlv7 = (cgc_size_t)(sizeof ( c )); }
    {cgc_size_t tlv18; tlv18 = (cgc_size_t)(sizeof ( c )); }
    {void * tlv11; tlv11 = (void *)(sizeof ( c )); }
    {int tlv10; tlv10 = (int)(sizeof ( c )); }
    {cgc_size_t tlv9; tlv9 = (cgc_size_t)(sizeof ( c )); }
    {cgc_size_t tlv19; tlv19 = (cgc_size_t)(sizeof ( c )); }
    {cgc_size_t tlv20; tlv20 = (cgc_size_t)(sizeof ( c )); }
    {char * tlv13; tlv13 = (char *)(sizeof ( c )); }
    {char * tlv15; tlv15 = (char *)(sizeof ( c )); }
}
void fix_ingred_main_0_3(){
fix_ingred_main_0_3_0();
fix_ingred_main_0_3_1();
}
void fix_ingred_main_0_4_0(){
unsigned int rand;
    bzero(&rand,sizeof(unsigned int));
    {unsigned int i; i = (unsigned int)(& rand); }
    {char c; c = (char)(& rand); }
    {unsigned long tlv_size_0; tlv_size_0 = (unsigned long)(& rand); }
    {void * tlv5; tlv5 = (void *)(& rand); }
    {cgc_size_t tlv4; tlv4 = (cgc_size_t)(& rand); }
    {void * tlv8; tlv8 = (void *)(& rand); }
    {cgc_size_t tlv7; tlv7 = (cgc_size_t)(& rand); }
    {cgc_size_t tlv18; tlv18 = (cgc_size_t)(& rand); }
    {void * tlv11; tlv11 = (void *)(& rand); }
    {int tlv10; tlv10 = (int)(& rand); }
    {cgc_size_t tlv9; tlv9 = (cgc_size_t)(& rand); }
    {cgc_size_t tlv19; tlv19 = (cgc_size_t)(& rand); }
    {cgc_size_t tlv20; tlv20 = (cgc_size_t)(& rand); }
    {char * tlv13; tlv13 = (char *)(& rand); }
    {char * tlv15; tlv15 = (char *)(& rand); }
}
void fix_ingred_main_0_4_1(){
unsigned int rand;
    bzero(&rand,sizeof(unsigned int));
    {unsigned int i; i = (unsigned int)(sizeof ( rand )); }
    {char c; c = (char)(sizeof ( rand )); }
    {unsigned long tlv_size_0; tlv_size_0 = (unsigned long)(sizeof ( rand )); }
    {void * tlv5; tlv5 = (void *)(sizeof ( rand )); }
    {cgc_size_t tlv4; tlv4 = (cgc_size_t)(sizeof ( rand )); }
    {void * tlv8; tlv8 = (void *)(sizeof ( rand )); }
    {cgc_size_t tlv7; tlv7 = (cgc_size_t)(sizeof ( rand )); }
    {cgc_size_t tlv18; tlv18 = (cgc_size_t)(sizeof ( rand )); }
    {void * tlv11; tlv11 = (void *)(sizeof ( rand )); }
    {int tlv10; tlv10 = (int)(sizeof ( rand )); }
    {cgc_size_t tlv9; tlv9 = (cgc_size_t)(sizeof ( rand )); }
    {cgc_size_t tlv19; tlv19 = (cgc_size_t)(sizeof ( rand )); }
    {cgc_size_t tlv20; tlv20 = (cgc_size_t)(sizeof ( rand )); }
    {char * tlv13; tlv13 = (char *)(sizeof ( rand )); }
    {char * tlv15; tlv15 = (char *)(sizeof ( rand )); }
}
void fix_ingred_main_0_4(){
fix_ingred_main_0_4_0();
fix_ingred_main_0_4_1();
}
void fix_ingred_main_0_8_0(){
    {unsigned int i; i = (unsigned int)(sizeof ( movie_t )); }
    {unsigned int rand; rand = (unsigned int)(sizeof ( movie_t )); }
    {char c; c = (char)(sizeof ( movie_t )); }
    {unsigned long tlv_size_0; tlv_size_0 = (unsigned long)(sizeof ( movie_t )); }
    {void * tlv5; tlv5 = (void *)(sizeof ( movie_t )); }
    {cgc_size_t tlv4; tlv4 = (cgc_size_t)(sizeof ( movie_t )); }
    {void * tlv8; tlv8 = (void *)(sizeof ( movie_t )); }
    {cgc_size_t tlv7; tlv7 = (cgc_size_t)(sizeof ( movie_t )); }
    {cgc_size_t tlv18; tlv18 = (cgc_size_t)(sizeof ( movie_t )); }
    {void * tlv11; tlv11 = (void *)(sizeof ( movie_t )); }
    {int tlv10; tlv10 = (int)(sizeof ( movie_t )); }
    {cgc_size_t tlv9; tlv9 = (cgc_size_t)(sizeof ( movie_t )); }
    {cgc_size_t tlv19; tlv19 = (cgc_size_t)(sizeof ( movie_t )); }
    {cgc_size_t tlv20; tlv20 = (cgc_size_t)(sizeof ( movie_t )); }
    {char * tlv13; tlv13 = (char *)(sizeof ( movie_t )); }
    {char * tlv15; tlv15 = (char *)(sizeof ( movie_t )); }
}
void fix_ingred_main_0_8(){
fix_ingred_main_0_8_0();
}
void fix_ingred_main_0_10_0(){
movie_t movie_ref;
    bzero(&movie_ref,1*sizeof(movie_t));
movie_t * movie = &movie_ref;
    {unsigned int i; i = (unsigned int)(movie); }
    {unsigned int rand; rand = (unsigned int)(movie); }
    {char c; c = (char)(movie); }
    {unsigned long tlv_size_0; tlv_size_0 = (unsigned long)(movie); }
    {void * tlv5; tlv5 = (void *)(movie); }
    {cgc_size_t tlv4; tlv4 = (cgc_size_t)(movie); }
    {void * tlv8; tlv8 = (void *)(movie); }
    {cgc_size_t tlv7; tlv7 = (cgc_size_t)(movie); }
    {cgc_size_t tlv18; tlv18 = (cgc_size_t)(movie); }
    {void * tlv11; tlv11 = (void *)(movie); }
    {int tlv10; tlv10 = (int)(movie); }
    {cgc_size_t tlv9; tlv9 = (cgc_size_t)(movie); }
    {cgc_size_t tlv19; tlv19 = (cgc_size_t)(movie); }
    {cgc_size_t tlv20; tlv20 = (cgc_size_t)(movie); }
    {char * tlv13; tlv13 = (char *)(movie); }
    {char * tlv15; tlv15 = (char *)(movie); }
}
void fix_ingred_main_0_10_1(){
movie_t movie_ref;
    bzero(&movie_ref,1*sizeof(movie_t));
movie_t * movie = &movie_ref;
    {unsigned int i; i = (unsigned int)('\0'); }
    {unsigned int rand; rand = (unsigned int)('\0'); }
    {char c; c = (char)('\0'); }
    {unsigned long tlv_size_0; tlv_size_0 = (unsigned long)('\0'); }
    {void * tlv5; tlv5 = (void *)('\0'); }
    {cgc_size_t tlv4; tlv4 = (cgc_size_t)('\0'); }
    {void * tlv8; tlv8 = (void *)('\0'); }
    {cgc_size_t tlv7; tlv7 = (cgc_size_t)('\0'); }
    {cgc_size_t tlv18; tlv18 = (cgc_size_t)('\0'); }
    {void * tlv11; tlv11 = (void *)('\0'); }
    {int tlv10; tlv10 = (int)('\0'); }
    {cgc_size_t tlv9; tlv9 = (cgc_size_t)('\0'); }
    {cgc_size_t tlv19; tlv19 = (cgc_size_t)('\0'); }
    {cgc_size_t tlv20; tlv20 = (cgc_size_t)('\0'); }
    {char * tlv13; tlv13 = (char *)('\0'); }
    {char * tlv15; tlv15 = (char *)('\0'); }
}
void fix_ingred_main_0_10(){
fix_ingred_main_0_10_0();
fix_ingred_main_0_10_1();
}
void fix_ingred_main_0_12_0(){
char tlv21_ref;
    bzero(&tlv21_ref,1*sizeof(char));
const char * tlv21 = &tlv21_ref;
    {unsigned int i; i = (unsigned int)(cgc_strlen ( tlv21 ) + 1); }
    {unsigned int rand; rand = (unsigned int)(cgc_strlen ( tlv21 ) + 1); }
    {char c; c = (char)(cgc_strlen ( tlv21 ) + 1); }
    {unsigned long tlv_size_0; tlv_size_0 = (unsigned long)(cgc_strlen ( tlv21 ) + 1); }
    {void * tlv5; tlv5 = (void *)(cgc_strlen ( tlv21 ) + 1); }
    {cgc_size_t tlv4; tlv4 = (cgc_size_t)(cgc_strlen ( tlv21 ) + 1); }
    {void * tlv8; tlv8 = (void *)(cgc_strlen ( tlv21 ) + 1); }
    {cgc_size_t tlv7; tlv7 = (cgc_size_t)(cgc_strlen ( tlv21 ) + 1); }
    {cgc_size_t tlv18; tlv18 = (cgc_size_t)(cgc_strlen ( tlv21 ) + 1); }
    {void * tlv11; tlv11 = (void *)(cgc_strlen ( tlv21 ) + 1); }
    {int tlv10; tlv10 = (int)(cgc_strlen ( tlv21 ) + 1); }
    {cgc_size_t tlv9; tlv9 = (cgc_size_t)(cgc_strlen ( tlv21 ) + 1); }
    {cgc_size_t tlv19; tlv19 = (cgc_size_t)(cgc_strlen ( tlv21 ) + 1); }
    {cgc_size_t tlv20; tlv20 = (cgc_size_t)(cgc_strlen ( tlv21 ) + 1); }
    {char * tlv13; tlv13 = (char *)(cgc_strlen ( tlv21 ) + 1); }
    {char * tlv15; tlv15 = (char *)(cgc_strlen ( tlv21 ) + 1); }
}
void fix_ingred_main_0_12(){
fix_ingred_main_0_12_0();
}
void fix_ingred_main_0_14_0(){
char tlv22_ref;
    bzero(&tlv22_ref,1*sizeof(char));
const char * tlv22 = &tlv22_ref;
    {unsigned int i; i = (unsigned int)(cgc_strlen ( tlv22 ) + 1); }
    {unsigned int rand; rand = (unsigned int)(cgc_strlen ( tlv22 ) + 1); }
    {char c; c = (char)(cgc_strlen ( tlv22 ) + 1); }
    {unsigned long tlv_size_0; tlv_size_0 = (unsigned long)(cgc_strlen ( tlv22 ) + 1); }
    {void * tlv5; tlv5 = (void *)(cgc_strlen ( tlv22 ) + 1); }
    {cgc_size_t tlv4; tlv4 = (cgc_size_t)(cgc_strlen ( tlv22 ) + 1); }
    {void * tlv8; tlv8 = (void *)(cgc_strlen ( tlv22 ) + 1); }
    {cgc_size_t tlv7; tlv7 = (cgc_size_t)(cgc_strlen ( tlv22 ) + 1); }
    {cgc_size_t tlv18; tlv18 = (cgc_size_t)(cgc_strlen ( tlv22 ) + 1); }
    {void * tlv11; tlv11 = (void *)(cgc_strlen ( tlv22 ) + 1); }
    {int tlv10; tlv10 = (int)(cgc_strlen ( tlv22 ) + 1); }
    {cgc_size_t tlv9; tlv9 = (cgc_size_t)(cgc_strlen ( tlv22 ) + 1); }
    {cgc_size_t tlv19; tlv19 = (cgc_size_t)(cgc_strlen ( tlv22 ) + 1); }
    {cgc_size_t tlv20; tlv20 = (cgc_size_t)(cgc_strlen ( tlv22 ) + 1); }
    {char * tlv13; tlv13 = (char *)(cgc_strlen ( tlv22 ) + 1); }
    {char * tlv15; tlv15 = (char *)(cgc_strlen ( tlv22 ) + 1); }
}
void fix_ingred_main_0_14(){
fix_ingred_main_0_14_0();
}
void fix_ingred_main_0_16_0(){
movie_t movie_ref;
    bzero(&movie_ref,1*sizeof(movie_t));
movie_t * movie = &movie_ref;
    {unsigned int i; i = (unsigned int)(movie -> title); }
    {unsigned int rand; rand = (unsigned int)(movie -> title); }
    {char c; c = (char)(movie -> title); }
    {unsigned long tlv_size_0; tlv_size_0 = (unsigned long)(movie -> title); }
    {void * tlv5; tlv5 = (void *)(movie -> title); }
    {cgc_size_t tlv4; tlv4 = (cgc_size_t)(movie -> title); }
    {void * tlv8; tlv8 = (void *)(movie -> title); }
    {cgc_size_t tlv7; tlv7 = (cgc_size_t)(movie -> title); }
    {cgc_size_t tlv18; tlv18 = (cgc_size_t)(movie -> title); }
    {void * tlv11; tlv11 = (void *)(movie -> title); }
    {int tlv10; tlv10 = (int)(movie -> title); }
    {cgc_size_t tlv9; tlv9 = (cgc_size_t)(movie -> title); }
    {cgc_size_t tlv19; tlv19 = (cgc_size_t)(movie -> title); }
    {cgc_size_t tlv20; tlv20 = (cgc_size_t)(movie -> title); }
    {char * tlv13; tlv13 = (char *)(movie -> title); }
    {char * tlv15; tlv15 = (char *)(movie -> title); }
}
void fix_ingred_main_0_16(){
fix_ingred_main_0_16_0();
}
void fix_ingred_main_0_17_0(){
movie_t movie_ref;
    bzero(&movie_ref,1*sizeof(movie_t));
movie_t * movie = &movie_ref;
    {unsigned int i; i = (unsigned int)(movie -> desc); }
    {unsigned int rand; rand = (unsigned int)(movie -> desc); }
    {char c; c = (char)(movie -> desc); }
    {unsigned long tlv_size_0; tlv_size_0 = (unsigned long)(movie -> desc); }
    {void * tlv5; tlv5 = (void *)(movie -> desc); }
    {cgc_size_t tlv4; tlv4 = (cgc_size_t)(movie -> desc); }
    {void * tlv8; tlv8 = (void *)(movie -> desc); }
    {cgc_size_t tlv7; tlv7 = (cgc_size_t)(movie -> desc); }
    {cgc_size_t tlv18; tlv18 = (cgc_size_t)(movie -> desc); }
    {void * tlv11; tlv11 = (void *)(movie -> desc); }
    {int tlv10; tlv10 = (int)(movie -> desc); }
    {cgc_size_t tlv9; tlv9 = (cgc_size_t)(movie -> desc); }
    {cgc_size_t tlv19; tlv19 = (cgc_size_t)(movie -> desc); }
    {cgc_size_t tlv20; tlv20 = (cgc_size_t)(movie -> desc); }
    {char * tlv13; tlv13 = (char *)(movie -> desc); }
    {char * tlv15; tlv15 = (char *)(movie -> desc); }
}
void fix_ingred_main_0_17(){
fix_ingred_main_0_17_0();
}
void fix_ingred_main_0(){
fix_ingred_main_0_2();
fix_ingred_main_0_3();
fix_ingred_main_0_4();
fix_ingred_main_0_8();
fix_ingred_main_0_10();
fix_ingred_main_0_12();
fix_ingred_main_0_14();
fix_ingred_main_0_16();
fix_ingred_main_0_17();
}
void fix_ingred_main_1_0_0(){
char buf_ref;
    bzero(&buf_ref,1*sizeof(char));
char * buf = &buf_ref;
    {cgc_size_t i; i = (cgc_size_t)(buf); }
    {char * c; c = (char *)(buf); }
    {cgc_size_t rx; rx = (cgc_size_t)(buf); }
    {int tlv1; tlv1 = (int)(buf); }
    {int tlv5; tlv5 = (int)(buf); }
    {void * tlv4; tlv4 = (void *)(buf); }
    {cgc_size_t tlv3; tlv3 = (cgc_size_t)(buf); }
}
void fix_ingred_main_1_0(){
fix_ingred_main_1_0_0();
}
void fix_ingred_main_1_1_1(){
cgc_size_t i;
    bzero(&i,sizeof(cgc_size_t));
cgc_size_t len;
    bzero(&len,sizeof(cgc_size_t));
    {cgc_size_t i; i = (cgc_size_t)(0); }
    {char * c; c = (char *)(0); }
    {cgc_size_t rx; rx = (cgc_size_t)(0); }
    {int tlv1; tlv1 = (int)(0); }
    {int tlv5; tlv5 = (int)(0); }
    {void * tlv4; tlv4 = (void *)(0); }
    {cgc_size_t tlv3; tlv3 = (cgc_size_t)(0); }
}
void fix_ingred_main_1_1_2(){
cgc_size_t i;
    bzero(&i,sizeof(cgc_size_t));
cgc_size_t len;
    bzero(&len,sizeof(cgc_size_t));
    {char * c; c = (char *)(i); }
    {cgc_size_t rx; rx = (cgc_size_t)(i); }
    {int tlv1; tlv1 = (int)(i); }
    {int tlv5; tlv5 = (int)(i); }
    {void * tlv4; tlv4 = (void *)(i); }
    {cgc_size_t tlv3; tlv3 = (cgc_size_t)(i); }
}
void fix_ingred_main_1_1_3(){
cgc_size_t i;
    bzero(&i,sizeof(cgc_size_t));
cgc_size_t len;
    bzero(&len,sizeof(cgc_size_t));
    {cgc_size_t i; i = (cgc_size_t)(len); }
    {char * c; c = (char *)(len); }
    {cgc_size_t rx; rx = (cgc_size_t)(len); }
    {int tlv1; tlv1 = (int)(len); }
    {int tlv5; tlv5 = (int)(len); }
    {void * tlv4; tlv4 = (void *)(len); }
    {cgc_size_t tlv3; tlv3 = (cgc_size_t)(len); }
}
void fix_ingred_main_1_1(){
fix_ingred_main_1_1_1();
fix_ingred_main_1_1_2();
fix_ingred_main_1_1_3();
}
void fix_ingred_main_1_2_0(){
int fd;
    bzero(&fd,sizeof(int));
char c_ref;
    bzero(&c_ref,1*sizeof(char));
char * c = &c_ref;
    {cgc_size_t i; i = (cgc_size_t)(fd); }
    {char * c; c = (char *)(fd); }
    {cgc_size_t rx; rx = (cgc_size_t)(fd); }
    {int tlv1; tlv1 = (int)(fd); }
    {int tlv5; tlv5 = (int)(fd); }
    {void * tlv4; tlv4 = (void *)(fd); }
    {cgc_size_t tlv3; tlv3 = (cgc_size_t)(fd); }
}
void fix_ingred_main_1_2_1(){
int fd;
    bzero(&fd,sizeof(int));
char c_ref;
    bzero(&c_ref,1*sizeof(char));
char * c = &c_ref;
    {cgc_size_t i; i = (cgc_size_t)(c); }
    {cgc_size_t rx; rx = (cgc_size_t)(c); }
    {int tlv1; tlv1 = (int)(c); }
    {int tlv5; tlv5 = (int)(c); }
    {void * tlv4; tlv4 = (void *)(c); }
    {cgc_size_t tlv3; tlv3 = (cgc_size_t)(c); }
}
void fix_ingred_main_1_2_2(){
int fd;
    bzero(&fd,sizeof(int));
char c_ref;
    bzero(&c_ref,1*sizeof(char));
char * c = &c_ref;
    {cgc_size_t i; i = (cgc_size_t)(1); }
    {char * c; c = (char *)(1); }
    {cgc_size_t rx; rx = (cgc_size_t)(1); }
    {int tlv1; tlv1 = (int)(1); }
    {int tlv5; tlv5 = (int)(1); }
    {void * tlv4; tlv4 = (void *)(1); }
    {cgc_size_t tlv3; tlv3 = (cgc_size_t)(1); }
}
void fix_ingred_main_1_2(){
fix_ingred_main_1_2_0();
fix_ingred_main_1_2_1();
fix_ingred_main_1_2_2();
}
void fix_ingred_main_1_3_4(){
int tlv1;
    bzero(&tlv1,sizeof(int));
cgc_size_t rx;
    bzero(&rx,sizeof(cgc_size_t));
    {cgc_size_t i; i = (cgc_size_t)(tlv1); }
    {char * c; c = (char *)(tlv1); }
    {cgc_size_t rx; rx = (cgc_size_t)(tlv1); }
    {int tlv5; tlv5 = (int)(tlv1); }
    {void * tlv4; tlv4 = (void *)(tlv1); }
    {cgc_size_t tlv3; tlv3 = (cgc_size_t)(tlv1); }
}
void fix_ingred_main_1_3_5(){
int tlv1;
    bzero(&tlv1,sizeof(int));
cgc_size_t rx;
    bzero(&rx,sizeof(cgc_size_t));
    {cgc_size_t i; i = (cgc_size_t)(0); }
    {char * c; c = (char *)(0); }
    {cgc_size_t rx; rx = (cgc_size_t)(0); }
    {int tlv1; tlv1 = (int)(0); }
    {int tlv5; tlv5 = (int)(0); }
    {void * tlv4; tlv4 = (void *)(0); }
    {cgc_size_t tlv3; tlv3 = (cgc_size_t)(0); }
}
void fix_ingred_main_1_3_6(){
int tlv1;
    bzero(&tlv1,sizeof(int));
cgc_size_t rx;
    bzero(&rx,sizeof(cgc_size_t));
    {cgc_size_t i; i = (cgc_size_t)(rx); }
    {char * c; c = (char *)(rx); }
    {int tlv1; tlv1 = (int)(rx); }
    {int tlv5; tlv5 = (int)(rx); }
    {void * tlv4; tlv4 = (void *)(rx); }
    {cgc_size_t tlv3; tlv3 = (cgc_size_t)(rx); }
}
void fix_ingred_main_1_3(){
fix_ingred_main_1_3_4();
fix_ingred_main_1_3_5();
fix_ingred_main_1_3_6();
}
void fix_ingred_main_1_4_4(){
char c_ref;
    bzero(&c_ref,1*sizeof(char));
char * c = &c_ref;
char delim;
    bzero(&delim,sizeof(char));
    {cgc_size_t i; i = (cgc_size_t)(* ( c ++ )); }
    {cgc_size_t rx; rx = (cgc_size_t)(* ( c ++ )); }
    {int tlv1; tlv1 = (int)(* ( c ++ )); }
    {int tlv5; tlv5 = (int)(* ( c ++ )); }
    {void * tlv4; tlv4 = (void *)(* ( c ++ )); }
    {cgc_size_t tlv3; tlv3 = (cgc_size_t)(* ( c ++ )); }
}
void fix_ingred_main_1_4_5(){
char c_ref;
    bzero(&c_ref,1*sizeof(char));
char * c = &c_ref;
char delim;
    bzero(&delim,sizeof(char));
    {cgc_size_t i; i = (cgc_size_t)(delim); }
    {char * c; c = (char *)(delim); }
    {cgc_size_t rx; rx = (cgc_size_t)(delim); }
    {int tlv1; tlv1 = (int)(delim); }
    {int tlv5; tlv5 = (int)(delim); }
    {void * tlv4; tlv4 = (void *)(delim); }
    {cgc_size_t tlv3; tlv3 = (cgc_size_t)(delim); }
}
void fix_ingred_main_1_4(){
fix_ingred_main_1_4_4();
fix_ingred_main_1_4_5();
}
void fix_ingred_main_1(){
fix_ingred_main_1_0();
fix_ingred_main_1_1();
fix_ingred_main_1_2();
fix_ingred_main_1_3();
fix_ingred_main_1_4();
}
void fix_ingred_main_2_3_0(){
    {char * rating_str; rating_str = (char *)("G"); }
    {char * genre_str; genre_str = (char *)("G"); }
    {char* format ; format  = (char*)("G"); }
}
void fix_ingred_main_2_3(){
fix_ingred_main_2_3_0();
}
void fix_ingred_main_2_4_0(){
    {char * rating_str; rating_str = (char *)("PG"); }
    {char * genre_str; genre_str = (char *)("PG"); }
    {char* format ; format  = (char*)("PG"); }
}
void fix_ingred_main_2_4(){
fix_ingred_main_2_4_0();
}
void fix_ingred_main_2_5_0(){
    {char * rating_str; rating_str = (char *)("PG13"); }
    {char * genre_str; genre_str = (char *)("PG13"); }
    {char* format ; format  = (char*)("PG13"); }
}
void fix_ingred_main_2_5(){
fix_ingred_main_2_5_0();
}
void fix_ingred_main_2_6_0(){
    {char * rating_str; rating_str = (char *)("R"); }
    {char * genre_str; genre_str = (char *)("R"); }
    {char* format ; format  = (char*)("R"); }
}
void fix_ingred_main_2_6(){
fix_ingred_main_2_6_0();
}
void fix_ingred_main_2_7_0(){
    {char * rating_str; rating_str = (char *)("Unknown"); }
    {char * genre_str; genre_str = (char *)("Unknown"); }
    {char* format ; format  = (char*)("Unknown"); }
}
void fix_ingred_main_2_7(){
fix_ingred_main_2_7_0();
}
void fix_ingred_main_2_9_0(){
    {char * rating_str; rating_str = (char *)("Action"); }
    {char * genre_str; genre_str = (char *)("Action"); }
    {char* format ; format  = (char*)("Action"); }
}
void fix_ingred_main_2_9(){
fix_ingred_main_2_9_0();
}
void fix_ingred_main_2_10_0(){
    {char * rating_str; rating_str = (char *)("Romance"); }
    {char * genre_str; genre_str = (char *)("Romance"); }
    {char* format ; format  = (char*)("Romance"); }
}
void fix_ingred_main_2_10(){
fix_ingred_main_2_10_0();
}
void fix_ingred_main_2_11_0(){
    {char * rating_str; rating_str = (char *)("Comedy"); }
    {char * genre_str; genre_str = (char *)("Comedy"); }
    {char* format ; format  = (char*)("Comedy"); }
}
void fix_ingred_main_2_11(){
fix_ingred_main_2_11_0();
}
void fix_ingred_main_2_12_0(){
    {char * rating_str; rating_str = (char *)("Horror"); }
    {char * genre_str; genre_str = (char *)("Horror"); }
    {char* format ; format  = (char*)("Horror"); }
}
void fix_ingred_main_2_12(){
fix_ingred_main_2_12_0();
}
void fix_ingred_main_2_13_0(){
    {char * rating_str; rating_str = (char *)("Other"); }
    {char * genre_str; genre_str = (char *)("Other"); }
    {char* format ; format  = (char*)("Other"); }
}
void fix_ingred_main_2_13(){
fix_ingred_main_2_13_0();
}
void fix_ingred_main_2(){
fix_ingred_main_2_3();
fix_ingred_main_2_4();
fix_ingred_main_2_5();
fix_ingred_main_2_6();
fix_ingred_main_2_7();
fix_ingred_main_2_9();
fix_ingred_main_2_10();
fix_ingred_main_2_11();
fix_ingred_main_2_12();
fix_ingred_main_2_13();
}
void fix_ingred_main_3_0_0(){
    {int num_movies; num_movies = (int)(0); }
}
void fix_ingred_main_3_0(){
fix_ingred_main_3_0_0();
}
void fix_ingred_main_3(){
fix_ingred_main_3_0();
}
void fix_ingred_main_4_0_0(){
    {unsigned int movie_id; movie_id = (unsigned int)(0); }
    {unsigned int num_movies; num_movies = (unsigned int)(0); }
    {char buf [ 256 ]; buf [ ( 256 )-1 ] = (char)(0); }
    {int tlv1; tlv1 = (int)(0); }
    {int tlv4; tlv4 = (int)(0); }
    {char * tlv6; tlv6 = (char *)(0); }
    {int tlv8; tlv8 = (int)(0); }
    {int tlv2; tlv2 = (int)(0); }
    {int tlv19; tlv19 = (int)(0); }
    {char * tlv18; tlv18 = (char *)(0); }
    {cgc_size_t tlv17; tlv17 = (cgc_size_t)(0); }
    {char tlv16; tlv16 = (char)(0); }
    {int tlv20; tlv20 = (int)(0); }
}
void fix_ingred_main_4_0(){
fix_ingred_main_4_0_0();
}
void fix_ingred_main_4_3_1(){
unsigned int num_movies;
    bzero(&num_movies,sizeof(unsigned int));
    {unsigned int movie_id; movie_id = (unsigned int)(num_movies); }
    {char buf [ 256 ]; buf [ ( 256 )-1 ] = (char)(num_movies); }
    {int tlv1; tlv1 = (int)(num_movies); }
    {int tlv4; tlv4 = (int)(num_movies); }
    {char * tlv6; tlv6 = (char *)(num_movies); }
    {int tlv8; tlv8 = (int)(num_movies); }
    {int tlv2; tlv2 = (int)(num_movies); }
    {int tlv19; tlv19 = (int)(num_movies); }
    {char * tlv18; tlv18 = (char *)(num_movies); }
    {cgc_size_t tlv17; tlv17 = (cgc_size_t)(num_movies); }
    {char tlv16; tlv16 = (char)(num_movies); }
    {int tlv20; tlv20 = (int)(num_movies); }
}
void fix_ingred_main_4_3(){
fix_ingred_main_4_3_1();
}
void fix_ingred_main_4_7_0(){
char buf [ 256 ];
    bzero(&buf,( 256 *sizeof(char) ) );
    {unsigned int movie_id; movie_id = (unsigned int)(STDIN); }
    {unsigned int num_movies; num_movies = (unsigned int)(STDIN); }
    {char buf [ 256 ]; buf [ ( 256 )-1 ] = (char)(STDIN); }
    {int tlv1; tlv1 = (int)(STDIN); }
    {int tlv4; tlv4 = (int)(STDIN); }
    {char * tlv6; tlv6 = (char *)(STDIN); }
    {int tlv8; tlv8 = (int)(STDIN); }
    {int tlv2; tlv2 = (int)(STDIN); }
    {int tlv19; tlv19 = (int)(STDIN); }
    {char * tlv18; tlv18 = (char *)(STDIN); }
    {cgc_size_t tlv17; tlv17 = (cgc_size_t)(STDIN); }
    {char tlv16; tlv16 = (char)(STDIN); }
    {int tlv20; tlv20 = (int)(STDIN); }
}
void fix_ingred_main_4_7_1(){
char buf [ 256 ];
    bzero(&buf,( 256 *sizeof(char) ) );
    {unsigned int movie_id; movie_id = (unsigned int)(buf); }
    {unsigned int num_movies; num_movies = (unsigned int)(buf); }
    {char buf [ 256 ]; buf [ ( 256 )-1 ] = (char)(buf); }
    {int tlv4; tlv4 = (int)(buf); }
    {char * tlv6; tlv6 = (char *)(buf); }
    {int tlv8; tlv8 = (int)(buf); }
    {int tlv2; tlv2 = (int)(buf); }
    {int tlv19; tlv19 = (int)(buf); }
    {char * tlv18; tlv18 = (char *)(buf); }
    {cgc_size_t tlv17; tlv17 = (cgc_size_t)(buf); }
    {char tlv16; tlv16 = (char)(buf); }
    {int tlv20; tlv20 = (int)(buf); }
}
void fix_ingred_main_4_7_2(){
char buf [ 256 ];
    bzero(&buf,( 256 *sizeof(char) ) );
    {unsigned int movie_id; movie_id = (unsigned int)(sizeof ( buf )); }
    {unsigned int num_movies; num_movies = (unsigned int)(sizeof ( buf )); }
    {char buf [ 256 ]; buf [ ( 256 )-1 ] = (char)(sizeof ( buf )); }
    {int tlv1; tlv1 = (int)(sizeof ( buf )); }
    {int tlv4; tlv4 = (int)(sizeof ( buf )); }
    {char * tlv6; tlv6 = (char *)(sizeof ( buf )); }
    {int tlv8; tlv8 = (int)(sizeof ( buf )); }
    {int tlv2; tlv2 = (int)(sizeof ( buf )); }
    {int tlv19; tlv19 = (int)(sizeof ( buf )); }
    {char * tlv18; tlv18 = (char *)(sizeof ( buf )); }
    {cgc_size_t tlv17; tlv17 = (cgc_size_t)(sizeof ( buf )); }
    {char tlv16; tlv16 = (char)(sizeof ( buf )); }
    {int tlv20; tlv20 = (int)(sizeof ( buf )); }
}
void fix_ingred_main_4_7_3(){
char buf [ 256 ];
    bzero(&buf,( 256 *sizeof(char) ) );
    {unsigned int movie_id; movie_id = (unsigned int)('\n'); }
    {unsigned int num_movies; num_movies = (unsigned int)('\n'); }
    {char buf [ 256 ]; buf [ ( 256 )-1 ] = (char)('\n'); }
    {int tlv1; tlv1 = (int)('\n'); }
    {int tlv4; tlv4 = (int)('\n'); }
    {char * tlv6; tlv6 = (char *)('\n'); }
    {int tlv8; tlv8 = (int)('\n'); }
    {int tlv2; tlv2 = (int)('\n'); }
    {int tlv19; tlv19 = (int)('\n'); }
    {char * tlv18; tlv18 = (char *)('\n'); }
    {cgc_size_t tlv17; tlv17 = (cgc_size_t)('\n'); }
    {char tlv16; tlv16 = (char)('\n'); }
    {int tlv20; tlv20 = (int)('\n'); }
}
void fix_ingred_main_4_7(){
fix_ingred_main_4_7_0();
fix_ingred_main_4_7_1();
fix_ingred_main_4_7_2();
fix_ingred_main_4_7_3();
}
void fix_ingred_main_4_8_1(){
int tlv2;
    bzero(&tlv2,sizeof(int));
    {unsigned int movie_id; movie_id = (unsigned int)(tlv2); }
    {unsigned int num_movies; num_movies = (unsigned int)(tlv2); }
    {char buf [ 256 ]; buf [ ( 256 )-1 ] = (char)(tlv2); }
    {int tlv1; tlv1 = (int)(tlv2); }
    {int tlv4; tlv4 = (int)(tlv2); }
    {char * tlv6; tlv6 = (char *)(tlv2); }
    {int tlv8; tlv8 = (int)(tlv2); }
    {int tlv19; tlv19 = (int)(tlv2); }
    {char * tlv18; tlv18 = (char *)(tlv2); }
    {cgc_size_t tlv17; tlv17 = (cgc_size_t)(tlv2); }
    {char tlv16; tlv16 = (char)(tlv2); }
    {int tlv20; tlv20 = (int)(tlv2); }
}
void fix_ingred_main_4_8_2(){
int tlv2;
    bzero(&tlv2,sizeof(int));
    {unsigned int movie_id; movie_id = (unsigned int)(0); }
    {unsigned int num_movies; num_movies = (unsigned int)(0); }
    {char buf [ 256 ]; buf [ ( 256 )-1 ] = (char)(0); }
    {int tlv4; tlv4 = (int)(0); }
    {char * tlv6; tlv6 = (char *)(0); }
    {int tlv8; tlv8 = (int)(0); }
    {int tlv2; tlv2 = (int)(0); }
    {int tlv19; tlv19 = (int)(0); }
    {char * tlv18; tlv18 = (char *)(0); }
    {cgc_size_t tlv17; tlv17 = (cgc_size_t)(0); }
    {char tlv16; tlv16 = (char)(0); }
    {int tlv20; tlv20 = (int)(0); }
}
void fix_ingred_main_4_8(){
fix_ingred_main_4_8_1();
fix_ingred_main_4_8_2();
}
void fix_ingred_main_4_9_1(){
    {unsigned int movie_id; movie_id = (unsigned int)(10); }
    {unsigned int num_movies; num_movies = (unsigned int)(10); }
    {char buf [ 256 ]; buf [ ( 256 )-1 ] = (char)(10); }
    {int tlv1; tlv1 = (int)(10); }
    {int tlv4; tlv4 = (int)(10); }
    {char * tlv6; tlv6 = (char *)(10); }
    {int tlv8; tlv8 = (int)(10); }
    {int tlv2; tlv2 = (int)(10); }
    {int tlv19; tlv19 = (int)(10); }
    {char * tlv18; tlv18 = (char *)(10); }
    {cgc_size_t tlv17; tlv17 = (cgc_size_t)(10); }
    {char tlv16; tlv16 = (char)(10); }
    {int tlv20; tlv20 = (int)(10); }
}
void fix_ingred_main_4_9(){
fix_ingred_main_4_9_1();
}
void fix_ingred_main_4_10_1(){
unsigned int movie_id;
    bzero(&movie_id,sizeof(unsigned int));
    {unsigned int num_movies; num_movies = (unsigned int)(movie_id); }
    {char buf [ 256 ]; buf [ ( 256 )-1 ] = (char)(movie_id); }
    {int tlv1; tlv1 = (int)(movie_id); }
    {int tlv4; tlv4 = (int)(movie_id); }
    {char * tlv6; tlv6 = (char *)(movie_id); }
    {int tlv8; tlv8 = (int)(movie_id); }
    {int tlv2; tlv2 = (int)(movie_id); }
    {int tlv19; tlv19 = (int)(movie_id); }
    {char * tlv18; tlv18 = (char *)(movie_id); }
    {cgc_size_t tlv17; tlv17 = (cgc_size_t)(movie_id); }
    {char tlv16; tlv16 = (char)(movie_id); }
    {int tlv20; tlv20 = (int)(movie_id); }
}
void fix_ingred_main_4_10_2(){
unsigned int movie_id;
    bzero(&movie_id,sizeof(unsigned int));
    {unsigned int movie_id; movie_id = (unsigned int)(1); }
    {unsigned int num_movies; num_movies = (unsigned int)(1); }
    {char buf [ 256 ]; buf [ ( 256 )-1 ] = (char)(1); }
    {int tlv1; tlv1 = (int)(1); }
    {int tlv4; tlv4 = (int)(1); }
    {char * tlv6; tlv6 = (char *)(1); }
    {int tlv8; tlv8 = (int)(1); }
    {int tlv2; tlv2 = (int)(1); }
    {int tlv19; tlv19 = (int)(1); }
    {char * tlv18; tlv18 = (char *)(1); }
    {cgc_size_t tlv17; tlv17 = (cgc_size_t)(1); }
    {char tlv16; tlv16 = (char)(1); }
    {int tlv20; tlv20 = (int)(1); }
}
void fix_ingred_main_4_10(){
fix_ingred_main_4_10_1();
fix_ingred_main_4_10_2();
}
void fix_ingred_main_4_12_1(){
unsigned int movie_id;
    bzero(&movie_id,sizeof(unsigned int));
    {unsigned int num_movies; num_movies = (unsigned int)(movie_id); }
    {char buf [ 256 ]; buf [ ( 256 )-1 ] = (char)(movie_id); }
    {int tlv1; tlv1 = (int)(movie_id); }
    {int tlv4; tlv4 = (int)(movie_id); }
    {char * tlv6; tlv6 = (char *)(movie_id); }
    {int tlv8; tlv8 = (int)(movie_id); }
    {int tlv2; tlv2 = (int)(movie_id); }
    {int tlv19; tlv19 = (int)(movie_id); }
    {char * tlv18; tlv18 = (char *)(movie_id); }
    {cgc_size_t tlv17; tlv17 = (cgc_size_t)(movie_id); }
    {char tlv16; tlv16 = (char)(movie_id); }
    {int tlv20; tlv20 = (int)(movie_id); }
}
void fix_ingred_main_4_12(){
fix_ingred_main_4_12_1();
}
void fix_ingred_main_4_13_1(){
movie_t movie_ref;
    bzero(&movie_ref,1*sizeof(movie_t));
movie_t * movie = &movie_ref;
    {unsigned int movie_id; movie_id = (unsigned int)(movie -> title); }
    {unsigned int num_movies; num_movies = (unsigned int)(movie -> title); }
    {char buf [ 256 ]; buf [ ( 256 )-1 ] = (char)(movie -> title); }
    {int tlv1; tlv1 = (int)(movie -> title); }
    {int tlv4; tlv4 = (int)(movie -> title); }
    {char * tlv6; tlv6 = (char *)(movie -> title); }
    {int tlv8; tlv8 = (int)(movie -> title); }
    {int tlv2; tlv2 = (int)(movie -> title); }
    {int tlv19; tlv19 = (int)(movie -> title); }
    {char * tlv18; tlv18 = (char *)(movie -> title); }
    {cgc_size_t tlv17; tlv17 = (cgc_size_t)(movie -> title); }
    {char tlv16; tlv16 = (char)(movie -> title); }
    {int tlv20; tlv20 = (int)(movie -> title); }
}
void fix_ingred_main_4_13(){
fix_ingred_main_4_13_1();
}
void fix_ingred_main_4_17_2(){
int tlv1;
    bzero(&tlv1,sizeof(int));
    {unsigned int movie_id; movie_id = (unsigned int)(tlv1); }
    {unsigned int num_movies; num_movies = (unsigned int)(tlv1); }
    {char buf [ 256 ]; buf [ ( 256 )-1 ] = (char)(tlv1); }
    {int tlv4; tlv4 = (int)(tlv1); }
    {char * tlv6; tlv6 = (char *)(tlv1); }
    {int tlv8; tlv8 = (int)(tlv1); }
    {int tlv2; tlv2 = (int)(tlv1); }
    {int tlv19; tlv19 = (int)(tlv1); }
    {char * tlv18; tlv18 = (char *)(tlv1); }
    {cgc_size_t tlv17; tlv17 = (cgc_size_t)(tlv1); }
    {char tlv16; tlv16 = (char)(tlv1); }
    {int tlv20; tlv20 = (int)(tlv1); }
}
void fix_ingred_main_4_17(){
fix_ingred_main_4_17_2();
}
void fix_ingred_main_4(){
fix_ingred_main_4_0();
fix_ingred_main_4_3();
fix_ingred_main_4_7();
fix_ingred_main_4_8();
fix_ingred_main_4_9();
fix_ingred_main_4_10();
fix_ingred_main_4_12();
fix_ingred_main_4_13();
fix_ingred_main_4_17();
}
void fix_ingred_main_5_0_0(){
    {int tlv6; tlv6 = (int)(0); }
    {int tlv16; tlv16 = (int)(0); }
    {cgc_size_t tlv14; tlv14 = (cgc_size_t)(0); }
    {char tlv13; tlv13 = (char)(0); }
    {int tlv17; tlv17 = (int)(0); }
}
void fix_ingred_main_5_0(){
fix_ingred_main_5_0_0();
}
void fix_ingred_main_5_3_1(){
unsigned int num_movies;
    bzero(&num_movies,sizeof(unsigned int));
    {int tlv6; tlv6 = (int)(num_movies); }
    {int tlv16; tlv16 = (int)(num_movies); }
    {char * tlv15; tlv15 = (char *)(num_movies); }
    {cgc_size_t tlv14; tlv14 = (cgc_size_t)(num_movies); }
    {char tlv13; tlv13 = (char)(num_movies); }
    {int tlv17; tlv17 = (int)(num_movies); }
}
void fix_ingred_main_5_3(){
fix_ingred_main_5_3_1();
}
void fix_ingred_main_5_7_0(){
char buf [ 256 ];
    bzero(&buf,( 256 *sizeof(char) ) );
    {int tlv6; tlv6 = (int)(STDIN); }
    {int tlv16; tlv16 = (int)(STDIN); }
    {char * tlv15; tlv15 = (char *)(STDIN); }
    {cgc_size_t tlv14; tlv14 = (cgc_size_t)(STDIN); }
    {char tlv13; tlv13 = (char)(STDIN); }
    {int tlv17; tlv17 = (int)(STDIN); }
}
void fix_ingred_main_5_7_1(){
char buf [ 256 ];
    bzero(&buf,( 256 *sizeof(char) ) );
    {int tlv6; tlv6 = (int)(buf); }
    {int tlv16; tlv16 = (int)(buf); }
    {char * tlv15; tlv15 = (char *)(buf); }
    {cgc_size_t tlv14; tlv14 = (cgc_size_t)(buf); }
    {char tlv13; tlv13 = (char)(buf); }
    {int tlv17; tlv17 = (int)(buf); }
}
void fix_ingred_main_5_7_2(){
char buf [ 256 ];
    bzero(&buf,( 256 *sizeof(char) ) );
    {int tlv6; tlv6 = (int)(sizeof ( buf )); }
    {int tlv16; tlv16 = (int)(sizeof ( buf )); }
    {char * tlv15; tlv15 = (char *)(sizeof ( buf )); }
    {cgc_size_t tlv14; tlv14 = (cgc_size_t)(sizeof ( buf )); }
    {char tlv13; tlv13 = (char)(sizeof ( buf )); }
    {int tlv17; tlv17 = (int)(sizeof ( buf )); }
}
void fix_ingred_main_5_7_3(){
char buf [ 256 ];
    bzero(&buf,( 256 *sizeof(char) ) );
    {int tlv6; tlv6 = (int)('\n'); }
    {int tlv16; tlv16 = (int)('\n'); }
    {char * tlv15; tlv15 = (char *)('\n'); }
    {cgc_size_t tlv14; tlv14 = (cgc_size_t)('\n'); }
    {char tlv13; tlv13 = (char)('\n'); }
    {int tlv17; tlv17 = (int)('\n'); }
}
void fix_ingred_main_5_7(){
fix_ingred_main_5_7_0();
fix_ingred_main_5_7_1();
fix_ingred_main_5_7_2();
fix_ingred_main_5_7_3();
}
void fix_ingred_main_5_8_1(){
int tlv2;
    bzero(&tlv2,sizeof(int));
    {int tlv6; tlv6 = (int)(tlv2); }
    {int tlv16; tlv16 = (int)(tlv2); }
    {char * tlv15; tlv15 = (char *)(tlv2); }
    {cgc_size_t tlv14; tlv14 = (cgc_size_t)(tlv2); }
    {char tlv13; tlv13 = (char)(tlv2); }
    {int tlv17; tlv17 = (int)(tlv2); }
}
void fix_ingred_main_5_8_2(){
int tlv2;
    bzero(&tlv2,sizeof(int));
    {int tlv6; tlv6 = (int)(0); }
    {int tlv16; tlv16 = (int)(0); }
    {char * tlv15; tlv15 = (char *)(0); }
    {cgc_size_t tlv14; tlv14 = (cgc_size_t)(0); }
    {char tlv13; tlv13 = (char)(0); }
    {int tlv17; tlv17 = (int)(0); }
}
void fix_ingred_main_5_8(){
fix_ingred_main_5_8_1();
fix_ingred_main_5_8_2();
}
void fix_ingred_main_5_9_1(){
    {int tlv6; tlv6 = (int)(10); }
    {int tlv16; tlv16 = (int)(10); }
    {char * tlv15; tlv15 = (char *)(10); }
    {cgc_size_t tlv14; tlv14 = (cgc_size_t)(10); }
    {char tlv13; tlv13 = (char)(10); }
    {int tlv17; tlv17 = (int)(10); }
}
void fix_ingred_main_5_9(){
fix_ingred_main_5_9_1();
}
void fix_ingred_main_5_10_1(){
unsigned int movie_id;
    bzero(&movie_id,sizeof(unsigned int));
    {int tlv6; tlv6 = (int)(movie_id); }
    {int tlv16; tlv16 = (int)(movie_id); }
    {char * tlv15; tlv15 = (char *)(movie_id); }
    {cgc_size_t tlv14; tlv14 = (cgc_size_t)(movie_id); }
    {char tlv13; tlv13 = (char)(movie_id); }
    {int tlv17; tlv17 = (int)(movie_id); }
}
void fix_ingred_main_5_10_2(){
unsigned int movie_id;
    bzero(&movie_id,sizeof(unsigned int));
    {int tlv6; tlv6 = (int)(1); }
    {int tlv16; tlv16 = (int)(1); }
    {char * tlv15; tlv15 = (char *)(1); }
    {cgc_size_t tlv14; tlv14 = (cgc_size_t)(1); }
    {char tlv13; tlv13 = (char)(1); }
    {int tlv17; tlv17 = (int)(1); }
}
void fix_ingred_main_5_10(){
fix_ingred_main_5_10_1();
fix_ingred_main_5_10_2();
}
void fix_ingred_main_5_12_1(){
unsigned int movie_id;
    bzero(&movie_id,sizeof(unsigned int));
    {int tlv6; tlv6 = (int)(movie_id); }
    {int tlv16; tlv16 = (int)(movie_id); }
    {char * tlv15; tlv15 = (char *)(movie_id); }
    {cgc_size_t tlv14; tlv14 = (cgc_size_t)(movie_id); }
    {char tlv13; tlv13 = (char)(movie_id); }
    {int tlv17; tlv17 = (int)(movie_id); }
}
void fix_ingred_main_5_12(){
fix_ingred_main_5_12_1();
}
void fix_ingred_main_5_16_1(){
int tlv1;
    bzero(&tlv1,sizeof(int));
    {int tlv6; tlv6 = (int)(tlv1); }
    {int tlv16; tlv16 = (int)(tlv1); }
    {char * tlv15; tlv15 = (char *)(tlv1); }
    {cgc_size_t tlv14; tlv14 = (cgc_size_t)(tlv1); }
    {char tlv13; tlv13 = (char)(tlv1); }
    {int tlv17; tlv17 = (int)(tlv1); }
}
void fix_ingred_main_5_16(){
fix_ingred_main_5_16_1();
}
void fix_ingred_main_5(){
fix_ingred_main_5_0();
fix_ingred_main_5_3();
fix_ingred_main_5_7();
fix_ingred_main_5_8();
fix_ingred_main_5_9();
fix_ingred_main_5_10();
fix_ingred_main_5_12();
fix_ingred_main_5_16();
}
void fix_ingred_main_6_0_0(){
    {int admin; admin = (int)(0); }
    {char buf [ 64 ]; buf [ ( 64 )-1 ] = (char)(0); }
    {char* username ; username  = (char*)(0); }
    {int tlv7; tlv7 = (int)(0); }
    {cgc_size_t tlv5; tlv5 = (cgc_size_t)(0); }
    {char tlv4; tlv4 = (char)(0); }
    {int tlv12; tlv12 = (int)(0); }
    {char * tlv11; tlv11 = (char *)(0); }
    {cgc_size_t tlv10; tlv10 = (cgc_size_t)(0); }
    {char tlv9; tlv9 = (char)(0); }
}
void fix_ingred_main_6_0_1(){
    {int admin; admin = (int)(1); }
    {char buf [ 64 ]; buf [ ( 64 )-1 ] = (char)(1); }
    {char* username ; username  = (char*)(1); }
    {int tlv1; tlv1 = (int)(1); }
    {int tlv2; tlv2 = (int)(1); }
    {int tlv7; tlv7 = (int)(1); }
    {char * tlv6; tlv6 = (char *)(1); }
    {cgc_size_t tlv5; tlv5 = (cgc_size_t)(1); }
    {char tlv4; tlv4 = (char)(1); }
    {int tlv12; tlv12 = (int)(1); }
    {char * tlv11; tlv11 = (char *)(1); }
    {cgc_size_t tlv10; tlv10 = (cgc_size_t)(1); }
    {char tlv9; tlv9 = (char)(1); }
}
void fix_ingred_main_6_0(){
fix_ingred_main_6_0_0();
fix_ingred_main_6_0_1();
}
void fix_ingred_main_6_2_0(){
char buf [ 64 ];
    bzero(&buf,( 64 *sizeof(char) ) );
    {int admin; admin = (int)(STDIN); }
    {char buf [ 64 ]; buf [ ( 64 )-1 ] = (char)(STDIN); }
    {char* username ; username  = (char*)(STDIN); }
    {int tlv7; tlv7 = (int)(STDIN); }
    {cgc_size_t tlv5; tlv5 = (cgc_size_t)(STDIN); }
    {char tlv4; tlv4 = (char)(STDIN); }
    {int tlv12; tlv12 = (int)(STDIN); }
    {char * tlv11; tlv11 = (char *)(STDIN); }
    {cgc_size_t tlv10; tlv10 = (cgc_size_t)(STDIN); }
    {char tlv9; tlv9 = (char)(STDIN); }
}
void fix_ingred_main_6_2_1(){
char buf [ 64 ];
    bzero(&buf,( 64 *sizeof(char) ) );
    {int admin; admin = (int)(buf); }
    {char buf [ 64 ]; buf [ ( 64 )-1 ] = (char)(buf); }
    {char* username ; username  = (char*)(buf); }
    {int tlv7; tlv7 = (int)(buf); }
    {cgc_size_t tlv5; tlv5 = (cgc_size_t)(buf); }
    {char tlv4; tlv4 = (char)(buf); }
    {int tlv12; tlv12 = (int)(buf); }
    {char * tlv11; tlv11 = (char *)(buf); }
    {cgc_size_t tlv10; tlv10 = (cgc_size_t)(buf); }
    {char tlv9; tlv9 = (char)(buf); }
}
void fix_ingred_main_6_2_2(){
char buf [ 64 ];
    bzero(&buf,( 64 *sizeof(char) ) );
    {int admin; admin = (int)(sizeof ( buf )); }
    {char buf [ 64 ]; buf [ ( 64 )-1 ] = (char)(sizeof ( buf )); }
    {char* username ; username  = (char*)(sizeof ( buf )); }
    {int tlv7; tlv7 = (int)(sizeof ( buf )); }
    {cgc_size_t tlv5; tlv5 = (cgc_size_t)(sizeof ( buf )); }
    {char tlv4; tlv4 = (char)(sizeof ( buf )); }
    {int tlv12; tlv12 = (int)(sizeof ( buf )); }
    {char * tlv11; tlv11 = (char *)(sizeof ( buf )); }
    {cgc_size_t tlv10; tlv10 = (cgc_size_t)(sizeof ( buf )); }
    {char tlv9; tlv9 = (char)(sizeof ( buf )); }
}
void fix_ingred_main_6_2_3(){
char buf [ 64 ];
    bzero(&buf,( 64 *sizeof(char) ) );
    {int admin; admin = (int)('\n'); }
    {char buf [ 64 ]; buf [ ( 64 )-1 ] = (char)('\n'); }
    {char* username ; username  = (char*)('\n'); }
    {int tlv7; tlv7 = (int)('\n'); }
    {cgc_size_t tlv5; tlv5 = (cgc_size_t)('\n'); }
    {char tlv4; tlv4 = (char)('\n'); }
    {int tlv12; tlv12 = (int)('\n'); }
    {char * tlv11; tlv11 = (char *)('\n'); }
    {cgc_size_t tlv10; tlv10 = (cgc_size_t)('\n'); }
    {char tlv9; tlv9 = (char)('\n'); }
}
void fix_ingred_main_6_2(){
fix_ingred_main_6_2_0();
fix_ingred_main_6_2_1();
fix_ingred_main_6_2_2();
fix_ingred_main_6_2_3();
}
void fix_ingred_main_6_4_1(){
int tlv1;
    bzero(&tlv1,sizeof(int));
    {int admin; admin = (int)(tlv1); }
    {char buf [ 64 ]; buf [ ( 64 )-1 ] = (char)(tlv1); }
    {char* username ; username  = (char*)(tlv1); }
    {int tlv7; tlv7 = (int)(tlv1); }
    {cgc_size_t tlv5; tlv5 = (cgc_size_t)(tlv1); }
    {char tlv4; tlv4 = (char)(tlv1); }
    {int tlv12; tlv12 = (int)(tlv1); }
    {char * tlv11; tlv11 = (char *)(tlv1); }
    {cgc_size_t tlv10; tlv10 = (cgc_size_t)(tlv1); }
    {char tlv9; tlv9 = (char)(tlv1); }
}
void fix_ingred_main_6_4(){
fix_ingred_main_6_4_1();
}
void fix_ingred_main_6_7_2(){
char buf [ 64 ];
    bzero(&buf,( 64 *sizeof(char) ) );
    {int admin; admin = (int)(sizeof ( buf ) + 4); }
    {char buf [ 64 ]; buf [ ( 64 )-1 ] = (char)(sizeof ( buf ) + 4); }
    {char* username ; username  = (char*)(sizeof ( buf ) + 4); }
    {int tlv1; tlv1 = (int)(sizeof ( buf ) + 4); }
    {int tlv2; tlv2 = (int)(sizeof ( buf ) + 4); }
    {int tlv7; tlv7 = (int)(sizeof ( buf ) + 4); }
    {char * tlv6; tlv6 = (char *)(sizeof ( buf ) + 4); }
    {cgc_size_t tlv5; tlv5 = (cgc_size_t)(sizeof ( buf ) + 4); }
    {char tlv4; tlv4 = (char)(sizeof ( buf ) + 4); }
    {int tlv12; tlv12 = (int)(sizeof ( buf ) + 4); }
    {char * tlv11; tlv11 = (char *)(sizeof ( buf ) + 4); }
    {cgc_size_t tlv10; tlv10 = (cgc_size_t)(sizeof ( buf ) + 4); }
    {char tlv9; tlv9 = (char)(sizeof ( buf ) + 4); }
}
void fix_ingred_main_6_7(){
fix_ingred_main_6_7_2();
}
void fix_ingred_main_6_9_1(){
int tlv2;
    bzero(&tlv2,sizeof(int));
    {int admin; admin = (int)(tlv2); }
    {char buf [ 64 ]; buf [ ( 64 )-1 ] = (char)(tlv2); }
    {char* username ; username  = (char*)(tlv2); }
    {int tlv7; tlv7 = (int)(tlv2); }
    {cgc_size_t tlv5; tlv5 = (cgc_size_t)(tlv2); }
    {char tlv4; tlv4 = (char)(tlv2); }
    {int tlv12; tlv12 = (int)(tlv2); }
    {char * tlv11; tlv11 = (char *)(tlv2); }
    {cgc_size_t tlv10; tlv10 = (cgc_size_t)(tlv2); }
    {char tlv9; tlv9 = (char)(tlv2); }
}
void fix_ingred_main_6_9(){
fix_ingred_main_6_9_1();
}
void fix_ingred_main_6(){
fix_ingred_main_6_0();
fix_ingred_main_6_2();
fix_ingred_main_6_4();
fix_ingred_main_6_7();
fix_ingred_main_6_9();
}
void fix_ingred_main_7_0_0(){
    {char buf [ 1024 ]; buf [ ( 1024 )-1 ] = (char)(0); }
    {int finish; finish = (int)(0); }
    {int tlv3; tlv3 = (int)(0); }
    {cgc_size_t tlv25; tlv25 = (cgc_size_t)(0); }
    {int tlv18; tlv18 = (int)(0); }
    {char * tlv17; tlv17 = (char *)(0); }
    {cgc_size_t tlv16; tlv16 = (cgc_size_t)(0); }
    {char tlv15; tlv15 = (char)(0); }
    {cgc_size_t tlv26; tlv26 = (cgc_size_t)(0); }
    {int tlv22; tlv22 = (int)(0); }
    {char * tlv21; tlv21 = (char *)(0); }
    {cgc_size_t tlv20; tlv20 = (cgc_size_t)(0); }
    {char tlv19; tlv19 = (char)(0); }
    {cgc_size_t tlv27; tlv27 = (cgc_size_t)(0); }
    {char * tlv14; tlv14 = (char *)(0); }
    {unsigned int genre; genre = (unsigned int)(0); }
    {unsigned int rating; rating = (unsigned int)(0); }
    {int tlv38; tlv38 = (int)(0); }
    {char * tlv37; tlv37 = (char *)(0); }
    {cgc_size_t tlv36; tlv36 = (cgc_size_t)(0); }
    {char tlv35; tlv35 = (char)(0); }
    {int tlv39; tlv39 = (int)(0); }
    {int tlv45; tlv45 = (int)(0); }
    {char * tlv44; tlv44 = (char *)(0); }
    {cgc_size_t tlv43; tlv43 = (cgc_size_t)(0); }
    {char tlv42; tlv42 = (char)(0); }
    {int tlv46; tlv46 = (int)(0); }
    {int tlv52; tlv52 = (int)(0); }
    {char * tlv51; tlv51 = (char *)(0); }
    {cgc_size_t tlv50; tlv50 = (cgc_size_t)(0); }
    {char tlv49; tlv49 = (char)(0); }
    {int tlv53; tlv53 = (int)(0); }
    {int tlv59; tlv59 = (int)(0); }
    {char * tlv58; tlv58 = (char *)(0); }
    {cgc_size_t tlv57; tlv57 = (cgc_size_t)(0); }
    {char tlv56; tlv56 = (char)(0); }
    {int tlv60; tlv60 = (int)(0); }
    {void * tlv65; tlv65 = (void *)(0); }
    {void * tlv66; tlv66 = (void *)(0); }
}
void fix_ingred_main_7_0(){
fix_ingred_main_7_0_0();
}
void fix_ingred_main_7_1_0(){
    {char buf [ 1024 ]; buf [ ( 1024 )-1 ] = (char)(sizeof ( movie_t )); }
    {int tlv1; tlv1 = (int)(sizeof ( movie_t )); }
    {int tlv2; tlv2 = (int)(sizeof ( movie_t )); }
    {int finish; finish = (int)(sizeof ( movie_t )); }
    {int tlv3; tlv3 = (int)(sizeof ( movie_t )); }
    {cgc_size_t tlv25; tlv25 = (cgc_size_t)(sizeof ( movie_t )); }
    {int tlv18; tlv18 = (int)(sizeof ( movie_t )); }
    {char * tlv17; tlv17 = (char *)(sizeof ( movie_t )); }
    {cgc_size_t tlv16; tlv16 = (cgc_size_t)(sizeof ( movie_t )); }
    {char tlv15; tlv15 = (char)(sizeof ( movie_t )); }
    {cgc_size_t tlv26; tlv26 = (cgc_size_t)(sizeof ( movie_t )); }
    {char * tlv11; tlv11 = (char *)(sizeof ( movie_t )); }
    {int tlv22; tlv22 = (int)(sizeof ( movie_t )); }
    {char * tlv21; tlv21 = (char *)(sizeof ( movie_t )); }
    {char tlv19; tlv19 = (char)(sizeof ( movie_t )); }
    {cgc_size_t tlv27; tlv27 = (cgc_size_t)(sizeof ( movie_t )); }
    {char * tlv14; tlv14 = (char *)(sizeof ( movie_t )); }
    {int tlv4; tlv4 = (int)(sizeof ( movie_t )); }
    {int tlv5; tlv5 = (int)(sizeof ( movie_t )); }
    {int tlv6; tlv6 = (int)(sizeof ( movie_t )); }
    {unsigned int genre; genre = (unsigned int)(sizeof ( movie_t )); }
    {int tlv7; tlv7 = (int)(sizeof ( movie_t )); }
    {unsigned int rating; rating = (unsigned int)(sizeof ( movie_t )); }
    {int tlv38; tlv38 = (int)(sizeof ( movie_t )); }
    {char * tlv37; tlv37 = (char *)(sizeof ( movie_t )); }
    {cgc_size_t tlv36; tlv36 = (cgc_size_t)(sizeof ( movie_t )); }
    {char tlv35; tlv35 = (char)(sizeof ( movie_t )); }
    {int tlv39; tlv39 = (int)(sizeof ( movie_t )); }
    {int tlv45; tlv45 = (int)(sizeof ( movie_t )); }
    {char * tlv44; tlv44 = (char *)(sizeof ( movie_t )); }
    {cgc_size_t tlv43; tlv43 = (cgc_size_t)(sizeof ( movie_t )); }
    {char tlv42; tlv42 = (char)(sizeof ( movie_t )); }
    {int tlv46; tlv46 = (int)(sizeof ( movie_t )); }
    {int tlv52; tlv52 = (int)(sizeof ( movie_t )); }
    {char * tlv51; tlv51 = (char *)(sizeof ( movie_t )); }
    {cgc_size_t tlv50; tlv50 = (cgc_size_t)(sizeof ( movie_t )); }
    {char tlv49; tlv49 = (char)(sizeof ( movie_t )); }
    {int tlv53; tlv53 = (int)(sizeof ( movie_t )); }
    {int tlv59; tlv59 = (int)(sizeof ( movie_t )); }
    {char * tlv58; tlv58 = (char *)(sizeof ( movie_t )); }
    {cgc_size_t tlv57; tlv57 = (cgc_size_t)(sizeof ( movie_t )); }
    {char tlv56; tlv56 = (char)(sizeof ( movie_t )); }
    {int tlv60; tlv60 = (int)(sizeof ( movie_t )); }
    {void * tlv65; tlv65 = (void *)(sizeof ( movie_t )); }
    {void * tlv66; tlv66 = (void *)(sizeof ( movie_t )); }
}
void fix_ingred_main_7_1(){
fix_ingred_main_7_1_0();
}
void fix_ingred_main_7_5_0(){
char buf [ 1024 ];
    bzero(&buf,( 1024 *sizeof(char) ) );
    {char buf [ 1024 ]; buf [ ( 1024 )-1 ] = (char)(STDIN); }
    {int finish; finish = (int)(STDIN); }
    {int tlv3; tlv3 = (int)(STDIN); }
    {cgc_size_t tlv25; tlv25 = (cgc_size_t)(STDIN); }
    {int tlv18; tlv18 = (int)(STDIN); }
    {char * tlv17; tlv17 = (char *)(STDIN); }
    {cgc_size_t tlv16; tlv16 = (cgc_size_t)(STDIN); }
    {char tlv15; tlv15 = (char)(STDIN); }
    {cgc_size_t tlv26; tlv26 = (cgc_size_t)(STDIN); }
    {int tlv22; tlv22 = (int)(STDIN); }
    {char * tlv21; tlv21 = (char *)(STDIN); }
    {cgc_size_t tlv20; tlv20 = (cgc_size_t)(STDIN); }
    {char tlv19; tlv19 = (char)(STDIN); }
    {cgc_size_t tlv27; tlv27 = (cgc_size_t)(STDIN); }
    {char * tlv14; tlv14 = (char *)(STDIN); }
    {int tlv5; tlv5 = (int)(STDIN); }
    {unsigned int genre; genre = (unsigned int)(STDIN); }
    {unsigned int rating; rating = (unsigned int)(STDIN); }
    {int tlv38; tlv38 = (int)(STDIN); }
    {char * tlv37; tlv37 = (char *)(STDIN); }
    {cgc_size_t tlv36; tlv36 = (cgc_size_t)(STDIN); }
    {char tlv35; tlv35 = (char)(STDIN); }
    {int tlv39; tlv39 = (int)(STDIN); }
    {int tlv45; tlv45 = (int)(STDIN); }
    {char * tlv44; tlv44 = (char *)(STDIN); }
    {cgc_size_t tlv43; tlv43 = (cgc_size_t)(STDIN); }
    {char tlv42; tlv42 = (char)(STDIN); }
    {int tlv46; tlv46 = (int)(STDIN); }
    {int tlv52; tlv52 = (int)(STDIN); }
    {char * tlv51; tlv51 = (char *)(STDIN); }
    {cgc_size_t tlv50; tlv50 = (cgc_size_t)(STDIN); }
    {char tlv49; tlv49 = (char)(STDIN); }
    {int tlv53; tlv53 = (int)(STDIN); }
    {int tlv59; tlv59 = (int)(STDIN); }
    {char * tlv58; tlv58 = (char *)(STDIN); }
    {cgc_size_t tlv57; tlv57 = (cgc_size_t)(STDIN); }
    {char tlv56; tlv56 = (char)(STDIN); }
    {int tlv60; tlv60 = (int)(STDIN); }
    {void * tlv65; tlv65 = (void *)(STDIN); }
    {void * tlv66; tlv66 = (void *)(STDIN); }
}
void fix_ingred_main_7_5_1(){
char buf [ 1024 ];
    bzero(&buf,( 1024 *sizeof(char) ) );
    {char buf [ 1024 ]; buf [ ( 1024 )-1 ] = (char)(buf); }
    {int finish; finish = (int)(buf); }
    {int tlv3; tlv3 = (int)(buf); }
    {cgc_size_t tlv25; tlv25 = (cgc_size_t)(buf); }
    {int tlv18; tlv18 = (int)(buf); }
    {char * tlv17; tlv17 = (char *)(buf); }
    {cgc_size_t tlv16; tlv16 = (cgc_size_t)(buf); }
    {char tlv15; tlv15 = (char)(buf); }
    {cgc_size_t tlv26; tlv26 = (cgc_size_t)(buf); }
    {int tlv22; tlv22 = (int)(buf); }
    {char * tlv21; tlv21 = (char *)(buf); }
    {cgc_size_t tlv20; tlv20 = (cgc_size_t)(buf); }
    {char tlv19; tlv19 = (char)(buf); }
    {cgc_size_t tlv27; tlv27 = (cgc_size_t)(buf); }
    {char * tlv14; tlv14 = (char *)(buf); }
    {unsigned int genre; genre = (unsigned int)(buf); }
    {unsigned int rating; rating = (unsigned int)(buf); }
    {int tlv38; tlv38 = (int)(buf); }
    {char * tlv37; tlv37 = (char *)(buf); }
    {cgc_size_t tlv36; tlv36 = (cgc_size_t)(buf); }
    {char tlv35; tlv35 = (char)(buf); }
    {int tlv39; tlv39 = (int)(buf); }
    {int tlv45; tlv45 = (int)(buf); }
    {char * tlv44; tlv44 = (char *)(buf); }
    {cgc_size_t tlv43; tlv43 = (cgc_size_t)(buf); }
    {char tlv42; tlv42 = (char)(buf); }
    {int tlv46; tlv46 = (int)(buf); }
    {int tlv52; tlv52 = (int)(buf); }
    {char * tlv51; tlv51 = (char *)(buf); }
    {cgc_size_t tlv50; tlv50 = (cgc_size_t)(buf); }
    {char tlv49; tlv49 = (char)(buf); }
    {int tlv53; tlv53 = (int)(buf); }
    {int tlv59; tlv59 = (int)(buf); }
    {char * tlv58; tlv58 = (char *)(buf); }
    {cgc_size_t tlv57; tlv57 = (cgc_size_t)(buf); }
    {char tlv56; tlv56 = (char)(buf); }
    {int tlv60; tlv60 = (int)(buf); }
    {void * tlv65; tlv65 = (void *)(buf); }
    {void * tlv66; tlv66 = (void *)(buf); }
}
void fix_ingred_main_7_5_2(){
char buf [ 1024 ];
    bzero(&buf,( 1024 *sizeof(char) ) );
    {char buf [ 1024 ]; buf [ ( 1024 )-1 ] = (char)(sizeof ( buf )); }
    {int finish; finish = (int)(sizeof ( buf )); }
    {int tlv3; tlv3 = (int)(sizeof ( buf )); }
    {cgc_size_t tlv25; tlv25 = (cgc_size_t)(sizeof ( buf )); }
    {int tlv18; tlv18 = (int)(sizeof ( buf )); }
    {char * tlv17; tlv17 = (char *)(sizeof ( buf )); }
    {cgc_size_t tlv16; tlv16 = (cgc_size_t)(sizeof ( buf )); }
    {char tlv15; tlv15 = (char)(sizeof ( buf )); }
    {cgc_size_t tlv26; tlv26 = (cgc_size_t)(sizeof ( buf )); }
    {int tlv22; tlv22 = (int)(sizeof ( buf )); }
    {char * tlv21; tlv21 = (char *)(sizeof ( buf )); }
    {cgc_size_t tlv20; tlv20 = (cgc_size_t)(sizeof ( buf )); }
    {char tlv19; tlv19 = (char)(sizeof ( buf )); }
    {cgc_size_t tlv27; tlv27 = (cgc_size_t)(sizeof ( buf )); }
    {char * tlv14; tlv14 = (char *)(sizeof ( buf )); }
    {int tlv5; tlv5 = (int)(sizeof ( buf )); }
    {unsigned int genre; genre = (unsigned int)(sizeof ( buf )); }
    {unsigned int rating; rating = (unsigned int)(sizeof ( buf )); }
    {int tlv38; tlv38 = (int)(sizeof ( buf )); }
    {char * tlv37; tlv37 = (char *)(sizeof ( buf )); }
    {cgc_size_t tlv36; tlv36 = (cgc_size_t)(sizeof ( buf )); }
    {char tlv35; tlv35 = (char)(sizeof ( buf )); }
    {int tlv39; tlv39 = (int)(sizeof ( buf )); }
    {int tlv45; tlv45 = (int)(sizeof ( buf )); }
    {char * tlv44; tlv44 = (char *)(sizeof ( buf )); }
    {cgc_size_t tlv43; tlv43 = (cgc_size_t)(sizeof ( buf )); }
    {char tlv42; tlv42 = (char)(sizeof ( buf )); }
    {int tlv46; tlv46 = (int)(sizeof ( buf )); }
    {int tlv52; tlv52 = (int)(sizeof ( buf )); }
    {char * tlv51; tlv51 = (char *)(sizeof ( buf )); }
    {cgc_size_t tlv50; tlv50 = (cgc_size_t)(sizeof ( buf )); }
    {char tlv49; tlv49 = (char)(sizeof ( buf )); }
    {int tlv53; tlv53 = (int)(sizeof ( buf )); }
    {int tlv59; tlv59 = (int)(sizeof ( buf )); }
    {char * tlv58; tlv58 = (char *)(sizeof ( buf )); }
    {cgc_size_t tlv57; tlv57 = (cgc_size_t)(sizeof ( buf )); }
    {char tlv56; tlv56 = (char)(sizeof ( buf )); }
    {int tlv60; tlv60 = (int)(sizeof ( buf )); }
    {void * tlv65; tlv65 = (void *)(sizeof ( buf )); }
    {void * tlv66; tlv66 = (void *)(sizeof ( buf )); }
}
void fix_ingred_main_7_5_3(){
char buf [ 1024 ];
    bzero(&buf,( 1024 *sizeof(char) ) );
    {char buf [ 1024 ]; buf [ ( 1024 )-1 ] = (char)('\n'); }
    {int finish; finish = (int)('\n'); }
    {int tlv3; tlv3 = (int)('\n'); }
    {cgc_size_t tlv25; tlv25 = (cgc_size_t)('\n'); }
    {int tlv18; tlv18 = (int)('\n'); }
    {char * tlv17; tlv17 = (char *)('\n'); }
    {cgc_size_t tlv16; tlv16 = (cgc_size_t)('\n'); }
    {char tlv15; tlv15 = (char)('\n'); }
    {cgc_size_t tlv26; tlv26 = (cgc_size_t)('\n'); }
    {int tlv22; tlv22 = (int)('\n'); }
    {char * tlv21; tlv21 = (char *)('\n'); }
    {cgc_size_t tlv20; tlv20 = (cgc_size_t)('\n'); }
    {char tlv19; tlv19 = (char)('\n'); }
    {cgc_size_t tlv27; tlv27 = (cgc_size_t)('\n'); }
    {char * tlv14; tlv14 = (char *)('\n'); }
    {int tlv5; tlv5 = (int)('\n'); }
    {unsigned int genre; genre = (unsigned int)('\n'); }
    {unsigned int rating; rating = (unsigned int)('\n'); }
    {int tlv38; tlv38 = (int)('\n'); }
    {char * tlv37; tlv37 = (char *)('\n'); }
    {cgc_size_t tlv36; tlv36 = (cgc_size_t)('\n'); }
    {char tlv35; tlv35 = (char)('\n'); }
    {int tlv39; tlv39 = (int)('\n'); }
    {int tlv45; tlv45 = (int)('\n'); }
    {char * tlv44; tlv44 = (char *)('\n'); }
    {cgc_size_t tlv43; tlv43 = (cgc_size_t)('\n'); }
    {char tlv42; tlv42 = (char)('\n'); }
    {int tlv46; tlv46 = (int)('\n'); }
    {int tlv52; tlv52 = (int)('\n'); }
    {char * tlv51; tlv51 = (char *)('\n'); }
    {cgc_size_t tlv50; tlv50 = (cgc_size_t)('\n'); }
    {char tlv49; tlv49 = (char)('\n'); }
    {int tlv53; tlv53 = (int)('\n'); }
    {int tlv59; tlv59 = (int)('\n'); }
    {char * tlv58; tlv58 = (char *)('\n'); }
    {cgc_size_t tlv57; tlv57 = (cgc_size_t)('\n'); }
    {char tlv56; tlv56 = (char)('\n'); }
    {int tlv60; tlv60 = (int)('\n'); }
    {void * tlv65; tlv65 = (void *)('\n'); }
    {void * tlv66; tlv66 = (void *)('\n'); }
}
void fix_ingred_main_7_5(){
fix_ingred_main_7_5_0();
fix_ingred_main_7_5_1();
fix_ingred_main_7_5_2();
fix_ingred_main_7_5_3();
}
void fix_ingred_main_7_6_0(){
int tlv1;
    bzero(&tlv1,sizeof(int));
    {char buf [ 1024 ]; buf [ ( 1024 )-1 ] = (char)(tlv1); }
    {int finish; finish = (int)(tlv1); }
    {int tlv3; tlv3 = (int)(tlv1); }
    {cgc_size_t tlv25; tlv25 = (cgc_size_t)(tlv1); }
    {int tlv18; tlv18 = (int)(tlv1); }
    {char * tlv17; tlv17 = (char *)(tlv1); }
    {cgc_size_t tlv16; tlv16 = (cgc_size_t)(tlv1); }
    {char tlv15; tlv15 = (char)(tlv1); }
    {cgc_size_t tlv26; tlv26 = (cgc_size_t)(tlv1); }
    {int tlv22; tlv22 = (int)(tlv1); }
    {char * tlv21; tlv21 = (char *)(tlv1); }
    {cgc_size_t tlv20; tlv20 = (cgc_size_t)(tlv1); }
    {char tlv19; tlv19 = (char)(tlv1); }
    {cgc_size_t tlv27; tlv27 = (cgc_size_t)(tlv1); }
    {char * tlv14; tlv14 = (char *)(tlv1); }
    {unsigned int genre; genre = (unsigned int)(tlv1); }
    {unsigned int rating; rating = (unsigned int)(tlv1); }
    {int tlv38; tlv38 = (int)(tlv1); }
    {char * tlv37; tlv37 = (char *)(tlv1); }
    {cgc_size_t tlv36; tlv36 = (cgc_size_t)(tlv1); }
    {char tlv35; tlv35 = (char)(tlv1); }
    {int tlv39; tlv39 = (int)(tlv1); }
    {int tlv45; tlv45 = (int)(tlv1); }
    {char * tlv44; tlv44 = (char *)(tlv1); }
    {cgc_size_t tlv43; tlv43 = (cgc_size_t)(tlv1); }
    {char tlv42; tlv42 = (char)(tlv1); }
    {int tlv46; tlv46 = (int)(tlv1); }
    {int tlv52; tlv52 = (int)(tlv1); }
    {char * tlv51; tlv51 = (char *)(tlv1); }
    {cgc_size_t tlv50; tlv50 = (cgc_size_t)(tlv1); }
    {char tlv49; tlv49 = (char)(tlv1); }
    {int tlv53; tlv53 = (int)(tlv1); }
    {int tlv59; tlv59 = (int)(tlv1); }
    {char * tlv58; tlv58 = (char *)(tlv1); }
    {cgc_size_t tlv57; tlv57 = (cgc_size_t)(tlv1); }
    {char tlv56; tlv56 = (char)(tlv1); }
    {int tlv60; tlv60 = (int)(tlv1); }
    {void * tlv65; tlv65 = (void *)(tlv1); }
    {void * tlv66; tlv66 = (void *)(tlv1); }
}
void fix_ingred_main_7_6(){
fix_ingred_main_7_6_0();
}
void fix_ingred_main_7_8_0(){
char tlv67_ref;
    bzero(&tlv67_ref,1*sizeof(char));
const char * tlv67 = &tlv67_ref;
    {char buf [ 1024 ]; buf [ ( 1024 )-1 ] = (char)(cgc_strlen ( tlv67 ) + 1); }
    {int tlv1; tlv1 = (int)(cgc_strlen ( tlv67 ) + 1); }
    {int tlv2; tlv2 = (int)(cgc_strlen ( tlv67 ) + 1); }
    {int finish; finish = (int)(cgc_strlen ( tlv67 ) + 1); }
    {int tlv3; tlv3 = (int)(cgc_strlen ( tlv67 ) + 1); }
    {cgc_size_t tlv25; tlv25 = (cgc_size_t)(cgc_strlen ( tlv67 ) + 1); }
    {int tlv18; tlv18 = (int)(cgc_strlen ( tlv67 ) + 1); }
    {char * tlv17; tlv17 = (char *)(cgc_strlen ( tlv67 ) + 1); }
    {cgc_size_t tlv16; tlv16 = (cgc_size_t)(cgc_strlen ( tlv67 ) + 1); }
    {char tlv15; tlv15 = (char)(cgc_strlen ( tlv67 ) + 1); }
    {cgc_size_t tlv26; tlv26 = (cgc_size_t)(cgc_strlen ( tlv67 ) + 1); }
    {char * tlv11; tlv11 = (char *)(cgc_strlen ( tlv67 ) + 1); }
    {int tlv22; tlv22 = (int)(cgc_strlen ( tlv67 ) + 1); }
    {char * tlv21; tlv21 = (char *)(cgc_strlen ( tlv67 ) + 1); }
    {cgc_size_t tlv20; tlv20 = (cgc_size_t)(cgc_strlen ( tlv67 ) + 1); }
    {char tlv19; tlv19 = (char)(cgc_strlen ( tlv67 ) + 1); }
    {cgc_size_t tlv27; tlv27 = (cgc_size_t)(cgc_strlen ( tlv67 ) + 1); }
    {char * tlv14; tlv14 = (char *)(cgc_strlen ( tlv67 ) + 1); }
    {int tlv4; tlv4 = (int)(cgc_strlen ( tlv67 ) + 1); }
    {int tlv5; tlv5 = (int)(cgc_strlen ( tlv67 ) + 1); }
    {int tlv6; tlv6 = (int)(cgc_strlen ( tlv67 ) + 1); }
    {unsigned int genre; genre = (unsigned int)(cgc_strlen ( tlv67 ) + 1); }
    {int tlv7; tlv7 = (int)(cgc_strlen ( tlv67 ) + 1); }
    {unsigned int rating; rating = (unsigned int)(cgc_strlen ( tlv67 ) + 1); }
    {int tlv38; tlv38 = (int)(cgc_strlen ( tlv67 ) + 1); }
    {char * tlv37; tlv37 = (char *)(cgc_strlen ( tlv67 ) + 1); }
    {cgc_size_t tlv36; tlv36 = (cgc_size_t)(cgc_strlen ( tlv67 ) + 1); }
    {char tlv35; tlv35 = (char)(cgc_strlen ( tlv67 ) + 1); }
    {int tlv39; tlv39 = (int)(cgc_strlen ( tlv67 ) + 1); }
    {int tlv45; tlv45 = (int)(cgc_strlen ( tlv67 ) + 1); }
    {char * tlv44; tlv44 = (char *)(cgc_strlen ( tlv67 ) + 1); }
    {cgc_size_t tlv43; tlv43 = (cgc_size_t)(cgc_strlen ( tlv67 ) + 1); }
    {char tlv42; tlv42 = (char)(cgc_strlen ( tlv67 ) + 1); }
    {int tlv46; tlv46 = (int)(cgc_strlen ( tlv67 ) + 1); }
    {int tlv52; tlv52 = (int)(cgc_strlen ( tlv67 ) + 1); }
    {char * tlv51; tlv51 = (char *)(cgc_strlen ( tlv67 ) + 1); }
    {cgc_size_t tlv50; tlv50 = (cgc_size_t)(cgc_strlen ( tlv67 ) + 1); }
    {char tlv49; tlv49 = (char)(cgc_strlen ( tlv67 ) + 1); }
    {int tlv53; tlv53 = (int)(cgc_strlen ( tlv67 ) + 1); }
    {int tlv59; tlv59 = (int)(cgc_strlen ( tlv67 ) + 1); }
    {char * tlv58; tlv58 = (char *)(cgc_strlen ( tlv67 ) + 1); }
    {cgc_size_t tlv57; tlv57 = (cgc_size_t)(cgc_strlen ( tlv67 ) + 1); }
    {char tlv56; tlv56 = (char)(cgc_strlen ( tlv67 ) + 1); }
    {int tlv60; tlv60 = (int)(cgc_strlen ( tlv67 ) + 1); }
    {void * tlv65; tlv65 = (void *)(cgc_strlen ( tlv67 ) + 1); }
    {void * tlv66; tlv66 = (void *)(cgc_strlen ( tlv67 ) + 1); }
}
void fix_ingred_main_7_8(){
fix_ingred_main_7_8_0();
}
void fix_ingred_main_7_10_0(){
movie_t movie_ref;
    bzero(&movie_ref,1*sizeof(movie_t));
movie_t * movie = &movie_ref;
    {char buf [ 1024 ]; buf [ ( 1024 )-1 ] = (char)(movie -> title); }
    {int finish; finish = (int)(movie -> title); }
    {int tlv3; tlv3 = (int)(movie -> title); }
    {cgc_size_t tlv25; tlv25 = (cgc_size_t)(movie -> title); }
    {int tlv18; tlv18 = (int)(movie -> title); }
    {char * tlv17; tlv17 = (char *)(movie -> title); }
    {cgc_size_t tlv16; tlv16 = (cgc_size_t)(movie -> title); }
    {char tlv15; tlv15 = (char)(movie -> title); }
    {cgc_size_t tlv26; tlv26 = (cgc_size_t)(movie -> title); }
    {char * tlv11; tlv11 = (char *)(movie -> title); }
    {int tlv22; tlv22 = (int)(movie -> title); }
    {char * tlv21; tlv21 = (char *)(movie -> title); }
    {char tlv19; tlv19 = (char)(movie -> title); }
    {cgc_size_t tlv27; tlv27 = (cgc_size_t)(movie -> title); }
    {char * tlv14; tlv14 = (char *)(movie -> title); }
    {int tlv5; tlv5 = (int)(movie -> title); }
    {int tlv6; tlv6 = (int)(movie -> title); }
    {unsigned int genre; genre = (unsigned int)(movie -> title); }
    {int tlv7; tlv7 = (int)(movie -> title); }
    {unsigned int rating; rating = (unsigned int)(movie -> title); }
    {int tlv38; tlv38 = (int)(movie -> title); }
    {char * tlv37; tlv37 = (char *)(movie -> title); }
    {cgc_size_t tlv36; tlv36 = (cgc_size_t)(movie -> title); }
    {char tlv35; tlv35 = (char)(movie -> title); }
    {int tlv39; tlv39 = (int)(movie -> title); }
    {int tlv45; tlv45 = (int)(movie -> title); }
    {char * tlv44; tlv44 = (char *)(movie -> title); }
    {cgc_size_t tlv43; tlv43 = (cgc_size_t)(movie -> title); }
    {char tlv42; tlv42 = (char)(movie -> title); }
    {int tlv46; tlv46 = (int)(movie -> title); }
    {int tlv52; tlv52 = (int)(movie -> title); }
    {char * tlv51; tlv51 = (char *)(movie -> title); }
    {cgc_size_t tlv50; tlv50 = (cgc_size_t)(movie -> title); }
    {char tlv49; tlv49 = (char)(movie -> title); }
    {int tlv53; tlv53 = (int)(movie -> title); }
    {int tlv59; tlv59 = (int)(movie -> title); }
    {char * tlv58; tlv58 = (char *)(movie -> title); }
    {cgc_size_t tlv57; tlv57 = (cgc_size_t)(movie -> title); }
    {char tlv56; tlv56 = (char)(movie -> title); }
    {int tlv60; tlv60 = (int)(movie -> title); }
    {void * tlv65; tlv65 = (void *)(movie -> title); }
    {void * tlv66; tlv66 = (void *)(movie -> title); }
}
void fix_ingred_main_7_10(){
fix_ingred_main_7_10_0();
}
void fix_ingred_main_7_13_0(){
int tlv2;
    bzero(&tlv2,sizeof(int));
    {char buf [ 1024 ]; buf [ ( 1024 )-1 ] = (char)(tlv2); }
    {int finish; finish = (int)(tlv2); }
    {int tlv3; tlv3 = (int)(tlv2); }
    {cgc_size_t tlv25; tlv25 = (cgc_size_t)(tlv2); }
    {int tlv18; tlv18 = (int)(tlv2); }
    {char * tlv17; tlv17 = (char *)(tlv2); }
    {cgc_size_t tlv16; tlv16 = (cgc_size_t)(tlv2); }
    {char tlv15; tlv15 = (char)(tlv2); }
    {cgc_size_t tlv26; tlv26 = (cgc_size_t)(tlv2); }
    {int tlv22; tlv22 = (int)(tlv2); }
    {char * tlv21; tlv21 = (char *)(tlv2); }
    {cgc_size_t tlv20; tlv20 = (cgc_size_t)(tlv2); }
    {char tlv19; tlv19 = (char)(tlv2); }
    {cgc_size_t tlv27; tlv27 = (cgc_size_t)(tlv2); }
    {char * tlv14; tlv14 = (char *)(tlv2); }
    {int tlv5; tlv5 = (int)(tlv2); }
    {unsigned int genre; genre = (unsigned int)(tlv2); }
    {unsigned int rating; rating = (unsigned int)(tlv2); }
    {int tlv38; tlv38 = (int)(tlv2); }
    {char * tlv37; tlv37 = (char *)(tlv2); }
    {cgc_size_t tlv36; tlv36 = (cgc_size_t)(tlv2); }
    {char tlv35; tlv35 = (char)(tlv2); }
    {int tlv39; tlv39 = (int)(tlv2); }
    {int tlv45; tlv45 = (int)(tlv2); }
    {char * tlv44; tlv44 = (char *)(tlv2); }
    {cgc_size_t tlv43; tlv43 = (cgc_size_t)(tlv2); }
    {char tlv42; tlv42 = (char)(tlv2); }
    {int tlv46; tlv46 = (int)(tlv2); }
    {int tlv52; tlv52 = (int)(tlv2); }
    {char * tlv51; tlv51 = (char *)(tlv2); }
    {cgc_size_t tlv50; tlv50 = (cgc_size_t)(tlv2); }
    {char tlv49; tlv49 = (char)(tlv2); }
    {int tlv53; tlv53 = (int)(tlv2); }
    {int tlv59; tlv59 = (int)(tlv2); }
    {char * tlv58; tlv58 = (char *)(tlv2); }
    {cgc_size_t tlv57; tlv57 = (cgc_size_t)(tlv2); }
    {char tlv56; tlv56 = (char)(tlv2); }
    {int tlv60; tlv60 = (int)(tlv2); }
    {void * tlv65; tlv65 = (void *)(tlv2); }
    {void * tlv66; tlv66 = (void *)(tlv2); }
}
void fix_ingred_main_7_13(){
fix_ingred_main_7_13_0();
}
void fix_ingred_main_7_15_0(){
char tlv68_ref;
    bzero(&tlv68_ref,1*sizeof(char));
const char * tlv68 = &tlv68_ref;
    {char buf [ 1024 ]; buf [ ( 1024 )-1 ] = (char)(cgc_strlen ( tlv68 ) + 1); }
    {int tlv1; tlv1 = (int)(cgc_strlen ( tlv68 ) + 1); }
    {int tlv2; tlv2 = (int)(cgc_strlen ( tlv68 ) + 1); }
    {int finish; finish = (int)(cgc_strlen ( tlv68 ) + 1); }
    {int tlv3; tlv3 = (int)(cgc_strlen ( tlv68 ) + 1); }
    {cgc_size_t tlv25; tlv25 = (cgc_size_t)(cgc_strlen ( tlv68 ) + 1); }
    {int tlv18; tlv18 = (int)(cgc_strlen ( tlv68 ) + 1); }
    {char * tlv17; tlv17 = (char *)(cgc_strlen ( tlv68 ) + 1); }
    {cgc_size_t tlv16; tlv16 = (cgc_size_t)(cgc_strlen ( tlv68 ) + 1); }
    {char tlv15; tlv15 = (char)(cgc_strlen ( tlv68 ) + 1); }
    {cgc_size_t tlv26; tlv26 = (cgc_size_t)(cgc_strlen ( tlv68 ) + 1); }
    {char * tlv11; tlv11 = (char *)(cgc_strlen ( tlv68 ) + 1); }
    {int tlv22; tlv22 = (int)(cgc_strlen ( tlv68 ) + 1); }
    {char * tlv21; tlv21 = (char *)(cgc_strlen ( tlv68 ) + 1); }
    {cgc_size_t tlv20; tlv20 = (cgc_size_t)(cgc_strlen ( tlv68 ) + 1); }
    {char tlv19; tlv19 = (char)(cgc_strlen ( tlv68 ) + 1); }
    {cgc_size_t tlv27; tlv27 = (cgc_size_t)(cgc_strlen ( tlv68 ) + 1); }
    {char * tlv14; tlv14 = (char *)(cgc_strlen ( tlv68 ) + 1); }
    {int tlv4; tlv4 = (int)(cgc_strlen ( tlv68 ) + 1); }
    {int tlv5; tlv5 = (int)(cgc_strlen ( tlv68 ) + 1); }
    {int tlv6; tlv6 = (int)(cgc_strlen ( tlv68 ) + 1); }
    {unsigned int genre; genre = (unsigned int)(cgc_strlen ( tlv68 ) + 1); }
    {int tlv7; tlv7 = (int)(cgc_strlen ( tlv68 ) + 1); }
    {unsigned int rating; rating = (unsigned int)(cgc_strlen ( tlv68 ) + 1); }
    {int tlv38; tlv38 = (int)(cgc_strlen ( tlv68 ) + 1); }
    {char * tlv37; tlv37 = (char *)(cgc_strlen ( tlv68 ) + 1); }
    {cgc_size_t tlv36; tlv36 = (cgc_size_t)(cgc_strlen ( tlv68 ) + 1); }
    {char tlv35; tlv35 = (char)(cgc_strlen ( tlv68 ) + 1); }
    {int tlv39; tlv39 = (int)(cgc_strlen ( tlv68 ) + 1); }
    {int tlv45; tlv45 = (int)(cgc_strlen ( tlv68 ) + 1); }
    {char * tlv44; tlv44 = (char *)(cgc_strlen ( tlv68 ) + 1); }
    {cgc_size_t tlv43; tlv43 = (cgc_size_t)(cgc_strlen ( tlv68 ) + 1); }
    {char tlv42; tlv42 = (char)(cgc_strlen ( tlv68 ) + 1); }
    {int tlv46; tlv46 = (int)(cgc_strlen ( tlv68 ) + 1); }
    {int tlv52; tlv52 = (int)(cgc_strlen ( tlv68 ) + 1); }
    {char * tlv51; tlv51 = (char *)(cgc_strlen ( tlv68 ) + 1); }
    {cgc_size_t tlv50; tlv50 = (cgc_size_t)(cgc_strlen ( tlv68 ) + 1); }
    {char tlv49; tlv49 = (char)(cgc_strlen ( tlv68 ) + 1); }
    {int tlv53; tlv53 = (int)(cgc_strlen ( tlv68 ) + 1); }
    {int tlv59; tlv59 = (int)(cgc_strlen ( tlv68 ) + 1); }
    {char * tlv58; tlv58 = (char *)(cgc_strlen ( tlv68 ) + 1); }
    {cgc_size_t tlv57; tlv57 = (cgc_size_t)(cgc_strlen ( tlv68 ) + 1); }
    {char tlv56; tlv56 = (char)(cgc_strlen ( tlv68 ) + 1); }
    {int tlv60; tlv60 = (int)(cgc_strlen ( tlv68 ) + 1); }
    {void * tlv65; tlv65 = (void *)(cgc_strlen ( tlv68 ) + 1); }
    {void * tlv66; tlv66 = (void *)(cgc_strlen ( tlv68 ) + 1); }
}
void fix_ingred_main_7_15(){
fix_ingred_main_7_15_0();
}
void fix_ingred_main_7_17_0(){
movie_t movie_ref;
    bzero(&movie_ref,1*sizeof(movie_t));
movie_t * movie = &movie_ref;
    {char buf [ 1024 ]; buf [ ( 1024 )-1 ] = (char)(movie -> desc); }
    {int tlv1; tlv1 = (int)(movie -> desc); }
    {int tlv2; tlv2 = (int)(movie -> desc); }
    {int finish; finish = (int)(movie -> desc); }
    {int tlv3; tlv3 = (int)(movie -> desc); }
    {cgc_size_t tlv25; tlv25 = (cgc_size_t)(movie -> desc); }
    {int tlv18; tlv18 = (int)(movie -> desc); }
    {char * tlv17; tlv17 = (char *)(movie -> desc); }
    {cgc_size_t tlv16; tlv16 = (cgc_size_t)(movie -> desc); }
    {char tlv15; tlv15 = (char)(movie -> desc); }
    {cgc_size_t tlv26; tlv26 = (cgc_size_t)(movie -> desc); }
    {char * tlv11; tlv11 = (char *)(movie -> desc); }
    {int tlv22; tlv22 = (int)(movie -> desc); }
    {char * tlv21; tlv21 = (char *)(movie -> desc); }
    {char tlv19; tlv19 = (char)(movie -> desc); }
    {cgc_size_t tlv27; tlv27 = (cgc_size_t)(movie -> desc); }
    {char * tlv14; tlv14 = (char *)(movie -> desc); }
    {int tlv4; tlv4 = (int)(movie -> desc); }
    {int tlv5; tlv5 = (int)(movie -> desc); }
    {int tlv6; tlv6 = (int)(movie -> desc); }
    {unsigned int genre; genre = (unsigned int)(movie -> desc); }
    {int tlv7; tlv7 = (int)(movie -> desc); }
    {unsigned int rating; rating = (unsigned int)(movie -> desc); }
    {int tlv38; tlv38 = (int)(movie -> desc); }
    {char * tlv37; tlv37 = (char *)(movie -> desc); }
    {cgc_size_t tlv36; tlv36 = (cgc_size_t)(movie -> desc); }
    {char tlv35; tlv35 = (char)(movie -> desc); }
    {int tlv39; tlv39 = (int)(movie -> desc); }
    {int tlv45; tlv45 = (int)(movie -> desc); }
    {char * tlv44; tlv44 = (char *)(movie -> desc); }
    {cgc_size_t tlv43; tlv43 = (cgc_size_t)(movie -> desc); }
    {char tlv42; tlv42 = (char)(movie -> desc); }
    {int tlv46; tlv46 = (int)(movie -> desc); }
    {int tlv52; tlv52 = (int)(movie -> desc); }
    {char * tlv51; tlv51 = (char *)(movie -> desc); }
    {cgc_size_t tlv50; tlv50 = (cgc_size_t)(movie -> desc); }
    {char tlv49; tlv49 = (char)(movie -> desc); }
    {int tlv53; tlv53 = (int)(movie -> desc); }
    {int tlv59; tlv59 = (int)(movie -> desc); }
    {char * tlv58; tlv58 = (char *)(movie -> desc); }
    {cgc_size_t tlv57; tlv57 = (cgc_size_t)(movie -> desc); }
    {char tlv56; tlv56 = (char)(movie -> desc); }
    {int tlv60; tlv60 = (int)(movie -> desc); }
    {void * tlv65; tlv65 = (void *)(movie -> desc); }
    {void * tlv66; tlv66 = (void *)(movie -> desc); }
}
void fix_ingred_main_7_17(){
fix_ingred_main_7_17_0();
}
void fix_ingred_main_7_21_0(){
int tlv4;
    bzero(&tlv4,sizeof(int));
    {char buf [ 1024 ]; buf [ ( 1024 )-1 ] = (char)(tlv4); }
    {int tlv1; tlv1 = (int)(tlv4); }
    {int tlv2; tlv2 = (int)(tlv4); }
    {int finish; finish = (int)(tlv4); }
    {int tlv3; tlv3 = (int)(tlv4); }
    {cgc_size_t tlv25; tlv25 = (cgc_size_t)(tlv4); }
    {int tlv18; tlv18 = (int)(tlv4); }
    {char * tlv17; tlv17 = (char *)(tlv4); }
    {cgc_size_t tlv16; tlv16 = (cgc_size_t)(tlv4); }
    {char tlv15; tlv15 = (char)(tlv4); }
    {cgc_size_t tlv26; tlv26 = (cgc_size_t)(tlv4); }
    {char * tlv11; tlv11 = (char *)(tlv4); }
    {int tlv22; tlv22 = (int)(tlv4); }
    {char * tlv21; tlv21 = (char *)(tlv4); }
    {cgc_size_t tlv20; tlv20 = (cgc_size_t)(tlv4); }
    {char tlv19; tlv19 = (char)(tlv4); }
    {cgc_size_t tlv27; tlv27 = (cgc_size_t)(tlv4); }
    {char * tlv14; tlv14 = (char *)(tlv4); }
    {int tlv5; tlv5 = (int)(tlv4); }
    {int tlv6; tlv6 = (int)(tlv4); }
    {unsigned int genre; genre = (unsigned int)(tlv4); }
    {int tlv7; tlv7 = (int)(tlv4); }
    {unsigned int rating; rating = (unsigned int)(tlv4); }
    {int tlv38; tlv38 = (int)(tlv4); }
    {char * tlv37; tlv37 = (char *)(tlv4); }
    {cgc_size_t tlv36; tlv36 = (cgc_size_t)(tlv4); }
    {char tlv35; tlv35 = (char)(tlv4); }
    {int tlv39; tlv39 = (int)(tlv4); }
    {int tlv45; tlv45 = (int)(tlv4); }
    {char * tlv44; tlv44 = (char *)(tlv4); }
    {cgc_size_t tlv43; tlv43 = (cgc_size_t)(tlv4); }
    {char tlv42; tlv42 = (char)(tlv4); }
    {int tlv46; tlv46 = (int)(tlv4); }
    {int tlv52; tlv52 = (int)(tlv4); }
    {char * tlv51; tlv51 = (char *)(tlv4); }
    {cgc_size_t tlv50; tlv50 = (cgc_size_t)(tlv4); }
    {char tlv49; tlv49 = (char)(tlv4); }
    {int tlv53; tlv53 = (int)(tlv4); }
    {int tlv59; tlv59 = (int)(tlv4); }
    {char * tlv58; tlv58 = (char *)(tlv4); }
    {cgc_size_t tlv57; tlv57 = (cgc_size_t)(tlv4); }
    {char tlv56; tlv56 = (char)(tlv4); }
    {int tlv60; tlv60 = (int)(tlv4); }
    {void * tlv65; tlv65 = (void *)(tlv4); }
    {void * tlv66; tlv66 = (void *)(tlv4); }
}
void fix_ingred_main_7_21(){
fix_ingred_main_7_21_0();
}
void fix_ingred_main_7_22_1(){
    {char buf [ 1024 ]; buf [ ( 1024 )-1 ] = (char)(10); }
    {int finish; finish = (int)(10); }
    {int tlv3; tlv3 = (int)(10); }
    {cgc_size_t tlv25; tlv25 = (cgc_size_t)(10); }
    {int tlv18; tlv18 = (int)(10); }
    {char * tlv17; tlv17 = (char *)(10); }
    {cgc_size_t tlv16; tlv16 = (cgc_size_t)(10); }
    {char tlv15; tlv15 = (char)(10); }
    {cgc_size_t tlv26; tlv26 = (cgc_size_t)(10); }
    {char * tlv11; tlv11 = (char *)(10); }
    {int tlv22; tlv22 = (int)(10); }
    {char * tlv21; tlv21 = (char *)(10); }
    {cgc_size_t tlv20; tlv20 = (cgc_size_t)(10); }
    {char tlv19; tlv19 = (char)(10); }
    {cgc_size_t tlv27; tlv27 = (cgc_size_t)(10); }
    {char * tlv14; tlv14 = (char *)(10); }
    {int tlv5; tlv5 = (int)(10); }
    {unsigned int genre; genre = (unsigned int)(10); }
    {int tlv7; tlv7 = (int)(10); }
    {unsigned int rating; rating = (unsigned int)(10); }
    {int tlv38; tlv38 = (int)(10); }
    {char * tlv37; tlv37 = (char *)(10); }
    {cgc_size_t tlv36; tlv36 = (cgc_size_t)(10); }
    {char tlv35; tlv35 = (char)(10); }
    {int tlv39; tlv39 = (int)(10); }
    {int tlv45; tlv45 = (int)(10); }
    {char * tlv44; tlv44 = (char *)(10); }
    {cgc_size_t tlv43; tlv43 = (cgc_size_t)(10); }
    {char tlv42; tlv42 = (char)(10); }
    {int tlv46; tlv46 = (int)(10); }
    {int tlv52; tlv52 = (int)(10); }
    {char * tlv51; tlv51 = (char *)(10); }
    {cgc_size_t tlv50; tlv50 = (cgc_size_t)(10); }
    {char tlv49; tlv49 = (char)(10); }
    {int tlv53; tlv53 = (int)(10); }
    {int tlv59; tlv59 = (int)(10); }
    {char * tlv58; tlv58 = (char *)(10); }
    {cgc_size_t tlv57; tlv57 = (cgc_size_t)(10); }
    {char tlv56; tlv56 = (char)(10); }
    {int tlv60; tlv60 = (int)(10); }
    {void * tlv65; tlv65 = (void *)(10); }
    {void * tlv66; tlv66 = (void *)(10); }
}
void fix_ingred_main_7_22(){
fix_ingred_main_7_22_1();
}
void fix_ingred_main_7_28_0(){
int tlv5;
    bzero(&tlv5,sizeof(int));
    {char buf [ 1024 ]; buf [ ( 1024 )-1 ] = (char)(tlv5); }
    {int tlv1; tlv1 = (int)(tlv5); }
    {int tlv2; tlv2 = (int)(tlv5); }
    {int finish; finish = (int)(tlv5); }
    {int tlv3; tlv3 = (int)(tlv5); }
    {cgc_size_t tlv25; tlv25 = (cgc_size_t)(tlv5); }
    {int tlv18; tlv18 = (int)(tlv5); }
    {char * tlv17; tlv17 = (char *)(tlv5); }
    {cgc_size_t tlv16; tlv16 = (cgc_size_t)(tlv5); }
    {char tlv15; tlv15 = (char)(tlv5); }
    {cgc_size_t tlv26; tlv26 = (cgc_size_t)(tlv5); }
    {char * tlv11; tlv11 = (char *)(tlv5); }
    {int tlv22; tlv22 = (int)(tlv5); }
    {char * tlv21; tlv21 = (char *)(tlv5); }
    {cgc_size_t tlv20; tlv20 = (cgc_size_t)(tlv5); }
    {char tlv19; tlv19 = (char)(tlv5); }
    {cgc_size_t tlv27; tlv27 = (cgc_size_t)(tlv5); }
    {char * tlv14; tlv14 = (char *)(tlv5); }
    {int tlv4; tlv4 = (int)(tlv5); }
    {int tlv6; tlv6 = (int)(tlv5); }
    {unsigned int genre; genre = (unsigned int)(tlv5); }
    {int tlv7; tlv7 = (int)(tlv5); }
    {unsigned int rating; rating = (unsigned int)(tlv5); }
    {int tlv38; tlv38 = (int)(tlv5); }
    {char * tlv37; tlv37 = (char *)(tlv5); }
    {cgc_size_t tlv36; tlv36 = (cgc_size_t)(tlv5); }
    {char tlv35; tlv35 = (char)(tlv5); }
    {int tlv39; tlv39 = (int)(tlv5); }
    {int tlv45; tlv45 = (int)(tlv5); }
    {char * tlv44; tlv44 = (char *)(tlv5); }
    {cgc_size_t tlv43; tlv43 = (cgc_size_t)(tlv5); }
    {char tlv42; tlv42 = (char)(tlv5); }
    {int tlv46; tlv46 = (int)(tlv5); }
    {int tlv52; tlv52 = (int)(tlv5); }
    {char * tlv51; tlv51 = (char *)(tlv5); }
    {cgc_size_t tlv50; tlv50 = (cgc_size_t)(tlv5); }
    {char tlv49; tlv49 = (char)(tlv5); }
    {int tlv53; tlv53 = (int)(tlv5); }
    {int tlv59; tlv59 = (int)(tlv5); }
    {char * tlv58; tlv58 = (char *)(tlv5); }
    {cgc_size_t tlv57; tlv57 = (cgc_size_t)(tlv5); }
    {char tlv56; tlv56 = (char)(tlv5); }
    {int tlv60; tlv60 = (int)(tlv5); }
    {void * tlv65; tlv65 = (void *)(tlv5); }
    {void * tlv66; tlv66 = (void *)(tlv5); }
}
void fix_ingred_main_7_28(){
fix_ingred_main_7_28_0();
}
void fix_ingred_main_7_32_0(){
    {char buf [ 1024 ]; buf [ ( 1024 )-1 ] = (char)(1); }
    {int finish; finish = (int)(1); }
    {int tlv3; tlv3 = (int)(1); }
    {cgc_size_t tlv25; tlv25 = (cgc_size_t)(1); }
    {int tlv18; tlv18 = (int)(1); }
    {char * tlv17; tlv17 = (char *)(1); }
    {cgc_size_t tlv16; tlv16 = (cgc_size_t)(1); }
    {char tlv15; tlv15 = (char)(1); }
    {cgc_size_t tlv26; tlv26 = (cgc_size_t)(1); }
    {int tlv22; tlv22 = (int)(1); }
    {char * tlv21; tlv21 = (char *)(1); }
    {cgc_size_t tlv20; tlv20 = (cgc_size_t)(1); }
    {char tlv19; tlv19 = (char)(1); }
    {cgc_size_t tlv27; tlv27 = (cgc_size_t)(1); }
    {char * tlv14; tlv14 = (char *)(1); }
    {int tlv4; tlv4 = (int)(1); }
    {int tlv5; tlv5 = (int)(1); }
    {int tlv6; tlv6 = (int)(1); }
    {unsigned int genre; genre = (unsigned int)(1); }
    {unsigned int rating; rating = (unsigned int)(1); }
    {int tlv38; tlv38 = (int)(1); }
    {char * tlv37; tlv37 = (char *)(1); }
    {cgc_size_t tlv36; tlv36 = (cgc_size_t)(1); }
    {char tlv35; tlv35 = (char)(1); }
    {int tlv39; tlv39 = (int)(1); }
    {int tlv45; tlv45 = (int)(1); }
    {char * tlv44; tlv44 = (char *)(1); }
    {cgc_size_t tlv43; tlv43 = (cgc_size_t)(1); }
    {char tlv42; tlv42 = (char)(1); }
    {int tlv46; tlv46 = (int)(1); }
    {int tlv52; tlv52 = (int)(1); }
    {char * tlv51; tlv51 = (char *)(1); }
    {cgc_size_t tlv50; tlv50 = (cgc_size_t)(1); }
    {char tlv49; tlv49 = (char)(1); }
    {int tlv53; tlv53 = (int)(1); }
    {int tlv59; tlv59 = (int)(1); }
    {char * tlv58; tlv58 = (char *)(1); }
    {cgc_size_t tlv57; tlv57 = (cgc_size_t)(1); }
    {char tlv56; tlv56 = (char)(1); }
    {int tlv60; tlv60 = (int)(1); }
    {void * tlv65; tlv65 = (void *)(1); }
    {void * tlv66; tlv66 = (void *)(1); }
}
void fix_ingred_main_7_32(){
fix_ingred_main_7_32_0();
}
void fix_ingred_main_7_35_1(){
int tlv6;
    bzero(&tlv6,sizeof(int));
    {char buf [ 1024 ]; buf [ ( 1024 )-1 ] = (char)(tlv6); }
    {int tlv1; tlv1 = (int)(tlv6); }
    {int tlv2; tlv2 = (int)(tlv6); }
    {int finish; finish = (int)(tlv6); }
    {int tlv3; tlv3 = (int)(tlv6); }
    {cgc_size_t tlv25; tlv25 = (cgc_size_t)(tlv6); }
    {int tlv18; tlv18 = (int)(tlv6); }
    {char * tlv17; tlv17 = (char *)(tlv6); }
    {cgc_size_t tlv16; tlv16 = (cgc_size_t)(tlv6); }
    {char tlv15; tlv15 = (char)(tlv6); }
    {cgc_size_t tlv26; tlv26 = (cgc_size_t)(tlv6); }
    {char * tlv11; tlv11 = (char *)(tlv6); }
    {int tlv22; tlv22 = (int)(tlv6); }
    {char * tlv21; tlv21 = (char *)(tlv6); }
    {cgc_size_t tlv20; tlv20 = (cgc_size_t)(tlv6); }
    {char tlv19; tlv19 = (char)(tlv6); }
    {cgc_size_t tlv27; tlv27 = (cgc_size_t)(tlv6); }
    {char * tlv14; tlv14 = (char *)(tlv6); }
    {int tlv4; tlv4 = (int)(tlv6); }
    {int tlv5; tlv5 = (int)(tlv6); }
    {unsigned int genre; genre = (unsigned int)(tlv6); }
    {int tlv7; tlv7 = (int)(tlv6); }
    {unsigned int rating; rating = (unsigned int)(tlv6); }
    {int tlv38; tlv38 = (int)(tlv6); }
    {char * tlv37; tlv37 = (char *)(tlv6); }
    {cgc_size_t tlv36; tlv36 = (cgc_size_t)(tlv6); }
    {char tlv35; tlv35 = (char)(tlv6); }
    {int tlv39; tlv39 = (int)(tlv6); }
    {int tlv45; tlv45 = (int)(tlv6); }
    {char * tlv44; tlv44 = (char *)(tlv6); }
    {cgc_size_t tlv43; tlv43 = (cgc_size_t)(tlv6); }
    {char tlv42; tlv42 = (char)(tlv6); }
    {int tlv46; tlv46 = (int)(tlv6); }
    {int tlv52; tlv52 = (int)(tlv6); }
    {char * tlv51; tlv51 = (char *)(tlv6); }
    {cgc_size_t tlv50; tlv50 = (cgc_size_t)(tlv6); }
    {char tlv49; tlv49 = (char)(tlv6); }
    {int tlv53; tlv53 = (int)(tlv6); }
    {int tlv59; tlv59 = (int)(tlv6); }
    {char * tlv58; tlv58 = (char *)(tlv6); }
    {cgc_size_t tlv57; tlv57 = (cgc_size_t)(tlv6); }
    {char tlv56; tlv56 = (char)(tlv6); }
    {int tlv60; tlv60 = (int)(tlv6); }
    {void * tlv65; tlv65 = (void *)(tlv6); }
    {void * tlv66; tlv66 = (void *)(tlv6); }
}
void fix_ingred_main_7_35(){
fix_ingred_main_7_35_1();
}
void fix_ingred_main_7_48_2(){
int tlv7;
    bzero(&tlv7,sizeof(int));
    {char buf [ 1024 ]; buf [ ( 1024 )-1 ] = (char)(tlv7); }
    {int tlv1; tlv1 = (int)(tlv7); }
    {int tlv2; tlv2 = (int)(tlv7); }
    {int finish; finish = (int)(tlv7); }
    {int tlv3; tlv3 = (int)(tlv7); }
    {cgc_size_t tlv25; tlv25 = (cgc_size_t)(tlv7); }
    {int tlv18; tlv18 = (int)(tlv7); }
    {char * tlv17; tlv17 = (char *)(tlv7); }
    {cgc_size_t tlv16; tlv16 = (cgc_size_t)(tlv7); }
    {char tlv15; tlv15 = (char)(tlv7); }
    {cgc_size_t tlv26; tlv26 = (cgc_size_t)(tlv7); }
    {char * tlv11; tlv11 = (char *)(tlv7); }
    {int tlv22; tlv22 = (int)(tlv7); }
    {char * tlv21; tlv21 = (char *)(tlv7); }
    {cgc_size_t tlv20; tlv20 = (cgc_size_t)(tlv7); }
    {char tlv19; tlv19 = (char)(tlv7); }
    {cgc_size_t tlv27; tlv27 = (cgc_size_t)(tlv7); }
    {char * tlv14; tlv14 = (char *)(tlv7); }
    {int tlv4; tlv4 = (int)(tlv7); }
    {int tlv5; tlv5 = (int)(tlv7); }
    {int tlv6; tlv6 = (int)(tlv7); }
    {unsigned int genre; genre = (unsigned int)(tlv7); }
    {unsigned int rating; rating = (unsigned int)(tlv7); }
    {int tlv38; tlv38 = (int)(tlv7); }
    {char * tlv37; tlv37 = (char *)(tlv7); }
    {cgc_size_t tlv36; tlv36 = (cgc_size_t)(tlv7); }
    {char tlv35; tlv35 = (char)(tlv7); }
    {int tlv39; tlv39 = (int)(tlv7); }
    {int tlv45; tlv45 = (int)(tlv7); }
    {char * tlv44; tlv44 = (char *)(tlv7); }
    {cgc_size_t tlv43; tlv43 = (cgc_size_t)(tlv7); }
    {char tlv42; tlv42 = (char)(tlv7); }
    {int tlv46; tlv46 = (int)(tlv7); }
    {int tlv52; tlv52 = (int)(tlv7); }
    {char * tlv51; tlv51 = (char *)(tlv7); }
    {cgc_size_t tlv50; tlv50 = (cgc_size_t)(tlv7); }
    {char tlv49; tlv49 = (char)(tlv7); }
    {int tlv53; tlv53 = (int)(tlv7); }
    {int tlv59; tlv59 = (int)(tlv7); }
    {char * tlv58; tlv58 = (char *)(tlv7); }
    {cgc_size_t tlv57; tlv57 = (cgc_size_t)(tlv7); }
    {char tlv56; tlv56 = (char)(tlv7); }
    {int tlv60; tlv60 = (int)(tlv7); }
    {void * tlv65; tlv65 = (void *)(tlv7); }
    {void * tlv66; tlv66 = (void *)(tlv7); }
}
void fix_ingred_main_7_48(){
fix_ingred_main_7_48_2();
}
void fix_ingred_main_7_59_2(){
int tlv3;
    bzero(&tlv3,sizeof(int));
    {char buf [ 1024 ]; buf [ ( 1024 )-1 ] = (char)(tlv3); }
    {int tlv1; tlv1 = (int)(tlv3); }
    {int tlv2; tlv2 = (int)(tlv3); }
    {int finish; finish = (int)(tlv3); }
    {cgc_size_t tlv25; tlv25 = (cgc_size_t)(tlv3); }
    {int tlv18; tlv18 = (int)(tlv3); }
    {char * tlv17; tlv17 = (char *)(tlv3); }
    {cgc_size_t tlv16; tlv16 = (cgc_size_t)(tlv3); }
    {char tlv15; tlv15 = (char)(tlv3); }
    {cgc_size_t tlv26; tlv26 = (cgc_size_t)(tlv3); }
    {char * tlv11; tlv11 = (char *)(tlv3); }
    {int tlv22; tlv22 = (int)(tlv3); }
    {char * tlv21; tlv21 = (char *)(tlv3); }
    {cgc_size_t tlv20; tlv20 = (cgc_size_t)(tlv3); }
    {char tlv19; tlv19 = (char)(tlv3); }
    {cgc_size_t tlv27; tlv27 = (cgc_size_t)(tlv3); }
    {char * tlv14; tlv14 = (char *)(tlv3); }
    {int tlv4; tlv4 = (int)(tlv3); }
    {int tlv5; tlv5 = (int)(tlv3); }
    {int tlv6; tlv6 = (int)(tlv3); }
    {unsigned int genre; genre = (unsigned int)(tlv3); }
    {int tlv7; tlv7 = (int)(tlv3); }
    {unsigned int rating; rating = (unsigned int)(tlv3); }
    {int tlv38; tlv38 = (int)(tlv3); }
    {char * tlv37; tlv37 = (char *)(tlv3); }
    {cgc_size_t tlv36; tlv36 = (cgc_size_t)(tlv3); }
    {char tlv35; tlv35 = (char)(tlv3); }
    {int tlv39; tlv39 = (int)(tlv3); }
    {int tlv45; tlv45 = (int)(tlv3); }
    {char * tlv44; tlv44 = (char *)(tlv3); }
    {cgc_size_t tlv43; tlv43 = (cgc_size_t)(tlv3); }
    {char tlv42; tlv42 = (char)(tlv3); }
    {int tlv46; tlv46 = (int)(tlv3); }
    {int tlv52; tlv52 = (int)(tlv3); }
    {char * tlv51; tlv51 = (char *)(tlv3); }
    {cgc_size_t tlv50; tlv50 = (cgc_size_t)(tlv3); }
    {char tlv49; tlv49 = (char)(tlv3); }
    {int tlv53; tlv53 = (int)(tlv3); }
    {int tlv59; tlv59 = (int)(tlv3); }
    {char * tlv58; tlv58 = (char *)(tlv3); }
    {cgc_size_t tlv57; tlv57 = (cgc_size_t)(tlv3); }
    {char tlv56; tlv56 = (char)(tlv3); }
    {int tlv60; tlv60 = (int)(tlv3); }
    {void * tlv65; tlv65 = (void *)(tlv3); }
    {void * tlv66; tlv66 = (void *)(tlv3); }
}
void fix_ingred_main_7_59(){
fix_ingred_main_7_59_2();
}
void fix_ingred_main_7_63_0(){
movie_t movie_ref;
    bzero(&movie_ref,1*sizeof(movie_t));
movie_t * movie = &movie_ref;
    {char buf [ 1024 ]; buf [ ( 1024 )-1 ] = (char)(movie -> desc); }
    {int tlv1; tlv1 = (int)(movie -> desc); }
    {int tlv2; tlv2 = (int)(movie -> desc); }
    {int finish; finish = (int)(movie -> desc); }
    {int tlv3; tlv3 = (int)(movie -> desc); }
    {cgc_size_t tlv25; tlv25 = (cgc_size_t)(movie -> desc); }
    {int tlv18; tlv18 = (int)(movie -> desc); }
    {char * tlv17; tlv17 = (char *)(movie -> desc); }
    {cgc_size_t tlv16; tlv16 = (cgc_size_t)(movie -> desc); }
    {char tlv15; tlv15 = (char)(movie -> desc); }
    {cgc_size_t tlv26; tlv26 = (cgc_size_t)(movie -> desc); }
    {char * tlv11; tlv11 = (char *)(movie -> desc); }
    {int tlv22; tlv22 = (int)(movie -> desc); }
    {char * tlv21; tlv21 = (char *)(movie -> desc); }
    {cgc_size_t tlv20; tlv20 = (cgc_size_t)(movie -> desc); }
    {char tlv19; tlv19 = (char)(movie -> desc); }
    {cgc_size_t tlv27; tlv27 = (cgc_size_t)(movie -> desc); }
    {char * tlv14; tlv14 = (char *)(movie -> desc); }
    {int tlv4; tlv4 = (int)(movie -> desc); }
    {int tlv5; tlv5 = (int)(movie -> desc); }
    {int tlv6; tlv6 = (int)(movie -> desc); }
    {unsigned int genre; genre = (unsigned int)(movie -> desc); }
    {int tlv7; tlv7 = (int)(movie -> desc); }
    {unsigned int rating; rating = (unsigned int)(movie -> desc); }
    {int tlv38; tlv38 = (int)(movie -> desc); }
    {char * tlv37; tlv37 = (char *)(movie -> desc); }
    {cgc_size_t tlv36; tlv36 = (cgc_size_t)(movie -> desc); }
    {char tlv35; tlv35 = (char)(movie -> desc); }
    {int tlv39; tlv39 = (int)(movie -> desc); }
    {int tlv45; tlv45 = (int)(movie -> desc); }
    {char * tlv44; tlv44 = (char *)(movie -> desc); }
    {cgc_size_t tlv43; tlv43 = (cgc_size_t)(movie -> desc); }
    {char tlv42; tlv42 = (char)(movie -> desc); }
    {int tlv46; tlv46 = (int)(movie -> desc); }
    {int tlv52; tlv52 = (int)(movie -> desc); }
    {char * tlv51; tlv51 = (char *)(movie -> desc); }
    {cgc_size_t tlv50; tlv50 = (cgc_size_t)(movie -> desc); }
    {char tlv49; tlv49 = (char)(movie -> desc); }
    {int tlv53; tlv53 = (int)(movie -> desc); }
    {int tlv59; tlv59 = (int)(movie -> desc); }
    {char * tlv58; tlv58 = (char *)(movie -> desc); }
    {cgc_size_t tlv57; tlv57 = (cgc_size_t)(movie -> desc); }
    {char tlv56; tlv56 = (char)(movie -> desc); }
    {int tlv60; tlv60 = (int)(movie -> desc); }
    {void * tlv65; tlv65 = (void *)(movie -> desc); }
    {void * tlv66; tlv66 = (void *)(movie -> desc); }
}
void fix_ingred_main_7_63(){
fix_ingred_main_7_63_0();
}
void fix_ingred_main_7_65_0(){
movie_t movie_ref;
    bzero(&movie_ref,1*sizeof(movie_t));
movie_t * movie = &movie_ref;
    {char buf [ 1024 ]; buf [ ( 1024 )-1 ] = (char)(movie -> title); }
    {int tlv1; tlv1 = (int)(movie -> title); }
    {int tlv2; tlv2 = (int)(movie -> title); }
    {int finish; finish = (int)(movie -> title); }
    {int tlv3; tlv3 = (int)(movie -> title); }
    {cgc_size_t tlv25; tlv25 = (cgc_size_t)(movie -> title); }
    {int tlv18; tlv18 = (int)(movie -> title); }
    {char * tlv17; tlv17 = (char *)(movie -> title); }
    {cgc_size_t tlv16; tlv16 = (cgc_size_t)(movie -> title); }
    {char tlv15; tlv15 = (char)(movie -> title); }
    {cgc_size_t tlv26; tlv26 = (cgc_size_t)(movie -> title); }
    {char * tlv11; tlv11 = (char *)(movie -> title); }
    {int tlv22; tlv22 = (int)(movie -> title); }
    {char * tlv21; tlv21 = (char *)(movie -> title); }
    {cgc_size_t tlv20; tlv20 = (cgc_size_t)(movie -> title); }
    {char tlv19; tlv19 = (char)(movie -> title); }
    {cgc_size_t tlv27; tlv27 = (cgc_size_t)(movie -> title); }
    {char * tlv14; tlv14 = (char *)(movie -> title); }
    {int tlv4; tlv4 = (int)(movie -> title); }
    {int tlv5; tlv5 = (int)(movie -> title); }
    {int tlv6; tlv6 = (int)(movie -> title); }
    {unsigned int genre; genre = (unsigned int)(movie -> title); }
    {int tlv7; tlv7 = (int)(movie -> title); }
    {unsigned int rating; rating = (unsigned int)(movie -> title); }
    {int tlv38; tlv38 = (int)(movie -> title); }
    {char * tlv37; tlv37 = (char *)(movie -> title); }
    {cgc_size_t tlv36; tlv36 = (cgc_size_t)(movie -> title); }
    {char tlv35; tlv35 = (char)(movie -> title); }
    {int tlv39; tlv39 = (int)(movie -> title); }
    {int tlv45; tlv45 = (int)(movie -> title); }
    {char * tlv44; tlv44 = (char *)(movie -> title); }
    {cgc_size_t tlv43; tlv43 = (cgc_size_t)(movie -> title); }
    {char tlv42; tlv42 = (char)(movie -> title); }
    {int tlv46; tlv46 = (int)(movie -> title); }
    {int tlv52; tlv52 = (int)(movie -> title); }
    {char * tlv51; tlv51 = (char *)(movie -> title); }
    {cgc_size_t tlv50; tlv50 = (cgc_size_t)(movie -> title); }
    {char tlv49; tlv49 = (char)(movie -> title); }
    {int tlv53; tlv53 = (int)(movie -> title); }
    {int tlv59; tlv59 = (int)(movie -> title); }
    {char * tlv58; tlv58 = (char *)(movie -> title); }
    {cgc_size_t tlv57; tlv57 = (cgc_size_t)(movie -> title); }
    {char tlv56; tlv56 = (char)(movie -> title); }
    {int tlv60; tlv60 = (int)(movie -> title); }
    {void * tlv65; tlv65 = (void *)(movie -> title); }
    {void * tlv66; tlv66 = (void *)(movie -> title); }
}
void fix_ingred_main_7_65(){
fix_ingred_main_7_65_0();
}
void fix_ingred_main_7(){
fix_ingred_main_7_0();
fix_ingred_main_7_1();
fix_ingred_main_7_5();
fix_ingred_main_7_6();
fix_ingred_main_7_8();
fix_ingred_main_7_10();
fix_ingred_main_7_13();
fix_ingred_main_7_15();
fix_ingred_main_7_17();
fix_ingred_main_7_21();
fix_ingred_main_7_22();
fix_ingred_main_7_28();
fix_ingred_main_7_32();
fix_ingred_main_7_35();
fix_ingred_main_7_48();
fix_ingred_main_7_59();
fix_ingred_main_7_63();
fix_ingred_main_7_65();
}
void fix_ingred_main_8(){
}
void fix_ingred_main_9_0_0(){
    {char * new_title; new_title = (char *)(0); }
    {char * new_desc; new_desc = (char *)(0); }
    {char buf [ 1024 ]; buf [ ( 1024 )-1 ] = (char)(0); }
    {cgc_size_t tlv2; tlv2 = (cgc_size_t)(0); }
    {int tlv3; tlv3 = (int)(0); }
    {int finish; finish = (int)(0); }
    {int tlv22; tlv22 = (int)(0); }
    {char * tlv21; tlv21 = (char *)(0); }
    {char tlv19; tlv19 = (char)(0); }
    {int tlv27; tlv27 = (int)(0); }
    {char * tlv26; tlv26 = (char *)(0); }
    {cgc_size_t tlv25; tlv25 = (cgc_size_t)(0); }
    {char tlv24; tlv24 = (char)(0); }
    {int tlv5; tlv5 = (int)(0); }
    {cgc_size_t tlv11; tlv11 = (cgc_size_t)(0); }
    {int tlv12; tlv12 = (int)(0); }
    {cgc_size_t tlv13; tlv13 = (cgc_size_t)(0); }
    {int tlv41; tlv41 = (int)(0); }
    {char * tlv40; tlv40 = (char *)(0); }
    {cgc_size_t tlv39; tlv39 = (cgc_size_t)(0); }
    {char tlv38; tlv38 = (char)(0); }
    {int tlv42; tlv42 = (int)(0); }
    {cgc_size_t tlv65; tlv65 = (cgc_size_t)(0); }
    {char * tlv33; tlv33 = (char *)(0); }
    {void * tlv34; tlv34 = (void *)(0); }
    {cgc_size_t tlv66; tlv66 = (cgc_size_t)(0); }
    {char * tlv36; tlv36 = (char *)(0); }
    {void * tlv37; tlv37 = (void *)(0); }
    {int tlv48; tlv48 = (int)(0); }
    {char * tlv47; tlv47 = (char *)(0); }
    {cgc_size_t tlv46; tlv46 = (cgc_size_t)(0); }
    {char tlv45; tlv45 = (char)(0); }
    {int tlv53; tlv53 = (int)(0); }
    {char * tlv52; tlv52 = (char *)(0); }
    {cgc_size_t tlv51; tlv51 = (cgc_size_t)(0); }
    {char tlv50; tlv50 = (char)(0); }
    {int tlv58; tlv58 = (int)(0); }
    {char * tlv57; tlv57 = (char *)(0); }
    {cgc_size_t tlv56; tlv56 = (cgc_size_t)(0); }
    {char tlv55; tlv55 = (char)(0); }
    {int tlv63; tlv63 = (int)(0); }
    {char * tlv62; tlv62 = (char *)(0); }
    {cgc_size_t tlv61; tlv61 = (cgc_size_t)(0); }
    {char tlv60; tlv60 = (char)(0); }
    {int new_year; new_year = (int)(0); }
    {int new_score; new_score = (int)(0); }
    {unsigned int genre; genre = (unsigned int)(0); }
    {unsigned int rating; rating = (unsigned int)(0); }
    {int tlv69; tlv69 = (int)(0); }
    {int tlv72; tlv72 = (int)(0); }
    {int tlv75; tlv75 = (int)(0); }
    {int tlv78; tlv78 = (int)(0); }
}
void fix_ingred_main_9_0_2(){
    {char * new_title; new_title = (char *)(0); }
    {char * new_desc; new_desc = (char *)(0); }
    {cgc_size_t tlv2; tlv2 = (cgc_size_t)(0); }
    {cgc_size_t tlv4; tlv4 = (cgc_size_t)(0); }
    {int tlv27; tlv27 = (int)(0); }
    {char * tlv26; tlv26 = (char *)(0); }
    {char tlv24; tlv24 = (char)(0); }
    {cgc_size_t tlv7; tlv7 = (cgc_size_t)(0); }
    {cgc_size_t tlv9; tlv9 = (cgc_size_t)(0); }
    {int tlv10; tlv10 = (int)(0); }
    {cgc_size_t tlv11; tlv11 = (cgc_size_t)(0); }
    {cgc_size_t tlv13; tlv13 = (cgc_size_t)(0); }
    {int tlv41; tlv41 = (int)(0); }
    {char * tlv40; tlv40 = (char *)(0); }
    {cgc_size_t tlv39; tlv39 = (cgc_size_t)(0); }
    {char tlv38; tlv38 = (char)(0); }
    {int tlv42; tlv42 = (int)(0); }
    {cgc_size_t tlv65; tlv65 = (cgc_size_t)(0); }
    {char * tlv33; tlv33 = (char *)(0); }
    {void * tlv34; tlv34 = (void *)(0); }
    {cgc_size_t tlv66; tlv66 = (cgc_size_t)(0); }
    {char * tlv36; tlv36 = (char *)(0); }
    {void * tlv37; tlv37 = (void *)(0); }
    {int tlv48; tlv48 = (int)(0); }
    {char * tlv47; tlv47 = (char *)(0); }
    {cgc_size_t tlv46; tlv46 = (cgc_size_t)(0); }
    {char tlv45; tlv45 = (char)(0); }
    {char * tlv52; tlv52 = (char *)(0); }
    {cgc_size_t tlv51; tlv51 = (cgc_size_t)(0); }
    {char tlv50; tlv50 = (char)(0); }
    {int tlv58; tlv58 = (int)(0); }
    {char * tlv57; tlv57 = (char *)(0); }
    {cgc_size_t tlv56; tlv56 = (cgc_size_t)(0); }
    {char tlv55; tlv55 = (char)(0); }
    {int tlv63; tlv63 = (int)(0); }
    {char * tlv62; tlv62 = (char *)(0); }
    {cgc_size_t tlv61; tlv61 = (cgc_size_t)(0); }
    {char tlv60; tlv60 = (char)(0); }
    {int new_year; new_year = (int)(0); }
    {int new_score; new_score = (int)(0); }
    {int tlv69; tlv69 = (int)(0); }
    {int tlv72; tlv72 = (int)(0); }
    {int tlv75; tlv75 = (int)(0); }
    {int tlv78; tlv78 = (int)(0); }
}
void fix_ingred_main_9_0(){
fix_ingred_main_9_0_0();
fix_ingred_main_9_0_2();
}
void fix_ingred_main_9_3_1(){
unsigned int num_movies;
    bzero(&num_movies,sizeof(unsigned int));
    {char * new_title; new_title = (char *)(num_movies); }
    {char * new_desc; new_desc = (char *)(num_movies); }
    {char buf [ 1024 ]; buf [ ( 1024 )-1 ] = (char)(num_movies); }
    {cgc_size_t tlv2; tlv2 = (cgc_size_t)(num_movies); }
    {int tlv3; tlv3 = (int)(num_movies); }
    {cgc_size_t tlv4; tlv4 = (cgc_size_t)(num_movies); }
    {int finish; finish = (int)(num_movies); }
    {int tlv22; tlv22 = (int)(num_movies); }
    {char * tlv21; tlv21 = (char *)(num_movies); }
    {cgc_size_t tlv20; tlv20 = (cgc_size_t)(num_movies); }
    {char tlv19; tlv19 = (char)(num_movies); }
    {int tlv27; tlv27 = (int)(num_movies); }
    {char * tlv26; tlv26 = (char *)(num_movies); }
    {cgc_size_t tlv25; tlv25 = (cgc_size_t)(num_movies); }
    {char tlv24; tlv24 = (char)(num_movies); }
    {int tlv5; tlv5 = (int)(num_movies); }
    {cgc_size_t tlv7; tlv7 = (cgc_size_t)(num_movies); }
    {cgc_size_t tlv9; tlv9 = (cgc_size_t)(num_movies); }
    {int tlv10; tlv10 = (int)(num_movies); }
    {cgc_size_t tlv11; tlv11 = (cgc_size_t)(num_movies); }
    {int tlv12; tlv12 = (int)(num_movies); }
    {cgc_size_t tlv13; tlv13 = (cgc_size_t)(num_movies); }
    {int tlv41; tlv41 = (int)(num_movies); }
    {char * tlv40; tlv40 = (char *)(num_movies); }
    {cgc_size_t tlv39; tlv39 = (cgc_size_t)(num_movies); }
    {char tlv38; tlv38 = (char)(num_movies); }
    {int tlv42; tlv42 = (int)(num_movies); }
    {cgc_size_t tlv65; tlv65 = (cgc_size_t)(num_movies); }
    {char * tlv33; tlv33 = (char *)(num_movies); }
    {void * tlv34; tlv34 = (void *)(num_movies); }
    {cgc_size_t tlv66; tlv66 = (cgc_size_t)(num_movies); }
    {char * tlv36; tlv36 = (char *)(num_movies); }
    {void * tlv37; tlv37 = (void *)(num_movies); }
    {int tlv48; tlv48 = (int)(num_movies); }
    {char * tlv47; tlv47 = (char *)(num_movies); }
    {cgc_size_t tlv46; tlv46 = (cgc_size_t)(num_movies); }
    {char tlv45; tlv45 = (char)(num_movies); }
    {int tlv53; tlv53 = (int)(num_movies); }
    {char * tlv52; tlv52 = (char *)(num_movies); }
    {cgc_size_t tlv51; tlv51 = (cgc_size_t)(num_movies); }
    {char tlv50; tlv50 = (char)(num_movies); }
    {int tlv58; tlv58 = (int)(num_movies); }
    {char * tlv57; tlv57 = (char *)(num_movies); }
    {cgc_size_t tlv56; tlv56 = (cgc_size_t)(num_movies); }
    {char tlv55; tlv55 = (char)(num_movies); }
    {int tlv63; tlv63 = (int)(num_movies); }
    {char * tlv62; tlv62 = (char *)(num_movies); }
    {cgc_size_t tlv61; tlv61 = (cgc_size_t)(num_movies); }
    {char tlv60; tlv60 = (char)(num_movies); }
    {int new_year; new_year = (int)(num_movies); }
    {int new_score; new_score = (int)(num_movies); }
    {unsigned int genre; genre = (unsigned int)(num_movies); }
    {unsigned int rating; rating = (unsigned int)(num_movies); }
    {int tlv69; tlv69 = (int)(num_movies); }
    {int tlv72; tlv72 = (int)(num_movies); }
    {int tlv75; tlv75 = (int)(num_movies); }
    {int tlv78; tlv78 = (int)(num_movies); }
}
void fix_ingred_main_9_3(){
fix_ingred_main_9_3_1();
}
void fix_ingred_main_9_7_0(){
char buf [ 1024 ];
    bzero(&buf,( 1024 *sizeof(char) ) );
    {char * new_title; new_title = (char *)(STDIN); }
    {char * new_desc; new_desc = (char *)(STDIN); }
    {cgc_size_t tlv2; tlv2 = (cgc_size_t)(STDIN); }
    {cgc_size_t tlv4; tlv4 = (cgc_size_t)(STDIN); }
    {int tlv27; tlv27 = (int)(STDIN); }
    {char * tlv26; tlv26 = (char *)(STDIN); }
    {char tlv24; tlv24 = (char)(STDIN); }
    {cgc_size_t tlv7; tlv7 = (cgc_size_t)(STDIN); }
    {cgc_size_t tlv9; tlv9 = (cgc_size_t)(STDIN); }
    {int tlv10; tlv10 = (int)(STDIN); }
    {cgc_size_t tlv11; tlv11 = (cgc_size_t)(STDIN); }
    {cgc_size_t tlv13; tlv13 = (cgc_size_t)(STDIN); }
    {int tlv41; tlv41 = (int)(STDIN); }
    {char * tlv40; tlv40 = (char *)(STDIN); }
    {cgc_size_t tlv39; tlv39 = (cgc_size_t)(STDIN); }
    {char tlv38; tlv38 = (char)(STDIN); }
    {int tlv42; tlv42 = (int)(STDIN); }
    {cgc_size_t tlv65; tlv65 = (cgc_size_t)(STDIN); }
    {char * tlv33; tlv33 = (char *)(STDIN); }
    {void * tlv34; tlv34 = (void *)(STDIN); }
    {cgc_size_t tlv66; tlv66 = (cgc_size_t)(STDIN); }
    {char * tlv36; tlv36 = (char *)(STDIN); }
    {void * tlv37; tlv37 = (void *)(STDIN); }
    {int tlv48; tlv48 = (int)(STDIN); }
    {char * tlv47; tlv47 = (char *)(STDIN); }
    {cgc_size_t tlv46; tlv46 = (cgc_size_t)(STDIN); }
    {char tlv45; tlv45 = (char)(STDIN); }
    {char * tlv52; tlv52 = (char *)(STDIN); }
    {cgc_size_t tlv51; tlv51 = (cgc_size_t)(STDIN); }
    {char tlv50; tlv50 = (char)(STDIN); }
    {int tlv58; tlv58 = (int)(STDIN); }
    {char * tlv57; tlv57 = (char *)(STDIN); }
    {cgc_size_t tlv56; tlv56 = (cgc_size_t)(STDIN); }
    {char tlv55; tlv55 = (char)(STDIN); }
    {int tlv63; tlv63 = (int)(STDIN); }
    {char * tlv62; tlv62 = (char *)(STDIN); }
    {cgc_size_t tlv61; tlv61 = (cgc_size_t)(STDIN); }
    {char tlv60; tlv60 = (char)(STDIN); }
    {int new_year; new_year = (int)(STDIN); }
    {int new_score; new_score = (int)(STDIN); }
    {int tlv69; tlv69 = (int)(STDIN); }
    {int tlv72; tlv72 = (int)(STDIN); }
    {int tlv75; tlv75 = (int)(STDIN); }
    {int tlv78; tlv78 = (int)(STDIN); }
}
void fix_ingred_main_9_7_1(){
char buf [ 1024 ];
    bzero(&buf,( 1024 *sizeof(char) ) );
    {char * new_title; new_title = (char *)(buf); }
    {char * new_desc; new_desc = (char *)(buf); }
    {cgc_size_t tlv2; tlv2 = (cgc_size_t)(buf); }
    {cgc_size_t tlv4; tlv4 = (cgc_size_t)(buf); }
    {int tlv27; tlv27 = (int)(buf); }
    {char * tlv26; tlv26 = (char *)(buf); }
    {char tlv24; tlv24 = (char)(buf); }
    {cgc_size_t tlv7; tlv7 = (cgc_size_t)(buf); }
    {cgc_size_t tlv9; tlv9 = (cgc_size_t)(buf); }
    {int tlv10; tlv10 = (int)(buf); }
    {cgc_size_t tlv11; tlv11 = (cgc_size_t)(buf); }
    {cgc_size_t tlv13; tlv13 = (cgc_size_t)(buf); }
    {int tlv41; tlv41 = (int)(buf); }
    {char * tlv40; tlv40 = (char *)(buf); }
    {cgc_size_t tlv39; tlv39 = (cgc_size_t)(buf); }
    {char tlv38; tlv38 = (char)(buf); }
    {int tlv42; tlv42 = (int)(buf); }
    {cgc_size_t tlv65; tlv65 = (cgc_size_t)(buf); }
    {char * tlv33; tlv33 = (char *)(buf); }
    {void * tlv34; tlv34 = (void *)(buf); }
    {cgc_size_t tlv66; tlv66 = (cgc_size_t)(buf); }
    {char * tlv36; tlv36 = (char *)(buf); }
    {void * tlv37; tlv37 = (void *)(buf); }
    {int tlv48; tlv48 = (int)(buf); }
    {char * tlv47; tlv47 = (char *)(buf); }
    {cgc_size_t tlv46; tlv46 = (cgc_size_t)(buf); }
    {char tlv45; tlv45 = (char)(buf); }
    {char * tlv52; tlv52 = (char *)(buf); }
    {cgc_size_t tlv51; tlv51 = (cgc_size_t)(buf); }
    {char tlv50; tlv50 = (char)(buf); }
    {int tlv58; tlv58 = (int)(buf); }
    {char * tlv57; tlv57 = (char *)(buf); }
    {cgc_size_t tlv56; tlv56 = (cgc_size_t)(buf); }
    {char tlv55; tlv55 = (char)(buf); }
    {int tlv63; tlv63 = (int)(buf); }
    {char * tlv62; tlv62 = (char *)(buf); }
    {cgc_size_t tlv61; tlv61 = (cgc_size_t)(buf); }
    {char tlv60; tlv60 = (char)(buf); }
    {int new_year; new_year = (int)(buf); }
    {int new_score; new_score = (int)(buf); }
    {int tlv69; tlv69 = (int)(buf); }
    {int tlv72; tlv72 = (int)(buf); }
    {int tlv75; tlv75 = (int)(buf); }
    {int tlv78; tlv78 = (int)(buf); }
}
void fix_ingred_main_9_7_2(){
char buf [ 1024 ];
    bzero(&buf,( 1024 *sizeof(char) ) );
    {char * new_title; new_title = (char *)(sizeof ( buf )); }
    {char * new_desc; new_desc = (char *)(sizeof ( buf )); }
    {cgc_size_t tlv2; tlv2 = (cgc_size_t)(sizeof ( buf )); }
    {cgc_size_t tlv4; tlv4 = (cgc_size_t)(sizeof ( buf )); }
    {int tlv27; tlv27 = (int)(sizeof ( buf )); }
    {char * tlv26; tlv26 = (char *)(sizeof ( buf )); }
    {char tlv24; tlv24 = (char)(sizeof ( buf )); }
    {cgc_size_t tlv7; tlv7 = (cgc_size_t)(sizeof ( buf )); }
    {cgc_size_t tlv9; tlv9 = (cgc_size_t)(sizeof ( buf )); }
    {int tlv10; tlv10 = (int)(sizeof ( buf )); }
    {cgc_size_t tlv11; tlv11 = (cgc_size_t)(sizeof ( buf )); }
    {cgc_size_t tlv13; tlv13 = (cgc_size_t)(sizeof ( buf )); }
    {int tlv41; tlv41 = (int)(sizeof ( buf )); }
    {char * tlv40; tlv40 = (char *)(sizeof ( buf )); }
    {cgc_size_t tlv39; tlv39 = (cgc_size_t)(sizeof ( buf )); }
    {char tlv38; tlv38 = (char)(sizeof ( buf )); }
    {int tlv42; tlv42 = (int)(sizeof ( buf )); }
    {cgc_size_t tlv65; tlv65 = (cgc_size_t)(sizeof ( buf )); }
    {char * tlv33; tlv33 = (char *)(sizeof ( buf )); }
    {void * tlv34; tlv34 = (void *)(sizeof ( buf )); }
    {cgc_size_t tlv66; tlv66 = (cgc_size_t)(sizeof ( buf )); }
    {char * tlv36; tlv36 = (char *)(sizeof ( buf )); }
    {void * tlv37; tlv37 = (void *)(sizeof ( buf )); }
    {int tlv48; tlv48 = (int)(sizeof ( buf )); }
    {char * tlv47; tlv47 = (char *)(sizeof ( buf )); }
    {cgc_size_t tlv46; tlv46 = (cgc_size_t)(sizeof ( buf )); }
    {char tlv45; tlv45 = (char)(sizeof ( buf )); }
    {char * tlv52; tlv52 = (char *)(sizeof ( buf )); }
    {cgc_size_t tlv51; tlv51 = (cgc_size_t)(sizeof ( buf )); }
    {char tlv50; tlv50 = (char)(sizeof ( buf )); }
    {int tlv58; tlv58 = (int)(sizeof ( buf )); }
    {char * tlv57; tlv57 = (char *)(sizeof ( buf )); }
    {cgc_size_t tlv56; tlv56 = (cgc_size_t)(sizeof ( buf )); }
    {char tlv55; tlv55 = (char)(sizeof ( buf )); }
    {int tlv63; tlv63 = (int)(sizeof ( buf )); }
    {char * tlv62; tlv62 = (char *)(sizeof ( buf )); }
    {cgc_size_t tlv61; tlv61 = (cgc_size_t)(sizeof ( buf )); }
    {char tlv60; tlv60 = (char)(sizeof ( buf )); }
    {int new_year; new_year = (int)(sizeof ( buf )); }
    {int new_score; new_score = (int)(sizeof ( buf )); }
    {int tlv69; tlv69 = (int)(sizeof ( buf )); }
    {int tlv72; tlv72 = (int)(sizeof ( buf )); }
    {int tlv75; tlv75 = (int)(sizeof ( buf )); }
    {int tlv78; tlv78 = (int)(sizeof ( buf )); }
}
void fix_ingred_main_9_7_3(){
char buf [ 1024 ];
    bzero(&buf,( 1024 *sizeof(char) ) );
    {char * new_title; new_title = (char *)('\n'); }
    {char * new_desc; new_desc = (char *)('\n'); }
    {cgc_size_t tlv2; tlv2 = (cgc_size_t)('\n'); }
    {cgc_size_t tlv4; tlv4 = (cgc_size_t)('\n'); }
    {int tlv27; tlv27 = (int)('\n'); }
    {char * tlv26; tlv26 = (char *)('\n'); }
    {char tlv24; tlv24 = (char)('\n'); }
    {cgc_size_t tlv7; tlv7 = (cgc_size_t)('\n'); }
    {cgc_size_t tlv9; tlv9 = (cgc_size_t)('\n'); }
    {int tlv10; tlv10 = (int)('\n'); }
    {cgc_size_t tlv11; tlv11 = (cgc_size_t)('\n'); }
    {cgc_size_t tlv13; tlv13 = (cgc_size_t)('\n'); }
    {int tlv41; tlv41 = (int)('\n'); }
    {char * tlv40; tlv40 = (char *)('\n'); }
    {cgc_size_t tlv39; tlv39 = (cgc_size_t)('\n'); }
    {char tlv38; tlv38 = (char)('\n'); }
    {int tlv42; tlv42 = (int)('\n'); }
    {cgc_size_t tlv65; tlv65 = (cgc_size_t)('\n'); }
    {char * tlv33; tlv33 = (char *)('\n'); }
    {void * tlv34; tlv34 = (void *)('\n'); }
    {cgc_size_t tlv66; tlv66 = (cgc_size_t)('\n'); }
    {char * tlv36; tlv36 = (char *)('\n'); }
    {void * tlv37; tlv37 = (void *)('\n'); }
    {int tlv48; tlv48 = (int)('\n'); }
    {char * tlv47; tlv47 = (char *)('\n'); }
    {cgc_size_t tlv46; tlv46 = (cgc_size_t)('\n'); }
    {char tlv45; tlv45 = (char)('\n'); }
    {char * tlv52; tlv52 = (char *)('\n'); }
    {cgc_size_t tlv51; tlv51 = (cgc_size_t)('\n'); }
    {char tlv50; tlv50 = (char)('\n'); }
    {int tlv58; tlv58 = (int)('\n'); }
    {char * tlv57; tlv57 = (char *)('\n'); }
    {cgc_size_t tlv56; tlv56 = (cgc_size_t)('\n'); }
    {char tlv55; tlv55 = (char)('\n'); }
    {int tlv63; tlv63 = (int)('\n'); }
    {char * tlv62; tlv62 = (char *)('\n'); }
    {cgc_size_t tlv61; tlv61 = (cgc_size_t)('\n'); }
    {char tlv60; tlv60 = (char)('\n'); }
    {int new_year; new_year = (int)('\n'); }
    {int new_score; new_score = (int)('\n'); }
    {int tlv69; tlv69 = (int)('\n'); }
    {int tlv72; tlv72 = (int)('\n'); }
    {int tlv75; tlv75 = (int)('\n'); }
    {int tlv78; tlv78 = (int)('\n'); }
}
void fix_ingred_main_9_7(){
fix_ingred_main_9_7_0();
fix_ingred_main_9_7_1();
fix_ingred_main_9_7_2();
fix_ingred_main_9_7_3();
}
void fix_ingred_main_9_8_1(){
int tlv5;
    bzero(&tlv5,sizeof(int));
    {unsigned int movie_id; movie_id = (unsigned int)(tlv5); }
    {unsigned int num_movies; num_movies = (unsigned int)(tlv5); }
    {char * new_title; new_title = (char *)(tlv5); }
    {char * new_desc; new_desc = (char *)(tlv5); }
    {cgc_size_t tlv2; tlv2 = (cgc_size_t)(tlv5); }
    {cgc_size_t tlv4; tlv4 = (cgc_size_t)(tlv5); }
    {int tlv17; tlv17 = (int)(tlv5); }
    {int tlv27; tlv27 = (int)(tlv5); }
    {char * tlv26; tlv26 = (char *)(tlv5); }
    {char tlv24; tlv24 = (char)(tlv5); }
    {cgc_size_t tlv7; tlv7 = (cgc_size_t)(tlv5); }
    {int tlv8; tlv8 = (int)(tlv5); }
    {cgc_size_t tlv9; tlv9 = (cgc_size_t)(tlv5); }
    {int tlv10; tlv10 = (int)(tlv5); }
    {cgc_size_t tlv11; tlv11 = (cgc_size_t)(tlv5); }
    {int tlv12; tlv12 = (int)(tlv5); }
    {cgc_size_t tlv13; tlv13 = (cgc_size_t)(tlv5); }
    {int tlv41; tlv41 = (int)(tlv5); }
    {char * tlv40; tlv40 = (char *)(tlv5); }
    {cgc_size_t tlv39; tlv39 = (cgc_size_t)(tlv5); }
    {char tlv38; tlv38 = (char)(tlv5); }
    {int tlv42; tlv42 = (int)(tlv5); }
    {cgc_size_t tlv65; tlv65 = (cgc_size_t)(tlv5); }
    {char * tlv33; tlv33 = (char *)(tlv5); }
    {void * tlv34; tlv34 = (void *)(tlv5); }
    {cgc_size_t tlv66; tlv66 = (cgc_size_t)(tlv5); }
    {char * tlv36; tlv36 = (char *)(tlv5); }
    {void * tlv37; tlv37 = (void *)(tlv5); }
    {int tlv48; tlv48 = (int)(tlv5); }
    {char * tlv47; tlv47 = (char *)(tlv5); }
    {cgc_size_t tlv46; tlv46 = (cgc_size_t)(tlv5); }
    {char tlv45; tlv45 = (char)(tlv5); }
    {char * tlv52; tlv52 = (char *)(tlv5); }
    {cgc_size_t tlv51; tlv51 = (cgc_size_t)(tlv5); }
    {char tlv50; tlv50 = (char)(tlv5); }
    {int tlv58; tlv58 = (int)(tlv5); }
    {char * tlv57; tlv57 = (char *)(tlv5); }
    {cgc_size_t tlv56; tlv56 = (cgc_size_t)(tlv5); }
    {char tlv55; tlv55 = (char)(tlv5); }
    {int tlv63; tlv63 = (int)(tlv5); }
    {char * tlv62; tlv62 = (char *)(tlv5); }
    {cgc_size_t tlv61; tlv61 = (cgc_size_t)(tlv5); }
    {char tlv60; tlv60 = (char)(tlv5); }
    {int new_year; new_year = (int)(tlv5); }
    {int new_score; new_score = (int)(tlv5); }
    {int tlv69; tlv69 = (int)(tlv5); }
    {int tlv72; tlv72 = (int)(tlv5); }
    {int tlv75; tlv75 = (int)(tlv5); }
    {int tlv78; tlv78 = (int)(tlv5); }
}
void fix_ingred_main_9_8(){
fix_ingred_main_9_8_1();
}
void fix_ingred_main_9_9_1(){
    {char * new_title; new_title = (char *)(10); }
    {char * new_desc; new_desc = (char *)(10); }
    {cgc_size_t tlv2; tlv2 = (cgc_size_t)(10); }
    {cgc_size_t tlv4; tlv4 = (cgc_size_t)(10); }
    {int tlv27; tlv27 = (int)(10); }
    {char * tlv26; tlv26 = (char *)(10); }
    {char tlv24; tlv24 = (char)(10); }
    {cgc_size_t tlv7; tlv7 = (cgc_size_t)(10); }
    {cgc_size_t tlv9; tlv9 = (cgc_size_t)(10); }
    {int tlv10; tlv10 = (int)(10); }
    {cgc_size_t tlv11; tlv11 = (cgc_size_t)(10); }
    {int tlv12; tlv12 = (int)(10); }
    {cgc_size_t tlv13; tlv13 = (cgc_size_t)(10); }
    {int tlv41; tlv41 = (int)(10); }
    {char * tlv40; tlv40 = (char *)(10); }
    {cgc_size_t tlv39; tlv39 = (cgc_size_t)(10); }
    {char tlv38; tlv38 = (char)(10); }
    {int tlv42; tlv42 = (int)(10); }
    {cgc_size_t tlv65; tlv65 = (cgc_size_t)(10); }
    {char * tlv33; tlv33 = (char *)(10); }
    {void * tlv34; tlv34 = (void *)(10); }
    {cgc_size_t tlv66; tlv66 = (cgc_size_t)(10); }
    {char * tlv36; tlv36 = (char *)(10); }
    {void * tlv37; tlv37 = (void *)(10); }
    {int tlv48; tlv48 = (int)(10); }
    {char * tlv47; tlv47 = (char *)(10); }
    {cgc_size_t tlv46; tlv46 = (cgc_size_t)(10); }
    {char tlv45; tlv45 = (char)(10); }
    {char * tlv52; tlv52 = (char *)(10); }
    {cgc_size_t tlv51; tlv51 = (cgc_size_t)(10); }
    {char tlv50; tlv50 = (char)(10); }
    {int tlv58; tlv58 = (int)(10); }
    {char * tlv57; tlv57 = (char *)(10); }
    {cgc_size_t tlv56; tlv56 = (cgc_size_t)(10); }
    {char tlv55; tlv55 = (char)(10); }
    {int tlv63; tlv63 = (int)(10); }
    {char * tlv62; tlv62 = (char *)(10); }
    {cgc_size_t tlv61; tlv61 = (cgc_size_t)(10); }
    {char tlv60; tlv60 = (char)(10); }
    {int new_year; new_year = (int)(10); }
    {int new_score; new_score = (int)(10); }
    {int tlv69; tlv69 = (int)(10); }
    {int tlv72; tlv72 = (int)(10); }
    {int tlv75; tlv75 = (int)(10); }
    {int tlv78; tlv78 = (int)(10); }
}
void fix_ingred_main_9_9(){
fix_ingred_main_9_9_1();
}
void fix_ingred_main_9_10_1(){
unsigned int movie_id;
    bzero(&movie_id,sizeof(unsigned int));
    {char * new_title; new_title = (char *)(movie_id); }
    {char * new_desc; new_desc = (char *)(movie_id); }
    {char buf [ 1024 ]; buf [ ( 1024 )-1 ] = (char)(movie_id); }
    {cgc_size_t tlv2; tlv2 = (cgc_size_t)(movie_id); }
    {int tlv3; tlv3 = (int)(movie_id); }
    {cgc_size_t tlv4; tlv4 = (cgc_size_t)(movie_id); }
    {int finish; finish = (int)(movie_id); }
    {int tlv22; tlv22 = (int)(movie_id); }
    {char * tlv21; tlv21 = (char *)(movie_id); }
    {cgc_size_t tlv20; tlv20 = (cgc_size_t)(movie_id); }
    {char tlv19; tlv19 = (char)(movie_id); }
    {int tlv27; tlv27 = (int)(movie_id); }
    {char * tlv26; tlv26 = (char *)(movie_id); }
    {cgc_size_t tlv25; tlv25 = (cgc_size_t)(movie_id); }
    {char tlv24; tlv24 = (char)(movie_id); }
    {int tlv5; tlv5 = (int)(movie_id); }
    {cgc_size_t tlv7; tlv7 = (cgc_size_t)(movie_id); }
    {cgc_size_t tlv9; tlv9 = (cgc_size_t)(movie_id); }
    {int tlv10; tlv10 = (int)(movie_id); }
    {cgc_size_t tlv11; tlv11 = (cgc_size_t)(movie_id); }
    {int tlv12; tlv12 = (int)(movie_id); }
    {cgc_size_t tlv13; tlv13 = (cgc_size_t)(movie_id); }
    {int tlv41; tlv41 = (int)(movie_id); }
    {char * tlv40; tlv40 = (char *)(movie_id); }
    {cgc_size_t tlv39; tlv39 = (cgc_size_t)(movie_id); }
    {char tlv38; tlv38 = (char)(movie_id); }
    {int tlv42; tlv42 = (int)(movie_id); }
    {cgc_size_t tlv65; tlv65 = (cgc_size_t)(movie_id); }
    {char * tlv33; tlv33 = (char *)(movie_id); }
    {void * tlv34; tlv34 = (void *)(movie_id); }
    {cgc_size_t tlv66; tlv66 = (cgc_size_t)(movie_id); }
    {char * tlv36; tlv36 = (char *)(movie_id); }
    {void * tlv37; tlv37 = (void *)(movie_id); }
    {int tlv48; tlv48 = (int)(movie_id); }
    {char * tlv47; tlv47 = (char *)(movie_id); }
    {cgc_size_t tlv46; tlv46 = (cgc_size_t)(movie_id); }
    {char tlv45; tlv45 = (char)(movie_id); }
    {int tlv53; tlv53 = (int)(movie_id); }
    {char * tlv52; tlv52 = (char *)(movie_id); }
    {cgc_size_t tlv51; tlv51 = (cgc_size_t)(movie_id); }
    {char tlv50; tlv50 = (char)(movie_id); }
    {int tlv58; tlv58 = (int)(movie_id); }
    {char * tlv57; tlv57 = (char *)(movie_id); }
    {cgc_size_t tlv56; tlv56 = (cgc_size_t)(movie_id); }
    {char tlv55; tlv55 = (char)(movie_id); }
    {int tlv63; tlv63 = (int)(movie_id); }
    {char * tlv62; tlv62 = (char *)(movie_id); }
    {cgc_size_t tlv61; tlv61 = (cgc_size_t)(movie_id); }
    {char tlv60; tlv60 = (char)(movie_id); }
    {int new_year; new_year = (int)(movie_id); }
    {int new_score; new_score = (int)(movie_id); }
    {unsigned int genre; genre = (unsigned int)(movie_id); }
    {unsigned int rating; rating = (unsigned int)(movie_id); }
    {int tlv69; tlv69 = (int)(movie_id); }
    {int tlv72; tlv72 = (int)(movie_id); }
    {int tlv75; tlv75 = (int)(movie_id); }
    {int tlv78; tlv78 = (int)(movie_id); }
}
void fix_ingred_main_9_10_2(){
unsigned int movie_id;
    bzero(&movie_id,sizeof(unsigned int));
    {char * new_title; new_title = (char *)(1); }
    {char * new_desc; new_desc = (char *)(1); }
    {char buf [ 1024 ]; buf [ ( 1024 )-1 ] = (char)(1); }
    {cgc_size_t tlv2; tlv2 = (cgc_size_t)(1); }
    {int tlv3; tlv3 = (int)(1); }
    {cgc_size_t tlv4; tlv4 = (cgc_size_t)(1); }
    {int finish; finish = (int)(1); }
    {int tlv22; tlv22 = (int)(1); }
    {char * tlv21; tlv21 = (char *)(1); }
    {cgc_size_t tlv20; tlv20 = (cgc_size_t)(1); }
    {char tlv19; tlv19 = (char)(1); }
    {int tlv27; tlv27 = (int)(1); }
    {char * tlv26; tlv26 = (char *)(1); }
    {cgc_size_t tlv25; tlv25 = (cgc_size_t)(1); }
    {char tlv24; tlv24 = (char)(1); }
    {int tlv5; tlv5 = (int)(1); }
    {cgc_size_t tlv7; tlv7 = (cgc_size_t)(1); }
    {cgc_size_t tlv9; tlv9 = (cgc_size_t)(1); }
    {int tlv10; tlv10 = (int)(1); }
    {cgc_size_t tlv11; tlv11 = (cgc_size_t)(1); }
    {int tlv12; tlv12 = (int)(1); }
    {cgc_size_t tlv13; tlv13 = (cgc_size_t)(1); }
    {int tlv41; tlv41 = (int)(1); }
    {char * tlv40; tlv40 = (char *)(1); }
    {cgc_size_t tlv39; tlv39 = (cgc_size_t)(1); }
    {char tlv38; tlv38 = (char)(1); }
    {int tlv42; tlv42 = (int)(1); }
    {cgc_size_t tlv65; tlv65 = (cgc_size_t)(1); }
    {char * tlv33; tlv33 = (char *)(1); }
    {void * tlv34; tlv34 = (void *)(1); }
    {cgc_size_t tlv66; tlv66 = (cgc_size_t)(1); }
    {char * tlv36; tlv36 = (char *)(1); }
    {void * tlv37; tlv37 = (void *)(1); }
    {int tlv48; tlv48 = (int)(1); }
    {char * tlv47; tlv47 = (char *)(1); }
    {cgc_size_t tlv46; tlv46 = (cgc_size_t)(1); }
    {char tlv45; tlv45 = (char)(1); }
    {int tlv53; tlv53 = (int)(1); }
    {char * tlv52; tlv52 = (char *)(1); }
    {cgc_size_t tlv51; tlv51 = (cgc_size_t)(1); }
    {char tlv50; tlv50 = (char)(1); }
    {int tlv58; tlv58 = (int)(1); }
    {char * tlv57; tlv57 = (char *)(1); }
    {cgc_size_t tlv56; tlv56 = (cgc_size_t)(1); }
    {char tlv55; tlv55 = (char)(1); }
    {int tlv63; tlv63 = (int)(1); }
    {char * tlv62; tlv62 = (char *)(1); }
    {cgc_size_t tlv61; tlv61 = (cgc_size_t)(1); }
    {char tlv60; tlv60 = (char)(1); }
    {int new_year; new_year = (int)(1); }
    {int new_score; new_score = (int)(1); }
    {unsigned int genre; genre = (unsigned int)(1); }
    {unsigned int rating; rating = (unsigned int)(1); }
    {int tlv69; tlv69 = (int)(1); }
    {int tlv72; tlv72 = (int)(1); }
    {int tlv75; tlv75 = (int)(1); }
    {int tlv78; tlv78 = (int)(1); }
}
void fix_ingred_main_9_10(){
fix_ingred_main_9_10_1();
fix_ingred_main_9_10_2();
}
void fix_ingred_main_9_12_1(){
unsigned int movie_id;
    bzero(&movie_id,sizeof(unsigned int));
    {char * new_title; new_title = (char *)(movie_id); }
    {char * new_desc; new_desc = (char *)(movie_id); }
    {char buf [ 1024 ]; buf [ ( 1024 )-1 ] = (char)(movie_id); }
    {cgc_size_t tlv2; tlv2 = (cgc_size_t)(movie_id); }
    {int tlv3; tlv3 = (int)(movie_id); }
    {cgc_size_t tlv4; tlv4 = (cgc_size_t)(movie_id); }
    {int finish; finish = (int)(movie_id); }
    {int tlv22; tlv22 = (int)(movie_id); }
    {char * tlv21; tlv21 = (char *)(movie_id); }
    {cgc_size_t tlv20; tlv20 = (cgc_size_t)(movie_id); }
    {char tlv19; tlv19 = (char)(movie_id); }
    {int tlv27; tlv27 = (int)(movie_id); }
    {char * tlv26; tlv26 = (char *)(movie_id); }
    {cgc_size_t tlv25; tlv25 = (cgc_size_t)(movie_id); }
    {char tlv24; tlv24 = (char)(movie_id); }
    {int tlv5; tlv5 = (int)(movie_id); }
    {cgc_size_t tlv7; tlv7 = (cgc_size_t)(movie_id); }
    {cgc_size_t tlv9; tlv9 = (cgc_size_t)(movie_id); }
    {int tlv10; tlv10 = (int)(movie_id); }
    {cgc_size_t tlv11; tlv11 = (cgc_size_t)(movie_id); }
    {int tlv12; tlv12 = (int)(movie_id); }
    {cgc_size_t tlv13; tlv13 = (cgc_size_t)(movie_id); }
    {int tlv41; tlv41 = (int)(movie_id); }
    {char * tlv40; tlv40 = (char *)(movie_id); }
    {cgc_size_t tlv39; tlv39 = (cgc_size_t)(movie_id); }
    {char tlv38; tlv38 = (char)(movie_id); }
    {int tlv42; tlv42 = (int)(movie_id); }
    {cgc_size_t tlv65; tlv65 = (cgc_size_t)(movie_id); }
    {char * tlv33; tlv33 = (char *)(movie_id); }
    {void * tlv34; tlv34 = (void *)(movie_id); }
    {cgc_size_t tlv66; tlv66 = (cgc_size_t)(movie_id); }
    {char * tlv36; tlv36 = (char *)(movie_id); }
    {void * tlv37; tlv37 = (void *)(movie_id); }
    {int tlv48; tlv48 = (int)(movie_id); }
    {char * tlv47; tlv47 = (char *)(movie_id); }
    {cgc_size_t tlv46; tlv46 = (cgc_size_t)(movie_id); }
    {char tlv45; tlv45 = (char)(movie_id); }
    {int tlv53; tlv53 = (int)(movie_id); }
    {char * tlv52; tlv52 = (char *)(movie_id); }
    {cgc_size_t tlv51; tlv51 = (cgc_size_t)(movie_id); }
    {char tlv50; tlv50 = (char)(movie_id); }
    {int tlv58; tlv58 = (int)(movie_id); }
    {char * tlv57; tlv57 = (char *)(movie_id); }
    {cgc_size_t tlv56; tlv56 = (cgc_size_t)(movie_id); }
    {char tlv55; tlv55 = (char)(movie_id); }
    {int tlv63; tlv63 = (int)(movie_id); }
    {char * tlv62; tlv62 = (char *)(movie_id); }
    {cgc_size_t tlv61; tlv61 = (cgc_size_t)(movie_id); }
    {char tlv60; tlv60 = (char)(movie_id); }
    {int new_year; new_year = (int)(movie_id); }
    {int new_score; new_score = (int)(movie_id); }
    {unsigned int genre; genre = (unsigned int)(movie_id); }
    {unsigned int rating; rating = (unsigned int)(movie_id); }
    {int tlv69; tlv69 = (int)(movie_id); }
    {int tlv72; tlv72 = (int)(movie_id); }
    {int tlv75; tlv75 = (int)(movie_id); }
    {int tlv78; tlv78 = (int)(movie_id); }
}
void fix_ingred_main_9_12(){
fix_ingred_main_9_12_1();
}
void fix_ingred_main_9_15_2(){
int tlv1;
    bzero(&tlv1,sizeof(int));
    {char * new_title; new_title = (char *)(tlv1); }
    {char * new_desc; new_desc = (char *)(tlv1); }
    {cgc_size_t tlv2; tlv2 = (cgc_size_t)(tlv1); }
    {cgc_size_t tlv4; tlv4 = (cgc_size_t)(tlv1); }
    {int tlv27; tlv27 = (int)(tlv1); }
    {char * tlv26; tlv26 = (char *)(tlv1); }
    {char tlv24; tlv24 = (char)(tlv1); }
    {cgc_size_t tlv7; tlv7 = (cgc_size_t)(tlv1); }
    {cgc_size_t tlv9; tlv9 = (cgc_size_t)(tlv1); }
    {int tlv10; tlv10 = (int)(tlv1); }
    {cgc_size_t tlv11; tlv11 = (cgc_size_t)(tlv1); }
    {cgc_size_t tlv13; tlv13 = (cgc_size_t)(tlv1); }
    {int tlv41; tlv41 = (int)(tlv1); }
    {char * tlv40; tlv40 = (char *)(tlv1); }
    {cgc_size_t tlv39; tlv39 = (cgc_size_t)(tlv1); }
    {char tlv38; tlv38 = (char)(tlv1); }
    {int tlv42; tlv42 = (int)(tlv1); }
    {cgc_size_t tlv65; tlv65 = (cgc_size_t)(tlv1); }
    {char * tlv33; tlv33 = (char *)(tlv1); }
    {void * tlv34; tlv34 = (void *)(tlv1); }
    {cgc_size_t tlv66; tlv66 = (cgc_size_t)(tlv1); }
    {char * tlv36; tlv36 = (char *)(tlv1); }
    {void * tlv37; tlv37 = (void *)(tlv1); }
    {int tlv48; tlv48 = (int)(tlv1); }
    {char * tlv47; tlv47 = (char *)(tlv1); }
    {cgc_size_t tlv46; tlv46 = (cgc_size_t)(tlv1); }
    {char tlv45; tlv45 = (char)(tlv1); }
    {char * tlv52; tlv52 = (char *)(tlv1); }
    {cgc_size_t tlv51; tlv51 = (cgc_size_t)(tlv1); }
    {char tlv50; tlv50 = (char)(tlv1); }
    {int tlv58; tlv58 = (int)(tlv1); }
    {char * tlv57; tlv57 = (char *)(tlv1); }
    {cgc_size_t tlv56; tlv56 = (cgc_size_t)(tlv1); }
    {char tlv55; tlv55 = (char)(tlv1); }
    {int tlv63; tlv63 = (int)(tlv1); }
    {char * tlv62; tlv62 = (char *)(tlv1); }
    {cgc_size_t tlv61; tlv61 = (cgc_size_t)(tlv1); }
    {char tlv60; tlv60 = (char)(tlv1); }
    {int new_year; new_year = (int)(tlv1); }
    {int new_score; new_score = (int)(tlv1); }
    {int tlv69; tlv69 = (int)(tlv1); }
    {int tlv72; tlv72 = (int)(tlv1); }
    {int tlv75; tlv75 = (int)(tlv1); }
    {int tlv78; tlv78 = (int)(tlv1); }
}
void fix_ingred_main_9_15(){
fix_ingred_main_9_15_2();
}
void fix_ingred_main_9_16_0(){
char tlv23_ref;
    bzero(&tlv23_ref,1*sizeof(char));
const char * tlv23 = &tlv23_ref;
    {unsigned int movie_id; movie_id = (unsigned int)(cgc_strlen ( tlv23 )); }
    {unsigned int num_movies; num_movies = (unsigned int)(cgc_strlen ( tlv23 )); }
    {char * new_title; new_title = (char *)(cgc_strlen ( tlv23 )); }
    {char * new_desc; new_desc = (char *)(cgc_strlen ( tlv23 )); }
    {char buf [ 1024 ]; buf [ ( 1024 )-1 ] = (char)(cgc_strlen ( tlv23 )); }
    {int tlv1; tlv1 = (int)(cgc_strlen ( tlv23 )); }
    {cgc_size_t tlv2; tlv2 = (cgc_size_t)(cgc_strlen ( tlv23 )); }
    {int tlv3; tlv3 = (int)(cgc_strlen ( tlv23 )); }
    {cgc_size_t tlv4; tlv4 = (cgc_size_t)(cgc_strlen ( tlv23 )); }
    {int finish; finish = (int)(cgc_strlen ( tlv23 )); }
    {int tlv17; tlv17 = (int)(cgc_strlen ( tlv23 )); }
    {int tlv22; tlv22 = (int)(cgc_strlen ( tlv23 )); }
    {char * tlv21; tlv21 = (char *)(cgc_strlen ( tlv23 )); }
    {cgc_size_t tlv20; tlv20 = (cgc_size_t)(cgc_strlen ( tlv23 )); }
    {char tlv19; tlv19 = (char)(cgc_strlen ( tlv23 )); }
    {int tlv27; tlv27 = (int)(cgc_strlen ( tlv23 )); }
    {char * tlv26; tlv26 = (char *)(cgc_strlen ( tlv23 )); }
    {cgc_size_t tlv25; tlv25 = (cgc_size_t)(cgc_strlen ( tlv23 )); }
    {char tlv24; tlv24 = (char)(cgc_strlen ( tlv23 )); }
    {int tlv5; tlv5 = (int)(cgc_strlen ( tlv23 )); }
    {int tlv6; tlv6 = (int)(cgc_strlen ( tlv23 )); }
    {cgc_size_t tlv7; tlv7 = (cgc_size_t)(cgc_strlen ( tlv23 )); }
    {int tlv8; tlv8 = (int)(cgc_strlen ( tlv23 )); }
    {cgc_size_t tlv9; tlv9 = (cgc_size_t)(cgc_strlen ( tlv23 )); }
    {int tlv10; tlv10 = (int)(cgc_strlen ( tlv23 )); }
    {cgc_size_t tlv11; tlv11 = (cgc_size_t)(cgc_strlen ( tlv23 )); }
    {int tlv12; tlv12 = (int)(cgc_strlen ( tlv23 )); }
    {cgc_size_t tlv13; tlv13 = (cgc_size_t)(cgc_strlen ( tlv23 )); }
    {int tlv41; tlv41 = (int)(cgc_strlen ( tlv23 )); }
    {char * tlv40; tlv40 = (char *)(cgc_strlen ( tlv23 )); }
    {cgc_size_t tlv39; tlv39 = (cgc_size_t)(cgc_strlen ( tlv23 )); }
    {char tlv38; tlv38 = (char)(cgc_strlen ( tlv23 )); }
    {int tlv42; tlv42 = (int)(cgc_strlen ( tlv23 )); }
    {cgc_size_t tlv65; tlv65 = (cgc_size_t)(cgc_strlen ( tlv23 )); }
    {char * tlv33; tlv33 = (char *)(cgc_strlen ( tlv23 )); }
    {void * tlv34; tlv34 = (void *)(cgc_strlen ( tlv23 )); }
    {cgc_size_t tlv66; tlv66 = (cgc_size_t)(cgc_strlen ( tlv23 )); }
    {char * tlv36; tlv36 = (char *)(cgc_strlen ( tlv23 )); }
    {void * tlv37; tlv37 = (void *)(cgc_strlen ( tlv23 )); }
    {int tlv48; tlv48 = (int)(cgc_strlen ( tlv23 )); }
    {char * tlv47; tlv47 = (char *)(cgc_strlen ( tlv23 )); }
    {cgc_size_t tlv46; tlv46 = (cgc_size_t)(cgc_strlen ( tlv23 )); }
    {char tlv45; tlv45 = (char)(cgc_strlen ( tlv23 )); }
    {int tlv53; tlv53 = (int)(cgc_strlen ( tlv23 )); }
    {char * tlv52; tlv52 = (char *)(cgc_strlen ( tlv23 )); }
    {cgc_size_t tlv51; tlv51 = (cgc_size_t)(cgc_strlen ( tlv23 )); }
    {char tlv50; tlv50 = (char)(cgc_strlen ( tlv23 )); }
    {int tlv58; tlv58 = (int)(cgc_strlen ( tlv23 )); }
    {char * tlv57; tlv57 = (char *)(cgc_strlen ( tlv23 )); }
    {cgc_size_t tlv56; tlv56 = (cgc_size_t)(cgc_strlen ( tlv23 )); }
    {char tlv55; tlv55 = (char)(cgc_strlen ( tlv23 )); }
    {int tlv63; tlv63 = (int)(cgc_strlen ( tlv23 )); }
    {char * tlv62; tlv62 = (char *)(cgc_strlen ( tlv23 )); }
    {cgc_size_t tlv61; tlv61 = (cgc_size_t)(cgc_strlen ( tlv23 )); }
    {char tlv60; tlv60 = (char)(cgc_strlen ( tlv23 )); }
    {int new_year; new_year = (int)(cgc_strlen ( tlv23 )); }
    {int new_score; new_score = (int)(cgc_strlen ( tlv23 )); }
    {unsigned int genre; genre = (unsigned int)(cgc_strlen ( tlv23 )); }
    {unsigned int rating; rating = (unsigned int)(cgc_strlen ( tlv23 )); }
    {int tlv69; tlv69 = (int)(cgc_strlen ( tlv23 )); }
    {int tlv72; tlv72 = (int)(cgc_strlen ( tlv23 )); }
    {int tlv75; tlv75 = (int)(cgc_strlen ( tlv23 )); }
    {int tlv78; tlv78 = (int)(cgc_strlen ( tlv23 )); }
}
void fix_ingred_main_9_16(){
fix_ingred_main_9_16_0();
}
void fix_ingred_main_9_17_3(){
cgc_size_t tlv2;
    bzero(&tlv2,sizeof(cgc_size_t));
    {unsigned int movie_id; movie_id = (unsigned int)(tlv2); }
    {unsigned int num_movies; num_movies = (unsigned int)(tlv2); }
    {char * new_title; new_title = (char *)(tlv2); }
    {char * new_desc; new_desc = (char *)(tlv2); }
    {char buf [ 1024 ]; buf [ ( 1024 )-1 ] = (char)(tlv2); }
    {int tlv1; tlv1 = (int)(tlv2); }
    {int tlv3; tlv3 = (int)(tlv2); }
    {cgc_size_t tlv4; tlv4 = (cgc_size_t)(tlv2); }
    {int finish; finish = (int)(tlv2); }
    {int tlv17; tlv17 = (int)(tlv2); }
    {int tlv22; tlv22 = (int)(tlv2); }
    {char * tlv21; tlv21 = (char *)(tlv2); }
    {cgc_size_t tlv20; tlv20 = (cgc_size_t)(tlv2); }
    {char tlv19; tlv19 = (char)(tlv2); }
    {int tlv27; tlv27 = (int)(tlv2); }
    {char * tlv26; tlv26 = (char *)(tlv2); }
    {cgc_size_t tlv25; tlv25 = (cgc_size_t)(tlv2); }
    {char tlv24; tlv24 = (char)(tlv2); }
    {int tlv5; tlv5 = (int)(tlv2); }
    {int tlv6; tlv6 = (int)(tlv2); }
    {cgc_size_t tlv7; tlv7 = (cgc_size_t)(tlv2); }
    {int tlv8; tlv8 = (int)(tlv2); }
    {cgc_size_t tlv9; tlv9 = (cgc_size_t)(tlv2); }
    {int tlv10; tlv10 = (int)(tlv2); }
    {cgc_size_t tlv11; tlv11 = (cgc_size_t)(tlv2); }
    {int tlv12; tlv12 = (int)(tlv2); }
    {cgc_size_t tlv13; tlv13 = (cgc_size_t)(tlv2); }
    {int tlv41; tlv41 = (int)(tlv2); }
    {char * tlv40; tlv40 = (char *)(tlv2); }
    {cgc_size_t tlv39; tlv39 = (cgc_size_t)(tlv2); }
    {char tlv38; tlv38 = (char)(tlv2); }
    {int tlv42; tlv42 = (int)(tlv2); }
    {cgc_size_t tlv65; tlv65 = (cgc_size_t)(tlv2); }
    {char * tlv33; tlv33 = (char *)(tlv2); }
    {void * tlv34; tlv34 = (void *)(tlv2); }
    {cgc_size_t tlv66; tlv66 = (cgc_size_t)(tlv2); }
    {char * tlv36; tlv36 = (char *)(tlv2); }
    {void * tlv37; tlv37 = (void *)(tlv2); }
    {int tlv48; tlv48 = (int)(tlv2); }
    {char * tlv47; tlv47 = (char *)(tlv2); }
    {cgc_size_t tlv46; tlv46 = (cgc_size_t)(tlv2); }
    {char tlv45; tlv45 = (char)(tlv2); }
    {int tlv53; tlv53 = (int)(tlv2); }
    {char * tlv52; tlv52 = (char *)(tlv2); }
    {cgc_size_t tlv51; tlv51 = (cgc_size_t)(tlv2); }
    {char tlv50; tlv50 = (char)(tlv2); }
    {int tlv58; tlv58 = (int)(tlv2); }
    {char * tlv57; tlv57 = (char *)(tlv2); }
    {cgc_size_t tlv56; tlv56 = (cgc_size_t)(tlv2); }
    {char tlv55; tlv55 = (char)(tlv2); }
    {int tlv63; tlv63 = (int)(tlv2); }
    {char * tlv62; tlv62 = (char *)(tlv2); }
    {cgc_size_t tlv61; tlv61 = (cgc_size_t)(tlv2); }
    {char tlv60; tlv60 = (char)(tlv2); }
    {int new_year; new_year = (int)(tlv2); }
    {int new_score; new_score = (int)(tlv2); }
    {unsigned int genre; genre = (unsigned int)(tlv2); }
    {unsigned int rating; rating = (unsigned int)(tlv2); }
    {int tlv69; tlv69 = (int)(tlv2); }
    {int tlv72; tlv72 = (int)(tlv2); }
    {int tlv75; tlv75 = (int)(tlv2); }
    {int tlv78; tlv78 = (int)(tlv2); }
}
void fix_ingred_main_9_17_4(){
cgc_size_t tlv2;
    bzero(&tlv2,sizeof(cgc_size_t));
    {unsigned int movie_id; movie_id = (unsigned int)(0); }
    {unsigned int num_movies; num_movies = (unsigned int)(0); }
    {char * new_title; new_title = (char *)(0); }
    {char * new_desc; new_desc = (char *)(0); }
    {char buf [ 1024 ]; buf [ ( 1024 )-1 ] = (char)(0); }
    {cgc_size_t tlv2; tlv2 = (cgc_size_t)(0); }
    {int tlv3; tlv3 = (int)(0); }
    {cgc_size_t tlv4; tlv4 = (cgc_size_t)(0); }
    {int finish; finish = (int)(0); }
    {int tlv17; tlv17 = (int)(0); }
    {int tlv22; tlv22 = (int)(0); }
    {char * tlv21; tlv21 = (char *)(0); }
    {cgc_size_t tlv20; tlv20 = (cgc_size_t)(0); }
    {char tlv19; tlv19 = (char)(0); }
    {int tlv27; tlv27 = (int)(0); }
    {char * tlv26; tlv26 = (char *)(0); }
    {cgc_size_t tlv25; tlv25 = (cgc_size_t)(0); }
    {char tlv24; tlv24 = (char)(0); }
    {int tlv6; tlv6 = (int)(0); }
    {cgc_size_t tlv7; tlv7 = (cgc_size_t)(0); }
    {int tlv8; tlv8 = (int)(0); }
    {cgc_size_t tlv9; tlv9 = (cgc_size_t)(0); }
    {int tlv10; tlv10 = (int)(0); }
    {cgc_size_t tlv11; tlv11 = (cgc_size_t)(0); }
    {int tlv12; tlv12 = (int)(0); }
    {cgc_size_t tlv13; tlv13 = (cgc_size_t)(0); }
    {int tlv41; tlv41 = (int)(0); }
    {char * tlv40; tlv40 = (char *)(0); }
    {cgc_size_t tlv39; tlv39 = (cgc_size_t)(0); }
    {char tlv38; tlv38 = (char)(0); }
    {int tlv42; tlv42 = (int)(0); }
    {cgc_size_t tlv65; tlv65 = (cgc_size_t)(0); }
    {char * tlv33; tlv33 = (char *)(0); }
    {void * tlv34; tlv34 = (void *)(0); }
    {cgc_size_t tlv66; tlv66 = (cgc_size_t)(0); }
    {char * tlv36; tlv36 = (char *)(0); }
    {void * tlv37; tlv37 = (void *)(0); }
    {int tlv48; tlv48 = (int)(0); }
    {char * tlv47; tlv47 = (char *)(0); }
    {cgc_size_t tlv46; tlv46 = (cgc_size_t)(0); }
    {char tlv45; tlv45 = (char)(0); }
    {int tlv53; tlv53 = (int)(0); }
    {char * tlv52; tlv52 = (char *)(0); }
    {cgc_size_t tlv51; tlv51 = (cgc_size_t)(0); }
    {char tlv50; tlv50 = (char)(0); }
    {int tlv58; tlv58 = (int)(0); }
    {char * tlv57; tlv57 = (char *)(0); }
    {cgc_size_t tlv56; tlv56 = (cgc_size_t)(0); }
    {char tlv55; tlv55 = (char)(0); }
    {int tlv63; tlv63 = (int)(0); }
    {char * tlv62; tlv62 = (char *)(0); }
    {cgc_size_t tlv61; tlv61 = (cgc_size_t)(0); }
    {char tlv60; tlv60 = (char)(0); }
    {int new_year; new_year = (int)(0); }
    {int new_score; new_score = (int)(0); }
    {unsigned int genre; genre = (unsigned int)(0); }
    {unsigned int rating; rating = (unsigned int)(0); }
    {int tlv69; tlv69 = (int)(0); }
    {int tlv72; tlv72 = (int)(0); }
    {int tlv75; tlv75 = (int)(0); }
    {int tlv78; tlv78 = (int)(0); }
}
void fix_ingred_main_9_17(){
fix_ingred_main_9_17_3();
fix_ingred_main_9_17_4();
}
void fix_ingred_main_9_19_0(){
char tlv83_ref;
    bzero(&tlv83_ref,1*sizeof(char));
const char * tlv83 = &tlv83_ref;
    {unsigned int movie_id; movie_id = (unsigned int)(cgc_strlen ( tlv83 ) + 1); }
    {unsigned int num_movies; num_movies = (unsigned int)(cgc_strlen ( tlv83 ) + 1); }
    {char * new_title; new_title = (char *)(cgc_strlen ( tlv83 ) + 1); }
    {char * new_desc; new_desc = (char *)(cgc_strlen ( tlv83 ) + 1); }
    {char buf [ 1024 ]; buf [ ( 1024 )-1 ] = (char)(cgc_strlen ( tlv83 ) + 1); }
    {int tlv1; tlv1 = (int)(cgc_strlen ( tlv83 ) + 1); }
    {cgc_size_t tlv2; tlv2 = (cgc_size_t)(cgc_strlen ( tlv83 ) + 1); }
    {int tlv3; tlv3 = (int)(cgc_strlen ( tlv83 ) + 1); }
    {cgc_size_t tlv4; tlv4 = (cgc_size_t)(cgc_strlen ( tlv83 ) + 1); }
    {int finish; finish = (int)(cgc_strlen ( tlv83 ) + 1); }
    {int tlv17; tlv17 = (int)(cgc_strlen ( tlv83 ) + 1); }
    {int tlv22; tlv22 = (int)(cgc_strlen ( tlv83 ) + 1); }
    {char * tlv21; tlv21 = (char *)(cgc_strlen ( tlv83 ) + 1); }
    {cgc_size_t tlv20; tlv20 = (cgc_size_t)(cgc_strlen ( tlv83 ) + 1); }
    {char tlv19; tlv19 = (char)(cgc_strlen ( tlv83 ) + 1); }
    {int tlv27; tlv27 = (int)(cgc_strlen ( tlv83 ) + 1); }
    {char * tlv26; tlv26 = (char *)(cgc_strlen ( tlv83 ) + 1); }
    {cgc_size_t tlv25; tlv25 = (cgc_size_t)(cgc_strlen ( tlv83 ) + 1); }
    {char tlv24; tlv24 = (char)(cgc_strlen ( tlv83 ) + 1); }
    {int tlv5; tlv5 = (int)(cgc_strlen ( tlv83 ) + 1); }
    {int tlv6; tlv6 = (int)(cgc_strlen ( tlv83 ) + 1); }
    {cgc_size_t tlv7; tlv7 = (cgc_size_t)(cgc_strlen ( tlv83 ) + 1); }
    {int tlv8; tlv8 = (int)(cgc_strlen ( tlv83 ) + 1); }
    {cgc_size_t tlv9; tlv9 = (cgc_size_t)(cgc_strlen ( tlv83 ) + 1); }
    {int tlv10; tlv10 = (int)(cgc_strlen ( tlv83 ) + 1); }
    {cgc_size_t tlv11; tlv11 = (cgc_size_t)(cgc_strlen ( tlv83 ) + 1); }
    {int tlv12; tlv12 = (int)(cgc_strlen ( tlv83 ) + 1); }
    {cgc_size_t tlv13; tlv13 = (cgc_size_t)(cgc_strlen ( tlv83 ) + 1); }
    {int tlv41; tlv41 = (int)(cgc_strlen ( tlv83 ) + 1); }
    {char * tlv40; tlv40 = (char *)(cgc_strlen ( tlv83 ) + 1); }
    {cgc_size_t tlv39; tlv39 = (cgc_size_t)(cgc_strlen ( tlv83 ) + 1); }
    {char tlv38; tlv38 = (char)(cgc_strlen ( tlv83 ) + 1); }
    {int tlv42; tlv42 = (int)(cgc_strlen ( tlv83 ) + 1); }
    {cgc_size_t tlv65; tlv65 = (cgc_size_t)(cgc_strlen ( tlv83 ) + 1); }
    {char * tlv33; tlv33 = (char *)(cgc_strlen ( tlv83 ) + 1); }
    {void * tlv34; tlv34 = (void *)(cgc_strlen ( tlv83 ) + 1); }
    {cgc_size_t tlv66; tlv66 = (cgc_size_t)(cgc_strlen ( tlv83 ) + 1); }
    {char * tlv36; tlv36 = (char *)(cgc_strlen ( tlv83 ) + 1); }
    {void * tlv37; tlv37 = (void *)(cgc_strlen ( tlv83 ) + 1); }
    {int tlv48; tlv48 = (int)(cgc_strlen ( tlv83 ) + 1); }
    {char * tlv47; tlv47 = (char *)(cgc_strlen ( tlv83 ) + 1); }
    {cgc_size_t tlv46; tlv46 = (cgc_size_t)(cgc_strlen ( tlv83 ) + 1); }
    {char tlv45; tlv45 = (char)(cgc_strlen ( tlv83 ) + 1); }
    {int tlv53; tlv53 = (int)(cgc_strlen ( tlv83 ) + 1); }
    {char * tlv52; tlv52 = (char *)(cgc_strlen ( tlv83 ) + 1); }
    {cgc_size_t tlv51; tlv51 = (cgc_size_t)(cgc_strlen ( tlv83 ) + 1); }
    {char tlv50; tlv50 = (char)(cgc_strlen ( tlv83 ) + 1); }
    {int tlv58; tlv58 = (int)(cgc_strlen ( tlv83 ) + 1); }
    {char * tlv57; tlv57 = (char *)(cgc_strlen ( tlv83 ) + 1); }
    {cgc_size_t tlv56; tlv56 = (cgc_size_t)(cgc_strlen ( tlv83 ) + 1); }
    {char tlv55; tlv55 = (char)(cgc_strlen ( tlv83 ) + 1); }
    {int tlv63; tlv63 = (int)(cgc_strlen ( tlv83 ) + 1); }
    {char * tlv62; tlv62 = (char *)(cgc_strlen ( tlv83 ) + 1); }
    {cgc_size_t tlv61; tlv61 = (cgc_size_t)(cgc_strlen ( tlv83 ) + 1); }
    {char tlv60; tlv60 = (char)(cgc_strlen ( tlv83 ) + 1); }
    {int new_year; new_year = (int)(cgc_strlen ( tlv83 ) + 1); }
    {int new_score; new_score = (int)(cgc_strlen ( tlv83 ) + 1); }
    {unsigned int genre; genre = (unsigned int)(cgc_strlen ( tlv83 ) + 1); }
    {unsigned int rating; rating = (unsigned int)(cgc_strlen ( tlv83 ) + 1); }
    {int tlv69; tlv69 = (int)(cgc_strlen ( tlv83 ) + 1); }
    {int tlv72; tlv72 = (int)(cgc_strlen ( tlv83 ) + 1); }
    {int tlv75; tlv75 = (int)(cgc_strlen ( tlv83 ) + 1); }
    {int tlv78; tlv78 = (int)(cgc_strlen ( tlv83 ) + 1); }
}
void fix_ingred_main_9_19(){
fix_ingred_main_9_19_0();
}
void fix_ingred_main_9_20_4(){
char new_title_ref;
    bzero(&new_title_ref,1*sizeof(char));
char * new_title = &new_title_ref;
    {unsigned int movie_id; movie_id = (unsigned int)(new_title); }
    {unsigned int num_movies; num_movies = (unsigned int)(new_title); }
    {char * new_desc; new_desc = (char *)(new_title); }
    {char buf [ 1024 ]; buf [ ( 1024 )-1 ] = (char)(new_title); }
    {int tlv1; tlv1 = (int)(new_title); }
    {cgc_size_t tlv2; tlv2 = (cgc_size_t)(new_title); }
    {int tlv3; tlv3 = (int)(new_title); }
    {cgc_size_t tlv4; tlv4 = (cgc_size_t)(new_title); }
    {int finish; finish = (int)(new_title); }
    {int tlv17; tlv17 = (int)(new_title); }
    {int tlv22; tlv22 = (int)(new_title); }
    {char * tlv21; tlv21 = (char *)(new_title); }
    {cgc_size_t tlv20; tlv20 = (cgc_size_t)(new_title); }
    {char tlv19; tlv19 = (char)(new_title); }
    {int tlv27; tlv27 = (int)(new_title); }
    {char * tlv26; tlv26 = (char *)(new_title); }
    {cgc_size_t tlv25; tlv25 = (cgc_size_t)(new_title); }
    {char tlv24; tlv24 = (char)(new_title); }
    {int tlv5; tlv5 = (int)(new_title); }
    {int tlv6; tlv6 = (int)(new_title); }
    {cgc_size_t tlv7; tlv7 = (cgc_size_t)(new_title); }
    {int tlv8; tlv8 = (int)(new_title); }
    {cgc_size_t tlv9; tlv9 = (cgc_size_t)(new_title); }
    {int tlv10; tlv10 = (int)(new_title); }
    {cgc_size_t tlv11; tlv11 = (cgc_size_t)(new_title); }
    {int tlv12; tlv12 = (int)(new_title); }
    {cgc_size_t tlv13; tlv13 = (cgc_size_t)(new_title); }
    {int tlv41; tlv41 = (int)(new_title); }
    {char * tlv40; tlv40 = (char *)(new_title); }
    {cgc_size_t tlv39; tlv39 = (cgc_size_t)(new_title); }
    {char tlv38; tlv38 = (char)(new_title); }
    {int tlv42; tlv42 = (int)(new_title); }
    {cgc_size_t tlv65; tlv65 = (cgc_size_t)(new_title); }
    {char * tlv33; tlv33 = (char *)(new_title); }
    {void * tlv34; tlv34 = (void *)(new_title); }
    {cgc_size_t tlv66; tlv66 = (cgc_size_t)(new_title); }
    {char * tlv36; tlv36 = (char *)(new_title); }
    {void * tlv37; tlv37 = (void *)(new_title); }
    {int tlv48; tlv48 = (int)(new_title); }
    {char * tlv47; tlv47 = (char *)(new_title); }
    {cgc_size_t tlv46; tlv46 = (cgc_size_t)(new_title); }
    {char tlv45; tlv45 = (char)(new_title); }
    {int tlv53; tlv53 = (int)(new_title); }
    {char * tlv52; tlv52 = (char *)(new_title); }
    {cgc_size_t tlv51; tlv51 = (cgc_size_t)(new_title); }
    {char tlv50; tlv50 = (char)(new_title); }
    {int tlv58; tlv58 = (int)(new_title); }
    {char * tlv57; tlv57 = (char *)(new_title); }
    {cgc_size_t tlv56; tlv56 = (cgc_size_t)(new_title); }
    {char tlv55; tlv55 = (char)(new_title); }
    {int tlv63; tlv63 = (int)(new_title); }
    {char * tlv62; tlv62 = (char *)(new_title); }
    {cgc_size_t tlv61; tlv61 = (cgc_size_t)(new_title); }
    {char tlv60; tlv60 = (char)(new_title); }
    {int new_year; new_year = (int)(new_title); }
    {int new_score; new_score = (int)(new_title); }
    {unsigned int genre; genre = (unsigned int)(new_title); }
    {unsigned int rating; rating = (unsigned int)(new_title); }
    {int tlv69; tlv69 = (int)(new_title); }
    {int tlv72; tlv72 = (int)(new_title); }
    {int tlv75; tlv75 = (int)(new_title); }
    {int tlv78; tlv78 = (int)(new_title); }
}
void fix_ingred_main_9_20_5(){
char new_title_ref;
    bzero(&new_title_ref,1*sizeof(char));
char * new_title = &new_title_ref;
    {unsigned int movie_id; movie_id = (unsigned int)(NULL); }
    {unsigned int num_movies; num_movies = (unsigned int)(NULL); }
    {char * new_title; new_title = (char *)(NULL); }
    {char * new_desc; new_desc = (char *)(NULL); }
    {char buf [ 1024 ]; buf [ ( 1024 )-1 ] = (char)(NULL); }
    {int tlv1; tlv1 = (int)(NULL); }
    {cgc_size_t tlv2; tlv2 = (cgc_size_t)(NULL); }
    {int tlv3; tlv3 = (int)(NULL); }
    {cgc_size_t tlv4; tlv4 = (cgc_size_t)(NULL); }
    {int finish; finish = (int)(NULL); }
    {int tlv17; tlv17 = (int)(NULL); }
    {int tlv22; tlv22 = (int)(NULL); }
    {char * tlv21; tlv21 = (char *)(NULL); }
    {cgc_size_t tlv20; tlv20 = (cgc_size_t)(NULL); }
    {char tlv19; tlv19 = (char)(NULL); }
    {int tlv27; tlv27 = (int)(NULL); }
    {char * tlv26; tlv26 = (char *)(NULL); }
    {cgc_size_t tlv25; tlv25 = (cgc_size_t)(NULL); }
    {char tlv24; tlv24 = (char)(NULL); }
    {int tlv5; tlv5 = (int)(NULL); }
    {int tlv6; tlv6 = (int)(NULL); }
    {cgc_size_t tlv7; tlv7 = (cgc_size_t)(NULL); }
    {int tlv8; tlv8 = (int)(NULL); }
    {cgc_size_t tlv9; tlv9 = (cgc_size_t)(NULL); }
    {int tlv10; tlv10 = (int)(NULL); }
    {cgc_size_t tlv11; tlv11 = (cgc_size_t)(NULL); }
    {int tlv12; tlv12 = (int)(NULL); }
    {cgc_size_t tlv13; tlv13 = (cgc_size_t)(NULL); }
    {int tlv41; tlv41 = (int)(NULL); }
    {char * tlv40; tlv40 = (char *)(NULL); }
    {cgc_size_t tlv39; tlv39 = (cgc_size_t)(NULL); }
    {char tlv38; tlv38 = (char)(NULL); }
    {int tlv42; tlv42 = (int)(NULL); }
    {cgc_size_t tlv65; tlv65 = (cgc_size_t)(NULL); }
    {char * tlv33; tlv33 = (char *)(NULL); }
    {void * tlv34; tlv34 = (void *)(NULL); }
    {cgc_size_t tlv66; tlv66 = (cgc_size_t)(NULL); }
    {char * tlv36; tlv36 = (char *)(NULL); }
    {void * tlv37; tlv37 = (void *)(NULL); }
    {int tlv48; tlv48 = (int)(NULL); }
    {char * tlv47; tlv47 = (char *)(NULL); }
    {cgc_size_t tlv46; tlv46 = (cgc_size_t)(NULL); }
    {char tlv45; tlv45 = (char)(NULL); }
    {int tlv53; tlv53 = (int)(NULL); }
    {char * tlv52; tlv52 = (char *)(NULL); }
    {cgc_size_t tlv51; tlv51 = (cgc_size_t)(NULL); }
    {char tlv50; tlv50 = (char)(NULL); }
    {int tlv58; tlv58 = (int)(NULL); }
    {char * tlv57; tlv57 = (char *)(NULL); }
    {cgc_size_t tlv56; tlv56 = (cgc_size_t)(NULL); }
    {char tlv55; tlv55 = (char)(NULL); }
    {int tlv63; tlv63 = (int)(NULL); }
    {char * tlv62; tlv62 = (char *)(NULL); }
    {cgc_size_t tlv61; tlv61 = (cgc_size_t)(NULL); }
    {char tlv60; tlv60 = (char)(NULL); }
    {int new_year; new_year = (int)(NULL); }
    {int new_score; new_score = (int)(NULL); }
    {unsigned int genre; genre = (unsigned int)(NULL); }
    {unsigned int rating; rating = (unsigned int)(NULL); }
    {int tlv69; tlv69 = (int)(NULL); }
    {int tlv72; tlv72 = (int)(NULL); }
    {int tlv75; tlv75 = (int)(NULL); }
    {int tlv78; tlv78 = (int)(NULL); }
}
void fix_ingred_main_9_20(){
fix_ingred_main_9_20_4();
fix_ingred_main_9_20_5();
}
void fix_ingred_main_9_22_0(){
movie_t movie_ref;
    bzero(&movie_ref,1*sizeof(movie_t));
movie_t * movie = &movie_ref;
    {unsigned int movie_id; movie_id = (unsigned int)(movie -> title); }
    {unsigned int num_movies; num_movies = (unsigned int)(movie -> title); }
    {char * new_title; new_title = (char *)(movie -> title); }
    {char * new_desc; new_desc = (char *)(movie -> title); }
    {cgc_size_t tlv2; tlv2 = (cgc_size_t)(movie -> title); }
    {cgc_size_t tlv4; tlv4 = (cgc_size_t)(movie -> title); }
    {int tlv17; tlv17 = (int)(movie -> title); }
    {int tlv27; tlv27 = (int)(movie -> title); }
    {char * tlv26; tlv26 = (char *)(movie -> title); }
    {char tlv24; tlv24 = (char)(movie -> title); }
    {cgc_size_t tlv7; tlv7 = (cgc_size_t)(movie -> title); }
    {int tlv8; tlv8 = (int)(movie -> title); }
    {cgc_size_t tlv9; tlv9 = (cgc_size_t)(movie -> title); }
    {int tlv10; tlv10 = (int)(movie -> title); }
    {cgc_size_t tlv11; tlv11 = (cgc_size_t)(movie -> title); }
    {int tlv12; tlv12 = (int)(movie -> title); }
    {cgc_size_t tlv13; tlv13 = (cgc_size_t)(movie -> title); }
    {int tlv41; tlv41 = (int)(movie -> title); }
    {char * tlv40; tlv40 = (char *)(movie -> title); }
    {cgc_size_t tlv39; tlv39 = (cgc_size_t)(movie -> title); }
    {char tlv38; tlv38 = (char)(movie -> title); }
    {int tlv42; tlv42 = (int)(movie -> title); }
    {cgc_size_t tlv65; tlv65 = (cgc_size_t)(movie -> title); }
    {char * tlv33; tlv33 = (char *)(movie -> title); }
    {void * tlv34; tlv34 = (void *)(movie -> title); }
    {cgc_size_t tlv66; tlv66 = (cgc_size_t)(movie -> title); }
    {char * tlv36; tlv36 = (char *)(movie -> title); }
    {void * tlv37; tlv37 = (void *)(movie -> title); }
    {int tlv48; tlv48 = (int)(movie -> title); }
    {char * tlv47; tlv47 = (char *)(movie -> title); }
    {cgc_size_t tlv46; tlv46 = (cgc_size_t)(movie -> title); }
    {char tlv45; tlv45 = (char)(movie -> title); }
    {char * tlv52; tlv52 = (char *)(movie -> title); }
    {cgc_size_t tlv51; tlv51 = (cgc_size_t)(movie -> title); }
    {char tlv50; tlv50 = (char)(movie -> title); }
    {int tlv58; tlv58 = (int)(movie -> title); }
    {char * tlv57; tlv57 = (char *)(movie -> title); }
    {cgc_size_t tlv56; tlv56 = (cgc_size_t)(movie -> title); }
    {char tlv55; tlv55 = (char)(movie -> title); }
    {int tlv63; tlv63 = (int)(movie -> title); }
    {char * tlv62; tlv62 = (char *)(movie -> title); }
    {cgc_size_t tlv61; tlv61 = (cgc_size_t)(movie -> title); }
    {char tlv60; tlv60 = (char)(movie -> title); }
    {int new_year; new_year = (int)(movie -> title); }
    {int new_score; new_score = (int)(movie -> title); }
    {int tlv69; tlv69 = (int)(movie -> title); }
    {int tlv72; tlv72 = (int)(movie -> title); }
    {int tlv75; tlv75 = (int)(movie -> title); }
    {int tlv78; tlv78 = (int)(movie -> title); }
}
void fix_ingred_main_9_22(){
fix_ingred_main_9_22_0();
}
void fix_ingred_main_9_24_2(){
int tlv3;
    bzero(&tlv3,sizeof(int));
    {unsigned int movie_id; movie_id = (unsigned int)(tlv3); }
    {unsigned int num_movies; num_movies = (unsigned int)(tlv3); }
    {char * new_title; new_title = (char *)(tlv3); }
    {char * new_desc; new_desc = (char *)(tlv3); }
    {cgc_size_t tlv2; tlv2 = (cgc_size_t)(tlv3); }
    {cgc_size_t tlv4; tlv4 = (cgc_size_t)(tlv3); }
    {int tlv17; tlv17 = (int)(tlv3); }
    {int tlv27; tlv27 = (int)(tlv3); }
    {char * tlv26; tlv26 = (char *)(tlv3); }
    {char tlv24; tlv24 = (char)(tlv3); }
    {cgc_size_t tlv7; tlv7 = (cgc_size_t)(tlv3); }
    {int tlv8; tlv8 = (int)(tlv3); }
    {cgc_size_t tlv9; tlv9 = (cgc_size_t)(tlv3); }
    {int tlv10; tlv10 = (int)(tlv3); }
    {cgc_size_t tlv11; tlv11 = (cgc_size_t)(tlv3); }
    {int tlv12; tlv12 = (int)(tlv3); }
    {cgc_size_t tlv13; tlv13 = (cgc_size_t)(tlv3); }
    {int tlv41; tlv41 = (int)(tlv3); }
    {char * tlv40; tlv40 = (char *)(tlv3); }
    {cgc_size_t tlv39; tlv39 = (cgc_size_t)(tlv3); }
    {char tlv38; tlv38 = (char)(tlv3); }
    {int tlv42; tlv42 = (int)(tlv3); }
    {cgc_size_t tlv65; tlv65 = (cgc_size_t)(tlv3); }
    {char * tlv33; tlv33 = (char *)(tlv3); }
    {void * tlv34; tlv34 = (void *)(tlv3); }
    {cgc_size_t tlv66; tlv66 = (cgc_size_t)(tlv3); }
    {char * tlv36; tlv36 = (char *)(tlv3); }
    {void * tlv37; tlv37 = (void *)(tlv3); }
    {int tlv48; tlv48 = (int)(tlv3); }
    {char * tlv47; tlv47 = (char *)(tlv3); }
    {cgc_size_t tlv46; tlv46 = (cgc_size_t)(tlv3); }
    {char tlv45; tlv45 = (char)(tlv3); }
    {char * tlv52; tlv52 = (char *)(tlv3); }
    {cgc_size_t tlv51; tlv51 = (cgc_size_t)(tlv3); }
    {char tlv50; tlv50 = (char)(tlv3); }
    {int tlv58; tlv58 = (int)(tlv3); }
    {char * tlv57; tlv57 = (char *)(tlv3); }
    {cgc_size_t tlv56; tlv56 = (cgc_size_t)(tlv3); }
    {char tlv55; tlv55 = (char)(tlv3); }
    {int tlv63; tlv63 = (int)(tlv3); }
    {char * tlv62; tlv62 = (char *)(tlv3); }
    {cgc_size_t tlv61; tlv61 = (cgc_size_t)(tlv3); }
    {char tlv60; tlv60 = (char)(tlv3); }
    {int new_year; new_year = (int)(tlv3); }
    {int new_score; new_score = (int)(tlv3); }
    {int tlv69; tlv69 = (int)(tlv3); }
    {int tlv72; tlv72 = (int)(tlv3); }
    {int tlv75; tlv75 = (int)(tlv3); }
    {int tlv78; tlv78 = (int)(tlv3); }
}
void fix_ingred_main_9_24(){
fix_ingred_main_9_24_2();
}
void fix_ingred_main_9_25_0(){
char tlv28_ref;
    bzero(&tlv28_ref,1*sizeof(char));
const char * tlv28 = &tlv28_ref;
    {unsigned int movie_id; movie_id = (unsigned int)(cgc_strlen ( tlv28 )); }
    {unsigned int num_movies; num_movies = (unsigned int)(cgc_strlen ( tlv28 )); }
    {char * new_title; new_title = (char *)(cgc_strlen ( tlv28 )); }
    {char * new_desc; new_desc = (char *)(cgc_strlen ( tlv28 )); }
    {char buf [ 1024 ]; buf [ ( 1024 )-1 ] = (char)(cgc_strlen ( tlv28 )); }
    {int tlv1; tlv1 = (int)(cgc_strlen ( tlv28 )); }
    {cgc_size_t tlv2; tlv2 = (cgc_size_t)(cgc_strlen ( tlv28 )); }
    {int tlv3; tlv3 = (int)(cgc_strlen ( tlv28 )); }
    {cgc_size_t tlv4; tlv4 = (cgc_size_t)(cgc_strlen ( tlv28 )); }
    {int finish; finish = (int)(cgc_strlen ( tlv28 )); }
    {int tlv17; tlv17 = (int)(cgc_strlen ( tlv28 )); }
    {int tlv22; tlv22 = (int)(cgc_strlen ( tlv28 )); }
    {char * tlv21; tlv21 = (char *)(cgc_strlen ( tlv28 )); }
    {cgc_size_t tlv20; tlv20 = (cgc_size_t)(cgc_strlen ( tlv28 )); }
    {char tlv19; tlv19 = (char)(cgc_strlen ( tlv28 )); }
    {int tlv27; tlv27 = (int)(cgc_strlen ( tlv28 )); }
    {char * tlv26; tlv26 = (char *)(cgc_strlen ( tlv28 )); }
    {cgc_size_t tlv25; tlv25 = (cgc_size_t)(cgc_strlen ( tlv28 )); }
    {char tlv24; tlv24 = (char)(cgc_strlen ( tlv28 )); }
    {int tlv5; tlv5 = (int)(cgc_strlen ( tlv28 )); }
    {int tlv6; tlv6 = (int)(cgc_strlen ( tlv28 )); }
    {cgc_size_t tlv7; tlv7 = (cgc_size_t)(cgc_strlen ( tlv28 )); }
    {int tlv8; tlv8 = (int)(cgc_strlen ( tlv28 )); }
    {cgc_size_t tlv9; tlv9 = (cgc_size_t)(cgc_strlen ( tlv28 )); }
    {int tlv10; tlv10 = (int)(cgc_strlen ( tlv28 )); }
    {cgc_size_t tlv11; tlv11 = (cgc_size_t)(cgc_strlen ( tlv28 )); }
    {int tlv12; tlv12 = (int)(cgc_strlen ( tlv28 )); }
    {cgc_size_t tlv13; tlv13 = (cgc_size_t)(cgc_strlen ( tlv28 )); }
    {int tlv41; tlv41 = (int)(cgc_strlen ( tlv28 )); }
    {char * tlv40; tlv40 = (char *)(cgc_strlen ( tlv28 )); }
    {cgc_size_t tlv39; tlv39 = (cgc_size_t)(cgc_strlen ( tlv28 )); }
    {char tlv38; tlv38 = (char)(cgc_strlen ( tlv28 )); }
    {int tlv42; tlv42 = (int)(cgc_strlen ( tlv28 )); }
    {cgc_size_t tlv65; tlv65 = (cgc_size_t)(cgc_strlen ( tlv28 )); }
    {char * tlv33; tlv33 = (char *)(cgc_strlen ( tlv28 )); }
    {void * tlv34; tlv34 = (void *)(cgc_strlen ( tlv28 )); }
    {cgc_size_t tlv66; tlv66 = (cgc_size_t)(cgc_strlen ( tlv28 )); }
    {char * tlv36; tlv36 = (char *)(cgc_strlen ( tlv28 )); }
    {void * tlv37; tlv37 = (void *)(cgc_strlen ( tlv28 )); }
    {int tlv48; tlv48 = (int)(cgc_strlen ( tlv28 )); }
    {char * tlv47; tlv47 = (char *)(cgc_strlen ( tlv28 )); }
    {cgc_size_t tlv46; tlv46 = (cgc_size_t)(cgc_strlen ( tlv28 )); }
    {char tlv45; tlv45 = (char)(cgc_strlen ( tlv28 )); }
    {int tlv53; tlv53 = (int)(cgc_strlen ( tlv28 )); }
    {char * tlv52; tlv52 = (char *)(cgc_strlen ( tlv28 )); }
    {cgc_size_t tlv51; tlv51 = (cgc_size_t)(cgc_strlen ( tlv28 )); }
    {char tlv50; tlv50 = (char)(cgc_strlen ( tlv28 )); }
    {int tlv58; tlv58 = (int)(cgc_strlen ( tlv28 )); }
    {char * tlv57; tlv57 = (char *)(cgc_strlen ( tlv28 )); }
    {cgc_size_t tlv56; tlv56 = (cgc_size_t)(cgc_strlen ( tlv28 )); }
    {char tlv55; tlv55 = (char)(cgc_strlen ( tlv28 )); }
    {int tlv63; tlv63 = (int)(cgc_strlen ( tlv28 )); }
    {char * tlv62; tlv62 = (char *)(cgc_strlen ( tlv28 )); }
    {cgc_size_t tlv61; tlv61 = (cgc_size_t)(cgc_strlen ( tlv28 )); }
    {char tlv60; tlv60 = (char)(cgc_strlen ( tlv28 )); }
    {int new_year; new_year = (int)(cgc_strlen ( tlv28 )); }
    {int new_score; new_score = (int)(cgc_strlen ( tlv28 )); }
    {unsigned int genre; genre = (unsigned int)(cgc_strlen ( tlv28 )); }
    {unsigned int rating; rating = (unsigned int)(cgc_strlen ( tlv28 )); }
    {int tlv69; tlv69 = (int)(cgc_strlen ( tlv28 )); }
    {int tlv72; tlv72 = (int)(cgc_strlen ( tlv28 )); }
    {int tlv75; tlv75 = (int)(cgc_strlen ( tlv28 )); }
    {int tlv78; tlv78 = (int)(cgc_strlen ( tlv28 )); }
}
void fix_ingred_main_9_25(){
fix_ingred_main_9_25_0();
}
void fix_ingred_main_9_26_3(){
cgc_size_t tlv4;
    bzero(&tlv4,sizeof(cgc_size_t));
    {unsigned int movie_id; movie_id = (unsigned int)(tlv4); }
    {unsigned int num_movies; num_movies = (unsigned int)(tlv4); }
    {char * new_title; new_title = (char *)(tlv4); }
    {char * new_desc; new_desc = (char *)(tlv4); }
    {char buf [ 1024 ]; buf [ ( 1024 )-1 ] = (char)(tlv4); }
    {int tlv1; tlv1 = (int)(tlv4); }
    {cgc_size_t tlv2; tlv2 = (cgc_size_t)(tlv4); }
    {int tlv3; tlv3 = (int)(tlv4); }
    {int finish; finish = (int)(tlv4); }
    {int tlv17; tlv17 = (int)(tlv4); }
    {int tlv22; tlv22 = (int)(tlv4); }
    {char * tlv21; tlv21 = (char *)(tlv4); }
    {cgc_size_t tlv20; tlv20 = (cgc_size_t)(tlv4); }
    {char tlv19; tlv19 = (char)(tlv4); }
    {int tlv27; tlv27 = (int)(tlv4); }
    {char * tlv26; tlv26 = (char *)(tlv4); }
    {cgc_size_t tlv25; tlv25 = (cgc_size_t)(tlv4); }
    {char tlv24; tlv24 = (char)(tlv4); }
    {int tlv5; tlv5 = (int)(tlv4); }
    {int tlv6; tlv6 = (int)(tlv4); }
    {cgc_size_t tlv7; tlv7 = (cgc_size_t)(tlv4); }
    {int tlv8; tlv8 = (int)(tlv4); }
    {cgc_size_t tlv9; tlv9 = (cgc_size_t)(tlv4); }
    {int tlv10; tlv10 = (int)(tlv4); }
    {cgc_size_t tlv11; tlv11 = (cgc_size_t)(tlv4); }
    {int tlv12; tlv12 = (int)(tlv4); }
    {cgc_size_t tlv13; tlv13 = (cgc_size_t)(tlv4); }
    {int tlv41; tlv41 = (int)(tlv4); }
    {char * tlv40; tlv40 = (char *)(tlv4); }
    {cgc_size_t tlv39; tlv39 = (cgc_size_t)(tlv4); }
    {char tlv38; tlv38 = (char)(tlv4); }
    {int tlv42; tlv42 = (int)(tlv4); }
    {cgc_size_t tlv65; tlv65 = (cgc_size_t)(tlv4); }
    {char * tlv33; tlv33 = (char *)(tlv4); }
    {void * tlv34; tlv34 = (void *)(tlv4); }
    {cgc_size_t tlv66; tlv66 = (cgc_size_t)(tlv4); }
    {char * tlv36; tlv36 = (char *)(tlv4); }
    {void * tlv37; tlv37 = (void *)(tlv4); }
    {int tlv48; tlv48 = (int)(tlv4); }
    {char * tlv47; tlv47 = (char *)(tlv4); }
    {cgc_size_t tlv46; tlv46 = (cgc_size_t)(tlv4); }
    {char tlv45; tlv45 = (char)(tlv4); }
    {int tlv53; tlv53 = (int)(tlv4); }
    {char * tlv52; tlv52 = (char *)(tlv4); }
    {cgc_size_t tlv51; tlv51 = (cgc_size_t)(tlv4); }
    {char tlv50; tlv50 = (char)(tlv4); }
    {int tlv58; tlv58 = (int)(tlv4); }
    {char * tlv57; tlv57 = (char *)(tlv4); }
    {cgc_size_t tlv56; tlv56 = (cgc_size_t)(tlv4); }
    {char tlv55; tlv55 = (char)(tlv4); }
    {int tlv63; tlv63 = (int)(tlv4); }
    {char * tlv62; tlv62 = (char *)(tlv4); }
    {cgc_size_t tlv61; tlv61 = (cgc_size_t)(tlv4); }
    {char tlv60; tlv60 = (char)(tlv4); }
    {int new_year; new_year = (int)(tlv4); }
    {int new_score; new_score = (int)(tlv4); }
    {unsigned int genre; genre = (unsigned int)(tlv4); }
    {unsigned int rating; rating = (unsigned int)(tlv4); }
    {int tlv69; tlv69 = (int)(tlv4); }
    {int tlv72; tlv72 = (int)(tlv4); }
    {int tlv75; tlv75 = (int)(tlv4); }
    {int tlv78; tlv78 = (int)(tlv4); }
}
void fix_ingred_main_9_26(){
fix_ingred_main_9_26_3();
}
void fix_ingred_main_9_28_0(){
char tlv84_ref;
    bzero(&tlv84_ref,1*sizeof(char));
const char * tlv84 = &tlv84_ref;
    {unsigned int movie_id; movie_id = (unsigned int)(cgc_strlen ( tlv84 ) + 1); }
    {unsigned int num_movies; num_movies = (unsigned int)(cgc_strlen ( tlv84 ) + 1); }
    {char * new_title; new_title = (char *)(cgc_strlen ( tlv84 ) + 1); }
    {char * new_desc; new_desc = (char *)(cgc_strlen ( tlv84 ) + 1); }
    {char buf [ 1024 ]; buf [ ( 1024 )-1 ] = (char)(cgc_strlen ( tlv84 ) + 1); }
    {int tlv1; tlv1 = (int)(cgc_strlen ( tlv84 ) + 1); }
    {cgc_size_t tlv2; tlv2 = (cgc_size_t)(cgc_strlen ( tlv84 ) + 1); }
    {int tlv3; tlv3 = (int)(cgc_strlen ( tlv84 ) + 1); }
    {cgc_size_t tlv4; tlv4 = (cgc_size_t)(cgc_strlen ( tlv84 ) + 1); }
    {int finish; finish = (int)(cgc_strlen ( tlv84 ) + 1); }
    {int tlv17; tlv17 = (int)(cgc_strlen ( tlv84 ) + 1); }
    {int tlv22; tlv22 = (int)(cgc_strlen ( tlv84 ) + 1); }
    {char * tlv21; tlv21 = (char *)(cgc_strlen ( tlv84 ) + 1); }
    {cgc_size_t tlv20; tlv20 = (cgc_size_t)(cgc_strlen ( tlv84 ) + 1); }
    {char tlv19; tlv19 = (char)(cgc_strlen ( tlv84 ) + 1); }
    {int tlv27; tlv27 = (int)(cgc_strlen ( tlv84 ) + 1); }
    {char * tlv26; tlv26 = (char *)(cgc_strlen ( tlv84 ) + 1); }
    {cgc_size_t tlv25; tlv25 = (cgc_size_t)(cgc_strlen ( tlv84 ) + 1); }
    {char tlv24; tlv24 = (char)(cgc_strlen ( tlv84 ) + 1); }
    {int tlv5; tlv5 = (int)(cgc_strlen ( tlv84 ) + 1); }
    {int tlv6; tlv6 = (int)(cgc_strlen ( tlv84 ) + 1); }
    {cgc_size_t tlv7; tlv7 = (cgc_size_t)(cgc_strlen ( tlv84 ) + 1); }
    {int tlv8; tlv8 = (int)(cgc_strlen ( tlv84 ) + 1); }
    {cgc_size_t tlv9; tlv9 = (cgc_size_t)(cgc_strlen ( tlv84 ) + 1); }
    {int tlv10; tlv10 = (int)(cgc_strlen ( tlv84 ) + 1); }
    {cgc_size_t tlv11; tlv11 = (cgc_size_t)(cgc_strlen ( tlv84 ) + 1); }
    {int tlv12; tlv12 = (int)(cgc_strlen ( tlv84 ) + 1); }
    {cgc_size_t tlv13; tlv13 = (cgc_size_t)(cgc_strlen ( tlv84 ) + 1); }
    {int tlv41; tlv41 = (int)(cgc_strlen ( tlv84 ) + 1); }
    {char * tlv40; tlv40 = (char *)(cgc_strlen ( tlv84 ) + 1); }
    {cgc_size_t tlv39; tlv39 = (cgc_size_t)(cgc_strlen ( tlv84 ) + 1); }
    {char tlv38; tlv38 = (char)(cgc_strlen ( tlv84 ) + 1); }
    {int tlv42; tlv42 = (int)(cgc_strlen ( tlv84 ) + 1); }
    {cgc_size_t tlv65; tlv65 = (cgc_size_t)(cgc_strlen ( tlv84 ) + 1); }
    {char * tlv33; tlv33 = (char *)(cgc_strlen ( tlv84 ) + 1); }
    {void * tlv34; tlv34 = (void *)(cgc_strlen ( tlv84 ) + 1); }
    {cgc_size_t tlv66; tlv66 = (cgc_size_t)(cgc_strlen ( tlv84 ) + 1); }
    {char * tlv36; tlv36 = (char *)(cgc_strlen ( tlv84 ) + 1); }
    {void * tlv37; tlv37 = (void *)(cgc_strlen ( tlv84 ) + 1); }
    {int tlv48; tlv48 = (int)(cgc_strlen ( tlv84 ) + 1); }
    {char * tlv47; tlv47 = (char *)(cgc_strlen ( tlv84 ) + 1); }
    {cgc_size_t tlv46; tlv46 = (cgc_size_t)(cgc_strlen ( tlv84 ) + 1); }
    {char tlv45; tlv45 = (char)(cgc_strlen ( tlv84 ) + 1); }
    {int tlv53; tlv53 = (int)(cgc_strlen ( tlv84 ) + 1); }
    {char * tlv52; tlv52 = (char *)(cgc_strlen ( tlv84 ) + 1); }
    {cgc_size_t tlv51; tlv51 = (cgc_size_t)(cgc_strlen ( tlv84 ) + 1); }
    {char tlv50; tlv50 = (char)(cgc_strlen ( tlv84 ) + 1); }
    {int tlv58; tlv58 = (int)(cgc_strlen ( tlv84 ) + 1); }
    {char * tlv57; tlv57 = (char *)(cgc_strlen ( tlv84 ) + 1); }
    {cgc_size_t tlv56; tlv56 = (cgc_size_t)(cgc_strlen ( tlv84 ) + 1); }
    {char tlv55; tlv55 = (char)(cgc_strlen ( tlv84 ) + 1); }
    {int tlv63; tlv63 = (int)(cgc_strlen ( tlv84 ) + 1); }
    {char * tlv62; tlv62 = (char *)(cgc_strlen ( tlv84 ) + 1); }
    {cgc_size_t tlv61; tlv61 = (cgc_size_t)(cgc_strlen ( tlv84 ) + 1); }
    {char tlv60; tlv60 = (char)(cgc_strlen ( tlv84 ) + 1); }
    {int new_year; new_year = (int)(cgc_strlen ( tlv84 ) + 1); }
    {int new_score; new_score = (int)(cgc_strlen ( tlv84 ) + 1); }
    {unsigned int genre; genre = (unsigned int)(cgc_strlen ( tlv84 ) + 1); }
    {unsigned int rating; rating = (unsigned int)(cgc_strlen ( tlv84 ) + 1); }
    {int tlv69; tlv69 = (int)(cgc_strlen ( tlv84 ) + 1); }
    {int tlv72; tlv72 = (int)(cgc_strlen ( tlv84 ) + 1); }
    {int tlv75; tlv75 = (int)(cgc_strlen ( tlv84 ) + 1); }
    {int tlv78; tlv78 = (int)(cgc_strlen ( tlv84 ) + 1); }
}
void fix_ingred_main_9_28(){
fix_ingred_main_9_28_0();
}
void fix_ingred_main_9_29_4(){
char new_desc_ref;
    bzero(&new_desc_ref,1*sizeof(char));
char * new_desc = &new_desc_ref;
    {unsigned int movie_id; movie_id = (unsigned int)(new_desc); }
    {unsigned int num_movies; num_movies = (unsigned int)(new_desc); }
    {char * new_title; new_title = (char *)(new_desc); }
    {char buf [ 1024 ]; buf [ ( 1024 )-1 ] = (char)(new_desc); }
    {int tlv1; tlv1 = (int)(new_desc); }
    {cgc_size_t tlv2; tlv2 = (cgc_size_t)(new_desc); }
    {int tlv3; tlv3 = (int)(new_desc); }
    {cgc_size_t tlv4; tlv4 = (cgc_size_t)(new_desc); }
    {int finish; finish = (int)(new_desc); }
    {int tlv17; tlv17 = (int)(new_desc); }
    {int tlv22; tlv22 = (int)(new_desc); }
    {char * tlv21; tlv21 = (char *)(new_desc); }
    {cgc_size_t tlv20; tlv20 = (cgc_size_t)(new_desc); }
    {char tlv19; tlv19 = (char)(new_desc); }
    {int tlv27; tlv27 = (int)(new_desc); }
    {char * tlv26; tlv26 = (char *)(new_desc); }
    {cgc_size_t tlv25; tlv25 = (cgc_size_t)(new_desc); }
    {char tlv24; tlv24 = (char)(new_desc); }
    {int tlv5; tlv5 = (int)(new_desc); }
    {int tlv6; tlv6 = (int)(new_desc); }
    {cgc_size_t tlv7; tlv7 = (cgc_size_t)(new_desc); }
    {int tlv8; tlv8 = (int)(new_desc); }
    {cgc_size_t tlv9; tlv9 = (cgc_size_t)(new_desc); }
    {int tlv10; tlv10 = (int)(new_desc); }
    {cgc_size_t tlv11; tlv11 = (cgc_size_t)(new_desc); }
    {int tlv12; tlv12 = (int)(new_desc); }
    {cgc_size_t tlv13; tlv13 = (cgc_size_t)(new_desc); }
    {int tlv41; tlv41 = (int)(new_desc); }
    {char * tlv40; tlv40 = (char *)(new_desc); }
    {cgc_size_t tlv39; tlv39 = (cgc_size_t)(new_desc); }
    {char tlv38; tlv38 = (char)(new_desc); }
    {int tlv42; tlv42 = (int)(new_desc); }
    {cgc_size_t tlv65; tlv65 = (cgc_size_t)(new_desc); }
    {char * tlv33; tlv33 = (char *)(new_desc); }
    {void * tlv34; tlv34 = (void *)(new_desc); }
    {cgc_size_t tlv66; tlv66 = (cgc_size_t)(new_desc); }
    {char * tlv36; tlv36 = (char *)(new_desc); }
    {void * tlv37; tlv37 = (void *)(new_desc); }
    {int tlv48; tlv48 = (int)(new_desc); }
    {char * tlv47; tlv47 = (char *)(new_desc); }
    {cgc_size_t tlv46; tlv46 = (cgc_size_t)(new_desc); }
    {char tlv45; tlv45 = (char)(new_desc); }
    {int tlv53; tlv53 = (int)(new_desc); }
    {char * tlv52; tlv52 = (char *)(new_desc); }
    {cgc_size_t tlv51; tlv51 = (cgc_size_t)(new_desc); }
    {char tlv50; tlv50 = (char)(new_desc); }
    {int tlv58; tlv58 = (int)(new_desc); }
    {char * tlv57; tlv57 = (char *)(new_desc); }
    {cgc_size_t tlv56; tlv56 = (cgc_size_t)(new_desc); }
    {char tlv55; tlv55 = (char)(new_desc); }
    {int tlv63; tlv63 = (int)(new_desc); }
    {char * tlv62; tlv62 = (char *)(new_desc); }
    {cgc_size_t tlv61; tlv61 = (cgc_size_t)(new_desc); }
    {char tlv60; tlv60 = (char)(new_desc); }
    {int new_year; new_year = (int)(new_desc); }
    {int new_score; new_score = (int)(new_desc); }
    {unsigned int genre; genre = (unsigned int)(new_desc); }
    {unsigned int rating; rating = (unsigned int)(new_desc); }
    {int tlv69; tlv69 = (int)(new_desc); }
    {int tlv72; tlv72 = (int)(new_desc); }
    {int tlv75; tlv75 = (int)(new_desc); }
    {int tlv78; tlv78 = (int)(new_desc); }
}
void fix_ingred_main_9_29(){
fix_ingred_main_9_29_4();
}
void fix_ingred_main_9_31_0(){
movie_t movie_ref;
    bzero(&movie_ref,1*sizeof(movie_t));
movie_t * movie = &movie_ref;
    {unsigned int movie_id; movie_id = (unsigned int)(movie -> desc); }
    {unsigned int num_movies; num_movies = (unsigned int)(movie -> desc); }
    {char * new_title; new_title = (char *)(movie -> desc); }
    {char * new_desc; new_desc = (char *)(movie -> desc); }
    {cgc_size_t tlv2; tlv2 = (cgc_size_t)(movie -> desc); }
    {cgc_size_t tlv4; tlv4 = (cgc_size_t)(movie -> desc); }
    {int tlv17; tlv17 = (int)(movie -> desc); }
    {int tlv27; tlv27 = (int)(movie -> desc); }
    {char * tlv26; tlv26 = (char *)(movie -> desc); }
    {char tlv24; tlv24 = (char)(movie -> desc); }
    {cgc_size_t tlv7; tlv7 = (cgc_size_t)(movie -> desc); }
    {int tlv8; tlv8 = (int)(movie -> desc); }
    {cgc_size_t tlv9; tlv9 = (cgc_size_t)(movie -> desc); }
    {int tlv10; tlv10 = (int)(movie -> desc); }
    {cgc_size_t tlv11; tlv11 = (cgc_size_t)(movie -> desc); }
    {int tlv12; tlv12 = (int)(movie -> desc); }
    {cgc_size_t tlv13; tlv13 = (cgc_size_t)(movie -> desc); }
    {int tlv41; tlv41 = (int)(movie -> desc); }
    {char * tlv40; tlv40 = (char *)(movie -> desc); }
    {cgc_size_t tlv39; tlv39 = (cgc_size_t)(movie -> desc); }
    {char tlv38; tlv38 = (char)(movie -> desc); }
    {int tlv42; tlv42 = (int)(movie -> desc); }
    {cgc_size_t tlv65; tlv65 = (cgc_size_t)(movie -> desc); }
    {char * tlv33; tlv33 = (char *)(movie -> desc); }
    {void * tlv34; tlv34 = (void *)(movie -> desc); }
    {cgc_size_t tlv66; tlv66 = (cgc_size_t)(movie -> desc); }
    {char * tlv36; tlv36 = (char *)(movie -> desc); }
    {void * tlv37; tlv37 = (void *)(movie -> desc); }
    {int tlv48; tlv48 = (int)(movie -> desc); }
    {char * tlv47; tlv47 = (char *)(movie -> desc); }
    {cgc_size_t tlv46; tlv46 = (cgc_size_t)(movie -> desc); }
    {char tlv45; tlv45 = (char)(movie -> desc); }
    {char * tlv52; tlv52 = (char *)(movie -> desc); }
    {cgc_size_t tlv51; tlv51 = (cgc_size_t)(movie -> desc); }
    {char tlv50; tlv50 = (char)(movie -> desc); }
    {int tlv58; tlv58 = (int)(movie -> desc); }
    {char * tlv57; tlv57 = (char *)(movie -> desc); }
    {cgc_size_t tlv56; tlv56 = (cgc_size_t)(movie -> desc); }
    {char tlv55; tlv55 = (char)(movie -> desc); }
    {int tlv63; tlv63 = (int)(movie -> desc); }
    {char * tlv62; tlv62 = (char *)(movie -> desc); }
    {cgc_size_t tlv61; tlv61 = (cgc_size_t)(movie -> desc); }
    {char tlv60; tlv60 = (char)(movie -> desc); }
    {int new_year; new_year = (int)(movie -> desc); }
    {int new_score; new_score = (int)(movie -> desc); }
    {int tlv69; tlv69 = (int)(movie -> desc); }
    {int tlv72; tlv72 = (int)(movie -> desc); }
    {int tlv75; tlv75 = (int)(movie -> desc); }
    {int tlv78; tlv78 = (int)(movie -> desc); }
}
void fix_ingred_main_9_31(){
fix_ingred_main_9_31_0();
}
void fix_ingred_main_9_34_2(){
int tlv6;
    bzero(&tlv6,sizeof(int));
    {unsigned int movie_id; movie_id = (unsigned int)(tlv6); }
    {unsigned int num_movies; num_movies = (unsigned int)(tlv6); }
    {char * new_title; new_title = (char *)(tlv6); }
    {char * new_desc; new_desc = (char *)(tlv6); }
    {cgc_size_t tlv2; tlv2 = (cgc_size_t)(tlv6); }
    {cgc_size_t tlv4; tlv4 = (cgc_size_t)(tlv6); }
    {int tlv17; tlv17 = (int)(tlv6); }
    {int tlv27; tlv27 = (int)(tlv6); }
    {char * tlv26; tlv26 = (char *)(tlv6); }
    {char tlv24; tlv24 = (char)(tlv6); }
    {cgc_size_t tlv7; tlv7 = (cgc_size_t)(tlv6); }
    {int tlv8; tlv8 = (int)(tlv6); }
    {cgc_size_t tlv9; tlv9 = (cgc_size_t)(tlv6); }
    {int tlv10; tlv10 = (int)(tlv6); }
    {cgc_size_t tlv11; tlv11 = (cgc_size_t)(tlv6); }
    {int tlv12; tlv12 = (int)(tlv6); }
    {cgc_size_t tlv13; tlv13 = (cgc_size_t)(tlv6); }
    {int tlv41; tlv41 = (int)(tlv6); }
    {char * tlv40; tlv40 = (char *)(tlv6); }
    {cgc_size_t tlv39; tlv39 = (cgc_size_t)(tlv6); }
    {char tlv38; tlv38 = (char)(tlv6); }
    {int tlv42; tlv42 = (int)(tlv6); }
    {cgc_size_t tlv65; tlv65 = (cgc_size_t)(tlv6); }
    {char * tlv33; tlv33 = (char *)(tlv6); }
    {void * tlv34; tlv34 = (void *)(tlv6); }
    {cgc_size_t tlv66; tlv66 = (cgc_size_t)(tlv6); }
    {char * tlv36; tlv36 = (char *)(tlv6); }
    {void * tlv37; tlv37 = (void *)(tlv6); }
    {int tlv48; tlv48 = (int)(tlv6); }
    {char * tlv47; tlv47 = (char *)(tlv6); }
    {cgc_size_t tlv46; tlv46 = (cgc_size_t)(tlv6); }
    {char tlv45; tlv45 = (char)(tlv6); }
    {char * tlv52; tlv52 = (char *)(tlv6); }
    {cgc_size_t tlv51; tlv51 = (cgc_size_t)(tlv6); }
    {char tlv50; tlv50 = (char)(tlv6); }
    {int tlv58; tlv58 = (int)(tlv6); }
    {char * tlv57; tlv57 = (char *)(tlv6); }
    {cgc_size_t tlv56; tlv56 = (cgc_size_t)(tlv6); }
    {char tlv55; tlv55 = (char)(tlv6); }
    {int tlv63; tlv63 = (int)(tlv6); }
    {char * tlv62; tlv62 = (char *)(tlv6); }
    {cgc_size_t tlv61; tlv61 = (cgc_size_t)(tlv6); }
    {char tlv60; tlv60 = (char)(tlv6); }
    {int new_year; new_year = (int)(tlv6); }
    {int new_score; new_score = (int)(tlv6); }
    {int tlv69; tlv69 = (int)(tlv6); }
    {int tlv72; tlv72 = (int)(tlv6); }
    {int tlv75; tlv75 = (int)(tlv6); }
    {int tlv78; tlv78 = (int)(tlv6); }
}
void fix_ingred_main_9_34(){
fix_ingred_main_9_34_2();
}
void fix_ingred_main_9_35_0(){
char tlv49_ref;
    bzero(&tlv49_ref,1*sizeof(char));
const char * tlv49 = &tlv49_ref;
    {unsigned int movie_id; movie_id = (unsigned int)(cgc_strlen ( tlv49 )); }
    {unsigned int num_movies; num_movies = (unsigned int)(cgc_strlen ( tlv49 )); }
    {char * new_title; new_title = (char *)(cgc_strlen ( tlv49 )); }
    {char * new_desc; new_desc = (char *)(cgc_strlen ( tlv49 )); }
    {char buf [ 1024 ]; buf [ ( 1024 )-1 ] = (char)(cgc_strlen ( tlv49 )); }
    {int tlv1; tlv1 = (int)(cgc_strlen ( tlv49 )); }
    {cgc_size_t tlv2; tlv2 = (cgc_size_t)(cgc_strlen ( tlv49 )); }
    {int tlv3; tlv3 = (int)(cgc_strlen ( tlv49 )); }
    {cgc_size_t tlv4; tlv4 = (cgc_size_t)(cgc_strlen ( tlv49 )); }
    {int finish; finish = (int)(cgc_strlen ( tlv49 )); }
    {int tlv17; tlv17 = (int)(cgc_strlen ( tlv49 )); }
    {int tlv22; tlv22 = (int)(cgc_strlen ( tlv49 )); }
    {char * tlv21; tlv21 = (char *)(cgc_strlen ( tlv49 )); }
    {cgc_size_t tlv20; tlv20 = (cgc_size_t)(cgc_strlen ( tlv49 )); }
    {char tlv19; tlv19 = (char)(cgc_strlen ( tlv49 )); }
    {int tlv27; tlv27 = (int)(cgc_strlen ( tlv49 )); }
    {char * tlv26; tlv26 = (char *)(cgc_strlen ( tlv49 )); }
    {cgc_size_t tlv25; tlv25 = (cgc_size_t)(cgc_strlen ( tlv49 )); }
    {char tlv24; tlv24 = (char)(cgc_strlen ( tlv49 )); }
    {int tlv5; tlv5 = (int)(cgc_strlen ( tlv49 )); }
    {int tlv6; tlv6 = (int)(cgc_strlen ( tlv49 )); }
    {cgc_size_t tlv7; tlv7 = (cgc_size_t)(cgc_strlen ( tlv49 )); }
    {int tlv8; tlv8 = (int)(cgc_strlen ( tlv49 )); }
    {cgc_size_t tlv9; tlv9 = (cgc_size_t)(cgc_strlen ( tlv49 )); }
    {int tlv10; tlv10 = (int)(cgc_strlen ( tlv49 )); }
    {cgc_size_t tlv11; tlv11 = (cgc_size_t)(cgc_strlen ( tlv49 )); }
    {int tlv12; tlv12 = (int)(cgc_strlen ( tlv49 )); }
    {cgc_size_t tlv13; tlv13 = (cgc_size_t)(cgc_strlen ( tlv49 )); }
    {int tlv41; tlv41 = (int)(cgc_strlen ( tlv49 )); }
    {char * tlv40; tlv40 = (char *)(cgc_strlen ( tlv49 )); }
    {cgc_size_t tlv39; tlv39 = (cgc_size_t)(cgc_strlen ( tlv49 )); }
    {char tlv38; tlv38 = (char)(cgc_strlen ( tlv49 )); }
    {int tlv42; tlv42 = (int)(cgc_strlen ( tlv49 )); }
    {cgc_size_t tlv65; tlv65 = (cgc_size_t)(cgc_strlen ( tlv49 )); }
    {char * tlv33; tlv33 = (char *)(cgc_strlen ( tlv49 )); }
    {void * tlv34; tlv34 = (void *)(cgc_strlen ( tlv49 )); }
    {cgc_size_t tlv66; tlv66 = (cgc_size_t)(cgc_strlen ( tlv49 )); }
    {char * tlv36; tlv36 = (char *)(cgc_strlen ( tlv49 )); }
    {void * tlv37; tlv37 = (void *)(cgc_strlen ( tlv49 )); }
    {int tlv48; tlv48 = (int)(cgc_strlen ( tlv49 )); }
    {char * tlv47; tlv47 = (char *)(cgc_strlen ( tlv49 )); }
    {cgc_size_t tlv46; tlv46 = (cgc_size_t)(cgc_strlen ( tlv49 )); }
    {char tlv45; tlv45 = (char)(cgc_strlen ( tlv49 )); }
    {int tlv53; tlv53 = (int)(cgc_strlen ( tlv49 )); }
    {char * tlv52; tlv52 = (char *)(cgc_strlen ( tlv49 )); }
    {cgc_size_t tlv51; tlv51 = (cgc_size_t)(cgc_strlen ( tlv49 )); }
    {char tlv50; tlv50 = (char)(cgc_strlen ( tlv49 )); }
    {int tlv58; tlv58 = (int)(cgc_strlen ( tlv49 )); }
    {char * tlv57; tlv57 = (char *)(cgc_strlen ( tlv49 )); }
    {cgc_size_t tlv56; tlv56 = (cgc_size_t)(cgc_strlen ( tlv49 )); }
    {char tlv55; tlv55 = (char)(cgc_strlen ( tlv49 )); }
    {int tlv63; tlv63 = (int)(cgc_strlen ( tlv49 )); }
    {char * tlv62; tlv62 = (char *)(cgc_strlen ( tlv49 )); }
    {cgc_size_t tlv61; tlv61 = (cgc_size_t)(cgc_strlen ( tlv49 )); }
    {char tlv60; tlv60 = (char)(cgc_strlen ( tlv49 )); }
    {int new_year; new_year = (int)(cgc_strlen ( tlv49 )); }
    {int new_score; new_score = (int)(cgc_strlen ( tlv49 )); }
    {unsigned int genre; genre = (unsigned int)(cgc_strlen ( tlv49 )); }
    {unsigned int rating; rating = (unsigned int)(cgc_strlen ( tlv49 )); }
    {int tlv69; tlv69 = (int)(cgc_strlen ( tlv49 )); }
    {int tlv72; tlv72 = (int)(cgc_strlen ( tlv49 )); }
    {int tlv75; tlv75 = (int)(cgc_strlen ( tlv49 )); }
    {int tlv78; tlv78 = (int)(cgc_strlen ( tlv49 )); }
}
void fix_ingred_main_9_35(){
fix_ingred_main_9_35_0();
}
void fix_ingred_main_9_36_2(){
cgc_size_t tlv7;
    bzero(&tlv7,sizeof(cgc_size_t));
    {unsigned int movie_id; movie_id = (unsigned int)(tlv7); }
    {unsigned int num_movies; num_movies = (unsigned int)(tlv7); }
    {char * new_title; new_title = (char *)(tlv7); }
    {char * new_desc; new_desc = (char *)(tlv7); }
    {char buf [ 1024 ]; buf [ ( 1024 )-1 ] = (char)(tlv7); }
    {int tlv1; tlv1 = (int)(tlv7); }
    {cgc_size_t tlv2; tlv2 = (cgc_size_t)(tlv7); }
    {int tlv3; tlv3 = (int)(tlv7); }
    {cgc_size_t tlv4; tlv4 = (cgc_size_t)(tlv7); }
    {int finish; finish = (int)(tlv7); }
    {int tlv17; tlv17 = (int)(tlv7); }
    {int tlv22; tlv22 = (int)(tlv7); }
    {char * tlv21; tlv21 = (char *)(tlv7); }
    {cgc_size_t tlv20; tlv20 = (cgc_size_t)(tlv7); }
    {char tlv19; tlv19 = (char)(tlv7); }
    {int tlv27; tlv27 = (int)(tlv7); }
    {char * tlv26; tlv26 = (char *)(tlv7); }
    {cgc_size_t tlv25; tlv25 = (cgc_size_t)(tlv7); }
    {char tlv24; tlv24 = (char)(tlv7); }
    {int tlv5; tlv5 = (int)(tlv7); }
    {int tlv6; tlv6 = (int)(tlv7); }
    {int tlv8; tlv8 = (int)(tlv7); }
    {cgc_size_t tlv9; tlv9 = (cgc_size_t)(tlv7); }
    {int tlv10; tlv10 = (int)(tlv7); }
    {cgc_size_t tlv11; tlv11 = (cgc_size_t)(tlv7); }
    {int tlv12; tlv12 = (int)(tlv7); }
    {cgc_size_t tlv13; tlv13 = (cgc_size_t)(tlv7); }
    {int tlv41; tlv41 = (int)(tlv7); }
    {char * tlv40; tlv40 = (char *)(tlv7); }
    {cgc_size_t tlv39; tlv39 = (cgc_size_t)(tlv7); }
    {char tlv38; tlv38 = (char)(tlv7); }
    {int tlv42; tlv42 = (int)(tlv7); }
    {cgc_size_t tlv65; tlv65 = (cgc_size_t)(tlv7); }
    {char * tlv33; tlv33 = (char *)(tlv7); }
    {void * tlv34; tlv34 = (void *)(tlv7); }
    {cgc_size_t tlv66; tlv66 = (cgc_size_t)(tlv7); }
    {char * tlv36; tlv36 = (char *)(tlv7); }
    {void * tlv37; tlv37 = (void *)(tlv7); }
    {int tlv48; tlv48 = (int)(tlv7); }
    {char * tlv47; tlv47 = (char *)(tlv7); }
    {cgc_size_t tlv46; tlv46 = (cgc_size_t)(tlv7); }
    {char tlv45; tlv45 = (char)(tlv7); }
    {int tlv53; tlv53 = (int)(tlv7); }
    {char * tlv52; tlv52 = (char *)(tlv7); }
    {cgc_size_t tlv51; tlv51 = (cgc_size_t)(tlv7); }
    {char tlv50; tlv50 = (char)(tlv7); }
    {int tlv58; tlv58 = (int)(tlv7); }
    {char * tlv57; tlv57 = (char *)(tlv7); }
    {cgc_size_t tlv56; tlv56 = (cgc_size_t)(tlv7); }
    {char tlv55; tlv55 = (char)(tlv7); }
    {int tlv63; tlv63 = (int)(tlv7); }
    {char * tlv62; tlv62 = (char *)(tlv7); }
    {cgc_size_t tlv61; tlv61 = (cgc_size_t)(tlv7); }
    {char tlv60; tlv60 = (char)(tlv7); }
    {int new_year; new_year = (int)(tlv7); }
    {int new_score; new_score = (int)(tlv7); }
    {unsigned int genre; genre = (unsigned int)(tlv7); }
    {unsigned int rating; rating = (unsigned int)(tlv7); }
    {int tlv69; tlv69 = (int)(tlv7); }
    {int tlv72; tlv72 = (int)(tlv7); }
    {int tlv75; tlv75 = (int)(tlv7); }
    {int tlv78; tlv78 = (int)(tlv7); }
}
void fix_ingred_main_9_36(){
fix_ingred_main_9_36_2();
}
void fix_ingred_main_9_38_5(){
int new_year;
    bzero(&new_year,sizeof(int));
    {unsigned int movie_id; movie_id = (unsigned int)(new_year); }
    {unsigned int num_movies; num_movies = (unsigned int)(new_year); }
    {char * new_title; new_title = (char *)(new_year); }
    {char * new_desc; new_desc = (char *)(new_year); }
    {char buf [ 1024 ]; buf [ ( 1024 )-1 ] = (char)(new_year); }
    {int tlv1; tlv1 = (int)(new_year); }
    {cgc_size_t tlv2; tlv2 = (cgc_size_t)(new_year); }
    {int tlv3; tlv3 = (int)(new_year); }
    {cgc_size_t tlv4; tlv4 = (cgc_size_t)(new_year); }
    {int finish; finish = (int)(new_year); }
    {int tlv17; tlv17 = (int)(new_year); }
    {int tlv22; tlv22 = (int)(new_year); }
    {char * tlv21; tlv21 = (char *)(new_year); }
    {cgc_size_t tlv20; tlv20 = (cgc_size_t)(new_year); }
    {char tlv19; tlv19 = (char)(new_year); }
    {int tlv27; tlv27 = (int)(new_year); }
    {char * tlv26; tlv26 = (char *)(new_year); }
    {cgc_size_t tlv25; tlv25 = (cgc_size_t)(new_year); }
    {char tlv24; tlv24 = (char)(new_year); }
    {int tlv5; tlv5 = (int)(new_year); }
    {int tlv6; tlv6 = (int)(new_year); }
    {cgc_size_t tlv7; tlv7 = (cgc_size_t)(new_year); }
    {int tlv8; tlv8 = (int)(new_year); }
    {cgc_size_t tlv9; tlv9 = (cgc_size_t)(new_year); }
    {int tlv10; tlv10 = (int)(new_year); }
    {cgc_size_t tlv11; tlv11 = (cgc_size_t)(new_year); }
    {int tlv12; tlv12 = (int)(new_year); }
    {cgc_size_t tlv13; tlv13 = (cgc_size_t)(new_year); }
    {int tlv41; tlv41 = (int)(new_year); }
    {char * tlv40; tlv40 = (char *)(new_year); }
    {cgc_size_t tlv39; tlv39 = (cgc_size_t)(new_year); }
    {char tlv38; tlv38 = (char)(new_year); }
    {int tlv42; tlv42 = (int)(new_year); }
    {cgc_size_t tlv65; tlv65 = (cgc_size_t)(new_year); }
    {char * tlv33; tlv33 = (char *)(new_year); }
    {void * tlv34; tlv34 = (void *)(new_year); }
    {cgc_size_t tlv66; tlv66 = (cgc_size_t)(new_year); }
    {char * tlv36; tlv36 = (char *)(new_year); }
    {void * tlv37; tlv37 = (void *)(new_year); }
    {int tlv48; tlv48 = (int)(new_year); }
    {char * tlv47; tlv47 = (char *)(new_year); }
    {cgc_size_t tlv46; tlv46 = (cgc_size_t)(new_year); }
    {char tlv45; tlv45 = (char)(new_year); }
    {int tlv53; tlv53 = (int)(new_year); }
    {char * tlv52; tlv52 = (char *)(new_year); }
    {cgc_size_t tlv51; tlv51 = (cgc_size_t)(new_year); }
    {char tlv50; tlv50 = (char)(new_year); }
    {int tlv58; tlv58 = (int)(new_year); }
    {char * tlv57; tlv57 = (char *)(new_year); }
    {cgc_size_t tlv56; tlv56 = (cgc_size_t)(new_year); }
    {char tlv55; tlv55 = (char)(new_year); }
    {int tlv63; tlv63 = (int)(new_year); }
    {char * tlv62; tlv62 = (char *)(new_year); }
    {cgc_size_t tlv61; tlv61 = (cgc_size_t)(new_year); }
    {char tlv60; tlv60 = (char)(new_year); }
    {int new_score; new_score = (int)(new_year); }
    {unsigned int genre; genre = (unsigned int)(new_year); }
    {unsigned int rating; rating = (unsigned int)(new_year); }
    {int tlv69; tlv69 = (int)(new_year); }
    {int tlv72; tlv72 = (int)(new_year); }
    {int tlv75; tlv75 = (int)(new_year); }
    {int tlv78; tlv78 = (int)(new_year); }
}
void fix_ingred_main_9_38_6(){
int new_year;
    bzero(&new_year,sizeof(int));
    {unsigned int movie_id; movie_id = (unsigned int)(1800); }
    {unsigned int num_movies; num_movies = (unsigned int)(1800); }
    {char * new_title; new_title = (char *)(1800); }
    {char * new_desc; new_desc = (char *)(1800); }
    {char buf [ 1024 ]; buf [ ( 1024 )-1 ] = (char)(1800); }
    {int tlv1; tlv1 = (int)(1800); }
    {cgc_size_t tlv2; tlv2 = (cgc_size_t)(1800); }
    {int tlv3; tlv3 = (int)(1800); }
    {cgc_size_t tlv4; tlv4 = (cgc_size_t)(1800); }
    {int finish; finish = (int)(1800); }
    {int tlv17; tlv17 = (int)(1800); }
    {int tlv22; tlv22 = (int)(1800); }
    {char * tlv21; tlv21 = (char *)(1800); }
    {cgc_size_t tlv20; tlv20 = (cgc_size_t)(1800); }
    {char tlv19; tlv19 = (char)(1800); }
    {int tlv27; tlv27 = (int)(1800); }
    {char * tlv26; tlv26 = (char *)(1800); }
    {cgc_size_t tlv25; tlv25 = (cgc_size_t)(1800); }
    {char tlv24; tlv24 = (char)(1800); }
    {int tlv5; tlv5 = (int)(1800); }
    {int tlv6; tlv6 = (int)(1800); }
    {cgc_size_t tlv7; tlv7 = (cgc_size_t)(1800); }
    {int tlv8; tlv8 = (int)(1800); }
    {cgc_size_t tlv9; tlv9 = (cgc_size_t)(1800); }
    {int tlv10; tlv10 = (int)(1800); }
    {cgc_size_t tlv11; tlv11 = (cgc_size_t)(1800); }
    {int tlv12; tlv12 = (int)(1800); }
    {cgc_size_t tlv13; tlv13 = (cgc_size_t)(1800); }
    {int tlv41; tlv41 = (int)(1800); }
    {char * tlv40; tlv40 = (char *)(1800); }
    {cgc_size_t tlv39; tlv39 = (cgc_size_t)(1800); }
    {char tlv38; tlv38 = (char)(1800); }
    {int tlv42; tlv42 = (int)(1800); }
    {cgc_size_t tlv65; tlv65 = (cgc_size_t)(1800); }
    {char * tlv33; tlv33 = (char *)(1800); }
    {void * tlv34; tlv34 = (void *)(1800); }
    {cgc_size_t tlv66; tlv66 = (cgc_size_t)(1800); }
    {char * tlv36; tlv36 = (char *)(1800); }
    {void * tlv37; tlv37 = (void *)(1800); }
    {int tlv48; tlv48 = (int)(1800); }
    {char * tlv47; tlv47 = (char *)(1800); }
    {cgc_size_t tlv46; tlv46 = (cgc_size_t)(1800); }
    {char tlv45; tlv45 = (char)(1800); }
    {int tlv53; tlv53 = (int)(1800); }
    {char * tlv52; tlv52 = (char *)(1800); }
    {cgc_size_t tlv51; tlv51 = (cgc_size_t)(1800); }
    {char tlv50; tlv50 = (char)(1800); }
    {int tlv58; tlv58 = (int)(1800); }
    {char * tlv57; tlv57 = (char *)(1800); }
    {cgc_size_t tlv56; tlv56 = (cgc_size_t)(1800); }
    {char tlv55; tlv55 = (char)(1800); }
    {int tlv63; tlv63 = (int)(1800); }
    {char * tlv62; tlv62 = (char *)(1800); }
    {cgc_size_t tlv61; tlv61 = (cgc_size_t)(1800); }
    {char tlv60; tlv60 = (char)(1800); }
    {int new_year; new_year = (int)(1800); }
    {int new_score; new_score = (int)(1800); }
    {unsigned int genre; genre = (unsigned int)(1800); }
    {unsigned int rating; rating = (unsigned int)(1800); }
    {int tlv69; tlv69 = (int)(1800); }
    {int tlv72; tlv72 = (int)(1800); }
    {int tlv75; tlv75 = (int)(1800); }
    {int tlv78; tlv78 = (int)(1800); }
}
void fix_ingred_main_9_38_8(){
int new_year;
    bzero(&new_year,sizeof(int));
    {unsigned int movie_id; movie_id = (unsigned int)(2015); }
    {unsigned int num_movies; num_movies = (unsigned int)(2015); }
    {char * new_title; new_title = (char *)(2015); }
    {char * new_desc; new_desc = (char *)(2015); }
    {char buf [ 1024 ]; buf [ ( 1024 )-1 ] = (char)(2015); }
    {int tlv1; tlv1 = (int)(2015); }
    {cgc_size_t tlv2; tlv2 = (cgc_size_t)(2015); }
    {int tlv3; tlv3 = (int)(2015); }
    {cgc_size_t tlv4; tlv4 = (cgc_size_t)(2015); }
    {int finish; finish = (int)(2015); }
    {int tlv17; tlv17 = (int)(2015); }
    {int tlv22; tlv22 = (int)(2015); }
    {char * tlv21; tlv21 = (char *)(2015); }
    {cgc_size_t tlv20; tlv20 = (cgc_size_t)(2015); }
    {char tlv19; tlv19 = (char)(2015); }
    {int tlv27; tlv27 = (int)(2015); }
    {char * tlv26; tlv26 = (char *)(2015); }
    {cgc_size_t tlv25; tlv25 = (cgc_size_t)(2015); }
    {char tlv24; tlv24 = (char)(2015); }
    {int tlv5; tlv5 = (int)(2015); }
    {int tlv6; tlv6 = (int)(2015); }
    {cgc_size_t tlv7; tlv7 = (cgc_size_t)(2015); }
    {int tlv8; tlv8 = (int)(2015); }
    {cgc_size_t tlv9; tlv9 = (cgc_size_t)(2015); }
    {int tlv10; tlv10 = (int)(2015); }
    {cgc_size_t tlv11; tlv11 = (cgc_size_t)(2015); }
    {int tlv12; tlv12 = (int)(2015); }
    {cgc_size_t tlv13; tlv13 = (cgc_size_t)(2015); }
    {int tlv41; tlv41 = (int)(2015); }
    {char * tlv40; tlv40 = (char *)(2015); }
    {cgc_size_t tlv39; tlv39 = (cgc_size_t)(2015); }
    {char tlv38; tlv38 = (char)(2015); }
    {int tlv42; tlv42 = (int)(2015); }
    {cgc_size_t tlv65; tlv65 = (cgc_size_t)(2015); }
    {char * tlv33; tlv33 = (char *)(2015); }
    {void * tlv34; tlv34 = (void *)(2015); }
    {cgc_size_t tlv66; tlv66 = (cgc_size_t)(2015); }
    {char * tlv36; tlv36 = (char *)(2015); }
    {void * tlv37; tlv37 = (void *)(2015); }
    {int tlv48; tlv48 = (int)(2015); }
    {char * tlv47; tlv47 = (char *)(2015); }
    {cgc_size_t tlv46; tlv46 = (cgc_size_t)(2015); }
    {char tlv45; tlv45 = (char)(2015); }
    {int tlv53; tlv53 = (int)(2015); }
    {char * tlv52; tlv52 = (char *)(2015); }
    {cgc_size_t tlv51; tlv51 = (cgc_size_t)(2015); }
    {char tlv50; tlv50 = (char)(2015); }
    {int tlv58; tlv58 = (int)(2015); }
    {char * tlv57; tlv57 = (char *)(2015); }
    {cgc_size_t tlv56; tlv56 = (cgc_size_t)(2015); }
    {char tlv55; tlv55 = (char)(2015); }
    {int tlv63; tlv63 = (int)(2015); }
    {char * tlv62; tlv62 = (char *)(2015); }
    {cgc_size_t tlv61; tlv61 = (cgc_size_t)(2015); }
    {char tlv60; tlv60 = (char)(2015); }
    {int new_year; new_year = (int)(2015); }
    {int new_score; new_score = (int)(2015); }
    {unsigned int genre; genre = (unsigned int)(2015); }
    {unsigned int rating; rating = (unsigned int)(2015); }
    {int tlv69; tlv69 = (int)(2015); }
    {int tlv72; tlv72 = (int)(2015); }
    {int tlv75; tlv75 = (int)(2015); }
    {int tlv78; tlv78 = (int)(2015); }
}
void fix_ingred_main_9_38(){
fix_ingred_main_9_38_5();
fix_ingred_main_9_38_6();
fix_ingred_main_9_38_8();
}
void fix_ingred_main_9_43_2(){
int tlv8;
    bzero(&tlv8,sizeof(int));
    {unsigned int movie_id; movie_id = (unsigned int)(tlv8); }
    {unsigned int num_movies; num_movies = (unsigned int)(tlv8); }
    {char * new_title; new_title = (char *)(tlv8); }
    {char * new_desc; new_desc = (char *)(tlv8); }
    {char buf [ 1024 ]; buf [ ( 1024 )-1 ] = (char)(tlv8); }
    {int tlv1; tlv1 = (int)(tlv8); }
    {cgc_size_t tlv2; tlv2 = (cgc_size_t)(tlv8); }
    {int tlv3; tlv3 = (int)(tlv8); }
    {cgc_size_t tlv4; tlv4 = (cgc_size_t)(tlv8); }
    {int finish; finish = (int)(tlv8); }
    {int tlv17; tlv17 = (int)(tlv8); }
    {int tlv22; tlv22 = (int)(tlv8); }
    {char * tlv21; tlv21 = (char *)(tlv8); }
    {cgc_size_t tlv20; tlv20 = (cgc_size_t)(tlv8); }
    {char tlv19; tlv19 = (char)(tlv8); }
    {int tlv27; tlv27 = (int)(tlv8); }
    {char * tlv26; tlv26 = (char *)(tlv8); }
    {cgc_size_t tlv25; tlv25 = (cgc_size_t)(tlv8); }
    {char tlv24; tlv24 = (char)(tlv8); }
    {int tlv5; tlv5 = (int)(tlv8); }
    {int tlv6; tlv6 = (int)(tlv8); }
    {cgc_size_t tlv7; tlv7 = (cgc_size_t)(tlv8); }
    {cgc_size_t tlv9; tlv9 = (cgc_size_t)(tlv8); }
    {int tlv10; tlv10 = (int)(tlv8); }
    {cgc_size_t tlv11; tlv11 = (cgc_size_t)(tlv8); }
    {int tlv12; tlv12 = (int)(tlv8); }
    {cgc_size_t tlv13; tlv13 = (cgc_size_t)(tlv8); }
    {int tlv41; tlv41 = (int)(tlv8); }
    {char * tlv40; tlv40 = (char *)(tlv8); }
    {cgc_size_t tlv39; tlv39 = (cgc_size_t)(tlv8); }
    {char tlv38; tlv38 = (char)(tlv8); }
    {int tlv42; tlv42 = (int)(tlv8); }
    {cgc_size_t tlv65; tlv65 = (cgc_size_t)(tlv8); }
    {char * tlv33; tlv33 = (char *)(tlv8); }
    {void * tlv34; tlv34 = (void *)(tlv8); }
    {cgc_size_t tlv66; tlv66 = (cgc_size_t)(tlv8); }
    {char * tlv36; tlv36 = (char *)(tlv8); }
    {void * tlv37; tlv37 = (void *)(tlv8); }
    {int tlv48; tlv48 = (int)(tlv8); }
    {char * tlv47; tlv47 = (char *)(tlv8); }
    {cgc_size_t tlv46; tlv46 = (cgc_size_t)(tlv8); }
    {char tlv45; tlv45 = (char)(tlv8); }
    {int tlv53; tlv53 = (int)(tlv8); }
    {char * tlv52; tlv52 = (char *)(tlv8); }
    {cgc_size_t tlv51; tlv51 = (cgc_size_t)(tlv8); }
    {char tlv50; tlv50 = (char)(tlv8); }
    {int tlv58; tlv58 = (int)(tlv8); }
    {char * tlv57; tlv57 = (char *)(tlv8); }
    {cgc_size_t tlv56; tlv56 = (cgc_size_t)(tlv8); }
    {char tlv55; tlv55 = (char)(tlv8); }
    {int tlv63; tlv63 = (int)(tlv8); }
    {char * tlv62; tlv62 = (char *)(tlv8); }
    {cgc_size_t tlv61; tlv61 = (cgc_size_t)(tlv8); }
    {char tlv60; tlv60 = (char)(tlv8); }
    {int new_year; new_year = (int)(tlv8); }
    {int new_score; new_score = (int)(tlv8); }
    {unsigned int genre; genre = (unsigned int)(tlv8); }
    {unsigned int rating; rating = (unsigned int)(tlv8); }
    {int tlv69; tlv69 = (int)(tlv8); }
    {int tlv72; tlv72 = (int)(tlv8); }
    {int tlv75; tlv75 = (int)(tlv8); }
    {int tlv78; tlv78 = (int)(tlv8); }
}
void fix_ingred_main_9_43(){
fix_ingred_main_9_43_2();
}
void fix_ingred_main_9_44_0(){
char tlv54_ref;
    bzero(&tlv54_ref,1*sizeof(char));
const char * tlv54 = &tlv54_ref;
    {unsigned int movie_id; movie_id = (unsigned int)(cgc_strlen ( tlv54 )); }
    {unsigned int num_movies; num_movies = (unsigned int)(cgc_strlen ( tlv54 )); }
    {char * new_title; new_title = (char *)(cgc_strlen ( tlv54 )); }
    {char * new_desc; new_desc = (char *)(cgc_strlen ( tlv54 )); }
    {char buf [ 1024 ]; buf [ ( 1024 )-1 ] = (char)(cgc_strlen ( tlv54 )); }
    {int tlv1; tlv1 = (int)(cgc_strlen ( tlv54 )); }
    {cgc_size_t tlv2; tlv2 = (cgc_size_t)(cgc_strlen ( tlv54 )); }
    {int tlv3; tlv3 = (int)(cgc_strlen ( tlv54 )); }
    {cgc_size_t tlv4; tlv4 = (cgc_size_t)(cgc_strlen ( tlv54 )); }
    {int finish; finish = (int)(cgc_strlen ( tlv54 )); }
    {int tlv17; tlv17 = (int)(cgc_strlen ( tlv54 )); }
    {int tlv22; tlv22 = (int)(cgc_strlen ( tlv54 )); }
    {char * tlv21; tlv21 = (char *)(cgc_strlen ( tlv54 )); }
    {cgc_size_t tlv20; tlv20 = (cgc_size_t)(cgc_strlen ( tlv54 )); }
    {char tlv19; tlv19 = (char)(cgc_strlen ( tlv54 )); }
    {int tlv27; tlv27 = (int)(cgc_strlen ( tlv54 )); }
    {char * tlv26; tlv26 = (char *)(cgc_strlen ( tlv54 )); }
    {cgc_size_t tlv25; tlv25 = (cgc_size_t)(cgc_strlen ( tlv54 )); }
    {char tlv24; tlv24 = (char)(cgc_strlen ( tlv54 )); }
    {int tlv5; tlv5 = (int)(cgc_strlen ( tlv54 )); }
    {int tlv6; tlv6 = (int)(cgc_strlen ( tlv54 )); }
    {cgc_size_t tlv7; tlv7 = (cgc_size_t)(cgc_strlen ( tlv54 )); }
    {int tlv8; tlv8 = (int)(cgc_strlen ( tlv54 )); }
    {cgc_size_t tlv9; tlv9 = (cgc_size_t)(cgc_strlen ( tlv54 )); }
    {int tlv10; tlv10 = (int)(cgc_strlen ( tlv54 )); }
    {cgc_size_t tlv11; tlv11 = (cgc_size_t)(cgc_strlen ( tlv54 )); }
    {int tlv12; tlv12 = (int)(cgc_strlen ( tlv54 )); }
    {cgc_size_t tlv13; tlv13 = (cgc_size_t)(cgc_strlen ( tlv54 )); }
    {int tlv41; tlv41 = (int)(cgc_strlen ( tlv54 )); }
    {char * tlv40; tlv40 = (char *)(cgc_strlen ( tlv54 )); }
    {cgc_size_t tlv39; tlv39 = (cgc_size_t)(cgc_strlen ( tlv54 )); }
    {char tlv38; tlv38 = (char)(cgc_strlen ( tlv54 )); }
    {int tlv42; tlv42 = (int)(cgc_strlen ( tlv54 )); }
    {cgc_size_t tlv65; tlv65 = (cgc_size_t)(cgc_strlen ( tlv54 )); }
    {char * tlv33; tlv33 = (char *)(cgc_strlen ( tlv54 )); }
    {void * tlv34; tlv34 = (void *)(cgc_strlen ( tlv54 )); }
    {cgc_size_t tlv66; tlv66 = (cgc_size_t)(cgc_strlen ( tlv54 )); }
    {char * tlv36; tlv36 = (char *)(cgc_strlen ( tlv54 )); }
    {void * tlv37; tlv37 = (void *)(cgc_strlen ( tlv54 )); }
    {int tlv48; tlv48 = (int)(cgc_strlen ( tlv54 )); }
    {char * tlv47; tlv47 = (char *)(cgc_strlen ( tlv54 )); }
    {cgc_size_t tlv46; tlv46 = (cgc_size_t)(cgc_strlen ( tlv54 )); }
    {char tlv45; tlv45 = (char)(cgc_strlen ( tlv54 )); }
    {int tlv53; tlv53 = (int)(cgc_strlen ( tlv54 )); }
    {char * tlv52; tlv52 = (char *)(cgc_strlen ( tlv54 )); }
    {cgc_size_t tlv51; tlv51 = (cgc_size_t)(cgc_strlen ( tlv54 )); }
    {char tlv50; tlv50 = (char)(cgc_strlen ( tlv54 )); }
    {int tlv58; tlv58 = (int)(cgc_strlen ( tlv54 )); }
    {char * tlv57; tlv57 = (char *)(cgc_strlen ( tlv54 )); }
    {cgc_size_t tlv56; tlv56 = (cgc_size_t)(cgc_strlen ( tlv54 )); }
    {char tlv55; tlv55 = (char)(cgc_strlen ( tlv54 )); }
    {int tlv63; tlv63 = (int)(cgc_strlen ( tlv54 )); }
    {char * tlv62; tlv62 = (char *)(cgc_strlen ( tlv54 )); }
    {cgc_size_t tlv61; tlv61 = (cgc_size_t)(cgc_strlen ( tlv54 )); }
    {char tlv60; tlv60 = (char)(cgc_strlen ( tlv54 )); }
    {int new_year; new_year = (int)(cgc_strlen ( tlv54 )); }
    {int new_score; new_score = (int)(cgc_strlen ( tlv54 )); }
    {unsigned int genre; genre = (unsigned int)(cgc_strlen ( tlv54 )); }
    {unsigned int rating; rating = (unsigned int)(cgc_strlen ( tlv54 )); }
    {int tlv69; tlv69 = (int)(cgc_strlen ( tlv54 )); }
    {int tlv72; tlv72 = (int)(cgc_strlen ( tlv54 )); }
    {int tlv75; tlv75 = (int)(cgc_strlen ( tlv54 )); }
    {int tlv78; tlv78 = (int)(cgc_strlen ( tlv54 )); }
}
void fix_ingred_main_9_44(){
fix_ingred_main_9_44_0();
}
void fix_ingred_main_9_45_2(){
cgc_size_t tlv9;
    bzero(&tlv9,sizeof(cgc_size_t));
    {unsigned int movie_id; movie_id = (unsigned int)(tlv9); }
    {unsigned int num_movies; num_movies = (unsigned int)(tlv9); }
    {char * new_title; new_title = (char *)(tlv9); }
    {char * new_desc; new_desc = (char *)(tlv9); }
    {char buf [ 1024 ]; buf [ ( 1024 )-1 ] = (char)(tlv9); }
    {int tlv1; tlv1 = (int)(tlv9); }
    {cgc_size_t tlv2; tlv2 = (cgc_size_t)(tlv9); }
    {int tlv3; tlv3 = (int)(tlv9); }
    {cgc_size_t tlv4; tlv4 = (cgc_size_t)(tlv9); }
    {int finish; finish = (int)(tlv9); }
    {int tlv17; tlv17 = (int)(tlv9); }
    {int tlv22; tlv22 = (int)(tlv9); }
    {char * tlv21; tlv21 = (char *)(tlv9); }
    {cgc_size_t tlv20; tlv20 = (cgc_size_t)(tlv9); }
    {char tlv19; tlv19 = (char)(tlv9); }
    {int tlv27; tlv27 = (int)(tlv9); }
    {char * tlv26; tlv26 = (char *)(tlv9); }
    {cgc_size_t tlv25; tlv25 = (cgc_size_t)(tlv9); }
    {char tlv24; tlv24 = (char)(tlv9); }
    {int tlv5; tlv5 = (int)(tlv9); }
    {int tlv6; tlv6 = (int)(tlv9); }
    {cgc_size_t tlv7; tlv7 = (cgc_size_t)(tlv9); }
    {int tlv8; tlv8 = (int)(tlv9); }
    {int tlv10; tlv10 = (int)(tlv9); }
    {cgc_size_t tlv11; tlv11 = (cgc_size_t)(tlv9); }
    {int tlv12; tlv12 = (int)(tlv9); }
    {cgc_size_t tlv13; tlv13 = (cgc_size_t)(tlv9); }
    {int tlv41; tlv41 = (int)(tlv9); }
    {char * tlv40; tlv40 = (char *)(tlv9); }
    {cgc_size_t tlv39; tlv39 = (cgc_size_t)(tlv9); }
    {char tlv38; tlv38 = (char)(tlv9); }
    {int tlv42; tlv42 = (int)(tlv9); }
    {cgc_size_t tlv65; tlv65 = (cgc_size_t)(tlv9); }
    {char * tlv33; tlv33 = (char *)(tlv9); }
    {void * tlv34; tlv34 = (void *)(tlv9); }
    {cgc_size_t tlv66; tlv66 = (cgc_size_t)(tlv9); }
    {char * tlv36; tlv36 = (char *)(tlv9); }
    {void * tlv37; tlv37 = (void *)(tlv9); }
    {int tlv48; tlv48 = (int)(tlv9); }
    {char * tlv47; tlv47 = (char *)(tlv9); }
    {cgc_size_t tlv46; tlv46 = (cgc_size_t)(tlv9); }
    {char tlv45; tlv45 = (char)(tlv9); }
    {int tlv53; tlv53 = (int)(tlv9); }
    {char * tlv52; tlv52 = (char *)(tlv9); }
    {cgc_size_t tlv51; tlv51 = (cgc_size_t)(tlv9); }
    {char tlv50; tlv50 = (char)(tlv9); }
    {int tlv58; tlv58 = (int)(tlv9); }
    {char * tlv57; tlv57 = (char *)(tlv9); }
    {cgc_size_t tlv56; tlv56 = (cgc_size_t)(tlv9); }
    {char tlv55; tlv55 = (char)(tlv9); }
    {int tlv63; tlv63 = (int)(tlv9); }
    {char * tlv62; tlv62 = (char *)(tlv9); }
    {cgc_size_t tlv61; tlv61 = (cgc_size_t)(tlv9); }
    {char tlv60; tlv60 = (char)(tlv9); }
    {int new_year; new_year = (int)(tlv9); }
    {int new_score; new_score = (int)(tlv9); }
    {unsigned int genre; genre = (unsigned int)(tlv9); }
    {unsigned int rating; rating = (unsigned int)(tlv9); }
    {int tlv69; tlv69 = (int)(tlv9); }
    {int tlv72; tlv72 = (int)(tlv9); }
    {int tlv75; tlv75 = (int)(tlv9); }
    {int tlv78; tlv78 = (int)(tlv9); }
}
void fix_ingred_main_9_45(){
fix_ingred_main_9_45_2();
}
void fix_ingred_main_9_47_5(){
int new_score;
    bzero(&new_score,sizeof(int));
    {unsigned int movie_id; movie_id = (unsigned int)(new_score); }
    {unsigned int num_movies; num_movies = (unsigned int)(new_score); }
    {char * new_title; new_title = (char *)(new_score); }
    {char * new_desc; new_desc = (char *)(new_score); }
    {char buf [ 1024 ]; buf [ ( 1024 )-1 ] = (char)(new_score); }
    {int tlv1; tlv1 = (int)(new_score); }
    {cgc_size_t tlv2; tlv2 = (cgc_size_t)(new_score); }
    {int tlv3; tlv3 = (int)(new_score); }
    {cgc_size_t tlv4; tlv4 = (cgc_size_t)(new_score); }
    {int finish; finish = (int)(new_score); }
    {int tlv17; tlv17 = (int)(new_score); }
    {int tlv22; tlv22 = (int)(new_score); }
    {char * tlv21; tlv21 = (char *)(new_score); }
    {cgc_size_t tlv20; tlv20 = (cgc_size_t)(new_score); }
    {char tlv19; tlv19 = (char)(new_score); }
    {int tlv27; tlv27 = (int)(new_score); }
    {char * tlv26; tlv26 = (char *)(new_score); }
    {cgc_size_t tlv25; tlv25 = (cgc_size_t)(new_score); }
    {char tlv24; tlv24 = (char)(new_score); }
    {int tlv5; tlv5 = (int)(new_score); }
    {int tlv6; tlv6 = (int)(new_score); }
    {cgc_size_t tlv7; tlv7 = (cgc_size_t)(new_score); }
    {int tlv8; tlv8 = (int)(new_score); }
    {cgc_size_t tlv9; tlv9 = (cgc_size_t)(new_score); }
    {int tlv10; tlv10 = (int)(new_score); }
    {cgc_size_t tlv11; tlv11 = (cgc_size_t)(new_score); }
    {int tlv12; tlv12 = (int)(new_score); }
    {cgc_size_t tlv13; tlv13 = (cgc_size_t)(new_score); }
    {int tlv41; tlv41 = (int)(new_score); }
    {char * tlv40; tlv40 = (char *)(new_score); }
    {cgc_size_t tlv39; tlv39 = (cgc_size_t)(new_score); }
    {char tlv38; tlv38 = (char)(new_score); }
    {int tlv42; tlv42 = (int)(new_score); }
    {cgc_size_t tlv65; tlv65 = (cgc_size_t)(new_score); }
    {char * tlv33; tlv33 = (char *)(new_score); }
    {void * tlv34; tlv34 = (void *)(new_score); }
    {cgc_size_t tlv66; tlv66 = (cgc_size_t)(new_score); }
    {char * tlv36; tlv36 = (char *)(new_score); }
    {void * tlv37; tlv37 = (void *)(new_score); }
    {int tlv48; tlv48 = (int)(new_score); }
    {char * tlv47; tlv47 = (char *)(new_score); }
    {cgc_size_t tlv46; tlv46 = (cgc_size_t)(new_score); }
    {char tlv45; tlv45 = (char)(new_score); }
    {int tlv53; tlv53 = (int)(new_score); }
    {char * tlv52; tlv52 = (char *)(new_score); }
    {cgc_size_t tlv51; tlv51 = (cgc_size_t)(new_score); }
    {char tlv50; tlv50 = (char)(new_score); }
    {int tlv58; tlv58 = (int)(new_score); }
    {char * tlv57; tlv57 = (char *)(new_score); }
    {cgc_size_t tlv56; tlv56 = (cgc_size_t)(new_score); }
    {char tlv55; tlv55 = (char)(new_score); }
    {int tlv63; tlv63 = (int)(new_score); }
    {char * tlv62; tlv62 = (char *)(new_score); }
    {cgc_size_t tlv61; tlv61 = (cgc_size_t)(new_score); }
    {char tlv60; tlv60 = (char)(new_score); }
    {int new_year; new_year = (int)(new_score); }
    {unsigned int genre; genre = (unsigned int)(new_score); }
    {unsigned int rating; rating = (unsigned int)(new_score); }
    {int tlv69; tlv69 = (int)(new_score); }
    {int tlv72; tlv72 = (int)(new_score); }
    {int tlv75; tlv75 = (int)(new_score); }
    {int tlv78; tlv78 = (int)(new_score); }
}
void fix_ingred_main_9_47_8(){
int new_score;
    bzero(&new_score,sizeof(int));
    {unsigned int movie_id; movie_id = (unsigned int)(100); }
    {unsigned int num_movies; num_movies = (unsigned int)(100); }
    {char * new_title; new_title = (char *)(100); }
    {char * new_desc; new_desc = (char *)(100); }
    {char buf [ 1024 ]; buf [ ( 1024 )-1 ] = (char)(100); }
    {int tlv1; tlv1 = (int)(100); }
    {cgc_size_t tlv2; tlv2 = (cgc_size_t)(100); }
    {int tlv3; tlv3 = (int)(100); }
    {cgc_size_t tlv4; tlv4 = (cgc_size_t)(100); }
    {int finish; finish = (int)(100); }
    {int tlv17; tlv17 = (int)(100); }
    {int tlv22; tlv22 = (int)(100); }
    {char * tlv21; tlv21 = (char *)(100); }
    {cgc_size_t tlv20; tlv20 = (cgc_size_t)(100); }
    {char tlv19; tlv19 = (char)(100); }
    {int tlv27; tlv27 = (int)(100); }
    {char * tlv26; tlv26 = (char *)(100); }
    {cgc_size_t tlv25; tlv25 = (cgc_size_t)(100); }
    {char tlv24; tlv24 = (char)(100); }
    {int tlv5; tlv5 = (int)(100); }
    {int tlv6; tlv6 = (int)(100); }
    {cgc_size_t tlv7; tlv7 = (cgc_size_t)(100); }
    {int tlv8; tlv8 = (int)(100); }
    {cgc_size_t tlv9; tlv9 = (cgc_size_t)(100); }
    {int tlv10; tlv10 = (int)(100); }
    {cgc_size_t tlv11; tlv11 = (cgc_size_t)(100); }
    {int tlv12; tlv12 = (int)(100); }
    {cgc_size_t tlv13; tlv13 = (cgc_size_t)(100); }
    {int tlv41; tlv41 = (int)(100); }
    {char * tlv40; tlv40 = (char *)(100); }
    {cgc_size_t tlv39; tlv39 = (cgc_size_t)(100); }
    {char tlv38; tlv38 = (char)(100); }
    {int tlv42; tlv42 = (int)(100); }
    {cgc_size_t tlv65; tlv65 = (cgc_size_t)(100); }
    {char * tlv33; tlv33 = (char *)(100); }
    {void * tlv34; tlv34 = (void *)(100); }
    {cgc_size_t tlv66; tlv66 = (cgc_size_t)(100); }
    {char * tlv36; tlv36 = (char *)(100); }
    {void * tlv37; tlv37 = (void *)(100); }
    {int tlv48; tlv48 = (int)(100); }
    {char * tlv47; tlv47 = (char *)(100); }
    {cgc_size_t tlv46; tlv46 = (cgc_size_t)(100); }
    {char tlv45; tlv45 = (char)(100); }
    {int tlv53; tlv53 = (int)(100); }
    {char * tlv52; tlv52 = (char *)(100); }
    {cgc_size_t tlv51; tlv51 = (cgc_size_t)(100); }
    {char tlv50; tlv50 = (char)(100); }
    {int tlv58; tlv58 = (int)(100); }
    {char * tlv57; tlv57 = (char *)(100); }
    {cgc_size_t tlv56; tlv56 = (cgc_size_t)(100); }
    {char tlv55; tlv55 = (char)(100); }
    {int tlv63; tlv63 = (int)(100); }
    {char * tlv62; tlv62 = (char *)(100); }
    {cgc_size_t tlv61; tlv61 = (cgc_size_t)(100); }
    {char tlv60; tlv60 = (char)(100); }
    {int new_year; new_year = (int)(100); }
    {int new_score; new_score = (int)(100); }
    {unsigned int genre; genre = (unsigned int)(100); }
    {unsigned int rating; rating = (unsigned int)(100); }
    {int tlv69; tlv69 = (int)(100); }
    {int tlv72; tlv72 = (int)(100); }
    {int tlv75; tlv75 = (int)(100); }
    {int tlv78; tlv78 = (int)(100); }
}
void fix_ingred_main_9_47(){
fix_ingred_main_9_47_5();
fix_ingred_main_9_47_8();
}
void fix_ingred_main_9_52_3(){
int tlv10;
    bzero(&tlv10,sizeof(int));
    {unsigned int movie_id; movie_id = (unsigned int)(tlv10); }
    {unsigned int num_movies; num_movies = (unsigned int)(tlv10); }
    {char * new_title; new_title = (char *)(tlv10); }
    {char * new_desc; new_desc = (char *)(tlv10); }
    {char buf [ 1024 ]; buf [ ( 1024 )-1 ] = (char)(tlv10); }
    {int tlv1; tlv1 = (int)(tlv10); }
    {cgc_size_t tlv2; tlv2 = (cgc_size_t)(tlv10); }
    {int tlv3; tlv3 = (int)(tlv10); }
    {cgc_size_t tlv4; tlv4 = (cgc_size_t)(tlv10); }
    {int finish; finish = (int)(tlv10); }
    {int tlv17; tlv17 = (int)(tlv10); }
    {int tlv22; tlv22 = (int)(tlv10); }
    {char * tlv21; tlv21 = (char *)(tlv10); }
    {cgc_size_t tlv20; tlv20 = (cgc_size_t)(tlv10); }
    {char tlv19; tlv19 = (char)(tlv10); }
    {int tlv27; tlv27 = (int)(tlv10); }
    {char * tlv26; tlv26 = (char *)(tlv10); }
    {cgc_size_t tlv25; tlv25 = (cgc_size_t)(tlv10); }
    {char tlv24; tlv24 = (char)(tlv10); }
    {int tlv5; tlv5 = (int)(tlv10); }
    {int tlv6; tlv6 = (int)(tlv10); }
    {cgc_size_t tlv7; tlv7 = (cgc_size_t)(tlv10); }
    {int tlv8; tlv8 = (int)(tlv10); }
    {cgc_size_t tlv9; tlv9 = (cgc_size_t)(tlv10); }
    {cgc_size_t tlv11; tlv11 = (cgc_size_t)(tlv10); }
    {int tlv12; tlv12 = (int)(tlv10); }
    {cgc_size_t tlv13; tlv13 = (cgc_size_t)(tlv10); }
    {int tlv41; tlv41 = (int)(tlv10); }
    {char * tlv40; tlv40 = (char *)(tlv10); }
    {cgc_size_t tlv39; tlv39 = (cgc_size_t)(tlv10); }
    {char tlv38; tlv38 = (char)(tlv10); }
    {int tlv42; tlv42 = (int)(tlv10); }
    {cgc_size_t tlv65; tlv65 = (cgc_size_t)(tlv10); }
    {char * tlv33; tlv33 = (char *)(tlv10); }
    {void * tlv34; tlv34 = (void *)(tlv10); }
    {cgc_size_t tlv66; tlv66 = (cgc_size_t)(tlv10); }
    {char * tlv36; tlv36 = (char *)(tlv10); }
    {void * tlv37; tlv37 = (void *)(tlv10); }
    {int tlv48; tlv48 = (int)(tlv10); }
    {char * tlv47; tlv47 = (char *)(tlv10); }
    {cgc_size_t tlv46; tlv46 = (cgc_size_t)(tlv10); }
    {char tlv45; tlv45 = (char)(tlv10); }
    {int tlv53; tlv53 = (int)(tlv10); }
    {char * tlv52; tlv52 = (char *)(tlv10); }
    {cgc_size_t tlv51; tlv51 = (cgc_size_t)(tlv10); }
    {char tlv50; tlv50 = (char)(tlv10); }
    {int tlv58; tlv58 = (int)(tlv10); }
    {char * tlv57; tlv57 = (char *)(tlv10); }
    {cgc_size_t tlv56; tlv56 = (cgc_size_t)(tlv10); }
    {char tlv55; tlv55 = (char)(tlv10); }
    {int tlv63; tlv63 = (int)(tlv10); }
    {char * tlv62; tlv62 = (char *)(tlv10); }
    {cgc_size_t tlv61; tlv61 = (cgc_size_t)(tlv10); }
    {char tlv60; tlv60 = (char)(tlv10); }
    {int new_year; new_year = (int)(tlv10); }
    {int new_score; new_score = (int)(tlv10); }
    {unsigned int genre; genre = (unsigned int)(tlv10); }
    {unsigned int rating; rating = (unsigned int)(tlv10); }
    {int tlv69; tlv69 = (int)(tlv10); }
    {int tlv72; tlv72 = (int)(tlv10); }
    {int tlv75; tlv75 = (int)(tlv10); }
    {int tlv78; tlv78 = (int)(tlv10); }
}
void fix_ingred_main_9_52(){
fix_ingred_main_9_52_3();
}
void fix_ingred_main_9_53_0(){
char tlv59_ref;
    bzero(&tlv59_ref,1*sizeof(char));
const char * tlv59 = &tlv59_ref;
    {unsigned int movie_id; movie_id = (unsigned int)(cgc_strlen ( tlv59 )); }
    {unsigned int num_movies; num_movies = (unsigned int)(cgc_strlen ( tlv59 )); }
    {char * new_title; new_title = (char *)(cgc_strlen ( tlv59 )); }
    {char * new_desc; new_desc = (char *)(cgc_strlen ( tlv59 )); }
    {char buf [ 1024 ]; buf [ ( 1024 )-1 ] = (char)(cgc_strlen ( tlv59 )); }
    {int tlv1; tlv1 = (int)(cgc_strlen ( tlv59 )); }
    {cgc_size_t tlv2; tlv2 = (cgc_size_t)(cgc_strlen ( tlv59 )); }
    {int tlv3; tlv3 = (int)(cgc_strlen ( tlv59 )); }
    {cgc_size_t tlv4; tlv4 = (cgc_size_t)(cgc_strlen ( tlv59 )); }
    {int finish; finish = (int)(cgc_strlen ( tlv59 )); }
    {int tlv17; tlv17 = (int)(cgc_strlen ( tlv59 )); }
    {int tlv22; tlv22 = (int)(cgc_strlen ( tlv59 )); }
    {char * tlv21; tlv21 = (char *)(cgc_strlen ( tlv59 )); }
    {cgc_size_t tlv20; tlv20 = (cgc_size_t)(cgc_strlen ( tlv59 )); }
    {char tlv19; tlv19 = (char)(cgc_strlen ( tlv59 )); }
    {int tlv27; tlv27 = (int)(cgc_strlen ( tlv59 )); }
    {char * tlv26; tlv26 = (char *)(cgc_strlen ( tlv59 )); }
    {cgc_size_t tlv25; tlv25 = (cgc_size_t)(cgc_strlen ( tlv59 )); }
    {char tlv24; tlv24 = (char)(cgc_strlen ( tlv59 )); }
    {int tlv5; tlv5 = (int)(cgc_strlen ( tlv59 )); }
    {int tlv6; tlv6 = (int)(cgc_strlen ( tlv59 )); }
    {cgc_size_t tlv7; tlv7 = (cgc_size_t)(cgc_strlen ( tlv59 )); }
    {int tlv8; tlv8 = (int)(cgc_strlen ( tlv59 )); }
    {cgc_size_t tlv9; tlv9 = (cgc_size_t)(cgc_strlen ( tlv59 )); }
    {int tlv10; tlv10 = (int)(cgc_strlen ( tlv59 )); }
    {cgc_size_t tlv11; tlv11 = (cgc_size_t)(cgc_strlen ( tlv59 )); }
    {int tlv12; tlv12 = (int)(cgc_strlen ( tlv59 )); }
    {cgc_size_t tlv13; tlv13 = (cgc_size_t)(cgc_strlen ( tlv59 )); }
    {int tlv41; tlv41 = (int)(cgc_strlen ( tlv59 )); }
    {char * tlv40; tlv40 = (char *)(cgc_strlen ( tlv59 )); }
    {cgc_size_t tlv39; tlv39 = (cgc_size_t)(cgc_strlen ( tlv59 )); }
    {char tlv38; tlv38 = (char)(cgc_strlen ( tlv59 )); }
    {int tlv42; tlv42 = (int)(cgc_strlen ( tlv59 )); }
    {cgc_size_t tlv65; tlv65 = (cgc_size_t)(cgc_strlen ( tlv59 )); }
    {char * tlv33; tlv33 = (char *)(cgc_strlen ( tlv59 )); }
    {void * tlv34; tlv34 = (void *)(cgc_strlen ( tlv59 )); }
    {cgc_size_t tlv66; tlv66 = (cgc_size_t)(cgc_strlen ( tlv59 )); }
    {char * tlv36; tlv36 = (char *)(cgc_strlen ( tlv59 )); }
    {void * tlv37; tlv37 = (void *)(cgc_strlen ( tlv59 )); }
    {int tlv48; tlv48 = (int)(cgc_strlen ( tlv59 )); }
    {char * tlv47; tlv47 = (char *)(cgc_strlen ( tlv59 )); }
    {cgc_size_t tlv46; tlv46 = (cgc_size_t)(cgc_strlen ( tlv59 )); }
    {char tlv45; tlv45 = (char)(cgc_strlen ( tlv59 )); }
    {int tlv53; tlv53 = (int)(cgc_strlen ( tlv59 )); }
    {char * tlv52; tlv52 = (char *)(cgc_strlen ( tlv59 )); }
    {cgc_size_t tlv51; tlv51 = (cgc_size_t)(cgc_strlen ( tlv59 )); }
    {char tlv50; tlv50 = (char)(cgc_strlen ( tlv59 )); }
    {int tlv58; tlv58 = (int)(cgc_strlen ( tlv59 )); }
    {char * tlv57; tlv57 = (char *)(cgc_strlen ( tlv59 )); }
    {cgc_size_t tlv56; tlv56 = (cgc_size_t)(cgc_strlen ( tlv59 )); }
    {char tlv55; tlv55 = (char)(cgc_strlen ( tlv59 )); }
    {int tlv63; tlv63 = (int)(cgc_strlen ( tlv59 )); }
    {char * tlv62; tlv62 = (char *)(cgc_strlen ( tlv59 )); }
    {cgc_size_t tlv61; tlv61 = (cgc_size_t)(cgc_strlen ( tlv59 )); }
    {char tlv60; tlv60 = (char)(cgc_strlen ( tlv59 )); }
    {int new_year; new_year = (int)(cgc_strlen ( tlv59 )); }
    {int new_score; new_score = (int)(cgc_strlen ( tlv59 )); }
    {unsigned int genre; genre = (unsigned int)(cgc_strlen ( tlv59 )); }
    {unsigned int rating; rating = (unsigned int)(cgc_strlen ( tlv59 )); }
    {int tlv69; tlv69 = (int)(cgc_strlen ( tlv59 )); }
    {int tlv72; tlv72 = (int)(cgc_strlen ( tlv59 )); }
    {int tlv75; tlv75 = (int)(cgc_strlen ( tlv59 )); }
    {int tlv78; tlv78 = (int)(cgc_strlen ( tlv59 )); }
}
void fix_ingred_main_9_53(){
fix_ingred_main_9_53_0();
}
void fix_ingred_main_9_54_0(){
cgc_size_t tlv11;
    bzero(&tlv11,sizeof(cgc_size_t));
    {unsigned int movie_id; movie_id = (unsigned int)(1); }
    {unsigned int num_movies; num_movies = (unsigned int)(1); }
    {char * new_title; new_title = (char *)(1); }
    {char * new_desc; new_desc = (char *)(1); }
    {cgc_size_t tlv2; tlv2 = (cgc_size_t)(1); }
    {cgc_size_t tlv4; tlv4 = (cgc_size_t)(1); }
    {int tlv17; tlv17 = (int)(1); }
    {int tlv27; tlv27 = (int)(1); }
    {char * tlv26; tlv26 = (char *)(1); }
    {char tlv24; tlv24 = (char)(1); }
    {cgc_size_t tlv7; tlv7 = (cgc_size_t)(1); }
    {int tlv8; tlv8 = (int)(1); }
    {cgc_size_t tlv9; tlv9 = (cgc_size_t)(1); }
    {int tlv10; tlv10 = (int)(1); }
    {cgc_size_t tlv11; tlv11 = (cgc_size_t)(1); }
    {cgc_size_t tlv13; tlv13 = (cgc_size_t)(1); }
    {int tlv41; tlv41 = (int)(1); }
    {char * tlv40; tlv40 = (char *)(1); }
    {cgc_size_t tlv39; tlv39 = (cgc_size_t)(1); }
    {char tlv38; tlv38 = (char)(1); }
    {int tlv42; tlv42 = (int)(1); }
    {cgc_size_t tlv65; tlv65 = (cgc_size_t)(1); }
    {char * tlv33; tlv33 = (char *)(1); }
    {void * tlv34; tlv34 = (void *)(1); }
    {cgc_size_t tlv66; tlv66 = (cgc_size_t)(1); }
    {char * tlv36; tlv36 = (char *)(1); }
    {void * tlv37; tlv37 = (void *)(1); }
    {int tlv48; tlv48 = (int)(1); }
    {char * tlv47; tlv47 = (char *)(1); }
    {cgc_size_t tlv46; tlv46 = (cgc_size_t)(1); }
    {char tlv45; tlv45 = (char)(1); }
    {char * tlv52; tlv52 = (char *)(1); }
    {cgc_size_t tlv51; tlv51 = (cgc_size_t)(1); }
    {char tlv50; tlv50 = (char)(1); }
    {int tlv58; tlv58 = (int)(1); }
    {char * tlv57; tlv57 = (char *)(1); }
    {cgc_size_t tlv56; tlv56 = (cgc_size_t)(1); }
    {char tlv55; tlv55 = (char)(1); }
    {int tlv63; tlv63 = (int)(1); }
    {char * tlv62; tlv62 = (char *)(1); }
    {cgc_size_t tlv61; tlv61 = (cgc_size_t)(1); }
    {char tlv60; tlv60 = (char)(1); }
    {int new_year; new_year = (int)(1); }
    {int new_score; new_score = (int)(1); }
    {int tlv69; tlv69 = (int)(1); }
    {int tlv72; tlv72 = (int)(1); }
    {int tlv75; tlv75 = (int)(1); }
    {int tlv78; tlv78 = (int)(1); }
}
void fix_ingred_main_9_54_4(){
cgc_size_t tlv11;
    bzero(&tlv11,sizeof(cgc_size_t));
    {unsigned int movie_id; movie_id = (unsigned int)(tlv11); }
    {unsigned int num_movies; num_movies = (unsigned int)(tlv11); }
    {char * new_title; new_title = (char *)(tlv11); }
    {char * new_desc; new_desc = (char *)(tlv11); }
    {char buf [ 1024 ]; buf [ ( 1024 )-1 ] = (char)(tlv11); }
    {int tlv1; tlv1 = (int)(tlv11); }
    {cgc_size_t tlv2; tlv2 = (cgc_size_t)(tlv11); }
    {int tlv3; tlv3 = (int)(tlv11); }
    {cgc_size_t tlv4; tlv4 = (cgc_size_t)(tlv11); }
    {int finish; finish = (int)(tlv11); }
    {int tlv17; tlv17 = (int)(tlv11); }
    {int tlv22; tlv22 = (int)(tlv11); }
    {char * tlv21; tlv21 = (char *)(tlv11); }
    {cgc_size_t tlv20; tlv20 = (cgc_size_t)(tlv11); }
    {char tlv19; tlv19 = (char)(tlv11); }
    {int tlv27; tlv27 = (int)(tlv11); }
    {char * tlv26; tlv26 = (char *)(tlv11); }
    {cgc_size_t tlv25; tlv25 = (cgc_size_t)(tlv11); }
    {char tlv24; tlv24 = (char)(tlv11); }
    {int tlv5; tlv5 = (int)(tlv11); }
    {int tlv6; tlv6 = (int)(tlv11); }
    {cgc_size_t tlv7; tlv7 = (cgc_size_t)(tlv11); }
    {int tlv8; tlv8 = (int)(tlv11); }
    {cgc_size_t tlv9; tlv9 = (cgc_size_t)(tlv11); }
    {int tlv10; tlv10 = (int)(tlv11); }
    {int tlv12; tlv12 = (int)(tlv11); }
    {cgc_size_t tlv13; tlv13 = (cgc_size_t)(tlv11); }
    {int tlv41; tlv41 = (int)(tlv11); }
    {char * tlv40; tlv40 = (char *)(tlv11); }
    {cgc_size_t tlv39; tlv39 = (cgc_size_t)(tlv11); }
    {char tlv38; tlv38 = (char)(tlv11); }
    {int tlv42; tlv42 = (int)(tlv11); }
    {cgc_size_t tlv65; tlv65 = (cgc_size_t)(tlv11); }
    {char * tlv33; tlv33 = (char *)(tlv11); }
    {void * tlv34; tlv34 = (void *)(tlv11); }
    {cgc_size_t tlv66; tlv66 = (cgc_size_t)(tlv11); }
    {char * tlv36; tlv36 = (char *)(tlv11); }
    {void * tlv37; tlv37 = (void *)(tlv11); }
    {int tlv48; tlv48 = (int)(tlv11); }
    {char * tlv47; tlv47 = (char *)(tlv11); }
    {cgc_size_t tlv46; tlv46 = (cgc_size_t)(tlv11); }
    {char tlv45; tlv45 = (char)(tlv11); }
    {int tlv53; tlv53 = (int)(tlv11); }
    {char * tlv52; tlv52 = (char *)(tlv11); }
    {cgc_size_t tlv51; tlv51 = (cgc_size_t)(tlv11); }
    {char tlv50; tlv50 = (char)(tlv11); }
    {int tlv58; tlv58 = (int)(tlv11); }
    {char * tlv57; tlv57 = (char *)(tlv11); }
    {cgc_size_t tlv56; tlv56 = (cgc_size_t)(tlv11); }
    {char tlv55; tlv55 = (char)(tlv11); }
    {int tlv63; tlv63 = (int)(tlv11); }
    {char * tlv62; tlv62 = (char *)(tlv11); }
    {cgc_size_t tlv61; tlv61 = (cgc_size_t)(tlv11); }
    {char tlv60; tlv60 = (char)(tlv11); }
    {int new_year; new_year = (int)(tlv11); }
    {int new_score; new_score = (int)(tlv11); }
    {unsigned int genre; genre = (unsigned int)(tlv11); }
    {unsigned int rating; rating = (unsigned int)(tlv11); }
    {int tlv69; tlv69 = (int)(tlv11); }
    {int tlv72; tlv72 = (int)(tlv11); }
    {int tlv75; tlv75 = (int)(tlv11); }
    {int tlv78; tlv78 = (int)(tlv11); }
}
void fix_ingred_main_9_54(){
fix_ingred_main_9_54_0();
fix_ingred_main_9_54_4();
}
void fix_ingred_main_9_67_4(){
int tlv12;
    bzero(&tlv12,sizeof(int));
    {unsigned int movie_id; movie_id = (unsigned int)(tlv12); }
    {unsigned int num_movies; num_movies = (unsigned int)(tlv12); }
    {char * new_title; new_title = (char *)(tlv12); }
    {char * new_desc; new_desc = (char *)(tlv12); }
    {char buf [ 1024 ]; buf [ ( 1024 )-1 ] = (char)(tlv12); }
    {int tlv1; tlv1 = (int)(tlv12); }
    {cgc_size_t tlv2; tlv2 = (cgc_size_t)(tlv12); }
    {int tlv3; tlv3 = (int)(tlv12); }
    {cgc_size_t tlv4; tlv4 = (cgc_size_t)(tlv12); }
    {int finish; finish = (int)(tlv12); }
    {int tlv17; tlv17 = (int)(tlv12); }
    {int tlv22; tlv22 = (int)(tlv12); }
    {char * tlv21; tlv21 = (char *)(tlv12); }
    {cgc_size_t tlv20; tlv20 = (cgc_size_t)(tlv12); }
    {char tlv19; tlv19 = (char)(tlv12); }
    {int tlv27; tlv27 = (int)(tlv12); }
    {char * tlv26; tlv26 = (char *)(tlv12); }
    {cgc_size_t tlv25; tlv25 = (cgc_size_t)(tlv12); }
    {char tlv24; tlv24 = (char)(tlv12); }
    {int tlv5; tlv5 = (int)(tlv12); }
    {int tlv6; tlv6 = (int)(tlv12); }
    {cgc_size_t tlv7; tlv7 = (cgc_size_t)(tlv12); }
    {int tlv8; tlv8 = (int)(tlv12); }
    {cgc_size_t tlv9; tlv9 = (cgc_size_t)(tlv12); }
    {int tlv10; tlv10 = (int)(tlv12); }
    {cgc_size_t tlv11; tlv11 = (cgc_size_t)(tlv12); }
    {cgc_size_t tlv13; tlv13 = (cgc_size_t)(tlv12); }
    {int tlv41; tlv41 = (int)(tlv12); }
    {char * tlv40; tlv40 = (char *)(tlv12); }
    {cgc_size_t tlv39; tlv39 = (cgc_size_t)(tlv12); }
    {char tlv38; tlv38 = (char)(tlv12); }
    {int tlv42; tlv42 = (int)(tlv12); }
    {cgc_size_t tlv65; tlv65 = (cgc_size_t)(tlv12); }
    {char * tlv33; tlv33 = (char *)(tlv12); }
    {void * tlv34; tlv34 = (void *)(tlv12); }
    {cgc_size_t tlv66; tlv66 = (cgc_size_t)(tlv12); }
    {char * tlv36; tlv36 = (char *)(tlv12); }
    {void * tlv37; tlv37 = (void *)(tlv12); }
    {int tlv48; tlv48 = (int)(tlv12); }
    {char * tlv47; tlv47 = (char *)(tlv12); }
    {cgc_size_t tlv46; tlv46 = (cgc_size_t)(tlv12); }
    {char tlv45; tlv45 = (char)(tlv12); }
    {int tlv53; tlv53 = (int)(tlv12); }
    {char * tlv52; tlv52 = (char *)(tlv12); }
    {cgc_size_t tlv51; tlv51 = (cgc_size_t)(tlv12); }
    {char tlv50; tlv50 = (char)(tlv12); }
    {int tlv58; tlv58 = (int)(tlv12); }
    {char * tlv57; tlv57 = (char *)(tlv12); }
    {cgc_size_t tlv56; tlv56 = (cgc_size_t)(tlv12); }
    {char tlv55; tlv55 = (char)(tlv12); }
    {int tlv63; tlv63 = (int)(tlv12); }
    {char * tlv62; tlv62 = (char *)(tlv12); }
    {cgc_size_t tlv61; tlv61 = (cgc_size_t)(tlv12); }
    {char tlv60; tlv60 = (char)(tlv12); }
    {int new_year; new_year = (int)(tlv12); }
    {int new_score; new_score = (int)(tlv12); }
    {unsigned int genre; genre = (unsigned int)(tlv12); }
    {unsigned int rating; rating = (unsigned int)(tlv12); }
    {int tlv69; tlv69 = (int)(tlv12); }
    {int tlv72; tlv72 = (int)(tlv12); }
    {int tlv75; tlv75 = (int)(tlv12); }
    {int tlv78; tlv78 = (int)(tlv12); }
}
void fix_ingred_main_9_67(){
fix_ingred_main_9_67_4();
}
void fix_ingred_main_9_68_0(){
char tlv64_ref;
    bzero(&tlv64_ref,1*sizeof(char));
const char * tlv64 = &tlv64_ref;
    {unsigned int movie_id; movie_id = (unsigned int)(cgc_strlen ( tlv64 )); }
    {unsigned int num_movies; num_movies = (unsigned int)(cgc_strlen ( tlv64 )); }
    {char * new_title; new_title = (char *)(cgc_strlen ( tlv64 )); }
    {char * new_desc; new_desc = (char *)(cgc_strlen ( tlv64 )); }
    {char buf [ 1024 ]; buf [ ( 1024 )-1 ] = (char)(cgc_strlen ( tlv64 )); }
    {int tlv1; tlv1 = (int)(cgc_strlen ( tlv64 )); }
    {cgc_size_t tlv2; tlv2 = (cgc_size_t)(cgc_strlen ( tlv64 )); }
    {int tlv3; tlv3 = (int)(cgc_strlen ( tlv64 )); }
    {cgc_size_t tlv4; tlv4 = (cgc_size_t)(cgc_strlen ( tlv64 )); }
    {int finish; finish = (int)(cgc_strlen ( tlv64 )); }
    {int tlv17; tlv17 = (int)(cgc_strlen ( tlv64 )); }
    {int tlv22; tlv22 = (int)(cgc_strlen ( tlv64 )); }
    {char * tlv21; tlv21 = (char *)(cgc_strlen ( tlv64 )); }
    {cgc_size_t tlv20; tlv20 = (cgc_size_t)(cgc_strlen ( tlv64 )); }
    {char tlv19; tlv19 = (char)(cgc_strlen ( tlv64 )); }
    {int tlv27; tlv27 = (int)(cgc_strlen ( tlv64 )); }
    {char * tlv26; tlv26 = (char *)(cgc_strlen ( tlv64 )); }
    {cgc_size_t tlv25; tlv25 = (cgc_size_t)(cgc_strlen ( tlv64 )); }
    {char tlv24; tlv24 = (char)(cgc_strlen ( tlv64 )); }
    {int tlv5; tlv5 = (int)(cgc_strlen ( tlv64 )); }
    {int tlv6; tlv6 = (int)(cgc_strlen ( tlv64 )); }
    {cgc_size_t tlv7; tlv7 = (cgc_size_t)(cgc_strlen ( tlv64 )); }
    {int tlv8; tlv8 = (int)(cgc_strlen ( tlv64 )); }
    {cgc_size_t tlv9; tlv9 = (cgc_size_t)(cgc_strlen ( tlv64 )); }
    {int tlv10; tlv10 = (int)(cgc_strlen ( tlv64 )); }
    {cgc_size_t tlv11; tlv11 = (cgc_size_t)(cgc_strlen ( tlv64 )); }
    {int tlv12; tlv12 = (int)(cgc_strlen ( tlv64 )); }
    {cgc_size_t tlv13; tlv13 = (cgc_size_t)(cgc_strlen ( tlv64 )); }
    {int tlv41; tlv41 = (int)(cgc_strlen ( tlv64 )); }
    {char * tlv40; tlv40 = (char *)(cgc_strlen ( tlv64 )); }
    {cgc_size_t tlv39; tlv39 = (cgc_size_t)(cgc_strlen ( tlv64 )); }
    {char tlv38; tlv38 = (char)(cgc_strlen ( tlv64 )); }
    {int tlv42; tlv42 = (int)(cgc_strlen ( tlv64 )); }
    {cgc_size_t tlv65; tlv65 = (cgc_size_t)(cgc_strlen ( tlv64 )); }
    {char * tlv33; tlv33 = (char *)(cgc_strlen ( tlv64 )); }
    {void * tlv34; tlv34 = (void *)(cgc_strlen ( tlv64 )); }
    {cgc_size_t tlv66; tlv66 = (cgc_size_t)(cgc_strlen ( tlv64 )); }
    {char * tlv36; tlv36 = (char *)(cgc_strlen ( tlv64 )); }
    {void * tlv37; tlv37 = (void *)(cgc_strlen ( tlv64 )); }
    {int tlv48; tlv48 = (int)(cgc_strlen ( tlv64 )); }
    {char * tlv47; tlv47 = (char *)(cgc_strlen ( tlv64 )); }
    {cgc_size_t tlv46; tlv46 = (cgc_size_t)(cgc_strlen ( tlv64 )); }
    {char tlv45; tlv45 = (char)(cgc_strlen ( tlv64 )); }
    {int tlv53; tlv53 = (int)(cgc_strlen ( tlv64 )); }
    {char * tlv52; tlv52 = (char *)(cgc_strlen ( tlv64 )); }
    {cgc_size_t tlv51; tlv51 = (cgc_size_t)(cgc_strlen ( tlv64 )); }
    {char tlv50; tlv50 = (char)(cgc_strlen ( tlv64 )); }
    {int tlv58; tlv58 = (int)(cgc_strlen ( tlv64 )); }
    {char * tlv57; tlv57 = (char *)(cgc_strlen ( tlv64 )); }
    {cgc_size_t tlv56; tlv56 = (cgc_size_t)(cgc_strlen ( tlv64 )); }
    {char tlv55; tlv55 = (char)(cgc_strlen ( tlv64 )); }
    {int tlv63; tlv63 = (int)(cgc_strlen ( tlv64 )); }
    {char * tlv62; tlv62 = (char *)(cgc_strlen ( tlv64 )); }
    {cgc_size_t tlv61; tlv61 = (cgc_size_t)(cgc_strlen ( tlv64 )); }
    {char tlv60; tlv60 = (char)(cgc_strlen ( tlv64 )); }
    {int new_year; new_year = (int)(cgc_strlen ( tlv64 )); }
    {int new_score; new_score = (int)(cgc_strlen ( tlv64 )); }
    {unsigned int genre; genre = (unsigned int)(cgc_strlen ( tlv64 )); }
    {unsigned int rating; rating = (unsigned int)(cgc_strlen ( tlv64 )); }
    {int tlv69; tlv69 = (int)(cgc_strlen ( tlv64 )); }
    {int tlv72; tlv72 = (int)(cgc_strlen ( tlv64 )); }
    {int tlv75; tlv75 = (int)(cgc_strlen ( tlv64 )); }
    {int tlv78; tlv78 = (int)(cgc_strlen ( tlv64 )); }
}
void fix_ingred_main_9_68(){
fix_ingred_main_9_68_0();
}
void fix_ingred_main_9_69_5(){
cgc_size_t tlv13;
    bzero(&tlv13,sizeof(cgc_size_t));
    {unsigned int movie_id; movie_id = (unsigned int)(tlv13); }
    {unsigned int num_movies; num_movies = (unsigned int)(tlv13); }
    {char * new_title; new_title = (char *)(tlv13); }
    {char * new_desc; new_desc = (char *)(tlv13); }
    {char buf [ 1024 ]; buf [ ( 1024 )-1 ] = (char)(tlv13); }
    {int tlv1; tlv1 = (int)(tlv13); }
    {cgc_size_t tlv2; tlv2 = (cgc_size_t)(tlv13); }
    {int tlv3; tlv3 = (int)(tlv13); }
    {cgc_size_t tlv4; tlv4 = (cgc_size_t)(tlv13); }
    {int finish; finish = (int)(tlv13); }
    {int tlv17; tlv17 = (int)(tlv13); }
    {int tlv22; tlv22 = (int)(tlv13); }
    {char * tlv21; tlv21 = (char *)(tlv13); }
    {cgc_size_t tlv20; tlv20 = (cgc_size_t)(tlv13); }
    {char tlv19; tlv19 = (char)(tlv13); }
    {int tlv27; tlv27 = (int)(tlv13); }
    {char * tlv26; tlv26 = (char *)(tlv13); }
    {cgc_size_t tlv25; tlv25 = (cgc_size_t)(tlv13); }
    {char tlv24; tlv24 = (char)(tlv13); }
    {int tlv5; tlv5 = (int)(tlv13); }
    {int tlv6; tlv6 = (int)(tlv13); }
    {cgc_size_t tlv7; tlv7 = (cgc_size_t)(tlv13); }
    {int tlv8; tlv8 = (int)(tlv13); }
    {cgc_size_t tlv9; tlv9 = (cgc_size_t)(tlv13); }
    {int tlv10; tlv10 = (int)(tlv13); }
    {cgc_size_t tlv11; tlv11 = (cgc_size_t)(tlv13); }
    {int tlv12; tlv12 = (int)(tlv13); }
    {int tlv41; tlv41 = (int)(tlv13); }
    {char * tlv40; tlv40 = (char *)(tlv13); }
    {cgc_size_t tlv39; tlv39 = (cgc_size_t)(tlv13); }
    {char tlv38; tlv38 = (char)(tlv13); }
    {int tlv42; tlv42 = (int)(tlv13); }
    {cgc_size_t tlv65; tlv65 = (cgc_size_t)(tlv13); }
    {char * tlv33; tlv33 = (char *)(tlv13); }
    {void * tlv34; tlv34 = (void *)(tlv13); }
    {cgc_size_t tlv66; tlv66 = (cgc_size_t)(tlv13); }
    {char * tlv36; tlv36 = (char *)(tlv13); }
    {void * tlv37; tlv37 = (void *)(tlv13); }
    {int tlv48; tlv48 = (int)(tlv13); }
    {char * tlv47; tlv47 = (char *)(tlv13); }
    {cgc_size_t tlv46; tlv46 = (cgc_size_t)(tlv13); }
    {char tlv45; tlv45 = (char)(tlv13); }
    {int tlv53; tlv53 = (int)(tlv13); }
    {char * tlv52; tlv52 = (char *)(tlv13); }
    {cgc_size_t tlv51; tlv51 = (cgc_size_t)(tlv13); }
    {char tlv50; tlv50 = (char)(tlv13); }
    {int tlv58; tlv58 = (int)(tlv13); }
    {char * tlv57; tlv57 = (char *)(tlv13); }
    {cgc_size_t tlv56; tlv56 = (cgc_size_t)(tlv13); }
    {char tlv55; tlv55 = (char)(tlv13); }
    {int tlv63; tlv63 = (int)(tlv13); }
    {char * tlv62; tlv62 = (char *)(tlv13); }
    {cgc_size_t tlv61; tlv61 = (cgc_size_t)(tlv13); }
    {char tlv60; tlv60 = (char)(tlv13); }
    {int new_year; new_year = (int)(tlv13); }
    {int new_score; new_score = (int)(tlv13); }
    {unsigned int genre; genre = (unsigned int)(tlv13); }
    {unsigned int rating; rating = (unsigned int)(tlv13); }
    {int tlv69; tlv69 = (int)(tlv13); }
    {int tlv72; tlv72 = (int)(tlv13); }
    {int tlv75; tlv75 = (int)(tlv13); }
    {int tlv78; tlv78 = (int)(tlv13); }
}
void fix_ingred_main_9_69(){
fix_ingred_main_9_69_5();
}
void fix_ingred_main_9(){
fix_ingred_main_9_0();
fix_ingred_main_9_3();
fix_ingred_main_9_7();
fix_ingred_main_9_8();
fix_ingred_main_9_9();
fix_ingred_main_9_10();
fix_ingred_main_9_12();
fix_ingred_main_9_15();
fix_ingred_main_9_16();
fix_ingred_main_9_17();
fix_ingred_main_9_19();
fix_ingred_main_9_20();
fix_ingred_main_9_22();
fix_ingred_main_9_24();
fix_ingred_main_9_25();
fix_ingred_main_9_26();
fix_ingred_main_9_28();
fix_ingred_main_9_29();
fix_ingred_main_9_31();
fix_ingred_main_9_34();
fix_ingred_main_9_35();
fix_ingred_main_9_36();
fix_ingred_main_9_38();
fix_ingred_main_9_43();
fix_ingred_main_9_44();
fix_ingred_main_9_45();
fix_ingred_main_9_47();
fix_ingred_main_9_52();
fix_ingred_main_9_53();
fix_ingred_main_9_54();
fix_ingred_main_9_67();
fix_ingred_main_9_68();
fix_ingred_main_9_69();
}
void fix_ingred_main_10(){
}
void fix_ingred_main_11_0_0(){
    {int admin_mode; admin_mode = (int)(0); }
    {char buf [ 4096 ]; buf [ ( 4096 )-1 ] = (char)(0); }
    {char* welcome ; welcome  = (char*)(0); }
    {char* menu ; menu  = (char*)(0); }
    {char* admin_menu ; admin_menu  = (char*)(0); }
    {int tlv11; tlv11 = (int)(0); }
    {char * tlv10; tlv10 = (char *)(0); }
    {char tlv8; tlv8 = (char)(0); }
}
void fix_ingred_main_11_0(){
fix_ingred_main_11_0_0();
}
void fix_ingred_main_11_4_0(){
char buf [ 4096 ];
    bzero(&buf,( 4096 *sizeof(char) ) );
    {int admin_mode; admin_mode = (int)(STDIN); }
    {char buf [ 4096 ]; buf [ ( 4096 )-1 ] = (char)(STDIN); }
    {char* welcome ; welcome  = (char*)(STDIN); }
    {char* menu ; menu  = (char*)(STDIN); }
    {char* admin_menu ; admin_menu  = (char*)(STDIN); }
    {int tlv11; tlv11 = (int)(STDIN); }
    {char * tlv10; tlv10 = (char *)(STDIN); }
    {char tlv8; tlv8 = (char)(STDIN); }
}
void fix_ingred_main_11_4_1(){
char buf [ 4096 ];
    bzero(&buf,( 4096 *sizeof(char) ) );
    {int admin_mode; admin_mode = (int)(buf); }
    {char buf [ 4096 ]; buf [ ( 4096 )-1 ] = (char)(buf); }
    {char* welcome ; welcome  = (char*)(buf); }
    {char* menu ; menu  = (char*)(buf); }
    {char* admin_menu ; admin_menu  = (char*)(buf); }
    {int tlv11; tlv11 = (int)(buf); }
    {char * tlv10; tlv10 = (char *)(buf); }
    {char tlv8; tlv8 = (char)(buf); }
}
void fix_ingred_main_11_4_2(){
char buf [ 4096 ];
    bzero(&buf,( 4096 *sizeof(char) ) );
    {int admin_mode; admin_mode = (int)(sizeof ( buf )); }
    {char buf [ 4096 ]; buf [ ( 4096 )-1 ] = (char)(sizeof ( buf )); }
    {char* welcome ; welcome  = (char*)(sizeof ( buf )); }
    {char* menu ; menu  = (char*)(sizeof ( buf )); }
    {char* admin_menu ; admin_menu  = (char*)(sizeof ( buf )); }
    {int tlv11; tlv11 = (int)(sizeof ( buf )); }
    {char * tlv10; tlv10 = (char *)(sizeof ( buf )); }
    {char tlv8; tlv8 = (char)(sizeof ( buf )); }
}
void fix_ingred_main_11_4_3(){
char buf [ 4096 ];
    bzero(&buf,( 4096 *sizeof(char) ) );
    {int admin_mode; admin_mode = (int)('\n'); }
    {char buf [ 4096 ]; buf [ ( 4096 )-1 ] = (char)('\n'); }
    {char* welcome ; welcome  = (char*)('\n'); }
    {char* menu ; menu  = (char*)('\n'); }
    {char* admin_menu ; admin_menu  = (char*)('\n'); }
    {int tlv11; tlv11 = (int)('\n'); }
    {char * tlv10; tlv10 = (char *)('\n'); }
    {char tlv8; tlv8 = (char)('\n'); }
}
void fix_ingred_main_11_4(){
fix_ingred_main_11_4_0();
fix_ingred_main_11_4_1();
fix_ingred_main_11_4_2();
fix_ingred_main_11_4_3();
}
void fix_ingred_main_11_5_1(){
int tlv1;
    bzero(&tlv1,sizeof(int));
    {int admin_mode; admin_mode = (int)(tlv1); }
    {char buf [ 4096 ]; buf [ ( 4096 )-1 ] = (char)(tlv1); }
    {char* welcome ; welcome  = (char*)(tlv1); }
    {char* menu ; menu  = (char*)(tlv1); }
    {char* admin_menu ; admin_menu  = (char*)(tlv1); }
    {int tlv11; tlv11 = (int)(tlv1); }
    {char * tlv10; tlv10 = (char *)(tlv1); }
    {char tlv8; tlv8 = (char)(tlv1); }
}
void fix_ingred_main_11_5(){
fix_ingred_main_11_5_1();
}
void fix_ingred_main_11_15_1(){
int tlv2;
    bzero(&tlv2,sizeof(int));
    {int admin_mode; admin_mode = (int)(tlv2); }
    {char buf [ 4096 ]; buf [ ( 4096 )-1 ] = (char)(tlv2); }
    {char* welcome ; welcome  = (char*)(tlv2); }
    {char* menu ; menu  = (char*)(tlv2); }
    {char* admin_menu ; admin_menu  = (char*)(tlv2); }
    {int tlv11; tlv11 = (int)(tlv2); }
    {char * tlv10; tlv10 = (char *)(tlv2); }
    {cgc_size_t tlv9; tlv9 = (cgc_size_t)(tlv2); }
    {char tlv8; tlv8 = (char)(tlv2); }
}
void fix_ingred_main_11_15(){
fix_ingred_main_11_15_1();
}
void fix_ingred_main_11(){
fix_ingred_main_11_0();
fix_ingred_main_11_4();
fix_ingred_main_11_5();
fix_ingred_main_11_15();
}
