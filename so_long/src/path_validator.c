/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_validator.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmellado <jmellado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 00:00:00 by jmellado          #+#    #+#             */
/*   Updated: 2025/07/19 00:00:00 by jmellado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	flood_fill(char *map, int pos, int width, int height, 
					int *collectibles, int *exit_found)
{
	if (pos < 0 || pos >= width * height)
		return;
	if (map[pos] == '\n' || map[pos] == '1' || map[pos] == 'V')
		return;
	if (map[pos] == 'C')
		(*collectibles)++;
	if (map[pos] == 'E')
		*exit_found = 1;
	map[pos] = 'V';
	if (pos % width > 0)
		flood_fill(map, pos - 1, width, height, collectibles, exit_found);
	if (pos % width < width - 2)
		flood_fill(map, pos + 1, width, height, collectibles, exit_found);
	if (pos >= width)
		flood_fill(map, pos - width, width, height, collectibles, exit_found);
	if (pos < width * (height - 1))
		flood_fill(map, pos + width, width, height, collectibles, exit_found);
}

void	check_flood_results(t_list *d, char *map_copy, 
						int collectibles_found, int exit_found)
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
