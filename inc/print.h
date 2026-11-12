#ifndef PRINT_h
#define PRINT_h 

#include "habitacion.h"

#define COLOR_RESET    "\033[0m"
#define COLOR_ROJO     "\033[1;31m"
#define COLOR_VERDE    "\033[1;32m"
#define COLOR_AMARILLO "\033[1;33m"
#define COLOR_AZUL     "\033[1;34m"
#define COLOR_MAGENTA  "\033[1;35m"
#define COLOR_CIAN     "\033[1;36m"
#define COLOR_BLANCO   "\033[1;37m"

void print_menu(const char *nombre_actual, int id_actual);
void print_habitacion(s_Habitacion H);

#endif