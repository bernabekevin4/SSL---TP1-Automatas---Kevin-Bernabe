#include <ctype.h>
#include "automata.h"

// Transforma un char en una columna igual que en la tabla
// Implementa el alfabeto reducido
static int columnaExpresion(int c){
    if (c == '+' || c == '-' || c == '*'){
        return 1;
    }
    
    if(isdigit(c)){
        return 0;
    }

    return 2;
}

//Verifica si la expresion pertenece a una operacion valida.
int esExpresionValida(char *s){
    // Tabla de transición (4 estados x 3 columnas del alfabeto reducido)
    static int tt[4][3] = {
        { 1,3,3 },
        { 1,2,3 },
        { 1,3,3 },
        { 3,3,3 },
    };

    int e = 0;
    int i = 0; 
    int c = s[0]; //Para leer los caracteres
    while (c != '\0')
    {
        e = tt[e][columnaExpresion(c)];
        i++;
        c = s[i];
    }
    
    //Ya que deberia terminar con un numero, e sera 1 ESTADO FINAL.
    if (e == 1) return 1;

    return 0;

}

//Verifica que una expresion pertenezca al alfabeto (+,-,*, 0..9)
int verificarExpresion(char *s)
{
    int i;

    for(i=0; s[i]; i++){
        //Cadena solo puede tener digitos, + y -, si obtiene otra cosa devuelve 0: false
        if(!( s[i] == '+' || s[i] == '-' || s[i] == '*' || isdigit(s[i]) )){
            return 0;
        }
    }

    // Si cumple con el alfabeto devuelve 1: true
    return 1;
}