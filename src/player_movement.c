/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmellado <jmellado@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 00:00:00 by jmellado          #+#    #+#             */
/*   Updated: 2025/07/26 19:01:53 by jmellado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"
#include "../mlx/mlx.h"

void	move_w(t_list *d)
{
	int	i;

	i = 0;
	while (d->big_line[i] != 'P')
		i++;
	if (d->big_line[i - d->width_l] != '1'
		&& !check_exit(d, d->big_line[i - d->width_l]))
	{
		d->moves++;
		if (d->big_line[i - d->width_l] == 'C')
			d->consum--;
		restore_exit_if_needed(d, i);
		d->big_line[i - d->width_l] = 'P';
	}
	print_map(d);
}

void	move_s(t_list *d)
{
	int	i;

	i = 0;
	while (d->big_line[i] != 'P')
		i++;
	if (d->big_line[i + d->width_l] != '1'
		&& !check_exit(d, d->big_line[i + d->width_l]))
	{
		d->moves++;
		if (d->big_line[i + d->width_l] == 'C')
			d->consum--;
		restore_exit_if_needed(d, i);
		d->big_line[i + d->width_l] = 'P';
	}
	print_map(d);
}

void	move_a(t_list *d)
{
	int	i;

	i = 0;
	while (d->big_line[i] != 'P')
		i++;
	if (d->big_line[i - 1] != '1' && !check_exit(d, d->big_line[i - 1]))
	{
		d->moves++;
		if (d->big_line[i - 1] == 'C')
			d->consum--;
		restore_exit_if_needed(d, i);
		d->big_line[i - 1] = 'P';
	}
	print_map(d);
}

void	move_d(t_list *d)
{
	int	i;

	i = 0;
	while (d->big_line[i] != 'P')
		i++;
	if (d->big_line[i + 1] != '1' && !check_exit(d, d->big_line[i + 1]))
	{
		d->moves++;
		if (d->big_line[i + 1] == 'C')
			d->consum--;
		restore_exit_if_needed(d, i);
		d->big_line[i + 1] = 'P';
	}
	print_map(d);
}
