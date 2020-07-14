/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sieukim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/10 10:34:42 by sieukim           #+#    #+#             */
/*   Updated: 2020/07/11 12:53:47 by sieukim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	int i;

	i = 0;
	while ((i * i <= nb) && (i <= 46340))
	{
		if (i * i == nb)
			return (i);
		i++;
	}
	return (0);
}