/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joh <joh@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 13:59:15 by joh               #+#    #+#             */
/*   Updated: 2020/07/06 14:21:47 by joh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_str_is_lowercase(char *str)
{
	char	cmp;
	int		index;
	int		res;

	res = 1;
	index = 0;
	while (1)
	{
		cmp = str[index];
		if (cmp == '\0')
		{
			break ;
		}
		if (!(cmp >= 'a' && cmp <= 'z'))
		{
			res = 0;
			break ;
		}
		index++;
	}
	return (res);
}
