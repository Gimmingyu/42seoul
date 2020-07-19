void ft_putstr(char *str);

int main(void)
{
	char str[8];

	str[0] = 'a';
	str[1] = 'b';
	str[2] = 'c';
	str[3] = 'd';
	str[4] = '\0';

	ft_putstr(str);
}
