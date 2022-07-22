/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guribeir <guribeir@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 17:43:21 by guribeir          #+#    #+#             */
/*   Updated: 2022/07/21 13:56:07 by guribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	img_pix_put(t_fractol *fr, int x, int y, int color)
{
	char	*pixel;

	pixel = fr->im.add + (y * fr->im.ll + x * (fr->im.bpp / 8));
	*(int *)pixel = color;
}

void	draw_fractal(t_fractol *fr)
{
	double		pr;
	double		pi;
	int			count;

	count = 0;
	fr->y = 0;
	while (fr->y < HEIGHT)
	{
		fr->x = 0;
		while (fr->x < WIDTH)
		{
			pr = fr->min_r + (double)fr->x * (fr->max_r - fr->min_r) / WIDTH;
			pi = fr->min_i + (double)fr->y * (fr->max_i - fr->min_i) / HEIGHT;
			if (fr->set == 1)
				count = mandelbrot(pr, pi);
			if (fr->set == 2)
				count = julia(fr, pr, pi);
			if (fr->set == 3)
				count = tricorn(pr, pi);
			color_select(fr, count);
			fr->x++;
		}
		fr->y++;
	}
}

int	render(t_fractol *fr)
{
	if (fr->win == NULL)
		return (1);
	mlx_clear_window(fr->mlx, fr->win);
	draw_fractal(fr);
	mlx_put_image_to_window(fr->mlx, fr->win, fr->im.img, 0, 0);
	return (0);
}
