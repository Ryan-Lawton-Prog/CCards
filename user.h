#ifndef USER_H
#define USER_H

#include "cards.h"

#define MAX_NAME_LENGTH 40
#define MAX_CARD_ANSWER_LENGTH 100
#define DB_USERS "DB_USERS"

/*******************************************************************************
 * deck struct - used as a linked list for storing each deck without having
 * to set re-adjust the size of a deck array or setting a maximum
*******************************************************************************/
struct user{
    char fullname[MAX_NAME_LENGTH+1];
    char username[MAX_NAME_LENGTH+1];
    char password[MAX_NAME_LENGTH+1];
};
typedef struct user user_t;

/*******************************************************************************
 * Function prototypes
*******************************************************************************/
user_t create_user();
user_t update_user(user_t, const char[], const char[], const char[]);
void get_fullname(user_t, char[]);
int check_username(user_t);
int check_password(user_t*);
user_t set_fullname(user_t, const char[]);
user_t set_username(user_t, const char[]);
user_t set_password(user_t, const char[]);
void update_user_db(user_t);

#endif