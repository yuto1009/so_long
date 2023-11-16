/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_game_data.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yutoendo <yutoendo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 22:07:19 by yutoendo          #+#    #+#             */
/*   Updated: 2023/11/16 22:12:40 by yutoendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

t_data *initialize_game_data(void)
{
    t_data *game_data;
    
    game_data = (t_data *)ft_calloc(1, sizeof(t_data));
	if (game_data == NULL)
		error_exit(MALLOC_ERROR);
    
    return (game_data);
}
