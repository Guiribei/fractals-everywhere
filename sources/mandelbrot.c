/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guribeir <guribeir@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 20:03:03 by guribeir          #+#    #+#             */
/*   Updated: 2022/07/21 04:42:18 by guribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mandelbrot(double cr, double ci)
{
	int		n;
	double	zr;
	double	zi;
	double	aux;

	n = 0;
	zr = 0;
	zi = 0;
	while (n < MAX_ITERATIONS)
	{
		if (zr * zr + zi * zi > 4.0)
			break ;
		aux = 2 * zr * zi + ci;
		zr = zr * zr - zi * zi + cr;
		zi = aux;
		n++;
	}
	return (n);
}
