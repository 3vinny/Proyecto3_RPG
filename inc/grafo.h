#ifndef GRAFO_H
#define GRAFO_H

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
void grafo_crear(s_Grafo *grafo); // inicia campos a 0/NULL
void grafo_destruir(s_Grafo *grafo); // libera vertices,vecinos y estructura

/* ==== VERTICES ==== */
bool grafo_agregar_vertice(s_Grafo *grafo, int id);
bool grafo_eliminar_vertice(s_Grafo *grafo, int id);
bool grafo_existe_vertice(s_Grafo *grafo, int id);
s_Vertice *grafo_buscar_vertice(s_Grafo *grafo, int id); // NULL si no existe

/* ==== ARISTAS ==== */
bool grafo_agregar_arista(s_Grafo *grafo, int id_a, int id_b);
bool grafo_eliminar_arista(s_Grafo *grafo, int id_a, int id_b);
int grafo_grado(s_Grafo *grafo, int id);

/* ==== BUSQUEDA ==== */
// BFS: ruta + corta entre origen-destino. retorna true si hay ruta, false si no
bool grafo_bfs_ruta(s_Grafo *grafo, int origen, int dest, int *ruta, int max_ruta, int *longitud);

// DFS: todas alcanzables desde el origen incluyendo el origen
// arreglo dinamico (hacer free) | NULL si error | cantidad: numero ids en arreglo.
int *grafo_dfs_alc(s_Grafo *grafo, int origen, int k, int *cantidad);

// BFS POR NIVELES: a k pasos del origen.
// arreglo dinamico (hacer free) | NULL si error | k=0 es origen
int *grafo_bfs_nivel(s_Grafo *grafo, int origen, int k, int *cantidad);

/* ==== UTILIDADES ==== */
bool grafo_isempty(s_Grafo *grafo);
int grafo_num_vertices(s_Grafo *grafo);
int grafo_num_aristas(s_Grafo *grafo);
void grafo_imprimir(s_Grafo *grafo);

#endif
