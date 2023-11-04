/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yutoendo <yutoendo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 14:54:20 by yutoendo          #+#    #+#             */
/*   Updated: 2023/11/04 17:26:19 by yutoendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

size_t get_map_len(char **map)
{   
    size_t i;
    
    i = 0;
    while (map[i] != NULL)
    {
        i++;
    }
    return (i);
}

int count_elements(char **map, char c)
{
    const size_t map_len = get_map_len(map);
    size_t i;
    size_t j;
    int count;
    
    i = 0;
    count = 0;
    while (i < map_len)
    {
        j = 0;
        while (map[i][j] != '\0')
        {
            if (map[i][j] == c)
            {
                count++;
            }
            j++;
        }
        i++;
    }
    return (count);
}


void error_exit(int error_num)
{
    if(error_num == MALLOC_ERROR)
        ft_printf("\x1b[31mError\nMalloc Error\n\x1b[0m");
    else if (error_num == EMPTY_MAP)
        ft_printf("\x1b[31mError\nEmpty map\n\x1b[0m");
    else if (error_num == INVALID_ARGS)
        ft_printf("\x1b[31mError\nInvalid arguments\n\x1b[0m");
    else if (error_num == MAP_NOT_FOUND)
         ft_printf("\x1b[31mError\nMap not found\n\x1b[0m");
    else if (error_num == INVALID_ELEMENTS)
        ft_printf("\x1b[31mError\nInvalid elements\n\x1b[0m");
    else if(error_num == INVALID_MAP_SHAPE)
        ft_printf("\x1b[31mError\nMap width is invalid\n\x1b[0m");
    else if (error_num == MAP_NOT_WALLED)
        ft_printf("\x1b[31mError\nMap is not walled\n\x1b[0m");
    else if (error_num == MAP_UNPLAYABLE)
        ft_printf("\x1b[31mError\nMap is unplayable\n\x1b[0m");
    exit(EXIT_FAILURE);  
}