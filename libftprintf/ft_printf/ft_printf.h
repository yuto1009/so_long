/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yutoendo <yutoendo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 12:48:53 by yuendo            #+#    #+#             */
/*   Updated: 2023/10/21 23:22:59 by yutoendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

# define MALLOC_FAILURE_OR_UNHANDLED_FORMAT -1
# define NULL_EXCEPTION -2

int	ft_printf(const char *format, ...);
int	is_valid_args_utils(char *str, va_list args,
		int is_format_specifier, int str_length);
int	print_upper_hex(va_list args);
int	print_lower_hex(va_list args);
int	print_unsigned_int(va_list args);
int	print_integer(va_list args);
int	print_pointer(va_list args);
int	print_str(va_list args);
int	print_char(va_list args);

#endif