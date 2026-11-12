#ifndef ABB_H
#define ABB_H

#include "habitacion.h"
#include <stdbool.h>

typedef struct s_NodoAbb {
    s_Habitacion dato;
    struct s_NodoAbb *izq;
    struct s_NodoAbb *der;
} s_NodoAbb;

typedef struct s_Abb
{
    s_NodoAbb *raiz;
} s_Abb;

/* ==== INICIAR/DESTRUIR ==== */
void abb_crear(s_Abb *abb);
void abb_destruir(s_Abb *abb);  // Libera memoria en postorder

/* ==== INSERCION/BUSQUEDA/ELIMINACION ==== */
bool abb_insertar(s_Abb *abb, s_Habitacion H);
s_NodoAbb* abb_buscar(const s_Abb *abb, int id);  // nodo o NULL
bool abb_eliminar(s_Abb *abb, int id);  // casos: hoja, 1 hijo, 2 hijos (false si no existe)

/* ==== RECORRIDOS ==== */
void abb_preorder(const s_Abb *abb);
void abb_inorder(const s_Abb *abb);
void abb_postorder(const s_Abb *abb);

/* ==== UTILIDADES ==== */
bool abb_isempty(const s_Abb *abb);
int abb_altura(const s_Abb *abb);
int abb_contar_nodos(const s_Abb *abb);

#endif
