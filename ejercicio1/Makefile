# Compilador a usar
CC = gcc

CFLAGS = -Wall -Wextra -Iinclude

# Lista de los archivo fuente .c
SRC = src/main.c \
      src/decimal.c \
      src/octal.c \
      src/hexadecimal.c

# Nombre del ejecutable
OUT = ejercicio1

# Crea el ejecutable
all:
	$(CC) $(CFLAGS) $(SRC) -o $(OUT)

# Ejecuta el programa
run: all
	./$(OUT)

# Borra el ejecutable generado
clean:
	del /Q $(OUT).exe 2>nul || rm -f $(OUT)