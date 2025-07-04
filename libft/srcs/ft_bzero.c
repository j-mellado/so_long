/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmellado <jmellado@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 12:12:01 by jmellado          #+#    #+#             */
/*   Updated: 2024/10/09 15:33:01 by jmellado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*ptr;
	size_t			i;

	ptr = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		ptr[i] = 0;
		i++;
	}
}

/*
#include <stdio.h> needed for test

int	main(void)
{
	size_t	n;
	char	str[11] = "abcdefghij";
	char	*rest_str;

	n = 5;
	printf("before the ft %s\n", str);
	ft_bzero(str,n);
	printf("after the ft %s\n", str);
	rest_str = str + n;
	printf("rest of string %s\n", rest_str);
	return (0);
}
*/
