/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jipark <jipark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 09:40:06 by jipark            #+#    #+#             */
/*   Updated: 2020/01/25 17:30:38 by jipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		check_num(char character)
{
	if (48 <= character && character <= 57)
	{
		return (1);
	}
	return (0);
}

int		check_low(char character)
{
	if (97 <= character && character <= 122)
	{
		return (1);
	}
	return (0);
}

int		check_up(char character)
{
	if (65 <= character && character <= 90)
	{
		return (1);
	}
	return (0);
}

char	*ft_strcapitalize(char *str)
{
	int i;

	i = 0;
	if (*str != 0 && check_low(str[0]))
		str[0] = str[0] - 32;
	while (1)
	{
		if (str[i + 1] == '\0')
			break ;
		if (!check_low(str[i]) && !check_up(str[i]) && !check_num(str[i]))
		{
			if (check_low(str[i + 1]))
				str[i + 1] = str[i + 1] - 32;
		}
		else
		{
			if (check_up(str[i + 1]))
				str[i + 1] = str[i + 1] + 32;
		}
		i++;
	}
	return (str);
}
