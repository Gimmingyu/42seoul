#include <stdio.h>

int *ft_map(int *tab, int length, int (*f)(int));

int my_func(int n)
{
	return (n * n);
}

int main()
{
	int arr[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	int *result = ft_map(arr, 10, &my_func);
	for (int i = 0; i < 10; i++)
		printf("i -> %d\n", result[i]);
	return 0;
}
