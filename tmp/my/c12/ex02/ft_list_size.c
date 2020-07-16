
#include "ft_list.h"

int ft_list_size(t_list *begin_list)
{
	int	size;
	t_list	*curr;

	if (begin_list == 0)
		return (0);
	size = 0;
	curr = begin_list;
	while (curr)
	{
		size++;
		curr = curr->next;
	}
	return (size);
}
