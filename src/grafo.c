#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"

/* ==== FUNCIONES: INICIAR/DESTRUIR ==== */
void grafo_crear(s_Grafo *grafo)
{
    if (grafo == NULL) return;

    grafo->vertices = NULL;
    grafo->num_vertices = 0;
    grafo->num_aristas = 0;
}
void grafo_destruir(s_Grafo *grafo)
{
    if(grafo == NULL)
    {
        error("Grafo inexistente");
        return;
    }

    s_Vertice *v = grafo->vertices;

    while(v != NULL) // Recorre todos los vertices hasta que sea NULL
    {
        s_Adyacente *adyacente = v->adyacentes;

        while(adyacente != NULL) // Recorre los vertices adyacentes hasta que sea NULL
        {
            s_Adyacente *sig_adyacente = adyacente->siguiente;
            free(adyacente);
            adyacente = sig_adyacente; 
        }

        s_Vertice *sig_v = v->siguiente;
        free(v);
        v = sig_v;
    }

    grafo->vertices = NULL;
    grafo->num_vertices = 0;
    grafo->num_aristas = 0;
}

/* ==== VERTICES ==== */
bool grafo_agregar_vertice(s_Grafo *grafo, int id)
{
    if(grafo == NULL)
    {
        error("Grafo inexistente");
        return false;
    }

    s_Vertice *v = grafo->vertices;
    s_Vertice *ultimo_v = NULL; 

    while(v != NULL) // Comprueba si el id ya existe
    {
        if(v->id == id) 
        {
            error("El vertice ya existe");
            return false;
        }
        ultimo_v = v;
        v = v->siguiente;
    }

    s_Vertice *nuevo_v= malloc(sizeof(struct s_Vertice));

    if(nuevo_v == NULL)
    {
        error("Memoria insuficiente");
        return false;
    }

    nuevo_v->adyacentes = NULL;
    nuevo_v->id = id;
    nuevo_v->siguiente = NULL;

    if(ultimo_v == NULL)
        grafo->vertices = nuevo_v;
    else
        ultimo_v->siguiente = nuevo_v;

    grafo->num_vertices++;

    return true;
}

bool grafo_eliminar_vertice(s_Grafo *grafo, int id)
{
    // 1. Encontrar y desligar el vértice de la lista de vértices
    // 2. Contar cuántas aristas se destruyen (para actualizar num_aristas)
    // 3. Recorrer cada vértice restante y eliminar aristas hacia 'id'
    // 4. Liberar la lista de adyacencia del vértice eliminado y el nodo
}

bool grafo_existe_vertice(s_Grafo *grafo, int id)
{
    if(grafo_buscar_vertice(grafo, id) != NULL) return true;
    else return false;
}

s_Vertice *grafo_buscar_vertice(s_Grafo *grafo, int id) // NULL si no existe
{
    if(grafo == NULL)
    {
        error("Grafo inexistente");
        return NULL;
    }

    s_Vertice *v = grafo->vertices;

    while(v != NULL)
    {
        if(v->id == id) return v;
        v = v->siguiente;
    }

    return NULL;
}

/* ==== ARISTAS ==== */
bool agregar_adyacente(s_Vertice *v, int id_vecino)
{
    s_Adyacente *nuevo_a = malloc(sizeof(s_Adyacente));

    if(nuevo_a == NULL)
    {
        error("Memoria insuficiente");
        return false;
    }

    nuevo_a->id_vecino = id_vecino;
    nuevo_a->siguiente = v->adyacentes; 
    v->adyacentes = nuevo_a;

    return true;
}

bool quitar_adyacente(s_Vertice *v, int id_vecino)
{
    s_Adyacente *adyacente = v->adyacentes;
    s_Adyacente *anterior_a = NULL;

    while(adyacente != NULL)
    {
        if(adyacente->id_vecino == id_vecino)
        {
            if(anterior_a == NULL)
                v->adyacentes = adyacente->siguiente;
            else
                anterior_a->siguiente = adyacente->siguiente;

            free(adyacente);
            return true;
        }
        anterior_a = adyacente;
        adyacente = adyacente->siguiente;
    }

    return false;
}

bool grafo_agregar_arista(s_Grafo *grafo, int id_a, int id_b)
{
    if(grafo == NULL)
    {
        error("Grafo inexistente");
        return false;
    }

    if(id_a == id_b)
    {
        error("No se permiten los mismos vertices");
        return false;
    }

    s_Vertice *a = grafo_buscar_vertice(grafo, id_a);
    s_Vertice *b = grafo_buscar_vertice(grafo, id_b);

    if(a == NULL || b == NULL)
    {
        error("Vertice inexistente");
        return false;
    }

    s_Adyacente *adyacente = a->adyacentes;

    while(adyacente != NULL) // Comprueba si la arista ya existe
    {
        if(adyacente->id_vecino == id_b)
        {
            error("La arista ya existe");
            return false;
        }
        adyacente = adyacente->siguiente;
    }

    if(agregar_adyacente(a, id_b) == false) return false;

    if(agregar_adyacente(b, id_a) == false)
    {
        quitar_adyacente(a, id_b); 
        return false;
    }

    grafo->num_aristas++;

    return true;
}

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
bool grafo_isempty(s_Grafo *grafo)
{
    if(grafo == NULL)
    {
        error("Grafo inexistente");
        return true;
    }

    return (grafo->num_vertices == 0) ? true : false;
}

int grafo_num_vertices(s_Grafo *grafo)
{
    if (grafo == NULL)
    {
        error("Grafo inexistente");
        return 0;
    }

    return grafo->num_vertices;
}

int grafo_num_aristas(s_Grafo *grafo)
{
    if (grafo == NULL)
    {
        error("Grafo inexistente");
        return 0;
    }

    return grafo->num_aristas;
}

void grafo_imprimir(s_Grafo *grafo)
{
    if(grafo == NULL)
    {
        error("Grafo inexistente");
        return;
    }

    if(grafo->vertices == NULL)
    {
        printf("Grafo vacio\n");
        return;
    }

    s_Vertice *v = grafo->vertices;

    while(v != NULL) // Recorre todos los vertices
    {
        printf("\nVertice %d:", v->id);

        s_Adyacente *adyacente = v->adyacentes;

        while(adyacente != NULL) // Recorre los vecinos del vertice
        {
            printf(" [%d] -", adyacente->id_vecino);
            adyacente = adyacente->siguiente;
        }

        printf("\n");
        v = v->siguiente;
    }
}