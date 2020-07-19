/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jko <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 14:20:28 by jko               #+#    #+#             */
/*   Updated: 2020/01/27 16:42:06 by jko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size);

int				main(void)
{
	char dest1[50] = "abc";
	char dest2[50] = "abc";
	char src[] = "0123";
	unsigned int size = 2;
	printf("%s, %u\n%s, %lu\n", dest1, ft_strlcat(dest1, src, size), dest2, strlcat(dest2, src, size));
	return (0);
}
