#include <ctype.h>
#include "hexadecimal.h"

//Transforma un char en una columna igual que en la tabla
//Implementa el alfabeto reducido
static int columnaHexadecimal(int c){
    switch (c)
    {
        case 'x':
            return 1;

        case 'X':
            return 1;

        case '0':
            return 0;

        default:
            if ((c >= '1' && c <= '9') ||
                (c >= 'A' && c <= 'F') ||
                (c >= 'a' && c <= 'f') ){
                return 2;   // Columna H
            }

            return 3;       // Columna Otro
    }
}

//Verifica si es hexadecimal
int esHexadecimal(char *s){
    // Tabla de transición (5 estados x 4 columnas del alfabeto reducido)
    static int tt[5][4] = {
        { 1,4,4,4 },
        { 4,2,4,4 },
        { 3,4,3,4 },
        { 3,4,3,4 },
        { 4,4,4,4 },
    };

    int e = 0;
    int i = 0; 
    int c = s[0]; //Para leer los caracteres
    while (c != '\0')
    {
        e = tt[e][columnaHexadecimal(c)];
        i++;
        c = s[i];
    }
    
    //Ya que deberia terminar con un hexadecimal
    //y no tener algun caracter distinto en medio
    //e sera 3 ESTADO FINAL.
    if (e == 3) return 1;

    return 0;

}

//Verifica que una palabra pertenezca al alfabeto (x, X, A..F, a..f, 0..9)
int verificarHexadecimal(char *s)
{
    int i;

    for(i = 0; s[i]; i++){

        if (!( isdigit(s[i]) ||
               s[i] == 'x' || s[i] == 'X' ||
               (s[i] >= 'A' && s[i] <= 'F') ||
               (s[i] >= 'a' && s[i] <= 'f') ))
        {
            return 0;
        }
    }

    return 1;
}