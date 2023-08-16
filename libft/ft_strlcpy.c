/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuendo <yuendo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 13:16:34 by yutoendo          #+#    #+#             */
/*   Updated: 2023/05/25 16:21:18 by yuendo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	if (dstsize == 0)
		return (ft_strlen(src));
	i = 0;
	while (src[i] && i < dstsize - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(src));
}

// #include <stdio.h>
// #include <string.h>
// int    main(void)
// {
//     char    dst[11];
//     char        src[] = "0123456789";
//     char    dst2[11];
//     char        src2[] = "0123456789";
//     ft_strlcpy(dst, src, sizeof(dst)); // "012345678"になる
//     printf("ft : %s\n", dst);
//     strlcpy(dst2, src2, sizeof(dst2)); // "012345678"になる
//     printf("or : %s\n", dst2);
// }