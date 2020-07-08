/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gim <gim@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 18:52:32 by gim               #+#    #+#             */
/*   Updated: 2020/07/08 17:02:46 by gim              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		is_first(char *str, int idx)
{
	char	check;

	check = str[idx - 1];
	if (idx == 0)
	{
		return (1);
	}
	else if (check >= '0' && check <= '9')
	{
		return (0);
	}
	else if (check >= 'a' && check <= 'z')
	{
		return (0);
	}
	else if (check >= 'A' && check <= 'Z')
	{
		return (0);
	}
	return (1);
}

void	get_upper(char *str, int idx)
{
	if (str[idx] >= 'a' && str[idx] <= 'z')
	{
		str[idx] -= 32;
	}
}

void	get_lower(char *str, int idx)
{
	if (str[idx] >= 'A' && str[idx] <= 'Z')
	{
		str[idx] += 32;
	}
}

char	*ft_strcapitalize(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (is_first(str, i))
		{
			get_upper(str, i);
		}
		else
		{
			get_lower(str, i);
		}
		i++;
	}
	return (str);
}
