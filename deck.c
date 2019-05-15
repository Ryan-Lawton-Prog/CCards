#include "deck.h"

/*******************************************************************************
 * Used to create an empty deck ready for processing
 * inputs:
 * - none
 * outputs:
 * - deck_t
*******************************************************************************/
deck_t create_deck(){
  deck_t temp; 
  temp = (deck_t)malloc(sizeof(struct deck));
  strcpy(temp->name, "");
  temp->cards = NULL;
  temp->next = NULL;
  return temp;
}

/*******************************************************************************
 * Used to add a deck to the deck heap (deck is defined here)
 * inputs:
 * - deck_t (Top of deck heap), string (name for deck), card_t (top of card heap)
 * outputs:
 * - deck_t (Top of deck heap)
*******************************************************************************/
deck_t add_deck(deck_t head, const char name[], card_t cards){
  deck_t temp,p;
  temp = create_deck();
  strcpy(temp->name,name);
  temp->cards = cards;
  if(!strcmp(head->name, "")){
    head = temp; 
  }
  else{
    p  = head;
    while(p->next != NULL){
      p = p->next;
    }
      p->next = temp;
  }
  return head;
}

/*******************************************************************************
 * get name from the deck 'n' and write it to the given array
 * inputs:
 * - deck_t, string
 * outputs:
 * - none
*******************************************************************************/
void get_name(deck_t n, char name[]){
  strcpy(name, n->name);
}

/*******************************************************************************
 * get cards from the deck 'n' and return the top of the card heap
 * inputs:
 * - deck_t
 * outputs:
 * - card_t
*******************************************************************************/
card_t get_cards(deck_t n){
  return n->cards;
}

/*******************************************************************************
 * set the name and cards parameter of a given deck 'n'
 * inputs:
 * - deck_t, string (name), card_t (top of card heap)
 * outputs:
 * - none
*******************************************************************************/
void set_deck(deck_t n, const char name[], card_t cards){
  strcpy(n->name, name);
  n->cards = cards;
}

/*******************************************************************************
 * get name in position 'pos' from the
 * sequence of decks from the top of the stack 'n'
 * inputs:
 * - deck_t, int, string (name)
 * outputs:
 * - none
*******************************************************************************/
void get_name_at(deck_t n, int pos, char name[]){
  deck_t temp;
  temp = n;
  int i;
  for(i = 0; i < get_deck_size(n); i++){
    if(i == pos){
      strcpy(name, temp->name);
      return;
    }
    temp = temp->next;
  }
  strcpy(name, "invalid index");
}

/*******************************************************************************
 * get cards in position 'pos' from the
 * sequence of decks from the top of the stack 'n'
 * inputs:
 * - deck_t, pos
 * outputs:
 * - card_t (top of heap)
*******************************************************************************/
card_t get_cards_at(deck_t n, int pos){
  deck_t temp;
  temp = n;
  int i;
  for(i = 0; i < get_deck_size(n); i++){
    if(i == pos){
      return n->cards;
    }
    temp = temp->next;
  }
  return NULL;
}

/*******************************************************************************
 * set name and cards in position 'pos' from the
 * sequence of decks from the top of the stack 'n'
 * inputs:
 * - deck_t, int, string (name), card_t (top of stack)
 * outputs:
 * - none
*******************************************************************************/
void set_deck_at(deck_t n, int pos, const char name[], card_t cards){
  deck_t temp;
  temp = n;
  int i;
  for(i = 0; i < get_deck_size(n); i++){
    if(i == pos){
      strcpy(temp->name, name);
      temp->cards = cards;
      return;
    }
    temp = temp->next;
  }
}

/*******************************************************************************
 * get next deck in the linked deck list
 * inputs:
 * - deck_t
 * outputs:
 * - deck_t (next deck)
*******************************************************************************/
deck_t get_next_deck(deck_t n){
  return n->next;
}

/*******************************************************************************
 * get how many decks there are in a heap
 * inputs:
 * - deck_t (top of heap)
 * outputs:
 * - int (amount of decks)
*******************************************************************************/
int get_deck_size(deck_t n){
  if(n->next == NULL){
    return 1;
  }
  return get_deck_size(n->next) + 1;
}