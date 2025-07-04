// srcs/utils.c
#include "../inc/so_long.h"

// Sale del programa con un mensaje de error en stderr
void ft_error_exit(const char *msg)
{
    write(STDERR_FILENO, "Error\n", 6);
    write(STDERR_FILENO, msg, ft_strlen(msg));
    write(STDERR_FILENO, "\n", 1);
    exit(EXIT_FAILURE);
}

// Libera la memoria de una matriz de caracteres (grid)
void free_map_grid(char **grid, int rows)
{
    int i;

    if (!grid) // Check if grid is NULL
        return;
    i = 0;
    while (i < rows)
    {
        free(grid[i]);
        i++;
    }
    free(grid);
}

// Comprueba si un nombre de archivo tiene la extensión .ber
int is_ber_extension(const char *filename)
{
    size_t len;

    len = ft_strlen(filename);
    if (len < 4)
        return (0);
    return (ft_strncmp(filename + len - 4, ".ber", 4) == 0);
}

// Crea una copia profunda de la matriz del mapa
char **copy_grid(char **original_grid, int rows, int cols)
{
    char **copy;
    int i;
    (void)cols; 

    copy = (char **)malloc(rows * sizeof(char *));
    if (!copy)
        return (NULL);
    i = 0;
    while (i < rows)
    {
        copy[i] = ft_strdup(original_grid[i]); // ft_strdup de libft
        if (!copy[i])
        {
            free_map_grid(copy, i);
            return (NULL);
        }
        i++;
    }
    return (copy);
}