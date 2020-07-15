#include <stdio.h>

int ft_sqrt(int nb);

int main(void)
{
	for(int i = -4; i < 20; i++)
		printf("%d, %d\n", i, ft_sqrt(i));
	return 0;
}