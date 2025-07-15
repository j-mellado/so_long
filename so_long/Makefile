NAME = so_long

SRCS = ./src/so_long.c ./src/read_map.c ./src/print_map.c ./src/get_next_line.c \
			./src/get_next_line_utils.c ./src/key_press.c ./src/check_exit.c \
			./src/ft_free.c ./src/ft_itoa.c ./src/ft_calloc.c ./src/ft_bzero.c \
			./src/ft_memset.c ./src/ft_error.c ./src/map_validator.c

INCLUD = ./inc/so_long.h \
			./mlx/mlx.h

CC = gcc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror
LIB = -L./mlx -lmlx -lXext -lX11 -lm

.c.o:
			@${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

OBJS = ${SRCS:.c=.o}

all:	${NAME}

${NAME}:	${OBJS}
	@make -C ./mlx all
	@cp ./mlx/libmlx.a .
	@$(CC) $(SRCS) $(LIB) -o $(NAME)

clean:
			@make -C ./mlx clean
			@${RM} ${OBJS}

fclean:
			@make -C ./mlx clean
			@${RM} ${OBJS}
			@${RM} ${NAME} libmlx.a

re: fclean all

.PHONY: all clean fclean re
