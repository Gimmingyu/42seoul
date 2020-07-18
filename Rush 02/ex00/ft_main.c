#include "ft_h.h"

void	tmp(char *str)
{
	int *ar;
	int len;

	len = ft_strlen(str);
	ar = ft_origin_num_arr(str, len);
	
	while (--len >= 0)
		printf("\n%d", ar[len]);
}

int		main(int argc, char *argv[])
{
	// char *origin_dict;
	
	// origin_dict = "numbers.dict";
	
	if (argc == 2)
	{
		//tmp(argv[1]);
		ft_read_txt("numbers.dict");
		tmp(argv[1]);
	}
	//else if (argc == 3)
		//find_new_dict(argv[2])

	return (0);
}
