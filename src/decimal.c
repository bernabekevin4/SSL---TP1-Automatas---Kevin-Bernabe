#include <ctype.h>
#include "decimal.h"

//Transforma un char en una columna igual que en la tabla
//Implementa el alfabeto reducido
static int columnaDecimal(int c){
    switch (c)
    {
        //Si lee +, devuelve la columna 1.
        case '+':
            return 1;
        //Si lee -, devuelve la columna 2.
        case '-':
            return 2;
        //Si lee un digito, devuelve la columna 0.
        default:
            return 0;
    }
}

//Verifica si es decimal
int esDecimal(char *s){
    //Tabla de transicion / matriz (4 filas, 3 columnas)
    static int tt[4][3] = {
        { 2,1,1 },
        { 2,3,3 },
        { 2,3,3 },
        { 3,3,3 },
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
    //un + o - en medio (devolviendo e = ·), e eventualmente es 2 ESTADO FINAL
    if(e == 2) return 1;

    //e no puede ser 1 ya que es la 1er condicion a ver, y jamas vueve a tt[0] 1era linea
    //Entonces el 3 siempre sera incorrecto

    //Si no cumple con terminar con un numero 
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