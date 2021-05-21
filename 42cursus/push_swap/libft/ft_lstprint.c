/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstprint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyekim <kyekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 15:00:35 by kyekim            #+#    #+#             */
/*   Updated: 2021/05/12 15:00:36 by kyekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstprint(t_list *alst)
{
	while (alst)
	{
		ft_putstr((char*)(alst->content));
		ft_putstr(" / ");
		ft_putnbr((int)alst->content_size);
		ft_putstr("\t->\t");
		alst = alst->next;
	}
	ft_putstr("NULL");
}
