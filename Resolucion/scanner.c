#include "scanner.h"

char caracter_actual;
ESTADO estado_actual = 0;
const int estados_aceptores[CANT_ESTADOS_ACEPTORES] = { 4, 5, 6, 7, 8 };
static int tabla_de_transicion[9][6] = {
  {7,  2,  1,  3,  0,  8 },
  {4,  1,  1,  4,  4,  4 },
  {5,  2,  5,  5,  5,  5 },
  {6,  6,  6,  3,  6,  6 },
  {-1, -1, -1, -1, -1, -1},
  {-1, -1, -1, -1, -1, -1},
  {-1, -1, -1, -1, -1, -1},
  {-1, -1, -1, -1, -1, -1},
  {-1, -1, -1, -1, -1, -1}};

int esEstadoAceptor(ESTADO estado)
{
  for (int i = 0 ; i < CANT_ESTADOS_ACEPTORES ; i++) 
  {
    if (estados_aceptores[i] == estado) 
    {
      return 1;
    }
  }

  return 0;
}

int obtenerNuevoEstado(char caracter)
{
  if (isalpha(caracter)) 
  {
    return tabla_de_transicion[estado_actual][CARACTER_LETRA];
  }
  else if (isdigit(caracter)) 
  {
    return tabla_de_transicion[estado_actual][CARACTER_DIGITO];
  }
  else if(isspace(caracter)) 
  {
    return tabla_de_transicion[estado_actual][CARACTER_ESPACIO];
  }
  else if (caracter == '#')
  {
    return tabla_de_transicion[estado_actual][CARACTER_NUMERAL];
  }
  else if (caracter == EOF)
  {
    return tabla_de_transicion[estado_actual][CARACTER_FIN_DE_ARCHIVO];
  }
    
  return tabla_de_transicion[estado_actual][CARACTER_OTRO];
}

TOKEN aceptarToken(ESTADO estado)
{
  switch (estado)
	{
		case ESTADO_ACEPTOR_IDENTIFICADOR:
      ungetc(caracter_actual, stdin);
		  return TOKEN_IDENTIFICADOR;

		case ESTADO_ACEPTOR_CONSTANTE_ENTERA:
      ungetc(caracter_actual, stdin);
		  return TOKEN_CONSTANTE_ENTERA;

    case ESTADO_ACEPTOR_NUMERAL:
		  return TOKEN_NUMERAL;

		case ESTADO_ACEPTOR_ERROR:
      ungetc(caracter_actual, stdin);
		  return TOKEN_ERROR;

    default:
      return TOKEN_FDT;
	}

	return TOKEN_FDT;
}

void reiniciar() {
  estado_actual = 0;
}

TOKEN scanner()
{
	do
	{
 		caracter_actual = getchar(); // Leer Caracter
    estado_actual = obtenerNuevoEstado(caracter_actual); // Transicionar de Estado
	} while (!esEstadoAceptor(estado_actual));

  reiniciar();

	return aceptarToken(estado_actual); // Aceptar y Devolver Token
}