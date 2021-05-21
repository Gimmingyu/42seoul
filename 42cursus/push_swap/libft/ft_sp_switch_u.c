/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sp_switch_u.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyekim <kyekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 15:08:49 by kyekim            #+#    #+#             */
/*   Updated: 2021/05/12 15:08:50 by kyekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_sp_wu_0(t_arg *arg)
{
	char *str;

	if (!(str = ft_strnew(arg->print_size)))
		return (0);
	ft_memset(str, ' ', arg->print_size);
	ft_memcpy(str, arg->old_print, arg->old_print_size);
	ft_memcpy(str + arg->old_print_size, arg->print + arg->old_print_size,
			arg->print_size - arg->old_print_size);
	free(arg->print);
	arg->print = str;
	return (1);
}

int	ft_sp_ws(t_arg *arg)
{
	char *str;

	if (!(str = ft_strnew(arg->print_size + 1)))
		return (0);
	ft_memcpy(str, arg->old_print, arg->old_print_size);
	ft_memcpy(str + arg->old_print_size, arg->print + 1, arg->print_size - 1);
	free(arg->print);
	arg->print = str;
	return (1);
}

int	ft_sp_sup(t_arg *arg, int i)
{
	char *str;

	if (!(str = ft_strnew(arg->print_size)))
		return (0);
	ft_memset(str, ' ', arg->print_size);
	ft_memcpy(str + i - arg->old_print_size,
			arg->old_print, arg->old_print_size);
	ft_memcpy(str + i, arg->print + i, arg->print_size - i);
	free(arg->print);
	arg->print = str;
	return (1);
}

int	ft_sp_lsp(t_arg *arg)
{
	char *str;

	if (arg->print[arg->print_size - 1] == ' '
			&& arg->print[arg->print_size - 2] == ' ')
	{
		if (!(str = ft_strnew(arg->print_size)))
			return (0);
		ft_memset(str, ' ', arg->print_size);
		ft_memcpy(str, arg->old_print, arg->old_print_size);
		ft_memcpy(str + arg->old_print_size,
		arg->print, arg->print_size - arg->old_print_size);
	}
	else
	{
		if (!(str = ft_strnew(arg->print_size + 1)))
			return (0);
		ft_memset(str, ' ', arg->print_size);
		ft_memcpy(str, arg->old_print, arg->old_print_size);
		ft_memcpy(str + arg->old_print_size,
		arg->print, arg->print_size - 1);
	}
	free(arg->print);
	arg->print = str;
	return (1);
}
