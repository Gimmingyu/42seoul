/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdtoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyekim <kyekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 14:55:01 by kyekim            #+#    #+#             */
/*   Updated: 2021/05/12 14:55:02 by kyekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_fdtoa(long double d, int size)
{
	char	*str;
	char	*strf;
	int		i;
	int		j;

	j = size;
	strf = NULL;
	if (!(str = ft_strnew(size + 1)))
		return (NULL);
	i = 0;
	if (d < 0)
		d = (d - (int)d) * (-1);
	else
		d = (d - (int)d);
	while (j--)
	{
		d = d * 10.0;
		str[i] = (int)d + 48;
		d = d - (int)d;
		i++;
	}
	str = ft_strjoin_free("0.", str, 2);
	return (str);
}
