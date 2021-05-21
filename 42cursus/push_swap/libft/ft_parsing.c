/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyekim <kyekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 15:03:11 by kyekim            #+#    #+#             */
/*   Updated: 2021/05/12 15:03:11 by kyekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static	t_arg	*ft_init_arg(void)
{
	t_arg *arg;

	if (!(arg = malloc(sizeof(*arg))))
		return (NULL);
	ft_bzero(arg, sizeof(*arg));
	return (arg);
}

int				ft_parsing(const char *str, t_arg **arg)
{
	int ret;
	int i;

	if (!(*arg = ft_init_arg()))
		return (0);
	i = 1;
	i = i + ft_parse_flag(str + i, *arg);
	i = i + ft_parse_width(str + i, *arg);
	i = i + ft_parse_precision(str + i, *arg);
	if ((ret = ft_parse_len(str + i, *arg)) == -1)
		return (0);
	i = i + ret;
	i = i + ft_parse_type(str + i, *arg);
	return (i);
}
