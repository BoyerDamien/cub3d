/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 12:30:29 by dboyer            #+#    #+#             */
/*   Updated: 2020/03/03 14:26:16 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

t_list		ft_list(void)
{
	t_list new;

	new.size = 0;
	new.append = ft_add_back;
	new.clear = ft_clear;
	new.concat = ft_concat;
	new.remove = ft_del;
	new.iter = ft_list_iter;
	new.last = ft_get_last_element;
	new.get = ft_get_list_element;
	new.copy = ft_list_copy;
	new.map = ft_map;
	return (new);
}
