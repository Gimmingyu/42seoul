/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jipark <jipark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/17 14:46:04 by jipark            #+#    #+#             */
/*   Updated: 2020/04/16 16:54:33 by jipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_h.h"

int		skip_mod(const char *str, int *i)
{
	int j;
	int cnt;

	j = *i;
	cnt = 0;
	while (str[j] == '%')
	{
		cnt++;
		j++;
	}
	while (cnt > 1)
		cnt -= 2;
	*i = j;
	if (cnt)
		return (0);
	*i -= 1;
	return (1);
}

int		write_mod(const char *str, int *i, t_printf *format)
{
	int j;
	int cnt;

	j = *i;
	cnt = 0;
	while (str[j] == '%')
	{
		cnt++;
		j++;
	}
	while (cnt > 1)
	{
		write(1, "%", 1);
		format->len += 1;
		cnt -= 2;
	}
	*i = j;
	if (cnt)
		return (0);
	*i -= 1;
	return (1);
}

void	write_zero(t_printf *format, int zero_len, int flag)
{
	while (zero_len > 0)
	{
		write(1, "0", 1);
		if (!flag)
			format->len += 1;
		zero_len--;
	}
}

void	write_white_space(t_printf *format, int width, int memory_len)
{
	while (width-- > memory_len)
	{
		write(1, " ", 1);
		format->len += 1;
	}
}

int		return_with_free(va_list ap, t_printf *format, int flag)
{
	int len;

	len = format->len;
	free(format);
	va_end(ap);
	if (flag == ERROR)
		return (ERROR);
	return (len);
}
