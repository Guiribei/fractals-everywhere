/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guribeir <guribeir@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 01:20:04 by guribeir          #+#    #+#             */
/*   Updated: 2022/07/15 16:38:30 by guribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# define WINDOW_WIDTH 500
# define WINDOW_HEIGHT 500
# define MLX_ERROR 1

# include <mlx.h>
#include <X11/keysym.h>
#include <X11/X.h>
# include <stdlib.h>
# include <unistd.h>
# include "../libft/libft.h"

typedef struct	s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

typedef	struct	s_img {
void	*mlx_img;
char	*addr;
int		bpp;
int		line_len;
int		endian;
}				t_img;

int		render(t_vars	*vars);
void	img_pix_put(t_img *img, int x, int y, int color);
int		close_window(int keycode, t_vars *vars);

#endif