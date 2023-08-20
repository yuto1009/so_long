/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_game_playable.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yutoendo <yutoendo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 13:44:52 by yuendo            #+#    #+#             */
/*   Updated: 2023/08/20 15:07:50 by yutoendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static t_point find_element_cordinates(t_data *game_data, char element)
{
    t_point cordinates;
    int i;
    int j;
    bool found;
    
    i = 0;
    j = 0;
    found = false;
    while (i < game_data->map_height)
    {
        while (j < game_data->map_width)
        {
            if (game_data->map.map[i][j] == element)
            {
                cordinates.y = i;
                cordinates.x = j;
                found = true;
                break;
            }
            j++;
        }
        if (found == true)
        {
            break;
        }
        j = 0;
        i++;
    }
    return cordinates;
}

static bool is_goal_reachable(t_data *game_data, t_point current, t_point goal, bool visited[game_data->map_height][game_data->map_width])
{
    int delta_y[] = {0, 1, 0, -1};
    int delta_x[] = {1, 0, -1, 0};
    int next_y;
    int next_x;
    int i;

    if (current.y == goal.y && current.x == goal.x )
    {
        return true;
    }
    i = 0;
    while (i < NEIGHBORS)
    {
        next_x = current.x + delta_x[i];
        next_y = current.y + delta_y[i];
        if (next_y >= game_data->map_height || next_y <= 0 || next_x >= game_data->map_width || next_x <= 0)
        {
            i++;
            continue;
        }
        if (visited[next_y][next_x] == true)
        {
            i++;
            continue;
        }
        if(game_data->map.map[next_y][next_x] == WALL)
        {
            i++;
            continue;
        }
        visited[next_y][next_x] = true;
        t_point next = {next_x, next_y};
        if (is_goal_reachable(game_data, next, goal, visited) == true)
        { 
            return true;
        }
        i++;
    }
    return false;
}

void is_game_playable(t_data *game_data)
{
    t_point current;
    t_point goal;
    bool visited[game_data->map_height][game_data->map_width];
    
    current = find_element_cordinates(game_data, PLAYER);
    goal = find_element_cordinates(game_data, EXIT);
    ft_memset(visited, false, sizeof(visited));
    if (is_goal_reachable(game_data, current, goal, visited) == false) 
    {
        ft_printf("\x1b[31mError\nMap is unplayable\n\x1b[0m");  
        exit(EXIT_FAILURE);
    }
}