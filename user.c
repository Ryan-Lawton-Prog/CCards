#include "user.h"

user_t create_user(){
    user_t temp;
    strcpy(temp.fullname,"");
    strcpy(temp.username,"");
    strcpy(temp.password,"");
}

user_t update_user(user_t user, const char fullname[], const char username[], const char password[]){
    return user;
}

void get_fullname(user_t user, char fullname[]){
    strcpy(fullname, user.fullname);
}

int check_username(user_t user, const char username[]){
    return 1;
}

int check_password(user_t user, const char password[]){
    return 1;
}

user_t set_fullname(user_t user, const char fullname[]){
    strcpy(user.fullname, fullname);
    return user;
}

user_t set_username(user_t user, const char username[]){
    strcpy(user.username, username);
    return user;
}

user_t set_password(user_t user, const char password[]){
    strcpy(user.password, password);
    return user;
}

user_t set_user(user_t user, const char fullname[], const char username[], const char password[]){
    strcpy(user.fullname, fullname);
    strcpy(user.username, username);
    strcpy(user.password, password);
    return user;
}