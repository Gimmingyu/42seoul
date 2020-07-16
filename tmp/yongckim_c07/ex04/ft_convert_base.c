/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongckim <yongckim@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 19:03:20 by yongckim          #+#    #+#             */
/*   Updated: 2020/07/15 22:08:50 by yongckim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_base(int nbr, char *base);

int		ft_atoi(char *str, char *base, int blen)
{
	int n;
	int i;

	n = 0;
	i = 0;
	while (*str != '\0')
	{
		while (base[i] != '\0')
		{
			if (base[i] == *str)
			{
				n = n * blen + i;
				i = 0;
				break ;
			}
			i++;
		}
		if (i != 0)
			break ;
		str++;
	}
	return (n);
}

int		basecheck(char *base)
{
	int i;
	int j;

	i = 0;
	while (base[i] != '\0')
	{
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		if (base[i] == '+' || base[i] == '-' ||
			base[i] == 32 || (base[i] >= 9 && base[i] <= 13))
			return (0);
		i++;
	}
	i = 0;
	while (base[i] != '\0')
		i++;
	return (i);
}

int		ft_atoi_base(char *str, char *base)
{
	int blen;
	int minus;

	blen = basecheck(base);
	minus = 0;
	if (blen == 0 || blen == 1)
		return (0);
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			minus++;
		str++;
	}
	if (minus % 2 == 1)
		return (-1 * ft_atoi(str, base, blen));
	return (ft_atoi(str, base, blen));
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		base;
	char	*ch;

	if (basecheck(base_from) == 0)
		return (0);
	if (basecheck(base_to) == 0)
		return (0);
	base = ft_atoi_base(nbr, base_from);
	ch = ft_base(base, base_to);
	return (ch);
}
