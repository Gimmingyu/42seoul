/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghwki <donghwki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 15:15:29 by donghwki          #+#    #+#             */
/*   Updated: 2020/01/28 16:08:40 by donghwki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	int sqrt;

	sqrt = 0;
	while (1)
	{
		sqrt++;
		if (sqrt * sqrt >= nb || sqrt * sqrt < 0)
			break ;
	}
	if (sqrt * sqrt == nb)
		return (sqrt);
	else
		return (0);
}
