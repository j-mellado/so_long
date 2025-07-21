/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_validator.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmellado <jmellado@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 00:00:00 by jmellado          #+#    #+#             */
/*   Updated: 2025/07/21 10:20:28 by jmellado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	flood_fill(t_flood_data *data, int pos)
{
	if (pos < 0 || pos >= data->width * data->height)
		return ;
	if (data->map[pos] == '\n' || data->map[pos] == '1'
		|| data->map[pos] == 'V')
		return ;
	if (data->map[pos] == 'C')
		data->collectibles++;
	if (data->map[pos] == 'E')
		data->exit_found = 1;
	data->map[pos] = 'V';
	if (pos % data->width > 0)
		flood_fill(data, pos - 1);
	if (pos % data->width < data->width - 2)
		flood_fill(data, pos + 1);
	if (pos >= data->width)
		flood_fill(data, pos - data->width);
	if (pos < data->width * (data->height - 1))
		flood_fill(data, pos + data->width);
}

void	check_flood_results(t_list *d, char *map_copy, int collectibles_found,
		int exit_found)
{
	if (collectibles_found != d->consum)
	{
		free(map_copy);
		ft_error(d, 12);
	}
	if (!exit_found)
	{
		free(map_copy);
		ft_error(d, 13);
	}
}
