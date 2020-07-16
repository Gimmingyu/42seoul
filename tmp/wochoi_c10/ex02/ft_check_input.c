/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wochoi <wochoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 15:02:52 by wochoi            #+#    #+#             */
/*   Updated: 2020/07/15 16:41:15 by wooyomac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_header.h"
#define OPTION_WITHOUT_ARG_MSG ": option requires an argument -- c"
#define OPTION_WITHOUT_ARG_MSIZE 34
#define ILLEGAL_OFFSET_MSG ": illegal offset -- "
#define ILLIGAL_OFFSET_MSIZE 20

void		print(char *str)
{
	int		len;

	len = 0;
	while (str[len])
		++len;
	write(1, str, len);
}

void		char_to_int(char *str, int *n)
{
	*n = 0;
	while (*str)
	{
		if (*str > '9' || *str < '0')
		{
			*n = -1;
			return ;
		}
		*n = *n * 10 + (*str - '0');
		++str;
	}
}

int			check_valid_input(int argc, char **argv)
{
	int		n;

	if (argc == 2)
	{
		print(basename(argv[0]));
		write(1, OPTION_WITHOUT_ARG_MSG, OPTION_WITHOUT_ARG_MSIZE);
		print("\n");
		return (-1);
	}
	char_to_int(argv[2], &n);
	if (n < 0)
	{
		print(basename(argv[0]));
		write(1, ILLEGAL_OFFSET_MSG, ILLIGAL_OFFSET_MSIZE);
		print(argv[2]);
		print("\n");
		return (-1);
	}
	return (n);
}
