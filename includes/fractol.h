/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guribeir <guribeir@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 01:20:04 by guribeir          #+#    #+#             */
/*   Updated: 2022/07/21 13:57:40 by guribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# define WIDTH 900
# define HEIGHT 900
# define MLX_ERROR 1
# define MAX_ITERATIONS 80

# include <mlx.h>
# include <X11/keysym.h>
# include <X11/X.h>
# include <stdlib.h>
# include <unistd.h>
# include "../libft/libft.h"

typedef struct s_aux
{
	double	middle_r;
	double	middle_i;
}				t_aux;

typedef struct s_img
{
	void	*img;
	char	*add;
	int		bpp;
	int		ll;
	int		en;
}				t_img;

typedef struct s_fractol
{
	void	*mlx;
	void	*win;
	double	min_r;
	double	max_r;
	double	min_i;
	double	max_i;
	double	kr;
	double	ki;
	int		x;
	int		y;
	int		set;
	int		color;
	t_img	im;
}				t_fractol;

int		mouse_hook(int button, int x, int y, t_fractol *fr);
void	arrows(int keysym, t_fractol *fr);
int		render(t_fractol *fr);
void	img_pix_put(t_fractol *fr, int x, int y, int color);
void	draw_fractal(t_fractol *fr);
int		mandelbrot(double cr, double ci);
int		julia(t_fractol *fr, double zr, double zi);
int		tricorn(double cr, double ci);
int		close_window(int keycode, t_fractol *fr);
int		handle_keypress(int keysym, t_fractol *fr);
int		exit_hook(t_fractol *fr);
int		skip_space_sign(char *str, int *is_neg);
double	ft_atof(char *str);
void	color_select(t_fractol *fr, int n);
void	color_1(t_fractol *fr, int n);
void	color_2(t_fractol *fr, int n);
void	color_3(t_fractol *fr, int n);
void	color_4(t_fractol *fr, int n);
void	color_5(t_fractol *fr, int n);

#endif