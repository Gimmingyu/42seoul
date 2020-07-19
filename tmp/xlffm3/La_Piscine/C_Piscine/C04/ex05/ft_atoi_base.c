/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jipark <jipark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 12:57:06 by jipark            #+#    #+#             */
/*   Updated: 2020/01/28 16:37:47 by jipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int				check_validation(char *base, char txt, unsigned int *sum)
{
	unsigned int i;

	i = 0;
	while (base[i] != '\0')
	{
		if (base[i] == txt)
		{
			*sum = i;
			return (1);
		}
		i++;
	}
	return (0);
}

unsigned int	get_base_length(char *base)
{
	unsigned int i;
	unsigned int j;

	i = 0;
	while (base[i] != '\0')
	{
		if (base[i] == '+' || base[i] == '-')
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

int				get_number(char *str, char *base, unsigned int base_length)
{
	unsigned int	sum;
	unsigned int	count;
	int				result;
	int				flag;

	count = 0;
	result = 0;
	flag = 1;
	while (str[count] == 32 || (9 <= str[count] && str[count] <= 13))
		count++;
	while (str[count] == '-' || str[count] == '+')
	{
		if (str[count] == '-')
			flag *= -1;
		count++;
	}
	while (check_validation(base, str[count], &sum))
	{
		result = (result * base_length) + sum;
		count++;
	}
	return (result * flag);
}

int				ft_atoi_base(char *str, char *base)
{
	unsigned int	base_length;
	int				result;

	base_length = get_base_length(base);
	if (!base_length)
		return (0);
	result = get_number(str, base, base_length);
	return (result);
}
