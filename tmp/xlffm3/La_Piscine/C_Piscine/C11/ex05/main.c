/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jipark <jipark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 19:33:04 by jipark            #+#    #+#             */
/*   Updated: 2020/02/06 11:22:29 by jipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_doop.h"

int (*g_arr[5])(int, int);

void	ft_putnbr(int result)
{
	long long	tmp;
	char		c;

	if (result < 0)
	{
		write(1, "-", 1);
		tmp = ((long long)result) * -1;
	}
	else
		tmp = result;
	if (tmp >= 10)
		ft_putnbr(tmp / 10);
	c = tmp % 10 + '0';
	write(1, &c, 1);
}

void	print_content(int num1, int num2, char operator)
{
	int result;

	result = 0;
	if (operator == '+')
		result = g_arr[0](num1, num2);
	else if (operator == '-')
		result = g_arr[1](num1, num2);
	else if (operator == '*')
		result = g_arr[2](num1, num2);
	else if (operator == '/')
		result = g_arr[3](num1, num2);
	else if (operator == '%')
		result = g_arr[4](num1, num2);
	ft_putnbr(result);
}

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
