/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyekim <kyekim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 01:16:49 by kyekim            #+#    #+#             */
/*   Updated: 2020/07/16 01:49:26 by kyekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

int	ft_strlen(char *str);

int	main(void)
{
	char str[] = "123abc";
	printf("%d, %lu\n", ft_strlen(str), strlen(str));
	return (0);
}
