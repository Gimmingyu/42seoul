/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exceptions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyekim <kyekim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/12 03:31:00 by kyekim            #+#    #+#             */
/*   Updated: 2020/07/12 16:25:44 by kyekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** (main) ft_exceptions: check all functions in this file
** return 1, return 0 and Error message
**
** (sub1) ft_exception_argc: check the argc is 2
** (sub2) ft_exception_shape: check the input(string) value
**                            [number , space, ... ]
** (sub3) ft_exception_length: check the input(string) length
** 							   [16 int, 15 space]
** (sub4) ft_exception_range: check the integer's range, 1~4
*/

#include "header.h"

int		ft_exception_argc(int argc)
{
	if (argc != 2)
		return (0);
	return (1);
}

int		ft_exception_shape(char *argv[])
{
	int i;

	i = 0;
	while (argv[1][i] != '\0')
	{
		if (i % 2 != 0)
		{
			if (!(argv[1][i] == ' '))
				return (0);
		}
		else
		{
			if (!(argv[1][i] >= '0' && argv[1][i] <= '9'))
				return (0);
		}
		i++;
	}
	return (1);
}

int		ft_exception_length(char *argv[])
{
	int i;

	i = 0;
	while (argv[1][i] != '\0')
		i++;
	if (i != 31)
		return (0);
	return (1);
}

int		ft_exception_range(char *argv[])
{
	int i;

	i = 0;
	while (i < 32)
	{
		if (argv[1][i] < '1' || argv[1][i] > '4')
			return (0);
		i += 2;
	}
	return (1);
}

int		ft_exceptions(int argc, char *argv[])
{
	if (ft_exception_argc(argc) == 0)
		return (0);
	if (ft_exception_shape(argv) == 0)
		return (0);
	if (ft_exception_length(argv) == 0)
	   return (0);
	if (ft_exception_range(argv) == 0)
		return (0);
	return (1);
}
