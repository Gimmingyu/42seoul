
#include <stdlib.h>
#include "ft_list.h"

void ft_list_clear(t_list *begin_list, void (*free_fct)(void *))
{
	t_list *curr;
	t_list *temp;

	if (free_fct == 0)
		return ;
	curr = begin_list;
	while (curr)
	{
		temp = curr;
		curr = curr->next;
		free_fct(temp->data);
		free(temp);
	}
}
