/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heryu <heryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 15:50:48 by heryu             #+#    #+#             */
/*   Updated: 2020/07/14 00:26:36 by heryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strlen(char *str);

void	convert_int_to_base(int nbr, char *ret, char *base, int sign)
{
	int		i;
	int		base_length;
	int		origin_nbr;

	origin_nbr = nbr;
	base_length = ft_strlen(base);
	ret[0] = '\0';
	i = 1;
	while (1)
	{
		ret[i] = base[nbr % base_length];
		nbr /= base_length;
		i++;
		if (nbr == 0)
			break ;
	}
	if (origin_nbr != 0 && sign == -1)
		ret[i] = '-';
}

void	rev_char_arr(char *ret, int size)
{
	int		i;
	char	tmp;
	int		count;

	i = 0;
	count = size / 2;
	while (i < count)
	{
		tmp = ret[i];
		ret[i] = ret[size - 1 - i];
		ret[size - 1 - i] = tmp;
		i++;
	}
}

char	*int_to_base(int nbr, char *base, int sign)
{
	int		base_length;
	int		alloc_size;
	char	*ret;
	int		origin_nbr;

	origin_nbr = nbr;
	alloc_size = 0;
	base_length = ft_strlen(base);
	if (nbr != 0 && sign == -1)
		alloc_size++;
	while (1)
	{
		alloc_size++;
		nbr /= base_length;
		if (nbr == 0)
			break ;
	}
	nbr = origin_nbr;
	ret = (char*)malloc(sizeof(char) * (alloc_size + 1));
	if (ret == (void*)0)
		return ((void*)0);
	convert_int_to_base(nbr, ret, base, sign);
	rev_char_arr(ret, alloc_size + 1);
	return (ret);
}
