#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void ft_advanced_sort_string_tab(char **tab, int (*cmp)(char *, char *));
/*
int main()
{
	char **tab = (char **)malloc(sizeof(char *) * 6);
	tab[0] = "abc";
	tab[1] = "a";
	tab[2] = "aa";
	tab[3] = "123";
	tab[4] = "21333";
	tab[5] = 0;
	ft_advanced_sort_string_tab(tab, strcmp);
	for(int i = 0; tab[i]; i++)
		printf("%s\n", tab[i]);

	return 0;
}
*/

int my_func(char *s1, char *s2)
{
	int i;
	int j;

	i = 0;
	while (s1[i])
		i++;
	j = 0;
	while (s2[j])
		j++;
	if (i == j)
		return (0);
	if (i > j)
		return (1);
	return (-1);
}

int main()
{
	int size = 15;
	char **tab = (char **)malloc(sizeof(char *) * (size + 1));

	tab[0] ="EyWjaceYO";
	tab[1] ="JGl9HzKWBYV";
	tab[2] ="jsBOM";
	tab[3] ="EfU5ajAGH";
	tab[4] ="KR3";
	tab[5] ="0rL5zvuU";
	tab[6] ="Pezg";
	tab[7] ="qQjC47oBb";
	tab[8] ="ikgL";
	tab[9] ="N";
	tab[10] ="BMUuJjr";
	tab[11] ="tInjlFc";
	tab[12] ="eHr";
	tab[13] ="zfu09Sr";
	tab[14] ="A3mIjzo";
	tab[15] = 0;
/*
	tab[0] ="0";
	tab[1] ="01";
	tab[2] ="012";
	tab[3] ="0123";
	tab[4] ="01234";
	tab[5] ="012345";
	tab[6] ="0123456";
	tab[7] ="01234567";
	tab[8] ="012345678";
	tab[9] ="0123456789";
	tab[10] ="0123456789a";
	tab[11] ="0123456789ab";
	tab[12] ="0123456789abc";
	tab[13] ="0123456789abcd";
	tab[14] ="0123456789abcde";
	tab[15] = 0;
*/
	ft_advanced_sort_string_tab(tab, &my_func);
	for(int i = 0; tab[i]; i++)
		printf("%s\n", tab[i]);

	return 0;
}
