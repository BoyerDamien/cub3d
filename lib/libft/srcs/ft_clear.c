/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clear.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 12:01:23 by dboyer            #+#    #+#             */
/*   Updated: 2020/03/03 13:48:24 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void		ft_clear(t_list *list)
{
	t_element *new_first;

	if (list->first)
	{
		new_first = list->first->next;
		list->remove(list, list->first);
		list->first = new_first;
		ft_clear(list);
	}
}
