/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_map_elements.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuendo <yuendo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 18:06:06 by yuendo            #+#    #+#             */
/*   Updated: 2023/11/10 12:03:19 by yuendo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static bool	check_essential_elements(char **map)
{
	size_t	map_len;
	size_t	i;

	map_len = get_map_len(map);
	i = 0;
	while (i < map_len)
	{
		if (count_elements(map, COLLECTIBLE) < true || count_elements(map,
				EXIT) != true || count_elements(map, PLAYER) != true)
		{
			return (false);
		}
		i++;
	}
	return (true);
}

static bool	is_known_elements(char **map)
{
	size_t		map_len;
	size_t		i;
	const char	*trimmed;

	map_len = get_map_len(map);
	i = 0;
	while (i < map_len)
	{
		trimmed = ft_strtrim(map[i], VALID_ELEMENTS);
		if (ft_strlen(trimmed) != 0)
		{
			free((void *)trimmed);
			return (false);
		}
		free((void *)trimmed);
		i++;
	}
	return (true);
}

void	is_valid_map_elements(char **map)
{
	if (check_essential_elements(map) == false
		|| is_known_elements(map) == false)
	{
		error_exit(INVALID_ELEMENTS);
	}
}
