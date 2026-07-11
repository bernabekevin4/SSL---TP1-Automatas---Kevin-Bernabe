#include <stdio.h>
#include "decimal.h"

int main()
{
    printf("Trabajo Practico 1 - Automatas\n");

    char palabra[] = "23+324";

    if(verificarDecimal(palabra)){
        if(esDecimal(palabra)){
            printf("Es decimal\n");
        }
    }

    return 0;
}

// gcc src/main.c src/decimal.c -Iinclude -o tp1