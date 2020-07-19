/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jipark <jipark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 20:53:05 by jipark            #+#    #+#             */
/*   Updated: 2020/01/28 20:24:22 by jipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_iterative_power(int nb, int power)
{
	int i;
	int default_nb;

	i = 1;
	default_nb = nb;
	if (nb == 0 && power == 0)
		return (1);
	else if (nb == 0 && power != 0)
		return (0);
	else if (nb != 0 && power == 0)
		return (1);
	else if (nb != 0 && power < 0)
		return (0);
	while (i++ < power)
		nb *= default_nb;
	return (nb);
}
