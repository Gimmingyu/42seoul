/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyekim <kyekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 14:20:46 by kyekim            #+#    #+#             */
/*   Updated: 2020/07/21 14:31:01 by kyekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_h.h"

void	ft_get_input(int argc, char *argv[], int i, int j)
{
	char	tmp[20000];

	if (argc == 3)
	{
		while (read(0, &tmp[i], 1))
			i++;
		tmp[i] = '\0';
		j = i - ft_get_num(argv[2]);
		while (tmp[j] != '\0')
		{
			write(1, &tmp[j], 1);
			j++;
		}
	}
	else if (argc == 1)
	{
		while (read(0, &tmp[i], 1))
			i++;
		tmp[i] = '\0';
		ft_putstr(tmp);
	}
}

int		main(int argc, char *argv[])
{
	if (argc == 1 || (argc == 3 && ft_check_only_num(argv[2])))
		ft_get_input(argc, argv, 0, 0);
	if (argc < 3)
		return (0);
	if (!ft_check_only_num(argv[2]))
	{
		ft_putstr(basename(argv[0]));
		ft_putstr(": illegal offset -- ");
		ft_putstr(argv[2]);
		write(1, "\n", 1);
		return (0);
	}
	else
	{
		if (argc >= 4)
			ft_print_tail(argc, argv);
	}
	return (0);
}
