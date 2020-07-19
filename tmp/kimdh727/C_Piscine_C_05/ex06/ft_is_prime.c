/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghwki <donghwki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 15:29:23 by donghwki          #+#    #+#             */
/*   Updated: 2020/01/28 16:08:57 by donghwki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	get_sqrt(int nb)
{
	int sqrt;

	sqrt = 0;
	while (1)
	{
		sqrt++;
		if (sqrt * sqrt >= nb || sqrt * sqrt < 0)
			break ;
	}
	return (sqrt);
}

int	ft_is_prime(int nb)
{
	int i;
	int sqrt;

	if (nb < 2)
		return (0);
	i = 2 - 1;
	sqrt = get_sqrt(nb);
	while (++i <= sqrt && i != nb)
		if (!(nb % i))
			return (0);
	return (1);
}
