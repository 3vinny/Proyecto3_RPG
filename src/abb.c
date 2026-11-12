#include "abb.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

/* ==== INICIAR/DESTRUIR ==== */
void abb_crear(s_Abb *abb)
{
    if (abb) *abb = NULL;
}

void abb_destruir(s_Abb *abb)
{
    if (abb == NULL || *abb == NULL) return;
    abb_destruir(&(*abb)->izq);
    abb_destruir(&(*abb)->der);
    free(*abb);
    *abb = NULL;
}

/* ==== INSERCION/BUSQUEDA/ELIMINACION ==== */
bool abb_insertar(s_Abb *abb, s_Habitacion H)
{
    if (abb == NULL)
    {
        return false;
    }

    //Arbol vacio
    if (*abb == NULL)
    {
        *abb = malloc(sizeof(s_NodoAbb));
        if (*abb == NULL)
        {
            printf("Sin espacio en memoria\n");
            return false;
        }
        (*abb)->dato = H;
        (*abb)->izq = NULL;
        (*abb)->der = NULL;
        return true;
    }

    if (H.id < (*abb)->dato.id)
    {
        return abb_insertar(&(*abb)->izq, H);
    }
    else if (H.id > (*abb)->dato.id)
    {
        return abb_insertar(&(*abb)->der, H);
    }
    return false;
}

s_NodoAbb* abb_buscar(s_Abb abb, int id)
{
    while (abb != NULL && abb->dato.id != id)
    {
        if (id < abb->dato.id)
        {
            abb = abb->izq;
        }
        else
        {
            abb = abb->der;
        }
    }
    return abb;
}

bool abb_eliminar(s_Abb *abb, int id)
{
    /* Tres casos */
    if (abb == NULL || *abb == NULL) return false;  

    if (id < (*abb)->dato.id) return abb_eliminar(&(*abb)->izq, id);
    if (id > (*abb)->dato.id) return abb_eliminar(&(*abb)->der, id);

    // Encontrado, se hace nodo temporal
    s_NodoAbb *temp = *abb;
    if ((*abb)->izq == NULL)
    {
        *abb = (*abb)->der;
        free(temp);
    }
    else if ((*abb)->der == NULL)
    {
        *abb = (*abb)->izq;
        free(temp);
    }
    else
    {
        // 2 hijos: buscar sucesor minimo subarbol derecho
        s_NodoAbb *(*sucesor) = &(*abb)->der;
        while ((*sucesor)->izq != NULL)
        {
            sucesor = &(*sucesor)->izq;
        }
        (*abb)->dato = (*sucesor)->dato;
        s_NodoAbb *aux = *sucesor;
        *sucesor = (*sucesor)->der;
        free(aux);
    }
    return true;
}

/* ==== RECORRIDOS ==== */
void abb_preorder(s_Abb abb)
{
    if (abb == NULL) return;

    printf("ID: %d | %s (%s)\n",abb->dato.id, abb->dato.nombre, abb->dato.tipo);
    abb_preorder(abb->izq);
    abb_preorder(abb->der);
}

void abb_inorder(s_Abb abb)
{
    if (abb == NULL) return;

    abb_inorder(abb->izq);
    printf("ID: %d | %s (%s)\n",abb->dato.id, abb->dato.nombre, abb->dato.tipo);
    abb_inorder(abb->der);
}

void abb_postorder(s_Abb abb)
{
    if (abb == NULL) return;

    abb_postorder(abb->izq);
    abb_postorder(abb->der);
    printf("ID: %d | %s (%s)\n",abb->dato.id, abb->dato.nombre, abb->dato.tipo);
}

/* ==== UTILIDADES ==== */
bool abb_isempty(s_Abb abb)
{
    return (abb == NULL);
}

int abb_altura(s_Abb abb)
{
    if (abb == NULL) return 0;
    // version simplificada para evitar la repeticion exponencial
    int altura_izq = abb_altura(abb->izq);
    int altura_der = abb_altura(abb->der);
    return (altura_izq > altura_der ? altura_izq : altura_der) + 1;
}

int abb_contar_nodos(s_Abb abb)
{
    if (abb == NULL)
        return 0;
    return 1 + abb_contar_nodos(abb->izq) + abb_contar_nodos(abb->der);
}