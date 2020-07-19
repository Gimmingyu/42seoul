#include <stdio.h>

void ft_print_combn(int n);

int main(void)
{
	for(int i = 1; i < 10; i++)
	{
		printf("start %d\n", i);
		ft_print_combn(i);
		printf("\n");
	}
}
