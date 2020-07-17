#include "ft_h.h"

void	tmp(char *str)
{
	int *ar;
	int i;

	i = 0;
	ar = ft_origin_num_arr(str);
	while (i < 2)
	{
		write(1, &ar[i], 1);
		write(1, "\n", 1);
	}
}

int		main(int argc, char *argv[])
{
	// char *origin_dict;
	
	// origin_dict = "numbers.dict";
	
	if (argc == 2)
	{
		ft_putstr(argv[1]);
		tmp(argv[1]);
	}
	//else if (argc == 3)
		//find_new_dict(argv[2])

	return (0);
}