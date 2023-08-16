/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuendo <yuendo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 13:32:07 by yutoendo          #+#    #+#             */
/*   Updated: 2023/05/19 17:00:20 by yuendo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*p;

	p = (unsigned char *)b;
	while (len--)
		*p++ = (unsigned char)c;
	return (b);
}

// #include        <stdio.h>
// #include        <string.h>
// int main(void)
// {
//     char str[] = "0123456789";
//     char str2[] = "0123456789";
//     memset(str+2, '*', 5);
//     ft_memset(str2+2, '*', 5);
//     printf("%s\n",str);
//     printf("%s\n", str2);
//     return (0);
// }