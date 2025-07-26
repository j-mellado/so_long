/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmellado <jmellado@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 10:14:29 by jmellado          #+#    #+#             */
/*   Updated: 2025/07/26 19:06:48 by jmellado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

/* Key codes for Linux */
# define KEY_ESC 65307
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_UP 65362
# define KEY_LEFT 65361
# define KEY_DOWN 65364
# define KEY_RIGHT 65363

typedef struct s_list
{
	void	*mlx;
	void	*win;
	void	*bush;
	void	*fond;
	void	*poke;
	void	*npc;
	void	*imgexit;
	int		errors;
	int		moves;
	int		linecontrol;
	int		x;
	int		y;
	int		consum;
	int		ex;
	int		back;
	int		wall;
	int		player;
	int		height_l;
	int		width_l;
	int		exit_pos;
	char	*big_line;
}			t_list;

typedef struct s_flood_data
{
	char	*map;
	int		width;
	int		height;
	int		collectibles;
	int		exit_found;
}			t_flood_data;

int			main(int argc, char **argv);
int			init_data(t_list *d, char *map);
int			ft_strlen(const char *s);
int			key_press(int key, t_list *d);
int			check_exit(t_list *d, char letter);
int			ft_free(t_list *d);
void		find_exit_position(t_list *d);
void		restore_exit_if_needed(t_list *d, int old_pos);
void		print_map(t_list *d);
void		read_map(char *map, t_list *d);
void		validate_map_path(t_list *d);
void		ft_bzero(void *s, size_t n);
void		ft_error(t_list *d, int num);
void		*ft_memset(void *b, int c, size_t len);
void		*ft_calloc(size_t count, size_t size);
char		*get_next_line(int fd);
char		*ft_strjoin(char *s1, char *s2);
char		*ft_strchr(const char *s, int c);
char		*ft_itoa(int n);
void		move_w(t_list *d);
void		move_s(t_list *d);
void		move_a(t_list *d);
void		move_d(t_list *d);
void		check_start_line(t_list *d);
void		check_fst_line(t_list *d);
void		checkline(t_list *d);
void		calc_xy(char r, int i, t_list *d);
void		put_sprite(t_list *d, char tile, int x, int y);
char		*copy_map(t_list *d);
int			find_player_position(t_list *d);
void		flood_fill(t_flood_data *data, int pos);
void		check_flood_results(t_list *d, char *map_copy,
				int collectibles_found, int exit_found);
char		*ft_substr(char const *s, unsigned int start, int len);

#endif
