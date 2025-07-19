/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 14:35:34 by marvin            #+#    #+#             */
/*   Updated: 2022/05/20 19:30:43 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"
#include "../mlx/mlx.h"

void	put_sprite(t_list *d, char tile, int x, int y)
{
	if (d->errors == 0)
	{
		if (tile == 'C')
			mlx_put_image_to_window(d->mlx, d->win, d->poke, x, y);
		if (tile == 'E')
			mlx_put_image_to_window(d->mlx, d->win, d->imgexit, x, y);
		if (tile == '1')
			mlx_put_image_to_window(d->mlx, d->win, d->bush, x, y);
		if (tile == '0')
			mlx_put_image_to_window(d->mlx, d->win, d->fond, x, y);
		if (tile == 'P')
			mlx_put_image_to_window(d->mlx, d->win, d->npc, x, y);
	}
}

void	calc_xy(char r, int i, t_list *d)
{
	int	x_;
	int	y_;

	y_ = (i / d->width_l) * 50;
	x_ = (i % d->width_l) * 50;
	put_sprite(d, r, x_, y_);
}

void	print_map(t_list *d)
{
	int	i;
	int	line;
	int	col;

	i = 0;
	line = 0;
	col = 0;
	while (d->big_line[i])
	{
		if (d->big_line[i] == '\n')
		{
			line++;
			col = 0;
			i++;
			continue;
		}
		if (d->big_line[i] != 'C' && d->big_line[i] != 'E'
			&& d->big_line[i] != '1'
			&& d->big_line[i] != '0' && d->big_line[i] != 'P')
			exit(0);
		put_sprite(d, d->big_line[i], col * 50, line * 50);
		col++;
		i++;
	}
}
