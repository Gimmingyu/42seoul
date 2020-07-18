#ifndef FT_H_H
# define FT_H_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

/* 
** save dict info
*/
typedef struct	s_dict
{
	int		size;
	char	key;
	char	value;
}						t_dict;

/*
** ft_str.c
*/
int		ft_strlen(char *str);
int		ft_strcmp(char *str1, char *str2);
void	ft_putstr(char *str);

/*
** ft_num.c
*/
int		ft_atoi(char *str);
int		ft_power_ten(int power);
int		*ft_origin_num_arr(char *str, int len);

/*
** ft_file.c
*/
void	ft_read_txt(char *dict_name);

#endif
