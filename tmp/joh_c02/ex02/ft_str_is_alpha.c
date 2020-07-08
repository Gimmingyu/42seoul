/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joh <joh@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 12:03:09 by joh               #+#    #+#             */
/*   Updated: 2020/07/06 13:51:09 by joh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_str_is_alpha(char *str)
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
		if (!((cmp >= 'A' && cmp <= 'Z') || (cmp >= 'a' && cmp <= 'z')))
		{
			res = 0;
			break ;
		}
		index++;
	}
	return (res);
}
