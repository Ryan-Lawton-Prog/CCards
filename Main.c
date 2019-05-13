#include "cards.h"


int main(){
  card_t*top = card_head("What is 1 + 1","2");
  card_next("test 2", "q2", top);
  card_next("test 3", "q3", top);
  printf("size: %d\n",get_size(top));
  return 0;
}