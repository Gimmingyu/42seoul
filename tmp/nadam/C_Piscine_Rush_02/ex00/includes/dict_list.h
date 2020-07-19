/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_list.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jko <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 20:58:14 by jko               #+#    #+#             */
/*   Updated: 2020/02/09 21:18:25 by jko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DICT_LIST_H
# define DICT_LIST_H

t_dict	*change_dict_value(t_dict *dict, t_dict *new_dict);
t_dict	*add_dict_list(t_dict *head, t_dict *new_dict);
t_dict	*find_dict_in_list(t_dict *head, char *key);
void	free_dict_list(t_dict *head);

#endif
