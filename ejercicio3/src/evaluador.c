#include <ctype.h>

// Convierte un carácter numerico ('0'..'9') a su valor entero.
// Devuelve -1 si el caracter no representa un dígito decimal.
static int caracterAEntero(char c){
    if(c >= '0' && c <= '9'){
        return c - '0';
    }

    return -1;
}

// Lee un numero completo de la expresion.
// La lectura finaliza al encontrar un operador o el fin de la cadena.
static int leerNumero(char *expresion, int *i){
    
    int numero = 0;

    while(isdigit(expresion[*i])){
        numero = numero * 10 + caracterAEntero(expresion[*i]);

        (*i)++;
    }

    return numero;

}

// Ejecuta una operacion aritmetica entre dos enteros.
static int ejecutarOperacion(char operador, int a, int b)
{
    switch (operador)
    {
        case '+':
            return a + b;

        case '-':
            return a - b;

        case '*':
            return a * b;
    }

    return 0;
}

// Lee un término completo formado por multiplicaciones.
// Ejemplo: "12*3*4" devuelve 144.
static int leerTermino(char *expresion, int *i)
{
    int termino = leerNumero(expresion, i);

    while (expresion[*i] == '*')
    {
        // Avanza al siguiente número
        (*i)++; 

        int numero = leerNumero(expresion, i);

        termino = ejecutarOperacion('*', termino, numero);
    }

    return termino;
}

// Evalua una expresion respetando
// la precedencia de la multiplicacion.
int evaluarExpresion(char *expresion)
{
    int i = 0;

    // Lee el primer termino
    int resultado = leerTermino(expresion, &i);

    while (expresion[i] != '\0')
    {
        // Guarda el operador + o -
        char operador = expresion[i];
        i++;

        // Lee el siguiente termino
        int termino = leerTermino(expresion, &i);

        // Aplica la operacion al resultado
        resultado = ejecutarOperacion(operador, resultado, termino);
    }

    return resultado;
}