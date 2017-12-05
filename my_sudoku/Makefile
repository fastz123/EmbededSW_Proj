CC = gcc
CFLAGS = -g -Wall
TARGET = test

.PHONY: all clean

all:
	gcc -g -c -I../include main.c -o main.o
	gcc -o main -L../lib main.o  -lfuncs
	cp main ~/makehw/program
clean:
	rm *.o
	rm main
