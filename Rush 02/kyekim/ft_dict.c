#include "ft_h.h"

t_list* init(void)
{
	t_list *ptr = (t_list *)malloc(sizeof(t_list));
	ptr->head = NULL;
	return (ptr);
}

void	print_list(t_list *ptr)
{
	t_dict *temp = ptr->head;
	while (temp->next != NULL)
	{
		//print(temp->key, temp->value);
		temp = temp->next;
	}
}

void	add_dict(t_list *ptr, char *num, char *alp)
{
	t_dict *new = (t_dict *)malloc(sizeof(t_dict));
	new->key = num;
	new->value = alp;
	new->next = NULL;
	
	if (ptr->head == NULL)
	{
		ptr->head = new;
		return ;
	}
	else
	{
		t_dict *current = ptr->head;
		while (current->next != NULL)
		{
			//print(current->key, current->value);
			current = current->next;
		}
		current->next = new;
	}
}

void	ft_find(t_list *ptr, char *s_key)
{
	t_dict *current = ptr->head;
	while (current->next != NULL)
	{
		if (ft_strcmp(current->key, s_key) == 0)
			//print(current->value);
		current = current->next;
	}
}
