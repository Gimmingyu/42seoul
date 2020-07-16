
#include "ft_list.h"

void	ft_list_push_front(t_list **begin_list, void *data)
{
	t_list *new_elem;

	new_elem = ft_create_elem(data);
	if (new_elem == 0)
		return ;
	if (begin_list != 0)
		new_elem->next = *begin_list;
	*begin_list = new_elem;
}

t_list *ft_list_push_strs(int size, char **strs)
{
	int i;
	t_list *begin_list;

	if ((begin_list = ft_create_elem(strs[0])) == 0)
		return (0);
	i = 1;
	while (i < size)
	{
		ft_list_push_front(&begin_list, strs[i]);
		i++;
	}
	return (begin_list);
}
