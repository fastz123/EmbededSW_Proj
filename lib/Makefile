CC = gcc
CFLAGS = -g -Wall -I../include
OUTPUT = libfuncs.a
OBJFILES = check_sudoku.o
.PHONY: clean

$(OUTPUT): $(OBJFILES)
	ar rv $(OUTPUT) $(OBJFILES)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm *.o $(OUTPUT)
