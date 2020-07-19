/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jko <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 14:12:48 by jko               #+#    #+#             */
/*   Updated: 2020/01/26 15:14:27 by jko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

char	*ft_strcapitalize(char *str);

int	main(void)
{
	char t[] = {'A', '\0'};
	printf("A, %s, %s \n", ft_strcapitalize(t), t);

	char t1[] = {'a', 'b', 'c', '\0'};
	printf("abc, %s, %s \n", ft_strcapitalize(t1), t1);
	
	char t2[] = {'A', 'B', 'C', '\0'};
	printf("ABC, %s, %s \n", ft_strcapitalize(t2), t2);
	
	char t3[] = {'1', '2', '3', '\0'};
	printf("123, %s, %s \n", ft_strcapitalize(t3), t3);
	
	char t4[] = {'!', '@', '#', '\0'};
	printf("!@#, %s, %s \n", ft_strcapitalize(t4), t4);
	
	char t5[] = {'a', 'B', 'c', 'D', '\0'};
	printf("aBcD, %s, %s \n", ft_strcapitalize(t5), t5);
	
	char t6[] = {'1', 'a', 'B', '\0'};
	printf("1aB, %s, %s \n", ft_strcapitalize(t6), t6);
	
	char t7[] = {'\0'};
	printf("'', %s, %s \n", ft_strcapitalize(t7), t7);

	char t8[] = "salut, comment tu vas ? 42mots quarante-deux; cinquante+et+un";
	printf("salut, comment tu vas ? 42mots quarante-deux; cinquante+et+un\n%s\n%s\n", ft_strcapitalize(t8), t8);
	return (0);
}

