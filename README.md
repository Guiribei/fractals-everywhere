# fractals-everywhere
My first graphical project at 42sp named fract-ol

In order to run that away from workspaces you should change the flags there on Makefile. The compilation flags would be -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz instead of mlx flags that are there.


Also you would probably need to donwload the linux version of mlx at https://github.com/42Paris/minilibx-linux


Since I did code it in a specific environment with minilibx. you'll have to set up these two little things (mencioned above) before running the Makefile. Once you're done with it, you can launch the program using some graphical desktop-sharing system like TightVNC to be able to see it.

Then you'll be able to visualize one of three fractals I've reproduced: Mandelbrot, Julia, or Tricorn. Have fun!
