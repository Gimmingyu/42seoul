/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyekim <kyekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 17:40:37 by kyekim            #+#    #+#             */
/*   Updated: 2021/06/24 14:41:14 by kyekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

char			ft_con_c(char c, int c1, int c2)
{
	if (c)
		return (c1);
	else
		return (c2);
}

static void		handler(int seg)
{
	(void)seg;
	g_nbr = 1;
}

static pid_t	ft_num(char *str)
{
	pid_t		i;

	i = 0;
	while (*str)
	{
		if (*str < '0' || '9' < *str)
			break ;
		i = i * 10 + (*str - '0');
		str++;
	}
	return (i);
}

static int		send_signal(pid_t pid, char sig)
{
	int	bit;
	int	j;
	int	i;

	bit = 0;
	i = 0;
	while (i++ < 3)
	{
		j = 0;
		g_nbr = 0;
		kill(pid, ft_con_c((sig & (1 << bit)), SIGUSR1, SIGUSR2));
		while (++j < 100)
		{
			if (g_nbr)
			{
				++bit;
				i = 0;
				break ;
			}
			usleep(1);
		}
		if (bit == 8)
			return (1);
	}
	return (0);
}

int				main(int ac, char *av[])
{
	pid_t		client_pid;

	if (ac != 3)
	{
		write(1, "Input: ./client [pid_id] [message]\n", 50);
		return (1);
	}
	signal(SIGUSR1, handler);
	signal(SIGUSR2, handler);
	client_pid = ft_num(av[1]);
	while (1)
	{
		if (!send_signal(client_pid, *av[2]))
		{
			send_signal(client_pid, '\0');
			write(1, "Failed to deliever your message\n", 32);
			return (1);
		}
		if (!*(av[2]++))
			break ;
	}
	write(1, "Successfully sent your message\n", 40);
	return (0);
}
