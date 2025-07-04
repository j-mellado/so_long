/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmellado <jmellado@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 15:55:43 by jmellado          #+#    #+#             */
/*   Updated: 2024/10/12 17:23:00 by jmellado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (*s != '\0')
	{
		len++;
		s++;
	}
	return (len);
}
/*
#include <stdio.h> <stdio.h> needed for test

int	main(void)
{
	const char	str[] = "12345678";
	size_t		ln;

	ln = ft_strlen(str);
	printf("the len of str is %zu", ln);
	return (0);
}
*/
