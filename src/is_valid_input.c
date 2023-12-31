/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yutoendo <yutoendo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 17:42:35 by yuendo            #+#    #+#             */
/*   Updated: 2023/11/16 22:47:59 by yutoendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static bool	is_valid_input_argc(int argc)
{
	if (argc != CORRECT_ARGC)
	{
		return (false);
	}
	return (true);
}

static bool	is_valid_file_extension(char *argv[])
{
	if (ft_strnstr(argv[MAP_ARGC], MAP_EXTENTION,
			ft_strlen(argv[MAP_ARGC])) == NULL)
	{
		return (false);
	}
	return (true);
}

void	is_valid_input(int argc, char *argv[])
{
	if (is_valid_input_argc(argc) == false
		|| is_valid_file_extension(argv) == false)
	{
		error_exit(INVALID_ARGS);
	}
}