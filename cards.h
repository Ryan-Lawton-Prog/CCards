#ifndef CARDS_H
#define CARDS_H

#include <stdio.h>  /*scanf, printf, fopen*/
#include <string.h> /*strcmp, strcpy, strlen*/
#include <stdlib.h> /*fprintf, fscanf, sscanf*/

#define MAX_CARD_QUESTION_LENGTH 20
#define MAX_CARD_DESCRIPTION_LENGTH 100

struct card{
  char question[MAX_CARD_QUESTION_LENGTH+1];
  char description[MAX_CARD_DESCRIPTION_LENGTH+1];
  struct card * next;
};
typedef struct card card_t;

struct deck{
  card_t top_of_deck;
  struct deck * next;
};
typedef struct deck deck_t;

extern card_t*card_head(const char[], const char[]);
extern card_t*card_next(const char[], const char[], card_t*);
extern void get_question(card_t*, char[]);
extern void get_description(card_t*, char[]);
extern void set_data(const char[], const char[], card_t*);
extern card_t*get_next(card_t*);
extern int get_size(card_t*);

#endif