NAME = so_long

CC = cc

CFLAGS = -Wall -Wextra -Werror -Imlx

SRCS = src/get_map.c src/is_game_playable.c src/is_map_walled.c src/is_valid_input.c\
		src/is_valid_map.c src/is_valid_map_elements.c src/is_valid_map_shape.c\
  		src/process_keyboard_input.c src/render_map.c src/so_long.c src/so_long_utils.c\
		get_next_line/get_next_line.c get_next_line/get_next_line_utils.c\

OBJS = $(SRCS:.c=.o)

LIBFTPRINTF_PATH = ./libftprintf

LIBFTPRINTF = $(LIBFTPRINTF_PATH)/libftprintf.a

MLX_PATH = mlx/

MLX = $(MLX_PATH)libmlx.a

all:	$(LIBFTPRINTF) $(MLX) $(NAME)

$(LIBFTPRINTF):
	@$(MAKE) -C $(LIBFTPRINTF_PATH)
	echo "Successfully compiled $(NAME)"

$(MLX):
	@$(MAKE) -C $(MLX_PATH)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFTPRINTF) $(MLX) -Lmlx -lmlx -framework OpenGL -framework AppKit mlx/libmlx.a

%.o : %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJS)
	@$(MAKE) -C $(LIBFTPRINTF_PATH) clean
	@$(MAKE) -C $(MLX_PATH) clean

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) -C $(LIBFTPRINTF_PATH) fclean

re: fclean all

.PHONY: all clean fclean re