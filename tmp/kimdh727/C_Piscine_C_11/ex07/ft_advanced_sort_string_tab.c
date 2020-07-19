/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_advanced_sort_string_tab.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghwki <donghwki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 01:29:25 by donghwki          #+#    #+#             */
/*   Updated: 2020/02/13 22:16:33 by donghwki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_advanced_sort_string_tab(char **tab, int (*cmp)(char *, char *))
{
	char	*tmp;
	int		count;
	int		sort;

	sort = 0;
	while (sort == 0)
	{
		count = 1;
		sort = 1;
		while (tab[count] != 0)
		{
			if (cmp(tab[count - 1], tab[count]) > 0)
			{
				tmp = tab[count - 1];
				tab[count - 1] = tab[count];
				tab[count] = tmp;
				sort = 0;
			}
			count++;
		}
	}
}
