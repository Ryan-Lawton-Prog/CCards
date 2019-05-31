#include "crypt.h"

/*******************************************************************************
 * XOR Encryption
 * inputs:
 * - string
 * outputs:
 * - None
*******************************************************************************/
void encrypt(char string[]){
    int i;
    for(i = 0; i < strlen(string); i++){
        string[i] = string[i]^KEY;
    }
}

/*******************************************************************************
 * XOR Decryption
 * inputs:
 * - string
 * outputs:
 * - None
*******************************************************************************/
void decrypt(char string[]){
    int i;
    for(i = 0; i < strlen(string); i++){
        string[i] = string[i]^KEY;
    }
}

/*******************************************************************************
 * Run-Time Compression
 * e.g. aaa -> a3
 * inputs:
 * - string
 * outputs:
 * - char*
*******************************************************************************/
char*compress(char*string){
    int str_len = strlen(string);
    char*final = (char*)malloc(sizeof(char) * ((str_len*2)+1));
    int i;
    int j = 0;
    /*looping through each char*/
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
        /*adding number after char in compressed string*/
        sprintf(str_num, "%d", count);
        final[j] = str_num[0];
        j++;
    }
    final[j] = '\0';
    return final;
}

/*******************************************************************************
 * Run-Time Decompression
 * e.g. a3 -> aaa
 * inputs:
 * - string, int
 * outputs:
 * - char*
*******************************************************************************/
char*decompress(char*string, int max){
    int str_len = strlen(string);
    char*final = (char*)malloc(sizeof(char) * ((max)+1));
    int i;
    int pos = 0;
    /*looping through each char*/
    for(i = 0; i < str_len; i++){
        int j;
        char num[2];
        num[0] = string[i+1];
        int repeat = atoi(num);
        /*depending on number, we add that many chars to final string*/
        for(j = 0; j < repeat; j++){
            final[pos+j] = string[i];
        }
        pos+=j;
        /*we want to loop in pairs so we add an additional increment*/
        i++;
    }
    final[pos] = '\0';
    return final;
}