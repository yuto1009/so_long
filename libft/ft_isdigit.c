/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yutoendo <yutoendo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 17:20:25 by yuendo            #+#    #+#             */
/*   Updated: 2023/07/05 17:06:53 by yutoendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
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
// 	printf("\nft_isdigit : \n");
//     printf("a = %d\n", ft_isdigit(a));
//     printf("b = %d\n", ft_isdigit(b));
//     printf("z = %d\n", ft_isdigit(z));
//     printf("A = %d\n", ft_isdigit(A));
//     printf("B = %d\n", ft_isdigit(B));
//     printf("Z = %d\n", ft_isdigit(Z));
//     printf("space = %d\n", ft_isdigit(space));
//     printf("null = %d\n", ft_isdigit(null));
//     printf("del = %d\n", ft_isdigit(del));
//     printf("zero = %d\n", ft_isdigit(zero));
//     printf("equal = %d\n", ft_isdigit(equal));
//     printf("plus = %d\n", ft_isdigit(plus));
// 	printf("one = %d\n", ft_isdigit(one));
// 	printf("nine = %d\n", ft_isdigit(nine));
// 	printf("\nisdigit : \n");
//     printf("a = %d\n", isdigit(a));
//     printf("b = %d\n", isdigit(b));
//     printf("z = %d\n", isdigit(z));
//     printf("A = %d\n", isdigit(A));
//     printf("B = %d\n", isdigit(B));
//     printf("Z = %d\n", isdigit(Z));
//     printf("space = %d\n", isdigit(space));
//     printf("null = %d\n", isdigit(null));
//     printf("del = %d\n", isdigit(del));
//     printf("zero = %d\n", isdigit(zero));
//     printf("equal = %d\n", isdigit(equal));
//     printf("plus = %d\n", isdigit(plus));
// 	printf("one = %d\n", isdigit(one));
// 	printf("nine = %d\n", isdigit(nine));
//     return (0);
// }