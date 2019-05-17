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

/*******************************************************************************
 * Function prototypes
*******************************************************************************/

void view_decks();
void create_a_deck();
void view_community_decks();
void view_user_stats();
void login(deck_t*, deck_t*, user_t*);

/*******************************************************************************
 * Main
*******************************************************************************/
int main(){
  int menu = 0;
  int logged_in = 1; /*once loggin has been implemented set to 0*/
  deck_t decks = create_deck();
  deck_t community_decks = create_deck();
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
      login(&decks, &community_decks, &user);
    }
    /* prints menu and gets menu type */
  }
  return 0;
}

void login(deck_t*deck, deck_t*community_deck, user_t*user){
  print_login();
}

