#include "juego.h"

void juego_inicializar(s_GameState *gs)
{
    if (gs == NULL) return;
    gs->ejecutando = false;
    gs->id_actual  = -1;
    grafo_crear(&gs->grafo);
    abb_crear(&gs->arbol);
    lista_crear(&gs->visitadas);
    pendientes_crear(&gs->pendientes);
}

void juego_destruir(s_GameState *gs)
{
    if (gs == NULL) return;
    grafo_destruir(&gs->grafo);
    abb_destruir(&gs->arbol);
    lista_destruir(&gs->visitadas);
    pendientes_destruir(&gs->pendientes);
    gs->ejecutando = false;
}

int seleccionar_opcion(void)
{
    int opcion = 0;
    printf("Elige una opcion: ");
    scanf("%d", &opcion);
    return opcion;
}