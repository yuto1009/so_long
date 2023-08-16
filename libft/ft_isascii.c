/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yutoendo <yutoendo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 12:23:09 by yutoendo          #+#    #+#             */
/*   Updated: 2023/07/05 17:07:40 by yutoendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	return (c >= 0 && c <= 127);
}

// #include <stdio.h>
// #include <ctype.h>
// int main(void){
//     char a = 'a';
//     char b = 'b';
//     char z = 'z';
//     char A = 'A';
//     char B = 'B';
//     char Z = 'Z';
//     char space = ' ';
//     char null = '\0';
//     char del = 127;
//     char zero = '0';
//     char equal = '=';
//     char plus = '+';
// 	char one = '1';
// 	char nine = '9';
// 	printf("\nft_isascii : \n");
//     printf("a = %d\n", ft_isascii(a));
//     printf("b = %d\n", ft_isascii(b));
//     printf("z = %d\n", ft_isascii(z));
//     printf("A = %d\n", ft_isascii(A));
//     printf("B = %d\n", ft_isascii(B));
//     printf("Z = %d\n", ft_isascii(Z));
//     printf("space = %d\n", ft_isascii(space));
//     printf("null = %d\n", ft_isascii(null));
//     printf("del = %d\n", ft_isascii(del));
//     printf("zero = %d\n", ft_isascii(zero));
//     printf("equal = %d\n", ft_isascii(equal));
//     printf("plus = %d\n", ft_isascii(plus));
// 	printf("one = %d\n", ft_isascii(one));
// 	printf("nine = %d\n", ft_isascii(nine));
// 	printf("\nisascii : \n");
//     printf("a = %d\n", isascii(a));
//     printf("b = %d\n", isascii(b));
//     printf("z = %d\n", isascii(z));
//     printf("A = %d\n", isascii(A));
//     printf("B = %d\n", isascii(B));
//     printf("Z = %d\n", isascii(Z));
//     printf("space = %d\n", isascii(space));
//     printf("null = %d\n", isascii(null));
//     printf("del = %d\n", isascii(del));
//     printf("zero = %d\n", isascii(zero));
//     printf("equal = %d\n", isascii(equal));
//     printf("plus = %d\n", isascii(plus));
// 	printf("one = %d\n", isascii(one));
// 	printf("nine = %d\n", isascii(nine));
//     return (0);
// }