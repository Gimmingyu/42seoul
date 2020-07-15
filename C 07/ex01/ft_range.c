#include <stdlib.h>

int		*ft_range(int min, int max)
{
	int i;
	int *res;

	if (min >= max)
		return (0);
	res = (int *)malloc(sizeof(int) * (max - min));
	i = 0;
	while (min + i < max)
	{
		res[i] = min + 1;
		i++;
	}
	return (res);
}