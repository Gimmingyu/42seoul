#include <unistd.h>

void ft_foreach(int *tab, int length, void(*f)(int));

void ft_putnbr(int n)
{
	char temp = n + '0';
	write(1, &temp, 1);
}

int main()
{
	int size = 8;
	int arr[8] = {1, 2, 3, 4, 5, 6, 7, 8};
	ft_foreach(arr, size, *ft_putnbr);
	return 0;
}
