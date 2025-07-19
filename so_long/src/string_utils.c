/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmellado <jmellado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 00:00:00 by jmellado          #+#    #+#             */
/*   Updated: 2025/07/19 00:00:00 by jmellado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return (&((char *)s)[i]);
		i++;
	}
	if ((char)c == '\0')
		return (&((char *)s)[i]);
	return (0);
}

char	*ft_substr(char const *s, unsigned int start, int len)
{
	int		i;
	char	*copia;

	i = 0;
	if (len > ft_strlen(s))
		len = ft_strlen(s);
	if (!s)
		return (0);
	copia = malloc(sizeof(char) * (len + 1));
	if (!copia)
		return (0);
	while (s[start] && start < ((unsigned int)ft_strlen(s)) && i < len)
	{
		copia[i] = s[start];
		i++;
		start++;
	}
	copia[i] = '\0';
	return (copia);
}
