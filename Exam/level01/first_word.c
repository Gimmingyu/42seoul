/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_word.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 17:35:32 by marvin            #+#    #+#             */
/*   Updated: 2020/07/16 18:14:23 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_isspace(int i)
{
	if (i == '\t' || i == '\n' || i == '\v' || i == '\f' || i == ' ')
		return (1);
	return (0);
}

int		main(int argc, char *argv[])
{
	int		i;

	i = 0;
	if (argc == 2)
	{
		while (!(ft_isspace(argv[1][i])))
			i++;
		while (!(ft_isspace(argv[1][i])) && argv[1][i])
			write(1, &argv[1][i++], 1);
	}
	write(1, "\n", 1);
	return (0);
}