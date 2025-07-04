// srcs/map_reader.c
#include "../inc/so_long.h"

// Lee todo el contenido de un archivo a un string único
// (Asegúrate de que esta función cumple el límite de 25 líneas.
//  Podrías necesitar una sub-función si el bucle de lectura es muy grande).
char *ft_read_file_to_string(const char *map_file)
{
    int     fd;
    char    buffer[1024]; // Tamaño del buffer ajustable
    char    *map_content;
    int     bytes_read;

    fd = open(map_file, O_RDONLY);
    if (fd < 0)
        ft_error_exit("No se pudo abrir el archivo del mapa.");

    map_content = ft_strdup(""); // Necesita tu ft_strdup de Libft
    if (!map_content)
        ft_error_exit("Error de asignacion de memoria para contenido del mapa.");

    while ((bytes_read = read(fd, buffer, sizeof(buffer) - 1)) > 0)
    {
        buffer[bytes_read] = '\0';
        char *temp = ft_strjoin(map_content, buffer); // Necesita tu ft_strjoin
        free(map_content);
        map_content = temp;
        if (!map_content)
            ft_error_exit("Error de reasignacion de memoria al leer el mapa.");
    }
    close(fd);

    if (bytes_read < 0)
    {
        free(map_content);
        ft_error_exit("Error al leer el archivo.");
    }
    return map_content;
}

// Llena la matriz `grid` de `t_map` y calcula `rows` y `cols`
void ft_fill_map_details(t_map *map, char *file_content)
{
    map->grid = ft_split(file_content, '\n'); // Necesita tu ft_split
    if (!map->grid)
    {
        free(map); // Libera la estructura map si ft_split falla
        ft_error_exit("Error al dividir el contenido del mapa en filas.");
    }

    map->rows = 0;
    while (map->grid[map->rows] != NULL)
        map->rows++;

    if (map->rows == 0) // Mapa vacío o solo saltos de línea
    {
        free_map_grid(map->grid, 0); // No hay filas, solo el puntero al array de punteros
        free(map);
        ft_error_exit("El mapa esta vacio.");
    }
    map->cols = ft_strlen(map->grid[0]);
}

// Función de alto nivel para inicializar el mapa del juego
t_map *init_game_map(const char *map_file)
{
    char    *file_content;
    t_map   *map;

    file_content = ft_read_file_to_string(map_file);

    map = (t_map *)malloc(sizeof(t_map));
    if (!map)
    {
        free(file_content);
        ft_error_exit("Error de asignacion de memoria para la estructura t_map.");
    }
    ft_bzero(map, sizeof(t_map)); // ft_bzero de Libft o inicializar manualmente a 0/NULL

    ft_fill_map_details(map, file_content);
    free(file_content); // Liberar el string que ya no se necesita

    return map;
}