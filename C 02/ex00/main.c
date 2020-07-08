/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyekim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 20:26:26 by kyekim            #+#    #+#             */
/*   Updated: 2020/07/08 20:28:05 by kyekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

char	*ft_strcpy(char *dest, char *src);

int		main(void)
{
	char *src;
	char dest[12];

	src = "Hello World";
	printf("base   : %s\n", src);
	strcpy(dest, src);
	printf("cpy    : %s\n", dest);
	ft_strcpy(dest, src);
	printf("ft_cpy : %s\n", dest);
}
