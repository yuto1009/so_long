/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yutoendo <yutoendo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 18:05:31 by yutoendo          #+#    #+#             */
/*   Updated: 2023/07/05 22:18:16 by yutoendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list *ft_lstnew(void *content){
    t_list *new_list;

    new_list = malloc(sizeof(t_list));
    if(new_list == NULL)
        return NULL;
    new_list->content = content;
    new_list->next = NULL;
    return new_list;
}