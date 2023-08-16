/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_map_walled.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yutoendo <yutoendo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 17:11:49 by yutoendo          #+#    #+#             */
/*   Updated: 2023/08/02 20:13:33 by yutoendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static bool is_map_vertically_walled(char **map)
{
    // この関数ではマップの上下が壁で囲まれているか確認
    size_t wall_len;
    size_t map_len;
    size_t i;
    
    wall_len = ft_strlen(map[0]);
    i = 0;
    while (i < wall_len)
    {
        if (map[0][i] != WALL)
        {
            return (false);
        }
        i++;
    }
    i = 0;
    map_len = get_map_len(map);
    while (i < wall_len)
    {
        if (map[map_len-1][i] != WALL)
        {
            return (false);
        }
        i++;
    }
    return (true);
}

static bool is_map_horizontally_walled(char **map)
{
    // この関数ではマップの左右が壁で囲まれているか確認
    size_t wall_len;
    size_t map_len;
    size_t i;
    
    wall_len = ft_strlen(map[0]);
    map_len = get_map_len(map);
    i = 0;
    while (i < map_len)
    {
        if (map[i][0] != WALL || map[i][wall_len-1] != WALL)
        {
            return (false);
        }
        i++;
    }
    return (true);
}
void is_map_walled(char **map)
{
    // この関数ではマップが壁に囲まれているか確認
    // 囲われていなかったらエラーを返し、イグジット
    if (is_map_vertically_walled(map) == false || is_map_horizontally_walled(map) == false)
    {
        free_2d_array(map);
        perror("Error\nMap is not walled\n");
        exit(EXIT_FAILURE);
    }
}