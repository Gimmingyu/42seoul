/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 17:41:40 by jipark            #+#    #+#             */
/*   Updated: 2020/04/16 13:47:06 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_h.h"

int		ft_printf(const char *str, ...)
{
	va_list		ap;
	t_printf	*format;

	if (!(format = (t_printf *)malloc(sizeof(t_printf))))
		return (ERROR);
	va_start(ap, str);
	if (!check_validation(ap, str, format))
		return (return_with_free(ap, format, ERROR));
	va_start(ap, str);
	get_result(str, format, ap);
	return (return_with_free(ap, format, OK));
}
