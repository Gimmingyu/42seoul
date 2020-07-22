/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_advanced_sort_string_tab.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyekim <kyekim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 04:39:04 by kyekim            #+#    #+#             */
/*   Updated: 2020/07/22 07:25:42 by kyekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_advanced_sort_string_tab(char **tab, int (*cmp)(char *, char *))
{
	char	*tmp;
	int		cnt;
	int		is_sorted;

	is_sorted = 0;
	while (is_sorted == 0)
	{
		cnt = 1;
		is_sorted = 1;
		while (tab[cnt] != 0)
		{
			if (cmp(tab[cnt - 1], tab[cnt]) > 0)
			{
				tmp = tab[cnt - 1];
				tab[cnt - 1] = tab[cnt];
				tab[cnt] = tmp;
				is_sorted = 0;
			}
			cnt++;
		}
	}
}
