/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jko <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 19:03:05 by jko               #+#    #+#             */
/*   Updated: 2020/02/12 21:43:43 by jko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STRING_H
# define FT_STRING_H

void	free_strs(char **strs, int size);
int		ft_strlen(char *str);
char	*ft_strdup_and_strcat(char *str, char *src, int size);
char	**ft_split(char *str, char *charset);

#endif
