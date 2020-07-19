/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghwki <donghwki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 22:16:42 by donghwki          #+#    #+#             */
/*   Updated: 2020/02/03 23:50:05 by donghwki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

# define BUF_SIZE 1024

int main(int argc, char const *argv[])
{
	int		fd;
	int 	buf_size;
	char	buf[BUF_SIZE];

	if (argc == 1)
		write(1, "File name missing.\n", 19);
	else if (argc > 2)
		write(1, "Too many arguments.\n", 20);
	else
	{
		fd = open(argv[1], O_RDONLY);
		if (fd == -1)
		{
			write(1, "Cannot read file.\n", 19);
			return (0);
		}
		while ((buf_size = read(fd, buf, BUF_SIZE)))
			write(1, buf, buf_size);
		close(fd);
	}
}
