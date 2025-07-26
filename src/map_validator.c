/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmellado <jmellado@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 00:00:00 by jmellado          #+#    #+#             */
/*   Updated: 2025/07/21 11:28:18 by jmellado         ###   ########.fr       */
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
	char			*map_copy;
	int				player_pos;
	t_flood_data	data;

	map_copy = copy_map(d);
	player_pos = find_player_position(d);
	if (player_pos == -1)
		ft_error(d, 11);
	data.map = map_copy;
	data.width = d->width_l;
	data.height = d->height_l;
	data.collectibles = 0;
	data.exit_found = 0;
	flood_fill(&data, player_pos);
	check_flood_results(d, map_copy, data.collectibles, data.exit_found);
	free(map_copy);
}
