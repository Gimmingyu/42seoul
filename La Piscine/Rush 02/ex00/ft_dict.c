/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dict.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/18 17:41:58 by jopark            #+#    #+#             */
/*   Updated: 2020/07/18 21:32:57 by jopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_h.h"

t_list		*init(void)
{
	t_list *ptr;

	ptr = (t_list *)malloc(sizeof(t_list));
	if (!ptr)
		return (NULL);
	ptr->head = NULL;
	return (ptr);
}

void		print_list(t_list *ptr)
{
	t_dict *temp;

	temp = ptr->head;
	while (temp->next != NULL)
	{
		printf("%s : %s\n", temp->key, temp->value);
		temp = temp->next;
	}
}

void		ft_free(t_list *ptr)
{
	t_dict *current;
	t_dict *temp;
	
	current = ptr->head;
	while (current->next != NULL)
	{
		temp = current->next;
		free(current);
		current = temp;
	}
}

void		add_dict(t_list *ptr, char *num, char *alp)
{
	t_dict *new;
	t_dict *current;

	new = (t_dict *)malloc(sizeof(t_dict));
	if (!new)
		return ;
	new->key = num;
	new->value = alp;
	new->next = NULL;
	if (ptr->head == NULL)
	{
		ptr->head = new;
		return ;
	}
	else
	{
		current = ptr->head;
		while (current->next != NULL)
		{
			current = current->next;
		}
		current->next = new;
	}
}

int			ft_find(t_list *ptr, char *s_key)
{
	t_dict *current;

	current = ptr->head;
	while (current->next != NULL)
	{
		if (ft_strcmp(current->key, s_key) == 0)
		{
			printf("%s ", current->value);
		}
		current = current->next;
	}
	return (0);
}
