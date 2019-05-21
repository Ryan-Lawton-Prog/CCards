#include "menu.h"

void clear_screen(){
    printf("\e[1;1H\e[2J");
}

void print_menu(){

}

void print_login(){
    
}

void print_community_deck(deck_t deck){
    printf("Title: %s\n", deck->name);
    printf("Author: %s\n\n", deck->author);
}

void print_community_decks(deck_t decks){
    deck_t temp = decks;
    int i;
    for(i = 0; i < get_deck_size(decks); i++){
        if(i > 0){
            temp = temp->next;
        }
        print_community_deck(temp);
    }
    printf("Enter the name of the deck to view or type \"exit\" to go back to the Main Menu\n> ");
}

void wait(){
    char input[100];
    printf("Enter any key\n");
    while((getchar()) != '\n');
    scanf("%[^\n]", input);
    while((getchar()) != '\n');
}

void print_invalid_deck(){
    clear_screen();
    printf("Invalid Deck Name or Command\n");
    wait();
}

void print_invalid_command(){
    clear_screen();
    printf("Invalid Command\n");
    wait();
}