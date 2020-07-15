int		ft_sqrt(int nb)
{
	int i;

	if (nb == 1)
		return (1);
	i = 1;
	while (i <= nb / 2)
	{
		if (i * i == nb)
			return (i);
		i++;
	}
	return (0);
}