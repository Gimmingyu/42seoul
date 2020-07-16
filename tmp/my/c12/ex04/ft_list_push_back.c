
#include "ft_list.h"

void	ft_list_push_back(t_list **begin_list, void *data)
{
	t_list *new_list;
	t_list *curr;

	if (begin_list == 0)
		return ;
	new_list = ft_create_elem(data);
	if (new_list == 0)
		return ;
	if (*begin_list == 0)
	{
		*begin_list = new_list;
		return ;
	}
	curr = *begin_list;
	while (curr->next)
		curr = curr->next;
	curr->next = new_list;
}
