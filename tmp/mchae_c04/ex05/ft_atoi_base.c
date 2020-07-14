/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchae <mchae@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 13:46:46 by mchae             #+#    #+#             */
/*   Updated: 2020/07/13 17:12:39 by mchae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int g_hex;

void			notation(char *char_num, int len, int base_len)
{
	
}

int				check_base(char *base)
{
	int			i;
	int			j;
	int			len;

	len = 1;
	i = 0;
	while (base[i + 1])
	{
		j = i;
		while (base[j])
		{
			if (base[i] == base[j + 1] || (base[j] >= 9 && base[j] <= 13) ||
				   	base[j] == ' ' || base[j] == '-' || base[j] == '+')
				return (0);
			j++;
		}
		len++;
		i++;
	}
	printf("len : %d\n", len);
	if(len == 2 || len == 8 || len == 10 || len == 16)
		return (len);
	else
		return (0);
}

int				ft_atoi_base(char *str, char *base)
{
	int			i;
	int			minus;
	int			base_len;
	int			len;
	char		char_num[50];

	len = 0;
	i = 0;
	minus = 1;
	g_hex = 1;
	base_len = check_base(base);
	if(base_len == 0)
		return 0;
	while ((*str >= 9 && *str <= 13) || *str == ' ')
	{
		str++;
	}
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			minus *= -1;
		str++;
	}
	while ((*str >= '0' && *str <='9') || (*str >= 'a' && *str <= 'f'))
	{
		char_num[i] = *str;
		len++;
		i++;
		str++;
	}
	notation(char_num, len, base_len);
	return (g_hex * minus);
}
