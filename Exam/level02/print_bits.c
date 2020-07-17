/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bits.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/10 05:45:40 by marvin            #+#    #+#             */
/*   Updated: 2020/07/10 05:45:40 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void    print_bits(unsigned char octet)
{
    int oct;
    int div;

    div = 128;
    oct = octet;
    while (div != 0)
    {
        if (div <= oct)
        {
            write(1, "1", 1);
            oct %= div;
        }
        else
        {
            write(1, "0", 1);
        }
        
        div /= 2;
    }
}