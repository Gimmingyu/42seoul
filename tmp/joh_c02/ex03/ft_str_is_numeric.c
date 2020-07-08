/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joh <joh@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 13:48:41 by joh               #+#    #+#             */
/*   Updated: 2020/07/06 13:58:33 by joh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_str_is_numeric(char *str)
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
		if (!((cmp >= '0' && cmp <= '9')))
		{
			res = 0;
			break ;
		}
		index++;
	}
	return (res);
}
