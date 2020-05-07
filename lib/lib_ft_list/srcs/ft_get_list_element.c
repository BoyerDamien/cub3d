/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_list_element.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 14:43:28 by dboyer            #+#    #+#             */
/*   Updated: 2020/04/29 20:10:08 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_list.h"

t_element	*ft_get_list_element(t_list *list, int index)
{
	t_element	*next;

	if (index < list->size)
	{
		next = list->first;
		while (next && next->index != index)
			next = next->next;
		return (next);
	}
	return (NULL);
}
