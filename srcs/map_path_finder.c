// srcs/map_path_finder.c
#include "../inc/so_long.h"

// Inicializa el estado BFS (copia el grid, inicializa cola)
t_bfs_state *ft_init_bfs_state(t_map *map)
{
    t_bfs_state *state;

    state = (t_bfs_state *)malloc(sizeof(t_bfs_state));
    if (!state)
        ft_error_exit("Error de asignacion de memoria para estado BFS.");
    ft_bzero(state, sizeof(t_bfs_state)); // Inicializa todo a 0/NULL

    state->temp_grid = copy_grid(map->grid, map->rows, map->cols);
    if (!state->temp_grid)
    {
        free(state);
        ft_error_exit("Error de asignacion de memoria para copia del mapa BFS.");
    }

    state->queue = (t_coords *)malloc(map->rows * map->cols * sizeof(t_coords));
    if (!state->queue)
    {
        free_map_grid(state->temp_grid, map->rows);
        free(state);
        ft_error_exit("Error de asignacion de memoria para cola BFS.");
    }

    state->rows = map->rows;
    state->cols = map->cols;
    state->queue[state->tail++] = (t_coords){map->player_x, map->player_y};
    state->temp_grid[map->player_y][map->player_x] = 'V'; // Marcar inicio como visitado
    return state;
}

// Procesa un vecino específico en el BFS
static void ft_process_single_neighbor(t_bfs_state *state, int nr, int nc)
{
    char next_char;

    if (nr < 0 || nr >= state->rows || nc < 0 || nc >= state->cols)
        return; // Fuera de límites

    next_char = state->temp_grid[nr][nc];
    if (next_char == '1' || next_char == 'V') // Es muro o ya visitado
        return;

    if (next_char == 'C')
        state->found_collectibles++;
    else if (next_char == 'E')
        state->found_exit++;

    state->temp_grid[nr][nc] = 'V'; // Marcar como visitado
    state->queue[state->tail++] = (t_coords){nc, nr}; // Añadir a la cola
}

// Explora los 4 vecinos de la posición actual
void ft_bfs_explore_neighbors(t_bfs_state *state, t_coords current)
{
    int dr[] = {-1, 1, 0, 0}; // Cambios en fila (arriba, abajo)
    int dc[] = {0, 0, -1, 1}; // Cambios en columna (izquierda, derecha)
    int i;

    i = 0;
    while (i < 4)
    {
        ft_process_single_neighbor(state, current.y + dr[i], current.x + dc[i]);
        i++;
    }
}

// Ejecuta el bucle principal del BFS
void ft_run_bfs(t_bfs_state *state)
{
    while (state->head < state->tail)
    {
        t_coords current = state->queue[state->head++];
        ft_bfs_explore_neighbors(state, current);
    }
}

// Verifica el resultado final del BFS
void ft_check_path_validity(t_bfs_state *state, t_map *map)
{
    if (state->found_collectibles != map->collectibles || state->found_exit == 0)
    {
        // Libera la memoria específica de BFS antes de la salida de error
        free_map_grid(state->temp_grid, state->rows);
        free(state->queue);
        free(state);
        // ft_error_exit también se encargará de liberar el 'map' principal si no está ya liberado
        ft_error_exit("El mapa no tiene un camino valido para todos los coleccionables y la salida.");
    }
}

// Libera la memoria asignada para el estado BFS
void ft_cleanup_bfs_state(t_bfs_state *state, t_map *map) // map es solo para consistencia con ft_error_exit si se llama desde ahi
{
    (void)map; // Para evitar warnings de variable no usada
    if (state)
    {
        free_map_grid(state->temp_grid, state->rows);
        free(state->queue);
        free(state);
    }
}

// Orquesta la validación del camino completo (función principal de este módulo)
void validate_map_path(t_map *map)
{
    t_bfs_state *state;

    state = ft_init_bfs_state(map);
    ft_run_bfs(state);
    ft_check_path_validity(state, map);
    ft_cleanup_bfs_state(state, map);
}