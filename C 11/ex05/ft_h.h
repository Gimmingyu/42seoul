/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_h.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyekim <kyekim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 01:27:19 by kyekim            #+#    #+#             */
/*   Updated: 2020/07/22 07:48:19 by kyekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H_H
# define FT_H_H

# include <stdio.h>
# include <unistd.h>

int		(*g_arr[5])(int, int);

int		get_plus(int num1, int num2);
int		get_minus(int num1, int num2);
int		get_multiple(int num1, int num2);
int		get_divide(int num1, int num2);
int		get_mod(int num1, int num2);

int		ft_atoi(char *str);

void	ft_putnbr(int res);
void	print_content(int num1, int num2, char operator);

#endif
