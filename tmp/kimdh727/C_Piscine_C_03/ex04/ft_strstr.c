/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghwki <donghwki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 12:12:07 by donghwki          #+#    #+#             */
/*   Updated: 2020/01/27 12:16:14 by donghwki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	cnt;

	if (!to_find[0])
		return (str);
	i = 0 - 1;
	cnt = 0;
	while (to_find[cnt])
		cnt++;
	while (str[++i] != 0)
	{
		if (str[i] == to_find[0])
		{
			j = 0;
			while (to_find[j] != 0 && to_find[j] == str[i + j])
				j++;
		}
		if (j == cnt)
			break ;
	}
	if (!str[i])
		return (0);
	return (str + i);
}
