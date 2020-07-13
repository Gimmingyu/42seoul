#include <stdio.h>
#include <stdlib.h>
char	*ft_convert_base(char *nbr, char *base_from, char *base_to);

int main(void)
{
	char *ret;

	ret = ft_convert_base("   +++----123456", "0123456789", "0123456789ABCDEF");
	printf("%s\n", ret);
	free(ret);
	ret = ft_convert_base("   +-++----15", "0123456789", "0123456789ABCDEF");
	printf("%s\n", ret);
	free(ret);
	ret = ft_convert_base("   +++----F", "0123456789ABCDEF", "01");
	printf("%s\n", ret);
	free(ret);
	return 0;
}
