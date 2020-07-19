#include <stdio.h>

void ft_sort_int_tab(int *tab, int size);

int main(void)
{
	int size = 6;
	int a[6] = {1 , 32, -13, 541, 11, 2};

	ft_sort_int_tab(a, size);

	for(int i = 0; i < size; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}
