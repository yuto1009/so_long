/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuendo <yuendo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 17:31:00 by yuendo            #+#    #+#             */
/*   Updated: 2023/05/25 19:54:23 by yuendo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*str;

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

// #include <string.h>
// #include <stdio.h>

// int main()
// {
//     char a[] = "aiueo";

//     printf("%s : %s\n", "ft", "lib");
//     printf("%s : %s\n", ft_strchr(a, 'a'), strchr(a, 'a'));
//     printf("%s : %s\n", ft_strchr(a, 'i'), strchr(a, 'i'));
//     printf("%s : %s\n", ft_strchr(a, 'u'), strchr(a, 'u'));
//     printf("%s : %s\n", ft_strchr(a, 'e'), strchr(a, 'e'));
//     printf("%s : %s\n", ft_strchr(a, 'o'), strchr(a, 'o'));
//     printf("%s : %s\n", ft_strchr(a, 0), strchr(a, 0));
//     printf("%p : %p\n", ft_strchr(a, 0), strchr(a, 0));
//     printf("%s : %s\n", ft_strchr(a, 1), strchr(a, 1));
//     printf("%s : %s\n", ft_strchr(a, 'z'), strchr(a, 'z'));
//     return (0);
// }