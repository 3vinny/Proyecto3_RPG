#ifndef JUEGO_H
#define JUEGO_H

#include "abb.h"
#include "stdio.h"
#include "grafo.h"
#include <stdbool.h>

typedef struct s_GameState
{
    bool ejecutando;
    int id_actual;
    s_Abb T;
    //variables / structs / etc
} s_GameState;

int seleccionar_opcion(void);

#endif
