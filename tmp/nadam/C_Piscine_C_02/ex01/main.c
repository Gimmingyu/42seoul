/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jko <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 12:21:46 by jko               #+#    #+#             */
/*   Updated: 2020/01/28 19:01:22 by jko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

char	*ft_strncpy(char *dest, char *src, unsigned int n);

int main(void)
{
	unsigned int n = 3;
	char src[50] = "abcdefghijk";
	char dest[50] = "0123456789";
	char dest2[50] = "0123456789";

//	dest2 = ft_strncpy(dest, src, n);
//	write(1, dest, n);
//	write(1, dest2, n);
	printf("%s\n", ft_strncpy(dest, src, n));

	printf("\n");

//	dest2 = strncpy(dest, src, n);
//	write(1, dest, n);
//	write(1, dest2, n);
	printf("%s\n", strncpy(dest2, src, n));

	return (0);
}
