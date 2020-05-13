/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/22 15:43:23 by dboyer            #+#    #+#             */
/*   Updated: 2020/05/13 15:56:39 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static inline void	print(t_element *element)
{
	printf("|%s| \n", (char *)(element->content));
}

static inline void	clear_map_content(t_element *element)
{
	free(element->content);
}

static inline int	apply_test(t_list *map)
{
	if (test_map_content(map) && test_map_border(map))
	{
		ft_printf("\nMap: \n\n");
		map->iter(map->first, print);
		return (1);
	}
	return (0);
}

void				ft_test_map(char *path)
{
	t_list	map;
	int		result;

	result = 0;
	ft_display_message("Check map...");
	map = ft_get_map(path);
	if (map.size > 0)
	{
		result = apply_test(&map);
		map.iter(map.first, clear_map_content);
		map.clear(&map);
	}
	if (!result)
	{
		ft_display_error("No valid map was found", "error");
		exit(EXIT_FAILURE);
	}
}
