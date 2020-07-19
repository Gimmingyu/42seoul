/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghwki <donghwki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 12:44:26 by donghwki          #+#    #+#             */
/*   Updated: 2020/01/29 00:24:47 by donghwki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int nb_power;

	if (!power)
		return (1);
	else if (power < 0)
		return (0);
	nb_power = 1;
	while (power--)
		nb_power *= nb;
	return (nb_power);
}
