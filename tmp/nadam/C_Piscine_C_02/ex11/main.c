/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jko <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 16:22:56 by jko               #+#    #+#             */
/*   Updated: 2020/01/25 16:33:16 by jko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_putstr_non_printable(char *str);

int	main(void)
{
	printf("%s\n", "Coucou\ntu vas bien ?");
	ft_putstr_non_printable("Coucou\ntu vas bien ?");
	printf("\n\n");
	return (0);
}
