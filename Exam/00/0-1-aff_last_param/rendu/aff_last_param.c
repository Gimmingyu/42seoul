/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff_last_param.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/10 11:22:04 by marvin            #+#    #+#             */
/*   Updated: 2020/07/10 11:22:04 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int     main(int argc, char **argv)
{
    if (argc > 1)
    {
        while(*argv[argc - 1])
            write(1, argv[argc - 1]++, 1);
    }
    write(1, '\n', 1);
    return (0);
}