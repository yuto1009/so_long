/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yutoendo <yutoendo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 17:23:18 by yuendo            #+#    #+#             */
/*   Updated: 2023/11/16 22:48:53 by yutoendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	main(int argc, char *argv[])
{
	t_data	*game_data;
	
	game_data = initialize_game_data();
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
