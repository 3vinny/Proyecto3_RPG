#include "juego.h"
#include "print.h"
#include "mazmorra.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


int main(void)
{
    s_GameState gs;
    juego_inicializar(&gs);
    gs.ejecutando = true;

    gs.abb = NULL;

   //habitacion de prueba para probar el main :V
   s_Habitacion inicio = {1,"celda","celda con la puerta rota","INICIO","-","-"};

   abb_insertar(&gs.abb, inicio);
   gs.id_actual = 1;

    while(gs.ejecutando)
    {
        s_NodoAbb *hab_actual = abb_buscar(gs.abb, gs.id_actual);
        print_menu(hab_actual ? hab_actual->dato.nombre : "Desconocida", gs.id_actual);
        int opcion = seleccionar_opcion();
        switch (opcion)
        {
        case 1:
            consultar_habitacion(&gs);
            break;
        case 2:
            system("clear");
            mostrar_vecinas(&gs);
            sleep(1);
            break;
        case 3:
            moverse_habitacion(&gs);
            sleep(1);
            break;
        case 6:
            system("clear");
            abb_inorder(gs.abb);
            sleep(1);
            break;
        case 11:
            gs.ejecutando = false;
            printf("chau\n");
            break;
        //faltan los demas casos jeje
        default:
            printf("Ingrese una opcion valida !!\n");
            break;
        }
    }

    return 0;
}