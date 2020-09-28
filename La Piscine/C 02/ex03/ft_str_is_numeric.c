/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyekim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 12:11:11 by kyekim            #+#    #+#             */
/*   Updated: 2020/07/13 12:11:12 by kyekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_str_is_numeric(char *str)
{
	int answer;

	answer = 1;
	while (*str != '\0')
	{
		if (!(*str >= 48 && *str <= 57))
		{
			answer = 0;
		}
		str++;
	}
	return (answer);
}