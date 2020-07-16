#include <stdio.h>
#include <stdlib.h>

int ft_count_if(char **tab, int length, int (*f)(char *));

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

int main(void)
{
	int length = 5;
	char **tab = (char **)malloc(sizeof(char *) * length);

	tab[0] = "12345";
	tab[1] = "12345";
	tab[2] = "12345";
	tab[3] = "1";
	tab[4] = "12345";
//	tab[5] = "";

	printf("%d\n", ft_count_if(tab, length, &my_func));
	return 0;
}
