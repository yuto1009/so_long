/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuendo <yuendo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 20:03:26 by yutoendo          #+#    #+#             */
/*   Updated: 2023/06/28 16:09:13 by yuendo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_str(va_list args)
{
	char	*s;

	s = va_arg(args, char *);
	if (!s)
	{
		write(STDOUT_FILENO, "(null)", 6);
		return (6);
	}
	else if (*s == '\0')
	{
		return (NULL_EXCEPTION);
	}
	ft_putstr_fd(s, STDOUT_FILENO);
	return ((int)ft_strlen(s));
}
