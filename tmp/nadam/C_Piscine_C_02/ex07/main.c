/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jko <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 16:23:32 by jko               #+#    #+#             */
/*   Updated: 2020/01/25 11:14:46 by jko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

char *ft_strupcase(char *str);

int main(void)
{
	printf("%c, %c\n", 'a', 'a' - 32);

	char tt[10] = {'a', 'b', 'c', '\0'};
	printf("abc, %s\n", ft_strupcase(tt));

	char tt1[10] = {'1', '2', '3', '\0'};
	printf("123, %s\n", ft_strupcase(tt1));
	
	char tt2[10] = {'A', 'B', 'C', '\0'};
	printf("ABC, %s\n", ft_strupcase(tt2));
	
	char tt3[] = {'a', 'B', 'c', '\0'};
	printf("aBc, %s\n", ft_strupcase(tt3));
	
	char tt4[] = {'!', '@', '#', '\0'};
	printf("!@#, %s\n", ft_strupcase(tt4));
	
	char tt5[] = {'a', 'A', 'b', 'B', '\0'};
	printf("aAbB, %s\n", ft_strupcase(tt5));
	
	char tt6[] = {'\0'};
	printf(", %s\n", ft_strupcase(tt6));
	
	return (0);
}
