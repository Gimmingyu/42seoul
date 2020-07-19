/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jipark <jipark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 08:46:15 by jipark            #+#    #+#             */
/*   Updated: 2020/01/28 10:51:13 by jipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		get_base_length(char *base)
{
	int i;
	int j;

	i = 0;
	while (base[i] != '\0')
	{
		j = i + 1;
		if (base[i] == '-' || base[i] == '+')
			return (0);
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

void	print_base_number(long long safe_nbr, char *base, int length)
{
	if (0 <= safe_nbr && safe_nbr < length)
	{
		write(1, &base[safe_nbr], 1);
	}
	else
	{
		print_base_number(safe_nbr / length, base, length);
		write(1, &base[safe_nbr % length], 1);
	}
}

void	ft_putnbr_base(int nbr, char *base)
{
	long long	safe_nbr;
	int			base_length;

	safe_nbr = (long long)nbr;
	base_length = get_base_length(base);
	if (!base_length)
		return ;
	if (safe_nbr < 0)
	{
		write(1, "-", 1);
		safe_nbr *= -1;
	}
	print_base_number(safe_nbr, base, base_length);
}
