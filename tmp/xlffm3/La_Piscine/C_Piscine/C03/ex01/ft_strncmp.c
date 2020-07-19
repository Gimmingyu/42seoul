/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jipark <jipark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 19:40:52 by jipark            #+#    #+#             */
/*   Updated: 2020/01/26 16:18:11 by jipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int s1_value;
	unsigned int s2_value;
	unsigned int count;

	count = 0;
	s1_value = 0;
	s2_value = 0;
	while (count < n && (s1[count] != '\0' || s2[count] != '\0'))
	{
		s1_value += (unsigned char)s1[count];
		s2_value += (unsigned char)s2[count];
		if (s1[count] != s2[count])
			return (s1_value - s2_value);
		count++;
	}
	return (0);
}
