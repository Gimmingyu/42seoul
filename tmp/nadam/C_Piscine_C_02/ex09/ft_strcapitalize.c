/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jko <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 14:05:37 by jko               #+#    #+#             */
/*   Updated: 2020/01/26 15:16:35 by jko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		is_first(char *str, int index)
{
	int i;

	i = index - 1;
	if (index == 0)
		return (1);
	if (str[i] >= '0' && str[i] <= '9')
		return (0);
	if (str[i] >= 'A' && str[i] <= 'Z')
		return (0);
	if (str[i] >= 'a' && str[i] <= 'z')
		return (0);
	return (1);
}

void	change_upcase(char *str, int index)
{
	if (str[index] >= 'a' && str[index] <= 'z')
		str[index] = str[index] - 32;
}

void	change_lowcase(char *str, int index)
{
	if (str[index] >= 'A' && str[index] <= 'Z')
		str[index] = str[index] + 32;
}

char	*ft_strcapitalize(char *str)
{
	int index;

	index = 0;
	while (str[index] != '\0')
	{
		if (is_first(str, index))
			change_upcase(str, index);
		else
			change_lowcase(str, index);
		index++;
	}
	return (str);
}
