/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jko <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 21:56:25 by jko               #+#    #+#             */
/*   Updated: 2020/01/27 16:44:45 by jko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

char	*ft_strcat(char *dest, char *src);

int		main(void)
{
	char src[10] = "world";
	char dest[30] = "Hello ";
	printf("%s", dest);
	printf(" + %s = %s\n", src, ft_strcat(dest, src));

	return (0);
}
