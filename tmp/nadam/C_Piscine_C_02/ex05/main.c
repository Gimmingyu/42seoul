/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jko <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 16:03:48 by jko               #+#    #+#             */
/*   Updated: 2020/01/24 16:05:31 by jko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_str_is_uppercase(char *str);

int	main(void)
{
	printf("ABC, %d\n", ft_str_is_uppercase("ABC"));
	printf("abc, %d\n", ft_str_is_uppercase("abc"));
	printf("ABcd, %d\n", ft_str_is_uppercase("ABcd"));
	printf("cdAB, %d\n", ft_str_is_uppercase("cdAB"));
	printf("123, %d\n", ft_str_is_uppercase("123"));
	printf("!@#, %d\n", ft_str_is_uppercase("!@#"));
	printf(", %d\n", ft_str_is_uppercase(""));
	return (0);
}
