/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuendo <yuendo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 16:11:36 by yuendo            #+#    #+#             */
/*   Updated: 2023/05/28 20:16:46 by yuendo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*p;
	size_t	i;
	size_t	strlen;

	if (!s || !f)
		return (NULL);
	strlen = ft_strlen(s);
	p = malloc(sizeof(char) * (strlen + 1));
	if (!p)
		return (NULL);
	i = 0;
	while (i < strlen)
	{
		p[i] = f(i, s[i]);
		i++;
	}
	p[i] = '\0';
	return (p);
}
