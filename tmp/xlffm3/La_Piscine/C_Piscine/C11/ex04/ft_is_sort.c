/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jipark <jipark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 19:26:06 by jipark            #+#    #+#             */
/*   Updated: 2020/02/05 11:54:10 by jipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		is_decrease(int *tab, int length, int (*f)(int, int))
{
	int i;
	int result;

	i = 0;
	while (i < length - 1)
	{
		result = f(tab[i], tab[i + 1]);
		if (result < 0)
			return (0);
		i++;
	}
	return (1);
}

int		is_increase(int *tab, int length, int (*f)(int, int))
{
	int i;
	int result;

	i = 0;
	while (i < length - 1)
	{
		result = f(tab[i], tab[i + 1]);
		if (result > 0)
			return (0);
		i++;
	}
	return (1);
}

int		ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	if (is_decrease(tab, length, f) || is_increase(tab, length, f))
		return (1);
	return (0);
}
