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

deck_t global_decks;
deck_t global_community_decks;
int debug;

/*******************************************************************************
 * Function prototypes
*******************************************************************************/

void view_decks(user_t);
void deck_menu(deck_t,user_t);
void create_a_deck(user_t);
void view_community_decks(user_t);
void view_community_deck(deck_t,user_t);
void view_user_stats();
int login(user_t*);
int create_new_account(user_t*);
int login_existing_account(user_t*);
int check_username_format(const char[]);
int check_password_format(const char[]);
void play_deck(deck_t, user_t);
void view_deck(deck_t, user_t);
void edit_deck(deck_t, user_t, int);
void delete_deck(deck_t, user_t);
int check_cmla(user_t*, int, char*[]);

/*******************************************************************************
 * Main
*******************************************************************************/
int main(int argc, char *argv[]){
    int menu = 0;
    int logged_in = 0;
    debug = 0;
    global_decks = create_deck();
    global_community_decks = load_community_decks();
    user_t user = create_user();
    int command = check_cmla(&user, argc, argv);
    if(command == 1){
        debug = 1;
    }else if(command == 2){
        logged_in = 1;
    }
    while(menu != -1){
        if(debug){
            logged_in = 1;
        }
        if(logged_in){
            print_menu();
            scanf("%d",&menu);
            /*  0: Exit
             *  1: View Decks
             *  2: Create Deck
             *  3: View Community Decks
             */
            switch(menu){
                case 0:
                    menu = -1;
                    break;
                case 1:
                    view_decks(user);
                    break;
                case 2:
                    create_a_deck(user);
                    break;
                case 3:
                    view_community_decks(user);
                    break;
                default:
                    print_red("Invalid choice\n", 1);
                    break;
            }
        }else{
            logged_in = login(&user);
        }
    }
    return 0;
}

int check_cmla(user_t*user, int argc, char *argv[]){
    if(argc > 1){
        if(!strcmp(argv[1], "debug")){
            return 1;
        }else if(!strcmp(argv[1], "login")){
            if(argc > 3){
                strcpy(user->username,argv[2]);
                strcpy(user->password,argv[3]);
                if (check_password(user) == 0) {
                    clear_screen();
                    print_red("Invalid credentials!\n", 1);
                    neutral_wait();
                }
                else {
                    global_decks = load_user_decks(*user);
                    /*clear_screen();*/
                    print_green("Log-in successful.\n", 1);
                    neutral_wait();
                    return 1;
                }
                return 0;
                return 2;
            }
        }
    }
    return 0;
}

/*******************************************************************************
 * 
 * inputs:
 * - None
 * outputs:
 * - None
*******************************************************************************/
void view_decks(user_t user){
      while(1){
        deck_t temp = global_decks;
        char input[100];
        int i; 
        print_user_decks(global_decks);
        if(strlen(global_decks->name) == 0){
            break;
        }
        while((getchar()) != '\n');
        scanf("%[^\n]", input);
        if(!strcmp(input, "exit")){
            return;
        }else{
            temp = global_decks; 
            int size = get_deck_size(global_decks);
            for(i=0; i< size;i++){
                if(i>0){
                    temp = temp->next;
                }
                if (!strcmp(input, temp->name)){
                    deck_menu(temp, user);
                    return; 
                }
            }
        }
    }
}

void deck_menu(deck_t deck, user_t user){
     int menu = 0;
     while((getchar()) != '\n');
     while(menu !=-1){
        print_deck_menu(deck);
        scanf("%d",&menu);
        /*  0: Exit
         *  1: Play Deck
         *  2: View Deck
         *  3: Delete Deck
         */
        switch(menu){
            case 0: 
                menu = -1; 
                break; 
            case 1:
                play_deck(deck, user);
                break; 
            case 2: 
                view_deck(deck, user);
                break; 
            case 3: 
                delete_deck(deck, user);
                menu = -1;
                break; 
            default:
                printf("Invalid choice\n");
                break; 
        }
    }
}

void play_deck(deck_t deck, user_t user){
    card_t temp = copy_cards(deck->cards);
    char answer[MAX_CARD_ANSWER_LENGTH+1];
    int correct = 0;
    while((getchar()) != '\n');
    int i;
    for(i = 0; i < get_size(deck->cards); i++){
        int num = (rand() % (get_size(temp)));
        print_card_question(get_card_at(temp, num));
        scanf("%[^\n]", answer);
        correct = correct + print_card_answer(get_card_at(temp, num), answer);
        remove_card_at(temp, num, get_size(temp)-1);
    }
    print_correct(deck, correct, user);
}

