
#include <stdio.h>
#include <stdlib.h>
#include "ft_list.h"

void ft_list_push_front(t_list **begin_list, void *data);
int ft_list_size(t_list *begin_list);
t_list *ft_list_last(t_list *begin_list);
void ft_list_push_back(t_list **begin_list, void *data);
t_list *ft_list_push_strs(int size, char **strs);

int main(void)
{
	/*
	t_list **begin_list = (t_list **)malloc(sizeof(t_list *));

	printf("size = %d\n", ft_list_size(*begin_list));
	ft_list_push_front(begin_list, "world!");
	printf("size = %d\n", ft_list_size(*begin_list));
	ft_list_push_front(begin_list, "hello");
	printf("size = %d\n", ft_list_size(*begin_list));
	ft_list_push_back(begin_list, "good");

	t_list *curr = *begin_list;
	while (curr)
	{
		printf("%s\n", curr->data);
		curr = curr->next;
	}

	curr = ft_list_last(*begin_list);
	printf("last data = %s\n", curr->data);
	*/

	int size = 4;
	char **strs = (char **)malloc(sizeof(char *) * size);
	strs[0] = "hello";
	strs[1] = "world";
	strs[2] = "good";
	strs[3] = "bye";

	t_list *curr = ft_list_push_strs(size, strs);
	while (curr)
	{
		printf("%s\n", curr->data);
		curr = curr->next;
	}
	return (0);
}

t_list *ft_create_elem(void *data)
{
	t_list *elem;

	elem = (t_list *)malloc(sizeof(t_list));
	if (elem == 0)
		return (0);
	elem->data = data;
	elem->next = 0;
	return (elem);
}

/*
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
*/

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
