/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jko <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 17:04:07 by jko               #+#    #+#             */
/*   Updated: 2020/01/29 11:41:30 by jko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_putnbr_base(int nbr, char *base);

int		main(void)
{
	int start = -20;
	int end = 30;
	char base[] = "0123456789abcdef";
	for (int i = start; i < end; i++)
	{
		ft_putnbr_base(i, base);
		printf("\n");
	}


	int i1 = -2147483648;
	char base1[] = "0123456789";
	ft_putnbr_base(i1, base1);
	printf("\n");

	return (0);
}
