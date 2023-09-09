/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuendo <yuendo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 17:47:48 by yuendo            #+#    #+#             */
/*   Updated: 2023/09/09 18:47:54 by yuendo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static char	*so_long_strjoin(char *s1, char *s2)
{
	char	*str;
	char	*str_start;
	char	*s1_start;
	size_t	size;

	if (!s1 && !s2)
		return (NULL);
	s1_start = s1;
	size = ft_strlen(s1) + ft_strlen(s2) + 1;
	str = (char *)ft_calloc(size, sizeof(char));
	if (!str)
		return (NULL);
	str_start = str;
	while (s1 != NULL && *s1)
		*str++ = *s1++;
	while (s2 != NULL && *s2)
		*str++ = *s2++;
	*str = 0;
	str = str_start;
	free(s1_start);
	return (str_start);
}

static char	**read_map_from_file(char *map_info)
{
	const int	fd = open(map_info, O_RDONLY);
	char		*line;
	char		*concat_lines;
	char		**map;

	concat_lines = NULL;
	if (fd == INVALID_FD)
		error_exit(MAP_NOT_FOUND);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL || line[0] == '\n')
			break ;
		concat_lines = so_long_strjoin(concat_lines, line);
		if (concat_lines == NULL)
			error_exit(MALLOC_ERROR);
		free(line);
	}
	free(line);
	close(fd);
	map = ft_split(concat_lines, '\n');
	free(concat_lines);
	return (map);
}

static void	is_valid_map(char **map)
{
	is_valid_map_shape(map);
	is_map_walled(map);
	is_valid_map_elements(map);
}

void	load_map(char *map_path, t_data *game_data)
{
	char	**map;

	map = read_map_from_file(map_path);
	if (map == NULL)
		error_exit(EMPTY_MAP);
	is_valid_map(map);
	game_data->map.map = map;
	game_data->map_width = ft_strlen(map[0]);
	game_data->map_height = get_map_len(map);
	game_data->coin_num = count_elements(map, COLLECTIBLE);
	game_data->move_count = 0;
	is_game_playable(game_data);
}
