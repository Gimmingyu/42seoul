/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jko <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/01 12:11:05 by jko               #+#    #+#             */
/*   Updated: 2020/02/04 17:58:44 by jko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	free_arrs(int **arrs, int n);
int		**split_inputs(char *inputs, int n);
void	print_error(char *str);
int		solve(int **inputs, int n);

int		main(int argc, char *argv[])
{
	int **inputs;
	int n;

	if (argc != 3)
	{
		print_error("Error");
		return (0);
	}
	printf("argv[1][0]=%c\n", argv[1][0]);
	if (argv[1][0] < '1' || argv[1][0] > '9')
	{
		print_error("Error");
		return (0);
	}
	n = argv[1][0] - '0';
	inputs = split_inputs(argv[2], n);
	if (inputs == 0)
	{
		print_error("Error");
		return (0);
	}
	if (solve(inputs, n) == 0)
		print_error("Error");
	free_arrs(inputs, n);
	return (0);
}
