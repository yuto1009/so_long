/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuendo <yuendo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 16:28:27 by yutoendo          #+#    #+#             */
/*   Updated: 2023/06/03 20:51:35 by yuendo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	char	*str_start;
	size_t	size;

	if (!s1 && !s2)
		return (NULL);
	size = ft_strlen(s1) + ft_strlen(s2) + 1;
	str = (char *)malloc(size);
	if (!str)
		return (NULL);
	str_start = str;
	while (s1 != NULL && *s1)
		*str++ = *s1++;
	while (s2 != NULL && *s2)
		*str++ = *s2++;
	*str = 0;
	return (str_start);
}
