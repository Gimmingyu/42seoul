/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_boolean.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jipark <jipark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 21:06:02 by jipark            #+#    #+#             */
/*   Updated: 2020/02/03 12:50:25 by jipark           ###   ########.fr       */
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
