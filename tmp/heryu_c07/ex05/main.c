#include <stdio.h>

char **ft_split(char *str, char *charset);

int main(void)
{
	char    **ret;
	int     i;
	ret = ft_split("#####FFF######", "#");
	i = 0;
    while (ret[i] != (void*)0)
    {
		printf("%s\n", ret[i]);
		i++;
	}
	ret = ft_split("#####FFF######F", "#");
	i = 0;
    while (ret[i] != (void*)0)
    {
		printf("%s\n", ret[i]);
		i++;
	}
	ret = ft_split("F#####FFF######F", "#");
	i = 0;
    while (ret[i] != (void*)0)
    {
		printf("%s\n", ret[i]);
		i++;
	}
	ret = ft_split("F#F#F#F", "#");
	i = 0;
    while (ret[i] != (void*)0)
    {
		printf("%s\n", ret[i]);
		i++;
	}
	return 0;
}
