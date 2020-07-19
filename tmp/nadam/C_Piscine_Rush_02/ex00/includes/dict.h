/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jko <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 20:26:37 by jko               #+#    #+#             */
/*   Updated: 2020/02/08 21:26:44 by jko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DICT_H
# define DICT_H

typedef struct	s_dict {
	char			*key;
	char			*value;
	struct s_dict	*next;
}				t_dict;

t_dict			*make_dict(char *key, char *value);
void			free_dict(t_dict *dict);

#endif
