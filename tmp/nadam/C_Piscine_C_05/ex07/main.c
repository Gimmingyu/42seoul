#include <stdio.h>

int	ft_find_next_prime(int nb);

int main(void)
{
	for (int i = -3; i < 25; i++)
		printf("%d, %d\n", i, ft_find_next_prime(i));
	printf("%d\n", ft_find_next_prime(2147483647));
	return 0;
}
