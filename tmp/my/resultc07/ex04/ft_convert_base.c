/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyekim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 14:29:33 by kyekim            #+#    #+#             */
/*   Updated: 2020/07/16 14:30:32 by kyekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int		get_base_number(char c, char *base);
void	compact(char *arr, int interval);
void	init_arr(char *arr, int size);
int		get_length(char *str);

int		is_valid(char *base)
{
	int i;
	int j;

	if (base[0] == '\0' || base[1] == '\0')
		return (0);
	i = 0;
	while (base[i] != '\0')
	{
		if (base[i] == '+' || base[i] == '-'
				|| base[i] == '\n' || base[i] == '\v'
				|| base[i] == '\t' || base[i] == '\f'
				|| base[i] == '\r' || base[i] == ' ')
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
	return (1);
}

int		check_char(char c, char *base)
{
	int i;

	if (c == '\t' || c == '\n'
			|| c == '\v' || c == '\f'
			|| c == '\r' || c == ' ')
		return (1);
	if (c == '-')
		return (-1);
	if (c == '+')
		return (-2);
	i = 0;
	while (base[i] != '\0')
	{
		if (c == base[i++])
			return (2);
	}
	return (0);
}

int		base_to_int(char *str, char *base, int length)
{
	int index;
	int count;
	int result;

	index = 0;
	while (check_char(str[index], base) == 1)
		index++;
	count = 1;
	while (check_char(str[index], base) < 0)
	{
		if (check_char(str[index], base) == -1)
			count *= -1;
		index++;
	}
	if (check_char(str[index], base) != 2)
		return (0);
	result = get_base_number(str[index++], base);
	length = get_length(base);
	while (check_char(str[index], base) == 2)
		result = result * length + get_base_number(str[index++], base);
	return (result * count);
}

char	*int_to_base(int nbr, char *base, int len)
{
	char	*result;
	int		i;

	result = (char *)malloc(sizeof(char) * 34);
	i = 0;
	while (i < 34)
		result[i++] = 0;
	if (nbr < 0)
	{
		result[0] = '-';
		nbr = nbr * (-1);
	}
	i = 33;
	while (nbr / len)
	{
		result[i] = base[nbr % len];
		nbr /= len;
		i--;
	}
	result[i] = base[nbr % len];
	compact(result, i);
	return (result);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int			len_from;
	int			len_to;
	int			temp;

	len_from = get_length(base_from);
	len_to = get_length(base_to);
	if (!is_valid(base_from) || !is_valid(base_to))
		return (0);
	temp = base_to_int(nbr, base_from, len_from);
	return (int_to_base(temp, base_to, len_to));
}
