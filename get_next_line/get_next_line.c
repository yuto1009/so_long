/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuendo <yuendo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 12:41:05 by yuendo            #+#    #+#             */
/*   Updated: 2023/06/22 11:51:20 by yuendo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*load_buffer(int fd, char *loaded)
{
	char	*buffer;
	ssize_t	loaded_bytes;

	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	loaded_bytes = 1;
	while (!my_strchr(loaded, '\n') && loaded_bytes != 0)
	{
		loaded_bytes = read(fd, buffer, BUFFER_SIZE);
		if (loaded_bytes == -1)
		{
			free(buffer);
			free(loaded);
			return (NULL);
		}
		buffer[loaded_bytes] = '\0';
		loaded = my_strjoin(loaded, buffer);
	}
	free(buffer);
	return (loaded);
}

char	*get_return_line_utils(char *loaded, char *return_line)
{
	size_t	i;

	i = 0;
	while (loaded[i] && loaded[i] != '\n')
	{
		return_line[i] = loaded[i];
		i++;
	}
	if (loaded[i] && loaded[i] == '\n')
	{
		return_line[i] = loaded[i];
		i++;
	}
	return_line[i] = '\0';
	return (return_line);
}

char	*get_return_line(char *loaded)
{
	size_t	i;
	char	*return_line;

	i = 0;
	if (!(*loaded))
		return (NULL);
	while (loaded[i] != '\0' && loaded[i] != '\n')
		i++;
	if (loaded[i] == '\n')
		i++;
	return_line = (char *)malloc((i + 1) * sizeof(char));
	if (!return_line)
		return (NULL);
	return (get_return_line_utils(loaded, return_line));
}

char	*get_next_load(char *loaded)
{
	char	*next_load;
	size_t	i;
	size_t	j;

	i = 0;
	while (loaded[i] && loaded[i] != '\n')
		i++;
	if (!loaded[i])
	{
		free(loaded);
		return (NULL);
	}
	i++;
	next_load = (char *)malloc((ft_strlen(loaded) - i + 1) * sizeof(char));
	if (!next_load)
	{
		free(loaded);
		return (NULL);
	}
	j = 0;
	while (loaded[i])
		next_load[j++] = loaded[i++];
	next_load[j] = '\0';
	free(loaded);
	return (next_load);
}

char	*get_next_line(int fd)
{
	static char	*loaded;
	char		*return_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	loaded = load_buffer(fd, loaded);
	if (!loaded)
		return (NULL);
	return_line = get_return_line(loaded);
	loaded = get_next_load(loaded);
	return (return_line);
}

// __attribute__((destructor))
// static void destructor() {
//     system("leaks -q a.out");
// }

// #include <fcntl.h>
// #include <stdio.h>
// int main()
// {
//     int        fd;
//     char    *line;

//     fd = open("./sample", O_RDONLY);
//     while (1)
//     {
//         line = get_next_line(fd);
//         if (line == NULL){
//             printf("LINE is NULL\n");
//             break ;
//         }
//         printf("%s", line);
//         free(line);
//     }

// 	fd = open("./sample2", O_RDONLY);
//     while (1)
//     {
//         line = get_next_line(fd);
//         if (line == NULL){
//             printf("LINE is NULL\n");
//             break ;
//         }
//         printf("%s", line);
//         free(line);
//     }

//     fd = open("./sample3", O_RDONLY);
//     while (1)
//     {
//         line = get_next_line(fd);
//         if (line == NULL){
//             printf("LINE is NULL\n");
//             return (0);
//         }
//         printf("%s", line);
//         free(line);
//     }
//     return (0);
// }