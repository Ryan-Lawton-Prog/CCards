#ifndef CRYPT_H
#define CRYPT_H

#include "cards.h"

#define KEY_Pos 0xB6
#define KEY_Neg 0xC9
#define MAX_INT_LENGTH 11
#define MAX_KEY_LENGTH 100


/*******************************************************************************
 * Function prototypes
*******************************************************************************/
void encrypt(char[]);
void decrypt(char[]);
char*compress(char*);
char*decompress(char*, int);



#endif