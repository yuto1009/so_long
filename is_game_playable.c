/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_game_playable.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuendo <yuendo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 13:44:52 by yuendo            #+#    #+#             */
/*   Updated: 2023/08/19 18:10:54 by yuendo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static t_point find_element_cordinates(t_data *game_data, char element)
{
    t_point cordinates;
    size_t i;
    size_t j;
    
    i = 0;
    j = 0;
    while (i < game_data->map_height)
    {
        while (j < game_data->map_width)
        {
            if (game_data->map.map[i][j] == element)
            {
                cordinates.y = i;
                cordinates.x = j;
                return cordinates;
            }
            j++;
        }
        i++;
    }
}

static bool is_goal_reachable(t_data *game_data, t_point current, t_point exit, bool visited[][])
{
    int delta_x[] = {1, 0, -1, 0};
    int delta_y[] = {0, 1, 0, -1};
    int next_x;
    int next_y;
    int i;
    
    if (current.x == exit.x && current.y == exit.y )
    {
        return true;
    }
    i = 0;
    while (i < NEIGHBORS)
    {
        next_x = current.x + delta_x[i];
        next_y = current.y + delta_y[i];
        if (next_x <= 0 || next_x >= game_data->map_width || next_y <= 0 || next_y >= game_data->map_height)
        {
            continue;
        }
        
    }
}

void is_game_playable(t_data *game_data)
{
    t_point current;
    t_point exit;
    bool visited[game_data->map_height][game_data->map_width];
    
    current = find_element_cordinates(game_data, PLAYER);
    exit = find_element_cordinates(game_data, EXIT);
    ft_memset(visited, false, sizeof(visited));
    
    
}