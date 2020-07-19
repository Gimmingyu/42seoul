/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghwki <donghwki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 17:06:51 by donghwki          #+#    #+#             */
/*   Updated: 2020/01/27 19:46:16 by donghwki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		is_white_space(char c)
{
	if (c == 32 || (c >= 8 && c <= 13))
		return (1);
	return (0);
}

int		is_sign(char c, int *sign)
{
	if (c == '-')
	{
		*sign *= -1;
		return (1);
	}
	else if (c == '+')
		return (1);
	return (0);
}

int		ft_atoi(char *str)
{
	unsigned int	i;
	int				flag;
	int				result;

	i = 0;
	flag = 1;
	result = 0;
	while (is_white_space(str[i]) && str[i])
		i++;
	while (is_sign(str[i], &flag))
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result * flag);
}
