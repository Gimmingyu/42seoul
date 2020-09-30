/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyekim <kyekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/01 00:28:26 by kyekim            #+#    #+#             */
/*   Updated: 2020/10/01 00:31:04 by kyekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_head;
	t_list	*cur;
	t_list	*tmp;

	if (lst == 0 || f == 0)
		return (0);
	if ((new_head = ft_lstnew(f(lst->content))) == 0)
		return (0);
	cur = new_head;
	lst = lst->next;
	while (lst)
	{
		if ((tmp = ft_lstnew(f(lst->content))) == 0)
		{
			ft_lstclear(&new_head, del);
			return (0);
		}
		cur->next = tmp;
		cur = tmp;
		lst = lst->next;
	}
	return (new_head);
}
