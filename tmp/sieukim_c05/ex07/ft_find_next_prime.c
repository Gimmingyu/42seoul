/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sieukim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/10 20:00:38 by sieukim           #+#    #+#             */
/*   Updated: 2020/07/11 11:09:38 by sieukim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb);

int	ft_find_next_prime(int nb)
{
	while (1)
	{
		if (ft_is_prime(nb) == 1)
			break ;
		nb++;
	}
	return (nb);
}

int	ft_is_prime(int nb)
{
	int i;
	int count;

	if (nb <= 1)
		return (0);
	i = 2;
	count = 0;
	while (i < nb)
	{
		if ((nb % i) == 0)
			count++;
		i++;
	}
	if (count == 0)
		return (1);
	return (0);
}
