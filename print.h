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
void print_blue(const char[], int);
void clear_screen();
void print_menu();
void print_login_menu();
void print_community_deck(deck_t);
void print_community_decks(deck_t);
void print_community_cards(deck_t,  int);
void print_community_card(card_t, int);
void print_user_deck(deck_t);
void print_user_decks(deck_t);
void print_user_cards(deck_t);
void print_user_card(card_t); 
void print_deck_menu(deck_t);
void wait();
void neutral_wait();
void neutral_wait_pre();
void print_invalid_deck();
void print_invalid_command();
void print_card_creation();
void print_add_deck();
void print_existing_account(user_t*);
void print_card_question(card_t);
int print_card_answer(card_t, const char[]);
void print_correct(deck_t, int, user_t);
void print_edit_deck(deck_t, int);
void print_delete_deck();

#endif
