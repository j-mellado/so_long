// inc/so_long.h

#ifndef SO_LONG_H
# define SO_LONG_H

// Incluir librerías estándar
# include <fcntl.h>   // Para open()
# include <unistd.h>  // Para read(), close(), write()
# include <stdlib.h>  // Para malloc(), free(), exit(), abs()
# include <stdio.h>   // Para depuración (¡pero usa write para errores finales!)

// Incluir tu libft
# include "libft.h"

// Estructuras de Datos
// Para el mapa y sus propiedades
typedef struct s_map
{
    char    **grid;
    int     rows;
    int     cols;
    int     player_x;
    int     player_y;
    int     collectibles;
    int     exit_count;
    int     player_count;
}   t_map;

// Para coordenadas (útil en BFS y manejo de posiciones)
typedef struct s_coords
{
    int x;
    int y;
}   t_coords;

// Para el estado del algoritmo BFS (validación de camino)
typedef struct s_bfs_state
{
    char        **temp_grid; // Copia del mapa para modificar en BFS
    t_coords    *queue;      // Cola para BFS
    int         head;        // Cabeza de la cola
    int         tail;        // Cola de la cola
    int         found_collectibles; // Coleccionables encontrados en el camino
    int         found_exit;         // Salida encontrada en el camino
    int         rows;        // Filas del mapa
    int         cols;        // Columnas del mapa
}   t_bfs_state;

// (Más estructuras para MiniLibX y el juego se añadirán más tarde)
// Ej: typedef struct s_game { void *mlx; void *win; t_map *map; /* ... */ } t_game;


// --- PROTOTIPOS DE FUNCIONES ---

// utils.c: Funciones de utilidad general
void    ft_error_exit(const char *msg); // Máx 5 líneas. Sale con mensaje de error.
void    free_map_grid(char **grid, int rows); // Libera la matriz del mapa.
int     is_ber_extension(const char *filename); // Comprueba extensión .ber.
char    **copy_grid(char **original_grid, int rows, int cols); // Copia el grid para BFS.

// map_reader.c: Funciones para leer el archivo del mapa
char    *ft_read_file_to_string(const char *map_file); // Lee todo el archivo en 1 string.
void    ft_fill_map_details(t_map *map, char *file_content); // Llena grid, rows, cols.
t_map   *init_game_map(const char *map_file); // Función de alto nivel para leer y validar.
t_map   *setup_game_map(const char *filename); // Orquesta la inicialización del mapa.

// map_validator.c: Funciones para validaciones básicas del mapa
void    validate_map_rectangular(t_map *map); // Solo la rectangularidad.
void    validate_map_elements_and_counts(t_map *map); // Caracteres permitidos y conteo P, C, E.
void    validate_map_walls(t_map *map); // Muros en los bordes.

// map_path_finder.c: Funciones para la validación de camino (BFS)
t_bfs_state *ft_init_bfs_state(t_map *map); // Inicializa el estado BFS.
void        ft_process_neighbor(t_bfs_state *state, int nr, int nc); // Procesa un vecino en BFS.
void        ft_run_bfs(t_bfs_state *state); // Ejecuta el bucle principal de BFS.
void        ft_check_path_validity(t_bfs_state *state, t_map *map); // Verifica el resultado BFS.
void        ft_cleanup_bfs_state(t_bfs_state *state, t_map *map); // Libera memoria BFS.
void        validate_map_path(t_map *map); // Orquestador de la validación de camino.


// (Más prototipos para MiniLibX, renderizado, eventos y lógica del juego)

#endif