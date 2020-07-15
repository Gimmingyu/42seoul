int		is_prime(int n)
{
	int i;
	int temp;

	if (n < 2)
		return (0);
	i = 2;
	while (i <= n / 2 && i <= 65536)
	{
		if (n % i == 0)
			return (0);
		i++;
	}
	return (1);
}

int		ft_find_next_prime(int nb)
{
	while (is_prime(nb) == 0)
		nb++;
	return (nb);
}