/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joh <joh@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 14:56:01 by joh               #+#    #+#             */
/*   Updated: 2020/07/06 15:05:12 by joh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_str_is_printable(char *str)
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
		if (!(cmp >= ' ' && cmp <= '~'))
		{
			res = 0;
			break ;
		}
		index++;
	}
	return (res);
}
