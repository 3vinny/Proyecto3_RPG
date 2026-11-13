#ifndef PENDIENTES_H
#define PENDIENTES_H

#include "habitacion.h"
#include "lista.h"
#include <stdbool.h>

typedef struct s_Pendiente {
    s_Habitacion hab;
    s_Lista vecinas; // IDs declarados en el archivo
    struct s_Pendiente *sig;
} s_Pendiente;

typedef struct s_Pendientes {
    s_Pendiente *cabeza;
    int cantidad;
} s_Pendientes;

/* ==== FUNCIONES: INICIAR/DESTRUIR ==== */
void pendientes_crear(s_Pendientes *p);
void pendientes_destruir(s_Pendientes *p);

/* ==== OPERACIONES ==== */
bool pendientes_agregar(s_Pendientes *p, s_Habitacion H, const s_Lista *vecinas);
bool pendientes_vacia(const s_Pendientes *p);
int pendientes_cantidad(const s_Pendientes *p);
int pendientes_revelar(s_Pendientes *p, int id_actual, s_Abb *abb, s_Grafo *grafo);

#endif