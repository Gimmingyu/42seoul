/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jko <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 11:30:22 by jko               #+#    #+#             */
/*   Updated: 2020/01/25 12:26:54 by jko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	rush(int x, int y);
void	ft_putchar(char c);

int		main(void)
{
	int index1;
	int index2;

	index1 = 0;
	while (index1 < 6)
	{
		index2 = 0;
		while (index2 < 7)
		{
			rush(index1, index2);
			ft_putchar('\n');
			index2++;
		}
		ft_putchar('\n');
		ft_putchar('\n');
		index1++;
	}
	return (0);
}
