#include <stdio.h>

void ft_div_mod(int a, int b, int *div, int *mod);

int main(void)
{
	int a = 11;
	int b = 5;

	printf("%d, %d\n", a, b);

	int div = -1;
	int mod = -1;
	
	ft_div_mod(a, b, &div, &mod);

	printf("%d, %d\n", div, mod);


	return (0);
}
