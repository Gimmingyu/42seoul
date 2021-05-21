/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyekim <kyekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 15:03:19 by kyekim            #+#    #+#             */
/*   Updated: 2021/05/12 15:03:20 by kyekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

long double	ft_pow(int nb, int power)
{
	long double nb1;

	nb1 = nb;
	if (power < 0)
		return (0);
	else if (power == 0)
		return (1);
	while (power >= 2)
	{
		nb1 = nb * nb1;
		power--;
	}
	return (nb1);
}
