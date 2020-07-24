/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyekim <kyekim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 00:52:40 by kyekim            #+#    #+#             */
/*   Updated: 2020/07/22 00:59:39 by kyekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_is_increase(int *tab, int length, int (*f)(int, int))
{
	int		i;
	int		res;

	i = 0;
	while (i < length - 1)
	{
		res = f(tab[i], tab[i + 1]);
		if (res > 0)
			return (0);
		i++;
	}
	return (1);
}

int		ft_is_decrease(int *tab, int length, int (*f)(int, int))
{
	int		i;
	int		res;

	i = 0;
	while (i < length - 1)
	{
		res = f(tab[i], tab[i + 1]);
		if (res < 0)
			return (0);
		i++;
	}
	return (1);
}

int		ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	if (ft_is_decrease(tab, length, f) || ft_is_increase(tab, length, f))
		return (1);
	return (0);
}
