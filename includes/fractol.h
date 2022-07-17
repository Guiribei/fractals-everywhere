/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guribeir <guribeir@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 01:20:04 by guribeir          #+#    #+#             */
/*   Updated: 2022/07/17 18:08:22 by guribeir         ###   ########.fr       */
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

typedef struct s_img
{
	void	*img;
	char	*add;
	int		bpp;
	int		ll;
	int		en;
}				t_img;

typedef struct s_vars
{
	void	*mlx;
	void	*win;
	t_img	im;
}				t_vars;

typedef struct s_rect
{
	int	x;
	int	y;
	int	width;
	int	height;
	int	color;
}				t_rect;

typedef struct s_fractol
{
	void	*mlx;
	void	*win;
	double	min_r;
	double	max_r;
	double	min_i;
	double	max_i;
}				t_fractol;

typedef struct s_coord
{
	int	x;
	int	y;
}				t_coord;

int		render(t_vars	*va);
int		render_rect(t_img *im, t_rect rect);
void	img_pix_put(t_img *im, int x, int y, int color);
int		close_window(int keycode, t_vars *va);
int		handle_keypress(int keysym, t_vars *va);
int		exit_hook(t_vars *va);

#endif