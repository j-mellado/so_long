/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmellado <jmellado@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 10:11:38 by jmellado          #+#    #+#             */
/*   Updated: 2025/07/21 10:15:39 by jmellado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"
#include "../mlx/mlx.h"

int	key_press(int key, t_list *d)
{
	char	*moves_p;

	if (key == KEY_ESC)
	{
		mlx_destroy_window(d->mlx, d->win);
		ft_free(d);
	}
	if (key == KEY_W || key == KEY_UP)
		move_w(d);
	if (key == KEY_A || key == KEY_LEFT)
		move_a(d);
	if (key == KEY_S || key == KEY_DOWN)
		move_s(d);
	if (key == KEY_D || key == KEY_RIGHT)
		move_d(d);
	moves_p = ft_itoa(d->moves);
	write(1, moves_p, ft_strlen(moves_p));
	if (moves_p)
		free(moves_p);
	write(1, "\n", 1);
	return (0);
}
