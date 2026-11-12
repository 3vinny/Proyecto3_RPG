#ifndef HABITACION_H
#define HABITACION_H

typedef struct {
    int id;
    char nombre[100];
    char descripcion[256];
    char tipo[30];
    char tesoro[100];
    char enemigo[100];
} s_Habitacion;

#endif