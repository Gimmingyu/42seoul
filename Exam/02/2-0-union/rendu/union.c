/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/10 12:18:24 by marvin            #+#    #+#             */
/*   Updated: 2020/07/10 12:18:24 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		not_seen_before(char *s, int max_pos, char c)
{
	int i;

	i = 0;
	while (i++ < max_pos)
		if (s[i] == c)
			return (0);
	return (1);
}

int		ft_union(char *s1, char *s2)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (s1[i++])
		if (not_seen_before(s1, i, s1[i]))
			write(1, &s1[i], 1);
	while (s2[j++])
		if (not_seen_before(s1, i, s2[j]) && not_seen_before(s2, j, s2[j]))
			write(1, &s2[j], 1);
}

int		main(int argc, char **argv)
{
	if (argc == 3)
		ft_union(argv[1], argv[2]);
	write(1, '\n', 1);
	return (0);
}