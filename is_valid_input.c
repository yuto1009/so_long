/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yutoendo <yutoendo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 17:02:31 by yutoendo          #+#    #+#             */
/*   Updated: 2023/08/04 14:02:14 by yutoendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void is_valid_input_argc(int argc)
{
    if (argc != CORRECT_ARGC){  // 引数の数が正しいか確認
        ft_printf("\x1b[31mError\nInvalid arguments\n\x1b[0m");  
        exit(EXIT_FAILURE); // このマクロはstdlib.hで定義されてる
    }
}

static void is_valid_file_extension(char *argv[])
{   
    if (ft_strnstr(argv[MAP_ARGC], MAP_EXTENTION, ft_strlen(argv[MAP_ARGC])) == NULL)  // 拡張子を確認
    {  
        ft_printf("Error\nInvalid file extension\n");
        exit(EXIT_FAILURE); 
    }
}

void is_valid_input(int argc, char *argv[])
{   
    is_valid_input_argc(argc);  // 引数の数が一つか確認
    is_valid_file_extension(argv);  // マップを格納するファイルの形式を確認
}