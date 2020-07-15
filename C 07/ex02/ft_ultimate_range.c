#include <stdlib.h>

int		ft_ultimate_range(int **range, int min, int max)
{
	int i;

	if (min >= max)
	{
		range = 0;
		return (0);
	}
	*range = (int *)malloc(sizeof(int) * (max - min));
	i = 0;
	while (min + i < max)
	{
		(*range)[i] = min + i;
		i++;
	}
	return (max - min);
}