#include <stdio.h>
#include "decimal.h"
#include "octal.h"
#include "hexadecimal.h"

int main()
{
    printf("Trabajo Practico 1 - Automatas\n");

    char palabra[] = "0xG1";

    if (verificarDecimal(palabra) && esDecimal(palabra)) {
        printf("Es decimal\n");
    }
    else if (verificarOctal(palabra) && esOctal(palabra)) {
        printf("Es octal\n");
    }
    else if (verificarHexadecimal(palabra) && esHexadecimal(palabra)) {
        printf("Es hexadecimal\n");
    }
    else {
        printf("Error lexico\n");
    }

    return 0;
}

// gcc src/main.c src/decimal.c src/octal.c src/hexadecimal.c -Iinclude -o tp1