#ifndef DECK_H
#define DECK_H

#include "cards.h"

#define MAX_DECK_NAME_LENGTH 50

struct deck{
  char name[MAX_DECK_NAME_LENGTH];
  card_t cards;
  struct deck * next;
};
typedef struct deck * deck_t;

deck_t create_deck();
deck_t add_deck(deck_t, const char[], card_t);
void get_name(deck_t, char[]);
card_t get_cards(deck_t);
void set_deck_data(deck_t, const char[], card_t);
void get_name_i(deck_t, int, char[]);
card_t get_cards_i(deck_t, int);
void set_deck_data_i(deck_t, int, const char[], card_t);
deck_t get_next_deck(deck_t);
int get_deck_size(deck_t);

#endif