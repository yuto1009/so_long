/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuendo <yuendo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 18:31:21 by yuendo            #+#    #+#             */
/*   Updated: 2023/09/09 18:47:45 by yuendo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static void	render_elements(t_data *game_data, int col, int row)
{
	if (game_data->map.map[col][row] == WALL)
		mlx_put_image_to_window(game_data->mlx, game_data->win,
			game_data->wall.img, row * game_data->wall.cordinate.x, col
			* game_data->wall.cordinate.y);
	if (game_data->map.map[col][row] == COLLECTIBLE)
		mlx_put_image_to_window(game_data->mlx, game_data->win,
			game_data->collectible.img, row
			* game_data->collectible.cordinate.x, col
			* game_data->collectible.cordinate.y);
	if (game_data->map.map[col][row] == EXIT)
		mlx_put_image_to_window(game_data->mlx, game_data->win,
			game_data->exit.img, row * game_data->exit.cordinate.x, col
			* game_data->exit.cordinate.y);
	if (game_data->map.map[col][row] == PLAYER)
	{
		game_data->map.player_x = col;
		game_data->map.player_y = row;
		mlx_put_image_to_window(game_data->mlx, game_data->win,
			game_data->player.img, row * game_data->player.cordinate.x, col
			* game_data->player.cordinate.y);
	}
	if (game_data->map.map[col][row] == EMPTY)
		mlx_put_image_to_window(game_data->mlx, game_data->win,
			game_data->empty.img, row * game_data->empty.cordinate.x, col
			* game_data->empty.cordinate.y);
}

static void	render_movements_count(t_data *game_data)
{
	char	*move_num_str;
	char	*move_str;

	move_num_str = ft_itoa(game_data->move_count);
	if (move_num_str == NULL)
	{
		error_exit(MALLOC_ERROR);
	}
	move_str = ft_strjoin(MOVEMENTS, move_num_str);
	if (move_str == NULL)
	{
		error_exit(MALLOC_ERROR);
	}
	mlx_string_put(game_data->mlx, game_data->win, 10, 10, MOVEMENT_COLOR,
		move_str);
	ft_printf("%s\n", move_str);
	free(move_num_str);
	free(move_str);
}

void	render_map(t_data *game_data)
{
	int	col;
	int	row;

	col = 0;
	while (col < game_data->map_height)
	{
		row = 0;
		while (row < game_data->map_width)
		{
			render_elements(game_data, col, row);
			row++;
		}
		col++;
	}
	render_movements_count(game_data);
}
