/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_string_tab.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyekim <kyekim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 07:15:20 by kyekim            #+#    #+#             */
/*   Updated: 2020/07/22 07:17:33 by kyekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_strcmp(char *first_argv, char *second_argv)
{
	unsigned char	first_value;
	unsigned char	second_value;
	int				i;

	i = 0;
	while (first_argv[i] != '\0' || second_argv[i] != '\0')
	{
		if (first_argv[i] != second_argv[i])
		{
			first_value = (unsigned char)first_argv[i];
			second_value = (unsigned char)second_argv[i];
			return (first_value - second_value);
		}
		i++;
	}
	return (0);
}

void	ft_sort_string_tab(char **tab)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	while (tab[i] != 0)
	{
		j = i + 1;
		while (tab[j] != 0)
		{
			if (ft_strcmp(tab[i], tab[j]) > 0)
			{
				tmp = tab[i];
				tab[i] = tab[j];
				tab[j] = tmp;
			}
			j++;
		}
		i++;
	}
}
