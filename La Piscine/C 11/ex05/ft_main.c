/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyekim <kyekim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 03:33:04 by kyekim            #+#    #+#             */
/*   Updated: 2020/07/22 07:26:06 by kyekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_h.h"

void	change_format(char *str1, char operator, char *str2)
{
	int num1;
	int num2;

	num1 = ft_atoi(str1);
	num2 = ft_atoi(str2);
	if (num2 == 0)
	{
		if (operator == '/')
		{
			write(1, "Stop : division by zero", 23);
			return ;
		}
		else if (operator == '%')
		{
			write(1, "Stop : modulo by zero", 21);
			return ;
		}
	}
	print_content(num1, num2, operator);
}

void	set_functions(void)
{
	g_arr[0] = get_plus;
	g_arr[1] = get_minus;
	g_arr[2] = get_multiple;
	g_arr[3] = get_divide;
	g_arr[4] = get_mod;
}

int		main(int argc, char *argv[])
{
	char *operator_arr;
	char operator;

	set_functions();
	if (argc == 4)
	{
		operator_arr = argv[2];
		if (operator_arr[1] == '\0' && (operator_arr[0] == '+'
		|| operator_arr[0] == '-' || operator_arr[0] == '*'
		|| operator_arr[0] == '/' || operator_arr[0] == '%'))
		{
			operator = operator_arr[0];
			change_format(argv[1], operator, argv[3]);
			write(1, "\n", 1);
		}
		else
		{
			write(1, "0\n", 2);
			return (0);
		}
	}
	return (0);
}
