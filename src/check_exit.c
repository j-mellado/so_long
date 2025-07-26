/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmellado <jmellado@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 10:14:14 by jmellado          #+#    #+#             */
/*   Updated: 2025/07/26 19:06:46 by jmellado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	check_exit(t_list *d, char letter)
{
	if (letter == 'E' && d->consum == 0)
	{
		write(1, "Completaste el mapa\n", 21);
		ft_free(d);
	}
	if (letter == 'E' && d->consum != 0)
	{
		write(1, "Necesitas recoger todos los consumibles!\n", 41);
		return (0);
	}
	else
		return (0);
}

void	find_exit_position(t_list *d)
{
	int	i;

	i = 0;
	while (d->big_line[i])
	{
		if (d->big_line[i] == 'E')
		{
			d->exit_pos = i;
			break ;
		}
		i++;
	}
}

void	restore_exit_if_needed(t_list *d, int old_pos)
{
	if (old_pos == d->exit_pos)
		d->big_line[old_pos] = 'E';
	else
		d->big_line[old_pos] = '0';
}
