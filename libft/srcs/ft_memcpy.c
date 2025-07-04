/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmellado <jmellado@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 12:12:29 by jmellado          #+#    #+#             */
/*   Updated: 2024/10/25 08:44:56 by jmellado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t count)
{
	unsigned char		*d;
	const unsigned char	*s;
	size_t				i;

	s = (const unsigned char *)src;
	d = (unsigned char *)dest;
	i = 0;
	while (dest == src || !count)
	{
		return (dest);
	}
	while (i < count)
	{
		d[i] = s[i];
		i++;
	}
	return (dest);
}

/*
int	main(void) <stdio.h> needed for test
{
	char	str1[] = "hola";
	char	str2[] = "Mox";

	printf("before the ft %s\n",str1);
	char* result = ft_memcpy(str1,str2,2);
	prinft("after the ft %s\n",str1);
	return(0);
}
*/
