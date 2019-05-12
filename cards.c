#include "cards.h"

card_t card(char[] data){
  card_t n = NULL;
  n->data = data;
  return n;
}

card_t card(char[] data, card_t * next){
  card_t n = NULL;
  n->data = data;
  n->next = next;
  return n;
}

char[] getData(card_t n){
  return n->data;
}

char[] setData(char[] data, card_t * n){
  return n->data = data;
}

card_t getNext(card_t n){
  return n->next;
}

int getSize(card_t n){
  if(n->next == NULL){
    return 1;
  }
  return getSize(n->next) + 1;
}