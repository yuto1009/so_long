/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yutoendo <yutoendo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 17:01:37 by yutoendo          #+#    #+#             */
/*   Updated: 2023/09/05 17:09:12 by yutoendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "so_long.h"

void is_valid_map(char **map)
{   
    is_valid_map_shape(map);
    is_map_walled(map); 
    is_valid_map_elements(map); 
}