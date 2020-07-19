/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush04.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghwki <donghwki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 15:04:27 by donghwki          #+#    #+#             */
/*   Updated: 2020/01/25 18:25:46 by donghwki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

int		is_left_right(int index, int max)
{
	if (index == 0)
		return (1);
	if (index == max - 1)
		return (3);
	return (0);
}

int		is_bottom_top(int index, int max)
{
	if (index == 0)
		return (1);
	if (index == max - 1)
		return (3);
	return (0);
}

void	rush04(int a, int b)
{
	int flag;
	int i;
	int j;

	i = 0 - 1;
	while (++i < b)
	{
		j = 0 - 1;
		while (++j < a)
		{
			flag = (is_left_right(j, a) + is_bottom_top(i, b));
			if (flag % 2 == 1)
				ft_putchar('B');
			else if (flag == 2 || flag == 6)
				ft_putchar('A');
			else if (flag == 4)
				ft_putchar('C');
			else
				ft_putchar(' ');
		}
		ft_putchar('\n');
	}
}
