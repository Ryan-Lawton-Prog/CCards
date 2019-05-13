#include "cards.h"

card_t*card_head(const char question[], const char description[]){
  card_t*n;
  strcpy(n->question, question);
  strcpy(n->description, description);
  n->next = NULL;
  return n;
}

card_t*card_next(const char question[], const char description[], card_t * head){
  if(getNext(head) == NULL){
    card_t*n;
    strcpy(n->question, question);
    strcpy(n->description, description);
    n->next = head;
    return n;
  }else{
    return card_next(question, description, head);
  }
}

void get_question(card_t*n, char question[]){
  strcpy(question, n->question);
}

void get_description(card_t*n, char description[]){
  strcpy(description, n->description);
}

void set_data(char question[], char description[], card_t*n){
  strcpy(n->question, question);
  strcpy(n->description, description);
}

card_t*get_next(card_t*n){
  return n->next;
}

int get_size(card_t*n){
  if(n->next == NULL){
    return 1;
  }
  return getSize(n->next) + 1;
}