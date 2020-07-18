#include "ft_h.h"

int		ft_atoi(char *str)
{
	int		i;
	int		sign;
	int 	res;

	i = 0;
	sign = 0;
	res = 0;
	while (str[i])
	{
		if (i == 0 && str[i] == '-')
			sign = 1;
		if (str[i] >= '0' && str[i] <= '9')
			res = res * 10 + str[i] - '0';
		else
			break;
	}
	if (sign)
		res *= -1;
	return (res);
}

int		ft_power_ten(int power)
{
	int		i;
	int		res;

	i = 1;
	res = 10;
	if (power == 0)
		return (1);
	while (i++ < power)
		res *= 10;
	return (res);
}

int		*ft_origin_num_arr(char *str, int len)
{
	int 	*ar;
	int 	i;
	
	i = 0;
	// char_ar = (char *)malloc((len + 1) * sizeof(char));
	ar = (int *)malloc((len) * sizeof(int));
	while (str[i])
	{
		ar[i] = str[i] - '0';
		ar[i] *= ft_power_ten(--len);
		printf("%d\n", ar[i]);
		break;
		i++;
	}
	return (ar);
}
