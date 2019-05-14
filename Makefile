main: cards.c test.c main.c
	gcc -Wall -Werror -ansi -o main cards.c test.c main.c -lm
