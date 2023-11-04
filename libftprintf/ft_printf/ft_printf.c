/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yutoendo <yutoendo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 12:45:43 by yuendo            #+#    #+#             */
/*   Updated: 2023/11/04 17:14:01 by yutoendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	is_valid_args(char *str, va_list args)
{
	int	is_format_specifier;
	int	str_length;

	is_format_specifier = 0;
	str_length = 0;
	str_length = is_valid_args_utils(str, args, is_format_specifier,
			str_length);
	return (str_length);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	va_list	args_copy;
	int		str_length;
	char	*str_copy;

	str_copy = (char *)str;
	if (!str)
		return (0);
	va_start(args, str);
	va_copy(args_copy, args);
	str_length = is_valid_args(str_copy, args);
	va_end(args);
	if (!str_length)
		return (0);
	return (str_length);
}
