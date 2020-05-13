/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_backtrack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/13 15:58:42 by dboyer            #+#    #+#             */
/*   Updated: 2020/05/13 16:11:21 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static inline int		is_valid(t_element *element, int index,\
		t_list *memory, char *neighbour)
{
	char *content;

	if (element)
	{
		content = (char *)(element->content);
		if (index < (int)ft_strlen(content)\
				&& ft_cinset(content[index], neighbour))
		{
			if (content[index] != 'D')
			{
				memory->append(memory, &element->index);
				memory->append(memory, &index);
			}
			return (1);
		}
	}
	return (0);
}

static inline t_element	*back_element(t_list *memory, t_list *map)
{
	t_element *element;

	element = (memory->last)->previous;
	return (map->get(map, *((int *)(element->content))));
}

static inline int		back_index(t_list *memory)
{
	int index;

	index = *((int *)(memory->last->content));
	memory->remove(memory, (memory->last)->previous);
	memory->remove(memory, memory->last);
	return (index);
}

int						ft_backtrack(t_element *element, int n_index,\
		t_list *map, t_list *memory)
{
	char	*content;
	int		index;
	char	*neighbour;

	index = n_index;
	content = (char *)element->content;
	neighbour = memory->size == 2 ? "1" : "1D";
	content[index] = content[index] == 'D' ? 'D' : 'X';
	if (content[index] && is_valid(element, index + 1, memory, neighbour))
		return (ft_backtrack(element, index + 1, map, memory));
	if (index > 0 && is_valid(element, index - 1, memory, neighbour))
		return (ft_backtrack(element, index - 1, map, memory));
	if (element->next && is_valid(element->next, index, memory, neighbour))
		return (ft_backtrack(element->next, index, map, memory));
	if (element->previous && is_valid(element->previous,\
				index, memory, neighbour))
		return (ft_backtrack(element->previous, index, map, memory));
	if (memory->size >= 2 && content[index] == 'X')
		return (ft_backtrack(back_element(memory, map),\
					back_index(memory), map, memory));
	else if (memory->size >= 2 && content[index] == 'D')
		return (1);
	return (0);
}
