#ifndef CARDS_H
#define CARDS_H

#include <stdio.h>  /*scanf, printf, fopen*/
#include <string.h> /*strcmp, strcpy, strlen*/
#include <stdlib.h> /*fprintf, fscanf, sscanf*/
#include "linkedList.h"


struct card{
  char[] data;
  struct card * next;
};
typedef card card_t

struct deck{
  card_t[] cards;
  struct deck * next;
};
typedef deck deck_t

card_t card(char[] data);
card_t card(char[] data, card_t * next);
char[] getData(card_t n);
char[] setData(char[] data, card_t * n);
card_t getNext(card_t n);
int getSize(card_t n);

#endif