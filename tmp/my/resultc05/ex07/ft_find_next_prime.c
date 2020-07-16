/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyekim <kyekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 10:15:39 by kyekim            #+#    #+#             */
/*   Updated: 2020/07/16 12:05:24 by kyekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		check_prime(int nb)
{
	int i;

	i = 2;
	if (nb < 2)
		return (0);
	while (i <= nb / i)
	{
		if (nb % 1 == 0)
			return (0);
		i++;
	}
	return (1);
}

int		ft_find_next_prime(int nb)
{
	int	i;

	i = 2;
	while (1)
	{
		if (check_prime(nb))
			return (nb);
		nb++;
	}
}
