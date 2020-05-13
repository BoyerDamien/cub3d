/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_character_rotate.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/13 11:00:12 by dboyer            #+#    #+#             */
/*   Updated: 2020/05/13 11:01:37 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

inline void	rotate(t_game *game, double rotation_speed)
{
	t_vector plane;
	t_vector orientation;

	plane = game->character.plane;
	orientation = game->character.orientation;
	plane.x = plane.x * cos(-rotation_speed) - plane.y * sin(-rotation_speed);
	plane.y = game->character.plane.x * sin(-rotation_speed) + \
				plane.y * cos(-rotation_speed);
	orientation.x = orientation.x * cos(-rotation_speed) - \
				orientation.y * sin(-rotation_speed);
	orientation.y = game->character.orientation.x * sin(-rotation_speed) + \
				orientation.y * cos(-rotation_speed);
	game->character.plane = plane;
	game->character.orientation = orientation;
}

void		ft_character_rotate(t_game *game, int rotation)
{
	t_vector	oldplane;
	t_vector	old_orientation;
	double		rotation_speed;

	oldplane = game->character.plane;
	old_orientation = game->character.orientation;
	rotation_speed = ft_degree_to_rad(ROTATION);
	if (rotation == 'r')
		rotate(game, rotation_speed);
	else
		rotate(game, -rotation_speed);
}
