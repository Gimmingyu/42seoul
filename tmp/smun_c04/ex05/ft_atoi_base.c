/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smun <smun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 20:21:23 by smun              #+#    #+#             */
/*   Updated: 2020/07/08 20:48:53 by smun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int		ft_isspace(char c)
{
	if (c == '\t' || c == '\n' ||
		c == '\v' || c == '\f' || c == '\r' || c == ' ')
		return (1);
	return (0);
}

int		ft_find_char(char c, char *str, int blen)
{
	int i;

	i = 0;
	while (str[i] && blen-- > 0)
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int		ft_conv_by_base(char *str, char *base, int blen)
{
	int		nbr;
	int		charindex;

	nbr = 0;
	while (1)
	{
		charindex = ft_find_char(*str, base, blen);
		if (charindex < 0)
			return (nbr);
		nbr = charindex + nbr * blen;
		str++;
	}
}

int		ft_atoi_base(char *str, char *base)
{
	int		i;
	int		blen;
	int		neg;

	blen = ft_is_valid_base(base);
	if (blen == 0)
		return (0);
	i = 0;
	neg = 1;
	while (ft_isspace(*str))
		str++;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			neg = -neg;
		str++;
	}
	return ((ft_conv_by_base(str, base, blen)) * neg);
}
