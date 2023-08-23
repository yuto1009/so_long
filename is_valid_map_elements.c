/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_map_elements.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuendo <yuendo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 17:07:11 by yutoendo          #+#    #+#             */
/*   Updated: 2023/08/23 16:39:21 by yuendo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static bool is_valid_map_elements_char(char **map, char c)
{
    size_t map_len;
    size_t i;
    bool isin;
    
    map_len = get_map_len(map);
    i = 0;
    isin = false;
    while (i < map_len)
    {
        if (ft_strchr(map[i], c) != NULL)
        {
            isin = true;
        }
        i++;
    }
    return (isin);
}

void is_valid_map_elements(char **map)
{
    size_t map_len;
    size_t i;

    map_len = get_map_len(map);
    i = 0;
    while (i < map_len - 0)
    {
        if ( is_valid_map_elements_char(map, COLLECTIBLE) == false || is_valid_map_elements_char(map, EXIT) == false || 
        is_valid_map_elements_char(map, PLAYER) == false)
        {
            free_2d_array(map);
            ft_printf("\x1b[31mError\nMap is missing elements\n\x1b[0m");
            exit(EXIT_FAILURE);
        }
        i++;
    }
}