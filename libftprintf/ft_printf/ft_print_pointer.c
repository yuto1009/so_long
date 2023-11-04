/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuendo <yuendo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 20:03:59 by yutoendo          #+#    #+#             */
/*   Updated: 2023/06/28 16:08:58 by yuendo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	put_hex_pointer(void *p)
{
	const char			*hex;
	unsigned long long	address;
	char				str[19];
	int					i;
	int					str_length;

	hex = "0123456789abcdef";
	address = (unsigned long long)p;
	str[0] = '0';
	str[1] = 'x';
	i = 18;
	while (i > 1)
	{
		str[i--] = hex[address % 16];
		address /= 16;
	}
	i = 2;
	while (str[i] == '0' && i < 18)
		i++;
	write(STDOUT_FILENO, str, 2);
	write(STDOUT_FILENO, str + i, 19 - i);
	str_length = 21 - i;
	return (str_length);
}

int	print_pointer(va_list args)
{
	void	*p;
	int		str_length;

	p = va_arg(args, void *);
	str_length = put_hex_pointer(p);
	return (str_length);
}
