#ifndef SCANNER_H_INCLUDED
#define SCANNER_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

typedef enum{IDENTIFICADOR,CONSTANTE_ENTERA, ERROR, FDT} TOKEN; // enum{Letra, Digito, Caracter Especial, Fin de Texto, Espacio}
typedef enum{LETRA, DIGITO, OTRO, FDC, ESPACIO} CARACTER;

// ---------------------------------------

TOKEN scanner();
bool deboParar(int e);
bool esEstadoFinal(int estado);
int cambiarEstado(char c);


#endif // SCANNER_H_INCLUDED
