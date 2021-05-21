/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyekim <kyekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 14:59:46 by kyekim            #+#    #+#             */
/*   Updated: 2021/05/12 14:59:47 by kyekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void*, size_t))
{
	if (alst == NULL || del == NULL)
		return ;
	if (((*alst)->next) != NULL)
		ft_lstdel(&((*alst)->next), del);
	ft_lstdelone(alst, del);
}
