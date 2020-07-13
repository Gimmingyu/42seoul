#include <stdio.h>

char *ft_strjoin(int size, char **strs, char *sep);

int main(int argc, char **argv)
{
	char *sep = "---";

	char *ptr = ft_strjoin(argc, argv, sep);
	printf("%s\n", ptr);

	return (0);
}
