#include "deck.h"

/*******************************************************************************
 * Used to create an empty deck ready for processing
 * inputs:
 * - none
 * outputs:
 * - deck_t
*******************************************************************************/
deck_t create_deck(){
    deck_t temp; 
    temp = (deck_t)malloc(sizeof(struct deck));
    strcpy(temp->name, "");
    strcpy(temp->author, "");
    strcpy(temp->owner, "");
    temp->played = 0;
    temp->accuracy = 0;
    temp->cards = NULL;
    temp->next = NULL;
    return temp;
}

/*******************************************************************************
 * Used to add a deck to the deck heap (deck is defined here)
 * inputs:
 * - deck_t (Top of deck heap), string (name for deck), card_t (top of card heap)
 * outputs:
 * - deck_t (Top of deck heap)
*******************************************************************************/
deck_t add_deck(deck_t head, 
        const char name[], 
        const char author[], 
        const char owner[], 
        int played, 
        double accuracy, 
        card_t cards){
    deck_t temp,p;
    temp = create_deck();
    strcpy(temp->name,name);
    strcpy(temp->author,author);
    strcpy(temp->owner,owner);
    temp->played = played;
    temp->accuracy = accuracy;
    temp->cards = cards;
    if(!strcmp(head->name, "")){
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
 * get name from the deck 'n' and write it to the given array
 * inputs:
 * - deck_t, string
 * outputs:
 * - none
*******************************************************************************/
void get_name(deck_t n, char name[]){
    strcpy(name, n->name);
}

/*******************************************************************************
 * get name in position 'pos' from the
 * sequence of decks from the top of the stack 'n'
 * inputs:
 * - deck_t, int, string (name)
 * outputs:
 * - none
*******************************************************************************/
void get_name_at(deck_t n, int pos, char name[]){
    deck_t temp;
    temp = n;
    int i;
    for(i = 0; i < get_deck_size(n); i++){
        if(i == pos){
            strcpy(name, temp->name);
            return;
        }
        temp = temp->next;
    }
    strcpy(name, "invalid index");
}

/*******************************************************************************
 * get cards from the deck 'n' and return the top of the card heap
 * inputs:
 * - deck_t
 * outputs:
 * - card_t
*******************************************************************************/
card_t get_cards(deck_t n){
    return n->cards;
}

/*******************************************************************************
 * get cards in position 'pos' from the
 * sequence of decks from the top of the stack 'n'
 * inputs:
 * - deck_t, pos
 * outputs:
 * - card_t (top of heap)
*******************************************************************************/
card_t get_cards_at(deck_t n, int pos){
    deck_t temp;
    temp = n;
    int i;
    for(i = 0; i < get_deck_size(n); i++){
        if(i == pos){
            return temp->cards;
        }
        temp = temp->next;
    }
    return NULL;
}

/*******************************************************************************
 * set the name and cards parameter of a given deck 'n'
 * inputs:
 * - deck_t, string (name), card_t (top of card heap)
 * outputs:
 * - none
*******************************************************************************/
void set_deck(deck_t n, const char name[], card_t cards){
    strcpy(n->name, name);
    n->cards = cards;
}

/*******************************************************************************
 * set name and cards in position 'pos' from the
 * sequence of decks from the top of the stack 'n'
 * inputs:
 * - deck_t, int, string (name), card_t (top of stack)
 * outputs:
 * - none
*******************************************************************************/
void set_deck_at(deck_t n, int pos, const char name[], card_t cards){
    deck_t temp;
    temp = n;
    int i;
    for(i = 0; i < get_deck_size(n); i++){
        if(i == pos){
            strcpy(temp->name, name);
            temp->cards = cards;
            return;
        }
        temp = temp->next;
    }
}

/*******************************************************************************
 * get times played from the deck 'n'
 * inputs:
 * - deck_t
 * outputs:
 * - int
*******************************************************************************/
int get_played(deck_t n){
    return n->played;
}

/*******************************************************************************
 * get times played in position 'pos' from the
 * sequence of decks starting at the top of the stack 'n'
 * inputs:
 * - deck_t, int
 * outputs:
 * - int
*******************************************************************************/
int get_times_played_at(deck_t n, int pos){
    deck_t temp;
    temp = n;
    int i;
    for(i = 0; i < get_deck_size(n); i++){
        if(i == pos){
            return temp->played;
        }
        temp = temp->next;
    }
    return -1;
}

/*******************************************************************************
 * get accuracy from the deck 'n'
 * inputs:
 * - deck_t
 * outputs:
 * - double
*******************************************************************************/
double get_accuracy(deck_t n){
    return n->accuracy;
}

/*******************************************************************************
 * get accuracy in position 'pos' from the
 * sequence of decks starting at the top of the stack 'n'
 * inputs:
 * - deck_t, int
 * outputs:
 * - double
*******************************************************************************/
double get_accuracy_at(deck_t n, int pos){
    deck_t temp;
    temp = n;
    int i;
    for(i = 0; i < get_deck_size(n); i++){
        if(i == pos){
            return temp->accuracy;
        }
        temp = temp->next;
    }
    return -1;
}

/*******************************************************************************
 * get author from the deck 'n'
 * inputs:
 * - deck_t
 * outputs:
 * - none
*******************************************************************************/
void get_author(deck_t n, char author[]){
    strcpy(author, n->author);
}

/*******************************************************************************
 * get author in position 'pos' from the
 * sequence of decks starting at the top of the stack 'n'
 * inputs:
 * - deck_t, int, string (author)
 * outputs:
 * - none
*******************************************************************************/
void get_author_at(deck_t n, int pos, char author[]){
    deck_t temp;
    temp = n;
    int i;
    for(i = 0; i < get_deck_size(n); i++){
        if(i == pos){
            strcpy(author, temp->author);
            return;
        }
        temp = temp->next;
    }
    strcpy(author, "invalid index");
}

/*******************************************************************************
 * get owner from the deck 'n'
 * inputs:
 * - deck_t
 * outputs:
 * - none
*******************************************************************************/
void get_owner(deck_t n, char owner[]){
    strcpy(owner, n->owner);
}

/*******************************************************************************
 * get owner in position 'pos' from the
 * sequence of decks starting at the top of the stack 'n'
 * inputs:
 * - deck_t, int, string (owner)
 * outputs:
 * - none
*******************************************************************************/
void get_owner_at(deck_t n, int pos, char owner[]){
    deck_t temp;
    temp = n;
    int i;
    for(i = 0; i < get_deck_size(n); i++){
        if(i == pos){
            strcpy(owner, temp->owner);
            return;
        }
        temp = temp->next;
    }
    strcpy(owner, "invalid index");
}

/*******************************************************************************
 * Updates the accuracy of a deck after a new game has been played
 * inputs:
 * - deck_t, int
 * outputs:
 * - none
*******************************************************************************/
void update_stats(deck_t n, int correct){
    n->accuracy = ((n->accuracy * n->played) + 
        (correct / get_size(n->cards))) / 
        (n->played + 1);
    n->played++;
}

/*******************************************************************************
 * Updates the accuracy of a deck at position 'pos' from the
 * sequence of decks starting at the top of the stack 'n'
 * inputs:
 * - deck_t, int, int
 * outputs:
 * - none
*******************************************************************************/
void update_stats_at(deck_t n, int pos, int correct){
    deck_t temp;
    temp = n;
    int i;
    for(i = 0; i < get_deck_size(n); i++){
        if(i == pos){
            temp->accuracy = ((temp->accuracy * temp->played) + 
                (correct / get_size(temp->cards))) / 
                (temp->played + 1);
            temp->played++;
            return;
        }
        temp = temp->next;
    }
}

/*******************************************************************************
 * get how many decks there are in a heap
 * inputs:
 * - deck_t (top of heap)
 * outputs:
 * - int (amount of decks)
*******************************************************************************/
int get_deck_size(deck_t n){
    if(n->next == NULL){
        return 1;
    }
    return get_deck_size(n->next) + 1;
}

/*******************************************************************************
 * get next deck in the linked deck list
 * inputs:
 * - deck_t
 * outputs:
 * - deck_t (next deck)
*******************************************************************************/
deck_t get_next_deck(deck_t n){
    return n->next;
}