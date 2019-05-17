#include "user.h"

/*******************************************************************************
 * Used to create an empty user
 * inputs:
 * - none
 * outputs:
 * - user_t
*******************************************************************************/
user_t create_user(){
    user_t temp;
    strcpy(temp.fullname,"");
    strcpy(temp.username,"");
    strcpy(temp.password,"");
    return temp;
}

/*******************************************************************************
 * Update a users information
 * inputs:
 * - user_t, string (fullname), string (username), string (password)
 * outputs:
 * - user_t
*******************************************************************************/
user_t update_user(user_t user, const char fullname[], const char username[], const char password[]){
    strcpy(user.fullname, fullname);
    strcpy(user.username, username);
    strcpy(user.password, password);
    return user;
}

/*******************************************************************************
 * Assigns a users fullname to a char array pointer
 * inputs:
 * - user_t, string (fullname)
 * outputs:
 * - none
*******************************************************************************/
void get_fullname(user_t user, char fullname[]){
    strcpy(fullname, user.fullname);
}

/*******************************************************************************
 * Checks a submitted users username and checks to see if it exists
 * inputs:
 * - user
 * outputs:
 * - none
*******************************************************************************/
int check_username(user_t user){
    return 1;
}

/*******************************************************************************
 * Checks a submitted users password and checks to see if it exists
 * inputs:
 * - user
 * outputs:
 * - none
*******************************************************************************/
int check_password(user_t user){
    return 1;
}

/*******************************************************************************
 * Sets the fullname of a user
 * inputs:
 * - user_t, string (fullname)
 * outputs:
 * - user_t
*******************************************************************************/
user_t set_fullname(user_t user, const char fullname[]){
    strcpy(user.fullname, fullname);
    return user;
}

/*******************************************************************************
 * Sets the username of a user
 * inputs:
 * - user_t, string (username)
 * outputs:
 * - user_t
*******************************************************************************/
user_t set_username(user_t user, const char username[]){
    strcpy(user.username, username);
    return user;
}

/*******************************************************************************
 * Sets the password of a user
 * inputs:
 * - user_t, string (username)
 * outputs:
 * - user_t
*******************************************************************************/
user_t set_password(user_t user, const char password[]){
    strcpy(user.password, password);
    return user;
}