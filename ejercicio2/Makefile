CC = gcc

CFLAGS = -Wall -Wextra -Iinclude

SRC = src/main.c \
      src/conversion.c

OUT = ejercicio2

all:
	$(CC) $(CFLAGS) $(SRC) -o $(OUT)

run: all
	./$(OUT).exe

clean:
	rm -f $(OUT).exe