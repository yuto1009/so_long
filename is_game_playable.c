/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_game_playable.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuendo <yuendo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 13:44:52 by yuendo            #+#    #+#             */
/*   Updated: 2023/08/19 19:49:44 by yuendo           ###   ########.fr       */
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

static bool is_goal_reachable(t_data *game_data, t_point current, t_point goal, bool visited[][game_data->map_width])
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
        next_y = current.y + delta_y[i];
        next_x = current.x + delta_x[i];
        if (next_y >= game_data->map_height || next_y <= 0 || next_x >= game_data->map_width || next_x <= 0)
        {
            continue;
        }
        if (visited[next_y][next_x] == true)
        {
            continue;
        }
        if(game_data->map.map[next_y][next_x] == WALL)
        {
            continue;
        }
        visited[next_y][next_x] = true;
        t_point next = {next_y, next_x};
        if (is_goal_reachable(game_data, next, goal, visited))
        { 
            return true;
        }
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