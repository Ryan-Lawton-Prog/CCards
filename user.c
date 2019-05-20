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
 * - user
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
        char temp_l[100] = {'\0'};
        char temp_r[100] = {'\0'};
        eof = fscanf(filep, "%s %[^\n]", temp_l, temp_r) != EOF;
        if(!eof){
            break;
        }
        if(!strcmp(temp_l, "username")){
            if(!strcmp(temp_r, user.username)){
                fclose(filep);
                return 0;
            }
        }
    }
    fclose(filep);
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
    FILE * filep;
    filep = fopen(DB_USERS, "r");
    if(filep == NULL){
        printf("Could not find Users DB\n");
        return 0;
    }
    int eof = 1;
    while(eof){
        char temp_l[100] = {'\0'};
        char temp_r[100] = {'\0'};
        eof = fscanf(filep, "%s %[^\n]", temp_l, temp_r) != EOF;
        if(!eof){
            break;
        }
        if(!strcmp(temp_l, "username") && !strcmp(temp_r, user.username)){
            eof = fscanf(filep, "%s %[^\n]", temp_l, temp_r) != EOF;
            if(!strcmp(temp_l, "password") && !strcmp(temp_r, user.password)){
                fclose(filep);
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
 * - user_t, string (username)
 * outputs:
 * - user_t
*******************************************************************************/
user_t set_password(user_t user, const char password[]){
    strcpy(user.password, password);
    return user;
}

void update_user_db(user_t user){
    FILE * filep;
    filep = fopen(DB_USERS, "a");
    if(filep == NULL){
        printf("Could not find Users DB\n");
        return;
    }
    fprintf(filep, "%s %s\n", "username", user.username);
    fprintf(filep, "%s %s\n", "password", user.password);
    fprintf(filep, "%s %s\n", "fullname", user.fullname);
    fclose(filep);
}