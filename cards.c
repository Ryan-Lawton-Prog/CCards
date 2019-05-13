#include "cards.h"

card_t create_card(){
  card_t temp; 
  temp = (card_t)malloc(sizeof(struct card));
  strcpy(temp->question, "");
  strcpy(temp->answer, "");
  temp->next = NULL;
  return temp;
}

card_t add_card(card_t head, const char question[], const char answer[]){
  card_t temp,p;
  temp = create_card();
  strcpy(temp->question,question);
  strcpy(temp->answer,answer);
  if(!strcmp(head->question, "")){
    printf("test");
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

void get_question(card_t n, char question[]){
  strcpy(question, n->question);
}

void get_answer(card_t n, char answer[]){
  strcpy(answer, n->answer);
}

void set_data(card_t n, const char question[], const char answer[]){
  strcpy(n->question, question);
  strcpy(n->answer, answer);
}

void get_question_i(card_t n, int pos, char question[]){
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

void get_answer_i(card_t n, int pos, char answer[]){
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

void set_data_i(card_t n, int pos, const char question[], const char answer[]){
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
  strcpy(temp->question, "invalid index");
  strcpy(temp->answer, "invalid index");
}

card_t get_next(card_t n){
  return n->next;
}

int get_size(card_t n){
  if(n->next == NULL){
    return 1;
  }
  return get_size(n->next) + 1;
}