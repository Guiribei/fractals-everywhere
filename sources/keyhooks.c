/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhooks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guribeir <guribeir@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 14:48:25 by guribeir          #+#    #+#             */
/*   Updated: 2022/07/21 05:46:55 by guribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	handle_keypress(int keysym, t_fractol *fr)
{
	if (keysym == XK_Escape)
	{
		mlx_destroy_window(fr->mlx, fr->win);
		fr->win = NULL;
	}
	if (keysym == XK_space)
		fr->color++;
	arrows(keysym, fr);
	return (0);
}

void	arrows(int keysym, t_fractol *fr)
{
	t_aux	aux;

	aux.middle_r = fr->max_r - fr->min_r;
	aux.middle_i = fr->max_i - fr->min_i;
	if (keysym == XK_Left)
	{
		fr->min_r -= aux.middle_r * 0.15;
		fr->max_r -= aux.middle_r * 0.15;
	}
	if (keysym == XK_Right)
	{
		fr->min_r += aux.middle_r * 0.15;
		fr->max_r += aux.middle_r * 0.15;
	}
	if (keysym == XK_Up)
	{
		fr->min_i -= aux.middle_i * 0.15;
		fr->max_i -= aux.middle_i * 0.15;
	}
	if (keysym == XK_Down)
	{
		fr->min_i += aux.middle_i * 0.15;
		fr->max_i += aux.middle_i * 0.15;
	}
	return ;
}
