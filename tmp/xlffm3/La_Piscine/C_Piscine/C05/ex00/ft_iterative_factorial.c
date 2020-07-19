/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jipark <jipark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 20:41:44 by jipark            #+#    #+#             */
/*   Updated: 2020/01/28 11:09:59 by jipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_iterative_factorial(int nb)
{
	int i;

	if (nb == 0)
		return (1);
	else if (nb < 0)
		return (0);
	i = nb - 1;
	while (i != 0)
		nb *= i--;
	return (nb);
}
