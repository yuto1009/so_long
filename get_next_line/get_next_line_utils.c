/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuendo <yuendo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 12:41:45 by yuendo            #+#    #+#             */
/*   Updated: 2023/08/01 16:02:19 by yuendo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// size_t	ft_strlen(const char *s)
// {
// 	size_t	i;

// 	if (s == NULL)
// 		return (0);
// 	i = 0;
// 	while (s[i])
// 		i++;
// 	return (i);
// }

// void	ft_bzero(void *s, size_t n)
// {
// 	unsigned char	*p;

// 	p = (unsigned char *)s;
// 	while (n--)
// 		*p++ = 0;
// }

// void	*ft_calloc(size_t count, size_t size)
// {
// 	void	*p;

// 	if (size && count > SIZE_MAX / size)
// 		return (NULL);
// 	p = (void *)malloc(count * size);
// 	if (!p)
// 		return (NULL);
// 	ft_bzero(p, count * size);
// 	return (p);
// }

char	*my_strchr(const char *s, int c)
{
	char	*str;

	if (!s)
		return (NULL);
	str = (char *)s;
	while (*str != '\0')
	{
		if (*str == (char)c)
			return (str);
		str++;
	}
	if (*str == (char)c)
		return (str);
	return (NULL);
}

char	*my_strjoin(char *loaded, char *buffer)
{
	char	*str;
	char	*str_start;
	char	*loaded_start;

	if (!loaded)
		loaded = (char *)ft_calloc(1, sizeof(char));
	if (!loaded || !buffer)
		return (NULL);
	str = (char *)malloc((ft_strlen(loaded) + ft_strlen(buffer) + 1)
			* sizeof(char));
	if (!str)
	{
		free(loaded);
		return (NULL);
	}
	str_start = str;
	loaded_start = loaded;
	while (*loaded)
		*str++ = *loaded++;
	while (*buffer)
		*str++ = *buffer++;
	*str = 0;
	free(loaded_start);
	return (str_start);
}
