/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_h.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyekim <kyekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 12:49:32 by kyekim            #+#    #+#             */
/*   Updated: 2020/07/21 14:31:45 by kyekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H_H
# define FT_H_H

# include <unistd.h>
# include <libgen.h>
# include <string.h>
# include <fcntl.h>
# include <sys/errno.h>
# include <sys/stat.h>
# include <sys/types.h>

int		ft_get_num(char *str);
int		ft_check_only_num(char *str);
void	ft_putstr(char *str);
void	ft_print_newline(void);
void	ft_print_content(int cnum, int argc, int file, char *str);
void	ft_print_tail(int argc, char *argv[]);

int		g_newline_flag;

#endif
