/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_map_elements.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yutoendo <yutoendo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 17:07:11 by yutoendo          #+#    #+#             */
/*   Updated: 2023/11/04 17:26:02 by yutoendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

// static bool is_element_on_map(char **map, char c)
// {
//     size_t map_len;
//     size_t i;
//     bool isin;
    
//     map_len = get_map_len(map);
//     i = 0;
//     isin = false;
//     while (i < map_len)
//     {
//         if (ft_strchr(map[i], c) != NULL)
//         {
//             isin = true;
//         }
//         i++;
//     }
//     return (isin);
// }

static bool check_essential_elements(char **map)
{
    const size_t map_len = get_map_len(map);
    size_t i;

    i = 0;
    while (i < map_len)
    {
        if (count_elements(map, COLLECTIBLE) < true || count_elements(map, EXIT) != true || 
        count_elements(map, PLAYER) != true)
        {
            return (false);
        }
        i++;
    }
    return (true);
}

// static size_t count_unique_elements(char **map, char c)
// {
//     size_t map_len;
//     size_t i;
//     size_t j;
//     size_t count;
    
//     map_len = get_map_len(map);
//     i = 0;
//     count = 0;
//     while (i < map_len)
//     {
//         j = 0;
//         while(map[i][j] != '\0')
//         {
//             if (map[i][j] == c)
//                 count++;
//             j++;
//         }
//         i++;
//     }
//     return (count);
// }

// static void check_unique_elements(char **map)
// {
//     if (count_unique_elements(map, PLAYER) != UNIQUE || count_unique_elements(map, EXIT) != UNIQUE)
//     {
//         ft_printf("\x1b[31mError\nPlayer and Exit must be unique\n\x1b[0m");
//         exit(EXIT_FAILURE);
//     }
// }

static bool is_known_elements(char **map)
{
    const size_t map_len = get_map_len(map);
    size_t i;

    i = 0;
    while (i < map_len)
    {
        const char *trimmed = ft_strtrim(map[i], VALID_ELEMENTS);
        if (ft_strlen(trimmed) != 0)
        {
            free((void *)trimmed);
            return (false);
        }
        free((void *)trimmed);
        i++;
    }
    return true;
}

void is_valid_map_elements(char **map)
{
    if (check_essential_elements(map) == false || is_known_elements(map) == false)
    {
        error_exit(INVALID_ELEMENTS);
    }
}