//////////////////////////////////////////////////////////////////////////////////////
/*
      TP0 - 2018
      "Un escáner elemental"
      Grupo 03

    • Ordóñez Julián Mateo
      1602974
    • Torres Schulten Manuel
      160.688.8
    • Viegas Manuel
      150.205.0
    • Viñas Alejandro Fabian
      160.613-0
                                                                                    */
//////////////////////////////////////////////////////////////////////////////////////


#include "scanner.h"
int cantIdentificadores = 0;
int cantConstantes = 0;
int cantErrores = 0;
TOKEN c;

int main()
{
    printf("Los resultados del datos.txt son: \n\n");
    do
    {
        c = scanner();
        switch(c)
        {
            case IDENTIFICADOR:
            printf("identificador\n");
            cantIdentificadores++;
            break;
            case CONSTANTE_ENTERA:
            printf("constante entera\n");
            cantConstantes++;
            break;
            case ERROR:
            printf("error\n");
            cantErrores++;
            break;
            case FDT:
            break;
            }
    }while(c!=FDT);

    printf("----\n");
    printf("Totales\n");
    printf("Identificadores: %d\n",cantIdentificadores);
    printf("Constantes enteras: %d\n",cantConstantes);
    printf("Errores: %d\n",cantErrores);

    return 0;
}
