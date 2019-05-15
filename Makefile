main: cards.c deck.c test.c menu.c main.c
	gcc -Wall -Werror -ansi -o main cards.c deck.c test.c menu.c main.c -lm
