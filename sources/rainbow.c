#include "fractol.h"

void	rainbow(void	*img)
{
	int	i;
	int	j;
//violeta
	i = 250;
	j = 250;
	while (i < 500 && j < 500)
	{
		my_mlx_pixel_put(img, i, j, 0x00FF0000);
		i++;
		j++;
	}
	i = 250;
	j = 250;
	while (i > 0 && j < 500)
	{
		my_mlx_pixel_put(img, i, j, 0x00FF00FF);
		i--;
		j++;
	}

	//azul
	i = 249;
	j = 251;
	while (i < 500 && j < 500)
	{
		my_mlx_pixel_put(img, i, j, 0x00FF8C00);
		i++;
		j++;
	}
	i = 249;
	j = 249;
	while (i > 0 && j < 500)
	{
		my_mlx_pixel_put(img, i, j, 0x000000FF);
		i--;
		j++;
	}
	//verde
	i = 248;
	j = 252;
	while (i < 500 && j < 500)
	{
		my_mlx_pixel_put(img, i, j, 0x00FFFF00);
		i++;
		j++;
	}
	i = 248;
	j = 248;
	while (i > 0 && j < 500)
	{
		my_mlx_pixel_put(img, i, j, 0x0000FF00);
		i--;
		j++;
	}
	//amarelo
	i = 247;
	j = 253;
	while (i < 500 && j < 500)
	{
		my_mlx_pixel_put(img, i, j, 0x0000FF00);
		i++;
		j++;
	}
	i = 247;
	j = 247;
	while (i > 0 && j < 500)
	{
		my_mlx_pixel_put(img, i, j, 0x00FFFF00);
		i--;
		j++;
	}
	//laranja
	i = 246;
	j = 254;
	while (i < 500 && j < 500)
	{
		my_mlx_pixel_put(img, i, j, 0x000000FF);
		i++;
		j++;
	}
	i = 246;
	j = 246;
	while (i > 0 && j < 500)
	{
		my_mlx_pixel_put(img, i, j, 0x00FF8C00);
		i--;
		j++;
	}
		//vermelho
	i = 245;
	j = 255;
	while (i < 500 && j < 500)
	{
		my_mlx_pixel_put(img, i, j, 0x00FF00FF);
		i++;
		j++;
	}
	i = 245;
	j = 245;
	while (i > 0 && j < 500)
	{
		my_mlx_pixel_put(img, i, j, 0x00FF0000);
		i--;
		j++;
	}
}