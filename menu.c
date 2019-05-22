#include "menu.h"

void print_red(const char text[], int bold){
    if(bold == 1){
        printf("\033[1;31m");
    }else{
        printf("\033[0;31m");
    }
    printf("%s", text);
    printf("\033[0m");
}
void print_green(const char text[], int bold){
    if(bold == 1){
        printf("\033[1;32m");
    }else{
        printf("\033[0;32m");
    }
    printf("%s", text);
    printf("\033[0m");
}
void print_yellow(const char text[], int bold){
    if(bold == 1){
        printf("\033[1;33m");
    }else{
        printf("\033[0;33m");
    }
    printf("%s", text);
    printf("\033[0m");
}

void clear_screen(){
    printf("\e[1;1H\e[2J");
}

void print_menu(){
    clear_screen();
    print_yellow("Would you like to:\n", 1);
    print_yellow("0: ", 0);
    printf("Exit Program\n");
    print_yellow("1: ", 0);
    printf("View your current decks\n");
    print_yellow("2: ", 0);
    printf("Create a deck\n");
    print_yellow("3: ", 0);
    printf("View the communties decks\n> ");
}

void print_login(){
    
}

void print_community_deck(deck_t deck){
    print_yellow("Title: ",0);
    printf("%s\n", deck->name);
    print_yellow("Author: ",0);
    printf("%s\n\n", deck->author);
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
    print_yellow("Enter the '", 0);
    print_green("Title", 0);
    print_yellow("' of the deck to view or type '", 0);
    print_green("exit", 0);
    print_yellow("' to go back to the Main Menu\n> ", 0);
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

void print_card_creation(){
    print_yellow("Do you want to add more cards?\n", 1); 
    print_yellow("Type '",0);
    print_green("yes",0);
    print_yellow("' to continue or '",0);
    print_green("no",0);
    print_yellow("' to stop\n> ",0);
}