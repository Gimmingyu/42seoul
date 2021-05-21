/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyekim <kyekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 16:11:55 by kyekim            #+#    #+#             */
/*   Updated: 2021/05/12 16:11:56 by kyekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack	*copy_stack(t_stack *a, t_stack *sa)
{
	int		i;
	t_stack	*cpy;

	i = 0;
	if (!(cpy = (t_stack*)malloc(sizeof(t_stack))))
		return (NULL);
	if (!(cpy->tab = (int*)malloc(sizeof(int) * a->size + 10)))
		return (NULL);
	if (sa->size == 0)
	{
		while (i < a->size)
		{
			cpy->tab[i] = a->tab[i];
			i++;
		}
	}
	else
	{
		i = -1;
		while (sa->tab[sa->size - 1] != a->tab[++i] && i < a->size)
			cpy->tab[i] = a->tab[i];
	}
	cpy->size = i;
	return (cpy);
}

int		get_size(char **argv)
{
	int		i;
	int		j;
	int		ret;
	char	**new_av;

	i = 1;
	j = 0;
	ret = 0;
	while (argv[i])
	{
		if (!(new_av = ft_strsplit(argv[i], ' ')))
			return (-1);
		while (new_av[j])
		{
			j++;
			ret += 1;
		}
		j = 0;
		ft_strdel_d(new_av);
		i++;
	}
	return (ret);
}

void	free_stack(t_stack *stack)
{
	if (stack->tab)
		free(stack->tab);
	if (stack)
		free(stack);
}

void	free_ab(t_ab *arg)
{
	if (arg->a)
		free_stack(arg->a);
	if (arg->b)
		free_stack(arg->b);
	if (arg->sa)
		free_stack(arg->sa);
	if (arg->sb)
		free_stack(arg->sb);
}
