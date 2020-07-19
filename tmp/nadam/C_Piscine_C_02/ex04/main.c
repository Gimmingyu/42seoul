/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jko <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 15:58:44 by jko               #+#    #+#             */
/*   Updated: 2020/01/24 16:01:36 by jko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_str_is_lowercase(char *str);

int	main(void)
{
	printf("abc, %d\n", ft_str_is_lowercase("abc"));
	printf("ab12, %d\n", ft_str_is_lowercase("ab12"));
	printf("123, %d\n", ft_str_is_lowercase("123"));
	printf("!@#, %d\n", ft_str_is_lowercase("!@#"));
	printf("ABC, %d\n", ft_str_is_lowercase("ABC"));
	printf("Aa, %d\n", ft_str_is_lowercase("Aa"));
	printf(", %d\n", ft_str_is_lowercase(""));
	return (0);
}
