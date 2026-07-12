#include <ctype.h>
#include "decimal.h"

//Transforma un char en una columna igual que en la tabla
//Implementa el alfabeto reducido
static int columnaDecimal(int c){
    switch (c)
    {
        case '+':
            return 1;

        case '-':
            return 2;

        case '0':
            return 3;

        default:
            if (c >= '1' && c <= '9'){
                return 0;   // Columna D
            }
            return 4;       // Columna Otro
    }
}

//Verifica si es decimal
int esDecimal(char *s){
    // Tabla de transición (5 estados x 5 columnas del alfabeto reducido)
    static int tt[5][5] = {
        { 3,2,2,1,4 },
        { 4,4,4,4,4 },
        { 3,4,4,4,4 },
        { 3,4,4,3,4 },
        { 4,4,4,4,4 },
    };

    int e = 0;
    int i = 0; 
    int c = s[0]; //Para leer los caracteres
    while (c != '\0')
    {
        e = tt[e][columnaDecimal(c)];
        i++;
        c = s[i];
    }
    
    //Ya que deberia terminar con un numero y no tener
    //un + o - en medio, e eventualmente es 3 ESTADO FINAL.
    //Si resulta solo ser un 0, e sera 1 ESTADO FINAL.
    if (e == 1 || e == 3) return 1;

    return 0;

}

//Verifica que una palabra pertenezca al alfabeto (+,-, 0..9)
int verificarDecimal(char *s)
{
    int i;

    //Mientras s[i] sea distinto de \0
    for(i=0; s[i]; i++){
        //Cadena solo puede tener digitos, + y -, si obtiene otra cosa devuelve 0: false
        if(!( s[i] == '+' || s[i] == '-' || isdigit(s[i]) )){
            return 0;
        }
    }

    //Si cumple con el alfabeto devuelve 1: true
    return 1;
}