/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyekim <kyekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 14:48:51 by kyekim            #+#    #+#             */
/*   Updated: 2021/05/12 14:52:50 by kyekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "../libft/includes/libft.h"

typedef struct	s_stack
{
	int			*tab;
	int			size;
}				t_stack;

typedef struct	s_ab
{
	t_stack		*a;
	t_stack		*b;
	t_stack		*sa;
	t_stack		*sb;
	int			size;
}				t_ab;

typedef struct	s_move
{
	char		*type;
	int			(*move)(t_stack *, t_stack*);
}				t_move;

int				get_size(char **argv);
int				set(t_ab *arg, char **argv, int argc);
int				check_a(char **argv);
int				check_b(t_stack *a);
char			**check_space(char **argv);
int				check_valid(t_stack *a, t_stack *b);
void			free_ab(t_ab *arg);
void			free_stack(t_stack *stack);

int				move_check(t_ab *arg, char *move, int v);
int				move_pa(t_stack *a, t_stack *b);
int				move_pb(t_stack *a, t_stack *b);
int				move_ra(t_stack *a, t_stack *b);
int				move_rb(t_stack *a, t_stack *b);
int				move_rr(t_stack *a, t_stack *b);
int				move_rrr(t_stack *a, t_stack *b);
int				move_rra(t_stack *a, t_stack *b);
int				move_rrb(t_stack *a, t_stack *b);
int				move_sa(t_stack *a, t_stack *b);
int				move_sb(t_stack *a, t_stack *b);
int				move_ss(t_stack *a, t_stack *b);

#endif
