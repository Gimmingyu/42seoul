/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/10 06:06:16 by marvin            #+#    #+#             */
/*   Updated: 2020/07/10 06:06:16 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char    *ft_trim(char *str)
{
    int i;

    while (str[0] <= 32 && str[0] >= 1)
    {
        i = 1;
        while (str[i] != '\0')
        {
            str[i - 1] = str[i];
            i++;
        }
        str[i - 1] = '\0';

    }
    return (str);
}

void    ft_print(char *str)
{
    int i;
    int space;

    space = 0;
    i = 0;
    while (str[i] != '\0')
    {
        if (str[i] <= 32 && str[i] >= 0)
        {
            space = 1;
        }
        else
        {
            if (space)
            {
                space = 0;
                write(1, "   ", 3);
            }
            write(1, &str[i], 1);
            space = 0;
        }
        i++;
    }
}

int     main(int argc, char **argv)
{
    if (argc == 2 && argv[1][0] != '\0')
    {
        ft_print(ft_trim(argv[1]));
    }
    write(1, '\n', 1);
}