/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sieukim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/10 19:53:09 by sieukim           #+#    #+#             */
/*   Updated: 2020/07/11 11:08:59 by sieukim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
