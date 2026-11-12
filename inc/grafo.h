#ifndef GRAFO_H
#define GRAFO_H

#include "habitacion.h"
#include <stdbool.h>

typedef struct s_Adyacente
{
    int id_vecino;
    struct s_Adyacente *siguiente; // siguiente en lista
} s_Adyacente;

typedef struct s_Vertice
{
    int id;
    s_Adyacente *adyacentes;
    struct s_Vertice *siguiente;
} s_Vertice;

typedef struct s_Grafo
{
    /* data */
    s_Vertice *vertices;
    int num_vertices;
    int num_aristas;
} s_Grafo;

/* ==== FUNCIONES: INICIAR/DESTRUIR ==== */
void grafo_crear(s_Grafo *grafo);
void grafo_destruir(s_Grafo *grafo);

/* ==== VERTICES ==== */

/* ==== ARISTAS ==== */

/* ==== BUSQUEDA ==== */

/* ==== UTILIDADES ==== */

#endif
