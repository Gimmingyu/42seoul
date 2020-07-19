#include <stdio.h>
#include <string.h>

int ft_strlen(char *str);

int main(void)
{
	char str[10];

	str[0] = 'a';
	str[1] = '9';
	str[2] = ' ';
	str[3] = 'c';
	str[4] = 'd';
	str[5] = '\0';

	int len = ft_strlen(str);
	printf("%d, %lu\n", len, strlen(str));
	return 0;
}
