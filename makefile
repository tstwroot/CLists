all:
	gcc -c list.c -o list.o
	gcc main.c -o main list.o