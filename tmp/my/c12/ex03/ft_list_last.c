
#include "ft_list.h"

t_list *ft_list_last(t_list *begin_list)
{
	t_list *curr;

	if (begin_list == 0)
		return (0);
	curr = begin_list;
	while (curr->next)
		curr = curr->next;
	return (curr);
}
