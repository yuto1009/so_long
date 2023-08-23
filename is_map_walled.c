/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_map_walled.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuendo <yuendo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 17:11:49 by yutoendo          #+#    #+#             */
/*   Updated: 2023/08/23 19:24:22 by yuendo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static bool is_map_vertically_walled(char **map)
{
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
    if (is_map_vertically_walled(map) == false || is_map_horizontally_walled(map) == false)
    {
        free_2d_array(map);
        ft_printf("Error\nMap is not walled\n");
        exit(EXIT_FAILURE);
    }
}