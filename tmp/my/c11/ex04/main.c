#include <stdio.h>

int ft_is_sort(int *tab, int length, int (*f)(int, int));

int my_func(int n1, int n2)
{
	return (n1 - n2);
}

int main(void)
{
	int length = 10;
	int tab[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 7};
	printf("%d\n", ft_is_sort(tab, length, &my_func));
	int tab1[] = {-1, -1, -2, -3, -4, -5, -6, -7, -8, -8};
	printf("%d\n", ft_is_sort(tab1, length, &my_func));
	int tab2[] = {0,0,0,0,0,0,0,0,0,0};
	printf("%d\n", ft_is_sort(tab2, length, &my_func));
  	int tab3[] = {0,-1,2};
	printf("%d\n", ft_is_sort(tab3, 0, &my_func));
 
	return 0;
}
