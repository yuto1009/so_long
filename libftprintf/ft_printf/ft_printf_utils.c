/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yutoendo <yutoendo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 19:58:04 by yutoendo          #+#    #+#             */
/*   Updated: 2023/09/15 15:16:01 by yutoendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_format_specifier(char format, va_list args)
{
	int	str_length;

	str_length = 0;
	if (format == 'c')
		str_length = print_char(args);
	else if (format == 's')
		str_length = print_str(args);
	else if (format == 'p')
		str_length = print_pointer(args);
	else if (format == 'd' || format == 'i')
		str_length = print_integer(args);
	else if (format == 'u')
		str_length = print_unsigned_int(args);
	else if (format == 'x')
		str_length = print_lower_hex(args);
	else if (format == 'X')
		str_length = print_upper_hex(args);
	else if (format == '%')
	{
		ft_putchar_fd('%', STDOUT_FILENO);
		str_length++;
	}
	else
		str_length = MALLOC_FAILURE_OR_UNHANDLED_FORMAT;
	return (str_length);
}

static char	*args_increment(int is_format_specifier, char *str)
{
	if (is_format_specifier > 0 || is_format_specifier == NULL_EXCEPTION)
		str++;
	if (*str != '\0')
		str++;
	return (str);
}

int	is_valid_args_utils(char *str, va_list args,
		int is_format_specifier, int str_length)
{
	while (str && *str)
	{
		if (*str == '%' && (str + 1) && *(str + 1))
		{
			is_format_specifier = print_format_specifier(*(str + 1), args);
			if (is_format_specifier == MALLOC_FAILURE_OR_UNHANDLED_FORMAT)
				return (str_length);
			if (is_format_specifier != NULL_EXCEPTION)
				str_length += is_format_specifier;
		}
		else if (*str == '%')
			return (str_length);
		else
		{
			ft_putchar_fd(*str, STDOUT_FILENO);
			str_length++;
		}
		str = args_increment(is_format_specifier, str);
		is_format_specifier = 0;
	}
	return (str_length);
}
