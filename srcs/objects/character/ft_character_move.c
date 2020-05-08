/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_character_move.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 14:32:57 by dboyer            #+#    #+#             */
/*   Updated: 2020/05/08 15:51:38 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static inline void move_minus(t_game *game, t_vector ref)
{
	t_vector move_vector;
	t_vector coordinate;

	coordinate = game->character.coordinate;
	move_vector = coordinate.sub(&coordinate, ref.mul_scalar(&ref, STEP));
	if (!ft_is_wall(game, move_vector.x, move_vector.y) && \
	!ft_is_sprite(game, move_vector.x, move_vector.y))
		game->character.coordinate = move_vector;
}

static inline void move_plus(t_game *game, t_vector ref)
{
	t_vector move_vector;
	t_vector coordinate;

	coordinate = game->character.coordinate;
	move_vector = coordinate.add(&coordinate, ref.mul_scalar(&ref, STEP));
	if (!ft_is_wall(game, move_vector.x, move_vector.y) && \
	!ft_is_sprite(game, move_vector.x, move_vector.y))
		game->character.coordinate = move_vector;
}

void ft_character_move(t_game *game, int move)
{
	if (move == RIGHT)
		move_plus(game, game->character.plane);
	else if (move == LEFT)
		move_minus(game, game->character.plane);
	else if (move == DOWN)
		move_minus(game, game->character.orientation);
	else if (move == UP)
		move_plus(game, game->character.orientation);
}
