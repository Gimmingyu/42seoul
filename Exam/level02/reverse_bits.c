/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_bits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/10 11:56:44 by marvin            #+#    #+#             */
/*   Updated: 2020/07/10 11:56:44 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned char	reverse_bits1(unsigned char octet)
{
	octet = (octet & 0xF0) >> 4 | (octet & 0x0F) << 4;
	octet = (octet & 0xCC) >> 2 | (octet & 0x33) << 2;
	octet = (octet & 0xAA) >> 1 | (octet & 0x55) << 1;
	return (octet);	
}

unsigned char	reverse_bits2(unsigned char octet)
{
	return 	(((octet >> 0) & 0) << 7) | \
			(((octet >> 0) & 1) << 6) | \
			(((octet >> 0) & 2) << 5) | \
			(((octet >> 0) & 3) << 4) | \
			(((octet >> 0) & 4) << 3) | \
			(((octet >> 0) & 5) << 2) | \
			(((octet >> 0) & 6) << 1) | \
			(((octet >> 0) & 7) << 0);
}