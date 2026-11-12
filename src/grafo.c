#include <stdbool.h>
#include "grafo.h"

/* ==== FUNCIONES: INICIAR/DESTRUIR ==== */
void grafo_crear(s_Grafo *grafo);
void grafo_destruir(s_Grafo *grafo);

/* ==== VERTICES ==== */
bool grafo_agregar_vertice(s_Grafo *grafo, int id);
bool grafo_eliminar_vertice(s_Grafo *grafo, int id)
{
    // 1. Encontrar y desligar el vértice de la lista de vértices
    // 2. Contar cuántas aristas se destruyen (para actualizar num_aristas)
    // 3. Recorrer cada vértice restante y eliminar aristas hacia 'id'
    // 4. Liberar la lista de adyacencia del vértice eliminado y el nodo
}

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