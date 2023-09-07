/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_game_playable.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuendo <yuendo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 13:44:52 by yuendo            #+#    #+#             */
/*   Updated: 2023/09/07 17:46:08 by yuendo           ###   ########.fr       */
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
    j = 0;
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

static bool is_valid_move(t_data *game_data, t_point next, bool visited[game_data->map_height][game_data->map_width])
{
    if (next.y >= game_data->map_height || next.y <= 0 || next.x >= game_data->map_width || next.x <= 0)
        return false;
    if (visited[next.y][next.x] == true)
        return false;
    if (game_data->map.map[next.y][next.x] == WALL)
        return false;
    return true;
}

// static bool is_coin_collectable(t_data *game_data, t_point current, t_point goal, bool visited[game_data->map_height][game_data->map_width])
// {
//     const int delta_y[] = {0, 1, 0, -1};
//     const int delta_x[] = {1, 0, -1, 0};
//     int i;
//     int coins_left;
    
//     coins_left = game_data->coin_num;
//     if (current.y == goal.y && current.x == goal.x && coins_left == 0)
//         return true;
//     i = 0;
//     while (i < NEIGHBORS)
//     {
//         const t_point next = {current.x + delta_x[i], current.y + delta_y[i]};
//         if (is_valid_move(game_data, next, visited) == true)
//         {
//             visited[next.y][next.x] = true;
//             if (game_data->map.map[next.y][next.x] == COLLECTIBLE)
//             {
//                 coins_left--;
//             }
//             if (is_coin_collectable(game_data, next, goal, visited) == true)
//                 return true;
//         }
//         i++;
//     }
//     return false;
// }

// static bool is_goal_reachable(t_data *game_data, t_point current, t_point goal, bool visited[game_data->map_height][game_data->map_width])
// {
//     const int delta_y[] = {0, 1, 0, -1};
//     const int delta_x[] = {1, 0, -1, 0};
//     int i;

//     if (current.y == goal.y && current.x == goal.x )
//         return true;
//     i = 0;
//     while (i < NEIGHBORS)
//     {
//         const t_point next = {current.x + delta_x[i], current.y + delta_y[i]};
//         if (is_valid_move(game_data, next, visited) == true)
//         {
//             visited[next.y][next.x] = true;
//             if (is_goal_reachable(game_data, next, goal, visited) == true)
//                 return true;
//         }
//         i++;
//     }
//     return false;
// }
static bool is_goal_reachable(t_data *game_data, t_point current, t_point goal, bool visited[game_data->map_height][game_data->map_width])
{
    const int delta_y[] = {0, 1, 0, -1};
    const int delta_x[] = {1, 0, -1, 0};
    int i;

    if (current.y == goal.y && current.x == goal.x )
        return true;
    i = 0;
    while (i < NEIGHBORS)
    {
        const t_point next = {current.x + delta_x[i], current.y + delta_y[i]};
        if (is_valid_move(game_data, next, visited) == true)
        {
            visited[next.y][next.x] = true;
            if (is_goal_reachable(game_data, next, goal, visited) == true)
                return true;
        }
        i++;
    }
    return false;
}

static bool is_coin_collectable(t_data *game_data, bool visited[game_data->map_height][game_data->map_width])
{
    int i;
    int j;
    int coins_left;
    
    i = 0;
    coins_left = game_data->coin_num;
    while (i < game_data->map_height)
    {
        j = 0;
        while (j < game_data->map_width)
        {
            if (game_data->map.map[i][j] == COLLECTIBLE && visited[i][j] == true)
            {
                coins_left--;
            }   
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
    
    current = find_unique_element_cordinates(game_data, PLAYER);
    goal = find_unique_element_cordinates(game_data, EXIT);
    ft_memset(visited, false, sizeof(visited));
    if (is_goal_reachable(game_data, current, goal, visited) == false) 
    {
        error_exit(MAP_UNPLAYABLE);
    }
    if (is_coin_collectable(game_data, visited) == false)
    {
        error_exit(MAP_UNPLAYABLE);
    }
}