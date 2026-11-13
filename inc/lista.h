#ifndef LISTA_H
#define LISTA_H

#include <stdbool.h>

/* Lista de pendientes (habitaciones secretas no reveladas)
Lista de visitadas (IDs)
(IDs eliminados, para no reinsertarlos)*/
/* Lista enlazada simple de enteros. Se usa para:
 *   - Habitaciones visitadas por el personaje (IDs, en orden de visita).
 *   - Lista de vecinas declaradas de cada habitación secreta pendiente.
 */
 
typedef struct s_NodoLista {
    int dato;
    struct s_NodoLista *sig;
} s_NodoLista;

typedef struct s_Lista {
    s_NodoLista *cabeza;
    s_NodoLista *cola;
    int cantidad;
} s_Lista;

/* ==== CREAR / DESTRUIR ==== */
void lista_crear(s_Lista *l);
void lista_destruir(s_Lista *l);

/* ==== OPERACIONES ==== */
bool lista_enqueue_final(s_Lista *l, int dato);
bool lista_enqueue_inicio(s_Lista *l, int dato);
bool lista_buscar(const s_Lista *l, int dato);
bool lista_eliminar(s_Lista *l, int dato);

/* ==== UTILIDADES ==== */
bool lista_vacia(const s_Lista *l);
int lista_cantidad(const s_Lista *l);
void lista_imprimir(const s_Lista *l);

#endif