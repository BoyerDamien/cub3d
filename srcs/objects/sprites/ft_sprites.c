/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprites.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 19:56:56 by dboyer            #+#    #+#             */
/*   Updated: 2020/05/13 15:23:19 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static inline void	init(t_game *game, t_sprite *new, t_ray *ray)
{
	t_vector plane;
	t_vector orientation;

	orientation = game->character.orientation;
	plane = game->character.plane;
	new->point = ray->point;
	new->point.x = (int)new->point.x + 0.5;
	new->point.y = (int)new->point.y + 0.5;
	new->transform = ft_vector(0, 0, 0);
	new->onset = ft_vector(0, 0, 0);
	new->offset = ft_vector(0, 0, 0);
	new->sprite = new->point.sub(&new->point, game->character.coordinate);
	new->inv_det = 1.0 / (plane.x * orientation.y - orientation.x * plane.y);
	new->transform.x = new->inv_det * (orientation.y * new->sprite.x - \
										orientation.x * new->sprite.y);
	new->transform.y = new->inv_det * (-plane.y * new->sprite.x + \
										new->sprite.y * plane.x);
}

t_sprite			*ft_sprite(t_game *game, t_ray *ray)
{
	t_sprite *new;

	if (!(new = (t_sprite *)malloc(sizeof(t_sprite))))
		return (NULL);
	init(game, new, ray);
	new->screen_x = (int)((game->window.width / 2) * \
							(1 + new->transform.x / new->transform.y));
	new->height = abs((int)(game->window.height / (new->transform.y)));
	new->onset.y = -new->height / 2 + game->window.height / 2;
	new->onset.y = new->onset.y < 0 ? 0 : new->onset.y;
	new->offset.y = new->height / 2 + game->window.height / 2;
	if (new->offset.y >= game->window.height)
		new->offset.y = game->window.height - 1;
	new->width = fabs(game->window.height / new->transform.y);
	new->onset.x = -new->width / 2 + new->screen_x;
	new->onset.x = new->onset.x < 0 ? 0 : new->onset.x;
	new->offset.x = new->width / 2 + new->screen_x;
	if (new->offset.x >= game->window.width)
		new->offset.x = game->window.width - 1;
	new->ratio = 255 / new->transform.y * LIGHT_RATIO;
	return (new);
}
