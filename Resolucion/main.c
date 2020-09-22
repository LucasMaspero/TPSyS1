#include "scanner.h"

int cantIdentificadores = 0;
int cantConstantesEnteras = 0;
int cantNumerales = 0;
int cantErrores = 0;

TOKEN c;

int main()
{
    do
    {
        c = scanner();

        switch (c)
        {
            case TOKEN_IDENTIFICADOR:
              printf("identificador\n");
              cantIdentificadores++;
              break;

            case TOKEN_CONSTANTE_ENTERA:
              printf("constante entera\n");
              cantConstantesEnteras++;
              break;

             case TOKEN_NUMERAL:
              printf("Numeral\n");
              cantNumerales++;
              break;

            case TOKEN_ERROR:
              printf("error\n");
              cantErrores++;
              break;

            case TOKEN_FDT:
              break;
        }

    } while (c != TOKEN_FDT);

    printf("----\n");
    printf("Totales:\n");
    printf("Identificadores: %d\n", cantIdentificadores);
    printf("Constantes enteras: %d\n", cantConstantesEnteras);
    printf("Numerales: %d\n", cantNumerales);
    printf("Errores: %d\n", cantErrores);

    return 0;
}