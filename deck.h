#ifndef DECK_H
#define DECK_H

#include "cards.h"
#include "user.h"

#define MAX_DECK_NAME_LENGTH 50
#define MAX_AUTHOR_LENGTH 40
#define MAX_OWNER_NAME_LENGTH 40
#define DB_DECKS "DB_DECKS"
#define DB_COMMUNITY_DECKS "DB_COMMUNITY_DECKS"
#define DB_TEMP "DB_TEMP"

/*******************************************************************************
 * deck struct - used as a linked list for storing each deck without having
 * to set re-adjust the size of a deck array or setting a maximum
*******************************************************************************/
struct deck{
    card_t cards;
    char name[MAX_DECK_NAME_LENGTH+1];
    char author[MAX_AUTHOR_LENGTH+1];
    char owner[MAX_OWNER_NAME_LENGTH+1];
    int is_public;
    int played;
    double accuracy;
    struct deck * next;
};
typedef struct deck * deck_t;


/*******************************************************************************
 * Function prototypes
*******************************************************************************/
deck_t create_deck();
deck_t add_deck(deck_t, const char[], const char[], 
    const char[], int, int, double, card_t);
deck_t insert_deck(deck_t);
void get_name(deck_t, char[]);
void get_name_at(deck_t, int, char[]);
card_t get_cards(deck_t);
card_t get_cards_at(deck_t, int);
void set_deck(deck_t, const char[], card_t);
void set_deck_at(deck_t, int, const char[], card_t);
int get_played(deck_t);
int get_played_at(deck_t, int);
double get_accuracy(deck_t);
double get_accuracy_at(deck_t, int);
void get_author(deck_t, char[]);
void get_author_at(deck_t, int, char[]);
void get_owner(deck_t, char[]);
void get_owner_at(deck_t, int, char[]);
void set_owner(deck_t, const char[]);
void update_stats(deck_t, int);
void update_stats_at(deck_t, int, int);
void edit_deck_db(deck_t, const char[]);
int get_deck_size(deck_t);
deck_t get_next_deck(deck_t);
void update_deck_db(deck_t);
deck_t get_last_deck(deck_t);
deck_t load_community_decks();
deck_t load_user_decks(user_t);
void save_community_decks(deck_t);
int check_deck_exists(const char[]);

#endif