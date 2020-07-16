
#include <stdio.h>
#include <stdlib.h>
#include "ft_list.h"

void ft_list_push_front(t_list **begin_list, void *data);
int ft_list_size(t_list *begin_list);
t_list *ft_list_last(t_list *begin_list);
void ft_list_push_back(t_list **begin_list, void *data);
t_list *ft_list_push_strs(int size, char **strs);
void ft_list_clear(t_list *begin_list, void (*free_fct)(void *));

void free_data(void *data)
{
	free(data);
}

int main(void)
{
	int size = 2;
	char **strs = (char **)malloc(sizeof(char *) * size);
	strs[0] = (char *)malloc(sizeof(char) * 6);
	for (int i = 0; "hello"[i]; i++)
		strs[0][i] = "hello"[i];
	strs[0][5] = 0;
	strs[1] = (char *)malloc(sizeof(char) * 6);
	for (int i = 0; "world"[i]; i++)
		strs[1][i] = "world"[i];
	strs[1][5] = 0;
	/*
	strs[2] = "good";
	strs[3] = "bye";
	*/


	t_list *begin_list = ft_list_push_strs(size, strs);
	t_list *curr = begin_list;
	while (curr)
	{
		printf("%s\n", curr->data);
		curr = curr->next;
	}
	ft_list_clear(begin_list, &free_data);
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
