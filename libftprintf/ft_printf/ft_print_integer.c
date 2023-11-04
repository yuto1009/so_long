/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_integer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuendo <yuendo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 20:05:28 by yutoendo          #+#    #+#             */
/*   Updated: 2023/06/30 12:23:17 by yuendo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_integer(va_list args)
{
	int		num;
	char	*s;
	int		str_length;

	num = va_arg(args, int);
	s = ft_itoa(num);
	if (!s)
		return (MALLOC_FAILURE_OR_UNHANDLED_FORMAT);
	ft_putstr_fd(s, STDOUT_FILENO);
	str_length = (int)ft_strlen(s);
	free(s);
	return (str_length);
}
