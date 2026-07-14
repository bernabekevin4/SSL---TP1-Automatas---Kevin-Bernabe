CC = gcc

CFLAGS = -Wall -Wextra -Iinclude

SRC = src/main.c \
      src/automata.c \
      src/evaluador.c

OUT = ejercicio3

all:
	$(CC) $(CFLAGS) $(SRC) -o $(OUT)

run: all
	./$(OUT).exe

clean:
	rm -f $(OUT).exe