/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmellado <jmellado@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 10:11:30 by jmellado          #+#    #+#             */
/*   Updated: 2025/07/21 10:15:33 by jmellado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

char	*readbuf(int fd, char *line)
{
	int		r;
	char	*buffer;

	r = 1;
	buffer = malloc(sizeof(char) * (1 + 1));
	if (!buffer)
		return (NULL);
	buffer[0] = '\0';
	while (r > 0 && !ft_strchr(buffer, '\n'))
	{
		r = read(fd, buffer, 1);
		if (r == -1)
		{
			free(buffer);
			return (NULL);
		}
		if (r > 0)
		{
			buffer[r] = '\0';
			line = ft_strjoin(line, buffer);
		}
	}
	free(buffer);
	return (line);
}

char	*get_next_line(int fd)
{
	char	*line;
	char	*line2;

	line2 = NULL;
	if (fd < 0)
		return (NULL);
	line = readbuf(fd, line2);
	return (line);
}
