/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_map_elements.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuendo <yuendo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 17:07:11 by yutoendo          #+#    #+#             */
/*   Updated: 2023/08/05 23:39:57 by yuendo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static bool is_valid_map_elements_char(char **map, char c)
{
    // この関数ではマップに入っている文字が正しいか確認
    // E (出口)
    // C (回収アイテム)
    // P (スタート)
    //   それ以外の文字が入っていたらエラー吐いてイグジット
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
    // この関数ではマップに必須要素が入っているか確認
    // 必須要素は
    // E (出口)
    // C (回収アイテム)
    // P (スタート)
    //   空白も弾く
    // 上記何かを満たしていなかったらエラー吐いてイグジット
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