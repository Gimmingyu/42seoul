/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghwki <donghwki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 14:58:48 by donghwki          #+#    #+#             */
/*   Updated: 2020/01/25 17:45:30 by donghwki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
// #include "ft_putchar.c"
// #include "rush04.c"

void	rush04(int a, int b);

#define TESTCASE 3
void	print(int n, int a, int b){
	printf("\n-------------------test%d  %d, %d ------------------------\n",n, a, b);
}

int main (){
	int testcase_a[TESTCASE + 3];
	int testcase_b[TESTCASE + 3];

	for (int i =0; i<TESTCASE; i++){
		testcase_a[i] = (rand()%12) + 1;
		testcase_a[i] = (rand()%12) + 1;
	}
	testcase_a[TESTCASE] = 1;
	testcase_b[TESTCASE] = 5;
	testcase_a[TESTCASE+1] = 5;
	testcase_b[TESTCASE+1] = 1;
	testcase_a[TESTCASE+2] = 1;
	testcase_b[TESTCASE+2] = 1;


	for (int i = 0; i<TESTCASE+3; i++){
		print(i + 1, testcase_a[i], testcase_b[i]);
		rush04(testcase_a[i], testcase_b[i]);
	}
}
