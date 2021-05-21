/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyekim <kyekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 14:48:51 by kyekim            #+#    #+#             */
/*   Updated: 2021/05/12 14:52:50 by kyekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/includes/libft.h"
# include "./checker.h"

int				set(t_ab *arg, char **argv, int argc);

int				check_a(char **argv);
int				check_b(t_stack *a);
char			**check_space(char **argv);
int				check_valid(t_stack *a, t_stack *b);
int				check_tab(int *tab, int size);
int				check_pivot_tab_up(t_stack *a, int pvt);
int				check_pivot_tab_dn(t_stack *a, int pvt);

t_stack			*copy_stack(t_stack *a, t_stack *b);
void			add_pivot(t_stack *stack, int pivot);
int				get_pivot(t_stack *stack);
void			free_stack(t_stack *stack);
void			free_ab(t_ab *arg);
int				get_size(char **argv);
int				get_med(t_stack *stack, int i, int j, int v_inf);
void			sort(t_ab *arg, int index);
void			sort_five(t_ab *arg);
void			sort_stack_fst(int c, t_ab *arg, t_stack *tab_tmp, int pos);
void			sort_stack_fst_next(t_stack *tab_tmp, t_ab *arg, int c_rb,
		int pos);
void			sort_stack_nd(int c, t_ab *arg, t_stack *tab_tmp, int pos);
void			sort_stack_nd_next(t_stack *tab_tmp, t_ab *arg, int c_ra,
		int pos);
void			little_sort(t_stack *stack_tmp, t_ab *arg);
#endif
