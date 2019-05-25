/*******************************************************************************
 * 48430 Fundamentals of C Programming - Assignment 3
 * Team: 3
 * Team Members: 
 *  Anto Mathews - 
 *  Ayush Bhatia - 
 *  Gordon Wang - 
 *  Jenny Tran - 
 *  Ryan Lawton - 12545341
 * Date of submission: 28/5/2019
*******************************************************************************/

#include "deck.h"
#include "print.h"
#include "user.h"
#include "test.h"

#define MAX_USERNAME_LENGTH 20
#define MAX_PASSWORD_LENGTH 20
#define MAX_INPUT_LENGTH 100

/*******************************************************************************
 * Function prototypes
*******************************************************************************/

void view_decks();
void create_a_deck(deck_t, deck_t, user_t);
void view_community_decks(deck_t, deck_t, user_t);
void view_community_deck(deck_t, deck_t, user_t);
void view_user_stats();
int login(deck_t, deck_t, user_t*);
int create_new_account(deck_t, deck_t, user_t*);
int login_existing_account(deck_t, deck_t, user_t*);
int check_username_format(const char[]);
int check_password_format(const char[]);

/*******************************************************************************
 * Main
*******************************************************************************/
int main(){
    int menu = 0;
    int logged_in = 0; /*once loggin has been implemented set to 0*/
    deck_t decks = create_deck();
    deck_t community_decks = load_community_decks();
    user_t user = create_user();
    while(menu != -1){
        if(logged_in){
            print_menu();
            scanf("%d",&menu);
            /* 0: Exit
             *  1: View Decks
             *  2: Create Deck
             *  3: View Community Decks
             */
            switch(menu){
                case 0:
                    menu = -1;
                    break;
                case 1:
                    test_add_card();
                    break;
                case 2:
                    create_a_deck(decks, community_decks, user);
                    break;
                case 3:
                    view_community_decks(community_decks, decks, user);
                    break;
                case 4:
                    break;
                case 5:
                    break;
                default:
                    print_red("Invalid choice\n", 1);
                    break;
            }
        }else{
            logged_in = login(decks, community_decks, &user);
        }
    }
    return 0;
}

void create_a_deck(deck_t decks, deck_t community_deck, user_t user){
    card_t cards = create_card();
    char name[MAX_DECK_NAME_LENGTH];
    char question[MAX_CARD_QUESTION_LENGTH];
    char answer[MAX_CARD_ANSWER_LENGTH];
    char user_input[MAX_INPUT_LENGTH];
    int is_public = 0;
    int choice = 0;
    clear_screen();
    do{
        while((getchar()) != '\n');
        print_yellow("What do you want to name your deck?\n> ",1);
        scanf("%[^\n]", name);
    } while (name[0] == '\0');


    while(choice != -1){
        while((getchar()) != '\n');
        print_yellow("Write your question card:\n> ",1);
        scanf("%[^\n]", question);
        while((getchar()) != '\n');
        print_yellow("Write your answer card:\n> ",1);
        scanf("%[^\n]", answer);

        cards = add_card(cards, question, answer);

        while(choice != -1){
            while((getchar()) != '\n');
            print_card_creation();
            scanf("%[^\n]", user_input);
            
            if(strcmp(user_input, "no") == 0){
                choice = -1;
            } else if (strcmp(user_input, "yes") == 0){
                break;
            } else {
                print_red("Invalid choice\n", 1);
            }
        }
    }

    while(is_public == 0){
        printf("Do you want make this deck public or private? "
               "Type 1 for public or 0 for private.\n");
        scanf("%d", &is_public);

        if(is_public == 1 || is_public == 0){
            break;
        } else {
            print_red("Invalid choice\n", 1);
            is_public = 0;
        }
    }
    
    if(is_public == 1){
        community_deck = add_deck(community_deck, name, user.fullname,
             "", is_public, 0, 0, cards);
        save_community_decks(community_deck);
    }

    decks = add_deck(decks, name, user.fullname, user.username,
         is_public, 0, 0, cards);
    update_deck_db(get_last_deck(decks));
}

void view_community_decks(deck_t community_decks, deck_t decks, user_t user){
    /*printing community decks*/
    while(1){
        clear_screen();
        deck_t temp = community_decks;
        char input[100];
        int i;
        print_community_decks(community_decks);
        while((getchar()) != '\n');
        scanf("%[^\n]", input);
        if(!strcmp(input, "exit")){
            return;
        }else{
            temp = community_decks;
            int size = get_deck_size(community_decks);
            for(i = 0; i < size; i++){
                if(i > 0){
                    temp = temp->next;
                }
                if(strcmp(input, temp->name) <= 1){
                    view_community_deck(temp, decks, user);
                    return;
                }
            }
        }
        print_invalid_deck();
    }
}

