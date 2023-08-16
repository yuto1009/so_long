/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yutoendo <yutoendo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 13:30:04 by yuendo            #+#    #+#             */
/*   Updated: 2023/07/05 17:55:49 by yutoendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_overflow(long num, int sign, const char *str)
{
	int	digit;

	while (ft_isdigit((unsigned char)*str))
	{
		digit = *str - '0';
		if (sign > 0 && (LONG_MAX - digit) / 10 < num)
			return (-1);
		if (sign < 0 && (LONG_MIN + digit) / 10 > -num)
			return (0);
		num = num * 10 + digit;
		str++;
	}
	return ((int)num * sign);
}

int	ft_atoi(const char *str)
{
	int		sign;
	long	num;

	sign = 1;
	num = 0;
	while (*str == ' ' || *str == '\t' || *str == '\n' || *str == '\v'
		|| *str == '\f' || *str == '\r')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	return (is_overflow(num, sign, str));
}

// #include <string.h>
// #include <stdio.h>
// #include <stdlib.h>
// #include <limits.h>
// int    main(void)
// {
//     char *str1 = "        ---+--+1234ab567";
//     char *str2 = "2147483649";
//     char *str3 = "2147483647";
//     char *str4 = "--++-+-23r90";
//     char *str5 = "++1234";
//     char *str6 = "**1234";
//     char *str7 = "9223372036854775808";
//     char *str8 = "-9223372036854775808";
//     char *str9 = "922337203685477580899999999764479099898765678765676433453";
//     char *str10 = "-9223372036854775810";
//     char *str11 = "18446744073709551616";

//     printf("ft vs original\n");
//     printf("%s :    %d %d\n", str1, ft_atoi(str1), atoi(str1));
//     printf("%s :    %d %d\n", str2, ft_atoi(str2), atoi(str2));
//     printf("%s :    %d %d\n", str3, ft_atoi(str3), atoi(str3));
//     printf("%s :    %d %d\n", str4, ft_atoi(str4), atoi(str4));
//     printf("%s :    %d %d\n", str5, ft_atoi(str5), atoi(str5));
//     printf("%s :    %d %d\n", str6, ft_atoi(str6), atoi(str6));
//     printf("%s :    %d %d\n", str7, ft_atoi(str7), atoi(str7));
//     printf("%s :    %d %d\n", str8, ft_atoi(str8), atoi(str8));
//     printf("%s :    %d %d\n", str9, ft_atoi(str9), atoi(str9));
//     printf("%s :    %d %d\n", str10, ft_atoi(str10), atoi(str10));
//     printf("%s :    %d %d\n", str11, ft_atoi(str11), atoi(str11));
//     printf("%ld\n", LONG_MAX);
//     printf("%ld\n", LONG_MIN);
//     printf("%llu\n", ULLONG_MAX);
//     return (0);
// }