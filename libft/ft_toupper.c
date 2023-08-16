/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuendo <yuendo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 17:00:31 by yuendo            #+#    #+#             */
/*   Updated: 2023/05/19 17:12:24 by yuendo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		c -= 32;
	return (c);
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
// 	printf("\nft_toupper : \n");
//     printf("a = %d\n", ft_toupper(a));
//     printf("b = %d\n", ft_toupper(b));
//     printf("z = %d\n", ft_toupper(z));
//     printf("A = %d\n", ft_toupper(A));
//     printf("B = %d\n", ft_toupper(B));
//     printf("Z = %d\n", ft_toupper(Z));
//     printf("space = %d\n", ft_toupper(space));
//     printf("null = %d\n", ft_toupper(null));
//     printf("del = %d\n", ft_toupper(del));
//     printf("zero = %d\n", ft_toupper(zero));
//     printf("equal = %d\n", ft_toupper(equal));
//     printf("plus = %d\n", ft_toupper(plus));
// 	printf("one = %d\n", ft_toupper(one));
// 	printf("nine = %d\n", ft_toupper(nine));
// 	printf("\ntoupper : \n");
//     printf("a = %d\n", toupper(a));
//     printf("b = %d\n", toupper(b));
//     printf("z = %d\n", toupper(z));
//     printf("A = %d\n", toupper(A));
//     printf("B = %d\n", toupper(B));
//     printf("Z = %d\n", toupper(Z));
//     printf("space = %d\n", toupper(space));
//     printf("null = %d\n", toupper(null));
//     printf("del = %d\n", toupper(del));
//     printf("zero = %d\n", toupper(zero));
//     printf("equal = %d\n", toupper(equal));
//     printf("plus = %d\n", toupper(plus));
// 	printf("one = %d\n", toupper(one));
// 	printf("nine = %d\n", toupper(nine));
//     return (0);
// }