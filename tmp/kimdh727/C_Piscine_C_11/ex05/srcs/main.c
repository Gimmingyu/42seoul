/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghwki <donghwki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 22:49:18 by donghwki          #+#    #+#             */
/*   Updated: 2020/02/13 22:07:33 by donghwki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "do_op.h"
#include <unistd.h>

void	print_num(unsigned int nb)
{
	char print;

	if (nb >= 10)
		print_num(nb / 10);
	print = nb % 10 + '0';
	write(1, &print, 1);
}

void	ft_putnbr(int nb)
{
	if (nb < 0)
	{
		nb *= -1;
		write(1, "-", 1);
	}
	print_num((unsigned int)nb);
	write(1, "\n", 1);
}

int		is_sign(char c, int *sign)
{
	if (c == '-')
	{
		*sign *= -1;
		return (1);
	}
	else if (c == '+')
		return (1);
	return (0);
}

int		ft_atoi(char *str)
{
	unsigned int	i;
	int				flag;
	int				result;

	i = 0;
	flag = 1;
	result = 0;
	if (is_sign(str[i], &flag))
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result * flag);
}

int		main(int argc, char *argv[])
{
	int		a;
	int		b;
	void	(*f[5])(int, int);

	if (argc != 4)
		return (0);
	a = ft_atoi(argv[1]);
	b = ft_atoi(argv[3]);
	f[0] = &op_add;
	f[1] = &op_sub;
	f[2] = &op_div;
	f[3] = &op_mul;
	f[4] = &op_mod;
	if (argv[2][0] == '+')
		f[0](a, b);
	else if (argv[2][0] == '-')
		f[1](a, b);
	else if (argv[2][0] == '/')
		f[2](a, b);
	else if (argv[2][0] == '*')
		f[3](a, b);
	else if (argv[2][0] == '%')
		f[4](a, b);
	else
		ft_putnbr(0);
}
