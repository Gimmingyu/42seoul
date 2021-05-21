/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_len.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyekim <kyekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 15:02:31 by kyekim            #+#    #+#             */
/*   Updated: 2021/05/12 15:02:32 by kyekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static	char	**ft_get_len(void)
{
	static char **len_c = NULL;

	if (len_c != NULL)
		return (len_c);
	len_c = ft_strsplit(LEN, ' ');
	return (len_c);
}

int				ft_parse_len(const char *str, t_arg *arg)
{
	char	*len_arg;
	char	**len;
	int		i;

	if (!(len_arg = ft_strnew(2)))
		return (-1);
	ft_memcpy(len_arg, str, 2);
	*(len_arg + 2) = '\0';
	len = ft_get_len();
	while (*len != NULL)
	{
		i = ft_strlen(*len);
		if (ft_memcmp(len_arg, *len, i) == 0)
		{
			free(len_arg);
			arg->len = *len;
			return (i);
		}
		len++;
	}
	free(len_arg);
	return (0);
}
