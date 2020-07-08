/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyekim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 18:31:22 by kyekim            #+#    #+#             */
/*   Updated: 2020/07/08 18:34:57 by kyekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_ultimate_div_mod(int *a, int *b);

int		main(void)
{
	int num1;
	int num2;

	num1 = 10;
	num2 = 3;
	ft_ultimate_div_mod(&num1, &num2);
	printf("div: %d, mod: %d", num1, num2);
	return (0);
}
