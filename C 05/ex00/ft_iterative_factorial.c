int		ft_iterative_factorial(int nb)
{
	int res;

	if (nb < 0)
		return (0);
	res = 1;
	while (nb-- > 0)
		res *= nb;
	return (res);
}