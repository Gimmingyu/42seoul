/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jko <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 14:48:14 by jko               #+#    #+#             */
/*   Updated: 2020/02/09 14:49:24 by jko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef READ_FILE_H
# define READ_FILE_H

int		get_line_num(char *file_name);
int		get_next_line_length(int fd);
char	*get_next_line(int fd, int length);
char	**read_lines(int fd1, int fd2, int line_num, char **result);
char	**read_dict_file(char *file_name);

#endif
