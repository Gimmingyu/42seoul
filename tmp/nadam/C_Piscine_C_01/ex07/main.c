#include <stdio.h>

void ft_rev_int_tab(int *tab, int size);

int main(void)
{
	int aa[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int size = 10;

	ft_rev_int_tab(aa, size);

	for(int i = 0; i < 10; i++)
	{
		printf("%d ", aa[i]);
	}
}
