/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_list_to_char.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/26 12:32:12 by dboyer            #+#    #+#             */
/*   Updated: 2020/04/27 10:06:36 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void fill_n_map(char **n_map, t_element *element){
	if (element){
		n_map[element->index] = (char *)element->content;
		return (fill_n_map(n_map, element->next));
	}
}

char **ft_map_list_to_char(char *path){
	int height;
	char **n_map;
    t_list map;

    map = ft_get_map(path);
	height = map.size;
	if (!(n_map = (char **)malloc( (height + 1) * sizeof(char *))))
		return (NULL);
	fill_n_map(n_map, map.first);
	for (int i = 0; i < height; i++){
		ft_printf("map = %s\n", n_map[i]);
	}
	n_map[height] = NULL;
    map.clear(&map);
	return (n_map);
}