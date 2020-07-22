/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyekim <kyekim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 00:48:16 by kyekim            #+#    #+#             */
/*   Updated: 2020/07/22 07:30:33 by kyekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_count_if(char **tab, int length, int (*f)(char*))
{
	int		i;
	int		cnt;
	int		res;

	i = 0;
	cnt = 0;
	while (i < length)
	{
		res = f(tab[i]);
		if (res != 0)
			cnt++;
		i++;
	}
	return (cnt);
}
