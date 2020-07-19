/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jipark <jipark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 15:55:15 by jipark            #+#    #+#             */
/*   Updated: 2020/02/28 15:55:15 by jipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list *head;
	t_list *new_lst;

	if (!lst || !(new_lst = ft_lstnew(f(lst->content))))
		return (0);
	head = new_lst;
	lst = lst->next;
	while (lst)
	{
		if (!(new_lst->next = ft_lstnew(f(lst->content))))
		{
			ft_lstclear(&head, del);
			return (0);
		}
		new_lst = new_lst->next;
		lst = lst->next;
	}
	return (head);
}
