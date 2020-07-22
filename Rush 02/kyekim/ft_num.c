/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_num.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyekim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/18 12:08:50 by kyekim            #+#    #+#             */
/*   Updated: 2020/07/19 23:41:28 by kyekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_h.h"

char	*ft_multi_concate(char *str1, char *str2)
{
	char	*res;

	res = ft_strcat(str1, str2);
	return (res);
}

char	*ft_power_ten(int power)
{
	char	*res;
	int		i;

	i = 0;
	res = (char *)malloc((power * 3 + 2) * sizeof(char));
	res[i++] = '1';
	while (i < power * 3 + 1)
		res[i++] = '0';
	res[i] = '\0';
	return (res);
}

int		ft_chk_except_num(char *str)
{
	char	ar[] = {"10, 11, 12, 13, 14, 15, 16, 17, 18, 19, \
					20, 30, 40, 50, 60, 70, 80, 90, 100"};
	int		i;

	i = 0;
	while (ar[i])
	{
		if (ft_strcmp(str, &ar[i]) == 0)
			return (1);
		i++;
	}
	return (0);
}

void	ft_make_num_forms(char *str, int flag)
{
	char	*res;
	char	tmp[3];

	res = ft_power_ten(flag);
	if (str[0] != '0')
	{
		tmp[0] = str[0];
		tmp[1] = '\0';
		ft_strcpy(g_list[g_len++], tmp);
		ft_strcpy(g_list[g_len++], "100");
	}
	if (str[1] != '0')
	{
		tmp[0] = str[1];
		tmp[1] = '0';
		tmp[2] = '\0';
		if (ft_chk_except_num(str + 1))
		{
			ft_strcpy(g_list[g_len++], str + 1);
			if (str[2] != '0')
			{
				tmp[0] = str[2];
				tmp[1] = '\0';
				ft_strcpy(g_list[g_len++], tmp);
			}
			ft_strcpy(g_list[g_len++], res);
			return;
		}
		else
			ft_strcpy(g_list[g_len++], tmp);
	}
	if (str[2] != '0')
	{
		tmp[0] = str[2];
		tmp[1] = '\0';
		ft_strcpy(g_list[g_len++], tmp);
	}
	ft_strcpy(g_list[g_len++], res);


	if (flag == 0)
	{
		int i=0;
		while (i < g_len)
		{
			//print(g_list[i]);
			i++;
		}
		//print("\n");
	}
	
}

void	ft_grouping_num_three(char *str, int len)
{
	int		remainer;
	int		ar_size;
	int		i;
	int		j;
	char	tmp[4];

	i = 0;
	j = 0;
	remainer = len % 3;
	ar_size = len / 3;
	if (remainer)
		ar_size++;
	while (i < len)
	{
		while (remainer && (i + j < 3 - remainer) && i == 0)
			tmp[j++] = '0';
		tmp[j++] = str[i++];
		if (j % 3 == 0 || i == len)
		{
			j = 0;
			tmp[3] = '\0';
			ft_make_num_forms(tmp, --ar_size);
		}
	}
}
