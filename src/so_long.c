/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yutoendo <yutoendo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 14:17:51 by yutoendo          #+#    #+#             */
/*   Updated: 2023/11/04 17:26:22 by yutoendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static int closes(t_data *game_data)
{
	mlx_destroy_window(game_data->mlx, game_data->win);
    exit(EXIT_SUCCESS);
	return (0);
}

int main(int argc, char *argv[])
{   
    t_data *game_data;

    game_data = (t_data *)ft_calloc(1, sizeof(t_data));
    if(game_data == NULL)
    {
        error_exit(MALLOC_ERROR);
    }
    is_valid_input(argc, argv); 
    get_map(argv[MAP_ARGC], game_data);
    game_data->mlx = mlx_init();
    game_data->win = mlx_new_window(game_data->mlx, game_data->map_width * TILE_SIZE, game_data->map_height * TILE_SIZE, "so_long");
    get_game_imgs(game_data);
    render_map(game_data);
    mlx_key_hook(game_data->win, key_hook, game_data);
    mlx_hook(game_data->win, DELETE_EVENT, DELETE_MASK, closes, game_data);
	mlx_loop(game_data->mlx);
    return 0;
}