/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maff_revalpha.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/10 11:05:35 by marvin            #+#    #+#             */
/*   Updated: 2020/07/10 11:05:35 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void    ft_putchar(char c)
{
    write(1, &c, 1);
}

int     main(void)
{
    int i;
    
    i = 'z';
    while (i-- >= 'a')
    {
        if (i % 2 == 0)
            ft_putchar(i - ('a'-'A'));
        else
            ft_putchar(i);
    }

    ft_putchar('\n');
    return (0);
}