/*******************************************************************************
 * 48430 Fundamentals of C Programming - Assignment 3
 * Team: ?
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

/*******************************************************************************
 * Function prototypes
*******************************************************************************/

void view_decks();
void create_a_deck();
void view_community_decks();
void view_user_stats();

/*******************************************************************************
 * Main
*******************************************************************************/
int main(){
  int menu = 0;
  int logged_in = 1; /*once loggin has been implemented set to 0*/
  while(menu != -1){
    if(logged_in){
      print_menu();
      scanf("%d",&menu);
      /* -1: Exit
       *  1: View Decks
       *  2: Create Deck
       *  4: View Community Decks
       *  5: View User Stats
      */
      switch(menu){
        case -1:
          break;
        case 1:
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
      char username[20];
      char password[20];
      print_login();
      scanf("%s",username);
      scanf("%s",password);
    }
    /* prints menu and gets menu type */
  }
  return 0;
}

