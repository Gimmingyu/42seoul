/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joh <joh@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 14:34:50 by joh               #+#    #+#             */
/*   Updated: 2020/07/06 14:37:13 by joh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_str_is_uppercase(char *str)
{
	int		index;
	int		res;
	char	cmp;

	res = 1;
	index = 0;
	while (1)
	{
		cmp = str[index];
		if (cmp == '\0')
		{
			break ;
		}
		if (!(cmp >= 'A' && cmp <= 'Z'))
		{
			res = 0;
			break ;
		}
		index++;
	}
	return (res);
}
