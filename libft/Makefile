# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmellado <jmellado@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/12 16:12:47 by jmellado          #+#    #+#              #
#    Updated: 2024/11/22 14:34:22 by jmellado         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Archivo: libft/Makefile

# Estándar
NAME            = libft.a

# Directorios
INC             = inc/
SRC_DIR         = srcs/
OBJ_DIR         = obj/

# Compilador y Flags
CC              = gcc
CFLAGS          = -Wall -Wextra -Werror # Eliminado el -I incompleto de aquí
RM              = rm -f
AR              = ar rcs

# Archivos Fuente
# =========================================================================
# ¡IMPORTANTE!: Definición robusta de SRC usando 'find'
# Esto busca recursivamente todos los archivos .c dentro de $(SRC_DIR) y sus subdirectorios.
# Así no tienes que listar cada archivo manualmente ni preocuparte por las variables no definidas.
SRC             = $(shell find $(SRC_DIR) -name "*.c")
# =========================================================================

# Aplicar la sustitución de patrón para crear la lista de archivos objeto
# Esto convierte rutas como 'src/mi_funcion.c' en 'obj/mi_funcion.o'
OBJ             = $(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)%.o,$(SRC))

# Reglas de construcción
all:            $(NAME)

# Regla para construir la biblioteca estática libft.a
# Depende de todos los archivos objeto (.o) en la lista OBJ
$(NAME):        $(OBJ)
				@$(AR) $(NAME) $(OBJ) # <-- ¡Asegúrate de que esta línea empieza con un TAB!

# Regla para compilar cada archivo .c en su correspondiente archivo .o
# (ej. src/ft_strncmp.c -> obj/ft_strncmp.o)
$(OBJ_DIR)%.o:  $(SRC_DIR)%.c
				@mkdir -p $(@D) # Crea el directorio 'obj/' si no existe.
				@$(CC) $(CFLAGS) -I$(INC) -c $< -o $@ # <-- Se usa -I$(INC) para la ruta de los includes. ¡Asegúrate del TAB!

clean:
				@$(RM) -r $(OBJ_DIR) # Borra el directorio 'obj/' y su contenido.
                # @$(RM) .cache_exists # Descomenta si usas esta cache y quieres borrarla en clean

fclean:         clean
				@$(RM) $(NAME) # Borra la biblioteca 'libft.a'
				@$(RM) -r $(OBJ_DIR) # Asegura que 'obj/' se borra también en fclean.

re:             fclean all

.PHONY:         all clean fclean re