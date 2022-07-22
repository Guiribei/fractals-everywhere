NAME = fractol
PATH_SRC = ./sources/
PATH_OBJ = ./objects/

SRC =	$(addprefix $(PATH_SRCS),\
		main.c \
		init.c \
		mandelbrot.c \
		julia.c \
		tricorn.c \
		keyhooks.c \
		mousehooks.c \
		atof.c \
		colorselect.c \
		colors.c)

OBJ =	$(SRC:%.c=$(PATH_OBJ)%.o)

INCLUDES = -I ./includes/
LIBFT = ./libft/libft.a
MLXFLAGS = -lmlx -lXext -lX11 -lm -lz
FLAGS = -Wall -Wextra -Werror

all: 		$(NAME)

$(NAME):	$(LIBFT) $(OBJ)
	cc $(FLAGS) $(OBJ) $(LIBFT) $(MLXFLAGS) -o $(NAME)

$(LIBFT):
	@make all -C ./libft/

$(PATH_OBJ)%.o: $(PATH_SRC)%.c
	mkdir -p $(PATH_OBJ)
	cc $(FLAGS) $(INCLUDES) -O3 -c $< -o $@
	@echo "\033[1;92m[SUCCESS] $@ Objects creation done!\033[0m"

clean:
	@make clean -C ./libft/
	@rm -rf $(PATH_OBJ)
	@echo "\33[1;93m[SUCCESS] Objects removal done!\33[0m"

fclean: clean
	@rm -f $(NAME)
	@make fclean -C ./libft/
	@echo "\033[1;93m[SUCCESS] Library removal done!\33[0m"

re: fclean all

.PHONY: all clean fclean re