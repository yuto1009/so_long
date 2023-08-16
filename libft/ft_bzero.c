/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yutoendo <yutoendo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 16:52:42 by yutoendo          #+#    #+#             */
/*   Updated: 2023/05/17 17:05:15 by yutoendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*p;

	p = (unsigned char *)s;
	while (n--)
		*p++ = 0;
}

// #include        <stdio.h>
// #include        <string.h>

// int main(void)
// {
//     char str[] = "0123456789";
//     char str2[] = "0123456789";
//     bzero(str+2, 5);
//     ft_bzero(str2+2, 5);
//     printf("%s\n",str);
//     printf("%s\n", str2);

//     return (0);
// }