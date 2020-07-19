/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jipark <jipark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 21:24:47 by jipark            #+#    #+#             */
/*   Updated: 2020/04/06 12:56:34 by jipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		get_free(char **result, int *word_size_arr, int word_count,
						int is_free)
{
	int i;

	i = 0;
	if (is_free == 1 || is_free == 2)
	{
		while (i < word_count + 1)
		{
			if (!result[i])
				free(result[i]);
			i++;
		}
		free(result);
	}
	if (is_free == 2 || is_free == 3)
		free(word_size_arr);
}

static int		get_word_count(char const *s, char c)
{
	int i;
	int count;

	count = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (i == 0 && !(s[i] == c))
			count++;
		else if (i != 0 && (s[i - 1] == c) &&
		!(s[i] == c))
			count++;
		i++;
	}
	return (count);
}

static int		*get_each_word_size(char const *s, char c, int word_count)
{
	int *arr;
	int index;
	int i;

	i = 0;
	if (!(arr = (int *)malloc(sizeof(int) * word_count)))
		return (0);
	while (i < word_count)
	{
		arr[i] = 1;
		i++;
	}
	i = 0;
	index = 0;
	while (s[i] != '\0')
	{
		if (!(s[i] == c))
			arr[index]++;
		else if (i != 0 && !(s[i - 1] == c))
			index++;
		i++;
	}
	return (arr);
}

static int		get_split_arr(char const *s, char c, char **result,
							int *size_arr)
{
	int i;
	int j;
	int index;

	i = 0;
	j = 0;
	index = 0;
	while (s[i] != '\0')
	{
		if (!(s[i] == c))
		{
			if (i == 0 || (i != 0 && (s[i - 1] == c)))
				if (!(result[index] = (char *)malloc(size_arr[index])))
					return (0);
			result[index][j++] = s[i];
			result[index][j] = '\0';
		}
		else if (i != 0 && !(s[i - 1] == c))
		{
			index++;
			j = 0;
		}
		i++;
	}
	return (1);
}

char			**ft_split(char const *s, char c)
{
	char	**result;
	int		*word_size_arr;
	int		word_count;

	word_count = get_word_count(s, c);
	if (!(result = (char **)malloc(sizeof(char *) * (word_count + 1))))
		return (0);
	result[word_count] = 0;
	if (!(word_size_arr = get_each_word_size(s, c, word_count)))
	{
		get_free(result, word_size_arr, word_count, 1);
		return (0);
	}
	if (!(get_split_arr(s, c, result, word_size_arr)))
	{
		get_free(result, word_size_arr, word_count, 2);
		return (0);
	}
	get_free(result, word_size_arr, word_count, 3);
	return (result);
}