void view_deck(deck_t deck, user_t user){
    int menu = 0;
    while(menu != -1){
        print_user_cards(deck);
        scanf("%d",&menu);
        switch(menu){
            case 0:
                menu = -1;
                break;
            default:
                if(menu > 0 && menu <= get_deck_size(deck)){
                    edit_deck(deck, user, menu);
                    break;
                }
                print_red("Invalid choice\n", 1);
                break;
        }
    }
}

void edit_deck(deck_t deck, user_t user, int pos){
    char input[MAX_INPUT_LENGTH];
    char question[MAX_CARD_QUESTION_LENGTH+2];
    char answer[MAX_CARD_ANSWER_LENGTH+2];
    while(1){
        print_edit_deck(deck, pos);
        while((getchar()) != '\n');
        scanf("%[^\n]", input);
        if(!strcmp(input, "exit")){
            break;
        }else if(!strcmp(input, "Question")){
            while((getchar()) != '\n');
            while(1){
                clear_screen();
                strcpy(question, "");
                print_yellow("Question: ",0);
                printf("%s\n", get_card_at(deck->cards, pos-1)->question);
                print_yellow("Write your question card:\n> ",1);
                scanf("%[^\n]", question);
                if(strlen(question) == 0) {
                    clear_screen();
                    print_yellow("Please enter at least one character.\n", 0);
                    neutral_wait();
                }
                else if(strlen(question) > MAX_CARD_QUESTION_LENGTH){
                    clear_screen();
                    print_yellow("Too many characters, please try again.\n", 0);
                    neutral_wait();
                }
                else{
                    question[-1] = '\0';
                    strcpy(get_card_at(deck->cards, pos-1)->question, question);
                    edit_deck_db(deck, deck->name, user);
                    break;
                }
            }
        }else if(!strcmp(input, "Answer")){
            while((getchar()) != '\n');
            while(1){
                clear_screen();
                strcpy(answer, "");
                print_yellow("Answer: ",0);
                printf("%s\n", get_card_at(deck->cards, pos-1)->answer);
                print_yellow("Write your answer card:\n> ",1);
                scanf("%[^\n]", answer);
                if(strlen(answer) == 0) {
                    clear_screen();
                    print_yellow("Please enter at least one character.\n", 0);
                    neutral_wait();
                }
                else if(strlen(answer) > MAX_CARD_ANSWER_LENGTH){
                    clear_screen();
                    print_yellow("Too many characters, please try again.\n", 0);
                    neutral_wait();
                }
                else{
                    answer[-1] = '\0';
                    strcpy(get_card_at(deck->cards, pos-1)->answer, answer);
                    edit_deck_db(deck, deck->name, user);
                    break;
                }
            }
        }
    }
}

void delete_deck(deck_t deck, user_t user){
    delete_deck_db(deck, deck->name, user);
    global_decks = load_user_decks(user);
    print_delete_deck();
}

