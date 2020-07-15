#include <stdio.h>

int *ft_range(int min, int max);

int main(void)
{
	int min = 0;
	int max = 10;
	int *result = ft_range(min, max);
	for(int i = 0; i < max - min; i++)
		printf("%d ", result[i]);
	printf("\n");
	return 0;
}
