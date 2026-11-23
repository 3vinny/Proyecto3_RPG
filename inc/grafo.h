/**
 * @file grafo.h
 * @brief Definición de estructuras y operaciones sobre el grafo de la mazmorra.
 * @author Ariel Barria (ariebarr@umagallanes.cl)
 * @date 2026-11-19
 */
#ifndef GRAFO_H
#define GRAFO_H

#include "habitacion.h"
#include <stdbool.h>

/**
 * @brief Estructura con el correspondiente vecino/adyacente/siguiente.
 */
typedef struct s_Adyacente
{
    int id_vecino;
    struct s_Adyacente *siguiente;
} s_Adyacente;

/**
 * @brief Representa uno de los vertices del grafo.
 */
typedef struct s_Vertice
{
    int id;
    s_Adyacente *adyacentes;
    struct s_Vertice *siguiente;
} s_Vertice;

/**
 * @brief Representa la estructura general del grafo.
 */
typedef struct s_Grafo
{
    /* data */
    s_Vertice *vertices;
    int num_vertices;
    int num_aristas;
} s_Grafo;

/* ======== FUNCIONES: INICIAR/DESTRUIR ======== */
/**
 * @brief Inicializa un grafo vacio.
 * 
 * @param grafo Puntero a la estructura del grafo.
 */
void grafo_crear(s_Grafo *grafo);

/**
 * @brief Inicializa un grafo vacio.
 * 
 * @param grafo Puntero a la estructura del grafo.
 */
void grafo_destruir(s_Grafo *grafo);

/* ======== VERTICES GRAFO ======== */
/**
 * @brief Agrega un vertice al grafo
 * 
 * @param grafo Puntero a la estructura del grafo.
 * @param id
 *
 * @return true
 * @return false
 */
bool grafo_agregar_vertice(s_Grafo *grafo, int id);

/**
 * @brief Elimina un vertice del grafo
 * 
 * @param grafo Puntero a la estructura del grafo.
 * @param id
 *
 * @return true
 * @return false
 */
bool grafo_eliminar_vertice(s_Grafo *grafo, int id);

/**
 * @brief Comprueba si existe tal vertice dentro del grafo.
 * 
 * @param grafo Puntero a la estructura del grafo.
 * @param id
 *
 * @return true
 * @return false
 */
bool grafo_existe_vertice(s_Grafo *grafo, int id);

/**
 * @brief Busca un vertice especifico en el grafo
 * 
 * @param grafo Puntero a la estructura del grafo.
 * @param id
 *
 * @return El vertice encontrado.
 * @return NULL si no existe.
 */
s_Vertice *grafo_buscar_vertice(s_Grafo *grafo, int id);

/* ======== ADYACENTES & ARISTAS ======== */
/**
 * @brief Agrega una adyacente.
 * 
 * @param v Puntero a la estructura del vertice.
 * @param id ID del vecino
 *
 * @return true
 * @return false
 */
bool agregar_adyacente(s_Vertice *v, int id_vecino);

/**
 * @brief Quita una adyacente.
 * 
 * @param v Puntero a la estructura del vertice.
 * @param id ID del vecino
 *
 * @return true
 * @return false
 */
bool quitar_adyacente(s_Vertice *v, int id_vecino);

/**
 * @brief Agrega una arista.
 * 
 * @param grafo Puntero a la estructura del grafo.
 * @param id_a ID del vecino A
 * @param id_b ID del vecino B
 *
 * @return true
 * @return false
 */
bool grafo_agregar_arista(s_Grafo *grafo, int id_a, int id_b);

/**
 * @brief Elimina una arista.
 * 
 * @param grafo Puntero a la estructura del grafo.
 * @param id_a ID del vecino A
 * @param id_b ID del vecino B
 *
 * @return true
 * @return false
 */
bool grafo_eliminar_arista(s_Grafo *grafo, int id_a, int id_b);

/**
 * @brief Indica el grado o número de aristas incidentes al vértice
 * 
 * @param grafo Puntero a la estructura del grafo.
 * @param id
 *
 * @return true
 * @return false
 */
int grafo_grado(s_Grafo *grafo, int id);

/* ======== BUSQUEDA ======== */

bool grafo_bfs_ruta(s_Grafo *grafo, int origen, int dest, int *ruta, int max_ruta, int *longitud);
int *grafo_dfs_alc(s_Grafo *grafo, int origen, int *cantidad);

/*
 * exactamente en nivel k, sin incluir el origen
 */
int *grafo_bfs_nivel(s_Grafo *grafo, int origen, int k, int *cantidad);

/* ======== UTILIDADES ======== */
bool grafo_isempty(s_Grafo *grafo);
int grafo_num_vertices(s_Grafo *grafo);
int grafo_num_aristas(s_Grafo *grafo);
void grafo_imprimir(s_Grafo *grafo);

#endif