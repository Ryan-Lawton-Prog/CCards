main: cards.c test.c Main.c
	gcc -Wall -Werror -ansi -o main cards.c test.c Main.c -lm
