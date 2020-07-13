#include <stdlib.h>
#include <stdio.h>

int	*ft_range(int min, int max);

int main(void)
{
	int *arr = ft_range(0, 10);
	int i = 0;
	while(i < 10)
	{
		printf("%d ", arr[i]);
		i++;
	}
	printf("\n");
	free(arr);
	return 0;
}
