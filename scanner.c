#include "scanner.h"

int estado_actual = 0;
char ant;
char c;
static int tabla[8][5] = {
    { 1 , 3 , 5 , 7 , 0},
    { 1 , 1 , 2 , 2 , 2},
    {99 ,99 ,99 ,99 ,99},
    { 4 , 3 , 4 , 4 , 4},
    {99 ,99 ,99 ,99 ,99},
    { 6 , 6 , 5 , 6 , 6},
    {99 ,99 ,99 ,99 ,99},
    {99 ,99 ,99 ,99 ,99}
    };
const bool estados[8] = {false,false,true,false,true,false,true,true};
// ------------------------------------------------------------------------------------------
bool deboParar(int e)
{
	return estados[e];
}
// ------------------------------------------------------------------------------------------
int cambiarEstado(char c)
{
  if(isalpha(c))
    return tabla[estado_actual][LETRA];
  else if(isdigit(c))
    return tabla[estado_actual][DIGITO];
  else if(isspace(c))
    return tabla[estado_actual][ESPACIO];
  else if (c == EOF )
    return tabla[estado_actual][FDC];

    return tabla[estado_actual][OTRO];
}
// -----------------------------------------------------------------------------------------
TOKEN aceptarToken(int estado_actual)
{
    switch(estado_actual)
	{
		case 2:
        ungetc(c,stdin);
		return IDENTIFICADOR;
		case 4:
        ungetc(c,stdin);
		return CONSTANTE_ENTERA;
		case 6:
        ungetc(c,stdin);
		return ERROR;

	}
	return FDT;
}
// -----------------------------------------------------------------------------------------
TOKEN scanner()
{
	do
	{
 		c  = getchar();
        estado_actual = cambiarEstado(c);
	}while(!deboParar(estado_actual));
	aceptarToken(estado_actual);
	estado_actual = 0;
}
