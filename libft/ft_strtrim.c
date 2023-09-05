/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yutoendo <yutoendo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 16:44:55 by yutoendo          #+#    #+#             */
/*   Updated: 2023/09/05 16:21:47 by yutoendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

const char	*ft_strtrim(char *s1, char *set)
{
	char	*str;
	size_t	size;

	if (!s1)
		return (NULL);
	if (set)
	{
		while (*s1 && ft_strchr(set, *s1))
			s1++;
	}
	size = ft_strlen(s1);
	if (set)
	{
		while (0 < size && ft_strchr(set, s1[size - 1]))
			size--;
	}
	str = ft_substr(s1, 0, size);
	if (!str)
		return (NULL);
	return (str);
}
