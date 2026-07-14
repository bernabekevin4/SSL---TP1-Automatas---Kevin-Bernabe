#include <stdio.h>
#include "automata.h"
#include "evaluador.h"

int main()
{
    char expresion[] = "12+3*4*2-5";

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
