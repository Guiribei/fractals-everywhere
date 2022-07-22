/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guribeir <guribeir@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 16:44:15 by guribeir          #+#    #+#             */
/*   Updated: 2022/07/22 23:13:24 by guribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "../libft/libft.h"

void	set_values(t_fractol *fr, char **argv)
{
	double	kr;
	double	ki;

	kr = 0;
	ki = 0;
	if (ft_strcmp(argv[1], "julia") == 0)
	{
		kr = ft_atof(argv[2]);
		ki = ft_atof(argv[3]);
	}
	fr->im.img = mlx_new_image(fr->mlx, WIDTH, HEIGHT);
	fr->min_r = -2.0;
	fr->max_r = 1.0;
	fr->min_i = -1.5;
	fr->max_i = fr->min_i + (fr->max_r - fr->min_r) * HEIGHT / WIDTH;
	fr->kr = kr;
	fr->ki = ki;
	fr->color = 9;
}

int	msg(void)
{
	ft_putstr_fd("\n", 1);
	ft_putstr_fd("=====================================================\n", 1);
	ft_putstr_fd("Invalid argument\n", 1);
	ft_putstr_fd("-----------------------------------------------------\n", 1);
	ft_putstr_fd("Please follow this example:\n", 1);
	ft_putstr_fd("\n", 1);
	ft_putstr_fd("./fractol [mandelbrot/julia/tricorn] ([kr][ki] julia)\n", 1);
	ft_putstr_fd("\n", 1);
	ft_putstr_fd("Press spacebar to change fractal's colors\n", 1);
	ft_putstr_fd("\n", 1);
	ft_putstr_fd("=====================================================\n", 1);
	ft_putstr_fd("\n", 1);
	return (1);
}

int	validation(t_fractol *fr, int argc, char **argv)
{
	if (argc < 2)
		return (1);
	else if ((ft_strcmp(argv[1], "julia")) == 0)
	{
		if (argc < 4)
			return (1);
		if (ft_atof(argv[2]) < -2 || ft_atof(argv[2]) > 2)
			return (1);
		if (ft_atof(argv[3]) > 2 || ft_atof(argv[2]) < -2)
			return (1);
		fr->set = 2;
	}
	else if ((ft_strcmp(argv[1], "tricorn")) == 0)
		fr->set = 3;
	else
	{
		if (ft_strcmp(argv[1], "mandelbrot") != 0)
			return (1);
		fr->set = 1;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_fractol	fr;

	if ((validation(&fr, argc, argv)) == 1)
		return (msg());
	fr.mlx = mlx_init();
	if (fr.mlx == NULL)
		return (MLX_ERROR);
	fr.win = mlx_new_window(fr.mlx, WIDTH, HEIGHT, "Fractal");
	if (fr.win == NULL)
	{
		free(fr.win);
		return (MLX_ERROR);
	}
	set_values(&fr, argv);
	fr.im.add = mlx_get_data_addr(fr.im.img, &fr.im.bpp, &fr.im.ll, &fr.im.en);
	mlx_loop_hook(fr.mlx, &render, &fr);
	mlx_hook(fr.win, KeyPress, KeyPressMask, &handle_keypress, &fr);
	mlx_hook(fr.win, 17, 0, exit_hook, &fr);
	mlx_mouse_hook(fr.win, mouse_hook, &fr);
	mlx_loop(fr.mlx);
	mlx_destroy_image(fr.mlx, fr.im.img);
	mlx_destroy_display(fr.mlx);
	free(fr.mlx);
	exit(0);
	return (0);
}
