#include "print.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void print_menu(const char *nombre_actual, int id_actual)
{
    printf("\t==== RPG: El Escapista de Mazmorras ====\n");
    printf("\t1. Consultar habitacion\n");
    printf("\t2. Mostrar habitaciones vecinas\n");
    printf("\t3. Moverse a una habitacion vacia\n");
    printf("\t4. Buscar ruta hacia otra habitacion\n");
    printf("\t5. Explorar habitaciones alcanzables\n");
    printf("\t6. Mostrar todas las habitaciones\n");
    printf("\t7. Mostrar habitaciones a N pasillos\n");
    printf("\t8. Buscar pasadizos secretos\n");
    printf("\t9. Quemar una habitacion\n");
    printf("\t10. Mostrar habitaciones visitadas\n");
    printf("\t11. Salir :(\n");
    printf("\n");
    printf("\t[HABITACION ACTUAL: %s (ID %d) ]\n", nombre_actual, id_actual);
    printf("\n");
}

void print_habitacion(s_Habitacion H)
{
    system("clear");
    sleep(1);
    printf("===%s (ID %d)===\n", H.nombre, H.id);
    printf("Descripcion: %s\n", H.descripcion);
    printf("Tipo: %s\n", H.tipo);
    printf("Tesoro: %s\n", H.tesoro);
    printf("Enemigo: %s\n", H.enemigo);
    sleep(2);
}