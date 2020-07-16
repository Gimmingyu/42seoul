/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jko <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 14:07:33 by jko               #+#    #+#             */
/*   Updated: 2020/02/06 21:53:38 by jko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "my_functions.h"

int	(*select_operator(char *str))(int, int)
{
	if (!str[0] || str[1])
		return (0);
	if (str[0] == '+')
		return (&add);
	else if (str[0] == '-')
		return (&sub);
	else if (str[0] == '*')
		return (&multi);
	else if (str[0] == '/')
		return (&divid);
	else if (str[0] == '%')
		return (&mod);
	return (0);
}

int	check_zero_error(int (*f)(int, int), int n2)
{
	if (f == 0)
	{
		ft_putnbr(0);
		return (1);
	}
	else if (n2 == 0 && f == divid)
	{
		write(1, "Stop : division by zero\n", 24);
		return (1);
	}
	else if (n2 == 0 && f == mod)
	{
		write(1, "Stop : modulo by zero\n", 22);
		return (1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int	n1;
	int	n2;
	int	result;
	int	(*calculator)(int, int);

	if (argc != 4)
		return (0);
	n1 = ft_atoi(argv[1]);
	n2 = ft_atoi(argv[3]);
	calculator = select_operator(argv[2]);
	if (check_zero_error(calculator, n2))
		return (0);
	result = calculator(n1, n2);
	ft_putnbr(result);
	return (0);
}
