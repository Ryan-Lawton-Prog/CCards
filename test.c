#include "deck.h"

void test_add_card(){
  card_t top = add_card(create_card(), "What is 1 + 1", "2");
  add_card(top, "test 2", "q2");
  add_card(top, "test 3", "q3");
  int i;
  card_t temp = top;
  char question[MAX_CARD_QUESTION_LENGTH];
  char answer[MAX_CARD_ANSWER_LENGTH];
  for(i = 0; i < get_size(top); i++){
    get_question(temp, question);
    get_answer(temp, answer);
    printf("%s : %s\n", question, answer);
    temp = temp->next;
  }
}