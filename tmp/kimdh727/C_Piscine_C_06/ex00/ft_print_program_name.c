/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghwki <donghwki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 18:41:27 by donghwki          #+#    #+#             */
/*   Updated: 2020/01/29 17:54:18 by donghwki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char *argv[])
{
	int len;

	len = 0;
	if (argc > 0)
		while (argv[0][len])
			len++;
	write(1, argv[0], len);
	write(1, "\n", 1);
}
