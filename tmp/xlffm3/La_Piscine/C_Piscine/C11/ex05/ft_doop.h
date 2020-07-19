/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_doop.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jipark <jipark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 21:00:33 by jipark            #+#    #+#             */
/*   Updated: 2020/02/05 15:29:15 by jipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef FT_DOOP_H
#	define FT_DOOP_H
#include <unistd.h>

extern int (*g_arr[5])(int, int);
int		get_plus(int num1, int num2);
int		get_minus(int num1, int num2);
int		get_divide(int num1, int num2);
int		get_mod(int num1, int num2);
int		get_multiple(int num1, int num2);
int		ft_atoi(char *str);
void	ft_putnbr(int result);
void	print_content(int num1, int num2, char operator);
void	change_format(char *str1, char operator, char *str2);
void	set_functions(void);
#	endif
