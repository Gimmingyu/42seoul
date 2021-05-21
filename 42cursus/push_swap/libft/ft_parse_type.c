/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_type.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyekim <kyekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 15:02:50 by kyekim            #+#    #+#             */
/*   Updated: 2021/05/12 15:02:51 by kyekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	(**ft_f_init(void))(va_list ap, t_arg *arg)
{
	int		(**type_function)(va_list ap, t_arg *arg);

	if (!(type_function = malloc(11 * sizeof(*type_function))))
		return (NULL);
	type_function[0] = ft_type_string;
	type_function[1] = ft_type_char;
	type_function[2] = ft_type_pointer;
	type_function[3] = ft_type_int;
	type_function[4] = ft_type_int;
	type_function[5] = ft_type_octal;
	type_function[6] = ft_type_unsigned;
	type_function[7] = ft_type_hexmin;
	type_function[8] = ft_type_hexmaj;
	type_function[9] = ft_type_float;
	type_function[10] = ft_type_percent;
	return (type_function);
}

int			(*g_ft_get_type(char c))(va_list ap, t_arg *arg)
{
	static int		(**type_function)(va_list ap, t_arg *arg) = NULL;
	int				i;
	char			*types;

	types = TYPES;
	i = 0;
	if (c == '\0')
		return (0);
	if (type_function == NULL)
		type_function = ft_f_init();
	while (types[i] != c && types[i] != '\0')
		i++;
	if (types[i] == c)
		return (type_function[i]);
	return (0);
}

int			ft_parse_type(const char *str, t_arg *arg)
{
	if (g_ft_get_type(*str) != 0)
		arg->arg_type = *str;
	return (arg->arg_type != '\0');
}
