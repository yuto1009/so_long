/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yutoendo <yutoendo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 14:17:51 by yutoendo          #+#    #+#             */
/*   Updated: 2023/08/12 12:53:50 by yutoendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

__attribute__((destructor)) // leakがないかチェック
static void destructor() {
    system("leaks -q a.out");
}

int	closes(int keycode, t_data *vars)
{
    if(keycode)
    ;
	mlx_destroy_window(vars->mlx, vars->win);
	return (0);
}

int main(int argc, char *argv[])
{   
    t_data *game_data;  
    
    game_data = (t_data *)ft_calloc(1, sizeof(t_data));
    if(game_data == NULL)
    {
        perror("Error\nMalloc Error\n");
        exit(EXIT_FAILURE);
    }
    is_valid_input(argc, argv); 
    get_map(argv[MAP_ARGC], game_data);
    
    // ここら辺ではmlxにマップの情報を渡すコードを書くはず
    // printf("最初の１行は壁の筈%s\n", game_data->map[0]);    // DEBUG
    // printf("最後の１行も壁の筈%s\n", game_data->map[(get_map_len(game_data->map) -1)]);    // DEBUG
    // free_2d_array(game_data->map);  // DEBUG
    // free(game_data);
    // return 0;
    
    
    game_data->mlx = mlx_init();
    game_data->win = mlx_new_window(game_data->mlx, game_data->map_width * TILE_SIZE, game_data->map_height * TILE_SIZE, "so_long");
    get_game_imgs(game_data);
    render_map(game_data);
    mlx_key_hook(game_data->win, key_hook, game_data);
    mlx_hook(game_data->win, DELETE_EVENT, DELETE_MASK, closes, game_data);
    
	mlx_loop(game_data->mlx);
    return 0;
}