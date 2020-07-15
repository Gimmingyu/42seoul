#include <stdio.h>
#include <string.h>

char *ft_strdup(char *src);

int main(void)
{
	char src[] = "abc";
	printf("%s\n%s\n\n", ft_strdup(src), strdup(src));
	char src2[] = "123";
	printf("%s\n%s\n\n", ft_strdup(src2), strdup(src2));
	char src3[] = "abcdefg";
	printf("%s\n%s\n\n", ft_strdup(src3), strdup(src3));
	char src4[] = "!@#";
	printf("%s\n%s\n\n", ft_strdup(src4), strdup(src4));
	char src5[] = "";
	printf("%s\n%s\n\n", ft_strdup(src5), strdup(src5));
	char src6[] = "1aw6e5f6aw5";
	printf("%s\n%s\n\n", ft_strdup(src6), strdup(src6));
	return 0;
}