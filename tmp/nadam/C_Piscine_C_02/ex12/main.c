#include <stdio.h>

void	*ft_print_memory(void *addr, unsigned int size);

int main()
{
	char str[70];
	char a = '!';
	for(int i = 0; i < 70; i++)
		str[i] = a++;
	ft_print_memory((void *)str, 70);

	char str2[92];
	int ttemp[23] = {0x426f6e6a, 0x6f757220, 0x6c657320, 0x616d696e, 0x63686573, 0x090a0963, 0x20206573, 0x7420666f, 0x7509746f, 0x75740963, 0x65207175, 0x206f6e20, 0x70657574, 0x20666169, 0x72652061, 0x76656309, 0x0a097072, 0x696e745f, 0x6d656d6f, 0x72790a0a, 0x0a096c6f, 0x6c2e6c6f, 0x6c0a2000};
	for(int i = 0; i < 24; i++){
		str2[4 * i] = ttemp[i] / 16 / 16 / 16 / 16 / 16 / 16;
		str2[4 * i + 1] = ttemp[i] / 16 / 16 / 16 / 16;
		str2[4 * i + 2] = ttemp[i] / 16 / 16;
		str2[4 * i + 3] = ttemp[i];
	}
	ft_print_memory((void *)str2, 92);
	ft_print_memory((void *)str2, 91);

	char str3[5] = "abcde";
	str3[0] = 0x5a;
	ft_print_memory((void *)str3, 5);
	return 0;
}
