#ifndef JUEGO_H
#define JUEGO_H

#include "abb.h"
#include "stdio.h"
#include "grafo.h"
#include "lista.h"
#include "pendientes.h"
#include <stdbool.h>

typedef struct s_GameState
{
    bool ejecutando;
    int id_actual;
    s_Abb abb;
    s_Grafo grafo;
    s_Lista visitadas;
    s_Pendientes pendientes;
    //variables / structs / etc
} s_GameState;

/* ==== FUNCIONES ==== */
/**
 * @brief Inicializa todos los campos del estado a valores seguros.
 *        Debe llamarse antes que cualquier otra función de juego.
 * @param gs Puntero al estado (no NULL).
 */
void juego_inicializar (s_GameState *gs);

/**
 * @brief Libera toda la memoria dinámica asociada al estado.
 *        Llamar SIEMPRE al salir del juego.
 * @param gs Puntero al estado (no NULL).
 */
void juego_destruir(s_GameState *gs);

/**
 * @brief Seleccionar opcion en el juego
 */
int seleccionar_opcion(void);

#endif
