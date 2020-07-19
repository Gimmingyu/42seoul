#include <stdio.h>

int ft_atoi_base(char *str, char *base);

int main(void)
{
	char str[] = "1";
	char base[] = "0123456789abcdef";
	printf("str	: %s\n", str);
	printf("base	: %s\n", base);
	printf("result	: %d\n\n", ft_atoi_base(str, base));
	
	char str1[] = "10";
	char base1[] = "0123456789abcdef";
	printf("str	: %s\n", str1);
	printf("base	: %s\n", base1);
	printf("result	: %d\n\n", ft_atoi_base(str1, base1));

	char str2[] = "-1";
	char base2[] = "0123456789abcdef";
	printf("str	: %s\n", str2);
	printf("base	: %s\n", base2);
	printf("result	: %d\n\n", ft_atoi_base(str2, base2));

	char str3[] = "-10";
	char base3[] = "0123456789abcdef";
	printf("str	: %s\n", str3);
	printf("base	: %s\n", base3);
	printf("result	: %d\n\n", ft_atoi_base(str3, base3));

	return 0;
}
