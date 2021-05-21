/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyekim <kyekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 20:42:57 by kyekim            #+#    #+#             */
/*   Updated: 2021/02/27 11:53:57 by kyekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlist;
	t_list	*first;

	if (!lst || !(newlist = ft_lstnew(f(lst->content))))
		return (0);
	first = newlist;
	while (lst->next)
	{
		if (!(newlist->next = ft_lstnew(f(lst->next->content))))
		{
			ft_lstclear(&first, del);
			return (0);
		}
		newlist = newlist->next;
		lst = lst->next;
	}
	return (first);
}
