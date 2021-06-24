/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyekim <kyekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 17:41:30 by kyekim            #+#    #+#             */
/*   Updated: 2021/06/24 14:37:04 by kyekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server_bonus.h"

void			ft_putstr(char *str)
{
	int			len;

	len = 0;
	while (str[len])
		len++;
	write(1, str, len);
}

static void		ft_putnbr_fd(int n)
{
	char		a;

	a = n % 10 + '0';
	if (n >= 10)
		ft_putnbr_fd(n / 10);
	write(1, &a, 1);
}

void			recept(int signum, siginfo_t *info, void *ptr)
{
	static int	ascii;
	static int	power;

	(void)ptr;
	if (!info->si_pid)
		return ;
	if (kill(info->si_pid, signum) != 0)
		return ;
	if (signum == SIGUSR1)
		ascii |= (1 << power);
	if (++power == 8)
	{
		power = 0;
		if (ascii)
			write(1, &ascii, 1);
		else
			ft_putstr("\n");
		ascii = 0;
	}
}

void			ft_bzero(void *p, int n)
{
	char		*c;

	c = (char *)p;
	while (n--)
		*c++ = 0;
}

int				main(void)
{
	pid_t				serv_pid;
	struct sigaction	act;
	sigset_t			hold;

	serv_pid = getpid();
	ft_putstr("Your Minitalk server pid: ");
	ft_putnbr_fd((int)serv_pid);
	ft_putstr("\n");
	sigemptyset(&hold);
	ft_bzero(&act, sizeof(sigaction));
	act.sa_sigaction = &recept;
	act.sa_flags = SA_SIGINFO;
	sigaddset(&hold, SIGUSR1);
	sigaddset(&hold, SIGUSR2);
	act.sa_mask = hold;
	if (sigaction(SIGUSR1, &act, NULL) || sigaction(SIGUSR2, &act, NULL))
	{
		ft_putstr("Please retry\n");
	}
	while (42)
		pause();
	return (0);
}
