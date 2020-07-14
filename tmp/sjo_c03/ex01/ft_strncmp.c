/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjo <twwj4134@gmail.com>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 19:44:52 by sjo               #+#    #+#             */
/*   Updated: 2020/07/14 00:31:18 by sjo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strncmp(char *s1, char *s2, unsigned int n)
{
	while (*s1 != 0 && *s2 != 0 && n > 0)
	{
		if (*s1 != *s2)
			break ;
		s1++;
		s2++;
		n--;
	}
	if (n == 0)
		return (0);
	else if ((*(unsigned char*)s1 - *(unsigned char*)s2) > 0)
		return (1);
	else if ((*(unsigned char*)s1 - *(unsigned char*)s2) < 0)
		return (-1);
	return (0);
}
