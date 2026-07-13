#include <stdio.h>
#include "decimal.h"
#include "octal.h"
#include "hexadecimal.h"

static void analizarConstante(char *buffer,
                              int *cantDecimal,
                              int *cantOctal,
                              int *cantHexadecimal,
                              int *cantErrores)
{
    if (verificarDecimal(buffer) && esDecimal(buffer)) {
        printf("%s -> Constante decimal\n", buffer);
        (*cantDecimal)++;
    }
    else if (verificarOctal(buffer) && esOctal(buffer)) {
        printf("%s -> Constante octal\n", buffer);
        (*cantOctal)++;
    }
    else if (verificarHexadecimal(buffer) && esHexadecimal(buffer)) {
        printf("%s -> Constante hexadecimal\n", buffer);
        (*cantHexadecimal)++;
    }
    else {
        printf("%s -> Error lexico\n", buffer);
        (*cantErrores)++;
    }
}

int main()
{
    printf("Trabajo Practico 1 - Automatas\n");
    printf("----------------------------------\n");

    int cantDecimal = 0;
    int cantOctal = 0;
    int cantHexadecimal = 0;
    int cantErrores = 0;

    char palabra[] = "3123@@0123@0x122@+123412131@0XAFc";
    char buffer[100];
    int j = 0;


    printf("Cadenas leidas: \n");
    for(int i = 0; palabra[i]; i++){
        
        if(palabra[i] != '@'){
            buffer[j++] = palabra[i];

        }else{
            buffer[j] = '\0';
            analizarConstante(buffer, &cantDecimal, &cantOctal, &cantHexadecimal, &cantErrores);
            j = 0;
        }
    }

    if(j > 0){
        buffer[j] = '\0';
        analizarConstante(buffer, &cantDecimal, &cantOctal, &cantHexadecimal, &cantErrores);
    }

    printf("----------------------------------\n");
    printf("RESUMEN de constantes leidas: \n");
    printf("----------------------------------\n");
    printf("Constantes decimales: %d\n", cantDecimal);
    printf("Constantes octales: %d\n", cantOctal);
    printf("Constantes hexadecimales: %d\n", cantHexadecimal);
    
    if (cantErrores > 0) {
        printf("\nSe detectaron errores %d lexicos.\n", cantErrores);
    } else {
        printf("\nNo se detectaron errores lexicos.\n");
    }

    return 0;
}

// gcc src/main.c src/decimal.c src/octal.c src/hexadecimal.c -Iinclude -o tp1