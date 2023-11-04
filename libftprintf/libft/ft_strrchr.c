/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yutoendo <yutoendo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 17:54:28 by yuendo            #+#    #+#             */
/*   Updated: 2023/11/04 17:15:43 by yutoendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*str;
	size_t	ssize;

	str = (char *)s;
	ssize = ft_strlen(str);
	if (str[ssize] == (char)c)
		return (&str[ssize]);
	while (ssize--)
	{
		if (str[ssize] == (char)c)
			return (&str[ssize]);
	}
	return (NULL);
}
