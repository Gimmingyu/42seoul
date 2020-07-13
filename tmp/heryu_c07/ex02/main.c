#include <stdio.h>

int		ft_ultimate_range(int **range, int min, int max);

int		main(void)
{
	int *arr = NULL;
	int i = 0;

	int n = ft_ultimate_range(&arr, 0, 10);
	printf("n : %d\n", n);
	while(i < 10)
	{
		printf("%d ", arr[i]);
		i++;
	}
	printf("\n");
	return 0;
}
