/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyekim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/18 12:09:43 by kyekim            #+#    #+#             */
/*   Updated: 2020/07/19 23:39:31 by kyekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_h.h"

char	*ft_malloc(char *s, int i)
{
	int len;
	char *temp;

	len = 0;
	while (*(s + i) != ' ' && *(s + i) != ':' && *(s + i) != '\n')
	{
		len++;
		i++;
	}
	temp = (char *)malloc(sizeof(char) * (len + 1));
	return (temp);
}

int		ft_check(char c)
{
	if (c == ' ' || (c >= 9 && c <= 13))
		return (1);
	if (c == ':')
		return (1);
	return (0);
}

void	ft_filter(char *s, t_list *temp)
{
	char	*num;
	char	*alp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	num = ft_malloc(s, i);
	while (s[i] != ' ' && s[i] != ':')
	{
		num[i] = s[i];
		i++;
	}
	num[i] = '\0';
	while (ft_check(s[i]))
		i++;
	alp = ft_malloc(s, i);
	while (s[i] != '\n')
		alp[j++] = s[i++];

	add_dict(temp, num, alp);
}

void	ft_read_txt(char *dict_name)
{
	FILE	*file;
	char	line[255];
	t_list *temp;

	temp = init();
	file = fopen(dict_name, "r");
	// ft_filter(line, temp);
	print_list(temp);
	fclose(file);
}
