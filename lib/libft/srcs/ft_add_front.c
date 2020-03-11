/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_front.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 11:23:18 by dboyer            #+#    #+#             */
/*   Updated: 2020/02/18 11:20:03 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_add_front(t_list *list, void *content)
{
	t_element *new_elem;

	new_elem = ft_new_element(content);
	if (list->size > 0)
	{
		new_elem->next = list->first;
		list->first->previous = new_elem;
		list->first = new_elem;
	}
	else
	{
		list->first = new_elem;
	}
	list->size++;
}
