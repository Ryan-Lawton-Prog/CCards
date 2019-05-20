#include "test.h"

void test_add_card(){
  card_t top = add_card(create_card(), "What is 1 + 1", "2");
  add_card(top, "test 2", "q2");
  add_card(top, "test 3", "q3");
  int i;
  card_t temp = top;
  char question[MAX_CARD_QUESTION_LENGTH];
  char answer[MAX_CARD_ANSWER_LENGTH];
  for(i = 0; i < get_size(top); i++){
    get_question_at(top, i, question);
    get_answer(temp, answer);
    printf("%s : %s\n", question, answer);
    temp = temp->next;
  }
}

void test_community_decks(deck_t deck){
  deck_t temp = deck;
  card_t temp_card = deck->cards;
  int i;
  for(i = 0; i < get_deck_size(deck); i++){
    if(i != 0){
      temp = temp->next;
      temp_card = temp->cards;
    }
    printf("NAME: %s\n", temp->name);
    printf("AUTHOR: %s\n", temp->author);
    printf("OWNER: %s\n", temp->owner);
    printf("IS PUBLIC: %d\n", temp->is_public);
    printf("PLAYED: %d\n", temp->played);
    printf("ACCURACY: %lf\n", temp->accuracy);
    int j;
    printf("CARD SIZE: %d\n", get_size(temp_card));
    for(j = 0; j < get_size(temp->cards); j++){
      printf(" QUESTION: %s\n", temp_card->question);
      printf("  ANSWER: %s\n", temp_card->answer);
      temp_card = temp_card->next;
    }
  }
}

void test_add_user(){
    user_t user;
    strcpy(user.fullname, "Ryan Lawton");
    strcpy(user.username, "Lawyer");
    strcpy(user.password, "password");
    update_user_db(user);
}