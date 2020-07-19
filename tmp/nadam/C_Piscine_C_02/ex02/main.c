/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jko <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 13:04:06 by jko               #+#    #+#             */
/*   Updated: 2020/01/26 15:26:37 by jko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	ft_str_is_alpha(char *str);

int main(void)
{
	char arr[6] = {'a', 'b', 'c', 'd', '\0', };
	printf("abcd, %d\n", ft_str_is_alpha(arr));
	printf("123a, %d\n", ft_str_is_alpha("123a\0"));
	printf("123, %d\n", ft_str_is_alpha("123\0"));
	printf(", %d\n", ft_str_is_alpha("\0"));
	printf("Aa[, %d\n", ft_str_is_alpha("Aa[\0"));
	return (0);
}
