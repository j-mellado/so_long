/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmellado <jmellado@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 10:14:14 by jmellado          #+#    #+#             */
/*   Updated: 2025/07/21 10:14:17 by jmellado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	check_exit(t_list *d, char letter)
{
	if (letter == 'E' && d->consum == 0)
	{
		write(1, "Completaste el mapa\n", 21);
		ft_free(d);
	}
	if (letter == 'E' && d->consum != 0)
	{
		write(1, "Necesitas recoger todos los consumibles!\n", 41);
		return (1);
	}
	else
		return (0);
}
