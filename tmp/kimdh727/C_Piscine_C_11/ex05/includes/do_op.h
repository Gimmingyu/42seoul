/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghwki <donghwki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 21:56:24 by donghwki          #+#    #+#             */
/*   Updated: 2020/02/13 21:58:17 by donghwki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DO_OP_H
# define DO_OP_H

void	print_num(unsigned int nb);
void	ft_putnbr(int nb);
int		is_sign(char c, int *sign);
int		ft_atoi(char *str);
void	op_add(int n1, int n2);
void	op_sub(int n1, int n2);
void	op_div(int n1, int n2);
void	op_mul(int n1, int n2);
void	op_mod(int n1, int n2);

#endif
