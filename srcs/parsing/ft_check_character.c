/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_character.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/11 11:09:50 by dboyer            #+#    #+#             */
/*   Updated: 2020/05/13 15:29:40 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static inline void	clear_map_content(t_element *element)
{
	free(element->content);
}

static inline int	count_characters(t_element *element, int count)
{
	char	*content;
	int		i;

	i = 0;
	if (element)
	{
		content = (char *)element->content;
		while (content[i])
		{
			count = ft_cinset(content[i], "NESW") ? count + 1 : count;
			i++;
		}
		return (count_characters(element->next, count));
	}
	return (count);
}

void				ft_check_character(char *path)
{
	t_list	map;
	int		result;

	result = 0;
	map = ft_get_map(path);
	if (map.size > 0 && count_characters(map.first, 0) == 1)
	{
		ft_display_process_status("N character", "ok");
		result = 1;
	}
	map.iter(map.first, clear_map_content);
	map.clear(&map);
	if (!result)
	{
		ft_display_process_status("N character", "error");
		ft_display_error("No character or several characters \
							were found", __func__);
		exit(EXIT_FAILURE);
	}
}
