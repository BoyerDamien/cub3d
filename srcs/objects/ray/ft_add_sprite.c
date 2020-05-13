/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_sprite.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/13 12:00:48 by dboyer            #+#    #+#             */
/*   Updated: 2020/05/13 14:47:51 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static inline int	fun(t_element *element, void *content)
{
	t_sprite *sprite;
	t_sprite *sprite_list;

	sprite = (t_sprite *)content;
	sprite_list = (t_sprite *)element->content;
	return (sprite->transform.y <= sprite_list->transform.y);
}

void				ft_add_sprite(t_list *list, t_sprite *sprite)
{
	t_element *found;

	if (list->size && (found = list->search(list->first, sprite, fun)))
		list->insert_before(list, found, sprite);
	else
		list->append(list, sprite);
}
