/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_string_tab.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghwki <donghwki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 01:12:59 by donghwki          #+#    #+#             */
/*   Updated: 2020/02/13 22:12:27 by donghwki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	str_swap(char **s1, char **s2)
{
	char *temp_ptr;

	temp_ptr = *s1;
	*s1 = *s2;
	*s2 = temp_ptr;
}

int		ft_strcmp(char *s1, char *s2)
{
	unsigned int	i;
	int				cmp;

	i = 0;
	while (s1[i] == s2[i] && s1[i] && s2[i])
		i++;
	cmp = s1[i] - s2[i];
	return (cmp);
}

void	ft_sort_string_tab(char **tab)
{
	int size;
	int i;
	int j;

	size = 0;
	while (tab[size])
		size++;
	i = 0 - 1;
	while (++i < size - 1)
	{
		j = i - 1;
		while (++j < size)
			if (ft_strcmp(tab[i], tab[j]) > 0)
				str_swap(&tab[i], &tab[j]);
	}
}
