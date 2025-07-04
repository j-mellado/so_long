// srcs/main.c
#include "../inc/so_long.h"

int main(int argc, char **argv)
{
    t_map *game_map;

    if (argc != 2)
    {
        ft_error_exit("Uso: ./so_long <mapa.ber>");
    }
    if (!is_ber_extension(argv[1]))
    {
        ft_error_exit("El archivo del mapa debe tener la extension .ber");
    }

    game_map = setup_game_map(argv[1]); // Llama a la función de alto nivel

    // Si llegamos aquí, el mapa es válido
    printf("Mapa cargado y validado correctamente:\n");
    for (int i = 0; i < game_map->rows; i++)
        printf("%s\n", game_map->grid[i]);
    printf("Filas: %d, Cols: %d, C: %d, E: %d, P: %d en (%d, %d)\n",
           game_map->rows, game_map->cols, game_map->collectibles,
           game_map->exit_count, game_map->player_count,
           game_map->player_x, game_map->player_y);


    // --- FASE 3 y 4 irán aquí (inicialización de MLX, renderizado, bucle de juego) ---

    // Liberar la memoria del mapa al final
    free_map_grid(game_map->grid, game_map->rows);
    free(game_map);

    return (EXIT_SUCCESS);
}