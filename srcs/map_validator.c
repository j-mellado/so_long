// srcs/map_validator.c
#include "../inc/so_long.h"

// Valida que todas las filas del mapa tienen la misma longitud (rectangular)
void validate_map_rectangular(t_map *map)
{
    int i;

    i = 0;
    while (i < map->rows)
    {
        if ((int)ft_strlen(map->grid[i]) != map->cols)
        {
            free_map_grid(map->grid, map->rows);
            free(map);
            ft_error_exit("El mapa no es rectangular.");
        }
        i++;
    }
}

// Procesa un solo caracter del mapa y actualiza los contadores
static void process_map_char(t_map *map, char c, int x, int y)
{
    if (c == 'C')
        map->collectibles++;
    else if (c == 'E')
        map->exit_count++;
    else if (c == 'P')
    {
        map->player_count++;
        map->player_x = x;
        map->player_y = y;
    }
    else if (c != '0' && c != '1')
    {
        free_map_grid(map->grid, map->rows);
        free(map);
        ft_error_exit("El mapa contiene caracteres no validos.");
    }
}

// Valida los elementos P, C, E y sus conteos
void validate_map_elements_and_counts(t_map *map)
{
    int i;
    int j;

    map->collectibles = 0;
    map->exit_count = 0;
    map->player_count = 0;

    i = 0;
    while (i < map->rows)
    {
        j = 0;
        while (j < map->cols)
        {
            process_map_char(map, map->grid[i][j], j, i);
            j++;
        }
        i++;
    }

    if (map->collectibles < 1)
        ft_error_exit("El mapa debe tener al menos un coleccionable.");
    if (map->exit_count != 1)
        ft_error_exit("El mapa debe tener exactamente una salida.");
    if (map->player_count != 1)
        ft_error_exit("El mapa debe tener exactamente una posicion inicial del jugador.");
}

// Valida que el mapa esté rodeado de muros
void validate_map_walls(t_map *map)
{
    int i;

    // Verificar filas superior e inferior
    i = 0;
    while (i < map->cols)
    {
        if (map->grid[0][i] != '1' || map->grid[map->rows - 1][i] != '1')
            ft_error_exit("El mapa no esta cerrado por muros (fila superior/inferior).");
        i++;
    }

    // Verificar columnas izquierda y derecha
    i = 0;
    while (i < map->rows)
    {
        if (map->grid[i][0] != '1' || map->grid[i][map->cols - 1] != '1')
            ft_error_exit("El mapa no esta cerrado por muros (columna izquierda/derecha).");
        i++;
    }
}