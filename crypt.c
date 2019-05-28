#include "crypt.h"

void encrypt(char string[]){
    int i;
    for(i = 0; i < strlen(string); i++){
        string[i] = string[i]^KEY_Pos;
        
    }
    scanf("%d", &i);
}

void decrypt(char string[]){
    int i;
    for(i = 0; i < strlen(string); i++){
        string[i] = string[i]^KEY_Pos;
    }
}

char*compress(char*string){
    int str_len = strlen(string);
    char*final = (char*)malloc(sizeof(char) * ((str_len*2)+1));
    int i;
    int j = 0;
    for(i = 0; i < str_len; i++){
        final[j] = string[i];
        j++;
        int count = 1;
        while (i + 1 < str_len && string[i] == string[i+1]){
            count++;
            i++;
            if(count >= 8){
                break;
            }
        }
        char str_num[MAX_INT_LENGTH];
        sprintf(str_num, "%d", count);
        final[j] = str_num[0];
        j++;
    }
    final[j] = '\0';
    return final;
}

char*decompress(char*string, int max){
    int str_len = strlen(string);
    char*final = (char*)malloc(sizeof(char) * ((max)+1));
    int i;
    int pos = 0;
    for(i = 0; i < str_len; i++){
        int j;
        printf("current: %s:%c\n", string, string[i]);
        for(j = 0; j < atoi(&string[i+1]); j++){
            final[pos+j] = string[i];
        }
        pos+=j;
        i++;
    }
    printf("THIS WORKS");
    final[pos] = '\0';
    printf("%s\n", final);
    scanf("%d", &i);

    return final;
}