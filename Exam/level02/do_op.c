/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 12:18:24 by marvin            #+#    #+#             */
/*   Updated: 2020/07/16 12:18:24 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int		main(int argc, char *argv[])
{
	int num1;
	int num2;

	if (argc == 4)
	{
		num1 = atoi(argv[1]);
		num2 = atoi(argv[3]);
		if (argv[2][0] == '+')
			printf("%d", num1 + num2);
		if (argv[2][0] == '-')
			printf("%d", num1 - num2);
		if (argv[2][0] == '*')
			printf("%d", num1 * num2);
		if (argv[2][0] == '/')
			printf("%d", num1 / num2);
	}
	printf("\n");
	return (0);
}