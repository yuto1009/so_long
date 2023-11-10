/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_keyinput.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuendo <yuendo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 18:39:44 by yuendo            #+#    #+#             */
/*   Updated: 2023/11/10 12:03:30 by yuendo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	closes(t_data *game_data)
{
	mlx_destroy_window(game_data->mlx, game_data->win);
	exit(EXIT_SUCCESS);
	return (0);
}

static void	exit_game(t_data *game_data)
{
	mlx_destroy_window(game_data->mlx, game_data->win);
	exit(EXIT_SUCCESS);
}

static void	move_player(t_data *game_data, int next_x, int next_y)
{
	int	last_x;
	int	last_y;

	last_x = game_data->map.player_x;
	last_y = game_data->map.player_y;
	if (game_data->map.map[next_x][next_y] == EXIT && game_data->coin_num == 0)
		exit_game(game_data);
	else if (game_data->map.map[next_x][next_y] == EMPTY ||
				game_data->map.map[next_x][next_y] == COLLECTIBLE)
	{
		if (game_data->map.map[next_x][next_y] == COLLECTIBLE)
		{
			game_data->coin_num--;
		}
		game_data->map.map[last_x][last_y] = EMPTY;
		game_data->map.map[next_x][next_y] = PLAYER;
		game_data->map.player_x = next_x;
		game_data->map.player_y = next_y;
		game_data->move_count++;
		render_map(game_data);
	}
}

int	key_hook(int keycode, t_data *game_data)
{
	int	player_nowx;
	int	player_nowy;

	player_nowx = game_data->map.player_x;
	player_nowy = game_data->map.player_y;
	if (keycode == W)
		move_player(game_data, player_nowx - 1, player_nowy);
	if (keycode == A)
		move_player(game_data, player_nowx, player_nowy - 1);
	if (keycode == S)
		move_player(game_data, player_nowx + 1, player_nowy);
	if (keycode == D)
		move_player(game_data, player_nowx, player_nowy + 1);
	if (keycode == ESC)
		exit_game(game_data);
	return (0);
}
