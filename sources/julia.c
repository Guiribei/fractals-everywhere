/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guribeir <guribeir@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 20:00:35 by guribeir          #+#    #+#             */
/*   Updated: 2022/07/21 04:43:36 by guribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	julia(t_fractol *fr, double zr, double zi)
{
	int		n;
	double	aux;

	n = 0;
	while (n < MAX_ITERATIONS)
	{
		if (zr * zr + zi * zi > 4.0)
			break ;
		aux = 2 * zr * zi + fr->ki;
		zr = zr * zr - zi * zi + fr->kr;
		zi = aux;
		n++;
	}
	return (n);
}
