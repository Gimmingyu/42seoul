/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_h.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jipark <jipark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 09:56:39 by jipark            #+#    #+#             */
/*   Updated: 2020/02/11 10:04:27 by jipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef FT_H_H
#	define FT_H_H

#include <unistd.h>
#include <sys/errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <libgen.h>

void	ft_putstr(char *str);
int		get_number(char *str);
int		check_only_number(char *str);
#	endif
