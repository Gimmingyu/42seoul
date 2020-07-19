/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jipark <jipark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 23:07:11 by jipark            #+#    #+#             */
/*   Updated: 2020/04/07 17:48:33 by jipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef GET_NEXT_LINE_BONUS_H
#	define GET_NEXT_LINE_BONUS_H
#	define FD_SIZE 4096

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int		check_new_idx(char *buf, int res);
int		append_new_line(char **line, char *buf, int idx);
int		get_idx(char **line, char *buf, int res);
int		check_validation(char **line, char *tmp[], int *res, int fd);
int		get_next_line(int fd, char **line);

int		get_return(int res, int fd, char **line, char *tmp[]);
int		ft_strlen(char *src);
char	*ft_strdup(char *src, int start, int end);
char	*ft_strjoin(char *s1, char *s2);
void	ft_bufcpy(char *tmp, char *buf, int idx);

#	endif
