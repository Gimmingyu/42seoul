/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeskim <jaeskim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 20:45:24 by jaeskim           #+#    #+#             */
/*   Updated: 2020/07/08 14:35:43 by jaeskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_is_alpha(char *str)
{
	if ((*str < 'A' || 'Z' < *str) && (*str < 'a' || 'z' < *str))
		return (0);
	else
		return (1);
}

char	*ft_strcapitalize(char *str)
{
	char *ret;
	char *tmp;

	ret = str;
	while (*str)
	{
		tmp = str;
		tmp--;
		if (!ft_is_alpha(str) && ret == str)
			*str = *str - 32;
		else if (!ft_is_alpha(tmp) && 'a' <= *str && *str <= 'z')
		{
			if (!('0' <= *tmp && *tmp <= '9'))
				*str = *str - 32;
		}
		else if (ft_is_alpha(tmp) && 'A' <= *str && *str <= 'Z')
			*str = *str + 32;
		str++;
	}
	return (ret);
}
