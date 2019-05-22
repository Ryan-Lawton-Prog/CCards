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
#include "menu.h"
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
void view_community_decks();
void view_user_stats();
void login(deck_t, deck_t, user_t*);

/*******************************************************************************
 * Main
*******************************************************************************/
int main(){
    int menu = 0;
    int logged_in = 1; /*once loggin has been implemented set to 0*/
    deck_t decks = create_deck();
    deck_t community_decks = load_community_decks();
    user_t user = create_user();
    while(menu != -1){
        if(logged_in){
            print_menu();
            printf("menu: ");
            scanf("%d",&menu);
            /* -1: Exit
             *  1: View Decks
             *  2: Create Deck
             *  4: View Community Decks
             */
            switch(menu){
                case -1:
                    break;
                case 1:
                    test_add_card();
                    break;
                case 2:
                    if(strcmp(community_decks->name, "") > 0){
                        save_community_decks(community_decks);
                    }
                    break;
                case 3:
                    create_a_deck(decks, community_decks, user);
                    break;
                case 4:
                    view_community_decks(community_decks, decks, user);
                    break;
                case 5:
                    break;
                default:
                    printf("Invalid choice\n");
                    break;
            }
        }else{
            login(decks, community_decks, &user);
        }
    }
    return 0;
}

void login(deck_t deck, deck_t community_deck, user_t*user){
    print_login();
}

void create_a_deck(deck_t decks, deck_t community_deck, user_t user){
    card_t cards = create_card();
    char name[MAX_DECK_NAME_LENGTH];
    char question[MAX_CARD_QUESTION_LENGTH];
    char answer[MAX_CARD_ANSWER_LENGTH];
    char user_input[MAX_INPUT_LENGTH];
    int is_public = 0;
    int choice = 0;

    do{
        while((getchar()) != '\n');
        printf("What do you want to name your deck?\n");
        scanf("%[^\n]", name);
    } while (name[0] == '\0');


    while(choice != -1){
        while((getchar()) != '\n');
        printf("Write your question card:\n");
        scanf("%[^\n]", question);
        while((getchar()) != '\n');
        printf("Write your answer card:\n");
        scanf("%[^\n]", answer);

        cards = add_card(cards, question, answer);

        while(choice != -1){
            while((getchar()) != '\n');
            printf("Do you want to add more cards? " 
                   "Type 'yes' to continue or 'no' to stop\n");
            scanf("%[^\n]", user_input);
            
            if(strcmp(user_input, "no") == 0){
                choice = -1;
            } else if (strcmp(user_input, "yes") == 0){
                break;
            } else {
                printf("Invalid choice\n");
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
            printf("Invalid choice\n");
            is_public = 0;
        }
    }
    
    if(is_public == 1){
        community_deck = add_deck(community_deck, name, user.fullname, "", is_public, 0, 0, cards);
        save_community_decks(community_deck);
    }

    decks = add_deck(decks, name, user.fullname, user.username, is_public, 0, 0, cards);
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
                if(!strcmp(input, temp->name)){
                    decks = add_deck(decks, temp->name, temp->author, user.username, 0, 0, 0, temp->cards);
                    update_deck_db(get_last_deck(decks));
                    printf("Added: \"%s\" to you deck collection\n", input);
                    return;
                }
            }
        }
        print_invalid_deck();
    }
}