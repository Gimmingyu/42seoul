/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jko <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 11:35:59 by jko               #+#    #+#             */
/*   Updated: 2020/01/25 15:10:34 by jko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	print_str(char *str)
{
	int index;

	index = 0;
	while (str[index] != '\0')
	{
		ft_putchar(str[index]);
		index++;
	}
	ft_putchar('\n');
}

void	make_top(char *dest, int x)
{
	int index;

	dest[0] = '/';
	if (x == 1)
	{
		dest[1] = '\0';
		return ;
	}
	index = 1;
	while (index < x - 1)
	{
		dest[index] = '*';
		index++;
	}
	dest[index] = '\\';
	dest[++index] = '\0';
}

void	make_bot(char *dest, int x)
{
	int index;

	dest[0] = '\\';
	if (x == 1)
	{
		dest[1] = '\0';
		return ;
	}
	index = 1;
	while (index < x - 1)
	{
		dest[index] = '*';
		index++;
	}
	dest[index] = '/';
	dest[++index] = '\0';
}

void	make_col(char *dest, int x)
{
	int index;

	dest[0] = '*';
	if (x == 1)
	{
		dest[1] = '\0';
		return ;
	}
	index = 1;
	while (index < x - 1)
	{
		dest[index] = ' ';
		index++;
	}
	dest[index] = '*';
	dest[++index] = '\0';
}

void	rush(int x, int y)
{
	char	top[x + 1];
	char	bot[x + 1];
	char	col[x + 1];
	int		index;

	if (x <= 0 || y <= 0)
		return ;
	index = 1;
	make_top(top, x);
	make_bot(bot, x);
	make_col(col, x);
	print_str(top);
	if (y == 1)
		return ;
	while (index < y - 1)
	{
		print_str(col);
		index++;
	}
	print_str(bot);
}
