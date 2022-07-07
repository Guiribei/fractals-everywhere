#include <mlx.h>
#include "../libft/libft.h"

typedef	struct	s_data {
void	*img;
char	*addr;
int		bits_per_pixel;
int		line_length;
int		endian;
}				t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	main(void)
{
	void	*mlx_ptr;
	void	*mlx_win;
	t_data	img;
	int		i;
	int		j;

	mlx_ptr = mlx_init();
	mlx_win = mlx_new_window(mlx_ptr, 500, 500, "Hello World!");
	img.img = mlx_new_image(mlx_ptr, 500, 500);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	//violeta
	i = 250;
	j = 250;
	while (i < 500 && j < 500)
	{
		my_mlx_pixel_put(&img, i, j, 0x00FF0000);
		i++;
		j++;
	}
	i = 250;
	j = 250;
	while (i > 0 && j < 500)
	{
		my_mlx_pixel_put(&img, i, j, 0x00FF00FF);
		i--;
		j++;
	}

	//azul
	i = 249;
	j = 251;
	while (i < 500 && j < 500)
	{
		my_mlx_pixel_put(&img, i, j, 0x00FF8C00);
		i++;
		j++;
	}
	i = 249;
	j = 249;
	while (i > 0 && j < 500)
	{
		my_mlx_pixel_put(&img, i, j, 0x000000FF);
		i--;
		j++;
	}
	//verde
	i = 248;
	j = 252;
	while (i < 500 && j < 500)
	{
		my_mlx_pixel_put(&img, i, j, 0x00FFFF00);
		i++;
		j++;
	}
	i = 248;
	j = 248;
	while (i > 0 && j < 500)
	{
		my_mlx_pixel_put(&img, i, j, 0x0000FF00);
		i--;
		j++;
	}
	//amarelo
	i = 247;
	j = 253;
	while (i < 500 && j < 500)
	{
		my_mlx_pixel_put(&img, i, j, 0x0000FF00);
		i++;
		j++;
	}
	i = 247;
	j = 247;
	while (i > 0 && j < 500)
	{
		my_mlx_pixel_put(&img, i, j, 0x00FFFF00);
		i--;
		j++;
	}
	//laranja
	i = 246;
	j = 254;
	while (i < 500 && j < 500)
	{
		my_mlx_pixel_put(&img, i, j, 0x000000FF);
		i++;
		j++;
	}
	i = 246;
	j = 246;
	while (i > 0 && j < 500)
	{
		my_mlx_pixel_put(&img, i, j, 0x00FF8C00);
		i--;
		j++;
	}
		//vermelho
	i = 245;
	j = 255;
	while (i < 500 && j < 500)
	{
		my_mlx_pixel_put(&img, i, j, 0x00FF00FF);
		i++;
		j++;
	}
	i = 245;
	j = 245;
	while (i > 0 && j < 500)
	{
		my_mlx_pixel_put(&img, i, j, 0x00FF0000);
		i--;
		j++;
	}
	mlx_put_image_to_window(mlx_ptr, mlx_win, img.img, 0, 0);
	mlx_loop(mlx_ptr);
	return (0);
}