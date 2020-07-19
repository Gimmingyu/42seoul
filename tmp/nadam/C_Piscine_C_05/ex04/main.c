#include <stdio.h>

int ft_fibonacci(int index);

int main(void)
{
	for(int i = -2; i < 10; i++)
		printf("%d, %d\n", i, ft_fibonacci(i));
	return 0;
}
