/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_search.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 20:45:45 by dboyer            #+#    #+#             */
/*   Updated: 2020/05/10 12:10:38 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_list.h"

t_element	*ft_search(t_element *element, int (*f)(t_element *element))
{
	if (element && !f(element))
		return (ft_search(element->next, f));
	return (element);
}
