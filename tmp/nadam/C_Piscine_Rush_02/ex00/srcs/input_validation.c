/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jko <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 17:10:56 by jko               #+#    #+#             */
/*   Updated: 2020/02/09 18:14:51 by jko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "file_to_hash.h"
#include "ft_string.h"

char	is_number_str(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int		get_len(char *str)
{
	int len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

char	is_valid(char *str)
{
	if (!is_number_str(str))
		return (0);
	return (1);
}
