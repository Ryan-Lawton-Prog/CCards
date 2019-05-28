main: cards.c crypt.c user.c deck.c test.c print.c main.c
	gcc -Wall -Werror -ansi -o main cards.c crypt.c user.c deck.c test.c print.c main.c -lm
