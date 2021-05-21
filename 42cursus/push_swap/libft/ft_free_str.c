/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyekim <kyekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 14:56:15 by kyekim            #+#    #+#             */
/*   Updated: 2021/05/12 14:56:21 by kyekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_free_str(char *str)
{
	char *str_ret;

	str_ret = NULL;
	str_ret = str;
	free(str);
	return (str_ret);
}
