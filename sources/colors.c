/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guribeir <guribeir@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 05:37:04 by guribeir          #+#    #+#             */
/*   Updated: 2022/07/21 13:57:06 by guribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	color_4(t_fractol *fr, int n)
{
	int	color;

	color = 0x00000000;
	if (n == MAX_ITERATIONS)
		color = 0x00000000;
	else if (n % 8 == 1)
		color = 0x00615af7;
	else if (n % 8 == 2)
		color = 0x000081ff;
	else if (n % 8 == 3)
		color = 0x00009fff;
	else if (n % 8 == 4)
		color = 0x0000b8ff;
	else if (n % 8 == 5)
		color = 0x0000cdff;
	else if (n % 8 == 6)
		color = 0x0000e0ef;
	else if (n % 8 == 7)
		color = 0x0000f0d7;
	else if (n % 8 == 0)
		color = 0x0066fec3;
	img_pix_put(fr, fr->x, fr->y, color);
}

void	color_5(t_fractol *fr, int n)
{
	int	color;

	color = 0x00000000;
	if (n == MAX_ITERATIONS)
		color = 0x00000000;
	else if (n % 8 == 7)
		color = 0x0009F1FF;
	else if (n % 8 == 6)
		color = 0x000FD3DC;
	else if (n % 8 == 5)
		color = 0x0012B6BA;
	else if (n % 8 == 4)
		color = 0x00139A9A;
	else if (n % 8 == 3)
		color = 0x00117F7C;
	else if (n % 8 == 2)
		color = 0x000E6460;
	else if (n % 8 == 1)
		color = 0x000A4B46;
	else if (n % 8 == 0)
		color = 0x0005332E;
	img_pix_put(fr, fr->x, fr->y, color);
}
