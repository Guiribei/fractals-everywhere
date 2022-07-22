/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mousehooks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guribeir <guribeir@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 16:44:46 by guribeir          #+#    #+#             */
/*   Updated: 2022/07/21 03:26:17 by guribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	exit_hook(t_fractol *fr)
{
	mlx_destroy_window(fr->mlx, fr->win);
	fr->win = NULL;
	return (0);
}

void	zooming(t_fractol *fr, double zoom)
{
	double	middle_r;
	double	middle_i;

	middle_r = fr->min_r - fr->max_r;
	middle_i = fr->max_i - fr->min_i;
	fr->max_r = fr->max_r + (middle_r - zoom * middle_r) / 2;
	fr->min_r = fr->max_r + zoom * middle_r;
	fr->min_i = fr->min_i + (middle_i - zoom * middle_i) / 2;
	fr->max_i = fr->min_i + zoom * middle_i;
}

void	moving(t_fractol *fr, double distance, char where)
{
	double	middle_r;
	double	middle_i;

	middle_r = fr->max_r - fr->min_r;
	middle_i = fr->max_i - fr->min_i;
	if (where == 'r')
	{
		fr->min_r += middle_r * distance;
		fr->max_r += middle_r * distance;
	}
	else if (where == 'l')
	{
		fr->min_r -= middle_r * distance;
		fr->max_r -= middle_r * distance;
	}
	else if (where == 'u')
	{
		fr->min_i -= middle_i * distance;
		fr->max_i -= middle_i * distance;
	}
	else if (where == 'd')
	{
		fr->min_i += middle_i * distance;
		fr->max_i += middle_i * distance;
	}
}

int	mouse_hook(int keycode, int x, int y, t_fractol *fr)
{
	if (keycode == 4)
	{
		zooming(fr, 0.9);
		x -= WIDTH / 2;
		y -= HEIGHT / 2;
		if (x < 0)
			moving(fr, (double)x * -1 / WIDTH, 'l');
		else if (x > 0)
			moving(fr, (double)x / WIDTH, 'r');
		if (y < 0)
			moving(fr, (double)y * -1 / HEIGHT, 'u');
		else if (y > 0)
			moving(fr, (double)y / HEIGHT, 'd');
	}
	else if (keycode == 5)
		zooming(fr, 1.11);
	return (0);
}
