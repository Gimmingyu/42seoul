/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   puzzle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jko <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/01 13:01:15 by jko               #+#    #+#             */
/*   Updated: 2020/02/04 18:03:12 by jko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	print_answer(int **ints, int n);
int		**malloc_arrs(int n);
void	free_arrs(int **arrs, int n);
char	init_arr(int *arr, int size);
int		is_valid(int **board, int **inputs, int n);
void	dfs(int row, int col, int **board, int **inputs, int n);

char	g_is_end = 0;

int		check_row(int row, int **board, int n)
{
	int used[10];
	int i;

	init_arr(used, n);
	i = 0;
	while (i < n)
	{
		if (!board[row][i])
			return (1);
		if (used[board[row][i]])
			return (0);
		used[board[row][i]]++;
		i++;
	}
	return (1);
}

int		check_col(int col, int **board, int n)
{
	int used[10];
	int i;

	init_arr(used, n);
	i = 0;
	while (i < n)
	{
		if (!board[i][col])
			return (1);
		if (used[board[i][col]])
			return (0);
		used[board[i][col]]++;
		i++;
	}
	return (1);
}

int		check_return(int row, int col, int **board, int **inputs, int n)
{
	if (g_is_end)
		return (1);
	if (row == n && col == 0)
	{
		if (is_valid(board, inputs, n))
		{
			g_is_end = 1;
			print_answer(board, n);
		}
		return (1);
	}
	return (0);
}

void	dfs(int row, int col, int **board, int **inputs, int n)
{
	int i;

	if (check_return(row, col, board, inputs, n))
		return ;
	i = 1;
	while (i <= n)
	{
		board[row][col] = i;
		if (check_row(row, board, n) && check_col(col, board, n))
		{
			if (col == n - 1)
				dfs(row + 1, 0, board, inputs, n);
			else
				dfs(row, col + 1, board, inputs, n);
		}
		board[row][col] = 0;
		i++;
	}
}

int		solve(int **inputs, int n)
{
	int **board;
	int	i;

	g_is_end = 0;
	board = malloc_arrs(n);
	i = 0;
	while (i < n)
	{
		init_arr(board[i], n);
		i++;
	}
	dfs(0, 0, board, inputs, n);
	free_arrs(board, n);
	return (g_is_end);
}
