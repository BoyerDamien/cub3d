/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_iter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 12:43:53 by dboyer            #+#    #+#             */
/*   Updated: 2020/03/03 14:13:08 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_list_iter(t_element *element, void (*f)(t_element *element))
{
	if (element)
	{
		f(element);
		ft_list_iter(element->next, f);
	}
}
