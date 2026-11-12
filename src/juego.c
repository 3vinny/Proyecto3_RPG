#include "juego.h"

int seleccionar_opcion(void)
{
    int opcion = 0;
    printf("Elige una opcion: ");
    scanf("%d", &opcion);
    return opcion;
}