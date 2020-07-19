/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jko <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/01 17:17:45 by jko               #+#    #+#             */
/*   Updated: 2020/02/04 18:03:15 by jko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		is_valid_up(int col, int **board, int **inputs, int n)
{
	int		i;
	int		count;
	int		temp;

	temp = board[0][col];
	count = 1;
	i = 1;
	while (i < n)
	{
		if (temp < board[i][col])
		{
			count++;
			temp = board[i][col];
		}
		i++;
	}
	if (count != inputs[0][col])
		return (0);
	return (1);
}

int		is_valid_down(int col, int **board, int **inputs, int n)
{
	int		i;
	int		count;
	int		temp;

	temp = board[n - 1][col];
	count = 1;
	i = n - 2;
	while (i >= 0)
	{
		if (temp < board[i][col])
		{
			count++;
			temp = board[i][col];
		}
		i--;
	}
	if (count != inputs[1][col])
		return (0);
	return (1);
}

int		is_valid_left(int row, int **board, int **inputs, int n)
{
	int		i;
	int		count;
	int		temp;

	temp = board[row][0];
	count = 1;
	i = 1;
	while (i < n)
	{
		if (temp < board[row][i])
		{
			count++;
			temp = board[row][i];
		}
		i++;
	}
	if (count != inputs[2][row])
		return (0);
	return (1);
}

int		is_valid_right(int row, int **board, int **inputs, int n)
{
	int		i;
	int		count;
	int		temp;

	temp = board[row][n - 1];
	count = 1;
	i = n - 2;
	while (i >= 0)
	{
		if (temp < board[row][i])
		{
			count++;
			temp = board[row][i];
		}
		i--;
	}
	if (count != inputs[3][row])
		return (0);
	return (1);
}

int		is_valid(int **board, int **inputs, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		if (!is_valid_up(i, board, inputs, n)
				|| !is_valid_down(i, board, inputs, n)
				|| !is_valid_left(i, board, inputs, n)
				|| !is_valid_right(i, board, inputs, n))
			return (0);
		i++;
	}
	return (1);
}
