#include "conversion.h"

// Convierte un carácter numérico ('0'..'9') a su valor entero.
// Devuelve -1 si el carácter no representa un dígito decimal.
int caracterAEntero(char c){
    if(c >= '0' && c <= '9'){
        return c - '0';
    }

    return -1;
}