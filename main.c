/*******************************************************************************
 * 48430 Fundamentals of C Programming - Assignment 3
 * Team: 3
 * Team Members: 
 *  Anto Mathews - 
 *  Ayush Bhatia - 
 *  Gordon Wang - 
 *  Jenny Tran - 
 *  Ryan Lawton - 12545341
 * Date of submission: ?
*******************************************************************************/

#include "deck.h"
#include "menu.h"
#include "user.h"
#include "test.h"

#define MAX_USERNAME_LENGTH 20
#define MAX_PASSWORD_LENGTH 20
#define DB_COMMUNITY_DECKS "DB_COMMUNITY_DECKS"

/*******************************************************************************
 * Function prototypes
*******************************************************************************/

void view_decks();
void create_a_deck();
void view_community_decks();
void view_user_stats();
void login(deck_t, deck_t, user_t*);
deck_t load_community_decks();
void save_community_decks(deck_t);

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

deck_t load_community_decks(){
    deck_t final_deck = create_deck();
    deck_t temp_deck = create_deck();
    card_t final_card = create_card();
    card_t temp_card = create_card();
    FILE * filep;
    filep = fopen(DB_COMMUNITY_DECKS, "r");
    if(filep == NULL){
        printf("Could not find Community Deck DB\n");
        return NULL;
    }
    int eof = 1;
    int reading_cards = 0;
    while(eof){
        char temp_l[100] = {'\0'};
        char temp_r[100] = {'\0'};
        eof = fscanf(filep, "%s %[^\n]", temp_l, temp_r) != EOF;
        if(!eof){
            break;
        }
        if(!reading_cards){
            if(!strcmp(temp_l, "name")){
                strcpy(temp_deck->name,temp_r);
            }else if(!strcmp(temp_l, "author")){
                strcpy(temp_deck->author,temp_r);
            }else if(!strcmp(temp_l, "played")){
                sscanf(temp_r, "%d", &temp_deck->played);
            }else if(!strcmp(temp_l, "accuracy")){
                sscanf(temp_r, "%lf", &temp_deck->accuracy);
                reading_cards = 1;
            }
        }else{
            if(!strcmp(temp_l, "end")){
                reading_cards = 0;
                final_deck = add_deck(final_deck, temp_deck->name, temp_deck->author, "", 1, temp_deck->played, temp_deck->accuracy, final_card);
                temp_card = create_card();
                final_card = create_card();
                temp_deck = create_deck();
            }else if(!strcmp(temp_l, "question")){
                strcpy(temp_card->question,temp_r);
            }else if(!strcmp(temp_l, "answer")){
                strcpy(temp_card->answer,temp_r);
                final_card = add_card(final_card, temp_card->question, temp_card->answer);
                temp_card = create_card();
            }
        }
    }
    fclose(filep);
    return final_deck;
}

void save_community_decks(deck_t deck){
    deck_t current_deck = deck;
    card_t current_card = deck->cards;
    FILE * filep;
    filep = fopen(DB_COMMUNITY_DECKS, "w");
    int i;
    for(i = 0; i < get_deck_size(deck); i++){
        if(i > 0){
            current_deck = current_deck->next;
            current_card = current_deck->cards;
        }
        fprintf(filep, "%s %s\n", "name", current_deck->name);
        fprintf(filep, "%s %s\n", "author", current_deck->author);
        fprintf(filep, "%s %d\n", "played", current_deck->played);
        fprintf(filep, "%s %lf\n", "accuracy", current_deck->accuracy);
        int j;
        for(j = 0; j < get_size(current_deck->cards); j++){
            fprintf(filep, "%s %s\n", "question", current_card->question);
            fprintf(filep, "%s %s\n", "answer", current_card->answer);
            current_card = current_card->next;
        }
        fprintf(filep, "%s %s\n", "end", "deck");
    }
    fclose(filep);
}