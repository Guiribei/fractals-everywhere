/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guribeir <guribeir@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 14:48:25 by guribeir          #+#    #+#             */
/*   Updated: 2022/07/17 17:43:06 by guribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	handle_keypress(int keysym, t_vars *va)
{
	if (keysym == XK_Escape)
	{
		mlx_destroy_window(va->mlx, va->win);
		va->win = NULL;
	}
	return (0);
}

int	exit_hook(t_vars *va)
{
	mlx_destroy_window(va->mlx, va->win);
	va->win = NULL;
	return (0);
}
