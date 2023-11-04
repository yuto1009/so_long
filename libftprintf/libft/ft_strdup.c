/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuendo <yuendo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 17:28:45 by yuendo            #+#    #+#             */
/*   Updated: 2023/05/21 17:54:38 by yuendo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	const char	*p;

	p = malloc(ft_strlen(s1) + 1);
	if (p == NULL)
		return (NULL);
	ft_strlcpy((char *)p, (char *)s1, ft_strlen(s1) + 1);
	return ((char *)p);
}
