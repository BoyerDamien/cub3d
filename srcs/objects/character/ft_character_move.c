/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_character_move.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 14:32:57 by dboyer            #+#    #+#             */
/*   Updated: 2020/04/27 10:58:16 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"


static void move_right(t_game *game)
{
	double angle;
	t_vector move_vector;
	t_vector coordinate;

	coordinate = game->character.coordinate;
	angle = game->character.orientation - ft_degree_to_rad(90);
	move_vector = ft_vector(sin(angle), cos(angle), 0);
	move_vector = coordinate.add(&coordinate, move_vector.mul_scalar(&move_vector, STEP));
	if (!ft_is_wall(game, move_vector.x, move_vector.y))
		game->character.coordinate = move_vector;
}

static void move_left(t_game *game)
{
	double angle;
	t_vector move_vector;
	t_vector coordinate;

	coordinate = game->character.coordinate;
	angle = game->character.orientation + ft_degree_to_rad(90);
	move_vector = ft_vector(sin(angle), cos(angle), 0);
	move_vector = coordinate.add(&coordinate, move_vector.mul_scalar(&move_vector, STEP));
	if (!ft_is_wall(game, move_vector.x, move_vector.y))
		game->character.coordinate = move_vector;
}

static void move_up(t_game *game)
{
	double angle;
	t_vector move_vector;
	t_vector coordinate;

	coordinate = game->character.coordinate;
	angle = game->character.orientation;
	move_vector = ft_vector(sin(angle), cos(angle), 0);
	move_vector = coordinate.add(&coordinate, move_vector.mul_scalar(&move_vector, STEP));
	if (!ft_is_wall(game, move_vector.x, move_vector.y))
		game->character.coordinate = move_vector;
}

static void move_down(t_game *game)
{
	double angle;
	t_vector move_vector;
	t_vector coordinate;

	coordinate = game->character.coordinate;
	angle = game->character.orientation;
	move_vector = ft_vector(sin(angle), cos(angle), 0);
	move_vector = coordinate.sub(&coordinate, move_vector.mul_scalar(&move_vector, STEP));
	if (!ft_is_wall(game, move_vector.x, move_vector.y))
		game->character.coordinate = move_vector;
}

void ft_character_move(t_game *game, int move)
{
	if (move == RIGHT)
		move_right(game);
	else if (move == LEFT)
		move_left(game);
	else if (move == DOWN)
		move_down(game);
	else if (move == UP)
		move_up(game);
}
