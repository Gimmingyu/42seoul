/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seusong <qhftkfaos@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/04 22:06:18 by seusong           #+#    #+#             */
/*   Updated: 2020/07/04 22:06:28 by seusong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	rush(int x, int y)
{
	int i;

	i = 0;
	while (x * y > i)
	{
		if (i / x == 0 || i / x == y - 1)
		{
			if (i % x == 0 || i % x == x - 1)
				ft_putchar('o');
			else
				ft_putchar('-');
		}
		else
		{
			if (i % x == 0 || i % x == x - 1)
				ft_putchar('|');
			else
				ft_putchar(' ');
		}
		if (i % x == x - 1)
			ft_putchar('\n');
		i++;
	}
}
