/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuendo <yuendo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 17:02:31 by yutoendo          #+#    #+#             */
/*   Updated: 2023/08/23 12:31:23 by yuendo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void is_valid_input_argc(int argc)
{
    if (argc != CORRECT_ARGC){  
        ft_printf("\x1b[31mError\nInvalid arguments\n\x1b[0m");  
        exit(EXIT_FAILURE); 
    }
}

static void is_valid_file_extension(char *argv[])
{   
    if (ft_strnstr(argv[MAP_ARGC], MAP_EXTENTION, ft_strlen(argv[MAP_ARGC])) == NULL) 
    {  
        ft_printf("Error\nInvalid file extension\n");
        exit(EXIT_FAILURE); 
    }
}

void is_valid_input(int argc, char *argv[])
{   
    is_valid_input_argc(argc); 
    is_valid_file_extension(argv);  
}