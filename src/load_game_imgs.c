/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_game_imgs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuendo <yuendo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 18:28:52 by yuendo            #+#    #+#             */
/*   Updated: 2023/11/10 12:03:24 by yuendo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static t_img	load_img(t_data *game_data, char *path)
{
	t_img	element;

	element.img = mlx_xpm_file_to_image(game_data->mlx, path,
			&element.cordinate.x, &element.cordinate.y);
	return (element);
}

void	load_game_imgs(t_data *game_data)
{
	game_data->player = load_img(game_data, PLAYER_PATH);
	game_data->collectible = load_img(game_data, COINS_PATH);
	game_data->wall = load_img(game_data, BACKGROUND_PATH);
	game_data->exit = load_img(game_data, EXIT_PATH);
	game_data->empty = load_img(game_data, EMPTY_PATH);
}
