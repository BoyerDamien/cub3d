/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_is_closed.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/13 16:02:26 by dboyer            #+#    #+#             */
/*   Updated: 2020/05/13 16:06:48 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static inline void	clear_map(t_element *element)
{
	int		i;
	char	*content;

	i = 0;
	content = (char *)element->content;
	while (content[i])
	{
		if (ft_cinset(content[i], "DX"))
			content[i] = '1';
		i++;
	}
}

static inline int	check_right(t_list *map, t_element *element, t_list *memory)
{
	int		i;
	int		j;
	char	*content;

	i = 0;
	j = 0;
	content = (char *)element->content;
	while (content[i] && !ft_cinset(content[i], "NSEW"))
		i++;
	while (content[i])
	{
		if (content[i] == '1')
			j = i;
		i++;
	}
	if (j > 0 && content[j] == '1')
	{
		content[j] = 'D';
		return (ft_backtrack(element, j, map, memory));
	}
	return (0);
}

static inline int	check_left(t_list *map, t_element *element, t_list *memory)
{
	int		i;
	char	*content;

	i = 0;
	content = (char *)element->content;
	while (content[i])
	{
		if (content[i] == '1')
		{
			content[i] = 'D';
			return (ft_backtrack(element, i, map, memory));
		}
		i++;
	}
	return (0);
}

int					ft_map_is_closed(t_list *map, t_element *element,\
								t_list *memory)
{
	int result;

	result = 0;
	result += check_right(map, element, memory);
	map->iter(map->first, clear_map);
	memory->clear(memory);
	result += check_left(map, element, memory);
	map->iter(map->first, clear_map);
	memory->clear(memory);
	return (result == 2);
}
