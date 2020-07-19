/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jko <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 15:21:57 by jko               #+#    #+#             */
/*   Updated: 2020/01/23 15:27:17 by jko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_rev_int_tab(int *tab, int size)
{
	int temp;
	int index;
	int rev_index;

	index = 0;
	rev_index = size - 1;
	while (index < rev_index)
	{
		temp = *(tab + index);
		*(tab + index) = *(tab + rev_index);
		*(tab + rev_index) = temp;
		index++;
		rev_index--;
	}
}
