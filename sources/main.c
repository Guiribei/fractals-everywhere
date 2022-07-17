/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guribeir <guribeir@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 16:44:15 by guribeir          #+#    #+#             */
/*   Updated: 2022/07/17 17:57:23 by guribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	img_pix_put(t_img *im, int x, int y, int color)
{
	char	*pixel;

	pixel = im->add + (y * im->ll + x * (im->bpp / 8));
	*(int *)pixel = color;
}

int	main(void)
{
	t_vars	va;

	va.mlx = mlx_init();
	if (va.mlx == NULL)
		return (MLX_ERROR);
	va.win = mlx_new_window(va.mlx, WIDTH, HEIGHT, "Fractal");
	if (va.win == NULL)
	{
		free(va.win);
		return (MLX_ERROR);
	}
	va.im.img = mlx_new_image(va.mlx, WIDTH, HEIGHT);
	va.im.add = mlx_get_data_addr(va.im.img, &va.im.bpp, &va.im.ll, &va.im.en);
	mlx_loop_hook(va.mlx, &render, &va);
	mlx_hook(va.win, KeyPress, KeyPressMask, &handle_keypress, &va);
	mlx_hook(va.win, 17, 0, exit_hook, &va);
	mlx_loop(va.mlx);
	mlx_destroy_image(va.mlx, va.im.img);
	mlx_destroy_display(va.mlx);
	free(va.mlx);
	exit(0);
	return (0);
}
