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
void create_a_deck();
void view_community_decks(deck_t, deck_t, user_t);
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
                    break;
                case 4:
                    view_community_decks(community_decks, decks, user);
                    break;
                case 5:
                    break;
                default:
                    print_invalid_command();
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