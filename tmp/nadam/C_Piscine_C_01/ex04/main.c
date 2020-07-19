#include <stdio.h>

void ft_ultimate_div_mod(int *a, int *b);
int main(void)
{

	int a = 11;
	int b = 2;

	ft_ultimate_div_mod(&a, &b);

	printf("%d, %d\n", a, b);




	return 0;
}
