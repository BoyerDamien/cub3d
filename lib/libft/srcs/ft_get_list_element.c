/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_list_element.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 14:43:28 by dboyer            #+#    #+#             */
/*   Updated: 2020/03/09 14:14:10 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

t_element	*ft_get_list_element(t_list *list, int index)
{
	t_element	*next;
	int			i;

	if (index < list->size)
	{
		i = 0;
		next = list->first;
		while (next && i != index)
		{
			next = next->next;
			i++;
		}
		return (next);
	}
	return (NULL);
}
