#include <stdio.h>

void ft_putnbr(int nb);

int main()
{
	ft_putnbr(1);
	printf(", 1\n");
	
	ft_putnbr(10);
	printf(", 10\n");
	
	ft_putnbr(123);
	printf(", 123\n");
	
	ft_putnbr(-1);
	printf(", -1\n");
	
	ft_putnbr(-55555);
	printf(", -55555\n");

	ft_putnbr(0);
	printf(", 0\n");

	ft_putnbr(-22);
	printf(", -22\n");
}
