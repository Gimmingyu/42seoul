/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_h.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyekim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/18 12:08:44 by kyekim            #+#    #+#             */
/*   Updated: 2020/07/19 22:35:38 by jopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H_H
# define FT_H_H

# include <stdlib.h>
# include <unistd.h>

/* 
** save dict info
*/
typedef struct	s_dict
{
	char			*key;
	char			*value;
	struct	s_dict	*next;
}				t_dict;

typedef struct	s_list
{
	t_dict *head;
}				t_list;

char    g_list[1000][1000];
int     g_len;

/*
** ft_str.c
*/
int     ft_strlen(char *str);
int     ft_strcmp(char *str1, char *str2);
void    ft_putstr(char *str);
char    *ft_strrev(char *str, int len);
char    *ft_strcat(char *str1, char *str2);
char    *ft_strcpy(char *dest, const char *src);

/*
** ft_num.c
*/
//long long	ft_atoi(char *str);
char    *ft_power_ten(int power);
void    ft_grouping_num_three(char *str, int len);
void    ft_make_num_forms(char *str, int flag);
char    *ft_make_unique_forms(int i);
char    *ft_multi_concate(char *st1, char *str2);

/*
** ft_file.c
*/
int		ft_read_txt(char *dict_name);

/*
** dict.c
*/
void	add_dict(t_list *ptr, char *num, char *alp);
t_list*	init(void);
void	print_list(t_list *ptr);
int		ft_find(t_list *ptr, char *s_key);
void        ft_free(t_list *ptr);

/*
** exception.c
*/
int		ft_check_int(char *s);
int     ft_check_print_able(char *s);


#endif
