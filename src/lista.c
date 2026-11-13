#include "lista.h"
#include <stdio.h>
#include <stdlib.h>

/* ==== CREAR / DESTRUIR ==== */
void lista_crear(s_Lista *l)
{
    if (l == NULL) return;
    l->cabeza = NULL;
    l->cola = NULL;
    l->cantidad = 0;
}

void lista_destruir(s_Lista *l)
{
    if (l == NULL) return;
    s_NodoLista *act = l->cabeza;
    while (act != NULL)
    {
        s_NodoLista *sig = act->sig;   // guardar antes de liberar
        free(act);
        act = sig;
    }
    l->cabeza = l->cola = NULL;
    l->cantidad = 0;
}

/* ==== OPERACIONES ==== */

bool lista_enqueue_final(s_Lista *l, int dato)
{
    if (l == NULL) return false;

    s_NodoLista *nuevo = malloc(sizeof(s_NodoLista));
    if (nuevo == NULL) return false;
    nuevo->dato = dato;
    nuevo->sig = NULL;

    if (l->cola == NULL)
    { 
        // lista vacía
        l->cabeza = l->cola = nuevo;
    }
    else
    {
        l->cola->sig = nuevo;            // engancha al final
        l->cola = nuevo;            // mueve la cola
    }
    l->cantidad++;
    return true;
}

bool lista_enqueue_inicio(s_Lista *l, int dato)
{
    if (l == NULL) return false;

    s_NodoLista *nuevo = malloc(sizeof(s_NodoLista));
    if (nuevo == NULL) return false;
    nuevo->dato = dato;
    nuevo->sig = l->cabeza;
    l->cabeza = nuevo;

    // lista vacia
    if (l->cola == NULL) l->cola = nuevo;
    l->cantidad++;
    return true;
}

bool lista_buscar(const s_Lista *l, int dato)
{
    if (l == NULL) return false;
    s_NodoLista *act = l->cabeza;
    while (act != NULL && act->dato != dato)
    {
        act = act->sig;
    }
    return (act != NULL);
}

bool lista_eliminar(s_Lista *l, int dato)
{
    if (l == NULL) return false;

    s_NodoLista *ant = NULL;
    s_NodoLista *act = l->cabeza;
    
    while (act != NULL && act->dato != dato)
    {
        ant = act;
        act = act->sig;
    }
    if (act == NULL) return false;
    
    if (ant == NULL)
        l->cabeza = act->sig;
    else
        ant->sig = act->sig;

    if (act == l->cola) l->cola = ant;

    free(act);
    l->cantidad--;
    return true;
}

/* ==== UTILIDADES ==== */
bool lista_vacia(const s_Lista *l)
{
    return (l == NULL || l->cabeza == NULL);
}

int lista_cantidad(const s_Lista *l)
{
    return (l == NULL) ? 0 : l->cantidad;
}

void lista_imprimir(const s_Lista *l)
{
    if (l == NULL || l->cabeza == NULL) 
    {
        printf("lista vacia o nula\n");
        return;
    }

    s_NodoLista *act = l->cabeza;
    while (act)
    {
        printf("%d", act->dato);
        if (act->sig) printf(", ");
        act = act->sig;
    }
    printf("\n");
}