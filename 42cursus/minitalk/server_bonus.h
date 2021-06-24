/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyekim <kyekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 17:40:09 by kyekim            #+#    #+#             */
/*   Updated: 2021/06/24 13:35:30 by kyekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_BONUS_H
# define SERVER_BONUS_H

# include <sys/types.h>
# include <unistd.h>
# include <signal.h>

int		g_nbr;
char	ft_con_c(char c, int c1, int c2);
void	recept(int signum, siginfo_t *info, void *ptr);

#endif
