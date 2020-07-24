/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyekim <kyekim@student.42seoul.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/17 19:30:48 by kyekim            #+#    #+#             */
/*   Updated: 2020/07/19 13:57:34 by kyekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	get_condition(char *base)
{
	unsigned int len;
	unsigned int i;
	unsigned int j;

	len = 0;
	while (base[len])
	{
		if (base[len] == '+' || base[len] == '-')
			return (0);
		if (base[len] == ' ' || (base[len] >= 8 && base[len] <= 13))
			return (0);
		len++;
	}
	if (len <= 1)
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

int				is_in_base(char *base, char c, unsigned int *sum)
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

int				get_number(char *str, char *base, unsigned int len)
{
	unsigned int	i;
	unsigned int	sum;
	int				flag;
	int				result;

	i = 0;
	flag = 1;
	result = 0;
	while (str[i] == 32 || (str[i] >= 8 && str[i] <= 13))
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			flag *= -1;
		i++;
	}
	while (is_in_base(base, str[i], &sum))
	{
		result = result * len + sum;
		i++;
	}
	return (result * flag);
}

int				ft_atoi_base(char *str, char *base)
{
	unsigned int	len;
	int				result;

	len = get_condition(base);
	if (!len)
		return (0);
	result = get_number(str, base, len);
	return (result);
}
