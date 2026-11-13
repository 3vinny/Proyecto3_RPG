#include "juego.h"
#include "print.h"
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
        print_menu(inicio.nombre, inicio.id);
        int opcion = seleccionar_opcion();
        switch (opcion)
        {
        case 1:
            print_habitacion(inicio);
            break;
        case 2:
            system("clear");
            printf("habitacioens vecinas :v\n");
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