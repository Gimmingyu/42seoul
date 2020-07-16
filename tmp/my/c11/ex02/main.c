#include <stdio.h>
#include <stdlib.h>

int ft_any(char **tab, int (*f)(char *));

int my_func(char *str)
{
	int len;

	len = 0;
	while (str[len])
	{
		len++;
		if (len >= 5)
			return (1);
	}
	return (0);
}

int main()
{
	char **tab = (char **)malloc(sizeof(char *) * 6);
	tab[0] = "123";
	tab[1] = "1";
	tab[2] = "1234";
	tab[3] = "1234";
	tab[4] = "123";
	tab[5] = 0;
	printf("%d\n", ft_any(tab, &my_func));
	return 0;
}
