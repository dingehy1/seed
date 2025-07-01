main: main.c editor.c process.c file.c show.c
	gcc -std=c99 -Wall main.c editor.c process.c file.c show.c -o main