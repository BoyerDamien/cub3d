/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_last_element.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 11:00:31 by dboyer            #+#    #+#             */
/*   Updated: 2020/03/03 14:16:09 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

t_element	*ft_get_last_element(t_list *list)
{
	t_element *next;

	next = list->first;
	while (next && next->next)
		next = next->next;
	return (next);
}
