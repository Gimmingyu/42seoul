/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jko <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/01 16:44:10 by jko               #+#    #+#             */
/*   Updated: 2020/02/04 18:03:17 by jko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		**malloc_arrs(int n);
void	free_arrs(int **arrs, int n);

int		**split_inputs(char *inputs, int n)
{
	int		**result;
	int		i;
	int		count;
	int		temp;

	result = malloc_arrs(n);
	i = 0;
	count = 0;
	temp = n + '0';
	while (inputs[i])
	{
		if (inputs[i] >= '1' && inputs[i] <= temp)
		{
			result[count / n][count % n] = inputs[i] - '0';
			i++;
			count++;
		}
		else if (inputs[i] == ' ')
			i++;
		else
			break ;
	}
	if (count == n * n)
		return (result);
	free_arrs(result, n);
	return (0);
}

void	print_error(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		write(2, &str[i], 1);
		i++;
	}
	write(2, "\n", 1);
}

void	print_answer(int **ints, int n)
{
	int		i;
	int		j;
	char	temp[2];

	temp[0] = ' ';
	i = 0;
	while (i < n)
	{
		temp[1] = ints[i][0] + '0';
		write(1, &temp[1], 1);
		j = 1;
		while (j < n)
		{
			temp[1] = ints[i][j] + '0';
			write(1, &temp, 2);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}
