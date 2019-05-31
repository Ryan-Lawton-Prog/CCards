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
 * - card_t (Top of card heap), string (question for card),
 *   string (answer for card)
 * outputs:
 * - card_t (Top of card heap)
*******************************************************************************/
card_t add_card(card_t head, const char question[], const char answer[]){
    card_t temp,p;
    temp = create_card();
    strcpy(temp->question,question);
    strcpy(temp->answer,answer);
    /*Checks if card linked list is empty*/
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
 * get question from the card 'card' and write it to the given array
 * inputs:
 * - card_t, string
 * outputs:
 * - none
*******************************************************************************/
void get_question(card_t card, char question[]){
    strcpy(question, card->question);
}

/*******************************************************************************
 * get answer from the card 'card' and write it to the given array
 * inputs:
 * - card_t, string
 * outputs:
 * - none
*******************************************************************************/
void get_answer(card_t card, char answer[]){
    strcpy(answer, card->answer);
}

/*******************************************************************************
 * set the question and answer parameter of a given card 'card'
 * inputs:
 * - card_t, string (question), string (answer)
 * outputs:
 * - none
*******************************************************************************/
void set_card(card_t card, const char question[], const char answer[]){
    strcpy(card->question, question);
    strcpy(card->answer, answer);
}

/*******************************************************************************
 * get question in position 'pos' from the
 * sequence of cards from the top of the stack 'card'
 * inputs:
 * - card_t, int
 * outputs:
 * - none
*******************************************************************************/
card_t get_card_at(card_t card, int pos){
    card_t temp;
    temp = card;
    int i;
    for(i = 0; i < get_size(card); i++){
        if(i == pos){
            return temp;
        }
        temp = temp->next;
    }
    return temp;
}

/*******************************************************************************
 * get question in position 'pos' from the
 * sequence of cards from the top of the stack 'card'
 * inputs:
 * - card_t, int, string (question)
 * outputs:
 * - none
*******************************************************************************/
void get_question_at(card_t card, int pos, char question[]){
    card_t temp;
    temp = card;
    int i;
    for(i = 0; i < get_size(card); i++){
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
 * sequence of cards from the top of the stack 'card'
 * inputs:
 * - card_t, int, string (answer)
 * outputs:
 * - none
*******************************************************************************/
void get_answer_at(card_t card, int pos, char answer[]){
    card_t temp;
    temp = card;
    int i;
    for(i = 0; i < get_size(card); i++){
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
 * sequence of cards from the top of the stack 'card'
 * inputs:
 * - card_t, int, string (question), string (answer)
 * outputs:
 * - none
*******************************************************************************/
void set_card_at(card_t card, int pos, const char question[],
    const char answer[]){
    card_t temp;
    temp = card;
    int i;
    for(i = 0; i < get_size(card); i++){
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
card_t get_next(card_t card){
    return card->next;
}

/*******************************************************************************
 * get how many cards there are in a heap
 * inputs:
 * - card_t (top of heap)
 * outputs:
 * - int (amount of cards)
*******************************************************************************/
int get_size(card_t card){
    if(card->next == NULL){
        return 1;
    }
    return get_size(card->next) + 1;
}

/*******************************************************************************
 * Removes a card at a provided index
 * inputs:
 * - card_t, int, int
 * outputs:
 * - None
*******************************************************************************/
void remove_card_at(card_t card, int pos, int max){
    card_t temp;
    temp = card;
    int i;
    for(i = 0; i < get_size(card); i++){
        if(i+1 == pos){
            if(pos == max){
                temp->next = NULL;
                return;
            }
            card_t next = temp->next;
            temp->next = next->next;
            return;
        }
        temp = temp->next;
    }
}

/*******************************************************************************
 * Makes a new set of cards from a provided set of cards
 * inputs:
 * - card_t
 * outputs:
 * - card_t
*******************************************************************************/
card_t copy_cards(card_t card){
    card_t final = create_card();
    card_t temp = card;
    int i;
    for(i = 0; i < get_size(card); i++){
        if(i > 0){
            temp = temp->next;
        }
        final = add_card(final, temp->question, temp->answer);
    }
    return final;
}