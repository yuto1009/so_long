/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_map_walled.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yutoendo <yutoendo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 17:11:49 by yutoendo          #+#    #+#             */
/*   Updated: 2023/11/04 17:25:51 by yutoendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static bool is_map_vertically_walled(char **map)
{
    const size_t wall_len = ft_strlen(map[0]);
    const size_t map_len = get_map_len(map);
    size_t i;
    
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
    const size_t wall_len = ft_strlen(map[0]);
    const size_t map_len = get_map_len(map);
    size_t i;
    
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
    if (is_map_vertically_walled(map) == false || is_map_horizontally_walled(map) == false)
    {
        error_exit(MAP_NOT_WALLED);
    }
}