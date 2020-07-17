#include "ft_h.h"

/*
** [ft_strlen] calc the length of params, except NULL
*/
int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

/*
** [ft_strcmp] compare two string, return the difference of ASCII
*/
int		ft_strcmp(char *str1, char *str2)
{
	while ((*str1 == *str2) && *str1 != '\0')
	{
		str1++;
		str2++;
	}
	return (*(unsigned char*)str1 - *(unsigned char*)str2);
}