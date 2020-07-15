#include <unistd.h>

int		ft_strcmp(char *s1, char *s2)
{
	while ((*s1 == *s2) && *s1 != '\0')
	{
		s1++;
		s2++;
	}
	return (*(unsigned char*)s1 - *(unsigned char*)s2);
}

void	ft_sort_string(char *str[], int size)
{
	int i;
	int j;
	char *tmp;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - 1 - i)
		{
			if (ft_strcmp(str[j], str[j + 1]) < 0)
			{
				tmp = str[j];
				str[j] = str[j + 1];
				str[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

void	ft_putstr(char *str)
{
	while (*str++ != '\0')
		write(1, str, 1);
}

int		main(int argc, char *argv[])
{
	int i;

	i = argc - 1;
	ft_sort_string(argv + 1, argc - 1);
	while (i-- > 0)
	{
		ft_putstr(argv[i]);
		write(1, "\n", 1);
	}
	return (0);
}