#include <stdlib.h>
#include <stdio.h>

char *ft_strjoin(int size, char **strs, char *sep);

int main(void)
{
	char *strs[7] = {
		"abc",
		"123",
		"def",
		"456",
		"ghi",
		"789",
		"AABBCCDDAABBCCDD"
	};
	char sep[] = "+";
	char *result = ft_strjoin(0, strs, sep);	
	printf("%p\n%s\n", result, result);

	return 0;
}