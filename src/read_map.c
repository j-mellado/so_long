/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmellado <jmellado@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 10:12:14 by jmellado          #+#    #+#             */
/*   Updated: 2025/07/26 18:20:03 by jmellado         ###   ########.fr       */
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
			ft_error(d, 14);
		process_line(d, line);
		if (line)
			free(line);
	}
	close(fd);
	check_fst_line(d);
	checkline(d);
}
