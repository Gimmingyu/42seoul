/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smun <smun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 19:40:18 by smun              #+#    #+#             */
/*   Updated: 2020/07/08 20:48:36 by smun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

/*
** 1. Gets the length of the base string.
**    At the same time, check for contains + or -
** 2. Make sure that base is not empty and size is greater than 1.
** 3. Check that base contains the same character twice.
** 4. Returns length of the base.
*/

int		ft_is_valid_base(char *base)
{
	int		len;
	int		i;
	int		j;

	len = 0;
	while (base[len] != '\0')
	{
		if (base[len] == '+' || base[len] == '-')
			return (0);
		len++;
	}
	if (len <= 1)
		return (0);
	i = 0;
	while (i < len)
	{
		j = i;
		while (--j >= 0)
		{
			if (base[i] == base[j])
				return (0);
		}
		i++;
	}
	return (len);
}

int		ft_abs(int nbr)
{
	if (nbr < 0)
		return (-nbr);
	return (nbr);
}

void	ft_rev_char_tab(char *tab, int size)
{
	int		i;
	char	temp;

	i = 0;
	while (i < size / 2)
	{
		temp = tab[i];
		tab[i] = tab[size - i - 1];
		tab[size - i - 1] = temp;
		i++;
	}
}

void	ft_putnbr_base(int nb, char *base)
{
	char	str[96];
	int		i;
	int		blen;

	blen = ft_is_valid_base(base);
	if (blen == 0)
		return ;
	if (nb == 0)
	{
		write(1, &base[0], 1);
		return ;
	}
	if (nb < 0)
		write(1, "-", 1);
	i = 0;
	while (nb)
	{
		str[i++] = base[ft_abs(nb % blen)];
		nb /= blen;
	}
	ft_rev_char_tab(str, i);
	write(1, str, i);
}
