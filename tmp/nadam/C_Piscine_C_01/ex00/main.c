#include <unistd.h>

void ft_ft(int *nbr);

int main(void)
{
	int a;
	char c[3];

	c[1] = ' ';
	c[2] = '\n';

	a = 1;
	c[0] = a + 48;
	write(1, &c, 3);

	ft_ft(&a);
	c[0] = a /10 + 48;
	write(1, &c, 1);
	c[0] = a % 10 + 48;
	write(1, &c, 3);


	return (0);
}
