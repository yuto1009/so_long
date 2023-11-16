/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_game_playable.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yutoendo <yutoendo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 18:16:13 by yuendo            #+#    #+#             */
/*   Updated: 2023/11/16 22:15:29 by yutoendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static bool	**init_visited(t_data *game_data)
{
	bool	**visited;
	int		i;

	visited = (bool **)ft_calloc(game_data->map_height, sizeof(bool *));
	if (visited == NULL)
		error_exit(MALLOC_ERROR);
	i = 0;
	while (i < game_data->map_height)
	{
		visited[i] = (bool *)ft_calloc(game_data->map_width, sizeof(bool));
		if (visited[i] == NULL)
			error_exit(MALLOC_ERROR);
		i++;
	}
	return (visited);
}

static void	depth_first_search(t_data *game_data, t_point current,
		bool **visited)
{
	if (game_data->map.map[current.y][current.x] == WALL)
		return ;
	if (game_data->map.map[current.y][current.x] == EXIT)
		return ;
	if (visited[current.y][current.x] == true)
	{
		return ;
	}
	visited[current.y][current.x] = true;
	depth_first_search(game_data, (t_point){current.x + 1, current.y}, visited);
	depth_first_search(game_data, (t_point){current.x - 1, current.y}, visited);
	depth_first_search(game_data, (t_point){current.x, current.y + 1}, visited);
	depth_first_search(game_data, (t_point){current.x, current.y - 1}, visited);
	return ;
}

static bool	is_able_to_exit(t_data *game_data,
							bool **visited)
{
	t_point	exit;

	exit = find_unique_element_cordinates(game_data, EXIT);
	if (visited[exit.y][exit.x] == true
		|| game_data->map.map[exit.y][exit.x] == EXIT)
		return (true);
	return (false);
}

static bool	is_able_to_collect_all_coins(t_data *game_data,
											bool **visited)
{
	int	i;
	int	j;
	int	coins_left;

	i = 0;
	j = 0;
	coins_left = game_data->coin_num;
	while (i < game_data->map_height)
	{
		j = 0;
		while (j < game_data->map_width)
		{
			if (game_data->map.map[i][j] == COLLECTIBLE
				&& visited[i][j] == true)
				coins_left--;
			j++;
		}
		i++;
	}
	if (coins_left == 0)
		return (true);
	return (false);
}

void	is_game_playable(t_data *game_data)
{
	t_point	current;
	bool	**visited;

	current = find_unique_element_cordinates(game_data, PLAYER);
	visited = init_visited(game_data);
	ft_memset(visited, false, sizeof(visited));
	depth_first_search(game_data, current, visited);
	if (is_able_to_exit(game_data, visited) == false)
		error_exit(MAP_UNPLAYABLE);
	if (is_able_to_collect_all_coins(game_data, visited) == false)
		error_exit(MAP_UNPLAYABLE);
}
