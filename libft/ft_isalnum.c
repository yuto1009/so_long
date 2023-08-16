/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yutoendo <yutoendo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 17:46:33 by yuendo            #+#    #+#             */
/*   Updated: 2023/05/29 22:10:08 by yutoendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	return (ft_isdigit(c) || ft_isalpha(c));
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
// 	printf("\nft_isalnum : \n");
//     printf("a = %d\n", ft_isalnum(a));
//     printf("b = %d\n", ft_isalnum(b));
//     printf("z = %d\n", ft_isalnum(z));
//     printf("A = %d\n", ft_isalnum(A));
//     printf("B = %d\n", ft_isalnum(B));
//     printf("Z = %d\n", ft_isalnum(Z));
//     printf("space = %d\n", ft_isalnum(space));
//     printf("null = %d\n", ft_isalnum(null));
//     printf("del = %d\n", ft_isalnum(del));
//     printf("zero = %d\n", ft_isalnum(zero));
//     printf("equal = %d\n", ft_isalnum(equal));
//     printf("plus = %d\n", ft_isalnum(plus));
// 	printf("one = %d\n", ft_isalnum(one));
// 	printf("nine = %d\n", ft_isalnum(nine));
// 	printf("\nisalnum : \n");
//     printf("a = %d\n", isalnum(a));
//     printf("b = %d\n", isalnum(b));
//     printf("z = %d\n", isalnum(z));
//     printf("A = %d\n", isalnum(A));
//     printf("B = %d\n", isalnum(B));
//     printf("Z = %d\n", isalnum(Z));
//     printf("space = %d\n", isalnum(space));
//     printf("null = %d\n", isalnum(null));
//     printf("del = %d\n", isalnum(del));
//     printf("zero = %d\n", isalnum(zero));
//     printf("equal = %d\n", isalnum(equal));
//     printf("plus = %d\n", isalnum(plus));
// 	printf("one = %d\n", isalnum(one));
// 	printf("nine = %d\n", isalnum(nine));
//     return (0);
// }