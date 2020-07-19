/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jko <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 10:55:19 by jko               #+#    #+#             */
/*   Updated: 2020/01/24 11:24:14 by jko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

char *ft_strcpy(char *dest, char *src);

int main(void)
{
	char str[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '\0', '9'};
	char dest[10];
	write(1, str, 10);
	printf("\n");

	ft_strcpy(dest, str);
	write(1, dest, 10);
	printf("\n");

	strcpy(dest, str);
	write(1, dest, 10);
	printf("\n\n\n");

	
	char str2[10] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', '\0', 'j'};
	char *dest2;
	dest2 = (char *) malloc(sizeof(char) * 10);

    write(1, str2, 10);
    printf("\n");

    dest2 = ft_strcpy(dest, str2);
    write(1, dest, 10);
	printf("\n");
	write(1, dest2, 10);
    printf("\n\n");

	dest2 = strcpy(dest, str2);
	printf("\n");
    write(1, dest2, 10);
    printf("\n");
	write(1, dest2, 10);
	printf("\n\n\n");


	return 0;
}
