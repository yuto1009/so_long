/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yutoendo <yutoendo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 12:34:56 by yutoendo          #+#    #+#             */
/*   Updated: 2023/07/05 17:07:55 by yutoendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	return (c >= 32 && c <= 126);
}

// #include <stdio.h>

// int	main(void)
// {
// 	char a = 'a';
// 	char b = 'b';
// 	char z = 'z';
// 	char A = 'A';
// 	char B = 'B';
// 	char Z = 'Z';
// 	char space = ' ';
// 	char null = '\0';
// 	char del = 127;
// 	char zero = '0';
// 	char equal = '=';
// 	char plus = '+';
// 	char line = '\n';
// 	char one = '1';
// 	char nine = '9';

// 	printf("a = %d\n", ft_isprint(a));
// 	printf("b = %d\n", ft_isprint(b));
// 	printf("z = %d\n", ft_isprint(z));
// 	printf("A = %d\n", ft_isprint(A));
// 	printf("B = %d\n", ft_isprint(B));
// 	printf("Z = %d\n", ft_isprint(Z));
// 	printf("space = %d\n", ft_isprint(space));
// 	printf("null = %d\n", ft_isprint(null));
// 	printf("del = %d\n", ft_isprint(del));
// 	printf("zero = %d\n", ft_isprint(zero));
// 	printf("equal = %d\n", ft_isprint(equal));
// 	printf("plus = %d\n", ft_isprint(plus));
// 	printf("line = %d\n", ft_isprint(line));
// 	printf("one = %d\n", ft_isprint(one));
// 	printf("nine = %d\n", ft_isprint(nine));

// 	return (0);
// }