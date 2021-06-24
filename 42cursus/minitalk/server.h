/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyekim <kyekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 17:39:49 by kyekim            #+#    #+#             */
/*   Updated: 2021/06/24 13:34:35 by kyekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H

# include <signal.h>
# include <sys/types.h>
# include <unistd.h>

int		g_nbr;
char	ft_con_c(char c, int c1, int c2);
void	recept(int signum, siginfo_t *info, void *ptr);

#endif
