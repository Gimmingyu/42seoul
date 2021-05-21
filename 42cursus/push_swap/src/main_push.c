/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyekim <kyekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 17:07:50 by kyekim            #+#    #+#             */
/*   Updated: 2021/05/17 20:28:44 by kyekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	ft_error(t_ab *arg)
{
	write(2, "Error\n", 6);
	free_ab(arg);
	return (-1);
}

int			main(int argc, char **argv)
{
	t_ab	arg;
	char	**back;

	back = argv;
	if (argc == 1)
		return (0);
	if (set(&arg, argv, get_size(argv)) == -1)
		return (0);
	if (check_a(back) == -1 || check_b(arg.a) == -1)
		return (ft_error(&arg));
	if (check_valid(arg.a, arg.b) == 1)
		return (0);
	while (arg.a->size > 1 && check_valid(arg.a, arg.b) == -1)
		sort(&arg, 0);
	while (check_valid(arg.a, arg.b) == -1)
	{
		while (check_valid(arg.a, arg.b) == -1
				&& check_tab(arg.a->tab, arg.a->size) == 1)
			sort(&arg, 1);
		while (check_tab(arg.a->tab, arg.a->size) == -1)
			sort(&arg, 2);
	}
	free_ab(&arg);
	return (0);
}
