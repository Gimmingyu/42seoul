/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyekim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/18 12:09:43 by kyekim            #+#    #+#             */
/*   Updated: 2020/07/19 22:36:10 by jopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_h.h"

char	*ft_malloc(char *s, int i)
{
	int		len;
	char	*temp;

	len = 0;
	while (*(s + i) != ' ' && *(s + i) != ':' && *(s + i) != '\n')
	{
		len++;
		i++;
	}
	temp = (char *)malloc(sizeof(char) * (len + 1));
	if (!temp)
		return (NULL);
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
	while (ft_check(s[i]))
		i++;
	num = ft_malloc(s, i);
	while (s[i] != ':' && s[i] != ' ')
	{
		num[j] = s[i];
		i++;
		j++;
	}
	num[i] = '\0';
	while (ft_check(s[i]))
		i++;
	alp = ft_malloc(s, i);
	j = 0;
	while (s[i] != '\n')
		alp[j++] = s[i++];
	add_dict(temp, num, alp);
}
