/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_frac_util.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyekim <kyekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 12:02:39 by kyekim            #+#    #+#             */
/*   Updated: 2021/02/27 12:02:41 by kyekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_fctoc(t_fraction *f, int len)
{
	int	index;

	index = f->man_len - len - 1;
	if (index < -1)
		index = -1;
	while (++index < f->man_len)
		f->man[index] += '0';
}

void	ft_plus_10pow(t_fraction *f, int exp)
{
	++(f->man[exp--]);
	while (f->man[++exp] > 9)
	{
		++(f->man[exp + 1]);
		f->man[exp] -= 10;
	}
	if (exp > f->man_len)
		f->man_len = exp;
	while (f->man[f->man_len])
		++(f->man_len);
}

void	ft_round_off(t_fraction *f, int exp)
{
	int			backup_len;
	int			i;

	exp = f->man_len - 2 - exp;
	if (exp < 0)
		return ;
	if (f->man[exp] > 4)
	{
		if (f->man[exp] == 5)
		{
			i = exp;
			while (--i > -1)
				if (f->man[i])
					break ;
			if (i == -1 && !(f->man[exp + 1] & 1))
				return ;
		}
		backup_len = f->man_len;
		ft_plus_10pow(f, ++exp);
		if (f->man_len != backup_len)
			++(f->exp);
	}
}

int		ft_put_prepad(t_form *form)
{
	int	result;

	result = 0;
	if (*form->padc != '0' && !form->ladjust)
		while (form->width-- > 0)
			result += (int)write(1, " ", 1);
	if (form->sign)
		result += (int)write(1, &(form->sign), 1);
	if (!form->ladjust)
		while (form->width-- > 0)
			result += (int)write(1, "0", 1);
	return (result);
}