/*******************************************************************************
 * Creates a deck for a user and stores it into the database
 * inputs:
 * - deck_t, deck_t, user
 * outputs:
 * - None
*******************************************************************************/
void create_a_deck(user_t user){
    card_t cards = create_card();
    char name[MAX_DECK_NAME_LENGTH+2];
    char question[MAX_CARD_QUESTION_LENGTH+2];
    char answer[MAX_CARD_ANSWER_LENGTH+2];
    char user_input[MAX_INPUT_LENGTH+2];
    int is_public = 0;
    int loop = 1;
    while(loop){
        clear_screen();
        while((getchar()) != '\n');
        print_yellow("What do you want to name your deck?\n> ",1);
        scanf("%[^\n]", name);
        if(strcmp(name, "") == 0) {
            clear_screen();
            print_yellow("Please enter at least one character.\n", 0);
            wait();
        }
        else if(strlen(name) > MAX_NAME_LENGTH){
            clear_screen();
            print_yellow("Too many characters, please try again.\n", 0);
            wait();
        }
        else{
            name[-1] = '\0';
            loop = 0;
        }
    }

    loop = 1;
    int question_or_answer = 0;
    while(loop){
        clear_screen();
        if(!question_or_answer){
            strcpy(question, "");
            print_yellow("Write your question card:\n> ",1);
            while((getchar()) != '\n');
            scanf("%[^\n]", question);
            if(strlen(question) == 0) {
                clear_screen();
                print_yellow("Please enter at least one character.\n", 0);
                neutral_wait_pre();
            }
            else if(strlen(question) > MAX_CARD_QUESTION_LENGTH){
                clear_screen();
                print_yellow("Too many characters, please try again.\n", 0);
                neutral_wait_pre();
            }
            else{
                question[-1] = '\0';
                question_or_answer = 1;
            }
        }else if(question_or_answer){
            strcpy(answer, "");
            print_yellow("Write your answer card:\n> ",1);
            while((getchar()) != '\n');
            scanf("%[^\n]", answer);
            if(strlen(answer) == 0) {
                clear_screen();
                print_yellow("Please enter at least one character.\n", 0);
                neutral_wait_pre();
            }
            else if(strlen(answer) > MAX_CARD_ANSWER_LENGTH){
                clear_screen();
                print_yellow("Too many characters, please try again.\n", 0);
                neutral_wait_pre();
            }
            else{
                answer[-1] = '\0';
                cards = add_card(cards, question, answer);
                while((getchar()) != '\n');
                while(loop){
                    print_card_creation();
                    scanf("%[^\n]", user_input);
                    if(strcmp(user_input, "no") == 0){
                        question_or_answer = 0;
                        loop = 0;
                    } else if (strcmp(user_input, "yes") == 0){
                        question_or_answer = 0;
                        break;
                    } else {
                        print_red("Invalid choice\n", 1);
                        neutral_wait_pre();
                    }
                }
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
            neutral_wait();
        }
    }
    
    if(is_public == 1){
        global_community_decks = add_deck(global_community_decks, name, user.fullname,
             "", is_public, 0, 0, cards);
        save_community_decks(global_community_decks);
    }

    global_decks = add_deck(global_decks, name, user.fullname, user.username,
         is_public, 0, 0, cards);
    update_deck_db(get_last_deck(global_decks));
}


/*******************************************************************************
 * Views all the community decks and allows
 * users to add them to their collction.
 * inputs:
 * - deck_t, deck_t, user_t
 * outputs:
 * - None
*******************************************************************************/
void view_community_decks(user_t user){
    /*printing community decks*/
    while(1){
        clear_screen();
        deck_t temp = global_community_decks;
        char input[MAX_INPUT_LENGTH];
        int i;
        print_community_decks(global_community_decks);
        while((getchar()) != '\n');
        scanf("%[^\n]", input);
        if(!strcmp(input, "exit")){
            return;
        }else{
            temp = global_community_decks;
            int size = get_deck_size(global_community_decks);
            for(i = 0; i < size; i++){
                if(i > 0){
                    temp = temp->next;
                }
                if(!strcmp(input, temp->name)){
                    view_community_deck(temp, user);
                    return;
                }
            }
        }
        print_invalid_deck();
    }
}

/*******************************************************************************
 * Views a single community deck and it's corresponding cards
 * either with or without answers
 * inputs:
 * - deck_t, deck_t, user_t
 * outputs:
 * - None
*******************************************************************************/
void view_community_deck(deck_t deck, user_t user){
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
                global_decks = add_deck(global_decks, deck->name, deck->author,
                    user.username, 0, 0, 0, deck->cards);
                update_deck_db(get_last_deck(global_decks));
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

/*******************************************************************************
 * Menu's to let a user login. returns an int if it was successful or not
 * inputs:
 * - deck_t, deck_t, user_t*
 * outputs:
 * - int
*******************************************************************************/
int login(user_t *user) {
	int success = 0;
	int login_menu_choice = 0;

    while(success == 0){
        print_login_menu();
        scanf("%d", &login_menu_choice);
        printf("\n");
        switch(login_menu_choice) {
            case 1: /* Log in to existing account */
                success = login_existing_account(user);
                break;
            case 2: /*Create a new account.*/
                while((getchar()) != '\n');
                success = create_new_account(user);
                break;
            default:
                print_red("Invalid choice\n", 1);
                success = 0;
                break;
        }
    }
	return success;
}

/*******************************************************************************
 * Menu's to login with an existing account
 * inputs:
 * - deck_t, deck_t, user_t*
 * outputs:
 * - None
*******************************************************************************/
int login_existing_account(user_t *user){
    print_existing_account(user);
    if (check_password(user) == 0) {
        clear_screen();
        print_red("Invalid credentials!\n", 1);
        neutral_wait_pre();
        return 0;   
    }
    else {
        global_decks = load_user_decks(*user);
        char fullname[MAX_AUTHOR_LENGTH];
        get_fullname(*user, fullname);
        strcpy(user->fullname,fullname);
        /*clear_screen();*/
        print_green("Log-in successful.\n", 1);
        wait();
        return 1;
    }
    return 0;
}

/*******************************************************************************
 * Menu's create a new account
 * inputs:
 * - deck_t, deck_t, user_t*
 * outputs:
 * - None
*******************************************************************************/
int create_new_account(user_t *user){
    char input_fullname[MAX_NAME_LENGTH+2] = "";
    char input_username[MAX_USERNAME_LENGTH+2] = "";
    char input_password[MAX_PASSWORD_LENGTH+2] = "";
    print_yellow("Creating a new account!\nEnter details below.\n", 1);
    /*Full name+*/
    int cont = 1;
    while (cont) {
        strcpy(input_fullname, "");
        clear_screen();
        print_yellow("Full name (maximum 40 characters):\n> ", 0);
        scanf("%[^\n]", input_fullname);
        if (strlen(input_fullname) == 0) {
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
            cont = 0;
        }
    }
    cont = 1;
    while((getchar()) != '\n');
    /* Username */
    while (cont) {
        strcpy(input_username, "");
        clear_screen();
        print_yellow("Username (maximum 20 characters):\n> ", 0);
        scanf("%[^\n]", input_username);
        if (check_username_format(input_username)) {
            input_username[-1] = '\0';
            strcpy(user->username, input_username);
            cont = 0;
        }
    }
    cont = 1;
    while((getchar()) != '\n');
    /* Password */
    while (cont) {
        strcpy(input_password, "");
        clear_screen();
        print_yellow("Password (maximum of 20 alphanumeric characters)\n", 0);
        print_yellow("Requires atleast one Number, Capital and lowercase letter\n> ", 0);
        scanf("%[^\n]", input_password);
        if (check_password_format(input_password)) {
            input_password[-1] = '\0';
            strcpy(user->password, input_password);
            cont = 0;
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

int check_username_format(const char username[]){
    user_t temp;
    strcpy(temp.username, username);
    if (strlen(username) == 0) {
        clear_screen();
        print_yellow("Please enter at least one character.\n", 0);
        wait();
        return 0;
    }
    else if(strlen(username) > MAX_USERNAME_LENGTH){
        clear_screen();
        print_yellow("Too many characters, please try again.\n", 0);
        wait();
        return 0;
    }else if(check_username(temp)){
        clear_screen();
        print_yellow("This username is already in use.\n", 0);
        wait();
        return 0;
    }
    int i;
    for(i = 0; i < strlen(username); i++){
        if((username[i] >= 'a' && username[i] <= 'z') ||
            (username[i] >= 'A' && username[i] <= 'Z') ||
            (username[i] >= '0' && username[i] <= '9')){
        }else{
            clear_screen();
            print_yellow("You can only use alphanumeric characters in your username.\n", 0);
            wait();
            return 0;
        }
    }
    return 1;
}

int check_password_format(const char password[]){
    int cont_lowercase = 0;
    int cont_uppercase = 0;
    int cont_number = 0;
    if (strlen(password) == 0) {
        clear_screen();
        print_yellow("Please enter at least one character.\n", 0);
        wait();
        return 0;
    }
    else if(strlen(password) > MAX_PASSWORD_LENGTH){
        clear_screen();
        print_yellow("Too many characters, please try again.\n", 0);
        wait();
        return 0;
    }
    int i;
    for(i = 0; i < strlen(password); i++){
        if((password[i] >= 'a' && password[i] <= 'z')){
            cont_lowercase = 1;
        }else if((password[i] >= 'A' && password[i] <= 'Z')){
            cont_uppercase = 1;
        }else if((password[i] >= '0' && password[i] <= '9')){
            cont_number = 1;
        }else{
            clear_screen();
            print_yellow("You can only use alphanumeric characters in your password.\n", 0);
            wait();
            return 0;
        }
    }
    if(cont_lowercase && cont_uppercase && cont_number){
        return 1;
    }
    clear_screen();
    print_yellow("Your password needs a lowercase character, an uppercase character and a number.\n", 0);
    wait();
    return 0;
}