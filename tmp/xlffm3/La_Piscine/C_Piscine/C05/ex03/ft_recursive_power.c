/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jipark <jipark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 20:56:48 by jipark            #+#    #+#             */
/*   Updated: 2020/01/29 11:12:02 by jipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_recursive_power(int nb, int power)
{
	if (nb == 0 && power == 0)
		return (1);
	else if (nb == 0 && power != 0)
		return (0);
	else if (nb != 0 && power == 0)
		return (1);
	else if (nb != 0 && power < 0)
		return (0);
	else
		return (nb * ft_recursive_power(nb, power - 1));
}
