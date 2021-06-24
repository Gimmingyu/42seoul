/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyekim <kyekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 17:39:08 by kyekim            #+#    #+#             */
/*   Updated: 2021/06/24 14:31:27 by kyekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_H
# define CLIENT_H

# include <signal.h>
# include <sys/types.h>
# include <unistd.h>

int				g_nbr;
char			ft_con_c(char c, int c1, int c2);
static void		handler(int seg);
static pid_t	ft_num(char *str);
void			recept(int signum, siginfo_t *info, void *ptr);

#endif
