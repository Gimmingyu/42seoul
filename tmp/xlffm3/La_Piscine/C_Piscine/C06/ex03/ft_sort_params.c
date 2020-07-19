/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jipark <jipark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 22:31:55 by jipark            #+#    #+#             */
/*   Updated: 2020/01/29 09:07:04 by jipark           ###   ########.fr       */
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

void	print_argvs(int argc, char *argv[])
{
	int i;
	int j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j] != '\0')
		{
			write(1, &argv[i][j], 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}

int		main(int argc, char *argv[])
{
	char	*tmp;
	int		i;
	int		j;

	i = 1;
	while (i < argc - 1)
	{
		j = i + 1;
		while (j < argc)
		{
			if (ft_strcmp(argv[i], argv[j]) > 0)
			{
				tmp = argv[i];
				argv[i] = argv[j];
				argv[j] = tmp;
			}
			j++;
		}
		i++;
	}
	print_argvs(argc, argv);
	return (0);
}
