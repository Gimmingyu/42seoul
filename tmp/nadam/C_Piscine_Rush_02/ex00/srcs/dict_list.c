/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jko <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 20:57:28 by jko               #+#    #+#             */
/*   Updated: 2020/02/09 21:31:24 by jko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_string.h"
#include "dict.h"

t_dict	*change_dict_value(t_dict *dict, t_dict *new_dict)
{
	free(dict->value);
	dict->value = new_dict->value;
	free(new_dict->key);
	free(new_dict);
	return (dict);
}

t_dict	*add_dict_list(t_dict *head, t_dict *new_dict)
{
	t_dict *curr;

	if (head == 0)
		return (new_dict);
	curr = head;
	while (curr->next)
		curr = curr->next;
	curr->next = new_dict;
	return (new_dict);
}

t_dict	*find_dict_in_list(t_dict *head, char *key)
{
	t_dict	*curr;

	if (head == 0)
		return (0);
	if (ft_strcmp(head->key, key) == 0)
		return (head);
	curr = head;
	while (curr->next)
	{
		if (ft_strcmp(curr->key, key) == 0)
			return (curr);
		curr = curr->next;
	}
	return (0);
}

void	free_dict_list(t_dict *head)
{
	t_dict *curr;
	t_dict *temp;

	if (head == 0)
		return ;
	curr = head;
	while (curr->next)
	{
		temp = curr;
		curr = curr->next;
		free_dict(temp);
	}
}
