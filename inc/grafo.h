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
bool grafo_agregar_vertice(s_Grafo *grafo, int id);
bool grafo_eliminar_vertice(s_Grafo *grafo, int id);
bool grafo_existe_vertice(s_Grafo *grafo, int id);
s_Vertice *grafo_buscar_vertice(s_Grafo *grafo, int id); // NULL si no existe

/* ==== ARISTAS ==== */
bool agregar_adyacente(s_Vertice *v, int id_vecino);
bool quitar_adyacente(s_Vertice *v, int id_vecino);
bool grafo_agregar_arista(s_Grafo *grafo, int id_a, int id_b);
bool grafo_eliminar_arista(s_Grafo *grafo, int id_a, int id_b);
int grafo_grado(s_Grafo *grafo, int id);

/* ==== BUSQUEDA ==== */
bool grafo_bfs_ruta(s_Grafo *grafo, int origen, int dest, int *ruta, int max_ruta, int *longitud);
int *grafo_dfs_alc(s_Grafo *grafo, int origen, int k, int *cantidad);
int *grafo_bfs_nivel(s_Grafo *grafo, int origen, int k, int *cantidad);

/* ==== UTILIDADES ==== */
bool grafo_isempty(s_Grafo *grafo);
int grafo_num_vertices(s_Grafo *grafo);
int grafo_num_aristas(s_Grafo *grafo);
void grafo_imprimir(s_Grafo *grafo);

#endif