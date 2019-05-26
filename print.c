#include "print.h"

/*******************************************************************************
 * Used to print to terminal in red, either normally or bold
 * inputs:
 * - string (text), int
 * outputs:
 * - None
*******************************************************************************/
void print_red(const char text[], int bold){
    if(bold == 1){
        printf("\033[1;31m");
    }else{
        printf("\033[0;31m");
    }
    printf("%s", text);
    printf("\033[0m");
}

/*******************************************************************************
 * Used to print to terminal in green, either normally or bold
 * inputs:
 * - string (text), int
 * outputs:
 * - None
*******************************************************************************/
void print_green(const char text[], int bold){
    if(bold == 1){
        printf("\033[1;32m");
    }else{
        printf("\033[0;32m");
    }
    printf("%s", text);
    printf("\033[0m");
}

/*******************************************************************************
 * Used to print to terminal in yellow, either normally or bold
 * inputs:
 * - string (text), int
 * outputs:
 * - None
*******************************************************************************/
void print_yellow(const char text[], int bold){
    if(bold == 1){
        printf("\033[1;33m");
    }else{
        printf("\033[0;33m");
    }
    printf("%s", text);
    printf("\033[0m");
}

/*******************************************************************************
 * Used to print to terminal in blue, either normally or bold
 * inputs:
 * - string (text), int
 * outputs:
 * - None
*******************************************************************************/
void print_blue(const char text[], int bold){
    if(bold == 1){
        printf("\033[1;34m");
    }else{
        printf("\033[0;34m");
    }
    printf("%s", text);
    printf("\033[0m");
}

/*******************************************************************************
 * Used to clear the terminal screen (refresh)
 * inputs:
 * - None
 * outputs:
 * - None
*******************************************************************************/
void clear_screen(){
    printf("\e[1;1H\e[2J");
}

