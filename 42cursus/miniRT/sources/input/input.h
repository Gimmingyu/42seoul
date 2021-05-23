/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyekim <kyekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 13:36:09 by kyekim            #+#    #+#             */
/*   Updated: 2021/05/09 13:36:13 by kyekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUT_H
# define INPUT_H

# define KEYPRESS	2
# define KEYRELEASE	3
# define MOUSEPRESS	4

# define ESC		53
# define W			13
# define A			0
# define S			1
# define D			2
# define Q			12
# define E			14

# define LEFT		123
# define RIGHT		124
# define DOWN		125
# define UP			126

# define MOUSELEFT	1
# define MOUSERIGHT	2
# define SCROLLUP	4
# define SCROLLDOWN	5

int		handle_key(int key);
int		handle_mouse(int button);

#endif
