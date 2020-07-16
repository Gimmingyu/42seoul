/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongckim <yongckim@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 21:54:58 by yongckim          #+#    #+#             */
/*   Updated: 2020/07/15 22:13:39 by yongckim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		base_len(char *base)
{
	int i;

	i = 0;
	while (base[i])
		i++;
	return (i);
}

int		ft_putnbr(int nbr, int *n, char *base)
{
	int i;
	int blen;

	blen = base_len(base);
	i = 0;
	if (nbr < 0)
		nbr *= -1;
	while (nbr)
	{
		n[i] = nbr % blen;
		nbr /= blen;
		i++;
	}
	return (i);
}

char	*ft_base(int nbr, char *base)
{
	int		n[100];
	int		i;
	char	*str;
	int		cnt;

	cnt = 1;
	if (nbr < 0)
		cnt = 2;
	i = ft_putnbr(nbr, n, base);
	if ((str = (char *)malloc(sizeof(char) * (i + cnt))) == ((void *)0))
		return (((void *)0));
	if (cnt == 2)
	{
		str[0] = '-';
		cnt = 1;
	}
	else
		cnt = 0;
	while (--i >= 0)
		str[cnt++] = base[n[i]];
	str[cnt] = '\0';
	return (str);
}
