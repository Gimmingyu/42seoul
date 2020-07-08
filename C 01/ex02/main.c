/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyekim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 17:52:56 by kyekim            #+#    #+#             */
/*   Updated: 2020/07/08 17:58:56 by kyekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_swap(int *a, int *b);

int		main(void)
{
	int *a;
	int *b;
	int c;
	int d;
	
	c = 3;
	d = 4;;
	a = &c;
	b = &d;

	printf("[origin] a: %d, b: %d\n", *a, *b);
	ft_swap(a, b);
	printf("[change] a: %d, b: %d\n", *a, *b);
	return (0);
}
