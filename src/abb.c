#include "abb.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>


/* ==== INSERCION/BUSQUEDA/ELIMINACION ==== */
bool abb_insertar(s_Abb *abb, s_Habitacion H)
{
    if(abb == NULL)
    {
        return false;
    }

    //Arbol vacio
    if(*abb == NULL)
    {
        *abb = malloc(sizeof(s_NodoAbb));
        if(*abb == NULL)
        {
            printf("Sin espacio en memoria\n");
            return false;
        }
        (*abb)->dato = H;
        (*abb)->izq = NULL;
        (*abb)->der = NULL;
        return true;
    }

    if(H.id < (*abb)->dato.id)
    {
        return abb_insertar(&(*abb)->izq, H);
    }
    else if (H.id > (*abb)->dato.id)
    {
        return abb_insertar(&(*abb)->der, H);
    }
    return false;
}
/* ==== RECORRIDOS ==== */
void abb_preorder(s_Abb abb)
{
    if(abb == NULL)
    {
        return;
    }

    printf("ID: %d | %s (%s)\n",abb->dato.id, abb->dato.nombre, abb->dato.tipo);
    abb_preorder(abb->izq);
    abb_preorder(abb->der);
}

void abb_inorder(s_Abb abb)
{
    if(abb == NULL)
    {
        return;
    }
    printf("Imprimiendo habitaciones (IN ORDER)...\n");
    sleep(1);
    abb_inorder(abb->izq);
    printf("ID: %d | %s (%s)\n",abb->dato.id, abb->dato.nombre, abb->dato.tipo);
    abb_inorder(abb->der);
}

void abb_postorder(s_Abb abb)
{
    if(abb == NULL)
    {
        return;
    }

    abb_postorder(abb->izq);
    abb_postorder(abb->der);
    printf("ID: %d | %s (%s)\n",abb->dato.id, abb->dato.nombre, abb->dato.tipo);
}