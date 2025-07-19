/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmellado <jmellado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 00:00:00 by jmellado          #+#    #+#             */
/*   Updated: 2025/07/15 00:00:00 by jmellado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

char	*copy_map(t_list *d)
{
	char	*map_copy;
	int		i;

	map_copy = ft_calloc(ft_strlen(d->big_line) + 1, sizeof(char));
	if (!map_copy)
		ft_error(d, 10);
	i = 0;
	while (d->big_line[i])
	{
		map_copy[i] = d->big_line[i];
		i++;
	}
	map_copy[i] = '\0';
	return (map_copy);
}

int	find_player_position(t_list *d)
{
	int	i;

	i = 0;
	while (d->big_line[i])
	{
		if (d->big_line[i] == 'P')
			return (i);
		i++;
	}
	return (-1);
}

void	validate_map_path(t_list *d)
{
	char	*map_copy;
	int		player_pos;
	int		collectibles_found;
	int		exit_found;

	map_copy = copy_map(d);
	player_pos = find_player_position(d);
	if (player_pos == -1)
		ft_error(d, 11);
	collectibles_found = 0;
	exit_found = 0;
	flood_fill(map_copy, player_pos, d->width_l, d->height_l, 
				&collectibles_found, &exit_found);
	check_flood_results(d, map_copy, collectibles_found, exit_found);
	free(map_copy);
}
