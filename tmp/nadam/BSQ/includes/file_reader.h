/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_reader.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jko <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 22:25:27 by jko               #+#    #+#             */
/*   Updated: 2020/02/10 22:25:47 by jko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILE_READER_H
# define FILE_READER_H

int		get_line_num(char *file_name);
int		get_next_line_length(int fd);
char	*get_next_line(int fd, int length);
char	**read_lines(int fd1, int fd2, int line_num, char **result);
char	**read_file(char *file_name);

#endif
