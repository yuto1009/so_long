/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yutoendo <yutoendo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 16:37:10 by yuendo            #+#    #+#             */
/*   Updated: 2023/07/05 17:08:15 by yutoendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	return ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'));
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

// 	printf("ft_isalpha : \n");
//     printf("a = %d\n", ft_isalpha(a));
//     printf("b = %d\n", ft_isalpha(b));
//     printf("z = %d\n", ft_isalpha(z));
//     printf("A = %d\n", ft_isalpha(A));
//     printf("B = %d\n", ft_isalpha(B));
//     printf("Z = %d\n", ft_isalpha(Z));
//     printf("space = %d\n", ft_isalpha(space));
//     printf("null = %d\n", ft_isalpha(null));
//     printf("del = %d\n", ft_isalpha(del));
//     printf("zero = %d\n", ft_isalpha(zero));
//     printf("equal = %d\n", ft_isalpha(equal));
//     printf("plus = %d\n", ft_isalpha(plus));

// 	printf("isalpha : \n");
//     printf("a = %d\n", isalpha(a));
//     printf("b = %d\n", isalpha(b));
//     printf("z = %d\n", isalpha(z));
//     printf("A = %d\n", isalpha(A));
//     printf("B = %d\n", isalpha(B));
//     printf("Z = %d\n", isalpha(Z));
//     printf("space = %d\n", isalpha(space));
//     printf("null = %d\n", isalpha(null));
//     printf("del = %d\n", isalpha(del));
//     printf("zero = %d\n", isalpha(zero));
//     printf("equal = %d\n", isalpha(equal));
//     printf("plus = %d\n", isalpha(plus));

//     return (0);
// }