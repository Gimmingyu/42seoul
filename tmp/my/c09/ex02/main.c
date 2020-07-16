#include <stdio.h>

char **ft_split(char *str, char *charset);
/*
int main()
{
//	char str[500] = "XU07 LEg11AIG62obhz0 HPmB6PhMxGYGGPjiAbsa";
	char str[500] = "1a234567a89123456789";
//	char charset[100] = "bR6rDPUz";
	char charset[100] = "a";
//	char charset[100] = "seg";
	char **result = ft_split(str, charset);

	for (int i = 0; result[i]; i++)
		printf("i=%d, %s\n", i, result[i]);
	
	return 0;
}
*/


#include <stdio.h>
int main()
{
//	char **a = ft_split("                    ", "     ");
//	char **a = ft_split("gUx8xf1PCzQmiwbsBHuoYw9Mim8OyS32nDIzwxztKe       ta", "sy5Lr");
//	char **a = ft_split("AaBbCCcDDDdDDDeAAAfEA", "abcdef");
	char **a = ft_split("LsLUoqPh7tZbnmRfRq3uhKMMnY6EEW6zAiXA", "");
	for(int i = 0; i < 11111; i++)
	{
		if(a[i] == 0)
			break;
		printf("[%s]\n", a[i]);
	}
}

