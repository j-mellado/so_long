/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 10:39:46 by marvin            #+#    #+#             */
/*   Updated: 2022/05/20 00:51:05 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"



void	process_line(t_list *d, char *line)
{
	int	i;

	if (d->linecontrol == 2)
		d->width_l = ft_strlen(line);
	i = 0;
	d->linecontrol = 1;
	while (line[i])
	{
		if (line[i] == '\n')
			d->linecontrol = 0;
		i++;
	}
	if (ft_strlen(line) + d->linecontrol != d->width_l)
		ft_error(d, 7);
	d->big_line = ft_strjoin(d->big_line, line);
}

void	read_map(char *map, t_list *d)
{
	int		fd;
	char	*line;

	fd = open(map, O_RDONLY);
	if (fd < 0)
		ft_free(d);
	d->linecontrol = 2;
	while (d->linecontrol != 1)
	{
		d->height_l++;
		line = get_next_line(fd);
		if (!line)
			ft_error(d, 9);
		process_line(d, line);
		if (line)
			free(line);
	}
	close(fd);
	check_fst_line(d);
	checkline(d);
}
