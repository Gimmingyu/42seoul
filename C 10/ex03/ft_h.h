/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_h.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyekim <kyekim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 16:02:50 by kyekim            #+#    #+#             */
/*   Updated: 2020/07/22 00:33:44 by kyekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H_H
# define FT_H_H

# include <unistd.h>
# include <libgen.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include <sys/errno.h>
# include <sys/stat.h>
# include <sys/types.h>

int		g_len;
int		g_flag;
int		g_star_flag;
int		g_last_cnt;
int		g_offset_cnt;

void	ft_parse_hexdump(int argc, char *argv[]);
void	ft_print_hex_content(char buf, int k);

int		ft_strlen(char *src);
char	*ft_strdup(char *src);
int		ft_strcmp(char *s1, char *s2);
void	ft_putstr(char *str);

void	ft_print_offset_cnt(int i);
void	ft_print_center_content(char *buf);
void	ft_print_address(unsigned long long addr);
void	ft_print_raw_content(char *buf);
void	ft_print_hexdump(int file, int c, int i);

void	ft_print_offset_c_cnt(int i);
void	ft_parse_c_hexdump(int argc, char *argv[]);
void	ft_print_c_hex_content(char buf, int k);
void	ft_print_center_c_content(char *buf);
void	ft_print_c_hexdump(int file, int c, int i);

void	ft_is_duplicate(char *cmp_buf, char buf[17]);
int		ft_check_length(unsigned long long addr);
void	ft_init_buf(char *buf);
void	ft_reset_global(void);

#endif
