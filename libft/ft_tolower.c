/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuendo <yuendo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 17:23:52 by yuendo            #+#    #+#             */
/*   Updated: 2023/05/19 17:26:49 by yuendo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		c += 32;
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
// 	printf("\nft_tolower : \n");
//     printf("a = %d\n", ft_tolower(a));
//     printf("b = %d\n", ft_tolower(b));
//     printf("z = %d\n", ft_tolower(z));
//     printf("A = %d\n", ft_tolower(A));
//     printf("B = %d\n", ft_tolower(B));
//     printf("Z = %d\n", ft_tolower(Z));
//     printf("space = %d\n", ft_tolower(space));
//     printf("null = %d\n", ft_tolower(null));
//     printf("del = %d\n", ft_tolower(del));
//     printf("zero = %d\n", ft_tolower(zero));
//     printf("equal = %d\n", ft_tolower(equal));
//     printf("plus = %d\n", ft_tolower(plus));
// 	printf("one = %d\n", ft_tolower(one));
// 	printf("nine = %d\n", ft_tolower(nine));
// 	printf("\ntolower : \n");
//     printf("a = %d\n", tolower(a));
//     printf("b = %d\n", tolower(b));
//     printf("z = %d\n", tolower(z));
//     printf("A = %d\n", tolower(A));
//     printf("B = %d\n", tolower(B));
//     printf("Z = %d\n", tolower(Z));
//     printf("space = %d\n", tolower(space));
//     printf("null = %d\n", tolower(null));
//     printf("del = %d\n", tolower(del));
//     printf("zero = %d\n", tolower(zero));
//     printf("equal = %d\n", tolower(equal));
//     printf("plus = %d\n", tolower(plus));
// 	printf("one = %d\n", tolower(one));
// 	printf("nine = %d\n", tolower(nine));
//     return (0);
// }