/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jko <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 13:57:07 by jko               #+#    #+#             */
/*   Updated: 2020/02/07 11:14:35 by jko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int i;
	int check;
	int check_r;

	if (length < 2)
		return (1);
	check = 0;
	check_r = 0;
	i = 0;
	while (i < length - 1)
	{
		if (f(tab[i], tab[i + 1]) >= 0)
			check++;
		if (f(tab[i], tab[i + 1]) <= 0)
			check_r++;
		i++;
	}
	if (check == length - 1 || check_r == length - 1)
		return (1);
	return (0);
}
