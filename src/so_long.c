/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuendo <yuendo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 17:23:18 by yuendo            #+#    #+#             */
/*   Updated: 2023/11/10 12:03:40 by yuendo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	main(int argc, char *argv[])
{
	t_data	*game_data;

	game_data = (t_data *)ft_calloc(1, sizeof(t_data));
	if (game_data == NULL)
	{
		error_exit(MALLOC_ERROR);
	}
	is_valid_input(argc, argv);
	load_map(argv[MAP_ARGC], game_data);
	game_data->mlx = mlx_init();
	game_data->win = mlx_new_window(game_data->mlx, game_data->map_width
			* TILE_SIZE, game_data->map_height * TILE_SIZE, "so_long");
	load_game_imgs(game_data);
	render_map(game_data);
	mlx_key_hook(game_data->win, key_hook, game_data);
	mlx_hook(game_data->win, DELETE_EVENT, 1L << 17, closes, game_data);
	mlx_loop(game_data->mlx);
	return (0);
}
