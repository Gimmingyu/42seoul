/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghwki <donghwki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 23:19:03 by donghwki          #+#    #+#             */
/*   Updated: 2020/01/29 14:57:23 by donghwki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char *argv[])
{
	int i;
	int len;

	i = 1 - 1;
	while (++i < argc)
	{
		len = 0;
		while (argv[i][len])
			len++;
		write(1, argv[i], len);
		write(1, "\n", 1);
	}
}
