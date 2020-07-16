
#include "ft_list.h"

t_list *ft_list_at(t_list *begin_list, unsigned int nbr)
{
	unsigned int	i;
	t_list		*curr;

	if (begin_list == 0)
		return (0);
	i = 0;
	curr = begin_list;
	while (curr && i < nbr)
	{
		curr = curr->next;
		i++;
	}
	if (curr == 0 || i != nbr)
		return (0);
	return (curr);
}
