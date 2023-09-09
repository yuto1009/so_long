/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_map_shape.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuendo <yuendo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 17:58:06 by yuendo            #+#    #+#             */
/*   Updated: 2023/09/09 18:48:01 by yuendo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	is_valid_map_shape(char **map)
{
	const size_t	first_line_len = ft_strlen(map[0]);
	size_t			i;

	i = 0;
	while (map[i] != NULL)
	{
		if (ft_strlen(map[i]) != first_line_len)
		{
			error_exit(INVALID_MAP_SHAPE);
		}
		i++;
	}
}
