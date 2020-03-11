/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_back.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 11:27:04 by dboyer            #+#    #+#             */
/*   Updated: 2020/03/03 14:18:41 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void		ft_add_back(t_list *list, void *content)
{
	t_element *new_elem;
	t_element *last;

	new_elem = ft_new_element(content);
	if (list->size > 0)
	{
		last = ft_get_last_element(list);
		new_elem->previous = last;
		last->next = new_elem;
	}
	else
	{
		list->first = new_elem;
	}
	list->size++;
}
