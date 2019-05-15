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

int main(){
  int menu = 0;
  while(menu != -1){
    /* prints menu and gets menu type */
    print_menu();
    scanf("%d",&menu);
    switch(menu)
    {
      case -1:
        break;
      default:
        printf("Invalid choice\n");
        break;
    }
  }
  return 0;
}