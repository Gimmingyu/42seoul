/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghwki <donghwki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 15:59:22 by donghwki          #+#    #+#             */
/*   Updated: 2020/01/31 16:28:36 by donghwki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

unsigned int	base_check(char *base)
{
	unsigned int len;
	unsigned int i;
	unsigned int j;

	len = 0 - 1;
	while (base[++len])
	{
		if (base[len] == '+' || base[len] == '-' ||
		base[len] == ' ' || (base[len] >= 9 && base[len] <= 13))
			return (0);
	}
	if (len < 2)
		return (0);
	i = 0 - 1;
	while (++i < len - 1)
	{
		j = i + 1 - 1;
		while (++j < len)
			if (base[i] == base[j])
				return (0);
	}
	return (len);
}

int				is_in_base(char *base, char c, int *sum)
{
	unsigned int i;

	i = 0;
	while (base[i])
	{
		if (base[i] == c)
		{
			*sum = i;
			return (1);
		}
		i++;
	}
	return (0);
}

int				get_num(char *nbr, char *base_from, unsigned int len)
{
	int	result;
	int	i;
	int sign;
	int sum;

	result = 0;
	i = 0;
	sign = 1;
	while (nbr[i] == ' ' || (nbr[i] >= 9 && nbr[i] <= 13))
		i++;
	while (nbr[i] == '+' || nbr[i] == '-')
		if (nbr[i++] == '-')
			sign *= -1;
	while (is_in_base(base_from, nbr[i], &sum))
	{
		result = result * len + sum;
		i++;
	}
	return (result * sign);
}

char			*get_convert(long decimal, char *base_to, int len, int b_len)
{
	char	*convert_str;
	int		i;
	int		index;
	int		sign;

	sign = decimal < 0 ? 1 : 0;
	decimal = decimal < 0 ? decimal * -1 : decimal;
	i = len + sign;
	convert_str = (char *)malloc(sizeof(char) * len + 1 + sign);
	convert_str[i] = 0;
	if (sign)
		convert_str[0] = '-';
	while (i > sign)
	{
		index = decimal % b_len;
		decimal /= b_len;
		convert_str[--i] = base_to[index];
	}
	return (convert_str);
}

char			*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	unsigned int	base_len;
	unsigned int	out_len;
	int				decimal;
	unsigned int	temp;

	base_len = base_check(base_from);
	if (!base_len)
		return (0);
	decimal = get_num(nbr, base_from, base_len);
	base_len = base_check(base_to);
	if (!base_len)
		return (0);
	temp = decimal < 0 ? decimal * -1 : decimal;
	out_len = !decimal ? 1 : 0;
	while (temp)
	{
		temp /= base_len;
		out_len++;
	}
	return (get_convert((long)decimal, base_to, out_len, base_len));
}
