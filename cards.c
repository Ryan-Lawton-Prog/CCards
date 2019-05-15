#include "cards.h"

/*******************************************************************************
 * Used to create an empty card ready for processing
 * inputs:
 * - none
 * outputs:
 * - card_t
*******************************************************************************/
card_t create_card(){
  card_t temp; 
  temp = (card_t)malloc(sizeof(struct card));
  strcpy(temp->question, "");
  strcpy(temp->answer, "");
  temp->next = NULL;
  return temp;
}

/*******************************************************************************
 * Used to add a card to the card heap (card is defined here)
 * inputs:
 * - card_t (Top of card heap), string (question for card), string (answer for card)
 * outputs:
 * - card_t (Top of card heap)
*******************************************************************************/
card_t add_card(card_t head, const char question[], const char answer[]){
  card_t temp,p;
  temp = create_card();
  strcpy(temp->question,question);
  strcpy(temp->answer,answer);
  if(!strcmp(head->question, "")){
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
 * get question from the card 'n' and write it to the given array
 * inputs:
 * - card_t, string
 * outputs:
 * - none
*******************************************************************************/
void get_question(card_t n, char question[]){
  strcpy(question, n->question);
}

/*******************************************************************************
 * get answer from the card 'n' and write it to the given array
 * inputs:
 * - card_t, string
 * outputs:
 * - none
*******************************************************************************/
void get_answer(card_t n, char answer[]){
  strcpy(answer, n->answer);
}

/*******************************************************************************
 * set the question and answer parameter of a given card 'n'
 * inputs:
 * - card_t, string (question), string (answer)
 * outputs:
 * - none
*******************************************************************************/
void set_card(card_t n, const char question[], const char answer[]){
  strcpy(n->question, question);
  strcpy(n->answer, answer);
}

/*******************************************************************************
 * get question in position 'pos' from the
 * sequence of cards from the top of the stack 'n'
 * inputs:
 * - card_t, int, string (question)
 * outputs:
 * - none
*******************************************************************************/
void get_question_at(card_t n, int pos, char question[]){
  card_t temp;
  temp = n;
  int i;
  for(i = 0; i < get_size(n); i++){
    if(i == pos){
      strcpy(question, temp->question);
      return;
    }
    temp = temp->next;
  }
  strcpy(question, "invalid index");
}

/*******************************************************************************
 * get answer in position 'pos' from the
 * sequence of cards from the top of the stack 'n'
 * inputs:
 * - card_t, int, string (answer)
 * outputs:
 * - none
*******************************************************************************/
void get_answer_at(card_t n, int pos, char answer[]){
  card_t temp;
  temp = n;
  int i;
  for(i = 0; i < get_size(n); i++){
    if(i == pos){
      strcpy(answer, temp->answer);
      return;
    }
    temp = temp->next;
  }
  strcpy(answer, "invalid index");
}

/*******************************************************************************
 * set question and answer in position 'pos' from the
 * sequence of cards from the top of the stack 'n'
 * inputs:
 * - card_t, int, string (question), string (answer)
 * outputs:
 * - none
*******************************************************************************/
void set_card_at(card_t n, int pos, const char question[], const char answer[]){
  card_t temp;
  temp = n;
  int i;
  for(i = 0; i < get_size(n); i++){
    if(i == pos){
      strcpy(temp->question, question);
      strcpy(temp->answer, answer);
      return;
    }
    temp = temp->next;
  }
}

/*******************************************************************************
 * get next card in the linked card list
 * inputs:
 * - card_t
 * outputs:
 * - card_t (next card)
*******************************************************************************/
card_t get_next(card_t n){
  return n->next;
}

/*******************************************************************************
 * get how many cards there are in a heap
 * inputs:
 * - card_t (top of heap)
 * outputs:
 * - int (amount of cards)
*******************************************************************************/
int get_size(card_t n){
  if(n->next == NULL){
    return 1;
  }
  return get_size(n->next) + 1;
}