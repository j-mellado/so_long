# Archivo: so_long/Makefile

NAME = so_long
CC = cc
CFLAGS = -Wall -Werror -Wextra
MINILIBX_DIR = minilibx
MINILIBX_FLAGS = -L$(MINILIBX_DIR) -lmlx -lXext -lX11

# Directorios del proyecto
LIBFT_DIR = libft
INC_DIR = inc
SRCS_DIR = srcs

# Lista de todos los archivos fuente .c (se irá expandiendo)
SRCS = $(SRCS_DIR)/main.c \
       $(SRCS_DIR)/utils.c \
       $(SRCS_DIR)/map_reader.c \
       $(SRCS_DIR)/map_validator.c \
       $(SRCS_DIR)/map_path_finder.c \
       $(SRCS_DIR)/so_long.c 


OBJS = $(SRCS:.c=.o)

# Regla principal: Compila todo
all: $(NAME)

$(NAME): $(LIBFT_DIR)/libft.a $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT_DIR)/libft.a $(MINILIBX_FLAGS) -o $(NAME)

# Regla para compilar libft: entra al directorio y ejecuta su Makefile
$(LIBFT_DIR)/libft.a:
	$(MAKE) -C $(LIBFT_DIR)

# Regla para compilar archivos .c a .o
%.o: %.c
	$(CC) $(CFLAGS) -I$(INC_DIR) -I$(LIBFT_DIR)/inc -c $< -o $@

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	rm -f $(OBJS)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
