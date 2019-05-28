#ifndef CARDS_H
#define CARDS_H

#include <stdio.h>  /*scanf, printf, fopen*/
#include <string.h> /*strcmp, strcpy, strlen*/
#include <stdlib.h> /*fprintf, fscanf, sscanf*/
#include <math.h>

#define MAX_CARD_QUESTION_LENGTH 200
#define MAX_CARD_ANSWER_LENGTH 100
#define MAX_INPUT_LENGTH 100

/*******************************************************************************
 * card struct - used as a linked list for storing a list of cards for a deck
*******************************************************************************/
struct card{
    char question[MAX_CARD_QUESTION_LENGTH+1];
    char answer[MAX_CARD_ANSWER_LENGTH+1];
    struct card * next;
};
typedef struct card * card_t;


/*******************************************************************************
 * Function prototypes
*******************************************************************************/
card_t create_card();
card_t add_card(card_t, const char[], const char[]);
void get_question(card_t, char[]);
void get_answer(card_t, char[]);
void set_card(card_t, const char[], const char[]);
card_t get_card_at(card_t, int);
void get_question_at(card_t, int, char[]);
void get_answer_at(card_t, int, char[]);
void set_card_at(card_t, int, const char[], const char[]);
card_t get_next(card_t);
int get_size(card_t);
void remove_card_at(card_t, int, int);
card_t copy_cards(card_t card);

#endif