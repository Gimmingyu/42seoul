/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jipark <jipark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 19:22:58 by jipark            #+#    #+#             */
/*   Updated: 2020/02/05 11:16:50 by jipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_count_if(char **tab, int length, int (*f)(char*))
{
	int result;
	int count;
	int i;

	i = 0;
	count = 0;
	while (i < length)
	{
		result = f(tab[i]);
		if (result != 0)
			count++;
		i++;
	}
	return (count);
}
