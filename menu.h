#ifndef MENU_H
#define MENU_H

#include "deck.h"
#include "user.h"

/*******************************************************************************
 * Function prototypes
*******************************************************************************/
void print_red(const char[], int);
void print_green(const char[], int);
void print_yellow(const char[], int);
void clear_screen();
void print_menu();
void print_login();
void print_community_deck(deck_t);
void print_community_decks(deck_t);
void wait();
void print_invalid_deck();
void print_invalid_command();
void print_card_creation();

#endif
