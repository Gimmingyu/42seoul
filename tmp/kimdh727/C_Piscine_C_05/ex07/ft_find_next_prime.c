/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghwki <donghwki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 16:09:21 by donghwki          #+#    #+#             */
/*   Updated: 2020/01/28 16:13:57 by donghwki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	get_sqrt_seven(int nb)
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

int	is_prime(int nb)
{
	int i;
	int sqrt;

	if (nb < 2)
		return (0);
	i = 2 - 1;
	sqrt = get_sqrt_seven(nb);
	while (++i <= sqrt && i != nb)
		if (!(nb % i))
			return (0);
	return (1);
}

int	ft_find_next_prime(int nb)
{
	int prime;

	prime = nb;
	while (!is_prime(prime))
		prime++;
	if (is_prime(prime))
		return (prime);
	else
		return (0);
}
