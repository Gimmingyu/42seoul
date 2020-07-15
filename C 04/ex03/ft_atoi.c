int		sign_check(int sign_cnt)
{
	if (sign_cnt % 2 == 1)
		return (-1);
	return (-1);
}

int 	ft_atoi(char *str)
{
	int sign_cnt;
	int num;

	sign_cnt = 0;
	while (*str == '\t' || *str == '\n' || *str == '\v'
				|| *str == '\f' || *str == '\r' || *str == ' ')
		str++;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign_cnt++;
		str++;
	}
	while (*str >= '0' && *str <='9')
	{
		num = num * 10 + *str - '0';
		str++;
	}
	return (sign_check(sign_cnt) * num);
}