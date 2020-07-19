/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jipark <jipark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 08:57:09 by jipark            #+#    #+#             */
/*   Updated: 2020/01/25 11:57:25 by jipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_str_is_printable(char *str)
{
	int i;

	i = 0;
	if (*str == 0)
		return (1);
	while (str[i] != '\0')
	{
		if (str[i] <= 31 || str[i] >= 127)
			return (0);
		i++;
	}
	return (1);
}
