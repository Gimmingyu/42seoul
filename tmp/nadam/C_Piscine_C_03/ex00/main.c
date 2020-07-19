/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jko <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 17:03:08 by jko               #+#    #+#             */
/*   Updated: 2020/01/27 16:43:59 by jko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

int	ft_strcmp(char *s1, char *s2);

int	main(void)
{
	printf("%d vs %d\n", ft_strcmp("abc", "abc"), strcmp("abc", "abc"));
	printf("%d vs %d\n", ft_strcmp("1234", "123"), strcmp("1234", "123"));
	printf("%d vs %d\n", ft_strcmp("123", "1234"), strcmp("123", "1234"));
	printf("%d vs %d\n", ft_strcmp("aaa", "aab"), strcmp("aaa", "aab"));
	printf("%d vs %d\n", ft_strcmp("aab", "aaa"), strcmp("aab", "aaa"));
	printf("%d vs %d\n", ft_strcmp("aaaa", "aca"), strcmp("aaaa", "aca"));
	printf("%d vs %d\n", ft_strcmp("", ""), strcmp("", ""));
	printf("%d vs %d\n", ft_strcmp("aaa", "aaaa"), strcmp("aaa", "aaaa"));
	printf("%d vs %d\n", ft_strcmp("aaa", "aa"), strcmp("aaa", "aa"));
	return (0);
}
