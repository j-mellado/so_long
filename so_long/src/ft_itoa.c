/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmellado <jmellado@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 10:13:22 by jmellado          #+#    #+#             */
/*   Updated: 2025/07/21 10:13:25 by jmellado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static long int	ft_baseexponente(long int base, size_t exp)
{
	long int	nbr;

	if (exp == 0)
		return (1);
	nbr = base;
	while (--exp)
		nbr *= base;
	return (nbr);
}

char	*ft_itoa(int n)
{
	char	*nbr;
	size_t	digitos;

	digitos = 1;
	while (n / ft_baseexponente(10, digitos))
		digitos++;
	nbr = (char *)ft_calloc(digitos + 1, sizeof(char));
	if (!nbr)
		return (0);
	while (--digitos)
	{
		nbr[digitos] = (char)((n % 10) + '0');
		n /= 10;
	}
	nbr[digitos] = (char)((n % 10) + '0');
	return (nbr);
}
