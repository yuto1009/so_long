/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuendo <yuendo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 11:53:13 by yuendo            #+#    #+#             */
/*   Updated: 2023/05/20 13:20:26 by yuendo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*str;
	size_t				i;

	str = (const unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (str[i] == (unsigned char)c)
			return ((void *)&str[i]);
		i++;
	}
	return (NULL);
}

// #include        <stdio.h>
// #include        <string.h>
// int main(void)
// {
//         char str[] = "abcdef\0ghij";    /* 途中に空文字のある文字列 */
//         char *p;
//         p = memchr(str, 'h', 12);
//         printf("検索文字は文字列の%ld番目\n",p - str);
//         return (0);
// }