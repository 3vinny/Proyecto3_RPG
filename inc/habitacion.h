#ifndef HABITACION_H
#define HABITACION_H
#include <stdlib.h>

typedef struct {
    int id;
    char nombre[64];
    char descripcion[256];
    char tipo[30];
    char tesoro[100];
    char enemigo[100];
} s_Habitacion;

/* ==== UTILIDADES ==== */
// const: solo lectura
void habitacion_imprimir(const s_Habitacion *h);
// Compara tipo contra los strings validos 
// (INICIO, NORMAL, TESORO, JEFE, COMBATE, VACIA, SECRETA)
int habitacion_comparar(const char *tipo);

#endif