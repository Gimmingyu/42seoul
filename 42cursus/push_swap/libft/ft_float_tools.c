/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_float_tools.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyekim <kyekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 14:55:39 by kyekim            #+#    #+#             */
/*   Updated: 2021/05/12 14:55:40 by kyekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char		*ft_bin_mant(unsigned long long i, int size)
{
	char	*str;
	int		k;
	int		j;

	j = 0;
	if (!(str = ft_strnew(size)))
		return (NULL);
	while (--size >= 0)
	{
		k = i >> size;
		if (k & 1)
			str[j] = '1';
		else
			str[j] = '0';
		j++;
	}
	return (str);
}

long double	ft_get_mant(unsigned long long nb)
{
	double	f;
	int		j;
	int		i;
	int		k;

	i = 64;
	j = 1;
	f = 0;
	i--;
	while (i >= 0)
	{
		k = nb >> i;
		if (k & 1)
			f += 1 / (long double)ft_pow(2, j);
		j++;
		i--;
	}
	return (f);
}

char		*ft_calc_mant(char **tab_mant, t_arg *arg, int i)
{
	int		j;
	int		ret;
	int		tmp;
	char	*str;

	if (!(str = ft_strnew(66 + arg->precision)))
		return (NULL);
	str = ft_memset(str, '0', 66 + arg->precision);
	while (i < 64)
	{
		tmp = 0;
		ret = 0;
		j = 65;
		while (j >= 0)
		{
			tmp = (str[j] - 48) + (tab_mant[i][j] - 48) + ret;
			ret = tmp > 9 ? 1 : 0;
			str[j] = tab_mant[i][j] == '.' ? '.' : (tmp % 10) + 48;
			j--;
			tmp = 0;
		}
		i++;
	}
	return (str);
}

char		*ft_float_zero(t_arg *arg)
{
	char *str;

	if (!(str = ft_strnew(65 + arg->precision)))
		return (NULL);
	ft_memset(str, '0', 65 + arg->precision);
	str[1] = '.';
	return (str);
}

char		*ft_mant(char *mantissa, t_arg *arg, int i)
{
	char **tab_mant;
	char *str_return;
	char *str;

	str = ft_strdup(mantissa);
	if (!(tab_mant = (char**)malloc(sizeof(char*) * 66 + arg->precision)))
		return (NULL);
	str_return = NULL;
	while (++i < 64)
	{
		if (str[i] == '1')
			tab_mant[i] = ft_fdtoa(1 / ft_pow(2, i + 1), 64 + arg->precision);
		else
		{
			if (!(tab_mant[i] = ft_strnew(65 + arg->precision)))
				return (NULL);
			tab_mant[i] = ft_memset(tab_mant[i], '0', 66 + arg->precision);
		}
	}
	tab_mant[i] = NULL;
	i = -1;
	str_return = !ft_strchr(mantissa, '1') ? ft_float_zero(arg) :
		ft_calc_mant(tab_mant, arg, 0);
	ft_free_arg(tab_mant, str);
	return (str_return);
}
