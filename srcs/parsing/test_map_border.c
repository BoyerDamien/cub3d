/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_map_border.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/24 15:19:35 by dboyer            #+#    #+#             */
/*   Updated: 2020/05/13 16:13:49 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static inline t_element		*find_onset_element(t_element *element)
{
	char	*content;
	int		i;

	i = 0;
	if (element)
	{
		content = (char *)element->content;
		while (content[i])
		{
			if (ft_cinset(content[i], "NSEW"))
				return (element);
			i++;
		}
	}
	return (find_onset_element(element->next));
}

int							test_map_border(t_list *map)
{
	t_element	*element;
	t_list		memory;
	int			result;
	int			i;
	int			j;

	i = 0;
	j = 0;
	memory = ft_list();
	element = find_onset_element(map->first);
	if (ft_map_is_closed(map, element, &memory))
	{
		ft_display_process_status("Map border", "ok");
		result = 1;
	}
	else
	{
		ft_display_process_status("Map border", "error");
		ft_display_error("Your map is not closed", __func__);
		result = 0;
	}
	return (result);
}
