#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int a;
	printf("int a = %d\n", a);

	int *p;
	printf("int *p = %p\n", p);

	p = (int *)malloc(sizeof(int));
	printf("malloc p = %p\n", p);
	free(p);
	printf("free p = %p\n", p);
//	free(p);
	free(0);
	free(0);

	char c;
	printf("char c = %d\n", c);

	int arr[5];
	for (int i = 0; i < 5; i++)
		printf("arr[%d] = %d\n", i, arr[i]);
	for (int i = 0; i < 5; i++)
	{
		arr[i] = i;
		printf("arr[%d] = %d\n", i, arr[i]);
	}
	return (0);
}
