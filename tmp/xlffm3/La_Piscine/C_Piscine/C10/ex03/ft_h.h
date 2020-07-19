/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_h.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jipark <jipark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 09:56:39 by jipark            #+#    #+#             */
/*   Updated: 2020/02/13 16:34:52 by jipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef FT_H_H
#	define FT_H_H

#include <unistd.h>
#include <sys/errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>
#include <libgen.h>

extern int	g_len;
extern int	g_flag;
extern int g_star_flag;
extern int g_last_cnt;
extern int g_offset_cnt;

int		ft_strlen(char *src);
char	*ft_strdup(char *src);
int		ft_strcmp(char *s1, char *s2);

void	print_offset_cnt(int i);
void	print_center_content(char *buf);
void	print_hexdump(int file, int c, int i);
void	parse_hexdump(int argc, char *argv[]);

void	print_address(unsigned long long adress);
int		check_length(unsigned long long address);
void	ft_putstr(char *str);
void	print_hex_content(char buf, int k);
void	init_buf(char *buf);

void	is_duplicate(char *cmp_buf, char *buf);
void	duplicate_buf(char *cmp_buf, char *buf);

void	parse_c_hexdump(int argc, char *argv[]);
void	print_c_hexdump(int file, int c, int i);
void	reset_global(void);
void	print_offset_c_cnt(int i);

#	endif
