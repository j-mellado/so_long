/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_w.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 22:51:33 by marvin            #+#    #+#             */
/*   Updated: 2022/05/20 19:31:19 by marvin           ###   ########.fr       */
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
