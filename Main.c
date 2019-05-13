#include "cards.h"

int main(){
  card_t top = add_card(create_card(), "What is 1 + 1", "2");
  add_card(top, "test 2", "q2");
  add_card(top, "test 3", "q3");
  printf("size: %d\n",get_size(top));
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

  get_question_i(top, 2, question);
  printf("%s pos 3\n", question);

  return 0;
}