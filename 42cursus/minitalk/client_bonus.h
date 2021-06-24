/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyekim <kyekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 17:39:28 by kyekim            #+#    #+#             */
/*   Updated: 2021/06/24 13:33:55 by kyekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_BONUS_H
# define CLIENT_BONUS_H

# include <signal.h>
# include <sys/types.h>
# include <unistd.h>

int		g_nbr;
char	ft_con_c(char c, int c1, int c2);
void	recept(int signum, siginfo_t *info, void *ptr);

#endif
