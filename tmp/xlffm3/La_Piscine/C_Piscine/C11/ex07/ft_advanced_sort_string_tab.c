/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_advanced_sort_string_tab.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jipark <jipark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 22:39:04 by jipark            #+#    #+#             */
/*   Updated: 2020/02/06 11:22:20 by jipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_advanced_sort_string_tab(char **tab, int (*cmp)(char *, char *))
{
	char	*tmp;
	int		count;
	int		is_sorted;

	is_sorted = 0;
	while (is_sorted == 0)
	{
		count = 1;
		is_sorted = 1;
		while (tab[count] != 0)
		{
			if (cmp(tab[count - 1], tab[count]) > 0)
			{
				tmp = tab[count - 1];
				tab[count - 1] = tab[count];
				tab[count] = tmp;
				is_sorted = 0;
			}
			count++;
		}
	}
}
