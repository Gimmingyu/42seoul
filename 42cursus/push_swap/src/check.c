/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyekim <kyekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 16:01:34 by kyekim            #+#    #+#             */
/*   Updated: 2021/05/12 16:01:36 by kyekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

int		check_b(t_stack *a)
{
	int i;
	int j;

	i = 0;
	j = 1;
	while (i < a->size)
	{
		while (j < a->size)
		{
			if (a->tab[i] == a->tab[j])
				return (-1);
			j++;
		}
		i++;
		j = i + 1;
	}
	return (1);
}

int		check_value(char **new_av, int i, int j)
{
	while (new_av[i])
	{
		if ((ft_strlen(new_av[i]) > 10 && new_av[i][0] != '-') ||
				(ft_strlen(new_av[i]) == 10 &&
				ft_strcmp(new_av[i], "2147483647") > 0))
			return (-1);
		if (ft_strlen(new_av[i]) > 11 || (ft_strlen(new_av[i]) == 11 &&
					ft_strcmp(new_av[i], "-2147483648") > 0))
			return (-1);
		while (new_av[i][j])
		{
			if ((new_av[i][0] == '-' || new_av[i][0] == '+')
			&& ft_strlen(new_av[i]) > 1)
				j++;
			if (new_av[i][j] && ft_isdigit(new_av[i][j]) != 1)
				return (-1);
			j++;
		}
		j = 0;
		i++;
	}
	return (1);
}

int		check_a(char **argv)
{
	int		i;
	int		j;
	char	**new_av;

	i = 1;
	j = 0;
	while (argv[i])
	{
		if (!(new_av = ft_strsplit(argv[i], ' ')))
		{
			ft_strdel_d(new_av);
			return (-1);
		}
		if (!(check_value(new_av, 0, 0) == 1))
		{
			ft_strdel_d(new_av);
			return (-1);
		}
		ft_strdel_d(new_av);
		i++;
	}
	return (1);
}
