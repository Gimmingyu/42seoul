/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jko <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 14:23:10 by jko               #+#    #+#             */
/*   Updated: 2020/01/26 15:52:46 by jko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size);

int	main(void)
{
	char *dest = (char *) malloc(sizeof(char) * 20);

	char t[] = {'a', 'b', 'c', 'd', '\0', '1', '2'}; 
	printf("%s, %d vs %lu \n", t, ft_strlcpy(dest, t, 7), strlcpy(dest, t, 7));
	char t1[] = {'1', 'A', 'b', '!', '\0', 'a', '\n'}; 
	printf("%s, %d vs %lu \n", t1, ft_strlcpy(dest, t1, 7), strlcpy(dest, t1, 7));
	char t2[] = {'a', 'B', 'c', 'D', '\0'}; 
	printf("%s, %d vs %lu \n", t2, ft_strlcpy(dest, t2, 7), strlcpy(dest, t2, 7));
	char t3[] = {'\0', 'a', 'b', 'c', '\0'}; 
	printf("%s, %d vs %lu \n", t3, ft_strlcpy(dest, t3, 7), strlcpy(dest, t3, 7));
	char t4[] = {'1', '2', '3', '4', '5', '6', '7'}; 
	printf("%s, %d vs %lu \n", t4, ft_strlcpy(dest, t4, 8), strlcpy(dest, t4, 8));

	char t5[] = "abc\0def\0";
	printf("%s, %d vs %lu \n", t5, ft_strlcpy(dest, t5, 2), strlcpy(dest, t5, 2));
	return (0);
}
