/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_basic.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghwki <donghwki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 01:43:06 by donghwki          #+#    #+#             */
/*   Updated: 2020/02/09 20:24:15 by donghwki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush_02.h"
#include <stdlib.h>
#include <unistd.h>

/*
**  	void 	ft_putstr(char *str)
**		설명 : 문자열을 매개변수로 받아 문자열을 출력!
**		반환값 : 없음
*/

void	ft_putstr(char *str)
{
	int strlen;

	strlen = 0;
	while (str[strlen])
		strlen++;
	write(1, str, strlen);
}

/*
** 		int		ft_strlen(char *str)
**		설명 : 문자열을 매개변수로 받아 문자열의 길이를 계산.
**		반환값 : 문자열 크기 리턴.
*/

int		ft_strlen(char *str)
{
	int len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

/*
** 		int		ft_strcmp(char *s1, char *s2)
**		설명 : 두개의 문자열 매개변수를 같은 값인지 비교
**		반환값 : 모두 같으면 0을 반환, 다르면(양수나 음수) 차이값을 반환!
*/

int		ft_strcmp(char *s1, char *s2)
{
	unsigned int	i;
	int				cmp;

	i = 0;
	while (s1[i] == s2[i] && s1[i] && s2[i])
		i++;
	cmp = s1[i] - s2[i];
	return (cmp);
}

/*
** 		char	*ft_strdup(char *str, int st, int en)
**		설명 : 문자열을 복사하고 복사된 문자열을 가리키는 포인터를 반환. 문자를 복사할 공간을 확보하기 위해서
** 			  malloc(3)을 호출하고, 함수 내수베에서 문자열을 복사 했으면 free(3)을 통해서 해제 시킨다!
**		반환값 : 복사된 문자열의 주소를 가리키는 포인터를 반환! 에러시 NULL 을 반환!
*/

char	*ft_strdup(char *str, int st, int en)
{
	int		i;
	char	*dest;

	if (!(dest = (char *)malloc(sizeof(char) * en - st + 1)))
		return (0);
	i = 0 - 1;
	while (++i < en - st)
		dest[i] = str[st + i];
	dest[i] = 0;
	return (dest);
}

/*
** 		char	*ft_trim(char *str)	// trim
**		변수 : st(start index), en(end inedx), idx(index)
**		설명 : 문자열에 처음과 마지막에 공백이 있으면  is_space()함수 계산으로 각각 1 증가!
**		반환값 : 양 끝 공백 문자 제거된 복사된 문자열 포인터 반환!
*/

char	*ft_trim(char *str)
{
	int		st;
	int		en;
	int		idx;
	char	*dest;

	st = 0;
	en = ft_strlen(str) - 1;
	while (is_space(str[st]))
		st++;
	while (is_space(str[en]))
		en--;
	if (!(dest = (char *)malloc(sizeof(char) * (en - st + 1 + 1))))
		return (0);
	idx = 0 - 1;
	while (++idx < en - st + 1)
		dest[idx] = str[st + idx];
	dest[idx] = 0;
	return (dest);
}
