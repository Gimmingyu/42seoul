#include <stdio.h>
#include "ft_list.h"

t_list *ft_create_elem(void *data);

int main(void)
{
	char *str = "hello world!";
	t_list *node = ft_create_elem(str);
	printf("data = %s\n", node->data);
	printf("next = %p\n", node->next);
	return (0);
}
