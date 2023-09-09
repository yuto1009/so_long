/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_game_playable.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuendo <yuendo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 13:44:52 by yuendo            #+#    #+#             */
/*   Updated: 2023/09/09 17:03:50 by yuendo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static t_point find_unique_element_cordinates(t_data *game_data, char element)
{
    t_point cordinates;
    int i;
    int j;
    bool found;
    
    i = 0;
    found = false;
    while (found == false && i < game_data->map_height)
    {
        j = 0;
        while (found == false && j < game_data->map_width)
        {
            if (game_data->map.map[i][j] == element)
            {
                cordinates.y = i;
                cordinates.x = j;
                found = true;
            }
            j++;
        }
        i++;
    }
    return cordinates;
}

static void depth_first_search(t_data *game_data, t_point current, bool visited[game_data->map_height][game_data->map_width])
{
    if (game_data->map.map[current.y][current.x] == WALL)
        return;
    if (visited[current.y][current.x] == true)
    {
        return;
    }
    visited[current.y][current.x] = true;
    depth_first_search(game_data, (t_point){current.x + 1, current.y}, visited);
    depth_first_search(game_data, (t_point){current.x - 1, current.y}, visited);
    depth_first_search(game_data, (t_point){current.x, current.y + 1}, visited);
    depth_first_search(game_data, (t_point){current.x, current.y - 1}, visited);
    return;
}

static bool is_able_to_exit(t_data *game_data, bool visited[game_data->map_height][game_data->map_width])
{
    t_point exit;
    
    exit = find_unique_element_cordinates(game_data, EXIT);
    if (visited[exit.y][exit.x] == true || game_data->map.map[exit.y][exit.x] == EXIT)
        return true;
    return false;
}

static bool is_able_to_collect_all_coins(t_data *game_data, bool visited[game_data->map_height][game_data->map_width])
{
    int i;
    int j;
    int coins_left;

    i = 0;
    j = 0;
    coins_left = game_data->coin_num;
    while (i < game_data->map_height)
    {
        j = 0;
        while (j < game_data->map_width)
        {
            if (game_data->map.map[i][j] == COLLECTIBLE && visited[i][j] == true)
                coins_left--;
            j++;
        }
        i++;
    }
    if (coins_left == 0)
        return true;
    return false;
}

void is_game_playable(t_data *game_data)
{
    t_point current;
    t_point goal;
    bool visited[game_data->map_height][game_data->map_width];
    int coins_left;
    
    coins_left = game_data->coin_num;
    current = find_unique_element_cordinates(game_data, PLAYER);
    goal = find_unique_element_cordinates(game_data, EXIT);
    ft_memset(visited, false, sizeof(visited));
    depth_first_search(game_data, current, visited);
    if (is_able_to_exit(game_data, visited) == false)
        error_exit(MAP_UNPLAYABLE);
    if (is_able_to_collect_all_coins(game_data, visited) == false)
        error_exit(MAP_UNPLAYABLE);
}