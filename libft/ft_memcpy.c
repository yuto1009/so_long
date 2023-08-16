/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuendo <yuendo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 17:09:52 by yutoendo          #+#    #+#             */
/*   Updated: 2023/05/30 15:53:56 by yuendo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;

	s = (const unsigned char *)src;
	d = (unsigned char *)dst;
	if (s == NULL && d == NULL)
		return NULL;
	while (n--)
		*d++ = *s++;
	return (dst);
}

// #include <stdio.h>
// #include <string.h>

// int main(void){
//     char buf[] = "ABCDEFG";
//     char buf2[] = "123456789";
//     char buf3[] = "ABCDEFG";
//     char buf4[] = "123456789";
//     char buf5[] = "zyx\012";
//     char buf6[] = "zyx\012";
//     memcpy(buf, buf2, 3);
//     ft_memcpy(buf3, buf4, 3);
//     printf("memcpy : %s\n", buf);
//     printf("ft_memcpy : %s\n", buf3);
//     memcpy(buf, buf5, 4);
//     ft_memcpy(buf3, buf6, 4);
//     printf("memcpy : %s\n", buf);
//     printf("ft_memcpy : %s\n", buf3);
//     return (0);
// }
// #include <stdio.h>
// #include <string.h>
// int main(void)
// {
//         // char str1[128] = {1,1,1,1,1,1,1};
//         // char str2[] = "ab\0cde";        /* 途中に空文字のある文字列 */
//         // char str3[128] = {1,1,1,1,1,1,1};
//         // int i;
//         // printf("コピー前 中身の確認\n");
//         // for (i=0; i<7; i++)
//         //         printf("%#x ",str1[i]);
//         // printf("\n");
//         // memcpy(str1, str2, 5);
//         // ft_memcpy(str3, str2, 5);
//         // printf("コピー後 中身の確認\n");
//         // for (i=0; i<7; i++){
//         //         printf("memcpy : %#x ",str1[i]);
//         //         printf("ft_memcpy : %#x ",str3[i]);
//         //         printf("\n");
//         // }
//         //     char buf[] = "ABCDEFG";
//         char buf1[] = "123456789";
//         char buf2[] = "123456789";
//         memcpy(buf1+4, buf1, 3);
//         ft_memcpy(buf2+4, buf2, 3);
//         printf("memcpy : %s\n", buf1);
//         printf("ft_memcpy : %s\n", buf2);
//         return (0);
// }