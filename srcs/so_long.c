// srcs/so_long.c (O puedes integrar esta lógica en main.c si main es muy simple)
#include "../inc/so_long.h"

// Función para validar el mapa en su conjunto, llamando a todas las sub-validaciones
void validate_all_map_rules(t_map *map)
{
    validate_map_rectangular(map); // Valida rectangularidad
    validate_map_elements_and_counts(map); // Valida P, C, E y caracteres
    validate_map_walls(map); // Valida muros
    validate_map_path(map); // Valida el camino BFS
}

// Función principal de inicialización de mapa (llamada desde main)
t_map *setup_game_map(const char *map_file)
{
    t_map *map;

    map = init_game_map(map_file); // Lee y llena la estructura t_map

    validate_all_map_rules(map); // Valida todas las reglas del mapa

    return map;
}