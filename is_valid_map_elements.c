/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_map_elements.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuendo <yuendo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 17:07:11 by yutoendo          #+#    #+#             */
/*   Updated: 2023/08/23 19:19:46 by yuendo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static bool is_element_on_map(char **map, char c)
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

static void check_minimum_elements(char **map)
{
    size_t map_len;
    size_t i;

    map_len = get_map_len(map);
    i = 0;
    while (i < map_len - 0)
    {
        if ( is_element_on_map(map, COLLECTIBLE) == false || is_element_on_map(map, EXIT) == false || 
        is_element_on_map(map, PLAYER) == false)
        {
            free_2d_array(map);
            ft_printf("\x1b[31mError\nMap is missing elements\n\x1b[0m");
            exit(EXIT_FAILURE);
        }
        i++;
    }
}

static size_t count_unique_elements(char **map, char c)
{
    size_t map_len;
    size_t i;
    size_t j;
    size_t count;
    
    map_len = get_map_len(map);
    i = 0;
    count = 0;
    while (i < map_len)
    {
        j = 0;
        while(map[i][j] != '\0')
        {
            if (map[i][j] == c)
                count++;
            j++;
        }
        i++;
    }
    return (count);
}

static void check_unique_elements(char **map)
{
    if (count_unique_elements(map, PLAYER) != UNIQUE || count_unique_elements(map, EXIT) != UNIQUE)
    {
        free_2d_array(map);
        ft_printf("\x1b[31mError\nPlayer and Exit must be unique\n\x1b[0m");
        exit(EXIT_FAILURE);
    }
}

void is_valid_map_elements(char **map)
{
    check_minimum_elements(map);
    check_unique_elements(map);
}