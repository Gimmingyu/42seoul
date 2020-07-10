/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alpha_mirror.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/10 12:30:52 by marvin            #+#    #+#             */
/*   Updated: 2020/07/10 12:30:52 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		is_alpha(char c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	return (0);
}

int		alpha_mirror(int c)
{
	if (c >= 'A' && c <= 'Z')
		c = 'Z' - (c - 'A');
	else
		c = 'z' - (c - 'a');
	return (c);
}

int		main(int argc, char **argv)
{
	if (argc == 2)
	{
		while (*argv[1])
		{
			if (is_alpha(*argv[1]))
				ft_putchar(alpha_mirror(*argv[1]++));
			else
				ft_putchar(*argv[1]++);
		}
	}
	write(1, "\n", 1);
}