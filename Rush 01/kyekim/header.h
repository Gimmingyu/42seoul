/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyekim </var/mail/kyekim>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/12 04:19:50 by kyekim            #+#    #+#             */
/*   Updated: 2020/07/12 14:10:44 by kyekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
#define HEADER_H
#include <unistd.h>
#include <stdlib.h>
#define N 4

/* check Error condition: input */
int		ft_exceptions(int argc, char *argv[]);
int		ft_execption_argc(char *argv[]);
int		ft_exception_shape(char *argv[]);
int		ft_exception_length(char *argv[]);
int		ft_exception_range(char *argv[]);

/* change char to num */
void	ft_atoi(char *str, int *udlr[]);

/* check that expected num is correct or not */
int		ft_dfs(int idx, int *udlr[], int *ans);
int		ft_check_udlr(int idx, int *udlr[], int *ans);
int		ft_check(int idx, int *udlr[], int *ans);
int		ft_check_1234(int idx, int *ans);
int		u_check(int idx, int *udlr[], int *ans);
int		d_check(int idx, int *udlr[], int *ans);
int		l_check(int idx, int *udlr[], int *ans);
int		r_check(int idx, int *udlr[], int *ans);

/* print */
void	ft_putchar(char ch);
void	ft_print(int *ans);

/* memory free */
void	ft_free(int *ans, int *udlr[]);

#endif
