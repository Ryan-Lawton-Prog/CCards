#ifndef CARDS_H
#define CARDS_H

#include <stdio.h>  /*scanf, printf, fopen*/
#include <string.h> /*strcmp, strcpy, strlen*/
#include <stdlib.h> /*fprintf, fscanf, sscanf*/

#define MAX_CARD_QUESTION_LENGTH 20
#define MAX_CARD_ANSWER_LENGTH 100

struct card{
  char question[MAX_CARD_QUESTION_LENGTH+1];
  char answer[MAX_CARD_ANSWER_LENGTH+1];
  struct card * next;
};
typedef struct card *card_t;

struct deck{
  card_t top_of_deck;
  struct deck * next;
};
typedef struct deck deck_t;

card_t create_card();
card_t add_card(card_t, const char[], const char[]);
void get_question(card_t, char[]);
void get_answer(card_t, char[]);
void set_data(card_t, const char[], const char[]);
void get_question_i(card_t, int, char[]);
void get_answer_i(card_t, int, char[]);
void set_data_i(card_t, int, const char[], const char[]);
card_t get_next(card_t);
int get_size(card_t);

#endif