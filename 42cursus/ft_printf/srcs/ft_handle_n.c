/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_n.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyekim <kyekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 12:03:04 by kyekim            #+#    #+#             */
/*   Updated: 2021/02/27 12:03:06 by kyekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_sub_handle_n(t_form *form)
{
	short int		*hp;
	char			*hhp;

	if (form->hhll == -2)
	{
		hhp = va_arg(form->va_para, char *);
		*hhp = (char)(form->result);
	}
	else if (form->hhll == -1)
	{
		hp = va_arg(form->va_para, short int *);
		*hp = (short int)(form->result);
	}
}

int		ft_handle_n(t_form *form)
{
	long long int	*llp;
	long int		*lp;
	int				*p;

	if (form->hhll == 2)
	{
		llp = va_arg(form->va_para, long long int *);
		*llp = (long long int)(form->result);
	}
	else if (form->hhll == 1)
	{
		lp = va_arg(form->va_para, long int *);
		*lp = (long int)(form->result);
	}
	else if (form->hhll == 0)
	{
		p = va_arg(form->va_para, int *);
		*p = form->result;
	}
	else
		ft_sub_handle_n(form);
	return (0);
}
