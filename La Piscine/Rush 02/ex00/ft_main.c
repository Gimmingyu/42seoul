/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyekim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/18 12:09:49 by kyekim            #+#    #+#             */
/*   Updated: 2020/07/19 18:59:45 by jopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_h.h"

void	tmp(char *str)
{
	int len;

	len = ft_strlen(str);
	ft_grouping_num_three(str, len);	
}

int		main(int argc, char *argv[])
{
	if (ft_check_int(argv[1]))
	{
		write(1, "Error\n", 6);
		return (0);
	}
	if (argc == 2)
	{
		if (ft_read_txt("numbers.dict"))
			return (0);
		tmp(argv[1]);
	}
	else if (argc == 3)
	{
		if (ft_read_txt(argv[1]))
			return (0);
	}
	return (0);
}