/*******************************************************************************
 * Prints the main menu text
 * inputs:
 * - None
 * outputs:
 * - None
*******************************************************************************/
void print_menu(){
    clear_screen();
    print_green("MAIN MENU\n-----------\n\n", 1);
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

/*******************************************************************************
 * Prints the login menu text
 * inputs:
 * - None
 * outputs:
 * - None
*******************************************************************************/
void print_login_menu() {
    clear_screen();
	print_green("LOG-IN MENU\n-----------\n\n", 1);
	print_yellow("Enter an option from the list below:\n", 1);
    print_yellow("1: ", 0);
	printf("Log in with an existing account.\n");
    print_yellow("2: ", 0);
	printf("Create a new account.\n> ");
}

/*******************************************************************************
 * Prints out a decks details
 * inputs:
 * - deck_t
 * outputs:
 * - None
*******************************************************************************/
void print_community_deck(deck_t deck){
    print_yellow("Title: ",0);
    printf("%s\n", deck->name);
    print_yellow("Author: ",0);
    printf("%s\n\n", deck->author);
}

/*******************************************************************************
 * Prints out all of the community decks available
 * inputs:
 * - deck_t
 * outputs:
 * - None
*******************************************************************************/
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

/*******************************************************************************
 * Prints out a cards details, either with answers or not
 * inputs:
 * - card_t, int
 * outputs:
 * - None
*******************************************************************************/
void print_community_card(card_t card, int show_answer){
    print_yellow("Question: ",0);
    printf("%s\n", card->question);
    if(show_answer){
        print_yellow("Answer: ",0);
        printf("%s\n", card->answer);
    }
    printf("\n");
}

/*******************************************************************************
 * Prints out a decks list of cards either with answers or not
 * inputs:
 * - deck_t, int
 * outputs:
 * - None
*******************************************************************************/
void print_community_cards(deck_t deck, int show_answer){
    clear_screen();
    card_t temp = deck->cards;
    int i;
    print_community_deck(deck);
    for(i = 0; i < get_size(deck->cards); i++){
        if(i > 0){
            temp = temp->next;
        }
        print_community_card(temp, show_answer);
    }
    print_yellow("Would you like to:\n", 1);
    print_yellow("0: ", 0);
    printf("Exit to menu\n");
    print_yellow("1: ", 0);
    printf("Add this deck to your list\n");
    print_yellow("2: ", 0);
    printf("Show question answers\n> ");
}

void print_user_deck(deck_t deck){
    print_yellow("Title: ",0);
    printf("%s\n", deck->name);
    print_yellow("Author: ",0);
    printf("%s\n\n", deck->author);
}

void print_user_decks(deck_t decks){
    clear_screen();
    deck_t temp = decks;
    int i;
    printf("%d", get_deck_size(decks));
    for(i = 0; i < get_deck_size(decks); i++){
        if(i > 0){
            temp = temp->next;
        }
        print_user_deck(temp);
    }
    print_yellow("Enter the '", 0);
    print_green("Title", 0);
    print_yellow("' of the deck to view or type '", 0);
    print_green("exit", 0);
    print_yellow("' to go back to the Main Menu\n> ", 0);
}

void print_user_card(card_t card, int show_answer){
    print_yellow("Question: ",0);
    printf("%s\n", card->question);
    if(show_answer){
        print_yellow("Answer: ",0);
        printf("%s\n", card->answer);
    }
    printf("\n");
}

void print_user_cards(deck_t deck, int show_answer){
    clear_screen();
    card_t temp = deck->cards;
    int i;
    print_user_deck(deck);
    for(i = 0; i < get_size(deck->cards); i++){
        if(i > 0){
            temp = temp->next;
        }
        print_user_card(temp, show_answer);
    }
    print_yellow("Would you like to:\n", 1);
    print_yellow("0: ", 0);
    printf("Exit to menu\n");
    print_yellow("1: ", 0);
    printf("Show question answers\n> ");
}

void print_deck_menu(deck_t deck){
    clear_screen();
    print_yellow("Would you like to:\n", 1);
    print_yellow("0: ", 0);
    printf("Exit to menu\n");
    print_yellow("1: ", 0);
    printf("Play this deck\n");
    print_yellow("2: ", 0);
    printf("View this deck\n");
    print_yellow("3: ", 0);
    printf("Edit this deck\n");
    print_yellow("4: ", 0);
    printf("Delete this deck\n> ");
}

/*******************************************************************************
 * Used to pause and wait for any generic user input
 * inputs:
 * - None
 * outputs:
 * - None
*******************************************************************************/
void wait(){
    char input[100];
    printf("Enter any key\n");
    while((getchar()) != '\n');
    scanf("%[^\n]", input);
    while((getchar()) != '\n');
}

/*******************************************************************************
 * Prints an alert for invalid deck menu commands
 * inputs:
 * - None
 * outputs:
 * - None
*******************************************************************************/
void print_invalid_deck(){
    clear_screen();
    print_red("Invalid Deck Name or Command\n", 1);
    wait();
}

/*******************************************************************************
 * Prints an alert for invalid commands
 * inputs:
 * - None
 * outputs:
 * - None
*******************************************************************************/
void print_invalid_command(){
    clear_screen();
    print_red("Invalid Command\n", 0);
    wait();
}

/*******************************************************************************
 * Prints the menu for the card creation routine
 * inputs:
 * - None
 * outputs:
 * - None
*******************************************************************************/
void print_card_creation(){
    print_yellow("Do you want to add more cards?\n", 1); 
    print_yellow("Type '",0);
    print_green("yes",0);
    print_yellow("' to continue or '",0);
    print_green("no",0);
    print_yellow("' to stop\n> ",0);
}

/*******************************************************************************
 * Prints an alert for adding a deck to a users collection
 * inputs:
 * - None
 * outputs:
 * - None
*******************************************************************************/
void print_add_deck(){
    clear_screen();
    print_yellow("Added to your deck collection\n", 0);
    wait();
}

/*******************************************************************************
 * Prints and recieves the details for loging in for a user
 * inputs:
 * - None
 * outputs:
 * - None
*******************************************************************************/
void print_existing_account(user_t*user){
    clear_screen();
    print_yellow("Enter your log-in details!\n", 1);
    print_yellow("Username: ", 0);
    while((getchar()) != '\n');
    scanf("%[^\n]", user->username);
    print_yellow("Password: ", 0);
    while((getchar()) != '\n');
    scanf("%[^\n]", user->password);
}