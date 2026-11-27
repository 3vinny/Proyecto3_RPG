#include "mazmorra.h"
#include "comunes.h"
#include "print.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void consultar_habitacion(s_GameState *gs)
{
    if(gs == NULL) return;

    printf("Ingresa el ID de la habitacion: ");
    int id = leer_entero();

    s_NodoAbb *nodo = abb_buscar(gs->abb, id);

    if(nodo == NULL)
    {
        printf("No existe una habitacion con ese ID\n");
        return;
    }

    print_habitacion(nodo->dato);
}

void mostrar_vecinas(s_GameState *gs)
{
    if (gs == NULL) return;

    s_NodoAbb *actual = abb_buscar(gs->abb, gs->id_actual);
    if(actual != NULL)
    {
        printf("Habitacion actual: %s (ID: %d)\n", actual->dato.nombre, actual->dato.id);
    }

    s_Vertice *v = grafo_buscar_vertice(&gs->grafo, gs->id_actual);
    if(v == NULL || v->adyacentes == NULL)
    {
        printf("No hay habitaciones vecinas\n");
        return;
    }

    s_Adyacente *ady;
    printf("Habitaciones vecinas:\n");
    for(ady = v->adyacentes; ady != NULL; ady = ady->siguiente)
    {
        s_NodoAbb *vecina = abb_buscar(gs->abb, ady->id_vecino);
        if(vecina != NULL)
        {
            printf(" . %s (ID %d)\n", vecina->dato.nombre, vecina->dato.id);
        }
    }
}

void moverse_habitacion(s_GameState *gs)
{
    if(gs == NULL) return;

    printf("Ingresa el ID de la habitacion a la que quieres ir: ");
    int id_destino = leer_entero();

    s_Vertice *v = grafo_buscar_vertice(&gs->grafo, gs->id_actual);
    if(v == NULL) return;

    bool es_vecina = false;
    s_Adyacente *ady;
    for(ady = v->adyacentes; ady != NULL; ady = ady->siguiente)
    {
        if(ady->id_vecino == id_destino)
        {
            es_vecina = true;
            break;
        }
    }

    if(!es_vecina)
    {
        printf("No puedes moverte hasta esa habitacion. (la habitacion %d no es vecina)\n", id_destino);
        return;
    }

    //actualizar la posiciona actual y registrar en visitadas
    gs->id_actual = id_destino;
    if(!lista_buscar(&gs->visitadas, id_destino))
    {
        lista_enqueue_final(&gs->visitadas, id_destino);
    }

    s_NodoAbb *destino = abb_buscar(gs->abb, id_destino);

    if(destino != NULL)
    {
       if (strcmp(destino->dato.enemigo, "-") != 0)
        {
            printf("hay un %s en tu camino\n", destino->dato.enemigo);
            printf("1. matarlo  2. correr\n> ");
            int accion = leer_entero_en_rango(1, 2);
            if (accion == 1)
            {
                printf("Matas a %s y avanzas\n", destino->dato.enemigo);
            }
            else
            {
                printf("Corres de %s y lo pierdes\n", destino->dato.enemigo);
            }
        } 
    }

}

bool cargar_mazmorra(s_GameState *gs, const char *nombre_archivo)
{
    if(gs == NULL || nombre_archivo == NULL) return false;

    FILE *f = fopen(nombre_archivo, "r");
    if(f == NULL)
    {
        printf("Error para abrir el archivo\n");
        return false;
    }

    char linea[512];
    while(fgets(linea,sizeof(linea), f) != NULL)
    {
        linea[strcspn(linea, "\r\n")] = '\0';
        if(linea[0] == '\0' || linea[0] == '#') continue;

        s_Habitacion H = {0};
        char oculta[10] = {0};
        char vecinas[128] = {0};

        int campos = sscanf(linea, "%d|%63[^|]|%255[^|]|%29[^|]|%99[^|]|%99[^|]|%9[^|]|%127[^\n]",
                    &H.id, H.nombre, H.descripcion, H.tipo,
                    H.tesoro, H.enemigo, oculta, vecinas);

        if(campos != 8) continue;
        
        if(strcmp(oculta, "N") == 0)
        {
            if(abb_insertar(&gs->abb,H))
            {
                grafo_agregar_vertice(&gs->grafo, H.id);

                if(strcmp(H.tipo, "INICIO") == 0)
                {
                    gs->id_actual = H.id;
                    lista_enqueue_final(&gs->visitadas, H.id);
                }
            }
        }
    }
    rewind(f);

    while(fgets(linea, sizeof(linea), f) != NULL)
    {
        linea[strcspn(linea, "\r\n")] = '\0';
        if(linea[0] == '\0' || linea[0] == '#') continue;

        s_Habitacion H = {0};
        char oculta[10] = {0};
        char vecinas[128] = {0};

        int campos = sscanf(linea, "%d|%63[^|]|%255[^|]|%29[^|]|%99[^|]|%99[^|]|%9[^|]|%127[^\n]",
                    &H.id, H.nombre, H.descripcion, H.tipo,
                    H.tesoro, H.enemigo, oculta, vecinas);

        if(campos != 8 || strcmp(oculta, "N") != 0 || strcmp(vecinas, "-") == 0)
        {
            continue;
        }

        char *token = strtok(vecinas, ",");
        while (token != NULL)
        {
            int id_vec = atoi(token);

            grafo_agregar_arista(&gs->grafo, H.id, id_vec);
            token = strtok(NULL, ",");
        }
    }

    fclose(f);
    return true;
}