/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuendo <yuendo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 17:28:17 by yuendo            #+#    #+#             */
/*   Updated: 2023/09/09 18:47:40 by yuendo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

size_t	get_map_len(char **map)
{
	size_t	i;

	i = 0;
	while (map[i] != NULL)
	{
		i++;
	}
	return (i);
}

int	count_elements(char **map, char c)
{
	size_t			i;
	size_t			j;
	int				count;
	const size_t	map_len = get_map_len(map);

	i = 0;
	count = 0;
	while (i < map_len)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (map[i][j] == c)
			{
				count++;
			}
			j++;
		}
		i++;
	}
	return (count);
}

t_point	find_unique_element_cordinates(t_data *game_data, char element)
{
	t_point	cordinates;
	int		i;
	int		j;
	bool	found;

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
	return (cordinates);
}

void	error_exit(int error_num)
{
	if (error_num == MALLOC_ERROR)
		ft_printf("\x1b[31mError\nMalloc Error\n\x1b[0m");
	else if (error_num == EMPTY_MAP)
		ft_printf("\x1b[31mError\nEmpty map\n\x1b[0m");
	else if (error_num == INVALID_ARGS)
		ft_printf("\x1b[31mError\nInvalid arguments\n\x1b[0m");
	else if (error_num == MAP_NOT_FOUND)
		ft_printf("\x1b[31mError\nMap not found\n\x1b[0m");
	else if (error_num == INVALID_ELEMENTS)
		ft_printf("\x1b[31mError\nInvalid elements\n\x1b[0m");
	else if (error_num == INVALID_MAP_SHAPE)
		ft_printf("\x1b[31mError\nMap width is invalid\n\x1b[0m");
	else if (error_num == MAP_NOT_WALLED)
		ft_printf("\x1b[31mError\nMap is not walled\n\x1b[0m");
	else if (error_num == MAP_UNPLAYABLE)
		ft_printf("\x1b[31mError\nMap is unplayable\n\x1b[0m");
	exit(EXIT_FAILURE);
}
