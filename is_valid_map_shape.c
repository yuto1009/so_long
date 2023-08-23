/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_map_shape.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuendo <yuendo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 17:13:46 by yutoendo          #+#    #+#             */
/*   Updated: 2023/08/23 16:11:31 by yuendo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void is_valid_map_shape(char **map)
{
    size_t first_line_len;
    size_t i;
    
    first_line_len = ft_strlen(map[0]);
    i = 0;
    while (map[i]!= NULL)
    {
        if (ft_strlen(map[i]) != first_line_len)
        {   
            free_2d_array(map);
            ft_printf("Error\nMap width is invalid\n");
            exit(EXIT_FAILURE);
        }
        i++;
    }
}