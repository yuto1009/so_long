/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yutoendo <yutoendo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 13:30:04 by yuendo            #+#    #+#             */
/*   Updated: 2023/11/04 17:14:08 by yutoendo         ###   ########.fr       */
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
