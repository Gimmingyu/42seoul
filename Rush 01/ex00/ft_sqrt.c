/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yju <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/11 19:20:48 by yju               #+#    #+#             */
/*   Updated: 2020/07/12 23:31:15 by yju              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_sqrt(int *arr)
{
	int arr_count;
	int i;
	long square_root;

	arr_count = 0;
	i = 0;
	square_root = 1;
	while (*arr)
	{
		if (*arr == ' ')
			arr++;
		else
		{
			arr_count++;
			arr++;
		}
	}
	while (i < 15)
	{
		square_root = (square_root + (arr_count / square_root)) / 2;
		i++;
	}
	return (square_root + 0.5);
}
