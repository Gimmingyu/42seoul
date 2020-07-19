/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jipark <jipark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 17:49:15 by jipark            #+#    #+#             */
/*   Updated: 2020/02/01 10:42:19 by jipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		is_valid(char str, char *base, int *sum)
{
	int i;

	i = 0;
	while (base[i] != '\0')
	{
		if (str == base[i])
		{
			*sum = i;
			return (1);
		}
		i++;
	}
	return (0);
}

int		get_base_len(char *base)
{
	unsigned int i;
	unsigned int j;

	i = 0;
	while (base[i] != '\0')
	{
		if (base[i] == '-' || base[i] == '+')
			return (0);
		if (base[i] == ' ' || (9 <= base[i] && base[i] <= 13))
			return (0);
		j = i + 1;
		while (base[j] != '\0')
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	if (i < 2)
		return (0);
	return (i);
}

int		ft_atoi_base(char *nbr, char *base)
{
	int count;
	int flag;
	int sum;
	int result;

	result = 0;
	flag = 1;
	count = 0;
	while (nbr[count] == ' ' || (9 <= nbr[count] && nbr[count] <= 13))
		count++;
	while (nbr[count] == '-' || nbr[count] == '+')
	{
		if (nbr[count] == '-')
			flag *= -1;
		count++;
	}
	while (is_valid(nbr[count], base, &sum))
	{
		result = (result * get_base_len(base)) + sum;
		count++;
	}
	return (flag * result);
}

void	convert_dest(int number, char *dest, char *base, int index)
{
	unsigned int	tmp;
	unsigned int	base_len;

	base_len = 0;
	while (base[base_len] != '\0')
		base_len++;
	if (number < 0)
	{
		dest[0] = '-';
		tmp = number * -1;
	}
	else
		tmp = number;
	if (tmp >= base_len)
		convert_dest(tmp / base_len, dest, base, index - 1);
	dest[index] = base[tmp % base_len];
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	char	*dest;
	int		number;
	int		convert_len;
	int		tmp;
	int		base_len;

	if (!get_base_len(base_from) || !get_base_len(base_to))
		return (0);
	number = ft_atoi_base(nbr, base_from);
	convert_len = 1;
	tmp = number;
	base_len = get_base_len(base_to);
	while (tmp != 0)
	{
		tmp /= base_len;
		convert_len++;
	}
	if (number == 0 || number < 0)
		convert_len = convert_len + 1;
	dest = (char *)malloc(sizeof(char) * convert_len);
	convert_dest(number, dest, base_to, convert_len - 2);
	dest[convert_len - 1] = '\0';
	return (dest);
}
