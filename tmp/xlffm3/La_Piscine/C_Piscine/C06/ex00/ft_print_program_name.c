/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jipark <jipark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 21:57:15 by jipark            #+#    #+#             */
/*   Updated: 2020/01/29 09:05:42 by jipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		main(int argc, char const *argv[])
{
	int i;
	int j;

	i = argc;
	j = 0;
	while (*(*(argv) + j) != '\0')
	{
		write(1, &(*(*(argv) + j)), 1);
		j++;
	}
	write(1, "\n", 1);
	return (0);
}
