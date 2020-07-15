#include <stdio.h>

int		ft_atoi(char *str);

int		main(void)
{
	printf("%d\n", ft_atoi("0"));
	printf("%d\n", ft_atoi("1"));
	printf("%d\n", ft_atoi("10"));
	printf("%d\n", ft_atoi("123"));
	printf("%d\n", ft_atoi("1234"));
	printf("%d\n", ft_atoi("1234567890"));
	printf("%d\n", ft_atoi("-1"));
	printf("%d\n", ft_atoi("-10"));
	printf("%d\n", ft_atoi("-1234"));
	printf("%d\n", ft_atoi("-1234567890"));
	printf("%d\n", ft_atoi("  \t \r ---123tt"));
	printf("%d\n", ft_atoi(""));
	printf("%d\n", ft_atoi("- + -+ - + 2-1 b"));
	return (0);
}