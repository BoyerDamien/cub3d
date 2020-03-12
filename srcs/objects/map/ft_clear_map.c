/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clear_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 12:56:44 by dboyer            #+#    #+#             */
/*   Updated: 2020/03/12 12:59:30 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

void ft_clear_map(t_map *map)
{
	int i;

	i = 0;
	while (map->content[i])
	{
		free(map->content[i]);
		i++;
	}
	free(map->content[i]);
}
