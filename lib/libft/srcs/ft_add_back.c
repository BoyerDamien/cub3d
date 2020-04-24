/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_back.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 11:27:04 by dboyer            #+#    #+#             */
/*   Updated: 2020/04/24 11:24:14 by dboyer           ###   ########.fr       */
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
		list->size++;
		last = ft_get_last_element(list);
		new_elem->previous = last;
		new_elem->index = list->size - 1;
		last->next = new_elem;
	}
	else
	{
		list->size = 1;
		new_elem->index = 0;
		list->first = new_elem;
	}
}
