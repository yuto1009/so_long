NAME = so_long

CC = cc

CFLAGS = -Wall -Wextra -Werror -Imlx

MLX_PATH = mlx/

MLX_LIB = $(MLX_PATH)libmlx.a

SRCS = so_long.c \
		is_valid_input.c \
		get_map.c \
		is_valid_map.c \
		is_valid_map_shape.c \
		is_map_walled.c \
		is_valid_map_elements.c \
		render_map.c \
		process_keyboard_input.c \
		is_game_playable.c \
		get_next_line/get_next_line.c \
		get_next_line/get_next_line_utils.c \


OBJS = $(SRCS:.c=.o)

LIBFT_PATH = ./libft

LIBFT = $(LIBFT_PATH)/libft.a

FT_PRINTF_PATH = ./ft_printf

FT_PRINTF = $(FT_PRINTF_PATH)/libftprintf.a

MLX_PATH = ./mlx

MLX = $(MLX_PATH)/libmlx.a

all:	$(LIBFT) $(FT_PRINTF) $(MLX) $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	$(MAKE) -C $(LIBFT_PATH)

$(FT_PRINTF):
	$(MAKE) -C $(FT_PRINTF_PATH)

$(MLX):
	$(MAKE) -C $(MLX_PATH)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT) $(FT_PRINTF) $(MLX) -Lmlx -lmlx -framework OpenGL -framework AppKit mlx/libmlx.a

clean:
	rm -f $(OBJS)
	$(MAKE) -C $(LIBFT_PATH) clean
	$(MAKE) -C $(FT_PRINTF_PATH) clean
	$(MAKE) -C $(MLX_PATH) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_PATH) fclean
	$(MAKE) -C $(FT_PRINTF_PATH) fclean

re: fclean all

.PHONY: all clean fclean re