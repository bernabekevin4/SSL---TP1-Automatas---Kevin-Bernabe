#include <ctype.h>
#include "octal.h"

//Transforma un char en una columna igual que en la tabla
//Implementa el alfabeto reducido
static int columnaOctal(int c){
    switch (c)
    {
        case '0':
            return 0;

        default:
            if (c >= '1' && c <= '7'){
                return 1;
            }
            return 2;
    }
}

// Verifica si la cadena representa una constante octal
int esOctal(char *s){
    //Tabla de transicion / matriz (4 filas, 3 columnas)
    static int tt[4][3] = {
        { 1,3,3 },
        { 3,2,3 },
        { 2,2,3 },
        { 3,3,3 },
    };

    int e = 0;
    int i = 0; 
    int c = s[0]; //Para leer los caracteres
    while (c != '\0')
    {
        e = tt[e][columnaOctal(c)];
        i++;
        c = s[i];
    }
    
    //Ya que deberia terminar con un numero y no tener
    //cualquier otro caracter en medio o numero mayor 7, e eventualmente es 2 ESTADO FINAL
    if(e == 2) return 1;

    //Si no cumple con terminar con un numero 
    return 0;
}

//Verifica que una palabra pertenezca al alfabeto (0..7)
int verificarOctal(char *s)
{
    int i;

    //Mientras s[i] sea distinto de \0
    for(i=0; s[i]; i++){
        //Cadena solo puede tener digitos entre el 0 y 7, de lo contrario devuelve un false: 0
        if (s[i] < '0' || s[i] > '7') {
            return 0;
        }
    }

    //Si cumple con el alfabeto devuelve 1: true
    return 1;
}