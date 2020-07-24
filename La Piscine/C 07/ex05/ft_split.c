/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyekim <kyekim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/18 19:54:30 by kyekim            #+#    #+#             */
/*   Updated: 2020/07/19 14:15:23 by kyekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		is_sep(char str, char *charset)
{
	int i;

	i = 0;
	while (charset[i] != '\0')
	{
		if (str == charset[i])
			return (1);
		i++;
	}
	return (0);
}

int		get_word_count(char *str, char *charset)
{
	int i;
	int count;

	count = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (i == 0 && !is_sep(str[i], charset))
			count++;
		else if (i != 0 && is_sep(str[i - 1], charset) &&
		!is_sep(str[i], charset))
			count++;
		i++;
	}
	return (count);
}

int		*get_each_word_size(char *str, char *charset, int word_count)
{
	int *arr;
	int index;
	int i;

	i = 0;
	arr = (int *)malloc(sizeof(int) * word_count);
	while (i < word_count)
	{
		arr[i] = 1;
		i++;
	}
	i = 0;
	index = 0;
	while (str[i] != '\0')
	{
		if (!is_sep(str[i], charset))
			arr[index]++;
		else if (i != 0 && !is_sep(str[i - 1], charset))
			index++;
		i++;
	}
	return (arr);
}

void	get_split_arr(char *str, char *charset, char **result, int *size_arr)
{
	int i;
	int j;
	int index;

	i = 0;
	j = 0;
	index = 0;
	while (str[i] != '\0')
	{
		if (!is_sep(str[i], charset))
		{
			if (i == 0 || (i != 0 && is_sep(str[i - 1], charset)))
				result[index] = (char *)malloc(sizeof(char) * size_arr[index]);
			result[index][j++] = str[i];
			result[index][j] = '\0';
		}
		else if (i != 0 && !is_sep(str[i - 1], charset))
		{
			index++;
			j = 0;
		}
		i++;
	}
}

char	**ft_split(char *str, char *charset)
{
	char	**result;
	int		*word_size_arr;
	int		word_count;

	word_count = get_word_count(str, charset);
	result = (char **)malloc(sizeof(char *) * (word_count + 1));
	word_size_arr = get_each_word_size(str, charset, word_count);
	get_split_arr(str, charset, result, word_size_arr);
	result[word_count] = 0;
	return (result);
}
