/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuendo <yuendo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 17:52:08 by yutoendo          #+#    #+#             */
/*   Updated: 2023/05/19 16:47:04 by yuendo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	dst_len;
	size_t	src_len;

	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if (dst_len >= dstsize)
		return (src_len + dstsize);
	i = 0;
	while (src[i] && i < dstsize - dst_len - 1)
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	dst[dst_len + i] = '\0';
	return (src_len + dst_len);
}

// #include <stdio.h>
// #include <string.h>
// int    main(void)
// {
//     char    dst[11];
//     char        src[] = "1234567890";
//     char    dst2[11];
//     char        src2[] = "1234567890";
//     ft_strlcat(dst, src, sizeof(dst)); // "012345678"になる
//     printf("ft : %s\n", dst);
//     strlcat(dst2, src2, sizeof(dst2)); // "012345678"になる
//     printf("or : %s\n", dst2);
// }