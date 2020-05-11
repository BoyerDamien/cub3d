/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clear.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 12:01:23 by dboyer            #+#    #+#             */
/*   Updated: 2020/05/11 19:49:15 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_list.h"

void		ft_clear(t_list *list)
{
	t_element *new_first;

	if (list->first && list->size)
	{
		new_first = list->first->next;
		list->remove(list, list->first);
		list->first = new_first;
		ft_clear(list);
	}
}
