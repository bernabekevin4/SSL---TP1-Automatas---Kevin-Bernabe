#include <stdio.h>
#include "automata.h"
#include "evaluador.h"

int main()
{
    char expresion[] = "3+4*7+3-5";

    printf("Ejercicio 3 - Resultado de expresion \n");
    printf("-------------------------------------\n");
    printf("Expresion a evaluar: %s\n", expresion);

    if (verificarExpresion(expresion) && esExpresionValida(expresion)){
        printf("Expresion valida\n");

        printf("Resultado: %d\n", evaluarExpresion(expresion));
    }else{
        printf("Expresion invalida\n");
    }

    return 0;
}

// gcc src/main.c src/evaluador.c src/automata.c -Iinclude -o ejercicio3