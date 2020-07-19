/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jko <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 20:28:04 by jko               #+#    #+#             */
/*   Updated: 2020/02/09 19:58:06 by jko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "dict.h"

t_dict	*make_dict(char *key, char *value)
{
	t_dict	*new_dict;

	if (key == 0 || value == 0)
		return (0);
	new_dict = (t_dict *)malloc(sizeof(t_dict));
	if (new_dict == 0)
		return (0);
	new_dict->key = key;
	new_dict->value = value;
	new_dict->next = 0;
	return (new_dict);
}

void	free_dict(t_dict *dict)
{
	free(dict->key);
	free(dict->value);
	dict->next = 0;
	free(dict);
}
