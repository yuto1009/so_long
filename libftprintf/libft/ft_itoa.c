/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuendo <yuendo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 12:29:50 by yuendo            #+#    #+#             */
/*   Updated: 2023/05/25 15:53:16 by yuendo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	my_getdigit(long int n)
{
	unsigned int	digit;

	digit = 0;
	if (n <= 0)
	{
		n /= -1;
		digit++;
	}
	while (n > 0)
	{
		n /= 10;
		digit++;
	}
	return (digit);
}

static char	my_tostr(int n)
{
	char	s;

	s = n + '0';
	return (s);
}

char	*ft_itoa(int num)
{
	char			*s;
	unsigned int	digit;
	unsigned int	i;
	long int		n;

	n = num;
	digit = my_getdigit(n);
	s = malloc(sizeof(char) * (digit + 1));
	if (!s)
		return (NULL);
	if (n < 0)
	{
		s[0] = '-';
		n /= -1;
	}
	s[digit] = '\0';
	i = digit - 1;
	if (n == 0)
		s[i] = '0';
	while (n > 0)
	{
		s[i--] = my_tostr(n % 10);
		n /= 10;
	}
	return (s);
}
