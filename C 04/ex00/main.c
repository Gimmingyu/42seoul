#include <stdio.h>
#include <string.h>

int	ft_strlen(char *str);

int	main(void)
{
	char str[] = "123abc";
	printf("%d, %lu\n", ft_strlen(str), strlen(str));
	return (0);
}