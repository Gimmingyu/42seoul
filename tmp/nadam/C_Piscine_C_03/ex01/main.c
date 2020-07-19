/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jko <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 17:26:01 by jko               #+#    #+#             */
/*   Updated: 2020/01/26 17:28:25 by jko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

int	ft_strncmp(char *s1, char *s2, unsigned int n);

int	main(void)
{
	printf("%d vs %d\n", ft_strncmp("abc", "abc", 3), strncmp("abc", "abc", 3));
	printf("%d vs %d\n", ft_strncmp("1234", "123", 3), strncmp("1234", "123", 3));
	printf("%d vs %d\n", ft_strncmp("123", "1234", 4), strncmp("123", "1234", 4));
	printf("%d vs %d\n", ft_strncmp("aaa", "aab", 3), strncmp("aaa", "aab", 3));
	printf("%d vs %d\n", ft_strncmp("aab", "aaa", 2), strncmp("aab", "aaa", 2));
	printf("%d vs %d\n", ft_strncmp("aaaa", "aca", 4), strncmp("aaaa", "aca", 4));
	printf("%d vs %d\n", ft_strncmp("", "", 1), strncmp("", "", 1));
	printf("%d vs %d\n", ft_strncmp("aaa", "aaaa", 4), strncmp("aaa", "aaaa", 4));
	printf("%d vs %d\n", ft_strncmp("aaa", "aa", 3), strncmp("aaa", "aa", 3));
	return (0);
}
