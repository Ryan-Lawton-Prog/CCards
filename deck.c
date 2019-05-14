#include "deck.h"

deck_t create_deck(){
  deck_t temp; 
  temp = (deck_t)malloc(sizeof(struct deck));
  strcpy(temp->name, "");
  temp->cards = NULL;
  temp->next = NULL;
  return temp;
}

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

void get_deck_name(deck_t n, char name[]){
  strcpy(name, n->name);
}

card_t get_deck_cards(deck_t n){
  return n->cards;
}

void set_deck_data(deck_t n, const char name[], card_t cards){
  strcpy(n->name, name);
  n->cards = cards;
}

void get_deck_name_i(deck_t n, int pos, char name[]){
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

card_t get_deck_cards(deck_t n, int pos){
  card_t temp;
  temp = n;
  int i;
  for(i = 0; i < get_size(n); i++){
    if(i == pos){
      return n->cards;
      return;
    }
    temp = temp->next;
  }
  return NULL;
}

void set_deck_data_i(deck_t n, int pos, const char name[], card_t cards){
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

deck_t get_next_deck(deck_t n){
  return n->next;
}

int get_deck_size(deck_t n){
  if(n->next == NULL){
    return 1;
  }
  return get_deck_size(n->next) + 1;
}