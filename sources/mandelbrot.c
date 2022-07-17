/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guribeir <guribeir@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 17:43:21 by guribeir          #+#    #+#             */
/*   Updated: 2022/07/17 17:57:56 by guribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	mandelbrot(t_img *im, t_coord *cd, double cr, double ci)
{
	int		n;
	double	zr;
	double	zi;
	double	aux;
	int		is_part_set;

	zr = 0;
	zi = 0;
	n = -1;
	is_part_set = 1;
	while (++n < MAX_ITERATIONS)
	{
		if (zr * zr + zi * zi > 4.0)
		{
			is_part_set = 0;
			break ;
		}
		aux = 2 * zr * zi + ci;
		zr = zr * zr - zi * zi + cr;
		zi = aux;
	}
	if (is_part_set == 1)
		img_pix_put(im, cd->x, cd->y, 0x00000000);
	else
		img_pix_put(im, cd->x, cd->y, 0x00FFFFFF);
}

void	draw_fractal(t_fractol *fr, t_vars *va)
{
	t_coord		cd;
	double		pr;
	double		pi;

	cd.y = 0;
	while (cd.y < HEIGHT)
	{
		cd.x = 0;
		while (cd.x < WIDTH)
		{
			pr = fr->min_r + (double)cd.x * (fr->max_r - fr->min_r) / WIDTH;
			pi = fr->min_i + (double)cd.y * (fr->max_i - fr->min_i) / HEIGHT;
			mandelbrot(&va->im, &cd, pr, pi);
			cd.x++;
		}
		cd.y++;
	}
}

int	render(t_vars *va)
{
	t_fractol	fr;

	if (va->win == NULL)
		return (1);
	fr.mlx = va->mlx;
	fr.min_r = -2.0;
	fr.max_r = 1.0;
	fr.min_i = -1.5;
	fr.max_i = fr.min_i + (fr.max_r - fr.min_r) * HEIGHT / WIDTH;
	fr.win = va->win;
	draw_fractal(&fr, va);
	mlx_put_image_to_window(va->mlx, va->win, va->im.img, 0, 0);
	return (0);
}
