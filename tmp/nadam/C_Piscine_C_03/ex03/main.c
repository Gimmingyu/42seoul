/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jko <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 22:10:40 by jko               #+#    #+#             */
/*   Updated: 2020/01/27 13:07:25 by jko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

char	*ft_strncat(char *dest, char *src, unsigned int nb);

int		main(void)
{
	char dest1[30] = "123\0";
	char dest2[30] = "123\0";
	char src[] = "abc\0defghijk\0";
	unsigned int size = 1;
	printf("%s\n%s\n", ft_strncat(dest1, src, size), strncat(dest2, src, size));

	return (0);
}
