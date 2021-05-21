/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_float_expo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyekim <kyekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 14:55:23 by kyekim            #+#    #+#             */
/*   Updated: 2021/05/12 14:55:27 by kyekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*ft_calc_real_neg(char *mant, int exp_d)
{
	int tmp;
	int i;
	int ret;

	ret = 0;
	if (!mant)
		return (NULL);
	while (exp_d-- > 1)
	{
		i = 0;
		while (mant[i++])
		{
			tmp = (ret + (mant[i] - 48)) / 2;
			if ((mant[i] - 48) % 2 == 1)
				ret = 10;
			else
				ret = 0;
			if (tmp >= 0)
				mant[i] = (tmp % 10 + 48);
		}
		if (ret == 10)
			if (!(mant = ft_strjoin_free(mant, "5", 1)))
				return (NULL);
	}
	return (mant);
}

char	*ft_calc_real_pos(char *mant, int exp_d)
{
	int i;
	int tmp;
	int ret;

	while (exp_d >= 0)
	{
		ret = 0;
		i = ft_strlen(mant) - 1;
		while (i >= 0)
		{
			tmp = ((mant[i] - 48) * 2);
			if (tmp >= 0)
				mant[i] = ((tmp % 10) + 48) + ret;
			if (tmp >= 10)
				ret = 1;
			else if (tmp >= 0)
				ret = 0;
			if (i == 0 && tmp >= 10)
				if (!(mant = ft_strjoin_free("1", mant, 2)))
					return (NULL);
			i--;
		}
		exp_d--;
	}
	return (mant);
}
