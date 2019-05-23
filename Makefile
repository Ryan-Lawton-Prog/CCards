main: cards.c deck.c user.c test.c print.c main.c
	gcc -Wall -Werror -ansi -o main cards.c deck.c user.c test.c print.c main.c -lm
