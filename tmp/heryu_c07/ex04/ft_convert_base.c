/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heryu <heryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 13:41:46 by heryu             #+#    #+#             */
/*   Updated: 2020/07/14 00:20:26 by heryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		is_space(char ch)
{
	if (ch == '\t' || ch == '\n' || ch == '\v')
		return (1);
	if (ch == '\f' || ch == '\r' || ch == ' ')
		return (1);
	return (0);
}

int		ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int		is_valid_base(char *base)
{
	unsigned char	check_dup[256];
	int				i;
	unsigned char	ch;

	if (ft_strlen(base) <= 1)
		return (0);
	i = 0;
	while (i < 256)
		check_dup[i++] = 0;
	i = 0;
	while (base[i] != '\0')
	{
		ch = *((unsigned char*)base + i);
		if (ch == '+' || ch == '-')
			return (0);
		check_dup[ch]++;
		if (check_dup[ch] > 1)
			return (0);
		i++;
	}
	return (1);
}

int		base_to_int(char *nbr, char *base)
{
	int		ret;
	int		i;
	int		j;
	int		search_flag;

	ret = 0;
	i = 0;
	while (nbr[i] != '\0')
	{
		j = 0;
		search_flag = -1;
		while (base[j] != '\0')
		{
			if (nbr[i] == base[j])
			{
				ret = (ret * ft_strlen(base)) + j;
				search_flag = 1;
			}
			j++;
		}
		if (search_flag == -1)
			break ;
		i++;
	}
	return (ret);
}

char	*int_to_base(int nbr, char *base, int sign);

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		i;
	int		sign;
	int		n;
	char	*ret;

	if (!is_valid_base(base_from) || !is_valid_base(base_to))
		return ((void*)0);
	i = 0;
	sign = 1;
	while (is_space(nbr[i]))
		i++;
	while (nbr[i] == '-' || nbr[i] == '+')
		if (nbr[i++] == '-')
			sign *= -1;
	n = base_to_int(&nbr[i], base_from);
	ret = int_to_base(n, base_to, sign);
	return (ret);
}
