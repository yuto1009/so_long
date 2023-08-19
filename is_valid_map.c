/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuendo <yuendo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 17:01:37 by yutoendo          #+#    #+#             */
/*   Updated: 2023/08/19 15:08:06 by yuendo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "so_long.h"

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

void free_2d_array(char **str)
{
    int i;

    i = 0;
    while (str[i])
    {
        free(str[i]);
        i++;
    }
    free(str);
}

void is_valid_map(char **map)
{   
    is_valid_map_shape(map);    // マップの形は正しいか
    is_map_walled(map); // マップは壁に囲まれているか
    is_valid_map_elements(map); // 必要な要素を含んでいるか
    // is_game_playable(map);
}