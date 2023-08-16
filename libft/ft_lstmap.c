/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuendo <yuendo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 14:57:01 by yuendo            #+#    #+#             */
/*   Updated: 2023/07/06 16:49:21 by yuendo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlst;
	t_list	*newnode;

	if (lst == NULL || f == NULL || del == NULL)
		return (NULL);
	newlst = NULL;
	while (lst)
	{
		newnode = malloc(sizeof(t_list));
		if (newnode == NULL)
		{
			ft_lstclear(&newlst, del);
			return (NULL);
		}
		newnode->content = f(lst->content);
		if (newnode->content == NULL)
		{
			del(newnode->content);
			free(newnode);
			ft_lstclear(&newlst, del);
			return (NULL);
		}
		ft_lstadd_back(&newlst, newnode);
		lst = lst->next;
	}
	return (newlst);
}
