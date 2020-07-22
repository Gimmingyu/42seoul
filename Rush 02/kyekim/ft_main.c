/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyekim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/18 12:09:49 by kyekim            #+#    #+#             */
/*   Updated: 2020/07/18 17:32:15 by kyekim           ###   ########.fr       */
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
	// char *origin_dict;
	
	// origin_dict = "numbers.dict";
	
	if (argc == 2)
	{
		//tmp(argv[1]);
		ft_read_txt("numbers.dict");
		tmp(argv[1]);
	}
	//else if (argc == 3)
		//find_new_dict(argv[2])

	return (0);
}
