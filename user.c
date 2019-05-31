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
user_t update_user(user_t user, const char fullname[], 
        const char username[], const char password[]){
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
 * - user_t
 * outputs:
 * - none
*******************************************************************************/
int check_username(user_t user){
    FILE * filep;
    filep = fopen(DB_USERS, "r");
    if(filep == NULL){
        printf("Could not find Users DB\n");
        return 1;
    }
    int eof = 1;
    while(eof){
        char temp_l[MAX_INPUT_LENGTH];
        char temp_r[MAX_INPUT_LENGTH];
        eof = fscanf(filep, "%s %[^\n]", temp_l, temp_r) != EOF;
        decrypt(temp_r);
        strcpy(temp_r, decompress(temp_r, MAX_USERNAME_LENGTH));
        if(!eof){
            break;
        }
        /*If username found, return that we found an existing user*/
        if(!strcmp(temp_l, "username")){
            if(!strcmp(temp_r, user.username)){
                fclose(filep);
                return 1;
            }
        }
    }
    fclose(filep);
    return 0;
}

/*******************************************************************************
 * Checks if the password is correct for a given user
 * inputs:
 * - user_t*
 * outputs:
 * - int
*******************************************************************************/
int check_password(user_t*user){
    FILE * filep;
    filep = fopen(DB_USERS, "r");
    if(filep == NULL){
        printf("Could not find Users DB\n");
        return 0;
    }
    int eof = 1;
    while(eof){
        char temp_l[MAX_INPUT_LENGTH];
        char temp_r[MAX_INPUT_LENGTH];
        eof = fscanf(filep, "%s %[^\n]", temp_l, temp_r) != EOF;
        if(!eof){
            break;
        }
        decrypt(temp_r);
        strcpy(temp_r, decompress(temp_r, MAX_USERNAME_LENGTH));
        /*Verifying that the password we are checking is for right user*/
        if(!strcmp(temp_l, "username") && !strcmp(temp_r, user->username)){
            eof = fscanf(filep, "%s %[^\n]", temp_l, temp_r) != EOF;
            decrypt(temp_r);
            strcpy(temp_r, decompress(temp_r, MAX_PASSWORD_LENGTH));
            /*Checking the users password*/
            if(!strcmp(temp_l, "password") && !strcmp(temp_r, user->password)){
                eof = fscanf(filep, "%s %[^\n]", temp_l, temp_r) != EOF;
                decrypt(temp_r);
                strcpy(temp_r, decompress(temp_r, MAX_NAME_LENGTH));
                strcpy(user->fullname, temp_r);
                fclose(filep);
                /*Return that password is correct for user*/
                return 1;
            }
        }
    }
    fclose(filep);
    return 0;
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
 * - user_t, string (password)
 * outputs:
 * - user_t
*******************************************************************************/
user_t set_password(user_t user, const char password[]){
    strcpy(user.password, password);
    return user;
}

/*******************************************************************************
 * Updates the user database with new user credentials
 * inputs:
 * - user_t
 * outputs:
 * - None
*******************************************************************************/
void update_user_db(user_t user){
    FILE * filep;
    /*append new user to end of db*/
    filep = fopen(DB_USERS, "a");
    if(filep == NULL){
        printf("Could not find Users DB\n");
        return;
    }
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
    char fullname[MAX_NAME_LENGTH];

    strcpy(username, compress(user.username));
    strcpy(password, compress(user.password));
    strcpy(fullname, compress(user.fullname));

    encrypt(username);
    encrypt(password);
    encrypt(fullname);

    fprintf(filep, "%s %s\n", "username", username);
    fprintf(filep, "%s %s\n", "password", password);
    fprintf(filep, "%s %s\n", "fullname", fullname);
    fclose(filep);
}