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

        //Por cada digito que tenga el numero, multiplica por 10 y lo suma
        numero = numero * 10 + caracterAEntero(expresion[*i]);

        (*i)++;
    }

    return numero;

}

// Ejecuta una operacion aritmetica entre dos enteros segun un operador recibido.
static int ejecutarOperacion(char operador, int a, int b){
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

// Lee un término completo. Se toma un caso especial al manejar multiplicaciones *
// Ejemplo: "12*3*4" devuelve 144 como un mismo termino.
static int leerTermino(char *expresion, int *i){
    
    // Lee hasta encontrar un operador
    int termino = leerNumero(expresion, i);

    // Si encuentra un *, maneja la multiplicacion
    while (expresion[*i] == '*'){
        // Avanza al siguiente número
        (*i)++; 

        //Vuelve a leer un numero hasta encontrar un operador
        int numero = leerNumero(expresion, i);

        // Multiplica al termino anteriormente encontrado por este numero
        termino = ejecutarOperacion('*', termino, numero);

        // Se repite si luego de estas operaciones, conforme cambia i, expresion[*i] sigue siendo igual a '*'
    }

    // Retorna el resultado del termino leido (solo numero leido u operado con *)
    return termino;
}

// Evalua una expresion respetando la precedencia de la multiplicacion.
int evaluarExpresion(char *expresion){
    int i = 0;

    // Lee el primer termino y almacena el resultado a lo largo de las operaciones. 
    int resultado = leerTermino(expresion, &i);

    while (expresion[i] != '\0'){
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