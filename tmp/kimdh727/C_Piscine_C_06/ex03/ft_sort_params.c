/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghwki <donghwki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 23:42:20 by donghwki          #+#    #+#             */
/*   Updated: 2020/01/29 18:26:11 by donghwki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	str_swap(char **s1, char **s2)
{
	char *temp_ptr;

	temp_ptr = *s1;
	*s1 = *s2;
	*s2 = temp_ptr;
}

int		ft_strcmp(char *s1, char *s2)
{
	unsigned int	i;
	int				cmp;

	i = 0;
	while (s1[i] == s2[i] && s1[i] && s2[i])
		i++;
	cmp = s1[i] - s2[i];
	return (cmp);
}

int		main(int argc, char *argv[])
{
	int		i;
	int		j;

	i = 1 - 1;
	while (++i < argc - 1)
	{
		j = i - 1;
		while (++j < argc)
			if (ft_strcmp(argv[i], argv[j]) > 0)
				str_swap(&argv[i], &argv[j]);
	}
	i = 1 - 1;
	while (++i < argc)
	{
		j = 0;
		while (argv[i][j])
			j++;
		write(1, argv[i], j);
		write(1, "\n", 1);
	}
}
