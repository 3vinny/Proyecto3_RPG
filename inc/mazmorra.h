#ifndef MAZMORRA_H
#define MAZMORRA_H
#include "juego.h"

void consultar_habitacion(s_GameState *gs);
void mostrar_vecinas(s_GameState *gs);
void moverse_habitacion(s_GameState *gs);
bool cargar_mazmorra(s_GameState *gs, const char *nombre_archivo);
#endif