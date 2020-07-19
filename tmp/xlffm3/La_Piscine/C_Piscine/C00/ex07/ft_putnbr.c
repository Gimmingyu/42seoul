/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jipark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 12:12:37 by jipark            #+#    #+#             */
/*   Updated: 2020/01/23 12:33:02 by jipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	set_digits_arr(char *arr, int *i, int *nb)
{
	while (*(i) < 10)
	{
		if (*(nb) < 0)
		{
			arr[*(i)] = (char)(-1 * ((*(nb) % 10)) + 48);
		}
		else
		{
			arr[*(i)] = (char)((*(nb) % 10) + 48);
		}
		*(nb) /= 10;
		*(i) += 1;
	}
}

void	get_index_arr(char *arr, int *i)
{
	while (*(i) > 0)
	{
		if (arr[*(i)] == '0' && arr[*(i) - 1] != '0')
		{
			*(i) -= 1;
			break ;
		}
		*(i) -= 1;
	}
}

void	ft_putnbr(int nb)
{
	char	arr[10];
	int		i;

	i = 0;
	if (nb < 0)
	{
		write(1, "-", 1);
	}
	set_digits_arr(arr, &i, &nb);
	i = 9;
	get_index_arr(arr, &i);
	if (arr[9] != '0')
	{
		i = 9;
	}
	while (i >= 0)
	{
		write(1, &arr[i--], 1);
	}
}
