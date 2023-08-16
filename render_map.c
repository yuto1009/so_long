/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuendo <yuendo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 19:48:30 by yuendo            #+#    #+#             */
/*   Updated: 2023/08/06 03:40:41 by yuendo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void render_elements(t_data *game_data, int col, int row)

{
    if (game_data->map.map[col][row] == WALL)
        mlx_put_image_to_window(game_data->mlx, game_data->win, game_data->wall.img, row * game_data->wall.x, col * game_data->wall.y);
    if (game_data->map.map[col][row] == COLLECTIBLE)
        mlx_put_image_to_window(game_data->mlx, game_data->win, game_data->collectible.img, row * game_data->collectible.x, col * game_data->collectible.y);
    if (game_data->map.map[col][row] == EXIT)
        mlx_put_image_to_window(game_data->mlx, game_data->win, game_data->exit.img, row * game_data->exit.x, col * game_data->exit.y);
    if (game_data->map.map[col][row] == PLAYER)
    {
        game_data->map.player_x = col;
        game_data->map.player_y = row;
        mlx_put_image_to_window(game_data->mlx, game_data->win, game_data->player.img, row * game_data->player.x, col * game_data->player.y);
    }    
    if (game_data->map.map[col][row] == EMPTY)
        mlx_put_image_to_window(game_data->mlx, game_data->win, game_data->empty.img, row * game_data->empty.x, col * game_data->empty.y);
    if(game_data->map.map[col][row] == DAMAGE)
        mlx_put_image_to_window(game_data->mlx, game_data->win, game_data->damage.img, row * game_data->damage.x, col * game_data->damage.y);
}

void render_map(t_data *game_data)
{
    int col;
    int row;

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
}
