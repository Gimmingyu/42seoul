/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jko <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 11:17:04 by jko               #+#    #+#             */
/*   Updated: 2020/01/25 14:02:25 by jko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

char	*ft_strlowcase(char *str);

int	main(void)
{
	char t[] = {'A', '\0'};
	printf("A, %s, %s \n", ft_strlowcase(t), t);

	char t1[] = {'a', 'b', 'c', '\0'};
	printf("abc, %s, %s \n", ft_strlowcase(t1), t1);
	
	char t2[] = {'A', 'B', 'C', '\0'};
	printf("ABC, %s, %s \n", ft_strlowcase(t2), t2);
	
	char t3[] = {'1', '2', '3', '\0'};
	printf("123, %s, %s \n", ft_strlowcase(t3), t3);
	
	char t4[] = {'!', '@', '#', '\0'};
	printf("!@#, %s, %s \n", ft_strlowcase(t4), t4);
	
	char t5[] = {'a', 'B', 'c', 'D', '\0'};
	printf("aBcD, %s, %s \n", ft_strlowcase(t5), t5);
	
	char t6[] = {'1', 'a', 'B', '\0'};
	printf("1aB, %s, %s \n", ft_strlowcase(t6), t6);
	
	char t7[] = {'\0'};
	printf("'', %s, %s \n", ft_strlowcase(t7), t7);

	return (0);
}
