/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jko <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 20:10:30 by jko               #+#    #+#             */
/*   Updated: 2020/02/08 23:19:14 by jko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STRING_H
# define FT_STRING_H

int		ft_strcmp(char *s1, char *s2);
char	*ft_strdup(char *str, int start, int len);
void	free_strs(char **strs, int size);
void	ft_strcpy(char *dest, char *src);
void	ft_strncat(char *dest, char *src, unsigned int nb);

#endif
