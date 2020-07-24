/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyekim <kyekim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/12 05:27:05 by kyekim            #+#    #+#             */
/*   Updated: 2020/07/12 16:26:34 by kyekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** ft_check: check two check list
** 1) ft_check_1234: check overlap numbers
** 2) ft_check_udlr: check all Up Down Left Right conditions are satisfied
**
** return 1: OK
** return 0: KO
*/

#include "header.h"

int		ft_check(int idx, int *udlr[], int *ans)
{
	if (!ft_check_1234(idx, ans))
		return (0);
	if (!ft_check_udlr(idx, udlr, ans))
		return (0);
	return (1);
}
