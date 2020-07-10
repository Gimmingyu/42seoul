/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repeat_alpha.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/10 11:44:57 by marvin            #+#    #+#             */
/*   Updated: 2020/07/10 11:44:57 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int     cnt_letter(char c)
{
    int repeat;

    if (c >= 'A' && c <= 'Z')
        repeat = c - 'A' + 1;
    else if (c >= 'a' && c <= 'z')
        repeat = c - 'a' + 1;
    else
        repeat = 1;
    return (repeat);
}

int     main(int argc, char **argv)
{
    int repeat;

    if (argc == 2)
    {
        while (*argv[1])
        {
            repeat = cnt_letter(*argv[1]);
            while(repeat--)
                write(1, *argv[1]++, 1);
        }
    }
    write(1, '\n', 1);
}