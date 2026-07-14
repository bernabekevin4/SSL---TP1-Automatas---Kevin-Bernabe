#include <stdio.h>
#include "conversion.h"

int main()
{
    printf("Ejercicio 2 - Caracter a Entero\n");
    printf("----------------------------------\n");

    char c = 'a';
    char a = '1';
    char f = '5';
    char b = '9';
    char i = '+';

    printf("'%c' -> %d\n", c, caracterAEntero(c));
    printf("'%c' -> %d\n", a, caracterAEntero(a));
    printf("'%c' -> %d\n", f, caracterAEntero(f));
    printf("'%c' -> %d\n", b, caracterAEntero(b));
    printf("'%c' -> %d\n", i, caracterAEntero(i));

    return 0;
}

// gcc src/main.c src/conversion.c -Iinclude -o ejercicio2
