# Proyecto3_RPG
Proyecto N°3 de la asignatura Estructura de Datos, correspondiente a un juego RPG: Explorador de Mazmorras, utilizando Grafos, ABB y AVL.
(Se puede usar proyecto anterior como base).

# Integrantes
- Ariel Barría
- Tomás Minte
- Lukas Bustamante

# Estructura del proyecto
## Carpetas
- src/
- inc/

# Convenciones de código
Para mantener un código uniforme entre todos los integrantes del grupo se utilizarán las siguientes convenciones:

## Funciones
Las funciones utilizarán snake_case con palabras ----.

Ejemplo:

## Variables
Las variables utilizarán ------.

Ejemplo:

## Constantes y #define
Las constantes y definiciones realizadas mediante #define se escribirán completamente en MAYÚSCULAS.

Ejemplo:
```c
#define MAX_OBJETOS 100 
#define VIDA_MAXIMA 100 
#define MAX_ENEMIGOS 20 
#define RUNNING 1
```

# Organización del proyecto
### Ariel Barría
Grafo
- [ ] Crear el repositorio con la estructura `src/`, `inc/`
- [ ] Definir `grafo.h
- [ ] Crear `lista_int` y `cola_int`
- [ ] Implementar el grafo: agregar y quitar vértices y aristas (sin duplicar pasillos)
- [ ] Quitar vértice debe devolver los pasillos destruidos
- [ ] BFS: ruta más corta, o informar que el destino no es alcanzable
- [ ] DFS: habitaciones alcanzables
- [ ] k pasillos: habitaciones a distancia exactamente k
- [ ] Menú 2 (vecinas), 4 (ruta con confirmación S/N), 5 (alcanzables) y 7 (k pasillos)
- [ ] Probar casos límite y pasar valgrind
- [ ] Sección del informe (grafo y búsquedas), aporte y declaración de IA

### Tomás Minte
ABB/AVL
- [ ] Crear `habitacion.h/.c` (id, nombre, descripción, tipo, tesoro, enemigo)
- [ ] Definir `abb.h`
- [ ] Implementar ABB/AVL: insertar, buscar, eliminar (3 casos) y recorridos inorden, preorden y postorden
- [ ] Lista de pendientes (secretas) y lista de IDs quemados
- [ ] Buscar pasadizos: revelar secretas en ABB y grafo, con pasillos solo a vecinas existentes
- [ ] Quemar: validar reglas, eliminar de ABB y grafo, informar pasillos destruidos
- [ ] Menú 1 (consultar), 6 (mostrar todas, inorden), 8 (pasadizos) y 9 (quemar)
- [ ] Probar casos límite y pasar valgrind
- [ ] Sección del informe (ABB, secretas, quemar), aporte y declaración de IA

### Lukas Bustamante
- [ ] Crear `print.c`
- [ ] Cargador del archivo: dos pasadas, secretas a pendientes y errores con número de línea
- [ ] Crear `jugador` (habitación actual y visitadas) y `mazmorra.c` que agrupe todas las estructuras
- [ ] `main.c` con el menú de 11 opciones
- [ ] Encuentro con enemigo (Combatir o Escapar)
- [ ] Menú 3 (moverse), 10 (visitadas) y 11 (salir sin fugas)
- [ ] Crear `mazmorra.txt` de ejemplo y otro con errores