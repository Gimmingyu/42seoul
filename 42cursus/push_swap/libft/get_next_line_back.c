/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_back.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyekim <kyekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 15:18:54 by kyekim            #+#    #+#             */
/*   Updated: 2021/05/12 15:18:55 by kyekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/get_next_line.h"

static t_list	*ft_valid_file(t_list **files, const int fd)
{
	t_list *tmp;

	tmp = *files;
	while (tmp)
	{
		if ((int)tmp->content_size == fd)
			return (tmp);
		tmp = tmp->next;
	}
	tmp = ft_lstnew("\0", fd);
	ft_lstadd(files, tmp);
	tmp = *files;
	return (&(*tmp));
}

static int		ft_return_value(char **line, void **content, int ret_v)
{
	size_t	i;
	char	*swp;

	i = 0;
	if (ret_v < BUFF_SIZE && !ft_strlen(*content))
		return (0);
	while (((char*)(*content))[i] != '\n'
			&& ((char*)(*content))[i] != '\0')
		i++;
	*line = ft_strsub(*content, 0, i);
	if (i < ft_strlen(*content) - 1)
	{
		swp = ft_strdup((char*)*content + i + 1);
		free(*content);
		*content = swp;
	}
	else
		ft_strclr(*content);
	return (1);
}

int				get_next_line(const int fd, char **line)
{
	t_list			*current;
	static	t_list	*files;
	char			buff[BUFF_SIZE + 1];
	int				ret_v;
	size_t			i;

	i = 0;
	if (fd < 0 || !line || read(fd, buff, 0) < 0 || BUFF_SIZE <= 0)
		return (-1);
	current = ft_valid_file(&files, fd);
	if (current == NULL)
		return (-1);
	while ((ret_v = read(fd, buff, BUFF_SIZE)))
	{
		buff[ret_v] = '\0';
		current->content = ft_strjoin_free(current->content, buff, 1);
		if (ft_strchr(buff, '\n'))
			break ;
	}
	return (ft_return_value(line, &current->content, ret_v));
}
