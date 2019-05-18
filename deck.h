#ifndef DECK_H
#define DECK_H

#include "cards.h"

#define MAX_DECK_NAME_LENGTH 50

/*******************************************************************************
 * deck struct - used as a linked list for storing each deck without having
 * to set re-adjust the size of a deck array or setting a maximum
*******************************************************************************/
struct deck{
  char name[MAX_DECK_NAME_LENGTH+1];
  card_t cards;
  /* add stat information */
  struct deck * next;
};
typedef struct deck * deck_t;


/*******************************************************************************
 * Function prototypes
*******************************************************************************/
deck_t create_deck();
deck_t add_deck(deck_t, const char[], card_t);
void get_name(deck_t, char[]);
card_t get_cards(deck_t);
void set_deck(deck_t, const char[], card_t);
void get_name_at(deck_t, int, char[]);
card_t get_cards_at(deck_t, int);
void set_deck_at(deck_t, int, const char[], card_t);
deck_t get_next_deck(deck_t);
int get_deck_size(deck_t);

#endif