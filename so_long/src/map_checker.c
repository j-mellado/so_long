/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmellado <jmellado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 00:00:00 by jmellado          #+#    #+#             */
/*   Updated: 2025/07/19 00:00:00 by jmellado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	check_start_line(t_list *d)
{
	int	i;

	i = d->width_l - 2;
	while (i < ft_strlen(d->big_line))
	{
		if (d->big_line[i] == '1')
			i = i + d->width_l;
		else
			ft_error(d, 2);
	}
	i = d->width_l;
	while (i < ft_strlen(d->big_line))
	{
		if (d->big_line[i] == '1')
			i = i + d->width_l;
		else
			ft_error(d, 1);
	}
}

void	check_fst_line(t_list *d)
{
	int	i;
	int	last;

	i = 0;
	last = ft_strlen(d->big_line) - d->width_l;
	while (i != d->width_l)
	{
		if (d->big_line[i] == '1' || d->big_line[i] == '\n')
			i++;
		else
			ft_error(d, 3);
	}
	while (last != ft_strlen(d->big_line))
	{
		if (d->big_line[last] == '1' || d->big_line[last] == '\n')
			last++;
		else
			ft_error(d, 4);
	}
	check_start_line(d);
}

void	checkline(t_list *d)
{
	int	i;

	i = 0;
	while (d->big_line[i])
	{
		if (d->big_line[i] != 'C' && d->big_line[i] != 'E'
			&& d->big_line[i] != '1'
			&& d->big_line[i] != '0' && d->big_line[i] != 'P'
			&& d->big_line[i] != '\n')
			ft_error(d, 8);
		if (d->big_line[i] == 'C')
			d->consum++;
		else if (d->big_line[i] == 'E')
			d->ex++;
		else if (d->big_line[i] == '1')
			d->wall++;
		else if (d->big_line[i] == '0')
			d->back++;
		else if (d->big_line[i] == 'P')
			d->player++;
		i++;
	}
	if (d->consum < 1 || d->ex < 1 || d->wall < 1
		|| d->player != 1)
		ft_error(d, 5);
}
