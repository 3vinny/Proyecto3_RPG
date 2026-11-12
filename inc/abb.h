#ifndef ABB_H
#define ABB_H

#include "habitacion.h"
#include <stdbool.h>

typedef struct s_NodoAbb {
    s_Habitacion dato;
    struct s_NodoAbb *izq;
    struct s_NodoAbb *der;
} s_NodoAbb;

typedef s_NodoAbb* s_Abb;

/* ==== INICIAR/DESTRUIR ==== */
void abb_crear(s_Abb *abb);
void abb_destruir(s_Abb *abb);  // Libera memoria en postorder

/* ==== INSERCION/BUSQUEDA/ELIMINACION ==== */
bool abb_insertar(s_Abb *abb, s_Habitacion H); // abb_insertar retorna false cuando el ID ya existe
s_NodoAbb* abb_buscar(s_Abb abb, int id);  // nodo o NULL
bool abb_eliminar(s_Abb *abb, int id);  // casos: hoja, 1 hijo, 2 hijos (false si no existe)

/* ==== RECORRIDOS ==== */
void abb_preorder(s_Abb abb);
void abb_inorder(s_Abb abb);
void abb_postorder(s_Abb abb);

/* ==== UTILIDADES ==== */
bool abb_isempty(s_Abb abb);
int abb_altura(s_Abb abb);
int abb_contar_nodos(s_Abb abb);

#endif
