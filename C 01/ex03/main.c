/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyekim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 18:14:37 by kyekim            #+#    #+#             */
/*   Updated: 2020/07/08 18:25:30 by kyekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_div_mod(int a, int b, int *div, int *mod);

int		main(void)
{
	int *div;
	int *mod;
	int n;
	int m;

	n = 0;
	m = 0;
	div = &n;
	mod = &m;
	ft_div_mod(10, 3, div, mod);
	printf("div: %d, mod: %d", *div, *mod);
}
