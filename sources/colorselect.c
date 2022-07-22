/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colorselect.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guribeir <guribeir@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 05:31:59 by guribeir          #+#    #+#             */
/*   Updated: 2022/07/21 13:58:20 by guribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	color_select(t_fractol *fr, int n)
{
	if (fr->color % 5 == 0)
		color_1(fr, n);
	else if (fr->color % 5 == 1)
		color_2(fr, n);
	else if (fr->color % 5 == 2)
		color_3(fr, n);
	else if (fr->color % 5 == 3)
		color_4(fr, n);
	else if (fr->color % 5 == 4)
		color_5(fr, n);
}

void	color_1(t_fractol *fr, int n)
{
	int	color;

	color = 0x00000000;
	if (n == MAX_ITERATIONS)
		color = 0x00000000;
	else if (n % 8 == 7)
		color = 0x00C9BF63;
	else if (n % 8 == 6)
		color = 0x008F00FF;
	else if (n % 8 == 5)
		color = 0x4B0082;
	else if (n % 8 == 4)
		color = 0x000000FF;
	else if (n % 8 == 3)
		color = 0x0000FF00;
	else if (n % 8 == 2)
		color = 0x00FFFF00;
	else if (n % 8 == 1)
		color = 0x00FF7F00;
	else if (n % 8 == 0)
		color = 0x00FF0000;
	img_pix_put(fr, fr->x, fr->y, color);
}

void	color_2(t_fractol *fr, int n)
{
	int	color;

	color = 0x00000000;
	if (n == MAX_ITERATIONS)
		color = 0x00000000;
	else if (n % 8 == 7)
		color = 0x00FF0000;
	else if (n % 8 == 6)
		color = 0x00FF0381;
	else if (n % 8 == 5)
		color = 0x00FFCC00;
	else if (n % 8 == 4)
		color = 0x00D1F40B;
	else if (n % 8 == 3)
		color = 0x00FB9AC0;
	else if (n % 8 == 2)
		color = 0x00EAF49D;
	else if (n % 8 == 1)
		color = 0x0053E3EA;
	else if (n % 8 == 0)
		color = 0x006BB6F7;
	img_pix_put(fr, fr->x, fr->y, color);
}

void	color_3(t_fractol *fr, int n)
{
	int	color;

	color = 0x00000000;
	if (n == MAX_ITERATIONS)
		color = 0x00000000;
	else if (n % 8 == 7)
		color = 0x00fafa6e;
	else if (n % 8 == 6)
		color = 0x00b5e877;
	else if (n % 8 == 5)
		color = 0x0077d183;
	else if (n % 8 == 4)
		color = 0x003fb78d;
	else if (n % 8 == 3)
		color = 0x00009c8f;
	else if (n % 8 == 2)
		color = 0x00007f86;
	else if (n % 8 == 1)
		color = 0x001c6373;
	else if (n % 8 == 0)
		color = 0x002a4858;
	img_pix_put(fr, fr->x, fr->y, color);
}
