/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 12:37:36 by dboyer            #+#    #+#             */
/*   Updated: 2020/03/03 14:48:41 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

t_list ft_map(t_list *list, void *(*f)(t_element *element))
{
	t_list new;
	t_element *next;
	t_element *result;

	new = ft_list();
	next = list->first;
	while (next)
	{
		result = f(next);
		if (result)
			new.append(&new, result);
		/*else
		{
			new.clear(&new);
			return (*list);
		}*/
		next = next->next;
	}
	return (new);
}