void view_community_deck(deck_t deck, deck_t decks, user_t user){
    int menu = 0;
    int show_answers = 0;
    while(menu != -1){
        print_community_cards(deck, show_answers);
        scanf("%d",&menu);
        switch(menu){
            case 0:
                menu = -1;
                break;
            case 1:
                decks = add_deck(decks, deck->name, deck->author,
                    user.username, 0, 0, 0, deck->cards);
                update_deck_db(get_last_deck(decks));
                print_add_deck();
                menu = -1;
                break;
            case 2:
                show_answers = 1;
                break;
            default:
                print_red("Invalid choice\n", 1);
                break;
        }
    }
}

/* Return 1 if logged in, 0 if not logged in */
int login(deck_t deck, deck_t community_deck, user_t *user) {
	int success = 0;
	int login_menu_choice = 0;

	fflush(stdin);
    while(success == 0){
        print_login_menu();
        scanf("%d", &login_menu_choice);
        printf("\n");
        switch(login_menu_choice) {
            case 1: /* Log in to existing account */
                success = login_existing_account(deck, community_deck, user);
                break;
            case 2: /*Create a new account.*/
                success = create_new_account(deck, community_deck, user);
                break;
            default:
                print_red("Invalid choice\n", 1);
                success = 0;
                break;
        }

        printf("\n");
        fflush(stdin);
    }
	return success;
}

int login_existing_account(deck_t deck, deck_t community_deck, user_t *user){
    print_existing_account(user);
    if (check_password(*user) == 0) {
        clear_screen();
        print_red("Invalid credentials!\n", 1);
        wait();
    }
    else {
        clear_screen();
        print_green("Log-in successful.\n", 1);
        wait();
        return 1;
    }
    return 0;
}

int create_new_account(deck_t deck, deck_t community_deck, user_t *user){
    char input_fullname[MAX_NAME_LENGTH+2] = "";
    char input_username[MAX_USERNAME_LENGTH+2] = "";
    char input_password[MAX_PASSWORD_LENGTH+2] = "";
    print_yellow("Creating a new account!\nEnter details below.\n", 1);
    /*Full name+*/
    while((getchar()) != '\n');
    while (strcmp(user->fullname, "") == 0) {
        clear_screen();
        print_yellow("Full name (maximum 40 characters):\n> ", 0);
        scanf("%[^\n]", input_fullname);
        if (strcmp(input_fullname, "") == 0) {
            clear_screen();
            print_yellow("Please enter at least one character.\n", 0);
            wait();
        }
        else if(strlen(input_fullname) > MAX_NAME_LENGTH){
            clear_screen();
            print_yellow("Too many characters, please try again.\n", 0);
            wait();
        }
        else{
            input_fullname[-1] = '\0';
            strcpy(user->fullname, input_fullname);
        }
    }
    while((getchar()) != '\n');
    /* Username */
    while (strcmp(user->username, "") == 0) {
        clear_screen();
        print_yellow("Username (maximum 20 characters):\n> ", 0);
        scanf("%[^\n]", input_username);
        if (strcmp(input_username, "") == 0) {
            clear_screen();
            print_yellow("Please enter at least one character.\n", 0);
            wait();
        }
        else if(strlen(input_username) > MAX_USERNAME_LENGTH){
            clear_screen();
            print_yellow("Too many characters, please try again.\n", 0);
            wait();
        }
        else{
            input_username[-1] = '\0';
            strcpy(user->username, input_username);
        }
    }
    while((getchar()) != '\n');
    /* Password */
    while (strcmp(user->password, "") == 0) {
        clear_screen();
        print_yellow("Password (maximum 20 characters):\n> ", 0);
        scanf("%[^\n]", input_password);
        if (strcmp(input_password, "") == 0) {
            clear_screen();
            print_yellow("Please enter at least one character.\n", 0);
            wait();
        }
        else if(strlen(input_password) > MAX_PASSWORD_LENGTH){
            clear_screen();
            print_yellow("Too many characters, please try again.\n", 0);
            wait();
        }
        else{
            input_password[-1] = '\0';
            strcpy(user->password, input_password);
        }
    }
    
    update_user_db(*user);
    clear_screen();
    print_green("Successfully created your account\n", 0);
    print_yellow("Welcome ", 1);
    print_blue(user->fullname, 1);
    printf("\n");
    wait();
    return 1;
}