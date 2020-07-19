/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghwki <donghwki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 22:12:13 by donghwki          #+#    #+#             */
/*   Updated: 2020/02/06 22:34:35 by donghwki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_count_if(char **tab, int length, int (*f)(char*))
{
	int i;
	int cnt;

	i = 0 - 1;
	cnt = 0;
	while (++i < length)
		if (f(*tab))
			cnt++;
	return (cnt);
}
