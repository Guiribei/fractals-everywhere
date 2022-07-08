/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guribeir <guribeir@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 01:20:04 by guribeir          #+#    #+#             */
/*   Updated: 2022/07/08 19:40:18 by guribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# define ESC 0xff1b

# include <mlx.h>
# include <stdlib.h>
# include <unistd.h>
# include "../libft/libft.h"

typedef struct	s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

typedef	struct	s_data {
void	*img;
char	*addr;
int		bits_per_pixel;
int		line_length;
int		endian;
}				t_data;

void	rainbow(void	*);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int		close_window(int keycode, t_vars *vars);

#endif