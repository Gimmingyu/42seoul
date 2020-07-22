/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_boolean.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyekim <kyekim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/18 21:06:02 by kyekim            #+#    #+#             */
/*   Updated: 2020/07/19 14:20:56 by kyekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef FT_BOOLEAN_H
#	define FT_BOOLEAN_H

#	include <unistd.h>
#	define TRUE	1
#	define FALSE 0
#	define SUCCESS 0
#	define EVEN(nbr) ((nbr) % (2) == (0))
#	define EVEN_MSG	"I have an even number of arguments.\n"
#	define ODD_MSG	"I have an odd number of arguments.\n"

typedef int		t_bool;
void			ft_putstr(char *str);
t_bool			ft_is_even(int nbr);
#	endif
