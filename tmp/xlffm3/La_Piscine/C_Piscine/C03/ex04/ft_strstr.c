/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jipark <jipark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 13:27:51 by jipark            #+#    #+#             */
/*   Updated: 2020/01/26 19:22:05 by jipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	int count;
	int t_count;
	int is_found;
	int index;

	count = -1;
	t_count = 0;
	if (!(*to_find))
		return (str);
	while (to_find[t_count] != '\0')
		t_count++;
	while (str[++count] != '\0')
	{
		index = 0;
		is_found = 1;
		while (index < t_count)
		{
			if (str[count + index] != to_find[index])
				is_found = 0;
			index++;
		}
		if (is_found)
			return (&str[count]);
	}
	return (0);
}
