/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyekim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/10 20:54:44 by kyekim            #+#    #+#             */
/*   Updated: 2020/07/14 01:05:09 by kyekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	str_length(char *dest)
{
	unsigned int	cnt;

	cnt = 0;
	while (dest[cnt] != '\0')
		cnt++;
	return (cnt);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	char			*dst;
	char			*src_start;
	unsigned int	dst_digit;
	unsigned int	remain;

	dst = dest;
	src_start = src;
	remain = size;
	while (remain-- != 0 && *dst != '\0')
		dst++;
	dst_digit = dst - dest;
	remain = size - dst_digit;
	if (remain == 0)
		return (dst_digit + str_length(src));
	while (*src != '\0')
	{
		if (remain > 1)
		{
			*dst++ = *src;
			remain--;
		}
		src++;
	}
	*dst = '\0';
	return (dst_digit + (src - src_start));
}
