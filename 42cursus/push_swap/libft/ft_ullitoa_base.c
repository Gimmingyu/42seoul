/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ullitoa_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyekim <kyekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 15:18:21 by kyekim            #+#    #+#             */
/*   Updated: 2021/05/12 15:18:24 by kyekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static int		ft_nblen(unsigned long long nb, int base)
{
	if (nb == 0)
		return (1);
	else if (nb / base > 0)
		return (1 + ft_nblen(nb / base, base));
	else
		return (1);
}

char			*ft_ullitoa_base(unsigned long long nb, int base)
{
	char	*str;
	size_t	len;

	len = ft_nblen(nb, base);
	if (!(str = ft_strnew(len)))
		return (NULL);
	while (len-- > 0)
	{
		*(str + len) = (nb % base) + ((nb % base > 9) ? 'A' - 10 : '0');
		nb /= base;
	}
	return (str);
}
