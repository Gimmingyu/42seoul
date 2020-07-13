#include <stdio.h>
#include <stdlib.h>

char *ft_strdup(char *src);

int main(void)
{
	char * src = "HelloWorld";
	char * ret = ft_strdup(src);
	int i = 0;
	while(i < 11)
	{
		printf("%c : %c\n", ret[i], src[i]);
		i++;
	}

	return 0;
}
