#include <stdlib.h>

char	*ft_strdup(char *src)
{
	char *res;
	int i;

	i = 0;
	while (src[i])
		i++;
	res = (char *)malloc(sizeof(char) * (i + 1));
	while (src[i])
	{
		res[i] = src[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}