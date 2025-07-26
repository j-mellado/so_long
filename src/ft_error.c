/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmellado <jmellado@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 10:13:47 by jmellado          #+#    #+#             */
/*   Updated: 2025/07/26 18:43:20 by jmellado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	ft_error2(int num)
{
	if (num == 8)
		write(1, "El mapa contiene caracteres erroneos.\n", 39);
	if (num == 9)
		write(1, "El mapa no es rectangular\n", 27);
	if (num == 10)
		write(1, "Error de memoria al copiar el mapa.\n", 37);
	if (num == 11)
		write(1, "No se encontro la posicion del jugador.\n", 41);
	if (num == 12)
		write(1, "No se pueden alcanzar todos los coleccionables.\n", 49);
	if (num == 13)
		write(1, "No se puede alcanzar la salida.\n", 33);
	if (num == 14)
		write(1, "Error al leer el archivo del mapa\n", 35);
}

void	ft_error(t_list *d, int num)
{
	write(1, "❌ERROR❌\n", 12);
	if (num > 7)
		ft_error2(num);
	if (num == 1)
		write(1, "En el principio de linea no hay pared.\n", 40);
	if (num == 2)
		write(1, "En el final de linea no hay pared.\n", 36);
	if (num == 3)
		write(1, "En la primera linea no hay pared.\n", 35);
	if (num == 4)
		write(1, "En la ultima linea no hay pared.\n", 34);
	if (d->consum < 1 && num == 5)
		write(1, "No hay consumibles!\n", 21);
	if (d->player != 1 && num == 5)
		write(1, "El mapa solo debe tener un personaje.\n", 39);
	if (d->ex < 1 && num == 5)
		write(1, "El mapa debe contener una salida.\n", 35);
	if (num == 6)
		write(1, "El fichero no tiene la extension correcta.\n", 44);
	if (num == 7)
		write(1, "El mapa no es rectangular.\n", 28);
	ft_free(d);
}
