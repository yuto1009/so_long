/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_map_shape.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yutoendo <yutoendo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 17:13:46 by yutoendo          #+#    #+#             */
/*   Updated: 2023/09/05 17:21:27 by yutoendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void is_valid_map_shape(char **map)
{
    const size_t first_line_len = ft_strlen(map[0]);
    size_t i;
    
    i = 0;
    while (map[i]!= NULL)
    {
        if (ft_strlen(map[i]) != first_line_len)
        {   
            error_exit(INVALID_MAP_SHAPE);
        }
        i++;
    }
}