/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jipark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 12:10:33 by jipark            #+#    #+#             */
/*   Updated: 2020/01/23 12:11:51 by jipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	check_digits(char *p_first_digit, char *p_second_digit)
{
	*(p_second_digit) += 1;
	if (*(p_second_digit) > '9')
	{
		*(p_first_digit) += 1;
		*(p_second_digit) = '0';
	}
}

void	print_all(int first, int second, int third, int fourth)
{
	write(1, &first, 1);
	write(1, &second, 1);
	write(1, " ", 1);
	write(1, &third, 1);
	write(1, &fourth, 1);
	if (first != '9' || second != '8' || third != '9' || fourth != '9')
	{
		write(1, ", ", 2);
	}
}

void	set_digits(char first, char second, char *p_third, char *p_fourth)
{
	if (second == '9')
	{
		*(p_third) = first + 1;
		*(p_fourth) = '0';
	}
	else
	{
		*(p_third) = first;
		*(p_fourth) = second + 1;
	}
}

void	ft_print_comb2(void)
{
	char first_num;
	char second_num;
	char third_num;
	char fourth_num;

	first_num = '0';
	second_num = '0';
	while (first_num != '9' || second_num != '9')
	{
		set_digits(first_num, second_num, &third_num, &fourth_num);
		while (third_num != ':' || fourth_num != '0')
		{
			print_all(first_num, second_num, third_num, fourth_num);
			check_digits(&third_num, &fourth_num);
		}
		check_digits(&first_num, &second_num);
	}
}
