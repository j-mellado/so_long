/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 19:26:26 by marvin            #+#    #+#             */
/*   Updated: 2022/05/20 20:15:54 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include<unistd.h>
# include<stdlib.h>
# include<limits.h>
# include<stdio.h>
# include<fcntl.h>

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
	char	*big_line;
}	t_list;

int		main(int argc, char **argv);
int		init_data(t_list *d, char *map);
int		ft_strlen(const char *s);
int		key_press(int key, t_list *d);
int		check_exit(t_list *d, char letter);
int		ft_free(t_list *d);
void	print_map(t_list *d);
void	read_map(char *map, t_list *d);
void	validate_map_path(t_list *d);
void	ft_bzero(void *s, size_t n);
void	ft_error(t_list *d, int num);
void	*ft_memset(void *b, int c, size_t len);
void	*ft_calloc(size_t count, size_t size);
char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strchr(const char *s, int c);
char	*ft_itoa(int n);

#endif
